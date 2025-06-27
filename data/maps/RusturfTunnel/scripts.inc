# 1 "data/maps/RusturfTunnel/scripts.pory"

# 2 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_MapScripts::
# 3 "data/maps/RusturfTunnel/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RusturfTunnel_OnTransition
# 4 "data/maps/RusturfTunnel/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RusturfTunnel_OnFrame
# 5 "data/maps/RusturfTunnel/scripts.pory"
	.byte 0
# 6 "data/maps/RusturfTunnel/scripts.pory"

# 7 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_OnFrame:
# 8 "data/maps/RusturfTunnel/scripts.pory"
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 4, RusturfTunnel_EventScript_ClearTunnelScene
# 9 "data/maps/RusturfTunnel/scripts.pory"
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 5, RusturfTunnel_EventScript_ClearTunnelScene
# 10 "data/maps/RusturfTunnel/scripts.pory"
	.2byte 0
# 11 "data/maps/RusturfTunnel/scripts.pory"

# 12 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_OnTransition:
# 13 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_RUSTURF_TUNNEL_STATE, 2, RusturfTunnel_EventScript_SetAquaGruntAndPeekoPos
# 14 "data/maps/RusturfTunnel/scripts.pory"
	end
# 15 "data/maps/RusturfTunnel/scripts.pory"

# 16 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_SetAquaGruntAndPeekoPos::
# 17 "data/maps/RusturfTunnel/scripts.pory"
	setobjectxyperm LOCALID_RUSTURF_TUNNEL_PEEKO, 13, 4
# 18 "data/maps/RusturfTunnel/scripts.pory"
	setobjectxyperm LOCALID_RUSTURF_TUNNEL_GRUNT, 13, 5
# 19 "data/maps/RusturfTunnel/scripts.pory"
	return
# 20 "data/maps/RusturfTunnel/scripts.pory"

# 21 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_Wanda::
# 22 "data/maps/RusturfTunnel/scripts.pory"
	lock
# 23 "data/maps/RusturfTunnel/scripts.pory"
	faceplayer
# 24 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_BoyfriendOnOtherSideOfRock, MSGBOX_DEFAULT
# 25 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 26 "data/maps/RusturfTunnel/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 27 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 28 "data/maps/RusturfTunnel/scripts.pory"
	release
# 29 "data/maps/RusturfTunnel/scripts.pory"
	end
# 30 "data/maps/RusturfTunnel/scripts.pory"

# 31 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandasBoyfriend::
# 32 "data/maps/RusturfTunnel/scripts.pory"
	lock
# 33 "data/maps/RusturfTunnel/scripts.pory"
	faceplayer
# 34 "data/maps/RusturfTunnel/scripts.pory"
	goto_if_set FLAG_TEMP_1, RusturfTunnel_EventScript_AlreadySpokenTo
# 35 "data/maps/RusturfTunnel/scripts.pory"
	setflag FLAG_TEMP_1
# 36 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_WhyCantTheyKeepDigging, MSGBOX_DEFAULT
# 37 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 38 "data/maps/RusturfTunnel/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 39 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 40 "data/maps/RusturfTunnel/scripts.pory"
	release
# 41 "data/maps/RusturfTunnel/scripts.pory"
	end
# 42 "data/maps/RusturfTunnel/scripts.pory"

# 43 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_AlreadySpokenTo::
# 44 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_ToGetToVerdanturf, MSGBOX_DEFAULT
# 45 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 46 "data/maps/RusturfTunnel/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 47 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 48 "data/maps/RusturfTunnel/scripts.pory"
	release
# 49 "data/maps/RusturfTunnel/scripts.pory"
	end
# 50 "data/maps/RusturfTunnel/scripts.pory"

# 51 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_ClearTunnelScene::
# 52 "data/maps/RusturfTunnel/scripts.pory"
	lockall
# 53 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_FaceWandasBoyfriend1
# 54 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_FaceWandasBoyfriend2
# 55 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_FaceWandasBoyfriend3
# 56 "data/maps/RusturfTunnel/scripts.pory"
	call RusturfTunnel_EventScript_WandasBoyfriendNotice
# 57 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_YouShatteredBoulderTakeHM, MSGBOX_DEFAULT
# 58 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer
# 59 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer
# 60 "data/maps/RusturfTunnel/scripts.pory"
	giveitem ITEM_HM_STRENGTH
