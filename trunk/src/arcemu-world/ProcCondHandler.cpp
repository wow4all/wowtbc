/*
* ArcEmu MMORPG Server
 * Copyright (C) 2005-2007 Ascent Team <http://www.ascentemu.com/>
* Copyright (C) 2008 <http://www.ArcEmu.org/>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Affero General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Affero General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

#include "StdAfx.h"

/******************************************************************************/
//					DRUID												   	  //
/******************************************************************************/

//Primal Fury Proc
ProcCondHandlerRes PrimalFury(ProcCondSharedDataStruct *shareddata)
{
	if( !shareddata->owner->IsPlayer() )
		return PROCCOND_BREAK_EXECUTION;

	Player * p = static_cast< Player * >( shareddata->owner );
	if( p->GetShapeShift() != FORM_BEAR && p->GetShapeShift() != FORM_DIREBEAR )
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

//Blood Frenzy
ProcCondHandlerRes BloodFrenzy(ProcCondSharedDataStruct *shareddata)
{
	if( !shareddata->owner->IsPlayer() || !shareddata->CastingSpell )
		return PROCCOND_BREAK_EXECUTION;

	if( static_cast< Player * >( shareddata->owner )->GetShapeShift() != FORM_CAT || (
		shareddata->CastingSpell->NameHash != SPELL_HASH_CLAW &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_RAKE &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_RAVAGE &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_SHRED ) )
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes LightningBoltDiscount(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell || shareddata->CastingSpell->NameHash != SPELL_HASH_LIGHTNING_BOLT)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

//Seal Fate
ProcCondHandlerRes SealFate(ProcCondSharedDataStruct *shareddata)
{
	if( !shareddata->owner->IsPlayer() || !shareddata->CastingSpell )
		return PROCCOND_BREAK_EXECUTION;

	if( shareddata->CastingSpell->Id == 14189 ||
		shareddata->CastingSpell->Id == 16953 ||
		shareddata->CastingSpell->Id == 16959)
		return PROCCOND_BREAK_EXECUTION;

	if( shareddata->CastingSpell->Effect[0] != 80 &&
		shareddata->CastingSpell->Effect[1] != 80 &&
		shareddata->CastingSpell->Effect[2] != 80 &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_MANGLE__CAT_ )
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

//intencity
ProcCondHandlerRes Intencity(ProcCondSharedDataStruct *shareddata)
{
	if( !shareddata->CastingSpell || shareddata->CastingSpell->Id != 5229)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

//Nature's Guardian
ProcCondHandlerRes NatureGuardian(ProcCondSharedDataStruct *shareddata)
{
	if( shareddata->owner->GetHealthPct() > 30 )
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

//Bloodlust
ProcCondHandlerRes Bloodlust(ProcCondSharedDataStruct *shareddata)
{
	if( !shareddata->owner->IsPlayer() )
		return PROCCOND_BREAK_EXECUTION;

	if( static_cast< Player* >( shareddata->owner )->GetShapeShift() != FORM_BEAR ||
		static_cast< Player* >( shareddata->owner )->GetShapeShift() != FORM_DIREBEAR )
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

//Bloodlust2
ProcCondHandlerRes Bloodlust2(ProcCondSharedDataStruct *shareddata)
{
	if( !shareddata->owner->IsPlayer() )
		return PROCCOND_BREAK_EXECUTION;

	if( static_cast< Player* >( shareddata->owner )->GetShapeShift() != FORM_CAT )
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

//holy concentration
ProcCondHandlerRes HolyConcentration(ProcCondSharedDataStruct *shareddata)
{
	if( !shareddata->owner->IsPlayer() )
		return PROCCOND_BREAK_EXECUTION;

	if( shareddata->CastingSpell == NULL )
		return PROCCOND_BREAK_EXECUTION;

	if( shareddata->CastingSpell->NameHash != SPELL_HASH_FLASH_HEAL &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_BINDING_HEAL &&
		shareddata->CastingSpell->NameHash != SPELL_HASH_GREATER_HEAL )
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

//Mace Stun Effect
ProcCondHandlerRes MaceStunEffect(ProcCondSharedDataStruct *shareddata)
{
	if( !shareddata->owner->IsPlayer() )
		return PROCCOND_BREAK_EXECUTION;

	uint32 talentlevel = 0;
	switch( shareddata->cur_itr->origId )
	{
		//mace specialization
		case 12284:	{talentlevel = 1;}break;
		case 12701:	{talentlevel = 2;}break;
		case 12702:	{talentlevel = 3;}break;
		case 12703:	{talentlevel = 4;}break;
		case 12704:	{talentlevel = 5;}break;
	}

	//warrior/rogue mace specialization can trigger only when using maces
	Item* it;
	if( static_cast< Player* >( shareddata->owner )->GetItemInterface() )
	{
		it = static_cast< Player* >( shareddata->owner )->GetItemInterface()->GetInventoryItem( EQUIPMENT_SLOT_MAINHAND );
		if( it != NULL && it->GetProto() )
		{
			uint32 reqskill = GetSkillByProto( it->GetProto()->Class, it->GetProto()->SubClass );
			if( reqskill != SKILL_MACES && reqskill != SKILL_2H_MACES )
				return PROCCOND_BREAK_EXECUTION; //not the right weapon
		}
		else
			return PROCCOND_BREAK_EXECUTION; //no weapon no joy
	}
	else
		return PROCCOND_BREAK_EXECUTION; //no weapon no joy

	//let's recalc chance to cast since we have a full 100 all time on this one
	//how lame to get talentpointlevel for this spell :(
	//float chance=it->GetProto()->Delay*100*talentlevel/60000;
	float chance = float( it->GetProto()->Delay ) * float( talentlevel ) / 600.0f;
	if( !Rand( chance ) )
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

//sword specialization
ProcCondHandlerRes SwordSpecialization(ProcCondSharedDataStruct *shareddata)
{
	if( !shareddata->owner->IsPlayer() )
		return PROCCOND_BREAK_EXECUTION;

	if( static_cast< Player* >( shareddata->owner )->GetItemInterface())
	{
		Item* it = static_cast< Player* >( shareddata->owner )->GetItemInterface()->GetInventoryItem( EQUIPMENT_SLOT_MAINHAND );
		if( it != NULL && it->GetProto() )
		{
			uint32 reqskill=GetSkillByProto( it->GetProto()->Class, it->GetProto()->SubClass );
			if( reqskill != SKILL_SWORDS && reqskill != SKILL_2H_SWORDS )
				return PROCCOND_BREAK_EXECUTION; //not the right weapon
		}
		else
			return PROCCOND_BREAK_EXECUTION; //no weapon no joy
	}
	else
		return PROCCOND_BREAK_EXECUTION; //no weapon no joy

	return PROCCOND_CONTINUE_EXECUTION;
}

//deep wound
ProcCondHandlerRes DeepWound(ProcCondSharedDataStruct *shareddata)
{
	if( !shareddata->owner->IsPlayer() )
		return PROCCOND_BREAK_EXECUTION;

	//deep wound requires a melee weapon
	Item* it;
	if( static_cast< Player* >( shareddata->owner )->GetItemInterface())
	{
		it = static_cast< Player* >( shareddata->owner )->GetItemInterface()->GetInventoryItem( EQUIPMENT_SLOT_MAINHAND );
		if( it != NULL && it->GetProto() )
		{
			//class 2 means weapons ;)
			if( it->GetProto()->Class != 2 )
				return PROCCOND_BREAK_EXECUTION;
		}
		else return PROCCOND_BREAK_EXECUTION; //no weapon no joy
	}
	else return PROCCOND_BREAK_EXECUTION; //no weapon no joy

	return PROCCOND_CONTINUE_EXECUTION;
}

/******************************************************************************/
//					Warrior												   	  //
/******************************************************************************/

//Blood Frenzy
ProcCondHandlerRes BloodFrenzy_war(ProcCondSharedDataStruct *shareddata)
{
	if( !shareddata->owner->IsPlayer() )
		return PROCCOND_BREAK_EXECUTION;

	if( shareddata->CastingSpell == NULL )
		return PROCCOND_BREAK_EXECUTION;

	if( shareddata->CastingSpell->NameHash != SPELL_HASH_REND && 
		shareddata->CastingSpell->NameHash != SPELL_HASH_DEEP_WOUND )
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

//Unbridled Wrath
ProcCondHandlerRes UnbridledWrath(ProcCondSharedDataStruct *shareddata)
{
	if( !shareddata->owner->IsPlayer() )
		return PROCCOND_BREAK_EXECUTION;

	uint32 talentlevel = 0;
	switch( shareddata->cur_itr->origId )
	{
		case 12999:	{talentlevel = 1;}break;
		case 13000:	{talentlevel = 2;}break;
		case 13001:	{talentlevel = 3;}break;
		case 13002:	{talentlevel = 4;}break;
	}

	//let's recalc chance to cast since we have a full 100 all time on this one
	Item* it;
	if( static_cast< Player* >( shareddata->owner )->GetItemInterface() )
	{
		it = static_cast< Player* >( shareddata->owner )->GetItemInterface()->GetInventoryItem( EQUIPMENT_SLOT_MAINHAND );
		if( !( it != NULL && it->GetProto() ) )
			return PROCCOND_BREAK_EXECUTION; //no weapon no joy
	}
	else
		return PROCCOND_BREAK_EXECUTION; //no weapon no joy
	//float chance=float(it->GetProto()->Delay)*float(talentlevel)/600.0f;
	float chance = float( it->GetProto()->Delay ) * float(talentlevel ) / 300.0f; //zack this had a very low proc rate. Kinda liek a waisted talent
	uint32 myroll = RandomUInt( 100 );
	if( myroll > chance )
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

 ////Rogue///
 
 ProcCondHandlerRes FindWeakness(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(!(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_FINISHING_MOVE))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}
//Pally//

 ProcCondHandlerRes LightsGrace(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->NameHash != SPELL_HASH_HOLY_LIGHT)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes BlessedLife(ProcCondSharedDataStruct *shareddata)
{
	shareddata->resisted_dmg = shareddata->Fulldmg / 2;

	return PROCCOND_BREAK_EXECUTION;
}

//Common//

ProcCondHandlerRes Flexibility(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell || shareddata->CastingSpell->NameHash != SPELL_HASH_FLASH_HEAL)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes WaveTrance(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell || !(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_HEALING))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes Charged(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell || !(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_DAMAGING))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

//Energized
ProcCondHandlerRes Energized1(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->NameHash != SPELL_HASH_LIGHTNING_BOLT)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes Energized2(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell || !(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_DAMAGING))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes Relentlessness(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell || !(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_DAMAGING))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes LightningBoltDiscount(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell || shareddata->CastingSpell->NameHash != SPELL_HASH_LIGHTNING_BOLT)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes InfusedShield(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell || shareddata->CastingSpell->NameHash != SPELL_HASH_HOLY_SHIELD)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes DivineLight(ProcCondSharedDataStruct *shareddata)
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

ProcCondHandlerRes Judgement(ProcCondSharedDataStruct *shareddata)
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

ProcCondHandlerRes Enlightenment(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell || (shareddata->CastingSpell->NameHash != SPELL_HASH_FLASH_OF_LIGHT && shareddata->CastingSpell->NameHash != SPELL_HASH_HOLY_LIGHT))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes Overpower(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell || shareddata->CastingSpell->NameHash != SPELL_HASH_OVERPOWER)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes Revenge(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell || shareddata->CastingSpell->Id == 37517 || shareddata->CastingSpell->NameHash != SPELL_HASH_REVENGE)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes Epiphany(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ManaSurge(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell || shareddata->CastingSpell->NameHash != SPELL_HASH_REPLENISH_MANA)
		return PROCCOND_BREAK_EXECUTION; 

	return PROCCOND_CONTINUE_EXECUTION;
}

////Items///

ProcCondHandlerRes StonebreakersTotem(ProcCondSharedDataStruct *shareddata)
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

ProcCondHandlerRes BrutalGladiatorsLibramofJustice(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->NameHash != SPELL_HASH_FLASH_OF_LIGHT)
	{
		return PROCCOND_BREAK_EXECUTION;
	}

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ShatteredSunPendantofAcumen_ArcaneBolt(ProcCondSharedDataStruct *shareddata)
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

ProcCondHandlerRes ShatteredSunPendantofRestoration(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(!(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_HEALING))
	{
		return PROCCOND_BREAK_EXECUTION;
	}

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes CommendationofKaelthas(ProcCondSharedDataStruct *shareddata)
{
	int32 procHealth = dbcSpell.LookupEntryForced(shareddata->origId)->EffectBasePoints[0] + 1;

	if(shareddata->owner->GetHealthPct() > procHealth)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes VialoftheSunwell(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(!(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_HEALING))
	{
		return PROCCOND_BREAK_EXECUTION;
	}

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes PendantoftheVioletEye(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(!shareddata->CastingSpell->manaCost && !shareddata->CastingSpell->ManaCostPercentage)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes TheLightningCapacitor(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(!(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_DAMAGING))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes CosmicInfuser(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(!(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_HEALING))
	{
		return PROCCOND_BREAK_EXECUTION;
	}

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes TimbalsFocusingCrystal(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_HEALING)
		return PROCCOND_BREAK_EXECUTION;

	if(!(shareddata->CastingSpell->spell_coef_flags & SPELL_FLAG_IS_DOT_OR_HOT_SPELL))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ShamanTier6TrinketEnergySurge(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->NameHash == SPELL_HASH_LESSER_HEALING_WAVE)
		return PROCCOND_CONTINUE_EXECUTION;

	if(shareddata->CastingSpell->NameHash == SPELL_HASH_LIGHTNING_BOLT)
		return PROCCOND_CONTINUE_EXECUTION;

	return PROCCOND_BREAK_EXECUTION;
}

ProcCondHandlerRes ShamanTier6TrinketPowerSurge(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->NameHash != SPELL_HASH_STORMSTRIKE)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes PaladinTier6TrinketEnduringLight(ProcCondSharedDataStruct *shareddata)
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

ProcCondHandlerRes PaladinTier6TrinketEnduringJudgement(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->Id != 20271)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes GraceoftheNaaru(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->NameHash != SPELL_HASH_HOLY_LIGHT)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}




void InitProcCondHandlers()
{
	//we set all handlers to null. A function pointer or a normal pointer still take up the same space
	memset(G_ProcCondHandlers, NULL, MAX_SPELL_ID_FROMDBC * sizeof( void * ) );


	G_ProcCondHandlers[ 40465 ] = ShamanTier6TrinketEnergySurge;
	G_ProcCondHandlers[ 40466 ] = ShamanTier6TrinketPowerSurge;
	G_ProcCondHandlers[ 40471 ] = PaladinTier6TrinketEnduringLight;
	G_ProcCondHandlers[ 40472 ] = PaladinTier6TrinketEnduringJudgement;
	G_ProcCondHandlers[ 43742 ] = GraceoftheNaaru;
	G_ProcCondHandlers[ 45055 ] = TimbalsFocusingCrystal;
	G_ProcCondHandlers[ 45058 ] = CommendationofKaelthas;
	G_ProcCondHandlers[ 45062 ] = VialoftheSunwell;
	G_ProcCondHandlers[ 35095 ] = PendantoftheVioletEye;
	G_ProcCondHandlers[ 37658 ] = TheLightningCapacitor;
	G_ProcCondHandlers[ 36483 ] = CosmicInfuser;
	G_ProcCondHandlers[ 45478 ] = ShatteredSunPendantofRestoration;
	G_ProcCondHandlers[ 45429 ] = ShatteredSunPendantofAcumen_ArcaneBolt;
	G_ProcCondHandlers[ 46093 ] = BrutalGladiatorsLibramofJustice;
	G_ProcCondHandlers[ 43749 ] = StonebreakersTotem;
	G_ProcCondHandlers[ 46089 ] = StonebreakersTotem;
	G_ProcCondHandlers[ 43837 ] = Revenge;
	G_ProcCondHandlers[ 28804 ] = Epiphany;
	G_ProcCondHandlers[ 37445 ] = ManaSurge;
	G_ProcCondHandlers[ 43837 ] = Enlightenment;
	G_ProcCondHandlers[ 37529 ] = Overpower;
	G_ProcCondHandlers[ 43838 ] = Judgement;
	G_ProcCondHandlers[ 43751 ] = Energized1;
	G_ProcCondHandlers[ 37214 ] = Energized2;
	G_ProcCondHandlers[ 37601 ] = Relentlessness;
	G_ProcCondHandlers[ 37237 ] = LightningBoltDiscount;
	G_ProcCondHandlers[ 37193 ] = InfusedShield;
	G_ProcCondHandlers[ 37234 ] = Charged;
	G_ProcCondHandlers[ 39950 ] = WaveTrance;
	G_ProcCondHandlers[ 37565 ] = Flexibility;
	G_ProcCondHandlers[ 16959 ] = PrimalFury;
	G_ProcCondHandlers[ 16953 ] = BloodFrenzy;
	G_ProcCondHandlers[ 14189 ] = SealFate;
	G_ProcCondHandlers[ 17106 ] = Intencity;
	G_ProcCondHandlers[ 31616 ] = NatureGuardian;
	G_ProcCondHandlers[ 37309 ] = Bloodlust;
	G_ProcCondHandlers[ 37310 ] = Bloodlust2;
	G_ProcCondHandlers[ 34754 ] = HolyConcentration;
	G_ProcCondHandlers[ 5530 ] = MaceStunEffect;
	G_ProcCondHandlers[ 4350 ] = SwordSpecialization;
	G_ProcCondHandlers[ 12721 ] = DeepWound;
	G_ProcCondHandlers[ 30069 ] = BloodFrenzy_war;
	G_ProcCondHandlers[ 30070 ] = BloodFrenzy_war;
	G_ProcCondHandlers[ 12964 ] = UnbridledWrath;
	G_ProcCondHandlers[ 31234 ] = FindWeakness;
	G_ProcCondHandlers[ 31235 ] = FindWeakness;
	G_ProcCondHandlers[ 31236 ] = FindWeakness;
	G_ProcCondHandlers[ 31237 ] = FindWeakness;
	G_ProcCondHandlers[ 35548 ] = FindWeakness;
	G_ProcCondHandlers[ 31834 ] = LightsGrace;
    G_ProcCondHandlers[ 31828 ] = BlessedLife;
	G_ProcCondHandlers[ 37237 ] = LightningBoltDiscount;
	
	
	
	
    	
	
	
	

}

ProcCondHandlerRes (*G_ProcCondHandlers[MAX_SPELL_ID_FROMDBC])(ProcCondSharedDataStruct *shareddata);
