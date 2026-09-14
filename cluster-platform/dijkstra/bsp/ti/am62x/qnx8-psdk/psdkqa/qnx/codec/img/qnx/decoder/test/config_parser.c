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

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h> // calloc
#include <errno.h>
#include <sys/types.h>

#include <osa_define.h>

#include "config_parser.h"

#define BS_BYTE_READ(x)  ((((x))[0] << 24) | (((x))[1] << 16) | (((x))[2] <<  8) | ((x))[3])
#define SECOND_BYTE      0x8000000
#define BS_PART_READ( buffptr, retval, bytesleft ) do {             \
    int32_t remainShift = (4 - bytesleft) * 8; \
	while (bytesleft > 0) { \
		retval <<= 8; \
		retval |= *buffptr; \
		buffptr++; \
		bytesleft--; \
	} \
	retval <<= remainShift; \
} while( 0 )

static inline int32_t mmf_log2(uint32_t v)
{
	int32_t log2 = 0;
	int32_t i;

	for (i = 31; i >= 0; i--) {
		if (v >> i) {
			log2 = i;
			break;
		}
	}
	return log2;
}


// The following tables are required to parse the AVCC SPS block to retrieve height and
// width for H.264 streams.
static const uint8_t vlc_len[512]={
14,13,12,12,11,11,11,11,10,10,10,10,10,10,10,10,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,7,7,7,7,7,7,7,
7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1};

static const uint8_t golomb_vals[512]={
31,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,
7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,11,11,11,11,12,12,12,12,13,13,13,13,14,14,14,14,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,
6,6,6,6,6,6,6,6,6,6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0};

static const int8_t signed_golomb_vals[512]={
16,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,8,-8,9,-9,10,-10,11,-11,12,-12,13,-13,14,-14,15,
-15,4,4,4,4,-4,-4,-4,-4,5,5,5,5,-5,-5,-5,-5,6,6,6,6,-6,-6,-6,-6,7,7,7,7,-7,-7,-7,-7,2,2,2,2,2,2,
2,2,2,2,2,2,2,2,2,2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0};

typedef struct {
	const uint8_t       *buff;
	uint32_t            buff_size;
	int                 bit_offset;
} psbitstream_t;


static inline uint32_t mmf_bitstremgetbit(psbitstream_t *s){
	int32_t byte    = s->bit_offset / 8;
	uint8_t result;

	if (byte >= (int32_t)s->buff_size) {
		return 0;
	}
	result  = s->buff[ byte ];
	result <<= (s->bit_offset & 0x07);
	result >>= 7;
	s->bit_offset++;

	return result;
}

// This is lazy, but we're not worried about performance.
static inline uint32_t mmf_bitstremgetbits(psbitstream_t *s, int n){
	int32_t  i;
	uint32_t retval = 0;

	if (s->bit_offset/8 >= (int32_t)s->buff_size) {
		return 0;
	}

	n--;
	for (i = 0; i < n ; i++) {
		retval |= mmf_bitstremgetbit(s);
		retval <<= 1;
	}
	retval |= mmf_bitstremgetbit(s);

	return retval;
}

//
// These are exp golomb code reading funcs. Required for AVC/ H.264
//
static int32_t mmf_golombunsigned(psbitstream_t *psb) {
	uint32_t retval = 0;
	int32_t  byte = psb->bit_offset / 8;
	int32_t  log;
	int32_t  bytesleft = psb->buff_size - byte;

	if (psb->bit_offset/8 >= (int32_t)psb->buff_size) {
		return 0;
	}

	if (bytesleft >= 4) {
		retval = BS_BYTE_READ( &psb->buff[byte] );
	} else {
		uint8_t *buffptr = (uint8_t*)&psb->buff[byte];
		BS_PART_READ( buffptr, retval, bytesleft );
	}

	retval <<= (psb->bit_offset & 0x07);

	if( retval >= SECOND_BYTE ) {
		retval >>= 23;
		psb->bit_offset += vlc_len[retval];

		return golomb_vals[retval];
	}
	log = 2 * mmf_log2(retval) - 31;
	psb->bit_offset += 32 - log;

	retval >>= log;
	retval--;
	return retval;
}

