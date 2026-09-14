#include <android/hardware/ucl/2.0/IUclCallback.h>
#include <hidl/LegacySupport.h>
#include <hidl/Status.h>
#include <hidl/LegacySupport.h>
#include <utils/misc.h>
#include <utils/Log.h>
#include <hidl/HidlSupport.h>
#include <hidl/HidlTransportSupport.h>
#include <unistd.h>
#include <log/log.h>
#include <utils/Errors.h>
#include <utils/StrongPointer.h>
#include <android/log.h>
#include<iostream>
#include <Ucl_Types.h>
#include <UclILStream_Channel_Types.h>
#include <UclILStreamHidlAdapter.h>
#include <UclILStream.h>
#include <UclILAdapter.h>
#include <UclSys.h>
#include <UclALDebug.h>
#include <Ucl_Version.h>

using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;
using android::hardware::ucl::V2_0::IUcl;
using android::hardware::ucl::V2_0::IUclCallback;
using namespace android::hardware::ucl::V2_0;
using namespace android::hardware::ucl::V2_0::implementation;
using namespace android;

android::sp<Ucl> Uclservice;
static bool UclServiceReg;

/// @defgroup UCL_CHN_FUNC UCL Channel APIs
/// @brief UCL Channel based APIs
/// @{
///
/// @brief  Open an UCL Channel
///
/// @param[in]  chId    Channel Identifier
/// @param[in]  flags   @ref UCL_O_FLAGS
///
/// @return > 0 File descriptor to be used
/// @return < 0 @ref UCL_ERR
///

Return<int32_t> Ucl::open( uint8_t chId, uint16_t flags )
{
    int32_t fd;

    std::lock_guard<std::mutex> lock( mClientRegLock );

    fd = UclILStream_Open( 0, chId, flags );

    /*if fd is sucess*/
    if (fd >= 0)
    {
		mFdList.push_back( fd );
        LOGI( 0u, "UclILStreamHidlAdapter", "Client is opened successfully,Filed ID: %d", fd );
    }
    else
    {
        LOGE( 0u, "UclILStreamHidlAdapter", "Client open failed,Filed ID: %d", fd );
    }

    return fd;
}

///
/// @brief  Close an UCL Channel
///
/// @param[in]  fd  File descriptor returned by the open call
///
/// @return @ref UCL_E_OK   Successfully closed the channel
/// @return @ref UCL_ERR
///
Return<int32_t> Ucl::close( int32_t fd )
{
    int32_t ret = -1;
    uint64_t index;

    std::lock_guard<std::mutex> lock( mClientRegLock );

    for(uint64_t i = 0; i < mFdList.size(); i++) 
	{
        if(mFdList[i] == fd)
         ret = UclILStream_Close( 0, fd );
    }

    if (ret >= 0)
    {
		
		/* Delete the fd list & Callback list*/
		for (index = 0; index < mIoctlCallbackReg.size(); index++)
		{
			if (mIoctlCallbackReg[index].first == fd)
			{
				{
					mIoctlCallbackReg.erase( mIoctlCallbackReg.begin() + index );
					LOGI( 0u, "UclILStreamHidlAdapter", "Unsubscribed callback,Filed ID: %d", fd );
				}
			}
		}
		for (index = 0; index < mFdList.size(); index++)
		{
			if (mFdList[index] == fd)
			{
				mFdList[index] = -1;
				mFdList.erase( mFdList.begin() + index );
				LOGI( 0u, "UclILStreamHidlAdapter", "Released FileId  ,Filed ID: %d", fd );
				LOGI( 0u, "UclILStreamHidlAdapter", "Client closed successfully,Filed ID: %d", fd );
			}
		}
		
    }
    else
    {
        LOGE( 0u, "UclILStreamHidlAdapter", "Client closure failed ,Filed ID: %d", fd );
    }

    return ret;
}

