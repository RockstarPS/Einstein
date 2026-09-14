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
//  Filename    : rc_statemanager.h
//  Description : Statemanager implementation converted from Unity C# implementation
//                by Appanasundaram, Sankar Ganesh (S.) <asankar1@visteon.com>
//  Created on  : 31-Jul-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  rc_statemanager.h
/// \brief Implements a statemanager. Statemanager allows to create multiple states
///        and each state allowes to have a set of properties. Then definition of 
///        transitions from one state to another. When the user selects a state
///        properties are interpolated from current state to next state values.
#ifndef rc_statemanager_h
#define rc_statemanager_h

#include <map>
#include <cmath>

namespace rendercore_engine
{
    /// \ingroup Behaviour
    /// @{

    /// <summary>
    /// specifies whether to move immadiately to end value or interpolate and reach overtime
    /// </summary>
    enum class process_mode
    {
        interpolate,    ///< interpolate to target (optionally choose a easing curve with API SetTransitionType
        snap_to_end     ///< move immadiately to target
    };

    /// @}
    /// \ingroup Behaviour
    /// @{

    /// <summary>
    /// A statemanager that canbe used in scripts to create multiple states with defined properties
    /// and transition to state with an interpolating animation of property value
    /// </summary>
    /// \attention this implementation is preliminary and the APIs will change in future releases
    class RCState_Manager
    {
    private:
        gfx3d_scg_display* display = nullptr;
        MdlEasingCurve easingCurve = MdlEasingCurve::linear;
        std::map<int32_t, std::map<int32_t, float32_t>> transitions; ///< TODO internal
        float32_t default_transition_duration = 0.00001F;///< TODO internal
        int32_t current_state = 0;///< TODO internal
        int32_t next_state = 0;///< TODO internal
        float32_t elapsed_time = 0.0F;///< TODO internal
        float32_t duration = 0.00001F;///< TODO internal
        //std::string type
        std::map<std::string, std::string> current_Texture2D_properties_value;///< TODO internal
        std::map<std::string, gfx3dTexture2D*> Texture2D_list;///< TODO internal
        std::map<std::string, gfx3dTexture2D*> Texture2D_cache; //path to texture 2D map

        std::map<int32_t, std::map<std::string, std::string>> state_Texture2D_properties;///< TODO internal
        //Euler type
        std::map<std::string, glm::vec3> Euler_start_values;///< TODO internal
        std::map<std::string, glm::vec3> Euler_end_values;///< TODO internal
        std::map<std::string, glm::vec3> current_Euler_properties_value;///< TODO internal
        std::map<int32_t, std::map<std::string, glm::vec3>> state_Euler_properties;///< TODO internal
        //glm::vec3 type
        std::map<std::string, glm::vec3> Vector3_start_values;///< TODO internal
        std::map<std::string, glm::vec3> Vector3_end_values;///< TODO internal
        std::map<std::string, glm::vec3> current_Vector3_properties_value;///< TODO internal
        std::map<int32_t, std::map<std::string, glm::vec3>> state_Vector3_properties;///< TODO internal
        //glm::vec4 type
        std::map<std::string, glm::vec4> Vector4_start_values;///< TODO internal
        std::map<std::string, glm::vec4> Vector4_end_values;///< TODO internal
        std::map<std::string, glm::vec4> current_Vector4_properties_value;///< TODO internal
        std::map<int32_t, std::map<std::string, glm::vec4>> state_Vector4_properties;///< TODO internal
        //gfx3dColor32 type
        std::map<std::string, gfx3dColor32> Color32_start_values;///< TODO internal
        std::map<std::string, gfx3dColor32> Color32_end_values;///< TODO internal
        std::map<std::string, gfx3dColor32> current_Color32_properties_value;///< TODO internal
        std::map<int32_t, std::map<std::string, gfx3dColor32>> state_Color32_properties;///< TODO internal
        //bool type
        std::map<std::string, float32_t> bool_steps;///< TODO internal
        std::map<std::string, float32_t> current_bool_properties_value;///< TODO internal
        std::map<int32_t, std::map<std::string, float32_t>> state_bool_properties;///< TODO internal
        //std::string type
        std::map<rc_wstring, rc_wstring> current_string_properties_value;///< TODO internal
        std::map<int32_t, std::map<rc_wstring, rc_wstring>> state_string_properties;///< TODO internal
        //float32_t type
        std::map<std::string, float32_t> current_float_properties_value;///< TODO internal
        std::map<int32_t, std::map<std::string, float32_t>> state_float_properties;///< TODO internal
        std::map<std::string, float32_t> float_start_values;///< TODO internal
        std::map<std::string, float32_t> float_end_values;///< TODO internal
        //glm::vec2 type
        std::map<std::string, glm::vec2> Vector2_start_values;///< TODO internal
        std::map<std::string, glm::vec2> Vector2_end_values;///< TODO internal
        std::map<std::string, glm::vec2> current_Vector2_properties_value;///< TODO internal
        std::map<int32_t, std::map<std::string, glm::vec2>> state_Vector2_properties;///< TODO internal

