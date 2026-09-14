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
*    @file IpduM_Cfg.h
*    @ingroup IpduMConfiguration
*    @brief This is IpduM Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the IpduM module.
*    @defgroup IpduMConfiguration
*    @brief This contains the configuration files for the IpduM module.
********************************************************************************************************************/
#ifndef IPDUM_CFG_H
#define IPDUM_CFG_H

/*******************************************************************************************************************
*  Include Files                                                                                                   *
*******************************************************************************************************************/
#include "ComStack_Types.h"
/*******************************************************************************************************************/
/*  Version Information                                                                                            */
/*******************************************************************************************************************/
/* Software Version */
#define IPDUM_CFG_SW_MAJOR_VERSION                               0u
#define IPDUM_CFG_SW_MINOR_VERSION                               0u
#define IPDUM_CFG_SW_PATCH_VERSION                               1u
/* Autosar Release */
#define IPDUM_CFG_AR_RELEASE_MAJOR_VERSION                       4u
#define IPDUM_CFG_AR_RELEASE_MINOR_VERSION                       3u
#define IPDUM_CFG_AR_RELEASE_REVISION_VERSION                    1u
/*******************************************************************************************************************
*  Macros Definitions                                                                                              *
********************************************************************************************************************/
/*! @brief The cycle time with which IpduM_MainFunction should be invoked (in milli seconds). */
#define IPDUM_MAIN_FUNCTION_PERIOD      10U
/*! @brief Switches the Default Error Tracer (Det) detection and notification ON or OFF.*/
#define IPDUM_DEV_ERROR_DETECT          STD_ON
/*! @brief This parameter defines the ByteOrder of the headers inside a Container I-PDU shall be ordered big endian. */
#define IPDUM_BIG_ENDIAN                0U
/*! @brief This parameter defines the ByteOrder of the headers inside a Container I-PDU shall be ordered little endian*/
#define IPDUM_LITTLE_ENDIAN             1U
/*! @brief This parameter defines the ByteOrder of the headers inside a Container I-PDU. */
#define IPDUM_HEADER_BYTE_ORDER         IPDUM_LITTLE_ENDIAN
/*! @brief This parameter allow optimizations in the case the IpduM will never be used with a static part. */
#define IPDUM_STATIC_PART_EXISTS        STD_ON
/*! @brief Active/Deactivate the version information API. */
#define IPDUM_VERSION_INFO_API          STD_ON


/* Multiplex Tx Pdu Id IPDUM->PDUR->CANIF*/
#define IPDUM_PDU_VIN_01                    0U
#define IPDUM_PDU_SERVICE_KEY_01            1U
#define IPDUM_PDU_MDK_ZV_REQ                2U
#define IPDUM_NUM_OF_TX_MESSAGE             3U
#define IPDUM_MAX_BYTES_IN_PDU              8U
#define IPDUM_TX_BUFFER_SIZE               24U

/* Multiplex parts ID COM->PDUR->IPDUM*/
#define IPDUM_PDU_VIN_01_M0                 0U
#define IPDUM_PDU_VIN_01_M1                 1U
#define IPDUM_PDU_VIN_01_M2                 2U
#define IPDUM_PDU_SERVICE_KEY_01_M0         3U
#define IPDUM_PDU_SERVICE_KEY_01_M1         4U
#define IPDUM_PDU_SERVICE_KEY_01_M2         5U
#define IPDUM_PDU_SERVICE_KEY_01_M3         6U
#define IPDUM_PDU_SERVICE_KEY_01_M4         7U
#define IPDUM_PDU_SERVICE_KEY_01_M5         8U
#define IPDUM_PDU_SERVICE_KEY_01_M6         9U
#define IPDUM_PDU_SERVICE_KEY_01_M7        10U
#define IPDUM_PDU_SERVICE_KEY_01_M8        11U
#define IPDUM_PDU_SERVICE_KEY_01_M9        12U
#define IPDUM_PDU_MDK_ZV_REQ_M0            13U
#define IPDUM_PDU_MDK_ZV_REQ_M1            14U
#define IPDUM_PDU_MDK_ZV_REQ_M2            15U
#define IPDUM_PDU_MDK_ZV_REQ_M3            16U
#define IPDUM_PDU_MDK_ZV_REQ_M4            17U
#define IPDUM_PDU_MDK_ZV_REQ_M5            18U
#define IPDUM_PDU_MDK_ZV_REQ_STATIC        19U
#define IPDUM_PDU_TX_NUM_OF_PARTS          20U

