/*
 * Copyright 2022, QNX Software Systems.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject
 * to the following conditions:
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include <inttypes.h>
#include <dlfcn.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h> // calloc
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <string.h>
#include <stdbool.h>
#include <gulliver.h>
#include "OMX_Extension_video_TI.h"
#include "omxil.h"
#include "log.h"
#include "config_parser.h"

#define OMX_SPEC_VERSION 0x00000001     // OMX Version
#define SET_OMX_VERSION_SIZE( param, size ) {             \
    param.nVersion.nVersion = OMX_SPEC_VERSION;           \
    param.nSize = size;                                   \
}

#define TIMEOUT_WAIT (5000 * 1000LL * 1000LL)  /* 5000 ms */

const char* OmxErrorTypeToStr( OMX_ERRORTYPE  err )
{
  const char *str = "Unknown error";
  switch( err )
  {
    case OMX_ErrorNone:                               str = "OMX_ErrorNone";                               break;
    case OMX_ErrorInsufficientResources:              str = "OMX_ErrorInsufficientResources";              break;
    case OMX_ErrorUndefined:                          str = "OMX_ErrorUndefined";                          break;
    case OMX_ErrorInvalidComponentName:               str = "OMX_ErrorInvalidComponentName";               break;
    case OMX_ErrorComponentNotFound:                  str = "OMX_ErrorComponentNotFound";                  break;
    case OMX_ErrorInvalidComponent:                   str = "OMX_ErrorInvalidComponent";                   break;
    case OMX_ErrorBadParameter:                       str = "OMX_ErrorBadParameter";                       break;
    case OMX_ErrorNotImplemented:                     str = "OMX_ErrorNotImplemented";                     break;
    case OMX_ErrorUnderflow:                          str = "OMX_ErrorUnderflow";                          break;
    case OMX_ErrorOverflow:                           str = "OMX_ErrorOverflow";                           break;
    case OMX_ErrorHardware:                           str = "OMX_ErrorHardware";                           break;
    case OMX_ErrorInvalidState:                       str = "OMX_ErrorInvalidState";                       break;
    case OMX_ErrorStreamCorrupt:                      str = "OMX_ErrorStreamCorrupt";                      break;
    case OMX_ErrorPortsNotCompatible:                 str = "OMX_ErrorPortsNotCompatible";                 break;
    case OMX_ErrorResourcesLost:                      str = "OMX_ErrorResourcesLost";                      break;
    case OMX_ErrorNoMore:                             str = "OMX_ErrorNoMore";                             break;
    case OMX_ErrorVersionMismatch:                    str = "OMX_ErrorVersionMismatch";                    break;
    case OMX_ErrorNotReady:                           str = "OMX_ErrorNotReady";                           break;
    case OMX_ErrorTimeout:                            str = "OMX_ErrorTimeout";                            break;
    case OMX_ErrorSameState:                          str = "OMX_ErrorSameState";                          break;
    case OMX_ErrorResourcesPreempted:                 str = "OMX_ErrorResourcesPreempted";                 break;
    case OMX_ErrorPortUnresponsiveDuringAllocation:   str = "OMX_ErrorPortUnresponsiveDuringAllocation";   break;
    case OMX_ErrorPortUnresponsiveDuringDeallocation: str = "OMX_ErrorPortUnresponsiveDuringDeallocation"; break;
    case OMX_ErrorPortUnresponsiveDuringStop:         str = "OMX_ErrorPortUnresponsiveDuringStop";         break;
    case OMX_ErrorIncorrectStateTransition:           str = "OMX_ErrorIncorrectStateTransition";           break;
    case OMX_ErrorIncorrectStateOperation:            str = "OMX_ErrorIncorrectStateOperation";            break;
    case OMX_ErrorUnsupportedSetting:                 str = "OMX_ErrorUnsupportedSetting";                 break;
    case OMX_ErrorUnsupportedIndex:                   str = "OMX_ErrorUnsupportedIndex";                   break;
    case OMX_ErrorBadPortIndex:                       str = "OMX_ErrorBadPortIndex";                       break;
    case OMX_ErrorPortUnpopulated:                    str = "OMX_ErrorPortUnpopulated";                    break;
    case OMX_ErrorComponentSuspended:                 str = "OMX_ErrorComponentSuspended";                 break;
    case OMX_ErrorDynamicResourcesUnavailable:        str = "OMX_ErrorDynamicResourcesUnavailable";        break;
    case OMX_ErrorMbErrorsInFrame:                    str = "OMX_ErrorMbErrorsInFrame";                    break;
    case OMX_ErrorFormatNotDetected:                  str = "OMX_ErrorFormatNotDetected";                  break;
    case OMX_ErrorContentPipeOpenFailed:              str = "OMX_ErrorContentPipeOpenFailed";              break;
    case OMX_ErrorContentPipeCreationFailed:          str = "OMX_ErrorContentPipeCreationFailed";          break;
    case OMX_ErrorSeperateTablesUsed:                 str = "OMX_ErrorSeperateTablesUsed";                 break;
    case OMX_ErrorTunnelingUnsupported:               str = "OMX_ErrorTunnelingUnsupported";               break;
    default: LOG(LOG_ERROR, "OmxilDec:%s Unknown OMX_ERRORTYPE=0x%x", __func__, err);      break;
  }
  return str;
}

static void logtofile(int fd, struct timespec *ts, const char *fmt, ... )
{
    static char linebuf[ LINE_MAX + 2 ];
    size_t offs = 0;
    size_t space = sizeof linebuf;
    int    len;
    struct tm tm;
    if ( localtime_r( &ts->tv_sec, &tm ) != NULL
            && ( len = strftime( linebuf, sizeof linebuf, "%F %T", &tm ) ) > 0 ) {
        offs  += len;
        space -= len;
        len = snprintf( linebuf+offs, space, ".%03u ", (unsigned)( ts->tv_nsec / 1000000 ) );
        if ( (size_t) len < space ) {
            offs  += len;
            space -= len;
        }
    }

    len = snprintf( linebuf+offs, space, "[OpenMAXIL.] ");
    if ( (size_t) len < space ) {
        offs  += len;
        space -= len;
    }
    va_list arglist;
    va_start(arglist, fmt);
    if ( ( len = vsnprintf( linebuf+offs, space, fmt, arglist ) ) > 0 ) {
        if ( len < (int)space ) {
            offs += len;
        } else {
            // It's been truncated.
            offs = sizeof linebuf - 1;
        }
        linebuf[ offs++ ] = '\n';
        write(fd, linebuf, offs);
    }
    va_end(arglist);
}

#define PERFORMANCE_LOG(fd, ...) (logtofile(fd, __VA_ARGS__))

//------------------------------------------------------------------------------
void OmxilVideoDec::timedwait(const char *caller )
{
    // !!! the mutex is already being held by the caller
    struct timespec to;
    clock_gettime( CLOCK_MONOTONIC, &to );
    nsec2timespec( &to, timespec2nsec( &to ) + TIMEOUT_WAIT );
    int r = pthread_cond_timedwait( &cond, &mutex, &to );
    switch ( r ) {
    case EOK:
        break;
    case ETIMEDOUT:
        LOG( LOG_ERROR, "OmxilDec=> %s timed-out", caller );
        compError = OMX_ErrorTimeout;
        break;
    default:
        LOG( LOG_ERROR, "OmxilDec=> %s undefined error: %d", caller, r );
        compError = OMX_ErrorUndefined;
    }
}

OMX_ERRORTYPE OmxilVideoDec::waitForCommandComplete()
{
    pthread_mutex_lock( &mutex );
    while( !cmdComplete && compError == OMX_ErrorNone) {
        timedwait( __func__ );
    }
    OMX_ERRORTYPE err = compError;
    pthread_mutex_unlock( &mutex );
    return err;
}

/**
 * decoder_file_push_thread
 */
