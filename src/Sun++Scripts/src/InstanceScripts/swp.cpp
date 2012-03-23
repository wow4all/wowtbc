#include "Setup.h"
void SetupSunwellPlateau(ScriptMgr * mgr);

//*****Raid_SunwellPlateau.cpp*******//

//Kalecgos

#define Kalecgos 24850

// Spells
//Dragon form
#define Arcane_Buffet 45018
#define Frost_Breath 44799 
//Wild_Magic // random spell
#define Wild_Magic1 44978
#define Wild_Magic2 45001
#define Wild_Magic3 45002
#define Wild_Magic4 45004
#define Wild_Magic5 45006
#define Wild_Magic6 45010
//end
#define Spectral_Blast 44866
//humanoid form
#define Curse_of_Boundless_Agony 45032
#define K_Shadow_Bolt_Volley 45031     
#define Spectral_Exhaustion  44867

class KalecgosAI : public CreatureAIScript
{
protected:
    int nrspells;
    SP_AI_Spell spells[12];
    bool phase;
    int spmin;
    int WildMagicTimer;


public:
    ADD_CREATURE_FACTORY_FUNCTION(KalecgosAI);

    KalecgosAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
        nrspells = 12;

        spells[0].info = dbcSpell.LookupEntry(Arcane_Buffet);
        spells[0].targettype = TARGET_SELF; 
        spells[0].cooldown = 80;
        spells[0].perctrigger = 20.0f;

        spells[1].info = dbcSpell.LookupEntry(Frost_Breath);
        spells[1].targettype = TARGET_RANDOM_DESTINATION; 
        spells[1].cooldown = 24;
        spells[1].perctrigger = 20.0f;
        
        spells[2].info = dbcSpell.LookupEntry(Spectral_Blast);
        spells[2].targettype = TARGET_SELF; 
        spells[2].cooldown = 45;
        spells[2].perctrigger = 20.0f;
        
        spells[3].info = dbcSpell.LookupEntry(Curse_of_Boundless_Agony);
        spells[3].targettype = TARGET_SELF; 
        spells[3].cooldown = 45;
        spells[3].perctrigger = 20.0f;
        
        spells[4].info = dbcSpell.LookupEntry(K_Shadow_Bolt_Volley);
        spells[4].targettype = TARGET_RANDOM_SINGLE; 
        spells[4].cooldown = 19;
        spells[4].perctrigger = 20.0f;
        
        spells[5].info = dbcSpell.LookupEntry(Spectral_Exhaustion);
        spells[5].targettype = TARGET_SELF; 
        spells[5].cooldown = 90;
        spells[5].perctrigger = 20.0f;
        
        spells[6].info = dbcSpell.LookupEntry(Wild_Magic1);
        spells[6].targettype = TARGET_SELF; 
        spells[6].perctrigger = 100.0f;
        
        spells[7].info = dbcSpell.LookupEntry(Wild_Magic2);
        spells[7].targettype = TARGET_SELF; 
        spells[7].perctrigger = 100.0f;

        spells[8].info = dbcSpell.LookupEntry(Wild_Magic3);
        spells[8].targettype = TARGET_SELF; 
        spells[8].perctrigger = 100.0f;
        
        spells[9].info = dbcSpell.LookupEntry(Wild_Magic4);
        spells[9].targettype = TARGET_SELF; 
        spells[9].perctrigger = 100.0f;
        
        spells[10].info = dbcSpell.LookupEntry(Wild_Magic5);
        spells[10].targettype = TARGET_SELF; 
        spells[10].perctrigger = 100.0f;
        
        spells[11].info = dbcSpell.LookupEntry(Wild_Magic6);
        spells[11].targettype = TARGET_SELF; 
        spells[11].perctrigger = 100.0f;
    }
    
    
    void OnCombatStart(Unit* mTarget)
    {
        for(int i=0;i<nrspells;i++)  spells[i].Timer = 0;
        spmin = 0;
        phase = 0;
        nrspells = 3;
        WildMagicTimer = 45;
        RegisterAIUpdateEvent(1000);
    }

    void OnTargetDied(Unit* mTarget)
    {

    }

    
    void OnCombatStop(Unit *mTarget)
    {
        _unit->SetUInt32Value(UNIT_FIELD_DISPLAYID , 23345); //to dragon
        RemoveAIUpdateEvent();
    }

    void OnDied(Unit * mKiller)
    {
        RemoveAIUpdateEvent();
    }

    void AIUpdate()
    {    
        if (_unit->GetHealthPct() <= 50 && !phase) 
        {
            spmin = 3;
            nrspells = 6;
            phase = 1;
            _unit->SetUInt32Value(UNIT_FIELD_DISPLAYID , 23345); //to humanoid  

?? 
        }
        if (!phase && !WildMagicTimer)    
        {
            int RandomSpeach;
            RandomUInt(1000);
            RandomSpeach=rand()%6;
            switch (RandomSpeach)
            {
                case 0: 
                    SpellCastNew(spells[6],_unit);
                    break;
                case 1:
                    SpellCastNew(spells[7],_unit);
                    break;
                case 2:
                    SpellCastNew(spells[8],_unit);
                    break;
                case 3: 
                    SpellCastNew(spells[9],_unit);
                    break;
                case 4:
                    SpellCastNew(spells[10],_unit);
                    break;
                case 5:
                    SpellCastNew(spells[11],_unit);
                    break;
            }
            WildMagicTimer = 45;
        }
        if (!phase)
        {
            WildMagicTimer--;
        }
        SpellCastVal(spells,_unit,spmin,nrspells);
    }
};

