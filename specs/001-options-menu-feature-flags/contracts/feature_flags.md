# Contract: Feature Flags Public API

**Date**: 2026-06-19  
**Purpose**: Define the public interface for feature flag registration and runtime queries

---

## Module: `include/feature_flags.h`

### Overview

Feature flags provide a simple, compile-time registry for toggling features in Pokemon Epoch Emerald. Developers define flags once via macro; players toggle them in the options menu; state persists to save file.

### Public API

#### Flag Registration Macro

```c
#define REGISTER_FEATURE_FLAG(flagId, name, description, defaultState)
```

**Purpose**: Register a feature flag at compile-time.

**Parameters**:
- `flagId` (u32): Unique ID for this flag (0-49 for 50-flag registry); used as array index
- `name` (const char*): Human-readable name for options menu (max 32 chars)
- `description` (const char*): Help text explaining what the flag does
- `defaultState` (bool): Default value (true=enabled, false=disabled)

**Example**:
```c
REGISTER_FEATURE_FLAG(0, "Expanded Moves", "Enables Gen IV move set additions", true)
REGISTER_FEATURE_FLAG(1, "Enhanced Items", "Adds new held items to battles", false)
```

**Usage Location**: `src/data/feature_flags.c` (centralized registry)

---

#### Get Flag State

```c
bool GetFeatureFlagState(u32 flagId)
```

**Purpose**: Query the current state of a feature flag at runtime.

**Parameters**:
- `flagId` (u32): ID of the flag to query

**Returns**: 
- `true`: Flag is enabled
- `false`: Flag is disabled

**Preconditions**: 
- FeatureFlagRegistry MUST be initialized (called during game load)
- `flagId` MUST be valid (0 ≤ flagId < flagCount)

**Usage Example**:
```c
if (GetFeatureFlagState(0)) {
    // Use expanded move set
} else {
    // Use base move set
}
```

---

#### Set Flag State

```c
void SetFeatureFlagState(u32 flagId, bool newState)
```

**Purpose**: Update a feature flag state and persist to save data.

**Parameters**:
- `flagId` (u32): ID of the flag to update
- `newState` (bool): New state value

**Side Effects**:
- Updates registry currentState
- Calls SaveFeatureFlags() to persist to save file
- Triggers callbacks if flag change affects active gameplay (optional in MVP)

**Preconditions**: 
- FeatureFlagRegistry MUST be initialized
- `flagId` MUST be valid

**Usage Example**:
```c
// Called from options menu when player toggles a flag
SetFeatureFlagState(1, true);  // Enable enhanced items
```

---

#### Initialize Registry

```c
void InitializeFeatureFlagRegistry(void)
```

**Purpose**: Load all feature flags from save data or use defaults.

**Called**: During game initialization (once, at startup)

**Behavior**:
1. Loads FeatureFlagRegistry from compile-time definitions
2. Reads SaveBlockFeatureFlags from current save
3. For each flag:
   - If save version matches: restore saved state
   - Else: use defaultState
4. Sets registry.initialized = true

**Preconditions**: None (first initialization call)

**Side Effects**: Populates registry with initial state

---

#### Get Flag Count

```c
u32 GetFeatureFlagCount(void)
```

**Purpose**: Get total number of registered feature flags.

**Returns**: Number of flags in registry (e.g., 10, 50)

**Usage**: Menu UI uses this to determine how many flags to display

---

### Save Data Contract

#### Save Block Structure

**Location**: `include/save.h` → SaveBlock struct extension

```c
typedef struct {
    u32 version;          // Current version: 1
    u8 flagStates[50];    // One byte per flag: 1=enabled, 0=disabled
    u8 reserved[14];      // MUST be zero for future compatibility
} SaveBlockFeatureFlags;
```

**Size**: 68 bytes

**Persistence**: Saved to cartridge when player saves game

**Version Handling**:
- Version 0 (not found): Flag is new; use defaultState
- Version 1 (current): Load flagStates array

---

## Module: `src/data/feature_flags.c`

### Registry Implementation

**Purpose**: Centralized definition of all feature flags

**Structure**:
```c
// Compile-time flag definitions via REGISTER_FEATURE_FLAG macro
// Example:
REGISTER_FEATURE_FLAG(0, "Expanded Moves", "...", true)
REGISTER_FEATURE_FLAG(1, "Enhanced Items", "...", false)
// ... up to 50 flags

// Global registry instance
FeatureFlagRegistry gFeatureFlagRegistry;

// Initialization, state queries, persistence functions
void InitializeFeatureFlagRegistry(void);
bool GetFeatureFlagState(u32 flagId);
void SetFeatureFlagState(u32 flagId, bool newState);
```

---

## Module: `src/ui/menu_options.c` (Extended)

### Options Menu Integration

**New Screen**: "Feature Flags"

**UI Flow**:
1. Player navigates to "Feature Flags" option in main menu
2. Menu displays list of all flags with current state
3. Player moves cursor (up/down arrow) to select flag
4. Player presses A to toggle state
5. State updates immediately in menu + saved to file
6. Player presses B to close and return to options

**Button Mapping**:
- Up/Down: Navigate flag list (with scrolling if > 5 flags)
- A: Toggle selected flag
- B: Close menu

**Display Format**:
```
Feature Flags
-----------
> Expanded Moves       [ON]
  Enhanced Items      [OFF]
  Custom Abilities    [ON]

(arrow keys: move, A: toggle, B: close)
```

---

## Error Handling

**Invalid Flag ID**: 
- Function: `GetFeatureFlagState(99)` where max flagId is 49
- Behavior: Assert fail (debug) or return false (release)
- Recovery: Fix code; no runtime recovery needed

**Registry Not Initialized**: 
- Function: `GetFeatureFlagState()` called before game load
- Behavior: Assert fail (debug) or return false (release)
- Recovery: Engine should initialize registry during game init

**Save Data Corrupted**: 
- Function: Load save with invalid version or corrupted flagStates
- Behavior: Log warning; use defaultState for all flags
- Recovery: Player can retoggle flags as desired

---

## Contract Validation

| Requirement | Test | Pass Criteria |
|-------------|------|--------------|
| Define flag at compile-time | REGISTER_FEATURE_FLAG macro used | Code compiles; flag appears in options menu |
| Query flag state | GetFeatureFlagState(id) returns value | Returns true/false matching current state |
| Toggle flag state | SetFeatureFlagState(id, newState) called | State updates in menu; persists to save |
| Save/load cycle | Toggle flag, save, load save | Flag state matches toggled value |
| Menu integration | Player toggles flag in options | Flag state updates + displays immediately |

---

## Phase 1 Completion

Public API defined with clear contracts for registration, runtime queries, and UI integration. Ready for implementation planning in Phase 2 (/speckit-tasks).
