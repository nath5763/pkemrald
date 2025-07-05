MtPyreBasement_MapScripts::
	.byte 0


mewtwoHint::
# 10 "data/maps/MtPyreBasement/scripts.pory"
	lockall
	return


mewtwoFight::
# 15 "data/maps/MtPyreBasement/scripts.pory"
	lockall
# 16 "data/maps/MtPyreBasement/scripts.pory"
	specialvar VAR_RESULT, CheckMew
# 17 "data/maps/MtPyreBasement/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne mewtwoFight_4
mewtwoFight_3:
# 22 "data/maps/MtPyreBasement/scripts.pory"
	msgbox mewtwoPuzzle
# 23 "data/maps/MtPyreBasement/scripts.pory"
	waitmessage
mewtwoFight_1:
# 25 "data/maps/MtPyreBasement/scripts.pory"
	releaseall
	end

mewtwoFight_2:
# 18 "data/maps/MtPyreBasement/scripts.pory"
	setflag FLAG_MEWTWO
# 19 "data/maps/MtPyreBasement/scripts.pory"
	setwildbattle SPECIES_MEWTWO, 70
# 20 "data/maps/MtPyreBasement/scripts.pory"
	dowildbattle
	goto mewtwoFight_1

mewtwoFight_4:
# 17 "data/maps/MtPyreBasement/scripts.pory"
	goto_if_set FLAG_MEWTWO, mewtwoFight_2
	goto mewtwoFight_3


mewtwoPuzzle::
# 5 "data/maps/MtPyreBasement/scripts.pory"
	.string "When crowned by might and battles won,\nAnd journey's thread at last is spun,\pThe one who holds all forms in seed,\nShall wake the path where none yet lead.$"
