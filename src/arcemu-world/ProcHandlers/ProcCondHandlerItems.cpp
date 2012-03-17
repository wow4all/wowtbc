
#include "StdAfx.h"

ProcCondHandlerRes ProcHandler::LibramofDivineJudgement(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(!shareddata->owner->IsPlayer())
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->Id != 20271)
		return PROCCOND_BREAK_EXECUTION;

	Player * plr = TO_PLAYER(shareddata->owner);

	if(!sSpellMgr.IsIdSpellHash(plr->LastSeal, SPELL_HASH_SEAL_OF_COMMAND))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::LibramofAvengement(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(!shareddata->owner->IsPlayer())
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->Id != 20271)
		return PROCCOND_BREAK_EXECUTION;

	Player * plr = TO_PLAYER(shareddata->owner);

	if (!sSpellMgr.IsIdSpellHash(plr->LastSeal, SPELL_HASH_SEAL_OF_COMMAND) &&
		!sSpellMgr.IsIdSpellHash(plr->LastSeal, SPELL_HASH_SEAL_OF_RIGHTEOUSNESS) &&
		!sSpellMgr.IsIdSpellHash(plr->LastSeal, SPELL_HASH_SEAL_OF_BLOOD) &&
		!sSpellMgr.IsIdSpellHash(plr->LastSeal, SPELL_HASH_SEAL_OF_VENGEANCE))
	{
		return PROCCOND_BREAK_EXECUTION;
	}

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::StonebreakersTotem(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->NameHash != SPELL_HASH_FROST_SHOCK &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_EARTH_SHOCK &&  
		shareddata->CastingSpell->NameHash != SPELL_HASH_FLAME_SHOCK)
	{
		return PROCCOND_BREAK_EXECUTION;
	}

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::BrutalGladiatorsLibramofJustice(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->NameHash != SPELL_HASH_FLASH_OF_LIGHT)
	{
		return PROCCOND_BREAK_EXECUTION;
	}

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::ShatteredSunPendantofAcumen_ArcaneBolt(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(!(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_DAMAGING))
	{
		return PROCCOND_BREAK_EXECUTION;
	}

	if(shareddata->victim && shareddata->victim->IsPacified())
	{
		return PROCCOND_BREAK_EXECUTION;
	}

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::ShatteredSunPendantofRestoration(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(!(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_HEALING))
	{
		return PROCCOND_BREAK_EXECUTION;
	}

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::CommendationofKaelthas(ProcCondSharedDataStruct *shareddata)
{
	int32 procHealth = dbcSpell.LookupEntryForced(shareddata->origId)->EffectBasePoints[0] + 1;

	if(shareddata->owner->GetHealthPct() > procHealth)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::VialoftheSunwell(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(!(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_HEALING))
	{
		return PROCCOND_BREAK_EXECUTION;
	}

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::PendantoftheVioletEye(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(!shareddata->CastingSpell->manaCost && !shareddata->CastingSpell->ManaCostPercentage)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::TheLightningCapacitor(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(!(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_DAMAGING))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::CosmicInfuser(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(!(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_HEALING))
	{
		return PROCCOND_BREAK_EXECUTION;
	}

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::DFTrinkets(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->owner->IsPlayer())
		return PROCCOND_BREAK_EXECUTION;

	static const uint32 aurasOfMadness[8][2] =
	{
		{40997, 1103}, // Rogue, Hunter, Paladin, Warrior, Druid, Shaman
		//{41404, 1490}, // Druid, Shaman, Priest, Warlock, Mage, Paladin vojta: tenhle spell ma nejaky zabugovany targetovani, prozatim zakazu
		{40998, 1039}, // Warrior, Rogue, Paladin, Hunter, Druid
		{41005, 1499}, // All classes except Hunter
		{41011, 1503}, // All classes
		{40999, 1490}, // Druid, Shaman, Priest, Warlock, Mage, Paladin
		{41009, 1494}, // Druid, Shaman, Priest, Warlock, Mage, Paladin, Hunter
		{41002, 1499}, // All classes except Hunter
		{39511, 1035}  // Paladin, Rogue, Druid, Warrior
	};

	Uint32Vector possibleAuras;
	for(int32 i = 0; i < 8; ++i)
	{
		if(aurasOfMadness[i][1] & shareddata->owner->getClassMask())
			possibleAuras.push_back(aurasOfMadness[i][0]);
	}
	
	if(!possibleAuras.empty())
	{
		SpellEntry * sp = dbcSpell.LookupEntryForced(possibleAuras.at(RandomUInt(static_cast<uint32>(possibleAuras.size() - 1))));
		SPELLPOINTER spell = SpellPool.PooledNew();
		SpellCastTargets targets(shareddata->owner->GetGUID());
		spell->Init(shareddata->owner, sp, true, NULLAUR);
		spell->prepare(&targets);

		if(Rand(20))
		{
			WorldPacket data;
			sChatHandler.FillMessageData(data, CHAT_MSG_YELL, LANG_UNIVERSAL, "This is madness!", shareddata->owner->GetGUID(), 0);
			shareddata->owner->GetMapMgr()->SendChatMessageToCellPlayers(shareddata->owner, &data, 2, 1, LANG_UNIVERSAL, TO_PLAYER(shareddata->owner)->GetSession());
		}
	}

	return PROCCOND_BREAK_EXECUTION; // musime BREAK, protoze jinak se znovu zacasti spell z trinketu coz nechceme, protoze by to mohlo vest ke crashi serveru
}

ProcCondHandlerRes ProcHandler::TimbalsFocusingCrystal(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_HEALING)
		return PROCCOND_BREAK_EXECUTION;

	if(!(shareddata->CastingSpell->spell_coef_flags & SPELL_FLAG_IS_DOT_OR_HOT_SPELL))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::ShamanTier6TrinketEnergySurge(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->NameHash == SPELL_HASH_LESSER_HEALING_WAVE)
		return PROCCOND_CONTINUE_EXECUTION;

	if(shareddata->CastingSpell->NameHash == SPELL_HASH_LIGHTNING_BOLT)
		return PROCCOND_CONTINUE_EXECUTION;

	return PROCCOND_BREAK_EXECUTION;
}

ProcCondHandlerRes ProcHandler::ShamanTier6TrinketPowerSurge(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->NameHash != SPELL_HASH_STORMSTRIKE)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::PaladinTier6TrinketEnduringLight(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if (shareddata->CastingSpell->NameHash != SPELL_HASH_HOLY_LIGHT &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_FLASH_OF_LIGHT)
	{
		return PROCCOND_BREAK_EXECUTION;
	}

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::PaladinTier6TrinketEnduringJudgement(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->Id != 20271)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::GraceoftheNaaru(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->NameHash != SPELL_HASH_HOLY_LIGHT)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::Shadowmend(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if (shareddata->CastingSpell->School != SCHOOL_FROST &&
		shareddata->CastingSpell->School != SCHOOL_SHADOW)
	{
		return PROCCOND_BREAK_EXECUTION;
	}

	//Your Frost and Shadow damage spells heal you for 2% of the damage they deal.
	shareddata->dmg_overwrite = ((float)shareddata->Fulldmg * (2.0f / 100.0f));

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::DruidTier6TrinketBlessingofCenarius(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if (shareddata->CastingSpell->NameHash != SPELL_HASH_MANGLE &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_MANGLE__BEAR_ && 
		shareddata->CastingSpell->NameHash != SPELL_HASH_MANGLE__CAT_)
	{
		return PROCCOND_BREAK_EXECUTION;
	}

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::DruidTier6TrinketBlessingofRemulos(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->NameHash != SPELL_HASH_STARFIRE)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::DruidTier6TrinketBlessingofElune(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->NameHash != SPELL_HASH_REJUVENATION)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::Thunderfury(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->victim == shareddata->owner) 
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::SpellHasteTrinket(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	//MIRA - Spell haste trinkets are various other actions
	switch(shareddata->origId)
	{
	//http://www.wowhead.com/?spell=33297
	//MIRA - harmfull spells z trinke Quagmirran's Eye
	case 33297:
		{
			if(!(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_DAMAGING))
				return PROCCOND_BREAK_EXECUTION;	
		}break;
	//http://www.wowhead.com/?item=28190 scarab of the infinite cicle
	//MIRA - only healing spells
	case 33953:
		{
			if(!(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_HEALING))
				return PROCCOND_BREAK_EXECUTION;
		}break;
	}

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::BandoftheEternalSage(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(!(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_DAMAGING))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::AshtongueTalismanofShadows(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL || shareddata->CastingSpell->NameHash != SPELL_HASH_CORRUPTION)
		return PROCCOND_BREAK_EXECUTION; 

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::MementoofTyrande(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::AshtongueTalismanofInsight(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(!(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_DAMAGING))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::AshtongueTalismanofSwiftness(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL || shareddata->CastingSpell->NameHash != SPELL_HASH_STEADY_SHOT)
		return PROCCOND_BREAK_EXECUTION; 

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::AshtongueTalismanofValor(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL || (shareddata->CastingSpell->NameHash != SPELL_HASH_MORTAL_STRIKE && shareddata->CastingSpell->NameHash != SPELL_HASH_BLOODTHIRST && shareddata->CastingSpell->NameHash != SPELL_HASH_SHIELD_SLAM))
		return PROCCOND_BREAK_EXECUTION; 

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::BandoftheEternalRestorer(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(!(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_HEALING)) //requires healing spell.
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::AshtongueTalismanofAcumenShadowWord(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL || shareddata->CastingSpell->NameHash != SPELL_HASH_SHADOW_WORD__PAIN)
		return PROCCOND_BREAK_EXECUTION; 

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::AshtongueTalismanofAcumenRenewheals(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL || shareddata->CastingSpell->NameHash != SPELL_HASH_RENEW)
		return PROCCOND_BREAK_EXECUTION; 

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::AshtongueTalismanofLethality(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	//we need a finishing move for this 
	if(!(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_FINISHING_MOVE) || shareddata->victim == shareddata->owner)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::DeepThunderAndStormheraldStun(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->ProcFlags & PROC_ON_MELEE_ATTACK)
		return PROCCOND_CONTINUE_EXECUTION;

	return PROCCOND_BREAK_EXECUTION;
}