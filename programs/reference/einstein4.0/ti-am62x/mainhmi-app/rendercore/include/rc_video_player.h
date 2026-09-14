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
//  Filename    : rc_video_player.h
//  Description : Header file for the video player
//  Created on  : 16-Sep-2019 by cshrihar@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef rc_video_player_h
#define rc_video_player_h

#include <string>
#include <cstdint>

namespace rendercore_engine
{
    enum class VideoRenderMode
    {
        OwnWindow,          ///< Renders the video to own window
        InternalTexture,    ///< Renders the video to an internal texture, which can be retrived via API
        CustomTexture,      ///< Renders the video to the attached nodes's first mesh
        CustomMaterial      ///< Renders to the specified material's texture uniform
    };
    enum class VideoFitMode
    {
        FitNone,            ///< Fits to destination frame, maintaining aspect ratio, No cropping, but pixels addition to width/height to compensate
        FitVertically,      ///< Fits heightwise to destination frame. Cropping or pixels addition to width to compensate
        FitHorizontally,    ///< Fits widthwise to destination frame. Cropping or pixels addition to height to compensate
        FitStretch          ///< Fits to the destination frame. May loose aspect ratio
    };
    enum class VideoPlayerMode
    {
        Unknown,        ///< Player is in init state
        Initializing,   ///< Player is loading the video and not yet ready to play the video
        Stopped,        ///< Video is loaded and the player is ready to play on command
        Playing,        ///< Video is currently playing
        Paused,         ///< Video is currently paused
        Error           ///< Video can't be played due to error
    };

