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
// Date: Thu Aug 23 18:44:39 IST 2024
// User: GSOUNDAR
// System: GIP
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef MEET_APPLICATION_TYPES_H_
#define MEET_APPLICATION_TYPES_H_
#include <utility>
#include <vector>
#include <map>
#include <cstdint>
#include "gpio_pin_mapping.h"

namespace dk
{
namespace lib
{
namespace meet
{



typedef uint16_t diagResType;



typedef enum
{
    EDiagMode_RW_Read = 0,
    EDiagMode_RW_Write = 1,
    EDiagMode_RC = 2,
    EDiagMode_IOCtrl = 3,
} EDiagMode_t;

typedef struct
{
    uint16_t didId;
    EDiagMode_t mode;
    uint8_t controlMode;
    std::vector<uint8_t> data;
} SDiagReqMsg;

typedef struct {
    gpioPin pin;
    const char* pinType;
    bool isSupported;
} gpioMapping_t;

/**
 * @brief GPIO pin mapping table for virtual-to-physical pin configuration.
 *
 * The `gpioPinMapping` array is populated using the `GPIO_MAPPING_TABLE` macro,
 * with each entry defined via the `X(PIN, VALUE, PINTYPE, ISSUPPORTED)` macro.
 *
 * Each entry maps a GPIO's physical pin, virtual value, type (input/output), and support flag.
 * This table is used in GPIO operations such as diagnostics (e.g., FE30/FE31).
 */

const gpioMapping_t gpioPinMapping[] = {
    #define X(PIN, PINTYPE,ISSUPPORTED) { PIN, PINTYPE,ISSUPPORTED},
    GPIO_MAPPING_TABLE
    #undef X
};

typedef std::vector<SDiagReqMsg> DiagReqMsgData_t;

typedef int32_t MeetRetType;

const  MeetRetType MEET_OK  = 0;
const  MeetRetType MEET_NOK  = -1;

const diagResType DIAG_POSITIVERESPONSE = 0U;                           // 0x00 - positive response
const diagResType DIAG_GENERALREJECT = ( 16U );                         // 0x10 - general reject
const diagResType DIAG_SERVICENOTSUPPORTED = ( 17U );                  // 0x11 - service not supported
const diagResType DIAG_SUBFUNCTIONNOTSUPPORTED = ( 18U );               // 0x12 - sub function not supported
const diagResType DIAG_INCORRECTMESSAGELENGTHORINVALIDFORMAT = ( 19U ); // 0x13 - incorrect message length or invalid format
const diagResType DIAG_RESPONSETOOLONG = ( 20U );                      // 0x14 - response too long
const diagResType DIAG_BUSYREPEATREQUEST = ( 33U );                    // 0x21 - busy repeat request
const diagResType DIAG_CONDITIONSNOTCORRECT = ( 34U );                  // 0x22 - conditions not correct
const diagResType DIAG_REQUESTSEQUENCEERROR = ( 36U );                  // 0x24 - request sequence error
const diagResType DIAG_NORESPONSEFROMSUBNETCOMPONENT = ( 37U );         // 0x25 - noresponse fromsubnet component
const diagResType DIAG_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION = ( 38U ); // 0x26 - failure prevents execution of requested action
const diagResType DIAG_REQUESTOUTOFRANGE = ( 49U );                     // 0x31 - request out of range
const diagResType DIAG_SECURITYACCESSDENIED = ( 51U );                  // 0x33 - security access denied
const diagResType DIAG_INVALIDKEY = ( 53U );                            // 0x35 - invalid key
const diagResType DIAG_EXCEEDNUMBEROFATTEMPTS = ( 54U );                // 0x36 - exceed number of attempts
const diagResType DIAG_REQUIREDTIMEDELAYNOTEXPIRED = ( 55U );           // 0x37 - required time delay not expired
const diagResType DIAG_UPLOADDOWNLOADNOTACCEPTED = ( 112U );            // 0x70 - upload download not accepted
const diagResType DIAG_TRANSFERDATASUSPENDED = ( 113U );                // 0x71 - transfer data suspended
const diagResType DIAG_GENERALPROGRAMMINGFAILURE = ( 114U );            // 0x72 - general programming failure
const diagResType DIAG_WRONGBLOCKSEQUENCECOUNTER = ( 115U );            // 0x73 - wrong block sequence counter
const diagResType DIAG_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING = ( 120U ); // 0x78 - request correctly received-responsepending
const diagResType DIAG_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION = ( 126U ); // 0x7E - sub function not supported in active session
const diagResType DIAG_SERVICENOTSUPPORTEDINACTIVESESSION = ( 127U );   // 0x7F - service not supported in active session
const diagResType DIAG_DEFAULT_INVALID_VALUE = ( 255U );                // 0XFF -  Invalid or Default value
} // meet
} // lib
} // dk


#endif /* DK_RUNTIME_CORE_CFG_GIP_SRC_COMPONENTS_MEET_COMPONENT_MEET_HANDLER_H_ */
