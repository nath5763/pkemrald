# 1 "data/maps/MauvilleCity/scripts.pory"

# 2 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_MapScripts::
# 3 "data/maps/MauvilleCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_OnTransition
# 4 "data/maps/MauvilleCity/scripts.pory"
	.byte 0
# 5 "data/maps/MauvilleCity/scripts.pory"

# 6 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_OnTransition:
# 7 "data/maps/MauvilleCity/scripts.pory"
	setflag FLAG_VISITED_MAUVILLE_CITY
# 8 "data/maps/MauvilleCity/scripts.pory"
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
# 9 "data/maps/MauvilleCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION
# 10 "data/maps/MauvilleCity/scripts.pory"
	setflag FLAG_SYS_TV_START
# 11 "data/maps/MauvilleCity/scripts.pory"
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
# 12 "data/maps/MauvilleCity/scripts.pory"
	setvar VAR_MAUVILLE_GYM_STATE, 0
# 13 "data/maps/MauvilleCity/scripts.pory"
	call_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_MoveWattsonBackToGym
# 14 "data/maps/MauvilleCity/scripts.pory"
	end
# 15 "data/maps/MauvilleCity/scripts.pory"

# 16 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_MoveWattsonBackToGym::
# 17 "data/maps/MauvilleCity/scripts.pory"
	clearflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
# 18 "data/maps/MauvilleCity/scripts.pory"
	setflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
# 19 "data/maps/MauvilleCity/scripts.pory"
	setflag FLAG_WATTSON_REMATCH_AVAILABLE
# 20 "data/maps/MauvilleCity/scripts.pory"
	return
# 21 "data/maps/MauvilleCity/scripts.pory"

# 22 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_Boy::
# 23 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_NurseHurtMonBackToHealth, MSGBOX_NPC
# 24 "data/maps/MauvilleCity/scripts.pory"
	end
# 25 "data/maps/MauvilleCity/scripts.pory"

# 26 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_Maniac::
# 27 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_AllSortsOfPeopleComeThrough, MSGBOX_NPC
# 28 "data/maps/MauvilleCity/scripts.pory"
	end
# 29 "data/maps/MauvilleCity/scripts.pory"

# 30 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_Woman::
# 31 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_RydelVeryGenerous, MSGBOX_NPC
# 32 "data/maps/MauvilleCity/scripts.pory"
	end
# 33 "data/maps/MauvilleCity/scripts.pory"

# 34 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_RichBoy::
# 35 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike, MSGBOX_NPC
# 36 "data/maps/MauvilleCity/scripts.pory"
	end
# 37 "data/maps/MauvilleCity/scripts.pory"

# 38 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_CitySign::
# 39 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_CitySign, MSGBOX_SIGN
# 40 "data/maps/MauvilleCity/scripts.pory"
	end
# 41 "data/maps/MauvilleCity/scripts.pory"

# 42 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_GymSign::
# 43 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_GymSign, MSGBOX_SIGN
# 44 "data/maps/MauvilleCity/scripts.pory"
	end
# 45 "data/maps/MauvilleCity/scripts.pory"

# 46 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_BikeShopSign::
# 47 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_BikeShopSign, MSGBOX_SIGN
# 48 "data/maps/MauvilleCity/scripts.pory"
	end
# 49 "data/maps/MauvilleCity/scripts.pory"

# 50 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_GameCornerSign::
# 51 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_GameCornerSign, MSGBOX_SIGN
# 52 "data/maps/MauvilleCity/scripts.pory"
	end
# 53 "data/maps/MauvilleCity/scripts.pory"

# 54 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_SchoolKidM::
# 55 "data/maps/MauvilleCity/scripts.pory"
	lock
# 56 "data/maps/MauvilleCity/scripts.pory"
	faceplayer
# 57 "data/maps/MauvilleCity/scripts.pory"
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_TVExplained
# 58 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_ExplainTV, MSGBOX_DEFAULT
# 59 "data/maps/MauvilleCity/scripts.pory"
	setflag FLAG_TV_EXPLAINED
# 60 "data/maps/MauvilleCity/scripts.pory"
	release
# 61 "data/maps/MauvilleCity/scripts.pory"
	end
# 62 "data/maps/MauvilleCity/scripts.pory"

# 63 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_TVExplained::
# 64 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_BeenCheckingOutTV, MSGBOX_DEFAULT
# 65 "data/maps/MauvilleCity/scripts.pory"
	release
# 66 "data/maps/MauvilleCity/scripts.pory"
	end
# 67 "data/maps/MauvilleCity/scripts.pory"

# 68 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_WallysUncle::
# 69 "data/maps/MauvilleCity/scripts.pory"
	lock
# 70 "data/maps/MauvilleCity/scripts.pory"
	faceplayer
# 71 "data/maps/MauvilleCity/scripts.pory"
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_UncleAskPlayerToBattleWally
# 72 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_UncleHesTooPeppy, MSGBOX_DEFAULT
# 73 "data/maps/MauvilleCity/scripts.pory"
	closemessage
# 74 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
# 75 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 76 "data/maps/MauvilleCity/scripts.pory"
	release
# 77 "data/maps/MauvilleCity/scripts.pory"
	end
# 78 "data/maps/MauvilleCity/scripts.pory"

# 79 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_UncleAskPlayerToBattleWally::
# 80 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_UncleCanYouBattleWally, MSGBOX_DEFAULT
# 81 "data/maps/MauvilleCity/scripts.pory"
	closemessage
# 82 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
# 83 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 84 "data/maps/MauvilleCity/scripts.pory"
	release
# 85 "data/maps/MauvilleCity/scripts.pory"
	end
# 86 "data/maps/MauvilleCity/scripts.pory"

# 87 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_Wally::
# 88 "data/maps/MauvilleCity/scripts.pory"
	lockall
# 89 "data/maps/MauvilleCity/scripts.pory"
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_WallyRequestBattleAgain
# 90 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
# 91 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 92 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_WallyWantToChallengeGym, MSGBOX_DEFAULT
# 93 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_UncleYourePushingIt, MSGBOX_DEFAULT
# 94 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_WallyWeCanBeatAnyone, MSGBOX_DEFAULT
# 95 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
# 96 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 97 "data/maps/MauvilleCity/scripts.pory"
	playse SE_PIN
# 98 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_ExclamationMark
# 99 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 100 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_Delay48
# 101 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 102 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_WallyWillYouBattleMe, MSGBOX_YESNO
# 103 "data/maps/MauvilleCity/scripts.pory"
	goto MauvilleCity_EventScript_BattleWallyPrompt
