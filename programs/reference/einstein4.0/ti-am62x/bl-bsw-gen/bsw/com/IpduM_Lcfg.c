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
*    @file IpduM_Lcfg.c
*    @ingroup IpduMConfiguration
*    @brief This is IpduM Link time configuration source file. It contains definitions of Link time configuration
*    parameters for the IpduM module.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "IpduM_Cfg.h"
#include "PduR.h"

/*******************************************************************************************************************
*  LINK TIME CONFIGURATION GLOBAL CONSTANT                                                                         *
********************************************************************************************************************/

const IpduM_TxPduConfigType IpduM_TxPduConfig[IPDUM_NUM_OF_TX_MESSAGE]=
{
    /* {TxConfirmationTimeout,TxLowerPduId,ByteOrder,TxTriggerMode,IsStaticPartExist,StaticPartPduRef} */
    /* 0 - VIN_01 */
    {
        0U,
        PDUR_PDU_VIN_01,
        IPDUM_LITTLE_ENDIAN,
        IPDUM_TX_TRIGGER_MODE_STATIC_OR_DYNAMIC_PART_TRIGGER,
        FALSE,
        0xFF
    },
    /* 1 - SERVICE_KEY_01 */
    {
        0U,
        PDUR_PDU_SERVICE_KEY_01,
        IPDUM_LITTLE_ENDIAN,
        IPDUM_TX_TRIGGER_MODE_STATIC_OR_DYNAMIC_PART_TRIGGER,
        FALSE,
        0xFF
    },
    /* 2 - MDKZV_REQ */
    {
        0U,
        PDUR_PDU_MDK_ZV_REQ,
        IPDUM_LITTLE_ENDIAN,
        IPDUM_TX_TRIGGER_MODE_STATIC_OR_DYNAMIC_PART_TRIGGER,
        TRUE,
        19
    }
};

const IpduM_BufferConfigType IpduM_TxBufferConfig[IPDUM_NUM_OF_TX_MESSAGE]=
{
    /* {BufferStartIdx,BufferEndIdx,BufferSize} */
    {  0U,  7U, 8U }, /* 0 - VIN_01 */
    {  8U, 15U, 8U }, /* 1 - SERVICE_KEY_01 */
    { 16U, 23U, 8U }  /* 2 - MDKZV_REQ */
};

const uint8 IpduM_TxBufferInitValues[IPDUM_TX_BUFFER_SIZE]=
{
    0x00, 0x00, 0x00, 0x00,  /* IPDUM_PDU_VIN_01 Start */
    0x00, 0x00, 0x00, 0x00,  /* IPDUM_PDU_VIN_01 End */
    0x00, 0x00, 0x00, 0x00,  /* IPDUM_PDU_SERVICE_KEY_01 Start */
    0x00, 0x00, 0x00, 0x00,  /* IPDUM_PDU_SERVICE_KEY_01 End */
    0x00, 0x00, 0x00, 0x00,  /* IPDUM_PDU_MDK_ZV_REQ Start */
    0x00, 0x00, 0x00, 0x00   /* IPDUM_PDU_MDK_ZV_REQ End */
};

