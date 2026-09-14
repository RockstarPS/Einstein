/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2019 by Visteon Corporation.       All rights reserved.                                             *
*                                                                                                                   *
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                  *
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States    *
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,            *
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its      *
* rights under all copyright laws to protect this work as a published work, when appropriate.                       *
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it  *
* without the written authorization of Visteon Corporation.                                                         *
********************************************************************************************************************/
/*!*****************************************************************************************************************
*    @file CanTrcv.c
*    @ingroup CanTrcv
*    @brief This file implements the AUTOSAR CanTrcv module.The CAN transceiver driver abstracts
*    the CAN transceiver hardware. It offers a hardware independent interface to the higher layers.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "CanTrcv.h"
#include "CanIf.h"
#include "CanIf_Cbk.h"
#if (CANTRCV_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
/********************************************************************************************************************
*  Version check                                                                                                    *
********************************************************************************************************************/
/* Software Version Check */
#if((CANTRCV_SW_MAJOR_VERSION != CANTRCV_CFG_SW_MAJOR_VERSION) || \
    (CANTRCV_SW_MINOR_VERSION != CANTRCV_CFG_SW_MINOR_VERSION) || \
    (CANTRCV_SW_PATCH_VERSION != CANTRCV_CFG_SW_PATCH_VERSION))
# error "Software version is inconsistent between source files and Configuration files!"
#endif
/* Autosar Version Check */
#if((CANTRCV_AR_RELEASE_MAJOR_VERSION != CANTRCV_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (CANTRCV_AR_RELEASE_MINOR_VERSION != CANTRCV_CFG_AR_RELEASE_MINOR_VERSION) || \
    (CANTRCV_AR_RELEASE_REVISION_VERSION != CANTRCV_CFG_AR_RELEASE_REVISION_VERSION))
# error "Autosar version is inconsistent between source files and Configuration files!"
#endif


#if (CANTRCV_DEV_ERROR_REPORT == STD_ON)
#define CanTrcv_DetReportError(ApiId,ErrorId) (void)Det_ReportError(CANTRCV_MODULE_ID,CANTRCV_MODULE_ID,ApiId,ErrorId)
#endif

/********************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/
/*! @brief Defines the Can Trcv Inactive state */
#define CANTRCV_INIT_STATUS_NOT_ACTIVE   0U
/*! @brief Defines the Can Trcv Active state */
#define CANTRCV_INIT_STATUS_ACTIVE       1U

/********************************************************************************************************************
*  PRIVATE TYPE DEFINITIONS                                                                                         *
********************************************************************************************************************/
/*! @brief Defines the type for Trcv Init state */
typedef uint8 CanTrcv_InitStatusType;

/********************************************************************************************************************
*  PRIVATE FUNCTION PROTOTYPES                                                                                      *
********************************************************************************************************************/
#if(CANTRCV_ECUM_WAKEUPSOURCE_SUPPORT == STD_ON)

/********************************************************************************************************************
*   @brief This method is used to notify the wakeup event to EcuM based on the wakeup sources
*   @param[in] Transceiver The transceiver for which wake up to be notified.
********************************************************************************************************************/
static void CanTrcv_ReportWakeup(uint8 Transceiver);
#endif
/********************************************************************************************************************
*  PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                        *
********************************************************************************************************************/
/*! @brief Defines the Init status of the Transceiver module */
static CanTrcv_InitStatusType       CanTrcv_InitStatus = CANTRCV_INIT_STATUS_NOT_ACTIVE;
#if (CANTRCV_GENERAL_WAKEUP_SUPPORT != CANTRCV_WAKEUP_NOT_SUPPORTED)
/*! @brief Defines the wakeup mode of the Transceivers */
static CanTrcv_TrcvWakeupModeType   CanTrcv_TrcvWakeupMode[CANTRCV_NUM_OF_TRCV_CHANNELS];
/*! @brief Defines the wakeup reason for the Transceivers */
static CanTrcv_TrcvWakeupReasonType CanTrcv_TrcvWakeupReason[CANTRCV_NUM_OF_TRCV_CHANNELS];
#endif

#if (CANTRCV_HW_PN_SUPPORT == STD_ON)
/*! @brief Defines the partial NW support enabled */
boolean CanTrcv_PnEnabled[CANTRCV_NUM_OF_TRCV_CHANNELS];
#endif
/********************************************************************************************************************
*   @brief      This method initializes the Can Transceiver internal variables to default values.
********************************************************************************************************************/
void CanTrcv_InitMemory(void)
{
    CanTrcv_InitStatus = CANTRCV_INIT_STATUS_NOT_ACTIVE;
}

/********************************************************************************************************************
*   @brief      This method initialize all the connected CAN transceivers based on their initialization sequences
*               and configuration
*   @param[in]  ConfigPtr  Pointer to the CanTrcv configuration data.
*   @ServiceID  0x00
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
void CanTrcv_Init(const CanTrcv_ConfigType* ConfigPtr)
{
    uint8 TrcvIndex=0U;
    CanTrcv_ChannelCfgType const * pCanTrcv_ChannelCfg;
    CanTrcv_HWFunctCfgType const * pCanTrcv_HWFunctCfg;
#if (CANTRCV_GENERAL_WAKEUP_SUPPORT != CANTRCV_WAKEUP_NOT_SUPPORTED)
    CanTrcv_TrcvWakeupReasonType WakeupReason;
#endif

    for (TrcvIndex = 0U; TrcvIndex < CANTRCV_NUM_OF_TRCV_CHANNELS ; TrcvIndex++)
    {
        pCanTrcv_ChannelCfg = &CanTrcv_ChannelCfg[TrcvIndex];
#if (CANTRCV_GENERAL_WAKEUP_SUPPORT != CANTRCV_WAKEUP_NOT_SUPPORTED)
        CanTrcv_TrcvWakeupMode[TrcvIndex] = CANTRCV_WUMODE_ENABLE;
        CanTrcv_TrcvWakeupReason[TrcvIndex] = CANTRCV_WU_ERROR;
#endif

        /*! Check if the transciever is supported */
        if ((FALSE != pCanTrcv_ChannelCfg->CanTrcv_IsChannelUsed) &&
            (CANTRCV_NUM_OF_HW_SUPPORTED > pCanTrcv_ChannelCfg->CanTrcv_HwFunctCfgId))
        {
            pCanTrcv_HWFunctCfg = &CanTrcv_HWFunctCfg[pCanTrcv_ChannelCfg->CanTrcv_HwFunctCfgId];
#if (CANTRCV_GENERAL_WAKEUP_SUPPORT != CANTRCV_WAKEUP_NOT_SUPPORTED)
            /* set the wakeup to reset */
            CanTrcv_TrcvWakeupReason[TrcvIndex] = CANTRCV_WU_RESET;
            if (NULL_PTR != pCanTrcv_HWFunctCfg->CanTrcv_GetBusWuReasonFn)
            {
                CanTrcv_EnterCriticalSection();
                if (FALSE != pCanTrcv_HWFunctCfg->CanTrcv_GetBusWuReasonFn(pCanTrcv_ChannelCfg->CanTrcv_TrcvChannelId,
                                                                                &WakeupReason))
                {
                    /* set the wakeup to wakeup by Bus */
                    CanTrcv_TrcvWakeupReason[TrcvIndex] = WakeupReason ;
                }
                CanTrcv_ExitCriticalSection();
            }
#if(CANTRCV_ECUM_WAKEUPSOURCE_SUPPORT == STD_ON)
            /* If report wakeup supported, report the wakeup source */
            CanTrcv_ReportWakeup(TrcvIndex);
#endif
#endif

            CanTrcv_EnterCriticalSection();
#if(CANTRCV_ICU_SUPPORT == STD_ON)
            /* If ICU supported , Disable the ICU */
            if (FALSE != pCanTrcv_ChannelCfg->CanTrcv_IsIcuSupportEnabled)
            {
                Icu_DisableNotification(pCanTrcv_ChannelCfg->CanTrcv_IcuchannelId);
            }
#endif
            /* Set the transceiver to Init mode from the config */
            if (NULL_PTR != pCanTrcv_HWFunctCfg->CanTrcv_SetOpModeFn)
            {
                (void)pCanTrcv_HWFunctCfg->CanTrcv_SetOpModeFn(pCanTrcv_ChannelCfg->CanTrcv_TrcvChannelId,
                                                                pCanTrcv_ChannelCfg->CanTrcv_InitMode);
            }
            CanTrcv_ExitCriticalSection();

        } /* Channel used check and HW function check */
    } /* init all channel loop */

    CanTrcv_InitStatus = CANTRCV_INIT_STATUS_ACTIVE;
    CANTRCV_IGNORE_UNUSED_PARAM(ConfigPtr);
}

