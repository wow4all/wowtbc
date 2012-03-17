
#include "StdAfx.h"

ProcCondHandlerRes ProcHandler::Flexibility(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell || shareddata->CastingSpell->NameHash != SPELL_HASH_FLASH_HEAL)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::Flameshadow(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell || shareddata->CastingSpell->School != SCHOOL_SHADOW || !(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_DAMAGING))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::Shadowflame(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell || shareddata->CastingSpell->School != SCHOOL_FIRE || !(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_DAMAGING))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::WaveTrance(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell || !(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_HEALING))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::Charged(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell || !(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_DAMAGING))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

//Energized
ProcCondHandlerRes ProcHandler::Energized1(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->NameHash != SPELL_HASH_LIGHTNING_BOLT)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::Energized2(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell || !(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_DAMAGING))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::Relentlessness(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell || !(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_DAMAGING))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::LightningBoltDiscount(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell || shareddata->CastingSpell->NameHash != SPELL_HASH_LIGHTNING_BOLT)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::InfusedShield(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell || shareddata->CastingSpell->NameHash != SPELL_HASH_HOLY_SHIELD)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::DivineLight(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell)
		return PROCCOND_BREAK_EXECUTION;

	if (shareddata->CastingSpell->NameHash != SPELL_HASH_JUDGEMENT_OF_THE_CRUSADER &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_JUDGEMENT_OF_JUSTICE &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_JUDGEMENT_OF_LIGHT &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_JUDGEMENT_OF_WISDOM &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_JUDGEMENT_OF_RIGHTEOUSNESS &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_JUDGEMENT_OF_BLOOD &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_JUDGEMENT_OF_VENGEANCE &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_JUDGEMENT_OF_COMMAND)
	{
		return PROCCOND_BREAK_EXECUTION;
	}

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::Judgement(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell)
		return PROCCOND_BREAK_EXECUTION;

	if (shareddata->CastingSpell->NameHash != SPELL_HASH_JUDGEMENT_OF_THE_CRUSADER &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_JUDGEMENT_OF_JUSTICE &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_JUDGEMENT_OF_LIGHT &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_JUDGEMENT_OF_WISDOM &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_JUDGEMENT_OF_RIGHTEOUSNESS &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_JUDGEMENT_OF_BLOOD &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_JUDGEMENT_OF_VENGEANCE &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_JUDGEMENT_OF_COMMAND)
	{
		return PROCCOND_BREAK_EXECUTION;
	}

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::Enlightenment(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell || (shareddata->CastingSpell->NameHash != SPELL_HASH_FLASH_OF_LIGHT && shareddata->CastingSpell->NameHash != SPELL_HASH_HOLY_LIGHT))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::Overpower(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell || shareddata->CastingSpell->NameHash != SPELL_HASH_OVERPOWER)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::Revenge(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell || shareddata->CastingSpell->Id == 37517 || shareddata->CastingSpell->NameHash != SPELL_HASH_REVENGE)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::Epiphany(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::ManaSurge(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell || shareddata->CastingSpell->NameHash != SPELL_HASH_REPLENISH_MANA)
		return PROCCOND_BREAK_EXECUTION; 

	return PROCCOND_CONTINUE_EXECUTION;
}