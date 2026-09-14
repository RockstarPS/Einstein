//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2017] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
/*****************************************************************************
*  File Name         :  ComMExt.c                                            *
*  Module Short Name :  ComMExt                                              *
*  Description       :  This file contains implementations of the COM        *
*                       State Manager callouts specified by AUTOSAR          *
*                       This is an integration code for ComM                 *
*                                                                            *
* Organization       :  Driver Information Software Section,                 *
*                       Visteon Software Operation                           *
*                       Visteon Corporation                                  *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name      :  GHS Multi                                            *
* Target Hardware    :  Platform Independent                                 *
*                                                                            *
******************************************************************************/

#include "ComMExt.h"
//#include "Rte_ComMExt.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
//#include "Dio.h"
//#include "PduR_Com.h"
#include "Com.h"
#include "Com_Lcfg.h"
#include "Stubs.h"
#include "Rte_IoHwAb_Type.h"

#if (COMMEXT_IS_CAN_SUPPORTED == STD_ON)
//#include "Can_Cfg.h"
#include "CanIf.h"
#endif

#if (COMMEXT_IS_NM_SUPPORTED == STD_ON)
#include "CanNm.h"
#include "Nm.h"
#endif


/********************************************************************************************************************
*  Public Macro Definitions                                                                                         *
********************************************************************************************************************/
/* Value of disabled interrupt */
#define COMMEXT_INTR_DISABLED                          0u
/* Value of enabled interrupt */
#define COMMEXT_INTR_ENABLED                           1u
/* Value of enable interrupt through task */
#define COMMEXT_ENABLE_INTR_IN_TASK                    2u

/********************************************************************************************************************
*  Public Macro Timer Definitions                                                                                         *
********************************************************************************************************************/

/********************************************************************************************************************
*  Private variables                                                                                                *
********************************************************************************************************************/
/* Store Initialization status */
static boolean ComMExt_IsInitialized = FALSE; /* MISRA warning fix, CID 10542980 and 10557662 */
/* Store COM IPDU group mask for communication control service */
static Com_IpduGroupVector ComMExt_IpduGroupVector;
#if (COMMEXT_NUMBER_OF_COM_CHANNELS > 0u)
/* Store current Interrupt status for all COM channels */
static uint8 ComMExt_InterruptStatus[COMMEXT_NUMBER_OF_COM_CHANNELS]; /* MISRA warning fix, CID 10466778 */
#endif
static boolean ComMExt_PduGrpTriggred = FALSE;

/********************************************************************************************************************
*  Private functions                                                                                                *
********************************************************************************************************************/
/*****************************************************************************************************************
** @brief             Disables interrupt for given channel
**
** Function Name    : ComMExt_Wakeup_Interrupt_Disable
**
** Visibility       : Private
**
** Invocation       : COM channel wake up trigger from ComMExt_CAN_RequestCommunication
**
** Critical Section : None
**
** @param[in]         Channel - Channel index
**
** @param[out]        None
**
** @return            None
**
** @ingroup           ComMExt
**
*****************************************************************************************************************/
static void ComMExt_Wakeup_Interrupt_Disable(UInt8 Channel);

/*!***************************************************************************************************************
** @brief             Enables interrupt for given channel
**
** Function Name    : ComMExt_Wakeup_Interrupt_Enable
**
** Visibility       : Private
**
** Invocation       : COM channel sleep trigger from ComMExt_CAN_ReleaseCommunication
**
** Critical Section : None
**
** @param[in]         Channel - Channel index
**
** @param[out]        None
**
** @return            None
**
** @ingroup           ComMExt
**
*****************************************************************************************************************/
static void ComMExt_Wakeup_Interrupt_Enable(UInt8 Channel);
//static void ComMExt_Ipducontrol_Handling(void);

