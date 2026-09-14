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
//  Filename    : gfx3d_behaviour.h
//  Description : GFX3D behaviour object
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gfx3d_behaviour.h
/// \brief GFX3D behaviour object
#ifndef gfx3d_scg_behaviour_h
#define gfx3d_scg_behaviour_h

#include "gfx3d_scg_types.h"
#include "rc_color.h"
#include "gfx3d_behaviour_data.h"
#include "gfx3dMeshBBox.h"
#include "gfx3dMesh.h"
#include "rc_video_player.h"
#include "gfx3dTransform.h"
#include "gfx3d_scg_utils.h"
#include "gfx3d_scg_anim.h"
#include "rc_statemanager.h"
#include "gfx3d_scg_loadstatus.h"
#include "rc_2dline.h"
#include "rc_smartptr.h"
#include "gfx3d_scg_morph_target.h"

namespace rendercore_engine
{
    /// \defgroup Behaviour Behaviour Classes
    /// <summary>
    /// classes which support scripting
    /// </summary>
    /// \ingroup Behaviour
    /// @{
    /// <summary>
    /// Baseclass for behaviours. All the scripts inherit from this
    /// and implement their functionality
    /// base node -- node to which the script / behaviour is attached to
    /// </summary>
    class rdf_behaviour : public rc_time
    {
    private:
        std::vector<gfx3d_scg_anim*> activeAnims; ///< list animations which may issue callbacks to this behaviour
    protected:
        bool isDataValid(void) const;///< check if data valid
        std::vector<rc_touch_data> touchData; ///< Storage for the touch data per touch index
        std::vector<std::queue<rc_touch_data>> touchDataQ; ///< Storage for the touch data events queue for each index
        rc_gesture_data gestureTouchData; ///< Storage for the gesture data
        /// Default public data & its default values..
        std::map<rc_string, rdf_behData> pubPropertiesMap;
        size_t uid = 0U; ///< unique id for the script
        gfx3d_scg_display* display = nullptr; ///<  display object
        gfx3d_scg_node* gameObjTrsfm = nullptr;	///< base node's transform object. Control scale rotation etc.. 

