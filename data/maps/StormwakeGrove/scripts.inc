StormwakeGrove_MapScripts::
	.byte 0


RaikouFight::
# 6 "data/maps/StormwakeGrove/scripts.pory"
	goto_if_unset FLAG_RAIKOU, RaikouFight_1
	return

RaikouFight_1:
# 7 "data/maps/StormwakeGrove/scripts.pory"
	setflag FLAG_RAIKOU
# 8 "data/maps/StormwakeGrove/scripts.pory"
	setwildbattle FLAG_RAIKOU, 30
# 9 "data/maps/StormwakeGrove/scripts.pory"
	dowildbattle
	return

