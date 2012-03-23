// ---    Illidan Encounter Event      --- //

/* Global Variables */

// Additional stuff
uint32 m_phase[1000000];	// dunno if it's enough (uint32 InstanceID -> 4,294,967,295)

// Events
uint32 DeathEvent[1000000];

#define WALK 0
#define RUN 256
#define FLY 768

// Global settings - comment to disable
#define USE_SHADOW_PRISON	// aggroes a lot of mobs/NPCs if they are not friendly to Illidan

struct Coords SearchPos[]=
{
	{ 744.743896f, 270.928619f, 352.996185f, 2.605572f },
	{ 742.240051f, 330.404205f, 352.996185f, 3.249600f },
	{ 686.947632f, 305.891022f, 353.192383f, 3.096451f },
	{ 676.432495f, 266.354828f, 353.264984f, 4.317750f },
	{ 674.560974f, 353.792755f, 352.996094f, 1.918359f }
};

/* Effect and Trigger AIs */

/* Door Event Trigger AI - Creature AI Class */

#define CN_DOOR_EVENT_TRIGGER	30001

class DoorEventTriggerAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(DoorEventTriggerAI);

    DoorEventTriggerAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
		unit->GetAIInterface()->m_moveFly = true;
    }
};

/* Demon Fire AI - Creature AI Class */

#define CN_DEMON_FIRE	23069

#define DEMON_FIRE		40029

class DemonFireAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(DemonFireAI);

    DemonFireAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
		unit->CastSpell(unit, dbcSpell.LookupEntry(DEMON_FIRE), true);
		unit->GetAIInterface()->disable_melee = true;
		unit->GetAIInterface()->m_canMove = false;
		unit->m_noRespawn = true;
		unit->Despawn(60000, 0);
    }

    void OnCombatStop(Unit *mTarget)
    {
        unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        unit->GetAIInterface()->SetAIState(STATE_IDLE);
    }
};

/* Eye Beam Trigger AI - Creature AI Class */

#define CN_EYE_BEAM_TRIGGER	30000

#define EYE_BLAST			40017

class EyeBeamTriggerAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(EyeBeamTriggerAI);

    EyeBeamTriggerAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
		unit->GetAIInterface()->SetAIState(STATE_SCRIPTMOVE);
		unit->GetAIInterface()->disable_melee = true;
		unit->GetAIInterface()->m_moveRun = true;
		unit->m_noRespawn = true;
		unit->Despawn(12000, 0);

		RegisterAIUpdateEvent(1000);
		WallCreating = false;
    }

    void OnCombatStop(Unit *mTarget)
    {
        unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        unit->GetAIInterface()->SetAIState(STATE_IDLE);
    }

    void OnDied(Unit * mKiller)
    {
       RemoveAIUpdateEvent();
    }

    void AIUpdate()
    {
		if (WallCreating == false)
		{
			if (unit->GetPositionX() == 642.240601f && unit->GetPositionY() == 297.297180f && unit->GetPositionZ() == 353.423401f)
				unit->GetAIInterface()->MoveTo(707.019043f, 270.441772f, 352.996063f, 5.953270f);
			if (unit->GetPositionX() == 641.197449f && unit->GetPositionY() == 314.330963f && unit->GetPositionZ() == 353.300262f)
				unit->GetAIInterface()->MoveTo(706.592407f, 343.425568f, 352.996124f, 3.659908f);
			if (unit->GetPositionX() == 657.239807f && unit->GetPositionY() == 256.925568f && unit->GetPositionZ() == 352.996094f)
				unit->GetAIInterface()->MoveTo(706.593262f, 310.011475f, 353.693848f, 2.506154f);
			if (unit->GetPositionX() == 657.913330f && unit->GetPositionY() == 353.562775f && unit->GetPositionZ() == 352.996185f)
				unit->GetAIInterface()->MoveTo(706.751343f, 298.312683f, 353.653809f, 3.436852f);
			if (unit->GetPositionX() == 707.019043f && unit->GetPositionY() == 270.441772f && unit->GetPositionZ() == 352.996063f)
				unit->GetAIInterface()->MoveTo(642.240601f, 297.297180f, 353.423401f, 5.953270f);
			if (unit->GetPositionX() == 706.592407f && unit->GetPositionY() == 343.425568f && unit->GetPositionZ() == 352.996124f)
				unit->GetAIInterface()->MoveTo(641.197449f, 314.330963f, 353.300262f, 3.659908f);
			if (unit->GetPositionX() == 706.593262f && unit->GetPositionY() == 310.011475f && unit->GetPositionZ() == 353.693848f)
				unit->GetAIInterface()->MoveTo(657.239807f, 256.925568f, 352.996094f, 2.506154f);
			if (unit->GetPositionX() == 706.751343f && unit->GetPositionY() == 298.312683f && unit->GetPositionZ() == 353.653809f)
				unit->GetAIInterface()->MoveTo(657.913330f, 353.562775f, 352.996185f, 3.436852f);

			WallCreating = true;
		}

		unit->CastSpell(unit, dbcSpell.LookupEntry(EYE_BLAST), true);
    }

protected:

	bool WallCreating;
};

/* Flame Crash Effect AI - Creature AI Class */

#define CN_FLAME_CRASH	23336

#define FLAME_CRASH_EFFECT	40836

class FlameCrashAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(FlameCrashAI);

    FlameCrashAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
		unit->CastSpell(unit, dbcSpell.LookupEntry(FLAME_CRASH_EFFECT), true);
		unit->GetAIInterface()->disable_melee = true;
		unit->GetAIInterface()->m_canMove = false;
		unit->m_noRespawn = true;
		unit->Despawn(120000, 0);
    }

    void OnCombatStop(Unit *mTarget)
    {
        unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        unit->GetAIInterface()->SetAIState(STATE_IDLE);
    }
};

/* Blaze Effect AI - Creature AI Class */

#define CN_BLAZE	23259

#define BLAZE_EFFECT	40610

class BlazeAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(BlazeAI);

    BlazeAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
		unit->CastSpell(unit, dbcSpell.LookupEntry(BLAZE_EFFECT), true);
		unit->GetAIInterface()->disable_melee = true;
		unit->GetAIInterface()->m_canMove = false;
		unit->m_noRespawn = true;
		unit->Despawn(60000, 0);
    }

	void OnCombatStop(Unit *mTarget)
    {
        unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        unit->GetAIInterface()->SetAIState(STATE_IDLE);
    }
};

/* Misc Creature AIs */

/* Flame of Azzinoth AI - Creature AI Class */

#define CN_FLAME_OF_AZZINOTH	22997	

#define BLAZE			40637		// this one just summons mob that will trigger that fire cloud - doesn't spawn mob
#define FLAME_BLAST		40631
#define FOA_ENRAGE		40683	// 40683 or 40743
#define CHAOS_CHARGE	40497 // CHAOS_CHARGE 40497 CHARGE 40602

class FlameOfAzzinothAI : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(FlameOfAzzinothAI);
	SP_AI_Spell spells[4];
	bool m_spellcheck[4];

    FlameOfAzzinothAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		nrspells = 2;
		for (int i = 0; i < nrspells; i++)
		{
			m_spellcheck[i] = false;
			spells[i].casttime = 0;
		}

		spells[0].info = dbcSpell.LookupEntry(BLAZE);
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = true;
		spells[0].cooldown = 30;
		spells[0].perctrigger = 7.0f;
		spells[0].attackstoptimer = 1000;

		spells[1].info = dbcSpell.LookupEntry(FLAME_BLAST);
		spells[1].targettype = TARGET_VARIOUS;
		spells[1].instant = true;
		spells[1].cooldown = 15;
		spells[1].perctrigger = 13.0f;
		spells[1].attackstoptimer = 1000;

		spells[2].info = dbcSpell.LookupEntry(CHAOS_CHARGE);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;

		spells[3].info = dbcSpell.LookupEntry(FOA_ENRAGE);
		spells[3].targettype = TARGET_SELF;
		spells[3].instant = true;

		unit->m_noRespawn = true;

		Enrage = false;
    }
    
    void OnCombatStart(Unit* mTarget)
    {
		for (int i = 0; i < nrspells; i++)
			spells[i].casttime = 0;

		RegisterAIUpdateEvent(unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
    }

    void OnCombatStop(Unit *mTarget)
    {
        unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        unit->GetAIInterface()->SetAIState(STATE_IDLE);
        RemoveAIUpdateEvent();
    }

    void OnDied(Unit * mKiller)
    {
       RemoveAIUpdateEvent();
    }

    void AIUpdate()
	{
		if (Enrage == true)
		{
			unit->CastSpell(unit, spells[3].info, spells[3].instant);

			Enrage = false;
			return;
		}

		if (unit->GetCurrentSpell() == NULL && unit->GetAIInterface()->GetNextTarget() != NULL)
		{
			Unit *target = NULL;
			target = unit->GetAIInterface()->GetNextTarget();

			if (unit->GetDistance2dSq(target) >= 225.0f && unit->GetDistance2dSq(target) <= 1225 && rand()%5 == 0)	// I must test this value (15-35yards for now)
			{
				unit->CastSpell(target, spells[2].info, spells[2].instant);

				Enrage = true;
				return;
			}
		}

		float val = (float)RandomFloat(100.0f);
		SpellCast(val);
    }

	void SpellCast(float val)
    {
        if(unit->GetCurrentSpell() == NULL && unit->GetAIInterface()->GetNextTarget())
        {
			float comulativeperc = 0;
		    Unit *target = NULL;
			for(int i=0;i<nrspells;i++)
			{
				if(!spells[i].perctrigger) continue;
				
				if(m_spellcheck[i])
				{
					target = unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
						case TARGET_SELF:
						case TARGET_VARIOUS:
							unit->CastSpell(unit, spells[i].info, spells[i].instant); break;
						case TARGET_ATTACKING:
							unit->CastSpell(target, spells[i].info, spells[i].instant); break;
						case TARGET_DESTINATION:
							unit->CastSpellAoF(target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(), spells[i].info, spells[i].instant); break;
					}

					m_spellcheck[i] = false;
					return;
				}

				uint32 t = (uint32)time(NULL);
				if(val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger) && t > spells[i].casttime)
				{
					unit->setAttackTimer(spells[i].attackstoptimer, false);
					spells[i].casttime = t + spells[i].cooldown;
					m_spellcheck[i] = true;
				}
				comulativeperc += spells[i].perctrigger;
			}
        }
    }

protected:

	int nrspells;
	bool Enrage;
};

/* Akama AI - Creature Gossip Class */
 
#define SendQuickMenu(textid) objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), textid, plr); \
    Menu->SendTo(plr);
 
