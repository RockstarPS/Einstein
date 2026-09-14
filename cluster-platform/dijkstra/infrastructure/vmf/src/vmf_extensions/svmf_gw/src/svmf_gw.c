
#include "ws2tcpip.h"
#include "windows.h"
#include "nw_vmf.h"
#include "svmf.h"
#include "vmf_mi_mqx.h"
#include "vmf_download.h"
#include "vmf_monitoring.h"

#undef VMF_TRACE


/* macros */
#ifdef VMF_TRACE
    #define DEBUG_INFO_HI(trace_task, args...)   VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO, trace_task, (char *)__PRETTY_FUNCTION__, args);
    #define DEBUG_INFO_LO(trace_task, args...)   VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_20, trace_task, (char *)__PRETTY_FUNCTION__, args);
    #define DEBUG_ERROR(trace_task, args...)     VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_ERROR, trace_task, (char *)__PRETTY_FUNCTION__, args);
#else
    #define DEBUG_INFO(trace_task, args...)      {printf("INFO_HI "); printf(trace_task); printf(" "); printf(__PRETTY_FUNCTION__), printf("() -- "); printf(args); printf("\n");}
    #define DEBUG_INFO_HI(trace_task, args...)   if (verbose>=1) {printf("INFO_HI "); printf(trace_task); printf(" "); printf(__PRETTY_FUNCTION__), printf("() -- "); printf(args); printf("\n");}
    #define DEBUG_INFO_LO(trace_task, args...)   if (verbose>=2) {printf("INFO_LO "); printf(trace_task); printf(" "); printf(__PRETTY_FUNCTION__), printf("() -- "); printf(args); printf("\n");}
    #define DEBUG_ERROR(trace_task, args...)     if (verbose>=0) {printf("ERROR   "); printf(trace_task); printf(" "); printf(__PRETTY_FUNCTION__), printf("() -- "); printf(args); printf("\n");}
#endif
#define bool    BOOL
#define VMF_TRID_NAME               "vmf-ser-gw"
#define VMF_TRACE_TASK_MAIN         "MAIN"
#define VMF_TRACE_TASK_VMF          "VMF"
#define VMF_TRACE_TASK_COM          "COM"
#define VMF_TRACE_TASK_FLASH        "FLASH"
#define VMF_TRACE_TASK_TCP          "TCP"

#define VMF_RECEIVER_STACK_SIZE     (64 * 1024)
#define COM_PORT_INVALID            99
#define IO_MSG_DELIMITER            0x0A
#define IO_MSG_DATALEN_MAX          4000
#define WRITE_RETRY_COUNT_MAX       10
#define SYNC_COUNT_MAX              500
#define SYNC_COUNT_WAIT_MS          20
#define VMF_SAT_TX_GRP_DEF          100     /* Saturn->Host */
#define VMF_SAT_RX_GRP_DEF          101     /* Host->Saturn */
#define VMF_SAT_MSG_EVT_DEF         1       /* saturn message event */
#define TRANSFER_BUFFER_SIZE        (1024)
#define SVMF_SRV_BACKFIRE           (0xAB)

/* types */
/* transfer message type */
#define VMF_SAT_GW_MSG_TX           1
#define VMF_SAT_GW_MSG_RX           2
#define VMF_SAT_SYNC_1              (0xa5)
#define VMF_SAT_SYNC_2              (0x5a)
#define VMF_SAT_SYNC_2_V2           (0x5b)
#define VMF_SAT_SERIAL_NAK          (0x55)
#define VMF_SAT_LOAD_REQ            (0x51)
#define VMF_SAT_LOAD_RESP           (0x15)
#define VMF_SAT_FLASH_REQ           (0x52)
#define VMF_SAT_FLASH_RESP          (0x25)
#define VMF_SAT_LOAD_ACK            (0x35)

#define CMD_TIMEOUT                 (500)
#define FLASH_TIMEOUT               (20000)     /* max flash write time */
#define MAX_RTRID                   (255)

//#define SERIAL_BAUDRATE             CBR_57600
#define SERIAL_BAUDRATE             CBR_115200
typedef struct
{
    unsigned8   sync_1;
    unsigned8   sync_2;
    unsigned16  pl_len;
    unsigned8   pl[0];
}vmf_sat_gw_msg_t;

#pragma pack(push,1)
typedef struct
{
    unsigned8   sync_1;
    unsigned8   sync_2;
    unsigned32  pl_len;
    unsigned8   pl[0];
}vmf_sat_flash_msg_t;
#pragma pack(pop,1)


#define MAX_VMF_TRACE_PL_LEN        (250)
#define MAX_VMF_TRACE_TASK_NAME_LEN (50)
#define MAX_TRACE_NAME_LEN          (10)

#ifndef VMF_TRACE_MSG_TYPE_SHM
#define VMF_TRACE_MSG_TYPE_TEXT     0
#define VMF_TRACE_MSG_TYPE_HEX      1
#define VMF_TRACE_MSG_TYPE_SHM      2

#pragma pack(push,1)

#define MAX_TRACE_NAME_LEN          (10)
#define MAX_TRACE_TASK_NAME_LEN     (30)
#define MAX_TRACE_SCOPE_LEN         (30)
#define MAX_TRACE_MSG_LEN           (MAX_VMF_TRACE_PL_LEN - (MAX_TRACE_NAME_LEN + MAX_TRACE_TASK_NAME_LEN + MAX_TRACE_SCOPE_LEN))
#define VMF_MI_SERVER_PORT          54321                                /* TCP port of VMF server */

#define CLOSESOCKET(fd)             closesocket(fd)
#define SOCKET_T                    SOCKET

typedef struct
{
    unsigned8           trid;                       /* trace id  */
    unsigned8           severity;                   /* message severity 0 = highest */
    unsigned8           sequence_type;              /* 0xa1 if last message in this payload else 0xa0 */
    unsigned8           fill;                       /* fill byte */
    unsigned32          num;                        /* task message number starting at 0 */
    unsigned32          msg_time;                   /* msg time in ms */
    unsigned16          tpl_len;                    /* trace payload length */
}vmf_trace_pl_header_t;


typedef struct
{
    unsigned8           trid;                       /* trace id  */
    unsigned8           severity;                   /* message severity 0 = highest */
    unsigned8           sequence_type;              /* 0xa1 if last message in this payload else 0xa0 */
    unsigned8           fill;                       /* fill byte */
    unsigned32          num;                        /* task message number starting at 0 */
    unsigned32          msg_time;                   /* msg time in ms */
    unsigned16          tpl_len;                    /* trace message length */
    char                name[MAX_TRACE_NAME_LEN+1]; /* trid name of a trace task */
    char                task[MAX_TRACE_TASK_NAME_LEN]; /* task name */
    char                scope[MAX_TRACE_SCOPE_LEN]; /* scope */
    char                msg[MAX_TRACE_MSG_LEN];     /* msg */
}vmf_trace_shm_pl_t;

#pragma pack(pop)

#ifndef VMF_TRACE_MSG_DELIMITER
#define VMF_TRACE_MSG_DELIMITER     "¦"
#endif

#endif

#ifndef GET_TPL_LEN
#define GET_TPL_LEN(tpl)    (size_t)(sizeof(vmf_trace_pl_header_t) + (tpl)->tpl_len)
#endif

typedef struct
{
    unsigned8           trid;                       /* trace id  */
    unsigned8           severity;                   /* message severity 0 = highest */
    unsigned8           sequence_type;              /* 0xa1 if last message in this payload else 0xa0 */
    unsigned8           fill;                       /* fill byte */
    unsigned32          num;                        /* task message number starting at 0 */
    unsigned32          msg_time;                   /* msg time in ms */
    unsigned16          tpl_len;                    /* trace payload length */
    char                tpl[MAX_VMF_TRACE_PL_LEN];  /* trace payload */
}vmf_trace_pl_t;


/*! VMF_TRACE_CTRL_REG_CLIENT - register a trace client */
typedef struct
{
    unsigned8           trid;                       /* trace id            */
    char                name[MAX_TRACE_NAME_LEN+1]; /* unique name of a trace task */
}vmf_trace_ctrl_reg_client_t;

/*! VMF_TRACE_CTRL_FILTER_SET, VMF_TRACE_CTRL_FILTER_RESP  - vmf trace ctrl - filter for severity */
typedef struct
{
    unsigned8           trid;                       /* trace id or 0x00 for all Trace-IDs */
    unsigned8           severity;                   /* trace only messages with a severity >=  */
    unsigned8           trace_active;               /* 0x01 if trace for this trace_trid is enabled */
    unsigned8           fill;                       /* fill byte */
    char                name[MAX_TRACE_NAME_LEN+1]; /* trid name of a trace task */
}vmf_trace_ctrl_filter_severity_t;


typedef vmf_trace_ctrl_filter_severity_t    vmf_trace_ctrl_filter_response_t;

typedef struct
{
    unsigned8           enable;                     /* 0x00 if queue disabled  */
                                                    /* 0x01 if queue enabled   */
}vmf_trace_ctrl_startup_q_t;


/*! vmf trace ctrl payload inside a vmf basic-messsage */
typedef struct
{
    union
    {
        vmf_trace_ctrl_reg_client_t         reg_client;     /* VMF_TRACE_CTRL_REG_CLIENT */
        vmf_trace_ctrl_filter_severity_t    flt_severity;   /* VMF_TRACE_CTRL_SEVERITY_FILTER */
        vmf_trace_ctrl_filter_response_t    flt_response;   /* VMF_TRACE_CTRL_FILTER_RESP */
        vmf_trace_ctrl_startup_q_t          startup_q;      /* VMF_TRACE_CTRL_STARTUP_Q_SET and RESP   */
    };
}vmf_trace_ctrl_pl_t;


/* variables */
static  bool                    use_tcp=true;
static  bool                    send_download_request=false;
static  bool                    flash_done=false;
static  bool                    flash_mode=false;
static  unsigned8               tx_group=VMF_SAT_TX_GRP_DEF;
static  unsigned8               rx_group[]={1,2,VMF_TRACE_CTRL,VMF_TRACE_SYSINFO_CTRL,101,103,20,21};
static  unsigned8               trx_event=VMF_SAT_MSG_EVT_DEF;
static  bool                    synced = false;
static  int                     sync_count = 0;
static  DCB                     dcb;
static  HANDLE                  hPort = 0;
static  int                     com_port = COM_PORT_INVALID;
static  unsigned8               vmf_trid;
static  vmf_client_id_t         vmf_connection_handle;
static  int                     verbose=0;
static  LPCSTR                  portname[10] = {0};
static  bool                    dump = false;
static  int                     version=1;
static  unsigned8               ltrids[MAX_RTRID]={0};      /* stored are local trids, index = remote trid */
static  unsigned8               rtrids[MAX_RTRID]={0};      /* stored are remote trids, index = local trid */
static  char                    flash_file[1024]={0};
static  FILE                    *fp = NULL;
static  unsigned32              file_len=0;
static  unsigned32              current_len=0;
static  char                    m4_promt[]={"M4 >"};

static unsigned32               svmf_clock_offset=0;
static unsigned32               svmf_last_clock=0;
static unsigned32               vmf_time_offset=0;
static bool                     auto_start_vmf = false;
static unsigned32               last_ack;
static unsigned8                block_num;
static  int                     tcp_port = VMF_MI_SERVER_PORT;
SOCKET_T                        client_sock=-1;

/* function prototypes */
static void usage               (void);
static void current_setup       (void);
static bool GetOpt              (int argc, char *argv[]);
static bool OpenSerial          (int com_port);
static void CloseSerial         (void);
static int Receive_Message      (BYTE *buffer,int len, unsigned8 *curr_msg_cnt);
static bool WriteSerial         (unsigned16 len, unsigned8 *buffer);
static bool WriteSlowSerial     (unsigned16 len, unsigned8 *buffer);
bool create_vmf_receiver_thread (void);
static void *vmf_thread_handler (void *pNoArg);
static void vmf_ser_sender      (nw_vmf_mi_transfer_v2_t *vmf_basic_msg);
static int Read_COM(HANDLE hd, unsigned8 *buffer, int len);

static void nw_con_HexDump      (char * name,unsigned8 *buffer,int len);
static void print_dcb           (DCB *pdcb);
unsigned8   calc_cs             (unsigned8 cs,unsigned8* buff, int len);

static unsigned8                 dyn_group=VMF_TRACE_CTRL;      // VMF_DYN_0;

static unsigned8                flash_last_id=0;
static unsigned8                flash_last_group;
static unsigned8                flash_last_event;
static unsigned8                flash_last_block_num;
static unsigned8               *flash_last_buffer;
static unsigned16               flash_last_len;
static bool                     transfer_done=false;


char        conn_text[VMF_MON_TEXT_LEN] = {"not connected"};
unsigned8   conn_status =  VMF_MON_STATUS_RED;


vmf_ret_t           vmf_convert_svmf2vmf(svmf_msg_t *p_svmf_msg, unsigned16 src_len ,vmf_msg_t *p_vmf_msg,unsigned16 dest_len, unsigned8 msg_cnt);
vmf_ret_t           vmf_convert_vmf2svmf(vmf_msg_t *p_vmf_msg,svmf_msg_t *p_svmf_msg, unsigned16 dest_len);
static unsigned16   vmf_mi_calc_cs(unsigned8 *psrc, unsigned16 len);
static bool         vmf_convert_rtl_msg(vmf_client_id_t cid, vmf_msg_t *p_vmf_msg);
static bool         vmf_convert_and_filter_ltr_msg (vmf_client_id_t cid, vmf_msg_t *p_vmf_msg);
static int          read_line(HANDLE hdl, char *buffer,int len);
static void         vmf_mi_auto_start_vmf(HANDLE hdl);
static int          wait_for(HANDLE hdl, char *suchtext);
static vmf_ret_t    vmf_download_msg_handler(vmf_client_id_t cid, vmf_basic_msg_t *p_vmf_basic_msg,unsigned8 download_id, char *file, unsigned8 group);
static void         *vmf_download_thread(void *pNoArg);
static bool         create_vmf_download_thread(void);
static vmf_ret_t    vmf_download_send_block             (vmf_client_id_t cid,unsigned8 id, unsigned8 group, unsigned8 event, unsigned8 block_num, unsigned8* buffer, unsigned16 len);
static vmf_ret_t    vmf_download_send_download_request  (vmf_client_id_t cid, unsigned8 id, unsigned8 group, unsigned8 event, unsigned32 file_len, char *target_name, char *file_name);
static vmf_ret_t    vmf_download_send_download_done     (vmf_client_id_t cid, unsigned8 id, unsigned8 group, unsigned8 event);
static void         print_percent(unsigned32 file_len, unsigned32 current_len);
static vmf_ret_t    vmf_download_repeat_msg(vmf_client_id_t cid);
static void         vmf_send_time_request(vmf_client_id_t cid);

