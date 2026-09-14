#include <stdio.h>
#include "Fls.h"
#include "NvMDefault_Cfg.h"
#include "NvM.h"
#include "SrecMake.h"
#include "FlsConst_Cfg.h"


static uint8 WriteBuffer[NVM_WRITE_VERIFICATION_DATASIZE];

static void RAMCopy(uint8 *SrcPtr,uint8 *DestPtr, uint16 length)
{
     uint16 fl_temp;
     if((SrcPtr != NULL) && (DestPtr != NULL))
     {
          for(fl_temp = 0; fl_temp< length; fl_temp++)
          {
                *DestPtr = *SrcPtr;
                DestPtr++;
                SrcPtr++;
          }
     }
}

static void EEPROM_ImageGeneration_SM (void)
{
    uint16 fl_CurrentVariantNo = 0; 
    uint16 fl_CurrentBlockID = 0;
    uint16 fl_CurrentIndex = 0;
    uint16 fl_CurrentBlockLength = 0;
    uint8* fl_SrcBufferPtr;
    uint16 fl_SectorIndex;
    uint8 fl_Result = E_NOT_OK;

    /*Setting Up Srec Gen Configuration*/
    SrecMake_Config.NoOfDynamicPartition = FEE_NUM_PARTITIONS;
    SrecMake_Config.BytesPerLine = EEPROM_SREC_DATA_BYTES_PER_LINE;
    SrecMake_Config.SrecType = S37REC;
    SrecMake_Config.NoOfFixedPartition = 1;
    for (fl_CurrentIndex = 0; fl_CurrentIndex< FEE_NUM_PARTITIONS; fl_CurrentIndex++)
    {
        fl_SectorIndex = Fee_PartitionConfig[fl_CurrentIndex].StartingSectorId;
        SrecMake_Config.Partition_StartAddress[fl_CurrentIndex] = Fee_SectorConfig[fl_SectorIndex].SectorStartAddress;
        SrecMake_Config.Partition_SectorSize[fl_CurrentIndex] = Fee_SectorConfig[fl_SectorIndex].SectorSize; 
    }
    SrecMake_Config.SrecOffset = EEPROM_OFSET;
    for (fl_CurrentIndex = 0; fl_CurrentIndex< FEE_NUM_PARTITIONS; fl_CurrentIndex++)
    {
        SrecMake_Config.Fixed_Start_Address[fl_CurrentIndex]= FixedPartitionStartAddress[fl_CurrentIndex];
        SrecMake_Config.Fixed_End_Address[fl_CurrentIndex] = FixedPartitionEndAddress[fl_CurrentIndex];
    }
    /***********************************/
    for (fl_CurrentVariantNo = 0; fl_CurrentVariantNo < NUM_OF_VARIANT; fl_CurrentVariantNo++)
    {
        // printf("Init\n");
        MEMSTACK_INIT();
        for (fl_CurrentIndex = 0; fl_CurrentIndex < NUM_OF_NVM_BLOCKS; fl_CurrentIndex++)
        {
            fl_CurrentBlockID = NvM_BlockList[fl_CurrentIndex].BlockID;
            fl_CurrentBlockLength = NvM_BlockConfig[fl_CurrentBlockID].NvBlockLength;
            fl_SrcBufferPtr = NvM_BlockList[fl_CurrentIndex].RamAddress[fl_CurrentVariantNo];
            RAMCopy(fl_SrcBufferPtr, &WriteBuffer[0], fl_CurrentBlockLength);
            NvM_WriteBlock(fl_CurrentBlockID,&WriteBuffer[0]);
            do
            {
                //  printf("Variant %d Index %d\n",fl_CurrentVariantNo,fl_CurrentIndex);
                MEMSTACK_MAINFUNCTION();
                NvM_GetErrorStatus(fl_CurrentBlockID,&fl_Result);
            }while (2u == fl_Result);
        }
        sprintf (SrecMake_Config.FileName,"../../out/srec/DFL_%s.srec",varinat_name[fl_CurrentVariantNo]);
        srec_main();
    }
}

