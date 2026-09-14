#include <stdio.h>
#include "Std_Types.h"
#include "SrecMake.h"
#include "Srec_Gen_Cfg.h"

#define SREC_MAX_LINE_CHARS               (200)

uint32 start_address=MEM_Start_Address;
char hdr[6]="484452";
uint32 sreclinesize =20u;
uint32 baseaddress = 32u;
//uint32 footeraddress = 12048u;    //+baseaddress
uint32 footeraddress = 32784u;
uint32 basesize = 100u;
uint32 totalline =0u;

static void writeS0rec(FILE *file);
static void writeS3rec(FILE *file);
static void writeS5rec(FILE *file);
static void writeS7rec(FILE *file);
//static void writeS9rec(FILE *file);
static uint8 computeChecksumFromString(char *data, uint8 length);
static void SwapEndian(char *data, uint8 length);

void srec_main(uint8 nthVariant){

   FILE *srecFile;
   char name[20];
   sprintf(name,"../../out/srec/srec_var%d.srec",nthVariant+1);
   srecFile = fopen(name, "wb");
   if(srecFile!=NULL){

      writeS0rec(srecFile);
      writeS3rec(srecFile);
      writeS5rec(srecFile);
      writeS7rec(srecFile);
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

static void writeS3rec(FILE *file)
{

   uint8   *flsContent;
   uint32  address;
   uint16  size;
   uint32 memorysize = 65536;
   
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
               start_address = 32752+MEM_Start_Address;
               Footer = TRUE;
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