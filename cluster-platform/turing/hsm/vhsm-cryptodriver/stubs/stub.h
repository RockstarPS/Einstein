#include "Std_Types.h"
#include "Csm_Types.h"
#define CRY_CODE
#define CRY
#define CID_63_SYM_ENCRYPT256_FN 0
#define CID_64_SYM_ENCRYPT256_FINISH 0
#define CID_65_SYM_ENCRYPT256_UPDATE 0
#define CID_130_SET_KEY_FN 0

//#define FUNC(rettype, memclass) void
void vHsmIpc_HostManager_PeriodicCheck(void);
FUNC (Std_ReturnType, CRY_CODE) IpcHost_MessageSend(uint8 *Ipcdata, uint16 Ipcdatasize, uint16 MessageId);
FUNC (void, CRY_CODE) IpcHost_BufferReleaseCallback(uint8 buffer_id);