# 104 "data/maps/MauvilleCity/scripts.pory"
	end
# 105 "data/maps/MauvilleCity/scripts.pory"

# 106 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_BattleWallyPrompt::
# 107 "data/maps/MauvilleCity/scripts.pory"
	call_if_eq VAR_RESULT, YES, MauvilleCity_EventScript_BattleWally
# 108 "data/maps/MauvilleCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_DeclineWallyBattle
# 109 "data/maps/MauvilleCity/scripts.pory"
	closemessage
# 110 "data/maps/MauvilleCity/scripts.pory"
	switch VAR_FACING
# 111 "data/maps/MauvilleCity/scripts.pory"
	case DIR_NORTH, MauvilleCity_EventScript_WallyAndUncleExitNorth
# 112 "data/maps/MauvilleCity/scripts.pory"
	case DIR_EAST, MauvilleCity_EventScript_WallyAndUncleExitEast
# 113 "data/maps/MauvilleCity/scripts.pory"
	end
# 114 "data/maps/MauvilleCity/scripts.pory"

# 115 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_WallyAndUncleExitNorth::
# 116 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth1
# 117 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth1
# 118 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth1
# 119 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 120 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
# 121 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 122 "data/maps/MauvilleCity/scripts.pory"
	delay 30
# 123 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerFaceUncleNorth
# 124 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerNorth
# 125 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 126 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
# 127 "data/maps/MauvilleCity/scripts.pory"
	closemessage
# 128 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth2
# 129 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth2
# 130 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth2
# 131 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 132 "data/maps/MauvilleCity/scripts.pory"
	goto MauvilleCity_EventScript_DefeatedWally
# 133 "data/maps/MauvilleCity/scripts.pory"
	end
# 134 "data/maps/MauvilleCity/scripts.pory"

# 135 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_WallyAndUncleExitEast::
# 136 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast1
# 137 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast1
# 138 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast1
# 139 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 140 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
# 141 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 142 "data/maps/MauvilleCity/scripts.pory"
	delay 30
# 143 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerEast
# 144 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 145 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
# 146 "data/maps/MauvilleCity/scripts.pory"
	closemessage
# 147 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast2
# 148 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast2
# 149 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast2
# 150 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 151 "data/maps/MauvilleCity/scripts.pory"
	goto MauvilleCity_EventScript_DefeatedWally
# 152 "data/maps/MauvilleCity/scripts.pory"
	end
# 153 "data/maps/MauvilleCity/scripts.pory"

# 154 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_DefeatedWally::
# 155 "data/maps/MauvilleCity/scripts.pory"
	removeobject LOCALID_MAUVILLE_WALLY
# 156 "data/maps/MauvilleCity/scripts.pory"
	removeobject LOCALID_MAUVILLE_WALLYS_UNCLE
# 157 "data/maps/MauvilleCity/scripts.pory"
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
# 158 "data/maps/MauvilleCity/scripts.pory"
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
# 159 "data/maps/MauvilleCity/scripts.pory"
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
# 160 "data/maps/MauvilleCity/scripts.pory"
	setvar VAR_WALLY_CALL_STEP_COUNTER, 0
# 161 "data/maps/MauvilleCity/scripts.pory"
	setflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
# 162 "data/maps/MauvilleCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottApproachPlayerNorth
# 163 "data/maps/MauvilleCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottApproachPlayerEast
# 164 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 165 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 166 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
# 167 "data/maps/MauvilleCity/scripts.pory"
	closemessage
# 168 "data/maps/MauvilleCity/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 169 "data/maps/MauvilleCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottExitNorth
# 170 "data/maps/MauvilleCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottExitEast
# 171 "data/maps/MauvilleCity/scripts.pory"
	removeobject LOCALID_MAUVILLE_SCOTT
# 172 "data/maps/MauvilleCity/scripts.pory"
	releaseall
# 173 "data/maps/MauvilleCity/scripts.pory"
	end
# 174 "data/maps/MauvilleCity/scripts.pory"

# 175 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_ScottApproachPlayerNorth::
# 176 "data/maps/MauvilleCity/scripts.pory"
	addobject LOCALID_MAUVILLE_SCOTT
# 177 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerNorth
# 178 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 179 "data/maps/MauvilleCity/scripts.pory"
	return
# 180 "data/maps/MauvilleCity/scripts.pory"

# 181 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_ScottApproachPlayerEast::
# 182 "data/maps/MauvilleCity/scripts.pory"
	setobjectxyperm LOCALID_MAUVILLE_SCOTT, 12, 13
# 183 "data/maps/MauvilleCity/scripts.pory"
	addobject LOCALID_MAUVILLE_SCOTT
# 184 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerEast
# 185 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 186 "data/maps/MauvilleCity/scripts.pory"
	return
# 187 "data/maps/MauvilleCity/scripts.pory"

# 188 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_ScottExitNorth::
# 189 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitNorth
# 190 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitNorth
# 191 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 192 "data/maps/MauvilleCity/scripts.pory"
	return
# 193 "data/maps/MauvilleCity/scripts.pory"

# 194 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_ScottExitEast::
# 195 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitEast
# 196 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitEast
# 197 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 198 "data/maps/MauvilleCity/scripts.pory"
	return
# 199 "data/maps/MauvilleCity/scripts.pory"

# 200 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_BattleWally::
# 201 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_WallyHereICome, MSGBOX_DEFAULT
# 202 "data/maps/MauvilleCity/scripts.pory"
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, MauvilleCity_Text_WallyDefeat
# 203 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
# 204 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 205 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_WallyIllGoBackToVerdanturf, MSGBOX_DEFAULT
# 206 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
# 207 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 208 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_ThankYouNotEnoughToBattle, MSGBOX_DEFAULT
# 209 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
# 210 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 211 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_UncleNoNeedToBeDown, MSGBOX_DEFAULT
# 212 "data/maps/MauvilleCity/scripts.pory"
	return
# 213 "data/maps/MauvilleCity/scripts.pory"

# 214 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_DeclineWallyBattle::
# 215 "data/maps/MauvilleCity/scripts.pory"
	setflag FLAG_DECLINED_WALLY_BATTLE_MAUVILLE
# 216 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_WallyMyUncleWontKnowImStrong, MSGBOX_DEFAULT
# 217 "data/maps/MauvilleCity/scripts.pory"
	release
# 218 "data/maps/MauvilleCity/scripts.pory"
	end
