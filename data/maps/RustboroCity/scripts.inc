# 1 "data/maps/RustboroCity/scripts.pory"

# 2 "data/maps/RustboroCity/scripts.pory"
RustboroCity_MapScripts::
# 3 "data/maps/RustboroCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_OnTransition
# 4 "data/maps/RustboroCity/scripts.pory"
	.byte 0
# 5 "data/maps/RustboroCity/scripts.pory"

# 6 "data/maps/RustboroCity/scripts.pory"
RustboroCity_OnTransition:
# 7 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_VISITED_RUSTBORO_CITY
# 8 "data/maps/RustboroCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 9 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_HideMapNamePopup
# 10 "data/maps/RustboroCity/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 11 "data/maps/RustboroCity/scripts.pory"
	end
# 12 "data/maps/RustboroCity/scripts.pory"

# 13 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HideMapNamePopup::
# 14 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 15 "data/maps/RustboroCity/scripts.pory"
	return
# 16 "data/maps/RustboroCity/scripts.pory"

# 17 "data/maps/RustboroCity/scripts.pory"

# 18 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_PlayerWalkDown:
# 19 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 20 "data/maps/RustboroCity/scripts.pory"
	step_end
# 21 "data/maps/RustboroCity/scripts.pory"

# 22 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_FatMan::
# 23 "data/maps/RustboroCity/scripts.pory"
	lock
# 24 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 25 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_EventScript_FatManSawGrunt
# 26 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WeShortenItToDevon, MSGBOX_DEFAULT
# 27 "data/maps/RustboroCity/scripts.pory"
	release
# 28 "data/maps/RustboroCity/scripts.pory"
	end
# 29 "data/maps/RustboroCity/scripts.pory"

# 30 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_FatManSawGrunt::
# 31 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_SneakyLookingManWentAroundCorner, MSGBOX_DEFAULT
# 32 "data/maps/RustboroCity/scripts.pory"
	release
# 33 "data/maps/RustboroCity/scripts.pory"
	end
# 34 "data/maps/RustboroCity/scripts.pory"

# 35 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonEmployee2::
# 36 "data/maps/RustboroCity/scripts.pory"
	lock
# 37 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 38 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureNewAroundHere, MSGBOX_DEFAULT
# 39 "data/maps/RustboroCity/scripts.pory"
	release
# 40 "data/maps/RustboroCity/scripts.pory"
	end
# 41 "data/maps/RustboroCity/scripts.pory"

# 42 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Woman::
# 43 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GymLeaderIsntEasyWithFire, MSGBOX_NPC
# 44 "data/maps/RustboroCity/scripts.pory"
	end
# 45 "data/maps/RustboroCity/scripts.pory"

# 46 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man1::
# 47 "data/maps/RustboroCity/scripts.pory"
	lock
# 48 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 49 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_EventScript_Man1HaveBadge
# 50 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HaveYouChallengedGym, MSGBOX_DEFAULT
# 51 "data/maps/RustboroCity/scripts.pory"
	release
# 52 "data/maps/RustboroCity/scripts.pory"
	end
# 53 "data/maps/RustboroCity/scripts.pory"

# 54 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man1HaveBadge::
# 55 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HeyThatsRustborosGymBadge, MSGBOX_DEFAULT
# 56 "data/maps/RustboroCity/scripts.pory"
	release
# 57 "data/maps/RustboroCity/scripts.pory"
	end
# 58 "data/maps/RustboroCity/scripts.pory"

# 59 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy2::
# 60 "data/maps/RustboroCity/scripts.pory"
	lock
# 61 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 62 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_EventScript_Boy2BrineyLeftTunnel
# 63 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MrBrineyWalksInTheTunnel, MSGBOX_DEFAULT
# 64 "data/maps/RustboroCity/scripts.pory"
	release
# 65 "data/maps/RustboroCity/scripts.pory"
	end
# 66 "data/maps/RustboroCity/scripts.pory"

# 67 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy2BrineyLeftTunnel::
# 68 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MrBrineyLovesPeeko, MSGBOX_DEFAULT
# 69 "data/maps/RustboroCity/scripts.pory"
	release
# 70 "data/maps/RustboroCity/scripts.pory"
	end
# 71 "data/maps/RustboroCity/scripts.pory"

# 72 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Twin::
# 73 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WowYouHavePokemon, MSGBOX_NPC
# 74 "data/maps/RustboroCity/scripts.pory"
	end
# 75 "data/maps/RustboroCity/scripts.pory"

# 76 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_NinjaBoy::
# 77 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CatchRarePokemonIfIGoToSchool, MSGBOX_SIGN
# 78 "data/maps/RustboroCity/scripts.pory"
	end
# 79 "data/maps/RustboroCity/scripts.pory"

# 80 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_TunnelSign::
# 81 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TunnelNearingCompletion, MSGBOX_SIGN
# 82 "data/maps/RustboroCity/scripts.pory"
	end
# 83 "data/maps/RustboroCity/scripts.pory"

# 84 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonCorpSign::
# 85 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonCorpSign, MSGBOX_SIGN
# 86 "data/maps/RustboroCity/scripts.pory"
	end
# 87 "data/maps/RustboroCity/scripts.pory"

# 88 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_GymSign::
# 89 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GymSign, MSGBOX_SIGN
# 90 "data/maps/RustboroCity/scripts.pory"
	end
# 91 "data/maps/RustboroCity/scripts.pory"

# 92 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 93 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonCorpBranchOfficeSign::
# 94 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonCorpBranchOfficeSign, MSGBOX_SIGN
# 95 "data/maps/RustboroCity/scripts.pory"
	end
# 96 "data/maps/RustboroCity/scripts.pory"

# 97 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_CitySign::
# 98 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CitySign, MSGBOX_SIGN
# 99 "data/maps/RustboroCity/scripts.pory"
	end
# 100 "data/maps/RustboroCity/scripts.pory"

# 101 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_TrainersSchoolSign::
# 102 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TrainersSchoolSign, MSGBOX_SIGN
# 103 "data/maps/RustboroCity/scripts.pory"
	end
# 104 "data/maps/RustboroCity/scripts.pory"

# 105 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_CuttersHouseSign::
# 106 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CuttersHouse, MSGBOX_SIGN
# 107 "data/maps/RustboroCity/scripts.pory"
	end
# 108 "data/maps/RustboroCity/scripts.pory"

# 109 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_LittleBoy::
# 110 "data/maps/RustboroCity/scripts.pory"
	lock
# 111 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 112 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PokemonCanChangeLookFromExp, MSGBOX_DEFAULT
# 113 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_LITTLE_BOY, Common_Movement_FaceOriginalDirection
# 114 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 115 "data/maps/RustboroCity/scripts.pory"
	release
# 116 "data/maps/RustboroCity/scripts.pory"
	end
# 117 "data/maps/RustboroCity/scripts.pory"

