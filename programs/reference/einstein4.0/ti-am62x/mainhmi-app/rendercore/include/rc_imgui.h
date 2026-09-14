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
//  Filename    : rc_debug.h

//  Description : debug interfaces..
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef rc_imgui_h
#define rc_imgui_h

#include <limits>
#include <thread>
#include <mutex>
#include <iostream>
#include <vector>

#define MAX_FPS 300

namespace rendercore_engine
{
	class gfx3d_scg_display;
	class gfx3d_scg_node;

	/// \ingroup Internal
	/// @{

	class rc_imgui_window
	{
	private:
		rc_imgui_window& operator=(const rc_imgui_window& p_rhs) = delete;
	public:
		virtual ~rc_imgui_window();
		virtual void Render() = 0;
		virtual void SetVisible(bool p_value) = 0;
		virtual bool GetVisible() = 0;
		virtual int32_t GetId() = 0;
		virtual bool PostRender();
	};

	/// @}

	enum class rc_video_capture_state
	{
		rc_invalid,
		rc_idle,
		rc_recording,
		rc_paused,
		rc_finished
	};
	class rc_video_capture;
	/// \ingroup Internal
	/// @{
	class rc_imgui
	{
	private:
		gfx3d_scg_display* display;
		std::vector< rc_imgui_window*> imguiWindows;
		rc_video_capture* ffmpegCapture = nullptr;
		rc_video_capture_state ffmpegstate = rc_video_capture_state::rc_invalid;
	public:
		rc_imgui(gfx3d_scg_display* p_display);
		virtual ~rc_imgui();

		enum WINDOW
		{
			PERFORMANCE_HUD = 1 << 0,
			EDITOR = 1 << 1,
			CONTROL_NODES = 1 << 2
		};

		void LoadWindows(int32_t p_flag = (static_cast<int32_t>(PERFORMANCE_HUD) | static_cast<int32_t>(EDITOR) | static_cast<int32_t>(CONTROL_NODES)));

		virtual void AddWindow(rc_imgui_window* p_win);

		virtual rc_imgui_window* GetWindow(int32_t p_flag);

		virtual bool RenderWindows();

		virtual void SetVisibility(WINDOW p_id, bool p_value);

		virtual void ToggleVisibility(WINDOW p_id);

		virtual bool IsMouseEventProcessing();

		virtual bool IsNetImGuiConnected();

		static rc_imgui* Get(gfx3d_scg_display* p_display);
		static void Clear(gfx3d_scg_display* p_display);
		static void Render(gfx3d_scg_display* p_display);

		void CaptureFinish();
		void CapturePause();
		void CaptureStart(const std::string& p_resPath);
		rc_video_capture_state GetCaptureState();
		void SendMouseEvent(bool p_ldown, float p_x, float p_y, float p_scroll);
	};
	/// @}
}
#endif
