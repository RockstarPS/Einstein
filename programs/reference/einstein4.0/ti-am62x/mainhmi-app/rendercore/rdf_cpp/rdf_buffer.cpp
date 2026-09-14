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
#include "rdf_buffer.h"
//Macro Definitions ...

namespace rendercore_engine
{

//Variable declarations ...
static CHAR8 const * const mdl_buffer_frame_47_0_uri = "buffers/br_frame_47_0.bin";
static CHAR8 const * const mdl_buffer_txt_warn_check_fuel_cap_uri = "buffers/br_txt_warn_check_fuel_cap.bin";

//Class data declarations ...
rdf_buffer const mdl_buffer_buffers_disp0[2] =
{
  {
    88U,
    mdl_buffer_frame_47_0_uri
  },
  {
    88U,
    mdl_buffer_txt_warn_check_fuel_cap_uri
  }
};

//Methods ...

}
