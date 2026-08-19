# 1 "data/maps/LavaridgeTown/scripts.pory"

# 2 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_MapScripts::
# 3 "data/maps/LavaridgeTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
# 4 "data/maps/LavaridgeTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
# 5 "data/maps/LavaridgeTown/scripts.pory"
	.byte 0
# 6 "data/maps/LavaridgeTown/scripts.pory"

# 7 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_OnTransition:
# 8 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_VISITED_LAVARIDGE_TOWN
# 9 "data/maps/LavaridgeTown/scripts.pory"
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
# 10 "data/maps/LavaridgeTown/scripts.pory"
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
# 11 "data/maps/LavaridgeTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 12 "data/maps/LavaridgeTown/scripts.pory"
	call Common_EventScript_SetupRivalOnBikeGfxId
# 13 "data/maps/LavaridgeTown/scripts.pory"
	call_if_unset FLAG_RECEIVED_GO_GOGGLES, LavaridgeTown_EventScript_StartRivalScene
# 14 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_CheckSetRivalPos
# 15 "data/maps/LavaridgeTown/scripts.pory"
	end
# 16 "data/maps/LavaridgeTown/scripts.pory"

# 17 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
# 18 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
# 19 "data/maps/LavaridgeTown/scripts.pory"
	return
# 20 "data/maps/LavaridgeTown/scripts.pory"

# 21 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_CheckSetRivalPos::
# 22 "data/maps/LavaridgeTown/scripts.pory"
	goto LavaridgeTown_EventScript_SetRivalPos
# 23 "data/maps/LavaridgeTown/scripts.pory"

# 24 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_SetRivalPos::
# 25 "data/maps/LavaridgeTown/scripts.pory"
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL, 5, 17
# 26 "data/maps/LavaridgeTown/scripts.pory"
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL_ON_BIKE, 5, 17
# 27 "data/maps/LavaridgeTown/scripts.pory"
	setobjectmovementtype LOCALID_LAVARIDGE_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
# 28 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
# 29 "data/maps/LavaridgeTown/scripts.pory"
	return
# 30 "data/maps/LavaridgeTown/scripts.pory"

# 31 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ShowMtChimneyTrainers::
# 32 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
# 33 "data/maps/LavaridgeTown/scripts.pory"
	return
# 34 "data/maps/LavaridgeTown/scripts.pory"

# 35 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_StartRivalScene::
# 36 "data/maps/LavaridgeTown/scripts.pory"
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
# 37 "data/maps/LavaridgeTown/scripts.pory"
	return
# 38 "data/maps/LavaridgeTown/scripts.pory"

# 39 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HideMapNamePopup::
# 40 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 41 "data/maps/LavaridgeTown/scripts.pory"
	return
# 42 "data/maps/LavaridgeTown/scripts.pory"

# 43 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_OnFrame:
# 44 "data/maps/LavaridgeTown/scripts.pory"
	.2byte 0
# 45 "data/maps/LavaridgeTown/scripts.pory"

# 46 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalGiveGoGoggles::
# 47 "data/maps/LavaridgeTown/scripts.pory"
	lockall
# 48 "data/maps/LavaridgeTown/scripts.pory"
	faceplayer
# 49 "data/maps/LavaridgeTown/scripts.pory"
	checkplayergender
# 50 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_PlayMayMusic
# 51 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_PlayBrendanMusic
# 52 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_MayGiveGoGoggles
# 53 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
# 54 "data/maps/LavaridgeTown/scripts.pory"
	end
# 55 "data/maps/LavaridgeTown/scripts.pory"

# 56 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_MayGiveGoGoggles::
# 57 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
# 58 "data/maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_GO_GOGGLES
# 59 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_GO_GOGGLES
# 60 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
# 61 "data/maps/LavaridgeTown/scripts.pory"
	goto LavaridgeTown_EventScript_RivalExit
# 62 "data/maps/LavaridgeTown/scripts.pory"
	end
# 63 "data/maps/LavaridgeTown/scripts.pory"

# 64 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_BrendanGiveGoGoggles::
# 65 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
# 66 "data/maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_GO_GOGGLES
# 67 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_GO_GOGGLES
# 68 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
# 69 "data/maps/LavaridgeTown/scripts.pory"
	goto LavaridgeTown_EventScript_RivalExit
# 70 "data/maps/LavaridgeTown/scripts.pory"
	end
# 71 "data/maps/LavaridgeTown/scripts.pory"

# 72 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExit::
# 73 "data/maps/LavaridgeTown/scripts.pory"
	closemessage