///
/// @brief  Read data from the UCL channel
///
/// @param[in]  fd      File descriptor returned by the open call
/// @param[out] pBuffer Buffer to return the received data
/// @param[in]  size    Size of the buffer
///
/// @return > 0 number of bytes read
/// @return < 0 @ref UCL_ERR
///
Return<void> Ucl::read( int32_t fd, read_cb _hidl_cb )
{
    int32_t sizeRead;
    hidl_vec < uint8_t > readBuffer;
    uint8_t buffer[2000];
    uint32_t size = 0;

    std::lock_guard < std::mutex > lock( mReadLock );

    sizeRead = UclILStream_Read( 0, fd, (uint8 *) &buffer, sizeof(buffer) );

    if (sizeRead > 0)
    {
        readBuffer.setToExternal( (uint8_t *) &buffer, sizeRead );
    }
    _hidl_cb( readBuffer, sizeRead );


    return Void();
}

///
/// @brief  Write data to the UCL channel
///
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  pBuffer Buffer that contains the data to be sent
/// @param[in]  size    Size of the buffer
///
/// @return > 0 number of bytes sent
/// @return < 0 @ref UCL_ERR
///

Return<int32_t> Ucl::write( int32_t fd, const hidl_vec<uint8_t>& data )
{
    int32_t byteSent;

    std::lock_guard < std::mutex > lock( mWriteLock );

    byteSent = UclILStream_Write( 0, fd, (uint8 *) data.data(), data.size() );


    return byteSent;
}

///
/// @brief  UCL Input/Output Control API to configure channel parameters
///
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  request @ref UCL_IOCTL
/// @param[in]  pData   Pointer to the structure corresponding to the request
/// @param[in]  size    Size of the structure
///
/// @return @ref UCL_E_OK   Success
/// @return @ref UCL_ERR
///
Return<void> Ucl::ioctl( int32_t fd, uint32_t request, const hidl_vec<uint8_t>& data, ioctl_cb _hidl_cb )
{
    int i;
    int32_t ret = 0;
    hidl_vec < uint8_t > getParam;

    std::lock_guard<std::mutex> lock( mIoctlLock );

    if (request == UCL_IOCTL_GET_CHANNEL_PARAM)
    {
        ucl_ioctl_channel_param_t chParam;
        ret = UclILStream_Ioctl( 0, fd, request, &chParam, sizeof(chParam) );

        if (ret >= 0)
        {
            getParam.setToExternal( (uint8_t *) &chParam, sizeof(chParam) );

        }
        _hidl_cb( getParam, ret );
    }

    else if (request == UCL_IOCTL_GET_STATS)
    {
        ucl_ioctl_channel_stats_t chStatus;
        ret = UclILStream_Ioctl( 0, fd, request, (void *) &chStatus, sizeof(chStatus) );

        if (ret >= 0)
        {
            getParam.setToExternal( (uint8_t *) &chStatus, sizeof(chStatus) );

        }

        _hidl_cb( getParam, ret );

    }

    else if (request == UCL_IOCTL_GET_LINK_STATUS)
    {
        uint8_t linkStatus;
        ret = UclILStream_Ioctl( 0, fd, request, (void *) &linkStatus, sizeof(linkStatus) );

        if (ret >= 0)
        {
            getParam.setToExternal( (uint8_t *) &linkStatus, sizeof(linkStatus) );

        }

        _hidl_cb( getParam, ret );

    }

    else
    {
        ret = UclILStream_Ioctl( 0, fd, request, (void *) data.data(), (uint16_t) data.size() );

        _hidl_cb( data, ret );

    }

    return Void();
}

///
/// @brief  Poll the UCL channel to check for receive data
///
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  timeout Timeout to wait for data
///
/// @return > 0 number of bytes waiting to be read
/// @return < 0 @ref UCL_ERR
///

Return<int32_t> Ucl::poll( int32_t fd, uint32_t timeout )
{
    int32_t byteRead;

    std::lock_guard<std::mutex> lock( mPollLock );

    byteRead = UclILStream_Poll( 0, fd, timeout );

    return byteRead;
}

