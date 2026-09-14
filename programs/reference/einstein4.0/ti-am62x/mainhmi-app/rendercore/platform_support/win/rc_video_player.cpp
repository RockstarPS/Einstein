///////////////////////////////////////////////////////////////////////////////
//
//                     CONFIDENTIAL VISTEON CORPORATION
//
// This is an unpublished work of authorship, which contains trade secrets,
// created in 2018. Visteon Corporation owns all rights to this work and
// intends to maintain it in confidence to preserve its trade secret status.
// Visteon Corporation reserves the right, under the copyright laws of the
// United States or those of any other country that may have jurisdiction,
// to protect this work as an unpublished work, in the event of an
// inadvertent or deliberate unauthorized publication. Visteon Corporation
// also reserves its rights under all copyright laws to protect this work as
// a published work, when appropriate. Those having access to this work may
// not copy it, use it, modify it or disclose the information contained in
// it without the written authorization of Visteon Corporation.
//
//  Filename    : rc_video_player.cpp
//  Description : Template impelementation of the videoplayer support
//                Its expected that the application creates a player for their platform
//                by leveraging from this. An example player is provided in 
//                platform_support\win\rc_video_player.cpp which realizes
//                playback using ffmpeg library
//  Created on  : 20-Feb-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#include "gfx3d_scg.h"
#include "rc_video_player.h"

extern "C"
{
#include <libavutil/opt.h>
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libavutil/channel_layout.h>
#include <libavutil/common.h>
#include <libavutil/imgutils.h>
#include <libavformat/avformat.h>
#include <libavutil/mathematics.h>
#include <libavutil/samplefmt.h>
#include <libswscale/swscale.h>
#include <libavdevice/avdevice.h>
#include <libavfilter/avfilter.h>
#include <libswresample/swresample.h>
}

namespace rendercore_engine
{
    class buffer_data
    {
    private:
        gfx3d_scg_display* display = nullptr;
        uint8_t* buff = nullptr;      // buffer start
        uint8_t* ptr = nullptr;       // current read position
        int64_t buffsize = 0;          // size of buffer
        int64_t size = 0;              // size left to read
    public:
        void Init(gfx3d_scg_display* const p_parent, uint8_t* p_buff, int64_t p_buffsize)
        {
            buff = p_buff;
            ptr = p_buff;
            buffsize = p_buffsize;
            size = p_buffsize;
            display = p_parent;
        }
        // seek to requested position 
        int64_t seek(int64_t p_offset, int32_t p_whence)
        {
            int64_t ret = 0;
            if ((p_whence & AVSEEK_SIZE) != 0)
            {
                // requesting size of file, no seek to be performed..
                ret = buffsize;
            }
            else
            {
                // requesting seek (same as fseek)
                if ((p_whence & SEEK_CUR) != 0)
                {
                    ret = (ptr - buff);
                }
                else if ((p_whence & SEEK_END) != 0)
                {
                    ret = (buffsize - 1);
                }
                else
                {
                }
                ret += p_offset;

                if ((ret >= 0) && (ret < buffsize))
                {
                    ptr = &buff[ret];
                    size = (buffsize - ret);
                    ret = 0;
                }
                else
                {
                    ret = AVERROR_EOF;
                }
            }
            return(ret);
        }
        // read from current position
        int32_t read(uint8_t* p_buf, int32_t p_buf_size)
        {
            p_buf_size = FFMIN(p_buf_size, static_cast<int32_t>(size));
            if (p_buf_size <= 0)
            {
                p_buf_size = AVERROR_EOF;
            }
            else
            {
                memcpy(p_buf, ptr, p_buf_size);
                ptr += p_buf_size;
                size -= p_buf_size;
            }
            return p_buf_size;
        }
        ~buffer_data()
        {
            if (buff != nullptr)
            {
                (void)display->ResourceFileFree((const CHAR8*)buff);
            }
        }
    };

    class rc_player_context
    {
    private:
        gfx3d_scg_display* display = nullptr;
        AVCodecContext* pCodecCtx = nullptr;
        AVFormatContext* pFormatCtx = nullptr;
        AVCodec* pCodec = nullptr;
        AVFrame* pFrame = nullptr;
        struct SwsContext* sws_ctx = nullptr;
        uint8_t* buffer = nullptr;
        AVFrame* pict = nullptr;
        AVPacket* pPacket = nullptr;
        AVIOContext* avio_ctx = nullptr;
        uint8_t* avio_ctx_buffer = nullptr;
        buffer_data bd;
        uint32_t videoStream = UINT_MAX;
        uint32_t bufferSize = 0U;
        int32_t pError = 0;
        uint32_t tWidth = 0U;
        uint32_t tHeight = 0U;
        AVPixelFormat tFormat = AVPixelFormat::AV_PIX_FMT_RGBA;
        HWND     ghWnd = nullptr;
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
        WTAsyncTask pTaskStatus;
#endif

