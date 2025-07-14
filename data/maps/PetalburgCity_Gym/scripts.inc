# 1 "data/maps/PetalburgCity_Gym/scripts.pory"

# 2 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_MapScripts::
# 3 "data/maps/PetalburgCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, PetalburgCity_Gym_OnLoad
# 4 "data/maps/PetalburgCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_Gym_OnTransition
# 5 "data/maps/PetalburgCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_Gym_OnWarp
# 6 "data/maps/PetalburgCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_Gym_OnFrame
# 7 "data/maps/PetalburgCity_Gym/scripts.pory"
	.byte 0
# 8 "data/maps/PetalburgCity_Gym/scripts.pory"

# 9 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_OnLoad:
# 10 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_OpenUnlockedDoors
# 11 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_ge VAR_PETALBURG_GYM_STATE, 7, PetalburgCity_Gym_EventScript_UnlockAllDoors
# 12 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 13 "data/maps/PetalburgCity_Gym/scripts.pory"

# 14 "data/maps/PetalburgCity_Gym/scripts.pory"
@ NOTE: Strength and OHKO rooms are misleading. Both are more accurately Critical-Hit
# 15 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenUnlockedDoors::
# 16 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 1
# 17 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenGymEntranceDoors
# 18 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
# 19 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
# 20 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_PARKER, PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
# 21 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
# 22 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_GEORGE, PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
# 23 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_JODY, PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
# 24 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_BERKE, PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
# 25 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 26 "data/maps/PetalburgCity_Gym/scripts.pory"

# 27 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_UnlockAllDoors::
# 28 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 1
# 29 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenGymEntranceDoors
# 30 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
# 31 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
# 32 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
# 33 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
# 34 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
# 35 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
# 36 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
# 37 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 38 "data/maps/PetalburgCity_Gym/scripts.pory"

# 39 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_OnTransition:
# 40 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_MoveWallyToEntrance
# 41 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_lt VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_MoveNormanToEntrance
# 42 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, PetalburgCity_Gym_EventScript_CheckNormanForRematch
# 43 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 44 "data/maps/PetalburgCity_Gym/scripts.pory"

# 45 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_MoveWallyToEntrance::
# 46 "data/maps/PetalburgCity_Gym/scripts.pory"
	setobjectxyperm LOCALID_PETALBURG_GYM_WALLY, 5, 108
# 47 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 48 "data/maps/PetalburgCity_Gym/scripts.pory"

# 49 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_MoveNormanToEntrance::
# 50 "data/maps/PetalburgCity_Gym/scripts.pory"
	setobjectxyperm LOCALID_PETALBURG_GYM_NORMAN, 4, 107
# 51 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 52 "data/maps/PetalburgCity_Gym/scripts.pory"

# 53 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_CheckNormanForRematch::
# 54 "data/maps/PetalburgCity_Gym/scripts.pory"
	setorcopyvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_NORMAN_1
# 55 "data/maps/PetalburgCity_Gym/scripts.pory"
	specialvar VAR_RESULT, IsTrainerReadyForRematch
# 56 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_DontMoveNormanToFront
# 57 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_PETALBURG_GYM_STATE, 8, PetalburgCity_Gym_EventScript_DontMoveNormanToFront
# 58 "data/maps/PetalburgCity_Gym/scripts.pory"
	setobjectxyperm LOCALID_PETALBURG_GYM_NORMAN, 4, 107
# 59 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 60 "data/maps/PetalburgCity_Gym/scripts.pory"

# 61 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_DontMoveNormanToFront::
# 62 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 8
# 63 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 64 "data/maps/PetalburgCity_Gym/scripts.pory"

# 65 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_OnWarp:
# 66 "data/maps/PetalburgCity_Gym/scripts.pory"
	map_script_2 VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_TurnPlayerNorth
# 67 "data/maps/PetalburgCity_Gym/scripts.pory"
	.2byte 0
# 68 "data/maps/PetalburgCity_Gym/scripts.pory"

# 69 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_TurnPlayerNorth::
# 70 "data/maps/PetalburgCity_Gym/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 71 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 72 "data/maps/PetalburgCity_Gym/scripts.pory"

# 73 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_OnFrame:
# 74 "data/maps/PetalburgCity_Gym/scripts.pory"
	map_script_2 VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial
# 75 "data/maps/PetalburgCity_Gym/scripts.pory"
	.2byte 0
# 76 "data/maps/PetalburgCity_Gym/scripts.pory"

# 77 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial::
# 78 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 79 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadSoDidItWorkOut, MSGBOX_DEFAULT
# 80 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyThankYouBye, MSGBOX_DEFAULT
# 81 "data/maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 82 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 83 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitGym
# 84 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 85 "data/maps/PetalburgCity_Gym/scripts.pory"
	playse SE_EXIT
# 86 "data/maps/PetalburgCity_Gym/scripts.pory"
	removeobject LOCALID_PETALBURG_GYM_WALLY
# 87 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_CITY_WALLY
# 88 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay 30
# 89 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 90 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 91 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadGoCollectBadges, MSGBOX_DEFAULT
# 92 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 2
# 93 "data/maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 94 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 95 "data/maps/PetalburgCity_Gym/scripts.pory"

# 96 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyExitGym:
# 97 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 98 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 99 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 100 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 101 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 102 "data/maps/PetalburgCity_Gym/scripts.pory"

# 103 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Norman::
# 104 "data/maps/PetalburgCity_Gym/scripts.pory"
	lock
# 105 "data/maps/PetalburgCity_Gym/scripts.pory"
	faceplayer
# 106 "data/maps/PetalburgCity_Gym/scripts.pory"
	switch VAR_PETALBURG_GYM_STATE
# 107 "data/maps/PetalburgCity_Gym/scripts.pory"
	case 2, PetalburgCity_Gym_EventScript_NormanNoBadges
# 108 "data/maps/PetalburgCity_Gym/scripts.pory"
	case 3, PetalburgCity_Gym_EventScript_NormanOneBadge
# 109 "data/maps/PetalburgCity_Gym/scripts.pory"
	case 4, PetalburgCity_Gym_EventScript_NormanTwoBadges
# 110 "data/maps/PetalburgCity_Gym/scripts.pory"
	case 5, PetalburgCity_Gym_EventScript_NormanThreeBadges
# 111 "data/maps/PetalburgCity_Gym/scripts.pory"
	case 6, PetalburgCity_Gym_EventScript_NormanBattle
# 112 "data/maps/PetalburgCity_Gym/scripts.pory"
	case 7, PetalburgCity_Gym_EventScript_NormanPostBattle
# 113 "data/maps/PetalburgCity_Gym/scripts.pory"
	case 8, PetalburgCity_Gym_EventScript_NormanRematch
# 114 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadYoureHereWithYourPokemon, MSGBOX_DEFAULT
# 115 "data/maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 116 "data/maps/PetalburgCity_Gym/scripts.pory"
	switch VAR_FACING
# 117 "data/maps/PetalburgCity_Gym/scripts.pory"
	case DIR_SOUTH, PetalburgCity_Gym_EventScript_BeginWallyTutorialSouth
# 118 "data/maps/PetalburgCity_Gym/scripts.pory"
	case DIR_NORTH, PetalburgCity_Gym_EventScript_BeginWallyTutorialNorth
# 119 "data/maps/PetalburgCity_Gym/scripts.pory"
	case DIR_WEST, PetalburgCity_Gym_EventScript_BeginWallyTutorialWest
# 120 "data/maps/PetalburgCity_Gym/scripts.pory"
	case DIR_EAST, PetalburgCity_Gym_EventScript_BeginWallyTutorialEast
# 121 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 122 "data/maps/PetalburgCity_Gym/scripts.pory"

