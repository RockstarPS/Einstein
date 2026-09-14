#include <windows.h>
#undef FAR
#define OS_H
#include "CanHelper.h"
#include "Can_Cfg.h"
// #include "CanIf_Types.h"
#include "CanIf_Lcfg.h"
#include "CanIf_Cfg.h"
//#include "CANconfig.cfg"

PduIdType FindCANTxPDUType(Can_IdType pTxCANID,int channelId );
typedef struct
{
	int TxChannelId;
	PduIdType TxPDUId;
	Can_IdType TxCANId;
}CAN_transmit_struct;

/*! @brief Defines the search parameter type */
typedef struct
{
    /*! @brief Defines the start id of the RxPduId of the mailbox */
	CanIf_PduIdConfigIdType	RxStartPduId;
    /*! @brief Defines the end id of the RxPduId of the mailbox  */
	CanIf_PduIdConfigIdType RxEndPduId;
    /*! @brief Defines the Id of the received message */
	CanIf_PduIdConfigIdType	RcvdRxPduId;
    /*! @brief Defines the Id of the received message */
	Can_IdType 				RcvdCanId;
}CanIf_RxSearchParamType;

static CAN_transmit_struct  PduInfoS[100];

static unsigned char lNumOfTxPDus;
void StartCanTimer(void);

static uint8 GetCanIf_GetCtrlId(PduIdType CanTxPduId);
static unsigned int WinCanIf_AcceptanceFilter (unsigned int pCanID);
static unsigned int TestCanIf_AcceptanceFilter (const Can_HwType* Mailbox, uint16 *CanIfRxPduId);
unsigned char FindifIDisConfigured(unsigned int *Hrhindex,unsigned char lChnl,unsigned int pCANID);
extern void Can_DisableControllerInterrupts(uint8 Controller);
extern void Can_EnableControllerInterrupts(uint8 Controller) ;
#if (CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_INDEX)
/*!******************************************************************************************************************
*   @brief      This method is uses index search filter algo to do SW filtering of the received can id
*   @param[in]  pRxSearchParam pointer to the search parmaters
*   @return     boolean returns tbe status . TRUE if can id is valid , FALSE if can id is invalid
********************************************************************************************************************/
boolean CanIf_RxMessageIndexSearch
(
    CanIf_RxSearchParamType *pRxSearchParam
);
#endif
#if (CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_TABLE)
/*!******************************************************************************************************************
*   @brief      This method is uses double hash filter algo to do SW filtering of the received can id
*   @param[in]  pRxSearchParam pointer to the search parmaters
*   @return     boolean returns tbe status . TRUE if can id is valid , FALSE if can id is invalid
********************************************************************************************************************/
boolean CanIf_RxMessageDoubleHashSearch
(
    CanIf_RxSearchParamType *pRxSearchParam
);
#endif
#if (CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_BINARY)
boolean CanIf_RxMessageBinarySearch
(
    CanIf_RxSearchParamType *pRxSearchParam
);
#endif
#if (CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_LINEAR)
boolean CanIf_RxMessageLinearSearch
(
    CanIf_RxSearchParamType *pRxSearchParam
);
#endif
uint32 CanIf_RxGetCanIdMask(CanIf_RxCanIdMaskIdxType CanIf_RxCanIdMaskIdx);

XLstatus demoCreateRxThread();
DWORD WINAPI RxThread(LPVOID par);
char*           g_AppName  = "AutsoarVirtualCOM";            //!< Application name which is displayed in VHWconf
XLportHandle    g_xlPortHandle              = XL_INVALID_PORTHANDLE;  //!< Global porthandle (we use only one!)
XLdriverConfig  g_xlDrvConfig;                                        //!< Contains the actual hardware configuration
XLaccess        g_xlChannelMask             = 0;                      //!< Global channelmask (includes all founded channels)
XLaccess        g_xlPermissionMask          = 0;                      //!< Global permissionmask (includes all founded channels)
unsigned int    g_BaudRate                  = 500000;                 //!< Default baudrate
unsigned char lInit;
XLhandle        g_hMsgEvent;                                          //!< notification handle for the receive queue

XLstatus CanInitDriver(XLaccess *pxlChannelMaskTx, unsigned char *pxlChannelIndex);
void FindifMCANConfigured(void);

void PC_CanInit(char* pAppNameP);


XLaccess  m_xlChannelMask[2];


void InitVectorCAN(void)
{
	if(lInit == 0)
	{
		PC_CanInit(g_AppName);
		lInit =1;
	}
	else
	{
	}	
}

