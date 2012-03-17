#include "StdAfx.h"

ProcCondHandlerRes ProcHandler::Vengeance(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_CONTINUE_EXECUTION;

	if(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_HEALING)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::SealofBlood(ProcCondSharedDataStruct *shareddata)
{
	//we loose health depending on father of trigger spell when trigering this effect
	uint32 totaldmg = shareddata->Fulldmg + (shareddata->Fulldmg * 35) / 100;
	int32 healthtoloose = (shareddata->ospinfo->EffectBasePoints[1] * totaldmg) / 100;
	if(healthtoloose > (int32)shareddata->owner->GetUInt32Value(UNIT_FIELD_HEALTH))
	{
		shareddata->owner->SetUInt32Value(UNIT_FIELD_HEALTH, 1);
	}
	else
	{
		shareddata->owner->ModUnsigned32Value(UNIT_FIELD_HEALTH, -healthtoloose);
	}

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::ImprovedLayonHands(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->NameHash != SPELL_HASH_LAY_ON_HANDS)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::SpiritualAttunement(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	//trigger only on heal spell cast by NOT us
	if(!(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_HEALING) || shareddata->owner == shareddata->victim)
		return PROCCOND_BREAK_EXECUTION;

	//pokud mame vyssi rank tak mensi nesmi proc
	if(shareddata->owner->IsPlayer() && shareddata->origId == 31785 && TO_PLAYER(shareddata->owner)->mSpells.find(33776) != TO_PLAYER(shareddata->owner)->mSpells.end())
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::LightsGrace(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->NameHash != SPELL_HASH_HOLY_LIGHT)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::EyeforanEye(ProcCondSharedDataStruct *shareddata)
{
	//not self casted crits
	if(shareddata->victim == shareddata->owner)
		return PROCCOND_BREAK_EXECUTION; 

	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(!(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_DAMAGING))
		return PROCCOND_BREAK_EXECUTION;

	//this should contain the same values as the fixed ones
	shareddata->dmg_overwrite = (shareddata->Fulldmg * (shareddata->ospinfo->EffectBasePoints[0] + 1)) / 100 ; //only half dmg

	int32 half_health = shareddata->owner->GetUInt32Value(UNIT_FIELD_HEALTH) >> 1;
	if(shareddata->dmg_overwrite > half_health)
	{
		shareddata->dmg_overwrite = half_health;
	}

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::BlessedLife(ProcCondSharedDataStruct *shareddata)
{
	shareddata->resisted_dmg = shareddata->Fulldmg / 2;

	return PROCCOND_BREAK_EXECUTION;
}

ProcCondHandlerRes ProcHandler::SanctifiedJudgement(ProcCondSharedDataStruct *shareddata)
{
	//!! not working since we use post even hook and seal disapears before event
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->NameHash != SPELL_HASH_JUDGEMENT)
		return PROCCOND_BREAK_EXECUTION;

	if(!shareddata->owner->IsPlayer())
		return PROCCOND_BREAK_EXECUTION;

	Player* c = TO_PLAYER(shareddata->owner);
	if(!c->LastSeal)
		return PROCCOND_BREAK_EXECUTION;

	SpellEntry *spellInfo = dbcSpell.LookupEntryForced(c->LastSeal);
	if(!spellInfo)
		return PROCCOND_BREAK_EXECUTION;

	shareddata->dmg_overwrite = spellInfo->manaCost * (shareddata->ospinfo->EffectBasePoints[0] + 1) / 100 ; //only half dmg

	return PROCCOND_CONTINUE_EXECUTION;
}
