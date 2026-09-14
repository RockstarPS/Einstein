#ifndef P32_SENDQHANDLER_H
#define	P32_SENDQHANDLER_H

#ifdef	__cplusplus
extern "C" {
#endif
#if 0
#include "../[OSCD]FWT/DeviceDrv/P32_TypeDef.h"
#include "../[OSCD]FWT/Common/P32_HardwareProfile.h"
#include "../[OSCD]FWT/DeviceDrv/P32_BaseFunc.h"
#else
#include "P32_TypeDef.h"
#include "P32_HardwareProfile.h"
#include "P32_BaseFunc.h"
#endif

PN_VOID PN_CmdSendQResp(PN_U8 Direction,PN_U8 Cmd,PN_U8* pData,PN_U16 Len);
PN_VOID PN_CmdDanasMixHandler(PN_U16 Len,PN_U8* pCmd);
PN_VOID PN_CmdEvHandler(PN_U16 Len,PN_U8* pCmd);
PN_VOID PN_CmdSendQHandler(PN_VOID);
PN_VOID PN_CmdSendRstHandler(PN_DEVICEID devId);
PN_VOID PN_SPItoUsbConverterVersion(PN_VOID);




#ifdef	__cplusplus
}
#endif

#endif	/* P32_SENDQHANDLER_H */

