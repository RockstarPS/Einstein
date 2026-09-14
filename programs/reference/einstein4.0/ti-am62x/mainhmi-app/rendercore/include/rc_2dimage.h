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
//  Filename    : rcore_image.h
//  Description : Image class. 
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef rc_2dimage_h
#define rc_2dimage_h

#include "rc_2dmesh.h"

namespace rendercore_engine
{
    /// <summary>
    /// Create a 2D image node that can be added to scene graph
    /// </summary>
    class rc_2dimage : public gfx3d_scg_node
    {
    private:
        gfx3dTexture2D* tex;       ///< Holds the textue information for the 2D image node
    public:
        /// <summary>
        /// Create 2D image node object by copying the mesh data from the p_parent
        /// i.e. p_parent also must be a 2D plane node.
        /// And allows the user to map a new texture on to the created rc_2dimage node
        /// </summary>
        /// <param name="p_parent">parent node in scene graph</param>
        /// <param name="p_name">name of the node</param>
        /// <returns></returns>
        rc_2dimage(gfx3d_scg_node* const p_parent, const std::string p_name);
        /// <summary>
        /// TODO : implement later
        /// </summary>
        /// <param name="p_rhs">source object to copy from</param>
        rc_2dimage(const rc_2dimage& p_rhs) = delete;
        /// <summary>
        /// TODO : implement later
        /// </summary>
        /// <param name="p_rhs">source object to copy from</param>
        rc_2dimage& operator=(const rc_2dimage& p_rhs) = delete;
        /// <summary>
        /// Dtor
        /// </summary>
        virtual ~rc_2dimage();
        /// <summary>
        /// Loads a decoded image data to 2D image node
        /// </summary>
        /// <param name="p_image"></param>
        /// <returns>true on success</returns>
        bool Load(const rc_imgDecoderData& p_image);
    };
}
#endif