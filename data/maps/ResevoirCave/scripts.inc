ResevoirCave_MapScripts::
# 4 "data/maps/ResevoirCave/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, sceneIntro
	.byte 0


sceneIntro::
# 16 "data/maps/ResevoirCave/scripts.pory"
	goto_if_set FLAG_RESEVOIR_CLEARED, sceneIntro_2
sceneIntro_1:
# 20 "data/maps/ResevoirCave/scripts.pory"
	goto_if_set FLAG_RESEVOIR_INTRO_DONE, sceneIntro_5
# 23 "data/maps/ResevoirCave/scripts.pory"
	lockall
# 24 "data/maps/ResevoirCave/scripts.pory"
	msgbox AquaAdminIntroText
# 25 "data/maps/ResevoirCave/scripts.pory"
	msgbox RockSmashGuyReplyText
# 26 "data/maps/ResevoirCave/scripts.pory"
	setflag FLAG_RESEVOIR_INTRO_DONE
# 27 "data/maps/ResevoirCave/scripts.pory"
	releaseall
	end

sceneIntro_2:
# 17 "data/maps/ResevoirCave/scripts.pory"
	removeobject 1
# 18 "data/maps/ResevoirCave/scripts.pory"
	removeobject 2
	goto sceneIntro_1

sceneIntro_5:
	end


aquaBattleScript::
# 32 "data/maps/ResevoirCave/scripts.pory"
	lock
# 33 "data/maps/ResevoirCave/scripts.pory"
	faceplayer
# 34 "data/maps/ResevoirCave/scripts.pory"
	msgbox aquaBattleScript_Text_0
# 35 "data/maps/ResevoirCave/scripts.pory"
	trainerbattle_single TRAINER_AQUA_ADMIN, aquaBattleScript_Text_1, aquaBattleScript_Text_2
# 36 "data/maps/ResevoirCave/scripts.pory"
	msgbox aquaBattleScript_Text_3
# 37 "data/maps/ResevoirCave/scripts.pory"
	setflag FLAG_RESEVOIR_CLEARED
# 38 "data/maps/ResevoirCave/scripts.pory"
	fadescreen FADE_TO_BLACK
# 39 "data/maps/ResevoirCave/scripts.pory"
	removeobject 1
# 40 "data/maps/ResevoirCave/scripts.pory"
	removeobject 2
# 41 "data/maps/ResevoirCave/scripts.pory"
	releaseall
	end


aquaBattleScript_Text_0:
# 34 "data/maps/ResevoirCave/scripts.pory"
	.string "You dare oppose Team Aqua? Prepare to battle!$"

aquaBattleScript_Text_1:
# 35 "data/maps/ResevoirCave/scripts.pory"
	.string "SUICUNE WILL BE MINE!$"

aquaBattleScript_Text_2:
# 35 "data/maps/ResevoirCave/scripts.pory"
	.string "ARG, can't find it anyways$"

aquaBattleScript_Text_3:
# 36 "data/maps/ResevoirCave/scripts.pory"
	.string "Grr... this isn't over...$"

AquaAdminIntroText::
# 7 "data/maps/ResevoirCave/scripts.pory"
	.string "You're going to build me a bridge,\nright now!$"

RockSmashGuyReplyText::
# 11 "data/maps/ResevoirCave/scripts.pory"
	.string "Sorry, I can't do that.\nThe rocks here are too dense.$"
