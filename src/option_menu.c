#include "global.h"
#include "option_menu.h"
#include "bg.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sprite.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "gba/m4a_internal.h"
#include "constants/rgb.h"
#include "event_data.h"
#include "constants/flags.h"
#include "feature_flags.h"
#include "permadeath.h"
#include "menu_feature_flags.h"
#include "data/feature_flags_labels.h"

#define tMenuSelection data[0]
#define tTextSpeed data[1]
#define tBattleSceneOff data[2]
#define tBattleStyle data[3]
#define tSound data[4]
#define tButtonMode data[5]
#define tWindowFrameType data[6]
#define tCatchupExp data[7]
#define tLevelCap data[8]
#define tTeamExpShare data[9]
#define tRandomizedStarters data[10]
#define tMenuScrollOffset data[11]
#define tPreviousSelection data[12]
#define tPermadeath data[13]

enum
{
    MENUITEM_TEXTSPEED,
    MENUITEM_BATTLESCENE,
    MENUITEM_BATTLESTYLE,
    MENUITEM_SOUND,
    MENUITEM_RANDOMIZED_STARTERS,
    MENUITEM_CATCHUPEXP,
    MENUITEM_TEAMEXPSHARE,
    MENUITEM_LEVELCAP,
    MENUITEM_PERMADEATH,
    MENUITEM_BUTTONMODE,
    MENUITEM_FRAMETYPE,
    MENUITEM_CANCEL,
    MENUITEM_COUNT,
};

enum
{
    WIN_HEADER,
    WIN_OPTIONS
};

#define YPOS_TEXTSPEED    (MENUITEM_TEXTSPEED * 16)
#define YPOS_BATTLESCENE  (MENUITEM_BATTLESCENE * 16)
#define YPOS_BATTLESTYLE  (MENUITEM_BATTLESTYLE * 16)
#define YPOS_SOUND        (MENUITEM_SOUND * 16)
#define YPOS_RANDOMIZED_STARTERS (MENUITEM_RANDOMIZED_STARTERS * 16)
#define YPOS_CATCHUPEXP   (MENUITEM_CATCHUPEXP * 16)
#define YPOS_TEAMEXPSHARE (MENUITEM_TEAMEXPSHARE * 16)
#define YPOS_LEVELCAP     (MENUITEM_LEVELCAP * 16)
#define YPOS_PERMADEATH   (MENUITEM_PERMADEATH * 16)
#define YPOS_BUTTONMODE   (MENUITEM_BUTTONMODE * 16)
#define YPOS_FRAMETYPE    (MENUITEM_FRAMETYPE * 16)

// Calculate Y position accounting for scroll offset
#define CALC_YPOS(menuItemIndex, scrollOffset) (((menuItemIndex) - (scrollOffset)) * 16 + 1)

static void DrawAllOptionChoices(u8 taskId);
static void Task_OptionMenuFadeIn(u8 taskId);
static void Task_OptionMenuProcessInput(u8 taskId);
static void Task_OptionMenuSave(u8 taskId);
static void Task_OptionMenuFadeOut(u8 taskId);
static u8 TextSpeed_ProcessInput(u8 selection);
static void TextSpeed_DrawChoices(u8 selection, u8 scrollOffset);
static u8 BattleScene_ProcessInput(u8 selection);
static void BattleScene_DrawChoices(u8 selection, u8 scrollOffset);
static u8 BattleStyle_ProcessInput(u8 selection);
static void BattleStyle_DrawChoices(u8 selection, u8 scrollOffset);
static u8 Sound_ProcessInput(u8 selection);
static void Sound_DrawChoices(u8 selection, u8 scrollOffset);
static u8 FrameType_ProcessInput(u8 selection);
static void FrameType_DrawChoices(u8 selection, u8 scrollOffset);
static u8 ButtonMode_ProcessInput(u8 selection);
static void ButtonMode_DrawChoices(u8 selection, u8 scrollOffset);
static void DrawHeaderText(void);
static void DrawOptionMenuTexts(u8 scrollOffset);
static void DrawBgWindowFrames(void);
static u8  CatchupExp_ProcessInput(u8 selection);
static void CatchupExp_DrawChoices(u8 selection, u8 scrollOffset);
static u8  TeamExpShare_ProcessInput(u8 selection);
static void TeamExpShare_DrawChoices(u8 selection, u8 scrollOffset);
static u8  LevelCap_ProcessInput(u8 selection);
static void LevelCap_DrawChoices(u8 selection, u8 scrollOffset);
static u8  RandomizedStarters_ProcessInput(u8 selection);
static void RandomizedStarters_DrawChoices(u8 selection, u8 scrollOffset);
static u8  Permadeath_ProcessInput(u8 selection);
static void Permadeath_DrawChoices(u8 selection, u8 scrollOffset);
static void HighlightOptionMenuItem(u8 index, u8 scrollOffset);
static void UpdateOptionMenuScroll(u8 taskId);
static void RedrawOptionMenu(u8 taskId);

