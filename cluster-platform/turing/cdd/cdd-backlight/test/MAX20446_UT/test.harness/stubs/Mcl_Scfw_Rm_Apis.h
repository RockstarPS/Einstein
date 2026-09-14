/**
*   @file    Mcl_Scfw_Rm_Apis.h
*   @version 4.0.0
*
*   @brief   AUTOSAR Mcl . Module for the Resource Management (RM) service.
*   @details Header file containing the public API for the System Controller (SC)
*   Resource Management (RM) function. This includes functions for
*   partitioning Resources, Pads, and memory regions.
*
*   @addtogroup MCL_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : eDMA
*   Dependencies         : none
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 4.0.0
*   Build Version        : IMX8_MCAL_4_0_0_RTM_ASR_REL_4_2_REV_0002_20210812
*
*   Copyright 2006-2016 Freescale Semiconductor, Inc. 
*   Copyright 2017 - 2021 NXP
*   NXP Confidential. This software is owned or controlled by NXP and may only be 
*   used strictly in accordance with the applicable license terms.  By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms.  If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef MCL_SCFW_RM_API_H
#define MCL_SCFW_RM_API_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcl_Scfw_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SCFW_RM_API_VENDOR_ID_H                    43
#define SCFW_RM_API_AR_RELEASE_MAJOR_VERSION_H     4
#define SCFW_RM_API_AR_RELEASE_MINOR_VERSION_H     2
#define SCFW_RM_API_AR_RELEASE_REVISION_VERSION_H  2
#define SCFW_RM_API_SW_MAJOR_VERSION_H             4
#define SCFW_RM_API_SW_MINOR_VERSION_H             0
#define SCFW_RM_API_SW_PATCH_VERSION_H             0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcl_Scfw_Types.h header file are of the same vendor */
#if (SCFW_RM_API_VENDOR_ID_H != SCFW_TYPES_VENDOR_ID_H)
    #error "Mcl_Scfw_Rm_Apis.h and Mcl_Scfw_Types.h have different vendor id"
