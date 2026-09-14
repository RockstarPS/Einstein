#include "egl\egl.h"
#include "vg\openvg.h"
#include "vg\vgext.h"
#include <stdlib.h>
#include <malloc.h>
#include "hmi_gfx_mgr02_layout.h"

#define MAX_EGL_SURFACES   (20*2)

#ifndef MAX_EGL_SURFACE_WIDTH
#ifdef GFX_MGR02_LAYERS_MAX_WIDTH
#define MAX_EGL_SURFACE_WIDTH   (GFX_MGR02_LAYERS_MAX_WIDTH)
#else
#define MAX_EGL_SURFACE_WIDTH   (800)
#endif
#endif

#ifndef MAX_EGL_SURFACE_HEIGHT
#ifdef GFX_MGR02_LAYERS_MAX_HEIGHT
#define MAX_EGL_SURFACE_HEIGHT  (GFX_MGR02_LAYERS_MAX_HEIGHT)
#else
#define MAX_EGL_SURFACE_HEIGHT  (480)
#endif
#endif


EGLSURFACE egl_surfaces[MAX_EGL_SURFACES];
EGLCONFIG  egl_config;
EGLCONTEXT egl_contexts[MAX_EGL_SURFACES];
EGLCONTEXT * l_current_context;

int max_width;
int max_height;
int vg_am_init=0;

#define ARGB8888TORGB565(p)   ((((unsigned short)(((unsigned char)p[2])>>3))<<11) | \
							   (((unsigned short)(((unsigned char)p[1])>>2))<< 5) | \
							   (((unsigned short)(((unsigned char)p[0])>>3))<< 0))

#define ARGB8888TOARGB4444(p) ((((unsigned short)(((unsigned char)p[0])>>4))<<12) | \
							   (((unsigned short)(((unsigned char)p[1])>>4))<< 8) | \
							   (((unsigned short)(((unsigned char)p[2])>>4))<< 4) | \
							   (((unsigned short)(((unsigned char)p[3])>>3))<< 0))

#define ARGB8888TOARGB1555(p) ((((unsigned short)(((unsigned char)p[0])>>7))<<15) | \
							   (((unsigned short)(((unsigned char)p[1])>>3))<<10) | \
							   (((unsigned short)(((unsigned char)p[2])>>3))<< 5) | \
							   (((unsigned short)(((unsigned char)p[3])>>3))<< 0))

/*
** VG buffer is always in ARGB888, apply conversion to match the
** EGL context buffer pixel format is not done, so for win32
** the EGL buffer also has to be ARGB8888
*/
void eglCopyVGtoSurface(void)
{
   if((l_current_context != 0) && (vg_am_init != 0))
   {
      EGLSURFACE * surf = l_current_context->surf;
      if(surf != 0)
      {
         if(surf->pbuff && surf->width && surf->height)
         {
            unsigned * pbuff = (unsigned *)vgGetSurfacePixelsAM();
			int height = MAX_EGL_SURFACE_HEIGHT;
			int width  = MAX_EGL_SURFACE_WIDTH;

            switch(surf->pix_format)
			{
               case VG_lARGB_8888:
               { 
                  unsigned char * dest = (unsigned char *)surf->pbuff;
                  unsigned char * p_buff;
                  unsigned        twidth;
                  unsigned        theight = surf->height;

			      while(theight)
                  {
                     theight--;
			         height--;

                     twidth = surf->width;
                     p_buff = (unsigned char *)(&pbuff[height*width]);
                  #ifdef GFX_MGR02_VG_MIRROR_OUTPUT
					 dest   = &((unsigned char *)surf->pbuff)[theight*twidth*4];
                  #endif 

			         while(twidth)
                     {
                        twidth--;
                        dest[0] = p_buff[3];
                        dest[1] = p_buff[2];
                        dest[2] = p_buff[1];
                        dest[3] = p_buff[0];
                        dest   +=4;
                        p_buff +=4;
                     }
 		          }
			   }
			   break;

               case VG_sRGB_565:
			   case VG_sARGB_1555:
			   case VG_sARGB_4444:
			   {
                  unsigned short * dest = (unsigned short *)surf->pbuff;
                  unsigned char  * p_buff;
                  unsigned         twidth;
                  unsigned         theight = surf->height;

			      while(theight)
                  {
                     theight--;
			         height--;

                     twidth = surf->width;
                     p_buff = (unsigned char *)(&pbuff[height*width]);
                  #ifdef GFX_MGR02_VG_MIRROR_OUTPUT
					 dest   = &((unsigned short *)surf->pbuff)[theight*twidth];
                  #endif 
			         while(twidth)
                     {
                        twidth--;
						if(surf->pix_format == VG_sRGB_565)
						{ 
						   dest[0] = ARGB8888TORGB565(p_buff); 
						}
						else if(surf->pix_format == VG_sARGB_1555)
						{ 
						   dest[0] = ARGB8888TOARGB1555(p_buff); 
						}
						else if(surf->pix_format == VG_sARGB_4444)
						{ 
						   dest[0] = ARGB8888TOARGB4444(p_buff); 
						}
						else
						{
						}
                        dest++;
                        p_buff +=4;
                     }
 		          }
			   }
			   break;
			}
         }
      }
   }
   vgPostSwapBuffersAM();
}