static int          vmf_mi_recv_wait(SOCKET_T *s,unsigned8* buf,int len,int flags);
static unsigned16   vmf_mi_tcp_send(SOCKET_T txSocket,nw_vmf_mi_transfer_v2_t *p_tx_msg);
static vmf_ret_t    vmf_mi_tcp_receive_message(SOCKET_T *sockd, nw_vmf_mi_transfer_v2_t *rx_buffer, unsigned16 rx_buffer_len,unsigned8 *curr_msg_cnt);
static bool         vmf_svmf_tcp_server(void);
static void         vmf_svmf_socket_close(SOCKET_T *sockd);
static vmf_ret_t    vmf_mon_send_response(vmf_client_id_t cid, char *item_name, unsigned8 status, char *status_text);


int main(int argc, char *argv[])
{
    if (false == GetOpt(argc, argv))
    {
        return 0;
    }

    if (use_tcp)
    {
        int   read_count;
        static BYTE buffer[8000] = {0};
        int    i;
        bool   bret=false;
    
    
    
        if (0 == tcp_port)
        {
            fprintf(stderr, "Invalid TCP Port -- Use -c option!\n");
            usage();
            return 0;
        }
    
        if (false == create_vmf_receiver_thread())
        {
            fprintf(stderr, "Create VMF Receiver thread faile!\n");
            return 0;
        }
    
        /* wait until connwection to VMF established */
        while (false == synced)
        {
            delay(20);
            sync_count ++;
            if (sync_count > SYNC_COUNT_MAX)
            {
                fprintf(stderr, "VMF Receiver thread did NOT sync! EXIT!!\n");
                return 0;
            }
        }
    
    
        if (VMF_TRACE_REGISTER(&vmf_trid, VMF_TRID_NAME) < 0)
        {
            fprintf(stderr, "CANNOT CONNECT TO VMF TRACER!!!\n");
        }
    
    
        vmf_svmf_tcp_server();
    
        DEBUG_INFO_HI(VMF_TRACE_TASK_MAIN, "Finished.");
        return 0;
    }
    else
    {
        int   read_count;
        static BYTE buffer[8000] = {0};
        int    i;
        bool   bret=false;
    
        if (COM_PORT_INVALID == com_port)
        {
            fprintf(stderr, "!Invalid COM Port -- Use -c option!\n");
            usage();
            return 0;
        }
    
    
        bret = OpenSerial(com_port);
        if (false == bret)
        {
            return 0;
        }
        DEBUG_INFO_HI(VMF_TRACE_TASK_MAIN, "COM Port Open -- Now waiting for commands...\n");
    
        if (auto_start_vmf)
        {
            vmf_mi_auto_start_vmf(hPort);
        }
    
        if (false == create_vmf_receiver_thread())
        {
            fprintf(stderr, "Create VMF Receiver thread faile!\n");
            return 0;
        }
    
        /* wait until connwection to VMF established */
        while (false == synced)
        {
            delay(20);
            sync_count ++;
            if (sync_count > SYNC_COUNT_MAX)
            {
                fprintf(stderr, "VMF Receiver thread did NOT sync! EXIT!!\n");
                return 0;
            }
        }
    
    
        if (VMF_TRACE_REGISTER(&vmf_trid, VMF_TRID_NAME) < 0)
        {
            fprintf(stderr, "CANNOT CONNECT TO VMF TRACER!!!\n");
        }
    
        while (true)
        {
            unsigned8 curr_rx_msg_cnt=0;
    
            /* serial receive thread */
            read_count = Receive_Message(buffer,sizeof(buffer),&curr_rx_msg_cnt);
            if (read_count > 0)
            {
                int rlen;
                vmf_ret_t   vmf_ret;
                vmf_msg_t   vmf_msg;
                nw_vmf_mi_transfer_v2_t *p_tr;
                static      bTimeRequested = false;
    
                /* convert message */
                p_tr = (nw_vmf_mi_transfer_v2_t*)buffer;
                if (VMF_OK != vmf_convert_svmf2vmf(&(p_tr->svmf_msg),read_count,&vmf_msg,sizeof(vmf_msg),curr_rx_msg_cnt))
                {
                    DEBUG_ERROR(VMF_TRACE_TASK_MAIN, "vmf_convert_svmf2vmf failed!");
                    continue;
                }
                else
                {
                    if (false == vmf_convert_rtl_msg(vmf_connection_handle, &vmf_msg))
                    {
                        continue;   /* ignore message */
                    }
                }
    
                if (false == bTimeRequested)
                {
                    /* request the current time */
                    vmf_send_time_request(vmf_connection_handle);
                    bTimeRequested = true;
                }
    
                /* forward message to VMF */
                rlen =  VMF_BASIC_MSG_LEN(vmf_msg.vmf_basic_msg.data.length);
                DEBUG_INFO_LO(VMF_TRACE_TASK_MAIN,"nw_vmf_send_basic, msg-len=%d",rlen);
                vmf_ret = nw_vmf_send_raw(vmf_connection_handle, (vmf_basic_msg_t*)&(vmf_msg.vmf_basic_msg),rlen);
                if (VMF_OK != vmf_ret)
                {
                    DEBUG_ERROR(VMF_TRACE_TASK_MAIN, "nw_vmf_send_basic failed!");
                    continue;
                }
            }
        }
    
        DEBUG_INFO_HI(VMF_TRACE_TASK_MAIN, "Finished.");
        return 0;
    }
}



/*********************************************************/
/* convert svmf message to vmf message                   */
/*********************************************************/
vmf_ret_t vmf_convert_svmf2vmf(svmf_msg_t *p_svmf_msg, unsigned16 src_len,vmf_msg_t *p_vmf_msg, unsigned16 dest_len, unsigned8 msg_cnt)
{
    vmf_basic_msg_t *vmf_basic_msg;
    vmf_ret_t       vmf_ret=VMF_OK;
    unsigned16      pl_len;
    unsigned32      svmf_curr_clock=0;


    if (p_svmf_msg->msg_type != SVMF_BASIC_MSG)
    {
#if 0
        int cp_len = dest_len;
        /* do not convert non basic messages */
        /* copy original message */
        if (src_len < dest_len)
        {
            cp_len = src_len;
        }
        DEBUG_ERROR(VMF_TRACE_TASK_MAIN,"to much data");
        memcpy(p_svmf_msg, p_vmf_msg, cp_len);
#endif
        return VMF_ERROR;
    }

    vmf_basic_msg = (vmf_basic_msg_t*) &(p_vmf_msg->vmf_basic_msg);
    pl_len = dest_len - sizeof(VMF_VAR_MSG_TYP(0));

    NW_VMF_MSG_EVENT(p_vmf_msg) = NW_SVMF_BASIC_MSG_EVENT(p_svmf_msg);
    NW_VMF_MSG_GROUP(p_vmf_msg) = NW_SVMF_BASIC_MSG_GROUP(p_svmf_msg);
    NW_VMF_MSG_TYPE(p_vmf_msg) = NW_SVMF_BASIC_MSG_TYPE(p_svmf_msg);
    NW_VMF_MSG_DATA_LENGTH(p_vmf_msg) = NW_SVMF_BASIC_MSG_DATA_LENGTH(p_svmf_msg);

    vmf_basic_msg->msg_base.base.msg_type       = MSG_TYPE_BASIC_MESSAGE;
    vmf_basic_msg->msg_base.base.pid            = p_svmf_msg->pid;
    vmf_basic_msg->msg_base.base.client_id      = p_svmf_msg->cid;
    vmf_basic_msg->msg_base.base.vmf_mi_server_id = 0;
    vmf_basic_msg->msg_base.base.co_msg_type    = 0;
    vmf_basic_msg->msg_base.base.client_count   = p_svmf_msg->client_count;
    vmf_basic_msg->msg_base.base.vmf_debug_85   = msg_cnt;
    svmf_curr_clock                             = (p_svmf_msg->msg_time_hh * 65536) + p_svmf_msg->msg_time;

    DEBUG_INFO_LO(VMF_TRACE_TASK_MAIN,"pl-len = %d", NW_VMF_MSG_DATA_LENGTH(p_vmf_msg));

    svmf_clock_offset = nw_os_cfg_get_ms_time() & 0xff000000;

    vmf_basic_msg->msg_base.base.msg_clk        =  svmf_clock_offset + svmf_curr_clock;
    svmf_last_clock                             =  svmf_curr_clock;


    vmf_basic_msg->msg_base.base.vmf_mi_server_id = SVMF_SRV_BACKFIRE;

    if (NW_SVMF_BASIC_MSG_DATA_LENGTH(p_svmf_msg) <= VMF_CLIENT_DATA_SIZE_STANDARD)
    {
        memcpy(NW_VMF_MSG_DATA_PTR(p_vmf_msg), NW_SVMF_BASIC_MSG_DATA_PTR(p_svmf_msg),NW_VMF_MSG_DATA_LENGTH(p_vmf_msg));
        DEBUG_INFO_LO(VMF_TRACE_TASK_MAIN,"copy data %dbytes to vmf message",NW_VMF_MSG_DATA_LENGTH(p_vmf_msg));

    }
    else
    {
        DEBUG_ERROR(VMF_TRACE_TASK_MAIN,"to much data");
        vmf_ret = VMF_ERROR;
    }

    DEBUG_INFO_LO(VMF_TRACE_TASK_MAIN,"vmf_convert_svmf2vmf length = %dbytes",NW_SVMF_BASIC_MSG_DATA_LENGTH(p_svmf_msg));

    return vmf_ret;
}



/*********************************************************/
/* convert vmf message to svmf message                   */
/*********************************************************/
vmf_ret_t vmf_convert_vmf2svmf(vmf_msg_t *p_vmf_msg,svmf_msg_t *p_svmf_msg, unsigned16 dest_len)
{
    vmf_ret_t vmf_ret=VMF_OK;
    unsigned16  pl_len;

    pl_len = dest_len - SVMF_MIN_MSG_LEN;
    DEBUG_INFO_LO(VMF_TRACE_TASK_MAIN,"vmf_convert_vmf2svmf");

//    printf("\np_vmf_msg->msg_base.base.msg_clk = %d\n",((vmf_basic_msg_t*)p_vmf_msg)->msg_base.base.msg_clk);

    NW_SVMF_BASIC_MSG_TYPE(p_svmf_msg)  = SVMF_BASIC_MSG;
    NW_SVMF_BASIC_MSG_GROUP(p_svmf_msg) = NW_VMF_MSG_GROUP(p_vmf_msg);
    NW_SVMF_BASIC_MSG_EVENT(p_svmf_msg) = NW_VMF_MSG_EVENT(p_vmf_msg);
    NW_SVMF_BASIC_MSG_DATA_LENGTH(p_svmf_msg) = NW_VMF_MSG_DATA_LENGTH(p_vmf_msg);

    if (NW_VMF_MSG_DATA_LENGTH(p_vmf_msg) <= pl_len)
    {
        memcpy(NW_SVMF_BASIC_MSG_DATA_PTR(p_svmf_msg),NW_VMF_MSG_DATA_PTR(p_vmf_msg),NW_SVMF_BASIC_MSG_DATA_LENGTH(p_svmf_msg));
    }
    else
    {
        DEBUG_ERROR(VMF_TRACE_TASK_MAIN,"to much data");
        vmf_ret = VMF_ERROR;
    }
    return vmf_ret;
}




