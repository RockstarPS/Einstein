//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2018] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
//
// Date: Thu Aug 23 18:44:39 IST 2024
// User: GSOUNDAR
// System: GIP
//
//---------------------------------------------------------------------------------------------------------------------
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "meet_component.h"
#include "meet_application_handler.h"
#include "signal.h"
#include <csignal>
#include <ctime>
#include <sys/wait.h>
#include <stb_image.h>

extern "C" {

}


LOG_IMPORT_CONTEXT ( gMEETLogContext );


namespace dk
{
namespace lib
{
namespace meet
{

void MeetAppHandler::Init( )
{
    screenWindowInit = false;
    bo = nullptr;
}

void MeetAppHandler::Stop( )
{
    if(screenWindowInit == true)
    {
        deinit_screen_window();
        screenWindowInit = false;
    }
}

void MeetAppHandler::periodicTask( )
{
    ///< Populate code if needed

}

void MeetAppHandler::processDiagRcv(DiagReqMsgData_t &pDiagReqMsgData)
{
    DiagReqMsgData_t::iterator itr;

    LOGI ( &gMEETLogContext, "processing diag request");

    for ( itr = pDiagReqMsgData.begin(); itr != pDiagReqMsgData.end(); ++itr )
    {
        switch ( itr->mode )
        {
        //Handle the cases RW, Routine IOCtrl
        case EDiagMode_RW_Read:
            RWRead_DIDHandler(itr->didId,itr->data);
            break;
        case EDiagMode_RW_Write:
            RWWrite_DIDHandler(itr->didId,itr->data);
            break;
        case EDiagMode_RC:
            RoutineCtrl_DIDHandler(itr->controlMode,itr->didId,itr->data);
            break;
        case EDiagMode_IOCtrl:
            IOCtrl_DIDHandler(itr->controlMode,itr->didId,itr->data);
            break;

        default:

            LOGE ( &gMEETLogContext, "Invalid Mode received for DID Id", itr->didId );
            break;
        }
    }

}


/***************************************************
 *                    DID HANDLERS
*****************************************************/
void MeetAppHandler::RWRead_DIDHandler(const uint16_t didId, const std::vector<uint8_t> data)
{
    (void) didId;
    (void) data;
}

void MeetAppHandler::RWWrite_DIDHandler(const uint16_t didId, const std::vector<uint8_t> data)
{
    (void) didId;
    (void) data;
}

void MeetAppHandler::IOCtrl_DIDHandler(const uint8_t controlMode,const uint16_t didId,const std::vector<uint8_t> data)
{
    diagResType respCode = DIAG_DEFAULT_INVALID_VALUE;
    std::vector<uint8_t> loutData;
    LOGI ( &gMEETLogContext, "Ioctrl Handler" );

    switch(didId)
    {
    case 0xFE35U:
        respCode = tftOpticTestPictures(controlMode, data, loutData);
        break;
    case 0xFD0EU:
        respCode = tftFullColorControl(controlMode, data, loutData);
        break;
    case 0xFE31U:
        respCode = digitalOutputControl(controlMode, data, loutData);
        break;
    default:
        LOGE ( &gMEETLogContext, "Invalid IO Ctrl DID received", didId );
        break;
    }
    mpMeetComponent.SendDiagReponse ( didId, EDiagMode_IOCtrl, loutData, respCode );

}

void MeetAppHandler::RoutineCtrl_DIDHandler(const uint8_t controlMode, const uint16_t didId,  const std::vector<uint8_t> data)
{
    (void)controlMode;
    (void)data;
    diagResType respCode = DIAG_DEFAULT_INVALID_VALUE;
    std::vector<uint8_t> loutData;
    LOGI ( &gMEETLogContext, "Routine Control Handler" );

    switch(didId)
    {
    default:
        LOGE ( &gMEETLogContext, "Invalid Routine Cntrl DID received", didId );
        break;
    }
    mpMeetComponent.SendDiagReponse ( didId, EDiagMode_RC, loutData, respCode );

}

/***************************************************
 *                    RWRead DIDS
*****************************************************/

/***************************************************
 *                    RWRead DIDS
*****************************************************/

///< Add the DIDS related to RWWrite

/***************************************************
 *                    IOCTRL DIDS
*****************************************************/
void MeetAppHandler::loadShaders(GLuint &program)
{
    const char *vertexShaderSource =
        "#version 300 es\n"
        "layout(location = 0) in vec2 position;\n"
        "layout(location = 1) in vec2 texCoord;\n"
        "out vec2 vTexCoord;\n"
        "void main() {\n"
        "    vTexCoord = texCoord;\n"
        "    gl_Position = vec4(position, 0.0, 1.0);\n"
        "}";

    const char *fragmentShaderSource =
        "#version 300 es\n"
        "precision mediump float;\n"
        "in vec2 vTexCoord;\n"
        "uniform sampler2D tex;\n"
        "out vec4 FragColor;\n"
        "void main() {\n"
        "    FragColor = texture(tex, vTexCoord);\n"
        "}";

    GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertShader, 1, &vertexShaderSource, nullptr);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);

