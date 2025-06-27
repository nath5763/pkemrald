# 1 "data/maps/MossdeepCity_House3/scripts.pory"

# 2 "data/maps/MossdeepCity_House3/scripts.pory"
MossdeepCity_House3_MapScripts::
# 3 "data/maps/MossdeepCity_House3/scripts.pory"
	.byte 0
# 4 "data/maps/MossdeepCity_House3/scripts.pory"

# 5 "data/maps/MossdeepCity_House3/scripts.pory"
MossdeepCity_House3_EventScript_SuperRodFisherman::
# 6 "data/maps/MossdeepCity_House3/scripts.pory"
	lock
# 7 "data/maps/MossdeepCity_House3/scripts.pory"
	faceplayer
# 8 "data/maps/MossdeepCity_House3/scripts.pory"
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_ReceivedSuperRod
# 9 "data/maps/MossdeepCity_House3/scripts.pory"
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
# 10 "data/maps/MossdeepCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MossdeepCity_House3_EventScript_DeclineSuperRod
# 11 "data/maps/MossdeepCity_House3/scripts.pory"
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper, MSGBOX_DEFAULT
# 12 "data/maps/MossdeepCity_House3/scripts.pory"
	giveitem ITEM_SUPER_ROD
# 13 "data/maps/MossdeepCity_House3/scripts.pory"
	setflag FLAG_RECEIVED_SUPER_ROD
# 14 "data/maps/MossdeepCity_House3/scripts.pory"
	msgbox MossdeepCity_House3_Text_TryDroppingRodInWater, MSGBOX_DEFAULT
# 15 "data/maps/MossdeepCity_House3/scripts.pory"
	release
# 16 "data/maps/MossdeepCity_House3/scripts.pory"
	end
# 17 "data/maps/MossdeepCity_House3/scripts.pory"

# 18 "data/maps/MossdeepCity_House3/scripts.pory"
MossdeepCity_House3_EventScript_ReceivedSuperRod::
# 19 "data/maps/MossdeepCity_House3/scripts.pory"
	msgbox MossdeepCity_House3_Text_GoAfterSeafloorPokemon, MSGBOX_DEFAULT
# 20 "data/maps/MossdeepCity_House3/scripts.pory"
	release
# 21 "data/maps/MossdeepCity_House3/scripts.pory"
	end
# 22 "data/maps/MossdeepCity_House3/scripts.pory"

# 23 "data/maps/MossdeepCity_House3/scripts.pory"
MossdeepCity_House3_EventScript_DeclineSuperRod::
# 24 "data/maps/MossdeepCity_House3/scripts.pory"
	msgbox MossdeepCity_House3_Text_DontYouLikeToFish, MSGBOX_DEFAULT
# 25 "data/maps/MossdeepCity_House3/scripts.pory"
	release
# 26 "data/maps/MossdeepCity_House3/scripts.pory"
	end
# 27 "data/maps/MossdeepCity_House3/scripts.pory"

# 28 "data/maps/MossdeepCity_House3/scripts.pory"
MossdeepCity_House3_Text_YouWantSuperRod:
# 29 "data/maps/MossdeepCity_House3/scripts.pory"
	.string "Hey there, TRAINER!\n"
# 30 "data/maps/MossdeepCity_House3/scripts.pory"
	.string "A SUPER ROD really is super!\p"
# 31 "data/maps/MossdeepCity_House3/scripts.pory"
	.string "Say all you want, but this baby can\n"
# 32 "data/maps/MossdeepCity_House3/scripts.pory"
	.string "catch POKéMON off the seafloor!\p"
# 33 "data/maps/MossdeepCity_House3/scripts.pory"
	.string "What do you think?\n"
# 34 "data/maps/MossdeepCity_House3/scripts.pory"
	.string "You want it, don't you?$"
# 35 "data/maps/MossdeepCity_House3/scripts.pory"

# 36 "data/maps/MossdeepCity_House3/scripts.pory"
MossdeepCity_House3_Text_SuperRodIsSuper:
# 37 "data/maps/MossdeepCity_House3/scripts.pory"
	.string "You bet, you bet!\n"
# 38 "data/maps/MossdeepCity_House3/scripts.pory"
	.string "After all, a SUPER ROD is really super!$"
# 39 "data/maps/MossdeepCity_House3/scripts.pory"

# 40 "data/maps/MossdeepCity_House3/scripts.pory"
MossdeepCity_House3_Text_TryDroppingRodInWater:
# 41 "data/maps/MossdeepCity_House3/scripts.pory"
	.string "If there's any water, try dropping in\n"
# 42 "data/maps/MossdeepCity_House3/scripts.pory"
	.string "your ROD and see what bites!$"
# 43 "data/maps/MossdeepCity_House3/scripts.pory"

# 44 "data/maps/MossdeepCity_House3/scripts.pory"
MossdeepCity_House3_Text_DontYouLikeToFish:
# 45 "data/maps/MossdeepCity_House3/scripts.pory"
	.string "Hunh?\n"
# 46 "data/maps/MossdeepCity_House3/scripts.pory"
	.string "Don't you like to fish?$"
# 47 "data/maps/MossdeepCity_House3/scripts.pory"

# 48 "data/maps/MossdeepCity_House3/scripts.pory"
MossdeepCity_House3_Text_GoAfterSeafloorPokemon:
# 49 "data/maps/MossdeepCity_House3/scripts.pory"
	.string "Go after the seafloor POKéMON with\n"
# 50 "data/maps/MossdeepCity_House3/scripts.pory"
	.string "your SUPER ROD.$"
