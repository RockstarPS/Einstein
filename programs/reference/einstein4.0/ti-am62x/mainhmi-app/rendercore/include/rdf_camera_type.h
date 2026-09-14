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
#ifndef rdf_camera_type_h
#define rdf_camera_type_h


//Macro Definitions ...

namespace rendercore_engine
{

//Class Definitions ...
class rdf_camera
{
public:
  rdf_orthographic const * orthoCamProperties;
  rdf_perspective const * perspCamProperties;
  MdlCamType_E type;
  uint32_t cullingmask;
  int32_t render_order;
  bool clear_colorbuff;
  bool clear_depthbuff;
  float32_t clearcolor_value[4];
  float32_t cleardepth_value;
  float32_t viewport[4];
  mdl_cullMode cullMode;
  mdl_depthTest depthTest;
  mdl_depthWrite depthWrite;
  MdlBlendFactor srcBlendfactor;
  MdlBlendFactor dstBlendfactor;
  MdlBlendFactor aSrcBlendfactor;
  MdlBlendFactor aDstBlendfactor;
  MdlBlendEquation ablendEquation;
  MdlBlendEquation blendEquation;
  float32_t scissorrect[4];
  rc_rsortType sort_type;
  uint32_t num_renderPass;
  int32_t renderPass;
  int32_t skinId;
};

}

#endif
