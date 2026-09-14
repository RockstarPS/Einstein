#include "Std_Types.h"

/* OS type definitions */
/* Begin osTypeDefinitions (default) */
typedef unsigned char  osuint8;
typedef unsigned short osuint16;
typedef unsigned long  osuint32;
typedef unsigned long long osuint64;
typedef signed   char  osint8;
typedef signed   short osint16;
typedef signed   long  osint32;
typedef signed long long osint64;
/* End osTypeDefinitions */

/* Boolean definition */
//#ifndef osbool
typedef osuint8 osbool;
//#endif


typedef osuint32                    TickType;
typedef TickType*                   TickRefType;