# 123 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorialSouth::
# 124 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 0
# 125 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
# 126 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 127 "data/maps/PetalburgCity_Gym/scripts.pory"

# 128 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorialNorth::
# 129 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 130 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
# 131 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 132 "data/maps/PetalburgCity_Gym/scripts.pory"

# 133 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorialWest::
# 134 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 2
# 135 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
# 136 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 137 "data/maps/PetalburgCity_Gym/scripts.pory"

# 138 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorialEast::
# 139 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 3
# 140 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
# 141 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 142 "data/maps/PetalburgCity_Gym/scripts.pory"

# 143 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorial::
# 144 "data/maps/PetalburgCity_Gym/scripts.pory"
	addobject LOCALID_PETALBURG_GYM_WALLY
# 145 "data/maps/PetalburgCity_Gym/scripts.pory"
	playse SE_DOOR
# 146 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_WallyArriveSouth
# 147 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallyArriveNorth
# 148 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallyArriveWestEast
# 149 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallyArriveWestEast
# 150 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyIdLikeAPokemon, MSGBOX_DEFAULT
# 151 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadOhYoureWallyRight, MSGBOX_DEFAULT
# 152 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyIveNeverCaughtAPokemon, MSGBOX_DEFAULT
# 153 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadHmISee, MSGBOX_DEFAULT
# 154 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth
# 155 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth
# 156 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_NormanAddressPlayerWest
# 157 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_NormanAddressPlayerEast
# 158 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadPlayerGoWithWally, MSGBOX_DEFAULT
# 159 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_NormanAddressWallySouth
# 160 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_NormanAddressWallyNorth
# 161 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_NormanAddressWallyWest
# 162 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_NormanAddressWallyEast
# 163 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_IllLoanYouMyZigzagoon, MSGBOX_DEFAULT
# 164 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyThankYouAndDadGivesPokeBall, MSGBOX_DEFAULT
# 165 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyOhWowThankYou, MSGBOX_DEFAULT
# 166 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_NormanFaceDoorSouth
# 167 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_NormanFaceDoorNorth
# 168 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_NormanFaceDoorWest
# 169 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_NormanFaceDoorEast
# 170 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_WallyFacePlayer
# 171 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallyFaceDown
# 172 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallyFacePlayer
# 173 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallyFacePlayer
# 174 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WouldYouReallyComeWithMe, MSGBOX_DEFAULT
# 175 "data/maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 176 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_DONT_TRANSITION_MUSIC
# 177 "data/maps/PetalburgCity_Gym/scripts.pory"
	playbgm MUS_FOLLOW_ME, FALSE
# 178 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_ExitGymWithWallySouth
# 179 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_ExitGymWithWallyNorth
# 180 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_ExitGymWithWallyWest
# 181 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_ExitGymWithWallyEast
# 182 "data/maps/PetalburgCity_Gym/scripts.pory"
	removeobject LOCALID_PETALBURG_GYM_WALLY
# 183 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_MOM
# 184 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 1
# 185 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_CITY_STATE, 2
# 186 "data/maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLY
# 187 "data/maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_PETALBURG_GYM_WALLY
# 188 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
# 189 "data/maps/PetalburgCity_Gym/scripts.pory"
	special InitBirchState
# 190 "data/maps/PetalburgCity_Gym/scripts.pory"
	warp MAP_PETALBURG_CITY, 15, 8
# 191 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitstate
# 192 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 193 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 194 "data/maps/PetalburgCity_Gym/scripts.pory"

# 195 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyArriveSouth::
# 196 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 197 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyArrive
# 198 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 199 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 200 "data/maps/PetalburgCity_Gym/scripts.pory"

# 201 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyArriveNorth::
# 202 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyArriveNorth
# 203 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 204 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterRight
# 205 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 206 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 207 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 208 "data/maps/PetalburgCity_Gym/scripts.pory"

# 209 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyArriveWestEast::
# 210 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 211 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 212 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyArrive
# 213 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 214 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 215 "data/maps/PetalburgCity_Gym/scripts.pory"

# 216 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallySouth::
# 217 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 218 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitSouthWest
# 219 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallySouth
# 220 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 221 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 222 "data/maps/PetalburgCity_Gym/scripts.pory"

# 223 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallyNorth::
# 224 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitNorth
# 225 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyNorth
# 226 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 227 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 228 "data/maps/PetalburgCity_Gym/scripts.pory"

# 229 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallyWest::
# 230 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitSouthWest
# 231 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyWest
# 232 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 233 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 234 "data/maps/PetalburgCity_Gym/scripts.pory"

# 235 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallyEast::
# 236 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitEast
# 237 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyEast
# 238 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 239 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 240 "data/maps/PetalburgCity_Gym/scripts.pory"

# 241 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth::
# 242 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterUp
# 243 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 244 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 245 "data/maps/PetalburgCity_Gym/scripts.pory"

# 246 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth::
# 247 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 248 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 249 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 250 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 251 "data/maps/PetalburgCity_Gym/scripts.pory"

# 252 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressPlayerWest::
# 253 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterRight
# 254 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 255 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 256 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 257 "data/maps/PetalburgCity_Gym/scripts.pory"

# 258 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressPlayerEast::
# 259 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterLeft
# 260 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 261 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 262 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 263 "data/maps/PetalburgCity_Gym/scripts.pory"

# 264 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressWallySouth::
# 265 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 266 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 267 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 268 "data/maps/PetalburgCity_Gym/scripts.pory"

# 269 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressWallyNorth::
# 270 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterRight
# 271 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 272 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 273 "data/maps/PetalburgCity_Gym/scripts.pory"

# 274 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressWallyWest::
# 275 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 276 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 277 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 278 "data/maps/PetalburgCity_Gym/scripts.pory"

# 279 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressWallyEast::
# 280 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 281 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 282 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 283 "data/maps/PetalburgCity_Gym/scripts.pory"

# 284 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyFacePlayer::
# 285 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, Common_Movement_FacePlayer
# 286 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 287 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 288 "data/maps/PetalburgCity_Gym/scripts.pory"

# 289 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyFaceDown::
# 290 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, Common_Movement_WalkInPlaceFasterDown
# 291 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 292 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 293 "data/maps/PetalburgCity_Gym/scripts.pory"

# 294 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanNoBadges::
# 295 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanGoToRustboro, MSGBOX_DEFAULT
# 296 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 297 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 298 "data/maps/PetalburgCity_Gym/scripts.pory"

# 299 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanOneBadge::
# 300 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanGoToDewford, MSGBOX_DEFAULT
# 301 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 302 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 303 "data/maps/PetalburgCity_Gym/scripts.pory"

# 304 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanTwoBadges::
# 305 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_YouHaveGottenStronger, MSGBOX_DEFAULT
# 306 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 307 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 308 "data/maps/PetalburgCity_Gym/scripts.pory"

# 309 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanThreeBadges::
# 310 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_YouHaveGottenStronger, MSGBOX_DEFAULT
# 311 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 312 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 313 "data/maps/PetalburgCity_Gym/scripts.pory"

# 314 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanFaceDoorSouth::
# 315 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 316 "data/maps/PetalburgCity_Gym/scripts.pory"

# 317 "data/maps/PetalburgCity_Gym/scripts.pory"
@ For all other NormanFaceDoorX, Norman is already facing the door from NormanAddressWallyX
# 318 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanFaceDoorNorth::
# 319 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 320 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 321 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 322 "data/maps/PetalburgCity_Gym/scripts.pory"

# 323 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanFaceDoorWest::
# 324 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 325 "data/maps/PetalburgCity_Gym/scripts.pory"

# 326 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanFaceDoorEast::
# 327 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 328 "data/maps/PetalburgCity_Gym/scripts.pory"