void PC_CanInit(char* pAppNameP)
{
    XLstatus      xlStatus;
    XLaccess      xlChanMaskTx = 0;
    
    int           stop = 0;
    int           activated = 0;
    unsigned char xlChanIndex = 0;
    unsigned int  txID = 0x01;
    int           outputMode = XL_OUTPUT_MODE_NORMAL;

    g_AppName = pAppNameP;

    xlStatus = CanInitDriver(&xlChanMaskTx, &xlChanIndex);
    
    if(XL_SUCCESS == xlStatus) {
        // ------------------------------------
        // go with all selected channels on bus
        // ------------------------------------
		
        xlStatus = xlActivateChannel(g_xlPortHandle, g_xlChannelMask, XL_BUS_TYPE_CAN, XL_ACTIVATE_RESET_CLOCK);
		demoCreateRxThread();
        //MyTrace("- ActivateChannel  : CM=0x%I64x, %s\n", g_xlChannelMask, xlGetErrorString(xlStatus));
    }
    xlCanSetReceiveMode(g_xlPortHandle, 1, 1);
	xlCanSetChannelMode(g_xlPortHandle, g_xlChannelMask, 1, 1);
	xlSetNotification(g_xlPortHandle, &g_hMsgEvent, 1);
	xlSetTimerRate(g_xlPortHandle, 100);
    return;
}

////////////////////////////////////////////////////////////////////////////
//! CanInitDriver
//! initializes the driver with one port and all founded channels which
//! have a connected CAN cab/piggy.
//!
////////////////////////////////////////////////////////////////////////////
XLstatus CanInitDriver(XLaccess *pxlChannelMaskTx, unsigned char *pxlChannelIndex) {
    
    XLstatus          xlStatus;
    XLaccess          xlChannelMaskTx = 0;
    unsigned int      i;
    
    
    // ------------------------------------
    // open the driver
	// Each application must call this function to load the driver.
	// If this call is not successfully, no other API calls are possible
    // ------------------------------------
    xlStatus = xlOpenDriver ();
    
    // ------------------------------------
    // get/print the hardware configuration
    // ------------------------------------
    if(XL_SUCCESS == xlStatus) 
    {
	    // ---------------------------------------------------- 
	    // Allows reading out more detailed information about the used hardware.
		// The result describes the current state of the driver configuration after each call
		// ----------------------------------------------------
		/*
		
		       XLdriverConfig.dllVersion - Version of the driver
			   channelCount - Total number of channels available
			   reserved - Reserved field for future use.
			   channel - Structure containing channels information
		
		*/
        xlStatus = xlGetDriverConfig(&g_xlDrvConfig);
        //xlStatus = xlOpenDriver ();
    }
    
    if(XL_SUCCESS == xlStatus) 
    {
     //   CanPrintConfig();
      
        //MyTrace("Usage: xlCANdemo <BaudRate> <ApplicationName> <Identifier>\n\n");
        
        // ------------------------------------
        // select the wanted channels
        // ------------------------------------
        g_xlChannelMask = 0;
        for (i=0; i < g_xlDrvConfig.channelCount; i++) {
            
            // we take all hardware we found and
            // check that we have only CAN cabs/piggy's
            // at the moment there is no VN8910 XLAPI support!
            if (g_xlDrvConfig.channel[i].channelBusCapabilities & XL_BUS_ACTIVE_CAP_CAN) { 
                
                if (!*pxlChannelMaskTx) {
                    *pxlChannelMaskTx = g_xlDrvConfig.channel[i].channelMask;
                    *pxlChannelIndex  = g_xlDrvConfig.channel[i].channelIndex;
                }
                m_xlChannelMask[i] =g_xlDrvConfig.channel[i].channelMask;
               // printf("Found ActivateChannel \n");
                g_xlChannelMask |= g_xlDrvConfig.channel[i].channelMask;
            }
        }
        
        if (!g_xlChannelMask) {
            //MyTrace("ERROR: no available channels found! (e.g. no CANcabs...)\n\n");
            xlStatus = XL_ERROR;printf("Channel Mask error \n");
        }
    }
    
    g_xlPermissionMask = g_xlChannelMask;
    
    // ------------------------------------
    // open ONE port including all channels
    // ------------------------------------
    if(XL_SUCCESS == xlStatus) {
        xlStatus = xlOpenPort(&g_xlPortHandle, g_AppName, g_xlChannelMask, &g_xlPermissionMask, RX_QUEUE_SIZE, XL_INTERFACE_VERSION, XL_BUS_TYPE_CAN);
    }
    
    if ( (XL_SUCCESS == xlStatus) && (XL_INVALID_PORTHANDLE != g_xlPortHandle) ) {
        
		
        // ------------------------------------
        // if we have permission we set the
        // bus parameters (baudrate)
        // ------------------------------------
        if (0 != g_xlPermissionMask) {
            
            xlStatus = xlCanSetChannelBitrate(g_xlPortHandle, g_xlPermissionMask, g_BaudRate);
            xlCanSetChannelAcceptance(g_xlPortHandle,g_xlChannelMask,0,0,XL_CAN_STD);
            xlCanSetChannelAcceptance(g_xlPortHandle,g_xlChannelMask,0,0,XL_CAN_EXT);
            xlCanSetReceiveMode(g_xlPortHandle,1,1);
        } 
        else {
            //MyTrace("-                  : we have NO init access!\n");
        }
        
    }
    else {
        xlClosePort(g_xlPortHandle);
        g_xlPortHandle = XL_INVALID_PORTHANDLE;
        xlStatus = XL_ERROR;
    }
    
    return xlStatus;
    
}                    

