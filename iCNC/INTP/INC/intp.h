
#ifndef _INTP_H
#define _INTP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\..\LINK\INC\link.h"
#include "..\..\UTILITY\INC\utility.h"


enum INTP_STATE {INTP_INIT,INTP_IDLE,INTP_PRE,INTP_EXE,INTP_CLOSE,INTP_ERROR,INTP_DWELL_TIME,INTP_M30_PROGRAM_END};

struct INTP_DATA
{
	INTP_STATE	        intpState;
	DEC_TO_LINK_BLOCK   decToLinkBlock; // read from LINK, generate by DEC after decoding a NC line

	//coordinate management data
	double              startPos[2];
	double              endPos[2];
	double              newPos[2];  // real-time new
	double              oldPos[2];  // last one
	double              nowPos[2];
	double              nowAngel;

	//parameters for interpolation
	double              totalLength;
	double              sumLength;
	double              residualLength;  // sum(已經過距離) + residual(剩下距離) = total(全程)

	double				linearFactor[2];
	double				momtSpeed;       // 瞬時速度 F
	double				cyclingTime;     //in[s], cycle time of real - time RT timer

};

int intpInit(INTP_DATA   *intpDataPtr);
int intpIdle(INTP_DATA   *intpDataPtr);
int intpPre(INTP_DATA   *intpDataPtr);
int intpExe(INTP_DATA   *intpDataPtr);
int intpClose(INTP_DATA   *intpDataPtr);
int intpError(INTP_DATA   *intpDataPtr);
int intpDwellTime(INTP_DATA   *intpDataPtr);


#endif 