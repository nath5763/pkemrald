# 1 "data/maps/Route118/scripts.pory"

# 2 "data/maps/Route118/scripts.pory"
Route118_MapScripts::
# 3 "data/maps/Route118/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route118_OnTransition
# 4 "data/maps/Route118/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route118_OnLoad
# 5 "data/maps/Route118/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route118_OnFrame
# 6 "data/maps/Route118/scripts.pory"
	.byte 0
# 7 "data/maps/Route118/scripts.pory"

# 8 "data/maps/Route118/scripts.pory"
Route118_OnTransition:
# 9 "data/maps/Route118/scripts.pory"
	call GabbyAndTy_EventScript_UpdateLocation
# 10 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
# 11 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_EAST, AbnormalWeather_StartGroudonWeather
# 12 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_WEST, AbnormalWeather_StartGroudonWeather
# 13 "data/maps/Route118/scripts.pory"
	end
# 14 "data/maps/Route118/scripts.pory"

# 15 "data/maps/Route118/scripts.pory"
Route118_OnLoad:
# 16 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_EAST, AbnormalWeather_EventScript_PlaceTilesRoute118East
# 17 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_WEST, AbnormalWeather_EventScript_PlaceTilesRoute118West
# 18 "data/maps/Route118/scripts.pory"
	end
# 19 "data/maps/Route118/scripts.pory"

# 20 "data/maps/Route118/scripts.pory"
Route118_OnFrame:
# 21 "data/maps/Route118/scripts.pory"
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
# 22 "data/maps/Route118/scripts.pory"
	.2byte 0
# 23 "data/maps/Route118/scripts.pory"

# 24 "data/maps/Route118/scripts.pory"
Route118_EventScript_GoodRodFisherman::
# 25 "data/maps/Route118/scripts.pory"
	lock
# 26 "data/maps/Route118/scripts.pory"
	faceplayer
# 27 "data/maps/Route118/scripts.pory"
	goto_if_set FLAG_RECEIVED_GOOD_ROD, Route118_EventScript_ReceivedGoodRod
# 28 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_YouAgreeGoodRodIsGood, MSGBOX_YESNO
# 29 "data/maps/Route118/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route118_EventScript_ReceiveGoodRod
# 30 "data/maps/Route118/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route118_EventScript_DeclineGoodRod
# 31 "data/maps/Route118/scripts.pory"
	end
# 32 "data/maps/Route118/scripts.pory"

# 33 "data/maps/Route118/scripts.pory"
Route118_EventScript_ReceiveGoodRod::
# 34 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_IdenticalMindsTakeThis, MSGBOX_DEFAULT
# 35 "data/maps/Route118/scripts.pory"
	giveitem ITEM_GOOD_ROD
# 36 "data/maps/Route118/scripts.pory"
	setflag FLAG_RECEIVED_GOOD_ROD
# 37 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_TryYourLuckFishing, MSGBOX_DEFAULT
# 38 "data/maps/Route118/scripts.pory"
	release
# 39 "data/maps/Route118/scripts.pory"
	end
# 40 "data/maps/Route118/scripts.pory"

# 41 "data/maps/Route118/scripts.pory"
Route118_EventScript_DeclineGoodRod::
# 42 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DontYouLikeToFish, MSGBOX_DEFAULT
# 43 "data/maps/Route118/scripts.pory"
	release
# 44 "data/maps/Route118/scripts.pory"
	end
# 45 "data/maps/Route118/scripts.pory"

# 46 "data/maps/Route118/scripts.pory"
Route118_EventScript_ReceivedGoodRod::
# 47 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_TryCatchingMonWithGoodRod, MSGBOX_DEFAULT
# 48 "data/maps/Route118/scripts.pory"
	release
# 49 "data/maps/Route118/scripts.pory"
	end
# 50 "data/maps/Route118/scripts.pory"

# 51 "data/maps/Route118/scripts.pory"
Route118_EventScript_Girl::
# 52 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_CanCrossRiversWithSurf, MSGBOX_NPC
# 53 "data/maps/Route118/scripts.pory"
	end
# 54 "data/maps/Route118/scripts.pory"

# 55 "data/maps/Route118/scripts.pory"
Route118_EventScript_RouteSignMauville::
# 56 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_RouteSignMauville, MSGBOX_SIGN
# 57 "data/maps/Route118/scripts.pory"
	end
# 58 "data/maps/Route118/scripts.pory"