EWRAM_DATA static bool8 sArrowPressed = FALSE;

static const u8 sText_CatchupExp[] = _("Catch-up EXP");
static const u8 sText_TeamExpShare[] = _("Team EXP Share");
static const u8 sText_LevelCap[] = _("Level Cap");
static const u8 sText_RandomizedStarters[] = _("Random Starters");
static const u8 sText_Permadeath[] = _("Permadeath");
static const u8 sText_OptionCursor[] = _(">");
static const u8 sText_Off[]        = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}OFF");
static const u8 sText_On[]         = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}ON");
static const u8 *const sCatchupChoices[] = { sText_Off, sText_On };

static const u16 sOptionMenuText_Pal[] = INCBIN_U16("graphics/interface/option_menu_text.gbapal");
// note: this is only used in the Japanese release
static const u8 sEqualSignGfx[] = INCBIN_U8("graphics/interface/option_menu_equals_sign.4bpp");

static void DrawAllOptionChoices(u8 taskId)
{
    u8 i;
    u8 scrollOffset = gTasks[taskId].tMenuScrollOffset;
    u8 maxVisibleRows = 7;

    for (i = 0; i < MENUITEM_COUNT; i++)
    {
        // Only draw the choice if it is currently visible on the screen
        if (i >= scrollOffset && i < scrollOffset + maxVisibleRows)
        {
            switch (i)
            {
            case MENUITEM_TEXTSPEED:
                TextSpeed_DrawChoices(gTasks[taskId].tTextSpeed, scrollOffset);
                break;
            case MENUITEM_BATTLESCENE:
                BattleScene_DrawChoices(gTasks[taskId].tBattleSceneOff, scrollOffset);
                break;
            case MENUITEM_BATTLESTYLE:
                BattleStyle_DrawChoices(gTasks[taskId].tBattleStyle, scrollOffset);
                break;
            case MENUITEM_SOUND:
                Sound_DrawChoices(gTasks[taskId].tSound, scrollOffset);
                break;
            case MENUITEM_RANDOMIZED_STARTERS:
                RandomizedStarters_DrawChoices(gTasks[taskId].tRandomizedStarters, scrollOffset);
                break;
            case MENUITEM_CATCHUPEXP:
                CatchupExp_DrawChoices(gTasks[taskId].tCatchupExp, scrollOffset);
                break;
            case MENUITEM_TEAMEXPSHARE:
                TeamExpShare_DrawChoices(gTasks[taskId].tTeamExpShare, scrollOffset);
                break;
            case MENUITEM_LEVELCAP:
                LevelCap_DrawChoices(gTasks[taskId].tLevelCap, scrollOffset);
                break;
            case MENUITEM_PERMADEATH:
                Permadeath_DrawChoices(gTasks[taskId].tPermadeath, scrollOffset);
                break;
            case MENUITEM_BUTTONMODE:
                ButtonMode_DrawChoices(gTasks[taskId].tButtonMode, scrollOffset);
                break;
            case MENUITEM_FRAMETYPE:
                FrameType_DrawChoices(gTasks[taskId].tWindowFrameType, scrollOffset);
                break;
            }
        }
    }
}

static const u8 *const sOptionMenuItemsNames[MENUITEM_COUNT] =
{
    [MENUITEM_TEXTSPEED]   = gText_TextSpeed,
    [MENUITEM_BATTLESCENE] = gText_BattleScene,
    [MENUITEM_BATTLESTYLE] = gText_BattleStyle,
    [MENUITEM_SOUND]       = gText_Sound,
    [MENUITEM_RANDOMIZED_STARTERS] = sText_RandomizedStarters,
    [MENUITEM_CATCHUPEXP]  = sText_CatchupExp,
    [MENUITEM_TEAMEXPSHARE] = sText_TeamExpShare,
    [MENUITEM_LEVELCAP]    = sText_LevelCap,
    [MENUITEM_PERMADEATH]  = sText_Permadeath,
    [MENUITEM_BUTTONMODE]  = gText_ButtonMode,
    [MENUITEM_FRAMETYPE]   = gText_Frame,
    [MENUITEM_CANCEL]      = gText_OptionMenuCancel,
};

