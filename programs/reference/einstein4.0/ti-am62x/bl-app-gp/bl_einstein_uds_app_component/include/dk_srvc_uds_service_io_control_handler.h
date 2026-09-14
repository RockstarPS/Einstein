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
/// @file dk_srvc_uds_service_IO_control_handler.h
/// @ingroup UdsServices
///
/// @brief  CUdsServiceIOControlHandler Class. It implements the the IOControl (0x31) service.
///
/// The IOControl service is used by the client to execute a defined sequence of steps and obtain any
/// relevant results. There is a lot of flexibility with this service, but typical usage may include functionality
/// such as erasing memory, resetting or learning adaptive data, running a self-test, overriding the normal server
/// control strategy, and controlling a server value to change over time including predefined sequences (e.g., close
/// convertible roof) to name a few. In general, when used to control outputs this service is used for more
/// complex type control whereas inputOutputControlByIdentifier is used for relatively simple (e.g., static) output
/// control.
///The IOControl service is used by the client to:
///     -# start a IO,
///     -# stop a IO, and
///     -# request IO results
/// A IO is referenced by a 2-byte IOIdentifier.
//---------------------------------------------------------------------------------------------------------------------
#ifndef DK_SRVC_UDS_SERVICE_IO_CONTROL_HANDLER_H
#define DK_SRVC_UDS_SERVICE_IO_CONTROL_HANDLER_H
#include "dk_srvc_uds_service_handler_if.h"
#include "dk_srvc_uds_service_manager_if.h"
#include "dk_runtime_bl_einstein_uds_app_component.h"

namespace dk
{
namespace app
{
namespace udsblservices
{
class CUdsServiceIOControlHandler : public CUdsServiceHandlerIf
{
public:

    ///
    /// @brief It defines the IO values . This value is the index in the IO configuration table.
    ///
    typedef enum
    {
        //EIO_SoftwareUpdate= 0, ///< Software update 0xF000u
        // EIO_SwitchNewVersion,  ///< Switch version 0xF001u
        //EIO_RollBackPreviousVersion,   ///< Roll back version 0xF002u
        //EIO_RemovePreviousVersion, ///< Remove previous version 0xF003u
        EIO_ProgramCheck=0, ///< Program Check 0xF000u
        EIO_RunDtcTest, ///< DTC test 0xF006u
        EIO_Last   ///< Guard
    } EIOConfigIndex_t;

    ///
    /// @brief This method is the IOControl (0x31) service handler initialization IO.This method should be
    ///        invoked by UDS service Manager on Init .
    ///
    void serviceInitialize(void);

    ///
    /// @brief This method is used to set the UDS service Manager instance reference for the IOControl (0x31)
    ///        service handler.
    ///
    /// @param[in] pUdsServiceManagerIf pointer to the UDS service manager Instance.
    ///
    explicit CUdsServiceIOControlHandler
    (
        CUdsServiceManagerIf &serviceManagerInstance
    ):mServiceManagerInstance(serviceManagerInstance)
    {

    }
    ~CUdsServiceIOControlHandler()
    {

    }

    //void setServiceManagerIf(CUdsServiceManagerIf * pUdsServiceManagerIf);

    ///
    /// @brief This method should be called on reception of installer response for request IO.
    ///
    /// @param[in] IOIndex index of IO ID
    /// @param[in] responseCode reponse status from the installer
	
private:

    ///
    /// @brief It defines the sub function value supported by IO Control(0x31) services.
    ///
    typedef enum
    {
        IOControlParameter_returnControlToECU,       ///< start IO sub function value.
        IOControlParameter_resetToDefault,           ///< stop IO sub function value.
        IOControlParameter_freezeCurrentState,       ///< Request results sub function value.
        IOControlParameter_shortTermAdjustment,      ///< Guard
        IOControlParameter_Last
    } EIOControlParameter_t;

    ///
    /// @brief It defines the configuration parameters for the IO Id.
    ///
    typedef struct
    {
        uint16_t    mDidId;                       ///< supported IO identifier value.It is a 2 byte value.
        uint16_t    mRequestStateLength;               ///< Supported sub function mask of the IO Id.
        uint16_t    mResponseStateLength ;
    } SIOControlDIdConfig_t;