void OmxilVideoDec::decoder_file_push_thread()
{
    pthread_setname_np(pthread_self(), "decoder_file_push_thread");
    LOG(LOG_DEBUG2,"decoder_file_push_thread has started \n");

    OMX_ERRORTYPE omxErr;

    while(!exit_thread) {
        pthread_mutex_lock(&mutex);
        if (compError != OMX_ErrorNone || eos_received) {
            LOG(LOG_DEBUG2,"decoder_player_push_thread bailed %d\n",__LINE__);
            pthread_mutex_unlock(&mutex);
            break;
        }
        if(portSettingChanged) {
            omxErr = ReconfigVdecSession();
            if( omxErr != OMX_ErrorNone ) {
                LOG( LOG_ERROR, "OmxilDec=> ReconfigVdecSession: return omxErr=%08x", omxErr );
                pthread_mutex_unlock(&mutex);
                break;
            }
        }

        while(!(qOutputBufHdr.empty()))
        {
            OMX_BUFFERHEADERTYPE *oBufHdr = qOutputBufHdr.front();
            omxErr = OMX_FillThisBuffer( compHandle, oBufHdr);
            if( omxErr != OMX_ErrorNone ) {
                LOG( LOG_ERROR, "OmxilDec=> OMX_FillThisBuffer: return omxErr=%08x", omxErr );
                break;
            }
            qOutputBufHdr.pop();
            if(frame_rate_control) {
                struct timespec ts;
                clock_gettime(CLOCK_MONOTONIC, &ts);
                uint64_t curr_time = (ts.tv_sec * 1000000) + (ts.tv_nsec / 1000);
                uint32_t dtime = (uint32_t)(curr_time - last_frame_ts);
                if(dtime < frame_duration) {
                    usleep((frame_duration - dtime)/2);
                }
                last_frame_ts = curr_time;
            }
            
        }
        OMX_BUFFERHEADERTYPE *buffer = NULL;
        if(!eos_sent)
            buffer = GetInputFrame();

        if (buffer) {
            if(log_fd != -1) {
                struct timespec ts;
                clock_gettime(CLOCK_MONOTONIC, &ts);
                uint64_t curr_time = (timespec2nsec( &ts ) / 1000LL);
                qTimeStamp.push(curr_time);
                PERFORMANCE_LOG(log_fd, &ts, "Send frame %d in, frame length: %d\n", nInFrameCount, buffer->nFilledLen);
                if(nInFrameCount == 0) {
                    startTime = curr_time;
                }
            }

            omxErr = OMX_EmptyThisBuffer( compHandle, buffer);
            if( omxErr != OMX_ErrorNone ) {
                LOG( LOG_ERROR, "OmxilDec=> OMX_EmptyThisBuffer: return omxErr=%08x", omxErr );
                pthread_mutex_unlock(&mutex);
                break;
            }
            nInFrameCount++;
        } else {
            pthread_cond_wait( &cond, &mutex );
        }
        pthread_mutex_unlock(&mutex);

    }
    LOG(LOG_DEBUG2,"decoder_file_push_thread has stopped");
}

static OMX_ERRORTYPE EventHandler(
    OMX_HANDLETYPE hComponent,
    OMX_PTR pAppData,
    OMX_EVENTTYPE eEvent,
    OMX_U32 nData1,
    OMX_U32 nData2,
    OMX_PTR pEventData )
{
    OmxilVideoDec *decH = (OmxilVideoDec*) pAppData;
    return decH->ProcessEvent(hComponent, eEvent, nData1, nData2, pEventData);
}
//------------------------------------------------------------------------------
OMX_ERRORTYPE OmxilVideoDec::ProcessEvent(
    OMX_HANDLETYPE hComponent,
    OMX_EVENTTYPE eEvent,
    OMX_U32 nData1,
    OMX_U32 nData2,
    OMX_PTR pEventData )
{
    OMX_ERRORTYPE omxErr = OMX_ErrorNone;

    if( compHandle == NULL) {
        LOG( LOG_ERROR, "OmxilDec=> EventHandler: compHandle is NULL" );
        return OMX_ErrorUndefined;
    }

    switch( eEvent ) {
        case OMX_EventError:
        {
            if( hComponent == compHandle ) {
                if (OMX_ErrorStreamCorrupt == (OMX_ERRORTYPE) nData1) {
                    LOG(LOG_ERROR, "OmxilDec:%s corrupted stream detected; continuing...", __func__);
                } else {
                    pthread_mutex_lock( &mutex );
                    compError = (OMX_ERRORTYPE) nData1;
                    LOG(LOG_ERROR, "OmxilDec:%s err=0x%x:'%s' ", __func__, compError, OmxErrorTypeToStr(compError));
                    pthread_cond_broadcast( &cond );
                    pthread_mutex_unlock( &mutex );
                }
            }

            break;
        }

        case OMX_EventCmdComplete:
        {
            switch( (OMX_COMMANDTYPE) nData1 ) {
                case OMX_CommandStateSet:
                {
                    // In this case, nData2 is the arrived at state
                    if( hComponent == compHandle ) {
                        LOG( LOG_INFO,
                                  "OmxilDec=> Reached compState: %d, ",
                                  (OMX_STATETYPE) nData2);
                        pthread_mutex_lock( &mutex );
                        cmdComplete = true;
                        pthread_cond_signal( &cond );
                        pthread_mutex_unlock( &mutex );

                    }

                    break;
                }

                case OMX_CommandFlush:
                    if( hComponent == compHandle ) {
                        pthread_mutex_lock( &mutex );
                        if(nData2 == inPortIndex)
                            inPortFlushed = true;
                        if(nData2 == outPortIndex)
                            outPortFlushed = true;
                        if(outPortFlushed && inPortFlushed) {
                            cmdComplete = true;
                            pthread_cond_signal( &cond );
                        }
                        pthread_mutex_unlock( &mutex );
                    }
                    break;

                case OMX_CommandPortDisable:
                case OMX_CommandPortEnable:
                    if( hComponent == compHandle ) {
                        pthread_mutex_lock( &mutex );
                        cmdComplete = true;
                        pthread_cond_signal( &cond );
                        pthread_mutex_unlock( &mutex );
                    }
                    break;
                default:
                    // do nothing
                    break;
            }

            break;
        }

        case OMX_EventBufferFlag:
        {
            if( nData2 & OMX_BUFFERFLAG_EOS ) {
                LOG( LOG_INFO, "OmxilDec=> Component detected EOS(%d,%d), ", nInFrameCount, nOutFrameCount);
                struct timespec to;
                clock_gettime(CLOCK_MONOTONIC, &to);
                stopTime = (timespec2nsec( &to ) / 1000LL);

                pthread_mutex_lock( &mutex );
                eos_received = true;
                pthread_cond_signal( &cond );
                pthread_mutex_unlock( &mutex );
            }

            break;
        }

        case OMX_EventPortSettingsChanged:
        {
            if( hComponent == compHandle ) {
                OMX_PARAM_PORTDEFINITIONTYPE portParam;
                OMX_ERRORTYPE omxErr = OMX_ErrorNone;

                LOG( LOG_INFO, "OmxilDec=> port settings changed %u %u, hComponent=%p", nData1, nData2, hComponent );
                pthread_mutex_lock( &mutex );
                SET_OMX_VERSION_SIZE( portParam, sizeof(portParam) );
                portParam.nPortIndex = outPortIndex;
                omxErr = OMX_GetParameter( compHandle,
                        OMX_IndexParamPortDefinition,
                        &portParam);
                if( omxErr != OMX_ErrorNone ) {
                    LOG( LOG_ERROR, "OmxilDec=> %s:%d OutPort OMX_GetParameter() returned 0x%08x", __func__, __LINE__, omxErr );
                }

                LOG( LOG_DEBUG1,
                          "OmxilDec=>  nbuffers=%u, ofsize=%u, oheight=%u, owidth=%u, nBufferCountMin=%u",
                          portParam.nBufferCountActual,
                          portParam.nBufferSize,
                          portParam.format.video.nFrameHeight,
                          portParam.format.video.nFrameWidth,
                          portParam.nBufferCountMin );

                portSettingChanged = true;
                pthread_cond_signal( &cond );
                pthread_mutex_unlock( &mutex );
            }
            break;
        }

        default:
            LOG( LOG_INFO, "OmxilDec=> Event %d %u %u ", eEvent, nData1, nData2);
            break;
    }

    return omxErr;

}

