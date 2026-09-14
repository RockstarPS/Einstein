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
#ifndef rdf_project_h
#define rdf_project_h


//Include Files ...
#include "rdf_types.h"
#include "rdf_display.h"
#include "rdf_font.h"
#include "rdf_project_type.h"
//Macro Definitions ...
//rdf project version: 13.0.0
#if (RDF_HDR_VMAJOR != 13)
 #error "Rdf header version and project data version mismatch..\n"
#endif // #if (RDF_HDR_VMAJOR != 13)

namespace rendercore_engine
{
enum class rdf_agid_e
{
  RC_ASSET_ID_0=0
 ,Count=1
 ,Invalid=-1
};

//Var externs ...
extern rdf_project const mdl_project;
extern rdf_assetgroup const mdl_assetgroup_agroups[1];

//Methods ...

}

#endif