XLstatus demoCreateRxThread()
{
	XLstatus      xlStatus;
	HANDLE g_hRXThread;
	if (g_xlPortHandle!= XL_INVALID_PORTHANDLE) {
	// Send a event for each Msg!!!
		xlStatus = xlSetNotification (g_xlPortHandle, &g_hMsgEvent, 1);
	
	}
	return xlStatus;
}

void WindowsEnterCriticalSectionOriginal (void);
void WindowsExitCriticalSectionOriginal (void);

uint8 CANIFStarted = 0;





XLstatus CANSend(XLevent xlEvent, int channel)
{
  XLstatus      xlStatus;
  unsigned int  messageCount = 1;
  xlStatus = xlCanTransmit(g_xlPortHandle, (g_xlChannelMask & ((uint8)0x01 << channel)), &messageCount, &xlEvent);
  return xlStatus;
}





unsigned char Can_Write_sim( Can_HwHandleType Hth,P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_CONST) PduInfo)
{

	XLevent xlEvent;
	XLstatus      xlStatus;
	int channel=0;
	int pdu_loaded = 0;
	int fl_count=0;
	channel =   GetCanIf_GetCtrlId(PduInfo->swPduHandle);
	while(fl_count < lNumOfTxPDus)
	{
		if((PduInfoS[fl_count].TxChannelId  == channel) &&
		   (PduInfoS[fl_count].TxPDUId  == PduInfo->swPduHandle) && 
		   (PduInfoS[fl_count].TxCANId == PduInfo->id))
		
		{
			pdu_loaded = 1;
			break;			
		}
		fl_count++;
	}
	
	if(pdu_loaded == 0)
	{
		PduInfoS[lNumOfTxPDus].TxChannelId = channel;
		PduInfoS[lNumOfTxPDus].TxPDUId = PduInfo->swPduHandle;
		PduInfoS[lNumOfTxPDus].TxCANId = PduInfo->id;
		lNumOfTxPDus++;
	}
	
	

	memset(&xlEvent, 0, sizeof(xlEvent));
	xlEvent.tag                 = XL_TRANSMIT_MSG;
	if(PduInfo->id > 0x7FF)
	{
		xlEvent.tagData.msg.id      = (XL_CAN_EXT_MSG_ID | PduInfo->id);//(unsigned int)  (LCanId);
	}
	else
	{
		xlEvent.tagData.msg.id      =PduInfo->id;
	}
	xlEvent.tagData.msg.dlc     = PduInfo->length;//(unsigned short)(Llength);
	memcpy(&xlEvent.tagData.msg.data[0],  PduInfo->sdu,	   PduInfo->length);
	xlEvent.tagData.msg.flags   = 0;
	xlStatus = CANSend(xlEvent, channel);

}

static uint8 GetCanIf_GetCtrlId(PduIdType CanTxPduId)
{
    /* Local Variables */
    CanIf_TxPduIdConfigType const *pCanIfTxPduIdConfig;
    CanIf_MailBoxConfigType const *pCanIfMailBoxConfig;
    uint16 MailBoxIndex;
    CanIf_ControllerIdType CtrlId = CANIF_NO_CAN_CONTROLLER_ID;

    /* Check Whether Pdu Id is valid */
    if (CANIF_NUM_OF_TX_PDU > CanTxPduId)
    {
        /* Read Tx Pdu Configuration */
        pCanIfTxPduIdConfig = &CanIf_TxPduIdConfig[CanTxPduId];
        /* Get MailBox Index */
        MailBoxIndex = pCanIfTxPduIdConfig -> TxPduHTHId;
        /* Check Whether Mail Box Index is valid */
        if (CANIF_NUM_OF_MAILBOX > MailBoxIndex)
        {
            /* Read Mailbox Configuration */
            pCanIfMailBoxConfig = &CanIf_MailBoxConfig[MailBoxIndex];
            /* Get Controller Index */
            CtrlId = pCanIfMailBoxConfig -> CanControllerId;
        }
    }
    /* return Ctrl Id */
    return CtrlId;
}


#define CANIF_CANID_MASK                                    0xC0000000u



