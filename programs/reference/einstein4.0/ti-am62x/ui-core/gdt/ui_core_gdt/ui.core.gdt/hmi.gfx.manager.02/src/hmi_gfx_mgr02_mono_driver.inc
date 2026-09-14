#if defined(GFX_MGR02_MONOTFT)
#if defined(GFX_TEXT_ON_GREY)    
SINT8 fl_factor_SU8 = 0;
#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_2BPP)
#define GET_TEXT_CORRECTION_FACTOR(draw_colour, bg_colour)    1 + (draw_colour - bg_colour) 
#define CLAMP_TEXT_CORRECTION_FACTOR(factor)                 ((factor) > 2 ? (2) :(factor))                                                                   
#elif(GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP)
#define GET_TEXT_CORRECTION_FACTOR(draw_colour, bg_colour)    7 + (draw_colour - bg_colour) 
#define CLAMP_TEXT_CORRECTION_FACTOR(factor)                 ((factor) > 14 ? (14) :(factor))                                                                   
#endif
#endif
UINT16 fl_cwidth_U16;
UINT8  fl_tempbmpdata_U8;
UINT16 fl_tempcopy_U16;
UINT16 fl_copy_rem_U16 = 0;
UINT16 fl_copy_sindex_U16 = p_clip_start;
UINT16 fl_copy_width_U16 = p_clip_length;
UINT16 fl_copy_y_U16 = 0;
UINT16 fl_copy_height_U16 = height;
SINT16 fl_actual_start_pos = 0;

#if GFX_MGR02_HOR_PACKING > 0
 if(p_clip_start > 0)
 {
   /* This means text scroll is going on,
   ** So take the actual characer position.
   ** current x position - scroll offset gives
   ** original position.
   */
   fl_actual_start_pos = x - p_clip_start;
 }
 else
 {
   fl_actual_start_pos = x;
 }
#else
fl_actual_start_pos = y;
#endif

#if 0
x += l_element_offset_x_S32;
y += l_element_offset_y_S32;
x += l_widget_offset_x_S32;
y += l_widget_offset_y_S32;
#endif

#ifdef GFX_COMPILE_SPEED_OPTIMIZE   
GfxDriverClipCalculate(x, y, fl_copy_sindex_U16, fl_copy_y_U16, fl_copy_width_U16, fl_copy_height_U16, width, height);
#else
GfxDriverClipCalculate(&x, &y, &fl_copy_sindex_U16, &fl_copy_y_U16, &fl_copy_width_U16, &fl_copy_height_U16, width, height);
#endif        