# 74 "data/maps/LavaridgeTown/scripts.pory"
	removeobject LOCALID_LAVARIDGE_RIVAL
# 75 "data/maps/LavaridgeTown/scripts.pory"
	addobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
# 76 "data/maps/LavaridgeTown/scripts.pory"
	delay 30
# 77 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
# 78 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 79 "data/maps/LavaridgeTown/scripts.pory"
	removeobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
# 80 "data/maps/LavaridgeTown/scripts.pory"
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
# 81 "data/maps/LavaridgeTown/scripts.pory"
	savebgm MUS_DUMMY
# 82 "data/maps/LavaridgeTown/scripts.pory"
	fadedefaultbgm
# 83 "data/maps/LavaridgeTown/scripts.pory"
	releaseall
# 84 "data/maps/LavaridgeTown/scripts.pory"
	end
# 85 "data/maps/LavaridgeTown/scripts.pory"

# 86 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_PlayMayMusic::
# 87 "data/maps/LavaridgeTown/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 88 "data/maps/LavaridgeTown/scripts.pory"
	return
# 89 "data/maps/LavaridgeTown/scripts.pory"

# 90 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_PlayBrendanMusic::
# 91 "data/maps/LavaridgeTown/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 92 "data/maps/LavaridgeTown/scripts.pory"
	return
# 93 "data/maps/LavaridgeTown/scripts.pory"

# 94 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalExit2:
# 95 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 96 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 97 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 98 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 99 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 100 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 101 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 102 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 103 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 104 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 105 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 106 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 107 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 108 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 109 "data/maps/LavaridgeTown/scripts.pory"

# 110 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsTrigger::
# 111 "data/maps/LavaridgeTown/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 112 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
# 113 "data/maps/LavaridgeTown/scripts.pory"
	end
# 114 "data/maps/LavaridgeTown/scripts.pory"

# 115 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_EnteredHotSprings::
# 116 "data/maps/LavaridgeTown/scripts.pory"
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
# 117 "data/maps/LavaridgeTown/scripts.pory"
	end
# 118 "data/maps/LavaridgeTown/scripts.pory"

# 119 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ExpertM::
# 120 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
# 121 "data/maps/LavaridgeTown/scripts.pory"
	end
# 122 "data/maps/LavaridgeTown/scripts.pory"

# 123 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_OldMan::
# 124 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
# 125 "data/maps/LavaridgeTown/scripts.pory"
	end
# 126 "data/maps/LavaridgeTown/scripts.pory"

# 127 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_Twin::
# 128 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
# 129 "data/maps/LavaridgeTown/scripts.pory"
	end
# 130 "data/maps/LavaridgeTown/scripts.pory"

# 131 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsOldWoman1::
# 132 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
# 133 "data/maps/LavaridgeTown/scripts.pory"
	end
# 134 "data/maps/LavaridgeTown/scripts.pory"

# 135 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsOldWoman2::
# 136 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
# 137 "data/maps/LavaridgeTown/scripts.pory"
	end
# 138 "data/maps/LavaridgeTown/scripts.pory"

# 139 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ExpertF::
# 140 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
# 141 "data/maps/LavaridgeTown/scripts.pory"
	end
# 142 "data/maps/LavaridgeTown/scripts.pory"

# 143 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_EggWoman::
# 144 "data/maps/LavaridgeTown/scripts.pory"
	lock
# 145 "data/maps/LavaridgeTown/scripts.pory"
	faceplayer
# 146 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
# 147 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
# 148 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
# 149 "data/maps/LavaridgeTown/scripts.pory"
	getpartysize
# 150 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
# 151 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
# 152 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
# 153 "data/maps/LavaridgeTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 154 "data/maps/LavaridgeTown/scripts.pory"
	message LavaridgeTown_Text_ReceivedTheEgg
# 155 "data/maps/LavaridgeTown/scripts.pory"
	waitfanfare
# 156 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_WYNAUT
# 157 "data/maps/LavaridgeTown/scripts.pory"
	release
# 158 "data/maps/LavaridgeTown/scripts.pory"
	end
# 159 "data/maps/LavaridgeTown/scripts.pory"

# 160 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ReceivedEgg::
# 161 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
# 162 "data/maps/LavaridgeTown/scripts.pory"
	release
# 163 "data/maps/LavaridgeTown/scripts.pory"
	end
# 164 "data/maps/LavaridgeTown/scripts.pory"

# 165 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_NoRoomForEgg::
# 166 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
# 167 "data/maps/LavaridgeTown/scripts.pory"
	release
