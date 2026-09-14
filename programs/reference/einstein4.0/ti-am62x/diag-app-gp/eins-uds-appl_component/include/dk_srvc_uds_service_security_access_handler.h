//---------------------------------------------------------------------------------------------------------------------
///
/// @file dk_srvc_uds_service_security_access_handler.h
/// @ingroup UdsBlServices
///
/// @brief  CUdsServiceSecurityAccessHandler Class. It implements the the SecurityAccess (0x27) service.
///
/// The purpose of this service is to provide a means to access data and/or diagnostic services, which have
/// restricted access for security, emissions, or safety reasons. Diagnostic services for downloading/uploading
/// routines or data into a server and reading specific memory locations from a server are situations where
/// security access may be required. Improper routines or data downloaded into a server could potentially
/// damage the electronics or other vehicle components or risk the vehicleâ€™s compliance to emission, safety, or
/// security standards. The security concept uses a seed and key relationship.
/// A typical example of the use of this service is as follows:
///     -# client requests the â€œSeedâ€�,
///     -# server sends the â€œSeedâ€�,
///     -# client sends the â€œKeyâ€� (appropriate for the Seed received),
///     -# server responds that the â€œKeyâ€� was valid and that it will unlock itself.
///
#ifndef DK_SRVC_UDS_SERVICE_IOCONTROL_HANDLER_H
#define DK_SRVC_UDS_SERVICE_IOCONTROL_HANDLER_H

#include <utility>
#include <vector>
#include <map>
#include <cstdint>
#include "CryptoRSA.h"
#include <jsonRWAccessor.h>
#include "dk_srvc_uds_service_handler_if.h"
#include "dk_srvc_uds_service_manager_if.h"

namespace dk
{
namespace app
{
namespace udsblservices
{


class CUdsServiceSecurityAccessHandler : public CUdsServiceHandlerIf
{
public:

    ///
    /// @brief It defines the sub function value supported by Security Access(0x27) services.
    ///
    typedef enum
    {
        ESecurityAccessSubFunction_ReqSeed=0x01u,      ///< RequestSeed with the level of security defined by the vehicle manufacturer.
        ESecurityAccessSubFunction_SendKey = 0x02u, ///< SendKey with the level of security defined by the vehicle manufacturer.
        ESecuritySubFunction_Last             ///< Guard
    } ESecuritySubFunction_t;

    ///
    /// @brief This method is the SecurityAccess (0x27) service handler initialization routine.This method should be
    ///        invoked by UDS service Manager on Init .
    ///
    void serviceInitialize(void);


    bool UDSStartDelayTimer(void);



    bool UDSStopDelayTimer(void);

    ///
    /// @brief This method is used to set the UDS service Manager instance reference for the SecurityAccess (0x27)
    ///        service handler.
    ///
    /// @param[in] pUdsServiceManagerIf pointer to the UDS service manager Instance.
    ///
    explicit CUdsServiceSecurityAccessHandler
    (
        CUdsServiceManagerIf &serviceManagerInstance
    ):mpServiceManagerInstance(serviceManagerInstance)
    {

    }
    ~CUdsServiceSecurityAccessHandler()
    {

    }

    ///
    /// @brief Read DID Response from VIP
    /// @param[in] msg  pointer to  BlDiagResponse
    ///
    void readDidResponseUpdateFrmVIP(BlDiagResponse & msg );

    ///
    /// @brief It defines the state of seed-key lock//unlock Counter
    ///        false -> key unlocked
    ///         tue -> key locked
    ///
    static bool mKeyUnlocked;

    const uint16_t mDelayCounterInSec = 960U;

private:
    ///
    /// @brief It defines the security request state .This state is used to check the security access request sequence.
    ///
    typedef enum
    {
        ESecurityAccessState_WaitForSeed=0u,    ///< It defines the wait for seed state . In this state the request
        /// seed sub function is processed.
        ESecurityAccessState_WaitForKey,        ///< It defines the wait for key state . In this state the verify
        /// key sub function is processed.
        ESecurityAccessState_Last,              ///< Guard
    } ESecurityAccessState_t;

    ///
    /// @brief It defines the configuration parameters for each security level.
    ///
    typedef struct
    {
        uint8_t     mRequestSeedSubFunctionValue; ///< request seed sub function value of security level .
        uint32_t    mSupportedSessionMask;        ///< Supported session mask of security level .
        uint32_t    mSupportedSecurityMask;       ///< Supported security mask of security level .
    } SSecuritySubFunctionConfig_t;

    ///
    /// @brief It defines the configuration table for each security level supported.
    ///
    const SSecuritySubFunctionConfig_t mSecuritySubFunctionConfig[ESecurityLevel_Last-1u]=
    {
        {
            ///< ESecurityLevel_L1
            0x1,                            ///< request seed sub function value of ESecurityLevel_L1 .
            ESessionMask_ExtenededSession,  ///< Supported session mask of ESecurityLevel_L1 .
            ESecurityMask_AllLevel          ///< Supported security mask of ESecurityLevel_L1 .
        },
        {
            ///< ESecurityLevel_L3
            0x3,                            ///< request seed sub function value of ESecurityLevel_L3 .
            ESessionMask_ExtenededSession,  ///< Supported session mask of ESecurityLevel_L3 .
            ESecurityMask_AllLevel          ///< Supported security mask of ESecurityLevel_L3 .
        }
    };