# 118 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_LittleGirl::
# 119 "data/maps/RustboroCity/scripts.pory"
	lock
# 120 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 121 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PokemonChangeShape, MSGBOX_DEFAULT
# 122 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_LITTLE_GIRL, Common_Movement_FaceOriginalDirection
# 123 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 124 "data/maps/RustboroCity/scripts.pory"
	release
# 125 "data/maps/RustboroCity/scripts.pory"
	end
# 126 "data/maps/RustboroCity/scripts.pory"

# 127 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man2::
# 128 "data/maps/RustboroCity/scripts.pory"
	lock
# 129 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 130 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TradePokemonGrowFast, MSGBOX_DEFAULT
# 131 "data/maps/RustboroCity/scripts.pory"
	release
# 132 "data/maps/RustboroCity/scripts.pory"
	end
# 133 "data/maps/RustboroCity/scripts.pory"

# 134 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger0::
# 135 "data/maps/RustboroCity/scripts.pory"
	lockall
# 136 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 137 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 138 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 0
# 139 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 140 "data/maps/RustboroCity/scripts.pory"
	end
# 141 "data/maps/RustboroCity/scripts.pory"

# 142 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger1::
# 143 "data/maps/RustboroCity/scripts.pory"
	lockall
# 144 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 145 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 146 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 1
# 147 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 148 "data/maps/RustboroCity/scripts.pory"
	end
# 149 "data/maps/RustboroCity/scripts.pory"

# 150 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger2::
# 151 "data/maps/RustboroCity/scripts.pory"
	lockall
# 152 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 153 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 154 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 2
# 155 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 156 "data/maps/RustboroCity/scripts.pory"
	end
# 157 "data/maps/RustboroCity/scripts.pory"

# 158 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger3::
# 159 "data/maps/RustboroCity/scripts.pory"
	lockall
# 160 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 161 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 162 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 3
# 163 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 164 "data/maps/RustboroCity/scripts.pory"
	end
# 165 "data/maps/RustboroCity/scripts.pory"

# 166 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger4::
# 167 "data/maps/RustboroCity/scripts.pory"
	lockall
# 168 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 169 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 170 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 4
# 171 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 172 "data/maps/RustboroCity/scripts.pory"
	end
# 173 "data/maps/RustboroCity/scripts.pory"

# 174 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsScene::
# 175 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_OutOfTheWay, MSGBOX_DEFAULT
# 176 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 177 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 178 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_RUSTBORO_GRUNT
# 179 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_RUSTBORO_DEVON_EMPLOYEE
# 180 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_GRUNT, RustboroCity_Movement_GruntEscape
# 181 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 182 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_GRUNT
# 183 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt1
# 184 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 185 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WaitDontTakeMyGoods, MSGBOX_DEFAULT
# 186 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 187 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt2
# 188 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 189 "data/maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 190 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_DEVON_EMPLOYEE
# 191 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 30, 10
# 192 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 193 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEVON_GOODS_STOLEN
# 194 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 2
# 195 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 2
# 196 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE116_STATE, 1
# 197 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_116_MR_BRINEY
# 198 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
# 199 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
# 200 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
# 201 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
# 202 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 203 "data/maps/RustboroCity/scripts.pory"
	end
# 204 "data/maps/RustboroCity/scripts.pory"

# 205 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 206 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ShadyCharacterTookOff::
# 207 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 208 "data/maps/RustboroCity/scripts.pory"
	return
# 209 "data/maps/RustboroCity/scripts.pory"

# 210 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 211 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_YouGotItThankYou::
# 212 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 213 "data/maps/RustboroCity/scripts.pory"
	return
# 214 "data/maps/RustboroCity/scripts.pory"

# 215 "data/maps/RustboroCity/scripts.pory"
@ Unknown, unused employee movements. Based on the differences in movement theyre for approaching an object (probably the player) in different positions
# 216 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachUp::
# 217 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachUp
# 218 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 219 "data/maps/RustboroCity/scripts.pory"
	return
# 220 "data/maps/RustboroCity/scripts.pory"

# 221 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 222 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachLeft::
# 223 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachLeft
# 224 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 225 "data/maps/RustboroCity/scripts.pory"
	return
# 226 "data/maps/RustboroCity/scripts.pory"

# 227 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 228 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachRight::
# 229 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachRight
# 230 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 231 "data/maps/RustboroCity/scripts.pory"
	return
# 232 "data/maps/RustboroCity/scripts.pory"

# 233 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 234 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachDown::
# 235 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachDown
# 236 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 237 "data/maps/RustboroCity/scripts.pory"
	return
# 238 "data/maps/RustboroCity/scripts.pory"

# 239 "data/maps/RustboroCity/scripts.pory"
@ Unused, similar movement to the above scripts
# 240 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerFar::
# 241 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerFar
# 242 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 243 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 244 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 245 "data/maps/RustboroCity/scripts.pory"
	return
# 246 "data/maps/RustboroCity/scripts.pory"

# 247 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 248 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscapeExtended:
# 249 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 250 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 251 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 252 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 253 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 254 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 255 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 256 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 257 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 258 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 259 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 260 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 261 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 262 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 263 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 264 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 265 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 266 "data/maps/RustboroCity/scripts.pory"
	step_end
# 267 "data/maps/RustboroCity/scripts.pory"

# 268 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscape:
# 269 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 270 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 271 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 272 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 273 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 274 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 275 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 276 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 277 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 278 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 279 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 280 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 281 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 282 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 283 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 284 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 285 "data/maps/RustboroCity/scripts.pory"
	step_end
# 286 "data/maps/RustboroCity/scripts.pory"

# 287 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt1:
# 288 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 289 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 290 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 291 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 292 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 293 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 294 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_up
# 295 "data/maps/RustboroCity/scripts.pory"
	step_end
# 296 "data/maps/RustboroCity/scripts.pory"

# 297 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt2:
# 298 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 299 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 300 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 301 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 302 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 303 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 304 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 305 "data/maps/RustboroCity/scripts.pory"
	step_end
# 306 "data/maps/RustboroCity/scripts.pory"

# 307 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 308 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachUp:
# 309 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 310 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 311 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 312 "data/maps/RustboroCity/scripts.pory"
	step_end
# 313 "data/maps/RustboroCity/scripts.pory"

# 314 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 315 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachLeft:
# 316 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 317 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 318 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 319 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 320 "data/maps/RustboroCity/scripts.pory"
	step_end
# 321 "data/maps/RustboroCity/scripts.pory"

# 322 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 323 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachRight:
# 324 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 325 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 326 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 327 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 328 "data/maps/RustboroCity/scripts.pory"
	step_end
# 329 "data/maps/RustboroCity/scripts.pory"

# 330 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 331 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachDown:
# 332 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 333 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 334 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 335 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 336 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 337 "data/maps/RustboroCity/scripts.pory"
	step_end