# 168 "data/maps/LavaridgeTown/scripts.pory"
	end
# 169 "data/maps/LavaridgeTown/scripts.pory"

# 170 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_DeclineEgg::
# 171 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
# 172 "data/maps/LavaridgeTown/scripts.pory"
	release
# 173 "data/maps/LavaridgeTown/scripts.pory"
	end
# 174 "data/maps/LavaridgeTown/scripts.pory"

# 175 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_TownSign::
# 176 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
# 177 "data/maps/LavaridgeTown/scripts.pory"
	end
# 178 "data/maps/LavaridgeTown/scripts.pory"

# 179 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_GymSign::
# 180 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
# 181 "data/maps/LavaridgeTown/scripts.pory"
	end
# 182 "data/maps/LavaridgeTown/scripts.pory"

# 183 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HerbShopSign::
# 184 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
# 185 "data/maps/LavaridgeTown/scripts.pory"
	end
# 186 "data/maps/LavaridgeTown/scripts.pory"

# 187 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_MayNiceBadgesTakeThis:
# 188 "data/maps/LavaridgeTown/scripts.pory"
	.string "MAY: {PLAYER}{KUN}! Long time no see!\p"
# 189 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh? While I visited the hot springs,\n"
# 190 "data/maps/LavaridgeTown/scripts.pory"
	.string "you got the LAVARIDGE GYM BADGE.\p"
# 191 "data/maps/LavaridgeTown/scripts.pory"
	.string "You must have collected\n"
# 192 "data/maps/LavaridgeTown/scripts.pory"
	.string "good POKéMON…\l"
# 193 "data/maps/LavaridgeTown/scripts.pory"
	.string "No, I believe you raised some.\p"
# 194 "data/maps/LavaridgeTown/scripts.pory"
	.string "I guess it would be okay for you to\n"
# 195 "data/maps/LavaridgeTown/scripts.pory"
	.string "have this.$"
# 196 "data/maps/LavaridgeTown/scripts.pory"

# 197 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
# 198 "data/maps/LavaridgeTown/scripts.pory"
	.string "MAY: With those GO-GOGGLES, you'll\n"
# 199 "data/maps/LavaridgeTown/scripts.pory"
	.string "have no trouble getting through the\l"
# 200 "data/maps/LavaridgeTown/scripts.pory"
	.string "desert near ROUTE 111.\p"
# 201 "data/maps/LavaridgeTown/scripts.pory"
	.string "But, wow, {PLAYER}{KUN}…\n"
# 202 "data/maps/LavaridgeTown/scripts.pory"
	.string "Challenging GYMS…\p"
# 203 "data/maps/LavaridgeTown/scripts.pory"
	.string "You're trying hard because you don't\n"
# 204 "data/maps/LavaridgeTown/scripts.pory"
	.string "want to lose to me, I bet!\p"
# 205 "data/maps/LavaridgeTown/scripts.pory"
	.string "{PLAYER}{KUN}, I think I should challenge\n"
# 206 "data/maps/LavaridgeTown/scripts.pory"
	.string "your dad in PETALBURG GYM.\p"
# 207 "data/maps/LavaridgeTown/scripts.pory"
	.string "See you again!$"
# 208 "data/maps/LavaridgeTown/scripts.pory"

# 209 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
# 210 "data/maps/LavaridgeTown/scripts.pory"
	.string "BRENDAN: {PLAYER}, hey, it's been a while.\n"
# 211 "data/maps/LavaridgeTown/scripts.pory"
	.string "How's it going?\p"
# 212 "data/maps/LavaridgeTown/scripts.pory"
	.string "Hmm…\n"
# 213 "data/maps/LavaridgeTown/scripts.pory"
	.string "That's a decent collection of BADGES.\p"
# 214 "data/maps/LavaridgeTown/scripts.pory"
	.string "All right, then.\n"
# 215 "data/maps/LavaridgeTown/scripts.pory"
	.string "You may as well have this.$"
# 216 "data/maps/LavaridgeTown/scripts.pory"

# 217 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
# 218 "data/maps/LavaridgeTown/scripts.pory"
	.string "BRENDAN: Keep those with you if you're\n"
# 219 "data/maps/LavaridgeTown/scripts.pory"
	.string "planning on going into that desert near\l"
# 220 "data/maps/LavaridgeTown/scripts.pory"
	.string "ROUTE 111.\p"
# 221 "data/maps/LavaridgeTown/scripts.pory"
	.string "There should be some POKéMON that\n"
