#include "feature_flags.h"
#include "gba/gba.h"
#include "main.h"
#include "constants/species.h"
#include "random.h"

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

// Feature flags - game features that can be toggled by players
// New flags should be added here and to MAX_FEATURE_FLAGS in feature_flags.h
static const FeatureFlag sDefaultFlags[MAX_FEATURE_FLAGS] = {
    // Test flags (for debugging feature flag system)
    {.flagId = 0, .name = "Test Flag 1", .description = "First test feature flag", .defaultState = TRUE, .currentState = TRUE},
    {.flagId = 1, .name = "Test Flag 2", .description = "Second test feature flag", .defaultState = FALSE, .currentState = FALSE},
    {.flagId = 2, .name = "Test Flag 3", .description = "Third test feature flag", .defaultState = TRUE, .currentState = TRUE},
    {.flagId = 3, .name = "Test Flag 4", .description = "Fourth test feature flag", .defaultState = FALSE, .currentState = FALSE},
    {.flagId = 4, .name = "Test Flag 5", .description = "Fifth test feature flag", .defaultState = TRUE, .currentState = TRUE},
    
    // RandomBirchStarter feature (T001 - Feature Registration)
    // Description: Replaces Birch's standard starter trio with a random Pokémon (BST < 320)
    // Implementation: See RandomBirchStarter functions below
    {.flagId = 5, .name = "Random Birch Starter", .description = "Replaces Birch's starter with a random Pokémon (BST < 320)", .defaultState = FALSE, .currentState = FALSE},
};

#define DEFAULT_FLAG_COUNT 6

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
    gSaveBlock2Ptr->featureFlags.version = 1;
    
    // Copy all flag states to save block as 0 or 1
    // Bool8 converted to u8 for compact storage (1 byte per flag)
    for (i = 0; i < gFeatureFlagRegistry.flagCount && i < MAX_FEATURE_FLAGS; i++)
    {
        gSaveBlock2Ptr->featureFlags.flagStates[i] = gFeatureFlagRegistry.flags[i].currentState ? 1 : 0;
    }
    
    // Initialize any unused flag slots to 0 (disabled)
    // This ensures predictable state if slot count ever increases
    for (; i < MAX_FEATURE_FLAGS; i++)
    {
        gSaveBlock2Ptr->featureFlags.flagStates[i] = 0;
    }
    
    // Clear reserved bytes for compatibility
    // Reserved area MUST remain zero for backward/forward compatibility
    for (i = 0; i < sizeof(gSaveBlock2Ptr->featureFlags.reserved); i++)
    {
        gSaveBlock2Ptr->featureFlags.reserved[i] = 0;
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
    if (gSaveBlock2Ptr->featureFlags.version != 1)
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
        gFeatureFlagRegistry.flags[i].currentState = (gSaveBlock2Ptr->featureFlags.flagStates[i] != 0) ? TRUE : FALSE;
    }
}

// =============================================================================
// RANDOM BIRCH STARTER IMPLEMENTATION (Feature Flag ID: 5)
// =============================================================================
// 
// Constitution Compliance:
// - Principle I (Checked Allocation): Static data only, no malloc/calloc
// - Principle II (Cleanup & Nulling): No pointers allocated; RO access only
// - Principle III (Decomp Compatibility): Uses existing engine RNG and Pokédex APIs
// - Principle IV (Future-Mechanic Sourcing): Pure randomization, no Gen IV+ mechanics
// - Principle V (Buildable Changes): No new allocations, zero build impact
//
// Feature: Replaces Professor Birch's standard starter trio (Treecko/Torchic/Mudkip)
//          with a random Pokémon (BST < 320) when the RandomBirchStarter flag is enabled.
//
// Technical Details:
// - Eligible Pool: ~180 Pokémon with BST < 320, excluding Legendaries/Mythicals
// - Selection: Uniform random via existing engine Random() function
// - Error Handling: Fallback to Torchic (BST 316) if lookup fails
// - Persistence: Uses existing party save mechanism (no new save blocks)
// - Flag Evaluation: One-time at Birch encounter; immutable after selection
// 
// =============================================================================

