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
// Date: Thu Mar 12 18:15:53 IST 2026
// User: KRAMESH5
// System: GIP
// Configuration: Platform
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.10
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
#define DK_MSG_POWERSYSTEMSTATE       (0xC000U)
#define DK_MSG_POWEREXTENDSHUTDOWNTIME       (0xC001U)
#define DK_MSG_POWERKEEPSYSTEMAWAKE       (0xC002U)
#define DK_MSG_HEALTHSTATUSREPORT       (0xE500U)
#define DK_MSG_POWERSYSTEMSTATEREQCHANGE       (0xC100U)
#define DK_MSG_POWERSYSTEMSTATEREQWAKELOCK       (0xC102U)
#define DK_MSG_POWERREPORTCOMPSTATE       (0xC101U)
#define DK_MSG_UCLERRORNOTIFY       (0xE001U)
#define DK_MSG_UCLLINKSTATUS       (0xE000U)
#define DK_MSG_HEALTHGETSTATUS       (0xE400U)
#define DK_MSG_RTC       (0x3607U)
#define DK_MSG_HEALTHDOMAINHEARTBEAT       (0xE300U)
#define DK_MSG_HEALTHDOMAINFATALERROR       (0xE301U)
#define DK_MSG_HEALTHEVENTRECORD       (0xE302U)
#define DK_MSG_HEALTHDUMPHDRINFO       (0xE200U)
#define DK_MSG_HEALTHDUMPDATA       (0xE201U)
#define DK_MSG_HEALTHDUMPGETHDR       (0xE100U)
#define DK_MSG_HEALTHDUMPGETDATA       (0xE101U)
#define DK_MSG_DISPLAYSETPOWER       (0x3E00U)
#define DK_MSG_DISPLAYGETSTATE       (0x3E01U)
#define DK_MSG_MAINHMIREADYSTATUS       (0x4300U)
#define DK_MSG_DISPLAYCURRENTSTATE       (0x3F00U)
#define DK_MSG_EMMCERRORNOTIFIER       (0xE303U)
#define DK_MSG_UPDATESHORTSERVICERESP       (0xBF02U)
#define DK_MSG_UPDATESHORTSERVICEREQ       (0xBE00U)
#define DK_MSG_UPDATELONGSERVICEREQ       (0xBE01U)
#define DK_MSG_SAFEHMIREADYSTATUS       (0x4301U)
#define DK_MSG_SHIFTPOSINDSTATUS       (0x6900U)
#define DK_MSG_WARNINGSTATUS       (0x3400U)
#define DK_MSG_WARNINGDISPLAYAVAILABLE       (0x3401U)
#define DK_MSG_TT_STATUS       (0x3500U)
#define DK_MSG_RTT_STATUS       (0x3501U)
#define DK_MSG_FRTT_STATUS       (0x3502U)
#define DK_MSG_RTT_TOGGLE       (0x3503U)
#define DK_MSG_RTT_ICON       (0x3504U)
#define DK_MSG_WARNINGDISPLAY       (0x3300U)
#define DK_MSG_WARNINGEXTDISPLAY       (0x3301U)
#define DK_MSG_SLOWGAUGEINFO       (0x3600U)
#define DK_MSG_ILLUMINATIONDATA       (0x5600U)
#define DK_MSG_FASTGAUGEINFO       (0x3601U)
#define DK_MSG_DIAGRESPONSE       (0x8800U)
#define DK_MSG_DIAGROUTINEREQUEST       (0x8601U)
#define DK_MSG_DIAGIOCTRLREQUEST       (0x8602U)
#define DK_MSG_DIAGDIDREQUEST       (0x8600U)
#define DK_MSG_DLTMESSAGEREADACK       (0x8A00U)
#define DK_MSG_DLTCONTROLMESSAGEREQUEST       (0x8A01U)
#define DK_MSG_DLTMESSAGEREADREQUEST       (0x8900U)
#define DK_MSG_DLTCONTROLMESSAGEREPONSE       (0x8901U)
#define DK_MSG_DOIPDIAGDATATRANSFERREQUEST       (0x5602U)
#define DK_MSG_DOIPDIAGDATAINDICATION       (0x5500U)
#define DK_MSG_UDSSERVICERESPONSETRANSMITREQUEST       (0x5502U)
#define DK_MSG_DOIPDIAGDATACONFIRMATION       (0x5501U)
#define DK_MSG_UDSSERVICESETTIMINGS       (0x5503U)
#define DK_MSG_DOIPSETPARAMS       (0x5601U)
#define DK_MSG_DOIPDIAGPOWERMODESTATUS       (0x5603U)
#define DK_MSG_UDSTIMEOUT       (0x5701U)
#define DK_MSG_UDSSERVICERESPONSETRANSMITCONFIRMATION       (0x5700U)
#define DK_MSG_UDSSERVICEREQINDICATION       (0x5702U)
#define DK_MSG_GIPDIAGREQUEST       (0x6807U)
#define DK_MSG_GIPDIAGRESPONSE       (0x6808U)
#define DK_MSG_DOIPDOWNLOADREQUEST       (0x8C00U)
#define DK_MSG_DOIPDOWNLOADRESPONSE       (0x8D01U)
#define DK_MSG_NETWORKINTERFACESTATUS       (0xA005U)
#define DK_MSG_NETWORKMODIFYFIREWALLSTATUS       (0xA000U)
#define DK_MSG_NETWORKMODIFYLINKSTATUS       (0xA001U)
#define DK_MSG_NETWORKMODIFYVLANINTERFACE       (0xA002U)
#define DK_MSG_NETWORKMODIFYINTERFACE       (0xA003U)
#define DK_MSG_ENETREGREQ       (0xA004U)