class AkamaGossip : public GossipScript
{
public:
    void GossipHello(Object* pObject, Player* plr, bool AutoSend)
    {
        GossipMenu *Menu;
		Creature *Akama = (Creature*)(pObject);
		if (Akama == NULL)
			return;

		if (Akama->GetAIInterface()->getCurrentWaypoint() >= 10)
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 22992, plr);
			Menu->AddItem( 0, "We're ready to face Illidan.", 2);
		}

		else
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 22991, plr);
			Menu->AddItem( 0, "I'm ready, Akama.", 1);
		}
	 
		if(AutoSend)
			Menu->SendTo(plr);
    }
 
	void GossipSelectOption(Object* pObject, Player* plr, uint32 Id, uint32 IntId, const char * EnteredCode)
    {
		Creature *Akama = (Creature*)(pObject);
		if (Akama == NULL)
			return;

		switch (IntId)
		{
		case 0:
			GossipHello(pObject, plr, true);
			break;
		case 1:
			Akama->SetUInt32Value(UNIT_NPC_FLAGS, 0);

			Akama->GetAIInterface()->StopMovement(0);
			Akama->GetAIInterface()->SetAIState(STATE_SCRIPTMOVE);
			Akama->GetAIInterface()->setMoveType(MOVEMENTTYPE_WANTEDWP);
			Akama->GetAIInterface()->setWaypointToMove(1);
			break;
		case 2:
			Akama->SetUInt32Value(UNIT_NPC_FLAGS, 0);

			Akama->GetAIInterface()->StopMovement(0);
			Akama->GetAIInterface()->SetAIState(STATE_SCRIPTMOVE);
			Akama->GetAIInterface()->setMoveType(MOVEMENTTYPE_WANTEDWP);
			Akama->GetAIInterface()->setWaypointToMove(17);
			break;
		}
	}
 
    void Destroy()
    {
        delete this;
    }
};

/* Akama AI - Creature AI Class */

#define CN_AKAMA	22990

#define HEALING_POTION			40535
#define BLESSING_OF_KINGS		20217
#define AKAMA_DESPAWN			41242

// Door Event Spells
#define AKAMA_DOOR_FAIL			41271
#define AKAMA_DOOR_OPEN			41268
#define DEATHSWORN_DOOR_OPEN	41269
#define GATE_FAILURE			10390

static Coords ToIllidan[] = 
{
	{  },
	{ 660.248596f, 330.695679f, 271.688110f, 1.243284f },
	{ 671.172241f, 353.273193f, 271.689453f, 1.022600f },
	{ 694.227783f, 379.461365f, 271.792145f, 6.232135f },
	{ 724.159973f, 373.263275f, 282.614349f, 5.324218f },
	{ 747.034973f, 335.668274f, 307.047150f, 4.972365f },
	{ 755.477234f, 304.194580f, 312.167328f, 6.276120f },
	{ 771.809753f, 303.744873f, 313.563507f, 6.265894f },
	{ 778.550232f, 304.515198f, 318.818542f, 0.002354f },
	{ 789.564697f, 304.493652f, 319.759583f, 6.248631f },
	{ 799.598389f, 295.776642f, 319.760040f, 4.687257f },
	{ 799.054016f, 288.826660f, 320.030334f, 4.563174f },
	{ 794.595459f, 262.302856f, 341.463715f, 4.500343f },
	{ 794.396973f, 256.420471f, 341.463715f, 4.557680f },
	{ 783.355957f, 250.460892f, 341.463776f, 3.746361f },
	{ 764.988098f, 238.561462f, 353.646484f, 3.324606f },
	{ 749.337463f, 236.288681f, 352.997223f, 1.633631f },
	{ 751.941528f, 304.626221f, 352.996124f, 3.128243f },
	{ 747.236511f, 304.922913f, 352.996155f, 6.278462f },
	{ 747.834106f, 362.513977f, 352.996155f, 1.604554f }
};

class AkamaAI : public CreatureAIScript
{
public:
	friend class AkamaGossip;

    ADD_CREATURE_FACTORY_FUNCTION(AkamaAI);
	SP_AI_Spell spells[3];
	bool m_spellcheck[3];

    AkamaAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		for (int i = 1; i < 20; i++)
		{
			unit->GetAIInterface()->addWayPoint(CreateWaypoint(i, 0, RUN));
		}

		nrspells = 1;
		for (int i = 0; i < nrspells; i++)
		{
			m_spellcheck[i] = false;
			spells[i].casttime = 0;
		}

		spells[0].info = dbcSpell.LookupEntry(BLESSING_OF_KINGS);
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = true;
		spells[0].cooldown = 600;	// 10 min
		spells[0].perctrigger = 15.0f;
		spells[0].attackstoptimer = 1000;

		spells[1].info = dbcSpell.LookupEntry(HEALING_POTION);
		spells[1].targettype = TARGET_SELF;
		spells[1].instant = true;
		spells[1].cooldown = 0;
		spells[1].perctrigger = 0.0f;
		spells[1].attackstoptimer = 1000;

		spells[2].info = dbcSpell.LookupEntry(AKAMA_DESPAWN);
		spells[2].targettype = TARGET_SELF;
		spells[2].instant = false;
		spells[2].cooldown = 0;
		spells[2].perctrigger = 0.0f;
		spells[2].attackstoptimer = 1000;

		unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_9);
		unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_DONTMOVEWP);
		unit->GetAIInterface()->SetAllowedToEnterCombat(false);

		m_phase[unit->GetInstanceID()] = 0;
		EventChapter = 0;
		SoundLimiter = 0;
		EventTimer = 0;

		Udalo = Olum = NULL;

		if (!DeathEvent[unit->GetInstanceID()])
			unit->SetUInt32Value(UNIT_NPC_FLAGS, 1);
		else
		{
			unit->SetUInt32Value(UNIT_NPC_FLAGS, 0);
			RegisterAIUpdateEvent(1000);

			EventChapter = 2;
		}
	}
    
    void OnCombatStart(Unit* mTarget)
    {
		for (int i = 0; i < nrspells; i++)
			spells[i].casttime = 0;

		SoundLimiter = 0;

		unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);

		RegisterAIUpdateEvent(1000);
    }

    void OnCombatStop(Unit *mTarget)
    {
		if (m_phase[unit->GetInstanceID()] > 0)
			unit->GetAIInterface()->SetAllowedToEnterCombat(false);

		unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		unit->GetAIInterface()->SetAIState(STATE_IDLE);
		unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 0);

		//RemoveAIUpdateEvent();
    }

	void OnTargetDied(Unit* mTarget)
    {
		if (unit->GetHealthPct() > 0)
		{
			int RandomSpeach = rand()%2;
			switch (RandomSpeach)
			{
			case 0:
				unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Illidan will pay!");
				unit->PlaySoundToSet(11381);
				break;
			case 1:
				unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "One step closer!");
				unit->PlaySoundToSet(11382);
				break;
			}
		}
    }

	void OnDied(Unit * mKiller)
    {
		unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Fight on friends! Kill him and end the curse on my people!");	// not sure
		unit->PlaySoundToSet(11391);

		RemoveAIUpdateEvent();

		EventTimer = 0;
    }

	void AIUpdate()
	{
		switch (EventChapter)
		{
		case 0:
			WayToIllidan();
			break;
		case 1:
			FightWithIllidan();
			break;
		case 2:
			EncounterEnd();
			break;
		}
	}

	void WayToIllidan()
	{
		if (unit->GetAIInterface()->getCurrentWaypoint() == 6 && EventTimer > 0)
		{
			GameObject* Gate = unit->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords(774.7f, 304.6f, 314.85f, 185905);
			Unit* DoorTrigger = unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(771.5f, 304.7f, 319.0f, CN_DOOR_EVENT_TRIGGER);
			if (Gate == NULL)
			{
				unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "It's strange that Illidan doesn't protect himself against intruders." );
				unit->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
				unit->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);

				unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_WANTEDWP);
				unit->GetAIInterface()->setWaypointToMove(7);

				if (Udalo != NULL)
				{
					Udalo->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
					Udalo->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);

					Udalo = NULL;
				}
				if (Olum != NULL)
				{
					Olum->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
					Olum->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);

					Olum = NULL;
				}

				RemoveAIUpdateEvent();

				EventTimer = 0;
				return;
			}

			switch (EventTimer)
			{
			case 2:
				unit->SetFacing(6.248631f);
				break;
			case 6:
				unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "The door is all that stands between us and the Betrayer. Stand aside, friends." );
				unit->Emote(EMOTE_ONESHOT_TALK);
				break;
			case 10:		// here will be first try to break door (Akama himself only)
				if (DoorTrigger != NULL)
				{
					unit->CastSpell(DoorTrigger, dbcSpell.LookupEntry(AKAMA_DOOR_FAIL), false);
					unit->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, DoorTrigger->GetGUID());
					unit->SetUInt32Value(UNIT_CHANNEL_SPELL, AKAMA_DOOR_FAIL);
				}
				break;
			case 19:		// here we will stop casting spell on door
				unit->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
				unit->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);
				break;
			case 20:
				unit->Emote(EMOTE_ONESHOT_NO);
				unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "I cannot do this alone..." );
				break;
			case 26:		// summoning two spirits to help Akama with breaking doors
				Udalo = unit->GetMapMgr()->GetInterface()->SpawnCreature(23410, 751.884705f, 311.270050f, 312.121185f, 0.047113f, true, false, 0, 0);
				Olum  = unit->GetMapMgr()->GetInterface()->SpawnCreature(23411, 751.687744f, 297.408600f, 312.124817f, 0.054958f, true, false, 0, 0);
				if (Udalo != NULL)
				{
					Udalo->GetAIInterface()->SetAllowedToEnterCombat(false);
					Udalo->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_9);

					Udalo->m_noRespawn = true;
					Udalo->Despawn(45000, 0);
				}
				if (Olum != NULL)
				{
					Olum->GetAIInterface()->SetAllowedToEnterCombat(false);
					Olum->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_9);

					Olum->m_noRespawn = true;
					Olum->Despawn(45000, 0);
				}
				break;
			case 27:
				if (Udalo != NULL)
					Udalo->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "You are not alone, Akama." );
				break;
			case 33:
				if (Olum != NULL)
					Olum->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Your people will always be with you." );
				break;
			case 38:			// Akama starts casting his spell again with both spirits
				if (DoorTrigger != NULL)
				{
					unit->CastSpell(DoorTrigger, dbcSpell.LookupEntry(AKAMA_DOOR_OPEN), false);
					unit->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, DoorTrigger->GetGUID());
					unit->SetUInt32Value(UNIT_CHANNEL_SPELL, AKAMA_DOOR_OPEN);
				}
				break;
			case 39:
				if (DoorTrigger != NULL)
				{
					if (Udalo != NULL)
					{
						Udalo->CastSpell(DoorTrigger, dbcSpell.LookupEntry(DEATHSWORN_DOOR_OPEN), false);
						Udalo->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, DoorTrigger->GetGUID());
						Udalo->SetUInt32Value(UNIT_CHANNEL_SPELL, DEATHSWORN_DOOR_OPEN);
					}
					if (Olum != NULL)
					{
						Olum->CastSpell(DoorTrigger, dbcSpell.LookupEntry(DEATHSWORN_DOOR_OPEN), false);
						Olum->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, DoorTrigger->GetGUID());
						Olum->SetUInt32Value(UNIT_CHANNEL_SPELL, DEATHSWORN_DOOR_OPEN);
					}
				}
				break;
			case 48:			// Door has been broken and channel stopped
				Gate->SetUInt32Value(GAMEOBJECT_STATE, 0);
				if (DoorTrigger != NULL)
				{
					DoorTrigger->CastSpell(unit, dbcSpell.LookupEntry(GATE_FAILURE), true);
				}
				break;
			case 49:
				unit->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
				unit->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);

				if (Udalo != NULL)
				{
					Udalo->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
					Udalo->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);
				}
				if (Olum != NULL)
				{
					Olum->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
					Olum->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);
				}
				break;
			case 52:
				unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "I thank you for your aid, my brothers. Our people will be redeemed!" );
				unit->Emote(EMOTE_ONESHOT_SALUTE);
				break;
			case 55:
				if (Udalo != NULL)
					Udalo->Emote(EMOTE_ONESHOT_SALUTE);
				if (Olum != NULL)
					Olum->Emote(EMOTE_ONESHOT_SALUTE);

				Udalo = NULL;
				Olum = NULL;
				break;
			case 58:
				unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_WANTEDWP);
				unit->GetAIInterface()->setWaypointToMove(7);
				RemoveAIUpdateEvent();
				break;
			}

			EventTimer++;
			if (EventTimer > 58)
				EventTimer = 0;
		}

		if (EventTimer > 0 && unit->GetAIInterface()->getCurrentWaypoint() == 16)
		{
			EventTimer++;
			switch (EventTimer)
			{
			case 2:
				unit->PlaySoundToSet(11388);
				unit->SetFacing(2.113512f);
				break;
			case 17:
				unit->SetUInt32Value(UNIT_NPC_FLAGS, 1);
				RemoveAIUpdateEvent();

				EventTimer = 0;
				break;
			}
		}

		if (EventTimer > 0 && unit->GetAIInterface()->getCurrentWaypoint() == 17 && m_phase[unit->GetInstanceID()] == 0)
		{
			Illidan = unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(704.539001f, 305.282013f, 353.919006f, 22917);
			if (Illidan == NULL || !Illidan->isAlive())
			{
				RemoveAIUpdateEvent();

				unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Not this time my friends." );
				unit->CastSpell(unit, spells[2].info, spells[2].instant);
				unit->Despawn(0,0);

				EventTimer = 0;
				return;
			}

			switch(EventTimer)
			{
			case 1:
				unit->SetFacing(3.126680f);
				break;
			case 2:
				Illidan->RemoveAura(39656);
				break;
			case 3:
		        Illidan->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Akama... your duplicity is hardly surprising. I should have slaughtered you and your malformed brethren long ago.");
				Illidan->PlaySoundToSet(11463);
				break;
			case 7:
				Illidan->Emote(EMOTE_ONESHOT_QUESTION);
				break;
			case 12:
				Illidan->Emote(EMOTE_ONESHOT_QUESTION);
				break;
			case 15:
		        unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "We've come to end your reign, Illidan. My people and all of Outland shall be free!");
				unit->PlaySoundToSet(11389);

				unit->Emote(EMOTE_ONESHOT_POINT);
			    break;
			case 18:
				unit->Emote(EMOTE_ONESHOT_TALK);
				break;
			case 22:
				unit->Emote(EMOTE_ONESHOT_SALUTE);
				break;
			case 25:
		        Illidan->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Boldly said. But I remain unconvinced.");
				Illidan->PlaySoundToSet(11464);

				Illidan->Emote(EMOTE_ONESHOT_QUESTION);
			    break;
			case 28:
				Illidan->Emote(EMOTE_ONESHOT_QUESTION);
				break;
			case 32:
		        unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "The time has come! The moment is at hand!");
				unit->PlaySoundToSet(11380);

				unit->Emote(EMOTE_ONESHOT_SHOUT);
				break;
			case 34:
				unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);
				unit->Emote(EMOTE_ONESHOT_ROAR);
				break;
			case 36:
				Illidan->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "You are not prepared!");
				Illidan->PlaySoundToSet(11466);

				unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_READY1H);

				Illidan->Emote(EMOTE_ONESHOT_CUSTOMSPELL05);
				break;
			case 38:
				Illidan->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);
				break;
			case 40:
				GameObject* RightGate = unit->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords(745.07f, 241.802f, 354.292f, 200000);
				GameObject* LeftGate  = unit->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords(744.829f, 369.276f, 354.324f, 200001);
				if (RightGate != NULL)
					RightGate->SetUInt32Value(GAMEOBJECT_STATE, 1);
				if (LeftGate != NULL)
					LeftGate->SetUInt32Value(GAMEOBJECT_STATE, 1);
				
				unit->GetAIInterface()->SetAllowedToEnterCombat(true);
				unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
				unit->GetAIInterface()->SetAIState(STATE_IDLE);
				unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
				unit->GetAIInterface()->m_canMove = true;

				unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_DONTMOVEWP);
				unit->GetAIInterface()->setWaypointToMove(0);

				Illidan->GetAIInterface()->SetAllowedToEnterCombat(true);
				Illidan->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
				Illidan->GetAIInterface()->m_canMove = true;

				RemoveAIUpdateEvent();

				unit->GetAIInterface()->AttackReaction(Illidan, 1, 0);

				Unit *IllidanTarget = NULL;
				IllidanTarget = FindTarget();
				if (IllidanTarget == NULL)
				{
					IllidanTarget = unit;
				}

				Illidan->GetAIInterface()->AttackReaction(IllidanTarget, 500, 0);

				EventChapter = 1;
				break;
			}

			EventTimer++;
			if (EventTimer > 40)
				EventTimer = 0;
		}
	}

	void FightWithIllidan()
	{
		SoundLimiter++;
		if (unit->GetHealthPct() <= 15 && unit->GetAIInterface()->GetNextTarget() != NULL)
		{
			if (SoundLimiter >= 15)
			{
				int RandomSpeach = rand()%2;
				switch (RandomSpeach)
				{
				case 0:
					unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "I will not last much longer!");
					unit->PlaySoundToSet(11385);
					break;
				case 1:
					unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "No! Not yet!");
					unit->PlaySoundToSet(11386);
					break;
				}

				SoundLimiter = 0;
			}

			if (unit->GetAIInterface()->GetNextTarget()->GetTypeId() == TYPEIDunit)
			{
				Creature *Target = NULL;
				Target = (Creature*)unit->GetAIInterface()->GetNextTarget();
				if (Target != NULL && Target->GetEntry() == 22917)
					unit->CastSpell(unit, spells[1].info, spells[1].instant);
			}
		}

		if ((unit->GetAIInterface()->GetNextTarget() != NULL || EventTimer > 7) && unit->GetAIInterface()->getCurrentWaypoint() < 18 && m_phase[unit->GetInstanceID()] != 0)
		{
			if (unit->GetAIInterface()->GetAllowedToEnterCombat() == true && EventTimer < 7)	// && Illidan && Illidan->GetHealthPct() > 85)
			{
				unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_READY1H);

				float val = (float)RandomFloat(100.0f);
				SpellCast(val);
			}

			if ((Illidan == NULL || !Illidan->isAlive()) && EventTimer <= 7)
			{
				unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Not this time my friends.");
				unit->CastSpell(unit, spells[2].info, spells[2].instant);
				unit->Despawn(0,0);
			}

			if ((Illidan != NULL && Illidan->isAlive() && Illidan->GetHealthPct() <= 85 && EventTimer <= 7) || EventTimer > 7)
			{
				switch (EventTimer)
				{
				case 0:
					Illidan->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Come, my minions. Deal with this traitor as he deserves!");
					Illidan->PlaySoundToSet(11465);
					break;
				case 7:
					unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_9);
					unit->GetAIInterface()->SetAIState(STATE_IDLE);
					unit->GetAIInterface()->SetNextTarget((Unit*)NULL);
					unit->GetAIInterface()->WipeTargetList();
					unit->GetAIInterface()->WipeHateList();

					unit->GetAIInterface()->disable_melee = true;
					unit->GetAIInterface()->m_canMove = false;

					Illidan->GetAIInterface()->RemoveThreatByPtr(unit);	// Akama will stuck in place anyway if alone in combat with Illidan
					break;
				case 8:
					unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "I will deal with these mongrels! Strike now, friends! Strike at the Betrayer!");
					unit->PlaySoundToSet(11390);

					unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
					break;
				case 9:
					unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_READY1H);
					break;
				case 10:
					unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
					break;
				case 11:
					unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 0);
					unit->Emote(EMOTE_ONESHOT_EXCLAMATION);
					break;
				case 13:
					unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_READY1H);
					unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);
					break;
				case 15:
					unit->GetAIInterface()->SetAllowedToEnterCombat(false);
					unit->GetAIInterface()->m_canMove = true;

					unit->GetAIInterface()->StopMovement(0);
					unit->GetAIInterface()->SetAIState(STATE_SCRIPTMOVE);
					unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_WANTEDWP);
					unit->GetAIInterface()->setWaypointToMove(18);

					RemoveAIUpdateEvent();

					//unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
					break;
				}
				
				EventTimer++;
				if (EventTimer > 15)
					EventTimer = 0;
			}
		}
	}

	void EncounterEnd()
	{
		if (m_phase[unit->GetInstanceID()] == 0 && DeathEvent[unit->GetInstanceID()] >= 40)
		{	
			if (DeathEvent[unit->GetInstanceID()] <= 41)
			{
				Unit *Maiev = NULL;
				for (int i = 0; i < 5; i++)
				{
					Maiev = unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(SearchPos[i].mX, SearchPos[i].mY, SearchPos[i].mZ, 23197);
					if (Maiev != NULL && Maiev->isAlive())
					{
						MposX = Maiev->GetPositionX();
						MposY = Maiev->GetPositionY();
						MposZ = Maiev->GetPositionZ();
						MposO = Maiev->GetOrientation();

						break;
					}
				}
				// Akama is despawned if he can't find Maiev anywhere (better than going to position x = 0.0f y = 0.0f and z = 0.0f (cells too small)
				if (Maiev == NULL)
				{
					unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Not this time my friends.");
					unit->CastSpell(unit, spells[2].info, spells[2].instant);
					unit->Despawn(0,0);
				}
			}

			if (unit->GetPositionX() == MposX && unit->GetPositionY() == MposY && unit->GetPositionZ() == MposZ && DeathEvent[unit->GetInstanceID()] < 44)
				DeathEvent[unit->GetInstanceID()] = 44;

			if (DeathEvent[unit->GetInstanceID()] == 42)
			{
				unit->GetAIInterface()->m_moveRun = true;
				unit->GetAIInterface()->MoveTo(MposX, MposY, MposZ, MposO);
				unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);

				RemoveAIUpdateEvent();
				RegisterAIUpdateEvent(1000);

				DeathEvent[unit->GetInstanceID()] = 43;

				//unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_READY1H);	// dunno why this emote sometimes bugs facing
				//unit->GetAIInterface()->SetNextTarget(Illidan);
			}

			if (DeathEvent[unit->GetInstanceID()] >= 45)
			{
				switch (DeathEvent[unit->GetInstanceID()])
				{
				case 45:
					unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "The Light will fill these dismal halls once again. I swear it.");
					unit->PlaySoundToSet(11387);

					Illidan = NULL;
					Illidan = unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(unit->GetPositionX(), unit->GetPositionY(), unit->GetPositionZ(), 22917);
					if (Illidan != NULL)
						unit->GetAIInterface()->SetNextTarget(Illidan);

					unit->Emote(EMOTE_ONESHOT_TALK);
					break;
				case 49:
					unit->Emote(EMOTE_ONESHOT_SALUTE);
					break;
				case 53:
					DeathEvent[unit->GetInstanceID()] = 0;

					unit->CastSpell(unit, spells[2].info, spells[2].instant);
					unit->Despawn(0,0);
					break;
				}
			}

			if (DeathEvent[unit->GetInstanceID()] >= 44)
				DeathEvent[unit->GetInstanceID()]++;
		}
	}

	void SpellCast(float val)
    {
        if(unit->GetCurrentSpell() == NULL && unit->GetAIInterface()->GetNextTarget())
        {
			float comulativeperc = 0;
		    Unit *target = NULL;
			for(int i=0;i<nrspells;i++)
			{
				if(!spells[i].perctrigger) continue;
				
				if(m_spellcheck[i])
				{
					target = unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
						case TARGET_SELF:
						case TARGET_VARIOUS:
							unit->CastSpell(unit, spells[i].info, spells[i].instant); break;
						case TARGET_ATTACKING:
							unit->CastSpell(target, spells[i].info, spells[i].instant); break;
						case TARGET_DESTINATION:
							unit->CastSpellAoF(target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(), spells[i].info, spells[i].instant); break;
					}
					m_spellcheck[i] = false;
					return;
				}

				uint32 t = (uint32)time(NULL);
				if(val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger) && t > spells[i].casttime)
				{
					unit->setAttackTimer(spells[i].attackstoptimer, false);
					spells[i].casttime = t + spells[i].cooldown;
					m_spellcheck[i] = true;
				}
				comulativeperc += spells[i].perctrigger;
			}
        }
    }

    void OnReachWP(uint32 iWaypointId, bool bForwards)
    {
		switch (iWaypointId)
		{
		case 6:
		case 16:
		case 17:
			RegisterAIUpdateEvent(1000);
			EventTimer = 1;
			break;
		case 19:
			unit->Despawn(0, 0);
			break;
		case 20:
			DeathEvent[unit->GetInstanceID()] = 49;
			break;
		default:
			{
				unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_WANTEDWP);
				unit->GetAIInterface()->setWaypointToMove(iWaypointId+1);
			}
		}
    }

    inline WayPoint* CreateWaypoint(int id, uint32 waittime, uint32 flags)
    {
        WayPoint * wp = unit->CreateWaypointStruct();
        wp->id = id;
        wp->x = ToIllidan[id].mX;
        wp->y = ToIllidan[id].mY;
        wp->z = ToIllidan[id].mZ;
        wp->o = ToIllidan[id].mO;
        wp->waittime = waittime;
        wp->flags = flags;
        wp->forwardemoteoneshot = 0;
        wp->forwardemoteid = 0;
        wp->backwardemoteoneshot = 0;
        wp->backwardemoteid = 0;
        wp->forwardskinid = 0;
        wp->backwardskinid = 0;
        return wp;
    }

	// A bit rewritten FindTarget function
	Unit* FindTarget()
	{
		Unit* target = NULL;
		float distance = 70.0f;
		float z_diff;

		Unit *pUnit;
		float dist;

		for (std::set<Player*>::iterator itr = unit->GetInRangePlayerSetBegin(); itr != unit->GetInRangePlayerSetEnd(); itr++)
		{
			pUnit = static_cast<Unit*>((*itr));

			if(pUnit->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_FEIGN_DEATH))
				continue;

			z_diff = fabs(unit->GetPositionZ() - pUnit->GetPositionZ());
			if(z_diff > 5.0f)
				continue;

			if(pUnit->m_invisible)
				continue;

			if(!pUnit->isAlive())
				continue;

			dist = Illidan->GetDistance2dSq(pUnit);

			if(dist > distance*distance)
				continue;

			distance = dist;
			target = pUnit;
		}

		return target;
	}