# 338 "data/maps/RustboroCity/scripts.pory"

# 339 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 340 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerFar:
# 341 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 342 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 343 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 344 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 345 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 346 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 347 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_down
# 348 "data/maps/RustboroCity/scripts.pory"
	step_end
# 349 "data/maps/RustboroCity/scripts.pory"

# 350 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonEmployee1::
# 351 "data/maps/RustboroCity/scripts.pory"
	lock
# 352 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 353 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_EventScript_ReturnGoodsSpokeToEmployee
# 354 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 355 "data/maps/RustboroCity/scripts.pory"
	release
# 356 "data/maps/RustboroCity/scripts.pory"
	end
# 357 "data/maps/RustboroCity/scripts.pory"

# 358 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsSpokeToEmployee::
# 359 "data/maps/RustboroCity/scripts.pory"
	waitse
# 360 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 4
# 361 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 362 "data/maps/RustboroCity/scripts.pory"
	end
# 363 "data/maps/RustboroCity/scripts.pory"

# 364 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger0::
# 365 "data/maps/RustboroCity/scripts.pory"
	lockall
# 366 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 367 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 368 "data/maps/RustboroCity/scripts.pory"
	end
# 369 "data/maps/RustboroCity/scripts.pory"

# 370 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger1::
# 371 "data/maps/RustboroCity/scripts.pory"
	lockall
# 372 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 373 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 374 "data/maps/RustboroCity/scripts.pory"
	end
# 375 "data/maps/RustboroCity/scripts.pory"

# 376 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger2::
# 377 "data/maps/RustboroCity/scripts.pory"
	lockall
# 378 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 379 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 380 "data/maps/RustboroCity/scripts.pory"
	end
# 381 "data/maps/RustboroCity/scripts.pory"

# 382 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger3::
# 383 "data/maps/RustboroCity/scripts.pory"
	lockall
# 384 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 385 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 386 "data/maps/RustboroCity/scripts.pory"
	end
# 387 "data/maps/RustboroCity/scripts.pory"

# 388 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeAskToGetGoods::
# 389 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp1
# 390 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft1
# 391 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown1
# 392 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown1
# 393 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN
# 394 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 3
# 395 "data/maps/RustboroCity/scripts.pory"
	copyobjectxytoperm LOCALID_RUSTBORO_DEVON_EMPLOYEE
# 396 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HelpMeIWasRobbed, MSGBOX_DEFAULT
# 397 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 398 "data/maps/RustboroCity/scripts.pory"
	end
# 399 "data/maps/RustboroCity/scripts.pory"

# 400 "data/maps/RustboroCity/scripts.pory"
@ The below movement scripts are either partially or fully duplicated by the movement scripts when the player returns the goods
# 401 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerUp1::
# 402 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 403 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 404 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 405 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 406 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 407 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 408 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 409 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 410 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 411 "data/maps/RustboroCity/scripts.pory"
	return
# 412 "data/maps/RustboroCity/scripts.pory"

# 413 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerLeft1::
# 414 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
# 415 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 416 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 417 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 418 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 419 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 420 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 421 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
# 422 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 423 "data/maps/RustboroCity/scripts.pory"
	return
# 424 "data/maps/RustboroCity/scripts.pory"

# 425 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerDown1::
# 426 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 427 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 428 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 429 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 430 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 431 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 432 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 433 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 434 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 435 "data/maps/RustboroCity/scripts.pory"
	return
# 436 "data/maps/RustboroCity/scripts.pory"

# 437 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerDown1::
# 438 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 439 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 440 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 441 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 442 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 443 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 444 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 445 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
# 446 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 447 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 448 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 449 "data/maps/RustboroCity/scripts.pory"
	return
# 450 "data/maps/RustboroCity/scripts.pory"

# 451 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerDown:
# 452 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 453 "data/maps/RustboroCity/scripts.pory"
	step_end
# 454 "data/maps/RustboroCity/scripts.pory"

# 455 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger0::
# 456 "data/maps/RustboroCity/scripts.pory"
	lockall
# 457 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 458 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 459 "data/maps/RustboroCity/scripts.pory"
	end
# 460 "data/maps/RustboroCity/scripts.pory"

# 461 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger1::
# 462 "data/maps/RustboroCity/scripts.pory"
	lockall
# 463 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 464 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 465 "data/maps/RustboroCity/scripts.pory"
	end
# 466 "data/maps/RustboroCity/scripts.pory"

# 467 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger2::
# 468 "data/maps/RustboroCity/scripts.pory"
	lockall
# 469 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 470 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 471 "data/maps/RustboroCity/scripts.pory"
	end
# 472 "data/maps/RustboroCity/scripts.pory"

# 473 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger3::
# 474 "data/maps/RustboroCity/scripts.pory"
	lockall
# 475 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 476 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 477 "data/maps/RustboroCity/scripts.pory"
	end
# 478 "data/maps/RustboroCity/scripts.pory"

# 479 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoods::
# 480 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp2
# 481 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft2
# 482 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown2
# 483 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown2
# 484 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 4, RustboroCity_EventScript_EmployeeFacePlayerRight
# 485 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 486 "data/maps/RustboroCity/scripts.pory"
	giveitem ITEM_GREAT_BALL, 20
# 487 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, RustboroCity_EventScript_BagFull
# 488 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
# 489 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 490 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_RETURNED_DEVON_GOODS
# 491 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 492 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 5
# 493 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 494 "data/maps/RustboroCity/scripts.pory"
	warp MAP_RUSTBORO_CITY_DEVON_CORP_3F, 2, 2
# 495 "data/maps/RustboroCity/scripts.pory"
	waitstate
# 496 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 497 "data/maps/RustboroCity/scripts.pory"
	end
# 498 "data/maps/RustboroCity/scripts.pory"

# 499 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BagFull::
# 500 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
# 501 "data/maps/RustboroCity/scripts.pory"
	return
# 502 "data/maps/RustboroCity/scripts.pory"

# 503 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerUp2::
# 504 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 505 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 506 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 507 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 508 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 509 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 510 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 511 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 512 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 513 "data/maps/RustboroCity/scripts.pory"
	return
# 514 "data/maps/RustboroCity/scripts.pory"

# 515 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerLeft2::
# 516 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterRight
# 517 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 518 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 519 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 520 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 521 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 522 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 523 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
# 524 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 525 "data/maps/RustboroCity/scripts.pory"
	return
# 526 "data/maps/RustboroCity/scripts.pory"

# 527 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerDown2::
# 528 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 529 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 530 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 531 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 532 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 533 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 534 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 535 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 536 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 537 "data/maps/RustboroCity/scripts.pory"
	return
# 538 "data/maps/RustboroCity/scripts.pory"

# 539 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerDown2::
# 540 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 541 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 542 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 543 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 544 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 545 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 546 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 547 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
# 548 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 549 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 550 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 551 "data/maps/RustboroCity/scripts.pory"
	return
