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
//  Filename    : gltfplus_scg_camera.h
//  Description : mesh adaptation for tiny gltf. 
//  Created on  : 10-Aug-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gltfplus_scg_camera.h
///	\brief 	   camera adaptation for tiny gltf. 
#ifndef gltfplus_scg_camera_h
#define gltfplus_scg_camera_h

#include "tinygltf_if.h"
#include "gfx3d_scg.h"

namespace rendercore_engine
{
    /// \ingroup Loader
    /// @{
    
    /// rdf scg mesh class, extending gfx3d scg mesh class 
	class gltfplus_scg_camera : public gfx3d_scg_camera
	{
    private:
        bool drawEnvironment = false;
        float32_t environmentRot = 0.0F;
    protected:
        /// perform a custom clear action. return true to indicate action done, false action not performed
        GLbitfield perform_clear(const GLbitfield p_clearFlag) const override;
	public:
		///constructor
        gltfplus_scg_camera(tinygltf::Camera* p_cam, gfx3d_scg_display * p_dsp);
        void SetDrawEnvironment(const bool p_drawEnvironment);
        bool GetDrawEnvironment() const;
        float32_t GetEnvironmentRotation() const;
        void SetEnvironmentRotation(const float32_t p_environmentRot);
    };
    /// @}
}

#endif