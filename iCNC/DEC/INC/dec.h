
// dec.h
#ifndef _DEC_H
#define _DEC_H

#include <stdio.h>
#include "..\..\LINK\INC\link.h"
#include "..\..\UTILITY\INC\utility.h"

#define CHAR_IN_A_LINE_MAX 200

enum DEC_STATE {DEC_INIT,DEC_IDLE,DEC_OPEN_NC_FILE,DEC_LOOP,DEC_WRITE_OUT,DEC_WRITE,DEC_RESET,DEC_WAIT_PGM_END,DEC_ERROR };


struct DEC_DATA
{
	char              ncFileName[200]; 
	FILE              *ncFilePtr;
	DEC_STATE         decState;
	LINE_CMD          linkCmd;
	
	char              *fileBufferPtr;         // buffer for file
	char              lineCommand[200];
	char              *asciiPtr;              // pointer, address in memory

    
	double            lineNumber;
	bool			  markN;	              // markUp if N appears
	bool			  markBlockCommand;       // markUp if commmand appears
	bool			  markM30;
	bool			  markM;
	bool			  markFileEnd;

	bool              relAbs;		          // false G90: abs,  true G91: rel
	bool              markG90G91;             // if exist or not exist simulitaneously->error
	bool              markG;

	//bool			  markRelative;
	double            xyzCoordinate[3];
	bool              xyzCoordinateValid[3];
	double            xyCoordinate[2];        // xy[0], xy[1]
	//bool              xyValid[2];			  // reset at line begin
	int               xyCheck[2];

	double            angle;                   //
	//bool            direction;             // true: CW, false: CCW
	bool			  markAngle;

	double            speed; 
	bool              speedValid;
	bool			  markF;
	DEC_TO_LINK_BLOCK decToLinkBlock;


};

int spaceFunction(DEC_DATA* decDataPtr);
int nFunction(DEC_DATA* decDataPtr);
int gFunction(DEC_DATA* decDataPtr);
int xyFunction(DEC_DATA* decDataPtr);
int endOfLine(DEC_DATA *decDataPtr);
int decWriteOut(DEC_DATA *decDataPtr);
int decAfterWrite(DEC_DATA *decDataPtr);
int decWaitProgramEnd(DEC_DATA *decDataPtr);



//*****************************
// function define
//*****************************

int decInit(DEC_DATA *decDataPtr);
int decIdle(DEC_DATA *decDataPtr);
int decOpenNcFile(DEC_DATA *decDataPtr);
int decPre(DEC_DATA *decDataPtr);
int decLoop(DEC_DATA *decDataPtr);
int endOfLine(DEC_DATA  *decDataPtr);
int decMain(DEC_DATA   *decDataPtr);
int decReset(DEC_DATA   *decDataPtr);
int decError(DEC_DATA *decDataPtr);


#endif 