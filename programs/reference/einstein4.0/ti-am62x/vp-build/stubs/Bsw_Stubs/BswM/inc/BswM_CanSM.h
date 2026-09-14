/* BswM_CanSM.h */
#define BSWM_CODE 
# include "CanSM_BswM.h"
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
extern FUNC(void, BSWM_CODE) BswM_CanSM_CurrentState(NetworkHandleType Network, CanSM_BswMCurrentStateType CurrentState);
