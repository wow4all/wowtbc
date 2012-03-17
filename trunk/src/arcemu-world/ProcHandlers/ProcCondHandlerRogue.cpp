
#include "StdAfx.h"

ProcCondHandlerRes ProcHandler::DeadlyThrowInterrupt(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->NameHash != SPELL_HASH_DEADLY_THROW)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::BladeTwisting(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	//only trigger effect for specified spells
	if(shareddata->CastingSpell->NameHash != SPELL_HASH_BACKSTAB && //backstab
		shareddata->CastingSpell->NameHash != SPELL_HASH_SINISTER_STRIKE && //sinister strike
		shareddata->CastingSpell->NameHash != SPELL_HASH_SHIV && //shiv
		shareddata->CastingSpell->NameHash != SPELL_HASH_GOUGE) //gouge
	{
		return PROCCOND_BREAK_EXECUTION;
	}

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::CombatPotency(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->owner->IsPlayer() || !shareddata->Fulldmg)
		return PROCCOND_BREAK_EXECUTION;

	//this needs offhand weapon
	Item* it = TO_PLAYER(shareddata->owner)->GetItemInterface()->GetInventoryItem(EQUIPMENT_SLOT_OFFHAND);

	if(!it || it->GetProto()->Class != ITEM_CLASS_WEAPON)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::Ruthlessness(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	//we need a finishing move for this 
	if(!(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_FINISHING_MOVE) || shareddata->victim == shareddata->owner)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::RelentlessStrikes(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	int32 proc_Chance = 0;

	//chance is based actually on combopoint count and not 100% always 
	if(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_FINISHING_MOVE && shareddata->owner->IsPlayer())
	{
		proc_Chance = TO_PLAYER(shareddata->owner)->m_comboPoints * shareddata->ospinfo->EffectBasePoints[1];
	}
	else 
		return PROCCOND_BREAK_EXECUTION;

	if(!Rand(proc_Chance))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::FindWeakness(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(!(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_FINISHING_MOVE))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::Initiative(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if (shareddata->CastingSpell->NameHash != SPELL_HASH_CHEAP_SHOT &&	//Cheap Shot
		shareddata->CastingSpell->NameHash != SPELL_HASH_AMBUSH &&		//Ambush
		shareddata->CastingSpell->NameHash != SPELL_HASH_GARROTE)		//Garrote
	{
		return PROCCOND_BREAK_EXECUTION;
	}

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::ImprovedSprint(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->NameHash != SPELL_HASH_SPRINT || shareddata->victim != shareddata->owner) //sprint
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}