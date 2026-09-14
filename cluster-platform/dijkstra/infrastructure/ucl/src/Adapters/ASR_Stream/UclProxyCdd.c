///---------------------------------------------------------------------------------------------------------------------
///
/// VISTEON CORPORATION CONFIDENTIAL
/// ________________________________
///
/// [2017] Visteon Corporation
/// All Rights Reserved.
///
/// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
/// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
/// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
/// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
/// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
/// under all copyright laws to protect this work as a published work, when appropriate.
/// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
/// without the written authorization of Visteon Corporation.
///---------------------------------------------------------------------------------------------------------------------
#include "string.h"
#include "Rte_UclProxyCdd.h"
#include "UclILStream.h"
#include "UclILStream_Channel_Types.h"
#include "UclProxyCdd.h"
#include "UclILStreamCfg.h"
#include "Std_Types.h"
#include "CmpLib.h"
#include "UclSys.h"


static uint16 maxFdNum = MAX_NO_OF_FDS;
static uint16 maxChNum = NO_OF_LOGICAL_CHN;
static sint32 fdChlist[MAX_NO_OF_FDS]= {-1};
extern const SUclILStreamChASRCfg SUclILStreamChASRCfgInst[NO_OF_LOGICAL_CHN];

CMPLIB_INSTANCE(UclProxyCdd)

static uint8 UclStackRunning;

static Std_ReturnType CmpInit(void)
{
	uint16 lmaxFdNum;
	
	UclStackRunning = FALSE;
	
	for(lmaxFdNum = 0; lmaxFdNum < MAX_NO_OF_FDS;lmaxFdNum++)
	{
		fdChlist[lmaxFdNum]=-1;
	}

	if (UCL_E_OK == UclSys_Initialize(0))
	{
		UclStackRunning = TRUE;
		return E_OK;
	}
	return E_NOT_OK;

}

static Std_ReturnType CmpDeInit(void)
{

	if (UCL_E_OK == UclSys_Shutdown(0))
	{
		UclStackRunning = FALSE;
		return E_OK;
	}

	return E_NOT_OK;
}

static Std_ReturnType CmpActivation(void)
{
	return E_OK;
}

static Std_ReturnType CmpDeActivation(void)
{
	return E_OK;
}

static Std_ReturnType CmpActive(void)
{
	if (TRUE == UclStackRunning)
	{
		UclSys_Task(0);
	}
	else
	{
		return E_NOT_OK;
	}

	return E_OK;
}

static Std_ReturnType CmpDiag(void)
{
	return E_NOT_OK;
}

static Std_ReturnType CmpDiagReturn(void)
{
	return E_OK;
}

///< shall be used as alternate to  AppCntrl Init or Deinit
Std_ReturnType CUclProxyCdd_Impl_Initialize(void)
{
	if (UCL_E_OK == UclSys_Initialize(0))
	{
		UclStackRunning = TRUE;
		return E_OK;
	}
	return E_NOT_OK;
}

///< shall be used as alternate to  AppCntrl Init or Deinit
Std_ReturnType CUclProxyCdd_Impl_Shutdown(void)
{
	UclStackRunning = FALSE;

	if (UCL_E_OK == UclSys_Shutdown(0))
	{
		return E_OK;
	}
	return E_NOT_OK;
}

Std_ReturnType CUclProxyCdd_Impl_InvalidateSecurityKey(uint8 DLInst)
{
	return E_NOT_OK;
}

Std_ReturnType CUclProxyCdd_Impl_GetStatus(uint8 DLInst, uint8 *Status)
{
	return E_NOT_OK;
}

/// @defgroup UCL_CHN_FUNC UCL Channel APIs
/// @brief UCL Channel based APIs
/// @brief  Open an UCL Channel
///
/// @param[in]  chId    Channel Identifier
/// @param[in]  flags   @ref UCL_O_FLAGS
/// @param[out]  fd    > 0 File descriptor to be used
///              fd    < 0 @ref UCL_ERR
/// @return  E_OK Sucess
/// @return  E_NOT_OK Failed
///
FUNC(Std_ReturnType, UclProxyCdd_CODE) CUclProxyCdd_Impl_Open(rte_ucl_ch_t chId, rte_ucl_flag_type flags,\
															P2VAR(rte_ucl_fd_t, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) fd)
{
	Std_ReturnType Ret=E_NOT_OK;

	if(fd != NULL )
	{
		*fd = UclILStream_Open( 0, chId, flags );

		if ((*fd >= 0) && (*fd < maxFdNum))
		{
			fdChlist[*fd]=chId;
			Ret= E_OK;
		}

		else
		{
			Ret= E_NOT_OK;
		}
	}
	return Ret;
}

