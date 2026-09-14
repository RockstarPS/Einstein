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
///  @file    : rc_gunzip.h
///  @brief   : Support function to decode gzip content. leveraged from 
///             PSA P2D3 LoadEngine component pvrzTextureDecode
//  Created on  : 02-Jul-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef rc_gunzip_h
#define rc_gunzip_h

namespace rendercore_engine
{
    /// <summary>
    /// Decodes a gzip compressed file to raw bytes
    /// <param name="p_inbuffer">gzip compressed source data buffer</param>
    /// <param name="p_inlength">compressed source data buffer length in bytes</param>
    /// <param name="p_outlength">storage for updating the number of bytes available in returned buffer pointer</param>
    /// <returns>returns a dynamically allocated buffer with uncompressed data. nullptr in case of any error</returns>
    /// </summary>
    extern CHAR8 const* rc_gunzip(const CHAR8* const p_inbuffer, const ulong_t p_inlength, size_t& p_outlength);
    /// Performs decompression of zstd compressed data
    extern CHAR8 const* rc_unzstd(const CHAR8* const p_inbuffer, const size_t p_inlength, size_t& p_outlength);
}

#endif