# 61 "data/maps/RusturfTunnel/scripts.pory"
	setflag FLAG_RECEIVED_HM_STRENGTH
# 62 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_ExplainStrength, MSGBOX_DEFAULT
# 63 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 64 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_BoyfriendApproachWanda1
# 65 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_BoyfriendApproachWanda2
# 66 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_BoyfriendApproachWanda3
# 67 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_WandaReunion, MSGBOX_DEFAULT
# 68 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 69 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_WandaAndBoyfriendExit1
# 70 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_WandaAndBoyfriendExit
# 71 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_WandaAndBoyfriendExit
# 72 "data/maps/RusturfTunnel/scripts.pory"
	call RusturfTunnel_EventScript_SetRusturfTunnelOpen
# 73 "data/maps/RusturfTunnel/scripts.pory"
	releaseall
# 74 "data/maps/RusturfTunnel/scripts.pory"
	end
# 75 "data/maps/RusturfTunnel/scripts.pory"

# 76 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_BoyfriendApproachWanda1::
# 77 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend1
# 78 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda1
# 79 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 80 "data/maps/RusturfTunnel/scripts.pory"
	return
# 81 "data/maps/RusturfTunnel/scripts.pory"

# 82 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_BoyfriendApproachWanda2::
# 83 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend
# 84 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda
# 85 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 86 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDA, Common_Movement_WalkInPlaceFasterDown
# 87 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 88 "data/maps/RusturfTunnel/scripts.pory"
	return
# 89 "data/maps/RusturfTunnel/scripts.pory"

# 90 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_BoyfriendApproachWanda3::
# 91 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend
# 92 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda
# 93 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 94 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDA, Common_Movement_WalkInPlaceFasterDown
# 95 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 96 "data/maps/RusturfTunnel/scripts.pory"
	return
# 97 "data/maps/RusturfTunnel/scripts.pory"

# 98 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_FaceWandasBoyfriend1::
# 99 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, Common_Movement_WalkInPlaceFasterUp
# 100 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 101 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 102 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 103 "data/maps/RusturfTunnel/scripts.pory"
	return
# 104 "data/maps/RusturfTunnel/scripts.pory"

# 105 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_FaceWandasBoyfriend2::
# 106 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_BoyfriendFaceRight
# 107 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 108 "data/maps/RusturfTunnel/scripts.pory"
	return
# 109 "data/maps/RusturfTunnel/scripts.pory"

# 110 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_FaceWandasBoyfriend3::
# 111 "data/maps/RusturfTunnel/scripts.pory"
	return
# 112 "data/maps/RusturfTunnel/scripts.pory"

# 113 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer::
# 114 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 115 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendApproachPlayer
# 116 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 117 "data/maps/RusturfTunnel/scripts.pory"
	return
# 118 "data/maps/RusturfTunnel/scripts.pory"

# 119 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandaAndBoyfriendExit1::
# 120 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDA, RusturfTunnel_Movement_WandaExit1
# 121 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendExit1
# 122 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 123 "data/maps/RusturfTunnel/scripts.pory"
	return
# 124 "data/maps/RusturfTunnel/scripts.pory"

# 125 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandaAndBoyfriendExit::
# 126 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerWatchWandaExit
# 127 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDA, RusturfTunnel_Movement_WandaExit
# 128 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendExit
# 129 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 130 "data/maps/RusturfTunnel/scripts.pory"
	return
# 131 "data/maps/RusturfTunnel/scripts.pory"

# 132 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandasBoyfriendNotice::
# 133 "data/maps/RusturfTunnel/scripts.pory"
	playse SE_PIN
# 134 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, Common_Movement_ExclamationMark
# 135 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 136 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, Common_Movement_Delay48
# 137 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 138 "data/maps/RusturfTunnel/scripts.pory"
	return
# 139 "data/maps/RusturfTunnel/scripts.pory"

# 140 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandaExit1:
# 141 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 142 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 143 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 144 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 145 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 146 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 147 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 148 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 149 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 150 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 151 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 152 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 153 "data/maps/RusturfTunnel/scripts.pory"