    uint16_t mClientAddress = 0xFFFFU ;
    uint16_t mRecord_U16;
    uint8_t mDtcnumber_U8;
    uint16_t mIOId; // requested IO ID

    ///
    /// @brief It defines the list of IO Id supported and its properties.
    ///
    const SIOControlDIdConfig_t mDidIdConfig[16]=
    {
        {
            0xFE01u,
            1,
            1
        },
        {
            0xFE12u,
            2,
            2
        },
        {
            0xFE3Fu,
            4,
            4
        },
        {
            0xFE44u,
            1,
            1
        },
        {
            0xFD42u,
            2,
            2
        },
        {
            0xFE31u,
            3,
            3
        },
        {
            0xFE0Bu,
            2,
            2
        },
        {
            0xFE0Au,
            4,
            4
        },
        {
            0xFD40u,
            7,
            7
        },
        {
            0xFD0Eu,
            3,
            3
        },
        {
            0xFE1Au,
            1,
            1
        },
        {
            0xB1EDu,
            2,
            2
        },
        //New did addition from here.

        {
            0x4000u,
            3,
            3
        },
        {
            0x4001u,
            3,
            3
        },
        {
            0xFE08u,
            3,
            2
        },
        {
            0xFE35,
            1,
            0
        }


    };

    ///
    /// @brief It defines the IO Control(0x31) service configurations values.This value should be configured at
    ///         serviceInitialize and should be passed to CUdsServiceManager to register the configuration.
    ///
    SServiceConfig_t mIOControlServiceConfig;


    ///
    /// @brief It holds the reference of CUdsServiceManager instance to which it was registered. This instance is used
    ///        by the service to update the positive and negative responses.
    ///
    //CUdsServiceManagerIf * mpServiceManagerInstance;
    CUdsServiceManagerIf &mServiceManagerInstance;

    ///
    /// @brief This method handles the IO Control(0x31) service request . The method should be set as
    ///        request handler callback  function for IO Control(0x31) service.This method updates positive
    ///        or negative response based on the request.
    ///
    /// @param[in] pRequestData  pointer to request data length
    /// @param[in] requestLength  size of the requested data.
    ///
    void IOControlRequestHandler(const uint16_t clientAddress,const uint8_t *const pRequestData,uint16_t requestLength);

    ///
    /// @brief This method handles the post response functionality of IO Control(0x31) service.This method is
    ///         configured as post response handler callback  function for IO Control(0x31) service.
    ///
    void IOControlPostresponseHandler(const uint16_t clientAddress);

    ///
    /// @brief This method handles the reset handler of IO Control(0x31) service.This method will set internal
    ///        status to initial value.This method is configured as reset handler callback function for IO
    ///        Control(0x31) service.
    ///
    void IOControlResetHandler(const uint16_t clientAddress);

    ///
    /// @brief This method process the IO sub function request and initiate the corresponding handler for
    ///         sub function IO.
    ///
    /// @param[in] IOId IO index value.
    /// @param[in] IOSubFunction IO sub function value.
    /// @param[in] pIOInfobuffer pointer to IO Information.
    /// @param[in] IOInfoLength size of the IO Information.
    ///
    CUdsServiceHandlerIf::EResponseCode_t processIORequest
    (
        uint8_t index,
        uint16_t DidId,
        const uint8_t * const pIOInfobuffer,
        uint16_t IOInfoLength
    );

    CUdsServiceHandlerIf::EResponseCode_t processIOResponse
    (
        uint8_t index,
        uint16_t DidId,
        const uint8_t * const pIOCntrlOp,
        uint16_t IOCntrlOpLenth,
        const uint8_t * const pIOInfobuffer,
        uint16_t IOInfoLength
    );


};
} // udsblservices
} // app
} // dk
#endif  //DK_SRVC_UDS_SERVICE_IO_CONTROL_HANDLER_H