# 219 "data/maps/MauvilleCity/scripts.pory"

# 220 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_WallyRequestBattleAgain::
# 221 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
# 222 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 223 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_WallyPleaseBattleMe, MSGBOX_YESNO
# 224 "data/maps/MauvilleCity/scripts.pory"
	goto MauvilleCity_EventScript_BattleWallyPrompt
# 225 "data/maps/MauvilleCity/scripts.pory"
	end
# 226 "data/maps/MauvilleCity/scripts.pory"

# 227 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_WallyExitNorth1:
# 228 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 229 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 230 "data/maps/MauvilleCity/scripts.pory"
	walk_down
# 231 "data/maps/MauvilleCity/scripts.pory"
	walk_down
# 232 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 233 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 234 "data/maps/MauvilleCity/scripts.pory"

# 235 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_WallyExitEast1:
# 236 "data/maps/MauvilleCity/scripts.pory"
	walk_down
# 237 "data/maps/MauvilleCity/scripts.pory"
	walk_down
# 238 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 239 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 240 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 241 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 242 "data/maps/MauvilleCity/scripts.pory"

# 243 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_WallyExitNorth2:
# 244 "data/maps/MauvilleCity/scripts.pory"
	delay_16
# 245 "data/maps/MauvilleCity/scripts.pory"
	delay_16
# 246 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 247 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 248 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 249 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 250 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 251 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 252 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 253 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 254 "data/maps/MauvilleCity/scripts.pory"
	delay_8
# 255 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 256 "data/maps/MauvilleCity/scripts.pory"

# 257 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_WallyExitEast2:
# 258 "data/maps/MauvilleCity/scripts.pory"
	delay_16
# 259 "data/maps/MauvilleCity/scripts.pory"
	delay_16
# 260 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 261 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 262 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 263 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 264 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 265 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 266 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 267 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 268 "data/maps/MauvilleCity/scripts.pory"
	delay_8
# 269 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 270 "data/maps/MauvilleCity/scripts.pory"

# 271 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_PlayerWatchWallyExitNorth2:
# 272 "data/maps/MauvilleCity/scripts.pory"
	delay_16
# 273 "data/maps/MauvilleCity/scripts.pory"
	delay_8
# 274 "data/maps/MauvilleCity/scripts.pory"
	walk_in_place_faster_left
# 275 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 276 "data/maps/MauvilleCity/scripts.pory"

# 277 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_PlayerWatchWallyExitEast2:
# 278 "data/maps/MauvilleCity/scripts.pory"
	delay_16
# 279 "data/maps/MauvilleCity/scripts.pory"
	delay_16
# 280 "data/maps/MauvilleCity/scripts.pory"
	delay_16
# 281 "data/maps/MauvilleCity/scripts.pory"
	walk_in_place_faster_left
# 282 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 283 "data/maps/MauvilleCity/scripts.pory"

# 284 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_PlayerWatchScottExitNorth:
# 285 "data/maps/MauvilleCity/scripts.pory"
	delay_16
# 286 "data/maps/MauvilleCity/scripts.pory"
	walk_in_place_faster_left
# 287 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 288 "data/maps/MauvilleCity/scripts.pory"

# 289 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_PlayerWatchScottExitEast:
# 290 "data/maps/MauvilleCity/scripts.pory"
	delay_16
# 291 "data/maps/MauvilleCity/scripts.pory"
	delay_16
# 292 "data/maps/MauvilleCity/scripts.pory"
	walk_in_place_faster_left
# 293 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 294 "data/maps/MauvilleCity/scripts.pory"

# 295 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_PlayerWatchWallyExitEast1:
# 296 "data/maps/MauvilleCity/scripts.pory"
	delay_16
# 297 "data/maps/MauvilleCity/scripts.pory"
	walk_in_place_faster_down
# 298 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 299 "data/maps/MauvilleCity/scripts.pory"

# 300 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_PlayerWatchWallyExitNorth1:
# 301 "data/maps/MauvilleCity/scripts.pory"
	delay_16
# 302 "data/maps/MauvilleCity/scripts.pory"
	walk_in_place_faster_left
# 303 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 304 "data/maps/MauvilleCity/scripts.pory"

# 305 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_WallysUncleExitNorth1:
# 306 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 307 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 308 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 309 "data/maps/MauvilleCity/scripts.pory"
	walk_down
# 310 "data/maps/MauvilleCity/scripts.pory"
	walk_down
# 311 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 312 "data/maps/MauvilleCity/scripts.pory"

# 313 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_WallysUncleExitEast1:
# 314 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 315 "data/maps/MauvilleCity/scripts.pory"
	walk_down
# 316 "data/maps/MauvilleCity/scripts.pory"
	walk_down
# 317 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 318 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 319 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 320 "data/maps/MauvilleCity/scripts.pory"

# 321 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_PlayerFaceUncleNorth:
# 322 "data/maps/MauvilleCity/scripts.pory"
	delay_16
# 323 "data/maps/MauvilleCity/scripts.pory"
	delay_8
# 324 "data/maps/MauvilleCity/scripts.pory"
	delay_4
# 325 "data/maps/MauvilleCity/scripts.pory"
	walk_in_place_faster_down
# 326 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 327 "data/maps/MauvilleCity/scripts.pory"

# 328 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_WallysUncleApproachPlayerNorth:
# 329 "data/maps/MauvilleCity/scripts.pory"
	walk_right
# 330 "data/maps/MauvilleCity/scripts.pory"
	walk_right
# 331 "data/maps/MauvilleCity/scripts.pory"
	walk_in_place_faster_up
# 332 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 333 "data/maps/MauvilleCity/scripts.pory"

# 334 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_WallysUncleApproachPlayerEast:
# 335 "data/maps/MauvilleCity/scripts.pory"
	walk_right
# 336 "data/maps/MauvilleCity/scripts.pory"
	walk_up
# 337 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 338 "data/maps/MauvilleCity/scripts.pory"

# 339 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_WallysUncleExitNorth2:
# 340 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 341 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 342 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 343 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 344 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 345 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 346 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 347 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 348 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 349 "data/maps/MauvilleCity/scripts.pory"

# 350 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_WallysUncleExitEast2:
# 351 "data/maps/MauvilleCity/scripts.pory"
	walk_down
# 352 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 353 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 354 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 355 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 356 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 357 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 358 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 359 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 360 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 361 "data/maps/MauvilleCity/scripts.pory"

# 362 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_ScottApproachPlayerNorth:
# 363 "data/maps/MauvilleCity/scripts.pory"
	walk_up
