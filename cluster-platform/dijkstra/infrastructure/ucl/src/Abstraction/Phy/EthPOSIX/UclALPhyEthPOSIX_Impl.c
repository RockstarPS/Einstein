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
///
///---------------------------------------------------------------------------------------------------------------------

#include <stdio.h> //debug
#include <pthread.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>
#include "UclALPhyEthPOSIX_Impl.h"
#include "UclCmnRingBuffer.h"
#include "UclALPhyCbk.h"
#include "UclALDebug.h"
#include "UclALOs.h"

void *UclALPhyEthPOSIX_Impl_TransmitTask(void *pData);
void *UclALPhyEthPOSIX_Impl_ReceiveTask(void *pData);

static Ucl_ReturnType UclALPhyEthPOSIX_Impl_Hw_Open(SUclALPhyEthPOSIXInst *pInst);
static Ucl_ReturnType UclALPhyEthPOSIX_Impl_Hw_Close(SUclALPhyEthPOSIXInst *pInst);
static Ucl_ReturnType UclALPhyEthPOSIX_Impl_Hw_Write(SUclALPhyEthPOSIXInst *pInst, uint8 *pData, uint16 Size);


Ucl_ReturnType UclALPhyEthPOSIX_Impl_IUclALPhy_Initialize(SUclALPhyEthPOSIXInst *pInst, uint8 InstId)
{
    Ucl_ReturnType Ret;
    uint8 i;

	pInst->peerReadyState = eUclALPhyPeerReadyStatus_NotReady;
	pInst->sockFd = -1;
    Ret = UclALPhyEthPOSIX_Impl_Hw_Open(pInst);

    if (Ret == UCL_E_OK)
    {
        Ret = UclCmnRingBuffer_Initialize ( &pInst->txRingBuffer, pInst->pCfg->pTxRingBuffer, pInst->pCfg->txRingBufferSize );
    }

    if ( Ret == UCL_E_OK )
    {
        Ret = UclCmnRingBuffer_Initialize(&pInst->rxRingBuffer, pInst->pCfg->pRxRingBuffer, pInst->pCfg->rxRingBufferSize);
    }

    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_MutexCreate(0, &pInst->txRingBufferMutexId);
    }

    if (Ret == UCL_E_OK)
    {
        Ret = UclALOs_MutexCreate ( 0, &pInst->rxRingBufferMutexId );
    }

    if (Ret == UCL_E_OK)
    {
        Ret = UclALOs_SemCreate(0, &pInst->txSemId, 1);
    }

    if (Ret == UCL_E_OK)
    {
        Ret = UclALOs_TaskCreate(0, &pInst->txTaskId, UclALPhyEthPOSIX_Impl_TransmitTask, (void *)pInst);
    }

    if (Ret == UCL_E_OK)
    {
        Ret = UclALOs_TaskCreate(0, &pInst->rxTaskId, UclALPhyEthPOSIX_Impl_ReceiveTask, (void *)pInst);
    }

    if (UCL_E_OK == Ret)
    {

		if (pInst->pCfg->nodeType == eUclALPhyEthNodeType_Client)
		{			
			LOGI(0, "UclALPhyEthPOSIX_Impl_IUclALPhy_Initialize", "%s", "Success\n");

			pInst->peerReadyState = eUclALPhyPeerReadyStatus_Ready;

			for (i = 0; i < pInst->numIUclALPhyCbk; i++)
			{
				//TODO: Implement HW Flow Control
				UclALPhyCbk_PeerReadyStatusChanged(pInst->pIUclALPhyCbk[i], eUclALPhyPeerReadyStatus_Ready);
			}
		}
    }	
   
	if (UCL_E_OK != Ret)
	{		
        LOGE(0, "UclALPhyEthPOSIX_Impl_IUclALPhy_Initialize", "Failed %d\n", Ret);
    }

    return Ret;
}

Ucl_ReturnType UclALPhyEthPOSIX_Impl_IUclALPhy_Shutdown(SUclALPhyEthPOSIXInst *pInst, uint8 InstId)
{
    Ucl_ReturnType Ret;

    Ret = UclALPhyEthPOSIX_Impl_Hw_Close(pInst);

    if (UCL_E_OK == Ret)
    {
        (void)UclALOs_SemDestroy(0, pInst->txSemId);
        (void)UclALOs_MutexDestroy(0, pInst->txRingBufferMutexId);
        (void)UclALOs_MutexDestroy(0, pInst->rxRingBufferMutexId);
        (void)UclALOs_TaskDestroy(0, pInst->txTaskId);
        (void)UclALOs_TaskDestroy(0, pInst->rxTaskId);

        LOGI(0, "UclALPhyEthPOSIX_Impl_IUclALPhy_Shutdown", "%s", "Success");
    }
    else
    {
        LOGE(0, "UclALPhyEthPOSIX_Impl_IUclALPhy_Shutdown", "Failed %d", Ret);
    }

    return Ret;
}

