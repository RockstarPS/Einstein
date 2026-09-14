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
*  MODULE NAME  :  nw_vmf_ini_parser.h                                                *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :   20th April 2012                                            *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  types used by the Visteon message framework                    *
******************************************************************************/
#ifndef __VMF_INI_PARSER_H
#define __VMF_INI_PARSER_H

#define INI_PARSER_ERROR(...)       fprintf(ERROR_CHANNEL,"INI_PARSER_ERROR: "__VA_ARGS__); fprintf(ERROR_CHANNEL, "\n");
#define INI_PARSER_INFO(...)        fprintf(ERROR_CHANNEL,"INI_PARSER_INFO: "__VA_ARGS__); fprintf(ERROR_CHANNEL, "\n");
#define INI_PARSER_INFO2(...)       fprintf(ERROR_CHANNEL,"INI_PARSER_INFO: "__VA_ARGS__); fprintf(ERROR_CHANNEL, "\n");


FILE *      ini_parser_open            (char *filename);
void        ini_parser_close           (FILE *   ffile);
char *      ini_parse_get_section_name (FILE *ffile,int section_num);
int         ini_parser_get_val         (FILE *stream,char *section,char *key_name,char *value,int val_len);
int         ini_parser_get_num_sections(FILE *ffile);
unsigned8   ini_parser_get_byte_list   (char *in_str, unsigned8 *byte_list, unsigned8 len);




#endif

