Route135_MapScripts::
# 2 "data/maps/Route135/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, doorLoad
	.byte 0


magmaMale::
# 6 "data/maps/Route135/scripts.pory"
	lockall
# 7 "data/maps/Route135/scripts.pory"
	faceplayer
# 8 "data/maps/Route135/scripts.pory"
	msgbox magmaMale_Text_0
# 9 "data/maps/Route135/scripts.pory"
	waitmessage
# 10 "data/maps/Route135/scripts.pory"
	releaseall
	end


aquaGirl::
# 15 "data/maps/Route135/scripts.pory"
	lockall
# 16 "data/maps/Route135/scripts.pory"
	faceplayer
# 17 "data/maps/Route135/scripts.pory"
	msgbox aquaGirl_Text_0
# 18 "data/maps/Route135/scripts.pory"
	waitmessage
# 19 "data/maps/Route135/scripts.pory"
	releaseall
	end


castformPuzzle::
# 24 "data/maps/Route135/scripts.pory"
	lockall
# 25 "data/maps/Route135/scripts.pory"
	msgbox castformPuzzle_Text_0
# 26 "data/maps/Route135/scripts.pory"
	waitmessage
# 27 "data/maps/Route135/scripts.pory"
	releaseall
	end


doorLoad::
# 32 "data/maps/Route135/scripts.pory"
	specialvar VAR_RESULT, CheckCastform
# 33 "data/maps/Route135/scripts.pory"
	goto_if_set FLAG_ANDREW_MAGMA, doorLoad_4
doorLoad_3:
# 36 "data/maps/Route135/scripts.pory"
	setflag FLAG_HIDE_LEADERS
doorLoad_1:
# 38 "data/maps/Route135/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq doorLoad_10
doorLoad_9:
# 42 "data/maps/Route135/scripts.pory"
	setmetatile 51, 5, 0x2B2, FALSE
# 43 "data/maps/Route135/scripts.pory"
	setmetatile 51, 4, 0x2AA, FALSE
doorLoad_7:
# 46 "data/maps/Route135/scripts.pory"
	goto_if_set FLAG_IS_CHAMPION, doorLoad_13
# 49 "data/maps/Route135/scripts.pory"
	setmetatile 42, 47, 0x021, FALSE
	return

doorLoad_2:
# 34 "data/maps/Route135/scripts.pory"
	clearflag FLAG_HIDE_LEADERS
	goto doorLoad_1

doorLoad_4:
# 33 "data/maps/Route135/scripts.pory"
	goto_if_set FLAG_BADGE08_GET, doorLoad_2
	goto doorLoad_3

doorLoad_8:
# 39 "data/maps/Route135/scripts.pory"
	setmetatile 51, 5, 0x2CA, TRUE
# 40 "data/maps/Route135/scripts.pory"
	setmetatile 51, 4, 0x2C2, TRUE
	goto doorLoad_7

doorLoad_10:
# 38 "data/maps/Route135/scripts.pory"
	goto_if_set TRAINER_ANDREW_MAGMA_PLACEHOLDER, doorLoad_8
	goto doorLoad_9

doorLoad_13:
# 47 "data/maps/Route135/scripts.pory"
	setmetatile 42, 47, 0x021, TRUE
	return


championClub::
# 54 "data/maps/Route135/scripts.pory"
	lockall
# 55 "data/maps/Route135/scripts.pory"
	msgbox championClub_Text_0
# 56 "data/maps/Route135/scripts.pory"
	waitmessage
# 57 "data/maps/Route135/scripts.pory"
	releaseall
	end


eeveeTrainer::
# 62 "data/maps/Route135/scripts.pory"
	lockall
# 63 "data/maps/Route135/scripts.pory"
	goto_if_set FLAG_EEVEE_GIFTED, eeveeTrainer_2
# 67 "data/maps/Route135/scripts.pory"
	trainerbattle_single FLAG_EEVEE_TRAINER, eeveeIntro, eeveeOutro, giftEevee
eeveeTrainer_1:
# 69 "data/maps/Route135/scripts.pory"
	releaseall
	end

eeveeTrainer_2:
# 64 "data/maps/Route135/scripts.pory"
	msgbox eeveeTrainer_Text_0
