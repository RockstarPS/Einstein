/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2008. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation.
**
**============================================================================
**
** Name:           system.h
**
** Description:    System definition file -- data types, useful macros, etc
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**============================================================================
**
**==========================================================================*/
#ifndef SYSTEM_H
#define SYSTEM_H


/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/


/*
**  Base data types
*/
typedef unsigned char   UINT8;
typedef   signed char   SINT8;
typedef unsigned char   UINT08;
typedef   signed char   SINT08;
typedef unsigned short  UINT16;
typedef   signed short  SINT16;
typedef unsigned long    UINT32;
typedef   signed long    SINT32;
typedef unsigned char   BOOLEAN;

/*
**  Derived types (legacy only)
*/
typedef UINT8   UBYTE;
typedef SINT8   SBYTE;
typedef UINT16  UWORD;
typedef SINT16  SWORD;
typedef UINT32  ULONG;
typedef SINT32  SLONG;

/*
**  Base data type modifiers
*/
/*
#define NEAR
#define FAR
*/
/*
**  Base function type modifiers
*/
/*
#define INTERRUPT
#define FARFUNC
#define NEARFUNC
#define REENTRANT
*/
/*
** Common function mimicking macros
*/

/*
**  If a definition of NULL isn't provided, then define it here
*/


/*
** Define TRUE and FALSE if not already defined
*/

#if !defined( TRUE )
  #define TRUE  ((BOOLEAN) 1)
#endif

#if !defined( FALSE )
  #define FALSE ((BOOLEAN) 0)
#endif

/*
** Define some useful macros
*/
#define TESTBIT( operand, bit_mask )   (((operand) &  (bit_mask)) != ((bit_mask) - (bit_mask)))
#define SETBIT( operand, bit_mask )    ((operand) |= (bit_mask))

#ifdef QAC71
 #define CLEARBIT( operand, bit_mask )  ((operand) &= (~(bit_mask)))
#else
 #define CLEARBIT( operand, bit_mask )  ((operand) &= ((UINT32)~(bit_mask)))
#endif

/*
**  Define normal "bit" position mask definitions 0 is least significant 32 is most significant
*/
#if !defined( BIT0 )
  #define BIT0    (0x01)
#endif
#if !defined( BIT1 )
  #define BIT1    (0x02)
#endif
#if !defined( BIT2 )
  #define BIT2    (0x04)
#endif
#if !defined( BIT3 )
  #define BIT3    (0x08)
#endif
#if !defined( BIT4 )
  #define BIT4    (0x10)
#endif
#if !defined( BIT5 )
  #define BIT5    (0x20)
#endif
#if !defined( BIT6 )
  #define BIT6    (0x40)
#endif
#if !defined( BIT7 )
  #define BIT7    (0x80)
#endif
#if !defined( BIT8 )
  #define BIT8    (0x0100u)
#endif
#if !defined( BIT9 )
  #define BIT9    (0x0200u)
#endif
#if !defined( BIT10 )
  #define BIT10   (0x0400u)
#endif
#if !defined( BIT11 )
  #define BIT11   (0x0800u)
#endif
#if !defined( BIT12 )
  #define BIT12   (0x1000u)
#endif
#if !defined( BIT13 )
  #define BIT13   (0x2000u)
#endif
#if !defined( BIT14 )
  #define BIT14   (0x4000u)
#endif
#if !defined( BIT15 )
  #define BIT15   (0x8000u)
#endif
#if !defined( BIT16 )
  #define BIT16   (0x00010000u)
#endif
#if !defined( BIT17 )
  #define BIT17   (0x00020000u)
#endif
#if !defined( BIT18 )
  #define BIT18   (0x00040000u)
#endif
#if !defined( BIT19 )
  #define BIT19   (0x00080000u)
#endif
#if !defined( BIT20 )
  #define BIT20   (0x00100000u)
#endif
#if !defined( BIT21 )
  #define BIT21   (0x00200000u)
#endif
#if !defined( BIT22 )
  #define BIT22   (0x00400000u)
#endif
#if !defined( BIT23 )
  #define BIT23   (0x00800000u)
#endif
#if !defined( BIT24 )
  #define BIT24   (0x01000000u)
#endif
#if !defined( BIT25 )
  #define BIT25   (0x02000000u)
#endif
#if !defined( BIT26 )
  #define BIT26   (0x04000000u)
#endif
#if !defined( BIT27 )
  #define BIT27   (0x08000000u)
#endif
#if !defined( BIT28 )
  #define BIT28   (0x10000000u)
#endif
#if !defined( BIT29 )
  #define BIT29   (0x20000000u)
#endif
#if !defined( BIT30 )
  #define BIT30   (0x40000000u)
#endif
#if !defined( BIT31 )
  #define BIT31   (0x80000000u)
#endif

/*
**  Define Spectrum "bit" position mask definitions 0 is most significant 31 is least significatn
*/
#if !defined( MPC_BIT31 )
  #define MPC_BIT31    (0x01ul)
#endif
#if !defined( MPC_BIT30 )
  #define MPC_BIT30    (0x02ul)
