#ifndef DLTEXT_IPC_H
#define DLTEXT_IPC_H

/****************************************************************************
 * Includes
 ****************************************************************************/
#include "Std_Types.h"
#include "DltExt_Types.h"
#include "DltExt_Cfg.h"

#if (DLTEXT_CFG_SHMEM_IPC_PRESENT == STD_ON)
/****************************************************************************
 * Macro Definitions
 ****************************************************************************/
#ifndef DLTEXT_IPC_FLUSH_TIMEOUT_MS
#define DLTEXT_IPC_FLUSH_TIMEOUT_MS       (3000u)
#endif

#ifndef DLTEXT_IPC_MAINFUNCTION_PERIOD_MS
#define DLTEXT_IPC_MAINFUNCTION_PERIOD_MS (10u)
#endif

/****************************************************************************
 * Function Prototypes
 ****************************************************************************/
void DltExt_Ipc_Init(void);
void DltExt_Ipc_DeInit(void);
void DltExt_Ipc_MainFunction(void);

void DltExt_Ipc_GipStatusUp(void);

Std_ReturnType DltExt_Ipc_PushVipAppFrame(const uint8 *DataPtr, uint16 Length);
Std_ReturnType DltExt_Ipc_PushVipResetFrame(const uint8 *DataPtr, uint16 Length);

#if (DLT_DM_TO_GIP_INTERFACE == STD_ON)
void CddIpc_DM_DltReadyResponse(void);
#endif

#if (DLT_HSM_TO_GIP_INTERFACE == STD_ON)
/* Exported HSM callback symbol */
void DltExt_Ipc_HsmLogEvent(uint32 data);
#endif

#endif /* DLTEXT_CFG_SHMEM_IPC_PRESENT == STD_ON */

#endif /* DLTEXT_IPC_H */