/*
*******************************************************************************************************
*** Serial (Windows)
*******************************************************************************************************
*/
static bool OpenSerial(int com_port)
{
    char ch_com_port[10]={0};

    DWORD bytes_read_count;
    BYTE read_buffer[100];
    DWORD dwFlags;
    unsigned8 my_dcb[]={0x1c,0x00,0x00,0x00,0x00,0xe1,0x00,0x00,0x81,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
                        0x00,0x02,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

    (void) itoa(com_port, ch_com_port, 10);
    snprintf((char *)portname, sizeof(portname), "\\\\.\\COM%s",  ch_com_port);
    DEBUG_INFO_HI(VMF_TRACE_TASK_COM, "ComPort=%02d, Portname == %s",com_port, (char *)portname);

    hPort = CreateFile((LPCSTR)portname, GENERIC_READ  | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);


    DEBUG_INFO_HI(VMF_TRACE_TASK_COM, "Handle %d -- Error=%d ", hPort, GetLastError());
    memcpy(&dcb,my_dcb,sizeof(dcb));

    dcb.BaudRate = SERIAL_BAUDRATE; //Baudrate
    dcb.ByteSize = 8;               //data bits
    dcb.Parity = NOPARITY;          //parity
    dcb.StopBits = ONESTOPBIT;      //stop bits
    dcb.fBinary    =  TRUE;
    dcb.fParity   = FALSE;
    dcb.fOutxCtsFlow  = FALSE;
    dcb.fOutxDsrFlow  = FALSE;
    dcb.fDtrControl    = DTR_CONTROL_ENABLE; // DTR_CONTROL_DISABLE;
    // dcb.fDsrSensitivity  = FALSE;
    dcb.fTXContinueOnXoff = TRUE;
    dcb.fOutX      = FALSE;
    dcb.fInX      = FALSE;
    dcb.fErrorChar    = FALSE;
    dcb.fNull      = FALSE;
    dcb.fRtsControl    = RTS_CONTROL_ENABLE; //RTS_CONTROL_DISABLE;
    dcb.fAbortOnError  = FALSE;
    dcb.wReserved    = 0;
    dcb.fAbortOnError = FALSE;

    if (!SetCommState(hPort,&dcb))
    {
        DEBUG_ERROR(VMF_TRACE_TASK_COM, "Error 2 opening COM port");
        return false;
    }

    {
        COMMTIMEOUTS tos;
        tos.ReadIntervalTimeout = 0;
        tos.ReadTotalTimeoutMultiplier = 0;
        tos.ReadTotalTimeoutConstant = 10;
        tos.WriteTotalTimeoutConstant = 0;
        tos.WriteTotalTimeoutMultiplier = 0;
        SetCommTimeouts( hPort, &tos );
    }

    /* Get rid of rubbish */
    dwFlags = PURGE_RXCLEAR | PURGE_TXCLEAR;
    PurgeComm(hPort, dwFlags);

    return true;
}

static void CloseSerial(void)
{
    CloseHandle(hPort);
}

/*********************************************************/
/* read a number of bytes from a device                  */
/*********************************************************/
static int Read_COM(HANDLE hd, unsigned8 *buffer, int len)
{

    int sum_received=0;
    DWORD  bytes_read_count=0;
    DWORD  dwCommModemStatus=0;
    DWORD  dwError=0;

    DEBUG_INFO_LO(VMF_TRACE_TASK_COM,"Read_COM %d bytes\n",len);
    while (sum_received < len)
    {
//        if (ReadFile (hd, &(buffer[sum_received]), len-sum_received, &bytes_read_count, 0))
        if (ReadFile (hd, &(buffer[sum_received]), 1,  &bytes_read_count, 0))
        {
#if 0
            if (dump)
            {
                if (bytes_read_count>0)
                {
                     nw_con_HexDump("Read_COM",&(buffer[sum_received]),bytes_read_count);
                }
            }
#endif
            sum_received+=bytes_read_count;
            delay(0);               /* important!! without delay (or printf) it will take forever before the other thread is activated */
        }
        else
        {
            /* read error */
            // printf(".");
            DEBUG_INFO_LO(VMF_TRACE_TASK_COM, "ReadFile failed - bytes_read_count=%d",bytes_read_count);
            return 0;
        }
    }

    if (dump)
    {
        if (sum_received>0)
        {
             nw_con_HexDump("Read_COM",buffer,sum_received);
        }
    }
    // nw_con_HexDump("Read_COM return",buffer,sum_received);
    DEBUG_INFO_LO(VMF_TRACE_TASK_COM,"Read_COM return %d bytes\n",sum_received);

    return sum_received;
}




/*********************************************************/
/* receive a message via the COM                         */
/*********************************************************/
static int Receive_Message(BYTE *buffer,int len,unsigned8 *curr_msg_cnt)
{
    enum
    {
        NO_SYNC,
        SYNC_1,
        SYNC_2,
        PROMPT
    };
    int                        retVal = 0;
    int                        bytes_read = 0;
    unsigned8                  byte_received;
    int                        syncted=NO_SYNC;
    int                        ret_val=0;
    unsigned16                 pl_len=0;
    bool                       do_ret=false;
    nw_vmf_mi_transfer_v2_t    *tr_msg;
    tr_msg = (nw_vmf_mi_transfer_v2_t*)buffer;
    unsigned8                   curr_rx_msg_cnt=0;
    unsigned8                   promt_ix=0;
    while (true)
    {
        syncted = NO_SYNC;
        bytes_read = 0;
        promt_ix =0;

        /* wait for sync */
        DEBUG_INFO_LO(VMF_TRACE_TASK_VMF,"Wait for Sync");
        while((syncted != SYNC_2) && (false == do_ret))
        {
            ret_val = Read_COM (hPort, &byte_received, 1);  // read sync byte
            if (ret_val > 0)
            {
                switch (syncted)
                {
                    case NO_SYNC:
                    if (byte_received == VALID_TOKEN0)
                    {
                        DEBUG_INFO_LO(VMF_TRACE_TASK_VMF, "received VALID_TOKEN0");
                        syncted=SYNC_1;
                        bytes_read++;
                        promt_ix=0;
                    }
                    else if ( byte_received ==  m4_promt[promt_ix])
                    {
                        /* it may be the promt */  
                        promt_ix++; 
                        if (promt_ix >= strlen(m4_promt))
                        {
                            /* we received a promt !*/
                            /* send auto login */
                            vmf_mi_auto_start_vmf(hPort);
                        }
                    }
                    else
                    {
                        bytes_read  = 0;
                        syncted     = NO_SYNC;
                    }
                    break;

                    case SYNC_1:
                    if (byte_received == VALID_TOKEN1)
                    {
                        DEBUG_INFO_LO(VMF_TRACE_TASK_VMF, "received VALID_TOKEN1");
                        bytes_read++;
                        syncted=SYNC_2;
                    }
                    else
                    {
                        bytes_read =0;
                        syncted = NO_SYNC;
                    }
                    break;
                }
            }
        }

        /* in sync read header */
        {
            int hlen;
            hlen = sizeof(nw_vmf_mi_transfer_v2_header_t)-bytes_read;
            DEBUG_INFO_LO(VMF_TRACE_TASK_VMF,"read %d byte header",hlen);
            ret_val = Read_COM(hPort,(unsigned8*) &(tr_msg->version_l), hlen);
            if (ret_val != hlen)
            {
                DEBUG_INFO_LO(VMF_TRACE_TASK_COM, "reading header failed");
                continue;
            }
         }

        /* in sync read svmf msg */
        {
            if(tr_msg->svmf_len > len)
            {
                DEBUG_INFO_LO(VMF_TRACE_TASK_COM, "Receive_Message pl_len=%d will not fit in buffer (len=%d) -  cutting message ", tr_msg->svmf_len,len);
                continue;
            }

            DEBUG_INFO_LO(VMF_TRACE_TASK_VMF,"read %d byte payload",tr_msg->svmf_len);
            ret_val = Read_COM (hPort,(unsigned8*) &(tr_msg->svmf_msg), tr_msg->svmf_len);      // read svmf message
            if (ret_val > 0)
            {
                unsigned16 cs=0;
                unsigned16 rx_cs=0;
                bytes_read += ret_val;
                DEBUG_INFO_LO(VMF_TRACE_TASK_COM, "read svmf-msg ret = %d ", ret_val);

                /* test cid */
                if ((0 == tr_msg->svmf_msg.cid) && (0 == tr_msg->svmf_msg.pid))
                {
                    /* echo ?? */
                    continue;
                }

                if (NULL != curr_msg_cnt)
                {
                    *curr_msg_cnt = tr_msg->comp;
                }

                /* calc checksumm */
                rx_cs =  ((tr_msg->csum_h) * 256) + tr_msg->csum_l;
#if 1
                if (0 == rx_cs)
                {
                    /* no cs calculation needed */
                   conn_status = VMF_MON_STATUS_GREEN;
                   snprintf(conn_text,VMF_MON_TEXT_LEN,"client on com%d connected to gateway",com_port);
                   break;       /* reception of message done */
                }
#endif
                cs = vmf_mi_calc_cs((unsigned8*)&(tr_msg->svmf_msg),tr_msg->svmf_len);
                if (cs == rx_cs)
                {
                    DEBUG_INFO_LO(VMF_TRACE_TASK_COM,"CS OK=%04x",rx_cs);
                    conn_status = VMF_MON_STATUS_GREEN;
                    snprintf(conn_text,VMF_MON_TEXT_LEN,"client on com%d connected to gateway",com_port);

                    break;      /* reception of message done */
                }
                else
                {
                    DEBUG_INFO_HI(VMF_TRACE_TASK_COM, "CS error: tr_msg->csum_l=%04x",tr_msg->csum_l);
                    conn_status = VMF_MON_STATUS_YELLOW;
                    snprintf(conn_text,VMF_MON_TEXT_LEN,"CS error");
                    continue;   /* cs error */
                }
            }
            else
            {
                DEBUG_INFO_LO(VMF_TRACE_TASK_COM, "reading svmf-msg failed");
                continue;
            }
         }
    }
    DEBUG_INFO_LO(VMF_TRACE_TASK_COM, "return  %d ", bytes_read);
    return bytes_read;
}




/*
*******************************************************************************************************
*** write a buffer content to serial
*******************************************************************************************************
*/
static bool WriteSerial(unsigned16 len, unsigned8 *buffer)
{
    int     summ = 0;
    bool    ret_val = true;
    DWORD   bytes_written_count = 0;

    do
    {
        DEBUG_INFO_LO(VMF_TRACE_TASK_COM, "writing %d bytes to serial ",len);
        ret_val = WriteFile(hPort, (char *)&(buffer[summ]), (DWORD)len, &bytes_written_count, NULL);
        summ +=bytes_written_count;
        DEBUG_INFO_LO(VMF_TRACE_TASK_COM, "summ=%d, ret_val=%d",summ,ret_val);

    }while(summ < len);
    DEBUG_INFO_LO(VMF_TRACE_TASK_COM, "writing to serial done ret_val =%d, bytes_written=%d",ret_val,bytes_written_count);
    if (dump)
    {
        if (len>0)
        {
             nw_con_HexDump("Write_COM",buffer,len);
        }
    }
    return ret_val;
}


static bool WriteSlowSerial(unsigned16 len, unsigned8 *buffer)
{
    int     summ = 0;
    bool    ret_val = true;
    DWORD   bytes_written_count = 0;

    do
    {
        DEBUG_INFO_LO(VMF_TRACE_TASK_COM, "writing %d bytes to serial ",len);
        ret_val = WriteFile(hPort, (char *)&(buffer[summ]), (DWORD)1, &bytes_written_count, NULL);
        summ +=bytes_written_count;
        DEBUG_INFO_LO(VMF_TRACE_TASK_COM, "summ=%d, ret_val=%d",summ,ret_val);
        delay(20);
    }while(summ < len);
    DEBUG_INFO_LO(VMF_TRACE_TASK_COM, "writing to serial done ret_val =%d, bytes_written=%d",ret_val,bytes_written_count);
    if (dump)
    {
        if (summ>0)
        {
             nw_con_HexDump("Write_COM",buffer,summ);
        }
    }
    return ret_val;
}






/*************************************************************************//**
 *
 *   receives data from a socket untill all data is received  \n
 *   NOTE: done because MSG_WAITALL is not supported on MQX
 *
 *
 *   \param[in] SOCKET   -- socket
 *   \param[in] buf      -- buffer for rx data
 *   \param[in] len      -- buffer len
 *   \param[in] flags    -- rx flags
 *   \return    number of bytes or 0 or -1
 *
 ******************************************************************************/
static int vmf_mi_recv_wait(SOCKET_T *s,unsigned8* buf,int len,int flags)
{
    int num_bytes;
    unsigned16  all_bytes=0;

    if ((NULL == s) || (NULL == buf))
    {
        return 0;
    }
    else if (*s == -1)
    {
        return 0;
    }
    

    while (all_bytes < len)
    {
        num_bytes = recv(*s, &(buf[all_bytes]), len-all_bytes, flags);
        if (num_bytes > 0)
        {
            all_bytes+=num_bytes;
        }
        else
        {
            /* socket closed ?! */
            /* invalidate handle to allow reconnect */
            vmf_svmf_socket_close(s);
            return num_bytes;
        }
    }
    return all_bytes;
}



/**************************************************************************//**
 *
 *   Function Name: vmf_mi_tcp_receiver()
 *
 *   Description:   receive and handle messages from connected socket
 *                  this function will only return in case on an error
 *
 *   \param[in]     pointer to socket handle
 *   \param[in]     pointer to receive buffer
 *   \param[in]     length of receive buffer
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
static vmf_ret_t vmf_mi_tcp_receive_message  (SOCKET_T *sockd, nw_vmf_mi_transfer_v2_t *rx_buffer, unsigned16 rx_buffer_len, unsigned8 *curr_msg_cnt)
{
    vmf_ret_t   ret_val = VMF_ERROR;

    /* try to reconnect */

    /* argument check */
    if ((NULL == sockd) || (NULL == rx_buffer))
    {
        return VMF_ERR_NULL_POINTER;
    }
    else if (0 == rx_buffer_len)
    {
        return VMF_ERR_OUT_OF_RANGE;
    }
    /* check if socket is connected */
    else if (-1 == *sockd)
    {
        return VMF_ERROR;
    }

    /* reception loop */
    while(true)
    {
        size_t  wanted_len=0;
        int     summ_bytes=0;
        int     num_bytes;

        /* wait for sync */
        while(true)
        {
            /* sync token 0 */
            num_bytes = vmf_mi_recv_wait(sockd, (unsigned8 *)&(rx_buffer->token0), 1, 0);
            if (num_bytes <= 0)
            {
                nw_sleep_ms(1);
               // vmf_mi_tcp_disconnect(sockd);
                break;              /* socket was closed !*/
            }
            if (VALID_TOKEN0 != rx_buffer->token0)
            {
                continue;
            }
            summ_bytes=1;
            
            /* sync token 1 */
            num_bytes = vmf_mi_recv_wait(sockd, (unsigned8 *)&(rx_buffer->token1), 1, 0);
            if (num_bytes <= 0)
            {
                nw_sleep_ms(1);
                // vmf_mi_tcp_disconnect(sockd);
                break;              /* socket was closed !*/
            }
            if (VALID_TOKEN1 != rx_buffer->token1)
            {
                continue;
            }
            else
            {
                summ_bytes++;
                break;              /* we are synced */
            }
        }

        /* we are synced              */
        /* receive the message header */
        wanted_len = sizeof(nw_vmf_mi_transfer_v2_header_t) - (sizeof(rx_buffer->token0) + sizeof(rx_buffer->token1));
        num_bytes = vmf_mi_recv_wait(sockd, (unsigned8 *)&(rx_buffer->version_l), wanted_len, 0);
        if (wanted_len == num_bytes)
        {
            summ_bytes+=num_bytes;

            /* test message len */
            if ( rx_buffer->svmf_len > (rx_buffer_len - sizeof(nw_vmf_mi_transfer_v2_header_t)))
            {
                /* message will not fit into buffer - so ignore */
                DEBUG_INFO_HI(VMF_TRACE_TASK_TCP, "message will not fit into buffer, msg len=%d",rx_buffer->svmf_len);
            }
            else if (rx_buffer->svmf_len > 0)
            {
                /* received vmf-msg length          */
                /* reveive remaining data = vmf_msg */
                num_bytes = vmf_mi_recv_wait(sockd, (unsigned8 *)&(rx_buffer->svmf_msg), rx_buffer->svmf_len, 0);
                if (num_bytes != rx_buffer->svmf_len)
                {
                    /* got invalid number of bytes */
                    /* receive next message        */
                    num_bytes = 0;
                }
                else
                {
                    summ_bytes+=num_bytes;
       
                    /* got a message - so leave the loop        */
                    if (dump)
                    {
                        if (summ_bytes>0)
                        {
                             nw_con_HexDump("TCP-Read",(unsigned8*)&(rx_buffer),summ_bytes);
                        }
                    }

                    if (NULL != curr_msg_cnt)
                    {
                        *curr_msg_cnt = rx_buffer->comp;
                    }


                    ret_val=VMF_OK;
                    /* return to calling function */
                    break;
                }
            }
            else
            {
                /* we received a keep alive message */
                /* ignore and wait for next message */
            }
        }
        else if (num_bytes > 0)
        {
            /* invalid message length */
            /* ignore message and wait for next message */
        }
        else
        {
            /* rx error - so leave the loop */
            break;
        }
    }

    return ret_val;
}


