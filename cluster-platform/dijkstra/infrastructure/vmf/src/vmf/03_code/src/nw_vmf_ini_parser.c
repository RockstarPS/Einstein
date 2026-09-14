/*****************************************************************************/
/* Copyright Statement                                                       */
/* CONFIDENTIAL - VISTEON CORPORATION                                        */
/* This is an unpublished work, which contains trade secrets, created in     */
/* 2008. Visteon Corporation owns all rights to this work and intends        */
/* to maintain it in confidence to preserve its trade secret status. Visteon */
/* Corporation reserves the right, under the copyright laws of the United    */
/* States or those of any other country that may have jurisdiction, to       */
/* protect this work as an unpublished copyright work in the event of an     */
/* inadvertent or deliberate unauthorized publication. Visteon Corporation   */
/* also reserves its rights under the copyright laws to protect this work    */
/* as a published work, when appropriate. Those having access to this work   */
/* may not copy it, use it or disclose the information contained in it       */
/* without the written authorization of Visteon Corporation.                 */
/*****************************************************************************/

/***************************************************************************

  Module:               ini_parser.c
  Description:          read and parse ini files

  Project Scope:        Multiple platforms

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Joachim Becker (jbecke30@visteon.com)

  Compiler/Assembler:   gcc
  Target Hardware:      Any

  *****************************************************************************/

#define VMF_INI_PARSER_C
#define VMF_LOGGER_USE_STRCASECMP



/* application includes */
#include <stdio.h>
#include "nw_vmf.h"
#include "nw_vmf_ini_parser.h"

#if 0
#ifdef VMF_TRACE
static unsigned8        vmf_trid=0;
#endif
#endif

/* externals  */
extern char        ini_path[];


/* local functions */
static void clean_string(char *str);
static void trim(char* str);

#ifndef VMF_LOGGER_USE_STRCASECMP
static char *lcase(char* str);
#endif


#define VMF_TRACE_TASK          "vmf"
#define VMF_TRACE_MODULE        "init_parser"
#define VMF_TRACE_SCOPE         (char *)__FUNCTION__
#define MAX_KEY_LEN             50

#if 0
    #ifdef VMF_TRACE
        /* don't use in vmf server process! */
        #define INI_PARSER_INFO(...)    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO, VMF_TRACE_MODULE, VMF_TRACE_SCOPE, __VA_ARGS__);
        #define INI_PARSER_WARNING(...) VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_WARNING, VMF_TRACE_MODULE, VMF_TRACE_SCOPE, __VA_ARGS__);
        #define INI_PARSER_ERROR(...)   VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_ERROR, VMF_TRACE_MODULE, VMF_TRACE_SCOPE, __VA_ARGS__);
    #else
        #define INI_PARSER_INFO(...)    printf("INFO    (%s): ", VMF_TRACE_SCOPE); printf(__VA_ARGS__); printf("\n");
        #define INI_PARSER_WARNING(...) printf("WARNING (%s): ", VMF_TRACE_SCOPE); printf(__VA_ARGS__); printf("\n");
        #define INI_PARSER_ERROR(...)   printf("ERROR   (%s): ", VMF_TRACE_SCOPE); printf(__VA_ARGS__); printf("\n");
    #endif
#else
    #define INI_PARSER_INFO(...)
    #define INI_PARSER_WARNING(...)
    #define INI_PARSER_ERROR(...)
#endif


/***************************************************************************//**
*    global ini-parser functions
 ******************************************************************************/
/*************************************************************************//**
 *
 *   open the ini file
 *
 *   \param         path and file-name
 *   \return        file pointer or NULL
 *
 ******************************************************************************/
FILE * ini_parser_open(char *filename)
{
    FILE *  fp=NULL;
    char path_name[255]={0};

    if (NULL == filename)
    {
        INI_PARSER_ERROR("filename is NULL!");
    }
    else if (filename[0] == 0)
    {
        INI_PARSER_ERROR("filename is empty!");
    }
    else
    {
        if (ini_path[0] != 0)
        {
            (void) snprintf(path_name,sizeof(path_name),"%s%s%s",ini_path,PATH_DELIMITER,filename);
        }
        else
        {
            nw_os_sstrncpy(path_name, filename, sizeof(path_name));
        }

        fp = fopen(path_name,"r");
        if (NULL == fp)
        {
            INI_PARSER_ERROR( "ini_parser_open(%s) fp = %p",path_name,fp );
        }
    }

    return fp;
}