static unsigned int TestCanIf_AcceptanceFilter (const Can_HwType* Mailbox, uint16 *CanIfRxPduId)
{
    /* Local Variables */
    CanIf_MailBoxConfigType const *pCanIfMailBoxConfig;
    CanIf_RxPduIdConfigType const *pCanIfRxPduIdConfig;
    CanIf_PduModeType CanIfPduMode;
    uint32 CanIfConfigMaskVal;
    Can_HwHandleType CanIfReceiveHohId;
    Can_IdType CanIfReceiveCanId;
    Can_IdType CanIfConfigCanId;
    CanIf_PduIdConfigIdType CanIfStartPduId;
    CanIf_PduIdConfigIdType CanIfEndPduId;
    CanIf_PduIdConfigIdType CanIfPduId;
    CanIf_ControllerIdType CanIfCtrlId;
    CanIf_RxSearchParamType CanIfRxSearchParam;
    boolean CanIfFilterAcceptSts = FALSE;
    unsigned int fl_count;
    unsigned int RetVal = CANIF_NUM_OF_MAILBOX;

    /* Get HoH Configuration */
   // CanIfReceiveHohId = Mailbox -> Hoh;
    for(fl_count = 0; ((fl_count < CANIF_NUM_OF_MAILBOX )&& (RetVal == CANIF_NUM_OF_MAILBOX)); fl_count++){
    /* Check whether Hoh Id is valid */
    	CanIfReceiveHohId = fl_count;
        if (CANIF_NUM_OF_MAILBOX > CanIfReceiveHohId)
        {
            /* Get Mail box Configuration */
            pCanIfMailBoxConfig = &CanIf_MailBoxConfig[CanIfReceiveHohId];
            /* Get Controller Id */
            CanIfCtrlId = pCanIfMailBoxConfig -> CanControllerId;
            /* Get Pdu Mode */
            CanIfPduMode = CANIF_ONLINE;//CanIf_GetCurrentPduMode(CanIfCtrlId);
            /* Check whether Pdu mode is ONLINE and requestd HOH is configured for Receive Operation*/
            if ((CANIF_OFFLINE != CanIfPduMode) &&
                (CANIF_CAN_OBJECT_TYPE_RECEIVE == pCanIfMailBoxConfig -> CanObjectType) &&
                (pCanIfMailBoxConfig -> CanControllerId == Mailbox->ControllerId))
            {
                /* Get Can Id */
                CanIfReceiveCanId =  ((Mailbox -> CanId) & (~CANIF_CANID_MASK));
                /* Get Start PduId */
                CanIfStartPduId = pCanIfMailBoxConfig -> PduStartId;
                /* Get End PduId */
                CanIfEndPduId = pCanIfMailBoxConfig -> PduEndId;
                /* Check whether CanHandleType is CANIF_CAN_HANDLE_TYPE_FULL_CAN */
                if (CANIF_CAN_HANDLE_TYPE_FULL_CAN == pCanIfMailBoxConfig -> CanHandleType)
                {
                    /* Check added to resolve coverity out of bound warning */
                    if (CANIF_NUM_OF_RX_PDU > CanIfStartPduId)
                    {
                        /* Get Rx Pdu Configuration */
                        pCanIfRxPduIdConfig = &CanIf_RxPduIdConfig[CanIfStartPduId];
                        /* Get Configured Can Id */
                        CanIfConfigCanId = pCanIfRxPduIdConfig -> RxPduCanId;
                        /* Get Configuration Mask Value */
                        CanIfConfigMaskVal = CanIf_RxGetCanIdMask(pCanIfRxPduIdConfig -> RxCanIdMaskIdx);
                        /* Check if the requested canId is associated with HoH */
                        if (CanIfReceiveCanId == (CanIfConfigCanId & CanIfConfigMaskVal))
                        {
                            *CanIfRxPduId = CanIfStartPduId;
                            RetVal = fl_count;
                            /* Set CanId availability Status */
                            CanIfFilterAcceptSts = TRUE;
                            break;
                        }
                    }
                }
                else
                {				
                    CanIfRxSearchParam.RxStartPduId = pCanIfMailBoxConfig -> PduStartId;
                    CanIfRxSearchParam.RxEndPduId =pCanIfMailBoxConfig -> PduEndId;
                    CanIfRxSearchParam.RcvdCanId = CanIfReceiveCanId;
                    CanIfRxSearchParam.RcvdRxPduId = 0U;
                    /*Search whether the requested CanId is present in HOH List */
                    #if (CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_LINEAR)
                    /* linear Search */
                    CanIfFilterAcceptSts=CanIf_RxMessageLinearSearch(&CanIfRxSearchParam);	
                    #elif (CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_BINARY)
                    /* Binary Search */
                    CanIfFilterAcceptSts=CanIf_RxMessageBinarySearch(&CanIfRxSearchParam);
                    #elif (CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_TABLE)
                    /* Double Hash */
                    CanIfFilterAcceptSts=CanIf_RxMessageDoubleHashSearch(&CanIfRxSearchParam);
                    #elif (CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_INDEX)
                    /* Double Hash */
                    CanIfFilterAcceptSts=CanIf_RxMessageIndexSearch(&CanIfRxSearchParam);
                    #else
                    CanIfFilterAcceptSts = FALSE;
                    #endif
                    if (TRUE == CanIfFilterAcceptSts)
                    {
                        *CanIfRxPduId = CanIfRxSearchParam.RcvdRxPduId;
                        RetVal = fl_count;
                        break;
                    }
                }
            }
        }
    }
    return RetVal;
}
  