const IpduM_TxPartConfigType IpduM_TxPartConfig[IPDUM_PDU_TX_NUM_OF_PARTS]=
{
    /* {   IsJitUpdateSupported,IsTxConfirmationEnabled, PartType, SegmentStartIdx
           SegmentEndIdx, TxIpduId, TxUpperConfirmationPduId } */
    { /* 0 */
        FALSE,
        FALSE,
        IPDUM_PART_TYPE_DYNAMIC,
        0U,
        7U,
        IPDUM_PDU_VIN_01,
        PDUR_PDU_VIN_01_M0
    },
    { /* 1 */
        FALSE,
        FALSE,
        IPDUM_PART_TYPE_DYNAMIC,
        8U,
        15U,
        IPDUM_PDU_VIN_01,
        PDUR_PDU_VIN_01_M1
    },
    { /* 2 */
        FALSE,
        FALSE,
        IPDUM_PART_TYPE_DYNAMIC,
        16U,
        23U,
        IPDUM_PDU_VIN_01,
        PDUR_PDU_VIN_01_M2
    },
    { /* 3 */
        FALSE,
        FALSE,
        IPDUM_PART_TYPE_DYNAMIC,
        24U,
        25U,
        IPDUM_PDU_SERVICE_KEY_01,
        PDUR_PDU_SERVICE_KEY_01_M0
    },
    { /* 4 */
        FALSE,
        FALSE,
        IPDUM_PART_TYPE_DYNAMIC,
        26U,
        27U,
        IPDUM_PDU_SERVICE_KEY_01,
        PDUR_PDU_SERVICE_KEY_01_M1
    },
    { /* 5 */
        FALSE,
        FALSE,
        IPDUM_PART_TYPE_DYNAMIC,
        28U,
        29U,
        IPDUM_PDU_SERVICE_KEY_01,
        PDUR_PDU_SERVICE_KEY_01_M2
    },
    { /* 6 */
        FALSE,
        FALSE,
        IPDUM_PART_TYPE_DYNAMIC,
        30U,
        31U,
        IPDUM_PDU_SERVICE_KEY_01,
        PDUR_PDU_SERVICE_KEY_01_M3
    },
    { /* 7 */
        FALSE,
        FALSE,
        IPDUM_PART_TYPE_DYNAMIC,
        32U,
        33U,
        IPDUM_PDU_SERVICE_KEY_01,
        PDUR_PDU_SERVICE_KEY_01_M4
    },
    { /* 8 */
        FALSE,
        FALSE,
        IPDUM_PART_TYPE_DYNAMIC,
        34U,
        35U,
        IPDUM_PDU_SERVICE_KEY_01,
        PDUR_PDU_SERVICE_KEY_01_M5
    },
    { /* 9 */
        FALSE,
        FALSE,
        IPDUM_PART_TYPE_DYNAMIC,
        36U,
        37U,
        IPDUM_PDU_SERVICE_KEY_01,
        PDUR_PDU_SERVICE_KEY_01_M6
    },
    { /* 10 */
        FALSE,
        FALSE,
        IPDUM_PART_TYPE_DYNAMIC,
        38U,
        39U,
        IPDUM_PDU_SERVICE_KEY_01,
        PDUR_PDU_SERVICE_KEY_01_M7
    },
    { /* 11 */
        FALSE,
        FALSE,
        IPDUM_PART_TYPE_DYNAMIC,
        40U,
        41U,
        IPDUM_PDU_SERVICE_KEY_01,
        PDUR_PDU_SERVICE_KEY_01_M8
    },
    { /* 12 */
        FALSE,
        FALSE,
        IPDUM_PART_TYPE_DYNAMIC,
        42U,
        43U,
        IPDUM_PDU_SERVICE_KEY_01,
        PDUR_PDU_SERVICE_KEY_01_M9
    },
    { /* 13 */
        FALSE,
        FALSE,
        IPDUM_PART_TYPE_DYNAMIC,
        44U,
        46U,
        IPDUM_PDU_MDK_ZV_REQ,
        PDUR_PDU_MDK_ZV_REQ_M0
    },
    { /* 14 */
        FALSE,
        FALSE,
        IPDUM_PART_TYPE_DYNAMIC,
        47U,
        54U,
        IPDUM_PDU_MDK_ZV_REQ,
        PDUR_PDU_MDK_ZV_REQ_M1
    },
    { /* 15 */
        FALSE,
        FALSE,
        IPDUM_PART_TYPE_DYNAMIC,
        55U,
        57U,
        IPDUM_PDU_MDK_ZV_REQ,
        PDUR_PDU_MDK_ZV_REQ_M2
    },
    { /* 16 */
        FALSE,
        FALSE,
        IPDUM_PART_TYPE_DYNAMIC,
        58U,
        65U,
        IPDUM_PDU_MDK_ZV_REQ,
        PDUR_PDU_MDK_ZV_REQ_M3
    },
    { /* 17 */
        FALSE,
        FALSE,
        IPDUM_PART_TYPE_DYNAMIC,
        66U,
        73U,
        IPDUM_PDU_MDK_ZV_REQ,
        PDUR_PDU_MDK_ZV_REQ_M4
    },
    { /* 18 */
        FALSE,
        FALSE,
        IPDUM_PART_TYPE_DYNAMIC,
        74U,
        76U,
        IPDUM_PDU_MDK_ZV_REQ,
        PDUR_PDU_MDK_ZV_REQ_M5
    },    
    { /* 19 */
        FALSE,
        FALSE,
        IPDUM_PART_TYPE_STATIC,
        77U,
        77U,
        IPDUM_PDU_MDK_ZV_REQ,
        PDUR_PDU_MDK_ZV_REQ_STATIC
    }
};

