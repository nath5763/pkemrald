#ifndef GUARD_CHAMPIONS_CLUB_H
#define GUARD_CHAMPIONS_CLUB_H

bool8 IsChampionsClubTrainer(u16 trainerId);
bool8 HasChampionsClubTrainerBeenFought(u16 trainerId);
void SetChampionsClubTrainerFought(u16 trainerId);
void ClearChampionsClubTrainerFought(u16 trainerId);

void ChampionsClubFloor2_SetupDailyTrainers(void);
void ChampionsClubFloor2_GetTrainerForLastTalked(void);

#endif // GUARD_CHAMPIONS_CLUB_H
