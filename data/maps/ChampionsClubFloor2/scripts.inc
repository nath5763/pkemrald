ChampionsClubFloor2_MapScripts::
# 2 "data/maps/ChampionsClubFloor2/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ChampionsClubFloor2_OnTransition
	.byte 0


ChampionsClubFloor2_OnTransition::
# 6 "data/maps/ChampionsClubFloor2/scripts.pory"
	special ChampionsClubFloor2_SetupDailyTrainers
	end


ChampionsClubFloor2_EventScript_DailyTrainer::
# 11 "data/maps/ChampionsClubFloor2/scripts.pory"
	lockall
# 12 "data/maps/ChampionsClubFloor2/scripts.pory"
	faceplayer
# 13 "data/maps/ChampionsClubFloor2/scripts.pory"
	specialvar VAR_RESULT, ChampionsClubFloor2_GetTrainerForLastTalked
# 14 "data/maps/ChampionsClubFloor2/scripts.pory"
	compare VAR_RESULT, TRAINER_CHAMPIONS_CLUB_ROXANNE
	goto_if_eq ChampionsClubFloor2_EventScript_DailyTrainer_2
ChampionsClubFloor2_EventScript_DailyTrainer_1:
# 17 "data/maps/ChampionsClubFloor2/scripts.pory"
	compare VAR_RESULT, TRAINER_CHAMPIONS_CLUB_BRAWLY
	goto_if_eq ChampionsClubFloor2_EventScript_DailyTrainer_5
ChampionsClubFloor2_EventScript_DailyTrainer_4:
# 20 "data/maps/ChampionsClubFloor2/scripts.pory"
	compare VAR_RESULT, TRAINER_CHAMPIONS_CLUB_WATTSON
	goto_if_eq ChampionsClubFloor2_EventScript_DailyTrainer_8
ChampionsClubFloor2_EventScript_DailyTrainer_7:
# 23 "data/maps/ChampionsClubFloor2/scripts.pory"
	compare VAR_RESULT, TRAINER_CHAMPIONS_CLUB_FLANNERY
	goto_if_eq ChampionsClubFloor2_EventScript_DailyTrainer_11
ChampionsClubFloor2_EventScript_DailyTrainer_10:
# 26 "data/maps/ChampionsClubFloor2/scripts.pory"
	compare VAR_RESULT, TRAINER_CHAMPIONS_CLUB_NORMAN
	goto_if_eq ChampionsClubFloor2_EventScript_DailyTrainer_14
ChampionsClubFloor2_EventScript_DailyTrainer_13:
# 29 "data/maps/ChampionsClubFloor2/scripts.pory"
	compare VAR_RESULT, TRAINER_CHAMPIONS_CLUB_WINONA
	goto_if_eq ChampionsClubFloor2_EventScript_DailyTrainer_17
ChampionsClubFloor2_EventScript_DailyTrainer_16:
# 32 "data/maps/ChampionsClubFloor2/scripts.pory"
	compare VAR_RESULT, TRAINER_CHAMPIONS_CLUB_TATE_AND_LIZA
	goto_if_eq ChampionsClubFloor2_EventScript_DailyTrainer_20
ChampionsClubFloor2_EventScript_DailyTrainer_19:
# 35 "data/maps/ChampionsClubFloor2/scripts.pory"
	compare VAR_RESULT, TRAINER_CHAMPIONS_CLUB_JUAN
	goto_if_eq ChampionsClubFloor2_EventScript_DailyTrainer_23
ChampionsClubFloor2_EventScript_DailyTrainer_22:
# 38 "data/maps/ChampionsClubFloor2/scripts.pory"
	compare VAR_RESULT, TRAINER_CHAMPIONS_CLUB_SIDNEY
	goto_if_eq ChampionsClubFloor2_EventScript_DailyTrainer_26
ChampionsClubFloor2_EventScript_DailyTrainer_25:
# 41 "data/maps/ChampionsClubFloor2/scripts.pory"
	compare VAR_RESULT, TRAINER_CHAMPIONS_CLUB_PHOEBE
	goto_if_eq ChampionsClubFloor2_EventScript_DailyTrainer_29
ChampionsClubFloor2_EventScript_DailyTrainer_28:
# 44 "data/maps/ChampionsClubFloor2/scripts.pory"
	compare VAR_RESULT, TRAINER_CHAMPIONS_CLUB_GLACIA
	goto_if_eq ChampionsClubFloor2_EventScript_DailyTrainer_32
