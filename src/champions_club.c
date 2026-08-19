#include "global.h"
#include "champions_club.h"
#include "event_data.h"
#include "rtc.h"
#include "constants/event_objects.h"
#include "constants/flags.h"
#include "constants/opponents.h"
#include "constants/vars.h"

enum ChampionsClubRosterId
{
    CHAMPIONS_CLUB_ROSTER_ROXANNE,
    CHAMPIONS_CLUB_ROSTER_BRAWLY,
    CHAMPIONS_CLUB_ROSTER_WATTSON,
    CHAMPIONS_CLUB_ROSTER_FLANNERY,
    CHAMPIONS_CLUB_ROSTER_NORMAN,
    CHAMPIONS_CLUB_ROSTER_WINONA,
    CHAMPIONS_CLUB_ROSTER_TATE_AND_LIZA,
    CHAMPIONS_CLUB_ROSTER_JUAN,
    CHAMPIONS_CLUB_ROSTER_SIDNEY,
    CHAMPIONS_CLUB_ROSTER_PHOEBE,
    CHAMPIONS_CLUB_ROSTER_GLACIA,
    CHAMPIONS_CLUB_ROSTER_DRAKE,
    CHAMPIONS_CLUB_ROSTER_WALLACE,
    CHAMPIONS_CLUB_ROSTER_STEVEN,
    CHAMPIONS_CLUB_ROSTER_LEAF,
    CHAMPIONS_CLUB_ROSTER_COUNTERPART,
    CHAMPIONS_CLUB_ROSTER_COUNT
};

#define CHAMPIONS_CLUB_SLOT_COUNT       16
#define CHAMPIONS_CLUB_DAILY_COUNT       4
#define CHAMPIONS_CLUB_GROUP_COUNT       4

struct ChampionsClubRosterEntry
{
    u16 trainerId;
    u8 graphicsId;
};

static const struct ChampionsClubRosterEntry sChampionsClubRoster[CHAMPIONS_CLUB_ROSTER_COUNT] =
{
    [CHAMPIONS_CLUB_ROSTER_ROXANNE]       = {TRAINER_CHAMPIONS_CLUB_ROXANNE,       OBJ_EVENT_GFX_ROXANNE},
    [CHAMPIONS_CLUB_ROSTER_BRAWLY]        = {TRAINER_CHAMPIONS_CLUB_BRAWLY,        OBJ_EVENT_GFX_BRAWLY},
    [CHAMPIONS_CLUB_ROSTER_WATTSON]       = {TRAINER_CHAMPIONS_CLUB_WATTSON,       OBJ_EVENT_GFX_WATTSON},
    [CHAMPIONS_CLUB_ROSTER_FLANNERY]      = {TRAINER_CHAMPIONS_CLUB_FLANNERY,      OBJ_EVENT_GFX_FLANNERY},
    [CHAMPIONS_CLUB_ROSTER_NORMAN]        = {TRAINER_CHAMPIONS_CLUB_NORMAN,        OBJ_EVENT_GFX_NORMAN},
    [CHAMPIONS_CLUB_ROSTER_WINONA]        = {TRAINER_CHAMPIONS_CLUB_WINONA,        OBJ_EVENT_GFX_WINONA},
    [CHAMPIONS_CLUB_ROSTER_TATE_AND_LIZA] = {TRAINER_CHAMPIONS_CLUB_TATE_AND_LIZA, OBJ_EVENT_GFX_LIZA},
    [CHAMPIONS_CLUB_ROSTER_JUAN]          = {TRAINER_CHAMPIONS_CLUB_JUAN,          OBJ_EVENT_GFX_JUAN},
    [CHAMPIONS_CLUB_ROSTER_SIDNEY]        = {TRAINER_CHAMPIONS_CLUB_SIDNEY,        OBJ_EVENT_GFX_SIDNEY},
    [CHAMPIONS_CLUB_ROSTER_PHOEBE]        = {TRAINER_CHAMPIONS_CLUB_PHOEBE,        OBJ_EVENT_GFX_PHOEBE},
    [CHAMPIONS_CLUB_ROSTER_GLACIA]        = {TRAINER_CHAMPIONS_CLUB_GLACIA,        OBJ_EVENT_GFX_GLACIA},
    [CHAMPIONS_CLUB_ROSTER_DRAKE]         = {TRAINER_CHAMPIONS_CLUB_DRAKE,         OBJ_EVENT_GFX_DRAKE},
    [CHAMPIONS_CLUB_ROSTER_WALLACE]       = {TRAINER_CHAMPIONS_CLUB_WALLACE,       OBJ_EVENT_GFX_WALLACE},
    [CHAMPIONS_CLUB_ROSTER_STEVEN]        = {TRAINER_CHAMPIONS_CLUB_STEVEN,        OBJ_EVENT_GFX_STEVEN},
    [CHAMPIONS_CLUB_ROSTER_LEAF]          = {TRAINER_CHAMPIONS_CLUB_LEAF,          OBJ_EVENT_GFX_LEAF},
};

