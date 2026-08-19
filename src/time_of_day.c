#include "global.h"
#include "palette.h"
#include "rtc.h"
#include "time_of_day.h"
#include "constants/map_types.h"
#include "constants/rgb.h"

#define MINUTES_PER_HOUR 60

#define DAWN_START_HOUR  5
#define DAY_START_HOUR   7
#define DUSK_START_HOUR  18
#define NIGHT_START_HOUR 20

#define COLOR_MULTIPLIER_BASE 256

struct TimeOfDayColorProfile
{
    u16 red;
    u16 green;
    u16 blue;
};

static const struct TimeOfDayColorProfile sDayProfile =
{
    .red = 256,
    .green = 256,
    .blue = 256,
};

static const struct TimeOfDayColorProfile sDawnProfile =
{
    .red = 288,
    .green = 256,
    .blue = 208,
};

static const struct TimeOfDayColorProfile sDuskProfile =
{
    .red = 288,
    .green = 208,
    .blue = 144,
};

static const struct TimeOfDayColorProfile sNightProfile =
{
    .red = 128,
    .green = 144,
    .blue = 176,
};

bool8 IsTimeOfDayLightingEnabled(void)
{
    switch (gMapHeader.mapType)
    {
    case MAP_TYPE_TOWN:
    case MAP_TYPE_CITY:
    case MAP_TYPE_ROUTE:
    case MAP_TYPE_OCEAN_ROUTE:
        return TRUE;
    default:
        return FALSE;
    }
}

static u16 LerpMultiplier(u16 start, u16 end, u16 elapsedMinutes)
{
    return start + (((s32)end - start) * elapsedMinutes) / MINUTES_PER_HOUR;
}

static struct TimeOfDayColorProfile LerpProfile(const struct TimeOfDayColorProfile *start,
                                                const struct TimeOfDayColorProfile *end,
                                                u16 elapsedMinutes)
{
    struct TimeOfDayColorProfile profile;

    profile.red = LerpMultiplier(start->red, end->red, elapsedMinutes);
    profile.green = LerpMultiplier(start->green, end->green, elapsedMinutes);
    profile.blue = LerpMultiplier(start->blue, end->blue, elapsedMinutes);
    return profile;
}

static struct TimeOfDayColorProfile GetTimeOfDayColorProfile(void)
{
    u16 minutes = gLocalTime.minutes;

    if (gLocalTime.hours == DAWN_START_HOUR)
        return LerpProfile(&sNightProfile, &sDawnProfile, minutes);
    if (gLocalTime.hours == DAWN_START_HOUR + 1)
        return LerpProfile(&sDawnProfile, &sDayProfile, minutes);
    if (gLocalTime.hours == DUSK_START_HOUR)
        return LerpProfile(&sDayProfile, &sDuskProfile, minutes);
    if (gLocalTime.hours == DUSK_START_HOUR + 1)
        return LerpProfile(&sDuskProfile, &sNightProfile, minutes);
    if (gLocalTime.hours >= DAY_START_HOUR && gLocalTime.hours < DUSK_START_HOUR)
        return sDayProfile;
    return sNightProfile;
}

enum TimeOfDay GetTimeOfDay(void)
{
    if (gLocalTime.hours >= DAWN_START_HOUR && gLocalTime.hours < DAY_START_HOUR)
        return TIME_OF_DAY_DAWN;
    if (gLocalTime.hours >= DAY_START_HOUR && gLocalTime.hours < DUSK_START_HOUR)
        return TIME_OF_DAY_DAY;
    if (gLocalTime.hours >= DUSK_START_HOUR && gLocalTime.hours < NIGHT_START_HOUR)
        return TIME_OF_DAY_DUSK;
    return TIME_OF_DAY_NIGHT;
}

void ApplyTimeOfDayPalette(u16 offset, u16 count)
{
    u16 i;
    struct TimeOfDayColorProfile profile;

    if (!IsTimeOfDayLightingEnabled())
        return;

    profile = GetTimeOfDayColorProfile();
    if (profile.red == COLOR_MULTIPLIER_BASE
     && profile.green == COLOR_MULTIPLIER_BASE
     && profile.blue == COLOR_MULTIPLIER_BASE)
        return;

    for (i = offset; i < offset + count; i++)
    {
        u16 color = gPlttBufferFaded[i];
        u16 red = color & 0x1F;
        u16 green = (color >> 5) & 0x1F;
        u16 blue = (color >> 10) & 0x1F;

        red = (red * profile.red + (COLOR_MULTIPLIER_BASE / 2)) / COLOR_MULTIPLIER_BASE;
        green = (green * profile.green + (COLOR_MULTIPLIER_BASE / 2)) / COLOR_MULTIPLIER_BASE;
        blue = (blue * profile.blue + (COLOR_MULTIPLIER_BASE / 2)) / COLOR_MULTIPLIER_BASE;

        if (red > 31)
            red = 31;
        if (green > 31)
            green = 31;
        if (blue > 31)
            blue = 31;

        gPlttBufferFaded[i] = (color & 0x8000) | RGB2(red, green, blue);
    }
}
