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
//  Filename    : gfx3d_scg_types.h
//  Description : GFX3D scene graph / engine specific generic types.
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file gfx3d_scg_types.h
/// \brief GFX3D scene graph generic types.
#ifndef gfx3d_scg_types_h
#define gfx3d_scg_types_h

#if defined(WIN32)
#include <windows.h>
#endif
#include <cstdlib>  
#if defined(_DEBUG)
#include <crtdbg.h>  
#include <string>
#endif
#include <array>
#include <cassert>
#include <cstdint>
#include <cstring>
#include <map>
#include <string>
#include <vector>
#include <malloc.h>
#include "gfx3d_types.h"
#include "rc_global_mem_allocator.h"
#include "rc_string.h"
#include "rc_mltext.h"
#include "gfx3d_math.h"
#include "rc_platform_cfg.h"
#include "rc_time.h"

namespace rendercore_engine
{
	class gfx3d_scg_3dtext_node;
	class gfx3d_scg_accessor;
	class gfx3d_scg_anim;
	class gfx3d_scg_image;
	class gfx3d_scg_material;
	class gfx3d_scg_mesh;
	class gfx3d_scg_node;
	class gfx3dTransform;
	class rdf_behaviour;
	class rc_input;

	/// \ingroup Engine
    /// @{
    ///a 4x4 matrix data type with changed flag
	class gfx3d_4x4mat
	{
	private:
        glm::fmat4x4 data{1.0F}; ///< holds the matrix data
		bool changed{ true }; ///< sets to true when object is written with new value
	public:
        inline gfx3d_4x4mat()
		{
		}
		/// sets a new matrix
		inline void Set(const glm::fmat4x4&& p_data)
		{
			data = p_data;
			changed = true;
		}
		/// sets a new matrix
		inline void Set(const glm::fmat4x4& p_data)
		{
			data = p_data;
			changed = true;
		}
		/// returns matrix
		inline const glm::fmat4x4 &Get() const
		{
			return(data);
		}
		inline bool IsChanged() const
		{
			return(changed);
		}
		inline void ClearChanged()
		{
			changed = false;
		}
	};
	///a 4x4 matrix, inverse mat data type with changed flag
	class gfx3d_4x4imat
	{
	private:
		glm::fmat4x4 data{ 1.0F }; ///< holds the matrix data
		glm::fmat4x4 inverse{ 1.0F }; ///< holds the inverse matrix data
		bool changed{ true }; ///< sets to true when object is written with new value
	public:
		inline gfx3d_4x4imat()
		{
		}
		/// sets a new matrix
		inline void Set(const glm::fmat4x4&& p_data)
		{
			data = p_data;
			inverse = glm::inverse(p_data);
			changed = true;
		}
		/// sets a new matrix
		inline void Set(const glm::fmat4x4& p_data)
		{
			data = p_data;
			inverse = glm::inverse(p_data);
			changed = true;
		}
		/// sets a new matrix
		inline void SetInv(const glm::fmat4x4&& p_data)
		{
			inverse = p_data;
			data = glm::inverse(p_data);
			changed = true;
		}
		/// sets a new matrix
		inline void SetInv(const glm::fmat4x4& p_data)
		{
			inverse = p_data;
			data = glm::inverse(p_data);
			changed = true;
		}
		/// returns matrix
		inline const glm::fmat4x4& Get() const
		{
			return(data);
		}
		inline const glm::fmat4x4& GetInv() const
		{
			return(inverse);
		}
		inline bool IsChanged() const
		{
			return(changed);
		}
		inline void ClearChanged()
		{
			changed = false;
		}
	};
	///a vec3 (position) data type with changed flag
    class gfx3d_vec3
	{
	private:
        glm::vec3 data; ///< holds the vec3 data
		bool changed{ true }; ///< sets to true when vec3 data is changed
	public:
        inline gfx3d_vec3()
		{
			data = glm::vec3(0.0F);
		}
		inline explicit gfx3d_vec3(const float32_t p_data)
		{
			data = glm::vec3(p_data);
		}
		/// sets the position
		inline bool Set(const glm::vec3& p_data)
		{
			bool fl_changed;
			if ((rc_fisEqual(p_data.x, data.x) == false) ||
				(rc_fisEqual(p_data.y, data.y) == false) ||
				(rc_fisEqual(p_data.z, data.z) == false))
			{
				data = p_data;
				changed = true;
				fl_changed = true;
			}
			else
			{
				fl_changed = false;
			}
			return(fl_changed);
		}
		inline bool SetX(const float32_t p_data)
		{
			bool fl_changed;
			if (rc_fisEqual(p_data, data.x) == false)
			{
				data.x = p_data;
				changed = true;
				fl_changed = true;
			}
			else
			{
				fl_changed = false;
			}
			return(fl_changed);
		}
		// for initialization..
		inline bool Set(const float32_t p_datax, const float32_t p_datay, const float32_t p_dataz)
		{
			bool fl_changed;
			if ((rc_fisEqual(p_datax, data.x) == false) ||
				(rc_fisEqual(p_datay, data.y) == false) ||
				(rc_fisEqual(p_dataz, data.z) == false))
			{
				data.x = p_datax;
				data.y = p_datay;
				data.z = p_dataz;
				changed = true;
				fl_changed = true;
			}
			else
			{
				fl_changed = false;
			}
			return(fl_changed);
		}
		inline bool SetY(const float32_t p_data)
		{
			bool fl_changed;
			if (rc_fisEqual(p_data, data.y) == false)
			{
				data.y = p_data;
				changed = true;
				fl_changed = true;
			}
			else
			{
				fl_changed = false;
			}
			return(fl_changed);
		}
		inline bool SetZ(const float32_t p_data)
		{
			bool fl_changed;
			if (rc_fisEqual(p_data, data.z) == false)
			{
				data.z = p_data;
				changed = true;
				fl_changed = true;
			}
			else
			{
				fl_changed = false;
			}
			return(fl_changed);
		}
		/// sets the position
		inline bool Set(const glm::vec3&& p_data)
		{
			bool fl_changed;
			if ((rc_fisEqual(p_data.x, data.x) == false) ||
				(rc_fisEqual(p_data.y, data.y) == false) ||
				(rc_fisEqual(p_data.z, data.z) == false))
			{
				data = p_data;
				changed = true;
				fl_changed = true;
			}
			else
			{
				fl_changed = false;
			}
			return(fl_changed);
		}
		inline bool Set(const float32_t p_data)
		{
			bool fl_changed;
			if ((rc_fisEqual(p_data, data.x) == false) ||
				(rc_fisEqual(p_data, data.y) == false) ||
				(rc_fisEqual(p_data, data.z) == false))
			{
				data.x = p_data;
				data.y = p_data;
				data.z = p_data;
				changed = true;
				fl_changed = true;
			}
			else
			{
				fl_changed = false;
			}
			return(fl_changed);
		}
		inline float32_t GetX() const
		{
			return(data.x);
		}
		inline float32_t GetY() const
		{
			return(data.y);
		}
		inline float32_t GetZ() const
		{
			return(data.z);
		}
		/// gets the position
		inline const glm::vec3 &Get() const
		{
			return(data);
		}
		inline void SetChanged(const bool p_val)
		{
			changed = p_val;
		}
		inline bool IsChanged()
		{
			const bool fl_changed = changed;
			changed = false;
			return(fl_changed);
		}
		inline const gfx3d_vec3& operator=(const glm::vec4& s1)
		{
			this->data = s1;
			return *this;
		}
	};

