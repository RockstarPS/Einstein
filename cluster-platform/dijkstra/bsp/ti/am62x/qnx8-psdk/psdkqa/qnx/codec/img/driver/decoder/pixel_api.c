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
 * Pixel processing function implementations
 */

#include "osal/inc/osa_mem.h"
#include "osal/inc/osa_define.h"
#include "osal/inc/osa_err.h"
#include "img_errors.h"
#include "img_pixfmts.h"
#include "pixel_api.h"
#include "vdec_defs.h"

#define NUM_OF_FORMATS 17
#define PIXNAME(x) /* Pixel name support not enabled */
#define FACT_SPEC_FORMAT_NUM_PLANES 4
#define FACT_SPEC_FORMAT_PLANE_UNUSED 0xf
#define FACT_SPEC_FORMAT_PLANE_CODE_BITS 4
#define FACT_SPEC_FORMAT_PLANE_CODE_MASK 3
#define FACT_SPEC_FORMAT_MIN_FACT_VAL 1

/*
 * @brief Pointer to the default format in the asPixelFormats array
 * default format is an invalid format
 * @note pointer set by initSearch()
 * This pointer is also used to know if the arrays were sorted
 */
static struct pixel_pixinfo *def_fmt = NULL;

/*
 * @brief Actual array storing the pixel formats information.
 */
static struct pixel_pixinfo pix_fmts[NUM_OF_FORMATS] = {
	{
		IMG_PIXFMT_420PL12YUV8,
		PIXEL_UV_ORDER,
		PIXEL_MULTICHROME,
		PIXEL_BIT8_MP,
		PIXEL_FORMAT_420,
		8,
		8,
		2
	},

	{
		IMG_PIXFMT_420PL12YVU8,
		PIXEL_VU_ORDER,
		PIXEL_MULTICHROME,
		PIXEL_BIT8_MP,
		PIXEL_FORMAT_420,
		8,
		8,
		2
	},

	{
		IMG_PIXFMT_420PL12YUV10,
		PIXEL_UV_ORDER,
		PIXEL_MULTICHROME,
		PIXEL_BIT10_MP,
		PIXEL_FORMAT_420,
		10,
		10,
		2
	},

	{
		IMG_PIXFMT_420PL12YVU10,
		PIXEL_VU_ORDER,
		PIXEL_MULTICHROME,
		PIXEL_BIT10_MP,
		PIXEL_FORMAT_420,
		10,
		10,
		2
	},

	{
		IMG_PIXFMT_420PL12YUV10_MSB,
		PIXEL_UV_ORDER,
		PIXEL_MULTICHROME,
		PIXEL_BIT10_MSB_MP,
		PIXEL_FORMAT_420,
		10,
		10,
		2
	},

	{
		IMG_PIXFMT_420PL12YVU10_MSB,
		PIXEL_VU_ORDER,
		PIXEL_MULTICHROME,
		PIXEL_BIT10_MSB_MP,
		PIXEL_FORMAT_420,
		10,
		10,
		2
	},

	{
		IMG_PIXFMT_420PL12YUV10_LSB,
		PIXEL_UV_ORDER,
		PIXEL_MULTICHROME,
		PIXEL_BIT10_LSB_MP,
		PIXEL_FORMAT_420,
		10,
		10,
		2
	},

	{
		IMG_PIXFMT_420PL12YVU10_LSB,
		PIXEL_VU_ORDER,
		PIXEL_MULTICHROME,
		PIXEL_BIT10_LSB_MP,
		PIXEL_FORMAT_420,
		10,
		10,
		2
	},

	{
		IMG_PIXFMT_422PL12YUV8,
		PIXEL_UV_ORDER,
		PIXEL_MULTICHROME,
		PIXEL_BIT8_MP,
		PIXEL_FORMAT_422,
		8,
		8,
		2
	},

	{
		IMG_PIXFMT_422PL12YVU8,
		PIXEL_VU_ORDER,
		PIXEL_MULTICHROME,
		PIXEL_BIT8_MP,
		PIXEL_FORMAT_422,
		8,
		8,
		2
	},

