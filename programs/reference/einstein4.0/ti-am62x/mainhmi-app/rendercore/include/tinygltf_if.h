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
//  Filename    : tinygltf_if.cpp
//  Description : Wrapper Class for the tinygltf 
//  Created on  : 10-Aug-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file tinygltf_if.h
///		  Wrapper Class for the tinygltf 
#pragma once
//#define TINYGLTF_NO_STB_IMAGE
//#define TINYGLTF_NO_STB_IMAGE_WRITE
#define TINYGLTF_NO_EXTERNAL_IMAGE
#include "tiny_gltf.h"

namespace rendercore_engine
{
	class rc_player_config
	{
	public:
		std::vector<std::pair<uint32_t, uint32_t>> displaySize;
		bool overrideAspect;

	};
	/// \ingroup Loader
	/// @{

	/// Used internally by the gltf loader class
	extern tinygltf::Model* ParseGLTF(std::string filename, std::string& err);
	extern std::string tinygltf_if_base64_decode(std::string const& encoded_string);
	extern std::string tinygltf_if_base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len);
	extern std::string tinygltf_if_JoinPath(const std::string& path0, const std::string& path1);
	extern std::string tinygltf_if_GetFilePathExtension(const std::string& FileName);
	extern std::string tinygltf_if_GetBaseDir(const std::string& filepath);
	extern bool tinygltf_if_LoadImageData(tinygltf::Image* Image, const int image_idx, std::string* err,
		std::string* warn, int width, int height,
		const unsigned char* bytes, int size, void* userdata);
	/// @}
	extern rc_player_config tinygltf_if_load_player_config(const std::string& p_path);
}