    glCompileShader(vertShader);
    GLint status;
    glGetShaderiv(vertShader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE)
    {
        GLint length;
        glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &length);
        if (length > 0)
        {
            GLchar message[1024];
            glGetShaderInfoLog(vertShader, length, nullptr, message);
            LOGE(&gMEETLogContext, "Failed to compile vertex shader: %s", message);
        }
        else
        {
            LOGE(&gMEETLogContext, "Failed to compile vertex shader: No log available.");
        }

    }
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE)
    {
        GLint length;

        glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &length);
        if (length > 0)
        {
            GLchar message[1024];
            glGetShaderInfoLog(fragmentShader, length, nullptr, message);
            LOGE(&gMEETLogContext, "Failed to compile fragment shader: %s", message);
        }
        else
        {
            LOGE(&gMEETLogContext, "Failed to compile fragment shader: No log available.");
        }
    }

    program = glCreateProgram();
    glAttachShader(program, vertShader);
    glAttachShader(program, fragmentShader);

    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &status);
    if (status == GL_FALSE)
    {
        GLint length;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
        if (length > 0)
        {
            GLchar message[1024];
            glGetProgramInfoLog(program, length, nullptr, message);
            LOGE(&gMEETLogContext, "Failed to link program: %s", message);
        }
        else
        {
            LOGE(&gMEETLogContext, "Failed to link program: No log available.");
        }
    }
}

void MeetAppHandler::stopGStreamerMeet()
{
    if (gstreamerPIDMeet > 0)
    {
        kill(gstreamerPIDMeet, SIGTERM);

        waitpid(gstreamerPIDMeet, nullptr, 0);

        gstreamerPIDMeet = -1;
        isRunning = false;
    }
    else
    {
        LOGE ( &gMEETLogContext, "Process already killed");
    }
}
uint8_t MeetAppHandler::display_pattern(const char * const path)
{
    uint8_t Ret = 0xFFU;
    if (isRunning)
    {
        stopGStreamerMeet();
    }

    (void)signal(SIGCHLD, SIG_IGN);
    gstreamerPIDMeet = fork();
    if (gstreamerPIDMeet == 0)
    {
        char location_arg[512];
        snprintf(location_arg, sizeof(location_arg), "location=%s", path);

        const char* argv[] = {
            "gst-launch-1.0",
            "filesrc", location_arg,
            "!",
            "pngdec",
            "!",
            "imagefreeze",
            "!",
            "videoconvert",
            "!",
            "videoscale",
            "!",
            "video/x-raw,width=1920,height=720",
            "!",
            "kmssink",
            nullptr
        };

        execvp("gst-launch-1.0", (char* const*)argv);

        perror("execvp failed");
        _exit(1);
    }
    else if (gstreamerPIDMeet > 0)
    {
        isRunning = true;
        LOGE(&gMEETLogContext, "Fork Successful");
        Ret = 0x00U;
    }
    else
    {
        LOGE(&gMEETLogContext, "Fork Failed");
    }

    return Ret;
}

uint8_t MeetAppHandler::display_test_pictures(const char * const path)
{
    uint8_t displayPatternStatus = display_pattern(path);
    LOGI ( &gMEETLogContext, "Screen init successs");
    return displayPatternStatus;
}