/*************************************************************************//**
 *
 *   close the ini file
 *
 *   \param         file pointer
 *   \return        void
 *
 ******************************************************************************/
void ini_parser_close(FILE *stream)
{
    if (stream != NULL)
    {
        (void)fclose(stream);
    }
}




/*************************************************************************//**
 *
 *   get number of sections in the ini file
 *
 *   \param         file pointer
 *   \return        number of sections or 0
 *
 ******************************************************************************/
int ini_parser_get_num_sections(FILE *ffile)
{
    int     ret_val = 0;
    char    *fg_ret=NULL;
    char    line[255];

    if (NULL == ffile)
    {
        INI_PARSER_ERROR( "NULL pointer");
    }
    else
    {
        /* read line by line */
        (void) fseek(ffile,0,SEEK_SET);    /* SOF */
        line[0]=0;
        while( !feof( ffile ) )
        {
          fg_ret = fgets( line, sizeof( line ), ffile);
          if( NULL == fg_ret )
          {
             // INI_PARSER_INFO( "Read error line ='%s'",line);
             break;
          }

          /* sections format is [section] starting at pos 0 of line */
          if ('['==line[0])
          {
            /* found section */
            ret_val++;
          }
        }

        (void) fseek(ffile,0,SEEK_SET);    /* SOF */
    }

    return ret_val;
}


/*************************************************************************//**
 *
 *   get a sections name
 *
 *   \param         file pointer
 *   \param         section number
 *   \return        pointer to section name or NULL
 *
 ******************************************************************************/
char *ini_parse_get_section_name(FILE *ffile,int section_num)
{
    static  char section_name[80u];
    char    *fg_ret=NULL;
    char    *ret_val=NULL;
    char    line[255u];
    int     num_count=0u;

    if (NULL == ffile)
    {
        INI_PARSER_ERROR( "NULL pointer");
    }
    else
    {
        /* read ine by line */
        (void) fseek(ffile,0u,SEEK_SET);    /* SOF */
        line[0u]=0u;
        section_name[0u]=0;
        while( !feof( ffile ) )
        {
          fg_ret = fgets( line, sizeof( line ), ffile);
          if( NULL == fg_ret )
          {
             INI_PARSER_INFO( "Read error" );
             break;
          }
          /* sections format is [section] starting at pos 0 of line */
          if ('['==line[0])
          {
            /* found section */
            if (num_count == section_num)
            {
                (void) sscanf(line,"[%40s]",section_name);
                clean_string(section_name);
                ret_val = ((char*)section_name);
                break;
            }
            num_count++;
          }
        }
    }

    return ret_val;
}


/*************************************************************************//**
 *
 *   get the value of a key inside a section
 *
 *   \param         file pointer
 *   \param         section name
 *   \param         key name
 *   \param         pointer to result-string buffer
 *   \param         size of result buffer
 *   \return        size of result string in bytes
 *
 ******************************************************************************/
