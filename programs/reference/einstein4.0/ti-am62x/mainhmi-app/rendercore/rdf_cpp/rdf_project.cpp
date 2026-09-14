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
#include "rdf_project.h"
//Macro Definitions ...

namespace rendercore_engine
{

//Variable declarations ...

//Class data declarations ...
rdf_assetgroup const mdl_assetgroup_agroups[1] =
{
  {
    "SampleE4AssetGroup_0.tar",
    static_cast<int32_t>(rdf_agid_e::RC_ASSET_ID_0),
    static_cast<int32_t>(rc_agcst_e::RC_ASSET_ID_INVALID),
  }
};
rdf_project const mdl_project =
{
  1U,
  12U,
  MdlFontEngine::feFreeType,
  MdlCoordSystem::csRHS,
  {2,4,0},
  {13,0,0},
  displays,
  fonts,
  false,
  1U,
  mdl_assetgroup_agroups,
  static_cast<int32_t>(rc_agcst_e::RC_ASSET_ID_INVALID),
  U'\U0000FFFD'
};

//Methods ...

}
