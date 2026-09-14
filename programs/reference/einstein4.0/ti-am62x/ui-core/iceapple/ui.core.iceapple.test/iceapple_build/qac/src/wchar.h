/****************************************************************************/
/*                            COPYRIGHT STATEMENT                           */
/*                     CONFIDENTIAL - VISTEON CORPORATION                   */
/* This is an unpublished work, which contains trade secrets, created in    */
/* 2007. Visteon Corporation owns all rights to this work and intends       */
/* to maintain it in confidence to preserve its trade secret status. Visteon*/
/* Corporation reserves the right, under the copyright laws of the United   */
/* States or those of any other country that may have jurisdiction, to      */
/* protect this work as an unpublished copyright work in the event of an    */
/* inadvertent or deliberate unauthorized publication. Visteon Corporation  */
/* also reserves its rights under the copyright laws to protect this work   */
/* as a published work, when appropriate. Those having access to this work  */
/* may not copy it, use it or disclose the information contained in it      */
/* without the written authorization of Visteon Corporation.                */
/****************************************************************************/
/*****************************************************************************

File Name        :  whar.h
Module Short Name:  whar
VOBName          :  sw_hmi_ss\06_components\widechar_lib\03_code
Author           :  rgopalak
Description      :  This file defines the interfaces for wchar functions

Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef WCHAR_H
#define WCHAR_H
#ifndef WCHAR_C
#define EXTERN  extern
#else
#define EXTERN
#endif

#include "stddef.h"
/*****************************************************************************
* Constant Declarations                                                      *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the constant.                                                        *
* purpose, unit, and resolution                                              *
*****************************************************************************/
#define WC_GOLBAL_RAM_PTR   /*@far @gpage */

/*****************************************************************************
* Global Macro Definitions                                                   *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
*****************************************************************************/

/*****************************************************************************
* Type Decleration                                                           *
*----------------------------------------------------------------------------*
* Decleration of type shall be accompanied by a comment that explains the    *
* purpose and usage of the type.                                             *
*****************************************************************************/
/*
#ifndef _WCHAR_T_DEFINED
typedef unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif*/

#ifndef WEOF
#define WEOF (0xffffffff)

#endif

typedef struct
{
	wchar_t start;
	wchar_t end;
}WCHAR_SET;

typedef struct
{
	WCHAR_SET capital;
	WCHAR_SET small;
	int offset;			/* Offset from Capital to Small letter */
}WCHAR_TABLE;

/*****************************************************************************
* Global Variable Declarations                                               *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, resolution, Valid Range and ValidityCheck *
*****************************************************************************/

/*****************************************************************************
* Global Function Prototypes                                                 *
*****************************************************************************/
EXTERN WC_GOLBAL_RAM_PTR wchar_t *wcscat(WC_GOLBAL_RAM_PTR wchar_t *ws1, \
                                         WC_GOLBAL_RAM_PTR const wchar_t *ws2);

EXTERN WC_GOLBAL_RAM_PTR wchar_t *wcsncat(WC_GOLBAL_RAM_PTR wchar_t *p_string_1, \
                                          WC_GOLBAL_RAM_PTR const wchar_t *p_string_2, \
                   size_t p_max_length);

EXTERN SINT8 wcscmp(WC_GOLBAL_RAM_PTR const wchar_t *p_string_1, \
                      WC_GOLBAL_RAM_PTR const wchar_t *p_string_2);

EXTERN SINT8 wcsncmp(WC_GOLBAL_RAM_PTR const wchar_t *p_string_1, \
                       WC_GOLBAL_RAM_PTR const wchar_t *p_string_2, \
               size_t p_max_length);

EXTERN WC_GOLBAL_RAM_PTR wchar_t * wcscpy(WC_GOLBAL_RAM_PTR wchar_t *p_destination, \
                                          WC_GOLBAL_RAM_PTR const wchar_t *p_source);

EXTERN WC_GOLBAL_RAM_PTR wchar_t * wcsncpy(WC_GOLBAL_RAM_PTR wchar_t *p_destination, \
                                           WC_GOLBAL_RAM_PTR const wchar_t *p_source, \
                  size_t p_max_length);

EXTERN UINT8 wcslen(WC_GOLBAL_RAM_PTR const wchar_t* p_string);

EXTERN UINT8 iswlower(wchar_t wc);

EXTERN UINT8 iswupper(wchar_t wc);

EXTERN UINT8 iswspace(wchar_t wc);

EXTERN UINT8 iswascii(wchar_t wc);

EXTERN SINT16 swprintf(WC_GOLBAL_RAM_PTR wchar_t *wbuff, size_t maxlen, \
                         WC_GOLBAL_RAM_PTR wchar_t *format, ...);

EXTERN wchar_t towupper(wchar_t wc);

EXTERN wchar_t towlower(wchar_t wc);

EXTERN void wchar_init(WC_GOLBAL_RAM_PTR WCHAR_TABLE *table);

EXTERN wchar_t btowc(unsigned char chr);

EXTERN UINT32 wchartolong(UINT16 * wcbuff);


#undef EXTERN
#endif

/*End of File*/
/*****************************************************************************
*   for each change to this file, be sure to record:                         *
*      1.  who made the change and when the change was made                  *
*      2.  why the change was made and the intended result                   *
*   Following block needs to be repeated for each change                     *
******************************************************************************
*   Note: In the traceability column we need to trace back to the Design Doc.*
*   For the initial version it is traced to the Design Document section.     *
*   For further changes it shall trace to the source of the change which may *
*   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  *
*   other reason                                                             *
*****************************************************************************/
/*----------------------------------------------------------------------------
Date              : 
By                : 
Traceability      : 
Change Description: 
----------------------------------------------------------------------------*/