# 59 "data/maps/Route118/scripts.pory"
Route118_EventScript_RouteSign119::
# 60 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_RouteSign119, MSGBOX_SIGN
# 61 "data/maps/Route118/scripts.pory"
	end
# 62 "data/maps/Route118/scripts.pory"

# 63 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenTrigger0::
# 64 "data/maps/Route118/scripts.pory"
	lockall
# 65 "data/maps/Route118/scripts.pory"
	setvar VAR_0x8008, 0
# 66 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 67 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 68 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_ROUTE118_STEVEN, Route118_Movement_StevenApproachLedge0
# 69 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 70 "data/maps/Route118/scripts.pory"
	goto Route118_EventScript_StevenTrigger
# 71 "data/maps/Route118/scripts.pory"
	end
# 72 "data/maps/Route118/scripts.pory"

# 73 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenTrigger1::
# 74 "data/maps/Route118/scripts.pory"
	lockall
# 75 "data/maps/Route118/scripts.pory"
	setvar VAR_0x8008, 1
# 76 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 77 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 78 "data/maps/Route118/scripts.pory"
	goto Route118_EventScript_StevenTrigger
# 79 "data/maps/Route118/scripts.pory"
	end
# 80 "data/maps/Route118/scripts.pory"

# 81 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenTrigger2::
# 82 "data/maps/Route118/scripts.pory"
	lockall
# 83 "data/maps/Route118/scripts.pory"
	setvar VAR_0x8008, 2
# 84 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 85 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 86 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_ROUTE118_STEVEN, Route118_Movement_StevenApproachLedge2
# 87 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 88 "data/maps/Route118/scripts.pory"
	goto Route118_EventScript_StevenTrigger
# 89 "data/maps/Route118/scripts.pory"
	end
# 90 "data/maps/Route118/scripts.pory"

# 91 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenTrigger::
# 92 "data/maps/Route118/scripts.pory"
	playse SE_LEDGE
# 93 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_ROUTE118_STEVEN, Route118_Movement_StevenJumpLedge
# 94 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 95 "data/maps/Route118/scripts.pory"
	delay 30
# 96 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_StevenQuestions, MSGBOX_DEFAULT
# 97 "data/maps/Route118/scripts.pory"
	closemessage
# 98 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_0x8008, 0, Route118_EventScript_StevenExit0
# 99 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_0x8008, 1, Route118_EventScript_StevenExit1
# 100 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_0x8008, 2, Route118_EventScript_StevenExit2
# 101 "data/maps/Route118/scripts.pory"
	setvar VAR_ROUTE118_STATE, 1
# 102 "data/maps/Route118/scripts.pory"
	removeobject LOCALID_ROUTE118_STEVEN
# 103 "data/maps/Route118/scripts.pory"
	releaseall
# 104 "data/maps/Route118/scripts.pory"
	end
# 105 "data/maps/Route118/scripts.pory"

# 106 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenExit0::
# 107 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_PLAYER, Route118_Movement_PlayerWatchStevenExit
# 108 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_ROUTE118_STEVEN, Route118_Movement_StevenExit0
# 109 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 110 "data/maps/Route118/scripts.pory"
	return
# 111 "data/maps/Route118/scripts.pory"

# 112 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenExit1::
# 113 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_PLAYER, Route118_Movement_PlayerWatchStevenExit
# 114 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_ROUTE118_STEVEN, Route118_Movement_StevenExit1
# 115 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 116 "data/maps/Route118/scripts.pory"
	return
# 117 "data/maps/Route118/scripts.pory"

# 118 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenExit2::
# 119 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_PLAYER, Route118_Movement_PlayerWatchStevenExit
# 120 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_ROUTE118_STEVEN, Route118_Movement_StevenExit2
# 121 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 122 "data/maps/Route118/scripts.pory"
	return
# 123 "data/maps/Route118/scripts.pory"

# 124 "data/maps/Route118/scripts.pory"
Route118_Movement_PlayerWatchStevenExit:
# 125 "data/maps/Route118/scripts.pory"
	delay_16
# 126 "data/maps/Route118/scripts.pory"
	walk_in_place_faster_right
# 127 "data/maps/Route118/scripts.pory"
	step_end
# 128 "data/maps/Route118/scripts.pory"

# 129 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenApproachLedge0:
# 130 "data/maps/Route118/scripts.pory"
	walk_left
# 131 "data/maps/Route118/scripts.pory"
	step_end
# 132 "data/maps/Route118/scripts.pory"

