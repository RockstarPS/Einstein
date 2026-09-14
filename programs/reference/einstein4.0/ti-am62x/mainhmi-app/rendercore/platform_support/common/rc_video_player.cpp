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

namespace rendercore_engine
{
    gfxVideoPlayer::gfxVideoPlayer(gfx3d_scg_node* const p_gameObject)
    {
        gameObj = p_gameObject;
    }
    gfxVideoPlayer::~gfxVideoPlayer()
    {
    }
    int32_t gfxVideoPlayer::GetFrame() const
    {
        return(frame);
    }
    void gfxVideoPlayer::SetFrame(const int32_t p_frame)
    {
        frame = p_frame;
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
        time = p_time;
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
        return(playMode == VideoPlayerMode::Stopped);
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
        texture2d = p_texture;
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
        if (IsPaused())
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
        if ((frame >= 0) && (static_cast<uint32_t>(frame) < frameCount))
        {
            frame++;
        }
    }
    void gfxVideoPlayer::Stop()
    {
        if (IsPlaying() || IsPaused())
        {
            playMode = VideoPlayerMode::Stopped;
        }
    }
    void gfxVideoPlayer::update()
    {
    }
}