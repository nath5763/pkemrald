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
	compare VAR_RESULT, 0
	goto_if_eq doorLoad_3
doorLoad_2:
# 37 "data/maps/Route135/scripts.pory"
	setmetatile 51, 5, 0x2B2, FALSE
# 38 "data/maps/Route135/scripts.pory"
	setmetatile 51, 4, 0x2AA, FALSE
	return

doorLoad_1:
# 34 "data/maps/Route135/scripts.pory"
	setmetatile 51, 5, 0x2CA, TRUE
# 35 "data/maps/Route135/scripts.pory"
	setmetatile 51, 4, 0x2C2, TRUE
	return

doorLoad_3:
# 33 "data/maps/Route135/scripts.pory"
	goto_if_set FLAG_ANDREW_MAGMA, doorLoad_1
	goto doorLoad_2


andrewFight::
# 44 "data/maps/Route135/scripts.pory"
	lockall
# 45 "data/maps/Route135/scripts.pory"
	faceplayer
# 46 "data/maps/Route135/scripts.pory"
	msgbox andrewFight_Text_0
# 47 "data/maps/Route135/scripts.pory"
	waitmessage
# 48 "data/maps/Route135/scripts.pory"
	trainerbattle_single TRAINER_ANDREW_MAGMA_PLACEHOLDER, andrewIntro, andrewOutro
# 49 "data/maps/Route135/scripts.pory"
	checktrainerflag TRAINER_ANDREW_MAGMA_PLACEHOLDER
	goto_if 1, andrewFight_2
andrewFight_1:
# 55 "data/maps/Route135/scripts.pory"
	releaseall
	end

andrewFight_2:
# 50 "data/maps/Route135/scripts.pory"
	fadescreen FADE_TO_BLACK
# 51 "data/maps/Route135/scripts.pory"
	setflag FLAG_ANDREW_MAGMA
# 52 "data/maps/Route135/scripts.pory"
	removeobject 3
# 53 "data/maps/Route135/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto andrewFight_1


magmaMale_Text_0:
# 8 "data/maps/Route135/scripts.pory"
	.string "We defected from our respective teams \n because we were afraid of \p what we were becoming.$"

aquaGirl_Text_0:
# 17 "data/maps/Route135/scripts.pory"
	.string "MAXIE is insane, we've decided \n to follow ANDREW instead. \p He said he found a secret here,\n it will save us.$"

castformPuzzle_Text_0:
# 25 "data/maps/Route135/scripts.pory"
	.string "The clouds must shift, the storm must form,\nReveal the path with weather's norm.\pIf change you seek from sky to sand,\nBring nature's child in guiding hand...$"

andrewFight_Text_0:
# 46 "data/maps/Route135/scripts.pory"
	.string "I heard the POKEMON in here\n can bring us salvation.$"

andrewIntro::
# 59 "data/maps/Route135/scripts.pory"
	.string "I need it's power to atone for my sins.$"

andrewOutro::
# 63 "data/maps/Route135/scripts.pory"
	.string "My sins cannot be washed away...$"
