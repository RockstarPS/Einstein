/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Dcm
 *           Program: MSR_Ford_SLP1 (MSR_Ford_SLP1)
 *          Customer: Visteon Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: i.MX8 DualX5
 *    License Scope : The usage is restricted to CBD2000484_D03
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Dcm_Lcfg.h
 *   Generation Time: 2022-07-05 19:42:19
 *           Project: Ford_S2dot8 - Version 1.0
 *          Delivery: CBD2000484_D03
 *      Tool Version: DaVinci Configurator  5.21.46 SP3
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * WARNING: This code has been generated with reduced-severity errors. 
 * The created output files contain errors that have been ignored. Usage of the created files can lead to unpredictable behavior of the embedded code.
 * Usage of the created files happens at own risk!
 * 
 * [Warning] DCM06013 - Invalid data identifier (DID) configuration - DcmDspDataConditionCheckReadFncUsed must be FALSE. 
 * - [Reduced Severity due to User-Defined Parameter] IO control DID /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DID_61A4_Warning_Lamp_Status_1 does not support ConditionCheckReadFnc. Therefore all parameters with definition DefinitionRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFncUsed must exist and be equal to false.
 * Erroneous configuration elements:
 * /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DID_61A4_Warning_Lamp_Status_1_CombinedDataElement[0:DcmDspDataConditionCheckReadFncUsed](value=true) (DefRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFncUsed)
 * 
 * [Warning] DCM06013 - Invalid data identifier (DID) configuration - DcmDspDataConditionCheckReadFncUsed must be FALSE. 
 * - [Reduced Severity due to User-Defined Parameter] IO control DID /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/Did_DID_61A5_Warning_Lamp_Status_2 does not support ConditionCheckReadFnc. Therefore all parameters with definition DefinitionRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFncUsed must exist and be equal to false.
 * Erroneous configuration elements:
 * /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DID_61A5_BITMAP_Warning_Lamp_Status_2[0:DcmDspDataConditionCheckReadFncUsed](value=true) (DefRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFncUsed)
 * 
 * [Warning] DCM06013 - Invalid data identifier (DID) configuration - DcmDspDataConditionCheckReadFncUsed must be FALSE. 
 * - [Reduced Severity due to User-Defined Parameter] IO control DID /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/Did_SUPPLIER_USE_GenIllum_DID does not support ConditionCheckReadFnc. Therefore all parameters with definition DefinitionRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFncUsed must exist and be equal to false.
 * Erroneous configuration elements:
 * /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/SUPPLIER_USE_GenIllum_DID[0:DcmDspDataConditionCheckReadFncUsed](value=true) (DefRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFncUsed)
 * 
 * [Warning] DCM06013 - Invalid data identifier (DID) configuration - DcmDspDataConditionCheckReadFncUsed must be FALSE. 
 * - [Reduced Severity due to User-Defined Parameter] IO control DID /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/Did_SUPPLIER_USE_PointerIllum_DID does not support ConditionCheckReadFnc. Therefore all parameters with definition DefinitionRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFncUsed must exist and be equal to false.
 * Erroneous configuration elements:
 * /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/SUPPLIER_USE_PointerIllum_DID[0:DcmDspDataConditionCheckReadFncUsed](value=true) (DefRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFncUsed)
 * 
 * [Warning] DCM06013 - Invalid data identifier (DID) configuration - DcmDspDataConditionCheckReadFncUsed must be FALSE. 
 * - [Reduced Severity due to User-Defined Parameter] IO control DID /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/Did_SUPPLIER_USE_SetDisplayPWM does not support ConditionCheckReadFnc. Therefore all parameters with definition DefinitionRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFncUsed must exist and be equal to false.
 * Erroneous configuration elements:
 * /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/SUPPLIER_USE_SetDisplayPWM[0:DcmDspDataConditionCheckReadFncUsed](value=true) (DefRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFncUsed)
 *********************************************************************************************************************/


#if !defined(DCM_LCFG_H)
# define DCM_LCFG_H
/* ----------------------------------------------
 ~&&&   Includes
---------------------------------------------- */
# include "Dem.h"
# include "Dem_Dcm.h"
/* ----------------------------------------------
 ~&&&   Versions
---------------------------------------------- */

/*! Implementation version */
# define DCM_LCFG_MAJOR_VERSION                                                13u
# define DCM_LCFG_MINOR_VERSION                                                 5u
# define DCM_LCFG_PATCH_VERSION                                                 0u
/* ----------------------------------------------
 ~&&&   Switches
---------------------------------------------- */
# if (DCM_DIDMGR_SUPPORT_ENABLED == STD_ON)
/*! Specifies whether the Dcm_CfgDidMgrOpInfoIoControlType structure is required */
#if (DCM_DIDMGR_OPTYPE_IO_RETCTRL2ECU_ENABLED == STD_ON) || \
    (DCM_DIDMGR_IODID_EXEC_PRECOND_LIMIT_ENABLED == STD_ON) || \
    (DCM_DIDMGR_IO_MASKRECORD_ENABLED == STD_ON)
# define DCM_DIDMGR_OP_INFO_IOCONTROL_ENABLED                        STD_ON
#else
# define DCM_DIDMGR_OP_INFO_IOCONTROL_ENABLED                        STD_OFF
#endif
# endif /* (DCM_DIDMGR_SUPPORT_ENABLED == STD_ON) */
/* ----------------------------------------------
 ~&&&   Typedefs Exported Level 2
---------------------------------------------- */
# if (DCM_MODEMGR_SUPPORT_ENABLED == STD_ON) /* COV_DCM_SUPPORT_ALWAYS TX */
/*! Mode-rule handler function prototype */
typedef P2FUNC(boolean, DCM_CODE, Dcm_ModeRuleFuncType) (Dcm_Ptr2LocalU8Type modeRuleRef /* OUT: The result NRC */);
# endif /* (DCM_MODEMGR_SUPPORT_ENABLED == STD_ON) */
# if (DCM_OBDUDSIDMGR_SUPPORT_ENABLED == STD_ON)
typedef uint8       Dcm_ObdIdMgrHandleMemType;
typedef uint8_least Dcm_ObdIdMgrHandleOptType;
# endif /* (DCM_OBDUDSIDMGR_SUPPORT_ENABLED == STD_ON) */
/*! Base data type for a thread */
typedef uint8        Dcm_ThreadIdMemType;
typedef uint8_least  Dcm_ThreadIdOptType;
/* ----------------------------------------------
 ~&&&   Typedefs
---------------------------------------------- */

/*! Depends on the largest configured buffer size */
typedef uint16 Dcm_CfgNetBufferSizeMemType;
/*! Depends on the largest configured buffer size */
typedef uint16_least Dcm_CfgNetBufferSizeOptType;
/*! Zero based reference to an authentication info entry */
typedef uint8 Dcm_CfgNetAuthInfoRefMemType;
/*! Zero based reference to an authentication info entry */
typedef uint8_least Dcm_CfgNetAuthInfoRefOptType;
/*! Function pointer prototype for a protocol activation notification */
typedef P2FUNC(Std_ReturnType, DCM_CODE, Dcm_NetProtocolIndicationFuncType) (Dcm_ProtocolType newProtocol /* IN: new ProtocolId */);

/*! Diagnostic protocol related notification functions */
struct DCM_CFGNETPROTOCOLNOTIFICATIONINFOTYPE_TAG
{
  Dcm_NetProtocolIndicationFuncType    StartFunc;  /*!< Pointer to a function of kind Xxx_StartProtocol() */
};
typedef struct DCM_CFGNETPROTOCOLNOTIFICATIONINFOTYPE_TAG Dcm_CfgNetProtocolNotificationInfoType;
/*! Zero based reference to a USDT buffer configuration entry (0..31) */
typedef uint8        Dcm_CfgNetBufferRefMemType;
typedef uint8_least  Dcm_CfgNetBufferRefOptType;

/*! Zero based reference to a ComM channel map entry (0..255) */
typedef uint8        Dcm_CfgNetNetIdRefMemType;
typedef uint8_least  Dcm_CfgNetNetIdRefOptType;

/*! Zero based reference to a USDT message transport object (0..31) */
typedef uint8        Dcm_CfgNetTObjHandleMemType;
typedef uint8_least  Dcm_CfgNetTObjHandleOptType;

/*! Zero based reference to a UUDT message transport object (0..255) */
typedef uint8        Dcm_CfgNetPTxObjHandleMemType;
typedef uint8_least  Dcm_CfgNetPTxObjHandleOptType;

/*! Diagnostic protocol priority (0..255) */
typedef uint8        Dcm_CfgNetProtPrioType;

/*! Diagnostic protocol maximum length (0..65535) */
typedef uint16       Dcm_CfgNetProtLengthType;

/*! Zero based reference to a UUDT message DcmTxPduId configuration entry (0..255) */
typedef uint8        Dcm_CfgNetPerTxPduIdRefMemType;
typedef uint8_least  Dcm_CfgNetPerTxPduIdRefOptType;

/*! Diagnostic client connection properties (Valid values: DCM_NET_CONN_PROP_*) */
typedef uint8        Dcm_CfgNetConnPropertiesType;

/*! Diagnostic client connection UUDT frame size (0..4294967295) */
typedef PduLengthType Dcm_UudtFrameSizeType;

/*! Configuration of a USDT buffer */
struct DCM_CFGNETBUFFERINFOTYPE_TAG
{
  Dcm_PbConstMsgType            BufferPtr;  /*!< Pointer to a USDT buffer */
  Dcm_CfgNetBufferSizeMemType   Size;       /*!< Size of this specific USDT buffer */
};
typedef struct DCM_CFGNETBUFFERINFOTYPE_TAG Dcm_CfgNetBufferInfoType;

/*! Configuration of a DcmRxPduId */
struct DCM_CFGNETRXPDUINFOTYPE_TAG
{
  boolean                   IsFuncReq;  /*!< Functional request message: FALSE = physical, TRUE = functional */
  Dcm_NetConnRefMemType     ConnRef;    /*!< Reference to Dcm_CfgNetConnectionInfo[] entry */
};
typedef struct DCM_CFGNETRXPDUINFOTYPE_TAG Dcm_CfgNetRxPduInfoType;

/*! Configuration of a diagnostic client connection */
struct DCM_CFGNETCONNECTIONTYPE_TAG
{
#if (DCM_NET_GENERIC_CONNECTION_ENABLED == STD_ON)
  uint16                          ConnectionId;           /*!< Unique identifier of the tester which uses this connection */
#endif
  uint16                          ClientSrcAddr;          /*!< Diagnostic client's unique source address (identifier) */
#if (DCM_NET_PERIODIC_TX_ENABLED == STD_ON)
  Dcm_TmrTimerCntrMemType         PeriodicTxConfTimeout;  /*!< Diagnostic client specific periodic message transmission confirmation timeout (0 - if no periodic message used) */
  Dcm_UudtFrameSizeType           UudtFrameSize;          /*!< Diagnostic client specific UUDT frame size */
#endif
  PduIdType                       TxPduIdMain;            /*!< PduR's PduId of the main diagnostic response */
  Dcm_CfgNetNetIdRefMemType       NetworkIdRef;           /*!< Reference to Dcm_CfgNetConnComMChannelMap[] entry */
  Dcm_NetProtRefMemType           ProtRef;                /*!< Reference to Dcm_PbCfgNetProtocolInfo[] entry */
#if (DCM_NET_PERIODIC_TX_ENABLED == STD_ON)
  Dcm_CfgNetPerTxPduIdRefMemType  PeriodicTxRef;          /*!< Reference to Dcm_PbCfgNetPerTxPduIdInfo[] entry */
  Dcm_CfgNetPTxObjHandleMemType   NumPeriodicTxPduIds;    /*!< Number of periodic messages of the diagnostic client (0 = none) */
#endif
  uint8                           EcuAddress;             /*!< ECU network address */
#if (DCM_NET_CONN_PROPERTIES_ENABLED == STD_ON)
  Dcm_CfgNetConnPropertiesType    Properties;             /*!< Diagnostic client specific properties (Any combination of DCM_NET_CONN_PROP_*) */
#endif
  uint8                           MetaDataLength;         /*!< Meta Data length. Has a value of 2 for generic connections and 0 for specific connections. */
#if (DCM_AUTHMGR_SUPPORT_ENABLED == STD_ON)
  Dcm_CfgNetAuthInfoRefMemType    AuthInfoRef;            /*!< Reference to Dcm_CfgAuthMgrNetConnInfo[] entry */
#endif
};
typedef struct DCM_CFGNETCONNECTIONTYPE_TAG Dcm_CfgNetConnectionInfoType;

/*! Configuration of a diagnostic client protocol */
struct DCM_CFGNETPROTOCOLTYPE_TAG
{
  Dcm_DiagP2TimingsType       SrvAdjTime;         /*!< The P2 times to be used for all diagnostic clients associated with this diagnostic protocol */
  Dcm_CfgNetProtLengthType    MaxLength;          /*!< Maximum allowed request/response length for all connections within this diagnostic protocol */
  Dcm_ProtocolType            Id;                 /*!< The diagnostic protocol name (e.g. UDS_ON_CAN) */
#if (DCM_NET_PROTOCOL_PRIORITISATION_ENABLED == STD_ON)
  Dcm_CfgNetProtPrioType      Priority;           /*!< The priority of all connections associated with this diagnostic protocol (0 - highest, 255 - lowest) */
#endif
  boolean                     HasRespPendOnBoot;  /*!< Specifies whether RCR-RP shall be sent prior jump to the boot-loader (TRUE - do send RCR-RP prior jump to FBL, FALSE - do not send) */
  Dcm_CfgNetBufferRefMemType  RxTxBufferRef;      /*!< Reference to Dcm_PbCfgNetBufferInfo[] entry */
#if (DCM_DEM_CLIENTID_ENABLED == STD_ON)
  uint8                       DemClientId;        /*!< The DEM client ID */
#endif
  uint8                       ThreadId;           /*!< The active Thread ID */
};
typedef struct DCM_CFGNETPROTOCOLTYPE_TAG Dcm_CfgNetProtocolInfoType;
typedef uint8  Dcm_NetTransportObjectStateType;
typedef uint16 Dcm_NetTransportObjectFlagType;
typedef uint8  Dcm_NetResponseType;
typedef uint8  Dcm_NetComMStateType;

/*! Control data of the USDT message buffers (main and additional) */
struct DCM_NETBUFFERCONTEXTTYPE_TAG
{
  volatile uint8  IsInUseCnt; /*!< Usage counter (0 - not in use, >0 - buffer in use from at least one user) */
};
typedef struct DCM_NETBUFFERCONTEXTTYPE_TAG Dcm_NetBufferContextType;

/*! Transport object control data */
struct DCM_NETTRANSPORTOBJECTTYPE_TAG
{
  Dcm_ReadOnlyMsgType             RxData;                                  /*!< Pointer to the buffer to store the request data (can be the main buffer or an additional buffer) */
  Dcm_NetTransportObjectFlagType  Flags;                                   /*!< Control flags of a transport object (Multiple combination of DCM_NET_TOBJ_FLAG_*) */
  Dcm_CfgNetBufferSizeMemType     RxLength;                                /*!< The diagnostic request length */
  Dcm_CfgNetBufferSizeMemType     BuffPos;                                 /*!< Keeps track of where to copy the next received diagnostic message data portion */
  PduIdType                       RxPduId;                                 /*!< DcmRxPduId used to allocate the transport object */
  Dcm_NetResponseType             ResType;                                 /*!< The diagnostic response type (e.g. RCR-RP, final (not-)paged etc.) */
  Dcm_CfgNetTObjHandleMemType     Handle;                                  /*!< The transport object ID */
  Dcm_NetConnRefMemType           ConnHdl;                                 /*!< Reference to Dcm_PbCfgNetConnectionInfo[] entry */
  Dcm_CfgNetBufferRefMemType      BufferHdl;                               /*!< Reference to Dcm_PbRamNetBufferContext[] entry */
  volatile Dcm_NetTransportObjectStateType State;                          /*!< State of the transport object (Valid values: DCM_NET_TOBJ_STATE_*) */
  Dcm_MsgItemType                 AddBuffer[DCM_NET_TOBJ_ADDBUFFER_SIZE];  /*!< Temporary buffer for NRC 0x78 and 0x21 responses and 0x3E 0x80 functional requests (optional sepcific cause code) */
  PduInfoType                     BuffInfo;                                /*!< PduR transmission data information exchange */
  uint16                          ClientSrcAddr;                           /*!< Client source address, static or according to meta data */
};
typedef struct DCM_NETTRANSPORTOBJECTTYPE_TAG Dcm_NetTransportObjectType;
typedef P2VAR(Dcm_NetTransportObjectType, TYPEDEF, DCM_VAR_NOINIT) Dcm_NetTransportObjectPtrType;

/*! ComM channel related control information */
struct DCM_NETCOMMCONTEXT_TAG
{
  Dcm_NetComMStateType   ComState;            /*!< The current state of the ComM channel (FullCom/SilentCom/NoCom) */
  Dcm_NetConnRefMemType  RegisteredNetworks;  /*!< Number of active USDT diagnostic client connections on certain ComM channel */
};
typedef struct DCM_NETCOMMCONTEXT_TAG Dcm_NetComMContextType;

#if (DCM_NET_PERIODIC_TX_ENABLED == STD_ON)
typedef uint8       Dcm_NetPerTxObjStateMemType;
typedef uint8_least Dcm_NetPerTxObjStateOptType;

/*! Periodic message (UUDT) transport object control data */
struct DCM_NETPERIODICTXOBJECTTYPE_TAG
{
  PduInfoType                          TxPduInfo;                               /*!< PduR transmission data information exchange */
  volatile Dcm_TmrTimerCntrMemType     Timer;                                   /*!< Message transmission deadline monitor (can be changed within an ISR) */
  Dcm_MsgItemType                      TxBuffer[DCM_NET_PERIODIC_BUFFER_SIZE];  /*!< Periodic message data buffer */
  volatile Dcm_NetPerTxObjStateMemType State;                                   /*!< Periodic message state (Free, Reserved, Queued, Sent) */
  uint16                               Did;                                     /*!< The periodic Did assigned with the message */
};
typedef struct DCM_NETPERIODICTXOBJECTTYPE_TAG Dcm_NetPeriodicTxObjectType;
#endif
#if (DCM_VARMGR_MULTI_COM_ENABLED == STD_ON)
/*! Network sub-component post-build-variant (selectable/loadable) related configuration data */
struct DCM_NETVARIANTINFOTYPE_TAG
{
  P2CONST(Dcm_CfgNetRxPduInfoType, AUTOMATIC, DCM_PBCFG)       RxPduIdTable;              /*!< Pointer to the DcmRxPdus' configuration */
  P2CONST(Dcm_CfgNetConnectionInfoType, AUTOMATIC, DCM_PBCFG)  ConnectionTable;           /*!< Pointer to the diagnostic clients' connections */
  P2CONST(Dcm_CfgNetProtocolInfoType, AUTOMATIC, DCM_PBCFG)    ProtocolTable;             /*!< Pointer to the diagnostic protocols' configuration */
  P2CONST(Dcm_CfgNetNetIdRefMemType, AUTOMATIC, DCM_PBCFG)     NetConnComMChannelMap;     /*!< Pointer to the diagnostic client related ComM channel map */
  P2CONST(NetworkHandleType, AUTOMATIC, DCM_PBCFG)             NetworkHandleLookUpTable;  /*!< Pointer to the ComM channel look-up table */
  P2CONST(NetworkHandleType, AUTOMATIC, DCM_PBCFG)             NetAllComMChannelMap;      /*!< Pointer to the map of all related to DCM ComM channels */
# if (DCM_NET_COMCTRL_ALLNET_SUPPORT_ENABLED == STD_ON)
  P2CONST(NetworkHandleType, AUTOMATIC, DCM_PBCFG)             ComCtrlChannelListAll;     /*!< Pointer to the list of all ComM channels to be used for SID 0x28 with SubNetType=AllChannels */
# endif

  P2CONST(Dcm_NetConnRefMemType, AUTOMATIC, DCM_PBCFG)         TxPduIdMap;                /*!< Pointer to the USDT DcmTxPduId to client connection map */
  P2CONST(Dcm_CfgNetPTxObjHandleMemType, AUTOMATIC, DCM_PBCFG) PerTxPduIdMap;             /*!< Pointer to the UUDT DcmTxPduId to periodic message transport object map */
  P2CONST(PduIdType, AUTOMATIC, DCM_PBCFG)                     PerTxPduIdTable;           /*!< Pointer to the list of all UUDT DcmTxPduIds */
# if (DCM_NET_MONITOR_FOREIGN_N_TA_ENABLED == STD_ON)
  P2CONST(PduIdType, AUTOMATIC, DCM_PBCFG)                     CanTp2DcmRxPduIdMap;       /*!< Pointer to the CanTpRxPduId to DcmRxPduId map */
# endif

  PduIdType                     NumRxPduIds;         /*!< Number of DcmRxPduIds */
  PduIdType                     NumTxPduIds;         /*!< Number of DcmTxPduIds */
# if (DCM_NET_MONITOR_FOREIGN_N_TA_ENABLED == STD_ON)
  PduIdType                     CanTpRxPduIdMin;     /*!< Lowest CanTpRxPduId */
  PduIdType                     CanTpRxPduIdMax;     /*!< Highest CanTpRxPduId */
  PduIdType                     NumCanTpRxPduIds;    /*!< Number of used CanTpRcPduIds (0 - none are used, >0 - at least one used) */
# endif
  NetworkHandleType             NumComMChannels;     /*!< Number of all ComM channels related to diagnostic clients */
  NetworkHandleType             NumAllComMChannels;  /*!< Number of all ComM channels managed by DCM */
  Dcm_CfgNetPTxObjHandleMemType NumPerTxObjects;     /*!< Maximum number of periodic message transport objects over all diagnostic client connections */
  Dcm_NetConnRefMemType         NumConnections;      /*!< Number of diagnostic client connections */
  Dcm_NetProtRefMemType         NumProtocols;        /*!< Number of diagnostic protocols */
  Dcm_CfgNetBufferRefMemType    NumBuffers;          /*!< Number of USDT buffers */
  Dcm_CfgNetTObjHandleMemType   NumTranspObjects;    /*!< Number of USDT transport objects */
};
typedef struct DCM_NETVARIANTINFOTYPE_TAG Dcm_CfgNetVariantInfoType;
#endif