# 65 "data/maps/Route135/scripts.pory"
	waitmessage
	goto eeveeTrainer_1


giftEevee::
# 74 "data/maps/Route135/scripts.pory"
	msgbox giftEevee_Text_0
# 75 "data/maps/Route135/scripts.pory"
	givemon SPECIES_EEVEE, 15, ITEM_EVERSTONE
# 76 "data/maps/Route135/scripts.pory"
	setflag FLAG_EEVEE_GIFTED
# 77 "data/maps/Route135/scripts.pory"
	waitmessage
# 78 "data/maps/Route135/scripts.pory"
	release
	end


cheerArchie::
# 91 "data/maps/Route135/scripts.pory"
	lockall
# 92 "data/maps/Route135/scripts.pory"
	msgbox cheerArchie_Text_0
# 93 "data/maps/Route135/scripts.pory"
	waitmessage
# 94 "data/maps/Route135/scripts.pory"
	releaseall
	end


cheerMaxie::
# 99 "data/maps/Route135/scripts.pory"
	lockall
# 100 "data/maps/Route135/scripts.pory"
	msgbox cheerMaxie_Text_0
# 101 "data/maps/Route135/scripts.pory"
	waitmessage
# 102 "data/maps/Route135/scripts.pory"
	releaseall
	end


maxieFight::
# 107 "data/maps/Route135/scripts.pory"
	lockall
# 108 "data/maps/Route135/scripts.pory"
	goto_if_set FLAG_MAXIE_135_DEFEATED, maxieFight_2
# 112 "data/maps/Route135/scripts.pory"
	trainerbattle_single FLAG_MAXIE_POST, maxieIntro, maxieOutro
maxieFight_1:
# 114 "data/maps/Route135/scripts.pory"
	releaseall
	end

maxieFight_2:
# 109 "data/maps/Route135/scripts.pory"
	msgbox maxietext
# 110 "data/maps/Route135/scripts.pory"
	waitmessage
	goto maxieFight_1


archieFight::
# 119 "data/maps/Route135/scripts.pory"
	lockall
# 120 "data/maps/Route135/scripts.pory"
	goto_if_set FLAG_ARCHIE_135_DEFEATED, archieFight_2
# 124 "data/maps/Route135/scripts.pory"
	trainerbattle_single FLAG_ARCHIE_POST, archieIntro, archieOutro
archieFight_1:
# 126 "data/maps/Route135/scripts.pory"
	releaseall
	end

archieFight_2:
# 121 "data/maps/Route135/scripts.pory"
	msgbox archietext
# 122 "data/maps/Route135/scripts.pory"
	waitmessage
	goto archieFight_1


andrewFight::
# 131 "data/maps/Route135/scripts.pory"
	lockall
# 132 "data/maps/Route135/scripts.pory"
	faceplayer
# 133 "data/maps/Route135/scripts.pory"
	msgbox andrewFight_Text_0
# 134 "data/maps/Route135/scripts.pory"
	waitmessage
# 135 "data/maps/Route135/scripts.pory"
	trainerbattle_single TRAINER_ANDREW_MAGMA_PLACEHOLDER, andrewIntro, andrewOutro, andrewDefeat, NO_MUSIC
# 136 "data/maps/Route135/scripts.pory"
	releaseall
	end


andrewDefeat::
# 141 "data/maps/Route135/scripts.pory"
	fadescreen FADE_TO_BLACK
# 142 "data/maps/Route135/scripts.pory"
	setflag FLAG_ANDREW_MAGMA
# 143 "data/maps/Route135/scripts.pory"
	removeobject 3
# 144 "data/maps/Route135/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 145 "data/maps/Route135/scripts.pory"
	releaseall
	end


aquaBlocker::
# 182 "data/maps/Route135/scripts.pory"
	lockall
# 183 "data/maps/Route135/scripts.pory"
	faceplayer
# 184 "data/maps/Route135/scripts.pory"
	msgbox aquaBlocker_Text_0
# 185 "data/maps/Route135/scripts.pory"
	waitmessage
# 186 "data/maps/Route135/scripts.pory"
	releaseall
	end


leftovers_get::
# 191 "data/maps/Route135/scripts.pory"
	lockall
# 192 "data/maps/Route135/scripts.pory"
	goto_if_unset FLAG_LEFTOVERS_135, leftovers_get_2
