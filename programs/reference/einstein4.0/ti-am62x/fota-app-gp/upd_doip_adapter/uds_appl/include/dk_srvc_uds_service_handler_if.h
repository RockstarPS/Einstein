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
////---------------------------------------------------------------------------------------------------------------------
///
/// @file dk_srvc_uds_service_handler_if.h
/// @ingroup UdsBlServices
///
/// @brief  CUdsServiceHandlerIf Class. CUdsServiceHandlerIf is an interface class. It defines the common interface 
///         which should be implemented by all UDS service handlers. It is used by the UDS service Manager to invoke 
///         the corresponding service handler.
/// It provides infrastructure for
///         * Initialization routine of service handlers.
///         * Setting Service Manager Instance .
///         * Security Level and its Mask values.
///         * session Level and its Mask values.
///         * service configuration structure.
///
//---------------------------------------------------------------------------------------------------------------------
#ifndef DK_SRVC_UDS_SERVICE_HANLER_IF_H
#define DK_SRVC_UDS_SERVICE_HANLER_IF_H
#include <cstdint>
#include <map>
#include <functional>
#include "dk_logger.h"

namespace dk
{
namespace app
{
namespace udsblservices
{
    
class CUdsServiceManagerIf; //Forward declaration 

class CUdsServiceHandlerIf
{
public:
    
    ///
    /// @brief Callback function type for request handler.
    ///
    typedef std::function<void(const uint16_t clientAddress,const uint8_t * const pRequestData,\
                const uint16_t requestLength)> RequsestHandlerCbkFn_t;
    
    ///
    /// @brief Callback function type for post response handler.
    ///
    typedef std::function<void(const uint16_t)> PostResponseHandlerCbkFn_t;
    
    ///
    ///@ brief Callback function type for resting the service handlers.
    /// 
    typedef std::function<void(const uint16_t)> ResetServiceHandlerCbkFn_t;
    ///
    /// @brief It defines the value of session supported.
    ///
    typedef enum
    {
        ESessionType_DefaultSession=0x00U,  ///< Default session level
        ESessionType_FotaSession,           ///< Programming session level
		/*ESessionType_ProgrammingSession, 	///< Programming Session*/
        ESessionType_Last                   ///< Guard
    }ESessionType_t;
    
    ///
    /// @brief It defines the bit mask value for each session.This value is used by the services to 
    ///        provide the supported session check.
    /// 
    typedef enum
    {
        ESessionMask_DefaultSession = 0x01U,     ///< It defines the bit mask value for Default sessions
        ESessionMask_FotaSession = 0x02U,        ///< It defines the bit mask value for programming sessions
		ESessionMask_ExtenededSession = 0x04u,   ///< It defines the bit mask value for extended sessions
        ESessionMask_AllSession=0x07u            ///< It defines the bit mask value for all sessions
    }ESessionMask_t;
    
    ///
    /// @brief It defines the value of security level supported.
    /// 
    typedef enum
    {
        ESecurityLevel_Default=0x0U, ///< It defines the value of default security level.
        ESecurityLevel_L1,          ///< It defines the value of security level One.
		ESecurityLevel_L2,          ///< It defines the value of security level Three.
        ESecurityLevel_Last         ///< Guard
    }ESecurityLevel_t;
    
    ///
    /// @brief It defines the bit mask value for each security level.This value is used by the services to 
    ///        provide the supported security level check .
    /// 
    typedef enum
    {
        ESecurityMask_levelDefault = 0x01U, ///< It defines the bit mask value of default security level .
        ESecurityMask_levelL1 = 0x02u,      ///< It defines the bit mask value of security level One.
        ESecurityMask_levelL2 = 0x04u,       ///< It defines the bit mask value of security level Two.
        ESecurityMask_AllLevel = 0x07      ///< It defines the bit mask value of all security level.
    }ESecurityMask_t;
    
