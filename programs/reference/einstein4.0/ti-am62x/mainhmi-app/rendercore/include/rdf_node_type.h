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
#ifndef rdf_node_type_h
#define rdf_node_type_h


//Macro Definitions ...

namespace rendercore_engine
{

//Class Definitions ...
class rdf_renderstates
{
public:
  mdl_cullMode cullMode;
  mdl_depthTest depthTest;
  mdl_depthWrite depthWrite;
  MdlBlendFactor srcBlendfactor;
  MdlBlendFactor dstBlendfactor;
  MdlBlendFactor aSrcBlendfactor;
  MdlBlendFactor aDstBlendfactor;
  MdlBlendEquation ablendEquation;
  MdlBlendEquation blendEquation;
};
class rdf_3dnode
{
public:
  int32_t cameraIndex;
  int32_t lightIndex;
  int32_t skinIndex;
  int32_t meshIndex;
  uint32_t weights_size;
  mdl_nodeType_E type;
  GLfloat const * weights;
  void const * tnode;
};
class rdf_node
{
public:
  void const * tnode;
  mdl_nodeType_E type;
  int32_t nodeRotationIdx;
  int32_t nodeScaleIdx;
  int32_t nodeTranslationIdx;
  int32_t nodePivotIdx;
  int32_t matrix;
  float32_t opacity;
  uint32_t cullingmask;
  int32_t scissorrect;
  int32_t margin;
  int32_t flipBookIndex;
  int32_t skinId;
  bool visible;
  int32_t sorder;
  uint32_t nodes_size;
  int32_t num_behaviours;
  rc_behaviour_getinst const * behaviours;
  rdf_custpropDefDataArray const * beh_cdataDef;
  CHAR8 const * name;
  GLint const * nodes;
  rdf_renderstates const * render_states;
};
class rdf_3dtext_node
{
public:
  CHAR8 const * defText;
  uint32_t fontIndex;
  uint32_t bboxWidthPx;
  uint32_t bboxHeightPx;
  mdl_layoutHalign_E horzAlign;
  mdl_layoutValign_E vertAlign;
  float32_t drawColor[4];
  mdl_textOverflowMode_E oflowMode;
  int32_t charSpacing;
  mdl_mlWordWrap_E wordWrap;
  mdl_mlWordBreak_E wordBreak;
  uint32_t lineCount;
  uint32_t startLine;
  uint32_t maxLine;
  int32_t lineSpacing;
  char16_t hardCutChar;
  int32_t skinId;
  bool doTranslation;
  uint8_t outlineWidth;
  float32_t dropShadowOffset[2];
  float32_t effectColor[4];
  bool lbForSline;
};
class rdf_3dlayout_node
{
public:
  float32_t size[2];
  int32_t skinId;
  mdl_layoutHalign_E halign;
  mdl_layoutValign_E valign;
  mdl_layoutOrder_E order;
  mdl_layoutDirection_E direction;
  mdl_layoutOverflowMode_E oflowmode;
};

}

#endif