# 329 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanPostBattle::
# 330 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_ShouldGiveEnigmaBerry
# 331 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_GiveEnigmaBerry
# 332 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_FACADE, PetalburgCity_Gym_EventScript_GiveFacade2
# 333 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, PetalburgCity_Gym_EventScript_NoAmountOfTrainingIsEnough
# 334 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadGoingToKeepTraining, MSGBOX_DEFAULT
# 335 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 336 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 337 "data/maps/PetalburgCity_Gym/scripts.pory"

# 338 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GiveFacade2::
# 339 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_GiveFacade
# 340 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 341 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 342 "data/maps/PetalburgCity_Gym/scripts.pory"

# 343 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanRematch::
# 344 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_rematch_double TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanPreRematch, PetalburgCity_Gym_Text_NormanRematchDefeat, PetalburgCity_Gym_Text_NormanRematchNeedTwoMons
# 345 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanPostRematch, MSGBOX_AUTOCLOSE
# 346 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 347 "data/maps/PetalburgCity_Gym/scripts.pory"

# 348 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ShouldGiveEnigmaBerry::
# 349 "data/maps/PetalburgCity_Gym/scripts.pory"
	specialvar VAR_RESULT, IsEnigmaBerryValid
# 350 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
# 351 "data/maps/PetalburgCity_Gym/scripts.pory"
	checkitem ITEM_ENIGMA_BERRY
# 352 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
# 353 "data/maps/PetalburgCity_Gym/scripts.pory"
	checkpcitem ITEM_ENIGMA_BERRY
# 354 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
# 355 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_ENIGMA_BERRY_AVAILABLE, 0, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
# 356 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GiveEnigmaBerry, MSGBOX_DEFAULT
# 357 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_RESULT, TRUE
# 358 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 359 "data/maps/PetalburgCity_Gym/scripts.pory"

# 360 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry::
# 361 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_RESULT, FALSE
# 362 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 363 "data/maps/PetalburgCity_Gym/scripts.pory"

# 364 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GiveEnigmaBerry::
# 365 "data/maps/PetalburgCity_Gym/scripts.pory"
	giveitem ITEM_ENIGMA_BERRY
# 366 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 367 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_ENIGMA_BERRY_AVAILABLE, 0
# 368 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 369 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 370 "data/maps/PetalburgCity_Gym/scripts.pory"

# 371 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanBattle::
# 372 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanIntro, MSGBOX_DEFAULT
# 373 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanDefeat
# 374 "data/maps/PetalburgCity_Gym/scripts.pory"
	message PetalburgCity_Gym_Text_ReceivedBalanceBadge
# 375 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmessage
# 376 "data/maps/PetalburgCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 377 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis, MSGBOX_DEFAULT
# 378 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 379 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 7
# 380 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_BADGE05_GET
# 381 "data/maps/PetalburgCity_Gym/scripts.pory"
	special ResetHealLocationFromDewford
# 382 "data/maps/PetalburgCity_Gym/scripts.pory"
	call EventScript_HideMrBriney
# 383 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
# 384 "data/maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
# 385 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 5
# 386 "data/maps/PetalburgCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 387 "data/maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_DEWFORD_HALL_SLUDGE_BOMB_MAN
# 388 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_UnlockAllDoors
# 389 "data/maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 390 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_GiveFacade
# 391 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay 30
# 392 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadHappyAndSad, MSGBOX_DEFAULT
# 393 "data/maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 394 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay 40
# 395 "data/maps/PetalburgCity_Gym/scripts.pory"
	playse SE_DOOR
# 396 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay 10
# 397 "data/maps/PetalburgCity_Gym/scripts.pory"
	addobject LOCALID_PETALBURG_GYM_WALLYS_DAD
# 398 "data/maps/PetalburgCity_Gym/scripts.pory"
	switch VAR_FACING
# 399 "data/maps/PetalburgCity_Gym/scripts.pory"
	case DIR_NORTH, PetalburgCity_Gym_EventScript_WallysDadArrivesNorth
# 400 "data/maps/PetalburgCity_Gym/scripts.pory"
	case DIR_WEST, PetalburgCity_Gym_EventScript_WallysDadArrivesWest
# 401 "data/maps/PetalburgCity_Gym/scripts.pory"
	case DIR_EAST, PetalburgCity_Gym_EventScript_WallysDadArrivesEast
# 402 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 403 "data/maps/PetalburgCity_Gym/scripts.pory"

# 404 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GiveFacade::
# 405 "data/maps/PetalburgCity_Gym/scripts.pory"
	giveitem ITEM_TM_FACADE
# 406 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 407 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_FACADE
# 408 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_ExplainFacade, MSGBOX_DEFAULT
# 409 "data/maps/PetalburgCity_Gym/scripts.pory"
	giveitem ITEM_ULTRA_BALL, 20
# 410 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 411 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 412 "data/maps/PetalburgCity_Gym/scripts.pory"

# 413 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadArrivesNorth::
# 414 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 415 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_WallysDadArrives
# 416 "data/maps/PetalburgCity_Gym/scripts.pory"

# 417 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadArrivesEast::
# 418 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 2
# 419 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_WallysDadArrives
# 420 "data/maps/PetalburgCity_Gym/scripts.pory"

# 421 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadArrivesWest::
# 422 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 3
# 423 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_WallysDadArrives
# 424 "data/maps/PetalburgCity_Gym/scripts.pory"

# 425 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadArrives::
# 426 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadEnterGym
# 427 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 428 "data/maps/PetalburgCity_Gym/scripts.pory"
	playse SE_PIN
# 429 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_ExclamationMark
# 430 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 431 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_Delay48
# 432 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 433 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay 10
# 434 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallysDadApproachPlayerNorth
# 435 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallysDadApproachPlayerEast
# 436 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallysDadApproachPlayerWest
# 437 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_PleaseComeWithMe, MSGBOX_DEFAULT
# 438 "data/maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 439 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay 20
# 440 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallysDadFaceNormanNorth
# 441 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallysDadFaceNormanEast
# 442 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallysDadFaceNormanWest
# 443 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_LetMeBorrowPlayer, MSGBOX_DEFAULT
# 444 "data/maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 445 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_DONT_TRANSITION_MUSIC
# 446 "data/maps/PetalburgCity_Gym/scripts.pory"
	playbgm MUS_FOLLOW_ME, FALSE
# 447 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_ExitGymWithWallysDadNorth
# 448 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_ExitGymWithWallysDadEast
# 449 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_ExitGymWithWallysDadWest
# 450 "data/maps/PetalburgCity_Gym/scripts.pory"
	removeobject LOCALID_PETALBURG_GYM_WALLYS_DAD
# 451 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_CITY_STATE, 4
# 452 "data/maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLYS_DAD
# 453 "data/maps/PetalburgCity_Gym/scripts.pory"
	warp MAP_PETALBURG_CITY, 15, 8
# 454 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitstate
# 455 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 456 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 457 "data/maps/PetalburgCity_Gym/scripts.pory"

# 458 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadFaceNormanNorth::
# 459 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_WalkInPlaceFasterUp
# 460 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 461 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 462 "data/maps/PetalburgCity_Gym/scripts.pory"

# 463 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadFaceNormanEast::
# 464 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_WalkInPlaceFasterRight
# 465 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 466 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 467 "data/maps/PetalburgCity_Gym/scripts.pory"

# 468 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadFaceNormanWest::
# 469 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_WalkInPlaceFasterLeft
# 470 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 471 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 472 "data/maps/PetalburgCity_Gym/scripts.pory"

# 473 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadApproachPlayerNorth::
# 474 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerNorth
# 475 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 476 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 477 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterLeft
# 478 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 479 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 480 "data/maps/PetalburgCity_Gym/scripts.pory"

# 481 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadApproachPlayerEast::
# 482 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerEast
# 483 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 484 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 485 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 486 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 487 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 488 "data/maps/PetalburgCity_Gym/scripts.pory"

