GaladriaGymInside_MapScripts::
	.byte 0


GymLeaderLeaf::
# 38 "data/maps/GaladriaGymInside/scripts.pory"
	lock
# 39 "data/maps/GaladriaGymInside/scripts.pory"
	faceplayer
# 40 "data/maps/GaladriaGymInside/scripts.pory"
	trainerbattle_single TRAINER_LEAF, LeafIntroText, LeafDefeatText
# 41 "data/maps/GaladriaGymInside/scripts.pory"
	setflag FLAG_GRASS_GYM
# 42 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox GymLeaderLeaf_Text_0
# 43 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 44 "data/maps/GaladriaGymInside/scripts.pory"
	release
	end


VenusaurTrainer::
# 49 "data/maps/GaladriaGymInside/scripts.pory"
	lock
# 50 "data/maps/GaladriaGymInside/scripts.pory"
	faceplayer
# 51 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox VenusaurTrainer_Text_0
# 52 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 53 "data/maps/GaladriaGymInside/scripts.pory"
	trainerbattle_single TRAINER_RED, VenusaurIntro, VenusaurDefeatText
# 54 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox VenusaurTrainer_Text_1
# 55 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 56 "data/maps/GaladriaGymInside/scripts.pory"
	release
	end


MeganiumTrainer::
# 61 "data/maps/GaladriaGymInside/scripts.pory"
	lock
# 62 "data/maps/GaladriaGymInside/scripts.pory"
	faceplayer
# 63 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox MeganiumTrainer_Text_0
# 64 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 65 "data/maps/GaladriaGymInside/scripts.pory"
	trainerbattle_single TRAINER_MAY_PLACEHOLDER, MeganiumIntro, MeganiumDefeatText
# 66 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox MeganiumTrainer_Text_1
# 67 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 68 "data/maps/GaladriaGymInside/scripts.pory"
	release
	end


BreloomTrainer::
# 73 "data/maps/GaladriaGymInside/scripts.pory"
	lock
# 74 "data/maps/GaladriaGymInside/scripts.pory"
	faceplayer
# 75 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox BreloomTrainer_Text_0
# 76 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 77 "data/maps/GaladriaGymInside/scripts.pory"
	trainerbattle_single TRAINER_BRENDAN_PLACEHOLDER, BreloomIntro, BreloomDefeatText
# 78 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox BreloomTrainer_Text_1
# 79 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 80 "data/maps/GaladriaGymInside/scripts.pory"
	release
	end


GymLeaderLeaf_Text_0:
# 42 "data/maps/GaladriaGymInside/scripts.pory"
	.string "The Elite 4 awaits...$"

VenusaurTrainer_Text_0:
# 51 "data/maps/GaladriaGymInside/scripts.pory"
	.string "Venesaur is slept on!$"

VenusaurTrainer_Text_1:
# 54 "data/maps/GaladriaGymInside/scripts.pory"
	.string "You still won't beat Leaf!$"

MeganiumTrainer_Text_0:
# 63 "data/maps/GaladriaGymInside/scripts.pory"
	.string "This is my dream.$"

MeganiumTrainer_Text_1:
# 66 "data/maps/GaladriaGymInside/scripts.pory"
	.string "I dream a lot...$"

BreloomTrainer_Text_0:
# 75 "data/maps/GaladriaGymInside/scripts.pory"
	.string "Brawly was too weak for me.$"

BreloomTrainer_Text_1:
# 78 "data/maps/GaladriaGymInside/scripts.pory"
	.string "I know Brawly went easy on me.$"

LeafIntroText::
# 4 "data/maps/GaladriaGymInside/scripts.pory"
	.string "Welcome challenger!\nI'm Leaf, the Grass-type Gym Leader.\p"
	.string "Let’s see if you can cut through my vines of victory!$"

LeafDefeatText::
# 9 "data/maps/GaladriaGymInside/scripts.pory"
	.string "You've pruned your way to victory...\nWell done, trainer.$"

VenusaurIntro::
# 13 "data/maps/GaladriaGymInside/scripts.pory"
	.string "You don't deserve Leaf.\nMy VENUSAUR will sleep you!.\p$"

VenusaurDefeatText::
# 17 "data/maps/GaladriaGymInside/scripts.pory"
	.string "GAH, My spore missed...$"

MeganiumIntro::
# 21 "data/maps/GaladriaGymInside/scripts.pory"
	.string "I like sleeping all day.\nLeaf let's me, that's why she's the best!\p$"

MeganiumDefeatText::
# 25 "data/maps/GaladriaGymInside/scripts.pory"
	.string "Hmmm, I think I need a nap.$"

BreloomIntro::
# 29 "data/maps/GaladriaGymInside/scripts.pory"
	.string "I could never beat Leaf though.\nLeaf's the best!\p$"

BreloomDefeatText::
# 33 "data/maps/GaladriaGymInside/scripts.pory"
	.string "Ugh, I need to train more.$"