# 364 "data/maps/MauvilleCity/scripts.pory"
	walk_up
# 365 "data/maps/MauvilleCity/scripts.pory"
	walk_up
# 366 "data/maps/MauvilleCity/scripts.pory"
	walk_up
# 367 "data/maps/MauvilleCity/scripts.pory"
	walk_up
# 368 "data/maps/MauvilleCity/scripts.pory"
	walk_up
# 369 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 370 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 371 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 372 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 373 "data/maps/MauvilleCity/scripts.pory"
	walk_in_place_faster_up
# 374 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 375 "data/maps/MauvilleCity/scripts.pory"

# 376 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_ScottApproachPlayerEast:
# 377 "data/maps/MauvilleCity/scripts.pory"
	walk_up
# 378 "data/maps/MauvilleCity/scripts.pory"
	walk_up
# 379 "data/maps/MauvilleCity/scripts.pory"
	walk_up
# 380 "data/maps/MauvilleCity/scripts.pory"
	walk_up
# 381 "data/maps/MauvilleCity/scripts.pory"
	walk_up
# 382 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 383 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 384 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 385 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 386 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 387 "data/maps/MauvilleCity/scripts.pory"
	walk_up
# 388 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 389 "data/maps/MauvilleCity/scripts.pory"

# 390 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_ScottExitNorth:
# 391 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 392 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 393 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 394 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 395 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 396 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 397 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 398 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 399 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 400 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 401 "data/maps/MauvilleCity/scripts.pory"

# 402 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_ScottExitEast:
# 403 "data/maps/MauvilleCity/scripts.pory"
	walk_down
# 404 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 405 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 406 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 407 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 408 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 409 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 410 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 411 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 412 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 413 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 414 "data/maps/MauvilleCity/scripts.pory"

# 415 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_Wattson::
# 416 "data/maps/MauvilleCity/scripts.pory"
	lock
# 417 "data/maps/MauvilleCity/scripts.pory"
	faceplayer
# 418 "data/maps/MauvilleCity/scripts.pory"
	goto_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_ReceivedThunderbolt
# 419 "data/maps/MauvilleCity/scripts.pory"
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_EventScript_CompletedNewMauville
# 420 "data/maps/MauvilleCity/scripts.pory"
	goto_if_set FLAG_GOT_BASEMENT_KEY_FROM_WATTSON, MauvilleCity_EventScript_BegunNewMauville
# 421 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_WattsonNeedFavorTakeKey, MSGBOX_DEFAULT
# 422 "data/maps/MauvilleCity/scripts.pory"
	giveitem ITEM_BASEMENT_KEY
# 423 "data/maps/MauvilleCity/scripts.pory"
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON
# 424 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
# 425 "data/maps/MauvilleCity/scripts.pory"
	release
# 426 "data/maps/MauvilleCity/scripts.pory"
	end
# 427 "data/maps/MauvilleCity/scripts.pory"

# 428 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_BegunNewMauville::
# 429 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
# 430 "data/maps/MauvilleCity/scripts.pory"
	release
# 431 "data/maps/MauvilleCity/scripts.pory"
	end
# 432 "data/maps/MauvilleCity/scripts.pory"

# 433 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_CompletedNewMauville::
# 434 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_WattsonThanksTakeTM, MSGBOX_DEFAULT
# 435 "data/maps/MauvilleCity/scripts.pory"
	giveitem ITEM_TM_THUNDERBOLT
# 436 "data/maps/MauvilleCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 437 "data/maps/MauvilleCity/scripts.pory"
	setflag FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON
# 438 "data/maps/MauvilleCity/scripts.pory"
	giveitem ITEM_ULTRA_BALL, 20
# 439 "data/maps/MauvilleCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 440 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
# 441 "data/maps/MauvilleCity/scripts.pory"
	release
# 442 "data/maps/MauvilleCity/scripts.pory"
	end
# 443 "data/maps/MauvilleCity/scripts.pory"

# 444 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_ReceivedThunderbolt::
# 445 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
# 446 "data/maps/MauvilleCity/scripts.pory"
	release
# 447 "data/maps/MauvilleCity/scripts.pory"
	end
# 448 "data/maps/MauvilleCity/scripts.pory"

# 449 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_RegisterWallyCall::
# 450 "data/maps/MauvilleCity/scripts.pory"
	lockall
# 451 "data/maps/MauvilleCity/scripts.pory"
	pokenavcall MauvilleCity_Text_WallyPokenavCall
# 452 "data/maps/MauvilleCity/scripts.pory"
	waitmessage
# 453 "data/maps/MauvilleCity/scripts.pory"
	delay 30
# 454 "data/maps/MauvilleCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 455 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_RegisteredWally, MSGBOX_DEFAULT
# 456 "data/maps/MauvilleCity/scripts.pory"
	waitfanfare
# 457 "data/maps/MauvilleCity/scripts.pory"
	closemessage
# 458 "data/maps/MauvilleCity/scripts.pory"
	delay 30
# 459 "data/maps/MauvilleCity/scripts.pory"
	setflag FLAG_ENABLE_WALLY_MATCH_CALL
# 460 "data/maps/MauvilleCity/scripts.pory"
	clearflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
# 461 "data/maps/MauvilleCity/scripts.pory"
	releaseall
# 462 "data/maps/MauvilleCity/scripts.pory"
	end
# 463 "data/maps/MauvilleCity/scripts.pory"

# 464 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_UncleHesTooPeppy:
# 465 "data/maps/MauvilleCity/scripts.pory"
	.string "UNCLE: It's because of POKéMON that\n"
# 466 "data/maps/MauvilleCity/scripts.pory"
	.string "this boy's got more pep, I suppose…\l"
# 467 "data/maps/MauvilleCity/scripts.pory"
	.string "But he's become a bit too peppy…$"
# 468 "data/maps/MauvilleCity/scripts.pory"

# 469 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_WallyWantToChallengeGym:
# 470 "data/maps/MauvilleCity/scripts.pory"
	.string "WALLY: Aww, UNCLE, please?\p"
# 471 "data/maps/MauvilleCity/scripts.pory"
	.string "I want to challenge this GYM and see\n"
# 472 "data/maps/MauvilleCity/scripts.pory"
	.string "how much better I've become.\p"
# 473 "data/maps/MauvilleCity/scripts.pory"
	.string "Please? May I, please?$"
# 474 "data/maps/MauvilleCity/scripts.pory"

