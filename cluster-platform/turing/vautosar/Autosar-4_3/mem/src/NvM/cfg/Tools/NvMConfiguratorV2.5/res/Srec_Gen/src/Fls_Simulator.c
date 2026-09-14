#include <stdio.h>
#include <malloc.h>

#include "Std_Types.h"
#include "Fls.h"
#include "MemIf.h"
#include "Fls_TypesLib.h"


#include "Fls_Simulator.h"

#if DFLASH_MAX_SIZE_MB != 0
# define MAXIMUM_DFLASH_SIZE   (1024*1024*DFLASH_MAX_SIZE_MB)
#else
# define MAXIMUM_DFLASH_SIZE   (1024*1024*8) //8MB
#warning "Defined DFLASH size is 0 or is not defined. Using default size of 8MB..."
#endif

static uint8 *memMapDflashContent = NULL;
static uint8 memEraseValue;
static memMapDflashType memMapDflash;


void Fls_Driver_Init()
{
   uint32 eraseValue = 0xFFFFFFFF;
   

   memMapDflashContent = calloc(1, MAXIMUM_DFLASH_SIZE);
   if(NULL == memMapDflashContent)
   {
      
   }
   memEraseValue = (uint8)(0x000000FF & eraseValue);
}


void Fls_Driver_Free(void)
{
   if(memMapDflashContent != NULL)
   {
      free(memMapDflashContent);
   }
}

uint8 * Fls_Driver_getImage(void)
{
   return (uint8 *)&memMapDflashContent[0];
}

memMapDflashType * Fls_Driver_getMemMap(void)
{
   return (memMapDflashType *)&memMapDflash;
}

FUNC(void, FLS_CODE) Fls_Init
(P2CONST(Fls_ConfigType, AUTOMATIC, FLS_APPL_CONST) ConfigPtr)
{

   uint32 idx;
   for(idx = 0; idx < MAXIMUM_DFLASH_SIZE; idx++)
   {
      memMapDflashContent[idx] = memEraseValue;
   }

   for(idx = 0; idx < MAXIMUM_MEMMAP_SIZE; idx++)
   {
      memMapDflash.info[idx].address = 0;
      memMapDflash.info[idx].size = 0;
   }
   memMapDflash.entries = 0;
}

void Fls_MainFunction(void)
{
}

FUNC(void, FLS_PUBLIC_CODE)Fls_Cancel(void)
{
}

FUNC(MemIf_StatusType, FLS_PUBLIC_CODE)Fls_GetStatus(void)
{
 return MEMIF_IDLE;
}

FUNC(MemIf_JobResultType, FLS_CODE)Fls_GetJobResult(void)
{
   return MEMIF_JOB_OK;
}

FUNC(Std_ReturnType, FLS_PUBLIC_CODE) Fls_Erase
(Fls_AddressType TargetAddress, Fls_LengthType Length)
{
   uint32 idx;
   for(idx = TargetAddress; idx < (TargetAddress + Length); idx++)
   {
      memMapDflashContent[idx] = memEraseValue;
   }

   for(idx = 0; idx < memMapDflash.entries; idx++)
   {
      if( (memMapDflash.info[idx].address >= TargetAddress) &&
          (memMapDflash.info[idx].address < (TargetAddress + Length)) )
      {
         memMapDflash.info[idx].address = 0;
         memMapDflash.info[idx].size = 0;

         for(uint32 count = idx; count < memMapDflash.entries; count++)
         {
            memMapDflash.info[count].address = memMapDflash.info[count + 1].address;
            memMapDflash.info[count].size = memMapDflash.info[count + 1].size;
         }
         
         if(memMapDflash.entries > 0)
         {
            memMapDflash.entries--;
         }
         
      }
   }

   return E_OK;
}


FUNC(Std_ReturnType, FLS_PUBLIC_CODE) Fls_Write
(Fls_AddressType TargetAddress,
P2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) SourceAddressPtr,
Fls_LengthType Length)
{
   uint32  idx;
   boolean found;

   for(idx = 0; idx < Length; idx++)
   {
      memMapDflashContent[idx + TargetAddress] = SourceAddressPtr[idx];
   }

   found = FALSE;
   for(uint32 addr = 0; addr < memMapDflash.entries; addr++)
   {

      if(TargetAddress == (memMapDflash.info[addr].address + memMapDflash.info[addr].size))
      {
         memMapDflash.info[addr].size += Length;
         found = TRUE;
         break;
      }
   }

   if(FALSE == found)
   {
      for(uint32 addr = 0; addr < memMapDflash.entries; addr++)
      {
         if( (0 != memMapDflash.info[addr].address) &&
             (TargetAddress <= memMapDflash.info[addr].address) )
         {
            for(uint32 count = memMapDflash.entries; count > addr; count--)
            {
               memMapDflash.info[count].address = memMapDflash.info[count - 1].address;
               memMapDflash.info[count].size = memMapDflash.info[count - 1].size;
            }
            memMapDflash.info[addr].address = TargetAddress;
            memMapDflash.info[addr].size = Length;
            memMapDflash.entries++;
            found = TRUE;
            break;
         }

      }
   }
   if(FALSE == found)
   {
      memMapDflash.info[memMapDflash.entries].address = TargetAddress;
      memMapDflash.info[memMapDflash.entries].size = Length;
      if(memMapDflash.entries < MAXIMUM_MEMMAP_SIZE)
      {
         memMapDflash.entries++;
      }
      
   }

   for(uint32 addr = 0; addr < memMapDflash.entries; addr++)
   {

      if( memMapDflash.info[addr + 1].address == (memMapDflash.info[addr].address + memMapDflash.info[addr].size) )
      { 
         memMapDflash.info[addr].size += memMapDflash.info[addr + 1].size;
         for(uint32 count = (addr + 1); count < memMapDflash.entries; count++)
         {
            memMapDflash.info[count].address = memMapDflash.info[count + 1].address;
            memMapDflash.info[count].size = memMapDflash.info[count + 1].size;
         }
         memMapDflash.entries--;
         break;
         
      }
   }

   return E_OK;
}


FUNC(Std_ReturnType, FLS_PUBLIC_CODE) Fls_Read
(Fls_AddressType SourceAddress,
P2VAR(uint8, AUTOMATIC, FLS_APPL_CONST) TargetAddressPtr,
Fls_LengthType Length)
{
   uint8  *targetAdd = (uint8 *)TargetAddressPtr;
   uint32 idx;
   if(targetAdd != NULL)
   {
      for(idx = 0; idx < Length; idx++)
      {
         targetAdd[idx] = memMapDflashContent[idx + SourceAddress];
      }
   }
   return E_OK;
}

FUNC(Std_ReturnType, FLS_PUBLIC_CODE) Fls_Compare
(Fls_AddressType SourceAddress,
P2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) TargetAddressPtr,
Fls_LengthType Length)
{
   Std_ReturnType LenReturnValue = E_OK;
   uint8  *targetAdd = (uint8 *)TargetAddressPtr;
   uint32 idx;

   if(targetAdd != NULL)
   {
      for(idx = 0; idx < Length; idx++)
      {
         if(targetAdd[idx] != memMapDflashContent[idx + SourceAddress])
         {
            LenReturnValue = E_NOT_OK;
            break;
         }
      }
   }  
  
  return(LenReturnValue);
}