protected:

	float MposX, MposY, MposZ, MposO;
	uint32 SoundLimiter;
	uint32 EventChapter;
	uint32 EventTimer;
	Creature *Udalo;
	Creature *Olum;
	Unit *Illidan;
	int nrspells;
};

/* Maiev AI - Creature AI Class */

#define CN_MAIEV 23197

//#define TELEPORT_MAIEV 41221
#define TELEPORT 34673	// 34673, 41992

class MaievAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(MaievAI);
	SP_AI_Spell spells[1];

    MaievAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		spells[0].info = dbcSpell.LookupEntry(TELEPORT);
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = true;
		spells[0].cooldown = 0;
		spells[0].perctrigger = 0.0f;
		spells[0].attackstoptimer = 0;

		unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
		unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_DONTMOVEWP);
		unit->GetAIInterface()->SetAllowedToEnterCombat(false);

		SoundTimer = 0;

		RegisterAIUpdateEvent(250);
    }
    
    void OnCombatStart(Unit* mTarget)
    {
		//RegisterAIUpdateEvent(unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
		//unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);
    }

    void OnCombatStop(Unit *mTarget)
    {
        //unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        //unit->GetAIInterface()->SetAIState(STATE_IDLE);

		//unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 0);
        //RemoveAIUpdateEvent();
    }

    void OnDied(Unit * mKiller)
    {
       RemoveAIUpdateEvent();

	   SoundTimer = 0;
    }

	void OnDamageTaken(Unit *mAttacker, float fAmount)
	{
		unit->SetUInt32Value(UNIT_FIELD_HEALTH, unit->GetUInt32Value(UNIT_FIELD_MAXHEALTH));
	}

    void AIUpdate()
    {
		unit->SetUInt32Value(UNIT_FIELD_HEALTH, unit->GetUInt32Value(UNIT_FIELD_MAXHEALTH));

		Unit *Illidan = unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(unit->GetPositionX(), unit->GetPositionY(), unit->GetPositionZ(), 22917);

		if (DeathEvent[unit->GetInstanceID()] == 0)
		{
			if (unit->GetAIInterface()->GetNextTarget() != NULL && unit->GetAIInterface()->m_canMove == true)
				SoundTimer++;

			float SayNaisha = (float)RandomFloat(100.0f);
			if ((SayNaisha < 2.5f && SoundTimer >= 100 && SoundTimer < 1330) || SoundTimer == 1361 || SoundTimer > 1400)
			{
				uint32 RandText;
				if (SoundTimer != 1361)
					RandText = rand()%3;
				if (SoundTimer == 1361)
					RandText = rand()%2;
				switch (RandText)	// Not sure if those both should be here, but couldn't find any relation when those are said on blizz
				{
					case 0:
						unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Bleed as I have bled!");	// not sure
						unit->PlaySoundToSet(11494);

						SoundTimer = 0;
						break;
					case 1:
						unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "That is for Naisha!");
						unit->PlaySoundToSet(11493);

						SoundTimer = 0;
						break;
					case 2:
						if (Illidan != NULL)
						{
							Illidan->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Feel the hatred of ten thousand years!");
							Illidan->PlaySoundToSet(11470);

							SoundTimer = 1337;
					}break;
				}
			}
		}

		if (DeathEvent[unit->GetInstanceID()] > 0)
		{
			if ((DeathEvent[unit->GetInstanceID()] <= 25 && Illidan != NULL) || (DeathEvent[unit->GetInstanceID()] > 25))
			{
				switch (DeathEvent[unit->GetInstanceID()])
				{
				case 1:
					unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Ah, it is finished. You are beaten.");	// not sure
					unit->PlaySoundToSet(11496);

					Illidan->Emote(EMOTE_ONESHOT_CUSTOMSPELL06);
					if(Illidan->GetCurrentSpell() != NULL)
						Illidan->GetCurrentSpell()->cancel();

					RemoveAIUpdateEvent();
					RegisterAIUpdateEvent(1000);
					break;
				case 2:
					Illidan->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_CUSTOMSPELL07);

					unit->GetAIInterface()->SetNextTarget(Illidan);
					break;
				case 5:
					Illidan->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "You have won... Maiev. But the huntress... is nothing without the hunt. You... are nothing... without me.");
					Illidan->PlaySoundToSet(11478);

					unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
					unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 0);
					//MaievWeaponOff();
					break;
				case 25:{
					GameObject* RightGate = unit->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords(745.07f, 241.802f, 354.292f, 200000);
					GameObject* LeftGate  = unit->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords(744.829f, 369.276f, 354.324f, 200001);
					if (RightGate != NULL)
						RightGate->SetUInt32Value(GAMEOBJECT_STATE, 0);
					if (LeftGate != NULL)
						LeftGate->SetUInt32Value(GAMEOBJECT_STATE, 0);

					Illidan->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
					Illidan->SetUInt32Value(UNIT_FIELD_HEALTH,0);
					Illidan->setDeathState(JUST_DIED);
					}break;
				case 30:
					unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "He's right. I feel nothing. I am nothing.");
					unit->PlaySoundToSet(11497);
					break;
				case 39:
					unit->GetMapMgr()->GetInterface()->SpawnCreature(CN_AKAMA, ToIllidan[19].mX, ToIllidan[19].mY, ToIllidan[19].mZ, ToIllidan[19].mO, true, false, 0, 0);	// we have one Akama already spawned so we don't need another one =/ (still it's freakin' workaround -.-')
					unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Farewell, champions.");
					unit->PlaySoundToSet(11498);
					break;
				case 40:
					unit->CastSpell(unit, dbcSpell.LookupEntry(TELEPORT), true);
					break;
				case 41:
					RemoveAIUpdateEvent();

					unit->Despawn(0,0);
					break;
				}

				if (DeathEvent[unit->GetInstanceID()] <= 41)
					DeathEvent[unit->GetInstanceID()]++;
			}

			else
			{
				unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Farewell, champions.");
				unit->PlaySoundToSet(11498);
				unit->Despawn(0,0);
			}
		}
    }

protected:

	uint32 SoundTimer;
};

/* Illidan Stormrage AI - Creature AI Class */

#define CN_ILLIDAN_STORMRAGE 22917

// Normal Form Spells
#define SHEAR								41032  // +
#define DRAW_SOUL							40904  // +
#define FLAME_CRASH							40832  // +
#define MORTAL_STRIKE						37335  // +

// Demon Forms
#define DEMON_FORM1							40511  // +
#define DEMON_FORM2							40398  // +
#define DEMON_FORM3							40510  // +

// Demon Form Spells
#define SHADOW_BLAST						41078  // +
#define SUMMON_DEMON						41117  // - Core Support
#define FLAME_BURST							41131  // ? Haven't Tried	// 41126 is the right one, but it's spell that needs to be scripted

// Illidan's Glaive spells
#define SUMMON_GLAIVE						41466
#define GLAIVE_RETURNS						39873
#define THROW_GLAIVE1						39635
#define THROW_GLAIVE2						39849

// Phase 2 Spells
#define DEMON_FORM							40506
#define AURA_OF_DREAD						41142
#define FIREBALL							40598  // +
#define DARK_BARRAGE						40585  // ? Haven't Tried
#define SUMMON_TEAR_OF_AZZINOTH				39855  // +

#define EYE_BLAST1							39908
#define EYE_BLAST2							40017

#define TEAR_OF_AZZINOTH_CHANNEL			39857

// Phase 3 Spells
#define AGONIZING_FLAMES					40932  // ? Haven't Tried (Before Demon Form!)

// Phase 4 Spells

