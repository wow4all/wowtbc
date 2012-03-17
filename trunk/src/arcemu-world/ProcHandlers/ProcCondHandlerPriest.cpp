#include "StdAfx.h"

ProcCondHandlerRes ProcHandler::Blackout(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->School != SCHOOL_SHADOW || !(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_DAMAGING))
		return PROCCOND_BREAK_EXECUTION;
	
	//sice shadow dmg ale neni to shadow spell
	if(shareddata->CastingSpell->NameHash == SPELL_HASH_MANA_BURN)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::HolyConcentration(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->owner->IsPlayer())
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->NameHash != SPELL_HASH_FLASH_HEAL &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_BINDING_HEAL &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_GREATER_HEAL)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::PrayerofMending(ProcCondSharedDataStruct *shareddata)
{
	//victim got a hit in the face so we jump on next injured target
	//find aura on self and get it's value
	AURAPOINTER pa = shareddata->owner->FindAura(shareddata->origId);
	if(!pa)
		return PROCCOND_BREAK_EXECUTION; 

	//check if we jumped proctimes
	if(pa->GetModAmount(0) == 1)
		return PROCCOND_BREAK_EXECUTION;

	//we use same caster as firts caster to be able to get heal bonuses !
	Unit * oricaster = shareddata->owner->GetMapMgrUnit(pa->GetCasterGUID());
	if(!oricaster || !oricaster->IsPlayer())
		return PROCCOND_BREAK_EXECUTION;

	//get a new target
	Player * p_caster			= TO_PLAYER(oricaster);
	Player * First_new_target	= NULL;
	Player * Next_new_target	= NULL;
	Player * First_whatever		= NULL;
	bool passed_prev_target		= false;
	bool stop					= false;
	
	//MIRA - 20y 
	float range = 20.0f;
	range *= range;

	if(p_caster->GetGroup())
	{
		p_caster->GetGroup()->Lock();
		for(uint32 i = 0;i < p_caster->GetGroup()->GetSubGroupCount();++i)
		{
			SubGroup * pGroup = p_caster->GetGroup()->GetSubGroup(i);
			if(pGroup)
			{
				for(GroupMembersSet::iterator itr = pGroup->GetGroupMembersBegin();itr != pGroup->GetGroupMembersEnd(); ++itr)
				{
					if(!(*itr)->m_loggedInPlayer || !(*itr)->m_loggedInPlayer->isAlive())
						continue;

					//we cannot retarget self
					if((*itr)->m_loggedInPlayer == shareddata->owner) 
					{
						passed_prev_target = true;
						continue;
					}

					if(sCommonMgr.IsInrange(p_caster,(*itr)->m_loggedInPlayer, range))
					{

						if(!First_whatever)
							First_whatever = (*itr)->m_loggedInPlayer;

						//we target stuff that has no full health. No idea if we must fill target list or not :(
						if(First_whatever && (*itr)->m_loggedInPlayer->GetUInt32Value(UNIT_FIELD_HEALTH) == (*itr)->m_loggedInPlayer->GetUInt32Value(UNIT_FIELD_MAXHEALTH))
							continue;

						//first targatable player in group (like make circular buffer from normal list)
						if(!First_new_target)
							First_new_target = (*itr)->m_loggedInPlayer; 

						if(passed_prev_target)
						{
							Next_new_target = (*itr)->m_loggedInPlayer;
							stop = true;
							break;
						}
					}
				}
				if(stop)
					break;
			}
		}
		p_caster->GetGroup()->Unlock();
	}
	if(First_new_target && !Next_new_target)
		Next_new_target = First_new_target; //we passed end of the list and it is time to restart it

	if(!Next_new_target)
		Next_new_target = First_whatever; //we passed end of the list and it is time to restart it

	if(Next_new_target)
	{
		SPELLPOINTER spell = SpellPool.PooledNew();
		spell->Init(oricaster, shareddata->ospinfo, true, NULLAUR);
		spell->forced_basepoints[0] = pa->GetModAmount(0) - 1;
		SpellCastTargets targets(Next_new_target->GetGUID());
		spell->prepare(&targets);
	}

	//MIRA - pridame bonusy castera
	int32 amount = sSpellMgr.CalculateSpellEffectFromProto(oricaster, shareddata->cur_itr->i, shareddata->spe);
	int32 bonus = 0;

	//Basic bonus
	bonus += oricaster->HealDoneMod[SCHOOL_HOLY];
	if(Next_new_target)
	{
		bonus += Next_new_target->HealTakenMod[SCHOOL_HOLY];
	}

	//Bonus from Intellect & Spirit
	if(oricaster->IsPlayer())
	{
		for(uint32 a = 0; a < 5; ++a)
		{
			bonus += float2int32(TO_PLAYER(oricaster)->SpellHealDoneByAttribute[a][SCHOOL_HOLY] * oricaster->GetUInt32Value(UNIT_FIELD_STAT0 + a));
		}
	}

	//Apply healing coef on the bonus!
	//Spellentry returns bullshit
	bonus *= 1.5f/3.5f;

	//apply bonus
	amount += bonus;
	amount += amount * oricaster->HealDonePctMod[SCHOOL_HOLY] / 100;
	if(Next_new_target)
	{
		amount += float2int32(float(amount) * Next_new_target->HealTakenPctMod[SCHOOL_HOLY]);
	}

	shareddata->dmg_overwrite = amount;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::Misery(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
	{
		return PROCCOND_BREAK_EXECUTION;
	}
	else
	{
		if( shareddata->CastingSpell->NameHash != SPELL_HASH_MIND_FLAY &&			// Mind Flay
			shareddata->CastingSpell->NameHash != SPELL_HASH_SHADOW_WORD__PAIN &&	//SW:P
			shareddata->CastingSpell->NameHash != SPELL_HASH_VAMPIRIC_TOUCH)		//SoC
		{
			return PROCCOND_BREAK_EXECUTION;
		}
	}

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::ShadowWeaving(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->School != SCHOOL_SHADOW || !(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_DAMAGING))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::Inspiration(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell || !(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_HEALING))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::BlessedRecovery(ProcCondSharedDataStruct *shareddata)
{
    if(!shareddata->owner->IsPlayer() || !shareddata->Fulldmg)
        return PROCCOND_BREAK_EXECUTION;

    SpellEntry *parentproc= dbcSpell.LookupEntryForced(shareddata->origId);
    SpellEntry *spellInfo = dbcSpell.LookupEntryForced(shareddata->spellId);
	if(!parentproc || !spellInfo)
		return PROCCOND_BREAK_EXECUTION;

	int32 val = parentproc->EffectBasePoints[0] + 1;
    SPELLPOINTER spell = SpellPool.PooledNew();
	spell->Init(shareddata->owner, spellInfo, true, NULLAUR);
    spell->forced_basepoints[0] = (val * shareddata->Fulldmg) / 300; //per tick
    SpellCastTargets targets(shareddata->owner->GetGUID());
    spell->prepare(&targets);

    return PROCCOND_BREAK_EXECUTION;
}

ProcCondHandlerRes ProcHandler::Shadowguard(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell && (shareddata->owner == shareddata->victim || !(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_DAMAGING)))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::ReflectiveShield(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->Absdmg)
		return PROCCOND_BREAK_EXECUTION;

	//requires Power Word: Shield active
	uint32 power_word_id = shareddata->owner->HasAurasWithNameHash(SPELL_HASH_POWER_WORD__SHIELD);
	if(!power_word_id)
		return PROCCOND_BREAK_EXECUTION;

	//make a direct strike then exit rest of handler
	int tdmg = shareddata->Absdmg * (shareddata->ospinfo->EffectBasePoints[0] + 1) / 100;

	//somehow we should make this not caused any threat (tobedone)
	shareddata->owner->SpellNonMeleeDamageLog(shareddata->victim, power_word_id, tdmg, false, true);

	return PROCCOND_BREAK_EXECUTION;
}

ProcCondHandlerRes ProcHandler::BlessedResilience(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_HEALING)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}