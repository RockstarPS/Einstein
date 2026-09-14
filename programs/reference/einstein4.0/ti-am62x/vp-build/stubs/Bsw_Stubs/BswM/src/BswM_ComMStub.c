#include "ComStack_Types.h"
#include "ComM.h"
#include "BswM_ComM.h"
#if AUTOSAR_ETH_ENABLE
#include "EthSM.h"
#endif
#include "CanSM.h"

FUNC(void, BSWM_CODE) BswM_ComM_CurrentMode(NetworkHandleType Network, ComM_ModeType RequestedMode)
{
    
}

void BswM_CanSM_CurrentState( NetworkHandleType Network, CanSM_BswMCurrentStateType CurrentState )
{
    
}

#if AUTOSAR_ETH_ENABLE
void BswM_EthSM_CurrentState( NetworkHandleType Network, EthSM_NetworkModeStateType CurrentState )
{
    
}
#endif