///
/// @brief  Poll the UCL channel to check for transmit confirmation
///
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  reqId   Request ID used in the ucl_write_ex call
/// @param[in]  timeout Timeout to wait for the confirmation
///
/// @return @ref UCL_E_OK   Successfully sent
/// @return < 0 @ref UCL_ERR
///
Return<int32_t> Ucl::poll_ex( int32_t fd, uint8_t reqId, uint32_t timeout )
{
    int32_t ret;

    ret = UclILStream_PollEx( 0, fd, reqId, NULL, timeout );

    return ret;
}
///
/// @brief  Write data to the UCL channel along with the request id
///
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  reqId   Request ID to be associated with this write request
/// @param[in]  pBuffer Buffer that contains the data to be sent
/// @param[in]  size    Size of the buffer
///
/// @return > 0 number of bytes sent
/// @return < 0 @ref UCL_ERR
///
Return<int32_t> Ucl::write_ex( int32_t fd, uint8_t reqId, const hidl_vec<uint8_t>& data )
{
    int32_t byteSent;

    std::lock_guard<std::mutex> lock( mWriteExLock );

    byteSent = UclILStream_WriteEx( 0, fd, reqId, (uint8 *) data.data(), data.size() );

    return byteSent;
}
/// @brief  UCL Input/Output Control API to configure channel parameters
///
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  callback Subscribe callback for the interface
///
/// @return @ref UCL_E_OK   Success
/// @return @ref UCL_ERR
/// @return

Return<int32_t> Ucl::ioctl_register_callback( int32_t fd, const sp<::android::hardware::ucl::V2_0::IUclCallback>& callback )
{
    int32_t ret = -1;
    unsigned long index;
    int32_t linkStatus;

    std::lock_guard<std::mutex> lock( mClientRegLock );

    LOGI( 0u, "UclILStreamHidlAdapter", " call back registration invoked in UCL server,Filed ID: %d", fd );

    for (index = 0; index < mFdList.size(); index++)
    {
        if ((mFdList[index] == fd) && (callback != NULL))
        {
            ret = 0;
            mIoctlCallbackReg.push_back( std::make_pair( fd, callback ) );
            callback->linkToDeath( this, (uint64_t) fd );
            LOGI( 0u, "UclILStreamHidlAdapter", " call back registration Success,Filed ID: %d", fd );
            ret = UclILStream_Ioctl( 0, fd, UCL_IOCTL_GET_LINK_STATUS, (void *) &linkStatus, sizeof(linkStatus) );

            if (ret >= 0)
            {
                auto hidl_status = callback->LinkStatusChanged( fd, linkStatus );

                if (!hidl_status.isOk())
                {
                    LOGI( 0u, "UclILStreamHidlAdapter", "Unable to invoke callback File ID: %d", fd );
                }
            }
            break;
        }

    }

    if (ret < 0)
    {
        LOGE( 0u, "UclILStreamHidlAdapter", "%s", "Invalid Fd :" );
        LOGE( 0u, "UclILStreamHidlAdapter", "Fd Callback registration failed, File id : %d", fd );
    }

    return ret;
}

extern "C" void UclILStream_Adapter_ErrorNotification(  uint8 DLInst, sint32 ErrorCode )
{
    unsigned long index;
	std::vector<std::pair<int32_t, sp<IUclCallback>>> lCbkReg;

    if (UclServiceReg == TRUE ) 
    {
		lCbkReg = Uclservice->mIoctlCallbackReg;

        /*Send Ucl error notification to all ucl clients*/
        for (index = 0; index < lCbkReg.size(); index++)
        {
            if ((lCbkReg[index].second != NULL))
            {
                auto hidl_status = lCbkReg[index].second->ErrorNotification(lCbkReg[index].first, ErrorCode );
                if (!hidl_status.isOk())
                {
                    LOGE( 0u, "UclILStreamHidlAdapter", "Unable to invoke callback: %s", "ErrorNotification" );
                }
            }
        }
    }

}