# 552 "data/maps/RustboroCity/scripts.pory"

# 553 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerRight::
# 554 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
# 555 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 556 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 557 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 558 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 559 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 560 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 561 "data/maps/RustboroCity/scripts.pory"
	return
# 562 "data/maps/RustboroCity/scripts.pory"

# 563 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Rival::
# 564 "data/maps/RustboroCity/scripts.pory"
	lockall
# 565 "data/maps/RustboroCity/scripts.pory"
	call_if_unset FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_PlayRivalMusic
# 566 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_FacePlayer
# 567 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 568 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 569 "data/maps/RustboroCity/scripts.pory"

# 570 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayRivalMusic::
# 571 "data/maps/RustboroCity/scripts.pory"
	checkplayergender
# 572 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_PlayMayMusic
# 573 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_PlayBrendanMusic
# 574 "data/maps/RustboroCity/scripts.pory"
	return
# 575 "data/maps/RustboroCity/scripts.pory"

# 576 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayMayMusic::
# 577 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 578 "data/maps/RustboroCity/scripts.pory"
	return
# 579 "data/maps/RustboroCity/scripts.pory"

# 580 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayBrendanMusic::
# 581 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 582 "data/maps/RustboroCity/scripts.pory"
	return
# 583 "data/maps/RustboroCity/scripts.pory"

# 584 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger0::
# 585 "data/maps/RustboroCity/scripts.pory"
	lockall
# 586 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 587 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 588 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 589 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 590 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 591 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 592 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 593 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 594 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer0
# 595 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 596 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 597 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 598 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 599 "data/maps/RustboroCity/scripts.pory"

# 600 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger1::
# 601 "data/maps/RustboroCity/scripts.pory"
	lockall
# 602 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 603 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 604 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 605 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 606 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 607 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 608 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 609 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 610 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer1
# 611 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 612 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 613 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 614 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 615 "data/maps/RustboroCity/scripts.pory"

# 616 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger2::
# 617 "data/maps/RustboroCity/scripts.pory"
	lockall
# 618 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 619 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 620 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 621 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 622 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 623 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 624 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 625 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 626 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer2
# 627 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 628 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 629 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 630 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 631 "data/maps/RustboroCity/scripts.pory"

# 632 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger3::
# 633 "data/maps/RustboroCity/scripts.pory"
	lockall
# 634 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 635 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 636 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 637 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 638 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 639 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 640 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 641 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 642 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer3
# 643 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 644 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 645 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 646 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 647 "data/maps/RustboroCity/scripts.pory"

# 648 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger4::
# 649 "data/maps/RustboroCity/scripts.pory"
	lockall
# 650 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 651 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 652 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 653 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 654 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 655 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 656 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 657 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 658 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer4
# 659 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 660 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 661 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 662 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 663 "data/maps/RustboroCity/scripts.pory"

# 664 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger5::
# 665 "data/maps/RustboroCity/scripts.pory"
	lockall
# 666 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 667 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 668 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 669 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 670 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 671 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 672 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 673 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 674 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer5
# 675 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 676 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 677 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 678 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 679 "data/maps/RustboroCity/scripts.pory"

# 680 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger6::
# 681 "data/maps/RustboroCity/scripts.pory"
	lockall
# 682 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 683 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 684 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 685 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 686 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 687 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 688 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 689 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 690 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer6
# 691 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 692 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 693 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 694 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 695 "data/maps/RustboroCity/scripts.pory"

# 696 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger7::
# 697 "data/maps/RustboroCity/scripts.pory"
	lockall
# 698 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 699 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 700 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 701 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 702 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 703 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 704 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 705 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 706 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer7
# 707 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 708 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 709 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 710 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 711 "data/maps/RustboroCity/scripts.pory"

# 712 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalEncounter::
# 713 "data/maps/RustboroCity/scripts.pory"
	checkplayergender
# 714 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_MayEncounter
# 715 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_BrendanEncounter
# 716 "data/maps/RustboroCity/scripts.pory"
	end
# 717 "data/maps/RustboroCity/scripts.pory"

# 718 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayEncounter::
# 719 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_MayBrineyHint
# 720 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_MayAskToBattle
# 721 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_MET_RIVAL_RUSTBORO
# 722 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayHiLetsRegister, MSGBOX_DEFAULT
# 723 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 724 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 725 "data/maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 726 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredMay, MSGBOX_DEFAULT
# 727 "data/maps/RustboroCity/scripts.pory"
	waitfanfare
# 728 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 729 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 730 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 731 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 732 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 733 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8008, 0
# 734 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayPassedBrineyWantToBattle, MSGBOX_YESNO
# 735 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
# 736 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
# 737 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_RestoreBgm
# 738 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 739 "data/maps/RustboroCity/scripts.pory"
	end
# 740 "data/maps/RustboroCity/scripts.pory"

# 741 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayAskToBattle::
# 742 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8008, 1
# 743 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayWantToBattle, MSGBOX_YESNO
# 744 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
# 745 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
# 746 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 747 "data/maps/RustboroCity/scripts.pory"
	end
# 748 "data/maps/RustboroCity/scripts.pory"

# 749 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMay::
# 750 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayImNotGoingToLose, MSGBOX_DEFAULT
# 751 "data/maps/RustboroCity/scripts.pory"
	switch VAR_STARTER_MON
# 752 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_BattleMayTreecko
# 753 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_BattleMayTorchic
# 754 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_BattleMayMudkip
# 755 "data/maps/RustboroCity/scripts.pory"
	end
# 756 "data/maps/RustboroCity/scripts.pory"

# 757 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayBrineyHint::
# 758 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayMrBrineyHint, MSGBOX_DEFAULT
# 759 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
# 760 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 761 "data/maps/RustboroCity/scripts.pory"
	end
# 762 "data/maps/RustboroCity/scripts.pory"

# 763 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RestoreBgm::
# 764 "data/maps/RustboroCity/scripts.pory"
	savebgm MUS_DUMMY
# 765 "data/maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 766 "data/maps/RustboroCity/scripts.pory"
	return
# 767 "data/maps/RustboroCity/scripts.pory"

# 768 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMayTreecko::
# 769 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TREECKO, RustboroCity_Text_MayDefeat
# 770 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 771 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 772 "data/maps/RustboroCity/scripts.pory"
	end
# 773 "data/maps/RustboroCity/scripts.pory"

# 774 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMayTorchic::
# 775 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TORCHIC, RustboroCity_Text_MayDefeat
# 776 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 777 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 778 "data/maps/RustboroCity/scripts.pory"
	end
# 779 "data/maps/RustboroCity/scripts.pory"

# 780 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMayMudkip::
# 781 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_MUDKIP, RustboroCity_Text_MayDefeat
# 782 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 783 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 784 "data/maps/RustboroCity/scripts.pory"
	end
