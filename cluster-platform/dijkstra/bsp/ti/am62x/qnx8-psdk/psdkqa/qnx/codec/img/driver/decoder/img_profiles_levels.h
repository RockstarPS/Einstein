/*****************************************************************************
*
* Copyright (c) Imagination Technologies Ltd.
* Copyright (c) 2018-22 Texas Instruments Incorporated - http://www.ti.com/
*
* The contents of this file are subject to the MIT license as set out below.
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHERa
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*
* Alternatively, the contents of this file may be used under the terms of the
* GNU General Public License Version 2 ("GPL")in which case the provisions of
* GPL are applicable instead of those above.
*
* If you wish to allow use of your version of this file only under the terms
* of GPL, and not to allow others to use your version of this file under the
* terms of the MIT license, indicate your decision by deleting the provisions
* above and replace them with the notice and other provisions required by GPL
* as set out in the file called "GPLHEADER" included in this distribution. If
* you do not delete the provisions above, a recipient may use your version of
* this file under the terms of either the MIT license or GPL.
*
* This License is also included in this distribution in the file called
* "MIT_COPYING".
*
*****************************************************************************/
/*
 * VXD DEC SYSDEV and UI Interface header
 */

#ifndef __IMG_PROFILES_LEVELS_H
#define __IMG_PROFILES_LEVELS_H

#include "vdecdd_utils.h"

/* Minimum level value for h.264 */
#define H264_LEVEL_MIN              (9)
/* Maximum level value for h.264 */
#define H264_LEVEL_MAX             (52)
/* Number of major levels for h.264 (5 + 1 for special levels) */
#define H264_LEVEL_MAJOR_NUM        (6)
/* Number of minor levels for h.264 */
#define H264_LEVEL_MINOR_NUM		(4)
/* h.264 Baseline/Constrained Baseline profile id.  */
#define H264_PROFILE_BASELINE      (66)
/* h.264 Main profile id.                           */
#define H264_PROFILE_MAIN          (77)
/* h.264 Extended profile id.                       */
#define H264_PROFILE_EXTENDED      (88)
/* h.264 High profile id.                           */
#define H264_PROFILE_HIGH         (100)
/* h.264 High 4:4:4 profile id.                     */
#define H264_PROFILE_HIGH444      (244)
/* h.264 High 4:2:2 profile id.                     */
#define H264_PROFILE_HIGH422      (122)
/* h.264 High 10 profile id.                        */
#define H264_PROFILE_HIGH10       (110)
/* h.264 CAVLC 4:4:4 Intra profile id.              */
#define H264_PROFILE_CAVLC444	(44)
/* h.264 Multiview High profile id.                 */
#define H264_PROFILE_MVC_HIGH     (118)
/* h.264 Stereo High profile id.                    */
#define H264_PROFILE_STEREO_HIGH  (128)

/* HEVC related definitions */

/* Minimum level value for HEVC */
#define HEVC_LEVEL_MIN             (30)
/* Maximum level value for HEVC */
#define HEVC_LEVEL_MAX            (186)
/* Number of major levels for HEVC */
#define HEVC_LEVEL_MAJOR_NUM        (6)
/* Number of minor levels for HEVC */
#define HEVC_LEVEL_MINOR_NUM        (3)
/* HEVC Main general_profile_idc value */
#define HEVC_PROFILE_MAIN           (1)
/* HEVC Main 10 general_profile_idc value */
#define HEVC_PROFILE_MAIN10         (2)
/* HEVC Main Still Picture general_profile_idc value */
#define HEVC_PROFILE_MAINSP         (3)

#endif /*__IMG_PROFILES_LEVELS_H */