int ini_parser_get_val(FILE *stream,char *section,char *key_name,char *value,int val_buff_len)
{
    int     num_sec=0;
    int     cnt=0;
    char    *current_section=NULL;
    int     ret_val=-1;

    /* argument check */
    if (NULL == stream)
    {
        INI_PARSER_ERROR( "stream = NULL");
        ret_val = 0;
    }
    else if (NULL == section)
    {
        INI_PARSER_ERROR( "section = NULL");
        ret_val = 0;
    }
    else if (NULL == key_name)
    {
        INI_PARSER_ERROR( "key_name = NULL");
        ret_val = 0;
    }
    else if (NULL == value)
    {
        INI_PARSER_ERROR( "value = NULL");
        ret_val = 0;
    }
    else if (0 == val_buff_len)
    {
        INI_PARSER_ERROR( "val_buff_len = 0");
        ret_val = 0;
    }
    else
    {
        num_sec = ini_parser_get_num_sections(stream);
        for (cnt=0;cnt< num_sec; cnt++)
        {
            current_section=ini_parse_get_section_name(stream,cnt);
            if (NULL == current_section)
            {
                INI_PARSER_INFO("section %s not found",section);
                break;
            }
    #ifdef VMF_LOGGER_USE_STRCASECMP
            if (0==strcasecmp(current_section,section))
    #else
            if (0==strcmp(lcase(current_section),section))
    #endif
            {
                /* found section */
                INI_PARSER_INFO("found section %s",section);
                break;
            }
        }

        if (current_section != NULL)
        {
            /* found section - search key */
            while( !feof( stream ) )
            {
                char key[255];
                value[0]=0;
                ret_val = ini_parser_get_next_key(stream,key,sizeof(key),value,val_buff_len);
                if (ret_val > 0)
                {
                    /* found a key */
    #ifdef VMF_LOGGER_USE_STRCASECMP
                    if (0==strcasecmp(key,key_name))
    #else
                    if (0==strcmp(lcase(key),key_name))
    #endif
                    {
                        /* correct key !*/
                        INI_PARSER_INFO("found key %s",key_name);
                        break;
                    }
                }
                else if(ret_val < 0)
                {
                    /* end of section */
                    break;
                }
            }
        }
        else
        {
            INI_PARSER_INFO("%s - %s not found",section,key_name);
        }
    }

    return ret_val;     /* return size of value */
}


/*************************************************************************//**
 *
 *   get the key-name and value of a key-number inside a section
 *
 *   \param         (input)file pointer
 *   \param         (input)section name
 *   \param         (input)key-number (0..)
 *   \param         (output)key-name buffer
 *   \param         (input)key-name buffer len
 *   \param         (output)value buffer
 *   \param         (input)size of value buffer

 *   \return        (input)key number if key was found
 *                  or INI_PARSER_END_OF_SECTION if sektion end
 *                  or INI_PARSER_EMPTY_LINE if empty line
 *
 ******************************************************************************/
int ini_parser_get_key_num_val(FILE *stream,char *section,unsigned16 key_num,char *key_name, int key_name_len, char *value,int val_buff_len)
{
    int     num_sec=0;
    int     cnt=0;
    char    *current_section=NULL;
    int     ret_val=INI_PARSER_END_OF_SECTION;

//printf("ini_parser_get_key_num_val sction:%s key-number:%d\n", section,key_num);

    /* argument check */
    if (NULL == stream)
    {
        INI_PARSER_ERROR( "stream = NULL");
        ret_val = INI_PARSER_END_OF_SECTION;
    }
    else if (NULL == section)
    {
        INI_PARSER_ERROR( "section = NULL");
        ret_val = INI_PARSER_END_OF_SECTION;
    }
    else if (NULL == key_name)
    {
        INI_PARSER_ERROR( "key_name = NULL");
        ret_val = INI_PARSER_END_OF_SECTION;
    }
    else if (0 == key_name_len)
    {
        INI_PARSER_ERROR( "key_name_len = 0");
        ret_val = INI_PARSER_END_OF_SECTION;
    }
    else if (NULL == value)
    {
        INI_PARSER_ERROR( "value = NULL");
        ret_val = INI_PARSER_END_OF_SECTION;
    }
    else if (0 == val_buff_len)
    {
        INI_PARSER_ERROR( "val_buff_len = 0");
        ret_val = INI_PARSER_END_OF_SECTION;
    }
    else
    {
        /* get number of sections */
        num_sec = ini_parser_get_num_sections(stream);
        for (cnt=0;cnt< num_sec; cnt++)
        {
            current_section=ini_parse_get_section_name(stream,cnt);
            if (NULL == current_section)
            {
                INI_PARSER_INFO("section %s not found",section);
                break;
            }
    #ifdef VMF_LOGGER_USE_STRICMP
            if (0==stricmp(current_section,section))
    #else
            if (0==strcmp(current_section,section))
    #endif
            {
                /* found section */
                break;
            }
        }

        if (current_section != NULL)
        {
            /* found the section - search key */
            if(!feof( stream ))
            {
                int num;
                key_name[0]=0;
                value[0]=0;

                for (num =0; num < key_num+1; )
                {
                    ret_val = ini_parser_get_next_key(stream,key_name,key_name_len,value,val_buff_len);
                    if (ret_val < 0)
                    {
                        break;
                    }
                    /* ignore empty line */
                    if ((key_name[0] != 0x00) && (key_name[0] != 0x0d) && (key_name[0] != 0x0d))
                    {
                        num++;
                    }
                }

                if (ret_val < 0)
                {
                    INI_PARSER_INFO("key-number %d in section %s not found",key_num, section);
                    ret_val = INI_PARSER_END_OF_SECTION;
                }
                else if (ret_val > 0)
                {
                    INI_PARSER_INFO("found key-number %d = %s in section %s ",key_num, key_name, section);
                    ret_val = key_num;
                }
                else
                {
                    INI_PARSER_INFO("found empty key %d in section %s ",key_num, section);
                    ret_val = INI_PARSER_EMPTY_LINE;
                }
            }
        }
        else
        {
            INI_PARSER_INFO("%s - %s not found",section,key_name);
            ret_val = INI_PARSER_END_OF_SECTION;
        }
    }

    return ret_val;     /* return section num or error */

}



