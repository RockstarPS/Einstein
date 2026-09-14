#include "Rte_Type.h"
#include "Rte_PtrView.h"
#include "hmi_rte_interface.h"
extern VAR(UInt8, RTE_VAR_INIT) Rte_EctMdl_EXT_CoolantTempCValue_EXT_CoolantTempCValue;

UINT32 l_odo_dist_val;

UINT32 l_trip_dte_val = 0;
UINT32 l_trip_afe_val = 0;
UINT32 l_trip_distance_val = 0;
UINT32 l_trip_time = 0;

UINT32 l_fuel_dte_val = 0;
UINT32 l_fuel_afe_val = 0;

static tHmiEtmScreen etmScreen;
static tHmiDiagPattern diagPattern;
static UINT32 diagColor;

void set_trip_time(UINT32 time)
{
	l_trip_time = time;
}

void set_trip_distance(UINT32 distance)
{
	l_trip_distance_val = distance;
}

void set_trip_dte(UINT32 trip_dte)
{
	l_trip_dte_val = trip_dte;
}

void set_trip_afe(UINT32 trip_afe)
{
	l_trip_afe_val = trip_afe;
}

void set_fuel_info_afe(UINT32 fuel_afe)
{
	l_fuel_afe_val = fuel_afe;
}

void set_fuel_info_dte(UINT32 fuel_dte)
{
	l_fuel_dte_val = fuel_dte;
}

void set_odo(UINT32 odo)
{
	l_odo_dist_val = odo;
}

void HmiSetEtmScreen(tHmiEtmScreen screen)
{
    etmScreen = screen;
}

tHmiEtmScreen HmiGetEtmScreen(void)
{
    return etmScreen;
}

void HmiSetDiagPattern(tHmiDiagPattern pattern)
{
    diagPattern = pattern;
}

void HmiSetDiagColor(UINT32 color)
{
    diagColor = color;
}

tHmiDiagPattern HmiGetDiagPattern(void)
{
    return diagPattern;
}

UINT32 HmiGetDiagColor(void)
{
    return diagColor;
}

UINT32 HmiGetSpeed(void)
{
    UINT16 speed;

    Rte_Read_tiSR_TISpdMdl_Out_SpdF_Speed(&speed);

    return (UINT32)speed;
}

UINT32 HmiGetRpm(void)
{
    UINT16 rpm;

    Rte_Read_tiSR_TIEngMdl_Out_TachoF_Tacho(&rpm);

    return (UINT32)rpm;

}

UINT32 HmiGetTemperature(void)
{
    return (UINT32)Rte_EctMdl_EXT_CoolantTempCValue_EXT_CoolantTempCValue;
}


