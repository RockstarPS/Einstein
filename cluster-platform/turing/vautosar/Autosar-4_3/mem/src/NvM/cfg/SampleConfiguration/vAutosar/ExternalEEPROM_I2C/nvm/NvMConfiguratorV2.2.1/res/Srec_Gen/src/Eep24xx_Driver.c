#ifndef EepDriver_C
#define EepDriver_C

#include "Eep24xx_Driver.h"
#include "Eep24xx.h"

#if DFLASH_MAX_SIZE_MB != 0
# define MAXIMUM_DFLASH_SIZE   (1024*1024*DFLASH_MAX_SIZE_MB)
#else
# define MAXIMUM_DFLASH_SIZE   (1024*1024*8) //8MB
#warning "Defined DFLASH size is 0 or is not defined. Using default size of 8MB..."
#endif

static uint8 *Eep24xxDataContent = NULL;
static uint8 Eep24xxResetVal;
static Eep24xxContentType Eep24xxContent;

void Eep24xx_Driver_Init()
{
   uint32 eraseValue = 0xFFFFFFFF;
   Eep24xxDataContent = calloc(1, MAXIMUM_DFLASH_SIZE);
   if(NULL == Eep24xxDataContent)
   {
      
   }
   Eep24xxResetVal = (uint8)(0x000000FF & eraseValue);
}

void Eep24xx_Driver_Free(void)
{
   if(Eep24xxDataContent != NULL)
   {
      free(Eep24xxDataContent);
   }
}

uint8 * Eep24xx_Driver_getImage(void)
{
   return (uint8 *)&Eep24xxDataContent[0];
}

Eep24xxContentType * Eep24xx_Driver_getMemMap(void)
{
   return (Eep24xxContentType *)&Eep24xxContent;
}
void Eep24xx_Init(const Eep24xx_ConfigType* ConfigPtr)
{
    uint32 idx;
    for(idx = 0; idx < MAXIMUM_DFLASH_SIZE; idx++)
    {
        Eep24xxDataContent[idx] = Eep24xxResetVal;
    }

    for(idx = 0; idx < MAXIMUM_MEMMAP_SIZE; idx++)
    {
        Eep24xxContent.info[idx].address = 0;
        Eep24xxContent.info[idx].size = 0;
    }
    Eep24xxContent.entries = 0;
}

void Eep24xx_SetMode(MemIf_ModeType Mode)
{
    //Mode = Mode;
}

Std_ReturnType Eep24xx_Read(Eep24xx_AddressType EepromAddress, uint8* DataBufferPtr,Eep24xx_LengthType Length)
{
    uint8  *targetAdd = (uint8 *)DataBufferPtr;
    uint32 idx;
    if(targetAdd != NULL)
    {
        for(idx = 0; idx < Length; idx++)
        {
            targetAdd[idx] = Eep24xxDataContent[idx + EepromAddress];
        }
    }
    return E_OK;
}

Std_ReturnType Eep24xx_Write(Eep24xx_AddressType EepromAddress,const uint8* DataBufferPtr,Eep24xx_LengthType Length)
{
    uint32  idx;
   boolean found;

   for(idx = 0; idx < Length; idx++)
   {
      Eep24xxDataContent[idx + EepromAddress] = DataBufferPtr[idx];
   }

   found = FALSE;
   for(uint32 addr = 0; addr < Eep24xxContent.entries; addr++)
   {

      if(EepromAddress == (Eep24xxContent.info[addr].address + Eep24xxContent.info[addr].size))
      {
         Eep24xxContent.info[addr].size += Length;
         found = TRUE;
         break;
      }
   }

   if(FALSE == found)
   {
      for(uint32 addr = 0; addr < Eep24xxContent.entries; addr++)
      {
         if( (0 != Eep24xxContent.info[addr].address) &&
             (EepromAddress <= Eep24xxContent.info[addr].address) )
         {
            for(uint32 count = Eep24xxContent.entries; count > addr; count--)
            {
               Eep24xxContent.info[count].address = Eep24xxContent.info[count - 1].address;
               Eep24xxContent.info[count].size = Eep24xxContent.info[count - 1].size;
            }
            Eep24xxContent.info[addr].address = EepromAddress;
            Eep24xxContent.info[addr].size = Length;
            Eep24xxContent.entries++;
            found = TRUE;
            break;
         }

      }
   }
   if(FALSE == found)
   {
      Eep24xxContent.info[Eep24xxContent.entries].address = EepromAddress;
      Eep24xxContent.info[Eep24xxContent.entries].size = Length;
      if(Eep24xxContent.entries < MAXIMUM_MEMMAP_SIZE)
      {
         Eep24xxContent.entries++;
      }
      
   }

   for(uint32 addr = 0; addr < Eep24xxContent.entries; addr++)
   {

      if( Eep24xxContent.info[addr + 1].address == (Eep24xxContent.info[addr].address + Eep24xxContent.info[addr].size) )
      { 
         Eep24xxContent.info[addr].size += Eep24xxContent.info[addr + 1].size;
         for(uint32 count = (addr + 1); count < Eep24xxContent.entries; count++)
         {
            Eep24xxContent.info[count].address = Eep24xxContent.info[count + 1].address;
            Eep24xxContent.info[count].size = Eep24xxContent.info[count + 1].size;
         }
         Eep24xxContent.entries--;
         break;
         
      }
   }

   return E_OK;
}

Std_ReturnType Eep24xx_Erase(Eep24xx_AddressType EepromAddress, Eep24xx_LengthType Length)
{
    uint32 idx;
   for(idx = EepromAddress; idx < (EepromAddress + Length); idx++)
   {
      Eep24xxDataContent[idx] = Eep24xxResetVal;
   }

   for(idx = 0; idx < Eep24xxContent.entries; idx++)
   {
      if( (Eep24xxContent.info[idx].address >= EepromAddress) &&
          (Eep24xxContent.info[idx].address < (EepromAddress + Length)) )
      {
         Eep24xxContent.info[idx].address = 0;
         Eep24xxContent.info[idx].size = 0;

         for(uint32 count = idx; count < Eep24xxContent.entries; count++)
         {
            Eep24xxContent.info[count].address = Eep24xxContent.info[count + 1].address;
            Eep24xxContent.info[count].size = Eep24xxContent.info[count + 1].size;
         }
         
         if(Eep24xxContent.entries > 0)
         {
            Eep24xxContent.entries--;
         }
         
      }
   }

   return E_OK;
}

Std_ReturnType Eep24xx_Compare(Eep24xx_AddressType EepromAddress,const uint8* DataBufferPtr,Eep24xx_LengthType Length)
{
    Std_ReturnType LenReturnValue = E_OK;
   uint8  *targetAdd =DataBufferPtr;
   uint32 idx;

   if(targetAdd != NULL)
   {
      for(idx = 0; idx < Length; idx++)
      {
         if(targetAdd[idx] != Eep24xxDataContent[idx + EepromAddress])
         {
            LenReturnValue = E_NOT_OK;
            break;
         }
      }
   }  
  
  return(LenReturnValue);
}

void Eep24xx_Cancel (void)
{
    return;
}

MemIf_StatusType Eep24xx_GetStatus(void)
{
    return MEMIF_IDLE;
}

MemIf_JobResultType Eep24xx_GetJobResult(void)
{
    return MEMIF_JOB_OK;
}

void Eep24xx_MainFunction(void)
{

}
#endif