/*****************************************************************************************************************
*  PUBLIC FUNCTIONS DEFINITIONS
*****************************************************************************************************************/
/*!***************************************************************************************************************
**
** @brief             This interface initializes COM modules
**
** Function Name    : ComMExt_Init
**
** Visibility       : Public
**
** Invocation       : Called from EcuM_AL_DriverInitTwo in EcuMExt
**
** Critical Section : None
**
** @param[in]         None
**
** @param[out]        None
**
** @return            None
**
** @ingroup           ComMExt
**
*****************************************************************************************************************/
FUNC(void, ComMExt_CODE) ComMExt_Init(void)
{
#if (COMMEXT_NUMBER_OF_COM_CHANNELS > 0u)
    uint8 Channel;
    for (Channel=0u; Channel < COMMEXT_NUMBER_OF_COM_CHANNELS; Channel++)
    {
        ComMExt_InterruptStatus[Channel] = COMMEXT_INTR_ENABLED;
    }
#endif
    Com_ClearIpduGroupVector(ComMExt_IpduGroupVector);
    ComMExt_PduGrpTriggred = FALSE;
    ComMExt_IsInitialized = TRUE;
}

/*!***************************************************************************************************************
**
** @brief             ComMExt 10ms periodic function
**
** Function Name    : ComMExt_Impl_MainFunction
**
** Visibility       : Public
**
** Invocation       : Called periodically from OsTask_10msCAN on 10ms periodic event
**
** Critical Section : None
**
** @param[in]         None
**
** @param[out]        None
**
** @return            None
**
** @ingroup           ComMExt
**
*****************************************************************************************************************/
FUNC(void, ComMExt_CODE) ComMExt_Impl_MainFunction(void)
{
    if(ComMExt_IsInitialized)
    {
#if (COMMEXT_NUMBER_OF_COM_CHANNELS > 0u)
        ComM_ModeType ComMode = COMM_NO_COMMUNICATION;
        UInt8 Channel;
#endif

//        ComMExt_Local_MainFunction(); // Invoke Runnables of modules which are not supported in DaVinci. Avoid manual update in Rte( DaVinci generated).

#if (COMMEXT_NUMBER_OF_COM_CHANNELS > 0u)
        for(Channel = 0u; Channel < COMMEXT_NUMBER_OF_COM_CHANNELS; Channel++)
        {
            (void)ComM_GetCurrentComMode(Channel, &ComMode);    // Get communication state
            if(ComMode == COMM_NO_COMMUNICATION)
            {
                if(ComMExt_InterruptStatus[Channel] == COMMEXT_ENABLE_INTR_IN_TASK)
                {
                    ComMExt_Wakeup_Interrupt_Enable(Channel);    // Enable interrupt if sleep success
                }
            }
        }
#endif
//        ComMExt_Ipducontrol_Handling();
    }
}


/*!***************************************************************************************************************
**
** @brief             Suspends transmission of all messages for given CAN channel
**
** Function Name    : ComMExt_CAN_ActivateSilentCommunication
**
** Visibility       : Public
**
** Invocation       : Called from CanNmCtrl module
**
** Critical Section : None
**
** @param[in]         Channel - CAN channel index
**
** @param[out]        None
**
** @return            RTE_E_OK - Success \n
**                    RTE_E_INVALID - Incorrect channel index
**
** @ingroup           ComMExt
**
*****************************************************************************************************************/
FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_ActivateSilentCommunication(UInt8 Channel)
{
    Std_ReturnType retval = RTE_E_INVALID;

#if (COMMEXT_IS_CAN_SUPPORTED == STD_ON)
    if(Channel >= COMMEXT_NUMBER_OF_CAN_CHANNELS) /*CERT C 17224623*/
    {
        retval = RTE_E_INVALID;
    }
    else
    {
        retval = CanIf_SetPduMode(Channel , CANIF_TX_OFFLINE); /* CANIF_SET_TX_OFFLINE_ACTIVE */
    }
#endif
    return retval;
}


