#define NOCRYPT 
#define NOGDI
#include "WinAbstraction.h"
#include <stdio.h>
#undef FAR
#define OS_TRAP_H
#include "Os.h"
#include "OsPrivate.h"

typedef  void (*lTaskThreadPtr) (void);

#if OsNumberOfTasks > 0
	void OSTaskThread_0(void);
#endif	

#if OsNumberOfTasks > 1
	void OSTaskThread_1(void);
#endif	
#if OsNumberOfTasks > 2
	void OSTaskThread_2(void);
#endif	
#if OsNumberOfTasks > 3
	void OSTaskThread_3(void);
#endif	
#if OsNumberOfTasks > 4
	void OSTaskThread_4(void);
#endif	
#if OsNumberOfTasks > 5
	void OSTaskThread_5(void);
#endif	
#if OsNumberOfTasks > 6
	void OSTaskThread_6(void);
#endif	
#if OsNumberOfTasks > 7
	void OSTaskThread_7(void);
#endif	
#if OsNumberOfTasks > 8
	void OSTaskThread_8(void);
#endif	
#if OsNumberOfTasks > 9
	void OSTaskThread_9(void);
#endif	
#if OsNumberOfTasks > 10
	void OSTaskThread_10(void);
#endif	
#if OsNumberOfTasks > 11
	void OSTaskThread_11(void);
#endif	
#if OsNumberOfTasks > 12
	void OSTaskThread_12(void);
#endif	
#if OsNumberOfTasks > 13
	void OSTaskThread_13(void);
#endif	
#if OsNumberOfTasks > 14
	void OSTaskThread_14(void);
#endif	
#if OsNumberOfTasks > 15
	void OSTaskThread_15(void);
#endif	
#if OsNumberOfTasks > 16
	void OSTaskThread_16(void);
#endif	
#if OsNumberOfTasks > 17
	void OSTaskThread_17(void);
#endif	
#if OsNumberOfTasks > 18
	void OSTaskThread_18(void);
#endif	
#if OsNumberOfTasks > 19
	void OSTaskThread_19(void);
#endif	
#if OsNumberOfTasks > 20
	void OSTaskThread_20(void);
#endif	
#if OsNumberOfTasks > 21
	void OSTaskThread_21(void);
#endif	
#if OsNumberOfTasks > 22
	void OSTaskThread_22(void);
#endif	
#if OsNumberOfTasks > 23
	void OSTaskThread_23(void);
#endif	

#if OsNumberOfTasks > 24
	void OSTaskThread_24(void);
#endif	


#if OsNumberOfTasks > 25
	void OSTaskThread_25(void);
#endif	
#if OsNumberOfTasks > 26
	void OSTaskThread_26(void);
#endif	
#if OsNumberOfTasks > 27
	void OSTaskThread_27(void);
#endif	
#if OsNumberOfTasks > 28
	void OSTaskThread_28(void);
#endif	
#if OsNumberOfTasks > 29
	void OSTaskThread_29(void);
#endif	
#if OsNumberOfTasks > 30
	void OSTaskThread_30(void);
#endif	
#if OsNumberOfTasks > 31
	void OSTaskThread_31(void);
#endif	

#if OsNumberOfTasks > 32
	void OSTaskThread_32(void);
#endif

#if OsNumberOfTasks > 33
	void OSTaskThread_33(void);
#endif
#if OsNumberOfTasks > 34
	void OSTaskThread_34(void);
#endif
#if OsNumberOfTasks > 35
	void OSTaskThread_35(void);
#endif

#if OsNumberOfTasks > 36
	void OSTaskThread_36(void);
#endif
#if OsNumberOfTasks > 37
	void OSTaskThread_37(void);
#endif
#if OsNumberOfTasks > 38
	void OSTaskThread_38(void);
#endif
#if OsNumberOfTasks > 39
	void OSTaskThread_39(void);
#endif
#if OsNumberOfTasks > 40
	void OSTaskThread_40(void);
#endif
#if OsNumberOfTasks > 41
	void OSTaskThread_41(void);
#endif
#if OsNumberOfTasks > 42
	void OSTaskThread_42(void);
#endif
#if OsNumberOfTasks > 43
	void OSTaskThread_43(void);