ChampionsClubFloor2_EventScript_DailyTrainer_31:
# 47 "data/maps/ChampionsClubFloor2/scripts.pory"
	compare VAR_RESULT, TRAINER_CHAMPIONS_CLUB_DRAKE
	goto_if_eq ChampionsClubFloor2_EventScript_DailyTrainer_35
ChampionsClubFloor2_EventScript_DailyTrainer_34:
# 50 "data/maps/ChampionsClubFloor2/scripts.pory"
	compare VAR_RESULT, TRAINER_CHAMPIONS_CLUB_WALLACE
	goto_if_eq ChampionsClubFloor2_EventScript_DailyTrainer_38
ChampionsClubFloor2_EventScript_DailyTrainer_37:
# 53 "data/maps/ChampionsClubFloor2/scripts.pory"
	compare VAR_RESULT, TRAINER_CHAMPIONS_CLUB_STEVEN
	goto_if_eq ChampionsClubFloor2_EventScript_DailyTrainer_41
ChampionsClubFloor2_EventScript_DailyTrainer_40:
# 56 "data/maps/ChampionsClubFloor2/scripts.pory"
	compare VAR_RESULT, TRAINER_CHAMPIONS_CLUB_LEAF
	goto_if_eq ChampionsClubFloor2_EventScript_DailyTrainer_44
ChampionsClubFloor2_EventScript_DailyTrainer_43:
# 59 "data/maps/ChampionsClubFloor2/scripts.pory"
	compare VAR_RESULT, TRAINER_CHAMPIONS_CLUB_BRENDAN
	goto_if_eq ChampionsClubFloor2_EventScript_DailyTrainer_47
ChampionsClubFloor2_EventScript_DailyTrainer_46:
# 62 "data/maps/ChampionsClubFloor2/scripts.pory"
	compare VAR_RESULT, TRAINER_CHAMPIONS_CLUB_MAY
	goto_if_eq ChampionsClubFloor2_EventScript_DailyTrainer_50
ChampionsClubFloor2_EventScript_DailyTrainer_49:
# 65 "data/maps/ChampionsClubFloor2/scripts.pory"
	releaseall
	end

ChampionsClubFloor2_EventScript_DailyTrainer_2:
# 15 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto ChampionsClubFloor2_EventScript_BattleRoxanne
	goto ChampionsClubFloor2_EventScript_DailyTrainer_1

ChampionsClubFloor2_EventScript_DailyTrainer_5:
# 18 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto ChampionsClubFloor2_EventScript_BattleBrawly
	goto ChampionsClubFloor2_EventScript_DailyTrainer_4

ChampionsClubFloor2_EventScript_DailyTrainer_8:
# 21 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto ChampionsClubFloor2_EventScript_BattleWattson
	goto ChampionsClubFloor2_EventScript_DailyTrainer_7

ChampionsClubFloor2_EventScript_DailyTrainer_11:
# 24 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto ChampionsClubFloor2_EventScript_BattleFlannery
	goto ChampionsClubFloor2_EventScript_DailyTrainer_10

ChampionsClubFloor2_EventScript_DailyTrainer_14:
# 27 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto ChampionsClubFloor2_EventScript_BattleNorman
	goto ChampionsClubFloor2_EventScript_DailyTrainer_13

ChampionsClubFloor2_EventScript_DailyTrainer_17:
# 30 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto ChampionsClubFloor2_EventScript_BattleWinona
	goto ChampionsClubFloor2_EventScript_DailyTrainer_16

ChampionsClubFloor2_EventScript_DailyTrainer_20:
# 33 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto ChampionsClubFloor2_EventScript_BattleTateAndLiza
	goto ChampionsClubFloor2_EventScript_DailyTrainer_19

ChampionsClubFloor2_EventScript_DailyTrainer_23:
# 36 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto ChampionsClubFloor2_EventScript_BattleJuan
	goto ChampionsClubFloor2_EventScript_DailyTrainer_22

ChampionsClubFloor2_EventScript_DailyTrainer_26:
# 39 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto ChampionsClubFloor2_EventScript_BattleSidney
	goto ChampionsClubFloor2_EventScript_DailyTrainer_25