# 489 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadApproachPlayerWest::
# 490 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerWest
# 491 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 492 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 493 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 494 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 495 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 496 "data/maps/PetalburgCity_Gym/scripts.pory"

# 497 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallysDadNorth::
# 498 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitNorth
# 499 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 500 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadNorth
# 501 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 502 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 503 "data/maps/PetalburgCity_Gym/scripts.pory"

# 504 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallysDadEast::
# 505 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitEast
# 506 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadEast
# 507 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 508 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 509 "data/maps/PetalburgCity_Gym/scripts.pory"

# 510 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallysDadWest::
# 511 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitWest
# 512 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadWest
# 513 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 514 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 515 "data/maps/PetalburgCity_Gym/scripts.pory"

# 516 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadExitNorth:
# 517 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 518 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 519 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 520 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 521 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 522 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 523 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 524 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 525 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 526 "data/maps/PetalburgCity_Gym/scripts.pory"
	set_invisible
# 527 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 528 "data/maps/PetalburgCity_Gym/scripts.pory"

# 529 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadExitEast:
# 530 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 531 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 532 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 533 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 534 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 535 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 536 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 537 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 538 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 539 "data/maps/PetalburgCity_Gym/scripts.pory"
	set_invisible
# 540 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 541 "data/maps/PetalburgCity_Gym/scripts.pory"

# 542 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadExitWest:
# 543 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 544 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 545 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 546 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 547 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 548 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 549 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 550 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 551 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 552 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 553 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 554 "data/maps/PetalburgCity_Gym/scripts.pory"
	set_invisible
# 555 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 556 "data/maps/PetalburgCity_Gym/scripts.pory"

# 557 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallysDadNorth:
# 558 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 559 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 560 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 561 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 562 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 563 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 564 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 565 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 566 "data/maps/PetalburgCity_Gym/scripts.pory"

# 567 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallysDadEast:
# 568 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 569 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 570 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 571 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 572 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 573 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 574 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 575 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 576 "data/maps/PetalburgCity_Gym/scripts.pory"

# 577 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallysDadWest:
# 578 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 579 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 580 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 581 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 582 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 583 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 584 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 585 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 586 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 587 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 588 "data/maps/PetalburgCity_Gym/scripts.pory"

# 589 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadEnterGym:
# 590 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 591 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 592 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_right
# 593 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 594 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_left
# 595 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 596 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 597 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 598 "data/maps/PetalburgCity_Gym/scripts.pory"

# 599 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadApproachPlayerNorth:
# 600 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 601 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 602 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 603 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 604 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 605 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_right
# 606 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 607 "data/maps/PetalburgCity_Gym/scripts.pory"

# 608 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadApproachPlayerEast:
# 609 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 610 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 611 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 612 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 613 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 614 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 615 "data/maps/PetalburgCity_Gym/scripts.pory"

# 616 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadApproachPlayerWest:
# 617 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 618 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 619 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 620 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 621 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 622 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 623 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 624 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 625 "data/maps/PetalburgCity_Gym/scripts.pory"

# 626 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_Unused:
# 627 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 628 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 629 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 630 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 631 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 632 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 633 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 634 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_down
# 635 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 636 "data/maps/PetalburgCity_Gym/scripts.pory"

# 637 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyArriveNorth:
# 638 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 639 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 640 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 641 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 642 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 643 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 644 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 645 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 646 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_left
# 647 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 648 "data/maps/PetalburgCity_Gym/scripts.pory"

# 649 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyArrive:
# 650 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 651 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 652 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 653 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 654 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 655 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 656 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 657 "data/maps/PetalburgCity_Gym/scripts.pory"

# 658 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyExitNorth:
# 659 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 660 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 661 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 662 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 663 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 664 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 665 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 666 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 667 "data/maps/PetalburgCity_Gym/scripts.pory"

# 668 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyExitEast:
# 669 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 670 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 671 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 672 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 673 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 674 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 675 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 676 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 677 "data/maps/PetalburgCity_Gym/scripts.pory"

# 678 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyExitSouthWest:
# 679 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 680 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 681 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 682 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 683 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 684 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 685 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 686 "data/maps/PetalburgCity_Gym/scripts.pory"

# 687 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallyNorth:
# 688 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 689 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 690 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 691 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 692 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 693 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 694 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 695 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 696 "data/maps/PetalburgCity_Gym/scripts.pory"

# 697 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallySouth:
# 698 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 699 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 700 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 701 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 702 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 703 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 704 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 705 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 706 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 707 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 708 "data/maps/PetalburgCity_Gym/scripts.pory"

# 709 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallyWest:
# 710 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 711 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 712 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 713 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 714 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 715 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 716 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 717 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 718 "data/maps/PetalburgCity_Gym/scripts.pory"

# 719 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallyEast:
# 720 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_down
# 721 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 722 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 723 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 724 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 725 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 726 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 727 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 728 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 729 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 730 "data/maps/PetalburgCity_Gym/scripts.pory"

# 731 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NoAmountOfTrainingIsEnough::
# 732 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadNoAmountOfTrainingIsEnough, MSGBOX_DEFAULT
# 733 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 734 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 735 "data/maps/PetalburgCity_Gym/scripts.pory"

# 736 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SpeedRoomDoor::
# 737 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 738 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_lt VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_DoorLocked
# 739 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 740 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 85
# 741 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterSpeedRoom, MSGBOX_YESNO
# 742 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 743 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 744 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 745 "data/maps/PetalburgCity_Gym/scripts.pory"

# 746 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_EnterRoom::
# 747 "data/maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 748 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay 30
# 749 "data/maps/PetalburgCity_Gym/scripts.pory"
	warpdoor MAP_PETALBURG_CITY_GYM, VAR_0x8008, VAR_0x8009
# 750 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitstate
# 751 "data/maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 752 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 753 "data/maps/PetalburgCity_Gym/scripts.pory"

# 754 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_DontEnterRoom::
# 755 "data/maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 756 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 757 "data/maps/PetalburgCity_Gym/scripts.pory"

# 758 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_DoorLocked::
# 759 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DoorAppearsLocked, MSGBOX_DEFAULT
# 760 "data/maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 761 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 762 "data/maps/PetalburgCity_Gym/scripts.pory"

# 763 "data/maps/PetalburgCity_Gym/scripts.pory"
@ VAR_0x8008 and VAR_0x8009 below are the x and y coordinates of the warp
# 764 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_AccuracyRoomDoor::
# 765 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 766 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_lt VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_DoorLocked
# 767 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 768 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 98
# 769 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterAccuracyRoom, MSGBOX_YESNO
# 770 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 771 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 772 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 773 "data/maps/PetalburgCity_Gym/scripts.pory"

# 774 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ConfusionRoomDoor::
# 775 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 776 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_DoorLocked
# 777 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 778 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 46
# 779 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterConfusionRoom, MSGBOX_YESNO
# 780 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 781 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 782 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 783 "data/maps/PetalburgCity_Gym/scripts.pory"

# 784 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftDefenseRoomDoor::
# 785 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 786 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_DoorLocked
# 787 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 788 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 59
# 789 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterDefenseRoom, MSGBOX_YESNO
# 790 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 791 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 792 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 793 "data/maps/PetalburgCity_Gym/scripts.pory"

# 794 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightDefenseRoomDoor::
# 795 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 796 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_DoorLocked
# 797 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 798 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 59
# 799 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterDefenseRoom, MSGBOX_YESNO
# 800 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 801 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 802 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 803 "data/maps/PetalburgCity_Gym/scripts.pory"

# 804 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RecoveryRoomDoor::
# 805 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 806 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_DoorLocked
# 807 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 808 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 72
# 809 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterRecoveryRoom, MSGBOX_YESNO
# 810 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 811 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 812 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 813 "data/maps/PetalburgCity_Gym/scripts.pory"