#if (DCM_VARMGR_MODE_POSTBUILD_LOAD_ENABLED == STD_ON)
/*! Network sub-component post-build-loadable reallocatable shared RAM data */
struct DCM_NETRAMVARIANTINFOTYPE_TAG
{
# if (DCM_NET_PERIODIC_TX_ENABLED == STD_ON)
  P2VAR(Dcm_NetPeriodicTxObjectType, AUTOMATIC, DCM_RAM_PBCFG) PeriodicTxObjects;  /*!< Pointer to the pool of periodic (UUDT) message transport objects */
# endif
  P2VAR(Dcm_NetComMContextType, AUTOMATIC, DCM_RAM_PBCFG)      ComMContexts;       /*!< Pointer to the pool of ComM channels' control states */
  P2VAR(Dcm_CfgNetTObjHandleMemType, AUTOMATIC, DCM_RAM_PBCFG) ConnHdl2TObjIdMap;  /*!< Pointer to the USDT diagnostic client connection to USDT message transport object allocation map */
  P2VAR(Dcm_NetTransportObjectType, AUTOMATIC, DCM_RAM_PBCFG)  TranspObjects;      /*!< Pointer to the pool of USDT message transport objects */
  P2VAR(Dcm_NetBufferContextType, AUTOMATIC, DCM_RAM_PBCFG)    BufferContexts;     /*!< Pointer to the pool of USDT message buffers' control states */
# if (DCM_MODE_COMMCTRL_ENABLED == STD_ON)
  P2VAR(Dcm_CommunicationModeType, AUTOMATIC, DCM_RAM_PBCFG)   ComCtrlChannels;    /*!< Pointer to the pool of ComM channels' communication state */
# endif
};
typedef struct DCM_NETRAMVARIANTINFOTYPE_TAG Dcm_CfgNetRamVariantInfoType;

/*! Network sub-component post-build-loadable reallocatable shared configuration data */
struct DCM_NETROMVARIANTINFOTYPE_TAG
{
  P2CONST(Dcm_CfgNetBufferInfoType, AUTOMATIC, DCM_PBCFG)  BufferInfo;  /*!< Pointer to the USDT buffer configuration */
};
typedef struct DCM_NETROMVARIANTINFOTYPE_TAG Dcm_CfgNetRomVariantInfoType;
#endif
/*! Depends on the mode rule table size */
typedef uint8 Dcm_CfgModeMgrRuleRefMemType;
/*! Depends on the mode rule table size */
typedef uint8_least Dcm_CfgModeMgrRuleRefOptType;
/*! Depends on the state group with largest number of states */
typedef uint8 Dcm_CfgStateGroupMemType;
/*! Depends on the state group with largest number of states */
typedef uint8_least Dcm_CfgStateGroupOptType;
/*! Depends on the total number of diagnostic service state/mode filters */
typedef uint8 Dcm_CfgStateRefMemType;
/*! Depends on the total number of diagnostic service state/mode filters */
typedef uint8_least Dcm_CfgStateRefOptType;
/*! Depends on the total number of security fixed byte values in non-default security levels */
typedef uint8 Dcm_CfgStateSecurityFixedByteRefMemType;
/*! Depends on the total number of security fixed byte values in non-default security levels */
typedef uint8_least Dcm_CfgStateSecurityFixedByteRefOptType;
/*! Depends on the how many Fixed byte sets are configured per a security level */
typedef uint8 Dcm_CfgStateVsgSecurityFixedByteInfoRefMemType;
/*! Depends on the how many Fixed byte sets are configured per a security level */
typedef uint8_least Dcm_CfgStateVsgSecurityFixedByteInfoRefOptType;
/*! A diagnostic entity diagnostic state related execution pre-conditions package */
struct DCM_CFGSTATEPRECONDITIONTYPE_TAG
{
  Dcm_CfgStateGroupMemType Session;   /*!< Diagnostic session pre-condition(s) (Bitmap) */
#if (DCM_STATE_SECURITY_ENABLED == STD_ON)
  Dcm_CfgStateGroupMemType Security;  /*!< Security access pre-condition(s) (Bitmap) */
#endif
#if (DCM_AUTHMGR_SUPPORT_ENABLED == STD_ON)
  Dcm_CfgStateGroupMemType AuthRole;  /*!< Authentication role pre-condition(s) (Bitmap) */
#endif
};
typedef struct DCM_CFGSTATEPRECONDITIONTYPE_TAG Dcm_CfgStateDiagStateInfoType;

/*! A diagnostic entity complete execution pre-conditions package */
struct DCM_CFGSTATEPRECONDITIONINFOTYPE_TAG
{
#if (DCM_MODEMGR_CHECK_SUPPORT_ENABLED == STD_ON)
  Dcm_CfgModeMgrRuleRefMemType         ModeRuleRef;   /*!< Reference to Dcm_CfgModeMgrRules[] entry */
#endif
  Dcm_CfgStateDiagStateInfoType        States;        /*!< A diagnostic state related pre-condition package */
};
typedef struct DCM_CFGSTATEPRECONDITIONINFOTYPE_TAG Dcm_CfgStatePreconditionInfoType;

/*! Diagnostic session configuration package */
struct DCM_CFGSTATESESSIONINFOTYPE_TAG
{
  Dcm_DiagP2TimingsType                     P2ServerTime;   /*!< Diagnostic session specific P2 timings */
  Rte_ModeType_DcmDiagnosticSessionControl  Mode;           /*!< The diagnostic session state related mode of the mode declaration group DcmDiagnosticSession */
  uint8                                     Value;          /*!< The diagnostic session state ID (i.e. the sub-function of SID 0x10) */
};
typedef struct DCM_CFGSTATESESSIONINFOTYPE_TAG Dcm_CfgStateSessionInfoType;

/*! Security access level configuration package */
struct DCM_CFGSTATESECURITYINFOTYPE_TAG
{
#if (DCM_STATE_SEC_RETRY_ENABLED == STD_ON)
  Dcm_TmrTimerCntrMemType          DelayTimeInvKey;    /*!< The delay time in case of received invalid key (always >0: specific time) */
# if (DCM_STATE_SEC_DELAY_ON_BOOT_ENABLED == STD_ON)
  Dcm_TmrTimerCntrMemType          DelayTimeOnBoot;    /*!< The delay time each time the ECU (re-)starts (i.e. after reset or power down) */
# endif
  Dcm_TmrTimerCntrMemType          ReloadTime;         /*!< The delay time to be used when a Xxx_GetAttemptCounter API fails to report the stored attempt counter value (0: infinity/no delay (see ReloadOnZeroDelay), >0: specific time) */
  boolean                          ReloadOnZeroDelay;  /*!< Determines the meaning of the "ReloadTime == 0": TRUE - the delay time is infinity, FALSE - no delay time required */
  uint8                            NumAttempts;        /*!< The maximum number of attempts to send a valid key */
#endif
  uint8                            Value;              /*!< The security access level state ID (i.e. equals to "(seed/key sub-function ID + 1) / 2" */
#if (DCM_MODE_SECURITY_ACCESS_ENABLED == STD_ON)
  Rte_ModeType_DcmSecurityAccess   Mode;               /*!< The security access level state related mode of the mode declaration group DcmSecurityAccess */
#endif
};
typedef struct DCM_CFGSTATESECURITYINFOTYPE_TAG Dcm_CfgStateSecurityInfoType;

/*! Function pointer prototype for a diagnostic state transition notification */
typedef P2FUNC(void, DCM_CALLOUT_CODE, Dcm_StateChangeIndicationFuncType)(uint8 formerStateId /* IN: former state ID */
                                                                         ,uint8 newStateId /* IN: new state ID */);

/*! Diagnostic state transition notification item configuration package */
struct DCM_CFGSTATENOTIFICATIONINFOTYPE_TAG
{
  Dcm_StateChangeIndicationFuncType      OnChgFunc; /*!< Pointer to a function of kind <UserDefined function per ECUC>() */
};
typedef struct DCM_CFGSTATENOTIFICATIONINFOTYPE_TAG Dcm_CfgStateNotificationInfoType;
typedef P2CONST(Dcm_CfgStateNotificationInfoType, TYPEDEF, DCM_CONST) Dcm_CfgStateNotificationInfoPtrType;
/*! Depends on the size of Dcm_CfgDidMgrDidOpInfo table */
typedef uint16 Dcm_CfgDidMgrOpHandleMemType;
/*! Depends on the size of Dcm_CfgDidMgrDidOpInfo table */
typedef uint16_least Dcm_CfgDidMgrOpHandleOptType;
/*! Depends on the size of Dcm_CfgDidMgrDidOpClassInfo table */
typedef uint16 Dcm_CfgDidMgrDidOpClassHandleMemType;
/*! Depends on the size of Dcm_CfgDidMgrDidOpClassInfo table */
typedef uint16_least Dcm_CfgDidMgrDidOpClassHandleOptType;
/*! Depends on the size of Dcm_CfgDidMgrDidInfo table */
typedef uint8 Dcm_CfgDidMgrDidInfoRefType;
/*! Depends on the size of Dcm_CfgDidMgrDidOpInfo table */
typedef uint16 Dcm_CfgDidMgrAbstractOpRefType;
/*! Depends on the size of the table Dcm_CfgDidMgrOpInfoIoControl */
typedef uint8 Dcm_CfgDidMgrCombinedOpRefType;
/*! Depends on the number of the defined dynamic DIDs */
typedef uint8 Dcm_CfgDidMgrDynDidHandleMemType;
/*! Depends on the number of the defined dynamic DIDs */
typedef uint8_least Dcm_CfgDidMgrDynDidHandleOptType;
/*! Depends on the summation of max number of elements (static DIDs) of all defined dynamic DIDs */
typedef uint8 Dcm_CfgDidMgrDynDidSrcItemIdxMemType;
/*! Depends on the summation of max number of elements (static DIDs) of all defined dynamic DIDs */
typedef uint8_least Dcm_CfgDidMgrDynDidSrcItemIdxOptType;
/*! Depends on the number of IO DIDs */
typedef uint8 Dcm_CfgDidMgrIoDidHandleMemType;
/*! Depends on the number of IO DIDs */
typedef uint8_least Dcm_CfgDidMgrIoDidHandleOptType;
/*! Depends on the size of Dcm_CfgDidMgrSignalOpClassInfo table */
typedef uint16 Dcm_CfgDidMgrSignalOpClassRefMemType;
/*! Depends on the size of Dcm_CfgDidMgrSignalOpClassInfo table */
typedef uint16_least Dcm_CfgDidMgrSignalOpClassRefOptType;
/*! Depends on the maximum number of signals register to a DID */
typedef uint8 Dcm_CfgDidMgrSignalIterMemType;
/*! Depends on the maximum number of signals register to a DID */
typedef uint8_least Dcm_CfgDidMgrSignalIterOptType;
/*! Depends on the size in bytes of the largest control enable mask record either internally or externally */
typedef uint8 Dcm_CfgDidMgrIoDidCemrLengthMemType;
/*! Depends on the size in bytes of the largest control enable mask record either internally or externally */
typedef uint8_least Dcm_CfgDidMgrIoDidCemrLengthOptType;
/*! Depends on the size of DcmCfg_SupportedDIDInfoPool table */
typedef uint8 Dcm_CfgDidMgrSupportedDIDRefType;
/*! Always generated as uint16 */
typedef uint16 Dcm_DidMgrDidLengthType;
/*! Always generated as uint16 */
typedef uint16 Dcm_CfgDidMgrSignalLengthType;
/*! If any paged DID is enalbed, it shall be mapped to Dcm_DidMgrDidLengthType. Otherwise, it shall be mapped to Dcm_CfgNetBufferSizeMemType */
typedef Dcm_CfgNetBufferSizeMemType Dcm_CfgDidMgrOptimizedDidLengthType;
/*! depends on the number of IO DIDs with S/R Interface */
typedef uint8 Dcm_CfgDidMgrIoCtrlSRHandlersRefMemType;
/*! depends on the number of IO DIDs with S/R Interface */
typedef uint8_least Dcm_CfgDidMgrIoCtrlSRHandlersRefOptType;
# if (DCM_DIDMGR_SUPPORT_ENABLED == STD_ON)
typedef Dcm_DidOpType     Dcm_DidMgrOpMemType;
typedef Dcm_DidOpOptType  Dcm_DidMgrOpOptType;
typedef uint8             Dcm_DidMgrOpCallMemType;
typedef uint8_least       Dcm_DidMgrOpCallOptType;
typedef uint16            Dcm_DidMgrOpClassType;
typedef uint8             Dcm_DidMgrRoEEventIdType;

typedef uint8 Dcm_DidMgrIoDidCemrHandlingType;

typedef P2VAR(Dcm_DidMgrDidLengthType,TYPEDEF,DCM_VAR_NOINIT) Dcm_DidMgrDidLengthPtrType;

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_DidMgrOpFuncType) (void);

/*! Information about a DID */
struct DCM_DIDMGRDIDINFOTYPE_TAG
{
  Dcm_CfgDidMgrOptimizedDidLengthType  MinLength;      /*!< Minimum length (concrete length for static DIDs) */
  Dcm_CfgDidMgrOptimizedDidLengthType  MaxLength;      /*!< Maximum length (concrete length for static DIDs) */
  Dcm_CfgDidMgrOptimizedDidLengthType  ReservedLength; /*!< Required buffer space to read the DID if needed - otherwise set to 0 */
  Dcm_CfgDidMgrOpHandleMemType         OpBaseIdx;      /*!< Base index of the associated operations */
#if (DCM_DIDMGR_OP_INFO_ANY_ENABLED == STD_ON)
  Dcm_CfgDidMgrAbstractOpRefType       OpRef;          /*!< Reference to operation information table */
#endif
  Dcm_DidMgrOpMemType                  Operations;     /*!< Bitmap of allowed operations */
};
typedef struct DCM_DIDMGRDIDINFOTYPE_TAG Dcm_CfgDidMgrDidInfoType;

#if (DCM_DIDMGR_SR_IO_CONTROL_ENABLED == STD_ON)
# if (DCM_DIDMGR_SR_IO_SHORT_TERM_ADJUSTMENT_ENABLED == STD_ON)
typedef P2FUNC(Std_ReturnType, DCM_CODE, Dcm_DidMgrIoCtrlReqCtrlStateWriteFuncType)(Dcm_ReadOnlyMsgType reqData);
# endif
typedef P2FUNC(Std_ReturnType, DCM_CODE, Dcm_DidMgrIoCtrlReqUnderCtrlReadFuncType)(P2VAR(uint32, AUTOMATIC, DCM_VAR_NOINIT) underControl);
typedef P2FUNC(Std_ReturnType, DCM_CODE, Dcm_DidMgrIoCtrlReqUnderCtrlWriteFuncType)(uint32 underControl);
typedef P2FUNC(Std_ReturnType, DCM_CODE, Dcm_DidMgrIoCtrlReqIoOpReqWriteFuncType)(uint8 ioOperation
                                                                                 ,uint32 cemr);
typedef P2FUNC(boolean, DCM_CODE, Dcm_DidMgrIoCtrlResIsUpdatedFuncType)(void);
typedef P2FUNC(Std_ReturnType, DCM_CODE, Dcm_DidMgrIoCtrlResReadFuncType)(P2VAR(Dcm_IOOperationResponseType, AUTOMATIC, DCM_VAR_NOINIT) ioResponse);

/*! Struct of SR IO-Control handlers */
struct DCM_DIDMGRIOCTRLSRHANDLERSTYPE
{
# if (DCM_DIDMGR_SR_IO_SHORT_TERM_ADJUSTMENT_ENABLED == STD_ON)
  Dcm_DidMgrIoCtrlReqCtrlStateWriteFuncType  IoCtrlReqCtrlStateWrite;    /*!< Handler to transfer data for short term adjustment */
# endif
  Dcm_DidMgrIoCtrlReqUnderCtrlReadFuncType   IoCtrlReqUnderControlRead;  /*!< Handler to read underControl parameter */
  Dcm_DidMgrIoCtrlReqUnderCtrlWriteFuncType  IoCtrlReqUnderControlWrite; /*!< Handler to write underControl parameter */
  Dcm_DidMgrIoCtrlReqIoOpReqWriteFuncType    IoCtrlReqIoOpReqWrite;      /*!< Handler to transfer new IO operation and CEMR */
  Dcm_DidMgrIoCtrlResIsUpdatedFuncType       IoCtrlResIsUpdated;         /*!< Handler to check if isUpdate flag for response is set */
  Dcm_DidMgrIoCtrlResReadFuncType            IoCtrlResRead;              /*!< Handler to read response data and clear isUpdate flag */
};
typedef struct DCM_DIDMGRIOCTRLSRHANDLERSTYPE Dcm_DidMgrIoCtrlSRHandlersType;
typedef P2CONST(Dcm_DidMgrIoCtrlSRHandlersType, TYPEDEF, DCM_CONST) Dcm_DidMgrIoCtrlSRHandlersPtrType;
typedef CONSTP2CONST(Dcm_DidMgrIoCtrlSRHandlersType, TYPEDEF, DCM_CONST) Dcm_DidMgrIoCtrlSRHandlersConstPtrType;
#endif

/*! Information about a DID operation */
struct DCM_DIDMGRDIDOPINFOTYPE_TAG
{
  Dcm_CfgStateRefMemType                 ExecCondRef;   /*!< Reference to execution conditions */
  Dcm_CfgDidMgrDidOpClassHandleMemType   OpTypeBaseIdx; /*!< Base index for operation types */
  Dcm_DidMgrOpCallMemType                CallTypes;     /*!< Bitmap of supported operation types */
};
typedef struct DCM_DIDMGRDIDOPINFOTYPE_TAG Dcm_CfgDidMgrDidOpInfoType;

/*! Information about a DID operation class */
struct DCM_CFGDIDMGRDIDOPCLASSINFOTYPE_TAG
{
  Dcm_CfgDidMgrSignalOpClassRefMemType  OpClassRef; /*!< Reference to a signal operation class information */
};
typedef struct DCM_CFGDIDMGRDIDOPCLASSINFOTYPE_TAG Dcm_CfgDidMgrDidOpClassInfoType;

/*! Information about a signal operation class */
struct DCM_CFGDIDMGRSIGNALOPCLASSINFOTYPE_TAG
{
  Dcm_DidMgrOpFuncType           OpFunc;    /*!< Generic operation function pointer that will be casted to the concrete operation at run-time */
  Dcm_CfgDidMgrSignalLengthType  MinLength; /*!< Minimum length of the signal */
  Dcm_CfgDidMgrSignalLengthType  MaxLength; /*!< Maximum length of the signal */
  Dcm_DidMgrOpClassType          FuncClass; /*!< Operation function class */
};
typedef struct DCM_CFGDIDMGRSIGNALOPCLASSINFOTYPE_TAG Dcm_CfgDidMgrSignalOpClassInfoType;

#if (DCM_DIDMGR_OP_INFO_IOCONTROL_ENABLED == STD_ON)
/*! Information about an IO control operation */
struct DCM_CFGDIDMGRIOCONTROLINFOTYPE_TAG
{
# if (DCM_DIDMGR_OPTYPE_IO_RETCTRL2ECU_ENABLED == STD_ON)
  Dcm_CfgDidMgrDidOpClassHandleMemType  RetCtrlToEcuOpRef;    /*!< Reference to ReturnControlToECU operation */
# endif
# if (DCM_DIDMGR_IODID_EXEC_PRECOND_LIMIT_ENABLED == STD_ON)
  Dcm_CfgStateRefMemType                CtrlExecCondRef;      /*!< Reference to execution conditions */
# endif
# if (DCM_DIDMGR_IO_MASKRECORD_ENABLED == STD_ON)
  Dcm_CfgDidMgrIoDidCemrLengthMemType   CtrlEnblMaskLength;   /*!< Length of the CEMR */
  Dcm_DidMgrIoDidCemrHandlingType       CtrlEnblMaskHandling; /*!< The type of an IO DID control enable mask record handling */
# endif
};
typedef struct DCM_CFGDIDMGRIOCONTROLINFOTYPE_TAG Dcm_CfgDidMgrOpInfoIoControlType;
#endif

#if (DCM_DIDMGR_OP_INFO_DEFINE_ENABLED == STD_ON)
/*! Operation information for definition of DynDID */
struct DCM_CFGDIDMGRDYNDEFINEINFOTYPE_TAG
{
# if (DCM_DIDMGR_PERIODICDYNDID_ENABLED == STD_ON)
  uint16                                  Did;             /*!< DID number */
# endif
# if (DCM_DIDMGR_DYNDID_CLR_ON_STATE_CHG_ENABLED == STD_ON)
  Dcm_CfgStateRefMemType                  ReadExecCondRef; /*!< Reference to execution conditions */
# endif
  Dcm_CfgDidMgrDynDidSrcItemIdxMemType    SrcItemRef;      /*!< Reference to the first source item */
  uint8                                   NumItems;        /*!< Total number of source items */
};
typedef struct DCM_CFGDIDMGRDYNDEFINEINFOTYPE_TAG Dcm_CfgDidMgrOpInfoDefineType;
#endif