/*!***************************************************************************************************************
**
** @brief             Resumes transmission of all messages for given CAN channel
**
** Function Name    : ComMExt_CAN_DeActivateSilentCommunication
**
** Visibility       : Public
**
** Invocation       : Called from CanNmCtrl module
**
** Critical Section : None
**
** @param[in]         Channel - CAN channel index
**
** @param[out]        None
**
** @return            RTE_E_OK - Success \n
**                    RTE_E_INVALID - Incorrect channel index
**
** @ingroup           ComMExt
**
*****************************************************************************************************************/
FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_DeActivateSilentCommunication(UInt8 Channel)
{
    Std_ReturnType retval = RTE_E_INVALID;

#if (COMMEXT_IS_CAN_SUPPORTED == STD_ON)
    if(Channel >= COMMEXT_NUMBER_OF_CAN_CHANNELS) /*CERT C 17225638*/
    {
        retval = RTE_E_INVALID;
    }
    else
    {
        retval = CanIf_SetPduMode(Channel , CANIF_ONLINE); /* CANIF_SET_TX_ONLINE */
    }
#endif
    return retval;
}


/*!***************************************************************************************************************
**
** @brief             Suspends reception of signal values for given COM channel
**
** Function Name    : ComMExt_CAN_CommControlDeActivateRx
**
** Visibility       : Public
**
** Invocation       : Called from DcmExt module for communication control diagnostic service
**
** Critical Section : None
**
** @param[in]         Channel - COM channel index
**
** @param[out]        None
**
** @return            RTE_E_OK - Success \n
**                    RTE_E_INVALID - Incorrect channel index
**
** @ingroup           ComMExt
**
**
**
*****************************************************************************************************************/
FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_CommControlDeActivateRx(ComMExt_IpduGroupId GroupId)
{
	Std_ReturnType retval = RTE_E_OK;
	if(GroupId < COMMEXT_NUMBER_OF_IPDU_GROUPS)
    {
		/* Disable COM RX IPDU Group */
        Com_SetIpduGroup(ComMExt_IpduGroupVector, (Com_IpduGroupIdType)GroupId, (boolean)FALSE); /*CERT C 17224000*/
    }
	return(retval);
}

/*!***************************************************************************************************************
**
** @brief             Resumes reception of signal values for given COM channel
**
** Function Name    : ComMExt_CAN_CommControlActivateRx
**
** Visibility       : Public
**
** Invocation       : Called from DcmExt module for communication control diagnostic service
**
** Critical Section : None
**
** @param[in]         Channel - COM channel index
**
** @param[out]        None
**
** @return            RTE_E_OK - Success \n
**                    RTE_E_INVALID - Incorrect channel index
**
** @ingroup           ComMExt
**
*****************************************************************************************************************/
FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_CommControlActivateRx(ComMExt_IpduGroupId GroupId)
{
	Std_ReturnType retval = RTE_E_OK;
	if(GroupId < COMMEXT_NUMBER_OF_IPDU_GROUPS)
    {
		/* Enable COM RX IPDU Group */
        Com_SetIpduGroup(ComMExt_IpduGroupVector, (Com_IpduGroupIdType)GroupId, (boolean)TRUE); /*CERT C 17225639*/
    }
	return(retval);
}

/*!***************************************************************************************************************
**
** @brief             Suspends application and NM messages transmission of given COM channel
**
** Function Name    : ComMExt_CAN_CommControlDeActivateTx
**
** Visibility       : Public
**
** Invocation       : Called from DcmExt module for communication control diagnostic service
**
** Critical Section : None
**
** @param[in]         Channel - COM channel index
**
** @param[out]        None
**
** @return            RTE_E_OK - Success \n
**                    RTE_E_INVALID - Incorrect channel index
**
** @ingroup           ComMExt
**
*****************************************************************************************************************/
FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_CommControlDeActivateTx(ComMExt_IpduGroupId GroupId)
{
	Std_ReturnType retval = RTE_E_OK;
	if(GroupId < COMMEXT_NUMBER_OF_IPDU_GROUPS)
    {
		/* Disable COM TX IPDU Group */
        Com_SetIpduGroup(ComMExt_IpduGroupVector, (Com_IpduGroupIdType)GroupId, (boolean)FALSE); /*CERT C 17223816*/
    }
	return(retval);
}

