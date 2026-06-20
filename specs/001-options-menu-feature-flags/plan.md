# Implementation Plan: Options Menu Feature Flags

**Branch**: `001-options-menu-feature-flags` | **Date**: 2026-06-19 | **Spec**: [spec.md](spec.md)
**Input**: Feature specification from `/specs/001-options-menu-feature-flags/spec.md`

**Note**: This plan details the technical approach to implement a feature flag system in the options menu with persistent save data support.

## Summary

Implement a feature flag registry system that allows developers to define feature flags and players to toggle them in the options menu. The system must persist flag states to save data, maintain backward compatibility with existing saves, and follow safe memory management practices per the project constitution. The MVP includes three user stories: flag registration, player UI toggling, and save data persistence.

## Technical Context

**Language/Version**: C (GNU89), as per existing codebase decompilation constraints  
**Primary Dependencies**: Engine utilities from `src/main.h`, `src/gba/gba.h`; existing options menu system  
**Storage**: Save data struct extended with feature flag state; file-based save persistence  
**Testing**: ROM build validation; in-game options menu testing; save/load cycle verification  
**Target Platform**: Game Boy Advance (GBA) - Pokémon Emerald ROM  
**Project Type**: ROM hack decompilation with extended features  
**Performance Goals**: Flag lookup < 1ms; options menu navigation unchanged; no noticeable save/load delay  
**Constraints**: Memory-limited GBA target; existing save format compatibility; GNU89 C only  
**Scale/Scope**: Support 10-50 feature flags; extend existing options menu UI; preserve save data format versioning

## Constitution Check

*GATE: Must pass before Phase 0 research. Re-check after Phase 1 design.*

### Allocation Safety
- New feature flag registry will use static struct array to hold up to 50 flags (no dynamic allocation on startup)
- Each flag entry is fixed-size: unique ID (4 bytes), name pointer (4 bytes), state (1 byte), default (1 byte)
- No malloc/calloc used for core flag storage during normal operation; flag data is compile-time defined
- Save data serialization allocates temporary buffer during load via existing engine allocator if needed; ownership tracked to prevent leaks
- Failure path: if save data read fails, flags revert to defaults; visible error logged to console

### Cleanup & Nulling
- Core flag registry pointers (name strings) are const pointers to ROM data; no cleanup needed
- Any temporary save data buffer allocated during load is immediately freed after copy to permanent save struct; pointer not retained
- Pointers to flag names or states remain valid for engine lifetime (stored in global save context)
- No double-free risk: each flag entry has single owner (the global flag registry)

### Decomp Compatibility
- Reuses existing engine patterns: static struct arrays like trainer data, save blocks
- GNU89 C compliant; no C99/C11 features
- Integrates with existing options menu code (src/ui/menu_options.c or equivalent) rather than creating new abstractions
- Save data extends existing save blocks; respects ROM decompilation constraints
- Build via standard `make` workflow; no new tools required

### Future-Mechanic Provenance
- Feature flags are engine infrastructure, not mechanics; no future-generation mechanics involved
- Not applicable to this feature

### Verification
- Build verification: `make clean && make` succeeds with no warnings
- Regression check: existing options menu items still function (sound, text speed, etc.)
- Functional test: define test flag, toggle in menu, verify state persists across save/load
- Memory safety review: static allocation confirmed; no dynamic allocs on critical paths

**GATE RESULT**: ✅ PASS - All Constitution requirements satisfied. Proceed to Phase 0.

## Project Structure

### Documentation (this feature)

```text
specs/001-options-menu-feature-flags/
├── spec.md                         # Feature specification
├── plan.md                         # This file
├── research.md                     # Phase 0: research findings (to be created)
├── data-model.md                   # Phase 1: entity definitions (to be created)
├── quickstart.md                   # Phase 1: developer guide (to be created)
├── contracts/                      # Phase 1: data contracts (to be created)
│   └── feature_flags.md
├── checklists/
│   └── requirements.md             # Quality checklist
└── tasks.md                        # Phase 2: task breakdown (created by /speckit-tasks)
```

### Source Code (repository root)

```text
src/
├── data/
│   ├── feature_flags.h             # Feature flag definitions and registry
│   └── feature_flags.c             # Flag registration and runtime queries
├── ui/
│   └── menu_options.c              # Extended to include flag toggle menu
├── save/
│   ├── save.h                      # Save struct extended with flag block
│   └── save.c                      # Save serialization/deserialization
└── gba/
    └── gba.h                       # Core engine defs (unchanged)

include/
├── feature_flags.h                 # Public API header
└── save.h                          # Save struct declarations (extended)
```

**Structure Decision**: Single-module feature flag system integrated into existing engine. Core data structures are static arrays (no dynamic allocation). Save data extended via existing save block mechanism. Options menu UI extends existing src/ui/menu_options.c with new flag toggle screen.

## Complexity Tracking

No Constitution violations. The feature uses static allocation and follows all decomp compatibility requirements.

| Item | Status | Note |
|------|--------|------|
| Allocation Safety | ✅ | Static struct array; no dynamic allocation on startup; temp buffers freed immediately |
| Cleanup & Nulling | ✅ | Const pointers to ROM data; no cleanup needed; temp allocations freed within scope |
| Decomp Compatibility | ✅ | Reuses existing engine patterns; GNU89 C; integrates with existing options menu |
| Future-Mechanic Provenance | N/A | Not applicable; engine infrastructure, not mechanics |
| Verification | ✅ | Build, regression, and functional tests defined |
