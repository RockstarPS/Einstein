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
/// @file dk_srvc_uds_service_routine_control_handler.h
/// @ingroup UdsServices
///
/// @brief  CUdsServiceRoutineControlHandler Class. It implements the the RoutineControl (0x31) service.
///
/// The RoutineControl service is used by the client to execute a defined sequence of steps and obtain any
/// relevant results. There is a lot of flexibility with this service, but typical usage may include functionality
/// such as erasing memory, resetting or learning adaptive data, running a self-test, overriding the normal server
/// control strategy, and controlling a server value to change over time including predefined sequences (e.g., close
/// convertible roof) to name a few. In general, when used to control outputs this service is used for more
/// complex type control whereas inputOutputControlByIdentifier is used for relatively simple (e.g., static) output
/// control.
///The RoutineControl service is used by the client to:
///     -# start a routine,
///     -# stop a routine, and
///     -# request routine results
/// A routine is referenced by a 2-byte routineIdentifier.
//---------------------------------------------------------------------------------------------------------------------
#ifndef DK_SRVC_UDS_SERVICE_ROUTINE_CONTROL_HANDLER_H
#define DK_SRVC_UDS_SERVICE_ROUTINE_CONTROL_HANDLER_H

#include "dk_srvc_uds_service_handler_if.h"
#include "dk_srvc_uds_service_manager_if.h"
#include "dk_runtime_bl_einstein_uds_app_component.h"


namespace dk
{
namespace app
{
namespace udsblservices
{

class CUdsServiceRoutineControlHandler : public CUdsServiceHandlerIf
{
public:

    explicit CUdsServiceRoutineControlHandler
    (
        CUdsServiceManagerIf &serviceManagerInstance
    ):mServiceManagerInstance(serviceManagerInstance)
    {

    }
    ///
    /// @brief This method is the RoutineControl (0x31) service handler initialization routine.This method should be
    ///        invoked by UDS service Manager on Init .
    ///
    virtual void serviceInitialize ( void );

    ///
    /// @brief This method is used to set the UDS service Manager instance reference for the RoutineControl (0x31)
    ///        service handler.
    ///
    /// @param[in] pUdsServiceManagerIf pointer to the UDS service manager Instance.
    ///
    void setServiceManagerIf ( CUdsServiceManagerIf *pUdsServiceManagerIf );
	
	void RoutineControlUpdAdapterResponseHandler(uint32_t ServiceID, CUdsServiceManagerIf::EResponseType_t Response, std::vector<uint8_t> responseBuffer);

	void DownloadServiceResponseHandler(DoIPDownloadResponse const  & msg);
	
	///
    /// @brief This method is used to convert data in array format to 32 bit value.
    ///
    /// @param[in] array start address.
    /// @param[in] address of the 32 bit value.
	/// 
	void arrayTo32BitValue(uint8_t *const arr, uint32_t *value);


private:

    ///
    /// @brief It defines the sub function value supported by Routine Control(0x31) services.
    ///
    typedef enum
    {
        ERoutineSubFunction_Start = 01u,    ///< start routine sub function value.
        ERoutineSubFunction_Stop,           ///< stop routine sub function value.
        ERoutineSubFunction_Requestresult,  ///< Request results sub function value.
        ERoutinSunFunction_Last             ///< Guard
    } ERoutineSubFunction_t;

    ///
    /// @brief It defines the mask value for the sub function supported by Routine Control(0x31) services.
    ///
    typedef enum
    {
        ERoutineSubFunctionMask_Start = 0x01u,       ///<  start routine sub function mask value.
        ERoutineSubFunctionMask_Stop = 0x02u,        ///<  stop routine sub function mask value.
        ERoutineSubFunctionMask_Requestresult = 0x04u, ///< Request results sub function mask value.
    } ERoutineSubFunctionMask_t;

    ///
    /// @brief It defines the configuration parameters for the routine Id.
    ///
    typedef struct
    {
        uint16_t    mRoutineId;      ///< supported routine identifier value.It is a 2 byte value.
        uint32_t    mSupportedSubFunctionMask;   ///< Supported sub function mask of the routine Id.
        uint32_t    mSupportedSessionMask;       ///< Supported session mask of the routine Id.
        uint32_t    mSupportedSecurityMask;      ///< Supported security mask of the routine Id.
    } SRoutineIdConfig_t;


    uint16_t mClientAddress = 0xFFFFU ;




