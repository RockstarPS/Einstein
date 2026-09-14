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
/// @file       gfx3d_render_lists.h
/// \brief      Implements a renderlists. 
///             Renderlist a collection of render batches. 
///             A batch is a sorted list, where primitives are grouped per a sort order.
///             RC_RLIST_INIT_PRIMSIZE specifies how many primitives can be part of a group / per sort order
///             By default an auto sorting is implemented, which means two grops are created per batch
///             one group for opeque nodes and one for transparent nodes
///               - render_list
///                 --- batch [0] <<< initial batch size is RC_RLIST_INIT_BATCHSIZE
///                     --- sort_order[0] / group [0]
///                         --- primitive_array[RC_RLIST_INIT_PRIMSIZE] <<< will be resized when threshold reached
///                     --- sort_order[1] / group [1]
///                     --- sort_order[N] / group [N]
///                 --- batch [1]
///                     --- sort_order[0] / group [0]
///                     --- sort_order[1] / group [1]
///                     --- sort_order[N] / group [N]
///                ............
//              Created on  : 02-Aug-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef gfx3d_render_lists_h
#define gfx3d_render_lists_h

#include <vector>

namespace rendercore_engine
{
    /// \ingroup Engine
    /// @{
    /// Sorting type
    enum class rc_rsortType
    {
        sortAuto,  ///< (default) All opeque primitives are placed in sort_order[0], transparant ones in sort_order[1]
        sortCustom ///< All primitives are placed in sort_order[x]. Where 'x' is set by application on a node basis. Default x=0.
                   ///< TODO : this selection is not implemented yet.
    };
    /// Sort indexes used in case of rc_rsortType::sortAuto
    enum class rc_autoSortIndex
    {
        asortOpeque, ///< Opeque node index
        asortTransp, ///< transparent node index
        asortSize    ///< size of sort_order[]
    };
    class gfx3d_scg_primitive;
    /// Each gfx3d_prim_list is a collection of nodes & their primitives to be drawn
    /// Its stored as a pair. nodeList[i] <--> primList[i]
    class gfx3d_prim_list
    {
    private:
        /// RC_RLIST_INIT_PRIMSIZE specifies initial size of primitive_array[]
        static const size_t RC_RLIST_INIT_PRIMSIZE = 50U;
        size_t order = static_cast<size_t>(SIZE_MAX);   ///< render order for this list
        size_t listSize = 0U; ///< number of primitives in the oPrimList[] & oNodeList[]
        std::vector<gfx3d_scg_primitive *> primList{ RC_RLIST_INIT_PRIMSIZE }; ///< contains the opeque primitives to be drawn
        std::vector<gfx3d_scg_node *> nodeList{ RC_RLIST_INIT_PRIMSIZE }; ///< contains the opeque primitives to be drawn
    public:
        /// <summary>
        /// Adds a primitive to list
        /// </summary>
        /// <param name="p_node">parent node for the primitive to be added</param>
        /// <param name="p_prim">primitive to be added</param>
        /// <returns>returns true if success, else false</returns>
        bool Add(gfx3d_scg_node * const p_node, gfx3d_scg_primitive * const p_prim, const size_t p_sortIndex);
        /// <summary>
        /// Clears the list and make no primitives present in list
        /// </summary>
        void Clear(void);
        /// <summary>
        /// Renders the primitives in list
        /// </summary>
		/// <param name="p_camCullMask">camera culling mask to be checked with nodes culling mask to decide if node to be rendered or not</param>
		/// <returns>returns true if atleast one primitive is drawn else false</returns>
        bool Render(const size_t p_camCullMask);
        /// <summary>
        /// get the number of nodes
        /// </summary>
        size_t GetNumNodes() const;
        /// <summary>
        /// Pointer to node at specified index
        /// </summary>
        /// <param name="p_index">index to primitive list (0 to GetNumNodes()-1)</param>
        /// <returns>sorted list</returns>
        gfx3d_scg_node* GetNodeEntry(const size_t p_index);
        /// <summary>
        /// Gets the rendering order for this list of nodes/primitives
        /// </summary>
        /// <returns>rendering order</returns>
        size_t GetOrder() const;
    };
    /// gfx3d_sorted_list is collection of sorted primitives lists
    /// Drawing will be performed from index 0 to index N
    /// To which index a primitive gets added depends on the sort type
    ///  - rc_rsortType::sortNone   : All primitives get added to index 0 / sortList[0] only
    ///  - rc_rsortType::sortAuto   : All opeque primitives get added to index 0 / sortList[0]
    ///                               All transparent primitives get added to index 1  
    ///  - rc_rsortType::sortCustom : All primitives get added to index specified by application
    class gfx3d_sorted_list
    {
    private:
        std::vector<gfx3d_prim_list> sortList{ static_cast<size_t>(rc_autoSortIndex::asortSize) }; ///< primitive list or batches; ///< primitive list or batches
        std::map<size_t, size_t> orderToIndexMap; // indicates the index of the sortOrder (p_sortIndex passed via API gfx3d_sorted_list::AddCustom) in sortList
        size_t numSortedList = 0U; // number of items in sortList
    public:
        /// <summary>
        /// Adds a primitive to list when rc_rsortType is sortAuto
		/// <param name="p_node">parent node for the primitive to be added</param>
		/// <param name="p_prim">primitive to be added</param>
		/// <param name="p_sortIndex">index prim to be sorted</param>
		/// <returns>returns true if success, else false</returns>
		/// </summary>
        bool AddAuto(gfx3d_scg_node * const p_node, gfx3d_scg_primitive * const p_prim, const rc_autoSortIndex p_sortIndex);
        /// <summary>
        /// Adds a primitive to list when rc_rsortType is sortCustom
        /// <param name="p_node">parent node for the primitive to be added</param>
        /// <param name="p_prim">primitive to be added</param>
        /// <param name="p_sortIndex">index prim to be sorted</param>
        /// <returns>returns true if success, else false</returns>
        /// </summary>
        bool AddCustom(gfx3d_scg_node* const p_node, gfx3d_scg_primitive* const p_prim, const size_t p_sortIndex = 0);
        /// <summary>
        /// Clears the list and make no primitives present in list
        /// </summary>
        void Clear(void);
        /// <summary>
        /// Renders the primitives in list
		/// <param name="p_camCullMask">camera culling mask to be checked with nodes culling mask to decide if node to be rendered or not</param>
		/// <returns>returns true if atleast one primitive is drawn else false</returns>
		/// </summary>
        bool RenderAuto(const size_t p_camCullMask);
		/// <summary>
        /// Renders the primitives in list
		/// <param name="p_camCullMask">camera culling mask to be checked with nodes culling mask to decide if node to be rendered or not</param>
		/// <returns>returns true if atleast one primitive is drawn else false</returns>
		/// </summary>
        bool RenderCustom(const size_t p_camCullMask);
		/// <summary>
		/// get the number of primitives
		/// </summary>
		size_t GetNumSortedList() const;
        /// <summary>
        /// Pointer to primitive list at specified index
        /// </summary>
        /// <param name="p_index">index to primitive list (0 to GetNumSortedList()-1)</param>
        /// <returns>sorted list</returns>
        gfx3d_prim_list* GetPrimListEntry(const size_t p_index);
        /// <summary>
        /// Check if the list is empty
        /// </summary>
        /// <returns>true if list empty</returns>
        bool IsEmpty() const;
    };    
    /// <summary>
	/// Renderlist class is to manage the list of primitives to be rendered.
    /// Renderlist sorts the primitives and sequences / order them  for rendering
	/// </summary>
    class gfx3d_render_list
    {
    private:
        /// RC_RLIST_INIT_BATCHSIZE specifies initial batch size
        static const size_t RC_RLIST_INIT_BATCHSIZE = 5U;
        size_t listSize = 0U; ///< number of batches in render list
        std::vector<gfx3d_sorted_list> batches = std::vector<gfx3d_sorted_list>(RC_RLIST_INIT_BATCHSIZE); ///< primitive list or batches
        mdl_depthTest lastDepthTest = mdl_depthTest::dtUnset;		///< depth testing. render state for the previously added primitive. USed to detect change
        MdlBlendFactor lastSrcBlendFactor = MdlBlendFactor::bfUnset;			///< blend mode. render state for the previously added primitive. USed to detect change
        MdlBlendFactor lastDstBlendFactor = MdlBlendFactor::bfUnset;            ///< blend mode. render state for the previously added primitive. USed to detect change
        rc_rsortType sortType = rc_rsortType::sortAuto; ///< specifies how to sort the renderlist
        void ResizeList(void); ///< Resizes the renderlist as the current batch reached full capacity
    public:
        /// <summary>
        /// Adds a node to active render list.
        /// </summary>
        /// <param name="p_node">node to be added</param>
        /// <returns>returns true if success, else false</returns>
        bool AddEmptyNode(gfx3d_scg_node* const p_node);
        /// <summary>
        /// Adds a primitive to active render list. Primitves will be added to p_sortIndex of the list (gfx3d_sorted_list)
        /// Adds a primitive to active render list. If auto sort is active primitives are added to opeque or transparent list
        /// </summary>
        /// <param name="p_node">parent node for the primitive to be added</param>
		/// <param name="p_prim">primitive to be added</param>
		/// <returns>returns true if success, else false</returns>
        bool Add(gfx3d_scg_node * const p_node, gfx3d_scg_primitive * const p_prim);
        /// <summary>
        /// Clears all the render list
        /// </summary>
        void Clear(void);
        /// <summary>
        /// Renders the primitives in render lists / batches
        /// </summary>
        /// <returns>returns true if atleast one primitive is drawn else false</returns>
        void Render(const size_t p_camCullMask);
        /// <summary>
        /// Set the sorting type
        /// </summary>
        /// <param name="p_sortType">rc_rsortType type.</param>
        void SetSortType(const rc_rsortType p_sortType);
        /// <summary>
        /// Get the sorting type
        /// </summary>
        rc_rsortType GetSortType() const;
        /// <summary>
        /// Returns the size of render list
        /// </summary>
        /// <returns>size of render list</returns>
        size_t GetListSize() const;
        /// <summary>
        /// Pointer to sorted list at specified index
        /// </summary>
        /// <param name="p_index">index to sorted list (0 to GetListSize()-1)</param>
        /// <returns>sorted list</returns>
        gfx3d_sorted_list* GetListEntry(const size_t p_index);
    };
    /// @}
}
#endif