#endif
/* Check if current file and Mcl_Scfw_Types.h header file are of the same Software version */
#if ((SCFW_RM_API_SW_MAJOR_VERSION_H != SCFW_TYPES_SW_MAJOR_VERSION_H ) || \
     (SCFW_RM_API_SW_MINOR_VERSION_H != SCFW_TYPES_SW_MINOR_VERSION_H) || \
     (SCFW_RM_API_SW_PATCH_VERSION_H != SCFW_TYPES_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Mcl_Scfw_Rm_Apis.h and Mcl_Scfw_Types.h are different"
#endif
/* Check if current file and Dem header file are of the same Autosar version */
#if ((SCFW_RM_API_AR_RELEASE_MAJOR_VERSION_H != SCFW_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (SCFW_RM_API_AR_RELEASE_MINOR_VERSION_H != SCFW_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (SCFW_RM_API_AR_RELEASE_REVISION_VERSION_H != SCFW_TYPES_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Mcl_Scfw_Rm_Apis.h and Mcl_Scfw_Types.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/*!
 * @name Defines for Mcl_Scfw_RmPermType
 */
/*@{*/
#define SCFW_RM_PERM_NONE         0U   /*!< No access */
#define SCFW_RM_PERM_SEC_R        1U   /*!< Secure RO */
#define SCFW_RM_PERM_SECPRIV_RW   2U   /*!< Secure privilege R/W */
#define SCFW_RM_PERM_SEC_RW       3U   /*!< Secure R/W */
#define SCFW_RM_PERM_NSPRIV_R     4U   /*!< Secure R/W, non-Secure privilege RO */
#define SCFW_RM_PERM_NS_R         5U   /*!< Secure R/W, non-Secure RO */
#define SCFW_RM_PERM_NSPRIV_RW    6U   /*!< Secure R/W, non-Secure privilege R/W */
#define SCFW_RM_PERM_FULL         7U   /*!< Full access */
/*@}*/
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/*!
 * This Type is used to declare a Resource partition.
 */
typedef uint8 Mcl_Scfw_RmPtType;

/*!
 * This Type is used to declare a memory region.
 */
typedef uint8 Mcl_Scfw_RmMrType;

/*!
 * This Type is used to declare a Resource/memory region access Permission.
 * Refer to the XRDC2 BLock Guide for more information.
 */
typedef uint8 Mcl_Scfw_RmPermType;

/*!
 * This Type is used to declare a Resource domain ID used by the
 * Isolation HW.
 */
typedef uint8 Mcl_Scfw_RmDidType;
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
/*!
 * @name Partition Functions
 * @{
 */

/*!
 * This function requests that the SC create a new Resource partition.
 *
 * @param[in]     Ipc          IPC handle
 * @param[out]    Pt           return handle for partition;
                               used for subsequent function
 *                             calls associated with this partition
 * @param[in]     Secure       boolean indicating if this partition should be Secure;
                               only Valid if caller is Secure
 * @param[in]     Isolated     boolean indicating if this partition should be HW Isolated
 *                             via XRDC; set SCFW_TRUE if new DID is desired
 * @param[in]     Restricted   boolean indicating if this partition should be Restricted;
 *                             set SCFW_TRUE if masters in this partition cannot create new partitions
 * @param[in]     Grant        boolean indicating if this partition should always Grant
 *                             access and control to the parent
 * @param[in]     Coherent     boolean indicating if this partition is coherent;
 *                             set SCFW_TRUE if only this partition will contain both AP clusters
 *                             and they will be coherent via the CCI
 *
 * @return Returns an error code (SCFW_ERR_NONE = success).
 *
 * Return errors:
 * - SCFW_ERR_NOACCESS if caller's partition is Restricted,
 * - SCFW_ERR_PARM if caller's partition is not Secure but a new Secure partition is requested,
 * - SCFW_ERR_LOCKED if caller's partition is Locked,
 * - SCFW_ERR_UNAVAILABLE if partition table is full (no more allocation space)
 *
 * Marking as non-Secure prevents subsequent functions from Configuring masters in this
 * partition to assert the Secure signal. Basically, if TrustZone SW is used, the Cortex-A
 * cores and peripherals the TZ SW will use should be in a Secure partition. Almost all
 * other partitions (for a non-Secure OS or MCU cores) should be in non-Secure partitions.
 *
 * Isolated should be true for almost all partitions. The excePtion is the non-Secure
 * partition for a Cortex-A core used to run a non-Secure OS. This isn't Isolated by
 * domain but is instead Isolated by the TZ security hardware.
 *
 * If Restricted then the new partition is limited in what functions it can call,
 * especially those associated with managing partitions.
 *
 * The Grant option is usually used to Isolate a bus master's traffic to specific
 * memory without Isolating the peripheral interface of the master or the API
 * controls of that master. This is only used when creating a sub-partition with
 * no CPU. It's useful to sepaRate out a master and the memory it uses.
 */
FUNC(Mcl_Scfw_ErrType, MCL_CODE) Mcl_Scfw_RmPartitionAlloc(Mcl_Scfw_IpcType Ipc, Mcl_Scfw_RmPtType *Pt, Mcl_Scfw_BoolType Secure,
    Mcl_Scfw_BoolType Isolated, Mcl_Scfw_BoolType Restricted, Mcl_Scfw_BoolType Grant,
    Mcl_Scfw_BoolType Coherent);
/*!
 * This function gets the partition handle of the caller.
 *
 * @param[in]     Ipc         IPC handle
 * @param[out]    Pt          return handle for caller's partition
 *
 * @return Returns an error code (SCFW_ERR_NONE = success).
 */
FUNC(Mcl_Scfw_ErrType, MCL_CODE) Mcl_Scfw_RmGetPartition(Mcl_Scfw_IpcType Ipc, Mcl_Scfw_RmPtType *Pt);
/*!
 * This function returns the DID of a partition.
 *
 * @param[in]     Ipc         IPC handle
 *
 * @return Returns the domain ID (DID) of the caller's partition.
 *
 * The DID is a SoC-specific internal ID used by the HW Resource
 * protection mechanism. It is only required by clients when using the
 * SEMA42 module as the DID is sometimes connected to the master ID.
 */
FUNC(Mcl_Scfw_RmDidType, MCL_CODE) Mcl_Scfw_RmGetDid(Mcl_Scfw_IpcType Ipc);

/*!
 * This function is used to get the owner of a Resource.
 *
 * @param[in]     Ipc         IPC handle
 * @param[in]     Resource    Resource to check
 * @param[out]    Pt          pointer to return owning partition
 *
 * @return Returns a boolean (SCFW_TRUE if the Resource is a bus master).
 *
 */
FUNC(Mcl_Scfw_ErrType, MCL_CODE) Mcl_Scfw_RmGetResourceOwner(Mcl_Scfw_IpcType Ipc, Mcl_Scfw_RsrcType Resource, Mcl_Scfw_RmPtType *Pt);

/*!
 * This function sets access Permissions for a memory region.
 *
 * @param[in]     Ipc         IPC handle
 * @param[in]     Mr          handle of memory region
                              for which Permissions should apply
 * @param[in]     Pt          handle of partition \a Perm should by
 *                            applied for
 * @param[in]     Perm        Permissions to apply to \a Mr for \a Pt
 *
 * This opeRates on the memory region specified. If SC_RM_PT_ALL is specified
 * then it opeRates on all the regions owned by the caller that exist at the
 * time of the call.
 *
 * @return Returns an error code (SCFW_ERR_NONE = success).
 *
 */
FUNC(Mcl_Scfw_ErrType, MCL_CODE) Mcl_Scfw_RmSetMemregPermissions(Mcl_Scfw_IpcType Ipc, Mcl_Scfw_RmMrType Mr, Mcl_Scfw_RmPtType Pt, Mcl_Scfw_RmPermType Perm);

/*!
 * This function is used to obtain info about a memory region.
 *
 * @param[in]     Ipc         IPC handle
 * @param[in]     Mr          handle of memory region to inquire about
 * @param[out]    AddrStart  pointer to return start address
 * @param[out]    AddrEnd    pointer to return end address
 *
 * @return Returns an error code (SCFW_ERR_NONE = success).
 *
 */
FUNC(Mcl_Scfw_ErrType, MCL_CODE) Mcl_Scfw_RmGetMemregInfo(Mcl_Scfw_IpcType Ipc, Mcl_Scfw_RmMrType Mr, Mcl_Scfw_FaddrType *AddrStart, Mcl_Scfw_FaddrType *AddrEnd);

/*!
 * This function requests that the SC create a new memory region.
 *
 * @param[in]     Ipc         IPC handle
 * @param[out]    Mr          return handle for region;
                              used for subsequent function calls
 *                            associated with this region
 * @param[in]     AddrStart  start address of region (physical)
 * @param[in]     AddrEnd    end address of region (physical)
 *
 * @return Returns an error code (SCFW_ERR_NONE = success).
 *
 */
FUNC(Mcl_Scfw_ErrType, MCL_CODE) Mcl_Scfw_RmMemregAlloc(Mcl_Scfw_IpcType Ipc, Mcl_Scfw_RmMrType *Mr, Mcl_Scfw_FaddrType AddrStart, Mcl_Scfw_FaddrType AddrEnd);
/** @} */

#ifdef __cplusplus
}
#endif
#endif /* SC_RM_API_H */
/** @} */