# 475 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_UncleYourePushingIt:
# 476 "data/maps/MauvilleCity/scripts.pory"
	.string "UNCLE: Now hold on, WALLY.\p"
# 477 "data/maps/MauvilleCity/scripts.pory"
	.string "Since you started living with POKéMON,\n"
# 478 "data/maps/MauvilleCity/scripts.pory"
	.string "you have grown quite a lot stronger.\p"
# 479 "data/maps/MauvilleCity/scripts.pory"
	.string "But don't you think you're pushing it\n"
# 480 "data/maps/MauvilleCity/scripts.pory"
	.string "to suddenly challenge a GYM?$"
# 481 "data/maps/MauvilleCity/scripts.pory"

# 482 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_WallyWeCanBeatAnyone:
# 483 "data/maps/MauvilleCity/scripts.pory"
	.string "WALLY: I'm not pushing it.\p"
# 484 "data/maps/MauvilleCity/scripts.pory"
	.string "If I combine forces with RALTS,\n"
# 485 "data/maps/MauvilleCity/scripts.pory"
	.string "we can beat anyone!$"
# 486 "data/maps/MauvilleCity/scripts.pory"

# 487 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_WallyWillYouBattleMe:
# 488 "data/maps/MauvilleCity/scripts.pory"
	.string "WALLY: Oh! Hi, {PLAYER}!\p"
# 489 "data/maps/MauvilleCity/scripts.pory"
	.string "I've gotten a lot stronger since\n"
# 490 "data/maps/MauvilleCity/scripts.pory"
	.string "we met.\p"
# 491 "data/maps/MauvilleCity/scripts.pory"
	.string "{PLAYER}, I want you and my UNCLE to\n"
# 492 "data/maps/MauvilleCity/scripts.pory"
	.string "understand that.\p"
# 493 "data/maps/MauvilleCity/scripts.pory"
	.string "{PLAYER}, please, will you have\n"
# 494 "data/maps/MauvilleCity/scripts.pory"
	.string "a battle with me?$"
# 495 "data/maps/MauvilleCity/scripts.pory"

# 496 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_WallyMyUncleWontKnowImStrong:
# 497 "data/maps/MauvilleCity/scripts.pory"
	.string "WALLY: Oh… If you won't battle me,\n"
# 498 "data/maps/MauvilleCity/scripts.pory"
	.string "{PLAYER}, my UNCLE won't know that I've\l"
# 499 "data/maps/MauvilleCity/scripts.pory"
	.string "become really strong.$"
# 500 "data/maps/MauvilleCity/scripts.pory"

# 501 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_UncleCanYouBattleWally:
# 502 "data/maps/MauvilleCity/scripts.pory"
	.string "UNCLE: {PLAYER}{KUN}, was it?\n"
# 503 "data/maps/MauvilleCity/scripts.pory"
	.string "On WALLY's behalf, can I ask you to\l"
# 504 "data/maps/MauvilleCity/scripts.pory"
	.string "battle with him just this once?\p"
# 505 "data/maps/MauvilleCity/scripts.pory"
	.string "I don't think he's going to listen to\n"
# 506 "data/maps/MauvilleCity/scripts.pory"
	.string "any reason the way he is now.$"
# 507 "data/maps/MauvilleCity/scripts.pory"

# 508 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_WallyPleaseBattleMe:
# 509 "data/maps/MauvilleCity/scripts.pory"
	.string "WALLY: {PLAYER}, please!\n"
# 510 "data/maps/MauvilleCity/scripts.pory"
	.string "Battle with me, please.$"
# 511 "data/maps/MauvilleCity/scripts.pory"

# 512 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_WallyHereICome:
# 513 "data/maps/MauvilleCity/scripts.pory"
	.string "WALLY: {PLAYER}, thank you.\p"
# 514 "data/maps/MauvilleCity/scripts.pory"
	.string "Okay… Here I come!$"
# 515 "data/maps/MauvilleCity/scripts.pory"

# 516 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_WallyDefeat:
# 517 "data/maps/MauvilleCity/scripts.pory"
	.string "WALLY: … … … … … … …\p"
# 518 "data/maps/MauvilleCity/scripts.pory"
	.string "… … … … … … … …\p"
# 519 "data/maps/MauvilleCity/scripts.pory"
	.string "I lost…$"
# 520 "data/maps/MauvilleCity/scripts.pory"

# 521 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_WallyIllGoBackToVerdanturf:
# 522 "data/maps/MauvilleCity/scripts.pory"
	.string "WALLY: UNCLE…\n"
# 523 "data/maps/MauvilleCity/scripts.pory"
	.string "I'll go back to VERDANTURF…$"
# 524 "data/maps/MauvilleCity/scripts.pory"

# 525 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_ThankYouNotEnoughToBattle:
# 526 "data/maps/MauvilleCity/scripts.pory"
	.string "{PLAYER}, thank you.\n"
# 527 "data/maps/MauvilleCity/scripts.pory"
	.string "Being a TRAINER is tough, isn't it?\p"
# 528 "data/maps/MauvilleCity/scripts.pory"
	.string "It's not enough just to have POKéMON\n"
# 529 "data/maps/MauvilleCity/scripts.pory"
	.string "and make them battle. That isn't what\l"
# 530 "data/maps/MauvilleCity/scripts.pory"
	.string "being a real TRAINER is about.$"
# 531 "data/maps/MauvilleCity/scripts.pory"

# 532 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_UncleNoNeedToBeDown:
# 533 "data/maps/MauvilleCity/scripts.pory"
	.string "UNCLE: WALLY, there's no need to be so\n"
# 534 "data/maps/MauvilleCity/scripts.pory"
	.string "down on yourself.\p"
# 535 "data/maps/MauvilleCity/scripts.pory"
	.string "Why, what's keeping you from becoming\n"
# 536 "data/maps/MauvilleCity/scripts.pory"
	.string "stronger and stronger?\p"
# 537 "data/maps/MauvilleCity/scripts.pory"
	.string "Come on, let's go home.\n"
# 538 "data/maps/MauvilleCity/scripts.pory"
	.string "Everyone's waiting for you.$"
# 539 "data/maps/MauvilleCity/scripts.pory"

# 540 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_UncleVisitUsSometime:
# 541 "data/maps/MauvilleCity/scripts.pory"
	.string "UNCLE: {PLAYER}{KUN}, it just dawned on me\n"
# 542 "data/maps/MauvilleCity/scripts.pory"
	.string "that you must be the TRAINER who kept\l"
