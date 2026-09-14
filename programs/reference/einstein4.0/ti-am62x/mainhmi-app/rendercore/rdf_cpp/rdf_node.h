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
//  Description : classes to describe the graphics project.
//  Created on  : 02-Jan-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef rdf_node_h
#define rdf_node_h


//Include Files ...
#include "rdf_types.h"
#include "rdf_node_type.h"
//Macro Definitions ...

namespace rendercore_engine
{

//Var externs ...
extern rdf_renderstates const mdl_renderstates_render_states;
extern rdf_node const mdl_node_nodes[111];
extern rdf_3dnode const mdl_3dnode_sample_1;
extern rdf_renderstates const mdl_renderstates_render_states_inst1;
extern rdf_3dnode const mdl_3dnode_mainCamera;
extern rdf_3dnode const mdl_3dnode_root;
extern rdf_3dnode const mdl_3dnode_frame_47;
extern rdf_3dnode const mdl_3dnode_frame_47_0;
extern rdf_3dnode const mdl_3dnode_bg;
extern rdf_3dnode const mdl_3dnode_warn_fuel_amber_group;
extern rdf_3dnode const mdl_3dnode_warn_amber_outline;
extern rdf_3dtext_node const mdl_3dtext_node_txt_warn_check_fuel_cap;
extern rdf_3dnode const mdl_3dnode_txt_warn_check_fuel_cap;
extern rdf_3dnode const mdl_3dnode_warn_fuel_cap_amber_icon;
extern rdf_3dnode const mdl_3dnode_vector_42;
extern rdf_3dnode const mdl_3dnode_group;
extern rdf_3dnode const mdl_3dnode_vector_43;
extern rdf_3dnode const mdl_3dnode_vector_44;
extern rdf_3dnode const mdl_3dnode_vector_45;
extern rdf_3dnode const mdl_3dnode_warn_airbag_red_group;
extern rdf_3dnode const mdl_3dnode_warning_red_outline;
extern rdf_3dtext_node const mdl_3dtext_node_txt_check_airbag;
extern rdf_3dnode const mdl_3dnode_txt_check_airbag;
extern rdf_3dnode const mdl_3dnode_wrn_airbag_icon;
extern rdf_3dnode const mdl_3dnode_layer_1_0;
extern rdf_3dnode const mdl_3dnode_vector;
extern rdf_3dnode const mdl_3dnode_vector_0;
extern rdf_3dnode const mdl_3dnode_vector_1;
extern rdf_3dnode const mdl_3dnode_vector_2;
extern rdf_3dnode const mdl_3dnode_vector_3;
extern rdf_3dnode const mdl_3dnode_vector_4;
extern rdf_3dnode const mdl_3dnode_menu_contents;
extern rdf_3dnode const mdl_3dnode_menu_bg;
extern rdf_3dnode const mdl_3dnode_menu_focus_bar;
extern rdf_3dtext_node const mdl_3dtext_node_txt_menu_drive_info;
extern rdf_3dnode const mdl_3dnode_txt_menu_drive_info;
extern rdf_3dtext_node const mdl_3dtext_node_txt_menu_vehicle_info;
extern rdf_3dnode const mdl_3dnode_txt_menu_vehicle_info;
extern rdf_3dtext_node const mdl_3dtext_node_txt_menu_adas;
extern rdf_3dnode const mdl_3dnode_txt_menu_adas;
extern rdf_3dtext_node const mdl_3dtext_node_txt_menu_navigation;
extern rdf_3dnode const mdl_3dnode_txt_menu_navigation;
extern rdf_3dtext_node const mdl_3dtext_node_txt_menu_alert_history;
extern rdf_3dnode const mdl_3dnode_txt_menu_alert_history;
extern rdf_3dtext_node const mdl_3dtext_node_txt_menu_title;
extern rdf_3dnode const mdl_3dnode_txt_menu_title;
extern rdf_3dnode const mdl_3dnode_menu_line_1;
extern rdf_3dnode const mdl_3dnode_menu_line_2;
extern rdf_3dnode const mdl_3dnode_menu_line_3;
extern rdf_3dnode const mdl_3dnode_menu_line_4;
extern rdf_3dnode const mdl_3dnode_ellipse_56;
extern rdf_3dnode const mdl_3dnode_ellipse_57;
extern rdf_3dnode const mdl_3dnode_ellipse_52;
extern rdf_3dnode const mdl_3dnode_ellipse_47;
extern rdf_3dnode const mdl_3dnode_ellipse_59;
extern rdf_3dnode const mdl_3dnode_ellipse_60;
extern rdf_3dnode const mdl_3dnode_ellipse_61;
extern rdf_3dnode const mdl_3dnode_ellipse_55;
extern rdf_3dnode const mdl_3dnode_ellipse_58;
extern rdf_3dnode const mdl_3dnode_ellipse_49;
extern rdf_3dnode const mdl_3dnode_ellipse_53;
extern rdf_3dnode const mdl_3dnode_ellipse_51;
extern rdf_3dnode const mdl_3dnode_vector_58;
extern rdf_3dnode const mdl_3dnode_vector_59;
extern rdf_3dnode const mdl_3dnode_vector_56;
extern rdf_3dnode const mdl_3dnode_vector_61;
extern rdf_3dnode const mdl_3dnode_vector_57;
extern rdf_3dnode const mdl_3dnode_vector_60;
extern rdf_3dtext_node const mdl_3dtext_node_txt_digital_speedo_day;
extern rdf_3dnode const mdl_3dnode_txt_digital_speedo_day;
extern rdf_3dtext_node const mdl_3dtext_node_txt_digital_speedo_day_0;
extern rdf_3dnode const mdl_3dnode_txt_digital_speedo_day_0;
extern rdf_3dtext_node const mdl_3dtext_node_txt_digital_speedo_day_1;
extern rdf_3dnode const mdl_3dnode_txt_digital_speedo_day_1;
extern rdf_3dtext_node const mdl_3dtext_node_txt_main_digital_speedo;
extern rdf_3dnode const mdl_3dnode_txt_main_digital_speedo;
extern rdf_3dtext_node const mdl_3dtext_node_txt_digital_speedo_day_3;
extern rdf_3dnode const mdl_3dnode_txt_digital_speedo_day_3;
extern rdf_3dtext_node const mdl_3dtext_node_txt_digital_speedo_day_4;
extern rdf_3dnode const mdl_3dnode_txt_digital_speedo_day_4;
extern rdf_3dtext_node const mdl_3dtext_node_txt_digital_speedo_day_5;
extern rdf_3dnode const mdl_3dnode_txt_digital_speedo_day_5;
extern rdf_3dnode const mdl_3dnode_group_24;
extern rdf_3dnode const mdl_3dnode_fuel_icon_5_1;
extern rdf_3dnode const mdl_3dnode_polygon_27;
extern rdf_3dnode const mdl_3dnode_ellipse_56_0;
extern rdf_3dnode const mdl_3dnode_ellipse_57_0;
extern rdf_3dnode const mdl_3dnode_ellipse_52_0;
extern rdf_3dnode const mdl_3dnode_ellipse_47_0;
extern rdf_3dnode const mdl_3dnode_ellipse_59_0;
extern rdf_3dnode const mdl_3dnode_ellipse_60_0;
extern rdf_3dnode const mdl_3dnode_ellipse_61_0;
extern rdf_3dnode const mdl_3dnode_ellipse_55_0;
extern rdf_3dnode const mdl_3dnode_ellipse_62;
extern rdf_3dnode const mdl_3dnode_ellipse_49_0;
extern rdf_3dnode const mdl_3dnode_ellipse_53_0;
extern rdf_3dnode const mdl_3dnode_ellipse_51_0;
extern rdf_3dnode const mdl_3dnode_vector_58_0;
extern rdf_3dnode const mdl_3dnode_vector_59_0;
extern rdf_3dnode const mdl_3dnode_vector_56_0;
extern rdf_3dnode const mdl_3dnode_vector_61_0;
extern rdf_3dnode const mdl_3dnode_vector_57_0;
extern rdf_3dnode const mdl_3dnode_vector_60_0;
extern rdf_3dtext_node const mdl_3dtext_node_txt_digital_speedo_day_6;
extern rdf_3dnode const mdl_3dnode_txt_digital_speedo_day_6;
extern rdf_3dtext_node const mdl_3dtext_node_txt_digital_speedo_day_7;
extern rdf_3dnode const mdl_3dnode_txt_digital_speedo_day_7;
extern rdf_3dtext_node const mdl_3dtext_node_txt_gear_value;
extern rdf_3dnode const mdl_3dnode_txt_gear_value;
extern rdf_3dtext_node const mdl_3dtext_node_txt_tacho_unit;
extern rdf_3dnode const mdl_3dnode_txt_tacho_unit;
extern rdf_3dtext_node const mdl_3dtext_node_txt_gear_title;
extern rdf_3dnode const mdl_3dnode_txt_gear_title;
extern rdf_3dtext_node const mdl_3dtext_node_txt_digital_speedo_day_17;
extern rdf_3dnode const mdl_3dnode_txt_digital_speedo_day_17;
extern rdf_3dtext_node const mdl_3dtext_node_txt_digital_speedo_day_18;
extern rdf_3dnode const mdl_3dnode_txt_digital_speedo_day_18;
extern rdf_3dnode const mdl_3dnode_default;
extern rdf_3dnode const mdl_3dnode_default_0;
extern rdf_3dnode const mdl_3dnode_vector_inst1;
extern rdf_3dnode const mdl_3dnode_vector_0_inst1;
extern rdf_3dnode const mdl_3dnode_vector_1_inst1;
extern rdf_3dnode const mdl_3dnode_vector_2_inst1;
extern rdf_3dtext_node const mdl_3dtext_node_txt_odo_unit;
extern rdf_3dnode const mdl_3dnode_txt_odo_unit;
extern rdf_3dtext_node const mdl_3dtext_node_txt_odo_value;
extern rdf_3dnode const mdl_3dnode_txt_odo_value;
extern rdf_3dtext_node const mdl_3dtext_node_txt_odo_title;
extern rdf_3dnode const mdl_3dnode_txt_odo_title;
extern rdf_3dtext_node const mdl_3dtext_node_txt_dte_title;
extern rdf_3dnode const mdl_3dnode_txt_dte_title;
extern rdf_3dtext_node const mdl_3dtext_node_txt_dte_value;
extern rdf_3dnode const mdl_3dnode_txt_dte_value;
extern rdf_3dtext_node const mdl_3dtext_node_txt_dte_unit;
extern rdf_3dnode const mdl_3dnode_txt_dte_unit;
extern rdf_3dtext_node const mdl_3dtext_node_txt_digital_speedo_day_25;
extern rdf_3dnode const mdl_3dnode_txt_digital_speedo_day_25;
extern rdf_3dtext_node const mdl_3dtext_node_txt_digital_speedo_day_26;
extern rdf_3dnode const mdl_3dnode_txt_digital_speedo_day_26;
extern rdf_3dtext_node const mdl_3dtext_node_txt_digital_speedo_day_27;
extern rdf_3dnode const mdl_3dnode_txt_digital_speedo_day_27;
extern rdf_3dtext_node const mdl_3dtext_node_txt_digital_speedo_day_28;
extern rdf_3dnode const mdl_3dnode_txt_digital_speedo_day_28;
extern rdf_3dtext_node const mdl_3dtext_node_txt_digital_speedo_day_29;
extern rdf_3dnode const mdl_3dnode_txt_digital_speedo_day_29;
extern rdf_3dtext_node const mdl_3dtext_node_txt_digital_speedo_day_30;
extern rdf_3dnode const mdl_3dnode_txt_digital_speedo_day_30;
extern rdf_3dtext_node const mdl_3dtext_node_txt_tacho_value;
extern rdf_3dnode const mdl_3dnode_txt_tacho_value;

//Methods ...

}

#endif