/// @defgroup UCL_CHN_FUNC UCL Channel APIs
/// @brief UCL Channel based APIs
/// @brief  Close an UCL Channel
///
/// @param[in]  fd  File descriptor returned by the open call
/// @param[out ] ret UCL_E_OK
///              ret < 0 @ref UCL_ERR
/// @return  E_OK Sucess
/// @return  E_NOT_OK Failed
///
FUNC(Std_ReturnType, UclProxyCdd_CODE) CUclProxyCdd_Impl_Close(rte_ucl_fd_t fd, P2VAR(sint32, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) ret)
{
	Std_ReturnType status=E_NOT_OK;

	if(ret!= NULL)
	{
		*ret = UclILStream_Close( 0, fd );

		if (*ret == UCL_E_OK)
		{
			fdChlist[fd]= -1;
			status= E_OK;
		}

		else
		{
			status= E_NOT_OK;

		}
	}
	return status;
}

/// @defgroup UCL_CHN_FUNC UCL Channel APIs
/// @brief  Read data from the UCL channel
///
/// @param[in]  fd      File descriptor returned by the open call
/// @param[out] pBuffer Buffer to return the received data
/// @param[in]  size    Size of the buffer
/// @param[out] sizeRead > 0 number of bytes read
///             sizeRead < 0  @ref UCL_ERR
/// @return  E_OK Sucess
/// @return  E_NOT_OK Failed
///
FUNC(Std_ReturnType, UclProxyCdd_CODE) CUclProxyCdd_Impl_Read(rte_ucl_fd_t fd, P2VAR(uint8, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) pbuffer, uint32 size,\
		                                                      P2VAR(sint32, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) sizeRead)
{
	Std_ReturnType status=E_NOT_OK;

	if(sizeRead!= NULL)
	{
		*sizeRead = UclILStream_Read( 0, fd, pbuffer, size );

		if(*sizeRead >= 0 )
		{
			status=E_OK;
		}
		else
		{
			status= E_NOT_OK;
		}
	}

	return status;
}

/// @defgroup UCL_CHN_FUNC UCL Channel APIs
/// @brief  Write data to the UCL channel
///
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  pBuffer Buffer that contains the data to be sent
/// @param[in]  size    Size of the buffer
/// @param[out] byteWrote > 0 number of bytes wrote
///             byteWrote < 0  @ref UCL_ERR
/// @return  E_OK Sucess
/// @return  E_NOT_OK Failed
///
FUNC(Std_ReturnType, UclProxyCdd_CODE) CUclProxyCdd_Impl_Write(	rte_ucl_fd_t fd, P2VAR(uint8, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) pbuffer,\
																uint32 size, P2VAR(sint32, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) byteWrote)
{
	Std_ReturnType status=E_NOT_OK;

	if(byteWrote!= NULL)
	{
		*byteWrote = UclILStream_Write( 0, fd, pbuffer, size );

		if(*byteWrote == size )
		{
			status=E_OK;
		}
		else
		{
			status= E_NOT_OK;
		}
	}
	return status;
}

