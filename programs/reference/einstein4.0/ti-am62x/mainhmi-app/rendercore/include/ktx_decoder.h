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
//  Filename    : ktx_decoder.h
//  Description : KTX texture file decoding APIs..
//  Created on  : 11-Sep-2018 by Nataraj, Murugappan (M.) <mnatara5@visteon.com>
///////////////////////////////////////////////////////////////////////////////
#ifndef ktx_decoder_h
#define ktx_decoder_h

#include <cstdint>

namespace rendercore_engine
{
    /// <summary>
    /// Flags to control decoding of a KTX file
    /// </summary>
    enum class KTXLoadFlagBit
    {
        klfFaces,   ///< Bit set Loads all faces, clear loads the first face only
        klfArrays,  ///< Bit set Loads all arrays, clear loads the first array element only
        klfMips,    ///< Bit set Loads all mipmap levels, clear loads the first level only
        KlfMaxFlag  ///< Total number of flags available
    };
    using KTXLoadFlags = std::bitset<static_cast<size_t>(KTXLoadFlagBit::KlfMaxFlag)>;
    /// \ingroup Utlities
    /// @{
    class KTXFileInfo
    {
    private:
        uint32_t numberOfMipmapLevels;      ///<Number of mipmap levels available
        uint32_t numberOfArrayElements;     ///<Number of array elements available
        uint32_t numberOfFaces;             ///<Number of faces available
        std::vector<rcTextureInfo> texInfo; ///<Texture array ordered as multidimentional array texInfo[numberOfMipmapLevels][numberOfArrayElements][numberOfFaces]
    public:
        /// <summary>
        /// Constructor
        /// </summary>
        KTXFileInfo();
        /// <summary>
        /// Clears all texture data it holds
        /// </summary>
        void Clear();
        /// <summary>
        /// Set the texture proprties
        /// </summary>
        /// <param name="p_numberOfMipmapLevels">Number of mipmap levels available</param>
        /// <param name="p_numberOfArrayElements">Number of arraylevels available</param>
        /// <param name="p_numberOfFaces">Number of faces available</param>
        void SetProprties(const uint32_t p_numberOfMipmapLevels, const uint32_t p_numberOfArrayElements, const uint32_t p_numberOfFaces);
        /// <summary>
        /// Adds a decoded texture to the list
        /// </summary>
        /// <param name="p_tex"></param>
        void AddTexture(const rcTextureInfo& p_tex);
        /// <summary>
        /// Get the Number of Mipmap Levels available
        /// </summary>
        /// <returns>Number of Mipmap Levels</returns>
        uint32_t GetNumberOfMipmapLevels() const;
        /// <summary>
        /// Get the Number of aray elements available
        /// </summary>
        /// <returns>Number of aray elements</returns>
        uint32_t GetNumberOfArrayElements() const;
        /// <summary>
        /// Get the number of faces available
        /// </summary>
        /// <returns>number of faces</returns>
        uint32_t GetNumberOfFaces() const;
        /// <summary>
        /// Total number of textures required = GetNumberOfMipmapLevels() * GetNumberOfArrayElements() * GetNumberOfFaces()
        /// </summary>
        /// <returns>number of textures required</returns>
        size_t GetNumRequiredTexture() const;
        /// <summary>
        /// Total textures added to the list
        /// </summary>
        /// <returns>available textures in list</returns>
        size_t GetNumAvailableTexture() const;
        /// <summary>
        /// Get the texture from the list.
        /// list is a multidimentional array organized as below. 
        /// texturelist[GetNumberOfMipmapLevels()][GetNumberOfArrayElements()][GetNumberOfFaces()]
        /// </summary>
        /// <param name="p_index">index of texture to be retrived</param>
        /// <param name="p_tex">output locatio where the texture data is copied</param>
        /// <returns>true if success</returns>
        bool GetTexture(const size_t p_index, rcTextureInfo& p_tex) const;
    };
    /// <summary>
    /// decodes a KTX1 (https://www.khronos.org/registry/KTX/specs/1.0/ktxspec_v1.html) file loaded in memory
    /// </summary>
    /// <param name="p_inKtx_data">pointer to ktx file data in memory</param>
    /// <param name="p_inSize">size in bytes for the ktx file data</param>
    /// <param name="p_inldflags">load options</param>
    /// <returns>Returns the decode information and textures</returns>
    KTXFileInfo load_ktx_from_memory(const CHAR8* p_inKtx_data, const size_t p_inSize, const KTXLoadFlags p_inldflags);
    /// @}
}
#endif
