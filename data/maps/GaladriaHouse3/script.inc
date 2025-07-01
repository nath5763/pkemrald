# 1 "data/maps/GaladriaHouse3/script.pory"

# 2 "data/maps/GaladriaHouse3/script.pory"
GaladriaHouse3_MapScripts::
# 3 "data/maps/GaladriaHouse3/script.pory"
	.byte 0

MatildaText::
# 6 "data/maps/GaladriaHouse3/script.pory"
	lockall
# 7 "data/maps/GaladriaHouse3/script.pory"
	faceplayer
# 8 "data/maps/GaladriaHouse3/script.pory"
	msgbox MatildaText_Text_0
# 9 "data/maps/GaladriaHouse3/script.pory"
	release
	end


MatildaText_Text_0:
# 8 "data/maps/GaladriaHouse3/script.pory"
	.string "We found a gap in the market,\n GRASS types!$"
