//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2015] Visteon Corporation
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
//
//---------------------------------------------------------------------------------------------------------------------
/*****************************************************************************
* File Name         :  LinTp_Types.h                                               *
* Module Short Name :  LinIf                                                 *
* Description       :  Contains LinTp Typedef declarations                 *
*                                                                            *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :  Turing C                                               *
*                                                                            *
*****************************************************************************/

#if !defined (LINTP_TYPES_H)
# define LINTP_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
/* include ComStack_Types.h so all needed types are known */
# include "ComStack_Types.h"
#include "Platform_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# define LINTP_TPS_MAJOR_VERSION                    (1u)
# define LINTP_TPS_MINOR_VERSION                    (0u)
# define LINTP_TPS_PATCH_VERSION                    (0u)

/* generator compatibility */
# define LINTP_GENERATOR_COMPATIBILITY_VERSION      ((uint16)0x0104u)

/* type definitions of LinTp */
# define LINTP_FUNC_REQUEST_IDLE                    (0x00u)
# define LINTP_FUNC_REQUEST_PENDING                 (0x01u)
# define LINTP_FUNC_REQUEST_TRANSMITTED             (0x02u)

# define LINTP_LOCAL_BUFFER_SIZE                    (8u) /* currently must be a multiple of 2 because of mask definition below */
# define LINTP_LOCAL_BUFFER_SIZE_MASK               (LINTP_LOCAL_BUFFER_SIZE - 1u)

/*@brief Functional Request Feature enabling - STD_ON(Enable) / STD_OFF(Disable)*/
#define LINTP_FUNCTIONAL_REQUEST_SUPPORTED                            STD_ON 

/*@brief Cancel Transmit Feature enabling - STD_ON(Enable) / STD_OFF(Disable)*/
#define LINTP_CANCEL_TRANSMIT_SUPPORTED                               STD_ON

/*@brief Change Parameter Feature enabling - STD_ON(Enable) / STD_OFF(Disable)*/
#define LINTP_CHANGE_PARAMETER_SUPPORTED                              STD_ON

/*@brief Cancel Response Feature enabling - STD_ON(Enable) / STD_OFF(Disable)*/
#define LINTP_CANCEL_RECEIVE_SUPPORTED                                STD_ON

/*@brief Version Info Feature enabling - STD_ON(Enable) / STD_OFF(Disable)*/
#define LINTP_VERSION_INFO_API                                        STD_ON

/*@brief Functional Request Feature enabling - STD_ON(Enable) / STD_OFF(Disable)*/
#define LINTP_FORWARD_RESPONSEPENDING_TO_PDUR      STD_ON

/*@brief Broadcast Request Handling Feature enabling - STD_ON(Enable) / STD_OFF(Disable)*/
#define LINTP_BROADCAST_REQUEST_HANDLING           STD_ON 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/*@brief This typedef is used to mention the channel type in TP layer*/
typedef uint8                                                      LinTp_ChannelType;

/*@brief This is the base type for the configuration of the LIN Transport Protocol*/
typedef uint8                                                     LinTp_ConfigType;

/**   \brief  value based type definition for LinTp_CtrlIdxOfRxNSdu */
typedef uint16 LinTp_CtrlIdxOfRxNSduType;
 
/**   \brief  value based type definition for LinTp_NADOfRxNSdu */
typedef uint8 LinTp_NADOfRxNSduType;
 
/**   \brief  value based type definition for LinTp_UpperLayerPduIdOfRxNSdu */
typedef PduIdType LinTp_UpperLayerPduIdOfRxNSduType;
 
/**   \brief  value based type definition for LinTp_NcrOfRxNSdu */
typedef uint16 LinTp_NcrOfRxNSduType;

/**   \brief  value based type definition for LinTp_CtrlIdxOfTxNSdu */
typedef uint16 LinTp_CtrlIdxOfTxNSduType;

/**   \brief  value based type definition for LinTp_NADOfTxNSdu */
typedef uint8 LinTp_NADOfTxNSduType;

/**   \brief  value based type definition for LinTp_NasOfTxNSdu */
typedef uint16 LinTp_NasOfTxNSduType;

/**   \brief  value based type definition for LinTp_NcsOfTxNSdu */
typedef uint16 LinTp_NcsOfTxNSduType;

/**   \brief  value based type definition for LinTp_UpperLayerPduIdOfTxNSdu */
typedef PduIdType LinTp_UpperLayerPduIdOfTxNSduType;

/**   \brief  value based type definition for LinTp_AssociatedRxNSduIdOfTxNSdu */
typedef PduIdType LinTp_AssociatedRxNSduIdOfTxNSduType;

/**   \brief  type used in LinTp_RxNSdu */
typedef struct 
{
  LinTp_CtrlIdxOfRxNSduType CtrlIdxOfRxNSdu;  /**< the index of the 1:1 relation pointing to LinTp_Ctrl */
  LinTp_NcrOfRxNSduType NcrOfRxNSdu;  /**< Ncr timeout in ticks */
  LinTp_UpperLayerPduIdOfRxNSduType UpperLayerPduIdOfRxNSdu;  /**< RxNSdu external ID (SNV) */
  LinTp_NADOfRxNSduType NADOfRxNSdu;  /**< NAD */
} LinTp_RxNSduType;

