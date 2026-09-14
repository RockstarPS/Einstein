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
#include <climits>
#include "imgui.h"
#include "rc_imgui.h"
#include <map>

#define UL(label, obj) (std::string(#label).append("##").append(std::to_string((uintptr_t)obj))).c_str()

class TextEditor;
namespace rendercore_engine
{
	class gfx3d_scg_camera;
	class gfx3d_scg_anim;
	class gfx3d_scg_scene;
	class gfx3dTransform;

#define EDITOR_MAX_PRMITIVE_DISPLAY 16

	class ImGuiAppLog
	{
		ImGuiTextBuffer     Buf;
		ImGuiTextFilter     Filter;
		ImVector<int>       LineOffsets;        // Index to lines offset. We maintain this with AddLog() calls, allowing us to have a random access on lines
		bool AutoScroll;     // Keep scrolling if already at the bottom
		bool suppressInfo = false;
		bool suppressWarn = false;
	public:
		ImGuiAppLog();
		void Clear();
		void AddLog(const rc_message_type p_type, const char* fmt, ...) IM_FMTARGS(3);
		void Draw(const char* title, bool* p_open = NULL);
	};

	/// \ingroup Internal
	/// @{
	struct enumMapping;
	class RcImguilogCbBase : public IRclogCbBase
	{
	public:
		ImGuiAppLog imguiLog;
		void RclogCallback(const rc_message_info p_msgInfo) override;
	};
	
	class rc_imgui_editor : public rc_imgui_window
	{
		int scgActiveSceneCount = 0; //refresh every next frame
		ImGuiTextFilter sceneFilter;
		int animActiveCount = 0; //refresh every next frame
		ImGuiTextFilter animFilter;
		int fl_mipmapsaved = 0;
		GLuint fl_mippoid = 0;
		int fl_mipucount = -1;
		bool show_tex_window = false;
		GLuint fl_seltex = 0U;
		bool l_extra = false;
		bool l_extra1 = false;
		char save_path[255] = "\0";
		bool showGStrans = true;
		bool header = false;
		std::vector<float32_t> skintrans;
		bool bskintrans = false;
		float32_t prevgsdata = 1.0f;
		int skincount = 0;
		const ImU32 color = ImColor(0, 255, 0);
		bool forceSaveReload = false;
		float32_t lineThickness = 1.0f;
		gfx3d_scg_scene* loadedSceneGuide = nullptr;
		bool linehover = false;
		bool linePull = false;
		int lineValue = 0;
		bool linehover1 = false;
		bool linePull1 = false;
		int lineValue1 = 0;
		int sceneId = 0;
		char sceneNames[256 * 128];
		std::vector< gfx3d_scg_scene*> scenesList;


		struct _zoomwindowData
		{
			UCHAR8* pix_data;
			int width = 128;
			int height = 128;
			int win_posx = 0;
			int win_posy = 0;
			GLuint texObj = 0;
			int zoom = 2;
		};
		IRclogCallbackSp logCb = IRclogCallbackSp(new RcImguilogCbBase());
		_zoomwindowData zoomwindowData;

		int id;
		gfx3d_scg_display* display = nullptr;
		gfx3d_scg_scene* currentScene = nullptr;
		int window_flags = 0;
		bool visible = false;

		bool showTimeline = false;
		bool showFPSInfo = false;
		bool showDetailedFPSInfo = false;
		bool showLayout = false;
		bool showTouchArea = false;
		bool showLayoutShaded = false;
		bool showLayoutRecursive = false;
		bool showLayoutChildAlso = false;
		bool showLayoutParentAlso = false;
		bool showRenderedMeshes = false;
		bool showLogWindow = false;

		bool resetToDefaultLayout = true;
		bool useDockWindowStyle = false;

		enum class _guideType
		{
			hide,
			rect,
			line,
			vline,
			hline,
			deleteType,
		};

		struct _guideData
		{
			_guideType type = _guideType::hide;
			glm::vec4 value;
			bool lineMoving = false;
		};

		bool loadGuides = true;
		std::vector<_guideData> lineGuidesData;
		bool showGuides = false;
		bool showGuidesEditor = true;
		bool showZoom = false;

		float32_t timeline = 0.0;
		float32_t timelineStart = 0.0;
		float32_t timelineEnd = 10.0;

		std::string windowTitle = "";

		std::string cullModeMappingStr = "";
		std::string blendModeMappingStr = "";
		std::string ablendModeMappingStr = "";
		std::string blendEqationStr = "";
		std::string ablendEqationStr = "";
		std::string depthTestMappingStr = "";
		std::string srcblendFactorMappingStr = "";
		std::string dstblendFactorMappingStr = "";
		std::string asrcblendFactorMappingStr = "";
		std::string adstblendFactorMappingStr = "";

		bool loggingEnabled = false;
		bool loggingAlwaysOn = false;
		bool envlistLoaded = false;
		int curEnv = 0;
		std::vector<std::string> hdrlist;

		void ShowSceneNodes(gfx3d_scg_node* node, bool parentVisible);
		void ShowRenderOrderGroups();
		void ShowGeneralInfo();
		void ShowAnimationsInfo();
		void ShowCameraInfo(gfx3d_scg_camera* camera);
		void ShowCamerasInfo();
		void ShowSceneGraph();

