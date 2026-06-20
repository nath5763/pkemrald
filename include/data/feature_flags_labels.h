#ifndef GUARD_FEATURE_FLAGS_LABELS_H
#define GUARD_FEATURE_FLAGS_LABELS_H

#include "gba/types.h"

// ============================================================================
// FEATURE FLAG LABELS
// ============================================================================
// 
// This module maps numeric feature flag IDs to user-friendly display labels
// for the options menu. Labels are stored as static const strings in ROM.
//
// Constitution Compliance:
// - Principle I (Checked Allocation): All labels stored in ROM; no malloc
// - Principle II (Cleanup & Nulling): No heap memory; N/A
// - Principle III (Decomp Compatibility): Reuses window.c menu API
// - Principle IV (Future-Mechanic Sourcing): Pure UI; no gameplay mechanics
// - Principle V (Buildable Changes): Zero allocation sites; all static
//

// Feature label entry (maps flagId to display string)
typedef struct {
    u32 flagId;                    // Feature flag ID (from feature flag registry)
    const char *label;             // User-friendly display name (1-32 chars)
    const char *description;       // Optional: Help text for future UI tooltips
} FeatureFlagLabel;

// ===========================================================================
// PUBLIC API
// ===========================================================================

// Feature label registry (defined in feature_flags_labels.c)
// Contains mappings from flagId to user-friendly labels
extern const FeatureFlagLabel sFeatureFlagLabels[];

// Get user-friendly label for a feature flag
// 
// Args:
//   flagId: Numeric feature flag ID (1-100 per engine convention)
//
// Returns:
//   const u8* - Always returns valid non-NULL pointer to label string.
//   Never returns NULL. String is immutable (ROM resident).
//
// Contract Guarantees:
//   - Always returns valid pointer (never NULL)
//   - String is const and never freed
//   - Lookup is O(N) but table is small (< 50 entries typical)
//   - Safe to use without NULL checks
//
// Fallback Behavior:
//   - If flagId in label table: returns label from table
//   - If flagId NOT in label table: returns internal flag name from registry
//   - If internal flag name not found: returns "Unknown"
//
// Example:
//   const u8 *label = GetFeatureFlagLabel(5);  // "Randomized Starters"
//   const u8 *label = GetFeatureFlagLabel(999);  // "Unknown" (not found)
//
const u8* GetFeatureFlagLabel(u32 flagId);

#endif // GUARD_FEATURE_FLAGS_LABELS_H
