ChampionsClub_MapScripts::
	.byte 0


benLoss::
# 7 "data/maps/ChampionsClub/scripts.pory"
	setflag FLAG_DEFEATED_BEN
# 8 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end


benFight::
# 13 "data/maps/ChampionsClub/scripts.pory"
	lockall
# 14 "data/maps/ChampionsClub/scripts.pory"
	faceplayer
# 15 "data/maps/ChampionsClub/scripts.pory"
	goto_if_unset FLAG_IS_CHAMPION, benFight_2
# 21 "data/maps/ChampionsClub/scripts.pory"
	goto_if_set FLAG_DEFEATED_BEN, benFight_5
# 26 "data/maps/ChampionsClub/scripts.pory"
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, benFight_7
# 31 "data/maps/ChampionsClub/scripts.pory"
	msgbox benPre
# 32 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end

benFight_2:
# 16 "data/maps/ChampionsClub/scripts.pory"
	msgbox noChamp
# 17 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end

benFight_5:
# 22 "data/maps/ChampionsClub/scripts.pory"
	msgbox benFight_Text_0
# 23 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end

benFight_7:
# 27 "data/maps/ChampionsClub/scripts.pory"
	trainerbattle_single TRAINER_TEST, benReady, benDefeat, benLoss
# 28 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end


ryanLoss::
# 38 "data/maps/ChampionsClub/scripts.pory"
	setflag FLAG_DEFEATED_RYAN
# 39 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end


ryanFight::
# 44 "data/maps/ChampionsClub/scripts.pory"
	lockall
# 45 "data/maps/ChampionsClub/scripts.pory"
	faceplayer
# 46 "data/maps/ChampionsClub/scripts.pory"
	goto_if_set FLAG_DEFEATED_RYAN, ryanFight_2
# 51 "data/maps/ChampionsClub/scripts.pory"
	goto_if_set FLAG_DEFEATED_BEN, ryanFight_4
# 56 "data/maps/ChampionsClub/scripts.pory"
	msgbox ryanPre
# 57 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end

ryanFight_2:
# 47 "data/maps/ChampionsClub/scripts.pory"
	msgbox benFight_Text_0
# 48 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end

ryanFight_4:
# 52 "data/maps/ChampionsClub/scripts.pory"
	trainerbattle_single TRAINER_RYAN_TEST, ryanReady, ryanDefeat, ryanLoss
# 53 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end


angieLoss::
# 63 "data/maps/ChampionsClub/scripts.pory"
	setflag FLAG_DEFEATED_ANGIE
# 64 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end


angieFight::
# 69 "data/maps/ChampionsClub/scripts.pory"
	lockall
# 70 "data/maps/ChampionsClub/scripts.pory"
	faceplayer
# 71 "data/maps/ChampionsClub/scripts.pory"
	goto_if_set FLAG_DEFEATED_ANGIE, angieFight_2
# 76 "data/maps/ChampionsClub/scripts.pory"
	goto_if_set FLAG_DEFEATED_RYAN, angieFight_4
# 81 "data/maps/ChampionsClub/scripts.pory"
	msgbox angiePre
# 82 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end

angieFight_2:
# 72 "data/maps/ChampionsClub/scripts.pory"
	msgbox benFight_Text_0
# 73 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end

angieFight_4:
# 77 "data/maps/ChampionsClub/scripts.pory"
	trainerbattle_single TRAINER_ANGIE_TEST, angieReady, angieDefeat, angieLoss
# 78 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end


sirusLoss::
# 88 "data/maps/ChampionsClub/scripts.pory"
	setflag FLAG_DEFEATED_SIRUS
# 89 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end


sirusFight::
# 94 "data/maps/ChampionsClub/scripts.pory"
	lockall
# 95 "data/maps/ChampionsClub/scripts.pory"
	faceplayer
# 96 "data/maps/ChampionsClub/scripts.pory"
	goto_if_set FLAG_DEFEATED_SIRUS, sirusFight_2
# 101 "data/maps/ChampionsClub/scripts.pory"
	goto_if_set FLAG_DEFEATED_ANGIE, sirusFight_4
# 106 "data/maps/ChampionsClub/scripts.pory"
	msgbox sirusPre
# 107 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end

sirusFight_2:
# 97 "data/maps/ChampionsClub/scripts.pory"
	msgbox benFight_Text_0
# 98 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end

sirusFight_4:
# 102 "data/maps/ChampionsClub/scripts.pory"
	trainerbattle_single TRAINER_ANGIE_TEST, sirusReady, sirusDefeat, sirusLoss
# 103 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end


benFight_Text_0:
# 22 "data/maps/ChampionsClub/scripts.pory"
	.string "Others are ready.$"

noChamp::
# 112 "data/maps/ChampionsClub/scripts.pory"
	.string "Hey Kid,\n we're all champions here.\p If you want fight,\n at least beat Steven.$"

benPre::
# 116 "data/maps/ChampionsClub/scripts.pory"
	.string "Congrats on champion.\n If you beat Steven I will \p give you a shot.$"

benReady::
# 120 "data/maps/ChampionsClub/scripts.pory"
	.string "So you can beat Steven,\n let's see how you fare.$"

benDefeat::
# 124 "data/maps/ChampionsClub/scripts.pory"
	.string "Wow...$"

ryanPre::
# 128 "data/maps/ChampionsClub/scripts.pory"
	.string "You're not ready for me.$"

ryanReady::
# 132 "data/maps/ChampionsClub/scripts.pory"
	.string "Took you long enough.$"

ryanDefeat::
# 136 "data/maps/ChampionsClub/scripts.pory"
	.string "Fine, you're good.$"

angiePre::
# 140 "data/maps/ChampionsClub/scripts.pory"
	.string "Prove you're ready to fight me.\n Ryan's ego could go down a peg.$"

angieReady::
# 144 "data/maps/ChampionsClub/scripts.pory"
	.string "HAHA\n I love seeing ryan mad. \n Let's give it a whirl!$"

angieDefeat::
# 148 "data/maps/ChampionsClub/scripts.pory"
	.string "Congrats on becoming\n one of the greatest.$"

sirusPre::
# 152 "data/maps/ChampionsClub/scripts.pory"
	.string "Unless you beat everyone else,\n I'm not giving you a shot.$"

sirusReady::
# 156 "data/maps/ChampionsClub/scripts.pory"
	.string "You have some skill, \n LETS GOOOOOO$"

sirusDefeat::
# 160 "data/maps/ChampionsClub/scripts.pory"
	.string "The Champion of Champions!$"
