
#include "StdAfx.h"

//Primal Fury Proc
ProcCondHandlerRes ProcHandler::PrimalFury(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->owner->IsPlayer())
		return PROCCOND_BREAK_EXECUTION;

	Player * p = TO_PLAYER(shareddata->owner);
	if(p->GetShapeShift() != FORM_BEAR && p->GetShapeShift() != FORM_DIREBEAR)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::PrimalFury2(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->owner->IsPlayer())
		return PROCCOND_BREAK_EXECUTION;

	Player* mPlayer = TO_PLAYER(shareddata->owner);

	if(!mPlayer->IsInFeralForm() || 
		(mPlayer->GetShapeShift() != FORM_CAT &&
		mPlayer->GetShapeShift() != FORM_BEAR &&
		mPlayer->GetShapeShift() != FORM_DIREBEAR))
	{
		return PROCCOND_BREAK_EXECUTION;
	}

	return PROCCOND_CONTINUE_EXECUTION;
}

//intencity
ProcCondHandlerRes ProcHandler::Intencity(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell || shareddata->CastingSpell->Id != 5229)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

//Blood Frenzy
ProcCondHandlerRes ProcHandler::BloodFrenzy(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->owner->IsPlayer() || !shareddata->CastingSpell)
		return PROCCOND_BREAK_EXECUTION;

	if (TO_PLAYER(shareddata->owner)->GetShapeShift() != FORM_CAT || (
		shareddata->CastingSpell->NameHash != SPELL_HASH_CLAW &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_RAKE &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_RAVAGE &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_SHRED))
	{
		return PROCCOND_BREAK_EXECUTION;
	}

	return PROCCOND_CONTINUE_EXECUTION;
}

//Seal Fate
ProcCondHandlerRes ProcHandler::SealFate(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->owner->IsPlayer() || !shareddata->CastingSpell)
		return PROCCOND_BREAK_EXECUTION;

	if (shareddata->CastingSpell->Id == 14189 ||
		shareddata->CastingSpell->Id == 16953 ||
		shareddata->CastingSpell->Id == 16959)
	{
		return PROCCOND_BREAK_EXECUTION;
	}

	if (shareddata->CastingSpell->Effect[0] != SPELL_EFFECT_ADD_COMBO_POINTS &&
		shareddata->CastingSpell->Effect[1] != SPELL_EFFECT_ADD_COMBO_POINTS &&
		shareddata->CastingSpell->Effect[2] != SPELL_EFFECT_ADD_COMBO_POINTS &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_MANGLE__CAT_)
	{
		return PROCCOND_BREAK_EXECUTION;
	}

	return PROCCOND_CONTINUE_EXECUTION;
}

//Bloodlust
ProcCondHandlerRes ProcHandler::Bloodlust(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->owner->IsPlayer())
		return PROCCOND_BREAK_EXECUTION;

	if (TO_PLAYER(shareddata->owner)->GetShapeShift() != FORM_BEAR ||
		TO_PLAYER(shareddata->owner)->GetShapeShift() != FORM_DIREBEAR)
	{
		return PROCCOND_BREAK_EXECUTION;
	}

	return PROCCOND_CONTINUE_EXECUTION;
}

//Bloodlust2
ProcCondHandlerRes ProcHandler::Bloodlust2(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->owner->IsPlayer())
		return PROCCOND_BREAK_EXECUTION;

	if(TO_PLAYER(shareddata->owner)->GetShapeShift() != FORM_CAT)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

//Moonkin Starfire Bonus
ProcCondHandlerRes ProcHandler::MoonkinStarfireBonus(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->NameHash != SPELL_HASH_WRATH)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

//Natural Perfection
ProcCondHandlerRes ProcHandler::NaturalPerfection(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_HEALING)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::CelestialFocus(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->NameHash != SPELL_HASH_STARFIRE)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::NaturesGrace(ProcCondSharedDataStruct *shareddata)
{
	shareddata->owner->RemoveAura(16886);

	return PROCCOND_CONTINUE_EXECUTION;
}