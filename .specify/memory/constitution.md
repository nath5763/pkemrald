<!--
Sync Impact Report
- Version change: template (unversioned) -> 1.0.0
- Modified principles:
  - Template principle slot 1 -> I. Checked Dynamic Allocation
  - Template principle slot 2 -> II. Deterministic Cleanup & Pointer Nulling
  - Template principle slot 3 -> III. Decomp-Compatible C and Engine Fidelity
  - Template principle slot 4 -> IV. Canonical Future-Mechanic Sourcing
  - Template principle slot 5 -> V. Buildable Changes & Regression Gates
- Added sections:
  - Implementation Standards
  - Workflow & Review
- Removed sections:
  - None
- Templates requiring updates:
  - ✅ .specify/templates/plan-template.md
  - ✅ .specify/templates/spec-template.md
  - ✅ .specify/templates/tasks-template.md
- Follow-up TODOs:
  - None
-->
# Pokemon Epoch Emerald Constitution

## Core Principles

### I. Checked Dynamic Allocation
Every dynamic allocation path in C MUST be checked before use. `malloc`, `calloc`,
`realloc`, allocator wrappers, and any helper that can return owned memory MUST
handle failure explicitly, MUST preserve the previous pointer across `realloc`
until success is confirmed, and MUST route failure to a visible error path or a
single cleanup path consistent with existing engine behavior. Ownership and
release expectations MUST be clear at the declaration, helper contract, or call
site. Rationale: unchecked allocation failures become crash-only bugs in a ROM
hack and are difficult to diagnose after assets, battle state, or save data are
already in motion.

### II. Deterministic Cleanup & Pointer Nulling
Owned heap memory MUST have one clear owner and one release path. After `free`
or ownership release, any pointer that remains live in the current scope, global
state, or a struct field MUST be set to `NULL` before control flow continues.
For local pointers that are released in a shared cleanup tail, the cleanup path
MUST leave the pointer `NULL` whenever execution can continue past the release.
Double-free-prone aliases, implicit ownership transfer, and cleanup that depends
on guesswork are prohibited. Rationale: explicit nulling and single-owner
cleanup prevent stale pointer reuse in long-lived engine code.

### III. Decomp-Compatible C and Engine Fidelity
Changes MUST preserve the repository's existing decompilation constraints:
GNU89-compatible C, established data layouts, deterministic engine behavior, and
the current build pipeline driven by `make`. Contributors MUST reuse existing
engine helpers, naming, and control-flow patterns before introducing new
abstractions. Any intentional gameplay or engine deviation MUST be called out in
the feature spec and implementation plan with the reason it cannot follow the
existing pattern. Rationale: compatibility with the decompilation toolchain and
binary expectations is part of correctness in this codebase.

### IV. Canonical Future-Mechanic Sourcing
Any mechanic, move, item, ability, evolution, battle rule, or other behavior
borrowed from games after Generation III MUST be derived from
`rh-hideout/pokeemerald-expansion`. The spec, plan, tasks, or PR description
MUST cite the upstream file paths and SHOULD include a commit or branch reference
when practical. Any deliberate deviation from upstream behavior MUST explain why
the change is needed for Pokemon Epoch Emerald. Rationale: a single upstream
source of truth prevents inconsistent fan-defined mechanics from entering the
project.

### V. Buildable Changes & Regression Gates
Every feature MUST define how compliance is verified before merge. At minimum,
the affected code path MUST be exercised, allocation-failure and cleanup paths
MUST be reviewed when dynamic memory is involved, and the repository MUST remain
buildable with the established `make` workflow. Changes that import
post-Generation III behavior MUST include regression checks for the adapted
mechanic and confirm that the upstream reference remains accurate. Rationale:
buildability and focused regression review are the minimum proof that a ROM-hack
change is safe to keep.

## Implementation Standards

- Specs for features that touch dynamic memory MUST identify the expected owner,
  the allocation failure behavior, and the cleanup/nulling path.
- Plans MUST record the concrete allocation sites, reused helpers, and any
  cleanup labels or ownership transfers that need reviewer attention.
- Tasks MUST include explicit work for allocation-safety review, pointer
  nulling after release, and upstream provenance capture when future mechanics
  are introduced.
- Post-Generation III mechanics MUST start from
  `rh-hideout/pokeemerald-expansion`, not from memory, summaries, or secondary
  tutorials.
- Changes to generated data, battle logic, or other high-risk systems MUST note
  the affected `make` targets or verification steps before implementation
  begins.

## Workflow & Review

- The Constitution Check in every implementation plan MUST confirm memory
  allocation safety, cleanup/nulling strategy, decomp compatibility, upstream
  sourcing, and build impact.
- Reviewers MUST reject changes that add or modify allocation sites without a
  checked failure path, a clear owner, and a documented cleanup strategy.
- Reviewers MUST reject future-mechanic work that does not cite the upstream
  `pokeemerald-expansion` implementation it derives from.
- Any exception to these rules MUST be documented in the plan's Complexity
  Tracking section with the simpler alternative and the reason it was rejected.

## Governance

This constitution supersedes conflicting local workflow notes for feature
specification, planning, and implementation. Amendments MUST update this file
and any impacted templates in the same change set. Semantic versioning applies
to the constitution itself: MAJOR for removing or redefining a principle in a
backward-incompatible way, MINOR for adding a new principle or materially
expanding governance, and PATCH for clarifications that do not change the
required behavior. Compliance review is mandatory during feature planning and
again before merge; non-compliant work MUST be blocked until the design or the
implementation is brought back into compliance.

**Version**: 1.0.0 | **Ratified**: 2026-06-19 | **Last Amended**: 2026-06-19
