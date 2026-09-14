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
//  Filename    : gfx3d_scg_bufferview.h
//  Description : GFX3D scene graph bufferview object
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gfx3d_scg_bufferview.h
/// \brief GFX3D scene graph bufferview object
#ifndef gfx3d_scg_bufferview_h
#define gfx3d_scg_bufferview_h

namespace rendercore_engine
{
    /// @{
    /// <summary>
	/// contains the bufferview class which defines the model getting loaded
    /// https://github.com/KhronosGroup/glTF/tree/master/specification/2.0#buffers-and-buffer-views
    /// </summary>
	class gfx3d_scg_bufferview : public gfx3d_scg_mem_obj
	{
	private:
        gfx3d_scg_display* display = nullptr;			///< parent display								
        size_t byteOffset = 0U;							///< offset in to the buffer data / start of the bufferview's data
        size_t byteLength = 0U;							///< number of bytes this bufferview represents
        size_t byteStride = 0U;							///< stride in byte between each vertex
        std::string name;								///< name of the buffer
        int32_t buffer = -1;							///< id of the buffer object to be used or index to gfx3d_scg_display::buffers
        MdlBvTgt_E target = MdlBvTgt_E::bvtInvalid;		///< buffer view target 
        bool bLoaded = false;                           ///< if true indicates that the buffer is loaded
        GLuint lGlVBuffer = 0U;                         ///< gl buffer object handle, incase this accessor data to be uploaded to a gl buffer object  
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
        mutable std::recursive_mutex data_mutex; ///< mutex to protect all data access by threads
#endif
    public:
        /// <summary>
        /// Constructs a bufferview
        /// </summary>
        /// <param name="p_parent"> parent display this accessor belongs to </param>
        gfx3d_scg_bufferview(gfx3d_scg_display * const p_parent);
        /// Distructor
        virtual ~gfx3d_scg_bufferview();
        /// <summary>
        /// Loads this node by creating dynamic contents..
        /// </summary>
        /// <param name="p_uid">id of the caller who is requesting this load</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        bool Load(const rc_bufferUserId p_uid);
        /// <summary>
        /// Unloads this node by deleting dynamic contents.. if none of the scene uses this node anymore
        /// </summary>
        /// <param name="p_uid">id of the caller who is requesting this unload</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        bool UnLoad(const rc_bufferUserId p_uid);
        /// returns  the bytes of size length from data 
        /// <summary>
        /// Returns data bytes from this byfferview from (p_offset) start index p_offset to (p_length) number of bytes
        /// </summary>
        /// <param name="p_offset">start index</param>
        /// <param name="p_length">length / number of bytes</param>
        /// <returns>returns data pointer if p_length data bytes exist from start p_offset in the buffer  </returns>
        const CHAR8* GetBytes(size_t p_offset, const size_t p_length) const;
        /// <summary>
        /// Get the name
        /// </summary>
        /// <returns>returns name </returns>
        std::string GetName() const;
        /// <summary>
        /// Set the name
        /// </summary>
        /// <param name="p_name"> name of bufferview </param>
        void SetName(const std::string p_name);
        /// <summary>
        /// Set the source data buffer for this bufferview.
        /// </summary>
        /// <param name="p_buffer"> buffer id/index to gfx3d_scg_display::buffers </param>
        void SetBuffer(const int32_t p_buffer);
        /// <summary>
        /// Get the source data buffer for this bufferview.
        /// </summary>
        /// <returns>buffer id/index to gfx3d_scg_display::buffers </returns>
        int32_t GetBuffer() const;
        /// <summary>
        /// Set byte offset
        /// </summary>
        /// <param name="p_byteOffset"> byte offset </param>
        void SetByteOffset(const size_t p_byteOffset);
        /// <summary>
        /// Get byte offset
        /// </summary>
        /// <returns>returns byte offset </returns>
        size_t GetByteOffset() const;
        /// <summary>
        /// Set byte length of bufferView
        /// </summary>
        /// <param name="p_byteLength"> byte length of bufferView </param>
        void SetByteLength(const size_t p_byteLength);
        /// <summary>
        /// Get byte length of bufferView
        /// </summary>
        /// <returns>returns byte length of bufferView</returns>
        size_t GetByteLength() const;
        /// <summary>
        /// Set byte stride
        /// </summary>
        /// <param name="p_byteStride"> byte stride </param>
        void SetByteStride(const size_t p_byteStride);
        /// <summary>
        /// Get byte stride
        /// </summary>
        /// <returns>returns byte stride </returns>
        size_t GetByteStride() const;
        /// <summary>
        /// Set bufferView target
        /// </summary>
        /// <param name="p_target"> bufferView target of type MdlBvTgt_E </param>
        void SetTarget(const MdlBvTgt_E p_target);
        /// <summary>
        /// Get bufferView target
        /// </summary>
        /// <returns>returns bufferView target </returns>
        MdlBvTgt_E GetTarget() const;
        /// <summary>
        /// function to get pointer to parent display
        /// </summary>
        /// <returns>returns pointer to parent display </returns>
        gfx3d_scg_display* GetDisplay() const;
        /// <summary>
        /// Sets the parent display
        /// </summary>
        /// <param name="p_disp">parent display</param>
        void SetDisplay(gfx3d_scg_display* const p_disp);
        /// <summary>
        /// Creates a GL buffer objects with the accessor data
        /// </summary>
        /// <param name="p_type"> buffer type  </param>
        /// <returns>returns id of the gl buffer </returns>
        GLuint GetGlBuffer(const GLenum p_type);
        /// <summary>
        /// Memmory object unload function.
        /// </summary>
        /// <returns>unloaded flag</returns>
        bool MemMonitorObjUnload();
    };
    /// @}
}

#endif