        static int32_t read_packet(void* opaque, uint8_t* buf, int32_t buf_size)
        {
            buffer_data* bd = static_cast<buffer_data*>(opaque);
            int32_t ret;
            if (bd != nullptr)
            {
                ret = bd->read(buf, buf_size);
            }
            else
            {
                ret = AVERROR_EOF;
            }
            return(ret);
        }
        static int64_t seek(void* opaque, int64_t offset, int32_t whence)
        {
            buffer_data* bd = static_cast<buffer_data*>(opaque);
            int64_t ret;
            if (bd != nullptr)
            {
                ret = bd->seek(offset, whence);
            }
            else
            {
                ret = AVERROR_EOF;
            }
            return(ret);
        }
        int32_t open_input_from_memory(const std::string p_url)
        {
            int32_t ret = -1;
            if (display != nullptr)
            {
                size_t fl_readsize = 0U;
                int32_t avio_ctx_buffer_size = 4096;
                uint8_t* buff = reinterpret_cast<uint8_t*>(const_cast<CHAR8*>(display->ResourceFileRead(p_url, fl_readsize)));
                bd.Init(display, buff, (int64_t)fl_readsize);
                pFormatCtx = avformat_alloc_context();
                avio_ctx_buffer = static_cast<uint8_t*>(av_malloc(avio_ctx_buffer_size));
                avio_ctx = avio_alloc_context(avio_ctx_buffer, avio_ctx_buffer_size, 0, &bd, &read_packet, nullptr, &seek);
                pFormatCtx->pb = avio_ctx;
                pFormatCtx->flags |= AVFMT_FLAG_CUSTOM_IO;
                // we set up our own IOint
                ret = avformat_open_input(&pFormatCtx, nullptr, nullptr, nullptr);
            }
            return(ret);
        }

        int32_t openFilenFindStreamInfo(std::string p_url)
        {
#if 1
            int32_t ret = open_input_from_memory(p_url);
#else
            int32_t ret = avformat_open_input(&pFormatCtx, p_url.c_str(), nullptr, nullptr);
#endif
            videoStream = -1;
            if (ret < 0)
            {
                RcDebugErrorLogId(rc_error_logId::elVideoPlayerCanNotOpenFile);
                WLOG("Uri %s\n", p_url.c_str());
            }
            else
            {
                ret = avformat_find_stream_info(pFormatCtx, nullptr);
                if (ret < 0)
                {
                    RcDebugErrorLogId(rc_error_logId::elVideoPlayerCanNotFindStreamInfo);
                    WLOG("Uri %s\n", p_url.c_str());
                }
                else
                {
                    for (uint32_t i = 0U; i < pFormatCtx->nb_streams; i++)
                    {
                        if (pFormatCtx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO)
                        {
                            videoStream = i;
                            break;
                        }
                    }
                    if (videoStream == -1)
                    {
                        RcDebugErrorLogId(rc_error_logId::elVideoPlayerCanNotFindVideoStream);
                        WLOG("Uri %s\n", p_url.c_str());
                        ret = -1;
                    }
                }
            }
            return(ret);
        }

        int32_t findnOpenCodec()
        {
            int32_t ret = -1;
            if ((pFormatCtx != nullptr) && (videoStream < UINT_MAX))
            {
                if (videoStream < pFormatCtx->nb_streams)
                {
                    pCodec = avcodec_find_decoder(pFormatCtx->streams[videoStream]->codecpar->codec_id);
                    if (pCodec == nullptr)
                    {
                        RcDebugErrorLogId(rc_error_logId::elVideoPlayerUnsupportedCodec);
                    }
                    else
                    {
                        pCodecCtx = avcodec_alloc_context3(pCodec);
                        ret = avcodec_parameters_to_context(pCodecCtx, pFormatCtx->streams[videoStream]->codecpar);
                        if (ret != 0)
                        {
                            RcDebugErrorLogId(rc_error_logId::elVideoPlayerCopyCodecContextFailed);
                        }
                        else
                        {
                            ret = avcodec_open2(pCodecCtx, pCodec, nullptr);
                            if (ret < 0)
                            {
                                RcDebugErrorLogId(rc_error_logId::elVideoPlayerOpenCodecFailed);
                            }
                            else
                            {
                                pFrame = av_frame_alloc();
                                if (pFrame == nullptr)
                                {
                                    RcDebugErrorLogId(rc_error_logId::elVideoPlayerAllocFrameFailed);
                                    ret = -1;
                                }
                                else
                                {
                                    ret = 0;
                                }
                            }
                        }
                    }
                }
            }
            return (ret);
        }
    public:

