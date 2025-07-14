ThunderNest_MapScripts::
# 2 "data/maps/ThunderNest/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, ThunderNest_CheckWarp
	.byte 0


ThunderNest_CheckWarp::
# 6 "data/maps/ThunderNest/scripts.pory"
	specialvar VAR_RESULT, CheckVoltorb
# 7 "data/maps/ThunderNest/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne ThunderNest_CheckWarp_1
	return

ThunderNest_CheckWarp_1:
# 8 "data/maps/ThunderNest/scripts.pory"
	setdynamicwarp 0, 63, 31, 37
# 9 "data/maps/ThunderNest/scripts.pory"
	setdynamicwarp 0, 63, 11, 12
	return


ZapdosFight::
# 14 "data/maps/ThunderNest/scripts.pory"
	goto_if_unset FLAG_ZAPDOS, ZapdosFight_1
	return

ZapdosFight_1:
# 15 "data/maps/ThunderNest/scripts.pory"
	setflag FLAG_ZAPDOS
# 16 "data/maps/ThunderNest/scripts.pory"
	setwildbattle SPECIES_ZAPDOS, 30
# 17 "data/maps/ThunderNest/scripts.pory"
	dowildbattle
	return


voltorbsign::
# 26 "data/maps/ThunderNest/scripts.pory"
	lockall
# 27 "data/maps/ThunderNest/scripts.pory"
	msgbox puzzlevoltorb
# 28 "data/maps/ThunderNest/scripts.pory"
	waitmessage
# 29 "data/maps/ThunderNest/scripts.pory"
	releaseall
	end


puzzlevoltorb::
# 21 "data/maps/ThunderNest/scripts.pory"
	.string "In circuits and spheres, I dwell unseen,\n A spark in your pocket, round and keen.\p To open this path, let energy surge\nBring the living orb.$"
