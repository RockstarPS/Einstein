#include <stdio.h>
#include "Std_Types.h"
#include "SrecMake.h"
#include "Srec_Gen_Cfg.h"

#define SREC_MAX_LINE_CHARS               (200)
#define MAX_NUMBER_OF_VARINTS             (30)
#define MAX_STRING_LENGHT_VARINT          (30)

const char varinat_name[MAX_NUMBER_OF_VARINTS][MAX_STRING_LENGHT_VARINT+1]  = {
    "VW_FPKB8_Default",
"2GP 920 310.D",
"2GP 920 312.C",
"22D 920 310.C",
"5CG 920 310.C",
"2GJ 920 310.D",
"2GJ 920 410.D",
"5NA 920 310.D",
"5NA 920 410.D",
"19D 920 310.D",
"5NG 920 310.D",
"3GB 920 314.B",
"6JM 920 310.C",
"565 920 310.C",
"654 920 310",
"575 920 330.A",
"6F0 920 332.A",
"6F0 920 330.A",
   "BASIC_VW270_FPK8",
   "BASIC_VW216_FPK8",
   "BASIC_VW316_FPK8",
   "BASIC_VW326_5NA_FPK8",
   "BASIC_VW331_FPK8",
   "BASIC_VW326_5NG_FPK8",
   "BASIC_SK216_FPK8",
"BASIC_SK326_FPK8",
"BASIC_SE370_FPK8",
"BASIC_SE270_FPK8"
   };



uint32 start_address=MEM_Start_Address;
char hdr[6]="484452";
uint32 sreclinesize =20u;
uint32 baseaddress = 0u;
//uint32 footeraddress = 12048u;    //+baseaddress
uint32 footeraddress = 32784u;
uint32 basesize = 100u;
uint32 totalline =0u;

static void writeS0rec(FILE *file);
static void writeS1rec(FILE *file);
static void writeS2rec(FILE *file);
static void writeS3rec(FILE *file);
static void writeS5rec(FILE *file);
static void writeS7rec(FILE *file);
static void writeS8rec(FILE *file);
static void writeS9rec(FILE *file);
static uint8 computeChecksumFromString(char *data, uint8 length);
static void SwapEndian(char *data, uint8 length);
static void Write_SData (FILE *file);
static void Update_Sector_EndAddress();
static void SData_Manager (FILE *file);