//------------------------------------------------------------------------------
static OMX_ERRORTYPE EmptyBufferDone(
    OMX_HANDLETYPE hComponent,
    OMX_PTR pAppData,
    OMX_BUFFERHEADERTYPE *pBufHdr )
{
    OmxilVideoDec *decH = (OmxilVideoDec*) pAppData;
    return decH->ProcessEmptyBufferDone(hComponent, pBufHdr);
}

//------------------------------------------------------------------------------
OMX_ERRORTYPE OmxilVideoDec::ProcessEmptyBufferDone(
    OMX_HANDLETYPE hComponent,
    OMX_BUFFERHEADERTYPE *pBufHdr )
{
    OMX_ERRORTYPE err = OMX_ErrorNone;

    if( compHandle != hComponent ) {
        LOG( LOG_ERROR, "OmxilDec=> EmptyBufferDone Unknown Component %p", hComponent );
        return OMX_ErrorNone;
    }

    pthread_mutex_lock( &mutex );
    pBufHdr->nFlags = 0;
    qInputBufHdr.push(pBufHdr);
    pthread_cond_signal( &cond );
    pthread_mutex_unlock( &mutex );

    return err;
}

//------------------------------------------------------------------------------
static OMX_ERRORTYPE FillBufferDone(
    OMX_HANDLETYPE hComponent,
    OMX_PTR pAppData,
    OMX_BUFFERHEADERTYPE *pBufHdr )
{
    OmxilVideoDec *decH = (OmxilVideoDec*) pAppData;
    return decH->ProcessFillBufferDone(hComponent, pBufHdr);
}

void OmxilVideoDec::saveOutputNV12(OmxilDecOutputBuffer_t *buf)
{
    int line;
    uint8_t *waddr = (uint8_t *)buf->addr;
    int wlen = src_width;

    //write Y plane
    for(line = 0; line < src_height; line++){
        int r = write(out_fd,
                (waddr + (stride * line)),
                wlen);
        if(r != wlen) {
            LOG(LOG_ERROR, "%s:%d write error", __func__, __LINE__);
            return;
        }
    }
    //write UV plane
    wlen = src_width;
    waddr = (uint8_t*)buf->addr + stride * aligned_height;
    for(line = 0; line < src_height/2; line++){
        int r = write(out_fd,
                (waddr + (stride * line)),
                wlen);
        if(r != wlen) {
            LOG(LOG_ERROR, "%s:%d write error", __func__, __LINE__);
            return;
        }
    }
}

void OmxilVideoDec::saveOutputNV16(OmxilDecOutputBuffer_t *buf)
{
    int line;
    uint8_t *waddr = (uint8_t *)buf->addr;
    int wlen = src_width;

    //write Y plane
    for(line = 0; line < src_height; line++){
        int r = write(out_fd,
                (waddr + (aligned_width * line)),
                wlen);
        if(r != wlen) {
            LOG(LOG_ERROR, "%s:%d write error", __func__, __LINE__);
            return;
        }
    }
    //write UV plane
    wlen = src_width;
    waddr = (uint8_t*)buf->addr + aligned_width * aligned_height;
    for(line = 0; line < src_height; line++){
        int r = write(out_fd,
                (waddr + (aligned_width * line)),
                wlen);
        if(r != wlen) {
            LOG(LOG_ERROR, "%s:%d write error", __func__, __LINE__);
            return;
        }
    }
}

void OmxilVideoDec::saveOutput1210(OmxilDecOutputBuffer_t *buf)
{
    int line;
    uint8_t *waddr = (uint8_t *)buf->addr;
    int wlen = src_width * 2;

    //write Y plane
    for(line = 0; line < src_height; line++){
        int r = write(out_fd,
                (waddr + (aligned_width * line * 2)),
                wlen);
        if(r != wlen) {
            LOG(LOG_ERROR, "%s:%d write error", __func__, __LINE__);
            return;
        }
    }
    //write UV plane
    wlen = src_width * 2;
    waddr = (uint8_t*)buf->addr + aligned_width * aligned_height * 2;
    for(line = 0; line < src_height/2; line++){
        int r = write(out_fd,
                (waddr + (aligned_width * line * 2)),
                wlen);
        if(r != wlen) {
            LOG(LOG_ERROR, "%s:%d write error", __func__, __LINE__);
            return;
        }
    }
}

void OmxilVideoDec::saveOutput1610(OmxilDecOutputBuffer_t *buf)
{
    int line;
    uint8_t *waddr = (uint8_t *)buf->addr;
    int wlen = src_width * 2;

    //write Y plane
    for(line = 0; line < src_height; line++){
        int r = write(out_fd,
                (waddr + (aligned_width * line * 2)),
                wlen);
        if(r != wlen) {
            LOG(LOG_ERROR, "%s:%d write error", __func__, __LINE__);
            return;
        }
    }
    //write UV plane
    wlen = src_width * 2;
    waddr = (uint8_t*)buf->addr + aligned_width * aligned_height * 2;
    for(line = 0; line < src_height; line++){
        int r = write(out_fd,
                (waddr + (aligned_width * line * 2)),
                wlen);
        if(r != wlen) {
            LOG(LOG_ERROR, "%s:%d write error", __func__, __LINE__);
            return;
        }
    }
}

//------------------------------------------------------------------------------
OMX_ERRORTYPE OmxilVideoDec::ProcessFillBufferDone(
    OMX_HANDLETYPE hComponent,
    OMX_BUFFERHEADERTYPE *pBufHdr )
{
    OMX_ERRORTYPE err = OMX_ErrorNone;

    if( compHandle != hComponent ) {
        LOG( LOG_ERROR, "OmxilDec=> FillBufferDone Unknown Component %p", hComponent );
        return OMX_ErrorNone;
    }

    if(pBufHdr->nFilledLen > 0) {
        if(log_fd != -1) {
            struct timespec ts;
            clock_gettime(CLOCK_MONOTONIC, &ts);
            uint64_t curr_time = (ts.tv_sec * 1000000) + (ts.tv_nsec / 1000);
            PERFORMANCE_LOG(log_fd, &ts, "Get frame %d out from codec\n", nOutFrameCount);
            uint64_t sending_time = qTimeStamp.front();
            int      delay = (curr_time - sending_time)/1000;
            PERFORMANCE_LOG(log_fd, &ts, "Decoding delay for frame %d: %dms\n", nOutFrameCount, delay);
            qTimeStamp.pop();
        }

        nOutFrameCount++;
        int dirty[4] = {0,0,src_width, src_height};
        OmxilDecOutputBuffer_t *pBuf = (OmxilDecOutputBuffer_t*)pBufHdr->pAppPrivate;
        if (screen_post_window(screen_win, pBuf->screen_buf, 1, dirty, 0) != 0) {
            LOG( LOG_ERROR, "OmxilDec=> FillBufferDone Failed to post to window.");
            err = OMX_ErrorUndefined;
        }
        if(out_fd != -1) {
            if(outputFormat == OMX_COLOR_FormatYUV420SemiPlanar)
                saveOutputNV12(pBuf);
            else if(outputFormat == (OMX_COLOR_FORMATTYPE)OMXQ_COLOR_Format1210)
                saveOutput1210(pBuf);
            else if(outputFormat == (OMX_COLOR_FORMATTYPE)OMXQ_COLOR_Format1610)
                saveOutput1610(pBuf);
            else if(outputFormat == (OMX_COLOR_FORMATTYPE)OMXQ_COLOR_FormatNV16)
                saveOutputNV16(pBuf);
            else
                LOG( LOG_ERROR, "OmxilDec=> FillBufferDone Failed to save output - unknown format.");
        }
    }
    else {
        LOG( LOG_DEBUG2, "OmxilDec=> FillBufferDone unprocessed data(nFilledLen=%d)", pBufHdr->nFilledLen);
    }

    //release the buffer
    pthread_mutex_lock( &mutex );
    pBufHdr->nFilledLen = 0;
    qOutputBufHdr.push(pBufHdr);

    pthread_cond_signal( &cond );
    pthread_mutex_unlock( &mutex );

    return err;

}