static void FLASH_ImageGeneration_SM (void)
{
    uint32 fl_CurrentAddress = 0;
    uint16 fl_CurrentVariantNo = 0; 
    uint16 fl_CurrentIndex = 0;
    uint16 fl_CurrentBlockLength = 0;
    uint16 fl_CurrentBlockID = 0;
    uint8* fl_SrcBufferPtr;
    for (fl_CurrentVariantNo = 0; fl_CurrentVariantNo < NUM_OF_VARIANT; fl_CurrentVariantNo++)
    {
        Fls_Init();
#if(FLASHCONSTANT_IMAGE_GEN == STD_ON)
        for (fl_CurrentIndex = 0; fl_CurrentIndex < NUM_OF_FLASH_ELEMENTS; fl_CurrentIndex++)
        {
            fl_CurrentAddress = Flash_ElementList[fl_CurrentIndex].LogicalAddress;
            WriteBuffer[0] = Flash_ElementList[fl_CurrentIndex].ParameterValue[fl_CurrentVariantNo];
            Fls_Write(fl_CurrentAddress,&WriteBuffer[0],1u);
        }
#endif

#if(NVMDEFAULTS_IMAGE_GEN == STD_ON)
        fl_CurrentAddress = NVMDEFAULTS_START_INDEX;
        for (fl_CurrentIndex = 0; fl_CurrentIndex < NUM_OF_NVM_BLOCKS; fl_CurrentIndex++)
        {
            fl_CurrentBlockID = NvM_BlockList[fl_CurrentIndex].BlockID;
            fl_CurrentBlockLength = NvM_BlockConfig[fl_CurrentBlockID].NvBlockLength;
            fl_SrcBufferPtr = NvM_BlockList[fl_CurrentIndex].RamAddress[fl_CurrentVariantNo];
            RAMCopy(fl_SrcBufferPtr, &WriteBuffer[0], fl_CurrentBlockLength);
            Fls_Write(fl_CurrentAddress,&WriteBuffer[0],fl_CurrentBlockLength);
            fl_CurrentAddress += fl_CurrentBlockLength;
            if (fl_CurrentAddress%4 !=0)
            {
                fl_CurrentAddress+=((4-fl_CurrentAddress%4)); /*PADDING*/
            }
        } 
#endif
#if(FLS_SREC_GEN == STD_ON)
        /*Setting Up Srec Gen Configuration*/
        SrecMake_Config.NoOfDynamicPartition = 0;
        SrecMake_Config.BytesPerLine = FLS_SREC_DATA_BYTES_PER_LINE;
        SrecMake_Config.SrecType = S37REC;    
        SrecMake_Config.NoOfFixedPartition = 1;
        SrecMake_Config.Fixed_Start_Address[0]= 0x0;
        SrecMake_Config.Fixed_End_Address[0] = FLS_CONST_IMAGE_SIZE + 1;
        SrecMake_Config.SrecOffset = FLS_SREC_OFSET;
        sprintf (SrecMake_Config.FileName,"../../out/fls_srec/FLS_%s.srec",varinat_name[fl_CurrentVariantNo]);
        /***********************************/
        srec_main();
#endif
#if(FLS_ULP_GEN == STD_ON)
        /*Setting Up Srec Gen Configuration*/
        SrecMake_Config.NoOfDynamicPartition = 0;
        SrecMake_Config.BytesPerLine = FLS_ULP_DATA_BYTES_PER_LINE;
        SrecMake_Config.SrecType = S19REC;    
        SrecMake_Config.NoOfFixedPartition = 1;
        SrecMake_Config.Fixed_Start_Address[0]= 0x0;
        SrecMake_Config.Fixed_End_Address[0] = FLS_CONST_IMAGE_SIZE + 1;
        SrecMake_Config.SrecOffset = FLS_ULP_OFSET;
        sprintf (SrecMake_Config.FileName,"../../out/fls_ulp/FLS_%s.ulp",varinat_name[fl_CurrentVariantNo]);
        /***********************************/
        srec_main();
#endif
    }
}

int main()
{
    printf("Running generator...\n");
    EEPROM_ImageGeneration_SM ();
    FLASH_ImageGeneration_SM();
    printf("Succesoooos\n");
    return 0;
}
