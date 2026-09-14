/**
 * fileoverview gl-matrix - High performance matrix and vector operations
 * author Brandon Jones
 * author Colin MacKenzie IV
 * version 2.3.2
 */
/* Copyright (c) 2015, Brandon Jones, Colin MacKenzie IV.

Permission is hereby granted, free of charge, to any person obtaining p_fov copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE. */
/// @file	gfx3d_math.h
///	@brief	gl-matrix - High performance matrix and vector operations
/// @copyright Copyright (c) 2015, Brandon Jones, Colin MacKenzie IV.
/// 02-AUG-2018 | emanoj1 | reproduced a subset from gl-matrix JS implementation. 
/// All functions expects 4x4 matrix
#ifndef gfx3d_math_h
#define gfx3d_math_h

#include <cmath>
#if defined(RC_DEBUG_MSG)
#include <cerrno>
#endif
#include <array>
#include <cassert>
#include <cstdint>
#include <cstring>
#include <map>
#include <string>
#include <vector>
#include <cstdlib>
#include <malloc.h>
#include <cerrno>
#include <algorithm>
#include <functional>
#include "rc_workarounds.h"

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/trigonometric.hpp>
// Include GLM extensions
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtc/quaternion.hpp>

namespace rendercore_engine
{
    // find betterways to resove these dependancies.
    inline int32_t rc_fmod(const int32_t _Xx, const int32_t _Yx)
    {
        return (_Xx % _Yx);
    }
    /// mod with unsigned int values
    inline uint32_t rc_fmod(const uint32_t _Xx, const uint32_t _Yx)
    {
        return (_Xx % _Yx);
    }
    /// mod with float32_t & int values
    inline float32_t rc_fmod(const float32_t _Xx, const float32_t _Yx)
    {
#ifdef RC_QNX_GCC_USE_FMOD
        return std::fmod(_Xx, _Yx);
#else
        return std::fmod(_Xx, _Yx);
#endif
    }
    /// clamp float32_t to range1,range2 with value
    inline float32_t rc_clamp_ext(const float32_t p_range1, const float32_t p_range2, const float32_t p_value)
    {
        float32_t fl_min;
        float32_t fl_max;
        float32_t fl_res;
        if (p_range1 < p_range2)
        {
            fl_min = p_range1;
            fl_max = p_range2;
        }
        else
        {
            fl_min = p_range2;
            fl_max = p_range1;
        }
        if (p_value > fl_max)
        {
            fl_res = fl_max;
        }
        else if (p_value < fl_min)
        {
            fl_res = fl_min;
        }
        else
        {
            fl_res = p_value;
        }
        return(fl_res);
    }
    /// clamp float32_t to lower -> upper with n
    inline float32_t rc_clamp(const float32_t lower, const float32_t upper, const float32_t value)
    {
        float32_t fl_res;
        if (value > upper)
        {
            fl_res = upper;
        }
        else if (value < lower)
        {
            fl_res = lower;
        }
        else
        {
            fl_res = value;
        }
        return(fl_res);
    }
    template<class T>
    /// <summary>
    /// Clamped version of glm::lerp function. p_perc is clamped between 0.0 to 1.0.
    /// glm::lerp doesnot perform the clamp
    /// </summary>
    /// <typeparam name="T">float, vec2,3,4</typeparam>
    /// <param name="p_start">Start value</param>
    /// <param name="p_end">End value</param>
    /// <param name="p_perc">percentage, will be clamped to range 0.0 to 1.0</param>
    /// <returns></returns>
    inline T rc_lerp(const T& p_start, const T& p_end, const T& p_perc)
    {
        return(glm::lerp(p_start, p_end, glm::clamp(p_perc, T(0.0F), T(1.0F))));
    }
    /// <summary>
    /// Clamped version of glm::lerp function for angle values.
    /// p_perc is clamped between 0.0 to 1.0.
    /// </summary>
    /// <typeparam name="T">float</typeparam>
    /// <param name="p_start">Start angle value</param>
    /// <param name="p_end">End angle value</param>
    /// <param name="p_perc">percentage, will be clamped to range 0.0 to 1.0</param>
    /// <returns></returns>
    inline float32_t rc_slerp(const float32_t p_start, const float32_t p_end, const float32_t p_perc)
    {
        float32_t fl_dist = (p_end - p_start);
        fl_dist = rc_clamp(0.0F, 360.0F, (fl_dist - (std::floor(fl_dist / 360.0F) * 360.0F)));
        if (fl_dist > 180.0F)
        {
            fl_dist -= 360.0F;
        }
        fl_dist += p_start;
        return (rc_lerp(p_start, fl_dist, p_perc));
    }
    /// <summary>
    /// Checks if the two float values p_a1 and p_a2 are equal. returns true if they are equal
    /// </summary>
    inline bool rc_fisEqual(const float32_t p_a1, const float32_t p_a2)
    {
        bool fl_sts;
        if (std::isinf(p_a1) && std::isinf(p_a2))
        {
            fl_sts = true;
        }
        else if (std::isnan(p_a1) && std::isnan(p_a2))
        {
            fl_sts = false;
        }
        else if (std::fabs(p_a1 - p_a2) < FLT_EPSILON)
        {
            fl_sts = true;
        }
        else
        {
            fl_sts = false;
        }
        return(fl_sts);
    }
    /// <summary>
    /// Checks if p_a == 0, returns true if zero
    /// </summary>
    inline bool rc_fisZero(const float32_t p_a)
    {
        bool fl_sts;
        if (std::fabs(p_a) < FLT_EPSILON)
        {
            fl_sts = true;
        }
        else
        {
            fl_sts = false;
        }
        return(fl_sts);
    }