PduIdType FindCANTxPDUType(Can_IdType pTxCANID,int channelId )
{
	PduIdType PduRet = CANIF_NUM_OF_TX_PDU; 
	int fl_count=0;
	
	if(lNumOfTxPDus > 0)
	{
		while(fl_count < lNumOfTxPDus)
		{
			if((PduInfoS[fl_count].TxCANId == pTxCANID) &&
			   (PduInfoS[fl_count].TxChannelId == channelId))
			{
				PduRet = PduInfoS[fl_count].TxPDUId;
				break;			
			}
			fl_count++;
		}
	}
	return(PduRet);
}
static unsigned int lPrevTime;
void CANReceiveEventThread(void)
{
#define TOTAL_EVENTS 100
	XLstatus        xlStatus;

	unsigned int    msgsrx = TOTAL_EVENTS;
	XLevent         xlEvent[TOTAL_EVENTS];
	Can_HwType  Mailbox;
	PduInfoType PduInfoPtr;
	uint16 CanIfRxPduId;
    unsigned int Hrhindex;
	msgsrx = TOTAL_EVENTS;
	while(g_xlPortHandle == XL_INVALID_PORTHANDLE )
	{
		sleep(1);
	}
	xlCanFlushTransmitQueue(g_xlPortHandle,3);
	memset(&xlEvent[0], 0, sizeof(xlEvent));
	xlStatus = xlReceive(g_xlPortHandle, &msgsrx, &xlEvent[0]);
	
	if (!xlStatus) {
		for(int flCount =0; flCount< msgsrx; flCount++)
		{
			if(xlEvent[flCount].tagData.msg.flags ==0)
			{
				if(xlEvent[flCount].tag == XL_RECEIVE_MSG)
				{			
					Mailbox.CanId = (xlEvent[flCount].tagData.msg.id & ~(0x80000000));
					Mailbox.ControllerId = xlEvent[flCount].chanIndex;
					Mailbox.Hoh = TestCanIf_AcceptanceFilter(&Mailbox,&CanIfRxPduId);
					if(Mailbox.Hoh != CANIF_NUM_OF_MAILBOX)
					{
						Mailbox.CanId = (xlEvent[flCount].tagData.msg.id & ~(0x80000000));
						Mailbox.ControllerId = xlEvent[flCount].chanIndex;
						PduInfoPtr.SduLength = xlEvent[flCount].tagData.msg.dlc;
						PduInfoPtr.SduDataPtr = &xlEvent[flCount].tagData.msg.data[0];
						WindowsEnterCriticalSectionOriginal(); 
						CanIf_RxIndication(&Mailbox, &PduInfoPtr );
						WindowsExitCriticalSectionOriginal();
						

					}
				}
			}
			else if((xlEvent[flCount].tagData.msg.flags & XL_CAN_MSG_FLAG_TX_COMPLETED ) != 0) 
			{
				WindowsEnterCriticalSectionOriginal(); 
				CanIf_TxConfirmation(FindCANTxPDUType(xlEvent[flCount].tagData.msg.id,xlEvent[flCount].chanIndex));
				WindowsExitCriticalSectionOriginal();
			}
			else
			{
			}
		}
	}
}

#if (CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_LINEAR)
/********************************************************************************************************************
*   @brief      This method is uses linear filter algo to do SW filtering of the received can id
*   @param[in]  pRxSearchParam pointer to the search parmaters
*   @return     boolean returns tbe status . TRUE if can id is valid , FALSE if can id is invalid
********************************************************************************************************************/
boolean CanIf_RxMessageLinearSearch
(
    CanIf_RxSearchParamType *pRxSearchParam
)
{
	Can_IdType ConfigCanId;
	uint32 ConfigMaskVal=0;
	boolean RxFilterAcceptSts=FALSE;
	CanIf_PduIdConfigIdType RxPduIdx = 0U;
	P2CONST(CanIf_RxPduIdConfigType,AUTOMATIC,CANIF_APPL_CONST) pRxPduIdConfig;
	/*Search whether the requested CanId is present in HOH List */
	for (RxPduIdx = pRxSearchParam->RxStartPduId; 
		((RxPduIdx <= pRxSearchParam->RxEndPduId) && (CANIF_NUM_OF_RX_PDU > pRxSearchParam->RxStartPduId) && (CANIF_NUM_OF_RX_PDU > pRxSearchParam->RxEndPduId) && (FALSE == RxFilterAcceptSts));
		RxPduIdx++)
	{
		/* Get Rx Pdu Configuration */
		pRxPduIdConfig = &CanIf_RxPduIdConfig[RxPduIdx];
		/* Get Configured Can Id */
		ConfigCanId = pRxPduIdConfig -> RxPduCanId;
		/* Get Configuration Mask Value */
		ConfigMaskVal = CanIf_RxGetCanIdMask(pRxPduIdConfig->RxCanIdMaskIdx);
		/* Check if the requested canId is associated with HoH */
		if ((pRxSearchParam->RcvdCanId & ConfigMaskVal) == (ConfigCanId & ConfigMaskVal))
		{
			pRxSearchParam->RcvdRxPduId = RxPduIdx;
			/* Set CanId availability Status */
			RxFilterAcceptSts = TRUE;
		}
	}
	return RxFilterAcceptSts;
}
#endif

