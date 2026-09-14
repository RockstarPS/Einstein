/*---------------------------------------------------------------------------------------------------------------------  
 
  VISTEON CORPORATION CONFIDENTIAL 
 ________________________________ 
 [2020] Visteon Corporation 
 All Rights Reserved. 
  NOTICE: This is an unpublished work of authorship, which contains trade secrets. 
 Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve 
 its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States 
 or those of any other country that may have jurisdiction, to protect this work as an unpublished work, 
 in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights 
 under all copyright laws to protect this work as a published work, when appropriate.
 Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it 
 without the written authorization of Visteon Corporation. 
 AUTO-GENERATED CODE FROM TOOL VER1.0  
-------------------------------DO NOT HAND MODIFY --------------------------------------------------  */ 
#ifndef COMABSCTRL_CFG_H 
#define COMABSCTRL_CFG_H 
#include "Std_Types.h"
#include "Rte_Type.h"

/*------------------------------Reception arrays start ------------------------*/
#define COMABS_CTRL_RX_INIT1_ARRAY
#define MAX_ELEMENTS_IN_RX_INIT1 15
#define COMABS_CTRL_RX_INIT2_ARRAY
#define MAX_ELEMENTS_IN_RX_INIT2 0
#define COMABS_CTRL_RX_INIT3_ARRAY \
    eDayNightModeIn, \
    eIllumination_levelIn, \
    eAmbient_Light_levelIn, \
    ePowerModeIn, \
    eTransportModeIn, \
    eGearModeIn, \
    eGearRecommendationIn, \
    eGearIn, \
    eWarningIn, \
    eGearStatusIn, \
    eEngineSpeedIn, \
    eVehicleSpeedABSIn, \
    eAirbagIn, \
    eAlive_101In, \
    eCRC_101In
    boolean ComAbsCtrl_NWSleep_Wakeup_Determination(boolean ComAbsCtrl_IgnStatus, boolean ICAN_NwAwake_Status);

    #ifndef ePwrMode_Off 
	#define ePwrMode_Off  (0U)
	#endif 
    #ifndef ePwrMode_Run 
	#define ePwrMode_Run  (1U)
	#endif 
#define MAX_ELEMENTS_IN_RX_INIT3 0
#define COMABS_CTRL_RX_INIT4_ARRAY
#define MAX_ELEMENTS_IN_RX_INIT4 0
#define COMABS_CTRL_RX_INIT_VALUE_ARRAY \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0
#define MAX_ELEMENTS_IN_RX_INIT_VALUE_ARRAY 15
#define COMABS_CTRL_RX_INVALID_PWR_MODE_RUN_ARRAY
#define MAX_ELEMENTS_IN_RX_INVALID_PWR_MODE_RUN_ARRAY 0
#define COMABS_CTRL_RX_INVALID_PWR_MODE_RUN_OR_START_ARRAY
#define MAX_ELEMENTS_IN_RX_INVALID_PWR_MODE_RUN_OR_START 0

#define COMABS_CTRL_RX_MISSING_RUN_DIAG_MODE_YES_ARRAY
#define MAX_ELEMENTS_IN_MISSING_RUN_DIAG_MODE_YES_ARRAY 0
#define COMABS_CTRL_RX_MISSING_RUN_DIAG_MODE_NO_ARRAY
#define MAX_ELEMENTS_IN_MISSING_RUN_DIAG_MODE_NO_ARRAY 0
#define COMABS_CTRL_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_YES_ARRAY
#define MAX_ELEMENTS_IN_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_YES_ARRAY 0
#define COMABS_CTRL_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_NO_ARRAY
#define MAX_ELEMENTS_IN_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_NO_ARRAY 0
#define COMABS_CTRL_NEVER_RECEIVED_RESET_INIT1_ARRAY
#define MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT1_ARRAY 0
#define COMABS_CTRL_NEVER_RECEIVED_RESET_INIT2_ARRAY
#define MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT2_ARRAY 0
#define COMABS_CTRL_NEVER_RECEIVED_RESET_INIT3_ARRAY
#define MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT3_ARRAY 0
#define COMABS_CTRL_NEVER_RECEIVED_RESET_INIT4_ARRAY
#define MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT4_ARRAY 0

