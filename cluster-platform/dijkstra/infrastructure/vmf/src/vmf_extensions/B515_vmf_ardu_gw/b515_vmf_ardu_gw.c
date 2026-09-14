#define B515_VMF_ARDU_GW_C

#include "windows.h"
#include "nw_vmf.h"
#include "stub_fkts.h"

#include "b515_vmf_ardu_gw.h"

#undef VMF_TRACE

//#define USE_OVERLAPPED

/* macros */
#ifdef VMF_TRACE
    #define DEBUG_INFO(trace_task, args...)      VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO, trace_task, (char *)__PRETTY_FUNCTION__, args);
    #define DEBUG_INFO_HI(trace_task, args...)   VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO, trace_task, (char *)__PRETTY_FUNCTION__, args);
    #define DEBUG_INFO_LO(trace_task, args...)   VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_20, trace_task, (char *)__PRETTY_FUNCTION__, args);
    #define DEBUG_ERROR(trace_task, args...)     VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_ERROR, trace_task, (char *)__PRETTY_FUNCTION__, args);
#else
    #define DEBUG_INFO(trace_task, args...)      if (verbose>0) {printf("INFO    "); printf(trace_task); printf(" "); printf(__PRETTY_FUNCTION__), printf("() -- "); printf(args); printf("\n");}
    #define DEBUG_INFO_HI(trace_task, args...)   if (verbose>0) {printf("INFO_HI "); printf(trace_task); printf(" "); printf(__PRETTY_FUNCTION__), printf("() -- "); printf(args); printf("\n");}
    #define DEBUG_INFO_LO(trace_task, args...)   if (verbose>1) {printf("INFO_LO "); printf(trace_task); printf(" "); printf(__PRETTY_FUNCTION__), printf("() -- "); printf(args); printf("\n");}
    #define DEBUG_ERROR(trace_task, args...)     {printf("ERROR   "); printf(trace_task); printf(" "); printf(__PRETTY_FUNCTION__), printf("() -- "); printf(args); printf("\n");}
#endif

#define VMF_TRID_NAME               "B515-VMF-GW"
#define VMF_TRACE_TASK_MAIN         "MAIN"
#define VMF_TRACE_TASK_VMF          "VMF"
#define VMF_TRACE_TASK_COM          "COM"
#define PNP_API						"PNP-API"
#define VMF_TRACE_TASK_FLASH        "FLASH/BOOT"

#define VMF_RECEIVER_STACK_SIZE     (64 * 1024)
#define COM_PORT_INVALID            99
#define IO_MSG_DELIMITER            0x0A
#define IO_MSG_DATALEN_MAX          256
#define WRITE_RETRY_COUNT_MAX       10
#define SYNC_COUNT_MAX              100
#define SYNC_COUNT_WAIT_MS          20



/* types */
#define CMD_TIMEOUT                 (500)
#define FLASH_TIMEOUT               (20000)     /* max flash write time */
    
//#define SERIAL_BAUDRATE             CBR_57600
#define SERIAL_BAUDRATE             CBR_115200


#define VMF_PNP_SYNC_1              (0xa5) 
#define VMF_PNP_SYNC_2              (0x5a)
#define VMF_PNP_ACK                 (0xa0)	
#define VMF_PNP_NAK                 (0xa1)
#define MAX_SERIAL_PAYLOAD          (1000)

#pragma pack(push,1)
typedef struct
{
    unsigned8   sync_1;	    // 0xa5
    unsigned8   sync_2;	    // 0x5a
    unsigned8   cmd;		// command
    unsigned8   address;	// address register
    unsigned8   pl_len;	    // payload len
    unsigned8   pl[0];      // payload
    unsigned8   cs;         // checksum
}pnp_gw_msg_t;

typedef struct
{
    unsigned8   sync_1;	    // 0xa5
    unsigned8   sync_2;	    // 0x5a
    unsigned8   cmd;		// command
    unsigned8   address;	// address register
    unsigned8   pl_len;	    // payload len
}pnp_gw_msg_header_t;
#pragma pack(pop,1)

/* transfer states */
enum
{
    ST_UNKNOWN,
    ST_NO_SYNC,
    ST_SYNC_2,
    ST_CMD,
    ST_ADDR,
    ST_PL_LEN,
    ST_PL,
    ST_CS,
    ST_NAK,
    ST_ACK,
    ST_LEAVE
};


typedef struct
{
    unsigned8   cmd;        // command
    unsigned8   address;    // address register
    unsigned8   pl_len;	    // payload len
    unsigned8   pl[0];	
}vmf_pn3030D_msg_t;
 




/* variables */
static  bool                    do_flash=false;
static  bool                    do_load=false;
static  bool                    flash_resp=false;
static  bool                    load_resp=false;
static  bool                    load_ack= false;
static  char                    filename[255]={0};
static  unsigned8               tx_group=PN3030D_OUT;
static  unsigned8               rx_group=PN3030D_IN;
static  unsigned8               trx_event=PN3030D_MSG_EVT_DEF;
static  bool                    synced = false;
static  unsigned8               sync_count = 0;
static  DCB                     dcb;
static  HANDLE                  hPort = 0;
static  int                     com_port = COM_PORT_INVALID;
static	unsigned8               vmf_trid;
		vmf_client_id_t         vmf_connection_handle = -1;
