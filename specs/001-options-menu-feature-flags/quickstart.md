# Quickstart: Feature Flags Development Guide

**Date**: 2026-06-19  
**Audience**: Developers adding features to Pokemon Epoch Emerald

---

## Overview

The Feature Flags system allows you to create toggleable features that players can enable/disable from the options menu. Flags persist across save/load cycles, making them ideal for:
- Testing new game mechanics before finalizing them
- Offering optional enhancements (expanded move sets, new items, etc.)
- A/B testing features during ROM hack development

---

## Quick Start: Adding Your First Feature Flag

### Step 1: Define Your Flag

Open `src/data/feature_flags.c` and add a new flag using the macro:

```c
REGISTER_FEATURE_FLAG(2, "My New Feature", "Enable my awesome feature", false)
```

- **ID (2)**: Must be unique; use the next available number
- **Name ("My New Feature")**: Appears in the options menu; keep under 32 characters
- **Description**: Help text shown when flag is selected; briefly explain what it does
- **Default (false)**: Initial state; set true to enable by default

### Step 2: Check Your Flag State in Code

Anywhere in your game code, query the flag:

```c
#include "feature_flags.h"

// In a function where your feature is used:
if (GetFeatureFlagState(2)) {
    ApplyMyAwesomeFeature();
} else {
    UseOriginalBehavior();
}
```

### Step 3: Build and Test

```bash
make clean && make
```

If the build succeeds, start the ROM and:
1. Open the Options menu
2. Select "Feature Flags"
3. Toggle your flag on/off
4. See the changes take effect in the game
5. Save and load to confirm persistence

---

## Understanding the System

### Registry

All flags are registered compile-time in `src/data/feature_flags.c`. The registry is a global struct initialized during game load.

```
At startup:
  ↓
InitializeFeatureFlagRegistry() called
  ↓
Loads all flags from compile-time definitions
  ↓
Reads saved flag states from save file (or uses defaults)
  ↓
Game runs; flags ready to query
```

### Save Data

Flag states are stored in the save file. When you toggle a flag in the options menu:

```
Player toggles flag:
  ↓
SetFeatureFlagState(flagId, newState) called
  ↓
Registry updated + save file updated
  ↓
Changes persist when game is saved
```

### Options Menu Integration

The options menu automatically displays all registered flags. No code changes needed; just define the flag and it appears.

---

## Common Patterns

### Pattern 1: Simple Feature Toggle

**Goal**: Enable/disable a feature entirely.

**Code**:
```c
if (GetFeatureFlagState(MY_FLAG_ID)) {
    // New feature code
    DoNewThing();
} else {
    // Original behavior
    DoOriginalThing();
}
```

---

### Pattern 2: Debug Flag for Testing

**Goal**: Let QA/testers toggle debug features without recompiling.

**Definition** (in feature_flags.c):
```c
REGISTER_FEATURE_FLAG(10, "Debug Mode", "Enable debug features", false)
```

**Usage** (in any debug code):
```c
if (GetFeatureFlagState(10)) {
    PrintDebugInfo();
    AllowCheatCommands();
}
```

---

### Pattern 3: Mutually Exclusive Features

**Goal**: Only one of two features can be active (like choosing between two AI behaviors).

**Code**:
```c
if (GetFeatureFlagState(FEATURE_A)) {
    UseAIBehaviorA();
} else if (GetFeatureFlagState(FEATURE_B)) {
    UseAIBehaviorB();
} else {
    UseDefaultAIBehavior();
}
```

---

## Memory & Performance

### Memory Usage

- **Per flag in ROM**: ~16 bytes (ID, name pointer, description pointer, default state, reserved)
- **Per flag in save file**: 1 byte
- **For 50 flags**: ~800 bytes in ROM, 50 bytes in save file

GBA cartridge budget: Negligible impact.

### Performance

- **Flag lookup** (`GetFeatureFlagState`): O(1) array access; < 1 microsecond
- **Menu navigation**: No noticeable delay; same speed as existing options
- **Save/load cycle**: Minimal overhead; flag block ≈ 68 bytes

No performance concerns.

---

## Safety & Cleanup

The feature flag system follows Pokemon Epoch Emerald's Constitution:

- **Memory Allocation**: Static compile-time registry; no dynamic allocation on critical path
- **Pointer Cleanup**: No pointers retained after load; safe for long engine lifetime
- **Error Handling**: Invalid flag IDs return safe default (false); logged if debug enabled
- **Backward Compatibility**: Old saves load with default flag values; no corruption risk

---

## Troubleshooting

### Flag doesn't appear in menu

**Cause**: Flag not registered in `src/data/feature_flags.c`

**Fix**: Verify REGISTER_FEATURE_FLAG macro is present and ID is unique

### Flag state reverts after reload

**Cause**: SetFeatureFlagState() not being called; flag change not saved

**Fix**: Confirm toggle happens through options menu; check SaveFeatureFlags() is called

### Game crashes on flag lookup

**Cause**: GetFeatureFlagState() called before InitializeFeatureFlagRegistry()

**Fix**: Ensure registry initialization happens during game startup (before first flag query)

### Save file corrupted after adding flag

**Cause**: Unlikely; but if it happens, save version mismatch triggers safety revert

**Fix**: Load save; all new flags show default state; retoggle as needed

---

## Next Steps

1. **Define your flag**: Add REGISTER_FEATURE_FLAG to feature_flags.c
2. **Wrap your code**: Use GetFeatureFlagState() to conditionally enable feature
3. **Build**: `make clean && make`
4. **Test**: Toggle in options menu; save and load
5. **Verify**: Check that toggled behavior works and persists

---

## Advanced: Custom Save Block Extension

If you need to store more than a boolean (e.g., a numeric setting), extend SaveBlockFeatureFlags:

1. Add field to struct in `include/save.h`
2. Implement getter/setter in `src/data/feature_flags.c`
3. Call from code instead of simple boolean toggle

(Details in architectural documentation if needed.)

---

## API Reference

### Functions

| Function | Purpose | Returns |
|----------|---------|---------|
| `GetFeatureFlagState(u32 id)` | Query flag state | bool (true=enabled, false=disabled) |
| `SetFeatureFlagState(u32 id, bool state)` | Update flag state and save | void |
| `InitializeFeatureFlagRegistry()` | Load flags from save data | void |
| `GetFeatureFlagCount()` | Get total number of flags | u32 |

### Constants

| Name | Value | Use |
|------|-------|-----|
| `MAX_FEATURE_FLAGS` | 50 | Maximum flags supported |
| `FEATURE_FLAG_NAME_MAX` | 32 | Max length of flag name |

---

## Questions?

Refer to:
- `specs/001-options-menu-feature-flags/data-model.md` — Technical data structure details
- `specs/001-options-menu-feature-flags/contracts/feature_flags.md` — Complete API contract
- `specs/001-options-menu-feature-flags/spec.md` — Original feature specification
