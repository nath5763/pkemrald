---

description: "Task list for feature flags implementation"
---

# Tasks: Options Menu Feature Flags

**Input**: Design documents from `/specs/001-options-menu-feature-flags/`
**Prerequisites**: plan.md (required), spec.md (required for user stories), data-model.md, contracts/feature_flags.md, research.md, quickstart.md

**Tests**: No TDD tests requested. Tasks focus on implementation and integration validation.

**Organization**: Tasks are grouped by user story to enable independent implementation and testing of each story. All user stories are P1 (equal priority) but are sequenced for logical dependency management.

## Format: `[ID] [P?] [Story] Description`

- **[P]**: Can run in parallel (different files, no dependencies)
- **[Story]**: Which user story this task belongs to (e.g., US1, US2, US3)
- Include exact file paths in descriptions

## Path Conventions

- **Repository**: Repository root = `C:\Users\Shrinath\IdeaProjects\pokeemerald`
- **Source paths**: Relative to root (e.g., `src/data/feature_flags.h`)
- **Build command**: `make clean && make`

---

## Phase 1: Setup (Shared Infrastructure)

**Purpose**: Project initialization and tooling setup

- [x] T001 Create feature flags header file at `include/feature_flags.h` with public API declarations (GetFeatureFlagState, SetFeatureFlagState, InitializeFeatureFlagRegistry, GetFeatureFlagCount)
- [x] T002 Create feature flags source file at `src/data/feature_flags.c` with registry implementation and flag state management
- [x] T003 [P] Examine existing save block structure in `include/save.h` and plan SaveBlockFeatureFlags extension with version field and flag state array
- [x] T004 [P] Review existing options menu code (locate in `src/ui/menu_options.c` or equivalent) to understand UI pattern and navigation

**Checkpoint**: Feature flag infrastructure headers and save structure planned - ready for user story implementation

---

## Phase 2: Foundational (Blocking Prerequisites)

**Purpose**: Core infrastructure that MUST be complete before ANY user story can be implemented

- [x] T005 Define FeatureFlagRegistry struct in `include/feature_flags.h` with flagCount, flags array, initialized flag
- [x] T006 Define FeatureFlag struct in `include/feature_flags.h` with flagId, name, description, defaultState, currentState fields
- [x] T007 Extend SaveBlock struct in `include/save.h` to include SaveBlockFeatureFlags with version and flagStates array (68 bytes)
- [x] T008 Implement InitializeFeatureFlagRegistry() in `src/data/feature_flags.c` to load flags from compile-time definitions and apply saved state or defaults
- [x] T009 [P] Implement GetFeatureFlagState(flagId) in `src/data/feature_flags.c` with bounds checking and O(1) array lookup
- [x] T010 [P] Implement GetFeatureFlagCount() in `src/data/feature_flags.c` to return total registered flags
- [x] T011 Create REGISTER_FEATURE_FLAG() compile-time macro in `include/feature_flags.h` for flag registration with unique ID validation
- [x] T012 Add test flag definitions to `src/data/feature_flags.c` (at least 5 flags) for validation and user story testing
- [x] T013 Audit memory allocation safety: Confirm static array usage with no malloc on startup; review Constitution Principle I compliance in `src/data/feature_flags.c`
- [x] T014 Audit pointer cleanup: Confirm const pointers to ROM; temp buffers freed immediately; review Constitution Principle II compliance in `src/data/feature_flags.c`
- [x] T015 Verify build succeeds: `make clean && make` produces no compiler errors or warnings

**Checkpoint**: Foundation ready - all feature flags infrastructure in place, memory-safe, and buildable. User story implementation can now begin

---

## Phase 3: User Story 1 - Developer Adds Feature Flag (Priority: P1) 🎯

**Goal**: Enable developers to define feature flags that are registered and queryable at runtime without recompilation

**Independent Test**: Define a new feature flag via REGISTER_FEATURE_FLAG macro, verify it registers with correct ID/name/default, confirm GetFeatureFlagState returns correct value, test that SetFeatureFlagState updates state persistently

### Implementation for User Story 1

- [x] T016 [P] [US1] Implement SetFeatureFlagState(flagId, newState) in `src/data/feature_flags.c` to update registry state and persist to SaveBlockFeatureFlags
- [x] T017 [US1] Audit SetFeatureFlagState for save persistence: Confirm flag state written to save file and retrievable on next load (Constitution verification)
- [x] T018 [US1] Create documentation in `specs/001-options-menu-feature-flags/quickstart.md` demonstrating how to add a new flag (Step 1)
- [x] T019 [US1] Verify GetFeatureFlagState works correctly with all test flags defined in T012: Test at least 5 flags with different default states
- [x] T020 [US1] Test flag state toggling: Call SetFeatureFlagState multiple times on same flag, verify state updates each time and persists
- [x] T021 [US1] Add memory safety comments to `src/data/feature_flags.c` documenting flag ownership and cleanup (Constitution requirements)

