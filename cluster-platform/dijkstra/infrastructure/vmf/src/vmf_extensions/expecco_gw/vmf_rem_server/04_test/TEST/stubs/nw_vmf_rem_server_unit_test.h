#ifndef __VMF_REM_SERVER_UNIT_TEST_H__
#define __VMF_REM_SERVER_UNIT_TEST_H__

#include <hwut_unit.h>
#include <string.h>
#include "os_types.h"
#include "pthread.h"
#include "nw_config.h"
#include "nw_vmf_rem.h"

#ifdef PREVENT_MEMORY_CRASH
#undef PREVENT_MEMORY_CRASH
#endif

#define sleep(time_milliseconds)
#define clock_gettime(type,tm)      0
#define getpid()                    (int)1

struct in_addr {
    unsigned long s_addr;
};


struct sockaddr_in {
        short   sin_family;
        unsigned short sin_port;
        struct  in_addr sin_addr;
        char    sin_zero[8];
};

#define UNIT_TEST_LIMITER printf("\n********************************************************************************************************\n");
#define UNIT_TEST_INFO_PRINT(...)  		    {printf("UT: "); printf(__VA_ARGS__);}
#define UNIT_TEST_ERROR_PRINT(...)  	    {printf("UT: "); printf(__VA_ARGS__);}
#if 0
#define UNIT_TEST_INFO_PRINT(...)  		    {printf("\n t = %d ms, ",(int)nw_timer_u32_get_global_time());printf(__VA_ARGS__);}
#define UNIT_TEST_ERROR_PRINT(...)  	    {printf("\n t = %d ms, ",(int)nw_timer_u32_get_global_time());printf(__VA_ARGS__);}
#endif
#define UNIT_TEST_DATA_PRINT(size, ptr_data)    {                                           \
                                                    unsigned16 i;                           \
                                                    if(ptr_data != (void*)0)                \
                                                    {                                       \
                                                        printf("UT: ");                     \
                                                        for(i = 0; i < (size); i++)         \
                                                        {                                   \
                                                            printf("%02x.",(ptr_data)[i]);  \
                                                        }                                   \
                                                    }                                       \
                                                }

#define SYSPAGE_ENTRY
#define MAKEWORD(a,b)       (1)
#define WSACleanup(...)
#define WSAGetLastError()   (errno)
#define SOCKADDR_IN         struct sockaddr_in
#define SOCKADDR            struct sockaddr
#define SOCKET              int
#define SOCKET_ERROR        (-1)
#define INVALID_SOCKET      (-1)
#define closesocket(s) 		(close(s))
#define htonl(a)            (1)
#define htons(a)            (1)
#define bind(a,b,c)         (1)
#define AF_INET             (1)
#define SOCK_STREAM         (1)
#define IPPROTO_TCP         (1)
#define _TCHAR              char
#define signal(a,b)

#define WAIT_4_SOCKET   (2)
#define WAIT_MORE_4_SOCKET  (5) 

#define VMF_TRACE_PRINT(...)
#define VMF_TRACE_PRINTF(...)


typedef struct WSAData {
  unsigned short     wVersion;
  unsigned short     wHighVersion;
  char           szDescription[2];
  char           szSystemStatus[2];
  unsigned short iMaxSockets;
  unsigned short iMaxUdpDg;
  char          *lpVendorInfo;
}WSADATA, *LPWSADATA;


int recv(int s,char *buf,int len,int flags);
void set_result_recv(int);
unsigned64 ClockCycles(void);
unsigned int delay( unsigned int duration );

extern vmf_error_t vmf_rem_get_rpc_rep_msg_len(unsigned16 *p_msglen, vmf_rpc_response_t *p_resp_msg);

extern bool test_util_get_rpc_msg_len(void);
extern bool test_util_get_vmf_msg_len(void);
extern bool test_vmf_client_rpc_decoder(void);
extern bool test_vmf_client_con_init(void);
extern bool test_vmf_create_rem_vmf_thread(void);
extern bool test_vmf_client_rpc_handler(void);
extern bool test_vmf_client_rpc_handler(void);
extern bool test_vmf_client_con_accept_sock(void);
extern bool test_vmf_client_rpc_receiver(void);
extern bool test_rpc_mutex_init(void);
extern bool test_rpc_create_and_bind_server_socket(void);
extern bool test_vmf_create_rx_thread(void);
extern bool test_vmf_rem_get_time_in_ms(void);
extern bool test_vmf_client_rpc_decoder_disconnect(void);
extern bool test_vmf_client_rpc_decoder_timed_receive(void);
extern bool test_vmf_client_rpc_decoder_receive(void);

extern vmf_error_t rpc_mutex_init(pthread_mutex_t *pMutex);
extern vmf_error_t rpc_create_and_bind_server_socket(SOCKET *rpc_srv_socket);
extern vmf_error_t vmf_client_con_listen_sock(SOCKET sock);
extern vmf_error_t vmf_client_con_accept_sock(SOCKET *p_connectedSocket);
extern void *vmf_client_rpc_receiver(SOCKET *rpc_socket);
extern int recv_wait(SOCKET s,char  * buf,int len,int flags);
extern vmf_ret_t nw_vmf_create_rx_thread  (SOCKET *p_sock);
extern void vmf_client_rpc_block_receive(SOCKET *rpc_socket,vmf_rpc_msg_t   *prpc_buffer);