static const struct WindowTemplate sOptionMenuWinTemplates[] =
{
    [WIN_HEADER] = {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 1,
        .width = 26,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 2
    },
    [WIN_OPTIONS] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 5,
        .width = 26,
        .height = 14,
        .paletteNum = 1,
        .baseBlock = 0x36
    },
    DUMMY_WIN_TEMPLATE
};

static const struct BgTemplate sOptionMenuBgTemplates[] =
{
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 0,
        .charBaseIndex = 1,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    }
};

static const u16 sOptionMenuBg_Pal[] = {RGB(17, 18, 31)};


static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_InitOptionMenu(void)
{
    switch (gMain.state)
    {
    default:
    case 0:
        SetVBlankCallback(NULL);
        gMain.state++;
        break;
    case 1:
        DmaClearLarge16(3, (void *)(VRAM), VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sOptionMenuBgTemplates, ARRAY_COUNT(sOptionMenuBgTemplates));
        ChangeBgX(0, 0, BG_COORD_SET);
        ChangeBgY(0, 0, BG_COORD_SET);
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        ChangeBgX(2, 0, BG_COORD_SET);
        ChangeBgY(2, 0, BG_COORD_SET);
        ChangeBgX(3, 0, BG_COORD_SET);
        ChangeBgY(3, 0, BG_COORD_SET);
        InitWindows(sOptionMenuWinTemplates);
        DeactivateAllTextPrinters();
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 | WININ_WIN0_BG1 | WININ_WIN0_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        ShowBg(1);
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        gMain.state++;
        break;
    case 3:
        LoadBgTiles(1, GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, 0x1A2);
        gMain.state++;
        break;
    case 4:
        LoadPalette(sOptionMenuBg_Pal, BG_PLTT_ID(0), sizeof(sOptionMenuBg_Pal));
        LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, BG_PLTT_ID(7), PLTT_SIZE_4BPP);
        gMain.state++;
        break;
    case 5:
        LoadPalette(sOptionMenuText_Pal, BG_PLTT_ID(1), sizeof(sOptionMenuText_Pal));
        gMain.state++;
        break;
    case 6:
        PutWindowTilemap(WIN_HEADER);
        DrawHeaderText();
        gMain.state++;
        break;
    case 7:
        gMain.state++;
        break;
    case 8:
        PutWindowTilemap(WIN_OPTIONS);
        DrawOptionMenuTexts(0);  // Initial scroll offset is 0
        gMain.state++;
    case 9:
        DrawBgWindowFrames();
        gMain.state++;
        break;
    case 10:
    {
        u8 taskId = CreateTask(Task_OptionMenuFadeIn, 0);

        gTasks[taskId].tMenuSelection = 0;
        gTasks[taskId].tPreviousSelection = 0;
        gTasks[taskId].tMenuScrollOffset = 0;
        gTasks[taskId].tTextSpeed = gSaveBlock2Ptr->optionsTextSpeed;
        gTasks[taskId].tBattleSceneOff = gSaveBlock2Ptr->optionsBattleSceneOff;
        gTasks[taskId].tBattleStyle = gSaveBlock2Ptr->optionsBattleStyle;
        gTasks[taskId].tSound = gSaveBlock2Ptr->optionsSound;
        gTasks[taskId].tButtonMode = gSaveBlock2Ptr->optionsButtonMode;
        gTasks[taskId].tWindowFrameType = gSaveBlock2Ptr->optionsWindowFrameType;
        gTasks[taskId].tCatchupExp = FlagGet(FLAG_CATCHUP_ENABLED);
        gTasks[taskId].tTeamExpShare = FlagGet(FLAG_TEAM_EXP_SHARE_ENABLED);
        gTasks[taskId].tLevelCap = FlagGet(FLAG_LEVEL_CAP_ENABLED);
        gTasks[taskId].tPermadeath = FlagGet(FLAG_PERMADEATH);
        gTasks[taskId].tRandomizedStarters = FlagGet(FLAG_RANDOM_STARTER);

        TextSpeed_DrawChoices(gTasks[taskId].tTextSpeed, 0);
        BattleScene_DrawChoices(gTasks[taskId].tBattleSceneOff, 0);
        BattleStyle_DrawChoices(gTasks[taskId].tBattleStyle, 0);
        Sound_DrawChoices(gTasks[taskId].tSound, 0);
        CatchupExp_DrawChoices(gTasks[taskId].tCatchupExp, 0);
        TeamExpShare_DrawChoices(gTasks[taskId].tTeamExpShare, 0);
        LevelCap_DrawChoices(gTasks[taskId].tLevelCap, 0);
        Permadeath_DrawChoices(gTasks[taskId].tPermadeath, 0);
        RandomizedStarters_DrawChoices(gTasks[taskId].tRandomizedStarters, 0);
        ButtonMode_DrawChoices(gTasks[taskId].tButtonMode, 0);
        FrameType_DrawChoices(gTasks[taskId].tWindowFrameType, 0);
        HighlightOptionMenuItem(gTasks[taskId].tMenuSelection, gTasks[taskId].tMenuScrollOffset);

        CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
        gMain.state++;
        break;
    }
    case 11:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        return;
    }
}