	{
		IMG_PIXFMT_422PL12YUV10,
		PIXEL_UV_ORDER,
		PIXEL_MULTICHROME,
		PIXEL_BIT10_MP,
		PIXEL_FORMAT_422,
		10,
		10,
		2
	},

	{
		IMG_PIXFMT_422PL12YVU10,
		PIXEL_VU_ORDER,
		PIXEL_MULTICHROME,
		PIXEL_BIT10_MP,
		PIXEL_FORMAT_422,
		10,
		10,
		2
	},

	{
		IMG_PIXFMT_422PL12YUV10_MSB,
		PIXEL_UV_ORDER,
		PIXEL_MULTICHROME,
		PIXEL_BIT10_MSB_MP,
		PIXEL_FORMAT_422,
		10,
		10,
		2
	},

	{
		IMG_PIXFMT_422PL12YVU10_MSB,
		PIXEL_VU_ORDER,
		PIXEL_MULTICHROME,
		PIXEL_BIT10_MSB_MP,
		PIXEL_FORMAT_422,
		10,
		10,
		2
	},

	{
		IMG_PIXFMT_422PL12YUV10_LSB,
		PIXEL_UV_ORDER,
		PIXEL_MULTICHROME,
		PIXEL_BIT10_LSB_MP,
		PIXEL_FORMAT_422,
		10,
		10,
		2
	},

	{
		IMG_PIXFMT_422PL12YVU10_LSB,
		PIXEL_VU_ORDER,
		PIXEL_MULTICHROME,
		PIXEL_BIT10_LSB_MP,
		PIXEL_FORMAT_422,
		10,
		10,
		2
	},

	{
		IMG_PIXFMT_UNDEFINED,
		PIXEL_INVALID_CI,
		0,
		(enum pixel_mem_packing)0,
		PIXEL_FORMAT_INVALID,
		0,
		0,
		0
	}
};

static struct pixel_pixinfo_table pixinfo_table[] = {
	{
		IMG_PIXFMT_420PL12YUV8_A8,
		{
			PIXNAME(IMG_PIXFMT_420PL12YUV8_A8)
			16,
			16,
			16,
			0,
			16,
			osa_true,
			osa_true,
			4,
			osa_true
		}
	},

	{
		IMG_PIXFMT_422PL12YUV8_A8,
		{
			PIXNAME(IMG_PIXFMT_422PL12YUV8_A8)
			16,
			16,
			16,
			0,
			16,
			osa_true,
			osa_false,
			4,
			osa_true
		}
	},

	{
		IMG_PIXFMT_420PL12YUV8,
		{
			PIXNAME(IMG_PIXFMT_420PL12YUV8)
			16,
			16,
			16,
			0,
			0,
			osa_true,
			osa_true,
			4,
			osa_false
		}
	},

	{
		IMG_PIXFMT_420PL12YVU8,
		{
			PIXNAME(IMG_PIXFMT_420PL12YVU8)
			16,
			16,
			16,
			0,
			0,
			osa_true,
			osa_true,
			4,
			osa_false
		}
	},

	{
		IMG_PIXFMT_420PL12YUV10,
		{
			PIXNAME(IMG_PIXFMT_420PL12YUV10)
			12,
			16,
			16,
			0,
			0,
			osa_true,
			osa_true,
			4,
			osa_false
		}
	},

	{
		IMG_PIXFMT_420PL12YVU10,
		{
			PIXNAME(IMG_PIXFMT_420PL12YVU10)
			12,
			16,
			16,
			0,
			0,
			osa_true,
			osa_true,
			4,
			osa_false
		}
	},

	{
		IMG_PIXFMT_420PL12YUV10_MSB,
		{
			PIXNAME(IMG_PIXFMT_420PL12YUV10_MSB)
			8,
			16,
			16,
			0,
			0,
			osa_true,
			osa_true,
			4,
			osa_false
		}
	},

