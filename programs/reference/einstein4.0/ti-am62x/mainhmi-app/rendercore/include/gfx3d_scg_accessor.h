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
/// @file  gfx3d_scg_accessor.h
/// \brief GFX3D scene graph accessor object
#ifndef gfx3d_scg_accessor_h
#define gfx3d_scg_accessor_h

namespace rendercore_engine
{
    /// \ingroup Engine
    /// @{
    /// <summary>
	/// data used by gfx3d_scg_accessor class
	/// </summary>
	class gfx3d_scg_accessor_data
    {
    private:
        const CHAR8* bytes = nullptr;		///< raw bytes in char format
        size_t totalBytes = 0U;				///< size of total bytes
        size_t byteStride = 0U;				///< stride if used
        size_t typeSize = 0U;			    ///< number of components (1=scalar, 2 = vec2, 3 = vec3 ...)
        size_t componentSizeBytes = 0U;		///< component size bytes
        size_t count = 0U;		            ///< number of attribute present
        MdlCompType_E componentType = MdlCompType_E::ctByte;	///< type of data to be transferred
        bool normalized = false;            ///< data normalized or not
    public:
        /// <summary>
        /// Set pointer to data buffer
        /// </summary>
        /// <param name="p_bytes"> pointer to data buffer</param>
        void SetBytes(const CHAR8* const p_bytes);
        /// <summary>
        /// function to get pointer to data buffer
        /// </summary>
        /// <returns>returns pointer to data buffer </returns>
        const CHAR8* GetBytes() const;
        /// <summary>
        /// Set total bytes used by accessor data
        /// </summary>
        /// <param name="p_totalBytes"> total bytes used by accessor data</param>
        void SetTotalBytes(const size_t p_totalBytes);
        /// <summary>
        /// function to get total bytes used by accessor data
        /// </summary>
        /// <returns>returns total bytes used by accessor data </returns>
        size_t GetTotalBytes() const;
        /// <summary>
        /// Set stride count if any
        /// </summary>
        /// <param name="p_byteStride"> stride count if any</param>
        void SetByteStride(const size_t p_byteStride);
        /// <summary>
        /// function to get stride count if any
        /// </summary>
        /// <returns>returns stride count </returns>
        size_t GetByteStride() const;
        /// <summary>
        /// Set size bytes
        /// </summary>
        /// <param name="p_typeSize"> size bytes</param>
        void SetTypeSize(const size_t p_typeSize);
        /// <summary>
        /// function to get size bytes
        /// </summary>
        /// <returns>returns size bytes </returns>
        size_t GetTypeSize() const;
        /// <summary>
        /// Set component size bytes
        /// </summary>
        /// <param name="p_componentSizeBytes"> component size bytes of type size_t</param>
        void SetComponentSizeBytes(const size_t p_componentSizeBytes);
        /// <summary>
        /// function to get component size bytes
        /// </summary>
        /// <returns>returns component size bytes</returns>
        size_t GetComponentSizeBytes() const;
        /// <summary>
        /// Set data type of the buffer
        /// </summary>
        /// <param name="p_componentType"> data type of the buffer</param>  
        void SetComponentType(const MdlCompType_E p_componentType);
        /// <summary>
        /// function to get component type of the buffer
        /// </summary>
        /// <returns>returns component type of the buffer if type MdlCompType_E </returns>
        MdlCompType_E GetComponentType() const;
        /// <summary>
        /// Returns the total number of attribute held by this accessor data
        /// </summary>
        /// <returns>total vertices</returns>
        size_t GetAttributeCount() const;
        /// <summary>
        /// Sets the total number of attribute held by this accessor data
        /// </summary>
        /// <param name="p_count">number of attributes</param>
        void SetAttributeCount(const size_t p_count);
        /// <summary>
        /// Returns the total number of bytes taken per attribute
        /// </summary>
        /// <returns>number of bytes per attribute</returns>
        size_t GetBytesPerAttribute() const;
        /// <summary>
        /// Gets if the data is normalized?
        /// </summary>
        /// <returns>true or false</returns>
        bool GetNormalized() const;
        /// <summary>
        /// Sets if the data is normalized
        /// </summary>
        /// <param name="p_normalized">true or false</param>
        void SetNormalized(const bool p_normalized);
    };
    /// <summary>
	/// Accessor class will essentially populate bufferView and buffer.
	/// Refer https://github.com/KhronosGroup/glTF/tree/master/specification/2.0#accessors.
    /// for more info as this is derived based on gltf
	/// </summary>
	class gfx3d_scg_accessor
	{
	private:
        std::string name;					  ///< name of accessor
        size_t byteOffset = 0U;	///< byte offset if data is interleaved
        size_t count = 0U;                    ///< number of vertices
        size_t typeSize = 0U;	              ///< number of components MdlType_E / (1=scalar, 2 = vec2, 3 = vec3 ...)
        size_t componentSizeBytes = 0U;		  ///< number of bytes per componentType
        size_t totalBytes = 0U;	              ///< total bytes used by accessor
        size_t byteStride = 0U;	              ///< strides used if any 
        int32_t bufferView = -1;		      ///< the bufferview index for this accessor
        MdlType_E type = MdlType_E::dtScalar; ///< data type of component 
        MdlCompType_E componentType = MdlCompType_E::ctByte;///< data type of the buffer
        rc_flag sceneLoadedMask;              ///< indicates for which scenes loaded this object. Used to decide how many are using
        bool bLoaded = false;                 ///< if true indicates that the buffer is loaded
        bool normalized = false;			  ///< is the data normalized
        gfx3d_scg_display * display = nullptr; ///< display parent object
        const CHAR8* bytes = nullptr;		  ///< total bytes 
        glm::vec4 min{FLT_MAX,FLT_MAX,FLT_MAX,FLT_MAX};     ///< minimum value of elements (valid only for float vec2/3/4)
        glm::vec4 max{-FLT_MAX,-FLT_MAX,-FLT_MAX,-FLT_MAX };///< maximum value of elements (valid only for float vec2/3/4)
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
        mutable std::recursive_mutex data_mutex; ///< mutex to protect all data access by threads
#endif
        size_t calculate_total_bytes() const;
    public:
        /// <summary>
        /// Constructs an accessor
        /// </summary>
        /// <param name="p_parent"> parent display this accessor belongs to </param>
        gfx3d_scg_accessor(gfx3d_scg_display * const p_parent);
        /// Distructor
        virtual ~gfx3d_scg_accessor();
        /// <summary>
        /// Creates the accessor by calculating internal data
        /// Updates componentSizeBytes, typeSize & totalBytes
        /// </summary>
        void Create(void);
        /// <summary>
        /// Loads this node by creating dynamic contents..
        /// </summary>
        /// <param name="p_scene">id of the scene which is requesting this node load</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        bool Load(const size_t p_scene);
        /// <summary>
        /// Unloads this node by deleting dynamic contents.. if none of the scene uses this node anymore
        /// </summary>
        /// <param name="p_scene">id of the scene which is requesting this node unload</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        bool UnLoad(const size_t p_scene);
        /// <summary>
        /// Set accessor's name
        /// </summary>
        /// <param name="p_name"> name of accessor of type string </param>
        void SetName(const std::string p_name);
        /// <summary>
        /// Get name of accessor
        /// </summary>
        /// <returns>returns name of accessor object </returns>
        std::string GetName() const;
        /// <summary>
        /// Set bufferview index of the accessor
        /// </summary>
        /// <param name="p_bufferView"> bufferview index of the accessor of type int </param>
        void SetBufferView(const int32_t p_bufferView);
        /// <summary>
        /// Get bufferview index of the accessor
        /// </summary>
        /// <returns>returns bufferview index of the accessor </returns>
        int32_t GetBufferView() const;
        /// <summary>
        /// Set byte offset if data is interleaved
        /// </summary>
        /// <param name="p_byteOffset"> byte offset if data is interleaved </param>
        void SetByteOffset(const size_t p_byteOffset);
        /// <summary>
        /// Get byte offset if data is interleaved
        /// </summary>
        /// <returns>returns byte offset if data is interleaved </returns>
        size_t GetByteOffset() const;
        /// <summary>
        /// Set component type of the accessor data (byte, unsigned byte ...)
        /// </summary>
        /// <param name="p_componentType"> component type</param>        
        void SetComponentType(const MdlCompType_E p_componentType);
        /// <summary>
        /// Get component type (MdlCompType_E) of the buffer
        /// </summary>
        /// <returns>returns component type of the buffer </returns>
        MdlCompType_E GetComponentType() const;
        /// <summary>
        /// Set true if data is normalized
        /// </summary>
        /// <param name="p_normalized"> true if data is normalized, false otherwise </param>
        void SetNormalized(const bool p_normalized);
        /// <summary>
        /// Get data is normalized status
        /// </summary>
        /// <returns>returns true if data is normalized, false otherwise </returns>
        bool GetNormalized() const;
        /// <summary>
        /// Set accessor's data count (number of types MdlType_E)
        /// </summary>
        /// <param name="p_count"> data count </param>
        void SetCount(const size_t p_count);
        /// <summary>
        /// function to get data count
        /// </summary>
        /// <returns>returns count </returns>
        size_t GetCount() const;
        /// <summary>
        /// Set data type (MdlType_E)
        /// </summary>
        /// <param name="p_type"> MdlType_E type of data  </param>
        void SetType(const MdlType_E p_type);
        /// <summary>
        /// function to get data types
        /// </summary>
        /// <returns>returns one of type in MdlType_E </returns>
        MdlType_E GetType() const;
        /// <summary>
        /// function to get pointer to data buffer
        /// </summary>
        /// <returns>returns pointer to data buffer </returns>
        const CHAR8* GetBytes() const;
        /// <summary>
        /// function to get size bytes
        /// </summary>
        /// <returns>returns size bytes </returns>
        size_t GetTypeSize() const;
        /// <summary>
        /// function to get stride count if any
        /// </summary>
        /// <returns>returns stride count </returns>
        size_t GetByteStride() const;
        /// <summary>
        /// function to get total bytes used by accessor
        /// </summary>
        /// <returns>returns total bytes used by accessor </returns>
        size_t GetTotalBytes() const;
        /// <summary>
        /// Get pointer to parent display
        /// </summary>
        /// <returns>returns pointer to parent display </returns>
        gfx3d_scg_display * GetDisplay() const;
        /// <summary>
        /// Sets the parent display
        /// </summary>
        /// <param name="p_disp">parent display</param>
        void SetDisplay(gfx3d_scg_display* const p_disp);
        /// <summary>
        /// Returns the number of bytes required by MdlCompType_E
        /// </summary>
        /// <returns>returns component size in bytes </returns>
        size_t GetComponentSizeBytes() const;
        /// <summary>
        /// returns the data used by accessor
        /// </summary>
        /// <param name="p_data"> pointer object to copy the accessor data </param>
        /// <returns>returns true if success </returns>
        bool GetData(gfx3d_scg_accessor_data* const p_data) const;
        /// <summary>
        /// Sets the minimum data for the elements held by this accessor.
        /// Its valid only for VEC2/3/4 element types. Accordingly only that many members of glm::vec4 is used
        /// </summary>
        /// <param name="p_min">Minimum value</param>
        void SetMinimum(const glm::vec4& p_min);
        /// <summary>
        /// Sets the maximum data for the elements held by this accessor.
        /// Its valid only for VEC2/3/4 element types. Accordingly only that many members of glm::vec4 is used
        /// </summary>
        /// <param name="p_min">Minimum value</param>
        void SetMaximum(const glm::vec4& p_max);
        /// <summary>
        /// Returns the minimum value in elements held by this accessor
        /// - FLT_MAX indicates the minimum value is not set / invalid
        /// - To be used only for VEC2/3/4 element types
        /// - Use the elements according to element type. E.g. For VEC2 only .x and .y componets to be used
        /// </summary>
        /// <returns>vec4 min value</returns>
        glm::vec4 GetMinimum() const;
        /// <summary>
        /// Returns the maximum value in elements held by this accessor
        /// - -FLT_MAX indicates the maximum value is not set / invalid
        /// - To be used only for VEC2/3/4 element types
        /// - Use the elements according to element type. E.g. For VEC2 only .x and .y componets to be used
        /// </summary>
        /// <returns>vec4 max value</returns>
        glm::vec4 GetMaximum() const;
    };
    /// @}
}

#endif