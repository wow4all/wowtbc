/*
 * Sun++ Scripts for Bfx-SummitEmu MMORPG Server <http://www.tbcgaming.com/>
 * Copyright (C) 2005-2007 Arcemu Team 
 * Copyright (C) 2007 Moon++ Team <http://www.moonplusplus.com/>
 * Copyright (C) 2007 Sun++ Team <http://www.Sunscripting.com/>
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "StdAfx.h"
#include "../Base/Base.h"

/*

//Kil'Jaeden sound IDs saved for future use
//Some of them are used anytime during the raid progression in the instance 
//Some others are used in the actual Kil'Jaeden encounter

12527 Sunwell Plateau - Kil Jaeden "Spawning"
12495 Sunwell Plateau - Kil Jaeden - "All my plans have led to this"
12496 Sunwell Plateau - Kil Jaeden - "Stay on task, do not waste time"
12497 Sunwell Plateau - Kil Jaeden - "I've waited long enough!"
12498 Sunwell Plateau - Kil Jaeden - "Fail me, and suffer for eternity!"
12499 Sunwell Plateau - Kil Jaeden - "Drain the girl, drain her power, untill there is nothing but an ...something... shell"
12500 Sunwell Plateau - Kil Jaeden - Very long thing, basiclly he tells us that he will take control over the Burning Legion.
12501 Sunwell Plateau - Kil Jaeden - "Another step towards destruction!"

*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sunblade Cabalist//

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define CN_SUNBLADE_CABALIST				25369
#define SUNBLADE_CABALIST_IGNITE_MANA	    46480
#define SUNBLADE_CABALIST_SUMMON_IMP	    46480
#define SUNBLADE_CABALIST_SHADOWBOLT	    46480

class SunbladeCabalistAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(SunbladeCabalistAI, MoonScriptCreatureAI);
	SunbladeCabalistAI(Creature* pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(SUNBLADE_CABALIST_IGNITE_MANA, Target_RandomPlayer, 100, 0, 15, 0, 5);
		AddSpell(SUNBLADE_CABALIST_SUMMON_IMP, Target_Current, 100, 0, 15, 0, 30);
		AddSpell(SUNBLADE_CABALIST_SHADOWBOLT, Target_Current, 100, 0, 15, 0, 10);
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sunblade Vindicator//

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define CN_SUNBLADE_VINDICATOR				25369
#define SUNBLADE_VINDICATOR_BRUTAL_STRIKE	46480
#define SUNBLADE_VINDICATOR_CLEAVE	        46480
#define SUNBLADE_MALEVOLENT_STRIKES	        46480

class SunbladeVindicatorAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(SunbladeVindicatorAI, MoonScriptCreatureAI);
	SunbladeVindicatorAI(Creature* pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(SUNBLADE_VINDICATOR_BRUTAL_STRIKE, Target_Current, 100, 0, 15, 0, 5);
		AddSpell(SUNBLADE_VINDICATOR_CLEAVE, Target_Current, 100, 0, 15, 0, 10);
		AddSpell(SUNBLADE_MALEVOLENT_STRIKES, Target_Current, 100, 0, 15, 0, 15);
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sunblade Protector//
#define CN_SUNBLADE_PROTECTOR				25507
#define SUNBLADE_PROTECTOR_FEL_LIGHTNING	46480

class CN_SUNBLADE_PROTECTORAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(CN_SUNBLADE_PROTECTORAI, MoonScriptCreatureAI);
	CN_SUNBLADE_PROTECTORAI(Creature* pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(SUNBLADE_PROTECTOR_FEL_LIGHTNING, Target_RandomPlayer, 100, 0, 15, 0, 60);
	}
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Sunblade Dusk Priest//

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Sunblade Dusk Priest//
#define CN_SUNBLADE_DUSK_PRIEST				25370
#define SUNBLADE_DUSKPRIEST_FEAR         	46561
#define SUNBLADE_DUSKPRIEST_MIND_FLAY       46562
#define SUNBLADE_DUSKPRIEST_SHADOWWORDPAIN  46560

class SunbladeDuskPriestAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(SunbladeDuskPriestAI, MoonScriptCreatureAI);
	SunbladeDuskPriestAI(Creature* pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(SUNBLADE_DUSKPRIEST_FEAR, Target_RandomPlayer, 100, 0, 15, 0, 60);
		AddSpell(SUNBLADE_DUSKPRIEST_MIND_FLAY, Target_RandomPlayer, 100, 0, 15, 0, 60);
		AddSpell(SUNBLADE_DUSKPRIEST_SHADOWWORDPAIN, Target_RandomPlayer, 100, 0, 15, 0, 60);
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Shadowsword Assassin
#define CN_SHADOWSWORD_ASSASSIN						25484
#define SHADOWSWORD_ASSASSIN_ASSASSINS_MARK			46459
#define SHADOWSWORD_ASSASSIN_AIMED_SHOT				46460
#define SHADOWSWORD_ASSASSIN_SHADOWSTEP				46463
#define SHADOWSWORD_ASSASSIN_GREATER_INVISIBILITY	16380

class ShadowswordAssassinAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(ShadowswordAssassinAI, MoonScriptCreatureAI);
	ShadowswordAssassinAI(Creature* pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(SHADOWSWORD_ASSASSIN_ASSASSINS_MARK, Target_Current, 100, 0, 15, 0, 100);
		AddSpell(SHADOWSWORD_ASSASSIN_AIMED_SHOT, Target_Current, 15, 4, 6, 5, 35, true);
		AddSpell(SHADOWSWORD_ASSASSIN_SHADOWSTEP, Target_RandomPlayer, 15, 0, 50, 0, 40);
		AddSpell(SHADOWSWORD_ASSASSIN_GREATER_INVISIBILITY, Target_Self, 5, 0, 180);
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Shadowsword Commander
#define CN_SHADOWSWORD_COMMANDER			25837
#define SHADOWSWORD_COMMANDER_SHIELD_SLAM	46762
#define SHADOWSWORD_COMMANDER_BATTLESHOUT	46763

class ShadowswordCommanderAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(ShadowswordCommanderAI, MoonScriptCreatureAI);
	ShadowswordCommanderAI(Creature* pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(SHADOWSWORD_COMMANDER_SHIELD_SLAM, Target_Current, 10, 0, 10);
		AddSpell(SHADOWSWORD_COMMANDER_BATTLESHOUT, Target_Self, 20, 0, 25);
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Shadowsword Guardian
#define CN_SHADOWSWORN_GUARDIAN 25508
#define SHADOWSWORN_GUARDIAN_BEARDOWN 46239
#define SHADOWSWORN_GUARDIAN_EARTHQUAKE 46240

class ShadowswordGuardianAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(ShadowswordGuardianAI, MoonScriptCreatureAI);
	ShadowswordGuardianAI(Creature* pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(SHADOWSWORN_GUARDIAN_EARTHQUAKE, Target_Current, 10, 0, 25);
		AddSpell(SHADOWSWORN_GUARDIAN_BEARDOWN, Target_RandomPlayer, 20, 0, 40);
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Kalecgos
#define CN_KALECGOS					24850
#define KALECGOS_FROST_BREATH		44799
#define KALECGOS_SPECTRAL_BLAST		44866
#define KALECGOS_ARCANE_BUFFET		45018

void SpellFunc_Kalecgos_WildMagic(SpellDesc* pThis, MoonScriptCreatureAI* pCreatureAI, Unit* pTarget, TargetType pType);

class KalecgosAI : public MoonScriptBossAI
{
    MOONSCRIPT_FACTORY_FUNCTION(KalecgosAI, MoonScriptBossAI);
	KalecgosAI(Creature* pCreature) : MoonScriptBossAI(pCreature)
	{
		AddSpell(KALECGOS_FROST_BREATH, Target_Current, 10, 1, 12, 0, 30);
		AddSpellFunc(SpellFunc_Kalecgos_WildMagic, Target_RandomPlayer, 15, 0, 10, 0, 100);
		AddSpell(KALECGOS_SPECTRAL_BLAST, Target_Current, 25, 0, 25, 0, 50);
		AddSpell(KALECGOS_ARCANE_BUFFET, Target_Current, 100, 0, 8);

		//Emotes
		AddEmote(Event_OnCombatStart, "No longer will I be a slave to Malygos! Challenge me and you will be destroyed!", Text_Yell, 12422);
		AddEmote(Event_OnTargetDied, "You were warned! ", Text_Yell, 12426);
		AddEmote(Event_OnTargetDied, "In the name of Kil'jaeden! ", Text_Yell, 12425);
		AddEmote(Event_OnDied, "I am forever in your debt. Once we have triumphed over Kil'jaeden, this entire world will be in your debt as well.", Text_Yell, 12431);
	}
};

void SpellFunc_Kalecgos_WildMagic(SpellDesc* pThis, MoonScriptCreatureAI* pCreatureAI, Unit* pTarget, TargetType pType)
{
	KalecgosAI* Kalecgos = ( pCreatureAI ) ? (KalecgosAI*)pCreatureAI : NULL;
	if( Kalecgos )
	{
		//TODO
/*
		#define SP_WILD_MAGIC_1			44978
		#define SP_WILD_MAGIC_2			45001
		#define SP_WILD_MAGIC_3			45002
		#define SP_WILD_MAGIC_4			45004
		#define SP_WILD_MAGIC_5			45006
		#define SP_WILD_MAGIC_6			45010*/
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sathrovarr the Corruptor
#define CN_SATHROVARR_THE_CORRUPTOR							24892
#define SATHROVARR_THE_CORRUPTOR_CURSE_OF_BOUNDLESS_AGONY	45034
#define SATHROVARR_THE_CORRUPTOR_SHADOW_BOLT_VOLLEY			38840
#define SATHROVARR_THE_CORRUPTOR_CORRUPTING_STRIKE			45029

