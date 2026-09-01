import importlib.util
import json
import tempfile
import unittest
import urllib.error
from pathlib import Path
from unittest import mock


MODULE_PATH = Path(__file__).with_name("collect_release_downloads.py")
SPEC = importlib.util.spec_from_file_location("collect_release_downloads", MODULE_PATH)
metrics = importlib.util.module_from_spec(SPEC)
assert SPEC.loader is not None
SPEC.loader.exec_module(metrics)


def release_payload(release_id=10, asset_id=20, downloads=12):
    return {
        "id": release_id,
        "tag_name": "v2.0.0",
        "name": "Version 2.0",
        "html_url": "https://github.com/example/project/releases/tag/v2.0.0",
        "published_at": "2026-08-19T12:00:00Z",
        "assets": [
            {
                "id": asset_id,
                "name": "game-patch.ups",
                "content_type": "application/octet-stream",
                "size": 1234,
                "browser_download_url": "https://example.invalid/game-patch.ups",
                "download_count": downloads,
            }
        ],
    }


class DownloadMetricsTests(unittest.TestCase):
    def test_first_observation_has_no_delta_and_writes_all_reports(self):
        release = metrics.normalize_release(release_payload())
        snapshot = metrics.build_snapshot(
            "example/project", release, {}, "2026-08-20T09:17:00Z"
        )
        rows = metrics.append_snapshot_rows([], snapshot)

        self.assertIsNone(snapshot["release"]["downloads_delta"])
        self.assertIsNone(snapshot["release"]["assets"][0]["downloads_delta"])
        self.assertEqual(rows[0]["downloads_delta"], "")

        with tempfile.TemporaryDirectory() as temporary_directory:
            output_dir = Path(temporary_directory)
            metrics.write_reports(output_dir, rows, snapshot)
            self.assertEqual(
                {path.name for path in output_dir.iterdir()},
                {"download-history.csv", "latest-downloads.json", "summary.md"},
            )
            saved_snapshot = json.loads(
                (output_dir / "latest-downloads.json").read_text(encoding="utf-8")
            )
            self.assertEqual(saved_snapshot["release"]["downloads_total"], 12)

    def test_later_observation_appends_history_and_calculates_delta(self):
        old_release = metrics.normalize_release(release_payload(downloads=12))
        old_snapshot = metrics.build_snapshot(
            "example/project", old_release, {}, "2026-08-13T09:17:00Z"
        )
        history = metrics.append_snapshot_rows([], old_snapshot)
        new_release = metrics.normalize_release(release_payload(downloads=17))
        new_snapshot = metrics.build_snapshot(
            "example/project",
            new_release,
            metrics.previous_asset_totals(history),
            "2026-08-20T09:17:00Z",
        )
        updated_history = metrics.append_snapshot_rows(history, new_snapshot)

        self.assertEqual(new_snapshot["release"]["downloads_delta"], 5)
        self.assertEqual(new_snapshot["release"]["assets"][0]["downloads_delta"], 5)
        self.assertEqual(len(updated_history), 2)
        self.assertEqual(updated_history[-1]["downloads_delta"], 5)

    def test_new_release_asset_starts_with_an_unknown_delta(self):
        prior_history = [{field: "" for field in metrics.HISTORY_FIELDS}]
        prior_history[0].update(
            {"asset_id": "20", "downloads_total": "100"}
        )
        release = metrics.normalize_release(
            release_payload(release_id=11, asset_id=21, downloads=3)
        )
        snapshot = metrics.build_snapshot(
            "example/project",
            release,
            metrics.previous_asset_totals(prior_history),
            "2026-08-20T09:17:00Z",
        )

        self.assertIsNone(snapshot["release"]["assets"][0]["downloads_delta"])
        self.assertIsNone(snapshot["release"]["downloads_delta"])

    def test_release_without_assets_records_a_zero_download_observation(self):
        payload = release_payload()
        payload["assets"] = []
        release = metrics.normalize_release(payload)
        snapshot = metrics.build_snapshot(
            "example/project", release, {}, "2026-08-20T09:17:00Z"
        )
        rows = metrics.append_snapshot_rows([], snapshot)

        self.assertEqual(snapshot["release"]["downloads_total"], 0)
        self.assertEqual(len(rows), 1)
        self.assertEqual(rows[0]["asset_id"], "")
        self.assertIn("no downloadable assets", metrics.render_summary(snapshot))

    def test_invalid_previous_history_schema_is_rejected(self):
        with tempfile.TemporaryDirectory() as temporary_directory:
            history_path = Path(temporary_directory) / "history.csv"
            history_path.write_text("wrong,column\nvalue,value\n", encoding="utf-8")
            with self.assertRaises(metrics.CollectionError):
                metrics.read_history(history_path)

    def test_malformed_api_response_is_rejected(self):
        payload = release_payload()
        del payload["assets"][0]["download_count"]
        with self.assertRaisesRegex(metrics.CollectionError, "download_count"):
            metrics.normalize_release(payload)

    def test_http_failure_is_reported_without_response_body_or_token(self):
        failure = urllib.error.HTTPError(
            "https://api.github.com/repos/example/project/releases/latest",
            403,
            "Forbidden",
            {},
            None,
        )
        with mock.patch.object(metrics.urllib.request, "urlopen", side_effect=failure):
            with self.assertRaisesRegex(metrics.CollectionError, "HTTP 403"):
                metrics.fetch_latest_release("example/project", "secret-token")


if __name__ == "__main__":
    unittest.main()
