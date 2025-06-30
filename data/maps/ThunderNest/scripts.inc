ThunderNest_MapScripts::
# 2 "data/maps/ThunderNest/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, ThunderNest_CheckWarp
	.byte 0


ThunderNest_CheckWarp::
# 6 "data/maps/ThunderNest/scripts.pory"
	specialvar VAR_RESULT, CheckVoltorb
# 7 "data/maps/ThunderNest/scripts.pory"
	compare VAR_RESULT, SPECIES_VOLTORB
	goto_if_eq ThunderNest_CheckWarp_1
	return

ThunderNest_CheckWarp_1:
# 8 "data/maps/ThunderNest/scripts.pory"
	setdynamicwarp 0, 63, 31, 37
# 9 "data/maps/ThunderNest/scripts.pory"
	setdynamicwarp 0, 63, 11, 12
	return