diagResType MeetAppHandler::tftOpticTestPictures(const uint8_t controlMode,const std::vector<uint8_t> data,std::vector<uint8_t >&loutdata)
{
    diagResType respCode = DIAG_DEFAULT_INVALID_VALUE;
    uint8 lPatternId;
    uint8_t Ret = 0x00U;
    if (controlMode == EIOCtrlOptType_shortTermAdjustment)
    {
        loutdata.push_back(controlMode);
        if(data.size() == 1U)
        {
            lPatternId = data.at ( 0U );
            const auto& it = opticPicturePathMap.find(lPatternId);
            if (it != opticPicturePathMap.end())
            {
                Ret = display_test_pictures(it->second);
                LOGI ( &gMEETLogContext, "display pattern status ",Ret);
                if(Ret == 0x00U)
                {
                    respCode = DIAG_POSITIVERESPONSE;
                }
            }
            else
            {
                LOGE ( &gMEETLogContext, "Pattern not available  Pattern Id:=> ", data.at ( 0U ) );
                respCode = DIAG_CONDITIONSNOTCORRECT;
            }
        }
        else
        {
            respCode = DIAG_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            LOGE ( &gMEETLogContext, "Invalid Length received", data.size() );
        }
    }
    else if (controlMode == EIOCtrlOptType_returnControlToECU)
    {
        loutdata.push_back(controlMode);
        if(data.size() == 0U)
        {
            stopGStreamerMeet();
            if(gstreamerPIDMeet !=0)
            {
                respCode = DIAG_POSITIVERESPONSE;
            }
        }
        else
        {
            respCode = DIAG_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            LOGE ( &gMEETLogContext, "Invalid Length received", data.size() );
        }
    }
    else
    {
        respCode = DIAG_SUBFUNCTIONNOTSUPPORTED;
        LOGE ( &gMEETLogContext, "Requested sub fcuntion is not supported", controlMode );
    }

    return respCode;
}
int MeetAppHandler::init_screen_window()
{
    drm_fd = open("/dev/dri/card0", O_RDWR | O_CLOEXEC);
    if (drm_fd < 0)
    {
        LOGE ( &gMEETLogContext, "Error opening DRM device:");
        screenInitStatus = -1;
    }
    if (screenInitStatus == 0)
    {
        if (drmSetMaster(drm_fd) != 0)
        {
            LOGE ( &gMEETLogContext, "Error setting DRM master:");
            (void)close(drm_fd);
            screenInitStatus = -1;
        }
        else
        {
            LOGI ( &gMEETLogContext, "Acquired master control over DRM device.");
        }
    }
    if(screenInitStatus == 0)
    {
        drmModeRes *resources = drmModeGetResources(drm_fd);
        if (resources == nullptr)
        {
            LOGE ( &gMEETLogContext, "cannot get DRM resources:");
            (void)close(drm_fd);
            screenInitStatus = -1;
        }
        else
        {
            for (int i = 0; i < resources->count_crtcs; i++)
            {
                drmModeCrtc *crtc = drmModeGetCrtc(drm_fd, resources->crtcs[i]);
                if (crtc != nullptr)
                {
                    CrtcId = crtc->crtc_id;
                    drmModeFreeCrtc(crtc);
                }
            }
            for (int j = 0; j < resources->count_connectors; j++)
            {
                drmModeConnector *connector = drmModeGetConnector(drm_fd, resources->connectors[j]);
                if (connector != nullptr)
                {
                    if (connector->connection == DRM_MODE_CONNECTED) {
                        LOGI(&gMEETLogContext, "Connector found for CRTC:");
                        connId = connector->connector_id;

                        if (connector->count_modes > 0) {
                            displayMode = connector->modes[0];
                        }
                    }
                    drmModeFreeConnector(connector);
                }
            }
        }
    }
    if(screenInitStatus == 0)
    {
        gbm = gbm_create_device(drm_fd);
        if (gbm == nullptr)
        {
            LOGE ( &gMEETLogContext, "Error creating GBM device");
            screenInitStatus = -1;
        }
        else
        {
            LOGI ( &gMEETLogContext, "GBM device created successfully.:");
        }
    }
    if(screenInitStatus == 0)
    {
        eglDisplay = eglGetDisplay(reinterpret_cast<EGLNativeDisplayType>(gbm));
        if (eglDisplay == EGL_NO_DISPLAY)
        {
            LOGE ( &gMEETLogContext, "Error getting EGL display:",eglGetError());
            (void)close(drm_fd);
            screenInitStatus = -1;
        }
        else
        {
            LOGE ( &gMEETLogContext, "EGL display obtained");
        }
    }
    if(screenInitStatus == 0)
    {
        EGLint major;
        EGLint minor;
        if (eglInitialize(eglDisplay, &major, &minor) == EGL_FALSE)
        {
            LOGE ( &gMEETLogContext, "Error initializing EGL:",eglGetError());
            (void)close(drm_fd);
            screenInitStatus = -1;
        }
        else
        {
            LOGI ( &gMEETLogContext, "EGL initialized successfully:");
        }
    }
    if(screenInitStatus == 0)
    {
        EGLint configAttribs[] =
        {
            EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
            EGL_RED_SIZE, 8,
            EGL_GREEN_SIZE, 8,
            EGL_BLUE_SIZE, 8,
            EGL_ALPHA_SIZE, 0,
            EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
            EGL_NONE
        };
        EGLint numConfigs;
        if (!eglChooseConfig(eglDisplay, configAttribs, &eglConfig, 1, &numConfigs) || numConfigs == 0)
        {
            LOGE ( &gMEETLogContext, "Error choosing EGL config::",eglGetError());
            (void)close(drm_fd);
            screenInitStatus = -1;
        }
        else
        {
            LOGI ( &gMEETLogContext, "EGL config chosen:");
        }
    }
    if(screenInitStatus == 0)
    {
        EGLint contextAttribs[] =
        {
            EGL_CONTEXT_CLIENT_VERSION, 2,
            EGL_NONE
        };
        eglContext = eglCreateContext(eglDisplay, eglConfig, EGL_NO_CONTEXT, contextAttribs);
        if (eglContext == EGL_NO_CONTEXT)
        {
            LOGE ( &gMEETLogContext, "Error creating EGL context");
            screenInitStatus = -1;
        }
        else
        {
            LOGI ( &gMEETLogContext, "EGL context created.:");
        }
    }
    if(screenInitStatus == 0)
    {
        gbmSurface = gbm_surface_create(gbm, screenWidth, screenHeight, GBM_FORMAT_XRGB8888, GBM_BO_USE_RENDERING);
        if (gbmSurface == nullptr)
        {
            LOGE ( &gMEETLogContext, "Error creating GBM surface");
            screenInitStatus = -1;
        }
        else
        {
            LOGI ( &gMEETLogContext, "GBM surface created");
        }
    }
    if(screenInitStatus == 0)
    {
        eglSurface = eglCreateWindowSurface(eglDisplay, eglConfig, reinterpret_cast<EGLNativeWindowType>(gbmSurface), NULL);
        if (eglSurface == EGL_NO_SURFACE)
        {
            LOGE ( &gMEETLogContext, "Error creating EGL surface");
            screenInitStatus = -1;
        }
        else
        {
            LOGE ( &gMEETLogContext, "EGL surface created.");
        }
    }

    return screenInitStatus;
}
uint8_t MeetAppHandler::colour_control(std::vector<uint8_t> data)
{
    uint8_t Ret = 0;
    float r = static_cast<float>(data[0]) / 255.0F;
    float g = static_cast<float>(data[1]) / 255.0F;
    float b = static_cast<float>(data[2]) / 255.0F;
    if(bo != nullptr)
    {
        gbm_surface_release_buffer(gbmSurface, bo);
        LOGE ( &gMEETLogContext, "Release buffer");
    }
    glClearColor(r, g, b, 0.0F);
    glClear(GL_COLOR_BUFFER_BIT);
    (void)eglSwapBuffers(eglDisplay, eglSurface);
    bo = gbm_surface_lock_front_buffer(gbmSurface);
    if (!bo)
    {
        LOGE (&gMEETLogContext, "Failed to lock front buffer");
        Ret = 0xFFU;
    }
    else
    {
        uint32_t fb = 0;

        int drmStatus = drmModeAddFB(drm_fd, screenWidth, screenHeight, drmFbDepth, drmFbBpp, gbm_bo_get_stride(bo), gbm_bo_get_handle(bo).u32, &fb);
        if (drmStatus)
        {
            LOGE ( &gMEETLogContext, "Failed to create framebuffer:",drmStatus,strerror(errno));
            Ret = 0xFFU;
        }
        else
        {
            if(mDisplayActive == false)
            {

                int setCrtcStatus = drmModeSetCrtc(drm_fd,CrtcId,fb,0, 0,&connId, 1,&displayMode);
                if(setCrtcStatus == 0)
                {
                    mDisplayActive = true;
                }
            }
            else
            {
                int pageFlipStatus = drmModePageFlip(drm_fd, CrtcId, fb, DRM_MODE_PAGE_FLIP_EVENT, nullptr);
                if (pageFlipStatus)
                {
                    LOGE ( &gMEETLogContext, "Failed to page flip:",pageFlipStatus, strerror(errno));
                    Ret = 0xFFU;
                }
                drmEventContext evctx = {};
                evctx.version = DRM_EVENT_CONTEXT_VERSION;
                evctx.page_flip_handler = nullptr;
                (void)drmHandleEvent(drm_fd, &evctx);
            }
        }
    }
    return Ret;
}
void MeetAppHandler::deinit_screen_window()
{
    if (texture != 0) {
        glDeleteTextures(1, &texture);
        texture = 0;  // Reset to avoid accidental use
        LOGE(&gMEETLogContext, "Deleted OpenGL texture.");
    }
    if (vbo != 0) {
        glDeleteBuffers(1, &vbo);
        vbo = 0;  // Reset to avoid accidental use
        LOGE(&gMEETLogContext, "Deleted OpenGL VBO.");
    }
    if (shader_program != 0) {
        glDeleteProgram(shader_program);
        shader_program = 0;  // Reset to avoid accidental use
        LOGE(&gMEETLogContext, "Deleted OpenGL shader program.");
    }

    if (eglSurface != EGL_NO_SURFACE) {
        (void)eglDestroySurface(eglDisplay, eglSurface);
        eglSurface = EGL_NO_SURFACE;  // Set to invalid surface after destruction
        LOGE(&gMEETLogContext, "Destroyed EGL surface.");
    }
    if (eglContext != EGL_NO_CONTEXT) {
        (void)eglDestroyContext(eglDisplay, eglContext);
        eglContext = EGL_NO_CONTEXT;  // Set to invalid context after destruction
        LOGE(&gMEETLogContext, "Destroyed EGL context.");
    }
    if (eglDisplay != EGL_NO_DISPLAY) {
        eglTerminate(eglDisplay);
        eglDisplay = EGL_NO_DISPLAY;  // Set to invalid display after termination
        LOGE(&gMEETLogContext, "Terminated EGL display.");
    }
    if (gbmSurface != nullptr) {
        if(bo != nullptr)
        {
            gbm_surface_release_buffer(gbmSurface, bo);  // Release the locked buffer
            bo = nullptr;  // Set to NULL to avoid accidental reuse
            LOGE(&gMEETLogContext, "Released GBM buffer.");
        }
        gbm_surface_destroy(gbmSurface);  // Destroy the GBM surface
        gbmSurface = nullptr;  // Set to NULL to avoid accidental reuse
        LOGE(&gMEETLogContext, "Destroyed GBM surface.");
    }
    if (gbm != nullptr) {
        gbm_device_destroy(gbm);  // Destroy the GBM device
        gbm = nullptr;  // Set to NULL to avoid accidental reuse
        LOGE(&gMEETLogContext, "Destroyed GBM device.");
    }
    if (drm_fd >= 0) {
        drmModeFreeResources(drmModeGetResources(drm_fd));  // Free DRM resources
        if (drmDropMaster(drm_fd) != 0)
        {
            LOGE ( &gMEETLogContext, "Error dropping DRM master:");
        }
        else
        {
            LOGE ( &gMEETLogContext, "released master control over DRM device.");
        }
        (void)close(drm_fd);  // Close the DRM file descriptor
        drm_fd = -1;  // Set to invalid descriptor
        LOGE(&gMEETLogContext, "Cleaned up and closed the DRM device.");
    }
    LOGE(&gMEETLogContext, "Screen window deinitialized successfully.");
}
uint8_t MeetAppHandler::display_full_colour_test(std::vector<uint8_t> data)
{
    uint8_t colourControlStatus = 0xFFU;
    if(screenWindowInit == false)
    {
        screenInitStatus = init_screen_window();
        if(screenInitStatus == 0)
        {
            screenWindowInit = true;
        }
    }
    if(screenWindowInit == true)
    {
        LOGI ( &gMEETLogContext, "Screen init successs");
        colourControlStatus = colour_control(data);
        LOGI ( &gMEETLogContext, "Colour control done");
    }
    else
    {
        LOGE ( &gMEETLogContext, "Screen init failed");
    }
    return colourControlStatus;
}
diagResType MeetAppHandler::tftFullColorControl(const uint8_t controlMode,const std::vector<uint8_t> data,std::vector<uint8_t >&loutdata)
{
    diagResType respCode = DIAG_DEFAULT_INVALID_VALUE;
    uint8_t Ret = 0xFFU;
    if ( (controlMode == EIOCtrlOptType_shortTermAdjustment) || (controlMode == EIOCtrlOptType_returnControlToECU) )
    {
        loutdata.push_back(controlMode);
        if( data.size() == 3U )
        {
            LOGI ( &gMEETLogContext, "display full colour test");
            Ret = display_full_colour_test(data);
            if(Ret == 0x00U)
            {
                respCode = DIAG_POSITIVERESPONSE;
            }
        }
        else
        {
            LOGE ( &gMEETLogContext, "Wrong Payload length", +data.size() );
            respCode = DIAG_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        }
    }
    return respCode;
}

