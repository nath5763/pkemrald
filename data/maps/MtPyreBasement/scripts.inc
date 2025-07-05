MtPyreBasement_MapScripts::
	.byte 0


mewtwoFight::
# 10 "data/maps/MtPyreBasement/scripts.pory"
	lockall
# 11 "data/maps/MtPyreBasement/scripts.pory"
	specialvar VAR_RESULT, CheckMew
# 12 "data/maps/MtPyreBasement/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne mewtwoFight_4
mewtwoFight_3:
# 17 "data/maps/MtPyreBasement/scripts.pory"
	msgbox mewtwoPuzzle
# 18 "data/maps/MtPyreBasement/scripts.pory"
	waitmessage
mewtwoFight_1:
# 20 "data/maps/MtPyreBasement/scripts.pory"
	releaseall
	end

mewtwoFight_2:
# 13 "data/maps/MtPyreBasement/scripts.pory"
	setflag FLAG_MEWTWO
# 14 "data/maps/MtPyreBasement/scripts.pory"
	setwildbattle SPECIES_MEWTWO, 70
# 15 "data/maps/MtPyreBasement/scripts.pory"
	dowildbattle
	goto mewtwoFight_1

mewtwoFight_4:
# 12 "data/maps/MtPyreBasement/scripts.pory"
	goto_if_unset FLAG_MEWTWO, mewtwoFight_2
	goto mewtwoFight_3


mewtwoPuzzle::
# 5 "data/maps/MtPyreBasement/scripts.pory"
	.string "When crowned by might and battles won,\nAnd journey's thread at last is spun,\pThe one who holds all forms in seed,\nShall wake the path where none yet lead.$"