# 785 "data/maps/RustboroCity/scripts.pory"

# 786 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanEncounter::
# 787 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanBrineyHint
# 788 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanAskToBattle
# 789 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_MET_RIVAL_RUSTBORO
# 790 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanHiLetsRegister, MSGBOX_DEFAULT
# 791 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 792 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 793 "data/maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 794 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredBrendan, MSGBOX_DEFAULT
# 795 "data/maps/RustboroCity/scripts.pory"
	waitfanfare
# 796 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 797 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 798 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 799 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 800 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 801 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanPassedBrineyWantToBattle, MSGBOX_YESNO
# 802 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
# 803 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
# 804 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_RestoreBgm
# 805 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 806 "data/maps/RustboroCity/scripts.pory"
	end
# 807 "data/maps/RustboroCity/scripts.pory"

# 808 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanAskToBattle::
# 809 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanWantToBattle, MSGBOX_YESNO
# 810 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
# 811 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
# 812 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 813 "data/maps/RustboroCity/scripts.pory"
	end
# 814 "data/maps/RustboroCity/scripts.pory"

# 815 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendan::
# 816 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanIWontGoEasy, MSGBOX_DEFAULT
# 817 "data/maps/RustboroCity/scripts.pory"
	switch VAR_STARTER_MON
# 818 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_BattleBrendanTreecko
# 819 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_BattleBrendanTorchic
# 820 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_BattleBrendanMudkip
# 821 "data/maps/RustboroCity/scripts.pory"
	end
# 822 "data/maps/RustboroCity/scripts.pory"

# 823 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanBrineyHint::
# 824 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanMrBrineyHint, MSGBOX_DEFAULT
# 825 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
# 826 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 827 "data/maps/RustboroCity/scripts.pory"
	end
# 828 "data/maps/RustboroCity/scripts.pory"

# 829 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendanTreecko::
# 830 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TREECKO, RustboroCity_Text_BrendanDefeat
# 831 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 832 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 833 "data/maps/RustboroCity/scripts.pory"
	end
# 834 "data/maps/RustboroCity/scripts.pory"

# 835 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendanTorchic::
# 836 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TORCHIC, RustboroCity_Text_BrendanDefeat
# 837 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 838 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 839 "data/maps/RustboroCity/scripts.pory"
	end
# 840 "data/maps/RustboroCity/scripts.pory"

# 841 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendanMudkip::
# 842 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_MUDKIP, RustboroCity_Text_BrendanDefeat
# 843 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 844 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 845 "data/maps/RustboroCity/scripts.pory"
	end
# 846 "data/maps/RustboroCity/scripts.pory"

# 847 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer0:
# 848 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 849 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 850 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 851 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 852 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 853 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 854 "data/maps/RustboroCity/scripts.pory"
	step_end
# 855 "data/maps/RustboroCity/scripts.pory"

# 856 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer1:
# 857 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 858 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 859 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 860 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 861 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 862 "data/maps/RustboroCity/scripts.pory"
	step_end
# 863 "data/maps/RustboroCity/scripts.pory"

# 864 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer2:
# 865 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 866 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 867 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 868 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 869 "data/maps/RustboroCity/scripts.pory"
	step_end
# 870 "data/maps/RustboroCity/scripts.pory"

# 871 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer3:
# 872 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 873 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 874 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 875 "data/maps/RustboroCity/scripts.pory"
	step_end
# 876 "data/maps/RustboroCity/scripts.pory"

# 877 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer4:
# 878 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 879 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 880 "data/maps/RustboroCity/scripts.pory"
	step_end
# 881 "data/maps/RustboroCity/scripts.pory"

# 882 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer5:
# 883 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 884 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 885 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 886 "data/maps/RustboroCity/scripts.pory"
	step_end
# 887 "data/maps/RustboroCity/scripts.pory"

# 888 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer6:
# 889 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 890 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 891 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 892 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 893 "data/maps/RustboroCity/scripts.pory"
	step_end
# 894 "data/maps/RustboroCity/scripts.pory"

# 895 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer7:
# 896 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 897 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 898 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 899 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 900 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 901 "data/maps/RustboroCity/scripts.pory"
	step_end
# 902 "data/maps/RustboroCity/scripts.pory"

# 903 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy1::
# 904 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouCanHave2On2Battle, MSGBOX_NPC
# 905 "data/maps/RustboroCity/scripts.pory"
	end
# 906 "data/maps/RustboroCity/scripts.pory"

# 907 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WeShortenItToDevon:
# 908 "data/maps/RustboroCity/scripts.pory"
	.string "The DEVON CORPORATION…\n"
# 909 "data/maps/RustboroCity/scripts.pory"
	.string "We all just shorten it to DEVON.\p"
# 910 "data/maps/RustboroCity/scripts.pory"
	.string "That company makes all sorts of\n"
# 911 "data/maps/RustboroCity/scripts.pory"
	.string "convenient products.$"
# 912 "data/maps/RustboroCity/scripts.pory"

# 913 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_SneakyLookingManWentAroundCorner:
# 914 "data/maps/RustboroCity/scripts.pory"
	.string "Hm? A sneaky-looking man?\p"
# 915 "data/maps/RustboroCity/scripts.pory"
	.string "Come to think of it, yes, a shady-\n"
# 916 "data/maps/RustboroCity/scripts.pory"
	.string "looking guy went around the corner.$"
# 917 "data/maps/RustboroCity/scripts.pory"

# 918 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HaveYouChallengedGym:
# 919 "data/maps/RustboroCity/scripts.pory"
	.string "Have you taken the POKéMON GYM\n"
# 920 "data/maps/RustboroCity/scripts.pory"
	.string "challenge?\p"
# 921 "data/maps/RustboroCity/scripts.pory"
	.string "When you get that shiny GYM BADGE\n"
# 922 "data/maps/RustboroCity/scripts.pory"
	.string "in hand, I guess TRAINERS begin to\l"
# 923 "data/maps/RustboroCity/scripts.pory"
	.string "realize what is required of them.$"
# 924 "data/maps/RustboroCity/scripts.pory"

# 925 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HeyThatsRustborosGymBadge:
# 926 "data/maps/RustboroCity/scripts.pory"
	.string "Hey, that's RUSTBORO's GYM BADGE!\p"
# 927 "data/maps/RustboroCity/scripts.pory"
	.string "Out of all the POKéMON GYM BADGES,\n"
# 928 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO's is the coolest, I'd say.$"
# 929 "data/maps/RustboroCity/scripts.pory"

# 930 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YoureNewAroundHere:
# 931 "data/maps/RustboroCity/scripts.pory"
	.string "Oh? Who might you be?\n"
# 932 "data/maps/RustboroCity/scripts.pory"
	.string "You're a new face around these parts.\p"
