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
//  Filename    : gfx3d_scg.h											
//  Description : GFX3D scene graph. A generic scenegraph definition to inherit
//  and create a more specific one. 
//  Its organizes as below
//  gfx3d_scg_display class
//         ---- scenes [collections gfx3d_scg_node class]
//                              ----- childs [collections gfx3d_scg_node class]
//                              ----- gfx3d_scg_mesh class
//											----- collection of primitives [gfx3d_scg_primitive class]
//											                                           ----- Material
//         ---- animation [gfx3d_scg_anim class]
//  display class is the starting point of a gltf scene graph. the whole scene is constructed a
//  child node tree as depicted above.
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gfx3d_scg.h													
/// \brief GFX3D scene graph. A generic scenegraph definition to inherit
/// and create a more specific one.

#ifndef gfx3d_scg_h
#define gfx3d_scg_h

/// \defgroup Engine Engine Classes
/// <summary>
/// Base classes of rendercore. Load project, scenes, control all the properties of objects
/// </summary>

/// \mainpage RenderCore API documentation
/// \section intro_sec Introduction
/// Rendercore is a 3D rendering engine developed to cater to UI requirements of DI software. 
/// Its developed in C++ (11) and provides a set of classes to allow the application engineer
/// to create a scene graph by instantiating. There is also possibility to inherit and enhance 
/// its capabilities. 
/// \section module_sec Base Classes
/// Key base class are listed below for easy access
/// <table>
///     <tr>
///         <th>Class</th>
///         <th>Header</th>
///         <th>Description</th>
///     </tr>
///     <tr>
///         <td>rendercore_engine::gfx3d_scg_project</td>
///         <td>gfx3d_scg_project.h</td>
///         <td>
///             This is a root of the scenegraph represeting a project. <br>
///             Project holds a list of Fonts (List<gfx3d_scg_font>) and Displays (List<gfx3d_scg_display>). <br>
///         </td>
///     </tr>
///     <tr>
///         <td>rendercore_engine::gfx3d_scg_display</td>
///         <td>gfx3d_scg_display.h</td>
///         <td>
///             Display holds a list of Scenes.<br>
///             A scene a hierarchical collection of nodes or a sub scene graph created with nodes linked in parent/child relationship<br>
///             A scene represents one layout such as fuel Economy scene or a Door Open Warning scene. <br>
///             Its therefore possible to load & unload the scenes at user control<br>
///             Its possible to activate & deactivate the scenes at user control<br>
///             A display also keeps track of other elements necessary for the scenes such as Textures, Material etc..<br>
///         </td>
///     </tr>
///     <tr>
///         <td>rendercore_engine::gfx3d_scg_node</td>
///         <td>gfx3d_scg_node.h</td>
///         <td>
///             Scenegraph base node that act as container and/or 3d geometry
///         </td>
///     </tr>
///     <tr>
///         <td>rendercore_engine::gfx3d_scg_3dtext_node</td>
///         <td>gfx3d_scg_3dtext_node.h</td>
///         <td>
///             Extends gfx3d_scg_node to implement a text or label functionality
///         </td>
///     </tr>
///     <tr>
///         <td>gfx3dTransform</td>
///         <td>gfx3dTransform.h</td>
///         <td>
///             Handles the transformations for all the scene graph nodes
///         </td>
///     </tr>
///     <tr>
///         <td>rendercore_engine::gfx3d_scg_anim</td>
///         <td>gfx3d_scg_anim.h</td>
///         <td>
///             Implements animation functionality. Has APIs to control animations
///         </td>
///     </tr>
///     <tr>
///         <td>rendercore_engine::gfx3d_scg_material</td>
///         <td>gfx3d_scg_material.h</td>
///         <td>
///             Implements material(opengl shader) to draw a 3d geometry. ProvidesAPI to update uniforms.
///         </td>
///     </tr>
///     <tr>
///         <td>gfx3dTexture2D</td>
///         <td>gfx3dTexture2D.h</td>
///         <td>
///             Allows creation of a texture object and assign it to a material at run time from a script.
///         </td>
///     </tr>
/// </table>
///

/// @bug when designing for rendercore in maya, photoshop or unity, choose names that follow C++ identifier naming conventions. e.g. donot use names that start with a number for example
/// @bug Currently full path of the node is not used and therefore its important to use unique names for elements (nodes, mterials, ..) for lookup by name to work properly. 
/// @bug Clipping is observed in rendered text with Freetype+Harfbuzz, mainly when point text is exported
/// @bug Fonts are not matched & missing characters in Monotype text rendering
#include "gfx3d_scg_types.h"
#include "rc_tar.h"
#include "rc_flag.h"
#include "rc_touch.h"
#include "rc_keys.h"
#include "rc_input.h"
#include "rc_render_states.h"
#include "rc_platform_common.h"
#include "workerthread.h"
#include "gfx3d_scg_glslshader.h"
#include "gfx3d_scg_gloabl_data.h"
#include "gfx3d_scg_project.h"
#include "logs/rc_debug_common.h"
#include "gfx3d_render_lists.h"
#include "rc_debug.h"
#include "gfx3d_scg_memory_monitor.h"
#include "gfx3d_scg_font.h"
#include "gfx3d_scg_anim_node.h"
#include "gfx3d_scg_anim.h"
#include "gfx3d_scg_view.h"
#include "rc_render_pass.h"
#include "gfx3d_scg_camera.h"
#include "gfx3d_scg_unity.h"
#include "gfx3d_scg_sampler.h"
#include "gfx3d_scg_accessor.h"
#include "gfx3d_scg_morph_target.h"
#include "gfx3d_scg_primitive.h"
#include "gfx3d_scg_buffer.h"
#include "gfx3d_scg_bufferview.h"
#include "gfx3d_scg_cmap_texture.h"
#include "gfx3d_scg_rtarget.h"
#include "gfx3d_scg_texture.h"
#include "gfx3d_scg_material.h"
#include "gfx3d_scg_material_group.h"
#include "gfx3d_scg_light.h"
#include "gfx3d_scg_skin.h"
#include "gfx3d_scg_guiskinning.h"
#include "gfx3d_scg_display.h"
#include "gfx3d_scg_node.h"
#include "gfx3d_scg_scene.h"
#include "rc_linebreak.h"
#include "gfx3d_scg_3dtext_node.h"
#include "gfx3d_scg_layout.h"
#include "gfx3d_scg_mesh.h"
#include "gfx3d_behaviour.h"
#include "rc_fbo_target.h"
#include "rc_localization.h"

namespace rendercore_engine
{

}
#endif
