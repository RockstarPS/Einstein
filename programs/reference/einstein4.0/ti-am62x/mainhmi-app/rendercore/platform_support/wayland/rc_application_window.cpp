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
//  Filename    : rc_ws_windows.h
//  Description : Platform specific window handling for X11
//  Created on  : 20-Feb-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef WIN32

#include "gfx3d_scg.h"
#include "rc_application_window.h"
#include <wayland-client.h>
#include <xdg-shell.h>
#include <wayland-egl.h>
#include <EGL/egl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sys/time.h>
#include <unistd.h>
#if defined(RCIMGUI_ENABLE)
#include "rc_imgui.h"
#endif
#define BG_APP

using namespace rendercore_engine;

namespace rendercore_engine
{
	/// contains data about the window
	struct ContextData
	{
		int width = 0;		///< width 
		int height = 0;		///<height
		bool m_configured = false;
		EGLNativeDisplayType eglNativeDisplay = static_cast<EGLNativeDisplayType>(EGL_DEFAULT_DISPLAY);	///<native display for window
		EGLNativeWindowType  eglNativeWindow = static_cast<EGLNativeWindowType>(nullptr);				///<native window
		struct wl_compositor* compositor = nullptr;
		struct wl_display* display = nullptr;	///<display object
		struct wl_surface* surface = nullptr;
		struct wl_registry* registry = nullptr;
		struct xdg_wm_base* shell = nullptr;
		struct xdg_surface* shell_surface = nullptr;
		struct xdg_toplevel* m_topLevel;
	
	};

	static void rc_wl_global_registry_handler(void* p_data, struct wl_registry* p_registry, uint32_t p_id, const char* p_interface, uint32_t p_version)
	{
		ContextData* fl_contextData = static_cast<ContextData*>(p_data);
		if ((p_interface != nullptr) && (fl_contextData != nullptr))
		{
			if (0 == strcmp(p_interface, "wl_compositor"))
			{
				fl_contextData->compositor = static_cast<wl_compositor*>(wl_registry_bind(p_registry, p_id, &wl_compositor_interface, 1));
				ILOG("rc_wl_global_registry_handler %s\n", p_interface);
			}
			else if (0 == strcmp(p_interface, "wl_shell"))
			{
				//fl_contextData->shell =  static_cast<wl_shell*>(wl_registry_bind(p_registry, p_id, &wl_shell_interface, 1));
				ILOG("rc_wl_global_registry_handler %s\n", p_interface);
			}
			else if (0 == strcmp(p_interface, "xdg_wm_base"))
			{
				fl_contextData->shell = static_cast<xdg_wm_base*>(wl_registry_bind(p_registry, p_id, &xdg_wm_base_interface, 1));
				//xdg_wm_base_add_listener(fl_contextData->shell, &g_wmBaseListener, fl_contextData);
				ILOG("rc_wl_global_registry_handler %s\n", p_interface);
			}
			else
			{
				ILOG("rc_wl_global_registry - %s\n", p_interface);
			}
		}
	}
	static void rc_wl_global_registry_remover(void* p_data, struct wl_registry* p_registry, uint32_t p_id)
	{
	}
	static const struct wl_registry_listener lc_registry_listener =
	{
		rc_wl_global_registry_handler,
		rc_wl_global_registry_remover
	};
	static void handleConfigure(void* data, struct xdg_surface* xdgSurface, uint32_t serial)
	{
		ContextData* fl_contextData = static_cast<ContextData*>(data);
		fl_contextData->m_configured = true;
		ILOG("XDG Surface Configured \n");
		xdg_surface_ack_configure(xdgSurface, serial);
	}

	static const struct xdg_surface_listener s_xdgSurfaceListener
	{
		handleConfigure
	};

	static void handlePing(void* data, struct xdg_wm_base* shell, uint32_t serial)
	{
		//DE_UNREF(data);
		xdg_wm_base_pong(shell, serial);
	}
	static const struct xdg_wm_base_listener s_wmBaseListener
	{
		handlePing
	};

	/// class rc win handles has the main handle for the window
	class rc_win_handles
	{
	private:

	public:
		ContextData data; ///< context data object
		rc_generic_ws* winConfig; ///< window config object
		///constructor
		rc_win_handles(rc_generic_ws* p_winConfig)
		{
			winConfig = p_winConfig;
		}
		///create window using contextData and title
		int WinCreate(ContextData* contextData, const char* title)
		{
			if (contextData != nullptr)
			{
				contextData->display = wl_display_connect(0);
				if (contextData->display == nullptr)
				{
					ELOG("wl_display_connect failed\n");
				}
				else
				{
					ILOG("wl_display_connected\n");
					{
						contextData->registry = wl_display_get_registry(contextData->display);
						wl_registry_add_listener(contextData->registry, &lc_registry_listener, (void*)contextData);
						//wl_display_dispatch(contextData->display);
						wl_display_roundtrip(contextData->display);
						if (nullptr != contextData->compositor)
						{
							ILOG("compositor done\n");
							contextData->surface = wl_compositor_create_surface(contextData->compositor);
							if (nullptr != contextData->surface)
							{
								ILOG("wl_compositor_create_surface done\n");
								if (contextData->shell != nullptr)
								{
									contextData->shell_surface = xdg_wm_base_get_xdg_surface(contextData->shell, contextData->surface);
									if (contextData->shell_surface != nullptr)
									{
										//wl_shell_surface_set_toplevel(contextData->shell_surface);
										xdg_wm_base_add_listener(contextData->shell, &s_wmBaseListener, this);
										xdg_surface_add_listener(contextData->shell_surface, &s_xdgSurfaceListener, this);

										// select xdg surface role
										contextData->m_topLevel = xdg_surface_get_toplevel(contextData->shell_surface);
										xdg_toplevel_set_title(contextData->m_topLevel, "BMDemo(ES)");
										ILOG("wl_surface_commit done\n");
									}
									else
									{
										ELOG("wl_shell_get_shell_surface failed\n");
									}
									#ifdef BG_APP
									struct wl_region* region;
									region = wl_compositor_create_region(contextData->compositor);
									wl_region_add(region, 0, 0,
										contextData->width,
										contextData->height);
									wl_surface_set_opaque_region(contextData->surface, region);
									wl_region_destroy(region);
									#else
									wl_surface_set_opaque_region(contextData->surface, NULL);
									#endif
									
								}
								contextData->m_configured = false;
								wl_surface_commit(contextData->surface);
								// wait till xdg surface is configured
								int dispatchedEvents = 0;
								while (dispatchedEvents != -1)
								{
									dispatchedEvents = wl_display_dispatch(contextData->display);
									if (contextData->m_configured)
										break;
								}

								contextData->eglNativeWindow = wl_egl_window_create(contextData->surface, contextData->width, contextData->height);
								contextData->eglNativeDisplay = (EGLNativeDisplayType)contextData->display;

								ILOG("wl_surface_commit done\n");
							}
							else
							{
								ELOG("wl surface failed\n");
							}
						}
						else
						{
							ELOG("wl compositor failed\n");
						}
					}
				}
			}
			return EGL_TRUE;
		}