/********************************************************************************************************************
*   @brief      This method sets the mode of the Transceiver to the value OpMode.
*   @param[in]  Transceiver  CAN transceiver to which API call has to be applied.
*   @param[in]  OpMode  This parameter contains the desired operating mode
*   @return     status of the request
*               - E_OK: will be returned if the request for transceiver mode change has been accepted.
*               - E_NOT_OK: will be returned if the request for transceiver mode change has not been accepted or any
*                 parameter is out of the allowed range.
*   @ServiceID  0x01
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant for different transceivers
********************************************************************************************************************/
Std_ReturnType CanTrcv_SetOpMode(uint8 Transceiver, CanTrcv_TrcvModeType OpMode)
{
    Std_ReturnType Status = E_NOT_OK;
    uint8 ErrorId = CANTRCV_E_NO_ERROR;
    /* Coverity Fix Story - 1674900 : CurrentOpMode is local variable and it always read through
    (void)pCanTrcv_HWFunctCfg->CanTrcv_GetOpModeFn(pCanTrcv_ChannelCfg->CanTrcv_TrcvChannelId,&CurrentOpMode) before usage */
    CanTrcv_TrcvModeType CurrentOpMode = CANTRCV_TRCVMODE_NORMAL;
    CanTrcv_ChannelCfgType const * pCanTrcv_ChannelCfg;
    CanTrcv_HWFunctCfgType const * pCanTrcv_HWFunctCfg;

    if(CANTRCV_INIT_STATUS_ACTIVE != CanTrcv_InitStatus)
    {
        ErrorId = CANTRCV_E_UNINIT;
    }
    else if (CANTRCV_NUM_OF_TRCV_CHANNELS <= Transceiver)
    {
        ErrorId = CANTRCV_E_INVALID_TRANSCEIVER;
    }
    else
    {
        /* Check if the channel is used */
        pCanTrcv_ChannelCfg = &CanTrcv_ChannelCfg[Transceiver];

        if ((FALSE != pCanTrcv_ChannelCfg->CanTrcv_IsChannelUsed) &&
            (CANTRCV_NUM_OF_HW_SUPPORTED > pCanTrcv_ChannelCfg->CanTrcv_HwFunctCfgId))
        {
            /* get current mode */
            pCanTrcv_HWFunctCfg = &CanTrcv_HWFunctCfg[pCanTrcv_ChannelCfg->CanTrcv_HwFunctCfgId];
            (void)pCanTrcv_HWFunctCfg->CanTrcv_GetOpModeFn(pCanTrcv_ChannelCfg->CanTrcv_TrcvChannelId,&CurrentOpMode);
            if(CurrentOpMode != OpMode)
            {
                switch(OpMode)
                {
                    case CANTRCV_TRCVMODE_NORMAL:
#if (CANTRCV_GENERAL_WAKEUP_SUPPORT != CANTRCV_WAKEUP_NOT_SUPPORTED)
                        /* Check for internal wakeup */
                        if ( CANTRCV_WU_ERROR == CanTrcv_TrcvWakeupReason[Transceiver])
                        {
                            CanTrcv_TrcvWakeupReason[Transceiver] = CANTRCV_WU_INTERNALLY ;
                        }
#endif
                        CanTrcv_EnterCriticalSection();
#if(CANTRCV_ICU_SUPPORT == STD_ON)
                        /* If ICU is configured, disable the ICU */
                        if (FALSE != pCanTrcv_ChannelCfg->CanTrcv_IsIcuSupportEnabled)
                        {
                            Icu_DisableNotification(pCanTrcv_ChannelCfg->CanTrcv_IcuchannelId);
                        }
#endif
                        if (NULL_PTR != pCanTrcv_HWFunctCfg->CanTrcv_SetOpModeFn)
                        {
                            Status = pCanTrcv_HWFunctCfg->CanTrcv_SetOpModeFn(pCanTrcv_ChannelCfg->CanTrcv_TrcvChannelId,
                                                                                                    CANTRCV_TRCVMODE_NORMAL);
                        }
                        CanTrcv_ExitCriticalSection();
                        break;

                    case CANTRCV_TRCVMODE_STANDBY:
                        CanTrcv_EnterCriticalSection();
#if(CANTRCV_ICU_SUPPORT == STD_ON)
                        /* If ICU is configured, disable the ICU */
                        if (FALSE != pCanTrcv_ChannelCfg->CanTrcv_IsIcuSupportEnabled)
                        {
                            Icu_EnableNotification(pCanTrcv_ChannelCfg->CanTrcv_IcuchannelId);
                        }
#endif
#if (CANTRCV_GENERAL_WAKEUP_SUPPORT != CANTRCV_WAKEUP_NOT_SUPPORTED)
                        CanTrcv_TrcvWakeupReason[Transceiver] = CANTRCV_WU_ERROR ;
#endif
                        if (NULL_PTR != pCanTrcv_HWFunctCfg->CanTrcv_SetOpModeFn)
                        {
                            Status = pCanTrcv_HWFunctCfg->CanTrcv_SetOpModeFn(pCanTrcv_ChannelCfg->CanTrcv_TrcvChannelId,
                                                                                                        CANTRCV_TRCVMODE_STANDBY);
                        }

                        CanTrcv_ExitCriticalSection();
                        break;

                    case CANTRCV_TRCVMODE_SLEEP:
                        if (NULL_PTR != pCanTrcv_HWFunctCfg->CanTrcv_SetOpModeFn)
                        {
                            Status = pCanTrcv_HWFunctCfg->CanTrcv_SetOpModeFn(pCanTrcv_ChannelCfg->CanTrcv_TrcvChannelId,CANTRCV_TRCVMODE_SLEEP);
                        }
                        break;
                    default:
                        ErrorId = CANTRCV_E_PARAM_TRCV_OPMODE;
                        break;
                }/* Switch - opmode */
            } /* CurrentOpMode != OpMode */
            else
            {
                Status = E_OK;
            }

            if (((uint8)E_OK) == Status)
            {
                /* check whether the mode is changed to the requested mode */
                if (NULL_PTR != pCanTrcv_HWFunctCfg->CanTrcv_SetOpModeFn)
                {
                    (void)pCanTrcv_HWFunctCfg->CanTrcv_GetOpModeFn(pCanTrcv_ChannelCfg->CanTrcv_TrcvChannelId,&CurrentOpMode);

                    if (CurrentOpMode == OpMode)
                    {
                        /* Notify upper layer */
                        CanIf_TrcvModeIndication(Transceiver,CurrentOpMode);
                    }
                    else
                    {
                        ErrorId = CANTRCV_E_NO_TRCV_CONTROL;
                        Status = E_NOT_OK;
                    }
                }
            }
        } /* Channel used check */
        else
        {
            ErrorId = CANTRCV_E_INVALID_TRANSCEIVER;
        }
    }
#if(CANTRCV_DEV_ERROR_REPORT == STD_ON)
    if (CANTRCV_E_NO_ERROR != ErrorId)
    {
        (void) CanTrcv_DetReportError(CANTRCV_SID_SETOPMODE,ErrorId);
    }
#else
    CANTRCV_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return Status;
}

