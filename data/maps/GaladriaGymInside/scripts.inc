GaladriaGymInside_MapScripts::
	.byte 0


GymLeaderLeaf::
# 43 "data/maps/GaladriaGymInside/scripts.pory"
	lock
# 44 "data/maps/GaladriaGymInside/scripts.pory"
	faceplayer
# 45 "data/maps/GaladriaGymInside/scripts.pory"
	trainerbattle_double TRAINER_LEAF, LeafIntroText, LeafDefeatText, LeafMoreText, LeafDefeated, NO_MUSIC
# 46 "data/maps/GaladriaGymInside/scripts.pory"
	release
	end


LeafDefeated::
# 52 "data/maps/GaladriaGymInside/scripts.pory"
	setflag FLAG_GRASS_GYM
# 53 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox LeafDefeated_Text_0
# 54 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 55 "data/maps/GaladriaGymInside/scripts.pory"
	release
	end


VenusaurTrainer::
# 60 "data/maps/GaladriaGymInside/scripts.pory"
	lock
# 61 "data/maps/GaladriaGymInside/scripts.pory"
	faceplayer
# 62 "data/maps/GaladriaGymInside/scripts.pory"
	goto_if_set TRAINER_RED, VenusaurTrainer_2
VenusaurTrainer_1:
# 65 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox VenusaurTrainer_Text_0
# 66 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 67 "data/maps/GaladriaGymInside/scripts.pory"
	trainerbattle_single TRAINER_RED, VenusaurIntro, VenusaurDefeatText, venesaurDefeat
# 68 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox VenusaurTrainer_Text_1
# 69 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 70 "data/maps/GaladriaGymInside/scripts.pory"
	release
	end

VenusaurTrainer_2:
# 63 "data/maps/GaladriaGymInside/scripts.pory"
	call venesaurDefeat
	goto VenusaurTrainer_1


venesaurDefeat::
# 75 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox VenusaurTrainer_Text_1
# 76 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 77 "data/maps/GaladriaGymInside/scripts.pory"
	applymovement Venesaur, Galadria_Movement_Ven
# 78 "data/maps/GaladriaGymInside/scripts.pory"
	waitmovement
# 79 "data/maps/GaladriaGymInside/scripts.pory"
	releaseall
	end


MeganiumTrainer::
# 84 "data/maps/GaladriaGymInside/scripts.pory"
	lock
# 85 "data/maps/GaladriaGymInside/scripts.pory"
	faceplayer
# 86 "data/maps/GaladriaGymInside/scripts.pory"
	goto_if_set TRAINER_MAY_PLACEHOLDER, MeganiumTrainer_2
MeganiumTrainer_1:
# 89 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox MeganiumTrainer_Text_0
# 90 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 91 "data/maps/GaladriaGymInside/scripts.pory"
	trainerbattle_single TRAINER_MAY_PLACEHOLDER, MeganiumIntro, MeganiumDefeatText, meganiumDefeat
# 92 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox MeganiumTrainer_Text_1
# 93 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 94 "data/maps/GaladriaGymInside/scripts.pory"
	release
	end

MeganiumTrainer_2:
# 87 "data/maps/GaladriaGymInside/scripts.pory"
	call meganiumDefeat
	goto MeganiumTrainer_1


meganiumDefeat::
# 99 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox MeganiumTrainer_Text_1
# 100 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 101 "data/maps/GaladriaGymInside/scripts.pory"
	applymovement Meganium, Galadria_Movement_Meg
# 102 "data/maps/GaladriaGymInside/scripts.pory"
	waitmovement
# 103 "data/maps/GaladriaGymInside/scripts.pory"
	releaseall
	end


BreloomTrainer::
# 108 "data/maps/GaladriaGymInside/scripts.pory"
	lock
# 109 "data/maps/GaladriaGymInside/scripts.pory"
	faceplayer
# 110 "data/maps/GaladriaGymInside/scripts.pory"
	goto_if_set TRAINER_BRENDAN_PLACEHOLDER, BreloomTrainer_2
BreloomTrainer_1:
# 113 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox BreloomTrainer_Text_0
# 114 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 115 "data/maps/GaladriaGymInside/scripts.pory"
	trainerbattle_single TRAINER_BRENDAN_PLACEHOLDER, BreloomIntro, BreloomDefeatText, breloomDefeat
# 116 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox BreloomTrainer_Text_1
# 117 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 118 "data/maps/GaladriaGymInside/scripts.pory"
	release
	end

BreloomTrainer_2:
# 111 "data/maps/GaladriaGymInside/scripts.pory"
	call breloomDefeat
	goto BreloomTrainer_1


breloomDefeat::
# 123 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox BreloomTrainer_Text_1
# 124 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 125 "data/maps/GaladriaGymInside/scripts.pory"
	applymovement Breloom, Galadria_Movement_Bre
# 126 "data/maps/GaladriaGymInside/scripts.pory"
	waitmovement
# 127 "data/maps/GaladriaGymInside/scripts.pory"
	releaseall
	end


LeafDefeated_Text_0:
# 53 "data/maps/GaladriaGymInside/scripts.pory"
	.string "The Elite 4 awaits...$"

VenusaurTrainer_Text_0:
# 65 "data/maps/GaladriaGymInside/scripts.pory"
	.string "Venesaur is slept on!$"

VenusaurTrainer_Text_1:
# 68 "data/maps/GaladriaGymInside/scripts.pory"
	.string "You still won't beat Leaf!$"

MeganiumTrainer_Text_0:
# 89 "data/maps/GaladriaGymInside/scripts.pory"
	.string "This is my dream.$"

MeganiumTrainer_Text_1:
# 92 "data/maps/GaladriaGymInside/scripts.pory"
	.string "I dream a lot...$"

BreloomTrainer_Text_0:
# 113 "data/maps/GaladriaGymInside/scripts.pory"
	.string "Brawly was too weak for me.$"

BreloomTrainer_Text_1:
# 116 "data/maps/GaladriaGymInside/scripts.pory"
	.string "I know Brawly went easy on me.$"

LeafIntroText::
# 4 "data/maps/GaladriaGymInside/scripts.pory"
	.string "Welcome challenger!\nI'm Leaf, the Grass-type Gym Leader.\p"
	.string "Let’s see if you can cut through my vines of victory!$"

LeafDefeatText::
# 9 "data/maps/GaladriaGymInside/scripts.pory"
	.string "You've pruned your way to victory...\nWell done, trainer.$"

LeafMoreText::
# 13 "data/maps/GaladriaGymInside/scripts.pory"
	.string "You're not ready for this.$"

VenusaurIntro::
# 18 "data/maps/GaladriaGymInside/scripts.pory"
	.string "You don't deserve Leaf.\nMy VENUSAUR will sleep you!.\p$"

VenusaurDefeatText::
# 22 "data/maps/GaladriaGymInside/scripts.pory"
	.string "GAH, My spore missed...$"

MeganiumIntro::
# 26 "data/maps/GaladriaGymInside/scripts.pory"
	.string "I like sleeping all day.\nLeaf let's me, that's why she's the best!\p$"

MeganiumDefeatText::
# 30 "data/maps/GaladriaGymInside/scripts.pory"
	.string "Hmmm, I think I need a nap.$"

BreloomIntro::
# 34 "data/maps/GaladriaGymInside/scripts.pory"
	.string "I could never beat Leaf though.\nLeaf's the best!\p$"

BreloomDefeatText::
# 38 "data/maps/GaladriaGymInside/scripts.pory"
	.string "Ugh, I need to train more.$"
