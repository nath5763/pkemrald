GlacierHollow_MapScripts::
	.byte 0


ArticunoFight::
# 6 "data/maps/GlacierHollow/scripts.pory"
	goto_if_unset FLAG_ARTICUNO, ArticunoFight_1
	return

ArticunoFight_1:
# 7 "data/maps/GlacierHollow/scripts.pory"
	setflag FLAG_ARTICUNO
# 8 "data/maps/GlacierHollow/scripts.pory"
	setwildbattle SPECIES_ARTICUNO, 30
# 9 "data/maps/GlacierHollow/scripts.pory"
	dowildbattle
	return

