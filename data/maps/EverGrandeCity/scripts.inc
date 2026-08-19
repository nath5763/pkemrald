# 1 "data/maps/EverGrandeCity/scripts.pory"

# 2 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_MapScripts::
# 3 "data/maps/EverGrandeCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
# 4 "data/maps/EverGrandeCity/scripts.pory"
	.byte 0
# 5 "data/maps/EverGrandeCity/scripts.pory"

# 6 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_OnTransition:
# 7 "data/maps/EverGrandeCity/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 8 "data/maps/EverGrandeCity/scripts.pory"
	end
# 9 "data/maps/EverGrandeCity/scripts.pory"

# 10 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_VictoryRoadSign::
# 11 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
# 12 "data/maps/EverGrandeCity/scripts.pory"
	end
# 13 "data/maps/EverGrandeCity/scripts.pory"

# 14 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_CitySign::
# 15 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
# 16 "data/maps/EverGrandeCity/scripts.pory"
	end
# 17 "data/maps/EverGrandeCity/scripts.pory"

# 18 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_PokemonLeagueSign::
# 19 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
# 20 "data/maps/EverGrandeCity/scripts.pory"
	end
# 21 "data/maps/EverGrandeCity/scripts.pory"

# 22 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_VictoryRoadGuard::
# 23 "data/maps/EverGrandeCity/scripts.pory"
	lock
# 24 "data/maps/EverGrandeCity/scripts.pory"
	faceplayer
# 25 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_VictoryRoadGuard, MSGBOX_DEFAULT
# 26 "data/maps/EverGrandeCity/scripts.pory"
	release
# 27 "data/maps/EverGrandeCity/scripts.pory"
	end
# 28 "data/maps/EverGrandeCity/scripts.pory"

# 29 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_SetVisitedEverGrande::
# 30 "data/maps/EverGrandeCity/scripts.pory"
	setflag FLAG_VISITED_EVER_GRANDE_CITY
# 31 "data/maps/EverGrandeCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 32 "data/maps/EverGrandeCity/scripts.pory"
	end
# 33 "data/maps/EverGrandeCity/scripts.pory"

# 34 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_EnteringVictoryRoad:
# 35 "data/maps/EverGrandeCity/scripts.pory"
	.string "ENTERING VICTORY ROAD$"
# 36 "data/maps/EverGrandeCity/scripts.pory"

# 37 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_EnteringPokemonLeague:
# 38 "data/maps/EverGrandeCity/scripts.pory"
	.string "ENTERING POKéMON LEAGUE\n"
# 39 "data/maps/EverGrandeCity/scripts.pory"
	.string "CENTER GATE$"
# 40 "data/maps/EverGrandeCity/scripts.pory"

# 41 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_CitySign:
# 42 "data/maps/EverGrandeCity/scripts.pory"
	.string "EVER GRANDE CITY\p"
# 43 "data/maps/EverGrandeCity/scripts.pory"
	.string "“The paradise of flowers, the sea,\n"
# 44 "data/maps/EverGrandeCity/scripts.pory"
	.string "and POKéMON.”$"
# 45 "data/maps/EverGrandeCity/scripts.pory"

# 46 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_VictoryRoadGuard:
# 47 "data/maps/EverGrandeCity/scripts.pory"
	.string "You cannot enter VICTORY ROAD\n"
# 48 "data/maps/EverGrandeCity/scripts.pory"
	.string "until you've defeated the ninth\l"
# 49 "data/maps/EverGrandeCity/scripts.pory"
	.string "GYM LEADER.$"
