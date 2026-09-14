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
//  Filename    : rc_imgui_performance_hud.h
//  Description : 
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#pragma once

#define MAX_FPS 300

#include "rc_imgui.h"

namespace rendercore_engine
{
	/// \ingroup Internal
	/// @{
    class PerformancePlot
    {
    private:
        size_t maxsize = 300U;
        std::vector<ImColor> colors;
        std::vector<ImU32> colorsU32;
        std::vector<float32_t> xdata;
        std::vector<std::vector<float32_t>> ydata;
        std::vector<float32_t*> ydataptr;
        std::vector<float32_t> min_ydata;
        std::vector<float32_t> max_ydata;
        std::vector<float32_t> avg_ydata;
        std::vector<std::string> labels;
        float32_t ymax = 120.0F;
        size_t windex = 0U;
        size_t rindex = 0U;
        bool roolover = false;
    public:
		PerformancePlot(const std::vector<ImColor>& p_colors, const std::vector<std::string>& p_labels, size_t p_maxsize = 300U);
		void AddData(float32_t p_xdata, const std::vector<float32_t>& p_ydata);
        void PlotData();
    };
	class performanceStatsGUI : public rc_imgui_window
	{
		int values_offset = 0;
		int id;
		gfx3d_scg_display* display;
		bool resetToDefaultLayout = true;
		PerformancePlot fpscpu_plot = PerformancePlot({ ImColor(0, 255, 0), ImColor(0, 255, 255) }, { "fps", "cpu" });
	public:
		performanceStatsGUI(int p_id, gfx3d_scg_display* p_display);
		virtual ~performanceStatsGUI();

		virtual void Render() override;
		virtual void SetVisible(bool p_value) override;
		virtual bool GetVisible() override;
		virtual int32_t GetId() override;


		void updateVisibility(bool iValue);
		void updateFPS(float32_t iValue);
		void updateFrameDuration(float32_t iValue);
		void updateAnimDuration(float32_t iValue);
		void updateBatchCount(int iValue);
		void updateTrianglesCount(int iValue);
		void updateTextureSwitchCount(int iValue);
		void updateFBOSwitchCount(int iValue);
		void updateShaderSwitchCount(int iValue);
		void updateShaderUniformSentCount(int iValue);
		void updateBufferSwitchCount(int iValue);
		void updateCpuUsage(int iValue);
		void updateGpuUsage(int iValue);
		void updateVRAMUsage(size_t iValue);
		void updateRAMUsage(size_t iValue);
		void showPerformanceHUD();
	private:
		void updateFrameInfo();

	private:
		//rwh:bool stop_thread = false;
		//rwh:std::thread the_thread;
		//rwh:std::mutex mtx;

		int m_window_flags = 0;

		bool visible = false;
		bool show_performance_hud_full = false;

		// FPS info
		int frame_cnt = 0;
		float32_t fps_cur = 0;
		float32_t cpu_cur = 0;
		// Frame duration info
		float32_t frame_duration_cur = 0.0f;

		int fio_count = 0;
		float32_t fio_transfer[MAX_FPS] = { 0.0f };
		float32_t fio_duration[MAX_FPS] = { 0.0f };
		float32_t fio_bytes[MAX_FPS] = { 0.0f };

		// Animation duration info
		float32_t anim_duration[MAX_FPS] = { 0.0f };
		float32_t anim_duration_cur = 0.0f;
		float32_t anim_duration_min = 0.0f;
		float32_t anim_duration_max = 0.0f;
		float32_t anim_duration_cum = 0.0f;
		float32_t anim_duration_avg = 0.0f;

		// Batch Count info
		float32_t batch_count[MAX_FPS] = { 0.0f };
		float32_t batch_count_cur = 0;
		float32_t batch_count_min = 0.0f;
		float32_t batch_count_max = 0;
		float32_t batch_count_cum = 0;
		float32_t batch_count_avg = 0;

		// Triangles count
		int triangle_count = 0;

		// Texture Switches
		int texture_switch_count = 0;

		// FBO Switches
		int fbo_switch_count = 0;

		// Shader
		int shader_switch_count = 0;
		int shader_uniform_sent_count = 0;

		// Buffer Switches
		int buffer_switch_count = 0;

		// Resource CPU/GPU Usage
		float32_t cpu_utilization = 0.0f;
		float32_t gpu_utilization = 0.0f;

		// Resource Memory Usage	
		size_t vram_utilized = 0U;
		size_t ram_utilized = 0U;

	};

	/// @}
}