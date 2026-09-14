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
//  Filename    : gfx3dMesh.h
//  Description : GFX3D behaviour mesh object
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gfx3dMesh.h
/// \brief GFX3D behaviour mesh object
#ifndef gfx3dMesh_h
#define gfx3dMesh_h

namespace rendercore_engine
{
    /// \ingroup Behaviour
    /// @{
    /// <summary>
    /// mesh class to support procedural mesh creation from script
    /// </summary>
    class gfx3dMesh
    {
    private:
        static const size_t maxUVSet = static_cast<size_t>(8);
        struct gfx3dMeshAttrib
        {
            GLuint UV[maxUVSet];
            GLuint Vertices;
            GLuint Normals;
            GLuint Triangles;
            GLuint Colors;
        }lGlVBuffer;
        struct gfx3dMeshAttribValid
        {
            bool Vertices;
            bool Triangles;
        }lGlVBufferValid;
        gfx3d_scg_primitive* prim;
        bool SetArribute(const GLuint p_glid, const glm::vec3* const p_data, const size_t p_length) const;
        bool SetArribute(const GLuint p_glid, const glm::vec4* const p_data, const size_t p_length) const;
    public:
        gfx3dMesh(gfx3d_scg_primitive* const p_prim);
        ~gfx3dMesh();
        void Clear();
        void SetUV(const glm::vec2* const p_data, const size_t p_length, const size_t p_uvset = 0U) const;
        void SetVertices(const glm::vec3* const p_data, const size_t p_length);
        void SetNormals(const glm::vec3* const p_data, const size_t p_length);
        void SetColors(const glm::vec4* const p_data, const size_t p_length);
        void SetTriangles(const int32_t* const p_data, const size_t p_length);
    };
    /// @}
}
#endif