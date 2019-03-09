
#include "StdAfx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include < malloc.h>


#include "..\INC\dec.h"  // include user defined header file
#include "..\..\CNC\inc\cnc.h"

extern CNC_DATA *cncDataPtr;

         
LINK_DATA       *linkDataPtr = &cncDataPtr->linkData;

               
DEC_DATA       *decDataPtr = &cncDataPtr->decData;




//extern int *cncDataPtr;
//***************************************************************
//form1_load -> cncInit -> decInit
//***************************************************************

int decInit(DEC_DATA *decDataPtr)//local data struct.generated by compiler after function call
	                 //  or more specifically, put the original decDATA to stack of the function
{					
	clearByteSpace((char *)decDataPtr, sizeof(DEC_DATA));
	
	for(int i = 0 ; i < 200 ; i++)
	{
		decDataPtr-> ncFileName[i] = '\0';
		decDataPtr-> lineCommand[i] = '\0';
	}

	for(int i = 0 ; i < 2 ; i++)
	{
		decDataPtr->xyCoordinate[i] = 0;
		decDataPtr->xyCheck[2]      = 0;
	}
	decDataPtr->asciiPtr ='\0';

	decDataPtr->relAbs           = false;
	decDataPtr->markN            = false;
	decDataPtr->markBlockCommand = false;
	decDataPtr->markM30          = false;
	decDataPtr->markFileEnd      = false;
	decDataPtr->xyzCoordinateValid[3] = false;
	decDataPtr->markAngle        = false;
	decDataPtr->speedValid       = false;
	decDataPtr->markF            = false;   //clean all the data except G90G91

	decDataPtr->decState = DEC_IDLE; // point to the next step
    return 1;
} // decInit()


//***************************************************************
//
//***************************************************************
int decIdle(DEC_DATA *decDataPtr)
{
	char testFileName[200];

	if(cncDataPtr->linkData.linkToDecData.linkToDecDataValid == true)
	{
		if(cncDataPtr->linkData.linkToDecData.ncFileValid == true
			&& cncDataPtr->linkData.linkToDecData.START == true)
		{
			cncDataPtr->linkData.linkToDecData.START = false;

			decDataPtr->decState = DEC_OPEN_NC_FILE;
		}

		cncDataPtr->linkData.linkToDecData.ncFileValid = false;
	}

	strcpy(testFileName, cncDataPtr->linkData.linkToDecData.ncFileName);
	//what to do in decIdle()
	//
	// if false, can write or send
	// -write data
	// -set bool to true
	// if true, means last one is pending



	//check, if order exists
	//where is the order? memory? global memory
		
   return 1;
} // decIdle()


//***************************************************************
//
//***************************************************************
int decOpenNcFile(DEC_DATA *decDataPtr)
{

	int result;
	int position;
	char    buffer[300];

	//open file
	strcpy(decDataPtr->ncFileName , cncDataPtr->linkData.linkToDecData.ncFileName);
	decDataPtr->ncFilePtr =fopen(decDataPtr->ncFileName,"r");//r: open to read
	if(decDataPtr->ncFilePtr != NULL)
	{
		//file pre processing
		//file size,
		result = fseek(decDataPtr->ncFilePtr, 0 , SEEK_END);

		position = ftell(decDataPtr->ncFilePtr) / sizeof(char);//get the file length in bytes
		
		result = fseek(decDataPtr->ncFilePtr, 0 , SEEK_SET);
		// to request memory from system

		// calloc , malloc
		decDataPtr->fileBufferPtr = (char*)calloc(position , sizeof(char));// using dynamic buffer to load file 
														//\0

		if(decDataPtr->fileBufferPtr != NULL)
		{
			//copy all bytes in file to dynamic buffer 
			result = fread(decDataPtr->fileBufferPtr, sizeof(char), position, decDataPtr->ncFilePtr);		
		}
		else 
		{
			decDataPtr->decState = DEC_ERROR;
			//not success , go to error state
			return -1;
		}

	    //fgets(decDataPtr->lineCommand, CHAR_IN_A_LINE_MAX-1, decDataPtr->ncFilePtr);
		//fgets(decDataPtr->lineCommand, CHAR_IN_A_LINE_MAX-1, decDataPtr->ncFilePtr);
		//fgets(decDataPtr->lineCommand, CHAR_IN_A_LINE_MAX-1, decDataPtr->ncFilePtr);
		//fgets(decDataPtr->lineCommand, CHAR_IN_A_LINE_MAX-1, decDataPtr->ncFilePtr);

		decDataPtr->asciiPtr = decDataPtr->fileBufferPtr;
		decDataPtr->decState = DEC_LOOP;
	}
	else
	{//open file not 
	 //decDataPtr->asciiPtr = decDataPtr->lineCommand;



	 decDataPtr->asciiPtr = decDataPtr->fileBufferPtr;
	 decDataPtr->decState = DEC_ERROR;

	}

   return 1;
} // decOpenNcFile()


