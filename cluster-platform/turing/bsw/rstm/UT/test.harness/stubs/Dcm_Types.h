/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2016. Visteon Corporation owns all rights to           *
 * this work and intends to maintain it in confidence to preserve             *
 * its trade secret status. Visteon Corporation reserves the right,           *
 * under the copyright laws of the United States or those of any              *
 * other country that may have jurisdiction, to protect this work             *
 * as an unpublished work, in the event of an inadvertent or                  *
 * deliberate unauthorized publication. Visteon Corporation also              *
 * reserves its rights under all copyright laws to protect this               *
 * work as a published work, when appropriate. Those having access            *
 * to this work may not copy it, use it, modify it or disclose the            *
 * information contained in it without the written authorization              *
 * of Visteon Corporation.                                                    *
 *                                                                            *
 ******************************************************************************/
#ifndef DCM_TYPES_H
#define DCM_TYPES_H
/*****************************************************************************
 *  File Name         :  Dcm_Types.h                                          *
 *  Module Short Name :  DiagMgr                                              *
 *  VOBName           :                                                       *
 *  Author            : msavariy                                              *
 *  Description       :  This file contains declations of the Autosar ECU     *
 *                       State Manager types and macros                       *
 *                                                                            *                                                                           *
 * Organization     :  Driver Information Software Section,                   *
 *                     Visteon Software Operation                             *
 *                     Visteon Corporation                                    *
 *                                                                            *
 * ---------------------------------------------------------------------------*
 * Compiler Name    :  GHS                                                    *
 * Target Hardware  :                                                         *
 *                                                                            *
 ******************************************************************************/
/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/
#include "Std_Types.h"
#include "ComStack_Types.h"
#include "Rte_Dcm_Type.h"

/*****************************************************************************
 *                                 Macro Definitions                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 ******************************************************************************/

/*Version Info*/
#define DCM_VENDOR_ID                    0x33U
#define DCM_MODULE_ID                    0x35U
#define DCM_SW_MAJOR_VERSION             0U
#define DCM_SW_MINOR_VERSION             1U
#define DCM_SW_PATCH_VERSION             23U

/*
 * Dcm_StatusType
 */

#ifndef DCM_E_OK
#define DCM_E_OK                           ((Std_ReturnType)E_OK)
#endif
#ifndef DCM_E_NOT_OK
#define DCM_E_NOT_OK                       ((Std_ReturnType)E_NOT_OK)
#endif
#ifndef DCM_E_ROE_NOT_ACCEPTED
#define DCM_E_ROE_NOT_ACCEPTED             ((Std_ReturnType)6)
#endif
#ifndef DCM_E_PERIODICID_NOT_ACCEPTED
#define DCM_E_PERIODICID_NOT_ACCEPTED      ((Std_ReturnType)7)
#endif
#ifndef DCM_E_REQUEST_NOT_ACCEPTED
#define DCM_E_REQUEST_NOT_ACCEPTED         ((Std_ReturnType)8)          /*!< The new request is not accepted by the application (Xxx_Indication()) */
#endif
#ifndef DCM_E_PENDING
#define DCM_E_PENDING                      ((Std_ReturnType)10)
#endif
#ifndef DCM_E_FORCE_RCRRP
#define DCM_E_FORCE_RCRRP                  ((Std_ReturnType)12)
#endif
#ifndef DCM_E_COMPARE_KEY_FAILED
#define DCM_E_COMPARE_KEY_FAILED           ((Std_ReturnType)11)         /*!< The security key is invalid (Xxx_CompareKey()) */
#endif
#ifndef DCM_E_CANCEL
#define DCM_E_CANCEL                       ((Std_ReturnType)13)
#endif

#ifndef DCM_E_PROCESSING_DONE
#define DCM_E_PROCESSING_DONE              ((Std_ReturnType)40)
#endif
#ifndef DCM_E_BUFFERTOOLOW
#define DCM_E_BUFFERTOOLOW                 ((Std_ReturnType)42)
#endif

#define DCM_E_PANIC_NRC                    DCM_E_GENERALREJECT

#  define DCM_DEM_RET_FILTERED_OK          (DEM_FILTERED_OK)
#  define DCM_DEM_RET_FILTERED_NO_ITEMS    (DEM_FILTERED_NO_MATCHING_DTC)
#  define DCM_DEM_RET_FILTERED_PENDING     (DEM_FILTERED_PENDING)