/*!***************************************************************************************************************
**
** @brief             Resumes application and NM messages transmission for given COM channel
**
** Function Name    : ComMExt_CAN_CommControlActivateTx
**
** Visibility       : Public
**
** Invocation       : Called from DcmExt module for communication control diagnostic service
**
** Critical Section : None
**
** @param[in]         Channel - COM channel index
**
** @param[out]        None
**
** @return            RTE_E_OK - Success \n
**                    RTE_E_INVALID - Incorrect channel index
**
** @ingroup           ComMExt
**
*****************************************************************************************************************/
FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_CommControlActivateTx(ComMExt_IpduGroupId GroupId)
{
	Std_ReturnType retval = RTE_E_OK;
	if(GroupId < COMMEXT_NUMBER_OF_IPDU_GROUPS)
    {
		/* Enable COM TX IPDU Group */
        Com_SetIpduGroup(ComMExt_IpduGroupVector, (Com_IpduGroupIdType)GroupId, (boolean)TRUE);/*CERT C 17226148*/
    }
	return(retval);
}

/*!***************************************************************************************************************
**
** @brief             Activates Suspend or Resume of COM messages
**
** Function Name    : ComMExt_CAN_CommControlSetDone
**
** Visibility       : Public
**
** Invocation       : Called from DcmExt module for communication control diagnostic service
**
** Critical Section : None
**
** @param[in]         PduInitRequest - PDU initialization status. TRUE - PDU initialized. FALSE - PDU not initialized
**
** @param[out]        None
**
** @return            None
**
** @ingroup           ComMExt
**
*****************************************************************************************************************/
FUNC(void, ComMExt_CODE) ComMExt_CAN_CommControlSetDone(boolean PduInitRequest)
{
	Com_IpduGroupControl(ComMExt_IpduGroupVector, (boolean)PduInitRequest);
    ComMExt_PduGrpTriggred = TRUE;
}

/*!***************************************************************************************************************
**
** @brief             Provides current communication mode of given COM channel
**
** Function Name    : ComMExt_CAN_GetCurrentComMode
**
** Visibility       : Public
**
** Invocation       : Called from CanNmCtrl module
**
** Critical Section : None
**
** @param[in]         Channel - COM channel index
**
** @param[out]        ComMode - Current communication mode
**
** @return            RTE_E_OK - Success \n
**                    RTE_E_INVALID - Incorrect channel index
**
** @ingroup           ComMExt
**
*****************************************************************************************************************/
FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_GetCurrentComMode(UInt8 Channel, P2VAR(UInt8, AUTOMATIC, RTE_COMMEXT_APPL_VAR) ComMode)
{
    Std_ReturnType retval = RTE_E_INVALID;

    if(Channel >= COMMEXT_NUMBER_OF_COM_CHANNELS)
    {
        retval = RTE_E_INVALID;
    }
    else
    {
        (void)ComM_GetCurrentComMode(Channel, ComMode);    // NULL_PTR validation for "ComMode" handled in invoked function
        retval = RTE_E_OK;
    }
    return retval;
}

