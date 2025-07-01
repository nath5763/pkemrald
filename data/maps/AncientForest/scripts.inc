# 2 "data/maps/AncientForest/scripts.pory"

# 3 "data/maps/AncientForest/scripts.pory"
AncientForest_MapScripts::
# 4 "data/maps/AncientForest/scripts.pory"
	.byte 0

bagCelebiBattle::
# 7 "data/maps/AncientForest/scripts.pory"
	lockall
# 8 "data/maps/AncientForest/scripts.pory"
	faceplayer
# 9 "data/maps/AncientForest/scripts.pory"
	goto_if_set FLAG_BAG_CELEBI_DONE, bagCelebiBattle_2
# 14 "data/maps/AncientForest/scripts.pory"
	setflag FLAG_BAG_CELEBI_DONE
# 15 "data/maps/AncientForest/scripts.pory"
	msgbox bagCelebiBattle_Text_1
# 16 "data/maps/AncientForest/scripts.pory"
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
# 17 "data/maps/AncientForest/scripts.pory"
	delay 40
# 18 "data/maps/AncientForest/scripts.pory"
	waitmoncry
# 19 "data/maps/AncientForest/scripts.pory"
	setwildbattle SPECIES_CELEBI, 30, ITEM_LUM_BERRY
# 20 "data/maps/AncientForest/scripts.pory"
	dowildbattle
# 21 "data/maps/AncientForest/scripts.pory"
	fadescreen FADE_TO_BLACK
# 22 "data/maps/AncientForest/scripts.pory"
	removeobject 1
# 23 "data/maps/AncientForest/scripts.pory"
	msgbox bagCelebiBattle_Text_2
# 24 "data/maps/AncientForest/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 25 "data/maps/AncientForest/scripts.pory"
	releaseall
	end

bagCelebiBattle_2:
# 10 "data/maps/AncientForest/scripts.pory"
	msgbox bagCelebiBattle_Text_0
# 11 "data/maps/AncientForest/scripts.pory"
	releaseall
	end


bagCelebiBattle_Text_0:
# 10 "data/maps/AncientForest/scripts.pory"
	.string "It's just a plain old bag.$"

bagCelebiBattle_Text_1:
# 15 "data/maps/AncientForest/scripts.pory"
	.string "As you inspect the bag,\n a mysterious force emerges...$"

bagCelebiBattle_Text_2:
# 23 "data/maps/AncientForest/scripts.pory"
	.string "The force fades...$"
