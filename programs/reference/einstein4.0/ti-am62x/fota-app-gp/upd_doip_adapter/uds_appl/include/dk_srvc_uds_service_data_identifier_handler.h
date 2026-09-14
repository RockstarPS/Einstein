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
/// @file dk_srvc_uds_service_data_identifier_handler.h
/// @ingroup UdsBlServices
///
/// @brief  CUdsServiceDataIdentifierHandler Class. It implements the the ReadDataByIdentifier (0x31) service.
///
/// The ReadDataByIdentifier service allows the client to request data record values from the server identified by
/// one or more dataIdentifiers.The client request message contains one or more two byte dataIdentifier values that 
/// identify data record(s) maintained by the server . The format and definition of the
/// dataRecord shall be vehicle manufacturer or system supplier specific, and may include analog input and
/// output signals, digital input and output signals, internal data, and system status information if supported by the
/// server.
//---------------------------------------------------------------------------------------------------------------------
#ifndef DK_SRVC_UDS_SERVICE_DATA_IDENTIFIER_HANDLER_H
#define DK_SRVC_UDS_SERVICE_DATA_IDENTIFIER_HANDLER_H
#include "dk_srvc_uds_service_handler_if.h"
#include "dk_srvc_uds_service_manager_if.h"

namespace dk
{
namespace app
{
namespace udsblservices
{

class CUdsServiceDataIdentifierHandler : public CUdsServiceHandlerIf
{
public:    
    


    /// 
    /// @brief Constructor of CUdsServiceDataIdentifierHandler.
    ///
    /// param[in]  reference of serviceManager instance
    ///
    explicit CUdsServiceDataIdentifierHandler
    (
        CUdsServiceManagerIf &serviceManagerInstance
    ):mServiceManagerInstance(serviceManagerInstance)
    {
        
    }
    
    /// 
    /// @brief Destructor of CUdsServiceDataIdentifierHandler.
    ///
    ~CUdsServiceDataIdentifierHandler()
    {
        
    }
    
    ///
    /// @brief This method is the ReadDataByIdentifier (0x31) service handler initialization routine.This method 
    ///        should be  invoked by UDS service Manager on Init . 
    ///
    virtual void serviceInitialize(void);

    ///
    /// @brief This method is used to update the response received for DID request from VIP.
    ///
    ///
    static void dataIdentifierdiagTunnelCallback(void* instancePointer, uint8_t result);

							  
private:
    /// @TODO enum type should be moved to dk_types 
    typedef enum : uint8_t
    {
        EDidAccessType_Read=0,
        EDidAccessType_Write,
        EDidAccessType_Last
    } EDidAccessType_t;
    
    ///
    /// @brief It defines the client address of the currently processing request.
    ///
    uint16_t mClientAddress = 0xFFFFU ;

    ///
    /// @brief It defines the index value of supported DID in the configuration table.
    ///
    typedef enum
    {
    	EDidConfigIndex_RequestFingerprint = 0,
    	EDidConfigIndex_RequestIndexSrvData,
    	EDidConfigIndex_RequestOperationalRef,
    	EDidConfigIndex_RequestSecOperationalRef,
        EDidConfigIndex_VirginFlag,
    	EDidConfigIndex_RequestBootVersion,
    	EDidConfigIndex_RequestVehicleManufacturerSparePartNumber_R,
    	EDidConfigIndex_RequestSystemSupplierIdentifier,
    	EDidConfigIndex_RequestECUSerialNumber,
    	EDidConfigIndex_RequestVehicleManufacturerECUHardwareNumber,
    	EDidConfigIndex_RequestVehicleManufacturerSparePartNumber_N,
		EDidConfigIndex_DigestVIP,
		EDidConfigIndex_DigestGIP,
        EDidConfigIndex_DigestSpecial,
        EDidConfigIndex_Last    ///< Guard
    }EDidConfigIndex_t;
    
    ///
    /// @brief It defines the access type mask for the DID
    ///
    typedef enum
    {
        EDidAccessTypeMask_Read=0x1U,        ///< Read access mask
        EDidAccessTypeMask_Write=0x2U,       ///< Write access mask
        EDidAccessTypeMask_ReadWrite=0x3U    ///< Read/Write access mask
    }EDidAccessTypeMask_t;
    