/********************************************************************************************************************
*   @brief      This method gets the mode of the Transceiver and returns it in OpMode.
*   @param[in]  Transceiver  CAN transceiver to which API call has to be applied.
*   @param[out] OpMode  Pointer to operation mode of the bus the API is applied to.
*   @return     status of the request
*                   - E_OK: will be returned if the operation mode was detected.
*                   - E_NOT_OK: will be returned if the operation mode was not detected.
*   @ServiceID  0x02
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant for different transceivers
********************************************************************************************************************/
Std_ReturnType CanTrcv_GetOpMode(uint8 Transceiver, CanTrcv_TrcvModeType* OpMode)
{
    Std_ReturnType Status = E_NOT_OK;
    uint8 ErrorId = CANTRCV_E_NO_ERROR;
    CanTrcv_ChannelCfgType const * pCanTrcv_ChannelCfg;
    CanTrcv_HWFunctCfgType const * pCanTrcv_HWFunctCfg;

    if(CANTRCV_INIT_STATUS_ACTIVE != CanTrcv_InitStatus)
    {
        ErrorId = CANTRCV_E_UNINIT;
    }
    else if (CANTRCV_NUM_OF_TRCV_CHANNELS <= Transceiver)
    {
        ErrorId = CANTRCV_E_INVALID_TRANSCEIVER;
    }
    else if (NULL_PTR == OpMode)
    {
        ErrorId = CANTRCV_E_PARAM_POINTER;
    }
    else
    {
        /* Check if the channel is used */
        pCanTrcv_ChannelCfg = &CanTrcv_ChannelCfg[Transceiver];

        if ((FALSE != pCanTrcv_ChannelCfg->CanTrcv_IsChannelUsed) &&
            (CANTRCV_NUM_OF_HW_SUPPORTED > pCanTrcv_ChannelCfg->CanTrcv_HwFunctCfgId))
        {
            /* get current mode */
            pCanTrcv_HWFunctCfg = &CanTrcv_HWFunctCfg[pCanTrcv_ChannelCfg->CanTrcv_HwFunctCfgId];
            Status = pCanTrcv_HWFunctCfg->CanTrcv_GetOpModeFn(pCanTrcv_ChannelCfg->CanTrcv_TrcvChannelId,OpMode);
            if (((uint8)E_NOT_OK) == Status)
            {
                ErrorId = CANTRCV_E_NO_TRCV_CONTROL;
            }
        }
        else
        {
            ErrorId = CANTRCV_E_INVALID_TRANSCEIVER;
        }
    }

#if(CANTRCV_DEV_ERROR_REPORT == STD_ON)
    if (CANTRCV_E_NO_ERROR != ErrorId)
    {
        (void) CanTrcv_DetReportError(CANTRCV_SID_GETOPMODE,ErrorId);
    }
#else
    CANTRCV_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return Status;
}

/********************************************************************************************************************
*   @brief      This method gets the wakeup reason for the Transceiver and returns it in parameter Reason.
*   @param[in]  Transceiver  CAN transceiver to which API call has to be applied.
*   @param[out] Reason  Pointer to wake up reason of the bus the API is applied to.
*   @return     status of the request
*                   - E_OK: will be returned if the transceiver wakeup reason was provided.
*                   - E_NOT_OK: will be returned if no wake up reason is available or if the service request failed
*                     due to development errors.
*   @ServiceID  0x03
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
Std_ReturnType CanTrcv_GetBusWuReason(uint8 Transceiver, CanTrcv_TrcvWakeupReasonType* Reason)
{
    Std_ReturnType Status = E_NOT_OK;
    uint8 ErrorId = CANTRCV_E_NO_ERROR;
    CanTrcv_ChannelCfgType const * pCanTrcv_ChannelCfg;

    if(CANTRCV_INIT_STATUS_ACTIVE != CanTrcv_InitStatus)
    {
        ErrorId = CANTRCV_E_UNINIT;
    }
    else if (CANTRCV_NUM_OF_TRCV_CHANNELS <= Transceiver)
    {
        ErrorId = CANTRCV_E_INVALID_TRANSCEIVER;
    }
    else if (NULL_PTR == Reason)
    {
        ErrorId = CANTRCV_E_PARAM_POINTER;
    }
    else
    {
        pCanTrcv_ChannelCfg = &CanTrcv_ChannelCfg[Transceiver];
        /* Check channel usage */
        if (FALSE != pCanTrcv_ChannelCfg->CanTrcv_IsChannelUsed)
        {
#if(CANTRCV_GENERAL_WAKEUP_SUPPORT != CANTRCV_WAKEUP_NOT_SUPPORTED)
            *Reason = CanTrcv_TrcvWakeupReason[Transceiver];
#else
            *Reason = CANTRCV_WU_NOT_SUPPORTED; /* wakeup not supported */
#endif
            Status = E_OK;
        }
        else
        {
            ErrorId = CANTRCV_E_INVALID_TRANSCEIVER;
        }
    }