#if (CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_BINARY)
/********************************************************************************************************************
*   @brief      This method is uses binary filter algo to do SW filtering of the received can id
*   @param[in]  pRxSearchParam pointer to the search parmaters
*   @return     boolean returns tbe status . TRUE if can id is valid , FALSE if can id is invalid
********************************************************************************************************************/
boolean CanIf_RxMessageBinarySearch
(
    CanIf_RxSearchParamType *pRxSearchParam
)
{
	boolean RxFilterAcceptSts=FALSE;
	CanIf_PduIdConfigIdType RxPduStartIdx=0U;
	CanIf_PduIdConfigIdType RxPduMidIdx=0U;
	CanIf_PduIdConfigIdType RxPduEndIdx=0U;
	Can_IdType RxConfigStartCanId,RxConfigEndCanId;
	uint32 RxConfigStartMaskVal=0U,RxConfigEndMaskVal=0U,RxConfigMidMaskVal=0U;
    P2CONST(CanIf_RxPduIdConfigType,AUTOMATIC,CANIF_APPL_CONST) pRxPduIdConfig;
	
	/* Intialize start and end id */
	RxPduStartIdx = pRxSearchParam->RxStartPduId;
	RxPduEndIdx = pRxSearchParam->RxEndPduId;
    if ((CANIF_NUM_OF_RX_PDU > RxPduStartIdx) &&
        (CANIF_NUM_OF_RX_PDU > RxPduEndIdx))
    {
        /* Initialize start Id mask */
        pRxPduIdConfig = &CanIf_RxPduIdConfig[RxPduStartIdx];
        RxConfigStartCanId = pRxPduIdConfig -> RxPduCanId;
        RxConfigStartMaskVal = CanIf_RxGetCanIdMask(pRxPduIdConfig->RxCanIdMaskIdx);
        /* Initialize end Id mask */
        pRxPduIdConfig = &CanIf_RxPduIdConfig[RxPduEndIdx];
        RxConfigEndCanId = pRxPduIdConfig -> RxPduCanId;
        RxConfigEndMaskVal = CanIf_RxGetCanIdMask(pRxPduIdConfig->RxCanIdMaskIdx);
        while((RxPduEndIdx-RxPduStartIdx)>1U)
        {
            /* Get the Middle pduId */
            RxPduMidIdx = (RxPduStartIdx+RxPduEndIdx)/2U;
            
            /* Get Rx Pdu Configuration */
            pRxPduIdConfig = &CanIf_RxPduIdConfig[RxPduMidIdx];
            /* Get Mask Value */
            RxConfigMidMaskVal = CanIf_RxGetCanIdMask(pRxPduIdConfig->RxCanIdMaskIdx);
            /* if Configured CanId is less than the received ID neglect the elements before mid element,
               else neglect the elements after mid element */
            if((pRxPduIdConfig -> RxPduCanId &  RxConfigMidMaskVal) < \
               (pRxSearchParam -> RcvdCanId & RxConfigMidMaskVal))
            {
                RxPduStartIdx = RxPduMidIdx+1U;
                if (CANIF_NUM_OF_RX_PDU > RxPduStartIdx)
                {
                    pRxPduIdConfig = &CanIf_RxPduIdConfig[RxPduStartIdx];
                    /* Get Configured Can Id */
                    RxConfigStartCanId = pRxPduIdConfig -> RxPduCanId;
                    /* Get Configuration Mask Value */
                    RxConfigStartMaskVal = CanIf_RxGetCanIdMask(pRxPduIdConfig->RxCanIdMaskIdx);
                }
                else
                {
                    /* invalid id configuration ,then exit the search */
                    break;
                }
            }
            else 
            {
                RxPduEndIdx = RxPduMidIdx;
                pRxPduIdConfig = &CanIf_RxPduIdConfig[RxPduEndIdx];
                /* Get Configured Can Id */
                RxConfigEndCanId = pRxPduIdConfig -> RxPduCanId;
                /* Get Configuration Mask Value */
                RxConfigEndMaskVal = CanIf_RxGetCanIdMask(pRxPduIdConfig->RxCanIdMaskIdx);
            }
        }
        /* if Id match with start or End then the received id is found else it is not found */
        if ((pRxSearchParam->RcvdCanId & RxConfigStartMaskVal) == (RxConfigStartCanId & RxConfigStartMaskVal))
                
        {
            pRxSearchParam->RcvdRxPduId = RxPduStartIdx;
            /* Set CanId availability Status */
            RxFilterAcceptSts = TRUE;
        }
        else if (((pRxSearchParam->RcvdCanId) & RxConfigEndMaskVal) == (RxConfigEndCanId & RxConfigEndMaskVal))
        {
            pRxSearchParam->RcvdRxPduId = RxPduEndIdx;
            /* Set CanId availability Status */
            RxFilterAcceptSts = TRUE;
        }
        else
        {
            RxFilterAcceptSts = FALSE;
        }
    }
	return RxFilterAcceptSts;
}
#endif

