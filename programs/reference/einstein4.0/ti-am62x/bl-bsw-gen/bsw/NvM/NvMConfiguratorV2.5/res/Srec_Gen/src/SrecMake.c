#include <stdio.h>
#include "Std_Types.h"
#include "SrecMake.h"
#include "General_Cfg.h"
#include "EmulatedEEPROM.h"


#define SREC_MAX_LINE_CHARS               (200)
char hdr[6]="484452";
uint32 totalline =0u;


SrecMake_ConfigType SrecMake_Config;

static void writeS0rec(FILE *file);
static void writeS5rec(FILE *file);
static void writeS7rec(FILE *file);
static void writeS8rec(FILE *file);
static void writeS9rec(FILE *file);
static uint8 computeChecksumFromString(char *data, uint8 length);
#ifdef Little_Endian
static void SwapEndian(char *data, uint8 length);
#endif
static void Write_SData (FILE *file);
static void Update_Sector_EndAddress();
static void SData_Manager (FILE *file);

void srec_main(){

   FILE *srecFile;
   srecFile = fopen(SrecMake_Config.FileName, "wb");
   if(srecFile!=NULL){

      switch (SrecMake_Config.SrecType)
      {
      case S19REC:
         writeS0rec(srecFile);
         SData_Manager(srecFile);
         writeS5rec(srecFile);
         writeS9rec(srecFile);
         break;

      case S28REC:
         writeS0rec(srecFile);
         SData_Manager(srecFile);
         writeS5rec(srecFile);
         writeS8rec(srecFile);
         break;
         
      case S37REC:
         // baseaddress = 32u;
         writeS0rec(srecFile);
         SData_Manager(srecFile);
         writeS5rec(srecFile);
         writeS7rec(srecFile);
         break;
      
      default:
         break;
      }
   }
   fclose(srecFile);
   printf("File Generated Successfully...\n");
}

static void writeS0rec(FILE *file){

   char data[4];
   uint8 i=0;
   uint8 checksum=0;

   char SrecLine[SREC_MAX_LINE_CHARS];
   SrecLine[i++]='S';
   SrecLine[i++]='0';

   SrecLine[i++]='0';
   SrecLine[i++]='6';

   sprintf(data, "%04X",0);

   SrecLine[i++] = data[0];
   SrecLine[i++] = data[1];
   SrecLine[i++] = data[2];
   SrecLine[i++] = data[3];

   SrecLine[i++]=hdr[0];
   SrecLine[i++]=hdr[1];
   SrecLine[i++]=hdr[2];
   SrecLine[i++]=hdr[3];
   SrecLine[i++]=hdr[4];
   SrecLine[i++]=hdr[5];

   checksum=computeChecksumFromString(&SrecLine[2], i-2);
   sprintf(data, "%02X", checksum);
   SrecLine[i++] = data[0];
   SrecLine[i++] = data[1];

   SrecLine[i++] = '\r';
   SrecLine[i++] = '\n';
   fwrite(SrecLine, 1, i, file);

}
static uint8 fl_DataWrite = FALSE;
typedef struct 
{
   uint8 SrcAddress_Len;           //Address Length Based on Srec type
   uint32 SrcAddress;              //Source Address in Buffer
   uint32 EndAddress;              //End Address in Buffer
   uint8 BytesPL;                  //Bytes Per Line
   uint32 Total_Lines;             //Total Lines writern
}Srec_JobSettingsType;
static Srec_JobSettingsType Srec_JobSettings;
static uint8   *SrecContent;
   