#if(CANTRCV_DEV_ERROR_REPORT == STD_ON)
    if (CANTRCV_E_NO_ERROR != ErrorId)
    {
        (void) CanTrcv_DetReportError(CANTRCV_SID_GETBUSWUREASON,ErrorId);
    }
#else
    CANTRCV_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return Status;
}

/********************************************************************************************************************
*   @brief      This method gets the version of the module and returns it in VersionInfo.
*   @param[out] VersionInfo  Pointer to version information of this module.
*   @ServiceID  0x04
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
void CanTrcv_GetVersionInfo(Std_VersionInfoType* VersionInfo)
{
    uint8 ErrorId = CANTRCV_E_NO_ERROR;

    if (NULL_PTR == VersionInfo )
    {
        ErrorId = CANTRCV_E_PARAM_POINTER;
    }
    else
    {
        /* update the version information */
        VersionInfo->vendorID         = CANTRCV_VENDOR_ID;
        VersionInfo->moduleID         = CANTRCV_MODULE_ID;
        VersionInfo->sw_major_version = CANTRCV_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = CANTRCV_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = CANTRCV_SW_PATCH_VERSION;
    }

#if(CANTRCV_DEV_ERROR_REPORT == STD_ON)
    if (CANTRCV_E_NO_ERROR != ErrorId)
    {
        (void) CanTrcv_DetReportError(CANTRCV_SID_GETVERSIONINFO,ErrorId);
    }
#else
    CANTRCV_IGNORE_UNUSED_PARAM(ErrorId);
#endif

}

/********************************************************************************************************************
*   @brief      This method Enables, disables or clears wake-up events of the Transceiver according to TrcvWakeupMode.
*   @param[in]  Transceiver  CAN transceiver to which API call has to be applied.
*   @param[in]  TrcvWakeupMode  Requested transceiver wakeup reason
*   @return     status of the request
*                   - E_OK: Will be returned, if the wakeup state has been changed to the requested mode.
*                   - E_NOT_OK: Will be returned, if the wakeup state change has failed or the parameter is out of
*                     the allowed range. The previ-ous state has not been changed.
*   @ServiceID  0x05
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different transceivers
********************************************************************************************************************/
Std_ReturnType CanTrcv_SetWakeupMode(uint8 Transceiver, CanTrcv_TrcvWakeupModeType TrcvWakeupMode)
{
    Std_ReturnType Status = E_NOT_OK;
    uint8 ErrorId = CANTRCV_E_NO_ERROR;

    CANTRCV_IGNORE_UNUSED_PARAM(TrcvWakeupMode);

#if (CANTRCV_GENERAL_WAKEUP_SUPPORT != CANTRCV_WAKEUP_NOT_SUPPORTED)
    CanTrcv_ChannelCfgType const * pCanTrcv_ChannelCfg;
#endif

    if(CANTRCV_INIT_STATUS_ACTIVE != CanTrcv_InitStatus)
    {
        ErrorId = CANTRCV_E_UNINIT;
    }
    else if (CANTRCV_NUM_OF_TRCV_CHANNELS <= Transceiver)
    {
        ErrorId = CANTRCV_E_INVALID_TRANSCEIVER;
    }
    else
    {
#if (CANTRCV_GENERAL_WAKEUP_SUPPORT != CANTRCV_WAKEUP_NOT_SUPPORTED)
        /* Check if the channel is used */
        pCanTrcv_ChannelCfg = &CanTrcv_ChannelCfg[Transceiver];

        if (FALSE != pCanTrcv_ChannelCfg->CanTrcv_IsChannelUsed)
        {
            switch (TrcvWakeupMode)
            {
                case CANTRCV_WUMODE_ENABLE:
                    CanTrcv_TrcvWakeupMode[Transceiver] = CANTRCV_WUMODE_ENABLE;
#if((CANTRCV_WAKEUP_BY_BUS_SUPPORT == STD_ON) && (CANTRCV_ECUM_WAKEUPSOURCE_SUPPORT == STD_ON))
                    CanTrcv_ReportWakeup(Transceiver);
#endif
                    Status = E_OK;
                    break;
                case CANTRCV_WUMODE_DISABLE:
                    CanTrcv_TrcvWakeupMode[Transceiver] = CANTRCV_WUMODE_DISABLE;
                    Status = E_OK;
                    break;
                case CANTRCV_WUMODE_CLEAR:
                    CanTrcv_TrcvWakeupReason[Transceiver] = CANTRCV_WU_ERROR;
                    Status = E_OK;
                    break;
                default:
                    ErrorId = CANTRCV_E_PARAM_TRCV_WAKEUP_MODE;
                    break;
            }
        }
        else
        {
            ErrorId = CANTRCV_E_INVALID_TRANSCEIVER;
        }
#endif
    }

#if(CANTRCV_DEV_ERROR_REPORT == STD_ON)
    if (CANTRCV_E_NO_ERROR != ErrorId)
    {
        (void) CanTrcv_DetReportError(CANTRCV_SID_SETWAKEUPMODE,ErrorId);
    }
#else
    CANTRCV_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return Status;
}

#if (CANTRCV_HW_PN_SUPPORT == STD_ON)
/********************************************************************************************************************
*   @brief      This method Reads the transceiver configuration/status data and returns it through parameter
*               TrcvSysData. This API shall exist only if CanTrcvHwPnSupport = TRUE.
*   @param[in]  Transceiver  CAN transceiver to which API call has to be applied.
*   @param[out] TrcvSysData  pointer to be updated with the Configuration/Status data of the transceiver
*   @return     status of the request
*                   - E_OK: will be returned if the transceiver status is successfully read.
*                   - E_NOT_OK: will be returned if the transceiver status data is not available or a development
*                     error occurs.
*   @ServiceID  0x09
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
Std_ReturnType CanTrcv_GetTrcvSystemData(uint8 Transceiver, const uint32* TrcvSysData)
{
    Std_ReturnType Status = E_NOT_OK;
    uint8 ErrorId = CANTRCV_E_NO_ERROR;
    CanTrcv_ChannelCfgType const * pCanTrcv_ChannelCfg;
    CanTrcv_HWFunctCfgType const * pCanTrcv_HWFunctCfg;

    if(CANTRCV_INIT_STATUS_ACTIVE != CanTrcv_InitStatus)
    {
        ErrorId = CANTRCV_E_UNINIT;
    }
    else if (CANTRCV_NUM_OF_TRCV_CHANNELS <= Transceiver)
    {
        ErrorId = CANTRCV_E_INVALID_TRANSCEIVER;
    }
    else if (NULL_PTR == TrcvSysData)
    {
        ErrorId = CANTRCV_E_PARAM_POINTER;
    }
    else
    {
         /* Check if the channel is used */
        pCanTrcv_ChannelCfg = &CanTrcv_ChannelCfg[Transceiver];

        if ((FALSE != pCanTrcv_ChannelCfg->CanTrcv_IsChannelUsed) &&
            (CANTRCV_NUM_OF_HW_SUPPORTED > pCanTrcv_ChannelCfg->CanTrcv_HwFunctCfgId))
        {
            pCanTrcv_HWFunctCfg = &CanTrcv_HWFunctCfg[pCanTrcv_ChannelCfg->CanTrcv_HwFunctCfgId];
            if (NULL_PTR != pCanTrcv_HWFunctCfg->CanTrcv_GetTrcvSystemDataFn)
            {
                Status = pCanTrcv_HWFunctCfg->CanTrcv_GetTrcvSystemDataFn(pCanTrcv_ChannelCfg->CanTrcv_TrcvChannelId,TrcvSysData);
            }
        }
    }