/**************************************************************************//**
 *
 *   Function Name: vmf_mi_tcp_receiver()
 *
 *   Description:   receive and handle messages from connected socket
 *                  this function will only return in case on an error
 *
 *   \param[in]     pointer to socket handle
 *   \param[in]     pointer to receive buffer
 *   \param[in]     length of receive buffer
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
static vmf_ret_t vmf_mi_tcp_receive_message_a(SOCKET_T *sockd, nw_vmf_mi_transfer_v2_t *rx_buffer, unsigned16 rx_buffer_len,unsigned8 *curr_msg_cnt)
{
    vmf_ret_t   ret_val = VMF_ERROR;
    int         summ_bytes=0;


    /* argument check */
    if ((NULL == sockd) || (NULL == rx_buffer))
    {
        return VMF_ERR_NULL_POINTER;
    }
    else if (0 == rx_buffer_len)
    {
        return VMF_ERR_OUT_OF_RANGE;
    }
    /* check if socket is connected */
    else if (-1 == *sockd)
    {
        return VMF_ERROR;
    }

    /* reception loop */
   DEBUG_INFO_LO(VMF_TRACE_TASK_TCP, "enter receive loop");
   while(true)
    {
        size_t wanted_len=0;
        int num_bytes;

        /* wait for sync */
        while(true)
        {
            /* sync token 0 */
            num_bytes = vmf_mi_recv_wait(sockd, (char *)&(rx_buffer->token0), 1, 0);
            if (num_bytes < 1)
            {
                nw_sleep_ms(1);
                break;              /* socket was closed !*/
            }
            if (VALID_TOKEN0 != rx_buffer->token0)
            {
                continue;
            }

            /* sync token 1 */
            summ_bytes++;
            num_bytes = vmf_mi_recv_wait(sockd, (char *)&(rx_buffer->token1), 1, 0);
            if (num_bytes < 1)
            {
                nw_sleep_ms(1);
                break;              /* socket was closed !*/
            }
            if (VALID_TOKEN1 != rx_buffer->token1)
            {
                continue;
            }
            else
            {
                break;              /* we are synced */
            }
        }

        /* we are synced           */
        /* receive the message len */
        DEBUG_INFO_LO(VMF_TRACE_TASK_TCP, "in sync");

        summ_bytes++;
        wanted_len = sizeof(rx_buffer->svmf_len);       /* length of vmf-len */
        num_bytes = vmf_mi_recv_wait(sockd, (char *)&(rx_buffer->svmf_msg), wanted_len, 0);
        if (wanted_len == num_bytes)
        {
            summ_bytes+=wanted_len;

            /* test message len */
            if ( rx_buffer->svmf_len > (rx_buffer_len - sizeof(nw_vmf_mi_transfer_v2_header_t)))
            {
                /* mesage will not fit into buffer - so ignore */
            }
            else if (rx_buffer->svmf_len > 0)
            {
                /* received vmf-msg length          */
                /* reveive remaining data = vmf_msg */
                num_bytes = vmf_mi_recv_wait(sockd, (char *)&(rx_buffer->svmf_msg), rx_buffer->svmf_len, 0);
                if (num_bytes != rx_buffer->svmf_len)
                {
                    /* got invalid number of bytes */
                    /* receive next message        */
                    num_bytes = 0;
                }
                else
                {
                    /* got a message - so leave the loop        */
                    ret_val=VMF_OK;

                    summ_bytes+=num_bytes;
                    DEBUG_INFO_LO(VMF_TRACE_TASK_TCP, "received %d bytes",summ_bytes);

                    if (dump)
                    {
                        if (summ_bytes>0)
                        {
                             nw_con_HexDump("TCP-Read",(unsigned8*)&(rx_buffer),summ_bytes);
                        }
                    }


                    if (NULL != curr_msg_cnt)
                    {
                        *curr_msg_cnt = rx_buffer->comp;
                    }

                    /* return to calling function */
                    break;
                }
            }
            else
            {
                /* we received a keep alive message */
                /* ignore and wait for next message */
            }
        }
        else if (num_bytes > 0)
        {
            /* invalid message length */
            /* ignore message and wait for next message */
        }
        else
        {
            /* rx error - so leave the loop */
            break;
        }
    }

    return ret_val;
}




/**************************************************************************//**
 *
 *   Function Name: vmf_svmf_tcp_server()
 *
 *   Description:   tcp server task
 *
 *
 *   \param[in]     void
 *
 *   Function Return value: - bool
 *
 ******************************************************************************/
static bool    vmf_svmf_tcp_server(void)
{
    int         addrlen;
    int         status;
    struct      sockaddr_in  server_name;
    struct      sockaddr_in  client_name;
    WSADATA     wsaData;
    SOCKET_T    list_sock;
    unsigned8   curr_rx_msg_cnt=0;

    #define     NUM_CON 5
    #define     ever    ;;

    int wsaret=WSAStartup(0x101,&wsaData);
    if(wsaret!=0)
    {
       return 0;
    }

    /* create and bind socket */

    /* create a socket */
    list_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (list_sock == -1)
    {
        return false;
    }

    /* server address  */
    server_name.sin_family = AF_INET;
    server_name.sin_addr.s_addr = INADDR_ANY;
    server_name.sin_port = htons(tcp_port);

    status = bind(list_sock, (struct sockaddr*)&server_name, sizeof(server_name));
    if (status == -1)
    {
        return false;
    }

    DEBUG_INFO(VMF_TRACE_TASK_MAIN, "started tcp listener on port %d",tcp_port);

    conn_status = VMF_MON_STATUS_RED;
    snprintf(conn_text,VMF_MON_TEXT_LEN,"listening to tcp port %d",tcp_port);

    status = listen(list_sock, NUM_CON);
    if (status == -1)
    {
        return false;
    }

    /* wait and accept connection */
    for(ever)
    {
        bool bTimeRequested = false;
    
        /* wait for a connection */
        addrlen = sizeof(client_name);
        client_sock = accept(list_sock, (struct sockaddr*)&client_name, &addrlen);
        if (client_sock != -1)
        {
            DEBUG_INFO(VMF_TRACE_TASK_MAIN, "client %s connected to svmf-tcp-gateway ",inet_ntoa(client_name.sin_addr));
            /* got connection */
            /* start receiver */
            conn_status = VMF_MON_STATUS_GREEN;
            snprintf(conn_text,VMF_MON_TEXT_LEN,"client %s connected to svmf-tcp-gateway ",inet_ntoa(client_name.sin_addr));
            bTimeRequested= false;
            for(ever)
            {
                vmf_ret_t   ret_val;
                vmf_msg_t   vmf_msg;
                int         rlen;
                nw_vmf_mi_transfer_v2_t rx_buffer;
    
                ret_val = vmf_mi_tcp_receive_message(&client_sock, &rx_buffer, sizeof(rx_buffer),&curr_rx_msg_cnt);
                if (VMF_OK == ret_val)
                {
                    /* convert and send message to vmf */
                    /* convert message */
                    if (VMF_OK != vmf_convert_svmf2vmf(&(rx_buffer.svmf_msg),0,&vmf_msg,sizeof(vmf_msg),curr_rx_msg_cnt))
                    {
                        DEBUG_ERROR(VMF_TRACE_TASK_MAIN, "vmf_convert_svmf2vmf failed!");
                        continue;
                    }
                    else
                    {
                        if (false == vmf_convert_rtl_msg(vmf_connection_handle, &vmf_msg))
                        {
                            continue;   /* ignore message */
                        }
                    }
    
                    if (false == bTimeRequested)
                    {
                        /* request the current time */
                        vmf_send_time_request(vmf_connection_handle);
                        bTimeRequested = true;
                    }
    
                    /* forward message to VMF */
                    rlen =  VMF_BASIC_MSG_LEN(vmf_msg.vmf_basic_msg.data.length);
                    DEBUG_INFO_LO(VMF_TRACE_TASK_MAIN,"nw_vmf_send_basic, msg-len=%d",rlen);
                    ret_val = nw_vmf_send_raw(vmf_connection_handle, (vmf_basic_msg_t*)&(vmf_msg.vmf_basic_msg),rlen);
                    if (VMF_OK != ret_val)
                    {
                        DEBUG_ERROR(VMF_TRACE_TASK_MAIN, "nw_vmf_send_basic failed!");
                        continue;
                    }
    
                }
                else
                {
                    /* wait for new connection */
                    DEBUG_INFO(VMF_TRACE_TASK_MAIN, "lost connection to client %s",inet_ntoa(client_name.sin_addr));
                    conn_status = VMF_MON_STATUS_RED;
                    snprintf(conn_text,VMF_MON_TEXT_LEN,"lost connection to client %s",inet_ntoa(client_name.sin_addr));
                    
                    vmf_svmf_socket_close(&client_sock);
                    memset(ltrids,0,sizeof(ltrids));
                    break;
                }
            }
        }
    }
    vmf_svmf_socket_close(&list_sock);
    WSACleanup();
    return true;
}





/*************************************************************************//**
 *
 *   send a buffer via tcp \n
 *   NOTE:
 *
 *   \param[in]     socket
 *   \param[in]     transfer message address
 *   \param[in]     length of transfer message
 *   \return        number of writte bytes
 *
 ******************************************************************************/
static unsigned16  vmf_mi_tcp_send(SOCKET_T txSocket,nw_vmf_mi_transfer_v2_t *tr_msg)
{
    int         transfer_msg_len=0;
    int         transfer_len=0;
    vmf_ret_t   vmf_ret;
    unsigned16  cs=0;

    /* argument check */
    if (NULL == tr_msg)
    {
        return 0;
    }
    else if (txSocket == -1)
    {
        DEBUG_INFO_LO(VMF_TRACE_TASK_TCP, "vmf_mi_tcp_send: socket not connected");
        return 0;
    }

   /* fill transfer message */
    tr_msg->token0      =  VALID_TOKEN0;
    tr_msg->token1      =  VALID_TOKEN1;
    tr_msg->version_l   =  VMF_MI_VERISION_L;
    tr_msg->version_h   =  VMF_MI_VERISION_H;
    tr_msg->comp = COMP_MI_NO;                  // no compression 
    tr_msg->csum_l = 0;
    tr_msg->csum_h = 0;
    tr_msg->svmf_len =  SVMF_MSG_LEN(tr_msg->svmf_msg.pl_len);

    /* calculate cs */
    cs = vmf_mi_calc_cs((unsigned8*)&(tr_msg->svmf_msg),tr_msg->svmf_len);
    tr_msg->csum_l = cs & 0xff;
    tr_msg->csum_h = cs >> 8;

    transfer_msg_len = sizeof(nw_vmf_mi_transfer_v2_header_t) + tr_msg->svmf_len;

    DEBUG_INFO_HI(VMF_TRACE_TASK_TCP, "vmf_mi_tcp_send: send message with %d bytes",transfer_msg_len);

    transfer_len = send(txSocket,( char *)tr_msg,transfer_msg_len,0);

    if (dump)
    {
        if (transfer_len>0)
        {
             nw_con_HexDump("vmf_mi_tcp_send: TCP-Write",(unsigned8*)tr_msg,transfer_len);
        }
    }
    if (transfer_len<=0)
    {
        DEBUG_ERROR(VMF_TRACE_TASK_TCP, "vmf_mi_tcp_send: send() failed with %d",transfer_len);
        transfer_len = 0;
    }
    else
    {
        DEBUG_INFO_LO(VMF_TRACE_TASK_TCP, "vmf_mi_tcp_send: send() %d bytes OK ",transfer_len);
    }
    

    return transfer_len;
}




/*
*******************************************************************************************************
*** VMF
*******************************************************************************************************
*/
bool create_vmf_receiver_thread(void)
{
    int             iRet;
    pthread_t       th;
    pthread_attr_t  attr;

    /* set thread stack */
    pthread_attr_init( &attr );
    if ( pthread_attr_setstacksize(&attr, VMF_RECEIVER_STACK_SIZE ) != 0 )
    {
        DEBUG_ERROR(VMF_TRACE_TASK_VMF, "create_vmf_receiver_thread() - pthread_attr_setstacksize() failed");
    }

    (void)pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED );
    iRet = pthread_create (&th  , &attr, vmf_thread_handler, NULL);
    pthread_attr_destroy(&attr);
    if (iRet)
    {
        DEBUG_ERROR(VMF_TRACE_TASK_VMF, "create_vmf_receiver_thread() error! errno = %d",iRet);
        return false;
    }

    return true;
}


static void *vmf_thread_handler(void *pNoArg)
{
    vmf_ret_t vmf_ret;
    VMF_VAR_MSG_TYP(IO_MSG_DATALEN_MAX) vmf_msg;
    vmf_msg_t *p_vmf_msg = (vmf_msg_t *)&vmf_msg;
    vmf_basic_msg_t *p_vmf_basic_msg = (vmf_basic_msg_t *)&vmf_msg;



    DEBUG_INFO_HI(VMF_TRACE_TASK_VMF, "VMF Receiver started...");

    vmf_ret = nw_vmf_connect(VMF_TRID_NAME, 0, 0, VMF_CLIENT_QUEUE_SIZE_STANDARD, VMF_CLIENT_QUEUE_MSG_SIZE_STANDARD);
    if (vmf_ret < 0)
    {
        printf("send_basic_message: connect failed --error %d\n",(int)vmf_connection_handle);
        return;
    }
    else
    {
        vmf_connection_handle = vmf_ret;
    }

    vmf_ret = nw_vmf_register_msg_group (vmf_connection_handle, sizeof(rx_group), rx_group);
    if (vmf_ret < 0)
    {
        DEBUG_ERROR(VMF_TRACE_TASK_VMF, "nw_vmf_register_msg_group failed -- vmf_ret == %d", vmf_ret);
    }

    /* allow main to go on... */
    synced = true;

    while(true)
    {
        p_vmf_msg = (vmf_msg_t *)&vmf_msg;
        vmf_ret = nw_vmf_timed_receive (vmf_connection_handle, p_vmf_msg, sizeof(vmf_msg),100);
        DEBUG_INFO_LO(VMF_TRACE_TASK_VMF,"vmf_thread_handler() nw_vmf_timed_receive() returned %d",vmf_ret);

        if (vmf_ret > 0)
        {
            p_vmf_basic_msg = (vmf_basic_msg_t *)&(vmf_msg.vmf_basic_msg);
            if (p_vmf_basic_msg->msg_base.base.vmf_mi_server_id  == SVMF_SRV_BACKFIRE)
            {
                /* prevent backfire */
                continue;
            }

            if (MSG_TYPE_BASIC_MESSAGE == NW_VMF_BASIC_MSG_TYPE(p_vmf_basic_msg))
            {
                nw_vmf_mi_transfer_v2_t  tr_msg;

                /* received a message */
                /* convert the message */
                if (true == vmf_convert_and_filter_ltr_msg (vmf_connection_handle, p_vmf_msg))
                {
                    vmf_ret = vmf_convert_vmf2svmf(p_vmf_msg,&(tr_msg.svmf_msg), SVMF_PL_LEN_STD);
                    if (VMF_OK == vmf_ret)
                    {
                        DEBUG_INFO_LO(VMF_TRACE_TASK_VMF,"send message-type =%d, group=%d",tr_msg.svmf_msg.msg_type,tr_msg.svmf_msg.group);
                        if (use_tcp)                     
                        {
                            (void)vmf_mi_tcp_send(client_sock,&tr_msg);
                        }
                        else
                        {
                            vmf_ser_sender(&tr_msg);
                        }
                    }
                    else
                    {
                        DEBUG_INFO_HI(VMF_TRACE_TASK_VMF, "vmf_convert_vmf2svmf failed()");
                    }
                }
                else
                {
                    DEBUG_INFO_LO(VMF_TRACE_TASK_VMF,"vmf_convert_and_filter_ltr_msg returned false");
                }
            }
            else
            {
                DEBUG_INFO_HI(VMF_TRACE_TASK_VMF, "This is not a basic message! msg-type=%d",NW_VMF_BASIC_MSG_TYPE(p_vmf_basic_msg));
                nw_con_HexDump("vmf_msg",(unsigned8*)p_vmf_basic_msg,vmf_ret);
            }
        }
        else if (0 == vmf_ret)
        {
            /* could happen -- do nothing...*/
        }
        else
        {
            /* error during vmf_receive -- wait some time and try again... */
            DEBUG_ERROR(VMF_TRACE_TASK_VMF, "vmf_receive failed -- vmf_ret == %d", vmf_ret);
            delay(20);
        }
    }
}







