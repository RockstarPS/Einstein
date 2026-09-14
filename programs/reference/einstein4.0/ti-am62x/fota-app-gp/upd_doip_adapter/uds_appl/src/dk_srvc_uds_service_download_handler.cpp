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
#include "doip_dtc.h"
#include "Reflashhandle.hpp"
#include <spawn.h>
#include <regex>

namespace dk
{
namespace app
{
namespace udsblservices
{

#ifndef UDSCFG_LOG_ENABLED
#define UDSCFG_LOG_ENABLED
#endif
//#ifdef UDSCFG_LOG_ENABLED
LOG_IMPORT_CONTEXT(gUdsBlServicesLogContext);
//#endif


void CUdsServiceDownloadHandler::serviceInitialize(void)
{
	transferInit();

	/// -# Configure Request File transfer service properties.
	mRequestFileTransferServiceConfig.mIsFunctionalRequestSupported = false;
	mRequestFileTransferServiceConfig.mResponsePendingSupported = true;
	mRequestFileTransferServiceConfig.mLengthCheckConditionType = \
													ELengthCheckConditionType_t::ELengthCheckCondition_GreaterOrEqual;
	mRequestFileTransferServiceConfig.mServiceRequestLength = 3U;
	mRequestFileTransferServiceConfig.mSupportedSessionMask = ESessionMask_t::ESessionMask_FotaSession;
	mRequestFileTransferServiceConfig.mSupportedSecurityMask = ESecurityMask_t::ESecurityMask_levelL2;
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
	mTransferDataServiceConfig.mSupportedSecurityMask = ESecurityMask_t::ESecurityMask_levelL2;
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
													ELengthCheckConditionType_t::ELengthCheckCondition_GreaterOrEqual;
	mTransferExitServiceConfig.mServiceRequestLength = 1U;
	mTransferExitServiceConfig.mSupportedSessionMask = ESessionMask_t::ESessionMask_FotaSession;
	mTransferExitServiceConfig.mSupportedSecurityMask = ESecurityMask_t::ESecurityMask_levelL2;
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

	/// -# Configure Request Download service properties.
	mRequestDownloadServiceConfig.mIsFunctionalRequestSupported = false;
	mRequestDownloadServiceConfig.mResponsePendingSupported = true;
	mRequestDownloadServiceConfig.mLengthCheckConditionType = \
														ELengthCheckConditionType_t::ELengthCheckCondition_GreaterOrEqual;
	mRequestDownloadServiceConfig.mServiceRequestLength = 1U;
	mRequestDownloadServiceConfig.mSupportedSessionMask = ESessionMask_t::ESessionMask_FotaSession;
	mRequestDownloadServiceConfig.mSupportedSecurityMask = ESecurityMask_t::ESecurityMask_levelL2;
	mRequestDownloadServiceConfig.mRequsestHandlerCbkFn = [=](const uint16_t clientAddress,const uint8_t *const pRequestData,const uint16_t requestLength)\
															{requestDownloadServiceRequestHandler(clientAddress,pRequestData,requestLength);};
	mRequestDownloadServiceConfig.mPostResponseHandlerCbkFn = [=](const uint16_t clientAddress)\
															{requestDownloadServicePostresponseHandler(clientAddress);} ;
	mRequestDownloadServiceConfig.mResetServiceHandlerCbkFn = [=](const uint16_t clientAddress) \
															{requestDownloadServiceResetHandler(clientAddress);} ;
		#ifdef UDSCFG_LOG_ENABLED
		LOGD(
			&gUdsBlServicesLogContext,
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

	// Initialize to default values
	responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;
	processedDataByteIndex = 0U;
	fileDataFormatId =0U;
	unCompressedFileSize =0U;
	compressedFileSize=0U;

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


	if (responseCode ==  CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
	{
		/// -# Reset all transfer status to process a new transfer request.
		transferInit();
		responseCode = processFileTransferOperation(
													modeOfOperation,
													filePathAndName,
													fileDataFormatId,
													unCompressedFileSize,
													compressedFileSize
													);
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
		//mClientAddress = clientAddress;
		UdsInstallerFileDownloadStatus DkMsgInstallerFileDownloadStatus;
		DkMsgInstallerFileDownloadStatus.modeOfOperation = mFileControlStatus.mModeOfOperation ;
		DkMsgInstallerFileDownloadStatus.requestedFilenameWithPathLen = \
			mFileControlStatus.mRequestedFilenameWithPathLen;

		(void)memcpy(
			   &DkMsgInstallerFileDownloadStatus.requestedFilenameWithPath[0],
			   &mFileControlStatus.mRequestedFilenameWithPath[0],
			   static_cast<uint32_t>(mFileControlStatus.mRequestedFilenameWithPathLen));

		DkMsgInstallerFileDownloadStatus.tempFilenameWithPathLen = mFileControlStatus.mTempFilenameWithPathLen;

		(void)memcpy(
			   &DkMsgInstallerFileDownloadStatus.tempFilenameWithPath[0],
			   &mFileControlStatus.mTempFilenameWithPath[0],
			   static_cast<uint32_t>(mFileControlStatus.mTempFilenameWithPathLen));
		#ifdef UDSCFG_LOG_ENABLED
		LOGD(&gUdsBlServicesLogContext," Download file notification message sent to installer ");
		#endif
		DK_RTE_Send_UdsInstallerFileDownloadStatus(DkMsgInstallerFileDownloadStatus);
	}
}


CUdsServiceHandlerIf::EResponseCode_t CUdsServiceDownloadHandler::processFileTransferOperation
(
	const EModeOfOperation_t modeOfOperation,
	const std::string filePathAndName,
	const uint8_t fileDataFormatId,
	const uint32_t unCompressedFileSize,
	const uint32_t compressedFileSize
)
{
	CUdsServiceHandlerIf::EResponseCode_t responseCode; // response status.
	std::vector<uint8_t> responseBuffer(7U);
	std::string fileName;   // temp file name
	FILE *fp_img;
	const char *fota_fileInfo = "/nand/fileInfo.bin";
	uint8_t ret = 0;

	/// -# Set responseCode as NoError, Assuming requested Operation supported.
	responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;

	/// -# Check for valid file name .
	if (filePathAndName.length() != 0U)
	{
		///-# If valid file name , check for supported mode of operation
		if ((modeOfOperation == EModeOfOperation_addFile) || (modeOfOperation == EModeOfOperation_replaceFile))
		{
			if(unCompressedFileSize <= mUdsDownloadMaxFileSize)
			{
				/// -# If valid file name and valid mode of opreation . Get the requested file name from the file path and
				///  name and append it to the temporary file path.The temporary file name is appended with "temp" string.
				fileName = mTemporaryFilePath+"temp"+filePathAndName.substr((filePathAndName.find_last_of("/\\") + 1U));

				/// -# Request to create temporary file.
				responseCode = CreateFile(fileName);

				/// -# Supported filePathAndName length is 255 . Hence check for valid length and check if the file
				///    creation is success.
				if ((fileName.length() < 255U) &&
					(responseCode == CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError))
				{
					/// -# Update positive response.
					mTemporaryFileName = fileName;
					mTemporaryFileSize = unCompressedFileSize;
					responseBuffer[0] = modeOfOperation;
					responseBuffer[1] = mUdsDownloadResponseBlockSize;
					responseBuffer[2] = (static_cast<uint8_t>(mUdsDownloadBlockSize >> 24U));
					responseBuffer[3] = (static_cast<uint8_t>(mUdsDownloadBlockSize >> 16U));
					responseBuffer[4] = (static_cast<uint8_t>(mUdsDownloadBlockSize >> 8U));
					responseBuffer[5] = (static_cast<uint8_t>(mUdsDownloadBlockSize));
					responseBuffer[6] = fileDataFormatId;

					if( 0 != access("/nand/fileInfo.bin" , F_OK ) )
					{
						std::strcpy((char *)fInfo.fileName, mTemporaryFileName.c_str());
						//fInfo.fileName = (int8_t)mTemporaryFileName;
						fInfo.totFileSize = mTemporaryFileSize;

						//DEBUG
						LOGD(&gUdsBlServicesLogContext,"File name after copying = %s\ntotFileSize = %d\n", fInfo.fileName, fInfo.totFileSize);

						if( (fp_img=fopen(fota_fileInfo, "wb")) != NULL)
						{
							ret = fwrite((const void*)&(fInfo), sizeof(SfileInfo_t), 1, fp_img);
							if(ret != 1)
							{
								LOGD(&gUdsBlServicesLogContext,"fwrite not successful\n");
							}
							fclose(fp_img);
						}
						else
						{
							LOGE(&gUdsBlServicesLogContext,"fopen error\n");
						}
					}

				}
				else
				{
					#ifdef UDSCFG_LOG_ENABLED
					LOGE(&gUdsBlServicesLogContext,"Temp file path length is invalid or file creation failed ");
					#endif
					/// -# If the file path length is invalid or file creation failed, then update NRC 0x70
					responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_UploadDownloadNotAccepted;
				}
			}
			else
			{
				#ifdef UDSCFG_LOG_ENABLED
				LOGD(&gUdsBlServicesLogContext,"Download File size above accepted range ",unCompressedFileSize);
				#endif
				/// -# if modeOfOperation not supported the update 0x31 NRC
				responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestOutOfRange;
			}
		}
		else if ((modeOfOperation == EModeOfOperation_deleteFile ) || \
				  (modeOfOperation == EModeOfOperation_readFile ) ||
				  (modeOfOperation == EModeOfOperation_readDirectory ))

		{
			#ifdef UDSCFG_LOG_ENABLED
			LOGD(&gUdsBlServicesLogContext,"Mode of operation not supported ");
			#endif
			/// -# if modeOfOperation not supported the update 0x31 NRC
			responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestOutOfRange;
		}
		else
		{
			#ifdef UDSCFG_LOG_ENABLED
			LOGD(&gUdsBlServicesLogContext,"Mode of operation not supported ",modeOfOperation);
			#endif
			 /// -# if modeOfOperation not supported the update 0x31 NRC
			responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestOutOfRange;
		}
	}
	else
	{
		#ifdef UDSCFG_LOG_ENABLED
		LOGD(&gUdsBlServicesLogContext,"Temporary file path is Invalid");
		#endif
		/// -# If the file path is invalid, then update NRC UploadDownloadNotAccepted
		responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_UploadDownloadNotAccepted;
	}

	if (responseCode == CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
	{
		/// -# If current file operation request supported , then update the mFileControlStatus and Update positive
		///    response.
		mFileControlStatus.mModeOfOperation = modeOfOperation;
		mFileControlStatus.mRequestedFilenameWithPath = filePathAndName;
		mFileControlStatus.mRequestedFilenameWithPathLen = static_cast<uint16_t>(filePathAndName.length());
		mFileControlStatus.mTempFilenameWithPath = mTemporaryFileName;
		mFileControlStatus.mTempFilenameWithPathLen = static_cast<uint16_t>(mTemporaryFileName.length());
		mFileControlStatus.mCompressedFileSize = compressedFileSize;
		mFileControlStatus.mUnCompressedFileSize = unCompressedFileSize;
		#ifdef UDSCFG_LOG_ENABLED
		LOGD(&gUdsBlServicesLogContext,"Valid File transfer request received");
		#endif
		mServiceManagerInstance.serviceResponseUpdate(
														mClientAddress,
														CUdsServiceManagerIf::EResponseType_t::EResponse_Positive,
														responseBuffer
														);
	}

	/// -# Return response status
	return responseCode;
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
	CUdsServiceHandlerIf::EResponseCode_t responseCode; // response status
	std::vector<uint8_t> responseData(1U);

	#ifdef UDSCFG_LOG_ENABLED
	LOGD(&gUdsBlServicesLogContext," Transfer data service received for data length ",requestLength);
	#endif
	//LOGD(&gUdsBlServicesLogContext,"[Resume]mTransferredDataLength:%d",mTransferredDataLength);
	//LOGD(&gUdsBlServicesLogContext,"[Resume]requestLength:%d",requestLength);
	//LOGD(&gUdsBlServicesLogContext,"[Resume]mTemporaryFileSize:%d",mTemporaryFileSize);
	if(mFileTransferState != EFileTransferState_transferData)
	{
		/// -# If the current transfer state is not transfer data then NRC RequestSequenceError should be updated
		responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestSequenceError;
	}
	else if(((mTransferredDataLength + requestLength) - 1U) > mTemporaryFileSize)
	{
		/// -# If the transferred length is greater than actual file length , then NRC TransferDataSuspended should be
		///    updated.
		//LOGD(&gUdsBlServicesLogContext,"[Resume]NRC71");
		//LOGD(&gUdsBlServicesLogContext,"[Resume]mTransferredDataLength:%d",mTransferredDataLength);
		//LOGD(&gUdsBlServicesLogContext,"[Resume]requestLength:%d",requestLength);
		//LOGD(&gUdsBlServicesLogContext,"[Resume]mTemporaryFileSize:%d",mTemporaryFileSize);
		responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_TransferDataSuspended;
	}
	else
	{
		/// -# Check for valid sequence counter(block),if the same block is repeated or next block is requested then
		/// accept  the request else reject the request.
		if((mSequenceCouner == pRequestData[0]) || (static_cast<uint8_t>(1U + mSequenceCouner) == pRequestData[0]))
		{
			if (static_cast<uint8_t>(1U + mSequenceCouner) == pRequestData[0])
			{
				/// -# If the sequence counter(block) is next block , then program the data and update sequence counter.
				mSequenceCouner = pRequestData[0];
				responseCode = programData((static_cast<uint32_t>(requestLength) - 1U), &pRequestData[1]);
				mTransferredDataLength   += (static_cast<uint32_t>(requestLength) - 1U);
			}
			else
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


	if (responseCode != CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
	{
		///-# If request not accepted then send negative response.
		#ifdef UDSCFG_LOG_ENABLED
		LOGD(&gUdsBlServicesLogContext,"Invalid Transfer Data Handler - NRC ",responseCode);
		#endif
		mServiceManagerInstance.sendNegativeResponse(clientAddress,responseCode);
	}
	else
	{
		#ifdef UDSCFG_LOG_ENABLED
		LOGD(&gUdsBlServicesLogContext,"Positive response for Transfer Data Block ", static_cast<uint32_t>(mSequenceCouner));
		#endif
		responseData[0]=mSequenceCouner;
		/// -# If the request is accepted then send positive response.
		mServiceManagerInstance.serviceResponseUpdate(
														clientAddress,
														CUdsServiceManagerIf::EResponseType_t::EResponse_Positive,
														responseData
														);
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
	UdsInstallerFileDownloadStatus DkMsgInstallerFileDownloadStatus; // DK message for FileOperationRequest
	//DkMsgInstallerFileDownloadStatus_t DkMsgInstallerFileOperationRequest; // DK message for FileOperationRequest

	fclose(mDownloadFile);
	mDownloadFile = 0;

	#ifdef UDSCFG_LOG_ENABLED
	LOGD(&gUdsBlServicesLogContext," Transfer exit service received for data length ", requestLength);
	#endif

	if(mFileTransferState != EFileTransferState_transferExit)
	{
		#ifdef UDSCFG_LOG_ENABLED
		LOGD(&gUdsBlServicesLogContext," Invalid transfer state ",EFileTransferState_transferExit);
		#endif
		/// -# If the current transfer state is not transfer exit then NRC RequestSequenceError should be updated
		responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestSequenceError;
	}
	else if (0 != requestLength)
	{
		responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_IncorrectMessageLengthOrInvalidFormat;
		#ifdef UDSCFG_LOG_ENABLED
		LOGD(
			&gUdsBlServicesLogContext,
			" Transfer Exit EResponseCode_IncorrectMessageLengthOrInvalidFormat "
			);
		#endif
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

	if (responseCode != CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
	{
		///-# If request not accepted then send negative response.
		mServiceManagerInstance.sendNegativeResponse(clientAddress,responseCode);
	}
	else
	{
		
		(void)extractGipFile(gipFilePath, gipDeltaFilePath);

		LOGD(&gUdsBlServicesLogContext," mTemporaryFileName: ", mTemporaryFileName);
		/// -# If request accepted , Send Message to Installer for file request update.
		mFileControlStatus.mModeOfOperation = EModeOfOperation_t::EModeOfOperation_addFile;
		mFileControlStatus.mRequestedFilenameWithPath = mTemporaryFileName;
		mFileControlStatus.mRequestedFilenameWithPathLen = static_cast<uint16_t>(mTemporaryFileName.length());
		mFileControlStatus.mTempFilenameWithPath = mTemporaryFileName;
		mFileControlStatus.mTempFilenameWithPathLen = static_cast<uint16_t>(mTemporaryFileName.length());

		mClientAddress = clientAddress;
		#ifdef UDSCFG_LOG_ENABLED
		LOGD(&gUdsBlServicesLogContext," Download file notification message sent to installer ",
				" File Name :", mFileControlStatus.mRequestedFilenameWithPath,
				" File Path Len: ", static_cast<uint32_t>( mFileControlStatus.mRequestedFilenameWithPathLen),
				" Temp File: ", mFileControlStatus.mTempFilenameWithPath,
				" Temp File Path Len: ", static_cast<uint32_t>(mFileControlStatus.mTempFilenameWithPathLen)
				);
		#endif
		DkMsgInstallerFileDownloadStatus.modeOfOperation = EFileModeOfOperation_AddFile ;
		DkMsgInstallerFileDownloadStatus.requestedFilenameWithPathLen = mFileControlStatus.mRequestedFilenameWithPathLen;

		(void)memcpy(
			   &DkMsgInstallerFileDownloadStatus.requestedFilenameWithPath[0],
			   &mFileControlStatus.mRequestedFilenameWithPath[0],
			   static_cast<uint32_t>(mFileControlStatus.mRequestedFilenameWithPathLen));

		DkMsgInstallerFileDownloadStatus.tempFilenameWithPathLen = mFileControlStatus.mTempFilenameWithPathLen;

		(void)memcpy(
			   &DkMsgInstallerFileDownloadStatus.tempFilenameWithPath[0],
			   &mFileControlStatus.mTempFilenameWithPath[0],
			   static_cast<uint32_t>(mFileControlStatus.mTempFilenameWithPathLen));


		//updateCustomSessionTimerConfig(0x02);
		DK_RTE_Send_UdsInstallerFileDownloadStatus(DkMsgInstallerFileDownloadStatus);

		/// update response to the tool
		/// no response data to be sent . Hence cleared the buffer.
		responseBuffer.clear();

		responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestCorrectlyReceivedResponsePending;

		// Send Pending response
		mServiceManagerInstance.sendNegativeResponse(clientAddress, responseCode);

		///-# Re-initialize download parameters to accept new transfer request.
		transferInit();
	}

	//DEBUG
	if( !access("/nand/fileInfo.bin" , F_OK ) )
	{
		remove("/nand/fileInfo.bin");
		LOGD(&gUdsBlServicesLogContext,"\n %s: removed fileInfo.bin\n", __func__);
	}
	else
	{
		LOGE(&gUdsBlServicesLogContext,"%s: Error, unable to find fileInfo \n", __func__);
	}
}

int32_t CUdsServiceDownloadHandler::extractGipFile(std::string file, std::string cache)
{
    pid_t unzip_pid;
    int32_t sts = -1;
    int32_t ret = -1;
    char *argv[7];

    std::string pdxFile;
    std::string pdxCache;

	SMetadata_t lMetadata;
	uint8_t currentVersion;

    pdxFile = file;
    pdxCache = cache;

    // Log the unpacking action
    LOGI(&gUdsBlServicesLogContext, "Unpacking file: ");
    LOGI(&gUdsBlServicesLogContext, file.c_str());

    argv[0] = (char*)"/proc/boot/unzip";  // Process name
    argv[1] = (char*)file.c_str();        // PDX file name
    argv[2] = (char*)"-o";                // Overwrite files
    argv[3] = (char*)"-qq";               // Quiet mode
    argv[4] = (char*)"-d";                // Output directory
    argv[5] = (char*)cache.c_str();       // Output directory Name
    argv[6] = NULL;

    ret = posix_spawn(&unzip_pid, "/proc/boot/unzip", NULL, NULL, argv, NULL);

	Metadata_GetInfo(&lMetadata);

	/*Read current version from metadata*/
	currentVersion = lMetadata.swPart[ESwPartId_System].partitionInfo[EPartition_A].version.patch;

	LOGI(&gUdsBlServicesLogContext, "Current Version : ", currentVersion);

    if (0 == ret)
    {
        if (-1 != waitpid(unzip_pid, &ret, 0))
        {
            LOGI(&gUdsBlServicesLogContext, "Unpack success");

			DIR* dir = opendir(gipDeltaFilePath.c_str());

			if (dir == nullptr) 
			{
				LOGI(&gUdsBlServicesLogContext, "Could not open fota cache");
				return 1;
			}

			struct dirent* entry;

			while ((entry = readdir(dir)) != NULL) 
			{
				std::string fileName = entry->d_name;
				
				if (fileName == "." || fileName == "..") 
				{
					continue;
				}

				LOGI(&gUdsBlServicesLogContext, "Unpacked file: ", fileName.c_str());

				gipVersionInfo version = extractVersionFromFilename(fileName);

				if (version.oldVersion != -1 && version.newVersion != -1) 
				{
					LOGE(&gUdsBlServicesLogContext, "Extracted Version : ",version.oldVersion,".",version.newVersion);

					if(currentVersion == version.oldVersion)
					{
						std::string fullPath = gipDeltaFilePath + '/' + fileName;

						mTemporaryFileName = fullPath.c_str();

						LOGI(&gUdsBlServicesLogContext, "Assigned File name : ", mTemporaryFileName.c_str());

						return 0;
					}
				}
			}

			closedir(dir);

            sts = 0;
        }
        else
        {
            LOGE(&gUdsBlServicesLogContext, "waitpid failed");
        }
    }
    else
    {
        LOGE(&gUdsBlServicesLogContext, "posix_spawn failed");
    }

    return sts;
}

gipVersionInfo CUdsServiceDownloadHandler::extractVersionFromFilename(const std::string& filename) 
{
    gipVersionInfo version = {-1, -1};

    size_t dotPosition = filename.rfind(".bin");

    if (dotPosition != std::string::npos && dotPosition >= 5) 
	{
		// Extract last 5 chars before .bin
        std::string versionPart = filename.substr(dotPosition - 5, 5); 
        
        if (versionPart[2] == '_') 
		{
            try 
			{
                version.oldVersion = std::stoi(versionPart.substr(0, 2));
                version.newVersion = std::stoi(versionPart.substr(3, 2));
            } 
			catch (...) 
			{
				LOGI(&gUdsBlServicesLogContext, "Invalid version format in filename : ", filename.c_str());
            }
        } 
		else 
		{
			LOGI(&gUdsBlServicesLogContext, "Unexpected version format : ", versionPart);
        }
    } 
	else 
	{
		LOGI(&gUdsBlServicesLogContext, "Could not parse version from filename : ", filename.c_str());
    }

    return version;
}

void CUdsServiceDownloadHandler::fileRequestInstallerResponseHandler(const uint8_t installerResponse)
{
	std::vector<uint8_t> responseBuffer;
	#ifdef UDSCFG_LOG_ENABLED
	LOGD(&gUdsBlServicesLogContext," Response received from installer ",installerResponse);
	#endif
	if (installerResponse == 0x00U)
	{
		/// no response data to be sent . Hence cleared the buffer.
		responseBuffer.clear();

		/// -# If installer response is not success , Update positive response.
		mServiceManagerInstance.serviceResponseUpdate(mClientAddress,
													CUdsServiceManagerIf::EResponseType_t::EResponse_Positive,
													responseBuffer
													);
	}
	else
	{
		///-# If installer response is not success then send NRC GeneralProgrammingFailure.
		 mServiceManagerInstance.sendNegativeResponse(mClientAddress,
					CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_GeneralProgrammingFailure);
	}
}

void CUdsServiceDownloadHandler::transferExitServicePostresponseHandler(const uint16_t clientAddress)
{
	#ifdef UDSCFG_LOG_ENABLED
	LOGI(&gUdsBlServicesLogContext," Transfer Exit Service post response Handler ",clientAddress);
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

CUdsServiceHandlerIf::EResponseCode_t CUdsServiceDownloadHandler::programData(const uint32_t dataLength, const uint8_t * const pData)
{
	CUdsServiceHandlerIf::EResponseCode_t responseCode; // response status

	if (mDownloadFile)
	{
		std::size_t bytes = std::fwrite(pData, 1, dataLength, mDownloadFile);
		if (bytes == dataLength)
		{
			/// -# If no error occurs when writing , update return status as NoError
			responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;
		}
		else
		{
			#ifdef UDSCFG_LOG_ENABLED
			LOGE(&gUdsBlServicesLogContext," File Write Failed ");
			#endif
			/// -# If error occurs when writing data ,update return status as  NRC GeneralProgrammingFailure
			responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_GeneralProgrammingFailure;
		}

	}
	else
	{
		#ifdef UDSCFG_LOG_ENABLED
		LOGE(&gUdsBlServicesLogContext," File Open error in programData");
		#endif
		responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_GeneralProgrammingFailure;
	}

	return responseCode;
}

CUdsServiceHandlerIf::EResponseCode_t CUdsServiceDownloadHandler::CreateFile(const std::string &fileName)
{
	std::ofstream downloadFile; // File stream for download file.
	CUdsServiceHandlerIf::EResponseCode_t responseCode;  // response status

	///-# Create a temporary file.
	// downloadFile.open(fileName,std::ios::binary|std::ios::trunc);
	downloadFile.open(fileName,std::ios::binary | std::ios::app);
	///-# Check whether file is created by opening the file.
	if (downloadFile.is_open())
	{
		///-# If the file can be opened ,then file is successfully created.
		#ifdef UDSCFG_LOG_ENABLED
		LOGD(&gUdsBlServicesLogContext,"Temporary file successfully created");
		#endif
		responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;
	}
	else
	{
		///-# If the file is not opened ,then file not created.
		#ifdef UDSCFG_LOG_ENABLED
		LOGE(&gUdsBlServicesLogContext," File Open error in programData");
		#endif
		responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_GeneralProgrammingFailure;
	}
	///-# Clear file operation error status if any.
	downloadFile.clear();
	///-# Close the file.
	downloadFile.close();
	///-# return response status.
	return responseCode;
}


#define UDS_REQ_DNLD_REQ_SIZE (10u)
#define UDS_REQ_DNLD_RESP_SIZE (4u)
#define UDS_REQ_DNLD_RESP_BLK_SIZE 4*1024 //(0x0E02u)//(0x0102u)
void CUdsServiceDownloadHandler::requestDownloadServiceRequestHandler(const uint16_t clientAddress,const uint8_t *const pRequestData,const uint16_t requestLength)
{
	/* @smerfu - Coverity Fix */
	CUdsServiceHandlerIf::EResponseCode_t responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError; // response status
	responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;
	std::vector<uint8_t> responseBuffer(static_cast<uint32_t>(5U));
	BlDiagRequest lBlDiagReq;

	#ifdef UDSCFG_LOG_ENABLED
	LOGD(&gUdsBlServicesLogContext," Request Download service received for data length ",requestLength);
	#endif

	uint32_t address;
	uint32_t size;

	if (NULL == pRequestData)
	{
		#ifdef UDSCFG_LOG_ENABLED
		LOGD(&gUdsBlServicesLogContext," pRequestData is Invalid ");
		#endif
		responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_IncorrectMessageLengthOrInvalidFormat;
	}
	else if(UDS_REQ_DNLD_REQ_SIZE != requestLength)
	{
		#ifdef UDSCFG_LOG_ENABLED
		LOGD(&gUdsBlServicesLogContext," Size mis-match requestLength ", requestLength, UDS_REQ_DNLD_REQ_SIZE);
		#endif
		responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_IncorrectMessageLengthOrInvalidFormat;
	}else if (mFileTransferState != EFileTransferState_default)
	{
		responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_ConditionsNotCorrect;
	}else
	{
		responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;
	}


	if (responseCode != CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
	{
		#ifdef UDSCFG_LOG_ENABLED
		LOGD(&gUdsBlServicesLogContext," If request not accepted then send negative response ", responseCode);
		#endif

		transferInit();

		///-# If request not accepted then send negative response.
		mServiceManagerInstance.sendNegativeResponse(clientAddress,responseCode);
	}
	else
	{
		#ifdef UDSCFG_LOG_ENABLED
		LOGD(&gUdsBlServicesLogContext," Frame Positive response ");
		#endif

		address = (((uint32_t)pRequestData[2] << 24u) |
					((uint32_t)pRequestData[3] << 16u) |
					((uint32_t)pRequestData[4] << 8u) |
					((uint32_t)pRequestData[5]));
		size = (((uint32_t)pRequestData[6] << 24u) |
				 ((uint32_t)pRequestData[7] << 16u) |
				 ((uint32_t)pRequestData[8] << 8u) |
				 ((uint32_t)pRequestData[9]));

		//Clear DTCs states
		/* Zone count is 1 => GIP */

		/* Check if the Address Matches */
		if(address != 0x60000000 && address != 0x0C000000)
		{
			#ifdef UDSCFG_LOG_ENABLED
			LOGD(&gUdsBlServicesLogContext, " Address Mismatch: ", address);
			#endif
			/* Address Mismatch -> Invalid req */
			//mServiceManagerInstance.sendNegativeResponse(clientAddress,responseCode);
			responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_IncorrectMessageLengthOrInvalidFormat;
			mServiceManagerInstance.sendNegativeResponse(clientAddress, responseCode);
			transferInit();
		}
		else if(size >= mUdsDownloadMaxFileSize)
		{
			#ifdef UDSCFG_LOG_ENABLED
			LOGD(&gUdsBlServicesLogContext,"Download File size above accepted range ",size);
			#endif

			transferInit();

			/// -# if modeOfOperation not supported the update 0x31 NRC
			responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestOutOfRange;
			mServiceManagerInstance.sendNegativeResponse(clientAddress, responseCode);
		}
		else
		{
			mTemporaryFileSize = size;
			mFileTransferState = EFileTransferState_transferData;

			if (address == 0x60000000)
			{
				mTemporaryFileName = "/fota_cache/gip.iso";
				lBlDiagReq.didId = 0xFD01;
			}
			else if (address == 0x0C000000)
			{
				mTemporaryFileName = "/fota_cache/vip_image.aes";
				lBlDiagReq.didId = 0xFD00;
			}

			LOGD(&gUdsBlServicesLogContext," mTemporaryFileName: ", mTemporaryFileName);

			mDownloadFile = fopen(mTemporaryFileName.data(), "w+b");

			if (mDownloadFile)
			{
				printf("Temporary file created: '%s'\n", mTemporaryFileName.data());
				/// -# Update positive response.
				/* mUdsDownloadResponseBlockSize */
				responseBuffer[0] = UDS_REQ_DNLD_RESP_SIZE << 4;
				responseBuffer[1] = (uint8_t)((UDS_REQ_DNLD_RESP_BLK_SIZE >> 24) & 0xFF);
				responseBuffer[2] = (uint8_t)((UDS_REQ_DNLD_RESP_BLK_SIZE >> 16) & 0xFF);
				responseBuffer[3] = (uint8_t)((UDS_REQ_DNLD_RESP_BLK_SIZE >>  8) & 0xFF);
				responseBuffer[4] = (uint8_t)((UDS_REQ_DNLD_RESP_BLK_SIZE      ) & 0xFF);

				// Inform Vip about download process
				lBlDiagReq.serviceId = 0x34;
				lBlDiagReq.contrlOpLen = 0U;
				lBlDiagReq.dataLen = 0U;
				DK_RTE_Send_BlGipDiagRequest(lBlDiagReq);

				/// -# If installer response is not success , Update positive response.
				mServiceManagerInstance.serviceResponseUpdate(clientAddress, CUdsServiceManagerIf::EResponseType_t::EResponse_Positive, responseBuffer);
			}
			else
			{
				printf("Error creating temporary file '%s'!\n", mTemporaryFileName.data());
				responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_GeneralReject;
				mServiceManagerInstance.sendNegativeResponse(clientAddress, responseCode);
			}
		 }
	 }
}

void CUdsServiceDownloadHandler::requestDownloadServicePostresponseHandler(const uint16_t clientAddress)
{
	#ifdef UDSCFG_LOG_ENABLED
	LOGD(&gUdsBlServicesLogContext," Request Download Service post response Handler ",clientAddress);
	#endif
}

void CUdsServiceDownloadHandler::requestDownloadServiceResetHandler(const uint16_t clientAddress)
{
	#ifdef UDSCFG_LOG_ENABLED
	LOGD(&gUdsBlServicesLogContext," Request Download Service reset handler ",clientAddress);
	#endif
	transferInit();
}

void CUdsServiceDownloadHandler::updateCustomSessionTimerConfig(uint8_t eSrvctypeID )
{
	UdsServiceSetTimings dkMsgUdsServiceSetTimings;
	/// -# Update the P2 timing parameters.
	dkMsgUdsServiceSetTimings.p2TimeMs = mServiceSessionTimerConfig[eSrvctypeID].mTimingConfig.mP2TimeMaxCountInMs;
	dkMsgUdsServiceSetTimings.p2StarTimeMs =mServiceSessionTimerConfig[eSrvctypeID].mTimingConfig.mP2StarTimeMinCountInMs;
	dkMsgUdsServiceSetTimings.p4TimeMs =mServiceSessionTimerConfig[eSrvctypeID].mTimingConfig.mP2StarTimeMaxCountInMs;
	#ifdef UDSCFG_LOG_ENABLED
	LOGD(
		&gUdsBlServicesLogContext,
		"Update UDS Timing parameters message sent for SrvcType ",
		eSrvctypeID,
		" p2TimeMs ",
		mServiceSessionTimerConfig[eSrvctypeID].mTimingConfig.mP2TimeMaxCountInMs,
		" p2StarTimeMs ",
		mServiceSessionTimerConfig[eSrvctypeID].mTimingConfig.mP2StarTimeMinCountInMs
		);
	#endif
	/// -# Send message to update the timing parameters for current session.
	DK_RTE_Send_UdsServiceSetTimings(dkMsgUdsServiceSetTimings);
}

void CUdsServiceDownloadHandler::installerFlashStatus(EInstallationStatus_t_t status)
{
	std::vector<uint8_t> responseBuffer;

	if(status == EInstallationStatus_Passed )
	{
		mServiceManagerInstance.serviceResponseUpdate(mClientAddress,
			CUdsServiceManagerIf::EResponseType_t::EResponse_Positive,
			responseBuffer
			);
	}
	else if (status == EInstallationStatus_Failed)
	{
		printf("UDS: installerFlashStatus::GeneralProgrammingFailure\n");
		mServiceManagerInstance.sendNegativeResponse(mClientAddress,
			CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_GeneralProgrammingFailure
		);
	}
	else
	{
		///<No Code Required
	}


}
} // udsblservices
} // app
} // dk