# 543 "data/maps/MauvilleCity/scripts.pory"
	.string "an eye out for WALLY when he caught\l"
# 544 "data/maps/MauvilleCity/scripts.pory"
	.string "his POKéMON.\p"
# 545 "data/maps/MauvilleCity/scripts.pory"
	.string "Why don't you visit us in VERDANTURF\n"
# 546 "data/maps/MauvilleCity/scripts.pory"
	.string "sometime?\l"
# 547 "data/maps/MauvilleCity/scripts.pory"
	.string "I'm sure WALLY would enjoy it.$"
# 548 "data/maps/MauvilleCity/scripts.pory"

# 549 "data/maps/MauvilleCity/scripts.pory"

# 550 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_WallyPokenavCall:
# 551 "data/maps/MauvilleCity/scripts.pory"
	.string "… … … … … …\n"
# 552 "data/maps/MauvilleCity/scripts.pory"
	.string "… … … … … Beep!\p"
# 553 "data/maps/MauvilleCity/scripts.pory"
	.string "WALLY: Oh, hello, {PLAYER}!\p"
# 554 "data/maps/MauvilleCity/scripts.pory"
	.string "I just wanted to tell you that\n"
# 555 "data/maps/MauvilleCity/scripts.pory"
	.string "my uncle bought me a POKéNAV!\p"
# 556 "data/maps/MauvilleCity/scripts.pory"
	.string "Now I can get in touch with you\n"
# 557 "data/maps/MauvilleCity/scripts.pory"
	.string "anytime, {PLAYER}!\p"
# 558 "data/maps/MauvilleCity/scripts.pory"
	.string "… … … … … …\n"
# 559 "data/maps/MauvilleCity/scripts.pory"
	.string "… … … … … Click!$"
# 560 "data/maps/MauvilleCity/scripts.pory"

# 561 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_RegisteredWally:
# 562 "data/maps/MauvilleCity/scripts.pory"
	.string "Registered WALLY\n"
# 563 "data/maps/MauvilleCity/scripts.pory"
	.string "in the POKéNAV.$"
# 564 "data/maps/MauvilleCity/scripts.pory"

# 565 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_ScottYouDidntHoldBack:
# 566 "data/maps/MauvilleCity/scripts.pory"
	.string "SCOTT: Hehe…\n"
# 567 "data/maps/MauvilleCity/scripts.pory"
	.string "I was watching that match!\p"
# 568 "data/maps/MauvilleCity/scripts.pory"
	.string "You're friends with that boy WALLY,\n"
# 569 "data/maps/MauvilleCity/scripts.pory"
	.string "aren't you?\p"
# 570 "data/maps/MauvilleCity/scripts.pory"
	.string "But you didn't hold anything back\n"
# 571 "data/maps/MauvilleCity/scripts.pory"
	.string "and beat him impressively.\p"
# 572 "data/maps/MauvilleCity/scripts.pory"
	.string "Yeah! That's what a real POKéMON\n"
# 573 "data/maps/MauvilleCity/scripts.pory"
	.string "battle is all about!\p"
# 574 "data/maps/MauvilleCity/scripts.pory"
	.string "I idolize TRAINERS like that!\p"
# 575 "data/maps/MauvilleCity/scripts.pory"
	.string "… … … … … …\n"
# 576 "data/maps/MauvilleCity/scripts.pory"
	.string "I'll be cheering for you!$"
# 577 "data/maps/MauvilleCity/scripts.pory"

# 578 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_WattsonNeedFavorTakeKey:
# 579 "data/maps/MauvilleCity/scripts.pory"
	.string "WATTSON: Oh, {PLAYER}{KUN}!\n"
# 580 "data/maps/MauvilleCity/scripts.pory"
	.string "You look like you have a lot of zip!\l"
# 581 "data/maps/MauvilleCity/scripts.pory"
	.string "That's a good thing, wahahahaha!\p"
# 582 "data/maps/MauvilleCity/scripts.pory"
	.string "Fine! I've decided!\n"
# 583 "data/maps/MauvilleCity/scripts.pory"
	.string "I need a favor, {PLAYER}{KUN}!\p"
# 584 "data/maps/MauvilleCity/scripts.pory"
	.string "MAUVILLE CITY has an underground\n"
# 585 "data/maps/MauvilleCity/scripts.pory"
	.string "sector called NEW MAUVILLE.\p"
# 586 "data/maps/MauvilleCity/scripts.pory"
	.string "{PLAYER}{KUN}, I'd like you to go there and\n"
# 587 "data/maps/MauvilleCity/scripts.pory"
	.string "switch off the GENERATOR.\p"
# 588 "data/maps/MauvilleCity/scripts.pory"
	.string "The GENERATOR has been running a bit\n"
# 589 "data/maps/MauvilleCity/scripts.pory"
	.string "haywire. It's getting unsafe.\p"
# 590 "data/maps/MauvilleCity/scripts.pory"
	.string "Here, this is the KEY to get into\n"
# 591 "data/maps/MauvilleCity/scripts.pory"
	.string "NEW MAUVILLE.$"
# 592 "data/maps/MauvilleCity/scripts.pory"

# 593 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_WattsonWontBeChallenge:
# 594 "data/maps/MauvilleCity/scripts.pory"
	.string "WATTSON: Don't you worry about it.\n"
# 595 "data/maps/MauvilleCity/scripts.pory"
	.string "It won't be a challenge to you.\p"
# 596 "data/maps/MauvilleCity/scripts.pory"
	.string "The entrance to NEW MAUVILLE is just\n"
# 597 "data/maps/MauvilleCity/scripts.pory"
	.string "a short SURF away from ROUTE 110.\p"
# 598 "data/maps/MauvilleCity/scripts.pory"
	.string "That's it, then, you have my trust!\n"
# 599 "data/maps/MauvilleCity/scripts.pory"
	.string "Wahahahaha!$"
# 600 "data/maps/MauvilleCity/scripts.pory"

# 601 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_WattsonThanksTakeTM:
# 602 "data/maps/MauvilleCity/scripts.pory"
	.string "WATTSON: Wahahahaha!\p"
# 603 "data/maps/MauvilleCity/scripts.pory"
	.string "I knew it, {PLAYER}{KUN}! I knew I'd made\n"
# 604 "data/maps/MauvilleCity/scripts.pory"
	.string "the right choice asking you!\p"
# 605 "data/maps/MauvilleCity/scripts.pory"
	.string "This is my thanks--a TM containing\n"
# 606 "data/maps/MauvilleCity/scripts.pory"
	.string "THUNDERBOLT!\p"
