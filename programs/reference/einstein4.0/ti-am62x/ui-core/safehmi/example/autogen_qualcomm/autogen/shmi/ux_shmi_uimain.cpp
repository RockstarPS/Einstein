/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2013. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation.
**
**============================================================================
**
** Name:           
**
** Description:    
**
** Organization:   UI Frameworks & Tools, Visteon
**
**============================================================================
**
**==========================================================================*/

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "ux_shmi_uimain.h"

#include "road_active_81.h"
#include "road_inactive_58.h"
#include "road_req_4d.h"
#include "sport_req_df.h"
#include "sport_inactive_ea.h"
#include "sport_active_13.h"
#include "offroad_req_88.h"
#include "offroad_override_req_47.h"
#include "offroad_override_active_7b.h"
#include "offroad_inactive_93.h"
#include "offroad_active_bc.h"
#include "custom_offroad_req_82.h"
#include "custom_offroad_override_req_41.h"
#include "custom_offroad_override_active_75.h"
#include "custom_offroad_inactive_8d.h"
#include "custom_offroad_active_b6.h"
#include "customa_req_a3.h"
#include "customa_inactive_ae.h"
#include "customa_active_d7.h"
#include "customb_req_a4.h"
#include "customb_inactive_af.h"
#include "customb_active_d8.h"
#include "rain_req_51.h"
#include "rain_inactive_5c.h"
#include "rain_active_85.h"
#include "eco_req_de.h"
#include "eco_inactive_e9.h"
#include "eco_active_12.h"
#include "error_mode_2e.h"
#include "icon_aux_56.h"
#include "turbine_f9.h"
#include "parking_brake_50.h"
#include "aux_lights_38.h"
#include "rear_fog_light_bc.h"
#include "low_fuel_5d.h"
#include "service_interval_b5.h"
#include "check_engine_d3.h"
#include "hight_beam_08.h"
#include "automatic_high_beam_ba.h"
#include "left_turn_indicator_ef.h"
#include "right_turn_indicator_62.h"
#include "low_tire_pressure_3d.h"
#include "coolant_temp_05.h"
#include "low_oil_pressure_cd.h"
#include "general_purpose_fault_c6.h"
#include "vehicle_hold_control_46.h"
#include "traction_control_fault_3f.h"
#include "heated_grips_fault_6a.h"
#include "heated_grips_3_81.h"
#include "heated_grips_2_80.h"
#include "heated_grips_1_7f.h"
#include "heated_grips_0_7e.h"
#include "low_battery_voltage_fd.h"
#include "abs_36.h"
#include "load_shed_a3.h"


/*============================================================================
** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
**==========================================================================*/


#if UX_SHMI_MAX_DESIGN_DEPTH > UX_SHMI_MAX_SCENE_DEPTH
  #error "UX_SHMI_MAX_DESIGN_DEPTH should be <= UX_SHMI_MAX_SCENE_DEPTH"
#endif

