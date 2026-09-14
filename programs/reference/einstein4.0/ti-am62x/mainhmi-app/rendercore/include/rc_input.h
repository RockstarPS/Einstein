///////////////////////////////////////////////////////////////////////////////
//
//                     CONFIDENTIAL VISTEON CORPORATION
//
// This is an unpublished work of authorship, which contains trade secrets,
// created in 2021. Visteon Corporation owns all rights to this work and
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
/// @file	rc_input.h
///	@brief 	Input event handling APIs
//  Created on  : 02-Mar-2021 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef rc_input_h
#define rc_input_h

#include <queue>

#include <mutex>  

namespace rendercore_engine
{
    /// <summary>
    /// Specifies how to prioratize touch event to nodes
    /// </summary>
    enum class rc_ntouch_priority
    {
        ntDepth,        ///< nodes which is closer to the camera receives touch first
        ntRenderOrder   ///< nodes rendered last receives the touch first
    };
    class gfx3d_scg_display;
    /// \ingroup Internal
    /// @{
    /// handles touch, gesture and key events
    /// Notes:
    /// 1) will not honor gl states effecting depth, as calculation based on matrix
    /// 2) mouse over is not supported
    /// 3) use as render2texture, touch events not supported
    class rc_input
    {
    private:
        const bool bEnabled;
        std::queue<rc_touch_data> touchDataQ;       ///< queue to buffer touch events reported by application
        std::queue<rc_gesture_data> gestureDataQ;   ///< queue to buffer gesture events reported by application
        std::vector<rc_touched_node> nodesToProcess;///< list of touch enabled nodes in active render cycle. Its internally populated by render loop
        size_t nodesToProcessCount = 0U;             ///< number nodes added in nodesToProcess (since nodesToProcess is not resized, this count is used to determine number of valid entries)
#ifndef RDF_GEN_BUILD
        std::mutex mutexTouchDataQ;                 ///< mutex to protect the touchDataQ and gestureDataQ as the application can add events from a different thread
#endif
        std::map<size_t, rc_touch> touchInputs;     ///< <touchID to touchEventHander> mapping. For every application reported touch ID, an event hander is mapped
        rc_gesture gestureInput;                    ///< Gesture input handler
        int32_t highestCamRenderOrder = INT32_MIN;  ///< Highest render order of the camera in nodesToProcess list 
        rc_ntouch_priority touchNodePriority = rc_ntouch_priority::ntDepth; ///< How nodes are prioratized for touch and gesture event processing
        void ProcessGesture();
        rc_keys keysInput;
    public:
        /// <summary>
        /// Constructs a input hander object
        /// </summary>
        /// <returns>instance of input hander</returns>
        rc_input(const gfx3d_scg_display* const p_disp);
        /// <summary>
        /// Distructs the input handler object
        /// </summary>
        virtual ~rc_input();
        /// <summary>
        /// Add a touch evet to the queue. Internally invoked
        /// </summary>
        /// <param name="p_data">touch data</param>
        void AddTouch(const rc_touch_data& p_data);
        /// <summary>
        /// Add a gesture evet to the queue. Internally invoked
        /// </summary>
        /// <param name="p_data">gesture data</param>
        void AddGesture(const rc_gesture_data& p_data);
        /// <summary>
        /// Add a key evet to the list. Internally invoked
        /// </summary>
        /// <param name="p_key">Key code</param>
        /// <param name="p_pressed">true - pressed, false - released </param>
        void AddKey(const rc_key_code p_key, const bool p_pressed);
        /// <summary>
        /// Adds a touch enabled node to the list(Internally invoked by renderloop).
        /// </summary>
        /// <param name="p_node">pointer to node in scenegraph</param>
        /// <param name="p_camera">camera that renders the node</param>
        void AddNode(gfx3d_scg_node* const p_node, const gfx3d_scg_camera* const p_camera);
        /// <summary>
        /// Touch event process loop (internally invoked).
        /// Pops events from the queue and delivers them to the topmost node
        /// that is in focus. Focus is determined by the node thats just beneth the 
        /// touch location. Provided that the node is rendered by camera with highest
        /// render order.
        /// </summary>
        void Process();
        /// <summary>
        /// After each rendercycle, the nodesToProcess[] are resetted to 
        /// allow latest set of nodes to be added again.
        /// </summary>
        void ResetNodes();
        /// <summary>
        /// Get the current priority selection for touch nodes
        /// </summary>
        /// <returns>priority selection</returns>
        rc_ntouch_priority GetTouchNodePriority();
        /// <summary>
        /// Sets the priority selection for touch nodes
        /// </summary>
        /// <param name="p_prio">priority selection</param>
        void SetTouchNodePriority(const rc_ntouch_priority p_prio);
        /// Returns true if the key is pressed 
        /// </summary>
        /// <param name="p_key">key code</param>
        /// <returns>true or false</returns>
        bool IsKeyUp(const rc_key_code p_key) const;
        /// <summary>
        /// Returns true if the key is pressed 
        /// </summary>
        /// <param name="p_key">key code</param>
        /// <returns>true or false</returns>
        bool IsKeyDn(const rc_key_code p_key) const;
        /// <summary>
        /// Returns true if the key is pressed 
        /// </summary>
        /// <param name="p_key">key code</param>
        /// <returns>true or false</returns>
        bool IsKey(const rc_key_code p_key) const;
    };
    /// @}
}
#endif