# 933 "data/maps/RustboroCity/scripts.pory"
	.string "Have you just transferred into the\n"
# 934 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL?$"
# 935 "data/maps/RustboroCity/scripts.pory"

# 936 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymLeaderIsntEasyWithFire:
# 937 "data/maps/RustboroCity/scripts.pory"
	.string "I challenged the GYM LEADER, but…\p"
# 938 "data/maps/RustboroCity/scripts.pory"
	.string "It's not going to be easy winning with\n"
# 939 "data/maps/RustboroCity/scripts.pory"
	.string "my FIRE-type POKéMON…\p"
# 940 "data/maps/RustboroCity/scripts.pory"
	.string "FIRE-type POKéMON don't match up\n"
# 941 "data/maps/RustboroCity/scripts.pory"
	.string "well against ROCK-type POKéMON…$"
# 942 "data/maps/RustboroCity/scripts.pory"

# 943 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyWalksInTheTunnel:
# 944 "data/maps/RustboroCity/scripts.pory"
	.string "The old sailor MR. BRINEY lives in\n"
# 945 "data/maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 946 "data/maps/RustboroCity/scripts.pory"
	.string "He goes for walks in the tunnel every\n"
# 947 "data/maps/RustboroCity/scripts.pory"
	.string "so often.$"
# 948 "data/maps/RustboroCity/scripts.pory"

# 949 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyLovesPeeko:
# 950 "data/maps/RustboroCity/scripts.pory"
	.string "The old sailor MR. BRINEY lives in\n"
# 951 "data/maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 952 "data/maps/RustboroCity/scripts.pory"
	.string "He said he was going shopping in\n"
# 953 "data/maps/RustboroCity/scripts.pory"
	.string "SLATEPORT for his pet, PEEKO.\p"
# 954 "data/maps/RustboroCity/scripts.pory"
	.string "That old sea dog, he must really love\n"
# 955 "data/maps/RustboroCity/scripts.pory"
	.string "that PEEKO.$"
# 956 "data/maps/RustboroCity/scripts.pory"

# 957 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WowYouHavePokemon:
# 958 "data/maps/RustboroCity/scripts.pory"
	.string "Wow, you have POKéMON with you, too.\p"
# 959 "data/maps/RustboroCity/scripts.pory"
	.string "When I get bigger, I'm going to go\n"
# 960 "data/maps/RustboroCity/scripts.pory"
	.string "places with POKéMON, too.$"
# 961 "data/maps/RustboroCity/scripts.pory"

# 962 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CatchRarePokemonIfIGoToSchool:
# 963 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL!\p"
# 964 "data/maps/RustboroCity/scripts.pory"
	.string "If I go to this school, will I be able\n"
# 965 "data/maps/RustboroCity/scripts.pory"
	.string "to catch rare POKéMON easily?$"
# 966 "data/maps/RustboroCity/scripts.pory"

# 967 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonCanChangeLookFromExp:
# 968 "data/maps/RustboroCity/scripts.pory"
	.string "If a POKéMON gains experience in\n"
# 969 "data/maps/RustboroCity/scripts.pory"
	.string "battles, it can sometimes change in\l"
# 970 "data/maps/RustboroCity/scripts.pory"
	.string "the way it looks.$"
# 971 "data/maps/RustboroCity/scripts.pory"

# 972 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonChangeShape:
# 973 "data/maps/RustboroCity/scripts.pory"
	.string "A POKéMON changes shape?\n"
# 974 "data/maps/RustboroCity/scripts.pory"
	.string "If one did that, I would be shocked!$"
# 975 "data/maps/RustboroCity/scripts.pory"

# 976 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TradePokemonGrowFast:
# 977 "data/maps/RustboroCity/scripts.pory"
	.string "A POKéMON you get in a trade from\n"
# 978 "data/maps/RustboroCity/scripts.pory"
	.string "someone grows fast.\p"
# 979 "data/maps/RustboroCity/scripts.pory"
	.string "But if you don't have certain GYM\n"
# 980 "data/maps/RustboroCity/scripts.pory"
	.string "BADGES, it may not obey you…$"
# 981 "data/maps/RustboroCity/scripts.pory"

# 982 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_OutOfTheWay:
# 983 "data/maps/RustboroCity/scripts.pory"
	.string "Get out!\n"
# 984 "data/maps/RustboroCity/scripts.pory"
	.string "Out of the way!$"
# 985 "data/maps/RustboroCity/scripts.pory"

# 986 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WaitDontTakeMyGoods:
# 987 "data/maps/RustboroCity/scripts.pory"
	.string "Wait! Pleeeaaase!\p"
# 988 "data/maps/RustboroCity/scripts.pory"
	.string "Don't take my GOODS!$"
# 989 "data/maps/RustboroCity/scripts.pory"

# 990 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HelpMeIWasRobbed:
# 991 "data/maps/RustboroCity/scripts.pory"
	.string "Oh, it's you!\p"
# 992 "data/maps/RustboroCity/scripts.pory"
	.string "You're that fantastic TRAINER who\n"
# 993 "data/maps/RustboroCity/scripts.pory"
	.string "helped me in PETALBURG WOODS!\p"
# 994 "data/maps/RustboroCity/scripts.pory"
	.string "Help me! I was robbed by TEAM AQUA!\n"
# 995 "data/maps/RustboroCity/scripts.pory"
	.string "I have to get the DEVON GOODS back!\p"
# 996 "data/maps/RustboroCity/scripts.pory"
	.string "If I don't…\n"
# 997 "data/maps/RustboroCity/scripts.pory"
	.string "I'm going to be in serious trouble.$"
# 998 "data/maps/RustboroCity/scripts.pory"

# 999 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel:
# 1000 "data/maps/RustboroCity/scripts.pory"
	.string "That shady character, I think he took\n"
# 1001 "data/maps/RustboroCity/scripts.pory"
	.string "off towards the tunnel over there.$"
# 1002 "data/maps/RustboroCity/scripts.pory"

# 1003 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YouGotItThankYou:
# 1004 "data/maps/RustboroCity/scripts.pory"
	.string "Oh! How did it go?\n"
# 1005 "data/maps/RustboroCity/scripts.pory"
	.string "The DEVON GOODS?\p"
# 1006 "data/maps/RustboroCity/scripts.pory"
	.string "You did!\n"
# 1007 "data/maps/RustboroCity/scripts.pory"
	.string "You got them back!\p"
# 1008 "data/maps/RustboroCity/scripts.pory"
	.string "You really are a great TRAINER!\p"
# 1009 "data/maps/RustboroCity/scripts.pory"
	.string "I know! As my thanks, I'll give you\n"
# 1010 "data/maps/RustboroCity/scripts.pory"
	.string "another GREAT BALL!$"
# 1011 "data/maps/RustboroCity/scripts.pory"

