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
//  Filename    : gfx3d_scg_sampler.h
//  Description : GFX3D scene graph font object
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gfx3d_scg_sampler.h
/// \brief GFX3D scene graph font object
#ifndef gfx3d_scg_sampler_h
#define gfx3d_scg_sampler_h

namespace rendercore_engine
{
    /// \ingroup Engine
    /// @{
    /// <summary>
    /// used to store the sampler data fetched from the gltf model
    /// https://github.com/KhronosGroup/glTF/tree/master/specification/2.0#samplers
	/// </summary>
	class gfx3d_scg_sampler
	{
	private:
        std::string name;			///< name of the sampler 
        MdlTextFilter_E minFilter = MdlTextFilter_E::tfNearest;	///< min filtering to be used to create texture 
        MdlTextFilter_E magFilter = MdlTextFilter_E::tfNearest;	///< mag filtering to be used to create texture
        MdlTextWrap_E wrapS = MdlTextWrap_E::twRepeat;			///< wrap-S decides how the texture will be wrapped around object 
        MdlTextWrap_E wrapT = MdlTextWrap_E::twRepeat;			///< wrap-T decides how the texture will be wrapped around object
    public:
		/// constructor
        gfx3d_scg_sampler();
		/// <summary>
		/// constructor
		/// </summary>
        gfx3d_scg_sampler(const MdlTextFilter_E p_minFilter, const MdlTextFilter_E p_magFilter, const MdlTextWrap_E p_wrapS, const MdlTextWrap_E p_wrapT);
		virtual ~gfx3d_scg_sampler();
        /// <summary>
        /// function to get Minification Filter
        /// </summary>
        /// <returns>returns Minification Filter </returns>
        MdlTextFilter_E GetMinFilter() const;
		/// <summary>
        /// function to get Magnification Filter
        /// </summary>
        /// <returns>returns Magnification Filter </returns>
        MdlTextFilter_E GetMagFilter() const;
		//Get Minifiaction and Magnification Filter
        /// <summary>
        /// function to get Minifiaction and Magnification Filter
        /// </summary>
        /// <returns>returns Minifiaction and Magnification Filter </returns>
        void GetFilter(MdlTextFilter_E& p_minFilter, MdlTextFilter_E& p_magFilter) const;
        /// <summary>
        /// Set Minifiaction Filter
        /// </summary>
        /// <param name="p_minFilter"> Minifiaction Filter </param>
        void SetMinFilter(const MdlTextFilter_E p_minFilter);
        /// <summary>
        /// Set Magnification Filter
        /// </summary>
        /// <param name="p_magFilter"> Magnification Filter </param>
        void SetMagFilter(const MdlTextFilter_E p_magFilter);
        /// <summary>
        /// Set Minifiaction and Magnification Filter
        /// </summary>
        /// <param name="p_minFilter"> Minifiaction Filter </param>
        /// <param name="p_magFilter"> Magnification Filter </param>
        void SetFilter(const MdlTextFilter_E p_minFilter, const MdlTextFilter_E p_magFilter);
        /// <summary>
        /// Get Wraping function for texture coordinate S
        /// </summary>
        /// <returns>returns Wraping function for texture coordinate S</returns>
        MdlTextWrap_E GetWrapS() const;
        /// <summary>
        /// Get Wrap function for texture coordinate T
        /// </summary>
        /// <returns>returns Wrap function for texture coordinate T</returns>
        MdlTextWrap_E GetWrapT() const;
		//Get Wrap function for texture coordinate S and T
        /// <summary>
        /// Get Wrap function for texture coordinate S and T
        /// </summary>
        /// <returns>returns Get Wrap function for texture coordinate S and T</returns>
        void GetWrap(MdlTextWrap_E& p_wrapS, MdlTextWrap_E& p_wrapT) const;
		// <summary>
        /// Set Wraping function for texture coordinate S
        /// </summary>
        /// <param name="p_wrapS"> Wraping function for texture coordinate S </param>
        void SetWrapS(const MdlTextWrap_E p_wrapS);
        // <summary>
        /// Set Wraping function for texture coordinate T
        /// </summary>
        /// <param name="p_wrapT"> Wraping function for texture coordinate T </param>
        void SetWrapT(const MdlTextWrap_E p_wrapT);
        // <summary>
        /// Set Wrap function for texture coordinate S and T
        /// </summary>
        /// <param name="p_wrapS"> Wraping function for texture coordinate S </param>
        /// <param name="p_wrapT"> Wraping function for texture coordinate T </param>
        void SetWrap(const MdlTextWrap_E p_wrapS, const MdlTextWrap_E p_wrapT);
        /// <summary>
        /// Set accessor's name
        /// </summary>
        /// <param name="p_name"> name of accessor of type string </param>
        void SetName(const std::string p_name);
        /// <summary>
        /// function to get name of accessor
        /// </summary>
        /// <returns>returns name of accessor object </returns>
        std::string GetName() const;
    };
    /// @}
}


#endif