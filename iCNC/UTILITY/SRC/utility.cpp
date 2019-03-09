#include "StdAfx.h"
#include <stdio.h>
#include <stdlib.h>

#include "..\INC\utility.h"
//***************************************************************
// clear memory data in a struct of any size.
//***************************************************************

int clearByteSpace(char *startPtr, int  size)
{
	for (int i = 0; i < size; i++)
	{
	    *startPtr = 0;
		startPtr++;  // pointer addition
		             // ++ = +4 byte for pointer of int
	}

	return 1;
} // clearByteSpace()


//***************************************************************
// 
//***************************************************************

bool isDigit(char * asciiPtr)
{
	if((*asciiPtr >= '0' ) &&  (*asciiPtr <= '9' ))
	{
		return true;
	}
	else
	{
		return false;
	}
}


//***************************************************************
// 
//***************************************************************



char *passDigit(char *asciiPtr)
{
    while(isDigit(asciiPtr) == true)
	{
		asciiPtr++;  // pass digit
	}

	return asciiPtr;
}

//***************************************************************
// 
//***************************************************************


bool isFloat(char * asciiPtr)
{
	int check = 0;
	if((*asciiPtr >= '+' ) &&  (*asciiPtr <= '-' ))
	{
		asciiPtr++;
	}
	else if((*asciiPtr >= '0' ) &&  (*asciiPtr <= '9' ))
	{
		asciiPtr++;
		
		while(*asciiPtr >= '.' && check != -1)
		{
			check = -1;
			asciiPtr++;
		}
		return true;
	}
	else
	{
		return false;
	}
	
}


//***************************************************************
// 
//***************************************************************



char *passFloat(char * asciiPtr)
{
	while(isFloat(asciiPtr) == true)
	{
		asciiPtr++;  // pass digit
	}
		 	
	return asciiPtr;
}



//***************************************************************
// 
//***************************************************************


char *passSpace(char* asciiPtr)
{

	while( *asciiPtr == ' ' || *asciiPtr == TAB)
	{
		asciiPtr++;
	}

	return asciiPtr;
}//passSpace()


//***************************************************************
// 
//***************************************************************