# 1012 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YoureLoadedWithItems:
# 1013 "data/maps/RustboroCity/scripts.pory"
	.string "You're loaded with items.\n"
# 1014 "data/maps/RustboroCity/scripts.pory"
	.string "I can't give you this GREAT BALL.$"
# 1015 "data/maps/RustboroCity/scripts.pory"

# 1016 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PleaseComeWithMe:
# 1017 "data/maps/RustboroCity/scripts.pory"
	.string "Excuse me, please!\n"
# 1018 "data/maps/RustboroCity/scripts.pory"
	.string "Please come with me!$"
# 1019 "data/maps/RustboroCity/scripts.pory"

# 1020 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayHiLetsRegister:
# 1021 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\p"
# 1022 "data/maps/RustboroCity/scripts.pory"
	.string "You had a MATCH CALL feature put\n"
# 1023 "data/maps/RustboroCity/scripts.pory"
	.string "on your POKéNAV!\p"
# 1024 "data/maps/RustboroCity/scripts.pory"
	.string "Let's register each other so we can\n"
# 1025 "data/maps/RustboroCity/scripts.pory"
	.string "contact one another anytime!\p"
# 1026 "data/maps/RustboroCity/scripts.pory"
	.string "… … … … … …$"
# 1027 "data/maps/RustboroCity/scripts.pory"

# 1028 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_RegisteredMay:
# 1029 "data/maps/RustboroCity/scripts.pory"
	.string "Registered MAY\n"
# 1030 "data/maps/RustboroCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1031 "data/maps/RustboroCity/scripts.pory"

# 1032 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayPassedBrineyWantToBattle:
# 1033 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, by the way, I passed\n"
# 1034 "data/maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY in PETALBURG WOODS.\p"
# 1035 "data/maps/RustboroCity/scripts.pory"
	.string "I guess he's on his way home to his\n"
# 1036 "data/maps/RustboroCity/scripts.pory"
	.string "cottage by the sea.\p"
# 1037 "data/maps/RustboroCity/scripts.pory"
	.string "How's your POKéDEX coming along,\n"
# 1038 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}? Mine's looking pretty decent!\p"
# 1039 "data/maps/RustboroCity/scripts.pory"
	.string "So…\n"
# 1040 "data/maps/RustboroCity/scripts.pory"
	.string "How about a little battle?$"
# 1041 "data/maps/RustboroCity/scripts.pory"

# 1042 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayOhHaventRaisedPokemonEnough:
# 1043 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, what's the matter?\p"
# 1044 "data/maps/RustboroCity/scripts.pory"
	.string "Haven't you caught or raised your\n"
# 1045 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON very much?\p"
# 1046 "data/maps/RustboroCity/scripts.pory"
	.string "That's not very good for a TRAINER!$"
# 1047 "data/maps/RustboroCity/scripts.pory"

# 1048 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayWantToBattle:
# 1049 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: So, what do you think?\n"
# 1050 "data/maps/RustboroCity/scripts.pory"
	.string "How about a little battle here?$"
# 1051 "data/maps/RustboroCity/scripts.pory"

# 1052 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayImNotGoingToLose:
# 1053 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: You just became a TRAINER,\n"
# 1054 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}. I'm not going to lose!$"
# 1055 "data/maps/RustboroCity/scripts.pory"

# 1056 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayDefeat:
# 1057 "data/maps/RustboroCity/scripts.pory"
	.string "Yikes!\n"
# 1058 "data/maps/RustboroCity/scripts.pory"
	.string "You're better than I expected!$"
# 1059 "data/maps/RustboroCity/scripts.pory"

# 1060 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayMrBrineyHint:
# 1061 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, by the way, MR. BRINEY, who\n"
# 1062 "data/maps/RustboroCity/scripts.pory"
	.string "I just passed…\p"
# 1063 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}, you just moved here so you\n"
# 1064 "data/maps/RustboroCity/scripts.pory"
	.string "might not know this, but MR. BRINEY\l"
# 1065 "data/maps/RustboroCity/scripts.pory"
	.string "was once a revered seafarer.$"
# 1066 "data/maps/RustboroCity/scripts.pory"

# 1067 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanHiLetsRegister:
# 1068 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: Oh, hey, {PLAYER}!\p"
# 1069 "data/maps/RustboroCity/scripts.pory"
	.string "You had a MATCH CALL feature put\n"
# 1070 "data/maps/RustboroCity/scripts.pory"
	.string "on your POKéNAV! Cool!\p"
# 1071 "data/maps/RustboroCity/scripts.pory"
	.string "Let's register each other so we can\n"
# 1072 "data/maps/RustboroCity/scripts.pory"
	.string "get in touch anytime!\p"
# 1073 "data/maps/RustboroCity/scripts.pory"
	.string "… … … … … …$"
# 1074 "data/maps/RustboroCity/scripts.pory"

# 1075 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_RegisteredBrendan:
# 1076 "data/maps/RustboroCity/scripts.pory"
	.string "Registered BRENDAN\n"
# 1077 "data/maps/RustboroCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1078 "data/maps/RustboroCity/scripts.pory"

# 1079 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanPassedBrineyWantToBattle:
# 1080 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: By the way, {PLAYER}, I walked\n"
# 1081 "data/maps/RustboroCity/scripts.pory"
	.string "by MR. BRINEY in PETALBURG WOODS.\p"
# 1082 "data/maps/RustboroCity/scripts.pory"
	.string "I bet he was on his way home to his\n"
# 1083 "data/maps/RustboroCity/scripts.pory"
	.string "cottage by the sea.\p"
# 1084 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, how's your POKéDEX?\n"
# 1085 "data/maps/RustboroCity/scripts.pory"
	.string "Have you filled in any pages yet?\p"
# 1086 "data/maps/RustboroCity/scripts.pory"
	.string "Mine rules.\p"
# 1087 "data/maps/RustboroCity/scripts.pory"
	.string "Want to have a battle to test how\n"
# 1088 "data/maps/RustboroCity/scripts.pory"
	.string "far you've progressed?$"
# 1089 "data/maps/RustboroCity/scripts.pory"

# 1090 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanNoConfidenceInPokemon:
# 1091 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: What's the matter? Don't have\n"
# 1092 "data/maps/RustboroCity/scripts.pory"
	.string "any confidence in your POKéMON?$"
# 1093 "data/maps/RustboroCity/scripts.pory"

# 1094 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanWantToBattle:
# 1095 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: What's up?\n"
# 1096 "data/maps/RustboroCity/scripts.pory"
	.string "Want to have a battle with me?$"
# 1097 "data/maps/RustboroCity/scripts.pory"

# 1098 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanIWontGoEasy:
# 1099 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: I know you just became\n"
# 1100 "data/maps/RustboroCity/scripts.pory"
	.string "a TRAINER, but I won't go easy!$"
# 1101 "data/maps/RustboroCity/scripts.pory"