Ucl_ReturnType UclALPhyEthPOSIX_Impl_IUclALPhy_Write(SUclALPhyEthPOSIXInst *pInst, uint8 InstId, uint8 *pData,
                                                        uint16 Size)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
	
    if ( ( NULL_PTR == pData ) || ( 0u == Size ) )
    {
		LOGE(0, "UclALPhyEthPOSIX_Impl_IUclALPhy_Write", "%s", "Invalid Args");
        Ret = UCL_E_INVALID_ARGS;
    }
    else if (pInst->sockFd == -1)
    {
        LOGE(0, "UclALPhyEthPOSIX_Impl_IUclALPhy_Write", "%s", "Invalid Dev Handle");
    }
    else
    {	
        if (UCL_E_OK == UclALOs_MutexLock(0, pInst->txRingBufferMutexId))
        {
            Ret = UclCmnRingBuffer_Write(&pInst->txRingBuffer, pData, Size);

            (void)UclALOs_MutexUnlock(0, pInst->txRingBufferMutexId);

            if (UCL_E_OK == Ret)
            {
                (void)UclALOs_SemPost(0, pInst->txSemId);
            }
            else if (UCL_E_BUFFER_FULL == Ret)
            {
                UclALPhyCbk_FatalError(pInst->pIUclALPhyCbk[0], UCL_E_BUFFER_FULL);
                LOGE(0, "UclALPhyEthPOSIX_Impl_IUclALPhy_Write", "No space to write %d\n", Size);
            }
            else
            {
                LOGE(0, "UclALPhyEthPOSIX_Impl_IUclALPhy_Write", "Error %d\n", Ret);
            }
        }
    }

    return Ret;
}

Ucl_ReturnType UclALPhyEthPOSIX_Impl_IUclALPhy_Read(SUclALPhyEthPOSIXInst *pInst, uint8 InstId, uint8 *pData,
                                                       uint16 *pSize)
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ( ( NULL_PTR == pData ) || ( NULL_PTR == pSize ) || ( 0u == *pSize ) )
    {
        Ret = UCL_E_INVALID_ARGS;
    }
    else
    {
        if (UCL_E_OK == UclALOs_MutexLock(0, pInst->rxRingBufferMutexId))
        {
            Ret = UclCmnRingBuffer_ReadFrame(&pInst->rxRingBuffer, 0x0, pData, pSize);

            (void)UclALOs_MutexUnlock(0, pInst->rxRingBufferMutexId);
        }
    }

    return Ret;
}

void *UclALPhyEthPOSIX_Impl_TransmitTask(void *pData)
{
    SUclALPhyEthPOSIXInst *pInst = (SUclALPhyEthPOSIXInst *)pData;
    const SUclALPhyEthPOSIXCfg *pCfg = pInst->pCfg;	
    Ucl_ReturnType Ret;
    uint16 BytesRead;		

    LOGI(0, "UclALPhyEthPOSIX_Impl_TransmitTask", "%s", "Begins\n");

	while (pInst->sockFd >= 0) 
	{
        Ret = UclALOs_SemWait ( 0, pInst->txSemId );

        if ( ( UCL_E_OK == Ret ) && ( eUclALPhyPeerReadyStatus_Ready == pInst->peerReadyState ) )
        {
			do
			{	
				BytesRead = pCfg->txDmaBufferSize;
				
				(void)UclALOs_Memset(0, pCfg->pTxDmaBuffer, 0, pCfg->txDmaBufferSize);
				
				Ret = UclALOs_MutexLock(0, pInst->txRingBufferMutexId);

				if (UCL_E_OK == Ret)
				{
                    ( void ) UclCmnRingBuffer_Read ( &pInst->txRingBuffer, pCfg->pTxDmaBuffer, &BytesRead ); //Cov: Assigning value to "Ret" here, but that stored value is overwritten before it can be used.
					
					(void)UclALOs_MutexUnlock(0, pInst->txRingBufferMutexId);
				}

                if ( 0u < BytesRead )
                {
                    Ret = UclALPhyEthPOSIX_Impl_Hw_Write ( pInst, pCfg->pTxDmaBuffer, BytesRead );

                    if ( UCL_E_OK != Ret )
                    {
                        LOGE ( 0, "UclALPhyEthPOSIX_Impl_TransmitTask", "Write Failed %d\n", Ret );
                    }
                }
            }
            while ( 0u < BytesRead );
        }
    }

    LOGI(0, "UclALPhyEthPOSIX_Impl_TransmitTask", "%s", "Exit\n");

    return NULL_PTR;
}

