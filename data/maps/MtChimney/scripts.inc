# 1 "data/maps/MtChimney/scripts.pory"

# 2 "data/maps/MtChimney/scripts.pory"
MtChimney_MapScripts::
# 3 "data/maps/MtChimney/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
# 4 "data/maps/MtChimney/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
# 5 "data/maps/MtChimney/scripts.pory"
	.byte 0
# 6 "data/maps/MtChimney/scripts.pory"

# 7 "data/maps/MtChimney/scripts.pory"
MtChimney_OnTransition:
# 8 "data/maps/MtChimney/scripts.pory"
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
# 9 "data/maps/MtChimney/scripts.pory"
	end
# 10 "data/maps/MtChimney/scripts.pory"

# 11 "data/maps/MtChimney/scripts.pory"
MtChimney_OnResume:
# 12 "data/maps/MtChimney/scripts.pory"
	setstepcallback STEP_CB_ASH
# 13 "data/maps/MtChimney/scripts.pory"
	end
# 14 "data/maps/MtChimney/scripts.pory"

# 15 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Archie::
# 16 "data/maps/MtChimney/scripts.pory"
	lock
# 17 "data/maps/MtChimney/scripts.pory"
	faceplayer
# 18 "data/maps/MtChimney/scripts.pory"
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
# 19 "data/maps/MtChimney/scripts.pory"
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
# 20 "data/maps/MtChimney/scripts.pory"
	closemessage
# 21 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, Common_Movement_FaceOriginalDirection
# 22 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 23 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
# 24 "data/maps/MtChimney/scripts.pory"
	release
# 25 "data/maps/MtChimney/scripts.pory"
	end
# 26 "data/maps/MtChimney/scripts.pory"

# 27 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieGoStopTeamMagma::
# 28 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
# 29 "data/maps/MtChimney/scripts.pory"
	return
# 30 "data/maps/MtChimney/scripts.pory"

# 31 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieBusyFighting::
# 32 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
# 33 "data/maps/MtChimney/scripts.pory"
	return
# 34 "data/maps/MtChimney/scripts.pory"

# 35 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Maxie::
# 36 "data/maps/MtChimney/scripts.pory"
	lockall
# 37 "data/maps/MtChimney/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 38 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
# 39 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_FacePlayer
# 40 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 41 "data/maps/MtChimney/scripts.pory"
	playse SE_PIN
# 42 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_ExclamationMark
# 43 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 44 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_Delay48
# 45 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 46 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
# 47 "data/maps/MtChimney/scripts.pory"
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
# 48 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
# 49 "data/maps/MtChimney/scripts.pory"
	closemessage
# 50 "data/maps/MtChimney/scripts.pory"
	delay 30
# 51 "data/maps/MtChimney/scripts.pory"
	fadescreen FADE_TO_BLACK
# 52 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MT_CHIMNEY_MAXIE
# 53 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_1
# 54 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MT_CHIMNEY_TABITHA
# 55 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_2
# 56 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
# 57 "data/maps/MtChimney/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 58 "data/maps/MtChimney/scripts.pory"
	setobjectxyperm LOCALID_MT_CHIMNEY_ARCHIE, 10, 12
# 59 "data/maps/MtChimney/scripts.pory"
	addobject LOCALID_MT_CHIMNEY_ARCHIE
# 60 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
# 61 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
# 62 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 63 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 64 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
# 65 "data/maps/MtChimney/scripts.pory"
	closemessage
# 66 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
# 67 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
# 68 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MT_CHIMNEY_ARCHIE
# 69 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
# 70 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
# 71 "data/maps/MtChimney/scripts.pory"
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
# 72 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
# 73 "data/maps/MtChimney/scripts.pory"
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
# 74 "data/maps/MtChimney/scripts.pory"
	releaseall
# 75 "data/maps/MtChimney/scripts.pory"
	end
# 76 "data/maps/MtChimney/scripts.pory"

# 77 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieApproachPlayerEast::
# 78 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
# 79 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 80 "data/maps/MtChimney/scripts.pory"
	return
# 81 "data/maps/MtChimney/scripts.pory"

# 82 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieApproachPlayerNorth::
# 83 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
# 84 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 85 "data/maps/MtChimney/scripts.pory"
	return
# 86 "data/maps/MtChimney/scripts.pory"

# 87 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieExitEast::
# 88 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitEast
# 89 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 90 "data/maps/MtChimney/scripts.pory"
	return
# 91 "data/maps/MtChimney/scripts.pory"

# 92 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieExitNorth::
# 93 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitNorth
# 94 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 95 "data/maps/MtChimney/scripts.pory"
	return
# 96 "data/maps/MtChimney/scripts.pory"

# 97 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_LavaCookieLady::
# 98 "data/maps/MtChimney/scripts.pory"
	lock
# 99 "data/maps/MtChimney/scripts.pory"
	faceplayer
# 100 "data/maps/MtChimney/scripts.pory"
	showmoneybox 0, 0
# 101 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
# 102 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
# 103 "data/maps/MtChimney/scripts.pory"
	checkmoney 200
# 104 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
# 105 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
# 106 "data/maps/MtChimney/scripts.pory"
	checkitemspace ITEM_LAVA_COOKIE
# 107 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
# 108 "data/maps/MtChimney/scripts.pory"
	giveitem ITEM_LAVA_COOKIE
# 109 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
# 110 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 111 "data/maps/MtChimney/scripts.pory"
	release
# 112 "data/maps/MtChimney/scripts.pory"
	end
# 113 "data/maps/MtChimney/scripts.pory"

# 114 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BagIsFull::
# 115 "data/maps/MtChimney/scripts.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 116 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 117 "data/maps/MtChimney/scripts.pory"
	release
# 118 "data/maps/MtChimney/scripts.pory"
	end
# 119 "data/maps/MtChimney/scripts.pory"

# 120 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_RemoveMoney::
# 121 "data/maps/MtChimney/scripts.pory"
	removemoney 200
# 122 "data/maps/MtChimney/scripts.pory"
	updatemoneybox
# 123 "data/maps/MtChimney/scripts.pory"
	return
# 124 "data/maps/MtChimney/scripts.pory"

# 125 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_DeclineLavaCookie::
# 126 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
# 127 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 128 "data/maps/MtChimney/scripts.pory"
	release
# 129 "data/maps/MtChimney/scripts.pory"
	end
# 130 "data/maps/MtChimney/scripts.pory"

# 131 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_NotEnoughMoney::
# 132 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
# 133 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 134 "data/maps/MtChimney/scripts.pory"
	release
# 135 "data/maps/MtChimney/scripts.pory"
	end
# 136 "data/maps/MtChimney/scripts.pory"

# 137 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieApproachPlayerEast:
# 138 "data/maps/MtChimney/scripts.pory"
	walk_up
# 139 "data/maps/MtChimney/scripts.pory"
	walk_up
# 140 "data/maps/MtChimney/scripts.pory"
	walk_up