	{
		IMG_PIXFMT_420PL12YVU10_MSB,
		{
			PIXNAME(IMG_PIXFMT_420PL12YVU10_MSB)
			8,
			16,
			16,
			0,
			0,
			osa_true,
			osa_true,
			4,
			osa_false
		}
	},

	{
		IMG_PIXFMT_422PL12YUV8,
		{
			PIXNAME(IMG_PIXFMT_422PL12YUV8)
			16,
			16,
			16,
			0,
			0,
			osa_true,
			osa_false,
			4,
			osa_false
		}
	},

	{
		IMG_PIXFMT_422PL12YVU8,
		{
			PIXNAME(IMG_PIXFMT_422PL12YVU8)
			16,
			16,
			16,
			0,
			0,
			osa_true,
			osa_false,
			4,
			osa_false
		}
	},

	{
		IMG_PIXFMT_422PL12YUV10,
		{
			PIXNAME(IMG_PIXFMT_422PL12YUV10)
			12,
			16,
			16,
			0,
			0,
			osa_true,
			osa_false,
			4,
			osa_false
		}
	},

	{
		IMG_PIXFMT_422PL12YVU10,
		{
			PIXNAME(IMG_PIXFMT_422PL12YVU10)
			12,
			16,
			16,
			0,
			0,
			osa_true,
			osa_false,
			4,
			osa_false
		}
	},

	{
		IMG_PIXFMT_422PL12YUV10_MSB,
		{
			PIXNAME(IMG_PIXFMT_422PL12YUV10_MSB)
			8,
			16,
			16,
			0,
			0,
			osa_true,
			osa_false,
			4,
			osa_false
		}
	},

	{
		IMG_PIXFMT_422PL12YVU10_MSB,
		{
			PIXNAME(IMG_PIXFMT_422PL12YVU10_MSB)
			8,
			16,
			16,
			0,
			0,
			osa_true,
			osa_false,
			4,
			osa_false
		}
	},
};

static struct pixel_pixinfo_table*
		pixel_get_pixelinfo_from_pixfmt(enum img_pixfmt pix_fmt)
{
	uint32				i;
	uint8				found = osa_false;
	struct pixel_pixinfo_table *this_pixinfo_table_entry = NULL;

	for (i = 0;
	     i < (sizeof(pixinfo_table) / sizeof(struct pixel_pixinfo_table));
	     i++) {
		if (pix_fmt ==  pixinfo_table[i].pix_color_fmt) {
			/*
			 * There must only be one entry per pixel colour format
			 * in the table
			 */
			VDEC_ASSERT(!found);
			found = osa_true;
			this_pixinfo_table_entry = &pixinfo_table[i];

			/*
			 * We deliberately do NOT break here - scan rest of
			 * table to ensure there are not duplicate entries
			 */
		}
	}
	return this_pixinfo_table_entry;
}

/*
 * @brief Array containing string lookup of pixel format IDC.
 * @warning this must be kept in step with PIXEL_FormatIdc.
 */
uint8 pix_fmt_idc_names[6][16] = {
	"Monochrome",
	"4:1:1",
	"4:2:0",
	"4:2:2",
	"4:4:4",
	"Invalid",
};

static int32 pixel_compare_pixfmts(const void *a, const void *b)
{
	return ((struct pixel_pixinfo *)a)->pixfmt -
		((struct pixel_pixinfo *)b)->pixfmt;
}

static struct pixel_info*
		pixel_get_bufinfo_from_pixfmt(enum img_pixfmt pix_fmt)
{
	struct pixel_pixinfo_table *pixinfo_table_entry = NULL;
	struct pixel_info *pix_info = NULL;

	pixinfo_table_entry = pixel_get_pixelinfo_from_pixfmt(pix_fmt);
	VDEC_ASSERT(pixinfo_table_entry);
	if (pixinfo_table_entry)
		pix_info = &pixinfo_table_entry->info;

	return pix_info;
}