# 133 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenApproachLedge2:
# 134 "data/maps/Route118/scripts.pory"
	walk_right
# 135 "data/maps/Route118/scripts.pory"
	step_end
# 136 "data/maps/Route118/scripts.pory"

# 137 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenJumpLedge:
# 138 "data/maps/Route118/scripts.pory"
	jump_2_down
# 139 "data/maps/Route118/scripts.pory"
	delay_16
# 140 "data/maps/Route118/scripts.pory"
	walk_down
# 141 "data/maps/Route118/scripts.pory"
	step_end
# 142 "data/maps/Route118/scripts.pory"

# 143 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenExit0:
# 144 "data/maps/Route118/scripts.pory"
	walk_right
# 145 "data/maps/Route118/scripts.pory"
	walk_right
# 146 "data/maps/Route118/scripts.pory"
	walk_right
# 147 "data/maps/Route118/scripts.pory"
	walk_right
# 148 "data/maps/Route118/scripts.pory"
	walk_right
# 149 "data/maps/Route118/scripts.pory"
	walk_right
# 150 "data/maps/Route118/scripts.pory"
	walk_right
# 151 "data/maps/Route118/scripts.pory"
	walk_right
# 152 "data/maps/Route118/scripts.pory"
	walk_right
# 153 "data/maps/Route118/scripts.pory"
	walk_right
# 154 "data/maps/Route118/scripts.pory"
	step_end
# 155 "data/maps/Route118/scripts.pory"

# 156 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenExit1:
# 157 "data/maps/Route118/scripts.pory"
	walk_right
# 158 "data/maps/Route118/scripts.pory"
	walk_right
# 159 "data/maps/Route118/scripts.pory"
	walk_right
# 160 "data/maps/Route118/scripts.pory"
	walk_right
# 161 "data/maps/Route118/scripts.pory"
	walk_right
# 162 "data/maps/Route118/scripts.pory"
	walk_right
# 163 "data/maps/Route118/scripts.pory"
	walk_right
# 164 "data/maps/Route118/scripts.pory"
	walk_right
# 165 "data/maps/Route118/scripts.pory"
	walk_right
# 166 "data/maps/Route118/scripts.pory"
	step_end
# 167 "data/maps/Route118/scripts.pory"

# 168 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenExit2:
# 169 "data/maps/Route118/scripts.pory"
	walk_right
# 170 "data/maps/Route118/scripts.pory"
	walk_right
# 171 "data/maps/Route118/scripts.pory"
	walk_right
# 172 "data/maps/Route118/scripts.pory"
	walk_right
# 173 "data/maps/Route118/scripts.pory"
	walk_right
# 174 "data/maps/Route118/scripts.pory"
	walk_right
# 175 "data/maps/Route118/scripts.pory"
	walk_right
# 176 "data/maps/Route118/scripts.pory"
	walk_right
# 177 "data/maps/Route118/scripts.pory"
	step_end
# 178 "data/maps/Route118/scripts.pory"

# 179 "data/maps/Route118/scripts.pory"
Route118_EventScript_Rose::
# 180 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_ROSE_1, Route118_Text_RoseIntro, Route118_Text_RoseDefeat, Route118_EventScript_RegisterRose
# 181 "data/maps/Route118/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 182 "data/maps/Route118/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route118_EventScript_RematchRose
# 183 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_RosePostBattle, MSGBOX_DEFAULT
# 184 "data/maps/Route118/scripts.pory"
	release
# 185 "data/maps/Route118/scripts.pory"
	end
# 186 "data/maps/Route118/scripts.pory"

# 187 "data/maps/Route118/scripts.pory"
Route118_EventScript_RegisterRose::
# 188 "data/maps/Route118/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 189 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 190 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_RoseRegister, MSGBOX_DEFAULT
# 191 "data/maps/Route118/scripts.pory"
	register_matchcall TRAINER_ROSE_1
# 192 "data/maps/Route118/scripts.pory"
	release
# 193 "data/maps/Route118/scripts.pory"
	end
# 194 "data/maps/Route118/scripts.pory"

# 195 "data/maps/Route118/scripts.pory"
Route118_EventScript_RematchRose::
# 196 "data/maps/Route118/scripts.pory"
	trainerbattle_rematch TRAINER_ROSE_1, Route118_Text_RoseRematchIntro, Route118_Text_RoseRematchDefeat