ChampionsClubFloor2_EventScript_DailyTrainer_29:
# 42 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto ChampionsClubFloor2_EventScript_BattlePhoebe
	goto ChampionsClubFloor2_EventScript_DailyTrainer_28

ChampionsClubFloor2_EventScript_DailyTrainer_32:
# 45 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto ChampionsClubFloor2_EventScript_BattleGlacia
	goto ChampionsClubFloor2_EventScript_DailyTrainer_31

ChampionsClubFloor2_EventScript_DailyTrainer_35:
# 48 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto ChampionsClubFloor2_EventScript_BattleDrake
	goto ChampionsClubFloor2_EventScript_DailyTrainer_34

ChampionsClubFloor2_EventScript_DailyTrainer_38:
# 51 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto ChampionsClubFloor2_EventScript_BattleWallace
	goto ChampionsClubFloor2_EventScript_DailyTrainer_37

ChampionsClubFloor2_EventScript_DailyTrainer_41:
# 54 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto ChampionsClubFloor2_EventScript_BattleSteven
	goto ChampionsClubFloor2_EventScript_DailyTrainer_40

ChampionsClubFloor2_EventScript_DailyTrainer_44:
# 57 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto ChampionsClubFloor2_EventScript_BattleLeaf
	goto ChampionsClubFloor2_EventScript_DailyTrainer_43

ChampionsClubFloor2_EventScript_DailyTrainer_47:
# 60 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto ChampionsClubFloor2_EventScript_BattleBrendan
	goto ChampionsClubFloor2_EventScript_DailyTrainer_46

ChampionsClubFloor2_EventScript_DailyTrainer_50:
# 63 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto ChampionsClubFloor2_EventScript_BattleMay
	goto ChampionsClubFloor2_EventScript_DailyTrainer_49


ChampionsClubFloor2_EventScript_BattleRoxanne::
# 70 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto_if_defeated TRAINER_CHAMPIONS_CLUB_ROXANNE, ChampionsClubFloor2_EventScript_AlreadyBattled
# 71 "data/maps/ChampionsClubFloor2/scripts.pory"
	trainerbattle_single TRAINER_CHAMPIONS_CLUB_ROXANNE, ChampionsClubFloor2_Text_BattleIntro, ChampionsClubFloor2_Text_BattleDefeat
# 72 "data/maps/ChampionsClubFloor2/scripts.pory"
	releaseall
	end


ChampionsClubFloor2_EventScript_BattleBrawly::
# 77 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto_if_defeated TRAINER_CHAMPIONS_CLUB_BRAWLY, ChampionsClubFloor2_EventScript_AlreadyBattled
# 78 "data/maps/ChampionsClubFloor2/scripts.pory"
	trainerbattle_single TRAINER_CHAMPIONS_CLUB_BRAWLY, ChampionsClubFloor2_Text_BattleIntro, ChampionsClubFloor2_Text_BattleDefeat
# 79 "data/maps/ChampionsClubFloor2/scripts.pory"
	releaseall
	end


ChampionsClubFloor2_EventScript_BattleWattson::
# 84 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto_if_defeated TRAINER_CHAMPIONS_CLUB_WATTSON, ChampionsClubFloor2_EventScript_AlreadyBattled
# 85 "data/maps/ChampionsClubFloor2/scripts.pory"
	trainerbattle_single TRAINER_CHAMPIONS_CLUB_WATTSON, ChampionsClubFloor2_Text_BattleIntro, ChampionsClubFloor2_Text_BattleDefeat
# 86 "data/maps/ChampionsClubFloor2/scripts.pory"
	releaseall
	end


ChampionsClubFloor2_EventScript_BattleFlannery::
# 91 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto_if_defeated TRAINER_CHAMPIONS_CLUB_FLANNERY, ChampionsClubFloor2_EventScript_AlreadyBattled
# 92 "data/maps/ChampionsClubFloor2/scripts.pory"
	trainerbattle_single TRAINER_CHAMPIONS_CLUB_FLANNERY, ChampionsClubFloor2_Text_BattleIntro, ChampionsClubFloor2_Text_BattleDefeat
# 93 "data/maps/ChampionsClubFloor2/scripts.pory"
	releaseall
	end


