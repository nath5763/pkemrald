ChampionsClub_MapScripts::
	.byte 0


ChampionsClub_EventScript_WorthySign::
# 6 "data/maps/ChampionsClub/scripts.pory"
	lockall
# 7 "data/maps/ChampionsClub/scripts.pory"
	goto_if_set FLAG_DEFEATED_SIRUS, ChampionsClub_EventScript_WorthySign_2
ChampionsClub_EventScript_WorthySign_1:
# 10 "data/maps/ChampionsClub/scripts.pory"
	msgbox ChampionsClub_Text_OnlyWorthyShallPass
# 11 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end

ChampionsClub_EventScript_WorthySign_2:
# 8 "data/maps/ChampionsClub/scripts.pory"
	goto ChampionsClub_EventScript_WorthyWarp
	goto ChampionsClub_EventScript_WorthySign_1


ChampionsClub_EventScript_WorthyWarp::
# 16 "data/maps/ChampionsClub/scripts.pory"
	warp MAP_CHAMPIONS_CLUB_FLOOR2, 2, 9
# 17 "data/maps/ChampionsClub/scripts.pory"
	waitstate
	end


benLoss::
# 27 "data/maps/ChampionsClub/scripts.pory"
	setflag FLAG_DEFEATED_BEN
# 28 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end


benFight::
# 33 "data/maps/ChampionsClub/scripts.pory"
	lockall
# 34 "data/maps/ChampionsClub/scripts.pory"
	faceplayer
# 35 "data/maps/ChampionsClub/scripts.pory"
	goto_if_unset FLAG_IS_CHAMPION, benFight_2
# 41 "data/maps/ChampionsClub/scripts.pory"
	goto_if_set FLAG_DEFEATED_BEN, benFight_5
# 46 "data/maps/ChampionsClub/scripts.pory"
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, benFight_7
# 51 "data/maps/ChampionsClub/scripts.pory"
	msgbox benPre
# 52 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end

benFight_2:
# 36 "data/maps/ChampionsClub/scripts.pory"
	msgbox noChamp
# 37 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end

benFight_5:
# 42 "data/maps/ChampionsClub/scripts.pory"
	msgbox benFight_Text_0
# 43 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end

benFight_7:
# 47 "data/maps/ChampionsClub/scripts.pory"
	trainerbattle_single TRAINER_TEST, benReady, benDefeat, benLoss
# 48 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end


ryanLoss::
# 58 "data/maps/ChampionsClub/scripts.pory"
	setflag FLAG_DEFEATED_RYAN
# 59 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end


ryanFight::
# 64 "data/maps/ChampionsClub/scripts.pory"
	lockall
# 65 "data/maps/ChampionsClub/scripts.pory"
	faceplayer
# 66 "data/maps/ChampionsClub/scripts.pory"
	goto_if_set FLAG_DEFEATED_RYAN, ryanFight_2
# 71 "data/maps/ChampionsClub/scripts.pory"
	goto_if_set FLAG_DEFEATED_BEN, ryanFight_4
# 76 "data/maps/ChampionsClub/scripts.pory"
	msgbox ryanPre
# 77 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end

ryanFight_2:
# 67 "data/maps/ChampionsClub/scripts.pory"
	msgbox benFight_Text_0
# 68 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end

ryanFight_4:
# 72 "data/maps/ChampionsClub/scripts.pory"
	trainerbattle_single TRAINER_RYAN_TEST, ryanReady, ryanDefeat, ryanLoss
# 73 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end


angieLoss::
# 83 "data/maps/ChampionsClub/scripts.pory"
	setflag FLAG_DEFEATED_ANGIE
# 84 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end


angieFight::
# 89 "data/maps/ChampionsClub/scripts.pory"
	lockall
# 90 "data/maps/ChampionsClub/scripts.pory"
	faceplayer
# 91 "data/maps/ChampionsClub/scripts.pory"
	goto_if_set FLAG_DEFEATED_ANGIE, angieFight_2
