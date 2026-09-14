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
/// @file dk_srvc_uds_service_ecu_reset_handler.h
/// @ingroup UdsServices
///
/// @brief  CUdsServiceEcuResetHandler Class. It implements the the ECU reset handler service 0x11.
///
/// This service requests the server to effectively perform a server reset based on the content of the resetType
/// parameter value embedded in the ECUReset request message. The ECUReset positive response message (if
/// required) shall be sent before the reset is executed in the server(s). After a successful server reset the server
/// shall activate the defaultSession.
///
//---------------------------------------------------------------------------------------------------------------------
#ifndef DK_SRVC_UDS_SERVICE_DTC_READ_HANDLER_H
#define DK_SRVC_UDS_SERVICE_DTC_READ_HANDLER_H
#include "dk_srvc_uds_service_handler_if.h"
#include "dk_srvc_uds_service_manager_if.h"
//#include "dk_runtime_c_uds_bl_service_manager_comp.h"
#include "dk_runtime_uds_appl_component.h"
namespace dk {
namespace app {
namespace udsblservices {

class CUdsServiceDtcHandler: public CUdsServiceHandlerIf {
public:
	///
	/// @brief This method is the ECU reset service handler initialization routine.This method should be
	///        invoked by UDS service Manager on Init .
	///
	void serviceInitialize(void);

	///
	/// @brief This method is used to set the UDS service Manager instance reference for the ECU reset
	///        service handler.
	///
	/// @param[in] pUdsServiceManagerIf pointer to the UDS service manager Instance.
	///
	explicit CUdsServiceDtcHandler(CUdsServiceManagerIf &serviceManagerInstance) :
			mpServiceManagerInstance(serviceManagerInstance) {

	}
	~CUdsServiceDtcHandler() {

	}

	static void readDtcdiagTunnelCallback(void* instancePointer, uint8_t result);

private:

	///
	/// @brief It defines the sub function value supported by Read DTC Handler (0x19) services.
	///
	typedef enum {
		EReadDtcSubFunction_reportDTCByStatusMask = 02u,  ///< reportDTCByStatusMask
		EReadDtcSubFunction_reportSupportedDTC = 0x0A,          ///< reportSupportedDTC
	} EReadDtcSubFunction_t;

	///
	/// @brief It defines the DTC Read request data length.
	///
	const uint8_t mUdsSupportedDtcReadRequestLength = 0x01u;
	const uint8_t mUdsDtcByMaskReadRequestLength = 0x02u;

	///
	/// @brief It defines the sub function value supported by DTC Read service.
	///
	const uint8_t mUdsDtcReadSubFunction = 0x03;

	uint8_t mDTCRespPendingFrmVIP = false;

	uint8_t mDtcSubfunction = 0;

	uint8_t mDtcReqMask = 0;

	uint16_t mClientAddress;
	uint16_t mRequestLength = 0;
	EInstallationStatus_t_t mGipFlashState = 0x1;
	///
	/// @brief It defines the DTC Read service configurations.
	///
	SServiceConfig_t mDtcReadServiceConfig;

	///
	/// @brief It defines the service configurations.
	///
	CUdsServiceManagerIf &mpServiceManagerInstance;

	///
	/// @brief This method handles the DTC Read request . The method should be set as request handler callback
	///        function for DTC Read service.This method updates positive or negative response based on the
	///        request .
	/// @param[in] pRequestData  pointer to request data length
	/// @param[in] requestLength  size of the requested data.
	///
	void dtcReadRequestHandler(const uint16_t clientAddress,
			const uint8_t * const pRequestData, uint16_t requestLength);

	///
	/// @brief This method handles the post response functionality of DTC Read service.This method is
	///         configured as post response handler callback  function for DTC Read service.
	///
	void dtcReadPostresponseHandler(const uint16_t clientAddress);

	///
	/// @brief This method handles the reset handler of DTC Read service.This method will set internal status to
	///        initial value.This method is configured as reset handler callback function for DTC Read service.
	///
	void dtcReadResetHandler(const uint16_t clientAddress);

};

} // udsblservices
} // app
} // dk
#endif  //DK_SRVC_UDS_SERVICE_DTC_READ_HANDLER_H
