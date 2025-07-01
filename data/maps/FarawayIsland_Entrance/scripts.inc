# 1 "data/maps/FarawayIsland_Entrance/scripts.pory"

# 2 "data/maps/FarawayIsland_Entrance/scripts.pory"
FarawayIsland_Entrance_MapScripts::
# 3 "data/maps/FarawayIsland_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FarawayIsland_Entrance_OnTransition
# 4 "data/maps/FarawayIsland_Entrance/scripts.pory"
	.byte 0
# 5 "data/maps/FarawayIsland_Entrance/scripts.pory"

# 6 "data/maps/FarawayIsland_Entrance/scripts.pory"
FarawayIsland_Entrance_OnTransition:
# 7 "data/maps/FarawayIsland_Entrance/scripts.pory"
	setflag FLAG_ARRIVED_ON_FARAWAY_ISLAND
# 8 "data/maps/FarawayIsland_Entrance/scripts.pory"
	end
# 9 "data/maps/FarawayIsland_Entrance/scripts.pory"

# 10 "data/maps/FarawayIsland_Entrance/scripts.pory"
FarawayIsland_Entrance_EventScript_SetCloudsWeather::
# 11 "data/maps/FarawayIsland_Entrance/scripts.pory"
	setweather WEATHER_SUNNY_CLOUDS
# 12 "data/maps/FarawayIsland_Entrance/scripts.pory"
	doweather
# 13 "data/maps/FarawayIsland_Entrance/scripts.pory"
	end
# 14 "data/maps/FarawayIsland_Entrance/scripts.pory"

# 15 "data/maps/FarawayIsland_Entrance/scripts.pory"
FarawayIsland_Entrance_EventScript_ClearWeather::
# 16 "data/maps/FarawayIsland_Entrance/scripts.pory"
	setweather WEATHER_NONE
# 17 "data/maps/FarawayIsland_Entrance/scripts.pory"
	doweather
# 18 "data/maps/FarawayIsland_Entrance/scripts.pory"
	end
# 19 "data/maps/FarawayIsland_Entrance/scripts.pory"

# 20 "data/maps/FarawayIsland_Entrance/scripts.pory"
FarawayIsland_Entrance_EventScript_Sign::
# 21 "data/maps/FarawayIsland_Entrance/scripts.pory"
	msgbox FarawayIsland_Entrance_Text_Sign, MSGBOX_SIGN
# 22 "data/maps/FarawayIsland_Entrance/scripts.pory"
	end
