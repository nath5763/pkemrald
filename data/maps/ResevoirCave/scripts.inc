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
	trainerbattle_single TRAINER_AQUA_ADMIN, AquaIntro, AquaOutro, postFight
# 23 "data/maps/ResevoirCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 24 "data/maps/ResevoirCave/scripts.pory"
	releaseall
	end


postFight::
# 29 "data/maps/ResevoirCave/scripts.pory"
	msgbox postFight_Text_0
# 30 "data/maps/ResevoirCave/scripts.pory"
	waitmessage
# 31 "data/maps/ResevoirCave/scripts.pory"
	setflag FLAG_RESEVOIR_CLEARED
# 32 "data/maps/ResevoirCave/scripts.pory"
	fadescreen FADE_TO_BLACK
# 33 "data/maps/ResevoirCave/scripts.pory"
	removeobject 1
# 34 "data/maps/ResevoirCave/scripts.pory"
	msgbox postFight_Text_1
# 35 "data/maps/ResevoirCave/scripts.pory"
	waitmessage
# 36 "data/maps/ResevoirCave/scripts.pory"
	giveitem ITEM_WATER_STONE
# 37 "data/maps/ResevoirCave/scripts.pory"
	waitbuttonpress
# 38 "data/maps/ResevoirCave/scripts.pory"
	removeobject 2
# 39 "data/maps/ResevoirCave/scripts.pory"
	fadescreen FADE_FROM_BLACK
	return


prisoner::
# 43 "data/maps/ResevoirCave/scripts.pory"
	lock
# 44 "data/maps/ResevoirCave/scripts.pory"
	faceplayer
# 45 "data/maps/ResevoirCave/scripts.pory"
	msgbox rocksmashGuyText
# 46 "data/maps/ResevoirCave/scripts.pory"
	waitmessage
# 47 "data/maps/ResevoirCave/scripts.pory"
	releaseall
	end


SuicuneFight::
# 52 "data/maps/ResevoirCave/scripts.pory"
	goto_if_unset FLAG_SUICUNE, SuicuneFight_1
	return

SuicuneFight_1:
# 53 "data/maps/ResevoirCave/scripts.pory"
	setflag FLAG_SUICUNE
# 54 "data/maps/ResevoirCave/scripts.pory"
	setwildbattle SPECIES_SUICUNE, 30
# 55 "data/maps/ResevoirCave/scripts.pory"
	dowildbattle
	return


aquaBattleScript_Text_0:
# 21 "data/maps/ResevoirCave/scripts.pory"
	.string "I need this guy to build me a tunnel.\nYou dare oppose Team Aqua?\p Prepare to battle!$"

postFight_Text_0:
# 29 "data/maps/ResevoirCave/scripts.pory"
	.string "Grr... this isn't over...$"

postFight_Text_1:
# 34 "data/maps/ResevoirCave/scripts.pory"
	.string "Thanks for freeing me,\n have these!$"

rocksmashGuyText::
# 6 "data/maps/ResevoirCave/scripts.pory"
	.string "There's no world where I \n break through that rock...$"

AquaIntro::
# 10 "data/maps/ResevoirCave/scripts.pory"
	.string "SUICUNE WILL BE MINE!$"

AquaOutro::
# 14 "data/maps/ResevoirCave/scripts.pory"
	.string "ARG, can't find it anyways$"
