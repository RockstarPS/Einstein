/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2020. Visteon Corporation owns all rights to           *
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
#ifndef E2EXF_H
#define E2EXF_H
/*****************************************************************************
*  File Name         :  E2E_Xf_H                                             *
*  Module Short Name :  E2E_Xf_H                                             *
*  Description       :                                                       *
*                                                                            *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :  Platform Independent                                   *
*                                                                            *
******************************************************************************/
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Std_Types.h"
#include "E2EXf_Cfg.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
typedef struct
{
    uint16 var; /* dummy variable to remove compilation error*/
    /*As per SWS spec, this is implemetation specific, and this should be updated as per requirement*/
} E2EXf_ConfigType;
/*****************************************************************************
*                            External Function Declarations	     		     *
******************************************************************************/
#define E2EXF_CODE_SEC_START
#include "MemMap.h"
/*============================================================================
**
** Function Name    :   E2EXf_<transformerId>
**
** Visibility       :   Public
**
** Description      :   Protects the array/buffer to be transmitted, using the in-place transformation
**
** Invocation       :
**
** Inputs           :   buffer - This argument is only an INOUT argument for E2E transformers
**						bufferLength - Used length of the buffer
**                      inputBuffer - This argument holds the E2E transformer’s input data
**                      inputBufferLength - This argument holds the length of the E2E transformer’s input data
** Outputs          :	uint8
**
** Critical Section :	NA
**
**==========================================================================*/
extern FUNC(uint8, E2EXF_CODE_SEC_START) E2EXf_transformerId(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);

/*============================================================================
**
** Function Name    :   E2EXf_Inv_<transformerId>
**
** Visibility       :   Public
**
** Description      :   Checks the received data.
**
** Invocation       :
**
** Inputs           :   buffer - This argument is only an INOUT argument for E2E transformers
**						bufferLength - Used length of the buffer
**                      inputBuffer - This argument holds the E2E transformer’s input data
**                      inputBufferLength - This argument holds the length of the E2E transformer’s input data
** Outputs          :	uint8
**
** Critical Section :	NA
**
**==========================================================================*/
extern FUNC(uint8, E2EXF_CODE_SEC_START) E2EXf_Inv_transformerId(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);

/*============================================================================
**
** Function Name    :   E2EXf_Init
**
** Visibility       :   Public
**
** Description      :   Initializes the state of the E2E Transformer
**
** Invocation       :
**
** Inputs           :   E2EXf_ConfigType* config - Pointer to a selected configuration structure
**
** Outputs          :	void
**
** Critical Section :	NA
**
**==========================================================================*/
extern FUNC(void, E2EXF_CODE_SEC_START) E2EXf_Init(const E2EXf_ConfigType* config);

/*============================================================================
**
** Function Name    :   E2EXf_DeInit
**
** Visibility       :   Public
**
** Description      :   Deinitializes the E2E transformer.
**
**
** Invocation       :
**
** Inputs           :   void
**
** Outputs          :	void
**
** Critical Section :	NA
**
**==========================================================================*/
extern FUNC(void, E2EXF_CODE_SEC_START) E2EXf_DeInit(void);

/*============================================================================
**
** Function Name    :   E2EXf_ GetVersionInfo
**
** Visibility       :   Public
**
** Description      :   Returns the version information of this module.
**
** Invocation       :
**
** Inputs           :   Std_VersionInfoType* versioninfo
**
** Outputs          :	void
**
** Critical Section :	NA
**
**==========================================================================*/
extern FUNC(void, E2EXF_CODE_SEC_START) E2EXf_GetVersionInfo(Std_VersionInfoType* versioninfo);

#define E2EXF_CODE_SEC_END
#include "MemMap.h"

#endif

/*============================================================================
**============================================================================
** R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
**===========================================================================*/
/*----------------------------------------------------------------------------
Date               : 7-June-2020
CDSID              : pangraje
Traceability       : RTC #
Change Description : Initial Framework version of E2E Transformer Module
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/
