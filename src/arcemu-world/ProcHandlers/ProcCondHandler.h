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

#ifndef _PROCHANDLER_H_
#define _PROCHANDLER_H_


//this should be a value greater then one from dbc. Note that we waist memory if we pick a too large one
// 65spellids would mean : 65k*4 bytes = 256KByte memory compiled in 32k bit mode. That is nothing :P
#define MAX_SPELL_ID_FROMDBC 65535

struct SpellEntry;
struct ProcTriggerSpell;
class Unit;

using namespace ProcEnums;

typedef std::list<struct ProcTriggerSpell>			ProcTriggerSpellList;

struct ProcCondSharedDataStruct
{
	ProcCondSharedDataStruct()
	{
		owner			= NULL;
		ProcFlags		= 0;
		victim			= NULL;
		CastingSpell	= NULL;
		origId			= 0;
		Fulldmg			= 0;
		Absdmg			= 0;
		dmg_overwrite	= 0;
		spellId			= 0;
		ospinfo			= NULL;
		spe				= NULL;
		resisted_dmg	= 0;
	}

	Unit							*owner;			//the proc is registered to this guy
	uint32							ProcFlags;		//contains the ProcFlags that called prochandler
	Unit							*victim;		//depending on procflags this can represent the target the suffered the event. Ex : damagde received, damage applied
	SpellEntry						*CastingSpell;	//in case this is a spellcast Proc then we have a value here
	uint32							origId;			//itr2->origId
	int32							Fulldmg;		//un case of a damage proc this contains full damage that can char receive
	int32							Absdmg;			//fulldmg - absdmg = damage applied to target
	ProcTriggerSpellList::iterator	cur_itr;		//we are iterating through a list of registered handlers. We are at this one atm;
	int32							dmg_overwrite;	//we can force spell effects to take values as we desire like spells that recover health based on dmg
	uint32							spellId;		//for overwrite cur_itr->spellId
	SpellEntry						*ospinfo;		//dbcSpell.LookupEntryForced(origId)
	SpellEntry						*spe;			//dbcSpell.LookupEntryForced(spellId)
	int32							resisted_dmg;	//return value of Unit::HandleProc
};

class ProcHandler
{
public:
	//Misc
	ProcCondHandlerRes NatureGuardian(ProcCondSharedDataStruct *shareddata);
	ProcCondHandlerRes MaceStunEffect(ProcCondSharedDataStruct *shareddata);
	ProcCondHandlerRes SwordSpecialization(ProcCondSharedDataStruct *shareddata);
	
	//Common
	#include "ProcCondHandlerCommon.h"

	//Druid
	#include "ProcCondHandlerDruid.h"

	//Hunter
	#include "ProcCondHandlerHunter.h"

	//Items
	#include "ProcCondHandlerItems.h"

	//Mage
	#include "ProcCondHandlerMage.h"

	//Paladin
	#include "ProcCondHandlerPaladin.h"

	//Priest
	#include "ProcCondHandlerPriest.h"

	//Rogue
	#include "ProcCondHandlerRogue.h"

	//Shaman
	#include "ProcCondHandlerShaman.h"

	//Warlock
	#include "ProcCondHandlerWarlock.h"

	//Warrior
	#include "ProcCondHandlerWarrior.h"
};

struct ProcHandlerDefinition
{
	ProcHandlerDefinition()
	{
		handler				= NULL;
		m_canProcOnCreature = false;
	}

	ProcCondHandlerRes (ProcHandler::*handler)(ProcCondSharedDataStruct *shareddata);
	bool m_canProcOnCreature;
};

//we registerer our functions in handler lists. This is made through function since we set non used 
//slots to NULL with function ....
void InitProcCondHandlers();

//an idea is to make this for spellhashes instead of ids
//at this step i just move old way to this one and maybe in next phase improve it
extern array<ProcHandlerDefinition, MAX_SPELL_ID_FROMDBC> G_ProcCondHandlers;

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//							Same thing but PPM related conditions
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

extern float (*G_ProcPPMCondHandlers[MAX_SPELL_ID_FROMDBC])(ProcCondSharedDataStruct *shareddata);

#endif