/*!***************************************************************************************************************
** @brief             Triggers sleep for given COM channel
**
** Function Name    : ComMExt_CAN_ReleaseCommunication
**
** Visibility       : Public
**
** Invocation       : Called from CanNmCtrl module
**
** Critical Section : None
**
** @param[in]         Channel - COM channel index
**
** @param[out]        None
**
** @return            RTE_E_OK - Success \n
**                    RTE_E_INVALID - Incorrect channel index
**
** @ingroup           ComMExt
**
*****************************************************************************************************************/
FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_ReleaseCommunication(UInt8 Channel)
{
    Std_ReturnType retval = RTE_E_INVALID;
    ComM_ModeType ComMode = COMM_NO_COMMUNICATION;
#if (COMMEXT_COM_IPDUGROUP_ACT_SUPPORT == STD_ON)    
    uint16 pdugroupid = 0U;
    ComMExt_IpduGroupIdConfigType const *IpduGroupIdConfigPtr;
#endif

    if(Channel >= COMMEXT_NUMBER_OF_COM_CHANNELS)
    {
        retval = RTE_E_INVALID;
    }
    else
    {
        (void)ComM_RequestComMode(Channel, COMM_NO_COMMUNICATION);
        (void)ComM_GetCurrentComMode(Channel, &ComMode);
#if (COMMEXT_IS_TRCV_SUPPORTED == STD_ON)
        if(COMM_NO_COMMUNICATION == ComMode)
        {
            Dio_WriteChannel(ComMExt_ChannelConfig[Channel].DioTrcvStbPinRef, ComMExt_ChannelConfig[Channel].TrcvStandbyStbVal);
            Dio_WriteChannel(ComMExt_ChannelConfig[Channel].DioTrcvEnPinRef, ComMExt_ChannelConfig[Channel].TrcvStandbyEnVal);
        }
#endif
#if (COMMEXT_COM_IPDUGROUP_ACT_SUPPORT == STD_ON)
        /* Tx group */
        for (pdugroupid = ComMExt_ChannelConfig[0].ComTxpduGroupStart;
            pdugroupid <= ComMExt_ChannelConfig[0].ComTxpduGroupEnd;
            pdugroupid++)
        {
            if (pdugroupid < COMMEXT_NUMBER_OF_TX_IPDU_GROUPS)
            {
                IpduGroupIdConfigPtr = &Com_TxIpduGroupIdConfig[pdugroupid];
                if (TRUE == IpduGroupIdConfigPtr->CtrlOnRequest)
                {
                    Com_SetIpduGroup(ComMExt_IpduGroupVector, IpduGroupIdConfigPtr->IpduGroupId, (boolean)FALSE);
                }
            }
        }
        /* Rx group */
        for (pdugroupid = ComMExt_ChannelConfig[0].ComRxpduGroupStart;
            pdugroupid <= ComMExt_ChannelConfig[0].ComRxpduGroupEnd;
            pdugroupid++)
        {
            if (pdugroupid < COMMEXT_NUMBER_OF_RX_IPDU_GROUPS)
            {
                IpduGroupIdConfigPtr = &Com_RxIpduGroupIdConfig[pdugroupid];
                if (TRUE == IpduGroupIdConfigPtr->CtrlOnRequest)
                {
                    Com_SetIpduGroup(ComMExt_IpduGroupVector, IpduGroupIdConfigPtr->IpduGroupId, (boolean)FALSE);
                }
            }
        }
        Com_IpduGroupControl(ComMExt_IpduGroupVector, (boolean)TRUE); /* other channel also reset to initial values */
#endif
        ComMExt_Wakeup_Interrupt_Enable(Channel);
        retval = RTE_E_OK;
    }
    return retval;
}

/*!***************************************************************************************************************
** @brief             Triggers wake up for given COM channel
**
** Function Name    : ComMExt_CAN_RequestCommunication
**
** Visibility       : Public
**
** Invocation       : Called from CanNmCtrl module
**
** Critical Section : None
**
** @param[in]         Channel - COM channel index
**
** @param[out]        None
**
** @return            RTE_E_OK - Success \n
**                    RTE_E_INVALID - Incorrect channel index
**
** @ingroup           ComMExt
**
*****************************************************************************************************************/
FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_RequestCommunication(UInt8 Channel)
{
    Std_ReturnType retval = RTE_E_INVALID;
#if (COMMEXT_COM_IPDUGROUP_ACT_SUPPORT == STD_ON)    
    uint16 pdugroupid = 0U;
    ComMExt_IpduGroupIdConfigType const *IpduGroupIdConfigPtr;
#endif

    if(Channel >= COMMEXT_NUMBER_OF_CAN_CHANNELS)
    {
        retval = RTE_E_INVALID;
    }
    else
    {
        ComMExt_Wakeup_Interrupt_Disable(Channel);
#if (COMMEXT_IS_TRCV_SUPPORTED == STD_ON)
        Dio_WriteChannel(ComMExt_ChannelConfig[Channel].DioTrcvStbPinRef, ComMExt_ChannelConfig[Channel].TrcvNormalStbVal);
        Dio_WriteChannel(ComMExt_ChannelConfig[Channel].DioTrcvEnPinRef, ComMExt_ChannelConfig[Channel].TrcvNormalEnVal);
#endif
        ComM_CommunicationAllowed(Channel, TRUE );
        (void)ComM_RequestComMode(Channel, COMM_FULL_COMMUNICATION);
#if (COMMEXT_COM_IPDUGROUP_ACT_SUPPORT == STD_ON)
        /* Tx group */
        for (pdugroupid = ComMExt_ChannelConfig[0].ComTxpduGroupStart;
            pdugroupid <= ComMExt_ChannelConfig[0].ComTxpduGroupEnd;
            pdugroupid++)
        {
            if (pdugroupid < COMMEXT_NUMBER_OF_TX_IPDU_GROUPS)
            {
                IpduGroupIdConfigPtr = &Com_TxIpduGroupIdConfig[pdugroupid];
                if (TRUE == IpduGroupIdConfigPtr->CtrlOnRequest)
                {
                    Com_SetIpduGroup(ComMExt_IpduGroupVector, IpduGroupIdConfigPtr->IpduGroupId, (boolean)TRUE);
                }
            }
        }
        /* Rx group */
        for (pdugroupid = ComMExt_ChannelConfig[0].ComRxpduGroupStart;
            pdugroupid <= ComMExt_ChannelConfig[0].ComRxpduGroupEnd;
            pdugroupid++)
        {
            if (pdugroupid < COMMEXT_NUMBER_OF_RX_IPDU_GROUPS)
            {
                IpduGroupIdConfigPtr = &Com_RxIpduGroupIdConfig[pdugroupid];
                if (TRUE == IpduGroupIdConfigPtr->CtrlOnRequest)
                {
                    Com_SetIpduGroup(ComMExt_IpduGroupVector, IpduGroupIdConfigPtr->IpduGroupId, (boolean)TRUE);
                }
            }
        }
        Com_IpduGroupControl(ComMExt_IpduGroupVector, (boolean)TRUE); /* other channel also reset to initial values */
#endif
        retval = RTE_E_OK;
    }
    return retval;
}