const IpduM_TxSegmentConfigType IpduM_TxSegmentConfig[IPDUM_NUM_OF_TX_SEGMENTS]=
{
    /* {SegmentMsByteIdx,SegmentMsBitIdx,SegmentLsByteIdx,
        SegmentLsBitIdx,SegmentBitLength,SegmentByteLength} */
    /*  0 */ { 0U, 1U, 0U, 0U,  2U, 1U  }, //selector filed segment for VIN_01_MUX
    /*  1 */ { 1U, 7U, 1U, 0U,  8U, 1U  }, //Mux0 Dynamic Part for KS_Geheimnis_1
    /*  2 */ { 2U, 7U, 2U, 0U,  8U, 1U  }, //Mux0 Dynamic Part for KS_Geheimnis_2
    /*  3 */ { 3U, 7U, 3U, 0U,  8U, 1U  }, //Mux0 Dynamic Part for KS_Geheimnis_3
    /*  4 */ { 4U, 7U, 4U, 0U,  8U, 1U  }, //Mux0 Dynamic Part for KS_Geheimnis_4
    /*  5 */ { 5U, 7U, 5U, 0U,  8U, 1U  }, //Mux0 Dynamic Part for VIN_1
    /*  6 */ { 6U, 7U, 6U, 0U,  8U, 1U  }, //Mux0 Dynamic Part for VIN_2
    /*  7 */ { 7U, 7U, 7U, 0U,  8U, 1U  }, //Mux0 Dynamic Part for VIN_3
    /*  8 */ { 0U, 1U, 0U, 0U,  2U, 1U  }, //selector filed segment for VIN_01_MUX
    /*  9 */ { 1U, 7U, 1U, 0U,  8U, 1U  }, //Mux1 Dynamic Part for VIN_4
    /* 10 */ { 2U, 7U, 2U, 0U,  8U, 1U  }, //Mux1 Dynamic Part for VIN_5
    /* 11 */ { 3U, 7U, 3U, 0U,  8U, 1U  }, //Mux1 Dynamic Part for VIN_6
    /* 12 */ { 4U, 7U, 4U, 0U,  8U, 1U  }, //Mux1 Dynamic Part for VIN_7
    /* 13 */ { 5U, 7U, 5U, 0U,  8U, 1U  }, //Mux1 Dynamic Part for VIN_8
    /* 14 */ { 6U, 7U, 6U, 0U,  8U, 1U  }, //Mux1 Dynamic Part for VIN_9
    /* 15 */ { 7U, 7U, 7U, 0U,  8U, 1U  }, //Mux1 Dynamic Part for VIN_10
    /* 16 */ { 0U, 1U, 0U, 0U,  2U, 1U  }, //selector filed segment for VIN_01_MUX
    /* 17 */ { 1U, 7U, 1U, 0U,  8U, 1U  }, //Mux2 Dynamic Part for VIN_11
    /* 18 */ { 2U, 7U, 2U, 0U,  8U, 1U  }, //Mux2 Dynamic Part for VIN_12
    /* 19 */ { 3U, 7U, 3U, 0U,  8U, 1U  }, //Mux2 Dynamic Part for VIN_13
    /* 20 */ { 4U, 7U, 4U, 0U,  8U, 1U  }, //Mux2 Dynamic Part for VIN_14
    /* 21 */ { 5U, 7U, 5U, 0U,  8U, 1U  }, //Mux2 Dynamic Part for VIN_15
    /* 22 */ { 6U, 7U, 6U, 0U,  8U, 1U  }, //Mux2 Dynamic Part for VIN_16
    /* 23 */ { 7U, 7U, 7U, 0U,  8U, 1U  }, //Mux2 Dynamic Part for VIN_17
    /* 24 */ { 0U, 7U, 0U, 0U,  8U, 1U  }, //selector filed segment for SK1_MUX
    /* 25 */ { 7U, 7U, 1U, 0U, 56U, 7U  }, //Mux0 Dynamic Part for SK1_Key_Data_1
    /* 26 */ { 0U, 7U, 0U, 0U,  8U, 1U  }, //selector filed segment for SK1_MUX
    /* 27 */ { 7U, 7U, 1U, 0U, 56U, 7U  }, //Mux1 Dynamic Part for SK1_Key_Data_2
    /* 28 */ { 0U, 7U, 0U, 0U,  8U, 1U  }, //selector filed segment for SK1_MUX
    /* 29 */ { 7U, 7U, 1U, 0U, 56U, 7U  }, //Mux2 Dynamic Part for SK1_Key_Data_3
    /* 30 */ { 0U, 7U, 0U, 0U,  8U, 1U  }, //selector filed segment for SK1_MUX
    /* 31 */ { 7U, 7U, 1U, 0U, 56U, 7U  }, //Mux3 Dynamic Part for SK1_Key_Data_4
    /* 32 */ { 0U, 7U, 0U, 0U,  8U, 1U  }, //selector filed segment for SK1_MUX
    /* 33 */ { 7U, 7U, 1U, 0U, 56U, 7U  }, //Mux4 Dynamic Part for SK1_Key_Data_5
    /* 34 */ { 0U, 7U, 0U, 0U,  8U, 1U  }, //selector filed segment for SK1_MUX
    /* 35 */ { 7U, 7U, 1U, 0U, 56U, 7U  }, //Mux5 Dynamic Part for SK1_Key_Data_6
    /* 36 */ { 0U, 7U, 0U, 0U,  8U, 1U  }, //selector filed segment for SK1_MUX
    /* 37 */ { 7U, 7U, 1U, 0U, 56U, 7U  }, //Mux6 Dynamic Part for SK1_Key_Data_7
    /* 38 */ { 0U, 7U, 0U, 0U,  8U, 1U  }, //selector filed segment for SK1_MUX
    /* 39 */ { 7U, 7U, 1U, 0U, 56U, 7U  }, //Mux7 Dynamic Part for SK1_Key_Data_8
    /* 40 */ { 0U, 7U, 0U, 0U,  8U, 1U  }, //selector filed segment for SK1_MUX
    /* 41 */ { 7U, 7U, 1U, 0U, 56U, 7U  }, //Mux8 Dynamic Part for SK1_Key_Data_9
    /* 42 */ { 0U, 7U, 0U, 0U,  8U, 1U  }, //selector filed segment for SK1_MUX
    /* 43 */ { 7U, 7U, 1U, 0U, 56U, 7U  }, //Mux9 Dynamic Part for SK1_Key_Data_10
    /* 44 */ { 0U, 7U, 0U, 4U,  4U, 1U  }, //selector filed segment for MDK_ZV_Req_MUX
    /* 45 */ { 1U, 7U, 1U, 0U,  8U, 1U  }, //Mux0 Dynamic Part for MDK_ZV_Bedienstelle
    /* 46 */ { 2U, 7U, 2U, 0U,  8U, 1U  }, //Mux0 Dynamic Part for MDK_ZV_Kommando
    /* 47 */ { 0U, 7U, 0U, 4U,  4U, 1U  }, //selector filed segment for MDK_ZV_Req_MUX
    /* 48 */ { 1U, 7U, 1U, 0U,  8U, 1U  }, //Mux1 Dynamic Part for MDK_ZV_Signatur_1
    /* 49 */ { 2U, 7U, 2U, 0U,  8U, 1U  }, //Mux1 Dynamic Part for MDK_ZV_Signatur_2
    /* 50 */ { 3U, 7U, 3U, 0U,  8U, 1U  }, //Mux1 Dynamic Part for MDK_ZV_Signatur_3
    /* 51 */ { 4U, 7U, 4U, 0U,  8U, 1U  }, //Mux1 Dynamic Part for MDK_ZV_Signatur_4
    /* 52 */ { 5U, 7U, 5U, 0U,  8U, 1U  }, //Mux1 Dynamic Part for MDK_ZV_Signatur_5
    /* 53 */ { 6U, 7U, 6U, 0U,  8U, 1U  }, //Mux1 Dynamic Part for MDK_ZV_Signatur_6
    /* 54 */ { 7U, 7U, 7U, 0U,  8U, 1U  }, //Mux1 Dynamic Part for MDK_ZV_Signatur_7
    /* 55 */ { 0U, 7U, 0U, 4U,  4U, 1U  }, //selector filed segment for MDK_ZV_Req_MUX
    /* 56 */ { 1U, 3U, 1U, 0U,  4U, 1U  }, //Mux2 Dynamic Part for MDK_ZV_Komfort_Typ
    /* 57 */ { 7U, 7U, 6U, 0U, 16U, 2U  }, //Mux2 Dynamic Part for MDK_ZV_Komfort_Zaehler
    /* 58 */ { 0U, 7U, 0U, 4U,  4U, 1U  }, //selector filed segment for MDK_ZV_Req_MUX
    /* 59 */ { 1U, 7U, 1U, 0U,  8U, 1U  }, //Mux3 Dynamic Part for MDK_SE_Referenz_1
    /* 60 */ { 2U, 7U, 2U, 0U,  8U, 1U  }, //Mux3 Dynamic Part for MDK_SE_Referenz_2
    /* 61 */ { 3U, 7U, 3U, 0U,  8U, 1U  }, //Mux3 Dynamic Part for MDK_SE_Referenz_3
    /* 62 */ { 4U, 7U, 4U, 0U,  8U, 1U  }, //Mux3 Dynamic Part for MDK_SE_Referenz_4
    /* 63 */ { 5U, 7U, 5U, 0U,  8U, 1U  }, //Mux3 Dynamic Part for MDK_SE_Referenz_5
    /* 64 */ { 6U, 7U, 6U, 0U,  8U, 1U  }, //Mux3 Dynamic Part for MDK_SE_Referenz_6
    /* 65 */ { 7U, 7U, 7U, 0U,  8U, 1U  }, //Mux3 Dynamic Part for MDK_SE_Referenz_7
    /* 66 */ { 0U, 7U, 0U, 4U,  4U, 1U  }, //selector filed segment for MDK_ZV_Req_MUX
    /* 67 */ { 1U, 7U, 1U, 0U,  8U, 1U  }, //Mux4 Dynamic Part for MDK_SE_Referenz_8
    /* 68 */ { 2U, 7U, 2U, 0U,  8U, 1U  }, //Mux4 Dynamic Part for MDK_SE_Referenz_9
    /* 69 */ { 3U, 7U, 3U, 0U,  8U, 1U  }, //Mux4 Dynamic Part for MDK_SE_Referenz_10
    /* 70 */ { 4U, 7U, 4U, 0U,  8U, 1U  }, //Mux4 Dynamic Part for MDK_SE_Referenz_11
    /* 71 */ { 5U, 7U, 5U, 0U,  8U, 1U  }, //Mux4 Dynamic Part for MDK_SE_Referenz_12
    /* 72 */ { 6U, 7U, 6U, 0U,  8U, 1U  }, //Mux4 Dynamic Part for MDK_SE_Referenz_13
    /* 73 */ { 7U, 7U, 7U, 0U,  8U, 1U  }, //Mux4 Dynamic Part for MDK_SE_Referenz_14
    /* 74 */ { 0U, 7U, 0U, 4U,  4U, 1U  }, //selector filed segment for MDK_ZV_Req_MUX
    /* 75 */ { 1U, 7U, 1U, 0U,  8U, 1U  }, //Mux5 Dynamic Part for MDK_SE_Referenz_15
    /* 76 */ { 2U, 7U, 2U, 0U,  8U, 1U  }, //Mux5 Dynamic Part for MDK_SE_Referenz_16
    /* 77 */ { 0U, 3U, 0U, 0U,  4U, 1U  }  //static Part for MDK_ZV_Req
};

