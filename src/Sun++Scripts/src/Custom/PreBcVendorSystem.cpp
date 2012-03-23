#include "Setup.h"



class VendorGossip : public GossipScript
{
public: //Declare Prototypes
	void GossipHello(Object* pObject, Player* Plr, bool AutoSend);
    void GossipSelectOption(Object* pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code);
    void GossipEnd(Object* pObject, Player* Plr);
};

void VendorGossip::GossipHello(Object* pObject, Player* Plr, bool AutoSend)
{

	GossipMenu *Menu; // Point to GossipMenu when we type Menu

	// Make the script check the player's rank
	// If the player has the correct rank, they will be able to buy from the vendor
	if( ( Plr->GetUInt32Value(PLAYER_CHOSEN_TITLE ) > 9 &&  Plr->GetUInt32Value(PLAYER_CHOSEN_TITLE ) <= 14) || ( Plr->GetUInt32Value(PLAYER_CHOSEN_TITLE ) > 23 &&  Plr->GetUInt32Value(PLAYER_CHOSEN_TITLE ) <= 28) ) 
	{
		objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 500001, Plr); // Show the welcome text
		Menu->AddItem( 0, "I would like to buy from you.", 1); // Show the option to buy from the vendor
	}
	else // If the player is not within the acceptable rank range it will use this part
	{
		objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 500000, Plr); // Shows the unable to buy text
	}
	
	Menu->AddItem(0,"Goodbye.",2); // Shows the option to say goodbye to the vendor

	if(AutoSend)
			Menu->SendTo(Plr); // Sends the menu to the player

}

void VendorGossip::GossipSelectOption(Object* pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
{

	Creature* pCreature = (pObject->IsCreature())?(TO_CREATURE(pObject)):NULL; // If what you're talking to is a monster set it to a creature object

	if(pCreature==NULL) //If the creature doesn't exist, stop.
		return;

	switch(IntId) // Which option did the player click?
    {
    case 1: // Player chose to buy from the vendor
        Plr->GetSession()->SendInventoryList(pCreature); // Send the player the NPC's stock
        break;
	case 2: // Player chose the "goodbye" option
		VendorGossip::GossipEnd(pObject, Plr); // Open the End function
		break;
	}

}

void VendorGossip::GossipEnd(Object* pObject, Player* Plr)
{

	GossipScript::GossipEnd(pObject, Plr); // Close the window

}


/*
Below is where all of the vendors' id's are stored and then assign this script to them
If you'd like to add additional vendors, simply copy and paste on of the vendor lines 
below and change the number to the ID of the NPC
*/

void SetupVendors(ScriptMgr * mgr)
{
	GossipScript * gs = new VendorGossip();
    /* Vendor List */

	//Hall of Legends (Horde)
    mgr->register_gossip_script(12795, gs);  // Hall of Legends: First Sergeant Hola'Mahl -- Armour
	mgr->register_gossip_script(12794, gs);  // Hall of Legends: Stone Guard Zarg -- Weapons
	mgr->register_gossip_script(12793, gs);  // Hall of Legends: Brave Stonehide -- Accessories

	//Champion's Hall (Alliance)
	mgr->register_gossip_script(12784, gs); // Champion's Hall: Lieutenant Jackspring -- Weapons
	mgr->register_gossip_script(12785, gs); // Champion's Hall: Sergeant Major Clate -- Armour
	mgr->register_gossip_script(12781, gs); // Champion's Hall: Master Sergeant Biggins -- Accessories

}