static  int                     verbose=0;
static  bool                    serial_nak_received = false;
static  LPCSTR                  portname[10] = {0};
static  bool                    dump = false;
static  int                     version=1;
static  unsigned8				response_cmd;
static  unsigned8				response_addr;
static  unsigned8				response_buffer[IO_MSG_DATALEN_MAX]; 
static	unsigned16				response_buffer_len=0;

static	unsigned8				tx_last_addr;
static	unsigned8				tx_last_msg_len;
static  unsigned8				tx_last_cmd;
static 	unsigned8				*ptx_last_msg;
static 	unsigned8				rx_q_buffer[MAX_SERIAL_PAYLOAD];
static 	int						rx_q_rd_ix = 0;
static 	int						rx_q_wr_ix = 0;
static 	int						rx_q_len = 0;


/* function prototypes */
static void usage               (void);
static void current_setup       (void);
static bool GetOpt              (int argc, char *argv[]);
static bool OpenSerial          (int com_port);
static void CloseSerial         (void);
static void Receive_Message     (void);
static bool WriteSerial         (unsigned8 *buffer, unsigned16 len);
bool create_vmf_receiver_thread (void);
static void *vmf_thread			(void *pNoArg);
static void vmf_message_handler (vmf_basic_msg_t *vmf_basic_msg);
static vmf_ret_t vmf_send_pn3030d_response        (char *cmd, unsigned16 len);
static int Read_COM(HANDLE hd, unsigned8 *buffer, int len);

static void nw_con_HexDump      (char * name,unsigned8 *buffer,int len);
static void print_dcb           (DCB *pdcb);
static unsigned8 calc_cs        (unsigned8* buff, int len);
static int serial_write_byte    (unsigned8 data);
static int serial_write_buffer  (unsigned8 *pdata, int len);
static void serial_send_message (unsigned8 cmd, unsigned8 address, unsigned8 *data, unsigned8 len);

static void rx_q_push_data(unsigned8 *data, int len);
static unsigned8 rx_q_pop_byte(void);
static void rx_q_get_rx_bytes(unsigned8 *buffer,int num);
static void rx_q_preload_bytes(int num);



/*************************************************************************//**
 *
 *   main entry into the module \n
 *	 
 *
 *   \param[in]         argc
 *   \param[in]         argv
 *
 *   \return            true if OK
 *
 ******************************************************************************/
int main(int argc, char *argv[])
{
	int   read_count;
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
        fprintf(stderr, "Create VMF Receiver thread failed!\n");
        return 0;
    }
	
    if (false == create_pnp_log_vmf_thread())
    {
        fprintf(stderr, "Create PNP logic lovel thread failed!\n");
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


    /* seriel receive loop*/
	while (true)
	{
		Receive_Message();
	}

	CloseSerial();

	DEBUG_INFO_HI(VMF_TRACE_TASK_MAIN, "Finished.");

	return 0;
}




/*************************************************************************//**
 *
 *   open the serial device \n
 *	 the handle is stored in the global variable hPort
 *
 *   \param[in]         COM port number ( 1 for COM1)
 *
 *   \return            true if OK
 *
 ******************************************************************************/
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

	dcb.BaudRate = SERIAL_BAUDRATE;	//Baudrate     
	dcb.ByteSize = 8;				//data bits 
	dcb.Parity = NOPARITY;			//parity 
	dcb.StopBits = ONESTOPBIT;		//stop bits
    dcb.fBinary    =  TRUE;
    dcb.fParity   = FALSE;
    dcb.fOutxCtsFlow  = FALSE;
    dcb.fOutxDsrFlow  = FALSE;
    dcb.fDtrControl    = DTR_CONTROL_DISABLE; // DTR_CONTROL_ENABLE; // DTR_CONTROL_DISABLE;
    // dcb.fDsrSensitivity  = FALSE;
    dcb.fTXContinueOnXoff = FALSE;
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
		tos.ReadTotalTimeoutConstant = 1;
		tos.WriteTotalTimeoutConstant = 0;
		tos.WriteTotalTimeoutMultiplier = 0;
        SetCommTimeouts( hPort, &tos );
    }
    
	/* Get rid of rubbish */
	dwFlags = PURGE_RXCLEAR | PURGE_TXCLEAR;
	PurgeComm(hPort, dwFlags);

	return true;
}



/*************************************************************************//**
 *
 *   close a serial device handle\n
 *	 the handle is taken from the global variable hPort
 *
 *   \param[in]         Cvoid
 *
 *   \return            void
 *
 ******************************************************************************/

static void CloseSerial(void)
{
	CloseHandle(hPort); 
}


/*************************************************************************//**
 *
 *   read a message from an open COM \n
 *	 
 *   \param[in]         handle
 *   \param[in]         message buffer
 *   \param[in]         number of bytes to read
 *
 *   \return            number of bytes received
 *
 ******************************************************************************/
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
//          SwitchToThread();
//			pthread_yield();
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


