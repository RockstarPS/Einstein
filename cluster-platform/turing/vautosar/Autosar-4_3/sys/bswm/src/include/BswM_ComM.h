
/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2024. Visteon Corporation owns all rights to           *
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
*  File Name         :  BswM_ComM.header                                          *
*  Module Short Name :  Private header                                       *
*  Description       :  Private inclusion for BswM                           *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :  Platform Independent                                   *
*                                                                            *
******************************************************************************/
#ifndef BSWM_COMM_H
#define BSWM_COMM_H
/* BswM_ComM.h */

#include "Rte_Type.h"

#define BSWM_CODE_SEC_START
#include "MemMap.h"
/**********************************************************************************************************************
 *  BswM_ComM_CurrentMode()
 *********************************************************************************************************************/
/*! \brief      Function called by ComM to indicate the current communication mode of a ComM channel.
 * \details     Passed RequestedMode is stored and depending rules are arbitrated.
 * \param[in]   Network       The ComM communication channel that the indicated state corresponds to.
 * \param[in]   RequestedMode The current state of the ComM communication channel.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for different networks
 * \synchronous TRUE
 * \config      BSWM_ENABLE_COMM
 * \trace       SPEC-7782, SPEC-7924, SPEC-7863, SPEC-7903
 */
extern FUNC(void, BSWM_CODE_SEC_START) BswM_ComM_CurrentMode(NetworkHandleType Network, ComM_ModeType RequestedMode);
extern FUNC(void, BSWM_CODE_SEC_START) BswM_ComM_InitiateReset(void);

#define BSWM_CODE_SEC_END
#include "MemMap.h"

#endif /*BSWM_COMM_H*/