//------------------------------------------------------------------------------
OMX_ERRORTYPE OmxilVideoDec::AllocatePortBuffers()
{
    OMX_U32 i;
    OMX_ERRORTYPE omxErr = OMX_ErrorNone;
    OMX_U8 *pBuffer;

    //Allocate input port buffers
    LOG( LOG_INFO, "OmxilDec=> AllocatePortBuffers allocating %u input buffers of %u size",
              nInputBufs, inputPortBufSize);

    pthread_mutex_lock(&mutex);
    for( i = 0; i < nInputBufs; i++ ) {
        // Buffers are allocated by MMF and shared with component
        OMX_BUFFERHEADERTYPE *pBufHdr = NULL;
        omxErr = OMX_AllocateBuffer( compHandle,
                &pBufHdr,
                inPortIndex,
                NULL,
                inputPortBufSize);
        if( omxErr != OMX_ErrorNone ) {
            LOG( LOG_ERROR, "OmxilDec=> %s:%d Port OMX_AllocateBuffer() returned 0x%08x", __func__, __LINE__, omxErr );
            pthread_mutex_unlock(&mutex);
            return omxErr;
        } else {
            LOG( LOG_INFO, "OmxilDec=> %s:%d Port comp %p, port %u, bufHdr 0x%p, size %u", __func__, __LINE__,
                    compHandle, inPortIndex, pBufHdr, inputPortBufSize);
            qInputBufHdr.push(pBufHdr);
        }
    }

    //Allocate output port buffers
    LOG( LOG_INFO,
              "OmxilDec=> AllocatePortBuffers allocating %u output buffers of %u size",
              nOutputBufs, outputPortBufSize);

    for( i = 0; i < nOutputBufs; i++ ) {
        // Buffers are allocated by MMF and shared with component
        OmxilDecOutputBuffer_t *pBuf = &(output_bufs[i]);
        OMX_BUFFERHEADERTYPE *pBufHdr = NULL;
        pBuffer = (OMX_U8 *) (intptr_t) pBuf->addr;

        omxErr = OMX_UseBuffer( compHandle,
                &pBufHdr,
                outPortIndex,
                (OMX_PTR) pBuf->addr,
                outputPortBufSize,
                pBuffer);

        if( omxErr != OMX_ErrorNone ) {
            LOG( LOG_ERROR, "OmxilDec=> %s:%d OMX_UseBuffer() returned 0x%08x", __func__, __LINE__, omxErr );
            pthread_mutex_unlock(&mutex);
            return omxErr;
        } else {
            LOG( LOG_INFO, "OmxilDec=> %s:%d comp %p, port %u, bufHdr %p, bufPtr %p, size %u", __func__, __LINE__,
                    compHandle, outPortIndex, pBufHdr, pBufHdr->pBuffer, pBufHdr->nAllocLen);
            pBufHdr->pAppPrivate = (OMX_PTR)pBuf;
            qOutputBufHdr.push(pBufHdr);
        }
    }

    pthread_mutex_unlock(&mutex);
    return OMX_ErrorNone;
}

//------------------------------------------------------------------------------
OMX_ERRORTYPE OmxilVideoDec::FreeInPortBuffers()
{
    OMX_ERRORTYPE omxErr = OMX_ErrorNone;
    OMX_BUFFERHEADERTYPE *pBufHdr = NULL;
    OMX_U32 nBufFreed = 0;

    pthread_mutex_lock(&mutex);
    while(nBufFreed < nInputBufs) {
        pBufHdr = qInputBufHdr.front();
        if(pBufHdr == NULL) {
            LOG( LOG_DEBUG1, "OmxilDec=> FreeInPortBuffers waiting for EmptyBufferDone ... (%u, %u)", nBufFreed, nInputBufs);
            timedwait( __func__ );
            if(compError == OMX_ErrorTimeout)
                break;
            else
                continue;
        }

        omxErr = OMX_FreeBuffer( compHandle, inPortIndex, pBufHdr );
        if( omxErr != OMX_ErrorNone ) {
            LOG( LOG_ERROR, "OmxilDec=> %s:%d InPort OMX_FreeBuffer() returned 0x%08x", __func__, __LINE__, omxErr );
        }
        nBufFreed ++;
        qInputBufHdr.pop();
    }
    pthread_mutex_unlock(&mutex);
    return omxErr;
}

OMX_ERRORTYPE OmxilVideoDec::FreeOutPortBuffers()
{
    OMX_U32 nBufFreed = 0;

    OMX_ERRORTYPE omxErr = OMX_ErrorNone;
    OMX_BUFFERHEADERTYPE *pBufHdr = NULL;
    pthread_mutex_lock(&mutex);
    while( nBufFreed < nOutputBufs ) {
        pBufHdr = qOutputBufHdr.front();
        if(pBufHdr == NULL) {
            LOG( LOG_DEBUG1, "OmxilDec=> FreeOutPortBuffers waiting for FillBufferDone... (%u, %u)", nBufFreed, nOutputBufs );
            timedwait( __func__ );
            if(compError == OMX_ErrorTimeout)
                break;
            else
                continue;
        }

        omxErr = OMX_FreeBuffer( compHandle, outPortIndex, pBufHdr );
        if( omxErr != OMX_ErrorNone ) {
            LOG( LOG_ERROR, "OmxilDec=> %s:%d OutPort OMX_FreeBuffer() returned 0x%08x", __func__, __LINE__, omxErr );
            break;
        }
        nBufFreed ++;
        qOutputBufHdr.pop();
    }
    pthread_mutex_unlock(&mutex);

    return omxErr;
}

//------------------------------------------------------------------------------
OMX_ERRORTYPE OmxilVideoDec::MoveToState( OMX_STATETYPE newState )
{
    OMX_ERRORTYPE omxErr;
    OMX_STATETYPE currState;

    switch( newState ) {
        case OMX_StateLoaded:
        case OMX_StateIdle:
        case OMX_StatePause:
        case OMX_StateExecuting:
            break;
        default:
            return OMX_ErrorBadParameter;
    }

    // Make sure the next state is legitimate
    omxErr = OMX_GetState(compHandle, &currState);
    if (omxErr != OMX_ErrorNone)
    {
        LOG( LOG_ERROR, "OmxilDec=> Failed to get current state!!!" );
        return omxErr;
    }

    if( currState == OMX_StateInvalid ) {
        LOG( LOG_ERROR, "OmxilDec=> Transition from Invalid state is not allowed!!!" );
        return OMX_ErrorInvalidState;
    }

    if( currState == newState ) {
        // State for component(s) has already been set
        return OMX_ErrorNone;
    }

    LOG( LOG_INFO, "OmxilDec=> StateTransition target state %d", newState );
    cmdComplete = false;
    omxErr = OMX_SendCommand( compHandle, OMX_CommandStateSet, newState, NULL );
    if( omxErr != OMX_ErrorNone ) {
        LOG( LOG_ERROR, "OmxilDec=> StateTransition(IDLE) returned 0x%08x", omxErr );
        return omxErr;
    }

    if( currState == OMX_StateLoaded && newState == OMX_StateIdle ) {
        // Allocate buffers for active ports
        omxErr = AllocatePortBuffers();
        if( omxErr != OMX_ErrorNone ) {
            LOG( LOG_ERROR, "OmxilDec=> AllocatePortBuffers returned 0x%08x", omxErr );
            return omxErr;
        }
    }
    else if( currState == OMX_StateIdle && newState == OMX_StateLoaded ) {
        // Free buffers for active ports
        omxErr = FreeOutPortBuffers();
        if( omxErr != OMX_ErrorNone ) {
            LOG( LOG_ERROR, "OmxilDec=> FreeOutPortBuffers returned 0x%08x", omxErr );
            return omxErr;
        }
        omxErr = FreeInPortBuffers();
        if( omxErr != OMX_ErrorNone ) {
            LOG( LOG_ERROR, "OmxilDec=> FreeInPortBuffers returned 0x%08x", omxErr );
            return omxErr;
        }
    }

    if( (omxErr = waitForCommandComplete()) != OMX_ErrorNone ) {
            LOG( LOG_ERROR, "OmxilDec=> waitForCommandComplete returned 0x%08x", omxErr );
    }
    return omxErr;
}