#endif
const lTaskThreadPtr lThreadPtrArray[] = 
{
	#if OsNumberOfTasks > 0
		OSTaskThread_0,
	#endif	
	#if OsNumberOfTasks > 1
		OSTaskThread_1,
	#endif	

	#if OsNumberOfTasks > 2
		OSTaskThread_2,
	#endif	

	#if OsNumberOfTasks > 3
		OSTaskThread_3,
	#endif	

	#if OsNumberOfTasks > 4
		OSTaskThread_4,
	#endif	

	#if OsNumberOfTasks > 5
		OSTaskThread_5,
	#endif	
	#if OsNumberOfTasks > 6
		OSTaskThread_6,
	#endif	
	#if OsNumberOfTasks > 7
		OSTaskThread_7,
	#endif	
	#if OsNumberOfTasks > 8
		OSTaskThread_8,
	#endif	
	#if OsNumberOfTasks > 9
		OSTaskThread_9,
	#endif	
	#if OsNumberOfTasks > 10
		OSTaskThread_10,
	#endif	
	#if OsNumberOfTasks > 11
		OSTaskThread_11,
	#endif	
	#if OsNumberOfTasks > 12
		OSTaskThread_12,
	#endif	
	#if OsNumberOfTasks > 13
		OSTaskThread_13,
	#endif	
	#if OsNumberOfTasks > 14
		OSTaskThread_14,
	#endif	

	#if OsNumberOfTasks > 15
		OSTaskThread_15,
	#endif	
	#if OsNumberOfTasks > 16
		OSTaskThread_16,
	#endif	
	#if OsNumberOfTasks > 17
		OSTaskThread_17,
	#endif	
	#if OsNumberOfTasks > 18
		OSTaskThread_18,
	#endif	
	#if OsNumberOfTasks > 19
		OSTaskThread_19,
	#endif	
	#if OsNumberOfTasks > 20
		OSTaskThread_20,
	#endif	
	#if OsNumberOfTasks > 21
		OSTaskThread_21,
	#endif	
	#if OsNumberOfTasks > 22
		OSTaskThread_22,
	#endif	
	#if OsNumberOfTasks > 23
		OSTaskThread_23,
	#endif	

	#if OsNumberOfTasks > 24
		OSTaskThread_24,
	#endif	

	#if OsNumberOfTasks > 25
		OSTaskThread_25,
	#endif	

	#if OsNumberOfTasks > 26
		OSTaskThread_26,
	#endif	

	#if OsNumberOfTasks > 27
		OSTaskThread_27,
	#endif	

	#if OsNumberOfTasks > 28
		OSTaskThread_28,
	#endif	

	#if OsNumberOfTasks > 29
		OSTaskThread_29,
	#endif	

	#if OsNumberOfTasks > 30
		OSTaskThread_30,
	#endif	

	#if OsNumberOfTasks > 31
		OSTaskThread_31,
	#endif	

	#if OsNumberOfTasks > 32
		OSTaskThread_32,
	#endif	
	
	#if OsNumberOfTasks > 33
		OSTaskThread_33,
	#endif	
	
	#if OsNumberOfTasks > 34
		OSTaskThread_34,
	#endif	

	#if OsNumberOfTasks > 35
		OSTaskThread_35,
	#endif	

	#if OsNumberOfTasks > 36
		OSTaskThread_36,
	#endif	

	#if OsNumberOfTasks > 37
		OSTaskThread_37,
	#endif	

	#if OsNumberOfTasks > 38
		OSTaskThread_38,
	#endif	

	#if OsNumberOfTasks > 39
		OSTaskThread_39,
	#endif	
	#if OsNumberOfTasks > 40
		OSTaskThread_40,
	#endif	

	#if OsNumberOfTasks > 41
		OSTaskThread_41,
	#endif	
	
	#if OsNumberOfTasks > 42
		OSTaskThread_42,
	#endif	

	#if OsNumberOfTasks > 43
		OSTaskThread_43,
	#endif	


};
HANDLE lEventHandle  [OsNumberOfTasks];
HANDLE lThreadHandle [OsNumberOfTasks];
DWORD lTaskThreadId[OsNumberOfTasks];
void CreateEventAndThreads(void)
{
	int fl_cnt = 0; 
	
	for (fl_cnt = 0; fl_cnt <  OsNumberOfTasks;fl_cnt++)
	{
		lEventHandle[fl_cnt ] = CreateEvent(NULL, FALSE, FALSE, NULL);
		
		lThreadHandle[fl_cnt] = CreateThread(
        NULL,               // Default security attributes
        0,                  // Default stack size
        lThreadPtrArray[fl_cnt],         // Thread start address (entry point)
        NULL,               // Parameter to the thread function
        0,   // Start the thread in a suspended state
        &lTaskThreadId[fl_cnt]                // Ignore the thread ID
											);
	}
}