static void Task_OptionMenuFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_OptionMenuProcessInput;
}

static void Task_OptionMenuProcessInput(u8 taskId)
{
    u8 previousSelection = gTasks[taskId].tPreviousSelection;

    if (JOY_NEW(A_BUTTON))
    {
        if (gTasks[taskId].tMenuSelection == MENUITEM_CANCEL)
            gTasks[taskId].func = Task_OptionMenuSave;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        gTasks[taskId].func = Task_OptionMenuSave;
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (gTasks[taskId].tMenuSelection > 0)
            gTasks[taskId].tMenuSelection--;

        UpdateOptionMenuScroll(taskId);
        RedrawOptionMenu(taskId);
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (gTasks[taskId].tMenuSelection < MENUITEM_CANCEL)
            gTasks[taskId].tMenuSelection++;

        UpdateOptionMenuScroll(taskId);
        RedrawOptionMenu(taskId);
    }
    else
    {
        u8 previousOption;

        switch (gTasks[taskId].tMenuSelection)
        {
        case MENUITEM_TEXTSPEED:
            previousOption = gTasks[taskId].tTextSpeed;
            gTasks[taskId].tTextSpeed = TextSpeed_ProcessInput(gTasks[taskId].tTextSpeed);

            if (previousOption != gTasks[taskId].tTextSpeed)
                TextSpeed_DrawChoices(gTasks[taskId].tTextSpeed, gTasks[taskId].tMenuScrollOffset);
            break;
        case MENUITEM_BATTLESCENE:
            previousOption = gTasks[taskId].tBattleSceneOff;
            gTasks[taskId].tBattleSceneOff = BattleScene_ProcessInput(gTasks[taskId].tBattleSceneOff);

            if (previousOption != gTasks[taskId].tBattleSceneOff)
                BattleScene_DrawChoices(gTasks[taskId].tBattleSceneOff, gTasks[taskId].tMenuScrollOffset);
            break;
        case MENUITEM_BATTLESTYLE:
            previousOption = gTasks[taskId].tBattleStyle;
            gTasks[taskId].tBattleStyle = BattleStyle_ProcessInput(gTasks[taskId].tBattleStyle);

            if (previousOption != gTasks[taskId].tBattleStyle)
                BattleStyle_DrawChoices(gTasks[taskId].tBattleStyle, gTasks[taskId].tMenuScrollOffset);
            break;
        case MENUITEM_SOUND:
            previousOption = gTasks[taskId].tSound;
            gTasks[taskId].tSound = Sound_ProcessInput(gTasks[taskId].tSound);

            if (previousOption != gTasks[taskId].tSound)
                Sound_DrawChoices(gTasks[taskId].tSound, gTasks[taskId].tMenuScrollOffset);
            break;
        case MENUITEM_RANDOMIZED_STARTERS:
            previousOption = gTasks[taskId].tRandomizedStarters;
            gTasks[taskId].tRandomizedStarters = RandomizedStarters_ProcessInput(gTasks[taskId].tRandomizedStarters);
            if (previousOption != gTasks[taskId].tRandomizedStarters)
                RandomizedStarters_DrawChoices(gTasks[taskId].tRandomizedStarters, gTasks[taskId].tMenuScrollOffset);
            break;
        case MENUITEM_CATCHUPEXP:
            previousOption = gTasks[taskId].tCatchupExp;
            gTasks[taskId].tCatchupExp = CatchupExp_ProcessInput(gTasks[taskId].tCatchupExp);
            if (previousOption != gTasks[taskId].tCatchupExp)
                CatchupExp_DrawChoices(gTasks[taskId].tCatchupExp, gTasks[taskId].tMenuScrollOffset);
            break;
        case MENUITEM_TEAMEXPSHARE:
            previousOption = gTasks[taskId].tTeamExpShare;
            gTasks[taskId].tTeamExpShare = TeamExpShare_ProcessInput(gTasks[taskId].tTeamExpShare);
            if (previousOption != gTasks[taskId].tTeamExpShare)
                TeamExpShare_DrawChoices(gTasks[taskId].tTeamExpShare, gTasks[taskId].tMenuScrollOffset);
            break;
        case MENUITEM_LEVELCAP:
            previousOption = gTasks[taskId].tLevelCap;
            gTasks[taskId].tLevelCap = LevelCap_ProcessInput(gTasks[taskId].tLevelCap);
            if (previousOption != gTasks[taskId].tLevelCap)
                LevelCap_DrawChoices(gTasks[taskId].tLevelCap, gTasks[taskId].tMenuScrollOffset);
            break;
        case MENUITEM_PERMADEATH:
            previousOption = gTasks[taskId].tPermadeath;
            gTasks[taskId].tPermadeath = Permadeath_ProcessInput(gTasks[taskId].tPermadeath);
            if (previousOption != gTasks[taskId].tPermadeath)
                Permadeath_DrawChoices(gTasks[taskId].tPermadeath, gTasks[taskId].tMenuScrollOffset);
            break;
        case MENUITEM_BUTTONMODE:
            previousOption = gTasks[taskId].tButtonMode;
            gTasks[taskId].tButtonMode = ButtonMode_ProcessInput(gTasks[taskId].tButtonMode);

            if (previousOption != gTasks[taskId].tButtonMode)
                ButtonMode_DrawChoices(gTasks[taskId].tButtonMode, gTasks[taskId].tMenuScrollOffset);
            break;
        case MENUITEM_FRAMETYPE:
            previousOption = gTasks[taskId].tWindowFrameType;
            gTasks[taskId].tWindowFrameType = FrameType_ProcessInput(gTasks[taskId].tWindowFrameType);

            if (previousOption != gTasks[taskId].tWindowFrameType)
                FrameType_DrawChoices(gTasks[taskId].tWindowFrameType, gTasks[taskId].tMenuScrollOffset);
            break;
        default:
            return;
        }

        if (sArrowPressed)
        {
            sArrowPressed = FALSE;
            CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
        }
    }

    // If selection changed, redraw the choices for the new menu item
    if (gTasks[taskId].tMenuSelection != previousSelection)
    {
        gTasks[taskId].tPreviousSelection = gTasks[taskId].tMenuSelection;
        RedrawOptionMenu(taskId);
    }
}