int32_t MeetAppHandler::getObjectPath(sd_bus *bus,const char *serviceName, const char** objPath)
{

    sd_bus_error error = SD_BUS_ERROR_NULL;
    sd_bus_message *msg = nullptr;

    int32_t ret = sd_bus_call_method(bus,destination,path,interfaceManager,memberGetUnit,
                                     &error,&msg,"s",serviceName
                                    );
    if(ret < 0)
    {
        LOGE(&gMEETLogContext, "Failed to get object unit path", strerror(-ret));
    }
    else
    {
        ret = sd_bus_message_read(msg, "o", objPath);
        if(ret < 0)
        {
            LOGE(&gMEETLogContext, "Failed to read object unit path", strerror(-ret));
        }
    }

    (void)sd_bus_error_free(&error);
    (void)sd_bus_message_unref(msg);

    return ret;

}

int32_t MeetAppHandler::getCurrentState(sd_bus *bus,const char *objPath, const char** state)
{
    sd_bus_error error = SD_BUS_ERROR_NULL;
    sd_bus_message *msg = nullptr;

    int32_t ret = sd_bus_call_method(bus,destination,objPath,interfaceProperties,memberGet,
                                     &error,&msg,"ss",interfaceUnit,memberActiveState
                                    );

    if (ret >= 0)
    {

        ret = sd_bus_message_enter_container(msg, 'v', "s");

        if(ret < 0)
        {
            LOGE(&gMEETLogContext, "Failed to enter variant container:", strerror(-ret));
        }
        else
        {
            ret = sd_bus_message_read(msg, "s", state);
            if(ret <  0)
            {
                LOGE(&gMEETLogContext, "Failed to read ActiveState:", strerror(-ret));
            }
        }
    }
    else
    {
        LOGE(&gMEETLogContext, "Failed to get ActiveState:", strerror(-ret));
    }

    (void)sd_bus_error_free(&error);
    (void)sd_bus_message_unref(msg);

    return ret;
}