/*!***************************************************************************************************************
** @brief             This method is used to get the busoff status of the CAN channels.
**
** Function Name    : ComMExt_GetBusOffStatus
**
** Visibility       : Public
**
** Invocation       : From SWC
**
** Critical Section : None
**
** @param[in]         Channel - CAN channel index
**
** @param[out]        BusOffStatus ( True : Busoff Occured, False : Busoff not occurred)
**
** @return            E_OK : Requested channel ID is supported, E_NOT_OK : Requested channel ID is not supported
**
** @ingroup           ComMExt
**
*****************************************************************************************************************/
Std_ReturnType ComMExt_GetBusOffStatus(uint8 Channel, boolean* BusOffStatus)
{
    uint8 RetStatus = E_OK;

    RetStatus = ComMExtCfg_GetBusOffStatus(Channel,BusOffStatus);
    return RetStatus;
}

/*****************************************************************************************************************
*  PRIVATE FUNCTIONS DEFINITIONS
*****************************************************************************************************************/
/*!***************************************************************************************************************
** @brief             Disables interrupt for given COM channel
**
** Function Name    : ComMExt_Wakeup_Interrupt_Disable
**
** Visibility       : Private
**
** Invocation       : COM channel wake up trigger from ComMExt_CAN_RequestCommunication
**
** Critical Section : None
**
** @param[in]         Channel - COM channel index
**
** @param[out]        None
**
** @return            None
**
** @ingroup           ComMExt
**
*****************************************************************************************************************/
static void ComMExt_Wakeup_Interrupt_Disable(UInt8 Channel)
{
    if (Channel < COMMEXT_NUMBER_OF_CAN_CHANNELS) /* Coverity warning fix, Potential Array Indexed, CID 10750004*/
    {
        if(ComMExt_InterruptStatus[Channel] != COMMEXT_INTR_DISABLED)
        {
            #if (COMMEXT_EXT_INTR_SUPPORT == STD_ON)
            ComMExt_IcuChannelInterruptDisable(ComMExt_ChannelConfig[Channel].IcuChannelRef);
            #endif
            ComMExt_InterruptStatus[Channel] = COMMEXT_INTR_DISABLED;
        }
    }
}

