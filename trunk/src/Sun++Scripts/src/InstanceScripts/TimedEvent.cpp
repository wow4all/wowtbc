#include "StdAfx.h"
#include "Setup.h"
#include "zadefines.h"
#include "Base.h"

class TIMEDEVENT : public MoonScriptCreatureAI
{
public:
    MOONSCRIPT_FACTORY_FUNCTION(TIMEDEVENT, MoonScriptCreatureAI);
    TIMEDEVENT(Creature* pCreature) : MoonScriptCreatureAI(pCreature)
    {
		m_EventTimer				= INVALIDATE_TIMER;
		m_MinuteTimer				= INVALIDATE_TIMER;
		m_TimerSet					= false;
		m_d							= 0;
		m_Opened					= false;
		m_spawnedAkilzonChest		= false;
		m_spawneddNalorakkChest		= false;
		m_spawnedJanalaiChest		= false;
		m_spawnedHalazziChest		= false;
		m_EventEnd					= false;
	}

	void StartEvent()
	{
		//zapneme timery a world state
		m_EventTimer	= AddTimer(1200000);
		m_MinuteTimer	= AddTimer(60000);
		m_TimerSet		= true;

		//world state
		GetUnit()->GetMapMgr()->GetWorldStateManager()->SetWorldState(WORLDSTATE_ZULAMAN_TIMEDEVENT_DISPLAY, 1);
		GetUnit()->GetMapMgr()->GetWorldStateManager()->SetWorldState(WORLDSTATE_ZULAMAN_TIMEDEVENT_TIME, 20);

		//aiupdate timer
		RegisterAIUpdateEvent(1000);
	}

	void AIUpdate()
	{
		if(!GetUnit()->IsInWorld())
			return;

		//kazdou minutu posleme novy cas
		if(IsTimerFinished(m_MinuteTimer) && !m_EventEnd)
		{
			ResetTimer(m_MinuteTimer, 60000);
			GetUnit()->GetMapMgr()->GetWorldStateManager()->SetWorldState(WORLDSTATE_ZULAMAN_TIMEDEVENT_TIME, static_cast<uint32>(GetTimer(m_EventTimer) / 60000));
		}

		m_Akilzon		= ForceCreatureFind(CN_AKILZON, AKILZON_SPAWN, false);
		m_Nalorakk		= ForceCreatureFind(CN_NALORAKK, NALORAKK_SPAWN, false);
		m_Janalai		= ForceCreatureFind(CN_JANALAI, JANALAI_SPAWN, false);
		m_Halazzi		= ForceCreatureFind(CN_HALAZZI, HALAZZI_SPAWN, false);
		
		if(m_Akilzon && !m_Akilzon->isAlive() && !m_spawnedAkilzonChest)
		{
			m_d++;
		}
		
		if(m_Halazzi && !m_Halazzi->isAlive() && !m_spawnedHalazziChest)
		{
			m_d++;
		}
		
		if(m_Nalorakk && !m_Nalorakk->isAlive() && !m_spawneddNalorakkChest)
		{
			m_d++;
		}
		
		if(m_Janalai && !m_Janalai->isAlive() && !m_spawnedJanalaiChest)
		{
			m_d++;
		}

		switch(m_d)
		{
		case 0:
			break;
		case 1:
			m_Chest = 187021;
			break;
		case 2:
			m_Chest = 186648;
			break;
		case 3:
			m_Chest = 186667;
			break;
		case 4:
			m_Chest = 186672;
			break;
		}
		
		if(m_Akilzon && !m_Akilzon->isAlive() && !IsTimerFinished(m_EventTimer) && !m_spawnedAkilzonChest)
		{
			ResetTimer(m_EventTimer, GetTimer(m_EventTimer) + 600000);
			m_Akilzon->GetMapMgr()->GetInterface()->SpawnGameObject(m_Chest, 300, 1460, 81.5f, 0, true, 0, 0);
			m_spawnedAkilzonChest = true;
			GetUnit()->GetMapMgr()->GetWorldStateManager()->SetWorldState(WORLDSTATE_ZULAMAN_TIMEDEVENT_TIME, static_cast<uint32>(GetTimer(m_EventTimer) / 60000));
		}
		
		if(m_Nalorakk && !m_Nalorakk->isAlive() && !IsTimerFinished(m_EventTimer) && !m_spawneddNalorakkChest)
		{
			ResetTimer(m_EventTimer, GetTimer(m_EventTimer) + 900000);
			m_Nalorakk->GetMapMgr()->GetInterface()->SpawnGameObject(m_Chest, -90, 1410, 27.5f, 0, true, 0, 0);
			m_spawneddNalorakkChest = true;
			GetUnit()->GetMapMgr()->GetWorldStateManager()->SetWorldState(WORLDSTATE_ZULAMAN_TIMEDEVENT_TIME, static_cast<uint32>(GetTimer(m_EventTimer) / 60000));
		}

		if(m_Janalai && !m_Janalai->isAlive() && !IsTimerFinished(m_EventTimer) && !m_spawnedJanalaiChest)
		{
			m_Janalai->GetMapMgr()->GetInterface()->SpawnGameObject(m_Chest, -78, 1140, 5.3f, 0, true, 0, 0);
			m_spawnedJanalaiChest = true;
		}

		if(m_Halazzi && !m_Halazzi->isAlive() && !IsTimerFinished(m_EventTimer) && !m_spawnedHalazziChest)
		{
			m_Halazzi->GetMapMgr()->GetInterface()->SpawnGameObject(m_Chest, 390, 1150, 6.2f, 0, true, 0, 0);
			m_spawnedHalazziChest = true;
		}

		if(m_d == 4 && !m_EventEnd)
		{
			m_EventEnd = true;
			GetUnit()->GetMapMgr()->GetWorldStateManager()->SetWorldState(WORLDSTATE_ZULAMAN_TIMEDEVENT_DISPLAY, 0);
			RemoveAIUpdateEvent();
		}

		if(IsTimerFinished(m_EventTimer) && !m_EventEnd)
		{
			m_EventEnd = true;
			GetUnit()->GetMapMgr()->GetWorldStateManager()->SetWorldState(WORLDSTATE_ZULAMAN_TIMEDEVENT_DISPLAY, 0);
			RemoveAIUpdateEvent();
		}

		ParentClass::AIUpdate();
	}

protected:
	Unit* m_Akilzon;
	Unit* m_Nalorakk;
	Unit* m_Janalai;
	Unit* m_Halazzi;

