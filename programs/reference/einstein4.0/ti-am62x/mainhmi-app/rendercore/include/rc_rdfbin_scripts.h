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
#ifndef rc_rdfbin_scripts_h
#define rc_rdfbin_scripts_h

namespace rendercore_engine
{
    /// <summary>
    /// Get the function pointer to create an instance of the script at 'p_scriptIndex'
    /// </summary>
    /// <param name="p_scriptIndex">Index of the script</param>
    /// <returns>function pointer or nullptr</returns>
    rc_behaviour_getinst RcRdfBinGetBehaviourGetinst(const uint32_t p_scriptIndex);
    /// <summary>
    /// Returns the MS time stamp (Year-Month-Day) of the generated rc_rdfbin_scripts.cpp
    /// It must be used to validate with the generated rdf binary file to 
    /// makesure rc_rdfbin_scripts.cpp and the rdf bin are matching
    /// </summary>
    /// <returns>MS time stamp</returns>
    uint32_t RcRdfBinGetMSTimeStamp();
    /// <summary>
    /// Returns the LS time stamp (Hour-Min-Sec-MSec) of the generated rc_rdfbin_scripts.cpp
    /// It must be used to validate with the generated rdf binary file to 
    /// makesure rc_rdfbin_scripts.cpp and the rdf bin are matching
    /// </summary>
    /// <returns>LS time stamp</returns>
    uint32_t RcRdfBinGetLSTimeStamp();
}

#endif