/// @defgroup UCL_CHN_FUNC UCL Channel APIs
/// @brief  Write data to the UCL channel along with the request id
///
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  reqId   Request ID to be associated with this write request
/// @param[in]  pBuffer Buffer that contains the data to be sent
/// @param[in]  size    Size of the buffer
/// @param[out] byteWrote > 0 number of bytes wrote
///             byteWrote < 0  @ref UCL_ERR
/// @return  E_OK Sucess
/// @return  E_NOT_OK Failed
///
FUNC(Std_ReturnType, UclProxyCdd_CODE) CUclProxyCdd_Impl_Write_Ex(rte_ucl_fd_t fd, uint8 reqId,P2VAR(uint8, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) pBuffer,\
                                                                  uint32 size, P2VAR(sint32, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) byteWrote)
{
	Std_ReturnType status=E_NOT_OK;

	if(byteWrote!= NULL)
	{
		*byteWrote = UclILStream_WriteEx( 0, fd, reqId, pBuffer, size );

		if(*byteWrote == size )
		{
			status=E_OK;
		}
		else
		{
			status= E_NOT_OK;
		}

	}

	return status;
}
/// @defgroup UCL_CHN_FUNC UCL Channel APIs
/// @brief  Poll the UCL channel to check for receive data
///
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  timeout Timeout to wait for data
///
/// @ret > 0 number of bytes waiting to be read
/// @ret < 0 @ref UCL_ERR
/// @return  E_OK Sucess
/// @return  E_NOT_OK Failed
///
FUNC(Std_ReturnType, UclProxyCdd_CODE) CUclProxyCdd_Impl_Poll(rte_ucl_fd_t fd, uint32 timeout,P2VAR(sint32, AUTOMATIC,\
		                                                      RTE_UCLPROXYCDD_APPL_VAR) ret)
{
	Std_ReturnType status=E_NOT_OK;

	if(ret!=NULL)
	{
		*ret = UclILStream_Poll( 0, fd, timeout );

		if(*ret >= 0 )
		{
			status=E_OK;
		}
		else
		{
			status= E_NOT_OK;
		}
	}
	return status;
}

/// @defgroup UCL_CHN_FUNC UCL Channel APIs
/// @brief  UCL Input/Output Control API to flush Rx queue
///
/// @param[in]  fd      File descriptor returned by the open call
/// @return @ref E_OK   Success
/// @return @ref E_NOT_OK
//
FUNC(Std_ReturnType, UclProxyCdd_CODE) CUclProxyCdd_Impl_IoCtl_FlushRxQueue(rte_ucl_fd_t fd)
{
	Std_ReturnType status;
	sint32 ret = E_NOT_OK;

	ret = UclILStream_Ioctl(0, fd, UCL_IOCTL_FLUSH_RX_QUEUE, NULL, 0X0);

	if (ret == UCL_E_OK)
	{
		status = E_OK;
	} else
	{
		status = E_NOT_OK;
	}

	return status;
}
/// @defgroup UCL_CHN_FUNC UCL Channel APIs
/// @brief  UCL UCL Input/Output Control API to flush Tx queue
///
/// @param[in]  fd      File descriptor returned by the open call
/// @return @ref E_OK   Success
/// @return @ref E_NOT_OK
//
FUNC(Std_ReturnType, UclProxyCdd_CODE) CUclProxyCdd_Impl_IoCtl_FlushTxQueue(rte_ucl_fd_t fd)
{
	Std_ReturnType status;
	sint32 ret = E_NOT_OK;

	ret = UclILStream_Ioctl(0, fd, UCL_IOCTL_FLUSH_TX_QUEUE, NULL, 0X0);

	if (ret == UCL_E_OK)
	{
		status = E_OK;
	}
	else
	{
		status = E_NOT_OK;
	}

	return status;
}
/// @defgroup UCL_CHN_FUNC UCL Channel APIs
/// @brief  UCL Input/Output Control API to GetLinkStatus
///
/// @param[in]  fd      File descriptor returned by the open call
/// @return @ref E_OK   Success
/// @return @ref E_NOT_OK
//

