# 1 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 2 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_MapScripts::
# 3 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.byte 0
# 4 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 5 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_EventScript_MoveRelearner::
# 6 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	lockall
# 7 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
# 8 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	waitmovement 0
# 9 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_set FLAG_TEMP_1, FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
# 10 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
# 11 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_TEMP_1
# 12 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
# 13 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 14 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 15 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove::
# 16 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
# 17 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	switch VAR_RESULT
# 18 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case NO, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
# 19 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
# 20 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 21 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 22 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon::
# 23 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
# 24 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special ChooseMonForMoveRelearner
# 25 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	waitstate
# 26 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
# 27 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special IsSelectedMonEgg
# 28 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg
# 29 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq VAR_0x8005, 0, FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
# 30 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove
# 31 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 32 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 33 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove::
# 34 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
# 35 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special TeachMoveRelearnerMove
# 36 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	waitstate
# 37 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, 0, FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
# 38 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
# 39 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
# 40 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 41 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 42 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon::
# 43 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
# 44 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
# 45 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 46 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 47 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg::
# 48 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
# 49 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
# 50 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 51 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 52 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale::
# 53 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
# 54 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
# 55 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 56 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 57 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor:
# 58 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I'm the MOVE TUTOR.\p"
# 59 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I know all the moves that POKéMON\n"
# 60 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "learn--every one of them--and I can\l"
# 61 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "teach POKéMON those moves.\p"
# 62 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I can teach a move to a POKéMON\n"
# 63 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "of yours if you'd like.\p"
# 64 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I'll do it for FREE.$"
# 65 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 66 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove:
# 67 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Oh! That's it! That's an honest to\n"
# 68 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "goodness FREEDOM!\p"
# 69 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Let me guess, you want me to teach\n"
# 70 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "a move?$"
# 71 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 72 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon:
# 73 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Which POKéMON needs tutoring?$"
# 74 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 75 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove:
# 76 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Which move should I teach?$"
# 77 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 78 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon:
# 79 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Sorry…\p"
# 80 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "It doesn't appear as if I have any move\n"
# 81 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I can teach that POKéMON.$"
# 82 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 83 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale:
# 84 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{PLAYER} handed over one FREEDOM UNIT\n"
# 85 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "in exchange.$"
# 86 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 87 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale:
# 88 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "If your POKéMON need to learn a move,\n"
# 89 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "come back with a FREEDOM UNIT.$"
# 90 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 91 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg:
# 92 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Hunh? There isn't a single move that\n"
# 93 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I can teach an EGG.$"
