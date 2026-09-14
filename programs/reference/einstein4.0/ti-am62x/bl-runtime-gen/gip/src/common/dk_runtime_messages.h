//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2022] Visteon Corporation
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
//
// File generated automatically using Visteon VMF & Dijkstra Runtime configuration generator 1.2.1
// Date: Tue Oct 01 17:31:26 IST 2024
// User: KRAMESH5
// System: GIP
// Configuration: Platform_Recovery
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.2
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef DK_RUNTIME_MESSAGES_H
#define DK_RUNTIME_MESSAGES_H

#include <stdint.h>

#ifdef __cplusplus
namespace dk
{
namespace runtime
{
#endif

#define DK_RTE_MAJOR_VERSION       (0U)
#define DK_RTE_MINOR_VERSION       (1U)
#define DK_RTE_PATCH_VERSION       (2U)

//< Message Defintions
#define DK_MSG_UPDATESHORTSERVICERESP       (0xBF02U)
#define DK_MSG_UPDATESHORTSERVICEREQ       (0xBE00U)
#define DK_MSG_UPDATELONGSERVICEREQ       (0xBE01U)
#define DK_MSG_POWERSYSTEMSTATEREQWAKELOCK       (0xC102U)
#define DK_MSG_POWERREPORTCOMPSTATE       (0xC101U)
#define DK_MSG_UCLERRORNOTIFY       (0xE001U)
#define DK_MSG_UCLLINKSTATUS       (0xE000U)
#define DK_MSG_HEALTHGETSTATUS       (0xE400U)
#define DK_MSG_HEALTHSTATUSREPORT       (0xE500U)
#define DK_MSG_DISPLAYCURRENTSTATE       (0x3F00U)
#define DK_MSG_DISPLAYGETSTATE       (0x3E01U)
#define DK_MSG_DOIPDOWNLOADREQUEST       (0x8C00U)
#define DK_MSG_DOIPDOWNLOADRESPONSE       (0x8D01U)
#define DK_MSG_DOIPDIAGDATAINDICATION       (0x5500U)
#define DK_MSG_DOIPDIAGDATACONFIRMATION       (0x5501U)
#define DK_MSG_DOIPSETPARAMS       (0x5601U)
#define DK_MSG_DOIPDIAGDATATRANSFERREQUEST       (0x5602U)
#define DK_MSG_DOIPDIAGPOWERMODESTATUS       (0x5603U)
#define DK_MSG_UDSTIMEOUT       (0x5701U)
#define DK_MSG_UDSSERVICERESPONSETRANSMITCONFIRMATION       (0x5700U)
#define DK_MSG_UDSSERVICEREQINDICATION       (0x5702U)
#define DK_MSG_UDSSERVICERESPONSETRANSMITREQUEST       (0x5502U)
#define DK_MSG_UDSSERVICESETTIMINGS       (0x5503U)

//< Compoment Ids
#define COMPID_OBLEINSTEINUDSAPPCOMPONENT         ((uint8_t)0x01U)
#define COMPID_OBLEINSTEINUDSAPPCOMPONENT_STR     ("OBLE")
#define COMPID_OBLEINSTEINUDSAPPCOMPONENT_DESC    ("")

#define COMPID_OBLUPDDOIPADAPTERCOMPONENT         ((uint8_t)0x02U)
#define COMPID_OBLUPDDOIPADAPTERCOMPONENT_STR     ("OBLU")
#define COMPID_OBLUPDDOIPADAPTERCOMPONENT_DESC    ("")

#define COMPID_OBLUPDUCLADAPTERCOMPONENT         ((uint8_t)0x03U)
#define COMPID_OBLUPDUCLADAPTERCOMPONENT_STR     ("OBLU")
#define COMPID_OBLUPDUCLADAPTERCOMPONENT_DESC    ("")

#define COMPID_OUDSCORECOMPONENT         ((uint8_t)0x04U)
#define COMPID_OUDSCORECOMPONENT_STR     ("OUDS")
#define COMPID_OUDSCORECOMPONENT_DESC    ("")

#define COMPID_ODOIPCOMPONENT         ((uint8_t)0x05U)
#define COMPID_ODOIPCOMPONENT_STR     ("ODOI")
#define COMPID_ODOIPCOMPONENT_DESC    ("")

#ifdef __cplusplus
} // runtime
} // dk
#endif
#endif //DK_RUNTIME_MESSAGES_H