        void prepare(std::string& p_url)
        {
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
            if (display != nullptr)
            {
                const auto fl_pjt = display->GetParent();
                if (fl_pjt != nullptr)
                {
                    pTaskStatus = fl_pjt->WTDoAsyncGenerlOpTask([this, p_url] {
#endif
                        clear();
                        pError = openFilenFindStreamInfo(p_url);
                        if (pError == 0)
                        {
                            pError = findnOpenCodec();
                            if (pError == 0)
                            {
                                if (!setup_frame(pCodecCtx->width, pCodecCtx->height, AV_PIX_FMT_RGBA))
                                {
                                    pError = -1;
                                }
                            }
                        }
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
                        });
                }
            }
#endif
        }

        bool is_ready()
        {
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
            bool fl_ready = false;
            if (pTaskStatus != nullptr)
            {
                fl_ready = !pTaskStatus->IsBusy();
            }
            return(fl_ready);
#else
            return(true);
#endif
        }

        void wait_for_load()
        {
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
            if (pTaskStatus != nullptr)
            {
                pTaskStatus->WaitForCompletion();
            }
#endif
        }

        bool is_error() const
        {
            return (pError != 0);
        }

        float32_t get_duration()
        {
            float32_t fl_duration = static_cast<float32_t>(pFormatCtx->duration);
            return (fl_duration / static_cast<float32_t>(AV_TIME_BASE));
        }

        float32_t get_fps()
        {
            return static_cast<float32_t>(av_q2d(pFormatCtx->streams[videoStream]->r_frame_rate));
        }

        uint32_t get_framecount()
        {
            // Calculate number of frames per second (fps)
            float32_t frmRate = static_cast<float32_t>(av_q2d(pFormatCtx->streams[videoStream]->r_frame_rate));
            // calculate Total number of frames
            uint32_t frmCnt = static_cast<uint32_t>(get_duration() * frmRate);
            return(frmCnt);
        }

        uint32_t get_width() const
        {
            return static_cast<uint32_t>(pCodecCtx->width);
        }

        uint32_t get_height() const
        {
            return static_cast<uint32_t>(pCodecCtx->height);
        }

        uint32_t get_currentframe()
        {
            int32_t fl_frame = pCodecCtx->frame_number;
            if (fl_frame < 0)
            {
                fl_frame = 0;
            }
            return static_cast<uint32_t>(fl_frame);
        }

        void set_speed(float32_t p_fps, float32_t p_factor)
        {
            float32_t fl_rfps = (p_fps * p_factor);
            pFormatCtx->streams[videoStream]->r_frame_rate = { static_cast<int32_t>(fl_rfps), 1 };
        }

        bool setup_frame(int32_t p_width, int32_t p_height, AVPixelFormat p_format)
        {
            bool fl_sts;

            tWidth = (p_width == 0) ? static_cast<uint32_t>(pCodecCtx->width) : static_cast<uint32_t>(p_width);
            tHeight = (p_height == 0) ? static_cast<uint32_t>(pCodecCtx->height) : static_cast<uint32_t>(p_height);
            tFormat = p_format;
            // set up our SWSContext to convert the image data to YUV420:
            if (sws_ctx == nullptr)
            {
                sws_ctx = sws_getContext(
                    pCodecCtx->width, pCodecCtx->height, pCodecCtx->pix_fmt, // source settings
                    tWidth, tHeight, p_format, SWS_BILINEAR, //destination settings
                    nullptr, nullptr, nullptr);
            }
            if ((buffer == nullptr) && (sws_ctx != nullptr))
            {
                int32_t fl_numBytes = av_image_get_buffer_size(p_format, p_width, p_height, 32);
                if (fl_numBytes > 0)
                {
                    bufferSize = (uint32_t)fl_numBytes;
                    buffer = static_cast<uint8_t*>(av_malloc(fl_numBytes * sizeof(uint8_t)));
                }
            }
            if ((buffer == nullptr) || (sws_ctx == nullptr))
            {
                fl_sts = false;
            }
            else
            {
                pict = av_frame_alloc();
                pPacket = av_packet_alloc();
                av_image_fill_arrays(pict->data, pict->linesize, buffer, tFormat, tWidth, tHeight, 32);
                fl_sts = true;
            }
            return(fl_sts);
        }

