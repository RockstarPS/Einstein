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
//  Filename    : gfx3d_scg_buffer.h
//  Description : GFX3D scene graph buffer object
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gfx3d_scg_buffer.h
/// \brief GFX3D scene graph buffer object
#ifndef gfx3d_scg_buffer_h
#define gfx3d_scg_buffer_h

namespace rendercore_engine
{
    /// \ingroup Engine
    /// @{

    using rc_bufferUserId = std::uintptr_t;

    /// <summary>
	/// contains the buffer class which contains the vertices of the model
    /// https://github.com/KhronosGroup/glTF/tree/master/specification/2.0#buffers-and-buffer-views
	/// </summary>
	class gfx3d_scg_buffer
	{
	private:
		const CHAR8* barray = nullptr;			///< byte array to data held by this buffer
        gfx3d_scg_display* display;  			///< parent/owner display object
        size_t byteLength;						///< length in bytes
        std::string name;						///< name of the buffer
        std::string uri;						///< uri / filepath of the buffer
        std::vector<rc_bufferUserId> users;     ///< List of users of this buffer
        bool bLoaded = false;                   ///< if true indicates that the buffer is loaded
    public:
        /// <summary>
        /// Constructs a buffer object by uri
        /// </summary>
        /// <param name="p_parent"> parent display </param>
        /// <param name="p_uri"> buffer data file path uri </param>
        /// <param name="p_byteLength"> optional length of data available in file </param>
        gfx3d_scg_buffer(gfx3d_scg_display* const p_parent, const std::string p_uri, const size_t p_byteLength=0);
        /// <summary>
        /// Constructs a buffer object by a buffer data array & length
        /// </summary>
        /// <param name="p_parent"> parent display </param>
        /// <param name="p_buffer"> buffer data pointer </param>
        /// <param name="p_byteLength"> length of data available in p_buffer </param>
        gfx3d_scg_buffer(gfx3d_scg_display * const p_parent, const CHAR8* const p_buffer, const size_t p_byteLength);
        /// Distructor
        virtual ~gfx3d_scg_buffer();
        gfx3d_scg_buffer& operator= (const gfx3d_scg_buffer&) = delete;
        gfx3d_scg_buffer(const gfx3d_scg_buffer&) = delete;
        /// <summary>
        /// Loads this node by creating dynamic contents..
        /// </summary>
        /// <param name="p_uid">id of the caller who is requesting this unload</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        bool Load(const rc_bufferUserId p_uid);
        /// <summary>
        /// Unloads this node by deleting dynamic contents.. if none of the scene uses this node anymore
        /// </summary>
        /// <param name="p_uid">id of the caller who is requesting this unload</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        bool UnLoad(const rc_bufferUserId p_uid);
        /// <summary>
        /// function to get name of buffer
        /// </summary>
        /// <returns>returns name of buffer object </returns>
        std::string GetName() const;
        /// <summary>
        /// Set accessor's name
        /// </summary>
        /// <param name="p_name"> name of buffer of type string </param>
        void SetName(const std::string p_name);
        /// <summary>
        /// function to get pointer to parent display
        /// </summary>
        /// <returns>returns pointer to parent display </returns>
        gfx3d_scg_display * GetDisplay() const;
        /// <summary>
        /// Sets the parent display
        /// </summary>
        /// <param name="p_disp">parent display</param>
        void SetDisplay(gfx3d_scg_display* const p_disp);
        /// <summary>
        /// function to get buffer uri of type string
        /// </summary>
        /// <returns>returns buffer uri </returns>
        std::string GetURI() const;
        /// <summary>
        /// function to get byte length of buffer
        /// </summary>
        /// <returns>returns byte length of buffer</returns>
        size_t GetByteLength() const;
        /// <summary>
        /// function to get pointer to buffer data
        /// </summary>
        /// <param name="p_index"> offset bytes or index in to array </param>
        /// <param name="p_length"> length in bytes required </param>
        /// <returns>returns pointer to buffer data if the index is within array bounds. else returns null</returns>
        const CHAR8* GetBufferArray(const size_t p_index, const size_t p_length) const;
	};
    /// @}
}

#endif