#if(CANTRCV_DEV_ERROR_REPORT == STD_ON)
    if (CANTRCV_E_NO_ERROR != ErrorId)
    {
        CanTrcv_DetReportError(CANTRCV_SID_GETTRCVSYSTEMDATA,ErrorId);
    }
#else
    CANTRCV_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return Status;
}

/********************************************************************************************************************
*   @brief      This method Clears the WUF flag in the transceiver hardware. This API shall exist only if
*               CanTrcvHwPnSupport = TRUE.
*               TrcvSysData. This API shall exist only if CanTrcvHwPnSupport = TRUE.
*   @param[in]  Transceiver  CAN transceiver to which API call has to be applied.
*   @return     status of the request
*                   - E_OK: will be returned if the WUF flag has been cleared.
*                   - E_NOT_OK: will be returned if the WUF flag has not been cleared or a development error occurs.
*   @ServiceID  0x0a
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different transceivers
********************************************************************************************************************/
Std_ReturnType CanTrcv_ClearTrcvWufFlag(uint8 Transceiver)
{
    Std_ReturnType Status = E_NOT_OK;
    uint8 ErrorId = CANTRCV_E_NO_ERROR;
    CanTrcv_ChannelCfgType const * pCanTrcv_ChannelCfg;
    CanTrcv_HWFunctCfgType const * pCanTrcv_HWFunctCfg;

    if(CANTRCV_INIT_STATUS_ACTIVE != CanTrcv_InitStatus)
    {
        ErrorId = CANTRCV_E_UNINIT;
    }
    else if (CANTRCV_NUM_OF_TRCV_CHANNELS <= Transceiver)
    {
        ErrorId = CANTRCV_E_INVALID_TRANSCEIVER;
    }
    else
    {
        /* Check if the channel is used */
        pCanTrcv_ChannelCfg = &CanTrcv_ChannelCfg[Transceiver];

        if ((FALSE != pCanTrcv_ChannelCfg->CanTrcv_IsChannelUsed) &&
            (CANTRCV_NUM_OF_HW_SUPPORTED > pCanTrcv_ChannelCfg->CanTrcv_HwFunctCfgId))
        {
            pCanTrcv_HWFunctCfg = &CanTrcv_HWFunctCfg[pCanTrcv_ChannelCfg->CanTrcv_HwFunctCfgId];
            if (NULL_PTR != pCanTrcv_HWFunctCfg->CanTrcv_ClearTrcvWufFlagFn)
            {
                Status = pCanTrcv_HWFunctCfg->CanTrcv_ClearTrcvWufFlagFn(pCanTrcv_ChannelCfg->CanTrcv_TrcvChannelId);
            }
        }
    }

#if(CANTRCV_DEV_ERROR_REPORT == STD_ON)
    if (CANTRCV_E_NO_ERROR != ErrorId)
    {
        CanTrcv_DetReportError(CANTRCV_SID_CLEARTRCVWUFFLAG,ErrorId);
    }
#else
    CANTRCV_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return Status;
}

/********************************************************************************************************************
*   @brief      This method Reads the status of the timeout flag from the transceiver hardware. This API shall exist
*               only if CanTrcvHwPnSupport = TRUE.
*               TrcvSysData. This API shall exist only if CanTrcvHwPnSupport = TRUE.
*   @param[in]  Transceiver  CAN transceiver to which API call has to be applied.
*   @param[out] FlagState  pointer to be udpated with State of the timeout flag
*   @return     status of the request
*                   - E_OK: Will be returned, if status of the timeout flag is success-fully read.
*                   - E_NOT_OK: Will be returned, if status of the timeout flag could not be read
*   @ServiceID  0x0b
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
Std_ReturnType CanTrcv_ReadTrcvTimeoutFlag(uint8 Transceiver, CanTrcv_TrcvFlagStateType* FlagState)
{
    Std_ReturnType Status = E_NOT_OK;
    uint8 ErrorId = CANTRCV_E_NO_ERROR;
    CanTrcv_ChannelCfgType const * pCanTrcv_ChannelCfg;
    CanTrcv_HWFunctCfgType const * pCanTrcv_HWFunctCfg;

    if(CANTRCV_INIT_STATUS_ACTIVE != CanTrcv_InitStatus)
    {
        ErrorId = CANTRCV_E_UNINIT;
    }
    else if (CANTRCV_NUM_OF_TRCV_CHANNELS <= Transceiver)
    {
        ErrorId = CANTRCV_E_INVALID_TRANSCEIVER;
    }
    else if (NULL_PTR == FlagState)
    {
        ErrorId = CANTRCV_E_PARAM_POINTER;
    }
    else
    {
        /* Check if the channel is used */
        pCanTrcv_ChannelCfg = &CanTrcv_ChannelCfg[Transceiver];

        if ((FALSE != pCanTrcv_ChannelCfg->CanTrcv_IsChannelUsed) &&
            (CANTRCV_NUM_OF_HW_SUPPORTED > pCanTrcv_ChannelCfg->CanTrcv_HwFunctCfgId))
        {
            pCanTrcv_HWFunctCfg = &CanTrcv_HWFunctCfg[pCanTrcv_ChannelCfg->CanTrcv_HwFunctCfgId];
            if (NULL_PTR != pCanTrcv_HWFunctCfg->CanTrcv_ReadTrcvTimeoutFlagFn)
            {
                Status = pCanTrcv_HWFunctCfg->CanTrcv_ReadTrcvTimeoutFlagFn(pCanTrcv_ChannelCfg->CanTrcv_TrcvChannelId,FlagState);
            }
        }
    }

#if(CANTRCV_DEV_ERROR_REPORT == STD_ON)
    if (CANTRCV_E_NO_ERROR != ErrorId)
    {
        CanTrcv_DetReportError(CANTRCV_SID_READTRCVTIMEOUTFLAG,ErrorId);
    }
#else
    CANTRCV_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return Status;
}

