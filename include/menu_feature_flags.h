// Feature Flags Menu Integration
// 
// Public interface for integrating feature flags into the options menu
// These functions handle the UI/input for the Feature Flags options screen
//
// Constitution Compliance:
// - Principle I: Static screen state, no malloc
// - Principle II: All pointers to registry (const), no retained pointers
//

#ifndef GUARD_MENU_FEATURE_FLAGS_H
#define GUARD_MENU_FEATURE_FLAGS_H

// Initialize feature flags menu screen state
// Called when entering feature flags menu from options
void InitFeatureFlagsMenuScreen(void);

// Handle input for feature flags menu (UP/DOWN/A/B)
// 
// Parameters:
//   upPressed: TRUE if UP arrow was just pressed
//   downPressed: TRUE if DOWN arrow was just pressed
//   aPressed: TRUE if A button was just pressed
//   bPressed: TRUE if B button was just pressed
//
// Returns: TRUE if menu should close (B pressed), FALSE to continue
//
// NOTE: Caller (option_menu.c) is responsible for debouncing via JOY_NEW()
bool8 HandleFeatureFlagMenuInput(bool8 upPressed, bool8 downPressed, bool8 aPressed, bool8 bPressed);

// Render feature flags menu display
// Draws all flags with names, descriptions, and current state (ON/OFF)
void RenderFeatureFlagMenu(void);

// Get current menu state (for save/persistence integration)
bool8 IsFeatureFlagsMenuOpen(void);

// Close feature flags menu and return to options
void CloseFeatureFlagsMenu(void);

#endif // GUARD_MENU_FEATURE_FLAGS_H
