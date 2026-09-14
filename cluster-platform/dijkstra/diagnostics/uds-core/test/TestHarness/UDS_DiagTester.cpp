/*
 * DoIP_DiagTester.cpp
 *
 *  Created on: Feb 7, 2020
 *      Author: RKRISHN8
 */



#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <chrono>
#include <csignal>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include<pthread.h>
#include <chrono>
#include <csignal>
#include <thread>
#include <iostream>
#include <stdint.h>
#include"DoIP_DiagTester.hpp"
#include <cmath>
#include <cerrno>
#include <cstring>
#include <sys/select.h>
#include <clocale>


using namespace std;
uint16_t ToolAddress;
uint16_t ecuIPV4Address;
uint16_t ecuTargetPortNum;
string ToolPhyInterface;

/*DOIP COMMANDS*/
#define VEH_ID_REQ_MSG 1U
#define VEH_ID_REQ_EID 2U
#define VEH_ID_REQ_VIN 3U
#define DIAGNOSTIC_MSG 5U
#define ROUTING_ACTIVATION 5u

#define DOIP_PROTOCOL_VERSION                 2U
#define DOIP_PROTOCOL_INVERSE_VERSION         253U
#define MAXLINE 5000

//#define DOIP_STACK_SIZE 65535
//#define DOIP_STACK_SIZE 387072
#define DOIP_STACK_SIZE 571392  //62kx9 
//#define TRANSFER_BUFFER_SIZE 63488
//#define TRANSFER_BUFFER_SIZE 126976
//#define TRANSFER_BUFFER_SIZE 190464
#define TRANSFER_BUFFER_SIZE 571392 //62kx9

/**SDoipTestParam gSDoipTestParam = {
		                           .eculogicalAddress =0x006F,
								   .ToolAddress = 0xE001,
								   .ecuTargetPortNum=13400,
								   .toolPhyInterface =("lo"),
                                  };*/
SDoipTestParam gSDoipTestParam;
shared_ptr<CDoipTester> CDoipTester::mInstance = NULL;

//uint8_t buffer_len[387072];
uint8_t buffer_len[571392]; //62kx9
static uint8_t gSampleBuffer[DOIP_STACK_SIZE];
static uint8_t gTestBuffer[TRANSFER_BUFFER_SIZE];
void handle_sigint(int sig);
volatile bool isSessionControlflag=false;
volatile bool threadFlag=true;

int main()
{

    cout<<"\nEnter target physical logical address:"<<endl;
    cout<<"#it is the DoIPTargetAddressPhysical \n#configured in uds.ini at the server \n#Ex: 006F"<<endl;
    cin>>hex>>gSDoipTestParam.eculogicalAddress;
    cout<<hex<<gSDoipTestParam.eculogicalAddress<<endl;

    cout<<"\nEnter source address:"<<endl;
    cout<<"#it is one of the known DoIPSourceAddress_0...N \n#configured in uds.ini at the server \n#Ex: E000"<<endl;
    cin>>hex>>gSDoipTestParam.ToolAddress;
    cout<<hex<<gSDoipTestParam.ToolAddress<<endl;

    gSDoipTestParam.ecuTargetPortNum=13400;
    CDoipTester::mInstance = make_shared<CDoipTester>(gSDoipTestParam);
	int8_t Ret;

	// Create Instance

	// Create threads
	Ret = CDoipTester::mInstance->DoipTester_InitiateTasks();
    CDoipTester::mInstance->mUdsRequests = CDoipTester::EUdsRequests::UDS_Last;
	if(Ret >= 0 )
	{
      cout<< "Doip Tester Instance creation : Success" << endl;

	}

	else
	{
		cout<< "Doip Tester Instance creation : failed" << endl;
	}
    while(threadFlag);

    CDoipTester::mInstance->mpCommandlineInputs->detach();
    CDoipTester::mInstance->mpTcpReceivethreadTask->detach();
    CDoipTester::mInstance->mpDoipTesterTask->detach();
    if(isSessionControlflag==true)
    CDoipTester::mInstance->mpSessionControl->detach();
    CDoipTester::mInstance->mpUdpReceivethreadTask->detach();
    cout<<"Exiting Test App"<<endl;

    return 0;
}


int8_t CDoipTester::DoipTester_InitiateTasks()
{


	mpUdpReceivethreadTask = new std::thread([this]() { this->UdpReceiveThread(); });
	mpDoipTesterTask = new std::thread([this]() { this->DoIPTaskThread(); });
    //mpUdpReceivethreadTask = new std::thread([this]() { this->UdpReceiveThread(); });
	return 0;
}