//Brutallus

#define Brutallus 24882

// Spells
#define Meteor_Slash 45150
#define Burn 46394
#define Stomp 45185
#define Brut_Berserk 26662

class BrutallusAI : public CreatureAIScript
{
protected:
    int nrspells;
    SP_AI_Spell spells[4];
    bool Enrage;
    int EnrageTimer;


public:
    ADD_CREATURE_FACTORY_FUNCTION(BrutallusAI);

    BrutallusAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
        nrspells = 4;

        spells[0].info = dbcSpell.LookupEntry(Meteor_Slash);
        spells[0].targettype = TARGET_SELF; 
        spells[0].instant=false;
        spells[0].cooldown = 120;
        spells[0].perctrigger = 20.0f;

        spells[1].info = dbcSpell.LookupEntry(Burn);
        spells[1].targettype = TARGET_VARIOUS; 
        spells[1].cooldown = 90;
        spells[1].perctrigger = 20.0f;
        
        spells[2].info = dbcSpell.LookupEntry(Stomp);
        spells[2].targettype = TARGET_ATTACKING; 
        spells[2].cooldown = 45;
        spells[2].perctrigger = 5.0f;
        
        spells[3].info = dbcSpell.LookupEntry(Brut_Berserk);
        spells[3].targettype = TARGET_SELF; 
        spells[3].perctrigger = 100.0f;
        
    }
    
    
    void OnCombatStart(Unit* mTarget)
    {
        for(int i=0;i<nrspells;i++)  spells[i].Timer = 0;
        Enrage = 0;
        nrspells = 3;
        EnrageTimer = 360;
        RegisterAIUpdateEvent(1000);
    }

    void OnTargetDied(Unit* mTarget)
    {

    }

    
    void OnCombatStop(Unit *mTarget)
    {
        RemoveAIUpdateEvent();
    }

    void OnDied(Unit * mKiller)
    {
        RemoveAIUpdateEvent();
    }

    void AIUpdate()
    {    
        if (!Enrage && !EnrageTimer)    
        {
            SpellCastNew(spells[3],_unit);
            Enrage = 1;
        }
        else
        {
            EnrageTimer--;
        }
        SpellCastVal(spells,_unit,0,nrspells);
    }
};

//Felmyst

#define Felmyst 25038

// Spells
#define Fel_Cleave 19983
#define Corrosion 45866
#define Demonic_Vapor 45402
#define Gas_Nova 45855
#define Noxious_Fumes 47002
#define Encapsulate 45662
#define FogofCorruption 45717 
#define Fel_Enrage 26662 //???    Brut

class FelmystAI : public CreatureAIScript
{
protected:
    int nrspells;
    SP_AI_Spell spells[8];
    bool Enrage;
    int EnrageTimer;


public:
    ADD_CREATURE_FACTORY_FUNCTION(FelmystAI);

    FelmystAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
        nrspells = 8;

        spells[0].info = dbcSpell.LookupEntry(Fel_Cleave);
        spells[0].targettype = TARGET_ATTACKING; 
        spells[0].cooldown = 120;
        spells[0].perctrigger = 20.0f;

        spells[1].info = dbcSpell.LookupEntry(Corrosion);
        spells[1].targettype = TARGET_RANDOM_SINGLE; 
        spells[1].instant=false;
        spells[1].cooldown = 50;
        spells[1].perctrigger = 10.0f;
        
        spells[2].info = dbcSpell.LookupEntry(Demonic_Vapor);
        spells[2].targettype = TARGET_SELF; 
        spells[2].cooldown = 115;
        spells[2].perctrigger = 10.0f;
        
        spells[3].info = dbcSpell.LookupEntry(Gas_Nova);
        spells[3].targettype = TARGET_SELF; 
        spells[3].cooldown = 180;
        spells[3].perctrigger = 10.0f;
        
        spells[4].info = dbcSpell.LookupEntry(Noxious_Fumes);
        spells[4].targettype = TARGET_SELF; 
        spells[4].cooldown = 30;
        spells[4].perctrigger = 10.0f;
        
        spells[5].info = dbcSpell.LookupEntry(Encapsulate);
        spells[5].targettype = TARGET_RANDOM_SINGLE; 
        spells[5].cooldown = 25;
        spells[5].perctrigger = 10.0f;
        
        spells[6].info = dbcSpell.LookupEntry(FogofCorruption);
        spells[6].targettype = TARGET_SELF; 
        spells[6].cooldown = 420;
        spells[6].perctrigger = 10.0f;
        
        spells[7].info = dbcSpell.LookupEntry(Fel_Enrage);
        spells[7].targettype = TARGET_SELF; 
        spells[7].perctrigger = 100.0f;
        
    }
    
    
    void OnCombatStart(Unit* mTarget)
    {
        for(int i=0;i<nrspells;i++)  spells[i].Timer = 0;
        Enrage = 0;
        nrspells = 7;
        EnrageTimer = 600;
        RegisterAIUpdateEvent(1000);
    }

    void OnTargetDied(Unit* mTarget)
    {

    }

    
    void OnCombatStop(Unit *mTarget)
    {
        RemoveAIUpdateEvent();
    }

    void OnDied(Unit * mKiller)
    {
        RemoveAIUpdateEvent();
    }

    void AIUpdate()
    {    
        if (!Enrage && !EnrageTimer)    
        {
            SpellCastNew(spells[7],_unit);
            Enrage = 1;
        }
        else
        {
            EnrageTimer--;
        }
        SpellCastVal(spells,_unit,0,nrspells);
    }
};

//Alythess
#define Alythess 25166