    ///
    /// @brief It defines the length check condition type of the service request length in UDS service Manager.
    ///        This value should be updated in the configuration type.
    ///
    typedef enum
    {
        ELengthCheckCondition_Equal=0U,
        ELengthCheckCondition_GreaterOrEqual,
        ELengthCheckCondition_Last
    }ELengthCheckConditionType_t;
    
    ///
    /// @brief It contains the properties of each services that needs to be validated by UDS service Manager.
    ///        Each service should update this configuration during initialization.
    /// 
    typedef struct 
    {
        bool  mIsFunctionalRequestSupported; ///< It defines whether the service accepts request from functional 
                                             ///       address type. 
        bool mResponsePendingSupported;     ///< It defines whether the response pending is supported or not.
        
        ELengthCheckConditionType_t  mLengthCheckConditionType;  ///< It defines the length check condition type for 
                                                                 ///   the service request length.
        uint16_t mServiceRequestLength;  ///< It defines the minimum service request length which needs to be checked. 
        uint32_t mSupportedSessionMask;  ///< It defines the session mask supported by the service.
        CUdsServiceHandlerIf::ESecurityMask_t mSupportedSecurityMask; ///< It defines the security mask supported by the service.
        RequsestHandlerCbkFn_t mRequsestHandlerCbkFn;    ///< It defines the request handler function of the service.
        PostResponseHandlerCbkFn_t mPostResponseHandlerCbkFn; ///< It defines the post response handling function of 
                                                              ///    the service
        ResetServiceHandlerCbkFn_t mResetServiceHandlerCbkFn; ///<It defines the reset function of the service handlers.
    }SServiceConfig_t;


    ///
    typedef struct
    {
      uint32_t mP2TimeMinCountInMs;      ///<P2 Server time minimum value in milliseconds.
      uint32_t mP2TimeMaxCountInMs;      ///<P2 Server time maximum value in milliseconds.This value is used for P2
    									 /// time in UdsCore.
      uint32_t mP2StarTimeMinCountInMs;  ///<P2 Star Server time minimum value in milliseconds.This value is used as
    									 /// periodicity for sending RCRRP Response.
      uint32_t mP2StarTimeMaxCountInMs;  ///<P2 Star Server time maximum value in milliseconds.
    }SUdsSrvcExtTimingConfig_t;

    ///
    /// @brief It defines the Timer configuration parameters for each service supported
    ///         service .
    ///
    typedef struct
    {
    	uint8_t             mSrvcIDValue; ///< It defines the service ID.
    	SUdsSrvcExtTimingConfig_t  mTimingConfig;            ///< It defines the timing configuration of the Service.
    }SUdsServiceExtTimingConfig_t;

    typedef enum
    {
    	EServiceID_DefaultService=0x00U,  	///< Default Service
    	EServiceID_WriteDID,           		///< Write GIP Digest
    	EServiceID_Routine,                 ///< Verify GIP Digest
    	EServiceID_Last						///< Guard
    }EServiceType_t;

    ///
    /// @brief It defines the P2 and P2Star timing configuration Table for Service need different configuration.
    ///
    const SUdsServiceExtTimingConfig_t mServiceSessionTimerConfig[EServiceID_Last]=
    {
    	{
    		///<default Timer configuration.
    		0x00U,  ///< default Service.
    		{
    			0U,      ///< P2 Server time minimum value for default session
    			50U,    ///< P2 Server time maximum value for default session
    			4000U,  ///< P2 Star Server Minimum value for default session
    			5000U   ///< P2 Star Server Maximum value for default session /* 5 sec */
    		}
    	},
    	{
    		///< Write GIP Digest DID.
    		0x2EU,
    		{
    			0U,       ///< P2 Server time minimum value for programming session.
    			50U,     ///< P2 Server time maximum value for programming session.
    			4000U,   ///< P2 Star Server Minimum value for programming session.
    			10000U   ///< P2 Star Server Maximum value for programming session. /* 10 sec */
    		}
    	},
		{
    		///< GIP Digest Verify.
    		0x31U,
    		{
    			0U,       ///< P2 Server time minimum value for programming session.
    			50U,     ///< P2 Server time maximum value for programming session.
    			4000U,   ///< P2 Star Server Minimum value for programming session.
    			900000U   ///< P2 Star Server Maximum value for programming session. /* 10 min */
    		}
    	}
    };