/*************************************************************************//**
 *
 *   push data to the rx queue \n
 *	 
 *   \param[out]        buffer
 *   \param[in]         number of bytes
 *
 *   \return            void
 *
 ******************************************************************************/
static void rx_q_push_data(unsigned8 *data, int len)
{
	if (0 == rx_q_len)
	{
		rx_q_rd_ix = 0;
		rx_q_wr_ix = 0;
	}
	memcpy(&rx_q_buffer[rx_q_wr_ix],data,len);
	rx_q_len +=len;
	rx_q_wr_ix += len;
	
}


/*************************************************************************//**
 *
 *   pop one byte from the rx queue
 *	 
 *
 *   \return            byte
 *
 ******************************************************************************/
static unsigned8 rx_q_pop_byte(void)
{
		unsigned8	by;

		if (0 == rx_q_len)
		{
			rx_q_preload_bytes(1);
		}
		
		by = rx_q_buffer[rx_q_rd_ix];
		rx_q_rd_ix ++;
		rx_q_len--;

		if (0 == rx_q_len)
		{
			rx_q_rd_ix = 0;
			rx_q_wr_ix = 0;
		}
		return by;
}


/*************************************************************************//**
 *
 *   load a specific number of bytes into a buffer \n
 *	 
 *   \param[out]        buffer
 *   \param[in]         number of bytes
 *
 *   \return            void
 *
 ******************************************************************************/
static void rx_q_get_rx_bytes(unsigned8 *buffer,int num)
{
	int ret_val;
	int curr_num=0;
	while (curr_num < num)
	{
		ret_val = Read_COM (hPort, &buffer[curr_num], num - curr_num);	
		if (ret_val > 0)
		{
			curr_num += ret_val;
		}
	}
}


/*************************************************************************//**
 *
 *   preload bytes into rx queue \n
 *	 
 *   \param[in]         number of bytes
 *
 *   \return            void
 *
 ******************************************************************************/
static void rx_q_preload_bytes(int num)
{
	unsigned8	data[MAX_SERIAL_PAYLOAD];
	int len;

	if (rx_q_len >= num)
	{
		/* enough data already in the queue */
		return;
	}
	len = num - rx_q_len;
	rx_q_get_rx_bytes(data,len);
	rx_q_push_data(data,len);
	
}





/*************************************************************************//**
 *
 *   serial receive handler \n
 *	 
 *   \param[in]         void
 *
 *   \return            void
 *
 ******************************************************************************/
