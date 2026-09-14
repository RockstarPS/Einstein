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
#ifndef rdf_light_type_h
#define rdf_light_type_h


//Macro Definitions ...

namespace rendercore_engine
{

//Class Definitions ...
class rdf_light
{
public:
  CHAR8 const * name;
  uint32_t cullingMask;
  float32_t range;
  float32_t intensity;
  float32_t innerCone;
  float32_t outerCone;
  float32_t color[3];
  float32_t attenuation;
  float32_t specular_amount;
  float32_t size;
  float32_t cone_attenuation;
  bool shadow_enable;
  bool shadow_reversecull;
  float32_t shadow_bias;
  float32_t shadow_transmittancebias;
  float32_t shadow_normalbias;
  float32_t shadow_opacity;
  float32_t shadow_blur;
  rc_matlighttype type;
};

}

#endif
