#include "StdAfx.h"
#include "Setup.h"
#include "EAS/EasyFunctions.h"

class StewardOfTime : public GossipScript
{
public:
	void GossipHello(Object* pObject, Player* plr, bool AutoSend)
	{
		GossipMenu *Menu;
		objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 9978, plr);
		Menu->AddItem( 0, "Please take me to the master's lair", 1);
		Menu->SendTo(plr);
	}

	void GossipSelectOption(Object* pObject, Player* plr, uint32 Id, uint32 IntId, const char * Code)
	{
		Creature* creat = static_cast< Creature* >( pObject );
		switch(IntId)
		{
		case 1:
			creat->CastSpell(plr, dbcSpell.LookupEntry(34891), true);
			break;
		}
	}

	void Destroy()
	{
		delete this;
	};
};

void SetupCoTNpC(ScriptMgr * mgr)
{
	GossipScript * StewardOfTimeGossip = (GossipScript*) new StewardOfTime();
	mgr->register_gossip_script(20142, StewardOfTimeGossip);
}