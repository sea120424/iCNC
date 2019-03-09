#ifndef _LINK_H
#define _LINK_H

enum LINE_CMD {NULL_CMD, G00_CMD, G04_DWELL_TIME, G06_ROT_CW, G07_ROT_CCW, M30_PROG_END};

struct MMI_TO_LINK_DATA
{
	char ncFileName[200];
	bool ncFileValid;
	bool mmiToLinkDataValid;

	bool RESET;
	bool START;
};

struct LINK_TO_MMI_DATA
{
	int     counter;
	double	CarCoordinate[3];
	char	serialCmd[4];
	bool	serialCmdVaild;
	bool    linkToMmiDataValid;
};

struct DEC_TO_LINK_BLOCK
{
	bool			cmdVaild;
	LINE_CMD        linkCmd;
	// full info of one NC line
	double          lineNumber;          // N code
	bool			lineNumberVaild;
	int		        lineCmd;             // ensure that only one effective command!!
	bool			lineCmdVaild;
	bool            relAbs;              // false G90: abs,  true G91: rel
	bool			relVaild;
	double          xyCoordinate[2];     // xy[0], xy[1]
	bool            xyValid[2];          // reset at line begin
	int             xyCheck[2];
	double          angle;
	bool            direction;           // true: CW, false: CCW
	bool			angleVaild;
	double          speed;               // F
	bool            speedValid;
	bool			decToLinkDataValid;
};

struct LINK_TO_DEC_DATA
{
	char ncFileName[200];
	bool ncFileValid;
	bool linkToDecDataValid;

	bool RESET;
	bool START;
};

struct INTP_TO_LINK_DATA
{
	double	CarCoordinate[3];
	char	serialCmd[4];
	bool	serialCmdVaild;
	bool    intpToLinkDataValid;

	bool    RESET;
};

struct LINK_TO_INTP_DATA
{
	bool			cmdVaild;
	// full info of one NC line
	int             lineNumber; // N code
	bool			lineNumberVaild;
	int		        lineCmd;   // ensure that only one effective command!!
	bool			lineCmdVaild;
	bool            relAbs;    // false G90: abs,  true G91: rel
	bool			relVaild;
	double          xyCoordinate[2];    // xy[0], xy[1]
	bool            xyValid[2]; // reset at line begin
	int             xyCheck[2];
	double          angle;
	bool            direction;  // true: CW, false: CCW
	bool			angleVaild;
	double          speed;      // F
	bool            speedValid;
	bool			linkToIntpDataValid;
};

struct LINK_DATA
{
	MMI_TO_LINK_DATA mmiToLinkData;
	LINK_TO_MMI_DATA linkToMmiData;

	DEC_TO_LINK_BLOCK decToLinkData;
	LINK_TO_DEC_DATA linkToDecData;

	INTP_TO_LINK_DATA intpToLinkData;
	LINK_TO_INTP_DATA linkToIntpData;

	
	//FIFO
	DEC_TO_LINK_BLOCK decToLinkBlock[100];
	bool decToIntpValid[100];
	int writeIndex;
	int readIndex;
	
	
};

int linkInit(LINK_DATA* linkDataPtr);

int linkMain(LINK_DATA* linkDataPtr);
int mmiToLinkDataInit(LINK_DATA* linkDataPtr);
int linkToMmiDataInit(LINK_DATA* linkDataPtr);
int decToLinkDataInit(LINK_DATA* linkDataPtr);
int linkToDecDataInit(LINK_DATA* linkDataPtr);
int intpToLinkDataInit(LINK_DATA* linkDataPtr);
int linkToIntpDataInit(LINK_DATA* linkDataPtr);

#endif