#define IPDUM_NUM_OF_TX_SEGMENTS           78U

#define IPDUM_PDU_MDK_ZV_RESP               0U
#define IPDUM_PDU_PSD_06                    1U
#define IPDUM_PDU_MOTOR_09                  2U
#define IPDUM_PDU_MOTOR_GAS_01              3U
#define IPDUM_RX_NUM_OF_MSG                 4U
#define IPDUM_NUM_OF_RX_DYNAMIC_PARTS       9U
#define IPDUM_NUM_OF_RX_MESSAGE             4U
#define IPDUM_RX_BUFFER_SIZE               32U
#define IPDUM_MAX_CONTAINER_BUFFER         64U
#define IPDUM_MAX_CONTAINER_QUEUE_SIZE      3U

#define PDUR_PDU_TX_MUX_MSG1                1U


/*! @brief  This type contains the implementation-specific post build configuration structure .
    Dummy config is used as post build not supported.*/
typedef struct
{
    uint8 Dummy;
}IpduM_ConfigType;

/*! @brief Defines the ByteOrder for all segments (static and dynamic part) and for the selectorField within
the MultiplexedPdu .IPDUM_BIG_ENDIAN -> 0 and IPDUM_LITTLE_ENDIAN -> 1
*/
typedef uint8 IpduM_ByteOrderType;

/*! @brief Writing the I-PDU representing the dynamic part does trigger a sending of the I-PDU. */
#define IPDUM_TX_TRIGGER_MODE_DYNAMIC_PART_TRIGGER              0U
/*! @brief Writing the I-PDU representing the static or the dynamic part does trigger a sending of the I-PDU. */
#define IPDUM_TX_TRIGGER_MODE_STATIC_OR_DYNAMIC_PART_TRIGGER    1U
/*! @brief Writing the I-PDU representing the static part does trigger a sending of the I-PDU. */
#define IPDUM_TX_TRIGGER_MODE_STATIC_PART_TRIGGER               2U
/*! @brief Only the buffer in the IpduM are written but not send is triggered, used for IpduM I-PDUs which are
    requested by TriggerTransmit. */
#define IPDUM_TX_TRIGGER_MODE_NONE                              3U
/*! @brief Selects whether to send the multiplexed I-PDU immediately or later. */
typedef uint8 IpduM_TxTriggerModeType;

/*! @brief Defines the Bit and Byte position configuration type for the Tx segments */
typedef struct
{
    uint8   SegmentMsByteIdx;   /*! MS byte Index of the segment */
    uint8   SegmentMsBitIdx;    /*! MS bit Index of the segment  */
    uint8   SegmentLsByteIdx;   /*! LS byte Index of the segment */
    uint8   SegmentLsBitIdx;    /*! LS bit Index of the segment  */
    uint8   SegmentBitLength;   /*! Bit length of the segment    */
    uint8   SegmentByteLength;  /*! Byte length of the segment   */
}IpduM_TxSegmentConfigType;

/*! @brief Defines the IpduM Tx buffer configuration type*/
typedef struct
{
    uint32          BufferStartIdx; /*! Start byte index of the IpduM Tx Buffer */
    uint32          BufferEndIdx;   /*! End   byte index of the IpduM Tx Buffer */
    uint32          BufferSize;     /*! Buffer Size the IpduM Tx Buffer */
}IpduM_BufferConfigType;

