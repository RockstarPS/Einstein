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
/// @file dk_srvc_uds_core_if.h
/// @ingroup UDSCore
///
/// @brief  CUdsCoreIf Class. CUdsCoreIf is an interface class. It provides the diagnostic interface which should be
///         implemented by the corresponding diagnostic implementation e.g. UDS , KWP etc.
/// CUdsCoreIf defines the common diagnostic interface which should be implemented by the corresponding diagnostic
/// implementation e.g. UDS,KWP etc.This layer provides a interface independent of diagnostic specification used.
/// It Provides infrastructure for
///         * Receiving a request from TP Interface.
///         * Transmuting a request to the TP interface.
///         * Receiving a transmission confirmation.
///         * mapping a TP instance to a particular Diagnostic instance.
///
//---------------------------------------------------------------------------------------------------------------------
#ifndef DK_SRVC_UDS_CORE_TP_IF_H
#define DK_SRVC_UDS_CORE_TP_IF_H
#include <cstdint>

namespace dk
{
namespace srvc
{
namespace udscore
{

class CUdsTpIf; ///< Forward declaration of CUdsTpIf , as CUdsTpIf and CUdsCoreIf has bidirectional association.

class CUdsCoreIf
{
public:

    virtual ~CUdsCoreIf()
	{
    }
    ///
    /// @brief It defines the request type of UDS services.
    ///
    typedef enum
    {
        ERequestType_PhysicalRequest =0, ///< It represents the request received from physical address.The diagnostic
        /// communication model where a node of a specific communication network
        /// receives a message from one sending node (1-1 communication).
        /// This model is also referred to as "unicast".
        ERequestType_FunctionalRequest,  ///< It represents the request received from functional address.The
        /// diagnostic communication model where a group or all nodes of a
        /// specific communication network receive a message from one sending node
        /// (1-n communication). This model is also referred to as "broadcast" or
        /// "multicast". OBD communication will always be done in the Functional
        /// Addressing mode.
        ERequestType_Last                ///< Guard.
    } ERequestType_t;

    ///
    /// @brief CUdsCore diagnostic request handling.
    /// This method shall be invoked when a successful diagnostic request is received from TP layer.
    /// It validates the request acceptance conditions . If a request is already processed , then the new request is
    /// rejected and a NRC 0x21 is sent to the tester. If no new request is processed then it checks for requested
    /// length with the server supported buffer size.If requested length greater than available buffer size ,
    /// then NRC 0x10 is sent. If all the cases passes it will copy the requested data to the CUdsCore buffer.
    ///
    /// @param[in] pDataBuffer pointer to data buffer.
    /// @param[in] dataLength length of data buffer.
    /// @param[in] requestType holds the type of request given.
    ///
    /// @return boolean true If the request is accepted.
    ///              false If the request is not accepted.
    ///
    virtual bool requestIndication(const uint8_t * const pDataBuffer,const uint16_t dataLength,
                                   const ERequestType_t requestType,const uint16_t clientAddress) = 0;

    ///
    /// @brief This method handles the transmit confirmation from TP.
    /// This method is to invoked by TP layer to confirm the transmission of diagnostic response or the failure to
    /// transmit the diagnostic response.
    ///
    /// @param[in]  transmitStatus status of message transmission .
    ///         -true -  successful transmission
    ///         -false - Failure transmission.
    ///
    virtual void transmitConfirmation(const bool transmitStatus,const uint16_t clientAddress) = 0;

    ///
    /// @brief This method used to restart the Session timer.
    /// This method used to restart the Session timer.This method should be invoked from TP layer on receiving the
    /// tester present request with a functional address. This provides an parallel processing for functionally
    /// addressed tester present service.
    ///
    ///

    virtual void reStartSessionTimer(void)=0;
    ///
    /// @brief This method used to set the TP instance for the UDS
    /// This method used to set the TP instance for the UDS. The TP class should inherit from CUdsTpIf Interface.
    ///
    /// @param pUdsTpIf pointer reference to TP instance
    ///
    virtual void setUdsTpIf(CUdsTpIf * const pUdsTpIf)=0;
};

} // udscore
} // srvc
} // dk

#endif	//DK_SRVC_UDS_CORE_TP_IF_H	