void srec_main(uint8 nthVariant){

  start_address=MEM_Start_Address;
  hdr[6]="484452";
  sreclinesize =20u;
  baseaddress = 0u;
///uint32 footeraddress = 12048u;    //+baseaddress
  footeraddress = 32784u;
  basesize = 100u;
  totalline =0u;

  uint8 curr_Partition = 0;

   FILE *srecFile;
   char name[40];
   sprintf(name,"../../out/srec/VW_WorkFlash_%s_%d.srec",varinat_name[nthVariant],nthVariant+1);
   srecFile = fopen(name, "wb");
   if(srecFile!=NULL){

      switch (SREC_TYPE)
      {
      case S19REC:
         writeS0rec(srecFile);
         writeS1rec(srecFile);
         writeS5rec(srecFile);
         writeS9rec(srecFile);
         break;

      case S28REC:
         writeS0rec(srecFile);
         writeS2rec(srecFile);
         writeS5rec(srecFile);
         writeS8rec(srecFile);
         break;
         
      case S37REC:
         baseaddress = 32u;
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
   printf("File Generated Successfully...");
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
   SrecContent = FLASH_Simulator_getImage();
   Srec_JobSettings.BytesPL = SREC_DATA_BYTES_PER_LINE;
   #if SREC_TYPE == S19REC
      Srec_JobSettings.SrcAddress_Len = 2;
   #elif SREC_TYPE == S28REC
      Srec_JobSettings.SrcAddress_Len = 4;
   #elif SREC_TYPE == S37REC
      Srec_JobSettings.SrcAddress_Len = 8;
   #endif
   
#ifdef SREC_DYNAMIC_ADDRESS
   for (uint8 i=0; i<NO_OF_PARTITION; i++)
   {
      //To Write Data
      Srec_JobSettings.SrcAddress = Partition_StartAddress[i];
      Srec_JobSettings.EndAddress = (Srec_JobSettings.SrcAddress + SECTOR_SIZE) - SECTOR_FOOTER_LENGTH - 1u;
      Update_Sector_EndAddress();
      fl_DataWrite = TRUE;
      Write_SData(file);
      //To Write Sector Footer
      Srec_JobSettings.SrcAddress = (Partition_StartAddress[i]+ SECTOR_SIZE) - SECTOR_FOOTER_LENGTH;
      Srec_JobSettings.EndAddress = (Partition_StartAddress[i]+ SECTOR_SIZE);
      fl_DataWrite = TRUE;
      Write_SData(file);
   }
#endif
#ifdef SREC_FIXED_ADDRESS
   for(uint8 i=0; i<NO_OF_FIXED_PARTITION; i++)
   {
      Srec_JobSettings.SrcAddress = Fixed_Start_Address[i];
      Srec_JobSettings.EndAddress = Fixed_End_Address [i];
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
   #if SREC_TYPE == S19REC
      SrecLine[i++]='1';
   #elif SREC_TYPE == S28REC
      SrecLine[i++]='2';
   #elif SREC_TYPE == S37REC
      SrecLine[i++]='3';
   #endif

      //Write Length
      sprintf(cur_length, "%02X", ((Srec_JobSettings.SrcAddress_Len/2) + Srec_JobSettings.BytesPL + 1/*CHECKSUM*/));
      SrecLine[i++] = cur_length[0];
      SrecLine[i++] = cur_length[1];

      //Write Address
   #if SREC_TYPE == S19REC
      sprintf(cur_Address, "%04X", Srec_JobSettings.SrcAddress + EEPROM_OFSET);
      SrecLine[i++] = cur_Address[0];
      SrecLine[i++] = cur_Address[1];
      SrecLine[i++] = cur_Address[2];
      SrecLine[i++] = cur_Address[3];
   #elif SREC_TYPE == S28REC
      sprintf(cur_Address, "%06X", Srec_JobSettings.SrcAddress + EEPROM_OFSET);
      SrecLine[i++] = cur_Address[0];
      SrecLine[i++] = cur_Address[1];
      SrecLine[i++] = cur_Address[2];
      SrecLine[i++] = cur_Address[3];
      SrecLine[i++] = cur_Address[4];
      SrecLine[i++] = cur_Address[5];
   #elif SREC_TYPE == S37REC
      sprintf(cur_Address, "%08X", Srec_JobSettings.SrcAddress + EEPROM_OFSET);
      SrecLine[i++] = cur_Address[0];
      SrecLine[i++] = cur_Address[1];
      SrecLine[i++] = cur_Address[2];
      SrecLine[i++] = cur_Address[3];
      SrecLine[i++] = cur_Address[4];
      SrecLine[i++] = cur_Address[5];
      SrecLine[i++] = cur_Address[6];
      SrecLine[i++] = cur_Address[7];
   #endif
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

static void writeS1rec(FILE *file)
{

   uint8   *flsContent;
   uint32  address;
   uint16  size;
   uint32 memorysize = SREC_MEMORY_SIZE;
   
   uint32 itr=0;
   char data[4];
   char flsdata[20];
   uint8 checksum=0;
   boolean End = FALSE;
   boolean Footer = FALSE;

   flsContent = FLASH_Simulator_getImage();
   char temp[2];

   if(INTERNAL_MEM){
   memorysize =  32752;
      while(!End)
      {

         sprintf(temp, "%01X", flsContent[memorysize]);
         if(temp[0]=='F')
         {
            memorysize-=1;
         }
         else
         {
            End = TRUE;
         }

      }

      End = FALSE;
   }

   int z=0;

   while(!End){
      char SrecLine[SREC_MAX_LINE_CHARS];
      uint8 i=0;
      //printf("%ld",sizeof(*flsContent));
      int p = 1;
      SrecLine[i++]='S';
      //printf("HI%c",SrecLine[i-1]);
      SrecLine[i++]='1';

      SrecLine[i++]='1';
      SrecLine[i++]='3';

      sprintf(data, "%04X", start_address);

      SrecLine[i++] = data[0];
      SrecLine[i++] = data[1];
      SrecLine[i++] = data[2];
      SrecLine[i++] = data[3];

      if(!Footer){
         for(int j=0; j<BYTES_PER_LINE; j++)
         {
            if(memorysize-1>itr)
            {
               sprintf(flsdata, "%02X", flsContent[baseaddress]);
               SrecLine[i++]=flsdata[0];
               SrecLine[i++]=flsdata[1];
               baseaddress = baseaddress+1;
               start_address = start_address+1;
            }
            else
            {
               // SrecLine[i++]='F';
               // SrecLine[i++]='F';
               sprintf(flsdata, "%02X", flsContent[baseaddress]);
               SrecLine[i++]=flsdata[0];
               SrecLine[i++]=flsdata[1];
               baseaddress = baseaddress+1;
               if (INTERNAL_MEM)
               {
                  start_address = 32752+MEM_Start_Address;
                  Footer = TRUE;
               }
               else
               {
                  End = TRUE;
               }
            }
            itr++;
         }
      }
      else
      {
         if(INTERNAL_MEM){

            for(int j=0; j<BYTES_PER_LINE; j++)
            {
               sprintf(flsdata, "%02X", flsContent[footeraddress]);
               SrecLine[i++]=flsdata[0];
               SrecLine[i++]=flsdata[1];
               footeraddress = footeraddress+1;
               start_address = start_address+1;
            }
         }
         End = TRUE;
      }


      #ifdef Little_Endian
         SwapEndian(&SrecLine[12],32); 
      #endif
      checksum=computeChecksumFromString(&SrecLine[2], i-2);
      sprintf(data, "%02X", checksum);
      SrecLine[i++] = data[0];
      SrecLine[i++] = data[1];
      SrecLine[i++] = '\r';
      SrecLine[i++] = '\n';
      totalline++;
      z++;
      fwrite(SrecLine, 1, i, file);

   }

}

static void writeS2rec(FILE *file)
{

   uint8   *flsContent;
   uint32  address;
   uint16  size;
   uint32 memorysize = SREC_MEMORY_SIZE;
   
   uint32 itr=0;
   char data[4];
   char flsdata[20];
   uint8 checksum=0;
   boolean End = FALSE;
   boolean Footer = FALSE;

   flsContent = FLASH_Simulator_getImage();
   char temp[2];

   if(INTERNAL_MEM){
   memorysize =  32752;
      while(!End)
      {
         sprintf(temp, "%01X", flsContent[memorysize]);
         if(temp[0]=='F')
         {
            memorysize-=1;
         }
         else
         {
            End = TRUE;
         }

      }

      End = FALSE;
   }

   int z=0;

   while(!End){
      char SrecLine[SREC_MAX_LINE_CHARS];
      uint8 i=0;
      //printf("%ld",sizeof(*flsContent));
      int p = 1;
      SrecLine[i++]='S';
      //printf("HI%c",SrecLine[i-1]);
      SrecLine[i++]='2';

      SrecLine[i++]='1';
      SrecLine[i++]='4';

      sprintf(data, "%06X", start_address);

      SrecLine[i++] = data[0];
      SrecLine[i++] = data[1];
      SrecLine[i++] = data[2];
      SrecLine[i++] = data[3];
      SrecLine[i++] = data[4];
      SrecLine[i++] = data[5];

      if(!Footer){
         for(int j=0; j<BYTES_PER_LINE; j++)
         {
            if(memorysize-1>itr)
            {
               sprintf(flsdata, "%02X", flsContent[baseaddress]);
               SrecLine[i++]=flsdata[0];
               SrecLine[i++]=flsdata[1];
               baseaddress = baseaddress+1;
               start_address = start_address+1;
            }
            else
            {
               // SrecLine[i++]='F';
               // SrecLine[i++]='F';
               sprintf(flsdata, "%02X", flsContent[baseaddress]);
               SrecLine[i++]=flsdata[0];
               SrecLine[i++]=flsdata[1];
               baseaddress = baseaddress+1;
               if (INTERNAL_MEM)
               {
                  start_address = 32752+MEM_Start_Address;
                  Footer = TRUE;
               }
               else
               {
                  End = TRUE;
               }
            }
            itr++;
         }
      }
      else
      {
         if(INTERNAL_MEM){

            for(int j=0; j<BYTES_PER_LINE; j++)
            {
               sprintf(flsdata, "%02X", flsContent[footeraddress]);
               SrecLine[i++]=flsdata[0];
               SrecLine[i++]=flsdata[1];
               footeraddress = footeraddress+1;
               start_address = start_address+1;
            }
         }
         End = TRUE;
      }


      #ifdef Little_Endian
         SwapEndian(&SrecLine[12],32); 
      #endif
      checksum=computeChecksumFromString(&SrecLine[2], i-2);
      sprintf(data, "%02X", checksum);
      SrecLine[i++] = data[0];
      SrecLine[i++] = data[1];
      SrecLine[i++] = '\r';
      SrecLine[i++] = '\n';
      totalline++;
      z++;
      fwrite(SrecLine, 1, i, file);

   }

}


static void writeS3rec(FILE *file)
{

   uint8   *flsContent;
   flsContent = FLASH_Simulator_getImage();
   uint32  address;
   uint16  size;
   uint32 memorysize = SREC_MEMORY_SIZE;
   
   uint32 itr=0;
   char data[4];
   char flsdata[20];
   uint8 checksum=0;
   boolean End = FALSE;
   boolean Footer = FALSE;
   boolean SmallSector = FALSE;
   boolean LargeSector = TRUE;
   flsContent = FLASH_Simulator_getImage();
   char temp[2];
   if (INTERNAL_MEM)
   {
      memorysize = 32752;
      while (!End)
      {		
         sprintf(temp, "%01X", flsContent[memorysize]);
         if(temp[0]=='F') 
         {
            memorysize-=1;
         }
         else
         {
            End = TRUE;
         }

      }

      End = FALSE;
   }

   int z = 0;

   while (!End)
   {
      char SrecLine[SREC_MAX_LINE_CHARS];
      uint8 i=0;
      //printf("%ld",sizeof(*flsContent));
      int p = 1;
      SrecLine[i++]='S';
      //printf("HI%c",SrecLine[i-1]);
      SrecLine[i++]='3';

      SrecLine[i++]='1';
      SrecLine[i++]='5';

      sprintf(data, "%08X", start_address);

      SrecLine[i++] = data[0];
      SrecLine[i++] = data[1];
      SrecLine[i++] = data[2];
      SrecLine[i++] = data[3];
      SrecLine[i++] = data[4];
      SrecLine[i++] = data[5];
      SrecLine[i++] = data[6];
      SrecLine[i++] = data[7];

      if (LargeSector)
      {

         for (int j = 0; j < BYTES_PER_LINE; j++)
         {
            if(memorysize-1>itr)
            {
               sprintf(flsdata, "%02X", flsContent[baseaddress]);
               SrecLine[i++]=flsdata[0];
               SrecLine[i++]=flsdata[1];
               baseaddress = baseaddress+1;
               start_address = start_address+1;
            }
            else
            {
               // SrecLine[i++]='F';
               // SrecLine[i++]='F';
               sprintf(flsdata, "%02X", flsContent[baseaddress]);
               SrecLine[i++]=flsdata[0];
               SrecLine[i++]=flsdata[1];
               baseaddress = baseaddress+1;
               if (INTERNAL_MEM)
               {
                  start_address = 32752+MEM_Start_Address;
                  Footer = TRUE;
                  LargeSector = FALSE;
               }
               else
               {
                  // End = TRUE;
                  SmallSector = TRUE;
                  LargeSector = FALSE;

               }
            }
            itr++;
         }
      }
      else if (Footer)
      {
         if (INTERNAL_MEM)
         {

            for(int j=0; j<BYTES_PER_LINE; j++)
            {
               sprintf(flsdata, "%02X", flsContent[footeraddress]);
               SrecLine[i++]=flsdata[0];
               SrecLine[i++]=flsdata[1];
               footeraddress = footeraddress+1;
               start_address = start_address+1;
            }

             baseaddress += SMALL_SEC_START_ADDR - start_address;
             baseaddress = 0x18020UL;
             start_address = SMALL_SEC_START_ADDR;
             memorysize += SMALL_SEC_END_ADDR - SMALL_SEC_START_ADDR;

            //memorysize = 1024*1024*8;
            
         }
         // End = TRUE;
         SmallSector = TRUE;
         Footer = FALSE;
      }
      else if (SmallSector)
            {
               for (int j = 0; j < BYTES_PER_LINE; j++)
               {
                  if (memorysize - 1 > itr)
                  {
                     sprintf(flsdata, "%02X", flsContent[baseaddress]);
                     SrecLine[i++] = flsdata[0];
                     SrecLine[i++] = flsdata[1];
                     baseaddress = baseaddress + 1;
                     start_address = start_address + 1;
                  }
                  else
                  {
                     // SrecLine[i++]='F';
                     // SrecLine[i++]='F';
                     sprintf(flsdata, "%02X", flsContent[baseaddress]);
                     SrecLine[i++] = flsdata[0];
                     SrecLine[i++] = flsdata[1];
                     baseaddress = baseaddress + 1;
                     
                     SmallSector = FALSE;
                     End = TRUE;
                  }
                  itr++;
               }
            }

      #ifdef Little_Endian
         SwapEndian(&SrecLine[12],32); 
      #endif
      checksum=computeChecksumFromString(&SrecLine[2], i-2);
      sprintf(data, "%02X", checksum);
      SrecLine[i++] = data[0];
      SrecLine[i++] = data[1];
      SrecLine[i++] = '\r';
      SrecLine[i++] = '\n';
      totalline++;
      z++;
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
   //printf("\n Data:\t%X\n", data);
   //printf("\n Total Lines:\t%08X\n", totalline);
   
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