/*!***************************************************************************************************************
** @brief             Enables interrupt for given COM channel
**
** Function Name    : ComMExt_Wakeup_Interrupt_Enable
**
** Visibility       : Private
**
** Invocation       : COM channel sleep trigger from ComMExt_CAN_ReleaseCommunication
**
** Critical Section : None
**
** @param[in]         Channel - COM channel index
**
** @param[out]        None
**
** @return            None
**
** @ingroup           ComMExt
**
*****************************************************************************************************************/
static void ComMExt_Wakeup_Interrupt_Enable(UInt8 Channel)
{
    #if (COMMEXT_EXT_INTR_SUPPORT == STD_ON)
    ComM_ModeType ComMode = COMM_NO_COMMUNICATION;
    Dio_LevelType TrcvRxPinStatus;
    #endif
    if (Channel < COMMEXT_NUMBER_OF_COM_CHANNELS) /* Coverity warning fix, Potential Array Indexed, CID 10749694*/
    {
        if(ComMExt_InterruptStatus[Channel] != COMMEXT_INTR_ENABLED)
        {
            ComMExt_InterruptStatus[Channel] = COMMEXT_INTR_ENABLED;
            #if (COMMEXT_EXT_INTR_SUPPORT == STD_ON)
            (void)ComM_GetCurrentComMode(Channel, &ComMode);
            if(COMM_NO_COMMUNICATION == ComMode)
            {
                TrcvRxPinStatus = Dio_ReadChannel(ComMExt_ChannelConfig[Channel].DioRxPinRef);
                if(TrcvRxPinStatus == (Dio_LevelType)STD_HIGH)
                {
                    ComMExt_SetPinToExtInterruptFctType SetExtIntrFct;
                    SetExtIntrFct = ComMExt_ChannelConfig[Channel].ExtIntrFuncRef;
                    //change CAN RX pin mode to dedicated EINT<X>
                    SetExtIntrFct();
                    ComMExt_IcuChannelInterruptEnable(ComMExt_ChannelConfig[Channel].IcuChannelRef);
                }
                else
                {
                    //Below invoke is Mandatory if OSEK NM from SIP used.
                    //Because while wake up at 1510ms guard interval, it will enable interrupt during communication.
                    ComMExt_SetIntrDetectedFctType SetIntrFct;
                    SetIntrFct = ComMExt_ChannelConfig[Channel].IntrDetectedFuncRef;
                    SetIntrFct();
                }
            }
            else
            {
                ComMExt_InterruptStatus[Channel] = COMMEXT_ENABLE_INTR_IN_TASK;
            }
            #endif
        }
    }
}
/*!***************************************************************************************************************
** @brief             Enable/Disable ipdus during Meet/Normal mode
**
** Function Name    : ComMExt_Ipducontrol_Handling
**
** Visibility       : Private
**
** Invocation       : ComMExt_Impl_MainFunction
**
** Critical Section : None
**
** @param[in]         None
**
** @param[out]        None
**
** @return            None
**
** @ingroup           ComMExt
**
*****************************************************************************************************************/

Std_ReturnType ComMExt_PduGroupActivationStatus(ComMExt_IpduGroupId GroupId, boolean* IPdu_GrpActiveStatus)
{
    Std_ReturnType ret = E_NOT_OK;

    if (IPdu_GrpActiveStatus != NULL_PTR)
    {
        *IPdu_GrpActiveStatus = FALSE;

        if (GroupId < COMMEXT_NUMBER_OF_IPDU_GROUPS)
        {
            const ComMExt_IpduGroupId byteIndex = GroupId >> 3U;
            const ComMExt_IpduGroupId bitPos    = GroupId & 0x07U;
            const uint32_t bitMask              = UINT32_C(1) << bitPos;
            const uint32_t vectorByte           = ComMExt_IpduGroupVector[byteIndex];

            if ((ComMExt_PduGrpTriggred == TRUE) && ((vectorByte & bitMask) != 0U))
            {
                *IPdu_GrpActiveStatus = TRUE;
            }

            ret = E_OK;
        }
    }

    return ret;
}
/*---------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 20/August/2018
By                : eashok
Traceability      : RTC #1179904
Change Description: Initial version.
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 03/March/2020
By                : pangraje
Traceability      : RTC #409772 and #389693
Change Description: Coverity and MISRA warning fixes
-----------------------------------------------------------------------------------------*/
