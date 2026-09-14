///////////////////////////////////////////////////////////////////////////////
//
//                     CONFIDENTIAL VISTEON CORPORATION
//
// This is an unpublished work of authorship, which contains trade secrets,
// created in 2018. Visteon Corporation owns all rights to this work and
// intends to maintain it in confidence to preserve its trade secret status.
// Visteon Corporation reserves the right, under the copyright laws of the
// United States or those of any other country that may have jurisdiction,
// to protect this work as an unpublished work, in the event of an
// inadvertent or deliberate unauthorized publication. Visteon Corporation
// also reserves its rights under all copyright laws to protect this work as
// a published work, when appropriate. Those having access to this work may
// not copy it, use it, modify it or disclose the information contained in
// it without the written authorization of Visteon Corporation.
//
// @file      rcore_engine_app.cpp
// @author    bhariha1
// @brief     Update of rcore_engine_app.cpp.
// @date      Jun 7, 2024
///////////////////////////////////////////////////////////////////////////////

#include <iostream>         
#include <iomanip>
#include <thread>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/ipc.h>
#include "gfx3d_scg.h"
#include "rdf_project.h"
#include "rdf_scg_project.h"
#include "rc_platform_common.h"
#include "rc_utils.h"
#include "ResourceLoader.hpp"
#include "rc_application_window.h"
#include "rcore_engine_app.hpp"
#include "rdf_scg_font.h"
#include "rc_monotype_engine.h"
#include "gfx3d_types.h"
#include "gfx3d_behaviour.h"
#include "rc_localization.h"
#include "gfx3d_scg_project.h"
#include "dk_runtime_types.h"
#include <vector>
#include <string>
#include <chrono>
#if defined BOOT_KPI_LOG_EN
#include "boot_kpi_a53_linux.h"
#endif /*BOOT_KPI_LOG_EN*/

using namespace rendercore_engine;
using namespace rcore_engine_app;
using namespace dk;
using namespace runtime;


namespace rcore_engine_app
{
	gfx3d_scg_display* m_display = nullptr;
	bool userQuit = false;

	gfx3d_scg_display* getDisplay()
	{
		return m_display;
	}
}

//===========================================================================
//	Function: set_node_text(std::string node_id, rc_string data)
//
//	Description: This method updated the RC Text node with the given text.
//
//	Parameters: 
//		a. node_id	- Node ID for which the text has to be updated.
//		b. data		- String of type rc_wstring.
//===========================================================================
void set_node_text(rdf_scenenodes_e node_id, rc_string data)
{
	gfx3d_scg_node* rc_node = nullptr;
	gfx3d_scg_3dtext_node* rc_text_node = nullptr;
	if(node_id != rdf_scenenodes_e::Invalid)
	{
		rc_node = m_display->GetNode(static_cast<size_t>(node_id));
		if (rc_node != nullptr)
		{
			rc_text_node = dynamic_cast<gfx3d_scg_3dtext_node*>(rc_node);
			if(rc_text_node != nullptr)
			{
				rc_text_node->SetText(data);
			}
		}
	}
}
//===========================================================================
//	Function: set_node_visibility(std::string node_id,bool data)
//
//	Description: This method sets/clears the visibility of the given Node.
//
//	Parameters: 
//		a. node_id	- Node ID for which the visibility property is controlled.
//		b. data		- True/False
//===========================================================================
void set_node_visibility(rdf_scenenodes_e node_id, bool data)
{
	gfx3d_scg_node* rc_node = nullptr;
	if(node_id != rdf_scenenodes_e::Invalid)
	{
		rc_node = m_display->GetNode(static_cast<size_t>(node_id));
		if (rc_node != nullptr)
		{
			rc_node->SetVisible(data);
		}
	}
}