    ///
    /// @brief It defines the list of routine Id supported and its properties.
    ///
    const SRoutineIdConfig_t mRoutineIdConfig[24] =
    {
        {
            /// Begin software update routine config
            0x0206u, ///< routine Id for Software update routine
            ERoutineSubFunctionMask_Start | ERoutineSubFunctionMask_Requestresult, ///< Supported sub function for
            ESessionMask_AllSession, ///< supported session mask for Software update routine
            ESecurityMask_AllLevel ///< supported security mask for Software update routine
        },
        {
            /// Begin software update routine config
            0xFE1Cu, ///< routine Id for Software update routine
            ERoutineSubFunctionMask_Start | ERoutineSubFunctionMask_Requestresult, ///< Supported sub function for
            ESessionMask_AllSession, ///< supported session mask for Software update routine
            ESecurityMask_AllLevel ///< supported security mask for Software update routine
        },
        {
            /// Begin software update routine config
            0xF04Du, ///< routine Id for Software update routine
            ERoutineSubFunctionMask_Start | ERoutineSubFunctionMask_Requestresult, ///< Supported sub function for
            ESessionMask_AllSession, ///< supported session mask for Software update routine
            ESecurityMask_AllLevel ///< supported security mask for Software update routine
        },
        {
            /// Begin software update routine config
            0xFE04u, ///< routine Id for Software update routine
            ERoutineSubFunctionMask_Start | ERoutineSubFunctionMask_Requestresult, ///< Supported sub function for
            ESessionMask_AllSession, ///< supported session mask for Software update routine
            ESecurityMask_AllLevel ///< supported security mask for Software update routine
        },
        {
            /// Begin software update routine config
            0xFE18u, ///< routine Id for Software update routine
            ERoutineSubFunctionMask_Start | ERoutineSubFunctionMask_Requestresult, ///< Supported sub function for
            ESessionMask_AllSession, ///< supported session mask for Software update routine
            ESecurityMask_AllLevel ///< supported security mask for Software update routine
        },
        {
            /// Begin software update routine config
            0xFE0Du, ///< routine Id for Software update routine
            ERoutineSubFunctionMask_Start | ERoutineSubFunctionMask_Requestresult, ///< Supported sub function for
            ESessionMask_AllSession, ///< supported session mask for Software update routine
            ESecurityMask_AllLevel ///< supported security mask for Software update routine
        },
        {
            /// Begin software update routine config
            0xFE16u, ///< routine Id for Software update routine
            ERoutineSubFunctionMask_Start | ERoutineSubFunctionMask_Requestresult, ///< Supported sub function for
            ESessionMask_AllSession, ///< supported session mask for Software update routine
            ESecurityMask_AllLevel ///< supported security mask for Software update routine
        },
        {
            /// Begin software update routine config
            0xF053u, ///< routine Id for Software update routine
            ERoutineSubFunctionMask_Start | ERoutineSubFunctionMask_Requestresult, ///< Supported sub function for
            ESessionMask_AllSession, ///< supported session mask for Software update routine
            ESecurityMask_AllLevel ///< supported security mask for Software update routine
        },
        {
            /// Begin software update routine config
            0xF052u, ///< routine Id for Software update routine
            ERoutineSubFunctionMask_Start | ERoutineSubFunctionMask_Requestresult, ///< Supported sub function for
            ESessionMask_AllSession, ///< supported session mask for Software update routine
            ESecurityMask_AllLevel ///< supported security mask for Software update routine
        },
        {
            /// Begin software update routine config
            0xF103u, ///< routine Id for Software update routine
            ERoutineSubFunctionMask_Start | ERoutineSubFunctionMask_Requestresult, ///< Supported sub function for
            ESessionMask_AllSession, ///< supported session mask for Software update routine
            ESecurityMask_AllLevel ///< supported security mask for Software update routine
        },
        {
            /// Begin software update routine config
            0xF051u, ///< routine Id for Software update routine
            ERoutineSubFunctionMask_Start | ERoutineSubFunctionMask_Requestresult, ///< Supported sub function for
            ESessionMask_AllSession, ///< supported session mask for Software update routine
            ESecurityMask_AllLevel ///< supported security mask for Software update routine
        },
        {
            /// Begin software update routine config
            0xFEEEu, ///< routine Id for Software update routine
            ERoutineSubFunctionMask_Start | ERoutineSubFunctionMask_Requestresult, ///< Supported sub function for
            ESessionMask_AllSession, ///< supported session mask for Software update routine
            ESecurityMask_AllLevel ///< supported security mask for Software update routine
        },
        {
            /// Begin software update routine config
            0xF114u, ///< routine Id for Software update routine
            ERoutineSubFunctionMask_Start | ERoutineSubFunctionMask_Requestresult, ///< Supported sub function for
            ESessionMask_AllSession, ///< supported session mask for Software update routine
            ESecurityMask_AllLevel ///< supported security mask for Software update routine
        },
        {
            /// Begin software update routine config
            0xF108u, ///< routine Id for Software update routine
            ERoutineSubFunctionMask_Start | ERoutineSubFunctionMask_Requestresult, ///< Supported sub function for
            ESessionMask_AllSession, ///< supported session mask for Software update routine
            ESecurityMask_AllLevel ///< supported security mask for Software update routine
        },
        {
            /// Begin software update routine config
            0xFE3Du, ///< routine Id for Software update routine
            ERoutineSubFunctionMask_Start | ERoutineSubFunctionMask_Requestresult, ///< Supported sub function for
            ESessionMask_AllSession, ///< supported session mask for Software update routine
            ESecurityMask_AllLevel ///< supported security mask for Software update routine
        },
        {
            /// Begin software update routine config
            0xF113u, ///< routine Id for Software update routine
            ERoutineSubFunctionMask_Start | ERoutineSubFunctionMask_Requestresult, ///< Supported sub function for
            ESessionMask_AllSession, ///< supported session mask for Software update routine
            ESecurityMask_AllLevel ///< supported security mask for Software update routine
        },
        {
            /// Begin software update routine config
            0xF11Bu, ///< routine Id for Software update routine
            ERoutineSubFunctionMask_Start | ERoutineSubFunctionMask_Requestresult, ///< Supported sub function for
            ESessionMask_AllSession, ///< supported session mask for Software update routine
            ESecurityMask_AllLevel ///< supported security mask for Software update routine
        },

        //New Did added from here.
        {
            /// Begin software update routine config
            0x37FEu, ///< routine Id for Software update routine
            ERoutineSubFunctionMask_Start | ERoutineSubFunctionMask_Requestresult, ///< Supported sub function for
            ESessionMask_AllSession, ///< supported session mask for Software update routine
            ESecurityMask_AllLevel ///< supported security mask for Software update routine
        },
        {
            /// Begin software update routine config
            0xF100u, ///< routine Id for Software update routine
            ERoutineSubFunctionMask_Start | ERoutineSubFunctionMask_Requestresult, ///< Supported sub function for
            ESessionMask_AllSession, ///< supported session mask for Software update routine
            ESecurityMask_AllLevel ///< supported security mask for Software update routine
        },
		{
            /// Begin software update Erase routine config
            0xFF00u, ///< routine Id for Software update Erase routine
            ERoutineSubFunctionMask_Start | ERoutineSubFunctionMask_Requestresult, ///< Supported sub function for
            ESessionMask_AllSession, ///< supported session mask for Software update routine
            ESecurityMask_AllLevel ///< supported security mask for Software update routine
        },
		{
            /// Begin software update Verification routine config
            0xFF01u, ///< routine Id for Software update Verification routine
            ERoutineSubFunctionMask_Start | ERoutineSubFunctionMask_Requestresult, ///< Supported sub function for
            ESessionMask_AllSession, ///< supported session mask for Software update routine
            ESecurityMask_AllLevel ///< supported security mask for Software update routine
        },
		{
            /// Begin software update Activation routine config
            0xFE00u, ///< routine Id for Software update Activation routine
            ERoutineSubFunctionMask_Start | ERoutineSubFunctionMask_Requestresult, ///< Supported sub function for
            ESessionMask_AllSession, ///< supported session mask for Software update routine
            ESecurityMask_AllLevel ///< supported security mask for Software update routine
        },
		{
            /// Begin software update RollBack routine config
            0xFE01u, ///< routine Id for Software update RollBack routine
            ERoutineSubFunctionMask_Start | ERoutineSubFunctionMask_Requestresult, ///< Supported sub function for
            ESessionMask_AllSession, ///< supported session mask for Software update routine
            ESecurityMask_AllLevel ///< supported security mask for Software update routine
        },
		{
            /// Begin software update Activation Complete | Sync routine config
            0xFE02u, ///< routine Id for Software Activation Complete | Sync update routine
            ERoutineSubFunctionMask_Start | ERoutineSubFunctionMask_Requestresult, ///< Supported sub function for
            ESessionMask_AllSession, ///< supported session mask for Software update routine
            ESecurityMask_AllLevel ///< supported security mask for Software update routine
        }		
    };