int8_t CDoipTester::doipHeaderBuild(std::vector<uint8_t> &vehicleInfoMsg,uint32_t Length, uint16_t msg_type)
{
    vehicleInfoMsg.push_back(DOIP_PROTOCOL_VERSION);
    vehicleInfoMsg.push_back(253);
    vehicleInfoMsg.push_back(static_cast<uint8_t>(msg_type >> 8u));
    vehicleInfoMsg.push_back(static_cast<uint8_t>(msg_type));
    vehicleInfoMsg.push_back(static_cast<uint8_t>((Length >> 24) & 0xFF));
    vehicleInfoMsg.push_back(static_cast<uint8_t>((Length >> 16) & 0xFF));
    vehicleInfoMsg.push_back(static_cast<uint8_t>((Length >> 8) & 0xFF));
    vehicleInfoMsg.push_back(static_cast<uint8_t>(Length & 0xFF));

return 0;
}
void CDoipTester::DoIPTaskThread()
{
	int8_t ret;
    struct sockaddr_in servaddr;
    EPayloadType_t lPayloadType_t;
    uint16_t msg_type;
    uint32_t Length;
    int udpTxStatus;
   std::vector<uint8_t> lDoIPMsg;
   std::vector<uint8_t> vehicleInfoMsg;
    int whileLoopFlag=true;

	while(whileLoopFlag)
	{
		switch(eDoIPtesterState)
		{

		case UDP_Socket_Init:
		{
			ret= DoipTester_InitUdpSockets();
			if( ret ==  0 )
			{
				cout<< "UDP_Socket_Init Success : migrating to next state >> UDP_Socket_Completed  " << endl;
				eDoIPtesterState = UDP_Socket_Completed;

			}

			break;
		}
		case UDP_Socket_Completed:
		{
            uint8_t idReq=0;
            cout<<"\nEnter below to choose vehicle identification request message type:\n1 for vehicle identification request message\n2 for vehicle identification request message with VIN\n3 for vehicle identification request message with EID"<<endl;
            cin>>idReq;
            //scanf("%u",&idReq);
            cout<<"idReq"<<idReq<<endl;
            switch(idReq)
            {
                case '1':
                    vehicleInfoMsg.clear();
                    lPayloadType_t =EPayloadType_VehicleIdRequestMessage;
                    msg_type =  static_cast<uint16_t> (lPayloadType_t);
                    Length = 0; // No payload required apart from DOIP header
                    doipHeaderBuild(vehicleInfoMsg,Length,msg_type);
                break;
                case '2':
                    vehicleInfoMsg.clear();
                    lPayloadType_t =EPayloadType_VehicleIdRequestVin;
                    msg_type =  static_cast<uint16_t> (lPayloadType_t);
                    Length = 17; //payload required apart from DOIP header
                    doipHeaderBuild(vehicleInfoMsg,Length,msg_type);
                    ret = DoipTester_SendVinRequest(vehicleInfoMsg);
                    break;
                case '3':
                    vehicleInfoMsg.clear();
                    lPayloadType_t =EPayloadType_VehicleIdRequestEid;
                    msg_type =  static_cast<uint16_t> (lPayloadType_t);
                    Length = 6; //payload required apart from DOIP header
                    doipHeaderBuild(vehicleInfoMsg,Length,msg_type);
                    ret = DoipTester_SendEidRequest(vehicleInfoMsg);
                    break;
                default:
                    vehicleInfoMsg.clear();
                    cout<<"Invalid Input"<<endl;

            }
		     memset(&servaddr, 0, sizeof(servaddr));

			// Filling server information
			servaddr.sin_family = AF_INET;
			servaddr.sin_port = htons(mDoipTestParam.ecuTargetPortNum);
			servaddr.sin_addr.s_addr = INADDR_BROADCAST;
            // send UDP message
            udpTxStatus = sendto(mudpSocketFd, vehicleInfoMsg.data(), vehicleInfoMsg.size() ,  MSG_DONTWAIT , (const struct sockaddr *) &servaddr, sizeof(servaddr));
            printf("\n");
			printf("\nSIZE OF UDP SENT DATA FROM CLIENT =%d\n",(uint32_t)udpTxStatus);
            for(uint8_t i=0;i<vehicleInfoMsg.size();i++)
            {
                printf("%X\t",vehicleInfoMsg[i]);
            }
            printf("\n\n\n");
            if(udpTxStatus <= 0 )
			{
				std::cout << "UDP Vehicle Send Request failed" << std::endl;
			}

			else
			{
				std::cout << "UDP Vehicle Send Success" << std::endl;
			}

			break;
		}
		case Vin_Reponse_Received:
		{
            ret= DoipTester_InitTcpSockets();
			if(ret ==  0 )
			{
				cout<< "TCP  Success : migrating to next state >> TCP_Socket_Completed  " << endl;
				eDoIPtesterState = Routing_Activation_Init ;

			}

			break;
		}
		case Routing_Activation_Init:
		{
           lDoIPMsg.clear();
	        lPayloadType_t = EPayloadType_RoutingActivaionRequest;
	        msg_type =  static_cast<uint16_t> (lPayloadType_t);
	        Length = 11; ///< 11 byte payload for DOIP
	        lDoIPMsg = {DOIP_PROTOCOL_VERSION,253,
	        		                            static_cast<uint8_t>(msg_type >> 8u),
												static_cast<uint8_t>(msg_type),
												static_cast<uint8_t>((Length >> 24) & 0xFF),
												static_cast<uint8_t>((Length >> 16) & 0xFF),
												static_cast<uint8_t> ((Length >> 8) & 0xFF),
												static_cast<uint8_t>(Length & 0xFF)};
	        ret = DoipTester_SendRoutingActivationRequest(lDoIPMsg);
            int tcpLength;
            tcpLength=write(mtcpSocketFd, lDoIPMsg.data(), lDoIPMsg.size());
	        if(tcpLength < 0)
	        {
	            std::cout << "TCP Routing Activation  Rq. Send failed.." << std::endl;

	        }
	        else
	        {
	            std::cout << "TCP Routing Activation  Req Send..." << std::endl;

	        }
            printf("\n\n");
            printf("\nSIZE OF TCP ROUTING ACTIVATION SENT DATA FROM CLIENT =%u\n",(uint32_t)tcpLength);
            for(uint8_t i=0;i<lDoIPMsg.size();i++)
            {
                printf("%X ",lDoIPMsg[i]);
            }
            printf("\n\n\n");
			break;
		}
		case Routing_Activation_Completed:
		{

             ///< No Code Required
			break;
		}
		case Doip_Tester_Ready:
		{
        /**    lDoIPMsg.clear();
	        lPayloadType_t = EPayloadType_DiagnosticMessage;
	        msg_type =  static_cast<uint16_t> (lPayloadType_t);
	        Length = 64004; ///< 11 byte payload for DOIP
	        lDoIPMsg= {
			                             DOIP_PROTOCOL_VERSION,253,
									    static_cast<uint8_t>(msg_type >> 8u),
											static_cast<uint8_t>(msg_type),
											static_cast<uint8_t>((Length >> 24) & 0xFF),
											static_cast<uint8_t>((Length >> 16) & 0xFF),
											static_cast<uint8_t>((Length >> 8) & 0xFF),
											static_cast<uint8_t>(Length & 0xFF)
	        								};
	        ret = DoipTester_SendDiagMessageInfo(lDoIPMsg);
            int length;
	        if((length=write(mtcpSocketFd, lDoIPMsg.data(), lDoIPMsg.size())) < 0 )
	        {
	            std::cout << " Diag Message  Send failed.." << std::endl;
	        }
	        else
	        {*/
               //eDoIPtesterState = Doip_Tester_Response;
	           // std::cout << " Diag Message  0x8001  Message Passed.." <<length<< std::endl;
               mpCommandlineInputs= new std::thread([this]() { this->DoIPCmdLineInpts(); });
               whileLoopFlag=false;
	        //}

			break;
		}
		case TCP_UDP_Socket_Close:
		{
			break;
		}
	}

        std::this_thread::sleep_for(std::chrono::milliseconds(1000 )); // sleep for 1second
	}

}


void print_packet(unsigned char *buffer , int size)
{

    unsigned short iphdrlen;

    struct iphdr *iph = (struct iphdr *)buffer;
    iphdrlen = iph->ihl*4;

    struct udphdr *udph = (struct udphdr*)(buffer + iphdrlen);

      PrintData(buffer,size);


    printf("\n###########################################################\n");
}

void PrintData (unsigned char* data , int size)
{
    int i,j;

    for(i=0 ; i < size ; i++)
    {
        if( i!=0 && i%16==0)   //if one line of hex printing is complete...
        {
            printf("         ");
            for(j=i-16 ; j<i ; j++)
            {
                if(data[j]>=32 && data[j]<=128)
                    printf("%c",(unsigned char)data[j]); //if its a number or alphabet

                else printf("."); //otherwise print a dot
            }
            printf("\n");
        } 

        if(i%16==0) printf("   ");
            printf(" %02X",(unsigned int)data[i]);

        if( i==size-1)  //print the last spaces
        {
            for(j=0;j<15-i%16;j++) printf("   "); //extra spaces

            printf("   ");

            for(j=i-i%16 ; j<=i ; j++)
            {
                if(data[j]>=32 && data[j]<=128) printf("%c",(unsigned char)data[j]);
                else printf(".");
            }
            printf("\n");
        }
    }
}
void CDoipTester::UdpReceiveThread()
{
    unsigned char buffer[65536];
    struct sockaddr_in  servaddr;
    struct udphdr *udph = (struct udphdr*)(buffer + sizeof(struct iphdr));
    struct iphdr *iph = (struct iphdr *)buffer;
    int sizeReceived=0;
    socklen_t len;
    std::vector<uint8_t> ldata;
    while(sizeReceived<=0)
    {
		if(mudpSocketFd >= 0)
		{
            len = sizeof(servaddr);
			sizeReceived = recvfrom(mudpSocketFd, (char *)buffer, 5000, MSG_WAITALL, (struct sockaddr *) &servaddr,  &len);
			ldata.clear();
			if(sizeReceived > 0 )
			{
				printf("\nMessage received at Doip Tester <UDP >:Length(inBytes)=%u\n",(uint32_t)sizeReceived);
			    std::copy(&buffer[0], &buffer[sizeReceived], back_inserter(ldata)); // copy the element to an vector

			    DoipTester_ProcessData(servaddr,ldata);
                print_packet(buffer ,sizeReceived);

			}

		}
        else
        {
           // pthread_cond_wait(&oe,&mu);
        }
	}

}

void CDoipTester::TcpReceiveThread()
{
    int32_t len=0;
    uint8_t buffer[4096];
    std::vector<uint8_t> ldata;
    sockaddr_in servaddr;
    fd_set readfds;
    sem_wait(&mSemTcpReceivethreadTask);
    while(1)
	{
		if(mtcpSocketFd >= 0)
		{
            int tempSocket= mtcpSocketFd;
            FD_ZERO( &readfds );
            FD_SET( tempSocket, &readfds );
            int err = select( tempSocket+1, &readfds, NULL, NULL, NULL );

            len = sizeof(servaddr);
            if(err>0){
			len = read(mtcpSocketFd, (uint8_t *)buffer, sizeof(buffer));
			ldata.clear();

			if(len > 0 )
			{
                if((isTesterPresenceLogs==false) ||
                        ((isTesterPresenceLogs==true) &&
                         mUdsRequests != UDS_TesterPresence)){
				printf("\nMessage received at Doip Tester <TCP>:Length(inBytes)=%u\n",(uint32_t)len);
			    std::copy(&buffer[0], &buffer[len], back_inserter(ldata)); // copy the element to an vector

			    (void) DoipTester_ProcessData(servaddr,ldata);
                print_packet(buffer ,len);
                if(mseedKeygen == ESendKey_Last || mseedKeygen == EsendKey)
                {
                    DoIPStateMachine(mUdsRequests);
                    mseedKeygen = INFINITE;
                }
                }
			}
            else
            {
	            //std::cout << "Message received Failed at Doip Tester <TCP > : Length(in Bytes) " << +len<<std::endl;

            }
            }
		}
	}

}


