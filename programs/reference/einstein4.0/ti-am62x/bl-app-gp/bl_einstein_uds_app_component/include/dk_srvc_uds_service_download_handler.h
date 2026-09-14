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
/// @file dk_srvc_uds_service_download_handler.h
/// @ingroup UdsServices
///
/// @brief  CUdsServiceDownloadHandler Class. It implements the the download diagnostics service handlers.The 
///         requestDownload service is used by the client to initiate a data transfer from the client to the server
///         (download).
///
/// TUdsServiceDownloadHandler implements the following services,
///     -# RequestFileTransfer (0x38) service
///     -# TransferData (0x36) service
///     -# RequestTransferExit (0x37) service
///
/// RequestFileTransfer (0x38) service:
/// The requestFileTransfer service is used by the client to initiate a file data transfer from either the client to the
/// server or from the server to the client (download or upload). Additionally, this service has capabilities to
/// retrieve information about the file system.
/// This service is intended as an alternative solution to the RequestDownload and RequestUpload service
/// supporting data upload and download functionality if a server implements a file system for data storage. When
/// configuring a download or upload process to or from a file system, the RequestFileTransfer service shall be
/// used replacing the RequestDownload or RequestUpload. The actual data transfer and termination of the data
/// transfer are implemented by using the TransferData and RequestTransferExit as used with the
/// RequestDownload or RequestUpload service. This service also includes functionality for deleting files or
/// directories on the server's file system. For this use case the TransferData and RequestTransferExit service
/// are not applicable. After the server has received the RequestFileTransfer request message the server shall take 
/// all necessary actions to receive or transmit data before it sends a positive response message.
/// diagnostic services and/or communication that have been previously activated are to remain active.
///
/// TransferData (0x36) service:
/// The TransferData service is used by the client to transfer data either from the client to the server (download)
/// or from the server to the client (upload).
/// The data transfer direction is defined by the preceding RequestDownload or RequestUpload service. If the
/// client initiated a RequestDownload the data to be downloaded is included in the parameter(s)
/// transferRequestParameter in the TransferData request message(s). If the client initiated a RequestUpload the
/// data to be uploaded is included in the parameter(s) transferResponseParameter in the TransferData response
/// message(s).The TransferData service request includes a blockSequenceCounter to allow for an improved error 
/// handling in case a TransferData service fails during a sequence of multiple TransferData requests. The
/// blockSequenceCounter of the server shall be initialized to one when receiving a RequestDownload (0x34) or
/// RequestUpload (0x35) request message. This means that the first TransferData (0x36) request message
/// following the RequestDownload (0x34) or RequestUpload (0x35) request message starts with a
/// blockSequenceCounter of one.
///
/// RequestTransferExit (0x37) service:
/// This service is used by the client to terminate a data transfer between client and server (upload or download).
///
//---------------------------------------------------------------------------------------------------------------------
#ifndef DK_SRVC_UDS_SERVICE_DOWNLOAD_HANDLER_H
#define DK_SRVC_UDS_SERVICE_DOWNLOAD_HANDLER_H
#include "dk_srvc_uds_service_handler_if.h"
#include "dk_srvc_uds_service_manager_if.h"
#include "dk_runtime_bl_einstein_uds_app_component.h"
//#include "upd_adapter.h"

namespace dk
{
namespace app
{
namespace udsblservices
{
 
class CUdsServiceDownloadHandler : public CUdsServiceHandlerIf
{
public:  
    
    /// 
    /// @brief Constructor of CUdsServiceDownloadHandler.
    ///
    /// param[in]  reference of serviceManager instance
    ///
    explicit CUdsServiceDownloadHandler
    (
        CUdsServiceManagerIf &serviceManagerInstance
    ):mServiceManagerInstance(serviceManagerInstance)
    {
        
    }
    
    /// 
    /// @brief Destructor of CUdsServiceDownloadHandler.
    ///
    ~CUdsServiceDownloadHandler()
    {
        
    }

