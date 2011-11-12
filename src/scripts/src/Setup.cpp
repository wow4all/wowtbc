/*
 * Moon++ Scripts for Ascent MMORPG Server
 * Copyright (C) 2005-2007 Ascent Team <http://www.ascentemu.com/>
 * Copyright (C) 2007-2008 Moon++ Team <http://www.moonplusplus.info/>
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
#include "Setup.h"
#define SKIP_ALLOCATOR_SHARING 1
#include <ScriptSetup.h>

extern "C" SCRIPT_DECL uint32 _exp_get_script_type()
{
	return SCRIPT_TYPE_MISC;
}

extern "C" SCRIPT_DECL void _exp_script_register(ScriptMgr* mgr)	// Comment any script to disable it
{
	//Instances
	
	//SetupAlteracValleyBattleground(mgr);
	//SetupAQ40(mgr);
	SetupKJScript(mgr);
	SetupArcatraz(mgr);
	SetupAuchenaiCrypts(mgr);
	//SetupBlackMorass(mgr);
	SetupPvPTerokkarForest(mgr);
	SetupPvPZangarmarsh(mgr);
	SetupPvPHellfirePeninsula(mgr);
	SetupBlackrockDepths(mgr);
	SetupBlackrockSpire(mgr);
	SetupBloodFurnace(mgr);
	SetupBotanica(mgr);
	SetupDeadmines(mgr);
	SetupDireMaul(mgr);
	SetupHellfireRamparts(mgr);
	SetupManaTombs(mgr);
	SetupMaraudon(mgr);
	//SetupOldHillsbradFoothills(mgr);
	SetupRagefireChasm(mgr);
	SetupRazorfenDowns(mgr);
	SetupScarletMonastery(mgr);
	SetupScholomance(mgr);
	SetupSethekkHalls(mgr);
	SetupShadowfangKeep(mgr);
	SetupShadowLabyrinth(mgr);
	SetupTheMechanar(mgr);
	SetupTheShatteredHalls(mgr);
	SetupTheSlavePens(mgr);
	SetupTheSteamvault(mgr);
	SetupTheUnderbog(mgr);
	SetupUldaman(mgr);
	SetupTheStockade(mgr);
	SetupWailingCaverns(mgr);
	//SetupMagistersTerrace(mgr);
	//Raids
	SetupBlackTemple(mgr);
	SetupBlackwingLair(mgr);
	SetupBattleOfMountHyjal(mgr);
	SetupGruulsLair(mgr);
	SetupKarazhan(mgr);
	SetupMoltenCore(mgr);
	SetupNaxxramas(mgr);
	SetupOnyxiasLair(mgr);
	SetupTheEye(mgr);
	SetupZulGurub(mgr);
	SetupSerpentshrineCavern(mgr);
	SetupMagtheridonsLair(mgr);
	SetupSunwellPlateau(mgr);
	//SetupWorldBosses(mgr); 
	SetupZulAman(mgr);
	//Events
	SetupEventDarkPortal(mgr);
	//Other

	//	###		Classes Quests	###
	SetupDruid(mgr);
	SetupPaladin(mgr);
	SetupWarrior(mgr);
	SetupMage(mgr);

//	###		Proffessions Quests	###
	SetupFirstAid(mgr);

//	###		Zones Quests	###
	
	SetupArathiHighlands(mgr);
	SetupAzshara(mgr);
	SetupAzuremystIsle(mgr);
	SetupBladeEdgeMountains(mgr);
	SetupBlastedLands(mgr);
	SetupBloodmystIsle(mgr);
	//SetupDarkshore(mgr);
	SetupDesolace(mgr);
	SetupDustwallowMarsh(mgr);
	SetupEasternPlaguelands(mgr);
	SetupGhostlands(mgr);
	SetupHellfirePeninsula(mgr);
	SetupHillsbradFoothills(mgr);
	SetupIsleOfQuelDanas(mgr);
	SetupLochModan(mgr);
	SetupMulgore(mgr);
	SetupNagrand(mgr);
	SetupNetherstorm(mgr);
	SetupOldHillsbrad(mgr);
	SetupRedrigeMountains(mgr);
	SetupShadowmoon(mgr);
	SetupSilvermoonCity(mgr);
	SetupSilverpineForest(mgr);
	//SetupZulAnmanTimedEvent(mgr);
	SetupStormwind(mgr);
	SetupStranglethornVale(mgr);
	SetupTanaris(mgr);
	SetupTerrokarForest(mgr);
	SetupThousandNeedles(mgr);
	SetupTirisfalGlades(mgr);
	//SetupUndercity(mgr);
	SetupUnGoro(mgr);
	SetupWestfall(mgr);
	SetupZangarmarsh(mgr);
	SetupTeldrassil(mgr);
//	###		Misc		###
	SetupQuestGossip(mgr);
	SetupQuestHooks(mgr);
	SetupUnsorted(mgr);

	// Gossip scripts
	SetupInnkeepers(mgr);
	//SetupReplicaNPC(mgr);
    SetupGuardGossip(mgr);
	SetupTrainerScript(mgr);
	SetupMulgoreGossip(mgr);
	SetupShattrathGossip(mgr);
	SetupTanarisGossip(mgr);
	SetupMoongladeScript(mgr);
	SetupStormwindGossip(mgr);
	SetupDarkmoonFaireGossip(mgr);
	SetupDarkmoonFaireBarker(mgr);

	// misc scripts
	SetupGoHandlers(mgr);
	SetupQDGoHandlers(mgr);
	SetupRandomScripts(mgr);
	SetupMiscCreatures(mgr);
	SetupDarkmoonFaireObjects(mgr);
}

#ifdef WIN32

BOOL APIENTRY DllMain( HANDLE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{
    return TRUE;
}

#endif
