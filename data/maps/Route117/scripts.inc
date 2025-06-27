# 1 "data/maps/Route117/scripts.pory"

# 2 "data/maps/Route117/scripts.pory"
Route117_MapScripts::
# 3 "data/maps/Route117/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_OnTransition
# 4 "data/maps/Route117/scripts.pory"
	.byte 0
# 5 "data/maps/Route117/scripts.pory"

# 6 "data/maps/Route117/scripts.pory"
Route117_OnTransition:
# 7 "data/maps/Route117/scripts.pory"
	call Route117_EventScript_TryMoveDayCareMan
# 8 "data/maps/Route117/scripts.pory"
	end
# 9 "data/maps/Route117/scripts.pory"

# 10 "data/maps/Route117/scripts.pory"
Route117_EventScript_TryMoveDayCareMan::
# 11 "data/maps/Route117/scripts.pory"
	goto_if_unset FLAG_PENDING_DAYCARE_EGG, Route117_EventScript_StopMoveDayCareMan
# 12 "data/maps/Route117/scripts.pory"
	setobjectxyperm LOCALID_DAYCARE_MAN, 47, 6
# 13 "data/maps/Route117/scripts.pory"
Route117_EventScript_StopMoveDayCareMan::
# 14 "data/maps/Route117/scripts.pory"
	return
# 15 "data/maps/Route117/scripts.pory"

# 16 "data/maps/Route117/scripts.pory"
Route117_EventScript_Woman::
# 17 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_ArentTheseFlowersPretty, MSGBOX_NPC
# 18 "data/maps/Route117/scripts.pory"
	end
# 19 "data/maps/Route117/scripts.pory"

# 20 "data/maps/Route117/scripts.pory"
Route117_EventScript_LittleBoy::
# 21 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_AirIsTastyHere, MSGBOX_NPC
# 22 "data/maps/Route117/scripts.pory"
	end
# 23 "data/maps/Route117/scripts.pory"

# 24 "data/maps/Route117/scripts.pory"
Route117_EventScript_Girl::
# 25 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_DayCarePokemonHadNewMove, MSGBOX_NPC
# 26 "data/maps/Route117/scripts.pory"
	end
# 27 "data/maps/Route117/scripts.pory"

# 28 "data/maps/Route117/scripts.pory"
Route117_EventScript_RouteSignVerdanturf::
# 29 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_RouteSignVerdanturf, MSGBOX_SIGN
# 30 "data/maps/Route117/scripts.pory"
	end
# 31 "data/maps/Route117/scripts.pory"

# 32 "data/maps/Route117/scripts.pory"
Route117_EventScript_RouteSignMauville::
# 33 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_RouteSignMauville, MSGBOX_SIGN
# 34 "data/maps/Route117/scripts.pory"
	end
# 35 "data/maps/Route117/scripts.pory"

# 36 "data/maps/Route117/scripts.pory"
Route117_EventScript_DayCareSign::
# 37 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_DayCareSign, MSGBOX_SIGN
# 38 "data/maps/Route117/scripts.pory"
	end
# 39 "data/maps/Route117/scripts.pory"

# 40 "data/maps/Route117/scripts.pory"
Route117_EventScript_Isaac::
# 41 "data/maps/Route117/scripts.pory"
	trainerbattle_single TRAINER_ISAAC_1, Route117_Text_IsaacIntro, Route117_Text_IsaacDefeat, Route117_EventScript_RegisterIsaac
# 42 "data/maps/Route117/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 43 "data/maps/Route117/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route117_EventScript_RematchIsaac
# 44 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_IsaacPostBattle, MSGBOX_DEFAULT
# 45 "data/maps/Route117/scripts.pory"
	release
# 46 "data/maps/Route117/scripts.pory"
	end
# 47 "data/maps/Route117/scripts.pory"

# 48 "data/maps/Route117/scripts.pory"
Route117_EventScript_RegisterIsaac::
# 49 "data/maps/Route117/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 50 "data/maps/Route117/scripts.pory"
	waitmovement 0
# 51 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_IsaacRegister, MSGBOX_DEFAULT
# 52 "data/maps/Route117/scripts.pory"
	register_matchcall TRAINER_ISAAC_1
# 53 "data/maps/Route117/scripts.pory"
	release
# 54 "data/maps/Route117/scripts.pory"
	end
# 55 "data/maps/Route117/scripts.pory"

