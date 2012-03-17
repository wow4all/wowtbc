
#include "StdAfx.h"

ProcCondHandlerRes ProcHandler::WindfuryWeapon(ProcCondSharedDataStruct *shareddata)
{
	//Should NEVER proc from ghost wolf
	if(!shareddata->owner->IsPlayer() || shareddata->owner->m_disarmed || TO_PLAYER(shareddata->owner)->GetShapeShift() == FORM_GHOSTWOLF)
		return PROCCOND_BREAK_EXECUTION;

	//!! The wierd thing is that we need the spell thet trigegred this enchant spell in order to output logs ..we are using oldspell info too 
	//we have to recalc the value of this spell
	SpellEntry * spellInfo		 = dbcSpell.LookupEntryForced(shareddata->origId);
	SpellEntry * sp_for_the_logs = dbcSpell.LookupEntryForced(shareddata->cur_itr->spellId);

	const int32 AP_owerride = sSpellMgr.CalculateSpellEffectFromProto(shareddata->owner, 0, spellInfo);
	const int32 dmg			= TO_PLAYER(shareddata->owner)->GetMainMeleeDamage(AP_owerride);

	//chance of dealing additional damage equal to two extra attacks with extra attack power
	if(shareddata->victim->isAlive())
	{
		shareddata->owner->Strike(shareddata->victim, MELEE, sp_for_the_logs, dmg, 0, 0, true, false);
	}

	if(shareddata->victim->isAlive())
	{
		shareddata->owner->Strike(shareddata->victim, MELEE, sp_for_the_logs, dmg, 0, 0, true, false);
	}

	//reset timeru
	TO_PLAYER(shareddata->owner)->setAttackTimer(0, true);
	TO_PLAYER(shareddata->owner)->setAttackTimer(0, false);

	// WF animation
	shareddata->spellId = 33010;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::LightningOverload(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	//trigger on lightning and chain lightning. Spell should be identical , well maybe next time :P
	if(shareddata->CastingSpell->NameHash == SPELL_HASH_LIGHTNING_BOLT || shareddata->CastingSpell->NameHash == SPELL_HASH_CHAIN_LIGHTNING)
	{
		shareddata->owner->CastSpell(shareddata->owner, 39805, true);
		
		shareddata->spellId = shareddata->CastingSpell->Id;
		shareddata->origId	= 39805;

		//we have to increase time to aura remove
		AURAPOINTER aur = shareddata->owner->FindAura(39805);
		if(aur)
		{
			int32 time = float2int32(sSpellMgr.GetSpellTimeToHit(shareddata->owner, shareddata->victim, shareddata->CastingSpell)) + 500;
			sEventMgr.ModifyEventTimeLeft(aur.get(), EVENT_AURA_REMOVE, time);
		}
		return PROCCOND_CONTINUE_EXECUTION;
	}

	return PROCCOND_BREAK_EXECUTION;
}

ProcCondHandlerRes ProcHandler::HealingWay(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->NameHash != SPELL_HASH_HEALING_WAVE)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::ElementalDevastation(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(!(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_DAMAGING))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::AncestralFortitude(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(!(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_HEALING))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::TotemoftheThirdWind(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->NameHash != SPELL_HASH_LESSER_HEALING_WAVE)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::FlametongueTotemAndFlametongueWeapon(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->owner->IsPlayer())
		return PROCCOND_BREAK_EXECUTION;

	if (shareddata->spellId == 25555 ||
		shareddata->spellId == 16389 ||
		shareddata->spellId == 10523 ||
		shareddata->spellId == 8248 ||
		shareddata->spellId == 8253)
	{
		shareddata->spellId = 16368;	// Flametongue Totem proc
	}
	else
	{
		shareddata->spellId = 29469;	// Flametongue Weapon proc
	}

	Item * mh = TO_PLAYER(shareddata->owner)->GetItemInterface()->GetInventoryItem(EQUIPMENT_SLOT_MAINHAND);
	if(mh != NULL)
	{
		float mhs = float(mh->GetProto()->Delay);
		shareddata->dmg_overwrite = FL2UINT(mhs * 0.001f * (shareddata->spe->EffectBasePoints[0] + 1) / 88);

		return PROCCOND_CONTINUE_EXECUTION;
	}
	else
		return PROCCOND_BREAK_EXECUTION;
}

ProcCondHandlerRes ProcHandler::Clearcasting(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION; 

	// Lightning Overload Proc is already free
	if(shareddata->origId == 39805)
		return PROCCOND_BREAK_EXECUTION; 

	if (shareddata->CastingSpell->NameHash != SPELL_HASH_LIGHTNING_BOLT&&
		shareddata->CastingSpell->NameHash != SPELL_HASH_CHAIN_LIGHTNING&&
		shareddata->CastingSpell->NameHash != SPELL_HASH_EARTH_SHOCK&&
		shareddata->CastingSpell->NameHash != SPELL_HASH_FLAME_SHOCK&&
		shareddata->CastingSpell->NameHash != SPELL_HASH_FROST_SHOCK)
	{
		return PROCCOND_BREAK_EXECUTION;
	}

	return PROCCOND_CONTINUE_EXECUTION;
}
