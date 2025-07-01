# 1 "data/maps/GaladriaHouse3/scripts.pory"

# 2 "data/maps/GaladriaHouse3/scripts.pory"
GaladriaHouse3_MapScripts::
# 3 "data/maps/GaladriaHouse3/scripts.pory"
	.byte 0

MatildaText::
# 6 "data/maps/GaladriaHouse3/scripts.pory"
	lockall
# 7 "data/maps/GaladriaHouse3/scripts.pory"
	faceplayer
# 8 "data/maps/GaladriaHouse3/scripts.pory"
	msgbox MatildaText_Text_0
# 9 "data/maps/GaladriaHouse3/scripts.pory"
	release
	end


MatildaText_Text_0:
# 8 "data/maps/GaladriaHouse3/scripts.pory"
	.string "We found a gap in the market,\n GRASS types!$"
