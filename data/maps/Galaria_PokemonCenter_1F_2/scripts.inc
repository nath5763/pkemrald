# 1 "data/maps/Galaria_PokemonCenter_1F_2/scripts.pory"

# 2 "data/maps/Galaria_PokemonCenter_1F_2/scripts.pory"
Galaria_PokemonCenter_1F_2_MapScripts::
# 3 "data/maps/Galaria_PokemonCenter_1F_2/scripts.pory"
	.byte 0
# 4 "data/maps/Galaria_PokemonCenter_1F_2/scripts.pory"

# 5 "data/maps/Galaria_PokemonCenter_1F_2/scripts.pory"

# 6 "data/maps/Galaria_PokemonCenter_1F_2/scripts.pory"
Galaria_EventScript_Nurse::
# 7 "data/maps/Galaria_PokemonCenter_1F_2/scripts.pory"
	setvar VAR_0x800B, LOCALID_DEWFORD_NURSE
# 8 "data/maps/Galaria_PokemonCenter_1F_2/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 9 "data/maps/Galaria_PokemonCenter_1F_2/scripts.pory"
	waitmessage
# 10 "data/maps/Galaria_PokemonCenter_1F_2/scripts.pory"
	waitbuttonpress
# 11 "data/maps/Galaria_PokemonCenter_1F_2/scripts.pory"
	release
# 12 "data/maps/Galaria_PokemonCenter_1F_2/scripts.pory"
	end