// Phase 5 Spells
#define ENRAGE								34971  // +

// Other spells
#define SHADOW_PRISON						40647  // +
#define SKULL_INTRO							39656  // + Works with RemoveAura
#define SUMMON_PARASITIC_SHADOWFIENDS		41915  // ? Haven't Tried
#define PARASITIC_SHADOWFIEND1				41914  // ? Haven't Tried
#define PARASITIC_SHADOWFIEND2				41913  // ? Haven't Tried

// Other macros
#define CN_BLADE_OF_AZZINOTH				22996

static Coords ForIllidan[] = 
{
	{  },
	{ 709.783203f, 305.073883f, 362.988770f, 1.546307f },	// Middle pos
	{ 678.703735f, 337.249664f, 362.988770f, 4.741172f },	// Eastern pos
	{ 679.968384f, 284.618011f, 362.988770f, 1.603503f },	// Western pos
	{ 680.798157f, 305.648743f, 353.192200f, 3.196716f }	// Land
};

static Coords UnitPos[]=
{
	{ 676.717346f, 322.445251f, 354.153320f, 5.732623f },	// Blade 1
	{ 677.368286f, 285.374725f, 354.242157f, 5.645614f }	// Blade 2
};

class IllidanStormrageAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(IllidanStormrageAI);
	SP_AI_Spell spells[15];
	bool m_spellcheck[15];

    IllidanStormrageAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		unit->GetAIInterface()->addWayPoint(CreateWaypoint(1, 0, FLY));
		unit->GetAIInterface()->addWayPoint(CreateWaypoint(2, 0, FLY));
		unit->GetAIInterface()->addWayPoint(CreateWaypoint(3, 0, FLY));
		unit->GetAIInterface()->addWayPoint(CreateWaypoint(4, 0, FLY));

		nrspells = 5;
		for (int i = 0 ; i < nrspells; i++)
		{
			m_spellcheck[i] = false;
			spells[i].casttime = 0;
		}

        spells[0].info = dbcSpell.LookupEntry(SHEAR);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = false;
		spells[0].cooldown = 15;
		spells[0].perctrigger = 12.0f;
		spells[0].attackstoptimer = 1000;

        spells[1].info = dbcSpell.LookupEntry(DRAW_SOUL);
		spells[1].targettype = TARGET_VARIOUS;
		spells[1].instant = false;
		spells[1].cooldown = 0;
		spells[1].perctrigger = 0.0f;	// 6.0f	attacks himself too so it can cause crashes if he dies because of his own hit
		spells[1].attackstoptimer = 1000;

        spells[2].info = dbcSpell.LookupEntry(FLAME_CRASH);
		spells[2].targettype = TARGET_DESTINATION;
		spells[2].instant = false;
		spells[2].cooldown = 25;
		spells[2].perctrigger = 12.0f;
		spells[2].attackstoptimer = 1000;

        spells[3].info = dbcSpell.LookupEntry(MORTAL_STRIKE);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 20;
		spells[3].perctrigger = 8.0f;
		spells[3].attackstoptimer = 1000;

		spells[4].info = dbcSpell.LookupEntry(AGONIZING_FLAMES);
		spells[4].targettype = TARGET_RANDOM_DESTINATION;
		spells[4].instant = true;
		spells[4].cooldown = 25;
		spells[4].perctrigger = 7.0f;
		spells[4].attackstoptimer = 1000;
		spells[4].mindist2cast = 0.0f;
		spells[4].maxdist2cast = 30.0f;
		spells[4].minhp2cast = 0;
		spells[4].maxhp2cast = 100;

        spells[5].info = dbcSpell.LookupEntry(ENRAGE);
		spells[5].targettype = TARGET_SELF;
		spells[5].instant = true;
		spells[5].cooldown = 0;
		spells[5].perctrigger = 0.0f;
		spells[5].attackstoptimer = 1000;
		spells[5].speech = "You've wasted too much time mortals, now you shall fall!";
		spells[5].soundid = 11474;

        spells[6].info = dbcSpell.LookupEntry(SHADOW_BLAST);
		spells[6].targettype = TARGET_DESTINATION;
		spells[6].instant = false;
		spells[6].cooldown = 0;
		spells[6].perctrigger = 0.0f;
		spells[6].attackstoptimer = 1000;

        spells[7].info = dbcSpell.LookupEntry(SUMMON_DEMON);
		spells[7].targettype = TARGET_SELF;	// ?
		spells[7].instant = false;
		spells[7].cooldown = 0;
		spells[7].perctrigger = 0.0f;
		spells[7].attackstoptimer = 1000;

        spells[8].info = dbcSpell.LookupEntry(SHADOW_PRISON);
		spells[8].targettype = TARGET_VARIOUS;
		spells[8].instant = true;
		spells[8].cooldown = 0;
		spells[8].perctrigger = 0.0f;
		spells[8].attackstoptimer = 1000;

		/* Spells after this point are not counted when using the SpellCast() 
		   funct in AI and need to be manually triggered! :-D */
		spells[9].info = dbcSpell.LookupEntry(DEMON_FORM1);
		spells[9].instant = true;
		spells[9].cooldown = 0;
		spells[9].perctrigger = 0.0f;
		spells[9].attackstoptimer = 1000;

		spells[10].info = dbcSpell.LookupEntry(DEMON_FORM2);
		spells[10].instant = true;
		spells[10].cooldown = 0;
		spells[10].perctrigger = 0.0f;

		spells[11].info = dbcSpell.LookupEntry(DEMON_FORM3);
		spells[11].instant = true;
		spells[11].cooldown = 0;
		spells[11].perctrigger = 0.0f;

		spells[12].info = dbcSpell.LookupEntry(FIREBALL);
		spells[12].targettype = TARGET_RANDOM_DESTINATION;
		spells[12].instant = false;
		spells[12].cooldown = 0;
		spells[12].perctrigger = 0.0f;

		spells[13].info = dbcSpell.LookupEntry(DARK_BARRAGE);
		spells[13].targettype = TARGET_RANDOM_SINGLE;
		spells[13].instant = false;
		spells[13].cooldown = 0;
		spells[13].perctrigger = 0.0f;
		spells[13].cooldown = 44;

		spells[14].info = dbcSpell.LookupEntry(EYE_BLAST1);
		spells[14].instant = false;
		spells[14].cooldown = 0;
		spells[14].perctrigger = 0.0f;

		/* Setup Illidan */
		unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_9);
		unit->CastSpell(unit, dbcSpell.LookupEntry(SKULL_INTRO), true);
		unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_DONTMOVEWP);
		unit->GetAIInterface()->SetAllowedToEnterCombat(false);
		unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
		unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 0);
		unit->GetAIInterface()->m_canMove = false;

		/* Initialize variables and stuff, I Guess */
		FoA1 = FoA2 = Maiev = NULL;
		DeathEvent[unit->GetInstanceID()] = 0;
		m_phase[unit->GetInstanceID()] = 0;	// must be 0 to use it with some other stuff.
		DemonSoundRand = false;
		DemonPhaseTimer = 0;
		BladesEvent = 0;
		MaievDialog = 0;
		DemonPhase = 0;
    }

    void OnCombatStart(Unit* mTarget)
    {
		RegisterAIUpdateEvent(unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
		unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_READY1H);
		unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);
		unit->GetAIInterface()->m_canMove = true;

		DeathEvent[unit->GetInstanceID()] = 0;
		m_phase[unit->GetInstanceID()] = 1;
		DemonPhaseTimer = 0;
		DemonPhase = 0;

		for (int i = 0; i < nrspells; i++)
			spells[i].casttime = 0;
		spells[13].casttime = 0;
    }

	void OnTargetDied(Unit* mTarget)
    {
		if (unit->GetHealthPct() > 0)
		{
			int RandomSpeach = rand()%2;
			switch (RandomSpeach)
			{
			case 0:
				unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Who shall be next to taste my blades?!");
				unit->PlaySoundToSet(11473);
				break;
			case 1:
				unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "This is too easy!");
				unit->PlaySoundToSet(11472);
				break;
			}
		}
    }

    void OnCombatStop(Unit *mTarget)
    {
		std::vector<Creature*> DespawnTable;	/* From M4ksiu - Big THX to Capt who learned me how to use std stuff <3	*/
												/* If anyone wants to use this function, then leave this note!			*/
		for(set<Object*>::iterator itr = unit->GetInRangeSetBegin(); itr != unit->GetInRangeSetEnd(); ++itr) 
		{ 
			if ((*itr)->GetTypeId()== TYPEIDunit && (*itr)->GetInstanceID() == unit->GetInstanceID() && (*itr) != unit)
			{
				Creature *CreatureToAdd = NULL;
				CreatureToAdd = (Creature*)(*itr);

				if (CreatureToAdd && CreatureToAdd->GetSQL_id() == 0 && (CreatureToAdd->GetEntry() == CN_FLAME_OF_AZZINOTH || 
					CreatureToAdd->GetEntry() == CN_BLADE_OF_AZZINOTH || (unit->isAlive() && CreatureToAdd->GetEntry() == CN_MAIEV)))
				{
					DespawnTable.push_back(CreatureToAdd);
				} 
			} 
		}

		for (uint32 i = 0; i < DespawnTable.size(); i++)
		{
			Creature *CreatureToDespawn = DespawnTable[i];

			if (CreatureToDespawn)
				CreatureToDespawn->Despawn(0,0);
		}

		DespawnTable.clear();

		unit->GetAIInterface()->SetAllowedToEnterCombat(true);
		unit->GetAIInterface()->disable_melee = false;
		unit->GetAIInterface()->m_moveFly = false;
		unit->GetAIInterface()->m_canMove = true;

		RemoveAIUpdateEvent();

		unit->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
		unit->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);
		unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
		unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
		unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);
		if (unit->FindAura(DEMON_FORM))
			unit->RemoveAura(DEMON_FORM);
		unit->SetFloatValue(OBJECT_FIELD_SCALE_X , 1.0f);

		unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        unit->GetAIInterface()->SetAIState(STATE_IDLE);

		DemonSoundRand = false;
		DemonPhaseTimer = 0;
		BladesEvent = 0;
		DemonPhase = 0;

		if (m_phase[unit->GetInstanceID()] == 2)
		{
			unit->Emote(EMOTE_ONESHOT_LAND);

			WorldPacket data(SMSG_MOVE_UNSET_HOVER, 13);
			data << unit->GetNewGUID();
			data << uint32(0);
			unit->SendMessageToSet(&data, false);

			float x = unit->m_spawn->x;
			float y = unit->m_spawn->y;
			float z = unit->m_spawn->z;
			float o = unit->m_spawn->o;
			
			unit->GetAIInterface()->MoveTo(x, y, z, o);
		}

		if (unit->isAlive())
			m_phase[unit->GetInstanceID()] = 1;
		else
			m_phase[unit->GetInstanceID()] = 0;

		FoA1 = FoA2 = NULL;
    }

    void OnDied(Unit * mKiller)
    {
		RemoveAIUpdateEvent();

		if (MaievDialog >= 28 && Maiev != NULL && Maiev->isAlive())	// it's workaround (added pointer check, coz if he dies when Maiev is not on battlefield then it will crash server)
		{
			unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_9);
			unit->GetAIInterface()->SetAllowedToEnterCombat(false);
			unit->SetUInt32Value(UNIT_FIELD_HEALTH, 1);
			if(unit->GetCurrentSpell() != NULL)
			    unit->GetCurrentSpell()->cancel();

			Maiev->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_9);
			Maiev->GetAIInterface()->SetAIState(STATE_IDLE);
			Maiev->WipeTargetList();
			Maiev->WipeHateList();

			DeathEvent[unit->GetInstanceID()] = 1;
			Maiev = NULL;
		}
		else
		{
			GameObject* RightGate = unit->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords(745.07f, 241.802f, 354.292f, 200000);
			GameObject* LeftGate  = unit->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords(744.829f, 369.276f, 354.324f, 200001);
			if (RightGate != NULL)
				RightGate->SetUInt32Value(GAMEOBJECT_STATE, 0);
			if (LeftGate != NULL)
				LeftGate->SetUInt32Value(GAMEOBJECT_STATE, 0);
		}
    }

	void AIUpdate()
	{
		if (DemonPhase > 0 && DemonPhase < 75)	// 0;9
		{
			DemonTrans();
		}
		else if (DemonPhase > 75 && DemonPhase < 134)	// 9;17
		{
			TransRevert();
		}
		else
		{
			if (m_phase[unit->GetInstanceID()] == 1)	// First Phase (without demon form)
			{
				PhaseOne();
			}
			if (m_phase[unit->GetInstanceID()] == 2)	// Second Phase (Fly phase)
			{
				PhaseTwo();
			}
			if (m_phase[unit->GetInstanceID()] == 3)	// Third Phase normal form with ability to change into Demon
			{
				PhaseThree();
			}
			if (m_phase[unit->GetInstanceID()] == 4)	// Fourth Phase Demon Form
			{
				PhaseFour();
			}
			if (m_phase[unit->GetInstanceID()] == 5)	// Fifth Phase with ability to change into Demon and Enrage
			{
				PhaseFive();
			}
		}
	}

	void PhaseOne()
	{
		if (unit->GetHealthPct() <= 65 && unit->GetCurrentSpell() == NULL)
		{
			unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "I will not be touched by a rebels such as you!");	// not sure
			unit->PlaySoundToSet(11479);

			unit->GetAIInterface()->MoveTo(unit->GetPositionX(), unit->GetPositionY(), unit->GetPositionZ() + 10.0f, unit->GetOrientation());
			unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_9);
			unit->GetAIInterface()->SetAllowedToEnterCombat(false);
			unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
			unit->GetAIInterface()->disable_melee = true;
			unit->GetAIInterface()->m_moveFly = true;
			unit->Emote(EMOTE_ONESHOT_LIFTOFF);

			WorldPacket data(SMSG_MOVE_SET_HOVER, 13);
            data << unit->GetNewGUID();
            data << uint32(0);
            unit->SendMessageToSet(&data, false);

			RemoveAIUpdateEvent();
			RegisterAIUpdateEvent(500);

			m_phase[unit->GetInstanceID()] = 2;
			CastCount = 5 + RandomUInt(2);
			TriggerSpawned = false;
			FireWallTimer = 0;
			LastFireWall = 0;
			BladesEvent = 1;
		}
		else
		{
			unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_READY1H);	// in OnCombatStart or in Dialog part it doesn't work (in places I wanted to add it)
			float val = (float)RandomFloat(100.0f);
			SpellCast(val);
		}
	}

	void FoASummon()	// little hacky way to spawn them by pushing into world, but proper spell won't work now
	{					// we can eventually add them as pointers and trigger some events from here (like Blade's channeling)
		FoA1 = unit->GetMapMgr()->GetInterface()->SpawnCreature(CN_FLAME_OF_AZZINOTH, 672.039246f, 326.748322f, 354.206390f, 0.207343f, true, false, 0, 0);
		FoA2 = unit->GetMapMgr()->GetInterface()->SpawnCreature(CN_FLAME_OF_AZZINOTH, 673.008667f, 283.813660f, 354.267548f, 6.203853f, true, false, 0, 0);
		if (FoA1 != NULL)
		{
			Unit *Blade = unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(UnitPos[0].mX, UnitPos[0].mY, UnitPos[0].mZ, CN_BLADE_OF_AZZINOTH);
			if (Blade != NULL)
			{
				Blade->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, FoA1->GetGUID());
				Blade->SetUInt32Value(UNIT_CHANNEL_SPELL, TEAR_OF_AZZINOTH_CHANNEL);
			}
		}
		if (FoA2 != NULL)
		{
			Unit *Blade = unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(UnitPos[1].mX, UnitPos[1].mY, UnitPos[1].mZ, CN_BLADE_OF_AZZINOTH);
			if (Blade != NULL)
			{
				Blade->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, FoA2->GetGUID());
				Blade->SetUInt32Value(UNIT_CHANNEL_SPELL, TEAR_OF_AZZINOTH_CHANNEL);
			}
		}
	}

	void PhaseTwo()
	{
		if ((BladesEvent && BladesEvent < 20) || (BladesEvent > 24 && BladesEvent < 45))
		{
			switch (BladesEvent)
			{
			case 2:
				unit->GetAIInterface()->StopMovement(0);
				unit->GetAIInterface()->SetAIState(STATE_SCRIPTMOVE);
				unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_WANTEDWP);
				unit->GetAIInterface()->setWaypointToMove(1);
				break;
			case 10:	// Blade1 fly
				unit->CastSpell(unit, dbcSpell.LookupEntry(THROW_GLAIVE2), false);
				unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Behold the flames of Azzinoth!");
				unit->PlaySoundToSet(11480);
				break;
			case 12:
				for (int i = 0; i < 2; i++)
				{
					unit->CastSpellAoF(UnitPos[i].mX, UnitPos[i].mY, UnitPos[i].mZ, dbcSpell.LookupEntry(THROW_GLAIVE1), false);
				}
				unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 0);
				break;
			case 14:		// Blades spawn
				for (int i = 0; i < 2; i++)
				{
					Creature *Blade = unit->GetMapMgr()->GetInterface()->SpawnCreature(CN_BLADE_OF_AZZINOTH, UnitPos[i].mX, UnitPos[i].mY, UnitPos[i].mZ, UnitPos[i].mO, false, false, 0, 0);
					if (Blade != NULL)
					{
						Blade->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
						Blade->GetAIInterface()->SetAllowedToEnterCombat(false);
						Blade->m_noRespawn = true;
					}
				}
				break;
			case 18:		// Flames of Azzinoth Spawn + channeling
				FoASummon();
				RemoveAIUpdateEvent();
				RegisterAIUpdateEvent(1000);
				unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);

				CastCount = 5 + RandomUInt(2);
				TriggerSpawned = false;
				FireWallTimer = 0;
				break;
			case 29:
				for (int i = 0 ; i < 2; i++)
				{
					Creature *Blade = unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(UnitPos[i].mX, UnitPos[i].mY, UnitPos[i].mZ, CN_BLADE_OF_AZZINOTH);
					if (Blade != NULL)
					{
						Blade->Despawn(0,0);
					}
				}
				break;
			case 30:		// Blades return
				unit->CastSpell(unit, dbcSpell.LookupEntry(GLAIVE_RETURNS), false);
				unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);	// he should also make something like jump emote when weapons are in his hands, but I can't find right one o_O
				break;
			case 34:{
				unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_READY1H);	
				unit->GetAIInterface()->m_moveFly = false;
				unit->Emote(EMOTE_ONESHOT_LAND);

				WorldPacket data(SMSG_MOVE_UNSET_HOVER, 13);
				data << unit->GetNewGUID();
				data << uint32(0);
				unit->SendMessageToSet(&data, false);
				}break;
			case 40:	//36
				unit->GetAIInterface()->SetAllowedToEnterCombat(true);
				unit->GetAIInterface()->disable_melee = false;
				unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
				unit->GetAIInterface()->m_canMove = true;
				unit->GetAIInterface()->ClearHateList();

				RemoveAIUpdateEvent();
				RegisterAIUpdateEvent(unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));

				DemonPhaseTimer = (uint32)time(NULL) + 60;
				m_phase[unit->GetInstanceID()] = 3;
				TriggerSpawned = false;
				FireWallTimer = 0;
				MaievDialog = 0;
				break;
			}

			if (BladesEvent != 3)
				BladesEvent++;
		}
		else
		{
			uint32 FoADeaths = 2;
			if ((FoA1 != NULL && !FoA1->isAlive()) || FoA1 == NULL)
			{
				Unit *Blade = unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(UnitPos[0].mX, UnitPos[0].mY, UnitPos[0].mZ, CN_BLADE_OF_AZZINOTH);
				if (Blade != NULL)
				{
					Blade->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
					Blade->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);
				}
				FoADeaths--;
				FoA1 = NULL;
			}
			if ((FoA2 != NULL && !FoA2->isAlive()) || FoA2 == NULL)
			{
				Unit *Blade = unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(UnitPos[1].mX, UnitPos[1].mY, UnitPos[1].mZ, CN_BLADE_OF_AZZINOTH);
				if (Blade != NULL)
				{
					Blade->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
					Blade->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);
				}
				FoADeaths--;
				FoA2 = NULL;
			}

			FireWallTimer++;
			if (unit->GetAIInterface()->getMoveType() != MOVEMENTTYPE_WANTEDWP && unit->GetCurrentSpell() == NULL)
			{
				if (unit->GetUInt32Value(UNIT_CHANNEL_SPELL) == 0)
				{
					if (FoADeaths == 0)
					{
						unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_9);
						unit->GetAIInterface()->SetAllowedToEnterCombat(false);
						unit->GetAIInterface()->m_canMove = true;
						if(unit->GetCurrentSpell() != NULL)
							unit->GetCurrentSpell()->cancel();

						unit->GetAIInterface()->StopMovement(0);
						unit->GetAIInterface()->SetAIState(STATE_SCRIPTMOVE);
						unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_WANTEDWP);
						unit->GetAIInterface()->setWaypointToMove(4);

						return;
					}
					if (CastCount <= 0)
					{
						if (RandomUInt(2) == 1)	// Move right
						{
							CurrentWP++;
							if (CurrentWP > 3)
								CurrentWP = 1;
						}
						else					// Move left
						{
							CurrentWP--;
							if (CurrentWP < 1)
								CurrentWP = 3;
						}

						unit->GetAIInterface()->StopMovement(0);
						unit->GetAIInterface()->SetAIState(STATE_SCRIPTMOVE);
						unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_WANTEDWP);
						unit->GetAIInterface()->setWaypointToMove(CurrentWP);

						return;
					}
				}
				if (unit->GetAIInterface()->getCurrentWaypoint() != 4)
				{
					if (FireWallTimer >= 30)
					{
						if (TriggerSpawned == false)
						{
							float posX;
							float posY;
							float posZ;

							uint32 RandomWall = rand()%8+1;
							while ((RandomWall == LastFireWall) || (RandomWall == LastFireWall - 4) || (RandomWall == LastFireWall + 4))
							{
								RandomWall = rand()%8+1;
							}

							switch (RandomWall)
							{
							case 1:
								posX = 642.240601f;
								posY = 297.297180f;
								posZ = 353.423401f;
								break;
							case 2:
								posX = 641.197449f;
								posY = 314.330963f;
								posZ = 353.300262f;
								break;
							case 3:
								posX = 657.239807f;
								posY = 256.925568f;
								posZ = 352.996094f;
								break;
							case 4:
								posX = 657.913330f;
								posY = 353.562775f;
								posZ = 352.996185f;
								break;
							case 5:
								posX = 707.019043f;
								posY = 270.441772f;
								posZ = 352.996063f;
								break;
							case 6:
								posX = 706.592407f;
								posY = 343.425568f;
								posZ = 352.996124f;
								break;
							case 7:
								posX = 706.593262f;
								posY = 310.011475f;
								posZ = 353.693848f;
								break;
							case 8:
								posX = 706.751343f;
								posY = 298.312683f;
								posZ = 353.653809f;
								break;
							}

							Unit *Trigger = NULL;
							Trigger = unit->GetMapMgr()->GetInterface()->SpawnCreature(CN_EYE_BEAM_TRIGGER, posX, posY, posZ, 0.0f, false, false, 0, 0);
							if (Trigger != NULL)
							{
								if (unit->GetCurrentSpell() != NULL)
									unit->GetCurrentSpell()->cancel();

								unit->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, Trigger->GetGUID());
								unit->SetUInt32Value(UNIT_CHANNEL_SPELL, EYE_BLAST1);
								unit->CastSpell(Trigger, spells[14].info, true);

								unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Stare into the eyes of the Betrayer!");	// must check this
								unit->PlaySoundToSet(11481);

								LastFireWall = RandomWall;
								TriggerSpawned = true;
								FireWallTimer = 30;
							}
							else
							{
								FireWallTimer = 0;
								LastFireWall = 0;
							}
						}
						if (TriggerSpawned == true && FireWallTimer >= 42)
						{
							unit->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
							unit->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);
							unit->RemoveAura(EYE_BLAST1);

							TriggerSpawned = false;
							FireWallTimer = 0;
						}
					}
					else if (unit->GetAIInterface()->GetNextTarget())
					{
						Unit* target = NULL;
						target = unit->GetAIInterface()->GetNextTarget();

						uint32 t = (uint32)time(NULL);
						uint32 Spell = RandomUInt(100);
						if (Spell >= 0 && Spell <= 25)
						{
							CastSpellOnRandomTarget(12, 0.0f, 60.0f, 0, 100);
							CastCount--;
						}
						if (Spell > 25 && Spell <= 35 && t > spells[13].casttime)
						{
							CastSpellOnRandomTarget(13, 0.0f, 60.0f, 0, 100);

							spells[13].casttime = t + spells[13].cooldown;
							CastCount--;
						}
					}
				}
			}
		}
	 }

	void PhaseThree()
	{
		if (unit->GetHealthPct() <= 30 && MaievDialog == 0 && (DemonPhase <= 0 || DemonPhase >= 135 && unit->GetCurrentSpell() == NULL))
		{
			#ifdef USE_SHADOW_PRISON
				unit->GetAIInterface()->StopMovement(1);
				unit->CastSpell(unit, spells[8].info, spells[8].instant);
			#endif

			unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_9);
			unit->GetAIInterface()->SetAllowedToEnterCombat(false);
			unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
			unit->GetAIInterface()->disable_melee = true;
			unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
			unit->GetAIInterface()->m_canMove = false;
			if(unit->GetCurrentSpell() != NULL)		// keeping it for now, will delete it later anyway
				unit->GetCurrentSpell()->cancel();

			RemoveAIUpdateEvent();
			RegisterAIUpdateEvent(1000);

			MaievDialog = 1;
		}
		if (MaievDialog > 0 && MaievDialog < 32 && (DemonPhase <= 0 || DemonPhase >= 135))
		{
			switch (MaievDialog)
			{
			case 3:		// 3
				unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Is this it, mortals? Is this all the fury you can muster?");
				unit->PlaySoundToSet(11476);
				break;
			case 6:		// 6
				unit->Emote(EMOTE_ONESHOT_QUESTION);
				break;
			case 9:
				SpawnMaiev();
				break;
			case 10:
				Maiev->CastSpell(unit, dbcSpell.LookupEntry(TELEPORT), true);

				unit->GetAIInterface()->SetNextTarget(Maiev);
				break;
			case 11:	// 12
				Maiev->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Their fury pales before mine, Illidan. We have some unsettled business between us.");
				Maiev->PlaySoundToSet(11491);
				break;
			case 12:	// 13
				MaievWeaponOff();
				break;
			case 13:	// 14
				Maiev->Emote(EMOTE_ONESHOT_EXCLAMATION);
				break;
			case 18:	// 20
				unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Maiev... How is it even possible?");
				unit->PlaySoundToSet(11477);
				break;
			case 21:	// 23
					//unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_READY1H);
				break;
			case 24:	// 27
				Maiev->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Ah, my long hunt is finally over. Today, Justice will be done!");
				Maiev->PlaySoundToSet(11492);

				Maiev->Emote(EMOTE_ONESHOT_EXCLAMATION);
				break;
			case 27:	// 30
				Maiev->Emote(EMOTE_ONESHOT_YES);
				break;
			case 28:	// 31
				Maiev->Emote(EMOTE_ONESHOT_ROAR);
				break;
			case 31:	//34
				unit->GetAIInterface()->SetAllowedToEnterCombat(true);
				unit->GetAIInterface()->disable_melee = false;
				unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
				unit->GetAIInterface()->m_canMove = true;

				if (Maiev != NULL && Maiev->isAlive())
				{
					Maiev->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_READY1H);
					Maiev->GetAIInterface()->SetAllowedToEnterCombat(true);
					Maiev->GetAIInterface()->setCurrentAgent(AGENT_NULL);
					Maiev->GetAIInterface()->SetAIState(STATE_IDLE);
					Maiev->GetAIInterface()->m_canMove = true;

					Maiev->GetAIInterface()->AttackReaction(unit, 1, 0);

					MaievWeaponOn();
				}
					
				RemoveAIUpdateEvent();
				RegisterAIUpdateEvent(unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));

				DemonPhaseTimer = (uint32)time(NULL) + 60;	
				m_phase[unit->GetInstanceID()] = 5;
				EnrageTimer = 10;
				break;
			}

			MaievDialog++;
		}
		else
		{
			uint32 t = (uint32)time(NULL);
			if (t > DemonPhaseTimer)
			{
				unit->GetAIInterface()->setCurrentAgent(AGENT_SPELL);
				unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
				if(unit->GetCurrentSpell() != NULL)
					unit->GetCurrentSpell()->cancel();
				
				RemoveAIUpdateEvent();
				RegisterAIUpdateEvent(250);

				DemonPhase = 1;
			}
			else
			{
				if (DemonPhase < 1 || DemonPhase > 134)
				{
					unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_READY1H);
					float val = (float)RandomFloat(100.0f);
					SpellCast(val);
				}
			}
		}
	}

	void DemonTrans()	// check and change how long spell 9 is in use on official
	{
		if(unit->GetCurrentSpell() != NULL)
			unit->GetCurrentSpell()->cancel();

		switch (DemonPhase)
		{	// let's give it 4 free triggers to not use melee attacks and spells
		case 5:
			unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 403);
			unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 0);
			break;
		case 13:
			unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Behold the power... of the demon within!");
			unit->PlaySoundToSet(11475);

			unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 404);
			break;
		case 33:
			unit->CastSpell(unit, DEMON_FORM, true);
			unit->SetFloatValue(OBJECT_FIELD_SCALE_X , 1.0f);
			break;
		case 43:
			unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 405);
			break;
		case 53:{
			unit->GetAIInterface()->ClearHateList();

			Unit *NewTarget = NULL;
			NewTarget = FindTarget();
			if (NewTarget != NULL)
				unit->GetAIInterface()->modThreatByPtr(NewTarget, 200);
		}break;
		case 61:	//63	//65	// he should also drop aggro and take new target (warlock should take it by dots casted before final change)
			unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);

			RemoveAIUpdateEvent();
			RegisterAIUpdateEvent(unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
			PhaseFour();

			DemonPhaseTimer = (uint32)time(NULL) + 30;
			m_phase[unit->GetInstanceID()] = 4;
			DemonSoundRand = false;
			DemonPhase = 74;
			break;
		}

		DemonPhase++;
	}

	void TransRevert()	// same here to spell 9 (but not that much I think); also I am thinking about changing spells on emotes
	{
		if(unit->GetCurrentSpell() != NULL)
			unit->GetCurrentSpell()->cancel();

		switch (DemonPhase)
		{
		case 81:	// 1 diff is too long?
			unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 403);
			break;
		case 84:	//85
			unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 404);
			break;
		case 108:	//108	//109
			if (unit->FindAura(DEMON_FORM))
				unit->RemoveAura(DEMON_FORM);
			unit->SetFloatValue(OBJECT_FIELD_SCALE_X , 1.0f);

			unit->GetAIInterface()->ClearHateList();
			break;
		case 114:	//116	//117
			unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 405);
			break;
		case 118:
			unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);
			break;
		case 126:
			unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
			unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);

			if (MaievDialog == 0)
				m_phase[unit->GetInstanceID()] = 3;
			else
			{
				EnrageTimer = rand()%10+11;
				m_phase[unit->GetInstanceID()] = 5;
			}

			RemoveAIUpdateEvent();
			RegisterAIUpdateEvent(unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));

			DemonPhaseTimer = (uint32)time(NULL) + 60;
			DemonPhase = 135;
			break;
		}

		DemonPhase++;
	}

	void PhaseFour()
	{
		uint32 t = (uint32)time(NULL);
		if (t > DemonPhaseTimer || (unit->GetHealthPct() <= 30 && MaievDialog == 0))
		{
			unit->GetAIInterface()->setCurrentAgent(AGENT_SPELL);

			RemoveAIUpdateEvent();
			RegisterAIUpdateEvent(250);

			DemonSoundRand = false;
			DemonPhase = 76;
		}
		if (t <= DemonPhaseTimer - 26 && MaievDialog > 0 && !DemonSoundRand)
		{
			int Sound = rand()%3;	// 66% chance to say something, should work fine
			switch (Sound)
			{
			case 0:
				unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "You know nothing of power!");
				unit->PlaySoundToSet(11469);

				DemonSoundRand = true;
				break;
			case 1:
				unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Such arrogance!");
				unit->PlaySoundToSet(11471);

				DemonSoundRand = true;
				break;
			}
		}
		else
		{
			if (unit->GetAIInterface()->GetNextTarget() != NULL && DemonPhase == 75 && unit->GetCurrentSpell() == NULL)
			{
				Unit *target = NULL;
				target = unit->GetAIInterface()->GetNextTarget();

				if (unit->GetDistance2dSq(target) >= 0.0f && unit->GetDistance2dSq(target) <= 4900.0f)
				{
					unit->GetAIInterface()->setCurrentAgent(AGENT_SPELL);
					unit->GetAIInterface()->StopMovement(1);

					int Spell = rand()%100;
					if (Spell >= 0 && Spell <= 80)
						unit->CastSpellAoF(target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(), spells[6].info, spells[6].instant);
					if (Spell > 80 && Spell <= 90) return;
						//unit->CastSpell(unit, spells[7].info, spells[7].instant);	// disabled for now as it can cause some unneeded animations			// both should have unit as target
					if (Spell > 90 && Spell <= 100)
						unit->CastSpell(unit, spells[1].info, spells[1].instant);	// this one needs to be scripted
				}
				else
				{
					unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
				}
			}
		}
	}

	void PhaseFive()
	{
		EnrageTimer--;
		uint32 t = (uint32)time(NULL);
		if (t > DemonPhaseTimer)
		{
			unit->GetAIInterface()->setCurrentAgent(AGENT_SPELL);
			unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
			if(unit->GetCurrentSpell() != NULL)
				unit->GetCurrentSpell()->cancel();

			RemoveAIUpdateEvent();
			RegisterAIUpdateEvent(250);
			
			DemonPhase = 1;
		}
		if (!EnrageTimer)
		{
			unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "You've wasted too much time mortals, now you shall fall!");
			unit->PlaySoundToSet(11474);

			unit->CastSpell(unit, spells[5].info, spells[5].instant);

			return;
		}
		else
		{
			if (DemonPhase < 1 || DemonPhase > 134)
			{
				unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_READY1H);

				float val = (float)RandomFloat(100.0f);
				SpellCast(val);
			}
		}
	}

	void SpellCast(float val)
    {
        if(unit->GetCurrentSpell() == NULL && unit->GetAIInterface()->GetNextTarget())
        {
			float comulativeperc = 0;
		    Unit *target = NULL;
			for(int i=0;i<nrspells;i++)
			{
				if(!spells[i].perctrigger) continue;
				
				if(m_spellcheck[i])
				{
					target = unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
						case TARGET_SELF:
						case TARGET_VARIOUS:
							unit->CastSpell(unit, spells[i].info, spells[i].instant); break;
						case TARGET_ATTACKING:
							unit->CastSpell(target, spells[i].info, spells[i].instant); break;
						case TARGET_DESTINATION:
							unit->CastSpellAoF(target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(), spells[i].info, spells[i].instant); break;
						case TARGET_RANDOM_FRIEND:
						case TARGET_RANDOM_SINGLE:
						case TARGET_RANDOM_DESTINATION:
							CastSpellOnRandomTarget(i, spells[i].mindist2cast, spells[i].maxdist2cast, spells[i].minhp2cast, spells[i].maxhp2cast); break;
					}
					m_spellcheck[i] = false;
					return;
				}

				uint32 t = (uint32)time(NULL);
				if(val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger) && t > spells[i].casttime)
				{
					if ((i == 4 && m_phase[unit->GetInstanceID()] == 3) || i != 4)
					{
						unit->setAttackTimer(spells[i].attackstoptimer, false);
						spells[i].casttime = t + spells[i].cooldown;
						m_spellcheck[i] = true;
					}
				}
				comulativeperc += spells[i].perctrigger;
			}
        }
    }

	void CastSpellOnRandomTarget(uint32 i, float mindist2cast, float maxdist2cast, int minhp2cast, int maxhp2cast)
	{
		if (!maxdist2cast) maxdist2cast = 100.0f;
		if (!maxhp2cast) maxhp2cast = 100;

		if(unit->GetCurrentSpell() == NULL && unit->GetAIInterface()->GetNextTarget())
        {
			std::vector<Unit*> TargetTable;		/* From M4ksiu - Big THX to Capt who helped me with std stuff to make it simple and fully working <3 */
												/* If anyone wants to use this function, then leave this note!										 */
			for(set<Object*>::iterator itr = unit->GetInRangeSetBegin(); itr != unit->GetInRangeSetEnd(); ++itr) 
			{ 
				if (((spells[i].targettype == TARGET_RANDOM_FRIEND && isFriendly(unit, (*itr))) || (spells[i].targettype != TARGET_RANDOM_FRIEND && isHostile(unit, (*itr)) && (*itr) != unit)) && ((*itr)->GetTypeId()== TYPEIDunit || (*itr)->GetTypeId() == TYPEID_PLAYER) && (*itr)->GetInstanceID() == unit->GetInstanceID()) // isAttackable(unit, (*itr)) && 
				{
					Unit* RandomTarget = NULL;
					RandomTarget = (Unit*)(*itr);

					if (RandomTarget->isAlive() && unit->GetDistance2dSq(RandomTarget) >= mindist2cast*mindist2cast && unit->GetDistance2dSq(RandomTarget) <= maxdist2cast*maxdist2cast && ((RandomTarget->GetHealthPct() >= minhp2cast && RandomTarget->GetHealthPct() <= maxhp2cast && spells[i].targettype == TARGET_RANDOM_FRIEND) || (unit->GetAIInterface()->getThreatByPtr(RandomTarget) > 0 && isHostile(unit, RandomTarget))))
					{
						TargetTable.push_back(RandomTarget);
					} 
				} 
			}

			if (unit->GetHealthPct() >= minhp2cast && unit->GetHealthPct() <= maxhp2cast && spells[i].targettype == TARGET_RANDOM_FRIEND)
				TargetTable.push_back(unit);

			if (!TargetTable.size())
				return;

			size_t RandTarget = rand()%TargetTable.size();

			Unit * RTarget = TargetTable[RandTarget];

			if (!RTarget)
				return;

			switch (spells[i].targettype)
			{
			case TARGET_RANDOM_FRIEND:
			case TARGET_RANDOM_SINGLE:
				unit->CastSpell(RTarget, spells[i].info, spells[i].instant); break;
			case TARGET_RANDOM_DESTINATION:
				unit->CastSpellAoF(RTarget->GetPositionX(), RTarget->GetPositionY(), RTarget->GetPositionZ(), spells[i].info, spells[i].instant); break;
			}

			TargetTable.clear();
		}
	}

	void SpawnMaiev()	// this doesn't have collision checks! so keep in mind that Maiev can be spawned behind walls!
	{
		float xchange  = (float)RandomFloat(15.0f);
		float distance = 15.0f;

		float ychange = sqrt(distance*distance - xchange*xchange);

		if (rand()%2 == 1)
			xchange *= -1;
		if (rand()%2 == 1)
			ychange *= -1;

		float newposx = unit->GetPositionX() + xchange;
		float newposy = unit->GetPositionY() + ychange;

		Maiev = unit->GetMapMgr()->GetInterface()->SpawnCreature(CN_MAIEV, newposx, newposy, unit->GetPositionZ() + 0.5f, 2.177125f, true, false, 0, 0);
		if (Maiev == NULL)
		{
			RemoveAIUpdateEvent();
			RegisterAIUpdateEvent(20000);

			MaievDialog = 30;
		}
		else
		{
			Maiev->GetAIInterface()->SetNextTarget(unit);
		}
	}

	void MaievWeaponOff()
	{
		/*Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY, 0);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY_01, 44850);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO, 0);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO_01, 0);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO_02, 218169346);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO_03, 4);
		Maiev->SetUInt32Value(UNIT_FIELD_BYTES_2, 0);*/
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY, 0);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY_01, 44850);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO, 0);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO_01, 0);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO_02, 33488898);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO_03, 781);
		Maiev->SetUInt32Value(UNIT_FIELD_BYTES_2, 0);
	}

	void MaievWeaponOn()
	{
		/*Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY, 44850);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY_01, 0);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO, 218169346);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO_01, 4);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO_02, 0);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO_03, 0);
		Maiev->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);*/	
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY, 44850);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY_01, 0);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO, 33488898);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO_01, 781);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO_02, 0);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO_03, 0);
		Maiev->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);
	}

	void OnReachWP(uint32 iWaypointId, bool bForwards)
    {
		CurrentWP = iWaypointId;
		switch(iWaypointId)
		{
		case 1:
			unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
			unit->GetAIInterface()->SetAIState(STATE_SCRIPTIDLE);
			unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_DONTMOVEWP);
			unit->GetAIInterface()->setWaypointToMove(0);

			if (BladesEvent < 4)
			{
				unit->GetAIInterface()->ClearHateList();

				RemoveAIUpdateEvent();
				RegisterAIUpdateEvent(500);
				BladesEvent = 4;
			}

			CastCount = 5 + RandomUInt(2);
			break;
		case 2:
		case 3:
			unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
			unit->GetAIInterface()->SetAIState(STATE_SCRIPTIDLE);
			unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_DONTMOVEWP);
			unit->GetAIInterface()->setWaypointToMove(0);

			CastCount = 5 + RandomUInt(2);
			break;
		case 4:
			unit->GetAIInterface()->m_canMove = false;

			unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
			unit->GetAIInterface()->SetAIState(STATE_SCRIPTIDLE);
			unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_DONTMOVEWP);
			unit->GetAIInterface()->setWaypointToMove(0);

			RemoveAIUpdateEvent();
			RegisterAIUpdateEvent(500);

			BladesEvent = 25;
			break;
		}
    }

	Unit *FindTarget()
	{
		std::vector<Unit*> TargetTable;		/* From M4ksiu - Big THX to Capt who helped me with std stuff to make it simple and fully working <3 */
											/* If anyone wants to use this function, then leave this note!										 */
		for(set<Object*>::iterator itr = unit->GetInRangeSetBegin(); itr != unit->GetInRangeSetEnd(); ++itr) 
		{ 
			if (isHostile(unit, (*itr)) && (*itr)->GetTypeId() == TYPEID_PLAYER && (*itr)->GetInstanceID() == unit->GetInstanceID())
			{
				Unit* RandomTarget = NULL;
				RandomTarget = (Unit*)(*itr);
				if (RandomTarget->isAlive() && unit->GetDistance2dSq(RandomTarget) <= 10000.0f && unit->GetDistance2dSq(RandomTarget) >= 0.0f && unit->GetAIInterface()->getThreatByPtr(RandomTarget) > 0)
				{
					TargetTable.push_back(RandomTarget);
				} 
			} 
		}

		if (!TargetTable.size())
			return NULL;

		size_t RandTarget = rand()%TargetTable.size();
		Unit * RTarget = TargetTable[RandTarget];

		if (!RTarget)
			return NULL;

		TargetTable.clear();

		return RTarget;
	}

    inline WayPoint* CreateWaypoint(int id, uint32 waittime, uint32 flags)
    {
        WayPoint * wp = unit->CreateWaypointStruct();
        wp->id = id;
        wp->x = ForIllidan[id].mX;
        wp->y = ForIllidan[id].mY;
        wp->z = ForIllidan[id].mZ;
        wp->o = ForIllidan[id].mO;
        wp->waittime = waittime;
        wp->flags = flags;
        wp->forwardemoteoneshot = 0;
        wp->forwardemoteid = 0;
        wp->backwardemoteoneshot = 0;
        wp->backwardemoteid = 0;
        wp->forwardskinid = 0;
        wp->backwardskinid = 0;
        return wp;
    }

protected:

	uint32 DemonPhaseTimer;
	uint32 FireWallTimer;
	bool DemonSoundRand;
	uint32 LastFireWall;
	bool TriggerSpawned;
	uint32 BladesEvent;
	uint32 MaievDialog;
	uint32 CurrentWP;
	int EnrageTimer;
	int DemonPhase;
	int CastCount;
	int nrspells;
	Unit* Maiev;
	Unit* FoA1;
	Unit* FoA2;
};