**Checkpoint**: User Story 1 complete - developers can add feature flags, query state, and toggle programmatically

---

## Phase 4: User Story 2 - Player Toggles Feature Flag in Options Menu (Priority: P1)

**Goal**: Players can open options menu, navigate to feature flags screen, toggle flags, and see immediate updates

**Independent Test**: Open in-game options menu, navigate to Feature Flags section, toggle at least 3 different flags on/off, verify each toggle updates the display immediately, close and reopen menu to confirm transient UI state

### Implementation for User Story 2

- [ ] T022 [P] [US2] Extend `src/ui/menu_options.c` to add "Feature Flags" menu option to main options menu
- [ ] T023 [US2] Create OptionsMenuFeatureFlagsScreen struct in `src/ui/menu_options.c` with selectedFlagIndex, scrollOffset, isOpen fields
- [ ] T024 [US2] Implement HandleFeatureFlagMenuInput() in `src/ui/menu_options.c` to process up/down arrow keys for navigation and A button to toggle
- [ ] T025 [US2] Implement RenderFeatureFlagMenu() in `src/ui/menu_options.c` to display flag list with names, descriptions, and current state (on/off)
- [ ] T026 [P] [US2] Implement OnFeatureFlagToggle() callback in `src/ui/menu_options.c` to call SetFeatureFlagState when player toggles a flag
- [ ] T027 [US2] Handle menu scrolling: If flagCount > max displayable flags, implement scroll logic to show subset with cursor movement
- [ ] T028 [US2] Add button legend to menu display: Show "(↑↓: move, A: toggle, B: close)" below flag list
- [ ] T029 [US2] Test menu navigation: Start options menu, navigate to Feature Flags, verify all flags display, test up/down cursor movement
- [ ] T030 [US2] Test flag toggle from menu: Select flag, press A, verify state updates in display, toggle another flag and repeat
- [ ] T031 [US2] Test menu close/reopen: Toggle flags in menu, press B to close, reopen options and navigate back to Feature Flags - verify previous selections still shown
- [ ] T032 [US2] Verify no regression: Confirm existing options menu items (Sound, Text Speed) still work after integration

**Checkpoint**: User Story 2 complete - players can toggle feature flags from options menu with real-time feedback

---

## Phase 5: User Story 3 - Feature Flag Settings Persist Across Sessions (Priority: P1)

**Goal**: Player's feature flag choices are saved to the save file and restored when loading a save

**Independent Test**: Toggle flags in menu, save game, load game, verify all flags show previously toggled states, add new flag to code, load old save, verify new flag shows default state while old flags retain saved state

### Implementation for User Story 3

- [ ] T033 [P] [US3] Implement SaveFeatureFlags() in `src/data/feature_flags.c` to serialize flag states to SaveBlockFeatureFlags.flagStates array
- [ ] T034 [P] [US3] Implement LoadFeatureFlags() in `src/data/feature_flags.c` to deserialize flag states from SaveBlockFeatureFlags, handling version mismatches gracefully
- [ ] T035 [US3] Modify game save routine to call SaveFeatureFlags() when player saves game (integrate with existing save.c)
- [ ] T036 [US3] Modify game load routine to call LoadFeatureFlags() during save file load (integrate with existing save.c); handle new flags gracefully by using defaultState
- [ ] T037 [US3] Handle backward compatibility: When loading old save without SaveBlockFeatureFlags version field, initialize with defaultState for all flags
- [ ] T038 [US3] Test save cycle: Toggle flags in menu, save game, verify SaveBlockFeatureFlags written to file with correct flag states
- [ ] T039 [US3] Test load cycle: Load a saved game, verify flags restored to previously saved state; test at least 3 consecutive save/load cycles
- [ ] T040 [US3] Test new flag after old save: Add new flag definition to `src/data/feature_flags.c`, load old save created before new flag existed, verify new flag shows defaultState while existing flags retain saved state
- [ ] T041 [US3] Test save data corruption: Verify system gracefully handles corrupted SaveBlockFeatureFlags (e.g., invalid version) by logging error and using defaultState for all flags
- [ ] T042 [US3] Audit save/load for memory safety: Confirm all flag state reads/writes use safe patterns; review Constitution Principle I for allocation safety and Principle II for cleanup

**Checkpoint**: User Story 3 complete - player preferences persist across save/load cycles with backward compatibility

---

## Phase N: Polish & Cross-Cutting Concerns

**Purpose**: Final validation, documentation, and regression testing