const IpduM_ContainedTxPduConfigType IpduM_ContainedTxPduConfig[IPDUM_NUM_OF_TX_CONTAINED_IPDU]=
{
    /* IsConfirmationEnabled, TxPduCollectionSemanticsType, TxPduTrigger, TxInContainerPduId
        UpperLayerNotifyPduId, TxPduHeaderId, TxPduSendTimeout */
    /* IPDUM_IPDU_CONTAINED_TX_VIN_01_M0 */
    {
        FALSE,
        IPDUM_COLLECT_LAST_IS_BEST,
        IPDUM_TRIGGER_ALWAYS,
        IPDUM_IPDU_CONTAINER_TX_VIN_01,
        PDUR_PDU_VIN_01,
        0x1U,
        100U
    },
    /* IPDUM_IPDU_CONTAINED_TX_VIN_01_M1 */
    {
        FALSE,
        IPDUM_COLLECT_LAST_IS_BEST,
        IPDUM_TRIGGER_ALWAYS,
        IPDUM_IPDU_CONTAINER_TX_VIN_01,
        PDUR_PDU_VIN_01,
        0x2U,
        100U
    },
    /* IPDUM_IPDU_CONTAINED_TX_VIN_01_M2 */
    {
        FALSE,
        IPDUM_COLLECT_LAST_IS_BEST,
        IPDUM_TRIGGER_ALWAYS,
        IPDUM_IPDU_CONTAINER_TX_VIN_01,
        PDUR_PDU_VIN_01,
        0x3U,
        100U
    },
    /* IPDUM_IPDU_CONTAINED_TX_SERVICE_KEY_01_M0 */
    {
        FALSE,
        IPDUM_COLLECT_LAST_IS_BEST,
        IPDUM_TRIGGER_ALWAYS,
        IPDUM_IPDU_CONTAINER_TX_SERVICE_KEY_01,
        PDUR_PDU_SERVICE_KEY_01,
        0x4U,
        100U
    },
    /* IPDUM_IPDU_CONTAINED_TX_SERVICE_KEY_01_M1 */
    {
        FALSE,
        IPDUM_COLLECT_LAST_IS_BEST,
        IPDUM_TRIGGER_ALWAYS,
        IPDUM_IPDU_CONTAINER_TX_SERVICE_KEY_01,
        PDUR_PDU_SERVICE_KEY_01,
        0x5U,
        100U
    },
    /* IPDUM_IPDU_CONTAINED_TX_SERVICE_KEY_01_M2 */
    {
        FALSE,
        IPDUM_COLLECT_LAST_IS_BEST,
        IPDUM_TRIGGER_ALWAYS,
        IPDUM_IPDU_CONTAINER_TX_SERVICE_KEY_01,
        PDUR_PDU_SERVICE_KEY_01,
        0x6U,
        100U
    },
    /* IPDUM_IPDU_CONTAINED_TX_SERVICE_KEY_01_M3 */
    {
        FALSE,
        IPDUM_COLLECT_LAST_IS_BEST,
        IPDUM_TRIGGER_ALWAYS,
        IPDUM_IPDU_CONTAINER_TX_SERVICE_KEY_01,
        PDUR_PDU_SERVICE_KEY_01,
        0x7U,
        100U
    },
    /* IPDUM_IPDU_CONTAINED_TX_SERVICE_KEY_01_M4 */
    {
        FALSE,
        IPDUM_COLLECT_LAST_IS_BEST,
        IPDUM_TRIGGER_ALWAYS,
        IPDUM_IPDU_CONTAINER_TX_SERVICE_KEY_01,
        PDUR_PDU_SERVICE_KEY_01,
        0x8U,
        100U
    },
    /* IPDUM_IPDU_CONTAINED_TX_SERVICE_KEY_01_M5 */
    {
        FALSE,
        IPDUM_COLLECT_LAST_IS_BEST,
        IPDUM_TRIGGER_ALWAYS,
        IPDUM_IPDU_CONTAINER_TX_SERVICE_KEY_01,
        PDUR_PDU_SERVICE_KEY_01,
        0x9U,
        100U
    },
    /* IPDUM_IPDU_CONTAINED_TX_SERVICE_KEY_01_M6 */
    {
        FALSE,
        IPDUM_COLLECT_LAST_IS_BEST,
        IPDUM_TRIGGER_ALWAYS,
        IPDUM_IPDU_CONTAINER_TX_SERVICE_KEY_01,
        PDUR_PDU_SERVICE_KEY_01,
        0xAU,
        100U
    },
    /* IPDUM_IPDU_CONTAINED_TX_SERVICE_KEY_01_M7 */
    {
        FALSE,
        IPDUM_COLLECT_LAST_IS_BEST,
        IPDUM_TRIGGER_ALWAYS,
        IPDUM_IPDU_CONTAINER_TX_SERVICE_KEY_01,
        PDUR_PDU_SERVICE_KEY_01,
        0xBU,
        100U
    },
    /* IPDUM_IPDU_CONTAINED_TX_SERVICE_KEY_01_M8 */
    {
        FALSE,
        IPDUM_COLLECT_LAST_IS_BEST,
        IPDUM_TRIGGER_ALWAYS,
        IPDUM_IPDU_CONTAINER_TX_SERVICE_KEY_01,
        PDUR_PDU_SERVICE_KEY_01,
        0xCU,
        100U
    },
    /* IPDUM_IPDU_CONTAINED_TX_SERVICE_KEY_01_M9 */
    {
        FALSE,
        IPDUM_COLLECT_LAST_IS_BEST,
        IPDUM_TRIGGER_ALWAYS,
        IPDUM_IPDU_CONTAINER_TX_SERVICE_KEY_01,
        PDUR_PDU_SERVICE_KEY_01,
        0xDU,
        100U
    },
    /* IPDUM_IPDU_CONTAINED_TX_MDKZV_REQ_M0 */
    {
        FALSE,
        IPDUM_COLLECT_LAST_IS_BEST,
        IPDUM_TRIGGER_ALWAYS,
        IPDUM_IPDU_CONTAINER_TX_MDKZV_REQ,
        PDUR_PDU_MDK_ZV_REQ,
        0xEU,
        100U
    },
    /* IPDUM_IPDU_CONTAINED_TX_MDKZV_REQ_M1 */
    {
        FALSE,
        IPDUM_COLLECT_LAST_IS_BEST,
        IPDUM_TRIGGER_ALWAYS,
        IPDUM_IPDU_CONTAINER_TX_MDKZV_REQ,
        PDUR_PDU_MDK_ZV_REQ,
        0xFU,
        100U
    },
    /* IPDUM_IPDU_CONTAINED_TX_MDKZV_REQ_M2 */
    {
        FALSE,
        IPDUM_COLLECT_LAST_IS_BEST,
        IPDUM_TRIGGER_ALWAYS,
        IPDUM_IPDU_CONTAINER_TX_MDKZV_REQ,
        PDUR_PDU_MDK_ZV_REQ,
        0x10U,
        100U
    },
    /* IPDUM_IPDU_CONTAINED_TX_MDKZV_REQ_M3 */
    {
        FALSE,
        IPDUM_COLLECT_LAST_IS_BEST,
        IPDUM_TRIGGER_ALWAYS,
        IPDUM_IPDU_CONTAINER_TX_MDKZV_REQ,
        PDUR_PDU_MDK_ZV_REQ,
        0x11U,
        100U
    },
    /* IPDUM_IPDU_CONTAINED_TX_MDKZV_REQ_M4 */
    {
        FALSE,
        IPDUM_COLLECT_LAST_IS_BEST,
        IPDUM_TRIGGER_ALWAYS,
        IPDUM_IPDU_CONTAINER_TX_MDKZV_REQ,
        PDUR_PDU_MDK_ZV_REQ,
        0x12U,
        100U
    },
    /* IPDUM_IPDU_CONTAINED_TX_MDKZV_REQ_M5 */
    {
        FALSE,
        IPDUM_COLLECT_LAST_IS_BEST,
        IPDUM_TRIGGER_ALWAYS,
        IPDUM_IPDU_CONTAINER_TX_MDKZV_REQ,
        PDUR_PDU_MDK_ZV_REQ,
        0x13U,
        100U
    }
};