	int32 m_EventTimer;
	int32 m_d;
	int32 m_Chest;
	int32 m_MinuteTimer;

	bool m_TimerSet;
	bool m_EventEnd;
	bool m_Opened;
	bool m_spawnedAkilzonChest;
	bool m_spawneddNalorakkChest;
	bool m_spawnedJanalaiChest;
	bool m_spawnedHalazziChest;
};

class HARRISON_JONES_GOSSIP : public GossipScript
{
public:

	void GossipHello(Object* pObject, Player* pPlayer, bool AutoSend)
	{
		if(pPlayer == NULL || !pObject->IsCreature())
			return;

		GossipMenu *Menu = NULL;
		objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, pPlayer);

		GameObject* Door = pObject->GetMapMgr()->GetInterface()->GetGameObjectForce(120, 1603, 44, 186728);
		if(Door && Door->GetUInt32Value(GAMEOBJECT_STATE))
		{
			Menu->AddItem(0, "Open the gate and start the event.", 1);
		}

		if(Menu)
		{
			if(AutoSend)
				Menu->SendTo(pPlayer);
		}
   	}
 
	void GossipSelectOption(Object* pObject, Player* pPlayer, uint32 Id, uint32 IntId, const char * EnteredCode)
	{
		if(pPlayer == NULL || !pObject->IsCreature())
			return;

		switch(IntId)
		{
		case 0:
			{
				GossipHello(pObject, pPlayer, true);
			}break;
		case 1:
			{
				GameObject* Door = pObject->GetMapMgr()->GetInterface()->GetGameObjectForce(120, 1603, 44, 186728);
				if(Door)
				{	
					Door->SetUInt32Value(GAMEOBJECT_STATE, 0);
					Door->SaveState();
					dynamic_cast<TIMEDEVENT*>(TO_CREATURE(pObject)->GetScript())->StartEvent();
				}
			}break;
		}

		pPlayer->Gossip_Complete();
	}	
};

void SetupZulAnmanTimedEvent(ScriptMgr *mgr)
{
	GossipScript* pHJG = (GossipScript*)new HARRISON_JONES_GOSSIP();
	mgr->register_gossip_script(CN_HARRISON_JONES, pHJG);
	mgr->register_creature_script(CN_HARRISON_JONES, &TIMEDEVENT::Create);
}