//< Compoment Ids
#define COMPID_OSYSTEMSTATECOMPONENT         ((uint8_t)0x01U)
#define COMPID_OSYSTEMSTATECOMPONENT_STR     ("OSYS")
#define COMPID_OSYSTEMSTATECOMPONENT_DESC    ("")

#define COMPID_OHEALTHMGRCOMPONENT         ((uint8_t)0x02U)
#define COMPID_OHEALTHMGRCOMPONENT_STR     ("OHEA")
#define COMPID_OHEALTHMGRCOMPONENT_DESC    ("")

#define COMPID_ODISPLAYMANAGERCOMPONENT         ((uint8_t)0x03U)
#define COMPID_ODISPLAYMANAGERCOMPONENT_STR     ("ODIS")
#define COMPID_ODISPLAYMANAGERCOMPONENT_DESC    ("")

#define COMPID_OEMMCMGRCOMPONENT         ((uint8_t)0x05U)
#define COMPID_OEMMCMGRCOMPONENT_STR     ("OEMM")
#define COMPID_OEMMCMGRCOMPONENT_DESC    ("")

#define COMPID_OSHMICOMPONENT         ((uint8_t)0x06U)
#define COMPID_OSHMICOMPONENT_STR     ("OSHM")
#define COMPID_OSHMICOMPONENT_DESC    ("")

#define COMPID_OMHMICOMPONENT         ((uint8_t)0x0BU)
#define COMPID_OMHMICOMPONENT_STR     ("OMHM")
#define COMPID_OMHMICOMPONENT_DESC    ("")

#define COMPID_OVIDEOMGRCOMPONENT         ((uint8_t)0x0CU)
#define COMPID_OVIDEOMGRCOMPONENT_STR     ("OVID")
#define COMPID_OVIDEOMGRCOMPONENT_DESC    ("")

#define COMPID_OHMIGAUGESCOMPONENT         ((uint8_t)0x0DU)
#define COMPID_OHMIGAUGESCOMPONENT_STR     ("OHMI")
#define COMPID_OHMIGAUGESCOMPONENT_DESC    ("")

#define COMPID_OHMIWARNINGSCOMPONENT         ((uint8_t)0x0EU)
#define COMPID_OHMIWARNINGSCOMPONENT_STR     ("OHMI")
#define COMPID_OHMIWARNINGSCOMPONENT_DESC    ("")

#define COMPID_OHMIGEARCOMPONENT         ((uint8_t)0x0FU)
#define COMPID_OHMIGEARCOMPONENT_STR     ("OHMI")
#define COMPID_OHMIGEARCOMPONENT_DESC    ("")

#define COMPID_OHMIILLUMINATIONCOMPONENT         ((uint8_t)0x10U)
#define COMPID_OHMIILLUMINATIONCOMPONENT_STR     ("OHMI")
#define COMPID_OHMIILLUMINATIONCOMPONENT_DESC    ("")

#define COMPID_OHMICOMPONENT         ((uint8_t)0x11U)
#define COMPID_OHMICOMPONENT_STR     ("OHMI")
#define COMPID_OHMICOMPONENT_DESC    ("")

#define COMPID_OMEETCOMPONENT         ((uint8_t)0x13U)
#define COMPID_OMEETCOMPONENT_STR     ("OMEE")
#define COMPID_OMEETCOMPONENT_DESC    ("")

#define COMPID_ODLTGATEWAYCOMPONENT         ((uint8_t)0x14U)
#define COMPID_ODLTGATEWAYCOMPONENT_STR     ("ODLT")
#define COMPID_ODLTGATEWAYCOMPONENT_DESC    ("")

#define COMPID_OUDSCORECOMPONENT         ((uint8_t)0x15U)
#define COMPID_OUDSCORECOMPONENT_STR     ("OUDS")
#define COMPID_OUDSCORECOMPONENT_DESC    ("")
#define COMPID_OEINSUDSAPPLCOMPONENT         ((uint8_t)0x16U)
#define COMPID_OEINSUDSAPPLCOMPONENT_STR     ("OEIN")
#define COMPID_OEINSUDSAPPLCOMPONENT_DESC    ("")
#define COMPID_ODOIPCOMPONENT         ((uint8_t)0x17U)
#define COMPID_ODOIPCOMPONENT_STR     ("ODOI")
#define COMPID_ODOIPCOMPONENT_DESC    ("")

#define COMPID_OUPDUCLADAPTERCOMPONENT         ((uint8_t)0x19U)
#define COMPID_OUPDUCLADAPTERCOMPONENT_STR     ("OUPD")
#define COMPID_OUPDUCLADAPTERCOMPONENT_DESC    ("")

#define COMPID_OUPDDOIPADAPTERCOMPONENT         ((uint8_t)0x1AU)
#define COMPID_OUPDDOIPADAPTERCOMPONENT_STR     ("OUPD")
#define COMPID_OUPDDOIPADAPTERCOMPONENT_DESC    ("")

#define COMPID_OUDSSWCDIAGCOMPONENT         ((uint8_t)0x18U)
#define COMPID_OUDSSWCDIAGCOMPONENT_STR     ("OUDS")
#define COMPID_OUDSSWCDIAGCOMPONENT_DESC    ("")

#define COMPID_ONETWORKMANAGERCOMPONENT         ((uint8_t)0x1BU)
#define COMPID_ONETWORKMANAGERCOMPONENT_STR     ("ONET")
#define COMPID_ONETWORKMANAGERCOMPONENT_DESC    ("")
#ifdef __cplusplus
} // runtime
} // dk
#endif
#endif //DK_RUNTIME_MESSAGES_H