#if (DCM_DIDMGR_OP_INFO_COMBINED_ENABLED == STD_ON)
/*! Combined operation information for IO control and response on event */
struct DCM_CFGDIDMGROPINFOCOMBINEDTYPE_TAG
{
  Dcm_CfgDidMgrCombinedOpRefType OpRefIoControl; /*!< Reference to IO control operation information */
  Dcm_CfgDidMgrCombinedOpRefType OpRefRoE;       /*!< Reference to response on event operation information */
};
typedef struct DCM_CFGDIDMGROPINFOCOMBINEDTYPE_TAG Dcm_CfgDidMgrOpInfoCombinedType;
#endif

#if (DCM_DIDMGR_RANGE_SUPPORT_ENABLED == STD_ON)
typedef Dcm_UtiU16RangeType Dcm_CfgDidMgrDidRangeType;
#endif

#if (DCM_DIDMGR_OP_INFO_ROE_ENABLED == STD_ON)
/*! Operation info for response on event */
struct DCM_CFGDIDMGROPROETYPE_TAG
{
  Dcm_DidMgrRoEEventIdType EventId; /*!< The event ID */
};
typedef struct DCM_CFGDIDMGROPROETYPE_TAG Dcm_CfgDidMgrOpInfoRoEType;
#endif
# endif /* (DCM_DIDMGR_SUPPORT_ENABLED == STD_ON) */
typedef uint8 Dcm_CfgRidMgrOpHandleMemType;
typedef uint8_least Dcm_CfgRidMgrOpHandleOptType;
typedef uint8 Dcm_CfgRidMgrRoutineInfoByteMemType;
typedef uint8 Dcm_CfgRidMgrInfoHandleMemType;
typedef uint8_least Dcm_CfgRidMgrInfoHandleOptType;
# if (DCM_RIDMGR_SUPPORT_ENABLED == STD_ON)
typedef uint8   Dcm_RidMgrOpType;
typedef uint8   Dcm_RidMgrOpCallType;
/*! Dedicated RID data length data type: all service ports do use 16bit length parameter */
typedef uint16  Dcm_RidMgrRidLengthType;
typedef P2VAR(Dcm_RidMgrRidLengthType, TYPEDEF, DCM_VAR_NOINIT) Dcm_RidMgrRidLengthPtrType;

/*!
 * Generic routine operation function prototype
 * \return DCM_E_OK             - Operation finished with success. Do not call again
 * \return DCM_E_NOT_OK         - Operation failed. Take the NRC from ErrorCode. Do not call again
 * \return DCM_E_PENDING        - Requested job not yet finished, call again.
 * \return DCM_E_FORCE_RCRRP    - Send immediately a RCR-RP response. Call again once transmission confirmed (with or without success)
 */
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_RidMgrOpFuncType)(void);

/*! Routine identifier related configuration package */
struct DCM_RIDMGRRIDINFOTYPE_TAG
{
  Dcm_CfgRidMgrOpHandleMemType         OpBaseIdx;          /*!< Reference to Dcm_CfgRidMgrOpInfo[] entry */
  Dcm_CfgStateRefMemType               ExecCondRef;        /*!< Execution pre-condition reference */
  Dcm_RidMgrOpType                     Operations;         /*!< Supported RID operations (Valid values: any combination of DCM_RIDMGR_OP_) */
  Dcm_CfgRidMgrRoutineInfoByteMemType  RoutineInfoByte;    /*!< The routine info byte if supported */
};
typedef struct DCM_RIDMGRRIDINFOTYPE_TAG Dcm_CfgRidMgrRidInfoType;

/*! Routine identifier operation related configuration package */
struct DCM_RIDMGROPINFOTYPE_TAG
{
  Dcm_RidMgrOpFuncType         OpFunc;          /*!< Pointer to the function implementation */
  Dcm_RidMgrRidLengthType      ReqMinLength;    /*!< Minimum request length without the only possible last dynamic length signal (does not include RID + SF) */
  Dcm_RidMgrRidLengthType      ReqMaxLength;    /*!< Maximum request length with the only possible last dynamic length signal (does not include RID + SF) */
  Dcm_RidMgrRidLengthType      ResMinLength;    /*!< Minimum response length without the only possible last dynamic length signal (does not include RID + SF) */
  Dcm_RidMgrRidLengthType      ResMaxLength;    /*!< Maximum response length with the only possible last dynamic length signal (does not include RID + SF) */
  Dcm_RidMgrOpCallType         OpType;          /*!< Function prototype descriptor (Valid values: one of DCM_RIDMGR_OPTYPE_ but not DCM_RIDMGR_OPTYPE_NONE) */
};
typedef struct DCM_RIDMGROPINFOTYPE_TAG Dcm_CfgRidMgrOpInfoType;
typedef P2CONST(Dcm_CfgRidMgrOpInfoType, TYPEDEF, DCM_CONST)   Dcm_RidMgrOpInfoPtrType;
# endif /* (DCM_RIDMGR_SUPPORT_ENABLED == STD_ON) */
typedef uint32 Dcm_CfgMemMgrMemAddrType;
typedef uint32 Dcm_CfgMemMgrReqAddrType;
typedef uint16 Dcm_CfgMemMgrReqSizeType;
typedef uint8 Dcm_CfgMemMgrStateRefType;
typedef uint8 Dcm_CfgMemMgrMemMapIdxMemType;
typedef uint8_least Dcm_CfgMemMgrMemMapIdxOptType;
# if (DCM_MEMMGR_SUPPORT_ENABLED == STD_ON)
/*! Memory manager related configuration package, describes a memory block and the characteristic of the memory block */
struct DCM_CFGMEMMGRMEMMAPINFOTYPE_TAG
{
  Dcm_CfgMemMgrStateRefType    ExecCondRefs[DCM_MEMMGR_NUM_MEMORY_OPERATIONS]; /*!< Reference to the Dcm_CfgStatePreconditions[] entry */
  Dcm_CfgMemMgrMemAddrType     StartAddr;                                      /*!< Start address of the memory block */
  Dcm_CfgMemMgrMemAddrType     EndAddr;                                        /*!< End address of the memory block */
};
typedef struct DCM_CFGMEMMGRMEMMAPINFOTYPE_TAG Dcm_CfgMemMgrMemMapInfoType;
typedef P2CONST(Dcm_CfgMemMgrMemMapInfoType, TYPEDEF, DCM_CONST) Dcm_CfgMemMgrMemMapInfoPtrType;

/*! MID related configuration package */
struct DCM_CFGMEMMGRMEMIDINFOTYPE_TAG
{
  Dcm_CfgMemMgrMemMapInfoPtrType MemMapTable;  /*!< Pointer to the memory map table */
  Dcm_CfgMemMgrMemMapIdxMemType  Size;         /*!< Size of the memory map table */
};
typedef struct DCM_CFGMEMMGRMEMIDINFOTYPE_TAG Dcm_CfgMemMgrMemIdInfoType;
typedef P2VAR(Dcm_CfgMemMgrMemIdInfoType, TYPEDEF, AUTOMATIC)   Dcm_CfgMemMgrMemIdInfoPtrType;
typedef P2CONST(Dcm_CfgMemMgrMemIdInfoType, TYPEDEF, AUTOMATIC) Dcm_CfgMemMgrMemIdInfoConstPtrType;

/*! Shared memory block descriptor data type for other service processors (e.g. 0x2C) */
struct DCM_MEMMGRMEMBLOCKTYPE_TAG
{
  Dcm_CfgMemMgrReqAddrType  Address;  /*!< The address to access */
  Dcm_CfgMemMgrReqSizeType  Length;   /*!< The number of bytes requested */
#if (DCM_MEMMGR_MID_SUPPORT_ENABLED == STD_ON)
  uint8                     Mid;      /*!< The memory identifier */
#endif
};
typedef struct DCM_MEMMGRMEMBLOCKTYPE_TAG Dcm_MemMgrMemBlockType;
typedef P2VAR(Dcm_MemMgrMemBlockType, TYPEDEF, DCM_VAR_NOINIT)   Dcm_MemMgrMemBlockPtrType;
typedef P2CONST(Dcm_MemMgrMemBlockType, TYPEDEF, DCM_VAR_NOINIT) Dcm_MemMgrMemBlockConstPtrType;
# endif /* (DCM_MEMMGR_SUPPORT_ENABLED == STD_ON) */
/*! Forward declaration of DCM_CONTEXTTYPE_TAG */
struct DCM_CONTEXTTYPE_TAG;
typedef struct DCM_CONTEXTTYPE_TAG Dcm_ContextType;
typedef P2VAR(Dcm_ContextType, TYPEDEF, DCM_VAR_NOINIT) Dcm_ContextPtrType;
/*! Diagnostic request indication notification function handler pointer type (for all Xxx_Indication()) */
typedef P2FUNC(Std_ReturnType, DCM_CODE, Dcm_DiagIndicationFuncType) (Dcm_MsgItemType sid     /* IN: SID */
                                                                     ,Dcm_ReadOnlyMsgType reqData /* IN: Request data (behind SID byte) */
                                                                     ,uint16 reqDataLen /* IN: Request data length  */
                                                                     ,uint8 reqType  /* IN: Request type (0 - physical, 1- functional) */
                                                                     ,uint16 srcAddr /* IN: Tester SourceAddress */
                                                                     ,Dcm_NegativeResponseCodePtrType nrc /* OUT: ErrorCode */);

/*! Diagnostic response confirmation notification function handler pointer type (for all Xxx_Confirmation()) */
typedef P2FUNC(Std_ReturnType, DCM_CODE, Dcm_DiagConfirmationFuncType) (Dcm_MsgItemType sid /* IN: SID */
                                                                       ,uint8 reqType  /* IN: Request type (0 - physical, 1- functional) */
                                                                       ,uint16 srcAddr /* IN: Tester SourceAddress */
                                                                       ,Dcm_ConfirmationStatusType confStatus /* IN: Confirmation status */);

/*
 * Diagnostic service handler "class" members:
 */

/*! Constructor (initialization) function prototype */
typedef P2FUNC(void, DCM_CODE, Dcm_DiagSvcInitFuncType) (void);
/*!
 * Processor function prototype
 * \return DCM_E_OK             - Operation finished with success. Do not call again
 * \return DCM_E_NOT_OK         - Operation failed. Take the NRC from ErrorCode. Do not call again
 * \return DCM_E_PENDING        - Requested job not yet finished, call again.
 * \return DCM_E_FORCE_RCRRP    - Send immediately a RCR-RP response. Call again once transmission confirmed (with or without success)
 * \return DCM_E_STOP_REPEATER  - Do not call again.
 * \return DCM_E_PROCESSINGDONE - Depricated return value, equivalent to DCM_E_OK. Shall not be used by any application service processor!
 */
typedef P2FUNC(Std_ReturnType, DCM_CALLOUT_CODE, Dcm_DiagSvcProcessorFuncType) (Dcm_ContextPtrType              pContext    /* IN: pContext */
                                                                               ,Dcm_OpStatusType                OpStatus    /* IN: OpStatus */
                                                                               ,Dcm_MsgContextPtrType           pMsgContext /* IN,OUT: pMsgContext */
                                                                               ,Dcm_NegativeResponseCodePtrType ErrorCode   /* OUT: ErrorCode */);
/*! Post-Processor (fast and normal types) function prototype */
typedef P2FUNC(void, DCM_CALLOUT_CODE, Dcm_DiagSvcConfirmationFuncType) (Dcm_ContextPtrType         pContext   /* IN,OUT: pContext */
                                                                        ,Dcm_ConfirmationStatusType confStatus /* IN: Confirmation status */);

/*!
 * Paged-data provider function prototype
 * \return DCM_E_OK                 - Operation finished with success. Do not call again
 * \return DCM_E_NOT_OK             - Operation failed. Take the NRC from ErrorCode. Do not call again
 * \return DCM_E_PENDING            - Some data written/commited. Call again to fill in more data
 * \return DCM_E_BUFFERTOOLOW       - Maximum available space used but was not enough. Call again when some additional free space available
 * \return DCM_E_DATA_READY_PADDING - No more data to be provided. Do not call again. If needed, switch to padding-byte data provider
 */
typedef P2FUNC(Std_ReturnType, DCM_CALLOUT_CODE, Dcm_DiagSvcUpdateFuncType) (Dcm_ContextPtrType              pContext      /* IN: Pointer to the context */
                                                                            ,Dcm_OpStatusType                OpStatus      /* IN: OpStatus */
                                                                            ,Dcm_DiagDataContextPtrType      pDataContext  /* IN,OUT: paged-data descriptor */
                                                                            ,Dcm_NegativeResponseCodePtrType ErrorCode     /* OUT: ErrorCode */);
/*! Paged-data job cancelation notification function prototype */
typedef P2FUNC(void, DCM_CALLOUT_CODE, Dcm_DiagSvcCancelFuncType) (Dcm_ContextPtrType pContext /* IN: Pointer to the context */
                                                                  ,Dcm_DiagDataContextPtrType pDataContext /* IN,OUT: paged-data descriptor */);

/*! Diagnostic service properties container in bitmap form (Valid values: DCM_DIAG_SVC_CFG_PROP_*) */
typedef uint8 DcmCfg_DiagServicePropertiesType;

/*! Configuration of a diagnostic service handler */
struct DCM_CFGDIAGSERVICEINFOTYPE_TAG
{
  Dcm_DiagSvcProcessorFuncType      ProcFunc;         /*!< Pointer to the processor function (e.g. Dcm_Service10Processor() or any application specific function name) */
#if (DCM_DIAG_SERVICE_DISPATCHER_ENABLED == STD_ON)
  Dcm_DiagSvcProcessorFuncType      AltProcFunc;      /*!< Pointer to the alternative processor function */
#endif
  DcmCfg_DiagServicePropertiesType  Props;            /*!< Diagnostic service properties (Any combination of DCM_DIAG_SVC_CFG_PROP_*) */
  uint8                             MinLength;        /*!< Minimum request length (excluding the SID byte) to be verified prior calling the service processor (0 - no restrictions, >0 - particular minimum length) */
  uint8                             ConfFuncRef;      /*!< Reference to the Dcm_CfgDiagSvcPostProcessors[] entry */
  uint8                             FastConfFuncRef;  /*!< Reference to the Dcm_CfgDiagSvcPostProcessors[] entry (if exist, fast post-processors are located right behind the normal post-processor) */
#if (DCM_PAGED_BUFFER_ENABLED == STD_ON)
  uint8                             UpdateFuncRef;    /*!< Reference to the Dcm_CfgDiagSvcUpdaters[] entry */
  uint8                             CancelFuncRef;    /*!< Reference to the Dcm_CfgDiagSvcCancellers[] entry */
#endif
};
typedef struct DCM_CFGDIAGSERVICEINFOTYPE_TAG Dcm_CfgDiagServiceInfoType;

/*! Configuration of diagnostic request notification handlers */
struct DCM_CFGDIAGSERVICENOFICATIONINFOTYPE_TAG
{
  Dcm_DiagIndicationFuncType      IndFunc;  /*!< Points to a Xxx_Indication() callout (NULL_PTR - means last pair element in a list) */
  Dcm_DiagConfirmationFuncType    ConfFunc; /*!< Points to a Xxx_Confirmation) callout (NULL_PTR - means last pair element in a list) */
};
typedef struct DCM_CFGDIAGSERVICENOFICATIONINFOTYPE_TAG Dcm_CfgDiagNotificationInfoType;
typedef P2CONST(Dcm_CfgDiagNotificationInfoType, TYPEDEF, DCM_CONST) Dcm_CfgDiagNotificationInfoPtrType;
/*! Depends on the total number of configuration variants */
typedef uint8 Dcm_CfgVarMgrDiagVariantIdMemType;
/*! Depends on the total number of configuration variants */
typedef uint8_least Dcm_CfgVarMgrDiagVariantIdOptType;
/*! Depends on the total number of diagnostic variants */
typedef uint8 Dcm_CfgVarMgrBitSetBaseType;
/*! A set of variants */
typedef Dcm_CfgVarMgrBitSetBaseType Dcm_CfgVarMgrBitSetType[1];
#if (DCM_VARMGR_MULTI_COM_ENABLED == STD_ON)
/* Pointer to a particular network configuration variant */
typedef P2CONST(Dcm_CfgNetVariantInfoType, TYPEDEF, DCM_CONST_PBCFG)  Dcm_CfgVarMgrComVariantType;
#endif

#if (DCM_DIAG_MULTI_SVC_TABLE_ENABLED == STD_ON)
/*! Configuration of the common variant data between network and diagnostic services variant information */
struct DCM_CFGVARMGRBRIDGEVARIANTTYPE_TAG
{
  P2CONST(Dcm_CfgDiagSvc2ProtMapMemType, AUTOMATIC, DCM_CONST_PBCFG) Svc2ProtocolMap; /*!< Points to the "diagnostic service to protocol map" for a particual DCM variant (criterion): Dcm_CfgDiagSvcId2ProtMap[] */
};
typedef struct DCM_CFGVARMGRBRIDGEVARIANTTYPE_TAG Dcm_CfgVarMgrBridgeVariantType;
#endif

#if (DCM_VARMGR_MODE_POSTBUILD_LOAD_ENABLED == STD_ON)
/*! Configuration of the common for all PBL variants RAM area */
struct DCM_CFGVARMGRRAMVARIANTTYPE_TAG
{
  Dcm_CfgNetRamVariantInfoType  NetworkRam; /*!< Relocatable RAM for the network sub-component */
};
typedef struct DCM_CFGVARMGRRAMVARIANTTYPE_TAG Dcm_CfgVarMgrRamVariantType;
typedef P2CONST(Dcm_CfgVarMgrRamVariantType, TYPEDEF, DCM_CONST_PBCFG) Dcm_CfgVarMgrRamVariantPtrType;
# if (DCM_VARMGR_MODE_POSTBUILD_LOAD_ENABLED == STD_ON)
/*! Diagnostic sub-component post-build-loadable reallocatable shared configuration data */
struct DCM_DIAGROMVARIANTINFOTYPE_TAG
{
  P2CONST(Dcm_CfgVarMgrBitSetType, AUTOMATIC, DCM_CONST_PBCFG) VariantFilter; /*!< Bitset for enabled variants */
};
typedef struct DCM_DIAGROMVARIANTINFOTYPE_TAG Dcm_CfgDiagRomVariantInfoType;
# endif

/*! Configuration of the common ROM (CONST) area for all PBL variants */
struct DCM_CFGVARMGRROMVARIANTTYPE_TAG
{
  Dcm_CfgNetRomVariantInfoType  NetworkRom; /*!< Relocatable ROM for the network sub-component */
# if (DCM_VARMGR_MULTI_SVC_ANY_ENABLED == STD_ON)
  Dcm_CfgDiagRomVariantInfoType DiagRom;    /*!< Relocatable ROM for the diagnostic sub-component */
# endif
};
typedef struct DCM_CFGVARMGRROMVARIANTTYPE_TAG Dcm_CfgVarMgrRomVariantType;
typedef P2CONST(Dcm_CfgVarMgrRomVariantType, TYPEDEF, DCM_CONST_PBCFG) Dcm_CfgVarMgrRomVariantPtrType;
#endif
/*! Container for all PBS/PBL (PBX) variant configuration parameters (a single criterion package): (network-, diagnostic- and common-(bridge)-variant data) */
struct DCM_CONFIGTYPE_TAG
{
#if (DCM_VARMGR_SUPPORT_ENABLED == STD_ON)
# if (DCM_VARMGR_MULTI_COM_ENABLED == STD_ON)
  Dcm_CfgVarMgrComVariantType       ComVariant;       /*!< Contains all network sub-component related variant information (called COM-criteria) */
# endif
# if (DCM_DIAG_MULTI_SVC_TABLE_ENABLED == STD_ON)
  Dcm_CfgVarMgrBridgeVariantType    BridgeVariant;    /*!< Contains all common/shared data (bridge) between COM and CFG variants */
# endif
# if (DCM_VARMGR_MULTI_SVC_ANY_ENABLED == STD_ON)
  Dcm_CfgVarMgrDiagVariantIdMemType DiagVariantId;    /*!< Identifier for the variant */
# endif
# if (DCM_VARMGR_MODE_POSTBUILD_LOAD_ENABLED == STD_ON)
  Dcm_CfgVarMgrRamVariantPtrType    RamVariant;       /*!< Relocatable PB RAM */
  Dcm_CfgVarMgrRomVariantPtrType    RomVariant;       /*!< Relocatable PB ROM */
# endif
  /* Generally required elements */
# if (DCM_VARMGR_MODE_POSTBUILD_LOAD_ENABLED == STD_ON)
  uint16                            GenOutputType;    /*!< Generator Output Compatibility Version */
  uint16                            FinalMagicNumber; /*!< Configuration structure magic number   */
# endif
#else
  uint8 NoConfig;                                     /*!< In case of PBS with single variant (DCm optimizes the code for pre-compile variant), still a configuration struct is expected by the software environment */
#endif
};
typedef struct DCM_CONFIGTYPE_TAG Dcm_ConfigType;

typedef P2CONST(Dcm_ConfigType, TYPEDEF, DCM_CONST_PBCFG) Dcm_ConfigPtrType;
# if (DCM_AUTHMGR_SUPPORT_ENABLED == STD_ON)
/*! Pointer to  ModeSwitchInterface DcmAuthenticationState_<DcmDslMainConnection> */
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ModeAuthStateModeSwitchOpFuncType) (uint8 nextMode);