FUNC(Std_ReturnType, UclProxyCdd_CODE) CUclProxyCdd_Impl_IoCtl_GetLinkStatus(rte_ucl_fd_t fd, P2VAR(sint32, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) linkStatus)
{
	Std_ReturnType status;
	sint32 ret=E_NOT_OK;
	sint32 mlinkStatus;

	ret = UclILStream_Ioctl( 0, fd, UCL_IOCTL_GET_LINK_STATUS, &mlinkStatus, sizeof(uint8) );

	if((ret == UCL_E_OK )&& (linkStatus!= NULL ))
	{
		*linkStatus= mlinkStatus;
		status=E_OK;
	}
	else
	{
		status= E_NOT_OK;
	}

	return status;
}
/// @defgroup UCL_CHN_FUNC UCL Channel APIs
/// @brief  UCL Input/Output Control API to get UCLDL statistics
///
/// @param[in]  fd      File descriptor returned by the open call
/// @return @ref E_OK   Success
/// @return @ref E_NOT_OK
//
FUNC(Std_ReturnType, UclProxyCdd_CODE) CUclProxyCdd_Impl_IoCtl_GetStats(rte_ucl_fd_t fd, P2VAR(rte_ucl_ioctl_channel_stats_t, AUTOMATIC,\
				                                                         RTE_UCLPROXYCDD_APPL_VAR) stats)
{
	Std_ReturnType status;
	sint32 ret=E_NOT_OK;
	ucl_ioctl_channel_stats_t mStats;

	ret = UclILStream_Ioctl( 0, fd, UCL_IOCTL_GET_STATS, &mStats, sizeof(ucl_ioctl_channel_stats_t) );

	if((ret == UCL_E_OK) && (stats != NULL))
	{
		stats->dl.tx_bytes = mStats.dl.tx_bytes;
		stats->dl.rx_bytes = mStats.dl.rx_bytes;
		stats->dl.tx_msgs = mStats.dl.tx_msgs;
		stats->dl.rx_msgs = mStats.dl.rx_msgs;
		stats->dl.tx_kbps = mStats.dl.tx_kbps;
		stats->dl.rx_kbps = mStats.dl.rx_kbps;
		stats->dl.avg_ack_latency = mStats.dl.avg_ack_latency;
		stats->il.num_open_channels = mStats.il.num_open_channels;
	    stats->il.num_open_fds = mStats.il.num_open_fds;
		status = E_OK;
	}

	else
	{
		status = E_NOT_OK;
	}

	return status;

}
/// @defgroup UCL_CHN_FUNC UCL Channel APIs
/// @brief  UCL Input/Output Control API to get channel parameters
///
/// @param[in]  fd      File descriptor returned by the open call
/// @return @ref E_OK   Success
/// @return @ref E_NOT_OK
//
FUNC(Std_ReturnType, UclProxyCdd_CODE) CUclProxyCdd_Impl_Ioctl_GetChParam(rte_ucl_fd_t fd, P2VAR(rte_ucl_ioctl_channel_param_t, AUTOMATIC,\
				RTE_UCLPROXYCDD_APPL_VAR) chParam)
{
	Std_ReturnType status;
	sint32 ret=E_NOT_OK;
	ucl_ioctl_channel_param_t mChParam;

	ret = UclILStream_Ioctl( 0, fd, UCL_IOCTL_GET_CHANNEL_PARAM, &mChParam, sizeof(ucl_ioctl_channel_param_t) );

	if((ret == UCL_E_OK) && (chParam != NULL))
	{
		chParam->priority_level = mChParam.priority_level;
		chParam->security_level = mChParam.security_level;
		chParam->time_to_live_ms = mChParam.time_to_live_ms;
		status=E_OK;
	}
	else
	{
		status= E_NOT_OK;
	}

	return status;

}

/// @defgroup UCL_CHN_FUNC UCL Channel APIs
/// @brief  UCL Input/Output Control API to set channel parameters
///
/// @param[in]  fd      File descriptor returned by the open call
/// @return @ref E_OK   Success
/// @return @ref E_NOT_OK
//
FUNC(Std_ReturnType, UclProxyCdd_CODE) CUclProxyCdd_Impl_Ioctl_SetChParam(rte_ucl_fd_t fd, P2CONST( rte_ucl_ioctl_channel_param_t,\
				                                                          AUTOMATIC,RTE_UCLPROXYCDD_APPL_DATA) chParam)
{
	Std_ReturnType status;
	sint32 ret=E_NOT_OK;
	ucl_ioctl_channel_param_t mChParam;

	if(chParam != NULL )
	{
		mChParam.priority_level = chParam->priority_level;
		mChParam.security_level = chParam->security_level;
		mChParam.time_to_live_ms = chParam->time_to_live_ms;

		ret = UclILStream_Ioctl( 0, fd, UCL_IOCTL_SET_CHANNEL_PARAM, &mChParam, sizeof(ucl_ioctl_channel_param_t) );

		if(ret == UCL_E_OK)
		{
			status=E_OK;
		}
		else
		{
			status= E_NOT_OK;
		}
	}

	return status;
}