        int64_t FrameToPts(int frame)
        {
            AVStream* fl_avStream = pFormatCtx->streams[videoStream];
            return (static_cast<int64_t>(frame) * fl_avStream->r_frame_rate.den * fl_avStream->time_base.den) /
                   (static_cast<int64_t>(fl_avStream->r_frame_rate.num) * fl_avStream->time_base.num);
        }

        void seekframe(const uint32_t p_frame)
        {
            av_seek_frame(pFormatCtx, videoStream, FrameToPts(p_frame), 0);
        }

        void seektime(float32_t p_time)
        {
            // Convert time to frame number
            uint32_t l_frame = static_cast<uint32_t>(get_fps() * p_time);
            seekframe(l_frame);
        }

        uint8_t* get_frame_data(uint32_t p_frame, uint32_t& p_bufferSize, bool p_restart = false)
        {
            int32_t fl_frameFinished = 0;

            while (fl_frameFinished == 0)
            {
                int32_t ret = av_read_frame(pFormatCtx, pPacket);
                if (ret < 0)
                {
                    if (p_restart)
                    {
                        if (av_seek_frame(pFormatCtx, videoStream, 0, 0) >= 0)
                        {
                            av_packet_unref(pPacket);
                            ret = av_read_frame(pFormatCtx, pPacket);
                        }
                    }
                }
                if (ret >= 0)
                {
                    do
                    {
                        ret = avcodec_send_packet(pCodecCtx, pPacket);
                    } while (ret == AVERROR(EAGAIN));
                    if (ret >= 0)
                    {
                        ret = avcodec_receive_frame(pCodecCtx, pFrame);
                        if (ret != AVERROR(EAGAIN))
                        {
                            if (ret < 0)
                            {
                                RcDebugErrorLogId(rc_error_logId::elVideoPlayerDecodeError);
                            }
                            else
                            {
                                sws_scale(sws_ctx, (uint8_t const* const*)pFrame->data, pFrame->linesize, 0, tHeight, pict->data, pict->linesize);
                            }
                            fl_frameFinished = 1;
                        }
                    }
                    else
                    {
                        RcDebugErrorLogId(rc_error_logId::elVideoPlayerDecodeSendPacketError);
                    }
                    av_packet_unref(pPacket);
                }
                else if (ret != AVERROR(EAGAIN))
                {
                    fl_frameFinished = 1;
                }
                else
                {
                    //TODO: log
                }
            }
            p_bufferSize = bufferSize;
            return(buffer);
        }

        static BOOL bSetupPixelFormat(HDC hdc)
        {
            PIXELFORMATDESCRIPTOR pfd, * ppfd;
            int pixelformat;

            ppfd = &pfd;

            ppfd->nSize = sizeof(PIXELFORMATDESCRIPTOR);
            ppfd->nVersion = 1;
            ppfd->dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL |
                PFD_DOUBLEBUFFER;
            ppfd->dwLayerMask = PFD_MAIN_PLANE;
            ppfd->iPixelType = PFD_TYPE_RGBA;
            ppfd->cColorBits = 8;
            ppfd->cDepthBits = 16;
            ppfd->cAccumBits = 0;
            ppfd->cStencilBits = 0;

            pixelformat = ChoosePixelFormat(hdc, ppfd);

            if ((pixelformat = ChoosePixelFormat(hdc, ppfd)) == 0)
            {
                MessageBox(nullptr, TEXT("ChoosePixelFormat failed"), TEXT("Error"), MB_OK);
                return FALSE;
            }

            if (SetPixelFormat(hdc, pixelformat, ppfd) == FALSE)
            {
                MessageBox(nullptr, TEXT("SetPixelFormat failed"), TEXT("Error"), MB_OK);
                return FALSE;
            }

            return TRUE;
        }