		///open window
		bool Open(void)
		{
			bool sts = false;
			if (winConfig != nullptr)
			{
				data.width = winConfig->GetWidth();
				data.height = winConfig->GetHeight();
			}
			else
			{
				data.width = 1920;
				data.height = 720;
			}
			ILOG("Windows Created %d %d \n", data.width, data.height);
			sts = WinCreate(&data, "Rendercore");
			return(sts);
		}
		bool Close(void)
		{
			bool fl_sts;
			wl_egl_window_destroy(static_cast<struct wl_egl_window*>(data.eglNativeWindow));
			wl_surface_destroy(data.surface);
			xdg_surface_destroy(data.shell_surface);
			wl_registry_destroy(data.registry);
			xdg_toplevel_destroy(data.m_topLevel);
			wl_display_flush(data.display);
			wl_display_disconnect(data.display);
			fl_sts = true;
			return(fl_sts);
		}
		/// swap window
		GLint Swap(void)
		{
			wl_display_dispatch_pending(data.display);
			return true;
		}
		EGLNativeWindowType GetNativeWindow()
		{
			return data.eglNativeWindow;
		}
		EGLNativeDisplayType GetNativeDisplay()
		{
			return data.eglNativeDisplay;
		}
	};
}
rc_application_window::rc_application_window()
{
	if (gfx3d_scg_project::GetProjGlesConfig() != GLES3_RENDERER)
	{
		ELOG("Build option mismatch GLES3_RENDERER\n");
		WLOG("Library build option & application build mismatch GLES3_RENDERER (lib=%d,app=%d)\n", gfx3d_scg_project::GetProjGlesConfig(), GLES3_RENDERER);
	}
	if (gfx3d_scg_project::GetProjMthreadsConfig() != RC_MTHREADS)
	{
		ELOG("Build option mismatch RC_MTHREADS\n");
		WLOG("Library build option & application build mismatch RC_MTHREADS (lib=%d,app=%d)\n", gfx3d_scg_project::GetProjMthreadsConfig(), RC_MTHREADS);
	}
}
rc_application_window::~rc_application_window()
{
	delete handle;
}
void rc_application_window::releaseNativeWindow(void)
{
	if (handle != nullptr)
	{
		//TODO
	}
}
bool rc_application_window::createNativeWindow(void)
{
	bool fl_sts;
	if (handle != nullptr)
	{
		if (handle->Open())
		{
			fl_sts = true;
		}
		else
		{
			fl_sts = false;
		}
	}
	else
	{
		fl_sts = false;
	}
	return(fl_sts);
}
EGLNativeWindowType rc_application_window::GetNativeWindow() const
{
	EGLNativeWindowType fl_nativeWindow;
	if (handle != nullptr)
	{
		fl_nativeWindow = handle->GetNativeWindow();
	}
	else
	{
		fl_nativeWindow = static_cast<EGLNativeWindowType>(nullptr);
	}
	return(fl_nativeWindow);
}
EGLNativeDisplayType rc_application_window::GetDeviceContext() const
{
	EGLNativeDisplayType fl_nativeDisplay;
	if (handle != nullptr)
	{
		fl_nativeDisplay = handle->GetNativeDisplay();
	}
	else
	{
		fl_nativeDisplay = static_cast<EGLNativeDisplayType>(EGL_DEFAULT_DISPLAY);
	}
	return(fl_nativeDisplay);
}
bool rc_application_window::Open(rc_generic_ws* p_parent)
{
    handle = new rc_win_handles(p_parent);
	if (p_parent != nullptr)
    {
       	display = p_parent->GetParent();
	}
    return true;
}
bool rc_application_window::Close(void)
{
	// TODO
	return(false);
}
bool rc_application_window::Swap(const bool p_changed)
{
	if (handle != nullptr)
	{
		//printf("Swap Happens \n");
		handle->Swap();
	}
#if defined(RCIMGUI_ENABLE)
    rc_imgui::Render(display);
    (void)p_changed;
    return true; //always swap buffer as drawn with imgui 
#else
	return(p_changed);
#endif	
}
bool rc_application_window::FrameEnd()
{
	return true;
}
EGLDisplay rc_application_window::GetPlatformDisplay() const
{
	return(EGL_NO_DISPLAY);
}
EGLint rc_application_window::GetPlatformVisualID() const
{
	return(static_cast<EGLint>(EGL_DONT_CARE));
}
#endif