# 141 "data/maps/MtChimney/scripts.pory"
	walk_up
# 142 "data/maps/MtChimney/scripts.pory"
	walk_up
# 143 "data/maps/MtChimney/scripts.pory"
	walk_up
# 144 "data/maps/MtChimney/scripts.pory"
	walk_right
# 145 "data/maps/MtChimney/scripts.pory"
	step_end
# 146 "data/maps/MtChimney/scripts.pory"

# 147 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieExitEast:
# 148 "data/maps/MtChimney/scripts.pory"
	walk_left
# 149 "data/maps/MtChimney/scripts.pory"
	walk_down
# 150 "data/maps/MtChimney/scripts.pory"
	walk_down
# 151 "data/maps/MtChimney/scripts.pory"
	walk_down
# 152 "data/maps/MtChimney/scripts.pory"
	walk_down
# 153 "data/maps/MtChimney/scripts.pory"
	walk_down
# 154 "data/maps/MtChimney/scripts.pory"
	walk_down
# 155 "data/maps/MtChimney/scripts.pory"
	walk_down
# 156 "data/maps/MtChimney/scripts.pory"
	step_end
# 157 "data/maps/MtChimney/scripts.pory"

# 158 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieApproachPlayerNorth:
# 159 "data/maps/MtChimney/scripts.pory"
	walk_up
# 160 "data/maps/MtChimney/scripts.pory"
	walk_up
# 161 "data/maps/MtChimney/scripts.pory"
	walk_up
# 162 "data/maps/MtChimney/scripts.pory"
	walk_up
# 163 "data/maps/MtChimney/scripts.pory"
	walk_up
# 164 "data/maps/MtChimney/scripts.pory"
	walk_right
# 165 "data/maps/MtChimney/scripts.pory"
	walk_right
# 166 "data/maps/MtChimney/scripts.pory"
	step_end
# 167 "data/maps/MtChimney/scripts.pory"

# 168 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieExitNorth:
# 169 "data/maps/MtChimney/scripts.pory"
	walk_left
# 170 "data/maps/MtChimney/scripts.pory"
	walk_left
# 171 "data/maps/MtChimney/scripts.pory"
	walk_down
# 172 "data/maps/MtChimney/scripts.pory"
	walk_down
# 173 "data/maps/MtChimney/scripts.pory"
	walk_down
# 174 "data/maps/MtChimney/scripts.pory"
	walk_down
# 175 "data/maps/MtChimney/scripts.pory"
	walk_down
# 176 "data/maps/MtChimney/scripts.pory"
	walk_down
# 177 "data/maps/MtChimney/scripts.pory"
	walk_down
# 178 "data/maps/MtChimney/scripts.pory"
	step_end
# 179 "data/maps/MtChimney/scripts.pory"

# 180 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused1:
# 181 "data/maps/MtChimney/scripts.pory"
	walk_down
# 182 "data/maps/MtChimney/scripts.pory"
	walk_down
# 183 "data/maps/MtChimney/scripts.pory"
	walk_down
# 184 "data/maps/MtChimney/scripts.pory"
	walk_down
# 185 "data/maps/MtChimney/scripts.pory"
	walk_down
# 186 "data/maps/MtChimney/scripts.pory"
	walk_left
# 187 "data/maps/MtChimney/scripts.pory"
	walk_left
# 188 "data/maps/MtChimney/scripts.pory"
	walk_down
# 189 "data/maps/MtChimney/scripts.pory"
	walk_down
# 190 "data/maps/MtChimney/scripts.pory"
	walk_down
# 191 "data/maps/MtChimney/scripts.pory"
	walk_down
# 192 "data/maps/MtChimney/scripts.pory"
	walk_left
# 193 "data/maps/MtChimney/scripts.pory"
	walk_left
# 194 "data/maps/MtChimney/scripts.pory"
	walk_left
# 195 "data/maps/MtChimney/scripts.pory"
	walk_left
# 196 "data/maps/MtChimney/scripts.pory"
	walk_left
# 197 "data/maps/MtChimney/scripts.pory"
	walk_down
# 198 "data/maps/MtChimney/scripts.pory"
	step_end
# 199 "data/maps/MtChimney/scripts.pory"

# 200 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused2:
# 201 "data/maps/MtChimney/scripts.pory"
	walk_down
# 202 "data/maps/MtChimney/scripts.pory"
	walk_down
# 203 "data/maps/MtChimney/scripts.pory"
	walk_down
# 204 "data/maps/MtChimney/scripts.pory"
	walk_down
# 205 "data/maps/MtChimney/scripts.pory"
	walk_left
# 206 "data/maps/MtChimney/scripts.pory"
	walk_left
# 207 "data/maps/MtChimney/scripts.pory"
	walk_left
# 208 "data/maps/MtChimney/scripts.pory"
	walk_down
# 209 "data/maps/MtChimney/scripts.pory"
	step_end
# 210 "data/maps/MtChimney/scripts.pory"

# 211 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused3:
# 212 "data/maps/MtChimney/scripts.pory"
	walk_right
# 213 "data/maps/MtChimney/scripts.pory"
	walk_down
# 214 "data/maps/MtChimney/scripts.pory"
	walk_down
# 215 "data/maps/MtChimney/scripts.pory"
	walk_down
# 216 "data/maps/MtChimney/scripts.pory"
	walk_down
# 217 "data/maps/MtChimney/scripts.pory"
	walk_left
# 218 "data/maps/MtChimney/scripts.pory"
	walk_left
# 219 "data/maps/MtChimney/scripts.pory"
	walk_left
# 220 "data/maps/MtChimney/scripts.pory"
	walk_left
# 221 "data/maps/MtChimney/scripts.pory"
	walk_left
# 222 "data/maps/MtChimney/scripts.pory"
	walk_down
# 223 "data/maps/MtChimney/scripts.pory"
	walk_down
# 224 "data/maps/MtChimney/scripts.pory"
	walk_down
# 225 "data/maps/MtChimney/scripts.pory"
	walk_down
# 226 "data/maps/MtChimney/scripts.pory"
	step_end
# 227 "data/maps/MtChimney/scripts.pory"

# 228 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused4:
# 229 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 230 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 231 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 232 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 233 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 234 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 235 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 236 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 237 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 238 "data/maps/MtChimney/scripts.pory"
	walk_left
# 239 "data/maps/MtChimney/scripts.pory"
	walk_left
# 240 "data/maps/MtChimney/scripts.pory"
	walk_down
# 241 "data/maps/MtChimney/scripts.pory"
	walk_down
# 242 "data/maps/MtChimney/scripts.pory"
	walk_down
# 243 "data/maps/MtChimney/scripts.pory"
	walk_left
# 244 "data/maps/MtChimney/scripts.pory"
	walk_left
# 245 "data/maps/MtChimney/scripts.pory"
	walk_down
# 246 "data/maps/MtChimney/scripts.pory"
	walk_down
# 247 "data/maps/MtChimney/scripts.pory"
	walk_left