    ///
    /// @brief It defines the temporary path for downloading the files using diagnostic services.
    ///
    //const std::string  mDefaultDownloadTemporaryFilePath = "/tmp/";
    const std::string  mDefaultDownloadTemporaryFilePath = "/fota_cache/";
    
    ///
    /// @brief This method is the download handler initialization routine.This method should be 
    ///        invoked by UDS service Manager on Init . 
    ///
    virtual  void serviceInitialize(void);
        
    ///
    /// @brief This method should be invoked on reception of message from installer for the download request.
    ///
    /// @param[in] installerResponse response received from the installer.
    ///             - 0x00 - Success        
    ///             - 0x01 - Failure 
    ///
    void fileRequestInstallerResponseHandler(const uint8_t installerResponse);
    
    ///
    /// @brief This method is used to set the temporary file path used for storing the request file.
    /// 
    /// @param[in] temporaryPath - temporary file path e.g  /tmp/ , /etc/uds/ ..
    ///
    void setDownloadFileTemporaryPath(const std::string &temporaryPath);
    
    ///
    /// @brief This method is used to update the fota state to other components.
    ///
    /// @param[in] fotaState fota state value.
    ///
    void readFotaStateUpdate(const uint8_t fotaState);
	
	///
    /// @brief This method is used to convert data in array format to 32 bit value.
    ///
    /// @param[in] array start address.
    /// @param[out] address of the 32 bit value.
	/// 
	void arrayTo32BitValue(uint8_t *arr, uint32_t *value);
	
	///
    /// @brief This method is used as callback from Update adaptor to provide the async response.
    ///
    /// @param[in] UDS Service ID.
    /// @param[in] Response for the service.
	/// @param[in] ResponseBuffer holding any data for the response.
	/// 
	void DownloadServiceResponseHandler(DoIPDownloadResponse const  & msg);
	    
private:

    ///
    /// @brief It defines the client address of the currently processing request.
    ///
    uint16_t mClientAddress = 0xFFFFU;

    ///
    /// @brief It defines the type of operation to be applied to the file or directory indicated in the filePathAndName
    ///    parameter.It is used in RequestFileTransfer (0x38) service.
    ///
    typedef enum 
    {
        EModeOfOperation_addFile = 0x01U,    ///<This value shall be used to add the file (download) defined in the
                                            ///    filePathAndName parameter.
        EModeOfOperation_deleteFile = 0x02U, ///<This value shall be used to delete the file defined in the 
                                            ///    filePathAndName parameter
        EModeOfOperation_replaceFile = 0x03U,   ///<This value shall be used to replace the file (download) defined in 
                                               ///    the filePathAndName parameter. If the file is not stored at the 
                                               ///    location the file shall be added.
        EModeOfOperation_readFile = 0x04U,   ///<This value shall be used to read the file (upload) at the location 
                                            /// defined by the filePathAndName parameter.
        EModeOfOperation_readDirectory = 0x05U, ///<This value shall be used to read the directory defined in the
                                               /// filePathAndName parameter. This value implies that the request 
                                               /// does not include a fileName.
        EModeOfOperation_Last = 0xFFU       ///< Guard
    }EModeOfOperation_t;

    ///
    /// @brief It defines the data transfer state . This state is used for checking the valid sequence in reception of 
    ///         data transfer services.
    ///
    typedef enum 
    {
        EFileTransferState_transferRequest = 0x0U, ///< Transfer request state indicating the initial state to receive 
                                                /// download request.
        EFileTransferState_transferData = 0x1U,    ///< Transfer data state ,indicating that the transfer data (0x36) 
                                                /// request can be processed
        EFileTransferState_transferExit = 0x2U,    ///< Transfer exit state , indicating that the transfer data has been 
                                                /// completed and ready to process transfer exit service.
        EFileTransferState_default = 0x3U      ///< Guard
    }EFileTransferState_t;
    