/********************************************************************************************************************
*   @brief      This method Clears the status of the timeout flag in the transceiver hardware. This API shall exist
*               only if CanTrcvHwPnSupport = TRUE
*               TrcvSysData. This API shall exist only if CanTrcvHwPnSupport = TRUE.
*   @param[in]  Transceiver  CAN transceiver to which API call has to be applied.
*   @return     status of the request
*                   - E_OK: Will be returned, if the timeout flag is successfully cleared.
*                   - E_NOT_OK: Will be returned, if the timeout flag could not be cleared.
*   @ServiceID  0x0c
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
Std_ReturnType CanTrcv_ClearTrcvTimeoutFlag(uint8 Transceiver)
{
    Std_ReturnType Status = E_NOT_OK;
    uint8 ErrorId = CANTRCV_E_NO_ERROR;
    CanTrcv_ChannelCfgType const * pCanTrcv_ChannelCfg;
    CanTrcv_HWFunctCfgType const * pCanTrcv_HWFunctCfg;

    if(CANTRCV_INIT_STATUS_ACTIVE != CanTrcv_InitStatus)
    {
        ErrorId = CANTRCV_E_UNINIT;
    }
    else if (CANTRCV_NUM_OF_TRCV_CHANNELS <= Transceiver)
    {
        ErrorId = CANTRCV_E_INVALID_TRANSCEIVER;
    }
    else
    {
        /* Check if the channel is used */
        pCanTrcv_ChannelCfg = &CanTrcv_ChannelCfg[Transceiver];

        if ((FALSE != pCanTrcv_ChannelCfg->CanTrcv_IsChannelUsed) &&
            (CANTRCV_NUM_OF_HW_SUPPORTED > pCanTrcv_ChannelCfg->CanTrcv_HwFunctCfgId))
        {
            pCanTrcv_HWFunctCfg = &CanTrcv_HWFunctCfg[pCanTrcv_ChannelCfg->CanTrcv_HwFunctCfgId];
            if (NULL_PTR != pCanTrcv_HWFunctCfg->CanTrcv_ClearTrcvTimeoutFlagFn)
            {
                Status = pCanTrcv_HWFunctCfg->CanTrcv_ClearTrcvTimeoutFlagFn(pCanTrcv_ChannelCfg->CanTrcv_TrcvChannelId);
            }
        }
    }


#if(CANTRCV_DEV_ERROR_REPORT == STD_ON)
    if (CANTRCV_E_NO_ERROR != ErrorId)
    {
        CanTrcv_DetReportError(CANTRCV_SID_CLEARTRCVTIMEOUTFLAG,ErrorId);
    }
#else
    CANTRCV_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return Status;
}

/********************************************************************************************************************
*   @brief      This method Reads the status of the silence flag from the transceiver hardware. This API shall
*               exist only if CanTrcvHwPnSupport = TRUE.
*   @param[in]  Transceiver  CAN transceiver to which API call has to be applied.
*   @param[out] FlagState  pointer to be updated with State of the silence flag.
*   @return     status of the request
*                   - E_OK: Will be returned, if status of the silence flag is success-fully read.
*                   - E_NOT_OK: Will be returned, if status of the silence flag could not be read.
*   @ServiceID  0x0d
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
Std_ReturnType CanTrcv_ReadTrcvSilenceFlag(uint8 Transceiver, CanTrcv_TrcvFlagStateType* FlagState)
{
    Std_ReturnType Status = E_NOT_OK;
    uint8 ErrorId = CANTRCV_E_NO_ERROR;
    CanTrcv_ChannelCfgType const * pCanTrcv_ChannelCfg;
    CanTrcv_HWFunctCfgType const * pCanTrcv_HWFunctCfg;

    if(CANTRCV_INIT_STATUS_ACTIVE != CanTrcv_InitStatus)
    {
        ErrorId = CANTRCV_E_UNINIT;
    }
    else if (CANTRCV_NUM_OF_TRCV_CHANNELS <= Transceiver)
    {
        ErrorId = CANTRCV_E_INVALID_TRANSCEIVER;
    }
    else if (NULL_PTR == FlagState)
    {
        ErrorId = CANTRCV_E_PARAM_POINTER;
    }
    else
    {
        /* Check if the channel is used */
        pCanTrcv_ChannelCfg = &CanTrcv_ChannelCfg[Transceiver];

        if ((FALSE != pCanTrcv_ChannelCfg->CanTrcv_IsChannelUsed) &&
            (CANTRCV_NUM_OF_HW_SUPPORTED > pCanTrcv_ChannelCfg->CanTrcv_HwFunctCfgId))
        {
            pCanTrcv_HWFunctCfg = &CanTrcv_HWFunctCfg[pCanTrcv_ChannelCfg->CanTrcv_HwFunctCfgId];
            if (NULL_PTR != pCanTrcv_HWFunctCfg->CanTrcv_ReadTrcvSilenceFlagFn)
            {
                Status = pCanTrcv_HWFunctCfg->CanTrcv_ReadTrcvSilenceFlagFn(pCanTrcv_ChannelCfg->CanTrcv_TrcvChannelId,FlagState);
            }
        }
    }


#if(CANTRCV_DEV_ERROR_REPORT == STD_ON)
    if (CANTRCV_E_NO_ERROR != ErrorId)
    {
        CanTrcv_DetReportError(CANTRCV_SID_READTRCVSILENCEFLAG,ErrorId);
    }
#else
    CANTRCV_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return Status;
}
#endif

