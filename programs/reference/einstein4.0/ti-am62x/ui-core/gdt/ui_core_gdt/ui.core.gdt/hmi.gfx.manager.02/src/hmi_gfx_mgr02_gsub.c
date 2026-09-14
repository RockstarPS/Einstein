/*=============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2012. Visteon Corporation owns all rights to this work and
 ** intends to maintain it in confidence to preserve its trade secret status.
 ** Visteon Corporation reserves the right, under the copyright laws of the
 ** United States or those of any other country that may have jurisdiction,
 ** to protect this work as an unpublished work, in the event of an
 ** inadvertent or deliberate unauthorized publication. Visteon Corporation
 ** also reserves its rights under all copyright laws to protect this work as
 ** a published work, when appropriate. Those having access to this work may
 ** not copy it, use it, modify it or disclose the information contained in
 ** it without the written authorization of Visteon Corporation.
 **
 **============================================================================
 **
 ** Name:           hmi_gfx_mgr02_gsub.c
 **
 ** Description:    Implements logic to process the GSUB table data provided IGDT
 **                 autocode generation.
 **                 
 **
 ** Organization:   GUI Software Section, Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
#define HMI_GFX_MGR02_GSUB_C
/*=============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "hmi_gfx_mgr02_generic.h"
#ifdef GFX_MGR02_FONT_GSUB_TABLE_ENABLED
#include "hmi_gfx_mgr02_layout.h"
#include "hmi_gfx_mgr02_gsub.h"

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif

#define HMI_INVALID_CLASS_ID (0xFFFFU)
#define HMI_INVALID_SEQCLASS_ID (0xFFFFU)
#define HMI_MAX_CLASSES      (15U)

#define HMI_FORMAT1          (1U)
#define HMI_FORMAT2          (2U)
#define HMI_FORMAT3          (3U)


static HMI_FONT_GSUB_LIG_SET_TABLE const * hmi_gfx_mgr02_gsub_find_lig_table(HMI_CHAR p_start_code, UINT16 p_num_gsub, HMI_FONT_GSUB_LIG_SET_TABLE const * p_gsub);
static UINT16 hmi_gfx_mgr02_gsub_do_ligature_sub(HMI_FONT_GSUB_LIG_SET_TABLE const * p_gsub,
                                          UINT16 p_gsub_len,
                                          const HMI_CHAR * p_src_P,
                                          HMI_CHAR * p_dst_P,
                                          UINT16 p_length_U16);
static UINT16 hmi_gfx_mgr02_gsub_get_coverage_index(HMI_FONT_GSUB_COVERAGE const * fl_coverage_ptr, UINT16 fl_coverage_cnt, const HMI_CHAR * fl_src);
static UINT8 hmi_gfx_mgr02_gsub_check_coverage_id(const HMI_CHAR * p_src_P, HMI_FONT_GSUB_COVERAGE const * fl_coverage_ptr, UINT16 p_pos_cnt_u16);
static UINT8 hmi_gfx_mgr02_gsub_do_single_sub(HMI_FONT_GSUB_LOOKUP_TABLE const * p_lookup_table_ptr,
                                        const HMI_CHAR * p_src_P,
                                        HMI_CHAR * p_dst_P);
static UINT16 hmi_gfx_mgr02_gsub_do_chained_context_f3_sub(HMI_FONT_GSUB_LOOKUP_TABLE const * p_lookup_table_ptr,
	                                                       HMI_FONT_GSUB_CHAIN_SUBST3_TABLE const * p_gsub,
                                                           HMI_CHAR * p_src_P,
                                                           HMI_CHAR * p_dst_P);
static UINT16 hmi_gfx_mgr02_gsub_do_chained_context_f2_sub(UINT16 fl_lookup_id, HMI_FONT_GSUB_LOOKUP_TABLE const * p_master_lkp_table_ptr,UINT16 p_lookup_count,
                                                           const HMI_CHAR * p_src_P, HMI_CHAR * p_dst_P, const HMI_CHAR * p_act_src_P, HMI_FONT_GSUB_CC_OUT *p_cc_outputs);
static UINT16 hmi_gfx_mgr02_gsub_do_context_sub(UINT16 fl_lookup_id, HMI_FONT_GSUB_LOOKUP_TABLE const * p_master_lkp_table_ptr,UINT16 p_lookup_count,HMI_CHAR * p_src_P,HMI_CHAR * p_dst_P, HMI_FONT_GSUB_CC_OUT *p_cc_outputs);
static HMI_FONT_GSUB_SUB_CLASS_RULE  const * hmi_gfx_mgr02_gsub_get_seqclass(const UINT16 *p_classes, UINT16 p_match_cls_num, HMI_FONT_GSUB_SUB_CLASS_SET const *p_subClassPtr, UINT16 p_seqclassdef_count);
static UINT16 hmi_gfx_mgr02_gsub_get_class_id(const HMI_CHAR * p_src_P, HMI_FONT_GSUB_CLASSDEF const *p_class_def, UINT16 p_classdef_count);
static UINT16 hmi_gfx_mgr02_gsub_do_multiple_sub(HMI_FONT_GSUB_LOOKUP_TABLE const * p_lookup_table_ptr,
                                        const HMI_CHAR * p_src_P,
                                        HMI_CHAR * p_dst_P);
static void hmi_gfx_mgr02_gsub_process_lkup_table(HMI_FONT_GSUB_LOOKUP_TABLE const * fl_lookup_table_ptr, UINT16 fl_lookup_id,UINT16 p_lookup_count, HMI_CHAR * p_src_P, HMI_CHAR * p_dst_P);
static UINT8 hmi_gfx_mgr02_gsub_validate_lkup(const HMI_GFX_DEVN_REORDER_INFO * p_reoder_info_SP, UINT16 p_script_list, UINT16 p_lookup_id);


/*============================================================================
** Function Name:    hmi_gfx_mgr02_gsub_find_lig_table
** Visibility:       global
** Description:      Interface to find the ligature table
** Invocation:       Internal
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          01-Jun-2016 by CSAKTHIV
** Updated:          
**==========================================================================*/
static HMI_FONT_GSUB_LIG_SET_TABLE const * hmi_gfx_mgr02_gsub_find_lig_table(HMI_CHAR p_start_code, UINT16 p_num_gsub, HMI_FONT_GSUB_LIG_SET_TABLE const * p_gsub)
{
   UINT16 fl_low_U16  = 0;
   UINT16 fl_mid_U16  = 0;
   UINT16 fl_high_U16 = p_num_gsub-1U;
   HMI_FONT_GSUB_LIG_SET_TABLE const * fl_gsub = GFX_MGR02_NULL_PTR;
   UINT16 fl_tablecharcode_U16;

   if((p_num_gsub>fl_high_U16)&&(p_num_gsub>fl_low_U16))
   {
     if((p_start_code <= p_gsub[fl_high_U16].start_code) && (p_start_code >= p_gsub[fl_low_U16].start_code))
     {
        /* Check for Character inside Table Boundary */
        for(;;)
        {  
         if(fl_mid_U16<p_num_gsub)
         {
           fl_tablecharcode_U16 = p_gsub[fl_mid_U16].start_code;

           if(p_start_code == fl_tablecharcode_U16)
           { 
               fl_gsub = &p_gsub[fl_mid_U16];
               break;
           }
           /* Vary the Lower and Upper indexes based on the incoming data */
           else if(p_start_code  < fl_tablecharcode_U16)
           {
              fl_high_U16 = fl_mid_U16-1U;	 /* decrement the Table High index value as per the Middle index value*/
           }
           else if(p_start_code > fl_tablecharcode_U16)
           {
              fl_low_U16 = fl_mid_U16+1U;		/* increment the Table Low index value as per the Middle index value */
           }
           else
           {
               /*For Fixing MISRA warning.*/
           }

           if(fl_low_U16 > fl_high_U16)
           {
              /*
              ** if the searched character is not found inside the
              ** Table, unsupported Character is returned
              */
              break;
           }
           else
           {
              /*
              ** calculate the new middle index value for the table
              */
              fl_mid_U16 = (fl_low_U16+fl_high_U16)/2U;
           }
         }			 
       }  
     }
   }
   return (fl_gsub);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_gsub_do_ligature_sub
** Visibility:       global
** Description:      Interface replace the glyph id with matching ligature id.
** Invocation:       Invoked by GDG02
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          01-Jun-2016 by CSAKTHIV
** Updated:          
**==========================================================================*/
static UINT16 hmi_gfx_mgr02_gsub_do_ligature_sub(HMI_FONT_GSUB_LIG_SET_TABLE const * p_gsub,
                                                 UINT16 p_gsub_len,
                                                 const HMI_CHAR * p_src_P,
                                                 HMI_CHAR * p_dst_P,
                                                 UINT16 p_length_U16)
{
   UINT16                          fl_num_lig;
   HMI_FONT_GSUB_LIG_TABLE const * fl_lig_tbl;
   UINT16                          fl_num_seq;
   HMI_CHAR                const * fl_seq;
   HMI_FONT_GSUB_LIG_SET_TABLE     const * fl_gsub;

   UINT16     fl_length_U16 = p_length_U16;
   const HMI_CHAR * fl_src_P      = p_src_P;
   HMI_CHAR * fl_dst_P      = p_dst_P;

   UINT16     fl_sub_len = 0;

   fl_gsub = hmi_gfx_mgr02_gsub_find_lig_table(fl_src_P[0], p_gsub_len, p_gsub);

   if(fl_gsub != GFX_MGR02_NULL_PTR)
   {
      fl_num_lig = fl_gsub->num_ligatures;
      fl_lig_tbl = fl_gsub->p_ligature;
      while(fl_num_lig>0U)
      {
         fl_num_seq = 1U;
         fl_seq     = fl_lig_tbl->seq;
         if(fl_length_U16 >= fl_lig_tbl->num_seq)
         {
            while(fl_num_seq <= fl_lig_tbl->num_seq)
            {
               if(fl_src_P[fl_num_seq] == *fl_seq)
               {
                  fl_num_seq++;
                  fl_seq++;
               }
               else
               {
                  break;
               }
            }
            if(fl_num_seq > fl_lig_tbl->num_seq)
            {
               *fl_dst_P   = fl_lig_tbl->ligature;
                fl_sub_len = fl_lig_tbl->num_seq;
                break;
            }
         }
         fl_lig_tbl++;
         fl_num_lig--;
      }
   }
   return(fl_sub_len);
}
/*============================================================================
** Function Name:    hmi_gfx_mgr02_gsub_get_coverage_index
** Visibility:       global
** Description:      Interface to process the GSUB table data.
** Invocation:       Invoked by layout
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          01-Jun-2016 by CSAKTHIV
** Updated:          
**==========================================================================*/
static UINT16 hmi_gfx_mgr02_gsub_get_coverage_index(HMI_FONT_GSUB_COVERAGE const * fl_coverage_ptr, UINT16 fl_coverage_cnt, const HMI_CHAR * fl_src)
{
   UINT16 i, fl_cov_id;
   HMI_CHAR const * fl_coverage_gid;
   fl_coverage_gid = fl_coverage_ptr->coverage_gids;	
   fl_cov_id = fl_coverage_cnt; 
   for(i =0; i < fl_coverage_cnt; i++)
   {
      if(*fl_coverage_gid == * fl_src)
	  {
	     fl_cov_id = i;
	     break;
      }
	  fl_coverage_gid++;
   }
   return fl_cov_id;
}
/*============================================================================
** Function Name:    hmi_gfx_mgr02_gsub_process
** Visibility:       global
** Description:      Interface to process the GSUB table data.
** Invocation:       Invoked by layout
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          01-Jun-2016 by CSAKTHIV
** Updated:          
**==========================================================================*/
static UINT8 hmi_gfx_mgr02_gsub_check_coverage_id(const HMI_CHAR * p_src_P, HMI_FONT_GSUB_COVERAGE const * fl_coverage_ptr, UINT16 p_pos_cnt_u16)
{
   
   UINT16  fl_cov_cnt_U16;
   HMI_CHAR const * fl_coverage_gid;
   UINT8   fl_glyph_match = (UINT8)FALSE;
   UINT16 fl_pos_cnt_u16 = p_pos_cnt_u16;
   const HMI_CHAR * fl_src_P = p_src_P;
   while(fl_pos_cnt_u16 != 0U)
   {
      fl_cov_cnt_U16  = fl_coverage_ptr->coverage_count;
      fl_coverage_gid = fl_coverage_ptr->coverage_gids;	
      while(fl_cov_cnt_U16 != 0U)
      {
          
     	 if(* fl_src_P == * fl_coverage_gid)
   	     {
   	        fl_glyph_match = TRUE;
   	        break;
   	     }
     	 else
     	 {
     	    fl_coverage_gid++;
     		fl_cov_cnt_U16--;
     	 }
      }
      if(fl_glyph_match ==TRUE)
      {
         /* check next position index is matching*/
   	     /* should match for all the position . so clearing to FALSE*/
		 fl_pos_cnt_u16--;
		 if(fl_pos_cnt_u16 != 0U)
		 {
   	        fl_glyph_match = FALSE;
   	        fl_coverage_gid++;
   	        fl_src_P++;
			fl_coverage_ptr++;
		 }
      }
      else
      {
         break; 
      } 
   }
   return fl_glyph_match;
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_gsub_do_single_sub
** Visibility:       global
** Description:      Interface replace the glyph id with matching id.
** Invocation:       Invoked by GDG02
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          18-Jan-2018 by KKUBENDI
** Updated:          
**==========================================================================*/
static UINT8 hmi_gfx_mgr02_gsub_do_single_sub(HMI_FONT_GSUB_LOOKUP_TABLE const * p_lookup_table_ptr,
                                        const HMI_CHAR * p_src_P,
                                        HMI_CHAR * p_dst_P)
{
   const HMI_CHAR * fl_src_P      = p_src_P;
   HMI_CHAR * fl_dst_P      = p_dst_P;
   UINT8   fl_glyph_match = FALSE;      
   HMI_FONT_GSUB_LOOKUP_TABLE const * fl_lookup_table_ptr = p_lookup_table_ptr;
   HMI_FONT_GSUB_COVERAGE const * fl_coverage_ptr;
   UINT16    fl_coverage_id;
   HMI_CHAR const * fl_susbt_id_ptr;   
  if(fl_lookup_table_ptr->type == 1U)
  {
    if(fl_lookup_table_ptr->subtable->format == 1U)
    {
      /* delta glyph id */
      UINT16 fl_delta_glyph_id;
      HMI_FONT_GSUB_SINGLE_SUBST1_TABLE const * fl_single_subt_ptr;
      fl_single_subt_ptr = (HMI_FONT_GSUB_SINGLE_SUBST1_TABLE  const *)fl_lookup_table_ptr->subtable->val.single_subst1;
      fl_delta_glyph_id = fl_single_subt_ptr->single_sbt1_delta_glyph_id;
      fl_coverage_ptr = fl_single_subt_ptr->single_sbt1_input_gid;
      fl_coverage_id = hmi_gfx_mgr02_gsub_get_coverage_index(fl_coverage_ptr,fl_coverage_ptr->coverage_count,fl_src_P);
      if(fl_coverage_id != fl_coverage_ptr->coverage_count)
      {
        * fl_dst_P = fl_single_subt_ptr->single_sbt1_input_gid->coverage_gids[fl_coverage_id] + fl_delta_glyph_id;
        fl_glyph_match = TRUE;
      }
    }
    else if(fl_lookup_table_ptr->subtable->format == 2U)
    {
      HMI_FONT_GSUB_SINGLE_SUBST2_TABLE const * fl_single_subt_ptr;
      fl_single_subt_ptr = (HMI_FONT_GSUB_SINGLE_SUBST2_TABLE  const *)fl_lookup_table_ptr->subtable->val.single_subst2;
      fl_coverage_ptr = fl_single_subt_ptr->single_sbt2_input_gid;
      fl_coverage_id = hmi_gfx_mgr02_gsub_get_coverage_index(fl_coverage_ptr,fl_coverage_ptr->coverage_count,fl_src_P);
      if(fl_coverage_id != fl_coverage_ptr->coverage_count)
      {
        /* valid coverage index */
        fl_susbt_id_ptr = &fl_single_subt_ptr->single_sbt2_subst_gid[fl_coverage_id];
        /* susbt the new glyph id */
        * fl_dst_P = * fl_susbt_id_ptr;
        fl_glyph_match = TRUE;
      }
    }
    else{
    	/*For Fixing MISRA warning.*/
    }
  }
  return fl_glyph_match;
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_gsub_do_chained_context_f3_sub
** Visibility:       global
** Description:      Interface replace the glyph id with matching ligature id.
** Invocation:       Invoked by GDG02
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          01-Jun-2016 by CSAKTHIV
** Updated:          
**==========================================================================*/
static UINT16 hmi_gfx_mgr02_gsub_do_chained_context_f3_sub(HMI_FONT_GSUB_LOOKUP_TABLE const * p_lookup_table_ptr,
	                                                       HMI_FONT_GSUB_CHAIN_SUBST3_TABLE const * p_gsub,
                                                           HMI_CHAR * p_src_P,
                                                           HMI_CHAR * p_dst_P)
{

   
   HMI_CHAR * fl_src_P      = p_src_P;
   HMI_CHAR * fl_dst_P      = p_dst_P;
   UINT16     fl_sub_len = 0;
   UINT8      fl_input_match_U8;
   UINT8      fl_backtrack_match_U8;
   UINT8      fl_lookahead_match_U8;
   UINT16     fl_count_U16,i;
   UINT16    fl_coverage_id;
   HMI_FONT_GSUB_LOOKUP_TABLE const * fl_lookup_table_ptr;

   HMI_FONT_GSUB_COVERAGE const * fl_coverage_ptr = p_gsub->input_coverage;
   fl_input_match_U8  = hmi_gfx_mgr02_gsub_check_coverage_id(fl_src_P,p_gsub->input_coverage, p_gsub->inputglyphcount);
   if(fl_input_match_U8 == TRUE)
   {
      if(p_gsub->backtrackglyphcount != 0U)
	  {
         /*if all input glyphs in all position matches, then proceed for backtrack sequence*/
	     fl_src_P = p_src_P;
	     fl_count_U16 = p_gsub->backtrackglyphcount;
	     fl_src_P = fl_src_P - fl_count_U16; 
         fl_coverage_ptr = p_gsub->backtrack_coverage;
	     fl_backtrack_match_U8  = hmi_gfx_mgr02_gsub_check_coverage_id(fl_src_P,fl_coverage_ptr, fl_count_U16);
	  }
	  else
	  {
		 fl_backtrack_match_U8 = TRUE;
      }
	  if(fl_backtrack_match_U8 == TRUE)
	  {
	     if(p_gsub->lookheadglyphcount != 0U)
		 {
            /*if all input glyphs in all position matches, then proceed for backtrack sequence*/
	        fl_src_P = p_src_P;
	        fl_src_P = fl_src_P + p_gsub->inputglyphcount; 
	        fl_lookahead_match_U8  = hmi_gfx_mgr02_gsub_check_coverage_id(fl_src_P,p_gsub->lookhead_coverage, p_gsub->lookheadglyphcount);
		 }
		 else
		 {
			fl_lookahead_match_U8 = TRUE;
         }
	  }
   }
   if((fl_input_match_U8 == TRUE)&&(fl_backtrack_match_U8 == TRUE)&&(fl_lookahead_match_U8 == TRUE))
   {
      HMI_FONT_GSUB_SUBST_LOOKUP_RECORD const * fl_subst_lookup_rec_ptr = p_gsub->substlookuprec;

	  HMI_CHAR const * fl_susbt_id_ptr;
	  UINT16 fl_subst_count = p_gsub->substcount;

      /* Proceed with subtitution table*/
	  fl_src_P = p_src_P;
	  fl_dst_P = p_dst_P;
	  for(i = 0; i < p_gsub->inputglyphcount; i++)
	  {
		  *fl_dst_P = *fl_src_P;
		   fl_src_P++;
		   fl_dst_P++;
	  }

	  while(fl_subst_count != 0U)
	  {
		  fl_src_P = p_src_P;
		  fl_dst_P = p_dst_P;
		  fl_src_P = fl_src_P + fl_subst_lookup_rec_ptr->sequence_id;
		  fl_dst_P = fl_dst_P + fl_subst_lookup_rec_ptr->sequence_id;
		  fl_lookup_table_ptr = &p_lookup_table_ptr[fl_subst_lookup_rec_ptr->lookup_id];
		  if(fl_lookup_table_ptr->type == 1U)

		  {
			  if(fl_lookup_table_ptr->subtable->format == 1U)
			  {
				  /* delta glyph id*/
				  UINT16 fl_delta_glyph_id;
			  	  HMI_FONT_GSUB_SINGLE_SUBST1_TABLE const * fl_single_subt_ptr;
				  fl_single_subt_ptr = (HMI_FONT_GSUB_SINGLE_SUBST1_TABLE  const *)fl_lookup_table_ptr->subtable->val.single_subst1;
				  fl_delta_glyph_id = fl_single_subt_ptr->single_sbt1_delta_glyph_id;
  				  fl_coverage_ptr = fl_single_subt_ptr->single_sbt1_input_gid;
  				  fl_coverage_id = hmi_gfx_mgr02_gsub_get_coverage_index(fl_coverage_ptr,fl_coverage_ptr->coverage_count,fl_src_P);
				  if(fl_coverage_id != fl_coverage_ptr->coverage_count)
				  {
				     * fl_dst_P = fl_single_subt_ptr->single_sbt1_input_gid->coverage_gids[fl_coverage_id] + fl_delta_glyph_id;
				  }
			  }
			  else if(fl_lookup_table_ptr->subtable->format == 2U)
			  {
			  	  HMI_FONT_GSUB_SINGLE_SUBST2_TABLE const * fl_single_subt_ptr;
				  fl_single_subt_ptr = (HMI_FONT_GSUB_SINGLE_SUBST2_TABLE  const *)fl_lookup_table_ptr->subtable->val.single_subst2;
				  fl_coverage_ptr = fl_single_subt_ptr->single_sbt2_input_gid;
				  fl_coverage_id = hmi_gfx_mgr02_gsub_get_coverage_index(fl_coverage_ptr,fl_coverage_ptr->coverage_count,fl_src_P);
				  if(fl_coverage_id != fl_coverage_ptr->coverage_count)
				  {
					  /* valid coverage index*/
					  fl_susbt_id_ptr = &fl_single_subt_ptr->single_sbt2_subst_gid[fl_coverage_id];
					  /* susbt the new glyph id*/
					  * fl_dst_P = * fl_susbt_id_ptr;
				  }
              }
              else
              {
                /*MISRA.IF.NO_ELSE fix*/
              }
		  }
		  else if(fl_lookup_table_ptr->type == LIGATURE)
          {
	          UINT16   fl_length_U16;
              UINT16   fl_ch_index;

              fl_length_U16 = (UINT16)wcslen(fl_src_P);
		      fl_length_U16--;
              fl_ch_index = hmi_gfx_mgr02_gsub_do_ligature_sub(fl_lookup_table_ptr->subtable->val.lig->gsub,
						                                               fl_lookup_table_ptr->subtable->val.lig->num_gsub,
																       fl_src_P, fl_dst_P,fl_length_U16);
              if(fl_ch_index > 0U)
    	      {
    	         fl_src_P = &fl_src_P[fl_ch_index+1U];
			     fl_dst_P = &fl_dst_P[fl_ch_index];
				 while(*fl_src_P != 0U)
				 {
                    *fl_dst_P++ = *fl_src_P++;
				 }
				*fl_dst_P = 0U;
    	      }
    	      else
    	      {
                 *fl_dst_P = *fl_src_P++;
			      fl_dst_P++;
    	      }    	              
		  }
		  else
          {
            /*MISRA.IF.NO_ELSE fix*/
          }
		  fl_subst_count--;
		  fl_subst_lookup_rec_ptr++;
	  }
	  fl_sub_len = 	p_gsub->inputglyphcount;
   }
   return fl_sub_len;
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_gsub_do_chained_context_f2_sub
** Visibility:       global
** Description:      Interface to substitute the glyphs with the CCS-F2.
** Invocation:       Invoked by GDG02
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          25-Oct-2019 by SBOLLAM
** Updated:          
**==========================================================================*/
static UINT16 hmi_gfx_mgr02_gsub_do_chained_context_f2_sub(UINT16 fl_lookup_id, HMI_FONT_GSUB_LOOKUP_TABLE const * p_master_lkp_table_ptr,UINT16 p_lookup_count,
                                                           const HMI_CHAR * p_src_P, HMI_CHAR * p_dst_P, const HMI_CHAR * p_act_src_P, HMI_FONT_GSUB_CC_OUT *p_cc_outputs)
{

   const HMI_CHAR * fl_src_P      = p_src_P;
   HMI_CHAR * fl_dst_P      = p_dst_P;
   UINT8      fl_input_match_U8 = (UINT8)FALSE;
   UINT16    fl_coverage_id;
   UINT16    fl_context_glpyhs_count = 1U;
   UINT16    fl_dst_incr_glpyhs_count = 1U;
   if(fl_lookup_id<p_lookup_count)
   {
	   HMI_FONT_GSUB_LOOKUP_TABLE const * p_lookup_table_ptr = &p_master_lkp_table_ptr[fl_lookup_id];
	   HMI_FONT_GSUB_CHAIN_SUBST2_TABLE const * p_gsub = (HMI_FONT_GSUB_CHAIN_SUBST2_TABLE const *)p_lookup_table_ptr->subtable->val.chain_subst2;

	   HMI_FONT_GSUB_COVERAGE const * fl_coverage_ptr = p_gsub->input_coverage;
	   fl_coverage_id  = hmi_gfx_mgr02_gsub_get_coverage_index(fl_coverage_ptr, fl_coverage_ptr->coverage_count,fl_src_P);
	   if(fl_coverage_id != fl_coverage_ptr->coverage_count)
	   {
	     fl_input_match_U8 = (UINT8)TRUE;
	   }
	   if(fl_input_match_U8 == (UINT8)TRUE)
	   {
	     /*if coverage gid matches then check for the input clases*/
	     UINT16 fl_bktrack_class = HMI_INVALID_CLASS_ID;
	     UINT16 fl_ip_classe = HMI_INVALID_CLASS_ID;
	     UINT16 fl_la_class = HMI_INVALID_CLASS_ID;
	     HMI_FONT_GSUB_INPUT_CLASSDEF const *fl_ip_classDef;
	     HMI_FONT_GSUB_BKTRACK_CLASSDEF const *fl_bktrk_classDef;
	     HMI_FONT_GSUB_LA_CLASSDEF const *fl_la_classDef;

	     fl_src_P = p_src_P;
	     /* If current glyph matches with any of the coverage glyph then get 
	     ** the current glyph input class
	     */
	     fl_ip_classDef = &p_gsub->IP_classDef[0];
	     if(fl_ip_classDef->format == HMI_FORMAT1)
	     {
	       /* Check whether input glyph matches, generally if glyph matches with coverage
	       ** then it should definitely matches with any of the input glyphs list
	       */
	       if(fl_ip_classDef->startglyph == *fl_src_P)
	       {
	         HMI_FONT_GSUB_SEQ const *fl_input_cls_ptr = (HMI_FONT_GSUB_SEQ const *)&fl_ip_classDef->val.input_seq[0];
	         fl_ip_classe = fl_input_cls_ptr->ClassValue;

			 /* coverity warning fix */
			 if(fl_ip_classe != HMI_INVALID_CLASS_ID)
	         {
	           fl_input_match_U8 = (UINT8)TRUE;
	         }
	         else
	         {
			   /* input doesn't matches with current glyph then skip further process */
	           fl_input_match_U8 = (UINT8)FALSE;
	         }
	       }
	       else
	       {
			 /* input doesn't matches with current glyph then skip further process */
	         fl_input_match_U8 = (UINT8)FALSE;
	       }
	     }
	     else if(fl_ip_classDef->format == HMI_FORMAT2)
	     {
	       fl_ip_classe = hmi_gfx_mgr02_gsub_get_class_id(fl_src_P,(HMI_FONT_GSUB_CLASSDEF const *)fl_ip_classDef->val.range_rec,fl_ip_classDef->Count);
	       if(fl_ip_classe != HMI_INVALID_CLASS_ID)
	       {
	         fl_input_match_U8 = (UINT8)TRUE;
	       }
	       else
	       {
	         fl_input_match_U8 = (UINT8)FALSE;
	        /* input doesn't matches with current glyph then skip further process */
	       }
	     }
	     else
	     {
	       /* Do nothing */
	     }
        
	     if(fl_input_match_U8 == (UINT8)TRUE)
	     {
	       /* We here that means coverage and input glyphs are matches */
	        fl_src_P = p_src_P;
	        fl_bktrk_classDef = &p_gsub->bktrack_classDef[0];

	        /* Just make ensure while decrementing source pointer that it should not be the 
	        ** first character from the actual source string pointer
	        */
	        if(fl_src_P != p_act_src_P)
	        {
	            fl_src_P--;
	            if(fl_bktrk_classDef->format == HMI_FORMAT1)
	            {
	              /* Check whether input glyph matches, generally if glyph matches with coverage
	              ** then it should definitely matches with any of the input glyphs list
	              */
	               if(fl_ip_classDef->startglyph == *fl_src_P)
	               {
	                 HMI_FONT_GSUB_SEQ const *fl_bkt_cls_ptr = (HMI_FONT_GSUB_SEQ const *)&fl_bktrk_classDef->val.bktrack_seq[0];
	                 fl_input_match_U8 = (UINT8)TRUE;
	                 fl_bktrack_class = fl_bkt_cls_ptr->ClassValue;
	               }
	               else
	               {
	                 fl_input_match_U8 = (UINT8)FALSE;
	                  /* None of the input glyph's are matches with Backtrack list of glyphs */
	               }
	            }
	            else if(fl_bktrk_classDef->format == HMI_FORMAT2)
	            {
	              fl_bktrack_class = hmi_gfx_mgr02_gsub_get_class_id(fl_src_P,(HMI_FONT_GSUB_CLASSDEF const *)fl_bktrk_classDef->val.range_rec,fl_bktrk_classDef->Count);
	              if(fl_bktrack_class != HMI_INVALID_CLASS_ID)
	              {
	                fl_input_match_U8 = (UINT8)TRUE;
	              }
	              else
	              {
	                fl_input_match_U8 = (UINT8)FALSE;
	                /* None of the input glyph's are matches with Backtrack list of glyphs */
	              }
	            }
	            else
	            {
	              /* Do nothing */
	            }
	        }
	        if(fl_input_match_U8 == (UINT8)FALSE)
	        {
	          #if defined(GFX_GSUB_DEBUG)
	             printf("Found the matching coverage and input but doesn't found the matching glyph in back track list");
	          #endif
	        }

	        {
	            /* Now check any glyphs are matches in look ahead list of 
	            ** glyphs, if matches then get its class type
	            */
	            fl_src_P = p_src_P;
	            fl_la_classDef = &p_gsub->la_classDef[0];

	            fl_src_P++;
	            if(fl_la_classDef->format == HMI_FORMAT1)
	            {
	              /* Check whether input glyph matches, generally if glyph matches with coverage
	              ** then it should definitely matches with any of the input glyphs list
	              */
	               if(fl_la_classDef->startglyph == *fl_src_P)
	               {
	                 HMI_FONT_GSUB_SEQ const *fl_la_cls_ptr = (HMI_FONT_GSUB_SEQ const *)&fl_la_classDef->val.look_ahead_seq[0];
	                 fl_input_match_U8 = (UINT8)TRUE;
	                 fl_la_class = fl_la_cls_ptr->ClassValue;
	               }
	               else
	               {
	                 fl_input_match_U8 = (UINT8)FALSE;
	                  /* None of the input glyph's are matches with LookAhead list of glyphs */
	               }
	            }
	            else if(fl_la_classDef->format == HMI_FORMAT2)
	            {
	              fl_la_class = hmi_gfx_mgr02_gsub_get_class_id(fl_src_P,(HMI_FONT_GSUB_CLASSDEF const *)fl_la_classDef->val.range_rec,fl_la_classDef->Count);
	              if(fl_la_class != HMI_INVALID_CLASS_ID)
	              {
	                fl_input_match_U8 = (UINT8)TRUE;
	              }
	              else
	              {
	                fl_input_match_U8 = (UINT8)FALSE;
	                /* None of the input glyph's are matches with LookAhead list of glyphs */
	              }
	            }
	            else
	            {
	              /* Do nothing */
	            }
	        }
	        if(fl_input_match_U8 == (UINT8)FALSE)
	        {
	          #if defined(GFX_GSUB_DEBUG)
	             printf("Found the matching coverage, input and back track but doesn't found the matching glyph in look ahead list");
	          #endif
	        }

	        {
	          /* Done with finding classess for input, backtrack and look ahead
	          ** Now check which classes sequences are matching with 
	          ** lookup substitution tables
	          */
	          UINT8 fl_final_match = (UINT8)FALSE;
	          UINT16 fl_final_index1 = 0xFFU;
	          HMI_FONT_GSUB_CHAIN_SUBCLASS_SET const *fl_lkup_sub_ptr = &p_gsub->subclassDef[0];
	          HMI_FONT_GSUB_CHAIN_SUBCLASS_RULETABLE const *fl_class_rules_ptr;
	          HMI_FONT_GSUB_CHAIN_SUBCLASS_RULETABLE const *fl_final_class_rules_ptr = GFX_MGR02_NULL_PTR;
	          UINT16 index1,index2;
	          for(index1=0U; index1<fl_lkup_sub_ptr->chainSubClassRuleCount; index1++)
	          {
	             fl_class_rules_ptr = &fl_lkup_sub_ptr->ruleTable[index1];
	             if((fl_bktrack_class ==  HMI_INVALID_CLASS_ID) && (fl_class_rules_ptr->backtrackseq == NULL))
	             {
	               fl_final_match = (UINT8)TRUE;
	               fl_final_index1 = index1;
	             }
	             else
	             {
	                 HMI_FONT_GSUB_CHAIN_SUBCLASS_BKTRACK_SEQ  const *fl_backtrackseq = fl_class_rules_ptr->backtrackseq;
	                 for(index2=0U; index2<fl_class_rules_ptr->backtrackGlyphCount; index2++)
	                 {
	                   if(fl_bktrack_class == fl_backtrackseq[index2].backtrackglyph)
	                   {
	                     /* Found matching class sequence in back track */
	                     fl_final_match = (UINT8)TRUE;
	                     fl_final_index1 = index1;
	                     break;
	                   }
	                 }
	             }
	             if(fl_final_match == (UINT8)TRUE){
	               break;
	             }
	          }
	          /* By default input class will 1 so we are not checking it */

              if(fl_final_match == (UINT8)TRUE)
              {  
                 if(fl_final_index1<(fl_lkup_sub_ptr->chainSubClassRuleCount))
                   {  
                     fl_final_match = (UINT8)FALSE;
                     /* Generally whichever backtrack class sequence matches in the class rules, 
                     ** with the same index class rule index lookahead class sequence will be matches
                     */ 
                     fl_class_rules_ptr = &fl_lkup_sub_ptr->ruleTable[fl_final_index1];
                     /* Now let's check for matching look ahead class sequence */
                     if((fl_la_class ==  HMI_INVALID_CLASS_ID) && (fl_class_rules_ptr->lookaheadSeq == NULL))
                     {
                       fl_final_match = (UINT8)TRUE;
                     }
                     else
                     {
                        HMI_FONT_GSUB_CHAIN_SUBCLASS_LOOKAHEAD_SEQ const *fl_lookaheadSeq = fl_class_rules_ptr->lookaheadSeq;
                        for(index2=0U; index2<fl_class_rules_ptr->lookaheadGlyphCount; index2++)
                        {
                          if(fl_la_class == fl_lookaheadSeq[index2].lookaheadglyph)
                          {
                            /* Found matching class sequence in look ahead */
                            fl_final_match = (UINT8)TRUE;
                            break;
                          }
                        }
                     }
                   }
              }
              else
	          {
	           #if defined(GFX_GSUB_DEBUG)
	              printf("Found the all matching coverage, input and back track,look ahead but doesn't found the matching back track class sequence ");
	           #endif 
	          }
	          if(fl_final_match == (UINT8)TRUE)
	          {
	            /*If found all the sequences backtrack, input and look ahead sequence
	            ** then take class rule pointer and apply its corresponding 
	            ** lookup table
	            */
                if(fl_final_index1<fl_lkup_sub_ptr->chainSubClassRuleCount)
                {
	              fl_final_class_rules_ptr = &fl_lkup_sub_ptr->ruleTable[fl_final_index1];
			    }
	          }
	          if(fl_final_class_rules_ptr != GFX_MGR02_NULL_PTR)
	          {
	             /* Finally found the matching class sequence rule now apply substitution lookup table at here */
	              UINT8 fl_total_sub_counts = (UINT8)fl_final_class_rules_ptr->substitutionCount;
	              HMI_FONT_GSUB_SUBST_LOOKUP_RECORD const *fl_substlookuprec = fl_final_class_rules_ptr->substlookuprec;
	              UINT8 fl_sub_rec_index;
	              UINT16 fl_prev_sub_index = 0xFFU;

	              /* fl_src pointer in calle function to be incremented with "fl_context_glpyhs_count" value */
	              /* Here 2 means = 1 (current/input glyph position) + 1(Look ahead glyph position)*/
	              fl_context_glpyhs_count = fl_total_sub_counts;
	              fl_dst_incr_glpyhs_count = fl_context_glpyhs_count;
	              fl_src_P = p_src_P;
	              for(fl_sub_rec_index=0; fl_sub_rec_index<fl_total_sub_counts; fl_sub_rec_index++)
	              {
	                 /* fl_sub_index -- is the index(position) where exactly substituion should be occur */
	                 UINT16 fl_sub_index = fl_substlookuprec[fl_sub_rec_index].sequence_id;
	                 /* fl_lookup_index -- is the index for a lookupt table which needs to be apply at postion "fl_sub_index" */
	                 UINT16 fl_lookup_index = fl_substlookuprec[fl_sub_rec_index].lookup_id;
	                 UINT8   fl_glyph_match = (UINT8)FALSE;

	                   if((fl_sub_index != (fl_prev_sub_index+1U)) && (fl_prev_sub_index != 0xFFU))
	                   {
	                      /* ex: This case when context count 3, one sub record says position 0, and second
	                      **     sub record says at position 2, with this we substitution we can fill only
	                      **     0 and 2nd positions, here 1st position is missing in the destination
	                      **     string, so below logic is to fill these gaps
	                      */
	                      UINT16 fl_temp_index = fl_prev_sub_index+1U;
	                      while(fl_temp_index < fl_sub_index)
	                      {
	                        *fl_dst_P++ = fl_src_P[fl_temp_index];
	                        fl_temp_index++;
	                      }
	                   }
	                   else if((fl_input_match_U8 == (UINT8)FALSE) && (fl_sub_rec_index < (fl_total_sub_counts - 1U)))
	                   {
	                      /* There are more than one sub record found but doesn't found the matching glyphs in coverage
	                      ** of one of the sub record lookup, so fill this as well
	                      */
	                       *fl_dst_P++ = fl_src_P[fl_sub_index];
	                   }
	                   else
	                   {
	                      /* Do nothing */
	                   }
	                   fl_prev_sub_index = fl_sub_index;
                       if(fl_lookup_index<p_lookup_count)
                       { 
                         p_lookup_table_ptr = &p_master_lkp_table_ptr[fl_lookup_index];

                         if(p_lookup_table_ptr->type == (UINT16)SINGLE)
                         {
                            fl_glyph_match = (UINT8)hmi_gfx_mgr02_gsub_do_single_sub(p_lookup_table_ptr,&fl_src_P[fl_sub_index], fl_dst_P);
                            if(fl_glyph_match==(UINT8)FALSE)
                            {
                              /* Doesn't found matching glyph in coverage table */
                              fl_input_match_U8 = (UINT8)FALSE;
                            #if defined(GFX_GSUB_DEBUG)
                              printf("Found the all matching coverage, input and back track,look ahead and its corresponding class rule but doesn't found the matching glyph in substitution coverage");
                            #endif
                            }
                            else
                            {
                              fl_dst_P++;
                              fl_input_match_U8 = (UINT8)TRUE;
                            }
                         }
                         else if(p_lookup_table_ptr->type == (UINT16)MULTIPLE)
                         {
                            fl_glyph_match = (UINT8)hmi_gfx_mgr02_gsub_do_multiple_sub(p_lookup_table_ptr,&fl_src_P[fl_sub_index], fl_dst_P);
                            if(fl_glyph_match != (UINT8)FALSE)
                            {
                              fl_dst_P += fl_glyph_match;
                              if(fl_glyph_match > 1U)
                              {
                                /* Already added context glyphs count to "fl_context_glpyhs_count", but in addition 
                                ** to that if multiple substute counti more than 1 then need add this value to  
                                ** "fl_context_glpyhs_count" so that both src and dst pointers will be in sync
                                */
                                fl_dst_incr_glpyhs_count += ((UINT16)fl_glyph_match-1U);
                              }
                              fl_input_match_U8 = (UINT8)TRUE;
                            }
                            else
                            {
                              /* Doesn't found matching glyph in coverage table */
                               fl_input_match_U8 = (UINT8)FALSE;
                              #if defined(GFX_GSUB_DEBUG)
                                printf("Found the all matching coverage, input and back track,look ahead and its corresponding class rule but doesn't found the matching glyph in substitution coverage");
                              #endif
                            }
                         }     
                         else
                         {
                         /* Do nothing */
                         }
                       }
	              }
	              if(fl_input_match_U8 == (UINT8)TRUE)
	              {
	                p_cc_outputs->src_ptr_inc_val = fl_context_glpyhs_count; /* src string pointer increment value*/
	                p_cc_outputs->dst_ptr_inc_val = fl_dst_incr_glpyhs_count; /* dst string pointer increment value*/
	              }
	              else
	              {
	                p_cc_outputs->src_ptr_inc_val = 1U; /* Default increment */
	                p_cc_outputs->dst_ptr_inc_val = 1U; /* Default increment */
	              }
	          }
	          else
	          {
	            fl_input_match_U8 = (UINT8)FALSE;
	           #if defined(GFX_GSUB_DEBUG)
	             printf("Found the classes for backtrack,input and look ahead but doesn't found the matching sequence classes in class rules");
	           #endif
	          }
	        }

	     }
	     else
	     {
	       fl_input_match_U8 = (UINT8)FALSE;
	       #if defined(GFX_GSUB_DEBUG)
	         printf("Found the matching coverage but doesn't found the matching input");
	       #endif
	     }
	   }
	   else
	   {
	       fl_input_match_U8 = (UINT8)FALSE;
	       #if defined(GFX_GSUB_DEBUG)
	         printf("Doesn't found the matching coverage");
	       #endif
	   }
   }
   return (UINT16)fl_input_match_U8;
}


/*============================================================================
** Function Name:    hmi_gfx_mgr02_gsub_do_context_sub
** Visibility:       global
** Description:      Interface to replace the glyph id with matching context.
** Invocation:       Invoked by ---
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          10-Oct-2019 by SBOLLAM
** Updated:          
**==========================================================================*/
static UINT16 hmi_gfx_mgr02_gsub_do_context_sub(UINT16 fl_lookup_id, HMI_FONT_GSUB_LOOKUP_TABLE const * p_master_lkp_table_ptr,UINT16 p_lookup_count,HMI_CHAR * p_src_P,HMI_CHAR * p_dst_P, HMI_FONT_GSUB_CC_OUT *p_cc_outputs)
{

   HMI_CHAR * fl_src_P      = p_src_P;
   HMI_CHAR * fl_dst_P      = p_dst_P;
   UINT8      fl_input_match_U8 = (UINT8)FALSE;
   UINT16     i;
   UINT16    fl_coverage_id;
   UINT16    fl_context_glpyhs_count = 1U;  
   UINT16    fl_dst_incr_glpyhs_count = 1U;
   if(fl_lookup_id<p_lookup_count)
   {
       HMI_FONT_GSUB_LOOKUP_TABLE const * p_lookup_table_ptr = &p_master_lkp_table_ptr[fl_lookup_id];
       HMI_FONT_GSUB_CONTEXT_SUBST2_TABLE const * p_gsub = (HMI_FONT_GSUB_CONTEXT_SUBST2_TABLE const *)p_lookup_table_ptr->subtable->val.context_subst2;
       HMI_FONT_GSUB_COVERAGE const * fl_coverage_ptr = p_gsub->input_coverage;
       fl_coverage_id  = hmi_gfx_mgr02_gsub_get_coverage_index(fl_coverage_ptr, fl_coverage_ptr->coverage_count,fl_src_P);
       if(fl_coverage_id != fl_coverage_ptr->coverage_count)
       {
         fl_input_match_U8 = (UINT8)TRUE;
       }
       if(fl_input_match_U8 == (UINT8)TRUE)
       {
         /*if coverage gid matches then check for the input clases*/
         UINT16 fl_length_U16;
         UINT16 fl_classes[HMI_MAX_CLASSES];
         UINT16 fl_class_index = 0U;
         UINT16 fl_class_id;
         fl_src_P = p_src_P;
         fl_length_U16 = (UINT16)wcslen(fl_src_P);

         /* In order avoid coverity warnings fill the bytes with 0xFF, since anyhow HMI_INVALID_CLASS_ID = 0xFFFF */
         (void)memset(fl_classes, 0xFF, (sizeof(UINT16)) * (HMI_MAX_CLASSES));
         for(i = 0U; i < fl_length_U16; i++)
         {
            /* For L-R scripts search the classes in a increment order, for R-L scripts it 
            ** should be in decrement order
            */
            fl_class_id = hmi_gfx_mgr02_gsub_get_class_id(fl_src_P,p_gsub->classDef,p_gsub->ClassdefCount);
            if(fl_class_id != HMI_INVALID_CLASS_ID)
            {
              fl_classes[fl_class_index++] = fl_class_id;
              fl_src_P++;
            }
            else
            {
              /* No further matches found, then go for class rules check */
              break;
            }
         }
         
         if(fl_class_index > 0U)
         {
           HMI_FONT_GSUB_SUB_CLASS_RULE  const * fl_subClassRulePtr = GFX_MGR02_NULL_PTR;
           
           while(fl_class_index > 0U)
           {
               fl_subClassRulePtr = hmi_gfx_mgr02_gsub_get_seqclass(&fl_classes[0U],fl_class_index, p_gsub->subClassPtr,p_gsub->subClassCount);
               if(fl_subClassRulePtr != GFX_MGR02_NULL_PTR)
               {
                  UINT8 fl_total_sub_counts = (UINT8)fl_subClassRulePtr->substitutionCount;
                  HMI_FONT_GSUB_SUBST_LOOKUP_RECORD const *fl_substlookuprec = fl_subClassRulePtr->substlookuprec;
                  UINT8 fl_sub_rec_index;
                  UINT16 fl_prev_sub_index = 0xFFU;

                  /* fl_src pointer in calle function to be incremented with "fl_context_glpyhs_count" value */
                  fl_context_glpyhs_count = fl_class_index;
                  fl_dst_incr_glpyhs_count = fl_context_glpyhs_count;
                  fl_src_P = p_src_P;
                  for(fl_sub_rec_index=0; fl_sub_rec_index<fl_total_sub_counts; fl_sub_rec_index++)
                  {
                     /* fl_sub_index -- is the index(position) where exactly substituion should be occur */
                     UINT16 fl_sub_index = fl_substlookuprec[fl_sub_rec_index].sequence_id;
                     /* fl_lookup_index -- is the index for a lookupt table which needs to be apply at postion "fl_sub_index" */
                     UINT16 fl_lookup_index = fl_substlookuprec[fl_sub_rec_index].lookup_id;
                     UINT8   fl_glyph_match = (UINT8)FALSE;


                       if((fl_sub_index != (fl_prev_sub_index+1U)) && (fl_prev_sub_index != 0xFFU))
                       {
                          /* ex: This case when context count 3, one sub record says position 0, and second
                          **     sub record says at position 2, with this we substitution we can fill only
                          **     0 and 2nd positions, here 1st position is missing in the destination
                          **     string, so below logic is to fill these gaps
                          */
                          UINT16 fl_temp_index = fl_prev_sub_index+1U;
                          while(fl_temp_index < fl_sub_index)
                          {
                            *fl_dst_P++ = fl_src_P[fl_temp_index];
                            fl_temp_index++;
                          }
                       }
                       else if((fl_input_match_U8 == (UINT8)FALSE) && (fl_sub_rec_index < (fl_total_sub_counts - 1U)))
                       {
                          /* There are more than one sub record found but doesn't found the matching glyphs in coverage
                          ** of one of the sub record lookup, so fill this as well
                          */
                           *fl_dst_P++ = fl_src_P[fl_sub_index];
                       }
                       else
                       {
                          /* Do nothing */
                       }
                       fl_prev_sub_index = fl_sub_index;

                       if(fl_lookup_index<p_lookup_count)
                       {
                         p_lookup_table_ptr = &p_master_lkp_table_ptr[fl_lookup_index];
                         

                         if(p_lookup_table_ptr->type ==(UINT16)CONTEXTC)
                         {
                            fl_input_match_U8 = (UINT8)hmi_gfx_mgr02_gsub_do_context_sub(fl_lookup_index,p_master_lkp_table_ptr,p_lookup_count,&fl_src_P[fl_sub_index], fl_dst_P, p_cc_outputs);
                            if(fl_input_match_U8 ==(UINT8)FALSE)
                            {
                               #if defined(GFX_GSUB_DEBUG)
                                printf("Found the matching class rules but doesn't find the glyphs in the coverage of the applied lookup table");
                              #endif
                            }
                         }
                         else if(p_lookup_table_ptr->type == (UINT16)SINGLE)
                         {
                            fl_glyph_match = (UINT8)hmi_gfx_mgr02_gsub_do_single_sub(p_lookup_table_ptr,&fl_src_P[fl_sub_index], fl_dst_P);
                            if(fl_glyph_match==(UINT8)FALSE)
                            {
                              /* Doesn't found matching glyph in coverage table */
                              fl_input_match_U8 = (UINT8)FALSE;
                            #if defined(GFX_GSUB_DEBUG)
                              printf("Found the matching class rules but doesn't find the glyphs in the coverage of the applied lookup table");
                            #endif
                            }
                            else
                            {
                              fl_dst_P++;
                              fl_input_match_U8 = (UINT8)TRUE;
                            }
                         }
                         else if(p_lookup_table_ptr->type == (UINT16)MULTIPLE)
                         {
                            fl_glyph_match = (UINT8)hmi_gfx_mgr02_gsub_do_multiple_sub(p_lookup_table_ptr,&fl_src_P[fl_sub_index], fl_dst_P);
                            if(fl_glyph_match != (UINT8)FALSE)
                            {
                              fl_dst_P += fl_glyph_match;
                              if(fl_glyph_match > 1U)
                              {
                                /* Already added context glyphs count to "fl_context_glpyhs_count", but in addition 
                                ** to that if multiple substute counti more than 1 then need add this value to  
                                ** "fl_context_glpyhs_count" so that both src and dst pointers will be in sync
                                */
                                fl_dst_incr_glpyhs_count += ((UINT16)fl_glyph_match-1U);
                              }
                              fl_input_match_U8 = (UINT8)TRUE;
                            }
                            else
                            {
                              /* Doesn't found matching glyph in coverage table */
                               fl_input_match_U8 = (UINT8)FALSE;
                              #if defined(GFX_GSUB_DEBUG)
                                printf("Found the matching class rules but doesn't find the glyphs in the coverage of the applied lookup table");
                              #endif
                            }
                         }     
                         else
                         {
                           /* Do nothing */
                         }
                       }
                  }
                  if(fl_input_match_U8 == (UINT8)TRUE)
                  {
                    p_cc_outputs->src_ptr_inc_val = fl_context_glpyhs_count; /* src string pointer increment value*/
                    p_cc_outputs->dst_ptr_inc_val = fl_dst_incr_glpyhs_count; /* dst string pointer increment value*/
                  }
                  else
                  {
                    p_cc_outputs->src_ptr_inc_val = 1U; /* Default increment */
                    p_cc_outputs->dst_ptr_inc_val = 1U; /* Default increment */
                  }
                  /* since we found the matching sequnce combination, come out of the while loop */
                  break;
                 
                }
                /* We are here because didn't found the matching class combinations set
                ** so make last class combination to invalid and try again
                */
                fl_classes[fl_class_index-1U] = 0xFFFFU;
                fl_class_index--;
             }
             if(fl_subClassRulePtr == GFX_MGR02_NULL_PTR)
             {
               /* Doesn't found matching sequence classes */
              fl_input_match_U8 = (UINT8)FALSE;
              #if defined(GFX_GSUB_DEBUG)
                 printf("Found the matching classes but doesn't fond the matching sequence classes in class rules");
              #endif
             }
         }
         else
         {
           /* Doesn't found matching classes */
           fl_input_match_U8 = (UINT8)FALSE;
           #if defined(GFX_GSUB_DEBUG)
             printf("Found the matching coverage but doesn't fond the matching classes");
           #endif
         }
       }
   }
   return (UINT16)fl_input_match_U8;  
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_gsub_get_seqclass
** Visibility:       global
** Description:      Interface to get the matching class sequence for an input
**                   class sequence
** Invocation:       Invoked by --
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          10-Oct-2019 by SBOLLAM
** Updated:          
**==========================================================================*/
static HMI_FONT_GSUB_SUB_CLASS_RULE  const * hmi_gfx_mgr02_gsub_get_seqclass(const UINT16 *p_classes, UINT16 p_match_cls_num, HMI_FONT_GSUB_SUB_CLASS_SET const *p_subClassPtr, UINT16 p_seqclassdef_count)
{
  UINT16 fl_index1,fl_index2;
  UINT16 fl_matched_class_cnt = p_match_cls_num-1U; /* By defatult class-1 matches,if input glyph is matches with coverage tables, hence -1*/
  UINT8  fl_cls_seq_match = (UINT8)FALSE;
  HMI_FONT_GSUB_SUB_CLASS_RULE  const * fl_ClassRulePtr_ret = GFX_MGR02_NULL_PTR;

  HMI_FONT_GSUB_SUB_CLASS_SET const *fl_subClass_ptr;
  for(fl_index1=0; fl_index1<p_seqclassdef_count; fl_index1++)
  {
    HMI_FONT_GSUB_SUB_CLASS_RULE  const * fl_subClassRulePtr;
    fl_subClass_ptr = &p_subClassPtr[fl_index1];
    for(fl_index2=0; fl_index2<fl_subClass_ptr->subClassRuleCount; fl_index2++)
    {
        fl_subClassRulePtr = &fl_subClass_ptr->subClassRuleOffsets[fl_index2];
      if(fl_subClassRulePtr->glyphCount == fl_matched_class_cnt)
      {
        /* if number of number of matched classes count with the input class rules count
        ** then whether clasess sequences order also matches with input class rules sequence
        */
        UINT16 fl_index3;
        fl_cls_seq_match = (UINT8)FALSE;
        for(fl_index3=0; fl_index3<fl_subClassRulePtr->glyphCount; fl_index3++)
        {
          if(p_classes[fl_index3+1U] == fl_subClassRulePtr->inputSequence[fl_index3])
          {
            fl_cls_seq_match = (UINT8)TRUE;
          }
          else
          {
            fl_cls_seq_match = (UINT8)FALSE;
            /* This is not the class sequence we are looking for*/
            break;
          }
        }
        if(fl_cls_seq_match != (UINT8)FALSE)
        {
           /* That's it we found the matchig input class sequence */
          fl_ClassRulePtr_ret = fl_subClassRulePtr;
          break; 
        }
      }
	  else if((fl_subClassRulePtr->glyphCount == 1U) && (fl_matched_class_cnt == 0U))
	  {
		  if(fl_subClassRulePtr->inputSequence[0] == 0U)
          {
            fl_cls_seq_match = (UINT8)TRUE;

			 /* That's it we found the matchig input class sequence */
             fl_ClassRulePtr_ret = fl_subClassRulePtr;
			 break;
          }
          else
          {
            fl_cls_seq_match = (UINT8)FALSE;
          }
	  }
	  else
	  {
		/* Do nothing */
	  }
    }
    if(fl_cls_seq_match != (UINT8)FALSE)
    {
      break;
    }
  }
  return fl_ClassRulePtr_ret;
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_gsub_get_class_id
** Visibility:       global
** Description:      Interface to get the matching class for an input char.
** Invocation:       Invoked by --
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          10-Oct-2019 by SBOLLAM
** Updated:          
**==========================================================================*/
static UINT16 hmi_gfx_mgr02_gsub_get_class_id(const HMI_CHAR * p_src_P, HMI_FONT_GSUB_CLASSDEF const *p_class_def, UINT16 p_classdef_count)
{
  UINT16 fl_index;
  UINT16 fl_class_ret = HMI_INVALID_CLASS_ID;

  for(fl_index=0; fl_index<p_classdef_count; fl_index++)
  {
    /*Check if the input char falls under below class */
    if((* p_src_P >= p_class_def[fl_index].startVal) && (* p_src_P <= p_class_def[fl_index].endVal))
    {
      fl_class_ret = p_class_def[fl_index].classVal;
      break;
    }
  }
  return fl_class_ret;
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_gsub_do_multiple_sub
** Visibility:       global
** Description:      Interface replace the glyph id with matching id.
** Invocation:       Invoked by GDG02
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          25-Jul-2018 by KKUBENDI
** Updated:          
**==========================================================================*/
static UINT16 hmi_gfx_mgr02_gsub_do_multiple_sub(HMI_FONT_GSUB_LOOKUP_TABLE const * p_lookup_table_ptr,
                                                 const HMI_CHAR * p_src_P,
                                                 HMI_CHAR * p_dst_P)
{
   const HMI_CHAR * fl_src_P = p_src_P;
   HMI_CHAR * fl_dst_P = p_dst_P;
   UINT16   fl_glyph_match = FALSE;      
   HMI_FONT_GSUB_LOOKUP_TABLE const * fl_lookup_table_ptr = p_lookup_table_ptr;
   HMI_FONT_GSUB_COVERAGE const * fl_coverage_ptr;
   UINT16    fl_coverage_id;
   UINT16     i;   
   if(fl_lookup_table_ptr->subtable->format == 1U)
   {
     HMI_FONT_GSUB_MULTIPLE_SUBST_TABLE const * fl_multiple_subst_ptr;
     fl_multiple_subst_ptr = (HMI_FONT_GSUB_MULTIPLE_SUBST_TABLE  const *)fl_lookup_table_ptr->subtable->val.multiple_subst;
     fl_coverage_ptr = fl_multiple_subst_ptr->input_coverage;
     fl_coverage_id = hmi_gfx_mgr02_gsub_get_coverage_index(fl_coverage_ptr,fl_coverage_ptr->coverage_count,fl_src_P);
     if(fl_coverage_id != fl_coverage_ptr->coverage_count)
     {
       if((fl_multiple_subst_ptr->subs_coverage->coverage_format == 1U) && (fl_multiple_subst_ptr->subs_coverage->coverage_count > 0U))
       {  
         for(i=0;i<fl_multiple_subst_ptr->subs_coverage->coverage_count;i++)
         {
           * fl_dst_P = fl_multiple_subst_ptr->subs_coverage->coverage_gids[i];
           fl_dst_P++;
         }
         fl_glyph_match = fl_multiple_subst_ptr->subs_coverage->coverage_count;
       }
     }
   }
   return fl_glyph_match;   
}
/*============================================================================
** Function Name:    hmi_gfx_mgr02_process_lkup_table
** Visibility:       global
** Description:      Interface to process the GSUB table data.
** Invocation:       Invoked by layout
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          01-Jun-2016 by CSAKTHIV
** Updated:          
**==========================================================================*/
static void hmi_gfx_mgr02_gsub_process_lkup_table(HMI_FONT_GSUB_LOOKUP_TABLE const * fl_lookup_table_ptr, UINT16 fl_lookup_id, UINT16 p_lookup_count, HMI_CHAR * p_src_P, HMI_CHAR * p_dst_P)
{

   UINT16     fl_length_U16 =0U;
   UINT16     fl_org_length_U16;   
   UINT16     fl_count_U16;
   UINT16     fl_index_U16=0U;
   HMI_CHAR   fl_ch_index;
   HMI_CHAR * fl_src_P      = p_src_P;
   HMI_CHAR * fl_dst_P      = p_dst_P;
   if(fl_lookup_id<p_lookup_count)
   {
	   HMI_FONT_GSUB_LOOKUP_TABLE const * fl_gsub_lookup_tbl = &fl_lookup_table_ptr[fl_lookup_id];

	   fl_length_U16 = (UINT16)wcslen(fl_src_P);
   

	   if(fl_gsub_lookup_tbl->type == (UINT16)LIGATURE)
	   {
	      while((*fl_src_P != 0U) && (fl_length_U16 > 0U))
	      {
	          fl_length_U16--;
			  fl_ch_index = hmi_gfx_mgr02_gsub_do_ligature_sub(fl_gsub_lookup_tbl->subtable->val.lig->gsub, 
				  fl_gsub_lookup_tbl->subtable->val.lig->num_gsub,
	    	  										           fl_src_P, fl_dst_P, fl_length_U16);
			  if(fl_ch_index>0U)
	    	  {
	    	     fl_src_P = &fl_src_P[fl_ch_index+1U];
	    	     fl_length_U16 -= fl_ch_index;
	    	  }
	    	  else
	    	  {
	             *fl_dst_P = *fl_src_P++;
	    	  }
	    	  fl_dst_P++;
	      }
	      *fl_dst_P = 0U;
	   }
	   else if(fl_gsub_lookup_tbl->type == (UINT16)CHAINING_CONTEXT)
	   {
	      if(fl_gsub_lookup_tbl->subtable->format == HMI_FORMAT3)
	      {
	          fl_count_U16 = fl_gsub_lookup_tbl->count;
	          while(fl_count_U16 > 0U)
	          {
				UINT16 fl_process_done = 0U;
	            fl_index_U16 = fl_gsub_lookup_tbl->count - fl_count_U16;	
	            fl_dst_P      = p_dst_P;
	            fl_org_length_U16 = (UINT16)wcslen(fl_src_P);
	            fl_length_U16 = fl_org_length_U16;
	            while((*fl_src_P != 0U) && (fl_length_U16 > 0U))
	            {
	              fl_process_done = hmi_gfx_mgr02_gsub_do_chained_context_f3_sub(fl_lookup_table_ptr,
	                                                                             &fl_gsub_lookup_tbl->subtable->val.chain_subst3[fl_index_U16],fl_src_P, fl_dst_P);
	                                                                             
				  if(fl_process_done != 0U)
				  {
	                /* increment to src & dst to next position where the chained look up table should be applied*/
	                fl_src_P = &fl_src_P[fl_gsub_lookup_tbl->subtable->val.chain_subst3[fl_index_U16].inputglyphcount];
	                fl_dst_P = &fl_dst_P[fl_gsub_lookup_tbl->subtable->val.chain_subst3[fl_index_U16].inputglyphcount];
				  }
				  else
				  {
					*fl_dst_P++ = *fl_src_P++;
				  }
	              if(fl_length_U16 >fl_gsub_lookup_tbl->subtable->val.chain_subst3[fl_index_U16].inputglyphcount)
	              {
	                fl_length_U16 =  fl_length_U16 - fl_gsub_lookup_tbl->subtable->val.chain_subst3[fl_index_U16].inputglyphcount;
	              }
	            }
				fl_src_P = p_dst_P;
	            fl_count_U16--;
	          }
	      }
	      else if(fl_gsub_lookup_tbl->subtable->format == HMI_FORMAT2)
	      {
	          HMI_FONT_GSUB_CC_OUT fl_cc_outputs;
      
	          fl_length_U16 = (UINT16)wcslen(fl_src_P);
	          while((*fl_src_P != 0U) && (fl_length_U16 > 0U))
	          {
	            fl_cc_outputs.src_ptr_inc_val = 1U; /* Default increment */
	            fl_cc_outputs.dst_ptr_inc_val = 1U; /* Default increment */

	            fl_ch_index = hmi_gfx_mgr02_gsub_do_chained_context_f2_sub(fl_lookup_id,fl_lookup_table_ptr,p_lookup_count,fl_src_P, fl_dst_P, p_src_P, &fl_cc_outputs);
	            if(fl_ch_index==(UINT16)0)
	            {
	              *fl_dst_P = *fl_src_P;

	              fl_src_P++;
	              fl_dst_P++;

	              fl_length_U16--;
	            }
	            else
	            {
	              fl_src_P += fl_cc_outputs.src_ptr_inc_val; /* src string pointer increment value*/
	              fl_dst_P += fl_cc_outputs.dst_ptr_inc_val; /* dst string pointer increment value*/
	              fl_length_U16 -= fl_cc_outputs.src_ptr_inc_val;

	            }
            
	          }
	          *fl_dst_P = 0;
	      }
	      else
	      {
	    	/*To Fix MISRA warning.*/
	      }
	   }
	   else if(fl_gsub_lookup_tbl->type == (UINT16)CONTEXTC)
	   {
	      HMI_FONT_GSUB_CC_OUT fl_cc_outputs;
      
	      fl_length_U16 = (UINT16)wcslen(fl_src_P);
	      while((*fl_src_P != 0U) && (fl_length_U16 > 0U))
	      {
	        fl_cc_outputs.src_ptr_inc_val = 1U; /* Default increment */
	        fl_cc_outputs.dst_ptr_inc_val = 1U; /* Default increment */

	        fl_ch_index = hmi_gfx_mgr02_gsub_do_context_sub(fl_lookup_id,fl_lookup_table_ptr,p_lookup_count,fl_src_P, fl_dst_P, &fl_cc_outputs);
	        if(fl_ch_index ==(UINT16)0)
	        {
	          *fl_dst_P = *fl_src_P;

	          fl_src_P++;
	          fl_dst_P++;

	          fl_length_U16--;
	        }
	        else
	        {
	          fl_src_P += fl_cc_outputs.src_ptr_inc_val; /* src string pointer increment value*/
	          fl_dst_P += fl_cc_outputs.dst_ptr_inc_val; /* dst string pointer increment value*/
	          fl_length_U16 -= fl_cc_outputs.src_ptr_inc_val;

	        }
        
	      }
	      *fl_dst_P = 0;
      
	   }
	   else if(fl_gsub_lookup_tbl->type == (UINT16)SINGLE)
	   {
	      fl_length_U16 = (UINT16)wcslen(fl_src_P);
	      while((*fl_src_P != 0U) && (fl_length_U16 > 0U))
	      {
	        fl_length_U16--;
	        fl_ch_index = hmi_gfx_mgr02_gsub_do_single_sub(fl_gsub_lookup_tbl,fl_src_P, fl_dst_P);
	        if(fl_ch_index==(UINT16)0)
	        {
	          *fl_dst_P = *fl_src_P;
	        }
	        fl_src_P++;
	        fl_dst_P++;
	      }
	      *fl_dst_P = 0;     
	   }
	   else if(fl_gsub_lookup_tbl->type == (UINT16)MULTIPLE)
	   {
	      fl_length_U16 = (UINT16)wcslen(fl_src_P);
	      while((*fl_src_P != 0U) && (fl_length_U16 > 0U))
	      {
	        fl_length_U16--;
	        fl_ch_index = hmi_gfx_mgr02_gsub_do_multiple_sub(fl_gsub_lookup_tbl,fl_src_P, fl_dst_P);
	        if(fl_ch_index>0U)
	        {
	          fl_dst_P += fl_ch_index;
	        }
	        else
	        {
	          *fl_dst_P = *fl_src_P;
	          fl_dst_P++;          
	        }
	        fl_src_P++;
	      }
	      *fl_dst_P = 0;       
	   }     
	   else
	   {
	      while((*fl_src_P != 0U) && (fl_length_U16 > 0U))
	      {
	          fl_length_U16--;
	          *fl_dst_P++ = *fl_src_P++;
	      }
	      *fl_dst_P = 0;
	   }
   }   
}
/*============================================================================
** Function Name:    hmi_gfx_mgr02_gsub_validate_lkup
** Visibility:       global
** Description:      Interface to decide whether to apply table or not.
** Invocation:       Invoked by layout
** Inputs/Outputs:   ip:Master lookup, 
**                   op: TRUE - Apply,FALSE - Don't apply
** Critical Section: None.
** Created:          
** Updated:          
**==========================================================================*/
static UINT8 hmi_gfx_mgr02_gsub_validate_lkup(const HMI_GFX_DEVN_REORDER_INFO * p_reoder_info_SP, UINT16 p_script_list, UINT16 p_lookup_id)
{
   UINT8 fl_proceed = (UINT8)TRUE;
   if(p_lookup_id < p_reoder_info_SP->i_lookup_count )
   {
     if(p_reoder_info_SP->i_lookup[p_lookup_id].type == (UINT16)CHAINING_CONTEXT)
     {
       if(p_reoder_info_SP->i_lookup[p_lookup_id].subtable->format == 1U)
       {
           /* CCS with format-2 support is not implemented */
           fl_proceed = (UINT8)FALSE;
       }
     }
     else if(p_reoder_info_SP->i_lookup[p_lookup_id].type == (UINT16)CONTEXTC)
     {
       if((p_reoder_info_SP->i_lookup[p_lookup_id].subtable->format == 1U) ||
          (p_reoder_info_SP->i_lookup[p_lookup_id].subtable->format == 3U))
       {
           /* CS with format-1 or 3 support is not implemented */
           fl_proceed = (UINT8)FALSE;
       }
       else
       {
         /* Do nothing */
       }
     }
     else
     {
       /* Do nothing */
     }
   }
   return fl_proceed;

}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_gsub_process
** Visibility:       global
** Description:      Interface to process the GSUB table data.
** Invocation:       Invoked by layout
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          01-Jun-2016 by CSAKTHIV
** Updated:          
**==========================================================================*/
void hmi_gfx_mgr02_gsub_process(HMI_GFX_DEVN_REORDER_INFO * p_reoder_info_SP, UINT32 p_num_chars_cpy)
{
   HMI_CHAR * fl_src_P;
   HMI_CHAR * fl_dst_P;
   UINT16 i, fl_script_list, fl_lkup_id;
  #if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED)  
   HMI_CHAR * fl_final_dest_P;
   #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)   
   HMI_CHAR   fl_string_A[GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH + 1];
   #else
   HMI_CHAR   fl_string_A[GFX_MGR02_MAX_TEXT_LENGTH + 1];
   #endif   
   BOOLEAN    fl_is_normalised = FALSE;
 #endif
   fl_dst_P      = p_reoder_info_SP->o_dst;
   fl_src_P      = p_reoder_info_SP->i_src;
   fl_script_list = p_reoder_info_SP->i_script_count;
  #if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED)      
   #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)   
   (void)memset(fl_string_A, 0, (sizeof(HMI_CHAR)) * (GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH + 1U));
   #else   
   (void)memset(fl_string_A, 0, (sizeof(HMI_CHAR)) * (GFX_MGR02_MAX_TEXT_LENGTH + 1U));
   #endif
   fl_final_dest_P = &fl_string_A[0];
  #endif

   for(i = 0; i < p_reoder_info_SP->i_script_count; i++)
   {
      if(strncmp(p_reoder_info_SP->i_script,p_reoder_info_SP->i_script_lookup[i].script_tag,4) == 0)
      {
         fl_script_list = i;
         break;  
      }
   }
   if(fl_script_list !=  p_reoder_info_SP->i_script_count)
   {
   #if defined(GFX_MGR02_FONT_GSUB_TABLE_ENABLED) && ((defined (GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)))
     HMI_FONT_GSUB_LOOKUP_TABLE const * fl_gsub_lookup_tbl;
   #endif
     for(i =0; i < p_reoder_info_SP->i_script_lookup[fl_script_list].script_lkup_cnt; i++)
     {
         fl_lkup_id = p_reoder_info_SP->i_script_lookup[fl_script_list].script_lkup_index[i];
       #if defined(GFX_MGR02_FONT_GSUB_TABLE_ENABLED) && ((defined (GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)))
		 fl_gsub_lookup_tbl = &p_reoder_info_SP->i_lookup[fl_lkup_id];

         if(((fl_gsub_lookup_tbl->type != SINGLE) &&\
		    (strncmp(p_reoder_info_SP->i_script_lookup[fl_script_list].script_tag,"arab",4) == 0)) ||\
            (strncmp(p_reoder_info_SP->i_script_lookup[fl_script_list].script_tag,"arab",4) != 0))
	   #endif
          {
             if(hmi_gfx_mgr02_gsub_validate_lkup(p_reoder_info_SP, fl_script_list, fl_lkup_id) == (UINT8)TRUE)
             {
   	           hmi_gfx_mgr02_gsub_process_lkup_table(p_reoder_info_SP->i_lookup, fl_lkup_id,p_reoder_info_SP->i_lookup_count,fl_src_P,fl_dst_P);
             #if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED)
               if(strncmp(p_reoder_info_SP->i_script_lookup[fl_script_list].script_tag,"thai",4) == 0)
               {
                  (void)hmi_gfx_mgr02_reorder_thai_diacritics(fl_dst_P);
               }
             #endif 
   	           /* processed string will be fl_dst_p copy it to src again */
              (void)HMI_STRNCPY(fl_src_P, fl_dst_P, p_num_chars_cpy);
             }
         }
     }
    #if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED)
      fl_is_normalised =  hmi_gfx_mgr02_normalize_Thai_SaraAm(fl_dst_P,fl_final_dest_P);
      if(fl_is_normalised == TRUE)
      {
         /* normalised string will be fl_final_dest_P copy it to fl_dst_P again */
         (void)HMI_STRNCPY(fl_dst_P, fl_final_dest_P, p_num_chars_cpy);
         (void)hmi_gfx_mgr02_reorder_thai_diacritics(fl_dst_P);
         /* Reordered string will be fl_dst_p copy it to src again */
         (void)HMI_STRNCPY(fl_src_P, fl_dst_P, p_num_chars_cpy);
      }  
     #endif 
   } 
}

#endif /* #ifdef GFX_MGR02_FONT_GSUB_TABLE_ENABLED */

/*============================================================================
 **
 **============================================================================
 ** C M S    R E V I S I O N    N O T E S
 **============================================================================
 **
 ** For each change to this file, be sure to record:
 ** 1.  Who made the change and when the change was made.
 ** 2.  Why the change was made and the intended result.
 **
 ** CMS Rev #        Date         By
 ** CMS Rev X.X      mm/dd/yy     CDSID
 **
 **============================================================================
 ** CMS Rev 1.2      6-Apr-2018    SBOLLAM
 ** 1056323: GMC-HUD: gfx_mgr changes for zero width chars rendering support 
 **          with freetype font engine and GSUB process
 **
 ** CMS Rev 1.1      18-Jan-2018     kkubendi
 ** Ref: RTC 1026955: 
 ** Implemented GSUB font table type: SINGLE SUBSTITUTION
 **
 ** CMS Rev 1.0      01-Jun-2016     csakthiv
 ** Creation.
 ** Algorithm to use the GSUB data provided font. Currently used for Thai language
 **==========================================================================*/
#ifdef  __cplusplus
}
#endif
/* end of file =============================================================*/
