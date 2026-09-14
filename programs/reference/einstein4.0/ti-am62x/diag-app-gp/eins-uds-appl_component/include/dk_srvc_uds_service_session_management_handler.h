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
/// @file dk_srvc_uds_service_session_management_handler.h
/// @ingroup UdsBlServices
///
/// @brief  CUdsServiceSessionManagementHandler Class. It implements the the DiagnosticSessionControl 0x10 service.
///
/// TThe DiagnosticSessionControl service is used to enable different diagnostic sessions in the server(s).
/// A diagnostic session enables a specific set of diagnostic services and/or functionality in the server(s). This
/// service provides the capability that the server(s) can report data link layer specific parameter values valid for
/// the enabled diagnostic session (e.g. timing parameter values). The user of this International Standard shall
/// define the exact set of services and/or functionality enabled in each diagnostic session.There shall always be
/// exactly one diagnostic session active in a server. A server shall always start the default diagnostic session when
/// powered up. If no other diagnostic session is started, then the default diagnostic session shall be running as
/// long as the server is powered.
///
//---------------------------------------------------------------------------------------------------------------------
#ifndef DK_SRVC_UDS_SERVICE_SESSION_MANAGEMENT_HANDLER_H
#define DK_SRVC_UDS_SERVICE_SESSION_MANAGEMENT_HANDLER_H
#include "dk_srvc_uds_service_handler_if.h"
#include "dk_srvc_uds_service_manager_if.h"
//#include "dk_runtime_c_uds_bl_service_manager_comp.h"
#include "dk_runtime_eins_uds_appl_component.h"

namespace dk
{
namespace app
{
namespace udsblservices
{

class CUdsServiceSessionManagementHandler : public CUdsServiceHandlerIf
{
public:
    ///
    /// @brief Constructor of CUdsServiceSessionManagementHandler.
    ///
    /// param[in]  reference of serviceManager instance
    ///
    explicit CUdsServiceSessionManagementHandler
    (
        CUdsServiceManagerIf &serviceManagerInstance
    ):mServiceManagerInstance(serviceManagerInstance)
    {

    }

    ///
    /// @brief Destructor of CUdsServiceSessionManagementHandler.
    ///
    ~CUdsServiceSessionManagementHandler()
    {

    }

    ///
    /// @brief This method is the DiagnosticSessionControl(0x10) service handler initialization routine.This method
    ///        should be  invoked by UDS service Manager on Init .
    ///
    virtual void serviceInitialize(void);

private:
    ///
    /// @brief It defines the P2 and P2Star timing configuration for each sessions. This value should be updated in the
    ///        to Uds Core after session change.
    ///
    typedef struct
    {
        uint32_t mP2TimeMinCountInMs;      ///<P2 Server time minimum value in milliseconds.
        uint32_t mP2TimeMaxCountInMs;      ///<P2 Server time maximum value in milliseconds.This value is used for P2
        /// time in UdsCore.
        uint32_t mP2StarTimeMinCountInMs;  ///<P2 Star Server time minimum value in milliseconds.This value is used as
        /// periodicity for sending RCRRP Response.
        uint32_t mP2StarTimeMaxCountInMs;  ///<P2 Star Server time maximum value in milliseconds.
    } SUdsTimingConfig_t;

    ///
    /// @brief It defines the configuration parameters for each session supported by DiagnosticSessionControl(0x10)
    ///         service .
    ///
    typedef struct
    {
        uint8_t             mSessionSubFunctionValue; ///< It defines the sub function value of the session.
        uint32_t            mSupportedSessionMask;    ///< It defines the session mask supported by the session.
        uint32_t            mSupportedSecurityMask;   ///< It defines the security mask supported by the session.
        SUdsTimingConfig_t  mTimingConfig;            ///< It defines the timing configuration of the session.
    } SUdsSessionConfig_t;

    ///
    /// @brief It defines the P2 and P2Star timing configuration Table for each session supported.
    ///
    //const SUdsSessionConfig_t mUdsSessionConfig[ESessionType_Last] =

