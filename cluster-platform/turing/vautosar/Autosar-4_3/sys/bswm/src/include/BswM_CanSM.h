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
*  File Name         :  BswM_CanSM.header                                    *
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
#ifndef BSWM_CANSM_H
#define BSWM_CANSM_H /*BSWM_CANSM_H*/

# include "CanSM_BswM.h"

#define BSWM_CODE_SEC_START
#include "MemMap.h"
/**********************************************************************************************************************
 *  BswM_CanSM_CurrentState()
 *********************************************************************************************************************/
/*! \brief      Function called by CanSM to indicate its current state.
 * \details     Passed state is stored and depending rules are arbitrated.
 * \param[in]   Network        The CAN channel that the indicated state corresponds to.
 * \param[in]   CurrentState   The current state of the CAN channel.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for different networks
 * \synchronous TRUE
 * \config      BSWM_ENABLE_CANSM
 * \trace       SPEC-7784, SPEC-7737, SPEC-7915, SPEC-7908
 */
extern FUNC(void, BSWM_CODE_SEC_START) BswM_CanSM_CurrentState(NetworkHandleType Network, CanSM_BswMCurrentStateType CurrentState);

#define BSWM_CODE_SEC_END
#include "MemMap.h"

#endif /*BSWM_CANSM_H*/