EGLint eglGetError(void)
{
   return(0);
}

EGLDisplay eglGetDisplay(EGLNativeDisplayType display_id)
{
   return(3);
   /* return(0); */
}

EGLBoolean eglInitialize(EGLDisplay dpy, EGLint * major,    EGLint * minor)
{
   int i;
   for(i=0; i < MAX_EGL_SURFACES; i++)
   {
      egl_surfaces[i].width      = 0;
      egl_surfaces[i].height     = 0;
      egl_surfaces[i].pbuff      = 0;
      egl_surfaces[i].pix_format = 0;
      egl_surfaces[i].id         = -1;
      egl_contexts[i].surf       = 0;
      egl_contexts[i].conf       = 0;
   }
   l_current_context = 0;
   max_width  = 0;
   max_height = 0;
   vg_am_init = vgInitContextAM(MAX_EGL_SURFACE_WIDTH, MAX_EGL_SURFACE_HEIGHT, VG_FALSE);
   return(EGL_TRUE);
}

EGLSURFACE * eglgetsurface(void)
{
   int i;
   for(i=0; i < MAX_EGL_SURFACES; i++)
   {
      if(egl_surfaces[i].id == -1)
      {
         egl_surfaces[i].id = i;
         return(&egl_surfaces[i]);
      }
   }
   return(EGL_NO_SURFACE);
}

EGLBoolean eglTerminate(EGLDisplay dpy)
{
   return(EGL_TRUE);
}

void eglReleaseAll(void)
{
}

const char * eglQueryString(EGLDisplay dpy, EGLint name)
{
   return(0);
}

EGLBoolean eglGetConfigs(EGLDisplay dpy,    EGLConfig * configs, EGLint config_size, EGLint * num_config)
{
  return EGL_TRUE;
}

EGLBoolean eglChooseConfig(EGLDisplay     dpy,
                           const EGLint * attrib_list,
                           EGLConfig    * configs,
                           EGLint         config_size,
                           EGLint       * num_config)
{
   int rbits = 0;
   int gbits = 0;
   int bbits = 0;
   int abits = 0;
   *configs  = 0;
   while(*attrib_list != EGL_NONE)
   {
      switch(*attrib_list)
      {
         case EGL_RED_SIZE:   rbits = attrib_list[1];break;
         case EGL_GREEN_SIZE: gbits = attrib_list[1];break;
         case EGL_BLUE_SIZE:  bbits = attrib_list[1];break;
         case EGL_ALPHA_SIZE: abits = attrib_list[1];break;
      }
      attrib_list++;
      attrib_list++;
   }
   if(rbits == 5 && gbits == 6 && bbits == 5 && abits == 0)
   {
      egl_config.pix_format = VG_sRGB_565;
      *configs = &egl_config;
   }
   else if(rbits == 5 && gbits == 5 && bbits == 5 && abits == 1)
   {
      egl_config.pix_format = VG_sARGB_1555;
      *configs = &egl_config;
   }
   else if(rbits == 4 && gbits == 4 && bbits == 4 && abits == 4)
   {
      egl_config.pix_format = VG_sARGB_4444;
      *configs = &egl_config;
   }
   else if(rbits == 8 && gbits == 8 && bbits == 8 && abits == 8)
   {
      egl_config.pix_format = VG_lARGB_8888;
      *configs = &egl_config;
   }
   return EGL_TRUE;
}

EGLBoolean eglGetConfigAttrib(EGLDisplay  dpy,
                              EGLConfig   config,
                              EGLint      attribute,
                              EGLint    * value)
{
  return EGL_TRUE;
}

EGLSurface eglCreateWindowSurface(EGLDisplay           dpy,
                                  EGLConfig            config,
                                  EGLNativeWindowType  win,
                                  const EGLint       * attrib_list)
{
  return 0;
}

EGLSurface eglCreatePbufferSurface(EGLDisplay     dpy,
                                   EGLConfig      config,
                                   const EGLint * attrib_list)
{
   int width;
   int height;
   EGLSURFACE * surface = EGL_NO_SURFACE;

   while(*attrib_list != EGL_NONE)
   {
      switch(*attrib_list)
      {
         case EGL_WIDTH:  width = attrib_list[1];break;
         case EGL_HEIGHT: height = attrib_list[1];break;
      }
      attrib_list++;
      attrib_list++;
   }
   if(width != 0 && height != 0 && config != 0)
   {
      surface = eglgetsurface();
      if(surface != EGL_NO_SURFACE)
      {
         surface->width      = width;
         surface->height     = height;
         surface->pbuff      = calloc(width*height, sizeof(unsigned));
         surface->pix_format = ((EGLCONFIG *)config)->pix_format;
      }
   }
   return surface;
}

