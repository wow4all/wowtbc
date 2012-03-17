/* TbcEmu 
 * ArcEmu MMORPG Server
 * Copyright (C) 2005-2007 Ascent Team <http://www.ascentemu.com/>
 * Copyright (C) 2008 <http://www.ArcEmu.org/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/*

	Compression player movement

*/

#include "StdAfx.h"

#ifdef ENABLE_COMPRESSED_MOVEMENT

void CMovementCompressor::ProcessPlayers()
{
	for(CompressPlayerSet::const_iterator itr =  m_players.begin();itr != m_players.end();++itr)
	{
		Player * plr = (*itr);
		if(plr->IsInWorld())
		{
			plr->EventDumpCompressedMovement(m_mapmgr->m_compressionBuffer);
		}
	}
}

void CMovementCompressor::AddPlayer(Player * pPlayer)
{
	pPlayer->CleanBuffer();
	m_players.insert(pPlayer);
}

void CMovementCompressor::RemovePlayer(Player * pPlayer)
{
	pPlayer->CleanBuffer();
	m_players.erase(pPlayer);
}

#endif