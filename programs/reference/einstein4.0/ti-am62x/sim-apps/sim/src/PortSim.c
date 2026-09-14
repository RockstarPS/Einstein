#include <windows.h>

void IOHWABSetADChannelValue(unsigned char pAdcID, int pAdvalue);

void IOHWABSetDigitalInputChannelValue(unsigned char pDigigID, unsigned char pDigiValue);


DWORD WINAPI f_test_box_thread(LPVOID lp_transmit_handler);

void fbutton_Simulation_init(void)
{
	printf("Simulation started \n");
	HANDLE thread = CreateThread(NULL, 0, f_test_box_thread, NULL, 0, NULL);		

}
typedef struct
{
    void* hFileMap;
    void* pData;
    char MapName[256];
    size_t Size;
} SharedMemory;

unsigned char CreateMemoryMap(SharedMemory* shm)
{
    if ((shm->hFileMap = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, shm->Size, shm->MapName)) == NULL)
    {
        return 0;
    }

    if ((shm->pData = MapViewOfFile(shm->hFileMap, FILE_MAP_ALL_ACCESS, 0, 0, shm->Size)) == NULL)
    {
        CloseHandle(shm->hFileMap);
        return 0;
    }
    return 1;
}

unsigned char FreeMemoryMap(SharedMemory* shm)
{
    if (shm && shm->hFileMap)
    {
        if (shm->pData)
        {
            UnmapViewOfFile(shm->pData);
        }

        if (shm->hFileMap)
        {
            CloseHandle(shm->hFileMap);
        }
		printf("Shared Mem created successfully \n");
        return 1;
    }
    return 0;
}

unsigned short gl_ports_data[512];
unsigned char count;
unsigned char value_index;

void fUpdatePortValues(unsigned short *shr_ptr,unsigned short pSize)
{
  unsigned char flCount =0;
  for(flCount = 0; flCount <pSize; flCount++ )
  {
	  Dio_WriteChannel(shr_ptr[flCount],shr_ptr[flCount+1]);
  }
}

void fUpdateA2DValues(unsigned short *shr_ptr,unsigned short pSize)
{
	unsigned char flCount =0;
	for(flCount = 0; flCount <pSize; flCount++ )
	{
		// Adc_UpdateValues(shr_ptr[flCount],shr_ptr[flCount+1]	);
	}
}

DWORD WINAPI f_test_box_thread(LPVOID lp_transmit_handler)
{
    SharedMemory shm = {0};
    shm.Size = 512;
    unsigned short lCommand;
    unsigned short lSize;
    unsigned short lPortId;
    unsigned short lvalue;
    unsigned short lptridx;

    sprintf(shm.MapName, "Local\\SharedMemory");
    if (CreateMemoryMap(&shm))
    {
		printf("SHM creating success \n");
        unsigned short * ptr = (unsigned short*)shm.pData;
        memset(ptr, 0, shm.Size);
		while(1)
		{
			memcpy(gl_ports_data,ptr,512);
			lptridx =1;
			lCommand =gl_ports_data[lptridx];
			lSize = gl_ports_data[lptridx+1];

			if(lCommand == 0x7FAA)
			{
				fUpdatePortValues(&gl_ports_data[lptridx+2],lSize);
			}
			lptridx += 2+ (lSize*2);

			lCommand =gl_ports_data[lptridx];
			lSize = gl_ports_data[lptridx+1];
			if(lCommand == 0x7FBB)
			{
				fUpdateA2DValues(&gl_ports_data[lptridx+2],lSize);
			}
			lptridx += (2+ (lSize*2));

			lCommand =gl_ports_data[lptridx];
			lSize = gl_ports_data[lptridx+1];
			if(lCommand == 0x7FCC)
			{
				fUpdatePortValues(&gl_ports_data[lptridx+2],lSize);
			}
			lptridx += (2+ (lSize*2));



			Sleep(10);
		}
       
   
    }
	else
	{
		printf("SHM creating failed \n");
	}
	Sleep(2000);
}


