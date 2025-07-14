PokecenterRoute135_MapScripts::
# 2 "data/maps/PokecenterRoute135/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, route135Respawn
	.byte 0


route135Respawn::
# 6 "data/maps/PokecenterRoute135/scripts.pory"
	setrespawn HEAL_LOCATION_ROUTE135
	end


nurseRoute135::
# 11 "data/maps/PokecenterRoute135/scripts.pory"
	lockall
# 12 "data/maps/PokecenterRoute135/scripts.pory"
	msgbox nurseRoute135_Text_0
# 13 "data/maps/PokecenterRoute135/scripts.pory"
	waitmessage
# 14 "data/maps/PokecenterRoute135/scripts.pory"
	waitbuttonpress
# 15 "data/maps/PokecenterRoute135/scripts.pory"
	special HealPlayerParty
# 16 "data/maps/PokecenterRoute135/scripts.pory"
	msgbox nurseRoute135_Text_1
# 17 "data/maps/PokecenterRoute135/scripts.pory"
	waitmessage
# 18 "data/maps/PokecenterRoute135/scripts.pory"
	waitbuttonpress
# 19 "data/maps/PokecenterRoute135/scripts.pory"
	releaseall
	end


nurseRoute135_Text_0:
# 12 "data/maps/PokecenterRoute135/scripts.pory"
	.string "I'm going to take your Pokemon\n and heal them.$"

nurseRoute135_Text_1:
# 16 "data/maps/PokecenterRoute135/scripts.pory"
	.string "Here you go!\n They're all healed up!$"
