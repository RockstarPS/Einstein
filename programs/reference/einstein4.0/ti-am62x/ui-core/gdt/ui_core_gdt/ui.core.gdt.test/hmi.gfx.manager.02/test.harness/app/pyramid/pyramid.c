#include <GLES/egl.h>
#include <GLES/gl.h>

#include <stdio.h>
#include <signal.h>

#define PRECISION 16
#define ONE (1 << PRECISION)
#define ZERO 0

#define N_ELEMENTS(_array) \
    (sizeof(_array) / sizeof(_array[0]))

static inline GLfixed FixedFromInt (int value)
{
	return value << PRECISION;
}

static EGLDisplay dpy;
static EGLSurface surface;
static EGLContext context;
static void* sgaRenderingSurface;

static EGLBoolean running = EGL_TRUE;

static void
Initialize ()
{
	EGLint     major, minor;
	EGLConfig  configs[100];
	EGLint     configs_count;
	
	dpy = eglGetDisplay (EGL_DEFAULT_DISPLAY);

	if (eglInitialize (dpy, &major, &minor))
	{
		printf ("Initialized version %d.%d\n", major, minor);
	}
	else
	{
		printf ("Failed to initialize\n");
		return;
	}

	if (!eglGetConfigs (dpy,
						configs,
						sizeof(configs)/sizeof(configs[0]),
						&configs_count))
	{
		printf ("Failed to get list of supported configurations\n");
		goto cleanup_display;
	}

	printf ("Got %d configurations\n", configs_count);

	if (configs_count < 1)
	{
		goto cleanup_display;
	}

	surface = eglCreateWindowSurface (dpy,
									  configs[0],
									  &sgaRenderingSurface,
									  NULL);

	if (surface == EGL_NO_SURFACE)
	{
		printf ("Couldn't make surface\n");
		goto cleanup_display;
	}

	context = eglCreateContext (dpy,
								configs[0],
								EGL_NO_CONTEXT,
								NULL);

	if (!eglMakeCurrent (dpy, surface, surface, context))
	{
		printf ("eglMakeCurrent() failed\n");
		goto cleanup_context;
	}

	return;

	cleanup_context:
	eglDestroyContext (dpy, context);

	cleanup_surface:
	eglDestroySurface (dpy, surface);

	cleanup_display:

	if (!eglTerminate (dpy))
	{
		printf ("Trouble closing down display\n");
	}
}

static void
Cleanup ()
{
	eglDestroyContext (dpy, context);
	eglDestroySurface (dpy, surface);
	eglMakeCurrent (dpy, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
	eglTerminate (dpy);
}

static void
Render ()
{
	/* the actual drawing. finally */

	static int rotation = 0;

	GLshort vertexArray[] = {
		0, -1, 0,
		1, 1, 1,
		1, 1, -1,

		0, -1, 0,
		-1, 1, 1,
		-1, 1, -1,

		0, -1, 0,
		1, 1, 1,
		-1, 1, 1,

		0, -1, 0,
		1, 1, -1,
		-1, 1, -1,

		1, 1, 1,
		1, 1, -1,
		-1, 1, -1,

		1, 1, 1, 
		-1, 1, -1,
		-1, 1, 1,
	};

	GLubyte colorArray[] = {
		255, 255, 255, 0,
		255, 0, 0, 0,
		0, 255, 0, 0,

		255, 255, 255, 0,
		0, 0, 255, 0,
		255, 255, 0, 0,

		255, 255, 255, 0,
		255, 0, 0, 0,
		0, 0, 255, 0,

		255, 255, 255, 0,
		0, 255, 0, 0,
		255, 255, 0, 0,

		128, 128, 128, 0,
		128, 128, 128, 0,
		128, 128, 128, 0,

		128, 128, 128, 0,
		128, 128, 128, 0,
		128, 128, 128, 0
	};

	glEnable (GL_DEPTH_TEST);
	glClearColor(255,255,255,255);
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnableClientState (GL_VERTEX_ARRAY);
	glEnableClientState (GL_COLOR_ARRAY);
	glVertexPointer (3, GL_SHORT, 0, vertexArray);
	glColorPointer (4, GL_UNSIGNED_BYTE, 0, colorArray);

	glLoadIdentity ();
	glScalex (FixedFromInt(1) / 2, FixedFromInt(1) / 2, FixedFromInt(1) / 2);
	glRotatex (FixedFromInt ((rotation += 10)), ONE, 0, 0);
	glRotatex (FixedFromInt (rotation / 2), 0, 0, ONE);
	glDrawArrays (GL_TRIANGLES, 0, N_ELEMENTS (vertexArray)/3);
	glDisableClientState (GL_VERTEX_ARRAY);
	glDisableClientState (GL_COLOR_ARRAY);

	/* end drawing */

	eglSwapBuffers (dpy, surface);
}

static void
sigint_handler (int signum)
{
	printf ("Exiting gracefully\n");
	running = EGL_FALSE;
}

int
main (int argc, char *argv[])
{
	/* Set up SIGINT (Ctrl-C) handler */
	signal (SIGINT, &sigint_handler);

	printf ("Doing Initialize()\n");
	fflush( stdout);
	Initialize();

	while (running)
	{
		Render ();
	}

	Cleanup ();
}