#ifndef DCM_SEC_LEV_LOCKED
#define DCM_SEC_LEV_LOCKED (0U)
#endif
/*
 *  Dcm_CommunicationModeType
 */
#  ifndef DCM_ENABLE_RX_TX_NORM
#   define DCM_ENABLE_RX_TX_NORM (0U)
#  endif

#  ifndef DCM_ENABLE_RX_DISABLE_TX_NORM
#   define DCM_ENABLE_RX_DISABLE_TX_NORM (1U)
#  endif

#  ifndef DCM_DISABLE_RX_ENABLE_TX_NORM
#   define DCM_DISABLE_RX_ENABLE_TX_NORM (2U)
#  endif

#  ifndef DCM_DISABLE_RX_TX_NORMAL
#   define DCM_DISABLE_RX_TX_NORMAL (3U)
#  endif

#  ifndef DCM_ENABLE_RX_TX_NM
#   define DCM_ENABLE_RX_TX_NM (4U)
#  endif

#  ifndef DCM_ENABLE_RX_DISABLE_TX_NM
#   define DCM_ENABLE_RX_DISABLE_TX_NM (5U)
#  endif

#  ifndef DCM_DISABLE_RX_ENABLE_TX_NM
#   define DCM_DISABLE_RX_ENABLE_TX_NM (6U)
#  endif

#  ifndef DCM_DISABLE_RX_TX_NM
#   define DCM_DISABLE_RX_TX_NM (7U)
#  endif

#  ifndef DCM_ENABLE_RX_TX_NORM_NM
#   define DCM_ENABLE_RX_TX_NORM_NM (8U)
#  endif

#  ifndef DCM_ENABLE_RX_DISABLE_TX_NORM_NM
#   define DCM_ENABLE_RX_DISABLE_TX_NORM_NM (9U)
#  endif

#  ifndef DCM_DISABLE_RX_ENABLE_TX_NORM_NM
#   define DCM_DISABLE_RX_ENABLE_TX_NORM_NM (10U)
#  endif

#  ifndef DCM_DISABLE_RX_TX_NORM_NM
#   define DCM_DISABLE_RX_TX_NORM_NM (11U)
#  endif

/*
 * Dcm_ReturnReadMemoryType
 */

#define DCM_READ_OK             (0x00)
#define DCM_READ_PENDING        (0x01)
#define DCM_READ_FAILED         (0x02)
#define DCM_READ_FORCE_RCRRP    (0x03)

/*
 * Dcm_ReturnWriteMemoryType
 */

#define DCM_WRITE_OK            (0x00)
#define DCM_WRITE_PENDING       (0x01)
#define DCM_WRITE_FAILED        (0x02)
#define DCM_WRITE_FORCE_RCRRP   (0x03)

/*
 * Dcm_EcuStartModeType
 */

#define DCM_COLD_START          (0x00)
#define DCM_WARM_START          (0x01)

/*
 * Dcm_DidSupportedType
 */

#define DCM_DID_SUPPORTED       (0x00)
#define DCM_DID_NOT_SUPPORTED   (0x01)

/*
 *  DCM ROE Type
 */
// #if(DCM_SVC_86_SUPPORT_ENABLED == STD_ON)

#define DCM_ROE_STOPPED         (0x00)
#define DCM_ROE_STARTED         (0x05)
#define DCM_ROE_CLEARED         (0x06)

#define DCM_ROE_ONDTCSTATUSCHANGE                         (0x01)
#define DCM_ROE_EVENT_WINDOW_INFINITE                     (0x02)
#define DCM_ROE_EVENT_WINDOW_CURRENT_CYCLE                (0x03)
#define DCM_ROE_EVENT_WINDOW_CURRENT_AND_FOLLOWING_CYCLE  (0x04)

// #endif /* (DCM_SVC_86_SUPPORT_ENABLED == STD_ON) */


/*****************************************************************************
 *                                 Type Declarations                          *
 ******************************************************************************/

typedef uint8 Dcm_StatusType;

