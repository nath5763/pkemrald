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
	setflag FLAG_BAG_CELEBI_DONE
# 10 "data/maps/AncientForest/scripts.pory"
	msgbox bagCelebiBattle_Text_0
# 11 "data/maps/AncientForest/scripts.pory"
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
# 12 "data/maps/AncientForest/scripts.pory"
	delay 40
# 13 "data/maps/AncientForest/scripts.pory"
	waitmoncry
# 14 "data/maps/AncientForest/scripts.pory"
	setwildbattle SPECIES_CELEBI, 30, ITEM_LUM_BERRY
# 15 "data/maps/AncientForest/scripts.pory"
	dowildbattle
# 16 "data/maps/AncientForest/scripts.pory"
	fadescreen FADE_TO_BLACK
# 17 "data/maps/AncientForest/scripts.pory"
	removeobject 1
# 18 "data/maps/AncientForest/scripts.pory"
	msgbox bagCelebiBattle_Text_1
# 19 "data/maps/AncientForest/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 20 "data/maps/AncientForest/scripts.pory"
	releaseall
	end


bagCelebiBattle_Text_0:
# 10 "data/maps/AncientForest/scripts.pory"
	.string "As you inspect the bag, a mysterious force emerges...$"

bagCelebiBattle_Text_1:
# 18 "data/maps/AncientForest/scripts.pory"
	.string "The force fades...$"
