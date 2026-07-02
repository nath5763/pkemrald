#ifndef GUARD_FEATURE_FLAGS_H
#define GUARD_FEATURE_FLAGS_H

#include "global.h"

// Feature flag registry configuration (MAX_FEATURE_FLAGS defined in global.h)
// Feature flag save block structure (SaveBlockFeatureFlags defined in global.h)

// Individual feature flag entry
typedef struct {
    u32 flagId;            // Unique identifier (0-MAX_FEATURE_FLAGS-1)
    const char *name;      // Human-readable name (max 32 chars)
    const char *description;  // Help text for options menu
    bool8 defaultState;    // Default state when flag is new (TRUE=enabled, FALSE=disabled)
    bool8 currentState;    // Current runtime state
} FeatureFlag;

// Feature flag registry
typedef struct {
    u32 flagCount;         // Total number of registered flags
    FeatureFlag flags[MAX_FEATURE_FLAGS];  // Array of flag entries
    bool8 initialized;     // TRUE once registry is loaded from save or defaults
} FeatureFlagRegistry;

// Public API declarations

// Initialize feature flag registry from save data or defaults
// Called once during game initialization
void InitializeFeatureFlagRegistry(void);

// Get current state of a feature flag
// Returns: TRUE if flag is enabled, FALSE if disabled
// Preconditions: Registry must be initialized; flagId must be valid (0 <= flagId < flagCount)
bool8 GetFeatureFlagState(u32 flagId);

// Set feature flag state and persist to save data
// Updates registry and calls SaveFeatureFlags() internally
// Preconditions: Registry must be initialized; flagId must be valid
void SetFeatureFlagState(u32 flagId, bool8 newState);

// Get total number of registered feature flags
// Returns: Number of flags in registry (e.g., 10, 50)
// Usage: UI uses this to determine how many flags to display
u32 GetFeatureFlagCount(void);

// Save all feature flag states to SaveBlockFeatureFlags
// Called internally by SetFeatureFlagState() and during game save
// Persists flag states to save file
void SaveFeatureFlags(void);

// Load all feature flag states from SaveBlockFeatureFlags
// Called during game load; handles version mismatches gracefully
// New flags will use defaultState; existing flags restored from save
void LoadFeatureFlags(void);

// ============================================================================
// RANDOM BIRCH STARTER API
// ============================================================================
//
// Feature: Replaces Professor Birch's standard starter trio with a random
//          Pokémon (BST < 320) when the RandomBirchStarter flag is enabled.
//
// Integration Point: Call AssignStarterPokemon() from Birch starter assignment code
//
// Memory Safety:
// - No dynamic allocation (Constitution Principle I)
// - Uses static eligible pool data only
// - Defensive error handling with fallback to Torchic

// Assign starter Pokémon based on RandomBirchStarter flag state
// 
// Returns: Species ID of Pokémon to give to player
// 
// Behavior:
//   - If RandomBirchStarter flag is ENABLED: Returns random Pokémon (BST < 320)
//   - If RandomBirchStarter flag is DISABLED: Returns standard starter choice
//
// Error Handling: Falls back to Torchic (BST 316) on Pokédex lookup failure
// 
// Usage: Call from Birch encounter script where starter Pokémon is assigned to party
// Example:
//   u16 starter_species = AssignStarterPokemon();
//   CreatePokemon(..., starter_species, ...);
u16 AssignStarterPokemon(void);

// Macro for registering feature flags at compile-time
// Usage: Place in src/data/feature_flags.c
// Example:
//   REGISTER_FEATURE_FLAG(0, "Expanded Moves", "Enables Gen IV move set additions", TRUE)
//   REGISTER_FEATURE_FLAG(1, "Enhanced Items", "Adds new held items to battles", FALSE)
//
// This macro should be used to populate the global feature flag registry
// 
// MEMORY SAFETY (Constitution Compliance):
//   Principle I (Checked Allocation):
//   - Flags are defined at compile-time in ROM
//   - No dynamic allocation; static lifetime
//   - Max 50 flags = ~800 bytes in ROM
//   - Safe upper bound prevents overflow
//
//   Principle II (Cleanup & Nulling):
//   - All flag names and descriptions are const pointers to ROM
//   - No cleanup required; pointers valid for program lifetime
//   - No dangling pointer risks; ownership clear (registry owns all entries)
//   - No heap memory retained after initialization
#define REGISTER_FEATURE_FLAG(flagId, name, description, defaultState) \
    { .flagId = (flagId), .name = (name), .description = (description), \
      .defaultState = (defaultState), .currentState = (defaultState) }

// Global registry instance
// 
// OWNERSHIP & LIFETIME:
//   - Single owner: the global gFeatureFlagRegistry
//   - Lifetime: program runtime (static allocation)
//   - Access: thread-safe at GBA execution model (single-threaded)
//
// MEMORY LAYOUT:
//   - Size: ~800 bytes (50 flags × 16 bytes per flag entry)
//   - Storage: ROM-resident struct array
//   - Initialization: InitializeFeatureFlagRegistry() called at game startup
//
// SAFETY PROPERTIES:
//   - All pointers are const (name, description) → ROM
//   - currentState checked in bounds before access
//   - flagCount validated before array access
//   - Initialized flag prevents use before setup
extern FeatureFlagRegistry gFeatureFlagRegistry;

// Global save block for feature flags
//
// OWNERSHIP & INTEGRATION:
//   - Managed as part of SaveBlock hierarchy (like SaveBlock1/SaveBlock2)
//   - Lifetime: persists across save/load cycles
//   - Integrated into game's save/load flow via helper functions
//
// MEMORY LAYOUT:
//   - Size: 68 bytes (4-byte version + 50-byte flags + 14-byte reserved)
//   - Storage: RAM-resident during gameplay
//   - Persistence: serialized to cartridge Flash on game save
//
// VERSION HANDLING (Backward Compatibility):
//   - version = 0: Uninitialized save (uses all defaults on first load)
//   - version = 1: Current format (loads saved flag states)
//   - Future versions: Will use defaults, allowing safe format evolution
//
// SAFETY PROPERTIES:
//   - Bounds-checked writes: only 0-49 flag indices written
//   - Reserved bytes zeroed: ensures forward compatibility
//   - Version check prevents misinterpretation of old saves
//   - Graceful degradation: old saves with new flags use defaultState
// Note: SaveBlockFeatureFlags is stored in gSaveBlock2Ptr->featureFlags

#endif // GUARD_FEATURE_FLAGS_H