void ui_app_process(void)
{
	rdf_scenenodes_e fl_node_id = rendercore_engine::rdf_scenenodes_e::Count;
	rdf_scenenodes_e fl_airbag_node_id = rendercore_engine::rdf_scenenodes_e::Count;
	rdf_scenenodes_e fl_fuellid_node_id = rendercore_engine::rdf_scenenodes_e::Count;
	bool data = false;
	static int fl_toggle_flag = 0;
	rc_string fl_digital_speed = "100";
	rc_string fl_tacho_value = "3";
	rc_string fl_gear_value = "P";

/* Speedo and Tacho */
	MainHMIInterface *obj_MainHMIInterface = MainHMIInterface::getInstance();
	fl_digital_speed = std::to_string(obj_MainHMIInterface->GetSpeedData());
	fl_tacho_value = std::to_string(obj_MainHMIInterface->GetTachoData());

	rdf_scenenodes_e fl_speed_node_id = rendercore_engine::rdf_scenenodes_e::sample_100_txt_main_digital_speedo;
	rdf_scenenodes_e fl_tacho_node_id = rendercore_engine::rdf_scenenodes_e::sample_100_txt_tacho_value;

	set_node_text(fl_speed_node_id, fl_digital_speed);
	set_node_text(fl_tacho_node_id, fl_tacho_value);	

/* Warning Display */  //wrnId: 1=> airbag wrnID: 2=> fuel lid
		fl_airbag_node_id = rendercore_engine::rdf_scenenodes_e::sample_100_warn_airbag_red_group;
		fl_fuellid_node_id = rendercore_engine::rdf_scenenodes_e::sample_100_menu_contents;

		if(obj_MainHMIInterface->airbagWarn_sts_bool == 1)
		{
			data = obj_MainHMIInterface->airbagWarn_sts_bool;
			set_node_visibility(fl_airbag_node_id, data);
			set_node_visibility(fl_fuellid_node_id, !data);
		}
		else if(obj_MainHMIInterface->fuelLidWarn_sts_bool == 1)
		{
			data = obj_MainHMIInterface->fuelLidWarn_sts_bool;
			set_node_visibility(fl_fuellid_node_id, data);
			set_node_visibility(fl_airbag_node_id, !data);
		}
		else
		{
			data = 0;
			set_node_visibility(fl_airbag_node_id, data);
			set_node_visibility(fl_fuellid_node_id, data);
		 	fl_node_id = rendercore_engine::rdf_scenenodes_e::sample_100_menu_contents; //26
		 	data = true;
		 	set_node_visibility(fl_node_id, data);
		}

/*Gear PositionDisplay*/	
	switch(obj_MainHMIInterface->gearPostion_U8) // Gear value mapping: 0->P ,1 ->R, 2->N, 3->D, 4->L
	{
		case 0:
				fl_gear_value = "P";
				break;
		case 1:
				fl_gear_value = "R";
				break;
		case 2:
				fl_gear_value = "N";
				break;
		case 3:
				fl_gear_value = "D";
				break;
		case 4:
				fl_gear_value = "L";
				break;
		default:
				fl_gear_value = "-";
				break;													
	}
	rdf_scenenodes_e fl_gear_node_id = rendercore_engine::rdf_scenenodes_e::sample_100_txt_gear_value;
	set_node_text(fl_gear_node_id, fl_gear_value);
#if 0
/* Telltale display */
	rdf_scenenodes_e fl_airbag_tt_node_id = rendercore_engine::rdf_scenenodes_e::sample_100_tt_check_airbag;
	rdf_scenenodes_e fl_leftTurnIndicator_node_id = rendercore_engine::rdf_scenenodes_e::sample_100_tt_left_indicator;
	rdf_scenenodes_e fl_rightTurnIndicator_node_id = rendercore_engine::rdf_scenenodes_e::sample_100_tt_right_indicator;

	set_node_visibility(fl_airbag_tt_node_id, obj_MainHMIInterface->tt_mask[0]); //airbag tt; 0 => OFF; 1 => ON
	set_node_visibility(fl_airbag_tt_node_id, obj_MainHMIInterface->tt_mask[1]); //left turn  tt
	set_node_visibility(fl_airbag_tt_node_id, obj_MainHMIInterface->tt_mask[2]); //right turn  tt
#endif
}