/*************************************************************************//**
 *
 *   create u8 list from comma seperated string
 *   like   "1,2,3,4" or
 *          "1-5"
 *   \param         pointer to string
 *   \param         resulting byte buffer
 *   \param         size of resulting buffer
 *
 *   \return        size of result string in bytes
 *
 ******************************************************************************/
unsigned8 ini_parser_get_byte_list(char *in_str, unsigned8 *byte_list, unsigned8 len)
{
    char        *pch=NULL;
    unsigned8   pos=0;
    int         val;
    unsigned8   ret_val=0;

    /* argument check */
    if (NULL == in_str)
    {
        INI_PARSER_ERROR( "in_str = NULL");
        ret_val = 0;
    }
    else if (NULL == byte_list)
    {
        INI_PARSER_ERROR( "byte_list = NULL");
        ret_val = 0;
    }
    else if (0 == len)
    {
        INI_PARSER_ERROR( "len = 0");
        ret_val = 0;
    }
    else
    {
        pch = strtok(in_str,",");
        while (pch != NULL)
        {
            {
                val = atoi(pch);
                if (val > 0xff)
                {
                    /* invalid value - ignore */
                    continue;
                }
                else
                {
                    char *fpos;
                    fpos = strpbrk(pch,"-");
                    if (NULL == fpos)
                    {
                        /* value does fit into byte array */
                        byte_list[pos]=(unsigned8)val;
                        pos++;
                    }
                    else
                    {
                        unsigned8 to_val;
                        int current_grp;

                        /* the value has the form n-m */
                        /* 'from' value is in val */

                        /* get 'to' value */
                        to_val = atoi(fpos+1);

                        /* add all values into table */
                        for (current_grp = val; current_grp <= to_val; current_grp++)
                        {
                            byte_list[pos]=current_grp;
                            pos++;
                            if (pos >= len)
                            {
                                break;
                            }
                        }
                    }
                }
                ret_val = pos;      /* ret-value = number of elements in array */
                if (pos >= len)
                {
                    break;
                }
            }
            pch = strtok(NULL,",");
        }

        #if 0
        {
            int i;
            for (i=0; i<pos; i++)
            {
                INI_PARSER_INFO( "byte_list(%d) = %d",i,byte_list[i]);
            }
        }
        #endif
    }

    return ret_val;
}




/***************************************************************************//**
*    local ini-parser functions
 ******************************************************************************/


/*************************************************************************//**
 *
 *   get next key and value
 *
 *   \param         file pointer
 *   \param         pointer to key-buffer
 *   \param         size of key-buffer
 *   \param         pointer to value-buffer
 *   \param         size of value-buffer
 *   \return        length of value string or INI_PARSER_END_OF_SECTION if new section
 *
 ******************************************************************************/
