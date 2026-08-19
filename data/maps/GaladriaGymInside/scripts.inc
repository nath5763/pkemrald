GaladriaGymInside_MapScripts::
# 2 "data/maps/GaladriaGymInside/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, GaladriaGymInside_OnLoad
	.byte 0


GaladriaGymInside_OnLoad::
# 6 "data/maps/GaladriaGymInside/scripts.pory"
	goto_if_set FLAG_GALADRIA_GYM_VENUSAUR_MOVED, GaladriaGymInside_OnLoad_2
GaladriaGymInside_OnLoad_1:
# 10 "data/maps/GaladriaGymInside/scripts.pory"
	goto_if_set FLAG_GALADRIA_GYM_MEGANIUM_MOVED, GaladriaGymInside_OnLoad_5
GaladriaGymInside_OnLoad_4:
# 14 "data/maps/GaladriaGymInside/scripts.pory"
	goto_if_set FLAG_GALADRIA_GYM_BRELOOM_MOVED, GaladriaGymInside_OnLoad_7
	return

GaladriaGymInside_OnLoad_2:
# 7 "data/maps/GaladriaGymInside/scripts.pory"
	setobjectxyperm Venesaur, 3, 7
# 8 "data/maps/GaladriaGymInside/scripts.pory"
	setobjectmovementtype Venesaur, MOVEMENT_TYPE_FACE_RIGHT
	goto GaladriaGymInside_OnLoad_1

GaladriaGymInside_OnLoad_5:
# 11 "data/maps/GaladriaGymInside/scripts.pory"
	setobjectxyperm Meganium, 14, 8
# 12 "data/maps/GaladriaGymInside/scripts.pory"
	setobjectmovementtype Meganium, MOVEMENT_TYPE_FACE_LEFT
	goto GaladriaGymInside_OnLoad_4

GaladriaGymInside_OnLoad_7:
# 15 "data/maps/GaladriaGymInside/scripts.pory"
	setobjectxyperm Breloom, 17, 4
# 16 "data/maps/GaladriaGymInside/scripts.pory"
	setobjectmovementtype Breloom, MOVEMENT_TYPE_FACE_LEFT
	return


GymLeaderLeaf::
# 59 "data/maps/GaladriaGymInside/scripts.pory"
	lock
# 60 "data/maps/GaladriaGymInside/scripts.pory"
	faceplayer
# 61 "data/maps/GaladriaGymInside/scripts.pory"
	trainerbattle_double TRAINER_LEAF, LeafIntroText, LeafDefeatText, Leaf_no_mon, LeafDefeated, NO_MUSIC
# 62 "data/maps/GaladriaGymInside/scripts.pory"
	release
	end


LeafDefeated::
# 68 "data/maps/GaladriaGymInside/scripts.pory"
	setflag FLAG_GRASS_GYM
# 69 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox LeafDefeated_Text_0
# 70 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 71 "data/maps/GaladriaGymInside/scripts.pory"
	release
	end


VenusaurTrainer::
# 76 "data/maps/GaladriaGymInside/scripts.pory"
	lock
# 77 "data/maps/GaladriaGymInside/scripts.pory"
	faceplayer
# 78 "data/maps/GaladriaGymInside/scripts.pory"
	goto_if_defeated TRAINER_RED, VenusaurTrainer_Defeated
# 79 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox VenusaurTrainer_Text_0
# 80 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 81 "data/maps/GaladriaGymInside/scripts.pory"
	trainerbattle_single TRAINER_RED, VenusaurIntro, VenusaurDefeatText, venesaurDefeat
# 82 "data/maps/GaladriaGymInside/scripts.pory"
	releaseall
	end


VenusaurTrainer_Defeated::
# 87 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox VenusaurTrainer_Defeated_Text_0
# 88 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 89 "data/maps/GaladriaGymInside/scripts.pory"
	releaseall
	end


venesaurDefeat::
# 94 "data/maps/GaladriaGymInside/scripts.pory"
	setflag FLAG_GALADRIA_GYM_VENUSAUR_MOVED
# 95 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox VenusaurTrainer_Defeated_Text_0
# 96 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 97 "data/maps/GaladriaGymInside/scripts.pory"
	applymovement Venesaur, Galadria_Movement_Ven
# 98 "data/maps/GaladriaGymInside/scripts.pory"
	waitmovement
# 99 "data/maps/GaladriaGymInside/scripts.pory"
	releaseall
	end


MeganiumTrainer::
# 104 "data/maps/GaladriaGymInside/scripts.pory"
	lock
# 105 "data/maps/GaladriaGymInside/scripts.pory"
	faceplayer
# 106 "data/maps/GaladriaGymInside/scripts.pory"
	goto_if_defeated TRAINER_MAY_PLACEHOLDER, MeganiumTrainer_Defeated
# 107 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox MeganiumTrainer_Text_0
# 108 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 109 "data/maps/GaladriaGymInside/scripts.pory"
	trainerbattle_single TRAINER_MAY_PLACEHOLDER, MeganiumIntro, MeganiumDefeatText, meganiumDefeat
# 110 "data/maps/GaladriaGymInside/scripts.pory"
	releaseall
	end