//
/// @defgroup UCL_CHN_FUNC UCL Channel APIs
/// @brief  Send notifcations to subscribers
/// @param[in]  DLInst  instance Id of the UCL DL
/// @param[in]  ErrorCode @ UCL ERR
//
void UclILStream_Adapter_ErrorNotification(uint8 DLInst, sint32 ErrorCode)
{
	uint16 index;

	for (index = 0; index < maxChNum; index++)
	{
		if (SUclILStreamChASRCfgInst[index].pCbk_UclILStreamASR_ErrorNotification!= NULL)
		{
			SUclILStreamChASRCfgInst[index].pCbk_UclILStreamASR_ErrorNotification(ErrorCode);
		}
	}
}

//
/// @defgroup UCL_CHN_FUNC UCL Channel APIs
/// @brief  Send notifcations to subscribers
/// @param[in]  DLInst  instance Id
/// @param[in]  Status @ucl_link status
//
void UclILStream_Adapter_LinkStatusChanged(uint8 DLInst, sint32 Status)
{
	uint16 index;

	for (index = 0; index < maxChNum; index++)
	{
		if (SUclILStreamChASRCfgInst[index].pCbk_UclILStreamASR_LinkStatusChanged!= NULL)
		{
			SUclILStreamChASRCfgInst[index].pCbk_UclILStreamASR_LinkStatusChanged(Status);
		}
	}
}

/// @defgroup UCL_CHN_FUNC UCL Channel APIs
/// @brief  Send notifcations to subscribers
/// @param[in]  chId  Id of the logical channel
/// @param[in]  fd  File Id of the logical channel
/// @param[in]  reqId Id provided by CUclProxyCdd_Impl_Write_Ex Api
/// @param[in]  Status @ucl_tx_status
//
void UclILStream_Adapter_MessageTransmitStatus( sint32 fd,uint8 reqId, sint32 Status)
{
	SDKTxStatus txStatus;
	uint8 index = 0x0;
    uint8 chId;
	 
	if ((fd >= 0) && (fd < maxFdNum) )
	{
		chId = fdChlist[fd];
		if ((chId < maxChNum) && (chId >= 0))
		{
			txStatus.fd = fd;
			txStatus.reqId = reqId;
			txStatus.txStatus = Status;

			while (index < maxChNum)
			{
				if (SUclILStreamChASRCfgInst[index].chId == chId)
				{
					if (SUclILStreamChASRCfgInst[index].pCbk_UclILStreamASR_MessageTransmitStatus!= NULL)
					{
						SUclILStreamChASRCfgInst[index].pCbk_UclILStreamASR_MessageTransmitStatus(&txStatus);
					}
					break;
				}
				index++;
			}
		}
	}
}

/// @defgroup UCL_CHN_FUNC UCL Channel APIs
/// @brief  Send notifcations to subscribers
/// @param[in]  chId  Id of the logical channel
/// @param[in]  fd  File Id of the logical channel
//
void UclILStream_Adapter_DataReceived( sint32 fd )
{
	SDKRxStatus rxStatus;
	uint8 index = 0x0;
    uint8 chId;
	if ((fd >= 0) && (fd < maxFdNum))
	{
		chId = fdChlist[fd];
		if ((chId < maxChNum) && (chId >= 0))
		{
			while (index < maxChNum)
			{
				if (SUclILStreamChASRCfgInst[index].chId == chId)
				{
					if (SUclILStreamChASRCfgInst[index].pCbk_UclILStreamASR_DataReceivedNotification!= NULL)
					{
						rxStatus.fd = fd;
						rxStatus.status = 0;  ///<Parameter is dummy,will be deprecated in future releases
						SUclILStreamChASRCfgInst[index].pCbk_UclILStreamASR_DataReceivedNotification( &rxStatus);
					}
					break;
				}
				index++;
			}
		}
	}
}