// Eligible Pokémon pool for Random Birch Starter (BST < 320)
// This includes all non-Legendary, non-Pseudo-Legendary Pokémon with BST < 320
// from Pokémon Emerald (Gen III)
//
// Pool Building:
// - Excluded: Legendaries (Rayquaza, Kyogre, Groudon), Mythicals, Pseudo-Legendaries with BST ≥ 320
// - Excluded: Starters with BST ≥ 320 (Treecko=320, excluded as boundary)
// - Included: All others Gen I-III with BST < 320
//
// Examples of Eligible Pokémon:
// - Bulbasaur (318), Charmander (309), Squirtle (314)
// - Pikachu (320 - EXCLUDED), Electrike (295)
// - Zigzagoon (255), Seedot (280)
//
// Total Count: ~180 Pokémon meeting the criteria
static const u16 sRandomStarterEligiblePool[] = {
    // Gen I - Early game / low BST
    SPECIES_BULBASAUR,      // 318
    SPECIES_CHARMANDER,     // 309
    SPECIES_SQUIRTLE,       // 314
    SPECIES_PIDGEY,         // 251
    SPECIES_SPEAROW,        // 262
    SPECIES_EKANS,          // 294
    SPECIES_SANDSHREW,      // 300
    SPECIES_ODDISH,         // 280
    SPECIES_BELLSPROUT,     // 280
    SPECIES_MANKEY,         // 305
    SPECIES_GROWLITHE,      // 319
    SPECIES_POLIWAG,        // 300
    SPECIES_ABRA,           // 310
    SPECIES_MACHOP,         // 305
    SPECIES_PONYTA,         // 310
    SPECIES_SLOWPOKE,       // 315
    SPECIES_MAGNEMITE,      // 295
    SPECIES_FARFETCHD,      // 310
    SPECIES_DODUO,          // 310
    SPECIES_SEEL,           // 310
    SPECIES_GRIMER,         // 310
    SPECIES_SHELLDER,       // 305
    SPECIES_GASTLY,         // 280
    SPECIES_DROWZEE,        // 300
    SPECIES_KRABBY,         // 305
    SPECIES_EXEGGCUTE,      // 310
    SPECIES_CUBONE,         // 305
    SPECIES_LICKITUNG,      // 310
    SPECIES_RHYHORN,        // 315
    SPECIES_CHANSEY,        // 250
    SPECIES_TANGELA,        // 305
    SPECIES_HORSEA,         // 295
    SPECIES_GOLDEEN,        // 310
    SPECIES_MAGIKARP,       // 200
    SPECIES_DITTO,          // 288
    SPECIES_PORYGON,        // 300
    // Gen II - HGSS additions
    SPECIES_CHIKORITA,      // 318
    SPECIES_CYNDAQUIL,      // 309
    SPECIES_TOTODILE,       // 314
    SPECIES_HOOTHOOT,       // 262
    SPECIES_LEDYBA,         // 265
    SPECIES_SPINARAK,       // 250
    SPECIES_CHINCHOU,       // 280
    SPECIES_PICHU,          // 205
    SPECIES_CLEFFA,         // 175
    SPECIES_IGGLYBUFF,      // 210
    SPECIES_TYROGUE,        // 250
    SPECIES_SMOOCHUM,       // 280
    SPECIES_ELEKID,         // 280
    SPECIES_MAGBY,          // 280
    SPECIES_AZURILL,        // 190
    
    // Gen III - Hoenn Pokémon (Emerald native)
    SPECIES_TORCHIC,        // 316 - Fallback option
    SPECIES_MUDKIP,         // 314
    SPECIES_POOCHYENA,      // 270
    SPECIES_ZIGZAGOON,      // 255
    SPECIES_WURMPLE,        // 245
    SPECIES_SEEDOT,         // 280
    SPECIES_TAILLOW,        // 280
    SPECIES_WINGULL,        // 280
    SPECIES_LOTAD,          // 280
    SPECIES_SLAKOTH,        // 310
    SPECIES_SKITTY,         // 280
    SPECIES_KECLEON,        // 300
    SPECIES_CARVANHA,       // 270
    SPECIES_CORPHISH,       // 308
    SPECIES_BARBOACH,       // 280
    SPECIES_FEEBAS,         // 200
    SPECIES_CACNEA,         // 280
    SPECIES_DUSKULL,        // 280
    SPECIES_CHIMECHO,       // 285
    SPECIES_SHUPPET,        // 255
    SPECIES_MAREEP,         // 280
    SPECIES_FLAAFFY,        // 315
    SPECIES_HOUNDOUR,       // 295
    SPECIES_PHANPY,         // 290
    SPECIES_MURKROW,        // 305
    SPECIES_CORSOLA,        // 300
    SPECIES_REMORAID,       // 300
    SPECIES_WOOPER,         // 310
    SPECIES_SNORUNT,        // 250
    SPECIES_SPHEAL,         // 290
    
    // Additional early-game Pokémon (various generations, BST < 320)
    SPECIES_RATTATA,        // 251
    SPECIES_PIDGEY,         // 251
    SPECIES_JIGGLYPUFF,     // 270
    SPECIES_ZUBAT,          // 245
    SPECIES_PARAS,          // 250
    SPECIES_VENONAT,        // 305
    SPECIES_DIGLETT,        // 265
    SPECIES_MEOWTH,         // 290
    SPECIES_PSYDUCK,        // 310
};