int32_t MeetAppHandler::digital_output_pins(const uint8_t portIndex,const uint8_t maskByte,const uint8_t outputBytes)
{
    int32_t ret = -1;
    bool setPinFail = false;

    for (uint8_t bitPos = 0; bitPos < 8; ++bitPos)
    {
        if (((maskByte >> bitPos) & 0x01U) == 0x01U)
        {
            const uint32_t gpio_pin = (portIndex * 8) + bitPos;

            const bool isPinconfigured = isPinSupported(gpio_pin);

            if(isPinconfigured != false)
            {
                const bool pin_value = ((outputBytes >> bitPos) & 0x01U) != 0U;
                ret = dk_bspal_dio_set_value(gpio_pin, pin_value);
                if(ret == -1)
                {
                    setPinFail = true;
                    LOGE ( &gMEETLogContext, "Unable to set pin", gpio_pin);
                }
            }
            else
            {   
                ret = 0;
                LOGE ( &gMEETLogContext,"Received pin number does not support:",gpio_pin);
            }
        }
    }
    if(setPinFail == true)
    {
        ret = -1;
    }
    return ret;
}

bool MeetAppHandler::isPinSupported(const uint32_t pin)
{
    const size_t size = sizeof(gpioPinMapping) / sizeof(gpioPinMapping[0]);
    bool isPinconfigured = false;
    uint32_t gpio_pin;
    for (size_t i = 0; i < size; ++i)
    {
        gpio_pin = static_cast<uint32_t>(gpioPinMapping[i].pin);
        if (gpio_pin == pin) 
        {
            isPinconfigured = true;
        }
    }
    return isPinconfigured;
}

