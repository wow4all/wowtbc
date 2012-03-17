/*
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

#include "StdAfx.h"

//Nature's Guardian
ProcCondHandlerRes ProcHandler::NatureGuardian(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->owner->GetHealthPct()> 30)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

//Mace Stun Effect
ProcCondHandlerRes ProcHandler::MaceStunEffect(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->owner->IsPlayer())
		return PROCCOND_BREAK_EXECUTION;

	uint32 talentlevel = 0;
	switch(shareddata->cur_itr->origId)
	{
		//mace specialization
		case 12284:	{talentlevel = 1;}break;
		case 12701:	{talentlevel = 2;}break;
		case 12702:	{talentlevel = 3;}break;
		case 12703:	{talentlevel = 4;}break;
		case 12704:	{talentlevel = 5;}break;
	}

	//warrior/rogue mace specialization can trigger only when using maces
	Item* it;

	it = TO_PLAYER(shareddata->owner)->GetItemInterface()->GetInventoryItem(EQUIPMENT_SLOT_MAINHAND);
	if(it != NULL && it->GetProto())
	{
		uint32 reqskill = GetSkillByProto(it->GetProto()->Class, it->GetProto()->SubClass);
		if(reqskill != SKILL_MACES && reqskill != SKILL_2H_MACES)
			return PROCCOND_BREAK_EXECUTION; //not the right weapon
	}
	else
		return PROCCOND_BREAK_EXECUTION; //no weapon no joy

	//let's recalc chance to cast since we have a full 100 all time on this one
	//how lame to get talentpointlevel for this spell :(
	//float chance=it->GetProto()->Delay*100*talentlevel/60000;
	float chance = float(it->GetProto()->Delay) * float(talentlevel) / 600.0f;
	if(!Rand(chance))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

//sword specialization
ProcCondHandlerRes ProcHandler::SwordSpecialization(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->owner->IsPlayer())
		return PROCCOND_BREAK_EXECUTION;

	Item* it = TO_PLAYER(shareddata->owner)->GetItemInterface()->GetInventoryItem(EQUIPMENT_SLOT_MAINHAND);
	if(it != NULL && it->GetProto())
	{
		uint32 reqskill=GetSkillByProto(it->GetProto()->Class, it->GetProto()->SubClass);
		if(reqskill != SKILL_SWORDS && reqskill != SKILL_2H_SWORDS)
			return PROCCOND_BREAK_EXECUTION; //not the right weapon
	}
	else
		return PROCCOND_BREAK_EXECUTION; //no weapon no joy

	return PROCCOND_CONTINUE_EXECUTION;
}

#define ADDPROCHANDLER(spellId, pHandler, oCanProcOnCreature)					\
	do																			\
	{																			\
		assert(G_ProcCondHandlers[spellId].handler == NULL);					\
		G_ProcCondHandlers[spellId].handler				= pHandler;				\
		G_ProcCondHandlers[spellId].m_canProcOnCreature = oCanProcOnCreature;	\
	}																			\
	while(false)

void InitProcCondHandlers()
{
	ADDPROCHANDLER(16959, &ProcHandler::PrimalFury, false);
	ADDPROCHANDLER(16953, &ProcHandler::BloodFrenzy, false);
	ADDPROCHANDLER(14189, &ProcHandler::SealFate, false);
	ADDPROCHANDLER(17106, &ProcHandler::Intencity, false);
	ADDPROCHANDLER(31616, &ProcHandler::NatureGuardian, false);
	ADDPROCHANDLER(37309, &ProcHandler::Bloodlust, false);
	ADDPROCHANDLER(37310, &ProcHandler::Bloodlust2, false);
	ADDPROCHANDLER(34754, &ProcHandler::HolyConcentration, false);
	ADDPROCHANDLER(5530,  &ProcHandler::MaceStunEffect, false);
	ADDPROCHANDLER(4350,  &ProcHandler::SwordSpecialization, false);
	ADDPROCHANDLER(16459, &ProcHandler::SwordSpecialization, false);
	ADDPROCHANDLER(12721, &ProcHandler::DeepWound, false);
	ADDPROCHANDLER(30069, &ProcHandler::BloodFrenzy_war, false);
	ADDPROCHANDLER(30070, &ProcHandler::BloodFrenzy_war, false);
	ADDPROCHANDLER(12964, &ProcHandler::UnbridledWrath, false);
	ADDPROCHANDLER(46833, &ProcHandler::MoonkinStarfireBonus, false);
	ADDPROCHANDLER(32747, &ProcHandler::DeadlyThrowInterrupt, false);
	ADDPROCHANDLER(37116, &ProcHandler::PrimalFury2, false);
	ADDPROCHANDLER(37117, &ProcHandler::PrimalFury2, false);
	ADDPROCHANDLER(31125, &ProcHandler::BladeTwisting, false);
	ADDPROCHANDLER(17794, &ProcHandler::ImprovedShadowBolt, false);
	ADDPROCHANDLER(17798, &ProcHandler::ImprovedShadowBolt, false);
	ADDPROCHANDLER(17797, &ProcHandler::ImprovedShadowBolt, false);
	ADDPROCHANDLER(17799, &ProcHandler::ImprovedShadowBolt, false);
	ADDPROCHANDLER(17800, &ProcHandler::ImprovedShadowBolt, false);
	ADDPROCHANDLER(32386, &ProcHandler::ShadowEmbrace, false);
	ADDPROCHANDLER(32388, &ProcHandler::ShadowEmbrace, false);
	ADDPROCHANDLER(32389, &ProcHandler::ShadowEmbrace, false);
	ADDPROCHANDLER(32390, &ProcHandler::ShadowEmbrace, false);
	ADDPROCHANDLER(32391, &ProcHandler::ShadowEmbrace, false);
	ADDPROCHANDLER(18118, &ProcHandler::Aftermath, false);
	ADDPROCHANDLER(15269, &ProcHandler::Blackout, false);
	ADDPROCHANDLER(43747, &ProcHandler::LibramofDivineJudgement, false);
	ADDPROCHANDLER(34260, &ProcHandler::LibramofAvengement, false);
	ADDPROCHANDLER(45283, &ProcHandler::NaturalPerfection, false);
	ADDPROCHANDLER(20055, &ProcHandler::Vengeance, false); //wotlk 20053
	ADDPROCHANDLER(17941, &ProcHandler::Nighfall, false);
	ADDPROCHANDLER(43749, &ProcHandler::StonebreakersTotem, false);
	ADDPROCHANDLER(46089, &ProcHandler::StonebreakersTotem, false);
	ADDPROCHANDLER(46093, &ProcHandler::BrutalGladiatorsLibramofJustice, false);
	ADDPROCHANDLER(45429, &ProcHandler::ShatteredSunPendantofAcumen_ArcaneBolt, false);
	ADDPROCHANDLER(45478, &ProcHandler::ShatteredSunPendantofRestoration, false);
	ADDPROCHANDLER(45430, &ProcHandler::ShatteredSunPendantofRestoration, false);
	ADDPROCHANDLER(16488, &ProcHandler::BloodCraze, false);
	ADDPROCHANDLER(16490, &ProcHandler::BloodCraze, false);
	ADDPROCHANDLER(16491, &ProcHandler::BloodCraze, false);
	ADDPROCHANDLER(45058, &ProcHandler::CommendationofKaelthas, false);
	ADDPROCHANDLER(45062, &ProcHandler::VialoftheSunwell, false);
	ADDPROCHANDLER(35095, &ProcHandler::PendantoftheVioletEye, false);
	ADDPROCHANDLER(37658, &ProcHandler::TheLightningCapacitor, false);
	ADDPROCHANDLER(36483, &ProcHandler::CosmicInfuser, false);
	ADDPROCHANDLER(35542, &ProcHandler::CombatPotency, false);
	ADDPROCHANDLER(35545, &ProcHandler::CombatPotency, false);
	ADDPROCHANDLER(35546, &ProcHandler::CombatPotency, false);
	ADDPROCHANDLER(35547, &ProcHandler::CombatPotency, false);
	ADDPROCHANDLER(35548, &ProcHandler::CombatPotency, false);
	ADDPROCHANDLER(39446, &ProcHandler::DFTrinkets, false);
	ADDPROCHANDLER(45055, &ProcHandler::TimbalsFocusingCrystal, false);
	ADDPROCHANDLER(40465, &ProcHandler::ShamanTier6TrinketEnergySurge, false);
	ADDPROCHANDLER(40466, &ProcHandler::ShamanTier6TrinketPowerSurge, false);
	ADDPROCHANDLER(40471, &ProcHandler::PaladinTier6TrinketEnduringLight, false);
	ADDPROCHANDLER(40472, &ProcHandler::PaladinTier6TrinketEnduringJudgement, false);
	ADDPROCHANDLER(43742, &ProcHandler::GraceoftheNaaru, false);
	ADDPROCHANDLER(39373, &ProcHandler::Shadowmend, false);
	ADDPROCHANDLER(40452, &ProcHandler::DruidTier6TrinketBlessingofCenarius, false);
	ADDPROCHANDLER(40445, &ProcHandler::DruidTier6TrinketBlessingofRemulos, false);
	ADDPROCHANDLER(40446, &ProcHandler::DruidTier6TrinketBlessingofElune, false);
	ADDPROCHANDLER(8232,  &ProcHandler::WindfuryWeapon, false);
	ADDPROCHANDLER(8235,  &ProcHandler::WindfuryWeapon, false);
	ADDPROCHANDLER(10486, &ProcHandler::WindfuryWeapon, false);
	ADDPROCHANDLER(16362, &ProcHandler::WindfuryWeapon, false);
	ADDPROCHANDLER(25505, &ProcHandler::WindfuryWeapon, false);
	ADDPROCHANDLER(39805, &ProcHandler::LightningOverload, false);
	ADDPROCHANDLER(12654, &ProcHandler::Ignite, false);
	ADDPROCHANDLER(27285, &ProcHandler::SeedofCorruption, true);
	ADDPROCHANDLER(18371, &ProcHandler::ImprovedDrainSoul, false);
	ADDPROCHANDLER(31117, &ProcHandler::UnstableAffliction, false);
	ADDPROCHANDLER(25228, &ProcHandler::SoulLink, false);
	ADDPROCHANDLER(30300, &ProcHandler::NetherProtection, false);
	ADDPROCHANDLER(30294, &ProcHandler::SoulLeech, false);
	ADDPROCHANDLER(18093, &ProcHandler::Pyroclasm, false);
	ADDPROCHANDLER(22959, &ProcHandler::ImprovedScorch, false);
	ADDPROCHANDLER(28682, &ProcHandler::Combustion, false);
	ADDPROCHANDLER(12579, &ProcHandler::WintersChill, false);
	ADDPROCHANDLER(21992, &ProcHandler::Thunderfury, false);
	ADDPROCHANDLER(5246,  &ProcHandler::IntimidatingShout, false);	
	ADDPROCHANDLER(41637, &ProcHandler::PrayerofMending, false);
	ADDPROCHANDLER(33200, &ProcHandler::Misery, false);
	ADDPROCHANDLER(33199, &ProcHandler::Misery, false);
	ADDPROCHANDLER(33198, &ProcHandler::Misery, false);
	ADDPROCHANDLER(33197, &ProcHandler::Misery, false);
	ADDPROCHANDLER(33196, &ProcHandler::Misery, false);
	ADDPROCHANDLER(15258, &ProcHandler::ShadowWeaving, false);
	ADDPROCHANDLER(15363, &ProcHandler::Inspiration, false);
	ADDPROCHANDLER(14893, &ProcHandler::Inspiration, false);
	ADDPROCHANDLER(15357, &ProcHandler::Inspiration, false);
	ADDPROCHANDLER(15359, &ProcHandler::Inspiration, false);
	ADDPROCHANDLER(27813, &ProcHandler::BlessedRecovery, false);
	ADDPROCHANDLER(27817, &ProcHandler::BlessedRecovery, false);
	ADDPROCHANDLER(27818, &ProcHandler::BlessedRecovery, false);
	ADDPROCHANDLER(29203, &ProcHandler::HealingWay, false);
	ADDPROCHANDLER(29177, &ProcHandler::ElementalDevastation, false);
	ADDPROCHANDLER(29178, &ProcHandler::ElementalDevastation, false);
	ADDPROCHANDLER(30165, &ProcHandler::ElementalDevastation, false);
	ADDPROCHANDLER(16177, &ProcHandler::AncestralFortitude, false);
	ADDPROCHANDLER(16236, &ProcHandler::AncestralFortitude, false);
	ADDPROCHANDLER(16237, &ProcHandler::AncestralFortitude, false);
	ADDPROCHANDLER(42371, &ProcHandler::TotemoftheThirdWind, false);
	ADDPROCHANDLER(34132, &ProcHandler::TotemoftheThirdWind, false);
	ADDPROCHANDLER(46099, &ProcHandler::TotemoftheThirdWind, false);
	ADDPROCHANDLER(43729, &ProcHandler::TotemoftheThirdWind, false);
	ADDPROCHANDLER(25555, &ProcHandler::FlametongueTotemAndFlametongueWeapon, false);	// Flametongue Totem
	ADDPROCHANDLER(16389, &ProcHandler::FlametongueTotemAndFlametongueWeapon, false);	// Flametongue Totem
	ADDPROCHANDLER(10523, &ProcHandler::FlametongueTotemAndFlametongueWeapon, false);	// Flametongue Totem
	ADDPROCHANDLER(8248,  &ProcHandler::FlametongueTotemAndFlametongueWeapon, false);	// Flametongue Totem
	ADDPROCHANDLER(8253,  &ProcHandler::FlametongueTotemAndFlametongueWeapon, false);	// Flametongue Totem
	ADDPROCHANDLER(8026,  &ProcHandler::FlametongueTotemAndFlametongueWeapon, false);	// Flametongue Weapon
	ADDPROCHANDLER(8028,  &ProcHandler::FlametongueTotemAndFlametongueWeapon, false);	// Flametongue Weapon
	ADDPROCHANDLER(8029,  &ProcHandler::FlametongueTotemAndFlametongueWeapon, false);	// Flametongue Weapon
	ADDPROCHANDLER(10445, &ProcHandler::FlametongueTotemAndFlametongueWeapon, false);	// Flametongue Weapon
	ADDPROCHANDLER(16343, &ProcHandler::FlametongueTotemAndFlametongueWeapon, false);	// Flametongue Weapon
	ADDPROCHANDLER(16344, &ProcHandler::FlametongueTotemAndFlametongueWeapon, false);	// Flametongue Weapon
	ADDPROCHANDLER(25488, &ProcHandler::FlametongueTotemAndFlametongueWeapon, false);	// Flametongue Weapon
	ADDPROCHANDLER(16246, &ProcHandler::Clearcasting, false);
	ADDPROCHANDLER(14157, &ProcHandler::Ruthlessness, false);
	ADDPROCHANDLER(14181, &ProcHandler::RelentlessStrikes, false);
	ADDPROCHANDLER(31234, &ProcHandler::FindWeakness, false);
	ADDPROCHANDLER(31235, &ProcHandler::FindWeakness, false);
	ADDPROCHANDLER(31236, &ProcHandler::FindWeakness, false);
	ADDPROCHANDLER(31237, &ProcHandler::FindWeakness, false);
	ADDPROCHANDLER(31238, &ProcHandler::FindWeakness, false);
	ADDPROCHANDLER(13977, &ProcHandler::Initiative, false);
	ADDPROCHANDLER(28377, &ProcHandler::Shadowguard, false);
	ADDPROCHANDLER(28378, &ProcHandler::Shadowguard, false);
	ADDPROCHANDLER(28379, &ProcHandler::Shadowguard, false);
	ADDPROCHANDLER(28380, &ProcHandler::Shadowguard, false);
	ADDPROCHANDLER(28381, &ProcHandler::Shadowguard, false);
	ADDPROCHANDLER(28382, &ProcHandler::Shadowguard, false);
	ADDPROCHANDLER(28385, &ProcHandler::Shadowguard, false);
	ADDPROCHANDLER(23690, &ProcHandler::ImprovedBerserkerRage, false);
	ADDPROCHANDLER(23691, &ProcHandler::ImprovedBerserkerRage, false);
	ADDPROCHANDLER(12536, &ProcHandler::ArcaneConcentration, false);
	ADDPROCHANDLER(12484, &ProcHandler::ImprovedBlizzard, false);
	ADDPROCHANDLER(12485, &ProcHandler::ImprovedBlizzard, false);
	ADDPROCHANDLER(12486, &ProcHandler::ImprovedBlizzard, false);
	ADDPROCHANDLER(29077, &ProcHandler::MasterofElements, false);
	ADDPROCHANDLER(34471, &ProcHandler::TheBeastWithin, false);
	ADDPROCHANDLER(34720, &ProcHandler::ThrilloftheHunt, false);
	ADDPROCHANDLER(33619, &ProcHandler::ReflectiveShield, false);
	ADDPROCHANDLER(30918, &ProcHandler::ImprovedSprint, false);
	ADDPROCHANDLER(31893, &ProcHandler::SealofBlood, false);
	ADDPROCHANDLER(20233, &ProcHandler::ImprovedLayonHands, false);
	ADDPROCHANDLER(20236, &ProcHandler::ImprovedLayonHands, false);
	ADDPROCHANDLER(31786, &ProcHandler::SpiritualAttunement, false);
	ADDPROCHANDLER(31834, &ProcHandler::LightsGrace, false);
	ADDPROCHANDLER(25997, &ProcHandler::EyeforanEye, false);
	ADDPROCHANDLER(31828, &ProcHandler::BlessedLife, false);
	ADDPROCHANDLER(31930, &ProcHandler::SanctifiedJudgement, false);
	ADDPROCHANDLER(43751, &ProcHandler::Energized1, false);
	ADDPROCHANDLER(33370, &ProcHandler::SpellHasteTrinket, false);
	ADDPROCHANDLER(33143, &ProcHandler::BlessedResilience, false);
	ADDPROCHANDLER(35084, &ProcHandler::BandoftheEternalSage, false);
	ADDPROCHANDLER(16922, &ProcHandler::CelestialFocus, false);
	ADDPROCHANDLER(37565, &ProcHandler::Flexibility, false);
	ADDPROCHANDLER(37379, &ProcHandler::Flameshadow, false);
	ADDPROCHANDLER(37378, &ProcHandler::Shadowflame, false);
	ADDPROCHANDLER(39950, &ProcHandler::WaveTrance, false);
	ADDPROCHANDLER(37234, &ProcHandler::Charged, false);
	ADDPROCHANDLER(37214, &ProcHandler::Energized2, false);
	ADDPROCHANDLER(37601, &ProcHandler::Relentlessness, false);
	ADDPROCHANDLER(37237, &ProcHandler::LightningBoltDiscount, false);
	ADDPROCHANDLER(37193, &ProcHandler::InfusedShield, false);
	ADDPROCHANDLER(37196, &ProcHandler::DivineLight, false);
	ADDPROCHANDLER(43838, &ProcHandler::Judgement, false);
	ADDPROCHANDLER(43837, &ProcHandler::Enlightenment, false);
	ADDPROCHANDLER(37529, &ProcHandler::Overpower, false);
	ADDPROCHANDLER(37517, &ProcHandler::Revenge, false);
	ADDPROCHANDLER(28804, &ProcHandler::Epiphany, false);
	ADDPROCHANDLER(37445, &ProcHandler::ManaSurge, false);
	ADDPROCHANDLER(40480, &ProcHandler::AshtongueTalismanofShadows, false);
	ADDPROCHANDLER(37656, &ProcHandler::MementoofTyrande, false);
	ADDPROCHANDLER(40483, &ProcHandler::AshtongueTalismanofInsight, false);
	ADDPROCHANDLER(40487, &ProcHandler::AshtongueTalismanofSwiftness, false);
	ADDPROCHANDLER(40459, &ProcHandler::AshtongueTalismanofValor, false);
	ADDPROCHANDLER(35087, &ProcHandler::BandoftheEternalRestorer, false);
	ADDPROCHANDLER(40441, &ProcHandler::AshtongueTalismanofAcumenShadowWord, false);
	ADDPROCHANDLER(40440, &ProcHandler::AshtongueTalismanofAcumenRenewheals, false);
	ADDPROCHANDLER(40461, &ProcHandler::AshtongueTalismanofLethality, false);
	ADDPROCHANDLER(16886, &ProcHandler::NaturesGrace, false);
	ADDPROCHANDLER(22858, &ProcHandler::Retaliation, true);
	ADDPROCHANDLER(34510, &ProcHandler::DeepThunderAndStormheraldStun, false);
}

array<ProcHandlerDefinition, MAX_SPELL_ID_FROMDBC> G_ProcCondHandlers;