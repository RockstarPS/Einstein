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
//  Filename    : gfx3dMeshBBox.h
//  Description : GFX3D behaviour mesh renderer object
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gfx3dMeshBBox.h
/// \brief GFX3D behaviour mesh bounding box object
#ifndef gfx3dMeshBBox_h
#define gfx3dMeshBBox_h

namespace rendercore_engine
{
    /// \ingroup Behaviour
    /// @{

    using gfx3dCamera = gfx3d_scg_camera;///< convenient short name for cameras
    using gfx3dMaterial = gfx3d_scg_material; ///< convenient short name for material
    using gfx3dTextMeshPro = gfx3d_scg_3dtext_node; ///< convinient name for text node

    /// @}
    /// \ingroup Behaviour
    /// @{

    /// <summary>
    /// Holds the bounding box of the mesh
    /// </summary>
    class gfx3dMeshBBox
    {
    private:
        glm::vec4 bbox_max{ 0.0F };  ///< maximum point of the bounding box
        glm::vec4 bbox_min{ 0.0F };  ///< minimum point of the bounding box
    public:
        /// <summary>
        /// Gets the bound rectangle maz xyz in model space.
        /// </summary>
        /// <returns>min xyz</returns>
        glm::vec3 GetMaxBBox() const;
        /// <summary>
        /// Gets the bound rectangle min xyz in model space.
        /// </summary>
        /// <returns>min xyz</returns>
        glm::vec3 GetMinBBox() const;
        /// <summary>
        /// Gets the disance from center to bound rectangle of the mesh in model space.
        /// Its half the width and height of the bound rectangle
        /// </summary>
        /// <returns>disance from center to bound rectangle</returns>
        glm::vec3 GetExtents() const;
        /// <summary>
        /// Gets the center point of bound rectangle in model space
        /// </summary>
        /// <returns>center point</returns>
        glm::vec3 GetCenter() const;
        /// <summary>
        /// Checks if the passed model space point falls within the bound recangle
        /// </summary>
        /// <param name="p_pos">position to be checked</param>
        /// <returns>true if point inside bounds. else false</returns>
        bool Contains(const glm::vec3 p_pos) const;
        /// <summary>
        /// Updates the bounding box. Called internally
        /// </summary>
        /// <param name="p_transform">parent transform object</param>
        void update_bbox(gfx3dTransform* const p_transform);
    };
    /// @}
}
#endif