/********************************************************************************************************************
*   @brief      This method Service is called by underlying CANIF in case a wake up interrupt is detected.
*   @param[in]  Transceiver  CAN transceiver to which API call has to be applied.
*   @return     status of the request
*                   - E_OK: API call has been accepted
*                   - E_NOT_OK: API call has not been accepted
*   @ServiceID  0x07
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
Std_ReturnType CanTrcv_CheckWakeup(uint8 Transceiver)
{
    Std_ReturnType Status = E_NOT_OK;
    uint8 ErrorId = CANTRCV_E_NO_ERROR;
#if (CANTRCV_GENERAL_WAKEUP_SUPPORT != CANTRCV_WAKEUP_NOT_SUPPORTED)
    CanTrcv_TrcvModeType CurrentOpMode;
    CanTrcv_TrcvWakeupReasonType WakeupReason;
    CanTrcv_ChannelCfgType const * pCanTrcv_ChannelCfg;
    CanTrcv_HWFunctCfgType const * pCanTrcv_HWFunctCfg;
#endif
    if(CANTRCV_INIT_STATUS_ACTIVE != CanTrcv_InitStatus)
    {
        ErrorId = CANTRCV_E_UNINIT;
    }
    else if (CANTRCV_NUM_OF_TRCV_CHANNELS <= Transceiver)
    {
        ErrorId = CANTRCV_E_INVALID_TRANSCEIVER;
    }
    else
    {
#if (CANTRCV_GENERAL_WAKEUP_SUPPORT != CANTRCV_WAKEUP_NOT_SUPPORTED)
        /* Check if the channel is used */
        pCanTrcv_ChannelCfg = &CanTrcv_ChannelCfg[Transceiver];

        if ((FALSE != pCanTrcv_ChannelCfg->CanTrcv_IsChannelUsed) &&
            (CANTRCV_NUM_OF_HW_SUPPORTED > pCanTrcv_ChannelCfg->CanTrcv_HwFunctCfgId) &&
            (FALSE != pCanTrcv_ChannelCfg->CanTrcv_WakeupByBusUsed) &&
            (CANTRCV_WUMODE_ENABLE == CanTrcv_TrcvWakeupMode[Transceiver]))
        {
            pCanTrcv_HWFunctCfg = &CanTrcv_HWFunctCfg[pCanTrcv_ChannelCfg->CanTrcv_HwFunctCfgId];
            CanTrcv_EnterCriticalSection();
            (void)pCanTrcv_HWFunctCfg->CanTrcv_GetOpModeFn(pCanTrcv_ChannelCfg->CanTrcv_TrcvChannelId,&CurrentOpMode);
            if( CANTRCV_TRCVMODE_NORMAL == CurrentOpMode)
            {
                Status = E_NOT_OK;
            }
            /* Check if external wakeup is pending */
            else if ((CANTRCV_WU_BY_BUS == CanTrcv_TrcvWakeupReason[Transceiver])
#if (CANTRCV_HW_PN_SUPPORT == STD_ON)
                    ||(CANTRCV_WU_BY_PIN == CanTrcv_TrcvWakeupReason[Transceiver]) ||
                     (CANTRCV_WU_BY_SYSERR == CanTrcv_TrcvWakeupReason[Transceiver])
#endif
                    )
            {
#if(CANTRCV_ECUM_WAKEUPSOURCE_SUPPORT == STD_ON)
                CanTrcv_ReportWakeup(Transceiver);
#endif
                Status = E_OK;
            }
            else
            {
                /* Get wakeup from the transceiver driver */
                if (NULL_PTR != pCanTrcv_HWFunctCfg->CanTrcv_GetBusWuReasonFn)
                {
                    if (FALSE != pCanTrcv_HWFunctCfg->CanTrcv_GetBusWuReasonFn(pCanTrcv_ChannelCfg->CanTrcv_TrcvChannelId,&WakeupReason))
                    {
                        CanTrcv_TrcvWakeupReason[Transceiver] = WakeupReason;
#if(CANTRCV_ECUM_WAKEUPSOURCE_SUPPORT == STD_ON)
                        CanTrcv_ReportWakeup(Transceiver);
#endif
                        Status = E_OK;
                    }
                }
            }
            CanTrcv_ExitCriticalSection();
        }
#endif
    }

#if(CANTRCV_DEV_ERROR_REPORT == STD_ON)
    if (CANTRCV_E_NO_ERROR != ErrorId)
    {
        (void) CanTrcv_DetReportError(CANTRCV_SID_CHECKWAKEFLAG,ErrorId);
    }
#else
    CANTRCV_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return Status;
}

#if (CANTRCV_HW_PN_SUPPORT == STD_ON)
/********************************************************************************************************************
*   @brief      This method configures the wake-up of the transceiver for Standby and Sleep Mode: Either the CAN
*               transceiver is woken up by a remote wake-up pattern (standard CAN wake-up) or by the configured
*               remote wake-up frame.
*   @param[in]  ActivationState PN_ENABLED: PN wakeup functionality in CanTrcv shall be enabled.
*               PN_DIABLED: PN wakeup functionality in CanTrcv shall be disabled.
*   @return     status of the request
*                   - E_OK: Will be returned, if the PN has been changed to the requested configuration.
*                   - E_NOT_OK: Will be returned, if the PN configuration change has failed. The previous
*                     configuration has not been changed.
*   @ServiceID  0x0f
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
Std_ReturnType CanTrcv_SetPNActivationState(CanTrcv_PNActivationType ActivationState)
{
    Std_ReturnType Status = E_NOT_OK;
    uint8 ErrorId = CANTRCV_E_NO_ERROR;
    uint8 TrcvIndex = 0U;
    CanTrcv_ChannelCfgType const * pCanTrcv_ChannelCfg;

    if(CANTRCV_INIT_STATUS_ACTIVE != CanTrcv_InitStatus)
    {
        ErrorId = CANTRCV_E_UNINIT;
    }
    else
    {
        for(TrcvIndex=0U; TrcvIndex < CANTRCV_NUM_OF_TRCV_CHANNELS; TrcvIndex++)
        {
            pCanTrcv_ChannelCfg = &CanTrcv_ChannelCfg[TrcvIndex];

            if ((FALSE != pCanTrcv_ChannelCfg->CanTrcv_IsChannelUsed) &&
                (CANTRCV_NUM_OF_PN_CFG_ID > pCanTrcv_ChannelCfg->CanTrcv_PnCfgId))
            {
                if (CANTRCV_PN_ENABLED == ActivationState)
                {
                    CanTrcv_PnEnabled[TrcvIndex] = TRUE;
                }
                else
                {
                    CanTrcv_PnEnabled[TrcvIndex] = FALSE;
                }
                Status = E_OK;
            }
        }
    }

#if(CANTRCV_DEV_ERROR_REPORT == STD_ON)
    if (CANTRCV_E_NO_ERROR != ErrorId)
    {
        CanTrcv_DetReportError(CANTRCV_SID_SETPNACTIVATIONSTATE,ErrorId);
    }
#else
    CANTRCV_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return Status;
}


/********************************************************************************************************************
*   @brief      This method Requests to check the status of the wakeup flag from the transceiver hardware.
*   @param[in]  Transceiver CAN transceiver to which API call has to be applied.
*   @return     status of the request
*                   - E_OK: Will be returned, if the request for checking the wakeup flag has been accepted.
*                   - E_NOT_OK: Will be returned, if the request for checking the wakeup flag has not been accepted.
*   @ServiceID  0x0e
*   @Sync/Async Asynchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
Std_ReturnType CanTrcv_CheckWakeFlag(uint8 Transceiver)
{
    Std_ReturnType Status = E_NOT_OK;
    uint8 ErrorId = CANTRCV_E_NO_ERROR;
    CanTrcv_ChannelCfgType const * pCanTrcv_ChannelCfg;
    CanTrcv_HWFunctCfgType const * pCanTrcv_HWFunctCfg;

    if(CANTRCV_INIT_STATUS_ACTIVE != CanTrcv_InitStatus)
    {
        ErrorId = CANTRCV_E_UNINIT;
    }
    else if (CANTRCV_NUM_OF_TRCV_CHANNELS <= Transceiver)
    {
        ErrorId = CANTRCV_E_INVALID_TRANSCEIVER;
    }
    else
    {
        /* Check if the channel is used */
        pCanTrcv_ChannelCfg = &CanTrcv_ChannelCfg[Transceiver];

        if ((FALSE != pCanTrcv_ChannelCfg->CanTrcv_IsChannelUsed) &&
            (CANTRCV_NUM_OF_HW_SUPPORTED > pCanTrcv_ChannelCfg->CanTrcv_HwFunctCfgId))
        {
            pCanTrcv_HWFunctCfg = &CanTrcv_HWFunctCfg[pCanTrcv_ChannelCfg->CanTrcv_HwFunctCfgId];
            if (NULL_PTR != pCanTrcv_HWFunctCfg->CanTrcv_CheckWakeFlagFn)
            {
                Status = pCanTrcv_HWFunctCfg->CanTrcv_CheckWakeFlagFn(pCanTrcv_ChannelCfg->CanTrcv_TrcvChannelId);
            }
        }
    }


