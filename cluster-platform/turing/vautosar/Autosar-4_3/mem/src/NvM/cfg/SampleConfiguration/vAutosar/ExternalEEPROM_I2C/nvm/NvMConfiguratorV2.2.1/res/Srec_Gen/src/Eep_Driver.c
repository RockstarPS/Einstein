#ifndef EepDriver_C
#define EepDriver_C

#include "Eep_Driver.h"
#include "EepDrv.h"

#define BUSY 1u
#define IDLE 0u

#if DFLASH_MAX_SIZE_MB != 0
# define MAXIMUM_DFLASH_SIZE   (1024*1024*DFLASH_MAX_SIZE_MB)
#else
# define MAXIMUM_DFLASH_SIZE   (1024*1024*8) //8MB
#warning "Defined DFLASH size is 0 or is not defined. Using default size of 8MB..."
#endif

static uint8 *EepDataContent;
static uint8 EepResetVal;
static EepContentType EepContent;

static uint8 EepDriverState = IDLE;



void Eep_Driver_Init()
{
   uint32 eraseValue = 0xFFFFFFFF;
   EepDataContent = calloc(1, MAXIMUM_DFLASH_SIZE);
   if(NULL == EepDataContent)
   {
      
   }
   EepResetVal = (uint8)(0x000000FF & eraseValue);
}

void Eep_Driver_Free(void)
{
   if(EepDataContent != NULL)
   {
      free(EepDataContent);
   }
}

uint8 * Eep_Driver_getImage(void)
{
   return (uint8 *)&EepDataContent[0];
}

EepContentType * Eep_Driver_getMemMap(void)
{
   return (EepContentType *)&EepContent;
}

void EepDrv_Init(const EepDrv_ConfigType* ConfigPtr)
{
    uint32 idx;
    for(idx = 0; idx < MAXIMUM_DFLASH_SIZE; idx++)
    {
        EepDataContent[idx] = EepResetVal;
    }

    for(idx = 0; idx < MAXIMUM_MEMMAP_SIZE; idx++)
    {
        EepContent.info[idx].address = 0;
        EepContent.info[idx].size = 0;
    }
    EepContent.entries = 0;
}

void EepDrv_SetMode(MemIf_ModeType Mode)
{
    //Mode = Mode;
}

Std_ReturnType EepDrv_Read(EepDrv_AddressType EepromAddress, uint8* DataBufferPtr,EepDrv_LengthType Length)
{
    uint8  *targetAdd = (uint8 *)DataBufferPtr;
    uint32 idx;
    if(targetAdd != NULL)
    {
        for(idx = 0; idx < Length; idx++)
        {
            targetAdd[idx] = EepDataContent[idx + EepromAddress];
            EepDriverState = BUSY;
        }
    }
    return E_OK;
}

Std_ReturnType EepDrv_Write(EepDrv_AddressType EepromAddress,const uint8* DataBufferPtr,EepDrv_LengthType Length)
{
    uint32  idx;
   boolean found;

   for(idx = 0; idx < Length; idx++)
   {
      EepDataContent[idx + EepromAddress] = DataBufferPtr[idx];
   }

   found = FALSE;
   for(uint32 addr = 0; addr < EepContent.entries; addr++)
   {

      if(EepromAddress == (EepContent.info[addr].address + EepContent.info[addr].size))
      {
         EepContent.info[addr].size += Length;
         found = TRUE;
         break;
      }
   }

   if(FALSE == found)
   {
      for(uint32 addr = 0; addr < EepContent.entries; addr++)
      {
         if( (0 != EepContent.info[addr].address) &&
             (EepromAddress <= EepContent.info[addr].address) )
         {
            for(uint32 count = EepContent.entries; count > addr; count--)
            {
               EepContent.info[count].address = EepContent.info[count - 1].address;
               EepContent.info[count].size = EepContent.info[count - 1].size;
            }
            EepContent.info[addr].address = EepromAddress;
            EepContent.info[addr].size = Length;
            EepContent.entries++;
            found = TRUE;
            break;
         }

      }
   }
   if(FALSE == found)
   {
      EepContent.info[EepContent.entries].address = EepromAddress;
      EepContent.info[EepContent.entries].size = Length;
      if(EepContent.entries < MAXIMUM_MEMMAP_SIZE)
      {
         EepContent.entries++;
      }
      
   }

   for(uint32 addr = 0; addr < EepContent.entries; addr++)
   {

      if( EepContent.info[addr + 1].address == (EepContent.info[addr].address + EepContent.info[addr].size) )
      { 
         EepContent.info[addr].size += EepContent.info[addr + 1].size;
         for(uint32 count = (addr + 1); count < EepContent.entries; count++)
         {
            EepContent.info[count].address = EepContent.info[count + 1].address;
            EepContent.info[count].size = EepContent.info[count + 1].size;
         }
         EepContent.entries--;
         break;
         
      }
   }
   EepDriverState = BUSY;
   return E_OK;
}

Std_ReturnType EepDrv_Erase(EepDrv_AddressType EepromAddress, EepDrv_LengthType Length)
{
    uint32 idx;
   for(idx = EepromAddress; idx < (EepromAddress + Length); idx++)
   {
      EepDataContent[idx] = EepResetVal;
   }

   for(idx = 0; idx < EepContent.entries; idx++)
   {
      if( (EepContent.info[idx].address >= EepromAddress) &&
          (EepContent.info[idx].address < (EepromAddress + Length)) )
      {
         EepContent.info[idx].address = 0;
         EepContent.info[idx].size = 0;

         for(uint32 count = idx; count < EepContent.entries; count++)
         {
            EepContent.info[count].address = EepContent.info[count + 1].address;
            EepContent.info[count].size = EepContent.info[count + 1].size;
         }
         
         if(EepContent.entries > 0)
         {
            EepContent.entries--;
         }
         
      }
   }
   EepDriverState = BUSY;
   return E_OK;
}

Std_ReturnType EepDrv_Compare(EepDrv_AddressType EepromAddress,const uint8* DataBufferPtr,EepDrv_LengthType Length)
{
    Std_ReturnType LenReturnValue = E_OK;
   uint8  *targetAdd =DataBufferPtr;
   uint32 idx;

   if(targetAdd != NULL)
   {
      for(idx = 0; idx < Length; idx++)
      {
         if(targetAdd[idx] != EepDataContent[idx + EepromAddress])
         {
            LenReturnValue = E_NOT_OK;
            break;
         }
      }
   }  
  EepDriverState = BUSY;
  return(LenReturnValue);
}

void EepDrv_Cancel (void)
{
    return;
}

MemIf_StatusType EepDrv_GetStatus(void)
{
    return MEMIF_IDLE;
}

MemIf_JobResultType EepDrv_GetJobResult(void)
{
    return MEMIF_JOB_OK;
}

void EepDrv_MainFunction(void)
{
   if (EepDriverState == BUSY)
   {
      Ea_JobEndNotification();
      EepDriverState = IDLE;
   }

}

#endif