# 248 "data/maps/MtChimney/scripts.pory"
	walk_left
# 249 "data/maps/MtChimney/scripts.pory"
	walk_left
# 250 "data/maps/MtChimney/scripts.pory"
	walk_left
# 251 "data/maps/MtChimney/scripts.pory"
	walk_left
# 252 "data/maps/MtChimney/scripts.pory"
	walk_down
# 253 "data/maps/MtChimney/scripts.pory"
	step_end
# 254 "data/maps/MtChimney/scripts.pory"

# 255 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused5:
# 256 "data/maps/MtChimney/scripts.pory"
	delay_16
# 257 "data/maps/MtChimney/scripts.pory"
	delay_16
# 258 "data/maps/MtChimney/scripts.pory"
	delay_16
# 259 "data/maps/MtChimney/scripts.pory"
	walk_down
# 260 "data/maps/MtChimney/scripts.pory"
	walk_down
# 261 "data/maps/MtChimney/scripts.pory"
	walk_down
# 262 "data/maps/MtChimney/scripts.pory"
	walk_left
# 263 "data/maps/MtChimney/scripts.pory"
	walk_left
# 264 "data/maps/MtChimney/scripts.pory"
	walk_left
# 265 "data/maps/MtChimney/scripts.pory"
	walk_down
# 266 "data/maps/MtChimney/scripts.pory"
	step_end
# 267 "data/maps/MtChimney/scripts.pory"

# 268 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused6:
# 269 "data/maps/MtChimney/scripts.pory"
	delay_16
# 270 "data/maps/MtChimney/scripts.pory"
	walk_left
# 271 "data/maps/MtChimney/scripts.pory"
	walk_down
# 272 "data/maps/MtChimney/scripts.pory"
	walk_down
# 273 "data/maps/MtChimney/scripts.pory"
	walk_down
# 274 "data/maps/MtChimney/scripts.pory"
	walk_down
# 275 "data/maps/MtChimney/scripts.pory"
	walk_left
# 276 "data/maps/MtChimney/scripts.pory"
	walk_left
# 277 "data/maps/MtChimney/scripts.pory"
	walk_left
# 278 "data/maps/MtChimney/scripts.pory"
	walk_left
# 279 "data/maps/MtChimney/scripts.pory"
	walk_left
# 280 "data/maps/MtChimney/scripts.pory"
	walk_down
# 281 "data/maps/MtChimney/scripts.pory"
	walk_down
# 282 "data/maps/MtChimney/scripts.pory"
	walk_down
# 283 "data/maps/MtChimney/scripts.pory"
	walk_down
# 284 "data/maps/MtChimney/scripts.pory"
	step_end
# 285 "data/maps/MtChimney/scripts.pory"

# 286 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused7:
# 287 "data/maps/MtChimney/scripts.pory"
	delay_16
# 288 "data/maps/MtChimney/scripts.pory"
	walk_left
# 289 "data/maps/MtChimney/scripts.pory"
	walk_left
# 290 "data/maps/MtChimney/scripts.pory"
	walk_down
# 291 "data/maps/MtChimney/scripts.pory"
	walk_down
# 292 "data/maps/MtChimney/scripts.pory"
	walk_down
# 293 "data/maps/MtChimney/scripts.pory"
	walk_left
# 294 "data/maps/MtChimney/scripts.pory"
	walk_left
# 295 "data/maps/MtChimney/scripts.pory"
	walk_down
# 296 "data/maps/MtChimney/scripts.pory"
	walk_down
# 297 "data/maps/MtChimney/scripts.pory"
	walk_left
# 298 "data/maps/MtChimney/scripts.pory"
	walk_left
# 299 "data/maps/MtChimney/scripts.pory"
	walk_left
# 300 "data/maps/MtChimney/scripts.pory"
	walk_left
# 301 "data/maps/MtChimney/scripts.pory"
	walk_left
# 302 "data/maps/MtChimney/scripts.pory"
	walk_down
# 303 "data/maps/MtChimney/scripts.pory"
	step_end
# 304 "data/maps/MtChimney/scripts.pory"

# 305 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused8:
# 306 "data/maps/MtChimney/scripts.pory"
	delay_16
# 307 "data/maps/MtChimney/scripts.pory"
	walk_down
# 308 "data/maps/MtChimney/scripts.pory"
	walk_left
# 309 "data/maps/MtChimney/scripts.pory"
	walk_left
# 310 "data/maps/MtChimney/scripts.pory"
	walk_left
# 311 "data/maps/MtChimney/scripts.pory"
	walk_left
# 312 "data/maps/MtChimney/scripts.pory"
	walk_in_place_faster_down
# 313 "data/maps/MtChimney/scripts.pory"
	step_end
# 314 "data/maps/MtChimney/scripts.pory"

# 315 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused9:
# 316 "data/maps/MtChimney/scripts.pory"
	walk_down
# 317 "data/maps/MtChimney/scripts.pory"
	walk_down
# 318 "data/maps/MtChimney/scripts.pory"
	walk_down
# 319 "data/maps/MtChimney/scripts.pory"
	walk_down
# 320 "data/maps/MtChimney/scripts.pory"
	walk_left
# 321 "data/maps/MtChimney/scripts.pory"
	walk_left
# 322 "data/maps/MtChimney/scripts.pory"
	walk_left
# 323 "data/maps/MtChimney/scripts.pory"
	walk_left
# 324 "data/maps/MtChimney/scripts.pory"
	walk_left
# 325 "data/maps/MtChimney/scripts.pory"
	walk_down
# 326 "data/maps/MtChimney/scripts.pory"
	walk_down
# 327 "data/maps/MtChimney/scripts.pory"
	walk_down
# 328 "data/maps/MtChimney/scripts.pory"
	walk_down
# 329 "data/maps/MtChimney/scripts.pory"
	step_end
# 330 "data/maps/MtChimney/scripts.pory"

# 331 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused10:
# 332 "data/maps/MtChimney/scripts.pory"
	walk_down
# 333 "data/maps/MtChimney/scripts.pory"
	step_end
# 334 "data/maps/MtChimney/scripts.pory"

# 335 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused11:
# 336 "data/maps/MtChimney/scripts.pory"
	walk_down
# 337 "data/maps/MtChimney/scripts.pory"
	walk_down
# 338 "data/maps/MtChimney/scripts.pory"
	walk_down
# 339 "data/maps/MtChimney/scripts.pory"
	walk_down
# 340 "data/maps/MtChimney/scripts.pory"
	walk_down
# 341 "data/maps/MtChimney/scripts.pory"
	walk_down
# 342 "data/maps/MtChimney/scripts.pory"
	walk_down
# 343 "data/maps/MtChimney/scripts.pory"
	step_end
# 344 "data/maps/MtChimney/scripts.pory"

# 345 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused12:
# 346 "data/maps/MtChimney/scripts.pory"
	delay_16
# 347 "data/maps/MtChimney/scripts.pory"
	delay_16
