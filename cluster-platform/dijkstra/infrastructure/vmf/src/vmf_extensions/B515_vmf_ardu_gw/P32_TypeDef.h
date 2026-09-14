#ifndef _PN3030_TYPE_DEF_H_
#define _PN3030_TYPE_DEF_H_

#define USE_32BIT_PROCESSOR

#ifdef USE_32BIT_PROCESSOR
#define PN_INTERNAL         static
#define PN_EXTERN           extern

typedef signed char         PN_S8;
typedef unsigned char       PN_U8;
typedef signed short        PN_S16;
typedef unsigned short      PN_U16;
typedef char                PN_CHAR;
typedef unsigned short      PN_WCH;
typedef signed long         PN_S32;
typedef unsigned long       PN_U32;
typedef long                PN_LONG;
typedef	float               PN_FLOAT;
typedef unsigned long       PN_ULONG;
typedef unsigned char       PN_BOOL;
typedef void                PN_VOID;
typedef double		    PN_DBL;
#endif


#define PN_FN_OK    		(0)
#define PN_FN_CONTINUE		(2)
#define PN_FN_FICRESTART	(3)
#define PN_FN_RESTART		(3)
#define PN_FN_FAIL  		(-1)
#define PN_FN_NOT_SUPPORT	(-2)
#define PN_FN_INV_STD		(-3)
#define PN_UNLOCK               (-10)
#define PN_SCAN_FAIL            (-20)


#define TRUE			1
#define FALSE			0
#endif