const IpduM_ContainerTxPduConfigType IpduM_ContainerTxPduConfig[IPDUM_NUM_OF_TX_CONTAINER_IPDU]=
{
    /* ContainerQueueSize, ContainerTxFirstContainedPduTrigger, ContainerTxTriggerModeType
        ContainerHeaderSize, ContainedIpduStartIdx, ContainedIpduEndIdx, LowerLayerTransmitId,
        ContainerTxConfirmationTimeout, ContainerTxSendTimeout, ContainerTxSizeThreshold */
    /* 0 - IPDUM_IPDU_CONTAINER_TX_VIN_01 */
    {
        0U,
        TRUE,
        IPDUM_TX_TRIGGER_MODE_TYPE_DIRECT,
        IPDUM_HEADER_SIZE_TYPE_LONG,
        0U,
        3U,
        PDUR_PDU_VIN_01,
        100U,
        1U,
        0U
    },
    /* 1 - IPDUM_IPDU_CONTAINER_TX_SERVICE_KEY_01 */
    {
        0U,
        TRUE,
        IPDUM_TX_TRIGGER_MODE_TYPE_DIRECT,
        IPDUM_HEADER_SIZE_TYPE_LONG,
        4U,
        13U,
        PDUR_PDU_SERVICE_KEY_01,
        100U,
        1U,
        0U
    },
    /* 2 - IPDUM_IPDU_CONTAINER_TX_MDKZV_REQ */
    {
        0U,
        TRUE,
        IPDUM_TX_TRIGGER_MODE_TYPE_DIRECT,
        IPDUM_HEADER_SIZE_TYPE_LONG,
        14U,
        19U,
        PDUR_PDU_MDK_ZV_REQ,
        100U,
        1U,
        0U
    }
};

