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
*  PROJECT NAME :  VMF multi instance extension                                                         *
*******************************************************************************
*  MODULE NAME  :  nw_vmf_mi.h                                                *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :   20th April 2012                                            *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  types used by the Visteon message framework                    *
******************************************************************************/
#ifndef __VMF_INI_H
#define __VMF_INI_H

#define VMF_MI_MAJOR_NUMBER            2
#define VMF_MI_MINOR_NUMBER            43

#define MAKE_MI_STRING2(str) #str
#define MAKE_MI_STRING1(str) MAKE_MI_STRING2(str)
#define VMF_MI_VERSION_STRING "VMF-MI version " MAKE_MI_STRING1(VMF_MI_MAJOR_NUMBER) "." MAKE_MI_STRING1(VMF_MI_MINOR_NUMBER)

#ifdef INTEGRITY
    #define VMF_MI_INI_FILE         "/opt/visteon/vmf_mi.ini"
#else
    #define VMF_MI_INI_FILE         "vmf_mi.ini"
#endif

#define MY_NAME                 "VMF_MI"

#define VMF_TRACE_MI            "vmf_mi"
#define VMF_TRACE_GL_TASK       "vmf_mi"
#define VMF_TRACE_GL_SCOPE      "vmf_mi_global"
#define VMF_TRACE_MI_SCOPE      (char *)__PRETTY_FUNCTION__

#define VMF_MI_STACK_SIZE       VMF_NW_STACK_SIZE


#define VMF_MI_ERROR(...)       VMF_TRACE_PRINTF(vmf_mi_trid, VMF_TRACE_SEVERITY_ERROR, VMF_TRACE_GL_TASK, VMF_TRACE_MI_SCOPE, __VA_ARGS__);
#define VMF_MI_INFO(...)        VMF_TRACE_PRINTF(vmf_mi_trid, VMF_TRACE_SEVERITY_INFO, VMF_TRACE_GL_TASK, VMF_TRACE_MI_SCOPE, __VA_ARGS__);
#define VMF_MI_INFO2(...)       VMF_TRACE_PRINTF(vmf_mi_trid, VMF_TRACE_SEVERITY_INFO_20, VMF_TRACE_GL_TASK, VMF_TRACE_MI_SCOPE, __VA_ARGS__);
#define VMF_MI_INFO3(...)       VMF_TRACE_PRINTF(vmf_mi_trid, VMF_TRACE_SEVERITY_INFO_20+20, VMF_TRACE_GL_TASK, VMF_TRACE_MI_SCOPE, __VA_ARGS__);

#if 0 /* old */
    #define VMF_MI_ERROR(...)       fprintf(ERROR_CHANNEL,"VMF_MI_ERROR: "__VA_ARGS__); fprintf(ERROR_CHANNEL, "\n");
    #define VMF_MI_INFO(...)        // fprintf(ERROR_CHANNEL,"VMF_MI_INFO:  "__VA_ARGS__); fprintf(ERROR_CHANNEL, "\n");
    #define VMF_MI_INFO2(...)       // fprintf(ERROR_CHANNEL,"VMF_MI_INFO:  "__VA_ARGS__); fprintf(ERROR_CHANNEL, "\n");
    #define VMF_MI_INFO3(...)       // fprintf(ERROR_CHANNEL,"VMF_MI_INFO:  "__VA_ARGS__); fprintf(ERROR_CHANNEL, "\n");
#endif


#ifdef __ANDROID__
    #define VMF_MI_DEBUG_ERROR(trid,scope, ...)           __android_log_print(ANDROID_LOG_ERROR, "VMF_MI_ERROR", __VA_ARGS__);
    #define VMF_MI_DEBUG_WARNING(trid,scope, ...)         // __android_log_print(ERROR_CHANNEL,"VMF_MI_WARNING:  "__VA_ARGS__); fprintf(ERROR_CHANNEL, "\n");
    #define VMF_MI_DEBUG_INFO(trid,scope, ...)            // __android_log_print(ERROR_CHANNEL,"VMF_MI_INFO:  "__VA_ARGS__); fprintf(ERROR_CHANNEL, "\n");
    #define VMF_MI_DEBUG_DEBUG(trid,scope,severity, ...)  // __android_log_print(ERROR_CHANNEL,"VMF_MI_DEBUG: "__VA_ARGS__); fprintf(ERROR_CHANNEL, "\n");
    #define VMF_MI_DEBUG_HEX(trid,scope,len,data)         // (void)VMF_TRACE_HEX(trid,VMF_TRACE_SEVERITY_INFO_20,scope,VMF_TRACE_MI_SCOPE,len,data);