- [ ] T043 [P] Build validation: `make clean && make` - confirm full ROM builds with no errors or warnings
- [ ] T044 [P] Regression test: Verify existing gameplay (battles, menu, save system) unaffected by feature flags integration
- [ ] T045 Functional end-to-end test: Complete US1+US2+US3 flow in-game (define flag, toggle in menu, save, load, verify)
- [ ] T046 [P] Memory audit: Confirm Constitution Principle I (checked allocation) and Principle II (pointer cleanup) compliance throughout implementation
- [ ] T047 Documentation: Verify `quickstart.md` matches final implementation; update if needed
- [ ] T048 [P] Success criteria validation: Confirm all 6 success criteria met (5+ flags toggleable, 3 save/load cycles work, descriptions clear, new flags auto-appear, ROM builds, < 1ms lookup)
- [ ] T049 Code review prep: Create summary of all Constitution-related changes and memory safety decisions for reviewer
- [ ] T050 Final ROM validation: ROM builds, feature flags appear in options menu, all toggles work, save/load persists state

**Checkpoint**: Implementation complete, tested, and ready for merge

---

## Dependencies & Execution Order

### Phase Dependencies

- **Setup (Phase 1)**: No dependencies - can start immediately
- **Foundational (Phase 2)**: Depends on Setup completion - BLOCKS all user stories (must complete before US1/US2/US3)
- **User Stories (Phase 3-5)**: All depend on Foundational phase completion
  - US1, US2, US3 can proceed in parallel (if staffed) AFTER Foundational
  - However, sequenced here for logical dependency: US1 (registry) → US2 (UI) → US3 (persistence)
  - In practice: US1 foundational work enables US2; US2 enables US3; but overlapping development is possible
- **Polish (Final Phase)**: Depends on all user stories being complete

### User Story Dependencies

- **User Story 1 (P1 - Developer Flag Registration)**: Can start after Foundational (Phase 2) - No dependencies on other stories
  - Tasks T016-T021 focus on flag state management and documentation
  - Independent test: Create flag, query/update state, confirm persistence

- **User Story 2 (P1 - Player Menu Toggling)**: Depends on US1 completion (needs working SetFeatureFlagState)
  - Tasks T022-T032 focus on menu UI and button handling
  - Independent test: Toggle flags in menu, verify real-time feedback
  - Can begin after T016 (SetFeatureFlagState) is implemented

- **User Story 3 (P1 - Save Persistence)**: Depends on US2 completion (needs menu to test)
  - Tasks T033-T042 focus on save/load serialization
  - Independent test: Toggle, save, load, verify state restored
  - Can begin after T026 (OnToggle callback) is implemented

### Within Each User Story

- Tests MUST be performed after all implementation tasks
- Audit tasks (memory safety) MUST run after implementation for that story
- Integration tests run after all user story tasks complete

### Parallel Opportunities

- **Phase 1 Setup**: T001 (header), T002 (source), T003 (save plan), T004 (menu review) can start independently
- **Phase 2 Foundational**: T009 (GetFlagState), T010 (GetCount) can run in parallel [P]
  - T003 (save plan), T004 (menu review) can run parallel to other foundational work [P]
- **Phase 3 (US1)**: No [P] tasks; implementation is sequential
- **Phase 4 (US2)**: T022 (menu option), T026 (toggle callback) can start in parallel [P]
- **Phase 5 (US3)**: T033 (save), T034 (load) can start in parallel [P]
- **Phase N (Polish)**: T043 (build), T044 (regression), T046 (memory audit) can run in parallel [P]

---

## Implementation Strategy

### MVP First (User Story 1 + User Story 2 Only - Minimum 2 Weeks)

1. Complete Phase 1: Setup (2 tasks: T001, T002)
2. Complete Phase 2: Foundational (10 tasks: T005-T015)
3. Complete Phase 3: User Story 1 (6 tasks: T016-T021)
4. Complete Phase 4: User Story 2 (11 tasks: T022-T032)
5. **STOP and VALIDATE**: Test US1+US2 independently (no persistence needed for MVP)
6. Deploy/demo MVP if ready

### Incremental Delivery (Add Persistence - Additional 1 Week)

1. Complete Phase 5: User Story 3 (10 tasks: T033-T042)
2. Run Phase N polish (8 tasks: T043-T050)
3. Final validation and merge

### Full Team Strategy (Parallel Work - 2 Weeks Total)

With 3 developers:
1. Week 1:
   - Developer A: Phase 1 Setup + Phase 2 Foundational (T001-T015)
   - Developer B: Awaits Phase 2 completion
   - Developer C: Awaits Phase 2 completion
2. Week 1 (Day 4+) - After Foundational done:
   - Developer A: US2 UI implementation (T022-T032)
   - Developer B: US1 state management (T016-T021)
   - Developer C: US3 save/load (T033-T042)
3. Week 2:
   - All: Polish & regression (T043-T050)
   - All: Final validation

---

## Notes

- [P] tasks = different files, no dependencies on incomplete tasks
- [Story] label maps task to specific user story for traceability
- Each user story should be independently completable and testable (but US2 depends on US1; US3 depends on US2)
- Memory safety audits (T013, T014, T021, T042, T046) are critical for Constitution compliance
- Build validation (T015, T043) must pass before proceeding to next phase
- Total: 50 tasks across 5 phases + polish
- Estimated effort: 2-3 weeks for experienced C developer on GBA ROM hacking
