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
/// @file dk_srvc_uds_tp_if.h
/// @ingroup UDSCore
///
/// @brief  CUdsTpIf Class. CUdsTpIf is an interface class. It provides the generic TP layer interface which should be
///         implemented by the corresponding TP interface implementation e.g. ISO 14229-3 UDSonCAN,DoIP ISO 14229-5 etc.
/// CUdsTpIf defines the common UDS-TP interface layer methods which should be used for the interaction between UDS and
/// Tp. The corresponding UDS-TP (e.g. ISO 14229-3 UDSonCAN,DoIP ISO 14229-5 etc.) should implements
/// this common methods.This layer provides data layer independent interfaces between the TP and UDS.
/// It Provides infrastructure for
///         * Receiving a request from TP and notify the received request to UDS.
///         * Accepting a transmit request from UDS and notify the request to TP.
///         * Validation of Diagnostic Target address during reception.
///         * Receiving transmit confirmation status from DoIP and notify the status to TP.
//---------------------------------------------------------------------------------------------------------------------
#ifndef DK_SRVC_UDS_TP_IF_H
#define DK_SRVC_UDS_TP_IF_H
#include <cstdint>
#include "dk_srvc_uds_core_if.h"
namespace dk
{
namespace srvc
{
namespace udscore
{

class CUdsTpIf
{
public:

	virtual ~CUdsTpIf()
	{
		
    }
    ///
    /// @brief This method should be invoked by TP layer on status of message transmission requested by UDS.
    ///
    /// @param[in] doIpSA It represents the address of the server that has performed the requested diagnostic
    ///                  service. It is a 2 byte unsigned integer value.
    /// @param[in] doIpTA It represents the address of the client that originally requested the diagnostic
    ///                  service and shall receive the requested data.
    /// @param[in] doIpTAType It is used to represent the addressing method chosen for a message transmission.
    ///                      Two different addressing methods are used,
    ///                      -# 0x00u - physical addressing
    ///                      -# 0x01u - functional addressing
    /// @param[in] doIpResult It indicate the status of message transmission .
    ///                      - 0x00u The message has been transmitted correctly (ok)
    ///                      - 0x01u The message transmission was not successful (error).
    ///
    ///
    virtual void trasmitDataConfirmation(const uint16_t doIpSA, const uint16_t doIpTA, const uint8_t doIpTAType, const uint8_t doIpResult) = 0;

    ///
    /// @brief This method should be invoked if diagnostic message is received . This method accepts the received
    ///         request only if the address matches the configured diagnostic address
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
    )= 0;

    ///
    /// @brief This method should be invoked by CUdsCoreIf for transmit a response to the TP layer.
    ///
    /// @param[in] pMessageData pointer to transmit message Data buffer
    /// @param[in] length length of the transmit data.
    /// @param[in] clientAddress requested client address.
    ///
    /// @brief uint8_t status of the transmit request
    ///        -# 0x01u If the transmit request is accepted.
    ///        -# 0x00u If the transmit request is not accepted.
    ///
    virtual uint8_t transmitDataRequest(const uint8_t * const pMessageData,const uint16_t length,const uint16_t clientAddress)= 0;

    ///
    /// @brief This method is used to set the CUdsCoreIf instance for TP layer.This instance is used by the TP layer
    ///        for notifying the request reception and transmit confirmation.
    ///
    /// @param[in] pUdsCoreIf pointer to the CUdsCoreIf instance.
    ///
    virtual void setUdsCoreIf(CUdsCoreIf * const pUdsCoreIf) =0;
};

} // udscore
} // srvc
} // dk

#endif  //DK_SRVC_UDS_TP_IF_H
