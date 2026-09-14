#ifndef B515_VMF_ARDU_GW_H
#define B515_VMF_ARDU_GW_H


#ifndef bool
#define bool    BOOL
#endif

typedef struct
{
    unsigned8   cmd;        	/* command */
    unsigned8   address;     	/* address register */
    unsigned8   pl_len;			/* payload len */
    unsigned8   pl[0];			/* payload */
}vmf_pn3030D_msg_header_t;


enum 
{
    CMD_INVALID         = 0,
    CMD_WRITE_REQ 	    = 1,
    CMD_READ_REQ        = 2,
    CMD_READ_RESPONSE	= 3,
    CMD_RESET           = 4,
    CMD_RESET_ASSERT	= 5,
    CMD_RESET_RELEASE	= 6,
	CMD_RETRANSMIT		= 7
};

bool 		pn3030_read_register(unsigned8 addr, unsigned8 *pl, unsigned8 pl_len,unsigned16 timeout);
bool 		pn3030_write_register(unsigned8 addr, unsigned8 *pl, unsigned8 pl_len);

vmf_ret_t 	vmf_send_msg(unsigned8 group, unsigned8 event, unsigned8 *data, unsigned16 len);

vmf_ret_t 	vmf_send_msg2pn(unsigned8 *data, unsigned16 len);
vmf_ret_t 	vmf_send_cmd2pn(unsigned8 cmd);


#endif

