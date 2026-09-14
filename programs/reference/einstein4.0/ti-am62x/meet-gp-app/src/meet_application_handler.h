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

#ifndef MEET_APPLICATION_HANDLER_H_
#define MEET_APPLICATION_HANDLER_H_

#include <utility>
#include <vector>
#include <map>
#include <cstdint>
#include <meet_application_types.h>
#include <pthread.h>
#include "dk_bspal_dio.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <xf86drm.h>
#include <xf86drmMode.h>
#include <gbm.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <systemd/sd-bus.h>




LOG_IMPORT_CONTEXT ( gRTELogContext );


namespace dk
{
namespace lib
{
namespace meet
{

class MeetComponent;

typedef uint8 routine_status_type;
typedef uint8 routine_type;
typedef uint8 routine_control_state;




class MeetAppHandler
{
public:

    MeetComponent &mpMeetComponent;

    MeetAppHandler ( MeetComponent &lMeetComponent ) : mpMeetComponent ( lMeetComponent ) ///< Constructor
    {


    }
    virtual ~MeetAppHandler()
    {
    }

    void Init();
    void Stop();
    void periodicTask(void);
    void processDiagRcv(DiagReqMsgData_t &pDiagReqMsgData);
    void stopHmi();
    void stopGStreamerMeet();

private:
    EGLDisplay eglDisplay = 0;
    EGLConfig eglConfig = 0;
    EGLSurface eglSurface = 0;
    EGLContext eglContext = 0;
    GLuint vbo = 0;
    GLuint shader_program = 0;
    GLuint texture = 0;
    int drm_fd = 0;
    uint32_t CrtcId = 0;
    struct gbm_device *gbm = nullptr;
    struct gbm_surface *gbmSurface = nullptr;
    int screenInitStatus = 0;
    bool screenWindowInit = false;
    struct gbm_bo *bo = nullptr;
    int init_screen_window();
    void deinit_screen_window();
    uint32_t connId = 0;
    drmModeModeInfo displayMode = {};
    bool mDisplayActive = false;
    bool mStopsafeHMIervice = false;
    bool mStophmiappService = false;
    std::vector<const char*> services = { "hmi-app.service","safeHmi.service" };
    const char* destination = "org.freedesktop.systemd1";
    const char* path = "/org/freedesktop/systemd1";
    const char* interfaceProperties = "org.freedesktop.DBus.Properties";
    const char* interfaceManager = "org.freedesktop.systemd1.Manager";
    const char* interfaceUnit = "org.freedesktop.systemd1.Unit";
    const char* memberGetUnit = "GetUnit";
    const char* memberStopUnit = "StopUnit";
    const char* memberReplace = "replace";
    const char* memberGet = "Get";
    const char* memberActiveState = "ActiveState";
    const uint32_t screenWidth = 1920U;
    const uint32_t screenHeight = 720U;
    const uint32_t drmFbDepth = 24U;         // bits per pixel used for color (RGB)
    const uint32_t drmFbBpp   = 32U;
    pid_t gstreamerPIDMeet = -1;
    bool isRunning = false;
    uint8_t colour_control(std::vector<uint8_t> data);
    uint8_t display_pattern(const char * const path);

    /*DID Handlers*/
    void RWRead_DIDHandler(const uint16_t didId,  const std::vector<uint8_t> data);
    void RWWrite_DIDHandler(const uint16_t didId,  const std::vector<uint8_t> data);
    void IOCtrl_DIDHandler(const uint8_t controlMode, const uint16_t didId,  const std::vector<uint8_t> data);
    void RoutineCtrl_DIDHandler(const uint8_t controlMode, const uint16_t didId,  const std::vector<uint8_t> data);
    bool isPinSupported(const uint32_t pin);
    int32_t digital_output_pins(const uint8_t portIndex,const uint8_t maskByte,const uint8_t outputBytes);
    diagResType digitalOutputControl(const uint8_t controlMode,const std::vector<uint8_t> data, std::vector<uint8_t >&loutdata );
    diagResType tftOpticTestPictures(const uint8_t controlMode,const std::vector<uint8_t> data, std::vector<uint8_t >&loutdata);
    diagResType tftFullColorControl(const uint8_t controlMode,const std::vector<uint8_t> data, std::vector<uint8_t >&loutdata);
    uint8_t display_full_colour_test(std::vector<uint8_t> data);
    void loadShaders(GLuint &program);
    int32_t getCurrentState(sd_bus *bus, const char *objPath,const char** state);
    int32_t getObjectPath(sd_bus *bus,const char *serviceName, const char** objPath);
    int32_t stopService(sd_bus *bus,const char *serviceName);

    uint8_t display_test_pictures(const char * const path);
};

extern const std::map<uint8_t, const char *> opticPicturePathMap;

} // meet
} // lib
} // dk


#endif
