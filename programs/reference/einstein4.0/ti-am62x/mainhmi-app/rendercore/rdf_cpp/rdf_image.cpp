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
#include "rdf_image.h"
//Macro Definitions ...

namespace rendercore_engine
{

//Variable declarations ...
static CHAR8 const * const mdl_image_frame_47_0_uri = "Assets/All_Export_BU/All_Export/images/frame_47_0.png";
static CHAR8 const * const mdl_image_bg_uri = "Assets/All_Export_BU/All_Export/images/bg.png";
static CHAR8 const * const mdl_image_rectangle_394_uri = "Assets/fuelCap/images/rectangle_394.png";
static CHAR8 const * const mdl_image_vector_42_uri = "Assets/fuelCap/images/vector_42.png";
static CHAR8 const * const mdl_image_vector_43_uri = "Assets/fuelCap/images/vector_43.png";
static CHAR8 const * const mdl_image_vector_44_uri = "Assets/fuelCap/images/vector_44.png";
static CHAR8 const * const mdl_image_vector_45_uri = "Assets/fuelCap/images/vector_45.png";
static CHAR8 const * const mdl_image_rectangle_394_inst1_uri = "Assets/frame50_just_wrnContents/images/rectangle_394.png";
static CHAR8 const * const mdl_image_layer_1_0_uri = "Assets/frame50_just_wrnContents/images/layer_1_0.png";
static CHAR8 const * const mdl_image_vector_uri = "Assets/frame50_just_wrnContents/images/vector.png";
static CHAR8 const * const mdl_image_vector_0_uri = "Assets/frame50_just_wrnContents/images/vector_0.png";
static CHAR8 const * const mdl_image_vector_1_uri = "Assets/frame50_just_wrnContents/images/vector_1.png";
static CHAR8 const * const mdl_image_vector_2_uri = "Assets/frame50_just_wrnContents/images/vector_2.png";
static CHAR8 const * const mdl_image_vector_3_uri = "Assets/frame50_just_wrnContents/images/vector_3.png";
static CHAR8 const * const mdl_image_vector_4_uri = "Assets/frame50_just_wrnContents/images/vector_4.png";
static CHAR8 const * const mdl_image_rectangle_395_uri = "Assets/All_Export_BU/All_Export/images/rectangle_395.png";
static CHAR8 const * const mdl_image_rectangle_396_uri = "Assets/All_Export_BU/All_Export/images/rectangle_396.png";
static CHAR8 const * const mdl_image_line_17_uri = "Assets/All_Export_BU/All_Export/images/line_17.png";
static CHAR8 const * const mdl_image_line_18_uri = "Assets/All_Export_BU/All_Export/images/line_18.png";
static CHAR8 const * const mdl_image_ellipse_56_uri = "Assets/All_Export_BU/All_Export/images/ellipse_56.png";
static CHAR8 const * const mdl_image_ellipse_57_uri = "Assets/All_Export_BU/All_Export/images/ellipse_57.png";
static CHAR8 const * const mdl_image_ellipse_52_uri = "Assets/All_Export_BU/All_Export/images/ellipse_52.png";
static CHAR8 const * const mdl_image_ellipse_47_uri = "Assets/All_Export_BU/All_Export/images/ellipse_47.png";
static CHAR8 const * const mdl_image_ellipse_59_uri = "Assets/All_Export_BU/All_Export/images/ellipse_59.png";
static CHAR8 const * const mdl_image_ellipse_60_uri = "Assets/All_Export_BU/All_Export/images/ellipse_60.png";
static CHAR8 const * const mdl_image_ellipse_61_uri = "Assets/All_Export_BU/All_Export/images/ellipse_61.png";
static CHAR8 const * const mdl_image_ellipse_55_uri = "Assets/All_Export_BU/All_Export/images/ellipse_55.png";
static CHAR8 const * const mdl_image_ellipse_58_uri = "Assets/All_Export_BU/All_Export/images/ellipse_58.png";
static CHAR8 const * const mdl_image_ellipse_49_uri = "Assets/All_Export_BU/All_Export/images/ellipse_49.png";
static CHAR8 const * const mdl_image_ellipse_53_uri = "Assets/All_Export_BU/All_Export/images/ellipse_53.png";
static CHAR8 const * const mdl_image_ellipse_51_uri = "Assets/All_Export_BU/All_Export/images/ellipse_51.png";
static CHAR8 const * const mdl_image_vector_58_uri = "Assets/All_Export_BU/All_Export/images/vector_58.png";
static CHAR8 const * const mdl_image_vector_59_uri = "Assets/All_Export_BU/All_Export/images/vector_59.png";
static CHAR8 const * const mdl_image_vector_56_uri = "Assets/All_Export_BU/All_Export/images/vector_56.png";
static CHAR8 const * const mdl_image_vector_61_uri = "Assets/All_Export_BU/All_Export/images/vector_61.png";
static CHAR8 const * const mdl_image_vector_57_uri = "Assets/All_Export_BU/All_Export/images/vector_57.png";
static CHAR8 const * const mdl_image_vector_60_uri = "Assets/All_Export_BU/All_Export/images/vector_60.png";
static CHAR8 const * const mdl_image_fuel_icon_5_1_uri = "Assets/All_Export_BU/All_Export/images/fuel_icon_5_1.png";
static CHAR8 const * const mdl_image_polygon_27_uri = "Assets/All_Export_BU/All_Export/images/polygon_27.png";
static CHAR8 const * const mdl_image_ellipse_56_0_uri = "Assets/All_Export_BU/All_Export/images/ellipse_56_0.png";
static CHAR8 const * const mdl_image_ellipse_57_0_uri = "Assets/All_Export_BU/All_Export/images/ellipse_57_0.png";
static CHAR8 const * const mdl_image_ellipse_52_0_uri = "Assets/All_Export_BU/All_Export/images/ellipse_52_0.png";
static CHAR8 const * const mdl_image_ellipse_47_0_uri = "Assets/All_Export_BU/All_Export/images/ellipse_47_0.png";
static CHAR8 const * const mdl_image_ellipse_59_0_uri = "Assets/All_Export_BU/All_Export/images/ellipse_59_0.png";
static CHAR8 const * const mdl_image_ellipse_60_0_uri = "Assets/All_Export_BU/All_Export/images/ellipse_60_0.png";
static CHAR8 const * const mdl_image_ellipse_61_0_uri = "Assets/All_Export_BU/All_Export/images/ellipse_61_0.png";
static CHAR8 const * const mdl_image_ellipse_55_0_uri = "Assets/All_Export_BU/All_Export/images/ellipse_55_0.png";
static CHAR8 const * const mdl_image_ellipse_62_uri = "Assets/All_Export_BU/All_Export/images/ellipse_62.png";
static CHAR8 const * const mdl_image_ellipse_49_0_uri = "Assets/All_Export_BU/All_Export/images/ellipse_49_0.png";
static CHAR8 const * const mdl_image_ellipse_53_0_uri = "Assets/All_Export_BU/All_Export/images/ellipse_53_0.png";
static CHAR8 const * const mdl_image_ellipse_51_0_uri = "Assets/All_Export_BU/All_Export/images/ellipse_51_0.png";
static CHAR8 const * const mdl_image_vector_58_0_uri = "Assets/All_Export_BU/All_Export/images/vector_58_0.png";
static CHAR8 const * const mdl_image_vector_59_0_uri = "Assets/All_Export_BU/All_Export/images/vector_59_0.png";
static CHAR8 const * const mdl_image_vector_56_0_uri = "Assets/All_Export_BU/All_Export/images/vector_56_0.png";
static CHAR8 const * const mdl_image_vector_57_0_uri = "Assets/All_Export_BU/All_Export/images/vector_57_0.png";
static CHAR8 const * const mdl_image_vector_60_0_uri = "Assets/All_Export_BU/All_Export/images/vector_60_0.png";
static CHAR8 const * const mdl_image_default_0_uri = "Assets/All_Export_BU/All_Export/images/default_0.png";
static CHAR8 const * const mdl_image_vector_inst1_uri = "Assets/All_Export_BU/All_Export/images/vector.png";
static CHAR8 const * const mdl_image_vector_0_inst1_uri = "Assets/All_Export_BU/All_Export/images/vector_0.png";
static CHAR8 const * const mdl_image_vector_1_inst1_uri = "Assets/All_Export_BU/All_Export/images/vector_1.png";
static CHAR8 const * const mdl_image_vector_2_inst1_uri = "Assets/All_Export_BU/All_Export/images/vector_2.png";

//Class data declarations ...
rdf_image const mdl_image_images_disp0[61] =
{
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_frame_47_0_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_bg_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_rectangle_394_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_vector_42_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_vector_43_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_vector_44_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_vector_45_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_rectangle_394_inst1_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_layer_1_0_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_vector_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_vector_0_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_vector_1_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_vector_2_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_vector_3_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_vector_4_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_rectangle_395_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_rectangle_396_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_line_17_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_line_18_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_ellipse_56_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_ellipse_57_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_ellipse_52_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_ellipse_47_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_ellipse_59_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_ellipse_60_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_ellipse_61_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_ellipse_55_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_ellipse_58_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_ellipse_49_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_ellipse_53_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_ellipse_51_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_vector_58_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_vector_59_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_vector_56_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_vector_61_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_vector_57_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_vector_60_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_fuel_icon_5_1_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_polygon_27_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_ellipse_56_0_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_ellipse_57_0_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_ellipse_52_0_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_ellipse_47_0_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_ellipse_59_0_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_ellipse_60_0_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_ellipse_61_0_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_ellipse_55_0_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_ellipse_62_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_ellipse_49_0_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_ellipse_53_0_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_ellipse_51_0_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_vector_58_0_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_vector_59_0_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_vector_56_0_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_vector_57_0_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_vector_60_0_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_default_0_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_vector_inst1_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_vector_0_inst1_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_vector_1_inst1_uri,
    false
  },
  {
    -1,
    MdlImgEncoding_E::iePng,
    mdl_image_vector_2_inst1_uri,
    false
  }
};

//Methods ...

}
