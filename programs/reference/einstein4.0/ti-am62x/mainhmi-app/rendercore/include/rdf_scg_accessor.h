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
//  Filename    : gfx3d_scg_accessor.h
//  Description : GFX3D scene graph accessor object
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file rdf_scg_accessor.h
/// \brief		  GFX3D scene graph accessor object
#ifndef rdf_scg_accessor_h
#define rdf_scg_accessor_h

namespace rendercore_engine
{
    /// \ingroup Loader
    /// @{

    /// <summary>
	/// Starting point or display of the scene graph
	/// </summary>
	class rdf_scg_accessor : public gfx3d_scg_accessor
	{
	protected:
    public:
		///  
		///constructor
		///
		///\param p_disp  rdf scg display
		///\param p_item to be loaded from gltf
		///
		rdf_scg_accessor(rdf_scg_display * const p_disp, rdf_accessor const * const p_item);
		/// destructor
		virtual ~rdf_scg_accessor();
	};

    /// @}
    /// \ingroup Loader
    /// @{

	/// buffer view class for rdf project
	class rdf_scg_bufferview : public gfx3d_scg_bufferview
    {
    protected:
    public:
		///  
		///constructor
		///
		///\param p_disp : rdf scg display
		///\param p_item to be loaded from gltf
		///
		rdf_scg_bufferview(rdf_scg_display * const p_disp, rdf_bufferView const * const p_item);
		/// destructor
		~rdf_scg_bufferview();
    };

    /// @}
    /// \ingroup Loader
    /// @{
    
    /// buffer class for rdf project
    class rdf_scg_buffer : public gfx3d_scg_buffer
    {
    protected:
    public:
		///  
		///constructor
		///
		///\param p_disp  rdf scg display
		///\param p_item to be loaded from gltf
		///
		rdf_scg_buffer(rdf_scg_display * const p_disp, rdf_buffer const * const p_item);
		/// destructor
		~rdf_scg_buffer();
    };
    /// @}
}

#endif