typedef uint8 Dcm_ReturnReadMemoryType;
typedef uint8 Dcm_ReturnWriteMemoryType;
typedef uint8 Dcm_EcuStartModeType;
#ifndef Rte_TypeDef_Dcm_MsgLenType
typedef uint32 Dcm_MsgLenType;
#endif
typedef uint8 DcmDsl_BufferType;
typedef uint8 Dcm_DemClientIdType;

#ifndef Rte_TypeDef_Dcm_MsgItemType
typedef uint8 Dcm_MsgItemType;
#endif
typedef Dcm_MsgItemType *Dcm_MsgType;
typedef uint8 Dcm_IdContextType;
typedef uint8 Dcm_DidSupportedType;

typedef uint8 Dcm_BitType;

typedef struct
{
    Dcm_BitType reqType :1;             /* 0: physical 1: functional */
    Dcm_BitType suppressPosResponse :1; /* 0: do not suppress positive response, 1: do suppress positive response  */
    Dcm_BitType reqTypeStored :2;       /* 0: physical 1: functional 2: not set */
} Dcm_MsgAddInfoType;

typedef struct
{
    Dcm_MsgLenType reqDataLen;
    Dcm_MsgLenType resDataLen;
    Dcm_MsgLenType resMaxDataLen;
    Dcm_MsgType reqData;
    Dcm_MsgType resData;
    volatile Dcm_MsgAddInfoType msgAddInfo;
    Dcm_IdContextType idContext;
    PduIdType rxPduId;
	Dcm_DemClientIdType DemClientId;
} Dcm_MsgContextType;

typedef struct
{
    uint8 Dcm_DataTransferState;
    uint8 Dcm_DataTransferOldBlockCounter;
    uint32 Blocklength;
    uint32 MemAddress;
    uint32 MemSize;
}Dcm_DataTransferType;

typedef struct
{
    uint16 TesterSourceAddr;
    uint8 ProtocolId;
    uint8 Sid;
    uint8 SubFuncId;
    boolean ReprogrammingRequest;
    boolean ApplUpdated;
    boolean ResponseRequired;
} Dcm_ProgConditionsType;

/* test */
typedef uint8 Dcm_ConfigType;

/* Service 87 */

// #if(DCM_SVC_87_SUPPORT_ENABLED == STD_ON)
typedef struct
{
    uint8    LinkCtrlType;
    uint8    Length;
    uint8    State_Ref;
    boolean  IsEnabled;
} Dcm_LinkControlTypeInfo;

typedef struct
{
    uint8   LinkCtrlIdentifier;
    boolean IsEnabled;
    Std_ReturnType (*SubServiceFnc_VMTWFP)(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *Buff, Dcm_NegativeResponseCodeType *NegRes);
} Dcm_LinkControlModeIdentifierInfo;

typedef struct
{
    uint32    LinkRecordIdentifier;
    Std_ReturnType (*SubServiceFnc_VMTWSP)(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *Buff, Dcm_NegativeResponseCodeType *NegRes);
} Dcm_LinkRecordIdentifierInfo;

typedef struct
{
    Std_ReturnType (*SubServiceFnc_TM)(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *Buff, Dcm_NegativeResponseCodeType *NegRes);
} Dcm_LinkTransitionModeInfo;
// #endif /* (DCM_SVC_87_SUPPORT_ENABLED == STD_ON) */

#endif /* DCM_TYPES_H */

/*****************************************************************************
 *     End of File
 *
 *******************************************************************************/
/****************************************************************************
 *   for each change to this file, be sure to record:                        *
 *      1.  who made the change and when the change was made                 *
 *      2.  why the change was made and the intended result                  *
 *   Following block needs to be repeated for each change                    *
 *****************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : 16-Jun-2016                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      :                                                       */
/*Change Description: Datadesign And Framework implemented, Initial Version */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 3-April-2017                                          */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : RTC 838240                                            */
/*Change Description: Fixed the compiler warnings.                          */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 25-Feb-2021                                           */
/*Version           :                                                       */
/*By                : iiliev1                                               */
/*Traceability      :                                                       */
/*Change Description: Implement 0x87 and 0x27 services                      */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 18-Jan-2022                                           */
/*Version           :                                                       */
/*By                : iiliev1                                               */
/*Traceability      : Rtc#1560389                                           */
/*Change Description: DCM and DEM Autosar 4.2.2 Migration                   */
/*--------------------------------------------------------------------------*/