    ///a vec4 (quarternian rotations) data type with changed flag
	class gfx3d_rotation
	{
	private:
		glm::vec3 dataEular;	///< Eular rotation
        glm::vec4 dataQuat;		///< holds the vec4 data
		bool changed{ true };	///< sets to true when of the object is changed
	public:
		/// <summary>
		/// Ctor initializes to zero rotation
		/// </summary>
		inline gfx3d_rotation()
		{
			dataEular = glm::vec3(0.0F);
			dataQuat = glm::vec4(0.0F, 0.0F, 0.0F, 1.0F);
		}
		/// <summary>
		/// Ctor with Quaternion angle
		/// </summary>
		/// <param name="p_data">Quaternion angle as vec4</param>
		inline gfx3d_rotation(const glm::vec4 p_data)
		{
			dataQuat = p_data;
			dataEular = gfx3d_math::rc_quat_to_euler(glm::quat(p_data.w, p_data.x, p_data.y, p_data.z));
		}
		/// <summary>
		/// Ctor with eular angles in degree
		/// </summary>
		/// <param name="p_data">eular angles in degree</param>
		inline gfx3d_rotation(const glm::vec3 p_data)
		{
			dataEular = p_data;
			glm::quat fl_quat = gfx3d_math::rc_euler_to_quat(dataEular);
			dataQuat.x = fl_quat.x;
			dataQuat.y = fl_quat.y;
			dataQuat.z = fl_quat.z;
			dataQuat.w = fl_quat.w;
		}
		/// <summary>
		/// Set the rotation in quaternion
		/// </summary>
		/// <param name="p_data">quaternion as a vec4</param>
		/// <returns>true if the data was changed</returns>
		inline bool Set(const glm::vec4& p_data)
		{
			bool fl_changed;
			if ((rc_fisEqual(p_data.x, dataQuat.x) == false) ||
				(rc_fisEqual(p_data.y, dataQuat.y) == false) ||
				(rc_fisEqual(p_data.z, dataQuat.z) == false) ||
				(rc_fisEqual(p_data.w, dataQuat.w) == false))
			{
				dataQuat = p_data;
				dataEular = gfx3d_math::rc_quat_to_euler(glm::quat(p_data.w, p_data.x, p_data.y, p_data.z));
				changed = true;
				fl_changed = true;
			}
			else
			{
				fl_changed = false;
			}
			return(fl_changed);
		}
		/// <summary>
		/// Set the rotation in quaternion
		/// </summary>
		/// <param name="p_data">quaternion as a vec4</param>
		/// <returns>true if the data was changed</returns>
		inline bool Set(const glm::vec4&& p_data)
		{
			bool fl_changed;
			if ((rc_fisEqual(p_data.x, dataQuat.x) == false) ||
				(rc_fisEqual(p_data.y, dataQuat.y) == false) ||
				(rc_fisEqual(p_data.z, dataQuat.z) == false) ||
				(rc_fisEqual(p_data.w, dataQuat.w) == false))
			{
				dataQuat = p_data;
				dataEular = gfx3d_math::rc_quat_to_euler(glm::quat(p_data.w, p_data.x, p_data.y, p_data.z));
				changed = true;
				fl_changed = true;
			}
			else
			{
				fl_changed = false;
			}
			return(fl_changed);
		}
		/// <summary>
		/// Set the rotation in quaternion
		/// </summary>
		/// <param name="p_datax">quaternion x</param>
		/// <param name="p_datay">quaternion y</param>
		/// <param name="p_dataz">quaternion z</param>
		/// <param name="p_dataw">quaternion w</param>
		/// <returns>true if the data was changed</returns>
		inline bool Set(const float32_t p_datax, const float32_t p_datay, const float32_t p_dataz, const float32_t p_dataw)
		{
			bool fl_changed;
			if ((rc_fisEqual(p_datax, dataQuat.x) == false) ||
				(rc_fisEqual(p_datay, dataQuat.y) == false) ||
				(rc_fisEqual(p_dataz, dataQuat.z) == false) ||
				(rc_fisEqual(p_dataw, dataQuat.w) == false))
			{
				dataQuat.x = p_datax;
				dataQuat.y = p_datay;
				dataQuat.z = p_dataz;
				dataQuat.w = p_dataw;
				dataEular = gfx3d_math::rc_quat_to_euler(glm::quat(p_dataw, p_datax, p_datay, p_dataz));
				changed = true;
				fl_changed = true;
			}
			else
			{
				fl_changed = false;
			}
			return(fl_changed);
		}
		/// gets the Quaternion rotation
		inline const glm::vec4 &GetQuat() const
		{
			return(dataQuat);
		}
		/// <summary>
		/// Set the data dirty flag
		/// </summary>
		/// <param name="p_val">dirty state</param>
		inline void SetChanged(const bool p_val)
		{
			changed = p_val;
		}
		/// <summary>
		/// Check the data is dirty or not. Also clears the flag on read
		/// </summary>
		/// <returns>true if the data is dirty</returns>
		inline bool IsChanged()
		{
			const bool fl_changed = changed;
			changed = false;
			return(fl_changed);
		}
		/// <summary>
		/// Set the Eular Rotation X angles in degree
		/// </summary>
		/// <param name="p_data">angles in degree</param>
		/// <returns>true if data changed</returns>
		inline bool SetX(const float32_t p_data)
		{
			bool fl_changed;
			if (rc_fisEqual(p_data, dataEular.x) == false)
			{
				dataEular.x = p_data;
				glm::quat fl_quat = gfx3d_math::rc_euler_to_quat(dataEular);
				dataQuat.x = fl_quat.x;
				dataQuat.y = fl_quat.y;
				dataQuat.z = fl_quat.z;
				dataQuat.w = fl_quat.w;
				changed = true;
				fl_changed = true;
			}
			else
			{
				fl_changed = false;
			}
			return(fl_changed);
		}
		// for initialization..
		/// <summary>
		/// Set the Eular Rotation angles in degree
		/// </summary>
		/// <param name="p_data">angles in degree</param>
		/// <returns>true if data changed</returns>
		inline bool Set(const float32_t p_datax, const float32_t p_datay, const float32_t p_dataz)
		{
			bool fl_changed;
			if ((rc_fisEqual(p_datax, dataEular.x) == false) ||
				(rc_fisEqual(p_datay, dataEular.y) == false) ||
				(rc_fisEqual(p_dataz, dataEular.z) == false))
			{
				dataEular.x = p_datax;
				dataEular.y = p_datay;
				dataEular.z = p_dataz;
				glm::quat fl_quat = gfx3d_math::rc_euler_to_quat(dataEular);
				dataQuat.x = fl_quat.x;
				dataQuat.y = fl_quat.y;
				dataQuat.z = fl_quat.z;
				dataQuat.w = fl_quat.w;
				changed = true;
				fl_changed = true;
			}
			else
			{
				fl_changed = false;
			}
			return(fl_changed);
		}
		/// <summary>
		/// Set the Eular Rotation Y angles in degree
		/// </summary>
		/// <param name="p_data">angles in degree</param>
		/// <returns>true if data changed</returns>
		inline bool SetY(const float32_t p_data)
		{
			bool fl_changed;
			if (rc_fisEqual(p_data, dataEular.y) == false)
			{
				dataEular.y = p_data;
				glm::quat fl_quat = gfx3d_math::rc_euler_to_quat(dataEular);
				dataQuat.x = fl_quat.x;
				dataQuat.y = fl_quat.y;
				dataQuat.z = fl_quat.z;
				dataQuat.w = fl_quat.w;
				changed = true;
				fl_changed = true;
			}
			else
			{
				fl_changed = false;
			}
			return(fl_changed);
		}
		/// <summary>
		/// Set the Eular Rotation Z angles in degree
		/// </summary>
		/// <param name="p_data">angles in degree</param>
		/// <returns>true if data changed</returns>
		inline bool SetZ(const float32_t p_data)
		{
			bool fl_changed;
			if (rc_fisEqual(p_data, dataEular.z) == false)
			{
				dataEular.z = p_data;
				glm::quat fl_quat = gfx3d_math::rc_euler_to_quat(dataEular);
				dataQuat.x = fl_quat.x;
				dataQuat.y = fl_quat.y;
				dataQuat.z = fl_quat.z;
				dataQuat.w = fl_quat.w;
				changed = true;
				fl_changed = true;
			}
			else
			{
				fl_changed = false;
			}
			return(fl_changed);
		}
		/// sets the position
		/// <summary>
		/// Set the Eular Rotation angles in degree
		/// </summary>
		/// <param name="p_data">angles in degree</param>
		/// <returns>true if data changed</returns>
		inline bool Set(const glm::vec3& p_data)
		{
			bool fl_changed;
			if ((rc_fisEqual(p_data.x, dataEular.x) == false) ||
				(rc_fisEqual(p_data.y, dataEular.y) == false) ||
				(rc_fisEqual(p_data.z, dataEular.z) == false))
			{
				dataEular = p_data;
				glm::quat fl_quat = gfx3d_math::rc_euler_to_quat(dataEular);
				dataQuat.x = fl_quat.x;
				dataQuat.y = fl_quat.y;
				dataQuat.z = fl_quat.z;
				dataQuat.w = fl_quat.w;
				changed = true;
				fl_changed = true;
			}
			else
			{
				fl_changed = false;
			}
			return(fl_changed);
		}
		/// sets the position
		/// <summary>
		/// Set the Eular Rotation angles in degree
		/// </summary>
		/// <param name="p_data">angles in degree</param>
		/// <returns>true if data changed</returns>
		inline bool Set(const glm::vec3&& p_data)
		{
			bool fl_changed;
			if ((rc_fisEqual(p_data.x, dataEular.x) == false) ||
				(rc_fisEqual(p_data.y, dataEular.y) == false) ||
				(rc_fisEqual(p_data.z, dataEular.z) == false))
			{
				dataEular = p_data;
				glm::quat fl_quat = gfx3d_math::rc_euler_to_quat(dataEular);
				dataQuat.x = fl_quat.x;
				dataQuat.y = fl_quat.y;
				dataQuat.z = fl_quat.z;
				dataQuat.w = fl_quat.w;
				changed = true;
				fl_changed = true;
			}
			else
			{
				fl_changed = false;
			}
			return(fl_changed);
		}
		/// <summary>
		/// Set the Eular Rotation angles in degree. Sets X=Y=Z=p_data
		/// </summary>
		/// <param name="p_data">angles in degree</param>
		/// <returns>true if data changed</returns>
		inline bool Set(const float32_t p_data)
		{
			bool fl_changed;
			if ((rc_fisEqual(p_data, dataEular.x) == false) ||
				(rc_fisEqual(p_data, dataEular.y) == false) ||
				(rc_fisEqual(p_data, dataEular.z) == false))
			{
				dataEular.x = p_data;
				dataEular.y = p_data;
				dataEular.z = p_data;
				glm::quat fl_quat = gfx3d_math::rc_euler_to_quat(dataEular);
				dataQuat.x = fl_quat.x;
				dataQuat.y = fl_quat.y;
				dataQuat.z = fl_quat.z;
				dataQuat.w = fl_quat.w;
				changed = true;
				fl_changed = true;
			}
			else
			{
				fl_changed = false;
			}
			return(fl_changed);
		}
		/// <summary>
		/// Get the Eular rotation X angle in degree
		/// </summary>
		/// <returns>angle in degree</returns>
		inline float32_t GetX() const
		{
			return(dataEular.x);
		}
		/// <summary>
		/// Get the Eular rotation Y angle in degree
		/// </summary>
		/// <returns>angle in degree</returns>
		inline float32_t GetY() const
		{
			return(dataEular.y);
		}
		/// <summary>
		/// Get the Eular rotation Z angle in degree
		/// </summary>
		/// <returns>angle in degree</returns>
		inline float32_t GetZ() const
		{
			return(dataEular.z);
		}
		/// <summary>
		/// Get the Eular rotation angle in degree
		/// </summary>
		/// <returns>angle in degree</returns>
		inline const glm::vec3& GetEular() const
		{
			return(dataEular);
		}
	};
    /// @}
}
#endif