void SData_Manager (FILE *file)
{
   SrecContent = EmulatedEEPROM_GetImage();
   // for (int j = 0; j<30; j++)
   // {
   //    for (int i = 0; i<30 ; i++)
   //    {
   //       printf( "%01X ", SrecContent[(j*10)+i]);
   //    }
   //    printf ("\n");
   // }
   Srec_JobSettings.BytesPL = SrecMake_Config.BytesPerLine;
   if(S19REC == SrecMake_Config.SrecType)
   {
      Srec_JobSettings.SrcAddress_Len = 2;
   }
   else if(S28REC == SrecMake_Config.SrecType)
   {
      Srec_JobSettings.SrcAddress_Len = 4;
   }
   else if(S37REC == SrecMake_Config.SrecType)
   {
      Srec_JobSettings.SrcAddress_Len = 8;
   }
   
#ifdef SREC_DYNAMIC_ADDRESS
   for (uint8 i=0; i<SrecMake_Config.NoOfDynamicPartition; i++)
   {
      // printf("Partition %d\n",i);
	  //To Write Data
      Srec_JobSettings.SrcAddress = SrecMake_Config.Partition_StartAddress[i];
      Srec_JobSettings.EndAddress = (Srec_JobSettings.SrcAddress + SrecMake_Config.Partition_SectorSize[i]) - SECTOR_FOOTER_LENGTH - 1u;
      // printf("\tStartAddress %d\n",Srec_JobSettings.SrcAddress);
	//   printf("\tEndAddress %d\n",Srec_JobSettings.EndAddress);
	  Update_Sector_EndAddress();
      fl_DataWrite = TRUE;
      Write_SData(file);
      //To Write Sector Footer
      Srec_JobSettings.SrcAddress = (SrecMake_Config.Partition_StartAddress[i]+ SrecMake_Config.Partition_SectorSize[i]) - SECTOR_FOOTER_LENGTH;
      Srec_JobSettings.EndAddress = (SrecMake_Config.Partition_StartAddress[i]+ SrecMake_Config.Partition_SectorSize[i]);
      fl_DataWrite = TRUE;
      Write_SData(file);
   }
#endif
#ifdef SREC_FIXED_ADDRESS
   for(uint8 i=0; i<SrecMake_Config.NoOfFixedPartition; i++)
   {
      Srec_JobSettings.SrcAddress = SrecMake_Config.Fixed_Start_Address[i];
      Srec_JobSettings.EndAddress = SrecMake_Config.Fixed_End_Address [i];
      fl_DataWrite = TRUE;
      Write_SData(file);
   }
#endif
   
}
void Update_Sector_EndAddress()
{
   char temp[2];
   boolean End = FALSE;
   while(!End)
   {
      sprintf(temp, "%01X", SrecContent[Srec_JobSettings.EndAddress]);
      if(temp[0]=='F')
         {
            Srec_JobSettings.EndAddress-=1;
         }
         else
         {
            Srec_JobSettings.EndAddress+=1;
            End = TRUE;
         }
      }
}
void Write_SData (FILE *file)
{
   while (fl_DataWrite)
   {
      char cur_length[2u];
      char cur_Address[Srec_JobSettings.SrcAddress_Len];
      uint8 Swap_Address = 0;
      char data[4];
      char flsdata[20];
      uint8 checksum=0;
      char SrecLine[SREC_MAX_LINE_CHARS]; 
      uint8 i = 0;
      //Write Srecord Type
      SrecLine[i++]='S';
      if(S19REC == SrecMake_Config.SrecType)
      {
         SrecLine[i++]='1';
      }
      else if(S28REC == SrecMake_Config.SrecType)
      {
         SrecLine[i++]='2';
      }
      else if(S37REC == SrecMake_Config.SrecType)
      {
         SrecLine[i++]='3';
      }

      //Write Length
      sprintf(cur_length, "%02X", ((Srec_JobSettings.SrcAddress_Len/2) + Srec_JobSettings.BytesPL + 1/*CHECKSUM*/));
      SrecLine[i++] = cur_length[0];
      SrecLine[i++] = cur_length[1];

      //Write Address
      if(S19REC == SrecMake_Config.SrecType)
      {
         sprintf(cur_Address, "%04X", Srec_JobSettings.SrcAddress + SrecMake_Config.SrecOffset);
         SrecLine[i++] = cur_Address[0];
         SrecLine[i++] = cur_Address[1];
         SrecLine[i++] = cur_Address[2];
         SrecLine[i++] = cur_Address[3];
      }
      else if(S28REC == SrecMake_Config.SrecType)
      {
         sprintf(cur_Address, "%06X", Srec_JobSettings.SrcAddress + SrecMake_Config.SrecOffset);
         SrecLine[i++] = cur_Address[0];
         SrecLine[i++] = cur_Address[1];
         SrecLine[i++] = cur_Address[2];
         SrecLine[i++] = cur_Address[3];
         SrecLine[i++] = cur_Address[4];
         SrecLine[i++] = cur_Address[5];
      }
      else if(S37REC == SrecMake_Config.SrecType)
      {
         sprintf(cur_Address, "%08X", Srec_JobSettings.SrcAddress + SrecMake_Config.SrecOffset);
         SrecLine[i++] = cur_Address[0];
         SrecLine[i++] = cur_Address[1];
         SrecLine[i++] = cur_Address[2];
         SrecLine[i++] = cur_Address[3];
         SrecLine[i++] = cur_Address[4];
         SrecLine[i++] = cur_Address[5];
         SrecLine[i++] = cur_Address[6];
         SrecLine[i++] = cur_Address[7];
      }
      Swap_Address = i;

      //Write Data 
      for(int j=0; j<Srec_JobSettings.BytesPL; j++)
      {
         sprintf(flsdata, "%02X", SrecContent[Srec_JobSettings.SrcAddress]);
         SrecLine[i++]=flsdata[0];
         SrecLine[i++]=flsdata[1];
         Srec_JobSettings.SrcAddress += 1;

         if(Srec_JobSettings.SrcAddress < Srec_JobSettings.EndAddress)
         {
            continue;
         }
         else
         {
            sprintf(cur_length, "%02X", ((Srec_JobSettings.SrcAddress_Len/2) + (j+1u) + 1u/*CHECKSUM*/));
            SrecLine[2] = cur_length[0];
            SrecLine[3] = cur_length[1];
            fl_DataWrite = FALSE;
            break;
         }

      }

      //Calculate Checksum
      #ifdef Little_Endian
         SwapEndian(&SrecLine[Swap_Address],32);                 //Length to be updated
      #endif
      checksum=computeChecksumFromString(&SrecLine[2], i-2);
      sprintf(data, "%02X", checksum);
      SrecLine[i++] = data[0];
      SrecLine[i++] = data[1];
      SrecLine[i++] = '\r';
      SrecLine[i++] = '\n';
      //totalline++;
      //z++;
      fwrite(SrecLine, 1, i, file);
   }
}