# 814 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftStrengthRoomDoor::
# 815 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 816 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_PARKER, PetalburgCity_Gym_EventScript_DoorLocked
# 817 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 818 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 20
# 819 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterStrengthRoom, MSGBOX_YESNO
# 820 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 821 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 822 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 823 "data/maps/PetalburgCity_Gym/scripts.pory"

# 824 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightStrengthRoomDoor::
# 825 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 826 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_DoorLocked
# 827 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 828 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 20
# 829 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterStrengthRoom, MSGBOX_YESNO
# 830 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 831 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 832 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 833 "data/maps/PetalburgCity_Gym/scripts.pory"

# 834 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftOHKORoomDoor::
# 835 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 836 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_DoorLocked
# 837 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 838 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 33
# 839 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterOHKORoom, MSGBOX_YESNO
# 840 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 841 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 842 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 843 "data/maps/PetalburgCity_Gym/scripts.pory"

# 844 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightOHKORoomDoor::
# 845 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 846 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_GEORGE, PetalburgCity_Gym_EventScript_DoorLocked
# 847 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 848 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 33
# 849 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterOHKORoom, MSGBOX_YESNO
# 850 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 851 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 852 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 853 "data/maps/PetalburgCity_Gym/scripts.pory"

# 854 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftGymLeadersRoomDoor::
# 855 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 856 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_JODY, PetalburgCity_Gym_EventScript_DoorLocked
# 857 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 858 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 7
# 859 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterGymLeadersRoom, MSGBOX_YESNO
# 860 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 861 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 862 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 863 "data/maps/PetalburgCity_Gym/scripts.pory"

# 864 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightGymLeadersRoomDoor::
# 865 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 866 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_BERKE, PetalburgCity_Gym_EventScript_DoorLocked
# 867 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 868 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 7
# 869 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterGymLeadersRoom, MSGBOX_YESNO
# 870 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 871 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 872 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 873 "data/maps/PetalburgCity_Gym/scripts.pory"

# 874 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Randall::
# 875 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_RANDALL, PetalburgCity_Gym_Text_RandallIntro, PetalburgCity_Gym_Text_RandallDefeat, PetalburgCity_Gym_EventScript_SlideOpenSpeedRoomDoors
# 876 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_RandallPostBadge
# 877 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_RandallPostBattle, MSGBOX_AUTOCLOSE
# 878 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 879 "data/maps/PetalburgCity_Gym/scripts.pory"

# 880 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenSpeedRoomDoors::
# 881 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 882 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
# 883 "data/maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 884 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 885 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 886 "data/maps/PetalburgCity_Gym/scripts.pory"

# 887 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RandallPostBadge::
# 888 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_RandallPostBadge, MSGBOX_NPC
# 889 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 890 "data/maps/PetalburgCity_Gym/scripts.pory"

# 891 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Parker::
# 892 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_PARKER, PetalburgCity_Gym_Text_ParkerIntro, PetalburgCity_Gym_Text_ParkerDefeat, PetalburgCity_Gym_EventScript_SlideOpenConfusionRoomDoors
# 893 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_ParkerPostBadge
# 894 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_ParkerPostBattle, MSGBOX_AUTOCLOSE
# 895 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 896 "data/maps/PetalburgCity_Gym/scripts.pory"

# 897 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenConfusionRoomDoors::
# 898 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 899 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
# 900 "data/maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 901 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 902 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 903 "data/maps/PetalburgCity_Gym/scripts.pory"

# 904 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ParkerPostBadge::
# 905 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_ParkerPostBadge, MSGBOX_NPC
# 906 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 907 "data/maps/PetalburgCity_Gym/scripts.pory"

# 908 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_George::
# 909 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_GEORGE, PetalburgCity_Gym_Text_GeorgeIntro, PetalburgCity_Gym_Text_GeorgeDefeat, PetalburgCity_Gym_EventScript_SlideOpenRecoveryRoomDoors
# 910 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_GeorgePostBadge
# 911 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GeorgePostBattle, MSGBOX_AUTOCLOSE
# 912 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 913 "data/maps/PetalburgCity_Gym/scripts.pory"

# 914 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenRecoveryRoomDoors::
# 915 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 916 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
# 917 "data/maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 918 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 919 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 920 "data/maps/PetalburgCity_Gym/scripts.pory"

# 921 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GeorgePostBadge::
# 922 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GeorgePostBadge, MSGBOX_NPC
# 923 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 924 "data/maps/PetalburgCity_Gym/scripts.pory"

# 925 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Berke::
# 926 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_BERKE, PetalburgCity_Gym_Text_BerkeIntro, PetalburgCity_Gym_Text_BerkeDefeat, PetalburgCity_Gym_EventScript_SlideOpenOHKORoomDoors
# 927 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_BerkePostBadge
# 928 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_BerkePostBattle, MSGBOX_AUTOCLOSE
# 929 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 930 "data/maps/PetalburgCity_Gym/scripts.pory"

# 931 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenOHKORoomDoors::
# 932 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 933 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
# 934 "data/maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 935 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 936 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 937 "data/maps/PetalburgCity_Gym/scripts.pory"

# 938 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BerkePostBadge::
# 939 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_BerkePostBadge, MSGBOX_NPC
# 940 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 941 "data/maps/PetalburgCity_Gym/scripts.pory"

# 942 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Mary::
# 943 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_MARY, PetalburgCity_Gym_Text_MaryIntro, PetalburgCity_Gym_Text_MaryDefeat, PetalburgCity_Gym_EventScript_SlideOpenAccuracyRoomDoors
# 944 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_MaryPostBadge
# 945 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
# 946 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 947 "data/maps/PetalburgCity_Gym/scripts.pory"

# 948 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenAccuracyRoomDoors::
# 949 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 950 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
# 951 "data/maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 952 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 953 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 954 "data/maps/PetalburgCity_Gym/scripts.pory"

# 955 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_MaryPostBadge::
# 956 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_MaryPostBadge, MSGBOX_NPC
# 957 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 958 "data/maps/PetalburgCity_Gym/scripts.pory"

# 959 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Alexia::
# 960 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_ALEXIA, PetalburgCity_Gym_Text_AlexiaIntro, PetalburgCity_Gym_Text_AlexiaDefeat, PetalburgCity_Gym_EventScript_SlideOpenDefenseRoomDoors
# 961 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_AlexiaPostBadge
# 962 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_AlexiaPostBattle, MSGBOX_AUTOCLOSE
# 963 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 964 "data/maps/PetalburgCity_Gym/scripts.pory"

# 965 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenDefenseRoomDoors::
# 966 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 967 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
# 968 "data/maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 969 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 970 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 971 "data/maps/PetalburgCity_Gym/scripts.pory"

# 972 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_AlexiaPostBadge::
# 973 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_AlexiaPostBadge, MSGBOX_NPC
# 974 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 975 "data/maps/PetalburgCity_Gym/scripts.pory"

# 976 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Jody::
# 977 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_JODY, PetalburgCity_Gym_Text_JodyIntro, PetalburgCity_Gym_Text_JodyDefeat, PetalburgCity_Gym_EventScript_SlideOpenStrengthRoomDoors
# 978 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_JodyPostBadge
# 979 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_JodyPostBattle, MSGBOX_AUTOCLOSE
# 980 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 981 "data/maps/PetalburgCity_Gym/scripts.pory"

# 982 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenStrengthRoomDoors::
# 983 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 984 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
# 985 "data/maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 986 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 987 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 988 "data/maps/PetalburgCity_Gym/scripts.pory"