    ///
    /// @brief It defines the file parameters used for handling the download requests.
    /// 
    typedef struct
    {
        uint8_t         mModeOfOperation;    ///< mode of operation received for the requested file.
        uint16_t        mRequestedFilenameWithPathLen;  ///< requested length of destination file name and path. 
        std::string     mRequestedFilenameWithPath;  ///< destination file path and name of the file.
        uint16_t        mTempFilenameWithPathLen;   ///< length of downloaded temporary file name and path. 
        std::string     mTempFilenameWithPath;   ///< file path and name of the temporary file. 
        uint32_t        mCompressedFileSize;    ///< compressed file size in bytes of the requested file.
        uint32_t        mUnCompressedFileSize;  ///< uncompressed file size in bytes of the requested file.
    }SFileControlStatus_t;
    
	
	typedef struct
	{
		uint8_t fileName[256];
		int32_t totFileSize;
        int32_t downloadedSize;
        int32_t remSize;
	}SfileInfo_t;
	
	SfileInfo_t fInfo;
	SfileInfo_t fInfoRd;

    const uint32_t  mUdsDownloadMaxFileSize = 1000U*1024U*1024U; /*ISO Size for 300MB ETFS + 16MB IFS*/
    ///
    /// @brief response length of download request service 
    ///
    const uint8_t  mUdsDownloadResponseBlockSize = 4U;
    
    ///
    /// @brief This parameter is used by the requestDownload positive response message to inform the client how many 
    ///        data bytes (maxNumberOfBlockLength) to include in each TransferData request message from the client.
    ///        This length reflects the complete message length, including the service identifier and the 
    ///        data-parameters present in the TransferData request message.
    const uint32_t mUdsDownloadBlockSize = 4U*1024U + 2U;
    //const uint32_t mUdsDownloadBlockSize = 64*1024 + 2U;

	///
    /// @brief byte position of compression and encryption in the requested data .
    ///
    const uint8_t  mCompressionandEncryptionBytePosition = 0x00U;
    
	///
    /// @brief byte position of Data Format Identifier in the requested data .
    ///
    const uint8_t  mDataFormatIdentifierBytePosition = 0x01U;
	
	///
    /// @brief byte position of Block Address in the requested data .
    ///
    const uint8_t  mBlockAddressBytePosition = 0x02U;
	
	///
    /// @brief byte position of Block Length in the requested data .
    ///
    const uint8_t  mBlockLengthBytePosition = 0x06U;
	
    ///
    /// @brief byte position of modeOfOperation in the requested data .
    ///
    const uint8_t  mModeOfOperationBytePosition = 0x00U;
    
    ///
    /// @brief byte position of modeOfOperation in the requested data .
    ///
    const uint8_t  mFilePathLengthByte0Position = 0x01U;
    
    ///
    /// @brief High byte position of filePathAndNameLength in the requested data .
    ///
    const uint8_t  mFilePathLengthByte1Position = 0x02U;
    
    ///
    /// @brief Low byte position of filePathAndNameLength in the requested data .
    ///
    const uint8_t  mFilePathLengthStartBytePosition  = 0x03U;
    
    ///
    /// @brief It defines the supported length for the file size.
    ///
    const uint8_t  mSupportedFileLengthByteSize  = 4U;
    
    ///
    /// @brief It defines the compression method supported.0x00 means no compression supported.
    ///
    const uint8_t  mCompressionFormatSupported = 0x00U;
    ///
    /// @brief It defines the encryption method supported. 0x00 means no encryption supported.
    /// 
    const uint8_t  mEncryptionFormatSupported = 0x00U;
    
    /// 
    /// @brief It defines the current file parameters used for handling the download requests.
    ///
    SFileControlStatus_t mFileControlStatus;
    
    ///
    /// @brief It defines the temporary file name for the currently requested file.
    ///
    std::string mTemporaryFileName;
    
    ///
    /// @brief It defines the temporary file path for the currently requested file.
    ///
    std::string mTemporaryFilePath;
    
    ///
    /// @brief It defines the current data transfer state .
    ///
    EFileTransferState_t mFileTransferState = EFileTransferState_default;
    
    ///
    /// @brief It defines the current temporary file length
    ///
    uint32_t mTemporaryFileSize=0U;
    