# 56 "data/maps/Route117/scripts.pory"
Route117_EventScript_RematchIsaac::
# 57 "data/maps/Route117/scripts.pory"
	trainerbattle_rematch TRAINER_ISAAC_1, Route117_Text_IsaacRematchIntro, Route117_Text_IsaacRematchDefeat
# 58 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_IsaacPostRematch, MSGBOX_AUTOCLOSE
# 59 "data/maps/Route117/scripts.pory"
	end
# 60 "data/maps/Route117/scripts.pory"

# 61 "data/maps/Route117/scripts.pory"
Route117_EventScript_Lydia::
# 62 "data/maps/Route117/scripts.pory"
	trainerbattle_single TRAINER_LYDIA_1, Route117_Text_LydiaIntro, Route117_Text_LydiaDefeat, Route117_EventScript_RegisterLydia
# 63 "data/maps/Route117/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 64 "data/maps/Route117/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route117_EventScript_RematchLydia
# 65 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_LydiaPostBattle, MSGBOX_DEFAULT
# 66 "data/maps/Route117/scripts.pory"
	release
# 67 "data/maps/Route117/scripts.pory"
	end
# 68 "data/maps/Route117/scripts.pory"

# 69 "data/maps/Route117/scripts.pory"
Route117_EventScript_RegisterLydia::
# 70 "data/maps/Route117/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 71 "data/maps/Route117/scripts.pory"
	waitmovement 0
# 72 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_LydiaRegister, MSGBOX_DEFAULT
# 73 "data/maps/Route117/scripts.pory"
	register_matchcall TRAINER_LYDIA_1
# 74 "data/maps/Route117/scripts.pory"
	release
# 75 "data/maps/Route117/scripts.pory"
	end
# 76 "data/maps/Route117/scripts.pory"

# 77 "data/maps/Route117/scripts.pory"
Route117_EventScript_RematchLydia::
# 78 "data/maps/Route117/scripts.pory"
	trainerbattle_rematch TRAINER_LYDIA_1, Route117_Text_LydiaRematchIntro, Route117_Text_LydiaRematchDefeat
# 79 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_LydiaPostRematch, MSGBOX_AUTOCLOSE
# 80 "data/maps/Route117/scripts.pory"
	end
# 81 "data/maps/Route117/scripts.pory"

# 82 "data/maps/Route117/scripts.pory"
Route117_EventScript_Dylan::
# 83 "data/maps/Route117/scripts.pory"
	trainerbattle_single TRAINER_DYLAN_1, Route117_Text_DylanIntro, Route117_Text_DylanDefeat, Route117_EventScript_RegisterDylan
# 84 "data/maps/Route117/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 85 "data/maps/Route117/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route117_EventScript_RematchDylan
# 86 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_DylanPostBattle, MSGBOX_DEFAULT
# 87 "data/maps/Route117/scripts.pory"
	release
# 88 "data/maps/Route117/scripts.pory"
	end
# 89 "data/maps/Route117/scripts.pory"

# 90 "data/maps/Route117/scripts.pory"
Route117_EventScript_RegisterDylan::
# 91 "data/maps/Route117/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 92 "data/maps/Route117/scripts.pory"
	waitmovement 0
# 93 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_DylanRegister, MSGBOX_DEFAULT
# 94 "data/maps/Route117/scripts.pory"
	register_matchcall TRAINER_DYLAN_1
# 95 "data/maps/Route117/scripts.pory"
	release
# 96 "data/maps/Route117/scripts.pory"
	end
# 97 "data/maps/Route117/scripts.pory"

# 98 "data/maps/Route117/scripts.pory"
Route117_EventScript_RematchDylan::
# 99 "data/maps/Route117/scripts.pory"
	trainerbattle_rematch TRAINER_DYLAN_1, Route117_Text_DylanRematchIntro, Route117_Text_DylanRematchDefeat
# 100 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_DylanPostRematch, MSGBOX_AUTOCLOSE
# 101 "data/maps/Route117/scripts.pory"
	end
# 102 "data/maps/Route117/scripts.pory"

# 103 "data/maps/Route117/scripts.pory"
Route117_EventScript_Maria::
# 104 "data/maps/Route117/scripts.pory"
	trainerbattle_single TRAINER_MARIA_1, Route117_Text_MariaIntro, Route117_Text_MariaDefeat, Route117_EventScript_RegisterMaria
# 105 "data/maps/Route117/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 106 "data/maps/Route117/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route117_EventScript_RematchMaria
# 107 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_MariaPostBattle, MSGBOX_DEFAULT
# 108 "data/maps/Route117/scripts.pory"
	release
