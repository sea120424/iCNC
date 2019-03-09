#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\..\UTILITY\INC\utility.h"
#include "..\..\CNC\INC\cnc.h"


//*********************************************************
//
//*********************************************************

int linkMain(LINK_DATA* linkDataPtr)
{
	if(linkDataPtr->mmiToLinkData.mmiToLinkDataValid == true)
	{
		if(linkDataPtr->mmiToLinkData.ncFileValid == true)
		{
			strcpy(linkDataPtr->linkToDecData.ncFileName,linkDataPtr->mmiToLinkData.ncFileName);
			linkDataPtr->mmiToLinkData.ncFileValid == false;
			linkDataPtr->linkToDecData.ncFileValid = true;
		}
		linkDataPtr->linkToDecData.START = linkDataPtr-> mmiToLinkData.START;
		linkDataPtr->linkToDecData.RESET = linkDataPtr-> mmiToLinkData.RESET;
		linkDataPtr->linkToDecData.linkToDecDataValid = true;
		linkDataPtr->mmiToLinkData.mmiToLinkDataValid = false;

	}


	return 1;
}

//*********************************************************
//
//*********************************************************
int linkInit(LINK_DATA* linkDataPtr)
{
	//clearByteSpace((char *) linkDataPtr , sizeof(LINK_DATA));
	mmiToLinkDataInit(linkDataPtr);
	linkToMmiDataInit(linkDataPtr);
	decToLinkDataInit(linkDataPtr);
	linkToDecDataInit(linkDataPtr);
	intpToLinkDataInit(linkDataPtr);
	linkToIntpDataInit(linkDataPtr);

	
	//FIFO
	linkDataPtr->writeIndex = 0;
	linkDataPtr->readIndex = 0;
	for(int i = 0 ; i < 100 ; i++)
	{
		linkDataPtr->decToIntpValid[i] = false;
	}
	
	return 1;
}

//*********************************************************
//
//*********************************************************
int mmiToLinkDataInit(LINK_DATA* linkDataPtr)
{
	for(int i = 0 ; i < 200 ; i++)
	{
		
		linkDataPtr->mmiToLinkData.ncFileName[i] = '\0';
	}


	linkDataPtr->mmiToLinkData.ncFileValid = false;
	linkDataPtr->mmiToLinkData.RESET = false;

	return 1;
}

//*********************************************************
//
//*********************************************************
int linkToMmiDataInit(LINK_DATA* linkDataPtr)
{
	linkDataPtr->linkToMmiData.counter = 0;

	for(int i = 0 ; i < 3 ; i++)
	{
		linkDataPtr->linkToMmiData.CarCoordinate[i] = 0.0;
	}

	for(int i = 0 ; i < 4 ; i++)
	{
		linkDataPtr->linkToMmiData.serialCmd[i] = '\0';
	}

	
	linkDataPtr->linkToMmiData.serialCmdVaild = false;

	return 1;
}

//*********************************************************
//
//*********************************************************
int decToLinkDataInit(LINK_DATA* linkDataPtr)
{
	linkDataPtr->decToLinkData.cmdVaild = false;
	linkDataPtr->decToLinkData.lineNumber = 0; 
	linkDataPtr->decToLinkData.lineNumberVaild = false;
	linkDataPtr->decToLinkData.lineCmd = 0;   
	linkDataPtr->decToLinkData.lineCmdVaild = false;
	linkDataPtr->decToLinkData.relAbs = false;    
	linkDataPtr->decToLinkData.relVaild = false;

	for(int i = 0 ; i < 2 ; i++)
	{
		linkDataPtr->decToLinkData.xyCoordinate[i] = 0.0;
		linkDataPtr->decToLinkData.xyValid[i] = false;
	}

	linkDataPtr->decToLinkData.angle = 0.0;
	linkDataPtr->decToLinkData.direction = false;  
	linkDataPtr->decToLinkData.angleVaild = false;
	linkDataPtr->decToLinkData.speed = 0.0;      
	linkDataPtr->decToLinkData.speedValid = false;

	return 1;
}

//*********************************************************
//
//*********************************************************
int linkToDecDataInit(LINK_DATA* linkDataPtr)
{
	for(int i = 0 ; i < 200 ; i++)
	{
		linkDataPtr->linkToDecData.ncFileName[i] = '\0';
	}

	linkDataPtr->linkToDecData.ncFileValid = false;
	linkDataPtr->linkToDecData.RESET = false;
	linkDataPtr->linkToDecData.START = false;

	return 1;
}

//*********************************************************
//
//*********************************************************
int intpToLinkDataInit(LINK_DATA* linkDataPtr)
{
	for(int i = 0 ; i < 3 ; i++)
	{
		linkDataPtr->intpToLinkData.CarCoordinate[i] = 0.0;
	}

	for(int i = 0 ; i < 4 ; i++)
	{
		linkDataPtr->intpToLinkData.serialCmd[i] = '\0';
	}

	linkDataPtr->intpToLinkData.serialCmdVaild = false;

	linkDataPtr->intpToLinkData.RESET = false;

	return 1;
}

//*********************************************************
//
//*********************************************************
int linkToIntpDataInit(LINK_DATA* linkDataPtr)
{
	linkDataPtr->linkToIntpData.cmdVaild = false;
	linkDataPtr->linkToIntpData.lineNumber = 0; 
	linkDataPtr->linkToIntpData.lineNumberVaild = false;
	linkDataPtr->linkToIntpData.lineCmd = 0;   
	linkDataPtr->linkToIntpData.lineCmdVaild = false;
	linkDataPtr->linkToIntpData.relAbs = false;    
	linkDataPtr->linkToIntpData.relVaild = false;

	for(int i = 0 ; i < 2 ; i++)
	{
		linkDataPtr->linkToIntpData.xyCoordinate[i] = 0.0;
		linkDataPtr->linkToIntpData.xyValid[i] = false;
	}

	linkDataPtr->linkToIntpData.angle = 0.0;
	linkDataPtr->linkToIntpData.direction = false;  
	linkDataPtr->linkToIntpData.angleVaild = false;
	linkDataPtr->linkToIntpData.speed = 0.0;      
	linkDataPtr->linkToIntpData.speedValid = false;

	return 1;
}