leftovers_get_1:
# 197 "data/maps/Route135/scripts.pory"
	releaseall
	end

leftovers_get_2:
# 193 "data/maps/Route135/scripts.pory"
	giveitem ITEM_LEFTOVERS
# 194 "data/maps/Route135/scripts.pory"
	setflag FLAG_LEFTOVERS_135
# 195 "data/maps/Route135/scripts.pory"
	removeobject 20
	goto leftovers_get_1


punchTutor::
# 202 "data/maps/Route135/scripts.pory"
	lock
# 203 "data/maps/Route135/scripts.pory"
	faceplayer
# 204 "data/maps/Route135/scripts.pory"
	msgbox punchTutorIntro
# 205 "data/maps/Route135/scripts.pory"
	waitmessage
# 206 "data/maps/Route135/scripts.pory"
	call punchTutorChooseMove
# 207 "data/maps/Route135/scripts.pory"
	msgbox punchTutorComeBack
# 208 "data/maps/Route135/scripts.pory"
	waitmessage
# 209 "data/maps/Route135/scripts.pory"
	release
	end


punchTutorChooseMove::
# 214 "data/maps/Route135/scripts.pory"
	multichoice 0, 0, MULTI_ROUTE135_PUNCH_TUTOR, FALSE
# 215 "data/maps/Route135/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq punchTutorChooseMove_2
# 219 "data/maps/Route135/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq punchTutorChooseMove_5
# 223 "data/maps/Route135/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq punchTutorChooseMove_8
# 227 "data/maps/Route135/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq punchTutorChooseMove_11
# 231 "data/maps/Route135/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq punchTutorChooseMove_14
punchTutorChooseMove_13:
	return

punchTutorChooseMove_2:
# 216 "data/maps/Route135/scripts.pory"
	call punchTutorTeachFire
	return

punchTutorChooseMove_5:
# 220 "data/maps/Route135/scripts.pory"
	call punchTutorTeachThunder
	return

punchTutorChooseMove_8:
# 224 "data/maps/Route135/scripts.pory"
	call punchTutorTeachIce
	return

punchTutorChooseMove_11:
# 228 "data/maps/Route135/scripts.pory"
	call punchTutorTeachMega
	return

punchTutorChooseMove_14:
# 232 "data/maps/Route135/scripts.pory"
	call punchTutorTeachDynamic
	goto punchTutorChooseMove_13


punchTutorTeachFire::
# 238 "data/maps/Route135/scripts.pory"
	setvar VAR_0x8005, TUTOR_MOVE_FIRE_PUNCH
# 239 "data/maps/Route135/scripts.pory"
	call punchTutorTeachSelectedMove
	return


punchTutorTeachThunder::
# 244 "data/maps/Route135/scripts.pory"
	setvar VAR_0x8005, TUTOR_MOVE_THUNDER_PUNCH
# 245 "data/maps/Route135/scripts.pory"
	call punchTutorTeachSelectedMove
	return


punchTutorTeachIce::
# 250 "data/maps/Route135/scripts.pory"
	setvar VAR_0x8005, TUTOR_MOVE_ICE_PUNCH
# 251 "data/maps/Route135/scripts.pory"
	call punchTutorTeachSelectedMove
	return


punchTutorTeachMega::
# 256 "data/maps/Route135/scripts.pory"
	setvar VAR_0x8005, TUTOR_MOVE_MEGA_PUNCH
# 257 "data/maps/Route135/scripts.pory"
	call punchTutorTeachSelectedMove
	return


punchTutorTeachDynamic::
# 262 "data/maps/Route135/scripts.pory"
	setvar VAR_0x8005, TUTOR_MOVE_DYNAMIC_PUNCH
# 263 "data/maps/Route135/scripts.pory"
	call punchTutorTeachSelectedMove
	return


punchTutorTeachSelectedMove::
# 268 "data/maps/Route135/scripts.pory"
	msgbox punchTutorChooseMon
# 269 "data/maps/Route135/scripts.pory"
	waitmessage
# 270 "data/maps/Route135/scripts.pory"
	special ChooseMonForMoveTutor
# 271 "data/maps/Route135/scripts.pory"
	waitstate
