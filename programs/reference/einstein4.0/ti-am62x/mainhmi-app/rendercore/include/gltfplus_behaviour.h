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
//  Filename    : gltfplus_behaviour.h
//  Description : GFX3D behaviour object
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gltfplus_behaviour.h
///	\brief GFX3D behaviour object
#ifndef gltfplus_behaviour_h
#define gltfplus_behaviour_h

#include "gfx3d_behaviour.h"
#include "tinygltf_if.h"
#include "gltfplus_script_engine.h"

namespace rendercore_engine
{
    /// \ingroup Loader
    /// @{

    /// <summary>
    /// defines a set of general behaviours defined by the gltf model
    /// </summary>
    class gltfplus_behaviour : public rdf_behaviour
    {
    private:
        std::string name;															///< name of behavior
        std::string type;															///< type of the behavior
        gltfplusMelScriptEngine* melScriptEngine = nullptr;						///< gltfplusmel script engine
        tinygltf::Model* model = nullptr;											///< tinygltf model
    public:
        /// uri object																				
        std::string uri;															        ///loads a behavior
        virtual void Load(void) override;													///starts a behavior
        virtual void Start(void) override;													///updated a behavior
        virtual void Update(void) override;													///called when disabled
        virtual void OnDisable(void) override;												/// called when enabled
        virtual void OnEnable(void) override;												///get int32_t
        virtual bool GetInt(const rc_string p_name, int32_t* const p_out) const override;							///get uint
        virtual bool GetUInt(const rc_string p_name, uint32_t* const p_out) const override;				///get float32_t
        virtual bool GetFloat(const rc_string p_name, float32_t* const p_out) const override;						///get vector2
        virtual bool GetVector(const rc_string p_name, glm::vec2* const p_out) const override;				///get vector3
        virtual bool GetVector(const rc_string p_name, glm::vec3* const p_out) const override;				///get vector4
        virtual bool GetVector(const rc_string p_name, glm::vec4* const p_out) const override;				///get string
        virtual bool GetString(const rc_string p_name, rc_string* const p_out) const override;				///get string
        virtual bool GetWString(const rc_string p_name, rc_wstring* const p_out) const override;				///get mesh renderer
        virtual bool GetMeshRenderer(const rc_string p_name, gfx3d_scg_mesh** const p_out) const override;	/// get material
        virtual bool GetMaterial(const rc_string p_name, gfx3dMaterial** const p_out) const override;			///get game objects
        virtual bool GetGameObject(const rc_string p_name, gfx3d_scg_node** const p_out) const override;		///get camera
        virtual bool GetCamera(const rc_string p_name, gfx3dCamera** const p_out) const override;				///get text mesh 
        virtual bool GetTextMeshPro(const rc_string p_name, gfx3dTextMeshPro** const p_out) const override;	///set int32_t 
        virtual bool SetInt(const rc_string p_name, const int32_t p_in) override;							///set uint
        virtual bool SetUInt(const rc_string p_name, const uint32_t p_in) override;					///set float32_t
        virtual bool SetFloat(const rc_string p_name, const float32_t p_in) override;						///set vec2
        virtual bool SetVector(const rc_string p_name, const glm::vec2 p_in) override;					///set vec3
        virtual bool SetVector(const rc_string p_name, const glm::vec3 p_in) override;					/// set vec4
        virtual bool SetVector(const rc_string p_name, const glm::vec4 p_in) override;					/// string
        virtual bool SetString(const rc_string p_name, const rc_string p_in) override;					/// string
        virtual bool SetMeshRenderer(const rc_string p_name, gfx3d_scg_mesh* const p_in) override;	///set materiial
        virtual bool SetMaterial(const rc_string p_name, gfx3dMaterial* const p_in) override;			///set game object
        virtual bool SetGameObject(const rc_string p_name, gfx3d_scg_node* const p_in) override;		///set camera
        virtual bool SetCamera(const rc_string p_name, gfx3dCamera* const p_in) override;				///set transform
        virtual bool SetTransform(const rc_string p_name, gfx3dTransform* const p_in) override;			///set text mesh
        virtual bool SetRCText(const rc_string p_name, gfx3dTextMeshPro* const p_in) override;		/// check if valid
        virtual bool isValid(void) override;
        /// constructor
        gltfplus_behaviour(tinygltf::Model* p_model, gfx3d_scg_display* p_disp, tinygltf::Value p_script);
        ~gltfplus_behaviour();
        /// generate custom property
        void generate_customProp(tinygltf::Value* p_extras);
    };
    /// @}
}
#endif