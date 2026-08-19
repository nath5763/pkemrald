#ifndef GUARD_TIME_OF_DAY_H
#define GUARD_TIME_OF_DAY_H

enum TimeOfDay
{
    TIME_OF_DAY_DAWN,
    TIME_OF_DAY_DAY,
    TIME_OF_DAY_DUSK,
    TIME_OF_DAY_NIGHT,
};

enum TimeOfDay GetTimeOfDay(void);
bool8 IsTimeOfDayLightingEnabled(void);
void ApplyTimeOfDayPalette(u16 offset, u16 count);

#endif // GUARD_TIME_OF_DAY_H
