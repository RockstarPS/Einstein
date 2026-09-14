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
//  Filename    : rc_gles_vivextns.h
//  Description : GLES Wrapper Implemenattions for vivante extensions
//  Created on  : 11-MAR-2021 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef rc_gles_vivextns_h
#define rc_gles_vivextns_h

namespace rendercore_engine
{
    /// <summary>
    /// Setup the vivante direct texture API if not done already and get the status of its availability
    /// </summary>
    /// <returns>true if API available</returns>
    bool rcSetupglTexDirectVIV();
    /// <summary>
    /// Clear the rcSetupglTexDirectVIV().
    /// Curretly exists for UT coverage
    /// </summary>
    void rcClearglTexDirectVIV();
    /// <summary>
    /// Vivante Direct texture glTexDirectVIV API wrapper
    /// </summary>
    /// <param name="p_target">refer vivante doc</param>
    /// <param name="p_width">refer vivante doc</param>
    /// <param name="p_height">refer vivante doc</param>
    /// <param name="p_format">refer vivante doc</param>
    /// <param name="p_pixels">refer vivante doc</param>
    /// <returns>true if the API exists and command issued</returns>
    bool rcglTexDirectVIV(const GLenum p_target, const GLsizei p_width, const GLsizei p_height, const GLenum p_format, GLvoid** const p_pixels);
    /// <summary>
    /// Vivante Direct texture glTexDirectVIVMap API wrapper
    /// </summary>
    /// <param name="p_target">refer vivante doc</param>
    /// <param name="p_width">refer vivante doc</param>
    /// <param name="p_height">refer vivante doc</param>
    /// <param name="p_format">refer vivante doc</param>
    /// <param name="p_logical">refer vivante doc</param>
    /// <param name="p_physical">refer vivante doc</param>
    /// <returns>true if the API exists and command issued</returns>
    bool rcglTexDirectVIVMap(const GLenum p_target, const GLsizei p_width, const GLsizei p_height, const GLenum p_format, GLvoid** const p_logical, const GLuint* const p_physical);
    /// <summary>
    /// Vivante Direct texture glTexDirectInvalidateVIV API wrapper
    /// </summary>
    /// <param name="p_target">refer vivante doc</param>
    /// <returns>true if the API exists and command issued</returns>
    bool rcglTexDirectInvalidateVIV(const GLenum p_target);
}
#endif