#  ifndef eReleaseCom
#   define eReleaseCom (0U)
#  endif
#ifndef tNetworkComMode
typedef uint8 tNetworkComMode;
#endif
typedef boolean tPwrModeState;
# define Rte_TypeDef_tInhibitLocalSleep
typedef uint8 tInhibitLocalSleep;
// # define Rte_TypeDef_tResetReason
// typedef uint8 tResetReason;
// VAR(tResetReason, RTE_VAR_INIT) Rte_ModeMgr_ppSRModeResetReason_ResetReason = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

/*-------------------------------------Reception arrays End ---------------------*/
/*------------------------------Transmission arrays start ------------------------*/
#define COMABS_CTRL_TX_INIT1_ARRAY
#define MAX_ELEMENTS_IN_TX_INIT1_ARRAY 52
#define COMABS_CTRL_TX_INIT2_ARRAY
#define MAX_ELEMENTS_IN_TX_INIT2_ARRAY 0
#define COMABS_CTRL_TX_INIT3_ARRAY \
    eSecureTxByte0Out, \
    eSecureTxByte1Out, \
    eSecureTxByte2Out, \
    eSecureTxByte3Out, \
    eMAC_TxOut, \
    eFV_TxOut, \
    eBattery_VoltageOut, \
    eOdometerOut, \
    eVehicleSpeedICOut, \
    eIllumination_PWMOut, \
    eDebug1_Byte0Out, \
    eDebug1_Byte1Out, \
    eDebug1_Byte2Out, \
    eDebug1_Byte3Out, \
    eDebug1_Byte4Out, \
    eDebug1_Byte5Out, \
    eDebug1_Byte6Out, \
    eDebug1_Byte7Out, \
    eDebug2_Byte0Out, \
    eDebug2_Byte1Out, \
    eDebug2_Byte2Out, \
    eDebug2_Byte3Out, \
    eDebug2_Byte4Out, \
    eDebug2_Byte5Out, \
    eDebug2_Byte6Out, \
    eDebug2_Byte7Out, \
    eDebug3_Byte0Out, \
    eDebug3_Byte1Out, \
    eDebug3_Byte2Out, \
    eDebug3_Byte3Out, \
    eDebug3_Byte4Out, \
    eDebug3_Byte5Out, \
    eDebug3_Byte6Out, \
    eDebug3_Byte7Out, \
    eDebug4_Byte0Out, \
    eDebug4_Byte1Out, \
    eDebug4_Byte2Out, \
    eDebug4_Byte3Out, \
    eDebug4_Byte4Out, \
    eDebug4_Byte5Out, \
    eDebug4_Byte6Out, \
    eDebug4_Byte7Out, \
    eDebug5_Byte0Out, \
    eDebug5_Byte1Out, \
    eDebug5_Byte2Out, \
    eDebug5_Byte3Out, \
    eDebug5_Byte4Out, \
    eDebug5_Byte5Out, \
    eDebug5_Byte6Out, \
    eDebug5_Byte7Out
#define MAX_ELEMENTS_IN_TX_INIT3_ARRAY 52
#define COMABS_CTRL_TX_INIT4_ARRAY
#define MAX_ELEMENTS_IN_TX_INIT4_ARRAY 0
#define COMABS_CTRL_TX_INIT_VALUE_ARRAY \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0, \
    (uint32)0,
    
#define MAX_ELEMENTS_IN_TX_INIT_VALUE_ARRAY 52
/*------------------------------Transmission arrays End ------------------------*/
/*------------------------------Reception array for testing  ------------------------*/
#define COMABS_CTRL_RX_TEST_ARRAY \
    eDayNightModeIn, \
    eIllumination_levelIn, \
    eAmbient_Light_levelIn, \
    ePowerModeIn, \
    eTransportModeIn, \
    eGearModeIn, \
    eGearRecommendationIn, \
    eGearIn, \
    eWarningIn, \
    eGearStatusIn, \
    eEngineSpeedIn, \
    eVehicleSpeedABSIn, \
    eAirbagIn, \
    eAlive_101In, \
    eCRC_101In
