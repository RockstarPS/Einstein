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

//Include Files ...
#include "rdf_primitive.h"
//Macro Definitions ...

namespace rendercore_engine
{

//Variable declarations ...
static GLint const mdl_attributes_frame_47_0_attrib_textcoord_array[1] = {1};
static GLint const mdl_attributes_txt_warn_check_fuel_cap_attrib_textcoord_array[1] = {3};

//Class data declarations ...
rdf_attributes const mdl_attributes_frame_47_0_attrib =
{
  127U,
  0,
  -1,
  -1,
  1U,
  0U,
  0U,
  0U,
  mdl_attributes_frame_47_0_attrib_textcoord_array,
  nullptr,
  nullptr,
  nullptr
};
rdf_primitive const mdl_primitive_frame_47_0 =
{
  2,
  0,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_frame_47_0[1]=
{
  &mdl_primitive_frame_47_0
};
rdf_primitive const mdl_primitive_bg =
{
  2,
  1,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_bg[1]=
{
  &mdl_primitive_bg
};
rdf_primitive const mdl_primitive_warn_amber_outline =
{
  2,
  2,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_warn_amber_outline[1]=
{
  &mdl_primitive_warn_amber_outline
};
rdf_attributes const mdl_attributes_txt_warn_check_fuel_cap_attrib =
{
  135U,
  4,
  -1,
  -1,
  1U,
  0U,
  0U,
  0U,
  mdl_attributes_txt_warn_check_fuel_cap_attrib_textcoord_array,
  nullptr,
  nullptr,
  nullptr
};
rdf_primitive const mdl_primitive_txt_warn_check_fuel_cap =
{
  5,
  3,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_warn_check_fuel_cap[1]=
{
  &mdl_primitive_txt_warn_check_fuel_cap
};
rdf_primitive const mdl_primitive_vector_42 =
{
  2,
  4,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_vector_42[1]=
{
  &mdl_primitive_vector_42
};
rdf_primitive const mdl_primitive_vector_43 =
{
  2,
  5,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_vector_43[1]=
{
  &mdl_primitive_vector_43
};
rdf_primitive const mdl_primitive_vector_44 =
{
  2,
  6,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_vector_44[1]=
{
  &mdl_primitive_vector_44
};
rdf_primitive const mdl_primitive_vector_45 =
{
  2,
  7,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_vector_45[1]=
{
  &mdl_primitive_vector_45
};
rdf_primitive const mdl_primitive_warning_red_outline =
{
  2,
  8,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_warning_red_outline[1]=
{
  &mdl_primitive_warning_red_outline
};
rdf_primitive const mdl_primitive_txt_check_airbag =
{
  5,
  9,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_check_airbag[1]=
{
  &mdl_primitive_txt_check_airbag
};
rdf_primitive const mdl_primitive_layer_1_0 =
{
  2,
  10,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_layer_1_0[1]=
{
  &mdl_primitive_layer_1_0
};
rdf_primitive const mdl_primitive_vector =
{
  2,
  11,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_vector[1]=
{
  &mdl_primitive_vector
};
rdf_primitive const mdl_primitive_vector_0 =
{
  2,
  12,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_vector_0[1]=
{
  &mdl_primitive_vector_0
};
rdf_primitive const mdl_primitive_vector_1 =
{
  2,
  13,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_vector_1[1]=
{
  &mdl_primitive_vector_1
};
rdf_primitive const mdl_primitive_vector_2 =
{
  2,
  14,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_vector_2[1]=
{
  &mdl_primitive_vector_2
};
rdf_primitive const mdl_primitive_vector_3 =
{
  2,
  15,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_vector_3[1]=
{
  &mdl_primitive_vector_3
};
rdf_primitive const mdl_primitive_vector_4 =
{
  2,
  16,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_vector_4[1]=
{
  &mdl_primitive_vector_4
};
rdf_primitive const mdl_primitive_menu_bg =
{
  2,
  17,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_menu_bg[1]=
{
  &mdl_primitive_menu_bg
};
rdf_primitive const mdl_primitive_menu_focus_bar =
{
  2,
  18,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_menu_focus_bar[1]=
{
  &mdl_primitive_menu_focus_bar
};
rdf_primitive const mdl_primitive_txt_menu_drive_info =
{
  5,
  19,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_menu_drive_info[1]=
{
  &mdl_primitive_txt_menu_drive_info
};
rdf_primitive const mdl_primitive_txt_menu_vehicle_info =
{
  5,
  20,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_menu_vehicle_info[1]=
{
  &mdl_primitive_txt_menu_vehicle_info
};
rdf_primitive const mdl_primitive_txt_menu_adas =
{
  5,
  21,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_menu_adas[1]=
{
  &mdl_primitive_txt_menu_adas
};
rdf_primitive const mdl_primitive_txt_menu_navigation =
{
  5,
  22,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_menu_navigation[1]=
{
  &mdl_primitive_txt_menu_navigation
};
rdf_primitive const mdl_primitive_txt_menu_alert_history =
{
  5,
  23,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_menu_alert_history[1]=
{
  &mdl_primitive_txt_menu_alert_history
};
rdf_primitive const mdl_primitive_txt_menu_title =
{
  5,
  24,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_menu_title[1]=
{
  &mdl_primitive_txt_menu_title
};
rdf_primitive const mdl_primitive_menu_line_1 =
{
  2,
  25,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_menu_line_1[1]=
{
  &mdl_primitive_menu_line_1
};
rdf_primitive const mdl_primitive_menu_line_2 =
{
  2,
  26,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_menu_line_2[1]=
{
  &mdl_primitive_menu_line_2
};
rdf_primitive const mdl_primitive_menu_line_3 =
{
  2,
  26,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_menu_line_3[1]=
{
  &mdl_primitive_menu_line_3
};
rdf_primitive const mdl_primitive_menu_line_4 =
{
  2,
  26,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_menu_line_4[1]=
{
  &mdl_primitive_menu_line_4
};
rdf_primitive const mdl_primitive_ellipse_56 =
{
  2,
  27,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_ellipse_56[1]=
{
  &mdl_primitive_ellipse_56
};
rdf_primitive const mdl_primitive_ellipse_57 =
{
  2,
  28,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_ellipse_57[1]=
{
  &mdl_primitive_ellipse_57
};
rdf_primitive const mdl_primitive_ellipse_52 =
{
  2,
  29,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_ellipse_52[1]=
{
  &mdl_primitive_ellipse_52
};
rdf_primitive const mdl_primitive_ellipse_47 =
{
  2,
  30,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_ellipse_47[1]=
{
  &mdl_primitive_ellipse_47
};
rdf_primitive const mdl_primitive_ellipse_59 =
{
  2,
  31,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_ellipse_59[1]=
{
  &mdl_primitive_ellipse_59
};
rdf_primitive const mdl_primitive_ellipse_60 =
{
  2,
  32,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_ellipse_60[1]=
{
  &mdl_primitive_ellipse_60
};
rdf_primitive const mdl_primitive_ellipse_61 =
{
  2,
  33,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_ellipse_61[1]=
{
  &mdl_primitive_ellipse_61
};
rdf_primitive const mdl_primitive_ellipse_55 =
{
  2,
  34,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_ellipse_55[1]=
{
  &mdl_primitive_ellipse_55
};
rdf_primitive const mdl_primitive_ellipse_58 =
{
  2,
  35,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_ellipse_58[1]=
{
  &mdl_primitive_ellipse_58
};
rdf_primitive const mdl_primitive_ellipse_49 =
{
  2,
  36,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_ellipse_49[1]=
{
  &mdl_primitive_ellipse_49
};
rdf_primitive const mdl_primitive_ellipse_53 =
{
  2,
  37,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_ellipse_53[1]=
{
  &mdl_primitive_ellipse_53
};
rdf_primitive const mdl_primitive_ellipse_51 =
{
  2,
  38,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_ellipse_51[1]=
{
  &mdl_primitive_ellipse_51
};
rdf_primitive const mdl_primitive_vector_58 =
{
  2,
  39,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_vector_58[1]=
{
  &mdl_primitive_vector_58
};
rdf_primitive const mdl_primitive_vector_59 =
{
  2,
  40,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_vector_59[1]=
{
  &mdl_primitive_vector_59
};
rdf_primitive const mdl_primitive_vector_56 =
{
  2,
  41,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_vector_56[1]=
{
  &mdl_primitive_vector_56
};
rdf_primitive const mdl_primitive_vector_61 =
{
  2,
  42,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_vector_61[1]=
{
  &mdl_primitive_vector_61
};
rdf_primitive const mdl_primitive_vector_57 =
{
  2,
  43,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_vector_57[1]=
{
  &mdl_primitive_vector_57
};
rdf_primitive const mdl_primitive_vector_60 =
{
  2,
  44,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_vector_60[1]=
{
  &mdl_primitive_vector_60
};
rdf_primitive const mdl_primitive_txt_digital_speedo_day =
{
  5,
  45,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_digital_speedo_day[1]=
{
  &mdl_primitive_txt_digital_speedo_day
};
rdf_primitive const mdl_primitive_txt_digital_speedo_day_0 =
{
  5,
  46,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_digital_speedo_day_0[1]=
{
  &mdl_primitive_txt_digital_speedo_day_0
};
rdf_primitive const mdl_primitive_txt_digital_speedo_day_1 =
{
  5,
  47,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_digital_speedo_day_1[1]=
{
  &mdl_primitive_txt_digital_speedo_day_1
};
rdf_primitive const mdl_primitive_txt_main_digital_speedo =
{
  5,
  48,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_main_digital_speedo[1]=
{
  &mdl_primitive_txt_main_digital_speedo
};
rdf_primitive const mdl_primitive_txt_digital_speedo_day_3 =
{
  5,
  49,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_digital_speedo_day_3[1]=
{
  &mdl_primitive_txt_digital_speedo_day_3
};
rdf_primitive const mdl_primitive_txt_digital_speedo_day_4 =
{
  5,
  50,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_digital_speedo_day_4[1]=
{
  &mdl_primitive_txt_digital_speedo_day_4
};
rdf_primitive const mdl_primitive_txt_digital_speedo_day_5 =
{
  5,
  51,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_digital_speedo_day_5[1]=
{
  &mdl_primitive_txt_digital_speedo_day_5
};
rdf_primitive const mdl_primitive_fuel_icon_5_1 =
{
  2,
  52,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_fuel_icon_5_1[1]=
{
  &mdl_primitive_fuel_icon_5_1
};
rdf_primitive const mdl_primitive_polygon_27 =
{
  2,
  53,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_polygon_27[1]=
{
  &mdl_primitive_polygon_27
};
rdf_primitive const mdl_primitive_ellipse_56_0 =
{
  2,
  54,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_ellipse_56_0[1]=
{
  &mdl_primitive_ellipse_56_0
};
rdf_primitive const mdl_primitive_ellipse_57_0 =
{
  2,
  55,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_ellipse_57_0[1]=
{
  &mdl_primitive_ellipse_57_0
};
rdf_primitive const mdl_primitive_ellipse_52_0 =
{
  2,
  56,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_ellipse_52_0[1]=
{
  &mdl_primitive_ellipse_52_0
};
rdf_primitive const mdl_primitive_ellipse_47_0 =
{
  2,
  57,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_ellipse_47_0[1]=
{
  &mdl_primitive_ellipse_47_0
};
rdf_primitive const mdl_primitive_ellipse_59_0 =
{
  2,
  58,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_ellipse_59_0[1]=
{
  &mdl_primitive_ellipse_59_0
};
rdf_primitive const mdl_primitive_ellipse_60_0 =
{
  2,
  59,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_ellipse_60_0[1]=
{
  &mdl_primitive_ellipse_60_0
};
rdf_primitive const mdl_primitive_ellipse_61_0 =
{
  2,
  60,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_ellipse_61_0[1]=
{
  &mdl_primitive_ellipse_61_0
};
rdf_primitive const mdl_primitive_ellipse_55_0 =
{
  2,
  61,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_ellipse_55_0[1]=
{
  &mdl_primitive_ellipse_55_0
};
rdf_primitive const mdl_primitive_ellipse_62 =
{
  2,
  62,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_ellipse_62[1]=
{
  &mdl_primitive_ellipse_62
};
rdf_primitive const mdl_primitive_ellipse_49_0 =
{
  2,
  63,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_ellipse_49_0[1]=
{
  &mdl_primitive_ellipse_49_0
};
rdf_primitive const mdl_primitive_ellipse_53_0 =
{
  2,
  64,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_ellipse_53_0[1]=
{
  &mdl_primitive_ellipse_53_0
};
rdf_primitive const mdl_primitive_ellipse_51_0 =
{
  2,
  65,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_ellipse_51_0[1]=
{
  &mdl_primitive_ellipse_51_0
};
rdf_primitive const mdl_primitive_vector_58_0 =
{
  2,
  66,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_vector_58_0[1]=
{
  &mdl_primitive_vector_58_0
};
rdf_primitive const mdl_primitive_vector_59_0 =
{
  2,
  67,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_vector_59_0[1]=
{
  &mdl_primitive_vector_59_0
};
rdf_primitive const mdl_primitive_vector_56_0 =
{
  2,
  68,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_vector_56_0[1]=
{
  &mdl_primitive_vector_56_0
};
rdf_primitive const mdl_primitive_vector_61_0 =
{
  2,
  42,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_vector_61_0[1]=
{
  &mdl_primitive_vector_61_0
};
rdf_primitive const mdl_primitive_vector_57_0 =
{
  2,
  69,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_vector_57_0[1]=
{
  &mdl_primitive_vector_57_0
};
rdf_primitive const mdl_primitive_vector_60_0 =
{
  2,
  70,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_vector_60_0[1]=
{
  &mdl_primitive_vector_60_0
};
rdf_primitive const mdl_primitive_txt_digital_speedo_day_6 =
{
  5,
  71,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_digital_speedo_day_6[1]=
{
  &mdl_primitive_txt_digital_speedo_day_6
};
rdf_primitive const mdl_primitive_txt_digital_speedo_day_7 =
{
  5,
  72,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_digital_speedo_day_7[1]=
{
  &mdl_primitive_txt_digital_speedo_day_7
};
rdf_primitive const mdl_primitive_txt_gear_value =
{
  5,
  73,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_gear_value[1]=
{
  &mdl_primitive_txt_gear_value
};
rdf_primitive const mdl_primitive_txt_tacho_unit =
{
  5,
  74,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_tacho_unit[1]=
{
  &mdl_primitive_txt_tacho_unit
};
rdf_primitive const mdl_primitive_txt_gear_title =
{
  5,
  75,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_gear_title[1]=
{
  &mdl_primitive_txt_gear_title
};
rdf_primitive const mdl_primitive_txt_digital_speedo_day_17 =
{
  5,
  76,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_digital_speedo_day_17[1]=
{
  &mdl_primitive_txt_digital_speedo_day_17
};
rdf_primitive const mdl_primitive_txt_digital_speedo_day_18 =
{
  5,
  77,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_digital_speedo_day_18[1]=
{
  &mdl_primitive_txt_digital_speedo_day_18
};
rdf_primitive const mdl_primitive_default_0 =
{
  2,
  78,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_default_0[1]=
{
  &mdl_primitive_default_0
};
rdf_primitive const mdl_primitive_vector_inst1 =
{
  2,
  79,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_vector_inst1[1]=
{
  &mdl_primitive_vector_inst1
};
rdf_primitive const mdl_primitive_vector_0_inst1 =
{
  2,
  80,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_vector_0_inst1[1]=
{
  &mdl_primitive_vector_0_inst1
};
rdf_primitive const mdl_primitive_vector_1_inst1 =
{
  2,
  81,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_vector_1_inst1[1]=
{
  &mdl_primitive_vector_1_inst1
};
rdf_primitive const mdl_primitive_vector_2_inst1 =
{
  2,
  82,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_frame_47_0_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_vector_2_inst1[1]=
{
  &mdl_primitive_vector_2_inst1
};
rdf_primitive const mdl_primitive_txt_odo_unit =
{
  5,
  83,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_odo_unit[1]=
{
  &mdl_primitive_txt_odo_unit
};
rdf_primitive const mdl_primitive_txt_odo_value =
{
  5,
  84,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_odo_value[1]=
{
  &mdl_primitive_txt_odo_value
};
rdf_primitive const mdl_primitive_txt_odo_title =
{
  5,
  85,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_odo_title[1]=
{
  &mdl_primitive_txt_odo_title
};
rdf_primitive const mdl_primitive_txt_dte_title =
{
  5,
  86,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_dte_title[1]=
{
  &mdl_primitive_txt_dte_title
};
rdf_primitive const mdl_primitive_txt_dte_value =
{
  5,
  87,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_dte_value[1]=
{
  &mdl_primitive_txt_dte_value
};
rdf_primitive const mdl_primitive_txt_dte_unit =
{
  5,
  88,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_dte_unit[1]=
{
  &mdl_primitive_txt_dte_unit
};
rdf_primitive const mdl_primitive_txt_digital_speedo_day_25 =
{
  5,
  89,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_digital_speedo_day_25[1]=
{
  &mdl_primitive_txt_digital_speedo_day_25
};
rdf_primitive const mdl_primitive_txt_digital_speedo_day_26 =
{
  5,
  90,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_digital_speedo_day_26[1]=
{
  &mdl_primitive_txt_digital_speedo_day_26
};
rdf_primitive const mdl_primitive_txt_digital_speedo_day_27 =
{
  5,
  91,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_digital_speedo_day_27[1]=
{
  &mdl_primitive_txt_digital_speedo_day_27
};
rdf_primitive const mdl_primitive_txt_digital_speedo_day_28 =
{
  5,
  92,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_digital_speedo_day_28[1]=
{
  &mdl_primitive_txt_digital_speedo_day_28
};
rdf_primitive const mdl_primitive_txt_digital_speedo_day_29 =
{
  5,
  93,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_digital_speedo_day_29[1]=
{
  &mdl_primitive_txt_digital_speedo_day_29
};
rdf_primitive const mdl_primitive_txt_digital_speedo_day_30 =
{
  5,
  94,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_digital_speedo_day_30[1]=
{
  &mdl_primitive_txt_digital_speedo_day_30
};
rdf_primitive const mdl_primitive_txt_tacho_value =
{
  5,
  95,
  MdlPrimMode_E::pmTriangles,
  MdlPrimShadowCastMode_E::pscmOff,
  -1,
  -1,
  0U,
  &mdl_attributes_txt_warn_check_fuel_cap_attrib,
  nullptr
};
rdf_primitive const * const primitives_mdl_mesh_txt_tacho_value[1]=
{
  &mdl_primitive_txt_tacho_value
};

//Methods ...

}
