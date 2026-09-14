/******************************************************************************
*                                                                             *
*                   CONFIDENTIAL - Visteon Automotive Systems                 *
*                                                                             *
*  This is an unpublished work, which is a trade secret, created in 2007.     *
*  Visteon Automotive Systems owns all rights to this work and intends to     *
*  maintain it in confidence to preserve its trade secret status.  Visteon    *
*  Automotive Systems reserves the right to protect this work as an           *
*  unpublished copyrighted work in the event of an inadvertent or deliberate  *
*  unauthorized publication.  Visteon Automotive Systems also reserves        *
*  its rights under the copyright laws to protect this work as a published    *
*  work.  Those having access to this work may not copy it, use it, or        *
*  disclose the information contained in it without the written authorization *
*  of Visteon Automotive Systems.                                             *
*                                                                             *
*******************************************************************************
*  PROJECT NAME :  VMF                                                        *
*******************************************************************************
*  MODULE NAME  :  vmf_ini_parser.h                                                *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :   20th April 2012                                            *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  types used by the Visteon message framework                    *
******************************************************************************/
#ifndef VMF_INI_PARSER_H
#define VMF_INI_PARSER_H

#define INI_PARSER_END_OF_SECTION       (-1)    /* end of section or end of file or parameter error */
#define INI_PARSER_EMPTY_LINE           (-2)    /* empty or commented line */



FILE *      ini_parser_open            (char *filename);
void        ini_parser_close           (FILE *   ffile);
char *      ini_parse_get_section_name (FILE *ffile,int section_num);
int         ini_parser_get_val         (FILE *stream,char *section,char *key_name,char *value,int val_len);
int         ini_parser_get_num_sections(FILE *ffile);
unsigned8   ini_parser_get_byte_list   (char *in_str, unsigned8 *byte_list, unsigned8 len);
int         ini_parser_get_next_key(FILE *stream,char *r_key,int r_key_len,char *r_val,int r_val_len);
int         ini_parser_get_key_num_val(FILE *stream,char *section,unsigned16 key_num,char *key_name, int key_name_len, char *value,int val_buff_len);

#endif

