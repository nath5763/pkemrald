ScorchedCavern_MapScripts::
	.byte 0


enteiFight::
# 6 "data/maps/ScorchedCavern/scripts.pory"
	goto_if_unset FLAG_ENTEI, enteiFight_1
	return

enteiFight_1:
# 7 "data/maps/ScorchedCavern/scripts.pory"
	setflag FLAG_ENTEI
# 8 "data/maps/ScorchedCavern/scripts.pory"
	setwildbattle SPECIES_ENTEI, 30
# 9 "data/maps/ScorchedCavern/scripts.pory"
	dowildbattle
	return