# 989 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_JodyPostBadge::
# 990 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_JodyPostBadge, MSGBOX_NPC
# 991 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 992 "data/maps/PetalburgCity_Gym/scripts.pory"

# 993 "data/maps/PetalburgCity_Gym/scripts.pory"
@ VAR_0x8004 below is the room number
# 994 "data/maps/PetalburgCity_Gym/scripts.pory"
@ VAR_0x8005 below is 0 when the door should be slid open and 1 when it should be unlocked immediately
# 995 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenGymEntranceDoors::
# 996 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 1
# 997 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 998 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 999 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetEntranceRoomDoorMetatiles
# 1000 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1001 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1002 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors::
# 1003 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 2
# 1004 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1005 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1006 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetSpeedRoomDoorMetatiles
# 1007 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1008 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1009 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors::
# 1010 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 3
# 1011 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1012 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1013 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetAccuracyRoomDoorMetatiles
# 1014 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1015 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1016 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors::
# 1017 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 4
# 1018 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1019 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1020 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetConfusionRoomDoorMetatiles
# 1021 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1022 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1023 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors::
# 1024 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 5
# 1025 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1026 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1027 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetDefenseRoomDoorMetatiles
# 1028 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1029 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1030 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors::
# 1031 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 6
# 1032 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1033 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1034 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetRecoveryRoomDoorMetatiles
# 1035 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1036 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1037 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors::
# 1038 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 7
# 1039 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1040 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1041 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetStrengthRoomDoorMetatiles
# 1042 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1043 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1044 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenOHKORoomDoors::
# 1045 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 8
# 1046 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1047 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1048 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetOHKORoomDoorMetatiles
# 1049 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1050 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1051 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetEntranceRoomDoorMetatiles::
# 1052 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 85, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1053 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 85, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1054 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 98, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1055 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 98, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1056 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1057 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1058 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetSpeedRoomDoorMetatiles::
# 1059 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 46, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1060 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 46, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1061 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 59, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1062 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 59, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1063 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1064 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1065 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetAccuracyRoomDoorMetatiles::
# 1066 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 59, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1067 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 59, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1068 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 72, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1069 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 72, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1070 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1071 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1072 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetConfusionRoomDoorMetatiles::
# 1073 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 20, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1074 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 20, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1075 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1076 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1077 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetDefenseRoomDoorMetatiles::
# 1078 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 20, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1079 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 20, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1080 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 33, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1081 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 33, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1082 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1083 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1084 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetRecoveryRoomDoorMetatiles::
# 1085 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 33, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1086 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 33, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1087 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1088 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1089 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetStrengthRoomDoorMetatiles::
# 1090 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 7, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1091 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 7, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1092 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1093 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1094 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetOHKORoomDoorMetatiles::
# 1095 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 7, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1096 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 7, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1097 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1098 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1099 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenRoomDoors::
# 1100 "data/maps/PetalburgCity_Gym/scripts.pory"
	special PetalburgGymSlideOpenRoomDoors
# 1101 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitstate
# 1102 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1103 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1104 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_UnlockRoomDoors::
# 1105 "data/maps/PetalburgCity_Gym/scripts.pory"
	special PetalburgGymUnlockRoomDoors
# 1106 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1107 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1108 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GymGuide::
# 1109 "data/maps/PetalburgCity_Gym/scripts.pory"
	lock
# 1110 "data/maps/PetalburgCity_Gym/scripts.pory"
	faceplayer