    ///
    /// @brief It defines the properties of each Data Identifier.
    ///
    typedef struct
    {
        uint16_t    mDidId;                      ///< 2 byte Data Identifier 
        uint16_t    mDidLength;                  ///< Size of the Data Identifier
        uint32_t    mSupportedAccessTypeMask;    ///< Supported Access type mask of the Data Identifier.
        uint32_t    mSupportedSessionMask;       ///< Supported session mask of the Data Identifier.
        CUdsServiceHandlerIf::ESecurityMask_t   mSupportedSecurityMask;      ///< Supported security mask of the Data Identifier.
    }SDidConfiguration_t;
    
    
    typedef struct
    {
        uint16_t clientAddress; ///< DID requested client address
        uint16_t mDidId;    ///< DID value
        std::vector<uint8_t> data; ///< DID request/response data.
    }SDidProcessingStatus_t;
    
    
	typedef struct
	{
		uint8_t fileName[256];
		int32_t totFileSize;
		int32_t downloadedSize;
		int32_t remSize;
	}SfileInfo_t;
	
	SfileInfo_t fInfoRd;

	
    ///
    /// @brief It contains the current list of DIDs processing and its state.
    ///
    std::vector<SDidProcessingStatus_t> SDidProcessingStatus;
    
    ///
    /// @brief It defines the list of supported Data Identifiers and its properties.
    /// 
    const SDidConfiguration_t mDidConfigurationTable[EDidConfigIndex_Last]=
    {
    		///data identifier of Virgin flag as 0xF062u
            {
                0xF062,
                3U,
                EDidAccessTypeMask_ReadWrite,
                ESessionMask_AllSession,
    		    ESecurityMask_AllLevel
    		},
			{
				0xFD00u,
				258U,
				EDidAccessTypeMask_ReadWrite,
			    ESessionMask_AllSession,
			    ESecurityMask_AllLevel
			},
			///data identifier of GIP Read/Write Digest as 0xFD01u.
			{
				0xFD01u,
				258U,
				EDidAccessTypeMask_ReadWrite,
				ESessionMask_AllSession,
				ESecurityMask_AllLevel
			},
            ///data identifier of Special Read/Write Digest as 0xFDFFu.
			{
				0xFDFFu,
				258U,
				EDidAccessTypeMask_ReadWrite,
				ESessionMask_AllSession,
				ESecurityMask_AllLevel
			}
    };

    const uint8_t mBootVersion[32] = {0x01, 'S',  'W',  '_',  'B',  'O',  'O',  'T',  '_',  '0',  '1',  '.',  '0',  '1',  '.',  '0', '1', 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20};

    const uint8_t mSparePartNumberRenault[10] = {0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30};

    const uint8_t mSparePartNumberNissan[10] = {0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30};

    const uint8_t mGipDigestData[34] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

    const uint8_t mSystemSupplierIdentifier[4] = {0x32, 0x4C, 0x31, 0x37};

    const uint8_t mECUSerialNumber[20] = {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20};

    const uint8_t mVehicleManufacturerECUHardwareNumber[10] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

    const uint8_t mOperationnalReference[10] = {0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30};

    const uint8_t mSecondOperRef[10] = {0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30};

    const uint8_t mFingerprint[16] = { ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' '};
    const uint8_t mIndexSrvcData[10]={0x50, 0x52, 0x4f, 0x54, 0x41, 0x53, 0x59, 0x4d, 0x56, 0x32};

    
    bool mdigestRespPendingVIPStatus=false;

    ///
    /// @brief It defines the current processing DID value.
    ///
    uint16_t currentRequestedDid = 0x0000U;
    
    ///
    /// @brief It defines the current processing DID Index.
    ///
    uint8_t currentDidConfigIndex = 0x00U;

    ///
    /// @brief It defines the ReadDataByIdentifier(0x22) service configurations values.This value should be 
    ///        configured at serviceInitialize and should be passed to CUdsServiceManager to register the configuration.
    ///
    SServiceConfig_t mReadDataIdentifierServiceConfig;
    
    ///
    /// @brief It defines the WriteDataByIdentifier(0x2E) service configurations values.This value should be 
    ///        configured at serviceInitialize and should be passed to CUdsServiceManager to register the configuration.
    ///
    SServiceConfig_t mWriteDataIdentifierServiceConfig;

