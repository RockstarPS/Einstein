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
//  Description : classes to describe the graphics project.
//  Created on  : 02-Jan-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef rdf_display_type_h
#define rdf_display_type_h


//Macro Definitions ...

namespace rendercore_engine
{

//Class Definitions ...
class rdf_display
{
public:
  float32_t x;
  float32_t y;
  float32_t w;
  float32_t h;
  uint32_t render_target;
  uint32_t num_rtargets;
  rdf_rtarget const * rtargets;
  uint32_t num_accessors;
  rdf_accessor const * accessors;
  uint32_t num_animations;
  rdf_animation const * animations;
  uint32_t num_buffers;
  rdf_buffer const * buffers;
  uint32_t num_bufferViews;
  rdf_bufferView const * bufferViews;
  uint32_t num_lights;
  rdf_light const * lights;
  uint32_t mat_vec_array_size;
  float32_t const * mat_vec_array;
  uint32_t num_materials;
  rdf_material const * materials;
  uint32_t num_meshes;
  rdf_mesh const * meshes;
  uint32_t num_textures;
  rdf_texture const * textures;
  uint32_t num_cmap_textures;
  rdf_cmap_texture const * cmap_textures;
  uint32_t num_images;
  rdf_image const * images;
  uint32_t num_samplers;
  rdf_sampler const * samplers;
  uint32_t num_cameras;
  rdf_camera const * cameras;
  uint32_t num_renderPasses;
  rdf_renderpass const * renderPasses;
  uint32_t num_skins;
  rdf_skin const * skins;
  uint32_t num_scenes;
  rdf_scene const * scenes;
  uint32_t num_nodes;
  rdf_node const * nodes;
  uint32_t node_vec_array_size;
  float32_t const * node_vec_array;
  CHAR8 const * guiskin_uri;
  uint32_t animation_opt_list_size;
  CHAR8 const * const * animation_opt_list;
};

}

#endif
