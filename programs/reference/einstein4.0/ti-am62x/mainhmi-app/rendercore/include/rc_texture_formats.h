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
//  Filename    : rc_texture_formats.h
//  Description : Texture2D object
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file	rc_texture_formats.h
///	\brief 		Texture2D object
#ifndef rc_texture_formats_h
#define rc_texture_formats_h

namespace rendercore_engine
{
    /// \ingroup Engine
    /// @{
    /// returns the GL image format configuration for passed RC type
    extern const RCglImgFormatMap* GetGLImageFormatMap(const MdlImgFormat_E p_rcFormat);
    /// returns the GL image format configuration for passed Open GL type and format
    extern const RCglImgFormatMap* GetGLImageFormatMap(const GLenum p_type, const GLenum p_format, const GLint p_internalformat);
    /// @}
}
#endif