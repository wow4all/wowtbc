/**
 * Summit MMORPG Server Software
 * Copyright (c) 2008 Summit Server Team
 * See COPYING for license details.
 */

#ifndef __WORLD_STATE_MANAGER_H
#define __WORLD_STATE_MANAGER_H

/*
 * World State Manager Class
 * See doc/World State Manager.txt for implementation details
 */

// forward declaration for mapmgr
class MapMgr;

// some defines
#define FACTION_MASK_ALL	-1
#define ZONE_MASK_ALL		-1

struct WorldState
{
	WorldState()
	{
		m_FactionMask	= 0;
		m_ZoneMask		= 0;
		m_Value			= 0;
	}

	int32 m_FactionMask;
	int32 m_ZoneMask;
	uint32 m_Value;
};

struct WorldStateTemplate
{
	WorldStateTemplate()
	{
		m_uField		= 0;
		m_iFactionMask	= 0;
		m_iZoneMask		= 0;
		m_uValue		= 0;
	}

	uint32 m_uField;
	int32 m_iFactionMask;
	int32 m_iZoneMask;
	uint32 m_uValue;
};

typedef std::map< uint32, WorldState >	WorldStateMap;
typedef std::list<WorldStateTemplate>		WorldStateTemplateList;

class SERVER_DECL WorldStateManager
{
private:
	// storing world state variables
	WorldStateMap m_states;
	// mapmgr we are working with.
	MapMgr * m_mapMgr;

public:
	WorldStateManager();

	inline void SetMapMgr(MapMgr * pMapMgr) { m_mapMgr = pMapMgr; }

	// updates a world state (sets and stores value, updates in clients on map)
	void SetWorldState(uint32 uWorldStateId, uint32 uValue, int32 iFactionMask = FACTION_MASK_ALL, int32 iZoneMask = ZONE_MASK_ALL);

	//get world state
	uint32 GetWorldState(uint32 uWorldStateId);

	// sends the current world states to a new player on the map.
	// this should also be called upon changing zone.
	void SendWorldStates(Player *pPlayer);

	// clears world states for a player leaving the map.
	void ClearWorldStates(Player *pPlayer);

	// loads a setting from the database.
	static const string GetPersistantSetting(const char *szKeyName, const char *szValue);
	static void SetPersistantSetting(const char *szKeyName, const char *szValue);
};



class WorldStateTemplateManager : public Singleton<WorldStateTemplateManager>
{
private:
	WorldStateTemplateList m_templatesForMaps[NUM_MAPS];


public:
	// loads predefined fields from database 
	void LoadFromDB();

	// applys a map template to a new instance
	void ApplyMapTemplate(MapMgr *pmgr);
};

#define sWorldStateTemplateManager WorldStateTemplateManager::getSingleton()

#endif			// __WORLD_STATE_MANAGER_H
