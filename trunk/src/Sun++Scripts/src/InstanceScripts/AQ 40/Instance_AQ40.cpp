/*
 * Summitemu scripts - AQ40
 * Copyright (C) 2010 tbcgaming <http://tbcgaming.com/>
 * Developed by bloodfangx
 */
 
enum CreatureSpells
{
  //ANUBISATH GUARDIAN
  GUARDIAN_PLAGUE     = -22997,
};
 
enum CreatureEntrys
{
  CN_ANUBGUARDIAN = -
};



class AnubGuardianAI : public MoonScriptCreatureAI
{
    MOONSCRIPT_FACTORY_FUNCTION(AnubGuardianAI, MoonScriptCreatureAI);
	AnubGuardianAI(Creature* pCreature) : MoonScriptCreatureAI( pCreature )
	{	
		   AddSpell(GUARDIAN_PLAGUE, Target_Self, 90, 0, 10);
	};

	void AIUpdate()
	
};



void SetupAQ40(ScriptMgr* pScriptMgr)
{
        mgr->register_creature_script(CN_ANUBGUARDIAN, &AnubGuardianAI::Create);
        
}
 
 