// Spells
#define Pyrogenics 45230
#define Flame_Touched 45348
#define Conflagration 45342
#define Aly_Blaze 45235 
#define Flame_Sear 46771 

class AlythessAI : public CreatureAIScript
{
protected:
    int nrspells;
    SP_AI_Spell spells[5];

public:
    ADD_CREATURE_FACTORY_FUNCTION(AlythessAI);

    AlythessAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
        nrspells = 5;

        spells[0].info = dbcSpell.LookupEntry(Pyrogenics);
        spells[0].targettype = TARGET_SELF; 
        spells[0].cooldown = 45;
        spells[0].perctrigger = 20.0f;

        spells[1].info = dbcSpell.LookupEntry(Flame_Touched);
        spells[1].targettype = TARGET_VARIOUS; 
        spells[1].cooldown = 150;
        spells[1].perctrigger = 5.0f;
        
        spells[2].info = dbcSpell.LookupEntry(Conflagration);
        spells[2].targettype = TARGET_RANDOM_SINGLE; 
        spells[2].instant=false;
        spells[2].cooldown = 35;
        spells[2].perctrigger = 5.0f;
        
        spells[3].info = dbcSpell.LookupEntry(Aly_Blaze);
        spells[3].targettype = TARGET_RANDOM_SINGLE; 
        spells[3].instant=false;
        spells[3].cooldown = 27;
        spells[3].perctrigger = 5.0f;
        
        spells[4].info = dbcSpell.LookupEntry(Flame_Sear);
        spells[4].targettype = TARGET_SELF; 
        spells[4].cooldown = 17;
        spells[4].perctrigger = 10.0f;
        
    }
    
    
    void OnCombatStart(Unit* mTarget)
    {
        for(int i=0;i<nrspells;i++)  spells[i].Timer = 0;
        RegisterAIUpdateEvent(1000);
    }

    void OnTargetDied(Unit* mTarget)
    {

    }

    
    void OnCombatStop(Unit *mTarget)
    {
        RemoveAIUpdateEvent();
    }

    void OnDied(Unit * mKiller)
    {
        RemoveAIUpdateEvent();
    }

    void AIUpdate()
    {    
        SpellCastVal(spells,_unit,0,nrspells);
    }
};


//Lady Sacrolash
#define Lady_Sacrolash 25165
#define Shadow_Image 25214  

// Spells
#define Dark_Touched 45347
#define Shadow_Blades 45348
#define Shadow_Nova 45329
#define Confounding_Blow 45256


class LadySacrolashAI : public CreatureAIScript
{
protected:
    int nrspells;
    int ShadowImageTimer;
    SP_AI_Spell spells[4];

public:
    ADD_CREATURE_FACTORY_FUNCTION(LadySacrolashAI);

    LadySacrolashAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
        nrspells = 4;

        spells[0].info = dbcSpell.LookupEntry(Dark_Touched);
        spells[0].targettype = TARGET_VARIOUS; 
        spells[0].cooldown = 120;
        spells[0].perctrigger = 50.0f;

        spells[1].info = dbcSpell.LookupEntry(Shadow_Blades);
        spells[1].targettype = TARGET_SELF; 
        spells[1].instant=false;
        spells[1].maxdist2cast = 20.0f;
        spells[1].cooldown = 45;
        spells[1].perctrigger = 15.0f;
        
        spells[2].info = dbcSpell.LookupEntry(Shadow_Nova);
        spells[2].targettype = TARGET_VARIOUS; 
        spells[2].instant=false;
        spells[2].maxdist2cast = 10.0f;
        spells[2].cooldown = 65;
        spells[2].perctrigger = 5.0f;
        
        spells[3].info = dbcSpell.LookupEntry(Confounding_Blow);
        spells[3].targettype = TARGET_RANDOM_SINGLE; 
        spells[3].maxdist2cast = 10.0f;
        spells[3].instant=false;
        spells[3].cooldown = 47;
        spells[3].perctrigger = 25.0f;
            
    }
    
    
    void OnCombatStart(Unit* mTarget)
    {
        for(int i=0;i<nrspells;i++)  spells[i].Timer = 0;
        ShadowImageTimer = 80;
        RegisterAIUpdateEvent(1000);
    }

    void OnTargetDied(Unit* mTarget)
    {

    }

    
    void OnCombatStop(Unit *mTarget)
    {
        RemoveAIUpdateEvent();
    }

    void OnDied(Unit * mKiller)
    {
        RemoveAIUpdateEvent();
    }

    void AIUpdate()
    {    
        if (!ShadowImageTimer)
        {
            ShadowImageTimer = 80;
            RandomSummon(_unit,Shadow_Image);
        }
        else
        {
            ShadowImageTimer--;
        }
        SpellCastVal(spells,_unit,0,nrspells);
    }
};

//Muru
#define Muru 25741 
//mobs
#define Dark_Fiend 25744
#define Shadowsword_Berserker 25798
#define Shadowsword_Fury_Mage 25799
#define Void_Sentinel 25772
// Spells
#define Negative_Energy 46008
#define Darkness 45996


class MuruAI : public CreatureAIScript
{
protected:
    int nrspells;
    SP_AI_Spell spells[2];
    int DarkFiendTimer;
    int ShadowswordBerserkersTimer;
    int ShadowswordFuryMageTimer;
    int VoidSentinelTimer;

public:
    ADD_CREATURE_FACTORY_FUNCTION(MuruAI);

    MuruAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
        nrspells = 2;

        spells[0].info = dbcSpell.LookupEntry(Negative_Energy);
        spells[0].targettype = TARGET_SELF; 
        spells[0].cooldown = 25;
        spells[0].perctrigger = 20.0f;