static void Task_OptionMenuSave(u8 taskId)
{
    gSaveBlock2Ptr->optionsTextSpeed = gTasks[taskId].tTextSpeed;
    gSaveBlock2Ptr->optionsBattleSceneOff = gTasks[taskId].tBattleSceneOff;
    gSaveBlock2Ptr->optionsBattleStyle = gTasks[taskId].tBattleStyle;
    gSaveBlock2Ptr->optionsSound = gTasks[taskId].tSound;
    gSaveBlock2Ptr->optionsButtonMode = gTasks[taskId].tButtonMode;
    gSaveBlock2Ptr->optionsWindowFrameType = gTasks[taskId].tWindowFrameType;
    if (gTasks[taskId].tCatchupExp)
        FlagSet(FLAG_CATCHUP_ENABLED);
    else
        FlagClear(FLAG_CATCHUP_ENABLED);

    if (gTasks[taskId].tTeamExpShare)
        FlagSet(FLAG_TEAM_EXP_SHARE_ENABLED);
    else
        FlagClear(FLAG_TEAM_EXP_SHARE_ENABLED);

    if (gTasks[taskId].tLevelCap)
        FlagSet(FLAG_LEVEL_CAP_ENABLED);
    else
        FlagClear(FLAG_LEVEL_CAP_ENABLED);
        
    if (gTasks[taskId].tPermadeath)
        FlagSet(FLAG_PERMADEATH);
    else
        FlagClear(FLAG_PERMADEATH);
    
    gTasks[taskId].tRandomizedStarters ? FlagSet(FLAG_RANDOM_STARTER) : FlagClear(FLAG_RANDOM_STARTER);

    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_OptionMenuFadeOut;
}

static void Task_OptionMenuFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        FreeAllWindowBuffers();
        SetMainCallback2(gMain.savedCallback);
    }
}

