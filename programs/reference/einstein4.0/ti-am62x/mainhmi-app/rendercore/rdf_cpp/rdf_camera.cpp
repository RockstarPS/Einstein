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
#include "rdf_camera.h"
//Macro Definitions ...

namespace rendercore_engine
{

//Variable declarations ...

//Class data declarations ...
rdf_camera const mdl_camera_cameras_disp0[1] =
{
  {
    &mdl_orthographic_mainCamera_ortho,
    nullptr,
    MdlCamType_E::ctOrthographic,
    0x000FFFFFU,
    -1,
    false,
    true,
    {0.000000F,0.000000F,0.000000F,0.000000F},
    1.000000F,
    {0.000000F,0.000000F,1920.000000F,720.000000F},
    mdl_cullMode::cmOff,
    mdl_depthTest::dtOff,
    mdl_depthWrite::dwFalse,
    MdlBlendFactor::bfSrcAlpha,
    MdlBlendFactor::bfOneminusSrcAlpha,
    MdlBlendFactor::bfZero,
    MdlBlendFactor::bfOne,
    MdlBlendEquation::beUnset,
    MdlBlendEquation::beAdd,
    {0.000000F,0.000000F,-1.000000F,-1.000000F},
    rc_rsortType::sortAuto,
    1U,
    0,
    -1
  }
};

//Methods ...

}