#else
    #define VMF_MI_DEBUG_ERROR(trid,scope, ...)           VMF_TRACE_PRINTF(trid, VMF_TRACE_SEVERITY_ERROR, VMF_TRACE_GL_TASK, scope, __VA_ARGS__);
    #define VMF_MI_DEBUG_WARNING(trid,scope, ...)         VMF_TRACE_PRINTF(trid, VMF_TRACE_SEVERITY_WARNING, VMF_TRACE_GL_TASK, scope, __VA_ARGS__);
    #define VMF_MI_DEBUG_INFO(trid,scope, ...)            VMF_TRACE_PRINTF(trid, VMF_TRACE_SEVERITY_INFO, VMF_TRACE_GL_TASK, scope, __VA_ARGS__);
    #define VMF_MI_DEBUG_DEBUG(trid,scope,severity, ...)  VMF_TRACE_PRINTF(trid, VMF_TRACE_SEVERITY_INFO_10, VMF_TRACE_GL_TASK, scope, __VA_ARGS__);
    #define VMF_MI_DEBUG_HEX(trid,scope,len,data)         (void)VMF_TRACE_HEX(trid,VMF_TRACE_SEVERITY_INFO_20,scope,VMF_TRACE_MI_SCOPE,len,data);
#endif


#define VMF_MI_MAX_SECTIONS             (5) 
#define VMF_MAX_REMOTE_IP               (20)  
#define VMF_MI_MAX_LEN_SECTION_NAME     (40)
#define VMF_MI_START_DELAY              (100)       /* delay between vmf stat and vma-mi start in ms*/
#define VMF_MI_MAX_DEVICE_TYPE_LEN      (10)        /* max length of device type */
#define VMF_MI_MAX_DEVICE_LEN           (255)       /* max length of a device name */  
#ifndef WAIT_SOME_TIME
#define WAIT_SOME_TIME                  (100)       /* wait time in ms */
#endif

/* key names */
#define KEY_LOCAL_PORT      			"local_port"
#define KEY_LOCAL_GROUPS    			"local_groups"
#define KEY_REMOTE_PORT     			"remote_port"
#define KEY_REMOTE_IP       			"remote_ip"
#define KEY_DEVICE_TYPE     			"device_type"
#define KEY_LOCAL_DEVICE    			"local_device"
#define KEY_REMOTE_DEVICE  			 	"remote_device"
#define KEY_COMPRESSION  			 	"compression"
#define KEY_ALLOW_BACKFIRE              "allow_backfire"

#define SECTION_CONFIG      			"VMF_CONFIG"

/* supported device types */
#define VMF_MI_DTYPE_TCP                "TCP"
#define VMF_MI_DTYPE_BLK                "BLK"
#define VMF_MI_DTYPE_CHAR               "CHAR"
#define VMF_MI_DTYPE_VMQ                "VMQ"
#define VMF_MI_DTYPE_FIFO               "FIFO"


/* supported compression types */
#define MI_NO_COMP                      0                   /* no cpmresssion */
#define MI_LZWR3                        1                   /* lzwr version 3 */

#define MO_DEFAULT_COMP                 MI_LZWR3

typedef enum
{
        NDT_TCP,
        NDT_BLK,
        NDT_CHAR,
        NDT_VMQ,
        NDT_FIFO
}vmf_mi_num_dtype;
#define NDT_DEFAULT     NDT_TCP







#define VMF_MI_KEEP_ALIVE_TIME  1000                            /* second keep alive time in ms */
#define VMF_MI_RX_TIMEOUT       (VMF_MI_KEEP_ALIVE_TIME * 2)    /* recv rx timeout */

#define VMF_MI_USE_SYNC_TOKEN
#define VALID_TOKEN             0xaa55
#define VALID_TOKEN0            0x55
#define VALID_TOKEN1            0xaa



/* this message format is used if first sync token is VALID_TOKEN0 */
#pragma pack(push,1)
typedef struct
{
    unsigned8                               token0;             /* VALID_TOKEN0 */     
    unsigned8                               token1;             /* VALID_TOKEN1 */
    unsigned16                              vmf_len;            /* len of vmf message in bytes (little endian) */
    VMF_VAR_MSG_TYP(MAX_VMF_DATA_LEN)       vmf_msg;
}nw_vmf_mi_transfer_t;
#pragma pack(pop)
#define VMF_MI_HEADER_LEN	                4


