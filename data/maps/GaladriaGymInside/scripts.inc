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
	msgbox VenusaurTrainer_Text_0
# 63 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 64 "data/maps/GaladriaGymInside/scripts.pory"
	trainerbattle_single TRAINER_RED, VenusaurIntro, VenusaurDefeatText
# 65 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox VenusaurTrainer_Text_1
# 66 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 67 "data/maps/GaladriaGymInside/scripts.pory"
	release
	end


MeganiumTrainer::
# 72 "data/maps/GaladriaGymInside/scripts.pory"
	lock
# 73 "data/maps/GaladriaGymInside/scripts.pory"
	faceplayer
# 74 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox MeganiumTrainer_Text_0
# 75 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 76 "data/maps/GaladriaGymInside/scripts.pory"
	trainerbattle_single TRAINER_MAY_PLACEHOLDER, MeganiumIntro, MeganiumDefeatText
# 77 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox MeganiumTrainer_Text_1
# 78 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 79 "data/maps/GaladriaGymInside/scripts.pory"
	release
	end


BreloomTrainer::
# 84 "data/maps/GaladriaGymInside/scripts.pory"
	lock
# 85 "data/maps/GaladriaGymInside/scripts.pory"
	faceplayer
# 86 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox BreloomTrainer_Text_0
# 87 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 88 "data/maps/GaladriaGymInside/scripts.pory"
	trainerbattle_single TRAINER_BRENDAN_PLACEHOLDER, BreloomIntro, BreloomDefeatText
# 89 "data/maps/GaladriaGymInside/scripts.pory"
	msgbox BreloomTrainer_Text_1
# 90 "data/maps/GaladriaGymInside/scripts.pory"
	waitmessage
# 91 "data/maps/GaladriaGymInside/scripts.pory"
	release
	end


LeafDefeated_Text_0:
# 53 "data/maps/GaladriaGymInside/scripts.pory"
	.string "The Elite 4 awaits...$"

VenusaurTrainer_Text_0:
# 62 "data/maps/GaladriaGymInside/scripts.pory"
	.string "Venesaur is slept on!$"

VenusaurTrainer_Text_1:
# 65 "data/maps/GaladriaGymInside/scripts.pory"
	.string "You still won't beat Leaf!$"

MeganiumTrainer_Text_0:
# 74 "data/maps/GaladriaGymInside/scripts.pory"
	.string "This is my dream.$"

MeganiumTrainer_Text_1:
# 77 "data/maps/GaladriaGymInside/scripts.pory"
	.string "I dream a lot...$"

BreloomTrainer_Text_0:
# 86 "data/maps/GaladriaGymInside/scripts.pory"
	.string "Brawly was too weak for me.$"

BreloomTrainer_Text_1:
# 89 "data/maps/GaladriaGymInside/scripts.pory"
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