//***************************************************************
//
//***************************************************************

int decLoop(DEC_DATA *decDataPtr)
{
	bool line = true;
	int result = 0 ;

	
	for(;line == true;)
	{
		
		switch(*decDataPtr->asciiPtr)
		{
		case ' ':
			
			spaceFunction(decDataPtr);
		
			break;
		case 'N':
		   nFunction(decDataPtr);

			break;
		case 'G':
			gFunction(decDataPtr);

			break;
		case 'X':
			decDataPtr->xyCheck[0]++;
			xyFunction(decDataPtr);
		case 'Y':
			decDataPtr->xyCheck[1]++;
		    xyFunction(decDataPtr);
			

			
			break;
		case '\0':
		case '\n':
		case ';':

		    if (endOfLine(decDataPtr)==-1)
			{
		        //line = false;
			}
			else
			{				
			//pick data DEC_TO_INTP_DATA
			    line = false;

				decDataPtr->decState = DEC_WRITE_OUT;

			}
			//exit DEC_Loop, next state DEC_WRITE_OUT to write decoded data to INTP
			break;
		}
		if(result == -1)
			{
				line = false;
			}
	}
	
   return 1;
} // decLoop()

//*********************************************************
//
//*********************************************************



int decError(DEC_DATA   *decDataPtr)
{
	 return 1;
}


//*********************************************************
//
//*********************************************************
int decMain(DEC_DATA   *decDataPtr)
{
	switch (decDataPtr->decState)
	{
	   case DEC_INIT:
		  decInit(decDataPtr);
		  break;
	   case DEC_IDLE:
		   decIdle(decDataPtr);
		   break;
	   case DEC_OPEN_NC_FILE:
		   decOpenNcFile(decDataPtr);
		   break;
	   case DEC_LOOP:
		   decLoop(decDataPtr);
		   break;
	   case DEC_WRITE_OUT:
		   decWriteOut(decDataPtr);
		   break;
	   case DEC_WAIT_PGM_END:
		   decWaitProgramEnd(decDataPtr);
		   break;
	   case DEC_RESET:
		   decReset(decDataPtr);
		   break;
	   default:DEC_ERROR;
		   decError(decDataPtr);
		   break;
	} // decState

	//attention!!!! free dynamic buffer at end of decording or after M30
	//free(decDataPtr -> fileButter);

  return 1;
} // decMain()


//*********************************************************
//
//*********************************************************
int decReset(DEC_DATA   *decDataPtr)
{

	//attention!!!! free dynamic buffer at end of decording or after M30
//	free(decDataPtr -> fileButterPtr);
	
  return 1;
} // decReset()
//*********************************************************
//
//*********************************************************

int decWriteOut(DEC_DATA   *decDataPtr)
{
/*	if(linkDataPtr->decToLinkData.decToLinkDataValid == false)
	{
	   linkDataPtr->decToLinkData = decDataPtr->decToLinkBlock;
	   linkDataPtr->decToLinkData.decToLinkDataValid = true;
      
	   if(decDataPtr->decToLinkBlock.decToLinkDataValid ==  M30_PROG_END)
	      decDataPtr-> decState = DEC_WAIT_PGM_END;
	   else
	      decDataPtr-> decState = DEC_LOOP;
	 
	  decAfterWrite(decDataPtr);
	}
*/

	if(linkDataPtr->decToIntpValid[linkDataPtr->writeIndex] == false)
	{
	    linkDataPtr->decToLinkBlock[linkDataPtr->writeIndex] = decDataPtr->decToLinkBlock;
		linkDataPtr->decToIntpValid[linkDataPtr->writeIndex] = true;
		linkDataPtr->decToIntpValid[linkDataPtr->readIndex] = true;

		linkDataPtr->writeIndex++;

		if(decDataPtr->decToLinkBlock.linkCmd ==  M30_PROG_END)
	       decDataPtr-> decState = DEC_WAIT_PGM_END;
	    else
	      decDataPtr-> decState = DEC_LOOP;
	 
	  decAfterWrite(decDataPtr);
	}

  return 1;
} //decWriteOut()

//*********************************************************
//
//*********************************************************

int  decWaitProgramEnd(DEC_DATA *decDataPtr)
{
	// wait real-time M30 program end signal sent by the INTP
	// free dyn. memory ,close file ,  and other actions
	// check if M30 true in linkData
	// if true, ......set/clear control data in decData,......
	 decDataPtr-> decState = DEC_IDLE;
   
   return 1;
} // dFunction()