#ifndef EGL_H_
#define EGL_H_

#define EGL_NO_DISPLAY 0
#define EGL_NO_SURFACE 0
#define EGL_FALSE 0
#define EGL_TRUE 1
#define EGL_NO_CONTEXT 0

#define EGL_DRAW_AREA_START_POINT_X_FJ 0
#define EGL_DRAW_AREA_START_POINT_Y_FJ 1
#define EGL_WIDTH 2
#define EGL_HEIGHT 3
#define EGL_NONE -1

#define EGL_RED_SIZE 0
#define EGL_GREEN_SIZE 0
#define EGL_BLUE_SIZE 0
#define EGL_DEPTH_SIZE 0
#define EGL_SAMPLES 0
#define EGL_SURFACE_TYPE 0
#define EGL_WINDOW_BIT 0
#define EGL_SUCCESS 1


typedef int EGLDisplay;
typedef int EGLSurface;
typedef int EGLint;
typedef int EGLConfig;
typedef int EGLContext;
typedef int EGLenum;
typedef unsigned int EGLBoolean;
typedef int EGLNativeDisplayType;
typedef int EGLNativeWindowType;
#define eglConstructFJ() EGL_TRUE
int eglGetDisplay(EGLNativeDisplayType display_id);
//#define eglInitialize(a, b, c)
//#define eglChooseConfig(a, b, c, d, e) *e= 1
#define eglBindAPI(a)

int eglCreateContext (EGLDisplay dpy, EGLConfig config, EGLContext share_context, const EGLint *attrib_list);
int eglCreateWindowSurface (EGLDisplay dpy, EGLConfig config, EGLNativeWindowType win, const EGLint *attrib_list);
#define RegWrite4(a, b)
//#define eglMakeCurrent(a, b, c, d)

#define eglTerminate(a)
#define eglReleaseThread()
#define eglDestructFJ(a) 1
#define eglGetError() 1
#define EGL_ALPHA_SIZE 0x3021
#define EGL_RENDERABLE_TYPE 0x3040
#define EGL_OPENGL_ES2_BIT 0x0004
#define EGL_CONTEXT_CLIENT_VERSION  0x3098
EGLBoolean eglDestroySurface(EGLDisplay dpy, EGLSurface surface);
EGLBoolean eglDestroyContext(EGLDisplay dpy, EGLContext ctx);
EGLBoolean eglInitialize(EGLDisplay dpy, EGLint *major, EGLint *minor);
EGLBoolean eglMakeCurrent(EGLDisplay dpy, EGLSurface draw, EGLSurface read, EGLContext ctx);

EGLBoolean eglChooseConfig(EGLDisplay display,const EGLint *attrib_list,EGLConfig *configs,EGLint config_size,EGLint *num_config);


int eglSwapBuffers(int a, int b);


#endif