/*! @brief Defines the data type for the number of IpduM Tx segments */
typedef uint8 IpduM_TxSegmentIdxType;

/*! @brief Defines the Tx part type as Static */
#define IPDUM_PART_TYPE_STATIC      0U
/*! @brief Defines the Tx part type as Dynamic */
#define IPDUM_PART_TYPE_DYNAMIC     1U
/*! @brief Defines the datatype for the Tx Part */
typedef uint8 IpduM_PartType;

/*! @brief Defines the IpduM Tx part configuration type */
typedef struct
{
    boolean                IsJitUpdateSupported;     /*! enables/disables the Just in time update */
    boolean                IsTxConfirmationEnabled;  /*! enables/disables the Just in transmit confirmation */
    IpduM_PartType         PartType;                 /*! describe the part type */
    IpduM_TxSegmentIdxType SegmentStartIdx;          /*! start index of the segment configuration belongs to this Part*/
    IpduM_TxSegmentIdxType SegmentEndIdx;            /*! end index of the segment configuration belongs to this Part */
    PduIdType              TxIpduId;                 /*! IpduM Pdu Id to which this part belongs to */
    PduIdType              TxUpperConfirmationPduId; /*! Uppder layer confirmation pdu id for this part */
}IpduM_TxPartConfigType;

/*! @brief Defines the IpduM Tx configuration type */
typedef struct
{
    uint32                  TxConfirmationTimeout; /*! Timeout value in millisecond for confirmation wait */
    PduIdType               TxLowerPduId;          /*! Lower layer transmit pdu id */
    IpduM_ByteOrderType     ByteOrder;             /*! ByteOrder for all segments & selectorField  */
    IpduM_TxTriggerModeType TxTriggerMode;         /*! Selects transmit mode of multiplexed I-PDU */
#if(IPDUM_STATIC_PART_EXISTS == STD_ON)
    boolean                 IsStaticPartExist;     /*! enables/disable the static part support */
    PduIdType               StaticPartPduRef;      /*! static part pdu id index in IpduM_TxPduMapConfig */
#endif
}IpduM_TxPduConfigType;

/*! @brief Defines the data type for the number for Rx dynamic part */
typedef uint8 IpduM_RxDynPartIdxType;

/*! @brief Defines the type for the Rx pdu dynamic part configuraiton */
typedef struct
{
    uint16      SelectorFieldValue; /*! selector field value for the dynamic part */
    PduIdType   DynPartUpperPduId;  /*! Upper layer Pdu Id used for receive indication of this dynamic part */
}IpduM_RxDynPartConfigType;

/*! @brief Defines the type for the IpduM Rx Pdu configuration */
typedef struct
{
    uint8                   SelectorFieldMsByteIdx;  /*! MS byte Index of the selector field */
    uint8                   SelectorFieldMsBitIdx;   /*! MS bit Index of the segment field */
    uint8                   SelectorFieldLsByteIdx;  /*! LS byte Index of the segment field */
    uint8                   SelectorFieldLsBitIdx;   /*! LS bit Index of the segment  field */
    uint8                   SelectorFieldBitLength;  /*! Bit length of the segment field */
    uint8                   SelectorFieldByteLength; /*! Byte length of the segment field */
    IpduM_ByteOrderType     ByteOrder;               /*! ByteOrder for all segments & selectorField  */
    IpduM_RxDynPartIdxType  RxDynPartStartIdx;       /*! Start index of Rx dynamic part configuration belongs to this*/
    IpduM_RxDynPartIdxType  RxDynPartEndIdx;         /*! End index of Rx dynamic part configuration belongs to this*/
#if(IPDUM_STATIC_PART_EXISTS == STD_ON)
    boolean                 IsStaticPartExist;       /*! enables/disable the static part support */
    PduIdType               StaticPartUpperPduId;    /*! Upper layer Pdu Id receive indication of this static part */
#endif
}IpduM_RxPduConfigType;