/*
*******************************************************************************************************
*** adapt  remote VMF trace messages message  to local trace messages
*** the function will replace the remote trids with local trids
*******************************************************************************************************
*/
static bool vmf_convert_rtl_msg (vmf_client_id_t cid, vmf_msg_t *p_vmf_msg)
{
    unsigned8       rtrid=0;
    bool            bret = true;

    if (NULL == p_vmf_msg)
    {
        bret = false;
        return;
    }
    else if (NW_VMF_MSG_TYPE(p_vmf_msg) != MSG_TYPE_BASIC_MESSAGE)
    {
        bret = false;
        return;
    }

    switch (NW_VMF_MSG_GROUP(p_vmf_msg))
    {
        case VMF_TRACE_CTRL:
        {
            vmf_trace_ctrl_pl_t *ptrace_ctrl=NULL;

            unsigned8   ltrid=0;
            char        *rtrid_name;

            switch (NW_VMF_MSG_EVENT(p_vmf_msg))
            {
                case VMF_TRACE_CTRL_REG_CLIENT:
                {
                    ptrace_ctrl = (vmf_trace_ctrl_pl_t*)NW_VMF_MSG_DATA_PTR(p_vmf_msg);
                    rtrid_name = ptrace_ctrl->reg_client.name;
                    rtrid = ptrace_ctrl->reg_client.trid;

                    if (VMF_TRACE_REGISTER(&ltrid, rtrid_name) ==VMF_OK)
                    {
                        /* store coresponding local trid */
                        ltrids[rtrid] = ltrid;
                        rtrids[ltrid] = rtrid;
                        DEBUG_INFO_HI(VMF_TRACE_TASK_VMF, "register %s with remote trid %d as local trid %d", rtrid_name, rtrid,ltrid);
                    }
                    bret = false;
                }
                break;

                case VMF_TRACE_CTRL_FILTER_RESP:
                {
                    ptrace_ctrl = (vmf_trace_ctrl_pl_t*)NW_VMF_MSG_DATA_PTR(p_vmf_msg);
                    vmf_trace_ctrl_filter_response_t    *pfilter_resp;

                    pfilter_resp =  &(ptrace_ctrl->flt_response);
                    rtrid = pfilter_resp->trid;
                    ltrid = ltrids[rtrid];

                    if (0 == ltrid)
                    {
                        rtrid_name = pfilter_resp->name;
                        /* register remote trace client */
                        if (VMF_TRACE_REGISTER(&ltrid, rtrid_name) ==VMF_OK)
                        {
                            /* store coresponding local trid */
                            ltrids[rtrid] = ltrid;
                            rtrids[ltrid] = rtrid;
                            DEBUG_INFO_HI(VMF_TRACE_TASK_VMF, "VMF_TRACE_CTRL_FILTER_RESP: register %s with remote trid %d as local trid %d", rtrid_name, rtrid,ltrid);
                        }
                    }
                    ptrace_ctrl->reg_client.trid = ltrid;
                    DEBUG_INFO_LO(VMF_TRACE_TASK_VMF, "VMF_TRACE_CTRL_FILTER_RESP replace remote trid %d with local trid %d", rtrid, ltrid);
                    bret = false;
                }
                break;

                case VMF_TRACE_CTRL_FILTER_SET:
                {
                    bret = false;   /* ignore */
                }
                break;

                case VMF_TRACE_SATURN_FLASH_DONE:
                /* no break */
                case VMF_TRACE_DOWNLOAD_TRANSFER_REQ_RESP:
                /* no break */
                case VMF_TRACE_DOWNLOAD_RESPONSE:
                /* no break */
                case VMF_TRACE_READ_MEM_RESP:
                /* no break */
                case VMF_TRACE_WRITE_MEM_RESP:
                {
                    bret = true;   /* send to VMF */
                }
                break;
                
                case VMF_CTRL_MONITOR_RESPONSE:
                {
                    bret = true;   /* send to VMF */
                }
                break;
                
                case VMF_TRACE_CTRL_FILTER_REQ:
                {
                    DEBUG_INFO_HI(VMF_TRACE_TASK_VMF, "VMF_TRACE_CTRL_FILTER_REQ");
                    bret = true;   /* send to VMF */
                }
                break;
                

                case VMF_TRACE_CTRL_REG_GW_GROUPS:
                {
                    int cnt;
                    (void)nw_vmf_register_msg_group (cid, NW_VMF_MSG_DATA_LENGTH(p_vmf_msg), NW_VMF_MSG_DATA_PTR(p_vmf_msg));
                    
                    for (cnt=0; cnt < NW_VMF_MSG_DATA_LENGTH(p_vmf_msg); cnt++)
                    {
                        DEBUG_INFO_HI(VMF_TRACE_TASK_VMF, "register group %d", NW_VMF_MSG_DATA_PTR(p_vmf_msg)[cnt]);
                    }
                    bret = false;   /* do not send to VMF  */
                }
                break;
                
                default:
                {
                    bret = false;
                }
                break;

            }
        }
        break;

        case VMF_TRACE_IN:
        {
            vmf_trace_pl_t *ptrace_pl=NULL;
            unsigned8   ltrid=0;
            unsigned32  ttime;

            /* replace remote trid with local trid in trace message */
            ptrace_pl = (vmf_trace_pl_t*)NW_VMF_MSG_DATA_PTR(p_vmf_msg);

#if 1            
            /* add time offset */
            ttime = ptrace_pl->msg_time & 0x00ffffff;
            ttime += svmf_clock_offset;
            ptrace_pl->msg_time = ttime;
#endif           

            rtrid = ptrace_pl->trid;
            ltrid = ltrids[rtrid];
            if (ltrid >0)
            {
                ptrace_pl->trid=ltrid;
                bret = true;
                DEBUG_INFO_LO(VMF_TRACE_TASK_VMF, "VMF_TRACE_CTRL_FILTER_RESP VMF_TRACE_IN-event=%d replace remote trid %d with local trid %d",NW_VMF_MSG_EVENT(p_vmf_msg) ,rtrid, ltrid);
            }
            else
            {
                DEBUG_INFO_HI(VMF_TRACE_TASK_VMF, "no local trid for remote trid %d", rtrid);
                bret = false;
                break;      /* ignore message */
            }

            switch (NW_VMF_MSG_EVENT(p_vmf_msg))
            {
                case VMF_TRACE_MSG_TYPE_SHM:
                {
                    /* convert to normal trace message */
                    vmf_trace_shm_pl_t  *pshm_pl;
                    char                name[MAX_TRACE_NAME_LEN+1];
                    char                task[MAX_TRACE_TASK_NAME_LEN+1]; /* task name */
                    char                scope[MAX_TRACE_SCOPE_LEN+1]; /* scope */
                    char                msg[MAX_TRACE_MSG_LEN+1];     /* msg */

                    pshm_pl = (vmf_trace_shm_pl_t*)ptrace_pl;
                    memcpy(name,pshm_pl->name,MAX_TRACE_NAME_LEN);
                    memcpy(task,pshm_pl->task,MAX_TRACE_TASK_NAME_LEN);
                    memcpy(scope,pshm_pl->scope,MAX_TRACE_SCOPE_LEN);
                    memcpy(msg,pshm_pl->msg,MAX_TRACE_MSG_LEN);

                    snprintf(ptrace_pl->tpl,MAX_VMF_TRACE_PL_LEN,"%s%s%s%s%s%s%s",name,VMF_TRACE_MSG_DELIMITER,task,VMF_TRACE_MSG_DELIMITER, scope,VMF_TRACE_MSG_DELIMITER,msg);
                    ptrace_pl->tpl_len  = strlen(ptrace_pl->tpl);
                    NW_VMF_MSG_EVENT(p_vmf_msg) = VMF_TRACE_MSG_TYPE_TEXT;
                    NW_VMF_MSG_DATA_LENGTH(p_vmf_msg) = GET_TPL_LEN(ptrace_pl);
                }
            }
        }
        break;


        default:
            bret = true;
        /* do nothing */
        break;

    }

    return bret;
}


/*
*******************************************************************************************************
*** adapt  local VMF trace messages message  to remote trace messages
*** the function will replace the local trids with remote trids
*** th function will return true if the converted message has to be send
*******************************************************************************************************
*/
static bool vmf_convert_and_filter_ltr_msg (vmf_client_id_t cid, vmf_msg_t *p_vmf_msg)
{
    unsigned8       rtrid=0;
    bool            bret=true;

    if (NULL == p_vmf_msg)
    {
        DEBUG_ERROR(VMF_TRACE_TASK_VMF,"vmf_convert_and_filter_ltr_msg - p_vmf_msg=NULL");
        return false;
    }

    if (NW_VMF_MSG_TYPE(p_vmf_msg) != MSG_TYPE_BASIC_MESSAGE)
    {
        DEBUG_ERROR(VMF_TRACE_TASK_VMF,"vmf_convert_and_filter_ltr_msg -NW_VMF_MSG_TYPE(p_vmf_msg) != MSG_TYPE_BASIC_MESSAGE");
        return false;
    }

    switch (NW_VMF_MSG_GROUP(p_vmf_msg))
    {
        case VMF_TRACE_CTRL:
        {
            vmf_trace_ctrl_pl_t *ptrace_ctrl=NULL;
            unsigned8   ltrid=0;

            bret = false;
            switch (NW_VMF_MSG_EVENT(p_vmf_msg))
            {
                case VMF_TRACE_CTRL_FILTER_SET:
                {
                    /* replace local trid with remote trid */
                    ptrace_ctrl = (vmf_trace_ctrl_pl_t*)NW_VMF_MSG_DATA_PTR(p_vmf_msg);

                    ltrid = ptrace_ctrl->flt_severity.trid;
                    rtrid = rtrids[ltrid];
                    if (0 == ltrid)
                    {
                        DEBUG_INFO_LO(VMF_TRACE_TASK_VMF, "VMF_TRACE_CTRL_FILTER_SET trid %d", ltrid);
                        bret = true;
                    }
                    else if (0 == rtrid)
                    {
                        DEBUG_INFO_LO(VMF_TRACE_TASK_VMF, "VMF_TRACE_CTRL_FILTER_SET no remote trif for local trid %d so ignore ", ltrid);
                        bret = false;
                    }
                    else
                    {
                        DEBUG_INFO_LO(VMF_TRACE_TASK_VMF, "VMF_TRACE_CTRL_FILTER_SET replace local trid %d with remote trid %d", ltrid,rtrid);
                        ptrace_ctrl->flt_severity.trid = rtrid;
                        bret = true;
                    }
                }
                break;

                case VMF_TRACE_CTRL_REQ_CONN_NAMES:
                {
                    DEBUG_INFO_LO(VMF_TRACE_TASK_VMF, "VMF_TRACE_CTRL_REQ_CONN_NAMES");
                    bret = true;
                }
                break;

                case VMF_TRACE_CTRL_FILTER_REQ:
                {
                    DEBUG_INFO_HI(VMF_TRACE_TASK_VMF, "VMF_TRACE_CTRL_FILTER_REQ");
                    bret = true;
                }
                break;


                case VMF_CTRL_CONNECTION_CHECK:
                {
                    DEBUG_INFO_LO(VMF_TRACE_TASK_VMF, "ignore VMF_CTRL_CONNECTION_CHECK");
                    bret = false;   /* ignore */
                }
                break;

                case VMF_TRACE_CTRL_FILTER_RESP:
                {
                    DEBUG_INFO_LO(VMF_TRACE_TASK_VMF, "convert VMF_TRACE_CTRL_FILTER_RESP to VMF_TRACE_CTRL_FILTER_SET");

                    /* replace local trid with remote trid */

                    ptrace_ctrl = (vmf_trace_ctrl_pl_t*)NW_VMF_MSG_DATA_PTR(p_vmf_msg);

                    ltrid = ptrace_ctrl->flt_severity.trid;
                    rtrid = rtrids[ltrid];
                    ptrace_ctrl->flt_severity.trid = rtrid;
                    if (0 == rtrid)
                    {
                        DEBUG_INFO_LO(VMF_TRACE_TASK_VMF, "VMF_TRACE_CTRL_FILTER_RESP no remote trif for local trid %d ", ltrid);
                        bret = false;
                    }
                    else
                    {
                        DEBUG_INFO_LO(VMF_TRACE_TASK_VMF, "VMF_TRACE_CTRL_FILTER_RESP replace local trid %d with remote trid %d", ltrid,rtrid);
                        NW_VMF_MSG_EVENT(p_vmf_msg) = VMF_TRACE_CTRL_FILTER_SET;
                        bret = true;
                    }

                }
                break;

                /* formward download messages to client */
                case VMF_TRACE_DOWNLOAD_REQUEST:
                /*  no break */
                case VMF_TRACE_DOWNLOAD_TRANSFER:
                /*  no break */
                case VMF_TRACE_DOWNLOAD_DONE:
                /*  no break */
                case VMF_TRACE_READ_MEM_REQ:
                /*  no break */
                case VMF_TRACE_WRITE_MEM_REQ:           
                {
                    bret = true;   /* forward to client */
                }
                break;
                
                case VMF_CTRL_MONITOR_REQUEST:        
                {
                    vmf_ret_t vmf_ret;
                    vmf_ret = vmf_mon_handle_request(cid, p_vmf_msg);
                    if (VMF_OK == vmf_ret)
                    {
                        bret = false;   /* already handled */
                    }
                    else
                    {
                        bret = true;   /* forward to client */
                    }
                }
                break;
                
                /* forward time sync to svmf client */
                case VMF_TRACE_CTRL_TIME_SYNC:
                    bret = true;
                break;

                default:
                    DEBUG_INFO_LO(VMF_TRACE_TASK_VMF,"ignore un-handled event %d",NW_VMF_MSG_EVENT(p_vmf_msg));
                    bret=false;
                break;

            }
        }
        break;

        default:
        /* do nothing */
        break;
    }
    return bret;
}