MeganiumTrainer_Defeated::
# 115 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox MeganiumTrainer_Defeated_Text_0
# 116 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 117 "data/maps/GaladriaGymInside/scripts.pory"
	releaseall
	end


meganiumDefeat::
# 122 "data/maps/GaladriaGymInside/scripts.pory"
	setflag FLAG_GALADRIA_GYM_MEGANIUM_MOVED
# 123 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox MeganiumTrainer_Defeated_Text_0
# 124 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 125 "data/maps/GaladriaGymInside/scripts.pory"
	applymovement Meganium, Galadria_Movement_Meg
# 126 "data/maps/GaladriaGymInside/scripts.pory"
	waitmovement
# 127 "data/maps/GaladriaGymInside/scripts.pory"
	releaseall
	end


BreloomTrainer::
# 132 "data/maps/GaladriaGymInside/scripts.pory"
	lock
# 133 "data/maps/GaladriaGymInside/scripts.pory"
	faceplayer
# 134 "data/maps/GaladriaGymInside/scripts.pory"
	goto_if_defeated TRAINER_BRENDAN_PLACEHOLDER, BreloomTrainer_Defeated
# 135 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox BreloomTrainer_Text_0
# 136 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 137 "data/maps/GaladriaGymInside/scripts.pory"
	trainerbattle_single TRAINER_BRENDAN_PLACEHOLDER, BreloomIntro, BreloomDefeatText, breloomDefeat
# 138 "data/maps/GaladriaGymInside/scripts.pory"
	releaseall
	end


BreloomTrainer_Defeated::
# 143 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox BreloomTrainer_Defeated_Text_0
# 144 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 145 "data/maps/GaladriaGymInside/scripts.pory"
	releaseall
	end


breloomDefeat::
# 150 "data/maps/GaladriaGymInside/scripts.pory"
	setflag FLAG_GALADRIA_GYM_BRELOOM_MOVED
# 151 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox BreloomTrainer_Defeated_Text_0
# 152 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 153 "data/maps/GaladriaGymInside/scripts.pory"
	applymovement Breloom, Galadria_Movement_Bre
# 154 "data/maps/GaladriaGymInside/scripts.pory"
	waitmovement
# 155 "data/maps/GaladriaGymInside/scripts.pory"
	releaseall
	end


LeafDefeated_Text_0:
# 69 "data/maps/GaladriaGymInside/scripts.pory"
	.string "The Elite 4 awaits...$"

VenusaurTrainer_Text_0:
# 79 "data/maps/GaladriaGymInside/scripts.pory"
	.string "Venesaur is slept on!$"

VenusaurTrainer_Defeated_Text_0:
# 87 "data/maps/GaladriaGymInside/scripts.pory"
	.string "You still won't beat Leaf!$"

MeganiumTrainer_Text_0:
# 107 "data/maps/GaladriaGymInside/scripts.pory"
	.string "This is my dream.$"

MeganiumTrainer_Defeated_Text_0:
# 115 "data/maps/GaladriaGymInside/scripts.pory"
	.string "I dream a lot...$"

BreloomTrainer_Text_0:
# 135 "data/maps/GaladriaGymInside/scripts.pory"
	.string "Brawly was too weak for me.$"

BreloomTrainer_Defeated_Text_0:
# 143 "data/maps/GaladriaGymInside/scripts.pory"
	.string "I know Brawly went easy on me.$"

LeafIntroText::
# 20 "data/maps/GaladriaGymInside/scripts.pory"
	.string "Welcome challenger!\nI'm Leaf, the Grass-type Gym Leader.\p"
	.string "Let’s see if you can cut through my vines of victory!$"

LeafDefeatText::
# 25 "data/maps/GaladriaGymInside/scripts.pory"
	.string "You've pruned your way to victory...\nWell done, trainer.$"

LeafMoreText::
# 29 "data/maps/GaladriaGymInside/scripts.pory"
	.string "You're not ready for this.$"

VenusaurIntro::
# 34 "data/maps/GaladriaGymInside/scripts.pory"
	.string "You don't deserve Leaf.\nMy VENUSAUR will sleep you!.\p$"

VenusaurDefeatText::
# 38 "data/maps/GaladriaGymInside/scripts.pory"
	.string "GAH, My spore missed...$"

MeganiumIntro::
# 42 "data/maps/GaladriaGymInside/scripts.pory"
	.string "I like sleeping all day.\nLeaf let's me, that's why she's the best!\p$"

MeganiumDefeatText::
# 46 "data/maps/GaladriaGymInside/scripts.pory"
	.string "Hmmm, I think I need a nap.$"

BreloomIntro::
# 50 "data/maps/GaladriaGymInside/scripts.pory"
	.string "I could never beat Leaf though.\nLeaf's the best!\p$"

BreloomDefeatText::
# 54 "data/maps/GaladriaGymInside/scripts.pory"
	.string "Ugh, I need to train more.$"

Leaf_no_mon::
# 159 "data/maps/GaladriaGymInside/scripts.pory"
	.string "A single blossom is beautiful,\n but a garden thrives in numbers…$"
