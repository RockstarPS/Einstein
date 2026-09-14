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
#ifndef rdf_project_type_h
#define rdf_project_type_h


//Macro Definitions ...
#define RDF_HDR_VMAJOR (13)
#define RDF_HDR_VMINOR (0)
#define RDF_HDR_VPATCH (0)

namespace rendercore_engine
{
enum class rdf_hdr_version
{
  major=13
 ,minor=0
 ,patch=0
 ,Count=3
 ,Invalid=-1
};

//Class Definitions ...
class rdf_assetgroup
{
public:
  CHAR8 const * assetfile;
  int32_t assetgroup;
  int32_t shared;
};
class rdf_project
{
public:
  uint32_t num_displays;
  uint32_t num_fonts;
  MdlFontEngine f_engine;
  MdlCoordSystem coordSys;
  RcVersion generatorAppVersion;
  RcVersion generatorDllVersion;
  rdf_display const * const * displays;
  rdf_font const * const * fonts;
  bool locz_compressed;
  uint32_t assetgroups_size;
  rdf_assetgroup const * assetgroups;
  int32_t globalasset_id;
  char32_t dflt_character;
};

}

#endif
