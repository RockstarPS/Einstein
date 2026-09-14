/*
 * UclILStreamASRAdapter.h
 *
 *  Created on: Jul 2, 2019
 *      Author: RKRISHN8
 */

#ifndef UCLILSTREAMASRADAPTER_H_
#define UCLILSTREAMASRADAPTER_H_


#include "Rte_UclProxyCdd.h"

typedef struct SUclILStreamChASRCfg_t
{
    uint8 chId;
    Std_ReturnType (*pCbk_UclILStreamASR_ErrorNotification)( sint32 data);
    Std_ReturnType (*pCbk_UclILStreamASR_LinkStatusChanged)( sint32 data );
    Std_ReturnType (*pCbk_UclILStreamASR_DataReceivedNotification)(const SDKRxStatus* status );
    Std_ReturnType (*pCbk_UclILStreamASR_MessageTransmitStatus)( const SDKTxStatus* status);
} SUclILStreamChASRCfg;

#endif /* UCLILSTREAMASRADAPTER_H_ */
