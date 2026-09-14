/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2009. Visteon Corporation owns all rights to this work and
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
**  Name:               warn_SIF.h
**
**  Description:
**
**  Organization:       Driver Information Software Section,
**                      DI Core Engineering Department
**
**===========================================================================*/
#ifndef warn_SIF_H
#define warn_SIF_H

/*==========================================================================*/
/* I N C L U D E   F I L E S                                                */
/*==========================================================================*/
#include "system.h"

/*==========================================================================*/
/* T Y P E   D E F I N I T I O N S                                          */
/*==========================================================================*/

/*----------------------------------------------------------------------*/
/* This is the return type for all standard interface functions.        */
/* Valid values for this type are defined below.                        */
/*----------------------------------------------------------------------*/
typedef UINT8 SIF_STATUS;

/*----------------------------------------------------------------------*/
/* DataStatus_OK: Data is available.  Value has been verified           */
/*----------------------------------------------------------------------*/
#define sif_OK          (0U)

/*----------------------------------------------------------------------*/
/* DataStatus_ERROR: Data is availbale but the value is not valid.      */
/*----------------------------------------------------------------------*/
#define sif_ERROR       (BIT3)

/*----------------------------------------------------------------------*/
/* Common helper macros                                                 */
/*----------------------------------------------------------------------*/
#define SIF_SET_DATA(value)  *msgData = (value)
#define SIF_GET_DATA()       (*msgData)
#define SIF_GET_DATA_REF()   (msgData)
#define SIF_ISVALID_DATA() (NULL != msgData)



#if defined SIF_SUPPORT_EXTENDED_QUALIFIER
/*----------------------------------------------------------------------*/
/* Helper macros for extended interface                                 */
/*----------------------------------------------------------------------*/
#define NULSIF_STANDARD_INTERFACE(name) SIF_STATUS name(void *msgData, void *Qualifier)
#define U08SIF_STANDARD_INTERFACE(name) SIF_STATUS name(UINT8 *msgData, UINT8 *Qualifier)
#define U16SIF_STANDARD_INTERFACE(name) SIF_STATUS name(UINT16 *msgData, UINT16 *Qualifier)
#define U32SIF_STANDARD_INTERFACE(name) SIF_STATUS name(UINT32 *msgData, UINT32 *Qualifier)

typedef SIF_STATUS (*U08SIF_GET_DATA)(UINT8 *msgData, UINT8 *Qualifier);
typedef SIF_STATUS (*U16SIF_GET_DATA)(UINT16 *msgData, UINT16 *Qualifier);
typedef SIF_STATUS (*U32SIF_GET_DATA)(UINT32 *msgData, UINT32 *Qualifier);

#define SIF_EXEC(name, sifData, sifQualifier) (name(&(sifData), &(sifQualifier)))


#define SIF_ISVALID_QUALIFIER() (NULL != Qualifier)
#define SIF_GET_QUALIFIER() (*Qualifier)

#else
/*----------------------------------------------------------------------*/
/* Helper macros for standard interface                                 */
/*----------------------------------------------------------------------*/
#define NULSIF_STANDARD_INTERFACE(name) SIF_STATUS name(void *msgData)
#define NULSIF_STANDARD_INTERFACE_MULTI_INST(name) SIF_STATUS name(void *msgData,UINT8 p_inst)
#define U08SIF_STANDARD_INTERFACE(name) SIF_STATUS name(UINT8 *msgData, UINT8 Qualifier)
#define U16SIF_STANDARD_INTERFACE(name) SIF_STATUS name(UINT16 *msgData, UINT16 Qualifier)
#define U32SIF_STANDARD_INTERFACE(name) SIF_STATUS name(UINT32 *msgData, UINT32 Qualifier)
#define U32SIF_STANDARD_INTERFACE_MULTI_INST(name) SIF_STATUS name(UINT32 *msgData, UINT32 Qualifier,UINT8 p_inst)

typedef SIF_STATUS (*U08SIF_GET_DATA)(UINT8 *msgData, UINT8 Qualifier);
typedef SIF_STATUS (*U16SIF_GET_DATA)(UINT16 *msgData, UINT16 Qualifier);
typedef SIF_STATUS (*U16SIF_GET_DATA_MULTI_INST)(UINT16 *msgData, UINT16 Qualifier,UINT8 inst);
typedef SIF_STATUS (*U32SIF_GET_DATA)(UINT32 *msgData, UINT32 Qualifier);
typedef UINT16 (*U16_GET_DATA)(UINT16 Id);

#define SIF_EXEC_INST(name, sifData, sifQualifier,inst) (name(&(sifData), (sifQualifier),(inst)))
#define SIF_EXEC(name, sifData, sifQualifier) (name(&(sifData), (sifQualifier)))

#define SIF_GET_QUALIFIER() (Qualifier)
#define SIF_ISVALID_QUALIFIER() (FALSE == FALSE)

#endif

/*==========================================================================*/
/* E N T R Y   P O I N T S                                                  */
/*==========================================================================*/

/*==========================================================================*/
/* F U N C T I O N  P R O T O T Y P E S                                     */
/*==========================================================================*/

/*==========================================================================*/
/* R E V I S I O N    N O T E S                                             */
/*==========================================================================*/
/* For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**==========================================================================*/

/****************************************************************************
**  Date  : 05/May/2010
**  by    : AFERRIS2
**  Ref   : None.
**  Change: Initial version.
**
*****************************************************************************/

/****************************************************************************
**  Date: 08/Jul/2010     by: AFERRIS2        Ref:
**  Change: 1.  Add new macro SIF_GET_DATA_REF()
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/
/****************************************************************************
**  Date: 10/Feb/2015     by: adevi        Ref:
**  Change: Compiler warnings resolved for Honda THAA
*****************************************************************************/
/****************************************************************************
**  Date: 14/Jun/2017     by: arajase2
**  Ref: RTC 888114: CMFB MISRA Warning fixes message core- SPRINT 43
**  Change: MISRA warnings resolved for CMFB
*****************************************************************************/

#endif  /* warn_SIF_H */
/* end of file =============================================================*/