# 197 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_RosePostRematch, MSGBOX_AUTOCLOSE
# 198 "data/maps/Route118/scripts.pory"
	end
# 199 "data/maps/Route118/scripts.pory"

# 200 "data/maps/Route118/scripts.pory"
Route118_EventScript_Barny::
# 201 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_BARNY, Route118_Text_BarnyIntro, Route118_Text_BarnyDefeat
# 202 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_BarnyPostBattle, MSGBOX_AUTOCLOSE
# 203 "data/maps/Route118/scripts.pory"
	end
# 204 "data/maps/Route118/scripts.pory"

# 205 "data/maps/Route118/scripts.pory"
Route118_EventScript_Wade::
# 206 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_WADE, Route118_Text_WadeIntro, Route118_Text_WadeDefeat
# 207 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_WadePostBattle, MSGBOX_AUTOCLOSE
# 208 "data/maps/Route118/scripts.pory"
	end
# 209 "data/maps/Route118/scripts.pory"

# 210 "data/maps/Route118/scripts.pory"
Route118_EventScript_Dalton::
# 211 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_DALTON_1, Route118_Text_DaltonIntro, Route118_Text_DaltonDefeat, Route118_EventScript_RegisterDalton
# 212 "data/maps/Route118/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 213 "data/maps/Route118/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route118_EventScript_RematchDalton
# 214 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DaltonPostBattle, MSGBOX_DEFAULT
# 215 "data/maps/Route118/scripts.pory"
	release
# 216 "data/maps/Route118/scripts.pory"
	end
# 217 "data/maps/Route118/scripts.pory"

# 218 "data/maps/Route118/scripts.pory"
Route118_EventScript_RegisterDalton::
# 219 "data/maps/Route118/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 220 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 221 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DaltonRegister, MSGBOX_DEFAULT
# 222 "data/maps/Route118/scripts.pory"
	register_matchcall TRAINER_DALTON_1
# 223 "data/maps/Route118/scripts.pory"
	release
# 224 "data/maps/Route118/scripts.pory"
	end
# 225 "data/maps/Route118/scripts.pory"

# 226 "data/maps/Route118/scripts.pory"
Route118_EventScript_RematchDalton::
# 227 "data/maps/Route118/scripts.pory"
	trainerbattle_rematch TRAINER_DALTON_1, Route118_Text_DaltonRematchIntro, Route118_Text_DaltonRematchDefeat
# 228 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DaltonPostRematch, MSGBOX_AUTOCLOSE
# 229 "data/maps/Route118/scripts.pory"
	end
# 230 "data/maps/Route118/scripts.pory"

# 231 "data/maps/Route118/scripts.pory"
Route118_EventScript_Perry::
# 232 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_PERRY, Route118_Text_PerryIntro, Route118_Text_PerryDefeat
# 233 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_PerryPostBattle, MSGBOX_AUTOCLOSE
# 234 "data/maps/Route118/scripts.pory"
	end
# 235 "data/maps/Route118/scripts.pory"

# 236 "data/maps/Route118/scripts.pory"
Route118_EventScript_Chester::
# 237 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_CHESTER, Route118_Text_ChesterIntro, Route118_Text_ChesterDefeat
# 238 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_ChesterPostBattle, MSGBOX_AUTOCLOSE
# 239 "data/maps/Route118/scripts.pory"
	end
# 240 "data/maps/Route118/scripts.pory"

# 241 "data/maps/Route118/scripts.pory"
Route118_EventScript_Deandre::
# 242 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_DEANDRE, Route118_Text_DeandreIntro, Route118_Text_DeandreDefeat
# 243 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DeandrePostBattle, MSGBOX_AUTOCLOSE
# 244 "data/maps/Route118/scripts.pory"
	end
# 245 "data/maps/Route118/scripts.pory"

# 246 "data/maps/Route118/scripts.pory"
Route118_Text_StevenQuestions:
# 247 "data/maps/Route118/scripts.pory"
	.string "STEVEN: Hi, {PLAYER}{KUN}!\p"
# 248 "data/maps/Route118/scripts.pory"
	.string "It's me, STEVEN!\n"
# 249 "data/maps/Route118/scripts.pory"
	.string "We met in the cave near DEWFORD.\p"
# 250 "data/maps/Route118/scripts.pory"
	.string "Have you met many kinds of POKéMON\n"
# 251 "data/maps/Route118/scripts.pory"
	.string "since I last saw you?\p"
# 252 "data/maps/Route118/scripts.pory"
	.string "There are many, many kinds of POKéMON\n"
