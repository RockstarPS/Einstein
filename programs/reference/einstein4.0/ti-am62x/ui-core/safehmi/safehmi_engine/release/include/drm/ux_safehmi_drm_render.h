// ============================================================================
//
//                      CONFIDENTIAL VISTEON CORPORATION
//
//  This is an unpublished work of authorship, which contains trade secrets,
//  created in 2017. Visteon Corporation owns all rights to this work and
//  intends to maintain it in confidence to preserve its trade secret status.
//  Visteon Corporation reserves the right, under the copyright laws of the
//  United States or those of any other country that may have jurisdiction,
//  to protect this work as an unpublished work, in the event of an
//  inadvertent or deliberate unauthorized publication. Visteon Corporation
//  also reserves its rights under all copyright laws to protect this work as
//  a published work, when appropriate. Those having access to this work may
//  not copy it, use it, modify it or disclose the information contained in
//  it without the written authorization of Visteon Corporation.
//
// ============================================================================
//
//  Name:           ux_safehmi_drm_render.h
//
//  Description:    QNX screen api based renderer for the safehmi player
//
//  Organization:   GUI Software Section, Visteon
//
// ============================================================================
//
// ============================================================================
#ifndef UX_SAFEHMI_DRM_RENDER_H
#define UX_SAFEHMI_DRM_RENDER_H

// ============================================================================
//  I N C L U D E   F I L E S
// ============================================================================
#include <drm/drm_fourcc.h>
#include <fcntl.h>
#include <unistd.h>
#include <xf86drm.h>
#include <xf86drmMode.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <cstring>
#include "ux_safehmi_types.h"
#include "ux_safehmi_renderer.h"

#if defined(TRACE_DEBUG)
#include "PVRScopeComms.h"
#endif

#ifdef SHMI_SHARED_FD
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/stat.h>
#include <pthread.h>

#define SOCKET_PATH "/tmp/drm_socket"
#define SHARED_MEM_NAME "/drm_shared_mutex"
#endif
// ============================================================================
//  T Y P E   D E F I N I T I O N S
// ============================================================================

// ============================================================================
//  E N T R Y   P O I N T S
// ============================================================================
namespace UX_SHMI_PLAYER
{
  typedef struct {
    char property_name[50];
    uint64_t property_value;
  }drm_property;
  /// <summary>
  /// Implements a renderer based on only Linux DRM APIs.
  /// </summary>
  class ux_safehmi_drm_render : public ux_safehmi_renderer
  {
  private:
    int32_t drm_fd;
    int32_t crtc_id;
    drm_mode_map_dumb map_dumb = {0};
    drmModeRes *resources;
    drmModePlaneRes *plane_res;
    drmModePlane *drmPlane;
    drmModeCrtc *crtc;
    drmModeConnector *connector;
    drmModeModeInfo *mode;
    drm_mode_create_dumb create_dumb[2];
    drm_mode_fb_cmd2 fb_cmd = {0};
    uint32_t fb_id[2];
    void *frame_buff_ptr[2];
    uint8_t fb_index;
    uint32_t shmi_plane_id;
    /// <summary>
    /// Holds the value of screen stride - Number of pixels for each row
    /// </summary>
    int32_t screen_stride;
    /// <summary>
    /// Size of the screen buffer(width/height)
    /// </summary>
    int32_t screen_size[2];
    /// <summary>
    /// Display x position
    /// </summary>
    int32_t window_xpos;
    /// <summary>
    /// Display y position
    /// </summary>
    int32_t window_ypos;
    /// <summary>
    /// Display width
    /// </summary>
    int32_t window_width;
    /// <summary>
    /// Display height
    /// </summary>
    int32_t window_height;
    /// <summary>
    /// pointer to hold the display buffer
    /// </summary>
    void *screen_buff_pointer;
#ifdef SHMI_SHARED_FD
    int32_t listen_socket;
    int32_t client_socket;
    pthread_mutex_t *mutex;
    bool share_fd;
#endif
#ifdef DRM_ATOMIC
    drmModeAtomicReq *drm_atomic_req;
    uint32_t fb_property_id;
#endif
#if defined(SHMI_DEBUG)
    struct timespec start;
    struct timespec stop;
    float64_t stime;
    float64_t etime;
#endif
  public:
    /// <summary>
    /// safehmi renderer constructor. Initialize the member variables with default values
    /// </summary>
    ux_safehmi_drm_render(void);
    /// <summary>
    /// safehmi renderer destructor. Dispose the qnx screen variables
    /// </summary>
    ~ux_safehmi_drm_render(void);

