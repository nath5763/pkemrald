# 1 "data/maps/MauvilleCity_House1/scripts.pory"

# 2 "data/maps/MauvilleCity_House1/scripts.pory"

# 3 "data/maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_EventScript_RockSmashDude::
# 4 "data/maps/MauvilleCity_House1/scripts.pory"
	lock
# 5 "data/maps/MauvilleCity_House1/scripts.pory"
	faceplayer
# 6 "data/maps/MauvilleCity_House1/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
# 7 "data/maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
# 8 "data/maps/MauvilleCity_House1/scripts.pory"
	giveitem ITEM_HM_ROCK_SMASH
# 9 "data/maps/MauvilleCity_House1/scripts.pory"
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
# 10 "data/maps/MauvilleCity_House1/scripts.pory"
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
# 11 "data/maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
# 12 "data/maps/MauvilleCity_House1/scripts.pory"
	release
# 13 "data/maps/MauvilleCity_House1/scripts.pory"
	end
# 14 "data/maps/MauvilleCity_House1/scripts.pory"

# 15 "data/maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_EventScript_ReceivedRockSmash::
# 16 "data/maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
# 17 "data/maps/MauvilleCity_House1/scripts.pory"
	release
# 18 "data/maps/MauvilleCity_House1/scripts.pory"
	end
# 19 "data/maps/MauvilleCity_House1/scripts.pory"

# 20 "data/maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
# 21 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "Woohoo!\p"
# 22 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "I hear people call me the ROCK SMASH\n"
# 23 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "GUY, but I find that sort of degrading.\p"
# 24 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "I think I deserve a bit more respect,\n"
# 25 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "like maybe the ROCK SMASH DUDE.\p"
# 26 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "Woohoo!\p"
# 27 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "Anyways, your POKéMON look pretty\n"
# 28 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "strong.\p"
# 29 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "I like that!\n"
# 30 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "Here, take this HIDDEN MACHINE!$"
# 31 "data/maps/MauvilleCity_House1/scripts.pory"

# 32 "data/maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_ExplainRockSmash:
# 33 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "That HM contains ROCK SMASH.\p"
# 34 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "If you come across large boulders\n"
# 35 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "that block your path…\p"
# 36 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "Well, use that HM move and smash\n"
# 37 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "them right out of your way!\p"
# 38 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "Yes, sir! Smash rocks aside, I say!\n"
# 39 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "Woohoo!$"
# 40 "data/maps/MauvilleCity_House1/scripts.pory"

# 41 "data/maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
# 42 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "Oh, yes, if you smash a rock, a POKéMON\n"
# 43 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "could come flying out of hiding.\p"
# 44 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "Woohoo!$"

MauvilleCity_House1_MapScripts::
# 48 "data/maps/MauvilleCity_House1/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, checkhostage
	.byte 0


checkhostage::
# 52 "data/maps/MauvilleCity_House1/scripts.pory"
	goto_if_set FLAG_RESEVOIR_CLEARED, checkhostage_1
# 55 "data/maps/MauvilleCity_House1/scripts.pory"
	setflag FLAG_HIDE_HOSTAGE
	return

checkhostage_1:
# 53 "data/maps/MauvilleCity_House1/scripts.pory"
	clearflag FLAG_HIDE_HOSTAGE
	return


hostageScript::
# 64 "data/maps/MauvilleCity_House1/scripts.pory"
	lockall
# 65 "data/maps/MauvilleCity_House1/scripts.pory"
	msgbox hostageNote
# 66 "data/maps/MauvilleCity_House1/scripts.pory"
	waitmessage
# 67 "data/maps/MauvilleCity_House1/scripts.pory"
	releaseall
	return


hostageNote::
# 59 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "I'm off to RESEVOIR CAVE,\n nothing fishy here!$"