    /// <summary>
    /// Calculate position moved toward from p_current to p_to by the fixed delta amount. Will not go past the final value.
    /// </summary>
    inline glm::vec3 rc_move_toward(const glm::vec3& p_current, const glm::vec3& p_to, const float32_t p_delta)
    {
        glm::vec3 vd = p_to - p_current;
        float32_t len = glm::length(vd);
        return len <= p_delta || len < FLT_EPSILON ? p_to : p_current + vd / len * p_delta;
    }

    /// \ingroup Utlities
    /// @{
    ///a math helper class for OpenGL, all functions are required to be supplied with a 4x4 matrix
	class gfx3d_math
	{
    private:
        static bool isLHSCoord; ///< indicates if the project follows LHS or RHS coordinate
	public:
        /// Set the co ordinate system
        /// \attention this API is internally invoked and not designed for invocation by application
        static void SetCoordSystem(const MdlCoordSystem &p_coord);
        /// Gets PI constant
        static float32_t RcPI(void);
		///convert from quarternian to euler X
        /// \attention logic source is from web
        static float32_t Qaut2EulerAngleX(const glm::vec4& p_quat, const float32_t p_offset = 0.0F);
		///convert from quarternian to euler Y
        static float32_t Qaut2EulerAngleY(const glm::vec4& p_quat, const float32_t p_offset = 0.0F);
		///convert from quarternian to euler Z
        static float32_t Qaut2EulerAngleZ(const glm::vec4& p_quat, const float32_t p_offset = 0.0F);
		///convert from quarternian to euler 
        static void Qaut2EulerAngle(const glm::vec4& p_quat, float32_t& p_xrot, float32_t& p_yrot, float32_t& p_zrot);
		/// create a perspective 4x4 matrix based on, fov, aspect ration, near and far plane supplied
        static void rc_matrix4x4_perspective(float32_t * const p_matrix, const float32_t p_fov, const float32_t p_aspect, const float32_t p_znear, const float32_t p_zfar);
		/// multiple the 2  4x4 matrices
        static void rc_matrix4x4_multiply(float32_t * const p_dm, const float32_t* const p_m1, const float32_t* const p_m2);
		/// rotate around X axis with supplied angle
        static void rc_matrix4x4_rotateX(float32_t * const p_t, const float32_t* const p_a, const float32_t p_n);
		/// rotate around Y axis with supplied angle
        static void rc_matrix4x4_rotateY(float32_t * const p_t, const float32_t* const p_a, const float32_t p_n);
		/// scaling based on rotation and translation
        static void rc_fromRotationTranslationScale(GLfloat * const p_t, const float32_t* const p_rot_a, const float32_t* const p_trans_n, const float32_t* const p_scale_r);
		/// invert the given 4x4  matrix
        static void rc_matrix4x4_invert(float32_t * const p_t, const float32_t* const p_a);
		/// transpose a 4x4 matrix
        static void rc_matrix4x4_transpose(float32_t * const p_t, const float32_t* const p_a);
        /// transpose a 4x4 matrix to 3x3 loosing its translation
        static void rc_matrix4x4to3x3_transpose(glm::fmat3x3& p_t, const float32_t* const p_a);
		/// calculate determinant for a 4x4 matrix
        static float32_t rc_matrix4x4_determinant(const float32_t* const p_t);
        /// calculate determinant for a 3x3 matrix
        static float32_t rc_matrix_determinant(const glm::fmat3x3& p_t);
        /// translate [in] matrix by [x,y] and resuly in [out]
        static void rc_matrix4x4_translate(float32_t* const p_out, const float32_t* const p_in, const float32_t p_x, const float32_t p_y, const float32_t p_z);
        /// scale [in] matrix by [x,y] and result in [out]
        static void rc_matrix4x4_scale(float32_t* const p_out, const float32_t* const p_in, const float32_t p_x, const float32_t p_y, const float32_t p_z);
        static void rc_matrix4x4_getscale(glm::vec3& p_out, const glm::fmat4x4& p_in);
        static void rc_matrix4x4_getrotation(glm::quat& p_out, const glm::fmat4x4 p_in);
        static void rc_quat_transform(glm::vec3& p_out, const glm::quat& p_rot, const glm::vec3& p_dir);
        /// <summary>
        /// Convert Eular angle in degree to Quaternion. 
        /// Multiplication order is ZYX
        /// </summary>
        /// <param name="p_eularDegrees"> angle in degree</param>
        /// <returns>Quaternion</returns>
        static glm::quat rc_euler_to_quat(glm::vec3 p_eularDegrees);
        /// <summary>
        /// Convert Quaternion to Eular angle in degree
        /// </summary>
        /// <param name="p_quat"> Quaternion</param>
        /// <returns>angle in degree</returns>
        static glm::vec3 rc_quat_to_euler(const glm::quat& p_quat);
    };
    /// @}
}
#endif