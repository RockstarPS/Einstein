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
//  Filename    : rc_2dmesh.h
//  Description : 2D mesh object
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef rc_2dmesh_h
#define rc_2dmesh_h

namespace rendercore_engine
{
    /// <summary>
    /// Support class for the rc_2dimage class. Holds the vertex data and material
    /// Note:- This class shouldnot be used standalone. Its written for usage by rc_2dimage
    /// Else it may cause memory leaks.
    /// </summary>
    class rc_2dmesh : public gfx3d_scg_mesh
    {
    private:
    public:
        rc_2dmesh(gfx3d_scg_display* const p_dsp, const gfx3d_scg_node* const p_parent);  ///< constructs a 2d mesh object
        /// <summary>
        /// TODO : implement later
        /// </summary>
        /// <param name="p_rhs">source object to copy from</param>
        rc_2dmesh(const rc_2dmesh& p_rhs) = delete;
        /// <summary>
        /// TODO : implement later
        /// </summary>
        /// <param name="p_rhs">source object to copy from</param>
        rc_2dmesh& operator=(const rc_2dmesh& p_rhs) = delete;
        /// <summary>
        /// Dtor
        /// </summary>
        virtual ~rc_2dmesh();
    };
}
#endif