
#include "windows.h"
#include "nw_vmf.h"
#undef VMF_TRACE

#define ERROR_CHANNEL stderr
//#define USE_OVERLAPPED

/* macros */
#ifdef VMF_TRACE
    #define DEBUG_INFO_HI(trace_task, args...)   VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO, trace_task, (char *)__PRETTY_FUNCTION__, args);
    #define DEBUG_INFO_LO(trace_task, args...)   VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_20, trace_task, (char *)__PRETTY_FUNCTION__, args);
    #define DEBUG_ERROR(trace_task, args...)     VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_ERROR, trace_task, (char *)__PRETTY_FUNCTION__, args);
#else
    #define DEBUG_INFO(trace_task, args...)      {printf("INFO_HI "); printf(trace_task); printf(" "); printf(__PRETTY_FUNCTION__), printf("() -- "); printf(args); printf("\n");}
    #define DEBUG_INFO_HI(trace_task, args...)   if (verbose>1) {printf("INFO_HI "); printf(trace_task); printf(" "); printf(__PRETTY_FUNCTION__), printf("() -- "); printf(args); printf("\n");}
    #define DEBUG_INFO_LO(trace_task, args...)   if (verbose>2) {printf("INFO_LO "); printf(trace_task); printf(" "); printf(__PRETTY_FUNCTION__), printf("() -- "); printf(args); printf("\n");}
    #define DEBUG_ERROR(trace_task, args...)     if (verbose>0) {printf("ERROR   "); printf(trace_task); printf(" "); printf(__PRETTY_FUNCTION__), printf("() -- "); printf(args); printf("\n");}
#endif
#define bool    BOOL
#define VMF_TRID_NAME               "VMF-SATURN-GW"
#define VMF_TRACE_TASK_MAIN         "MAIN"
#define VMF_TRACE_TASK_VMF          "VMF"
#define VMF_TRACE_TASK_COM          "COM"
#define VMF_TRACE_TASK_FLASH        "FLASH/BOOT"

#define VMF_RECEIVER_STACK_SIZE     (64 * 1024)
#define COM_PORT_INVALID            99
#define IO_MSG_DELIMITER            0x0A
#define IO_MSG_DATALEN_MAX          4000
#define WRITE_RETRY_COUNT_MAX       10
#define SYNC_COUNT_MAX              100
#define SYNC_COUNT_WAIT_MS          20
#define VMF_SAT_TX_GRP_DEF          100     /* Saturn->Host */
#define VMF_SAT_RX_GRP_DEF          101     /* Host->Saturn */
#define VMF_SAT_MSG_EVT_DEF         1       /* saturn message event */
#define TRANSFER_BUFFER_SIZE        (1024)

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


/* variables */
static  bool                    do_flash=false;
static  bool                    do_load=false;
static  bool                    flash_resp=false;
static  bool                    load_resp=false;
static  bool                    load_ack= false;
static  char                    filename[255]={0};
static  unsigned8               tx_group=VMF_SAT_TX_GRP_DEF;
static  unsigned8               rx_group=VMF_SAT_RX_GRP_DEF;
static  unsigned8               trx_event=VMF_SAT_MSG_EVT_DEF;
static  bool                    synced = false;
static  unsigned8               sync_count = 0;
static  DCB                     dcb;
static  HANDLE                  hPort = 0;
static  int                     com_port = COM_PORT_INVALID;
static  unsigned8               vmf_trid;
static  vmf_client_id_t         vmf_connection_handle;
static  int                     verbose=0;
static  bool                    serial_nak_received = false;
static  LPCSTR                  portname[10] = {0};
static  bool                    dump = false;
static  int                     version=1;
    
#ifdef USE_OVERLAPPED
static OVERLAPPED               ovrlpRead={0};
static OVERLAPPED               ovrlpWrite={0};
#endif

/* function prototypes */
static void usage               (void);
static void current_setup       (void);
static bool GetOpt              (int argc, char *argv[]);
static bool OpenSerial          (int com_port);
static void CloseSerial         (void);
static int Receive_Message      (BYTE *buffer,int len);
static bool WriteSerial         (unsigned16 len, unsigned8 *buffer);
bool create_vmf_receiver_thread (void);
static void *vmf_thread_handler (void *pNoArg);
static void vmf_message_handler (vmf_basic_msg_t *vmf_basic_msg);
bool vmf_send_io_command        (unsigned16 len, char *cmd);
static int Read_COM(HANDLE hd, unsigned8 *buffer, int len);

