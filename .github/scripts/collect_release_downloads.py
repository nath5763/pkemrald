#!/usr/bin/env python3
"""Collect download metrics for a repository's latest stable GitHub release."""

from __future__ import annotations

import argparse
import csv
import json
import os
import sys
import urllib.error
import urllib.request
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Dict, Iterable, List, Mapping, Optional, Sequence


API_VERSION = "2026-03-10"
HISTORY_FIELDS = (
    "collected_at",
    "repository",
    "release_id",
    "release_tag",
    "release_name",
    "release_published_at",
    "asset_id",
    "asset_name",
    "asset_size",
    "asset_url",
    "downloads_total",
    "downloads_delta",
)


class CollectionError(RuntimeError):
    """Raised when GitHub metrics cannot be collected or validated."""


def fetch_latest_release(repository: str, token: Optional[str] = None) -> Mapping[str, Any]:
    """Return GitHub's latest stable release response for ``owner/repository``."""
    url = f"https://api.github.com/repos/{repository}/releases/latest"
    headers = {
        "Accept": "application/vnd.github+json",
        "User-Agent": "release-download-metrics-workflow",
        "X-GitHub-Api-Version": API_VERSION,
    }
    if token:
        headers["Authorization"] = f"Bearer {token}"

    request = urllib.request.Request(url, headers=headers)
    try:
        with urllib.request.urlopen(request, timeout=30) as response:
            payload = json.load(response)
    except urllib.error.HTTPError as error:
        if error.code == 404:
            raise CollectionError(
                f"GitHub did not return a latest stable release for {repository}."
            ) from error
        raise CollectionError(
            f"GitHub API request failed for {repository} with HTTP {error.code}."
        ) from error
    except (urllib.error.URLError, TimeoutError, json.JSONDecodeError) as error:
        raise CollectionError(f"Could not read the GitHub API response: {error}") from error

    if not isinstance(payload, dict):
        raise CollectionError("GitHub returned an unexpected latest-release response.")
    return payload


def normalize_release(payload: Mapping[str, Any]) -> Dict[str, Any]:
    """Validate and reduce a GitHub release response to reportable fields."""
    required_release_fields = ("id", "tag_name", "html_url", "published_at", "assets")
    missing = [field for field in required_release_fields if field not in payload]
    if missing:
        raise CollectionError(
            "Latest-release response is missing: " + ", ".join(sorted(missing))
        )
    if not isinstance(payload["assets"], list):
        raise CollectionError("Latest-release response has a non-list assets field.")

    assets: List[Dict[str, Any]] = []
    for raw_asset in payload["assets"]:
        if not isinstance(raw_asset, dict):
            raise CollectionError("Latest-release response contains an invalid asset.")
        required_asset_fields = (
            "id",
            "name",
            "size",
            "browser_download_url",
            "download_count",
        )
        missing = [field for field in required_asset_fields if field not in raw_asset]
        if missing:
            raise CollectionError(
                "Release asset is missing: " + ", ".join(sorted(missing))
            )
        download_count = raw_asset["download_count"]
        if not isinstance(download_count, int) or download_count < 0:
            raise CollectionError("Release asset has an invalid download_count.")
        assets.append(
            {
                "id": raw_asset["id"],
                "name": str(raw_asset["name"]),
                "content_type": str(raw_asset.get("content_type") or ""),
                "size": raw_asset["size"],
                "browser_download_url": str(raw_asset["browser_download_url"]),
                "download_count": download_count,
            }
        )

    return {
        "id": payload["id"],
        "tag_name": str(payload["tag_name"]),
        "name": str(payload.get("name") or payload["tag_name"]),
        "html_url": str(payload["html_url"]),
        "published_at": str(payload["published_at"]),
        "assets": assets,
    }


def read_history(history_path: Optional[Path]) -> List[Dict[str, str]]:
    """Read an earlier artifact's history, or return an empty first-run history."""
    if history_path is None or not history_path.is_file():
        return []

    with history_path.open("r", encoding="utf-8", newline="") as history_file:
        reader = csv.DictReader(history_file)
        if tuple(reader.fieldnames or ()) != HISTORY_FIELDS:
            raise CollectionError("Previous history has an unexpected CSV schema.")
        return [dict(row) for row in reader]


def previous_asset_totals(history: Iterable[Mapping[str, str]]) -> Dict[str, int]:
    """Return the most recently observed cumulative count for every asset ID."""
    totals: Dict[str, int] = {}
    for row in history:
        asset_id = str(row.get("asset_id", "") or "")
        downloads_total = row.get("downloads_total", "")
        if not asset_id:
            continue
        try:
            totals[asset_id] = int(downloads_total)
        except (TypeError, ValueError) as error:
            raise CollectionError(
                f"Previous history has an invalid count for asset {asset_id}."
            ) from error
    return totals