/*
 * @brief Search a pixel format based on its attributes rather than its format
 * enum.
 * @warning use PIXEL_Comparpix_fmts to search by enum
 */
static int32 pixel_compare_pixinfo(const void *a, const void *b)
{
	int32 result = 0;
	const struct pixel_pixinfo *fmt_a = (struct pixel_pixinfo *)a;
	const struct pixel_pixinfo *fmt_b = (struct pixel_pixinfo *)b;

	result = fmt_a->chroma_fmt_idc - fmt_b->chroma_fmt_idc;
	if (result != 0)
		return result;

	result = fmt_a->mem_pkg - fmt_b->mem_pkg;
	if (result != 0)
		return result;

	result = fmt_a->chroma_interleave - fmt_b->chroma_interleave;
	if (result != 0)
		return result;

	result = fmt_a->bitdepth_y - fmt_b->bitdepth_y;
	if (result != 0)
		return result;

	result = fmt_a->bitdepth_c - fmt_b->bitdepth_c;
	if (result != 0)
		return result;

	result = fmt_a->num_planes - fmt_b->num_planes;
	if (result != 0)
		return result;

	return result;
}

static void pixel_init_search(void)
{
	static uint32 search_inited = 0;

	search_inited++;
	if (search_inited == 1) {
		if (!def_fmt) {
			int32 i = 0;

			i = NUM_OF_FORMATS - 1;
			while (i >= 0) {
				if (IMG_PIXFMT_UNDEFINED ==
				   pix_fmts[i].pixfmt) {
					def_fmt = &pix_fmts[i];
					break;
				}
			}
			VDEC_ASSERT(def_fmt);
		}
	} else {
		search_inited--;
	}
}

static struct pixel_pixinfo *pixel_search_fmt(const struct pixel_pixinfo *key,
					      uint8 enum_only)
{
	struct pixel_pixinfo *fmt_found = NULL;
	int32 (*compar)(const void *pixfmt1, const void *pixfmt2);

	if (enum_only)
		compar = &pixel_compare_pixfmts;
	else
		compar = &pixel_compare_pixinfo;

	{
		uint32 i;

		for (i = 0; i < NUM_OF_FORMATS; i++) {
			if (compar(key, &pix_fmts[i]) == 0) {
				fmt_found = &pix_fmts[i];
				break;
			}
		}
	}
	return fmt_found;
}

/*
 * @brief Set a pixel format info structure to the default.
 * @warning This MODIDIFES the pointer therefore you shouldn't
 * call it on pointer you got from the library!
 */
static void pixel_pixinfo_defaults(struct pixel_pixinfo *to_def)
{
	if (!def_fmt)
		pixel_init_search();

	memcpy(to_def, def_fmt, sizeof(struct pixel_pixinfo));
}