# 1111 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_GymGuidePostVictory
# 1112 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 1113 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 1114 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1115 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1116 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GymGuidePostVictory::
# 1117 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 1118 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 1119 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1120 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1121 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftGymStatue::
# 1122 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 1123 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_GymStatueCertified
# 1124 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_GymStatue
# 1125 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1126 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1127 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightGymStatue::
# 1128 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 1129 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_GymStatueCertified
# 1130 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_GymStatue
# 1131 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1132 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1133 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GymStatueCertified::
# 1134 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 1135 "data/maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 1136 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1137 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1138 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GymStatue::
# 1139 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 1140 "data/maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 1141 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1142 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1143 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadYoureHereWithYourPokemon:
# 1144 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm?\p"
# 1145 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Well, if it isn't {PLAYER}!\n"
# 1146 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "So you're all finished moving in?\p"
# 1147 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm surprised that you managed to\n"
# 1148 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "get here by yourself.\p"
# 1149 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Oh, I see.\n"
# 1150 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "You're with your POKéMON.\p"
# 1151 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Hm… Then I guess you're going to\n"
# 1152 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "become a TRAINER like me, {PLAYER}.\p"
# 1153 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "That's great news!\n"
# 1154 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'll be looking forward to it!$"
# 1155 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1156 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyIdLikeAPokemon:
# 1157 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Um… I…\n"
# 1158 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'd like to get a POKéMON, please…$"
# 1159 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1160 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadOhYoureWallyRight:
# 1161 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm? You're… Uh… Oh, right.\n"
# 1162 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "You're WALLY, right?$"
# 1163 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1164 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyIveNeverCaughtAPokemon:
# 1165 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY: I'm going to go stay with my\n"
# 1166 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "relatives in VERDANTURF TOWN.\p"
# 1167 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I thought I would be lonely by myself,\n"
# 1168 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "so I wanted to take a POKéMON along.\p"
# 1169 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "But I've never caught a POKéMON before.\n"
# 1170 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I don't know how…$"
# 1171 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1172 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadHmISee:
# 1173 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm. I see.$"
# 1174 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1175 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadPlayerGoWithWally:
# 1176 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}, you heard that,\n"
# 1177 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "right?\p"
# 1178 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Go with WALLY and make sure that he\n"
# 1179 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "safely catches a POKéMON.$"
# 1180 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1181 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_IllLoanYouMyZigzagoon:
# 1182 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY, here, I'll loan you my POKéMON.\p"
# 1183 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY received a ZIGZAGOON!$"
# 1184 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1185 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyThankYouAndDadGivesPokeBall:
# 1186 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY: Oh, wow!\n"
# 1187 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "A POKéMON!\p"
# 1188 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm. I'll give you a POKé BALL, too.\n"
# 1189 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Go for it!\p"
# 1190 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY received a POKé BALL!$"
# 1191 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1192 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyOhWowThankYou:
# 1193 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY: Oh, wow!\n"
# 1194 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Thank you!$"
# 1195 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1196 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WouldYouReallyComeWithMe:
# 1197 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}… Would you really come\n"
# 1198 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "with me?$"
# 1199 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1200 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadSoDidItWorkOut:
# 1201 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: So, did it work out?$"
# 1202 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1203 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyThankYouBye:
# 1204 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY: Thank you, yes, it did.\n"
# 1205 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Here's your POKéMON back.\p"
# 1206 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}, thank you for coming along\n"
# 1207 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "with me.\p"
# 1208 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "You two are why I was able to catch\n"
# 1209 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "my POKéMON.\p"
# 1210 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I promise I'll take really good\n"
# 1211 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "care of it.\p"
# 1212 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Oh! My mom's waiting for me,\n"
# 1213 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "so I have to go!\p"
# 1214 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Bye, {PLAYER}!$"
# 1215 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1216 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadGoCollectBadges:
# 1217 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Now…\p"
# 1218 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}, if you want to become a\n"
# 1219 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "strong TRAINER, here's my advice.\p"
# 1220 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Head for RUSTBORO CITY beyond this\n"
# 1221 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "town.\p"
# 1222 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "There, you should challenge\n"
# 1223 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the GYM LEADER, ROXANNE.\p"
# 1224 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "After her, go on to other POKéMON\n"
# 1225 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "GYMS and defeat their LEADERS.\p"
# 1226 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Collect BADGES from them,\n"
# 1227 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "understood?\p"
# 1228 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Of course, I'm a GYM LEADER, too.\n"
# 1229 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "We'll battle one day, {PLAYER}.\p"
# 1230 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "But that's only after you become\n"
# 1231 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "stronger.$"
# 1232 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1233 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanGoToRustboro:
# 1234 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm? Aren't you going to the\n"
# 1235 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "POKéMON GYM in RUSTBORO CITY?\p"
# 1236 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "There's no challenge for me to\n"
# 1237 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "battle a greenhorn TRAINER.\p"
# 1238 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}, I want you to challenge me\n"
# 1239 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "when you become a lot stronger.\p"
# 1240 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'll battle you, {PLAYER}, when you\n"
# 1241 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "can show me four GYM BADGES, okay?$"
# 1242 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1243 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanGoToDewford:
# 1244 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: I see… So, you've beaten\n"
# 1245 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the GYM LEADER in RUSTBORO CITY.\p"
# 1246 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "But there are many more TRAINERS\n"
# 1247 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "who are stronger than you, {PLAYER}.\p"
# 1248 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Across the sea in DEWFORD TOWN is a\n"
# 1249 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "GYM LEADER named BRAWLY.\p"
# 1250 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "You should go challenge him.$"
# 1251 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1252 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_YouHaveGottenStronger:
# 1253 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm… {PLAYER}, you have gotten\n"
# 1254 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "stronger.\p"
# 1255 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I can tell by the number of BADGES\n"
# 1256 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "that you've earned.$"
# 1257 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1258 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanIntro:
# 1259 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm…\n"
# 1260 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "So, you did get four GYM BADGES.\p"
# 1261 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Fine, as I promised, we will have\n"
# 1262 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "a POKéMON battle.\p"
# 1263 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}…\p"
# 1264 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm so happy that I can have\n"
# 1265 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "a real battle with my own child.\p"
# 1266 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "But, a battle is a battle!\p"
# 1267 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I will do everything in my power as\n"
# 1268 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "a GYM LEADER to win.\p"
# 1269 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}, you'd better give it your\n"
# 1270 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "best shot, too!$"
# 1271 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1272 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanDefeat:
# 1273 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "…\p"
# 1274 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I… I can't…\p"
# 1275 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I can't believe it. {PLAYER}…\p"
# 1276 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I lost to {PLAYER}?\p"
# 1277 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "But, rules are rules!\n"
# 1278 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Here, take this.$"
# 1279 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1280 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ReceivedBalanceBadge:
# 1281 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER} received the BALANCE BADGE\n"
# 1282 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "from DAD!$"
# 1283 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1284 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis:
# 1285 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: With that BADGE, the DEFENSE\n"
# 1286 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "of all your POKéMON will increase.\p"
# 1287 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "POKéMON that know the HM move SURF\n"
# 1288 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "will be able to travel over water.\p"
# 1289 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "This is my gift to you. {PLAYER}, I'm\n"
# 1290 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "sure you can use it correctly.$"
# 1291 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1292 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ExplainFacade:
# 1293 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: TM42 contains FACADE.\p"
# 1294 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "It doubles the power of moves if\n"
# 1295 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the POKéMON is poisoned, paralyzed,\l"
# 1296 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "or burned.\p"
# 1297 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "It might be able to turn a bad\n"
# 1298 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "situation into an advantage.$"
# 1299 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1300 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadHappyAndSad:
# 1301 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: As the GYM LEADER, I can't\n"
# 1302 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "express how upset I am…\p"
# 1303 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "But as a father, it makes me both\n"
# 1304 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "happy and a little sad. It's odd…$"
# 1305 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1306 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_PleaseComeWithMe:
# 1307 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Ah, there you are, {PLAYER}{KUN}!\p"
# 1308 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Please come with me.\n"
# 1309 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I have something I want you to have.$"
# 1310 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1311 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_LetMeBorrowPlayer:
# 1312 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "NORMAN, you don't mind, do you?\p"
# 1313 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Let me borrow your {PLAYER}{KUN} for\n"
# 1314 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "a minute or two.$"
# 1315 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1316 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadGoingToKeepTraining:
# 1317 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}, you should go visit\n"
# 1318 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "your mother every so often.\p"
# 1319 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm going to stay here and redouble\n"
# 1320 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "my training.\p"
# 1321 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "It would bother me as a TRAINER to\n"
# 1322 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "not avenge my loss to you, {PLAYER}!$"
# 1323 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1324 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadNoAmountOfTrainingIsEnough:
# 1325 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}, how are things going?\p"
# 1326 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The world of POKéMON is deep.\p"
# 1327 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I honestly think that no amount of\n"
# 1328 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "training would ever be enough.$"
# 1329 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1330 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GymGuideAdvice:
# 1331 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Hey, how's it going, CHAMPION-\n"
# 1332 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "bound {PLAYER}?\p"
# 1333 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The doors in this GYM open when you\n"
# 1334 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "beat the awaiting TRAINERS.\p"
# 1335 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Whoops! The doors in this room are\n"
# 1336 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "already open, so don't attack me!\p"
# 1337 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The TRAINERS of PETALBURG GYM\n"
# 1338 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "use all kinds of items.\p"
# 1339 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The door at the left leads to\n"
# 1340 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the SPEED ROOM.\p"
# 1341 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The door at the right leads to\n"
# 1342 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the ACCURACY ROOM.\p"
# 1343 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The room's name will be on\n"
# 1344 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the door, so choose carefully.\p"
# 1345 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Once you've chosen the door…\n"
# 1346 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Well, hey, go for it!$"
# 1347 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1348 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GymGuidePostVictory:
# 1349 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}! Whoa! You've overcome even\n"
# 1350 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "your own father!\p"
# 1351 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Like, whoa!\n"
# 1352 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "What a stunning turn of events!$"
# 1353 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1354 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_RandallIntro:
# 1355 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The ability to attack before the\n"
# 1356 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "opponent…\p"
# 1357 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Just that alone puts me at a great\n"
# 1358 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "advantage, don't you agree?$"
# 1359 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1360 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_RandallDefeat:
# 1361 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "That was a magnificent battle!$"
# 1362 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1363 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_RandallPostBattle:
# 1364 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Go on to the next room where a new\n"
# 1365 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "challenge awaits you.\p"
# 1366 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "At the left is the CONFUSION ROOM.\p"
# 1367 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The right door leads to the DEFENSE\n"
# 1368 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "ROOM.$"
# 1369 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1370 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_RandallPostBadge:
# 1371 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Whomever you beat, and whomever you\n"
# 1372 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "may lose to, you never shirk from\l"
# 1373 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "training yourself and your POKéMON.\p"
# 1374 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "That's what I think being a\n"
# 1375 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "GYM LEADER is all about.$"
# 1376 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1377 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ParkerIntro:
# 1378 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "This is the CONFUSION ROOM.\p"
# 1379 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Let me see how well bonded you are\n"
# 1380 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "with your POKéMON!$"
# 1381 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1382 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ParkerDefeat:
# 1383 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I couldn't confuse your team enough…\n"
# 1384 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "You share a strong bond together.$"
# 1385 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1386 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ParkerPostBattle:
# 1387 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The next room is the STRENGTH ROOM.\n"
# 1388 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Can you withstand brute force?$"
# 1389 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1390 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ParkerPostBadge:
# 1391 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "After you beat our LEADER, the\n"
# 1392 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "training has become a lot tougher.$"
# 1393 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1394 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GeorgeIntro:
# 1395 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Just when you think you're going to\n"
# 1396 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "win, your opponent restores HP…\p"
# 1397 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Can you just imagine how awful that\n"
# 1398 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "must feel?\p"
# 1399 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'll show you exactly how awful it\n"
# 1400 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "feels!$"
# 1401 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1402 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GeorgeDefeat:
# 1403 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I couldn't restore HP enough…\n"
# 1404 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "What ATTACK power…$"
# 1405 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1406 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GeorgePostBattle:
# 1407 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I should have expected no less from\n"
# 1408 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "our LEADER's kid.\p"
# 1409 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "No, wait! A TRAINER's abilities are\n"
# 1410 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "earned only through effort.\p"
# 1411 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I lost because my own efforts\n"
# 1412 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "weren't enough.\p"
# 1413 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Go on! The ONE-HIT KO ROOM is next.$"
# 1414 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1415 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GeorgePostBadge:
# 1416 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm going to keep training at GYMS.\n"
# 1417 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "One day, I'll become a LEADER.$"
# 1418 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1419 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_BerkeIntro:
# 1420 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm not going to take it easy just\n"
# 1421 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "because you're our LEADER's kid.\p"
# 1422 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'll show you how horrid it is for\n"
# 1423 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "a POKéMON to take a critical hit!$"
# 1424 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1425 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_BerkeDefeat:
# 1426 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Your power…\n"
# 1427 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "You're the real deal.$"
# 1428 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1429 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_BerkePostBattle:
# 1430 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Your father really is strong.\n"
# 1431 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "He's a TRAINER worth my respect.\p"
# 1432 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "And, I sense the same glow coming\n"
# 1433 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "from you as your father.\p"
# 1434 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I hope that you'll stage a terrific\n"
# 1435 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "battle with your father!$"
# 1436 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1437 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_BerkePostBadge:
# 1438 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Since your dad became the LEADER,\n"
# 1439 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the TRAINERS of PETALBURG CITY have\l"
# 1440 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "become a lot tougher.$"
# 1441 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1442 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_MaryIntro:
# 1443 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Giggle…\n"
# 1444 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "This is the ACCURACY ROOM.\p"
# 1445 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "It's pretty nasty when every attack\n"
# 1446 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "lands without fail.$"
# 1447 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1448 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_MaryDefeat:
# 1449 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "You were a cut above me…$"
# 1450 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1451 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_MaryPostBattle:
# 1452 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "There are some even stronger\n"
# 1453 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "TRAINERS waiting for you.\p"
# 1454 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The left is the DEFENSE ROOM, and\n"
# 1455 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the right is the RECOVERY ROOM.\p"
# 1456 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Your POKéMON's ATTACK power will be\n"
# 1457 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "on trial either way.$"
# 1458 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1459 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_MaryPostBadge:
# 1460 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you know what we're trying to\n"
# 1461 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "achieve as TRAINERS?\p"
# 1462 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "We're striving to become soul mates\n"
# 1463 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "with our POKéMON.$"
# 1464 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1465 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_AlexiaIntro:
# 1466 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The higher the DEFENSE, the more\n"
# 1467 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "reckless I can be in attack.$"
# 1468 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1469 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_AlexiaDefeat:
# 1470 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Our defenses weren't enough…$"
# 1471 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1472 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_AlexiaPostBattle:
# 1473 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I think you've taught me a valuable\n"
# 1474 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "lesson here.\p"
# 1475 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Now, go on! The left door goes to\n"
# 1476 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the STRENGTH ROOM.\p"
# 1477 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The right door opens to\n"
# 1478 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the ONE-HIT KO ROOM.\p"
# 1479 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Both of them have TRAINERS who are\n"
# 1480 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "skilled at offense.$"
# 1481 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1482 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_AlexiaPostBadge:
# 1483 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Hi! Have you tried using SURF?$"
# 1484 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1485 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_JodyIntro:
# 1486 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Our GYM LEADER told us to go all out\n"
# 1487 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "and beat you.\p"
# 1488 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Even if you happen to be the\n"
# 1489 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "LEADER's kid!$"
# 1490 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1491 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_JodyDefeat:
# 1492 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "But… I went all out!$"
# 1493 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1494 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_JodyPostBattle:
# 1495 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The way you use your POKéMON…\n"
# 1496 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "It's like your father's style.\p"
# 1497 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Go on through! The GYM LEADER, your\n"
# 1498 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "father, is waiting!$"
# 1499 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1500 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_JodyPostBadge:
# 1501 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Sure, it's fine to make your POKéMON\n"
# 1502 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "stronger.\p"
# 1503 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "But what decides the winner?\p"
# 1504 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Why, it's the feelings TRAINERS have\n"
# 1505 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "for their POKéMON.$"
# 1506 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1507 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DoorAppearsLocked:
# 1508 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "This door appears to be locked\n"
# 1509 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "right now…$"
# 1510 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1511 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterSpeedRoom:
# 1512 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "“SPEED ROOM,” the sign says.\p"
# 1513 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1514 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1515 "data/maps/PetalburgCity_Gym/scripts.pory"
@ Unused
# 1516 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DoorAppearsLocked2:
# 1517 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "This door appears to be locked\n"
# 1518 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "right now…$"
# 1519 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1520 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterAccuracyRoom:
# 1521 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "“ACCURACY ROOM,” the sign says.\p"
# 1522 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1523 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1524 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterConfusionRoom:
# 1525 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "“CONFUSION ROOM,” the sign says.\p"
# 1526 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1527 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1528 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterDefenseRoom:
# 1529 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "“DEFENSE ROOM,” the sign says.\p"
# 1530 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1531 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1532 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterRecoveryRoom:
# 1533 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "“RECOVERY ROOM,” the sign says.\p"
# 1534 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1535 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1536 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterStrengthRoom:
# 1537 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "“STRENGTH ROOM,” the sign says.\p"
# 1538 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1539 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1540 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterOHKORoom:
# 1541 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "“ONE-HIT KO ROOM,” the sign says.\p"
# 1542 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1543 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1544 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterGymLeadersRoom:
# 1545 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "“GYM LEADER'S ROOM\p"
# 1546 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "“See for yourself what POKéMON await\n"
# 1547 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "you!” the sign says.\p"
# 1548 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1549 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1550 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GymStatue:
# 1551 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "PETALBURG CITY POKéMON GYM$"
# 1552 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1553 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GymStatueCertified:
# 1554 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "PETALBURG CITY POKéMON GYM\p"
# 1555 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "NORMAN'S CERTIFIED TRAINERS:\n"
# 1556 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}$"
# 1557 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1558 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanPreRematch:
# 1559 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}…\n"
# 1560 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I had a feeling that you would come.\p"
# 1561 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I would never refuse to accept\n"
# 1562 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "a challenge from you.\p"
# 1563 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "You do understand, don't you?\p"
# 1564 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Inside a GYM, it doesn't matter that\n"
# 1565 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "we are a parent and child.\p"
# 1566 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "…No, because we are parent and child,\n"
# 1567 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "we owe it to each other to do the best\l"
# 1568 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "we can. Isn't that right, {PLAYER}?$"
# 1569 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1570 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanRematchDefeat:
# 1571 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Uh… Haha…\n"
# 1572 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Maybe that was going too hard…$"
# 1573 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1574 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanPostRematch:
# 1575 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}…\n"
# 1576 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "What is your dream?\p"
# 1577 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "My dream…\n"
# 1578 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Hahaha…\l"
# 1579 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "It has already come true, actually.$"
# 1580 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1581 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanRematchNeedTwoMons:
# 1582 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}…\n"
# 1583 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I had a feeling that you would come.\p"
# 1584 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I would never refuse to accept\n"
# 1585 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "a challenge from you.\p"
# 1586 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "You do understand, don't you?\p"
# 1587 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Inside a GYM, it doesn't matter that\n"
# 1588 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "we are a parent and child.\p"
# 1589 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Hm? Wait a second, {PLAYER}.\p"
# 1590 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you only have one POKéMON that is\n"
# 1591 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "capable of battle?\p"
# 1592 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Sorry, but you'll have to come back\n"
# 1593 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "with at least two POKéMON.$"