#if (CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_TABLE)
/********************************************************************************************************************
*   @brief      This method is uses double hash filter algo to do SW filtering of the received can id
*   @param[in]  pRxSearchParam pointer to the search parmaters
*   @return     boolean returns tbe status . TRUE if can id is valid , FALSE if can id is invalid
********************************************************************************************************************/
boolean CanIf_RxMessageDoubleHashSearch
(
    CanIf_RxSearchParamType *pRxSearchParam
)
{
	uint32 RxCanIdMask=0U;
	Can_IdType RxHashValue=0U;
	CanIf_RxHashTableSizeType RxHashOffset=0U;
	boolean RxFilterAcceptSts=FALSE,RxIsSearchValid=TRUE;
	P2CONST(CanIf_RxPduIdConfigType,AUTOMATIC,CANIF_APPL_CONST) pRxPduIdConfig;
	P2CONST(CanIf_RxHashTableType,AUTOMATIC,CANIF_APPL_CONST) pRxHashTableRef;  
	P2CONST(CanIf_RxHashTableConfigType,AUTOMATIC,CANIF_APPL_CONST) pRxHashTableConfig;
	
    if (CANIF_NUM_OF_RX_PDU > pRxSearchParam->RxStartPduId)
    {
        pRxPduIdConfig = &CanIf_RxPduIdConfig[pRxSearchParam->RxStartPduId];
        if (CANIF_RX_NUM_OF_HASH_TABLE> pRxPduIdConfig->RxHashTableId)
        {
            pRxHashTableConfig = &CanIf_RxHashTableConfig[pRxPduIdConfig->RxHashTableId];
            
            do
            {
                /* Calculate the Hash Index */
                RxHashValue = ((CANIF_UTILGETHASH1(pRxSearchParam->RcvdCanId,pRxHashTableConfig->RxHashTableSize)) + \
                            (RxHashOffset * (CANIF_UTILGETHASH2(pRxSearchParam->RcvdCanId,
                             pRxHashTableConfig->RxHash2PrimeNum))))% pRxHashTableConfig->RxHashTableSize;
                            
                if (pRxHashTableConfig->RxHashTableSize > RxHashValue)
                {
                    pRxHashTableRef = &(pRxHashTableConfig->pRxRxHashTableRef[RxHashValue]);
                    /* If the Id is available in the Hash Index , then update the return status as TRUE and
                       Update the received RxPduId */
                    if (pRxHashTableRef->RxCanId != pRxHashTableConfig->RxHashTableEmptyValue )
                    {
                        if((pRxHashTableRef->RxCanId == pRxSearchParam->RcvdCanId) &&
                            (CANIF_NUM_OF_RX_PDU > pRxHashTableRef->RxPduId))
                        {
                            pRxPduIdConfig = &CanIf_RxPduIdConfig[pRxHashTableRef->RxPduId];
                            RxCanIdMask = CanIf_RxGetCanIdMask(pRxPduIdConfig->RxCanIdMaskIdx);
                            if ((pRxHashTableRef->RxCanId & RxCanIdMask) == \
                                (pRxPduIdConfig->RxPduCanId & RxCanIdMask))
                            {
                                pRxSearchParam->RcvdRxPduId = pRxHashTableRef->RxPduId;
                                RxFilterAcceptSts = TRUE;
                            }
                            /* msg found , hence exit from search */
                            RxIsSearchValid = FALSE;
                        }
                    }
                    else
                    {
                        /* Empty value reached in the hash */
                        RxIsSearchValid = FALSE;
                    }
                }
                else
                {
                    /* Invalid hash value/configuration exit the loop */
                    RxIsSearchValid = FALSE;
                }
                /* If Id is not there , increase the offset and check in the next slot */
                RxHashOffset++;
            }while((RxHashOffset < pRxHashTableConfig->RxHashTableSize)&& (FALSE != RxIsSearchValid));
        }/* (CANIF_RX_NUM_OF_HASH_TABLE> pRxPduIdConfig->RxHashTableId) */
    }/* ((CANIF_NUM_OF_RX_PDU > pRxSearchParam->RxStartPduId) */        
	return RxFilterAcceptSts;
}
#endif