/*@brief Control structure of LinTp for one channel */
typedef struct  
{
  uint16                           LinTp_Timer;               /*!< Current timer value for timeout handling               */
  uint16                           LinTp_TimerReload;         /*!< Timer timeout value depends on next awaited frame type */
  uint16                           LinTp_P2Timer;             /*!< Storing current timer value used for P2 and P2max      */
  uint16                           LinTp_RespPendingCounter;  /*!< Number of received response pending frames             */

  uint16                           LinTp_RemainingLength;     /*!< Bytes to be stored in PduR buffer / to be transmitted  */
  PduIdType                        LinTp_Curr_UL_NSdu_Id;     /*!< Network layer Pdu ID of current request / response     */

  PduInfoType                      LinTp_PduInfoPtr;          /*!< PduInfo structure passed to PduR                       */
  PduIdType                        LinTp_Curr_Rx_Id;          /*!< Internal ID of RxNSdu belonging to current LinTpTxNSdu */

# if ( LINTP_FUNCTIONAL_REQUEST_SUPPORTED == STD_ON )
  PduInfoType                      LinTp_FuncPduInfoPtr;      /*!< PduInfo structure passed to PduR for functional req    */
  PduIdType                        LinTp_Curr_Func_NSdu_Id;   /*!< Network layer Pdu ID of functional request             */
  uint8                            LinTp_ComModeRestore;      /*!< Recovery to correct schedule after functional request  */
  uint8                            LinTp_FuncRequest;         /*!< Status of the functional request                       */
# endif

  uint8                            LinTp_Ch_State;            /*!< State engine                                           */
  uint8                            LinTp_NAD_Requested;       /*!< NAD of request - responses will be compared against it */
  uint8                            LinTp_Tx_Rx_Buffer_Idx;    /*!< Null based index of Tp buffer                          */
  uint8                            LinTp_Tx_Rx_Buffer_Length; /*!< Number of payload bytes of current frame               */
  uint8                            LinTp_Tx_Rx_Buffer[LINTP_LOCAL_BUFFER_SIZE];     /*!< Local Tp buffer                  */
  uint8                            LinTp_SN;                  /*!< Sequence Number of CFs                                 */

  uint8                            LinTp_PortNotification;    /*!< Indication flag to change the schedule table for diag  */

  uint8                            LinTp_PduRNotification;    /*!< Indication flag to notify PduR on Tp Tx/Rx frame       */
  uint8                            LinTp_PduRNotifyResultTx;  /*!< Result of Tx notification to PduR                      */
  PduIdType                        LinTp_PduRNSduIdTx;        /*!< Tx NsduId which shall be reported to PduR              */
  uint8                            LinTp_PduRNotifyResultRx;  /*!< Result of Rx notification to PduR                      */
  PduIdType                        LinTp_PduRNSduIdRx;        /*!< Rx NsduId which shall be reported to PduR              */
  PduIdType                        LinTp_PduRNSduIdTm;        /*!< NsduId which shall be reported to PduR                 */
} LinTp_ControlType;

/**   \brief  type used in LinTp_TxNSdu */
typedef struct 
{
  LinTp_CtrlIdxOfTxNSduType CtrlIdxOfTxNSdu;  /**< the index of the 1:1 relation pointing to LinTp_Ctrl */
  LinTp_NasOfTxNSduType NasOfTxNSdu;  /**< Nas timeout in ticks */
  LinTp_NcsOfTxNSduType NcsOfTxNSdu;  /**< Ncs timeout in ticks */
  LinTp_AssociatedRxNSduIdOfTxNSduType AssociatedRxNSduIdOfTxNSdu;
  LinTp_UpperLayerPduIdOfTxNSduType UpperLayerPduIdOfTxNSdu;
  LinTp_NADOfTxNSduType NADOfTxNSdu;  /**< NAD */
} LinTp_TxNSduType;





/*****************************************************************************************************************/

/* LIN TP communication mode type */
typedef uint8                 LinTp_Mode;           
/*This macro is used when Applicative schedule is selected */
#define LINTP_APPLICATIVE_SCHEDULE           ((LinTp_Mode)0x00u)
/*This macro is used when Master request schedule table is selected */
#define LINTP_DIAG_REQUEST                   ((LinTp_Mode)0x01u)
/*This macro is used when Slave response schedule table is selected */
#define LINTP_DIAG_RESPONSE                  ((LinTp_Mode)0x02u)



#endif /* LINTP_TYPES_H */

/*============================================================================
**
**============================================================================
** C M S    R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
** CMS Rev #        Date         By
** CMS Rev X.X      mm/dd/yy     CDSID
**
**============================================================================

**============================================================================
**Date               : 15-APRIL-2020
**CDSID              : LMAHENDR
**Traceability       : RTC 
**Change Description : Initial version
**============================================================================
*/
/**********************************************************************************************************************
 *  END OF FILE: LinTp_Types.h
 *********************************************************************************************************************/

