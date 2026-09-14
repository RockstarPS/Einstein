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
/// @file  rc_2dline.h
/// \brief 2D line drawing support
//  Created on  : 1-June-2021 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef rc_2dline_h
#define rc_2dline_h

namespace rendercore_engine
{
    /// <summary>
    /// Controls how the lines are joined
    /// </summary>
    enum class rc_lineJoin
    {
        ljMiter,    ///< Makes a sharp joint (default)
        ljSquare,   ///< Miter joint but the sharp corner is cut short
        ljRound     ///< Joint corner is rouded (with an arc)
    };
    /// <summary>
    /// Line start and end point cap.
    /// </summary>
    enum class rc_lineCap
    {
        lcSquare,   ///< Ends are flat (default)
        lcRound     ///< Rounded ends
    };
    enum class rc_lineMode
    {
        ldNew = 0U,         ///< Clears everything and adds as a new line
        ldAdd = 1U,         ///< Adds another independant line to existing 
        ldOptNew = ldNew,   ///< Clears everything and adds as a new line (remains temporarily for compatibility)
        ldOptAdd = ldAdd    ///< Adds another independant line to existing (remains temporarily for compatibility)
    };
    /// <summary>
    /// Holds the entire primitive / vertices
    /// </summary>
    class rc_2dlineprim
    {
    private:
        std::vector<glm::vec3> vertPos;     ///< vertex position data
        std::vector<glm::vec2> vertTex;     ///< vertex uv data
        std::vector<glm::vec4> vertColor;   ///< vertex color data
        std::vector<int32_t> vertIndex;     ///< indices data
    public:
        /// <summary>
        /// Clear the vertex data
        /// </summary>
        void Clear();
        /// <summary>
        /// Extend the vertex and index buffer memory storage by specified values
        /// new size will be newVertexSize = curVertexSize+p_abuff
        ///                  newIndexSize = curIndexSize+p_index
        /// </summary>
        /// <param name="p_abuff">vertex buffer size to extend</param>
        /// <param name="p_index">index buffer size to extend</param>
        /// <returns>true if buffer is extended</returns>
        bool Reserve(const size_t p_abuff, const size_t p_index);
        /// <summary>
        /// Adds the passed point to vertex buffer
        /// </summary>
        /// <param name="p_data">vertex data</param>
        /// <param name="p_data">vertex color data</param>
        /// <returns>true on success</returns>
        bool SetVertexPos(const glm::vec2& p_pos, const glm::vec4& p_color);
        /// <summary>
        /// Adds the passed point to vertex buffer
        /// </summary>
        /// <param name="p_data">vertex data</param>
        /// <param name="p_data">vertex color data</param>
        /// <param name="p_UV0">vertex uv data</param>
        /// <returns>true on success</returns>
        bool SetVertexPos(const glm::vec2& p_pos, const glm::vec4& p_color, const glm::vec2& p_UV0);
        /// <summary>
        /// Adds the passed point to vertex buffer
        /// </summary>
        /// <param name="p_data">vertex data</param>
        /// <param name="p_data">vertex color data</param>
        /// <returns>true on success</returns>
        bool SetVertexPos(const size_t p_index, const glm::vec2& p_pos);
        /// <summary>
        /// Adds the passed color to vertex color buffer
        /// This must be in sync with vertex position so donot use this API..
        /// its internally invoked by SetVertexPos
        /// </summary>
        /// <param name="p_data">vertex color data</param>
        /// <returns>true on success</returns>
        bool set_vertex_color(const glm::vec4& p_data);
        /// <summary>
        /// Adds the passed uv to vertex uv buffer
        /// This must be in sync with vertex position so donot use this API..
        /// its internally invoked by SetVertexPos
        /// </summary>
        /// <param name="p_data">vertex uv data</param>
        /// <returns>true on success</returns>
        bool set_vertex_uv0(const glm::vec2& p_UV0);
        /// <summary>
        /// Adds the passed index to indices buffer
        /// </summary>
        /// <param name="p_data">vertex index</param>
        /// <returns>true on success</returns>
        bool AddIndexData(const size_t p_data);
        /// <summary>
        /// Upload the mesh data to gfx3dMesh
        /// </summary>
        /// <param name="p_mesh">destination gfx3dMesh object</param>
        /// <returns>true on success</returns>
        bool UploadData(gfx3d_scg_mesh* const p_mesh);
        /// <summary>
        /// Upload the mesh data to gfx3dMesh for debug drawing only wire frame
        /// </summary>
        /// <param name="p_mesh">destination gfx3dMesh object</param>
        /// <returns>true on success</returns>
        bool UploadDataDebug(gfx3d_scg_mesh* const p_mesh, float32_t p_dbgthickness = 0.1F);
        /// <summary>
        /// Returns the current size of indices buffer
        /// </summary>
        /// <returns>length</returns>
        size_t GetIndexBuffLength() const;
        /// <summary>
        /// Returns the current size of vertex buffer
        /// </summary>
        /// <returns>length</returns>
        size_t GetVertexBuffLength() const;
    };
    /// <summary>
    /// 2D line support class. Assists in preperation of primitive data for drawing a line.
    /// </summary>
    class rc_2dline
    {
    private:
        rc_2dlineprim primData;                     ///< primitive data object.
        float32_t thickness = 1.0F;                 ///< Lin thickness >= 1.0F
        float32_t aAliaz = 1.0F;                    ///< Antialiaz level >= 1.0F
        float32_t miterLimit = 0.0F;                ///< limiting factor when lines join too steep
        glm::vec4 fgcolor{ 1.0F, 1.0F, 1.0F, 1.0F };///< Line color
        glm::vec4 bgcolor{ 1.0F, 1.0F, 1.0F, 0.0F };///< Edge color for antialiaz
        rc_lineCap lineCap = rc_lineCap::lcSquare;  ///< Line cap selection
        rc_lineJoin lineJoin = rc_lineJoin::ljMiter;///< Line joining selection
        size_t pointReadIndex = 0U;                 ///< Used internally for managing the reading of pionts to form rectangle
        float32_t minNumRoundJoints = 5.0F;         ///< Minimum number of joints to be used for round joint.
        std::vector<glm::vec2> uvCoords{ glm::vec2(+1.0F, +1.0F), glm::vec2(-1.0F, +1.0F), glm::vec2(+1.0F, -1.0F), glm::vec2(-1.0F, -1.0F) };
        bool useUVs = false;
        /// <summary>
        /// Performs a smooth joining (miter or round or square) of the points and generates a mesh
        /// </summary>
        /// <param name="p_points">sequence of points to form the line</param>
        /// <returns>true on success</returns>
        bool create_mesh_jsmooth(const std::vector<glm::vec2>& p_points);
        /// <summary>
        /// Extracts two points from the p_point list and returns the rectangle
        /// by extending the points by its normal by the given thickness of line
        /// incase the points are same, takes the next point until a rectangle can be formed
        /// </summary>
        /// <param name="p_point">points array</param>
        /// <param name="p_aa">if true generate a aa rect from index 4-7 of p_out</param>
        /// <param name="p_out">where the rectangle will be returned</param>
        /// <returns>true if rectangle loaded to p_out</returns>
        bool get_next_rect(const std::vector<glm::vec2>& p_point, const bool fl_aa, std::vector<glm::vec2>& p_out);
        /// <summary>
        /// Extracts first two points from the p_point list to form a rectangle
        /// internally invokes get_next_rect after resetting the read location to 
        /// start of the points list
        /// </summary>
        /// <param name="p_point">points array</param>
        /// <param name="p_aa">if true generate a aa rect from index 4-7 of p_out</param>
        /// <param name="p_out">where the rectangle will be returned</param>
        /// <returns>true if rectangle loaded to p_out</returns>
        bool get_first_rect(const std::vector<glm::vec2>& p_point, const bool fl_aa, std::vector<glm::vec2>& p_out);
        /// <summary>
        /// Finds the intersect point of outer or inner edges of two given rectangles
        /// </summary>
        /// <param name="p_side">inner edge or outer edge (0 / 1 depending on p_rec1 and p_rec2 0 may be inner or outer. use the p_inside to determine)</param>
        /// <param name="p_rec1">first rectangle</param>
        /// <param name="p_rec2">second rectangle</param>
        /// <param name="p_ipoint">intersect point output value</param>
        /// <param name="p_inside">true will be written if the passed side is inside edge</param>
        /// <returns>true on success</returns>
        static bool findIntersectPoint(const size_t p_side, std::vector<glm::vec2>& p_rec1, std::vector<glm::vec2>& p_rec2, glm::vec2& p_ipoint, bool& p_inside);
        /// <summary>
        /// Checks if point p_p falls inbetween points p_p1 and p_p2
        /// </summary>
        /// <param name="p_p1">start point</param>
        /// <param name="p_p2">end point</param>
        /// <param name="p_p">point to check</param>
        /// <returns>true if p_p is part of line formed by points p_p1 and p_p2, and is as well inside</returns>
        static bool isPointBetween(const glm::vec2& p_p1, const glm::vec2& p_p2, const glm::vec2& p_p);
        /// <summary>
        /// Creates vertices and triangulate an arc formed between points p_sp and p_ep and center of rotation p_pivot
        /// </summary>
        /// <param name="p_pivot">pivot of arc point</param>
        /// <param name="p_sp">start point</param>
        /// <param name="p_ep">end point</param>
        /// <param name="p_arc_pindex">vertex index for pivot</param>
        /// <param name="p_arc_sindex">vertex index for start point</param>
        /// <param name="p_arc_eindex">vertex index for end point</param>
        /// <returns>true on success</returns>
        bool create_arc(
            const glm::vec2& p_pivot,
            const glm::vec2& p_sp,
            const glm::vec2& p_ep,
            const size_t p_arc_pindex,
            const size_t p_arc_sindex,
            const size_t p_arc_eindex);
        /// <summary>
        /// Creates vertices and triangulate an arc formed between points p_sp and p_ep and center of rotation p_pivot
        /// </summary>
        /// <param name="p_pivot">pivot of arc point</param>
        /// <param name="p_sp">start point</param>
        /// <param name="p_ep">end point</param>
        /// <param name="p_arc_pindex">vertex index for pivot</param>
        /// <param name="p_arc_sindex">vertex index for start point</param>
        /// <param name="p_arc_eindex">vertex index for end point</param>
        /// <returns>true on success</returns>
        bool create_arc_aa(
            const glm::vec2& p_pivot,
            const glm::vec2& p_sp,
            const glm::vec2& p_ep,
            const size_t p_arc_sindex,
            const size_t p_arc_eindex);
        /// <summary>
        /// Validate the mitter limit if joining mode is mitter
        ///  - if mitter switch the joint mode if mitterlimit crosses threshold
        ///  - if not mitter just return the joining type as is
        /// </summary>
        /// <returns>joining type to be used</returns>
        rc_lineJoin validate_mitter_limit(const glm::vec2& p1, const glm::vec2& p2) const;
    public:
        rc_2dline();
        rc_2dline(const bool p_useUVs);
        /// <summary>
        /// Set the line joining type
        /// </summary>
        /// <param name="p_join">joining type</param>
        void SetLineJoining(const rc_lineJoin p_join);
        /// <summary>
        /// Get the line joining type 
        /// </summary>
        /// <returns>joining type</returns>
        rc_lineJoin GetLineJoining() const;
        /// <summary>
        /// Set the line cap type
        /// </summary>
        /// <param name="p_join">cap type</param>
        void SetLineCap(const rc_lineCap p_cap);
        /// <summary>
        /// Get the line cap type 
        /// </summary>
        /// <returns>cap type</returns>
        rc_lineCap GetLineCap() const;
        /// <summary>
        /// Gets the line joining length limit factor
        /// </summary>
        /// <returns>length limit factor</returns>
        float32_t GetLineMiterLimit() const;
        /// <summary>
        /// Sets the line joining length limit factor
        /// When the lines join too steep, this factor is applied to limit from line being
        /// extended infinitely. When the threshold crosses this limit, the joining will be
        /// changed to square internally.
        /// a value 0  means no limiting. > 0 will perform limiting
        /// </summary>
        /// <param name="p_limit">length limit factor</param>
        void SetLineMiterLimit(const float32_t p_limit);
        /// <summary>
        /// Prepares the mesh data for the passed line segment data.
        /// </summary>
        /// <param name="p_points">Line data as array of XY points</param>
        /// <param name="p_append">Specifes how the line data to be added</param>
        /// <returns>true on success</returns>
        bool AddLines(const std::vector<glm::vec2>& p_points, const rc_lineMode p_mode = rc_lineMode::ldNew);
        /// <summary>
        /// Prepares the mesh data for the passed line segment data.
        /// </summary>
        /// <param name="p_points">Line data as array of XY points</param>
        /// <param name="p_append">Specifes how the line data to be added</param>
        /// <returns>true on success</returns>
        bool AddLines(const std::vector<glm::vec2>&& p_points, const rc_lineMode p_mode = rc_lineMode::ldNew);
        /// <summary>
        /// Prepares the mesh data for the passed line segment data.
        /// </summary>
        /// <param name="p_points">Line data as array of XY points</param>
        /// <param name="p_append">Specifes how the line data to be added</param>
        /// <returns>true on success</returns>
        bool AddLines(const std::vector<glm::vec2>* const p_points, const rc_lineMode p_mode = rc_lineMode::ldNew);
        /// <summary>
        /// Sets the line thickness (>= 1.0F)
        /// </summary>
        /// <param name="p_thickness">thickness</param>
        void SetThickness(const float32_t p_thickness);
        /// <summary>
        /// Set the antialiaz level (must be >= 1.0F and <= Thickness)
        /// </summary>
        /// <param name="p_aa">antialiaz</param>
        void SetAntialiasSize(const float32_t p_aa);
        /// <summary>
        /// Sets the line color
        /// </summary>
        /// <param name="p_color">rgba color value</param>
        void SetFgColor(const glm::vec4& p_color);
        /// <summary>
        /// Sets the line edge color for antialiaz
        /// </summary>
        /// <param name="p_color">rgba color value</param>
        void SetBgColor(const glm::vec4& p_color);
        /// <summary>
        /// Sets the line color
        /// </summary>
        /// <param name="p_color">rgba color value</param>
        void SetFgColor(const glm::vec4&& p_color);
        /// <summary>
        /// Sets the line edge color for antialiaz
        /// </summary>
        /// <param name="p_color">rgba color value</param>
        void SetBgColor(const glm::vec4&& p_color);
        /// <summary>
        /// Gets the line thickness
        /// </summary>
        float32_t GetThickness() const;
        /// <summary>
        /// Get the antialiaz level
        /// </summary>
        float32_t GetAntialiasSize() const;
        /// <summary>
        /// Gets the line color
        /// </summary>
        glm::vec4 GetFgColor() const;
        /// <summary>
        /// Gets the line edge color for antialiaz
        /// </summary>
        /// <param name="p_color">rgba color value</param>
        glm::vec4 GetBgColor() const;
        /// <summary>
        /// Gets the minimum number of joints used for round joint
        /// </summary>
        /// <returns>minimum number of joints</returns>
        size_t GetMinNumRoundJoints() const;
        /// <summary>
        /// Sets the minimum number of joints needed for round joint
        /// this will be scaled up internally when the angle increases.
        /// Set a value > 3
        /// </summary>
        /// <param name="p_value">minimum number of joints</param>
        void SetMinNumRoundJoints(const size_t p_value);
        /// <summary>
        /// Uploads the prepared data to mesh
        /// </summary>
        /// <param name="p_mesh">target mesh</param>
        /// <returns></returns>
        bool UploadData(gfx3d_scg_mesh* const p_mesh);
        /// <summary>
        /// Uploads the prepared data to mesh (debugging purpose)
        /// </summary>
        /// <param name="p_mesh">target mesh</param>
        /// <returns></returns>
        bool UploadDataDebug(gfx3d_scg_mesh* const p_mesh);
    };
}

#endif