        spells[1].info = dbcSpell.LookupEntry(Darkness);
        spells[1].targettype = TARGET_SELF; 
        spells[1].cooldown = 40;
        spells[1].perctrigger = 15.0f;
        
        
    }
    
    
    void OnCombatStart(Unit* mTarget)
    {
        for(int i=0;i<nrspells;i++)  spells[i].Timer = 0;
        DarkFiendTimer = 40;
        ShadowswordBerserkersTimer = 31;
        ShadowswordFuryMageTimer = 47;
        VoidSentinelTimer = 58;
        RegisterAIUpdateEvent(1000);
    }

    void OnTargetDied(Unit* mTarget)
    {

    }

    
    void OnCombatStop(Unit *mTarget)
    {
        RemoveAIUpdateEvent();
    }

    void OnDied(Unit * mKiller)
    {
        RemoveAIUpdateEvent();
    }

    void AIUpdate()
    {
        if (!DarkFiendTimer)
        {
            DarkFiendTimer = 60;
            RandomSummon(_unit,Dark_Fiend);
        }
        else
        {
            DarkFiendTimer--;
        }    
        if (!ShadowswordBerserkersTimer)
        {
            ShadowswordBerserkersTimer = 60;
            RandomSummon(_unit,Shadowsword_Berserker);
        }
        else
        {
            ShadowswordBerserkersTimer--;
        }
        if (!ShadowswordFuryMageTimer)
        {
            ShadowswordFuryMageTimer = 60;
            RandomSummon(_unit,Shadowsword_Fury_Mage);
        }
        else
        {
            ShadowswordFuryMageTimer--;
        }
        if (!VoidSentinelTimer)
        {
            VoidSentinelTimer = 60;
            RandomSummon(_unit,Void_Sentinel);
        }
        else
        {
            VoidSentinelTimer--;
        }
        SpellCastVal(spells,_unit,0,nrspells);
    }
};

//Mobs

//Shadow_Image

// Spells
#define Dark_Strike 45271
#define Shadowfury 45270

class ShadowImageAI : public CreatureAIScript
{
protected:
    int nrspells;
    SP_AI_Spell spells[2];

public:
    ADD_CREATURE_FACTORY_FUNCTION(ShadowImageAI);

    ShadowImageAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
        nrspells = 2;

        spells[0].info = dbcSpell.LookupEntry(Dark_Strike);
        spells[0].targettype = TARGET_ATTACKING; 
        spells[0].cooldown = 20;
        spells[0].perctrigger = 20.0f;

        spells[1].info = dbcSpell.LookupEntry(Shadowfury);
        spells[1].targettype = TARGET_RANDOM_SINGLE; 
        spells[1].maxdist2cast = 30.0f;
        spells[1].instant=false;
        spells[1].cooldown = 20;
        spells[1].perctrigger = 15.0f;
        
        
    }
    
    
    void OnCombatStart(Unit* mTarget)
    {
        for(int i=0;i<nrspells;i++)  spells[i].Timer = 0;
        RegisterAIUpdateEvent(1000);
    }

    void OnTargetDied(Unit* mTarget)
    {

    }

    
    void OnCombatStop(Unit *mTarget)
    {
        RemoveAIUpdateEvent();
    }

    void OnDied(Unit * mKiller)
    {
        _unit->Despawn(3000,0);
        RemoveAIUpdateEvent();
    }

    void AIUpdate()
    {    
        SpellCastVal(spells,_unit,0,nrspells);
    }
};

//Dark Fiend

class DarkFiendAI : public CreatureAIScript
{

public:
    ADD_CREATURE_FACTORY_FUNCTION(DarkFiendAI);

    DarkFiendAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {

        
        
    }
    
    
    void OnCombatStart(Unit* mTarget)
    {
        RegisterAIUpdateEvent(1000);
    }

    void OnTargetDied(Unit* mTarget)
    {

    }

    
    void OnCombatStop(Unit *mTarget)
    {
        RemoveAIUpdateEvent();
    }

    void OnDied(Unit * mKiller)
    {
        _unit->Despawn(3000,0);
        RemoveAIUpdateEvent();
    }

    void AIUpdate()
    {    

    }
};

//Shadowsword Berserkers

class ShadowswordBerserkerAI : public CreatureAIScript
{

public:
    ADD_CREATURE_FACTORY_FUNCTION(ShadowswordBerserkerAI);

    ShadowswordBerserkerAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {

        
        
    }
    
    
    void OnCombatStart(Unit* mTarget)
    {
        RegisterAIUpdateEvent(1000);
    }

    void OnTargetDied(Unit* mTarget)
    {

    }

    
    void OnCombatStop(Unit *mTarget)
    {
        RemoveAIUpdateEvent();
    }

    void OnDied(Unit * mKiller)
    {
        _unit->Despawn(3000,0);
        RemoveAIUpdateEvent();
    }

    void AIUpdate()
    {    

    }
};

//Shadowsword Fury Mages

class ShadowswordFuryMageAI : public CreatureAIScript
{

public:
    ADD_CREATURE_FACTORY_FUNCTION(ShadowswordFuryMageAI);

    ShadowswordFuryMageAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {

        
        
    }
    
    
    void OnCombatStart(Unit* mTarget)
    {
        RegisterAIUpdateEvent(1000);
    }

    void OnTargetDied(Unit* mTarget)
    {

    }

    
    void OnCombatStop(Unit *mTarget)
    {
        RemoveAIUpdateEvent();
    }