ChampionsClubFloor2_EventScript_BattleNorman::
# 98 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto_if_defeated TRAINER_CHAMPIONS_CLUB_NORMAN, ChampionsClubFloor2_EventScript_AlreadyBattled
# 99 "data/maps/ChampionsClubFloor2/scripts.pory"
	trainerbattle_single TRAINER_CHAMPIONS_CLUB_NORMAN, ChampionsClubFloor2_Text_BattleIntro, ChampionsClubFloor2_Text_BattleDefeat
# 100 "data/maps/ChampionsClubFloor2/scripts.pory"
	releaseall
	end


ChampionsClubFloor2_EventScript_BattleWinona::
# 105 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto_if_defeated TRAINER_CHAMPIONS_CLUB_WINONA, ChampionsClubFloor2_EventScript_AlreadyBattled
# 106 "data/maps/ChampionsClubFloor2/scripts.pory"
	trainerbattle_single TRAINER_CHAMPIONS_CLUB_WINONA, ChampionsClubFloor2_Text_BattleIntro, ChampionsClubFloor2_Text_BattleDefeat
# 107 "data/maps/ChampionsClubFloor2/scripts.pory"
	releaseall
	end


ChampionsClubFloor2_EventScript_BattleTateAndLiza::
# 112 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto_if_defeated TRAINER_CHAMPIONS_CLUB_TATE_AND_LIZA, ChampionsClubFloor2_EventScript_AlreadyBattled
# 113 "data/maps/ChampionsClubFloor2/scripts.pory"
	trainerbattle_single TRAINER_CHAMPIONS_CLUB_TATE_AND_LIZA, ChampionsClubFloor2_Text_BattleIntro, ChampionsClubFloor2_Text_BattleDefeat
# 114 "data/maps/ChampionsClubFloor2/scripts.pory"
	releaseall
	end


ChampionsClubFloor2_EventScript_BattleJuan::
# 119 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto_if_defeated TRAINER_CHAMPIONS_CLUB_JUAN, ChampionsClubFloor2_EventScript_AlreadyBattled
# 120 "data/maps/ChampionsClubFloor2/scripts.pory"
	trainerbattle_single TRAINER_CHAMPIONS_CLUB_JUAN, ChampionsClubFloor2_Text_BattleIntro, ChampionsClubFloor2_Text_BattleDefeat
# 121 "data/maps/ChampionsClubFloor2/scripts.pory"
	releaseall
	end


ChampionsClubFloor2_EventScript_BattleSidney::
# 126 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto_if_defeated TRAINER_CHAMPIONS_CLUB_SIDNEY, ChampionsClubFloor2_EventScript_AlreadyBattled
# 127 "data/maps/ChampionsClubFloor2/scripts.pory"
	trainerbattle_single TRAINER_CHAMPIONS_CLUB_SIDNEY, ChampionsClubFloor2_Text_BattleIntro, ChampionsClubFloor2_Text_BattleDefeat
# 128 "data/maps/ChampionsClubFloor2/scripts.pory"
	releaseall
	end


ChampionsClubFloor2_EventScript_BattlePhoebe::
# 133 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto_if_defeated TRAINER_CHAMPIONS_CLUB_PHOEBE, ChampionsClubFloor2_EventScript_AlreadyBattled
# 134 "data/maps/ChampionsClubFloor2/scripts.pory"
	trainerbattle_single TRAINER_CHAMPIONS_CLUB_PHOEBE, ChampionsClubFloor2_Text_BattleIntro, ChampionsClubFloor2_Text_BattleDefeat
# 135 "data/maps/ChampionsClubFloor2/scripts.pory"
	releaseall
	end


ChampionsClubFloor2_EventScript_BattleGlacia::
# 140 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto_if_defeated TRAINER_CHAMPIONS_CLUB_GLACIA, ChampionsClubFloor2_EventScript_AlreadyBattled
# 141 "data/maps/ChampionsClubFloor2/scripts.pory"
	trainerbattle_single TRAINER_CHAMPIONS_CLUB_GLACIA, ChampionsClubFloor2_Text_BattleIntro, ChampionsClubFloor2_Text_BattleDefeat
# 142 "data/maps/ChampionsClubFloor2/scripts.pory"
	releaseall
	end