#define MAX_ELEMENTS_IN_RX_TEST_ARRAY 15
/*------------------------------Transmission array for testing  ------------------------*/
#define COMABS_CTRL_TX_TEST_ARRAY \
    eSecureTxByte0Out, \
    eSecureTxByte1Out, \
    eSecureTxByte2Out, \
    eSecureTxByte3Out, \
    eMAC_TxOut, \
    eFV_TxOut, \
    eBattery_VoltageOut, \
    eOdometerOut, \
    eVehicleSpeedICOut, \
    eIllumination_PWMOut, \
    eDebug1_Byte0Out, \
    eDebug1_Byte1Out, \
    eDebug1_Byte2Out, \
    eDebug1_Byte3Out, \
    eDebug1_Byte4Out, \
    eDebug1_Byte5Out, \
    eDebug1_Byte6Out, \
    eDebug1_Byte7Out, \
    eDebug2_Byte0Out, \
    eDebug2_Byte1Out, \
    eDebug2_Byte2Out, \
    eDebug2_Byte3Out, \
    eDebug2_Byte4Out, \
    eDebug2_Byte5Out, \
    eDebug2_Byte6Out, \
    eDebug2_Byte7Out, \
    eDebug3_Byte0Out, \
    eDebug3_Byte1Out, \
    eDebug3_Byte2Out, \
    eDebug3_Byte3Out, \
    eDebug3_Byte4Out, \
    eDebug3_Byte5Out, \
    eDebug3_Byte6Out, \
    eDebug3_Byte7Out, \
    eDebug4_Byte0Out, \
    eDebug4_Byte1Out, \
    eDebug4_Byte2Out, \
    eDebug4_Byte3Out, \
    eDebug4_Byte4Out, \
    eDebug4_Byte5Out, \
    eDebug4_Byte6Out, \
    eDebug4_Byte7Out, \
    eDebug5_Byte0Out, \
    eDebug5_Byte1Out, \
    eDebug5_Byte2Out, \
    eDebug5_Byte3Out, \
    eDebug5_Byte4Out, \
    eDebug5_Byte5Out, \
    eDebug5_Byte6Out, \
    eDebug5_Byte7Out, \
    eAlive_200Out, \
    eCRC_200Out
#define MAX_ELEMENTS_IN_TX_TEST_ARRAY 52

#  ifndef eReleaseCom
#   define eReleaseCom (0U)
#  endif
#  ifndef eRequestCom
#   define eRequestCom (1U)
#  endif
#  ifndef eLIMITED
#   define eLIMITED (4U)
#  endif
#  ifndef eNwMode_Sleep
#   define eNwMode_Sleep (0U)
#  endif
#  ifndef eNmMode_ReadyToSleep
#   define eNmMode_ReadyToSleep (1U)
#  endif
#  ifndef eNmMode_Normal
#   define eNmMode_Normal (2U)
#  endif
#ifndef COMM_NO_COMMUNICATION  
/*! @brief ComM state machine is in "No Communication" mode. Configured channel shall have no transmission or reception 
    capability.*/
#define COMM_NO_COMMUNICATION           0U 
#endif 
#ifndef COMM_SILENT_COMMUNICATION 
/*! @brief ComM state machine is in "Silent Communication" mode. Configured channel shall have only reception 
    capability, no transmission capability. */
#define COMM_SILENT_COMMUNICATION       1U 
#endif 
#ifndef COMM_FULL_COMMUNICATION 
/*! @brief ComM state machine is in "Full Communication" mode. Configured channel shall have both transmission and 
    reception capability. */
#define COMM_FULL_COMMUNICATION         2U 
#endif 

#define COMABSCTRL_GET_CURRENT_CONTEXT  
/*End of File*/ 
/*****************************************************************************
*  for each change to this file, be sure to record:                         *
*     1.  who made the change and when the change was made                  *
*     2.  why the change was made and the intended result                   *
*  Following block needs to be repeated for each change
******************************************************************************
*  Note: In the trace-ability column we need to trace back to the Design Doc.*
*  For the initial version it is traced to the Design Document section.     *
*  For further changes it shall trace to the source of the change which may *
*  be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  *
*  other reason                                                            *
******************************************************************************/
/*****************************************************************************
Date              :13/Aug/2020
By                :bjayara2
Traceability      : 1006237: Comabs - ComAbsCtrl Automation -
                   Python scripts for collecting all elements -Init1, Init2,
                    Init3, Init4,
                    pwr modes,init values for Tx and Rx signals
Change Description:Ford Bx755 Initial version
******************************************************************************/
#endif /* COMABSCTRL_CFG_H */
