GymLeaderLeaf::
# 35 "data/maps/GaladriaGymInside/scripts.pory"
	lock
# 36 "data/maps/GaladriaGymInside/scripts.pory"
	faceplayer
# 37 "data/maps/GaladriaGymInside/scripts.pory"
	trainerbattle_single TRAINER_LEAF, LeafIntroText, LeafDefeatText
# 38 "data/maps/GaladriaGymInside/scripts.pory"
	setflag FLAG_GRASS_GYM
# 39 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox GymLeaderLeaf_Text_0
# 40 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 41 "data/maps/GaladriaGymInside/scripts.pory"
	release
	end


VenusaurTrainer::
# 46 "data/maps/GaladriaGymInside/scripts.pory"
	lock
# 47 "data/maps/GaladriaGymInside/scripts.pory"
	faceplayer
# 48 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox VenusaurTrainer_Text_0
# 49 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 50 "data/maps/GaladriaGymInside/scripts.pory"
	trainerbattle_single TRAINER_RED, VenusaurIntro, VenusaurDefeatText
# 51 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox VenusaurTrainer_Text_1
# 52 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 53 "data/maps/GaladriaGymInside/scripts.pory"
	release
	end


MeganiumTrainer::
# 58 "data/maps/GaladriaGymInside/scripts.pory"
	lock
# 59 "data/maps/GaladriaGymInside/scripts.pory"
	faceplayer
# 60 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox MeganiumTrainer_Text_0
# 61 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 62 "data/maps/GaladriaGymInside/scripts.pory"
	trainerbattle_single TRAINER_MAY_PLACEHOLDER, MeganiumIntro, MeganiumDefeatText
# 63 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox MeganiumTrainer_Text_1
# 64 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 65 "data/maps/GaladriaGymInside/scripts.pory"
	release
	end


BreloomTrainer::
# 70 "data/maps/GaladriaGymInside/scripts.pory"
	lock
# 71 "data/maps/GaladriaGymInside/scripts.pory"
	faceplayer
# 72 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox BreloomTrainer_Text_0
# 73 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 74 "data/maps/GaladriaGymInside/scripts.pory"
	trainerbattle_single TRAINER_BRENDAN_PLACEHOLDER, BreloomIntro, BreloomDefeatText
# 75 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox BreloomTrainer_Text_1
# 76 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 77 "data/maps/GaladriaGymInside/scripts.pory"
	release
	end


GymLeaderLeaf_Text_0:
# 39 "data/maps/GaladriaGymInside/scripts.pory"
	.string "The Elite 4 awaits...$"

VenusaurTrainer_Text_0:
# 48 "data/maps/GaladriaGymInside/scripts.pory"
	.string "Venesaur is slept on!$"

VenusaurTrainer_Text_1:
# 51 "data/maps/GaladriaGymInside/scripts.pory"
	.string "You still won't beat Leaf!$"

MeganiumTrainer_Text_0:
# 60 "data/maps/GaladriaGymInside/scripts.pory"
	.string "This is my dream.$"

MeganiumTrainer_Text_1:
# 63 "data/maps/GaladriaGymInside/scripts.pory"
	.string "I dream a lot...$"

BreloomTrainer_Text_0:
# 72 "data/maps/GaladriaGymInside/scripts.pory"
	.string "Brawly was too weak for me.$"

BreloomTrainer_Text_1:
# 75 "data/maps/GaladriaGymInside/scripts.pory"
	.string "I know Brawly went easy on me.$"

LeafIntroText::
# 1 "data/maps/GaladriaGymInside/scripts.pory"
	.string "Welcome challenger!\nI'm Leaf, the Grass-type Gym Leader.\p"
	.string "Let’s see if you can cut through my vines of victory!$"

LeafDefeatText::
# 6 "data/maps/GaladriaGymInside/scripts.pory"
	.string "You've pruned your way to victory...\nWell done, trainer.$"

VenusaurIntro::
# 10 "data/maps/GaladriaGymInside/scripts.pory"
	.string "You don't deserve Leaf.\nMy VENUSAUR will sleep you!.\p$"

VenusaurDefeatText::
# 14 "data/maps/GaladriaGymInside/scripts.pory"
	.string "GAH, My spore missed...$"

MeganiumIntro::
# 18 "data/maps/GaladriaGymInside/scripts.pory"
	.string "I like sleeping all day.\nLeaf let's me, that's why she's the best!\p$"

MeganiumDefeatText::
# 22 "data/maps/GaladriaGymInside/scripts.pory"
	.string "Hmmm, I think I need a nap.$"

BreloomIntro::
# 26 "data/maps/GaladriaGymInside/scripts.pory"
	.string "I could never beat Leaf though.\nLeaf's the best!\p$"

BreloomDefeatText::
# 30 "data/maps/GaladriaGymInside/scripts.pory"
	.string "Ugh, I need to train more.$"