ChampionsClubFloor2_EventScript_BattleDrake::
# 147 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto_if_defeated TRAINER_CHAMPIONS_CLUB_DRAKE, ChampionsClubFloor2_EventScript_AlreadyBattled
# 148 "data/maps/ChampionsClubFloor2/scripts.pory"
	trainerbattle_single TRAINER_CHAMPIONS_CLUB_DRAKE, ChampionsClubFloor2_Text_BattleIntro, ChampionsClubFloor2_Text_BattleDefeat
# 149 "data/maps/ChampionsClubFloor2/scripts.pory"
	releaseall
	end


ChampionsClubFloor2_EventScript_BattleWallace::
# 154 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto_if_defeated TRAINER_CHAMPIONS_CLUB_WALLACE, ChampionsClubFloor2_EventScript_AlreadyBattled
# 155 "data/maps/ChampionsClubFloor2/scripts.pory"
	trainerbattle_single TRAINER_CHAMPIONS_CLUB_WALLACE, ChampionsClubFloor2_Text_BattleIntro, ChampionsClubFloor2_Text_BattleDefeat
# 156 "data/maps/ChampionsClubFloor2/scripts.pory"
	releaseall
	end


ChampionsClubFloor2_EventScript_BattleSteven::
# 161 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto_if_defeated TRAINER_CHAMPIONS_CLUB_STEVEN, ChampionsClubFloor2_EventScript_AlreadyBattled
# 162 "data/maps/ChampionsClubFloor2/scripts.pory"
	trainerbattle_single TRAINER_CHAMPIONS_CLUB_STEVEN, ChampionsClubFloor2_Text_BattleIntro, ChampionsClubFloor2_Text_BattleDefeat
# 163 "data/maps/ChampionsClubFloor2/scripts.pory"
	releaseall
	end


ChampionsClubFloor2_EventScript_BattleLeaf::
# 168 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto_if_defeated TRAINER_CHAMPIONS_CLUB_LEAF, ChampionsClubFloor2_EventScript_AlreadyBattled
# 169 "data/maps/ChampionsClubFloor2/scripts.pory"
	trainerbattle_single TRAINER_CHAMPIONS_CLUB_LEAF, ChampionsClubFloor2_Text_BattleIntro, ChampionsClubFloor2_Text_BattleDefeat
# 170 "data/maps/ChampionsClubFloor2/scripts.pory"
	releaseall
	end


ChampionsClubFloor2_EventScript_BattleBrendan::
# 175 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto_if_defeated TRAINER_CHAMPIONS_CLUB_BRENDAN, ChampionsClubFloor2_EventScript_AlreadyBattled
# 176 "data/maps/ChampionsClubFloor2/scripts.pory"
	trainerbattle_single TRAINER_CHAMPIONS_CLUB_BRENDAN, ChampionsClubFloor2_Text_BattleIntro, ChampionsClubFloor2_Text_BattleDefeat
# 177 "data/maps/ChampionsClubFloor2/scripts.pory"
	releaseall
	end


ChampionsClubFloor2_EventScript_BattleMay::
# 182 "data/maps/ChampionsClubFloor2/scripts.pory"
	goto_if_defeated TRAINER_CHAMPIONS_CLUB_MAY, ChampionsClubFloor2_EventScript_AlreadyBattled
# 183 "data/maps/ChampionsClubFloor2/scripts.pory"
	trainerbattle_single TRAINER_CHAMPIONS_CLUB_MAY, ChampionsClubFloor2_Text_BattleIntro, ChampionsClubFloor2_Text_BattleDefeat
# 184 "data/maps/ChampionsClubFloor2/scripts.pory"
	releaseall
	end


ChampionsClubFloor2_EventScript_AlreadyBattled::
# 189 "data/maps/ChampionsClubFloor2/scripts.pory"
	msgbox ChampionsClubFloor2_Text_AlreadyBattled
# 190 "data/maps/ChampionsClubFloor2/scripts.pory"
	releaseall
	end


ChampionsClubFloor2_Text_BattleIntro::
# 194 "data/maps/ChampionsClubFloor2/scripts.pory"
	.string "Let's see what a fellow Champion\ncan do!$"

ChampionsClubFloor2_Text_BattleDefeat::
# 198 "data/maps/ChampionsClubFloor2/scripts.pory"
	.string "A worthy victory.$"

ChampionsClubFloor2_Text_AlreadyBattled::
# 202 "data/maps/ChampionsClubFloor2/scripts.pory"
	.string "We've already battled today.\nLet's meet again another day.$"