# 154 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandaExit:
# 155 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 156 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 157 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 158 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 159 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 160 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 161 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 162 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 163 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 164 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 165 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 166 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 167 "data/maps/RusturfTunnel/scripts.pory"

# 168 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerWatchWandaExit:
# 169 "data/maps/RusturfTunnel/scripts.pory"
	delay_8
# 170 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_up
# 171 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 172 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 173 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 174 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 175 "data/maps/RusturfTunnel/scripts.pory"

# 176 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_Unused1:
# 177 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 178 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 179 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 180 "data/maps/RusturfTunnel/scripts.pory"

# 181 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_Unused2:
# 182 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 183 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_up
# 184 "data/maps/RusturfTunnel/scripts.pory"
	delay_8
# 185 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 186 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 187 "data/maps/RusturfTunnel/scripts.pory"

# 188 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_Unused3:
# 189 "data/maps/RusturfTunnel/scripts.pory"
	walk_up
# 190 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_down
# 191 "data/maps/RusturfTunnel/scripts.pory"
	delay_8
# 192 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 193 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 194 "data/maps/RusturfTunnel/scripts.pory"

# 195 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerWatchBoyfriend1:
# 196 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 197 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 198 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 199 "data/maps/RusturfTunnel/scripts.pory"

# 200 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerWatchBoyfriend:
# 201 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 202 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_left
# 203 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 204 "data/maps/RusturfTunnel/scripts.pory"

# 205 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BoyfriendFaceRight:
# 206 "data/maps/RusturfTunnel/scripts.pory"
	walk_up
# 207 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 208 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 209 "data/maps/RusturfTunnel/scripts.pory"

# 210 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandasBoyfriendExit1:
# 211 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 212 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 213 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 214 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 215 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 216 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 217 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 218 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 219 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 220 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 221 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 222 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 223 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 224 "data/maps/RusturfTunnel/scripts.pory"

# 225 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandasBoyfriendExit:
# 226 "data/maps/RusturfTunnel/scripts.pory"
	walk_up
# 227 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 228 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 229 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 230 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 231 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 232 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 233 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 234 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 235 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 236 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 237 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 238 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 239 "data/maps/RusturfTunnel/scripts.pory"

# 240 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandasBoyfriendApproachPlayer:
# 241 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 242 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 243 "data/maps/RusturfTunnel/scripts.pory"

# 244 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BoyfriendApproachWanda1:
# 245 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fast_up
# 246 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fast_up
# 247 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_up
# 248 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_right
# 249 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 250 "data/maps/RusturfTunnel/scripts.pory"

# 251 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BoyfriendApproachWanda:
# 252 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fast_right
# 253 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fast_right
# 254 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_right
# 255 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_up
# 256 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 257 "data/maps/RusturfTunnel/scripts.pory"

# 258 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_TunnelBlockagePos1::
# 259 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_TEMP_1, 1
# 260 "data/maps/RusturfTunnel/scripts.pory"
	end
# 261 "data/maps/RusturfTunnel/scripts.pory"

# 262 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_TunnelBlockagePos2::
# 263 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_TEMP_1, 2
# 264 "data/maps/RusturfTunnel/scripts.pory"
	end
# 265 "data/maps/RusturfTunnel/scripts.pory"

# 266 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_TunnelBlockagePos3::
# 267 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_TEMP_1, 3
# 268 "data/maps/RusturfTunnel/scripts.pory"
	end
# 269 "data/maps/RusturfTunnel/scripts.pory"

# 270 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_AquaGruntBackUp::
# 271 "data/maps/RusturfTunnel/scripts.pory"
	lockall
# 272 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_ComeAndGetSome, MSGBOX_DEFAULT
# 273 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 274 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_GRUNT, RusturfTunnel_Movement_GruntAndPeekoBackUp
# 275 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_PEEKO, RusturfTunnel_Movement_GruntAndPeekoBackUp
# 276 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 277 "data/maps/RusturfTunnel/scripts.pory"
	copyobjectxytoperm LOCALID_RUSTURF_TUNNEL_GRUNT
# 278 "data/maps/RusturfTunnel/scripts.pory"
	copyobjectxytoperm LOCALID_RUSTURF_TUNNEL_PEEKO
# 279 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 3
# 280 "data/maps/RusturfTunnel/scripts.pory"
	releaseall
# 281 "data/maps/RusturfTunnel/scripts.pory"
	end
