
#include "StdAfx.h"

ProcCondHandlerRes ProcHandler::TheBeastWithin(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	if(shareddata->CastingSpell->Id != 19574)
		return PROCCOND_BREAK_EXECUTION;

	return PROCCOND_CONTINUE_EXECUTION;
}

ProcCondHandlerRes ProcHandler::ThrilloftheHunt(ProcCondSharedDataStruct *shareddata)
{
	if(shareddata->CastingSpell == NULL)
		return PROCCOND_BREAK_EXECUTION;

	shareddata->dmg_overwrite = shareddata->CastingSpell->manaCost * 40 / 100;

	return PROCCOND_CONTINUE_EXECUTION;
}