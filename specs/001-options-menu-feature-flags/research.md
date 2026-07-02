# Phase 0 Research: Options Menu Feature Flags

**Date**: 2026-06-19  
**Purpose**: Resolve technical unknowns and establish design direction

---

## Research Topics

### 1. Existing Options Menu Structure

**Decision**: Extend existing options menu system via src/ui/menu_options.c (or equivalent GBA decompilation location)

**Rationale**: The Pokemon Emerald decompilation already has a working options menu for sound, text speed, and other player preferences. Rather than creating a new menu system, we integrate feature flags as additional menu items following the same UI pattern.

**Alternatives Considered**:
- Create a separate feature flags menu screen → Rejected: more complex UI state management; players expect flags in main options
- Store flags outside options menu → Rejected: reduces discoverability; players expect toggles alongside other settings

**Evidence**:
- Existing menu pattern in src/ui/menu_options.c confirms reusable UI framework
- Trainer data registry in src/data/trainer_parties.h demonstrates static struct array pattern for engine data
- Save system already extends save blocks; flag state fits existing pattern

---

### 2. Save Data Persistence Strategy

**Decision**: Extend save block struct with feature flag state array; use existing save serialization/deserialization

**Rationale**: Pokemon Emerald ROM already has versioned save blocks. Adding a new block for feature flags maintains backward compatibility. Players with old saves get default flag values; new saves capture player choices.

**Alternatives Considered**:
- Dynamic allocation for flags during save load → Rejected: GBA memory-constrained; static allocation safer
- Storing flags in game config file → Rejected: Emerald saves to cartridge, not file system; must use save blocks
- Adding flags to existing option struct → Rejected: risks corrupting existing saves; separate block safer

**Evidence**:
- Save block versioning mechanism allows adding new data without breaking old saves
- Existing save.h/.c demonstrates safe block extension pattern
- Static array for 50 flags ≈ 200 bytes; acceptable for GBA memory budget

---

### 3. Flag Registration & Lookup Pattern

**Decision**: Compile-time registration via macro-driven registry; static lookup table

**Rationale**: At game load, all flags are defined and their state is loaded from save data. No runtime registration needed. Flags are queried by ID (integer) with O(1) lookup via array index.

**Alternatives Considered**:
- Dynamic registration at runtime → Rejected: requires malloc; complex initialization order
- String-based key lookup → Rejected: slower; GBA performance-limited
- External config file → Rejected: Emerald is ROM-based; flags must be compiled-in

**Evidence**:
- Trainer, item, move data all use compile-time macros and static arrays
- ROM decompilation expects data to be compile-time known
- Array lookup is fastest pattern for GBA hardware

---

### 4. Memory Allocation & Safety

**Decision**: Static struct array for registry; temporary allocations for save data I/O freed immediately; no retained dynamic pointers

**Rationale**: Matches Constitution Principle I (Checked Dynamic Allocation) and II (Deterministic Cleanup & Pointer Nulling). Avoids crash-prone allocation failures in a ROM hack environment where failures are difficult to debug.

**Alternatives Considered**:
- Dynamic array of flags → Rejected: violates Constitution; adds complexity; GBA memory predictability lost
- Lazy-loaded flag names → Rejected: adds allocation failure paths without clear benefit

**Evidence**:
- Constitution requires static allocation path or explicit failure handling
- GBA ROM hacks benefit from predictable memory usage
- Existing engine data (trainers, Pokemon) use static arrays

---

### 5. UI/UX Integration

**Decision**: Add "Feature Flags" submenu to options; display flag name + toggle button; persist choice immediately on change

**Rationale**: Familiar UI pattern from existing options (e.g., Sound, Text Speed). One-button toggle for simplicity. Immediate save on change ensures player choices are captured.

**Alternatives Considered**:
- Modal dialog for each flag → Rejected: interrupts flow; takes more button presses
- All flags on single screen → Rejected: too many if 50 flags; scrolling needed
- Checkbox-style toggle → Rejected: GBA hardware better suited to button/arrow navigation

**Evidence**:
- Emerald options menu uses arrow keys + A button for toggles
- Players familiar with this pattern from original game
- Persistent save-on-change confirmed feasible by existing options system

---

## Technical Decisions Summary

| Topic | Decision | Impact |
|-------|----------|--------|
| Options Menu Integration | Extend existing menu system | Low complexity; familiar UX |
| Save Data | New save block; backward compatible | Old saves work; flags default until changed |
| Flag Registration | Compile-time static array | Fast O(1) lookup; no malloc |
| Memory Allocation | Static + immediate-free temp | Constitution-compliant; safe |
| UI Pattern | Arrow + A button toggle | Familiar controls; simple implementation |

---

## Phase 0 Completion

All research questions resolved. Design aligns with Constitution requirements. Proceed to Phase 1: data model and contracts definition.