# 348 "data/maps/MtChimney/scripts.pory"
	walk_in_place_faster_left
# 349 "data/maps/MtChimney/scripts.pory"
	delay_16
# 350 "data/maps/MtChimney/scripts.pory"
	walk_down
# 351 "data/maps/MtChimney/scripts.pory"
	walk_down
# 352 "data/maps/MtChimney/scripts.pory"
	walk_down
# 353 "data/maps/MtChimney/scripts.pory"
	walk_down
# 354 "data/maps/MtChimney/scripts.pory"
	walk_down
# 355 "data/maps/MtChimney/scripts.pory"
	step_end
# 356 "data/maps/MtChimney/scripts.pory"

# 357 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused13:
# 358 "data/maps/MtChimney/scripts.pory"
	delay_16
# 359 "data/maps/MtChimney/scripts.pory"
	delay_16
# 360 "data/maps/MtChimney/scripts.pory"
	delay_16
# 361 "data/maps/MtChimney/scripts.pory"
	delay_16
# 362 "data/maps/MtChimney/scripts.pory"
	delay_16
# 363 "data/maps/MtChimney/scripts.pory"
	delay_16
# 364 "data/maps/MtChimney/scripts.pory"
	walk_in_place_faster_left
# 365 "data/maps/MtChimney/scripts.pory"
	delay_16
# 366 "data/maps/MtChimney/scripts.pory"
	walk_down
# 367 "data/maps/MtChimney/scripts.pory"
	walk_down
# 368 "data/maps/MtChimney/scripts.pory"
	step_end
# 369 "data/maps/MtChimney/scripts.pory"

# 370 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused14:
# 371 "data/maps/MtChimney/scripts.pory"
	lock_facing_direction
# 372 "data/maps/MtChimney/scripts.pory"
	walk_fast_left
# 373 "data/maps/MtChimney/scripts.pory"
	unlock_facing_direction
# 374 "data/maps/MtChimney/scripts.pory"
	face_right
# 375 "data/maps/MtChimney/scripts.pory"
	step_end
# 376 "data/maps/MtChimney/scripts.pory"

# 377 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused15:
# 378 "data/maps/MtChimney/scripts.pory"
	walk_left
# 379 "data/maps/MtChimney/scripts.pory"
	walk_in_place_faster_right
# 380 "data/maps/MtChimney/scripts.pory"
	delay_16
# 381 "data/maps/MtChimney/scripts.pory"
	step_end
# 382 "data/maps/MtChimney/scripts.pory"

# 383 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt1::
# 384 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
# 385 "data/maps/MtChimney/scripts.pory"
	end
# 386 "data/maps/MtChimney/scripts.pory"

# 387 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt2::
# 388 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
# 389 "data/maps/MtChimney/scripts.pory"
	end
# 390 "data/maps/MtChimney/scripts.pory"

# 391 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt3::
# 392 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
# 393 "data/maps/MtChimney/scripts.pory"
	end
# 394 "data/maps/MtChimney/scripts.pory"

# 395 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Tabitha::
# 396 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
# 397 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
# 398 "data/maps/MtChimney/scripts.pory"
	end
# 399 "data/maps/MtChimney/scripts.pory"

# 400 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Grunt2::
# 401 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
# 402 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 403 "data/maps/MtChimney/scripts.pory"
	end
# 404 "data/maps/MtChimney/scripts.pory"

# 405 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt1::
# 406 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
# 407 "data/maps/MtChimney/scripts.pory"
	end
# 408 "data/maps/MtChimney/scripts.pory"

# 409 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt2::
# 410 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
# 411 "data/maps/MtChimney/scripts.pory"
	end
# 412 "data/maps/MtChimney/scripts.pory"

# 413 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt3::
# 414 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
# 415 "data/maps/MtChimney/scripts.pory"
	end
# 416 "data/maps/MtChimney/scripts.pory"

# 417 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt4::
# 418 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
# 419 "data/maps/MtChimney/scripts.pory"
	end
# 420 "data/maps/MtChimney/scripts.pory"

# 421 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt5::
# 422 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
# 423 "data/maps/MtChimney/scripts.pory"
	end
# 424 "data/maps/MtChimney/scripts.pory"

# 425 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt6::
# 426 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
# 427 "data/maps/MtChimney/scripts.pory"
	end
# 428 "data/maps/MtChimney/scripts.pory"

# 429 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_MagmaPoochyena::
# 430 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
# 431 "data/maps/MtChimney/scripts.pory"
	end
# 432 "data/maps/MtChimney/scripts.pory"

# 433 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_AquaPoochyena::
# 434 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
# 435 "data/maps/MtChimney/scripts.pory"
	end
# 436 "data/maps/MtChimney/scripts.pory"

# 437 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_MeteoriteMachine::
# 438 "data/maps/MtChimney/scripts.pory"
	lockall
# 439 "data/maps/MtChimney/scripts.pory"
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
# 440 "data/maps/MtChimney/scripts.pory"
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
# 441 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
# 442 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
# 443 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
# 444 "data/maps/MtChimney/scripts.pory"
	giveitem ITEM_METEORITE
# 445 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_RECEIVED_METEORITE
# 446 "data/maps/MtChimney/scripts.pory"
	releaseall
# 447 "data/maps/MtChimney/scripts.pory"
	end
# 448 "data/maps/MtChimney/scripts.pory"

# 449 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_LeaveMeteoriteAlone::
# 450 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
# 451 "data/maps/MtChimney/scripts.pory"
	releaseall
# 452 "data/maps/MtChimney/scripts.pory"
	end
# 453 "data/maps/MtChimney/scripts.pory"

# 454 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_MachineOff::
# 455 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
# 456 "data/maps/MtChimney/scripts.pory"
	releaseall
# 457 "data/maps/MtChimney/scripts.pory"
	end
# 458 "data/maps/MtChimney/scripts.pory"

# 459 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_MachineOn::
# 460 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MetoriteFittedOnMachine, MSGBOX_DEFAULT
# 461 "data/maps/MtChimney/scripts.pory"
	releaseall
# 462 "data/maps/MtChimney/scripts.pory"
	end
# 463 "data/maps/MtChimney/scripts.pory"

# 464 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_RouteSign::
# 465 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
# 466 "data/maps/MtChimney/scripts.pory"
	end
# 467 "data/maps/MtChimney/scripts.pory"

# 468 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Shelby::
# 469 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
# 470 "data/maps/MtChimney/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 471 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
# 472 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
# 473 "data/maps/MtChimney/scripts.pory"
	release
# 474 "data/maps/MtChimney/scripts.pory"
	end
# 475 "data/maps/MtChimney/scripts.pory"

# 476 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_DefeatedShelby::
# 477 "data/maps/MtChimney/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 478 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 479 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
# 480 "data/maps/MtChimney/scripts.pory"
	register_matchcall TRAINER_SHELBY_1
# 481 "data/maps/MtChimney/scripts.pory"
	release