static void nw_con_HexDump          (char * name,unsigned8 *buffer,int len);
static void print_dcb               (DCB *pdcb);
unsigned8   calc_cs                 (unsigned8 cs,unsigned8* buff, int len);
static bool start_download_transfer (char *flash_file);
static bool start_flash_transfer    (char *flash_file);
static void send_board_number       (void);

int main(int argc, char *argv[])
{
	int   read_count;
	static BYTE buffer[4096] = {0}; 
	int    i;
    bool   bret=false;


    if (false == GetOpt(argc, argv))
    {
        return 0;
    }

    if (COM_PORT_INVALID == com_port)
    {
        fprintf(stderr, "Invalid COM Port -- Use -c option!\n");
        usage();
        return 0;
    }

    if (false == create_vmf_receiver_thread())
    {
        fprintf(stderr, "Create VMF Receiver thread faile!\n");
        return 0;
    }

    if (VMF_TRACE_REGISTER(&vmf_trid, VMF_TRID_NAME) < 0)
    {
        fprintf(stderr, "CANNOT CONNECT TO VMF TRACER!!!\n");
    }

    while (false == synced)
    {
        delay(20);
        sync_count ++;
        if (sync_count > SYNC_COUNT_MAX)
        {
            fprintf(stderr, "VMF Receiver thread does NOT sync! EXIT!!");
            return 0;
        }
    }


	bret = OpenSerial(com_port);
	if (false == bret)
    {
        return 0;
    }
    DEBUG_INFO_HI(VMF_TRACE_TASK_MAIN, "COM Port Open -- Now waiting for commands...");


    /* flash or load Saturn if requested via command line */
    if (do_flash)
    {
        bret = start_flash_transfer(filename);
        if (false == bret)
        {
            DEBUG_INFO_HI(VMF_TRACE_TASK_MAIN, "download transfer of %s failed",filename);
        }
    }
    else if(do_load)
    {
        bret = start_download_transfer(filename);
        if (false == bret)
        {
            DEBUG_INFO_HI(VMF_TRACE_TASK_MAIN, "download transfer of %s failed",filename);
        }
    }
    else
    {
        delay(500);
        send_board_number();
    }    
    
	while (true)
	{
		read_count = Receive_Message(buffer,sizeof(buffer));
		if (read_count > 0)
		{
            serial_nak_received = false;            /* clear if there was  a valid transfere */
#if 0
			for (i=0; i<read_count; i++)
			{
				DEBUG_INFO_LO(VMF_TRACE_TASK_MAIN, "     %d", buffer[i]);
			}
#endif
            /* forward message to VMF */
            if (VMF_OK != vmf_send_io_command((unsigned16)read_count, (char *)buffer))
            {
                DEBUG_ERROR(VMF_TRACE_TASK_MAIN, "vmf_send_io_command failed!");
            }
            
		}

	}

	CloseSerial();

	DEBUG_INFO_HI(VMF_TRACE_TASK_MAIN, "Finished.");

	return 0;
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

    
#ifdef USE_OVERLAPPED
	hPort = CreateFile((LPCSTR)portname, GENERIC_READ  | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);
    ovrlpRead.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
    ovrlpWrite.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
#else
	hPort = CreateFile((LPCSTR)portname, GENERIC_READ  | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
#endif


    DEBUG_INFO_HI(VMF_TRACE_TASK_COM, "Handle %d -- Error=%d ", hPort, GetLastError());
    memcpy(&dcb,my_dcb,sizeof(dcb));

	dcb.BaudRate = SERIAL_BAUDRATE;	//Baudrate     
	dcb.ByteSize = 8;				//data bits 
	dcb.Parity = NOPARITY;			//parity 
	dcb.StopBits = ONESTOPBIT;		//stop bits
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

#ifdef USE_OVERLAPPED   
    {
        COMMTIMEOUTS tos;
        tos.ReadIntervalTimeout = 10; //1;
        tos.ReadTotalTimeoutMultiplier = 1;
        tos.ReadTotalTimeoutConstant = 10; // 0;
        tos.WriteTotalTimeoutMultiplier = 0;
        tos.WriteTotalTimeoutConstant = 1;// 500;
        SetCommTimeouts( hPort, &tos );
    }
#else
    {
        COMMTIMEOUTS tos;
#if 0
        tos.ReadIntervalTimeout = 1000; //1;
        tos.ReadTotalTimeoutMultiplier = 1;
        tos.ReadTotalTimeoutConstant = 10; // 0;
        tos.WriteTotalTimeoutMultiplier = 0;
        tos.WriteTotalTimeoutConstant = 1;// 500;
#endif
	tos.ReadIntervalTimeout = 0;
	tos.ReadTotalTimeoutMultiplier = 0;
	tos.ReadTotalTimeoutConstant = 10;
	tos.WriteTotalTimeoutConstant = 0;
	tos.WriteTotalTimeoutMultiplier = 0;



        SetCommTimeouts( hPort, &tos );
    }
#endif
    
	/* Get rid of rubbish */
	dwFlags = PURGE_RXCLEAR | PURGE_TXCLEAR;
	PurgeComm(hPort, dwFlags);

	return true;
}

static void CloseSerial(void)
{
	CloseHandle(hPort); 
}

#ifdef USE_OVERLAPPED
/*********************************************************/
/* read a number of bytes from a device                  */
/*********************************************************/
static int Read_COM(HANDLE hd, unsigned8 *buffer, int len)
{
    int     sum_received=0;
	DWORD   bytes_read_count=0;
    DWORD   dwCommModemStatus=0;
    DWORD   dwError=0;
    DWORD   dwRead=0;
    DWORD   dwRet=0;
    
    /* start read */
    while (sum_received < len)
    {
        ReadFile(hd, &(buffer[sum_received]), len-sum_received, &bytes_read_count, &ovrlpRead);
        sum_received+=bytes_read_count;
        
        dwRet = WaitForSingleObject(&ovrlpRead.hEvent,5000);
        if (GetOverlappedResult(hd, &ovrlpRead, &bytes_read_count, FALSE))
        {
            printf(">%d ",bytes_read_count);
        }
        else
        {
            printf(">");
            delay(100);
        }
        
    }     
    return sum_received;
}

#else

/*********************************************************/
/* read a number of bytes from a device                  */
/*********************************************************/
static int Read_COM(HANDLE hd, unsigned8 *buffer, int len)
{
    int sum_received=0;
	DWORD  bytes_read_count=0;
    DWORD  dwCommModemStatus=0;
    DWORD  dwError=0;
    
//    printf("Read_COM start %d bytes\n",len); 


    while (sum_received < len)
    {
    	if (ReadFile (hd, &(buffer[sum_received]), len, &bytes_read_count, 0))
        {
            if (dump)
            {
                if (bytes_read_count>0)
                {
                     nw_con_HexDump("Read_COM",&(buffer[sum_received]),bytes_read_count);
                }
            }
            sum_received+=bytes_read_count;
#if 0
            if (bytes_read_count>0)
            {
                 printf("sum_received = %d\n",sum_received);
            }
            else
            {
                 // printf("-");
            }
#else
            delay(1);               /* important!! without delay (or printf) it will take forever before the other tread is activated */
#endif        
        }
        else
        {
            /* read error */                           
            // printf(".");
            DEBUG_INFO_LO(VMF_TRACE_TASK_COM, "ReadFile failed",bytes_read_count);
            return 0;
        }
    }
    // nw_con_HexDump("Read_COM return",buffer,sum_received);
    return sum_received;
}

#endif


/*********************************************************/
/* receive a message via the COM                         */
/*********************************************************/
static int Receive_Message(BYTE *buffer,int len) 
{ 
    enum
    {
        NO_SYNC,
        SYNC_1,
        SYNC_2
    };
	int         retVal = 0; 
	int         byte_ix = 0;
	unsigned8   byte_received;
    int         syncted=NO_SYNC;	
    int         ret_val=0;
    unsigned16  pl_len=0;
    bool        do_ret=false;

	while (true)
	{
        syncted = NO_SYNC;
        byte_ix = 0;
        
   		/* wait for sync */
        while((syncted != SYNC_2) && (false == do_ret))
        {
    		ret_val = Read_COM (hPort, &byte_received, 1);	// read sync byte

            if (ret_val > 0)
            {
                switch (syncted)
                {
                    case NO_SYNC:
                    if (byte_received == VMF_SAT_SERIAL_NAK)
                    {
                        /* inform other thread that there was a NAK */
                        DEBUG_INFO_LO(VMF_TRACE_TASK_VMF, "Receive_Message()  NAK received - inform tx thread ");
                        serial_nak_received=true;
                        do_ret=true;                        
                    }
                    else if (byte_received == VMF_SAT_LOAD_RESP)
                    {
                        DEBUG_INFO_LO(VMF_TRACE_TASK_VMF, "Receive_Message() VMF_SAT_LOAD_RESP");
                        load_resp = true;
                        do_ret=true;                        
                    }
                    else if (byte_received == VMF_SAT_FLASH_RESP)
                    {
                        DEBUG_INFO_LO(VMF_TRACE_TASK_VMF, "Receive_Message() VMF_SAT_FLASH_RESP");
                        flash_resp = true;
                        do_ret=true;                        
                    }
                    else if (byte_received == VMF_SAT_LOAD_ACK)
                    {
                        DEBUG_INFO_LO(VMF_TRACE_TASK_VMF, "Receive_Message() VMF_SAT_LOAD_ACK");
                        load_ack = true;
                        do_ret=true;                        
                    }
                    else if (byte_received == VMF_SAT_SYNC_1)
                    {
                        DEBUG_INFO_LO(VMF_TRACE_TASK_VMF, "Receive_Message() VMF_SAT_SYNC_1");
                        syncted=SYNC_1;
                    }
                    else
                    {
                        byte_ix =0;
                        syncted = NO_SYNC;
                    }
                    break;
                        
                    case SYNC_1:
                    if (byte_received == VMF_SAT_SYNC_2)
                    {
                        syncted=SYNC_2;
                    }
                    else
                    {
                        byte_ix =0;
                        syncted = NO_SYNC;
                    }
                    break;
                }
            }
        }
        
        if (do_ret)
        {
            DEBUG_INFO_LO(VMF_TRACE_TASK_VMF, "Receive_Message() return 0");
            return 0;
        }

                
        /* in sync read pl-len */
		{
            ret_val = Read_COM(hPort,(unsigned8*) &pl_len, sizeof(pl_len));	        // read 2 byte  ( little endian )
            if (ret_val > 0)
            {
    			DEBUG_INFO_LO(VMF_TRACE_TASK_COM, "pl-len = %d ", pl_len);
            }
            else
            {
    			DEBUG_INFO_LO(VMF_TRACE_TASK_COM, "reading pl-len failed");
                continue;
            }   
         }

        /* in sync read pl */
		{
            if(pl_len > len)
            {
    			DEBUG_INFO_LO(VMF_TRACE_TASK_COM, "Receive_Message pl_len=%d will not fit in buffer (len=%d) -  cutting message ", pl_len,len);
                pl_len=len;
            }
            ret_val = Read_COM (hPort, &(buffer[byte_ix]), pl_len);	    // read pl-len bytes
            if (ret_val > 0)
            {
                byte_ix += ret_val; 
    			DEBUG_INFO_LO(VMF_TRACE_TASK_COM, "read pl ret = %d ", ret_val);
                break;      /* reception of message done */
            }
            else
            {
    			DEBUG_INFO_LO(VMF_TRACE_TASK_COM, "reading pl failed");
                continue;
            }   
         }
	}

    DEBUG_INFO_LO(VMF_TRACE_TASK_COM, "return  %d ", byte_ix);
	return byte_ix; 
} 




/*
*******************************************************************************************************
*** write a buffer content to serial
*******************************************************************************************************
*/
#ifdef USE_OVERLAPPED
static bool WriteSerial(unsigned16 len, unsigned8 *buffer)
{
    bool ret_val = true;
    DWORD bytes_written_count = 0;

	DEBUG_INFO_LO(VMF_TRACE_TASK_COM, "writing %d bytes to serial, hPort=%d, buffer=%p",len,hPort,buffer);
    if (!WriteFile(hPort, (char *)buffer, (DWORD)len, &bytes_written_count, &ovrlpWrite))
    {
        ret_val = false;
    }
	DEBUG_INFO_LO(VMF_TRACE_TASK_COM, "writing to serial done ret_val =%d",ret_val);

    return ret_val;
}
#else


static bool WriteSerial(unsigned16 len, unsigned8 *buffer)
{
    int     summ = 0;
    bool    ret_val = true;
    DWORD   bytes_written_count = 0;

    do
    {
    	DEBUG_INFO_LO(VMF_TRACE_TASK_COM, "writing %d bytes to serial ",len);
        ret_val = WriteFile(hPort, (char *)buffer, (DWORD)len, &bytes_written_count, NULL);
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
#endif






/*
*******************************************************************************************************
*** VMF
*******************************************************************************************************
*/

bool vmf_send_io_command(unsigned16 len, char *cmd)
{
    bool ret_val;
    VMF_VAR_BASIC_MSG_TYP(IO_MSG_DATALEN_MAX) vmf_msg;
    vmf_basic_msg_t *p_vmf_msg = (vmf_basic_msg_t *)&vmf_msg;

    if (NULL == cmd)
    {
        DEBUG_ERROR(VMF_TRACE_TASK_VMF, "NULL pointer");
        return false;
    }

    if (0 == len)
    {
        DEBUG_ERROR(VMF_TRACE_TASK_VMF, "len == 0");
        return false;
    }

    VMF_BASIC_MSG_GROUP_ID(p_vmf_msg)       = tx_group;
    VMF_BASIC_MSG_EVENT_ID(p_vmf_msg)       = VMF_SAT_MSG_EVT_DEF;
    NW_VMF_BASIC_MSG_DATA_LENGTH(p_vmf_msg) = len;
    memcpy(NW_VMF_BASIC_MSG_DATA_PTR(p_vmf_msg), cmd, len);

    ret_val = nw_vmf_send_basic(vmf_connection_handle, p_vmf_msg);

    return ret_val;
}




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
    VMF_VAR_MSG_TYP(IO_MSG_DATALEN_MAX) vmf_msg_last;
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

    vmf_ret = nw_vmf_register_msg_group (vmf_connection_handle, sizeof(rx_group), &rx_group);
    if (vmf_ret < 0)
    {
        DEBUG_ERROR(VMF_TRACE_TASK_VMF, "register_basic_msg_group failed -- vmf_ret == %d", vmf_ret);
    }

    /* allow main to go on... */
    synced = true;

    while(true)
    {
        p_vmf_msg = (vmf_msg_t *)&vmf_msg;
        vmf_ret = nw_vmf_timed_receive (vmf_connection_handle, p_vmf_msg, sizeof(vmf_msg),100);
        DEBUG_INFO_LO(VMF_TRACE_TASK_VMF,"vmf_thread_handler() nw_vmf_timed_receive() returned %d",vmf_ret);
        
        /* test if we have to resend the last message */
        if (serial_nak_received)
        {
            /* re-send message */
            DEBUG_INFO_HI(VMF_TRACE_TASK_VMF,"vmf_thread_handler() NAK received so resend message");
            p_vmf_basic_msg = (vmf_basic_msg_t *)&vmf_msg_last;
            vmf_message_handler (p_vmf_basic_msg);
            delay(50);
        }
        serial_nak_received = false;
        
        if (vmf_ret > 0)
        {
            p_vmf_basic_msg = (vmf_basic_msg_t *)&vmf_msg;
            if (MSG_TYPE_BASIC_MESSAGE == NW_VMF_BASIC_MSG_TYPE(p_vmf_basic_msg))
            {
                /* received a message */
                if (NW_VMF_BASIC_MSG_GROUP(p_vmf_basic_msg) == rx_group)
                {
                    memcpy(&vmf_msg_last,&vmf_msg,sizeof(vmf_msg_last));
                    p_vmf_basic_msg = (vmf_basic_msg_t *)&vmf_msg;
                    vmf_message_handler (p_vmf_basic_msg);
                }
                else
                {
                    DEBUG_INFO_HI(VMF_TRACE_TASK_VMF, "Message group not handled: MsgGroup == % d", NW_VMF_BASIC_MSG_GROUP(p_vmf_basic_msg));
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
*** transfer file to arduino 
*******************************************************************************************************
*/
static bool transfer_file(char *filename)
{
    bool    bret=false;
    bool    first=true;
    
    /* transfer image file to ardu */
    FILE *file=NULL;
    
    DEBUG_INFO_LO(VMF_TRACE_TASK_FLASH,"send file %s to arduino",filename);      
    file=fopen(filename,"rb");
    if (NULL == file)
    {
        printf("error opening %s\n",filename);
        bret=false;
    }
#if 1
    else
    {
        vmf_sat_flash_msg_t     flash_msg={0};

        /* file is open - transfer data */
        unsigned8   data[TRANSFER_BUFFER_SIZE];
        size_t      data_len=0;
        long        summ=0; 
        unsigned32  pl_len=0;                   
     
        /* get file length */
        fseek (file , 0 , SEEK_END);
        pl_len = ftell (file);
        rewind (file);
        
        DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH,"send %d bytes to Saturn",pl_len);
        
        /* transfer flash msg header */
        flash_msg.sync_1 = VMF_SAT_SYNC_1;
        if (version == 2)
        {
            flash_msg.sync_2 = VMF_SAT_SYNC_2_V2;
        }
        else
        {
            flash_msg.sync_2 = VMF_SAT_SYNC_2;
        }
        flash_msg.pl_len = pl_len;
        WriteSerial(sizeof(flash_msg),(unsigned8*)&flash_msg);        
        
        // nw_con_HexDump("flash_msg",(unsigned8*)&flash_msg,sizeof(flash_msg));
   
        do
        {
            /* read file */
            data_len = fread(data, 1,sizeof(data),file);
            DEBUG_INFO_LO(VMF_TRACE_TASK_FLASH,"fread() data_len=%d,summ=%d ",data_len,summ);
            if (data_len > 0)
            {                
                #if 0
                if (first)
                {
                    first = false;
                    nw_con_HexDump("first",(unsigned8*)&data,data_len);
                }
                #endif
                /* send data to arduino */
                bret = WriteSerial(data_len,data);
                if (false == bret)
                {
                    DEBUG_ERROR(VMF_TRACE_TASK_FLASH,"transfer_file() WriteSerial failed");
                    break;     
                }    
            }
            summ +=data_len;
        }while(summ<pl_len);
        DEBUG_INFO(VMF_TRACE_TASK_FLASH,"transfered %d bytes to Arduino",summ); 
    }
#endif
    if (file != NULL)
    {
        fclose(file);
    }
    DEBUG_INFO(VMF_TRACE_TASK_FLASH,"transfered done"); 
    return bret;
}    

/*
*******************************************************************************************************
*** start Saturn flashing
*******************************************************************************************************
*/
static bool start_flash_transfer(char *flash_file)
{
    unsigned8   tx_buffer[10]={0};
    bool        bret=false;
    int         timeout=0;
    bool        tmp_dump;
    
    DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH, "");
    load_ack= false;
    
    if (NULL == flash_file)
    {
        return false;
    }
    
    /* no dump during flashing (to slow) */
    tmp_dump = dump;
    dump = false;
    
    /* send flash request to Ardu */
    tx_buffer[0]= VMF_SAT_FLASH_REQ;
    bret = WriteSerial(1, tx_buffer);       /* send flash request */
    if (false == bret)
    {
        DEBUG_ERROR(VMF_TRACE_TASK_FLASH, " WriteSerial failed!");
        delay(20);
    }
    else
    {
        /* wait for response */
        DEBUG_INFO_LO(VMF_TRACE_TASK_FLASH, " waiting for response");
        for (timeout=0;timeout<CMD_TIMEOUT;timeout++)
        {
            if (true == flash_resp)
            {
                /* received flash response */
                break;
            } 
            {
                /* the flash_resp flag is set inside Receive_Message() */
                unsigned8 buff[1];
                Receive_Message(buff,sizeof(buff));
                DEBUG_INFO_LO(VMF_TRACE_TASK_FLASH," after Receive_Message flash_resp=%d",flash_resp);
            }
            delay(1);   /* wait*/   
        }
        
        bret = flash_resp;
        if (false == flash_resp)
        {
            /* timeout */
            DEBUG_ERROR(VMF_TRACE_TASK_FLASH,"!! timeout waiting for flash response !!");
        }
        else
        {
            /* got response  */
            bret = transfer_file(flash_file);
            DEBUG_INFO(VMF_TRACE_TASK_FLASH," writing firmware to flash");
            flash_resp = false;
            /* wait until flash is writte */
            for (timeout=0;timeout<FLASH_TIMEOUT;timeout++)
            {
                char ch='/';
                if (true == load_ack)
                {
                    /* received load ack */
                    break;
                } 
                {
                    unsigned8 buff[1];
                    Receive_Message(buff,sizeof(buff));
                }
                delay(1);   /* wait*/ 
                if (ch='/')
                {
                    ch = '\\';
                }
                else
                {
                    ch = '/';
                }
                printf("\r%c",ch);                
                  
            }
            if (false == load_ack)
            {
                /* timeout */
                DEBUG_ERROR(VMF_TRACE_TASK_FLASH,"\n!! timeout waiting for load ack !!");
            }
            else
            {
                DEBUG_INFO(VMF_TRACE_TASK_FLASH,"\n!! firmware flash done!!");
            }
        }
    }
    dump=tmp_dump;
    return load_ack;
}


/*
*******************************************************************************************************
*** start Saturn download
*******************************************************************************************************
*/
static bool start_download_transfer(char *flash_file)
{
    unsigned8   tx_buffer[10]={0};
    bool        bret=false;
    int         timeout=0;
    bool        tmp_dump;
    
    DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH, "");
    load_ack= false;
    
    if (NULL == flash_file)
    {
        return false;
    }
    
     /* no dump during flashing (to slow) */
    tmp_dump = dump;
    dump = false;

   /* send flash request to Ardu */
    tx_buffer[0]= VMF_SAT_LOAD_REQ;

    bret = WriteSerial(1, tx_buffer);       /* send flash request */
    if (false == bret)
    {
        DEBUG_INFO_HI(VMF_TRACE_TASK_FLASH, " WriteSerial failed!");
        delay(20);
    }
    else
    {
        /* wait for response */
        for (timeout=0;timeout<CMD_TIMEOUT;timeout++)
        {
            if (true == load_resp)
            {
                /* received flash response */
                break;
            } 
            {
                unsigned8 buff[1];
                Receive_Message(buff,sizeof(buff));
            }
            delay(1);   /* wait*/   
        }
        
        bret = load_resp;
        if (false == load_resp)
        {
            /* timeout */
            DEBUG_ERROR(VMF_TRACE_TASK_FLASH,"!! timeout waiting for flash response !!"); 
        }
        else
        {
            /* got response */
            DEBUG_INFO_LO(VMF_TRACE_TASK_FLASH," received flash response after %dms",timeout);
            bret = transfer_file(flash_file);
            load_resp = false;
            for (timeout=0;timeout<FLASH_TIMEOUT;timeout++)
            {
                if (true == load_ack)
                {
                    /* received load ack */
                    break;
                } 
                {
                    unsigned8 buff[1];
                    Receive_Message(buff,sizeof(buff));
                }
                delay(1);   /* wait*/   
            }
            if (false == load_ack)
            {
                /* timeout */
                DEBUG_ERROR(VMF_TRACE_TASK_FLASH,"!! timeout waiting for load ack !!");
            }
            else
            {
                DEBUG_INFO(VMF_TRACE_TASK_FLASH,"!! firmware download done!!");
            }
        }
    }
    dump=tmp_dump;
    return load_ack;
}



/*
*******************************************************************************************************
*** handle received VMF message
*******************************************************************************************************
*/

static void vmf_message_handler (vmf_basic_msg_t *vmf_basic_msg)
{
    int                 len=0;
    vmf_sat_gw_msg_t    transfer_msg={0};
    bool                bret=false;
    unsigned8           cs=0;
    
    if (VMF_SAT_MSG_EVT_DEF == NW_VMF_BASIC_MSG_EVENT(vmf_basic_msg))
    {
        len = NW_VMF_BASIC_MSG_DATA_LENGTH(vmf_basic_msg);
        if (len <= IO_MSG_DATALEN_MAX)
        {
            DEBUG_INFO_HI(VMF_TRACE_TASK_VMF, "Received VMF_SAT_MSG_EVT_DEF message");

            /* Send data to serial line */
            /* prepare transfer header */
            transfer_msg.sync_1     = VMF_SAT_SYNC_1;
            if (version == 2)
            {
                transfer_msg.sync_2 = VMF_SAT_SYNC_2_V2;
            }
            else
            {
                transfer_msg.sync_2 = VMF_SAT_SYNC_2;
            }
            transfer_msg.pl_len     = len; 
            
            /* send header */
            bret = WriteSerial(sizeof(transfer_msg), (unsigned8 *)&transfer_msg);
            if (false == bret)
            {
                DEBUG_INFO_HI(VMF_TRACE_TASK_VMF, "WriteSerial failed (header)!");
                perror("WriteSerial");
                delay(20);
            }
            else
            {
                /* send payload */                
                bret = WriteSerial(len, NW_VMF_BASIC_MSG_DATA_PTR(vmf_basic_msg));
                if (false == bret)
                {
                    DEBUG_INFO_HI(VMF_TRACE_TASK_VMF, "WriteSerial failed (payload)!");
                    delay(20);
                }
            } 
            /* calc and send checksum */
            cs =  calc_cs(cs,NW_VMF_BASIC_MSG_DATA_PTR(vmf_basic_msg),len);  
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
        usage();
        return false;
    }
    
    while ((opt = getopt(argc, argv, "?hHc:t:r:e:vf:l:db:")) != -1)
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
            break;

            case 'd':
                dump=true;
            break;
            
            case 't':
                /* transmit event group Saturn->Host */
                tx_group = (unsigned8)atoi(optarg);
            break;

            case 'r':
                /* receive event group Host->Saturn */
                rx_group = (unsigned8)atoi(optarg);
            break;

            case 'e':
                /* event for both directions  */
                trx_event = (unsigned8)atoi(optarg);
            break;

            case 'f':
                /* event for both directions  */
                snprintf(filename,sizeof(filename),optarg);
                if (strlen(filename)>0)
                {
                    do_flash = true;
                }
            break;

            case 'l':
                /* event for both directions  */
                snprintf(filename,sizeof(filename),optarg);
                if (strlen(filename)>0)
                {
                    do_load = true;
                }
            break;
            
            case 'b':
                version=atoi(optarg);
            break;


            case 'v':
                verbose++;
            break;
            

        }
    }
    if (verbose > 0)
    {
        current_setup();
    }
    return ret_val;
}

static void usage(void)
{
    printf("************************************************************************\n");
    printf("** NXP-Saturn VMF COM GW 1.7 by J. Becker 2014                        **\n");
    printf("************************************************************************\n");
    printf("**                                                                    **\n");
    printf("** usage: NXP-Saturn-vmf-com-gw.exe [options]                         **\n");
    printf("**                                                                    **\n");
    printf("**     Opt.           Description                                     **\n");
    printf("**     -c <n>         COM port                                        **\n");
    printf("**     -t <n>         VMF-tx-group (Saturn->Host)                     **\n");
    printf("**     -r <n>         VMF-rx-group (Host->Saturn)                     **\n");
    printf("**     -e <n>         VMF-event (both directions)                     **\n");
    printf("**     -f <filename>  flash file to Saturn flash memeory              **\n");
    printf("**     -l <filename>  load filename to Saturn                         **\n");
    printf("**     -v             verbose                                         **\n");
    printf("**     -d             dump messages in hex                            **\n");
    printf("**     -b2            if R2 board                                     **\n");
    printf("** Examples:                                                          **\n");
    printf("** saturn_vmf_com_gw -c 6 -v -v -b2                                   **\n");
    printf("** saturn_vmf_com_gw -c 6 -l \"c:\\tmp\\saturn_flashfile.bin\" -v         **\n");
    printf("** saturn_vmf_com_gw -c 6 -f \"c:\\tmp\\saturn_flashfile.bin\" -v -d      **\n");
    printf("************************************************************************\n");
}

 static void current_setup(void)
 {
    printf("************************************************************************\n");
    printf("**  NXP-Saturn VMF COM GW 1.7 by J. Becker %s %s\n",__DATE__,__TIME__);
    printf("************************************************************************\n");
    printf("** verbosity=%d                                                         \n",verbose);
    printf("** Com-Port = COM%d                                                     \n",com_port);
    printf("** VMF-tx-group (Saturn->Host)= %03d                                    \n",tx_group);
    printf("** VMF-rx-group (Host->Saturn)= %03d                                    \n",rx_group);
    printf("** VMF-event (both directions)= %03d                                    \n",trx_event);
    if (dump)                                                   
    {
        printf("** Message dump enabled                                             \n",trx_event);
    }
    if (do_flash)
    {
      printf("** flash Saturn - filname =%s \n",filename);
    }
    if (do_load)
    {
      printf("** load Saturn - filname =%s \n",filename);
    }
    printf("************************************************************************\n");
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