# 253 "data/maps/Route118/scripts.pory"
	.string "in this wide world of ours.\p"
# 254 "data/maps/Route118/scripts.pory"
	.string "If you wanted to raise only your\n"
# 255 "data/maps/Route118/scripts.pory"
	.string "favorites, that's fine.\p"
# 256 "data/maps/Route118/scripts.pory"
	.string "Perhaps you find it more fun to raise\n"
# 257 "data/maps/Route118/scripts.pory"
	.string "all sorts of POKéMON.\p"
# 258 "data/maps/Route118/scripts.pory"
	.string "As a TRAINER of POKéMON,\n"
# 259 "data/maps/Route118/scripts.pory"
	.string "what do you think?\p"
# 260 "data/maps/Route118/scripts.pory"
	.string "Of course, it's not any of my business.\p"
# 261 "data/maps/Route118/scripts.pory"
	.string "It would be nice if we were to meet\n"
# 262 "data/maps/Route118/scripts.pory"
	.string "again somewhere.$"
# 263 "data/maps/Route118/scripts.pory"

# 264 "data/maps/Route118/scripts.pory"
Route118_Text_YouAgreeGoodRodIsGood:
# 265 "data/maps/Route118/scripts.pory"
	.string "Hmm!\n"
# 266 "data/maps/Route118/scripts.pory"
	.string "A GOOD ROD is really good!\p"
# 267 "data/maps/Route118/scripts.pory"
	.string "Wouldn't you agree?$"
# 268 "data/maps/Route118/scripts.pory"

# 269 "data/maps/Route118/scripts.pory"
Route118_Text_IdenticalMindsTakeThis:
# 270 "data/maps/Route118/scripts.pory"
	.string "Hmm!\n"
# 271 "data/maps/Route118/scripts.pory"
	.string "We're of identical minds!\p"
# 272 "data/maps/Route118/scripts.pory"
	.string "Hmm!\n"
# 273 "data/maps/Route118/scripts.pory"
	.string "Take this GOOD ROD!$"
# 274 "data/maps/Route118/scripts.pory"

# 275 "data/maps/Route118/scripts.pory"
Route118_Text_TryYourLuckFishing:
# 276 "data/maps/Route118/scripts.pory"
	.string "Wherever there's water, try your luck\n"
# 277 "data/maps/Route118/scripts.pory"
	.string "at fishing.$"
# 278 "data/maps/Route118/scripts.pory"

# 279 "data/maps/Route118/scripts.pory"
Route118_Text_DontYouLikeToFish:
# 280 "data/maps/Route118/scripts.pory"
	.string "Don't you like to fish?$"
# 281 "data/maps/Route118/scripts.pory"

# 282 "data/maps/Route118/scripts.pory"
Route118_Text_TryCatchingMonWithGoodRod:
# 283 "data/maps/Route118/scripts.pory"
	.string "Try catching all sorts of POKéMON\n"
# 284 "data/maps/Route118/scripts.pory"
	.string "with your GOOD ROD.$"
# 285 "data/maps/Route118/scripts.pory"

# 286 "data/maps/Route118/scripts.pory"
Route118_Text_CanCrossRiversWithSurf:
# 287 "data/maps/Route118/scripts.pory"
	.string "Even if there isn't a boat, you can\n"
# 288 "data/maps/Route118/scripts.pory"
	.string "cross rivers and the sea if you have\l"
# 289 "data/maps/Route118/scripts.pory"
	.string "a POKéMON that knows SURF.\p"
# 290 "data/maps/Route118/scripts.pory"
	.string "POKéMON can be counted on to do so\n"
# 291 "data/maps/Route118/scripts.pory"
	.string "much!$"
# 292 "data/maps/Route118/scripts.pory"

# 293 "data/maps/Route118/scripts.pory"
Route118_Text_RouteSignMauville:
# 294 "data/maps/Route118/scripts.pory"
	.string "ROUTE 118\n"
# 295 "data/maps/Route118/scripts.pory"
	.string "{LEFT_ARROW} MAUVILLE CITY$"
# 296 "data/maps/Route118/scripts.pory"

# 297 "data/maps/Route118/scripts.pory"
Route118_Text_RouteSign119:
# 298 "data/maps/Route118/scripts.pory"
	.string "ROUTE 118\n"
# 299 "data/maps/Route118/scripts.pory"
	.string "{UP_ARROW} ROUTE 119$"
