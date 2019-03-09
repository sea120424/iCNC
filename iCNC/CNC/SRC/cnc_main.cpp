
#include "StdAfx.h"
#include <stdio.h>
#include <stdlib.h>

#include "..\inc\cnc.h"  // include user defined header file



extern CNC_DATA *cncDataPtr;

//*********************************************************
//
//*********************************************************
int cncInit(void)
{
	// clear data
	clearByteSpace((char *)cncDataPtr, sizeof(CNC_DATA));
	mmiInit(&cncDataPtr->mmiData);
	decInit(&cncDataPtr->decData);
	//sysInit(&cncDataPtr->sysData);
	//intpInit(&cncDataPtr->intpData);
	linkInit(&cncDataPtr->linkData);
	
  return 1;
} // cncInit()


//*********************************************************
//
//*********************************************************
int nrtMain(void)
{
  mmiMain(&cncDataPtr->mmiData);
  linkMain(&cncDataPtr->linkData);
  decMain(&cncDataPtr->decData);
 
  return 1;
} // nrtMain()


//*********************************************************
//
//*********************************************************
int rtMain(void)
{
  //intpMain(&cncDataPtr->intpData);

  return 1;
} // rtMain()


//*********************************************************
//
//*********************************************************
int cncMain(void)
{


  return 1;
} // cncMain()