    ///
    /// @brief It defines the current received length of the transfer data.
    ///
    uint32_t mTransferredDataLength=0U;
    
    ///
    /// @brief It defines the current sequence counter in transfer data service.
    ///
    uint8_t mSequenceCouner=0U; 
    
    ///
    /// @brief It holds the reference of CUdsServiceManager instance to which it was registered. This instance is used 
    ///        by the service to update the positive and negative responses.
    /// 
    CUdsServiceManagerIf  &mServiceManagerInstance;
	
	///
    /// @brief It defines the mRequestDownloadServiceConfig (0x34) service configurations values.This value should be configured  
    ///         at serviceInitialize and should be passed to CUdsServiceManager to register the configuration.
    ///
    SServiceConfig_t mRequestDownloadServiceConfig;
    
    ///
    /// @brief It defines the RequestFileTransfer (0x38) service configurations values.This value should be configured  
    ///         at serviceInitialize and should be passed to CUdsServiceManager to register the configuration.
    ///
    SServiceConfig_t mRequestFileTransferServiceConfig;
    
    ///
    /// @brief It defines the TransferData (0x36) service configurations values.This value should be configured  
    ///         at serviceInitialize and should be passed to CUdsServiceManager to register the configuration.
    ///
    SServiceConfig_t mTransferDataServiceConfig;
    
    ///
    /// @brief It defines the RequestTransferExit (0x37) service configurations values.This value should be configured  
    ///         at serviceInitialize and should be passed to CUdsServiceManager to register the configuration.
    ///
    SServiceConfig_t mTransferExitServiceConfig;

    ///
    /// @brief This method handles the RequestDownload (0x34)  request . The method should be set as request 
    ///        handler callback  function for RequestDownload (0x34)  service.This method updates positive or 
    ///        negative response based on the request . 
    ///
    /// @param[in] clientAddress requested client address.
    /// @param[in] pRequestData  pointer to request data length
    /// @param[in] requestLength  size of the requested data.
    ///
    void requestDownloadServiceRequestHandler(const uint16_t clientAddress,const uint8_t * const pRequestData,const uint16_t requestLength);
	
	///
    /// @brief This method handles the post response functionality of RequestDownload (0x34) service.This method is 
    ///         configured as post response handler callback  function for RequestDownload (0x34) service.
    ///
    /// @param[in] clientAddress requested client address.
    ///
    void requestDownloadServiceResetHandler(const uint16_t clientAddress);
	
	///
    /// @brief This method handles the post response functionality of RequestDownload (0x34) service.This method is 
    ///         configured as post response handler callback  function for RequestDownload (0x34) service.
    ///
    /// @param[in] clientAddress requested client address.
    ///
    void requestDownloadServicePostresponseHandler(const uint16_t clientAddress);
	
    ///
    /// @brief This method handles the RequestFileTransfer (0x38)  request . The method should be set as request 
    ///        handler callback  function for RequestFileTransfer (0x38)  service.This method updates positive or 
    ///        negative response based on the request . 
    ///
    /// @param[in] clientAddress requested client address.
    /// @param[in] pRequestData  pointer to request data length
    /// @param[in] requestLength  size of the requested data.
    ///
    void requestFileTransferServiceRequestHandler(const uint16_t clientAddress,const uint8_t * const pRequestData,const uint16_t requestLength);
    
    ///
    /// @brief This method handles the post response functionality of RequestFileTransfer (0x38) service.This method is 
    ///         configured as post response handler callback  function for RequestFileTransfer (0x38) service.
    ///
    /// @param[in] clientAddress requested client address.
    ///
    void requestFileTransferServicePostresponseHandler(const uint16_t clientAddress);
    
    ///
    /// @brief This method handles the reset handler of RequestFileTransfer (0x38) service.This method will set 
    ///        internal status to initial value.This method is configured as reset handler callback function for 
    ///         RequestFileTransfer (0x38) service.
    ///
    /// @param[in] clientAddress requested client address.
    ///
    void requestFileTransferServiceResetHandler(const uint16_t clientAddress);
    