		void UnselectOtherSelectedProperty();

		void ShowSelectedAnimationProperty();

		std::string GetFullname(gfx3d_scg_node* node);

		std::string GetProperties(gfx3d_scg_node* node);

		void ShowSelectedNodeProperty();
		void ShowSelectedCameraProperty();

		void ShowMainEditor();

		void ShowMaterial(int p_meshidx, gfx3d_scg_material* material);

		void ShowTimelineEditor();

		bool IsNodeVisible(gfx3dTransform* node);

		void showLayoutNodeRec(gfx3d_scg_node* node, gfx3d_scg_camera* camera, bool rec, bool parentAlso);
		void showTouchLayoutNodeRec(gfx3d_scg_node* node, gfx3d_scg_camera* camera, bool rec, ImU32 p_scolor = ImColor(ImVec4(1.0f, 1.0f, 0.0f, 0.5f)));

		void ShowLayoutInfo();

		void ShowLogWindow(bool* p_open);

		void ShowZoom();

		void LayoutPreset();

		struct TextEditorProperty
		{
			TextEditor* editor = nullptr;

			std::string filename = "";
		};

		std::vector<TextEditorProperty*> openedTextFiles;

		TextEditorProperty* OpenTextFile(std::string filepath);

		void CloseTextFile(TextEditorProperty* editorProperty);

		int ShowTextEditor(TextEditorProperty* editorProperty);

		void ShowTextEditors();

		void SaveTextFile(TextEditorProperty* editorProperty);

		bool IsAnyMeshesRendered(gfx3d_scg_node* node, size_t p_CamCullingMask);

		struct NodeProperties
		{
			bool visible = false;
			bool primvisible = true;
			float32_t opacity = 0;
			int cullMode = 0;
			int cullingmask = 0;
			int blendMode = 0;
			int depthTest = 0;
			int depthWrite = 0;
			int flipBookIndex = -1;
			int totalChildren = 0;
			gfx3d_scg_node* node = nullptr;
			gfx3d_scg_scene* scene = nullptr;

			//layout node
			mdl_layoutOrder_E layout_order = mdl_layoutOrder_E::oNormal;
			mdl_layoutHalign_E layout_hAlign = mdl_layoutHalign_E::hLeft;
			mdl_layoutValign_E layout_vAlign = mdl_layoutValign_E::vTop;
			mdl_layoutDirection_E layout_direction = mdl_layoutDirection_E::dHorizontal;
			float32_t layout_width = 0;
			float32_t layout_height = 0;

			int cullModeForMaterial[EDITOR_MAX_PRMITIVE_DISPLAY];

			void Set(gfx3d_scg_node* p_node, gfx3d_scg_scene* p_scene);
			NodeProperties() :cullMode(0), node(nullptr) {}
		};

		struct CameraProperties
		{
			std::string name = "";
			int cullMode = 0;
			int cullingmask = 0;
			int blendMode = 0;
			int depthTest = 0;
			int depthWrite = 0;

			float32_t viewport[4] = { 0,0,1.0f,1.0f };

			float32_t xmag = 0;
			float32_t ymag = 0;

			bool orthographic = false;
			int render_target = 0;
			float32_t fieldOfView = 1.0f;
			float32_t nearClipPlane = 0.1f;
			float32_t farClipPlane = 1.0f;
			float32_t aspect = 1.0f;

			float32_t backgroundColor[4] = { 0,0,0,0 };

			int renderOrder = 0;
			float32_t clearDepthValue = 0;
			bool active = false;

			gfx3d_scg_camera* node = nullptr;

			void Set(gfx3d_scg_camera* p_node, std::string p_name);
			CameraProperties() :cullMode(0), node(nullptr) {}
		};

		struct AnimationProperties
		{
			std::string name = "";
			MdlAnimationPlaybackMode_E playback = MdlAnimationPlaybackMode_E::apmNormal;
			int repeatCount = 0;
			float32_t playbackSpeed = 0;

			gfx3d_scg_anim* node = nullptr;
			std::vector<gfx3d_scg_anim*> nodes;
			void Set(gfx3d_scg_anim* p_node, std::string p_name);
		};

		NodeProperties selectedNode;
		CameraProperties selectedCamera;
		AnimationProperties selectedAnimation;

		bool buildCameraList = true;
		bool sortCameraList = false;
		std::map<int, std::vector<gfx3d_scg_camera*>> cameraList;
		void FillCameraList();
		void render_glyphinfo(rc_text_shaper_info& p_shinfo, std::vector<rc_text_render_char_info> p_chinfo);
		void UpdateTextureFiltering(gfx3dTexture2D* p_tex);
		rc_imgui* parent = nullptr;
	public:
		rc_imgui_editor(int p_id, gfx3d_scg_display* p_display, rc_imgui * p_parent);
		virtual ~rc_imgui_editor();

		void ShowGuides();

		virtual void Render() override;
		virtual bool PostRender() override;
		virtual void SetVisible(bool p_value) override;
		virtual bool GetVisible() override;
		virtual int32_t GetId() override;

		void EnabledLogging(bool p_alwaysOn = false);
		void DisableLogging();
		std::string utf16toutf8(std::u16string& p_string);

	};

	/// @}
}