extern "C" void UclILStream_Adapter_QueueFullNotification( sint32 fd ,sint32 ErrorCode )
{
    unsigned long index;
    bool Result = FALSE;
    std::vector<std::pair<int32_t, sp<IUclCallback>>> lCbkReg;

    if (UclServiceReg == TRUE )
    {
		lCbkReg = Uclservice->mIoctlCallbackReg;
        ///< Send UCL error notification to all UCL clients
        for (index = 0; index < lCbkReg.size(); index++)
        {
            if (lCbkReg[index].first == fd)
            {
                if ((lCbkReg[index].second != NULL))
                {
                    auto hidl_status = lCbkReg[index].second->ErrorNotification( lCbkReg[index].first,ErrorCode );

                    if (!hidl_status.isOk())
                    {
                        LOGE( 0u, "UclILStreamHidlAdapter", "Unable to invoke callback: %s", "Error Notification" );
                    }
                    Result = TRUE;
                    break;
                }
            }
        }

        if (Result == FALSE )
        {
            LOGE( 0u, "UclILStreamHidlAdapter", "UCL Error Notification Callback to filed id : %ld failed", fd );
        }
    }
}

extern "C" void UclILStream_Adapter_LinkStatusChanged(  uint8 DLInst, sint32 Status )
{
    unsigned long index;
	std::vector<std::pair<int32_t, sp<IUclCallback>>> lCbkReg;

    if (UclServiceReg == TRUE )
    {
		lCbkReg = Uclservice->mIoctlCallbackReg;
        for (index = 0; index < lCbkReg.size(); index++)
        {
            if ((lCbkReg[index].second != NULL))
            {
                auto hidl_status = lCbkReg[index].second->LinkStatusChanged(lCbkReg[index].first, Status );
                if (!hidl_status.isOk())
                {
                    LOGE( 0u, "UclILStreamHidlAdapter", "Unable to invoke callback: %s", "LinkStatusChanged" );
                }

            }
        }
    }

}

extern "C" void UclILStream_Adapter_MessageTransmitStatus( sint32 fd, uint8_t reqId, sint32 Status )
{
    unsigned long index;
    bool Result = FALSE;
	std::vector<std::pair<int32_t, sp<IUclCallback>>> lCbkReg;

    /*Send Ucl error notification to all ucl clients*/
    if (UclServiceReg == TRUE )
    {
		lCbkReg = Uclservice->mIoctlCallbackReg;
        for (index = 0; index < lCbkReg.size(); index++)
        {
            if (lCbkReg[index].first == fd)
            {
                if ((lCbkReg[index].second != NULL))
                {
                    auto hidl_status = lCbkReg[index].second->MessageTransmitStatus(lCbkReg[index].first, reqId, Status );

                    if (!hidl_status.isOk())
                    {
                        LOGI( 0u, "UclILStreamHidlAdapter", "Unable to invoke callback: %s", "MessageTransmitStatus" );
                    }
                    Result = TRUE;
                    break;
                }
            }
        }

        if (Result == FALSE )
        {
            LOGE( 0u, "UclILStreamHidlAdapter", "UCL Transmit Status Callback to filed id : %ld failed", fd );

        }
    }
}

extern "C" void UclILStream_Adapter_DataReceived( sint32 fd )
{
    unsigned long index;
    bool Result = FALSE;
	std::vector<std::pair<int32_t, sp<IUclCallback>>> lCbkReg;

    if (UclServiceReg == TRUE )
    {
		lCbkReg = Uclservice->mIoctlCallbackReg;
        /*Send Ucl error notification to all ucl clients*/
        for (index = 0; index < lCbkReg.size(); index++)
        {
            if (lCbkReg[index].first == fd)
            {
                if ((lCbkReg[index].second != NULL))
                {
                    auto hidl_status = lCbkReg[index].second->DataReceivedNotification(
                                    lCbkReg[index].first);

                    if (!hidl_status.isOk())
                    {
                        LOGE( 0u, "UclILStreamHidlAdapter", "Unable to invoke callback: %s",
                                        "DataReceivedNotification" );

                    }
                    Result = TRUE;
                    break;
                }
            }
        }

        if (Result == FALSE )
        {
            LOGE( 0u, "UclILStreamHidlAdapter", "UCL data received Callback to filed id : %ld failed", fd );

        }
    }

}

