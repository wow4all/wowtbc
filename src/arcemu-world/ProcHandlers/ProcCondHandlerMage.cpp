#include "StdAfx.h"

ProcCondHandlerRes ProcHandler::ArcaneBlast(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->NameHash != SPELL_HASH_ARCANE_BLAST) //Arcane Blast
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::Ignite(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->School != SCHOOL_FIRE)
		return PROCCOND_BREAK_EXECUTION;

	SpellEntry * spellInfo = dbcSpell.LookupEntryForced(shareddata->spellId);
	SpellDuration*  sd = dbcSpellDuration.LookupEntryForced(spellInfo->DurationIndex);
	uint32 tickcount = GetDuration(sd) / spellInfo->EffectAmplitude[0];
	shareddata->dmg_overwrite = shareddata->ospinfo->EffectBasePoints[0] * shareddata->Fulldmg / (100  * tickcount);

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::ImprovedScorch(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	//only trigger effect for specified spells
	if(shareddata->CastingSpell->NameHash != SPELL_HASH_SCORCH) //Scorch
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::Combustion(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	//only trigger effect for specified spells
	if(!(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_DAMAGING)	|| shareddata->CastingSpell->School != SCHOOL_FIRE)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->ProcFlags & PROC_ON_SPELL_CRIT_HIT)
	{
		shareddata->cur_itr->procCharges++;

		//whatch that number cause it depends on original stack count !
		if(shareddata->cur_itr->procCharges >= 3)
		{
			shareddata->owner->RemoveAllAuraByNameHash(SPELL_HASH_COMBUSTION);
			return PROCCOND_BREAK_EXECUTION;
		}
	}

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::WintersChill(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	// Winter's Chill shouldn't proc on self
	if(shareddata->victim == shareddata->owner || shareddata->CastingSpell->School != SCHOOL_FROST)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::ArcaneConcentration(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(!(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_DAMAGING))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::ImprovedBlizzard(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	//Blizzard
	if(shareddata->CastingSpell->NameHash != SPELL_HASH_BLIZZARD || shareddata->victim == shareddata->owner)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::MasterofElements(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	//fire and frost criticals
	if(shareddata->CastingSpell->School != SCHOOL_FIRE && shareddata->CastingSpell->School != SCHOOL_FROST)
		return PROCCOND_BREAK_EXECUTION;

	shareddata->dmg_overwrite = shareddata->CastingSpell->manaCost * (shareddata->ospinfo->EffectBasePoints[0] + 1) / 100;

	return PROCCOND_CONTINUE_EXECUTION;
}