    void OnDied(Unit * mKiller)
    {
        _unit->Despawn(3000,0);
        RemoveAIUpdateEvent();
    }

    void AIUpdate()
    {    

    }
};

//Void Sentinels

#define Void_Spawn 25824
//spell
#define Shadow_Pulse 46087

class VoidSentinelAI : public CreatureAIScript
{
protected:
    int nrspells;
    SP_AI_Spell spells[1];

public:
    ADD_CREATURE_FACTORY_FUNCTION(VoidSentinelAI);

    VoidSentinelAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
        nrspells = 1;

        spells[0].info = dbcSpell.LookupEntry(Shadow_Pulse);
        spells[0].targettype = TARGET_SELF; 
        spells[0].cooldown = 25;
        spells[0].perctrigger = 20.0f;
        
    }
    
    
    void OnCombatStart(Unit* mTarget)
    {
        for(int i=0;i<nrspells;i++)  spells[i].Timer = 0;
        RegisterAIUpdateEvent(1000);
    }

    void OnTargetDied(Unit* mTarget)
    {

    }

    
    void OnCombatStop(Unit *mTarget)
    {
        RemoveAIUpdateEvent();
    }

    void OnDied(Unit * mKiller)
    {
        RandomSummon(_unit,Void_Spawn);
        _unit->Despawn(3000,0);
        RemoveAIUpdateEvent();
    }

    void AIUpdate()
    {    
        SpellCastVal(spells,_unit,0,nrspells);
    }
};

//Void_Spawn

class VoidSpawnAI : public CreatureAIScript
{

public:
    ADD_CREATURE_FACTORY_FUNCTION(VoidSpawnAI);

    VoidSpawnAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {

        
        
    }
    
    
    void OnCombatStart(Unit* mTarget)
    {
        RegisterAIUpdateEvent(1000);
    }

    void OnTargetDied(Unit* mTarget)
    {

    }

    
    void OnCombatStop(Unit *mTarget)
    {
        RemoveAIUpdateEvent();
    }

    void OnDied(Unit * mKiller)
    {
        _unit->Despawn(3000,0);
        RemoveAIUpdateEvent();
    }

    void AIUpdate()
    {    

    }
};

//trash gener

//--------------------------------------------------------------------------------------
#define CN_Sathrovarrthe_Corruptor        24892
//Spells
#define SPELL_Corrupting_Strike        45029
#define SPELL_CurseofBoundless_Agony        45032
#define SPELL_Shadow_Bolt_Volley_SC        45031

class SathrovarrtheCorruptorAI : public CreatureAIScript
{protected:
    int nrspells;
    SP_AI_Spell spells[3];
public:
    ADD_CREATURE_FACTORY_FUNCTION(SathrovarrtheCorruptorAI);
    SathrovarrtheCorruptorAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
        nrspells = 3;

        spells[0].info = dbcSpell.LookupEntry(SPELL_Corrupting_Strike);
        spells[0].targettype =TARGET_AUTO;
        spells[0].cooldown = 11;
        spells[0].perctrigger = 20.0f;

        spells[1].info = dbcSpell.LookupEntry(SPELL_CurseofBoundless_Agony);
        spells[1].targettype =TARGET_AUTO;
        spells[1].cooldown = 45;
        spells[1].perctrigger = 20.0f;

        spells[2].info = dbcSpell.LookupEntry(SPELL_Shadow_Bolt_Volley_SC);
        spells[2].targettype =TARGET_RANDOM_SINGLE;
        spells[2].instant=false;
        spells[2].maxdist2cast=40.0f;
        spells[2].cooldown = 15;
        spells[2].perctrigger = 20.0f;

    }
    void OnCombatStart(Unit* mTarget)
    {
        for(int i=0;i<nrspells;i++)  spells[i].Timer = 0;
        RegisterAIUpdateEvent(1000);
    }
    void OnCombatStop(Unit *mTarget)
    {
        RemoveAIUpdateEvent();
    }
    void OnDied(Unit * mKiller)
    {
        _unit->Despawn(30000,0);
        RemoveAIUpdateEvent();
    }
    void AIUpdate()
    {
        SpellCastVal(spells,_unit,0,nrspells);
    }
};




//--------------------------------------------------------------------------------------
#define CN_Sunblade_Cabalist        25363
//Spells
#define SPELL_Ignite_Mana        46543
#define SPELL_Shadow_Bolt_SC        47248
#define SPELL_Summon_Imp_SC        46544

class SunbladeCabalistAI : public CreatureAIScript
{protected:
    int nrspells;
    SP_AI_Spell spells[3];
public:
    ADD_CREATURE_FACTORY_FUNCTION(SunbladeCabalistAI);
    SunbladeCabalistAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
        nrspells = 3;

        spells[0].info = dbcSpell.LookupEntry(SPELL_Ignite_Mana);
        spells[0].targettype =TARGET_RANDOM_SINGLE;
        spells[0].instant=false;
        spells[0].maxdist2cast=50.0f;
        spells[0].cooldown = 25;
        spells[0].perctrigger = 20.0f;

        spells[1].info = dbcSpell.LookupEntry(SPELL_Shadow_Bolt_SC);
        spells[1].targettype =TARGET_RANDOM_SINGLE;
        spells[1].instant=false;
        spells[1].maxdist2cast=50.0f;
        spells[1].cooldown = 11;
        spells[1].perctrigger = 20.0f;