const IpduM_PduMapConfigType IpduM_TxPduMapConfig[IPDUM_NUM_OF_TX_IPDU_ID] =
{
	/* DestIpduMId, IpduMPduIdType */
    {
		IPDUM_IPDU_ID_TX_MSG_VIN_01_M0,
		IPDUM_ID_TYPE_MULTIPLEX
	},
	{
		IPDUM_IPDU_ID_TX_MSG_VIN_01_M1,
		IPDUM_ID_TYPE_MULTIPLEX
	},
	{
		IPDUM_IPDU_ID_TX_MSG_VIN_01_M2,
		IPDUM_ID_TYPE_MULTIPLEX
	},
	{
		IPDUM_IPDU_ID_TX_MSG_SERVICE_KEY_01_M0,
		IPDUM_ID_TYPE_MULTIPLEX
	},
	{
		IPDUM_IPDU_ID_TX_MSG_SERVICE_KEY_01_M1,
		IPDUM_ID_TYPE_MULTIPLEX
	},
	{
		IPDUM_IPDU_ID_TX_MSG_SERVICE_KEY_01_M2,
		IPDUM_ID_TYPE_MULTIPLEX
	},
	{
		IPDUM_IPDU_ID_TX_MSG_SERVICE_KEY_01_M3,
		IPDUM_ID_TYPE_MULTIPLEX
	},
	{
		IPDUM_IPDU_ID_TX_MSG_SERVICE_KEY_01_M4,
		IPDUM_ID_TYPE_MULTIPLEX
	},
	{
		IPDUM_IPDU_ID_TX_MSG_SERVICE_KEY_01_M5,
		IPDUM_ID_TYPE_MULTIPLEX
	},
	{
		IPDUM_IPDU_ID_TX_MSG_SERVICE_KEY_01_M6,
		IPDUM_ID_TYPE_MULTIPLEX
	},
	{
		IPDUM_IPDU_ID_TX_MSG_SERVICE_KEY_01_M7,
		IPDUM_ID_TYPE_MULTIPLEX
	},
	{
		IPDUM_IPDU_ID_TX_MSG_SERVICE_KEY_01_M8,
		IPDUM_ID_TYPE_MULTIPLEX
	},
	{
		IPDUM_IPDU_ID_TX_MSG_SERVICE_KEY_01_M9,
		IPDUM_ID_TYPE_MULTIPLEX
	},
	{
		IPDUM_IPDU_ID_TX_MSG_MDKZV_REQ_M0,
		IPDUM_ID_TYPE_MULTIPLEX
	},
	{
		IPDUM_IPDU_ID_TX_MSG_MDKZV_REQ_M1,
		IPDUM_ID_TYPE_MULTIPLEX
	},
	{
		IPDUM_IPDU_ID_TX_MSG_MDKZV_REQ_M2,
		IPDUM_ID_TYPE_MULTIPLEX
	},
	{
		IPDUM_IPDU_ID_TX_MSG_MDKZV_REQ_M3,
		IPDUM_ID_TYPE_MULTIPLEX
	},
	{
		IPDUM_IPDU_ID_TX_MSG_MDKZV_REQ_M4,
		IPDUM_ID_TYPE_MULTIPLEX
	},
	{
		IPDUM_IPDU_ID_TX_MSG_MDKZV_REQ_M5,
		IPDUM_ID_TYPE_MULTIPLEX
	},
	{
		IPDUM_IPDU_ID_TX_MSG_MDKZV_REQ_STATIC,
		IPDUM_ID_TYPE_MULTIPLEX
	}
};