typedef struct
{
    uint8               	SrcLsBit;
    uint8               	SrcLsByte;
    uint8               	DestLsBit;
    uint8               	DestLsByte;
    uint32              	MaxSrcBufferSize;
    uint32              	MaxDestBufferSize;
    IpduM_ByteOrderType   	SrcBufferEndianess;
    IpduM_ByteOrderType   	DestBufferEndianess;
    uint32              	SignalLengthInBits;
    uint32              	SingalLengthInBytes;
}IpduM_UtilBitCopyPropsType;
/*******************************************************************************************************************
*  Container configuration                                                                                         *
********************************************************************************************************************/
/*! @brief Header size is 64 bit: * Header Id 32 bit * Dlc 32 bit */
#define IPDUM_HEADER_SIZE_TYPE_LONG     0U
/*! @brief Header size is 32 bit: * Header Id 24 bit * Dlc 8 bit */
#define IPDUM_HEADER_SIZE_TYPE_SHORT    1U
/*! @brief Defines the layout of the header information (header id and length) */
typedef uint8 IpduM_ContainerHeaderSizeType;

 /*! @brief Defines the handling of this ContainerPdu shall be done in the next IpduM main function (DEFERRED)*/
#define IPDUM_PROCESSING_DEFERRED       0U
/*! @brief Defines the handling of this ContainerPdu shall be done in the context of the caller (IMMEDIATE) */
#define IPDUM_PROCESSING_IMMEDIATE      1U
 /*! @brief Defines whether the handling of this ContainerPdu shall be done in the context of the caller
    (IMMEDIATE) or in the next IpduM main function (DEFERRED). */
typedef uint8 IpduM_ContainerPduProcessingType;

/*! @brief The IpduMRxContainedPdus which are referencing this IpduMRxContainerPdu are expected inside this
    IpduMRxContainerPdu, but there may also occur other Pdus inside this IpduMRxContainerPdu as well.
    This also supports the case where no IpduMRxContainedPdu references the IpduMRxContainerPdu.*/
#define IPDUM_CONTAINER_RX_ACCEPT_TYPE_ALL                0U
/*! @brief Only the IpduMRxContainedPdus which are referencing this IpduM-RxContainerPdu are expected inside
    this IpduMRxContainerPdu. */
#define IPDUM_CONTAINER_RX_ACCEPT_TYPE_ACCEPT_CONFIGURED  1U
/*! @brief Defines for the received IpduMRxContainerPdu whether the list of referencing IpduM-RxContainedPdus
    (via the reference IpduMRxContainedPduContainerRef) is a closed set. */
typedef uint8 IpduM_ContainerRxAcceptType;
/*! @brief Defines the type for the Configuration of a received contained Pdu. */
typedef struct
{
    uint32      ContainedPduHeaderId;  /* Header Id which is part of the ContainerPdu when this ContainedPdu is inside. */
    PduIdType   ContainerPduId;        /* Reference to a container Pdu this contained Pdu may be transported in. */
    PduIdType   UpperLayerNotifyPduId;  /* Upper layer Pdu Id used for notifing receive indication */
}IpduM_ContainedRxPduConfigType;

/*! @brief Defines the data type for the size of the contained Pdu */
typedef uint8 IpduM_RxContainedIpduIdxType;

/*
#define COM_IPDU_RX_CONATAINED_ZV_MDK_Resp_M0       0U
#define COM_IPDU_RX_CONATAINED_ZV_MDK_Resp_M1       1U
#define COM_IPDU_RX_CONATAINED_ZV_PSD_06_M0         2U
#define COM_IPDU_RX_CONATAINED_ZV_MOTOR_09_M0       3U
#define COM_IPDU_RX_CONATAINED_ZV_MOTOR_09_M1       4U
#define COM_IPDU_RX_CONATAINED_ZV_MOTOR_09_M2       5U
#define COM_IPDU_RX_CONATAINED_ZV_MOTOR_09_M3       6U
#define COM_IPDU_RX_CONATAINED_ZV_MOTOR_GAS_01_M0   7U
#define COM_IPDU_RX_CONATAINED_ZV_MOTOR_GAS_01_M1   8U */
#define IPDUM_NUM_OF_RX_CONTAINED_IPDU              9U

