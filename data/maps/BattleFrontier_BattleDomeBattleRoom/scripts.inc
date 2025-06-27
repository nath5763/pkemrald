# 1 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ On this map the player will automatically walk into the room, but the camera is supposed to remain still.
# 3 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ To do this GF sets the player (LOCALID_PLAYER) invisible and creates a fake player object (LOCALID_DOME_PLAYER).
# 4 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ The graphics of this fake player object are represented with VAR_OBJ_GFX_ID_1.
# 5 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ The graphics of the opponent are represented with VAR_OBJ_GFX_ID_0, which will ultimately be set by dome_setopponentgfx.
# 6 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 7 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
.set NO_DRAW,       0
# 8 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
.set DRAW_TRAINER,  1
# 9 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
.set DRAW_TUCKER,   2
# 10 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 11 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_MapScripts::
# 12 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleDomeBattleRoom_OnTransition
# 13 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeBattleRoom_OnFrame
# 14 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeBattleRoom_OnWarp
# 15 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleDomeBattleRoom_OnResume
# 16 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.byte 0
# 17 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 18 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_OnTransition:
# 19 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_setopponentgfx
# 20 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 21 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 22 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_SetWalkingAudienceMemberPos
# 23 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfx
# 24 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	end
# 25 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 26 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfx::
# 27 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	checkplayergender
# 28 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxMale
# 29 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxFemale
# 30 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 31 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 32 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxMale::
# 33 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 34 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 35 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 36 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxFemale::
# 37 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 38 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 39 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 40 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_OnFrame:
# 41 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleDomeBattleRoom_EventScript_EnterRoom
# 42 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.2byte 0
# 43 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 44 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_EnterRoom::
# 45 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	lockall
# 46 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
# 47 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_TryDoAudienceMemberWalkToSeat
# 48 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_ANNOUNCER, Common_Movement_WalkInPlaceDown
# 49 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 50 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayer
# 51 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerHasEnteredDome, MSGBOX_DEFAULT
# 52 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 53 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	showobjectat LOCALID_DOME_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_DOME_BATTLE_ROOM
# 54 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_TEMP_F, DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerEnter
# 55 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_TEMP_E, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerEnterForTucker
# 56 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerEnter::
# 57 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerEnter
# 58 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceReactToPlayer
# 59 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 60 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerEnterForTucker::
# 61 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerEnterForTucker
# 62 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceReactToPlayer::
# 63 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 64 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 65 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 66 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_TEMP_F, DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_BattleOpponent
# 67 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_TEMP_E, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTucker
# 68 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_BattleOpponent::
# 69 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_getopponentname
# 70 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerVersusTrainer, MSGBOX_DEFAULT
# 71 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 72 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerStepForward
# 73 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_OpponentStepForward
# 74 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 75 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	tower_getopponentintro 0
# 76 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 77 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 78 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_initopponentparty
# 79 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_DoDomeBattle
# 80 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, NO_DRAW
# 81 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 82 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_WON, BattleFrontier_BattleDomeBattleRoom_EventScript_DefeatedOpponent
# 83 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_LOST, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToOpponent
# 84 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_FORFEITED, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToOpponent
# 85 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, DRAW_TRAINER
# 86 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_Draw::
# 87 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_RefereeDecisionPleaseWait, MSGBOX_DEFAULT
# 88 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 89 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 90 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 91 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 60
# 92 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_REFEREE, BattleFrontier_BattleDomeBattleRoom_Movement_RefereeEnter
# 93 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 94 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_ANNOUNCER, BattleFrontier_BattleDomeBattleRoom_Movement_AnnouncerFaceLeft
# 95 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 96 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 180
# 97 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_REFEREE, BattleFrontier_BattleDomeBattleRoom_Movement_RefereeExit
# 98 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 99 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_TEMP_2, DRAW_TUCKER, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToOpponent @ Tucker always wins on a draw
# 100 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_compareseeds
# 101 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 102 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleDomeBattleRoom_EventScript_DefeatedOpponent
# 103 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_LostToOpponent::
# 104 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_ANNOUNCER, Common_Movement_WalkInPlaceDown
# 105 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 106 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_getopponentname
# 107 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_2, NO_DRAW, BattleFrontier_BattleDomeBattleRoom_EventScript_OpponentWon
# 108 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_2, DRAW_TRAINER, BattleFrontier_BattleDomeBattleRoom_EventScript_OpponentWonDraw
# 109 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_2, DRAW_TUCKER, BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerWonDraw
# 110 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 111 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 112 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 60
# 113 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_LostTourney::
# 114 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_resolvewinners DOME_PLAYER_LOST_MATCH
# 115 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobbyLost::
# 116 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 117 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobby
# 118 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 119 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_OpponentWon::
# 120 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_gettrainername STR_VAR_2
# 121 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_TrainerIsWinner
# 122 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 123 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 124 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 125 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_OpponentWonDraw::
# 126 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_gettrainername STR_VAR_1
# 127 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerTrainer
# 128 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 129 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 130 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 131 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerWonDraw::
# 132 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerTucker
# 133 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 134 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 135 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 136 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_DefeatedOpponent::
# 137 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_ANNOUNCER, Common_Movement_WalkInPlaceDown
# 138 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 139 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_2, NO_DRAW, BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerWon
# 140 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_2, DRAW_TRAINER, BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerWonDraw
# 141 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 142 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 143 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 60
# 144 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_getroundtext
# 145 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_resolvewinners DOME_PLAYER_WON_MATCH
# 146 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 147 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 148 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 149 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 150 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUNDS_COUNT, BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney
# 151 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_0x8006, 1
# 152 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_PRE_BATTLE_ROOM, 5, 3
# 153 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitstate
# 154 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 155 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney::
# 156 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerApproachAudience
# 157 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 158 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_LVL_MODE
# 159 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 160 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleDomeBattleRoom_EventScript_WonLvOpenTourney
# 161 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLv50Champ, MSGBOX_DEFAULT
# 162 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_CelebrateWin
# 163 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 164 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_WonLvOpenTourney::
# 165 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLvOpenChamp, MSGBOX_DEFAULT
# 166 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_CelebrateWin::
# 167 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	special DoDomeConfetti
# 168 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 169 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 170 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 60
# 171 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 172 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobby
# 173 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 174 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerWon::
# 175 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsWinner, MSGBOX_DEFAULT
# 176 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 177 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 178 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerWonDraw::
# 179 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerPlayer, MSGBOX_DEFAULT
# 180 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 181 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 182 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayer::
# 183 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_get DOME_DATA_ATTEMPTED_CHALLENGE
# 184 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttempt
# 185 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_get DOME_DATA_HAS_WON_CHALLENGE
# 186 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWon
# 187 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_get DOME_DATA_WIN_STREAK_ACTIVE
# 188 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreak
# 189 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampion
# 190 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 191 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 192 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttempt::
# 193 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
# 194 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 195 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptRound1
# 196 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND2, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptRound2
# 197 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_SEMIFINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptSemifinal
# 198 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptFinal
# 199 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 200 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 201 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptRound1::
# 202 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_BrightNewHope
# 203 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 204 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 205 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 206 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptRound2::
# 207 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_RisingStar
# 208 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 209 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 210 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 211 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptSemifinal::
# 212 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_WillTheyRaceToChampionship
# 213 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 214 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 215 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 216 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptFinal::
# 217 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_CanAchieveChampionFirstTry
# 218 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 219 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 220 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 221 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWon::
# 222 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
# 223 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 224 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonRound1
# 225 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND2, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonRound2
# 226 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_SEMIFINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonSemifinal
# 227 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonFinal
# 228 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 229 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 230 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonRound1::
# 231 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_CanLossBeAvenged
# 232 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 233 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 234 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 235 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonRound2::
# 236 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_OnFireForChampionship
# 237 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 238 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 239 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 240 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonSemifinal::
# 241 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_WinHereAdvancesToFinal
# 242 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 243 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 244 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 245 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonFinal::
# 246 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_WillLongHeldDreamComeTrue
# 247 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 248 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 249 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 250 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampion::
# 251 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_TEMP_F, DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionNoTucker
# 252 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_TEMP_E
# 253 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_SILVER, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerSilver
# 254 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerGold
# 255 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerSilver
# 256 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerGold
# 257 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionNoTucker::
# 258 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
# 259 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 260 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionRound1
# 261 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND2, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionRound2
# 262 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_SEMIFINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionSemifinal
# 263 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionFinal
# 264 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 265 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 266 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionRound1::
# 267 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_TheInvincibleChampion
# 268 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 269 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 270 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 271 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionRound2::
# 272 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_CanAnyoneHopeToBeatTrainer
# 273 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 274 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 275 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 276 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionSemifinal::
# 277 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_DoBattlesExistSolelyForTrainer
# 278 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 279 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 280 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 281 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionFinal::
# 282 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_CurrentChampAimingToRetainTitle
# 283 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 284 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 285 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 286 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerSilver::
# 287 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_FeelGlowOfTrueMaster, MSGBOX_DEFAULT
# 288 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 289 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 290 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerGold::
# 291 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_CanWinStreakBeStretched, MSGBOX_DEFAULT
# 292 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 293 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 294 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreak::
# 295 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
# 296 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 297 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakRound1
# 298 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND2, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakRound2
# 299 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_SEMIFINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakSemifinal
# 300 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakFinal
# 301 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 302 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 303 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakRound1::
# 304 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_FormerChampHasReturned
# 305 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 306 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 307 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 308 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakRound2::
# 309 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_FormerToughnessReturned
# 310 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 311 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 312 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 313 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakSemifinal::
# 314 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_WillDoExpectedAdvanceToFinals
# 315 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 316 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 317 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 318 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakFinal::
# 319 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_WillFormerChampRegainGlory
# 320 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 321 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 322 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 323 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum::
# 324 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 325 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 326 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 327 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTucker::
# 328 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_TEMP_E
# 329 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_SILVER, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerSilver
# 330 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerGold
# 331 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerSilver
# 332 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerGold
# 333 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 334 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerSilver::
# 335 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_MakeWayForDomeAceTucker, MSGBOX_DEFAULT
# 336 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerEnter
# 337 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 338 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerGold::
# 339 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_LegendHasReturnedDomeAceTucker, MSGBOX_DEFAULT
# 340 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerEnter::
# 341 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 342 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_AUDIENCE_TWIN, BattleFrontier_BattleDomeBattleRoom_Movement_AudienceTwinJump
# 343 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_ANNOUNCER, BattleFrontier_BattleDomeBattleRoom_Movement_AnnouncerMoveForTuckerEntrance
# 344 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_TuckerEnterAndDance
# 345 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 346 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 347 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 348 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 349 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 350 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 351 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 352 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 353 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 354 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 355 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 356 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 357 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 358 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 359 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 360 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 361 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_SpectatorTuckerChant
# 362 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 363 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 364 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 365 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 366 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_TEMP_E
# 367 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerGoldIntro
# 368 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerSilver
# 369 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerGold
# 370 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 371 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerSilver
# 372 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_TuckerSilverIntro, MSGBOX_DEFAULT
# 373 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 374 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerSilver::
# 375 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_LetsSeeYourStrategy, MSGBOX_DEFAULT
# 376 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_DoTuckerBattle
# 377 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 378 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_LOST, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker
# 379 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_FORFEITED, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker
# 380 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_DREW, BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerDraw
# 381 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_IncredibleVictorIsPlayer, MSGBOX_DEFAULT
# 382 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_resolvewinners DOME_PLAYER_WON_MATCH
# 383 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_getsymbols
# 384 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney
# 385 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 386 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_TuckerApproachPlayer
# 387 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 388 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_SeeYourFrontierPass, MSGBOX_DEFAULT
# 389 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 390 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_ReceivedTacticsSymbol
# 391 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 392 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitfanfare
# 393 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_givesymbol
# 394 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_WontUnderestimateYouNextTime, MSGBOX_DEFAULT
# 395 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney
# 396 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 397 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerGoldIntro::
# 398 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 399 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerGold
# 400 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_TuckerGoldIntro, MSGBOX_DEFAULT
# 401 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 402 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerGold::
# 403 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_UnleashAllPowerIPossess, MSGBOX_DEFAULT
# 404 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_DoTuckerBattle
# 405 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 406 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_LOST, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker
# 407 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_FORFEITED, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker
# 408 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_DREW, BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerDraw
# 409 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_IncredibleVictorIsPlayer, MSGBOX_DEFAULT
# 410 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_resolvewinners DOME_PLAYER_WON_MATCH
# 411 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_getsymbols
# 412 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney
# 413 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 414 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_TuckerApproachPlayer
# 415 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 416 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_NeverLostWhenPowerUnleashed, MSGBOX_DEFAULT
# 417 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 418 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_TacticsSymbolTookGoldenShine
# 419 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 420 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitfanfare
# 421 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_givesymbol
# 422 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_LookForwardToNextEncounter, MSGBOX_DEFAULT
# 423 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney
# 424 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 425 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_DoTuckerBattle::
# 426 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerVersusTucker, MSGBOX_DEFAULT
# 427 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 428 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerStepForward2
# 429 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_TuckerStepForward
# 430 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 431 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_DoDomeBattle
# 432 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 433 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 434 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker::
# 435 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_WinnerIsTucker, MSGBOX_DEFAULT
# 436 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 437 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 438 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 439 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_LostTourney
# 440 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 441 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerDraw::
# 442 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, DRAW_TUCKER
# 443 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_Draw
# 444 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 445 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_DoDomeBattle::
# 446 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
# 447 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	special HealPlayerParty
# 448 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_DOME
# 449 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 450 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_9, 1
# 451 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	special DoSpecialTrainerBattle
# 452 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitstate
# 453 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_9, 0
# 454 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_restorehelditems
# 455 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	special HealPlayerParty
# 456 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_resetsketch
# 457 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 458 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 459 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_OnWarp:
# 460 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleDomeBattleRoom_EventScript_SetUpObjects
# 461 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.2byte 0
# 462 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 463 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_SetUpObjects::
# 464 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	hideobjectat LOCALID_DOME_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_DOME_BATTLE_ROOM
# 465 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AddAudience
# 466 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfx
# 467 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 468 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisible
# 469 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 470 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_EndSetUpObjects
# 471 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 472 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	copyvar VAR_TEMP_E, VAR_RESULT
# 473 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleDomeBattleRoom_EventScript_EndSetUpObjects
# 474 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SetBrainObjectGfx
# 475 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setobjectxyperm LOCALID_DOME_OPPONENT, 13, 9
# 476 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	removeobject LOCALID_DOME_OPPONENT
# 477 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	addobject LOCALID_DOME_OPPONENT
# 478 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisibleFacingUp
# 479 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_EndSetUpObjects::
# 480 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	end
# 481 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 482 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_OnResume:
# 483 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_9, 1, BattleFrontier_BattleDomeBattleRoom_EventScript_CallAddAudience
# 484 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	end
# 485 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 486 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_CallAddAudience::
# 487 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AddAudience
# 488 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 489 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 490 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ Add audience members to supplement the permanent object event audience
# 491 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AddAudience::
# 492 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_F, DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_AddRound1Audience
# 493 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_F, DOME_ROUND2, BattleFrontier_BattleDomeBattleRoom_EventScript_AddRound2Audience
# 494 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_F, DOME_SEMIFINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AddSemifinalAudience
# 495 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_F, DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AddFinalAudience
# 496 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 497 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 498 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AddRound1Audience::
# 499 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 500 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 501 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AddRound2Audience::
# 502 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 1, 3, 0
# 503 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_EXPERT_F, 4, 6, 0
# 504 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 6, 8, 0
# 505 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 9, 11, 0
# 506 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 11, 13, 0
# 507 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_5, 13, 15, 0
# 508 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 19, 7, 1
# 509 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 22, 11, 1
# 510 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_BOY, 25, 15, 1
# 511 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 2, 2
# 512 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCHOOL_KID_M, 29, 5, 1
# 513 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 514 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 515 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AddSemifinalAudience::
# 516 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 1, 3, 0
# 517 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_EXPERT_F, 4, 6, 0
# 518 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 6, 8, 0
# 519 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_2, 7, 9, 0
# 520 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 9, 11, 0
# 521 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LASS, 10, 12, 0
# 522 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 11, 13, 0
# 523 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_5, 13, 15, 0
# 524 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 15, 2, 1
# 525 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 16, 3, 1
# 526 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_2, 17, 4, 1
# 527 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 19, 7, 1
# 528 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_EXPERT_F, 20, 9, 1
# 529 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 22, 11, 1
# 530 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 23, 13, 1
# 531 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_BOY, 25, 15, 1
# 532 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 2, 2
# 533 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_HEX_MANIAC, 28, 5, 2
# 534 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCHOOL_KID_M, 29, 5, 1
# 535 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 30, 6, 2
# 536 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 31, 8, 2
# 537 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 538 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 539 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AddFinalAudience::
# 540 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 0, 2, 0
# 541 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 1, 3, 0
# 542 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 2, 15, 0
# 543 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_5, 3, 5, 0
# 544 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_EXPERT_F, 4, 6, 0
# 545 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 5, 7, 0
# 546 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 6, 8, 0
# 547 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_2, 7, 9, 0
# 548 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_3, 8, 10, 0
# 549 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 9, 11, 0
# 550 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LASS, 10, 12, 0
# 551 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 11, 13, 0
# 552 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 12, 14, 0
# 553 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_5, 13, 15, 2
# 554 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_HIKER, 14, 12, 2
# 555 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 15, 2, 1
# 556 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 16, 3, 1
# 557 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_2, 17, 4, 1
# 558 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_3, 18, 6, 1
# 559 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 19, 7, 1
# 560 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_EXPERT_F, 20, 9, 1
# 561 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_2, 21, 10, 1
# 562 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 22, 11, 1
# 563 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 23, 13, 1
# 564 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 24, 14, 1
# 565 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_BOY, 25, 15, 1
# 566 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 2, 2
# 567 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_FAT_MAN, 27, 3, 2
# 568 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_HEX_MANIAC, 28, 5, 2
# 569 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCHOOL_KID_M, 29, 5, 1
# 570 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 30, 6, 2
# 571 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 31, 8, 2
# 572 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 573 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 574 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisible:
# 575 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	set_invisible
# 576 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 577 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 578 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_PlayerEnter:
# 579 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	set_visible
# 580 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 581 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 582 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 583 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 584 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 585 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_PlayerStepForward:
# 586 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 587 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 588 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 589 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_PlayerApproachAudience:
# 590 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 591 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 592 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 593 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ Identical to Movement_PlayerEnter
# 594 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_PlayerEnterForTucker:
# 595 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	set_visible
# 596 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 597 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 598 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 599 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 600 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 601 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 602 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 603 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 604 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_PlayerStepForward2:
# 605 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 606 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 607 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 608 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_OpponentStepForward:
# 609 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 610 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 611 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 612 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisibleFacingUp:
# 613 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 614 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	set_invisible
# 615 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 616 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 617 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_TuckerEnterAndDance:
# 618 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	set_visible
# 619 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 620 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 621 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 622 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 623 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 624 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 625 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 626 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 627 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 628 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 629 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 630 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 631 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 632 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 633 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 634 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 635 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 636 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_fast_up
# 637 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_fast_up
# 638 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 639 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 640 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 641 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 642 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 643 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 644 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 645 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 646 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 647 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 648 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 649 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 650 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 651 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_2_left
# 652 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	unlock_facing_direction
# 653 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 654 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	lock_facing_direction
# 655 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_2_left
# 656 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_2_left
# 657 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	unlock_facing_direction
# 658 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 659 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	lock_facing_direction
# 660 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_2_left
# 661 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	unlock_facing_direction
# 662 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 663 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 664 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 665 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 666 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 667 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 668 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 669 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 670 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 671 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 672 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 673 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 674 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 675 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 676 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 677 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 678 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 679 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 680 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 681 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 682 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 683 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 684 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 685 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 686 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 687 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 688 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 689 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 690 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 691 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 692 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 693 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	lock_facing_direction
# 694 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 695 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_slow_right
# 696 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 697 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_slow_right
# 698 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	unlock_facing_direction
# 699 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 700 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 701 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_in_place_up
# 702 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_in_place_up
# 703 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 704 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 705 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 706 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 707 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_in_place_up
# 708 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 709 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 710 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_down
# 711 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_down
# 712 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 713 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 714 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 715 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 716 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 717 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 718 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 719 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 720 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 721 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 722 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 723 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 724 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 725 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 726 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_AnnouncerMoveForTuckerEntrance:
# 727 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 728 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 729 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 730 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 731 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_in_place_faster_right
# 732 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 733 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 734 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 735 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 736 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 737 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 738 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 739 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 740 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 741 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 742 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 743 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 744 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 745 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 746 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 747 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 748 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 749 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 750 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 751 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 752 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 753 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 754 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 755 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 756 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 757 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 758 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 759 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 760 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 761 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 762 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 763 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 764 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 765 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 766 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 767 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 768 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 769 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 770 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 771 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 772 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 773 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_in_place_faster_down
# 774 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 775 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 776 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_TuckerStepForward:
# 777 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 778 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 779 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 780 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_TuckerApproachPlayer:
# 781 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 782 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 783 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 784 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 785 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround::
# 786 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 0, DIR_EAST
# 787 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 2, DIR_EAST
# 788 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 4, DIR_EAST
# 789 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 6, DIR_EAST
# 790 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 8, DIR_EAST
# 791 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 10, DIR_WEST
# 792 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 12, DIR_WEST
# 793 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 14, DIR_WEST
# 794 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 16, DIR_WEST
# 795 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 18, DIR_WEST
# 796 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 20, DIR_EAST
# 797 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 22, DIR_EAST
# 798 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 24, DIR_EAST
# 799 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 26, DIR_EAST
# 800 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 28, DIR_EAST
# 801 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 30, DIR_EAST
# 802 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 20
# 803 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 0, DIR_SOUTH
# 804 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 2, DIR_SOUTH
# 805 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 4, DIR_SOUTH
# 806 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 6, DIR_SOUTH
# 807 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 8, DIR_SOUTH
# 808 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 10, DIR_SOUTH
# 809 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 12, DIR_SOUTH
# 810 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 14, DIR_SOUTH
# 811 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 16, DIR_SOUTH
# 812 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 18, DIR_SOUTH
# 813 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 20, DIR_SOUTH
# 814 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 22, DIR_SOUTH
# 815 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 24, DIR_SOUTH
# 816 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 26, DIR_SOUTH
# 817 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 28, DIR_SOUTH
# 818 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 30, DIR_SOUTH
# 819 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 20
# 820 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 1, DIR_EAST
# 821 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 3, DIR_EAST
# 822 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 5, DIR_EAST
# 823 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 7, DIR_EAST
# 824 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 9, DIR_EAST
# 825 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 11, DIR_WEST
# 826 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 13, DIR_WEST
# 827 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 15, DIR_WEST
# 828 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 17, DIR_WEST
# 829 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 19, DIR_WEST
# 830 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 21, DIR_EAST
# 831 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 23, DIR_EAST
# 832 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 25, DIR_EAST
# 833 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 27, DIR_WEST
# 834 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 31, DIR_WEST
# 835 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 20
# 836 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 1, DIR_SOUTH
# 837 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 3, DIR_SOUTH
# 838 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 5, DIR_SOUTH
# 839 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 7, DIR_SOUTH
# 840 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 9, DIR_SOUTH
# 841 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 11, DIR_SOUTH
# 842 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 13, DIR_SOUTH
# 843 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 15, DIR_SOUTH
# 844 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 17, DIR_SOUTH
# 845 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 19, DIR_SOUTH
# 846 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 21, DIR_SOUTH
# 847 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 23, DIR_SOUTH
# 848 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 25, DIR_SOUTH
# 849 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 27, DIR_SOUTH
# 850 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 31, DIR_SOUTH
# 851 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 20
# 852 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 853 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 854 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobby::
# 855 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
# 856 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomePreBattleRoom_EventScript_WarpToLobbyDoubles
# 857 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_LOBBY, 5, 11
# 858 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitstate
# 859 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	end
# 860 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 861 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_WarpToLobbyDoubles::
# 862 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_LOBBY, 17, 11
# 863 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitstate
# 864 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	end
# 865 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 866 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ On round 1 there's a 50% chance that a specific audience member will walk to his seat
# 867 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_SetWalkingAudienceMemberPos::
# 868 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	random 2
# 869 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	copyvar VAR_TEMP_D, VAR_RESULT
# 870 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_TEMP_D, 0, Common_EventScript_NopReturn
# 871 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setobjectxyperm LOCALID_DOME_AUDIENCE_WALKING, 2, 0
# 872 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setobjectmovementtype LOCALID_DOME_AUDIENCE_WALKING, MOVEMENT_TYPE_FACE_RIGHT
# 873 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 874 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 875 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_TryDoAudienceMemberWalkToSeat::
# 876 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_TEMP_D, 0, Common_EventScript_NopReturn
# 877 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_AUDIENCE_WALKING, BattleFrontier_BattleDomeBattleRoom_Movement_AudienceMemberWalkToSeat
# 878 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 879 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 880 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_AudienceTwinJump:
# 881 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 882 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 883 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 884 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 885 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 886 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 887 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 888 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 889 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 890 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 891 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 892 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 893 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 894 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	disable_jump_landing_ground_effect
# 895 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_in_place_down
# 896 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 897 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_in_place_down
# 898 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	enable_jump_landing_ground_effect
# 899 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 900 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 901 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_AudienceMemberWalkToSeat:
# 902 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_down
# 903 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_down
# 904 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 905 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 906 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_in_place_faster_down
# 907 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 908 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 909 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_RefereeEnter:
# 910 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 911 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 912 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 913 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 914 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 915 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 916 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_AnnouncerFaceLeft:
# 917 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_in_place_faster_left
# 918 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 919 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 920 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_RefereeExit:
# 921 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 922 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 923 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 924 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 925 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 926 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 927 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerHasEnteredDome:
# 928 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} has entered the BATTLE DOME!$"
# 929 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 930 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerVersusTrainer:
# 931 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{STR_VAR_1}\n"
# 932 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "match!\p"
# 933 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} versus {STR_VAR_2}!\p"
# 934 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Let the battle begin!$"
# 935 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 936 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsWinner:
# 937 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} is the winner!\n"
# 938 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 939 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 940 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_TrainerIsWinner:
# 941 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{STR_VAR_2} is the winner!\n"
# 942 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 943 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 944 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLv50Champ:
# 945 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} is the Level 50\n"
# 946 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Battle Tournament Champion!\p"
# 947 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 948 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 949 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLvOpenChamp:
# 950 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} is the Open Level\n"
# 951 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Battle Tournament Champion!\p"
# 952 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 953 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 954 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_RefereeDecisionPleaseWait:
# 955 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "What an unbelievable finish!\n"
# 956 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "We have a double knockout!\p"
# 957 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "In this event, the Battle Tournament\n"
# 958 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "rules call for a REFEREE'S decision.\p"
# 959 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Please wait while the judging\n"
# 960 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "is under way.$"
# 961 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 962 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerTrainer:
# 963 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The REFEREES have reached\n"
# 964 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a decision!\p"
# 965 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is…\n"
# 966 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Oh, my goodness!\l"
# 967 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is {STR_VAR_1}!\l"
# 968 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 969 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 970 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerPlayer:
# 971 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The REFEREES have reached\n"
# 972 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a decision!\p"
# 973 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is…\n"
# 974 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Oh, my goodness!\l"
# 975 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is {PLAYER}!\l"
# 976 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 977 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 978 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_BrightNewHope:
# 979 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The bright new hope!\p"
# 980 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 981 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 982 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_RisingStar:
# 983 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The rising star!\p"
# 984 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 985 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 986 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WillTheyRaceToChampionship:
# 987 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Will this TRAINER race to\n"
# 988 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "the championship?\p"
# 989 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 990 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 991 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_CanAchieveChampionFirstTry:
# 992 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Can the feat of a championship\n"
# 993 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "on the first try be achieved?\p"
# 994 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 995 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 996 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_CanLossBeAvenged:
# 997 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Can the loss of the last match\n"
# 998 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "be avenged?\p"
# 999 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1000 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1001 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_OnFireForChampionship:
# 1002 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The TRAINER is on fire for\n"
# 1003 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "the first championship try!\p"
# 1004 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1005 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1006 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WinHereAdvancesToFinal:
# 1007 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "A win here means this TRAINER\n"
# 1008 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "advances to the final!\p"
# 1009 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1010 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1011 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WillLongHeldDreamComeTrue:
# 1012 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Will the long-held dream of\n"
# 1013 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a championship finally come true?\p"
# 1014 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1015 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1016 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_TheInvincibleChampion:
# 1017 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The invincible champion!\p"
# 1018 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1019 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1020 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_CanAnyoneHopeToBeatTrainer:
# 1021 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Can anyone hope to beat this\n"
# 1022 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TRAINER?\p"
# 1023 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1024 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1025 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_DoBattlesExistSolelyForTrainer:
# 1026 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Do battles exist solely for\n"
# 1027 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "this TRAINER?\p"
# 1028 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1029 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1030 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_CurrentChampAimingToRetainTitle:
# 1031 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The current champion aiming to\n"
# 1032 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "retain the title!\p"
# 1033 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1034 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1035 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_FormerChampHasReturned:
# 1036 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The former champion has returned!\p"
# 1037 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1038 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1039 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_FormerToughnessReturned:
# 1040 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The former toughness has returned!\p"
# 1041 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1042 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1043 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WillDoExpectedAdvanceToFinals:
# 1044 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Will this TRAINER do as expected\n"
# 1045 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "and advance to the finals?\p"
# 1046 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1047 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1048 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WillFormerChampRegainGlory:
# 1049 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Will the former champ regain\n"
# 1050 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "lost glory?\p"
# 1051 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1052 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1053 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_FeelGlowOfTrueMaster:
# 1054 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Feel the glow of a true master!$"
# 1055 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1056 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_MakeWayForDomeAceTucker:
# 1057 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "And now… The TRAINER standing in\n"
# 1058 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER}'s record-setting path…\p"
# 1059 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Yes! The one and only!\n"
# 1060 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The BATTLE DOME COMMISSIONER!\l"
# 1061 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Our very own DOME ACE!\l"
# 1062 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Make way for TUCKER!$"
# 1063 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1064 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_SpectatorTuckerChant:
# 1065 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Spectators: TUCKER! TUCKER!\n"
# 1066 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TUCKER! TUCKER! TUCKER!$"
# 1067 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1068 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_TuckerSilverIntro:
# 1069 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TUCKER: Ahahah!\p"
# 1070 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Do you hear it? This crowd!\n"
# 1071 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "They're all itching to see our match!\p"
# 1072 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Ahahah!\p"
# 1073 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I bet you're twitching all over from\n"
# 1074 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "the tension of getting to battle me!\p"
# 1075 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "But don't you worry about a thing!\p"
# 1076 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I'm the no. 1 star of the BATTLE DOME!\n"
# 1077 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I, TUCKER the DOME ACE, will bathe you\l"
# 1078 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "in my brilliant glow!$"
# 1079 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1080 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_LetsSeeYourStrategy:
# 1081 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Your strategy!\n"
# 1082 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Let's see it!$"
# 1083 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1084 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_IncredibleVictorIsPlayer:
# 1085 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Unbelievable! It's incredible!\n"
# 1086 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The victor is {PLAYER}!$"
# 1087 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1088 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WinnerIsTucker:
# 1089 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is TUCKER!\n"
# 1090 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The DOME ACE has prevailed!\p"
# 1091 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations, TUCKER!$"
# 1092 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1093 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_SeeYourFrontierPass:
# 1094 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TUCKER: Rules are rules!\n"
# 1095 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Let me see your FRONTIER PASS.$"
# 1096 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1097 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_ReceivedTacticsSymbol:
# 1098 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The Tactics Symbol was embossed on\n"
# 1099 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "the FRONTIER PASS!$"
# 1100 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1101 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WontUnderestimateYouNextTime:
# 1102 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "… … … … … …\p"
# 1103 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I sorely underestimated you. I won't\n"
# 1104 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "make the same mistake next time…$"
# 1105 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1106 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_CanWinStreakBeStretched:
# 1107 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Can the win streak be stretched?\n"
# 1108 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The confidence is there!$"
# 1109 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1110 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_LegendHasReturnedDomeAceTucker:
# 1111 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Ladies and gentlemen!\n"
# 1112 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Boys, girls, and POKéMON!\p"
# 1113 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Finally!\n"
# 1114 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Finally, the legend has returned!\p"
# 1115 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Yes, the name of that legend!\n"
# 1116 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Our very own DOME ACE!\l"
# 1117 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "It's none other than TUCKER!$"
# 1118 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1119 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_TuckerGoldIntro:
# 1120 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TUCKER: Ah…\n"
# 1121 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The pummeling roar of the crowd…\l"
# 1122 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Their furnace-like heat of excitement…\l"
# 1123 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "This is a wonderful place…\p"
# 1124 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "To the crowd, I am the DOME ACE…\n"
# 1125 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I represent their hopes and dreams…\l"
# 1126 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I must never fade from their sight…\p"
# 1127 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I must burn!\n"
# 1128 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Brighter and more brilliant!\l"
# 1129 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I must light all that gather here!$"
# 1130 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1131 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_UnleashAllPowerIPossess:
# 1132 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I will unleash all the power that\n"
# 1133 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I possess! Right here and now!$"
# 1134 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1135 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_NeverLostWhenPowerUnleashed:
# 1136 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TUCKER: You're genuinely fantastic!\p"
# 1137 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Never before! I haven't ever lost in the\n"
# 1138 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "times I've had to unleash my power.\p"
# 1139 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Yes, quite fantastic!\n"
# 1140 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Your FRONTIER PASS, please?$"
# 1141 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1142 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_TacticsSymbolTookGoldenShine:
# 1143 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The Tactics Symbol took on\n"
# 1144 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a golden shine!$"
# 1145 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1146 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_LookForwardToNextEncounter:
# 1147 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "You're strong, but above all,\n"
# 1148 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "you have a unique charm!\p"
# 1149 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "In you, I see a definite potential for\n"
# 1150 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a superstar like me.\p"
# 1151 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I will very much look forward to\n"
# 1152 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "our next encounter!$"
# 1153 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1154 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ Unused
# 1155 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLv50Champ2:
# 1156 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} is the Level 50\n"
# 1157 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Battle Tournament Champion!\p"
# 1158 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 1159 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1160 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ Unused
# 1161 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLvOpenChamp2:
# 1162 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} is the Open Level\n"
# 1163 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Battle Tournament Champion!\p"
# 1164 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 1165 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1166 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerVersusTucker:
# 1167 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The final match!\p"
# 1168 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} versus the DOME ACE, TUCKER!\p"
# 1169 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Let the battle begin!$"
# 1170 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1171 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerTucker:
# 1172 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The REFEREES have reached\n"
# 1173 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a decision!\p"
# 1174 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is…\n"
# 1175 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Oh, my goodness!\l"
# 1176 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is our very own DOME ACE!\l"
# 1177 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "It's TUCKER!\p"
# 1178 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations! And thank you!\n"
# 1179 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Let's hear it for the DOME ACE, TUCKER!$"