static int32_t mmf_golombconstrained(psbitstream_t *psb) {
	uint32_t retval = 0;
	int32_t  byte = psb->bit_offset / 8;
	int32_t  bytesleft = psb->buff_size - byte;

	if (psb->bit_offset/8 >= (int32_t)psb->buff_size) {
		return 0;
	}

	if (bytesleft >= 4) {
		retval = BS_BYTE_READ( &psb->buff[byte] );
	} else {
		uint8_t *buffptr = (uint8_t*)&psb->buff[byte];
		BS_PART_READ( buffptr, retval, bytesleft );
	}
	retval <<= (psb->bit_offset & 0x07);
	retval >>= 23;
	psb->bit_offset += vlc_len[retval];

	return golomb_vals[retval];
}

static int32_t mmf_golombsigned(psbitstream_t *psb) {
	int32_t  retval = 0;
	uint32_t codenum = 0;
	int32_t  byte = psb->bit_offset / 8;
	int32_t  log;
	int32_t  bytesleft = psb->buff_size - byte;

	if (psb->bit_offset/8 >= (int32_t)psb->buff_size) {
		return 0;
	}

	if (bytesleft >= 4) {
		codenum = BS_BYTE_READ( &psb->buff[byte] );
	} else {
		uint8_t *buffptr = (uint8_t*)&psb->buff[byte];
		BS_PART_READ( buffptr, codenum, bytesleft );
	}
	codenum <<= (psb->bit_offset & 0x07);

	if(codenum >= SECOND_BYTE){
		codenum >>= 23;
		psb->bit_offset += vlc_len[codenum];

		return signed_golomb_vals[codenum];
	}
	log = 2 * mmf_log2(codenum) - 31;
	psb->bit_offset += 32 - log;

	codenum >>= log;
	if (codenum & 0x00001) {
		retval = -((int32_t)(codenum>>1));
	} else {
		retval =  (codenum>>1);
	}

	return retval;

}


static void skip_list(psbitstream_t *psb, int size) {
	// We only worry about it if the presence bit says it's there.
	if(mmf_bitstremgetbit(psb)) {
		int32_t       val;
		int32_t       i;

		val = 8;
		for(i = 0; i < size; i++) {
			if (val) {
				val = (val + mmf_golombsigned(psb)) & 0xff;
			}
			// If it's not there
			if(!i && !val){
				break;
			}
		}
	}
}


//
// H.264/AVC Config Parsing.
//
#define H264_CUSTOM_ASPECT_RATIO     255
static const uint8_t h264_aspec_ratio_from_idc[14][2] = {
		{1, 1},
		{1, 1},
		{12, 11},
		{10, 11},
		{16, 11},
		{40, 33},
		{24, 11},
		{20, 11},
		{32, 11},
		{80, 33},
		{18, 11},
		{15, 11},
		{64, 33},
		{160, 99}
};


