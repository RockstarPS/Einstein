///////////////////////////////////////////////////////////////////////////////
//
//                     CONFIDENTIAL VISTEON CORPORATION
//
// This is an unpublished work of authorship, which contains trade secrets,
// created in 2021. Visteon Corporation owns all rights to this work and
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
//  Filename    : rc_platform_dirtex.cpp
//  Description : Platform specific direct texture implementation.
//                Modify as per requirement
//  Created on  : 04-Jul-2022 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#include "gfx3d_scg.h"
#include "rc_platform_dirtex.h"
#include "rc_gles_vivextns.h"
#include <screen/screen.h>
#define EGL_EGLEXT_PROTOTYPES
#include <EGL/eglext.h>

namespace
{
    screen_context_t screen_ctx = nullptr;
}
namespace rendercore_engine
{
    struct rc_dt_handle
    {
        screen_pixmap_t native_pixmap = nullptr;
        screen_buffer_t screen_pbuf = nullptr;
        EGLImageKHR egl_img = nullptr;
    };
    MdlImgFormat_E RcGetDirectTextureFormat(const MdlImgFormat_E p_reqFormat)
    {
        return(MdlImgFormat_E::ifRgba);
    }
    GLenum RcGetDirectTextureTarget()
    {
        GLenum fl_target;
        if (rcSetupglTexDirectVIV())
        {
            fl_target = static_cast<GLenum>(GL_TEXTURE_2D);
        }
        else
        {
            fl_target = static_cast<GLenum>(GL_TEXTURE_EXTERNAL_OES);
        }
        return(fl_target);
    }
    bool RcCreateDirectTexture(rc_dir_texture& p_dtex)
    {
        UCHAR8* fl_rawbytes = nullptr;
        bool fl_sts;
        GLCALL(fl_sts = rcglTexDirectVIV(static_cast<GLenum>(GL_TEXTURE_2D), static_cast<GLsizei>(p_dtex.width), static_cast<GLsizei>(p_dtex.height), static_cast<GLenum>(GL_RGBA), reinterpret_cast<GLvoid**>(&fl_rawbytes)));
        if (fl_sts)
        {
            p_dtex.handle = nullptr;
            p_dtex.pixels = static_cast<UCHAR8*>(fl_rawbytes);
        }
        else
        {
            fl_sts = false;
            
            if (screen_ctx == nullptr)
            {
                if (screen_create_context(&screen_ctx, SCREEN_APPLICATION_CONTEXT) != 0)
                {
                    ILOG("screen_create_context failed\n");
                }
            }
            if (screen_ctx != nullptr)
            {
                rc_dt_handle fl_handle;
                if (screen_create_pixmap(&fl_handle.native_pixmap, screen_ctx) == 0)
                {
                    rc_dt_handle* const fl_handleptr = new rc_dt_handle;
                    int32_t fl_size[2] = { p_dtex.width, p_dtex.height };
                    int32_t fl_cont = 0;
                    int32_t fl_stride = 0;
                    int32_t fl_ret = screen_set_pixmap_property_iv(fl_handle.native_pixmap, SCREEN_PROPERTY_FORMAT, (const int[]) { SCREEN_FORMAT_RGBA8888 });
                    fl_ret += screen_set_pixmap_property_iv(fl_handle.native_pixmap, SCREEN_PROPERTY_USAGE, (const int[]) { SCREEN_USAGE_READ | SCREEN_USAGE_WRITE | SCREEN_USAGE_VIDEO  });
                    fl_ret += screen_set_pixmap_property_iv(fl_handle.native_pixmap, SCREEN_PROPERTY_BUFFER_SIZE, fl_size);
                    fl_ret += screen_create_pixmap_buffer(fl_handle.native_pixmap);
                    fl_ret += screen_get_pixmap_property_pv(fl_handle.native_pixmap, SCREEN_PROPERTY_RENDER_BUFFERS, (void**)&fl_handle.screen_pbuf);
                    fl_ret += screen_get_buffer_property_iv(fl_handle.screen_pbuf, SCREEN_PROPERTY_BUFFER_SIZE, fl_size);
                    fl_ret += screen_get_buffer_property_iv(fl_handle.screen_pbuf, SCREEN_PROPERTY_STRIDE, &fl_stride);
                    ILOG("SCREEN_PROPERTY_BUFFER_SIZE=%d x %d\n", fl_size[0], fl_size[1]);
                    if ((fl_ret == 0) && (fl_stride == p_dtex.stride ) && 
                        (fl_size[0] == p_dtex.width ) && (fl_size[1] == p_dtex.height ) &&
                        (screen_get_buffer_property_iv(fl_handle.screen_pbuf, SCREEN_PROPERTY_PHYSICALLY_CONTIGUOUS, &fl_cont) == 0))
                    {
                        ILOG("SCREEN_PROPERTY_PHYSICALLY_CONTIGUOUS=%d\n", fl_cont);
                        if (fl_cont != 0)
                        {
                            if (screen_get_buffer_property_iv(fl_handle.screen_pbuf, SCREEN_PROPERTY_STRIDE, &fl_stride) == 0)
                            {
                                ILOG("SCREEN_PROPERTY_STRIDE=%d\n", fl_stride);
                                if (screen_get_buffer_property_pv(fl_handle.screen_pbuf, SCREEN_PROPERTY_POINTER, (void**)&p_dtex.pixels) == 0)
                                {
                                    EGLint const eglImageAttributes[] = { EGL_IMAGE_PRESERVED_KHR, EGL_TRUE, EGL_NONE };
                                    fl_handle.egl_img = eglCreateImage(EGL_DEFAULT_DISPLAY, EGL_NO_CONTEXT, EGL_NATIVE_PIXMAP_KHR, (EGLClientBuffer)(fl_handle.native_pixmap), NULL);
                                    if (fl_handle.egl_img == EGL_NO_IMAGE_KHR)
                                    {
                                        ILOG("eglCreateImageKHR EGL Error\n");
                                    }
                                    else
                                    {
                                        glEGLImageTargetTexture2DOES(GL_TEXTURE_EXTERNAL_OES, fl_handle.egl_img);
                                        fl_sts = true;
                                    }
                                }
                            }
                        }
                    }
                    *fl_handleptr = fl_handle;
                    p_dtex.handle = fl_handleptr;
                }
                if (fl_sts == false)
                {
                    // cleanup
                    (void)RcDeleteDirectTexture(p_dtex);
                }
            }
        }
        return(fl_sts);
    }
    bool RcLockDirectTexture(rc_dir_texture& p_dtex)
    {
        (void)p_dtex;
        return(false);
    }
    bool RcInvalidateDirectTexture(rc_dir_texture& p_dtex)
    {
        (void)rcglTexDirectInvalidateVIV(static_cast<GLenum>(GL_TEXTURE_2D));
        (void)p_dtex;
        return(true);
    }
    bool RcDeleteDirectTexture(rc_dir_texture& p_dtex)
    {
        if (p_dtex.handle != nullptr)
        {
            glEGLImageTargetTexture2DOES(GL_TEXTURE_EXTERNAL_OES, EGL_NO_IMAGE_KHR);
            (void)eglDestroyImage(EGL_DEFAULT_DISPLAY, p_dtex.handle->egl_img);
            (void)screen_destroy_pixmap_buffer(p_dtex.handle->native_pixmap);
            (void)screen_destroy_pixmap(p_dtex.handle->native_pixmap);
            delete p_dtex.handle;
            p_dtex.handle = nullptr;
        }
        p_dtex.pixels = nullptr;
        return(true);
    }
}