EGLSurface eglCreatePixmapSurface(EGLDisplay          dpy,
                                  EGLConfig           config,
                                  EGLNativePixmapType pixmap,
                                  const EGLint *      attrib_list)
{
  return 0;
}

EGLBoolean eglDestroySurface(EGLDisplay dpy, EGLSurface surface)
{
   EGLSURFACE * fsurface = surface;
   if(fsurface != EGL_NO_SURFACE)
   {
      free(fsurface->pbuff);
      fsurface->width      = 0;
      fsurface->height     = 0;
      fsurface->pbuff      = 0;
      fsurface->id         = -1;
   }
   return EGL_TRUE;
}

EGLBoolean eglQuerySurface(EGLDisplay dpy,
                           EGLSurface surface,
                           EGLint     attribute,
                           EGLint   * value)
{
  return EGL_TRUE;
}

EGLBoolean eglBindAPI(EGLenum api)
{
  return EGL_TRUE;
}

EGLenum eglQueryAPI(void)
{
   return(0);
}

EGLBoolean eglWaitClient(void)
{
  return EGL_TRUE;
}

EGLBoolean eglReleaseThread(void)
{
  return EGL_TRUE;
}

EGLSurface eglCreatePbufferFromClientBuffer(EGLDisplay       dpy,
                                            EGLenum         buftype,
                                            EGLClientBuffer buffer,
                                            EGLConfig       config,
                                            const EGLint  * attrib_list)
{
   return(0);
}

EGLBoolean eglSurfaceAttrib(EGLDisplay dpy,
                            EGLSurface surface,
                            EGLint     attribute,
                            EGLint     value)
{
  return EGL_TRUE;
}

EGLBoolean eglBindTexImage(EGLDisplay dpy,
                           EGLSurface surface,
                           EGLint buffer)
{
  return EGL_TRUE;
}

EGLBoolean eglReleaseTexImage(EGLDisplay dpy,
                              EGLSurface surface,
                              EGLint buffer)
{
  return EGL_TRUE;
}

EGLBoolean eglSwapInterval(EGLDisplay dpy,
                           EGLint interval)
{
  return EGL_TRUE;
}

EGLContext eglCreateContext(EGLDisplay dpy,
                            EGLConfig config,
                            EGLContext share_context,
                            const EGLint * attrib_list)
{
   EGLContext ctx = 0;
   int i;
   for(i=0; i < MAX_EGL_SURFACES;i++)
   {
      if(egl_contexts[i].conf == 0)
      {
         egl_contexts[i].conf = config;
         ctx = &egl_contexts[i];
         break;
      }
   }
   return(ctx);
}

EGLBoolean eglDestroyContext(EGLDisplay dpy,
                             EGLContext ctx)
{
  EGLCONTEXT * context = ctx;
  if(context != 0)
  {
     context->surf = 0;
     context->conf = 0;
     if(l_current_context == context)
     {
        l_current_context = 0;
     }
  }
  return EGL_TRUE;
}

EGLBoolean eglMakeCurrent(EGLDisplay dpy,
                          EGLSurface draw,
                          EGLSurface read,
                          EGLContext ctx)
{
   EGLCONTEXT * context = ctx;
   if(ctx != 0)
   {
      context->surf = draw;
      l_current_context = context;
      if(context->surf->width > MAX_EGL_SURFACE_WIDTH)
	  {
		 printf("Surface width is  > MAX_EGL_SURFACE_WIDTH.\n");
	  }
      if(context->surf->height > MAX_EGL_SURFACE_HEIGHT)
	  {
		 printf("Surface width is  > MAX_EGL_SURFACE_HEIGHT\n");
	  }
   }
   return EGL_TRUE;
}

EGLContext eglGetCurrentContext(void)
{
   return(0);
}

EGLSurface eglGetCurrentSurface(EGLint readdraw)
{
   return(0);
}

EGLDisplay eglGetCurrentDisplay(void)
{
   return(0);
}

EGLBoolean eglQueryContext(EGLDisplay dpy,
                           EGLContext ctx,
                           EGLint attribute,
                           EGLint * value)
{
  return EGL_TRUE;
}

EGLBoolean eglWaitGL(void)
{
  return EGL_TRUE;
}

EGLBoolean eglWaitNative(EGLint engine)
{
  return EGL_TRUE;
}

EGLBoolean eglSwapBuffers(EGLDisplay dpy,
                          EGLSurface surface)
{
  return EGL_TRUE;
}

EGLBoolean eglCopyBuffers(EGLDisplay          dpy,
                          EGLSurface          surface,
                          EGLNativePixmapType target)
{
  return EGL_TRUE;
}

