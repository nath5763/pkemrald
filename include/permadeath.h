#ifndef GUARD_PERMADEATH_H
#define GUARD_PERMADEATH_H

#include "global.h"

#define FEATURE_FLAG_PERMADEATH 6

bool8 IsPermadeathEnabled(void);
void TryRetireFaintedPlayerPartyMons(void);
// Opens the read-only memorial PC viewer from the field PC script flow.
void AccessMemorialPC(void);

#endif // GUARD_PERMADEATH_H
