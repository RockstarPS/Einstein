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
// Filename    : gfx3d_scg_layout.h
// Description : Docked layout for grouping of multiple nodes.
//	The parent node will have a position, all the children nodes' position will be decided
//	based on the position of its parent. 
//
//  Filename    : gfx3d_scg_layout.h
//  Description : GFX3D scene graph docked node object
//  Created on  : 24-Jun-2019 by amorwal@visteon.com
///////////////////////////////////////////////////////////////////////////////

/// @file  gfx3d_scg_layout.h													
/// brief\ header file for docked layout class
#ifndef gfx3d_scg_layout_H_
#define gfx3d_scg_layout_H_
namespace rendercore_engine
{
    /// \ingroup Engine
    /// @{
    /// <summary>
	/// class facilitating stack layout feature.
    /// Supports
    /// - direction : vertical, horizontal
    /// - order : normal, reverse
    /// - alignment(vertical - top, center, bottom, horizontal - left, center, right)
    /// Only one level of child groups supports 
    /// means
    ///     P1
    ///         ->Child1_Level0
    ///         ->Child2_Level0
    ///         ->  ->Child2_Child1_Level1  -- supported
    ///         ->Child3_Level0
    ///         ->  ->Child3_Child1_Level1
    ///         ->  ->  ->Child3_Child1_Level2  -- not supported
    /// Margin only support at leaf nodes, not on groups
    ///
    /// </summary>
	/// \see rendercore_engine::gfx3d_scg_node
	class gfx3d_scg_layout : public gfx3d_scg_node
	{
	private:
        bool calculateForClip = false;          ///< calculate scissor rect is costly so decide based on condition
	protected:
		float32_t layoutWidth = 0.0F;                                               ///< width of the layout in model space
		float32_t layoutHeight = 0.0F;                                              ///< height of the layout in model space
        float32_t xoffset = 0.0F;							                        ///< X offset based on the number of nodes
        float32_t yoffset = 0.0F;						                            ///< Y offset based on the number of nodes
        mdl_layoutOrder_E order = mdl_layoutOrder_E::oNormal;                   ///< layout ordering, how the items are ordered
		mdl_layoutHalign_E hAlign = mdl_layoutHalign_E::hLeft;				    ///< right, center, left, describes the alignment of the layout nodes, used only when anchor is top or bottom
		mdl_layoutValign_E vAlign = mdl_layoutValign_E::vTop;				    ///< top, center, bottom, describes the alignment of the layout nodes, used only when anchor is left or right
		mdl_layoutDirection_E direction = mdl_layoutDirection_E::dHorizontal;	///< direction, either vertical or horizontal.
        mdl_layoutOverflowMode_E oflowMode = mdl_layoutOverflowMode_E::ovRemove;	///< overflow mode 

        void addToRenderList(const size_t p_cmask) override; 	//overriding addToRenderList so if crop overflow mode used, layout node can be push for rendercall

	public:
        /// <summary>
        /// Constructs a layout object
        /// </summary>
        /// <param name="p_parent"> parent display this accessor belongs to </param>
        gfx3d_scg_layout(gfx3d_scg_node * const p_parent);
        /// Copy construct
        gfx3d_scg_layout(const gfx3d_scg_layout& p_obj);
        /// Performs a shallow copy..
        gfx3d_scg_layout& operator=(const gfx3d_scg_layout& p_rhs) = delete;
        /// Distructor
        virtual ~gfx3d_scg_layout();
        /// <summary>
        /// pre render override. performs actions before the renderloop
        /// \see rendercore_engine::gfx3d_scg_node::pre_render()
        /// </summary>
        /// <param name="p_par_matrix"> parent model matrix </param>
        /// <param name="p_visible"> parent visible or not</param>
        virtual void pre_render(const gfx3d_4x4mat& p_par_matrix, const bool p_visible, const rc_prmode p_mode, const uint32_t p_depth) override;
        /// <summary>
        /// render override. performs actions for the renderloop
        /// \see rendercore_engine::gfx3d_scg_node::render()
        /// </summary>
        /// <param name="p_prim"> primitive to be rendered </param>
        virtual void render(gfx3d_scg_primitive * const p_prim) override;
        /// <summary>
        /// Get the layout order
        /// </summary>
        mdl_layoutOrder_E GetLayoutOrder() const;
        /// <summary>
        /// Get the layout horizontal alignment
        /// </summary>
        mdl_layoutHalign_E GetLayoutHAlign() const;
        /// <summary>
        /// Get the layout vertical alignment
        /// </summary>
        mdl_layoutValign_E GetLayoutVAlign() const;
        /// <summary>
        /// Get the layout direction
        /// </summary>
        mdl_layoutDirection_E GetLayoutDirection() const;
        /// <summary>
        /// Get the layout width in model space
        /// </summary>
        float32_t GetLayoutWidth() const;
        /// <summary>
        /// Get the layout height in model space
        /// </summary>
        float32_t GetLayoutHeight() const;
        /// <summary>
        /// Set the layout order
        /// </summary>
        /// <param name="p_order"> layout order </param>
        void SetLayoutOrder(const mdl_layoutOrder_E p_order);
        /// <summary>
        /// Set the layout horizontal alignment
        /// </summary>
        /// <param name="p_halign"> layout horizontal alignment </param>
        void SetLayoutHAlign(const mdl_layoutHalign_E p_halign);
        /// <summary>
        /// Set the layout vertical alignment
        /// </summary>
        /// <param name="p_valign"> layout vertical alignment </param>
        void SetLayoutVAlign(const mdl_layoutValign_E p_valign);
        /// <summary>
        /// Set the layout direction
        /// </summary>
        /// <param name="p_direction"> layout direction</param>
        void SetLayoutDirection(const mdl_layoutDirection_E p_direction);
        /// <summary>
        /// Set the layout width in model space
        /// </summary>
        /// <param name="p_value"> layout width </param>
        void SetLayoutWidth(const float32_t p_value);
        /// <summary>
        /// Set the layout height in model space
        /// </summary>
        /// <param name="p_value"> layout height </param>
        void SetLayoutHeight(const float32_t p_value);
        /// <summary>
       /// Set the layout Overflow mode
       /// </summary>
       /// <param name="p_value"> layout mode </param>
        void SetOverflowMode(const mdl_layoutOverflowMode_E p_oflowMode);
        /// <summary>
       /// Get the layout Overflow mode
       /// </summary>
        mdl_layoutOverflowMode_E GetOverflowMode() const;
	};
    /// @}
}
#endif