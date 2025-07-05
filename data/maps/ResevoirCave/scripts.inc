ResevoirCave_MapScripts::
	.byte 0


aquaBattleScript::
# 19 "data/maps/ResevoirCave/scripts.pory"
	lock
# 20 "data/maps/ResevoirCave/scripts.pory"
	faceplayer
# 21 "data/maps/ResevoirCave/scripts.pory"
	msgbox aquaBattleScript_Text_0
# 22 "data/maps/ResevoirCave/scripts.pory"
	trainerbattle_single TRAINER_AQUA_ADMIN, AquaIntro, AquaOutro
# 23 "data/maps/ResevoirCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 24 "data/maps/ResevoirCave/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq aquaBattleScript_2
aquaBattleScript_1:
# 33 "data/maps/ResevoirCave/scripts.pory"
	releaseall
	end

aquaBattleScript_2:
# 25 "data/maps/ResevoirCave/scripts.pory"
	msgbox aquaBattleScript_Text_1
# 26 "data/maps/ResevoirCave/scripts.pory"
	waitmessage
# 27 "data/maps/ResevoirCave/scripts.pory"
	setflag FLAG_RESEVOIR_CLEARED
# 28 "data/maps/ResevoirCave/scripts.pory"
	fadescreen FADE_TO_BLACK
# 29 "data/maps/ResevoirCave/scripts.pory"
	removeobject 1
# 30 "data/maps/ResevoirCave/scripts.pory"
	removeobject 2
# 31 "data/maps/ResevoirCave/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto aquaBattleScript_1


prisoner::
# 38 "data/maps/ResevoirCave/scripts.pory"
	lock
# 39 "data/maps/ResevoirCave/scripts.pory"
	faceplayer
# 40 "data/maps/ResevoirCave/scripts.pory"
	msgbox rocksmashGuyText
# 41 "data/maps/ResevoirCave/scripts.pory"
	waitmessage
# 42 "data/maps/ResevoirCave/scripts.pory"
	releaseall
	end


SuicuneFight::
# 47 "data/maps/ResevoirCave/scripts.pory"
	goto_if_unset FLAG_SUICUNE, SuicuneFight_1
	return

SuicuneFight_1:
# 48 "data/maps/ResevoirCave/scripts.pory"
	setflag FLAG_SUICUNE
# 49 "data/maps/ResevoirCave/scripts.pory"
	setwildbattle SPECIES_SUICUNE, 30
# 50 "data/maps/ResevoirCave/scripts.pory"
	dowildbattle
	return


aquaBattleScript_Text_0:
# 21 "data/maps/ResevoirCave/scripts.pory"
	.string "I need this guy to build me a tunnel.\nYou dare oppose Team Aqua?\p Prepare to battle!$"

aquaBattleScript_Text_1:
# 25 "data/maps/ResevoirCave/scripts.pory"
	.string "Grr... this isn't over...$"

rocksmashGuyText::
# 6 "data/maps/ResevoirCave/scripts.pory"
	.string "There's no world where I \n break through that rock...$"

AquaIntro::
# 10 "data/maps/ResevoirCave/scripts.pory"
	.string "SUICUNE WILL BE MINE!$"

AquaOutro::
# 14 "data/maps/ResevoirCave/scripts.pory"
	.string "ARG, can't find it anyways$"