        spells[2].info = dbcSpell.LookupEntry(SPELL_Summon_Imp_SC);
        spells[2].targettype =TARGET_SELF;
        spells[2].cooldown = 90;
        spells[2].perctrigger = 20.0f;

    }
    void OnCombatStart(Unit* mTarget)
    {
        for(int i=0;i<nrspells;i++)  spells[i].Timer = 0;
        RegisterAIUpdateEvent(1000);
    }
    void OnCombatStop(Unit *mTarget)
    {
        RemoveAIUpdateEvent();
    }
    void OnDied(Unit * mKiller)
    {
        _unit->Despawn(30000,0);
        RemoveAIUpdateEvent();
    }
    void AIUpdate()
    {
        SpellCastVal(spells,_unit,0,nrspells);
    }
};




//--------------------------------------------------------------------------------------
#define CN_Sunblade_Arch_Mage        25367
//Spells
#define SPELL_Arcane_Explosion        46553
#define SPELL_Blink_SAM        46573
#define SPELL_Frost_Nova_SAM        46555

class SunbladeArchMageAI : public CreatureAIScript
{protected:
    int nrspells;
    SP_AI_Spell spells[3];
public:
    ADD_CREATURE_FACTORY_FUNCTION(SunbladeArchMageAI);
    SunbladeArchMageAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
        nrspells = 3;

        spells[0].info = dbcSpell.LookupEntry(SPELL_Arcane_Explosion);
        spells[0].targettype =TARGET_AUTO;
        spells[0].cooldown = 14;
        spells[0].perctrigger = 20.0f;

        spells[1].info = dbcSpell.LookupEntry(SPELL_Blink_SAM);
        spells[1].targettype =TARGET_AUTO;
        spells[0].instant=false;
        spells[1].cooldown = 19;
        spells[1].perctrigger = 20.0f;

        spells[2].info = dbcSpell.LookupEntry(SPELL_Frost_Nova_SAM);
        spells[2].targettype =TARGET_AUTO;
        spells[2].cooldown = 12;
        spells[2].perctrigger = 20.0f;

    }
    void OnCombatStart(Unit* mTarget)
    {
        for(int i=0;i<nrspells;i++)  spells[i].Timer = 0;
        RegisterAIUpdateEvent(1000);
    }
    void OnCombatStop(Unit *mTarget)
    {
        RemoveAIUpdateEvent();
    }
    void OnDied(Unit * mKiller)
    {
        _unit->Despawn(30000,0);
        RemoveAIUpdateEvent();
    }
    void AIUpdate()
    {
        SpellCastVal(spells,_unit,0,nrspells);
    }
};




//--------------------------------------------------------------------------------------
#define CN_Sunblade_Slayer        25368
//Spells
#define SPELL_Shoot_SS        47001
#define SPELL_Slaying_Shot        46557

class SunbladeSlayerAI : public CreatureAIScript
{protected:
    int nrspells;
    SP_AI_Spell spells[2];
public:
    ADD_CREATURE_FACTORY_FUNCTION(SunbladeSlayerAI);
    SunbladeSlayerAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
        nrspells = 2;

        spells[0].info = dbcSpell.LookupEntry(SPELL_Shoot_SS);
        spells[0].targettype =TARGET_RANDOM_SINGLE;
        spells[0].maxdist2cast=50.0f;
        spells[0].cooldown = 16;
        spells[0].perctrigger = 20.0f;

        spells[1].info = dbcSpell.LookupEntry(SPELL_Slaying_Shot);
        spells[1].targettype =TARGET_RANDOM_SINGLE;
        spells[1].maxdist2cast=50.0f;
        spells[1].cooldown = 20;
        spells[1].perctrigger = 20.0f;

    }
    void OnCombatStart(Unit* mTarget)
    {
        for(int i=0;i<nrspells;i++)  spells[i].Timer = 0;
        RegisterAIUpdateEvent(1000);
    }
    void OnCombatStop(Unit *mTarget)
    {
        RemoveAIUpdateEvent();
    }
    void OnDied(Unit * mKiller)
    {
        _unit->Despawn(30000,0);
        RemoveAIUpdateEvent();
    }
    void AIUpdate()
    {
        SpellCastVal(spells,_unit,0,nrspells);
    }
};




//--------------------------------------------------------------------------------------
#define CN_Sunblade_Vindicator        25369
//Spells
#define SPELL_Cleave_SV        46559
#define SPELL_Mortal_Strike        39171

class SunbladeVindicatorAI : public CreatureAIScript
{protected:
    int nrspells;
    SP_AI_Spell spells[2];
public:
    ADD_CREATURE_FACTORY_FUNCTION(SunbladeVindicatorAI);
    SunbladeVindicatorAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
        nrspells = 2;

        spells[0].info = dbcSpell.LookupEntry(SPELL_Cleave_SV);
        spells[0].targettype =TARGET_AUTO;
        spells[0].cooldown = 8;
        spells[0].perctrigger = 20.0f;

        spells[1].info = dbcSpell.LookupEntry(SPELL_Mortal_Strike);
        spells[1].targettype =TARGET_AUTO;
        spells[1].cooldown = 12;
        spells[1].perctrigger = 20.0f;

    }
    void OnCombatStart(Unit* mTarget)
    {
        for(int i=0;i<nrspells;i++)  spells[i].Timer = 0;
        RegisterAIUpdateEvent(1000);
    }
    void OnCombatStop(Unit *mTarget)
    {
        RemoveAIUpdateEvent();
    }
    void OnDied(Unit * mKiller)
    {
        _unit->Despawn(30000,0);
        RemoveAIUpdateEvent();
    }
    void AIUpdate()
    {
        SpellCastVal(spells,_unit,0,nrspells);
    }
};




