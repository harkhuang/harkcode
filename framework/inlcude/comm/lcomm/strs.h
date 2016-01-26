/***************************************************/
#ifndef _STRS_H_
#define _STRS_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/***********************************************************************************/
bool StrTrim(char * Str);
/***********************************************************************************/
bool StrRemoveAllSpace(char * Str);
/***********************************************************************************/
bool StrRemoveRedundantSpace(char * Str);
/***********************************************************************************/
void StrToUpper(char * Str);
/***********************************************************************************/
void StrToLower(char * Str);
/***********************************************************************************/
int  StrReplace(char * srcstr, const char * oldstr, const char * newstr);
/**********************************************************************************/
bool StrIsDigit(char * Str);

char * GetDataValue(char *src, char *dest , int nmaxlen, int num, char ch);


#endif

