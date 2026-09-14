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
//  Filename    : rc_touch.h
//  Description : Touch event handling APIs
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file	rc_touch.h
///	\brief 		custom string class APIs
#ifndef rc_touch_h
#define rc_touch_h

#include <mutex>  

namespace rendercore_engine
{
    /// \ingroup Internal
    /// @{
    /// Captures possible mouse events
    enum class rc_mouse_event
    {
        meMove,         ///< Mouse button / touch moving without down
        meDrag,		    ///< Mouse button / touch down and moving
        meDown,         ///< Mouse button just down / just touched (Active state)
        meUp,           ///< Mouse button / touch just released ()
        meCancel,       ///< Mouse event processing is cancelled, no more events until untouched (like rc_touch_data::freeze)
        meStationary    ///< Mouse at same position After the Down or move event is issues, status will be Stationary, until next event is detected
    };
    /// <summary>
    /// Direction of swipe gesture
    /// </summary>
    enum class rc_gesture_swipe_direction
    {
        sdLeft,
        sdRight,
        sdUp, 
        sdDown
    };
    /// <summary>
    /// Supported gesture types
    /// </summary>
    enum class rc_gesture_type
    {
        gtNone,       ///< gesture inactive / no gesture  
        gtSwipeLeft,  ///< swipe or fling
        gtSwipeRight, ///< swipe or fling
        gtSwipeUp,    ///< swipe or fling
        gtSwipeDown,  ///< swipe or fling
        gtScaleBegin, ///< Zoom or pinch started (Down event)
        gtScale,      ///< zoom or pinch is currently running
        gtScaleEnd    ///< Zoom or pinch is ended (up event)
    };
    /// Holds the touch event data
    class rc_touch_data
    {
    public:
        glm::vec3 position;     ///< xy position or touch co ordinate
        float32_t scrollDelta;  ///< scroll wheel delta incase of a mouse
        float32_t deltaTime;    ///< time difference from the detection of button down
        size_t    touchID;      ///< ID of touch. Stays constant from finger down till finger up
        rc_mouse_event touchEvent;  ///< mouse or touch event
        bool freeze;            ///< when a selected item goes inactive , the mouse events are freezed until the Up event is received..
        uint8_t touchIndex;     ///< Index of the touch (internally set). Index of a touch can change if a preceding touch got released. 0 will be first touch, 1 second touch and so on..
        bool inFocus;           ///< Is this node in focus? (pointer inside the boundbox)
        rc_touch_data();
        virtual ~rc_touch_data();
    };
    class rc_gesture_data
    {
    public:
        rc_gesture_type type = rc_gesture_type::gtNone;
		glm::vec3 position;     ///< first touched x,y point in case of swipe, and focused Point(calculated between the multi touches) in case of Zoom/Pinch 
        float32_t scaleFactor = 1.0F; 
        glm::vec2 velocity;           
    };
    class gfx3d_scg_camera;
    /// Touch processing
    /// 
    /// to hold info about the touched node.
    class rc_touched_node
    {
    private:
        gfx3d_scg_node* node = nullptr;             ///< scenegraph node
        const gfx3d_scg_camera* camera = nullptr;   ///< Camera of this node
        glm::fmat4x4 mmx = glm::fmat4x4(1.0F);      ///< Model matrix for this node
        bool valid = false;             ///< True if this node is touch active state
        bool bboxCalculated = false;    ///< True if the bound box is calculated
        std::array<float32_t, 5> bbox   ///< Bounding box of this node
        {
            {0.0F,0.0F,0.0F,0.0F,0.0F}
        }; //0 - minx, 1 - miny, 2 - maxx, 3- maxy, 4 - zmin
    public:
        /// <summary>
        /// Gets the node
        /// </summary>
        /// <returns>node</returns>
        gfx3d_scg_node* GetNode() const;
        /// <summary>
        /// Sets the node
        /// </summary>
        /// <param name="p_node">node</param>
        void SetNode(gfx3d_scg_node* const p_node);
        /// <summary>
        /// Gets the camera of the node
        /// </summary>
        /// <returns>camera</returns>
        const gfx3d_scg_camera* GetCamera() const;
        /// <summary>
        /// Sets the camera of the node
        /// </summary>
        /// <param name="p_camera">camera object</param>
        void SetCamera(const gfx3d_scg_camera* const p_camera);
        /// <summary>
        /// Checks if this node as valid. Node becomes valid if any touch position
        /// is found to be inside its bound box by CheckBoundingBox.
        /// </summary>
        /// <returns></returns>
        bool IsValid() const;
        /// <summary>
        /// Sets the node data validity
        /// </summary>
        /// <param name="p_isValid">validity</param>
        void SetIsValid(const bool p_isValid);
        /// <summary>
        /// Gets the bounding box
        /// </summary>
        /// <returns>bounding box</returns>
        const std::array<float32_t, 5>& GetBoundingBox() const;
        /// <summary>
        /// Sets the bounding box
        /// </summary>
        /// <param name="p_bbox">bounding box to be set</param>
        void SetBoundingBox(const std::array<float32_t, 5>& p_bbox);
        /// <summary>
        /// 1. Calculates the bounding box if not already done
        /// 2. Validates the passed position is within the bound box 
        /// 3. If bbox is within position, then sets the node as valid and returns true
        ///    else returns false.
        /// </summary>
        /// <param name="p_position">position to be checked</param>
        /// <returns>true or false</returns>
        bool CheckBoundingBox(const glm::vec3& p_position);
        /// <summary>
        /// Gets the depth of the node.
        /// </summary>
        /// <returns>depth of the node</returns>
        float32_t GetNodeDepth() const;
    };