// Each group mixes leaders with later-game trainers and appears once per four
// accelerated days.
static const u8 sChampionsClubTrainerGroups[CHAMPIONS_CLUB_GROUP_COUNT][CHAMPIONS_CLUB_DAILY_COUNT] =
{
    {CHAMPIONS_CLUB_ROSTER_ROXANNE,  CHAMPIONS_CLUB_ROSTER_NORMAN,        CHAMPIONS_CLUB_ROSTER_SIDNEY, CHAMPIONS_CLUB_ROSTER_WALLACE},
    {CHAMPIONS_CLUB_ROSTER_BRAWLY,   CHAMPIONS_CLUB_ROSTER_WINONA,        CHAMPIONS_CLUB_ROSTER_PHOEBE, CHAMPIONS_CLUB_ROSTER_STEVEN},
    {CHAMPIONS_CLUB_ROSTER_WATTSON,  CHAMPIONS_CLUB_ROSTER_TATE_AND_LIZA, CHAMPIONS_CLUB_ROSTER_GLACIA, CHAMPIONS_CLUB_ROSTER_LEAF},
    {CHAMPIONS_CLUB_ROSTER_FLANNERY, CHAMPIONS_CLUB_ROSTER_JUAN,          CHAMPIONS_CLUB_ROSTER_DRAKE,  CHAMPIONS_CLUB_ROSTER_COUNTERPART},
};

// These quartets spread the active trainers around the room while ensuring
// every configured position is used over a four-day placement cycle.
static const u8 sChampionsClubSlotGroups[CHAMPIONS_CLUB_GROUP_COUNT][CHAMPIONS_CLUB_DAILY_COUNT] =
{
    {0, 5, 8, 15},
    {1, 4, 10, 13},
    {2, 7, 9, 14},
    {3, 6, 11, 12},
};

static s8 GetChampionsClubTrainerWinBit(u16 trainerId)
{
    if (trainerId >= TRAINER_CHAMPIONS_CLUB_ROXANNE && trainerId <= TRAINER_CHAMPIONS_CLUB_LEAF)
        return trainerId - TRAINER_CHAMPIONS_CLUB_ROXANNE;
    if (trainerId == TRAINER_CHAMPIONS_CLUB_BRENDAN || trainerId == TRAINER_CHAMPIONS_CLUB_MAY)
        return CHAMPIONS_CLUB_ROSTER_COUNTERPART;
    return -1;
}

static u16 GetTrainerIdForRosterEntry(u8 rosterId)
{
    if (rosterId == CHAMPIONS_CLUB_ROSTER_COUNTERPART)
    {
        if (gSaveBlock2Ptr->playerGender == MALE)
            return TRAINER_CHAMPIONS_CLUB_MAY;
        return TRAINER_CHAMPIONS_CLUB_BRENDAN;
    }
    return sChampionsClubRoster[rosterId].trainerId;
}

static u8 GetGraphicsIdForRosterEntry(u8 rosterId)
{
    if (rosterId == CHAMPIONS_CLUB_ROSTER_COUNTERPART)
    {
        if (gSaveBlock2Ptr->playerGender == MALE)
            return OBJ_EVENT_GFX_RIVAL_MAY_NORMAL;
        return OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL;
    }
    return sChampionsClubRoster[rosterId].graphicsId;
}