static void writeS5rec(FILE *file){

   char data[8];
   uint8 i=0;
   uint8 checksum=0;

   char SrecLine[SREC_MAX_LINE_CHARS];
   SrecLine[i++]='S';
   SrecLine[i++]='5';

   SrecLine[i++]='0';
   SrecLine[i++]='3';
   sprintf(data, "%04X", totalline);
   
   SrecLine[i++] = data[0];
   SrecLine[i++] = data[1];
   SrecLine[i++] = data[2];
   SrecLine[i++] = data[3];
   //printf("\n Total Lines:\t%X\n", data[5]);

   checksum=computeChecksumFromString(&SrecLine[2], i-2);
   sprintf(data, "%02X", checksum);
   SrecLine[i++] = data[0];
   SrecLine[i++] = data[1];
   
   SrecLine[i++] = '\r';
   SrecLine[i++] = '\n';
   fwrite(SrecLine, 1, i, file);

}


static void writeS7rec(FILE *file){

   char data[8];
   uint8 i=0;
   uint8 checksum=0;

   char SrecLine[SREC_MAX_LINE_CHARS];
   SrecLine[i++]='S';
   SrecLine[i++]='7';

   SrecLine[i++]='0';
   SrecLine[i++]='5';

   sprintf(data, "%08X",0);

   SrecLine[i++] = data[0];
   SrecLine[i++] = data[1];
   SrecLine[i++] = data[2];
   SrecLine[i++] = data[3];
   SrecLine[i++] = data[4];
   SrecLine[i++] = data[5];
   SrecLine[i++] = data[6];
   SrecLine[i++] = data[7];

   checksum=computeChecksumFromString(&SrecLine[2], i-2);
   sprintf(data, "%02X", checksum);
   SrecLine[i++] = data[0];
   SrecLine[i++] = data[1];
   
   SrecLine[i++] = '\r';
   SrecLine[i++] = '\n';
   fwrite(SrecLine, 1, i, file);

}