void *UclALPhyEthPOSIX_Impl_ReceiveTask(void *pData)
{   
	SUclALPhyEthPOSIXInst *pInst = (SUclALPhyEthPOSIXInst *)pData;
    const SUclALPhyEthPOSIXCfg *pCfg = pInst->pCfg;
	Ucl_ReturnType Ret = UCL_E_OK;       
	ssize_t rcvLen;
	struct sockaddr *srcAddr;
	socklen_t *srcAddrLen;
	socklen_t servAddrLen;
	uint8 i;

    LOGI(0, "UclALPhyEthPOSIX_Impl_ReceiveTask", "%s", "Begins\n");
	
	if( pCfg->nodeType == eUclALPhyEthNodeType_Server)
	{
		srcAddr = (struct sockaddr*)&pInst->cliAddr;
		pInst->cliAddrLen = sizeof(pInst->cliAddr);
		srcAddrLen = &(pInst->cliAddrLen);		
	}
	else
	{
		srcAddr = (struct sockaddr*)&pInst->servAddr;
		servAddrLen = sizeof(pInst->servAddr);
		srcAddrLen = &servAddrLen;		
	}
	
    while ( pInst->sockFd >= 0 )
    {
        rcvLen = recvfrom ( pInst->sockFd, pCfg->pRxDmaBuffer, pCfg->rxDmaBufferSize, 0,  srcAddr, srcAddrLen );

        if ( rcvLen > 0 )
        {
            Ret = UclALOs_MutexLock ( 0, pInst->rxRingBufferMutexId );

            if ( UCL_E_OK == Ret )
            {
                Ret = UclCmnRingBuffer_Write ( &pInst->rxRingBuffer, pCfg->pRxDmaBuffer, ( uint16 ) rcvLen );

                ( void ) UclALOs_MutexUnlock ( 0, pInst->rxRingBufferMutexId );

                if ( UCL_E_BUFFER_FULL == Ret )
                {
                    LOGE ( 0, "UclALPhyEthPOSIX_Impl_ReceiveTask", "%s", "Receive RB Full" );
                }
            }

            if ( pInst->pCfg->nodeType == eUclALPhyEthNodeType_Server )
            {
                // Started getting pings. Client is up
                if ( eUclALPhyPeerReadyStatus_NotReady == pInst->peerReadyState )
                {
                    pInst->peerReadyState = eUclALPhyPeerReadyStatus_Ready;

                    UclALPhyCbk_PeerReadyStatusChanged ( pInst->pIUclALPhyCbk[0], eUclALPhyPeerReadyStatus_Ready );
                }
            }

            if ( UCL_E_OK == Ret )
            {
                for ( i = 0; i < pInst->numIUclALPhyCbk; i++ )
                {
                    UclALPhyCbk_ReceiveDataAvailable ( pInst->pIUclALPhyCbk[i] );
                }
            }
        }
        else if ( rcvLen == 0 )
        {
            //Host disconnected
            LOGE ( 0, "UclALPhyEthPOSIX_Impl_ReceiveTask", "%s", "Host Disconnected " );

            if ( eUclALPhyPeerReadyStatus_Ready == pInst->peerReadyState )
            {
                pInst->peerReadyState = eUclALPhyPeerReadyStatus_NotReady;

                UclALPhyCbk_PeerReadyStatusChanged ( pInst->pIUclALPhyCbk[0], eUclALPhyPeerReadyStatus_NotReady );
            }

            //Close the connection
            ( void ) close ( pInst->sockFd );
            pInst->sockFd = -1;
        }
        else
        {
			if ( __get_errno_ptr() != NULL_PTR )
			{
				LOGE ( 0, "UclALPhyEthPOSIX_Impl_ReceiveTask", "Rcv Error %d - %s ", errno, strerror ( errno ) );
			}
			else
			{
				LOGE ( 0, "UclALPhyEthPOSIX_Impl_ReceiveTask", "Rcv Error  __get_errno_ptr NULL" );
			}	
        }
    }

    LOGI ( 0, "UclALPhyEthPOSIX_Impl_ReceiveTask", "%s", "Exit\n" );

    return NULL_PTR;
}