int8_t CDoipTester::DoipTester_InitTcpSockets()
{
	int8_t ret = -1;
    //char buffer[MAXLINE];
    struct sockaddr_in servaddr;

    // Creating socket file descriptor
    if ((mtcpSocketFd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
	{
        std::cout << "TCP Socket creation failed.." << std::endl;
    }
    else
    {

        std::cout << "TCP Socket creation Success.." << std::endl;
        //std::cout << "Target Information retrieved through UDP Request<sa_family>" << +mClientServeraddr.sin_family<< std::endl;
        //std::cout << "Target Information retrieved through UDP Request<Port Number>" << mClientServeraddr.sin_port << std::endl;
        //std::cout << "Target Information retrieved through UDP Request<IP address>" << mClientServeraddr.sin_addr.s_addr << std::endl;
        ///< Filling server information
         memset(&servaddr, 0, sizeof(servaddr));
         servaddr= mClientServeraddr;

         // Filling server information
         servaddr.sin_family = PF_INET;
         servaddr.sin_port = htons(13400);


         char IP_Address[100];
         cin.clear();
         cin.ignore();
         cout<<"\nEnter Server TCP IP address:"<<endl;
         cout<<"#Ex: 192.168.1.76"<<endl;
         cin.getline (IP_Address, 100);
         cout << "\nEntered IP address is: " << IP_Address << endl;
         char * s = IP_Address;
         servaddr.sin_addr.s_addr = inet_addr(s);

         //servaddr.sin_addr.s_addr = inet_addr("192.168.1.76");
         //servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

         if (connect(mtcpSocketFd, (struct sockaddr*)&servaddr,
                     sizeof(servaddr)) != 0)
	     {
             std::cout << "TCP connection failed.." << std::endl;
	     }
         else
         {
	        ret= 0x0;
			sem_post(&mSemTcpReceivethreadTask);
            std::cout << "TCP connection success.." << std::endl;
            mpTcpReceivethreadTask = new std::thread([this]() { this->TcpReceiveThread(); });
         }
    }

	return ret;
}

int8_t CDoipTester::DoipTester_InitUdpSockets( )
{
	int8_t ret = -1;
	int broadcastEnable=1;

    //std::string devname ("lo");
      char devname[50];
      cout<<"\nEnter source interface name:"<<endl;
      cout<<"#It is the PC tester ethernet interface name \n#to which server is connected. \n#Ex: eno1"<<endl;
      cin>>devname;
      printf("\niface name is %s\n",devname);
	 // Creating socket file descriptor
	if ( (mudpSocketFd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 )
	{
		cout<< "UDP socket creation failed" << endl;
	}
	else
	{
		cout << "UDP socket creation successful" << mudpSocketFd<<std::endl;

		if( setsockopt(mudpSocketFd, SOL_SOCKET, SO_BINDTODEVICE,
                    devname,(strlen(devname))) < 0)
		{
		   cout<< "UDP Socket : Bind to device failed" << endl;
		}

		else
		{
			std::cout << "UDP Bind to device success " << mudpSocketFd<<std::endl;


			if( setsockopt(mudpSocketFd, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, sizeof(broadcastEnable)) < 0 )
			{
				sem_post(&mSemUdpReceivethreadTask);
				std::cout << "UDP Broadcast permission failed to set " << mudpSocketFd<<std::endl;
			}
			else
			{
				ret = 0x0;
				std::cout << "UDP broadcast permission set.." << mudpSocketFd<<std::endl;
			}
		}
	}

	return ret;
}

/**int8_t CDoipTester::DoipTester_ConnectTcpSockets()
{
    struct sockaddr_in clientAddr;
	int8_t ret = -1;
    uint32_t len;
	   

	len = sizeof(clientAddr); 
        // Accept the data packet from client and verification 
	  std::cout << "Accept Socket Request from TCP client" << std::endl;
	   std::cout << "Socked ID is" << +mtcpSocketFd<< std::endl;
	  mtcpconnSocketfd = accept(mtcpSocketFd, (sockaddr *)&clientAddr, &len); 

	   std::cout << "Client Information retrieved through TCP Request<sa_family>" << +clientAddr.sin_family<< std::endl;
	   std::cout << "Client Information retrieved through TCP Request<Port Number>" << clientAddr.sin_port << std::endl;
	   std::cout << "Client Information retrieved through TCP Request<IP address>" << clientAddr.sin_addr.s_addr << std::endl;

		if (mtcpconnSocketfd < 0) 
		{ 
			std::cout << "TCP Server Accept failed " << std::endl;
		} 
		else
		{
			std::cout << "TCP Server Accept  the client  " << std::endl;
				ret= 0x0;
				sem_post(&mSemTcpReceivethreadTask);
				std::cout << "TCP connection success.." << std::endl;
		}

}*/

/**Tester Presence Thread*/
void CDoipTester::SessionControlThread(void)
{
        std::vector<uint8_t> lMsg;
	    int Ret= -1;
        cout<<"Sending Tester presence in 500ms interval"<<endl;
        while(1){
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            if(sessionThreadVar==UDS_DiagnosticSession_Extendded){
               mUdsRequests = UDS_TesterPresence;
               lMsg.clear();
			    Ret= ProcessTxDiagTesterPresence(lMsg);
                isTesterPresenceLogs=true;
                Ret= write(mtcpSocketFd , lMsg.data(), lMsg.size());
                if(Ret <=0)
                {
                    cout<<"Tester presence in extended session failed"<<endl;
                }
            }
        }

}
void CDoipTester::DoIPCmdLineInpts(void)
{
	char doipCmdLine;
    int testerFlag=-1;

	while(1)
	{
       // pthread_mutex_lock(&mu);
		cout << " Press 'A' for Diagnostic Session Service $0x10: Default "<<endl;
        cout << " Press 'C' for Diagnostic Session Service $0x10: Extendded"<<endl;
		cout << " Press 'D' for Security Access Service $0x27  "<<endl;
		//cout << " Press 'E' for Routine Control Service Service $0x27  "<<endl;
		//cout << " Press 'F' Reflash Program Check Service $0x27  "<<endl;
		cout << " Press 'G' for Tester Presence Service $0x3E  "<<endl;
		cout << " Press 'H' to send larget data (Max Length check)  "<<endl;
        cout << " Press 'I' for ECU Reset Service $0x11  "<<endl;
        //cout <<" Press 'J'  Graceful Close  of the  complete socket "<<endl;
        //cout <<" Press 'K'  Graceful Close  of the  one client Socket "<<endl;
        cout << " Press 'L' for Read Data By Identifier Service $0x27 "<<endl;
        cout<<  " Press 'M' to send minimum data (Min Length Check) "<<endl;
        //cout << " Press 'N' Data transfer using ECU Reset Service "<<endl;
		cout << " Press 'B' for request download $0x34"<<endl;
		cout << " Press 'F' for data transfer $0x36  "<<endl;
		cout << " Press 'T' for exit data transfer $0x37  "<<endl;
        //cout <<" Press 'L' for Seed Key Send Service Service $0x27 "<<endl;
        cout<<  " Press 'Z' to exit gracefully"<<endl;

		cin>>doipCmdLine;

		switch(doipCmdLine)
		{
            case 'A': case 'a' :
            isTesterPresenceLogs=false;
			mUdsRequests = UDS_DiagnosticSession_Default;
            sessionThreadVar=UDS_DiagnosticSession_Default;
			break;

            case 'B':case 'b':
				mUdsRequests = UDS_TransferData;
				mUdsStateMachine = RequestDownload;
				break;

            case 'C':case 'c':
           mUdsRequests = UDS_DiagnosticSession_Extendded;
           cout<<"\nEnter 1 for tester presence else 0:"<<endl;
           cout<<"#If set to 1, tester presence service is sent periodically \n#to ensure diagnostic session not fallback to default"<<endl;
           cin>>testerFlag;
           if(testerFlag==1){
           isTesterPresenceLogs=true;
           isSessionControlflag=true;
           sessionThreadVar=UDS_DiagnosticSession_Extendded;
           mpSessionControl=new std::thread([this]() { this->SessionControlThread(); });
           }
       break;

            case 'D':case 'd':
			mUdsRequests = UDS_SeedKeyReq;
            mseedKeygen = ESeedKeyRequests_Last ;

			break;

		case 'E':case 'e':
			mUdsRequests = UDS_RoutineControl;
			break;
        case 'F':case 'f':
		    mBlockSeqCntr=0;
		   mUdsStateMachine=TransferData;
			mUdsRequests = UDS_TransferData;
			break;

		case 'T':case 't':
		   mUdsStateMachine=TransferExitRequest;
			mUdsRequests = UDS_TransferData;

			break;
        case 'G':case 'g':
			mUdsRequests = UDS_TesterPresence;
              break;

        case 'H':case 'h':
            mUdsRequests= UDS_TransferLargerData;
			break;

        case 'I':case 'i':
          mUdsRequests=  UDS_ECUReset;
          break;

        case 'J':case 'j':
        mUdsRequests=  DOIP_CloseSocket;
        break;


        case 'K':case 'k':
        mUdsRequests=  DOIP_OpenSocket;
        break;

        case 'L':case 'l':
        mUdsRequests=UDS_ReadDataByIdentifier;
        break;

        case 'm':case 'M':
        mUdsRequests=UDS_MinLenghtCheck;
        break;

        case 'n':case 'N':
          mUdsRequests=  UDS_DataTransfer;
          break;

        case 'z':case 'Z':
         mUdsRequests=DOIP_CloseSocket;
        break;


		default:
			break;
		}
        DoIPStateMachine(mUdsRequests);
        std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // sleep for 1second
	}


}


int8_t CDoipTester::DoipTester_SendVinRequest(std::vector<uint8_t> &vehicleInfoMsg)
{
    vehicleInfoMsg.push_back(0x01);
    vehicleInfoMsg.push_back(0x02);
    vehicleInfoMsg.push_back(0x03);
    vehicleInfoMsg.push_back(0x04);
    vehicleInfoMsg.push_back(0x05);
    vehicleInfoMsg.push_back(0x06);
    vehicleInfoMsg.push_back(0x07);
    vehicleInfoMsg.push_back(0x08);
    vehicleInfoMsg.push_back(0x09);
    vehicleInfoMsg.push_back(0x0a);
    vehicleInfoMsg.push_back(0x0b);
    vehicleInfoMsg.push_back(0x0c);
    vehicleInfoMsg.push_back(0x0d);
    vehicleInfoMsg.push_back(0x0e);
    vehicleInfoMsg.push_back(0x0f);
    vehicleInfoMsg.push_back(0x10);
    vehicleInfoMsg.push_back(0x11);
	return 0X0;
}

int8_t CDoipTester::DoipTester_SendEidRequest(std::vector<uint8_t> &vehicleInfoMsg)
{
    vehicleInfoMsg.push_back(0x01);
    vehicleInfoMsg.push_back(0x02);
    vehicleInfoMsg.push_back(0x03);
    vehicleInfoMsg.push_back(0x04);
    vehicleInfoMsg.push_back(0x05);
    vehicleInfoMsg.push_back(0x06);
    return 0X0;

}

int8_t CDoipTester::DoipTester_SendGidRequest(std::vector<uint8_t> &vehicleInfoMsg)
{
    vehicleInfoMsg.push_back(0x01);
    vehicleInfoMsg.push_back(0x02);
    vehicleInfoMsg.push_back(0x03);
    vehicleInfoMsg.push_back(0x04);
    vehicleInfoMsg.push_back(0x05);
    vehicleInfoMsg.push_back(0x06);
	return 0X0;

}

void  CDoipTester::DoIPStateMachine(int mUdSRequests)
{
	std::vector<uint8_t> lMsg;
	int Ret= -1;
	 uint16_t lRoutineIdentifier = 0x0206;
	std::vector<uint8_t> lSeedMsg ;

cout<<"doipstate"<<endl;
		   switch(mUdsRequests)
		   {


		   case UDS_DiagnosticSession_Default:

			lMsg.clear();

			   Ret= ProcessTxDiagSessionCntrlMsgs(lMsg,EdefaultSession);
               Ret= write(mtcpSocketFd , lMsg.data(), lMsg.size());
               cout << " Diagnostic Session " << Ret <<endl;
			break;

		   case UDS_DiagnosticSession_Reprogramming:

			lMsg.clear();

			    Ret= ProcessTxDiagSessionCntrlMsgs(lMsg,EprogrammingSession);

               Ret= write(mtcpSocketFd , lMsg.data(), lMsg.size());
               cout << " Reprogramming Session " << Ret <<endl;
			break;

           case UDS_DiagnosticSession_Extendded:
                lMsg.clear();
                Ret= ProcessTxDiagSessionCntrlMsgs(lMsg,EextendedDiagnosticSession);
                Ret= write(mtcpSocketFd , lMsg.data(), lMsg.size());
                cout << " Extended Session " << Ret <<endl;
           break;

		   case UDS_TesterPresence:
			lMsg.clear();

			    Ret= ProcessTxDiagTesterPresence(lMsg);

                  Ret= write(mtcpSocketFd , lMsg.data(), lMsg.size());
                   cout << " Tester Presence Sucessful" << Ret <<endl;

                /*Send the message via TCP */

		   break;


		   case UDS_SeedKeyReq:
               lMsg.clear();
			   if(mseedKeygen == ErequestSeed )
			   {
				   Ret= ProcessSeedKeyMsgs(lMsg,ErequestSeed  ,lSeedMsg);
                   Ret= write(mtcpSocketFd , lMsg.data(), lMsg.size());
                   cout << " SERVICE KEY REQUEST " << Ret <<endl;
			   }

               if(mseedKeygen == ESeedKeyRequests_Last)
			   {
				   Ret= ProcessSeedKeyMsgs(lMsg,ESeedKeyRequests_Last ,lSeedMsg);
                   Ret= write(mtcpSocketFd , lMsg.data(), lMsg.size());
                   cout << " SERVICE KEY REQUEST FOR DIFFERENT LEVELS " << Ret <<endl;
			   }

			   if(mseedKeygen == EsendKey )
			   {
				   Ret= ProcessSeedKeyMsgs(lMsg,EsendKey,lkeyMsg);
                   Ret= write(mtcpSocketFd , lMsg.data(), lMsg.size());
                   cout << " SERVICE KEY SEND " << Ret <<endl;
			   }
               if(mseedKeygen == ESendKey_Last)
			   {
				   Ret= ProcessSeedKeyMsgs(lMsg,ESendKey_Last,lkeyMsg);
                   Ret= write(mtcpSocketFd , lMsg.data(), lMsg.size());
                   cout << " SERVICE KEY SEND LAST " << Ret <<endl;

			   }

		   break;

		   case UDS_RoutineControl:
              {

                     lMsg.clear();

				  Ret= ProcessTxRoutineCntrlMsgs(lMsg, EstartRoutine,lRoutineIdentifier);
                  Ret= write(mtcpSocketFd , lMsg.data(), lMsg.size());
                   cout << " Routine Control Message Send " << Ret <<endl;

			   }
		   break;

		   case UDS_TransferData:
		   {
			   //cout<<"entered to transfer"<<endl;
			   //mReqInProgress=false;

			   //if(mReqInProgress == false )
			   { 

				   if(mUdsStateMachine == RequestDownload)
				   {
					  // cout<<"excuted download"<<endl;
					   Ret =ProcessTxDiagTransferMsgs( lMsg, ERequestDownLoadReq);
					   Ret= write(mtcpSocketFd , lMsg.data(), lMsg.size());
					   mReqInProgress = true;
				   }

				   if(mUdsStateMachine == FileTransferRequest)
				   {

				   }

				   if(mUdsStateMachine == TransferData)
				   {
					   if(mtransferDataCompleted == false)
					   {
						   //cout<<"transfering data"<<endl;
						   mBlockSeqCntr++;
						   Ret =ProcessTxDiagTransferMsgs( lMsg, ERequestTransferDataReq);
						   Ret= write(mtcpSocketFd , lMsg.data(), lMsg.size());
						   //cout<<"1ret"<<Ret<<endl;
						   mReqInProgress = true;
						   

					   }

					   if(mtransferDataCompleted == true)
					   {
						   
						   mBlockSeqCntr = 0;
						   //mUdsStateMachine = TransferExitRequest;

					   }

				   }


				   if(mUdsStateMachine == TransferExitRequest)
				   {
					   cout<<"transfer exit"<<endl;
					   Ret =ProcessTxDiagTransferMsgs( lMsg, ERequestTransferExitReq);
					   Ret= write(mtcpSocketFd , lMsg.data(), lMsg.size());

					   //Ret =ProcessTxDiagTransferMsgs( lMsg, ERequestTransferExitReq);
					   mReqInProgress = true;

				   }
			   }

		   }


		   break;

          case UDS_TransferLargerData:

	        lMsg.clear();
			Ret= DiagMessage_ReqTransfer(lMsg,UDS_TransferLargerData);
             Ret= write(mtcpSocketFd , lMsg.data(), lMsg.size());
            cout << " Large Data is send" << +Ret <<endl;

          break;

          case UDS_MinLenghtCheck:

	        lMsg.clear();
			Ret= DiagMessage_ReqTransfer(lMsg,UDS_MinLenghtCheck);
             Ret= write(mtcpSocketFd , lMsg.data(), lMsg.size());
            cout << " Minimum Data is send" << +Ret <<endl;

          break;

		case UDS_ECUReset:
	        lMsg.clear();
			Ret=  ProcessTxEcuResetMsgs(lMsg);
             Ret= write(mtcpSocketFd , lMsg.data(), lMsg.size());
			 cout << " ECU Reset command is initiated" << +Ret <<endl;
         break;

		case UDS_DataTransfer:
	        lMsg.clear();
			Ret=  ProcessTxEcuResetMsgs_DataTransfer(lMsg);
             Ret= write(mtcpSocketFd , lMsg.data(), lMsg.size());
			 cout << " Data transfer using ECU Reset initiated" << +Ret <<endl;
         break;

        case UDS_ReadDataByIdentifier:
             lMsg.clear();
             Ret=ProcessTxReadDataByIdentifier(lMsg);
             Ret=write(mtcpSocketFd , lMsg.data(), lMsg.size());
             cout<<"ReadDataByIdentifier command is initiated:"<<endl;
             break;


        case DOIP_CloseSocket:

         if(mtcpconnSocketfd >= 0)
       {

        //shutdown(mtcpconnSocketfd, SHUT_RDWR) ;

          Ret = close(mudpSocketFd);

		 cout << "UDP CLient Socket Closed" << +Ret <<endl;

         mudpSocketFd = -1;

         Ret = close(mtcpSocketFd);
		 cout << "TCP Client Socket Closed" << +Ret <<endl;

         mtcpSocketFd = -1;

         threadFlag=false;


        }
         break;


        case DOIP_OpenSocket:


         if(mtcpSocketFd  <  0)
        {

        DoipTester_InitTcpSockets();


       }
         break;


        /**case DOIP_PollforNewSocket: NOT USED

         if(mtcpSocketFd  <  0)
        {
            DoipTester_InitTcpSockets();
         }

         if(mtcpconnSocketfd  <  0)
        {
			DoipTester_ConnectTcpSockets();
         }
         break;*/

		   default:
			   break;

		   }
           printf("\n\n\n");
            printf("\nSIZE OF TCP DATA FROM CLIENT = %u\n",(uint32_t)Ret);
            if(mUdsRequests!=UDS_TransferLargerData &&
                    mUdsRequests!=UDS_DataTransfer &&
                    mUdsRequests!=UDS_MinLenghtCheck){
            for(uint8_t i=0;i<lMsg.size();i++)
            {
                printf("%X ", lMsg[i]);
				cout<<"printed"<<endl;
				break;
            }
            printf("\n\n\n");
            }



   }

int8_t CDoipTester::DoipTester_ProcessData(sockaddr_in &servaddr, std::vector<uint8_t> &lMsg)
{
	int8_t ret = -1;
    uint16_t msg_type;
    uint16_t Length;

	//uint16_t ecuLogicalAddr = 0x0;
	//uint16_t toolLogicalAddr = 0x0;

	if((lMsg[0] == DOIP_PROTOCOL_VERSION) && (lMsg[1] == DOIP_PROTOCOL_INVERSE_VERSION))
	{
		if(DoipTester_getPayloadLength(lMsg) < (0xFFFFFFFFu))
		{
			if(DoipTester_getPayloadLength(lMsg) <= DOIP_STACK_SIZE )
			{
				switch((EPayloadType_t)DoipTester_getPayloadType(lMsg))
				{
					case EPayloadType_RoutingActivationResponse:	/* Routing Activation request */
					{
						uint16_t ecuLogicalAddr = 0x0;
						uint16_t toolLogicalAddr = 0x0;
						ecuLogicalAddr = ( static_cast<uint16_t>(lMsg[8]) << 8 ) ;
						ecuLogicalAddr |=lMsg[9];
						cout << "Logical address of the ECU "<<+ecuLogicalAddr <<endl;
						toolLogicalAddr = ( static_cast<uint16_t>(lMsg[10]) << 8 ) ;
						toolLogicalAddr |=lMsg[11];
						cout << "Logical address of the external test equipment "<<+toolLogicalAddr <<endl;
						cout << "Routing activation Response received "<<endl;

						cout << "Routing activation Status value "<< +lMsg[12]<<endl;

						if ((lMsg[12] == 0x10) || (lMsg[12] == 0x11))
						{
							eDoIPtesterState = Doip_Tester_Ready;
							cout << "Routing_Activation_Completed "<<endl;
						}
                        //mpCommandlineInputs= new std::thread([this]() { this->DoIPCmdLineInpts(); });
						break;
					}
					case EPayloadType_AliveCheckResponse:
					{
						break;
					}
					case EPayloadType_DiagnosticMessage:
					{
						(void)ProcessRxDiagMessage(lMsg);
						break;

					}

					case EPayloadType_DiagnosticMessagePositiveAck:	 /* Diagnostic message */
						{
	                       cout << "Positive Diag Ack Received : 0x8002  "<<endl;
							uint16_t ecuLogicalAddr = 0x0;
							uint16_t toolLogicalAddr = 0x0;
							ecuLogicalAddr = ( static_cast<uint16_t>(lMsg[8]) << 8 ) ;
							ecuLogicalAddr |=lMsg[9];
							cout << "Logical address of the ECU "<<+ecuLogicalAddr <<endl;
							toolLogicalAddr = ( static_cast<uint16_t>(lMsg[10]) << 8 ) ;
							toolLogicalAddr |=lMsg[11];
							cout << "Logical address of the external test equipment "<<+toolLogicalAddr <<endl;
							cout << "Diagnostic message Pos Ack received "<<+lMsg[12]<<endl;
			                //eDoIPtesterState = Doip_Tester_Ready;

		    				break;
					}

					case EPayloadType_DiagnosticMessageNegativeAck:
					{
						  cout << "Negative Diag Ack Received : 0x8003  "<<endl;
							uint16_t ecuLogicalAddr = 0x0;
							uint16_t toolLogicalAddr = 0x0;
							ecuLogicalAddr = ( static_cast<uint16_t>(lMsg[8]) << 8 ) ;
							ecuLogicalAddr |=lMsg[9];
							cout << "Logical address of the ECU "<<+ecuLogicalAddr <<endl;
							toolLogicalAddr = ( static_cast<uint16_t>(lMsg[10]) << 8 ) ;
							toolLogicalAddr |=lMsg[11];
							cout << "Logical address of the external test equipment "<<+toolLogicalAddr <<endl;
							cout << "Diagnostic message  Neg Ack received "<<+lMsg[12]<<endl;
			                //eDoIPtesterState = Doip_Tester_Ready;
		    				break;
					}

					case EPayloadType_VehicleAnnouncementOrResponse:
					{
						std::cout << "DoipTester_ProcessUdpData : Vehicle Response Received "<<std::endl;
						eDoIPtesterState = Vin_Reponse_Received ;
						mClientServeraddr= servaddr;
						mClientServeraddr.sin_port = htons(servaddr.sin_port);
					}	break;

					case EPayloadType_DiagPowerModeInfoRequest:
					{
						break;
					}
					case EPayloadType_EntityStatusRequest:
					{
						break;
					}

					case EPayloadType_AliveCheckRequest:
					{
                        printf("\nAlive check request %x\n",lMsg[3]);
						EPayloadType_t lPayloadType_t;
						int8_t tmpret;
						lPayloadType_t = EPayloadType_AliveCheckResponse;
						msg_type =  static_cast<uint16_t> (lPayloadType_t);
						Length = 2u; ///< 11 byte payload for DOIP
					   std::vector<uint8_t> lDoIPMsg = {DOIP_PROTOCOL_VERSION,253,
							static_cast<uint8_t>(msg_type >> 8u),
							static_cast<uint8_t>(msg_type),
							static_cast<uint8_t>((Length >> 24) & 0xFF),
							static_cast<uint8_t>((Length >> 16) & 0xFF),
							static_cast<uint8_t> ((Length >> 8) & 0xFF),
							static_cast<uint8_t>(Length & 0xFF)};
						tmpret = DoipTester_SendAliveCheckResponse(lDoIPMsg);
						int tcpLength;
						tcpLength=write(mtcpSocketFd, lDoIPMsg.data(), lDoIPMsg.size());
						if(tcpLength < 0)
						{
							std::cout << "TCP Alive check response Send failed..." << std::endl;

						}
						else
						{
							std::cout << "TCP Alive check response Send..." << std::endl;

						}
						printf("\n\n");
						cout<<"SIZE OF TCP ALIVE CHECK REQUEST FROM SERVER "<<endl;
						printf("\n");
						break;
					}

					default:
					{
						std::cout << "DoipTester_ProcessUdpData : Unknown Payload type "<<std::endl;
						break;
					}
				}
			}
			else
			{
				std::cout << "DoipTester_ProcessUdpData : Invalid Payload length "<<std::endl;

			}
		}
		else
		{
			std::cout << "DoipTester_ProcessUdpData : Invalid Payload length "<<std::endl;
		}
	}

	return ret;
}


uint32_t CDoipTester::DoipTester_getPayloadLength( std::vector<uint8_t> &buffer)
{
	uint32_t payloadLength = 0 ;
	if(buffer.size() > 8)
	{
		payloadLength  = buffer.at(4) << 24U;
		payloadLength |= buffer.at(5) << 16U;
		payloadLength |= buffer.at(6) << 8U;
		payloadLength |= buffer.at(7);

	}
	return payloadLength;
}


uint16_t CDoipTester::DoipTester_getPayloadType( std::vector<uint8_t> &buffer)
{
	uint16_t payloadType = 0;
	if(buffer.size() > 4)
	{
		payloadType  = buffer.at(2) << 8U ;
		payloadType |= buffer.at(3);
	}
	return payloadType;
}

int8_t CDoipTester::DoipTester_SendRoutingActivationRequest(std::vector<uint8_t> &lMsg)
{
    cout<<"\nEnter routing activation type:"<<endl;
    cout<<"#It is DoIPRoutingactivationType \n#configured in doip.ini at the server"<<endl;
    cout<<"#00  Default \n#01  WWH-OBD \n#E0  Central security"<<endl;
    //cin>>hex>>uActivationType;

	lMsg.push_back(( mDoipTestParam.ToolAddress >> 8 ) & (0xFF));
	lMsg.push_back( ( mDoipTestParam.ToolAddress) &0xFF);
    scanf("%X",&uActivationType);
	lMsg.push_back( uActivationType); // Activation type " Default"
	lMsg.push_back( 0X0); // Reserved for future
	lMsg.push_back( 0X0); // Reserved for future
	lMsg.push_back( 0X0); // Reserved for future
	lMsg.push_back( 0X0); // Reserved for future
	lMsg.push_back( 0X0); //  Reserved for OEM specific use
	lMsg.push_back( 0X0);//  Reserved for OEM specific use
	lMsg.push_back( 0X0);//  Reserved for OEM specific use
	lMsg.push_back( 0X0);//  Reserved for OEM specific use

	return 0;

}

int8_t CDoipTester::DoipTester_SendAliveCheckResponse(std::vector<uint8_t> &lMsg)
{
	lMsg.push_back(( mDoipTestParam.ToolAddress >> 8 ) & (0xFF));
	lMsg.push_back( ( mDoipTestParam.ToolAddress) &0xFF);

	return 0;

}

int8_t CDoipTester::ProcessRxDiagMessage(std::vector<uint8_t> &lMsg )
{

	EUdsResponse_t leUdsType= 0X0;
	//uint32_t lMaxBlockLengthNum = 0x0;
	uint16_t lRoutineIdentifier = 0x0;
	uint32_t lSeedKeyMsg = 0x0;
	uint16_t ecuLogicalAddr;
	uint16_t toolLogicalAddr;
    uint8_t ones=1;

          std::vector<uint8_t> lMsg_tmp;
          int Ret_tmp= -1;

	ecuLogicalAddr = ( static_cast<uint16_t>(lMsg[8]) << 8 ) ;
	ecuLogicalAddr |=lMsg[9];
	cout << "Logical address of the ECU "<<std::hex<<+ecuLogicalAddr <<endl;
	toolLogicalAddr = ( static_cast<uint16_t>(lMsg[10]) << 8 ) ;
	toolLogicalAddr |=lMsg[11];
	cout << "Logical address of the external test equipment "<<std::hex<<+toolLogicalAddr <<endl;
	leUdsType = lMsg[12];

	///cout << "Received UDS Response : Command "<<+leUdsType <<endl;

	mReqInProgress = true;

	switch(leUdsType)
	{

		case ETesterPresResponse:

			cout << "Seed Key Response Received  : 0x7E "<<endl;
		break;


		case EDiagSessionCntrlResponse:
			uint8_t lSession;
			lSession = lMsg[12];

			cout << "Diag Session Response Received  : 0x50"<<endl;
			cout << "Diag Session is"<<+lSession<<endl;

		break;

		case ERoutineCntrlResponse:

			cout << "Routine Identifier Response Received  : 0x71"<<endl;

			uint32_t lRoutineMsg;
            //uint8_t lRoutineMode;

          cout << "Routine Identifier Mode :"<<std::hex<<+lMsg[13] <<endl;

            cout << "Routine Identifier Msg Id is :"<<std::hex<<+lRoutineIdentifier <<endl;
			lRoutineIdentifier = ( static_cast<uint16_t>(lMsg[14]) << 8 ) ;
			lRoutineIdentifier |=lMsg[15];
			cout << "Routine Identifier is :"<<std::hex<<+lRoutineIdentifier <<endl;


			lRoutineMsg =( static_cast<uint32_t>(lMsg[15])  << 24 ) | (( static_cast<uint32_t>(lMsg[16]) << 16 ) )| (( static_cast<uint32_t>(lMsg[17])  << 8) ) |
								(( static_cast<uint32_t>(lMsg[18])));


			break;



		case EDiagSeedKeyReponse:
			cout << "Seed Key Subfunction :"<<+lMsg[12] <<endl;
			if((lMsg[13] == 0x01 && mseedKeygen!= EsendKey &&
                        isSecuritySeedRecv==false)) //rx Seed
			{
                isSecuritySeedRecv=true;
                mseedKeygen = EsendKey;
                uint8_t data=(~lMsg[14])+ones;
                uint8_t data1=(~lMsg[15])+ones;
                lkeyMsg.clear();
                lkeyMsg.push_back(data);
                lkeyMsg.push_back(data1);
                mUdsRequests = UDS_SeedKeyReq;


			}
			else if (lMsg[13] ==  0x2) //rx key
			{


				cout << "Seed Key Subfunction :"<<+lMsg[12] <<endl;

				lSeedKeyMsg =( static_cast<uint32_t>(lMsg[13])  << 24 ) | (( static_cast<uint32_t>(lMsg[14]) << 16 ) )| (( static_cast<uint32_t>(lMsg[15])  << 8) ) |
							(( static_cast<uint32_t>(lMsg[16])));

				cout << "Seed Key Message is :"<<+lSeedKeyMsg <<endl;
				mseedKeygen = ESeedKeyRequests_Last;

			}
			else if(lMsg[13] == 0x03 && mseedKeygen!= ESendKey_Last &&
                    isSecuritySeedRecv==false)
			{
                isSecuritySeedRecv=true;
				mseedKeygen = ESendKey_Last;
                uint8_t data=(~lMsg[14])+ones;
                uint8_t data1=(~lMsg[15])+ones;
                lkeyMsg.clear();
                lkeyMsg.push_back(data);
                lkeyMsg.push_back(data1);
                mUdsRequests = UDS_SeedKeyReq;
			}



			break;


		case ERequestDownLoadResponse:

			// lMsg[13]; ///can be neglected // Pack data in UDS format
			lMaxBlockLengthNum =( static_cast<uint32_t>(lMsg[14])  << 24 ) | (( static_cast<uint32_t>(lMsg[15]) << 16 ) )| (( static_cast<uint32_t>(lMsg[16])  << 8) ) |
					(( static_cast<uint32_t>(lMsg[17])));

			cout << "Block Length Num (In Bytes) "<<+lMaxBlockLengthNum <<endl;
			cout << "Request Download Response Received : 0x74 " <<endl;

			mUdsStateMachine = FileTransferRequest;
			break;

		case ERequestFileTransferResponse:
			break;



		case ECUResetResponse:


          cout << "ECU Reset Response Received: 0x51 " <<endl;
          lMsg_tmp.clear();
          Ret_tmp=  ProcessTxEcuResetMsgs_DataTransfer(lMsg_tmp);
          Ret_tmp= write(mtcpSocketFd , lMsg_tmp.data(), lMsg_tmp.size());
          cout << " Data transfer using ECU Reset initiated" << +Ret_tmp <<endl;

          break;

		case ETransferDataResponse:
			cout << "Block Sequence number Num (In Bytes) "<<+lMsg[13]<<endl;
			cout << "Transfer Data Reponse Received  : 0x76 "<<endl;

			temp+=data_size;
			cout<<"data transferd :   "<<temp<<endl;;

			/* mBlockSeqCntr++;
			 lMsg_tmp.clear();
						   Ret_tmp =ProcessTxDiagTransferMsgs( lMsg_tmp, ERequestTransferDataReq);
						   Ret_tmp= write(mtcpSocketFd , lMsg_tmp.data(), lMsg_tmp.size());
						   cout<<"1ret"<<Ret_tmp<<endl;
						   mReqInProgress = true;
			
          cout << " Data transfer using download service initiated" << +Ret_tmp <<endl;*/

			if( temp >= 3758096384||(temp>=0xE0000000)  ) //checking for 3.5GB datatransfer
			{
				cout<<"transfer completed"<<endl;
				temp=0;
			}
			else
			{
				mBlockSeqCntr++;
			 lMsg_tmp.clear();
						   Ret_tmp =ProcessTxDiagTransferMsgs( lMsg_tmp, ERequestTransferDataReq);
						   Ret_tmp= write(mtcpSocketFd , lMsg_tmp.data(), lMsg_tmp.size());
						   cout << " Data transfer using download service initiated" << +Ret_tmp <<endl;
						   mReqInProgress = true;
			}
			
			
			break;

		case ERequestTransferExitResponse:
			cout << "Block Sequence number Num (In Bytes) "<<+lMsg[12]<<endl;
			cout << "Transfer Data Reponse Received  : 0x77 "<<endl;
			mUdsStateMachine = DefaultState;

			break;

        case ENegativeResponse:
			cout << " Negative Reponse Code Received" <<endl;
        break;


		default:
			break;
	}

	return 0;

}


int8_t CDoipTester::ProcessTxEcuResetMsgs(std::vector<uint8_t> &lMsg )
{

	genDoipHeader(lMsg,6,EPayloadType_DiagnosticMessage);
	// PACK DOIP Address
	lMsg.push_back(( static_cast<uint8_t> (mDoipTestParam.ToolAddress >> 8 ) & (0xFF)));  //DOIP tool address
	lMsg.push_back( static_cast<uint8_t>(( mDoipTestParam.ToolAddress) &0xFF)); //DOIP tool address
	lMsg.push_back( static_cast<uint8_t> (( mDoipTestParam.eculogicalAddress >> 8 ) & (0xFF)));  // ECU address
	lMsg.push_back( static_cast<uint8_t> (( mDoipTestParam.eculogicalAddress) &0xFF)); // ECU address

	lMsg.push_back( 0X11u);  //ECU Reset
	lMsg.push_back( 0x1);  //Hard Reset

	return 0;

}

int8_t CDoipTester::ProcessTxEcuResetMsgs_DataTransfer(std::vector<uint8_t> &lMsg )
{

	genDoipHeader(lMsg,(TRANSFER_BUFFER_SIZE+6),EPayloadType_DiagnosticMessage);
	// PACK DOIP Address
	lMsg.push_back(( static_cast<uint8_t> (mDoipTestParam.ToolAddress >> 8 ) & (0xFF)));  //DOIP tool address
	lMsg.push_back( static_cast<uint8_t>(( mDoipTestParam.ToolAddress) &0xFF)); //DOIP tool address
	lMsg.push_back( static_cast<uint8_t> (( mDoipTestParam.eculogicalAddress >> 8 ) & (0xFF)));  // ECU address
	lMsg.push_back( static_cast<uint8_t> (( mDoipTestParam.eculogicalAddress) &0xFF)); // ECU address

	lMsg.push_back( 0X11u);  //ECU Reset
	lMsg.push_back( 0x1);  //Hard Reset
    std::copy(&gTestBuffer[0], &gTestBuffer[380928], back_inserter(lMsg)); // copy the element to an vector

	return 0;

}


int8_t CDoipTester::ProcessTxRoutineCntrlMsgs(std::vector<uint8_t> &lMsg, ERoutineCntrlType_t lRoutineCtrl,uint16_t routineIdentifier)
{

	genDoipHeader(lMsg,8,EPayloadType_DiagnosticMessage);
	// PACK DOIP Address
	lMsg.push_back(( static_cast<uint8_t> (mDoipTestParam.ToolAddress >> 8 ) & (0xFF)));  //DOIP tool address
	lMsg.push_back( static_cast<uint8_t>(( mDoipTestParam.ToolAddress) &0xFF)); //DOIP tool address
	lMsg.push_back( static_cast<uint8_t> (( mDoipTestParam.eculogicalAddress >> 8 ) & (0xFF)));  // ECU address
	lMsg.push_back( static_cast<uint8_t> (( mDoipTestParam.eculogicalAddress) &0xFF)); // ECU address

	lMsg.push_back( 0X31U);  //Routine Control Msgs SID
	lMsg.push_back( lRoutineCtrl);  //Default session
	lMsg.push_back(( static_cast<uint8_t> (routineIdentifier >> 8 ) & (0xFF)));  //Routine Identifier
	lMsg.push_back( static_cast<uint8_t>(( routineIdentifier) &0xFF)); //Routine Identifier

	return 0;

}




int8_t CDoipTester::ProcessTxDiagSessionCntrlMsgs(std::vector<uint8_t> &lMsg, EUdsSession_t eUdsSession)
{

	genDoipHeader(lMsg,6,EPayloadType_DiagnosticMessage);
	// PACK DOIP Address
	lMsg.push_back(( static_cast<uint8_t> (mDoipTestParam.ToolAddress >> 8 ) & (0xFF)));  //DOIP tool address
	lMsg.push_back( static_cast<uint8_t>(( mDoipTestParam.ToolAddress) &0xFF)); //DOIP tool address
	lMsg.push_back( static_cast<uint8_t> (( mDoipTestParam.eculogicalAddress >> 8 ) & (0xFF)));  // ECU address
	lMsg.push_back( static_cast<uint8_t> (( mDoipTestParam.eculogicalAddress) &0xFF)); // ECU address

	lMsg.push_back( 0X10U);  //Diagnostic Session Exit SID
	lMsg.push_back( eUdsSession);  //Default session


	return 0;

}


int8_t CDoipTester::ProcessTxDiagTesterPresence(std::vector<uint8_t> &lMsg )
{

	genDoipHeader(lMsg,0x6,EPayloadType_DiagnosticMessage);
	// PACK DOIP Address
	lMsg.push_back(( static_cast<uint8_t> (mDoipTestParam.ToolAddress >> 8 ) & (0xFF)));  //DOIP tool address
	lMsg.push_back( static_cast<uint8_t>(( mDoipTestParam.ToolAddress) &0xFF)); //DOIP tool address
	lMsg.push_back( static_cast<uint8_t> (( mDoipTestParam.eculogicalAddress >> 8 ) & (0xFF)));  // ECU address
	lMsg.push_back( static_cast<uint8_t> (( mDoipTestParam.eculogicalAddress) &0xFF)); // ECU address

	lMsg.push_back( 0X3EU);  //Diagnostic Session Exit SID
	lMsg.push_back( 0X00);  //Default session
	return 0;

}
/**ReadDataByIdentifier*/
int8_t CDoipTester::ProcessTxReadDataByIdentifier(std::vector<uint8_t> &lMsg )
{
	genDoipHeader(lMsg,0x7,EPayloadType_DiagnosticMessage);
	// PACK DOIP Address
	lMsg.push_back(( static_cast<uint8_t> (mDoipTestParam.ToolAddress >> 8 ) & (0xFF)));  //DOIP tool address
	lMsg.push_back( static_cast<uint8_t>(( mDoipTestParam.ToolAddress) &0xFF)); //DOIP tool address
	lMsg.push_back( static_cast<uint8_t> (( mDoipTestParam.eculogicalAddress >> 8 ) & (0xFF)));  // ECU address
	lMsg.push_back( static_cast<uint8_t> (( mDoipTestParam.eculogicalAddress) &0xFF)); // ECU address

    lMsg.push_back( 0X22U);
    cout<<"ENTER DID_1"<<endl;
    if(scanf("%X",&did_1)<0){}
    lMsg.push_back(did_1);
    cout<<"ENTER DID_2"<<endl;
    if(scanf("%X",&did_2)<0){}
    lMsg.push_back(did_2);

    return 0;
}

int8_t CDoipTester::ProcessSeedKeyMsgs(std::vector<uint8_t> &lMsg,ESeedKeyRequests_t lReqType ,std::vector<uint8_t> lKeyValues)
{
    uint32_t length=0X6;
    if(lReqType ==  EsendKey || lReqType ==  ESendKey_Last )
    {
        length=0X8;
    }

    genDoipHeader(lMsg,length,EPayloadType_DiagnosticMessage);
	// PACK DOIP Address
	lMsg.push_back(( static_cast<uint8_t> (mDoipTestParam.ToolAddress >> 8 ) & (0xFF)));  //DOIP tool address
	lMsg.push_back( static_cast<uint8_t>(( mDoipTestParam.ToolAddress) &0xFF)); //DOIP tool address
	lMsg.push_back( static_cast<uint8_t> (( mDoipTestParam.eculogicalAddress >> 8 ) & (0xFF)));  // ECU address
	lMsg.push_back( static_cast<uint8_t> (( mDoipTestParam.eculogicalAddress) &0xFF)); // ECU address

	lMsg.push_back( 0X27U);  //Diagnostic Session Exit SID
    lMsg.push_back( lReqType); 



	// How to copy key values from one vector to another
	std::copy(lKeyValues.begin(),lKeyValues.end(),back_inserter(lMsg));


	return 0;

}

int8_t CDoipTester::ProcessTxDiagTransferMsgs(std::vector<uint8_t> &lMsg, EUdsDownload_t eUdsType)
{
	//cout<<"processdiagtransfer"<<endl;
	
	//genDoipHeader(lMsg,(DOIP_STACK_SIZE+4),EPayloadType_DiagnosticMessage);
	if(eUdsType==ERequestDownLoadReq)
	  genDoipHeader(lMsg,15,EPayloadType_DiagnosticMessage); 
	else if(eUdsType==ERequestTransferDataReq)
    	genDoipHeader(lMsg,571392+7,EPayloadType_DiagnosticMessage); //62kx9(refer lMaxBlockLengthNum)
	else 
	   genDoipHeader(lMsg,9,EPayloadType_DiagnosticMessage);

	// PACK DOIP Address
	lMsg.push_back(( static_cast<uint8_t> (mDoipTestParam.ToolAddress >> 8 ) & (0xFF)));  //DOIP tool address
	lMsg.push_back( static_cast<uint8_t>(( mDoipTestParam.ToolAddress) &0xFF)); //DOIP tool address
	lMsg.push_back( static_cast<uint8_t> (( mDoipTestParam.eculogicalAddress >> 8 ) & (0xFF)));  // ECU address
	lMsg.push_back( static_cast<uint8_t> (( mDoipTestParam.eculogicalAddress) &0xFF)); // ECU address

	// PACK UDS Address

	switch(eUdsType)
	{

		case ERequestDownLoadReq:

			// Pack data in UDS format
			lMsg.push_back( 0X34U);  //Reuest Download 0X34
			lMsg.push_back( 0x0U );  //Reuest Download 0X0 : Neither compression Nor Enryption
			lMsg.push_back( 0x44U ); // 4 BYTE Memory Size parameter  // 4 byte Memory Address parmeter
			/// Memory Address Parameter
			lMsg.push_back( 0x12U );
			lMsg.push_back( 0x44U );
			lMsg.push_back( 0x56U );
			lMsg.push_back( 0x78U );
			/// Memory Size Parameter : Memory size : 0x10 00 00 00 : 268 435 456 bytes
			/// 10 00 00 00 
			/*lMsg.push_back( 0x00U );
			lMsg.push_back( 0x1DU );
			lMsg.push_back( 0x10U );
			lMsg.push_back( 0x28U );*/

			lMsg.push_back( 0xE0U ); //3.5GB (3.5x1024x1024x1024)
			lMsg.push_back( 0x00U );
			lMsg.push_back( 0x00U );
			lMsg.push_back( 0x00U );
			break;

		case EFileTransferReq:
			break;

		case ERequestTransferDataReq:

			lMsg.push_back( 0X36U);  //TransferData Request SID
			lMsg.push_back( mBlockSeqCntr );  //BlockSequenceCntr
			lMsg.push_back( 0x44U ); // 4 BYTE Memory Size parameter  // 4 byte Memory Address parmeter
			cout<<"download size:"<<lMaxBlockLengthNum<<endl;
			memset(gSampleBuffer,'0',data_size);    //data size 62kx9                 
			//std::copy(&gSampleBuffer[0], &gSampleBuffer[380936], back_inserter(lMsg)); // copy the element to an vector
			std::copy(&gSampleBuffer[0], &gSampleBuffer[571392], back_inserter(lMsg)); // copy the element to an vector (62kx9)
			//std::copy(&gSampleBuffer[0], &gSampleBuffer[193536], back_inserter(lMsg)); // copy the element to an vector
			break;

		case ERequestTransferExitReq:

			lMsg.push_back( 0X37U);  //Transfer Exit SID
			lMsg.push_back( 0x0 );
			lMsg.push_back( 0x0 );
			lMsg.push_back( 0x0 );
			lMsg.push_back( 0x0 );
			break;

		case EDiagSessionCntrlReq:
			lMsg.push_back( 0X10U);  //Diagnostic Session Exit SID
			lMsg.push_back( 0X01U);  //Default session


			break;
		default:
			break;
	}

	return 0;
}



int8_t CDoipTester::DiagMessage_ReqTransfer(std::vector<uint8_t> &lMsg,uint8_t
        uminMax)
{
    if(uminMax==UDS_MinLenghtCheck)
    {
        genDoipHeader(lMsg,0x5,EPayloadType_DiagnosticMessage);
    }
    else
    {
	    genDoipHeader(lMsg,(4095),EPayloadType_DiagnosticMessage);
    }

	lMsg.push_back(( static_cast<uint8_t> (mDoipTestParam.ToolAddress >> 8 ) & (0xFF)));
	lMsg.push_back( static_cast<uint8_t>(( mDoipTestParam.ToolAddress) &0xFF));
	lMsg.push_back( static_cast<uint8_t> (( mDoipTestParam.eculogicalAddress >> 8 ) & (0xFF)));
	lMsg.push_back( static_cast<uint8_t> (( mDoipTestParam.eculogicalAddress) &0xFF));
    lMsg.push_back( 0X3EU);  //Diagnostic Session Exit SID
    if(uminMax!=UDS_MinLenghtCheck){
	lMsg.push_back( 0X00);  //Default session
    }

    if(uminMax!=UDS_MinLenghtCheck){
	std::copy(&gSampleBuffer[0], &gSampleBuffer[4089], back_inserter(lMsg)); // copy the element to an vector
    }


	return 0;
}





int8_t CDoipTester::genDoipHeader(std::vector<uint8_t> &lMsg,uint32_t len,EPayloadType_t doipMsgType)
{
	uint16_t lMsgType;

	lMsgType= doipMsgType;
	lMsg.push_back(0x2); // DOIP 2012 VERSION
	lMsg.push_back( 0XFD ); //DOIP VERSION
	lMsg.push_back( static_cast<uint8_t> (( lMsgType >> 8 ) & (0xFF)));
	lMsg.push_back( static_cast<uint8_t> (( lMsgType) &0xFF));
	lMsg.push_back( static_cast<uint8_t> ((len>> 24 )) & (0xFF));
	lMsg.push_back( static_cast<uint8_t>(( len >> 16)) & (0xff));
	lMsg.push_back(static_cast<uint8_t> ((len >> 8 )) & (0xFF));
	lMsg.push_back( static_cast<uint8_t>( len &0xFF));



	return 0;
}
int8_t CDoipTester::DoipTester_SendDiagMessageInfo(std::vector<uint8_t> &lMsg)
{
  

    for(uint8_t i= 0; i < sizeof(buffer_len); i++)
    {
    	buffer_len[i] = (uint8_t)i+1;
    }
	lMsg.push_back(( static_cast<uint8_t> (mDoipTestParam.ToolAddress >> 8 ) & (0xFF)));
	lMsg.push_back( static_cast<uint8_t>(( mDoipTestParam.ToolAddress) &0xFF));
	lMsg.push_back( static_cast<uint8_t> (( mDoipTestParam.eculogicalAddress >> 8 ) & (0xFF)));
	lMsg.push_back( static_cast<uint8_t> (( mDoipTestParam.eculogicalAddress) &0xFF));

	std::cout << "DOIP Diag message Creted> : Length(in Bytes) " << +sizeof(buffer_len)<< std::endl;
	 std::copy(&buffer_len[0], &buffer_len[64000], back_inserter(lMsg)); // copy the element to an vector
	

	return 0;
}