static void Receive_Message(void) 
{ 
	unsigned8   rx_byte;
    unsigned16  pl_len=0;
    bool        do_ret=false;
	int         retVal = 0; 
	int         byte_ix = 0;
    int         state=ST_NO_SYNC;	
    int         ret_val=0;
    unsigned8   current_cmd;
    unsigned8   current_addr;
    unsigned8   current_pl_len=0;
    unsigned8   current_pl_ix=0;

    unsigned8   current_pl[MAX_SERIAL_PAYLOAD];

	while (true)
	{
        state = ST_NO_SYNC;
        byte_ix = 0;
        
   		/* wait for sync */
        while(state != ST_LEAVE)
        {

			#if 1
			rx_byte = rx_q_pop_byte();
			ret_val = 1;
			#else
    		ret_val = Read_COM (hPort, &rx_byte, 1);	// read a single byte
			#endif

            if (ret_val > 0)
            {
                switch (state)
                {
                    case ST_NO_SYNC:
                    {
                        if (rx_byte == VMF_PNP_NAK)
                        {
                            DEBUG_INFO_HI(VMF_TRACE_TASK_VMF, "VMF_PNP_NAK ");
                            
							/* re-transmit last message */
							if (tx_last_msg_len > 0)
							{
								DEBUG_ERROR(VMF_TRACE_TASK_VMF, "re-transmit last message, cmd=%d, tx_last_msg_len=%d",tx_last_cmd,tx_last_msg_len);
								serial_send_message(tx_last_cmd, tx_last_addr, ptx_last_msg, tx_last_msg_len);
								tx_last_msg_len = 0; 		/* only one re-transmission */
							}
							else
							{
								DEBUG_INFO_LO(VMF_TRACE_TASK_VMF, "no last message to re-transmit ");
							}
							rx_q_preload_bytes(7);
							state = ST_NO_SYNC;                        
                        }
                        else if (rx_byte == VMF_PNP_ACK)
                        {
                            DEBUG_INFO_LO(VMF_TRACE_TASK_VMF, "VMF_PNP_ACK");
							tx_last_msg_len = 0;
 							rx_q_preload_bytes(7);
                            state = ST_NO_SYNC;                        
                        }
                        else if (rx_byte == VMF_PNP_SYNC_1)
                        {
                            DEBUG_INFO_LO(VMF_TRACE_TASK_VMF, "VMF_PNP_SYNC_1");
                            state=ST_SYNC_2;
                        }
                        else
                        {
							/* invalid state */
                            byte_ix =0;
							rx_q_preload_bytes(7);
                            state = ST_NO_SYNC;
                        }
                    }
                    break;
                        
                    case ST_SYNC_2:
                    {
                        if (rx_byte == VMF_PNP_SYNC_2)
                        {
                            DEBUG_INFO_LO(VMF_TRACE_TASK_VMF, "VMF_PNP_SYNC_2");
                            state=ST_CMD;
                        }
                        else
                        {
							rx_q_preload_bytes(7);
                            state = ST_NO_SYNC;
                        }
                    }
                    break;
 
 
                    case ST_CMD:
                  	{
                        DEBUG_INFO_LO(VMF_TRACE_TASK_VMF,"state = ST_CMD, cmd = %d",rx_byte);
                        /* read cmd byte */
                        current_cmd = rx_byte;
                        state = ST_ADDR;
                    }
                    break;
                   
                    
                    case ST_ADDR:
                  	{
                        DEBUG_INFO_LO(VMF_TRACE_TASK_VMF,"state = ST_CMD, addr = %d",rx_byte);
                        /* read register address  byte */
                        current_addr = rx_byte;
                        state = ST_PL_LEN;
                    }
                    break;
            
            
                    case ST_PL_LEN:
                  	{
                        DEBUG_INFO_LO(VMF_TRACE_TASK_VMF,"state = ST_PL_LEN, len = %d",rx_byte);
                        /* read payload len */
                        current_pl_len = rx_byte;
						if (current_pl_len > IO_MSG_DATALEN_MAX)
						{
							/* invalid payload */
							DEBUG_INFO_HI(VMF_TRACE_TASK_VMF,"payload to big = %d",rx_byte);
							rx_q_preload_bytes(7);
							state = ST_NO_SYNC;
						}
                        else if (current_pl_len>0)
                        {
							rx_q_preload_bytes(current_pl_len+1); /* payload + checksum*/
            				current_pl_ix = 0;
                            state = ST_PL;
                        }
                        else
                        {     
                            /* no payload */
                            state = ST_CS;
                        }
                    }
                    break;
                   
                    
                    case ST_PL:
                    {
                        DEBUG_INFO_LO(VMF_TRACE_TASK_VMF,"state = ST_PL");
                        /* read payload */
                        current_pl[current_pl_ix]=rx_byte;
                        if (++current_pl_ix >= current_pl_len)
                        {
            				/* we are done - so go to the ST_CS state */
                            state = ST_CS;
                        }
            			/* stay in ST_PL state */
                    }
                    break; 
                    
                    case ST_CS:
                    {
                        /* test checksum */
                        unsigned8   cs;
                        
                        DEBUG_INFO_LO(VMF_TRACE_TASK_VMF,"state = ST_CS, cs=%d", rx_byte);
                        cs = calc_cs(current_pl,current_pl_len);
                        if (cs == rx_byte)
                        {
                            bool    bret;
							/* send ACK */
            				DEBUG_INFO_HI(VMF_TRACE_TASK_VMF,"CS OK");
        					DEBUG_INFO_LO(VMF_TRACE_TASK_VMF,"send ACK");
                            serial_write_byte(VMF_PNP_ACK);
							ret_val = current_pl_len;
							
							/* store message into response buffer */
							{
								response_addr = current_addr;
								response_cmd = current_cmd;
								nw_os_smemcpy(response_buffer, sizeof(response_buffer),current_pl, current_pl_len);
								response_buffer_len = current_pl_len;
							}
							
							/* transfer message via vmf */
							{
								vmf_ret_t	vmf_err;
								unsigned8			buffer[IO_MSG_DATALEN_MAX+ sizeof(vmf_pn3030D_msg_t)];
								vmf_pn3030D_msg_t	*pn3030_pl = (vmf_pn3030D_msg_t*)buffer;
							
								pn3030_pl->cmd = current_cmd;
								pn3030_pl->address = current_addr;
								pn3030_pl->pl_len = current_pl_len;
								nw_os_smemcpy (pn3030_pl->pl, IO_MSG_DATALEN_MAX, current_pl,current_pl_len);
								
								vmf_err = vmf_send_pn3030d_response((char *)buffer,(unsigned16)sizeof(vmf_pn3030D_msg_t) + current_pl_len);
								if (VMF_OK != vmf_err)
								{
									DEBUG_ERROR(VMF_TRACE_TASK_MAIN, "vmf_send_pn3030d_response() failed!, error=%d",vmf_err);
								}
							}
							
							rx_q_preload_bytes(7);
                            state = ST_NO_SYNC;    
                        }
                        else
                        {
                            /* cs error -send NAK */
            				DEBUG_ERROR(VMF_TRACE_TASK_VMF,"CS Error");
                            serial_write_byte(VMF_PNP_NAK);
							rx_q_preload_bytes(7);
							state = ST_NO_SYNC;
                        }
                    }
            		break;
                    
                    default:
                    {
                        /* invalid state - set to start state */
            			DEBUG_INFO_HI(VMF_TRACE_TASK_VMF,"invalid state=%d\n",state);
						rx_q_preload_bytes(7);
                        state = ST_NO_SYNC;        
                    }
                }
            } /*if (ret_val > 0) */
			else
			{
				delay(0);
			}
        }  /* while(state != ST_DONE) */
    }   /* while(true) */
} 



 /*************************************************************************//**
 *
 *   calculate checksum of a given buffer\n
 *
 *   \param[in/out]     pointer to message buffer
 *   \param[in]         length of message
 *   \return            checksum
 *
 ******************************************************************************/
