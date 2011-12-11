/*
 * Sun++ Scripts for TbcE MMORPG Server
 * Copyright (C) 2005-2007 Ascent Team <http://www.ascentemu.com/>
 * Copyright (C) 2007-2008 Moon++ Team <http://www.moonplusplus.info/>
 * Copyright (C) 2009-2011 Durotar Team  <http://www.Wow-tbc.org/>
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

//Shadowy Necromancer//
#define SHADOWY_NECROMANCER			                17899
#define SHADOWY_NECROMANCER_SBOLT                   31627
#define SHADOWY_NECROMANCER_UNHOLY_FRENZY           31626
/*Bfx Not sure on these Need Dummy Script 
#define SHADOWY_NECROMANCER_RAISE_DEAD_1            31617
#define SHADOWY_NECROMANCER_RAISE_DEAD_2            31625
#define SHADOWY_NECROMANCER_RAISE_DEAD_3            31624
*/

class SHADOWY_NECROMANCERAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(SHADOWY_NECROMANCERAI, MoonScriptCreatureAI);
	SHADOWY_NECROMANCERAI(Creature* pCreature) : MoonScriptCreatureAI(pCreature)
	{
        
		
        //spells
		AddSpell(SHADOWY_NECROMANCER_SBOLT, Target_Current, 100, 0, 15, 0, 10);
		AddSpell(SHADOWY_NECROMANCER_UNHOLY_FRENZY, TARGET_RANDOM_FRIEND, 100, 0, 15, 0, 30);
	}
};

//Giant Infernal//
#define GIANT_INFERNAL			                    17899
#define GIANT_INFERNAL_FLAME_BUFFET                 31724

class GIANT_INFERNALAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(GIANT_INFERNALAI, MoonScriptCreatureAI);
	GIANT_INFERNALAI(Creature* pCreature) : MoonScriptCreatureAI(pCreature)
	{
        //spells
		AddSpell(GIANT_INFERNAL_FLAME_BUFFET, Target_Current, 100, 0, 15, 0, 5);
	}
	
};

//Frost Wyrm//
#define FROST_WYRM			                        17907
#define FROST_WYRM_FROSTBREATH                      31688

class FROST_WYRMAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(FROST_WYRMAI, MoonScriptCreatureAI);
	FROST_WYRMAI(Creature* pCreature) : MoonScriptCreatureAI(pCreature)
	{
        //spells
		AddSpell(FROST_WYRM_FROSTBREATH, Target_RandomPlayer, 100, 0, 15, 0, 7);
	};
	
	{
		SetFlyMode( true );
		SetCanMove( false );
		
	};
};

//Gargoyle//
#define GARGOYLE			                        17906
#define GARGOYLE_STRIKE                             31664
#define GARGOYLE_STRIKE_PROC                        32647

class GARGOYLEAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(GARGOYLEAI, MoonScriptCreatureAI);
	GARGOYLEAI(Creature* pCreature) : MoonScriptCreatureAI(pCreature)
	{
        //spells
		AddSpell(GARGOYLE_STRIKE, Target_RandomPlayer, 100, 0, 15, 0, 7);
		AddSpell(GARGOYLE_STRIKE_PROC, Target_RandomPlayer, 100, 0, 15, 0, 7);
	};
	
	{
		SetFlyMode( true );
		SetCanMove( true );
		
	};
};

//Banshee/
#define BANSHEE			                            17905
#define BANSHEE_ANTI_MAGIC_SHELL                    31662
#define BANSHEE_CURSE                               31651
#define BANSHEE_WAIL                                38183

class BANSHEEAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(GARGOYLEAI, MoonScriptCreatureAI);
	BANSHEEAI(Creature* pCreature) : MoonScriptCreatureAI(pCreature)
	{
        //spells
		AddSpell(BANSHEE_ANTI_MAGIC_SHELL, TargetSelf, 100, 0, 15, 0, 15);
		AddSpell(BANSHEE_CURSE , Target_Current, 100, 0, 15, 0, 10);
		AddSpell(BANSHEE_WAIL, Target_RandomPlayer, 100, 0, 15, 0, 25);
	};
	
	
};

void SetupHyjalTrash(ScriptMgr * mgr)
{
	

	mgr->register_creature_script(BANSHEE, &BANSHEEAI::Create);
	mgr->register_creature_script(GARGOYLE, &GARGOYLEAI::Create);
	mgr->register_creature_script(FROST_WYRM, &FROST_WYRMAI::Create);
	mgr->register_creature_script(GIANT_INFERNAL, &GIANT_INFERNALAI::Create);
	mgr->register_creature_script(SHADOWY_NECROMANCER, &SHADOWY_NECROMANCERAI::Create);

}