#ifndef SYSTEM_H
#define SYSTEM_H

/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2010. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/

/*****************************************************************************

File Name        :  system.h
Module Short Name:  CST08
VOBName          :  sw_services_ss\cst08_c_infrastructure_sh72xx\03_code\src
                    \system.h
Author           :  nshivapr
Description      :  Implementation file for typedefs and macro definitions. 
Organization     :  Driver Information Software Section,
                    Visteon Corporation
----------------------------------------------------------------------------
Compiler Name    :  Renesas SH Compiler v.9.02,v.9.03
Target Processor :  Renesas SH7262,SH7268 and SH7269
******************************************************************************/


/* ===========================================================================
**  convert ECLK define to Hcs08 format
** ==========================================================================*/



    typedef unsigned char   UINT8;
    typedef   signed char   SINT8;
    typedef unsigned int    UINT16;
    typedef   signed int    SINT16;
    typedef unsigned long   UINT32;
    typedef   signed long   SINT32;
    typedef unsigned char   BOOLEAN;

typedef UINT8   UBYTE;
typedef SINT8   SBYTE;
typedef UINT16  UWORD;
typedef SINT16  SWORD;
typedef UINT32  ULONG;
typedef SINT32  SLONG;

    #define NEAR
    #define FAR

    #define FARFUNC


#define BIT0    (0x01)
#define BIT1    (0x02)
#define BIT2    (0x04)
#define BIT3    (0x08)
#define BIT4    (0x10)
#define BIT5    (0x20)
#define BIT6    (0x40)
#define BIT7    (0x80)
#define BIT8    (0x0100u)
#define BIT9    (0x0200u)
#define BIT10   (0x0400u)
#define BIT11   (0x0800u)
#define BIT12   (0x1000u)
#define BIT13   (0x2000u)
#define BIT14   (0x4000u)
#define BIT15   (0x8000u)
#define BIT16   (0x00010000uL)
#define BIT17   (0x00020000uL)
#define BIT18   (0x00040000uL)
#define BIT19   (0x00080000uL)
#define BIT20   (0x00100000uL)
#define BIT21   (0x00200000uL)
#define BIT22   (0x00400000uL)
#define BIT23   (0x00800000uL)
#define BIT24   (0x01000000uL)
#define BIT25   (0x02000000uL)
#define BIT26   (0x04000000uL)
#define BIT27   (0x08000000uL)
#define BIT28   (0x10000000uL)
#define BIT29   (0x20000000uL)
#define BIT30   (0x40000000uL)
#define BIT31   (0x80000000uL)


#if !defined( NULL )
    #define NULL    ((void *) 0)
#endif

/*
**
*/
#define TESTBIT( operand, bit_mask )        (((operand) &  (bit_mask)) != ((bit_mask) - (bit_mask)))
#define SETBIT( operand, bit_mask )         ((operand) |= (bit_mask))
#define CLEARBIT( operand, bit_mask )       ((operand) &= ((UINT32)~(bit_mask)))

#if !defined( FALSE )
    #define FALSE   ((BOOLEAN) 0)
#endif

#if !defined( TRUE )
    #define TRUE    ((BOOLEAN) 1)
#endif

/*
** define is_true and is_false
*/
#define IS_TRUE(x) (x != FALSE)
#define IS_FALSE(x) (x == FALSE)



#endif
