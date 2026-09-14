#ifndef HMI_RTE_INTERFACE_H
#define HMI_RTE_INTERFACE_H

#include "system.h"

#define HMI_PART_N  L"TURING-A"
#define HMI_CORE    L"AMBER-P2"
#define HMI_CAL     L"01.00.00"
#define HMI_SW      L"01.03.00"

#define HMI_TEMPERATURE_OFFSET  60

extern UINT32 l_odo_dist_val;

extern UINT32 l_trip_dte_val;
extern UINT32 l_trip_afe_val;
extern UINT32 l_trip_distance_val;
extern UINT32 l_trip_time;

extern UINT32 l_fuel_dte_val;
extern UINT32 l_fuel_afe_val;

typedef enum{
	UI_GAUGE_SCREEN,
	UI_ETM_SCREEN,
	UI_MAIN_MENU_SCREEN,
	UI_MAX_MAIN_MENU_SCREEN
} UI_MAIN_SCREEN;

typedef enum {
    eHmiEtmScreen100,
    eHmiEtmScreen110,
    eHmiEtmScreen120,
    eHmiEtmScreen130,
    eHmiEtmScreen230,
    eHmiEtmScreen233,
    eHmiEtmScreenMax
} tHmiEtmScreen;

typedef enum {
    eHmiDiagPattern1,
    eHmiDiagPattern2,
    eHmiDiagPattern3,
    eHmiDiagPattern4,
    eHmiDiagPattern5,
    eHmiDiagPatternMax
} tHmiDiagPattern;

void HmiSetEtmScreen(tHmiEtmScreen screen);
tHmiEtmScreen HmiGetEtmScreen(void);

void HmiSetDiagPattern(tHmiDiagPattern pattern);
void HmiSetDiagColor(UINT32 color);
tHmiDiagPattern HmiGetDiagPattern(void);
UINT32 HmiGetDiagColor(void);

UINT32 HmiGetSpeed(void);
UINT32 HmiGetRpm(void);
UINT32 HmiGetTemperature(void);

void set_trip_time(UINT32 time);
void set_trip_distance(UINT32 distance);
void set_trip_dte(UINT32 dte);
void set_trip_afe(UINT32 afe);
void set_fuel_info_dte(UINT32 dte);
void set_fuel_info_afe(UINT32 fuel_afe);
void set_odo(UINT32 odo);

#endif