enum img_pixfmt pixel_get_pixfmt(enum pixel_fmt_idc chroma_fmt_idc,
				 enum pixel_chroma_interleaved
					chroma_interleaved,
				 enum pixel_mem_packing mem_pkg,
				 uint32 bitdepth_y, uint32 bitdepth_c,
				 uint32 num_planes)
{
	uint32 internal_num_planes = (num_planes == 0 || num_planes > 4) ? 2 :
								num_planes;
	struct pixel_pixinfo key;
	struct pixel_pixinfo *fmt_found = NULL;

	if (chroma_fmt_idc != PIXEL_FORMAT_MONO &&
	    chroma_fmt_idc != PIXEL_FORMAT_411 &&
	    chroma_fmt_idc != PIXEL_FORMAT_420 &&
	    chroma_fmt_idc != PIXEL_FORMAT_422 &&
	    chroma_fmt_idc != PIXEL_FORMAT_444)
		return IMG_PIXFMT_UNDEFINED;

	/* valid bit depth 8, 9, 10, or 16/0 for 422 */
	if (bitdepth_y < 8 || bitdepth_y > 10)
		return IMG_PIXFMT_UNDEFINED;

	/* valid bit depth 8, 9, 10, or 16/0 for 422 */
	if (bitdepth_c < 8 || bitdepth_c > 10)
		return IMG_PIXFMT_UNDEFINED;

	key.pixfmt = IMG_PIXFMT_UNDEFINED;
	key.chroma_fmt_idc = chroma_fmt_idc;
	key.chroma_interleave = chroma_interleaved;
	key.mem_pkg = mem_pkg;
	key.bitdepth_y = bitdepth_y;
	key.bitdepth_c = bitdepth_c;
	key.num_planes = internal_num_planes;

	/*
	 * 9 and 10 bits formats are handled in the same way, and there is only
	 * one entry in the PixelFormat table
	 */
	if (key.bitdepth_y == 9)
		key.bitdepth_y = 10;

	/*
	 * 9 and 10 bits formats are handled in the same way, and there is only
	 * one entry in the PixelFormat table
	 */
	if (key.bitdepth_c == 9)
		key.bitdepth_c = 10;

	pixel_init_search();

	/* do not search by format */
	fmt_found = pixel_search_fmt(&key, osa_false);
	if (!fmt_found)
		return IMG_PIXFMT_UNDEFINED;

	return fmt_found->pixfmt;
}

static void pixel_get_internal_pixelinfo(struct pixel_pixinfo *pixinfo,
					struct pixel_info *pix_bufinfo)
{
	if (pixinfo->bitdepth_y == 8 && pixinfo->bitdepth_c == 8)
		pix_bufinfo->pixels_in_bop = 16;
	else if (pixinfo->mem_pkg == PIXEL_BIT10_MP)
		pix_bufinfo->pixels_in_bop = 12;
	else
		pix_bufinfo->pixels_in_bop = 8;

	if (pixinfo->bitdepth_y == 8)
		pix_bufinfo->ybytes_in_bop = pix_bufinfo->pixels_in_bop;
	else
		pix_bufinfo->ybytes_in_bop = 16;

	if (pixinfo->chroma_fmt_idc == PIXEL_FORMAT_MONO) {
		pix_bufinfo->uvbytes_in_bop = 0;
	} else if (pixinfo->bitdepth_c == 8) {
		pix_bufinfo->uvbytes_in_bop = pix_bufinfo->pixels_in_bop;
		if (pixinfo->chroma_fmt_idc == PIXEL_FORMAT_422 &&
		    pixinfo->num_planes == 1) {
			pix_bufinfo->uvbytes_in_bop = 0;
			pix_bufinfo->pixels_in_bop = 8;
		}
	} else {
		pix_bufinfo->uvbytes_in_bop = 16;
	}

	if (pixinfo->chroma_fmt_idc == PIXEL_FORMAT_444)
		pix_bufinfo->uvbytes_in_bop *= 2;

	if (pixinfo->chroma_interleave == PIXEL_INVALID_CI) {
		pix_bufinfo->uvbytes_in_bop /= 2;
		pix_bufinfo->vbytes_in_bop = pix_bufinfo->uvbytes_in_bop;
	} else {
		pix_bufinfo->vbytes_in_bop = 0;
	}

	pix_bufinfo->alphabytes_in_bop = 0;

	if (pixinfo->num_planes == 1)
		pix_bufinfo->is_planar = osa_false;
	else
		pix_bufinfo->is_planar = osa_true;

	if (pixinfo->chroma_fmt_idc == PIXEL_FORMAT_420)
		pix_bufinfo->uv_height_halved = osa_true;
	else
		pix_bufinfo->uv_height_halved = osa_false;

	if (pixinfo->chroma_fmt_idc == PIXEL_FORMAT_444)
		pix_bufinfo->uv_stride_ratio_times4 = 8;
	else
		pix_bufinfo->uv_stride_ratio_times4 = 4;

	if (pixinfo->chroma_interleave == PIXEL_INVALID_CI)
		pix_bufinfo->uv_stride_ratio_times4 /= 2;