#if(CANTRCV_DEV_ERROR_REPORT == STD_ON)
    if (CANTRCV_E_NO_ERROR != ErrorId)
    {
        CanTrcv_DetReportError(CANTRCV_SID_GETOPMODE,ErrorId);
    }
#else
    CANTRCV_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return Status;
}
#endif

/*******************************************************************************************************************
*   @brief      This method Service to scan all busses for wake up events and perform these event.
*   @ServiceID  0x06
********************************************************************************************************************/
void CanTrcv_MainFunction(void)
{
#if (CANTRCV_GENERAL_WAKEUP_SUPPORT != CANTRCV_WAKEUP_NOT_SUPPORTED)
    uint8 TrcvIndex = 0U;
    CanTrcv_ChannelCfgType const *pCanTrcv_ChannelCfg;
    CanTrcv_HWFunctCfgType const *pCanTrcv_HWFunctCfg;
    CanTrcv_TrcvModeType CurrentOpMode;
    CanTrcv_TrcvWakeupReasonType WakeupReason;

    for (TrcvIndex = 0U; TrcvIndex < CANTRCV_NUM_OF_TRCV_CHANNELS;TrcvIndex++)
    {
        pCanTrcv_ChannelCfg = &CanTrcv_ChannelCfg[TrcvIndex];
        /*! Check if the transciever is supported */
        if ((FALSE != pCanTrcv_ChannelCfg->CanTrcv_IsChannelUsed) &&
            (CANTRCV_NUM_OF_HW_SUPPORTED > pCanTrcv_ChannelCfg->CanTrcv_HwFunctCfgId))
        {
            pCanTrcv_HWFunctCfg = &CanTrcv_HWFunctCfg[pCanTrcv_ChannelCfg->CanTrcv_HwFunctCfgId];
            (void)pCanTrcv_HWFunctCfg->CanTrcv_GetOpModeFn(pCanTrcv_ChannelCfg->CanTrcv_TrcvChannelId,&CurrentOpMode);
            if (CANTRCV_TRCVMODE_NORMAL != CurrentOpMode)
            {
                if (FALSE != pCanTrcv_ChannelCfg->CanTrcv_WakeupByBusUsed)
                {
                    CanTrcv_EnterCriticalSection();
                    pCanTrcv_HWFunctCfg->CanTrcv_GetBusWuReasonFn(pCanTrcv_ChannelCfg->CanTrcv_TrcvChannelId,&WakeupReason);
                    if (CANTRCV_WU_ERROR != WakeupReason)
                    {
                        CanTrcv_TrcvWakeupReason[TrcvIndex] = WakeupReason;
                        if ((CANTRCV_WUMODE_ENABLE == CanTrcv_TrcvWakeupMode[TrcvIndex]) &&
                                (pCanTrcv_ChannelCfg->CanTrcv_IsWakeupSourceSupported))
                        {
#if(CANTRCV_ECUM_WAKEUPSOURCE_SUPPORT == STD_ON)
                            EcuM_CheckWakeup(pCanTrcv_ChannelCfg->CanTrcv_WakeupSource);
#endif
                        }
                    }
                    CanTrcv_ExitCriticalSection();
                }
            }
        }
    }
#endif
}

/*******************************************************************************************************************
*   @brief      This method Reads the transceiver diagnostic status periodically and sets product/development
*               accordingly.
*   @ServiceID  0x08
********************************************************************************************************************/
void CanTrcv_MainFunctionDiagnostics(void)
{

}

#if(CANTRCV_ECUM_WAKEUPSOURCE_SUPPORT == STD_ON)
/********************************************************************************************************************
*   @brief This method is used to notify the wakeup event to EcuM based on the wakeup sources
*   @param[in] Transceiver The transceiver for which wake up to be notified.
********************************************************************************************************************/
static void CanTrcv_ReportWakeup(uint8 Transceiver)
{
    CanTrcv_ChannelCfgType const *pCanTrcv_ChannelCfg;
#if(CANTRCV_HW_PN_SUPPORT == STD_ON)
    CanTrcv_PartialNetworkCfgType const * pCanTrcv_PartialNetworkCfg;
#endif
    if (CANTRCV_NUM_OF_TRCV_CHANNELS > Transceiver)
    {
        pCanTrcv_ChannelCfg = &CanTrcv_ChannelCfg[Transceiver];
        switch(CanTrcv_TrcvWakeupReason[Transceiver])
        {
            case CANTRCV_WU_BY_BUS:
                if ((FALSE != pCanTrcv_ChannelCfg->CanTrcv_WakeupByBusUsed) &&
                    (pCanTrcv_ChannelCfg->CanTrcv_IsWakeupSourceSupported))
                {
                    EcuM_SetWakeupEvent(pCanTrcv_ChannelCfg->CanTrcv_WakeupSource);
                }
                break;
#if(CANTRCV_HW_PN_SUPPORT == STD_ON)
            case CANTRCV_WU_BY_SYSERR:
            case CANTRCV_WU_BY_PIN:
                if (CANTRCV_NUM_OF_PN_CFG_ID > pCanTrcv_ChannelCfg->CanTrcv_PnCfgId)
                {
                    pCanTrcv_PartialNetworkCfg = &CanTrcv_ChannelCfg[pCanTrcv_ChannelCfg->CanTrcv_PnCfgId];
                    if((FALSE != pCanTrcv_PartialNetworkCfg->CanTrcv_BusErrFlagSupport) ||
                        (pCanTrcv_PartialNetworkCfg->CanTrcv_IsSysErrOrPorSupported))
                    {
                        EcuM_SetWakeupEvent(pCanTrcv_PartialNetworkCfg->CanTrcv_SyserrWakeupSource);
                    }
                }
                break;
#endif
            default:
            /*CanTrcv*/
                break;
        }
    }

}
#endif
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
/*******************************************************************************************************************
*   For each change to this file, be sure to record:                                                               *
*      1.  who made the change and when the change was made                                                        *
*      2.  why the change was made and the intended result                                                         *
*   Following block needs to be repeated for each change                                                           *
*******************************************************************************************************************/
/*!*****************************************************************************************************************
*  @date    14-Apr-2021
*  @version 0.0.1
*  @author  pchinnat
*  @brief   Initial version implementation RTC#
*******************************************************************************************************************/
