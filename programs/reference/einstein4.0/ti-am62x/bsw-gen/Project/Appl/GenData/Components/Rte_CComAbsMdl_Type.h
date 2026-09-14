/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_CComAbsMdl_Type.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application types header file for SW-C <CComAbsMdl>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CCOMABSMDL_TYPE_H
# define _RTE_CCOMABSMDL_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef eCmpCmd_Init
#   define eCmpCmd_Init (0U)
#  endif

#  ifndef eCmpCmd_DeInit
#   define eCmpCmd_DeInit (1U)
#  endif

#  ifndef eCmpCmd_Activate
#   define eCmpCmd_Activate (2U)
#  endif

#  ifndef eCmpCmd_DeActivate
#   define eCmpCmd_DeActivate (3U)
#  endif

#  ifndef eDayNightModeIn
#   define eDayNightModeIn (0U)
#  endif

#  ifndef eIllumination_levelIn
#   define eIllumination_levelIn (1U)
#  endif

#  ifndef eAmbient_Light_levelIn
#   define eAmbient_Light_levelIn (2U)
#  endif

#  ifndef ePowerModeIn
#   define ePowerModeIn (3U)
#  endif

#  ifndef eTransportModeIn
#   define eTransportModeIn (4U)
#  endif

#  ifndef eGearModeIn
#   define eGearModeIn (5U)
#  endif

#  ifndef eGearRecommendationIn
#   define eGearRecommendationIn (6U)
#  endif

#  ifndef eGearIn
#   define eGearIn (7U)
#  endif

#  ifndef eWarningIn
#   define eWarningIn (8U)
#  endif

#  ifndef eGearStatusIn
#   define eGearStatusIn (9U)
#  endif

#  ifndef eEngineSpeedIn
#   define eEngineSpeedIn (10U)
#  endif

#  ifndef eTurn_Indicator_ControlIn
#   define eTurn_Indicator_ControlIn (11U)
#  endif

#  ifndef eEndOfRxSignal
#   define eEndOfRxSignal (12U)
#  endif

#  ifndef eJust_Received
#   define eJust_Received (0U)
#  endif

#  ifndef eNot_Just_Received
#   define eNot_Just_Received (1U)
#  endif

#  ifndef eSIGNAL_OK
#   define eSIGNAL_OK (0U)
#  endif

#  ifndef eSIGNAL_MISSING
#   define eSIGNAL_MISSING (1U)
#  endif

#  ifndef eSIGNAL_NEVER_RECEIVED
#   define eSIGNAL_NEVER_RECEIVED (2U)
#  endif

#  ifndef eSIGNAL_INVALID
#   define eSIGNAL_INVALID (4U)
#  endif

#  ifndef eTxSigConfirmStatus_Cleared
#   define eTxSigConfirmStatus_Cleared (0U)
#  endif

#  ifndef eTxSigConfirmStatus_Set
#   define eTxSigConfirmStatus_Set (1U)
#  endif

#  ifndef eTxSigConfirmStatus_NotSupported
#   define eTxSigConfirmStatus_NotSupported (2U)
#  endif

#  ifndef eSecureTxByte0Out
#   define eSecureTxByte0Out (0U)
#  endif

#  ifndef eSecureTxByte1Out
#   define eSecureTxByte1Out (1U)
#  endif

#  ifndef eSecureTxByte2Out
#   define eSecureTxByte2Out (2U)
#  endif

#  ifndef eSecureTxByte3Out
#   define eSecureTxByte3Out (3U)
#  endif

#  ifndef eMAC_TxOut
#   define eMAC_TxOut (4U)
#  endif

#  ifndef eFV_TxOut
#   define eFV_TxOut (5U)
#  endif

#  ifndef eOdometerOut
#   define eOdometerOut (6U)
#  endif

#  ifndef eVehicleSpeedICOut
#   define eVehicleSpeedICOut (7U)
#  endif

#  ifndef eIllumination_PWMOut
#   define eIllumination_PWMOut (8U)
#  endif

#  ifndef eDebug1_Byte0Out
#   define eDebug1_Byte0Out (9U)
#  endif

#  ifndef eDebug1_Byte1Out
#   define eDebug1_Byte1Out (10U)
#  endif

#  ifndef eDebug1_Byte2Out
#   define eDebug1_Byte2Out (11U)
#  endif