    class rc_player_context;
    class gfxVideoPlayer
    {
    private:
        rc_player_context* context = nullptr;                       ///< manages the video decoder context for the player
        gfx3d_scg_node* gameObj = nullptr;                          ///< Parent Gameobject of this video player instance
        gfx3dTexture2D* texture2d = nullptr;                        ///< Texture 2D object when the video to be rendered to a texture
        gfx3d_scg_mesh* renderer = nullptr;                         ///< Pointer to renderer, when the video to be rendered to a custom material VideoRenderMode::CustomMaterial
        std::string matTex2DUniform;                                ///< tex 2D uniform, when the vide to be rendered to a custom material VideoRenderMode::CustomMaterial
        std::string url;                                            ///< path to video file URL
        int32_t frame = -1;                                         ///< current frame number of video player
        uint32_t frameCount = 0U;                                   ///< total frames in video
        float32_t frameRate = 0.0F;                                 ///< frames per second of the current video
        uint32_t height = 0U;                                       ///< height in pixels of the current video
        uint32_t width = 0U;                                        ///< width in pixels of the current video
        float32_t lengthSeconds = 0.0F;                             ///< Length of currently loaded video in seconds 
        float32_t playbackSpeedFactor = 1.0F;                       ///< Video playback speed factor. 1.0 is actual speed, 2.0 plays twice faster
        float32_t time = 0.0F;                                      ///< Current playback time / position in seconds of the video
        VideoFitMode fitMode = VideoFitMode::FitStretch;            ///< Specifies how the video to be fitted in destination window
        VideoPlayerMode playMode = VideoPlayerMode::Unknown;        ///< Current Video player mode
        VideoRenderMode  renderMode = VideoRenderMode::OwnWindow;   ///< Where the video should be rendered
        bool bLooping = false;                                      ///< if true indicates that the video loops for ever, when played
        bool bAutoPlay = true;                                      ///< if true indicates that the video shall play as soon as video is loaded. False indicates a user trigger is required to play
        bool bInternalTex = false;                                  ///< Indicates the texture 2D is internally created
        bool updateReq = false;                                     ///< An update request is pending
        void update_frame();                                        ///< Updates the video frame data
    public:
        ///< Constructor
        gfxVideoPlayer(gfx3d_scg_node* const p_gameObject = nullptr);
        ///< Destructor
        ~gfxVideoPlayer();
        /// <summary>
        /// Periodic update task for the video player
        /// </summary>
        void update();
        /// <summary>
        /// Get the current frame number which is being played
        /// Wait for gfxVideoPlayer::IsPrepared() to return true before invoking, else return value is not valid
        /// </summary>
        /// <returns>frame number</returns>
        int32_t GetFrame() const;
        /// <summary>
        /// Set the next frame number to be played
        /// </summary>
        /// <param name="p_frame">frame number to be set</param>
        void SetFrame(const int32_t p_frame);
        /// <summary>
        /// Gets the number of frames available in input video
        /// Wait for gfxVideoPlayer::IsPrepared() to return true before invoking, else return value is not valid
        /// </summary>
        /// <returns>frame number</returns>
        uint32_t GetFrameCount() const;
        /// <summary>
        /// Returns the frames/second for the input video
        /// Wait for gfxVideoPlayer::IsPrepared() to return true before invoking, else return value is not valid
        /// </summary>
        /// <returns>fps</returns>
        float32_t GetFrameRate() const;
        /// <summary>
        /// Input video width in pixels
        /// Wait for gfxVideoPlayer::IsPrepared() to return true before invoking, else return value is not valid
        /// </summary>
        /// <returns>width in pixels</returns>
        uint32_t GetWidth() const;
        /// <summary>
        /// Input video height in pixels
        /// Wait for gfxVideoPlayer::IsPrepared() to return true before invoking, else return value is not valid
        /// </summary>
        /// <returns>height in pixels</returns>
        uint32_t GetHeight() const;
        /// <summary>
        /// Gets the current playback time or position of the video in seconds
        /// Wait for gfxVideoPlayer::IsPrepared() to return true before invoking, else return value is not valid
        /// </summary>
        /// <returns></returns>
        float32_t GetTime() const;
        /// <summary>
        /// Sets the position of the video to the specified seconds. Next frame will be choosen accordingly
        /// Wait for gfxVideoPlayer::IsPrepared() to return true before invoking, else return value is not valid
        /// </summary>
        /// <param name="p_time">time in seconds</param>
        void SetTime(const float32_t p_time);
        /// <summary>
        /// Gets the aspect ratio followed to map the the video
        /// </summary>
        /// <returns>aspect mode</returns>
        VideoFitMode GetVideoFitMode() const;
        /// <summary>
        /// Sets the aspect ratio to be followed to map the the video
        /// </summary>
        /// <param name="p_fitmode">aspect mode</param>
        void SetVideoFitMode(const VideoFitMode p_fitmode);
        /// <summary>
        /// Returns true if loop playback is enabled. i.e. video restarts to start after reaching end
        /// </summary>
        /// <returns>true or false</returns>
        bool IsLooping() const;
        /// <summary>
        /// Sets the looping mode to true or false
        ///  true - video loops infinetly
        ///  false - video plays once
        /// </summary>
        /// <param name="p_loop">true to enable looping</param>
        void SetLooping(const bool p_loop);
        /// <summary>
        /// Check if the video is paused or not
        /// </summary>
        /// <returns>true if paused</returns>
        bool IsPaused() const;
        /// <summary>
        /// Check if the video is playing or not
        /// </summary>
        /// <returns>true if playing</returns>
        bool IsPlaying() const;
        /// <summary>
        /// Check if the video is ready to play or not
        /// </summary>
        /// <returns>true if ready, else still loading in progress</returns>
        bool IsPrepared() const;
        /// <summary>
        /// Gets the length of the video in seconds
        /// Wait for gfxVideoPlayer::IsPrepared() to return true before invoking, else return value is not valid
        /// </summary>
        /// <returns>video length in seconds</returns>
        float32_t GetLength() const;
        /// <summary>
        /// Returns the playback speed multiplier factor
        /// e.g. 2.0 means runs twice the fps than video input
        /// </summary>
        /// <returns>speed multiplier factor</returns>
        float32_t GetPlaybackSpeed() const;
        /// <summary>
        /// Sets the video playback speed multiplier factor
        /// e.g. 2.0 means runs twice the fps than video input
        /// </summary>
        /// <param name="p_speed">speed multiplier factor</param>
        void SetPlaybackSpeed(const float32_t p_speed);
        /// <summary>
        /// Check if auto play is enabled or not (playOnAwake).
        /// </summary>
        /// <returns>true if autoplay enabled</returns>
        bool IsAutoPlay() const;
        /// <summary>
        /// Sets the autoplay mode
        /// </summary>
        /// <param name="p_autoplay">true to enable auto play</param>
        void SetAutoPlay(const bool p_autoplay);
        /// <summary>
        /// Select the render target for the video
        /// </summary>
        /// <param name="p_rendermode">render target selection</param>
        void SetRenderMode(const VideoRenderMode p_rendermode);
        /// <summary>
        /// Get the current render target selection
        /// </summary>
        /// <returns>render target selection</returns>
        VideoRenderMode GetRenderMode() const;
        /// <summary>
        /// Set Marerial uniform name to which the video texture to be mapped
        /// Valid when GetRederMode() == VideoRenderMode::CustomMaterial
        /// </summary>
        /// <param name="p_uniform">name of uniform</param>
        void SetTargetMaterialProperty(const std::string p_uniform);
        /// <summary>
        /// Get Material uniform name to which the video texture to be mapped
        /// Valid when GetRederMode() == VideoRenderMode::CustomMaterial
        /// </summary>
        /// <returns>name of uniform</returns>
        std::string GetTargetMaterialProperty() const;
        /// <summary>
        /// Render to be used when GetRederMode() == VideoRenderMode::CustomMaterial
        /// </summary>
        /// <param name="p_renderer">pointer to renderer</param>
        void SetTargetMaterialRenderer(gfx3d_scg_mesh* const p_renderer);
        /// <summary>
        /// Render to be used when GetRederMode() == VideoRenderMode::CustomMaterial
        /// </summary>
        /// <returns>pointer to renderer</returns>
        gfx3d_scg_mesh* GetTargetMaterialRenderer() const;
        /// <summary>
        /// Target texture2d where the video to be rendered when GetRederMode() == VideoRenderMode::CustomTexture
        /// </summary>
        /// <param name="p_texture">texture 2d pointer</param>
        void SetTargetTexture(gfx3dTexture2D* const p_texture);
        /// <summary>
        /// Target texture2d where the video to be rendered when GetRederMode() == VideoRenderMode::CustomTexture
        /// </summary>
        /// <returns>texture 2d pointer</returns>
        gfx3dTexture2D* GetTargetTexture() const;
        /// <summary>
        /// Returns the internal texture2D where the vide is rendered when GetRederMode() == VideoRenderMode::InternalTexture. 
        /// </summary>
        /// <returns>texture 2d pointer</returns>
        gfx3dTexture2D* GetTexture() const;
        /// <summary>
        /// Sets the video Url
        /// </summary>
        /// <param name="p_url">url to video to be played</param>
        void SetUrl(const std::string p_url);
        /// <summary>
        /// Gets the video url which is being played
        /// </summary>
        /// <returns>url to video played</returns>
        std::string GetUrl() const;
        /// <summary>
        /// Pauses the playbackand leaves the current time intact.
        /// </summary>
        void Pause();
        /// <summary>
        /// Starts playback.
        /// </summary>
        void Play();
        /// <summary>
        /// Initiates playback engine preparation.
        /// </summary>
        void Prepare();
        /// <summary>
        /// Advances the current time by one frame immediately.
        /// </summary>
        void StepForward();
        /// <summary>
        /// Stops the playbackand sets the current time to 0.
        /// </summary>
        void Stop();
    };
}
#endif