# 607 "data/maps/MauvilleCity/scripts.pory"
	.string "Go on, you've earned it!$"
# 608 "data/maps/MauvilleCity/scripts.pory"

# 609 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_WattsonYoungTakeCharge:
# 610 "data/maps/MauvilleCity/scripts.pory"
	.string "WATTSON: Wahahahaha!\p"
# 611 "data/maps/MauvilleCity/scripts.pory"
	.string "It pleases me to no end to see\n"
# 612 "data/maps/MauvilleCity/scripts.pory"
	.string "the young step up and take charge!$"
# 613 "data/maps/MauvilleCity/scripts.pory"

# 614 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_NurseHurtMonBackToHealth:
# 615 "data/maps/MauvilleCity/scripts.pory"
	.string "You know, it's cool to have POKéMON\n"
# 616 "data/maps/MauvilleCity/scripts.pory"
	.string "battles and stuff…\p"
# 617 "data/maps/MauvilleCity/scripts.pory"
	.string "But if your POKéMON gets hurt,\n"
# 618 "data/maps/MauvilleCity/scripts.pory"
	.string "you have to nurse it back to health.$"
# 619 "data/maps/MauvilleCity/scripts.pory"

# 620 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_AllSortsOfPeopleComeThrough:
# 621 "data/maps/MauvilleCity/scripts.pory"
	.string "The roads of this town stretch north\n"
# 622 "data/maps/MauvilleCity/scripts.pory"
	.string "and south, and east and west.\p"
# 623 "data/maps/MauvilleCity/scripts.pory"
	.string "Because of that, we get all sorts of\n"
# 624 "data/maps/MauvilleCity/scripts.pory"
	.string "people coming through.$"
# 625 "data/maps/MauvilleCity/scripts.pory"

# 626 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_RydelVeryGenerous:
# 627 "data/maps/MauvilleCity/scripts.pory"
	.string "Have you been to RYDEL'S CYCLES yet?\p"
# 628 "data/maps/MauvilleCity/scripts.pory"
	.string "RYDEL, the owner, is a very generous\n"
# 629 "data/maps/MauvilleCity/scripts.pory"
	.string "man.$"
# 630 "data/maps/MauvilleCity/scripts.pory"

# 631 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_PokemonCanJumpYouOnBike:
# 632 "data/maps/MauvilleCity/scripts.pory"
	.string "Even if you're riding a BIKE,\n"
# 633 "data/maps/MauvilleCity/scripts.pory"
	.string "wild POKéMON could jump you.$"
# 634 "data/maps/MauvilleCity/scripts.pory"

# 635 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_CitySign:
# 636 "data/maps/MauvilleCity/scripts.pory"
	.string "MAUVILLE CITY\n"
# 637 "data/maps/MauvilleCity/scripts.pory"
	.string "“The bright and shiny city of fun!”$"
# 638 "data/maps/MauvilleCity/scripts.pory"

# 639 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_GymSign:
# 640 "data/maps/MauvilleCity/scripts.pory"
	.string "MAUVILLE CITY POKéMON GYM\n"
# 641 "data/maps/MauvilleCity/scripts.pory"
	.string "LEADER: WATTSON\l"
# 642 "data/maps/MauvilleCity/scripts.pory"
	.string "“The cheerfully electrifying man!”$"
# 643 "data/maps/MauvilleCity/scripts.pory"

# 644 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_BikeShopSign:
# 645 "data/maps/MauvilleCity/scripts.pory"
	.string "“Ride in gravel and shake up your\n"
# 646 "data/maps/MauvilleCity/scripts.pory"
	.string "soul!”\l"
# 647 "data/maps/MauvilleCity/scripts.pory"
	.string "RYDEL'S CYCLES$"
# 648 "data/maps/MauvilleCity/scripts.pory"

# 649 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_GameCornerSign:
# 650 "data/maps/MauvilleCity/scripts.pory"
	.string "“The play spot for all!”\n"
# 651 "data/maps/MauvilleCity/scripts.pory"
	.string "MAUVILLE GAME CORNER$"
# 652 "data/maps/MauvilleCity/scripts.pory"

# 653 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_ExplainTV:
# 654 "data/maps/MauvilleCity/scripts.pory"
	.string "Hi, do you check out TV at all?\p"
# 655 "data/maps/MauvilleCity/scripts.pory"
	.string "They've added a bunch of cool new\n"
# 656 "data/maps/MauvilleCity/scripts.pory"
	.string "shows recently.\p"
# 657 "data/maps/MauvilleCity/scripts.pory"
	.string "TV is so cool. I've seen my friends on\n"
# 658 "data/maps/MauvilleCity/scripts.pory"
	.string "TV just out of the blue.\p"
# 659 "data/maps/MauvilleCity/scripts.pory"
	.string "And, sometimes, they even put you on TV\n"
# 660 "data/maps/MauvilleCity/scripts.pory"
	.string "without telling you.\p"
# 661 "data/maps/MauvilleCity/scripts.pory"
	.string "I wish I would be on TV sometime.\p"
# 662 "data/maps/MauvilleCity/scripts.pory"
	.string "That's why I think you should check\n"
# 663 "data/maps/MauvilleCity/scripts.pory"
	.string "out TVs whenever you can.$"
# 664 "data/maps/MauvilleCity/scripts.pory"

# 665 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_BeenCheckingOutTV:
# 666 "data/maps/MauvilleCity/scripts.pory"
	.string "Hi, have you been checking out TVs?$"
# 667 "data/maps/MauvilleCity/scripts.pory"

# 668 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_MoveRelearnersHouse_EventScript_MoveRelearner::
# 669 "data/maps/MauvilleCity/scripts.pory"
	lockall
# 670 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
# 671 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 672 "data/maps/MauvilleCity/scripts.pory"
	goto_if_set FLAG_TEMP_1, FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
# 673 "data/maps/MauvilleCity/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
# 674 "data/maps/MauvilleCity/scripts.pory"
	setflag FLAG_TEMP_1
# 675 "data/maps/MauvilleCity/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
# 676 "data/maps/MauvilleCity/scripts.pory"
	end
# 677 "data/maps/MauvilleCity/scripts.pory"

# 678 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_MoveRelearnersHouse_EventScript_AskTeachMove::
# 679 "data/maps/MauvilleCity/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
# 680 "data/maps/MauvilleCity/scripts.pory"
	switch VAR_RESULT
# 681 "data/maps/MauvilleCity/scripts.pory"
	case NO, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