namespace UX_SHMI_PLAYER
{
extern ux_safehmi_item const * lc_childlist_root[25];
extern ux_safehmi_item const * lc_childlist_ride_modes[29];
extern ux_safehmi_item const * lc_childlist_shmi_region_1[4];


/*============================================================================
** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
**==========================================================================*/


/*============================================================================
** M E M O R Y   A L L O C A T I O N
**===========================================================================*/
Canvasroot root(0, 0, 1920, 720, true, 0xFFFFFFFFU, 25U, static_cast<const ux_safehmi_item **>(lc_childlist_root));
static Itemride_modes ride_modes(0, 0, 1, 1, true, 0xFFFFFFFFU, 29U, static_cast<const ux_safehmi_item **>(lc_childlist_ride_modes), sHMI_ObjType::eItem);
static Imageroad_active road_active(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, road_active_81 );
static Imageroad_inactive road_inactive(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, road_inactive_58 );
static Imageroad_req road_req(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, road_req_4d );
static Imagesport_req sport_req(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, sport_req_df );
static Imagesport_inactive sport_inactive(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, sport_inactive_ea );
static Imagesport_active sport_active(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, sport_active_13 );
static Imageoffroad_req offroad_req(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, offroad_req_88 );
static Imageoffroad_override_req offroad_override_req(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, offroad_override_req_47 );
static Imageoffroad_override_active offroad_override_active(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, offroad_override_active_7b );
static Imageoffroad_inactive offroad_inactive(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, offroad_inactive_93 );
static Imageoffroad_active offroad_active(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, offroad_active_bc );
static Imagecustom_offroad_req custom_offroad_req(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, custom_offroad_req_82 );
static Imagecustom_offroad_override_req custom_offroad_override_req(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, custom_offroad_override_req_41 );
static Imagecustom_offroad_override_active custom_offroad_override_active(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, custom_offroad_override_active_75 );
static Imagecustom_offroad_inactive custom_offroad_inactive(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, custom_offroad_inactive_8d );
static Imagecustom_offroad_active custom_offroad_active(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, custom_offroad_active_b6 );
static Imagecustoma_req customa_req(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, customa_req_a3 );
static Imagecustoma_inactive customa_inactive(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, customa_inactive_ae );
static Imagecustoma_active customa_active(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, customa_active_d7 );
static Imagecustomb_req customb_req(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, customb_req_a4 );
static Imagecustomb_inactive customb_inactive(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, customb_inactive_af );
static Imagecustomb_active customb_active(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, customb_active_d8 );
static Imagerain_req rain_req(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, rain_req_51 );
static Imagerain_inactive rain_inactive(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, rain_inactive_5c );
static Imagerain_active rain_active(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, rain_active_85 );
static Imageeco_req eco_req(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, eco_req_de );
static Imageeco_inactive eco_inactive(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, eco_inactive_e9 );
static Imageeco_active eco_active(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, eco_active_12 );
static Imageerror_mode_0 error_mode_0(1803, 104, 67, 56, true, 0xFFFFFFFFU, 0U, nullptr, error_mode_2e );
static Imageicon_aux icon_aux(274, 26, 44, 16, true, 0xFFFFFFFFU, 0U, nullptr, icon_aux_56 );
static Imageturbine turbine(323, 16, 48, 42, true, 0xFFFFFFFFU, 0U, nullptr, turbine_f9 );
static Imageparking_brake parking_brake(1180, 11, 48, 40, true, 0xFFFFFFFFU, 0U, nullptr, parking_brake_50 );
static Imageaux_lights aux_lights(1501, 11, 39, 39, true, 0xFFFFFFFFU, 0U, nullptr, aux_lights_38 );
static Imagerear_fog_light rear_fog_light(1449, 11, 39, 39, true, 0xFFFFFFFFU, 0U, nullptr, rear_fog_light_bc );
static Imagelow_fuel low_fuel(641, 12, 43, 42, true, 0xFFFFFFFFU, 0U, nullptr, low_fuel_5d );
static Imageservice_interval service_interval(392, 12, 17, 39, true, 0xFFFFFFFFU, 0U, nullptr, service_interval_b5 );
static Imagecheck_engine check_engine(583, 11, 52, 34, true, 0xFFFFFFFFU, 0U, nullptr, check_engine_d3 );
static Imagehight_beam hight_beam(1390, 11, 48, 30, true, 0xFFFFFFFFU, 0U, nullptr, hight_beam_08 );
static Imageautomatic_high_beam automatic_high_beam(1337, 11, 48, 30, true, 0xFFFFFFFFU, 0U, nullptr, automatic_high_beam_ba );
static Imageleft_turn_indicator left_turn_indicator(1835, 654, 46, 50, true, 0xFFFFFFFFU, 0U, nullptr, left_turn_indicator_ef );
static Imageright_turn_indicator right_turn_indicator(38, 654, 46, 50, true, 0xFFFFFFFFU, 0U, nullptr, right_turn_indicator_62 );
static Imagelow_tire_pressure low_tire_pressure(696, 11, 40, 39, true, 0xFFFFFFFFU, 0U, nullptr, low_tire_pressure_3d );
static Imagecoolant_temp coolant_temp(537, 11, 40, 36, true, 0xFFFFFFFFU, 0U, nullptr, coolant_temp_05 );
static Imagelow_oil_pressure low_oil_pressure(468, 11, 62, 27, true, 0xFFFFFFFFU, 0U, nullptr, low_oil_pressure_cd );
static Imagegeneral_purpose_fault general_purpose_fault(424, 11, 41, 38, true, 0xFFFFFFFFU, 0U, nullptr, general_purpose_fault_c6 );
static Imagevehicle_hold_control vehicle_hold_control(1233, 11, 49, 40, true, 0xFFFFFFFFU, 0U, nullptr, vehicle_hold_control_46 );
static Imagetraction_control_0 traction_control_0(1607, 10, 50, 40, true, 0xFFFFFFFFU, 0U, nullptr, traction_control_fault_3f );
static Imageheated_grips_fault heated_grips_fault(1283, 9, 51, 38, true, 0xFFFFFFFFU, 0U, nullptr, heated_grips_fault_6a );
static Imageheated_grips_3 heated_grips_3(1283, 9, 51, 49, true, 0xFFFFFFFFU, 0U, nullptr, heated_grips_3_81 );
static Imageheated_grips_2 heated_grips_2(1283, 9, 51, 49, true, 0xFFFFFFFFU, 0U, nullptr, heated_grips_2_80 );
static Imageheated_grips_1 heated_grips_1(1283, 9, 51, 49, true, 0xFFFFFFFFU, 0U, nullptr, heated_grips_1_7f );
static Imageheated_grips_0 heated_grips_0(1283, 9, 51, 49, true, 0xFFFFFFFFU, 0U, nullptr, heated_grips_0_7e );
static Itemshmi_region_1 shmi_region_1(0, 0, 1, 1, true, 0xFFFFFFFFU, 4U, static_cast<const ux_safehmi_item **>(lc_childlist_shmi_region_1), sHMI_ObjType::eItem);
static Imagelow_battery_voltage low_battery_voltage(1653, 11, 48, 33, true, 0xFFFFFFFFU, 0U, nullptr, low_battery_voltage_fd );
static Imageabs_0 abs_0(1547, 10, 49, 40, true, 0xFFFFFFFFU, 0U, nullptr, abs_36 );
static Imagetraction_control_fault traction_control_fault(1599, 10, 50, 40, true, 0xFFFFFFFFU, 0U, nullptr, traction_control_fault_3f );
static Imageload_shed load_shed(1653, 2, 53, 46, true, 0xFFFFFFFFU, 0U, nullptr, load_shed_a3 );

ux_safehmi_item const * lc_childlist_root[25U] = 
{
 &ride_modes,
 &icon_aux,
 &turbine,
 &parking_brake,
 &aux_lights,
 &rear_fog_light,
 &low_fuel,
 &service_interval,
 &check_engine,
 &hight_beam,
 &automatic_high_beam,
 &left_turn_indicator,
 &right_turn_indicator,
 &low_tire_pressure,
 &coolant_temp,
 &low_oil_pressure,
 &general_purpose_fault,
 &vehicle_hold_control,
 &traction_control_0,
 &heated_grips_fault,
 &heated_grips_3,
 &heated_grips_2,
 &heated_grips_1,
 &heated_grips_0,
 &shmi_region_1
 
};

ux_safehmi_item const * lc_childlist_ride_modes[29U] = 
{
 &road_active,
 &road_inactive,
 &road_req,
 &sport_req,
 &sport_inactive,
 &sport_active,
 &offroad_req,
 &offroad_override_req,
 &offroad_override_active,
 &offroad_inactive,
 &offroad_active,
 &custom_offroad_req,
 &custom_offroad_override_req,
 &custom_offroad_override_active,
 &custom_offroad_inactive,
 &custom_offroad_active,
 &customa_req,
 &customa_inactive,
 &customa_active,
 &customb_req,
 &customb_inactive,
 &customb_active,
 &rain_req,
 &rain_inactive,
 &rain_active,
 &eco_req,
 &eco_inactive,
 &eco_active,
 &error_mode_0
 
};

ux_safehmi_item const * lc_childlist_shmi_region_1[4U] = 
{
 &low_battery_voltage,
 &abs_0,
 &traction_control_fault,
 &load_shed
 
};



/*============================================================================
** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/


int32_t GetItemX(const SHMI_ELEMENTS assetID)
{
	int32_t value;
	switch(assetID)
	{
		case SHMI_ELEMENTS::SHMI_RIDE_MODES:
		{
			value = ride_modes.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_ROAD_ACTIVE:
		{
			value = road_active.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_ROAD_INACTIVE:
		{
			value = road_inactive.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_ROAD_REQ:
		{
			value = road_req.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_SPORT_REQ:
		{
			value = sport_req.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_SPORT_INACTIVE:
		{
			value = sport_inactive.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_SPORT_ACTIVE:
		{
			value = sport_active.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_REQ:
		{
			value = offroad_req.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_OVERRIDE_REQ:
		{
			value = offroad_override_req.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_OVERRIDE_ACTIVE:
		{
			value = offroad_override_active.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_INACTIVE:
		{
			value = offroad_inactive.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_ACTIVE:
		{
			value = offroad_active.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_REQ:
		{
			value = custom_offroad_req.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_OVERRIDE_REQ:
		{
			value = custom_offroad_override_req.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_OVERRIDE_ACTIVE:
		{
			value = custom_offroad_override_active.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_INACTIVE:
		{
			value = custom_offroad_inactive.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_ACTIVE:
		{
			value = custom_offroad_active.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMA_REQ:
		{
			value = customa_req.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMA_INACTIVE:
		{
			value = customa_inactive.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMA_ACTIVE:
		{
			value = customa_active.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMB_REQ:
		{
			value = customb_req.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMB_INACTIVE:
		{
			value = customb_inactive.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMB_ACTIVE:
		{
			value = customb_active.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_RAIN_REQ:
		{
			value = rain_req.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_RAIN_INACTIVE:
		{
			value = rain_inactive.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_RAIN_ACTIVE:
		{
			value = rain_active.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_ECO_REQ:
		{
			value = eco_req.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_ECO_INACTIVE:
		{
			value = eco_inactive.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_ECO_ACTIVE:
		{
			value = eco_active.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_ERROR_MODE_0:
		{
			value = error_mode_0.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_ICON_AUX:
		{
			value = icon_aux.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TURBINE:
		{
			value = turbine.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_PARKING_BRAKE:
		{
			value = parking_brake.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_AUX_LIGHTS:
		{
			value = aux_lights.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_REAR_FOG_LIGHT:
		{
			value = rear_fog_light.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOW_FUEL:
		{
			value = low_fuel.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_SERVICE_INTERVAL:
		{
			value = service_interval.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CHECK_ENGINE:
		{
			value = check_engine.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_HIGHT_BEAM:
		{
			value = hight_beam.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_AUTOMATIC_HIGH_BEAM:
		{
			value = automatic_high_beam.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_LEFT_TURN_INDICATOR:
		{
			value = left_turn_indicator.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_RIGHT_TURN_INDICATOR:
		{
			value = right_turn_indicator.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOW_TIRE_PRESSURE:
		{
			value = low_tire_pressure.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_COOLANT_TEMP:
		{
			value = coolant_temp.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOW_OIL_PRESSURE:
		{
			value = low_oil_pressure.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GENERAL_PURPOSE_FAULT:
		{
			value = general_purpose_fault.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_VEHICLE_HOLD_CONTROL:
		{
			value = vehicle_hold_control.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TRACTION_CONTROL_0:
		{
			value = traction_control_0.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_FAULT:
		{
			value = heated_grips_fault.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_3:
		{
			value = heated_grips_3.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_2:
		{
			value = heated_grips_2.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_1:
		{
			value = heated_grips_1.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_0:
		{
			value = heated_grips_0.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_SHMI_REGION_1:
		{
			value = shmi_region_1.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOW_BATTERY_VOLTAGE:
		{
			value = low_battery_voltage.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_ABS_0:
		{
			value = abs_0.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TRACTION_CONTROL_FAULT:
		{
			value = traction_control_fault.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOAD_SHED:
		{
			value = load_shed.GetX();
			break;
		}
		default:{/*Do Nothing*/ value = 0; break;}
	}
	return value;
}