# 272 "data/maps/Route135/scripts.pory"
	lock
# 273 "data/maps/Route135/scripts.pory"
	faceplayer
# 274 "data/maps/Route135/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq punchTutorTeachSelectedMove_2
punchTutorTeachSelectedMove_1:
	return

punchTutorTeachSelectedMove_2:
# 275 "data/maps/Route135/scripts.pory"
	msgbox punchTutorAnythingElse, MSGBOX_YESNO
# 276 "data/maps/Route135/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq punchTutorTeachSelectedMove_4
	goto punchTutorTeachSelectedMove_1

punchTutorTeachSelectedMove_4:
# 277 "data/maps/Route135/scripts.pory"
	call punchTutorChooseMove
	goto punchTutorTeachSelectedMove_1


magmaMale_Text_0:
# 8 "data/maps/Route135/scripts.pory"
	.string "We defected from our respective teams \n because we were afraid of \p what we were becoming.$"

aquaGirl_Text_0:
# 17 "data/maps/Route135/scripts.pory"
	.string "MAXIE is insane, we've decided \n to follow ANDREW instead. \p He said he found a secret here,\n it will save us.$"

castformPuzzle_Text_0:
# 25 "data/maps/Route135/scripts.pory"
	.string "The clouds must shift,\n the storm must form,\pReveal the path with weather's norm.\nIf change you seek from sky to sand,\pBring nature's child in guiding hand...$"

championClub_Text_0:
# 55 "data/maps/Route135/scripts.pory"
	.string "Champion's Club$"

eeveeTrainer_Text_0:
# 64 "data/maps/Route135/scripts.pory"
	.string "How are you liking that eevee?$"

giftEevee_Text_0:
# 74 "data/maps/Route135/scripts.pory"
	.string "Have this EEVEE!$"

cheerArchie_Text_0:
# 92 "data/maps/Route135/scripts.pory"
	.string "LETS GO ARCHIEEE!!$"

cheerMaxie_Text_0:
# 100 "data/maps/Route135/scripts.pory"
	.string "MAXIE, YOU GOT THIS!$"

andrewFight_Text_0:
# 133 "data/maps/Route135/scripts.pory"
	.string "I heard the POKEMON in here\n can bring us salvation.$"

aquaBlocker_Text_0:
# 184 "data/maps/Route135/scripts.pory"
	.string "Boss said no one passes,\n he's doing some RnD.$"

eeveeIntro::
# 82 "data/maps/Route135/scripts.pory"
	.string "I only like cute Pokemon!$"

eeveeOutro::
# 86 "data/maps/Route135/scripts.pory"
	.string "EEVEE is the best.$"

andrewIntro::
# 149 "data/maps/Route135/scripts.pory"
	.string "I need it's power to atone for my sins.$"

andrewOutro::
# 153 "data/maps/Route135/scripts.pory"
	.string "My sins cannot be washed away...$"

maxieIntro::
# 157 "data/maps/Route135/scripts.pory"
	.string "I need a warm up for Archie$"

maxieOutro::
# 161 "data/maps/Route135/scripts.pory"
	.string "Hmm, I can still beat Archie$"

maxietext::
# 165 "data/maps/Route135/scripts.pory"
	.string "YOU'RE GOING DOWN ARCHIE$"

archieIntro::
# 169 "data/maps/Route135/scripts.pory"
	.string "I eat you for breakfast$"

archieOutro::
# 173 "data/maps/Route135/scripts.pory"
	.string "Whatever$"

archietext::
# 177 "data/maps/Route135/scripts.pory"
	.string "FIGHT ME MAXIE$"

punchTutorIntro::
# 283 "data/maps/Route135/scripts.pory"
	.string "I've trained my fists against rock,\n"
	.string "ice, and thunder itself.\p"
	.string "If your POKeMON can handle it,\n"
	.string "I can teach some serious punches.$"

punchTutorChooseMon::
# 290 "data/maps/Route135/scripts.pory"
	.string "Which POKeMON should throw the punch?$"

punchTutorAnythingElse::
# 294 "data/maps/Route135/scripts.pory"
	.string "Want me to teach another punching move?$"

punchTutorComeBack::
# 298 "data/maps/Route135/scripts.pory"
	.string "Come back if you want to hit harder.$"
