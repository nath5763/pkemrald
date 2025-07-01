# 1 "data/maps/GaladriaMart/scripts.pory"

# 2 "data/maps/GaladriaMart/scripts.pory"
GaladriaMart_MapScripts::
# 3 "data/maps/GaladriaMart/scripts.pory"
	.byte 0
# 4 "data/maps/GaladriaMart/scripts.pory"

# 5 "data/maps/GaladriaMart/scripts.pory"
Galadria_Mart_EventScript_Clerk::
# 6 "data/maps/GaladriaMart/scripts.pory"
	lock
# 7 "data/maps/GaladriaMart/scripts.pory"
	faceplayer
# 8 "data/maps/GaladriaMart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/GaladriaMart/scripts.pory"
	waitmessage
# 10 "data/maps/GaladriaMart/scripts.pory"
	pokemart Galadria_Mart_Pokemart
# 11 "data/maps/GaladriaMart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 12 "data/maps/GaladriaMart/scripts.pory"
	release
# 13 "data/maps/GaladriaMart/scripts.pory"
	end
# 14 "data/maps/GaladriaMart/scripts.pory"

# 15 "data/maps/GaladriaMart/scripts.pory"
	.align 2
# 16 "data/maps/GaladriaMart/scripts.pory"
Galadria_Mart_Pokemart:
# 17 "data/maps/GaladriaMart/scripts.pory"
	.2byte ITEM_ULTRA_BALL
# 18 "data/maps/GaladriaMart/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 19 "data/maps/GaladriaMart/scripts.pory"
	.2byte ITEM_MAX_POTION
# 20 "data/maps/GaladriaMart/scripts.pory"
	.2byte ITEM_FULL_RESTORE
# 21 "data/maps/GaladriaMart/scripts.pory"
	.2byte ITEM_FULL_HEAL
# 22 "data/maps/GaladriaMart/scripts.pory"
	.2byte ITEM_REVIVE
# 23 "data/maps/GaladriaMart/scripts.pory"
	.2byte ITEM_MAX_REPEL
# 24 "data/maps/GaladriaMart/scripts.pory"
	.2byte ITEM_PROTEIN
# 25 "data/maps/GaladriaMart/scripts.pory"
	.2byte ITEM_CALCIUM
# 26 "data/maps/GaladriaMart/scripts.pory"
	.2byte ITEM_IRON
# 27 "data/maps/GaladriaMart/scripts.pory"
	.2byte ITEM_ZINC
# 28 "data/maps/GaladriaMart/scripts.pory"
	.2byte ITEM_CARBOS
# 29 "data/maps/GaladriaMart/scripts.pory"
	.2byte ITEM_HP_UP
# 30 "data/maps/GaladriaMart/scripts.pory"
	pokemartlistend