/* =======================================================================================================*/

/* Rx IpduM config */
const IpduM_RxDynPartConfigType IpduM_RxDynPartConfig[IPDUM_NUM_OF_RX_DYNAMIC_PARTS]=
{
    /* {SelectorFieldValue,DynPartUpperPduId} */
    { 0x00, PDUR_PDU_MDK_ZV_RESP_M0 },  /* 0 - IPDUM_PDU_MDK_ZV_RESP selector config Start Idx */
    { 0x01, PDUR_PDU_MDK_ZV_RESP_M1 },  /* 1 - IPDUM_PDU_MDK_ZV_RESP selector config End Idx */
    { 0x00, PDUR_PDU_PSD_06_M0 },      /* 2 - IPDUM_PDU_PSD_06 selector config Start & End Idx */
    { 0x00, PDUR_PDU_MOTOR_09_M0 },     /* 3 - IPDUM_PDU_MOTOR_09 selector config Start Idx */
    { 0x01, PDUR_PDU_MOTOR_09_M1 },     /* 4 - IPDUM_PDU_MOTOR_09 selector config Idx */
    { 0x02, PDUR_PDU_MOTOR_09_M2 },     /* 5 - IPDUM_PDU_MOTOR_09 selector config Idx */
    { 0x03, PDUR_PDU_MOTOR_09_M3 },     /* 6 - IPDUM_PDU_MOTOR_09 selector config End Idx */
    { 0x00, PDUR_PDU_MOTOR_GAS_01_M0 }, /* 7 - IPDUM_PDU_MOTOR_GAS_01 selector config Start Idx */
    { 0x01, PDUR_PDU_MOTOR_GAS_01_M1 }  /* 8 - IPDUM_PDU_MOTOR_GAS_01 selector config End Idx */
};

const IpduM_RxPduConfigType IpduM_RxPduConfig[IPDUM_RX_NUM_OF_MSG] =
{
    /* { SelectorFieldMsByteIdx, SelectorFieldMsBitIdx, SelectorFieldLsByteIdx,
         SelectorFieldLsBitIdx, SelectorFieldBitLength, SelectorFieldByteLength,
         ByteOrder, RxDynPartStartIdx, RxDynPartEndIdx, IsStaticPartExist, StaticPartUpperPduId} */
    /* 0 - IPDUM_PDU_MDK_ZV_RESP */
    {
        0U,
        7U,
        0U,
        4U,
        4U,
        1U,
        IPDUM_LITTLE_ENDIAN,
        0U,
        1U,
        TRUE,
        PDUR_PDU_MDK_ZV_RESP_STATIC
    },
    /* 1 - IPDUM_PDU_PSD_06 */
    {
        0U,
        2U,
        0U,
        0U,
        3U,
        1U,
        IPDUM_LITTLE_ENDIAN,
        2U,
        2U,
        FALSE,
        0xFF
    },
    /* 2 - IPDUM_PDU_MOTOR_09 */
    {
        7U,
        1U,
        7U,
        0U,
        2U,
        1U,
        IPDUM_LITTLE_ENDIAN,
        3U,
        6U,
        TRUE,
        PDUR_PDU_MOTOR_09_STATIC        
    },
    /* 3 - IPDUM_PDU_MOTOR_GAS_01 */
    {
        1U,
        4U,
        1U,
        4U,
        1U,
        1U,
        IPDUM_LITTLE_ENDIAN,
        7U,
        8U,
        TRUE,
        PDUR_PDU_MOTOR_GAS_01_STATIC
    },
};

