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
#ifndef rdf_material_type_h
#define rdf_material_type_h


//Macro Definitions ...

namespace rendercore_engine
{

//Class Definitions ...
class rdf_material_base
{
public:
  bool isShaderUri;
  uint32_t vs_uid;
  uint32_t fs_uid;
  uint32_t po_uid;
  CHAR8 const * lvertShader;
  CHAR8 const * lfragShader;
  uint32_t lvertShaderLength;
  uint32_t lfragShaderLength;
  CHAR8 const * lbProgram;
  uint32_t lbProgramLength;
  mdl_cullMode cullMode;
  uint32_t shaderBinaryFormat;
  MdlBlendFactor srcBlendfactor;
  MdlBlendFactor dstBlendfactor;
  MdlBlendFactor aSrcBlendfactor;
  MdlBlendFactor aDstBlendfactor;
  MdlBlendEquation ablendEquation;
  MdlBlendEquation blendEquation;
};
class rdf_material
{
public:
  uint32_t uid;
  uint32_t DefUniformDataSize;
  rdf_shaderDefData const * DefUniformData;
  CHAR8 const * name;
  rdf_material_base const * baseProperties;
};

}

#endif