#  ifndef eDebug1_Byte3Out
#   define eDebug1_Byte3Out (12U)
#  endif

#  ifndef eDebug1_Byte4Out
#   define eDebug1_Byte4Out (13U)
#  endif

#  ifndef eDebug1_Byte5Out
#   define eDebug1_Byte5Out (14U)
#  endif

#  ifndef eDebug1_Byte6Out
#   define eDebug1_Byte6Out (15U)
#  endif

#  ifndef eDebug1_Byte7Out
#   define eDebug1_Byte7Out (16U)
#  endif

#  ifndef eDebug2_Byte0Out
#   define eDebug2_Byte0Out (17U)
#  endif

#  ifndef eDebug2_Byte1Out
#   define eDebug2_Byte1Out (18U)
#  endif

#  ifndef eDebug2_Byte2Out
#   define eDebug2_Byte2Out (19U)
#  endif

#  ifndef eDebug2_Byte3Out
#   define eDebug2_Byte3Out (20U)
#  endif

#  ifndef eDebug2_Byte4Out
#   define eDebug2_Byte4Out (21U)
#  endif

#  ifndef eDebug2_Byte5Out
#   define eDebug2_Byte5Out (22U)
#  endif

#  ifndef eDebug2_Byte6Out
#   define eDebug2_Byte6Out (23U)
#  endif

#  ifndef eDebug2_Byte7Out
#   define eDebug2_Byte7Out (24U)
#  endif

#  ifndef eDebug3_Byte0Out
#   define eDebug3_Byte0Out (25U)
#  endif

#  ifndef eDebug3_Byte1Out
#   define eDebug3_Byte1Out (26U)
#  endif

#  ifndef eDebug3_Byte2Out
#   define eDebug3_Byte2Out (27U)
#  endif

#  ifndef eDebug3_Byte3Out
#   define eDebug3_Byte3Out (28U)
#  endif

#  ifndef eDebug3_Byte4Out
#   define eDebug3_Byte4Out (29U)
#  endif

#  ifndef eDebug3_Byte5Out
#   define eDebug3_Byte5Out (30U)
#  endif

#  ifndef eDebug3_Byte6Out
#   define eDebug3_Byte6Out (31U)
#  endif

#  ifndef eDebug3_Byte7Out
#   define eDebug3_Byte7Out (32U)
#  endif

#  ifndef eDebug4_Byte0Out
#   define eDebug4_Byte0Out (33U)
#  endif

#  ifndef eDebug4_Byte1Out
#   define eDebug4_Byte1Out (34U)
#  endif

#  ifndef eDebug4_Byte2Out
#   define eDebug4_Byte2Out (35U)
#  endif

#  ifndef eDebug4_Byte3Out
#   define eDebug4_Byte3Out (36U)
#  endif

#  ifndef eDebug4_Byte4Out
#   define eDebug4_Byte4Out (37U)
#  endif

#  ifndef eDebug4_Byte5Out
#   define eDebug4_Byte5Out (38U)
#  endif

#  ifndef eDebug4_Byte6Out
#   define eDebug4_Byte6Out (39U)
#  endif

#  ifndef eDebug4_Byte7Out
#   define eDebug4_Byte7Out (40U)
#  endif

#  ifndef eDebug5_Byte0Out
#   define eDebug5_Byte0Out (41U)
#  endif

#  ifndef eDebug5_Byte1Out
#   define eDebug5_Byte1Out (42U)
#  endif

#  ifndef eDebug5_Byte2Out
#   define eDebug5_Byte2Out (43U)
#  endif

#  ifndef eDebug5_Byte3Out
#   define eDebug5_Byte3Out (44U)
#  endif

#  ifndef eDebug5_Byte4Out
#   define eDebug5_Byte4Out (45U)
#  endif

#  ifndef eDebug5_Byte5Out
#   define eDebug5_Byte5Out (46U)
#  endif

#  ifndef eDebug5_Byte6Out
#   define eDebug5_Byte6Out (47U)
#  endif

#  ifndef eDebug5_Byte7Out
#   define eDebug5_Byte7Out (48U)
#  endif

#  ifndef eEndOfTxSignal
#   define eEndOfTxSignal (49U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CCOMABSMDL_TYPE_H */
