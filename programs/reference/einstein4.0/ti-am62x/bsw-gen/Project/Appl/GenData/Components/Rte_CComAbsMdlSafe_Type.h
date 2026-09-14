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
 *          File:  Rte_CComAbsMdlSafe_Type.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application types header file for SW-C <CComAbsMdlSafe>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CCOMABSMDLSAFE_TYPE_H
# define _RTE_CCOMABSMDLSAFE_TYPE_H

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

#  ifndef eVehicleSpeedABSIn
#   define eVehicleSpeedABSIn (0U)
#  endif

#  ifndef eAirbagIn
#   define eAirbagIn (1U)
#  endif

#  ifndef eAlive_101In
#   define eAlive_101In (2U)
#  endif

#  ifndef eCRC_101In
#   define eCRC_101In (3U)
#  endif

#  ifndef eEndOfSafeRxSignal
#   define eEndOfSafeRxSignal (4U)
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
#   define eSIGNAL_INVALID (3U)
#  endif

#  ifndef eSIGNAL_INVALID_CRC
#   define eSIGNAL_INVALID_CRC (4U)
#  endif

#  ifndef eSIGNAL_INVALID_ALIVE_COUNTER
#   define eSIGNAL_INVALID_ALIVE_COUNTER (5U)
#  endif

#  ifndef eSIGNAL_REPEATED
#   define eSIGNAL_REPEATED (6U)
#  endif

#  ifndef eBattery_VoltageOut
#   define eBattery_VoltageOut (0U)
#  endif

#  ifndef eAlive_200Out
#   define eAlive_200Out (1U)
#  endif

#  ifndef eCRC_200Out
#   define eCRC_200Out (2U)
#  endif

#  ifndef eEndofSafeTxSignals
#   define eEndofSafeTxSignals (3U)
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

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CCOMABSMDLSAFE_TYPE_H */