//------------------------------------------------------------------------------
OmxilVideoDec::OmxilVideoDec(const char *inputpath, const char *outpath, int ibuf_num, int obuf_num)
               :in_path(inputpath)
                ,out_path(outpath)
                ,out_fd(-1)
                ,log_fd(-1)
                ,screen_ctx(NULL)
                ,screen_win(NULL)
                ,output_buf_num(obuf_num)
                ,input_buf_num(ibuf_num)
                ,frame_rate(30)
                ,src_width(0)
                ,src_height(0)
                ,stride(0)
                ,compHandle(nullptr)
                ,inPortIndex(0)
                ,outPortIndex(0)
                ,numOfPorts(0)
                ,cmdComplete(false)
                ,inPortFlushed(false)
                ,outPortFlushed(false)
                ,eos_received(false)
                ,eos_sent(false)
                ,compError(OMX_ErrorNone)
                ,outputPortBufSize(0)
                ,nOutputBufs(0)
                ,nOutFrameCount(0)
                ,nInputBufs(0)
                ,inputPortBufSize(0)
                ,nInFrameCount(0)
                ,frame_ts(0)
                ,exit_thread(false)
                ,thread_running(false)
                ,frame_duration(33333)
                ,last_frame_ts(0)
                ,frame_rate_control(false)
{
    init();
}

OmxilVideoDec::~OmxilVideoDec()
{
    /* Terminate our buffer push thread before continuing */
    if(thread_running) {
        exit_thread = true;
        decoder_push.join();
    }

    FlushVdec();
    CloseVdec();

    pthread_mutex_destroy( &mutex );
    pthread_cond_destroy( &cond );
    if(out_fd != -1) {
        close(out_fd);
    }

    if (screen_win) {
        screen_destroy_window(screen_win);
    }

    if (screen_ctx) {
        screen_destroy_context(screen_ctx);
    }
    free(screen_buf);

    if(log_fd != -1) {
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);
        uint64_t dec_time = (stopTime - startTime)/1000;
        float dec_frame_rate = nOutFrameCount * 1000.0 / (float)dec_time;
        PERFORMANCE_LOG(log_fd, &ts, "Total decoding time %lu ms.", dec_time);
        PERFORMANCE_LOG(log_fd, &ts, "Number of decoded frames %d ", nOutFrameCount);
        PERFORMANCE_LOG(log_fd, &ts, "Decoding frame rate is %.2f fps.", dec_frame_rate);
        close(log_fd);
    }
}

// Obtain an instance of video decoder component
OMX_CALLBACKTYPE OmxilVideoDec::callbacks = { &EventHandler,
                                          &EmptyBufferDone,
                                          &FillBufferDone };

//------------------------------------------------------------------------------
OMX_ERRORTYPE OmxilVideoDec::InitDecComp()
{
    OMX_ERRORTYPE omxErr;
    OMX_PORT_PARAM_TYPE portParam;
    OMX_PARAM_PORTDEFINITIONTYPE inPortParam;
    OMX_PARAM_PORTDEFINITIONTYPE outPortParam;

    // Initialize OpenMAX IL
    omxErr = OMX_Init();
    if( omxErr != OMX_ErrorNone ) {
        LOG( LOG_ERROR, "OmxilDec=> Component OMX_Init() returned 0x%08x", omxErr );
        return omxErr;
    }

    OMX_U32 num_comp = 1;
    OMX_U32 *pnum_comp = &num_comp;
    OMX_U8 comp_name[128];
    OMX_U8 *pcomp_name[1]={comp_name};
    omxErr = OMX_GetComponentsOfRole ((OMX_STRING)mInput->getRole(), pnum_comp, pcomp_name);
    if( omxErr != OMX_ErrorNone ) {
        LOG( LOG_ERROR, "OmxilDec=> OMX_GetComponentsOfRole() returned 0x%08x", omxErr );
        return omxErr;
    }
    // Create the OMX component
    omxErr = OMX_GetHandle( &compHandle,
                            (OMX_STRING)comp_name,
                            (OMX_PTR) this,
                            &callbacks );
    if( !compHandle || (omxErr != OMX_ErrorNone) ) {
        LOG( LOG_ERROR, "OmxilDec=> Component(%s) OMX_GetHandle() returned 0x%08x", comp_name, omxErr );
        goto error_exit;
    }

    // Get component ports info and prepare internal port contexts.
    SET_OMX_VERSION_SIZE( portParam, sizeof(OMX_PORT_PARAM_TYPE) );
    portParam.nPorts = 0;
    omxErr = OMX_GetParameter( compHandle,
                OMX_IndexParamVideoInit,
                &portParam );
    if( omxErr != OMX_ErrorNone ) {
        LOG( LOG_ERROR, "OmxilDec=> Component OMX_GetParameter() returned 0x%08x version %u",
                  omxErr, portParam.nVersion.nVersion );
        goto error_exit;
    }

    numOfPorts = portParam.nPorts;
    if(numOfPorts < 2) {
        LOG( LOG_ERROR, "OmxilDec=>  Invalid number of ports %d", numOfPorts );
        goto error_exit;
    }
    inPortIndex = portParam.nStartPortNumber;
    outPortIndex = portParam.nStartPortNumber + 1;

    //Configure input port
    pthread_mutex_lock(&mutex);
    SET_OMX_VERSION_SIZE( inPortParam, sizeof(OMX_PARAM_PORTDEFINITIONTYPE) );
    inPortParam.nPortIndex = inPortIndex;
    omxErr = OMX_GetParameter( compHandle,
                               OMX_IndexParamPortDefinition,
                               &inPortParam );
    if( omxErr != OMX_ErrorNone ) {
        LOG( LOG_ERROR, "OmxilDec=> %s:%d Port OMX_GetParameter() returned 0x%08x", __func__, __LINE__, omxErr );
        goto error_unlock_mutex_and_exit;
    }

    // Allocate input buffer for the worst case to avoid input buffer reconfiguration
    inPortParam.format.video.nFrameWidth   = aligned_width;
    inPortParam.format.video.nFrameHeight  = aligned_height;
    inPortParam.format.video.xFramerate    = (OMX_U32)(frame_rate << 16); // FrameRate in Q16 format
    inPortParam.format.video.eCompressionFormat = mInput->getFormat();
    inPortParam.nBufferCountActual = input_buf_num;

    LOG( LOG_INFO, "OmxilDec=> Port comp %p, port %u", compHandle, inPortParam.nPortIndex );
    omxErr = OMX_SetParameter( compHandle,
                               OMX_IndexParamPortDefinition,
                               &inPortParam );
    if( omxErr != OMX_ErrorNone ) {
        LOG( LOG_ERROR, "OmxilDec=> %s:%d Port OMX_SetParameter() returned 0x%08x", __func__, __LINE__, omxErr );
        goto error_unlock_mutex_and_exit;
    }

    omxErr = OMX_GetParameter( compHandle,
                               OMX_IndexParamPortDefinition,
                               &inPortParam );
    if( omxErr != OMX_ErrorNone ) {
        LOG( LOG_ERROR, "OmxilDec=> %s:%d Port OMX_GetParameter() returned 0x%08x", __func__, __LINE__, omxErr );
        goto error_unlock_mutex_and_exit;
    }
    nInputBufs = inPortParam.nBufferCountActual;
    inputPortBufSize = inPortParam.nBufferSize;

    //Configure output port
    SET_OMX_VERSION_SIZE( outPortParam, sizeof(OMX_PARAM_PORTDEFINITIONTYPE) );
    outPortParam.nPortIndex = outPortIndex;
    omxErr = OMX_GetParameter( compHandle,
                               OMX_IndexParamPortDefinition,
                               &outPortParam );
    if( omxErr != OMX_ErrorNone ) {
        LOG( LOG_ERROR, "OmxilDec=> %s:%d Port OMX_GetParameter() returned 0x%08x", __func__, __LINE__, omxErr );
        goto error_unlock_mutex_and_exit;
    }

    outPortParam.format.video.nFrameWidth   = aligned_width;
    outPortParam.format.video.nFrameHeight  = aligned_height;
    outPortParam.format.video.nStride = stride;
    outPortParam.format.video.nSliceHeight = src_height;
    outPortParam.format.video.eColorFormat = outputFormat;
    outPortParam.nBufferCountActual = output_buf_num;

    LOG( LOG_INFO, "OmxilDec=> Port comp %p, port %u", compHandle, outPortParam.nPortIndex );
    omxErr = OMX_SetParameter( compHandle,
                               OMX_IndexParamPortDefinition,
                               &outPortParam );
    if( omxErr != OMX_ErrorNone ) {
        LOG( LOG_ERROR, "OmxilDec=> %s:%d Port OMX_SetParameter() returned 0x%08x", __func__, __LINE__, omxErr );
        goto error_unlock_mutex_and_exit;
    }

    omxErr = OMX_GetParameter( compHandle,
                               OMX_IndexParamPortDefinition,
                               &outPortParam );
    if( omxErr != OMX_ErrorNone ) {
        LOG( LOG_ERROR, "OmxilDec=> %s:%d Port OMX_SetParameter() returned 0x%08x", __func__, __LINE__, omxErr );
        goto error_unlock_mutex_and_exit;
    }
    outputPortBufSize = (OMX_U32)output_bufs[0].size;
    nOutputBufs = outPortParam.nBufferCountActual;

    pthread_mutex_unlock(&mutex);

    compError = OMX_ErrorNone;

    LOG( LOG_DEBUG2, "OmxilDec=>%s video  created successfully", __func__ );
    return OMX_ErrorNone;

error_unlock_mutex_and_exit:
    pthread_mutex_unlock(&mutex);
error_exit:
    OMX_Deinit();
    return omxErr;
}

