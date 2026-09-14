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
#include "rdf_accessor.h"
//Macro Definitions ...

namespace rendercore_engine
{

//Variable declarations ...

//Class data declarations ...
rdf_accessor const mdl_accessor_accessors_disp0[6] =
{
  {
    0,
    0U,
    MdlCompType_E::ctFloat,
    false,
    4U,
    MdlType_E::dtVec3,
    0,
    3
  },
  {
    1,
    0U,
    MdlCompType_E::ctFloat,
    false,
    4U,
    MdlType_E::dtVec2,
    4,
    6
  },
  {
    2,
    0U,
    MdlCompType_E::ctUnsignedByte,
    false,
    6U,
    MdlType_E::dtScalar,
    -1,
    -1
  },
  {
    3,
    0U,
    MdlCompType_E::ctFloat,
    false,
    4U,
    MdlType_E::dtVec2,
    4,
    6
  },
  {
    4,
    0U,
    MdlCompType_E::ctFloat,
    false,
    4U,
    MdlType_E::dtVec3,
    0,
    3
  },
  {
    5,
    0U,
    MdlCompType_E::ctUnsignedByte,
    false,
    6U,
    MdlType_E::dtScalar,
    -1,
    -1
  }
};

//Methods ...

}
