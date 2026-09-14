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
//  Description : Platform specific window handling for DRM
//  Created on  : 20-Feb-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef WIN32

#include "gfx3d_scg.h"
#include "rc_application_window.h"
//#include "rc_shared_mutex.h"
#include <EGL/egl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sys/time.h>
#include <unistd.h>
#include <drm/drm_fourcc.h>
#include <xf86drm.h>
#include <xf86drmMode.h>
#include <gbm.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/un.h>
#if defined(RCIMGUI_ENABLE)
#include "rc_imgui.h"
#endif

//#define SOCKET_PATH "/tmp/drm_socket"

#ifdef USE_OVLY_PLANE
#define PLANE_ID 41
#else
#define PLANE_ID 31
#endif 
#define CRTC_ID 38


using namespace rendercore_engine;
namespace
{
	struct drm_fb
	{
		struct gbm_bo* bo;
		uint32_t fb_id;
	};
	extern "C"
	{
		__attribute__((weak)) uint64_t gbm_bo_get_modifier(struct gbm_bo* bo);
		__attribute__((weak)) int gbm_bo_get_plane_count(struct gbm_bo* bo);
		__attribute__((weak)) uint32_t gbm_bo_get_stride_for_plane(struct gbm_bo* bo, int plane);
		__attribute__((weak)) uint32_t gbm_bo_get_offset(struct gbm_bo* bo, int plane);
		__attribute__((weak)) struct gbm_surface* gbm_surface_create_with_modifiers(
				struct gbm_device* gbm,
				uint32_t width, uint32_t height,
				uint32_t format,
				const uint64_t* modifiers,
				const unsigned int count);
		void drm_fb_destroy_callback(struct gbm_bo* p_bo, void* p_data)
		{
			if (p_data != nullptr)
			{
				struct drm_fb* fl_fb = (struct drm_fb*)p_data;
				if (fl_fb->fb_id)
				{
					int drm_fd = gbm_device_get_fd(gbm_bo_get_device(p_bo));
					drmModeRmFB(drm_fd, fl_fb->fb_id);
				}
				free(fl_fb);
			}
		}
		struct gbm_surface* get_surface_with_modifiers(
			struct gbm_device* dev,
			uint32_t width, uint32_t height,
			uint32_t format,
			const uint64_t* modifiers,
			const unsigned int count)
		{
			struct gbm_surface* fl_surfece;
			if (gbm_surface_create_with_modifiers != nullptr)
			{
				fl_surfece = gbm_surface_create_with_modifiers(
					dev,
					width,
					height,
					format,
					modifiers,
					count);
			}
			else
			{
				fl_surfece = nullptr;
			}
			return(fl_surfece);
		}
		drm_fb* get_fb_from_bo(struct gbm_bo* bo)
		{
			struct drm_fb* fl_fb = (struct drm_fb*)gbm_bo_get_user_data(bo);
			if (fl_fb == nullptr)
			{
				uint32_t width;
				uint32_t height;
				uint32_t format;
				uint32_t strides[4] = { 0 };
				uint32_t handles[4] = { 0 };
				uint32_t offsets[4] = { 0 };
				uint32_t flags = 0;
				int ret = -1;
				int fl_drm_fd = gbm_device_get_fd(gbm_bo_get_device(bo));

				fl_fb = (struct drm_fb*)calloc(1, sizeof * fl_fb);
				fl_fb->bo = bo;
				width = gbm_bo_get_width(bo);
				height = gbm_bo_get_height(bo);
				format = gbm_bo_get_format(bo);


				if (gbm_bo_get_modifier && gbm_bo_get_plane_count &&
					gbm_bo_get_stride_for_plane && gbm_bo_get_offset)
				{
					uint64_t modifiers[4] = { 0 };
					modifiers[0] = gbm_bo_get_modifier(bo);
					int num_planes = gbm_bo_get_plane_count(bo);
					if (num_planes > 4)
					{
						ILOG("gbm_bo_get_plane_count %d > 4\n", num_planes);
						num_planes = 4;
					}
					for (int i = 0; i < num_planes; i++)
					{
						strides[i] = gbm_bo_get_stride_for_plane(bo, i);
						handles[i] = gbm_bo_get_handle(bo).u32;
						offsets[i] = gbm_bo_get_offset(bo, i);
						modifiers[i] = modifiers[0];
					}
					if (modifiers[0])
					{
						flags = DRM_MODE_FB_MODIFIERS;
						ILOG("Using modifier %lu\n", modifiers[0]);
					}
					ret = drmModeAddFB2WithModifiers(fl_drm_fd, width, height,
						format, handles, strides, offsets,
						modifiers, &fl_fb->fb_id, flags);
				}
				if (ret)
				{
					if (flags)
					{
						ILOG("Modifiers failed!\n");
					}
					uint32_t fl_array[4] =
					{
						gbm_bo_get_handle(bo).u32, 0, 0, 0
					};
					memcpy(handles, (const void*)&fl_array, sizeof(handles));
					fl_array[0] = gbm_bo_get_stride(bo);
					memcpy(strides, (const void*)&fl_array, sizeof(strides));
					memset(offsets, 0, sizeof(offsets));
					ret = drmModeAddFB2(
						fl_drm_fd,
						width,
						height,
						format,
						handles,
						strides,
						offsets,
						&fl_fb->fb_id, 0);
				}
				if (ret)
				{
					ILOG("failed to create fb: %s\n", strerror(errno));
					free(fl_fb);
					fl_fb = nullptr;
				}
				else
				{
					gbm_bo_set_user_data(bo, fl_fb, drm_fb_destroy_callback);
					ILOG("Buffer created %d\n", fl_fb->fb_id);
				}
			}
			return fl_fb;
		}
	}
	const int maxFBs = 2; ///< Number of framebuffers to be used. Minimum - 2
	struct gbm_bo *current_bo = NULL;
    struct gbm_bo *previous_bo = NULL;
	int current_buffer = 0;
    int next_buffer = 1;
	bool firstframe = true;
	struct drmConnection
	{
		int fd = -1;
		drmModeModeInfo* mode = nullptr;
		uint32_t crtc_id = 0;
		int crtc_index = -1;
		uint32_t connector_id = 0;
		struct gbm_device* dev = nullptr;
		struct gbm_surface* surface = nullptr;
		struct gbm_bo* bo[maxFBs]{};
		drm_fb* fb[maxFBs]{};
		int fbindex = 0;
		fd_set fds;
	};
	drmConnection drm;
	drmEventContext evctx;
	void page_flip_handler(int p_fd, unsigned int p_frame, unsigned int p_sec, unsigned int p_usec, void* p_data)
	{
		// suppress 'unused parameter' warnings
		(void)p_fd, (void)p_frame, (void)p_sec, (void)p_usec;
		if (p_data != nullptr)
		{
			int* waiting_for_flip = (int*)p_data;
			*waiting_for_flip = 0;

		}
	}
	uint32_t find_crtc_for_encoder(const drmModeRes* p_resources, const drmModeEncoder* p_encoder)
	{
		uint32_t fl_crtc_id = -1;
		for (int i = 0; i < p_resources->count_crtcs; i++)
		{
			// possible_crtcs is a bitmask as described here:
			// https://dvdhrm.wordpress.com/2012/09/13/linux-drm-mode-setting-api
			const uint32_t fl_crtc_mask = (1U << static_cast<uint32_t>(i));
			if ((p_encoder->possible_crtcs & fl_crtc_mask) != 0U)
			{
				fl_crtc_id = p_resources->crtcs[i];
				break;
			}
		}
		return fl_crtc_id;
	}
	uint32_t find_crtc_for_connector(const drmConnection& p_drm, const drmModeRes* p_resources, const drmModeConnector* p_connector)
	{
		uint32_t fl_ret = -1;
		for (int i = 0; i < p_connector->count_encoders; i++)
		{
			const uint32_t fl_encoder_id = p_connector->encoders[i];
			drmModeEncoder* fl_encoder = drmModeGetEncoder(p_drm.fd, fl_encoder_id);
			if (fl_encoder != nullptr)
			{
				const uint32_t fl_crtc_id = find_crtc_for_encoder(p_resources, fl_encoder);
				drmModeFreeEncoder(fl_encoder);
				if (fl_crtc_id != 0)
				{
					fl_ret = fl_crtc_id;
					break;
				}
			}
		}
		return fl_ret;
	}
}
namespace rendercore_engine
{
	//int recv_fd(int socket_fd);  // Declare the function before usage
	//int socket_fd;