diagResType MeetAppHandler::digitalOutputControl(const uint8_t controlMode,const std::vector<uint8_t> data,std::vector<uint8_t >&loutdata)
{
    diagResType respCode = DIAG_DEFAULT_INVALID_VALUE;
    int32_t Ret = -1;

    if ( controlMode == EIOCtrlOptType_shortTermAdjustment )
    {

        loutdata.push_back(controlMode);

        if( data.size() == 3U )
        {
            const uint8_t portIndex = static_cast<uint8_t>(data[0]);
            const uint8_t maskByte = static_cast<uint8_t>(data[1]);
            const uint8_t outputBytes = static_cast<uint8_t>(data[2]);

            if(portIndex > 20)
            {
                respCode = DIAG_CONDITIONSNOTCORRECT;
            }
            else
            {
                Ret = digital_output_pins(portIndex,maskByte,outputBytes);
                if(Ret != -1)
                {
                    respCode = DIAG_POSITIVERESPONSE;
                }
                else
                {
                    respCode = DIAG_CONDITIONSNOTCORRECT;
                }
            }
        }
        else
        {
            LOGE ( &gMEETLogContext, "Wrong Payload length", +data.size() );
            respCode = DIAG_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        }
    }
    else if(controlMode == EIOCtrlOptType_returnControlToECU)
    {
        loutdata.push_back(controlMode);
        respCode = DIAG_POSITIVERESPONSE;
    }

    return respCode;
}

