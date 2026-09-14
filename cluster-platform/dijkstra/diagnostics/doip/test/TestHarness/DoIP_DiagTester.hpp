/*
 * DoIP_DiagTester.hpp
 *
 *  Created on: Feb 7, 2020
 *      Author: RKRISHN8
 */

#ifndef DOIP_DIAGTESTER_HPP_
#define DOIP_DIAGTESTER_HPP_

#include<stdint.h>
#include<memory>
#include<vector>
#include<iostream>
#include <pthread.h>
#include <semaphore.h>



#include<netinet/ip_icmp.h>   //Provides declarations for icmp header
#include<netinet/udp.h>   //Provides declarations for udp header
#include<netinet/tcp.h>   //Provides declarations for tcp header
#include<netinet/ip.h>    //Provides declarations for ip header
#include<sys/socket.h>
#include<arpa/inet.h>

#define INFINITE 99
using namespace std;
typedef struct
{
	uint16_t eculogicalAddress;
	uint16_t ToolAddress;
	uint16_t ecuTargetPortNum;
    //char toolPhyInterface[10];
	//std::string toolPhyInterface;
}SDoipTestParam;

void print_packet(unsigned char*, int);
void PrintData (unsigned char* , int);
class CDoipTester
{

	public:

	CDoipTester(SDoipTestParam &lDoipTestParam) : mDoipTestParam(lDoipTestParam)
	{
		eDoIPtesterState = UDP_Socket_Init;
	    sem_init(&mSemUdpReceivethreadTask, 0, 1);
	    sem_init(&mSemTcpReceivethreadTask, 0, 1);
        pthread_mutex_init(&mu,NULL);
        pthread_cond_init(&oe,NULL);
	}

	~CDoipTester()
	{

	}

	typedef enum
	{
		UDP_Socket_Init = 0,
		UDP_Socket_Completed,
		Vin_Reponse_Received,
		TCP_Socket_Init,
		TCP_Socket_Completed,
		Routing_Activation_Init,
		Routing_Activation_Completed,
		Doip_Tester_Ready,
        Doip_Tester_Response,
		TCP_UDP_Socket_Close,
	}EDoipTesterState_t;

    typedef enum
	{
		UDS_DiagnosticSession_Default = 0,
		UDS_DiagnosticSession_Reprogramming,
		UDS_TesterPresence,
		UDS_SeedKeyReq,
		UDS_RoutineControl,
		UDS_TransferData,
	    UDS_TransferLargerData,
	    UDS_ECUReset,
        UDS_ReadDataByIdentifier,
        DOIP_CloseSocket,
        DOIP_OpenSocket,
        DOIP_PollforNewSocket,
        UDS_Last,
        UDS_DiagnosticSession_Extendded,
        UDS_MinLenghtCheck,
        UDS_DataTransfer
	}EUdsRequests;



	typedef enum
	{
		RequestDownload = 0,
		FileTransferRequest =1 ,
		TransferData =2 ,
		TransferExitRequest,
		DefaultState,
	}EStateMachine_t;

	enum EUdsDownload_t
	{
		ERequestDownLoadReq = 0x0000U,
		EFileTransferReq = 0x0001U,
		ERequestTransferDataReq =0x0002u,
		ERequestTransferExitReq = 0x0003U,
		EDiagSessionCntrlReq=0x0004U,
		ERequest_Last,
	};

typedef uint16_t EUdsResponse_t;
#define EDiagSessionCntrlResponse ((EUdsResponse_t) 0x50U)
#define EDiagSeedKeyReponse ((EUdsResponse_t) 0x67U)
#define ERoutineCntrlResponse ((EUdsResponse_t) 0x71U)
#define ERequestDownLoadResponse ((EUdsResponse_t) 0x74U)
#define ETransferDataResponse ((EUdsResponse_t) 0x76U)
#define ETesterPresResponse ((EUdsResponse_t) 0x7EU)
#define ERequestTransferExitResponse ((EUdsResponse_t) 0X77U)
#define ERequestFileTransferResponse ((EUdsResponse_t)0x78u)
#define ECUResetResponse ((EUdsResponse_t)0x51u)
#define ENegativeResponse ((EUdsResponse_t)0x7Fu)

typedef uint8_t EUdsSession_t;
#define EdefaultSession  ((EUdsSession_t)0X1)
#define EprogrammingSession   ((EUdsSession_t)0X02)
#define EextendedDiagnosticSession  ((EUdsSession_t)0X3)
#define EsafetySystemDiagnosticSession  ((EUdsSession_t)0X4)

typedef uint8_t ESeedKeyRequests_t;
#define ErequestSeed	  ((ESeedKeyRequests_t)0X1)
#define EsendKey  ((ESeedKeyRequests_t)0X2)
#define ESeedKeyRequests_Last  ((ESeedKeyRequests_t)0X3)
#define ESendKey_Last  ((ESeedKeyRequests_t)0X4)



typedef uint8_t ERoutineCntrlType_t;
#define EstartRoutine	  ((ERoutineCntrlType_t)0X1)
#define EstopRoutine  ((ERoutineCntrlType_t)0X2)
#define ErequestRoutineResults  ((ERoutineCntrlType_t)0X3)

