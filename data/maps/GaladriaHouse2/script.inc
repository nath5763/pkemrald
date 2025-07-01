# 1 "data/maps/GaladriaHouse2/script.pory"

# 2 "data/maps/GaladriaHouse2/script.pory"
GaladriaHouse2_MapScripts::
# 3 "data/maps/GaladriaHouse2/script.pory"
	.byte 0

AshtonText::
# 7 "data/maps/GaladriaHouse2/script.pory"
	lockall
# 8 "data/maps/GaladriaHouse2/script.pory"
	faceplayer
# 9 "data/maps/GaladriaHouse2/script.pory"
	msgbox AshtonText_Text_0
# 10 "data/maps/GaladriaHouse2/script.pory"
	release
	end


AshtonText_Text_0:
# 9 "data/maps/GaladriaHouse2/script.pory"
	.string "LEAF made a home for us here,\n away from the economic ruin\n we faced in LILYCOVE.$"