/*
*******************************************************************************************************
*** handle received VMF message
*******************************************************************************************************
*/

static void vmf_ser_sender (nw_vmf_mi_transfer_v2_t *tr_msg)
{
    int                 len=0;
    bool                bret=false;
    unsigned8           cs=0;
    unsigned8           dummy=0xff;
    static unsigned8    msg_count =0;

    if (tr_msg != NULL)
    {
        unsigned16  cs=0;

        /* fill transfer message */
        tr_msg->token0      =  VALID_TOKEN0;
        tr_msg->token1      =  VALID_TOKEN1;
        tr_msg->version_l   =  VMF_MI_VERISION_L;
        tr_msg->version_h   =  VMF_MI_VERISION_H;
        tr_msg->comp = msg_count++;
        tr_msg->csum_l = 0;
        tr_msg->csum_h = 0;
        tr_msg->svmf_len =  SVMF_MSG_LEN(tr_msg->svmf_msg.pl_len);

        /* calculate cs */
        cs = vmf_mi_calc_cs((unsigned8*)&(tr_msg->svmf_msg),tr_msg->svmf_len);
        tr_msg->csum_l = cs & 0xff;
        tr_msg->csum_h = cs >> 8;

        len = sizeof(nw_vmf_mi_transfer_v2_header_t) + tr_msg->svmf_len;
        DEBUG_INFO_LO(VMF_TRACE_TASK_VMF,"len = %d, tr_msg->svmf_len = %d",len,tr_msg->svmf_len);

        if (len <= IO_MSG_DATALEN_MAX)
        {
            /* send the message */
            bret = WriteSerial(len, (unsigned8 *)tr_msg);
            if (false == bret)
            {
                DEBUG_INFO_HI(VMF_TRACE_TASK_VMF, "WriteSerial failed (header)!");
                perror("WriteSerial");
                delay(20);
                /* try again */
                bret = WriteSerial(len, (unsigned8 *)tr_msg);
                if (false == bret)
                {
                    DEBUG_INFO_HI(VMF_TRACE_TASK_VMF, "WriteSerial retry failed (header)!");
                }
            }
            /* add dummy byte */
            (void)WriteSerial(sizeof(dummy), &dummy);
        }
    }
}

unsigned8 calc_cs(unsigned8 cs,unsigned8* buff, int len)
{
    int cnt;
    unsigned8   my_cs=cs;
    for (cnt=0;cnt<len;cnt++)
    {
        cs^=buff[cnt];
    }
    return cs;
}






/*
*******************************************************************************************************
*** Generic stuff
*******************************************************************************************************
*/

static bool GetOpt(int argc, char *argv[])
{
    bool ret_val = true;
    int  opt=0;
    extern char *optarg;

    if (argc < 2)
    {
        use_tcp = true;
    }

    while ((opt = getopt(argc, argv, "?hHc:p:t:r:e:vf:l:db:a")) != -1)
    {
        switch (opt)
        {
            case '?':
            case 'h':
            case 'H':
                /* show usage */
                usage();
                ret_val = false;
            break;

            case 'c':
                /* COM Port */
                com_port = (int)atoi(optarg);
                use_tcp = false;
                auto_start_vmf=true;
            break;

            case 'p':
                /* COM Port */
                tcp_port = (int)atoi(optarg);
                use_tcp = true;
            break;

            case 'd':
                dump=true;
            break;

            case 'v':
                verbose++;
            break;

            case 'a':
                auto_start_vmf=true;
            break;

            case 'f':
                /* flash Saturn  */
                snprintf(flash_file,sizeof(flash_file),optarg);
                if (strlen(flash_file)>0)
                {
                    send_download_request = true;
                    flash_mode = true;
                    create_vmf_download_thread();
                }
                else
                {
                    fprintf(ERROR_CHANNEL,"filename missing after -f option\n");
                }
            break;


        }
    }
    if (verbose >= 0)
    {
        current_setup();
    }
    return ret_val;
}



static void usage(void)
{
    printf("\n");
    printf("************************************************************************\n");
    printf("** SVMF serial/TCP gateway 2.7 J. Becker 2015                         **\n");
    printf("************************************************************************\n");
    printf("** ! set the IP address of the network interface to 169.254.5.90 !    **\n");
    printf("** usage: svmf_ser_gw.exe [options]                                   **\n");
    printf("**                                                                    **\n");
    printf("**     Opt.           Description                                     **\n");
    printf("**     -c <n>         COM port                                        **\n");
    printf("**     -p <n>         TCP port [default = %04d]                      **\n",tcp_port);
    printf("**     -v             verbose                                         **\n");
    printf("**     -d             dump messages in hex                            **\n");
    printf("**     -a             auto start vmf on target                        **\n");
    printf("**     -f             flash Saturn                                    **\n");
    printf("** Examples:                                                          **\n");
    printf("** svmf_tcp_gw -p 1234 -v -v -d                                       **\n");
    printf("** svmf_tcp_gw -p 2345                                                **\n");
    printf("** svmf_ser_gw -c 6 -v -v -d                                          **\n");
    printf("** svmf_ser_gw -c 6                                                   **\n");
    printf("** svmf_ser_gw -c 6  -v -a -f 61.bin                                  **\n");
    printf("************************************************************************\n");
    printf("\n");
}

 static void current_setup(void)
 {
    printf("\n");
    printf("************************************************************************\n");
    printf("** SVMF serial/TCP gateway 2.7 J. Becker 2015                         **\n");
    printf("************************************************************************\n");
    printf("** verbosity=%d                                                         \n",verbose);
    if (use_tcp)
    {
    printf("** ! set the IP address of the network interface to 169.254.5.90 !      \n");
    printf("** TCP-Port =%d                                                         \n",tcp_port);
    }
    else
    {
    printf("** Com-Port =COM%d                                                      \n",com_port);
    }
    printf("************************************************************************\n");
    printf("\n");
 }



/*************************************************************************//**
 *
 *   hex_dump
 *   NOTE: hex dump a buffer
 *
 *
 *   \param[in] unsigned8 *     - pointer to bufer
 *   \param[in] len             - length of bufer
 *   \return    void
 *
 ******************************************************************************/
static void nw_con_HexDump(char * name,unsigned8 *buffer,int len)
{
#define CPL 16
    static  bool b_in_use = false;
    int     i,j, ct;
    char    asci[2*CPL+1];

    if (buffer == NULL)
    {
        fprintf(ERROR_CHANNEL,"nw_con_HexDump - buffer == NULL\n");
        return;
    }

    while (b_in_use)
    {
        delay(1);
    }
    b_in_use = true;


    if (len <= 0)
    {
        b_in_use = false;
        return;
    }

    fprintf(ERROR_CHANNEL,"%s\n",name);
    for (i=0,j=0; i<len; ++i)
    {
        asci[j]='.';
        asci[j+1]=0;

        ct = (int)buffer[i];
        fprintf(ERROR_CHANNEL,"0x%02x,", ct);
        if ((ct > 0x1f) && (ct < 0x7f))
        {
            asci[j]=ct;
        }

        if ((((i+1) % CPL) == 0))
        {
            fprintf(ERROR_CHANNEL,"    %s\n",asci);
            asci[0]=0;
            j=0;
        }
        else
        {
            j+=1;
        }
    }
    for (; j<CPL; ++j)
    {
        fprintf(ERROR_CHANNEL,"     ");
    }

    fprintf(ERROR_CHANNEL,"    %s\n\n",asci);
    b_in_use = false;
}



static void print_dcb(DCB *pdcb)
{
    fprintf(ERROR_CHANNEL,"DCB.BaudRate=%i\n",pdcb->BaudRate);
    fprintf(ERROR_CHANNEL,"DCB.fBinary=%i\n",pdcb->fBinary);
    fprintf(ERROR_CHANNEL,"DCB.fParity=%i\n",pdcb->fParity);
    fprintf(ERROR_CHANNEL,"DCB.fOutxCtsFlow=%i\n",pdcb->fOutxCtsFlow);
    fprintf(ERROR_CHANNEL,"DCB.fOutxDsrFlow=%i\n",pdcb->fOutxDsrFlow);
    fprintf(ERROR_CHANNEL,"DCB.fDtrControl=%i\n",pdcb->fDtrControl);

    fprintf(ERROR_CHANNEL,"DCB.fDsrSensitivity=%i\n",pdcb->fDsrSensitivity);
    fprintf(ERROR_CHANNEL,"DCB.fTXContinueOnXoff=%i\n",pdcb->fTXContinueOnXoff);
    fprintf(ERROR_CHANNEL,"DCB.fOutX=%i\n",pdcb->fOutX);
    fprintf(ERROR_CHANNEL,"DCB.fInX=%i\n",pdcb->fInX);
    fprintf(ERROR_CHANNEL,"DCB.fErrorChar=%i\n",pdcb->fErrorChar);
    fprintf(ERROR_CHANNEL,"DCB.fNull=%i\n",pdcb->fNull);
    fprintf(ERROR_CHANNEL,"DCB.fRtsControl=%i\n",pdcb->fRtsControl);

    fprintf(ERROR_CHANNEL,"DCB.fAbortOnError=%i\n",pdcb->fAbortOnError);

    fprintf(ERROR_CHANNEL,"DCB.ByteSize=%i\n",pdcb->ByteSize);
    fprintf(ERROR_CHANNEL,"DCB.Parity=%i\n",pdcb->Parity);
    fprintf(ERROR_CHANNEL,"DCB.StopBits=%i\n",pdcb->StopBits);
}


static void send_board_number(void)
{
    /* transfer empty message to inform arduino about board version number */
    vmf_sat_gw_msg_t        transfer_msg={0};
    transfer_msg.sync_1     = VMF_SAT_SYNC_1;

    DEBUG_INFO_HI(VMF_TRACE_TASK_MAIN, "send_board_number()=%d\n",version);
    if (version == 2)
    {
        transfer_msg.sync_2 = VMF_SAT_SYNC_2_V2;
    }
    else
    {
        transfer_msg.sync_2 = VMF_SAT_SYNC_2;
    }
    transfer_msg.pl_len     = 0;

    /* send message */
    (void)WriteSerial(sizeof(transfer_msg), (unsigned8 *)&transfer_msg);
}



/**************************************************************************//**
 *
 *   Function Name: vmf_mi_calc_cs()
 *
 *   Description:   calculate the checksum of the given buffer
 *                  the checksum is calculated by adding eache byte in the buffer
 *                  an overflow is igneored
 *   \param         input buffer[input]
 *   \param         length of input data[input]
 *
 *   \return        checksum
 *
 ******************************************************************************/
static unsigned16 vmf_mi_calc_cs(unsigned8 *psrc, unsigned16 len)
{
        unsigned16  cs=0;
        unsigned16  cnt=0;

        for (cnt=0;cnt<len;cnt++)
        {
            cs += psrc[cnt];
        }
        return cs;
}



/**************************************************************************//**
 *
 *   Function Name: vmf_mi_auto_start_vmf()
 *
 *   Description:   send the svmf_trace shell command to the shell to start svmf
 *                  on the target 
 *   \param         input buffer[input]
 *   \param         length of input data[input]
 *
 *   \return        checksum
 *
 ******************************************************************************/
static void vmf_mi_auto_start_vmf(HANDLE hdl)
{
    const   char qm[] =  {"?\n"};
    const   char cr[] =  {"\n"};
    const   char swap[] ={"swap\n"};
    const   char vmf_start[] ={"vmf_start\n"};
    const   char dab_trace[] ={"svmf_trace\n"};
    const   char ch_A5[] = {"A5 >"};
    const   char ch_M4[] = {"M4 >"};
    unsigned8   start = 0xbb;
    char    buffer[100]={0};
    char    *result;
    int     ret_val=0;

 //--------------------------
    DEBUG_INFO_LO(VMF_TRACE_TASK_MAIN,"auto start vmf");
    /* send CR */
    DEBUG_INFO_LO(VMF_TRACE_TASK_MAIN,"send newline");
    WriteSlowSerial(sizeof(cr)-1, (unsigned8 *)cr);
    delay(100);

    /* start vmf */
    DEBUG_INFO_LO(VMF_TRACE_TASK_MAIN,"send vmf_start");
    WriteSlowSerial(sizeof(dab_trace)-1,(unsigned8 *)dab_trace);
    delay(100);
    /* send CR */
    DEBUG_INFO_LO(VMF_TRACE_TASK_MAIN,"send newline");
    WriteSlowSerial(sizeof(cr)-1, (unsigned8 *)cr);
    delay(100);

    /* send start command */
    DEBUG_INFO_LO(VMF_TRACE_TASK_MAIN,"send start byte");
    WriteSlowSerial(1, (unsigned8 *)&start);
    DEBUG_INFO_LO(VMF_TRACE_TASK_MAIN,"send newline");
    WriteSlowSerial(sizeof(cr)-1, (unsigned8 *)cr);
    delay(100);

 //--------------------------
    /* start vmf */
    DEBUG_INFO_LO(VMF_TRACE_TASK_MAIN,"send vmf_start");
    WriteSlowSerial(sizeof(dab_trace)-1,(unsigned8 *)dab_trace);
    /* send CR */
    DEBUG_INFO_LO(VMF_TRACE_TASK_MAIN,"send newline");
    WriteSlowSerial(sizeof(cr)-1, (unsigned8 *)cr);
    delay(100);

    /* send start command */
    DEBUG_INFO_LO(VMF_TRACE_TASK_MAIN,"send start byte");
    WriteSlowSerial(1, (unsigned8 *)&start);
    DEBUG_INFO_LO(VMF_TRACE_TASK_MAIN,"send newline");
    WriteSlowSerial(sizeof(cr)-1, (unsigned8 *)cr);
    delay(100);

//    wait_for(0,"M4 >");

 //--------------------------
    /* start vmf */
    DEBUG_INFO_LO(VMF_TRACE_TASK_MAIN,"send vmf_start");
    WriteSlowSerial(sizeof(dab_trace)-1,(unsigned8 *)dab_trace);
    /* send CR */
    DEBUG_INFO_LO(VMF_TRACE_TASK_MAIN,"send newline");
    WriteSlowSerial(sizeof(cr)-1, (unsigned8 *)cr);
    delay(100);

    /* send start command */
    DEBUG_INFO_LO(VMF_TRACE_TASK_MAIN,"send start byte");
    WriteSlowSerial(1, (unsigned8 *)&start);
    DEBUG_INFO_LO(VMF_TRACE_TASK_MAIN,"send newline");
    WriteSlowSerial(sizeof(cr)-1, (unsigned8 *)cr);
    delay(100);
}