# 282 "data/maps/RusturfTunnel/scripts.pory"

# 283 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_GruntAndPeekoBackUp:
# 284 "data/maps/RusturfTunnel/scripts.pory"
	lock_facing_direction
# 285 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 286 "data/maps/RusturfTunnel/scripts.pory"
	unlock_facing_direction
# 287 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 288 "data/maps/RusturfTunnel/scripts.pory"

# 289 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_Peeko::
# 290 "data/maps/RusturfTunnel/scripts.pory"
	lock
# 291 "data/maps/RusturfTunnel/scripts.pory"
	faceplayer
# 292 "data/maps/RusturfTunnel/scripts.pory"
	waitse
# 293 "data/maps/RusturfTunnel/scripts.pory"
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
# 294 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_Peeko, MSGBOX_DEFAULT
# 295 "data/maps/RusturfTunnel/scripts.pory"
	waitmoncry
# 296 "data/maps/RusturfTunnel/scripts.pory"
	release
# 297 "data/maps/RusturfTunnel/scripts.pory"
	end
# 298 "data/maps/RusturfTunnel/scripts.pory"

# 299 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_Grunt::
# 300 "data/maps/RusturfTunnel/scripts.pory"
	lock
# 301 "data/maps/RusturfTunnel/scripts.pory"
	faceplayer
# 302 "data/maps/RusturfTunnel/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 303 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_GruntIntro, MSGBOX_DEFAULT
# 304 "data/maps/RusturfTunnel/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_RUSTURF_TUNNEL, RusturfTunnel_Text_GruntDefeat
# 305 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_GruntTakePackage, MSGBOX_DEFAULT
# 306 "data/maps/RusturfTunnel/scripts.pory"
	giveitem ITEM_DEVON_GOODS
# 307 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 308 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PushPlayerAsideForGrunt
# 309 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_GRUNT, RusturfTunnel_Movement_GruntEscape
# 310 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 311 "data/maps/RusturfTunnel/scripts.pory"
	removeobject LOCALID_RUSTURF_TUNNEL_GRUNT
# 312 "data/maps/RusturfTunnel/scripts.pory"
	delay 50
# 313 "data/maps/RusturfTunnel/scripts.pory"
	addobject LOCALID_RUSTURF_TUNNEL_BRINEY
# 314 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_BRINEY, RusturfTunnel_Movement_BrineyApproachPeeko1
# 315 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 316 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerMoveAsideForBriney
# 317 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_BRINEY, RusturfTunnel_Movement_BrineyApproachPeeko2
# 318 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 319 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_PeekoGladToSeeYouSafe, MSGBOX_DEFAULT
# 320 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_BRINEY, Common_Movement_FacePlayer
# 321 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 322 "data/maps/RusturfTunnel/scripts.pory"
	message RusturfTunnel_Text_ThankYouLetsGoHomePeeko
# 323 "data/maps/RusturfTunnel/scripts.pory"
	waitmessage
# 324 "data/maps/RusturfTunnel/scripts.pory"
	waitse
# 325 "data/maps/RusturfTunnel/scripts.pory"
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
# 326 "data/maps/RusturfTunnel/scripts.pory"
	waitbuttonpress
# 327 "data/maps/RusturfTunnel/scripts.pory"
	waitmoncry
# 328 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 329 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerWatchBrineyExit
# 330 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_BRINEY, RusturfTunnel_Movement_BrineyExit
# 331 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_PEEKO, RusturfTunnel_Movement_PeekoExit
# 332 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 333 "data/maps/RusturfTunnel/scripts.pory"
	removeobject LOCALID_RUSTURF_TUNNEL_BRINEY
# 334 "data/maps/RusturfTunnel/scripts.pory"
	removeobject LOCALID_RUSTURF_TUNNEL_PEEKO
# 335 "data/maps/RusturfTunnel/scripts.pory"
	clearflag FLAG_DEVON_GOODS_STOLEN
# 336 "data/maps/RusturfTunnel/scripts.pory"
	setflag FLAG_RECOVERED_DEVON_GOODS
# 337 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 4
# 338 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_BRINEY_HOUSE_STATE, 1
# 339 "data/maps/RusturfTunnel/scripts.pory"
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
# 340 "data/maps/RusturfTunnel/scripts.pory"
	release