const IpduM_BufferConfigType IpduM_RxBufferConfig[IPDUM_NUM_OF_RX_MESSAGE]=
{
    /* {BufferStartIdx,BufferEndIdx,BufferSize} */
    {  0U,  7U, 8U},
    {  8U, 15U, 8U},
    { 16U, 23U, 8U},
    { 24U, 31U, 8U}
};

/*! @brief Defines the container configuration parameters */
const IpduM_ContainerRxPduConfigType IpduM_ContainerRxPduConfig[IPDUM_NUM_OF_RX_CONTAINER_IPDU]=
{
    /* ContainerQueueSize, ContainedIpduStartIdx, ContainedIpduEndIdx, ContainerHeaderSize
        ContainerPduProcessingType, ContainerRxAcceptType */
    /* 0 - IPDUM_IPDU_CONTAINER_RX_MSG_ZV_MDK_Resp */
    {
        0U,
        0U,
        1U,
        IPDUM_HEADER_SIZE_TYPE_LONG,
        IPDUM_PROCESSING_DEFERRED,
        IPDUM_CONTAINER_RX_ACCEPT_TYPE_ACCEPT_CONFIGURED
    },
    /* 1 - IPDUM_IPDU_CONTAINER_RX_MSG_PSD_06 */
    {
        0U,
        2U,
        2U,
        IPDUM_HEADER_SIZE_TYPE_LONG,
        IPDUM_PROCESSING_DEFERRED,
        IPDUM_CONTAINER_RX_ACCEPT_TYPE_ACCEPT_CONFIGURED
    },
    /* 2 - IPDUM_IPDU_CONTAINER_RX_MSG_MOTOR_09 */
    {
        0U,
        3U,
        6U,
        IPDUM_HEADER_SIZE_TYPE_LONG,
        IPDUM_PROCESSING_DEFERRED,
        IPDUM_CONTAINER_RX_ACCEPT_TYPE_ACCEPT_CONFIGURED
    },
    /* 3 - IPDUM_IPDU_CONTAINER_RX_MSG_MOTOR_GAS_01 */
    {
        0U,
        7U,
        8U,
        IPDUM_HEADER_SIZE_TYPE_LONG,
        IPDUM_PROCESSING_DEFERRED,
        IPDUM_CONTAINER_RX_ACCEPT_TYPE_ACCEPT_CONFIGURED
    }
};

const IpduM_ContainedRxPduConfigType IpduM_ContainedRxPduConfig[IPDUM_NUM_OF_RX_CONTAINED_IPDU]=
{
    /* ContainedPduHeaderId, ContainerPduId, UpperLayerNotifyPduId */
    {
        0x1U,
        IPDUM_IPDU_CONTAINER_RX_MSG_ZV_MDK_Resp,
        PDUR_PDU_MDK_ZV_RESP_M0
    },
    {
        0x2U,
        IPDUM_IPDU_CONTAINER_RX_MSG_ZV_MDK_Resp,
        PDUR_PDU_MDK_ZV_RESP_M1
    },
    {
        0x3U,
        IPDUM_IPDU_CONTAINER_RX_MSG_PSD_06,
        PDUR_PDU_PSD_06_M0
    },
    {
        0x4U,
        IPDUM_IPDU_CONTAINER_RX_MSG_MOTOR_09,
        PDUR_PDU_MOTOR_09_M0
    },
    {
        0x5U,
        IPDUM_IPDU_CONTAINER_RX_MSG_MOTOR_09,
        PDUR_PDU_MOTOR_09_M1
    },
    {
        0x6U,
        IPDUM_IPDU_CONTAINER_RX_MSG_MOTOR_09,
        PDUR_PDU_MOTOR_09_M2
    },
    {
        0x7U,
        IPDUM_IPDU_CONTAINER_RX_MSG_MOTOR_09,
        PDUR_PDU_MOTOR_09_M3
    },
    {
        0x8U,
        IPDUM_IPDU_CONTAINER_RX_MSG_MOTOR_GAS_01,
        PDUR_PDU_MOTOR_GAS_01_M0
    },
    {
        0x9U,
        IPDUM_IPDU_CONTAINER_RX_MSG_MOTOR_GAS_01,
        PDUR_PDU_MOTOR_GAS_01_M1
    }
};
const IpduM_PduMapConfigType IpduM_RxPduMapConfig[IPDUM_NUM_OF_RX_IPDU_ID] =
{
	/* DestIpduMId, IpduMPduIdType */
    {
		IPDUM_PDU_MDK_ZV_RESP,
		IPDUM_ID_TYPE_MULTIPLEX
	},
    {
		IPDUM_PDU_PSD_06,
		IPDUM_ID_TYPE_MULTIPLEX
	},
    {
		IPDUM_PDU_MOTOR_09,
		IPDUM_ID_TYPE_MULTIPLEX
	},
    {
		IPDUM_PDU_MOTOR_GAS_01,
		IPDUM_ID_TYPE_MULTIPLEX
	}
};

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
