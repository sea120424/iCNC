#include "StdAfx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\..\UTILITY\INC\utility.h"
#include "..\..\CNC\INC\cnc.h"

extern CNC_DATA* cncDataPtr;


//*********************************************************
//
//*********************************************************
int mmiMain(MMI_DATA* mmiDataPtr)
{
	switch(mmiDataPtr->mmiState)
	{
	case MMI_IDLE:
		mmiIdle(mmiDataPtr);
		break;

	case MEM_STATE:
		mmiMemState(mmiDataPtr);
		break;

	case JOG_STATE:
		mmiJogState(mmiDataPtr);
		break;

	case MMI_RESET:
		mmiReset(mmiDataPtr);
		break;

	default:
		break;

	}

	return 1;
}
