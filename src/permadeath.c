#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "feature_flags.h"
#include "list_menu.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "permadeath.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "window.h"
#include "constants/songs.h"
#include "data.h"

enum
{
    MEMORIAL_WIN_TITLE,
    MEMORIAL_WIN_LIST,
    MEMORIAL_WIN_DETAILS,
    MEMORIAL_WIN_COUNT
};

struct MemorialMenuState
{
    struct ListMenuItem listItems[RETIRED_MON_HISTORY_CAPACITY];
    u8 listNames[RETIRED_MON_HISTORY_CAPACITY][POKEMON_NAME_LENGTH + 1];
    struct RetiredMonRecord records[RETIRED_MON_HISTORY_CAPACITY];
    u8 windowIds[MEMORIAL_WIN_COUNT];
    u8 listTaskId;
    u8 scrollArrowTaskId;
    u16 count;
    u16 scrollOffset;
    u16 cursorPos;
};

static EWRAM_DATA struct MemorialMenuState sMemorialMenu = {0};

static const u8 sTextMemorialTitle[] = _("MEMORIAL HALL");
static const u8 sTextMemorialEmpty[] = _("No retired POKéMON.");
static const u8 sTextMemorialHint[] = _("B: Exit");
static const u8 sTextMemorialStatus[] = _("Retired from use.");
static const u8 sTextMemorialLv[] = _("Lv");

static const struct WindowTemplate sMemorialWindowTemplates[MEMORIAL_WIN_COUNT] =
{
    [MEMORIAL_WIN_TITLE] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 12,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 1
    },
    [MEMORIAL_WIN_LIST] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 4,
        .width = 12,
        .height = 12,
        .paletteNum = 15,
        .baseBlock = 25
    },
    [MEMORIAL_WIN_DETAILS] = {
        .bg = 0,
        .tilemapLeft = 14,
        .tilemapTop = 4,
        .width = 15,
        .height = 12,
        .paletteNum = 15,
        .baseBlock = 169
    },
};

static void Task_OpenMemorialPC(u8 taskId);
static void Task_HandleMemorialPCInput(u8 taskId);
static void DestroyMemorialWindows(void);
static void BuildMemorialList(void);
static void DrawMemorialTitle(void);
static void DrawMemorialDetails(s32 itemIndex);
static void MemorialMenuMoveCursor(s32 itemIndex, bool8 onInit, struct ListMenu *list);
static bool8 ShouldSkipPermadeathBattle(void);
static bool8 IsMonEligibleForRetirement(struct Pokemon *mon);
static bool8 IsMonAlreadyRetired(u32 personality);
static void BuildRetiredMonRecord(struct RetiredMonRecord *record, struct Pokemon *mon);
static void CopyRetiredMonNickname(u8 *dst, const struct RetiredMonRecord *record);

bool8 IsPermadeathEnabled(void)
{
    return GetFeatureFlagState(FEATURE_FLAG_PERMADEATH);
}

void TryRetireFaintedPlayerPartyMons(void)
{
    u8 i;
    u8 partyCount;
    bool8 retiredAny = FALSE;

    if (ShouldSkipPermadeathBattle())
        return;

    partyCount = CalculatePlayerPartyCount();
    for (i = 0; i < partyCount; i++)
    {
        struct Pokemon *mon = &gPlayerParty[i];
        struct RetiredMonRecord record;
        u32 personality;

        if (!IsMonEligibleForRetirement(mon))
            continue;

        personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
        if (IsMonAlreadyRetired(personality))
        {
            ZeroMonData(mon);
            retiredAny = TRUE;
            continue;
        }

        BuildRetiredMonRecord(&record, mon);
        AppendRetiredMonRecord(&record);
        ZeroMonData(mon);
        retiredAny = TRUE;
    }

    if (retiredAny)
    {
        CompactPartySlots();
        gPlayerPartyCount = CalculatePlayerPartyCount();
        gSaveBlock1Ptr->playerPartyCount = gPlayerPartyCount;
    }
}

void AccessMemorialPC(void)
{
    CreateTask(Task_OpenMemorialPC, 80);
}

static void Task_OpenMemorialPC(u8 taskId)
{
    u8 i;

    CpuFill16(0, &sMemorialMenu, sizeof(sMemorialMenu));
    for (i = 0; i < MEMORIAL_WIN_COUNT; i++)
        sMemorialMenu.windowIds[i] = WINDOW_NONE;
    sMemorialMenu.count = GetRetiredMonCount();
    sMemorialMenu.scrollArrowTaskId = 0xFF;

    DrawMemorialTitle();
    BuildMemorialList();

    gTasks[taskId].func = Task_HandleMemorialPCInput;
}