# 482 "data/maps/MtChimney/scripts.pory"
	end
# 483 "data/maps/MtChimney/scripts.pory"

# 484 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_RematchShelby::
# 485 "data/maps/MtChimney/scripts.pory"
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
# 486 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
# 487 "data/maps/MtChimney/scripts.pory"
	end
# 488 "data/maps/MtChimney/scripts.pory"

# 489 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Melissa::
# 490 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
# 491 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
# 492 "data/maps/MtChimney/scripts.pory"
	end
# 493 "data/maps/MtChimney/scripts.pory"

# 494 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Sheila::
# 495 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
# 496 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
# 497 "data/maps/MtChimney/scripts.pory"
	end
# 498 "data/maps/MtChimney/scripts.pory"

# 499 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Shirley::
# 500 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
# 501 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
# 502 "data/maps/MtChimney/scripts.pory"
	end
# 503 "data/maps/MtChimney/scripts.pory"

# 504 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Grunt1::
# 505 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
# 506 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 507 "data/maps/MtChimney/scripts.pory"
	end
# 508 "data/maps/MtChimney/scripts.pory"

# 509 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Sawyer::
# 510 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
# 511 "data/maps/MtChimney/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 512 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
# 513 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
# 514 "data/maps/MtChimney/scripts.pory"
	release
# 515 "data/maps/MtChimney/scripts.pory"
	end
# 516 "data/maps/MtChimney/scripts.pory"

# 517 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_SawyerDefeated::
# 518 "data/maps/MtChimney/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 519 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 520 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
# 521 "data/maps/MtChimney/scripts.pory"
	register_matchcall TRAINER_SAWYER_1
# 522 "data/maps/MtChimney/scripts.pory"
	release
# 523 "data/maps/MtChimney/scripts.pory"
	end
# 524 "data/maps/MtChimney/scripts.pory"

# 525 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_SawyerRematch::
# 526 "data/maps/MtChimney/scripts.pory"
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
# 527 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
# 528 "data/maps/MtChimney/scripts.pory"
	end
# 529 "data/maps/MtChimney/scripts.pory"

# 530 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MeteoriteWillActivateVolcano:
# 531 "data/maps/MtChimney/scripts.pory"
	.string "The power contained in the METEORITE…\p"
# 532 "data/maps/MtChimney/scripts.pory"
	.string "By amplifying its power with this\n"
# 533 "data/maps/MtChimney/scripts.pory"
	.string "machine, MT. CHIMNEY's volcanic\l"
# 534 "data/maps/MtChimney/scripts.pory"
	.string "activity will instantly intensify…\p"
# 535 "data/maps/MtChimney/scripts.pory"
	.string "Its energy will grow deep inside\n"
# 536 "data/maps/MtChimney/scripts.pory"
	.string "the crater and…\l"
# 537 "data/maps/MtChimney/scripts.pory"
	.string "Fufufu…$"
# 538 "data/maps/MtChimney/scripts.pory"

# 539 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieIntro:
# 540 "data/maps/MtChimney/scripts.pory"
	.string "MAXIE: Hm?\n"
# 541 "data/maps/MtChimney/scripts.pory"
	.string "Who are you?\p"
# 542 "data/maps/MtChimney/scripts.pory"
	.string "… … … … … …\n"
# 543 "data/maps/MtChimney/scripts.pory"
	.string "… … … … … …\p"
# 544 "data/maps/MtChimney/scripts.pory"
	.string "I'd heard ARCHIE bemoaning a child\n"
# 545 "data/maps/MtChimney/scripts.pory"
	.string "who's been meddling in TEAM AQUA's\l"
# 546 "data/maps/MtChimney/scripts.pory"
	.string "affairs.\p"
# 547 "data/maps/MtChimney/scripts.pory"
	.string "It must be you he meant.\p"
# 548 "data/maps/MtChimney/scripts.pory"
	.string "Humph! So you're thinking of\n"
# 549 "data/maps/MtChimney/scripts.pory"
	.string "interfering with us, TEAM MAGMA?\p"
# 550 "data/maps/MtChimney/scripts.pory"
	.string "Now you listen.\n"
# 551 "data/maps/MtChimney/scripts.pory"
	.string "Long ago, living things used the\l"
# 552 "data/maps/MtChimney/scripts.pory"
	.string "land to live and grow.\p"
# 553 "data/maps/MtChimney/scripts.pory"
	.string "That is why land is all important!\n"
# 554 "data/maps/MtChimney/scripts.pory"
	.string "It is the cradle of all!\p"
# 555 "data/maps/MtChimney/scripts.pory"
	.string "That is why TEAM MAGMA is dedicated\n"
# 556 "data/maps/MtChimney/scripts.pory"
	.string "to the expansion of the land mass.\p"
# 557 "data/maps/MtChimney/scripts.pory"
	.string "It is for further advancement of\n"
# 558 "data/maps/MtChimney/scripts.pory"
	.string "humankind and POKéMON!\p"
# 559 "data/maps/MtChimney/scripts.pory"
	.string "And for that, we need the power of\n"
# 560 "data/maps/MtChimney/scripts.pory"
	.string "what sleeps within this mountain…\p"
# 561 "data/maps/MtChimney/scripts.pory"
	.string "Oh! There was no need for you to\n"
# 562 "data/maps/MtChimney/scripts.pory"
	.string "learn that much.\p"
# 563 "data/maps/MtChimney/scripts.pory"
	.string "But, no matter!\n"
# 564 "data/maps/MtChimney/scripts.pory"
	.string "I'll teach you the consequences of\l"
# 565 "data/maps/MtChimney/scripts.pory"
	.string "meddling in our grand design!$"
# 566 "data/maps/MtChimney/scripts.pory"

# 567 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieDefeat:
# 568 "data/maps/MtChimney/scripts.pory"
	.string "What?!\p"
# 569 "data/maps/MtChimney/scripts.pory"
	.string "I, MAXIE, was caught off guard?!$"
# 570 "data/maps/MtChimney/scripts.pory"

# 571 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
# 572 "data/maps/MtChimney/scripts.pory"
	.string "MAXIE: But, enough.\n"
# 573 "data/maps/MtChimney/scripts.pory"
	.string "I will back off this time.\p"
# 574 "data/maps/MtChimney/scripts.pory"
	.string "But don't think that this is the last\n"
# 575 "data/maps/MtChimney/scripts.pory"
	.string "you've seen of TEAM MAGMA.\p"
# 576 "data/maps/MtChimney/scripts.pory"
	.string "Fufufu…\p"
# 577 "data/maps/MtChimney/scripts.pory"
	.string "Even without the METEORITE, if we\n"
# 578 "data/maps/MtChimney/scripts.pory"
	.string "obtain that ORB… Fufufu…$"
# 579 "data/maps/MtChimney/scripts.pory"

# 580 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaIntro:
# 581 "data/maps/MtChimney/scripts.pory"
	.string "Hehehe!\p"