static unsigned8 calc_cs(unsigned8* buff, int len)
{
    int cnt;
    unsigned8   cs=0;
    for (cnt=0;cnt<len;cnt++)
    {
        cs^=buff[cnt];    
    }
    return cs;
}


/*************************************************************************//**
*
*   send a serial byte to the PC \n
*   
*
*   \param[in]         byte to send
*    
*   \return            numbers of byte written
*
******************************************************************************/
static int serial_write_byte(unsigned8 data)
{
    int rlen;
    (void)WriteSerial(&data,1);
    
    return 1;
}
 
 
/*************************************************************************//**
*
*   send a buffer via serial to the the PC \n
*   
*
*   \param[in]         pointer to data
*   \param[in]         length of data
*    
*   \return            numbers of byte written
*
******************************************************************************/
static int   serial_write_buffer(unsigned8 *pdata, int len)
{
    (void)WriteSerial(pdata,len);
    return len;
}

 


/*************************************************************************//**
*
*   send a message to the serial
*
*
*   \param[in] 	 	command byte
*   \param[in] 	 	address byte
*   \param[in]  	pointer to message buffer
*   \param[in]      length of message
*   \return        	void
*
******************************************************************************/
void serial_send_message(unsigned8 cmd, unsigned8 address, unsigned8 *data, unsigned8 len)
{
    pnp_gw_msg_header_t    header;
    unsigned8   cs;
    
    ptx_last_msg 	= data;
	tx_last_addr 	= address;
	tx_last_msg_len = len;
	tx_last_cmd 	= cmd;
	
    header.sync_1  	= VMF_PNP_SYNC_1;
    header.sync_2  	= VMF_PNP_SYNC_2;
    header.cmd     	= cmd;
    header.address 	= address;
    header.pl_len 	= len;
     
    /* send header */
    (void)serial_write_buffer((unsigned8*)&header, sizeof(header));

    /* send payload if this is not a read request */
	if (cmd != CMD_READ_REQ)
	{
		/* send payload */
		(void)serial_write_buffer(data, len);
		/* calc checksum */
		cs = calc_cs(data, len);
	}
	else
	{
//		printf("cs set to 0\n");
		cs = 0;
	}
    (void)serial_write_byte(cs);    
}



/*************************************************************************//**
 *
 *   write a message to the serial \n
 *	 
 *   \param[in]         message buffer
 *   \param[in]         message size
 *
 *   \return            true if OK
 *
 ******************************************************************************/
static bool WriteSerial(unsigned8 *buffer, unsigned16 len)
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




/*************************************************************************//**
 *
 *   send the PN3030D read response to VMF\n
 *	 
 *   \param[in]         message buffer
 *   \param[in]         message size
 *
 *   \return            true if OK
 *
 ******************************************************************************/
vmf_ret_t vmf_send_pn3030d_response(char *cmd, unsigned16 len)
{
    vmf_ret_t ret_val;
    VMF_VAR_BASIC_MSG_TYP(IO_MSG_DATALEN_MAX) vmf_msg;
    vmf_basic_msg_t *p_vmf_msg = (vmf_basic_msg_t *)&vmf_msg;

    if (NULL == cmd)
    {
        DEBUG_ERROR(VMF_TRACE_TASK_VMF, "NULL pointer");
        return VMF_ERROR;
    }

    if (0 == len)
    {
        DEBUG_ERROR(VMF_TRACE_TASK_VMF, "len == 0");
        return VMF_ERROR;
    }

    VMF_BASIC_MSG_GROUP_ID(p_vmf_msg)       = tx_group;
    VMF_BASIC_MSG_EVENT_ID(p_vmf_msg)       = cmd[0]; //PN3030D_MSG_EVT_DEF;
    NW_VMF_BASIC_MSG_DATA_LENGTH(p_vmf_msg) = len;
    memcpy(NW_VMF_BASIC_MSG_DATA_PTR(p_vmf_msg), cmd, len);

    ret_val = nw_vmf_send_basic(vmf_connection_handle, p_vmf_msg);
    return ret_val;
}


/*************************************************************************//**
 *
 *   send a  message to the PN3030D gateway via VMF\n
 *	 
 *   \param[in]         message buffer
 *   \param[in]         message size
 *
 *   \return            vmf_ret_t
 *
 ******************************************************************************/
vmf_ret_t vmf_send_msg2pn(unsigned8 *data, unsigned16 len)
{
	vmf_ret_t vmf_ret;

	/* send to the PN3030D rx group*/
	vmf_ret = vmf_send_msg(rx_group, 1, data, len);
	
	return vmf_ret;
}



/*************************************************************************//**
 *
 *   send a command to PN3030D-gateway via VMF\n
 *	 
 *   \param[in]         command
 *
 *   \return            vmf_ret_t
 *
 ******************************************************************************/
