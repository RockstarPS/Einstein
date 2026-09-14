/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2001. Visteon Corporation owns all rights to this work and
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
**  Name:               localSemaphores.h
**
**  Description:        This module contains definitions for the creation of
**                      local semaphores within a module.
**
**  Organization:       Driver Information Software Section,
**                      DI Core Engineering Department
**
**==========================================================================*/
#ifndef localSemaphores_H
#define localSemaphores_H


/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "system.h"
#include "string.h"


/*==============================================================================*/
/* A C C E S S   M A C R O S                                                    */
/*==============================================================================*/

#define SEM_SETBIT( operand, bit_mask )    ((operand) |= (bit_mask))
#define SEM_CLEARBIT( operand, bit_mask )  ((operand) &= ((UINT8)~(bit_mask)))

/*------------------------------------------------------------------------------*/
/* MACRO: BUF_SIZE(x)   Returns the size (in bytes) required for the            */
/*                      semaphore buffer                                        */
/*------------------------------------------------------------------------------*/
#define BUF_SIZE(x) ((((UINT32)(x)) + (8UL - (((UINT32)(x)) & 7UL))) >> 3)

/*------------------------------------------------------------------------------*/
/* MACRO: SEM_BYTE(sem)    Returns the byte location for the given semaphore    */
/* MACRO: SEM_BIT(sem)     Returns the bit mask for the given semaphore         */
/*------------------------------------------------------------------------------*/
#define SEM_BYTE(sem)   ( (UINT32)(sem) >> 3)
#define SEM_BIT(sem)    (( 1U << ((UINT32)(sem) & 7U) ))

/*------------------------------------------------------------------------------*/
/* MACRO: LOCAL_SEMAPHORES(name, num)       Creates a semaphore buffer          */
/*------------------------------------------------------------------------------*/
#define LOCAL_SEMAPHORES(sembuf, num)   UINT8 (sembuf)[BUF_SIZE(num)]

/*------------------------------------------------------------------------------*/
/* MACRO: CLEAR_ALL_SEMAPHORES(sembuf)      Clears all semaphores in buffer     */
/* MACRO: SET_ALL_SEMAPHORES(sembuf)        Sets all semaphores in buffer       */
/*------------------------------------------------------------------------------*/
#define CLEAR_ALL_SEMAPHORES(sembuf) (void)memset(((void*)(&(sembuf)[0])), 0, sizeof(sembuf))

/*------------------------------------------------------------------------------*/
/* MACRO: GET_SEMAPHORE(sembuf, sem)   Get semaphore state                      */
/* MACRO: SET_SEMAPHORE(sembuf, sem)   Set semaphore                            */
/* MACRO: CLR_SEMAPHORE(sembuf, sem)   Clear semaphore                          */
/*------------------------------------------------------------------------------*/
#define GET_SEMAPHORE(sembuf, sem) (((sembuf)[SEM_BYTE(sem)] & (UINT8)SEM_BIT(sem)) != (0U))
#define SET_SEMAPHORE(sembuf, sem) ( SEM_SETBIT((sembuf)[SEM_BYTE(sem)], (UINT8)SEM_BIT(sem)) )
#define CLR_SEMAPHORE(sembuf, sem) ( SEM_CLEARBIT((sembuf)[SEM_BYTE(sem)], SEM_BIT(sem)) )

#define COPY_SEMAPHORES(dest, source)   (void)memcpy((dest), (source), sizeof(dest))


/*==========================================================================*/
/* F U N C T I O N  P R O T O T Y P E S                                     */
/*==========================================================================*/
BOOLEAN semCheckAllSemaphores(UINT8 *semBuf, UINT32 semSize);


/*============================================================================
** R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
** PVCS Rev #       Date            By
** PVCS Rev X.X     dd Month yyyy   CDSID
**      Comment
**============================================================================
**
**  12/Oct/2005   by AFERRIS2
**  1.  Specifically ignore return value from memset() and memcpy() functions
**      since these will never be used.
**  2.  Added extra brackets to macros to eliminate QAC warnings.
**
** PVCS Rev 1.0     11/Aug/2004         AFERRIS2
**      Comment
**
**==========================================================================*/

/****************************************************************************
**  Date  : 19/Nov/2008
**  by    : AFERRIS2
**  Ref   :
**  Change: 1.  Correction to macro GET_SEMAPHORE() to eliminate QAC warnings
**              in modules that use this macro.
**
*****************************************************************************/

/****************************************************************************
**  Date: 29/Jun/2015     by: adevi        Ref: RTC 365702
**  Change: QAC warnings resolved for Honda THAA.
*****************************************************************************/

/****************************************************************************
**  Date: 19/May/2015     by: arajase2        Ref: RTC 859438
**  Change: MISRA warnings resolved for CMFB.
*****************************************************************************/

#endif
/* end of file =============================================================*/