//===========================================================================
//	Function: main(void)
//
//	Description: Main function.
//
//	Parameters: 
//		a. argc - not used
//		b. argv - not used
//===========================================================================
int32_t rendercoreMain(void)
{
	int32_t fl_return_status = EXIT_SUCCESS;
	char resourcepath[MAX_PATH] = "/app/usr/bin/asset/resources/";
	MainHMIInterface *obj_MainHMIInterface = MainHMIInterface::getInstance();
	uint8_t fl_power_state = obj_MainHMIInterface->GetPowerState();
	#if defined BOOT_KPI_LOG_EN
	static bool firstRender = true;
	#endif
	rdf_scg_project rdf_scg_project_((rdf_project *)&mdl_project, resourcepath);

	const uint32_t th_count = rdf_scg_project_.GetMaxThreadCount();
	if (th_count > static_cast<uint32_t>(2))
	{
		rdf_scg_project_.SetMaxThreadCount(static_cast<uint32_t>(2));
	}

	m_display = rdf_scg_project_.GetDisplay(0);

	if (m_display != nullptr)
	{
		m_display->Create(std::shared_ptr<rc_platform_window>(new rc_application_window()));
		m_display->LoadScene(0, MdlSceneLoadMode::Additive, MdlAssetLoadMode::Asynchronous);

		do
		{
			fl_power_state = obj_MainHMIInterface->GetPowerState();
			if (fl_power_state == ESystemState_FullRun)
			{
				#if defined BOOT_KPI_LOG_EN
				if(firstRender)
				{
					BOOT_KPI_LOG(KPI_ID_GIP_MAINHMI_BEFORE_FIRST_RENDER, "MainHmiBeforeFR");
				}
				#endif
				ui_app_process();
				rdf_scg_project_.Render();
				#if defined BOOT_KPI_LOG_EN
				if(firstRender)
				{
					BOOT_KPI_LOG(KPI_ID_GIP_MAINHMI_AFTER_FIRST_RENDER, "MainHmiAfterFR");
				}
				#endif
				rdf_scg_project_.WaitForRenderDone();
				#if defined BOOT_KPI_LOG_EN
				if(firstRender)
				{
					BOOT_KPI_LOG(KPI_ID_GIP_MAINHMI_WAIT_FOR_RENDER_DONE, "MainHmiWtRenDone");
					firstRender = false;
				}
				#endif
			}
		} while (userQuit == false);
	}
	else
	{
		printf(" m_display is null \n");
	}

	printf(" return from main function \n ");
	return (fl_return_status);
}

MainHMIInterface* MainHMIInterface::instance = nullptr;

MainHMIInterface::MainHMIInterface()
{
	speedValue_S32 = 0;
	tachoValue_S32 = 0;
}

void MainHMIInterface::SetSpeedData(int32_t data)
{
	speedValue_S32 = data;
}

int32_t MainHMIInterface::GetSpeedData(void)
{
	return speedValue_S32;
}
uint8_t MainHMIInterface::GetPowerState(void)
{
	return powerState;
}

void MainHMIInterface::SetTachoData(int32_t data)
{
	tachoValue_S32 = data;
}

int32_t MainHMIInterface::GetTachoData(void)
{
	return tachoValue_S32;
}

void MainHMIInterface::SetAirbagWarn(uint8_t data)
{
	airbagWarn_sts_bool = data;
}

void MainHMIInterface::SetFuelLidWarn(uint8_t data)
{
	fuelLidWarn_sts_bool = data;
}

void MainHMIInterface::SetGearPosition(uint8_t data)
{
	gearPostion_U8 = data;
}

void MainHMIInterface::SetTT_data(uint8_t arr[15])
{
	for (int8_t i = 0; i < sizeof(arr); i++) //0 ->Airbag, 1-> LeftINdicator, 2-> Right Indicator
	{
		tt_mask[i] = arr[i];
	}
}
void MainHMIInterface::SetPowerState(uint8_t data)
{
	powerState = data;
}
/*============================================================================
 **============================================================================*/
/*** R E V I S I O N    N O T E S**/
/**----------------------------------------------------------------------------
 **  For each change to this file, be sure to record:
 **  1.  who made the change and when the change was made
 **  2.  why the change was made and the intended result
 **----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
Date              : 16-Apr-2025
CDSID             : braj
Traceability      : PE4TI29141-7910: MainHmi Initial integration with Einstein4.0
-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
Date              : 17-June-2025
CDSID             : braj
Traceability      : PE4TI29141-8804: Integrated UCL callbacks function using DK logic to fetch input values from VIP app to GIP
-----------------------------------------------------------------------------*/

/* end of file */