EventScript_RepelWoreOff::
    lockall
    msgbox Text_RepelPrompt, MSGBOX_DEFAULT
    yesnobox 20, 8                @ adjust coords if you like
    compare VAR_RESULT, 1         @ 0 = YES, 1 = NO (stock behavior)
    goto_if_eq EventScript_TryUseAnotherRepel
    releaseall
    end

EventScript_TryUseAnotherRepel::
    compare VAR_LAST_REPEL_USED, ITEM_REPEL
    goto_if_eq EventScript_CheckNormalRepel
    compare VAR_LAST_REPEL_USED, ITEM_SUPER_REPEL
    goto_if_eq EventScript_CheckSuperRepel
    compare VAR_LAST_REPEL_USED, ITEM_MAX_REPEL
    goto_if_eq EventScript_CheckMaxRepel
    @ Safety fallback if var is unexpected: do nothing
    releaseall

EventScript_CheckNormalRepel::
    checkitem ITEM_REPEL, 1
	compare VAR_RESULT, TRUE
    goto_if_eq EventScript_ConsumeNormalRepel
    msgbox Text_RepelNoneLeft, MSGBOX_DEFAULT
    releaseall
    end

EventScript_CheckSuperRepel::
    checkitem ITEM_SUPER_REPEL, 1
	compare VAR_RESULT, TRUE
    goto_if_eq EventScript_ConsumeSuperRepel
    msgbox Text_RepelNoneLeft, MSGBOX_DEFAULT
    releaseall
    end

EventScript_CheckMaxRepel::
    checkitem ITEM_MAX_REPEL, 1
	compare VAR_RESULT, TRUE
    goto_if_eq EventScript_ConsumeMaxRepel
    msgbox Text_RepelNoneLeft, MSGBOX_DEFAULT
    releaseall
    end

EventScript_ConsumeNormalRepel::
    removeitem ITEM_REPEL, 1
    setvar VAR_REPEL_STEP_COUNT, 100
    msgbox Text_RepelUsedAnother, MSGBOX_DEFAULT
    releaseall
    end

EventScript_ConsumeSuperRepel::
    removeitem ITEM_SUPER_REPEL, 1
    setvar VAR_REPEL_STEP_COUNT, 200
    msgbox Text_RepelUsedAnother, MSGBOX_DEFAULT
    releaseall
    end

EventScript_ConsumeMaxRepel::
    removeitem ITEM_MAX_REPEL, 1
    setvar VAR_REPEL_STEP_COUNT, 500   @ or 250 if you prefer vanilla
    msgbox Text_RepelUsedAnother, MSGBOX_DEFAULT
    releaseall
    end

@ ---------- Text ----------
Text_RepelPrompt:
	.string "Repel's effect wore off.\pUse another?$"

Text_RepelNoneLeft:
	.string "You don't have another one.$"

Text_RepelUsedAnother:
	.string "You used another Repel.$"