static int h264_parse_sps(const uint8_t *rawps, uint32_t pslen, decoder_info_t *info, avc1_decoder_specific_t *avc1) {
	psbitstream_t   psb;
	int32_t         profile;
	int32_t         poc_type;
	int32_t         i;
	int32_t         ar_idc;

	// Just in case there is no aspect ratio information in the SPS.
	info->par_x = 1;
	info->par_y = 1;
	info->width = 0;
	info->height = 0;

	// Turn our buffer into a bitstream.
	psb.bit_offset = 0;
	psb.buff_size = pslen;
	psb.buff = rawps;

	profile = mmf_bitstremgetbits(&psb, 8);
	avc1->profile_indication    = profile;
	avc1->profile_compatibility = mmf_bitstremgetbits(&psb, 8);
	avc1->level_indication      = mmf_bitstremgetbits(&psb, 8);

	if(mmf_golombconstrained(&psb) >= 32) {
		return -1;
	}

	// More to do for high profile or better.
	if (profile >= 100) {

		avc1->chroma_format_idc = mmf_golombconstrained(&psb);
		if (avc1->chroma_format_idc == 3)
			mmf_bitstremgetbit(&psb);

		mmf_golombunsigned(&psb);
		mmf_golombunsigned(&psb);
		mmf_bitstremgetbit(&psb);

		if (mmf_bitstremgetbit(&psb)) {
			for (i = 0; i < 6; i++) {
				skip_list(&psb, 16);
			}
			for (i = 0; i < 2; i++) {
				skip_list(&psb, 64);
			}
		}
	}

	mmf_golombunsigned(&psb);
	poc_type = mmf_golombconstrained(&psb);

	if (poc_type == 0) {
		mmf_golombunsigned(&psb);
	} else if (poc_type == 1) {
		int32_t cycle_len;

		mmf_bitstremgetbit(&psb);
		mmf_golombsigned(&psb);
		mmf_golombsigned(&psb);
		cycle_len = mmf_golombunsigned(&psb);

		for(i = 0; i < cycle_len; i++)
			mmf_golombsigned(&psb);
	}

	avc1->num_ref_frames =  mmf_golombconstrained(&psb);
	mmf_bitstremgetbit(&psb);

	// Store the width and height
	info->width = (mmf_golombunsigned(&psb) + 1) * 16;
	info->height = (mmf_golombunsigned(&psb) + 1) * 16;

	// Mine for aspect ratio info.
	// frame mbs only flag
	if(mmf_bitstremgetbit(&psb) == 0) {
		avc1->frame_mbs_only_flag = 0;
		//mb_adaptive_frame_field_flag
		mmf_bitstremgetbit(&psb);
	} else {
		avc1->frame_mbs_only_flag = 1;
	}
	//direct_8x8_inference_flag
	mmf_bitstremgetbit(&psb);
	//frame_cropping_flag
	if(mmf_bitstremgetbit(&psb)) {
		int vsub   = (avc1->chroma_format_idc == 1) ? 1 : 0;
		int hsub   = (avc1->chroma_format_idc == 1 || avc1->chroma_format_idc == 2) ? 1 : 0;
		int step_x = 1 << hsub;
		int step_y = (2 - avc1->frame_mbs_only_flag) << vsub;

		// frame_crop_left_offset
		unsigned int crop_left = mmf_golombunsigned(&psb);
		//frame_crop_right_offset
		unsigned int crop_right = mmf_golombunsigned(&psb);
		//frame_crop_top_offset
		unsigned int crop_top = mmf_golombunsigned(&psb);
		//frame_crop_bottom_offset
		unsigned int crop_bottom = mmf_golombunsigned(&psb);

		if (crop_left  > (unsigned)INT32_MAX / 4 / step_x ||
				crop_right > (unsigned)INT32_MAX / 4 / step_x ||
				crop_top   > (unsigned)INT32_MAX / 4 / step_y ||
				crop_bottom> (unsigned)INT32_MAX / 4 / step_y ||
				(crop_left + crop_right ) * step_x >= (uint32_t)info->width ||
				(crop_top  + crop_bottom) * step_y >= (uint32_t)info->height
				) {
			OSA_PR_ERR("crop values invalid %d %d %d %d / %d %d\n", crop_left, crop_right, crop_top, crop_bottom, info->width, info->height);
			avc1->cropping.crop_left = 0;
			avc1->cropping.crop_right = 0;
			avc1->cropping.crop_top = 0;
			avc1->cropping.crop_bottom = 0;
		} else {
			avc1->cropping.crop_left   = crop_left   * step_x;
			avc1->cropping.crop_right  = crop_right  * step_x;
			avc1->cropping.crop_top   = crop_top    * step_y;
			avc1->cropping.crop_bottom= crop_bottom * step_y;
		}
	}

	// VUI Parameters Flags -- Aspect ratio is here.
	if(mmf_bitstremgetbit(&psb)) {
		OSA_PR_DEBUG("VUI Parameters present");
		//aspect_ratio_info_present_flag
		if (mmf_bitstremgetbit(&psb)) {
			OSA_PR_DEBUG("aspect ratio present");
			ar_idc = mmf_bitstremgetbits(&psb, 8);
			OSA_PR_DEBUG("    ar_idc = %d", ar_idc);
			if (ar_idc == H264_CUSTOM_ASPECT_RATIO) {
				info->par_x = mmf_bitstremgetbits(&psb, 16);
				info->par_y = mmf_bitstremgetbits(&psb, 16);
				OSA_PR_DEBUG("    sar x = %d, sar y = %d.", info->par_x, info->par_y);
			} else {
				if (ar_idc < 14) {
					// Interpret the pre-defined field.
					info->par_x = h264_aspec_ratio_from_idc[ar_idc][0];
					info->par_y = h264_aspec_ratio_from_idc[ar_idc][1];
				}
			}
			// By spec. if par x or par y are 0, par is unspecified.  So back to 1:1
			if (info->par_x == 0 || info->par_y == 0) {
				OSA_PR_DEBUG("    Undefined aspect ratio.");
				info->par_x = 1;
				info->par_y = 1;
			}
		}

		//overscan_info_present_flag
		if (mmf_bitstremgetbit(&psb)) {
			mmf_bitstremgetbit(&psb);
		}

		//video_signal_type_present_flag
		if (mmf_bitstremgetbit(&psb)) {
			mmf_bitstremgetbits(&psb, 3);
			avc1->video_full_range_flag = mmf_bitstremgetbit(&psb);
			//colour_description_present_flag
			if (mmf_bitstremgetbit(&psb)) {
				mmf_bitstremgetbits(&psb, 24);
			}
		}

		//chroma_loc_info_present_flag
		if (mmf_bitstremgetbit(&psb)) {
			mmf_golombunsigned(&psb);
			mmf_golombunsigned(&psb);
		}

		//timing_info_present_flag
		if (mmf_bitstremgetbit(&psb)) {
			info->num_units_in_tick = mmf_bitstremgetbits(&psb, 32);
			info->time_scale = mmf_bitstremgetbits(&psb, 32);
			info->fixed_frame_rate_flag = mmf_bitstremgetbit(&psb);
		}


	}

	return EOK;
}