    ///< Service identifier of all UDS services as per ISO 14299-1.
    
    ///
    /// @brief It defines the service Identifier value of DiagnosticSessionControl service.
    ///
    const uint8_t mDiagnosticSessionControlServiceId                = 0x10U ;
    
    ///
    /// @brief It defines the service Identifier value of ECUReset service.
    ///
    const uint8_t mEcuResetServiceId                                = 0x11U ;
        
    ///
    /// @brief It defines the service Identifier value of SecurityAccess service.
    ///
    const uint8_t mSecurityAccessServiceId                          = 0x27U ;
    
    ///
    /// @brief It defines the service Identifier value of CommunicationControl service.
    ///
    const uint8_t mCommunicationControlServiceId                    = 0x28U ;
    
    ///
    /// @brief It defines the service Identifier value of TesterPresent service.
    ///
    const uint8_t mTesterPresentServiceId                           = 0x3EU ;
    
    ///
    /// @brief It defines the service Identifier value of AccessTimingParameter service.
    ///
    const uint8_t mAccessTimingParameterServiceId                   = 0x83U ;
    
    ///
    /// @brief It defines the service Identifier value of SecuredDataTransmission service.
    ///
    const uint8_t mSecuredDataTransmissionServiceId                 = 0x84U ;
    
    ///
    /// @brief It defines the service Identifier value of ControlDTCSetting service.
    ///
    const uint8_t mControlDtcSettingServiceId                       = 0x85U ;
    
    ///
    /// @brief It defines the service Identifier value of ResponseOnEvent service.
    ///
    const uint8_t mResponseOnEventServiceId                         = 0x86U ;
    
    ///
    /// @brief It defines the service Identifier value of LinkControl service.
    ///
    const uint8_t mLinkControlServiceId                             = 0x87U ;
    
    ///
    /// @brief It defines the service Identifier value of ReadDataByIdentifier service.
    ///
    const uint8_t mReadDataByIdentifierServiceId                    = 0x22U ;
    
    ///
    /// @brief It defines the service Identifier value of ReadMemoryByAddress service.
    ///
    const uint8_t mReadMemoryByAddressServiceId                     = 0x23U ;
    
    ///
    /// @brief It defines the service Identifier value of ReadScalingDataByIdentifier service.
    ///
    const uint8_t mReadScalingDataByAddressServiceId                = 0x24U ;
    
    ///
    /// @brief It defines the service Identifier value of ReadDataByPeriodicIdentifier service.
    ///
    const uint8_t mReadDataByPeriodicIdentifierServiceId            = 0x2AU ;
    
    ///
    /// @brief It defines the service Identifier value of DynamicallyDefineDataIdentifier service.
    ///
    const uint8_t mDynamicallyDefinedDataIdentifierServiceId        = 0x2CU ;
    
    ///
    /// @brief It defines the service Identifier value of WriteDataByIdentifier service.
    ///
    const uint8_t mWriteDataByIdentifierServiceId                   = 0x2EU ;
    
    ///
    /// @brief It defines the service Identifier value of WriteMemoryByAddress  service.
    ///
    const uint8_t mWriteMemoryByAddressServiceId                    = 0x3DU ;
    
    ///
    /// @brief It defines the service Identifier value of ClearDiagnosticInformation service.
    ///
    const uint8_t mClearDiagnosticInformationServiceId              = 0x14U ;
    
    ///
    /// @brief It defines the service Identifier value of ReadDTCInformation service.
    ///
    const uint8_t mReadDtcInformationServiceId                      = 0x19U ;
    