#if (CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_INDEX)
/********************************************************************************************************************
*   @brief      This method is uses index search filter algo to do SW filtering of the received can id
*   @param[in]  pRxSearchParam pointer to the search parmaters
*   @return     boolean returns tbe status . TRUE if can id is valid , FALSE if can id is invalid
********************************************************************************************************************/
boolean CanIf_RxMessageIndexSearch
(
    CanIf_RxSearchParamType *pRxSearchParam
)
{
    uint32 RxCanIdMask=0U;
	boolean RxFilterAcceptSts=FALSE;
	CanIf_PduIdConfigIdType RxSubGrpIdx=0u,RxPduIdx=0U;
	CanIf_PduIdConfigIdType RxNumOfPduIds=0u,RxNumOfSubGrp=0u;
	CanIf_PduIdConfigIdType RxNextSubGrpStartIdx=0u,RxNextSubGrpEndIdx=0U;
	P2CONST(CanIf_RxPduIdConfigType,AUTOMATIC,CANIF_APPL_CONST) pRxPduIdConfig;

    if ( CANIF_NUM_OF_RX_PDU > pRxSearchParam->RxStartPduId)
    {
        /*Search whether the requested CanId is present in HOH List */
        pRxPduIdConfig = &CanIf_RxPduIdConfig[pRxSearchParam->RxStartPduId];
        RxNumOfPduIds = ((pRxSearchParam->RxEndPduId)-(pRxSearchParam->RxStartPduId))+1U;
        /* Find the number of subgroups based on the group number */
        if(0U == (RxNumOfPduIds%CANIF_INDEX_FILTER_GROUP_NUMBER))
        {
            RxNumOfSubGrp = RxNumOfPduIds/CANIF_INDEX_FILTER_GROUP_NUMBER;
        }
        else
        {
            RxNumOfSubGrp = (RxNumOfPduIds/CANIF_INDEX_FILTER_GROUP_NUMBER)+1U;
        }		
        /* Process if the received Id is greater than the first subgroup Can Id*/
        if (pRxSearchParam->RcvdCanId >= pRxPduIdConfig->RxPduCanId)
        {
            for (RxSubGrpIdx=0;((RxSubGrpIdx<RxNumOfSubGrp) && 
                (RxFilterAcceptSts == FALSE));RxSubGrpIdx++)
            {
                /* update the subgroup start idx */
                RxNextSubGrpStartIdx = pRxSearchParam->RxStartPduId+(RxSubGrpIdx*CANIF_INDEX_FILTER_GROUP_NUMBER);
                /* Calculate End Group PduId */
                if (pRxSearchParam->RxEndPduId >= (RxNextSubGrpStartIdx+CANIF_INDEX_FILTER_GROUP_NUMBER))
                {
                    RxNextSubGrpEndIdx = RxNextSubGrpStartIdx+CANIF_INDEX_FILTER_GROUP_NUMBER-1U;
                }
                else
                {
                    if (((pRxSearchParam->RxEndPduId)-RxNextSubGrpEndIdx) == 0u)
                    {
                         RxNextSubGrpEndIdx += ((pRxSearchParam->RxEndPduId)-RxNextSubGrpEndIdx+1U);
                    }
                    else
                    {
                        RxNextSubGrpEndIdx += ((pRxSearchParam->RxEndPduId)-RxNextSubGrpEndIdx);
                    }
                } /*(pRxSearchParam->RxEndPduId >= (RxNextSubGrpStartIdx+CANIF_INDEX_FILTER_GROUP_NUMBER)) */
                /* Get sub group RxPdu configuration*/ 
                if (CANIF_NUM_OF_RX_PDU > RxNextSubGrpEndIdx)
                {
                    pRxPduIdConfig = &CanIf_RxPduIdConfig[RxNextSubGrpEndIdx];
                    if (pRxSearchParam->RcvdCanId <= pRxPduIdConfig->RxPduCanId)
                    {
                        /* Do Sequencial search in the subgroup for the received ID */
                        for(RxPduIdx=RxNextSubGrpStartIdx;RxPduIdx<=RxNextSubGrpEndIdx;RxPduIdx++)
                        {
                            pRxPduIdConfig = &CanIf_RxPduIdConfig[RxPduIdx];
                            RxCanIdMask = CanIf_RxGetCanIdMask(pRxPduIdConfig->RxCanIdMaskIdx); 
                            /* If Id found update the RxPduId and update the return status */
                            if((pRxSearchParam->RcvdCanId & RxCanIdMask) == \
                                (pRxPduIdConfig->RxPduCanId & RxCanIdMask))
                            {
                                pRxSearchParam->RcvdRxPduId = RxPduIdx;
                                RxFilterAcceptSts = TRUE;
                                break;
                            }
                        }
                    }/*(pRxSearchParam->RcvdCanId <= pRxPduIdConfig->RxPduCanId) */
                }
                else
                {
                    /* Invalid configuration */
                    break;
                }
            } /* sub group loop */
        }	/* (pRxSearchParam->RcvdCanId >= pRxPduIdConfig->RxPduCanId) */
    } /* CANIF_NUM_OF_RX_PDU > pRxSearchParam->RxStartPduId */
	return RxFilterAcceptSts;
}
#endif

uint32 CanIf_RxGetCanIdMask(CanIf_RxCanIdMaskIdxType CanIf_RxCanIdMaskIdx)
{
	uint32 RxCanIdMask = 0U;
	
	/* find the mask from the configuration */
	if (CANIF_NUM_OF_RX_CAN_ID_MASKS > CanIf_RxCanIdMaskIdx)
	{
		RxCanIdMask = CanIf_RxCanIdMaskConfig[CanIf_RxCanIdMaskIdx];
	}
	else
	{
		RxCanIdMask = 0U;
	}
	
	return RxCanIdMask;
}

#undef OS_H	