static Ucl_ReturnType UclALPhyEthPOSIX_Impl_Hw_Open(SUclALPhyEthPOSIXInst *pInst)
{       
	Ucl_ReturnType Ret = UCL_E_OK;
		
	// socket create 
    pInst->sockFd = socket(AF_INET,  SOCK_DGRAM, IPPROTO_UDP); 

    if ( pInst->sockFd == -1 )
    {
		if ( __get_errno_ptr() != NULL_PTR )
		{
			LOGE ( 0, "UclALPhyEthPOSIX_Impl_Hw_Open", "Socket create failed %d - %s", errno, strerror ( errno ) );
		}
		else
		{
			LOGE ( 0, "UclALPhyEthPOSIX_Impl_Hw_Open", "Socket create failed __get_errno_ptr NULL" );
		}
		
        Ret = UCL_E_NOK;
    }
    else
    {
        LOGI ( 0, "UclALPhyEthPOSIX_Impl_Hw_Open", "Socket create success %d", pInst->sockFd );

        ( void ) UclALOs_Memset ( 0, &pInst->servAddr, 0, sizeof ( pInst->servAddr ) );

        // assign IP, PORT
        pInst->servAddr.sin_family = AF_INET;
        pInst->servAddr.sin_addr.s_addr = inet_addr ( pInst->pCfg->interfaceIp );
        pInst->servAddr.sin_port = htons ( pInst->pCfg->portNo );

        if ( pInst->pCfg->nodeType == eUclALPhyEthNodeType_Server )
        {
            // Bind the socket to IP
            if ( ( bind ( pInst->sockFd, ( struct sockaddr * ) & ( pInst->servAddr ), sizeof ( pInst->servAddr ) ) ) != 0 )
            {
				if ( __get_errno_ptr() != NULL_PTR )
				{
					LOGE ( 0, "UclALPhyEthPOSIX_Impl_Hw_Open", "Socket Bind failed %d - %s \n", errno, strerror ( errno ) );
				}
				else
				{
					LOGE ( 0, "UclALPhyEthPOSIX_Impl_Hw_Open", "Socket Bind failed __get_errno_ptr NULL \n" );
				}
				
                Ret = UCL_E_NOK;
            }
            else
            {
                LOGI ( 0, "UclALPhyEthPOSIX_Impl_Hw_Open", "%s", "Socket binded successfully .." );
            }
        }
    }

    return Ret;
}

static Ucl_ReturnType UclALPhyEthPOSIX_Impl_Hw_Close ( SUclALPhyEthPOSIXInst *pInst )
{
    Ucl_ReturnType Ret = UCL_E_OK;

    if ( pInst->sockFd >= 0 )
    {
        ( void ) close ( pInst->sockFd );
        pInst->sockFd = -1;
        LOGI ( 0, "UclALPhyEthPOSIX_Impl_Hw_Close", "Socket to the interface %s closed\n", pInst->pCfg->interfaceIp );
    }
    else
    {
        LOGI ( 0, "UclALPhyEthPOSIX_Impl_Hw_Close", "Socket to the interface %s already closed\n", pInst->pCfg->interfaceIp );
    }

    return Ret;
}

static Ucl_ReturnType UclALPhyEthPOSIX_Impl_Hw_Write(SUclALPhyEthPOSIXInst *pInst, uint8 *pData, uint16 Size)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
	uint16 BytesSent = 0;		
	ssize_t BytesWrote;
	struct sockaddr *destAddr;
	socklen_t destAddrlen;
	
    do
    {
        if ( pInst->pCfg->nodeType == eUclALPhyEthNodeType_Server )
        {
            destAddr = ( struct sockaddr * ) &pInst->cliAddr;
            destAddrlen = pInst->cliAddrLen;
        }
        else
        {
            destAddr = ( struct sockaddr * ) &pInst->servAddr;
            destAddrlen = sizeof ( pInst->servAddr );
        }

        BytesWrote = sendto ( pInst->sockFd, &pData[BytesSent], ( size_t ) ( Size - BytesSent ), 0, destAddr, destAddrlen );

        if ( BytesWrote == -1 )
        {
            LOGE ( 0, "UclALPhyEthPOSIX_Impl_Hw_Write", "Sento %s:%d failed",  inet_ntoa ( ( ( struct sockaddr_in * ) destAddr )->sin_addr ), ntohs ( ( ( struct sockaddr_in * ) destAddr )->sin_port ) );
        }
        else
        {
            BytesSent += ( uint16 ) BytesWrote;
        }
    }
    while ( BytesSent < Size );

    if ( BytesSent == Size )
    {
        Ret = UCL_E_OK;
    }

    return Ret;
}
