// ***********************************************************************
// Assembly         : 
// Author           : emanoj1
// Created          : 03-15-2019
//
// Last Modified By : emanoj1
// Last Modified On : 03-15-2019
// ***********************************************************************
// <copyright file="gltfplus_script_engine.cpp" company="Visteon Corporation">
//     This is an unpublished work of authorship, which contains trade secrets, 
//     created in 2018. Visteon Corporation owns all rights to this work and 
//     intends to maintain it in confidence to preserve its trade secret status. 
//     Visteon Corporation reserves the right, under the copyright laws of the 
//     United States or those of any other country that may have jurisdiction, 
//     to protect this work as an unpublished work, in the event of an inadvertent
//     or deliberate unauthorized publication. Visteon Corporation also reserves 
//     its rights under all copyright laws to protect this work as a published work, 
//     when appropriate. Those having access to this work may not copy it, use it, 
//     modify it or disclose the information contained in it without the written 
//     authorization of Visteon Corporation. 
//     Copyright (c) Visteon Corporation. All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
/// @file gltfplus_script_engine.h
///	\brief contains the script engine
#ifndef gltfplus_script_engine_h
#define gltfplus_script_engine_h

#if !defined(RC_V8_JS_ENGINE)
#define RC_V8_JS_ENGINE (0)		///< Define V8 JS engine
#endif

namespace rendercore_engine
{
    class gltfplusScript;
    class gltfplus_behaviour;
    class gfx3d_scg_project;
    /// \ingroup Internal
    /// @{
    /// used to load scripts from the model
    class gltfplusMelScriptEngine
    {
    private:
        gltfplusScript* script;			///< script object
        gltfplus_behaviour* behaviour;	///< behaviour
        tinygltf::Model* model;			///< tiny gltf model
    public:
        /// constructor
        gltfplusMelScriptEngine(tinygltf::Model* p_model, gltfplus_behaviour* p_behaviour);
        ~gltfplusMelScriptEngine();
        /// runs the mel scripts for models
        bool RunScript(void);
        static void Reset(gfx3d_scg_project* const p_prj);
    };
    /// @}
}
#endif