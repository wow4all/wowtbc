
#include "StdAfx.h"

//deep wound
ProcCondHandlerRes ProcHandler::DeepWound(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->owner->IsPlayer())
		return PROCCOND_BREAK_EXECUTION;

	//deep wound requires a melee weapon
	Item* it;
	it = TO_PLAYER(shareddata->owner)->GetItemInterface()->GetInventoryItem(EQUIPMENT_SLOT_MAINHAND);
	if(it != NULL && it->GetProto())
	{
		//class 2 means weapons ;)
		if(it->GetProto()->Class != 2)
			return PROCCOND_BREAK_EXECUTION;
	}
	else 
		return PROCCOND_BREAK_EXECUTION; //no weapon no joy

	return PROCCOND_CONTINUE_EXECUTION;
}

//Blood Frenzy
ProcCondHandlerRes ProcHandler::BloodFrenzy_war(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->owner->IsPlayer())
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->NameHash != SPELL_HASH_REND && 
		shareddata->CastingSpell->NameHash != SPELL_HASH_DEEP_WOUND)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

//Unbridled Wrath
ProcCondHandlerRes ProcHandler::UnbridledWrath(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->owner->IsPlayer())
		return PROCCOND_BREAK_EXECUTION;

	uint32 talentlevel = 0;
	switch(shareddata->cur_itr->origId)
	{
		case 12999:	{talentlevel = 1;}break;
		case 13000:	{talentlevel = 2;}break;
		case 13001:	{talentlevel = 3;}break;
		case 13002:	{talentlevel = 4;}break;
	}

	//let's recalc chance to cast since we have a full 100 all time on this one
	Item* it = TO_PLAYER(shareddata->owner)->GetItemInterface()->GetInventoryItem(EQUIPMENT_SLOT_MAINHAND);
	if(!(it != NULL && it->GetProto()))
		return PROCCOND_BREAK_EXECUTION; //no weapon no joy

	//float chance=float(it->GetProto()->Delay)*float(talentlevel)/600.0f;
	float chance = float(it->GetProto()->Delay) * float(talentlevel) / 300.0f; //zack this had a very low proc rate. Kinda liek a waisted talent
	uint32 myroll = RandomUInt(100);
	if(myroll > chance)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::BloodCraze(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell && shareddata->CastingSpell->c_is_flags & SPELL_FLAG_IS_HEALING)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::IntimidatingShout(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->victim == shareddata->owner) 
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::ImprovedBerserkerRage(ProcCondSharedDataStruct *shareddata)
{
	if(!shareddata->CastingSpell || shareddata->CastingSpell->NameHash != SPELL_HASH_BERSERKER_RAGE)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::Retaliation(ProcCondSharedDataStruct *shareddata)
{
	//retatliation needs target to be not in front. Can be casted by creatures too
	if(shareddata->owner->isInBack(shareddata->victim))
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}