# 1102 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanDefeat:
# 1103 "data/maps/RustboroCity/scripts.pory"
	.string "Hmm…\n"
# 1104 "data/maps/RustboroCity/scripts.pory"
	.string "You're pretty good.$"
# 1105 "data/maps/RustboroCity/scripts.pory"

# 1106 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanMrBrineyHint:
# 1107 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: By the way, you know\n"
# 1108 "data/maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY? The guy I just passed?\p"
# 1109 "data/maps/RustboroCity/scripts.pory"
	.string "I bet you didn't know this, since you\n"
# 1110 "data/maps/RustboroCity/scripts.pory"
	.string "just moved here, {PLAYER}, but\l"
# 1111 "data/maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY was once a great sailor.$"
# 1112 "data/maps/RustboroCity/scripts.pory"

# 1113 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TunnelNearingCompletion:
# 1114 "data/maps/RustboroCity/scripts.pory"
	.string "“Timesaving tunnel nearing\n"
# 1115 "data/maps/RustboroCity/scripts.pory"
	.string "completion!”\p"
# 1116 "data/maps/RustboroCity/scripts.pory"
	.string "…Is what it says on the sign, but\n"
# 1117 "data/maps/RustboroCity/scripts.pory"
	.string "there's also a big “X” splashed\l"
# 1118 "data/maps/RustboroCity/scripts.pory"
	.string "across it in red paint…$"
# 1119 "data/maps/RustboroCity/scripts.pory"

# 1120 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpSign:
# 1121 "data/maps/RustboroCity/scripts.pory"
	.string "DEVON CORPORATION\p"
# 1122 "data/maps/RustboroCity/scripts.pory"
	.string "“For all your living needs, we make\n"
# 1123 "data/maps/RustboroCity/scripts.pory"
	.string "it all.”$"
# 1124 "data/maps/RustboroCity/scripts.pory"

# 1125 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymSign:
# 1126 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO CITY POKéMON GYM\n"
# 1127 "data/maps/RustboroCity/scripts.pory"
	.string "LEADER: ROXANNE\p"
# 1128 "data/maps/RustboroCity/scripts.pory"
	.string "“The ROCK-loving honors student!”$"
# 1129 "data/maps/RustboroCity/scripts.pory"

# 1130 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpBranchOfficeSign:
# 1131 "data/maps/RustboroCity/scripts.pory"
	.string "DEVON CORP. BRANCH OFFICE\p"
# 1132 "data/maps/RustboroCity/scripts.pory"
	.string "“Access limited to DEVON employees\n"
# 1133 "data/maps/RustboroCity/scripts.pory"
	.string "and authorized personnel.”$"
# 1134 "data/maps/RustboroCity/scripts.pory"

# 1135 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CitySign:
# 1136 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO CITY\p"
# 1137 "data/maps/RustboroCity/scripts.pory"
	.string "“The city probing the integration of\n"
# 1138 "data/maps/RustboroCity/scripts.pory"
	.string "nature and science.”$"
# 1139 "data/maps/RustboroCity/scripts.pory"

# 1140 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TrainersSchoolSign:
# 1141 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL\p"
# 1142 "data/maps/RustboroCity/scripts.pory"
	.string "“We'll teach you anything about\n"
# 1143 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON!”$"
# 1144 "data/maps/RustboroCity/scripts.pory"

# 1145 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CuttersHouse:
# 1146 "data/maps/RustboroCity/scripts.pory"
	.string "CUTTER'S HOUSE$"
# 1147 "data/maps/RustboroCity/scripts.pory"

# 1148 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevelopedNewPokenavFeature:
# 1149 "data/maps/RustboroCity/scripts.pory"
	.string "I've been developing an added feature\n"
# 1150 "data/maps/RustboroCity/scripts.pory"
	.string "for the POKéNAV…\p"
# 1151 "data/maps/RustboroCity/scripts.pory"
	.string "And it turned out great!\p"
# 1152 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, may I see that POKéNAV?\n"
# 1153 "data/maps/RustboroCity/scripts.pory"
	.string "The one our PRESIDENT gave you?$"
# 1154 "data/maps/RustboroCity/scripts.pory"

# 1155 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_AddedMatchCallPleaseCallMrStone:
# 1156 "data/maps/RustboroCity/scripts.pory"
	.string "There you go, {PLAYER}!\p"
# 1157 "data/maps/RustboroCity/scripts.pory"
	.string "I added a new feature named\n"
# 1158 "data/maps/RustboroCity/scripts.pory"
	.string "MATCH CALL to your POKéNAV.\p"
# 1159 "data/maps/RustboroCity/scripts.pory"
	.string "Using the MATCH CALL feature,\n"
# 1160 "data/maps/RustboroCity/scripts.pory"
	.string "you can chat with people who have\l"
# 1161 "data/maps/RustboroCity/scripts.pory"
	.string "been registered in your POKéNAV.\p"
# 1162 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, our PRESIDENT STONE should\n"
# 1163 "data/maps/RustboroCity/scripts.pory"
	.string "be registered in your POKéNAV.\p"
# 1164 "data/maps/RustboroCity/scripts.pory"
	.string "Test it out.\n"
# 1165 "data/maps/RustboroCity/scripts.pory"
	.string "Please give our PRESIDENT a call.$"
# 1166 "data/maps/RustboroCity/scripts.pory"

# 1167 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PleaseSelectPokenav:
# 1168 "data/maps/RustboroCity/scripts.pory"
	.string "Please select the POKéNAV.$"
# 1169 "data/maps/RustboroCity/scripts.pory"

# 1170 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_IdBetterGetBackToWork:
# 1171 "data/maps/RustboroCity/scripts.pory"
	.string "Okay, I'd better get back to work.\n"
# 1172 "data/maps/RustboroCity/scripts.pory"
	.string "Please take care, {PLAYER}!$"
# 1173 "data/maps/RustboroCity/scripts.pory"

# 1174 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YouCanHave2On2Battle:
# 1175 "data/maps/RustboroCity/scripts.pory"
	.string "Did you know this?\p"
# 1176 "data/maps/RustboroCity/scripts.pory"
	.string "You can have a 2-on-2 battle even\n"
# 1177 "data/maps/RustboroCity/scripts.pory"
	.string "if you're not with another TRAINER.\p"
# 1178 "data/maps/RustboroCity/scripts.pory"
	.string "If you catch the eyes of two TRAINERS\n"
# 1179 "data/maps/RustboroCity/scripts.pory"
	.string "when you have two or more POKéMON,\l"
# 1180 "data/maps/RustboroCity/scripts.pory"
	.string "they'll both challenge you.\p"
# 1181 "data/maps/RustboroCity/scripts.pory"
	.string "Don't you think it'd be cool if you\n"
# 1182 "data/maps/RustboroCity/scripts.pory"
	.string "could beat two TRAINERS by yourself?$"
