/* BswM_ComM.h */
#ifndef BSWM_COMM_H
#define BSWM_COMM_H

#include "Rte_Type.h"
#include "ComStack_Types.h"
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
#define BSWM_CODE
extern FUNC(void, BSWM_CODE) BswM_ComM_CurrentMode(NetworkHandleType Network, ComM_ModeType RequestedMode);

#endif