    /// handles a single touch
    class rc_touch
    {
    private:
        rc_touched_node touchedNode;    ///< Holds info about the touched node
        rc_touch_data   touchData;      ///< holds the last set touch data
        bool active = false;            ///< True if the touch is active
        void update_behaviour(const bool p_prevFocus) const;
    public:
        /// <summary>
        /// creates a touch
        /// </summary>
        rc_touch();
        /// <summary>
        /// touch destructor
        /// </summary>
        virtual ~rc_touch();
        /// <summary>
        /// Returns the node information for this touch
        /// </summary>
        /// <returns>node info</returns>
        const rc_touched_node& GetTouchedNode() const;
        /// <summary>
        /// Sets the node for this touch. When the process detects that
        /// a node is being touched (touch position falls with i the 
        /// bounds of the node and is top most), it sets the node to
        /// touch handler. This allows the touch hander to forward further 
        /// events such as drag, release etc to the same node.
        /// </summary>
        /// <param name="p_node">node info</param>
        void SetTouchedNode(const rc_touched_node& p_node);
        /// <summary>
        /// Returns wheather the this touch is in active state
        /// i.e. a node is being set via SetTouchedNode()..
        /// </summary>
        /// <returns>true or false</returns>
        bool IsActive() const;
        /// <summary>
        /// Sets the touch to active state (true) or not (false)
        /// </summary>
        /// <param name="p_active">true or false</param>
        void SetIsActive(const bool p_active);
        /// <summary>
        /// Process a touch data event
        /// </summary>
        /// <param name="p_data">touch data</param>
        /// <returns>true if touch still active</returns>
        bool Process(const rc_touch_data& p_data);
        /// <summary>
        /// Process the current touch while there is no events
        /// Perfomed only to change the touch status to stationary
        /// </summary>
        void Process();
    };

    /// handles a single gesture
    class rc_gesture
    {
    private:
        rc_touched_node focusNode;    ///< Holds info about the touched node
        rc_gesture_data gestureData;    ///< Holds the last set gesture data
        bool active = false;            ///< True if the gesture is active
        void update_behaviour() const;// updates behaviour for gestures

    public:
        rc_gesture();
        virtual ~rc_gesture();
        /// <summary>
        /// Returns the node information for this Gesture
        /// </summary>
        /// <returns>node info</returns>
        const rc_touched_node& GetFocusNode() const;
        /// <summary>
        /// Sets the node for this gesture. When the process detects that
        /// a node is being touched (touch position falls with i the 
        /// bounds of the node and is top most), it sets the node to
        /// touch handler.
        /// </summary>
        /// <param name="p_node">node info</param>
        void SetFocusNode(const rc_touched_node& p_node);
        /// <summary>
        /// Returns wheather the this gesture is in active state
        /// i.e. a node is being set via SetFocusNode()..
        /// </summary>
        /// <returns>true or false</returns>
        bool IsActive() const;
        /// <summary>
        /// Sets the gesture to active state (true) or not (false)
        /// </summary>
        /// <param name="p_active">true or false</param>
        void SetIsActive(const bool p_active);
        /// <summary>
        /// Process a gesture data event
        /// </summary>
        /// <param name="p_gesture">gesture data</param>
        /// <returns>true if gesture is still active</returns>
        bool Process(const rc_gesture_data& p_gesture);

    };
    /// @}
}
#endif