    ///
    /// @brief It holds the reference of CUdsServiceManager instance to which it was registered. This instance is used 
    ///        by the service to update the positive and negative responses.
    ///
    CUdsServiceManagerIf &mServiceManagerInstance;

    ///
    /// @brief This method handles the ReadDataByIdentifier (0x31) service request . The method should be set as 
    ///        request handler callback  function for ReadDataByIdentifier (0x31) service.This method updates positive 
    ///        or negative response based on the request.
    ///
    /// @param[in] clientAddress requested client address.
    /// @param[in] pRequestData  pointer to request data length
    /// @param[in] requestLength  size of the requested data.
    ///
    void readDataIdentifierRequestHandler(const uint16_t clientAddress,const uint8_t * const pRequestData,const uint16_t requestLength);
    
    ///
    /// @brief This method handles the post response functionality of ReadDataByIdentifier (0x31) service.This method  
    ///         is configured as post response handler callback  function for ReadDataByIdentifier (0x31) service.
    ///
    /// @param[in] clientAddress requested client address.
    ///
    void readDataIdentifierPostresponseHandler(const uint16_t clientAddress);
    
    ///
    /// @brief This method handles the reset handler of ReadDataByIdentifier (0x31) service.This method will set  
    ///        internal status to initial value.This method is configured as reset handler callback function for  
    ///        ReadDataByIdentifier (0x31) service.
    ///
    /// @param[in] clientAddress requested client address.
    ///
    void readDataIdentifierResetHandler(const uint16_t clientAddress);
    
    ///
    /// @brief This method handles the ReadDataByIdentifier (0x31) service request . The method should be set as 
    ///        request handler callback  function for ReadDataByIdentifier (0x31) service.This method updates positive 
    ///        or negative response based on the request.
    ///
    /// @param[in] clientAddress requested client address.
    /// @param[in] pRequestData  pointer to request data length
    /// @param[in] requestLength  size of the requested data.
    ///
    void writeDataIdentifierRequestHandler(const uint16_t clientAddress,const uint8_t *const pRequestData,const uint16_t requestLength);
    
    ///
    /// @brief This method handles the post response functionality of ReadDataByIdentifier (0x31) service.This method  
    ///         is configured as post response handler callback  function for ReadDataByIdentifier (0x31) service.
    ///
    /// @param[in] clientAddress requested client address.
    ///
    void writeDataIdentifierPostresponseHandler(const uint16_t clientAddress);
    
    ///
    /// @brief This method handles the reset handler of ReadDataByIdentifier (0x31) service.This method will set  
    ///        internal status to initial value.This method is configured as reset handler callback function for  
    ///        ReadDataByIdentifier (0x31) service.
    ///
    /// @param[in] clientAddress requested client address.
    ///
    void writeDataIdentifierResetHandler(const uint16_t clientAddress);  
    
    ///
    /// @brief This method handles the requested Data Identifiers . This method gets data from the corresponding client
    ///         for the data.
    ///
    /// @param[in] didconfigIndex Data Identifier index value.
    /// @param[in] didValue Data Identifier value.
    /// @param[in] didLength size of the requested DID.
    ///
    CUdsServiceHandlerIf::EResponseCode_t processReadDidRequest
    (
        const EDidConfigIndex_t didconfigIndex,
        const uint16_t didValue,
        const uint16_t didLength
    );
    
    ///
    /// @brief This method handles the requested Data Identifiers . This method gets data from the corresponding client
    ///         for the data.
    ///
    /// @param[in] didconfigIndex Data Identifier index value.
    /// @param[in] didValue Data Identifier value.
    /// @param[in] didLength size of the requested DID.
    /// @param[in] requested data for the DID.
    ///
    CUdsServiceHandlerIf::EResponseCode_t processWriteDidRequest
    (
        const EDidConfigIndex_t didconfigIndex,
        const uint16_t didValue,
        const uint16_t didLength,
        const uint8_t * const pDidData
    );

};

} // udsblservices
} // app
} // dk

#endif  //DK_SRVC_UDS_SERVICE_DATA_IDENTIFIER_HANDLER_H
