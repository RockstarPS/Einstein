/*
 * Copyright 2022, QNX Software Systems.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject
 * to the following conditions:
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef OMX_EXTENSION_VIDEO_TI_H
#define OMX_EXTENSION_VIDEO_TI_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/***************************************************************************/
/*    Include Files                                                        */
/***************************************************************************/
#include "OMX_Video.h"

/***************************************************************************/
/*    Macro Definitions                                                    */
/***************************************************************************/
/**
 * Buffer header nFlags field extension.
 *
 * Decoder component sets the DISPLAYONLY flag to
 * indicate that the buffer is for display only
 * can not be released yet.
 * client can release the buffer if this flag is not set
 *
 */
#define OMXQ_BUFFERFLAG_DISPLAY 0x80000000

enum {
    OMXQ_VIDEO_CodingHEVC = OMX_VIDEO_CodingVendorStartUnused + 0x1, /**< Extensions for HEVC format */
    OMXQ_VIDEO_CodingVP9,                                            /**< Extensions for VP9 format */
};

enum {
    OMXQ_COLOR_Format1210 = OMX_COLOR_FormatVendorStartUnused + 0x1,
    OMXQ_COLOR_FormatNV16,
    OMXQ_COLOR_Format1610,
    OMXQ_COLOR_FormatP010,
    OMXQ_COLOR_FormatYV12,
    OMXQ_COLOR_FormatIMC3,
    OMXQ_COLOR_Format422H,
    OMXQ_COLOR_Format422V,
    OMXQ_COLOR_Format444P,
    OMXQ_COLOR_FormatY800,
    OMXQ_COLOR_FormatYUY2,
    OMXQ_COLOR_FormatUYVY,
    OMXQ_COLOR_FormatRGBX,
    OMXQ_COLOR_FormatRGBA,
    OMXQ_COLOR_FormatBGRX,
};
/***************************************************************************/
/*    Type  Definitions                                                    */
/***************************************************************************/

/***************************************************************************/
/*    Function Prototypes                                                  */
/***************************************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* OMX_EXTENSION_VIDEO_TI_H */