    ///
    /// @brief  Length of the Random number (bytes) .
    ///
    const uint32_t mRandomNumLen = 32u;
    ///
    /// @brief It defines the key size for all security levels.
    ///
    const uint8_t mUdsSecurityKeySize = 16u;
    ///
    /// @brief It defines the client address of the currently processing request.
    ///
    uint16_t mClientAddress = 0xFFFFU ;

    ///
    /// @brief It defines the Length of seed key Increment Counter ( interm of bytes)
    ///
    const uint16_t mSeedIncrementCntrLen = 32u;

    ///
    /// @brief It defines the maximum retry of seed key
    ///
    const uint8_t mMaxRetries = 10u;

    timer_t timer1000ms_ID;


    ///
    /// @brief It defines the length of the ECU serial number "F18C" ( interm of bytes)
    ///
    const uint16_t mF18C_Did_length= 20u;

    ///
    /// @brief Length of raw seed before encryption ( interm of bytes)
    ///
    const  uint16_t mSeedKeyResponseLength = 32u +32u+2u+20u;

    ///
    /// @brief It Length of generated seed ( interm of bytes)
    ///
    const uint16_t mSeedLength = 256u;


    ///
    /// @brief It Length of generated key ( interm of bytes)
    ///
    const uint16_t mKeyLength = 256u;
    ///
    /// @brief mJsonRWPath : Path to read default value of the seed key increment counter.Store the Initial value
    ///
    const std::string mJsonRWDefaultPath = "/etc/rw_only_diag_params.json";

    ///
    /// @brief mJsonRWPath : Path to store seed key increment counter.
    ///
    const std::string mJsonRWPath = "/fota_cache/rw_only_diag_params.json";

    ///
    /// @brief It defines the Length of seed key Increment Counter ( interm of bytes)
    ///

    const std::string mJsonRD_ONLY_Path = "/etc/rd_only_diag_params.json";


    ///
    /// @brief VIP response state. Shall be set to true when VIP response is expected via UCL
    ///
    bool mVipResponsePending = false;


    ///
    /// @brief seed requested state.
    ///
    bool mSeedRequestFlag = false;

    ///
    /// @brief dummy seed request.
    ///
    bool mDummySeedFlag = false;
    ///
    /// @brief Length of random number to be fixed as a part of raw seed  ( interm of bytes)
    ///
    uint8_t mSeedRandomNumber[32];

    ///
    /// @brief Increment counter to be fixed as a part of raw seed  ( interm of bytes)
    ///
    uint8_t mSeedIncrementCntr[32];

    ///
    /// @brief requested sub function
    ///
    uint8_t mRequestedSubFcn = 0x0;



    uint8_t mtriggerDelayCounter = 0x01;


    uint8_t boot_flag = 1U;


    ///
    /// @brief Global counter for tracking number of attempt made for sending correct seed key
    ///
    uint8_t mMaxRetriesReached = 0u;




    ///
    /// @brief Instant of the crypto class. Used for Encryption/Decryption of seed & key
    ///
    CryptoRSA mCryptoRSA;

    ///
    /// @brief It defines the requested security level.
    ///
    CUdsServiceHandlerIf::ESecurityLevel_t mRequestedSecuritylevel;

    ///
    /// @brief It defines the request security subfunction
    ///

    uint8_t msecuritySubFunction;

    /// @brief It defines the SecurityAccess (0x27) service configurations values.This value should be configured at
    ///         serviceInitialize and should be passed to CUdsServiceManager to register the configuration.
    ///
    SServiceConfig_t mSecurityAccessServiceConfig;

    ///
    /// @brief It holds the reference of CUdsServiceManager instance to which it was registered. This instance is used
    ///        by the service to update the positive and negative responses.
    ///
    // CUdsServiceManagerIf * mpServiceManagerInstance;
    CUdsServiceManagerIf &mpServiceManagerInstance;
    ///
    /// @brief It defines the internal security request state which is used to validate the request.
    ///
    ESecurityAccessState_t mSecurityAccessState;

    ///
    /// @brief It defines the requested security level .This value is set when a seed is successfully transmitted
    ///        to request and this level is set as current security level when the key send by the tester is valid.
    ///
    CUdsServiceHandlerIf::ESecurityLevel_t mRequestedSecurityLevel;

    ///
    /// @brief This method handles the SecurityAccess (0x27) service request . The method should be set as
    ///        request handler callback  function for SecurityAccess (0x27) service.This method updates positive
    ///        or negative response based on the request.
    ///
    /// @param[in] pRequestData  pointer to request data length
    /// @param[in] requestLength  size of the requested data.
    ///
    void securityAccessRequestHandler(const uint16_t clientAddress, const uint8_t * const pRequestData,uint16_t requestLength);