static void HighlightOptionMenuItem(u8 index, u8 scrollOffset)
{
    s32 yPos;
    yPos = CALC_YPOS(index, scrollOffset);
    AddTextPrinterParameterized(WIN_OPTIONS, FONT_NORMAL, sText_OptionCursor, 0, yPos + 1, TEXT_SKIP_DRAW, NULL);
}

static void UpdateOptionMenuScroll(u8 taskId)
{
    u8 selection = gTasks[taskId].tMenuSelection;
    u8 scrollOffset = gTasks[taskId].tMenuScrollOffset;
    const u8 maxVisibleRows = 7;

    if (selection < scrollOffset)
        scrollOffset = selection;
    else if (selection >= scrollOffset + maxVisibleRows)
        scrollOffset = selection - maxVisibleRows + 1;

    gTasks[taskId].tMenuScrollOffset = scrollOffset;
}

static void RedrawOptionMenu(u8 taskId)
{
    DrawOptionMenuTexts(gTasks[taskId].tMenuScrollOffset);
    DrawAllOptionChoices(taskId);
    HighlightOptionMenuItem(gTasks[taskId].tMenuSelection, gTasks[taskId].tMenuScrollOffset);
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
}

static void DrawOptionMenuChoice(const u8 *text, u8 x, u8 y, u8 style)
{
    u8 dst[16];
    u16 i;

    for (i = 0; *text != EOS && i < ARRAY_COUNT(dst) - 1; i++)
        dst[i] = *(text++);

    if (style != 0)
    {
        dst[2] = TEXT_COLOR_RED;
        dst[5] = TEXT_COLOR_LIGHT_RED;
    }

    dst[i] = EOS;
    AddTextPrinterParameterized(WIN_OPTIONS, FONT_NORMAL, dst, x, y + 1, TEXT_SKIP_DRAW, NULL);
}

static u8 TextSpeed_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection <= 1)
            selection++;
        else
            selection = 0;

        sArrowPressed = TRUE;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection != 0)
            selection--;
        else
            selection = 2;

        sArrowPressed = TRUE;
    }
    return selection;
}

static void TextSpeed_DrawChoices(u8 selection, u8 scrollOffset)
{
    u8 styles[3];
    s32 widthSlow, widthMid, widthFast, xMid;
    s32 yPos = CALC_YPOS(MENUITEM_TEXTSPEED, scrollOffset);

    styles[0] = 0;
    styles[1] = 0;
    styles[2] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_TextSpeedSlow, 104, yPos, styles[0]);

    widthSlow = GetStringWidth(FONT_NORMAL, gText_TextSpeedSlow, 0);
    widthMid = GetStringWidth(FONT_NORMAL, gText_TextSpeedMid, 0);
    widthFast = GetStringWidth(FONT_NORMAL, gText_TextSpeedFast, 0);

    widthMid -= 94;
    xMid = (widthSlow - widthMid - widthFast) / 2 + 104;
    DrawOptionMenuChoice(gText_TextSpeedMid, xMid, yPos, styles[1]);

    DrawOptionMenuChoice(gText_TextSpeedFast, GetStringRightAlignXOffset(FONT_NORMAL, gText_TextSpeedFast, 198), yPos, styles[2]);
}

static u8 CatchupExp_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;      // flip
        sArrowPressed = TRUE;
    }
    return selection;
}

static void CatchupExp_DrawChoices(u8 selection, u8 scrollOffset)
{
    u8 styles[2] = {0,0};
    s32 yPos = CALC_YPOS(MENUITEM_CATCHUPEXP, scrollOffset);
    styles[selection] = 1;

    // Right-side value column mimics other rows (x=104 and right-align at 198)
    DrawOptionMenuChoice(sText_Off, 104, yPos, styles[0]);
    DrawOptionMenuChoice(sText_On, GetStringRightAlignXOffset(FONT_NORMAL, sText_Off, 198),
                         yPos, styles[1]);
}

static u8 TeamExpShare_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }
    return selection;
}

static void TeamExpShare_DrawChoices(u8 selection, u8 scrollOffset)
{
    u8 styles[2] = {0, 0};
    s32 yPos = CALC_YPOS(MENUITEM_TEAMEXPSHARE, scrollOffset);

    styles[selection] = 1;
    DrawOptionMenuChoice(sText_Off, 104, yPos, styles[0]);
    DrawOptionMenuChoice(sText_On, GetStringRightAlignXOffset(FONT_NORMAL, sText_Off, 198),
                         yPos, styles[1]);
}