//--------------------------------------------------------------------------------------
#define CN_Sunblade_Dusk_Priest        25370
//Spells
#define SPELL_Fear_SDP        46561
#define SPELL_Mind_Flay        46562
#define SPELL_Shadow_Word_Pain_SDP        46560

class SunbladeDuskPriestAI : public CreatureAIScript
{protected:
    int nrspells;
    SP_AI_Spell spells[3];
public:
    ADD_CREATURE_FACTORY_FUNCTION(SunbladeDuskPriestAI);
    SunbladeDuskPriestAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
        nrspells = 3;

        spells[0].info = dbcSpell.LookupEntry(SPELL_Fear_SDP);
        spells[0].targettype =TARGET_AUTO;
        spells[0].cooldown = 12;
        spells[0].perctrigger = 20.0f;

        spells[1].info = dbcSpell.LookupEntry(SPELL_Mind_Flay);
        spells[1].targettype =TARGET_RANDOM_SINGLE;
        spells[1].instant=false;
        spells[1].maxdist2cast=50.0f;
        spells[1].cooldown = 8;
        spells[1].perctrigger = 20.0f;

        spells[2].info = dbcSpell.LookupEntry(SPELL_Shadow_Word_Pain_SDP);
        spells[2].targettype =TARGET_RANDOM_SINGLE;
        spells[2].maxdist2cast=60.0f;
        spells[2].cooldown = 27;
        spells[2].perctrigger = 20.0f;

    }
    void OnCombatStart(Unit* mTarget)
    {
        for(int i=0;i<nrspells;i++)  spells[i].Timer = 0;
        RegisterAIUpdateEvent(1000);
    }
    void OnCombatStop(Unit *mTarget)
    {
        RemoveAIUpdateEvent();
    }
    void OnDied(Unit * mKiller)
    {
        _unit->Despawn(30000,0);
        RemoveAIUpdateEvent();
    }
    void AIUpdate()
    {
        SpellCastVal(spells,_unit,0,nrspells);
    }
};




//--------------------------------------------------------------------------------------
#define CN_Sunblade_Dawn_Priest        25371
//Spells
#define SPELL_Holy_Nova_SDaP        46564
#define SPELL_Holyform        46565
#define SPELL_Renew_SDaP        46563

class SunbladeDawnPriestAI : public CreatureAIScript
{protected:
    int nrspells;
    SP_AI_Spell spells[3];
public:
    ADD_CREATURE_FACTORY_FUNCTION(SunbladeDawnPriestAI);
    SunbladeDawnPriestAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
        nrspells = 3;

        spells[0].info = dbcSpell.LookupEntry(SPELL_Holy_Nova_SDaP);
        spells[0].targettype =TARGET_AUTO;
        spells[0].cooldown = 23;
        spells[0].perctrigger = 20.0f;

        spells[1].info = dbcSpell.LookupEntry(SPELL_Holyform);
        spells[1].targettype =TARGET_AUTO;
        spells[1].cooldown = 19;
        spells[1].perctrigger = 20.0f;

        spells[2].info = dbcSpell.LookupEntry(SPELL_Renew_SDaP);
        spells[2].targettype =TARGET_RANDOM_FRIEND;
        spells[2].cooldown = 90;
        spells[2].perctrigger = 20.0f;

    }
    void OnCombatStart(Unit* mTarget)
    {
        for(int i=0;i<nrspells;i++)  spells[i].Timer = 0;
        RegisterAIUpdateEvent(1000);
    }
    void OnCombatStop(Unit *mTarget)
    {
        RemoveAIUpdateEvent();
    }
    void OnDied(Unit * mKiller)
    {
        _unit->Despawn(30000,0);
        RemoveAIUpdateEvent();
    }
    void AIUpdate()
    {
        SpellCastVal(spells,_unit,0,nrspells);
    }
};




//--------------------------------------------------------------------------------------
#define CN_Sunblade_Scout        25372
//Spells
#define SPELL_Sinister_Strike_SS        46558

class SunbladeScoutAI : public CreatureAIScript
{protected:
    int nrspells;
    SP_AI_Spell spells[1];
public:
    ADD_CREATURE_FACTORY_FUNCTION(SunbladeScoutAI);
    SunbladeScoutAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
        nrspells = 1;

        spells[0].info = dbcSpell.LookupEntry(SPELL_Sinister_Strike_SS);
        spells[0].targettype =TARGET_ATTACKING;
        spells[0].cooldown = 8;
        spells[0].perctrigger = 20.0f;

    }
    void OnCombatStart(Unit* mTarget)
    {
        for(int i=0;i<nrspells;i++)  spells[i].Timer = 0;
        RegisterAIUpdateEvent(1000);
    }
    void OnCombatStop(Unit *mTarget)
    {
        RemoveAIUpdateEvent();
    }
    void OnDied(Unit * mKiller)
    {
        _unit->Despawn(30000,0);
        RemoveAIUpdateEvent();
    }
    void AIUpdate()
    {
        SpellCastVal(spells,_unit,0,nrspells);
    }
};




//--------------------------------------------------------------------------------------
#define CN_Sunblade_Protector        25507
//Spells
#define SPELL_Fel_Lightning        46480

class SunbladeProtectorAI : public CreatureAIScript
{protected:
    int nrspells;
    SP_AI_Spell spells[1];
public:
    ADD_CREATURE_FACTORY_FUNCTION(SunbladeProtectorAI);
    SunbladeProtectorAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
        nrspells = 1;