    const SUdsSessionConfig_t mUdsSessionConfig[ESessionType_Last] =
    {
        {
            ///<default session configuration.
            0x01U,  ///< default session sub function value.
            ESessionMask_AllSession, ///< All session mask as default session supported in all session.
            ESecurityMask_AllLevel,  ///< All security mask as default session supported in all security levels.
            {
                0U,      ///< P2 Server time minimum value for default session
                50U,    ///< P2 Server time maximum value for default session
                4000U,  ///< P2 Star Server Minimum value for default session
                5000U   ///< P2 Star Server Maximum value for default session
            }
        },
        {
            ///< programming session configuration.
            0x02U,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel,
            {
                0U,     ///< P2 Server time minimum value for programming session.
                50U,    ///< P2 Server time maximum value for programming session.
                4000U,  ///< P2 Star Server Minimum value for programming session.
                5000U   ///< P2 Star Server Maximum value for programming session.
            }
        },
        {
            ///< programming session configuration.
            0x03U,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel,
            {
                0U,     ///< P2 Server time minimum value for programming session.
                50U,    ///< P2 Server time maximum value for programming session.
                4000U,  ///< P2 Star Server Minimum value for programming session.
                5000U   ///< P2 Star Server Maximum value for programming session.
            }
        },
    };

    ///
    ///< @brief This value defines the response length of DiagnosticSessionControl(0x10) diagnostic service
    ///         (without service Id).
    ///
    const uint8_t mUdsSessionManagementResponseLength    = 0x5U;
    ///
    ///< @brief This flag enables ECU reset during transition from Reprogramming session to default session
    ///         (without service Id).
    ///
    uint8_t mEcuResetFlag = 0x0U;

    ///
    /// @brief It defines the DiagnosticSessionControl(0x10) service configurations values.This value should be
    ///        configured at  serviceInitialize and should be passed to CUdsServiceManager to register the configuration.
    ///
    SServiceConfig_t mSessionManagementServiceConfig;

    ///
    /// @brief It holds the reference of CUdsServiceManager instance to which it was registered. This instance is used
    ///        by the service to update the positive and negative responses.
    ///
    CUdsServiceManagerIf &mServiceManagerInstance;

    ///
    /// @brief This method handles the DiagnosticSessionControl(0x10) service request . The method should be set as
    ///        request handler callback  function for DiagnosticSessionControl service.This method updates positive
    ///        or negative response based on the request.
    ///
    /// @param[in] clientAddress requested client address.
    /// @param[in] pRequestData  pointer to request data length
    /// @param[in] requestLength  size of the requested data.
    ///
    void sessionManagementRequestHandler(const uint16_t clientAddress,const uint8_t * const pRequestData,const uint16_t requestLength);

    ///
    /// @brief This method handles the post response functionality of DiagnosticSessionControl(0x10) service.This
    ///         method is  configured as post response handler callback  function for tester present service.
    ///         This method should update the timing parameters of the changed session values to UdsCore.
    ///
    /// @param[in] clientAddress requested client address.
    ///
    void sessionManagementPostresponseHandler(const uint16_t clientAddress);

    ///
    /// @brief This method handles the reset handler of tester present service.This method will set internal status to
    ///        initial value.This method is configured as reset handler callback function for tester present service.
    ///        This method should set the session to default session.
    ///
    /// @param[in] clientAddress requested client address.
    ///
    void sessionManagementResetHandler(const uint16_t clientAddress);

    ///
    /// @brief This method handles validity check for session transition.This method handles the supplier and
    ///        manufacturer specific validity check for session transition.For e.g. System power state, Vehicle speed,
    ///        Voltage check etc.
    ///
    /// @param requestedSession the new session value to be changed.
    ///
    CUdsServiceHandlerIf::EResponseCode_t sessionTransitionValid(const CUdsServiceHandlerIf::ESessionType_t requestedSession);
};

} // udsblservices
} // app
} // dk

#endif  //DK_SRVC_UDS_SERVICE_SESSION_MANAGEMENT_HANDLER_H
