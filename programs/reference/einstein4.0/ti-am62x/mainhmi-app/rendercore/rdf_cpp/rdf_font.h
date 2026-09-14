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
#ifndef rdf_font_h
#define rdf_font_h


//Include Files ...
#include "rdf_types.h"
#include "rdf_font_type.h"
//Macro Definitions ...

namespace rendercore_engine
{
enum class rdf_font_e
{
  fid_BaiJamjuree_Regular=0
 ,fid_BaiJamjuree_Regular_28_0=0
 ,fid_BaiJamjuree_Medium=1
 ,fid_BaiJamjuree_Medium_43_0=1
 ,fid_BaiJamjuree_Medium_inst2=2
 ,fid_BaiJamjuree_Medium_inst2_35_0=2
 ,fid_BaiJamjuree_Bold=3
 ,fid_BaiJamjuree_Bold_180_0=3
 ,fid_BaiJamjuree_Bold_inst4=4
 ,fid_BaiJamjuree_Bold_inst4_24_0=4
 ,fid_BaiJamjuree_Bold_inst5=5
 ,fid_BaiJamjuree_Bold_inst5_34_0=5
 ,fid_BaiJamjuree_Bold_inst6=6
 ,fid_BaiJamjuree_Bold_inst6_35_0=6
 ,fid_BaiJamjuree_Bold_inst7=7
 ,fid_BaiJamjuree_Bold_inst7_80_0=7
 ,fid_BaiJamjuree_Medium_inst8=8
 ,fid_BaiJamjuree_Medium_inst8_24_0=8
 ,fid_BaiJamjuree_Medium_inst9=9
 ,fid_BaiJamjuree_Medium_inst9_34_0=9
 ,fid_BaiJamjuree_Regular_inst10=10
 ,fid_BaiJamjuree_Regular_inst10_34_0=10
 ,fid_BaiJamjuree_Bold_inst11=11
 ,fid_BaiJamjuree_Bold_inst11_18_0=11
 ,Count=24
 ,Invalid=-1
};

//Var externs ...
extern rdf_font const * const fonts[12];
extern rdf_font const mdl_font_BaiJamjuree_Regular;
extern rdf_font const mdl_font_BaiJamjuree_Medium;
extern rdf_font const mdl_font_BaiJamjuree_Medium_inst1;
extern rdf_font const mdl_font_BaiJamjuree_Bold;
extern rdf_font const mdl_font_BaiJamjuree_Bold_inst1;
extern rdf_font const mdl_font_BaiJamjuree_Bold_inst2;
extern rdf_font const mdl_font_BaiJamjuree_Bold_inst3;
extern rdf_font const mdl_font_BaiJamjuree_Bold_inst4;
extern rdf_font const mdl_font_BaiJamjuree_Medium_inst2;
extern rdf_font const mdl_font_BaiJamjuree_Medium_inst3;
extern rdf_font const mdl_font_BaiJamjuree_Regular_inst1;
extern rdf_font const mdl_font_BaiJamjuree_Bold_inst5;

//Methods ...

}

#endif
