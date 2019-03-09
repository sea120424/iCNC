
#include "StdAfx.h"
#include <stdio.h>
#include <stdlib.h>


#include "..\inc\dec.h"  // include user defined header file
#include "..\..\UTILITY\INC\utility.h"




//***************************************************************
//
//***************************************************************
int spaceFunction(DEC_DATA *decDataPtr)
{
	decDataPtr->asciiPtr++;
	//pass space
   return 1;
} // spaceFunction()



//***************************************************************
//
//***************************************************************
int nFunction(DEC_DATA *decDataPtr)
{
	if(decDataPtr-> markN == true)  //N100 N123 G00 G91
	{   //mutiple inputs of N
		decDataPtr->decState = DEC_ERROR;
		return -1;
	}
	
	decDataPtr->asciiPtr++;
    decDataPtr->asciiPtr = passSpace(decDataPtr->asciiPtr);
	//check if digit is following, if not ,system error, for example N1200 G00 G91 
	if (isDigit(decDataPtr->asciiPtr) == true)
	{   //call atoi(0 to convert
		decDataPtr->lineNumber = atoi(decDataPtr->asciiPtr);
		decDataPtr->markN = true;
		decDataPtr->asciiPtr = passDigit(decDataPtr->asciiPtr);
	}
	else
	{
		//no number follow N -> error 
		decDataPtr->decState = DEC_ERROR;
		return -1;
	}

	 
   return 1;
} // nFunction()


//***************************************************************
//
//***************************************************************
int gFunction(DEC_DATA *decDataPtr)
{
	decDataPtr->asciiPtr = passSpace(decDataPtr->asciiPtr);
	if(decDataPtr->markG90G91 == true)
	{
		decDataPtr->decState = DEC_ERROR;
		return -1;
	}
	else
	{
		decDataPtr->asciiPtr++;
		decDataPtr->asciiPtr = passDigit(decDataPtr->asciiPtr);
		if (isDigit(decDataPtr->asciiPtr) == true)
		{   
			decDataPtr->lineNumber = atoi(decDataPtr->asciiPtr);
			decDataPtr->markN = true;
		}
		
		int n;
		n = atoi(decDataPtr->asciiPtr);

		switch (n)
		{
		case 00:
			if(decDataPtr->markG == true)
			{
				decDataPtr->decState = DEC_ERROR;
				return -1;
			}	
			decDataPtr->markG = true;
			decDataPtr->linkCmd = G00_CMD;
			
			break;
		case 01:
			if(decDataPtr->markG == true)
			{
				decDataPtr->decState = DEC_ERROR;
				return -1;
			}	
			decDataPtr->markG = true;
			//decDataPtr->decToLinkBlock.lineCmd = 
			break;
		case 04:
			if(decDataPtr->markG == true)
			{
				decDataPtr->decState = DEC_ERROR;
				return -1;
			}	
			decDataPtr->markG = true;
			decDataPtr->linkCmd = G04_DWELL_TIME;
			break;
		case 06:
			if(decDataPtr->markG == true)
			{
				decDataPtr->decState = DEC_ERROR;
				return -1;
			}	
			decDataPtr->markG = true;
			decDataPtr->linkCmd = G06_ROT_CW;
			break;
		case 07:
			if(decDataPtr->markG == true)
			{
				decDataPtr->decState = DEC_ERROR;
				return -1;
			}	
			decDataPtr->markG = true;
			decDataPtr->linkCmd = G07_ROT_CCW;
			break;
		case 90:
			decDataPtr->markG90G91 = true;
			decDataPtr->relAbs = false;
			break;
		case 91:
			decDataPtr->markG90G91 = true;
			decDataPtr->relAbs = true;
			break;
		default :
			decDataPtr->decState = DEC_ERROR;
			return -1;
			break;

		}
			


	}

	decDataPtr->asciiPtr = passDigit(decDataPtr->asciiPtr);
   return 1;
} // gFunction()

//***************************************************************
//
//***************************************************************
int mFunction(DEC_DATA *decDataPtr)
{
	if(decDataPtr-> markM == true)  //N100 N123 G00 G91
	{   //mutiple inputs of M
		decDataPtr->decState = DEC_ERROR;
		return -1;
	}

	decDataPtr->asciiPtr++;
    decDataPtr->asciiPtr = passSpace(decDataPtr->asciiPtr);

	if (isDigit(decDataPtr->asciiPtr) == true)
	{   //call atoi(0 to convert
		decDataPtr->lineNumber = atoi(decDataPtr->asciiPtr);
		decDataPtr->markM = true;
		decDataPtr->asciiPtr = passDigit(decDataPtr->asciiPtr);
	}
	else
	{
		//no number follow N -> error 
		decDataPtr->decState = DEC_ERROR;
		return -1;
	}
	
 

	
   return 1;
} // mFunction()