# 109 "data/maps/Route117/scripts.pory"
	end
# 110 "data/maps/Route117/scripts.pory"

# 111 "data/maps/Route117/scripts.pory"
Route117_EventScript_RegisterMaria::
# 112 "data/maps/Route117/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 113 "data/maps/Route117/scripts.pory"
	waitmovement 0
# 114 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_MariaRegister, MSGBOX_DEFAULT
# 115 "data/maps/Route117/scripts.pory"
	register_matchcall TRAINER_MARIA_1
# 116 "data/maps/Route117/scripts.pory"
	release
# 117 "data/maps/Route117/scripts.pory"
	end
# 118 "data/maps/Route117/scripts.pory"

# 119 "data/maps/Route117/scripts.pory"
Route117_EventScript_RematchMaria::
# 120 "data/maps/Route117/scripts.pory"
	trainerbattle_rematch TRAINER_MARIA_1, Route117_Text_MariaRematchIntro, Route117_Text_MariaRematchDefeat
# 121 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_MariaPostRematch, MSGBOX_AUTOCLOSE
# 122 "data/maps/Route117/scripts.pory"
	end
# 123 "data/maps/Route117/scripts.pory"

# 124 "data/maps/Route117/scripts.pory"
Route117_EventScript_Derek::
# 125 "data/maps/Route117/scripts.pory"
	trainerbattle_single TRAINER_DEREK, Route117_Text_DerekIntro, Route117_Text_DerekDefeat
# 126 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_DerekPostBattle, MSGBOX_AUTOCLOSE
# 127 "data/maps/Route117/scripts.pory"
	end
# 128 "data/maps/Route117/scripts.pory"

# 129 "data/maps/Route117/scripts.pory"
Route117_EventScript_Anna::
# 130 "data/maps/Route117/scripts.pory"
	trainerbattle_double TRAINER_ANNA_AND_MEG_1, Route117_Text_AnnaIntro, Route117_Text_AnnaDefeat, Route117_Text_AnnaNotEnoughMons, Route117_EventScript_RegisterAnna
# 131 "data/maps/Route117/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 132 "data/maps/Route117/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route117_EventScript_RematchAnna
# 133 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_AnnaPostBattle, MSGBOX_DEFAULT
# 134 "data/maps/Route117/scripts.pory"
	release
# 135 "data/maps/Route117/scripts.pory"
	end
# 136 "data/maps/Route117/scripts.pory"

# 137 "data/maps/Route117/scripts.pory"
Route117_EventScript_RegisterAnna::
# 138 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_AnnaAndMegRegister, MSGBOX_DEFAULT
# 139 "data/maps/Route117/scripts.pory"
	register_matchcall TRAINER_ANNA_AND_MEG_1
# 140 "data/maps/Route117/scripts.pory"
	release
# 141 "data/maps/Route117/scripts.pory"
	end
# 142 "data/maps/Route117/scripts.pory"

# 143 "data/maps/Route117/scripts.pory"
Route117_EventScript_RematchAnna::
# 144 "data/maps/Route117/scripts.pory"
	trainerbattle_rematch_double TRAINER_ANNA_AND_MEG_1, Route117_Text_AnnaRematchIntro, Route117_Text_AnnaRematchDefeat, Route117_Text_AnnaRematchNotEnoughMons
# 145 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_AnnaPostRematch, MSGBOX_AUTOCLOSE
# 146 "data/maps/Route117/scripts.pory"
	end
# 147 "data/maps/Route117/scripts.pory"

# 148 "data/maps/Route117/scripts.pory"
Route117_EventScript_Meg::
# 149 "data/maps/Route117/scripts.pory"
	trainerbattle_double TRAINER_ANNA_AND_MEG_1, Route117_Text_MegIntro, Route117_Text_MegDefeat, Route117_Text_MegNotEnoughMons, Route117_EventScript_RegisterMeg
# 150 "data/maps/Route117/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 151 "data/maps/Route117/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route117_EventScript_RematchMeg
# 152 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_MegPostBattle, MSGBOX_DEFAULT
# 153 "data/maps/Route117/scripts.pory"
	release
# 154 "data/maps/Route117/scripts.pory"
	end
# 155 "data/maps/Route117/scripts.pory"

# 156 "data/maps/Route117/scripts.pory"
Route117_EventScript_RegisterMeg::
# 157 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_AnnaAndMegRegister, MSGBOX_DEFAULT
# 158 "data/maps/Route117/scripts.pory"
	register_matchcall TRAINER_ANNA_AND_MEG_1
