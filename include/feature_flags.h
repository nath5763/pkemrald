#ifndef GUARD_FEATURE_FLAGS_H
#define GUARD_FEATURE_FLAGS_H

#include "gba/types.h"

// Feature flag registry configuration
#define MAX_FEATURE_FLAGS 50

// Feature flag save block structure
typedef struct {
    u32 version;           // Version: 1 for current, 0 for uninitialized
    u8 flagStates[MAX_FEATURE_FLAGS];  // One byte per flag: 1=enabled, 0=disabled
    u8 reserved[14];       // Reserved for future use (must be zero)
} SaveBlockFeatureFlags;  // sizeof: 68 bytes

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

// Macro for registering feature flags at compile-time
// Usage: Place in src/data/feature_flags.c
// Example:
//   REGISTER_FEATURE_FLAG(0, "Expanded Moves", "Enables Gen IV move set additions", TRUE)
//   REGISTER_FEATURE_FLAG(1, "Enhanced Items", "Adds new held items to battles", FALSE)
//
// This macro should be used to populate the global feature flag registry
#define REGISTER_FEATURE_FLAG(flagId, name, description, defaultState) \
    { .flagId = (flagId), .name = (name), .description = (description), \
      .defaultState = (defaultState), .currentState = (defaultState) }

// Global registry instance
extern FeatureFlagRegistry gFeatureFlagRegistry;

// Global save block for feature flags
extern SaveBlockFeatureFlags gSaveBlockFeatureFlags;

#endif // GUARD_FEATURE_FLAGS_H