# 582 "data/maps/MtChimney/scripts.pory"
	.string "So you've come all the way here!\p"
# 583 "data/maps/MtChimney/scripts.pory"
	.string "But you're too late!\n"
# 584 "data/maps/MtChimney/scripts.pory"
	.string "I've already delivered the METEORITE\l"
# 585 "data/maps/MtChimney/scripts.pory"
	.string "from METEOR FALLS to the BOSS!$"
# 586 "data/maps/MtChimney/scripts.pory"

# 587 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaDefeat:
# 588 "data/maps/MtChimney/scripts.pory"
	.string "Hehehe…\p"
# 589 "data/maps/MtChimney/scripts.pory"
	.string "Even though I've lost, if our leader\n"
# 590 "data/maps/MtChimney/scripts.pory"
	.string "awakens that thing…$"
# 591 "data/maps/MtChimney/scripts.pory"

# 592 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaPostBattle:
# 593 "data/maps/MtChimney/scripts.pory"
	.string "BOSS, hurry!\n"
# 594 "data/maps/MtChimney/scripts.pory"
	.string "Give it the METEORITE's energy!\p"
# 595 "data/maps/MtChimney/scripts.pory"
	.string "Hehehe…$"
# 596 "data/maps/MtChimney/scripts.pory"

# 597 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2Intro:
# 598 "data/maps/MtChimney/scripts.pory"
	.string "We of TEAM MAGMA are working hard for\n"
# 599 "data/maps/MtChimney/scripts.pory"
	.string "everyone's sake.\p"
# 600 "data/maps/MtChimney/scripts.pory"
	.string "Like, if that thing's power made more\n"
# 601 "data/maps/MtChimney/scripts.pory"
	.string "land, there'd be more places to live.\p"
# 602 "data/maps/MtChimney/scripts.pory"
	.string "Everyone'd be happy!$"
# 603 "data/maps/MtChimney/scripts.pory"

# 604 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2Defeat:
# 605 "data/maps/MtChimney/scripts.pory"
	.string "Hunh?\n"
# 606 "data/maps/MtChimney/scripts.pory"
	.string "What do you mean I lost?$"
# 607 "data/maps/MtChimney/scripts.pory"

# 608 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2PostBattle:
# 609 "data/maps/MtChimney/scripts.pory"
	.string "Our BOSS says, “It will make everyone\n"
# 610 "data/maps/MtChimney/scripts.pory"
	.string "happy.”\p"
# 611 "data/maps/MtChimney/scripts.pory"
	.string "But why does everyone keep getting\n"
# 612 "data/maps/MtChimney/scripts.pory"
	.string "in our way?$"
# 613 "data/maps/MtChimney/scripts.pory"

# 614 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1Intro:
# 615 "data/maps/MtChimney/scripts.pory"
	.string "If there were more land, I'd be able\n"
# 616 "data/maps/MtChimney/scripts.pory"
	.string "to get a big house of my own!\p"
# 617 "data/maps/MtChimney/scripts.pory"
	.string "I'm going to build it on hardened lava!$"
# 618 "data/maps/MtChimney/scripts.pory"

# 619 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1Defeat:
# 620 "data/maps/MtChimney/scripts.pory"
	.string "My dream of a big house…$"
# 621 "data/maps/MtChimney/scripts.pory"

# 622 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1PostBattle:
# 623 "data/maps/MtChimney/scripts.pory"
	.string "A kid like you, you ought to be\n"
# 624 "data/maps/MtChimney/scripts.pory"
	.string "splashing about in the waves!$"
# 625 "data/maps/MtChimney/scripts.pory"

# 626 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
# 627 "data/maps/MtChimney/scripts.pory"
	.string "That annoying TEAM AQUA…\n"
# 628 "data/maps/MtChimney/scripts.pory"
	.string "They always mess with our plans!$"
# 629 "data/maps/MtChimney/scripts.pory"

# 630 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MeteoritesPackAmazingPower:
# 631 "data/maps/MtChimney/scripts.pory"
	.string "METEORITES pack amazing power!$"
# 632 "data/maps/MtChimney/scripts.pory"

# 633 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_YouBetterNotMessWithUs:
# 634 "data/maps/MtChimney/scripts.pory"
	.string "You'd better not mess with us!\p"
# 635 "data/maps/MtChimney/scripts.pory"
	.string "We're trying to awaken that thing\n"
# 636 "data/maps/MtChimney/scripts.pory"
	.string "for the benefit of everyone!$"
# 637 "data/maps/MtChimney/scripts.pory"

# 638 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_AquasNameSimilar:
# 639 "data/maps/MtChimney/scripts.pory"
	.string "We're TEAM MAGMA!\p"
# 640 "data/maps/MtChimney/scripts.pory"
	.string "They're TEAM AQUA!\p"
# 641 "data/maps/MtChimney/scripts.pory"
	.string "It totally annoys me that they'd\n"
# 642 "data/maps/MtChimney/scripts.pory"
	.string "use a name like ours!$"
# 643 "data/maps/MtChimney/scripts.pory"

# 644 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_DouseThemInFire:
# 645 "data/maps/MtChimney/scripts.pory"
	.string "Yeah!\n"
# 646 "data/maps/MtChimney/scripts.pory"
	.string "Douse them in fire!$"
# 647 "data/maps/MtChimney/scripts.pory"

# 648 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_KeepMakingMoreLand:
# 649 "data/maps/MtChimney/scripts.pory"
	.string "We're going to keep making more land!$"
# 650 "data/maps/MtChimney/scripts.pory"

# 651 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Bufoh:
# 652 "data/maps/MtChimney/scripts.pory"
	.string "Bufoh!$"
# 653 "data/maps/MtChimney/scripts.pory"

# 654 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieGoStopTeamMagma:
# 655 "data/maps/MtChimney/scripts.pory"
	.string "ARCHIE: Grr, {PLAYER}!\n"
# 656 "data/maps/MtChimney/scripts.pory"
	.string "I should've guessed you'd show up!\p"
# 657 "data/maps/MtChimney/scripts.pory"
	.string "See for yourself what the fanatics\n"
# 658 "data/maps/MtChimney/scripts.pory"
	.string "of TEAM MAGMA are up to!\p"
# 659 "data/maps/MtChimney/scripts.pory"
	.string "They're trying to inject the stolen\n"
# 660 "data/maps/MtChimney/scripts.pory"
	.string "METEORITE's power into the volcano!\p"
# 661 "data/maps/MtChimney/scripts.pory"
	.string "Doing something like that will cause\n"
# 662 "data/maps/MtChimney/scripts.pory"
	.string "the volcano's eruption!$"
# 663 "data/maps/MtChimney/scripts.pory"

# 664 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieIHaveMyHandsFull:
# 665 "data/maps/MtChimney/scripts.pory"
	.string "ARCHIE: Grrr…\p"
# 666 "data/maps/MtChimney/scripts.pory"
	.string "I want to stop that MAXIE,\n"
