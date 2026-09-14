/*=============================================================================
**              CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2000. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have  jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation
**
**=============================================================================
**
**  Name:          ViewLampcdd.h
**
**
**
**  Organization:   Driver Information Software Section,
**                  DI Core Engineering Department
**
**============================================================================
**
** $Revision:   1.0  $
** $Date:   25 Jul 2016   $
** $Author:   kpalama1  $
**
**==========================================================================
**============================================================================
**
** $Revision:   2.0  $
** $Date:   20 Sep 2016   $
** $Author:   kpalama1  $
**
**==========================================================================*/
#ifndef View_Telltale_H
#define View_Telltale_H

/*============================================================================
**                 I N C L U D E   F I L E S
**==========================================================================*/

/*============================================================================
** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
**==========================================================================*/

#define BYTE (uint8)8

#define TT_OUTPUT_BYTES ((TT_TOTAL_NUM_OF_TELLTALES/(uint8)8) +(uint8)1)

#define SETBIT( operand, bit_mask )         ((operand) |= (bit_mask))

#define CLEARBIT( operand, bit_mask )       ((operand) &= (~(bit_mask)))


/* Function Declarations */

void ViewTelltale_SendTelltaleStatus(uint8 index, uint8 TT_status);





#endif




/*-----------------------------------------------------------------------------
Date              : 16-08-2024
CDSID             : ckulothu 
Traceability      : DICMBD-164 MainScreen-TFT Telltales manager from Bookshelf
Change Description: View_Telltale file update for 7XXD Program (Initial Version)
-----------------------------------------------------------------------------*/
