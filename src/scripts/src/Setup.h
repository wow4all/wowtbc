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
#include "StdAfx.h"

#ifndef INSTANCE_SCRIPTS_SETUP_H
#define INSTANCE_SCRIPTS_SETUP_H

//Instances
//void SetupAlteracValleyBattleground(ScriptMgr * mgr);
//void SetupAQ40(ScriptMgr * mgr);
void SetupKJScript(ScriptMgr * mgr);
void SetupArcatraz(ScriptMgr * mgr);
void SetupAuchenaiCrypts(ScriptMgr * mgr);
//void SetupBlackMorass(ScriptMgr * mgr);
void SetupPvPTerokkarForest(ScriptMgr * mgr);
void SetupPvPZangarmarsh(ScriptMgr * mgr);
void SetupDpsDummies(ScriptMgr * mgr);
void SetupPvPHellfirePeninsula(ScriptMgr * mgr);
void SetupBlackrockSpire(ScriptMgr *mgr);
void SetupBlackrockDepths(ScriptMgr * mgr);
void SetupDpsDummies(ScriptMgr * mgr);
void SetupBotanica(ScriptMgr * mgr);
void SetupDeadmines(ScriptMgr * mgr);
void SetupDireMaul(ScriptMgr * mgr);
void SetupHellfireRamparts(ScriptMgr * mgr);
void SetupManaTombs(ScriptMgr * mgr);
void SetupMaraudon(ScriptMgr * mgr);
//void SetupOldHillsbradFoothills(ScriptMgr * mgr);
void SetupRagefireChasm(ScriptMgr * mgr);
void SetupRazorfenDowns(ScriptMgr * mgr);
void SetupScarletMonastery(ScriptMgr * mgr);
void SetupScholomance(ScriptMgr * mgr);
void SetupSethekkHalls(ScriptMgr * mgr);
void SetupShadowfangKeep(ScriptMgr * mgr);
void SetupShadowLabyrinth(ScriptMgr * mgr);
void SetupTheMechanar(ScriptMgr * mgr);
void SetupTheShatteredHalls(ScriptMgr * mgr);
void SetupTheSlavePens(ScriptMgr * mgr);
void SetupTheSteamvault(ScriptMgr * mgr);
void SetupTheUnderbog(ScriptMgr * mgr);
void SetupUldaman(ScriptMgr * mgr);
void SetupTheStockade(ScriptMgr * mgr);
void SetupWailingCaverns(ScriptMgr * mgr);
//void SetupMagistersTerrace(ScriptMgr * mgr);
//Raids
void SetupBlackTemple(ScriptMgr * mgr);
void SetupBlackwingLair(ScriptMgr * mgr);
void SetupBattleOfMountHyjal(ScriptMgr * mgr);
void SetupGruulsLair(ScriptMgr * mgr);
void SetupKarazhan(ScriptMgr * mgr);
void SetupMoltenCore(ScriptMgr * mgr);
void SetupNaxxramas(ScriptMgr * mgr);
void SetupOnyxiasLair(ScriptMgr * mgr);
void SetupTheEye(ScriptMgr * mgr);
void SetupZulGurub(ScriptMgr * mgr);
void SetupSerpentshrineCavern(ScriptMgr * mgr);
void SetupMagtheridonsLair(ScriptMgr * mgr);
void SetupSunwellPlateau(ScriptMgr* pScriptMgr);
//void SetupWorldBosses(ScriptMgr * mgr);
void SetupZulAman(ScriptMgr * mgr);
//Events
void SetupEventDarkPortal(ScriptMgr * mgr);

//	###		Classes Quests	###
void SetupDruid(ScriptMgr * mgr);
void SetupPaladin(ScriptMgr * mgr);
void SetupWarrior(ScriptMgr * mgr);
void SetupMage(ScriptMgr * mgr);

//	###		Proffessions Quests	###
void SetupFirstAid(ScriptMgr * mgr);

//	###		Zones Quests	###
void SetupArathiHighlands(ScriptMgr * mgr);
void SetupAzshara(ScriptMgr * mgr);
void SetupAzuremystIsle(ScriptMgr * mgr);
void SetupBladeEdgeMountains(ScriptMgr * mgr);
void SetupBlastedLands(ScriptMgr * mgr);
void SetupBloodmystIsle(ScriptMgr * mgr);
//void SetupDarkshore(ScriptMgr * mgr)
void SetupDesolace(ScriptMgr * mgr);
void SetupDustwallowMarsh(ScriptMgr * mgr);
void SetupEasternPlaguelands(ScriptMgr * mgr);
void SetupGhostlands(ScriptMgr * mgr);
void SetupHellfirePeninsula(ScriptMgr * mgr);
void SetupHillsbradFoothills(ScriptMgr * mgr);
void SetupIsleOfQuelDanas(ScriptMgr * mgr);
void SetupLochModan(ScriptMgr * mgr);
void SetupMulgore(ScriptMgr * mgr);
void SetupNagrand(ScriptMgr * mgr);
void SetupNetherstorm(ScriptMgr * mgr);
void SetupOldHillsbrad(ScriptMgr * mgr);
void SetupRedrigeMountains(ScriptMgr * mgr);
void SetupShadowmoon(ScriptMgr * mgr);
void SetupSilvermoonCity(ScriptMgr * mgr);
void SetupSilverpineForest(ScriptMgr * mgr);
//void SetupZulAnmanTimedEvent(ScriptMgr * mgr);
void SetupStormwind(ScriptMgr * mgr);
void SetupStranglethornVale(ScriptMgr * mgr);
void SetupTanaris(ScriptMgr * mgr);
void SetupTerrokarForest(ScriptMgr * mgr);
void SetupThousandNeedles(ScriptMgr * mgr);
void SetupTirisfalGlades(ScriptMgr * mgr);
//void SetupUndercity(ScriptMgr * mgr);
void SetupUnGoro(ScriptMgr * mgr);
void SetupWestfall(ScriptMgr * mgr);
void SetupZangarmarsh(ScriptMgr * mgr);
void SetupTeldrassil(ScriptMgr *mgr);
//	###		Misc	###
void SetupQuestGossip(ScriptMgr * mgr);
void SetupQuestHooks(ScriptMgr * mgr);
void SetupUnsorted(ScriptMgr * mgr);

// Gossip scripts
void SetupInnkeepers(ScriptMgr * mgr);
//void SetupReplicaNPC(ScriptMgr* mgr);
void SetupGuardGossip(ScriptMgr * mgr);
void SetupTrainerScript(ScriptMgr * mgr);
void SetupMulgoreGossip(ScriptMgr * mgr);
void SetupShattrathGossip(ScriptMgr * mgr);
void SetupTanarisGossip(ScriptMgr * mgr);
void SetupMoongladeScript(ScriptMgr * mgr);
void SetupStormwindGossip(ScriptMgr * mgr);
void SetupDarkmoonFaireGossip(ScriptMgr * mgr);
void SetupDarkmoonFaireBarker(ScriptMgr * mgr);

// Misc scripts
void SetupGoHandlers(ScriptMgr * mgr);
void SetupQDGoHandlers(ScriptMgr * mgr);
void SetupRandomScripts(ScriptMgr * mgr);
void SetupMiscCreatures(ScriptMgr * mgr);
void SetupDarkmoonFaireObjects(ScriptMgr * mgr);

#endif
