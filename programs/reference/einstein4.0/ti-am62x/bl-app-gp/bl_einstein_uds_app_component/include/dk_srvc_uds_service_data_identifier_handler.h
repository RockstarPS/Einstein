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

private:
    /// @TODO enum type should be moved to dk_types
    typedef enum : uint8_t
    {
        EDidAccessType_Read=0,
        EDidAccessType_Write,
        EDidAccessType_Last
    } EDidAccessType_t;

    ///
    /// @brief It defines the index value of supported DID in the configuration table.
    ///
    typedef enum
    {
        EDidConfigIndex_ReadSocVersion = 0,
        EDidConfigIndex_Dummy,

        EDidConfigIndex_Last = 23    ///< Guard
    } EDidConfigIndex_t;

    ///
    /// @brief It defines the access type mask for the DID
    ///
    typedef enum
    {
        EWriteDidConfigIndex_DigestVIP = 0,
        EWriteDidConfigIndex_DigestGIP,
        EWriteDidConfigIndex_Last   ///< Guard
    } EWriteDidConfigIndex_t;
    typedef enum
    {
        EDidAccessTypeMask_Read=0x1U,        ///< Read access mask
        EDidAccessTypeMask_Write=0x2U,       ///< Write access mask
        EDidAccessTypeMask_ReadWrite=0x3U    ///< Read/Write access mask
    } EDidAccessTypeMask_t;

    ///
    /// @brief It defines the properties of each Data Identifier.
    ///
    typedef struct
    {
        uint16_t    mDidId;                      ///< 2 byte Data Identifier
        uint16_t    mDidLength;                  ///< Size of the Data Identifier
        uint32_t    mSupportedAccessTypeMask;    ///< Supported Access type mask of the Data Identifier.
        uint32_t    mSupportedSessionMask;       ///< Supported session mask of the Data Identifier.
        uint32_t    mSupportedSecurityMask;      ///< Supported security mask of the Data Identifier.
    } SDidConfiguration_t;


    typedef struct
    {
        uint16_t clientAddress; ///< DID requested client address
        uint16_t mDidId;    ///< DID value
        std::vector<uint8_t> data; ///< DID request/response data.
    } SDidProcessingStatus_t;




    ///
    /// @brief It contains the current list of DIDs processing and its state.<<Future use >>
    ///
    std::vector<SDidProcessingStatus_t> SDidProcessingStatus;

    ///
    /// @brief Client address to be stored in global variable.
    ///

    uint16_t mClientAddress = 0xFFFFU ;


    ///
    /// @brief It defines the list of supported Data Identifiers and its properties.
    ///
    const SDidConfiguration_t mDidConfigurationTable[49]=
    {
        ///< SOC Read version
        {
            0xFE02,
            3U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        ///< Dummy configuration for test purpose.
        {
            0xFD3B,
            25U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },

        ///< Dummy configuration for test purpose.
        {
            0xFE30,
            21U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0xFE10,
            4U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0xFE0C,
            3U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0xFE0E,
            4U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0xFEC8,
            23U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0xFE13,
            4U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },

        {
            0xFD3B,
            25U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0xFD08,
            3U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },

        {
            0xFD04,
            3U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },

        {
            0xFD45,
            9U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },

        {
            0xFD02,
            20U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },

        {
            0xFD07,
            3U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0xFD01,
            17U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },

        {
            0xFD00,
            17U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0xFD60,
            2U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },

        {
            0xFD68,
            27U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0xFD6B,
            2U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },

        {
            0xFD66,
            96U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },

        {
            0xFD05,
            6U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },

        {
            0xFED6,
            3U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },

        {
            0xFD12,
            6U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0xFE81,
            8U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0xB1ED,
            4U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        //New Did addition from here.

        {
            0x1000,
            3U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0x100A,
            1U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0x100B,
            24U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0x37FE,
            18U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0x8002,
            3U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0xF100,
            4U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0xF150,
            3U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0xF152,
            2U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0xF186,
            1U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0xF18B,
            3U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0xF18C,
            10U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0x4002,
            8U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0x4010,
            15U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0x4011,
            8U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0x4012,
            8U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0x4013,
            26U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0xF190,
            17U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0xFDBD,
            8U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        {
            0xFD50,
            4U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
		{
            0xFE14,
            96U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
		{
            0xFE1B,
            28U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
		{
            0xFE1D,
            2U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
		{
            0xFE26,
            1U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
		{
            0xFE60,
            2U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Read,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        }


    };



    const SDidConfiguration_t mWriteDidConfigurationTable[20]=
    {

        {
            0xFD04u,
            3U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Write,
            ESessionMask_t::ESessionMask_AllSession,
            ESecurityMask_t::ESecurityMask_AllLevel
        },
        {
            0xFD45u,
            9U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Write,
            ESessionMask_t::ESessionMask_AllSession,
            ESecurityMask_t::ESecurityMask_AllLevel
        },
        {
            0xFD02u,
            10U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Write,
            ESessionMask_t::ESessionMask_AllSession,
            ESecurityMask_t::ESecurityMask_AllLevel
        },
        {
            0xFD07u,
            3U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Write,
            ESessionMask_t::ESessionMask_AllSession,
            ESecurityMask_t::ESecurityMask_AllLevel
        },
        {
            0xFD01u,
            17U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Write,
            ESessionMask_t::ESessionMask_AllSession,
            ESecurityMask_t::ESecurityMask_AllLevel
        },
        {
            0xFD00u,
            17U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Write,
            ESessionMask_t::ESessionMask_AllSession,
            ESecurityMask_t::ESecurityMask_AllLevel
        },
        {
            0xFD60u,
            2U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Write,
            ESessionMask_t::ESessionMask_AllSession,
            ESecurityMask_t::ESecurityMask_AllLevel
        },
        {
            0xFD6Bu,
            2U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Write,
            ESessionMask_t::ESessionMask_AllSession,
            ESecurityMask_t::ESecurityMask_AllLevel
        },
        {
            0xFD66u,
            25U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Write,
            ESessionMask_t::ESessionMask_AllSession,
            ESecurityMask_t::ESecurityMask_AllLevel
        },
        {
            0xFD05u,
            3U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Write,
            ESessionMask_t::ESessionMask_AllSession,
            ESecurityMask_t::ESecurityMask_AllLevel
        },
        {
            0xFD12u,
            4U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Write,
            ESessionMask_t::ESessionMask_AllSession,
            ESecurityMask_t::ESecurityMask_AllLevel
        },
        {
            0xFD08,
            3U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Write,
            ESessionMask_AllSession,
            ESecurityMask_AllLevel
        },
        //New  Did addition from here.

        {
            0x1000,
            3U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Write,
            ESessionMask_t::ESessionMask_AllSession,
            ESecurityMask_t::ESecurityMask_AllLevel
        },
        {
            0x100B,
            24U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Write,
            ESessionMask_t::ESessionMask_AllSession,
            ESecurityMask_t::ESecurityMask_AllLevel
        },

        {
            0xF15A,
            4U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Write,
            ESessionMask_t::ESessionMask_AllSession,
            ESecurityMask_t::ESecurityMask_AllLevel
        },
        {
            0xF190,
            17U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Write,
            ESessionMask_t::ESessionMask_AllSession,
            ESecurityMask_t::ESecurityMask_AllLevel
        },
        {
            0xFE1B,
            28U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Write,
            ESessionMask_t::ESessionMask_AllSession,
            ESecurityMask_t::ESecurityMask_AllLevel
        },
        {
            0xFE1D,
            2U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Write,
            ESessionMask_t::ESessionMask_AllSession,
            ESecurityMask_t::ESecurityMask_AllLevel
        },
        {
            0xFE26,
            1U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Write,
            ESessionMask_t::ESessionMask_AllSession,
            ESecurityMask_t::ESecurityMask_AllLevel
        },
        {
            0xFE60,
            2U,
            EDidAccessTypeMask_t::EDidAccessTypeMask_Write,
            ESessionMask_t::ESessionMask_AllSession,
            ESecurityMask_t::ESecurityMask_AllLevel
        }


    };


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
    /// @brief Process R-W response message.
    ///
    /// @param[in] clientAddress requested client address.
    ///
    void processRWResponse( uint8_t index,uint16_t DidId, const uint8_t * const pRWInfobuffer, uint16_t RWInfoLength );

};

} // udsblservices
} // app
} // dk

#endif  //DK_SRVC_UDS_SERVICE_DATA_IDENTIFIER_HANDLER_H