    ///
    /// @brief This method handles the post response functionality of tester present service.This method is
    ///         configured as post response handler callback  function for tester present service.
    ///
    void securityAccessPostresponseHandler(const uint16_t clientAddress);

    ///
    /// @brief This method handles the reset handler of SecurityAccess (0x27) service.This method will set internal
    ///        status to initial value.This method is configured as reset handler callback function for tester present
    ///        service.
    ///
    void resetSecurityAccess(const uint16_t clientAddress);

    ///
    /// @brief This method handles the request seed sub function for the SecurityAccess (0x27) service of each security
    ///         level.
    ///
    /// @param[in] newSecurityLevel requested new security level
    /// @param[in] securitySubFunction sub function value of the requested new security level
    ///
    CUdsServiceHandlerIf::EResponseCode_t processSeedRequest (const uint16_t clientAddress, CUdsServiceHandlerIf::ESecurityLevel_t newSecurityLevel,
            uint8_t securitySubFunction );

    ///
    /// @brief This method handles the verify key sub function for the SecurityAccess (0x27) service of each security
    ///         level.
    ///
    /// @param[in] pKeyDataBuffer pointer to received key data buffer
    /// @param[in] keyDataLength  size of the received key data
    /// @param[in] securitySubFunction sub function value of the requested  security level
    ///
    CUdsServiceHandlerIf::EResponseCode_t processKeyRequest(const uint16_t clientAddress,const uint8_t * const pKeyDataBuffer,
            uint16_t keyDataLength,uint8_t securitySubFunction );

    ///
    /// @brief This method is used to generate a seed for the requested security level.
    ///
    /// @param[out] pSeedBuffer pointer to seed buffer . Generated seed value is updated in this buffer.
    /// @param[in] seedLength   size of the seed to be generated.
    /// @param[in] securitySubFunction sub function for which seed to be generated.
    ///
    CUdsServiceHandlerIf::EResponseCode_t requestSeed(uint8_t *pSeedBuffer,uint16_t seedLength,uint8_t securitySubFunction);

    ///
    /// @brief This method is used to verify the key for the requested security level.
    ///
    /// @param[in] pKeyBuffer pointer to received key data buffer.
    /// @param[in] keyLength   size of the received key data
    /// @param[in] securitySubFunction sub function for which key verification to be done.
    ///
    uint8_t verifyKey(const uint8_t * const pKeyBuffer,uint8_t keyLength,uint8_t securitySubFunction);

    ///
    /// @brief This method is to update/Compute Session Timer.
    /// @param[in] eSrvctypeID : Service Type.
    ///
    void updateCustomSessionTimerConfig(uint8_t eSrvctypeID );

    ///
    /// @brief This method is used to increment 256 bit seed key increment counter .
    /// @param[in/out] pMsgBuff : Buffer to increment the counter
    /// @param[in] pMsgBuff : Size of the buffer (in bytes).
    /// @param[out] "-1" failed "0" success
    ///
    int32_t update256bitInrementCounter(uint8_t *pMsgBuff, uint16_t lBufSize );

    ///
    /// @brief This method is used to inspect if max value reached  .
    /// @param[in/out] pMsgBuff : Buffer to increment the counter
    /// @param[in] pMsgBuff : Size of the buffer (in bytes).
    /// @param[out] "-1" failed "0" success
    ///
    int32_t isMaxValueNotReached(uint8_t *pMsgBuff, uint16_t lBufSize);

    ///
    /// @brief This method is used to verify key
    /// @param[in] pKeyDataBuffer :  Key sent from the tool
    /// @param[in] keyDataLength : size of the key
    /// @param[in] securitySubFunction : security sub function value
    /// @param[out] "-1" failed "0" success
    ///

    int32_t verifyKey( const uint8_t * const pKeyDataBuffer, uint16_t keyDataLength, uint8_t securitySubFunction);

    ///
    /// @brief This method is to compute seed and sent the value in intended format
    /// @param[in] msg :  Msg from VIP (UCL). On reception of  "0xF18C" serial number from VIP , seed is computed
    ///
    void prepareFormalSeedResponse(BlDiagResponse & msg );

    ///
    /// @brief This method is used to generate seed
    /// @param[in] msg :  Msg from VIP (UCL). On reception of  "0xF18C" serial number from VIP , seed is computed
    ///
    void processSeedGen(BlDiagResponse & msg );


    /// @brief This method is used update dummy seed
    /// @param[out] pSeed :  update the seed value
    /// @param[in] length : size of the seed(bytes)
    ///
    int32_t  genDummySeed( uint8_t &pSeed,  uint16_t length);

    /// @brief This method is used update dummy seed
    /// @param[out] pSeed :  update the seed value
    /// @param[in] length : size of the seed(bytes)
    ///
    int32_t genFormalSeed(void );


    static int8_t verifySecurityAccess(void);
};

} // udsblservices
} // app
} // dk
#endif  //DK_SRVC_UDS_SERVICE_SECURITY_ACCESS_HANDLER_H