int32_t MeetAppHandler::stopService(sd_bus *bus,const char *serviceName)
{
    sd_bus_error error = SD_BUS_ERROR_NULL;
    sd_bus_message *msg = nullptr;

    int32_t ret = sd_bus_call_method(bus,destination,path,interfaceManager,memberStopUnit,                          // Method name
                                     &error,&msg,"ss",serviceName,memberReplace
                                    );
    if(ret < 0)
    {
        LOGE(&gMEETLogContext, "Failed to stop service", strerror(-ret), serviceName);
    }

    (void)sd_bus_error_free(&error);
    (void)sd_bus_message_unref(msg);

    return ret;
}

void MeetAppHandler::stopHmi()
{

    while((mStophmiappService == false) || (mStopsafeHMIervice == false))
    {
        int ret = -1;
        uint8_t servicesSize = services.size();
        sd_bus *bus = nullptr;
        // Connect to the system bus
        ret = sd_bus_open_system(&bus);
        if (ret >= 0)
        {
            /*Stop service */
            for(int i = 0; i< servicesSize; i++)
            {
                const char *objPath = nullptr;
                const char *state = nullptr;
                const char *serviceName = services[i];
                ret = getObjectPath(bus,serviceName,&objPath);

                if(ret >= 0 && objPath != nullptr)
                {
                    ret = getCurrentState(bus,objPath,&state);
                    if(ret >= 0 && state != nullptr)
                    {
                        if(strcmp(state, "active") == 0)
                        {
                            (void) stopService(bus,serviceName);
                        }
                        else if(strcmp(state, "failed") == 0 || strcmp(state, "inactive") == 0)
                        {
                            if (strcmp(serviceName,"hmi-app.service") == 0)
                            {
                                LOGI(&gMEETLogContext,"Service is stopped successfully.\n",serviceName);
                                mStophmiappService = true;
                            }
                            else if(strcmp(serviceName,"safeHmi.service") == 0)
                            {
                                LOGI(&gMEETLogContext,"Service is stopped successfully.\n",serviceName);
                                mStopsafeHMIervice = true;
                            }
                            else
                            {
                                //Do Nothing
                            }
                        }
                        else
                        {
                            /*DO nothing*/
                        }
                    }
                }
            }
        }
        else
        {
            LOGE(&gMEETLogContext, "Failed to connect to system bus:", strerror(-ret),ret);
        }

        // Cleanup
        (void)sd_bus_flush(bus);
        sd_bus_close(bus);
        (void)sd_bus_unref(bus);
    }

}

} // meet
} // lib
} // dk