# 341 "data/maps/RusturfTunnel/scripts.pory"
	end
# 342 "data/maps/RusturfTunnel/scripts.pory"

# 343 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PushPlayerAsideForGrunt:
# 344 "data/maps/RusturfTunnel/scripts.pory"
	face_down
# 345 "data/maps/RusturfTunnel/scripts.pory"
	lock_facing_direction
# 346 "data/maps/RusturfTunnel/scripts.pory"
	walk_up
# 347 "data/maps/RusturfTunnel/scripts.pory"
	unlock_facing_direction
# 348 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_left
# 349 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 350 "data/maps/RusturfTunnel/scripts.pory"

# 351 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerMoveAsideForBriney:
# 352 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 353 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_up
# 354 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 355 "data/maps/RusturfTunnel/scripts.pory"

# 356 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_GruntEscape:
# 357 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 358 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 359 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 360 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 361 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 362 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 363 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 364 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 365 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 366 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 367 "data/maps/RusturfTunnel/scripts.pory"

# 368 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BrineyApproachPeeko1:
# 369 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 370 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 371 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 372 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 373 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 374 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 375 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 376 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 377 "data/maps/RusturfTunnel/scripts.pory"

# 378 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BrineyExit:
# 379 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 380 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 381 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 382 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 383 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 384 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 385 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 386 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 387 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 388 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 389 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 390 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 391 "data/maps/RusturfTunnel/scripts.pory"

# 392 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerWatchBrineyExit:
# 393 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 394 "data/maps/RusturfTunnel/scripts.pory"
	delay_8
# 395 "data/maps/RusturfTunnel/scripts.pory"
	delay_4
# 396 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_left
# 397 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 398 "data/maps/RusturfTunnel/scripts.pory"

# 399 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BrineyApproachPeeko2:
# 400 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 401 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 402 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 403 "data/maps/RusturfTunnel/scripts.pory"

# 404 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PeekoExit:
# 405 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 406 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 407 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 408 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 409 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 410 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 411 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 412 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 413 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 414 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 415 "data/maps/RusturfTunnel/scripts.pory"

# 416 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_Mike::
# 417 "data/maps/RusturfTunnel/scripts.pory"
	trainerbattle_single TRAINER_MIKE_2, RusturfTunnel_Text_MikeIntro, RusturfTunnel_Text_MikeDefeat
# 418 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_MikePostBattle, MSGBOX_AUTOCLOSE
# 419 "data/maps/RusturfTunnel/scripts.pory"
	end
# 420 "data/maps/RusturfTunnel/scripts.pory"

# 421 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_ComeAndGetSome:
# 422 "data/maps/RusturfTunnel/scripts.pory"
	.string "What, are you coming?\n"
# 423 "data/maps/RusturfTunnel/scripts.pory"
	.string "Come and get some, then!$"
# 424 "data/maps/RusturfTunnel/scripts.pory"

# 425 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_Peeko:
# 426 "data/maps/RusturfTunnel/scripts.pory"
	.string "PEEKO: Pii pihyoh!$"
# 427 "data/maps/RusturfTunnel/scripts.pory"

# 428 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_GruntIntro:
# 429 "data/maps/RusturfTunnel/scripts.pory"
	.string "Grah, keelhaul it all!\p"
# 430 "data/maps/RusturfTunnel/scripts.pory"
	.string "That hostage POKéMON turned out to\n"
# 431 "data/maps/RusturfTunnel/scripts.pory"
	.string "be worthless!\p"
# 432 "data/maps/RusturfTunnel/scripts.pory"
	.string "And to think I made a getaway…\n"
# 433 "data/maps/RusturfTunnel/scripts.pory"
	.string "In this tunnel to nowhere!\p"
# 434 "data/maps/RusturfTunnel/scripts.pory"
	.string "Hey! You!\n"
# 435 "data/maps/RusturfTunnel/scripts.pory"
	.string "So you want to battle me?$"
# 436 "data/maps/RusturfTunnel/scripts.pory"

# 437 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_GruntDefeat:
# 438 "data/maps/RusturfTunnel/scripts.pory"
	.string "Urrrggh! My career in crime comes to\n"
# 439 "data/maps/RusturfTunnel/scripts.pory"
	.string "a dead end!$"