vmf_ret_t vmf_send_cmd2pn(unsigned8 cmd)
{
	vmf_ret_t vmf_ret;

	/* send to the PN3030D rx group*/
	vmf_ret = vmf_send_msg(rx_group, trx_event, &cmd, 1);
	
	return vmf_ret;
}




/*************************************************************************//**
 *
 *   send a basic message to VMF\n
 *	 
 *   \param[in]         vmf group
 *   \param[in]         vmf event
 *   \param[in]         message buffer
 *   \param[in]         message size
 *
 *   \return            VMF_OK if OK
 *
 ******************************************************************************/
vmf_ret_t vmf_send_msg(unsigned8 group, unsigned8 event, unsigned8 *data, unsigned16 len)
{
    vmf_ret_t ret_val;
    VMF_VAR_BASIC_MSG_TYP(IO_MSG_DATALEN_MAX) vmf_msg;
    vmf_basic_msg_t *p_vmf_msg = (vmf_basic_msg_t *)&vmf_msg;

    if (NULL == data)
    {
        DEBUG_ERROR(VMF_TRACE_TASK_VMF, "NULL pointer");
        return VMF_ERROR;
    }
	else if (0 == len)
    {
        DEBUG_ERROR(VMF_TRACE_TASK_VMF, "len == 0");
        return VMF_ERROR;
    }
	else if (len > IO_MSG_DATALEN_MAX)
	{
        DEBUG_ERROR(VMF_TRACE_TASK_VMF, "len > %d",IO_MSG_DATALEN_MAX);
        return VMF_ERROR;
	}

    VMF_BASIC_MSG_GROUP_ID(p_vmf_msg)       = group;
    VMF_BASIC_MSG_EVENT_ID(p_vmf_msg)       = event;
    NW_VMF_BASIC_MSG_DATA_LENGTH(p_vmf_msg) = len;
    memcpy(NW_VMF_BASIC_MSG_DATA_PTR(p_vmf_msg), data, len);

    ret_val = nw_vmf_send_basic(vmf_connection_handle, p_vmf_msg);
    return ret_val;
}


/*************************************************************************//**
 *
 *   HThis function will create the VMF thread\n
 *	 
 *   \param[in]         vmf void
 *
 *   \return            true if OK
 *
 ******************************************************************************/
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
    iRet = pthread_create (&th  , &attr, vmf_thread, NULL);
    pthread_attr_destroy(&attr);
    if (iRet)
    {
        DEBUG_ERROR(VMF_TRACE_TASK_VMF, "create_vmf_receiver_thread() error! errno = %d",iRet);
        return false;
    }

    return true;
}



/*************************************************************************//**
 *
 *   VMF thread\n
 *	 This thread will receive all VMF messages
 *
 *   \param[in]         vmf message
 *
 *   \return            void
 *
 ******************************************************************************/