	// Get the shared memory mutex
	//pthread_mutex_t* mutex = setup_shared_mutex();
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
    }
	bool rc_application_window::Open(rc_generic_ws* p_parent)
	{
		if (p_parent != nullptr)
    	{
        	display = p_parent->GetParent();
		}
		return true;
	}
    void rc_application_window::releaseNativeWindow(void)
    {
    }
    bool rc_application_window::createNativeWindow(void)
	{
		/*struct sockaddr_un addr;
		// Create Unix domain socket
		if ((socket_fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
			printf("socket error\n");
			fflush(stdout);
			exit(-1);
		}
		memset(&addr, 0, sizeof(addr));
		addr.sun_family = AF_UNIX;
		strncpy(addr.sun_path, SOCKET_PATH, sizeof(addr.sun_path) - 1);
		
		// Connect to the server
		if (connect(socket_fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
			printf("connect error\n");
			fflush(stdout);
			close(socket_fd);
			exit(-1);
		}

		// Receive the DRM file descriptor from the server
		drm.fd = recv_fd(socket_fd);
		printf("Received DRM FD: %d\n", drm.fd);
		fflush(stdout);*/
		
		bool fl_sts;
		const char* device = "/dev/dri/card1";
		evctx.version = 2;
		evctx.page_flip_handler = &page_flip_handler;
		evctx.vblank_handler = nullptr;
		drm.fd = open(device, O_RDWR);

		if (drm.fd >= 0)
		{
			drmModeRes* fl_resources = drmModeGetResources(drm.fd);
			if (fl_resources != nullptr)
			{
				drmModeConnector* fl_connector = nullptr;
				// find a connected connector:
				for (int i = 0; i < fl_resources->count_connectors; i++)
				{
					// Retrieve connector information based on its index
					fl_connector = drmModeGetConnector(drm.fd, fl_resources->connectors[i]);
					if (!fl_connector)
					{
						// Skip if the connector cannot be retrieved
						continue;
					}
					// Check if the connector matches your updated setup and is connected
					 if ((fl_connector->connection == DRM_MODE_CONNECTED) && (fl_connector->connector_id == 40)) 
						 // Match the object ID of the updated connector
					{
						// It's the correct and connected connector, let's use this!
						break;
					}

					drmModeFreeConnector(fl_connector);
					fl_connector = nullptr;
				}
				if (fl_connector != nullptr)
				{
					int fl_area = 0;
					// find prefered mode or the highest resolution mode:
					for (int i = 0; i < fl_connector->count_modes; i++)
					{
						drmModeModeInfo* current_mode = &fl_connector->modes[i];

						if (current_mode->type & DRM_MODE_TYPE_PREFERRED)
						{
							drm.mode = current_mode;
							break;
						}
						int current_area = current_mode->hdisplay * current_mode->vdisplay;
						printf("\n Current mode received from Connector 1 is hdisplay %d, vdisplay %d\n", current_mode->hdisplay,
						current_mode->vdisplay);
						if (current_area > fl_area)
						{
							drm.mode = current_mode;
							fl_area = current_area;
						}
					}
					if (drm.mode != nullptr)
					{
						drmModeEncoder* encoder = nullptr;
						ILOG("DRM - Selected Mode %dx%d\n", drm.mode->hdisplay, drm.mode->vdisplay);
						// find encoder: 
						for (int i = 0; i < fl_resources->count_encoders; i++)
						{
							encoder = drmModeGetEncoder(drm.fd, fl_resources->encoders[i]);
							if (encoder->encoder_id == fl_connector->encoder_id)
							{
								break;
							}
							drmModeFreeEncoder(encoder);
							encoder = nullptr;
						}
						if (encoder != nullptr)
						{
							drm.crtc_id = encoder->crtc_id;
						}
						else
						{
							drm.crtc_id = find_crtc_for_connector(drm, fl_resources, fl_connector);
						}

						if (drm.crtc_id != 0)
						{
							for (int i = 0; i < fl_resources->count_crtcs; i++)
							{
								if (fl_resources->crtcs[i] == drm.crtc_id)
								{
									drm.crtc_index = i;
									break;
								}
							}
							drmModeFreeResources(fl_resources);
							drm.connector_id = fl_connector->connector_id;
							drm.dev = gbm_create_device(drm.fd);
							uint64_t modifier = DRM_FORMAT_MOD_LINEAR;
							ILOG("DRM - native visual id / format = %d\n", GBM_FORMAT_XRGB8888);
							drm.surface = get_surface_with_modifiers(drm.dev, drm.mode->hdisplay, drm.mode->vdisplay,
								GBM_FORMAT_XRGB8888,
								&modifier, 1U);
							if (drm.surface == nullptr)
							{
								drm.surface = gbm_surface_create(drm.dev, drm.mode->hdisplay, drm.mode->vdisplay, GBM_FORMAT_XRGB8888, GBM_BO_USE_SCANOUT | GBM_BO_USE_RENDERING);
							}
							if (drm.surface != nullptr)
							{
								ILOG("DRM - createNativeWindow Success\n");
								fl_sts = true;
							}
							else
							{
								ILOG("DRM - failed to create gbm surface\n");
								fl_sts = false;
							}
						}
						else
						{
							ILOG("DRM - no crtc found!\n");
							fl_sts = false;
						}

					}
					else
					{
						ILOG("DRM - could not find mode!\n");
						fl_sts = false;
					}
				}
				else
				{
					// we could be fancy and listen for hotplug events and wait for
					// a connector..
					ILOG("DRM - no connected connector!(device=%s)\n", device);
					fl_sts = false;
				}
			}
			else
			{
				ILOG("drmModeGetResources(device=%s) failed: '%s'\n", device, strerror(errno));
				fl_sts = false;
			}
			
		}
		else
		{
			ILOG("DRM - could not open drm device %s\n", device);
			fl_sts = false;
		}
		return(fl_sts);
    }
    EGLNativeWindowType rc_application_window::GetNativeWindow() const
    {
        return((EGLNativeWindowType)(drm.surface));
    }
    EGLNativeDisplayType rc_application_window::GetDeviceContext() const
    {
		return((EGLNativeDisplayType)drm.dev);
    }
	EGLDisplay rc_application_window::GetPlatformDisplay() const
	{
		EGLDisplay fl_display;
		PFNEGLGETPLATFORMDISPLAYEXTPROC fl_get_platform_display = reinterpret_cast<PFNEGLGETPLATFORMDISPLAYEXTPROC>(eglGetProcAddress("eglGetPlatformDisplayEXT"));
		if(fl_get_platform_display != nullptr)
		{
		   fl_display = fl_get_platform_display(EGL_PLATFORM_GBM_KHR, drm.dev, nullptr);
		}
		else
		{
			fl_display = EGL_NO_DISPLAY;
		}
		return(fl_display);
	}
    bool rc_application_window::Close(void)
    {
        // TODO to be handled
		//close(socket_fd);
		close(drm.fd);
        return(false);
    }
    bool rc_application_window::Swap(const bool p_changed)
    {
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
		bool fl_sts = true;
		if (maxFBs == 2)
		{
			drm.bo[current_buffer] = gbm_surface_lock_front_buffer(drm.surface);
			drm.fb[current_buffer] = get_fb_from_bo(drm.bo[current_buffer]);
			
			//printf("Current buffer index_during_acquire: %d\n", current_buffer);
			//printf("Buffer Object (drm.bo[current_buffer]_during_acquire): %p\n", drm.bo[current_buffer]);
			//printf("Framebuffer (drm.fb[current_buffer]_during_acquire): %p\n", drm.fb[current_buffer]);
			
			if (drm.fb[current_buffer] == nullptr)
			{
				fl_sts = false;
			}
			else
			{
				if(firstframe)
				{
					// Perform Lock Operation while accessing the Critical regions (drm.fd)
					//pthread_mutex_lock(mutex);
						if(drmSetMaster(drm.fd) == 0)
						{
							printf("\n drmSetMaster first frame before set CRTc from mainHMI Plane :31\n");
							fflush(stdout);
						}
						else
						{
							printf("\n Failed to setDRMMASTER in first frame before set CRTc  from mainHMI Error : %s\n", strerror(errno));
							fflush(stdout);
						}
						int ret = drmModeSetCrtc(drm.fd, drm.crtc_id, drm.fb[current_buffer]->fb_id, 0, 0, &drm.connector_id, 1, drm.mode);
						if (ret)
						{
							printf("failed to set mode: %s\n", strerror(errno));
							fflush(stdout);
							fl_sts = false;
						}
						else
						{
							printf("ModeSetCrtc set to 31\n");
							fflush(stdout);
						}
						uint32_t width = gbm_bo_get_width(drm.bo[current_buffer]);
						uint32_t height = gbm_bo_get_height(drm.bo[current_buffer]);
						ret = drmModeSetPlane(drm.fd, 31, drm.crtc_id, drm.fb[current_buffer]->fb_id, 0, 0, 0, width, height, 0, 0, width << 16, height << 16);
						if (ret)
						{
							printf("Failed to set plane 31\n");
							fflush(stdout);
						}
						else
						{
							printf("Plane set to 31\n");
							fflush(stdout);
						}
						if(drmDropMaster(drm.fd) == 0)
						{
							printf("\n drmDropMaster for mainHmi after setplane from plane 31 \n");
							fflush(stdout);
						}
						else
						{
							printf("\n Failed to drop DRM Master from mainHMIafter setplane Error : %s\n", strerror(errno));
							fflush(stdout);
						}
					// Perform UnLock Operation After accessing the Critical regions (drm.fd)
					//pthread_mutex_unlock(mutex);
					firstframe = false;
				}
				if (fl_sts)
				{
					volatile int waiting_for_flip = 1;
					// Perform Lock Operation while accessing the Critical regions (drm.fd)
					//pthread_mutex_lock(mutex);
						if(drmSetMaster(drm.fd) == 0)
						{
							//printf("\n drmSetMaster to do pageFlip in Plane :31 from MainHmi\n");
							fflush(stdout);
						}
						else
						{
							//printf("\n Failed to set DRMMASTER in PageFlip in plane 31 from mainHmi Error : %s\n", strerror(errno));
							fflush(stdout);
						}
						int ret = drmModePageFlip(drm.fd, drm.crtc_id, drm.fb[current_buffer]->fb_id, DRM_MODE_PAGE_FLIP_EVENT, (void*)&waiting_for_flip);
						if (ret)
						{
							//printf("failed to queue page flip from MainHMI: %s\n", strerror(errno));
							fflush(stdout);
							fl_sts = false;
						}
						else
						{
							//printf("\n PageFlip got success = %d", ret);
						}
						while ((waiting_for_flip) && fl_sts)
						{
							drmHandleEvent(drm.fd, &evctx);
						}
						if(drmDropMaster(drm.fd) == 0)
						{
							//printf("\n drmDropMaster for mainHmi after pageflip from plane 31 \n");
							fflush(stdout);
						}
						else
						{
							//printf("\n Failed to drop DRM Master after Pageflip mainHMI Error : %s\n", strerror(errno));
							fflush(stdout);
						}
						// Perform UnLock Operation After accessing the Critical regions (drm.fd)
					//pthread_mutex_unlock(mutex);
					if (previous_bo)
					{
						gbm_surface_release_buffer(drm.surface, previous_bo);
						//printf("previous_bo_After_pageflip_surface_release: %p\n", previous_bo);
						previous_bo = NULL;
					}
					previous_bo = drm.bo[current_buffer]; 
					//printf("previous_bo_after current_rendering_done: %p\n", previous_bo);
					// Toggle Buffer
					current_buffer = next_buffer - current_buffer;
				}
			}
		}	
		return (fl_sts);
	}
    EGLint rc_application_window::GetPlatformVisualID() const
    {
        return(static_cast<EGLint>(GBM_FORMAT_XRGB8888));
    }
	
	/*int recv_fd(int socket) 
	{
		struct msghdr msg = {0};
		struct iovec io;
		char buf[1];  // Buffer for the regular data
		char control[CMSG_SPACE(sizeof(int))];  // Buffer for the control message

		// Set up the io vector structure
		io.iov_base = buf;
		io.iov_len = sizeof(buf);

		// Prepare message structure
		msg.msg_iov = &io;
		msg.msg_iovlen = 1;
		msg.msg_control = control;
		msg.msg_controllen = sizeof(control);

		// Receive the message (which contains the file descriptor)
		if (recvmsg(socket, &msg, 0) == -1) 
		{
			printf("Failed to receive message\n");
			fflush(stdout);
			exit(1);
		}

		// Extract the file descriptor from the control message
		struct cmsghdr *cmsg = CMSG_FIRSTHDR(&msg);
		if (cmsg == NULL || cmsg->cmsg_len != CMSG_LEN(sizeof(int))) 
		{
			printf("No valid file descriptor received\n");
			fflush(stdout);
			exit(1);
		}

		if (cmsg->cmsg_level != SOL_SOCKET || cmsg->cmsg_type != SCM_RIGHTS) 
		{
			printf("Invalid control message level or type\n");
			fflush(stdout);
			exit(1);
		}

		int fd = *((int *) CMSG_DATA(cmsg));  // Extract the FD from the message
		return fd;
	}*/
}
#endif