    ///
    /// @brief It defines the service Identifier value of InputOutputControlByIdentifier service. 
    ///
    const uint8_t mInputOutputControlByIdentifierServiceId          = 0x2FU ;
    
    ///
    /// @brief It defines the service Identifier value of RoutineControl service.
    ///
    const uint8_t mRoutineControlServiceId                          = 0x31U ;
    
    ///
    /// @brief It defines the service Identifier value of RequestDownload service.
    ///
    const uint8_t mRequestDownloadServiceId                         = 0x34U ;
    
    ///
    /// @brief It defines the service Identifier value of RequestUpload service.
    ///
    const uint8_t mRequestUploadServiceId                           = 0x35U ;
    
    ///
    /// @brief It defines the service Identifier value of TransferData service.
    ///
    const uint8_t mTransferDataServiceId                            = 0x36U ;
    
    ///
    /// @brief It defines the service Identifier value of RequestTransferExit service.
    ///
    const uint8_t mRequestTransferExitServiceId                     = 0x37U ;
    
    ///
    /// @brief It defines the service Identifier value of RequestFileTransfer service.
    ///
    const uint8_t mRequestFileTransferServiceId                     = 0x38U ;
    
    ///
    /// @brief It defines the Negative response code supported by UDS as per ISO 14299-1.
    ///
    typedef enum
    {
        EResponseCode_NoError  =   0x00U,
        ///< This indicates that the request is valid and positive response to be sent.
        
        EResponseCode_GeneralReject  = 0x10U,
        ///< This NRC indicates that the requested action has been rejected by the server.
        
        EResponseCode_ServiceNotSupported   = 0x11U ,
        ///< This NRC indicates that the requested action will not be taken because the server 
        /// does not support the requested service.
             
        EResponseCode_SubFunctionNotSupported  = 0x12U ,
        ///<  This NRC indicates that the requested action will not be taken because the server
        /// does not support the service specific parameters of the request message.
              
        EResponseCode_IncorrectMessageLengthOrInvalidFormat  = 0x13U ,
        ///< This NRC indicates that the requested action will not be taken because the length 
        /// of the received request message does not match the prescribed length for the  
        /// specified service or the format of the parameters do not match the prescribed format 
        /// for the specified service.
             
        EResponseCode_ResponseTooLong   = 0x14U ,
        ///< This NRC shall be reported by the server if the response to be generated exceeds 
        /// the maximum number of bytes available by the underlying network layer.
             
        EResponseCode_BusyRepeatRequest = 0x21U ,
        ///< This NRC indicates that the server is temporarily too busy to perform the requested    
        /// operation. In this circumstance the client shall perform repetition of the "identical   
        /// request message" or "another request message".
             
        EResponseCode_ConditionsNotCorrect  = 0x22U ,
        ///< This NRC indicates that the requested action will not be taken because the server  
        /// prerequisite conditions are not met.
             
        EResponseCode_RequestSequenceError  = 0x24U ,
        ///< This NRC indicates that the requested action will not be taken because the server  
        /// expects a different sequence of request messages or message as sent by the  
        /// client. This may occur when sequence sensitive requests are issued in the wrong order.
             
        EResponseCode_NoResponseFromSubnetComponent   = 0x25U ,
        ///< This NRC indicates that the server has received the request but the requested  
        /// action could not be performed by the server as a subnet component which is  
        /// necessary to supply the requested information did not respond within the specified 
        /// time.
             
        EResponseCode_FailurePreventsExecutionOfRequestedAction  = 0x26U ,
        ///< This NRC indicates that the requested action will not be taken because a failure 
        /// condition, identified by a DTC (with at least one DTC status bit for TestFailed, 
        /// Pending, Confirmed or TestFailedSinceLastClear set to 1), has occurred and that  
        /// this failure condition prevents the server from performing the requested action.
             
        EResponseCode_RequestOutOfRange    = 0x31U ,
        ///<This NRC indicates that the requested action will not be taken because the server 
        /// has detected that the request message contains a parameter which attempts to 
        /// substitute a value beyond its range of authority (e.g. attempting to substitute a data 
        /// byte of 111 when the data is only defined to 100), or which attempts to access a 
        /// dataIdentifier/routineIdentifer that is not supported or not supported in active 
        /// session.
            
        EResponseCode_SecurityAccessDenied  = 0x33U ,
        ///< This NRC indicates that the requested action will not be taken because the 
        /// server's security strategy has not been satisfied by the client.
             
        EResponseCode_InvalidKey = 0x35U ,
        ///< This NRC indicates that the server has not given security access because the key 
        /// sent by the client did not match with the key in the server's memory. This counts 
        /// as an attempt to gain security. The server shall remain locked and increment its 
        /// internal securityAccessFailed counter.
             
        EResponseCode_ExceedNumberOfAttempts   = 0x36U ,
        ///< This NRC indicates that the requested action will not be taken because the client 
        /// has unsuccessfully attempted to gain security access more times than the server's 
        /// security strategy will allow.
             
        EResponseCode_RequiredTimeDelayNotExpired = 0x37U ,
        ///< This NRC indicates that the requested action will not be taken because the client's 
        /// latest attempt to gain security access was initiated before the server's required 
        /// time-out period had elapsed.    
             
        EResponseCode_UploadDownloadNotAccepted = 0x70U ,
        ///< This NRC indicates that an attempt to upload/download to a server's memory 
        /// cannot be accomplished due to some fault conditions.
             
        EResponseCode_TransferDataSuspended = 0x71U ,
        ///< This NRC indicates that a data transfer operation was halted due to some fault. 
        /// The active transferData sequence shall be aborted.
            
        EResponseCode_GeneralProgrammingFailure = 0x72U ,
        ///< This NRC indicates that the server detected an error when erasing or programming 
        /// a memory location in the permanent memory device (e.g. Flash Memory).   

        EResponseCode_WrongBlockSequenceCounter    = 0x73U ,
        ///< This NRC indicates that the server detected an error in the sequence of 
        /// blockSequenceCounter values. Note that the repetition of a TransferData request 
        /// message with a blockSequenceCounter equal to the one included in the previous 
        /// TransferData request message shall be accepted by the server.
             
        EResponseCode_RequestCorrectlyReceivedResponsePending = 0x78U ,
        ///< This NRC indicates that the request message was received correctly, and that all 
        /// parameters in the request message were valid, but the action to be performed is 
        /// not yet completed and the server is not yet ready to receive another request.
             
        EResponseCode_SubFunctionNotSupportedInActive_Session    = 0x7EU ,
        ///< This NRC indicates that the requested action will not be taken because the server 
        /// does not support the requested sub-function in the session currently active.
             
        EResponseCode_ServiceNotSupportedInActiveSession  = 0x7FU ,
        ///< This NRC indicates that the requested action will not be taken because the server 
        /// does not support the requested service in the session currently active.
             
        EResponseCode_RpmTooHigh    = 0x81U ,
        ///< This NRC indicates that the requested action will not be taken because the server 
        /// prerequisite condition for RPM is not met (current RPM is above a preprogrammed 
        /// maximum threshold).    
             
        EResponseCode_RpmTooLow = 0x82U ,
        ///< This NRC indicates that the requested action will not be taken because the server  
        /// prerequisite condition for RPM is not met (current RPM is below a preprogrammed 
        /// minimum threshold).
             
        EResponseCode_EngineIsRunning   = 0x83U ,
        ///< This NRC is required for those actuator tests which cannot be actuated while the 
        /// Engine is running. This is different from RPM too high negative response, and  
        /// needs to be allowed.
            
        EResponseCode_EngineIsNotRunning   = 0x84U ,
        ///< This NRC is required for those actuator tests which cannot be actuated unless the 
        /// Engine is running. This is different from RPM too low negative response, and 
        /// needs to be allowed.
        
        EResponseCode_EngineRunTimeTooLow = 0x85U ,
        ///< This NRC indicates that the requested action will not be taken because the server 
        /// prerequisite condition for engine run time is not met (current engine run time is 
        /// below a pre-programmed limit).
        
        EResponseCode_TemperatureTooHigh    = 0x86U ,
        ///< This NRC indicates that the requested action will not be taken because the server 
        /// prerequisite condition for temperature is not met (current temperature is above a  
        /// pre-programmed maximum threshold).
        
        EResponseCode_TemperatureTooLow = 0x87U ,
        ///< This NRC indicates that the requested action will not be taken because the server 
        /// prerequisite condition for temperature is not met (current temperature is below a  
        /// pre-programmed minimum threshold).
        
        EResponseCode_VehicleSpeedTooHigh  = 0x88U ,
        ///< This NRC indicates that the requested action will not be taken because the server 
        /// prerequisite condition for vehicle speed is not met (current VS is above a preprogrammed 
        /// maximum threshold).
        
        EResponseCode_VehicleSpeedTooLow   = 0x89U ,
        ///< This NRC indicates that the requested action will not be taken because the server 
        /// prerequisite condition for vehicle speed is not met (current VS is below a preprogrammed 
        /// minimum threshold).
        
        EResponseCode_ThrottlePedalTooHigh = 0x8AU ,
        ///< This NRC indicates that the requested action will not be taken because the server 
        /// prerequisite condition for throttle/pedal position is not met (current TP/APP is  
        /// above a pre-programmed maximum threshold). 
        
        EResponseCode_ThrottlePedalTooLow  = 0x8BU ,
        ///< This NRC indicates that the requested action will not be taken because the server 
        /// prerequisite condition for throttle/pedal position is not met (current TP/APP is  
        /// below a pre-programmed minimum threshold).
        
        EResponseCode_TransmissionRangeNotInNeutral   = 0x8CU ,
        ///< This NRC indicates that the requested action will not be taken because the server  
        /// prerequisite condition for being in neutral is not met (current transmission range is 
        /// not in neutral).
        
        EResponseCode_TransmissionRangeNotInGear  = 0x8DU ,
        ///< This NRC indicates that the requested action will not be taken because the server 
        /// prerequisite condition for being in gear is not met (current transmission range is 
        /// not in gear).
        
        EResponseCode_BrakeSwitchNotClosed = 0x8FU ,
        ///< This NRC indicates that for safety reasons, this is required for certain tests before 
        /// it begins, and must be maintained for the entire duration of the test.
        
        EResponseCode_ShifterLeverNotInPark   = 0x90U ,
        ///< This NRC indicates that for safety reasons, this is required for certain tests before 
        /// it begins, and must be maintained for the entire duration of the test.
        
        EResponseCode_TorqueConverterClutchLocked  = 0x91U ,
        ///< This NRC indicates that the requested action will not be taken because the server 
        /// prerequisite condition for torque converter clutch is not met (current TCC status  
        /// above a pre-programmed limit or locked).
        
        EResponseCode_VoltageTooHigh    = 0x92U ,
        ///< This NRC indicates that the requested action will not be taken because the server 
        /// prerequisite condition for voltage at the primary pin of the server (ECU) is not met 
        /// (current voltage is above a pre-programmed maximum threshold).
        
        EResponseCode_VoltageTooLow = 0x93U,
        ///< This NRC indicates that the requested action will not be taken because the server
        /// prerequisite condition for voltage at the primary pin of the server (ECU) is not met 
        /// (current voltage is below a pre-programmed maximum threshold).      
        
        EResponseCode_Last=0xffU
        ///< Guard
        
    }EResponseCode_t;
    
    ///
    /// @brief This method should be invoked by UDS service Manager on Init . This method should be implemented by each 
    ///        UDS service handlers for registering the services and its configuration.
    ///
    virtual void serviceInitialize(void)=0;
};

} // udsblservices
} // app
} // dk

#endif  //DK_SRVC_UDS_SERVICE_HANLER_IF_H