static void Task_HandleMemorialPCInput(u8 taskId)
{
    if (sMemorialMenu.count == 0)
    {
        if (JOY_NEW(A_BUTTON | B_BUTTON))
        {
            PlaySE(SE_SELECT);
            DestroyMemorialWindows();
            DestroyTask(taskId);
            ScriptContext_Enable();
        }
        return;
    }

    switch (ListMenu_ProcessInput(sMemorialMenu.listTaskId))
    {
    case LIST_NOTHING_CHOSEN:
        return;
    case LIST_CANCEL:
        PlaySE(SE_SELECT);
        DestroyListMenuTask(sMemorialMenu.listTaskId, &sMemorialMenu.scrollOffset, &sMemorialMenu.cursorPos);
        if (sMemorialMenu.scrollArrowTaskId != 0xFF)
            RemoveScrollIndicatorArrowPair(sMemorialMenu.scrollArrowTaskId);
        DestroyMemorialWindows();
        DestroyTask(taskId);
        ScriptContext_Enable();
        break;
    default:
        PlaySE(SE_SELECT);
        DrawMemorialDetails(sMemorialMenu.scrollOffset + sMemorialMenu.cursorPos);
        break;
    }
}

static void DestroyMemorialWindows(void)
{
    u8 i;

    for (i = 0; i < MEMORIAL_WIN_COUNT; i++)
    {
        if (sMemorialMenu.windowIds[i] != WINDOW_NONE)
        {
            ClearStdWindowAndFrame(sMemorialMenu.windowIds[i], TRUE);
            RemoveWindow(sMemorialMenu.windowIds[i]);
            sMemorialMenu.windowIds[i] = WINDOW_NONE;
        }
    }
}

static void BuildMemorialList(void)
{
    u8 i;
    u8 windowId;

    windowId = AddWindow(&sMemorialWindowTemplates[MEMORIAL_WIN_LIST]);
    sMemorialMenu.windowIds[MEMORIAL_WIN_LIST] = windowId;
    DrawStdWindowFrame(windowId, FALSE);

    windowId = AddWindow(&sMemorialWindowTemplates[MEMORIAL_WIN_DETAILS]);
    sMemorialMenu.windowIds[MEMORIAL_WIN_DETAILS] = windowId;
    DrawStdWindowFrame(windowId, FALSE);

    if (sMemorialMenu.count == 0)
    {
        FillWindowPixelBuffer(sMemorialMenu.windowIds[MEMORIAL_WIN_LIST], PIXEL_FILL(1));
        FillWindowPixelBuffer(sMemorialMenu.windowIds[MEMORIAL_WIN_DETAILS], PIXEL_FILL(1));
        AddTextPrinterParameterized(sMemorialMenu.windowIds[MEMORIAL_WIN_DETAILS], FONT_NORMAL, sTextMemorialEmpty, 8, 8, 0, NULL);
        AddTextPrinterParameterized(sMemorialMenu.windowIds[MEMORIAL_WIN_DETAILS], FONT_NORMAL, sTextMemorialHint, 8, 32, 0, NULL);
        CopyWindowToVram(sMemorialMenu.windowIds[MEMORIAL_WIN_LIST], COPYWIN_FULL);
        CopyWindowToVram(sMemorialMenu.windowIds[MEMORIAL_WIN_DETAILS], COPYWIN_FULL);
        return;
    }

    for (i = 0; i < sMemorialMenu.count; i++)
    {
        GetRetiredMonRecord(i, &sMemorialMenu.records[i]);
        CopyRetiredMonNickname(sMemorialMenu.listNames[i], &sMemorialMenu.records[i]);
        if (sMemorialMenu.listNames[i][0] == EOS)
            StringCopy(sMemorialMenu.listNames[i], gSpeciesNames[sMemorialMenu.records[i].species]);

        sMemorialMenu.listItems[i].name = sMemorialMenu.listNames[i];
        sMemorialMenu.listItems[i].id = i;
    }

    FillWindowPixelBuffer(sMemorialMenu.windowIds[MEMORIAL_WIN_LIST], PIXEL_FILL(1));
    FillWindowPixelBuffer(sMemorialMenu.windowIds[MEMORIAL_WIN_DETAILS], PIXEL_FILL(1));

    gMultiuseListMenuTemplate = (struct ListMenuTemplate){
        .items = sMemorialMenu.listItems,
        .moveCursorFunc = MemorialMenuMoveCursor,
        .itemPrintFunc = NULL,
        .totalItems = sMemorialMenu.count,
        .maxShowed = 8,
        .windowId = sMemorialMenu.windowIds[MEMORIAL_WIN_LIST],
        .header_X = 0,
        .item_X = 8,
        .cursor_X = 0,
        .upText_Y = 2,
        .cursorPal = 2,
        .fillValue = 1,
        .cursorShadowPal = 3,
        .lettersSpacing = 0,
        .itemVerticalPadding = 2,
        .scrollMultiple = LIST_MULTIPLE_SCROLL_DPAD,
        .fontId = FONT_NORMAL,
        .cursorKind = CURSOR_BLACK_ARROW
    };

    sMemorialMenu.listTaskId = ListMenuInit(&gMultiuseListMenuTemplate, sMemorialMenu.scrollOffset, sMemorialMenu.cursorPos);
    if (sMemorialMenu.count > gMultiuseListMenuTemplate.maxShowed)
    {
        sMemorialMenu.scrollArrowTaskId = AddScrollIndicatorArrowPairParameterized(
            SCROLL_ARROW_UP, 104, 44, 132, sMemorialMenu.count - gMultiuseListMenuTemplate.maxShowed, 5500, 5500, &sMemorialMenu.scrollOffset);
    }

    DrawMemorialDetails(0);
}

