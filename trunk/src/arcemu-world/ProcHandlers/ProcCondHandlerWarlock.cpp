
#include "StdAfx.h"

ProcCondHandlerRes ProcHandler::ImprovedShadowBolt(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	//only trigger effect for specified spells
	if(shareddata->CastingSpell->NameHash!=SPELL_HASH_SHADOW_BOLT)//shadow bolt								
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::Nighfall(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	//only trigger effect for specified spells
	if(shareddata->CastingSpell->NameHash != SPELL_HASH_CORRUPTION && //Corruption
		shareddata->CastingSpell->NameHash != SPELL_HASH_DRAIN_LIFE)//Drain Life								
	{
		return PROCCOND_BREAK_EXECUTION;
	}

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::ShadowEmbrace(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->NameHash != SPELL_HASH_CORRUPTION && // Corruption
		shareddata->CastingSpell->NameHash != SPELL_HASH_CURSE_OF_AGONY && //CoA
		shareddata->CastingSpell->NameHash != SPELL_HASH_SIPHON_LIFE && //Siphon Life
		shareddata->CastingSpell->NameHash != SPELL_HASH_SEED_OF_CORRUPTION) //SoC
	{
		return PROCCOND_BREAK_EXECUTION;
	}

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::Aftermath(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	//only trigger effect for specified spells
	skilllinespell* skillability = objmgr.GetSpellSkill(shareddata->CastingSpell->Id);
	if(!skillability)
		return PROCCOND_BREAK_EXECUTION;

	if(skillability->skilline != SKILL_DESTRUCTION)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::SeedofCorruption(ProcCondSharedDataStruct *shareddata)
{
	bool can_proc_now = false;
	//if we proced on spell tick
	if(shareddata->ProcFlags & PROC_ON_SPELL_HIT_VICTIM)
	{
		if(shareddata->CastingSpell == NULL)
			return PROCCOND_BREAK_EXECUTION;

		//this spell builds up in time
		shareddata->cur_itr->procCharges += shareddata->Fulldmg;

		//if charge built up																		//if this is not a killer blow
		if((int32)shareddata->cur_itr->procCharges >= shareddata->ospinfo->EffectBasePoints[1] && shareddata->Fulldmg < (int32)shareddata->owner->GetUInt32Value(UNIT_FIELD_HEALTH)) 
		{
			can_proc_now = true;
		}
	}
	else 
	{
		//target died
		can_proc_now = true;
	}

	if(can_proc_now == false)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->owner->isAlive())
	{
		SpellEntry * spellInfo = dbcSpell.LookupEntryForced(shareddata->spellId);
		SPELLPOINTER spell = SpellPool.PooledNew();
		spell->Init(shareddata->owner, spellInfo, true, NULLAUR);
		SpellCastTargets targets;
		targets.m_targetMask = TARGET_FLAG_DEST_LOCATION;
		targets.m_destX = shareddata->owner->GetPositionX();
		targets.m_destY = shareddata->owner->GetPositionY();
		targets.m_destZ = shareddata->owner->GetPositionZ();
		spell->prepare(&targets);

		shareddata->owner->RemoveAllAuraByNameHash(SPELL_HASH_SEED_OF_CORRUPTION);
	}

	shareddata->cur_itr->deleted = true;

	return PROCCOND_BREAK_EXECUTION;
}

ProcCondHandlerRes ProcHandler::ImprovedDrainSoul(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;
	
	if(shareddata->CastingSpell->NameHash != SPELL_HASH_DRAIN_SOUL)						
		return PROCCOND_BREAK_EXECUTION;
	
	shareddata->dmg_overwrite = (shareddata->ospinfo->EffectBasePoints[2] + 1) * shareddata->owner->GetUInt32Value(UNIT_FIELD_MAXPOWER1) / 100;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::UnstableAffliction(ProcCondSharedDataStruct *shareddata)
{
	shareddata->dmg_overwrite = (shareddata->ospinfo->EffectBasePoints[0] + 1) * 9;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::SoulLink(ProcCondSharedDataStruct *shareddata)
{
	//we need a pet for this, else we do not trigger it at all
	if(shareddata->owner->IsPlayer())
		return PROCCOND_BREAK_EXECUTION;

	Unit* new_caster = NULL;
	if(shareddata->owner->GetSummon())
	{
		new_caster = shareddata->owner->GetSummon();
	}
	else if(shareddata->owner->GetUInt64Value(UNIT_FIELD_CHARM))
	{
		new_caster = shareddata->owner->GetMapMgrUnit(shareddata->owner->GetUInt64Value(UNIT_FIELD_CHARM));
	}

	if(new_caster != NULL && new_caster->isAlive())
	{
		SpellEntry* spellInfo = dbcSpell.LookupEntryForced(25228);
		SPELLPOINTER spell = SpellPool.PooledNew();
		spell->Init(new_caster, spellInfo, true, NULLAUR);
		spell->forced_basepoints[0] = shareddata->Fulldmg;
		SpellCastTargets targets(shareddata->owner->GetGUID());
		spell->prepare(&targets);
	}

	return PROCCOND_BREAK_EXECUTION;
}

ProcCondHandlerRes ProcHandler::NetherProtection(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	//only trigger effect for specified spells
	if(!(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_DAMAGING))
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->School != SCHOOL_FIRE && shareddata->CastingSpell->School != SCHOOL_SHADOW)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::SoulLeech(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	//only trigger effect for specified spells
	int32 amount = 0;
	switch(shareddata->CastingSpell->NameHash)
	{
	case SPELL_HASH_SHADOW_BOLT:	//Shadow Bolt
	case SPELL_HASH_SOUL_FIRE:		//Soul Fire
	case SPELL_HASH_INCINERATE:		//Incinerate
	case SPELL_HASH_SEARING_PAIN:	//Searing Pain
	case SPELL_HASH_CONFLAGRATE:	//Conflagrate
		{
			amount = shareddata->CastingSpell->EffectBasePoints[0] + 1;
		}break;
	case SPELL_HASH_SHADOWBURN:		//Shadowburn
		{
			amount = shareddata->CastingSpell->EffectBasePoints[1] + 1;
		}break;
	default:
		{
			amount = 0;
		}
	}

	if(!amount)
		return PROCCOND_BREAK_EXECUTION;

	SpellEntry *spellInfo = dbcSpell.LookupEntryForced(shareddata->spellId);
	if(!spellInfo)
		return PROCCOND_BREAK_EXECUTION;

	SPELLPOINTER spell = SpellPool.PooledNew();
	spell->Init(shareddata->owner, spellInfo, true, NULLAUR);
	spell->SetUnitTarget(shareddata->owner);
	spell->Heal(amount * (shareddata->ospinfo->EffectBasePoints[0] + 1) / 100);
	SpellPool.PooledDelete(spell);

	return PROCCOND_BREAK_EXECUTION;
}

ProcCondHandlerRes ProcHandler::Pyroclasm(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	//only trigger effect for specified spells
	if (shareddata->CastingSpell->NameHash != SPELL_HASH_RAIN_OF_FIRE &&	//Rain of Fire
		shareddata->CastingSpell->NameHash != SPELL_HASH_HELLFIRE_EFFECT && //Hellfire
		shareddata->CastingSpell->NameHash != SPELL_HASH_SOUL_FIRE)			//Soul Fire
	{
		return PROCCOND_BREAK_EXECUTION;
	}

	return PROCCOND_CONTINUE_EXECUTION;
}