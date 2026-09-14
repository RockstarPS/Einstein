
#ifndef _MY_TYPES_H_
#define _MY_TYPES_H_

/* typedefs */
typedef long long			signed64;
typedef unsigned long long  unsigned64;
typedef int					signed32;
typedef unsigned int		unsigned32;
typedef short				signed16;
typedef unsigned short		unsigned16;
typedef signed char			signed8;
typedef unsigned char		unsigned8;

typedef signed32	mqd_t;

#ifndef __cplusplus
	#ifndef _BOOLEAN
	 typedef short	 	bool;
	#endif
#endif
typedef int 		pid_t;
typedef unsigned32 MoccaClientHandle_t;

typedef unsigned8	ui1;
typedef unsigned8	ui8;
typedef unsigned16	ui16;
typedef unsigned32	ui32;

pid_t getpid(void);


#define MOST_DEVICE_ID_VOID					(0xFFFF)
#define MOCCACLIENT_EVENT_NEARDATA_SIZE 	(4)
#define MOCCACLIENT_DEVTYPE_LOCAL_FB		(1)	///< GW local MOST function block registration tag.
#define MOCCACLIENT_DEVTYPE_LOCAL_MOD		(4)	///< GW local model registration tag.
#define MOCCACLIENT_EVENT_NEARDATA_SIZE 	(4)

#ifndef NULL
#define NULL	0
#endif


// Simplified Event Message header.
// This type can be used with MoccaClient
typedef struct MoccaClientEvent_tag
{	ui8			m_ucEventID;				// event- id.
	ui8			m_ucReferenceID;			// Deprecated. Set to zero.
	ui8			m_ucNearData[MOCCACLIENT_EVENT_NEARDATA_SIZE]; // near data for fast, short messages.
} MoccaClientEvent_t;

// Simplified Most Message header.
// This type can be used with MoccaClientMostMessageSend(), OnMostMessage() callback API.
typedef struct MoccaClientMostMessageHeader_tag
{	ui16		m_wMostDeviceID;		// SEND:  RECEIVE: Source device ID
	ui8			m_ucFBlockID;			// FBlock id, part of MOST address system.
	ui8			m_ucInstID;				// Instance id, part of MOST address system.
	ui16		m_wFunctionID;			// Function id, part of MOST address system.
	ui8			m_ucOpType;				// OpType - MOST command type for function and property objects.
} MoccaClientMostMessageHeader_t;


// Type of callback function, invoked upon dispatching of a most message.
typedef void (*pfnOnMostMessage)( void *pvUserContext, const MoccaClientMostMessageHeader_t *cpMostMessageHeader, const ui8 *pucData, ui32 dwDataSize );
// Type of callback function, invoked upon dispatching of an event message.
typedef void (*pfnOnEvent)( void *pvUserContext, ui8 ucChannel, const MoccaClientEvent_t *cpEvent, const ui8 *pucExtraData, ui32 dwExtraDataSize );


typedef struct IMoccaClientSink_tag
{	pfnOnMostMessage	OnMostMessage;		// Pointer to function, to be called, if there is a new most message.
	pfnOnEvent			OnEvent;			// Pointer to function, to be called, if there is a new event message.
} IMoccaClientSink;

#ifndef true
#define true 	(1)
#endif

#ifndef false
#define false 	(0)
#endif


#define GW_TRUE true
#define GW_FALSE false


/* syslog */
#define	LOG_KERN	(0<<3)	/* kernel messages */
#define	LOG_USER	(1<<3)	/* random user-level messages */
#define	LOG_MAIL	(2<<3)	/* mail system */
//#define	LOG_DAEMON	(3<<3)	/* system daemons */
#define	LOG_AUTH	(4<<3)	/* security/authorization messages */
#define	LOG_SYSLOG	(5<<3)	/* messages generated internally by syslogd */
#define	LOG_LPR		(6<<3)	/* line printer subsystem */
#define	LOG_NEWS	(7<<3)	/* network news subsystem */
#define	LOG_UUCP	(8<<3)	/* UUCP subsystem */
#define	LOG_CRON	(9<<3)	/* clock daemon */
#define	LOG_AUTHPRIV	(10<<3)	/* security/authorization messages (private) */
#define	LOG_FTP		(11<<3)	/* ftp daemon */

#define	LOG_EMERG	0	/* system is unusable */
#define	LOG_ALERT	1	/* action must be taken immediately */
#define	LOG_CRIT	2	/* critical conditions */
#define	LOG_ERR		3	/* error conditions */
#define	LOG_WARNING	4	/* warning conditions */
#define	LOG_NOTICE	5	/* normal but significant condition */
#define	LOG_INFO	6	/* informational */
#define	LOG_DEBUG	7	/* debug-level messages */


#define snprintf vsnprintf

#define UI16_HIGH_BYTE(p)	   ((ui8)((ui16)(p) >> 8) & 0x00FF)
#define UI16_LOW_BYTE(p)	   ((ui8)((ui16)(p) & 0x00FF))


#ifdef WIN32
#define delay(ms) {\
struct timespec delay;\
	delay.tv_sec  = (ms/1000);\
	delay.tv_nsec = (ms%1000);\
	pthread_delay_np(&delay);\
	}
#endif

#endif

