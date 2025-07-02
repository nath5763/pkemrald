# 1 "data/maps/GaladriaHouse1/scripts.pory"

# 2 "data/maps/GaladriaHouse1/scripts.pory"
GaladriaHouse1_MapScripts::
# 3 "data/maps/GaladriaHouse1/scripts.pory"
	.byte 0

GretaText::
# 7 "data/maps/GaladriaHouse1/scripts.pory"
	lockall
# 8 "data/maps/GaladriaHouse1/scripts.pory"
	faceplayer
# 9 "data/maps/GaladriaHouse1/scripts.pory"
	msgbox GretaText_Text_0
# 10 "data/maps/GaladriaHouse1/scripts.pory"
	release
	end


GretaText_Text_0:
# 9 "data/maps/GaladriaHouse1/scripts.pory"
	.string "As the Devon Corporation expanded,\n It became too expensive to live \p on the mainland. Here we are!$"