static void DrawMemorialTitle(void)
{
    u8 windowId;

    windowId = AddWindow(&sMemorialWindowTemplates[MEMORIAL_WIN_TITLE]);
    sMemorialMenu.windowIds[MEMORIAL_WIN_TITLE] = windowId;
    DrawStdWindowFrame(windowId, FALSE);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    AddTextPrinterParameterized(windowId, FONT_NORMAL, sTextMemorialTitle, 8, 1, 0, NULL);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void DrawMemorialDetails(s32 itemIndex)
{
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    u8 levelText[8];
    u8 windowId = sMemorialMenu.windowIds[MEMORIAL_WIN_DETAILS];
    const struct RetiredMonRecord *record;

    if (itemIndex < 0 || itemIndex >= sMemorialMenu.count)
        return;

    record = &sMemorialMenu.records[itemIndex];

    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    CopyRetiredMonNickname(nickname, record);
    if (nickname[0] == EOS)
        StringCopy(nickname, gSpeciesNames[record->species]);

    AddTextPrinterParameterized(windowId, FONT_NORMAL, nickname, 8, 8, 0, NULL);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gSpeciesNames[record->species], 8, 24, 0, NULL);
    StringCopy(levelText, sTextMemorialLv);
    ConvertIntToDecimalStringN(levelText + 2, record->level, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, levelText, 8, 40, 0, NULL);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, sTextMemorialStatus, 8, 64, 0, NULL);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, sTextMemorialHint, 8, 88, 0, NULL);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void MemorialMenuMoveCursor(s32 itemIndex, bool8 onInit, struct ListMenu *list)
{
    if (itemIndex >= 0 && itemIndex < sMemorialMenu.count)
    {
        DrawMemorialDetails(itemIndex);
        if (!onInit)
            PlaySE(SE_SELECT);
    }
}

static bool8 ShouldSkipPermadeathBattle(void)
{
    if (!IsPermadeathEnabled())
        return TRUE;

    if (gBattleTypeFlags & (BATTLE_TYPE_LINK
                         | BATTLE_TYPE_SAFARI
                         | BATTLE_TYPE_WALLY_TUTORIAL
                         | BATTLE_TYPE_RECORDED
                         | BATTLE_TYPE_RECORDED_LINK))
        return TRUE;

    return FALSE;
}

static bool8 IsMonEligibleForRetirement(struct Pokemon *mon)
{
    if (GetMonData(mon, MON_DATA_SPECIES, NULL) == SPECIES_NONE)
        return FALSE;

    if (GetMonData(mon, MON_DATA_IS_EGG, NULL))
        return FALSE;

    if (GetMonData(mon, MON_DATA_HP, NULL) != 0)
        return FALSE;

    return TRUE;
}

static bool8 IsMonAlreadyRetired(u32 personality)
{
    u16 i;
    struct RetiredMonRecord record;

    for (i = 0; i < GetRetiredMonCount(); i++)
    {
        if (GetRetiredMonRecord(i, &record) && record.personality == personality)
            return TRUE;
    }

    return FALSE;
}

static void BuildRetiredMonRecord(struct RetiredMonRecord *record, struct Pokemon *mon)
{
    u8 nickname[POKEMON_NAME_LENGTH + 1];

    CpuFill16(0, record, sizeof(*record));
    record->personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
    record->species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    record->level = GetMonData(mon, MON_DATA_LEVEL, NULL);
    GetMonData(mon, MON_DATA_NICKNAME, nickname);
    StringCopyN(record->nickname, nickname, POKEMON_NAME_LENGTH);
}

static void CopyRetiredMonNickname(u8 *dst, const struct RetiredMonRecord *record)
{
    StringCopyN(dst, record->nickname, POKEMON_NAME_LENGTH);
    dst[POKEMON_NAME_LENGTH] = EOS;
}