// cleanup the avc configuration object
static void h264_free_decoder_specific( avc1_decoder_specific_t* avcc )
{
	int32_t i;
	if (avcc) {
		for( i = 0; i < avcc->sps_count; i++ ) {
			free(avcc->sps[i].string);
			free(avcc->sps[i].nalu);
		}
		free(avcc->sps);
		free(avcc->sps_info);
		for( i = 0; i < avcc->pps_count; i++ ) {
			free(avcc->pps[i].string);
			free(avcc->pps[i].nalu);
		}
		free(avcc->pps);
		free(avcc);
	}
}


int32_t h264_parse_decoder_config(const uint8_t* raw_avcc, uint32_t avcc_size, decoder_info_t *info_out, avc1_decoder_specific_t** avcc_out)
{
    int32_t i;
    avc1_decoder_specific_t *avcc;
    uint8_t *buf;
    int32_t offsetSps;
    int32_t offsetPps;
    uint8_t nalType;
    uint32_t size;

    if (avcc_size < 9) {
        return ENOTSUP;
    }

    // Search for SPS and PPS
    offsetSps = offsetPps = -1;
    for (i = 0; i < (int32_t)avcc_size - 4; i++) {
        // First byte is a don't care, but must be present.
        if (raw_avcc[i] == 0 && raw_avcc[i+1] == 0 && raw_avcc[i+2] == 1) {
            nalType = raw_avcc[i+3] & 0x1F;
            if (nalType == 7) {
                OSA_PR_DEBUG("Found SPS at offset %d", i);
                offsetSps = i;
            }
            if (nalType == 8) {
                OSA_PR_DEBUG("Found PPS at offset %d", i);
                offsetPps = i;
            }
        }
        if ((offsetSps != -1) && (offsetPps != -1)) {
            break;
        }
    }

    if (offsetSps < 0) {
        OSA_PR_DEBUG("No SPS" );
        return ENOTSUP;
    }
    if (offsetPps < 0) {
        OSA_PR_DEBUG("No PPS" );
        return ENOTSUP;
    }

    if ((avcc = (avc1_decoder_specific_t *)calloc(1, sizeof(avc1_decoder_specific_t))) == NULL) {
        return ENOMEM;
    }

    avcc->sps_count             = 1;
    avcc->sps                   = (avc1_param_set_t*)calloc(1, sizeof(avc1_param_set_t));
    avcc->sps_info              = (decoder_info_t*)calloc(1, sizeof(decoder_info_t));
    if (!avcc->sps || !avcc->sps_info )
    {
        h264_free_decoder_specific(avcc);
        return ENOMEM;
    }

    // Parse required info out of the SPS.
    // Start parsing SPS header
    buf =  (uint8_t *)raw_avcc + offsetSps + 4;
    size = avcc_size - (offsetSps + 4);
    if (size < 2) {
        h264_free_decoder_specific(avcc);
        return ENOTSUP;
    }

    h264_parse_sps(buf, size, &avcc->sps_info[0], avcc);

    avcc->pps_count             = 1;
    avcc->pps                   = (avc1_param_set_t*)calloc(1, sizeof(avc1_param_set_t)*avcc->pps_count);

    // For h.264 there can be multiple param sets, for now take the first.
    // we are returning all of them, so a parser can choose the appropriate one.
    if (info_out) {
        *info_out = avcc->sps_info[0];
    }

    if (avcc_out) {
        *avcc_out = avcc;
    } else {
        h264_free_decoder_specific(avcc);
    }
    return EOK;
}