    ///
    /// @brief It defines the Routine Control(0x31) service configurations values.This value should be configured at
    ///         serviceInitialize and should be passed to CUdsServiceManager to register the configuration.
    ///
    SServiceConfig_t mRoutineControlServiceConfig;

    ///
    /// @brief It holds the reference of CUdsServiceManager instance to which it was registered. This instance is used
    ///        by the service to update the positive and negative responses.
    ///
    CUdsServiceManagerIf &mServiceManagerInstance;

    ///
    /// @brief This method handles the Routine Control(0x31) service request . The method should be set as
    ///        request handler callback  function for Routine Control(0x31) service.This method updates positive
    ///        or negative response based on the request.
    ///
    /// @param[in] pRequestData  pointer to request data length
    /// @param[in] requestLength  size of the requested data.
    ///
    void routineControlRequestHandler ( const uint16_t clientAddress, uint8_t const *pRequestData, const uint16_t requestLength );

    ///
    /// @brief This method handles the post response functionality of Routine Control(0x31) service.This method is
    ///         configured as post response handler callback  function for Routine Control(0x31) service.
    ///
    void routineControlPostresponseHandler ( const uint16_t clientAddress );

    ///
    /// @brief This method handles the reset handler of Routine Control(0x31) service.This method will set internal
    ///        status to initial value.This method is configured as reset handler callback function for Routine
    ///        Control(0x31) service.
    ///
    void routineControlResetHandler ( const uint16_t clientAddress );


    EResponseCode_t RoutineControlProcessResponse
    (
        uint8_t index,
        uint16_t DidId,
        const uint8_t * const pIOCntrlbuffer,
        uint16_t IOCntrlLength,
        const uint8_t * const pIOInfobuffer,
        uint16_t IOInfoLength
    );
};

}
}
}

#endif  //DK_SRVC_UDS_SERVICE_ROUTINE_CONTROL_HANDLER_H
