/*
 * Sun++ Scripts for TbcE MMORPG Server
 * Copyright (C) 2005-2007 Ascent Team <http://www.ascentemu.com/>
 * Copyright (C) 2007-2008 Moon++ Team <http://www.moonplusplus.info/>
 * Copyright (C) 2009-2012 <http://code.google.com/p/wowtbc/.org/>
 *
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
#include "../Base/ai.h"
 
#define NPC_Dps_Dummy_Normal 87123
#define NPC_Dps_Dummy_Heroic 87124
#define NPC_Dps_Dummy_Boss   87125
 


class Dps_Dummy_NormalAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(Dps_Dummy_NormalAI);

    Dps_Dummy_NormalAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		_unit->GetAIInterface()->SetAllowedToEnterCombat(false);
	}

	
};

class Dps_Dummy_HeroicAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(Dps_Dummy_HeroicAI);

    Dps_Dummy_HeroicAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		_unit->GetAIInterface()->SetAllowedToEnterCombat(false);
	}

	
};

class Dps_Dummy_BossAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(Dps_Dummy_BossAI);

    Dps_Dummy_BossAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		_unit->GetAIInterface()->SetAllowedToEnterCombat(false);
	}

	
};

void SetupDpsDummies(ScriptMgr* pScriptMgr) 
{
	pScriptMgr->register_creature_script(NPC_Dps_Dummy_Normal, &Dps_Dummy_NormalAI::Create);
	pScriptMgr->register_creature_script(NPC_Dps_Dummy_Heroic, &Dps_Dummy_HeroicAI::Create);
	pScriptMgr->register_creature_script(NPC_Dps_Dummy_Boss, &Dps_Dummy_BossAI::Create);
	
};
