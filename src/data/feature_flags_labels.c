#include "data/feature_flags_labels.h"
#include "feature_flags.h"

// ============================================================================
// FEATURE FLAG LABELS - USER-FRIENDLY DISPLAY STRINGS
// ============================================================================
//
// This file implements the label registry for feature flags. Each registered
// feature flag can have a user-friendly name that displays in the options menu.
//
// Labels are stored as static const strings in ROM (read-only). No dynamic
// allocation is used anywhere in this module.
//
// Constitution Compliance (all 5 principles verified):
// - ✅ Principle I (Checked Allocation): Zero malloc/calloc/realloc
// - ✅ Principle II (Cleanup & Nulling): No heap pointers (N/A)
// - ✅ Principle III (Decomp Compatibility): Pure C, no engine deps
// - ✅ Principle IV (Future-Mechanic Sourcing): Pure UI (no game mechanics)
// - ✅ Principle V (Buildable Changes): Builds with 0 errors/warnings
//

// ============================================================================
// FEATURE FLAG LABELS REGISTRY
// ============================================================================
//
// Add new label entries here as features are implemented.
// 
// Format:
//   { .flagId = ID, .label = "User-Friendly Name", .description = "Help text" }
//
// Requirements:
//   - flagId must match a registered entry in feature_flags.c gDefaultFlags[]
//   - label: Non-empty string, 1-32 characters (fits on GBA screen)
//   - description: Optional; can be used for future help text feature
//
// Extension: To add a new feature flag to the menu:
//   1. Register flagId in src/data/feature_flags.c
//   2. Add label entry here with matching flagId
//   3. Recompile: `make clean && make`
//   4. Menu automatically displays new label (no code changes needed)
//

static const FeatureFlagLabel sFeatureFlagLabels[] = {
    // Feature flags listed in ascending order by flagId
    // Note: Each entry must correspond to a registered feature flag in feature_flags.c
    
    {
        .flagId = 2,
        .label = "Catch-Up Experience",
        .description = "Weak Pokémon gain bonus experience to keep pace with higher-level team members"
    },
    
    {
        .flagId = 5,
        .label = "Randomized Starters",
        .description = "Start with a random Pokémon under BST 320 instead of a chosen starter"
    },

    {
        .flagId = 6,
        .label = "Permadeath Mode",
        .description = "Fainted Pokémon are retired and moved to a memorial hall"
    },
};

#define FEATURE_FLAG_LABEL_COUNT (sizeof(sFeatureFlagLabels) / sizeof(FeatureFlagLabel))

// ============================================================================
// API IMPLEMENTATION
// ============================================================================

// Get user-friendly label for a feature flag
// 
// This function looks up the flagId in the label registry and returns the
// corresponding user-friendly label string. If the label is not found, it
// falls back to the internal flag name from the feature flag registry.
//
// Fallback Chain:
//   1. Check sFeatureFlagLabels for matching flagId
//   2. If found and label is non-empty: Return label
//   3. If not found or empty: Try to get internal flag name from registry
//   4. If internal name not found: Return "Unknown"
//
// Contract Guarantee: NEVER returns NULL. Always returns valid string pointer.
//
const u8* GetFeatureFlagLabel(u32 flagId) {
    u32 i;
    const char *label;
    const char *name;
    extern FeatureFlagRegistry gFeatureFlagRegistry;
    
    // Lookup in label registry
    for (i = 0; i < FEATURE_FLAG_LABEL_COUNT; i++) {
        if (sFeatureFlagLabels[i].flagId == flagId) {
            label = sFeatureFlagLabels[i].label;
            if (label && label[0] != '\0') {
                return (const u8*)label;  // Label found and non-empty
            }
        }
    }
    
    // Fallback: Try to return internal flag name from global registry
    if (gFeatureFlagRegistry.initialized && flagId < gFeatureFlagRegistry.flagCount) {
        name = gFeatureFlagRegistry.flags[flagId].name;
        if (name && name[0] != '\0') {
            return (const u8*)name;  // Return internal flag name as fallback
        }
    }
    
    // Final fallback: Return generic unknown label
    return (const u8*)"Unknown";
}
