# Phase 1 Data Model: Feature Flags System

**Date**: 2026-06-19  
**Purpose**: Define entities, relationships, and validation rules for feature flag storage and retrieval

---

## Core Entities

### FeatureFlag

**Purpose**: Represents a single toggleable feature in the game

**Attributes**:
- `flagId` (u32): Unique identifier; used as array index for O(1) lookup
- `name` (const char*): Human-readable name displayed in options menu (e.g., "Expanded Moves")
- `description` (const char*): Tooltip/help text explaining what the flag enables
- `defaultState` (bool): Initial state when flag first appears (true=enabled, false=disabled)
- `currentState` (bool): Current runtime state; loaded from save or uses defaultState

**Relationships**:
- Belongs to: FeatureFlagRegistry (1 flag : 1 registry entry)
- Referenced by: SaveData (1 flag : 1 save state)

**Validation Rules**:
- flagId MUST be unique within registry (enforced at compile-time via macro)
- name MUST be non-empty (minimum 1 char, maximum 32 chars for menu display)
- name MUST NOT contain special UI control chars (newlines, tabs, etc.)
- All flags MUST have defaultState defined
- currentState MUST be valid (true or false only)

**Storage**: Static struct array in ROM; one entry per flag

---

### FeatureFlagRegistry

**Purpose**: Central collection of all feature flags; provides registration, lookup, and state management

**Attributes**:
- `flagCount` (u32): Total number of registered flags; typically 10-50
- `flags` (FeatureFlag[]): Array of all flags; indexed by flagId
- `initialized` (bool): True once all flags are loaded from save or defaults

**Operations**:
- `GetFlag(flagId)` → FeatureFlag*: O(1) lookup by ID
- `GetFlagState(flagId)` → bool: Get current state of flag
- `SetFlagState(flagId, newState)` → void: Update flag state and persist to save
- `InitializeFromSaveData(save)` → void: Load all flag states from save file; use defaults for new flags
- `SerializeToSaveData(save)` → void: Write all flag states to save struct

**Relationships**:
- Contains: Many FeatureFlags (1 registry : N flags)
- Used by: Options menu UI, game engine code querying flag state

**Validation Rules**:
- flagId parameter MUST exist in registry (bounds check before GetFlag)
- flagCount MUST match compile-time array size (enforced by macros)
- initialized flag MUST be true before any GetFlagState call

**Storage**: Static global registry instantiated at compile-time; one instance per ROM

---

### SaveBlockFeatureFlags

**Purpose**: Persistent storage of player feature flag preferences in save file

**Attributes**:
- `version` (u32): Save block version for future extensibility; current = 1
- `flagStates` (u8[]): Bit-packed or byte array of flag states; 1 byte per flag for simplicity
- `reserved` (u8[]): Reserved bytes for future extensions; MUST be zero-initialized

**Size Estimate**: 
- 50 flags × 1 byte per flag = 50 bytes minimum
- + version (4 bytes) = 54 bytes total
- Well within GBA save block size limits

**Relationships**:
- Extends: Existing save struct (SaveBlock in src/save/save.h)
- Read by: FeatureFlagRegistry::InitializeFromSaveData
- Written by: FeatureFlagRegistry::SerializeToSaveData

**Validation Rules**:
- version MUST equal current version (1); reject if mismatch
- flagStates array length MUST match FeatureFlagRegistry::flagCount
- All reserved bytes MUST be zero (for future compat)

**Storage**: Save file (cartridge); persisted when player saves game

---

### OptionsMenuScreen

**Purpose**: UI component that displays and allows toggling feature flags

**Attributes**:
- `selectedFlagIndex` (u32): Cursor position in flag list (0 to flagCount-1)
- `scrollOffset` (u32): First flag displayed on screen (handles lists > screen height)
- `isOpen` (bool): True while menu is active

**Operations**:
- `HandleInput(button)` → void: Process player input (up, down, A to toggle, B to close)
- `Render()` → void: Draw flag list and current flag state
- `OnToggle(flagId)` → void: Called when player toggles a flag; updates state and save

**Relationships**:
- Reads: FeatureFlagRegistry (current state for display)
- Modifies: FeatureFlagRegistry (calls SetFlagState)
- Updates: SaveData (via FeatureFlagRegistry::SerializeToSaveData)

**Validation Rules**:
- selectedFlagIndex MUST be < flagCount (bounds check on input)
- scrollOffset + visible_lines MUST not exceed flagCount

**Storage**: Transient; recreated each time menu opens

---

## State Transitions

### Flag Lifecycle

```
[Undefined] 
    ↓ (compile-time definition)
[Registered] 
    ↓ (game load / InitializeFromSaveData)
[Active with default OR saved state]
    ↓ (player toggles in menu OR code calls SetFlagState)
[Updated state persisted]
```

### Save Game Cycle

```
[Game Load]
    ↓
[InitializeFromSaveData: old saves load flags with defaults; new flags added]
    ↓
[FeatureFlagRegistry populated; game runs]
    ↓ (player toggles flag in options menu)
[SetFlagState: updates registry + calls SerializeToSaveData]
    ↓ (player saves game)
[SaveBlockFeatureFlags written to cartridge]
    ↓
[Game Load]: cycle repeats
```

---

## Backward Compatibility

**Old Save File Encountered**:
1. Save block read; version = 0 (not found)
2. Registry identifies version mismatch
3. All flags use defaultState
4. When player saves, version upgraded to 1 and all current states persisted

**New Flag Added to Code**:
1. Existing saves still load (old flag count respected)
2. New flag appears with defaultState
3. Once toggled, state persists in future saves

---

## Memory Layout

```
FeatureFlag struct (per flag):
  u32 flagId           (4 bytes)
  const char* name     (4 bytes pointer)
  const char* descr    (4 bytes pointer)
  u8 defaultState      (1 byte)
  u8 currentState      (1 byte)
  -----
  Total: 14 bytes per flag (with alignment: typically 16 bytes)

Example: 50 flags × 16 bytes = 800 bytes in ROM (negligible)

SaveBlockFeatureFlags (in save file):
  u32 version          (4 bytes)
  u8 flagStates[50]    (50 bytes)
  u8 reserved[14]      (14 bytes, MUST be 0)
  -----
  Total: 68 bytes per save (well within cartridge limits)
```

---

## Validation Summary

| Entity | Validation | Enforcement |
|--------|-----------|--------------|
| FeatureFlag | Unique ID, valid name | Compile-time macro check |
| FeatureFlagRegistry | ID bounds, state validity | Runtime bounds check + assert |
| SaveBlockFeatureFlags | Version match, array size | Load-time version check |
| OptionsMenuScreen | Cursor bounds, scroll bounds | Input handler bounds check |

---

## Phase 1 Completion

Data model defined with clear entities, relationships, and validation rules. Ready for contract definition and quickstart guide.