class SathrovarrTheCorruptorAI : public MoonScriptBossAI
{
    MOONSCRIPT_FACTORY_FUNCTION(SathrovarrTheCorruptorAI, MoonScriptBossAI);
	SathrovarrTheCorruptorAI(Creature* pCreature) : MoonScriptBossAI(pCreature)
	{
		AddSpell(SATHROVARR_THE_CORRUPTOR_CURSE_OF_BOUNDLESS_AGONY, Target_RandomPlayer, 20, 0, 12, 0, 40); 
		AddSpell(SATHROVARR_THE_CORRUPTOR_SHADOW_BOLT_VOLLEY, Target_RandomPlayerApplyAura, 20, 1, 25, 0, 40);
		AddSpell(SATHROVARR_THE_CORRUPTOR_CORRUPTING_STRIKE, Target_Current, 30, 0, 5, 0, 10);

		//Emotes
		AddEmote(Event_OnCombatStart, "Gyahaha... There will be no reprieve. My work here is nearly finished.", Text_Yell);
		AddEmote(Event_OnTargetDied, "Pitious mortal!", Text_Yell);
		AddEmote(Event_OnTargetDied, "Haven't you heard? I always win!", Text_Yell);
		AddEmote(Event_OnDied, "I'm... never on... the losing... side...", Text_Yell);
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Brutallus
//#define CN_Blaze 23259 should spawn when he casts burn on a random member at there location at least it does on trinitycore temp spawn for like 10-20 seconds
#define CN_BRUTALLUS			24882
#define BRUTALLUS_METEOR_SLASH	45150
#define BRUTALLUS_BURN			45141
#define BRUTALLUS_STOMP			45185
#define BRUTALLUS_BERSERK		26662
#define FIRE_WALL				43113
#define CN_FELMYST				25038
#define SPELL_DUAL_WIELD        2459


class BrutallusAI : public MoonScriptBossAI
{
    MOONSCRIPT_FACTORY_FUNCTION(BrutallusAI, MoonScriptBossAI);
	BrutallusAI(Creature* pCreature) : MoonScriptBossAI(pCreature)
	{
	    _unit->MechanicsDispels[ DISPEL_MECHANIC_CHARM ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_FEAR ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_ROOT ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_SLEEP ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_SNARE ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_STUN ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_KNOCKOUT ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_POLYMORPH ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_BANISH ] = 1;
		
		
	    AddSpell( BRUTALLUS_METEOR_SLASH, Target_Current, 35, 1, 16 );
		AddSpell( BRUTALLUS_BURN, Target_RandomPlayer, 50, 0, 30 );
		AddSpell( BRUTALLUS_STOMP, Target_Current, 25, 0, 9 );

		//6min Enrage
		SetEnrageInfo( AddSpell( BRUTALLUS_BERSERK, Target_Self, 0, 0, 0, 0, 0, false, "So much for a real challenge... Die!", Text_Yell, 12470 ), 360000);

		//Emotes
		AddEmote( Event_OnCombatStart, "Ah, more lambs to the slaughter!", Text_Yell, 12463 );
		AddEmote( Event_OnTargetDied, "Perish, insect!", Text_Yell, 12464 );
		AddEmote( Event_OnTargetDied, "You are meat!", Text_Yell, 12465 );
		AddEmote( Event_OnTargetDied, "Too easy!", Text_Yell, 12466 );
		AddEmote( Event_OnTaunt, "Bring the fight to me!", Text_Yell, 12467 );
		AddEmote( Event_OnTaunt, "Another day, another glorious battle!", Text_Yell, 12468 );
		AddEmote( Event_OnTaunt, "I live for this!", Text_Yell, 12469 );
		AddEmote( Event_OnDied, "Gah! Well done... Now... this gets... interesting...", Text_Yell, 12471 );
	}
	
	
	void OnCombatStart(Unit* mTarget)
    {
 
        _unit->CastSpell(_unit, dbcSpell.LookupEntry(SPELL_DUAL_WIELD), true);
		GetUnit()->SetFloatValue(UNIT_FIELD_MINDAMAGE, 7000);//Bfx DB does not support offhands using this instead.
		GetUnit()->SetFloatValue(UNIT_FIELD_MAXDAMAGE, 8000);
		GetUnit()->SetFloatValue(UNIT_FIELD_MINOFFHANDDAMAGE, 6000);
		GetUnit()->SetFloatValue(UNIT_FIELD_MAXOFFHANDDAMAGE, 7500);
		
		ParentClass::OnCombatStart(mTarget);
 
    };

        
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Felmyst
#define FELMYST_CLEAVE				19983
#define FELMYST_CORROSION			45866
#define FELMYST_DEMONIC_VAPOR		45402
#define FELMYST_GAS_NOVA			45855
#define FELMYST_NOXIOUS_FUME		47002
#define FELMYST_ENCAPSULATE			45662
#define FELMYST_FOG_OF_CORRUPTION	45717
#define FELMYST_ENRAGE				26662	//Using same as Brutallus for now, need to find actual spell id

class FelmystAI : public MoonScriptBossAI
{
    MOONSCRIPT_FACTORY_FUNCTION(FelmystAI, MoonScriptBossAI);
	FelmystAI(Creature* pCreature) : MoonScriptBossAI(pCreature)
	{
	    _unit->MechanicsDispels[ DISPEL_MECHANIC_CHARM ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_FEAR ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_ROOT ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_SLEEP ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_SNARE ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_STUN ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_KNOCKOUT ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_POLYMORPH ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_BANISH ] = 1;
	
	
		//Phase 1 spells
		AddPhaseSpell(1, AddSpell(FELMYST_CLEAVE, Target_Current, 6, 0, 10, 0, 5));
		AddPhaseSpell(1, AddSpell(FELMYST_GAS_NOVA, Target_Self, 25, 1, 18));
		AddPhaseSpell(1, AddSpell(FELMYST_ENCAPSULATE, Target_RandomPlayer, 25, 7, 30, 0, 30));
		AddPhaseSpell(1, AddSpell(FELMYST_CORROSION, Target_Current, 20, 0.75f, 35, 0, 30, false, "Choke on your final breath!"));

		//Phase 2 spells
		AddPhaseSpell(2, AddSpell(FELMYST_DEMONIC_VAPOR, Target_RandomPlayer, 10, 0, 20));

		//Phase 3 spells
		//Fog of corruption is the actual breath Felmyst does during his second phase, probably we'll have to spawn it like a creature.
		//AddSpell(FELMYST_FOG_OF_CORRUPTION, Target_RandomPlayerApplyAura, 15, 0, 20, 0, 10); Does not support by the core.

		//10min Enrage
		SetEnrageInfo(AddSpell(FELMYST_ENRAGE, Target_Self, 0, 0, 0, 0, 0, false, "No more hesitation! Your fates are written!"), 600000);

		//Emotes
		AddEmote(Event_OnCombatStart, "Glory to Kil'jaeden! Death to all who oppose!", Text_Yell);
		AddEmote(Event_OnTargetDied, "I kill for the master! ", Text_Yell);
		AddEmote(Event_OnTargetDied, "The end has come!", Text_Yell);
		AddEmote(Event_OnDied, "Kil'jaeden... will... prevail...", Text_Yell);
		AddEmote(Event_OnTaunt, "I am stronger than ever before!", Text_Yell);
	}

	void OnCombatStart(Unit* pTarget)
	{
		ApplyAura(FELMYST_NOXIOUS_FUME);
		ParentClass::OnCombatStart(pTarget);
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Grand Warlock Alythess && Lady Sacrolash

#define CN_LADY_SACROLASH				25165
#define CN_GRAND_WARLOCK_ALYTHESS		25166
#define ENRAGE							26662	
#define EMPOWER							45366

#define DARK_TOUCHED					45347
#define SHADOW_BLADES					45248
#define SHADOW_FURY					    45270
#define CONFOUNDING_BLOW				45256

#define PYROGENICS						45230
#define FLAME_TOUCHED					45348
#define CONFLAGRATION					45342
#define BLAZE							45235
#define FLAME_SEAR						46771

class LadySacrolashAI : public MoonScriptBossAI
{
    MOONSCRIPT_FACTORY_FUNCTION(LadySacrolashAI, MoonScriptBossAI);
	LadySacrolashAI(Creature* pCreature) : MoonScriptBossAI(pCreature)
	{
	    _unit->MechanicsDispels[ DISPEL_MECHANIC_CHARM ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_FEAR ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_ROOT ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_SLEEP ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_SNARE ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_STUN ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_KNOCKOUT ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_POLYMORPH ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_BANISH ] = 1;
	
	    
		Init();

		SetEnrageInfo( AddSpell( ENRAGE, Target_Self, 0, 0, 0  ), 360000 );
		Emote( "Misery...", Text_Yell, 12484 );
		AddEmote( Event_OnTargetDied, "Shadows, engulf!", Text_Yell, 12486 );
	}

	void Init()
	{
		phase = 1;
		ShadowbladesTimer = 10000;
        ShadowfuryTimer = 30000;
        ConfoundingblowTimer = 25000;
		ConflagrationTimer = 30000;
	};

	void AIUpdate()
	{
		if( IsInCombat() == false || IsCasting() )
			return;

		if( ShadowbladesTimer <= mAIUpdateFrequency )
		{
			Unit* pTarget = _unit->GetAIInterface()->GetNextTarget();
			if( pTarget )
			{
				_unit->CastSpell( pTarget, SHADOW_BLADES, false );
				pTarget->RemoveAllAuras( FLAME_TOUCHED, 0 );
				pTarget->CastSpell( pTarget, DARK_TOUCHED, true );
			}
            ShadowbladesTimer = 10000;
			return;
		}else ShadowbladesTimer -= mAIUpdateFrequency;

		if( ConfoundingblowTimer <= mAIUpdateFrequency )
        {
			Player* pTarget = static_cast< Player* >( GetBestPlayerTarget() );
			if( pTarget )
			{
				_unit->CastSpell( pTarget, CONFOUNDING_BLOW, false );
				pTarget->RemoveAllAuras( FLAME_TOUCHED, 0 );
				pTarget->CastSpell( pTarget, DARK_TOUCHED, true );
			};

			ConfoundingblowTimer = 20000 + (rand()%5000);
			return;
        }else ConfoundingblowTimer -= mAIUpdateFrequency;

		if( phase == 0 )
		{
			if( ShadowfuryTimer <= mAIUpdateFrequency )
			{
				Player* pTarget = static_cast< Player* >( GetBestPlayerTarget() );
				if( pTarget )
				{
					_unit->CastSpell( pTarget, SHADOW_FURY, false );

					char msg[256];
					snprintf((char*)msg, 256, "Lady Sacrolash directs Shadow Fury at %s", pTarget->GetName());
					pTarget->SendChatMessage( CHAT_MSG_RAID_BOSS_EMOTE, LANG_UNIVERSAL,  msg );
					Emote( "Shadow to the aid of fire!", Text_Yell, 12485);

					pTarget->RemoveAllAuras( FLAME_TOUCHED, 0 );
					pTarget->CastSpell( pTarget, DARK_TOUCHED, true );
					
				};

				ShadowfuryTimer = 30000 +( rand()%5000 );
				return;
			}
			else
				ShadowfuryTimer -= mAIUpdateFrequency;
		}
		else
		{
			if( ConflagrationTimer <= mAIUpdateFrequency )
			{
				Player* pTarget = static_cast< Player* >( GetBestPlayerTarget() );
				if( pTarget )
				{
					_unit->CastSpell( pTarget, CONFLAGRATION, false );
				
					pTarget->RemoveAllAuras( FLAME_TOUCHED, 0 );
					pTarget->CastSpell( pTarget, DARK_TOUCHED, true );
				}

				ConflagrationTimer = 30000 +( rand()%5000 );
				return;
			}
			else
				ConflagrationTimer -= mAIUpdateFrequency;
		};
	};

	void OnCombatStop( Unit* pTarget )
	{
		ParentClass::OnCombatStop( pTarget );
		Init();
	};

    uint32	ShadowfuryTimer;
    uint32	ConfoundingblowTimer;
    uint32	ConflagrationTimer;
	uint32	ShadowbladesTimer;
	uint8	phase;
};

class GrandWarlockAlythessAI : public MoonScriptBossAI
{
    MOONSCRIPT_FACTORY_FUNCTION(GrandWarlockAlythessAI, MoonScriptBossAI);
	GrandWarlockAlythessAI(Creature* pCreature) : MoonScriptBossAI(pCreature)
	{
	
	    _unit->MechanicsDispels[ DISPEL_MECHANIC_CHARM ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_FEAR ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_ROOT ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_SLEEP ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_SNARE ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_STUN ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_KNOCKOUT ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_POLYMORPH ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_BANISH ] = 1;
		
		Init();

		SetEnrageInfo( AddSpell(ENRAGE, Target_Self, 0, 0, 0, 0, 0, false, "Your luck has run its course!", Text_Yell, 12493 ), 360000);
		mLadySacrolash = NULL;
		mRespond = 0;
		mRespondTimer = AddTimer( 1100 );
		RegisterAIUpdateEvent( 500 );
		SetCanMove( false );

		AddEmote(Event_OnTargetDied, "Fire, consume!", Text_Yell, 12490 );
	}

	void Init()
	{
		ConflagrationTimer = 45000;
        BlazeTimer = 20000;
        PyrogenicsTimer = 15000;
        ShadowfuryTimer = 40000;
		FlamesearTimer = 15000;

		phase = 0;
	};

	void OnCombatStart( Unit* pTarget )
	{
		SetBehavior(Behavior_Melee);
		RegisterAIUpdateEvent(mAIUpdateFrequency);
		SetCanMove( false );
	};

	void AIUpdate()
	{
		ParentClass::AIUpdate();
		
		if( IsTimerFinished( mRespondTimer ) )
			Respond();

		if( !IsInCombat() )
			return;

		if( phase = 0 && ( mLadySacrolash == NULL || !mLadySacrolash->IsAlive() ) )
		{
			phase = 1;
			Emote( "Sacrolash!", Text_Yell, 12488 );
		};
		
		if( IsCasting() )
			return;

		if( FlamesearTimer <= mAIUpdateFrequency )
        {
            Unit* pTarget = GetBestPlayerTarget();
			if( pTarget )
            {
                _unit->CastSpell( pTarget, FLAME_SEAR, false );

				pTarget->RemoveAllAuras( DARK_TOUCHED, 0 );
				pTarget->CastSpell( pTarget, FLAME_TOUCHED, true );
			};

			FlamesearTimer = 15000;
			return;
        }else FlamesearTimer -= mAIUpdateFrequency;

        if ( PyrogenicsTimer <= mAIUpdateFrequency )
        {
            Unit* pTarget = GetBestPlayerTarget();
			if( pTarget )
            {
                _unit->CastSpell( pTarget, PYROGENICS, false );

				pTarget->RemoveAllAuras( DARK_TOUCHED, 0 );
				pTarget->CastSpell( pTarget, FLAME_TOUCHED, true );
			};

			PyrogenicsTimer = 15000;
			return;
        }else PyrogenicsTimer -= mAIUpdateFrequency;

        if ( BlazeTimer <= mAIUpdateFrequency )
        {
			Unit* pTarget = _unit->GetAIInterface()->GetNextTarget();
			if( pTarget )
			{
                _unit->CastSpell( pTarget, BLAZE, false );
                
				pTarget->RemoveAllAuras( DARK_TOUCHED, 0 );
				pTarget->CastSpell( pTarget, FLAME_TOUCHED, true );
			};

			BlazeTimer = 20000;
			return;
		}else BlazeTimer -= mAIUpdateFrequency;

		if( phase == 0 )
		{
			if( ConflagrationTimer <= mAIUpdateFrequency )
			{
				Player* pTarget = static_cast< Player* >( GetBestPlayerTarget() );
				if( pTarget )
				{
					_unit->CastSpell( pTarget, CONFLAGRATION, false );

					char msg[256];
					snprintf((char*)msg, 256, "Lady Sacrolash directs Confligration at %s", pTarget->GetName());
					_unit->SendChatMessage( CHAT_MSG_RAID_BOSS_EMOTE, LANG_UNIVERSAL,  msg );
					Emote( "Fire to the aid of shadow!", Text_Yell, 12489 );

					pTarget->RemoveAllAuras( DARK_TOUCHED, 0 );
					pTarget->CastSpell( pTarget, FLAME_TOUCHED, true );
				};

				ConflagrationTimer = 30000 +( rand()%5000 );
				return;
			}
			else
				ConflagrationTimer -= mAIUpdateFrequency;
		}
		else
		{
			if( ShadowfuryTimer <= mAIUpdateFrequency )
			{
				Player* pTarget = static_cast< Player* >( GetBestPlayerTarget() );
				if( pTarget )
				{
					_unit->CastSpell( pTarget, SHADOW_FURY, false );
					pTarget->RemoveAllAuras( FLAME_TOUCHED, 0 );
					pTarget->CastSpell( pTarget, DARK_TOUCHED, true );
				};

				ShadowfuryTimer = 30000 +( rand()%5000 );
				return;
			}
			else
				ShadowfuryTimer -= mAIUpdateFrequency;
		};
	};
	
	void OnDied(Unit* pKiller)
	{
		if( mLadySacrolash && mLadySacrolash->IsAlive() )
		{
			mLadySacrolash->Emote( "Alythess! Your fire burns within me!", Text_Yell, 12488 );
			mLadySacrolash->ApplyAura( EMPOWER );
			mLadySacrolash->phase = 1;
		};

		ParentClass::OnDied(pKiller);
	}

	void Respond()
	{
		++mRespond;
		switch( mRespond )
			{
		case 1:
			{
				mLadySacrolash = static_cast<LadySacrolashAI*>( GetNearestCreature( CN_LADY_SACROLASH ) );
				Emote( "Depravity...", Text_Yell );
				ResetTimer( mRespondTimer, 1600 );
			}break;
		case 2:
			{
				if( mLadySacrolash && mLadySacrolash->IsAlive() )
					mLadySacrolash->Emote( "Confusion...", Text_Yell );

			ResetTimer( mRespondTimer, 1600 );
			}break;
		case 3:
			{
				Emote( "Hatred...", Text_Yell );
				ResetTimer( mRespondTimer, 1600 );
			}break;
		case 4:
			{
				if( mLadySacrolash && mLadySacrolash->IsAlive() )
					mLadySacrolash->Emote( "Mistrust...", Text_Yell );

				ResetTimer( mRespondTimer, 1600 );
			}break;
		case 5:
			{
				Emote( "Chaos...", Text_Yell );
				ResetTimer( mRespondTimer, 1600 );
			}break;
		case 6:
			{
				if( mLadySacrolash && mLadySacrolash->IsAlive() )
					mLadySacrolash->Emote( "These are the hallmarks...", Text_Yell );

				ResetTimer( mRespondTimer, 2600 );
			}break;
		case 7:
			{
				Emote( "These are the pillars...", Text_Yell );
				RemoveTimer( mRespondTimer );
			}break;
		};
	};

	uint32					ConflagrationTimer;
    uint32					BlazeTimer;
    uint32					PyrogenicsTimer;
    uint32					ShadowfuryTimer;
    uint32					FlamesearTimer;
	uint8					phase;

	int32					mRespondTimer;
	uint32					mRespond;
	LadySacrolashAI*		mLadySacrolash;
};

#define CREATURE_SHADOW_IMAGE 25214

#define SPELL_SHADOW_IMAGE_VISUAL 45263
#define SPELL_DARKSTRIKE 5271
#define SPELL_SHADOW_FURY 45270

class mob_Shadow_imageAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(mob_Shadow_imageAI, MoonScriptCreatureAI);
	mob_Shadow_imageAI(Creature* pCreature) : MoonScriptCreatureAI(pCreature)
	{
	  _unit->CastSpell(_unit, dbcSpell.LookupEntry(SPELL_SHADOW_IMAGE_VISUAL), true);
	  
	  AddEmote(Event_OnCombatStart, "Fire, consume!", Text_Yell, 12490 );
	  
	  
	  AddSpell( SPELL_DARKSTRIKE, Target_RandomPlayer, 50, 0, 3);
	  AddSpell( SPELL_SHADOW_FURY, Target_RandomPlayer, 50, 0, 10);

	}
	
	void OnDied(Unit * mKiller)
	{
	
	}
	
	void OnTargetDied(Unit* mTarget)
	{
	
	}
	
	void OnCombatStart(Unit* mTarget)
	{
	
	}
	

};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//M'uru
#define CN_MURU						25960
#define CN_SHADOWSWORD_BERSERKER	25798
#define CN_SHADOWSWORD_FURY_MAGE	25799
#define CN_VOID_SENTINEL			25772
#define CN_ENTROPIUS				25840
#define MURU_NEGATIVE_ENERGY		46285
#define MURU_DARKNESS				45996
#define MURU_SUMMON_BERSERKER		46037
#define MURU_SUMMON_FURY_MAGE		46038
#define MURU_SUMMON_VOID_SENTINEL	45988

class MuruAI : public MoonScriptBossAI
{
	MOONSCRIPT_FACTORY_FUNCTION(MuruAI, MoonScriptBossAI);
	MuruAI(Creature* pCreature) : MoonScriptBossAI(pCreature)
	{
	
	    pCreature->GetAIInterface()->m_canMove = false;
		
	    _unit->MechanicsDispels[ DISPEL_MECHANIC_CHARM ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_FEAR ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_ROOT ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_SLEEP ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_SNARE ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_STUN ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_KNOCKOUT ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_POLYMORPH ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_BANISH ] = 1;
		
		
		AddSpell(MURU_NEGATIVE_ENERGY, Target_SecondMostHated, 25, 0, 1, 0, 40);
		AddSpell(MURU_DARKNESS, Target_Current, 25, 0, 10, 0, 10);

		
	}

	void OnCombatStart(Unit* mTarget)
	{
		SetAllowMelee(false);
		//doors
		ParentClass::OnCombatStart(mTarget);
	}

	void OnLoad()
	{
		spawnplace = 1;
		summoningst = false;
		timmer = 0;
		SetAllowMelee(false);
		ParentClass::OnLoad();
	}

	void AIUpdate()
	{
		SetAllowMelee(false);
		timmer++;
		if (summoningst == true && (timmer == 20 || timmer == 60 || timmer == 100))
		{
			SpawnCreature(CN_SHADOWSWORD_BERSERKER, 1871, 650, 71, 0, false);
			SpawnCreature(CN_SHADOWSWORD_FURY_MAGE, 1871, 650, 71, 0, false);
			SpawnCreature(CN_SHADOWSWORD_FURY_MAGE, 1748, 700, 71, 0, false);
			SpawnCreature(CN_SHADOWSWORD_BERSERKER, 1748, 700, 71, 0, false);
		}

		if (timmer == 120)
		{
			timmer = 0;
			summoningst = true;
			switch (spawnplace)
			{
			case 1:
				{
				SpawnCreature(CN_VOID_SENTINEL, 1800, 652, 71, 0, false);
				++spawnplace;
				}break;
			case 2:
				{
				SpawnCreature(CN_VOID_SENTINEL, 1798, 605, 71, 0, false);
				++spawnplace;
				}break;
			case 3:
				{
				SpawnCreature(CN_VOID_SENTINEL, 1826, 650, 71, 0, false);
				++spawnplace;
				}break;
			case 4:
				{
				SpawnCreature(CN_VOID_SENTINEL, 1783, 625, 71, 0, false);
				++spawnplace;
				}break;
			case 5:
				{
				SpawnCreature(CN_VOID_SENTINEL, 1816, 595, 71, 0, false);
				++spawnplace;
				}break;
			case 6:
				{
				SpawnCreature(CN_VOID_SENTINEL, 1844, 641, 71, 0, false);
				spawnplace = 1;
				}break;
			}
		}

		if (GetHealthPercent() <= 35)
		{
			SpawnCreature(CN_ENTROPIUS, true);
			Despawn(100,0);
		}

		ParentClass::AIUpdate();
	}

	void OnDied(Unit * mKiller)
	{
		ParentClass::OnDied(mKiller);
	}
protected:
	int timmer, spawnplace;
	bool summoningst;
};

#define BERSERK_FLURRY 46160

class ShadowswordBerserkerAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(ShadowswordBerserkerAI, MoonScriptCreatureAI);
	ShadowswordBerserkerAI(Creature* pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(BERSERK_FLURRY, Target_Current, 30, 0, 30);
	}

	void OnCombatStart(Unit* mTarget)
	{
		ParentClass::OnCombatStart(mTarget);
	}

	void OnLoad()
	{
		_unit->GetAIInterface()->m_moveRun = true;
		Creature *Muruu = _unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(1815, 625, 69, CN_MURU);
		if (Muruu)
		{
			MoveTo(Muruu);
		}
		ParentClass::OnLoad();
	}

	void AIUpdate()
	{
		ParentClass::AIUpdate();
	}

	void OnDied(Unit * mKiller)
	{
		Despawn(100,0);
		ParentClass::OnDied(mKiller);
	}

protected:
	Creature *Muruu;

};

#define FEL_FIREBALL 46101
#define SPELL_FURY 46102

class ShadowswordFuryMageAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(ShadowswordFuryMageAI, MoonScriptCreatureAI);
	ShadowswordFuryMageAI(Creature* pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(FEL_FIREBALL, Target_RandomPlayer, 100, 2, 2, 4, 40); 
		AddSpell(SPELL_FURY, Target_Self, 30, 0, 50); 
	}

	void OnCombatStart(Unit* mTarget)
	{
		ParentClass::OnCombatStart(mTarget);
	}

	void OnLoad()
	{
		_unit->GetAIInterface()->m_moveRun = true;
		Creature *Muruu = _unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(1815, 625, 69, CN_MURU);
		if (Muruu)
		{
			MoveTo(Muruu);
		}
		ParentClass::OnLoad();
	}

	void AIUpdate()
	{
		ParentClass::AIUpdate();
	}

	void OnDied(Unit * mKiller)
	{
		Despawn(100,0);
		ParentClass::OnDied(mKiller);
	}

protected:
	Creature *Muruu;
};

#define SHADOW_PULSE 46087
#define WOID_BLAST 46161

class VoidSentinelAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(VoidSentinelAI, MoonScriptCreatureAI);
	VoidSentinelAI(Creature* pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(SHADOW_PULSE, Target_Current, 50, 0, 3);
		AddSpell(WOID_BLAST, Target_Current, 20, 1.50f, 15);
	}

	void OnCombatStart(Unit* mTarget)
	{
		ParentClass::OnCombatStart(mTarget);
	}

	void OnLoad()
	{
		_unit->GetAIInterface()->m_moveRun = true;
		Creature *Muruu = _unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(1815, 625, 69, CN_MURU);
		if (Muruu)
		{
			MoveTo(Muruu);
		}
		ParentClass::OnLoad();
	}

	void AIUpdate()
	{
		ParentClass::AIUpdate();
	}

	void OnDied(Unit * mKiller)
	{
		Despawn(100,0);
		ParentClass::OnDied(mKiller);
	}

protected:
	Creature *Muruu;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Entropius
#define ENTROPIUS_NEGATIVE_ENERGY	46289 //SpellID taken from Wowhead
#define ENTROPIUS_NEGATIVE_ENERGY1	46008
#define ENTROPIUS_NEGATIVE_ENERGY2	46285
#define ENTROPIUS_BLACK_HOLE		46242 //SpellID taken from Wowhead

class EntropiusAI : public MoonScriptBossAI
{
	MOONSCRIPT_FACTORY_FUNCTION(EntropiusAI, MoonScriptBossAI);
	EntropiusAI(Creature* pCreature) : MoonScriptBossAI(pCreature)
	{
	
	    
	    _unit->MechanicsDispels[ DISPEL_MECHANIC_CHARM ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_FEAR ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_ROOT ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_SLEEP ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_SNARE ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_STUN ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_KNOCKOUT ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_POLYMORPH ] = 1;
		_unit->MechanicsDispels[ DISPEL_MECHANIC_BANISH ] = 1;
	
	
		AddSpell(ENTROPIUS_NEGATIVE_ENERGY1, Target_RandomDestination, 15, 0, 1, 0, 40);
		AddSpell(ENTROPIUS_BLACK_HOLE, Target_RandomDestination, 10, 0, 10, 0, 40);

		
	}

	void OnCombatStart(Unit* mTarget)
	{
		ParentClass::OnCombatStart(mTarget);
	}

	void OnLoad()
	{
		ParentClass::OnLoad();
	}

	void AIUpdate()
	{
		ParentClass::AIUpdate();
	}

	void OnDied(Unit * mKiller)
	{
		//doors
		ParentClass::OnDied(mKiller);
	}
};







void SetupSunwellPlateau(ScriptMgr* pScriptMgr)
{
    
	pScriptMgr->register_creature_script(CN_SUNBLADE_PROTECTOR, &CN_SUNBLADE_PROTECTORAI::Create);
	pScriptMgr->register_creature_script(CN_SUNBLADE_VINDICATOR, &SunbladeVindicatorAI::Create);
	pScriptMgr->register_creature_script(CN_SUNBLADE_DUSK_PRIEST, &SunbladeDuskPriestAI::Create);

	pScriptMgr->register_creature_script(CN_KALECGOS, &KalecgosAI::Create);
	pScriptMgr->register_creature_script(CN_SATHROVARR_THE_CORRUPTOR, &SathrovarrTheCorruptorAI::Create);
	pScriptMgr->register_creature_script(CN_BRUTALLUS, &BrutallusAI::Create);
	pScriptMgr->register_creature_script(CN_FELMYST, &FelmystAI::Create);
	pScriptMgr->register_creature_script(CN_LADY_SACROLASH, &LadySacrolashAI::Create);
	pScriptMgr->register_creature_script(CN_GRAND_WARLOCK_ALYTHESS, &GrandWarlockAlythessAI::Create);
	pScriptMgr->register_creature_script(CREATURE_SHADOW_IMAGE, &mob_Shadow_imageAI::Create);
	
	pScriptMgr->register_creature_script(CN_MURU, &MuruAI::Create);
	pScriptMgr->register_creature_script(CN_SHADOWSWORD_BERSERKER, &ShadowswordBerserkerAI::Create);
	pScriptMgr->register_creature_script(CN_SHADOWSWORD_FURY_MAGE, &ShadowswordFuryMageAI::Create);
	pScriptMgr->register_creature_script(CN_VOID_SENTINEL, &VoidSentinelAI::Create);
	pScriptMgr->register_creature_script(CN_ENTROPIUS, &EntropiusAI::Create);
	
	
	
	
	pScriptMgr->register_creature_script(CN_SUNBLADE_CABALIST, &SunbladeCabalistAI::Create);
	
	
	
}