# 222 "data/maps/LavaridgeTown/scripts.pory"
	.string "are exclusively desert-dwellers.\l"
# 223 "data/maps/LavaridgeTown/scripts.pory"
	.string "You might look around for those.\p"
# 224 "data/maps/LavaridgeTown/scripts.pory"
	.string "As for me…\n"
# 225 "data/maps/LavaridgeTown/scripts.pory"
	.string "I'm considering challenging NORMAN,\l"
# 226 "data/maps/LavaridgeTown/scripts.pory"
	.string "the GYM LEADER of PETALBURG.\p"
# 227 "data/maps/LavaridgeTown/scripts.pory"
	.string "Unlike you, {PLAYER}, your dad looks like\n"
# 228 "data/maps/LavaridgeTown/scripts.pory"
	.string "he really is tough.\p"
# 229 "data/maps/LavaridgeTown/scripts.pory"
	.string "See you around!$"
# 230 "data/maps/LavaridgeTown/scripts.pory"

# 231 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HaveEggWillYouTakeIt:
# 232 "data/maps/LavaridgeTown/scripts.pory"
	.string "I have here an EGG.\p"
# 233 "data/maps/LavaridgeTown/scripts.pory"
	.string "I'd hoped to hatch it by covering it in\n"
# 234 "data/maps/LavaridgeTown/scripts.pory"
	.string "hot sand by the hot springs.\l"
# 235 "data/maps/LavaridgeTown/scripts.pory"
	.string "But that doesn't seem to be enough…\p"
# 236 "data/maps/LavaridgeTown/scripts.pory"
	.string "I've heard it would be best if it were\n"
# 237 "data/maps/LavaridgeTown/scripts.pory"
	.string "kept together with POKéMON and\l"
# 238 "data/maps/LavaridgeTown/scripts.pory"
	.string "carried about.\p"
# 239 "data/maps/LavaridgeTown/scripts.pory"
	.string "You are a TRAINER, yes?\n"
# 240 "data/maps/LavaridgeTown/scripts.pory"
	.string "And your POKéMON radiate vitality.\p"
# 241 "data/maps/LavaridgeTown/scripts.pory"
	.string "So, what say you?\n"
# 242 "data/maps/LavaridgeTown/scripts.pory"
	.string "Will you take this EGG to hatch?$"
# 243 "data/maps/LavaridgeTown/scripts.pory"

# 244 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
# 245 "data/maps/LavaridgeTown/scripts.pory"
	.string "Good! I hope you'll walk plenty with\n"
# 246 "data/maps/LavaridgeTown/scripts.pory"
	.string "this here EGG!$"
# 247 "data/maps/LavaridgeTown/scripts.pory"

# 248 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_ReceivedTheEgg:
# 249 "data/maps/LavaridgeTown/scripts.pory"
	.string "{PLAYER} received the EGG.$"
# 250 "data/maps/LavaridgeTown/scripts.pory"

# 251 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_NoRoomForThisEgg:
# 252 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh? You've too many POKéMON.\n"
# 253 "data/maps/LavaridgeTown/scripts.pory"
	.string "There's no room for this EGG…$"
# 254 "data/maps/LavaridgeTown/scripts.pory"

# 255 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_AsYouWishThen:
# 256 "data/maps/LavaridgeTown/scripts.pory"
	.string "As you wish, then…\p"
# 257 "data/maps/LavaridgeTown/scripts.pory"
	.string "If you have a change of heart about\n"
# 258 "data/maps/LavaridgeTown/scripts.pory"
	.string "hatching this EGG, I will be here.$"
# 259 "data/maps/LavaridgeTown/scripts.pory"

# 260 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
# 261 "data/maps/LavaridgeTown/scripts.pory"
	.string "Every so often, an EGG will be found at\n"
# 262 "data/maps/LavaridgeTown/scripts.pory"
	.string "the POKéMON DAY CARE.\p"
# 263 "data/maps/LavaridgeTown/scripts.pory"
	.string "Or at least that's how the rumor goes.$"
# 264 "data/maps/LavaridgeTown/scripts.pory"

# 265 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HotSpringsNeverRunDry:
# 266 "data/maps/LavaridgeTown/scripts.pory"
	.string "We draw as much hot water as we need,\n"
# 267 "data/maps/LavaridgeTown/scripts.pory"
	.string "and yet the hot springs never run dry.\p"
# 268 "data/maps/LavaridgeTown/scripts.pory"
	.string "Isn't it magical?(TEAM MAGMA THAT IS)\p"