/* this message format is used if first sync token is VALID_TOKEN0_V2 */
#pragma pack(push,1)
typedef struct
{
    unsigned8                               token0;             /* VALID_TOKEN0 */
    unsigned8                               token1;             /* VALID_TOKEN1 */
    unsigned8                               version_l;
    unsigned8                               version_h;
    unsigned8                               comp;               /* 0 = no compression, 1 = LZW */
    unsigned8                               reserved;
    unsigned8                               csum_l;             /* 0x0000 == ignore checksum   */
    unsigned8                               csum_h;
    unsigned16                              vmf_len;            /* len of vmf message in bytes (little endian) */
    VMF_VAR_MSG_TYP(MAX_VMF_DATA_LEN)       vmf_msg;
}nw_vmf_mi_transfer_v2_t;
#pragma pack(pop)
#define VMF_MI_HEADER_LEN_V2                10




#define NW_VMF_MI_GET_TRANSFER_MSG_LEN(vmf_len)     (vmf_len + VMF_MI_HEADER_LEN)
#define NW_VMF_MI_GET_TRANSFER_CO_MSG_LEN(vmf_len)  (vmf_len + VMF_MI_HEADER_LEN_V2)

typedef struct  
{
        u_long  onoff;
        u_long  keepalivetime;
        u_long  keepaliveinterval;
}tcp_keepalive_t;

typedef struct 
{
    bool        in_use;
    vmf_mi_num_dtype num_dtype;
    unsigned16  local_port;
    unsigned16  remote_port;
    unsigned16  local_group_num;
    unsigned8   local_groups[MAX_GROUP_NUM];    /* groups to register */
    unsigned8   this_section;
    unsigned8   comp_type;                      /* compession type */
    unsigned8   allow_backfire;
    char        remote_ip[VMF_MAX_REMOTE_IP];   /* ip v4 - zero terminated */
    char        device_type[VMF_MI_MAX_DEVICE_TYPE_LEN];   /* device type */
    char        section_name[VMF_MI_MAX_LEN_SECTION_NAME];
    char        local_device[VMF_MI_MAX_DEVICE_LEN];
    char        remote_device[VMF_MI_MAX_DEVICE_LEN];
}vmf_mi_section_t;

vmf_ret_t       vmf_mi_vmf_sender                   (vmf_client_id_t vmf_client_id,vmf_msg_t * p_vmf_msg, unsigned16 len,unsigned8 section_num);
vmf_ret_t       nw_vmf_mi_create_starter_thread     (void);
void            nw_vmf_mi_enable_server             (void);
bool            nw_vmf_is_mi_enabled                (void);
vmf_ret_t       nw_vmf_mi_create_tcp_server_thread  (vmf_mi_section_t *p_vmf_mi_section);
vmf_ret_t       nw_vmf_mi_create_vmf_server_thread  (vmf_mi_section_t *p_vmf_mi_section);
int             nw_vmf_mi_dtype_tcp_readinit        (FILE * stream, vmf_mi_section_t *vmf_mi_sections,int section_num,char *p_section_name);
int             nw_vmf_mi_dtype_file_readinit       (FILE * stream, vmf_mi_section_t *vmf_mi_sections,int section_num,char *p_section_name);
vmf_ret_t       nw_vmf_mi_start_tcp_instance        (vmf_mi_section_t *vmf_mi_sections,int section_num);
vmf_ret_t       nw_vmf_mi_start_dtf_instance        (vmf_mi_section_t *vmf_mi_sections,int section_num);
vmf_ret_t       nw_vmf_mi_vmf_connect               (vmf_mi_section_t * p_ass_section);
vmf_ret_t       nw_vmf_mi_vmf_disconnect            (vmf_client_id_t vmf_client_id);
int             vmf_mi_recv_wait(SOCKET s,char  * buf,int len,int flags);
unsigned16      nw_mi_compress(unsigned8 comp, unsigned8 *psrc, unsigned16 src_len, unsigned8 *pdest, unsigned16 dest_buff_len);
unsigned16      nw_mi_decompress(unsigned8 comp, unsigned8 *psrc, unsigned16 src_len, unsigned8 *pdest, unsigned16 dest_buff_len);


#endif