#endif
#if !defined( MPC_BIT29 )
  #define MPC_BIT29    (0x04ul)
#endif
#if !defined( MPC_BIT28 )
  #define MPC_BIT28    (0x08ul)
#endif
#if !defined( MPC_BIT27 )
  #define MPC_BIT27    (0x10ul)
#endif
#if !defined( MPC_BIT26 )
  #define MPC_BIT26    (0x20ul)
#endif
#if !defined( MPC_BIT25 )
  #define MPC_BIT25    (0x40ul)
#endif
#if !defined( MPC_BIT24 )
  #define MPC_BIT24    (0x80ul)
#endif
#if !defined( MPC_BIT23 )
  #define MPC_BIT23    (0x0100ul)
#endif
#if !defined( MPC_BIT22 )
  #define MPC_BIT22    (0x0200ul)
#endif
#if !defined( MPC_BIT21 )
  #define MPC_BIT21   (0x0400ul)
#endif
#if !defined( MPC_BIT20 )
  #define MPC_BIT20   (0x0800ul)
#endif
#if !defined( MPC_BIT19 )
  #define MPC_BIT19   (0x1000ul)
#endif
#if !defined( MPC_BIT18 )
  #define MPC_BIT18   (0x2000ul)
#endif
#if !defined( MPC_BIT17 )
  #define MPC_BIT17   (0x4000ul)
#endif
#if !defined( MPC_BIT16 )
  #define MPC_BIT16   (0x8000ul)
#endif
#if !defined( MPC_BIT15 )
  #define MPC_BIT15   (0x00010000ul)
#endif
#if !defined( MPC_BIT14 )
  #define MPC_BIT14   (0x00020000ul)
#endif
#if !defined( MPC_BIT13 )
  #define MPC_BIT13   (0x00040000ul)
#endif
#if !defined( MPC_BIT12 )
  #define MPC_BIT12   (0x00080000ul)
#endif
#if !defined( MPC_BIT11 )
  #define MPC_BIT11   (0x00100000ul)
#endif
#if !defined( MPC_BIT10 )
  #define MPC_BIT10   (0x00200000ul)
#endif
#if !defined( MPC_BIT9 )
  #define MPC_BIT9   (0x00400000ul)
#endif
#if !defined( MPC_BIT8 )
  #define MPC_BIT8   (0x00800000ul)
#endif
#if !defined( MPC_BIT7 )
  #define MPC_BIT7   (0x01000000ul)
#endif
#if !defined( MPC_BIT6 )
  #define MPC_BIT6   (0x02000000ul)
#endif
#if !defined( MPC_BIT5 )
  #define MPC_BIT5   (0x04000000ul)
#endif
#if !defined( MPC_BIT4 )
  #define MPC_BIT4   (0x08000000ul)
#endif
#if !defined( MPC_BIT3 )
  #define MPC_BIT3   (0x10000000ul)
#endif
#if !defined( MPC_BIT2 )
  #define MPC_BIT2   (0x20000000ul)
#endif
#if !defined( MPC_BIT1 )
  #define MPC_BIT1   (0x40000000ul)
#endif
#if !defined( MPC_BIT0 )
  #define MPC_BIT0   (0x80000000ul)
#endif

/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/


/*============================================================================
** D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/


/*============================================================================
**
**============================================================================
** C M S    R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
** CMS Rev #        Date         By
** CMS Rev X.X      mm/dd/yy     CDSID
**
**============================================================================
**  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
**  Date  : 20/08/2014
**  by    : rchiluvu
**  Ref   : -------
**  Change: 179391: Revise Core 'cst05' asset to include MPC5605B and MPC5606B processor support
**  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** RTC \main\unofficial release for ss-INFRASTRUCTURE_CST05_2.14.02 10-Jul-14   ssukuma1
**                     RTC-179391 - change which should support both MPC5605B and 
**                     MPC5606B processors within the cst05 core asset.
**
**
** RTC \main\official release for ss-INFRASTRUCTURE_CST05_2.13 10-Jan-14   dkasiman
**                     RTC-104943:RAINBOW,RAINBOW_LITE,SPECTRUM and BOLERO micro definitions
**                     moved from ivectors$.cfg
**
** Clearcase main\9  10/15/2012    krohini
**                    Updated macros DISABLE_INTERRUPTS(), ENABLE_INTERRUPTS(),
**                    and NOP().
**
** Clearcase main\8  03/17/2011    wderouch
**                    Update Rainbow lite rom size to 1.5Mb
**
** Clearcase main\7  09/10/2010    jarun
**                    BSDI00086895 - Add support for Bolero micro
**                    Merged from csmith47 einstein_2.0_dev branch.
**
** Clearcase main\3  06/25/2010     wderouch
**                    updated for Rainbow lite
**
** Clearcase main\2   01/06/2010     wderouch
**                    Added support for Rainbow
**
**
**      M I G R A T I O N  T O  S E R V I C E S  S S  V O B
**
** CMS Rev main/1   11/11/08     JKANOZA
** Initial revision.
**
**==========================================================================*/

/* end of file =============================================================*/

#endif