# 269 "data/maps/LavaridgeTown/scripts.pory"
	.string "These hot springs appear near active\n"
# 270 "data/maps/LavaridgeTown/scripts.pory"
	.string "volcanoes. Veins of water under the\l"
# 271 "data/maps/LavaridgeTown/scripts.pory"
	.string "ground are heated by MAGMA to well up\l"
# 272 "data/maps/LavaridgeTown/scripts.pory"
	.string "as hot springs. WE WILL RISE AGAIN...$"
# 273 "data/maps/LavaridgeTown/scripts.pory"

# 274 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_PokemonNippedBackside:
# 275 "data/maps/LavaridgeTown/scripts.pory"
	.string "Being buried in this hot sand is…\n"
# 276 "data/maps/LavaridgeTown/scripts.pory"
	.string "Sigh…\p"
# 277 "data/maps/LavaridgeTown/scripts.pory"
	.string "So warm and heavenly…\p"
# 278 "data/maps/LavaridgeTown/scripts.pory"
	.string "Eh? Gyaah! Ouch!\p"
# 279 "data/maps/LavaridgeTown/scripts.pory"
	.string "A POKéMON nipped my backside!$"
# 280 "data/maps/LavaridgeTown/scripts.pory"

# 281 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_OhYouLikeHotSprings:
# 282 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh, you like hot springs, do you?\p"
# 283 "data/maps/LavaridgeTown/scripts.pory"
	.string "That's surprising for one as young\n"
# 284 "data/maps/LavaridgeTown/scripts.pory"
	.string "as you.$"
# 285 "data/maps/LavaridgeTown/scripts.pory"

# 286 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BatheInHotSpringsEveryDay:
# 287 "data/maps/LavaridgeTown/scripts.pory"
	.string "I bathe in the hot springs every day.\p"
# 288 "data/maps/LavaridgeTown/scripts.pory"
	.string "I want to become a beautiful and strong\n"
# 289 "data/maps/LavaridgeTown/scripts.pory"
	.string "GYM LEADER like FLANNERY.$"
# 290 "data/maps/LavaridgeTown/scripts.pory"

# 291 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_IfPokemonInHotSprings:
# 292 "data/maps/LavaridgeTown/scripts.pory"
	.string "If people put POKéMON in hot springs,\n"
# 293 "data/maps/LavaridgeTown/scripts.pory"
	.string "it might be seriously strange.\p"
# 294 "data/maps/LavaridgeTown/scripts.pory"
	.string "Why, it might be an electric bath, or\n"
# 295 "data/maps/LavaridgeTown/scripts.pory"
	.string "a bubble bath, or even a lava bath…$"
# 296 "data/maps/LavaridgeTown/scripts.pory"

# 297 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HotSpringsClaims:
# 298 "data/maps/LavaridgeTown/scripts.pory"
	.string "They're claiming that these hot springs\n"
# 299 "data/maps/LavaridgeTown/scripts.pory"
	.string "are good for calming nervous tension,\l"
# 300 "data/maps/LavaridgeTown/scripts.pory"
	.string "relieving aching muscles, solving\l"
# 301 "data/maps/LavaridgeTown/scripts.pory"
	.string "romantic problems, and attracting\l"
# 302 "data/maps/LavaridgeTown/scripts.pory"
	.string "money…$"
# 303 "data/maps/LavaridgeTown/scripts.pory"

# 304 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_TownSign:
# 305 "data/maps/LavaridgeTown/scripts.pory"
	.string "LAVARIDGE TOWN\p"
# 306 "data/maps/LavaridgeTown/scripts.pory"
	.string "“POKéMON CENTER HOT SPRINGS\n"
# 307 "data/maps/LavaridgeTown/scripts.pory"
	.string "An excellent place for relaxing!”$"
# 308 "data/maps/LavaridgeTown/scripts.pory"

# 309 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_GymSign:
# 310 "data/maps/LavaridgeTown/scripts.pory"
	.string "LAVARIDGE TOWN POKéMON GYM\n"
# 311 "data/maps/LavaridgeTown/scripts.pory"
	.string "LEADER: FLANNERY\l"
# 312 "data/maps/LavaridgeTown/scripts.pory"
	.string "“One with a fiery passion that burns!”$"
# 313 "data/maps/LavaridgeTown/scripts.pory"

# 314 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HerbShopSign:
# 315 "data/maps/LavaridgeTown/scripts.pory"
	.string "POKéMON HERB SHOP\n"
# 316 "data/maps/LavaridgeTown/scripts.pory"
	.string "“Bitter taste--better cure!”$"