static int wait_for(HANDLE hdl, char *suchtext)
{
    int     ret_val=0;
    int     result=0;
    char    buffer[100]={0};

    {
         while (ret_val==0)
         {
             ret_val = read_line(hdl, buffer,sizeof(buffer));
         }

         result = strncmp(buffer,suchtext,sizeof(suchtext));
         DEBUG_INFO_HI(VMF_TRACE_TASK_MAIN,"strcmp '%s','%s' return = %d",buffer,suchtext,result);
    }

    ret_val=1;
    if (result != 0)
    {
        ret_val=0;
    }
    else
    {
        DEBUG_INFO_HI(VMF_TRACE_TASK_MAIN,"wait_for found: %s, line=%s",suchtext,buffer);
    }
    return ret_val;
}


static int read_line(HANDLE hdl, char *buffer,int len)
{
    int     ix=0;
    int     ret_val=0;
    DEBUG_INFO_HI(VMF_TRACE_TASK_MAIN,"start - len=%d",len);
    ix=0;
    while(true)
    {
         ret_val =  Read_COM(hPort, &(buffer[ix]), 1);
         if (ret_val > 0)
         {
            if (buffer[ix] == 0x0a)
            {
                DEBUG_INFO_HI(VMF_TRACE_TASK_MAIN,"buffer[ix] == 0x0a");
                break;
            }
            ix++;
            if (ix >=len)
            {
                DEBUG_INFO_HI(VMF_TRACE_TASK_MAIN,"ix>len, ix=%d,len=%d",ix,len);
                break;
            }
         }
    }
    DEBUG_INFO_HI(VMF_TRACE_TASK_MAIN,"read_line return %d, byte 0 = %02x",ix,buffer[ix-1]);
    return ix;
}





static bool create_vmf_download_thread(void)
{
    int             iRet;
    pthread_t       th;
    pthread_attr_t  attr;

    /* set thread stack */
    pthread_attr_init( &attr );
    if ( pthread_attr_setstacksize(&attr, VMF_RECEIVER_STACK_SIZE ) != 0 )
    {
        DEBUG_ERROR(VMF_TRACE_TASK_VMF, "create_vmf_download_thread() - pthread_attr_setstacksize() failed");
    }

    if (false == send_download_request)
    {
        /* ignore */
        return false;
    }


    (void)pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED );
    iRet = pthread_create (&th  , &attr, vmf_download_thread, NULL);
    pthread_attr_destroy(&attr);
    if (iRet)
    {
        DEBUG_ERROR(VMF_TRACE_TASK_VMF, "create_vmf_download_thread() failed! errno = %d",iRet);
        return false;
    }

    return true;
}


static void *vmf_download_thread(void *pNoArg)
{
    #define VMF_DOWNLOAD_REC_TIMOUT 2000
    #define VMF_DOWNLOAD_ACK_TIMOUT 2000
    #define VMF_DOWNLOAD_REQ_TIMOUT 1000

    vmf_client_id_t vmf_download_handle;
    vmf_ret_t       vmf_ret;
    VMF_VAR_MSG_TYP(IO_MSG_DATALEN_MAX) vmf_msg;
    vmf_msg_t       *p_vmf_msg = (vmf_msg_t *)&vmf_msg;
    vmf_basic_msg_t *p_vmf_basic_msg = (vmf_basic_msg_t *)&vmf_msg;
    unsigned8       download_groups[]={VMF_TRACE_CTRL,VMF_DYN_0};
    unsigned16      current_msg_size=0;
    unsigned8       current_download_id = 1;
    unsigned32      last_send;

    transfer_done = false;

    last_send = nw_os_cfg_get_ms_time();
    last_ack = last_send;

    DEBUG_INFO_HI(VMF_TRACE_TASK_VMF, "VMF download started...");

    /* open file */
    fp = fopen(flash_file,"rb");
    if (NULL == fp)
    {
        fprintf(stderr,"error opening flash file: %s\n",flash_file);
        vmf_ret = VMF_ERROR;
        return;
    }

    /* get file length */
    fseek(fp, 0L, SEEK_END);
    file_len = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    fprintf(stderr, "** downloading %s len= %d bytes\n",flash_file,file_len);


    vmf_ret = nw_vmf_connect("vmf_download", 0, 0, VMF_CLIENT_QUEUE_SIZE_STANDARD, VMF_CLIENT_QUEUE_MSG_SIZE_STANDARD);
    if (vmf_ret < 0)
    {
        DEBUG_ERROR(VMF_TRACE_TASK_VMF, "nw_vmf_connect failed -- vmf_ret == %d", vmf_ret);
        return;
    }
    else
    {
        vmf_download_handle = vmf_ret;
    }

    vmf_ret = nw_vmf_register_msg_group (vmf_download_handle, sizeof(download_groups), download_groups);
    if (vmf_ret < 0)
    {
        DEBUG_ERROR(VMF_TRACE_TASK_VMF, "nw_vmf_register_msg_group failed -- vmf_ret == %d", vmf_ret);
    }

    while(true)
    {
        vmf_ret = nw_vmf_timed_receive (vmf_download_handle, p_vmf_msg, sizeof(vmf_msg),VMF_DOWNLOAD_REC_TIMOUT);
        DEBUG_INFO_LO(VMF_TRACE_TASK_VMF,"nw_vmf_timed_receive() returned %d",vmf_ret);

        /* try to start download */
        if (send_download_request)
        {
            /* handle Download-Request timout */
            if (false == transfer_done)
            {
                if ((nw_os_cfg_get_ms_time() - last_send) >= VMF_DOWNLOAD_REQ_TIMOUT)
                {
                    vmf_ret = vmf_download_send_download_request(vmf_download_handle, current_download_id, VMF_TRACE_CTRL, VMF_TRACE_DOWNLOAD_REQUEST , file_len, FLASH_TARGET_LEOPARD, flash_file);
                    last_send = nw_os_cfg_get_ms_time();
                }
            }
        }
        else
        {
            /* we are currently flashing */
            if (flash_done)
            {
                /* we are done */
                DEBUG_INFO_HI(VMF_TRACE_TASK_VMF,"disconnecting from vmf and stopping thread",vmf_ret);
                nw_vmf_disconnect(vmf_download_handle);
                return;
            }
#if 1
            /* handle ACK timout */
            if ((nw_os_cfg_get_ms_time() - last_ack) >= VMF_DOWNLOAD_ACK_TIMOUT)
            {
                vmf_download_repeat_msg(vmf_download_handle);
                last_ack = nw_os_cfg_get_ms_time();
            }
#endif
        }

        if (vmf_ret > 0)
        {
            p_vmf_basic_msg = (vmf_basic_msg_t *)&(vmf_msg.vmf_basic_msg);
            if (p_vmf_basic_msg->msg_base.base.vmf_mi_server_id  == SVMF_SRV_BACKFIRE)
#if 0
            {
                /* prevent backfire */
                DEBUG_INFO_HI(VMF_TRACE_TASK_VMF, "prevent backfire group=%d, event=%d",NW_VMF_BASIC_MSG_EVENT(p_vmf_basic_msg),NW_VMF_BASIC_MSG_GROUP(p_vmf_basic_msg));
                continue;
            }
#endif
            if (MSG_TYPE_BASIC_MESSAGE == NW_VMF_BASIC_MSG_TYPE(p_vmf_basic_msg))
            {
                DEBUG_INFO_HI(VMF_TRACE_TASK_VMF, "received group=%d, event=%d",NW_VMF_BASIC_MSG_EVENT(p_vmf_basic_msg),NW_VMF_BASIC_MSG_GROUP(p_vmf_basic_msg));
                if (dyn_group == NW_VMF_BASIC_MSG_GROUP(p_vmf_basic_msg))
                {
                    vmf_ret = vmf_download_msg_handler(vmf_download_handle, p_vmf_basic_msg,current_download_id,flash_file, dyn_group);
                }
            }
            else
            {
                DEBUG_INFO_HI(VMF_TRACE_TASK_VMF, "This is not a basic message! msg-type=%d",NW_VMF_BASIC_MSG_TYPE(p_vmf_basic_msg));
                nw_con_HexDump("vmf_msg",(unsigned8*)p_vmf_basic_msg,vmf_ret);
            }
        }
        else
        {
            /* error during vmf_receive -- wait some time and try again... */
            DEBUG_INFO_LO(VMF_TRACE_TASK_VMF, "vmf_receive failed -- vmf_ret == %d", vmf_ret);
            delay(20);
        }
    }
}

static vmf_ret_t vmf_download_msg_handler(vmf_client_id_t cid, vmf_basic_msg_t *p_vmf_basic_msg, unsigned8 download_id, char* file, unsigned8 group)
{
    static      int current_msg_size=0;
                vmf_ret_t   vmf_ret = VMF_OK;
    static      unsigned8   buffer[IO_MSG_DATALEN_MAX];
    static      size_t      read_len;

    DEBUG_INFO_HI(VMF_TRACE_TASK_VMF, "vmf_download_msg_handler - event = %d", NW_VMF_BASIC_MSG_EVENT(p_vmf_basic_msg));

    if (NULL == p_vmf_basic_msg)
    {
        DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"NULL-pointer",file);
        return VMF_ERROR;
    }

    switch  NW_VMF_BASIC_MSG_EVENT(p_vmf_basic_msg)
    {
        case VMF_TRACE_DOWNLOAD_RESPONSE:
        {
            vmf_download_resp_t *p_resp;

            DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"received VMF_TRACE_DOWNLOAD_RESPONSE");
            p_resp = (vmf_download_resp_t*)NW_VMF_BASIC_MSG_DATA_PTR(p_vmf_basic_msg);
            if (p_resp->download_id == download_id)
            {
                read_len=0;
                current_len =0;
                DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"VMF_TRACE_DOWNLOAD_RESPONSE");
                send_download_request = false;
            }
            else
            {
                DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"ignore VMF_TRACE_DOWNLOAD_RESPONSE - invalid download id =%d",p_resp->download_id);
                /* ignore - different download-id */
            }
        }
        break;

        case VMF_TRACE_DOWNLOAD_TRANSFER:
            /* ignore - own message */
            DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"ignore own VMF_TRACE_DOWNLOAD_TRANSFER");
        break;

        case VMF_TRACE_DOWNLOAD_TRANSFER_REQ_RESP:
        {
            unsigned8 response;

            DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"received VMF_TRACE_DOWNLOAD_TRANSFER_REQ_RESP");
            vmf_download_trans_resp_req_t *p_resp=NULL;

            p_resp = (vmf_download_trans_resp_req_t*)NW_VMF_BASIC_MSG_DATA_PTR(p_vmf_basic_msg);
            response =  p_resp->response;

            if (p_resp->download_id != download_id)
            {
                 DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"ignore VMF_TRACE_DOWNLOAD_TRANSFER_REQ_RESP - invalid download id =%d",p_resp->download_id);
                 break;
            }
            if (VMF_TCD_ACK == response)
            {
                /* received ACK */
                /* test block number */
                DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"received ACK for block %d",block_num);
                if (block_num != p_resp->resp_block)
                {
                    DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"received invalid block_num = %d, expected %d",p_resp->resp_block, block_num);
                    break;
                }

                /* correct response for last send block */
                block_num++;
                last_ack = nw_os_cfg_get_ms_time();
                current_msg_size = (p_resp->block_len_h * 256) +  p_resp->block_len_l;

                if (0 == current_msg_size)
                {
                    transfer_done=true;
                }

                DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"current block=%d, current_msg_size = %d",block_num, current_msg_size);
                if (transfer_done)
                {
                    DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"transfer_done = true, call vmf_download_send_download_done()");
                    vmf_download_send_download_done(cid, download_id, group, VMF_TRACE_DOWNLOAD_DONE );
//                    flash_done = true;
//                    flash_mode = false;
                    fprintf(stderr, "download done - waiting for flashing    \n");
                }
                else
                {
                    /* send next block */
                    DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"send next block %d",block_num);

                    if (current_msg_size > IO_MSG_DATALEN_MAX)
                    {
                        /* abort */
                        DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"invalid message size = %d",current_msg_size);
                        flash_mode = false;
                        flash_done = true;
                        break;
                    }

                    read_len = fread(buffer, 1, current_msg_size , fp);
                    current_len +=  read_len;

                    if (0 == read_len)
                    {
                        DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"no more data to read!");
                        transfer_done = true;
                    }
                    else
                    {
                        vmf_ret = vmf_download_send_block(cid, download_id, group, VMF_TRACE_DOWNLOAD_TRANSFER , block_num, buffer, read_len);
                        if (vmf_ret != VMF_OK)
                        {
                            DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"vmf_download_send_block() failed");
                            vmf_ret = VMF_ERROR;
                            break;
                        }
                    }

                }
            }
            else if (VMF_TCD_IGNORE == response)
            {
                /* this is a transfer request without response */
                block_num = 0;
                current_msg_size = (p_resp->block_len_h * 256) +  p_resp->block_len_l;
                DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"first block, current_msg_size = %d",current_msg_size);

                read_len = fread(buffer, 1, current_msg_size ,fp);
                current_len +=  read_len;
                DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"fread(%d) returned %d",current_msg_size,read_len);

                if (0 == read_len)
                {
                    DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"no more data to read!");
                }
                else
                {
                    vmf_ret = vmf_download_send_block(cid, download_id, group, VMF_TRACE_DOWNLOAD_TRANSFER , block_num, buffer, read_len);
                    if (vmf_ret != VMF_OK)
                    {
                        DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"vmf_download_send_block() failed");
                        vmf_ret = VMF_ERROR;
                        break;
                    }
                }

            }
            else
            {
                /* received NAK */
                DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"received NAK for block %d, re-send block ",p_resp->resp_block);
                vmf_ret = vmf_download_send_block(cid, download_id, group, VMF_TRACE_DOWNLOAD_TRANSFER , block_num, buffer, read_len);
                if (vmf_ret != VMF_OK)
                {
                    DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"vmf_download_send_block() failed");
                    vmf_ret = VMF_ERROR;
                    break;
                }
            }
        }
        break;

        case VMF_TRACE_DOWNLOAD_REQUEST:
            /* ignore - own message */
            DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"ignore own VMF_TRACE_DOWNLOAD_REQUEST");
        break;

        case VMF_TRACE_DOWNLOAD_DONE:
            /* ignore - own message */
            DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"ignore own VMF_TRACE_DOWNLOAD_DONE");
        break;


        case VMF_TRACE_SATURN_FLASH_DONE:
            printf("\nflashing done!!\n");
            flash_done = true;
            flash_mode = false;
        break;

        default:
        {
            vmf_ret = VMF_OK;
            DEBUG_INFO_HI(VMF_TRACE_TASK_VMF,"ignore un-handled event %d",NW_VMF_BASIC_MSG_EVENT(p_vmf_basic_msg));
        }
        break;
    }

    if (vmf_ret != VMF_OK)
    {
        DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"flashing failed - abort transfer");
        fclose(fp);
        vmf_download_send_download_done(cid, download_id, group, VMF_TRACE_DOWNLOAD_DONE );
    }

    return vmf_ret;
}