/*! @brief Defines the configuration type of the Rx container IPDU */
typedef struct
{
    /*! Defines a local queue for handling of each ContainerPdu. */
    uint8                               ContainerQueueSize;
    /*! Defines the start index of the Ipdu contained config. */
    IpduM_RxContainedIpduIdxType        ContainedIpduStartIdx;
    /*! Defines the end index of the Ipdu contained config. */
    IpduM_RxContainedIpduIdxType        ContainedIpduEndIdx;
    /*! Defines the layout of the header information (header id and length). */
    IpduM_ContainerHeaderSizeType       ContainerHeaderSize;
    /*! Defines the processing type of the Container I-Pdu */
    IpduM_ContainerPduProcessingType    ContainerPduProcessingType;
    /*! Defines the acceptance type of the Container I-Pdu */
    IpduM_ContainerRxAcceptType         ContainerRxAcceptType;
}IpduM_ContainerRxPduConfigType;

/* Config */
/*! @brief Container PDU handle */
#define IPDUM_IPDU_CONTAINER_RX_MSG_ZV_MDK_Resp     0U
#define IPDUM_IPDU_CONTAINER_RX_MSG_PSD_06          1U
#define IPDUM_IPDU_CONTAINER_RX_MSG_MOTOR_09        2U
#define IPDUM_IPDU_CONTAINER_RX_MSG_MOTOR_GAS_01    3U
#define IPDUM_NUM_OF_RX_CONTAINER_IPDU              4U


/*! @brief The IpduMContainedTxPdu data will be fetched via TriggerTransmit just before the transmission executes. */
#define IPDUM_COLLECT_LAST_IS_BEST      0U
/* The IpduMContainedTxPdu data will instantly be stored to the IpduMCon-tainerTxPdu in the context of the Transmit API. */
#define IPDUM_COLLECT_QUEUED            1U
/*! @brief Defines whether this IpduMContainedTxPdu shall be collected using a last-is-best or queued semantics. */
typedef uint8 IpduM_ContainedTxPduCollectionSemanticsType;

/*! @brief This Pdu directly triggers the sending of the ContainerPdu */
#define IPDUM_TRIGGER_ALWAYS            0U
/*! @brief This Pdu does not triggers the sending of the ContainerPdu (other trigger criteria might still trigger
    sending of the ContainerPdu). */
#define IPDUM_TRIGGER_NEVER             1U
/* Defines whether this Pdu triggers the sending of the ContainerPdu. */
typedef uint8 IpduM_ContainedTxPduTriggerType;

/*! @brief Defines the configuration type for the Tx contained Ipdu */
typedef struct
{
    /*! @brief This Parameter determines whether for this contained I-PDU a TxConfir-mation shall be provided.
        If set to TRUE a TxConfirmation is issued. It is not used when an I-PDU is requested using the trigger
        transmit API. */
    boolean                                     IsConfirmationEnabled;
    /*! @brief Defines whether this IpduMContainedTxPdu shall be collected using a last-is-best or queued semantics. */
    IpduM_ContainedTxPduCollectionSemanticsType TxPduCollectionSemanticsType;
    /*! @brief Defines whether this Pdu triggers the sending of the ContainerPdu. */
    IpduM_ContainedTxPduTriggerType             TxPduTrigger;
    /*! Reference to the container Pdu which this contained Pdu shall be collected in. */
    PduIdType                                   TxInContainerPduId;
    /*! Reference to the Pdu which is used for notificatio. */
    PduIdType                                   UpperLayerNotifyPduId;
    /*! Header Id which is part of the ContainerPdu when this ContainedPdu is inside. */
    uint32                                      TxPduHeaderId;
    /*! Defines a ContainedPdu specific sender timeout which can reduce the ContainerPdu timer when this
        ContainedPdu is put inside the ContainerPdu. */
    uint32                                      TxPduSendTimeout;
}IpduM_ContainedTxPduConfigType;