/*! Connection specific authentication info */
struct DCM_CFGAUTHMGRNETCONNINFOTYPE_TAG
{
  Dcm_ModeAuthStateModeSwitchOpFuncType AuthStateModeSwitchOpFunc;  /*!< ModeSwitch DcmAuthenticationState_<DcmDslMainConnection> */
  uint32  EcuChallengeLength;                                       /*!< Length of the ECU challenge */
  uint32  RandomJobId;                                              /*!< The CSM job ID for the random generator */
  uint32  ProofOfOwnershipJobId;                                    /*!< The CSM job ID for the proof of ownership */
#if (DCM_SVC_29_02_SUPPORT_ENABLED == STD_ON)
  uint32  SignClientChallengeJobId;                                 /*!< The CSM job ID for the signing the client challenge */
  uint16  EcuCertificateId;                                         /*!< The KEYM ID for the ECU certificate */
#endif
  uint16  ConnectionCertificateId;                                  /*!< The KEYM ID for the connection certificate */
  uint16  CertRoleId;                                               /*!< The KEYM ID for the role certificate element */
#if (DCM_AUTHMGR_WHITELIST_SERVICES_ENABLED == STD_ON)
  uint16  CertWLServicesId;                                         /*!< The KEYM ID for the services white list certificate element */
#endif
#if (DCM_AUTHMGR_WHITELIST_DID_ENABLED == STD_ON)
  uint16  CertWLDidId;                                              /*!< The KEYM ID for the DID white list certificate element */
#endif
#if (DCM_AUTHMGR_WHITELIST_RID_ENABLED == STD_ON)
  uint16  CertWLRidId;                                              /*!< The KEYM ID for the RID white list certificate element */
#endif
#if (DCM_AUTHMGR_WHITELIST_MEM_ENABLED == STD_ON)
  uint16  CertWLMemId;                                              /*!< The KEYM ID for the memory selection white list certificate element */
#endif
};
typedef struct DCM_CFGAUTHMGRNETCONNINFOTYPE_TAG Dcm_CfgAuthMgrNetConnInfoType;
# endif /* (DCM_AUTHMGR_SUPPORT_ENABLED == STD_ON) */
# if (DCM_SVC_01_SUPPORT_ENABLED == STD_ON)
/*! Function pointer prototype for a PID handler */
typedef P2FUNC(Std_ReturnType, DCM_CODE, Dcm_Svc01OpFuncType)(Dcm_MsgType Data);

/*! Diagnostic service 0x01 configuration data */
struct DCM_CFGSVC01DATAINFOTYPE_TAG
{
  Dcm_Svc01OpFuncType  OpFunc;    /*!< Pointer to the PID handler */
  uint16               ResLength; /*!< Response data length without PID */
};
typedef struct DCM_CFGSVC01DATAINFOTYPE_TAG Dcm_CfgSvc01ServiceInfoType;
typedef P2CONST(Dcm_CfgSvc01ServiceInfoType, TYPEDEF, DCM_CONST) Dcm_CfgSvc01ServiceInfoPtrType;
# endif /* (DCM_SVC_01_SUPPORT_ENABLED == STD_ON) */
typedef uint8 Dcm_CfgSvc06Mid2TidRefMemType;
typedef uint8_least Dcm_CfgSvc06Mid2TidRefOptType;
# if (DCM_SVC_06_SUPPORT_ENABLED == STD_ON) && (DCM_OBDIDMGR_OBDMID_SUPPORT_BY_DCM_ENABLED == STD_ON)
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_Svc06MidTidOpFuncType) (Dcm_OpStatusType opStatus          /* opStatus */
                                                                         ,Dcm_Uint16VarDataPtrType testValue /* testValue */
                                                                         ,Dcm_Uint16VarDataPtrType minValue  /* minValue */
                                                                         , Dcm_Uint16VarDataPtrType maxValue /* maxValue */
                                                                         , Dcm_Uint8VarDataPtrType status    /* status */);

/*! Information type for MIDs and TIDs */
struct DCM_CFGSVC06SERVICEINFOTYPE_TAG
{
  Dcm_Svc06MidTidOpFuncType  OpFunc; /*!< Pointer to the Mid Tid handler */
  uint8                      Uasid;  /*!< Unit and scaling identifier to be put on the tester response */
  uint8                      Tid;    /*!< Tester identifier to be put on the tester response */
};
typedef struct DCM_CFGSVC06SERVICEINFOTYPE_TAG Dcm_CfgSvc06MidTidInfoType;
typedef P2CONST(Dcm_CfgSvc06MidTidInfoType, TYPEDEF, DCM_CONST) Dcm_CfgSvc06MidTidInfoPtrType;
# endif /* (DCM_SVC_06_SUPPORT_ENABLED == STD_ON) && (DCM_OBDIDMGR_OBDMID_SUPPORT_BY_DCM_ENABLED == STD_ON) */
# if (DCM_SVC_08_SUPPORT_ENABLED == STD_ON)
/*! Function pointer prototype for a Request-Control handler */
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_Svc08OpFuncType) (Dcm_MsgType resData, Dcm_ReadOnlyMsgType reqData);

/*! Diagnostic service 0x08 configuration data */
struct DCM_CFGSVC08SERVICEINFOTYPE_TAG
{
  Dcm_Svc08OpFuncType OpFunc;     /*!< Pointer to the Request-Control handler */
  uint16              ReqLength;  /*!< Request data length without TID */
  uint16              ResLength;  /*!< Response data length without TID */
};
typedef struct DCM_CFGSVC08SERVICEINFOTYPE_TAG Dcm_CfgSvc08ServiceInfoType;
typedef P2CONST(Dcm_CfgSvc08ServiceInfoType, TYPEDEF, DCM_CONST)  Dcm_CfgSvc08ServiceInfoPtrType;
# endif /* (DCM_SVC_08_SUPPORT_ENABLED == STD_ON) */
# if (DCM_SVC_09_SUPPORT_ENABLED == STD_ON)
/*! Function pointer prototype for a VID handler */
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_Svc09OpFuncType) (Dcm_OpStatusType opStatus
                                                                   ,Dcm_MsgType DataValueBuffer
#if (DCM_DCM_AR_VERSION >= DCM_DCM_AR_VERSION_422)
                                                                   ,Dcm_Uint8VarDataPtrType DataValueBufferSize
#endif
                                                                   );

/*! Diagnostic service 0x09 configuration data */
struct DCM_CFGSVC09SERVICEINFOTYPE_TAG
{
  Dcm_Svc09OpFuncType OpFunc;     /*!< Pointer to the VID handler */
  uint8               ResLength;  /*!< Response data length without VID */
};
typedef struct DCM_CFGSVC09SERVICEINFOTYPE_TAG Dcm_CfgSvc09ServiceInfoType;
typedef P2CONST(Dcm_CfgSvc09ServiceInfoType, TYPEDEF, DCM_CONST) Dcm_CfgSvc09ServiceInfoPtrType;
# endif /* (DCM_SVC_09_SUPPORT_ENABLED == STD_ON) */
# if (DCM_SVC_10_SUPPORT_ENABLED == STD_ON) /* COV_DCM_SUPPORT_ALWAYS TX */
/*! Diagnostic service 0x10 sub-function (diagnostic session) configuration data */
struct DCM_CFGSVC10SUBFUNCINFOTYPE_TAG
{
  Dcm_Svc10P2TimingsType   ResponseTime;    /*!< P2 timings to be reported in the positive response */
#if (DCM_SVC_10_JMP2BOOT_ENABLED == STD_ON)
  Dcm_Svc10SessionBootType BootType;        /*!< Bootloader interaction type (Valid values: DCM_SVC10_BOOT_TYPE_*) */
#endif
};
typedef struct DCM_CFGSVC10SUBFUNCINFOTYPE_TAG Dcm_CfgSvc10SubFuncInfoType;
# endif /* (DCM_SVC_10_SUPPORT_ENABLED == STD_ON) */
# if (DCM_SVC_11_SUPPORT_ENABLED == STD_ON)
/*! Diagnostic service 0x11 sub-function information */
struct DCM_CFGSVC11SUBFUNCINFOTYPE_TAG
{
  Dcm_DiagSvcProcessorFuncType      SubSvcFunc; /*!< The sub function processor */
};
typedef struct DCM_CFGSVC11SUBFUNCINFOTYPE_TAG Dcm_CfgSvc11SubFuncInfoType;
# endif /* (DCM_SVC_11_SUPPORT_ENABLED == STD_ON) */
# if (DCM_SVC_19_SUPPORT_ENABLED == STD_ON)
/*! Diagnostic service 0x19 sub-function configuration data */
struct DCM_CFGSVC19SUBFUNCINFOTYPE_TAG
{
  Dcm_DiagSvcProcessorFuncType      SubSvcFunc; /*!< Pointer to the sub-function handler */
  uint8                             ReqLength;  /*!< Diagnostic service request length (sub-function and data): 0 - dynamic length, !=0 - concrete length (no ISO 14229-1 SF is longer than 255 bytes) */
};
typedef struct DCM_CFGSVC19SUBFUNCINFOTYPE_TAG Dcm_CfgSvc19SubFuncInfoType;
# endif /* (DCM_SVC_19_SUPPORT_ENABLED == STD_ON) */
# if (DCM_SVC_27_SUPPORT_ENABLED == STD_ON)
typedef uint8 Dcm_Svc27OpClassType;

/*! Generic function pointer prototype for a Get-Seed handler */
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_Svc27GetSeedFuncType)(void);

/*! Function pointer prototype for a Compare-Key handler */
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_Svc27CompareKeyFuncType)(Dcm_ReadOnlyMsgType reqData
                                                                          ,Dcm_OpStatusType opStatus
                                                                          ,Dcm_NegativeResponseCodePtrType nrc);

#if (DCM_STATE_SEC_ATT_CNTR_EXT_STORAGE_ENABLED == STD_ON)
/*! Function pointer prototype for a Get-Security-Attempt-Counter handler */
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_Svc27GetAttemptCntrFuncType)(Dcm_OpStatusType opStatus
                                                                              ,P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) attemptCount);

/*! Function pointer prototype for a Set-Security-Attempt-Counter handler */
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_Svc27SetAttemptCntrFuncType)(Dcm_OpStatusType opStatus
                                                                              ,uint8 attemptCount);
#endif

/*! Diagnostic service 0x27 sub-function configuration data */
struct DCM_CFGSVC27SUBFUNCINFOTYPE_TAG
{
  Dcm_CfgNetBufferSizeMemType       ReqLength;   /*!< Request length (for seed: SF + ADR_size, for key: SF + key_size) */
};
typedef struct DCM_CFGSVC27SUBFUNCINFOTYPE_TAG Dcm_CfgSvc27SubFuncInfoType;

/*! Security level specific configuration data */
struct DCM_CFGSVC27SECLEVELINFOTYPE_TAG
{
  Dcm_Svc27GetSeedFuncType         GetSeedFunc;         /*!< Pointer to the Get-Seed handler */
  Dcm_Svc27CompareKeyFuncType      CompareKeyFunc;      /*!< Pointer to the Compare-Key handler */
#if (DCM_STATE_SEC_ATT_CNTR_EXT_STORAGE_ENABLED == STD_ON)
  Dcm_Svc27GetAttemptCntrFuncType  GetAttemptCntrFunc;  /*!< Pointer to the Get-Security-Attempt-Counter handler */
  Dcm_Svc27SetAttemptCntrFuncType  SetAttemptCntrFunc;  /*!< Pointer to the Set-Security-Attempt-Counter handler */
#endif
  Dcm_CfgNetBufferSizeMemType      SeedResLength;       /*!< Seed response length */
  Dcm_Svc27OpClassType             GetSeedFuncClass;    /*!< Get-Seed function prototyp descriptor */
};
typedef struct DCM_CFGSVC27SECLEVELINFOTYPE_TAG Dcm_CfgSvc27SecLevelInfoType;
# endif /* (DCM_SVC_27_SUPPORT_ENABLED == STD_ON) */
# if (DCM_SVC_2C_SUPPORT_ENABLED == STD_ON)
/* Define by DID properties */
#if (DCM_SVC_2C_01_SUPPORT_ENABLED == STD_ON)
typedef uint8 Dcm_Svc2CSrcDidOffsetType;
typedef uint8 Dcm_Svc2CSrcDidSizeType;
#endif
typedef Dcm_UtiBitSetBaseType Dcm_Svc2CSrcClassType;

/*! Information about a DynDID */
struct DCM_SVC2CDYNDIDITEMTYPE_TAG
{
  Dcm_DidMgrDidLengthType         Length; /*!< Total length of the DynDID */
  uint8                           Count;  /*!< Number of source items */
};
typedef struct DCM_SVC2CDYNDIDITEMTYPE_TAG Dcm_Svc2CDynDidItemType;

typedef P2VAR(Dcm_Svc2CDynDidItemType, TYPEDEF, DCM_VAR_NOINIT) Dcm_Svc2CDynDidItemPtrType;

/*! Diagnostic service 0x2C sub-function configuration data */
struct DCM_CFGSVC2CSUBFUNCINFOTYPE_TAG
{
  Dcm_DiagSvcProcessorFuncType SubSvcFunc;   /*!< The sub function processor */
  Dcm_CfgNetBufferSizeMemType  MinReqLength; /*!< Minimum length of a request */
};
typedef struct DCM_CFGSVC2CSUBFUNCINFOTYPE_TAG Dcm_CfgSvc2CSubFuncInfoType;

#if (DCM_SVC_2C_01_SUPPORT_ENABLED == STD_ON)
/*! Information about source DID of a DynDID */
struct DCM_SVC2CSRCDIDITEMINFOTYPE_TAG
{
  Dcm_CfgDidMgrDidInfoRefType  DidInfoIdx; /*!< Reference to Dcm_CfgDidMgrDidInfo[] entry */
  Dcm_Svc2CSrcDidOffsetType    Offset;     /*!< Configured offset in DID data */
  Dcm_Svc2CSrcDidSizeType      Size;       /*!< Configured size of DID data */
};
typedef struct DCM_SVC2CSRCDIDITEMINFOTYPE_TAG Dcm_Svc2CSrcDidItemInfoType;
#endif

#if (DCM_SVC_2C_02_SUPPORT_ENABLED == STD_ON)
/*! Information about source memory item of a DynDID */
struct DCM_SVC2CSRCMEMITEMINFOTYPE_TAG
{
  Dcm_MemMgrMemBlockType MemBlock; /*!< Memory block information */
};
typedef struct DCM_SVC2CSRCMEMITEMINFOTYPE_TAG Dcm_Svc2CSrcMemItemInfoType;
#endif

/*! Information about a DynDID source */
union DCM_SVC2CDYNDIDSRCITEMTYPE_TAG
{                                                                                                                                                    /* PRQA S 0750 */ /* MD_Dcm_Rule19.2 */
#if (DCM_SVC_2C_01_SUPPORT_ENABLED == STD_ON)
  Dcm_Svc2CSrcDidItemInfoType      DidDescriptor; /*!< Descriptor for DID items */
#endif
#if (DCM_SVC_2C_02_SUPPORT_ENABLED == STD_ON)
  Dcm_Svc2CSrcMemItemInfoType      MemDescriptor; /*!< Descriptor for Memory items */
#endif
};
typedef union DCM_SVC2CDYNDIDSRCITEMTYPE_TAG Dcm_Svc2CDynDidSrcItemType;

typedef P2VAR(Dcm_Svc2CDynDidSrcItemType, TYPEDEF, DCM_VAR_NOINIT) Dcm_Svc2CDynDidSrcItemPtrType;

/*! Information about the needed persisting elements of a DynDid */
struct DCM_SVC2CDYNDIDNVMDATATYPE_TAG
{
  Dcm_Svc2CDynDidSrcItemType         SrcItems[DCM_NUM_DYNDID_ITEMS];                                /*!< List of source items */
  Dcm_Svc2CSrcClassType              Sequencer[Dcm_UtiGenericBitSetCalcSize(DCM_NUM_DYNDID_ITEMS)]; /*!< BitMask of enabled source items */          /* PRQA S 1039 */ /* MD_Dcm_Rule1.2_1039 */
  Dcm_Svc2CDynDidItemType            Items[DCM_NUM_DYNDIDS];                                        /*!< List of DIDs */
#if (DCM_SVC_2C_NVRAM_SUPPORT_ENABLED == STD_ON)
  uint16                             MagicNumber;                                                   /*!< Magic number for configuration verification */
# if (DCM_VARMGR_MULTI_SVC_EXCLUSIVE_ENABLED == STD_ON)
  Dcm_CfgVarMgrDiagVariantIdMemType  CfgVariantId;                                                  /*!< Contains the CFG-criteria ID */
# endif
#endif
};
typedef struct DCM_SVC2CDYNDIDNVMDATATYPE_TAG Dcm_Svc2CDynDidNvMDataType;
# endif /* (DCM_SVC_2C_SUPPORT_ENABLED == STD_ON) */
# if (DCM_SVC_85_SUPPORT_ENABLED == STD_ON)
#if (DCM_DEM_API_430_ENABLED == STD_ON)
typedef P2FUNC(Std_ReturnType, DEM_CODE, Dcm_DemControlDtcSettingFuncType) (uint8 ClientId);
#else
typedef P2FUNC(Dem_ReturnControlDTCSettingType, DEM_CODE, Dcm_DemControlDtcSettingFuncType) (Dem_DTCGroupType DTCGroup, Dem_DTCKindType DTCKind);
#endif

/*! Diagnostic service 0x85 sub-function configuration data */
struct DCM_CFGSVC85SUBFUNCINFOTYPE_TAG
{
  Dcm_DemControlDtcSettingFuncType  DemFunc;  /*!< Pointer to the corresponding DTCsetting state Dem API (e.g. Dem_DcmDisableDTCSetting) */
  Rte_ModeType_DcmControlDtcSetting Mode;     /*!< The corresponding mode of the DTCsetting state (Valid values: RTE_MODE_DcmControlDtcSetting_*) */
};
typedef struct DCM_CFGSVC85SUBFUNCINFOTYPE_TAG Dcm_CfgSvc85SubFuncInfoType;
# endif /* (DCM_SVC_85_SUPPORT_ENABLED == STD_ON) */
/* ----------------------------------------------
 ~&&&   Module internal API function declarations
---------------------------------------------- */
# define DCM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
# include "MemMap.h"                                                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*lint -restore */
# if (DCM_DIDMGR_SUPPORT_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  Dcm_DidMgrDidNoOp()
 *********************************************************************************************************************/
/*! \brief          Does nothing.
 *  \details        Placeholder for a signal operation which requires no action.
 *  \param[out]     data        Response data buffer
 *  \return         DCM_E_OK
 *  \context        TASK
 *  \reentrant      TRUE
 *  \pre            -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgrDidNoOp(Dcm_MsgType data);

#if (DCM_DIDMGR_NVM_READ_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  Dcm_DidMgrReadNvMSignal()
 *********************************************************************************************************************/
/*! \brief          Handler to read out a NvRam Block.
 *  \details        -
 *  \param[in]      opStatus    The operation status
 *  \param[out]     data        Response data buffer
 *  \param[in]      blockId     Id of the NvRam block
 *  \return         Operation result
 *  \context        TASK
 *  \reentrant      FALSE
 *  \pre            -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgrNvMReadSignal(Dcm_OpStatusType opStatus
                                                      ,Dcm_MsgType      data
                                                      ,uint16           blockId);
#endif

#if (DCM_DIDMGR_NVM_WRITE_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  Dcm_DidMgrNvMWriteSignal()
 *********************************************************************************************************************/