        static void DrawPixels(HWND hWnd, HDC hdcwnd, uint32_t p_w, uint32_t p_h, uint8_t* p_fb)
        {
            static VOID* fl_vBit = nullptr;
            static HBITMAP  hbitmap = 0;       // bitmap handle
            HDC           hdc;           // handle of the DC we will create
            BITMAPINFO    bmi;           // bitmap header
            ULONG         ulWindowWidth, ulWindowHeight;      // window width/height
            RECT          rt;            // used for getting window dimensions
            ULONG         ulBitmapWidth, ulBitmapHeight;      // bitmap width/height

            GetClientRect(hWnd, &rt);
            ulWindowWidth = rt.right - rt.left;
            ulWindowHeight = rt.bottom - rt.top;
            hdc = CreateCompatibleDC(hdcwnd);

            if ((hbitmap == 0) && (ulWindowWidth) && (ulWindowHeight))
            {
                ZeroMemory(&bmi, sizeof(BITMAPINFO));
                ulBitmapWidth = ulWindowWidth;
                ulBitmapHeight = ulWindowHeight;
                ulBitmapWidth = p_w;
                ulBitmapHeight = p_h;
                bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
                bmi.bmiHeader.biWidth = ulBitmapWidth;
                bmi.bmiHeader.biHeight = ulBitmapHeight;
                bmi.bmiHeader.biPlanes = 1;
                bmi.bmiHeader.biBitCount = 32;         // four 8-bit components
                bmi.bmiHeader.biCompression = BI_RGB;
                bmi.bmiHeader.biSizeImage = (ulBitmapWidth * ulBitmapHeight * 4U);
                hbitmap = CreateDIBSection(hdc, &bmi, DIB_RGB_COLORS, &fl_vBit, nullptr, 0x0);
            }
            if ((fl_vBit != nullptr) && (p_fb != nullptr))
            {
                SelectObject(hdc, hbitmap);
                uint8_t* dest = static_cast<uint8_t*>(fl_vBit);
                uint8_t* src = p_fb;
                size_t size = static_cast<size_t>(ulWindowWidth * ulWindowHeight);
                for (size_t i = 0U; i < size; i++)
                {
                    // RGBA to BGRA for windows..
                    dest[0] = src[2];
                    dest[1] = src[1];
                    dest[2] = src[0];
                    dest[3] = src[3];
                    dest += 4;
                    src += 4;
                }
                int32_t fl_bh = static_cast<int32_t>(ulWindowHeight);
                StretchBlt(hdcwnd, rt.left, fl_bh - 1, ulWindowWidth, -fl_bh, hdc, 0, 0, p_w, p_h, SRCCOPY);
            }
            DeleteDC(hdc);
        }
        static const UINT WM_USER_VIDEO_DIM = WM_USER;
        static const UINT WM_USER_VIDEO_BUFFER = WM_USER + 1;

        static LRESULT WINAPI MainWndProc(HWND    hWnd, UINT    uMsg, WPARAM  wParam, LPARAM  lParam)
        {
            LRESULT      lRet = 1;
            PAINTSTRUCT  ps;
            static uint32_t vwidth = 0U;
            static uint32_t vheight = 0U;
            static uint8_t* vbuffer = nullptr;

            switch (uMsg)
            {
            case WM_USER_VIDEO_DIM:
            {
                vwidth = static_cast<uint32_t>(wParam);
                vheight = static_cast<uint32_t>(lParam);
            }
            break;
            case WM_USER_VIDEO_BUFFER:
            {
#if !defined(_WIN64)
                vbuffer = reinterpret_cast<uint8_t*>(lParam);
#else
                intptr_t msb = wParam;
                intptr_t lsb = lParam;
                vbuffer = reinterpret_cast<uint8_t*>((msb << 32) | lsb);
#endif
            }
            break;
            case WM_CREATE:
            {
                HDC hDC = GetDC(hWnd);
                if (!bSetupPixelFormat(hDC))
                {
                    PostQuitMessage(0);
                }
            }
            break;

            case WM_PAINT:
            {
                HDC hwndc = BeginPaint(hWnd, &ps);
                DrawPixels(hWnd, hwndc, vwidth, vheight, vbuffer);
                EndPaint(hWnd, &ps);
                lRet = DefWindowProc(hWnd, uMsg, wParam, lParam);
            }
            break;

            case WM_SIZE:
            {
            }
            break;

            case WM_CLOSE:
            {
                HDC hDC = GetDC(hWnd);
                if (hDC)
                {
                    ReleaseDC(hWnd, hDC);
                }
                DestroyWindow(hWnd);
            }
            break;

            case WM_DESTROY:
            {
                HDC hDC = GetDC(hWnd);
                if (hDC)
                {
                    ReleaseDC(hWnd, hDC);
                }
                PostQuitMessage(0);
            }
            break;
            default:
            {
                lRet = DefWindowProc(hWnd, uMsg, wParam, lParam);
            }
            break;
            }
            return lRet;
        }