# 96 "data/maps/ChampionsClub/scripts.pory"
	goto_if_set FLAG_DEFEATED_RYAN, angieFight_4
# 101 "data/maps/ChampionsClub/scripts.pory"
	msgbox angiePre
# 102 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end

angieFight_2:
# 92 "data/maps/ChampionsClub/scripts.pory"
	msgbox benFight_Text_0
# 93 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end

angieFight_4:
# 97 "data/maps/ChampionsClub/scripts.pory"
	trainerbattle_single TRAINER_ANGIE_TEST, angieReady, angieDefeat, angieLoss
# 98 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end


sirusLoss::
# 108 "data/maps/ChampionsClub/scripts.pory"
	setflag FLAG_DEFEATED_SIRUS
# 109 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end


sirusFight::
# 114 "data/maps/ChampionsClub/scripts.pory"
	lockall
# 115 "data/maps/ChampionsClub/scripts.pory"
	faceplayer
# 116 "data/maps/ChampionsClub/scripts.pory"
	goto_if_set FLAG_DEFEATED_SIRUS, sirusFight_2
# 121 "data/maps/ChampionsClub/scripts.pory"
	goto_if_set FLAG_DEFEATED_ANGIE, sirusFight_4
# 126 "data/maps/ChampionsClub/scripts.pory"
	msgbox sirusPre
# 127 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end

sirusFight_2:
# 117 "data/maps/ChampionsClub/scripts.pory"
	msgbox benFight_Text_0
# 118 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end

sirusFight_4:
# 122 "data/maps/ChampionsClub/scripts.pory"
	trainerbattle_single TRAINER_ANGIE_TEST, sirusReady, sirusDefeat, sirusLoss
# 123 "data/maps/ChampionsClub/scripts.pory"
	releaseall
	end


benFight_Text_0:
# 42 "data/maps/ChampionsClub/scripts.pory"
	.string "Others are ready.$"

ChampionsClub_Text_OnlyWorthyShallPass::
# 21 "data/maps/ChampionsClub/scripts.pory"
	.string "Only the worthy shall pass.$"

noChamp::
# 132 "data/maps/ChampionsClub/scripts.pory"
	.string "Hey Kid,\n we're all champions here.\p If you want fight,\n at least beat Steven.$"

benPre::
# 136 "data/maps/ChampionsClub/scripts.pory"
	.string "Congrats on champion.\n If you beat Steven I will \p give you a shot.$"

benReady::
# 140 "data/maps/ChampionsClub/scripts.pory"
	.string "So you can beat Steven,\n let's see how you fare.$"

benDefeat::
# 144 "data/maps/ChampionsClub/scripts.pory"
	.string "Wow...$"

ryanPre::
# 148 "data/maps/ChampionsClub/scripts.pory"
	.string "You're not ready for me.$"

ryanReady::
# 152 "data/maps/ChampionsClub/scripts.pory"
	.string "Took you long enough.$"

ryanDefeat::
# 156 "data/maps/ChampionsClub/scripts.pory"
	.string "Fine, you're good.$"

angiePre::
# 160 "data/maps/ChampionsClub/scripts.pory"
	.string "Prove you're ready to fight me.\n Ryan's ego could go down a peg.$"

angieReady::
# 164 "data/maps/ChampionsClub/scripts.pory"
	.string "HAHA\n I love seeing ryan mad. \n Let's give it a whirl!$"

angieDefeat::
# 168 "data/maps/ChampionsClub/scripts.pory"
	.string "Congrats on becoming\n one of the greatest.$"

sirusPre::
# 172 "data/maps/ChampionsClub/scripts.pory"
	.string "Unless you beat everyone else,\n I'm not giving you a shot.$"

sirusReady::
# 176 "data/maps/ChampionsClub/scripts.pory"
	.string "You have some skill, \n LETS GOOOOOO$"

sirusDefeat::
# 180 "data/maps/ChampionsClub/scripts.pory"
	.string "The Champion of Champions!$"