/*! @brief Defines the type for the Tx Contained IPDU size */
typedef uint8 IpduM_TxContainedIpduIdxType;

/*! @brief The IpduM sends this ContainerPdu when this ContainerPdu is triggered. */
#define IPDUM_TX_TRIGGER_MODE_TYPE_DIRECT               0U
/*! @brief This ContainerPdu is stored in the IpduM and fetched via trigger transmit. */
#define IPDUM_TX_TRIGGER_MODE_TYPE_TRIGGER_TRANSMIT     1U
/*! @brief Defines whether this ContainerPdu is fetched via trigger transmit. */
typedef uint8 IpduM_ContainerTxTriggerModeType;

/*! Defines the configuration type for the Tx Ipdu container */
typedef struct
{
    /*! @brief Defines a local queue for handling of each ContainerPdu. */
    uint8                               ContainerQueueSize;
    /*! @brief Defines if the transmission of this IpduMContainerTxPdu shall be requested right after the first
        IpduMContainedTxPdu was put into it. */
    boolean                             ContainerTxFirstContainedPduTrigger;
    /*! @brief Defines whether this ContainerPdu is fetched via trigger transmit. */
    IpduM_ContainerTxTriggerModeType    ContainerTxTriggerModeType;
    /*! @brief Defines the layout of the header information (header id and length). */
    IpduM_ContainerHeaderSizeType       ContainerHeaderSize;
    /*! Defines the start index of the Ipdu contained config. */
    IpduM_TxContainedIpduIdxType        ContainedIpduStartIdx;
    /*! Defines the end index of the Ipdu contained config. */
    IpduM_TxContainedIpduIdxType        ContainedIpduEndIdx;
    /*! @brief Reference to the Pdu which represents the container and is used for transmission. */
    PduIdType                           LowerLayerTransmitId;
    /* This timeout (in milliseconds) defines the timeout period for monitoring the reception of the TxConfirmation.
        It is not used when an I-PDU is requested using the trigger transmit API. */
    uint32                              ContainerTxConfirmationTimeout;
    /*! When this timeout expires the ContainerPdu is triggered for sending. The respective timer is started when the
        first Pdu is put into the ContainerPdu. */
    uint32                              ContainerTxSendTimeout;
    /*! Defines the size threshold in bytes which, when exceeded, triggers the sending of the ContainerPdu although the
        maxium Pdu size (PduLength parameter of Pdu object) has not been reached yet. */
    uint32                              ContainerTxSizeThreshold;
}IpduM_ContainerTxPduConfigType;

/* Config for Tx */
/* IPDU Id called by the PduR for transmission Com->PduR->IpduM */
#define PDUR_IPDU_CONTAINER_TX_VIN_01               0U
#define PDUR_IPDU_CONTAINER_TX_SERVICE_KEY_01       1U
#define PDUR_IPDU_CONTAINER_TX_MDKZV_REQ            2U