        void update_window()
        {
            if (ghWnd == nullptr)
            {
                RECT       rect;
                WNDCLASS   wndclass;
                LPWNDCLASS wndclassinfo = nullptr;

                ghWnd = FindWindow(TEXT("RdcVideoplayer"), TEXT("RdcVideoplayer"));
                if (ghWnd != nullptr)
                {
                    return;
                }
                /* Register the frame class */
                wndclass.style = 0;
                wndclass.lpfnWndProc = (WNDPROC)MainWndProc;
                wndclass.cbClsExtra = 0;
                wndclass.cbWndExtra = 0;
                wndclass.hInstance = GetModuleHandle(nullptr);
                wndclass.hIcon = LoadIcon(GetModuleHandle(nullptr), TEXT("RdcVideoplayer"));
                wndclass.hCursor = LoadCursor(nullptr, IDC_ARROW);
                wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
                wndclass.lpszMenuName = TEXT("RdcVideoplayer");
                wndclass.lpszClassName = TEXT("RdcVideoplayer");

                if (!GetClassInfo(GetModuleHandle(nullptr), TEXT("RdcVideoplayer"), wndclassinfo))
                {
                    if (!RegisterClass(&wndclass))
                    {
                        return;
                    }
                }

                /* Create the frame */
                ghWnd = CreateWindow(TEXT("RdcVideoplayer"),
                    TEXT("RdcVideoplayer"),
                    WS_MAXIMIZE | WS_TILEDWINDOW,
                    CW_USEDEFAULT,
                    CW_USEDEFAULT,
                    tWidth,
                    tHeight,
                    nullptr,
                    nullptr,
                    GetModuleHandle(nullptr),
                    nullptr);

                /* make sure window was created */
                if (!ghWnd)
                {
                    RcDebugErrorLogId(rc_error_logId::elVideoPlayerCreateSimulationWinFailed);
                    return;
                }

                GetClientRect(ghWnd, &rect);
                if ((LONG)tWidth > rect.right)
                {
                    rect.right = (tWidth - rect.right);
                }
                else
                {
                    rect.right = 0;
                }
                rect.right += tWidth;
                if ((LONG)tHeight > rect.bottom)
                {
                    rect.bottom = (tHeight - rect.bottom);
                }
                else
                {
                    rect.bottom = 0;
                }
                rect.bottom += tHeight;
                MoveWindow(ghWnd, rect.left, rect.top, rect.right, rect.bottom, TRUE);

                SendMessage(ghWnd, WM_USER_VIDEO_DIM, tWidth, tHeight);
#if !defined(_WIN64)
                SendMessage(ghWnd, WM_USER_VIDEO_BUFFER, 0, (intptr_t)buffer);
#else
                SendMessage(ghWnd, WM_USER_VIDEO_BUFFER, ((intptr_t)buffer >> 32), ((intptr_t)buffer & 0xFFFFFFFF));
#endif
                ShowWindow(ghWnd, 1);
                UpdateWindow(ghWnd);
            }
            else
            {
                InvalidateRect(ghWnd, nullptr, FALSE);
                UpdateWindow(ghWnd);
            }
        }

        void clear()
        {
            // Clear the memory 

            if (pPacket != nullptr)
            {
                av_packet_free(&pPacket);
                pPacket = nullptr;
            }

            if (pict != nullptr)
            {
                av_frame_unref(pict);
                av_frame_free(&pict);
                pict = nullptr;
            }

            if (buffer != nullptr)
            {
                av_free(buffer);
                buffer = nullptr;
            }

            if (sws_ctx != nullptr)
            {
                sws_freeContext(sws_ctx);
                sws_ctx = nullptr;
            }

            if (pFrame != nullptr)
            {
                av_frame_free(&pFrame);
                pFrame = nullptr;
            }

            if (pCodecCtx != nullptr)
            {
                avcodec_free_context(&pCodecCtx);
                pCodecCtx = nullptr;
            }

            if (avio_ctx != nullptr)
            {
                av_freep(&avio_ctx->buffer);
                avio_context_free(&avio_ctx);
                avio_ctx = nullptr;
            }

            if (pFormatCtx != nullptr)
            {
                avformat_close_input(&pFormatCtx);
                pFormatCtx = nullptr;
            }
        }

        ~rc_player_context()
        {
            clear();
        }
        rc_player_context(gfx3d_scg_display * p_display)
        {
            display = p_display;
        }
    };