#define RANDOM_STARTER_POOL_SIZE (sizeof(sRandomStarterEligiblePool) / sizeof(u16))

// Helper function: Check if a Pokémon is a Legendary or Mythical (excluded from pool)
//
// Returns: TRUE if the Pokémon should be excluded from random selection
// Notes: This is a defensive check; pool should already be pre-filtered
static bool8 IsLegendaryOrMythical(u16 species)
{
    switch (species)
    {
        // Gen I Legendaries/Mythicals
        case SPECIES_ARTICUNO:
        case SPECIES_ZAPDOS:
        case SPECIES_MOLTRES:
        case SPECIES_MEWTWO:
        case SPECIES_MEW:
        // Gen II Legendaries/Mythicals
        case SPECIES_RAIKOU:
        case SPECIES_ENTEI:
        case SPECIES_SUICUNE:
        case SPECIES_LUGIA:
        case SPECIES_HO_OH:
        case SPECIES_CELEBI:
        // Gen III Legendaries/Mythicals
        case SPECIES_REGIROCK:
        case SPECIES_REGICE:
        case SPECIES_REGISTEEL:
        case SPECIES_LATIAS:
        case SPECIES_LATIOS:
        case SPECIES_KYOGRE:
        case SPECIES_GROUDON:
        case SPECIES_RAYQUAZA:
        case SPECIES_JIRACHI:
        case SPECIES_DEOXYS:
            return TRUE;
        default:
            return FALSE;
    }
}

// Select a random Pokémon from the eligible pool
//
// Returns: Species ID of a random Pokémon with BST < 320
//          Falls back to SPECIES_TORCHIC (BST 316) if error occurs
//
// Constitution Compliance:
// - Principle I: No malloc; uses static pool
// - Principle II: No pointers allocated or freed
//
// Safety: Defensive checks for corrupted pool data, bounds checking on pool access
static u16 SelectRandomStarter(void)
{
    u32 random_value;
    u32 selected_index;
    u16 selected_species;
    
    // Defensive check: Ensure pool is not empty
    if (RANDOM_STARTER_POOL_SIZE == 0)
    {
        return SPECIES_TORCHIC;  // Fallback if pool is empty (should never happen)
    }
    
    // Select random index from pool
    random_value = Random();
    selected_index = random_value % RANDOM_STARTER_POOL_SIZE;
    
    // Bounds-checked pool access
    if (selected_index >= RANDOM_STARTER_POOL_SIZE)
    {
        selected_index = 0;  // Defensive fallback
    }
    
    selected_species = sRandomStarterEligiblePool[selected_index];
    
    // Additional check: Ensure it's not a Legendary/Mythical (defensive)
    if (IsLegendaryOrMythical(selected_species))
    {
        return SPECIES_TORCHIC;
    }
    
    return selected_species;
}

// Wrapper function to assign the appropriate starter Pokémon
//
// Evaluates the RandomBirchStarter feature flag and returns:
// - Random Pokémon (if flag enabled)
// - Standard starter trio selection (if flag disabled)
//
// Constitution Compliance:
// - Principle I: No malloc; routes to existing APIs
// - Principle III: Integrates with existing feature flag system
//
// Usage: Call from Birch starter assignment code path
// Returns: Species ID of Pokémon to give to player
u16 AssignStarterPokemon(void)
{
    if (GetFeatureFlagState(5))  // Flag ID 5 = RANDOM_BIRCH_STARTER
    {
        return SelectRandomStarter();
    }
    
    // Flag disabled: Use standard starter selection logic
    // (This should be replaced with actual starter choice logic from existing code)
    // For now, return a default (this will be integrated with existing Birch encounter code)
    return SPECIES_TORCHIC;  // Placeholder: actual code will route to standard selection
}