        template <class T>
        /// <summary>
        /// Checks for a keys presence in a std::map and returns true if present
        /// </summary>
        bool ContainsKey(const T& p_map, const std::string p_key) const
        {
            const auto it = p_map.find(p_key);
            return (it != p_map.end());
        }
        template <class T>
        /// <summary>
        /// Checks for a keys presence in a std::map and returns true if present
        /// </summary>
        bool ContainsKey(const T& p_map, const rc_wstring p_key) const
        {
            const auto it = p_map.find(p_key);
            return (it != p_map.end());
        }
        template <class T>
        /// <summary>
        /// Checks for a keys presence in a std::map and returns true if present
        /// </summary>
        bool ContainsKey(const T& p_map, const int32_t p_key) const
        {
            const auto it = p_map.find(p_key);
            return (it != p_map.end());
        }
        /// <summary>
        /// Process the statemanager
        /// \attention this API is internally invoked
        /// </summary>
        void process();
        /// \attention this API is internally invoked
        float32_t get_transition_duration(const int32_t start_state, const int32_t end_state);
        /// \attention this API is internally invoked
        void set_default_Texture2D_properties(const int32_t state_id);
        /// \attention this API is internally invoked
        void process_Texture2D_properties(const process_mode mode);
        /// \attention this API is internally invoked
        void set_default_string_properties(const int32_t state_id);
        /// \attention this API is internally invoked
        void process_string_properties(const process_mode mode);
        /// \attention this API is internally invoked
        void set_default_bool_properties(const int32_t state_id);
        /// \attention this API is internally invoked
        void calculate_bool_property_steps();
        /// \attention this API is internally invoked
        void process_bool_properties(const process_mode mode);
        /// \attention this API is internally invoked
        void set_default_Color32_properties(const int32_t state_id);
        /// \attention this API is internally invoked
        void calculate_Color32_property_steps();
        /// \attention this API is internally invoked
        void process_Color32_properties(const process_mode mode);
        /// \attention this API is internally invoked
        void set_default_Vector4_properties(const int32_t state_id);
        /// \attention this API is internally invoked
        void calculate_Vector4_property_steps();
        /// \attention this API is internally invoked
        void process_Vector4_properties(const process_mode mode);
        /// \attention this API is internally invoked
        void set_default_Euler_properties(const int32_t state_id);
        /// \attention this API is internally invoked
        void calculate_Euler_property_steps();
        /// \attention this API is internally invoked
        void process_Euler_properties(const process_mode mode);
        /// \attention this API is internally invoked
        void set_default_float_properties(const int32_t state_id);
        /// \attention this API is internally invoked
        void calculate_float_property_steps();
        /// \attention this API is internally invoked
        void process_float_properties(const process_mode mode);
        /// \attention this API is internally invoked
        void set_default_Vector2_properties(const int32_t state_id);
        /// \attention this API is internally invoked
        void calculate_Vector2_property_steps();
        /// \attention this API is internally invoked
        void process_Vector2_properties(const process_mode mode);
        /// \attention this API is internally invoked
        void set_default_Vector3_properties(const int32_t state_id);
        /// \attention this API is internally invoked
        void calculate_Vector3_property_steps();
        /// \attention this API is internally invoked
        void process_Vector3_properties(const process_mode mode);
        
