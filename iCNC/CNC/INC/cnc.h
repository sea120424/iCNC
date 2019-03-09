#ifndef _CNC_H
#define _CNC_H
#include "..\..\DEC\INC\dec.h" 
#include "..\..\MMI\INC\mmi.h" 
#include "..\..\LINK\INC\link.h" 
#include "..\..\UTILITY\INC\utility.h"



struct CNC_DATA
{
   DEC_DATA         decData;
   MMI_DATA         mmiData;
   //SYS_DATA         sysData;
   //INTP_DATA		intpData;
   //LINK_DATA       *linkDataPtr = &linkData;
	LINK_DATA       linkData;	                

};

int cncInit(void);
int nrtMain(void);
int rtMain(void);
#endif