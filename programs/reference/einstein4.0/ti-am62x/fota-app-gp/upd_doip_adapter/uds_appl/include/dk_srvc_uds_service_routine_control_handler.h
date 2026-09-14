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
#include "dk_runtime_uds_appl_component.h"

namespace dk
{
namespace app
{
namespace udsblservices
{
class CUdsServiceRoutineControlHandler : public CUdsServiceHandlerIf
{
public:    
	
    /// 
    /// @brief It defines the routine values . This value is the index in the routine configuration table.
    ///
    typedef enum
    {
        //ERoutine_SoftwareUpdate= 0, ///< Software update 0xF000u
       // ERoutine_SwitchNewVersion,  ///< Switch version 0xF001u
        //ERoutine_RollBackPreviousVersion,   ///< Roll back version 0xF002u
        //ERoutine_RemovePreviousVersion, ///< Remove previous version 0xF003u
		ERoutine_ProgramCheck=0, ///< Program Check 0xF000u
		ERoutine_RunDtcTest, ///< DTC test 0xF006u
        ERoutine_Last   ///< Guard
    }ERoutineConfigIndex_t; 
    
    ///
    /// @brief This method is the RoutineControl (0x31) service handler initialization routine.This method should be 
    ///        invoked by UDS service Manager on Init . 
    ///
    void serviceInitialize(void);
    
    ///
    /// @brief This method is used to set the UDS service Manager instance reference for the RoutineControl (0x31)  
    ///        service handler.
    ///
    /// @param[in] pUdsServiceManagerIf pointer to the UDS service manager Instance.
    ///
    explicit CUdsServiceRoutineControlHandler
       (
           CUdsServiceManagerIf &serviceManagerInstance
       ):mpServiceManagerInstance(serviceManagerInstance)
       {

       }
    ~CUdsServiceRoutineControlHandler()
       {

       }


    static void routinediagTunnelCallback(void* instancePointer, uint8_t result);

private:

    ///
    /// @brief It defines the sub function value supported by Routine Control(0x31) services.
    ///
    typedef enum
    {
        ERoutineSubFunction_Start=01u,      ///< start routine sub function value.
        ERoutineSubFunction_Stop,           ///< stop routine sub function value.
        ERoutineSubFunction_Requestresult,  ///< Request results sub function value.
        ERoutinSunFunction_Last             ///< Guard
    }ERoutineSubFunction_t; 
    
    ///
    /// @brief It defines the mask value for the sub function supported by Routine Control(0x31) services.
    ///
    typedef enum
    {
        ERoutineSubFunctionMask_Start=0x01u,         ///<  start routine sub function mask value.
        ERoutineSubFunctionMask_Stop=0x02u,          ///<  stop routine sub function mask value.
        ERoutineSubFunctionMask_Requestresult=0x04u, ///< Request results sub function mask value.
    }ERoutineSubFunctionMask_t;
    
    ///
    /// @brief It defines the configuration parameters for the routine Id.
    ///
    typedef struct
    {
        uint16_t    mRoutineId;      ///< supported routine identifier value.It is a 2 byte value.
        uint32_t    mSupportedSubFunctionMask;   ///< Supported sub function mask of the routine Id.
        uint32_t    mSupportedSessionMask;       ///< Supported session mask of the routine Id.
        uint32_t    mSupportedSecurityMask;      ///< Supported security mask of the routine Id.
    }SRoutineIdConfig_t;
    
    ///
    /// @brief It defines the control status parameter for routine processing.
    /// 
    typedef struct
    {
        ERoutineConfigIndex_t mCurrentRoutineIndex;    ///< current processing routine index.
        ERoutineSubFunction_t mCurrentRoutineSubFunction;    ///< current processing routine sub function
        uint8_t dtcStatus; /* to be update in response message */
        bool mIsRoutineResponsePending;  ///< status flag for response processing .
    }SRoutineStatus_t;
    
    uint16_t mClientAddress = 0xFFFFU ;
    uint16_t mRecord_U16;
    uint8_t mDtcnumber_U8;
    uint16_t mRoutineId; // requested routine ID
        
    ///
    /// @brief It defines the Routine Control(0x31) service configurations values.This value should be configured at 
    ///         serviceInitialize and should be passed to CUdsServiceManager to register the configuration.
    ///
    SServiceConfig_t mRoutineControlServiceConfig;
    
    ///
    /// @brief It defines the current routine processing status.
    ///
    SRoutineStatus_t mCurrentroutineStatus;
    
    ///
    /// @brief It holds the reference of CUdsServiceManager instance to which it was registered. This instance is used 
    ///        by the service to update the positive and negative responses.
    ///
    //CUdsServiceManagerIf * mpServiceManagerInstance;
    CUdsServiceManagerIf &mpServiceManagerInstance;
    
    ///
    /// @brief This method handles the Routine Control(0x31) service request . The method should be set as 
    ///        request handler callback  function for Routine Control(0x31) service.This method updates positive 
    ///        or negative response based on the request.
    ///
    /// @param[in] pRequestData  pointer to request data length
    /// @param[in] requestLength  size of the requested data.
    ///
    void routineControlRequestHandler(const uint16_t clientAddress,const uint8_t *const pRequestData,uint16_t requestLength);
    
    ///
    /// @brief This method handles the post response functionality of Routine Control(0x31) service.This method is 
    ///         configured as post response handler callback  function for Routine Control(0x31) service.
    ///
    void routineControlPostresponseHandler(const uint16_t clientAddress);
    
    ///
    /// @brief This method handles the reset handler of Routine Control(0x31) service.This method will set internal 
    ///        status to initial value.This method is configured as reset handler callback function for Routine 
    ///        Control(0x31) service.
    ///
    void routineControlResetHandler(const uint16_t clientAddress);
    
};
} // udsblservices
} // app
} // dk
#endif  //DK_SRVC_UDS_SERVICE_ROUTINE_CONTROL_HANDLER_H
