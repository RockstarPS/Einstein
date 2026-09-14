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

#define eglConstructFJ() EGL_TRUE
#define eglGetDisplay(a) 1
#define eglInitialize(a, b, c)
#define eglChooseConfig(a, b, c, d, e) *e= 1
#define eglBindAPI(a)
#define eglCreateContext(a, b, c, d) 1
#define eglCreateWindowSurface(a, b, c, d) 1
#define RegWrite4(a, b)
#define eglMakeCurrent(a, b, c, d)

#define eglTerminate(a)
#define eglReleaseThread()
#define eglDestructFJ(a) 1
#define eglGetError() 1

int eglSwapBuffers(int a, int b);


#endif

