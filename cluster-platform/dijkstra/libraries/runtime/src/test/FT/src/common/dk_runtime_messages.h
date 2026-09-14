//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2018] Visteon Corporation
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
// File generated automatically using Visteon VMF & Dijkstra Runtime configuration generator 1.1.3
// Date: Wed Oct 21 19:36:46 IST 2020
// User: SSINGH25
// System: GIP
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

#define DK_RTE_MAJOR_VERSION       (0u)
#define DK_RTE_MINOR_VERSION       (1u)
#define DK_RTE_PATCH_VERSION       (2u)

//< Message Defintions
#define DK_MSG_DKMSGTESTMSGRECEIVE       (0x3602u)
#define DK_MSG_DKMSGTESTMSGTRANSMIT       (0x360Cu)
#define DK_MSG_DKMSGTESTTRANSMITU32       (0x360Du)
#define DK_MSG_DKMSGTESTTRANSMITF64       (0x3606u)
#define DK_MSG_DKMSGTEST2RECEIVE       (0x360Eu)
#define DK_MSG_DKMSGTESTAPP2TRANSMIT       (0x360Bu)
#define DK_MSG_DKMSGTESTAPP2RECEIVE       (0x3609u)
#define DK_MSG_DKMSGT4CON1COMP1P       (0x360Fu)
#define DK_MSG_DKMSGT4CON1COMP2P       (0x3610u)
#define DK_MSG_DKMSGT4CON2COMP1P       (0x3611u)
#define DK_MSG_DKMSGT4CON2COMP2P       (0x3612u)
#define DK_MSG_DKMSGT4CON1COMP1TX       (0x3613u)
#define DK_MSG_DKMSGT4CON1COMP2TX       (0x3614u)
#define DK_MSG_DKMSGT4CON1COMP1RX       (0x3615u)
#define DK_MSG_DKMSGT4CON2COMP2RX       (0x3616u)

//< Compoment Ids
#define COMPID_OTEST_APP1_COMP1         ((uint8_t)0x0Au)
#define COMPID_OTEST_APP1_COMP1_STR     ("OTES")
#define COMPID_OTEST_APP1_COMP1_DESC    ("")

#define COMPID_OTEST_APP1_COMP2         ((uint8_t)0x0Bu)
#define COMPID_OTEST_APP1_COMP2_STR     ("OTES")
#define COMPID_OTEST_APP1_COMP2_DESC    ("")

#define COMPID_OTEST_APP2_COMP1         ((uint8_t)0x0Cu)
#define COMPID_OTEST_APP2_COMP1_STR     ("OTES")
#define COMPID_OTEST_APP2_COMP1_DESC    ("")

#define COMPID_OTEST_APP3_COM1         ((uint8_t)0x0Du)
#define COMPID_OTEST_APP3_COM1_STR     ("OTES")
#define COMPID_OTEST_APP3_COM1_DESC    ("")

#define COMPID_OT11         ((uint8_t)0x0Eu)
#define COMPID_OT11_STR     ("OT11")
#define COMPID_OT11_DESC    ("")

#define COMPID_OT12         ((uint8_t)0x0Fu)
#define COMPID_OT12_STR     ("OT12")
#define COMPID_OT12_DESC    ("")

#define COMPID_OT21         ((uint8_t)0x10u)
#define COMPID_OT21_STR     ("OT21")
#define COMPID_OT21_DESC    ("")

#define COMPID_OT22         ((uint8_t)0x11u)
#define COMPID_OT22_STR     ("OT22")
#define COMPID_OT22_DESC    ("")

#ifdef __cplusplus
} // runtime
} // dk
#endif
#endif //DK_RUNTIME_MESSAGES_H