    ///
    /// @brief This method handles the TransferData (0x36)  request . The method should be set as request 
    ///        handler callback  function for TransferData (0x36)  service.This method updates positive or 
    ///        negative response based on the request . 
    ///
    /// @param[in] clientAddress requested client address.
    /// @param[in] pRequestData  pointer to request data length
    /// @param[in] requestLength  size of the requested data.
    ///
    void transferDataServiceRequestHandler(const uint16_t clientAddress,const uint8_t * const pRequestData,const uint16_t requestLength);
    
    ///
    /// @brief This method handles the post response functionality of TransferData (0x36) service.This method is 
    ///         configured as post response handler callback  function for TransferData (0x36) service.
    ///
    /// @param[in] clientAddress requested client address.
    ///
    void transferDataServicePostresponseHandler(const uint16_t clientAddress);
    
    ///
    /// @brief This method handles the reset handler of TransferData (0x36) service.This method will set 
    ///        internal status to initial value.This method is configured as reset handler callback function for 
    ///        TransferData (0x36) service.
    ///
    /// @param[in] clientAddress requested client address.
    ///
    void transferDataServiceResetHandler(const uint16_t clientAddress);
    
    ///
    /// @brief This method handles the RequestTransferExit (0x37)  request . The method should be set as request 
    ///        handler callback  function for RequestTransferExit (0x37)  service.This method updates positive or 
    ///        negative response based on the request . 
    ///
    /// @param[in] clientAddress requested client address.
    /// @param[in] pRequestData  pointer to request data length
    /// @param[in] requestLength  size of the requested data.
    ///
    void transferExitServiceRequestHandler(const uint16_t clientAddress,const uint8_t * const pRequestData,const uint16_t requestLength);
    
    ///
    /// @brief This method handles the post response functionality of RequestTransferExit (0x37) service.This method is 
    ///         configured as post response handler callback  function for RequestTransferExit (0x37) service.
    ///
    /// @param[in] clientAddress requested client address.
    ///
    void transferExitServicePostresponseHandler(const uint16_t clientAddress);
    
    ///
    /// @brief This method handles the post response functionality of RequestTransferExit (0x37) service.This method is 
    ///         configured as post response handler callback  function for RequestTransferExit (0x37) service.
    ///
    /// @param[in] clientAddress requested client address.
    ///
    void transferExitServiceResetHandler(const uint16_t clientAddress);
    
    ///
    /// @brief This method is used to initialize the internal flags used in download services. 
    ///
    void transferInit(void);
	
	void DownloadResponseHandler();
    
    ///
    /// @brief This method is used to process the receive transfer file request mode of operation.
    ///        
    /// @param[in] modeOfOperation mode of operation received for the requested file.
    /// @param[in] filePathAndName requested length of destination file name and path. 
    /// @param[in] fileDataFormatId data format of the received request.
    /// @param[in] unCompressedFileSize uncompressed size of the received request file.
    /// @param[in] compressedFileSize compressed size of the received request file.
    ///
    /// @return EResponseCode_t No error or negative response code for the failure.
    CUdsServiceHandlerIf::EResponseCode_t processFileTransferOperation
    (
        const EModeOfOperation_t modeOfOperation,
        const std::string filePathAndName,
        const uint8_t fileDataFormatId,
        const uint32_t unCompressedFileSize,
        const uint32_t compressedFileSize
    );
    
    ///
    /// @brief This method is used to write data in the requested memory. Here the data would be written in a temporary
    ///         file.
    ///
    /// param[in] dataLength size of the requested data
    /// param[in] pointer to the requested data buffer.
    ///
    CUdsServiceHandlerIf::EResponseCode_t programData(const uint32_t dataLength, const uint8_t * const pData);
    
    ///
    /// @brief This method is used to create a file.
    ///
    /// @param[in] fileName file name with path.
    ///
    CUdsServiceHandlerIf::EResponseCode_t CreateFile(const std::string &fileName);
};

} // udsservices
} // app
} // dk

#endif  // DK_SRVC_UDS_SERVICE_DOWNLOAD_HANDLER_H
