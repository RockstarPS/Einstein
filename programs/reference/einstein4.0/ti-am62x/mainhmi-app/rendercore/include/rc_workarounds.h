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
//  Filename    : rc_workarounds.h
//  Description : Temporary work arounds for different compilers..
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef rc_workarounds_h
#define rc_workarounds_h

// TODO : dirty work for p2d3, need to find the correct solution..
#if defined(RC_STD_GPP0X) && defined(__QNX660__)
#if (__GNUC__ <= 4) && (__GNUC_MINOR__ <= 7) && (__GNUC_PATCHLEVEL__  <= 3)
#include <sstream>
namespace std
{
    template <typename T>
    inline std::string to_string(T value)
    {
        //create an output string stream
        std::ostringstream os;

        //throw the value into the string stream
        os << value;

        //convert the string stream into a string and return
        return os.str();
    }
    template <typename T>
    inline std::u16string to_wstring(T value)
    {
        //create an output string stream
        std::basic_stringstream<char16_t> os;

        //throw the value into the string stream
        os << value;

        //convert the string stream into a string and return
        return os.str();
    }
}
#endif
#endif

// TODO : dirty work for p2d3, need to find the correct solution..
#if defined(RC_QNX_GCC_PATCH) && defined(__QNX660__)
#if (__GNUC__ <= 4) && (__GNUC_MINOR__ <= 7) && (__GNUC_PATCHLEVEL__  <= 3)
namespace std {
    template<class _Ty> inline
        bool isnan(_Ty _Left)
    {	// test for NaN
        return (isnan(_Left));
    }
    template<class _Ty> inline
        bool isinf(_Ty _Left)
    {	// test for NaN
        return (isinf(_Left));
    }
    template<class _Ty> inline
        _Ty roundf(_Ty val)
    {	// test for NaN
        return (roundf(val));
    }
    template<class _Ty> inline
        _Ty copysign(_Ty x, _Ty y)
    {
        if ((x < 0 && y > 0) || (x > 0 && y < 0))
            return -x;
        return x;
    }
    template<class _Ty> inline
        _Ty isfinite(_Ty val)
    {
        return (isfinite(val));
    }
} // namespace std
inline float round(float _Xx)
{
    size_t fl_val = static_cast<size_t>(_Xx + 0.5F);
    return static_cast<float>(fl_val);
}
#endif
#endif

#endif