	pix_bufinfo->has_alpha = osa_false;
}

static void pixel_yuv_get_descriptor_int(struct pixel_info *pixinfo,
					struct img_pixfmt_desc  *pix_desc)
{
	pix_desc->bop_denom = pixinfo->pixels_in_bop;
	pix_desc->h_denom = (pixinfo->uv_stride_ratio_times4 == 2 ||
					 !pixinfo->is_planar) ? 2 : 1;
	pix_desc->v_denom = (pixinfo->uv_height_halved || !pixinfo->is_planar)
						? 2 : 1;

	pix_desc->planes[0] = osa_true;
	pix_desc->bop_numer[0] = pixinfo->ybytes_in_bop;
	pix_desc->h_numer[0] = pix_desc->h_denom;
	pix_desc->v_numer[0] = pix_desc->v_denom;

	pix_desc->planes[1] = pixinfo->is_planar;
	pix_desc->bop_numer[1] = pixinfo->uvbytes_in_bop;
	pix_desc->h_numer[1] = (pix_desc->h_denom *
				pixinfo->uv_stride_ratio_times4) / 4;
	pix_desc->v_numer[1] = 1;

	pix_desc->planes[2] = (pixinfo->vbytes_in_bop > 0) ? osa_true : osa_false;
	pix_desc->bop_numer[2] = pixinfo->vbytes_in_bop;
	pix_desc->h_numer[2] = (pixinfo->vbytes_in_bop > 0) ? 1 : 0;
	pix_desc->v_numer[2] = (pixinfo->vbytes_in_bop > 0) ? 1 : 0;

	pix_desc->planes[3] = pixinfo->has_alpha;
	pix_desc->bop_numer[3] = pixinfo->alphabytes_in_bop;
	pix_desc->h_numer[3] = pix_desc->h_denom;
	pix_desc->v_numer[3] = pix_desc->v_denom;

	return;
}

int32 pixel_yuv_get_desc(struct pixel_pixinfo *pix_info,
		       struct img_pixfmt_desc *pix_desc)
{
	struct pixel_info  int_pix_info;

	struct pixel_info *int_pix_info_old = NULL;
	enum img_pixfmt pix_fmt = pixel_get_pixfmt(pix_info->chroma_fmt_idc,
						   pix_info->chroma_interleave,
						   pix_info->mem_pkg,
						   pix_info->bitdepth_y,
						   pix_info->bitdepth_c,
						   pix_info->num_planes);

	/* Validate the output from new function. */
	if (pix_fmt != IMG_PIXFMT_UNDEFINED)
		int_pix_info_old = pixel_get_bufinfo_from_pixfmt(pix_fmt);

	pixel_get_internal_pixelinfo(pix_info, &int_pix_info);

	if (int_pix_info_old) {
		VDEC_ASSERT(int_pix_info_old->has_alpha ==
			    int_pix_info.has_alpha);
		VDEC_ASSERT(int_pix_info_old->is_planar ==
			    int_pix_info.is_planar);
		VDEC_ASSERT(int_pix_info_old->uv_height_halved ==
			    int_pix_info.uv_height_halved);
		VDEC_ASSERT(int_pix_info_old->alphabytes_in_bop ==
			    int_pix_info.alphabytes_in_bop);
		VDEC_ASSERT(int_pix_info_old->pixels_in_bop ==
			    int_pix_info.pixels_in_bop);
		VDEC_ASSERT(int_pix_info_old->uvbytes_in_bop ==
			    int_pix_info.uvbytes_in_bop);
		VDEC_ASSERT(int_pix_info_old->uv_stride_ratio_times4 ==
			    int_pix_info.uv_stride_ratio_times4);
		VDEC_ASSERT(int_pix_info_old->vbytes_in_bop ==
			    int_pix_info.vbytes_in_bop);
		VDEC_ASSERT(int_pix_info_old->ybytes_in_bop ==
			    int_pix_info.ybytes_in_bop);
	}

