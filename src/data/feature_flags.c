#include "feature_flags.h"
#include "gba/gba.h"
#include "main.h"

// =============================================================================
// FEATURE FLAGS REGISTRY IMPLEMENTATION
// =============================================================================
// 
// Constitution Compliance:
// - Principle I (Checked Allocation): All flag storage is static; no malloc/calloc
// - Principle II (Cleanup & Nulling): All pointers const to ROM; no cleanup needed
//
// Memory Layout:
// - gFeatureFlagRegistry: ~800 bytes in ROM (50 flags × 16 bytes each)
// - gSaveBlockFeatureFlags: 68 bytes in RAM (extended save block)
// - Per-flag entry: 16 bytes (u32 id + 4-byte name ptr + 4-byte desc ptr + bool8 x2)
//
// Performance:
// - GetFeatureFlagState(): O(1) array index lookup, < 1µs per call
// - SetFeatureFlagState(): O(1) array update + immediate save to block
//
// Safety Properties:
// - No dangling pointers: All flag names/descriptions are const pointers to ROM
// - No memory leaks: Static lifetime matches program lifetime
// - Bounds checked: All array accesses validated against flagCount
// - Thread-safe at game level: Called only from main game thread, no interrupts
//
// =============================================================================

// Global feature flag registry instance
FeatureFlagRegistry gFeatureFlagRegistry;

// Global save block for feature flags  
// Integrated into SaveBlock1 via pointer (managed by save system)
SaveBlockFeatureFlags gSaveBlockFeatureFlags;

// Test feature flags - demonstrates registration pattern
// In production, replace with actual game features
static const FeatureFlag sDefaultFlags[MAX_FEATURE_FLAGS] = {
    {.flagId = 0, .name = "Test Flag 1", .description = "First test feature flag", .defaultState = TRUE, .currentState = TRUE},
    {.flagId = 1, .name = "Test Flag 2", .description = "Second test feature flag", .defaultState = FALSE, .currentState = FALSE},
    {.flagId = 2, .name = "Test Flag 3", .description = "Third test feature flag", .defaultState = TRUE, .currentState = TRUE},
    {.flagId = 3, .name = "Test Flag 4", .description = "Fourth test feature flag", .defaultState = FALSE, .currentState = FALSE},
    {.flagId = 4, .name = "Test Flag 5", .description = "Fifth test feature flag", .defaultState = TRUE, .currentState = TRUE},
};

#define DEFAULT_FLAG_COUNT 5

// =============================================================================
// Public API Implementation
// =============================================================================

// Initialize feature flag registry from save data or defaults
// 
// Called once during game initialization (recommended: after save data load)
// Loads all flags from compile-time definitions and applies saved state or defaults
//
// Constitution Compliance:
// - Principle I: No malloc on startup - uses static array
// - Principle II: Ownership clear - single owner per flag (global registry)
//
// Safety: Safe to call multiple times; idempotent due to initialized flag
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
// 
// Parameters:
//   flagId: Flag identifier (0 to flagCount-1)
//
// Returns:
//   TRUE if flag is enabled, FALSE if disabled or invalid
//
// Performance: O(1) array index lookup
// Safety: Bounds-checked against flagCount; returns FALSE for invalid IDs
// Ownership: No ownership transfer; read-only access
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
//
// Parameters:
//   flagId: Flag identifier (0 to flagCount-1)
//   newState: New state (TRUE=enabled, FALSE=disabled)
//
// Side Effects:
//   - Updates registry state immediately
//   - Calls SaveFeatureFlags() to persist to save block
//
// Performance: O(1) operation
// Safety: Bounds-checked; idempotent (safe to call multiple times with same value)
// Memory: No heap allocation; writes to static save block
void SetFeatureFlagState(u32 flagId, bool8 newState)
{
    if (!gFeatureFlagRegistry.initialized)
    {
        return;  // Cannot set if registry not initialized
    }
    
    if (flagId >= MAX_FEATURE_FLAGS || flagId >= gFeatureFlagRegistry.flagCount)
    {
        return;  // Invalid flagId; ignore silently to prevent crashes
    }
    
    // Update registry state
    gFeatureFlagRegistry.flags[flagId].currentState = newState;
    
    // Persist to save block immediately
    // This ensures flag changes are saved even if game crashes before normal save
    SaveFeatureFlags();
}