int ini_parser_get_next_key(FILE *stream,char *r_key,int r_key_len,char *r_val,int r_val_len)
{
    char    *fg_ret=NULL;
    char    line[255];
    char    *pch=NULL;
    int     retval=0;

    /* argument check */
    if (NULL == stream)
    {
        INI_PARSER_ERROR( "stream = NULL");
        retval = 0;
    }
    else if (NULL == r_key)
    {
        INI_PARSER_ERROR( "r_key = NULL");
        retval = 0;
    }
    else if (NULL == r_val)
    {
        INI_PARSER_ERROR( "r_val = NULL");
        retval = 0;
    }
    else if (0 == r_key_len)
    {
        INI_PARSER_ERROR( "r_key_len = 0");
        retval = 0;
    }
    else if (0 == r_val_len)
    {
        INI_PARSER_ERROR( "r_val_len = 0");
        retval = 0;
    }
    else
    {
        fg_ret = fgets(line, sizeof( line ), stream);
        if (NULL != fg_ret)
        {
            pch = strtok(line,"=");
            if (NULL != pch)
            {
                /* copy key */
                clean_string(pch);
                if (0 != pch[0])
                {
                    nw_os_sstrncpy(r_key, pch, r_key_len);
                    pch = strtok(NULL,"=");
                    if (NULL != pch)
                    {
                        /* copy value*/
                        clean_string(pch);
                        nw_os_sstrncpy(r_val, pch, r_val_len);
                        retval = strlen(r_val);
                    }
                }
            }
            if (line[0]=='[')
            {
                /* new section */
                retval = INI_PARSER_END_OF_SECTION;
            }
        }
    }

    return retval;
}


/*************************************************************************//**
 *   firs trim string then
 *   remove control character and replace them with 0
 *
 *   \param         pointer to string
 *   \return        void
 *
 ******************************************************************************/
static void clean_string(char *str)
{
    unsigned i;

    /* argument check */
    if (NULL == str)
    {
        INI_PARSER_ERROR( "str = NULL");
    }
    else
    {
        trim(str);
        for (i=0;i<strlen(str);i++)
        {
            if ((str[i] == ';') || (str[i] == '\'') || (str[i] == '#') || (str[i] < ' ') || (str[i] == ']') || (str[i] < 0x20))
            {
                str[i]=0;
                break;
            }
            else if (str[i] == '/')
            {
                if (str[i+1] == '/')
                {
                    str[i]=0;
                    break;
                }
            }
        }
    }
}


/*************************************************************************//**
 *
 *   l-trim and r-tim string
 *
 *   \param         pointer to string
 *   \return        void
 *
 ******************************************************************************/
static void trim(char* str)
{
    char        tmp[255];
    unsigned    wr_pos=0;
    unsigned    rd_pos=0;
    unsigned16  len=0;

    /* argument check */
    if (NULL == str)
    {
        INI_PARSER_ERROR( "str = NULL");
    }
    else
    {
        /* ltrim */
        while((str[rd_pos] == ' ') && (str[rd_pos] != 0x0))
        {
            rd_pos++;
        }
        nw_os_sstrncpy(tmp, &(str[rd_pos]), sizeof(tmp));

        /* remove spaces within the text */
        len = strlen(tmp);
        for(rd_pos=0, wr_pos=0; rd_pos<len; rd_pos++)
        {
            if (tmp[rd_pos] != ' ')
            {
                /* copy into same buffer - string can only become smaller */
                tmp[wr_pos]=tmp[rd_pos];
                wr_pos++;
            }
        }
        tmp[wr_pos]=0;
        (void)strcpy(str,tmp);
    }
}


#ifndef VMF_LOGGER_USE_STRCASECMP

/*************************************************************************//**
 *
 *   lcase
 *
 *   \param         convert string to lower case
 *   \return        void
 *
 ******************************************************************************/
static char *lcase(char* str)
{
#ifndef VMF_LOGGER_USE_STRICMP
    int cnt;
    int len;

    if (NULL != str)
    {
        len = strlen(str);

        for(cnt = 0; cnt<len ; cnt++)
        {
            str[cnt] = tolower(str[cnt]);
        }
    }
#endif
    return str;
}

#endif


#undef VMF_INI_PARSER_C