        spells[0].info = dbcSpell.LookupEntry(SPELL_Fel_Lightning);
        spells[0].targettype =TARGET_RANDOM_SINGLE;
        spells[0].instant=false;
        spells[0].maxdist2cast=60.0f;
        spells[0].cooldown = 17;
        spells[0].perctrigger = 20.0f;

    }
    void OnCombatStart(Unit* mTarget)
    {
        for(int i=0;i<nrspells;i++)  spells[i].Timer = 0;
        RegisterAIUpdateEvent(1000);
    }
    void OnCombatStop(Unit *mTarget)
    {
        RemoveAIUpdateEvent();
    }
    void OnDied(Unit * mKiller)
    {
        _unit->Despawn(30000,0);
        RemoveAIUpdateEvent();
    }
    void AIUpdate()
    {
        SpellCastVal(spells,_unit,0,nrspells);
    }
};




//--------------------------------------------------------------------------------------
#define CN_Sunblade_Dragonhawk        25867
//Spells
#define SPELL_Flame_Breath        47251

class SunbladeDragonhawkAI : public CreatureAIScript
{protected:
    int nrspells;
    SP_AI_Spell spells[1];
public:
    ADD_CREATURE_FACTORY_FUNCTION(SunbladeDragonhawkAI);
    SunbladeDragonhawkAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
        nrspells = 1;

        spells[0].info = dbcSpell.LookupEntry(SPELL_Flame_Breath);
        spells[0].targettype =TARGET_AUTO;
        spells[0].cooldown = 14;
        spells[0].perctrigger = 20.0f;

    }
    void OnCombatStart(Unit* mTarget)
    {
        for(int i=0;i<nrspells;i++)  spells[i].Timer = 0;
        RegisterAIUpdateEvent(1000);
    }
    void OnCombatStop(Unit *mTarget)
    {
        RemoveAIUpdateEvent();
    }
    void OnDied(Unit * mKiller)
    {
        _unit->Despawn(30000,0);
        RemoveAIUpdateEvent();
    }
    void AIUpdate()
    {
        SpellCastVal(spells,_unit,0,nrspells);
    }
};




//--------------------------------------------------------------------------------------
#define CN_Fire_Fiend        26101
//Spells
#define SPELL_Fire_Nova_FF        46551

class FireFiendAI : public CreatureAIScript
{protected:
    int nrspells;
    SP_AI_Spell spells[1];
public:
    ADD_CREATURE_FACTORY_FUNCTION(FireFiendAI);
    FireFiendAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
        nrspells = 1;

        spells[0].info = dbcSpell.LookupEntry(SPELL_Fire_Nova_FF);
        spells[0].targettype =TARGET_AUTO;
        spells[0].cooldown = 11;
        spells[0].perctrigger = 20.0f;

    }
    void OnCombatStart(Unit* mTarget)
    {
        for(int i=0;i<nrspells;i++)  spells[i].Timer = 0;
        RegisterAIUpdateEvent(1000);
    }
    void OnCombatStop(Unit *mTarget)
    {
        RemoveAIUpdateEvent();
    }
    void OnDied(Unit * mKiller)
    {
        _unit->Despawn(30000,0);
        RemoveAIUpdateEvent();
    }
    void AIUpdate()
    {
        SpellCastVal(spells,_unit,0,nrspells);
    }
};

void SetupSunwellPlateau(ScriptMgr * mgr)
{
    mgr->register_creature_script(Kalecgos, &KalecgosAI::Create);
    mgr->register_creature_script(Brutallus, &BrutallusAI::Create);
    mgr->register_creature_script(Felmyst, &FelmystAI::Create);
    mgr->register_creature_script(Alythess, &AlythessAI::Create);
    mgr->register_creature_script(Lady_Sacrolash, &LadySacrolashAI::Create);
    mgr->register_creature_script(Muru, &MuruAI::Create);
    //mobs
    mgr->register_creature_script(Shadow_Image, &ShadowImageAI::Create);
    mgr->register_creature_script(Dark_Fiend, &DarkFiendAI::Create);
    mgr->register_creature_script(Shadowsword_Berserker, 

&ShadowswordBerserkerAI::Create);
    mgr->register_creature_script(Shadowsword_Fury_Mage, 

&ShadowswordFuryMageAI::Create);
    mgr->register_creature_script(Void_Sentinel, &VoidSentinelAI::Create);
    mgr->register_creature_script(Void_Spawn, &VoidSpawnAI::Create);
    //gener mobs
    mgr->register_creature_script(CN_Sathrovarrthe_Corruptor, 

&SathrovarrtheCorruptorAI::Create);
    mgr->register_creature_script(CN_Sunblade_Cabalist, &SunbladeCabalistAI::Create);
    mgr->register_creature_script(CN_Sunblade_Arch_Mage, &SunbladeArchMageAI::Create);
    mgr->register_creature_script(CN_Sunblade_Slayer, &SunbladeSlayerAI::Create);
    mgr->register_creature_script(CN_Sunblade_Vindicator, 

&SunbladeVindicatorAI::Create);
    mgr->register_creature_script(CN_Sunblade_Dusk_Priest, 

&SunbladeDuskPriestAI::Create);
    mgr->register_creature_script(CN_Sunblade_Dawn_Priest, 

&SunbladeDawnPriestAI::Create);
    mgr->register_creature_script(CN_Sunblade_Scout, &SunbladeScoutAI::Create);
    mgr->register_creature_script(CN_Sunblade_Protector, &SunbladeProtectorAI::Create);
    mgr->register_creature_script(CN_Sunblade_Dragonhawk, 

&SunbladeDragonhawkAI::Create);
    mgr->register_creature_script(CN_Fire_Fiend, &FireFiendAI::Create);
    
        
    