# 440 "data/maps/RusturfTunnel/scripts.pory"

# 441 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_GruntTakePackage:
# 442 "data/maps/RusturfTunnel/scripts.pory"
	.string "This is plain not right…\p"
# 443 "data/maps/RusturfTunnel/scripts.pory"
	.string "The BOSS told me this would be a\n"
# 444 "data/maps/RusturfTunnel/scripts.pory"
	.string "slick-and-easy job to pull.\p"
# 445 "data/maps/RusturfTunnel/scripts.pory"
	.string "All I had to do was steal some package\n"
# 446 "data/maps/RusturfTunnel/scripts.pory"
	.string "from DEVON.\p"
# 447 "data/maps/RusturfTunnel/scripts.pory"
	.string "Tch!\n"
# 448 "data/maps/RusturfTunnel/scripts.pory"
	.string "You want it back that badly, take it!$"
# 449 "data/maps/RusturfTunnel/scripts.pory"

# 450 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_PeekoGladToSeeYouSafe:
# 451 "data/maps/RusturfTunnel/scripts.pory"
	.string "PEEKO!\n"
# 452 "data/maps/RusturfTunnel/scripts.pory"
	.string "Am I glad to see you're safe!$"
# 453 "data/maps/RusturfTunnel/scripts.pory"

# 454 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_ThankYouLetsGoHomePeeko:
# 455 "data/maps/RusturfTunnel/scripts.pory"
	.string "PEEKO owes her life to you!\p"
# 456 "data/maps/RusturfTunnel/scripts.pory"
	.string "They call me MR. BRINEY.\n"
# 457 "data/maps/RusturfTunnel/scripts.pory"
	.string "And, you are?\p"
# 458 "data/maps/RusturfTunnel/scripts.pory"
	.string "… … … … … … … …\n"
# 459 "data/maps/RusturfTunnel/scripts.pory"
	.string "… … … … … … … …\p"
# 460 "data/maps/RusturfTunnel/scripts.pory"
	.string "Ah, so you are {PLAYER}{KUN}!\n"
# 461 "data/maps/RusturfTunnel/scripts.pory"
	.string "I sincerely thank you!\p"
# 462 "data/maps/RusturfTunnel/scripts.pory"
	.string "Now, if there's anything that troubles\n"
# 463 "data/maps/RusturfTunnel/scripts.pory"
	.string "you, don't hesitate to tell me!\p"
# 464 "data/maps/RusturfTunnel/scripts.pory"
	.string "You can usually find me in my cottage\n"
# 465 "data/maps/RusturfTunnel/scripts.pory"
	.string "by the sea near PETALBURG WOODS.\p"
# 466 "data/maps/RusturfTunnel/scripts.pory"
	.string "Come, PEEKO, we should make our way\n"
# 467 "data/maps/RusturfTunnel/scripts.pory"
	.string "home.\p"
# 468 "data/maps/RusturfTunnel/scripts.pory"
	.string "PEEKO: Pihyoh!$"
# 469 "data/maps/RusturfTunnel/scripts.pory"

# 470 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_WhyCantTheyKeepDigging:
# 471 "data/maps/RusturfTunnel/scripts.pory"
	.string "… …\p"
# 472 "data/maps/RusturfTunnel/scripts.pory"
	.string "Why can't they keep digging?\n"
# 473 "data/maps/RusturfTunnel/scripts.pory"
	.string "Is the bedrock too hard?\p"
# 474 "data/maps/RusturfTunnel/scripts.pory"
	.string "My beloved awaits me in VERDANTURF\n"
# 475 "data/maps/RusturfTunnel/scripts.pory"
	.string "TOWN just beyond here…\p"
# 476 "data/maps/RusturfTunnel/scripts.pory"
	.string "If RUSTBORO and VERDANTURF were\n"
# 477 "data/maps/RusturfTunnel/scripts.pory"
	.string "joined by this tunnel, I could visit\l"
# 478 "data/maps/RusturfTunnel/scripts.pory"
	.string "her every day…\p"
# 479 "data/maps/RusturfTunnel/scripts.pory"
	.string "But this…\n"
# 480 "data/maps/RusturfTunnel/scripts.pory"
	.string "What am I to do?$"
# 481 "data/maps/RusturfTunnel/scripts.pory"

