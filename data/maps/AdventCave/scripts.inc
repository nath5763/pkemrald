AdventCave_MapScripts::
# 2 "data/maps/AdventCave/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, unblockLugia
	.byte 0


hoohPuzzle::
# 10 "data/maps/AdventCave/scripts.pory"
	lockall
# 11 "data/maps/AdventCave/scripts.pory"
	msgbox sign
# 12 "data/maps/AdventCave/scripts.pory"
	waitmessage
# 13 "data/maps/AdventCave/scripts.pory"
	releaseall
	end


unblockLugia::
# 18 "data/maps/AdventCave/scripts.pory"
	specialvar VAR_RESULT, CheckHooh
# 19 "data/maps/AdventCave/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq unblockLugia_1
# 23 "data/maps/AdventCave/scripts.pory"
	setmetatile 40, 25, 0x201, FALSE
# 24 "data/maps/AdventCave/scripts.pory"
	setmetatile 40, 26, 0x201, FALSE
	return

unblockLugia_1:
# 20 "data/maps/AdventCave/scripts.pory"
	setmetatile 40, 25, 0x202, TRUE
# 21 "data/maps/AdventCave/scripts.pory"
	setmetatile 40, 26, 0x202, TRUE
	return


sign::
# 5 "data/maps/AdventCave/scripts.pory"
	.string "Seven shades the heavens wear,\nWoven bright in molten air.\pThose who glimpse the fire-born arc,\nShall find joy's light within the dark.$"