//***************************************************************
//
//***************************************************************
int fFunction(DEC_DATA *decDataPtr)
{
	if(decDataPtr-> markF == true)  //N100 N123 G00 G91
	{   //mutiple inputs of F
		decDataPtr->decState = DEC_ERROR;
		return -1;
	}
	if (isFloat(decDataPtr->asciiPtr) == true)
	{   //call atoi(0 to convert
		decDataPtr->lineNumber = atof(decDataPtr->asciiPtr);
		decDataPtr->markF = true;
		decDataPtr->asciiPtr = passFloat(decDataPtr->asciiPtr);
	}
	else
	{
		//no number follow N -> error 
		decDataPtr->decState = DEC_ERROR;
		return -1;
	}


   return 1;
} // fFunction()

//***************************************************************
//
//***************************************************************
int xyFunction(DEC_DATA *decDataPtr)
{
	//decDataPtr-> xyCoordinate[0] = atof(decDataPtr->asciiPtr);
	if(decDataPtr->xyCheck[0] > 1 || decDataPtr->xyCheck[1] > 1)
	{
	   decDataPtr->decState = DEC_ERROR;
	}
		
	if (isFloat(decDataPtr->asciiPtr) == true)
	{   //call atoi(0 to convert
		decDataPtr->lineNumber = atof(decDataPtr->asciiPtr);
		decDataPtr->asciiPtr = passFloat(decDataPtr->asciiPtr);
	}
	else
	{
		decDataPtr->decState = DEC_ERROR;
		return -1;
	}
	
   return 1;
} // xyFunction()

//***************************************************************
//
//***************************************************************
int dFunction(DEC_DATA *decDataPtr)
{
	if(decDataPtr-> markAngle == true)  //N100 N123 G00 G91
	{   //mutiple inputs of F
		decDataPtr->decState = DEC_ERROR;
		return -1;
	}
	if (isFloat(decDataPtr->asciiPtr) == true)
	{   //call atoi(0 to convert
		decDataPtr->lineNumber = atof(decDataPtr->asciiPtr);
		decDataPtr->markAngle = true;
		decDataPtr->asciiPtr = passFloat(decDataPtr->asciiPtr);
	}
	else
	{
		//no number follow N -> error 
		decDataPtr->decState = DEC_ERROR;
		return -1;
	}
  
   return 1;
} // dFunction()


//***************************************************************
//
//***************************************************************
int decAfterWrite(DEC_DATA *decDataPtr)
{
	// clear saved data, such as all marker
    decDataPtr->linkCmd = NULL_CMD;
	decDataPtr->markN = false;
	//...and so on
	// any marker to set ? or remain vaild?
	// depends on the life circle of the code,one shot or modal

   return 1;
} // decAfterWrite()

//***************************************************************
//
//***************************************************************
int endOfLine(DEC_DATA *decDataPtr)
{
    // Clear the 
	clearByteSpace((char *)decDataPtr, sizeof(DEC_TO_LINK_BLOCK));
	// Check 

	
	if(decDataPtr->markN)
	{
        decDataPtr->decToLinkBlock.lineNumber = decDataPtr->lineNumber;
		decDataPtr->decToLinkBlock.lineNumberVaild = true;
	}
	else
	{//no N input ,OK,lineNumberVaild = false, no error 
		      
	}
	

	switch(decDataPtr->decToLinkBlock.lineCmd)
	 {
	 case G00_CMD:
         if(decDataPtr->markN)
		 {
		    decDataPtr->decToLinkBlock.lineNumber = decDataPtr->lineNumber;
			decDataPtr->decToLinkBlock.lineNumberVaild = true;
		 }
		 else
		 {//no N input ,OK,lineNumberVaild = false, no error 
		      
		 }

		 if(decDataPtr->markG90G91)
		 {
		    decDataPtr->decToLinkBlock.relAbs =  decDataPtr->relAbs;
		 }
		 else
		 {//no G90,G91-> error
		    decDataPtr->decState = DEC_ERROR;
			return -1;
		 }

		 if((decDataPtr->xyCheck[0] ) || (decDataPtr->xyCheck[1]) )
		 {
		    for(int i=0; i < 2; i++)
			{
			    if(decDataPtr->xyCheck[i])
				decDataPtr->decToLinkBlock.xyCoordinate[i] =  decDataPtr->xyCoordinate[i];
				decDataPtr->decToLinkBlock.xyCheck[i] =  decDataPtr->xyCheck[i];
			}
		 }
		 else
		 {   //no x or y -> error
		    decDataPtr->decState = DEC_ERROR;
			return -1;
		 }
		 //further check of input ...

		 break;
	 case G06_ROT_CW: 
	 case G07_ROT_CCW:
		 break;
	 case G04_DWELL_TIME:
		 break;
	 case M30_PROG_END:
		 break;

	 default:  decDataPtr->decState = DEC_ERROR;
	 }



    // data packing finish!! 
    return 1;
} // endOfLine()