# 159 "data/maps/Route117/scripts.pory"
	release
# 160 "data/maps/Route117/scripts.pory"
	end
# 161 "data/maps/Route117/scripts.pory"

# 162 "data/maps/Route117/scripts.pory"
Route117_EventScript_RematchMeg::
# 163 "data/maps/Route117/scripts.pory"
	trainerbattle_rematch_double TRAINER_ANNA_AND_MEG_1, Route117_Text_MegRematchIntro, Route117_Text_MegRematchDefeat, Route117_Text_MegRematchNotEnoughMons
# 164 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_MegPostRematch, MSGBOX_AUTOCLOSE
# 165 "data/maps/Route117/scripts.pory"
	end
# 166 "data/maps/Route117/scripts.pory"

# 167 "data/maps/Route117/scripts.pory"
Route117_EventScript_Melina::
# 168 "data/maps/Route117/scripts.pory"
	trainerbattle_single TRAINER_MELINA, Route117_Text_MelinaIntro, Route117_Text_MelinaDefeat
# 169 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_MelinaPostBattle, MSGBOX_AUTOCLOSE
# 170 "data/maps/Route117/scripts.pory"
	end
# 171 "data/maps/Route117/scripts.pory"

# 172 "data/maps/Route117/scripts.pory"
Route117_EventScript_Brandi::
# 173 "data/maps/Route117/scripts.pory"
	trainerbattle_single TRAINER_BRANDI, Route117_Text_BrandiIntro, Route117_Text_BrandiDefeat
# 174 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_BrandiPostBattle, MSGBOX_AUTOCLOSE
# 175 "data/maps/Route117/scripts.pory"
	end
# 176 "data/maps/Route117/scripts.pory"

# 177 "data/maps/Route117/scripts.pory"
Route117_EventScript_Aisha::
# 178 "data/maps/Route117/scripts.pory"
	trainerbattle_single TRAINER_AISHA, Route117_Text_AishaIntro, Route117_Text_AishaDefeat
# 179 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_AishaPostBattle, MSGBOX_AUTOCLOSE
# 180 "data/maps/Route117/scripts.pory"
	end
# 181 "data/maps/Route117/scripts.pory"

# 182 "data/maps/Route117/scripts.pory"
Route117_Text_DayCarePokemonHadNewMove:
# 183 "data/maps/Route117/scripts.pory"
	.string "I left my POKéMON at the DAY CARE.\p"
# 184 "data/maps/Route117/scripts.pory"
	.string "When I got it back, it had a new move\n"
# 185 "data/maps/Route117/scripts.pory"
	.string "that I didn't teach it.\l"
# 186 "data/maps/Route117/scripts.pory"
	.string "I was really, really surprised.$"
# 187 "data/maps/Route117/scripts.pory"

# 188 "data/maps/Route117/scripts.pory"
Route117_Text_ArentTheseFlowersPretty:
# 189 "data/maps/Route117/scripts.pory"
	.string "What do you think?\n"
# 190 "data/maps/Route117/scripts.pory"
	.string "Aren't these flowers pretty?\p"
# 191 "data/maps/Route117/scripts.pory"
	.string "I planted them all!$"
# 192 "data/maps/Route117/scripts.pory"

# 193 "data/maps/Route117/scripts.pory"
Route117_Text_AirIsTastyHere:
# 194 "data/maps/Route117/scripts.pory"
	.string "The air is tasty here!$"
# 195 "data/maps/Route117/scripts.pory"

# 196 "data/maps/Route117/scripts.pory"
Route117_Text_RouteSignVerdanturf:
# 197 "data/maps/Route117/scripts.pory"
	.string "ROUTE 117\n"
# 198 "data/maps/Route117/scripts.pory"
	.string "{LEFT_ARROW} VERDANTURF TOWN$"
# 199 "data/maps/Route117/scripts.pory"

# 200 "data/maps/Route117/scripts.pory"
Route117_Text_RouteSignMauville:
# 201 "data/maps/Route117/scripts.pory"
	.string "ROUTE 117\n"
# 202 "data/maps/Route117/scripts.pory"
	.string "{RIGHT_ARROW} MAUVILLE CITY$"
# 203 "data/maps/Route117/scripts.pory"

# 204 "data/maps/Route117/scripts.pory"
Route117_Text_DayCareSign:
# 205 "data/maps/Route117/scripts.pory"
	.string "POKéMON DAY CARE\n"
# 206 "data/maps/Route117/scripts.pory"
	.string "“Let us raise your POKéMON.”$"