static vmf_ret_t  vmf_download_send_download_request(vmf_client_id_t cid, unsigned8 id, unsigned8 group, unsigned8 event, unsigned32 file_len, char *target_name, char *file_name)
{
    VMF_VAR_BASIC_MSG_TYP(IO_MSG_DATALEN_MAX)   vmf_basic_msg;
    vmf_ret_t          vmf_ret = VMF_OK;
    vmf_download_req_t *preq =  (vmf_download_req_t*)NW_VMF_BASIC_MSG_DATA_PTR(&vmf_basic_msg);
    char               *delimiter;
    unsigned16         pl_len;

    DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"vmf_download_send_download_request()");

    preq->version = 0;
    preq->fill = 0;
    preq->download_id = id;
    preq->group = dyn_group;
    preq->event = 0;
    preq->data_len_ll = (unsigned8)(file_len & 0xff);
    preq->data_len_lh = (unsigned8)((file_len >> 8) & 0xff);
    preq->data_len_hl = (unsigned8)((file_len >> 16) & 0xff);


    pl_len =  sizeof(vmf_download_req_t);

    strncpy (&preq->pl[0], target_name,256);

    delimiter = &(preq->pl[strlen(target_name)]);       /* points to first byte after target name */
    *delimiter = '\0';                                  /* target-name  delimiter */
    *(++delimiter) = '\0';                              /* file-name  delimiter */
    *(++delimiter) = '\0';                              /* file-path  delimiter */
    pl_len += strlen(target_name) + 3;

    /* create VMF message */
    NW_VMF_BASIC_MSG_EVENT(&vmf_basic_msg) = event;
    NW_VMF_BASIC_MSG_GROUP(&vmf_basic_msg) = group;
    NW_VMF_BASIC_MSG_DATA_LENGTH(&vmf_basic_msg) = pl_len;
    vmf_ret = nw_vmf_send_basic(cid, (vmf_basic_msg_t*)&vmf_basic_msg);

    return vmf_ret;
 }


 static vmf_ret_t  vmf_download_send_download_done(vmf_client_id_t cid, unsigned8 id, unsigned8 group, unsigned8 event)
 {
    vmf_ret_t   vmf_ret = VMF_OK;
    vmf_download_done_t pdone;
    vmf_basic_msg_t    vmf_basic_msg;
    unsigned16         pl_len;

    DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"vmf_download_send_download_done() ");

    pdone.version = 0;
    pdone.fill = 0;
    pdone.download_id = id;
    pl_len = sizeof(vmf_download_done_t);

    /* create VMF message */
    NW_VMF_BASIC_MSG_EVENT(&vmf_basic_msg) = event;
    NW_VMF_BASIC_MSG_GROUP(&vmf_basic_msg) = group;
    memcpy(NW_VMF_BASIC_MSG_DATA_PTR(&vmf_basic_msg), &pdone, pl_len);
    NW_VMF_BASIC_MSG_DATA_LENGTH(&vmf_basic_msg) = pl_len;
    vmf_ret = nw_vmf_send_basic(cid, &vmf_basic_msg);
    return vmf_ret;
 }



 static vmf_ret_t  vmf_download_send_block(vmf_client_id_t cid, unsigned8 id, unsigned8 group, unsigned8 event, unsigned8 block_num,unsigned8* buffer, unsigned16 len)
 {
    VMF_VAR_BASIC_MSG_TYP(IO_MSG_DATALEN_MAX)   vmf_basic_msg;
    vmf_ret_t               vmf_ret = VMF_OK;
    vmf_download_trans_t    *ptransfer = (vmf_download_trans_t*)NW_VMF_BASIC_MSG_DATA_PTR(&vmf_basic_msg);
    unsigned16              pl_len;

    DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"send block %d with len = %d, event =%d, group=%d",block_num, len,event,group);

    if (transfer_done)
    {
        return VMF_OK;
    }


    if (NULL == buffer)
    {
        DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"NULL-pointer");
        return VMF_ERROR;
    }
    else if (0 == len)
    {
        DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"len = 0");
        return VMF_ERROR;
    }

    /* store parameter */
    flash_last_id = id;
    flash_last_group = group;
    flash_last_event = event;
    flash_last_block_num = block_num;
    flash_last_buffer = buffer;
    flash_last_len = len;

    /* prepare payload */
    ptransfer->version = 0;
    ptransfer->fill = 0;
    ptransfer->download_id = id;
    ptransfer->block_num =  block_num;
    ptransfer->block_len_ll = len % 256;
    ptransfer->block_len_lh = len / 256;
    pl_len = sizeof(vmf_download_trans_t);

    memcpy(ptransfer->pl, buffer, len);
    pl_len += len;

    /* create VMF message */
    NW_VMF_BASIC_MSG_EVENT(&vmf_basic_msg) = event;
    NW_VMF_BASIC_MSG_GROUP(&vmf_basic_msg) = group;
    NW_VMF_BASIC_MSG_DATA_LENGTH(&vmf_basic_msg) = pl_len;

    DEBUG_INFO_LO(VMF_TRACE_TASK_FLASH,"send vmf-message with pl_len of %d bytes", pl_len);
    vmf_ret = nw_vmf_send_basic(cid, (vmf_basic_msg_t*)&vmf_basic_msg);
    DEBUG_INFO_LO(VMF_TRACE_TASK_FLASH,"nw_vmf_send_basic returned %d", vmf_ret);

    print_percent(file_len, current_len);

    return vmf_ret;
 }


 static vmf_ret_t  vmf_download_repeat_msg(vmf_client_id_t cid)
 {
    VMF_VAR_BASIC_MSG_TYP(IO_MSG_DATALEN_MAX)   vmf_basic_msg;
    vmf_ret_t               vmf_ret = VMF_OK;
    vmf_download_trans_t    *ptransfer = (vmf_download_trans_t*)NW_VMF_BASIC_MSG_DATA_PTR(&vmf_basic_msg);
    unsigned16              pl_len;

    if (transfer_done)
    {
        return VMF_OK;
    }

    DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"!!! repeat block %d with len = %d, event =%d, group=%d",flash_last_block_num, flash_last_len,flash_last_event,flash_last_group);

    if (NULL == flash_last_buffer)
    {
        DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"NULL-pointer");
        return VMF_ERROR;
    }
    else if (0 == flash_last_len)
    {
        DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"len = 0");
        return VMF_ERROR;
    }

    /* prepare payload */
    ptransfer->version = 0;
    ptransfer->fill = 0;
    ptransfer->download_id = flash_last_id;
    ptransfer->block_num =  flash_last_block_num;
    ptransfer->block_len_ll = flash_last_len % 256;
    ptransfer->block_len_lh = flash_last_len / 256;
    pl_len = sizeof(vmf_download_trans_t);

    memcpy(ptransfer->pl, flash_last_buffer, flash_last_len);
    pl_len += flash_last_len;

    /* create VMF message */
    NW_VMF_BASIC_MSG_EVENT(&vmf_basic_msg) = flash_last_event;
    NW_VMF_BASIC_MSG_GROUP(&vmf_basic_msg) = flash_last_group;
    NW_VMF_BASIC_MSG_DATA_LENGTH(&vmf_basic_msg) = pl_len;

    DEBUG_INFO_LO(VMF_TRACE_TASK_FLASH,"send vmf-message with pl_len of %d bytes", pl_len);
    vmf_ret = nw_vmf_send_basic(cid, (vmf_basic_msg_t*)&vmf_basic_msg);
    DEBUG_INFO_LO(VMF_TRACE_TASK_FLASH,"nw_vmf_send_basic returned %d", vmf_ret);

    print_percent(file_len, current_len);

    return vmf_ret;
}


 static void  vmf_send_time_request(vmf_client_id_t cid)
 {
        {
            VMF_VAR_BASIC_MSG_TYP(0)    vmf_basic_msg;

            vmf_basic_msg.msg_base.id.event = VMF_TRACE_CTRL_TIME_REQ;
            vmf_basic_msg.msg_base.id.group = VMF_TRACE_CTRL;
            vmf_basic_msg.data.length=0;

            (void)nw_vmf_send_basic(cid,(vmf_basic_msg_t*)&vmf_basic_msg);
        }
}

static void print_percent(unsigned32 file_len, unsigned32 current_len)
{
    float fpc;

    fpc = ((float)current_len*100) / (float)file_len;
    DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"file_len=%d, current_len = %d",file_len,current_len);
//    printf("flashing... %3.1f%% done\n",fpc);
    printf("downloading... %3.1f%% done\r",fpc);
}


static void vmf_svmf_socket_close(SOCKET_T *sockd)
 {
    if (*sockd != -1)
    {
        DEBUG_INFO_HI(VMF_TRACE_TASK_TCP,"close-socket %d",*sockd);
        CLOSESOCKET(*sockd);
        *sockd = -1;
    }    
 }


/**************************************************************************//**
 *
 *   Function Name: vmf_mon_send_response()
 *
 *   Description:   send a monitoring response message
 *
 *   Parameters:    cid
 *                  iten name
 *                  item status
 *                  item text
 *
 *   Return value:  vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t  vmf_mon_send_response(vmf_client_id_t cid, char *item_name, unsigned8 status, char *status_text)
{
    /* ! this message is place on the stack - it may be a good idea to make this static */
    VMF_VAR_BASIC_MSG_TYP(sizeof(vmf_ctrl_monitoring_resp_t)) vmf_basic_msg;
    vmf_ret_t                   vmf_ret = VMF_ERROR;
    vmf_ctrl_monitoring_resp_t  *resp;
    size_t                      len;

    /* argument check */
    if ( 0 == cid)
    {
        return VMF_ERROR;
    }
    else if (NULL == item_name)
    {
        return VMF_ERR_NULL_POINTER;
    }

    resp = (vmf_ctrl_monitoring_resp_t*)NW_VMF_BASIC_MSG_DATA_PTR(&vmf_basic_msg);

    /* create response message */
    len = strlen(item_name);
    if (len > 0)
    {
        strncpy(resp->item_name,item_name,VMF_MON_ITEM_NAME_LEN);
        resp->item_name[VMF_MON_ITEM_NAME_LEN-1]=0;
    }
    else
    {
        resp->item_name[0]=0;
    }
    resp->item_name_len = len+1;

    /* copy response text if available */
    resp->text[0]=0;
    if (NULL != status_text)
    {
        len = strlen(status_text);
        if (len > 0)
        {
            strncpy(resp->text,status_text,VMF_MON_TEXT_LEN);
            resp->text[VMF_MON_TEXT_LEN-1]=0;
        }
    }
    resp->text_len = len+1;
    resp->version = VMF_MON_VERSION;
    resp->status  = status;

    /* create the VMF message */
    NW_VMF_BASIC_MSG_GROUP(&vmf_basic_msg) = VMF_TRACE_CTRL;
    NW_VMF_BASIC_MSG_EVENT(&vmf_basic_msg) = VMF_CTRL_MONITOR_RESPONSE;
    NW_VMF_BASIC_MSG_DATA_LENGTH(&vmf_basic_msg) = sizeof(vmf_ctrl_monitoring_resp_t) - VMF_MON_TEXT_LEN + len + 1;

    /* send data to VMF */
    vmf_ret = nw_vmf_send_basic (cid,(vmf_basic_msg_t*)&vmf_basic_msg);
    return vmf_ret;
}



/**************************************************************************//**
 *
 *   Function Name: vmf_mon_handle_request()
 *
 *   Description:   handler for VMF_CTRL_MONITOR_REQUEST messages
 *
 *   Parameters:    cid
 *                  vmf message
 *
 *   Return value:  VMF_OK if message was handled
 *
 ******************************************************************************/
vmf_ret_t  vmf_mon_handle_request(vmf_client_id_t cid, vmf_msg_t *p_vmf_msg)
{
    unsigned8                   status= VMF_MON_STATUS_UNKNOWN;
    vmf_ctrl_monitoring_req_t   *req;
    vmf_ret_t                   vmf_ret = VMF_ERROR;
    char                        text[VMF_MON_TEXT_LEN];

    text[0]=0;

    /* argument check */
    if ( 0 == cid)
    {
        return VMF_ERROR;
    }
    else if (NULL == p_vmf_msg)
    {
        return VMF_ERR_NULL_POINTER;
    }
    else if (NW_VMF_MSG_GROUP(p_vmf_msg) != VMF_TRACE_CTRL)
    {
        /* ignore */
        return VMF_OK;
    }
    else if (NW_VMF_MSG_EVENT(p_vmf_msg) != VMF_CTRL_MONITOR_REQUEST)
    {
        /* ignore */
        return VMF_OK;
    }

    req = (vmf_ctrl_monitoring_req_t*)NW_VMF_MSG_DATA_PTR(p_vmf_msg);
    
    /* search for items */
    
    /* ITEM_UP375_GW_CORE */
    if (0 == strncmp(req->item_name,ITEM_UP375_GW_CORE,VMF_MON_ITEM_NAME_LEN))
    {
        /* found ITEM_A5_VMF */
        snprintf(text,VMF_MON_TEXT_LEN,"Gateway up and running");
        (void)vmf_mon_send_response(cid, req->item_name, VMF_MON_STATUS_GREEN, text);
        vmf_ret = true;
    }

    /* ITEM_UP375_GW_CONN */
    else if (0 == strncmp(req->item_name,ITEM_UP375_GW_CONN,VMF_MON_ITEM_NAME_LEN))
    {
        (void)vmf_mon_send_response(cid, req->item_name, conn_status, conn_text);
        vmf_ret = true;
    }

 
   return  vmf_ret;
}


