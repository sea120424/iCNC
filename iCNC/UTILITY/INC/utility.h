#ifndef _UTILITY_H
#define _UTILITY_H
#define TAB		0x09


int clearByteSpace(char *startPtr, int  size);

char *passDigit(char *asciiPtr);
bool isDigit(char * asciiPtr);

char *passSpace(char* asciiPtr);

char *passFloat(char * asciiPtr);
bool isFloat(char * asciiPtr);

#endif