# 667 "data/maps/MtChimney/scripts.pory"
	.string "but I can't!\p"
# 668 "data/maps/MtChimney/scripts.pory"
	.string "Not when I have my hands full battling\n"
# 669 "data/maps/MtChimney/scripts.pory"
	.string "three opponents at once!$"
# 670 "data/maps/MtChimney/scripts.pory"

# 671 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieThankYou:
# 672 "data/maps/MtChimney/scripts.pory"
	.string "ARCHIE: {PLAYER}!\n"
# 673 "data/maps/MtChimney/scripts.pory"
	.string "Thank you!\p"
# 674 "data/maps/MtChimney/scripts.pory"
	.string "With your help, we thwarted TEAM\n"
# 675 "data/maps/MtChimney/scripts.pory"
	.string "MAGMA's destructive plan!\p"
# 676 "data/maps/MtChimney/scripts.pory"
	.string "But… You…\n"
# 677 "data/maps/MtChimney/scripts.pory"
	.string "Whose side are you on?\p"
# 678 "data/maps/MtChimney/scripts.pory"
	.string "Ah, it doesn't matter.\p"
# 679 "data/maps/MtChimney/scripts.pory"
	.string "We will remain vigilant and keep up\n"
# 680 "data/maps/MtChimney/scripts.pory"
	.string "our pursuit of TEAM MAGMA.\p"
# 681 "data/maps/MtChimney/scripts.pory"
	.string "{PLAYER}, we shall meet again!$"
# 682 "data/maps/MtChimney/scripts.pory"

# 683 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MagmaOutnumbersUs:
# 684 "data/maps/MtChimney/scripts.pory"
	.string "Darn… TEAM MAGMA outnumbers us!\n"
# 685 "data/maps/MtChimney/scripts.pory"
	.string "We can't keep up with them!$"
# 686 "data/maps/MtChimney/scripts.pory"

# 687 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_LessHabitatForWaterPokemon:
# 688 "data/maps/MtChimney/scripts.pory"
	.string "If they expand the land, there'll be\n"
# 689 "data/maps/MtChimney/scripts.pory"
	.string "less habitats for WATER POKéMON!$"
# 690 "data/maps/MtChimney/scripts.pory"

# 691 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MagmasNameSimilar:
# 692 "data/maps/MtChimney/scripts.pory"
	.string "We're TEAM AQUA!\p"
# 693 "data/maps/MtChimney/scripts.pory"
	.string "They're TEAM MAGMA!\p"
# 694 "data/maps/MtChimney/scripts.pory"
	.string "It burns me up that they'd use such\n"
# 695 "data/maps/MtChimney/scripts.pory"
	.string "a confusing name!$"
# 696 "data/maps/MtChimney/scripts.pory"

# 697 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Bushaa:
# 698 "data/maps/MtChimney/scripts.pory"
	.string "Bushaa!$"
# 699 "data/maps/MtChimney/scripts.pory"

# 700 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_LavaCookiesJust200:
# 701 "data/maps/MtChimney/scripts.pory"
	.string "LAVA COOKIES are MT. CHIMNEY's local\n"
# 702 "data/maps/MtChimney/scripts.pory"
	.string "specialty.\p"
# 703 "data/maps/MtChimney/scripts.pory"
	.string "Try one. It's just ¥200.$"
# 704 "data/maps/MtChimney/scripts.pory"

# 705 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ThankYouDear:
# 706 "data/maps/MtChimney/scripts.pory"
	.string "Thank you, dear!$"
# 707 "data/maps/MtChimney/scripts.pory"

# 708 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_YouveNotGotTheMoney:
# 709 "data/maps/MtChimney/scripts.pory"
	.string "Oh, dear. You can't buy a thing if\n"
# 710 "data/maps/MtChimney/scripts.pory"
	.string "you've not got the money.$"
# 711 "data/maps/MtChimney/scripts.pory"

# 712 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_OhFineThen:
# 713 "data/maps/MtChimney/scripts.pory"
	.string "Oh, fine then.$"
# 714 "data/maps/MtChimney/scripts.pory"

# 715 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MetoriteFittedOnMachine:
# 716 "data/maps/MtChimney/scripts.pory"
	.string "A METEORITE is fitted on a mysterious\n"
# 717 "data/maps/MtChimney/scripts.pory"
	.string "machine…\p"
# 718 "data/maps/MtChimney/scripts.pory"
	.string "The machine seems to be storing\n"
# 719 "data/maps/MtChimney/scripts.pory"
	.string "energy in the METEORITE.$"
# 720 "data/maps/MtChimney/scripts.pory"

# 721 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_RemoveTheMeteorite:
# 722 "data/maps/MtChimney/scripts.pory"
	.string "A METEORITE is fitted on a mysterious\n"
# 723 "data/maps/MtChimney/scripts.pory"
	.string "machine…\p"
# 724 "data/maps/MtChimney/scripts.pory"
	.string "Do you want to remove the METEORITE?$"
# 725 "data/maps/MtChimney/scripts.pory"

# 726 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_PlayerRemovedMeteorite:
# 727 "data/maps/MtChimney/scripts.pory"
	.string "{PLAYER} removed the METEORITE from\n"
# 728 "data/maps/MtChimney/scripts.pory"
	.string "the mysterious machine.$"
# 729 "data/maps/MtChimney/scripts.pory"

# 730 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_PlayerLeftMeteorite:
# 731 "data/maps/MtChimney/scripts.pory"
	.string "{PLAYER} left the METEORITE where\n"
# 732 "data/maps/MtChimney/scripts.pory"
	.string "it was.$"
# 733 "data/maps/MtChimney/scripts.pory"

# 734 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MachineMakesNoResponse:
# 735 "data/maps/MtChimney/scripts.pory"
	.string "This mysterious machine…\n"
# 736 "data/maps/MtChimney/scripts.pory"
	.string "It makes no response whatsoever.$"
# 737 "data/maps/MtChimney/scripts.pory"

# 738 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_RouteSign:
# 739 "data/maps/MtChimney/scripts.pory"
	.string "{DOWN_ARROW} JAGGED PATH\n"
# 740 "data/maps/MtChimney/scripts.pory"
	.string "LAVARIDGE TOWN AHEAD$"
# 741 "data/maps/MtChimney/scripts.pory"

# 742 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyIntro:
# 743 "data/maps/MtChimney/scripts.pory"
	.string "I've been to the hot springs and\n"
# 744 "data/maps/MtChimney/scripts.pory"
	.string "refreshed my tired bones.\l"
# 745 "data/maps/MtChimney/scripts.pory"
	.string "Right now I'm feeling strong!$"
# 746 "data/maps/MtChimney/scripts.pory"

# 747 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyDefeat:
# 748 "data/maps/MtChimney/scripts.pory"
	.string "Oh, my goodness.\n"
# 749 "data/maps/MtChimney/scripts.pory"
	.string "Now, aren't you something!$"
# 750 "data/maps/MtChimney/scripts.pory"