static u8 LevelCap_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }
    return selection;
}

static void LevelCap_DrawChoices(u8 selection, u8 scrollOffset)
{
    u8 styles[2] = {0, 0};
    s32 yPos = CALC_YPOS(MENUITEM_LEVELCAP, scrollOffset);
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_Off, 104, yPos, styles[0]);
    DrawOptionMenuChoice(sText_On, GetStringRightAlignXOffset(FONT_NORMAL, sText_Off, 198),
                         yPos, styles[1]);
}

static u8 Permadeath_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }
    return selection;
}

static void Permadeath_DrawChoices(u8 selection, u8 scrollOffset)
{
    u8 styles[2] = {0, 0};
    s32 yPos = CALC_YPOS(MENUITEM_PERMADEATH, scrollOffset);
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_Off, 104, yPos, styles[0]);
    DrawOptionMenuChoice(sText_On, GetStringRightAlignXOffset(FONT_NORMAL, sText_Off, 198),
                         yPos, styles[1]);
}

static u8 RandomizedStarters_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;      // flip
        sArrowPressed = TRUE;
    }
    return selection;
}

static u8 BattleScene_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }

    return selection;
}

static void BattleScene_DrawChoices(u8 selection, u8 scrollOffset)
{
    u8 styles[2];
    s32 yPos = CALC_YPOS(MENUITEM_BATTLESCENE, scrollOffset);

    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_BattleSceneOn, 104, yPos, styles[0]);
    DrawOptionMenuChoice(gText_BattleSceneOff, GetStringRightAlignXOffset(FONT_NORMAL, gText_BattleSceneOff, 198), yPos, styles[1]);
}

static u8 BattleStyle_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }

    return selection;
}

static void BattleStyle_DrawChoices(u8 selection, u8 scrollOffset)
{
    u8 styles[2];
    s32 yPos = CALC_YPOS(MENUITEM_BATTLESTYLE, scrollOffset);

    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_BattleStyleShift, 104, yPos, styles[0]);
    DrawOptionMenuChoice(gText_BattleStyleSet, GetStringRightAlignXOffset(FONT_NORMAL, gText_BattleStyleSet, 198), yPos, styles[1]);
}

static u8 Sound_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        SetPokemonCryStereo(selection);
        sArrowPressed = TRUE;
    }

    return selection;
}

static void Sound_DrawChoices(u8 selection, u8 scrollOffset)
{
    u8 styles[2];
    s32 yPos = CALC_YPOS(MENUITEM_SOUND, scrollOffset);

    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_SoundMono, 104, yPos, styles[0]);
    DrawOptionMenuChoice(gText_SoundStereo, GetStringRightAlignXOffset(FONT_NORMAL, gText_SoundStereo, 198), yPos, styles[1]);
}

static u8 FrameType_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection < WINDOW_FRAMES_COUNT - 1)
            selection++;
        else
            selection = 0;

        LoadBgTiles(1, GetWindowFrameTilesPal(selection)->tiles, 0x120, 0x1A2);
        LoadPalette(GetWindowFrameTilesPal(selection)->pal, BG_PLTT_ID(7), PLTT_SIZE_4BPP);
        sArrowPressed = TRUE;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection != 0)
            selection--;
        else
            selection = WINDOW_FRAMES_COUNT - 1;

        LoadBgTiles(1, GetWindowFrameTilesPal(selection)->tiles, 0x120, 0x1A2);
        LoadPalette(GetWindowFrameTilesPal(selection)->pal, BG_PLTT_ID(7), PLTT_SIZE_4BPP);
        sArrowPressed = TRUE;
    }
    return selection;
}

static void FrameType_DrawChoices(u8 selection, u8 scrollOffset)
{
    u8 text[16];
    u8 n = selection + 1;
    u16 i;
    s32 yPos = CALC_YPOS(MENUITEM_FRAMETYPE, scrollOffset);

    for (i = 0; gText_FrameTypeNumber[i] != EOS && i <= 5; i++)
        text[i] = gText_FrameTypeNumber[i];

    // Convert a number to decimal string
    if (n / 10 != 0)
    {
        text[i] = n / 10 + CHAR_0;
        i++;
        text[i] = n % 10 + CHAR_0;
        i++;
    }
    else
    {
        text[i] = n % 10 + CHAR_0;
        i++;
        text[i] = CHAR_SPACER;
        i++;
    }

    text[i] = EOS;

    DrawOptionMenuChoice(gText_FrameType, 104, yPos, 0);
    DrawOptionMenuChoice(text, 128, yPos, 1);
}

