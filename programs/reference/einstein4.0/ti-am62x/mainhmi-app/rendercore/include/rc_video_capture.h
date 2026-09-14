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
//  Filename    : rc_ffmpeg_capture.h
//  Description : Implementation for capturing OpenGL output as a video
//  Created on  : 24-SEP-2020 by Ashutosh Morwal
///////////////////////////////////////////////////////////////////////////////
#ifndef ffmpeg_vdo_cap_h
#define ffmpeg_vdo_cap_h
#include "gfx3d_scg.h"

namespace rendercore_engine
{
#if defined(ENABLE_FFMPEG)
    class rc_ffmpeg_data;
    class rc_video_capture
    {
    private:
        rc_ffmpeg_data* ffmpegdata;
        uint8_t* rgb;
        unsigned int max_nframes;
        GLubyte* pixels;
        unsigned int nframes;
        int size_written;
        void ffmpeg_encoder_set_frame_yuv_from_rgb(uint8_t* rgb);
        void ffmpeg_encoder_encode_frame(uint8_t* rgb);
        void ffmpeg_encoder_glread_rgb(uint8_t** rgb, GLubyte** pixels);
    public:
        unsigned int getNframes();
        rc_video_capture(unsigned int w, unsigned int h);
        ~rc_video_capture();
        void Start(const std::string& p_path);
        void Finish(void);
        void CaptureFrame();
    };
#else
    class rc_video_capture
    {
    public:
        rc_video_capture(unsigned int w, unsigned int h)
        {
        }
        void Start(const std::string& p_path)
        {
        }
        void Finish(void)
        {
        }
        void CaptureFrame()
        {
        }
    };
#endif
}
#endif
