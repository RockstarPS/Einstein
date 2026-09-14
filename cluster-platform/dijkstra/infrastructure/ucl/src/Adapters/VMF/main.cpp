///---------------------------------------------------------------------------------------------------------------------
///
/// VISTEON CORPORATION CONFIDENTIAL
/// ________________________________
///
/// [2017] Visteon Corporation
/// All Rights Reserved.
///
/// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
/// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
/// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
/// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
/// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
/// under all copyright laws to protect this work as a published work, when appropriate.
/// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
/// without the written authorization of Visteon Corporation.
///
///---------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <chrono>
#include <csignal>
#include <thread>
#include <errno.h>
#if (defined(__QNX__))
#include <sys/procmgr.h>
#include <login.h>
#endif
#include "UclVmfProxy.hpp"

static bool bRequestUclVmfExit;

void exit_handler(const int s)
{
    std::cout << "Ucl VMF Proxy Exiting...Rcvd " << s << std::endl; //MISRA C++-2008 Rule 0-1-11, CID - 10722858
    bRequestUclVmfExit = true;
}

static Ucl_ReturnType acquire_ability()
{
	Ucl_ReturnType Ret = UCL_E_NOK;
	sint32 RetVal = UCL_E_NOK; 

#if (defined(__QNX__) && (_NTO_VERSION >= 660))
	RetVal = procmgr_ability( 0,
		PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_IO,
		PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_MEM_PHYS,
		PROCMGR_AOP_DENY  | PROCMGR_ADN_NONROOT | PROCMGR_AOP_LOCK | PROCMGR_AID_EOL);
#endif	

	if( RetVal != EOK)
	{
		std::cout << "ucl_proxy_vmf: Failed to Acquire Abilities. " << "Error : " << RetVal << std::endl;
	}
	else
	{
		std::cout << "ucl_proxy_vmf: Abilities Acquired Successfully" << std::endl;
		Ret = UCL_E_OK;
	}
	
	return Ret;
}

static Ucl_ReturnType drop_ability()
{
	Ucl_ReturnType Ret = UCL_E_NOK;
	sint32 RetVal =  UCL_E_NOK; 
	
#if (defined(__QNX__) && (_NTO_VERSION >= 660))
	RetVal = procmgr_ability( 0,
		PROCMGR_AOP_DENY | PROCMGR_ADN_NONROOT | PROCMGR_AOP_LOCK | PROCMGR_AID_IO,
		PROCMGR_AOP_DENY | PROCMGR_ADN_NONROOT | PROCMGR_AOP_LOCK | PROCMGR_AID_MEM_PHYS,
		PROCMGR_AID_EOL);
#endif	
	if( RetVal != EOK)
	{
		std::cout << "ucl_proxy_vmf: Failed to Drop Abilities. " << "Error : " << RetVal << std::endl;
	}
	else
	{
		std::cout << "ucl_proxy_vmf: Abilities Drop Successfully" << std::endl;
		Ret = UCL_E_OK;
	}
	
	return Ret;
}

static Ucl_ReturnType switch_to_user_mode( const char *userParam )
{
	Ucl_ReturnType Ret = UCL_E_OK;

#if (defined(__QNX__) && (_NTO_VERSION >= 660))	
	if(set_ids_from_arg( userParam ) != EOK)
	{
		if ( __get_errno_ptr() != NULL_PTR )
		{
			std::cout << "ucl_proxy_vmf: Unable to drop to user " << userParam << "Error = " << strerror(errno) << std::endl;
		}
		else
		{
			std::cout << "ucl_proxy_vmf: Unable to drop to user " << userParam << std::endl;
		}
		Ret = UCL_E_NOK;
	}
	else
	{
		std::cout << "ucl_proxy_vmf: Switch to user " << userParam << "  successfull" << std::endl;
	}
#endif
	
	return Ret;
}

static void get_options( const int argc, char * const argv[], char **const userParm )
{
    sint32 Option;
  
	while ((Option = getopt(argc, argv, "U:")) != -1)
		{
            switch (Option)
			{
                case 'U':
				    // Free memory if userParm already points to allocated memory
                    if (*userParm != nullptr)
					{
                        free(*userParm);
                    }
                    *userParm = strdup(optarg);
					break;
				case '?':
					std::cout << "ucl_proxy_vmf: Rcvd Invalid Command Line Option" << std::endl;				
					break;
				default:
					std::cout << "ucl_proxy_vmf: Invalid Option "  << std::endl;
					break;
            }
        }
    
}

int main(int argc, char *argv[])
{
    Ucl_ReturnType Ret;
	char *UserParm = NULL;

	get_options(argc, argv, &UserParm);
	
	//Acquire procmgr ability
	if (UserParm != NULL)
    {
		Ret = acquire_ability();	
	
		//Drop-Root Priviledge
		if (UCL_E_OK == Ret)
		{
			 Ret = switch_to_user_mode(UserParm);
		}
	}
	
	Ret = CUclVmfProxy::getInstance().start();
	
	//Drop procmgr ability
	if ( UserParm != NULL_PTR )
    {
		Ret = drop_ability();
		
		free( UserParm );
	}
	
    if (UCL_E_OK == Ret)
    {
        bRequestUclVmfExit = false;

		if( std::signal(SIGINT, &exit_handler) == SIG_ERR )  // MISRA C++-2008 Rule 0-3-2, CID - 16860470
															// MISRA C++-2008 Rule 0-1-7, CID - 12252554 
		{
			#if defined(__QNX__)
			if ( __get_errno_ptr() != NULL_PTR )
			#endif
			{
				std::cout << "ucl_proxy_vmf Failed to register SIGINT handler err = " << errno << std::endl;
			}
			#if defined(__QNX__)
			else
			{
				std::cout << "ucl_proxy_vmf Failed to register SIGINT handler" << std::endl;
			}
			#endif
		}

        while (!bRequestUclVmfExit)
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

			(void)CUclVmfProxy::getInstance().stop(); //MISRA C++-2008 Rule 0-1-7, CID - 12256170

        //std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    else
    {
        std::cout << "Ucl VMF Proxy Start Failed" << std::endl;
    }
	
	 std::cout << "ucl_proxy_vmf Exiting..." << std::endl;
	 
    return 0;
}
