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
#ifndef rdf_primitive_type_h
#define rdf_primitive_type_h


//Macro Definitions ...

namespace rendercore_engine
{

//Class Definitions ...
class rdf_attributes
{
public:
  uint32_t uid;
  int32_t position;
  int32_t normal;
  int32_t tangent;
  uint32_t textcoord_array_size;
  uint32_t color_array_size;
  uint32_t joints_array_size;
  uint32_t weights_array_size;
  GLint const * textcoord;
  GLint const * primColors;
  GLint const * joints;
  GLint const * weights;
};
class rdf_primitive
{
public:
  int32_t indices;
  int32_t primMaterial;
  MdlPrimMode_E mode;
  MdlPrimShadowCastMode_E shadowCastMode;
  int32_t skinId;
  int32_t matSkinId;
  uint32_t targets_size;
  rdf_attributes const * attributes;
  rdf_morphTarget const * targets;
};

}

#endif