extern vmf_error_t vmf_client_rpc_decoder_connect(vmf_rpc_msg_t *p_rpc_msg);
extern vmf_error_t vmf_client_rpc_decoder_reg_msg_grp(vmf_rpc_msg_t *p_rpc_msg);
extern vmf_error_t vmf_client_rpc_decoder_de_reg_msg_grp(vmf_rpc_msg_t *p_rpc_msg);
extern vmf_error_t vmf_client_rpc_decoder_reg_ext_most_link(vmf_rpc_msg_t *p_rpc_msg);
extern vmf_error_t vmf_client_rpc_decoder_reg_spy(vmf_rpc_msg_t *p_rpc_msg);
extern vmf_error_t vmf_client_rpc_decoder_reg_most_fblock(vmf_rpc_msg_t *p_rpc_msg);
extern vmf_error_t vmf_client_rpc_decoder_de_reg_most_fblock(vmf_rpc_msg_t *p_rpc_msg);
extern vmf_error_t vmf_client_rpc_decoder_reg_most_shadow(vmf_rpc_msg_t *p_rpc_msg);
extern vmf_error_t vmf_client_rpc_decoder_de_reg_most_shadow(vmf_rpc_msg_t *p_rpc_msg);
extern vmf_error_t vmf_client_rpc_decoder_send_most_async(vmf_rpc_msg_t *p_rpc_msg);
extern vmf_error_t vmf_client_rpc_decoder_send_most_ctrl(vmf_rpc_msg_t *p_rpc_msg);
extern vmf_error_t vmf_client_rpc_decoder_send_basic(vmf_rpc_msg_t *p_rpc_msg);
extern vmf_error_t vmf_client_rpc_decoder_send(vmf_rpc_msg_t *p_rpc_msg);
extern vmf_error_t vmf_client_rpc_decoder_receive(vmf_rpc_msg_t *p_rpc_msg,vmf_rpc_response_t *p_response);
extern vmf_error_t vmf_client_rpc_decoder_disconnect(vmf_rpc_msg_t *p_rpc_msg);
extern vmf_error_t vmf_client_rpc_decoder_timed_receive(vmf_rpc_msg_t *p_rpc_msg,vmf_rpc_response_t *p_response,unsigned16 timeout);

extern int WSAStartup(int, int *);
extern void set_wsastartupresult(int);
extern int listen(int, int);
extern void set_result_listen(int);
extern SOCKET accept(SOCKET, int *, int *);
extern void set_accept_result(SOCKET param);
extern void set_send_result(SOCKET param);
extern SOCKET send( SOCKET my_sock, char * p_rpc_response, unsigned16 tx_buffer_len, int num );
extern void set_socket(SOCKET param);
extern SOCKET socket(int, int, int);


extern void set_pthread_mutex_lock(signed16 param);
extern void set_pthread_mutex_unlock(signed16 param);
extern void set_pthread_attr_init(int param);
extern void set_pthread_attr_setdetachstate(int param);
extern void set_pthread_create(int param);
extern void set_pthread_attr_destroy(int param);
extern void set_pthread_attr_setstacklazy(int param);
extern void set_pthread_mutexattr_init(int param);
extern void set_pthread_mutexattr_settype(int param);
extern void set_pthread_mutexattr_destroy(int param);
extern void set_pthread_mutex_init(int param);
extern void set_pthread_attr_setstacksize(int param);

extern void set_nw_vmf_disconnect( vmf_ret_t param);
extern void set_nw_vmf_timed_receive_result(signed16 param);
extern void set_nw_vmf_receive_result(signed16 param);
extern void set_nw_vmf_send_result(vmf_ret_t param);
extern void set_nw_vmf_send_basic(vmf_ret_t param);
extern void set_nw_vmf_send_most_ctrl_result(vmf_ret_t param);
extern void set_nw_vmf_send_most_async_result(vmf_ret_t param);
extern void set_nw_vmf_register_most_shadow(vmf_ret_t param);
extern void set_nw_vmf_register_most_fblock_result(vmf_ret_t param);
extern void set_nw_vmf_de_register_most_shadow_result(vmf_ret_t  param);
extern void set_nw_vmf_de_register_most_fblock_result(vmf_ret_t param);
extern void set_nw_vmf_register_spy_result(vmf_ret_t param);
extern void set_nw_vmf_register_ext_most_link_result(vmf_ret_t param);
extern void set_nw_vmf_de_register_msg_group_result(vmf_ret_t param);
extern void set_nw_vmf_connect_result(vmf_client_id_t param);
extern void set_nw_vmf_register_msg_group(vmf_ret_t param);            

#endif /* __VMF_REM_SERVER_UNIT_TEST_H__ */