	/// @breif DoIP Payload Types
	enum EPayloadType_t
	{
		EPayloadType_GenericHeaderNegativeAck           = 0x0000U,  ///< DOIP Header Negative acknowledgment message type
		EPayloadType_VehicleIdRequestMessage            = 0x0001U,	///< DOIP Vehicle Identifier Request message type
		EPayloadType_VehicleIdRequestEid       		 			= 0x0002U,	///< DOIP Vehicle Identifier Request with EID message type
		EPayloadType_VehicleIdRequestVin       		 			= 0x0003U,	///< DOIP Vehicle Identifier Request with VIN message type
		EPayloadType_VehicleAnnouncementOrResponse      = 0x0004U,	///< DOIP Vehicle Announcement Response message type
		EPayloadType_RoutingActivaionRequest            = 0x0005U,	///< DOIP Routing Activation Request message type
		EPayloadType_RoutingActivationResponse          = 0x0006U,	///< DOIP Routing Activation Response message type
		EPayloadType_AliveCheckRequest                  = 0x0007U,	///< DOIP Alive Check Request message type
		EPayloadType_AliveCheckResponse                 = 0x0008U,	///< DOIP Alive Check Response message type
		/* 0x0009 to 0x4000 is reserved by ISO 13400-2 */
		EPayloadType_ReservedSection1Start              = 0x0009U,	///< RESERVED FOR ISO 13400
		EPayloadType_ReservedSection1End                = 0x4000U,	///< RESERVED FOR ISO 13400
		EPayloadType_EntityStatusRequest                = 0x4001U,	///< DOIP Entity Status Request message type
		EPayloadType_EntityStatusResponse               = 0x4002U,	///< DOIP Entity Status Response message type
		EPayloadType_DiagPowerModeInfoRequest           = 0x4003U,	///< DOIP Power mode information Request message type
		EPayloadType_DiagPowerModeInfoResponse          = 0x4004U,	///< DOIP Power mode information Response message type
		/* 0x4005 to 0x8000 is reserved by ISO 13400-2 */
		EPayloadType_ReservedSection2Start              = 0x4005U,	///< RESERVED FOR ISO 13400
		EPayloadType_ReservedSection2End                = 0x8000U,	///< RESERVED FOR ISO 13400
		EPayloadType_DiagnosticMessage                  = 0x8001U,	///< DOIP Diagnostic message type
		EPayloadType_DiagnosticMessagePositiveAck       = 0x8002U,	///< DOIP  Diagnostic Positive acknowledgment message type
		EPayloadType_DiagnosticMessageNegativeAck       = 0x8003U,	///< DOIP Diagnostic Negative acknowledgment message type
		/* 0x8004 to 0xEFFF is reserved by ISO 13400-2 */
		EPayloadType_ReservedSection3Start              = 0x8004U,	///< RESERVED FOR ISO 13400
		EPayloadType_ReservedSection3End                = 0xEFFFU,	///< RESERVED FOR ISO 13400
		/* 0xF000 to 0xFFFF is reserved by ISO 13400-2 for Manufcaturing Purpose */
		EPayloadType_ReservedManufacturePurposeStart    = 0xF000U,	///< RESERVED FOR MANUFACTURER PURPOSE
		EPayloadType_ReservedManufacturePurposeEnd      = 0xFFFFU,	///< RESERVED FOR MANUFACTURER PURPOSE
		EPayloadType_Last
	};

	int8_t DoipTester_InitUdpSockets(void);
	int8_t DoipTester_InitTcpSockets(void);
	int8_t DoipTester_InitiateTasks(void);
	int8_t DoipTester_SendVinRequest(std::vector<uint8_t> &vehicleInfoMsg);
    int8_t DoipTester_SendEidRequest(std::vector<uint8_t> &vehicleInfoMsg);
    int8_t DoipTester_SendGidRequest(std::vector<uint8_t> &vehicleInfoMsg);
	int8_t DoipTester_SendRoutingActivationRequest(std::vector<uint8_t> &lMsg);
	//int8_t DoipTester_SendAliveCheckResponse(SDoipTestParam &lDoipTestParam);
	int8_t DoipTester_SendAliveCheckResponse(std::vector<uint8_t> &lMsg);
	int8_t DoipTester_SendDiagPowerModeRequest(void);
	int8_t DoipTester_SendDiagMessageInfo(std::vector<uint8_t> &lMsg);
	int8_t DoipTester_SendDiagMessageStatus(SDoipTestParam &lDoipTestParam);
	int8_t DoipTester_ProcessData(sockaddr_in &servaddr, std::vector<uint8_t> &lMsg);
	uint32_t DoipTester_getPayloadLength( std::vector<uint8_t> &buffer);
	uint16_t DoipTester_getPayloadType( std::vector<uint8_t> &buffer);