    /// <summary>
    /// safehmi renderer initialization function - creates window for the safehmi renderer where the updates
    /// are rendered. Returns 0 if initialization is success else returns non zero
    /// </summary>
    virtual int32_t RenderInit(ux_safehmi_context const &p_ctx, const shmi_qnx_disp_info &p_disp_info) override;
    /// <summary>
    /// Wait V-Sync
    /// </summary>
    void WaitVSync(void) const;

  private:
    void CleanupDRMHandle(void);
    /// <summary>
    /// Fills the rectangle area(p_x, p_y, p_w, p_h) with the specified color(p_colorARGB) in the screen buffer
    /// </summary>
    void cpuFillRect(const int32_t p_x, const int32_t p_y, const int32_t p_w, const int32_t p_h, const uint32_t p_colorARGB) const;
    /// <summary>
    /// Copies the src pixels into the screen buffer
    /// </summary>
    void cpuCopyImage(const int32_t p_x, const int32_t p_y, const int32_t p_w, const int32_t p_h, const int32_t p_stride, uint32_t const *const p_srcpixels);

  protected:
    /// <summary>
    /// This is invoked by the safehmi player before the renderpass is started. So here, the current screen back buffer
    /// pointer is read to allow all the rendering to be directed to the backbuffer. Also the screen is filled with
    /// a black BG color.
    /// </summary>
    virtual void RenderStart(void) override;
    /// <summary>
    /// This is invoked by the safehmi player after the renderpass is completed. So here, the prepared backbuffer
    /// swapped to form the front buffer. Also fps and render time debug informations are calculated and
    /// printed to console.
    /// </summary>
    virtual void RenderEnd(void) override;
    /// <summary>
    /// This is invoked by the safehmi player to render a Image element during the renderpass
    /// </summary>
    virtual void RenderImage(ux_safehmi_image const *const p_elem, ux_safehmi_context &p_ctx) override;
    /// <summary>
    /// This is invoked by the safehmi player to render a filled rectangle element during the renderpass
    /// </summary>
    virtual void RenderRectangle(ux_safehmi_rectangle const *const p_elem, const ux_safehmi_context &p_ctx) override;
    /// <summary>
    /// This is invoked by the safehmi player to render canvas element during the renderpass.
    /// </summary>
    virtual void RenderCanvas(ux_safehmi_canvas const *const p_elem, const ux_safehmi_context &p_ctx) override;
  };

  // ============================================================================
  //  D A T A   A C C E S S   S E R V I C E S
  // ============================================================================

}
// ============================================================================
//
// ============================================================================
//  C M S    R E V I S I O N    N O T E S
// ============================================================================
//
//  For each change to this file, be sure to record:
//  1.  Who made the change and when the change was made.
//  2.  Why the change was made and the intended result.
//
//  CMS Rev #        Date         By
//  CMS Rev X.X      mm/dd/yy     CDSID
//
// ============================================================================
//
//  CMS Rev 1.0      20-Jun-2020  arajase2
//  Source code is leveraged from QMLPlayer. QMLPlayer RTC baseline - ss-UI-CORE-EARLY-HMI-1.3.1
//
// ============================================================================

// end of file ================================================================
#endif
