/**
 * Summit MMORPG Server Software
 * Copyright (c) 2008 Summit Server Team
 * See COPYING for license details.
 */

#include "StdAfx.h"
initialiseSingleton(WorldStateTemplateManager);

/** World State Manager Implementation Class **/
WorldStateManager::WorldStateManager()
{
	m_mapMgr = NULL;
}

// updates a world state with a new value
void WorldStateManager::SetWorldState(uint32 uWorldStateId, uint32 uValue, int32 iFactionMask /* = FACTION_MASK_ALL */, int32 iZoneMask /* = ZONE_MASK_ALL */)
{
	WorldStateMap::iterator itr = m_states.find(uWorldStateId);
	if(itr == m_states.end())
	{
		WorldState newState;
		newState.m_FactionMask		= iFactionMask;
		newState.m_ZoneMask			= iZoneMask;
		newState.m_Value			= uValue;
		m_states.insert(make_pair(uWorldStateId, newState));

		//reinicialize iterator
		itr = m_states.find(uWorldStateId);
	}
	else
	{
		// set the new value
		itr->second.m_FactionMask	= iFactionMask;
		itr->second.m_ZoneMask		= iZoneMask;
		itr->second.m_Value			= uValue;
	}

	WorldPacket data(SMSG_UPDATE_WORLD_STATE, 16);
	data << uint32(uWorldStateId);
	data << uint32(uValue);
	m_mapMgr->SendPacketToPlayers(itr->second.m_ZoneMask, itr->second.m_FactionMask, data);
}

uint32 WorldStateManager::GetWorldState(uint32 uWorldStateId)
{
	WorldStateMap::iterator itr = m_states.find(uWorldStateId);
	if(itr != m_states.end())
		return itr->second.m_Value;
	else
		return 0;
}

void WorldStateManager::SendWorldStates(Player *pPlayer)
{
	uint32 state_count = 0;

	WorldPacket data(SMSG_INIT_WORLD_STATES, (m_states.size() * 8) + 32);
	data << uint32(m_mapMgr->GetMapId());
	data << uint32(pPlayer->GetZoneId());
	data << uint32(pPlayer->GetAreaID());

	// set this to zero, since the count can be variable
	data << uint16(0);

	// add states to packet
	for(WorldStateMap::iterator itr = m_states.begin(); itr != m_states.end(); ++itr)
	{
		if(itr->second.m_FactionMask != FACTION_MASK_ALL && itr->second.m_FactionMask != static_cast<int32>(pPlayer->GetTeam()))
			continue;

		if(itr->second.m_ZoneMask != ZONE_MASK_ALL && itr->second.m_ZoneMask != static_cast<int32>(pPlayer->GetZoneId()))
			continue;

		data << uint32(itr->first);
		data << uint32(itr->second.m_Value);

		++state_count;
	}

	// append the count, and send away
	*(uint16*)(&data.contents()[12]) = state_count;
	pPlayer->GetSession()->SendPacket(&data);	
}

void WorldStateManager::ClearWorldStates(Player *pPlayer)
{
	WorldPacket data(SMSG_INIT_WORLD_STATES, 16);
	data << uint32(0);	// map=0
	data << uint16(0);	// data1=0	
	data << uint16(0);	// data2=0
	data << uint16(0);	// valcount=0
	pPlayer->GetSession()->SendPacket(&data);
}

const string WorldStateManager::GetPersistantSetting(const char *szKeyName, const char *szDefaultValue)
{
	QueryResult* pResult = CharacterDatabase.Query("SELECT setting_value FROM worldstate_save_data WHERE setting_id = \"%s\"", CharacterDatabase.EscapeString(string(szKeyName)).c_str());
	if(pResult == NULL)
		return string(szDefaultValue);
	else
		return string(pResult->Fetch()[0].GetString());;
}

void WorldStateManager::SetPersistantSetting(const char *szKeyName, const char *szValue)
{
	string pkey = string(szKeyName);
	string pval = string(szValue);

	pkey = CharacterDatabase.EscapeString(pkey);
	pval = CharacterDatabase.EscapeString(pval);

	CharacterDatabase.Execute("REPLACE INTO worldstate_save_data VALUES(\"%s\", \"%s\")", pkey.c_str(), pval.c_str());
}


//////////////////////////////////////////////////////////////////////////
// Template Manager
//////////////////////////////////////////////////////////////////////////

void WorldStateTemplateManager::LoadFromDB()
{
	QueryResult* pResult = WorldDatabase.Query("SELECT * FROM worldstate_template");
	if(!pResult)
		return;

	do 
	{
		Field *fields = pResult->Fetch();
		uint32 mapid = fields[0].GetUInt32();

		WorldStateTemplate tmpl;
		tmpl.m_iZoneMask		= fields[1].GetInt32();
		tmpl.m_iFactionMask		= fields[2].GetInt32();
		tmpl.m_uField			= fields[3].GetUInt32();
		tmpl.m_uValue			= fields[4].GetUInt32();
	
		m_templatesForMaps[mapid].push_back(tmpl);

	}while (pResult->NextRow());
}

void WorldStateTemplateManager::ApplyMapTemplate(MapMgr *pmgr)
{
	WorldStateTemplateList::iterator itr	= m_templatesForMaps[pmgr->GetMapId()].begin();
	WorldStateTemplateList::iterator itrend = m_templatesForMaps[pmgr->GetMapId()].end();
	for(; itr != itrend; ++itr)
	{
		pmgr->GetWorldStateManager()->SetWorldState(itr->m_uField, itr->m_uValue, itr->m_iFactionMask, itr->m_iZoneMask);
	}
}