//------------------------------------------------------------------------------
void OmxilVideoDec::CloseVdec()
{
    OMX_ERRORTYPE omxErr;
    OMX_STATETYPE currState;
    LOG( LOG_DEBUG1, "OmxilDec=> CloseVdec called ");

    if( compHandle ) {
        //wait util state change completed
        omxErr = OMX_GetState(compHandle, &currState);
        if (omxErr == OMX_ErrorNone)
        {
            if( currState != OMX_StateInvalid &&
                    currState != OMX_StateLoaded ) {
                StopVdec();
            }
        }

        // Freeing component
        LOG( LOG_DEBUG1, "OmxilDec=> Freeing component %p", compHandle );
        omxErr = OMX_FreeHandle( compHandle );
        if( omxErr != OMX_ErrorNone ) {
            LOG( LOG_ERROR, "OmxilDec=> Component OMX_FreeHandle() returned 0x%08x", omxErr );
        }
    }

    OMX_Deinit();

    LOG( LOG_INFO, "OmxilDec=> CloseVdec Done" );

    return;
}


//------------------------------------------------------------------------------
OMX_ERRORTYPE OmxilVideoDec::StartVdec()
{
    OMX_ERRORTYPE omxErr;

    omxErr = MoveToState( OMX_StateIdle );
    if( omxErr != OMX_ErrorNone ) {
        LOG( LOG_ERROR, "OmxilDec=> Transition LOADED->IDLE failed 0x%x", omxErr );
        return omxErr;
    }

    omxErr = MoveToState( OMX_StateExecuting );
    if( omxErr != OMX_ErrorNone ) {
        LOG( LOG_ERROR, "OmxilDec=> Transition IDLE->EXECUTING failed 0x%x", omxErr );
        return omxErr;
    }

    //send decoder config data
    omxErr = send_config_data();
    if(omxErr != OMX_ErrorNone) {
        LOG( LOG_ERROR, "OmxilDec=> Failed to send_config_data");
        return omxErr;
    }

    thread_running = true;
    decoder_push = std::thread(&OmxilVideoDec::decoder_file_push_thread, this);

    LOG( LOG_DEBUG1, "OmxilDec=> Started" );
    return OMX_ErrorNone;

}

//------------------------------------------------------------------------------
OMX_ERRORTYPE OmxilVideoDec::StopVdec()
{
    OMX_ERRORTYPE omxErr = OMX_ErrorNone;

    omxErr = MoveToState( OMX_StateIdle );
    if( omxErr != OMX_ErrorNone ) {
        LOG( LOG_ERROR, "OmxilDec=> StopVdec Transition EXECUTING->IDLE failed 0x%x", omxErr );
        return omxErr;
    }

    omxErr = MoveToState( OMX_StateLoaded );
    if( omxErr != OMX_ErrorNone ) {
        LOG( LOG_ERROR, "OmxilDec=> StopVdec Transition IDLE->LOADED failed 0x%x", omxErr );
        return omxErr;
    }

    return omxErr;
}

//------------------------------------------------------------------------------
OMX_ERRORTYPE OmxilVideoDec::PauseVdec()
{
    OMX_ERRORTYPE omxErr = OMX_ErrorNone;

    omxErr = MoveToState( OMX_StatePause );
    if( omxErr != OMX_ErrorNone ) {
        LOG( LOG_ERROR, "OmxilDec=> PauseVdec Transition To Pause failed 0x%x", omxErr );
        return omxErr;
    }

    return omxErr;
}

//------------------------------------------------------------------------------
OMX_ERRORTYPE OmxilVideoDec::ResumeVdec()
{
    OMX_ERRORTYPE omxErr = OMX_ErrorNone;

    omxErr = MoveToState( OMX_StateExecuting );
    if( omxErr != OMX_ErrorNone ) {
        LOG( LOG_ERROR, "OmxilDec=> ResumeVdec Transition To Executing failed 0x%x", omxErr );
        return omxErr;
    }

    return omxErr;

}

//------------------------------------------------------------------------------
OMX_ERRORTYPE OmxilVideoDec::FlushVdec()
{
    OMX_ERRORTYPE omxErr;
    OMX_STATETYPE currState;
    OMX_ERRORTYPE err = OMX_ErrorNone;

    LOG( LOG_DEBUG2, "OmxilDec=> FlushVdec In");
    if( !compHandle ) {
        LOG( LOG_ERROR, "OmxilDec=> FlushVdec  returned");
        return err;
    }

    omxErr = OMX_GetState(compHandle, &currState);
    if (omxErr != OMX_ErrorNone)
    {
        LOG( LOG_ERROR, "OmxilDec=> FlushVdec Failed to get current state!!!" );
        return omxErr;
    }

    if( currState == OMX_StateInvalid ) {
        LOG( LOG_ERROR, "OmxilDec=> flushing from INVALID state is not allowed!" );
        return omxErr;
    }

    if( currState == OMX_StateLoaded || currState == OMX_StateIdle) {
        LOG( LOG_DEBUG1, "OmxilDec=> skip flushing due to compState=%d", currState );
        return OMX_ErrorNone;
    }

    cmdComplete = false;
    inPortFlushed = false;
    outPortFlushed = false;
    omxErr = OMX_SendCommand( compHandle, OMX_CommandFlush, OMX_ALL, NULL );
    if( omxErr != OMX_ErrorNone ) {
        LOG( LOG_ERROR, "OmxilDec=> Send OMX_CommandFlush returned 0x%08x", omxErr );
        return omxErr;
    }
    if( (omxErr = waitForCommandComplete()) != OMX_ErrorNone ) {
        LOG( LOG_ERROR, "OmxilDec=> waitForCommandComplete returned 0x%08x", omxErr );
        return omxErr;
    }
    LOG( LOG_DEBUG2, "OmxilDec=> FlushVdec complete");

    return err;
}

OmxilBailReason OmxilVideoDec::GetBailReason()
{
    if (compError != OMX_ErrorNone)
        return BAIL_ERROR;
    else if (eos_received)
        return BAIL_EOS;
    else
        return BAIL_NOT_BAILED;
}

OMX_BUFFERHEADERTYPE* OmxilVideoDec::GetInputFrame()
{
    OMX_BUFFERHEADERTYPE *rbuf = NULL;

    if(qInputBufHdr.empty()) {
        return NULL;
    }
    rbuf = qInputBufHdr.front();
    qInputBufHdr.pop();

    mInput->readFrame(rbuf->pBuffer, &(rbuf->nFilledLen));
    if(rbuf->nFilledLen == 0) {
        LOG(LOG_INFO,"%s:%d reach the end of input file", __func__, __LINE__);
        rbuf->nFlags |= OMX_BUFFERFLAG_EOS;
        eos_sent = true;
    }
    else {
        if(rbuf->nFilledLen < rbuf->nAllocLen) {
            rbuf->nFlags |= OMX_BUFFERFLAG_ENDOFFRAME;
            rbuf->nTimeStamp = frame_ts;
            frame_ts += 1000 / frame_rate;
        }
        else {
            LOG(LOG_INFO,"GetInputFrame get partial frame: %d", rbuf->nFilledLen);
        }
    }

    return rbuf;
}