	int8_t ProcessTxDiagMessage(std::vector<uint8_t> &lMsg, EUdsDownload_t eUdsType);
	int8_t  ProcessTxDiagSessionCntrlMsgs(std::vector<uint8_t> &lMsg, EUdsSession_t eUdsSession);
	int8_t ProcessTxDiagTesterPresence(std::vector<uint8_t> &lMsg );
	int8_t ProcessSeedKeyMsgs(std::vector<uint8_t> &lMsg,ESeedKeyRequests_t lReqType ,std::vector<uint8_t> lKeyValues);
	int8_t ProcessTxRoutineCntrlMsgs(std::vector<uint8_t> &lMsg, ERoutineCntrlType_t lRoutineCtrl,uint16_t routineIdentifier);
    int8_t ProcessTxEcuResetMsgs(std::vector<uint8_t> &lMsg );
    int8_t ProcessTxEcuResetMsgs_DataTransfer(std::vector<uint8_t> &lMsg );
    int8_t ProcessTxReadDataByIdentifier(std::vector<uint8_t> &lMsg );
	int8_t ProcessTxDiagTransferMsgs(std::vector<uint8_t> &lMsg, EUdsDownload_t eUdsType);
	int8_t ProcessRxDiagMessage(std::vector<uint8_t> &lMsg );
	int8_t genDoipHeader(std::vector<uint8_t> &lMsg,uint32_t len,EPayloadType_t doipMsgType);
    int8_t DiagMessage_ReqTransfer(std::vector<uint8_t> &lMsg,uint8_t uMinMax);
    int8_t DoipTester_ConnectTcpSockets(void);
    int8_t doipHeaderBuild(std::vector<uint8_t> &vehicleInfoMsg,uint32_t Length,uint16_t msg_type);

 
    uint8_t sessionThreadVar=0x00U;

    std::vector<uint8_t> lkeyMsg;

	void UdpReceiveThread(void);
	void TcpReceiveThread(void);
	void DoIPTaskThread(void);

    void DoIPStateMachine(int);
	void DoIPCmdLineInpts(void);
    void SessionControlThread(void); 

	static std::shared_ptr<CDoipTester> mInstance;
	std::thread *mpUdpReceivethreadTask;			///< Udp Receive Task Thread
	std::thread *mpTcpReceivethreadTask;			///< TCP Receive Task Thread
	std::thread *mpDoipTesterTask;		         	///< Shall be a periodic task

    std::thread *mpSessionControl;

	std::thread *mpDoipStateMachine;                ///< Shall be a periodic task
	std::thread *mpCommandlineInputs;               ///< Shall be a periodic task
	char doipCmdLine;
	EUdsRequests mUdsRequests;
	EStateMachine_t mUdsStateMachine;


	sockaddr_in mClientServeraddr;
	sem_t mSemUdpReceivethreadTask;
	sem_t mSemTcpReceivethreadTask;
    pthread_mutex_t mu;
    pthread_cond_t oe;
	SDoipTestParam mDoipTestParam;

	uint8_t mUdsTransferDataInProgress;
	uint8_t mRequestDownloadCompleted;
	uint8_t mtransferDataCompleted;
	uint16_t mBlockSeqCntr = 0x0;
	//const uint16_t totalBlockSeqCnt = 4096 ;
	const uint16_t totalBlockSeqCnt = 200 ;
    uint8_t did_1,did_2;
    uint8_t uActivationType;

	uint32_t lMaxBlockLengthNum = 0x0;
	uint32_t temp=(int)0;
	//uint32_t data_size=380936;
	uint32_t data_size=571392; //62kx9
	//uint32_t a=0x00;
	//int n;


	int mudpSocketFd = -1;
	int mtcpSocketFd = -1;
	EDoipTesterState_t eDoIPtesterState;
	EPayloadType_t ePayloadType;

	bool mRoutingActivationCompleted = false;
	bool mReqInProgress = false;
	bool mRoutineIdentifierInProgress = false;
	ESeedKeyRequests_t mseedKeygen;
   int mtcpconnSocketfd;
   bool isTesterPresenceLogs=false;
   bool isSecuritySeedRecv=false;

};


#endif /* DOIP_DIAGTESTER_HPP_ */