#if OsNumberOfTasks > 0
void OSTaskThread_0(void)
{
	WaitForSingleObject(lEventHandle[0],INFINITE);
	
	if(TcbTaskRefConfig[0]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[0]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[0]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 1
void OSTaskThread_1(void)
{
	WaitForSingleObject(lEventHandle[1],INFINITE);
	
	if(TcbTaskRefConfig[1]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[1]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[1]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 2
void OSTaskThread_2(void)
{
	WaitForSingleObject(lEventHandle[2],INFINITE);
	
	if(TcbTaskRefConfig[2]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[2]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[2]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 3
void OSTaskThread_3(void)
{
	WaitForSingleObject(lEventHandle[3],INFINITE);
	
	if(TcbTaskRefConfig[3]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[3]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[3]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 4
void OSTaskThread_4(void)
{
	WaitForSingleObject(lEventHandle[4],INFINITE);
	
	if(TcbTaskRefConfig[4]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[4]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[4]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 5
void OSTaskThread_5(void)
{
	WaitForSingleObject(lEventHandle[5],INFINITE);
	
	if(TcbTaskRefConfig[5]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[5]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[5]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 6
void OSTaskThread_6(void)
{
	WaitForSingleObject(lEventHandle[6],INFINITE);
	
	if(TcbTaskRefConfig[6]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[6]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[6]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 7
void OSTaskThread_7(void)
{
	WaitForSingleObject(lEventHandle[7],INFINITE);
	
	if(TcbTaskRefConfig[7]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[7]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[7]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 8
void OSTaskThread_8(void)
{
	WaitForSingleObject(lEventHandle[8],INFINITE);
	
	if(TcbTaskRefConfig[8]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[8]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[8]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 9
void OSTaskThread_9(void)
{
	WaitForSingleObject(lEventHandle[9],INFINITE);
	
	if(TcbTaskRefConfig[9]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[9]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[9]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 10
void OSTaskThread_10(void)
{
	WaitForSingleObject(lEventHandle[10],INFINITE);
	
	if(TcbTaskRefConfig[10]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[10]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[10]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 11
void OSTaskThread_11(void)
{
	WaitForSingleObject(lEventHandle[11],INFINITE);
	
	if(TcbTaskRefConfig[11]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[11]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[11]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 12
void OSTaskThread_12(void)
{
	WaitForSingleObject(lEventHandle[12],INFINITE);
	
	if(TcbTaskRefConfig[12]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[12]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[12]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 13
void OSTaskThread_13(void)
{
	WaitForSingleObject(lEventHandle[13],INFINITE);
	
	if(TcbTaskRefConfig[13]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[13]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[13]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 14
void OSTaskThread_14(void)
{
	WaitForSingleObject(lEventHandle[14],INFINITE);
	
	if(TcbTaskRefConfig[14]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[14]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[14]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 15
void OSTaskThread_15(void)
{
	WaitForSingleObject(lEventHandle[15],INFINITE);
	
	if(TcbTaskRefConfig[15]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[15]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[15]->TaskStartAddress();
		}
	}
}
#endif
#if OsNumberOfTasks > 16
void OSTaskThread_16(void)
{
	WaitForSingleObject(lEventHandle[16],INFINITE);
	
	if(TcbTaskRefConfig[16]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[16]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[16]->TaskStartAddress();
		}
	}
}
#endif
#if OsNumberOfTasks > 17
void OSTaskThread_17(void)
{
	WaitForSingleObject(lEventHandle[17],INFINITE);
	
	if(TcbTaskRefConfig[17]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[17]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[17]->TaskStartAddress();
		}
	}
}
#endif
#if OsNumberOfTasks > 18
void OSTaskThread_18(void)
{
	WaitForSingleObject(lEventHandle[18],INFINITE);
	
	if(TcbTaskRefConfig[18]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[18]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[18]->TaskStartAddress();
		}
	}
}
#endif
#if OsNumberOfTasks > 19
void OSTaskThread_19(void)
{
	WaitForSingleObject(lEventHandle[19],INFINITE);
	
	if(TcbTaskRefConfig[19]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[19]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[19]->TaskStartAddress();
		}
	}
}
#endif
#if OsNumberOfTasks > 20
void OSTaskThread_20(void)
{
	WaitForSingleObject(lEventHandle[20],INFINITE);
	
	if(TcbTaskRefConfig[20]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[20]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[20]->TaskStartAddress();
		}
	}
}
#endif
#if OsNumberOfTasks > 21
void OSTaskThread_21(void)
{
	WaitForSingleObject(lEventHandle[21],INFINITE);
	
	if(TcbTaskRefConfig[21]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[21]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[21]->TaskStartAddress();
		}
	}
}
#endif
#if OsNumberOfTasks > 22
void OSTaskThread_22(void)
{
	WaitForSingleObject(lEventHandle[22],INFINITE);
	
	if(TcbTaskRefConfig[22]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[22]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[22]->TaskStartAddress();
		}
	}
}
#endif
#if OsNumberOfTasks > 23
void OSTaskThread_23(void)
{
	WaitForSingleObject(lEventHandle[23],INFINITE);
	
	if(TcbTaskRefConfig[23]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[23]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[23]->TaskStartAddress();
		}
	}
}
#endif
#if OsNumberOfTasks > 24
void OSTaskThread_24(void)
{
	WaitForSingleObject(lEventHandle[24],INFINITE);
	
	if(TcbTaskRefConfig[24]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[24]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[24]->TaskStartAddress();
		}
	}
}
#endif
#if OsNumberOfTasks > 25
void OSTaskThread_25(void)
{
	WaitForSingleObject(lEventHandle[25],INFINITE);
	
	if(TcbTaskRefConfig[25]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[25]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[25]->TaskStartAddress();
		}
	}
}
#endif
#if OsNumberOfTasks > 26
void OSTaskThread_26(void)
{
	WaitForSingleObject(lEventHandle[26],INFINITE);
	
	if(TcbTaskRefConfig[26]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[26]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[26]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 27
void OSTaskThread_27(void)
{
	WaitForSingleObject(lEventHandle[27],INFINITE);
	
	if(TcbTaskRefConfig[27]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[27]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[27]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 28
void OSTaskThread_28(void)
{
	WaitForSingleObject(lEventHandle[28],INFINITE);
	
	if(TcbTaskRefConfig[28]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[28]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[28]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 29
void OSTaskThread_29(void)
{
	WaitForSingleObject(lEventHandle[29],INFINITE);
	
	if(TcbTaskRefConfig[29]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[29]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[29]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 30
void OSTaskThread_30(void)
{
	WaitForSingleObject(lEventHandle[30],INFINITE);
	
	if(TcbTaskRefConfig[30]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[30]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[30]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 31
void OSTaskThread_31(void)
{
	WaitForSingleObject(lEventHandle[31],INFINITE);
	
	if(TcbTaskRefConfig[31]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[31]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[31]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 32
void OSTaskThread_32(void)
{
	WaitForSingleObject(lEventHandle[32],INFINITE);
	
	if(TcbTaskRefConfig[32]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[32]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[32]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 33
void OSTaskThread_33(void)
{
	WaitForSingleObject(lEventHandle[33],INFINITE);
	
	if(TcbTaskRefConfig[33]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[33]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[33]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 34
void OSTaskThread_34(void)
{
	WaitForSingleObject(lEventHandle[34],INFINITE);
	
	if(TcbTaskRefConfig[34]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[34]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[34]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 35
void OSTaskThread_35(void)
{
	WaitForSingleObject(lEventHandle[35],INFINITE);
	
	if(TcbTaskRefConfig[35]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[35]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[35]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 36
void OSTaskThread_36(void)
{
	WaitForSingleObject(lEventHandle[36],INFINITE);
	
	if(TcbTaskRefConfig[36]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[36]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[36]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 37
void OSTaskThread_37(void)
{
	WaitForSingleObject(lEventHandle[37],INFINITE);
	
	if(TcbTaskRefConfig[37]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[37]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[37]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 38
void OSTaskThread_38(void)
{
	WaitForSingleObject(lEventHandle[38],INFINITE);
	
	if(TcbTaskRefConfig[38]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[38]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[38]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 39
void OSTaskThread_39(void)
{
	WaitForSingleObject(lEventHandle[39],INFINITE);
	
	if(TcbTaskRefConfig[39]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[39]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[39]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 40
void OSTaskThread_40(void)
{
	WaitForSingleObject(lEventHandle[40],INFINITE);
	
	if(TcbTaskRefConfig[40]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[40]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[40]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 41
void OSTaskThread_41(void)
{
	WaitForSingleObject(lEventHandle[41],INFINITE);
	
	if(TcbTaskRefConfig[41]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[41]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[41]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 42
void OSTaskThread_42(void)
{
	WaitForSingleObject(lEventHandle[42],INFINITE);
	
	if(TcbTaskRefConfig[42]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[42]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[42]->TaskStartAddress();
		}
	}
}
#endif

#if OsNumberOfTasks > 43
void OSTaskThread_43(void)
{
	WaitForSingleObject(lEventHandle[43],INFINITE);
	
	if(TcbTaskRefConfig[43]->TasksType == TASK_EXTENDED)
	{
		TcbTaskRefConfig[43]->TaskStartAddress();
	}
	else
	{
		/*This is a basic task */
		while(1)
		{
			TcbTaskRefConfig[43]->TaskStartAddress();
		}
	}
}
#endif
