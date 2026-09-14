#ifndef __MIREO_VIGPSAPI_H__
#define __MIREO_VIGPSAPI_H__

#define NOMINMAX
#include <winuser.h>

#define mireo_app_class		L"CardinaleWndClass"
#define mireo_wnd_title		L"BlackEdition"

#define WM_MIREO_ACTIVATE					RegisterWindowMessage(_T("WM_MIREO_ACTIVATE"))
#define WM_MIREO_SHOW_MAIN_MENU				RegisterWindowMessage(_T("WM_MIREO_SHOW_MAIN_MENU"))
#define WM_MIREO_CLOSE_APP					RegisterWindowMessage(_T("WM_MIREO_CLOSE_APP"))
#define WM_MIREO_GET_VERSION				RegisterWindowMessage(_T("WM_MIREO_GET_VERSION"))

#define WM_MIREO_SHOW_GEO_ADDRESS			RegisterWindowMessage(_T("WM_MIREO_SHOW_GEO_ADDRESS"))
#define WM_MIREO_GOTO_GEO_ADDRESS			RegisterWindowMessage(_T("WM_MIREO_GOTO_GEO_ADDRESS"))

#define WM_MIREO_SET_TIME_FORMAT			RegisterWindowMessage(_T("WM_MIREO_SET_TIME_FORMAT"))
#define WM_MIREO_SET_LANGUAGE				RegisterWindowMessage(_T("WM_MIREO_SET_LANGUAGE"))
#define WM_MIREO_RESTORE_DEFAULTS			RegisterWindowMessage(_T("WM_MIREO_RESTORE_DEFAULTS"))

#define WM_MIREO_GET_GPS_POSITION			RegisterWindowMessage(_T("WM_MIREO_GET_GPS_POSITION"))

#define WM_MIREO_GUIDANCE_REPEAT			RegisterWindowMessage(_T("WM_MIREO_GUIDANCE_REPEAT"))
#define WM_MIREO_GUIDANCE_START				RegisterWindowMessage(_T("WM_MIREO_GUIDANCE_START"))
#define WM_MIREO_GUIDANCE_END				RegisterWindowMessage(_T("WM_MIREO_GUIDANCE_END"))

#define WM_MIREO_MSG_BOX					RegisterWindowMessage(_T("WM_MIREO_MSG_BOX"))

#define WM_MIREO_SPEEDLIMIT_WARN			RegisterWindowMessage(_T("WM_MIREO_SPEEDLIMIT_WARN"))
#define WM_MIREO_GET_TTG					RegisterWindowMessage(_T("WM_MIREO_GET_TTG"))
#define WM_MIREO_GET_WHOLE_TTG				RegisterWindowMessage(_T("WM_MIREO_GET_WHOLE_TTG"))

#define WM_MIREO_START_ROUTE				RegisterWindowMessage(_T("WM_MIREO_START_ROUTE"))
#define WM_MIREO_END_ROUTE					RegisterWindowMessage(_T("WM_MIREO_END_ROUTE"))
#define WM_MIREO_ADD_VIA_POINT				RegisterWindowMessage(_T("WM_MIREO_ADD_VIA_POINT"))

#define WM_MIREO_SET_TRUCK_ATTRIBS			RegisterWindowMessage(_T("WM_MIREO_SET_TRUCK_ATTRIBS"))

#define WM_MIREO_TEXT_TO_SPEAK				RegisterWindowMessage(_T("WM_MIREO_TEXT_TO_SPEAK"))

#define WM_MIREO_DAYNIGHT_TRANSITION		RegisterWindowMessage(_T("WM_MIREO_DAYNIGHT_TRANSITION"))

#define WM_MIREO_HEALTH_REQUEST				RegisterWindowMessage(_T("WM_MIREO_HEALTH_REQUEST"))
#define WM_MIREO_HEALTH_RESPONSE			RegisterWindowMessage(_T("WM_MIREO_HEALTH_RESPONSE"))
#define WM_MIREO_GET_DTG					RegisterWindowMessage(_T("WM_MIREO_GET_DTG"))
#define WM_MIREO_GET_WHOLE_DTG				RegisterWindowMessage(_T("WM_MIREO_GET_WHOLE_DTG"))
#define WM_MIREO_MUTE						RegisterWindowMessage(_T("WM_MIREO_MUTE"))
#define WM_MIREO_SHOW_MAP					RegisterWindowMessage(_T("WM_MIREO_SHOW_MAP"))
#define WM_MIREO_SET_NIGHT_MODE				RegisterWindowMessage(_T("WM_MIREO_SET_NIGHT_MODE"))
#define WM_MIREO_SET_DISTANCE_UNITS			RegisterWindowMessage(_T("WM_MIREO_SET_DISTANCE_UNITS"))

#ifdef HMI_GRAPHICS_APP_C
const WPARAM MUT_METRIC = 0;
const WPARAM MUT_IMPERIAL = 1;

const WPARAM MA_MUTE = 0;
const WPARAM MA_UNMUTE = 1;

const WPARAM MDN_NIGHT = 1;
const WPARAM MDN_DAY = 0;

const WPARAM MA_FOREGROUND = 1;
const WPARAM MA_BACKGROUND = 2;

const WPARAM MVER_APP = 1;
const WPARAM MVER_API = 2;

const LRESULT current_mireo_api_ver = 210;

const WPARAM MTF_12 = 1;
const WPARAM MTF_24 = 0;

const WPARAM MSG_TYPE_OK_CANCEL=0;
const WPARAM MSG_TYPE_OK=1;
const WPARAM MSG_TYPE_YES_NO=2;
const WPARAM MSG_TYPE_TIMED=3;

#endif

struct ExcGeoAddress {
	WCHAR country[64];
	WCHAR city[64];
	WCHAR area[64];
	WCHAR postal_code[16];
	WCHAR street[64];
	WCHAR house_no[8];
	WCHAR POI[128];

	double WGS84_x;
	double WGS84_y;
};

struct ExcMsgBox {
	unsigned short type;
	WCHAR title[64];
	WCHAR text[256];
	unsigned int request_id;
};

struct ExcTruckAttribs {
	unsigned short TruckType;
	unsigned short CargoType;

	unsigned short Units;

	double weight;
	double weight_per_axle;
	
	double length;
	double width;
	double height;
};

//
// NavmanWireless
//
#ifdef NO_NavmanWireless

static unsigned WM_ANWBT_OUTMSG_CALLSTATUS = RegisterWindowMessage(TEXT("WM_ANWBT_OUTMSG_CALLSTATUS"));

typedef enum {
    DS_IDLE = 0,
    //PhoneLink is running, but no phone connected.
    DS_STANDBY,
    // PhoneLink is running, and phone is connected.
    DS_INCOMINGCALL,
    //There is an incoming call
    DS_OUTGOINGCALL,
    //A call is dialing out.
    DS_ONGOINGCALL,
    //A call is picked up
} ANW_DIALERSTATE;

#endif

#endif // __MIREO_VIGPSAPI_H__