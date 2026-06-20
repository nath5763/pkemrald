#include "feature_flags.h"
#include "gba/gba.h"
#include "main.h"

// Global feature flag registry instance
FeatureFlagRegistry gFeatureFlagRegistry;

// Global save block for feature flags
SaveBlockFeatureFlags gSaveBlockFeatureFlags;

// Test feature flags - will be replaced with actual flags
static const FeatureFlag sDefaultFlags[MAX_FEATURE_FLAGS] = {
    {.flagId = 0, .name = "Test Flag 1", .description = "First test feature flag", .defaultState = TRUE, .currentState = TRUE},
    {.flagId = 1, .name = "Test Flag 2", .description = "Second test feature flag", .defaultState = FALSE, .currentState = FALSE},
    {.flagId = 2, .name = "Test Flag 3", .description = "Third test feature flag", .defaultState = TRUE, .currentState = TRUE},
    {.flagId = 3, .name = "Test Flag 4", .description = "Fourth test feature flag", .defaultState = FALSE, .currentState = FALSE},
    {.flagId = 4, .name = "Test Flag 5", .description = "Fifth test feature flag", .defaultState = TRUE, .currentState = TRUE},
};

#define DEFAULT_FLAG_COUNT 5

// Initialize feature flag registry from save data or defaults
// Constitution Principle I: Checked Dynamic Allocation - uses static array, no malloc on startup
// Constitution Principle II: Deterministic Cleanup - all pointers to ROM (const), no cleanup needed
void InitializeFeatureFlagRegistry(void)
{
    u32 i;
    
    // Initialize all flags from defaults
    for (i = 0; i < DEFAULT_FLAG_COUNT && i < MAX_FEATURE_FLAGS; i++)
    {
        gFeatureFlagRegistry.flags[i] = sDefaultFlags[i];
        // Ensure we use the current state (should match default initially)
        gFeatureFlagRegistry.flags[i].currentState = sDefaultFlags[i].defaultState;
    }
    
    gFeatureFlagRegistry.flagCount = DEFAULT_FLAG_COUNT;
    gFeatureFlagRegistry.initialized = TRUE;
    
    // Try to load saved state from save block if version is valid
    LoadFeatureFlags();
}

// Get current state of a feature flag
// O(1) lookup by array index
bool8 GetFeatureFlagState(u32 flagId)
{
    if (!gFeatureFlagRegistry.initialized)
    {
        return FALSE;  // Return false if registry not initialized
    }
    
    if (flagId >= MAX_FEATURE_FLAGS || flagId >= gFeatureFlagRegistry.flagCount)
    {
        return FALSE;  // Invalid flagId; return false for safety
    }
    
    return gFeatureFlagRegistry.flags[flagId].currentState;
}

// Set feature flag state and persist to save data
// Updates registry and persists to save block
void SetFeatureFlagState(u32 flagId, bool8 newState)
{
    if (!gFeatureFlagRegistry.initialized)
    {
        return;  // Cannot set if registry not initialized
    }
    
    if (flagId >= MAX_FEATURE_FLAGS || flagId >= gFeatureFlagRegistry.flagCount)
    {
        return;  // Invalid flagId; ignore
    }
    
    // Update registry state
    gFeatureFlagRegistry.flags[flagId].currentState = newState;
    
    // Persist to save block immediately
    SaveFeatureFlags();
}

// Get total number of registered feature flags
u32 GetFeatureFlagCount(void)
{
    return gFeatureFlagRegistry.flagCount;
}

// Save all feature flag states to SaveBlockFeatureFlags
// Persists flag states to save file for retrieval on load
// Constitution Principle I: Allocation Safety - no malloc here; static data only
void SaveFeatureFlags(void)
{
    u32 i;
    
    if (!gFeatureFlagRegistry.initialized)
    {
        return;
    }
    
    // Set version to indicate this save block is valid
    gSaveBlockFeatureFlags.version = 1;
    
    // Copy all flag states to save block
    for (i = 0; i < gFeatureFlagRegistry.flagCount && i < MAX_FEATURE_FLAGS; i++)
    {
        gSaveBlockFeatureFlags.flagStates[i] = gFeatureFlagRegistry.flags[i].currentState ? 1 : 0;
    }
    
    // Initialize any unused flag slots to 0
    for (; i < MAX_FEATURE_FLAGS; i++)
    {
        gSaveBlockFeatureFlags.flagStates[i] = 0;
    }
    
    // Clear reserved bytes for compatibility
    for (i = 0; i < sizeof(gSaveBlockFeatureFlags.reserved); i++)
    {
        gSaveBlockFeatureFlags.reserved[i] = 0;
    }
}

// Load all feature flag states from SaveBlockFeatureFlags
// Handles version mismatches gracefully; new flags use defaults, existing flags restored from save
// Constitution Principle II: Cleanup - no pointers retained; immediate processing
void LoadFeatureFlags(void)
{
    u32 i;
    
    if (!gFeatureFlagRegistry.initialized)
    {
        return;
    }
    
    // Check if save block version is valid (version 1)
    if (gSaveBlockFeatureFlags.version != 1)
    {
        // Save block not initialized or version mismatch; use all defaults
        return;
    }
    
    // Restore flag states from save block
    for (i = 0; i < gFeatureFlagRegistry.flagCount && i < MAX_FEATURE_FLAGS; i++)
    {
        gFeatureFlagRegistry.flags[i].currentState = (gSaveBlockFeatureFlags.flagStates[i] != 0) ? TRUE : FALSE;
    }
}