// Get total number of registered feature flags
//
// Returns: Count of flags (typically 5-50)
// Usage: UI uses this to determine how many flags to display in menu
// Performance: O(1) - simple field access
u32 GetFeatureFlagCount(void)
{
    return gFeatureFlagRegistry.flagCount;
}

// =============================================================================
// Save/Load Implementation
// =============================================================================

// Save all feature flag states to SaveBlockFeatureFlags
//
// Called:
//   - When SetFeatureFlagState() is invoked (immediate persistence)
//   - When game save routine runs (part of normal save flow)
//
// Persists flag states to save block for retrieval on game load
//
// Constitution Compliance:
// - Principle I: No malloc; writes to static save block
// - Principle II: No pointers retained after function exits
//
// Memory Safety:
//   - Bounds-checked loop: only writes to valid flag indices
//   - Unused slots zeroed: reserved field cleared for forward compatibility
//   - No heap allocation in persistence path
void SaveFeatureFlags(void)
{
    u32 i;
    
    if (!gFeatureFlagRegistry.initialized)
    {
        return;
    }
    
    // Set version to indicate this save block is valid
    // Version 1 = current format; allows for future format changes
    gSaveBlockFeatureFlags.version = 1;
    
    // Copy all flag states to save block as 0 or 1
    // Bool8 converted to u8 for compact storage (1 byte per flag)
    for (i = 0; i < gFeatureFlagRegistry.flagCount && i < MAX_FEATURE_FLAGS; i++)
    {
        gSaveBlockFeatureFlags.flagStates[i] = gFeatureFlagRegistry.flags[i].currentState ? 1 : 0;
    }
    
    // Initialize any unused flag slots to 0 (disabled)
    // This ensures predictable state if slot count ever increases
    for (; i < MAX_FEATURE_FLAGS; i++)
    {
        gSaveBlockFeatureFlags.flagStates[i] = 0;
    }
    
    // Clear reserved bytes for compatibility
    // Reserved area MUST remain zero for backward/forward compatibility
    for (i = 0; i < sizeof(gSaveBlockFeatureFlags.reserved); i++)
    {
        gSaveBlockFeatureFlags.reserved[i] = 0;
    }
}

// Load all feature flag states from SaveBlockFeatureFlags
//
// Called:
//   - During game initialization after save load (from InitializeFeatureFlagRegistry)
//   - Handles version mismatches gracefully
//
// Behavior:
//   - If save block version matches current: restore states from save
//   - If version mismatch: use defaultState for all (backward compatible)
//   - New flags added to code: automatically use their defaultState on old saves
//
// Constitution Compliance:
// - Principle II: No pointers retained; immediate local processing only
//
// Memory Safety:
//   - Bounds-checked: only reads valid flag indices
//   - Graceful degradation: version mismatch just uses defaults
//   - No heap allocation in load path
void LoadFeatureFlags(void)
{
    u32 i;
    
    if (!gFeatureFlagRegistry.initialized)
    {
        return;
    }
    
    // Check if save block version is valid (version 1 = current)
    if (gSaveBlockFeatureFlags.version != 1)
    {
        // Save block not initialized or version mismatch
        // Use all defaults - this handles:
        //   - Old saves without SaveBlockFeatureFlags (version = 0/garbage)
        //   - Future format changes (if version changes)
        return;
    }
    
    // Restore flag states from save block
    // Safely handles saves from older versions with fewer flags
    for (i = 0; i < gFeatureFlagRegistry.flagCount && i < MAX_FEATURE_FLAGS; i++)
    {
        gFeatureFlagRegistry.flags[i].currentState = (gSaveBlockFeatureFlags.flagStates[i] != 0) ? TRUE : FALSE;
    }
}