    gfxVideoPlayer::gfxVideoPlayer(gfx3d_scg_node* const p_gameObject)
    {
        if (p_gameObject != nullptr)
        {
            context = new rc_player_context(p_gameObject->GetDisplay());
            gameObj = p_gameObject;
        }
    }

    gfxVideoPlayer::~gfxVideoPlayer()
    {
        if (context != nullptr)
        {
            delete context;
            context = nullptr;
        }
        if (texture2d != nullptr)
        {
            delete texture2d;
            texture2d = nullptr;
        }
    }

    int32_t gfxVideoPlayer::GetFrame() const
    {
        return (frame);
    }

    void gfxVideoPlayer::SetFrame(const int32_t p_frame)
    {
        if (frame != p_frame)
        {
            context->seekframe(p_frame);
            frame = p_frame;
            updateReq = true;
        }
    }

    uint32_t gfxVideoPlayer::GetFrameCount() const
    {
        return(frameCount);
    }

    float32_t gfxVideoPlayer::GetFrameRate() const
    {
        return(frameRate);
    }

    uint32_t gfxVideoPlayer::GetWidth() const
    {
        return(width);
    }

    uint32_t gfxVideoPlayer::GetHeight() const
    {
        return(height);
    }

    float32_t gfxVideoPlayer::GetTime() const
    {
        return(time);
    }

    void gfxVideoPlayer::SetTime(const float32_t p_time)
    {
        if (time != p_time)
        {
            time = p_time;
            context->seektime(time);
            updateReq = true;
        }
    }

    VideoFitMode gfxVideoPlayer::GetVideoFitMode() const
    {
        return(fitMode);
    }

    void gfxVideoPlayer::SetVideoFitMode(const VideoFitMode p_fitmode)
    {
        fitMode = p_fitmode;
    }

    bool gfxVideoPlayer::IsLooping() const
    {
        return (bLooping);
    }

    void gfxVideoPlayer::SetLooping(const bool p_loop)
    {
        bLooping = p_loop;
    }

    bool gfxVideoPlayer::IsPaused() const
    {
        return(playMode == VideoPlayerMode::Paused);
    }

    bool gfxVideoPlayer::IsPlaying() const
    {
        return(playMode == VideoPlayerMode::Playing);
    }

    bool gfxVideoPlayer::IsPrepared() const
    {
        return(playMode >= VideoPlayerMode::Stopped);
    }

    float32_t gfxVideoPlayer::GetLength() const
    {
        return(lengthSeconds);
    }

    float32_t gfxVideoPlayer::GetPlaybackSpeed() const
    {
        return(playbackSpeedFactor);
    }

    void gfxVideoPlayer::SetPlaybackSpeed(const float32_t p_speed)
    {
        playbackSpeedFactor = p_speed;
    }

    bool gfxVideoPlayer::IsAutoPlay() const
    {
        return(bAutoPlay);
    }

    void gfxVideoPlayer::SetAutoPlay(const bool p_autoplay)
    {
        bAutoPlay = p_autoplay;
    }

    void gfxVideoPlayer::SetRenderMode(const VideoRenderMode p_rendermode)
    {
        renderMode = p_rendermode;
    }

    VideoRenderMode gfxVideoPlayer::GetRenderMode() const
    {
        return(renderMode);
    }

    void gfxVideoPlayer::SetTargetMaterialProperty(const std::string p_uniform)
    {
        matTex2DUniform = p_uniform;
        renderMode = VideoRenderMode::CustomMaterial;
    }

    std::string gfxVideoPlayer::GetTargetMaterialProperty() const
    {
        return(matTex2DUniform);
    }

    void gfxVideoPlayer::SetTargetMaterialRenderer(gfx3d_scg_mesh* const p_renderer)
    {
        renderer = p_renderer;
    }

    gfx3d_scg_mesh* gfxVideoPlayer::GetTargetMaterialRenderer() const
    {
        return(renderer);
    }

    void gfxVideoPlayer::SetTargetTexture(gfx3dTexture2D* const p_texture)
    {
        if (texture2d != p_texture)
        {
            if ((texture2d != nullptr) && (bInternalTex))
            {
                delete texture2d;
                bInternalTex = false;
            }
            texture2d = p_texture;
            renderMode = VideoRenderMode::CustomTexture;
        }
    }

    gfx3dTexture2D* gfxVideoPlayer::GetTargetTexture() const
    {
        return(texture2d);
    }

