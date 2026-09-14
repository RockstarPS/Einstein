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
#include <cstdint>
#include <iostream>
#include <vector>
#include <unistd.h>
#include "dk_srvc_uds_service_download_handler.h"
#include <algorithm>
#include <sstream>

#define MAX_SIZE_OF_DOIP_REQUEST (7168U)

LOG_DECLARE_CONTEXT(gUdsBlServicesLogContext);

namespace dk
{
namespace app
{
namespace udsblservices
{

void CUdsServiceDownloadHandler::serviceInitialize(void)
{
	transferInit();

	/// -# Configure Request Download service properties.
    mRequestDownloadServiceConfig.mIsFunctionalRequestSupported = false;
    mRequestDownloadServiceConfig.mResponsePendingSupported = true;
    mRequestDownloadServiceConfig.mLengthCheckConditionType = \
                                                    ELengthCheckConditionType_t::ELengthCheckCondition_Equal;
    mRequestDownloadServiceConfig.mServiceRequestLength = 11U;
    mRequestDownloadServiceConfig.mSupportedSessionMask = ESessionMask_t::ESessionMask_FotaSession;
    mRequestDownloadServiceConfig.mSupportedSecurityMask = ESecurityMask_t::ESecurityMask_AllLevel;
    mRequestDownloadServiceConfig.mRequsestHandlerCbkFn = [=](const uint16_t clientAddress,const uint8_t *const pRequestData,const uint16_t requestLength)\
                                                        {requestDownloadServiceRequestHandler(clientAddress,pRequestData,requestLength);};
    mRequestDownloadServiceConfig.mPostResponseHandlerCbkFn = [=](const uint16_t clientAddress)\
                                                        {requestDownloadServicePostresponseHandler(clientAddress);} ;
    mRequestDownloadServiceConfig.mResetServiceHandlerCbkFn = [=](const uint16_t clientAddress) \
                                                        {requestDownloadServiceResetHandler(clientAddress);} ;
    #ifdef UDSCFG_LOG_ENABLED
    LOGD(
        &gUdsServicesLogContext,
        mRequestDownloadServiceId,
        " service register requested for mode ",
        CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds
        );
    #endif
    /// -# Add Request Download service configuration to Uds Service Manager.
    mServiceManagerInstance.addServiceHandler(
                                                CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds,
                                                mRequestDownloadServiceId,
                                                &mRequestDownloadServiceConfig
                                               );

    /// -# Configure Request File transfer service properties.
    mRequestFileTransferServiceConfig.mIsFunctionalRequestSupported = false;
    mRequestFileTransferServiceConfig.mResponsePendingSupported = true;
    mRequestFileTransferServiceConfig.mLengthCheckConditionType = \
                                                    ELengthCheckConditionType_t::ELengthCheckCondition_GreaterOrEqual;
    mRequestFileTransferServiceConfig.mServiceRequestLength = 3U;
    mRequestFileTransferServiceConfig.mSupportedSessionMask = ESessionMask_t::ESessionMask_FotaSession;
    mRequestFileTransferServiceConfig.mSupportedSecurityMask = ESecurityMask_t::ESecurityMask_AllLevel;
    mRequestFileTransferServiceConfig.mRequsestHandlerCbkFn = [=](const uint16_t clientAddress,const uint8_t *const pRequestData,const uint16_t requestLength)\
                                {requestFileTransferServiceRequestHandler(clientAddress,pRequestData,requestLength);};
    mRequestFileTransferServiceConfig.mPostResponseHandlerCbkFn = [=](const uint16_t clientAddress)\
                                                        {requestFileTransferServicePostresponseHandler(clientAddress);} ;
    mRequestFileTransferServiceConfig.mResetServiceHandlerCbkFn = [=](const uint16_t clientAddress) \
                                                        {requestFileTransferServiceResetHandler(clientAddress);} ;

    #ifdef UDSCFG_LOG_ENABLED
    LOGD(
        &gUdsBlServicesLogContext,
        mRequestFileTransferServiceId,
        " service register requested for mode ",
        CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds
        );
    #endif
    /// -# Add Request File transfer service configuration to Uds Service Manager.
    mServiceManagerInstance.addServiceHandler(
                                                CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds,
                                                mRequestFileTransferServiceId,
                                                &mRequestFileTransferServiceConfig
                                               );

    /// -# Configure Transfer data service properties.
    mTransferDataServiceConfig.mIsFunctionalRequestSupported = false;
    mTransferDataServiceConfig.mResponsePendingSupported = true;
    mTransferDataServiceConfig.mLengthCheckConditionType = \
                                                    ELengthCheckConditionType_t::ELengthCheckCondition_GreaterOrEqual;
    mTransferDataServiceConfig.mServiceRequestLength = 3U;
    mTransferDataServiceConfig.mSupportedSessionMask = ESessionMask_t::ESessionMask_FotaSession;
    mTransferDataServiceConfig.mSupportedSecurityMask = ESecurityMask_t::ESecurityMask_AllLevel;
    mTransferDataServiceConfig.mRequsestHandlerCbkFn = [=](const uint16_t clientAddress,const uint8_t *const pRequestData,const uint16_t requestLength)\
                                                        {transferDataServiceRequestHandler(clientAddress,pRequestData,requestLength);};
    mTransferDataServiceConfig.mPostResponseHandlerCbkFn = [=](const uint16_t clientAddress)\
                                                        {transferDataServicePostresponseHandler(clientAddress);} ;
    mTransferDataServiceConfig.mResetServiceHandlerCbkFn = [=](const uint16_t clientAddress) \
                                                        {transferDataServiceResetHandler(clientAddress);} ;

    #ifdef UDSCFG_LOG_ENABLED
    LOGD(
        &gUdsBlServicesLogContext,
        mTransferDataServiceId,
        " service register requested for mode ",
        CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds
        );
    #endif
    /// -# Add Transfer data service configuration to Uds Service Manager.
    mServiceManagerInstance.addServiceHandler(
                                                CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds,
                                                mTransferDataServiceId,
                                                &mTransferDataServiceConfig
                                               );

    /// -# Configure Transfer exit service properties.
    mTransferExitServiceConfig.mIsFunctionalRequestSupported = false;
    mTransferExitServiceConfig.mResponsePendingSupported = true;
    mTransferExitServiceConfig.mLengthCheckConditionType = \
                                                    ELengthCheckConditionType_t::ELengthCheckCondition_Equal;
    mTransferExitServiceConfig.mServiceRequestLength = 1U;
    mTransferExitServiceConfig.mSupportedSessionMask = ESessionMask_t::ESessionMask_FotaSession;
    mTransferExitServiceConfig.mSupportedSecurityMask = ESecurityMask_t::ESecurityMask_AllLevel;
    mTransferExitServiceConfig.mRequsestHandlerCbkFn = [=](const uint16_t clientAddress,const uint8_t *const pRequestData,const uint16_t requestLength)\
                                                        {transferExitServiceRequestHandler(clientAddress,pRequestData,requestLength);};
    mTransferExitServiceConfig.mPostResponseHandlerCbkFn = [=](const uint16_t clientAddress)\
                                                        {transferExitServicePostresponseHandler(clientAddress);} ;
    mTransferExitServiceConfig.mResetServiceHandlerCbkFn = [=](const uint16_t clientAddress) \
                                                        {transferExitServiceResetHandler(clientAddress);} ;
    #ifdef UDSCFG_LOG_ENABLED
    LOGD(
        &gUdsBlServicesLogContext,
        mRequestTransferExitServiceId,
        " service register requested for mode ",
        CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds
        );
    #endif
    /// -# Add Transfer exit service configuration to Uds Service Manager.
    mServiceManagerInstance.addServiceHandler(
                                                CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds,
                                                mRequestTransferExitServiceId,
                                                &mTransferExitServiceConfig
                                               );

}

void CUdsServiceDownloadHandler::setDownloadFileTemporaryPath(const std::string &temporaryPath)
{
    if (temporaryPath.length() > 0U)
    {
        /// -# Set the requested temporary file path,if a valid path is requested.
        mTemporaryFilePath = temporaryPath;
    }
    else
    {
        /// -# Set the default temporary file path,if a invalid path is requested.
        mTemporaryFilePath = mDefaultDownloadTemporaryFilePath;
    }
    #ifdef UDSCFG_LOG_ENABLED
    LOGD(&gUdsBlServicesLogContext," Download temporary path ",mTemporaryFilePath);
    #endif
}

void CUdsServiceDownloadHandler::requestDownloadServiceRequestHandler(const uint16_t clientAddress,const uint8_t *const pRequestData,const uint16_t requestLength)
{

    CUdsServiceHandlerIf::EResponseCode_t responseCode; // response status.
    uint16_t processedDataByteIndex = 0U;
    uint8_t DataFormatIdentifier = 0U;
	uint8_t CompressionandEncryptionformat = 0U;
	uint32_t BlockAddress = 0U;
	uint32_t BlockLength = 0U;
	std::vector<uint8_t> responseBuffer;

    CUdsServiceHandlerIf::ESessionType_t currentSession;
    currentSession = mServiceManagerInstance.getCurrentSession();
    responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;
	DoIPDownloadRequest UdsRequestDownload;

	arrayTo32BitValue(&pRequestData[mBlockAddressBytePosition], &BlockAddress);
	arrayTo32BitValue(&pRequestData[mBlockLengthBytePosition], &BlockLength);
	CompressionandEncryptionformat = static_cast<uint8_t>(pRequestData[mCompressionandEncryptionBytePosition]);
	DataFormatIdentifier = static_cast<uint8_t>(pRequestData[mDataFormatIdentifierBytePosition]);

    #ifdef UDSCFG_LOG_ENABLED
    LOGD(&gUdsBlServicesLogContext," Request Download Length: ",requestLength);
    #endif
    mClientAddress = clientAddress;

    if (currentSession == CUdsServiceHandlerIf::ESessionType_t::ESessionType_DefaultSession)
    {
        responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_SecurityAccessDenied;
    }

    if (responseCode != CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
    {
        ///-# If request not accepted then send negative response.
        mServiceManagerInstance.sendNegativeResponse(mClientAddress, responseCode);
    }
    else
    {
        #ifdef UDSCFG_LOG_ENABLED
        LOGD(&gUdsBlServicesLogContext," mFileTransferState changed to EFileTransferState_transferData");
        #endif
        /// -# If the request is successfully accepted , set transfer state to EFileTransferState_transferData.
        mFileTransferState = EFileTransferState_transferData;
		mTemporaryFileSize = BlockLength;

        /// -# If request accepted , Send Message to Installer for file request update.

		UdsRequestDownload.serviceId	= mRequestDownloadServiceId;
		UdsRequestDownload.formatId  	= DataFormatIdentifier;
		UdsRequestDownload.CompEncId	= CompressionandEncryptionformat;
		UdsRequestDownload.blklength	= BlockLength;
		UdsRequestDownload.blkaddress	= BlockAddress;

		DK_RTE_Send_DoIPDownloadRequest(UdsRequestDownload);

    }
}

void CUdsServiceDownloadHandler::requestDownloadServicePostresponseHandler(const uint16_t clientAddress)
{
    #ifdef UDSCFG_LOG_ENABLED
    LOGD(&gUdsServicesLogContext," Request Download Service post response Handler ",clientAddress);
    #endif
}

void CUdsServiceDownloadHandler::requestDownloadServiceResetHandler(const uint16_t clientAddress)
{
    ///-# Reset the download services status to default value
    #ifdef UDSCFG_LOG_ENABLED
    LOGD(&gUdsServicesLogContext," Request Download Service reset handler ",clientAddress);
    #endif
    transferInit();
}

void CUdsServiceDownloadHandler::requestFileTransferServiceRequestHandler(const uint16_t clientAddress,const uint8_t *const pRequestData,const uint16_t requestLength)
{

    CUdsServiceHandlerIf::EResponseCode_t responseCode; // response status.
    uint16_t processedDataByteIndex;    // request data byte current index.
    EModeOfOperation_t modeOfOperation; // received mode of operation.
    std::string filePathAndName;        // received file path name
    uint8_t fileDataFormatId;           // received file format ID
    uint32_t unCompressedFileSize;      // received uncompressed file size
    uint32_t compressedFileSize;        // received compressed file size
    uint16_t filePathAndNameLength;     // received file path length
    uint8_t fileSizeParameterLength;    // received length of file size.
    CUdsServiceHandlerIf::ESessionType_t currentSession;    // current session type.
    currentSession = mServiceManagerInstance.getCurrentSession();
    // Initialize to default values
    responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;
    processedDataByteIndex = 0U;
    fileDataFormatId =0U;
    //unCompressedFileSize =0U;
    //compressedFileSize=0U;
	DoIPDownloadRequest UdsRequestFileTransfer;

    #ifdef UDSCFG_LOG_ENABLED
    LOGD(&gUdsBlServicesLogContext," File transfer request received of data  length ",requestLength);
    #endif
    mClientAddress = clientAddress;
    /// -# Check for valid request length , if invalid length update response status as InvalidFormat.
    if (requestLength > 3U)
    {
        /// -# If valid request , Get mode of Operation
        modeOfOperation = static_cast<EModeOfOperation_t>(pRequestData[mModeOfOperationBytePosition]);
        /// -# If valid request , filePath name length
        filePathAndNameLength  = ((static_cast<uint16_t>((static_cast<uint16_t>(pRequestData[mFilePathLengthByte0Position])) << 0x08U)) \
                                    & 0xFF00U) |\
                                    ((static_cast<uint16_t>(pRequestData[mFilePathLengthByte1Position])) &0x00FFU);

        processedDataByteIndex += mFilePathLengthByte1Position;

        /// -# Check for valid requested data length
        if ((processedDataByteIndex+filePathAndNameLength) < requestLength)
        {
            /// -# If valid request, get file Name and path from the requested data
            (void)filePathAndName.assign(reinterpret_cast<const char *>(&pRequestData[processedDataByteIndex+1U]),
                                         static_cast<uint32_t>(filePathAndNameLength));
            processedDataByteIndex += filePathAndNameLength;
        }
        else
        {
            #ifdef UDSCFG_LOG_ENABLED
            /// -# Set NRC InvalidFormat if the requested length is less than the required length
            LOGD(&gUdsBlServicesLogContext," Invalid request length for file Size ");
            #endif
            responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_IncorrectMessageLengthOrInvalidFormat;
        }

        /// -# Check for valid mode of operation to process the data download format
        if ((responseCode == CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError) && \
            ((modeOfOperation != EModeOfOperation_t::EModeOfOperation_deleteFile) && \
            (modeOfOperation != EModeOfOperation_t::EModeOfOperation_readDirectory)))
        {
            /// -# if valid mode of operation is requested, check for valid length
            if (processedDataByteIndex < requestLength)
            {
                /// -# Get Data format Identifier from the requested data
                fileDataFormatId = pRequestData[processedDataByteIndex+1U];
                /// -# Check if the requested format is supported
                if ((static_cast<uint8_t>((mCompressionFormatSupported & 0xF0U) |
                                          (mEncryptionFormatSupported & 0x0FU))) == fileDataFormatId)

                {
                    processedDataByteIndex+=1U;
                }
                else
                {
                    #ifdef UDSCFG_LOG_ENABLED
                     /// -# if the format is not supported,update 0x31 NRC
                    LOGD(
                        &gUdsBlServicesLogContext,
                        " Invalid Encryption or compression format. Compression Format Received",
                         ((static_cast<uint32_t>(mCompressionFormatSupported)) & 0xF0U) >> 4U,
                        "Encryption Received =",
                        (static_cast<uint32_t>(mEncryptionFormatSupported)) & 0x0FU
                        );
                    #endif
                    responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestOutOfRange;
                }
            }
            else
            {
                /// -# Set NRC InvalidFormat if the requested length is less than the required length
                #ifdef UDSCFG_LOG_ENABLED
                LOGD(&gUdsBlServicesLogContext," Invalid request length for Data format Identifier ");
                #endif
                responseCode = CUdsServiceHandlerIf::EResponseCode_t::\
                                    EResponseCode_IncorrectMessageLengthOrInvalidFormat;
            }
        }

        /// -# Check for valid mode of operation to process the data download compressed and uncompressed size
        if ((responseCode == CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError) && \
            ((modeOfOperation != EModeOfOperation_t::EModeOfOperation_deleteFile) && \
            (modeOfOperation != EModeOfOperation_t::EModeOfOperation_readDirectory) &&
            (modeOfOperation != EModeOfOperation_t::EModeOfOperation_readFile)))
        {
            /// -# if valid mode of operation is requested, check for valid length
            if (processedDataByteIndex < requestLength)
            {

                /// -# Get the size of data length supported from the requested data
                fileSizeParameterLength = pRequestData[processedDataByteIndex+1U];
                processedDataByteIndex+=1U;

                /// -# Check if the requested data length size is supported .
                if ((fileSizeParameterLength > mSupportedFileLengthByteSize) && \
                    ((processedDataByteIndex + (static_cast<uint16_t>(fileSizeParameterLength)*2U)) < requestLength))
                {
                    #ifdef UDSCFG_LOG_ENABLED
                    LOGD(&gUdsBlServicesLogContext," Request file size length not supported");
                    #endif
                    responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestOutOfRange;
                }
                else
                {
                    ///-# get the compressed and uncompressed size from the requested data .
                    processedDataByteIndex+=1U;
                    unCompressedFileSize = (((static_cast<uint32_t>(pRequestData[processedDataByteIndex])) << 24U) | \
                                         ((static_cast<uint32_t>(pRequestData[processedDataByteIndex+1U])) << 16U) | \
                                         ((static_cast<uint32_t>(pRequestData[processedDataByteIndex+2U])) << 8U) | \
                                         ((static_cast<uint32_t>(pRequestData[processedDataByteIndex+3U])) & 0xFFU) );
                    processedDataByteIndex+=(fileSizeParameterLength);
                    compressedFileSize = (((static_cast<uint32_t>(pRequestData[processedDataByteIndex])) << 24U) | \
                                         ((static_cast<uint32_t>(pRequestData[processedDataByteIndex+1U])) << 16U) | \
                                         ((static_cast<uint32_t>(pRequestData[processedDataByteIndex+2U])) << 8U) | \
                                         ((static_cast<uint32_t>(pRequestData[processedDataByteIndex+3U])) & 0xFFU) );
                    #ifdef UDSCFG_LOG_ENABLED
                    LOGD(
                        &gUdsBlServicesLogContext,
                        "Requested File size Compressed = ",
                        unCompressedFileSize,
                        " Uncompressed = ",
                        compressedFileSize
                        );
                    #endif
                }
            }
            else
            {
                /// -# Set NRC InvalidFormat if the requested length is less than the required length
                #ifdef UDSCFG_LOG_ENABLED
                LOGD(&gUdsBlServicesLogContext," Invalid request length for file size ");
                #endif
                responseCode = CUdsServiceHandlerIf::EResponseCode_t::\
                                    EResponseCode_IncorrectMessageLengthOrInvalidFormat;
            }

        }

    }
    else
    {
        /// -# Set NRC InvalidFormat if the requested length is less than the required length
        #ifdef UDSCFG_LOG_ENABLED
        LOGD(&gUdsBlServicesLogContext," Invalid request length ");
        #endif
        responseCode = CUdsServiceHandlerIf::EResponseCode_t::\
                    EResponseCode_IncorrectMessageLengthOrInvalidFormat;
    }

    if (currentSession == CUdsServiceHandlerIf::ESessionType_t::ESessionType_DefaultSession)
    {
        responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_SecurityAccessDenied;
    }

    if (responseCode != CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
    {
        ///-# If request not accepted then send negative response.
        mServiceManagerInstance.sendNegativeResponse(mClientAddress,responseCode);
    }
    else
    {
        #ifdef UDSCFG_LOG_ENABLED
        LOGD(&gUdsBlServicesLogContext," mFileTransferState changed to EFileTransferState_transferData");
        #endif
        /// -# If the request is successfully accepted , set transfer state to EFileTransferState_transferData.
        mFileTransferState = EFileTransferState_transferData;

        /// -# If request accepted , Send Message to Installer for file request update.

		UdsRequestFileTransfer.serviceId	= mRequestFileTransferServiceId;
		UdsRequestFileTransfer.formatId  	= fileDataFormatId;
		UdsRequestFileTransfer.CompEncId	= modeOfOperation;
		UdsRequestFileTransfer.blklength	= filePathAndNameLength;
		memcpy(UdsRequestFileTransfer.data, &pRequestData[mFilePathLengthStartBytePosition], filePathAndNameLength);

		DK_RTE_Send_DoIPDownloadRequest(UdsRequestFileTransfer);
	}
}

void CUdsServiceDownloadHandler::requestFileTransferServicePostresponseHandler(const uint16_t clientAddress)
{
    #ifdef UDSCFG_LOG_ENABLED
    LOGD(&gUdsBlServicesLogContext,"Post Handler Invoked for Request file transfer",clientAddress);
    #endif
}

void CUdsServiceDownloadHandler::requestFileTransferServiceResetHandler(const uint16_t clientAddress)
{
    #ifdef UDSCFG_LOG_ENABLED
    LOGD(&gUdsBlServicesLogContext,"Post Handler Invoked for Request file transfer",clientAddress);
    #endif
	transferInit();
}

void CUdsServiceDownloadHandler::transferDataServiceRequestHandler(const uint16_t clientAddress,const uint8_t *const pRequestData,const uint16_t requestLength)
{
   // LOGE(&gUdsBlServicesLogContext,"transferDataServiceRequestHandler function is invoked");
    CUdsServiceHandlerIf::EResponseCode_t responseCode; // response status
    std::vector<uint8_t> responseData(1U);
    CUdsServiceHandlerIf::ESessionType_t currentSession;    // current session type.
	std::vector<uint8_t> responseBuffer;

    #ifdef UDSCFG_LOG_ENABLED
    LOGD(&gUdsBlServicesLogContext," Transfer data service received for data length ",requestLength);
    #endif

    currentSession = mServiceManagerInstance.getCurrentSession();

    if(mFileTransferState != EFileTransferState_transferData)
    {
        /// -# If the current transfer state is not transfer data then NRC RequestSequenceError should be updated
        responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestSequenceError;
    }
//    else if(((mTransferredDataLength + requestLength) - 1U) > mTemporaryFileSize)
//    {
//        /// -# If the transferred length is greater than actual file length , then NRC TransferDataSuspended should be
//        ///    updated.
//
//        responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_TransferDataSuspended;
//    }
    else
    {
        /// -# Check for valid sequence counter(block),if the same block is repeated or next block is requested then
        /// accept  the request else reject the request.
        if(((mSequenceCouner == pRequestData[0]) || (static_cast<uint8_t>(1U + mSequenceCouner) == pRequestData[0]))||((pRequestData[0] == 1u) && (mSequenceCouner==0xFF)))
        {
            //if (static_cast<uint8_t>(1U + mSequenceCouner) == pRequestData[0])
            {
                /// -# If the sequence counter(block) is next block , then program the data and update sequence counter.
                mSequenceCouner = pRequestData[0];
                responseCode = programData((static_cast<uint32_t>(requestLength) - 1U), &pRequestData[1]);
                mTransferredDataLength   += (static_cast<uint32_t>(requestLength) - 1U);
            }
           // else
            {
                /// -# If the same sequence counter is again sent , just send positive response as the data has already
                ///    been programmed. This can happen when the response for previous transfer was not received by the
                ///    external programmer tool and retry the request.
                 responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;
            }

            if(mTransferredDataLength == mTemporaryFileSize)
            {
                #ifdef UDSCFG_LOG_ENABLED
                LOGD(&gUdsBlServicesLogContext,"Transfer state changed to EFileTransferState_transferExit");
                #endif
                /// -# If the complete file is downloaded ,set state to EFileTransferState_transferExit.
                mFileTransferState = EFileTransferState_transferExit;
            }
        }
        else
        {
            /// -# If the wrong sequence counter received , update WrongBlockSequenceCounter NRC.
            responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_WrongBlockSequenceCounter;
        }
    }

    if (responseCode == CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
    {
        if (currentSession == CUdsServiceHandlerIf::ESessionType_t::ESessionType_DefaultSession)
        {
            responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_SecurityAccessDenied;
        }
        else
        {

            #ifdef UDSCFG_LOG_ENABLED
            LOGD(&gUdsBlServicesLogContext,"Positive response for Transfer Data Block ",mSequenceCouner);
            #endif
        }
    }

    if (responseCode != CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
    {
        ///-# If request not accepted then send negative response.
        #ifdef UDSCFG_LOG_ENABLED
        LOGD(&gUdsBlServicesLogContext,"Invalid Transfer Data Handler - NRC ",responseCode);
        #endif
        mServiceManagerInstance.sendNegativeResponse(clientAddress,responseCode);
    }
}


void CUdsServiceDownloadHandler::transferDataServicePostresponseHandler(const uint16_t clientAddress)
{
    #ifdef UDSCFG_LOG_ENABLED
    LOGD(&gUdsBlServicesLogContext,"Post Handler Invoked for Transfer data service",clientAddress);
    #endif
}

void CUdsServiceDownloadHandler::transferDataServiceResetHandler(const uint16_t clientAddress)
{
    #ifdef UDSCFG_LOG_ENABLED
    LOGD(&gUdsBlServicesLogContext,"Reset handler Invoked for Transfer data service",clientAddress);
    #endif
    ///-# Reset the download services status to default value
    transferInit();
}

void CUdsServiceDownloadHandler::transferExitServiceRequestHandler(const uint16_t clientAddress,const uint8_t *const pRequestData,const uint16_t requestLength)
{
    CUdsServiceHandlerIf::EResponseCode_t responseCode; // response status
    std::vector<uint8_t> responseBuffer;
    CUdsServiceHandlerIf::ESessionType_t currentSession;    // current session type.
	DoIPDownloadRequest UdsTransferExit;

    #ifdef UDSCFG_LOG_ENABLED
    LOGD(&gUdsBlServicesLogContext," Transfer exit service received for data length ",requestLength);
    #endif

    currentSession = mServiceManagerInstance.getCurrentSession();

    if(mFileTransferState != EFileTransferState_transferExit)
    {
        #ifdef UDSCFG_LOG_ENABLED
        LOGD(&gUdsBlServicesLogContext," Invalid transfer state ",EFileTransferState_transferExit);
        #endif
        /// -# If the current transfer state is not transfer exit then NRC RequestSequenceError should be updated
        responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestSequenceError;
    }
    else
    {
        if((0UL != mTemporaryFileSize) && (mTransferredDataLength == mTemporaryFileSize))
        {
            /// -# If the requested file has been fully transferred then update status as NoError
            responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;
        }
        else
        {
            #ifdef UDSCFG_LOG_ENABLED
            LOGD(&gUdsBlServicesLogContext," Invalid transferred file size ",mTemporaryFileSize);
            #endif
            /// -# If the requested length is not transferred then NRC 0x24 should be updated.
            responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestSequenceError;
        }
    }

    if (responseCode == CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
    {
        if (currentSession == CUdsServiceHandlerIf::ESessionType_t::ESessionType_DefaultSession)
        {
            responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_SecurityAccessDenied;
        }
        else
        {
			UdsTransferExit.serviceId	= mRequestTransferExitServiceId;

			DK_RTE_Send_DoIPDownloadRequest(UdsTransferExit);

        }
    }// end of main if

    if (responseCode != CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
    {
        ///-# If request not accepted then send negative response.
        mServiceManagerInstance.sendNegativeResponse(clientAddress,responseCode);
    }

    ///-# Re-initialize download parameters to accept new transfer request.
    transferInit();
}

void CUdsServiceDownloadHandler::transferExitServicePostresponseHandler(const uint16_t clientAddress)
{
    #ifdef UDSCFG_LOG_ENABLED
    LOGD(&gUdsBlServicesLogContext," Transfer Exit Service post response Handler ",clientAddress);
    #endif
}

void CUdsServiceDownloadHandler::transferExitServiceResetHandler(const uint16_t clientAddress)
{
    ///-# Reset the download services status to default value
    #ifdef UDSCFG_LOG_ENABLED
    LOGD(&gUdsBlServicesLogContext," Transfer Exit Service reset handler ",clientAddress);
    #endif
    transferInit();
}

void CUdsServiceDownloadHandler::transferInit(void)
{
    ///-# Initialize download services status to default value
    mFileTransferState = EFileTransferState_default;
    mTemporaryFileSize = 0U;
    mTransferredDataLength = 0U;
    mSequenceCouner = 0U;
    #ifdef UDSCFG_LOG_ENABLED
    LOGD(&gUdsBlServicesLogContext," download services status to default value " );
    #endif
}
void CUdsServiceDownloadHandler::readFotaStateUpdate(const uint8_t state)
{
    #ifdef UDSCFG_LOG_ENABLED
    LOGD(&gUdsBlServicesLogContext," Received Fota State Update ", state);
    #endif

    transferInit();
    if( !access("/fota_cache/fileInfo.bin" , F_OK ) )
    {
	    remove("/fota_cache/fileInfo.bin");
	    LOGD(&gUdsBlServicesLogContext,"\n %s: removed fileInfo.bin\n", __func__);
    }
    else
    {
	    LOGE(&gUdsBlServicesLogContext,"%s: Error, unable to find fileInfo \n", __func__);
    }
}

CUdsServiceHandlerIf::EResponseCode_t CUdsServiceDownloadHandler::programData(const uint32_t dataLength, const uint8_t * const pData)
{
    CUdsServiceHandlerIf::EResponseCode_t responseCode; // response status
	DoIPDownloadRequest UdsTransferData;

    #ifdef UDSCFG_LOG_ENABLED
    LOGD(&gUdsBlServicesLogContext," Program data Invoked for data length ",dataLength );
    #endif

	UdsTransferData.serviceId = mTransferDataServiceId;
	UdsTransferData.dataLen = dataLength;

	if(dataLength < MAX_SIZE_OF_DOIP_REQUEST)
	{
		memcpy(UdsTransferData.data, pData, dataLength);

		responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;

		DK_RTE_Send_DoIPDownloadRequest(UdsTransferData);
	}
    else
    {
        #ifdef UDSCFG_LOG_ENABLED
        LOGE(&gUdsBlServicesLogContext," Error in programData");
        #endif
        responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_GeneralProgrammingFailure;
    }

    ///-# return response status.
    return responseCode;
}

void CUdsServiceDownloadHandler:: arrayTo32BitValue(uint8_t *arr, uint32_t *value)
{
    // Ensure the array has at least 4 bytes
    if (arr != nullptr)
	{
        // Combine bytes into a 32-bit value (little-endian)
		*value = 0;
		*value |= (static_cast<uint32_t>(arr[0])) << 24;
		*value |= (static_cast<uint32_t>(arr[1])) << 16;
		*value |= (static_cast<uint32_t>(arr[2])) << 8;
		*value |= (static_cast<uint32_t>(arr[3])) << 0;
    }
}

void CUdsServiceDownloadHandler::DownloadServiceResponseHandler(DoIPDownloadResponse const  & msg)
{
	uint32_t ServiceID = msg.serviceId;
	CUdsServiceManagerIf::EResponseType_t Response;

	if(msg.result == 0x00)
	{
		Response = CUdsServiceManagerIf::EResponseType_t::EResponse_Positive;
	}
	else
	{
		Response = CUdsServiceManagerIf::EResponseType_t::EResponse_Negative;
	}
	std::vector<uint8_t> responseBuffer;

	if(ServiceID == mTransferDataServiceId)
	{
		responseBuffer.resize(1);
		responseBuffer[0]= mSequenceCouner;
	}
	else if(ServiceID == mRequestDownloadServiceId)
	{
		responseBuffer.resize(3);
		responseBuffer[0] = 0x20;
		responseBuffer[1] = static_cast<uint8_t>((MAX_SIZE_OF_DOIP_REQUEST >> 8));
		responseBuffer[2] = static_cast<uint8_t>(MAX_SIZE_OF_DOIP_REQUEST);
	}

	mServiceManagerInstance.serviceResponseUpdate(mClientAddress, Response, responseBuffer);
}

} // udsservices
} // app
} // dk