# 482 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_ToGetToVerdanturf:
# 483 "data/maps/RusturfTunnel/scripts.pory"
	.string "To get from RUSTBORO to VERDANTURF,\n"
# 484 "data/maps/RusturfTunnel/scripts.pory"
	.string "you need to go to DEWFORD, then pass\l"
# 485 "data/maps/RusturfTunnel/scripts.pory"
	.string "through SLATEPORT and MAUVILLE…$"
# 486 "data/maps/RusturfTunnel/scripts.pory"

# 487 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_YouShatteredBoulderTakeHM:
# 488 "data/maps/RusturfTunnel/scripts.pory"
	.string "Wow! You shattered that boulder\n"
# 489 "data/maps/RusturfTunnel/scripts.pory"
	.string "blocking the way.\p"
# 490 "data/maps/RusturfTunnel/scripts.pory"
	.string "To show you how much I appreciate it,\n"
# 491 "data/maps/RusturfTunnel/scripts.pory"
	.string "I'd like you to have this HM.$"
# 492 "data/maps/RusturfTunnel/scripts.pory"

# 493 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_ExplainStrength:
# 494 "data/maps/RusturfTunnel/scripts.pory"
	.string "That HM contains STRENGTH.\p"
# 495 "data/maps/RusturfTunnel/scripts.pory"
	.string "If a muscular POKéMON were to learn\n"
# 496 "data/maps/RusturfTunnel/scripts.pory"
	.string "that, it would be able to move even\l"
# 497 "data/maps/RusturfTunnel/scripts.pory"
	.string "large boulders.$"
# 498 "data/maps/RusturfTunnel/scripts.pory"

# 499 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_WandaReunion:
# 500 "data/maps/RusturfTunnel/scripts.pory"
	.string "WANDA!\n"
# 501 "data/maps/RusturfTunnel/scripts.pory"
	.string "Now I can see you anytime!\p"
# 502 "data/maps/RusturfTunnel/scripts.pory"
	.string "WANDA: That's…wonderful.\p"
# 503 "data/maps/RusturfTunnel/scripts.pory"
	.string "Please, take some rest at my home.$"
# 504 "data/maps/RusturfTunnel/scripts.pory"

# 505 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_BoyfriendOnOtherSideOfRock:
# 506 "data/maps/RusturfTunnel/scripts.pory"
	.string "On the other side of this rock…\n"
# 507 "data/maps/RusturfTunnel/scripts.pory"
	.string "My boyfriend is there.\p"
# 508 "data/maps/RusturfTunnel/scripts.pory"
	.string "He… He's not just digging the tunnel\n"
# 509 "data/maps/RusturfTunnel/scripts.pory"
	.string "to come see me.\p"
# 510 "data/maps/RusturfTunnel/scripts.pory"
	.string "He works his hands raw and rough\n"
# 511 "data/maps/RusturfTunnel/scripts.pory"
	.string "for the benefit of everyone.$"
# 512 "data/maps/RusturfTunnel/scripts.pory"

# 513 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_MikeIntro:
# 514 "data/maps/RusturfTunnel/scripts.pory"
	.string "What do you call a wild man up in the\n"
# 515 "data/maps/RusturfTunnel/scripts.pory"
	.string "mountains? A mountain man, right?\p"
# 516 "data/maps/RusturfTunnel/scripts.pory"
	.string "So why don't they call a POKéMON in\n"
# 517 "data/maps/RusturfTunnel/scripts.pory"
	.string "the mountains a mountain POKéMON?$"
# 518 "data/maps/RusturfTunnel/scripts.pory"

# 519 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_MikeDefeat:
# 520 "data/maps/RusturfTunnel/scripts.pory"
	.string "My POKéMON…\n"
# 521 "data/maps/RusturfTunnel/scripts.pory"
	.string "Ran out of power…$"
# 522 "data/maps/RusturfTunnel/scripts.pory"

# 523 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_MikePostBattle:
# 524 "data/maps/RusturfTunnel/scripts.pory"
	.string "They halted development here to\n"
# 525 "data/maps/RusturfTunnel/scripts.pory"
	.string "protect POKéMON, right?\l"
# 526 "data/maps/RusturfTunnel/scripts.pory"
	.string "There's a feel-good story!$"