void Ucl::serviceDied( uint64_t cookie, const wp<IBase>& who )
{
    bool res;
	std::lock_guard<std::mutex> lock( mClientRegLock );
    LOGI( 0u, "UclILStreamHidlAdapter", "An Ucl client Died :  value is : %lu", cookie );
    res = unregisterCallback( who.promote(), cookie );
}

bool Ucl::unregisterCallback( const sp<IBase>& callback, uint64_t deathClientId )
{
    bool Res = FALSE;
    unsigned long index;
    int32_t fileId;

    fileId = (int32_t) deathClientId;

    if (callback != NULL)
    {
        /*Send Ucl error notification to all ucl clients*/
        for (index = 0; index < mIoctlCallbackReg.size(); index++)
        {
            if (mIoctlCallbackReg[index].first == fileId)
            {

                LOGI( 0u, "UclILStreamHidlAdapter", "Death Notification Received :  FileId is : %lu", fileId );

                (void) UclILStream_Close( 0, fileId );
                /* Delete the fd list & Callback list*/
                for (index = 0; index < mIoctlCallbackReg.size(); index++)
                {
                    if (mIoctlCallbackReg[index].first == fileId)
                    {
                        {
                            mIoctlCallbackReg[index].second = NULL;
                            mIoctlCallbackReg[index].first = -1;
                            mIoctlCallbackReg.erase( mIoctlCallbackReg.begin() + index );
                            LOGI( 0u, "UclILStreamHidlAdapter", "Unsubscribed callback,Filed ID: %d", fileId );
                            Res = TRUE;
                        }
                    }
                }

                for (index = 0; index < mFdList.size(); index++)
                {
                    if (mFdList[index] == fileId)
                    {
                        mFdList[index] = -1;
                        mFdList.erase( mFdList.begin() + index );
                        LOGI( 0u, "UclILStreamHidlAdapter", "Released FileId  ,Filed ID: %d", fileId );
                        LOGI( 0u, "UclILStreamHidlAdapter", "Client closed successfully,Filed ID: %d", fileId );
                        Res = TRUE;

                    }
                }

            }
        }
    }

    if (Res == FALSE )
    {
        LOGE( 0u, "UclILStreamHidlAdapter", "Unknown death notification FileId received: %d", fileId );
    }

    return Res;
}

void UclGen_HidlServerShutdown()
{
    UclServiceReg = FALSE;
    Uclservice->mIoctlCallbackReg.clear();
    Uclservice->mFdList.clear();
    UclSys_Shutdown( 0 );
}

int UclGen_HidlServerInit()
{
    int Ret = -1;
    Ucl_ReturnType sysInit;

    UclServiceReg = FALSE;

    LOGI( 0u, "UclILStreamHidlAdapter", "UCL STREAM VERSION : %s", UCL_VERSION );
    sysInit = UclSys_Initialize( 0 );

    if (sysInit >= 0)
    {
        LOGI( 0u,"UclILStreamHidlAdapter", "%s", "UCL service is starting : ");

        Uclservice = new Ucl();
        Uclservice->mIoctlCallbackReg.clear();
        Uclservice->mFdList.clear();
        LOGI( 0u, "UclILStreamHidlAdapter", "%s", "UCL  Service registered successfully :" )

        configureRpcThreadpool( 10, true );

        // Register our service -- if somebody is already registered by our name,
        // they will be killed (their thread pool will throw an exception).
        status_t status = Uclservice->registerAsService();
        if (status == OK)
        {
            //  ALOGD( "UCL service is ready.");
            UclServiceReg = TRUE;
            LOGI( 0u, "UclILStreamHidlAdapter", "%s", "Ucl service is ready ");

            Ret = 0;

            joinRpcThreadpool();
        }
        else
        {
            LOGE( 0u, "UclILStreamHidlAdapter", "%s", "Ucl service failed to register" );
        }
    }

    return Ret;
}
