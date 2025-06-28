# 1 "data/maps/Galadria_Layout/scripts.pory"

# 2 "data/maps/Galadria_Layout/scripts.pory"
Galadria_Layout_MapScripts::
# 3 "data/maps/Galadria_Layout/scripts.pory"
	.byte 0
# 4 "data/maps/Galadria_Layout/scripts.pory"
Galadria_Mart_EventScript_Clerk::
# 5 "data/maps/Galadria_Layout/scripts.pory"
	lock
# 6 "data/maps/Galadria_Layout/scripts.pory"
	faceplayer
# 7 "data/maps/Galadria_Layout/scripts.pory"
	message gText_HowMayIServeYou
# 8 "data/maps/Galadria_Layout/scripts.pory"
	waitmessage
# 9 "data/maps/Galadria_Layout/scripts.pory"
	pokemart Galadria_Mart_Pokemart
# 10 "data/maps/Galadria_Layout/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 11 "data/maps/Galadria_Layout/scripts.pory"
	release
# 12 "data/maps/Galadria_Layout/scripts.pory"
	end
# 13 "data/maps/Galadria_Layout/scripts.pory"

# 14 "data/maps/Galadria_Layout/scripts.pory"
	.align 2
# 15 "data/maps/Galadria_Layout/scripts.pory"
Galadria_Mart_Pokemart:
# 16 "data/maps/Galadria_Layout/scripts.pory"
	.2byte ITEM_ULTRA_BALL
# 17 "data/maps/Galadria_Layout/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 18 "data/maps/Galadria_Layout/scripts.pory"
	.2byte ITEM_MAX_POTION
# 19 "data/maps/Galadria_Layout/scripts.pory"
	.2byte ITEM_FULL_HEAL
# 20 "data/maps/Galadria_Layout/scripts.pory"
	.2byte ITEM_REVIVE
# 21 "data/maps/Galadria_Layout/scripts.pory"
	.2byte ITEM_MAX_REPEL
# 22 "data/maps/Galadria_Layout/scripts.pory"
	.2byte ITEM_X_ATTACK
# 23 "data/maps/Galadria_Layout/scripts.pory"
	.2byte ITEM_X_DEFEND
# 24 "data/maps/Galadria_Layout/scripts.pory"
	.2byte ITEM_SHADOW_MAIL
# 25 "data/maps/Galadria_Layout/scripts.pory"
	pokemartlistend
