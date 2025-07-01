# 1 "data/maps/GaladriaHouse2/scripts.pory"

# 2 "data/maps/GaladriaHouse2/scripts.pory"
GaladriaHouse2_MapScripts::
# 3 "data/maps/GaladriaHouse2/scripts.pory"
	.byte 0

AshtonText::
# 7 "data/maps/GaladriaHouse2/scripts.pory"
	lockall
# 8 "data/maps/GaladriaHouse2/scripts.pory"
	faceplayer
# 9 "data/maps/GaladriaHouse2/scripts.pory"
	msgbox AshtonText_Text_0
# 10 "data/maps/GaladriaHouse2/scripts.pory"
	release
	end


AshtonText_Text_0:
# 9 "data/maps/GaladriaHouse2/scripts.pory"
	.string "LEAF made a home for us here,\n away from the economic ruin\n we faced in LILYCOVE.$"