static void *vmf_thread(void *pNoArg)
{
    vmf_ret_t vmf_ret;
    VMF_VAR_MSG_TYP(IO_MSG_DATALEN_MAX) vmf_msg;
    VMF_VAR_MSG_TYP(IO_MSG_DATALEN_MAX) vmf_msg_last;
    vmf_msg_t *p_vmf_msg = (vmf_msg_t *)&vmf_msg;
    vmf_basic_msg_t *p_vmf_basic_msg = (vmf_basic_msg_t *)&vmf_msg;



    DEBUG_INFO_HI(VMF_TRACE_TASK_VMF, "VMF Receiver started...");

    vmf_ret = nw_vmf_connect(VMF_TRID_NAME, 0, 0, VMF_CLIENT_QUEUE_SIZE_STANDARD, VMF_CLIENT_QUEUE_MSG_SIZE_STANDARD);
    if (vmf_ret <= 0)
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
        DEBUG_INFO_LO(VMF_TRACE_TASK_VMF,"vmf_thread() nw_vmf_timed_receive() returned %d",vmf_ret);
        
        /* test if we have to resend the last message */
        if (serial_nak_received)
        {
            /* re-send message */
            DEBUG_INFO_HI(VMF_TRACE_TASK_VMF,"vmf_thread() NAK received so resend message");
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
					// nw_con_HexDump("vmf rx_msg",(unsigned8*)p_vmf_basic_msg,vmf_ret);
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
                nw_con_HexDump("invalid vmf-rx_msg",(unsigned8*)p_vmf_basic_msg,vmf_ret);
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





/*************************************************************************//**
 *
 *   Handler for incomming VMF messages\n
 *	 
 *   \param[in]         vmf message
 *
 *   \return            true if OK
 *
 ******************************************************************************/
static void vmf_message_handler (vmf_basic_msg_t *vmf_basic_msg)
{
    int                 len=0;
    vmf_pn3030D_msg_t   *pn_msg=NULL;
    
    DEBUG_INFO_HI(VMF_TRACE_TASK_VMF, "vmf event = %d",NW_VMF_BASIC_MSG_EVENT(vmf_basic_msg));
    
   // if (PN3030D_MSG_EVT_DEF == NW_VMF_BASIC_MSG_EVENT(vmf_basic_msg))
    {
        len = NW_VMF_BASIC_MSG_DATA_LENGTH(vmf_basic_msg);
        if (len <= IO_MSG_DATALEN_MAX)
        {
            /* forward message to serial*/
            pn_msg = (vmf_pn3030D_msg_t*)NW_VMF_BASIC_MSG_DATA_PTR(vmf_basic_msg); 
            DEBUG_INFO_HI(VMF_TRACE_TASK_VMF, "send message with cmd:%d to PN3030D",pn_msg->cmd);
            serial_send_message (pn_msg->cmd, pn_msg->address, pn_msg->pl, pn_msg->pl_len);
        }
    }
}






/*************************************************************************//**
 *
 *   read pn3030d register\n
 *	 this API replaces the original PNP API
 *
 *   \param[in]         chup address ( chould be 0x86)
 *   \param[in]         register address
 *
 *   \return            palyoad byte
 *
 ******************************************************************************/
unsigned8 SPI_ReadByte(unsigned8 chip_addr, unsigned8 reg_addr)
{
	#define READ_REGISTER_TIMEOUT	5000
	unsigned8	pl;
	if (chip_addr != 0x86 )
	{
        DEBUG_ERROR(PNP_API, "invalid chip address = 0x%02x",chip_addr);
	}

	if (false == pn3030_read_register(reg_addr, &pl, sizeof(pl), READ_REGISTER_TIMEOUT))
	{
        DEBUG_ERROR(PNP_API, "pn3030_read_register error");
	}
	return pl;
}


/*************************************************************************//**
 *
 *   read pn3030d register\n
 *	 this API replaces the original PNP API
 *
 *   \param[in]         chup address ( chould be 0x86)
 *   \param[in]         register address
 *
 *   \return            palyoad byte
 *
 ******************************************************************************/
void SPI_ReadBlock(PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 *data, int size)
{
	if (chip_addr != 0x86 )
	{
        DEBUG_ERROR(PNP_API, "invalid chip address = 0x%02x",chip_addr);
	}

	if (false == pn3030_read_register(reg_addr, data, size,READ_REGISTER_TIMEOUT))
	{
        DEBUG_ERROR(PNP_API, "pn3030_read_register error");
	}
	else
	{
        DEBUG_INFO_HI(PNP_API, "pn3030_read_register OK len = %d, %02x,%02x,%02x,...",size,data[0],data[1],data[2]);
	}
	
}


/*************************************************************************//**
 *
 *   write one byte to a pn3030d register\n
 *	 this API replaces the original PNP API
 *
 *   \param[in]         chup address ( chould be 0x86)
 *   \param[in]         register address
 *
 *   \return            palyoad byte
 *
 ******************************************************************************/
void SPI_WriteByte(unsigned8 chip_addr, unsigned8 reg_addr, unsigned8 data)
{
	if (chip_addr != 0x86 )
	{
        DEBUG_ERROR(PNP_API, "invalid chip address = 0x%02x",chip_addr);
	}
	
	if (false ==  pn3030_write_register(reg_addr, &data, 1))
	{
        DEBUG_ERROR(PNP_API, "pn3030_write_register error");
	}
}




/*************************************************************************//**
 *
 *   write a pn3030d register\n
 *	 
 *   \param[in]         register address
 *   \param[in/out]     payload buffer
 *   \param[in]     	length of payload
 *
 *   \return            true if OK
 *
 ******************************************************************************/
bool pn3030_read_register(unsigned8 addr, unsigned8 *pl, unsigned8 pl_len,unsigned16 timeout)
{
    bool 		bret=false;
	unsigned32	start;
	
    if (NULL == pl)
	{
		bret = false;
	}
	else if (0 == pl_len)
	{
		bret = false;
	}
	else
    {
        if (pl_len <= IO_MSG_DATALEN_MAX)
        {
            DEBUG_INFO_HI(VMF_TRACE_TASK_VMF, "send  CMD_READ_REQ to PN3030D");

            /* forward message to serial*/
			response_buffer_len=0;
#if 0
            serial_send_message(CMD_READ_REQ, addr, pl, pl_len);
			DEBUG_INFO_HI(VMF_TRACE_TASK_VMF,"CMD_READ_REQ vmf_pl->cmd=%d, vmf_pl->address=0x%02x, pl_len=%d",CMD_READ_REQ,addr,pl_len);
#else			
			{
				vmf_pn3030D_msg_header_t	vmf_pl;
				vmf_ret_t					vmf_ret;
				
				vmf_pl.cmd = CMD_READ_REQ;
				vmf_pl.address = addr;
				vmf_pl.pl_len = pl_len;

				DEBUG_INFO_HI(VMF_TRACE_TASK_VMF,"vmf_pl->cmd=%d, vmf_pl->address=0x%02x, pl_len=%d",vmf_pl.cmd,vmf_pl.address,pl_len);
				
				vmf_ret = vmf_send_msg(rx_group, vmf_pl.cmd, (unsigned8 *)&vmf_pl, sizeof(vmf_pl));
				if (vmf_ret < 0)
				{
					DEBUG_ERROR(VMF_TRACE_TASK_VMF, "vmf_send_msg() failed");
					return false;
				}
			}
#endif			
			start = nw_os_cfg_get_ms_time();
			while(nw_os_cfg_get_ms_time() < (start + timeout))
			{
				if ((response_buffer_len > 0) && (response_addr == addr))
				{
					/* we got a response */
					nw_os_smemcpy(pl, pl_len, response_buffer,response_buffer_len);
					bret=true;
					break;
				}
				delay(1);
//				printf(".");
			}
        }
    }
	return bret;
}


/*************************************************************************//**
 *
 *   write a pn3030d register\n
 *	 
 *   \param[in]         register address
 *   \param[in]         payload buffer
 *   \param[in]     	length of payload
 *
 *   \return            true if OK
 *
 ******************************************************************************/
bool pn3030_write_register(unsigned8 addr, unsigned8 *pl, unsigned8 pl_len)
{
    bool bret=false;
	
    if (NULL == pl)
	{
		bret = false;
	}
	else if (0 == pl_len)
	{
		bret = false;
	}
	else
    {
        if (pl_len <= IO_MSG_DATALEN_MAX)
        {
            DEBUG_INFO_HI(VMF_TRACE_TASK_VMF, "send  CMD_WRITE_REQ to PN3030D");

            /* forward message to serial*/
#if 0
            serial_send_message(CMD_WRITE_REQ, addr, pl, pl_len);
#else
			{
				unsigned8					buff[512];
				vmf_pn3030D_msg_header_t	*vmf_pl = (vmf_pn3030D_msg_header_t *)buff;
				vmf_ret_t					vmf_ret;
				
				vmf_pl->cmd = CMD_WRITE_REQ;
				vmf_pl->address = addr;
				vmf_pl->pl_len = pl_len;
				memcpy(vmf_pl->pl, pl, pl_len);
				
				DEBUG_INFO_HI(VMF_TRACE_TASK_VMF,"vmf_pl->cmd=%d, vmf_pl->address=0x%02x, pl_len=%d",vmf_pl->cmd,vmf_pl->address,pl_len);
				vmf_ret = vmf_send_msg(rx_group, vmf_pl->cmd, (unsigned8 *)vmf_pl, pl_len+sizeof(vmf_pn3030D_msg_header_t));
				if (vmf_ret < 0)
				{
					DEBUG_ERROR(VMF_TRACE_TASK_VMF, "vmf_send_msg() failed");
					return false;
				}
			}
#endif
			bret = true;
        }
    }
	return bret;
}




/*************************************************************************//**
 *
 *   replacement for Linux GetOpt() function \n
 *	 
 *   \param[in]         argc
 *   \param[in]         arg
 *
 *   \return            true if OK
 *
 ******************************************************************************/
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
                /* transmit event group Pn3030D->Host */
                tx_group = (unsigned8)atoi(optarg);
            break;

            case 'r':
                /* receive event group Host->Pn3030D */
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


/*************************************************************************//**
 *
 *  print the usage screen to the console\n
 *	 
 *
 *   \param[in]         void
 *
 *   \return            void
 *
 ******************************************************************************/
static void usage(void)
{
    printf("************************************************************************\n");
    printf("** B515 VMF Ardu GW 1.0 by J. Becker 2015                             **\n");
    printf("************************************************************************\n");
    printf("**                                                                    **\n");
    printf("** usage: b515_vmf_ardu_gw [options]                                  **\n");
    printf("**                                                                    **\n");
    printf("**     Opt.           Description                                     **\n");
    printf("**     -c <n>         COM port                                        **\n");
    printf("**     -t <n>         VMF-tx-group (Pn3030D->Host)                    **\n");
    printf("**     -r <n>         VMF-rx-group (Host->Pn3030D)                    **\n");
    printf("**     -e <n>         VMF-event (both directions)                     **\n");
    printf("**     -v             verbose                                         **\n");
    printf("**     -d             dump messages in hex                            **\n");
    printf("** Examples:                                                          **\n");
    printf("** b515_vmf_ardu_gw -c 6 -v -v -b2                                    **\n");
    printf("************************************************************************\n");
}

/*************************************************************************//**
 *
 *  print the current setup screen to the console\n
 *	 
 *
 *   \param[in]         void
 *
 *   \return            void
 *
 ******************************************************************************/
 static void current_setup(void)
 {
    printf("************************************************************************\n");
    printf("**  B515 VMF Ardu GW 1.0 by by J. Becker %s %s\n",__DATE__,__TIME__);
    printf("************************************************************************\n");
    printf("** verbosity=%d                                                         \n",verbose);
    printf("** Com-Port = COM%d                                                     \n",com_port);
    printf("** VMF-tx-group (Pn3030D->Host)= %03d                                   \n",tx_group);
    printf("** VMF-rx-group (Host->Pn3030D)= %03d                                   \n",rx_group);
    printf("** VMF-event (both directions)= %03d                                    \n",trx_event);
    if (dump)                                                   
    {
        printf("** Message dump enabled                                             \n",trx_event);
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




/*************************************************************************//**
 *
 *  debug function: print the COM DCB struct\n
 *	 
 *
 *   \param[in]         dcb
 *
 *   \return            void
 *
 ******************************************************************************/
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