#define IPDUM_IPDU_CONTAINED_TX_VIN_01_M0           0U
#define IPDUM_IPDU_CONTAINED_TX_VIN_01_M1           1U
#define IPDUM_IPDU_CONTAINED_TX_VIN_01_M2           2U
#define IPDUM_IPDU_CONTAINED_TX_SERVICE_KEY_01_M0   3U
#define IPDUM_IPDU_CONTAINED_TX_SERVICE_KEY_01_M1   4U
#define IPDUM_IPDU_CONTAINED_TX_SERVICE_KEY_01_M2   5U
#define IPDUM_IPDU_CONTAINED_TX_SERVICE_KEY_01_M3   6U
#define IPDUM_IPDU_CONTAINED_TX_SERVICE_KEY_01_M4   7U
#define IPDUM_IPDU_CONTAINED_TX_SERVICE_KEY_01_M5   8U
#define IPDUM_IPDU_CONTAINED_TX_SERVICE_KEY_01_M6   9U
#define IPDUM_IPDU_CONTAINED_TX_SERVICE_KEY_01_M7  10U
#define IPDUM_IPDU_CONTAINED_TX_SERVICE_KEY_01_M8  11U
#define IPDUM_IPDU_CONTAINED_TX_SERVICE_KEY_01_M9  12U
#define IPDUM_IPDU_CONTAINED_TX_MDKZV_REQ_M0       13U
#define IPDUM_IPDU_CONTAINED_TX_MDKZV_REQ_M1       14U
#define IPDUM_IPDU_CONTAINED_TX_MDKZV_REQ_M2       15U
#define IPDUM_IPDU_CONTAINED_TX_MDKZV_REQ_M3       16U
#define IPDUM_IPDU_CONTAINED_TX_MDKZV_REQ_M4       17U
#define IPDUM_IPDU_CONTAINED_TX_MDKZV_REQ_M5       18U
#define IPDUM_NUM_OF_TX_CONTAINED_IPDU             19U

/* Tx container Ipdu ,  called by pdur for transmit confirmation CanIf->PduR->IpduM*/
#define IPDUM_IPDU_CONTAINER_TX_VIN_01          0U
#define IPDUM_IPDU_CONTAINER_TX_SERVICE_KEY_01  1U
#define IPDUM_IPDU_CONTAINER_TX_MDKZV_REQ       2U
#define IPDUM_NUM_OF_TX_CONTAINER_IPDU          3U

#define IPDUM_ID_TYPE_MULTIPLEX		0U
#define IPDUM_ID_TYPE_CONTAINER		1U
typedef uint8 IpduM_PduIdType;

typedef struct
{
	PduIdType		 DestIpduMId;
	IpduM_PduIdType  IpduMPduIdType;
}IpduM_PduMapConfigType;

#define IPDUM_IPDU_ID_TX_MSG_VIN_01_M0  	        0U
#define IPDUM_IPDU_ID_TX_MSG_VIN_01_M1  	        1U
#define IPDUM_IPDU_ID_TX_MSG_VIN_01_M2	            2U
#define IPDUM_IPDU_ID_TX_MSG_SERVICE_KEY_01_M0	    3U
#define IPDUM_IPDU_ID_TX_MSG_SERVICE_KEY_01_M1	    4U
#define IPDUM_IPDU_ID_TX_MSG_SERVICE_KEY_01_M2	    5U
#define IPDUM_IPDU_ID_TX_MSG_SERVICE_KEY_01_M3	    6U
#define IPDUM_IPDU_ID_TX_MSG_SERVICE_KEY_01_M4	    7U
#define IPDUM_IPDU_ID_TX_MSG_SERVICE_KEY_01_M5	    8U
#define IPDUM_IPDU_ID_TX_MSG_SERVICE_KEY_01_M6	    9U
#define IPDUM_IPDU_ID_TX_MSG_SERVICE_KEY_01_M7	   10U
#define IPDUM_IPDU_ID_TX_MSG_SERVICE_KEY_01_M8	   11U
#define IPDUM_IPDU_ID_TX_MSG_SERVICE_KEY_01_M9	   12U
#define IPDUM_IPDU_ID_TX_MSG_MDKZV_REQ_M0	       13U
#define IPDUM_IPDU_ID_TX_MSG_MDKZV_REQ_M1	       14U
#define IPDUM_IPDU_ID_TX_MSG_MDKZV_REQ_M2	       15U
#define IPDUM_IPDU_ID_TX_MSG_MDKZV_REQ_M3	       16U
#define IPDUM_IPDU_ID_TX_MSG_MDKZV_REQ_M4	       17U
#define IPDUM_IPDU_ID_TX_MSG_MDKZV_REQ_M5	       18U
#define IPDUM_IPDU_ID_TX_MSG_MDKZV_REQ_STATIC	   19U
#define IPDUM_NUM_OF_TX_IPDU_ID			           20U