    public:
        /// Sets the public properties default values list
        void SetPublicPropToDefaultValue(const rdf_custpropDefDataArray * const p_pmap);
        /// <summary>
        /// Set a single public property default value 
        /// </summary>
        void SetPublicPropToDefaultValue(const rdf_custpropDefData* const p_custData);
        /// Loads the behaviour by settingup default values
        /// \attention this API is internally invoked and not designed for invocation by application
        virtual void Load(void);
        /// UnLoads the behaviour
        /// \attention this API is internally invoked and not designed for invocation by application
        void UnLoad(void);
        /// Start method of a script. This gets invoked after the base node's scene gets loaded
        /// (Its a one time call on the scene load)
        /// \see rendercore_engine::gfx3d_scg_project::Load()
        /// \see rendercore_engine::gfx3d_scg_display::LoadScene()
        /// \see rendercore_engine::gfx3d_scg_display::Load()
        /// \attention this API is internally invoked and not designed for invocation by application
        virtual void Start(void);
        /// Update method of a script. This gets invoked on every render cycle, if the scene in which the 
        /// base node of the script is located is loaded
        /// \see rendercore_engine::gfx3d_scg_project::Render()
        /// \see rendercore_engine::gfx3d_scg_display::LoadScene()
        /// \see rendercore_engine::gfx3d_scg_display::Load()
        /// \attention this API is internally invoked and not designed for invocation by application
        virtual void Update(void);
        /// <summary>
        /// Resets the transient data after update cycle
        /// Internally invoked.
        /// </summary>
        void reset_transient_data(void);
        /// Invoked when the base node gets disabled
        /// \attention this API is internally invoked and not designed for invocation by application
        /// \attention TODO functionality not implemented
        virtual void OnDisable(void);
        /// Invoked when the base node gets enabled
        /// \attention this API is internally invoked and not designed for invocation by application
        /// \attention TODO functionality not implemented
        virtual void OnEnable(void);
        /// Invoked when rendercore detects a gesture event for the base node
        /// \attention this API is internally invoked and not designed for invocation by application
        void SetGesture(const rc_gesture_data& p_gesture_data);
#ifdef RC_CHRONO_FEATURE
        /// Returne the physics engine instance
        rc_physics_engine* GetPhysicsEngine();
        /// Initalizes the physics engine with required collision type
        void InitializeCollisionType(SystemType_E type);
#endif
        /// <summary>
        /// invoke this from script to get the last gesture data
        /// </summary>
        /// <returns>gesture data</returns>
        const rc_gesture_data GetGesture() const;
        /// Invoked when rendercore detects a touch event for the base node
        /// creates queue of events for each touch index
        /// \attention this API is internally invoked and not designed for invocation by application
        void SetTouch(const rc_touch_data p_touch_data);
        /// <summary>
        /// Invoke this from script to get the last Touch data
        /// Note : Incase all touch events received prior to this script execute cycle is needed, use 'GetTouchEvent' API instead.
        /// </summary>
        /// <param name="p_index">touch id. for single touch pass 0, for multi touch pass 0, 1.. to get corresponding touch data</param>
        /// <returns>returns the touch data </returns>
        const rc_touch_data GetTouch(const size_t p_index);
        /// <summary>
        /// Returns all the touch points (Internally uses GetTouch to construct the list)
        /// </summary>
        /// <returns>List of touch points</returns>
        const std::vector<rc_touch_data> GetTouches();
        /// <summary>
        /// Invoke this from script to get the next touch event data from the FIFO queue for the index.
        /// p_tdata is loaded only if the function returns a 'true'
        /// the fetched touch data will be popped from the respective queue
        /// </summary>
        /// <param name="p_index">touch id. for single touch pass 0, for multi touch pass 0, 1.. to get corresponding touch data</param>
        /// <param name="p_tdata">the next touch event data from the FIFO touch data queue for p_index</param>
        /// <returns>Returns true if p_tdata is successfully loaded with valid event, false if touch data queue is empty for the p_index</returns>
        bool GetTouchEvent(const size_t p_index, rc_touch_data& p_tdata);
        /// <summary>
        /// Returns the number of touches
        /// </summary>
        /// <returns>number of touches</returns>
        int32_t GetTouchCount() const;
        /// <summary>
        /// Returns the mouse position (same value as GetTouch(0))
        /// </summary>
        /// <returns>x,y position in pixel units</returns>
        glm::vec3 GetMousePosition();
        /// <summary>
        /// Center wheel scroll movement delya in y. 
        /// </summary>
        /// <returns>delta movement in y </returns>
        glm::vec2 GetMouseScrollDelta();
        /// <summary>
        /// Returns true if the mouse button is pressed, else return false
        /// </summary>
        /// <param name="p_button">button id (0 - left, 1 - right, 2 - middle button)</param>
        /// <returns></returns>
        bool GetMouseButton(const int32_t p_button);
        /// <summary>
        /// Returns true if the mouse button is pressed and released
        /// </summary>
        /// <param name="p_button">button id (0 - left, 1 - right, 2 - middle button)</param>
        /// <returns></returns>
        bool GetMouseButtonUp(const int32_t p_button);
        /// <summary>
        /// Returns true if the mouse button is pressed
        /// </summary>
        /// <param name="p_button">button id (0 - left, 1 - right, 2 - middle button)</param>
        /// <returns></returns>
        bool GetMouseButtonDown(const int32_t p_button);
        /// virtual fn what to do on Mouse down event
        virtual void OnMouseDown(void);
        /// called when the user has clicked and moving without releasing the button.
        virtual void OnMouseDrag(void);
        /// called when the mouse enters an elements area.
        virtual void OnMouseEnter(void);
        /// called when the mouse exits an elements area.
        virtual void OnMouseExit(void);
        /// called when the mouse is over an elements area.
        virtual void OnMouseOver(void);
        /// called when the mouse button is released.
        virtual void OnMouseUp(void);
        /// called when the mouse button is pressed & released inside the same element area.
        virtual void OnMouseUpAsButton(void);
        /// <summary>
        /// called when swipe/fling gesture occurs
        /// </summary>
        /// <param name="p_direction">Swipe direction , 0 -> Left , 1 -> Right , 2 -> Up, 3 -> Down</param>
        /// <param name="p_velocity">velocity</param>
        virtual void OnGestureSwipe(const rc_gesture_swipe_direction p_direction, const glm::vec2& p_velocity);
        /// <summary>
        /// called when pinch/zoom gesture begins
        /// </summary>
        virtual void OnGestureZoomBegin();
        /// <summary>
        /// called when pinch/zoom gesture is in progress
        /// </summary>
        /// <param name="p_scale"> scale factor, identify if it is pinch or zoom </param>
        virtual void OnGestureZoom(const float32_t p_scale);
        /// <summary>
        ///  called when pinch/zoom gesture ends.
        /// </summary>
        virtual void OnGestureZoomEnd();
        /// <summary>
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
        /// <summary>
        /// lookup an integer public property of this script by its name (p_name) and returns the value in p_out
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_out">pointer to an integer storage where the value can be written</param>
        /// \attention this API is for internal invokation
        virtual bool GetInt(const rc_string p_name, int32_t* const p_out) const;
        /// <summary>
        /// lookup an unsigned integer public property of this script by its name (p_name) and returns the value in p_out
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_out">pointer to an unsigned integer storage where the value can be written</param>
        /// \attention this API is for internal invokation
        virtual bool GetUInt(const rc_string p_name, uint32_t* const p_out) const;
        /// <summary>
        /// lookup an float32_t property and returns its value
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_out">pointer to an float32_t storage where the value can be written</param>
        /// \see GetInt(), follows same signature 
        virtual bool GetFloat(const rc_string p_name, float32_t* const p_out) const;
        /// <summary>
        /// lookup a Vector property and returns its value
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_out">pointer to a glm::vec2 storage where the value can be written</param>
        /// \see GetInt(), follows same signature 
        virtual bool GetVector(const rc_string p_name, glm::vec2* const p_out) const;
        /// <summary>
        /// lookup a Vector property and returns its value
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_out">pointer to a glm::vec3 storage where the value can be written</param>
        /// \see GetInt(), follows same signature 
        virtual bool GetVector(const rc_string p_name, glm::vec3* const p_out) const;
        /// <summary>
        /// lookup a Vector property and returns its value
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_out">pointer to a glm::vec4 storage where the value can be written</param>
        /// \see GetInt(), follows same signature 
        virtual bool GetVector(const rc_string p_name, glm::vec4* const p_out) const;
        /// <summary>
        /// lookup a Color property and returns its value
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_out">pointer to a glm::vec4 storage where the value can be written</param>
        /// \see GetInt(), follows same signature 
        virtual bool GetColor(const rc_string p_name, glm::vec4* const p_out) const;
        /// <summary>
        /// lookup a string property and returns its value
        /// </summary>
        /// \see GetInt(), follows same signature 
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_out">pointer to a rc_string storage where the value can be written</param>
        virtual bool GetString(const rc_string p_name, rc_string* const p_out) const;
        /// <summary>
        /// lookup a string property and returns its value
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_out">pointer to a rc_string storage where the value can be written</param>
        /// \see GetInt(), follows same signature 
        virtual bool GetWString(const rc_string p_name, rc_wstring* const p_out) const;
        /// <summary>
        /// lookup a MeshRenderer property and returns its value
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_out">pointer to a gfx3d_scg_mesh storage where the value can be written</param>
        /// \see GetInt(), follows same signature 
        virtual bool GetMeshRenderer(const rc_string p_name, gfx3d_scg_mesh** const p_out) const;
        /// <summary>
        /// lookup a material property and returns its value
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_out">pointer to a gfx3dMaterial storage where the value can be written</param>
        /// \see GetInt(), follows same signature 
        virtual bool GetMaterial(const rc_string p_name, gfx3dMaterial** const p_out) const;
        /// <summary>
        /// lookup a game object property and returns its value
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_out">pointer to a gfx3dGameObject storage where the value can be written</param>
        /// \see GetInt(), follows same signature 
        virtual bool GetGameObject(const rc_string p_name, gfx3d_scg_node** const p_out) const;
        /// <summary>
        /// lookup a camera object property and returns its value
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_out">pointer to a gfx3dCamera storage where the value can be written</param>
        /// \see GetInt(), follows same signature 
        virtual bool GetCamera(const rc_string p_name, gfx3dCamera** const p_out) const;
        /// <summary>
        /// lookup a text/label object property and returns its value
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_out">pointer to a gfx3dTextMeshPro storage where the value can be written</param>
        /// \see GetInt(), follows same signature 
        virtual bool GetTextMeshPro(const rc_string p_name, gfx3dTextMeshPro** const p_out) const;
        /// <summary>
        /// lookup a text/label object property and returns its value
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_out">pointer to a gfx3dTextMeshPro storage where the value can be written</param>
        /// \see GetInt(), follows same signature 
        virtual bool GetRCText(const rc_string p_name, gfx3dTextMeshPro** const p_out) const;
        /// <summary>
        /// lookup a transform object property and returns its value
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_out">pointer to a gfx3dTransform storage where the value can be written</param>
        /// \see GetInt(), follows same signature 
        virtual bool GetTransform(const rc_string p_name, gfx3dTransform** const p_out) const;
        /// <summary>
        /// lookup a float vector object property and returns its value
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_out">pointer to a vector of floats where the value can be written</param>
        /// \see GetInt(), follows same signature 
        virtual bool GetFloatList(const rc_string p_name, std::vector<float32_t>** const p_out) const;
        /// <summary>
        /// lookup a string vector object property and returns its value
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_out">pointer to a vector of strings where the value can be written</param>
        /// \see GetInt(), follows same signature 
        virtual bool GetStringList(const rc_string p_name, std::vector<rc_string>** const p_out) const;
        /// <summary>
        /// lookup a int vector object property and returns its value
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_out">pointer to a vector of ints where the value can be written</param>
        /// \see GetInt(), follows same signature 
        virtual bool GetIntList(const rc_string p_name, std::vector<int32_t>** const p_out) const;
        /// <summary>
        /// lookup a bool vector object property and returns its value
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_out">pointer to a vector of bools where the value can be written</param>
        /// \see GetInt(), follows same signature 
        virtual bool GetBoolList(const rc_string p_name, std::vector<bool>** const p_out) const;
        /// <summary>
        /// lookup a public integer property by its name and set a value to it
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_in">int value to be written</param>
        /// <returns>returns non zero on success </returns>
        /// \attention this API is for internal invocation
        virtual bool SetInt(const rc_string p_name, const int32_t p_in);
        /// <summary>
        /// lookup a public property by its name and set a value to it
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_in">unsigned int value to be written</param>
        /// <returns>returns non zero on success </returns>
        /// \see SetInt() for a description since it follows same signature 
        virtual bool SetUInt(const rc_string p_name, const uint32_t p_in);
        /// <summary>
        /// lookup a public property by its name and set a value to it
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_in">float32_t value to be written</param>
        /// <returns>returns non zero on success </returns>
        /// \see SetInt() for a description since it follows same signature 
        virtual bool SetFloat(const rc_string p_name, const float32_t p_in);
        /// <summary>
        /// lookup a public property by its name and set a value to it
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_in">glm::vec2 value to be written</param>
        /// <returns>returns non zero on success </returns>
        /// \see SetInt() for a description since it follows same signature 
        virtual bool SetVector(const rc_string p_name, const glm::vec2 p_in);
        /// <summary>
        /// lookup a public property by its name and set a value to it
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_in">glm::vec3 value to be written</param>
        /// <returns>returns non zero on success </returns>
        /// \see SetInt() for a description since it follows same signature 
        virtual bool SetVector(const rc_string p_name, const glm::vec3 p_in);
        /// <summary>
        /// lookup a public property by its name and set a value to it
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_in">glm::vec4 value to be written</param>
        /// <returns>returns non zero on success </returns>
        /// \see SetInt() for a description since it follows same signature 
        virtual bool SetVector(const rc_string p_name, const glm::vec4 p_in);
        /// <summary>
        /// lookup a public property by its name and set a value to it
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_in">glm::vec4 value to be written</param>
        /// <returns>returns non zero on success </returns>
        /// \see SetInt() for a description since it follows same signature 
        virtual bool SetColor(const rc_string p_name, const glm::vec4 p_in);
        /// <summary>
        /// lookup a public property by its name and set a value to it
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_in"> rc_string value to be written</param>
        /// <returns>returns non zero on success </returns>
        /// \see SetInt() for a description since it follows same signature 
        virtual bool SetString(const rc_string p_name, const rc_string p_in);
        /// <summary>
        /// lookup a public property by its name and set a value to it
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_in">rc_string value to be written</param>
        /// <returns>returns non zero on success </returns>
        /// \see SetInt() for a description since it follows same signature 
        virtual bool SetWString(const rc_string p_name, const rc_wstring p_in);
        /// <summary>
        /// lookup a public property by its name and set a value to it
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_in">gfx3d_scg_mesh value to be written</param>
        /// <returns>returns non zero on success </returns>
        /// \see SetInt() for a description since it follows same signature 
        virtual bool SetMeshRenderer(const rc_string p_name, gfx3d_scg_mesh* const p_in);
        /// <summary>
        /// lookup a public property by its name and set a value to it
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_in">gfx3dMaterial value to be written</param>
        /// <returns>returns non zero on success </returns>
        /// \see SetInt() for a description since it follows same signature 
        virtual bool SetMaterial(const rc_string p_name, gfx3dMaterial* const p_in);
        /// <summary>
        /// lookup a public property by its name and set a value to it
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_in">gfx3d_scg_node value to be written</param>
        /// <returns>returns non zero on success </returns>
        /// \see SetInt() for a description since it follows same signature 
        virtual bool SetGameObject(const rc_string p_name, gfx3d_scg_node* const p_in);
        /// <summary>
        /// lookup a public property by its name and set a value to it
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_in">gfx3dCamera value to be written</param>
        /// <returns>returns non zero on success </returns>
        /// \see SetInt() for a description since it follows same signature 
        virtual bool SetCamera(const rc_string p_name, gfx3dCamera* const p_in);
        /// <summary>
        /// lookup a public property by its name and set a value to it
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_in">gfx3dTransform value to be written</param>
        /// <returns>returns non zero on success </returns>
        /// \see SetInt() for a description since it follows same signature 
        virtual bool SetTransform(const rc_string p_name, gfx3dTransform* const p_in);
        /// <summary>
        /// lookup a public property by its name and set a value to it
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_in">gfx3dTextMeshPro value to be written</param>
        /// <returns>returns non zero on success </returns>
        /// \see SetInt() for a description since it follows same signature 
        virtual bool SetRCText(const rc_string p_name, gfx3dTextMeshPro* const p_in);
        /// <summary>
        /// lookup a public property by its name and set a value to it
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_in">gfx3dTexture2D value to be written</param>
        /// <returns>returns non zero on success </returns>
        /// \see SetInt() for a description since it follows same signature 
        virtual bool SetTexture2D(const rc_string p_name, gfx3dTexture2D* const p_in);
        /// <summary>
        /// lookup a public property by its name and set a value to it
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_out">float vector value to be written</param>
        /// \see SetInt() for a description since it follows same signature
        virtual bool SetFloatList(const rc_string p_name, std::vector<float32_t>* const p_in);
        /// <summary>
        /// lookup a public property by its name and set a value to it
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_out">string vector value to be written</param>
        /// \see SetInt() for a description since it follows same signature
        virtual bool SetStringList(const rc_string p_name, std::vector<rc_string>* const p_in);
        /// <summary>
        /// lookup a public property by its name and set a value to it
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_out">int vector value to be written</param>
        /// \see SetInt() for a description since it follows same signature
        virtual bool SetIntList(const rc_string p_name, std::vector<int32_t>* const p_in);
        /// <summary>
        /// lookup a public property by its name and set a value to it
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_out">bool vector value to be written</param>
        /// \see SetInt() for a description since it follows same signature
        virtual bool SetBoolList(const rc_string p_name, std::vector<bool>* const p_in);
        /// <summary>
        /// lookup a public property by its name and set a value to it
        /// </summary>
        /// <param name="p_name">name of property to look up</param>
        /// <param name="p_out">pointer to a rendercore_engine::gfx3dTexture2D storage where the value can be written</param>
        /// \see SetInt() for a description since it follows same signature 
        virtual bool GetTexture2D(const rc_string p_name, gfx3dTexture2D** const p_out) const;
        /// <summary>
        /// returns true if the script is valid to be executed
        /// </summary>
        /// \attention this API is for internal invocation
        virtual bool isValid(void);
        /// <summary>
        /// returns true if the script has an Update() method
        /// </summary>
        /// \attention this API is for internal invocation
        virtual bool isUpdateMethodPresent(void) const;
        /// <summary>
        /// returns true if there is any touch event handlings in the script (e.g. either OnMouseXYZ or Update)
        /// </summary>
        /// \attention this API is for internal invocation
        virtual bool isTouchEnabled(void) const;
        /// <summary>
        /// returns true if there is OnMouseXYZ event handlers in the script
        /// </summary>
        /// \attention this API is for internal invocation
        virtual bool isOnMousePresent(void) const;
        /// <summary>
        /// Returns the name of this behaviour
        /// </summary>
        /// <returns>name</returns>
        virtual const std::string& GetName() const;
        /// constructor 
        rdf_behaviour(gfx3d_scg_display* const p_display);
        /// distructor 
        virtual ~rdf_behaviour();
        /// <summary>
        /// get floating point property value by property name 'p_prop' from specified node name 'p_node'
        /// useful to acccess a public property another script from another node.
        /// \attention this involves string lookup and scring comparisons can be costly
        /// \see gfx3dTransform::GetFloatProperty() as this internally uses it
        /// <param name="p_node">name of property to look up</param>
        /// <param name="p_prop">std::string storage where the value can be written</param>
        /// </summary>
        float32_t GetNodeProperty(const std::string p_node, const std::string p_prop) const;
        /// <summary>
        /// get an integer property value by property name 'p_prop' from specified node name 'p_node'
        /// <param name="p_node">name of property to look up</param>
        /// <param name="p_prop">std::string storage where the value can be written</param>
        /// </summary>
        int32_t GetNodeIntProperty(const std::string p_node, const std::string p_prop) const;
        /// <summary>
        /// get a string property value by property name 'p_prop' from specified node name 'p_node'
        /// <param name="p_node">name of property to look up</param>
        /// <param name="p_prop">std::string storage where the value can be written</param>
        /// </summary>
        rc_string GetNodeStringProperty(const std::string p_node, const std::string p_prop) const;
        /// <summary>
        /// get property of a material
        /// <param name="p_node">name of property to look up</param>
        /// <param name="p_prop">std::string storage where the value can be written</param>
       /// </summary>
        float32_t GetMaterialProperty(const std::string p_node, const std::string p_prop) const;
        /// <summary>
        /// set property of a material
        /// <param name="p_node">node of property to look up</param>
        /// <param name="p_prop">name of the property to update</param>
        /// <param name="p_val">value to be set</param>
        /// </summary>
        void SetMaterialProperty(const std::string p_node, const std::string p_prop, const float32_t p_val) const;
        /// <summary>
        /// set float32_t value to given property of a node
        /// <param name="p_node">node of property to look up</param>
        /// <param name="p_prop">name of the property to update</param>
        /// <param name="p_val">value to be set</param>
        /// </summary>
        void SetNodeProperty(const std::string p_node, const std::string p_prop, const float32_t p_val);
        /// <summary>
        /// set float32_t value to given property of a node
        /// <param name="p_node">node of property to look up</param>
        /// <param name="p_prop">name of the property to update</param>
        /// <param name="p_val">value to be set</param>
        /// </summary>
        void SetNodeProperty(const std::string p_node, const std::string p_prop, const float64_t p_val);
        /// <summary>
        /// set float32_t value to given property of a node
        /// <param name="p_node">node of property to look up</param>
        /// <param name="p_prop">name of the property to update</param>
        /// <param name="p_val">value to be set</param>
        /// </summary>
        void SetNodeProperty(const std::string p_node, const std::string p_prop, const int32_t p_val);
        /// <summary>
        /// set text value to given property of a node
        /// <param name="p_node">node of property to look up</param>
        /// <param name="p_prop">name of the property to update</param>
        /// <param name="p_val">value to be set</param>
        /// </summary>
        void SetNodeProperty(const std::string p_node, const std::string p_prop, const rc_wstring p_val);
        /// <summary>
        /// set int property by gameobject
        /// <param name="p_go">gfx3d_scg_node to look up</param>
        /// <param name="p_prop">name of the property to update</param>
        /// <param name="p_val">value to be set</param>
        /// </summary>
        void SetNodeProperty(const gfx3d_scg_node* const p_go, const std::string p_prop, const int32_t p_val) const;
        /// <summary>
        /// set float32_t property by gameobject
        /// <param name="p_go">gfx3dGameObject of property to look up</param>
        /// <param name="p_prop">name of the property to update</param>
        /// <param name="p_val">value to be set</param>
        /// </summary>
        void SetNodeProperty(const gfx3d_scg_node* const p_go, const std::string p_prop, const float32_t p_val) const;
        /// <summary>
        /// set string property by gameobject
        /// <param name="p_go">gfx3d_scg_node of property to look up</param>
        /// <param name="p_prop">name of the property to update</param>
        /// <param name="p_val">value to be set</param>
        /// </summary>
        void SetNodeProperty(const gfx3d_scg_node* const p_go, const std::string p_prop, const rc_wstring p_val) const;
        /// <summary>
        /// Set the nodes flipbook index property by node name
        /// <param name="p_nodename">name of the node</param>
        /// <param name="p_index">value to be set</param>
        /// </summary>
        void SetNodeFlipBookIndex(const std::string p_nodename, const int32_t p_index);
        /// <summary>
        /// Set the nodes flipbook index property by node reference
        /// <param name="p_go">reference to the node</param>
        /// <param name="p_index">value to be set</param>
        /// </summary>
        void SetNodeFlipBookIndex(const gfx3d_scg_node* const p_go, const int32_t p_index) const;
        /// <summary>
        /// Set the nodes opacity index property by node name
        /// <param name="p_nodename">name of the node</param>
        /// <param name="p_opacity">value to be set</param>
        /// </summary>
        void SetNodeOpacity(const std::string p_nodename, const float32_t p_opacity);
        /// <summary>
        /// Set the nodes opacity index property by node name
        /// <param name="p_go">reference of the node</param>
        /// <param name="p_opacity">value to be set</param>
        /// </summary>
        void SetNodeOpacity(const gfx3d_scg_node* const p_go, const float32_t p_opacity) const;
        /// <summary>
        /// Returns the nodes flipbook index property by node name
        /// <param name="p_nodename">name of the node</param>
        /// </summary>
        int32_t GetNodeFlipBookIndex(const std::string p_nodename) const;
        /// <summary>
        /// Returns the nodes flipbook index property by node reference
        /// <param name="p_go">reference to the node</param>
        /// <param name="p_index">value to be set</param>
        /// </summary>
        int32_t GetNodeFlipBookIndex(gfx3d_scg_node* const p_go) const;
        /// <summary>
        /// Returns the nodes opacity index property by node name
        /// <param name="p_nodename">name of the node</param>
        /// <param name="p_opacity">value to be set</param>
        /// </summary>
        float32_t GetNodeOpacity(const std::string p_nodename) const;
        /// <summary>
        /// Returns the nodes opacity index property by node name
        /// <param name="p_go">reference of the node</param>
        /// <param name="p_opacity">value to be set</param>
        /// </summary>
        float32_t GetNodeOpacity(gfx3d_scg_node* const p_go) const;
        /// <summary>
        /// get floating point property value by property name 'p_prop' from specified GameObject 'p_go'
        /// <param name="p_go">name of gfx3d_scg_node to look up</param>
        /// <param name="p_prop">name of the property to get</param>
        /// </summary>
        float32_t GetNodeProperty(gfx3d_scg_node* const p_go, const std::string p_prop) const;
        /// <summary>
        /// get an integer property value by property name 'p_prop' from specified GameObject 'p_go'
        /// <param name="p_go">name of gfx3d_scg_node to look up</param>
        /// <param name="p_prop">name of the property to get</param>
        /// </summary>
        int32_t GetNodeIntProperty(gfx3d_scg_node* const p_go, const std::string p_prop) const;
        /// <summary>
        /// get a string property value by property name 'p_prop' from specified GameObject 'p_go'
        /// <param name="p_go">name of gfx3d_scg_node to look up</param>
        /// <param name="p_prop">name of the property to get</param>
        /// </summary>
        rc_string GetNodeStringProperty(gfx3d_scg_node* const p_go, const std::string p_prop) const;
        /// <summary>
        /// get property value of property name 'p_prop' from this node (node to which this behaviour is attached)
        /// <param name="p_prop">name of the property to get</param>
        /// </summary>
        float32_t GetThisNodeProperty(const std::string p_prop) const;
        /// <summary>
        /// get property value of property name 'p_prop' from this node (node to which this behaviour is attached)
        /// <param name="p_prop">name of the property to get</param>
        /// </summary>
        int32_t GetThisNodeIntProperty(const std::string p_prop) const;
        /// <summary>
        /// get property value of property name 'p_prop' from this node (node to which this behaviour is attached)
        /// <param name="p_prop">name of the property to get</param>
        /// </summary>
        rc_string GetThisNodeStringProperty(const std::string p_prop) const;
        /// <summary>
        /// set float32_t value to given property of this node(i.e node to which this behaviour is attached)
        /// <param name="p_prop">name of the property to set</param>
        /// <param name="p_val">value to be set</param>
        /// </summary>
        void SetThisNodeProperty(const std::string p_prop, const float32_t p_val);
        /// <summary>
        /// set integer value to given property of this node(i.e node to which this behaviour is attached)
        /// <param name="p_prop">name of the property to set</param>
        /// <param name="p_val">value to be set</param>
        /// </summary>
        void SetThisNodeProperty(const std::string p_prop, const int32_t p_val);
        /// <summary>
        /// set text value to given property of this node(i.e node to which this behaviour is attached)
        /// <param name="p_prop">name of the property to set</param>
        /// <param name="p_val">value to be set</param>
        /// </summary>
        void SetThisNodeProperty(const std::string p_prop, const rc_wstring p_val);
        /// <summary>
        /// Find animation by name attached to same node as this script
        /// <param name="p_animName">name of animation</param>
        /// </summary>
        gfx3d_scg_anim* FindAnimation(const std::string p_animName) const;
        /// <summary>
        /// Find animation by name attached to p_target gameobject
        /// </summary>
        /// <param name="p_target">target gameobject</param>
        /// <param name="p_animName">name of animation to lookup</param>
        /// <returns>pointer to animation if found, else nullptr</returns>
        gfx3d_scg_anim* FindAnimation(gfx3d_scg_node const* const p_target, const std::string p_animName) const;
        /// <summary>
        /// Find animation by name attached to p_transform
        /// </summary>
        /// <param name="p_target">target transform</param>
        /// <param name="p_animName">name of animation to lookup</param>
        /// <returns>pointer to animation if found, else nullptr</returns>
        gfx3d_scg_anim* FindAnimation(gfx3dTransform const* const p_transform, const std::string p_animName) const;
        /// <summary>
        /// Start the animation  
        /// Note :- back to back Start/Stop may not be accepted
        /// When animation is asked to Stop, it enters in to Stopping state and only after
        /// the animation state internally changes to stopped, only then a new Start command will
        /// succeed.
        /// <param name="p_animName">name of animation</param>
        /// <param name="p_notifyStateChange">if true, rendercore invokes this scripts OnAnimationStateChange() on animation state change.</param>
        /// </summary>
        /// <returns>Returns true if able to start animation, else false(maybe already playing)</returns>
        bool StartAnimation(const std::string p_animName, const bool p_notifyStateChange = false);
        /// <summary>
        /// Start the animation p_animName which is attached to node p_targetName
        /// </summary>
        /// <param name="p_targetName">node name to which the animation is attached</param>
        /// <param name="p_animName">name of the animation</param>
        /// <param name="p_notifyStateChange">if true, rendercore invokes this scripts OnAnimationStateChange() on animation state change.</param>
        /// <returns>Returns true if able to start animation, else false(maybe already playing)</returns>
        bool StartAnimation(const std::string p_targetName, const CHAR8* const p_animName, const bool p_notifyStateChange = false);
        /// <summary>
        /// Start the animation p_animName which is attached to node p_targetName
        /// </summary>
        /// <param name="p_targetName">node name to which the animation is attached</param>
        /// <param name="p_animName">name of the animation</param>
        /// <param name="p_notifyStateChange">if true, rendercore invokes this scripts OnAnimationStateChange() on animation state change.</param>
        /// <returns>Returns true if able to start animation, else false(maybe already playing)</returns>
        bool StartAnimation(const std::string p_targetName, const std::string p_animName, const bool p_notifyStateChange = false);
        /// <summary>
        /// Start the animation p_animName which is attached to node p_targetName
        /// </summary>
        /// <param name="p_target">gameobject of target node to which the animation is attached</param>
        /// <param name="p_animName">name of the animation</param>
        /// <param name="p_notifyStateChange">if true, rendercore invokes this scripts OnAnimationStateChange() on animation state change.</param>
        /// <returns>Returns true if able to start animation, else false(maybe already playing)</returns>
        bool StartAnimation(gfx3d_scg_node * const p_target, const std::string p_animName, const bool p_notifyStateChange = false);
        /// <summary>
        /// Start the animation p_animName which is attached to node p_targetName
        /// </summary>
        /// <param name="p_target">transfor object of target node to which the animation is attached</param>
        /// <param name="p_animName">name of the animation</param>
        /// <param name="p_notifyStateChange">if true, rendercore invokes this scripts OnAnimationStateChange() on animation state change.</param>
        /// <returns>Returns true if able to start animation, else false(maybe already playing)</returns>
        bool StartAnimation(gfx3dTransform const * const p_target, const std::string p_animName, const bool p_notifyStateChange = false);
        /// <summary>
        /// Stop the animation which is attached to the same node where this behaviour is attached.
        /// <param name="p_resetToStart">when stopped should animation set to start or end</param>
        /// <param name="p_animName">name of animation</param>
        /// <returns>Returns true if able to stop animation, else false</returns>
        /// </summary>
        bool StopAnimation(const std::string p_animName, const bool p_resetToStart = false);
        /// <summary>
        /// Stop the animation which is attached to the specified gameobject.
        /// </summary>
        /// <param name="p_target">gameobject where the animation is attached</param>
        /// <param name="p_animName">name of the animation</param>
        /// <param name="p_resetToStart">whether to reset the time to start (true) of animation while stopping or not (false)</param>
        /// <returns>Returns true if able to stop animation, else false</returns>
        bool StopAnimation(gfx3d_scg_node * const p_target, const std::string p_animName, const bool p_resetToStart = false);
        /// <summary>
        /// Stop the animation which is attached to the specified node.
        /// </summary>
        /// <param name="p_target">node where the animation is attached</param>
        /// <param name="p_animName">name of the animation</param>
        /// <param name="p_resetToStart">whether to reset the time to start (true) of animation while stopping or not (false)</param>
        /// <returns>Returns true if able to stop animation, else false</returns>
        bool StopAnimation(gfx3dTransform const * const p_target, const std::string p_animName, const bool p_resetToStart = false);
        /// <summary>
        /// Abort the animation inline at current position. Can issue a Start immediately after Abort.
        /// animation must be attached to the same node where this behaviour is attached.
        /// <param name="p_animName">name of animation</param>
        /// <returns>Returns true if able to stop animation, else false</returns>
        /// </summary>
        bool AbortAnimation(const std::string p_animName);
        /// <summary>
        /// Abort the animation inline at current position. Can issue a Start immediately after Abort.
        /// animation must be attached to the specified gameobject.
        /// </summary>
        /// <param name="p_target">gameobject where the animation is attached</param>
        /// <param name="p_animName">name of the animation</param>
        /// <returns>Returns true if able to stop animation, else false</returns>
        bool AbortAnimation(gfx3d_scg_node * const p_target, const std::string p_animName);
        /// <summary>
        /// Abort the animation inline at current position. Can issue a Start immediately after Abort.
        /// animation must be attached to the specified gfx3dTransform.
        /// </summary>
        /// <param name="p_target">node where the animation is attached</param>
        /// <param name="p_animName">name of the animation</param>
        /// <returns>Returns true if able to stop animation, else false</returns>
        bool AbortAnimation(gfx3dTransform const* const p_target, const std::string p_animName);
        /// <summary>
        /// Pause the animation which is attached to the same node where this behaviour is attached. 
        /// <param name="p_animName">name of animation</param>
        /// <returns>Returns true if able to pause animation, else false</returns>
        /// </summary>
        bool PauseAnimation(const std::string p_animName);
        /// <summary>
        /// Pause the animation which is attached to the specified gameobject.
        /// </summary>
        /// <param name="p_target">gameobject where the animation is attached</param>
        /// <param name="p_animName">name of the animation</param>
        /// <returns>Returns true if able to pause animation, else false</returns>
        bool PauseAnimation(gfx3d_scg_node * const p_target, const std::string p_animName);
        /// <summary>
        /// Pause the animation which is attached to the specified node.
        /// </summary>
        /// <param name="p_target">node where the animation is attached</param>
        /// <param name="p_animName">name of the animation</param>
        /// <returns>Returns true if able to pause animation, else false</returns>
        bool PauseAnimation(gfx3dTransform const * const p_target, const std::string p_animName);
        /// <summary>
        /// Resume the animation which is attached to the same node where this behaviour is attached. 
        /// <param name="p_animName">name of animation</param>
        /// <returns>Returns true if able to resume animation, else false</returns>
        /// </summary>
        bool ResumeAnimation(const std::string p_animName);
        /// <summary>
        /// Resume the animation which is attached to the specified gameobject.
        /// </summary>
        /// <param name="p_target">gameobject where the animation is attached</param>
        /// <param name="p_animName">name of the animation</param>
        /// <returns>Returns true if able to resume animation, else false</returns>
        bool ResumeAnimation(gfx3d_scg_node * const p_target, const std::string p_animName);
        /// <summary>
        /// Resume the animation which is attached to the specified node.
        /// </summary>
        /// <param name="p_target">node where the animation is attached</param>
        /// <param name="p_animName">name of the animation</param>
        /// <returns>Returns true if able to resume animation, else false</returns>
        bool ResumeAnimation(gfx3dTransform const * const p_target, const std::string p_animName);
        /// <summary>
        /// callback function to animation state change  
        /// <param name="p_animName">name of animation</param>
        /// <param name="p_state">name of animation</param>
        /// </summary>
        /// \attention this API is internally invoked
        virtual void OnAnimationStateChange(const rc_string p_animName, const int32_t p_state);
        /// <summary>
        /// Sets the current "timeLine" variable of this script
        /// </summary>
        /// \attention this API is internally invoked
        void SetTime(const rc_time& p_timeLine);
        /// <summary>
        /// Creates an instance of this script and returns it
        /// </summary>
        /// \attention this API is internally invoked
        virtual rdf_behaviour* CreateInstance(gfx3d_scg_display* const p_display);
        /// <summary>
        /// Returns the public property map
        /// </summary>
        /// \attention this API is for internal debug purpose
        const std::map<rc_string, rdf_behData>& GetPublicProperty() const;
        /// Returns the unique ID for this script.
        size_t GetUID(void) const;
        /// <summary>
        /// Sets the transform object for this behaviour (attached node)
        /// </summary>
        /// <param name="p_transform">transform</param>
        void SetTransform(gfx3d_scg_node* const p_transform);
        /// <summary>
        /// Sets the parent display for this behaviour
        /// </summary>
        /// <param name="p_display">parent display</param>
        void SetDisplay(gfx3d_scg_display* const p_display);
        /// <summary>
        /// Returns the attached node
        /// </summary>
        /// <returns>transform</returns>
        gfx3d_scg_node* GetTransform(void);
        /// <summary>
        /// Return the parent display for this behaviour
        /// </summary>
        /// <returns>display</returns>
        gfx3d_scg_display* GetDisplay(void) const;
        /// <summary>
        /// Returns the total languages in translation table
        /// </summary>
        /// <returns>returns the index of the selected lanuage</returns>
        std::uint32_t GetNumberOfLanguages() const;
        /// <summary>
        /// Returns the currently set language index (0 to GetNumberOfLanguages()-1)
        /// </summary>
        /// <returns>returns the index of the selected lanuage</returns>
        std::uint32_t GetCurrentLanguage() const;
        /// <summary>
        /// Sets the current lanugage by index
        /// </summary>
        /// <param name="p_lang">language index to be set as current</param>
        /// <returns>returns true if active lanuage is changed</returns>
        bool SetCurrentLanguage(const std::uint32_t p_lang)  const;
        /// <summary>
        /// Returns the currently set language name
        /// </summary>
        /// <returns>returns the name of active lanuage</returns>
        std::u16string GetCurrentLanguageName() const;
        /// <summary>
        /// Returns the all language names as a list
        /// </summary>
        /// <returns>returns the names of all lanuages in translation table</returns>
        std::vector<rc_wstring>* GetLanguagesList() const;
        /// <summary>
        /// Gets the Translated TextID/Key's Index. Useful to save the key
        /// when the translation to fetched frequently. This avoid the
        /// keyname based lookup delay.
        /// </summary>
        /// <param name="p_tid">translation ID or Key value string</param>
        /// <returns>returns the TextID Index</returns>
        std::uint32_t GetTranslationKeyIndex(const std::u16string& p_tid) const;
        /// <summary>
        /// Gets the translated string by its translation ID or Key index
        /// </summary>
        /// <param name="p_tid">translation ID or Key index</param>
        /// <returns>returns the srtring corresponding to requested key in currently selected language</returns>
        std::u16string GetTranslation(const std::uint32_t p_tid) const;
        /// <summary>
        /// Gets the translated string by its translation ID or Key index
        /// </summary>
        /// <param name="p_tid">translation ID or Key index</param>
        /// <param name="p_lang">language index</param>
        /// <returns>returns the srtring corresponding to requested key in requested language</returns>
        std::u16string GetTranslation(const std::uint32_t p_tid, const std::uint32_t p_lang) const;
        /// <summary>
        /// Gets the translated string by its translation ID or Key string
        /// </summary>
        /// <param name="p_tid">translation ID or Key value string</param>
        /// <returns>returns the srtring corresponding to requested key in currently selected language</returns>
        std::u16string GetTranslation(const std::u16string& p_tid) const;
        /// <summary>
        /// Gets the translated string by its translation ID or Key string
        /// </summary>
        /// <param name="p_tid">translation ID or Key value string</param>
        /// <param name="p_lang">language index</param>
        /// <returns>returns the srtring corresponding to requested key in requested language</returns>
        std::u16string GetTranslation(const std::u16string& p_tid, const std::uint32_t p_lang) const;
        /// <summary>
        /// Sets the skin by index
        /// Requested is accepted (returns true) when a valid skin id is requested
        /// 1. There is no ongoing transtion is in progress. i.e. GetSkinTransitionStage() returns 1.0f
        /// 2. If a transtion for a SkinX is in progress then only SetCurrentSkin(SkinX, true) is accepted to
        ///    cancell the transition and set SkinX as the current skin.
        /// </summary>
        /// <param name="p_skin">Skin id to be activated</param>
        /// <returns>true if skin id is valid & request is taken</returns>
        bool SetCurrentSkin(const std::int32_t p_skin, const bool p_skip_transition = false) const;
        /// <summary>
        /// Sets the skin by name
        /// Requested is accepted (returns true) when a valid skin id is requested
        /// 1. There is no ongoing transtion is in progress. i.e. GetSkinTransitionStage() returns 1.0f
        /// 2. If a transtion for a SkinX is in progress then only SetCurrentSkin(SkinX, true) is accepted to
        ///    cancell the transition and set SkinX as the current skin.
        /// </summary>
        /// <param name="p_skin">Name of the Skin to be activated</param>
        /// <param name="p_skip_transition">if true the transition is skipped and skin change happens immediate</param>
        /// <returns>true if skin id is valid & request is taken</returns>
        bool SetCurrentSkin(const std::string p_skin, const bool p_skip_transition = false) const;
        /// <summary>
        /// Returns the number of skins
        /// </summary>
        /// <returns>total nuber of skins available</returns>
        std::uint32_t GetNumberOfSkins() const;
        /// <summary>
        /// Get the currently active skin id
        /// </summary>
        /// <returns>current skin id</returns>
        std::int32_t GetCurrentSkin() const;
        /// <summary>
        /// Get the currently active skin name
        /// </summary>
        /// <returns>current skin name</returns>
        std::string GetCurrentSkinName() const;
        /// <summary>
        /// Get a list of available skins names
        /// </summary>
        /// <returns>list of skin names</returns>
        std::vector<rc_string>* GetSkinsList() const;
        /// <summary>
        /// Return the skin id corresponding to passed skin name
        /// </summary>
        /// <param name="p_name">Name of the skin</param>
        /// <returns>the skin id</returns>
        std::int32_t GetSkinIndex(const std::string p_name) const;
        /// <summary>
        /// Return the skin name corresponding to passed skin id
        /// </summary>
        /// <param name="p_index">Id of the skin</param>
        /// <returns>the skin name</returns>
        std::string GetSkinName(const std::int32_t p_index) const;
        /// <summary>
        /// If  a skin transition is ongoing, this API can provide what the % of progress 
        /// on a scale  0.0 to 1.0
        /// 0.0 (in current skin) to 1.0 (reached destination skin)
        /// </summary>
        /// <returns>Return the % position of any ongoing skin transition</returns>
        float32_t GetSkinTransitionStage() const;
        /// <summary>
        /// Loads the passed image in to the passed texture 2D object.
        /// </summary>
        /// <param name="p_tex2d">A texture 2D object to which the image to be loaded</param>
        /// <param name="p_relpath">URI or Relative path to the asset file in the resources tar or filesystem</param>
        /// <param name="p_direct">If true tries to use direct texture extensions if available</param>
        /// <returns></returns>
        bool LoadTexture(gfx3dTexture2D* const p_tex2d, const std::string p_relpath, const bool p_direct = false) const;
        /// <summary>
        /// Loads the passed image in to the passed texture Cube object.
        /// </summary>
        /// <param name="p_tex2d">A texture 2D object to which the image to be loaded</param>
        /// <param name="p_relpath">URI or Relative path to the asset file in the resources tar or filesystem (currently only a ktx file with cumbemap data)</param>
        /// <param name="p_direct">If true tries to use direct texture extensions if available</param>
        /// <returns></returns>
        bool LoadTextureCube(gfx3dTexture2D* const p_tex2d, const std::string p_relpath, const bool p_direct = false) const;
        /// <summary>
        /// Schedules current framebuffer content grab to passed texture 2D object.
        /// The p_tex2d will be updated at the end of current render cycle
        /// Note : Immadiate use of the texture wont work. After calling ScheduleFrameGrab, only in
        /// the next script Update cycle the content will be available in p_tex2d
        /// </summary>
        /// <param name="p_tex2d">A texture 2D object to which the image to be loaded</param>
        /// <returns>true on success</returns>
        bool ScheduleFrameGrab(gfx3dTexture2D* const p_tex2d) const;
        /// <summary>
        /// Set the current resource load rule to be used while loading a scene
        /// <param name="p_lrule">Rule to be set</param>
        /// </summary>
        void SetResourceLoadRule(const MdlResourceLoadRule p_lrule);
        /// <summary>
        /// Gets the count of Morph targets (p_state_id ranges from 0 to count-1)
        /// </summary>
        /// <returns>Returns the count</returns>
        int32_t GetMorphStatesCount() const;
        /// <summary>
        /// Gets the ID of morph target with the given name
        /// </summary>
        /// <param name="p_state_name">name of the morph target</param>
        /// <returns>ID of the morph target </returns>
        int32_t GetMorphStateID(const rc_string p_state_name) const;
        /// <summary>
        /// Gets the name of morph target with a given ID
        /// </summary>
        /// <param name="p_state_id">ID of the morph target</param>
        /// <returns>name of the morph target</returns>
        rc_string GetMorphStateName(const int32_t p_state_id) const;
        /// <summary>
        /// Gets the weight of morph target with a given ID (valid range 0.0% to 100.0%)
        /// </summary>
        /// <returns>weight of the morph target</returns>
        float32_t GetMorphStateWeight(const int32_t p_state_id) const;
        /// <summary>
        /// Sets the weight of morph target of the given the ID (valid range 0.0% to 100.0%)
        /// </summary>
        /// <param name="p_state_id">Id of the morph target</param>
        /// <param name="p_weight">weight to be set for given morph target</param>
        /// <returns>true if weight is set else false</returns>
        bool SetMorphStateWeight(const int32_t p_state_id, const float32_t p_weight) const;
        /// <summary>
        /// Changes the sorting order of the node where this script is attached. Node with larger sort order renders last
        /// Valid range is 0-127 (applicable when gfx3d_scg_camera.GetSortType() is rc_rsortType.sortCustom)
        /// Negative value indicates the sorting is unset and rule is then to follow the parent node
        /// </summary>
        /// <param name="p_sorder">SortOrder</param>
        void SetSortOrder(const int8_t p_sorder);
        /// <summary>
        /// Returns the sorting order
        /// </summary>
        /// <returns>SortOrder</returns>
        int8_t GetSortOrder() const;
        /// <summary>
        /// Converts the p_arg value to string per the format string p_format and returns
        /// </summary>
        /// <typeparam name="T">Type of the argument (int32_t, float32_t etc)</typeparam>
        /// <param name="p_format">format string (e.g "%d"), refer snprintf</param>
        /// <param name="p_arg">value to be formatted</param>
        /// <returns>converted string</returns>
        template<typename T>
        inline rc_string RcStringFormat(const std::string& p_format, const T p_arg)
        {
            const rc_pfm_cfg_ibase& fl_cfg = gfx3d_scg_display::GetProjectConfig(display);
            const int32_t lc_max_length = static_cast<const int32_t>(fl_cfg.RcGetMaxStringLength());
            std::string fl_ret;
#if defined(RC_STD_GPP0X) && defined(__QNX660__)
            int32_t fl_size = snprintf(nullptr, static_cast <size_t>(0), p_format.c_str(), p_arg);
#else
            int32_t fl_size = std::snprintf(nullptr, static_cast <size_t>(0), p_format.c_str(), p_arg);
#endif
            if (fl_size > 0)
            {
                if (fl_size < lc_max_length)
                {
                    fl_size++; // for the null termination
                    std::unique_ptr<CHAR8[]> buf(new CHAR8[fl_size]);
#if defined(RC_STD_GPP0X) && defined(__QNX660__)
                    fl_size = snprintf(buf.get(), static_cast<size_t>(fl_size), p_format.c_str(), p_arg);
#else
                    fl_size = std::snprintf(buf.get(), static_cast<size_t>(fl_size), p_format.c_str(), p_arg);
#endif
                    if (fl_size > 0)
                    {
                        fl_ret = std::string(buf.get());
                    }
                }
                else
                {
                    RcDebugErrorLogId(rc_error_logId::elRcStrFormatMaxLenghtReached);
                    fl_size = 0;
                }
            }
            if (fl_size <= 0)
            {
                RcDebugErrorLogId(rc_error_logId::elRcStrFormatFailed);
                WLOG("rc_string_format (fmt:%s type:%s)\n", p_format.c_str(), typeid(T).name());
                fl_ret = std::to_string(p_arg);
            }
            return (fl_ret);
        }
        /// <summary>
        /// Converts the p_arg value to u16 string per the format string p_format and returns
        /// </summary>
        /// <typeparam name="T">Type of the argument (int32_t, float32_t etc)</typeparam>
        /// <param name="p_format">format string (e.g L"%d"), refer swprintf</param>
        /// <param name="p_arg">value to be formatted</param>
        /// <returns>converted wide string</returns>
        template<typename T>
        inline rc_wstring RcWStringFormat(const std::u16string& p_format, const T p_arg)
        {
            const std::string fl_format = U16StringtoString(p_format);
            const std::string fl_aret = RcStringFormat(fl_format, p_arg);
            return (StringtoU16String(fl_aret));
        }
    };
    /// this is for use by the RDF data
    typedef rdf_behaviour* (*rc_behaviour_getinst)(gfx3d_scg_display* const p_display);
    /// @}
}

#endif