static u8 ButtonMode_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection <= 1)
            selection++;
        else
            selection = 0;

        sArrowPressed = TRUE;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection != 0)
            selection--;
        else
            selection = 2;

        sArrowPressed = TRUE;
    }
    return selection;
}

static void ButtonMode_DrawChoices(u8 selection, u8 scrollOffset)
{
    s32 widthNormal, widthLR, widthLA, xLR;
    u8 styles[3];
    s32 yPos = CALC_YPOS(MENUITEM_BUTTONMODE, scrollOffset);

    styles[0] = 0;
    styles[1] = 0;
    styles[2] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_ButtonTypeNormal, 104, yPos, styles[0]);

    widthNormal = GetStringWidth(FONT_NORMAL, gText_ButtonTypeNormal, 0);
    widthLR = GetStringWidth(FONT_NORMAL, gText_ButtonTypeLR, 0);
    widthLA = GetStringWidth(FONT_NORMAL, gText_ButtonTypeLEqualsA, 0);

    widthLR -= 94;
    xLR = (widthNormal - widthLR - widthLA) / 2 + 104;
    DrawOptionMenuChoice(gText_ButtonTypeLR, xLR, yPos, styles[1]);

    DrawOptionMenuChoice(gText_ButtonTypeLEqualsA, GetStringRightAlignXOffset(FONT_NORMAL, gText_ButtonTypeLEqualsA, 198), yPos, styles[2]);
}

static void RandomizedStarters_DrawChoices(u8 selection, u8 scrollOffset)
{
    u8 styles[2] = {0, 0};
    s32 yPos = CALC_YPOS(MENUITEM_RANDOMIZED_STARTERS, scrollOffset);

    styles[selection] = 1;

    DrawOptionMenuChoice(sText_Off, 104, yPos, styles[0]);
    DrawOptionMenuChoice(sText_On, GetStringRightAlignXOffset(FONT_NORMAL, sText_Off, 198),
                         yPos, styles[1]);
}

static void DrawHeaderText(void)
{
    FillWindowPixelBuffer(WIN_HEADER, PIXEL_FILL(1));
    AddTextPrinterParameterized(WIN_HEADER, FONT_NORMAL, gText_Option, 8, 1, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(WIN_HEADER, COPYWIN_FULL);
}

static void DrawOptionMenuTexts(u8 scrollOffset)
{
    u8 i;
    s32 yPos;
    u8 maxVisibleRows = 7;  // Fits 7 items on screen at 16 pixels each

    FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(1));

    // Render only visible items
    for (i = 0; i < MENUITEM_COUNT; i++)
    {
        // Calculate Y position relative to scroll offset
        yPos = ((i - scrollOffset) * 16) + 1;

        // Only render if item is within visible window
        if (i >= scrollOffset && i < scrollOffset + maxVisibleRows)
        {
            AddTextPrinterParameterized(WIN_OPTIONS, FONT_NORMAL, sOptionMenuItemsNames[i], 8, yPos, TEXT_SKIP_DRAW, NULL);
        }
    }

    CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
}

#define TILE_TOP_CORNER_L 0x1A2
#define TILE_TOP_EDGE     0x1A3
#define TILE_TOP_CORNER_R 0x1A4
#define TILE_LEFT_EDGE    0x1A5
#define TILE_RIGHT_EDGE   0x1A7
#define TILE_BOT_CORNER_L 0x1A8
#define TILE_BOT_EDGE     0x1A9
#define TILE_BOT_CORNER_R 0x1AA

static void DrawBgWindowFrames(void)
{
    //                     bg, tile,              x, y, width, height, palNum
    // Draw title window frame
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1,  0,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2,  0, 27,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28,  0,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_LEFT_EDGE,     1,  1,  1,  2,  7);
    FillBgTilemapBufferRect(1, TILE_RIGHT_EDGE,   28,  1,  1,  2,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1,  3,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2,  3, 27,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28,  3,  1,  1,  7);

    // Draw options list window frame
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1,  4,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2,  4, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28,  4,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_LEFT_EDGE,     1,  5,  1, 18,  7);
    FillBgTilemapBufferRect(1, TILE_RIGHT_EDGE,   28,  5,  1, 18,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1, 19,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2, 19, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28, 19,  1,  1,  7);

    CopyBgTilemapBufferToVram(1);
}