OMX_ERRORTYPE OmxilVideoDec::send_config_data()
{
    OMX_ERRORTYPE omxErr = OMX_ErrorNone;
    OMX_BUFFERHEADERTYPE *buffer = qInputBufHdr.front();
    uint32_t configSize = mInput->getConfigSize();

    if(configSize < buffer->nAllocLen) {
        buffer->nFilledLen = configSize;
        memcpy(buffer->pBuffer, mInput->getConfigPtr(), configSize);
        buffer->nFlags = OMX_BUFFERFLAG_CODECCONFIG;
        omxErr = OMX_EmptyThisBuffer( compHandle, buffer);
        if( omxErr != OMX_ErrorNone ) {
            LOG( LOG_ERROR, "OmxilDec=> send_config_data OMX_EmptyThisBuffer: return omxErr=%08x", omxErr );
        }
        else {
            qInputBufHdr.pop();
        }
    }
    else {
        LOG( LOG_ERROR, "OmxilDec=> send_config_data invalid config size(%d)", configSize);
        omxErr = OMX_ErrorInsufficientResources;
    }

    return omxErr;
}

void OmxilVideoDec::init()
{
    int v;

    screen_buf = (screen_buffer_t *)malloc(output_buf_num * sizeof(screen_buffer_t));
    if(screen_buf == NULL) {
        throw Error("Error: unable to allocate memory for screen_buf(%lu)", output_buf_num * sizeof(screen_buffer_t));
    }

    output_bufs = (OmxilDecOutputBuffer_t *)malloc(output_buf_num * sizeof(OmxilDecOutputBuffer_t));
    if(output_bufs == NULL) {
        throw Error("Error: unable to allocate memory for screen_buf(%lu)", output_buf_num * sizeof(OmxilDecOutputBuffer_t));
    }


    if(out_path != NULL) {
        out_fd = open(out_path, O_WRONLY | O_CREAT, 0644);
        if(out_fd == -1) {
            LOG( LOG_ERROR, "OmxilDec=> Failed to open output(%s)", out_path);
        }
    }

    try {
        mInput = createInput(in_path);
    }
    catch (const std::exception &e) {
        throw Error("Error: unable create input (%s)\n", in_path);
    }

    LOG(LOG_DEBUG2,"Creating screen context");
    if (screen_create_context(&(screen_ctx), SCREEN_DISPLAY_MANAGER_CONTEXT) != 0) {
        throw Error("Failed to create screen context! Error: %s\n", strerror(errno));
    }

    LOG(LOG_DEBUG2,"Creating screen window");
    if (screen_create_window(&(screen_win), screen_ctx) != 0) {
        throw Error("Failed to create screen window! Error: %s\n", strerror(errno));
    }

    int32_t chroma_format = mInput->getChromaFormat();
    LOG(LOG_INFO,"%s chroma_format=%d, LumaDepth=%d, ChromaDepth=%d", __func__, chroma_format, mInput->getLumaDepth(), mInput->getChromaDepth());
    if(chroma_format == 1) {
        if(mInput->getLumaDepth() == 8)
            outputFormat = OMX_COLOR_FormatYUV420SemiPlanar;
        else if(mInput->getLumaDepth() == 10)
            outputFormat = (OMX_COLOR_FORMATTYPE)OMXQ_COLOR_Format1210;
        else
            throw Error("Unsupported depth %d\n", mInput->getLumaDepth());
    }
    else if(chroma_format == 2) {
        if(mInput->getLumaDepth() == 8)
            outputFormat = (OMX_COLOR_FORMATTYPE)OMXQ_COLOR_FormatNV16;
        else if(mInput->getLumaDepth() == 10)
            outputFormat = (OMX_COLOR_FORMATTYPE)OMXQ_COLOR_Format1610;
        else
            throw Error("Unsupported depth %d\n", mInput->getLumaDepth());
    }
    else {
        throw Error("Unsupported chrome format: %d\n", chroma_format);
    }

    src_width = mInput->getWidth();
    src_height = mInput->getHeight();
    aligned_width = mInput->getAlignedWidth();
    aligned_height = mInput->getAlignedHeight();
    int size[2];
    size[0] = src_width;
    size[1] = src_height;
    if (screen_set_window_property_iv(screen_win, SCREEN_PROPERTY_SOURCE_SIZE, size) != 0) {
        throw Error("Failed to set source dimensions for window! Error: %s\n", strerror(errno));
    }

    size[0] = aligned_width;
    size[1] = aligned_height;
    if (screen_set_window_property_iv(screen_win, SCREEN_PROPERTY_BUFFER_SIZE, size) < 0) {
        throw Error("Failed to set SCREEN_PROPERTY_BUFFER_SIZE for window! Error: %s\n", strerror(errno));
    }

    v = SCREEN_USAGE_READ | SCREEN_USAGE_WRITE | SCREEN_USAGE_NATIVE | SCREEN_USAGE_VIDEO;
    if (screen_set_window_property_iv(screen_win, SCREEN_PROPERTY_USAGE, &v) < 0) {
        throw Error("Failed to set SCREEN_PROPERTY_USAGE for window! Error: %s\n", strerror(errno));
    }

    if(outputFormat == OMX_COLOR_FormatYUV420SemiPlanar)
        v = SCREEN_FORMAT_NV12;
    else {
        //TODO This is a workaround because graphic doesn't support other format, set GRBA8888 to get a big enought buffer.
        //should be reverted after NV16 is supported in J7 graphics.
        v = SCREEN_FORMAT_RGBA8888;
    }
    if (screen_set_window_property_iv(screen_win, SCREEN_PROPERTY_FORMAT, &v) < 0) {
        throw Error("Failed to set SCREEN_PROPERTY_FORMAT for window! Error: %s\n", strerror(errno));
    }

    v = SCREEN_TRANSPARENCY_SOURCE_OVER;
    if (screen_set_window_property_iv(screen_win, SCREEN_PROPERTY_TRANSPARENCY, &v) < 0) {
        throw Error("Failed to set SCREEN_PROPERTY_TRANSPARENCY for window! Error: %s\n", strerror(errno));
    }

    if (screen_create_window_buffers(screen_win, output_buf_num) < 0) {
        throw Error("Failed to create window buffers for window! Error: %s\n", strerror(errno));
    }

    if (screen_get_window_property_pv(screen_win, SCREEN_PROPERTY_RENDER_BUFFERS, (void **)screen_buf) < 0) {
        throw Error("Failed to get SCREEN_PROPERTY_RENDER_BUFFERS for window! Error: %s\n", strerror(errno));
    }

    if(outputFormat == OMX_COLOR_FormatYUV420SemiPlanar) {
        if (screen_get_buffer_property_iv(screen_buf[0], SCREEN_PROPERTY_STRIDE, &stride)) {
            throw Error("Failed to get SCREEN_PROPERTY_STRIDE Error: %s\n",strerror(errno));
        }
    }
    else
        stride = aligned_width;
    LOG(LOG_INFO,"Stride of the output buffer is[%d]", stride);

    for (OMX_U32 i = 0; i < output_buf_num; i++) {
        void *pointer;
        int frame_size;
        long long offset;
        if (screen_get_buffer_property_pv(screen_buf[i], SCREEN_PROPERTY_POINTER, &pointer) != EOK) {
            throw Error("Failed to get SCREEN_PROPERTY_POINTER for buf[%d]! Error: %s\n",i, strerror(errno));
        }

        if (screen_get_buffer_property_llv(screen_buf[i], SCREEN_PROPERTY_PHYSICAL_ADDRESS,
                                           &offset) < 0) {
            throw Error("Failed to get SCREEN_PROPERTY_POINTER for buf[%d]! Error: %s\n",i, strerror(errno));
        }

        if (screen_get_buffer_property_iv(screen_buf[i], SCREEN_PROPERTY_SIZE, &frame_size)) {
            throw Error("Failed to get SCREEN_PROPERTY_POINTER for buf[%d]! Error: %s\n",i, strerror(errno));
        }
        output_bufs[i].addr = pointer;
        output_bufs[i].size = frame_size;
        output_bufs[i].offset = offset;
        output_bufs[i].screen_buf = screen_buf[i];
        LOG(LOG_DEBUG2,"Get frame size for buf[%d]: %d, %p, %llx",i, frame_size, pointer, offset);
    }

    v = 1;
    if (screen_set_window_property_iv(screen_win, SCREEN_PROPERTY_VISIBLE, &v) < 0) {
        throw Error("Failed to set SCREEN_PROPERTY_VISIBLE for window! Error: %s\n", strerror(errno));
    }


    //thread lock for input/output port
    if(pthread_mutex_init( &mutex, NULL) != EOK) {
        throw Error( "OmxilDec=>%s failure, mutex init err \n", __func__ );
    }

    pthread_condattr_t attr;
    if (pthread_condattr_init(&attr) != EOK) {
        throw Error("OmxilDec=>%s failure, condattr init err\n", __func__);
    }
    if (pthread_condattr_setclock(&attr, CLOCK_MONOTONIC) != EOK) {
        pthread_condattr_destroy(&attr);
        throw Error("OmxilDec=>%s failure, condattr_setclock err \n", __func__ );
    }

    if(pthread_cond_init( &cond, &attr ) != EOK) {
        pthread_condattr_destroy(&attr);
        throw Error("OmxilDec=>%s failure, cond init err \n", __func__ );
    }
    pthread_condattr_destroy(&attr);


    if((InitDecComp()) != OMX_ErrorNone) {
        throw Error("Failed to create decoder:\n");
    }

}