def build_snapshot(
    repository: str,
    release: Mapping[str, Any],
    previous_totals: Mapping[str, int],
    collected_at: str,
) -> Dict[str, Any]:
    """Build the machine-readable snapshot and calculate interval deltas."""
    assets = []
    for asset in release["assets"]:
        asset_id = str(asset["id"])
        current_total = asset["download_count"]
        previous_total = previous_totals.get(asset_id)
        delta = None if previous_total is None else current_total - previous_total
        assets.append({**asset, "downloads_delta": delta})

    release_total = sum(asset["download_count"] for asset in assets)
    release_delta: Optional[int]
    if all(asset["downloads_delta"] is not None for asset in assets):
        release_delta = sum(asset["downloads_delta"] for asset in assets)
    else:
        release_delta = None

    return {
        "collected_at": collected_at,
        "repository": repository,
        "release": {
            "id": release["id"],
            "tag_name": release["tag_name"],
            "name": release["name"],
            "html_url": release["html_url"],
            "published_at": release["published_at"],
            "downloads_total": release_total,
            "downloads_delta": release_delta,
            "assets": assets,
        },
    }


def append_snapshot_rows(
    history: Sequence[Mapping[str, str]], snapshot: Mapping[str, Any]
) -> List[Dict[str, Any]]:
    """Append one row per asset, or a zero-asset marker row, to CSV history."""
    rows: List[Dict[str, Any]] = [dict(row) for row in history]
    release = snapshot["release"]
    assets: Sequence[Mapping[str, Any]] = release["assets"]
    if not assets:
        assets = (
            {
                "id": "",
                "name": "",
                "size": "",
                "browser_download_url": "",
                "download_count": 0,
                "downloads_delta": None,
            },
        )

    for asset in assets:
        delta = asset["downloads_delta"]
        rows.append(
            {
                "collected_at": snapshot["collected_at"],
                "repository": snapshot["repository"],
                "release_id": release["id"],
                "release_tag": release["tag_name"],
                "release_name": release["name"],
                "release_published_at": release["published_at"],
                "asset_id": str(asset["id"]),
                "asset_name": asset["name"],
                "asset_size": asset["size"],
                "asset_url": asset["browser_download_url"],
                "downloads_total": asset["download_count"],
                "downloads_delta": "" if delta is None else delta,
            }
        )
    return rows


def markdown_escape(value: Any) -> str:
    """Make release-controlled text safe inside a Markdown table cell."""
    return (
        str(value)
        .replace("\\", "\\\\")
        .replace("|", "\\|")
        .replace("\r", " ")
        .replace("\n", " ")
    )


def render_summary(snapshot: Mapping[str, Any]) -> str:
    """Render a readable workflow summary for the current collection."""
    release = snapshot["release"]
    release_delta = release["downloads_delta"]
    delta_text = "—" if release_delta is None else f"{release_delta:+d}"
    lines = [
        "# Release download metrics",
        "",
        f"Repository: `{markdown_escape(snapshot['repository'])}`  ",
        (
            f"Latest stable release: "
            f"[{markdown_escape(release['name'])}]({release['html_url']}) "
            f"(`{markdown_escape(release['tag_name'])}`)  "
        ),
        f"Collected: `{markdown_escape(snapshot['collected_at'])}`  ",
        f"Total downloads: **{release['downloads_total']}** ({delta_text} since prior observation)",
        "",
    ]

    if not release["assets"]:
        lines.append("This release has no downloadable assets.")
    else:
        lines.extend(
            [
                "| Asset | Size (bytes) | Total downloads | Change |",
                "|---|---:|---:|---:|",
            ]
        )
        for asset in release["assets"]:
            asset_delta = asset["downloads_delta"]
            asset_delta_text = "—" if asset_delta is None else f"{asset_delta:+d}"
            lines.append(
                f"| [{markdown_escape(asset['name'])}]({asset['browser_download_url']}) "
                f"| {asset['size']} | {asset['download_count']} | {asset_delta_text} |"
            )
    lines.append("")
    return "\n".join(lines)


def write_reports(
    output_dir: Path,
    history: Sequence[Mapping[str, Any]],
    snapshot: Mapping[str, Any],
) -> None:
    """Write the rolling CSV, current JSON snapshot, and Markdown summary."""
    output_dir.mkdir(parents=True, exist_ok=True)
    with (output_dir / "download-history.csv").open(
        "w", encoding="utf-8", newline=""
    ) as history_file:
        writer = csv.DictWriter(history_file, fieldnames=HISTORY_FIELDS)
        writer.writeheader()
        writer.writerows(history)

    with (output_dir / "latest-downloads.json").open(
        "w", encoding="utf-8"
    ) as snapshot_file:
        json.dump(snapshot, snapshot_file, indent=2, ensure_ascii=False)
        snapshot_file.write("\n")

    (output_dir / "summary.md").write_text(
        render_summary(snapshot), encoding="utf-8"
    )


def parse_args(argv: Optional[Sequence[str]] = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--repository", required=True, help="GitHub owner/repository")
    parser.add_argument("--history", type=Path, help="Prior download-history.csv")
    parser.add_argument("--output-dir", type=Path, required=True)
    return parser.parse_args(argv)


def main(argv: Optional[Sequence[str]] = None) -> int:
    args = parse_args(argv)
    try:
        raw_release = fetch_latest_release(args.repository, os.getenv("GH_TOKEN"))
        release = normalize_release(raw_release)
        history = read_history(args.history)
        previous_totals = previous_asset_totals(history)
        collected_at = datetime.now(timezone.utc).isoformat(timespec="seconds").replace(
            "+00:00", "Z"
        )
        snapshot = build_snapshot(
            args.repository, release, previous_totals, collected_at
        )
        updated_history = append_snapshot_rows(history, snapshot)
        write_reports(args.output_dir, updated_history, snapshot)
    except (CollectionError, OSError) as error:
        print(f"error: {error}", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