/*! \brief          Handler to write a NvRam block.
 *  \details        -
 *  \param[in]      data         Request data buffer
 *  \param[in]      opStatus     The operation status
 *  \param[out]     errorCode    The NRC
 *  \param[in]      blockId      Id of the NvRam block
 *  \return         Operation result
 *  \context        TASK
 *  \reentrant      FALSE
 *  \pre            -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgrNvMWriteSignal(Dcm_ReadOnlyMsgType             data
                                                       ,Dcm_OpStatusType                opStatus
                                                       ,Dcm_NegativeResponseCodePtrType errorCode
                                                       ,uint16                          blockId);
#endif

#if (DCM_DIDMGR_SR_IO_CONTROL_ENABLED == STD_ON)
/**********************************************************************************************************************
*  Dcm_DidMgrIoCtrlSRHandler_Control()
*********************************************************************************************************************/
/*! \brief          Handler for IO Dids with S/R Interface.
 *  \details        Handler for IO Dids with S/R Interface and operation type resetToDefault (0x01), freezeCurrentState(0x02)
 *                  or shortTermAdjustment (0x03)
 *  \param[in]      srEntryIndex    Index to table with corresponding RTE S/R callouts
 *  \param[in]      ioOperation     IO Operation type (InputOutputControlParameter of Service 0x02F)
 *  \param[in]      reqData         Request data containing the controlState in case of IO Operation shortTermAdjustment (0x03)
 *  \param[in]      opStatus        The operation status
 *  \param[in]      cemr            Control Enable Mask Record
 *  \param[out]     errorCode       The NRC
 *  \return         Operation result
 *  \context        TASK
 *  \reentrant      FALSE
 *  \pre            -
*********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgrIoCtrlSRHandler_Control(Dcm_CfgDidMgrIoCtrlSRHandlersRefOptType srEntryIndex
                                                                ,uint8                                   ioOperation
                                                                ,Dcm_ReadOnlyMsgType                     reqData
                                                                ,Dcm_OpStatusType                        opStatus
                                                                ,uint32                                  cemr
                                                                ,Dcm_NegativeResponseCodePtrType         errorCode);
#endif

#if (DCM_DIDMGR_SR_IO_CONTROL_ENABLED == STD_ON)
/**********************************************************************************************************************
*  Dcm_DidMgrIoCtrlSRHandler_Reset()
*********************************************************************************************************************/
/*! \brief          Handler for IO Dids with S/R Interface.
 *  \details        Handler for IO Dids with S/R Interface and operation type retrunControlToEcu (0x00)
 *  \param[in]      srEntryIndex    Index to table with corresponding RTE S/R callouts
 *  \param[in]      cemr            Control Enable Mask Record
 *  \param[out]     errorCode       The NRC
 *  \return         Operation result
 *  \context        TASK
 *  \reentrant      FALSE
 *  \pre            -
*********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgrIoCtrlSRHandler_Reset(Dcm_CfgDidMgrIoCtrlSRHandlersRefOptType srEntryIndex
                                                              ,uint32                                  cemr
                                                              ,Dcm_NegativeResponseCodePtrType         errorCode);
#endif
# endif /* (DCM_DIDMGR_SUPPORT_ENABLED == STD_ON) */
# if (DCM_OBDUDSIDMGR_SUPPORT_ENABLED == STD_ON)
#if (DCM_VARMGR_MULTI_SVC_ANY_ENABLED == STD_ON) && \
    (DCM_DIDMGR_SUPPORT_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  Dcm_ObdIdMgrGetDidAvailabilityMask()
 *********************************************************************************************************************/
/*! \brief          OBD availability DID (AID) mask value provider.
 *  \details        Calculates the 32bit mask value for PBS/PBL/CALIBRATABLE_OBD and pre-compile
 *  \param[in]      DidLookUpRefStart    The index of the first element in the DID look-up table the AID shall report.
 *  \param[in]      DidLookUpRefEnd      The index of the last element in the DID look-up table the AID shall report.
 *  \param[in]      maskValue            The offline generated/calibratable mask value
 *  \return         The 32 bit bitmap value
 *  \context        ISR1|ISR2|TASK
 *  \reentrant      TRUE
 *  \pre            -
 *********************************************************************************************************************/
FUNC(uint32, DCM_CODE) Dcm_ObdIdMgrGetDidAvailabilityMask(uint16 DidLookUpRefStart
                                                         ,uint16 DidLookUpRefEnd
                                                         ,Dcm_ObdIdMgrMaskValueTableType maskValue);
#else
/* Just return the offline calculated/calibrated mask */
# define Dcm_ObdIdMgrGetDidAvailabilityMask(DidLookUpRefStart, DidLookUpRefEnd, maskValue) (maskValue)                                               /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif

#if (DCM_VARMGR_MULTI_SVC_ANY_ENABLED == STD_ON) && \
    (DCM_RIDMGR_SUPPORT_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  Dcm_ObdIdMgrGetRidAvailabilityMask()
 *********************************************************************************************************************/
/*! \brief          OBD availability RID (AID) mask value provider.
 *  \details        Calculates the 32bit mask value for PBS/PBL/CALIBRATABLE_OBD and pre-compile
 *  \param[in]      RidLookUpRefStart    The index of the first element in the RID look-up table the AID shall report.
 *  \param[in]      RidLookUpRefEnd      The index of the last element in the RID look-up table the AID shall report.
 *  \param[in]      maskValue            The offline generated/calibratable mask value
 *  \return         The 32 bit bitmap value
 *  \context        ISR1|ISR2|TASK
 *  \reentrant      TRUE
 *  \pre            -
 *********************************************************************************************************************/
FUNC(uint32, DCM_CODE) Dcm_ObdIdMgrGetRidAvailabilityMask(uint16 RidLookUpRefStart
                                                         ,uint16 RidLookUpRefEnd
                                                         ,Dcm_ObdIdMgrMaskValueTableType maskValue);
#else
/* Just return the offline calculated/calibrated mask */
# define Dcm_ObdIdMgrGetRidAvailabilityMask(RidLookUpRefStart, RidLookUpRefEnd, maskValue) (maskValue)                                               /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif

#if (DCM_OBDUDSIDMGR_UDSMID_SUPPORT_BY_DCM_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  Dcm_ObdIdMgrReadUdsMid()
 *********************************************************************************************************************/
/*! \brief          OBD Service "supported ID" reader.
 *  \details        -
 *  \param[in]      handle      The handle
 *  \param[in]      opStatus    The operation status
 *  \param[in]      pDataContext Pointer to the data context
 *  \return         Operation result
 *  \context        TASK
 *  \reentrant      TRUE
 *  \pre            -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CODE) Dcm_ObdIdMgrReadUdsMid(Dcm_ObdIdMgrHandleMemType handle
                                                     ,Dcm_OpStatusType opStatus
                                                     ,Dcm_DiagDataContextPtrType pDataContext);
#endif
# endif /* (DCM_OBDUDSIDMGR_SUPPORT_ENABLED == STD_ON) */
/***********************************************************************************************************************
 *  Dcm_Service27Init()
***********************************************************************************************************************/
/*! \brief         Initializes service 0x27 processing.
 *  \details       -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(void, DCM_CODE) Dcm_Service27Init(void);
/***********************************************************************************************************************
 *  Dcm_Service2FInit()
***********************************************************************************************************************/
/*! \brief         Initializes service 0x2F processing.
 *  \details       -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(void, DCM_CODE) Dcm_Service2FInit(void);
# if (DCM_SVC_2C_SUPPORT_ENABLED == STD_ON)
#if (DCM_DIDMGR_DYNDID_SRCITEM_CHECK_COND_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  Dcm_Svc2CDefMgrConditionCheckRead()
 *********************************************************************************************************************/
/*! \brief          Common DynDID check read condition operation.
 *  \details        -
 *  \param[in]      dynDidHandle    DynDID reference to be read
 *  \param[in]      opStatus        Current operation status
 *  \param[out]     errorCode       Returns an error if any
 *  \return         Next action to perform
 *  \context        TASK
 *  \reentrant      FALSE
 *  \pre            -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CODE) Dcm_Svc2CDefMgrConditionCheckRead(Dcm_CfgDidMgrDynDidHandleMemType dynDidHandle
                                                                ,Dcm_OpStatusType opStatus
                                                                ,Dcm_NegativeResponseCodePtrType errorCode);
#endif
/**********************************************************************************************************************
 *  Dcm_Svc2CDefMgrRead()
 *********************************************************************************************************************/
/*! \brief          Common DynDID reader operation.
 *  \details        -
 *  \param[in]      dynDidHandle    DynDID reference to be read
 *  \param[in]      opStatus        Current operation status
 *  \param[in,out]  pDataContext    Pointer to the data context
 *  \return         Next action to perform
 *  \context        TASK
 *  \reentrant      FALSE
 *  \pre            -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CODE) Dcm_Svc2CDefMgrRead(Dcm_CfgDidMgrDynDidHandleMemType dynDidHandle
                                                  ,Dcm_OpStatusType opStatus
                                                  ,Dcm_DiagDataContextPtrType pDataContext);

/**********************************************************************************************************************
 *  Dcm_Svc2CDefMgrReadDataLength()
 *********************************************************************************************************************/
/*! \brief          Common DynDID reader operation.
 *  \details        -
 *  \param[in]      dynDidHandle    DynDID reference to be read
 *  \param[out]     dataLength      Returns the current DynDID length
 *  \return         Next action to perform
 *  \context        TASK
 *  \reentrant      FALSE
 *  \pre            -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CODE) Dcm_Svc2CDefMgrReadDataLength(Dcm_CfgDidMgrDynDidHandleMemType dynDidHandle
                                                            ,Dcm_DidMgrDidLengthPtrType dataLength);
# endif /* (DCM_SVC_2C_SUPPORT_ENABLED == STD_ON) */
# define DCM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
# include "MemMap.h"                                                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*lint -restore */
/* ----------------------------------------------
 ~&&&   Call-back function declarations
---------------------------------------------- */
# define DCM_START_SEC_CALLOUT_CODE
/*lint -save -esym(961, 19.1) */
# include "MemMap.h"                                                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*lint -restore */
#if (DCM_PAGED_BUFFER_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  Dcm_PagedBufferDataPadding()
 *********************************************************************************************************************/
/*! \brief          A sub-function utility of readDtcInfo.
 *  \details        This function is used for data padding.
 *  \param[in]      pContext              Pointer to the context
 *  \param[in]      opStatus              The operation status
 *  \param[in,out]  pDataContext          Pointer to the data context
 *  \param[out]     ErrorCode             The NRC
 *  \return         DCM_E_BUFFERTOOLOW    Enforce transmission of the current part
 *  \context        TASK
 *  \reentrant      TRUE
 *  \pre            -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_PagedBufferDataPadding(Dcm_ContextPtrType              pContext
                                                                 ,Dcm_OpStatusType                opStatus
                                                                 ,Dcm_DiagDataContextPtrType      pDataContext
                                                                 ,Dcm_NegativeResponseCodePtrType ErrorCode);
#endif
/***********************************************************************************************************************
 *  DcmExt_Services_CS_SessionChangeNotification()
***********************************************************************************************************************/
/*! \brief         This function will be called at a diagnostic session state transition.
 *  \details       -
 *  \param[in]     formerState  Specifies the former diagnostic session ID (source state of transition)
 *  \param[in]     newState     Specifies the new diagnostic session ID (target state of transition)
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 *  \note          The function argument values have the same definition as the ones returned by the API
 *                 Dcm_GetSesCtrlType().
***********************************************************************************************************************/
FUNC(void, DCM_CALLOUT_CODE) DcmExt_Services_CS_SessionChangeNotification(Dcm_SesCtrlType formerState, Dcm_SesCtrlType newState);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_0202()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_0202(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_0202()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_0202(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_2B05()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_2B05(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_2B05()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_2B05(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_404C()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_404C(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_404C()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_404C(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_404C()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_404C(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_4190()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_4190(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_4190()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_4190(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_4193()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_4193(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_4193()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_4193(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_4194()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_4194(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_4194()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_4194(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_4195()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_4195(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_4195()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_4195(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_4196()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_4196(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_4196()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_4196(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_4197()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_4197(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_4197()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_4197(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_4197()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_4197(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_600E()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_600E(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_600E()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_600E(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_600F()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_600F(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_600F()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_600F(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_601A()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_601A(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_RCTECU_601A()
***********************************************************************************************************************/
/*! \brief         Manipulates the IO signal via returning control to ECU.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReturnControlToEcuFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RCTECU_601A(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_STA_601A()
***********************************************************************************************************************/
/*! \brief         Adjusts the IO signal.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataShortTermAdjustmentFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_STA_601A(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_601E()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_601E(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_601E()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_601E(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_601E()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_601E(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_601F()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_601F(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_601F()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_601F(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_601F()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_601F(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_6022()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_6022(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_6022()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_6022(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_6023()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_6023(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_6023()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_6023(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_602E()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_602E(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_602E()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_602E(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_61A4()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_61A4(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_61A4()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_61A4(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RCTECU_61A4()
***********************************************************************************************************************/
/*! \brief         Manipulates the IO signal via returning control to ECU.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReturnControlToEcuFnc.
 *  \param[in]     controlMask  Control mask
 *  \param[out]    ErrorCode    Negative response code
 *  \return        E_OK         The operation is finished
 *  \return        E_NOT_OK     The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RCTECU_61A4(uint32 controlMask, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_STA_61A4()
***********************************************************************************************************************/
/*! \brief         Adjusts the IO signal.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataShortTermAdjustmentFnc.
 *  \param[in]     Data         Data buffer
 *  \param[in]     controlMask  Control mask
 *  \param[out]    ErrorCode    Negative response code
 *  \return        E_OK         The operation is finished
 *  \return        E_NOT_OK     The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_STA_61A4(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, uint32 controlMask, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_61A5()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_61A5(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_61A5()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_61A5(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RCTECU_61A5()
***********************************************************************************************************************/
/*! \brief         Manipulates the IO signal via returning control to ECU.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReturnControlToEcuFnc.
 *  \param[in]     controlMask  Control mask
 *  \param[out]    ErrorCode    Negative response code
 *  \return        E_OK         The operation is finished
 *  \return        E_NOT_OK     The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RCTECU_61A5(uint32 controlMask, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_STA_61A5()
***********************************************************************************************************************/
/*! \brief         Adjusts the IO signal.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataShortTermAdjustmentFnc.
 *  \param[in]     Data         Data buffer
 *  \param[in]     controlMask  Control mask
 *  \param[out]    ErrorCode    Negative response code
 *  \return        E_OK         The operation is finished
 *  \return        E_NOT_OK     The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_STA_61A5(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, uint32 controlMask, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_61A9()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_61A9(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_RCTECU_61A9()
***********************************************************************************************************************/
/*! \brief         Manipulates the IO signal via returning control to ECU.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReturnControlToEcuFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RCTECU_61A9(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_STA_61A9()
***********************************************************************************************************************/
/*! \brief         Adjusts the IO signal.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataShortTermAdjustmentFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_STA_61A9(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_61B0()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_61B0(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_RCTECU_61B0()
***********************************************************************************************************************/
/*! \brief         Manipulates the IO signal via returning control to ECU.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReturnControlToEcuFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RCTECU_61B0(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_STA_61B0()
***********************************************************************************************************************/
/*! \brief         Adjusts the IO signal.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataShortTermAdjustmentFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_STA_61B0(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_61B1()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_61B1(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_RCTECU_61B1()
***********************************************************************************************************************/
/*! \brief         Manipulates the IO signal via returning control to ECU.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReturnControlToEcuFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RCTECU_61B1(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_STA_61B1()
***********************************************************************************************************************/
/*! \brief         Adjusts the IO signal.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataShortTermAdjustmentFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_STA_61B1(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_61B2()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_61B2(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_RCTECU_61B2()
***********************************************************************************************************************/
/*! \brief         Manipulates the IO signal via returning control to ECU.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReturnControlToEcuFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RCTECU_61B2(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_STA_61B2()
***********************************************************************************************************************/
/*! \brief         Adjusts the IO signal.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataShortTermAdjustmentFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_STA_61B2(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_61B7()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_61B7(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_61B7()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_61B7(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_61B8()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_61B8(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_61B8()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_61B8(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_61C0()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_61C0(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_RCTECU_61C0()
***********************************************************************************************************************/
/*! \brief         Manipulates the IO signal via returning control to ECU.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReturnControlToEcuFnc.
 *  \param[in]     controlMask  Control mask
 *  \param[out]    ErrorCode    Negative response code
 *  \return        E_OK         The operation is finished
 *  \return        E_NOT_OK     The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RCTECU_61C0(uint32 controlMask, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_STA_61C0()
***********************************************************************************************************************/
/*! \brief         Adjusts the IO signal.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataShortTermAdjustmentFnc.
 *  \param[in]     Data         Data buffer
 *  \param[in]     controlMask  Control mask
 *  \param[out]    ErrorCode    Negative response code
 *  \return        E_OK         The operation is finished
 *  \return        E_NOT_OK     The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_STA_61C0(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, uint32 controlMask, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_61CE()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_61CE(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_RCTECU_61CE()
***********************************************************************************************************************/
/*! \brief         Manipulates the IO signal via returning control to ECU.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReturnControlToEcuFnc.
 *  \param[in]     controlMask  Control mask
 *  \param[out]    ErrorCode    Negative response code
 *  \return        E_OK         The operation is finished
 *  \return        E_NOT_OK     The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RCTECU_61CE(uint32 controlMask, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_STA_61CE()
***********************************************************************************************************************/
/*! \brief         Adjusts the IO signal.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataShortTermAdjustmentFnc.
 *  \param[in]     Data         Data buffer
 *  \param[in]     controlMask  Control mask
 *  \param[out]    ErrorCode    Negative response code
 *  \return        E_OK         The operation is finished
 *  \return        E_NOT_OK     The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_STA_61CE(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, uint32 controlMask, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_630F()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_630F(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_630F()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_630F(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_A48A()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_A48A(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D022()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D022(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D022()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D022(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D026()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D026(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D026()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D026(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D029()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D029(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D029()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D029(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D02B()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D02B(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D02B()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D02B(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D02C()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D02C(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D02C()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D02C(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D02E()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D02E(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D02E()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D02E(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D039()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D039(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D039()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D039(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D03B()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D03B(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D03B()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D03B(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D03E()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D03E(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D03E()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D03E(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D03F()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D03F(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D03F()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D03F(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D04F()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D04F(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D04F()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D04F(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D100()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D100(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D100()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D100(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D700()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D700(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D700()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D700(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D701()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D701(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D701()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D701(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D706()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D706(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D706()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D706(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D707()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D707(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D707()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D707(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D708()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D708(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D708()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D708(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D709()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D709(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D709()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D709(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D70A()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D70A(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D70A()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D70A(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D70B()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D70B(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D70B()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D70B(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D70C()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D70C(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D70C()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D70C(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D70D()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D70D(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D70D()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D70D(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D70E()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D70E(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D70E()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D70E(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D70F()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D70F(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D70F()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D70F(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D710()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D710(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D710()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D710(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D780()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D780(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D780()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D780(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D781()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D781(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D781()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D781(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D782()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D782(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D782()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D782(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D783()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D783(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D783()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D783(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D784()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D784(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D784()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D784(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D785()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D785(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D785()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D785(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D786()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D786(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D786()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D786(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D787()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D787(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D787()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D787(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D788()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D788(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D788()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D788(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_D789()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_D789(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_D789()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_D789(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DD02()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DD02(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DD02()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DD02(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE00()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE00(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE00()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE00(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE00()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE00(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE01()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE01(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE01()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE01(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE01()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE01(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE02()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE02(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE02()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE02(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE02()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE02(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE03()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE03(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE03()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE03(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE03()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE03(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE04()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE04(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE04()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE04(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE04()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE04(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE05()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE05(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE05()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE05(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE05()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE05(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE06()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE06(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE06()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE06(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE06()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE06(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE07()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE07(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE07()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE07(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE07()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE07(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE08()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE08(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE08()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE08(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE08()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE08(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE09()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE09(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE09()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE09(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE09()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE09(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE0A()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE0A(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE0A()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE0A(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE0A()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE0A(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE0B()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE0B(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE0B()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE0B(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE0B()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE0B(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE0C()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE0C(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE0C()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE0C(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE0C()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE0C(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE0D()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE0D(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE0D()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE0D(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE0D()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE0D(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE0E()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE0E(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE0E()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE0E(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE0E()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE0E(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE0F()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE0F(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE0F()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE0F(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE0F()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE0F(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE10()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE10(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE10()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE10(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE10()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE10(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE11()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE11(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE11()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE11(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE11()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE11(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE12()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE12(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE12()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE12(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE12()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE12(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE13()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE13(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE13()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE13(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE13()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE13(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE14()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE14(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE14()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE14(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE14()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE14(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE15()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE15(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE15()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE15(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE15()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE15(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE16()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE16(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE16()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE16(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE16()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE16(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE17()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE17(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE17()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE17(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE17()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE17(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE18()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE18(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE18()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE18(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE18()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE18(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE19()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE19(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE19()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE19(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE19()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE19(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE1A()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE1A(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE1A()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE1A(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE1A()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE1A(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE1B()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE1B(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE1B()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE1B(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE1B()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE1B(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE1C()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE1C(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE1C()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE1C(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE1C()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE1C(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE1D()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE1D(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE1D()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE1D(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE1D()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE1D(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE1E()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE1E(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE1E()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE1E(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE1E()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE1E(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_DE1F()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_DE1F(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_DE1F()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_DE1F(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_DE1F()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_DE1F(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_F109()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_F109(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_F109()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_F109(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_F110()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_F110(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_F110()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_F110(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_F111()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_F111(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_F111()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_F111(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_F113()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_F113(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_F113()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_F113(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_F120()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[in]     opStatus       The operation status
 *  \param[out]    Data           Data buffer
 *  \return        E_OK           Read operation succeeded
 *  \return        E_NOT_OK       The operation has failed
 *  \return        DCM_E_PENDING  The operation not yet finished
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_F120(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_F120()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[in]     opStatus       The operation status
 *  \param[out]    ErrorCode      Negative response code
 *  \return        E_OK           The operation is finished
 *  \return        E_NOT_OK       The operation has failed
 *  \return        DCM_E_PENDING  The operation not yet finished
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_F120(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_F124()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_F124(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_F124()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_F124(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_F125()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[in]     opStatus       The operation status
 *  \param[out]    Data           Data buffer
 *  \return        E_OK           Read operation succeeded
 *  \return        E_NOT_OK       The operation has failed
 *  \return        DCM_E_PENDING  The operation not yet finished
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_F125(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_F125()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[in]     opStatus       The operation status
 *  \param[out]    ErrorCode      Negative response code
 *  \return        E_OK           The operation is finished
 *  \return        E_NOT_OK       The operation has failed
 *  \return        DCM_E_PENDING  The operation not yet finished
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_F125(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_F126()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[in]     opStatus       The operation status
 *  \param[out]    Data           Data buffer
 *  \return        E_OK           Read operation succeeded
 *  \return        E_NOT_OK       The operation has failed
 *  \return        DCM_E_PENDING  The operation not yet finished
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_F126(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_F126()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[in]     opStatus       The operation status
 *  \param[out]    ErrorCode      Negative response code
 *  \return        E_OK           The operation is finished
 *  \return        E_NOT_OK       The operation has failed
 *  \return        DCM_E_PENDING  The operation not yet finished
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_F126(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_F127()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[in]     opStatus       The operation status
 *  \param[out]    Data           Data buffer
 *  \return        E_OK           Read operation succeeded
 *  \return        E_NOT_OK       The operation has failed
 *  \return        DCM_E_PENDING  The operation not yet finished
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_F127(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_F127()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[in]     opStatus       The operation status
 *  \param[out]    ErrorCode      Negative response code
 *  \return        E_OK           The operation is finished
 *  \return        E_NOT_OK       The operation has failed
 *  \return        DCM_E_PENDING  The operation not yet finished
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_F127(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_F128()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[in]     opStatus       The operation status
 *  \param[out]    Data           Data buffer
 *  \return        E_OK           Read operation succeeded
 *  \return        E_NOT_OK       The operation has failed
 *  \return        DCM_E_PENDING  The operation not yet finished
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_F128(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_F128()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[in]     opStatus       The operation status
 *  \param[out]    ErrorCode      Negative response code
 *  \return        E_OK           The operation is finished
 *  \return        E_NOT_OK       The operation has failed
 *  \return        DCM_E_PENDING  The operation not yet finished
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_F128(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_F15F()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_F15F(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_F15F()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_F15F(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_F162()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_F162(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_F162()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_F162(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_F163()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_F163(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_F163()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_F163(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_F166()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_F166(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_F166()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_F166(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_F17C()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_F17C(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_F17C()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_F17C(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_F17F()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[in]     opStatus       The operation status
 *  \param[out]    Data           Data buffer
 *  \return        E_OK           Read operation succeeded
 *  \return        E_NOT_OK       The operation has failed
 *  \return        DCM_E_PENDING  The operation not yet finished
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_F17F(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_F17F()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[in]     opStatus       The operation status
 *  \param[out]    ErrorCode      Negative response code
 *  \return        E_OK           The operation is finished
 *  \return        E_NOT_OK       The operation has failed
 *  \return        DCM_E_PENDING  The operation not yet finished
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_F17F(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_F17F()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data           Data buffer
 *  \param[in]     opStatus       The operation status
 *  \param[out]    ErrorCode      Negative response code
 *  \return        E_OK           The operation is finished
 *  \return        E_NOT_OK       The operation has failed
 *  \return        DCM_E_PENDING  The operation not yet finished
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_F17F(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_F188()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_F188(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_F188()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_F188(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_F18C()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_F18C(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_F18C()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_F18C(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_F442()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_F442(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_F442()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_F442(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FD03()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FD03(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FD03()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FD03(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FD04()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FD04(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FD04()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FD04(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FD09()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FD09(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FD09()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FD09(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FD0A()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FD0A(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FD0A()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FD0A(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FD25()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FD25(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FD25()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FD25(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RCTECU_FD25()
***********************************************************************************************************************/
/*! \brief         Manipulates the IO signal via returning control to ECU.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReturnControlToEcuFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RCTECU_FD25(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_STA_FD25()
***********************************************************************************************************************/
/*! \brief         Adjusts the IO signal.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataShortTermAdjustmentFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_STA_FD25(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FD26()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FD26(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FD26()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FD26(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RCTECU_FD26()
***********************************************************************************************************************/
/*! \brief         Manipulates the IO signal via returning control to ECU.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReturnControlToEcuFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RCTECU_FD26(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_STA_FD26()
***********************************************************************************************************************/
/*! \brief         Adjusts the IO signal.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataShortTermAdjustmentFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_STA_FD26(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FD27()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FD27(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FD27()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FD27(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RCTECU_FD27()
***********************************************************************************************************************/
/*! \brief         Manipulates the IO signal via returning control to ECU.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReturnControlToEcuFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RCTECU_FD27(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_STA_FD27()
***********************************************************************************************************************/
/*! \brief         Adjusts the IO signal.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataShortTermAdjustmentFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_STA_FD27(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FD28()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FD28(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FD28()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FD28(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FD28()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FD28(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FD44()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FD44(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FD44()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FD44(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FD45()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FD45(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FD45()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FD45(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FD45()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FD45(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FD46()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FD46(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FD65()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FD65(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FD65()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FD65(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FD65()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FD65(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FD66()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FD66(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FD66()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FD66(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FD66()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FD66(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FD67()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FD67(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FD67()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FD67(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FD67()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FD67(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FD6A()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FD6A(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FD6B()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FD6B(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FD6B()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FD6B(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FD7D()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FD7D(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FD7D()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FD7D(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FD80()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[in]     opStatus       The operation status
 *  \param[out]    Data           Data buffer
 *  \return        E_OK           Read operation succeeded
 *  \return        E_NOT_OK       The operation has failed
 *  \return        DCM_E_PENDING  The operation not yet finished
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FD80(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FD80()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[in]     opStatus       The operation status
 *  \param[out]    ErrorCode      Negative response code
 *  \return        E_OK           The operation is finished
 *  \return        E_NOT_OK       The operation has failed
 *  \return        DCM_E_PENDING  The operation not yet finished
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FD80(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FD82()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FD82(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FD82()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FD82(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FD83()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[in]     opStatus       The operation status
 *  \param[out]    Data           Data buffer
 *  \return        E_OK           Read operation succeeded
 *  \return        E_NOT_OK       The operation has failed
 *  \return        DCM_E_PENDING  The operation not yet finished
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FD83(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FD83()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[in]     opStatus       The operation status
 *  \param[out]    ErrorCode      Negative response code
 *  \return        E_OK           The operation is finished
 *  \return        E_NOT_OK       The operation has failed
 *  \return        DCM_E_PENDING  The operation not yet finished
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FD83(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FE00()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FE00(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FE00()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FE00(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FE03()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FE03(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FE03()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FE03(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FE0A()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FE0A(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_RCTECU_FE0A()
***********************************************************************************************************************/
/*! \brief         Manipulates the IO signal via returning control to ECU.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReturnControlToEcuFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RCTECU_FE0A(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_STA_FE0A()
***********************************************************************************************************************/
/*! \brief         Adjusts the IO signal.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataShortTermAdjustmentFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_STA_FE0A(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FE0E()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FE0E(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FE0E()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FE0E(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FE0E()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FE0E(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FE3A()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FE3A(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_RCTECU_FE3A()
***********************************************************************************************************************/
/*! \brief         Manipulates the IO signal via returning control to ECU.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReturnControlToEcuFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RCTECU_FE3A(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_STA_FE3A()
***********************************************************************************************************************/
/*! \brief         Adjusts the IO signal.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataShortTermAdjustmentFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_STA_FE3A(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FE40()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FE40(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FE40()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FE40(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FE70()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FE70(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_RCTECU_FE70()
***********************************************************************************************************************/
/*! \brief         Manipulates the IO signal via returning control to ECU.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReturnControlToEcuFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RCTECU_FE70(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_STA_FE70()
***********************************************************************************************************************/
/*! \brief         Adjusts the IO signal.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataShortTermAdjustmentFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_STA_FE70(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FEF3()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FEF3(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_RCTECU_FEF3()
***********************************************************************************************************************/
/*! \brief         Manipulates the IO signal via returning control to ECU.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReturnControlToEcuFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RCTECU_FEF3(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_STA_FEF3()
***********************************************************************************************************************/
/*! \brief         Adjusts the IO signal.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataShortTermAdjustmentFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_STA_FEF3(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FEF4()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FEF4(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_RCTECU_FEF4()
***********************************************************************************************************************/
/*! \brief         Manipulates the IO signal via returning control to ECU.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReturnControlToEcuFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RCTECU_FEF4(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_STA_FEF4()
***********************************************************************************************************************/
/*! \brief         Adjusts the IO signal.
 *  \details       This function is a request from the DCM to the application to adjust the IO signal. The concrete name
 *                 of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataShortTermAdjustmentFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_STA_FEF4(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FEF5()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FEF5(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FEF5()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FEF5(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FEF5()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FEF5(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FEF6()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FEF6(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FEF6()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FEF6(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FEF6()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FEF6(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FEF7()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FEF7(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FEF7()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FEF7(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FEF7()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FEF7(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FEF8()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FEF8(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FEF8()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FEF8(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FEF8()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FEF8(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FEF9()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FEF9(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FEF9()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FEF9(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FEF9()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FEF9(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FEFA()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FEFA(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FEFA()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FEFA(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FEFA()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FEFA(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FEFB()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FEFB(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FEFB()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FEFB(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FEFB()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FEFB(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FEFC()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FEFC(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FEFC()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FEFC(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FEFC()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FEFC(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FEFD()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FEFD(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FEFD()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FEFD(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FEFD()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FEFD(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FEFE()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FEFE(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FEFE()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FEFE(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FEFE()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FEFE(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FEFF()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FEFF(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FEFF()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FEFF(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FEFF()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FEFF(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FF00()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FF00(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FF00()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FF00(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FF00()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FF00(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FF01()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FF01(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FF01()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FF01(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FF01()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FF01(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FF02()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FF02(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FF02()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FF02(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FF02()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FF02(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FF03()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FF03(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FF03()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FF03(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FF03()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FF03(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FF04()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FF04(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FF04()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FF04(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FF04()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FF04(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FF05()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FF05(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FF05()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FF05(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FF05()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FF05(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FF06()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FF06(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FF06()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FF06(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FF06()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FF06(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FF07()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FF07(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FF07()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FF07(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FF07()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FF07(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FF08()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FF08(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FF08()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FF08(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FF08()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FF08(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FF09()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FF09(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FF09()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FF09(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FF09()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FF09(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FF0A()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FF0A(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FF0A()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FF0A(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FF0A()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FF0A(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FF0B()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FF0B(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FF0B()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FF0B(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FF0B()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FF0B(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FF0C()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FF0C(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FF0C()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FF0C(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FF0C()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FF0C(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FF0D()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FF0D(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FF0D()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FF0D(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FF0D()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FF0D(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FF0E()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FF0E(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FF0E()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FF0E(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FF0E()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FF0E(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FF0F()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FF0F(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FF0F()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FF0F(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FF0F()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FF0F(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FF10()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FF10(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FF10()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FF10(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FF10()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FF10(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FF11()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FF11(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FF11()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FF11(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FF11()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FF11(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FF12()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FF12(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FF12()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FF12(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FF12()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FF12(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FF13()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FF13(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FF13()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FF13(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FF13()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FF13(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FF14()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FF14(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FF14()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FF14(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FF14()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FF14(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FF15()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FF15(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FF15()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FF15(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FF15()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FF15(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataRead_FF16()
***********************************************************************************************************************/
/*! \brief         Reads the data element of the DID.
 *  \details       This function is a request from the DCM to the application to get a data value of a DID/PID. The
 *                 concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc.
 *  \param[out]    Data      Data buffer
 *  \return        E_OK      Read operation succeeded
 *  \return        E_NOT_OK  The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataRead_FF16(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data);
/***********************************************************************************************************************
 *  DcmExt_Services_CndChk_FF16()
***********************************************************************************************************************/
/*! \brief         Checks conditions to read the data element.
 *  \details       This function is a request from the DCM to the application, if the conditions to read a data element
 *                 are correct. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFnc.
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CndChk_FF16(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_DataWrite_FF16()
***********************************************************************************************************************/
/*! \brief         Writes data element of a DID.
 *  \details       This function is a request from the DCM to the application to write in a DID. The concrete name of
 *                 the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc.
 *  \param[in]     Data       Data buffer
 *  \param[out]    ErrorCode  Negative response code
 *  \return        E_OK       The operation is finished
 *  \return        E_NOT_OK   The operation has failed
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_DataWrite_FF16(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineStart_0202()
***********************************************************************************************************************/
/*! \brief         Starts a routine execution.
 *  \details       This function is a request from DCM to the application to start a routine execution.
 *  \param[in]     OpStatus           The operation status
 *  \param[out]    Out_RoutineInfo    Fixed-length output data to provide in the routine control response
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineStart_0202(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineStop_0202()
***********************************************************************************************************************/
/*! \brief         Stops a routine execution.
 *  \details       This function is a request from DCM to the application to stop a routine execution.
 *  \param[in]     OpStatus           The operation status
 *  \param[out]    Out_RoutineInfo    Fixed-length output data to provide in the routine control response
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineStop_0202(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineResults_0202()
***********************************************************************************************************************/
/*! \brief         Reads a routine results.
 *  \details       This function is a request from DCM to the application to read a routine results.
 *  \param[in]     OpStatus                       The operation status
 *  \param[out]    Out_RoutineInfo                Fixed-length output data to provide in the routine control response
 *  \param[out]    Out_Results_Response_Sequence  Variable-length output data to provide in the routine control response
 *  \param[out]    DataLength                     Concrete length of the dynamic response Signal
 *  \return        E_OK                           The operation is finished
 *  \return        DCM_E_PENDING                  The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP              Forces a RCR-RP response
 *                                                The call out will called again once the response is sent. The OpStatus
 *                                                parameter will contain the transmission result
 *  \return        E_NOT_OK                       The operation has failed. A concrete NRC shall be set, otherwise the
 *                                                DCM sends NRC 0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineResults_0202(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_Results_Response_Sequence, P2VAR(uint16, AUTOMATIC, DCM_VAR_NOINIT) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineStart_0210()
***********************************************************************************************************************/
/*! \brief         Starts a routine execution.
 *  \details       This function is a request from DCM to the application to start a routine execution.
 *  \param[in]     OpStatus           The operation status
 *  \param[out]    Out_RoutineInfo    Fixed-length output data to provide in the routine control response
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineStart_0210(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineStart_0213()
***********************************************************************************************************************/
/*! \brief         Starts a routine execution.
 *  \details       This function is a request from DCM to the application to start a routine execution.
 *  \param[in]     OpStatus           The operation status
 *  \param[out]    Out_RoutineInfo    Fixed-length output data to provide in the routine control response
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineStart_0213(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineStart_0301()
***********************************************************************************************************************/
/*! \brief         Starts a routine execution.
 *  \details       This function is a request from DCM to the application to start a routine execution.
 *  \param[in]     In_RTN_0301_START_REQ_DAT_1_Memory_Address  Fixed-length input data provided in the routine control
 *                                                             request
 *  \param[in]     OpStatus                                    The operation status
 *  \param[out]    Out_RoutineInfo                             Fixed-length output data to provide in the routine
 *                                                             control response
 *  \return        E_OK                                        The operation is finished
 *  \return        DCM_E_PENDING                               The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP                           Forces a RCR-RP response
 *                                                             The call out will called again once the response is sent.
 *                                                             The OpStatus parameter will contain the transmission
 *                                                             result
 *  \return        E_NOT_OK                                    The operation has failed. A concrete NRC shall be set,
 *                                                             otherwise the DCM sends NRC 0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineStart_0301(uint32 In_RTN_0301_START_REQ_DAT_1_Memory_Address, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineStart_0304()
***********************************************************************************************************************/
/*! \brief         Starts a routine execution.
 *  \details       This function is a request from DCM to the application to start a routine execution.
 *  \param[in]     OpStatus                                         The operation status
 *  \param[out]    Out_RoutineInfo                                  Fixed-length output data to provide in the routine
 *                                                                  control response
 *  \param[out]    Out_RTN_0304_START_RES_DAT_1_Application_Status  Fixed-length output data to provide in the routine
 *                                                                  control response
 *  \return        E_OK                                             The operation is finished
 *  \return        DCM_E_PENDING                                    The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP                                Forces a RCR-RP response
 *                                                                  The call out will called again once the response is
 *                                                                  sent. The OpStatus parameter will contain the
 *                                                                  transmission result
 *  \return        E_NOT_OK                                         The operation has failed. A concrete NRC shall be
 *                                                                  set, otherwise the DCM sends NRC 0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineStart_0304(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RTN_0304_START_RES_DAT_1_Application_Status, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineStart_2047()
***********************************************************************************************************************/
/*! \brief         Starts a routine execution.
 *  \details       This function is a request from DCM to the application to start a routine execution.
 *  \param[in]     In_RTN_2047_START_REQ_DAT_1_Brand_DNA_Chime           Fixed-length input data provided in the routine
 *                                                                       control request
 *  \param[in]     In_RTN_2047_START_REQ_DAT_2_Volume_Attenuation_Level  Fixed-length input data provided in the routine
 *                                                                       control request
 *  \param[in]     In_RTN_2047_START_REQ_DAT_3_Repetitions               Fixed-length input data provided in the routine
 *                                                                       control request
 *  \param[in]     OpStatus                                              The operation status
 *  \param[out]    Out_RoutineInfo                                       Fixed-length output data to provide in the
 *                                                                       routine control response
 *  \return        E_OK                                                  The operation is finished
 *  \return        DCM_E_PENDING                                         The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP                                     Forces a RCR-RP response
 *                                                                       The call out will called again once the
 *                                                                       response is sent. The OpStatus parameter will
 *                                                                       contain the transmission result
 *  \return        E_NOT_OK                                              The operation has failed. A concrete NRC shall
 *                                                                       be set, otherwise the DCM sends NRC 0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineStart_2047(uint8 In_RTN_2047_START_REQ_DAT_1_Brand_DNA_Chime, uint8 In_RTN_2047_START_REQ_DAT_2_Volume_Attenuation_Level, uint8 In_RTN_2047_START_REQ_DAT_3_Repetitions, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineStop_2047()
***********************************************************************************************************************/
/*! \brief         Stops a routine execution.
 *  \details       This function is a request from DCM to the application to stop a routine execution.
 *  \param[in]     OpStatus           The operation status
 *  \param[out]    Out_RoutineInfo    Fixed-length output data to provide in the routine control response
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineStop_2047(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineResults_2047()
***********************************************************************************************************************/
/*! \brief         Reads a routine results.
 *  \details       This function is a request from DCM to the application to read a routine results.
 *  \param[in]     OpStatus                                                       The operation status
 *  \param[out]    Out_RoutineInfo                                                Fixed-length output data to provide in
 *                                                                                the routine control response
 *  \param[out]    Out_RTN_2047_RQR_RES_DAT_1_Chime_Programmed_Attenuation_Level  Fixed-length output data to provide in
 *                                                                                the routine control response
 *  \return        E_OK                                                           The operation is finished
 *  \return        DCM_E_PENDING                                                  The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP                                              Forces a RCR-RP response
 *                                                                                The call out will called again once
 *                                                                                the response is sent. The OpStatus
 *                                                                                parameter will contain the
 *                                                                                transmission result
 *  \return        E_NOT_OK                                                       The operation has failed. A concrete
 *                                                                                NRC shall be set, otherwise the DCM
 *                                                                                sends NRC 0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineResults_2047(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RTN_2047_RQR_RES_DAT_1_Chime_Programmed_Attenuation_Level, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineStart_FD84()
***********************************************************************************************************************/
/*! \brief         Starts a routine execution.
 *  \details       This function is a request from DCM to the application to start a routine execution.
 *  \param[in]     In_HM_DR_Report_Reset        Fixed-length input data provided in the routine control request
 *  \param[in]     OpStatus                     The operation status
 *  \param[out]    Out_RoutineInfo              Fixed-length output data to provide in the routine control response
 *  \param[out]    Out_HM_DR_FD84_ReportStatus  Fixed-length output data to provide in the routine control response
 *  \return        E_OK                         The operation is finished
 *  \return        DCM_E_PENDING                The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP            Forces a RCR-RP response
 *                                              The call out will called again once the response is sent. The OpStatus
 *                                              parameter will contain the transmission result
 *  \return        E_NOT_OK                     The operation has failed. A concrete NRC shall be set, otherwise the DCM
 *                                              sends NRC 0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineStart_FD84(uint8 In_HM_DR_Report_Reset, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_HM_DR_FD84_ReportStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineResults_FD84()
***********************************************************************************************************************/
/*! \brief         Reads a routine results.
 *  \details       This function is a request from DCM to the application to read a routine results.
 *  \param[in]     OpStatus                             The operation status
 *  \param[out]    Out_RoutineInfo                      Fixed-length output data to provide in the routine control
 *                                                      response
 *  \param[out]    Out_HM_DR_FD84_ReportReset_Executed  Fixed-length output data to provide in the routine control
 *                                                      response
 *  \param[out]    Out_Routine_results                  Fixed-length output data to provide in the routine control
 *                                                      response
 *  \return        E_OK                                 The operation is finished
 *  \return        DCM_E_PENDING                        The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP                    Forces a RCR-RP response
 *                                                      The call out will called again once the response is sent. The
 *                                                      OpStatus parameter will contain the transmission result
 *  \return        E_NOT_OK                             The operation has failed. A concrete NRC shall be set, otherwise
 *                                                      the DCM sends NRC 0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineResults_FD84(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_HM_DR_FD84_ReportReset_Executed, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_Routine_results, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineStart_FD85()
***********************************************************************************************************************/
/*! \brief         Starts a routine execution.
 *  \details       This function is a request from DCM to the application to start a routine execution.
 *  \param[in]     OpStatus           The operation status
 *  \param[out]    Out_RoutineInfo    Fixed-length output data to provide in the routine control response
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineStart_FD85(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineStart_FD87()
***********************************************************************************************************************/
/*! \brief         Starts a routine execution.
 *  \details       This function is a request from DCM to the application to start a routine execution.
 *  \param[in]     In_Options         Fixed-length input data provided in the routine control request
 *  \param[in]     In_Parameters      Fixed-length input data provided in the routine control request
 *  \param[in]     In_Data            Fixed-length input data provided in the routine control request
 *  \param[in]     OpStatus           The operation status
 *  \param[out]    Out_RoutineInfo    Fixed-length output data to provide in the routine control response
 *  \param[out]    Out_Feedback       Fixed-length output data to provide in the routine control response
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineStart_FD87(uint8 In_Options, uint8 In_Parameters, P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) In_Data, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_Feedback, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineStart_FE0A()
***********************************************************************************************************************/
/*! \brief         Starts a routine execution.
 *  \details       This function is a request from DCM to the application to start a routine execution.
 *  \param[in]     OpStatus           The operation status
 *  \param[out]    Out_RoutineInfo    Fixed-length output data to provide in the routine control response
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineStart_FE0A(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineStart_FE0B()
***********************************************************************************************************************/
/*! \brief         Starts a routine execution.
 *  \details       This function is a request from DCM to the application to start a routine execution.
 *  \param[in]     OpStatus           The operation status
 *  \param[out]    Out_RoutineInfo    Fixed-length output data to provide in the routine control response
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineStart_FE0B(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineStart_FE0C()
***********************************************************************************************************************/
/*! \brief         Starts a routine execution.
 *  \details       This function is a request from DCM to the application to start a routine execution.
 *  \param[in]     OpStatus           The operation status
 *  \param[out]    Out_RoutineInfo    Fixed-length output data to provide in the routine control response
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineStart_FE0C(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineStart_FE22()
***********************************************************************************************************************/
/*! \brief         Starts a routine execution.
 *  \details       This function is a request from DCM to the application to start a routine execution.
 *  \param[in]     OpStatus           The operation status
 *  \param[out]    Out_RoutineInfo    Fixed-length output data to provide in the routine control response
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineStart_FE22(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineResults_FE22()
***********************************************************************************************************************/
/*! \brief         Reads a routine results.
 *  \details       This function is a request from DCM to the application to read a routine results.
 *  \param[in]     OpStatus           The operation status
 *  \param[out]    Out_RoutineInfo    Fixed-length output data to provide in the routine control response
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineResults_FE22(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineStart_FE30()
***********************************************************************************************************************/
/*! \brief         Starts a routine execution.
 *  \details       This function is a request from DCM to the application to start a routine execution.
 *  \param[in]     In_NVM_Subfunction     Fixed-length input data provided in the routine control request
 *  \param[in]     In_Prefix_Character_0  Fixed-length input data provided in the routine control request
 *  \param[in]     In_Prefix_Character_1  Fixed-length input data provided in the routine control request
 *  \param[in]     In_Prefix_Character_2  Fixed-length input data provided in the routine control request
 *  \param[in]     In_Prefix_Character_3  Fixed-length input data provided in the routine control request
 *  \param[in]     In_Suffix_Character_0  Fixed-length input data provided in the routine control request
 *  \param[in]     In_Suffix_Character_1  Fixed-length input data provided in the routine control request
 *  \param[in]     In_Suffix_Character_2  Fixed-length input data provided in the routine control request
 *  \param[in]     OpStatus               The operation status
 *  \param[out]    Out_RoutineInfo        Fixed-length output data to provide in the routine control response
 *  \param[out]    Out_NVM_Subfunction    Fixed-length output data to provide in the routine control response
 *  \return        E_OK                   The operation is finished
 *  \return        DCM_E_PENDING          The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP      Forces a RCR-RP response
 *                                        The call out will called again once the response is sent. The OpStatus
 *                                        parameter will contain the transmission result
 *  \return        E_NOT_OK               The operation has failed. A concrete NRC shall be set, otherwise the DCM sends
 *                                        NRC 0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineStart_FE30(uint8 In_NVM_Subfunction, uint8 In_Prefix_Character_0, uint8 In_Prefix_Character_1, uint8 In_Prefix_Character_2, uint8 In_Prefix_Character_3, uint8 In_Suffix_Character_0, uint8 In_Suffix_Character_1, uint8 In_Suffix_Character_2, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_NVM_Subfunction, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineResults_FE30()
***********************************************************************************************************************/
/*! \brief         Reads a routine results.
 *  \details       This function is a request from DCM to the application to read a routine results.
 *  \param[in]     In_NVM_Subfunction   Fixed-length input data provided in the routine control request
 *  \param[in]     OpStatus             The operation status
 *  \param[out]    Out_RoutineInfo      Fixed-length output data to provide in the routine control response
 *  \param[out]    Out_NVM_Subfunction  Fixed-length output data to provide in the routine control response
 *  \return        E_OK                 The operation is finished
 *  \return        DCM_E_PENDING        The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP    Forces a RCR-RP response
 *                                      The call out will called again once the response is sent. The OpStatus parameter
 *                                      will contain the transmission result
 *  \return        E_NOT_OK             The operation has failed. A concrete NRC shall be set, otherwise the DCM sends
 *                                      NRC 0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineResults_FE30(uint8 In_NVM_Subfunction, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_NVM_Subfunction, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineStart_FE41()
***********************************************************************************************************************/
/*! \brief         Starts a routine execution.
 *  \details       This function is a request from DCM to the application to start a routine execution.
 *  \param[in]     OpStatus           The operation status
 *  \param[out]    Out_RoutineInfo    Fixed-length output data to provide in the routine control response
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineStart_FE41(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineStop_FE41()
***********************************************************************************************************************/
/*! \brief         Stops a routine execution.
 *  \details       This function is a request from DCM to the application to stop a routine execution.
 *  \param[in]     OpStatus           The operation status
 *  \param[out]    Out_RoutineInfo    Fixed-length output data to provide in the routine control response
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineStop_FE41(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineResults_FE41()
***********************************************************************************************************************/
/*! \brief         Reads a routine results.
 *  \details       This function is a request from DCM to the application to read a routine results.
 *  \param[in]     OpStatus           The operation status
 *  \param[out]    Out_RoutineInfo    Fixed-length output data to provide in the routine control response
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineResults_FE41(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineStart_FE42()
***********************************************************************************************************************/
/*! \brief         Starts a routine execution.
 *  \details       This function is a request from DCM to the application to start a routine execution.
 *  \param[in]     OpStatus           The operation status
 *  \param[out]    Out_RoutineInfo    Fixed-length output data to provide in the routine control response
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineStart_FE42(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineStop_FE42()
***********************************************************************************************************************/
/*! \brief         Stops a routine execution.
 *  \details       This function is a request from DCM to the application to stop a routine execution.
 *  \param[in]     OpStatus           The operation status
 *  \param[out]    Out_RoutineInfo    Fixed-length output data to provide in the routine control response
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineStop_FE42(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineResults_FE42()
***********************************************************************************************************************/
/*! \brief         Reads a routine results.
 *  \details       This function is a request from DCM to the application to read a routine results.
 *  \param[in]     OpStatus                       The operation status
 *  \param[out]    Out_RoutineInfo                Fixed-length output data to provide in the routine control response
 *  \param[out]    Out_Bitmapped_Checksum_Status  Fixed-length output data to provide in the routine control response
 *  \return        E_OK                           The operation is finished
 *  \return        DCM_E_PENDING                  The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP              Forces a RCR-RP response
 *                                                The call out will called again once the response is sent. The OpStatus
 *                                                parameter will contain the transmission result
 *  \return        E_NOT_OK                       The operation has failed. A concrete NRC shall be set, otherwise the
 *                                                DCM sends NRC 0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineResults_FE42(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_Bitmapped_Checksum_Status, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineStart_FE68()
***********************************************************************************************************************/
/*! \brief         Starts a routine execution.
 *  \details       This function is a request from DCM to the application to start a routine execution.
 *  \param[in]     In_BlockID         Fixed-length input data provided in the routine control request
 *  \param[in]     OpStatus           The operation status
 *  \param[out]    Out_RoutineInfo    Fixed-length output data to provide in the routine control response
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineStart_FE68(uint16 In_BlockID, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineResults_FE68()
***********************************************************************************************************************/
/*! \brief         Reads a routine results.
 *  \details       This function is a request from DCM to the application to read a routine results.
 *  \param[in]     OpStatus           The operation status
 *  \param[out]    Out_RoutineInfo    Fixed-length output data to provide in the routine control response
 *  \param[out]    Out_Data_Bytes     Fixed-length output data to provide in the routine control response
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineResults_FE68(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_Data_Bytes, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineStart_FF00()
***********************************************************************************************************************/
/*! \brief         Starts a routine execution.
 *  \details       This function is a request from DCM to the application to start a routine execution.
 *  \param[in]     In_RTN_FF00_START_REQ_DAT_1_Memory_Address  Fixed-length input data provided in the routine control
 *                                                             request
 *  \param[in]     In_RTN_FF00_START_REQ_DAT_2_Memory_Size     Fixed-length input data provided in the routine control
 *                                                             request
 *  \param[in]     OpStatus                                    The operation status
 *  \param[out]    Out_RoutineInfo                             Fixed-length output data to provide in the routine
 *                                                             control response
 *  \return        E_OK                                        The operation is finished
 *  \return        DCM_E_PENDING                               The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP                           Forces a RCR-RP response
 *                                                             The call out will called again once the response is sent.
 *                                                             The OpStatus parameter will contain the transmission
 *                                                             result
 *  \return        E_NOT_OK                                    The operation has failed. A concrete NRC shall be set,
 *                                                             otherwise the DCM sends NRC 0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineStart_FF00(uint32 In_RTN_FF00_START_REQ_DAT_1_Memory_Address, uint32 In_RTN_FF00_START_REQ_DAT_2_Memory_Size, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_RoutineStart_FF01()
***********************************************************************************************************************/
/*! \brief         Starts a routine execution.
 *  \details       This function is a request from DCM to the application to start a routine execution.
 *  \param[in]     In_RTN_FF01_START_REQ_DAT_1_Memory_Address  Fixed-length input data provided in the routine control
 *                                                             request
 *  \param[in]     In_RTN_FF01_START_REQ_DAT_2_Memory_Size     Fixed-length input data provided in the routine control
 *                                                             request
 *  \param[in]     OpStatus                                    The operation status
 *  \param[out]    Out_RoutineInfo                             Fixed-length output data to provide in the routine
 *                                                             control response
 *  \param[out]    Out_RTN_FF01_START_RES_DAT_1_Checksum       Fixed-length output data to provide in the routine
 *                                                             control response
 *  \return        E_OK                                        The operation is finished
 *  \return        DCM_E_PENDING                               The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP                           Forces a RCR-RP response
 *                                                             The call out will called again once the response is sent.
 *                                                             The OpStatus parameter will contain the transmission
 *                                                             result
 *  \return        E_NOT_OK                                    The operation has failed. A concrete NRC shall be set,
 *                                                             otherwise the DCM sends NRC 0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_RoutineStart_FF01(uint32 In_RTN_FF01_START_REQ_DAT_1_Memory_Address, uint32 In_RTN_FF01_START_REQ_DAT_2_Memory_Size, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Out_RoutineInfo, P2VAR(uint16, AUTOMATIC, DCM_VAR_NOINIT) Out_RTN_FF01_START_RES_DAT_1_Checksum, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  Dcm_Service10Processor()
***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     pContext           Pointer to the context
 *  \param[in]     opStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *                                    The pointers in pMsgContext points behind the SID.
 *  \param[out]    ErrorCode          Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK           Job processing finished, send positive response
 *  \return        DCM_E_PENDING      Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  (Vendor extension) Forces a RCR-RP response.
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        DCM_E_NOT_OK       Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service10Processor(Dcm_ContextPtrType pContext, Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_Service11Processor()
***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     pContext           Pointer to the context
 *  \param[in]     opStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *                                    The pointers in pMsgContext points behind the SID.
 *  \param[out]    ErrorCode          Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK           Job processing finished, send positive response
 *  \return        DCM_E_PENDING      Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  (Vendor extension) Forces a RCR-RP response.
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        DCM_E_NOT_OK       Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service11Processor(Dcm_ContextPtrType pContext, Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_Service14Processor()
***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     pContext           Pointer to the context
 *  \param[in]     opStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *                                    The pointers in pMsgContext points behind the SID.
 *  \param[out]    ErrorCode          Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK           Job processing finished, send positive response
 *  \return        DCM_E_PENDING      Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  (Vendor extension) Forces a RCR-RP response.
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        DCM_E_NOT_OK       Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service14Processor(Dcm_ContextPtrType pContext, Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_Service19Processor()
***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     pContext           Pointer to the context
 *  \param[in]     opStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *                                    The pointers in pMsgContext points behind the SID.
 *  \param[out]    ErrorCode          Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK           Job processing finished, send positive response
 *  \return        DCM_E_PENDING      Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  (Vendor extension) Forces a RCR-RP response.
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        DCM_E_NOT_OK       Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service19Processor(Dcm_ContextPtrType pContext, Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_Service22Processor()
***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     pContext           Pointer to the context
 *  \param[in]     opStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *                                    The pointers in pMsgContext points behind the SID.
 *  \param[out]    ErrorCode          Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK           Job processing finished, send positive response
 *  \return        DCM_E_PENDING      Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  (Vendor extension) Forces a RCR-RP response.
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        DCM_E_NOT_OK       Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service22Processor(Dcm_ContextPtrType pContext, Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_Service23Processor()
***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     pContext           Pointer to the context
 *  \param[in]     opStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *                                    The pointers in pMsgContext points behind the SID.
 *  \param[out]    ErrorCode          Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK           Job processing finished, send positive response
 *  \return        DCM_E_PENDING      Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  (Vendor extension) Forces a RCR-RP response.
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        DCM_E_NOT_OK       Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service23Processor(Dcm_ContextPtrType pContext, Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_Service27Processor()
***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     pContext           Pointer to the context
 *  \param[in]     opStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *                                    The pointers in pMsgContext points behind the SID.
 *  \param[out]    ErrorCode          Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK           Job processing finished, send positive response
 *  \return        DCM_E_PENDING      Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  (Vendor extension) Forces a RCR-RP response.
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        DCM_E_NOT_OK       Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service27Processor(Dcm_ContextPtrType pContext, Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_Service2EProcessor()
***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     pContext           Pointer to the context
 *  \param[in]     opStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *                                    The pointers in pMsgContext points behind the SID.
 *  \param[out]    ErrorCode          Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK           Job processing finished, send positive response
 *  \return        DCM_E_PENDING      Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  (Vendor extension) Forces a RCR-RP response.
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        DCM_E_NOT_OK       Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service2EProcessor(Dcm_ContextPtrType pContext, Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_Service2FProcessor()
***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     pContext           Pointer to the context
 *  \param[in]     opStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *                                    The pointers in pMsgContext points behind the SID.
 *  \param[out]    ErrorCode          Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK           Job processing finished, send positive response
 *  \return        DCM_E_PENDING      Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  (Vendor extension) Forces a RCR-RP response.
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        DCM_E_NOT_OK       Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service2FProcessor(Dcm_ContextPtrType pContext, Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_Service31Processor()
***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     pContext           Pointer to the context
 *  \param[in]     opStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *                                    The pointers in pMsgContext points behind the SID.
 *  \param[out]    ErrorCode          Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK           Job processing finished, send positive response
 *  \return        DCM_E_PENDING      Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  (Vendor extension) Forces a RCR-RP response.
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        DCM_E_NOT_OK       Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service31Processor(Dcm_ContextPtrType pContext, Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_Service_34_RequestDownload_cb()
***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     opStatus              The operation status
 *  \param[in,out] pMsgContext           Message-related information for one diagnostic protocol identifier
 *                                       The pointers in pMsgContext points behind the SID.
 *  \return        DCM_E_OK              Job processing finished, send positive response
 *  \return        DCM_E_PENDING         Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP     (Vendor extension) Forces a RCR-RP response.
 *                                       The call out will called again once the response is sent. The OpStatus
 *                                       parameter will contain the transmission result
 *  \return        DCM_E_PROCESSINGDONE  (Vendor extension) Can be returned instead of calling Dcm_ProcessingDone() for
 *                                       the current pMsgContext.
 *                                       Saves application code and stack usage.
 *  \return        DCM_E_STOP_REPEATER   Stops the repeater proxy
 *  \return        DCM_E_NOT_OK          Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service_34_RequestDownload_cb(Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext);
/***********************************************************************************************************************
 *  Dcm_Service_36_TransferData_cb()
***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     opStatus              The operation status
 *  \param[in,out] pMsgContext           Message-related information for one diagnostic protocol identifier
 *                                       The pointers in pMsgContext points behind the SID.
 *  \return        DCM_E_OK              Job processing finished, send positive response
 *  \return        DCM_E_PENDING         Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP     (Vendor extension) Forces a RCR-RP response.
 *                                       The call out will called again once the response is sent. The OpStatus
 *                                       parameter will contain the transmission result
 *  \return        DCM_E_PROCESSINGDONE  (Vendor extension) Can be returned instead of calling Dcm_ProcessingDone() for
 *                                       the current pMsgContext.
 *                                       Saves application code and stack usage.
 *  \return        DCM_E_STOP_REPEATER   Stops the repeater proxy
 *  \return        DCM_E_NOT_OK          Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service_36_TransferData_cb(Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext);
/***********************************************************************************************************************
 *  Dcm_Service_37_RequestTransferExit_cb()
***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     opStatus              The operation status
 *  \param[in,out] pMsgContext           Message-related information for one diagnostic protocol identifier
 *                                       The pointers in pMsgContext points behind the SID.
 *  \return        DCM_E_OK              Job processing finished, send positive response
 *  \return        DCM_E_PENDING         Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP     (Vendor extension) Forces a RCR-RP response.
 *                                       The call out will called again once the response is sent. The OpStatus
 *                                       parameter will contain the transmission result
 *  \return        DCM_E_PROCESSINGDONE  (Vendor extension) Can be returned instead of calling Dcm_ProcessingDone() for
 *                                       the current pMsgContext.
 *                                       Saves application code and stack usage.
 *  \return        DCM_E_STOP_REPEATER   Stops the repeater proxy
 *  \return        DCM_E_NOT_OK          Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service_37_RequestTransferExit_cb(Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext);
/***********************************************************************************************************************
 *  Dcm_Service3EProcessor()
***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     pContext           Pointer to the context
 *  \param[in]     opStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *                                    The pointers in pMsgContext points behind the SID.
 *  \param[out]    ErrorCode          Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK           Job processing finished, send positive response
 *  \return        DCM_E_PENDING      Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  (Vendor extension) Forces a RCR-RP response.
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        DCM_E_NOT_OK       Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service3EProcessor(Dcm_ContextPtrType pContext, Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_Service85Processor()
***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     pContext           Pointer to the context
 *  \param[in]     opStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *                                    The pointers in pMsgContext points behind the SID.
 *  \param[out]    ErrorCode          Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK           Job processing finished, send positive response
 *  \return        DCM_E_PENDING      Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  (Vendor extension) Forces a RCR-RP response.
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        DCM_E_NOT_OK       Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service85Processor(Dcm_ContextPtrType pContext, Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_Service10PostProcessor()
***********************************************************************************************************************/
/*! \brief         Finalizes the service processing.
 *  \details       Triggers a mode switch, performs a state transition or executes other actions depending on the
 *                 concrete diagnostic service.
 *  \param[in]     pContext  Pointer to the context
 *  \param[in]     status    The post-processing status
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(void, DCM_CALLOUT_CODE) Dcm_Service10PostProcessor(Dcm_ContextPtrType pContext, Dcm_ConfirmationStatusType status);
/***********************************************************************************************************************
 *  Dcm_Service10FastPostProcessor()
***********************************************************************************************************************/
/*! \brief         Finalizes the service processing.
 *  \details       Processes time critical diagnostic service specific operations immediately after confirmation of
 *                 service processing.
 *  \param[in]     pContext  Pointer to the context
 *  \param[in]     status    The post-processing status
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(void, DCM_CALLOUT_CODE) Dcm_Service10FastPostProcessor(Dcm_ContextPtrType pContext, Dcm_ConfirmationStatusType status);
/***********************************************************************************************************************
 *  Dcm_Service11PostProcessor()
***********************************************************************************************************************/
/*! \brief         Finalizes the service processing.
 *  \details       Triggers a mode switch, performs a state transition or executes other actions depending on the
 *                 concrete diagnostic service.
 *  \param[in]     pContext  Pointer to the context
 *  \param[in]     status    The post-processing status
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(void, DCM_CALLOUT_CODE) Dcm_Service11PostProcessor(Dcm_ContextPtrType pContext, Dcm_ConfirmationStatusType status);
/***********************************************************************************************************************
 *  Dcm_Service11FastPostProcessor()
***********************************************************************************************************************/
/*! \brief         Finalizes the service processing.
 *  \details       Processes time critical diagnostic service specific operations immediately after confirmation of
 *                 service processing.
 *  \param[in]     pContext  Pointer to the context
 *  \param[in]     status    The post-processing status
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(void, DCM_CALLOUT_CODE) Dcm_Service11FastPostProcessor(Dcm_ContextPtrType pContext, Dcm_ConfirmationStatusType status);
/***********************************************************************************************************************
 *  Dcm_Service19PostProcessor()
***********************************************************************************************************************/
/*! \brief         Finalizes the service processing.
 *  \details       Triggers a mode switch, performs a state transition or executes other actions depending on the
 *                 concrete diagnostic service.
 *  \param[in]     pContext  Pointer to the context
 *  \param[in]     status    The post-processing status
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(void, DCM_CALLOUT_CODE) Dcm_Service19PostProcessor(Dcm_ContextPtrType pContext, Dcm_ConfirmationStatusType status);
/***********************************************************************************************************************
 *  Dcm_Service27PostProcessor()
***********************************************************************************************************************/
/*! \brief         Finalizes the service processing.
 *  \details       Triggers a mode switch, performs a state transition or executes other actions depending on the
 *                 concrete diagnostic service.
 *  \param[in]     pContext  Pointer to the context
 *  \param[in]     status    The post-processing status
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(void, DCM_CALLOUT_CODE) Dcm_Service27PostProcessor(Dcm_ContextPtrType pContext, Dcm_ConfirmationStatusType status);
/***********************************************************************************************************************
 *  Dcm_Service2FPostProcessor()
***********************************************************************************************************************/
/*! \brief         Finalizes the service processing.
 *  \details       Triggers a mode switch, performs a state transition or executes other actions depending on the
 *                 concrete diagnostic service.
 *  \param[in]     pContext  Pointer to the context
 *  \param[in]     status    The post-processing status
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(void, DCM_CALLOUT_CODE) Dcm_Service2FPostProcessor(Dcm_ContextPtrType pContext, Dcm_ConfirmationStatusType status);
/***********************************************************************************************************************
 *  Dcm_Service85PostProcessor()
***********************************************************************************************************************/
/*! \brief         Finalizes the service processing.
 *  \details       Triggers a mode switch, performs a state transition or executes other actions depending on the
 *                 concrete diagnostic service.
 *  \param[in]     pContext  Pointer to the context
 *  \param[in]     status    The post-processing status
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(void, DCM_CALLOUT_CODE) Dcm_Service85PostProcessor(Dcm_ContextPtrType pContext, Dcm_ConfirmationStatusType status);
/***********************************************************************************************************************
 *  DcmExt_Services_SessionIndication()
***********************************************************************************************************************/
/*! \brief         Performs manufacturer specific validations on a diagnostic service request.
 *  \details       This function is a request from the DCM to the application to validate the received diagnostic
 *                 service, additionally to the DCM internal validation.
 *  \param[in]     SID                         Contains the diagnostic service Id
 *  \param[in]     RequestData                 Points to the request data. Points behind the service Id byte
 *  \param[in]     DataSize                    Specifies the requested data length (without the SID byte)
 *  \param[in]     ReqType                     Specifies the diagnostic request type:
 *                                             0 - physical request
 *                                             1 - functional request
 *  \param[in]     SourceAddress               Contains the diagnostic client source address
 *  \param[out]    ErrorCode                   NRC to be sent in the negative response in case of failure (E_NOT_OK)
 *  \return        E_OK                        The operation is finished
 *  \return        DCM_E_REQUEST_NOT_ACCEPTED  The diagnostic service shall not be processed.
 *                                             No response will be sent
 *  \return        E_NOT_OK                    The operation has failed
 *                                             A concrete NRC shall be set, otherwise the DCM sends NRC 0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_SessionIndication(uint8 SID, P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_SessionConfirmation()
***********************************************************************************************************************/
/*! \brief         Finishes manufacturer specific actions on a diagnostic service request.
 *  \details       This function is a notification from the DCM to the application that a diagnostic service processing
 *                 is finished.
 *  \param[in]     SID                 Contains the diagnostic service Id
 *  \param[in]     ReqType             Specifies the diagnostic request type:
 *                                     0 - physical request
 *                                     1 - functional request
 *  \param[in]     SourceAddress       Contains the diagnostic client source address
 *  \param[in]     ConfirmationStatus  Contains the response transmission resp. diagnostic response type
 *  \return        E_OK                The operation is finished
 *  \return        E_NOT_OK            The operation has failed. Has no effect on DCM.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_SessionConfirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus);
/***********************************************************************************************************************
 *  Dcm_RepeaterDeadEnd()
***********************************************************************************************************************/
/*! \brief         Dummy repeater proxy.
 *  \details       -
 *  \param[in]     pContext             Pointer to the context
 *  \param[in]     opStatus             The operation status
 *  \param[in,out] pMsgContext          Message-related information for one diagnostic protocol identifier
 *  \param[out]    ErrorCode            Negative response code
 *  \return        DCM_E_STOP_REPEATER  Stops the repeater proxy
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RepeaterDeadEnd(Dcm_ContextPtrType pContext, Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_Services_CS_HardReset()
***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic sub-service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic sub-service, configured to be
 *                 handled by a CDD, is received. All of the relevant diagnostic request parameter information is
 *                 forwarded by DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSubService/DcmDsdSubServiceFnc.
 *  \param[in]     opStatus              The operation status
 *  \param[in,out] pMsgContext           Message-related information for one diagnostic protocol identifier
 *                                       The pointers in pMsgContext points behind the sub-function.
 *  \return        DCM_E_OK              Job processing finished, send positive response
 *  \return        DCM_E_PENDING         Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP     (Vendor extension) Forces a RCR-RP response.
 *                                       The call out will called again once the response is sent. The OpStatus
 *                                       parameter will contain the transmission result
 *  \return        DCM_E_PROCESSINGDONE  (Vendor extension) Can be returned instead of calling Dcm_ProcessingDone() for
 *                                       the current pMsgContext.
 *                                       Saves application code and stack usage.
 *  \return        DCM_E_STOP_REPEATER   Stops the repeater proxy
 *  \return        DCM_E_NOT_OK          Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_Services_CS_HardReset(Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext);
/***********************************************************************************************************************
 *  Dcm_Service19_01Processor()
***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic sub-service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic sub-service, configured to be
 *                 handled by a CDD, is received. All of the relevant diagnostic request parameter information is
 *                 forwarded by DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSubService/DcmDsdSubServiceFnc.
 *  \param[in]     pContext             Pointer to the context
 *  \param[in]     opStatus             The operation status
 *  \param[in,out] pMsgContext          Message-related information for one diagnostic protocol identifier
 *                                      The pointers in pMsgContext points behind the sub-function.
 *  \param[out]    ErrorCode            Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK             Job processing finished, send positive response
 *  \return        DCM_E_PENDING        Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP    (Vendor extension) Forces a RCR-RP response.
 *                                      The call out will called again once the response is sent. The OpStatus parameter
 *                                      will contain the transmission result
 *  \return        DCM_E_STOP_REPEATER  Stops the repeater proxy
 *  \return        DCM_E_NOT_OK         Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service19_01Processor(Dcm_ContextPtrType pContext, Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_Service19_02Processor()
***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic sub-service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic sub-service, configured to be
 *                 handled by a CDD, is received. All of the relevant diagnostic request parameter information is
 *                 forwarded by DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSubService/DcmDsdSubServiceFnc.
 *  \param[in]     pContext             Pointer to the context
 *  \param[in]     opStatus             The operation status
 *  \param[in,out] pMsgContext          Message-related information for one diagnostic protocol identifier
 *                                      The pointers in pMsgContext points behind the sub-function.
 *  \param[out]    ErrorCode            Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK             Job processing finished, send positive response
 *  \return        DCM_E_PENDING        Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP    (Vendor extension) Forces a RCR-RP response.
 *                                      The call out will called again once the response is sent. The OpStatus parameter
 *                                      will contain the transmission result
 *  \return        DCM_E_STOP_REPEATER  Stops the repeater proxy
 *  \return        DCM_E_NOT_OK         Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service19_02Processor(Dcm_ContextPtrType pContext, Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_Service19_06Processor()
***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic sub-service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic sub-service, configured to be
 *                 handled by a CDD, is received. All of the relevant diagnostic request parameter information is
 *                 forwarded by DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSubService/DcmDsdSubServiceFnc.
 *  \param[in]     pContext             Pointer to the context
 *  \param[in]     opStatus             The operation status
 *  \param[in,out] pMsgContext          Message-related information for one diagnostic protocol identifier
 *                                      The pointers in pMsgContext points behind the sub-function.
 *  \param[out]    ErrorCode            Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK             Job processing finished, send positive response
 *  \return        DCM_E_PENDING        Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP    (Vendor extension) Forces a RCR-RP response.
 *                                      The call out will called again once the response is sent. The OpStatus parameter
 *                                      will contain the transmission result
 *  \return        DCM_E_STOP_REPEATER  Stops the repeater proxy
 *  \return        DCM_E_NOT_OK         Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service19_06Processor(Dcm_ContextPtrType pContext, Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_Service19_0AProcessor()
***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic sub-service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic sub-service, configured to be
 *                 handled by a CDD, is received. All of the relevant diagnostic request parameter information is
 *                 forwarded by DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSubService/DcmDsdSubServiceFnc.
 *  \param[in]     pContext             Pointer to the context
 *  \param[in]     opStatus             The operation status
 *  \param[in,out] pMsgContext          Message-related information for one diagnostic protocol identifier
 *                                      The pointers in pMsgContext points behind the sub-function.
 *  \param[out]    ErrorCode            Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK             Job processing finished, send positive response
 *  \return        DCM_E_PENDING        Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP    (Vendor extension) Forces a RCR-RP response.
 *                                      The call out will called again once the response is sent. The OpStatus parameter
 *                                      will contain the transmission result
 *  \return        DCM_E_STOP_REPEATER  Stops the repeater proxy
 *  \return        DCM_E_NOT_OK         Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service19_0AProcessor(Dcm_ContextPtrType pContext, Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_services_L1_UnLocked_GetSeed()
***********************************************************************************************************************/
/*! \brief         Gets seed.
 *  \details       This function is a request from the DCM to the application to provide a security level specific seed.
 *                 The concrete name of the callout is defined by the configuration parameter
 *                 /DcmDsp/DcmDspSecurity/DcmDspSecurityRow/DcmDspSecurityGetSeedFnc.
 *  \param[in]     opStatus       The operation status
 *  \param[out]    Seed           Seed data
 *  \param[out]    ErrorCode      Negative response code
 *  \return        E_OK           The operation is finished
 *  \return        E_NOT_OK       The operation has failed
 *  \return        DCM_E_PENDING  The operation is not yet finished
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_services_L1_UnLocked_GetSeed(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_services_L1_UnLockedCompare_Key()
***********************************************************************************************************************/
/*! \brief         Compares key.
 *  \details       This function is a request from the DCM to the application to verify the requested security access
 *                 level specific key. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspSecurity/DcmDspSecurityRow/DcmDspSecurityCompareKeyFnc.
 *  \param[in]     Key                       Key data
 *  \param[in]     opStatus                  The operation status
 *  \param[out]    ErrorCode                 Negative response code
 *  \return        E_OK                      The operation is finished
 *  \return        E_NOT_OK                  The operation has failed
 *  \return        DCM_E_PENDING             The operation is not yet finished
 *  \return        DCM_E_COMPARE_KEY_FAILED  The received key is not valid
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_services_L1_UnLockedCompare_Key(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_services_L3_unLocked_GetSeed()
***********************************************************************************************************************/
/*! \brief         Gets seed.
 *  \details       This function is a request from the DCM to the application to provide a security level specific seed.
 *                 The concrete name of the callout is defined by the configuration parameter
 *                 /DcmDsp/DcmDspSecurity/DcmDspSecurityRow/DcmDspSecurityGetSeedFnc.
 *  \param[in]     opStatus       The operation status
 *  \param[out]    Seed           Seed data
 *  \param[out]    ErrorCode      Negative response code
 *  \return        E_OK           The operation is finished
 *  \return        E_NOT_OK       The operation has failed
 *  \return        DCM_E_PENDING  The operation is not yet finished
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_services_L3_unLocked_GetSeed(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_services_L3_unLockedCompare_Key()
***********************************************************************************************************************/
/*! \brief         Compares key.
 *  \details       This function is a request from the DCM to the application to verify the requested security access
 *                 level specific key. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspSecurity/DcmDspSecurityRow/DcmDspSecurityCompareKeyFnc.
 *  \param[in]     Key                       Key data
 *  \param[in]     opStatus                  The operation status
 *  \param[out]    ErrorCode                 Negative response code
 *  \return        E_OK                      The operation is finished
 *  \return        E_NOT_OK                  The operation has failed
 *  \return        DCM_E_PENDING             The operation is not yet finished
 *  \return        DCM_E_COMPARE_KEY_FAILED  The received key is not valid
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_services_L3_unLockedCompare_Key(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_services_L61_GetSeed()
***********************************************************************************************************************/
/*! \brief         Gets seed.
 *  \details       This function is a request from the DCM to the application to provide a security level specific seed.
 *                 The concrete name of the callout is defined by the configuration parameter
 *                 /DcmDsp/DcmDspSecurity/DcmDspSecurityRow/DcmDspSecurityGetSeedFnc.
 *  \param[in]     opStatus       The operation status
 *  \param[out]    Seed           Seed data
 *  \param[out]    ErrorCode      Negative response code
 *  \return        E_OK           The operation is finished
 *  \return        E_NOT_OK       The operation has failed
 *  \return        DCM_E_PENDING  The operation is not yet finished
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_services_L61_GetSeed(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
/***********************************************************************************************************************
 *  DcmExt_services_L61_Compare_Key()
***********************************************************************************************************************/
/*! \brief         Compares key.
 *  \details       This function is a request from the DCM to the application to verify the requested security access
 *                 level specific key. The concrete name of the callout is defined by the configuration parameter
 *                 /Dcm/DcmConfigSet/DcmDsp/DcmDspSecurity/DcmDspSecurityRow/DcmDspSecurityCompareKeyFnc.
 *  \param[in]     Key                       Key data
 *  \param[in]     opStatus                  The operation status
 *  \param[out]    ErrorCode                 Negative response code
 *  \return        E_OK                      The operation is finished
 *  \return        E_NOT_OK                  The operation has failed
 *  \return        DCM_E_PENDING             The operation is not yet finished
 *  \return        DCM_E_COMPARE_KEY_FAILED  The received key is not valid
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmExt_services_L61_Compare_Key(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
# define DCM_STOP_SEC_CALLOUT_CODE
/*lint -save -esym(961, 19.1) */
# include "MemMap.h"                                                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*lint -restore */
/* ----------------------------------------------
 ~&&&   ROM 8-Bit
---------------------------------------------- */
# define DCM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
# include "MemMap.h"                                                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*lint -restore */
/*! TxPduId to DCM connection map */
extern CONST(Dcm_NetConnRefMemType, DCM_CONST) Dcm_CfgNetTxPduInfo[1];
/*! Map of DCM relevant network handles */
extern CONST(Dcm_CfgNetNetIdRefMemType, DCM_CONST) Dcm_CfgNetConnComMChannelMap[1];
/*! Security Fixed Byte values */
extern CONST(uint8, DCM_CONST) Dcm_CfgStateSecurityFixedBytes[36];
/*! Look up table of all supported ALFIDs */
extern CONST(uint8, DCM_CONST) Dcm_CfgMemMgrAlfidLookUpTable[3];
/*! Look up table of DCM service identifiers */
extern CONST(uint8, DCM_CONST) Dcm_CfgDiagSvcIdLookUpTable[16];
/*! Service 0x10 look up table  */
extern CONST(uint8, DCM_CONST) Dcm_CfgSvc10SubFuncLookUpTable[6];
/*! Service 0x11 look up table  */
extern CONST(uint8, DCM_CONST) Dcm_CfgSvc11SubFuncLookUpTable[2];
/*! Service 0x19 look up table  */
extern CONST(uint8, DCM_CONST) Dcm_CfgSvc19SubFuncLookUpTable[5];
/*! Service 0x27 look up table  */
extern CONST(uint8, DCM_CONST) Dcm_CfgSvc27SubFuncLookUpTable[7];
/*! Service 0x3E look up table  */
extern CONST(uint8, DCM_CONST) Dcm_CfgSvc3ESubFuncLookUpTable[2];
/*! Look up table of service 0x85 */
extern CONST(uint8, DCM_CONST) Dcm_CfgSvc85SubFuncLookUpTable[3];
# define DCM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
# include "MemMap.h"                                                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*lint -restore */
/* ----------------------------------------------
 ~&&&   ROM 16-Bit
---------------------------------------------- */
# define DCM_START_SEC_CONST_16
/*lint -save -esym(961, 19.1) */
# include "MemMap.h"                                                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*lint -restore */
/*! DID look up table  */
extern CONST(uint16, DCM_CONST) Dcm_CfgDidMgrDidLookUpTable[180];
/*! RID look up table  */
extern CONST(uint16, DCM_CONST) Dcm_CfgRidMgrRidLookUpTable[20];
# define DCM_STOP_SEC_CONST_16
/*lint -save -esym(961, 19.1) */
# include "MemMap.h"                                                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*lint -restore */
/* ----------------------------------------------
 ~&&&   ROM of unspecified size
---------------------------------------------- */
# define DCM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
# include "MemMap.h"                                                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*lint -restore */
/*! DCM buffer descriptor */
extern CONST(Dcm_CfgNetBufferInfoType, DCM_CONST) Dcm_CfgNetBufferInfo[1];
/*! RxPduId map */
extern CONST(Dcm_CfgNetRxPduInfoType, DCM_CONST) Dcm_CfgNetRxPduInfo[2];
/*! DCM connection descriptor */
extern CONST(Dcm_CfgNetConnectionInfoType, DCM_CONST) Dcm_CfgNetConnectionInfo[1];
/*! DCM protocol descriptor */
extern CONST(Dcm_CfgNetProtocolInfoType, DCM_CONST) Dcm_CfgNetProtocolInfo[1];
/*! Map of all relevant for DCM network handles */
extern CONST(NetworkHandleType, DCM_CONST) Dcm_CfgNetAllComMChannelMap[1];
/*! Look up table of DCM relevant network handles */
extern CONST(NetworkHandleType, DCM_CONST) Dcm_CfgNetNetworkHandleLookUpTable[2];
/*! Diagnostic service execution conditions */
extern CONST(Dcm_CfgStatePreconditionInfoType, DCM_CONST) Dcm_CfgStatePreconditions[15];
/*! Session state properties */
extern CONST(Dcm_CfgStateSessionInfoType, DCM_CONST) Dcm_CfgStateSessionInfo[5];
/*! Security Access state properties */
extern CONST(Dcm_CfgStateSecurityInfoType, DCM_CONST) Dcm_CfgStateSecurityInfo[3];
/*! Security level specific end index into Dcm_CfgStateSecurityFixedBytes[] (last +1) */
extern CONST(Dcm_CfgStateSecurityFixedByteRefMemType, DCM_CONST) Dcm_CfgStateSecurityFixedByteInfo[4];
/*! Session state change notification(s) */
extern CONST(Dcm_CfgStateNotificationInfoType, DCM_CONST) Dcm_CfgStateSessionNotificationInfo[2];
/*! DID properties */
extern CONST(Dcm_CfgDidMgrDidInfoType, DCM_CONST) Dcm_CfgDidMgrDidInfo[179];
/*! DID operation properties */
extern CONST(Dcm_CfgDidMgrDidOpInfoType, DCM_CONST) Dcm_CfgDidMgrDidOpInfo[273];
/*! DID operation classes */
extern CONST(Dcm_CfgDidMgrDidOpClassInfoType, DCM_CONST) Dcm_CfgDidMgrDidOpClassInfo[455];
/*! DID signal operation classes */
extern CONST(Dcm_CfgDidMgrSignalOpClassInfoType, DCM_CONST) Dcm_CfgDidMgrSignalOpClassInfo[456];
/*! IO control DID operation properties */
extern CONST(Dcm_CfgDidMgrOpInfoIoControlType, DCM_CONST) Dcm_CfgDidMgrOpInfoIoControl[17];
/*! RID properties */
extern CONST(Dcm_CfgRidMgrRidInfoType, DCM_CONST) Dcm_CfgRidMgrRidInfo[19];
/*! RID operation properties */
extern CONST(Dcm_CfgRidMgrOpInfoType, DCM_CONST) Dcm_CfgRidMgrOpInfo[31];
/*! Properties of the MIDs */
extern CONST(Dcm_CfgMemMgrMemIdInfoType, DCM_CONST) Dcm_CfgMemMgrMidInfo[1];
/*! Properties of the memory map of a specific MID */
extern CONST(Dcm_CfgMemMgrMemMapInfoType, DCM_CONST) Dcm_CfgMemMgrMemMap[3];
/*! DCM service initializers */
extern CONST(Dcm_DiagSvcInitFuncType, DCM_CONST) Dcm_CfgDiagSvcInitializers[3];
/*! DCM service properties */
extern CONST(Dcm_CfgDiagServiceInfoType, DCM_CONST) Dcm_CfgDiagServiceInfo[16];
/*! Indirection from diag service info to execution pre conditions */
extern CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgDiagSvcIdExecPrecondTable[15];
/*! DCM service post processors */
extern CONST(Dcm_DiagSvcConfirmationFuncType, DCM_CONST) Dcm_CfgDiagSvcPostProcessors[9];
/*! OEM notification functions */
extern CONST(Dcm_CfgDiagNotificationInfoType, DCM_CONST) Dcm_CfgDiagOemNotificationInfo[2];
/*! Service 0x10 sub-service properties table  */
extern CONST(Dcm_CfgSvc10SubFuncInfoType, DCM_CONST) Dcm_CfgSvc10SubFuncInfo[5];
/*! Indirection from service 0x10 sub functions to execution pre conditions */
extern CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc10SubFuncExecPrecondTable[5];
/*! Service 0x11 sub-service properties table  */
extern CONST(Dcm_CfgSvc11SubFuncInfoType, DCM_CONST) Dcm_CfgSvc11SubFuncInfo[1];
/*! Indirection from service 0x11 sub functions to execution pre conditions */
extern CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc11SubFuncExecPrecondTable[1];
/*! Service 0x19 sub-service properties table  */
extern CONST(Dcm_CfgSvc19SubFuncInfoType, DCM_CONST) Dcm_CfgSvc19SubFuncInfo[4];
/*! Indirection from service 0x19 sub functions to execution pre conditions */
extern CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc19SubFuncExecPrecondTable[4];
/*! Service 0x27 sub-service properties table  */
extern CONST(Dcm_CfgSvc27SubFuncInfoType, DCM_CONST) Dcm_CfgSvc27SubFuncInfo[6];
/*! Service 0x27 security level properties table  */
extern CONST(Dcm_CfgSvc27SecLevelInfoType, DCM_CONST) Dcm_CfgSvc27SecLevelInfo[3];
/*! Indirection from service 0x27 sub functions to execution pre conditions */
extern CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc27SubFuncExecPrecondTable[6];
/*! Indirection from service 0x3E sub functions to execution pre conditions */
extern CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc3ESubFuncExecPrecondTable[1];
/*! Indirection from service 0x85 sub functions to execution pre conditions */
extern CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc85SubFuncExecPrecondTable[2];
/*! DCM service 0x85 properties */
extern CONST(Dcm_CfgSvc85SubFuncInfoType, DCM_CONST) Dcm_CfgSvc85SubFuncInfo[2];
# define DCM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
# include "MemMap.h"                                                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*lint -restore */
#endif /* !defined(DCM_LCFG_H) */
/* ********************************************************************************************************************
 * END OF FILE: Dcm_Lcfg.h
 * ******************************************************************************************************************** */