    gfx3dTexture2D* gfxVideoPlayer::GetTexture() const
    {
        return(texture2d);
    }

    void gfxVideoPlayer::SetUrl(const std::string p_url)
    {
        if (url != p_url)
        {
            // new url loaded, need to reload the video.
            url = p_url;
            playMode = VideoPlayerMode::Unknown;
            context->prepare(url);
        }
    }

    std::string gfxVideoPlayer::GetUrl() const
    {
        return(url);
    }

    void gfxVideoPlayer::Pause()
    {
        if (IsPlaying())
        {
            playMode = VideoPlayerMode::Paused;
        }
    }

    void gfxVideoPlayer::Play()
    {
        if ((playMode >= VideoPlayerMode::Stopped) && (playMode != VideoPlayerMode::Error))
        {
            playMode = VideoPlayerMode::Playing;
        }
    }

    void gfxVideoPlayer::Prepare()
    {
        if (playMode == VideoPlayerMode::Unknown)
        {
            playMode = VideoPlayerMode::Initializing;
        }
    }

    void gfxVideoPlayer::StepForward()
    {
        if (playMode == VideoPlayerMode::Paused)
        {
            if ((frame >= 0) && (static_cast<uint32_t>(frame) < frameCount))
            {
                update_frame();
            }
        }
    }

    void gfxVideoPlayer::Stop()
    {
        if (IsPlaying() || IsPaused())
        {
            playMode = VideoPlayerMode::Stopped;
            context->seekframe(1);
            update_frame();
        }
    }

    void gfxVideoPlayer::update_frame()
    {
        uint32_t fl_bufferSize = 0U;
        frame = context->get_currentframe();
        uint8_t* fl_buffer = context->get_frame_data(frame, fl_bufferSize, bLooping);
        if (renderMode == VideoRenderMode::OwnWindow)
        {
            context->update_window();
        }
        else
        {
            if ((renderMode == VideoRenderMode::InternalTexture) ||
                (renderMode == VideoRenderMode::CustomMaterial))
            {
                if ((texture2d == nullptr) && (gameObj != nullptr))
                {
                    texture2d = new gfx3dTexture2D(gameObj->GetDisplay(), width, height, MdlImgFormat_E::ifRgba);
                    bInternalTex = true;
                }
            }
            if (texture2d != nullptr)
            {
                texture2d->LoadRawTextureData(fl_buffer, fl_bufferSize);
                if (renderMode == VideoRenderMode::CustomMaterial)
                {
                    if (renderer != nullptr)
                    {
                        auto fl_prim = renderer->GetPrimitive(0);
                        if (fl_prim != nullptr)
                        {
                            gfx3dMaterial* fl_material = fl_prim->GetMaterial();
                            if (fl_material != nullptr)
                            {
                                fl_material->SetTexture(matTex2DUniform, texture2d);
                            }
                        }
                    }
                }
            }
        }
    }

    void gfxVideoPlayer::update()
    {
        if (!url.empty())
        {
            if ((playMode == VideoPlayerMode::Unknown) ||
                (playMode == VideoPlayerMode::Initializing))
            {
                if (context->is_ready())
                {
                    if (!context->is_error())
                    {
                        context->wait_for_load();
                        if (!context->is_error())
                        {
                            // video load success
                            frame = 0;
                            time = 0.0F;
                            frameCount = context->get_framecount();
                            frameRate = context->get_fps();
                            height = context->get_height();
                            width = context->get_width();
                            lengthSeconds = context->get_duration();
                            playMode = VideoPlayerMode::Stopped;
                        }
                        else
                        {
                            playMode = VideoPlayerMode::Error;
                        }
                    }
                    else
                    {
                        playMode = VideoPlayerMode::Error;
                    }
                }
            }
            if (playMode == VideoPlayerMode::Playing)
            {
                // update frames while playing..
                // TODO
                // 1. get the framebuffer for the current frame
                // 2. based on render mod
                //    - set to internl texture, external texture or to a window
                if ((frame > 0) && (static_cast<uint32_t>(frame) >= frameCount))
                {
                    if (!bLooping)
                    {
                        playMode = VideoPlayerMode::Stopped;
                        context->seekframe(1U);
                    }
                }
                if (playMode == VideoPlayerMode::Playing)
                {
                    update_frame();
                    updateReq = false;
                }
            }
            else if (updateReq)
            {
                if (playMode == VideoPlayerMode::Paused)
                {
                    update_frame();
                    updateReq = false;
                }
            }
            else
            {
                //TODO: log
            }
        }
    }
}