int32_t GetItemY(const SHMI_ELEMENTS assetID)
{
	int32_t value;
	switch(assetID)
	{
		case SHMI_ELEMENTS::SHMI_RIDE_MODES:
		{
			value = ride_modes.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_ROAD_ACTIVE:
		{
			value = road_active.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_ROAD_INACTIVE:
		{
			value = road_inactive.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_ROAD_REQ:
		{
			value = road_req.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_SPORT_REQ:
		{
			value = sport_req.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_SPORT_INACTIVE:
		{
			value = sport_inactive.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_SPORT_ACTIVE:
		{
			value = sport_active.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_REQ:
		{
			value = offroad_req.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_OVERRIDE_REQ:
		{
			value = offroad_override_req.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_OVERRIDE_ACTIVE:
		{
			value = offroad_override_active.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_INACTIVE:
		{
			value = offroad_inactive.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_ACTIVE:
		{
			value = offroad_active.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_REQ:
		{
			value = custom_offroad_req.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_OVERRIDE_REQ:
		{
			value = custom_offroad_override_req.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_OVERRIDE_ACTIVE:
		{
			value = custom_offroad_override_active.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_INACTIVE:
		{
			value = custom_offroad_inactive.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_ACTIVE:
		{
			value = custom_offroad_active.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMA_REQ:
		{
			value = customa_req.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMA_INACTIVE:
		{
			value = customa_inactive.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMA_ACTIVE:
		{
			value = customa_active.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMB_REQ:
		{
			value = customb_req.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMB_INACTIVE:
		{
			value = customb_inactive.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMB_ACTIVE:
		{
			value = customb_active.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_RAIN_REQ:
		{
			value = rain_req.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_RAIN_INACTIVE:
		{
			value = rain_inactive.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_RAIN_ACTIVE:
		{
			value = rain_active.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_ECO_REQ:
		{
			value = eco_req.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_ECO_INACTIVE:
		{
			value = eco_inactive.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_ECO_ACTIVE:
		{
			value = eco_active.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_ERROR_MODE_0:
		{
			value = error_mode_0.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_ICON_AUX:
		{
			value = icon_aux.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TURBINE:
		{
			value = turbine.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_PARKING_BRAKE:
		{
			value = parking_brake.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_AUX_LIGHTS:
		{
			value = aux_lights.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_REAR_FOG_LIGHT:
		{
			value = rear_fog_light.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOW_FUEL:
		{
			value = low_fuel.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_SERVICE_INTERVAL:
		{
			value = service_interval.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CHECK_ENGINE:
		{
			value = check_engine.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_HIGHT_BEAM:
		{
			value = hight_beam.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_AUTOMATIC_HIGH_BEAM:
		{
			value = automatic_high_beam.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_LEFT_TURN_INDICATOR:
		{
			value = left_turn_indicator.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_RIGHT_TURN_INDICATOR:
		{
			value = right_turn_indicator.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOW_TIRE_PRESSURE:
		{
			value = low_tire_pressure.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_COOLANT_TEMP:
		{
			value = coolant_temp.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOW_OIL_PRESSURE:
		{
			value = low_oil_pressure.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GENERAL_PURPOSE_FAULT:
		{
			value = general_purpose_fault.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_VEHICLE_HOLD_CONTROL:
		{
			value = vehicle_hold_control.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TRACTION_CONTROL_0:
		{
			value = traction_control_0.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_FAULT:
		{
			value = heated_grips_fault.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_3:
		{
			value = heated_grips_3.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_2:
		{
			value = heated_grips_2.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_1:
		{
			value = heated_grips_1.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_0:
		{
			value = heated_grips_0.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_SHMI_REGION_1:
		{
			value = shmi_region_1.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOW_BATTERY_VOLTAGE:
		{
			value = low_battery_voltage.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_ABS_0:
		{
			value = abs_0.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TRACTION_CONTROL_FAULT:
		{
			value = traction_control_fault.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOAD_SHED:
		{
			value = load_shed.GetY();
			break;
		}
		default:{/*Do Nothing*/ value = 0; break;}
	}
	return value;
}

bool GetItemVisibility(const SHMI_ELEMENTS assetID)
{
	bool value;
	switch(assetID)
	{
		case SHMI_ELEMENTS::SHMI_RIDE_MODES:
		{
			value = ride_modes.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_ROAD_ACTIVE:
		{
			value = road_active.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_ROAD_INACTIVE:
		{
			value = road_inactive.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_ROAD_REQ:
		{
			value = road_req.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_SPORT_REQ:
		{
			value = sport_req.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_SPORT_INACTIVE:
		{
			value = sport_inactive.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_SPORT_ACTIVE:
		{
			value = sport_active.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_REQ:
		{
			value = offroad_req.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_OVERRIDE_REQ:
		{
			value = offroad_override_req.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_OVERRIDE_ACTIVE:
		{
			value = offroad_override_active.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_INACTIVE:
		{
			value = offroad_inactive.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_ACTIVE:
		{
			value = offroad_active.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_REQ:
		{
			value = custom_offroad_req.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_OVERRIDE_REQ:
		{
			value = custom_offroad_override_req.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_OVERRIDE_ACTIVE:
		{
			value = custom_offroad_override_active.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_INACTIVE:
		{
			value = custom_offroad_inactive.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_ACTIVE:
		{
			value = custom_offroad_active.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMA_REQ:
		{
			value = customa_req.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMA_INACTIVE:
		{
			value = customa_inactive.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMA_ACTIVE:
		{
			value = customa_active.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMB_REQ:
		{
			value = customb_req.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMB_INACTIVE:
		{
			value = customb_inactive.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMB_ACTIVE:
		{
			value = customb_active.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_RAIN_REQ:
		{
			value = rain_req.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_RAIN_INACTIVE:
		{
			value = rain_inactive.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_RAIN_ACTIVE:
		{
			value = rain_active.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_ECO_REQ:
		{
			value = eco_req.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_ECO_INACTIVE:
		{
			value = eco_inactive.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_ECO_ACTIVE:
		{
			value = eco_active.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_ERROR_MODE_0:
		{
			value = error_mode_0.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_ICON_AUX:
		{
			value = icon_aux.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TURBINE:
		{
			value = turbine.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_PARKING_BRAKE:
		{
			value = parking_brake.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_AUX_LIGHTS:
		{
			value = aux_lights.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_REAR_FOG_LIGHT:
		{
			value = rear_fog_light.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOW_FUEL:
		{
			value = low_fuel.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_SERVICE_INTERVAL:
		{
			value = service_interval.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_CHECK_ENGINE:
		{
			value = check_engine.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_HIGHT_BEAM:
		{
			value = hight_beam.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_AUTOMATIC_HIGH_BEAM:
		{
			value = automatic_high_beam.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_LEFT_TURN_INDICATOR:
		{
			value = left_turn_indicator.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_RIGHT_TURN_INDICATOR:
		{
			value = right_turn_indicator.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOW_TIRE_PRESSURE:
		{
			value = low_tire_pressure.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_COOLANT_TEMP:
		{
			value = coolant_temp.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOW_OIL_PRESSURE:
		{
			value = low_oil_pressure.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GENERAL_PURPOSE_FAULT:
		{
			value = general_purpose_fault.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_VEHICLE_HOLD_CONTROL:
		{
			value = vehicle_hold_control.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TRACTION_CONTROL_0:
		{
			value = traction_control_0.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_FAULT:
		{
			value = heated_grips_fault.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_3:
		{
			value = heated_grips_3.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_2:
		{
			value = heated_grips_2.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_1:
		{
			value = heated_grips_1.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_0:
		{
			value = heated_grips_0.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_SHMI_REGION_1:
		{
			value = shmi_region_1.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOW_BATTERY_VOLTAGE:
		{
			value = low_battery_voltage.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_ABS_0:
		{
			value = abs_0.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TRACTION_CONTROL_FAULT:
		{
			value = traction_control_fault.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOAD_SHED:
		{
			value = load_shed.GetVisibility();
			break;
		}
		default:{/*Do Nothing*/ value = false; break;}
	}
	return value;
}

void SetItemX(const SHMI_ELEMENTS assetID, const int32_t p_val)
{
	switch(assetID)
	{
		case SHMI_ELEMENTS::SHMI_RIDE_MODES:
		{
			ride_modes.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_ROAD_ACTIVE:
		{
			road_active.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_ROAD_INACTIVE:
		{
			road_inactive.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_ROAD_REQ:
		{
			road_req.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_SPORT_REQ:
		{
			sport_req.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_SPORT_INACTIVE:
		{
			sport_inactive.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_SPORT_ACTIVE:
		{
			sport_active.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_REQ:
		{
			offroad_req.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_OVERRIDE_REQ:
		{
			offroad_override_req.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_OVERRIDE_ACTIVE:
		{
			offroad_override_active.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_INACTIVE:
		{
			offroad_inactive.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_ACTIVE:
		{
			offroad_active.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_REQ:
		{
			custom_offroad_req.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_OVERRIDE_REQ:
		{
			custom_offroad_override_req.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_OVERRIDE_ACTIVE:
		{
			custom_offroad_override_active.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_INACTIVE:
		{
			custom_offroad_inactive.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_ACTIVE:
		{
			custom_offroad_active.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMA_REQ:
		{
			customa_req.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMA_INACTIVE:
		{
			customa_inactive.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMA_ACTIVE:
		{
			customa_active.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMB_REQ:
		{
			customb_req.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMB_INACTIVE:
		{
			customb_inactive.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMB_ACTIVE:
		{
			customb_active.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_RAIN_REQ:
		{
			rain_req.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_RAIN_INACTIVE:
		{
			rain_inactive.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_RAIN_ACTIVE:
		{
			rain_active.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_ECO_REQ:
		{
			eco_req.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_ECO_INACTIVE:
		{
			eco_inactive.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_ECO_ACTIVE:
		{
			eco_active.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_ERROR_MODE_0:
		{
			error_mode_0.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_ICON_AUX:
		{
			icon_aux.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TURBINE:
		{
			turbine.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_PARKING_BRAKE:
		{
			parking_brake.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_AUX_LIGHTS:
		{
			aux_lights.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_REAR_FOG_LIGHT:
		{
			rear_fog_light.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOW_FUEL:
		{
			low_fuel.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_SERVICE_INTERVAL:
		{
			service_interval.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CHECK_ENGINE:
		{
			check_engine.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_HIGHT_BEAM:
		{
			hight_beam.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_AUTOMATIC_HIGH_BEAM:
		{
			automatic_high_beam.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_LEFT_TURN_INDICATOR:
		{
			left_turn_indicator.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_RIGHT_TURN_INDICATOR:
		{
			right_turn_indicator.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOW_TIRE_PRESSURE:
		{
			low_tire_pressure.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_COOLANT_TEMP:
		{
			coolant_temp.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOW_OIL_PRESSURE:
		{
			low_oil_pressure.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GENERAL_PURPOSE_FAULT:
		{
			general_purpose_fault.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_VEHICLE_HOLD_CONTROL:
		{
			vehicle_hold_control.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TRACTION_CONTROL_0:
		{
			traction_control_0.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_FAULT:
		{
			heated_grips_fault.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_3:
		{
			heated_grips_3.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_2:
		{
			heated_grips_2.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_1:
		{
			heated_grips_1.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_0:
		{
			heated_grips_0.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_SHMI_REGION_1:
		{
			shmi_region_1.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOW_BATTERY_VOLTAGE:
		{
			low_battery_voltage.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_ABS_0:
		{
			abs_0.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TRACTION_CONTROL_FAULT:
		{
			traction_control_fault.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOAD_SHED:
		{
			load_shed.SetX(p_val);
			break;
		}
		default:{/*Do Nothing*/break;}
	}
}

void SetItemY(const SHMI_ELEMENTS assetID, const int32_t p_val)
{
	switch(assetID)
	{
		case SHMI_ELEMENTS::SHMI_RIDE_MODES:
		{
			ride_modes.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_ROAD_ACTIVE:
		{
			road_active.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_ROAD_INACTIVE:
		{
			road_inactive.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_ROAD_REQ:
		{
			road_req.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_SPORT_REQ:
		{
			sport_req.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_SPORT_INACTIVE:
		{
			sport_inactive.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_SPORT_ACTIVE:
		{
			sport_active.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_REQ:
		{
			offroad_req.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_OVERRIDE_REQ:
		{
			offroad_override_req.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_OVERRIDE_ACTIVE:
		{
			offroad_override_active.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_INACTIVE:
		{
			offroad_inactive.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_ACTIVE:
		{
			offroad_active.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_REQ:
		{
			custom_offroad_req.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_OVERRIDE_REQ:
		{
			custom_offroad_override_req.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_OVERRIDE_ACTIVE:
		{
			custom_offroad_override_active.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_INACTIVE:
		{
			custom_offroad_inactive.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_ACTIVE:
		{
			custom_offroad_active.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMA_REQ:
		{
			customa_req.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMA_INACTIVE:
		{
			customa_inactive.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMA_ACTIVE:
		{
			customa_active.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMB_REQ:
		{
			customb_req.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMB_INACTIVE:
		{
			customb_inactive.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMB_ACTIVE:
		{
			customb_active.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_RAIN_REQ:
		{
			rain_req.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_RAIN_INACTIVE:
		{
			rain_inactive.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_RAIN_ACTIVE:
		{
			rain_active.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_ECO_REQ:
		{
			eco_req.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_ECO_INACTIVE:
		{
			eco_inactive.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_ECO_ACTIVE:
		{
			eco_active.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_ERROR_MODE_0:
		{
			error_mode_0.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_ICON_AUX:
		{
			icon_aux.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TURBINE:
		{
			turbine.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_PARKING_BRAKE:
		{
			parking_brake.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_AUX_LIGHTS:
		{
			aux_lights.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_REAR_FOG_LIGHT:
		{
			rear_fog_light.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOW_FUEL:
		{
			low_fuel.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_SERVICE_INTERVAL:
		{
			service_interval.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CHECK_ENGINE:
		{
			check_engine.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_HIGHT_BEAM:
		{
			hight_beam.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_AUTOMATIC_HIGH_BEAM:
		{
			automatic_high_beam.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_LEFT_TURN_INDICATOR:
		{
			left_turn_indicator.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_RIGHT_TURN_INDICATOR:
		{
			right_turn_indicator.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOW_TIRE_PRESSURE:
		{
			low_tire_pressure.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_COOLANT_TEMP:
		{
			coolant_temp.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOW_OIL_PRESSURE:
		{
			low_oil_pressure.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GENERAL_PURPOSE_FAULT:
		{
			general_purpose_fault.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_VEHICLE_HOLD_CONTROL:
		{
			vehicle_hold_control.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TRACTION_CONTROL_0:
		{
			traction_control_0.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_FAULT:
		{
			heated_grips_fault.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_3:
		{
			heated_grips_3.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_2:
		{
			heated_grips_2.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_1:
		{
			heated_grips_1.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_0:
		{
			heated_grips_0.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_SHMI_REGION_1:
		{
			shmi_region_1.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOW_BATTERY_VOLTAGE:
		{
			low_battery_voltage.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_ABS_0:
		{
			abs_0.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TRACTION_CONTROL_FAULT:
		{
			traction_control_fault.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOAD_SHED:
		{
			load_shed.SetY(p_val);
			break;
		}
		default:{/*Do Nothing*/break;}
	}
}

void SetItemVisibility(const SHMI_ELEMENTS assetID, const bool p_val)
{
	switch(assetID)
	{
		case SHMI_ELEMENTS::SHMI_RIDE_MODES:
		{
			ride_modes.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_ROAD_ACTIVE:
		{
			road_active.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_ROAD_INACTIVE:
		{
			road_inactive.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_ROAD_REQ:
		{
			road_req.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_SPORT_REQ:
		{
			sport_req.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_SPORT_INACTIVE:
		{
			sport_inactive.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_SPORT_ACTIVE:
		{
			sport_active.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_REQ:
		{
			offroad_req.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_OVERRIDE_REQ:
		{
			offroad_override_req.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_OVERRIDE_ACTIVE:
		{
			offroad_override_active.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_INACTIVE:
		{
			offroad_inactive.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_OFFROAD_ACTIVE:
		{
			offroad_active.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_REQ:
		{
			custom_offroad_req.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_OVERRIDE_REQ:
		{
			custom_offroad_override_req.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_OVERRIDE_ACTIVE:
		{
			custom_offroad_override_active.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_INACTIVE:
		{
			custom_offroad_inactive.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOM_OFFROAD_ACTIVE:
		{
			custom_offroad_active.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMA_REQ:
		{
			customa_req.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMA_INACTIVE:
		{
			customa_inactive.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMA_ACTIVE:
		{
			customa_active.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMB_REQ:
		{
			customb_req.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMB_INACTIVE:
		{
			customb_inactive.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CUSTOMB_ACTIVE:
		{
			customb_active.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_RAIN_REQ:
		{
			rain_req.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_RAIN_INACTIVE:
		{
			rain_inactive.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_RAIN_ACTIVE:
		{
			rain_active.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_ECO_REQ:
		{
			eco_req.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_ECO_INACTIVE:
		{
			eco_inactive.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_ECO_ACTIVE:
		{
			eco_active.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_ERROR_MODE_0:
		{
			error_mode_0.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_ICON_AUX:
		{
			icon_aux.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TURBINE:
		{
			turbine.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_PARKING_BRAKE:
		{
			parking_brake.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_AUX_LIGHTS:
		{
			aux_lights.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_REAR_FOG_LIGHT:
		{
			rear_fog_light.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOW_FUEL:
		{
			low_fuel.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_SERVICE_INTERVAL:
		{
			service_interval.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_CHECK_ENGINE:
		{
			check_engine.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_HIGHT_BEAM:
		{
			hight_beam.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_AUTOMATIC_HIGH_BEAM:
		{
			automatic_high_beam.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_LEFT_TURN_INDICATOR:
		{
			left_turn_indicator.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_RIGHT_TURN_INDICATOR:
		{
			right_turn_indicator.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOW_TIRE_PRESSURE:
		{
			low_tire_pressure.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_COOLANT_TEMP:
		{
			coolant_temp.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOW_OIL_PRESSURE:
		{
			low_oil_pressure.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GENERAL_PURPOSE_FAULT:
		{
			general_purpose_fault.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_VEHICLE_HOLD_CONTROL:
		{
			vehicle_hold_control.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TRACTION_CONTROL_0:
		{
			traction_control_0.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_FAULT:
		{
			heated_grips_fault.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_3:
		{
			heated_grips_3.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_2:
		{
			heated_grips_2.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_1:
		{
			heated_grips_1.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_HEATED_GRIPS_0:
		{
			heated_grips_0.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_SHMI_REGION_1:
		{
			shmi_region_1.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOW_BATTERY_VOLTAGE:
		{
			low_battery_voltage.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_ABS_0:
		{
			abs_0.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TRACTION_CONTROL_FAULT:
		{
			traction_control_fault.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_LOAD_SHED:
		{
			load_shed.SetVisibility(p_val);
			break;
		}
		default:{/*Do Nothing*/break;}
	}
}

void SetItemFlipbookIndex(const SHMI_ELEMENTS assetID, const int32_t p_val)
{
	switch(assetID)
	{
		case SHMI_ELEMENTS::SHMI_RIDE_MODES:
		{
			ride_modes.SetFlipbookIndex(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_SHMI_REGION_1:
		{
			shmi_region_1.SetFlipbookIndex(p_val);
			break;
		}
		default:{/*Do Nothing*/break;}
	}
}
int32_t GetItemFlipbookIndex(const SHMI_ELEMENTS assetID)
{
	int32_t value = -1;
	switch(assetID)
	{
		case SHMI_ELEMENTS::SHMI_RIDE_MODES:
		{
			value = ride_modes.GetFlipbookIndex();
			break;
		}
		case SHMI_ELEMENTS::SHMI_SHMI_REGION_1:
		{
			value = shmi_region_1.GetFlipbookIndex();
			break;
		}
		default:{/*Do Nothing*/break;}
	}
	return value;
}




}//namespace-UX_SHMI_PLAYER

/*============================================================================
**
**============================================================================
** C M S    R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
** CMS Rev #        Date         By
** CMS Rev X.X      mm/dd/yy     CDSID
**
**============================================================================
**
** CMS Rev 1.0      04-Feb-2016  emanoj1
** Creation.
**
**==========================================================================*/

/* end of file =============================================================*/
