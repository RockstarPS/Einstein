//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2017] Visteon Corporation
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
///
/// @file dk_srvc_uds_tp_doip.h
/// @ingroup UDSCore
///
/// @brief  CUdsTpDoip Class. CUdsTpDoip implements the UDS-TP interface for DoIP(ISO 14229-5).
///
/// CUdsTpDoip implements the UDS-TP interface for DoIP(ISO 14229-5).This layer provides interface for UDS to interacts
/// DoIP layer and vice versa.
/// It Provides infrastructure for,
///         * Receiving a request from DoIP and notify the received request to UDS.
///         * Accepting a transmit request from UDS and notify the request to DoIp
///         * Validation of Diagnostic Target address during reception.
///         * Receiving transmit confirmation status from DoIP and notify the status to UDS
//---------------------------------------------------------------------------------------------------------------------
#ifndef DK_SRVC_UDS_TP_DOIP_H
#define DK_SRVC_UDS_TP_DOIP_H

#include "dk_srvc_uds_tp_if.h"
#include "dk_runtime_uds_core_component.h"
#include <iostream>

namespace dk
{
namespace srvc
{
namespace udscore
{
class CUdsTpDoip: public CUdsTpIf
{
public:
    ///
    /// @brief Configuration structure for supported address .
    ///
    typedef struct
    {
        uint16_t mAddress;      ///< diagnostic client address
        CUdsCoreIf::ERequestType_t mAddressType;  ///< diagnostic client address type. 0-physical , 1-functional
    } SUdsTpReceiveAddressConfig_t;

    typedef struct
    {
        uint16_t mUdsTpSourceAddress; ///< Source address of the diagnostic Server.
        std::vector<SUdsTpReceiveAddressConfig_t> mUdsTpReceiveAddressConfig; ///< supported list of address config.
        uint16_t mDtoolAddress;
        uint16_t mRdiagAddress;
        uint16_t mFtoolAddress;

    } SUdsTpDoipConfig_t;

    ///
    /// @brief Constructor of CUdsTpDoip .
    /// @param doipConfig  configuration used for initializing DoIP.
    ///
    CUdsTpDoip(const SUdsTpDoipConfig_t udsTpDoipConfig):mUdsTpDoipConfig(udsTpDoipConfig)
    {

    }

    ///
    /// @brief Destructor of CUdsTpDoip .
    ///
    ~CUdsTpDoip()
    {

    }

    ///
    /// @brief This method is the DoIP TP implementation of generic TP(CUdsTpIf) interface.This method should be invoked
    ///        by TP layer on status of message transmission requested by UDS.
    /// @param[in] doIpSA    It represents the address of the server that has performed the requested diagnostic
    ///                  service. It is a 2 byte unsigned integer value.
    /// @param[in] doIpTA    It represents the address of the client that originally requested the diagnostic
    ///                  service and shall receive the requested data.
    /// @param[in] doIpTAType    It is used to represent the addressing method chosen for a message transmission.
    ///                      Two different addressing methods are used,
    ///                      -# 0x00u - physical addressing
    ///                      -# 0x01u - functional addressing
    /// @param[in] doIpResult    It indicate the status of message transmission .
    ///                      - 0x00u The message has been transmitted correctly (ok)
    ///                      - 0x01u The message transmission was not successful (error).
    ///
    ///
    virtual void trasmitDataConfirmation(const uint16_t doIpSA,const uint16_t doIpTA,const uint8_t doIpTAType,const uint8_t doIpResult);

    ///
    /// @brief This method is the DoIP TP implementation of generic TP(CUdsTpIf) interface.This method should be invoked
    ///        if diagnostic message is received . This method accepts the received request only if the address
    ///        matches the configured diagnostic address.
    ///
    /// @param[in] doIpSA It represents the address of the client that has requested the diagnostic service.
    ///                  It is a 2 byte unsigned integer value.
    /// @param[in] doIpTA It represents the server identifier for the server that shall perform the requested
    ///                  diagnostic service.It is a 2 byte unsigned integer value.
    /// @param[in] doIpTAType It is used to represent the addressing method chosen for a message transmission.
    ///                      Two different addressing methods are used,
    ///                      -# 0x00u - physical addressing
    ///                      -# 0x01u - functional addressing
    /// @param[in] pMessageData - Pointer to the received data.
    /// @param[in] length       - length of the received data.
    /// @param[in] doIpResult   - It is used to represent the data reception status.
    ///
    virtual void requestDataIndication
    (
        const uint16_t doIpSA,
        const uint16_t doIpTA,
        const uint8_t doIpTAType,
        const uint8_t* const pMessageData,
        const uint16_t length,
        const uint8_t doIpResult
    );

    ///
    /// @brief This method is the DoIP TP implementation of generic TP(CUdsTpIf) interface .This method should be
    ///        invoked by CUdsCoreIf for transmit a response to the TP layer.
    ///
    /// @param[in] pMessageData pointer to transmit message Data buffer
    /// @param[in] length length of the transmit data.
    /// @param[in] clientAddress requested client address.
    ///
    /// @brief uint8_t status of the transmit request
    ///        -# 0x00u If the transmit request is accepted.
    ///        -# 0x01u If the transmit request is not accepted.
    ///
    virtual uint8_t transmitDataRequest(const uint8_t *const pMessageData,const uint16_t length,const uint16_t clientAddress);

    ///
    /// @brief This method is the DoIP TP implementation of generic TP(CUdsTpIf) interface .This method is used to set
    ///        the CUdsCoreIf instance for TP layer.This instance is used by the TP layer for notifying the request
    ///        reception and transmit confirmation.
    ///
    /// @param[in] pUdsCoreIf pointer to the CUdsCoreIf instance.
    ///
    virtual void setUdsCoreIf(CUdsCoreIf * const pUdsCoreIf);

private:

    ///
    /// @brief It is the reference to the Diagnostic layer.
    ///
    CUdsCoreIf * mpUdsCoreTpIf=nullptr;

    ///
    /// @brief This is the configuration of DoIP layer DoIP.It contains the source address of the Diagnostic server.
    ///
    SUdsTpDoipConfig_t mUdsTpDoipConfig;
};

} // udscore
} // srvc
} // dk

#endif  //DK_SRVC_UDS_TP_DOIP_H
