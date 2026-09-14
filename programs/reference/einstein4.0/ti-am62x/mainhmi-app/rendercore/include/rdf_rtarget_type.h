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
#ifndef rdf_rtarget_type_h
#define rdf_rtarget_type_h


//Macro Definitions ...

namespace rendercore_engine
{

//Class Definitions ...
class rdf_rtarget
{
public:
  float32_t viewport_x;
  float32_t viewport_y;
  float32_t viewport_w;
  float32_t viewport_h;
  uint32_t msaa_level;
  rtColorDepthE colorSize;
  int32_t tex_index;
  uint32_t depth_size;
};

}

#endif
