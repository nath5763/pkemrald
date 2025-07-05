AshenRoost_MapScripts::
	.byte 0


MoltresFight::
# 6 "data/maps/AshenRoost/scripts.pory"
	goto_if_unset FLAG_MOLTRES, MoltresFight_1
	return

MoltresFight_1:
# 7 "data/maps/AshenRoost/scripts.pory"
	setflag FLAG_MOLTRES
# 8 "data/maps/AshenRoost/scripts.pory"
	setwildbattle SPECIES_MOLTRES, 30
# 9 "data/maps/AshenRoost/scripts.pory"
	dowildbattle
	return

