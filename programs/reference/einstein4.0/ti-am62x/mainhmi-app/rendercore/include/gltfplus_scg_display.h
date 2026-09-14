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
//  Created on  : 25-Jan-2018 by mpandey@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gltfplus_scg_display.h
///	\brief it is a display class and contains graphics data for display
#ifndef gltfplus_scg_display_h
#define gltfplus_scg_display_h

#include "gfx3d_scg.h"
#include "gltfplus_scg_project.h"
#include "tinygltf_if.h"

namespace rendercore_engine
{
    /// \ingroup Loader
    /// @{
    
    /// gltfplus_scg_display loads scenegraph.
	class gltfplus_scg_display : public gfx3d_scg_display
	{
    private:
		//rdf_display const * config;
		tinygltf::Model * m_model;
        void glesGenerateBuffers(CHAR8 const * const p_resource_path);
		bool process_KHR_lights_punctual(tinygltf::Model* p_model);
	public:
		/// constructor
		gltfplus_scg_display(gltfplus_scg_project *, tinygltf::Model * model);
		/// <summary>
		/// returns the node type 
		/// </summary>
        static mdl_nodeType_E GetNodeType(tinygltf::Node * p_node);
		/// <summary>
		/// get the tinygltf model object
		/// </summary>
		tinygltf::Model * GetModel(void);
		/// <summary>
		/// This function goes throught all the nodes present in the scene, based on type of node loads either text of normal node.4
		/// For now only these two type of nodes supported.
		/// </summary>
		void CreateScene(const size_t idx) override;
		/// <summary>
		/// Creates the animation nodes for the all anims.
		/// </summary>
		void CreateAnim() override;
		/// <summary>
		/// Creates the animation nodes for the requested id/index.
		/// </summary>
		/// <param name="p_index">index of animation to load</param>
		void CreateAnim(const size_t p_index) override;
	};
    /// @}
	/// \ingroup Loader
	/// @{
	/// get the current state of pipeline, cull mode
	extern mdl_cullMode get_pipelineStageCullMode(tinygltf::Value* p_extras);
	/// get the current state of pipeline, depth function
	extern mdl_depthTest get_pipelineStageDepthFunc(tinygltf::Value* p_extras);
	/// get the current state of pipeline, depth write
	extern mdl_depthWrite get_pipelineDepthWrite(tinygltf::Value* p_extras);
	/// get the current state of pipeline, blend mode
	extern MdlBlendMode get_pipelineAlphaBlendMode(tinygltf::Value* p_extras);
	/// <summary>
	///  Returns an int value from tinygltf::Value
	/// </summary>
	/// <param name="p_value">tinygltf::Value</param>
	/// <param name="p_arrayIndex">array index to fetch value from</param>
	/// <returns>integer value</returns>
	extern int32_t tgltfGetInt(tinygltf::Value& p_value, int32_t p_arrayIndex);
	/// <summary>
	///  Returns a float value from tinygltf::Value
	/// </summary>
	/// <param name="p_value">tinygltf::Value</param>
	/// <param name="p_arrayIndex">array index to fetch value from</param>
	/// <returns>float value</returns>
	extern float32_t tgltfGetFloat(tinygltf::Value& p_value, int32_t p_arrayIndex);
	/// @}
}
#endif