if ((height != 0) &&
	(width != 0) &&
	(fl_copy_width_U16 > 0) &&
	(fl_copy_height_U16 > 0) &&
	(alpha > 0) &&
	(fl_copy_sindex_U16 < width) &&
	(fl_copy_width_U16 <= (width - fl_copy_sindex_U16)) &&
	(fl_copy_y_U16 < height) &&
	(fl_copy_height_U16 <= (height - fl_copy_y_U16)) &&
	((y + fl_copy_height_U16) <= lc_layer_def_S[layer].area.height) &&
	((x + fl_copy_width_U16) <= lc_layer_def_S[layer].area.width))
{
	GFX_MGR02_COLOR * fl_fb_U8AP;
	GFX_MGR02_COLOR * fl_temp_fb_U8AP;
	UINT8         fl_start_offset_U8;
	UINT8         fl_end_offset_U8;
	UINT8         fl_fb_mask_U8;
	UINT8         fl_end_mask_U8;
	UINT8         fl_start_mask_U8;
	UINT8         fl_bmp_data_mask_U8 = 0;
	UINT8         fl_data_U8;
	UINT16        fl_nb_lines_U16;
	UINT8         fl_start_height_U8;
	UINT16        fl_count_U16;
	UINT8         fl_bmp_data_U8;

#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_2BPP)||(GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP)
#if (defined(GFX_TEXT_ON_GREY)|| defined(GFX_IMAGE_BLEND_USING_ARRAY)|| defined(GFX_IMAGE_BLEND_USING_FORMULA))
	UINT8 fl_temp_fb_data_U8;
#endif
#endif
#if ((defined(GFX_TRANSPARENT)) ||(defined(GFX_TEXT_ON_GREY)|| ( (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP) && (defined(GFX_IMAGE_BLEND_USING_ARRAY)|| defined(GFX_IMAGE_BLEND_USING_FORMULA)))) )                 
	UINT8 fl_fb_byte_U8 = 0;
#endif
#if defined(GFX_TEXT_ON_GREY)|| defined(GFX_IMAGE_BLEND_USING_FORMULA)
#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_2BPP)
	UINT8 fl_division_factor_U8 = 0x03;
#elif(GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP)
	UINT8 fl_division_factor_U8 = 15;
#endif
#endif



	UINT8 fl_cnt_U8 = 0;
	UINT8 fl_tempshift_U8 = 0;
	UINT8 fl_tempdata_U8 = 0;
	UINT8 fl_initialcnt_U8 = 0;
	UINT8 fl_finalcnt_U8 = 0;
	UINT8 fl_is_transparent = 0;
	UINT8 fl_is_text_on_grey = 0;
	UINT8 fl_image_blend = 0;
#if defined(GFX_TRANSPARENT)
	UINT8 fl_imgpixel_data_U8 = 0;
#endif
#if defined(GFX_TEXT_ON_GREY)      
	UINT8 fl_drawcolour_U8 = drawcolour;
#endif        



#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_1BPP)
	UINT8 fl_shiftbits_U8 = 0x1;
	UINT8 fl_shiftcnt_U8 = 0x8;
	UINT8 fl_maskbits_U8 = 0x1;
#elif (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_2BPP)
	UINT8 fl_shiftbits_U8 = 0x2;
	UINT8 fl_shiftcnt_U8 = 0x4;
	UINT8 fl_maskbits_U8 = 0x3;
#else
	UINT8 fl_shiftbits_U8 = 0x4;
	UINT8 fl_shiftcnt_U8 = 0x2;
	UINT8 fl_maskbits_U8 = 0xF;
#endif



#ifdef GFX_RLE_SUPPORT
	UINT8         p_width = 0;
	UINT16        fl_data_count_U16 = 0;
#ifdef GFX_COMPILE_SPEED_OPTIMIZE
	UINT8  const * fl_rle_cur_bmp_data = 0;
	UINT8 fl_rle_cur_count = 0;
	UINT8 fl_rle_cur_flag = 0;
	UINT8 fl_rle_cur_data = 0;

	UINT8 const * fl_rle_nln_bmp_data = 0;
	UINT8 fl_rle_nln_count = 0;
	UINT8 fl_rle_nln_flag = 0;
	UINT8 fl_rle_nln_data = 0;
	UINT16 fl_width = 0;

	UINT8 const * fl_rle_clip_bmp_data = 0;
	UINT8 fl_rle_clip_count = 0;
	UINT8 fl_rle_clip_flag = 0;
	UINT8 fl_rle_clip_data = 0;

#else  
	GFX_ONLINE_RLE fl_rle_cur;
	GFX_ONLINE_RLE fl_rle_nln;
	GFX_ONLINE_RLE fl_rle_clip;
#endif      

#endif

#if defined(GFX_TRANSPARENT)
	fl_is_transparent = YES;
#endif


#if defined(GFX_IMAGE_BLEND_USING_ARRAY) || defined(GFX_IMAGE_BLEND_USING_FORMULA)
	fl_image_blend = YES;
#endif   

#if defined(GFX_TEXT_ON_GREY)
	fl_is_text_on_grey = YES;
#endif   

	if (alpha > 0)
	{
		alpha = alpha >> GFX_MGR02_PIX_ALPHA_SHFT;
	}

#if defined(GFX_LAYER_XY_OFFSET_ENABLED)
	x = x + GFX_LAYER_X_OFFSET;
	y = y + GFX_LAYER_Y_OFFSET;
#endif

#if GFX_MGR02_HOR_PACKING > 0
	fl_count_U16 = x;
	x = y;
	y = fl_count_U16;
	fl_count_U16 = width;
	width = height;
	height = fl_count_U16;
	fl_count_U16 = fl_copy_sindex_U16;
	fl_copy_sindex_U16 = fl_copy_y_U16;
	fl_copy_y_U16 = fl_count_U16;
	fl_count_U16 = height;
	height = fl_copy_width_U16;
	fl_copy_width_U16 = fl_copy_height_U16;
#else
	height = fl_copy_height_U16;
#endif

#ifdef GFX_RLE_SUPPORT   
	FL_RLE_CUR_COUNT = 0;
	FL_RLE_CUR_BMP_DATA = bmp_data;
	if (fl_copy_sindex_U16 != 0)
	{
#ifdef GFX_COMPILE_SPEED_OPTIMIZE
		fl_width = fl_copy_sindex_U16;
		GfxDriverRLEonlineNLine(fl_rle_cur_bmp_data, fl_rle_cur_count, fl_rle_cur_flag, fl_rle_cur_data, fl_width);
#else
		GfxDriverRLEonlineNLine(&fl_rle_cur, fl_copy_sindex_U16);
#endif
	}
	if (fl_copy_y_U16 != 0)
	{
		fl_copy_y_U16 = fl_copy_y_U16 << LCD_SIZE_MUL_FACTOR;
		fl_copy_rem_U16 = SOFFS(fl_copy_y_U16);
		fl_copy_y_U16 = NLINES(fl_copy_y_U16);
		fl_copy_y_U16 = fl_copy_y_U16 * width;
#ifdef GFX_COMPILE_SPEED_OPTIMIZE
		fl_width = fl_copy_y_U16;
		GfxDriverRLEonlineNLine(fl_rle_cur_bmp_data, fl_rle_cur_count, fl_rle_cur_flag, fl_rle_cur_data, fl_width);
#else
		GfxDriverRLEonlineNLine(&fl_rle_cur, fl_copy_y_U16);
#endif
	}
#endif   

#if LCD_SIZE_MUL_FACTOR > 0
	y <<= LCD_SIZE_MUL_FACTOR;
	height <<= LCD_SIZE_MUL_FACTOR;
	fl_copy_y_U16 <<= LCD_SIZE_MUL_FACTOR;
#if GFX_MGR02_HOR_PACKING > 0
	fl_count_U16 <<= LCD_SIZE_MUL_FACTOR;
#endif
#endif

	fl_start_offset_U8 = SOFFS(y);
	fl_temp_fb_U8AP = fb_data_ptr;
	fl_fb_U8AP = GET_FBP(fl_temp_fb_U8AP, x, y, layer);

	if ((fl_start_offset_U8 + height) >= 8)
	{
		if (fl_start_offset_U8 == 0)
		{
			/*
			** Bitmap is aligned to byte boundary.
			*/
			fl_nb_lines_U16 = NLINES(height);
			while (fl_nb_lines_U16 != 0)
			{
				fl_cwidth_U16 = fl_copy_width_U16;
#ifndef GFX_RLE_SUPPORT
				if (fl_copy_sindex_U16 != 0)
				{
					bmp_data = &bmp_data[fl_copy_sindex_U16];
				}
				if (fl_copy_y_U16 != 0)
				{
					fl_copy_rem_U16 = SOFFS(fl_copy_y_U16);
					fl_copy_y_U16 = NLINES(fl_copy_y_U16);
					fl_copy_y_U16 = fl_copy_y_U16 * width;
					bmp_data = &bmp_data[fl_copy_y_U16];
				}
#endif
				for (fl_count_U16 = 0; fl_count_U16 < fl_cwidth_U16; fl_count_U16++)
				{
#ifndef GFX_RLE_SUPPORT
					IMG_PR_OP(fl_bmp_data_U8, *bmp_data);
					if (fl_copy_rem_U16 != 0)
					{
						IMG_PR_OP(fl_bmp_data_U8, *bmp_data);
						fl_data_U8 = SR(fl_bmp_data_U8, fl_copy_rem_U16);
						IMG_PR_OP(fl_bmp_data_U8, bmp_data[width]);
						fl_data_U8 += SL(fl_bmp_data_U8, fl_copy_rem_U16);
						IMG_PR_OP(fl_bmp_data_U8, fl_data_U8);
					}
					fl_copy_y_U16 = 0;
					bmp_data++;
#else
					if (FL_RLE_CUR_COUNT == 0)
					{
#ifdef GFX_COMPILE_SPEED_OPTIMIZE
						GfxDriverRLEonline(fl_rle_cur_bmp_data, fl_rle_cur_count, fl_rle_cur_flag, fl_rle_cur_data);
#else
						GfxDriverRLEonline(&fl_rle_cur);
#endif
					}
					FL_RLE_CLIP_FLAG = FL_RLE_CUR_FLAG;
					FL_RLE_CLIP_COUNT = FL_RLE_CUR_COUNT;
					FL_RLE_CLIP_BMP_DATA = FL_RLE_CUR_BMP_DATA;
					FL_RLE_CLIP_DATA = FL_RLE_CUR_DATA;
					FL_RLE_CUR_COUNT--;
					if (FL_RLE_CUR_FLAG == FALSE)
					{
						IMG_PR_OP(fl_bmp_data_U8, *FL_RLE_CUR_BMP_DATA++);
					}
					else
					{
						IMG_PR_OP(fl_bmp_data_U8, FL_RLE_CUR_DATA);
					}
					fl_data_count_U16++;
					if (fl_copy_rem_U16 != 0)
					{
						fl_data_U8 = SR(fl_bmp_data_U8, fl_copy_rem_U16);
#ifdef GFX_COMPILE_SPEED_OPTIMIZE
						fl_width = width;
						GfxDriverRLEonlineNLine(fl_rle_clip_bmp_data, fl_rle_clip_count, fl_rle_clip_flag, fl_rle_clip_data, fl_width);
#else
						GfxDriverRLEonlineNLine(&fl_rle_clip, width);
#endif
						if ((FL_RLE_CLIP_COUNT == 0))
						{
#ifdef GFX_COMPILE_SPEED_OPTIMIZE
							GfxDriverRLEonline(fl_rle_clip_bmp_data, fl_rle_clip_count, fl_rle_clip_flag, fl_rle_clip_data);
#else
							GfxDriverRLEonline(&fl_rle_clip);
#endif
						}
						FL_RLE_CLIP_COUNT--;
						if (FL_RLE_CLIP_FLAG == FALSE)
						{
							IMG_PR_OP(fl_bmp_data_U8, *FL_RLE_CLIP_BMP_DATA++);
						}
						else
						{
							IMG_PR_OP(fl_bmp_data_U8, FL_RLE_CLIP_DATA);
						}
						fl_data_U8 += SL(fl_bmp_data_U8, fl_copy_rem_U16);
						IMG_PR_OP(fl_bmp_data_U8, fl_data_U8);
					}
					/* When the image data is clipped then rle data of the */
					/* image also need to be considered for the actual width only */
					if ((fl_data_count_U16 == fl_cwidth_U16) && (width > fl_cwidth_U16))
					{
						p_width = width - fl_cwidth_U16;
#ifdef GFX_COMPILE_SPEED_OPTIMIZE
						fl_width = p_width;
						GfxDriverRLEonlineNLine(fl_rle_cur_bmp_data, fl_rle_cur_count, fl_rle_cur_flag, fl_rle_cur_data, fl_width);
#else
						GfxDriverRLEonlineNLine(&fl_rle_cur, p_width);
#endif
						fl_data_count_U16 = 0;
					}
#endif  /* GFX_RLE_SUPPORT */
					if (alpha > 0)
					{
						if ((alpha != GFX_MGR02_PIX_FORMAT_ALPHA) || (fl_is_text_on_grey == YES) || (fl_is_transparent == YES) || (fl_image_blend == YES))
							/* Enable the below macro if further improvement in rendering is required.*/
#if 0 /*GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP*/
							fl_tempdata_U8 = PMSK(fl_bmp_data_U8);
						fl_data_U8 = 0;
						fl_fb_byte_U8 = FB(fl_fb_U8AP, fl_count_U16, layer);
#if (defined(GFX_TRANSPARENT))                    
						if (fl_tempdata_U8 != trans_color)
						{
							fl_bmp_data_U8 = fl_tempdata_U8;
						}
						else
						{
							fl_bmp_data_U8 = 0;
						}
#elif defined(GFX_TEXT_ON_GREY)
						fl_temp_fb_data_U8 = PMSK(fl_fb_byte_U8);
						fl_factor_SU8 = GET_TEXT_CORRECTION_FACTOR(fl_drawcolour_U8, fl_temp_fb_data_U8);
						fl_factor_SU8 = CLAMP_TEXT_CORRECTION_FACTOR(fl_factor_SU8);
						fl_data_U8 = fl_temp_fb_data_U8 + (((fl_tempdata_U8 * (fl_drawcolour_U8 - fl_temp_fb_data_U8)) + fl_factor_SU8) / fl_division_factor_U8);
#elif defined(GFX_IMAGE_BLEND_USING_ARRAY)
						fl_temp_fb_data_U8 = (PMSK(fl_fb_byte_U8) << 4);
						fl_temp_fb_data_U8 |= fl_tempdata_U8;
						if (fl_temp_fb_data_U8 <= 15)
						{
							fl_data_U8 = fl_temp_fb_data_U8;
						}
						else if (fl_temp_fb_data_U8 >= 232)
						{
							fl_data_U8 = 15;
						}
						else
						{
							fl_data_U8 = (l_alpha_blend[fl_temp_fb_data_U8]);
						}
#elif defined(GFX_IMAGE_BLEND_USING_FORMULA)
						fl_temp_fb_data_U8 = PMSK(fl_fb_byte_U8);
						fl_data_U8 = fl_tempdata_U8 + (((fl_temp_fb_data_U8 * fl_division_factor_U8) - (fl_temp_fb_data_U8 * fl_tempdata_U8)) / fl_division_factor_U8);
#endif
						/* for Left nibble */
						fl_tempdata_U8 = ((fl_bmp_data_U8 >> (LCD_SIZE_MUL_FACTOR << 1)));
#if(defined(GFX_TRANSPARENT))                 
						if (fl_tempdata_U8 != trans_color)
						{
							fl_data_U8 |= (fl_tempdata_U8 << (LCD_SIZE_MUL_FACTOR << 1));
						}
						if (fl_bmp_data_U8 == 0)
						{
							/*skip this pixel pair*/
							continue;
						}
#elif defined(GFX_TEXT_ON_GREY)
						fl_temp_fb_data_U8 = (fl_fb_byte_U8 >> (LCD_SIZE_MUL_FACTOR << 1));
						fl_factor_SU8 = GET_TEXT_CORRECTION_FACTOR(fl_drawcolour_U8, fl_temp_fb_data_U8);
						fl_factor_SU8 = CLAMP_TEXT_CORRECTION_FACTOR(fl_factor_SU8);
						fl_temp_fb_data_U8 = fl_temp_fb_data_U8 + (((fl_tempdata_U8 * (fl_drawcolour_U8 - fl_temp_fb_data_U8)) + fl_factor_SU8) / fl_division_factor_U8);
						fl_data_U8 |= (fl_temp_fb_data_U8 << (LCD_SIZE_MUL_FACTOR << 1));
#elif defined(GFX_IMAGE_BLEND_USING_ARRAY)
						fl_temp_fb_data_U8 = (fl_fb_byte_U8 & BMASKL);
						fl_temp_fb_data_U8 |= fl_tempdata_U8;
						if (fl_temp_fb_data_U8 <= 15)
						{
							fl_data_U8 |= (fl_temp_fb_data_U8 << (LCD_SIZE_MUL_FACTOR << 1));
						}
						else if (fl_temp_fb_data_U8 >= 232)
						{
							fl_data_U8 |= 0xF0;
						}
						else
						{
							fl_data_U8 |= (l_alpha_blend[fl_temp_fb_data_U8] << (LCD_SIZE_MUL_FACTOR << 1));
						}
#elif defined(GFX_IMAGE_BLEND_USING_FORMULA)
						fl_temp_fb_data_U8 = (fl_fb_byte_U8 >> (LCD_SIZE_MUL_FACTOR << 1));
						fl_temp_fb_data_U8 = fl_tempdata_U8 + (((fl_temp_fb_data_U8 * fl_division_factor_U8) - (fl_temp_fb_data_U8 * fl_tempdata_U8)) / fl_division_factor_U8);
						fl_data_U8 |= (fl_temp_fb_data_U8 << (LCD_SIZE_MUL_FACTOR << 1));
#endif 
						fl_bmp_data_U8 = fl_data_U8;
#else  
						{
#if ((defined(GFX_TRANSPARENT)) ||(defined(GFX_TEXT_ON_GREY)|| ( (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP) && (defined(GFX_IMAGE_BLEND_USING_ARRAY)|| defined(GFX_IMAGE_BLEND_USING_FORMULA)))) )                 
							fl_fb_byte_U8 = FB(fl_fb_U8AP, fl_count_U16, layer);
#endif
							fl_tempshift_U8 = 0;
							fl_tempbmpdata_U8 = 0;
							for (fl_cnt_U8 = 0; fl_cnt_U8 < fl_shiftcnt_U8; fl_cnt_U8++)
							{
								fl_tempdata_U8 = (fl_bmp_data_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP)
								if (alpha != GFX_MGR02_PIX_FORMAT_ALPHA)
								{
#if defined(GFX_TEXT_ON_GREY)
									fl_drawcolour_U8 = l_bmp_alpha_merge[(drawcolour << 4) | (alpha)];
#else
									fl_tempdata_U8 = l_bmp_alpha_merge[(fl_tempdata_U8 << 4) | (alpha)];
#endif
								}
#endif

#if (defined(GFX_TRANSPARENT))                                     
								fl_imgpixel_data_U8 = (fl_bmp_data_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
								if (fl_imgpixel_data_U8 == trans_color)
								{
									fl_tempdata_U8 = (fl_fb_byte_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
								}
#elif defined(GFX_TEXT_ON_GREY)
								fl_temp_fb_data_U8 = (fl_fb_byte_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
								fl_factor_SU8 = GET_TEXT_CORRECTION_FACTOR(fl_drawcolour_U8, fl_temp_fb_data_U8);
								fl_factor_SU8 = CLAMP_TEXT_CORRECTION_FACTOR(fl_factor_SU8);
								fl_tempdata_U8 = fl_temp_fb_data_U8 + (((fl_tempdata_U8 * (fl_drawcolour_U8 - fl_temp_fb_data_U8)) + fl_factor_SU8) / fl_division_factor_U8);
#else
								fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#endif                      
#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP)
#if defined(GFX_IMAGE_BLEND_USING_ARRAY)
								fl_temp_fb_data_U8 = (fl_fb_byte_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
								fl_tempdata_U8 = l_alpha_blend[fl_tempdata_U8 | (fl_temp_fb_data_U8 << 4)];
								fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#elif defined(GFX_IMAGE_BLEND_USING_FORMULA)
								fl_temp_fb_data_U8 = (fl_fb_byte_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
								fl_tempdata_U8 = fl_tempdata_U8 + (((fl_temp_fb_data_U8 * fl_division_factor_U8) - (fl_temp_fb_data_U8 * fl_tempdata_U8)) / fl_division_factor_U8);
								fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#else 
								fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#endif
#else
								fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#endif
								fl_tempshift_U8 += fl_shiftbits_U8;
							}
							fl_bmp_data_U8 = fl_tempbmpdata_U8;
						}
#endif
						IMG_CP_OP(FB(fl_fb_U8AP, fl_count_U16, layer), fl_bmp_data_U8);
					}
					GFX_DRIVER_SCHED_WAIT();
				}
				fl_fb_U8AP = NEXT_FBP_LINE(fl_fb_U8AP, layer);
				fl_nb_lines_U16--;
				if (fl_copy_width_U16 != width)
				{
					bmp_data = &bmp_data[width - (fl_copy_width_U16 + fl_copy_sindex_U16)];
				}
			}
			fl_end_offset_U8 = SOFFS(height);
			if (fl_end_offset_U8 != 0)
			{
				/*
				** Copy the unaligned end pixels. if any
				*/
				if ((fl_actual_start_pos & 0x01) == 0) //Checking X/Y is even
				{
					/* Case 1 (Both start x/y clip x/y are even) */
					fl_fb_mask_U8 = SL(((UINT8)0xFF), (8 - fl_end_offset_U8));
					fl_bmp_data_mask_U8 = SR(((UINT8)0xFF), (8 - fl_end_offset_U8));
				}
				else
				{
					/* Case 4 ( start x/y is odd but clip x/y is even) */
					fl_fb_mask_U8 = SL(((UINT8)0xFF), (8 - fl_end_offset_U8));
					fl_bmp_data_mask_U8 = SL(((UINT8)0xFF), (8 - fl_end_offset_U8));
				}
				/* Case 2 and Case 3 will be handled as part of the "Unaligned byte" block */

				fl_cwidth_U16 = fl_copy_width_U16;
				if (fl_copy_sindex_U16 != 0)
				{
					bmp_data = &bmp_data[fl_copy_sindex_U16];
				}
#ifdef GFX_RLE_SUPPORT
				fl_data_count_U16 = 0;
#endif
				for (fl_count_U16 = 0; fl_count_U16 < fl_cwidth_U16; fl_count_U16++)
				{
#ifndef GFX_RLE_SUPPORT
					IMG_PR_OP(fl_bmp_data_U8, *bmp_data);
					bmp_data++;
#else
					if (FL_RLE_CUR_COUNT == 0)
					{
#ifdef GFX_COMPILE_SPEED_OPTIMIZE
						GfxDriverRLEonline(fl_rle_cur_bmp_data, fl_rle_cur_count, fl_rle_cur_flag, fl_rle_cur_data);
#else
						GfxDriverRLEonline(&fl_rle_cur);
#endif
					}
					FL_RLE_CUR_COUNT--;
					if (FL_RLE_CUR_FLAG == FALSE)
					{
						FL_RLE_CUR_DATA = *FL_RLE_CUR_BMP_DATA++;
					}
					IMG_PR_OP(fl_bmp_data_U8, FL_RLE_CUR_DATA);
					fl_data_count_U16++;
					if ((fl_data_count_U16 == fl_cwidth_U16) && (width > fl_cwidth_U16))
					{
						p_width = width - fl_cwidth_U16;
#ifdef GFX_COMPILE_SPEED_OPTIMIZE
						fl_width = p_width;
						GfxDriverRLEonlineNLine(fl_rle_cur_bmp_data, fl_rle_cur_count, fl_rle_cur_flag, fl_rle_cur_data, fl_width);
#else
						GfxDriverRLEonlineNLine(&fl_rle_cur, p_width);
#endif
						fl_data_count_U16 = 0;
					}
#endif
					fl_data_U8 = FB(fl_fb_U8AP, fl_count_U16, layer);
					if (alpha > 0)
					{
						if ((alpha != GFX_MGR02_PIX_FORMAT_ALPHA) || (fl_is_text_on_grey == YES) || (fl_is_transparent == YES) || (fl_image_blend == YES))
						{
#if ((defined(GFX_TRANSPARENT)) ||(defined(GFX_TEXT_ON_GREY)|| ( (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP) && (defined(GFX_IMAGE_BLEND_USING_ARRAY)|| defined(GFX_IMAGE_BLEND_USING_FORMULA)))) )                 
							fl_fb_byte_U8 = fl_data_U8;
#endif
							fl_tempshift_U8 = 0;
							fl_data_U8 &= fl_fb_mask_U8;
                          #if !defined(GFX_TRANSPARENT)
							fl_tempbmpdata_U8 = fl_data_U8;
						  #else
						    /* For chroma-key enabled image, when transaprent color doesn't match,
							** then we have to relpace the pixel instead of blending just like normal image
							*/
						    fl_tempbmpdata_U8 = 0;
						  #endif
#if (GFX_MGR02_BIT_ORDER_LSB_FIRST==1)
							if (fl_copy_rem_U16 > 0)
							{
								fl_initialcnt_U8 = (8 - fl_end_offset_U8) / fl_shiftbits_U8;
								fl_finalcnt_U8 = fl_shiftcnt_U8;
								fl_tempshift_U8 = fl_initialcnt_U8 * fl_shiftbits_U8;
								//fl_bmp_data_mask_U8   = SL(((UINT8)0xFF) , (8-fl_end_offset_U8));
							}
							else
							{
								fl_initialcnt_U8 = 0;
								fl_finalcnt_U8 = fl_end_offset_U8 / fl_shiftbits_U8;
							}
#else
							fl_initialcnt_U8 = (8 - fl_end_offset_U8) / fl_shiftbits_U8;
							fl_finalcnt_U8 = fl_shiftcnt_U8;
							fl_tempshift_U8 = fl_initialcnt_U8 * fl_shiftbits_U8;
#endif
							//fl_bmp_data_U8    = fl_bmp_data_U8 & fl_bmp_data_mask_U8;
							for (fl_cnt_U8 = fl_initialcnt_U8; fl_cnt_U8 < fl_finalcnt_U8; fl_cnt_U8++)
							{
								fl_tempdata_U8 = (fl_bmp_data_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP)
								if (alpha != GFX_MGR02_PIX_FORMAT_ALPHA)
								{
#if defined(GFX_TEXT_ON_GREY)
									fl_drawcolour_U8 = l_bmp_alpha_merge[(drawcolour << 4) | (alpha)];
#else
									fl_tempdata_U8 = l_bmp_alpha_merge[(fl_tempdata_U8 << 4) | (alpha)];
#endif
								}
#endif
#if (defined(GFX_TRANSPARENT))                                     
								fl_imgpixel_data_U8 = (fl_bmp_data_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
								if (fl_imgpixel_data_U8 == trans_color)
								{
									fl_tempdata_U8 = fl_fb_byte_U8 & fl_maskbits_U8;
								}
#elif defined(GFX_TEXT_ON_GREY)
								fl_temp_fb_data_U8 = (fl_fb_byte_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
								fl_factor_SU8 = GET_TEXT_CORRECTION_FACTOR(fl_drawcolour_U8, fl_temp_fb_data_U8);
								fl_factor_SU8 = CLAMP_TEXT_CORRECTION_FACTOR(fl_factor_SU8);
								fl_tempdata_U8 = fl_temp_fb_data_U8 + (((fl_tempdata_U8 * (fl_drawcolour_U8 - fl_temp_fb_data_U8)) + fl_factor_SU8) / fl_division_factor_U8);
#else
								fl_tempbmpdata_U8 = fl_data_U8 & fl_maskbits_U8;
								fl_tempbmpdata_U8 = (fl_tempbmpdata_U8 << fl_tempshift_U8);
#endif
#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP)
#if defined(GFX_IMAGE_BLEND_USING_ARRAY)
								fl_temp_fb_data_U8 = (fl_fb_byte_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
								fl_tempdata_U8 = l_alpha_blend[fl_tempdata_U8 | (fl_temp_fb_data_U8 << 4)];
								fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#elif defined(GFX_IMAGE_BLEND_USING_FORMULA)
								fl_temp_fb_data_U8 = (fl_fb_byte_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
								fl_tempdata_U8 = fl_tempdata_U8 + (((fl_temp_fb_data_U8 * fl_division_factor_U8) - (fl_temp_fb_data_U8 * fl_tempdata_U8)) / fl_division_factor_U8);
								fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#endif
#if (GFX_MGR02_BIT_ORDER_LSB_FIRST==1)
								fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#else
								fl_tempbmpdata_U8 |= fl_tempdata_U8;
#endif
#endif
								fl_tempshift_U8 += fl_shiftbits_U8;
							}
							fl_data_U8 = FB(fl_fb_U8AP, fl_count_U16, layer);
							fl_data_U8 &= fl_fb_mask_U8;
							if ((fl_actual_start_pos & 0x01) == 0) //Checking X/Y is even
							{
								fl_data_U8 |= (fl_tempbmpdata_U8 & fl_bmp_data_mask_U8);   //Old code
							}
							else
							{
								fl_bmp_data_U8 = SR((fl_tempbmpdata_U8 & fl_bmp_data_mask_U8), (8 - fl_end_offset_U8)); //New code
								fl_data_U8 |= fl_bmp_data_U8;
							}
						}
						else
						{
							fl_data_U8 &= fl_fb_mask_U8;
							if ((fl_actual_start_pos & 0x01) == 0) //Checking X/Y is even
							{
								fl_data_U8 |= (fl_bmp_data_U8 & fl_bmp_data_mask_U8);   //Old code
							}
							else
							{
								fl_bmp_data_U8 = SR((fl_bmp_data_U8 & fl_bmp_data_mask_U8), (8 - fl_end_offset_U8)); //New code
								fl_data_U8 |= fl_bmp_data_U8;
							}
						}
						IMG_CP_OP(FB(fl_fb_U8AP, fl_count_U16, layer), fl_data_U8);
					}
					GFX_DRIVER_SCHED_WAIT();
				}
			}
		}
		else
		{
			/*
			** Bitmap is not aligned to byte boundary
			** First perform the top, then middle lastly the bottom.
			*/
			UINT8 const * fl_data_U8AP;
			fl_start_height_U8 = (8 - fl_start_offset_U8);
			fl_end_mask_U8 = SR(((UINT8)0xFF), fl_start_height_U8);


			fl_cwidth_U16 = fl_copy_width_U16;
			fl_data_U8AP = bmp_data;
			if (fl_copy_sindex_U16 != 0)
			{
				fl_data_U8AP = &fl_data_U8AP[fl_copy_sindex_U16];
			}
			if (fl_copy_y_U16 != 0)
			{
				fl_copy_rem_U16 = SOFFS(fl_copy_y_U16);
				/* To find which index should be referred in bmp_data */
				/* Since fl_copy_sindex_U16 is required for further processing, its not modified */
				fl_tempcopy_U16 = NLINES(fl_copy_y_U16);
				fl_tempcopy_U16 = fl_tempcopy_U16 * width;
				fl_data_U8AP = &fl_data_U8AP[fl_tempcopy_U16];
			}
#ifdef GFX_RLE_SUPPORT
			FL_RLE_NLN_BMP_DATA = FL_RLE_CUR_BMP_DATA;
			FL_RLE_NLN_COUNT = FL_RLE_CUR_COUNT;
			FL_RLE_NLN_FLAG = FL_RLE_CUR_FLAG;
			FL_RLE_NLN_DATA = FL_RLE_CUR_DATA;
#endif
			for (fl_count_U16 = 0; fl_count_U16 < fl_cwidth_U16; fl_count_U16++)
			{
#ifndef GFX_RLE_SUPPORT
				IMG_PR_OP(fl_bmp_data_U8, *fl_data_U8AP);
				if (fl_copy_rem_U16 != 0)
				{
					IMG_PR_OP(fl_bmp_data_U8, *fl_data_U8AP);
					fl_data_U8 = SR(fl_bmp_data_U8, fl_copy_rem_U16);
					IMG_PR_OP(fl_bmp_data_U8, fl_data_U8AP[width]);
					fl_data_U8 += SL(fl_bmp_data_U8, fl_copy_rem_U16);
					IMG_PR_OP(fl_bmp_data_U8, fl_data_U8);
				}
#else
				if (FL_RLE_CUR_COUNT == 0)
				{
#ifdef GFX_COMPILE_SPEED_OPTIMIZE
					GfxDriverRLEonline(fl_rle_cur_bmp_data, fl_rle_cur_count, fl_rle_cur_flag, fl_rle_cur_data);
#else
					GfxDriverRLEonline(&fl_rle_cur);
#endif
				}
				FL_RLE_CLIP_FLAG = FL_RLE_CUR_FLAG;
				FL_RLE_CLIP_COUNT = FL_RLE_CUR_COUNT;
				FL_RLE_CLIP_BMP_DATA = FL_RLE_CUR_BMP_DATA;
				FL_RLE_CLIP_DATA = FL_RLE_CUR_DATA;
				FL_RLE_CUR_COUNT--;
				if (FL_RLE_CUR_FLAG == FALSE)
				{
					FL_RLE_CUR_DATA = *FL_RLE_CUR_BMP_DATA++;
				}
				IMG_PR_OP(fl_bmp_data_U8, FL_RLE_CUR_DATA);
				if (fl_copy_rem_U16 != 0)
				{
					fl_data_U8 = SR(fl_bmp_data_U8, fl_copy_rem_U16);
#ifdef GFX_COMPILE_SPEED_OPTIMIZE
					fl_width = width;
					GfxDriverRLEonlineNLine(fl_rle_clip_bmp_data, fl_rle_clip_count, fl_rle_clip_flag, fl_rle_clip_data, fl_width);
#else
					GfxDriverRLEonlineNLine(&fl_rle_clip, width);
#endif                     
					if ((FL_RLE_CLIP_COUNT == 0))
					{
#ifdef GFX_COMPILE_SPEED_OPTIMIZE
						GfxDriverRLEonline(fl_rle_clip_bmp_data, fl_rle_clip_count, fl_rle_clip_flag, fl_rle_clip_data);
#else
						GfxDriverRLEonline(&fl_rle_clip);
#endif
					}
					FL_RLE_CLIP_COUNT--;
					if (FL_RLE_CLIP_FLAG == FALSE)
					{
						IMG_PR_OP(fl_bmp_data_U8, *FL_RLE_CLIP_BMP_DATA++);
					}
					else
					{
						IMG_PR_OP(fl_bmp_data_U8, FL_RLE_CLIP_DATA);
					}
					fl_data_U8 += SL(fl_bmp_data_U8, fl_copy_rem_U16);
					IMG_PR_OP(fl_bmp_data_U8, fl_data_U8);
				}
#endif
				fl_data_U8 = FB(fl_fb_U8AP, fl_count_U16, layer);
				if (alpha > 0)
				{
					if ((alpha != GFX_MGR02_PIX_FORMAT_ALPHA) || (fl_is_text_on_grey == YES) || (fl_is_transparent == YES) || (fl_image_blend == YES))
					{
#if ((defined(GFX_TRANSPARENT)) ||(defined(GFX_TEXT_ON_GREY)|| ( (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP) && (defined(GFX_IMAGE_BLEND_USING_ARRAY)|| defined(GFX_IMAGE_BLEND_USING_FORMULA)))) )                 
						fl_fb_byte_U8 = fl_data_U8;
#endif
						fl_tempshift_U8 = 0;
						fl_data_U8 &= fl_end_mask_U8;
						fl_tempbmpdata_U8 = fl_data_U8;
						fl_bmp_data_U8 = SL(fl_bmp_data_U8, fl_start_offset_U8);
#if (GFX_MGR02_BIT_ORDER_LSB_FIRST==1)
						fl_tempshift_U8 = fl_start_height_U8 / fl_shiftbits_U8;
						fl_initialcnt_U8 = fl_shiftcnt_U8 - fl_tempshift_U8;
						fl_tempshift_U8 = fl_initialcnt_U8 * fl_shiftbits_U8;
						fl_finalcnt_U8 = fl_shiftcnt_U8;
#else
						fl_initialcnt_U8 = 0;
						fl_finalcnt_U8 = fl_start_height_U8 / fl_shiftbits_U8;
#endif
						for (fl_cnt_U8 = fl_initialcnt_U8; fl_cnt_U8 < fl_finalcnt_U8; fl_cnt_U8++)
						{
							fl_tempdata_U8 = (fl_bmp_data_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP)
							if (alpha != GFX_MGR02_PIX_FORMAT_ALPHA)
							{
#if defined(GFX_TEXT_ON_GREY)
								fl_drawcolour_U8 = l_bmp_alpha_merge[(drawcolour << 4) | (alpha)];
#else
								fl_tempdata_U8 = l_bmp_alpha_merge[(fl_tempdata_U8 << 4) | (alpha)];
#endif                         
							}
#endif

#if (defined(GFX_TRANSPARENT))                 
							fl_imgpixel_data_U8 = (fl_bmp_data_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
							if (fl_imgpixel_data_U8 == trans_color)
							{
								fl_tempdata_U8 = (fl_fb_byte_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
							}
#elif defined(GFX_TEXT_ON_GREY)
							fl_temp_fb_data_U8 = (fl_fb_byte_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
							fl_factor_SU8 = GET_TEXT_CORRECTION_FACTOR(fl_drawcolour_U8, fl_temp_fb_data_U8);
							fl_factor_SU8 = CLAMP_TEXT_CORRECTION_FACTOR(fl_factor_SU8);
							fl_tempdata_U8 = fl_temp_fb_data_U8 + (((fl_tempdata_U8 * (fl_drawcolour_U8 - fl_temp_fb_data_U8)) + fl_factor_SU8) / fl_division_factor_U8);
#else
							fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#endif
#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP)
#if defined(GFX_IMAGE_BLEND_USING_ARRAY)
							fl_temp_fb_data_U8 = (fl_fb_byte_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
							fl_tempdata_U8 = l_alpha_blend[fl_tempdata_U8 | (fl_temp_fb_data_U8 << 4)];
							fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#elif defined(GFX_IMAGE_BLEND_USING_FORMULA)
							fl_temp_fb_data_U8 = (fl_fb_byte_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
							fl_tempdata_U8 = fl_tempdata_U8 + (((fl_temp_fb_data_U8 * fl_division_factor_U8) - (fl_temp_fb_data_U8 * fl_tempdata_U8)) / fl_division_factor_U8);
							fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#else
							fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#endif
#else
							fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#endif                 
							fl_tempshift_U8 += fl_shiftbits_U8;
						}
						fl_data_U8 = fl_tempbmpdata_U8;
					}
					else
					{
						fl_data_U8 &= fl_end_mask_U8;
						fl_data_U8 |= SL(fl_bmp_data_U8, fl_start_offset_U8);
					}
					IMG_CP_OP(FB(fl_fb_U8AP, fl_count_U16, layer), fl_data_U8);
				}
				fl_data_U8AP++;
				GFX_DRIVER_SCHED_WAIT();
			}
			fl_fb_U8AP = NEXT_FBP_LINE(fl_fb_U8AP, layer);
			fl_nb_lines_U16 = (height - (UINT16)fl_start_height_U8);
			fl_end_offset_U8 = (UINT8)(fl_nb_lines_U16 & 0x07);
			fl_nb_lines_U16 >>= 3;

#ifdef GFX_RLE_SUPPORT

			FL_RLE_CUR_BMP_DATA = FL_RLE_NLN_BMP_DATA;
			FL_RLE_CUR_COUNT = FL_RLE_NLN_COUNT;
			FL_RLE_CUR_FLAG = FL_RLE_NLN_FLAG;
			FL_RLE_CUR_DATA = FL_RLE_NLN_DATA;
#ifdef GFX_COMPILE_SPEED_OPTIMIZE
			fl_width = width;
			GfxDriverRLEonlineNLine(fl_rle_nln_bmp_data, fl_rle_nln_count, fl_rle_nln_flag, fl_rle_nln_data, fl_width);
#else
			GfxDriverRLEonlineNLine(&fl_rle_nln, width);
#endif
			fl_data_count_U16 = 0;
#endif

			while (fl_nb_lines_U16 != 0)
			{
				fl_cwidth_U16 = fl_copy_width_U16;
				if (fl_copy_sindex_U16 != 0)
				{
					bmp_data = &bmp_data[fl_copy_sindex_U16];
				}
				if (fl_copy_y_U16 != 0)
				{
					fl_tempcopy_U16 = NLINES((fl_copy_y_U16 + fl_copy_rem_U16));
					fl_copy_y_U16 = 0;
					fl_tempcopy_U16 = fl_tempcopy_U16 * width;
					bmp_data = &bmp_data[fl_tempcopy_U16];
				}
				for (fl_count_U16 = 0; fl_count_U16 < fl_cwidth_U16; fl_count_U16++)
				{
#ifndef GFX_RLE_SUPPORT
					if (fl_copy_rem_U16 != 0)
					{
						IMG_PR_OP(fl_data_U8, *bmp_data);
						bmp_data++;
					}
					else
					{
						IMG_PR_OP(fl_bmp_data_U8, *bmp_data);
						fl_data_U8 = SR(fl_bmp_data_U8, fl_start_height_U8);
						IMG_PR_OP(fl_bmp_data_U8, bmp_data[width]);
						fl_data_U8 += SL(fl_bmp_data_U8, fl_start_offset_U8);
						bmp_data++;
					}
#else
					/*
					** move the cur line buffer to read next data
					*/
					if (FL_RLE_CUR_COUNT == 0)
					{
#ifdef GFX_COMPILE_SPEED_OPTIMIZE
						GfxDriverRLEonline(fl_rle_cur_bmp_data, fl_rle_cur_count, fl_rle_cur_flag, fl_rle_cur_data);
#else
						GfxDriverRLEonline(&fl_rle_cur);
#endif
					}
					FL_RLE_CLIP_FLAG = FL_RLE_CUR_FLAG;
					FL_RLE_CLIP_COUNT = FL_RLE_CUR_COUNT;
					FL_RLE_CLIP_BMP_DATA = FL_RLE_CUR_BMP_DATA;
					FL_RLE_CLIP_DATA = FL_RLE_CUR_DATA;
					FL_RLE_CUR_COUNT--;
					if (FL_RLE_CUR_FLAG == FALSE)
					{
						FL_RLE_CUR_DATA = *FL_RLE_CUR_BMP_DATA++;
					}
					/*
					** move the next line buffer to read next data
					*/
					if (FL_RLE_NLN_COUNT == 0)
					{
#ifdef GFX_COMPILE_SPEED_OPTIMIZE
						GfxDriverRLEonline(fl_rle_nln_bmp_data, fl_rle_nln_count, fl_rle_nln_flag, fl_rle_nln_data);
#else
						GfxDriverRLEonline(&fl_rle_nln);
#endif
					}
					FL_RLE_NLN_COUNT--;
					if (FL_RLE_NLN_FLAG == FALSE)
					{
						FL_RLE_NLN_DATA = *FL_RLE_NLN_BMP_DATA++;
					}
					IMG_PR_OP(fl_bmp_data_U8, FL_RLE_CUR_DATA);
					fl_data_U8 = SR(fl_bmp_data_U8, fl_start_height_U8);
					IMG_PR_OP(fl_bmp_data_U8, FL_RLE_NLN_DATA);
					fl_data_U8 += SL(fl_bmp_data_U8, fl_start_offset_U8);
					fl_data_count_U16++;
					if (fl_copy_rem_U16 != 0)
					{
						fl_data_U8 = SR(fl_bmp_data_U8, fl_copy_rem_U16);
#ifdef GFX_COMPILE_SPEED_OPTIMIZE
						fl_width = width;
						GfxDriverRLEonlineNLine(fl_rle_clip_bmp_data, fl_rle_clip_count, fl_rle_clip_flag, fl_rle_clip_data, fl_width);
#else
						GfxDriverRLEonlineNLine(&fl_rle_clip, width);
#endif                     
						if ((FL_RLE_CLIP_COUNT == 0))
						{
#ifdef GFX_COMPILE_SPEED_OPTIMIZE
							GfxDriverRLEonline(fl_rle_clip_bmp_data, fl_rle_clip_count, fl_rle_clip_flag, fl_rle_clip_data);
#else
							GfxDriverRLEonline(&fl_rle_clip);
#endif
						}
						FL_RLE_CLIP_COUNT--;
						if (FL_RLE_CLIP_FLAG == FALSE)
						{
							IMG_PR_OP(fl_bmp_data_U8, *FL_RLE_CLIP_BMP_DATA++);
						}
						else
						{
							IMG_PR_OP(fl_bmp_data_U8, FL_RLE_CLIP_DATA);
						}
						fl_data_U8 += SL(fl_bmp_data_U8, fl_copy_rem_U16);
						IMG_PR_OP(fl_bmp_data_U8, fl_data_U8);
					}
					if ((fl_data_count_U16 == fl_cwidth_U16) && (width > fl_cwidth_U16))
					{
						p_width = width - fl_cwidth_U16;
#ifdef GFX_COMPILE_SPEED_OPTIMIZE
						fl_width = p_width;
						GfxDriverRLEonlineNLine(fl_rle_cur_bmp_data, fl_rle_cur_count, fl_rle_cur_flag, fl_rle_cur_data, fl_width);
#else
						GfxDriverRLEonlineNLine(&fl_rle_cur, p_width);
#endif
#ifdef GFX_COMPILE_SPEED_OPTIMIZE
						fl_width = p_width;
						GfxDriverRLEonlineNLine(fl_rle_nln_bmp_data, fl_rle_nln_count, fl_rle_nln_flag, fl_rle_nln_data, fl_width);
#else
						GfxDriverRLEonlineNLine(&fl_rle_nln, p_width);
#endif
						fl_data_count_U16 = 0;
					}
#endif
					if (alpha > 0)
					{
						if ((alpha != GFX_MGR02_PIX_FORMAT_ALPHA) || (fl_is_text_on_grey == YES) || (fl_is_transparent == YES) || (fl_image_blend == YES))
						{
#if ((defined(GFX_TRANSPARENT)) ||(defined(GFX_TEXT_ON_GREY)|| ( (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP) && (defined(GFX_IMAGE_BLEND_USING_ARRAY)|| defined(GFX_IMAGE_BLEND_USING_FORMULA)))) )                 
							fl_fb_byte_U8 = FB(fl_fb_U8AP, fl_count_U16, layer);
#endif
							fl_tempshift_U8 = 0;
							fl_tempbmpdata_U8 = 0;
							for (fl_cnt_U8 = 0; fl_cnt_U8 < fl_shiftcnt_U8; fl_cnt_U8++)
							{
								fl_tempdata_U8 = (fl_data_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP)                   
								if (alpha != GFX_MGR02_PIX_FORMAT_ALPHA)
								{
#if defined(GFX_TEXT_ON_GREY)
									fl_drawcolour_U8 = l_bmp_alpha_merge[(drawcolour << 4) | (alpha)];
#else
									fl_tempdata_U8 = l_bmp_alpha_merge[(fl_tempdata_U8 << 4) | (alpha)];
#endif                         
								}
#endif                                       

#if  (defined(GFX_TRANSPARENT))                                  
								fl_imgpixel_data_U8 = (fl_data_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
								if (fl_imgpixel_data_U8 == trans_color)
								{
									fl_tempdata_U8 = (fl_fb_byte_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
								}
#elif defined(GFX_TEXT_ON_GREY)
								fl_temp_fb_data_U8 = (fl_fb_byte_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
								fl_factor_SU8 = GET_TEXT_CORRECTION_FACTOR(fl_drawcolour_U8, fl_temp_fb_data_U8);
								fl_factor_SU8 = CLAMP_TEXT_CORRECTION_FACTOR(fl_factor_SU8);
								fl_tempdata_U8 = fl_temp_fb_data_U8 + (((fl_tempdata_U8 * (fl_drawcolour_U8 - fl_temp_fb_data_U8)) + fl_factor_SU8) / fl_division_factor_U8);
#else
								fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#endif
#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP)
#if defined(GFX_IMAGE_BLEND_USING_ARRAY)
								fl_temp_fb_data_U8 = (fl_fb_byte_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
								fl_tempdata_U8 = l_alpha_blend[fl_tempdata_U8 | (fl_temp_fb_data_U8 << 4)];
								fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#elif defined(GFX_IMAGE_BLEND_USING_FORMULA)
								fl_temp_fb_data_U8 = (fl_fb_byte_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
								fl_tempdata_U8 = fl_tempdata_U8 + (((fl_temp_fb_data_U8 * fl_division_factor_U8) - (fl_temp_fb_data_U8 * fl_tempdata_U8)) / fl_division_factor_U8);
								fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#else
								fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#endif  
#else
								fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#endif
								fl_tempshift_U8 += fl_shiftbits_U8;
							}
							fl_data_U8 = fl_tempbmpdata_U8;
						}
						IMG_CP_OP(FB(fl_fb_U8AP, fl_count_U16, layer), fl_data_U8);
					}
					GFX_DRIVER_SCHED_WAIT();
				}
				fl_fb_U8AP = NEXT_FBP_LINE(fl_fb_U8AP, layer);
				fl_nb_lines_U16--;
				if (fl_copy_width_U16 != width)
				{
					bmp_data = &bmp_data[width - (fl_copy_width_U16 + fl_copy_sindex_U16)];
				}
			}
			if (fl_end_offset_U8 != 0)
			{
				fl_start_mask_U8 = SL(((UINT8)0xFF), fl_end_offset_U8);
				fl_cwidth_U16 = fl_copy_width_U16;
				fl_bmp_data_mask_U8 = SR(((UINT8)0xFF), (8 - (SOFFS(height + fl_copy_rem_U16))));
				if (fl_bmp_data_mask_U8 == 0)
				{
					fl_bmp_data_mask_U8 = 0xFF;
				}
				if (fl_copy_sindex_U16 != 0)
				{
					bmp_data = &bmp_data[fl_copy_sindex_U16];
				}
				if (fl_copy_y_U16 != 0)
				{
					fl_tempcopy_U16 = NLINES((fl_copy_y_U16 + fl_copy_rem_U16));
					fl_tempcopy_U16 = fl_tempcopy_U16 * width;
					bmp_data = &bmp_data[fl_tempcopy_U16];
				}
				if (fl_end_offset_U8 > fl_start_offset_U8)
				{
					for (fl_count_U16 = 0; fl_count_U16 < fl_cwidth_U16; fl_count_U16++)
					{
						fl_data_U8 = FB(fl_fb_U8AP, fl_count_U16, layer);
#ifndef GFX_RLE_SUPPORT
						IMG_PR_OP(fl_bmp_data_U8, *bmp_data);
						fl_tempbmpdata_U8 = 0;
						fl_tempbmpdata_U8 = SR(fl_bmp_data_U8, fl_start_height_U8);
						IMG_PR_OP(fl_bmp_data_U8, bmp_data[width]);
						fl_bmp_data_U8 &= fl_bmp_data_mask_U8;
						fl_tempbmpdata_U8 += SL(fl_bmp_data_U8, fl_start_offset_U8);
						bmp_data++;
#else
						if (FL_RLE_CUR_COUNT == 0)
						{
#ifdef GFX_COMPILE_SPEED_OPTIMIZE
							GfxDriverRLEonline(fl_rle_cur_bmp_data, fl_rle_cur_count, fl_rle_cur_flag, fl_rle_cur_data);
#else
							GfxDriverRLEonline(&fl_rle_cur);
#endif
						}
						FL_RLE_CUR_COUNT--;
						if (FL_RLE_CUR_FLAG == FALSE)
						{
							FL_RLE_CUR_DATA = *FL_RLE_CUR_BMP_DATA++;
						}
						if (FL_RLE_NLN_COUNT == 0)
						{
#ifdef GFX_COMPILE_SPEED_OPTIMIZE
							GfxDriverRLEonline(fl_rle_nln_bmp_data, fl_rle_nln_count, fl_rle_nln_flag, fl_rle_nln_data);
#else
							GfxDriverRLEonline(&fl_rle_nln);
#endif
						}
						FL_RLE_NLN_COUNT--;
						if (FL_RLE_NLN_FLAG == FALSE)
						{
							FL_RLE_NLN_DATA = *FL_RLE_NLN_BMP_DATA++;
						}
						IMG_PR_OP(fl_bmp_data_U8, FL_RLE_CUR_DATA);
						fl_tempbmpdata_U8 = 0;
						fl_tempbmpdata_U8 = SR(fl_bmp_data_U8, fl_start_height_U8);
						IMG_PR_OP(fl_bmp_data_U8, FL_RLE_NLN_DATA);
						fl_bmp_data_U8 &= fl_bmp_data_mask_U8;
						fl_tempbmpdata_U8 += SL(fl_bmp_data_U8, fl_start_offset_U8);
						fl_data_count_U16++;
						if ((fl_data_count_U16 == fl_cwidth_U16) && (width > fl_cwidth_U16))
						{
							p_width = width - fl_cwidth_U16;
#ifdef GFX_COMPILE_SPEED_OPTIMIZE
							fl_width = p_width;
							GfxDriverRLEonlineNLine(fl_rle_cur_bmp_data, fl_rle_cur_count, fl_rle_cur_flag, fl_rle_cur_data, fl_width);
#else
							GfxDriverRLEonlineNLine(&fl_rle_cur, p_width);
#endif
#ifdef GFX_COMPILE_SPEED_OPTIMIZE
							fl_width = p_width;
							GfxDriverRLEonlineNLine(fl_rle_nln_bmp_data, fl_rle_nln_count, fl_rle_nln_flag, fl_rle_nln_data, fl_width);
#else
							GfxDriverRLEonlineNLine(&fl_rle_nln, p_width);
#endif
							fl_data_count_U16 = 0;
						}
#endif
						if (alpha > 0)
						{
							if ((alpha != GFX_MGR02_PIX_FORMAT_ALPHA) || (fl_is_text_on_grey == YES) || (fl_is_transparent == YES) || (fl_image_blend == YES))
							{
#if ((defined(GFX_TRANSPARENT)) ||(defined(GFX_TEXT_ON_GREY)|| ( (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP) && (defined(GFX_IMAGE_BLEND_USING_ARRAY)|| defined(GFX_IMAGE_BLEND_USING_FORMULA)))) )                 
								fl_fb_byte_U8 = fl_data_U8;
#endif
								fl_tempshift_U8 = 0;
								fl_bmp_data_U8 = fl_tempbmpdata_U8;
								fl_data_U8 &= fl_start_mask_U8;
								fl_tempbmpdata_U8 = fl_data_U8;
#if (GFX_MGR02_BIT_ORDER_LSB_FIRST==1)
								fl_initialcnt_U8 = 0;
								fl_finalcnt_U8 = fl_end_offset_U8 / fl_shiftbits_U8;
#else
								fl_initialcnt_U8 = (8 - fl_end_offset_U8) / fl_shiftbits_U8;
								fl_finalcnt_U8 = fl_shiftcnt_U8;
								fl_tempshift_U8 = fl_initialcnt_U8 * fl_shiftbits_U8;
#endif
								for (fl_cnt_U8 = fl_initialcnt_U8; fl_cnt_U8 < fl_finalcnt_U8; fl_cnt_U8++)
								{
									fl_tempdata_U8 = (fl_bmp_data_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP)                       
									if (alpha != GFX_MGR02_PIX_FORMAT_ALPHA)
									{
#if defined(GFX_TEXT_ON_GREY)
										fl_drawcolour_U8 = l_bmp_alpha_merge[(drawcolour << 4) | (alpha)];
#else
										fl_tempdata_U8 = l_bmp_alpha_merge[(fl_tempdata_U8 << 4) | (alpha)];
#endif                       
									}
#endif
#if (defined(GFX_TRANSPARENT))                                    
									fl_imgpixel_data_U8 = (fl_bmp_data_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
									if (fl_imgpixel_data_U8 == trans_color)
									{
										fl_tempdata_U8 = (fl_fb_byte_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
									}
#elif defined(GFX_TEXT_ON_GREY)
									fl_temp_fb_data_U8 = (fl_fb_byte_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
									fl_factor_SU8 = GET_TEXT_CORRECTION_FACTOR(fl_drawcolour_U8, fl_temp_fb_data_U8);
									fl_factor_SU8 = CLAMP_TEXT_CORRECTION_FACTOR(fl_factor_SU8);
									fl_tempdata_U8 = fl_temp_fb_data_U8 + (((fl_tempdata_U8 * (fl_drawcolour_U8 - fl_temp_fb_data_U8)) + fl_factor_SU8) / fl_division_factor_U8);
#else
									fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#endif
#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP)
#if defined(GFX_IMAGE_BLEND_USING_ARRAY)
									fl_temp_fb_data_U8 = (fl_fb_byte_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
									fl_tempdata_U8 = l_alpha_blend[fl_tempdata_U8 | (fl_temp_fb_data_U8 << 4)];
									fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#elif defined(GFX_IMAGE_BLEND_USING_FORMULA)
									fl_temp_fb_data_U8 = (fl_fb_byte_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
									fl_tempdata_U8 = fl_tempdata_U8 + (((fl_temp_fb_data_U8 * fl_division_factor_U8) - (fl_temp_fb_data_U8 * fl_tempdata_U8)) / fl_division_factor_U8);
									fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#else
									fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#endif
#else
									fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#endif
									fl_tempshift_U8 += fl_shiftbits_U8;
								}
								fl_data_U8 = fl_tempbmpdata_U8;
							}
							else
							{
								fl_data_U8 &= fl_start_mask_U8;
								fl_data_U8 += fl_tempbmpdata_U8;
							}
							IMG_CP_OP(FB(fl_fb_U8AP, fl_count_U16, layer), fl_data_U8);
						}
						GFX_DRIVER_SCHED_WAIT();
					}
				}
				else
				{
					for (fl_count_U16 = 0; fl_count_U16 < fl_cwidth_U16; fl_count_U16++)
					{
						fl_data_U8 = FB(fl_fb_U8AP, fl_count_U16, layer);
#ifndef GFX_RLE_SUPPORT
						IMG_PR_OP(fl_bmp_data_U8, *bmp_data);
						bmp_data++;
#else
						if (FL_RLE_CUR_COUNT == 0)
						{
#ifdef GFX_COMPILE_SPEED_OPTIMIZE
							GfxDriverRLEonline(fl_rle_cur_bmp_data, fl_rle_cur_count, fl_rle_cur_flag, fl_rle_cur_data);
#else
							GfxDriverRLEonline(&fl_rle_cur);
#endif
						}
						FL_RLE_CUR_COUNT--;
						if (FL_RLE_CUR_FLAG == FALSE)
						{
							FL_RLE_CUR_DATA = *FL_RLE_CUR_BMP_DATA++;
						}
						IMG_PR_OP(fl_bmp_data_U8, FL_RLE_CUR_DATA);
#endif
						fl_bmp_data_U8 &= fl_bmp_data_mask_U8;
						fl_bmp_data_U8 = SR(fl_bmp_data_U8, (fl_start_height_U8 - fl_copy_rem_U16));
						if (alpha > 0)
						{
							if ((alpha != GFX_MGR02_PIX_FORMAT_ALPHA) || (fl_is_text_on_grey == YES) || (fl_is_transparent == YES) || (fl_image_blend == YES))
							{
#if ((defined(GFX_TRANSPARENT)) ||(defined(GFX_TEXT_ON_GREY)|| ( (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP) && (defined(GFX_IMAGE_BLEND_USING_ARRAY)|| defined(GFX_IMAGE_BLEND_USING_FORMULA)))) )                 
								fl_fb_byte_U8 = fl_data_U8;
#endif
								fl_tempshift_U8 = 0;
								fl_data_U8 &= fl_start_mask_U8;
								fl_tempbmpdata_U8 = fl_data_U8;
#if (GFX_MGR02_BIT_ORDER_LSB_FIRST==1)
								fl_initialcnt_U8 = 0;
								fl_finalcnt_U8 = fl_end_offset_U8 / fl_shiftbits_U8;
#else
								fl_initialcnt_U8 = (8 - fl_end_offset_U8) / fl_shiftbits_U8;
								fl_finalcnt_U8 = fl_shiftcnt_U8;
								fl_tempshift_U8 = fl_initialcnt_U8 * fl_shiftbits_U8;
#endif
								for (fl_cnt_U8 = fl_initialcnt_U8; fl_cnt_U8 < fl_finalcnt_U8; fl_cnt_U8++)
								{
									fl_tempdata_U8 = (fl_bmp_data_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP)                           
									if (alpha != GFX_MGR02_PIX_FORMAT_ALPHA)
									{
#if defined(GFX_TEXT_ON_GREY)
										fl_drawcolour_U8 = l_bmp_alpha_merge[(drawcolour << 4) | (alpha)];
#else
										fl_tempdata_U8 = l_bmp_alpha_merge[(fl_tempdata_U8 << 4) | (alpha)];
#endif                                                          
									}
#endif
#if (defined(GFX_TRANSPARENT))                                     
									fl_imgpixel_data_U8 = (fl_bmp_data_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
									if (fl_imgpixel_data_U8 == trans_color)
									{
										fl_tempdata_U8 = (fl_fb_byte_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
									}
#elif defined(GFX_TEXT_ON_GREY)
									fl_temp_fb_data_U8 = (fl_fb_byte_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
									fl_factor_SU8 = GET_TEXT_CORRECTION_FACTOR(fl_drawcolour_U8, fl_temp_fb_data_U8);
									fl_factor_SU8 = CLAMP_TEXT_CORRECTION_FACTOR(fl_factor_SU8);
									fl_tempdata_U8 = fl_temp_fb_data_U8 + (((fl_tempdata_U8 * (fl_drawcolour_U8 - fl_temp_fb_data_U8)) + fl_factor_SU8) / fl_division_factor_U8);
#else
									fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#endif
#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP)
#if defined(GFX_IMAGE_BLEND_USING_ARRAY)
									fl_temp_fb_data_U8 = (fl_fb_byte_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
									fl_tempdata_U8 = l_alpha_blend[fl_tempdata_U8 | (fl_temp_fb_data_U8 << 4)];
									fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#elif defined(GFX_IMAGE_BLEND_USING_FORMULA)
									fl_temp_fb_data_U8 = (fl_fb_byte_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
									fl_tempdata_U8 = fl_tempdata_U8 + (((fl_temp_fb_data_U8 * fl_division_factor_U8) - (fl_temp_fb_data_U8 * fl_tempdata_U8)) / fl_division_factor_U8);
									fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#else
									fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#endif
#else
									fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#endif
									fl_tempshift_U8 += fl_shiftbits_U8;
								}
								fl_data_U8 = fl_tempbmpdata_U8;
							}
							else
							{
								fl_data_U8 &= fl_start_mask_U8;
								fl_data_U8 += fl_bmp_data_U8;
							}
							IMG_CP_OP(FB(fl_fb_U8AP, fl_count_U16, layer), fl_data_U8);
						}
						GFX_DRIVER_SCHED_WAIT();
					}
				}
			}
		}
	}
	else
	{
		/*
		** Just one line to copy
		*/
		fl_end_mask_U8 = SL(((UINT8)0xFF), (fl_start_offset_U8 + height));
#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_1BPP)
		fl_bmp_data_mask_U8 = SR(((UINT8)0xFF), (8 - height));    // Old code
#else
		if ((fl_actual_start_pos & 0x01) == 0) // Checking x/y is even
		{
			fl_bmp_data_mask_U8 = SR(((UINT8)0xFF), (8 - height));    // Old code
		}
		else
		{
			fl_bmp_data_mask_U8 = SL(((UINT8)0xFF), (8 - height));    // New code
		}
#endif

		fl_start_mask_U8 = SR(((UINT8)0xFF), (8 - fl_start_offset_U8));

		fl_start_mask_U8 += fl_end_mask_U8;

		fl_cwidth_U16 = fl_copy_width_U16;
		if (fl_copy_sindex_U16 != 0)
		{
			bmp_data = &bmp_data[fl_copy_sindex_U16];
		}
		if (fl_copy_y_U16 != 0)
		{
			fl_tempcopy_U16 = NLINES(fl_copy_y_U16);
			fl_tempcopy_U16 = fl_tempcopy_U16 * width;
			bmp_data = &bmp_data[fl_tempcopy_U16];
		}
		for (fl_count_U16 = 0; fl_count_U16 < fl_cwidth_U16; fl_count_U16++)
		{
			fl_data_U8 = FB(fl_fb_U8AP, fl_count_U16, layer);
#ifndef GFX_RLE_SUPPORT
			IMG_PR_OP(fl_bmp_data_U8, *bmp_data);
			bmp_data++;
#else
			if (FL_RLE_CUR_COUNT == 0)
			{
#ifdef GFX_COMPILE_SPEED_OPTIMIZE
				GfxDriverRLEonline(fl_rle_cur_bmp_data, fl_rle_cur_count, fl_rle_cur_flag, fl_rle_cur_data);
#else
				GfxDriverRLEonline(&fl_rle_cur);
#endif
			}
			FL_RLE_CUR_COUNT--;
			if (FL_RLE_CUR_FLAG == FALSE)
			{
				FL_RLE_CUR_DATA = *FL_RLE_CUR_BMP_DATA++;
			}
			IMG_PR_OP(fl_bmp_data_U8, FL_RLE_CUR_DATA);
#endif
			fl_bmp_data_U8 &= fl_bmp_data_mask_U8;
			
#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_1BPP)
                        fl_bmp_data_U8 = SL(fl_bmp_data_U8, fl_start_offset_U8);  //Old code
#else
			if ((fl_actual_start_pos & 0x01) == 0) //Checking X/Y is even
			{
				fl_bmp_data_U8 = SL(fl_bmp_data_U8, fl_start_offset_U8);  //Old code			   
			}
			else
			{
				fl_bmp_data_U8 = SR(fl_bmp_data_U8, (8 - height));
			}
#endif

			if (alpha > 0)
			{
				if ((alpha != GFX_MGR02_PIX_FORMAT_ALPHA) || (fl_is_text_on_grey == YES) || (fl_is_transparent == YES) || (fl_image_blend == YES))
				{
#if ((defined(GFX_TRANSPARENT)) ||(defined(GFX_TEXT_ON_GREY)|| ( (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP) && (defined(GFX_IMAGE_BLEND_USING_ARRAY)|| defined(GFX_IMAGE_BLEND_USING_FORMULA)))) )                 
				fl_fb_byte_U8 = fl_data_U8;
#endif
					fl_tempshift_U8 = 0;
					fl_data_U8 &= fl_start_mask_U8;
					fl_tempbmpdata_U8 = fl_data_U8;
#if (GFX_MGR02_BIT_ORDER_LSB_FIRST==1)
#if(GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_1BPP)

					fl_start_height_U8 = (8 - fl_start_offset_U8);
					fl_tempshift_U8 = fl_start_height_U8 / fl_shiftbits_U8;
					fl_initialcnt_U8 = fl_shiftcnt_U8 - fl_tempshift_U8;
					fl_tempshift_U8 = fl_initialcnt_U8 * fl_shiftbits_U8;
					fl_finalcnt_U8 = fl_shiftcnt_U8;					
#else
					fl_initialcnt_U8 = 0U;
					if (fl_start_offset_U8 == 0)
					{
						fl_finalcnt_U8 = fl_shiftcnt_U8;
					}
					else
					{
						fl_finalcnt_U8 = fl_start_offset_U8 / fl_shiftbits_U8;
					}
					fl_tempshift_U8 = 0U;
#endif
	

#else
					if (fl_start_offset_U8 == 0)
					{
						fl_initialcnt_U8 = 0U;
						fl_tempshift_U8 = (fl_shiftcnt_U8 - 1U) * fl_shiftbits_U8;
					}
					else
					{
						fl_initialcnt_U8 = fl_start_offset_U8 / fl_shiftbits_U8;
						fl_tempshift_U8 = fl_initialcnt_U8 * fl_shiftbits_U8;
					}
					fl_finalcnt_U8 = fl_shiftcnt_U8;

#endif
					for (fl_cnt_U8 = fl_initialcnt_U8; fl_cnt_U8 < fl_finalcnt_U8; fl_cnt_U8++)
					{
						fl_tempdata_U8 = (fl_bmp_data_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP)                   
						if (alpha != GFX_MGR02_PIX_FORMAT_ALPHA)
						{
#if defined(GFX_TEXT_ON_GREY)
							fl_drawcolour_U8 = l_bmp_alpha_merge[(drawcolour << 4) | (alpha)];
#else
							fl_tempdata_U8 = l_bmp_alpha_merge[(fl_tempdata_U8 << 4) | (alpha)];
#endif                        
						}
#endif                                      

#if (defined(GFX_TRANSPARENT))                 
						fl_imgpixel_data_U8 = (fl_bmp_data_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
						if (fl_imgpixel_data_U8 == trans_color)
						{
							fl_tempdata_U8 = (fl_fb_byte_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
						}
#elif defined(GFX_TEXT_ON_GREY)
						fl_temp_fb_data_U8 = (fl_fb_byte_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
						fl_factor_SU8 = GET_TEXT_CORRECTION_FACTOR(fl_drawcolour_U8, fl_temp_fb_data_U8);
						fl_factor_SU8 = CLAMP_TEXT_CORRECTION_FACTOR(fl_factor_SU8);
						fl_tempdata_U8 = fl_temp_fb_data_U8 + (((fl_tempdata_U8 * (fl_drawcolour_U8 - fl_temp_fb_data_U8)) + fl_factor_SU8) / fl_division_factor_U8);
#else
						fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#endif
#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP)
#if defined(GFX_IMAGE_BLEND_USING_ARRAY)
						fl_temp_fb_data_U8 = (fl_fb_byte_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
						fl_tempdata_U8 = l_alpha_blend[fl_tempdata_U8 | (fl_temp_fb_data_U8 << 4)];
						fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#elif defined(GFX_IMAGE_BLEND_USING_FORMULA)
						fl_temp_fb_data_U8 = (fl_fb_byte_U8 >> fl_tempshift_U8) & fl_maskbits_U8;
						fl_tempdata_U8 = fl_tempdata_U8 + (((fl_temp_fb_data_U8 * fl_division_factor_U8) - (fl_temp_fb_data_U8 * fl_tempdata_U8)) / fl_division_factor_U8);
						fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#else
						fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);
#endif
#else
						fl_tempbmpdata_U8 |= (fl_tempdata_U8 << fl_tempshift_U8);

#endif
#if (GFX_MGR02_BIT_ORDER_LSB_FIRST==1)
						fl_tempshift_U8 += fl_shiftbits_U8;
#else
						fl_tempshift_U8 -= fl_shiftbits_U8;
#endif
					}
					fl_data_U8 = fl_tempbmpdata_U8;
				}
				else
				{
					fl_data_U8 &= fl_start_mask_U8;
					fl_data_U8 += fl_bmp_data_U8;
				}
				IMG_CP_OP(FB(fl_fb_U8AP, fl_count_U16, layer), fl_data_U8);
			}
			GFX_DRIVER_SCHED_WAIT();
		}
	}
}

#endif