# 682 "data/maps/MauvilleCity/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
# 683 "data/maps/MauvilleCity/scripts.pory"
	end
# 684 "data/maps/MauvilleCity/scripts.pory"

# 685 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_MoveRelearnersHouse_EventScript_ChooseMon::
# 686 "data/maps/MauvilleCity/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
# 687 "data/maps/MauvilleCity/scripts.pory"
	special ChooseMonForMoveRelearner
# 688 "data/maps/MauvilleCity/scripts.pory"
	waitstate
# 689 "data/maps/MauvilleCity/scripts.pory"
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
# 690 "data/maps/MauvilleCity/scripts.pory"
	special IsSelectedMonEgg
# 691 "data/maps/MauvilleCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg
# 692 "data/maps/MauvilleCity/scripts.pory"
	goto_if_eq VAR_0x8005, 0, FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
# 693 "data/maps/MauvilleCity/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove
# 694 "data/maps/MauvilleCity/scripts.pory"
	end
# 695 "data/maps/MauvilleCity/scripts.pory"

# 696 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_MoveRelearnersHouse_EventScript_ChooseMove::
# 697 "data/maps/MauvilleCity/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
# 698 "data/maps/MauvilleCity/scripts.pory"
	special TeachMoveRelearnerMove
# 699 "data/maps/MauvilleCity/scripts.pory"
	waitstate
# 700 "data/maps/MauvilleCity/scripts.pory"
	goto_if_eq VAR_0x8004, 0, FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
# 701 "data/maps/MauvilleCity/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
# 702 "data/maps/MauvilleCity/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
# 703 "data/maps/MauvilleCity/scripts.pory"
	end
# 704 "data/maps/MauvilleCity/scripts.pory"

# 705 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_MoveRelearnersHouse_EventScript_NoMoveToTeachMon::
# 706 "data/maps/MauvilleCity/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
# 707 "data/maps/MauvilleCity/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
# 708 "data/maps/MauvilleCity/scripts.pory"
	end
# 709 "data/maps/MauvilleCity/scripts.pory"

# 710 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_MoveRelearnersHouse_EventScript_CantTeachEgg::
# 711 "data/maps/MauvilleCity/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
# 712 "data/maps/MauvilleCity/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
# 713 "data/maps/MauvilleCity/scripts.pory"
	end
# 714 "data/maps/MauvilleCity/scripts.pory"

# 715 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale::
# 716 "data/maps/MauvilleCity/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
# 717 "data/maps/MauvilleCity/scripts.pory"
	releaseall
# 718 "data/maps/MauvilleCity/scripts.pory"
	end
# 719 "data/maps/MauvilleCity/scripts.pory"

# 720 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_MoveRelearnersHouse_Text_ImTheMoveTutor:
# 721 "data/maps/MauvilleCity/scripts.pory"
	.string "I'm the MOVE TUTOR.\p"
# 722 "data/maps/MauvilleCity/scripts.pory"
	.string "I know all the moves that POKéMON\n"
# 723 "data/maps/MauvilleCity/scripts.pory"
	.string "learn--every one of them--and I can\l"
# 724 "data/maps/MauvilleCity/scripts.pory"
	.string "teach POKéMON those moves.\p"
# 725 "data/maps/MauvilleCity/scripts.pory"
	.string "I can teach a move to a POKéMON\n"
# 726 "data/maps/MauvilleCity/scripts.pory"
	.string "of yours if you'd like.\p"
# 727 "data/maps/MauvilleCity/scripts.pory"
	.string "I'll do it for FREE.$"
# 728 "data/maps/MauvilleCity/scripts.pory"

# 729 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove:
# 730 "data/maps/MauvilleCity/scripts.pory"
	.string "Oh! That's it! That's an honest to\n"
# 731 "data/maps/MauvilleCity/scripts.pory"
	.string "goodness FREEDOM!\p"
# 732 "data/maps/MauvilleCity/scripts.pory"
	.string "Let me guess, you want me to teach\n"
# 733 "data/maps/MauvilleCity/scripts.pory"
	.string "a move?$"
# 734 "data/maps/MauvilleCity/scripts.pory"

# 735 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_MoveRelearnersHouse_Text_TutorWhichMon:
# 736 "data/maps/MauvilleCity/scripts.pory"
	.string "Which POKéMON needs tutoring?$"
# 737 "data/maps/MauvilleCity/scripts.pory"

# 738 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_MoveRelearnersHouse_Text_TeachWhichMove:
# 739 "data/maps/MauvilleCity/scripts.pory"
	.string "Which move should I teach?$"
# 740 "data/maps/MauvilleCity/scripts.pory"

# 741 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon:
# 742 "data/maps/MauvilleCity/scripts.pory"
	.string "Sorry…\p"
# 743 "data/maps/MauvilleCity/scripts.pory"
	.string "It doesn't appear as if I have any move\n"
# 744 "data/maps/MauvilleCity/scripts.pory"
	.string "I can teach that POKéMON.$"
# 745 "data/maps/MauvilleCity/scripts.pory"

# 746 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_MoveRelearnersHouse_Text_HandedOverHeartScale:
# 747 "data/maps/MauvilleCity/scripts.pory"
	.string "{PLAYER} handed over one FREEDOM UNIT\n"
# 748 "data/maps/MauvilleCity/scripts.pory"
	.string "in exchange.$"
# 749 "data/maps/MauvilleCity/scripts.pory"

# 750 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_MoveRelearnersHouse_Text_ComeBackWithHeartScale:
# 751 "data/maps/MauvilleCity/scripts.pory"
	.string "If your POKéMON need to learn a move,\n"
# 752 "data/maps/MauvilleCity/scripts.pory"
	.string "come back with a FREEDOM UNIT.$"
# 753 "data/maps/MauvilleCity/scripts.pory"

# 754 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_MoveRelearnersHouse_Text_CantTeachEgg:
# 755 "data/maps/MauvilleCity/scripts.pory"
	.string "Hunh? There isn't a single move that\n"
# 756 "data/maps/MauvilleCity/scripts.pory"
	.string "I can teach an EGG.$"

testfight::
# 762 "data/maps/MauvilleCity/scripts.pory"
	lockall
# 763 "data/maps/MauvilleCity/scripts.pory"
	trainerbattle_single TRAINER_TEST, introben, outroben
	return


introben::
# 766 "data/maps/MauvilleCity/scripts.pory"
	.string "start$"

outroben::
# 770 "data/maps/MauvilleCity/scripts.pory"
	.string "end$"