    public:
        RCState_Manager(gfx3d_scg_display* p_display);
        /// distructor
        ~RCState_Manager();
        /// <summary>
        /// Sets the easing curve to be used for the transitions (Default is Linear)
        /// </summary>
        /// <param name="p_easing"></param>
        void SetEasingCurve(const MdlEasingCurve p_easing);
        /// <summary>
        /// Get the easing curve for transitions
        /// </summary>
        /// <param name="p_easing"></param>
        MdlEasingCurve GetEasingCurve() const;
        /// <summary>
        /// Set a default transition duration for the statemanager
        /// </summary>
        void set_default_transition_duration(const float32_t dur_seconds);
        /// <summary>
        /// Add a transition from 'from_state_id' to 'to_state_id' and the duration of transition 'dur_seconds'
        /// bool state true = state 1, false = state 0
        /// </summary>
        void add_transition(const bool from_state_id, const bool to_state_id, const float32_t dur_seconds);
        /// <summary>
        /// Add a transition from 'from_state_id' to 'to_state_id' and the duration of transition 'dur_seconds'
        /// </summary>
        void add_transition(const int32_t from_state_id, const int32_t to_state_id, float32_t dur_seconds);
        /// <summary>
        /// Add a property to state and returns its handle
        /// </summary>
        int32_t add_state_float_property(const int32_t state_id, const std::string name, const float32_t value);
        /// <summary>
        /// Add a property to state and returns its handle
        /// </summary>
        int32_t add_state_Vector2_property(const int32_t state_id, const std::string name, const glm::vec2 value);
        /// <summary>
        /// Add a property to state and returns its handle
        /// </summary>
        int32_t add_state_Vector3_property(const bool state_id, const std::string name, const glm::vec3 value);
        /// <summary>
        /// Add a property to state and returns its handle
        /// </summary>
        int32_t add_state_Vector3_property(const int32_t state_id, const std::string name, const glm::vec3 value);
        /// <summary>
        /// Add a property to state and returns its handle
        /// </summary>
        int32_t add_state_Euler_property(const bool state_id, const std::string name, const glm::vec3 value);
        /// <summary>
        /// Add a property to state and returns its handle
        /// </summary>
        int32_t add_state_Euler_property(const int32_t state_id, const std::string name, const glm::vec3 value);
        /// <summary>
        /// Add a property to state and returns its handle
        /// </summary>
        int32_t add_state_Vector4_property(const int32_t state_id, const std::string name, const glm::vec4 value);
        /// <summary>
        /// Add a property to state and returns its handle
        /// </summary>
        int32_t add_state_Color32_property(const int32_t state_id, const std::string name, const gfx3dColor32 value);
        /// <summary>
        /// Add a property to state and returns its handle
        /// </summary>
        int32_t add_state_bool_property(const int32_t state_id, const std::string name, const bool value);
        /// <summary>
        /// Add a property to state and returns its handle
        /// </summary>
        int32_t add_state_string_property(const int32_t state_id, const rc_wstring name, const rc_wstring value);
        /// <summary>
        /// Add a property to state and returns its handle
        /// </summary>
        int32_t add_state_Texture2D_property(const int32_t state_id, const std::string name, const std::string value);
        /// <summary>
        /// check if a property value is changed
        /// </summary>
        bool is_float_property_updated(const std::string name);
        /// <summary>
        /// check if a property value is changed
        /// </summary>
        bool is_Vector2_property_updated(const std::string property);
        /// <summary>
        /// check if a property value is changed
        /// </summary>
        bool is_Vector3_property_updated(const std::string property);
        /// <summary>
        /// check if a property value is changed
        /// </summary>
        bool is_Euler_property_updated(const std::string property);
        /// <summary>
        /// check if a property value is changed
        /// </summary>
        bool is_Vector4_property_updated(const std::string property);
        /// <summary>
        /// check if a property value is changed
        /// </summary>
        bool is_Color32_property_updated(const std::string property);
        /// <summary>
        /// check if a property value is changed
        /// </summary>
        bool is_bool_property_updated(const std::string name);
        /// <summary>
        /// check if a property value is changed
        /// </summary>
        bool is_string_property_updated(const std::string name);
        /// <summary>
        /// check if a property value is changed
        /// </summary>
        bool is_Texture2D_property_updated(const std::string name);
        /// <summary>
        /// Lookup a property by its name and gets its value
        /// </summary>
        float32_t get_current_float_property(const std::string property_name);
        /// <summary>
        /// Lookup a property by its name and gets its value
        /// </summary>
        glm::vec2 get_current_Vector2_property(const std::string property_name);
        /// <summary>
        /// Lookup a property by its name and gets its value
        /// </summary>
        glm::vec3 get_current_Vector3_property(const std::string property_name);
        /// <summary>
        /// Lookup a property by its name and gets its value
        /// </summary>
        glm::vec3 get_current_Euler_property(const std::string property_name);
        /// <summary>
        /// Lookup a property by its name and gets its value
        /// </summary>
        glm::vec4 get_current_Vector4_property(const std::string property_name);
        /// <summary>
        /// Lookup a property by its name and gets its value
        /// </summary>
        gfx3dColor32 get_current_Color32_property(const std::string property_name);
        /// <summary>
        /// Lookup a property by its name and gets its value
        /// </summary>
        bool get_current_bool_property(const std::string property_name);
        /// <summary>
        /// Lookup a property by its name and gets its value
        /// </summary>
        rc_wstring get_current_string_property(const rc_wstring property_name);
        /// <summary>
        /// Lookup a property by its name and gets its value
        /// </summary>
        gfx3dTexture2D* get_current_Texture2D_property(const std::string property_name);
        /// <summary>
        /// Go to specified state id. This triggers a state transition
        /// bool state true = state 1, false = state 0
        /// </summary>
        void goto_state(const bool state_id);
        /// <summary>
        /// Go to specified state id. This triggers a state transition
        /// </summary>
        void goto_state(const int32_t state_id);
        /// <summary>
        /// Set passed state id as the default state
        /// </summary>
        void set_default_state(const int32_t state_id);
        /// <summary>
        /// Get the current state
        /// </summary>
        int32_t get_current_state() const;
        /// <summary>
        /// Get the next state
        /// </summary>
        int32_t get_next_state() const;
    };
    /// @}
}
#endif