OMX_ERRORTYPE OmxilVideoDec::SetDisplayArea(int x, int y, int width, int height)
{
    int v[2];
    v[0] = x;
    v[1] = y;
    if (screen_set_window_property_iv(screen_win, SCREEN_PROPERTY_POSITION, v) != 0) {
        LOG(LOG_ERROR, "Failed to set source dimensions for window! Error: %s\n", strerror(errno));
        return OMX_ErrorUnsupportedSetting;
    }

    v[0] = width;
    v[1] = height;
    if (screen_set_window_property_iv(screen_win, SCREEN_PROPERTY_SIZE, v) != 0) {
        LOG(LOG_ERROR, "Failed to set SCREEN_PROPERTY_BUFFER_SIZE for window! Error: %s\n", strerror(errno));
        return OMX_ErrorUnsupportedSetting;
    }

    return OMX_ErrorNone;
}

OMX_ERRORTYPE OmxilVideoDec::ReconfigVdecSession()
{
    int i;
    OMX_ERRORTYPE omxErr;
    OMX_PARAM_PORTDEFINITIONTYPE param;
    OMX_U8 *pBuffer;
    OMX_STATETYPE currState;

    LOG( LOG_DEBUG2, "=> ReconfigVdecSession In");
    omxErr = OMX_GetState(compHandle, &currState);
    if (omxErr != OMX_ErrorNone)
    {
        LOG( LOG_ERROR, "=> ReconfigVdecSession Failed to get current state!!!");
        return omxErr;
    }

    if( currState == OMX_StateInvalid ) {
        LOG( LOG_ERROR, "=> reconfig in INVALID state is not allowed!" );
        return OMX_ErrorInvalidState;
    }

    if( currState == OMX_StateLoaded ) {
        //In LOADED state, resource is not allocated, there is no need to do reconfigure.
        LOG( LOG_INFO, "=> skip reconfigure due to OMX_StateLoaded");
        return OMX_ErrorNone;
    }

    //step 1: disable output port
    cmdComplete = false;
    omxErr = OMX_SendCommand( compHandle, OMX_CommandPortDisable, outPortIndex, NULL );
    if( omxErr != OMX_ErrorNone ) {
        LOG( LOG_ERROR, "=> %s:%d Port OMX_SendCommand(OMX_CommandPortDisable) returned 0x%08x for index %u",  __func__, __LINE__,omxErr, outPortIndex );
        return omxErr;
    }

    //step 2: free output port buffers
    omxErr = FreeOutPortBuffers();
    if( omxErr != OMX_ErrorNone ) {
        LOG( LOG_ERROR, "=> FreeOutPortBuffers returned 0x%08x", omxErr );
        return omxErr;
    }
    //step 3: output port disable complete
    if( (omxErr = waitForCommandComplete()) != OMX_ErrorNone ) {
        LOG( LOG_ERROR, "=> waitForCommandComplete returned 0x%08x", omxErr );
        return omxErr;
    }

    //step 6: update output buffers
    SET_OMX_VERSION_SIZE( param, sizeof(param) );
    param.nPortIndex = outPortIndex;  //update output buffer

    omxErr = OMX_GetParameter( compHandle,
                               OMX_IndexParamPortDefinition,
                               &param );
    if( omxErr != OMX_ErrorNone ) {
        LOG( LOG_ERROR, "=> %s:%d Port OMX_GetParameter() returned 0x%08x", __func__, __LINE__, omxErr );
        return omxErr;
    }

    param.nBufferCountActual = output_buf_num;
    param.format.video.nStride = (OMX_U32)stride;
    param.format.video.nSliceHeight = (OMX_U32)src_height;
    omxErr = OMX_SetParameter( compHandle,
                               OMX_IndexParamPortDefinition,
                               &param );
    if( omxErr != OMX_ErrorNone ) {
        LOG( LOG_ERROR, "=> %s:%d Port OMX_SetParameter() returned 0x%08x", __func__, __LINE__, omxErr );
        return omxErr;
    }
    omxErr = OMX_GetParameter( compHandle,
                               OMX_IndexParamPortDefinition,
                               &param );
    if( omxErr != OMX_ErrorNone ) {
        LOG( LOG_ERROR, "=> %s:%d Port OMX_GetParameter() returned 0x%08x", __func__, __LINE__, omxErr );
        return omxErr;
    }
    nOutputBufs = param.nBufferCountActual > output_buf_num ? output_buf_num : param.nBufferCountActual;


    //step 5: enable output port
    cmdComplete = false;
    omxErr = OMX_SendCommand( compHandle, OMX_CommandPortEnable, outPortIndex, NULL );
    if( omxErr != OMX_ErrorNone ) {
        LOG( LOG_ERROR, "=> %s:%d Port OMX_SendCommand(OMX_CommandPortEnable) returned 0x%08x for index %u", __func__, __LINE__, omxErr, outPortIndex);
        return omxErr;
    }

    for( i = 0; i < (int)nOutputBufs; i++ ) {
        // Buffers are allocated by MMF and shared with component
        OmxilDecOutputBuffer_t *pBuf = &(output_bufs[i]);
        OMX_BUFFERHEADERTYPE *pBufHdr = NULL;
        //pBuffer = (OMX_U8 *) (intptr_t) pBuf->offset;
        pBuffer = (OMX_U8 *) pBuf->addr;

        omxErr = OMX_UseBuffer( compHandle,
                &pBufHdr,
                outPortIndex,
                (OMX_PTR) pBuf->addr,
                outputPortBufSize,
                pBuffer);

        if( omxErr != OMX_ErrorNone ) {
            LOG( LOG_ERROR, "OmxilDec=> %s:%d OMX_UseBuffer() returned 0x%08x", __func__, __LINE__, omxErr );
            pthread_mutex_unlock(&mutex);
            return omxErr;
        } else {
            LOG( LOG_INFO, "OmxilDec=> %s:%d comp %p, port %u, bufHdr 0x%p, bufPtr 0x%p, size %u", __func__, __LINE__,
                    compHandle, outPortIndex, pBufHdr, pBufHdr->pBuffer, pBufHdr->nAllocLen);
            pBufHdr->pAppPrivate = (OMX_PTR)pBuf;
            qOutputBufHdr.push(pBufHdr);
        }
    }

    portSettingChanged = false;

    //step 7: output port enable complete
    if( (omxErr = waitForCommandComplete()) != OMX_ErrorNone ) {
        LOG( LOG_ERROR, "=> waitForCommandComplete returned 0x%08x", omxErr );
        return omxErr;
    }

    return OMX_ErrorNone;
}


