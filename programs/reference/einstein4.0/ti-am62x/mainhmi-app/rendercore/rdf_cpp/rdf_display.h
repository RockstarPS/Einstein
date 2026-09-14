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
#ifndef rdf_display_h
#define rdf_display_h


//Include Files ...
#include "rdf_types.h"
#include "rdf_rtarget.h"
#include "rdf_accessor.h"
#include "rdf_buffer.h"
#include "rdf_bufferView.h"
#include "rdf_material.h"
#include "rdf_mesh.h"
#include "rdf_texture.h"
#include "rdf_image.h"
#include "rdf_sampler.h"
#include "rdf_camera.h"
#include "rdf_renderpass.h"
#include "rdf_scene.h"
#include "rdf_node.h"
#include "rdf_display_type.h"
//Macro Definitions ...

namespace rendercore_engine
{
enum class rdf_camera_id_e
{
  cameras_d0_mainCamera=0
 ,Count=1
 ,Invalid=-1
};
enum class rdf_material_id_e
{
  materials_d0_gltfplus_mat_frame_47_0=0
 ,materials_d0_gltfplus_mat_bg=1
 ,materials_d0_gltfplus_mat_rectangle_394=2
 ,materials_d0_RenderCore_RC_Text=3
 ,materials_d0_gltfplus_mat_vector_42=4
 ,materials_d0_gltfplus_mat_vector_43=5
 ,materials_d0_gltfplus_mat_vector_44=6
 ,materials_d0_gltfplus_mat_vector_45=7
 ,materials_d0_gltfplus_mat_rectangle_394_1=8
 ,materials_d0_RenderCore_RC_Text_1=9
 ,materials_d0_gltfplus_mat_layer_1_0=10
 ,materials_d0_gltfplus_mat_vector=11
 ,materials_d0_gltfplus_mat_vector_0=12
 ,materials_d0_gltfplus_mat_vector_1=13
 ,materials_d0_gltfplus_mat_vector_2=14
 ,materials_d0_gltfplus_mat_vector_3=15
 ,materials_d0_gltfplus_mat_vector_4=16
 ,materials_d0_gltfplus_mat_rectangle_395=17
 ,materials_d0_gltfplus_mat_rectangle_396=18
 ,materials_d0_RenderCore_RC_Text_2=19
 ,materials_d0_RenderCore_RC_Text_3=20
 ,materials_d0_RenderCore_RC_Text_4=21
 ,materials_d0_RenderCore_RC_Text_5=22
 ,materials_d0_RenderCore_RC_Text_6=23
 ,materials_d0_RenderCore_RC_Text_7=24
 ,materials_d0_gltfplus_mat_line_17=25
 ,materials_d0_gltfplus_mat_line_18=26
 ,materials_d0_gltfplus_mat_ellipse_56=27
 ,materials_d0_gltfplus_mat_ellipse_57=28
 ,materials_d0_gltfplus_mat_ellipse_52=29
 ,materials_d0_gltfplus_mat_ellipse_47=30
 ,materials_d0_gltfplus_mat_ellipse_59=31
 ,materials_d0_gltfplus_mat_ellipse_60=32
 ,materials_d0_gltfplus_mat_ellipse_61=33
 ,materials_d0_gltfplus_mat_ellipse_55=34
 ,materials_d0_gltfplus_mat_ellipse_58=35
 ,materials_d0_gltfplus_mat_ellipse_49=36
 ,materials_d0_gltfplus_mat_ellipse_53=37
 ,materials_d0_gltfplus_mat_ellipse_51=38
 ,materials_d0_gltfplus_mat_vector_58=39
 ,materials_d0_gltfplus_mat_vector_59=40
 ,materials_d0_gltfplus_mat_vector_56=41
 ,materials_d0_gltfplus_mat_vector_61=42
 ,materials_d0_gltfplus_mat_vector_57=43
 ,materials_d0_gltfplus_mat_vector_60=44
 ,materials_d0_RenderCore_RC_Text_8=45
 ,materials_d0_RenderCore_RC_Text_9=46
 ,materials_d0_RenderCore_RC_Text_10=47
 ,materials_d0_RenderCore_RC_Text_11=48
 ,materials_d0_RenderCore_RC_Text_12=49
 ,materials_d0_RenderCore_RC_Text_13=50
 ,materials_d0_RenderCore_RC_Text_14=51
 ,materials_d0_gltfplus_mat_fuel_icon_5_1=52
 ,materials_d0_gltfplus_mat_polygon_27=53
 ,materials_d0_gltfplus_mat_ellipse_56_0=54
 ,materials_d0_gltfplus_mat_ellipse_57_0=55
 ,materials_d0_gltfplus_mat_ellipse_52_0=56
 ,materials_d0_gltfplus_mat_ellipse_47_0=57
 ,materials_d0_gltfplus_mat_ellipse_59_0=58
 ,materials_d0_gltfplus_mat_ellipse_60_0=59
 ,materials_d0_gltfplus_mat_ellipse_61_0=60
 ,materials_d0_gltfplus_mat_ellipse_55_0=61
 ,materials_d0_gltfplus_mat_ellipse_62=62
 ,materials_d0_gltfplus_mat_ellipse_49_0=63
 ,materials_d0_gltfplus_mat_ellipse_53_0=64
 ,materials_d0_gltfplus_mat_ellipse_51_0=65
 ,materials_d0_gltfplus_mat_vector_58_0=66
 ,materials_d0_gltfplus_mat_vector_59_0=67
 ,materials_d0_gltfplus_mat_vector_56_0=68
 ,materials_d0_gltfplus_mat_vector_57_0=69
 ,materials_d0_gltfplus_mat_vector_60_0=70
 ,materials_d0_RenderCore_RC_Text_15=71
 ,materials_d0_RenderCore_RC_Text_16=72
 ,materials_d0_RenderCore_RC_Text_17=73
 ,materials_d0_RenderCore_RC_Text_18=74
 ,materials_d0_RenderCore_RC_Text_19=75
 ,materials_d0_RenderCore_RC_Text_20=76
 ,materials_d0_RenderCore_RC_Text_21=77
 ,materials_d0_gltfplus_mat_default_0=78
 ,materials_d0_gltfplus_mat_vector_0_1=80
 ,materials_d0_gltfplus_mat_vector_1_1=81
 ,materials_d0_gltfplus_mat_vector_2_1=82
 ,materials_d0_RenderCore_RC_Text_22=83
 ,materials_d0_RenderCore_RC_Text_23=84
 ,materials_d0_RenderCore_RC_Text_24=85
 ,materials_d0_RenderCore_RC_Text_25=86
 ,materials_d0_RenderCore_RC_Text_26=87
 ,materials_d0_RenderCore_RC_Text_27=88
 ,materials_d0_RenderCore_RC_Text_28=89
 ,materials_d0_RenderCore_RC_Text_29=90
 ,materials_d0_RenderCore_RC_Text_30=91
 ,materials_d0_RenderCore_RC_Text_31=92
 ,materials_d0_RenderCore_RC_Text_32=93
 ,materials_d0_RenderCore_RC_Text_33=94
 ,materials_d0_RenderCore_RC_Text_34=95
 ,Count=96
 ,Invalid=-1
};
enum class rdf_scene_id_e
{
  scenes_d0_sample_1=0
 ,Count=1
 ,Invalid=-1
};
enum class rdf_scenenodes_e
{
  sample_100_sample_1=0
 ,sample_100_mainCamera=1
 ,sample_100_root=2
 ,sample_100_frame_47=3
 ,sample_100_frame_47_0=4
 ,sample_100_bg=5
 ,sample_100_warn_fuel_amber_group=6
 ,sample_100_warn_amber_outline=7
 ,sample_100_txt_warn_check_fuel_cap=8
 ,sample_100_warn_fuel_cap_amber_icon=9
 ,sample_100_vector_42=10
 ,sample_100_group=11
 ,sample_100_vector_43=12
 ,sample_100_vector_44=13
 ,sample_100_vector_45=14
 ,sample_100_warn_airbag_red_group=15
 ,sample_100_warning_red_outline=16
 ,sample_100_txt_check_airbag=17
 ,sample_100_wrn_airbag_icon=18
 ,sample_100_layer_1_0=19
 ,sample_100_vector=20
 ,sample_100_vector_0=21
 ,sample_100_vector_1=22
 ,sample_100_vector_2=23
 ,sample_100_vector_3=24
 ,sample_100_vector_4=25
 ,sample_100_menu_contents=26
 ,sample_100_menu_bg=27
 ,sample_100_menu_focus_bar=28
 ,sample_100_txt_menu_drive_info=29
 ,sample_100_txt_menu_vehicle_info=30
 ,sample_100_txt_menu_adas=31
 ,sample_100_txt_menu_navigation=32
 ,sample_100_txt_menu_alert_history=33
 ,sample_100_txt_menu_title=34
 ,sample_100_menu_line_1=35
 ,sample_100_menu_line_2=36
 ,sample_100_menu_line_3=37
 ,sample_100_menu_line_4=38
 ,sample_100_ellipse_56=39
 ,sample_100_ellipse_57=40
 ,sample_100_ellipse_52=41
 ,sample_100_ellipse_47=42
 ,sample_100_ellipse_59=43
 ,sample_100_ellipse_60=44
 ,sample_100_ellipse_61=45
 ,sample_100_ellipse_55=46
 ,sample_100_ellipse_58=47
 ,sample_100_ellipse_49=48
 ,sample_100_ellipse_53=49
 ,sample_100_ellipse_51=50
 ,sample_100_vector_58=51
 ,sample_100_vector_59=52
 ,sample_100_vector_56=53
 ,sample_100_vector_61=54
 ,sample_100_vector_57=55
 ,sample_100_vector_60=56
 ,sample_100_txt_digital_speedo_day=57
 ,sample_100_txt_digital_speedo_day_0=58
 ,sample_100_txt_digital_speedo_day_1=59
 ,sample_100_txt_main_digital_speedo=60
 ,sample_100_txt_digital_speedo_day_3=61
 ,sample_100_txt_digital_speedo_day_4=62
 ,sample_100_txt_digital_speedo_day_5=63
 ,sample_100_group_24=64
 ,sample_100_fuel_icon_5_1=65
 ,sample_100_polygon_27=66
 ,sample_100_ellipse_56_0=67
 ,sample_100_ellipse_57_0=68
 ,sample_100_ellipse_52_0=69
 ,sample_100_ellipse_47_0=70
 ,sample_100_ellipse_59_0=71
 ,sample_100_ellipse_60_0=72
 ,sample_100_ellipse_61_0=73
 ,sample_100_ellipse_55_0=74
 ,sample_100_ellipse_62=75
 ,sample_100_ellipse_49_0=76
 ,sample_100_ellipse_53_0=77
 ,sample_100_ellipse_51_0=78
 ,sample_100_vector_58_0=79
 ,sample_100_vector_59_0=80
 ,sample_100_vector_56_0=81
 ,sample_100_vector_61_0=82
 ,sample_100_vector_57_0=83
 ,sample_100_vector_60_0=84
 ,sample_100_txt_digital_speedo_day_6=85
 ,sample_100_txt_digital_speedo_day_7=86
 ,sample_100_txt_gear_value=87
 ,sample_100_txt_tacho_unit=88
 ,sample_100_txt_gear_title=89
 ,sample_100_txt_digital_speedo_day_17=90
 ,sample_100_txt_digital_speedo_day_18=91
 ,sample_100_default=92
 ,sample_100_default_0=93
 ,sample_100_vector_5=94
 ,sample_100_vector_0_1=95
 ,sample_100_vector_1_1=96
 ,sample_100_vector_2_1=97
 ,sample_100_txt_odo_unit=98
 ,sample_100_txt_odo_value=99
 ,sample_100_txt_odo_title=100
 ,sample_100_txt_dte_title=101
 ,sample_100_txt_dte_value=102
 ,sample_100_txt_dte_unit=103
 ,sample_100_txt_digital_speedo_day_25=104
 ,sample_100_txt_digital_speedo_day_26=105
 ,sample_100_txt_digital_speedo_day_27=106
 ,sample_100_txt_digital_speedo_day_28=107
 ,sample_100_txt_digital_speedo_day_29=108
 ,sample_100_txt_digital_speedo_day_30=109
 ,sample_100_txt_tacho_value=110
 ,Count=111
 ,Invalid=-1
};
enum class rdf_texture_id_e
{
  textures_d0_frame_47_0=0
 ,textures_d0_bg=1
 ,textures_d0_rectangle_394=2
 ,textures_d0_vector_42=3
 ,textures_d0_vector_43=4
 ,textures_d0_vector_44=5
 ,textures_d0_vector_45=6
 ,textures_d0_rectangle_394_1=7
 ,textures_d0_layer_1_0=8
 ,textures_d0_vector=9
 ,textures_d0_vector_0=10
 ,textures_d0_vector_1=11
 ,textures_d0_vector_2=12
 ,textures_d0_vector_3=13
 ,textures_d0_vector_4=14
 ,textures_d0_rectangle_395=15
 ,textures_d0_rectangle_396=16
 ,textures_d0_line_17=17
 ,textures_d0_line_18=18
 ,textures_d0_ellipse_56=19
 ,textures_d0_ellipse_57=20
 ,textures_d0_ellipse_52=21
 ,textures_d0_ellipse_47=22
 ,textures_d0_ellipse_59=23
 ,textures_d0_ellipse_60=24
 ,textures_d0_ellipse_61=25
 ,textures_d0_ellipse_55=26
 ,textures_d0_ellipse_58=27
 ,textures_d0_ellipse_49=28
 ,textures_d0_ellipse_53=29
 ,textures_d0_ellipse_51=30
 ,textures_d0_vector_58=31
 ,textures_d0_vector_59=32
 ,textures_d0_vector_56=33
 ,textures_d0_vector_61=34
 ,textures_d0_vector_57=35
 ,textures_d0_vector_60=36
 ,textures_d0_fuel_icon_5_1=37
 ,textures_d0_polygon_27=38
 ,textures_d0_ellipse_56_0=39
 ,textures_d0_ellipse_57_0=40
 ,textures_d0_ellipse_52_0=41
 ,textures_d0_ellipse_47_0=42
 ,textures_d0_ellipse_59_0=43
 ,textures_d0_ellipse_60_0=44
 ,textures_d0_ellipse_61_0=45
 ,textures_d0_ellipse_55_0=46
 ,textures_d0_ellipse_62=47
 ,textures_d0_ellipse_49_0=48
 ,textures_d0_ellipse_53_0=49
 ,textures_d0_ellipse_51_0=50
 ,textures_d0_vector_58_0=51
 ,textures_d0_vector_59_0=52
 ,textures_d0_vector_56_0=53
 ,textures_d0_vector_57_0=54
 ,textures_d0_vector_60_0=55
 ,textures_d0_default_0=56
 ,textures_d0_vector_0_1=58
 ,textures_d0_vector_1_1=59
 ,textures_d0_vector_2_1=60
 ,Count=61
 ,Invalid=-1
};

//Var externs ...
extern rdf_display const * const displays[1];
extern rdf_display const mdl_display_DefaultDisplay;

//Methods ...

}

#endif