#define IPDUM_IPDU_ID_RX_MSG_ZV_MDK_Resp  	        0U
#define IPDUM_IPDU_ID_RX_MSG_PSD_06  	            1U
#define IPDUM_IPDU_ID_RX_MSG_MOTOR_09  	            2U
#define IPDUM_IPDU_ID_RX_MSG_MOTOR_GAS_01  	        3U
#define IPDUM_NUM_OF_RX_IPDU_ID	                    4U

#define IPDUM_FULL_HEADER_MASK  0xFFFFFFFF
#define IPDUM_SHORT_HEADER_MASK 0xFFFF

#define IpduM_EnterCriticalSection()
#define IpduM_ExitCriticalSection()

#ifndef IPDUM_DUMMY_STATEMENT
#define IPDUM_DUMMY_STATEMENT(v) (v)=(v)
#endif

/* Extern definitions */
/*! @brief Defines the IpduM Tx configuration */
extern const IpduM_TxPduConfigType IpduM_TxPduConfig[IPDUM_NUM_OF_TX_MESSAGE];
/*! @brief Defines the IpduM Tx part configuration */
extern const IpduM_TxPartConfigType IpduM_TxPartConfig[IPDUM_PDU_TX_NUM_OF_PARTS];
/*! @brief Defines the Bit and Byte position configuration for the Tx segments */
extern const IpduM_TxSegmentConfigType IpduM_TxSegmentConfig[IPDUM_NUM_OF_TX_SEGMENTS];
/*! @brief Defines the IpduM Tx buffer configuration */
extern const IpduM_BufferConfigType IpduM_TxBufferConfig[IPDUM_NUM_OF_TX_MESSAGE];
/*! @brief Defines the IpduM Tx Buffer Init values */
extern const uint8 IpduM_TxBufferInitValues[IPDUM_TX_BUFFER_SIZE];
/*! @brief Defines the IpduM Tx buffer configuration */
extern const IpduM_BufferConfigType IpduM_RxBufferConfig[IPDUM_NUM_OF_RX_MESSAGE];
/*! @brief Defines the Rx pdu dynamic part configuration */
extern const IpduM_RxDynPartConfigType IpduM_RxDynPartConfig[IPDUM_NUM_OF_RX_DYNAMIC_PARTS];
/*! @brief Defines the IpduM Rx Pdu configuration */
extern const IpduM_RxPduConfigType IpduM_RxPduConfig[IPDUM_RX_NUM_OF_MSG];
/*! @brief Defines IpduM_ContainerRxPduConfig */
extern const IpduM_ContainerRxPduConfigType IpduM_ContainerRxPduConfig[IPDUM_NUM_OF_RX_CONTAINER_IPDU];
/*! @brief Defines IpduM_ContainedRxPduConfig */
extern const IpduM_ContainedRxPduConfigType IpduM_ContainedRxPduConfig[IPDUM_NUM_OF_RX_CONTAINED_IPDU];
/*! @brief Defines IpduM_ContainedTxPduConfig */
extern const IpduM_ContainedTxPduConfigType IpduM_ContainedTxPduConfig[IPDUM_NUM_OF_TX_CONTAINED_IPDU];
/*! @brief Defines IpduM_ContainerTxPduConfig */
extern const IpduM_ContainerTxPduConfigType IpduM_ContainerTxPduConfig[IPDUM_NUM_OF_TX_CONTAINER_IPDU];
/*! @brief Defines IpduM_TxPduMapConfig */
extern const IpduM_PduMapConfigType IpduM_TxPduMapConfig[IPDUM_NUM_OF_TX_IPDU_ID];
/*! @brief Defines IpduM_RxPduMapConfig */
extern const IpduM_PduMapConfigType IpduM_RxPduMapConfig[IPDUM_NUM_OF_RX_IPDU_ID];
#endif /* IPDUM_CFG_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
