# 1 "data/maps/Galaria_PokemonCenter_1F_2/scripts.pory"

# 2 "data/maps/Galaria_PokemonCenter_1F_2/scripts.pory"
Galaria_EventScript_Nurse::
# 3 "data/maps/Galaria_PokemonCenter_1F_2/scripts.pory"
	setvar VAR_0x800B, LOCALID_DEWFORD_NURSE
# 4 "data/maps/Galaria_PokemonCenter_1F_2/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 5 "data/maps/Galaria_PokemonCenter_1F_2/scripts.pory"
	waitmessage
# 6 "data/maps/Galaria_PokemonCenter_1F_2/scripts.pory"
	waitbuttonpress
# 7 "data/maps/Galaria_PokemonCenter_1F_2/scripts.pory"
	release
# 8 "data/maps/Galaria_PokemonCenter_1F_2/scripts.pory"
	end

Galaria_PokemonCenter_1F_2_MapScripts::
# 12 "data/maps/Galaria_PokemonCenter_1F_2/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, visitedGaladria
	.byte 0


visitedGaladria::
# 16 "data/maps/Galaria_PokemonCenter_1F_2/scripts.pory"
	setflag FLAG_GALADRIA_FLY
	return