# 751 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyPostBattle:
# 752 "data/maps/MtChimney/scripts.pory"
	.string "Well, well, I've lost. I can't call\n"
# 753 "data/maps/MtChimney/scripts.pory"
	.string "myself an EXPERT now, can I?$"
# 754 "data/maps/MtChimney/scripts.pory"

# 755 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRegister:
# 756 "data/maps/MtChimney/scripts.pory"
	.string "Thank you, child. It was fun, as if\n"
# 757 "data/maps/MtChimney/scripts.pory"
	.string "I were battling my own grandchild.\p"
# 758 "data/maps/MtChimney/scripts.pory"
	.string "Please, come see me again for\n"
# 759 "data/maps/MtChimney/scripts.pory"
	.string "a rematch.$"
# 760 "data/maps/MtChimney/scripts.pory"

# 761 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRematchIntro:
# 762 "data/maps/MtChimney/scripts.pory"
	.string "If you can mesh your heart with those\n"
# 763 "data/maps/MtChimney/scripts.pory"
	.string "of your POKéMON, why, you should be\l"
# 764 "data/maps/MtChimney/scripts.pory"
	.string "able to achieve great things.$"
# 765 "data/maps/MtChimney/scripts.pory"

# 766 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRematchDefeat:
# 767 "data/maps/MtChimney/scripts.pory"
	.string "Oh, my goodness.\n"
# 768 "data/maps/MtChimney/scripts.pory"
	.string "Now, aren't you something!$"
# 769 "data/maps/MtChimney/scripts.pory"

# 770 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyPostRematch:
# 771 "data/maps/MtChimney/scripts.pory"
	.string "Perhaps your heart has become one\n"
# 772 "data/maps/MtChimney/scripts.pory"
	.string "with the hearts of your POKéMON.$"
# 773 "data/maps/MtChimney/scripts.pory"

# 774 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaIntro:
# 775 "data/maps/MtChimney/scripts.pory"
	.string "I've got the fire in me, baby.\n"
# 776 "data/maps/MtChimney/scripts.pory"
	.string "I can't stand it! I have to battle!$"
# 777 "data/maps/MtChimney/scripts.pory"

# 778 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaDefeat:
# 779 "data/maps/MtChimney/scripts.pory"
	.string "Ooh, that was a scorching-hot match!$"
# 780 "data/maps/MtChimney/scripts.pory"

# 781 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaPostBattle:
# 782 "data/maps/MtChimney/scripts.pory"
	.string "The heat of MT. CHIMNEY warms\n"
# 783 "data/maps/MtChimney/scripts.pory"
	.string "me up, baby!$"
# 784 "data/maps/MtChimney/scripts.pory"

# 785 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaIntro:
# 786 "data/maps/MtChimney/scripts.pory"
	.string "I've finally made it to MT. CHIMNEY.\n"
# 787 "data/maps/MtChimney/scripts.pory"
	.string "I want to make my POKéMON battle!$"
# 788 "data/maps/MtChimney/scripts.pory"

# 789 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaDefeat:
# 790 "data/maps/MtChimney/scripts.pory"
	.string "The way you battle…\n"
# 791 "data/maps/MtChimney/scripts.pory"
	.string "It's like a MT. CHIMNEY eruption!$"
# 792 "data/maps/MtChimney/scripts.pory"

# 793 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaPostBattle:
# 794 "data/maps/MtChimney/scripts.pory"
	.string "Like I said, I've finally made it to\n"
# 795 "data/maps/MtChimney/scripts.pory"
	.string "MT. CHIMNEY. It would be a shame if\l"
# 796 "data/maps/MtChimney/scripts.pory"
	.string "I only do a little sightseeing…\p"
# 797 "data/maps/MtChimney/scripts.pory"
	.string "I want to get in some battles and buy\n"
# 798 "data/maps/MtChimney/scripts.pory"
	.string "COOKIES as souvenirs.$"
# 799 "data/maps/MtChimney/scripts.pory"

# 800 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyIntro:
# 801 "data/maps/MtChimney/scripts.pory"
	.string "Since I bathed in the hot springs,\n"
# 802 "data/maps/MtChimney/scripts.pory"
	.string "I've been feeling great!\l"
# 803 "data/maps/MtChimney/scripts.pory"
	.string "I'm sure I'm going to win!$"
# 804 "data/maps/MtChimney/scripts.pory"

# 805 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyDefeat:
# 806 "data/maps/MtChimney/scripts.pory"
	.string "Yowch!\n"
# 807 "data/maps/MtChimney/scripts.pory"
	.string "I'm getting a chill out of the water.$"
# 808 "data/maps/MtChimney/scripts.pory"

# 809 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyPostBattle:
# 810 "data/maps/MtChimney/scripts.pory"
	.string "I'll have to take another dip in the\n"
# 811 "data/maps/MtChimney/scripts.pory"
	.string "hot springs. Want to join me?\p"
# 812 "data/maps/MtChimney/scripts.pory"
	.string "Just joking!$"
# 813 "data/maps/MtChimney/scripts.pory"

# 814 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerIntro:
# 815 "data/maps/MtChimney/scripts.pory"
	.string "This is one fine mountain! Plenty of\n"
# 816 "data/maps/MtChimney/scripts.pory"
	.string "hot people around for company!$"
# 817 "data/maps/MtChimney/scripts.pory"

# 818 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerDefeat:
# 819 "data/maps/MtChimney/scripts.pory"
	.string "Oh, you're a real firebrand, too!$"
# 820 "data/maps/MtChimney/scripts.pory"

# 821 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerPostBattle:
# 822 "data/maps/MtChimney/scripts.pory"
	.string "I think I need a dip in LAVARIDGE\n"
# 823 "data/maps/MtChimney/scripts.pory"
	.string "HOT SPRING with the locals!$"
# 824 "data/maps/MtChimney/scripts.pory"

# 825 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRegister:
# 826 "data/maps/MtChimney/scripts.pory"
	.string "I like little fireballs like you.\n"
# 827 "data/maps/MtChimney/scripts.pory"
	.string "Let me register you in my POKéNAV.$"
# 828 "data/maps/MtChimney/scripts.pory"

# 829 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRematchIntro:
# 830 "data/maps/MtChimney/scripts.pory"
	.string "I'm happily surrounded by hot people\n"
# 831 "data/maps/MtChimney/scripts.pory"
	.string "around these parts. I won't lose!$"
# 832 "data/maps/MtChimney/scripts.pory"

# 833 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRematchDefeat:
# 834 "data/maps/MtChimney/scripts.pory"
	.string "Gosh, you're still the same\n"
# 835 "data/maps/MtChimney/scripts.pory"
	.string "firebrand as before!$"
# 836 "data/maps/MtChimney/scripts.pory"

# 837 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerPostRematch:
# 838 "data/maps/MtChimney/scripts.pory"
	.string "Actually, it really is hot here.\n"
# 839 "data/maps/MtChimney/scripts.pory"
	.string "I'm overdressed for these parts.$"