static void writeS8rec(FILE *file){

   char data[8];
   uint8 i=0;
   uint8 checksum=0;

   char SrecLine[SREC_MAX_LINE_CHARS];
   SrecLine[i++]='S';
   SrecLine[i++]='8';

   SrecLine[i++]='0';
   SrecLine[i++]='4';

   sprintf(data, "%06X",0);

   SrecLine[i++] = data[0];
   SrecLine[i++] = data[1];
   SrecLine[i++] = data[2];
   SrecLine[i++] = data[3];
   SrecLine[i++] = data[4];
   SrecLine[i++] = data[5];


   checksum=computeChecksumFromString(&SrecLine[2], i-2);
   sprintf(data, "%02X", checksum);
   SrecLine[i++] = data[0];
   SrecLine[i++] = data[1];
   
   SrecLine[i++] = '\r';
   SrecLine[i++] = '\n';
   fwrite(SrecLine, 1, i, file);

}

static void writeS9rec(FILE *file){

   char data[8];
   uint8 i=0;
   uint8 checksum=0;

   char SrecLine[SREC_MAX_LINE_CHARS];
   SrecLine[i++]='S';
   SrecLine[i++]='9';

   SrecLine[i++]='0';
   SrecLine[i++]='3';

   sprintf(data, "%04X",0);

   SrecLine[i++] = data[0];
   SrecLine[i++] = data[1];
   SrecLine[i++] = data[2];
   SrecLine[i++] = data[3];

   checksum=computeChecksumFromString(&SrecLine[2], i-2);
   sprintf(data, "%02X", checksum);
   SrecLine[i++] = data[0];
   SrecLine[i++] = data[1];
   
   SrecLine[i++] = '\r';
   SrecLine[i++] = '\n';
   fwrite(SrecLine, 1, i, file);

}

static uint8 computeChecksumFromString(char *data, uint8 length)
{
   uint16 checksum = 0;
   
   for(uint8 idx = 0; idx < length; idx+=2)
   {
      uint8 charByte;
      uint8 byte;
      char character[2];
      character[1] = 0;
      
      character[0] = data[idx];
      charByte = (uint8)strtol(character,NULL,16);

      byte = (uint8)((0x0F & charByte) << 4);
      character[0] = data[idx + 1];
      charByte = (uint8)strtol(character,NULL,16);
      byte |= (uint8)(0x0F & charByte);
      
      checksum += byte;
   }
   
   return (((uint8)(checksum & 0x00FF)) ^ 0xFF);
}
#ifdef Little_Endian
static void SwapEndian(char *data, uint8 length)
{
   //printf("\n%s",data);
   char TempData[length];
   for(int i=0; i<length;i++)
   {
      TempData[i]=data[i+1];
      i++;
      TempData[i]=data[i-1];
   }
   //printf("\n%s", TempData);
   for(int i=0; i<length; i++){
      data[i] = TempData[i+7];
      data[i+1] = TempData[i+6];
      data[i+2] = TempData[i+5];
      data[i+3] = TempData[i+4];
      data[i+4] = TempData[i+3];
      data[i+5] = TempData[i+2];
      data[i+6] = TempData[i+1];
      data[i+7] = TempData[i];
      i+=7;
   }
   //printf("\n%s\n",data);
}
#endif