static bool8 GetDailyRosterEntryForSlot(u16 day, u8 slot, u8 *rosterId)
{
    u8 i;
    u8 trainerGroup = day % CHAMPIONS_CLUB_GROUP_COUNT;
    u8 cycle = day / CHAMPIONS_CLUB_GROUP_COUNT;
    u8 slotGroup = (day + cycle) % CHAMPIONS_CLUB_GROUP_COUNT;

    for (i = 0; i < CHAMPIONS_CLUB_DAILY_COUNT; i++)
    {
        if (sChampionsClubSlotGroups[slotGroup][i] == slot)
        {
            *rosterId = sChampionsClubTrainerGroups[trainerGroup][(i + cycle) % CHAMPIONS_CLUB_DAILY_COUNT];
            return TRUE;
        }
    }
    return FALSE;
}

bool8 IsChampionsClubTrainer(u16 trainerId)
{
    return GetChampionsClubTrainerWinBit(trainerId) >= 0;
}

bool8 HasChampionsClubTrainerBeenFought(u16 trainerId)
{
    s8 bit = GetChampionsClubTrainerWinBit(trainerId);

    if (bit < 0)
        return FALSE;
    return (VarGet(VAR_CHAMPIONS_CLUB_DAILY_WINS) & (1 << bit)) != 0;
}

void SetChampionsClubTrainerFought(u16 trainerId)
{
    s8 bit = GetChampionsClubTrainerWinBit(trainerId);

    if (bit >= 0)
        VarSet(VAR_CHAMPIONS_CLUB_DAILY_WINS, VarGet(VAR_CHAMPIONS_CLUB_DAILY_WINS) | (1 << bit));
}

void ClearChampionsClubTrainerFought(u16 trainerId)
{
    s8 bit = GetChampionsClubTrainerWinBit(trainerId);

    if (bit >= 0)
        VarSet(VAR_CHAMPIONS_CLUB_DAILY_WINS, VarGet(VAR_CHAMPIONS_CLUB_DAILY_WINS) & ~(1 << bit));
}

void ChampionsClubFloor2_SetupDailyTrainers(void)
{
    u8 i;
    u8 rosterId;
    u16 day = (u16)gLocalTime.days;

    if (VarGet(VAR_CHAMPIONS_CLUB_ROSTER_DAY) != day)
    {
        VarSet(VAR_CHAMPIONS_CLUB_ROSTER_DAY, day);
        VarSet(VAR_CHAMPIONS_CLUB_DAILY_WINS, 0);
    }

    for (i = 0; i < CHAMPIONS_CLUB_SLOT_COUNT; i++)
    {
        FlagSet(FLAG_TEMP_1 + i);
        VarSet(VAR_OBJ_GFX_ID_0 + i, OBJ_EVENT_GFX_BOY_1);
    }

    for (i = 0; i < CHAMPIONS_CLUB_SLOT_COUNT; i++)
    {
        if (GetDailyRosterEntryForSlot(day, i, &rosterId))
        {
            VarSet(VAR_OBJ_GFX_ID_0 + i, GetGraphicsIdForRosterEntry(rosterId));
            FlagClear(FLAG_TEMP_1 + i);
        }
    }
}

void ChampionsClubFloor2_GetTrainerForLastTalked(void)
{
    u8 rosterId;
    u8 slot;

    if (gSpecialVar_LastTalked == 0 || gSpecialVar_LastTalked > CHAMPIONS_CLUB_SLOT_COUNT)
    {
        gSpecialVar_Result = TRAINER_NONE;
        return;
    }

    slot = gSpecialVar_LastTalked - 1;
    if (GetDailyRosterEntryForSlot(VarGet(VAR_CHAMPIONS_CLUB_ROSTER_DAY), slot, &rosterId))
        gSpecialVar_Result = GetTrainerIdForRosterEntry(rosterId);
    else
        gSpecialVar_Result = TRAINER_NONE;
}