	pixel_yuv_get_descriptor_int(&int_pix_info, pix_desc);

	return IMG_SUCCESS;
}

struct pixel_pixinfo *pixel_get_pixinfo(const enum img_pixfmt pix_fmt)
{
	struct pixel_pixinfo key;
	struct pixel_pixinfo *fmt_found = NULL;

	pixel_init_search();
	pixel_pixinfo_defaults(&key);
	key.pixfmt = pix_fmt;

	fmt_found = pixel_search_fmt(&key, osa_true);
	if (!fmt_found)
		return def_fmt;
	return fmt_found;
}

int32 pixel_get_fmt_desc(enum img_pixfmt pix_fmt,
		       struct img_pixfmt_desc *pix_desc)
{
	if (pix_fmt >= IMG_PIXFMT_ARBPLANAR8 &&
	    pix_fmt <= IMG_PIXFMT_ARBPLANAR8_LAST) {
		uint32 i;
		uint16 spec;

		pix_desc->bop_denom = 1;
		pix_desc->h_denom = 1;
		pix_desc->v_denom = 1;

		spec = (pix_fmt - IMG_PIXFMT_ARBPLANAR8) & 0xffff;
		for (i = 0; i < FACT_SPEC_FORMAT_NUM_PLANES; i++) {
			uint8 code = (spec >> FACT_SPEC_FORMAT_PLANE_CODE_BITS *
				   (FACT_SPEC_FORMAT_NUM_PLANES - 1 - i)) & 0xf;
			pix_desc->bop_numer[i] = 1;
			pix_desc->h_numer[i] = ((code >> 2) &
				FACT_SPEC_FORMAT_PLANE_CODE_MASK) +
				FACT_SPEC_FORMAT_MIN_FACT_VAL;
			pix_desc->v_numer[i] =
				(code & FACT_SPEC_FORMAT_PLANE_CODE_MASK) +
				FACT_SPEC_FORMAT_MIN_FACT_VAL;
			if (i == 0 || code != FACT_SPEC_FORMAT_PLANE_UNUSED) {
				pix_desc->planes[i] = osa_true;

				pix_desc->h_denom =
					pix_desc->h_denom > pix_desc->h_numer[i] ?
					pix_desc->h_denom : pix_desc->h_numer[i];

				pix_desc->v_denom =
					pix_desc->v_denom > pix_desc->v_numer[i] ?
					pix_desc->v_denom : pix_desc->v_numer[i];
			} else {
				pix_desc->planes[i] = osa_false;
			}
		}
	} else {
		struct pixel_info *info =
			pixel_get_bufinfo_from_pixfmt(pix_fmt);
		if(!info) {
			VDEC_ASSERT(0);
			return -OSA_EINVAL;
		}

		pixel_yuv_get_descriptor_int(info, pix_desc);
	}

	return IMG_SUCCESS;
}

int32 pixel_gen_pixfmt(enum img_pixfmt *pix_fmt, struct img_pixfmt_desc* pix_desc)
{
	uint16 spec = 0, i;
	uint8 code;

	for (i = 0; i < FACT_SPEC_FORMAT_NUM_PLANES; i++) {
		if (pix_desc->planes[i] != 1) {
			code = FACT_SPEC_FORMAT_PLANE_UNUSED;
		} else {
			code = (((pix_desc->h_numer[i] - FACT_SPEC_FORMAT_MIN_FACT_VAL) &
				FACT_SPEC_FORMAT_PLANE_CODE_MASK) << 2) |
				((pix_desc->v_numer[i] - FACT_SPEC_FORMAT_MIN_FACT_VAL) &
				FACT_SPEC_FORMAT_PLANE_CODE_MASK);
		}
		spec |= (code << FACT_SPEC_FORMAT_PLANE_CODE_BITS * (FACT_SPEC_FORMAT_NUM_PLANES - 1 - i));
	}

	*pix_fmt = (enum img_pixfmt)(IMG_PIXFMT_ARBPLANAR8 | spec);

	return 0;
}
