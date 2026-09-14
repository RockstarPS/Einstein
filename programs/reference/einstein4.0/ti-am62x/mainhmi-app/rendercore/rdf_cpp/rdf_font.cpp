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
#include "rdf_font.h"
//Macro Definitions ...

namespace rendercore_engine
{

//Variable declarations ...

//Class data declarations ...
rdf_font const mdl_font_BaiJamjuree_Regular =
{
  "Assets/fuelCap/fonts/BaiJamjuree-Regular.ttf",
  "BaiJamjuree-Regular",
  28.000000F,
  MdlFontStyle::fsNormal,
  MdlFontRenderHint::rhAntiAlias,
  MdlFontHeightCalc_E::fhUseMaxOfTypoAndWin
};
rdf_font const mdl_font_BaiJamjuree_Medium =
{
  "Assets/All_Export_BU/All_Export/fonts/BaiJamjuree-Medium.ttf",
  "BaiJamjuree-Medium",
  43.000000F,
  MdlFontStyle::fsNormal,
  MdlFontRenderHint::rhAntiAlias,
  MdlFontHeightCalc_E::fhUseMaxOfTypoAndWin
};
rdf_font const mdl_font_BaiJamjuree_Medium_inst1 =
{
  "Assets/All_Export_BU/All_Export/fonts/BaiJamjuree-Medium.ttf",
  "BaiJamjuree-Medium",
  35.000000F,
  MdlFontStyle::fsNormal,
  MdlFontRenderHint::rhAntiAlias,
  MdlFontHeightCalc_E::fhUseMaxOfTypoAndWin
};
rdf_font const mdl_font_BaiJamjuree_Bold =
{
  "Assets/All_Export_BU/All_Export/fonts/BaiJamjuree-Bold.ttf",
  "BaiJamjuree-Bold",
  180.000000F,
  MdlFontStyle::fsBold,
  MdlFontRenderHint::rhAntiAlias,
  MdlFontHeightCalc_E::fhUseMaxOfTypoAndWin
};
rdf_font const mdl_font_BaiJamjuree_Bold_inst1 =
{
  "Assets/All_Export_BU/All_Export/fonts/BaiJamjuree-Bold.ttf",
  "BaiJamjuree-Bold",
  24.000000F,
  MdlFontStyle::fsBold,
  MdlFontRenderHint::rhAntiAlias,
  MdlFontHeightCalc_E::fhUseMaxOfTypoAndWin
};
rdf_font const mdl_font_BaiJamjuree_Bold_inst2 =
{
  "Assets/All_Export_BU/All_Export/fonts/BaiJamjuree-Bold.ttf",
  "BaiJamjuree-Bold",
  34.000000F,
  MdlFontStyle::fsBold,
  MdlFontRenderHint::rhAntiAlias,
  MdlFontHeightCalc_E::fhUseMaxOfTypoAndWin
};
rdf_font const mdl_font_BaiJamjuree_Bold_inst3 =
{
  "Assets/All_Export_BU/All_Export/fonts/BaiJamjuree-Bold.ttf",
  "BaiJamjuree-Bold",
  35.000000F,
  MdlFontStyle::fsBold,
  MdlFontRenderHint::rhAntiAlias,
  MdlFontHeightCalc_E::fhUseMaxOfTypoAndWin
};
rdf_font const mdl_font_BaiJamjuree_Bold_inst4 =
{
  "Assets/All_Export_BU/All_Export/fonts/BaiJamjuree-Bold.ttf",
  "BaiJamjuree-Bold",
  80.000000F,
  MdlFontStyle::fsBold,
  MdlFontRenderHint::rhAntiAlias,
  MdlFontHeightCalc_E::fhUseMaxOfTypoAndWin
};
rdf_font const mdl_font_BaiJamjuree_Medium_inst2 =
{
  "Assets/All_Export_BU/All_Export/fonts/BaiJamjuree-Medium.ttf",
  "BaiJamjuree-Medium",
  24.000000F,
  MdlFontStyle::fsNormal,
  MdlFontRenderHint::rhAntiAlias,
  MdlFontHeightCalc_E::fhUseMaxOfTypoAndWin
};
rdf_font const mdl_font_BaiJamjuree_Medium_inst3 =
{
  "Assets/All_Export_BU/All_Export/fonts/BaiJamjuree-Medium.ttf",
  "BaiJamjuree-Medium",
  34.000000F,
  MdlFontStyle::fsNormal,
  MdlFontRenderHint::rhAntiAlias,
  MdlFontHeightCalc_E::fhUseMaxOfTypoAndWin
};
rdf_font const mdl_font_BaiJamjuree_Regular_inst1 =
{
  "Assets/fuelCap/fonts/BaiJamjuree-Regular.ttf",
  "BaiJamjuree-Regular",
  34.000000F,
  MdlFontStyle::fsNormal,
  MdlFontRenderHint::rhAntiAlias,
  MdlFontHeightCalc_E::fhUseMaxOfTypoAndWin
};
rdf_font const mdl_font_BaiJamjuree_Bold_inst5 =
{
  "Assets/All_Export_BU/All_Export/fonts/BaiJamjuree-Bold.ttf",
  "BaiJamjuree-Bold",
  18.000000F,
  MdlFontStyle::fsBold,
  MdlFontRenderHint::rhAntiAlias,
  MdlFontHeightCalc_E::fhUseMaxOfTypoAndWin
};
rdf_font const * const fonts[12]=
{
&mdl_font_BaiJamjuree_Regular,
&mdl_font_BaiJamjuree_Medium,
&mdl_font_BaiJamjuree_Medium_inst1,
&mdl_font_BaiJamjuree_Bold,
&mdl_font_BaiJamjuree_Bold_inst1,
&mdl_font_BaiJamjuree_Bold_inst2,
&mdl_font_BaiJamjuree_Bold_inst3,
&mdl_font_BaiJamjuree_Bold_inst4,
&mdl_font_BaiJamjuree_Medium_inst2,
&mdl_font_BaiJamjuree_Medium_inst3,
&mdl_font_BaiJamjuree_Regular_inst1,
&mdl_font_BaiJamjuree_Bold_inst5
};

//Methods ...

}
