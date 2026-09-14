
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <fcntl.h>

#define CRC_MAX_FILE_NAME 256
#define CRC_TYPE_MAX 6
#define DYN_EXP(val, mask, shift) (val | ((val & mask) >> shift))
#define CRC_MISR_POLYNOMIAL 0x0FC22F87
#define CRC_LOG_SEVERITY_ERROR 0x00000001
#define CRC_LOG_SEVERITY_WARNING 0x00000002
#define CRC_LOG_SEVERITY_CRITICAL_INFO 0x00000004
#define CRC_LOG_SEVERITY_INFO 0x00000008
#define TWO_BITS_MSB 0xC0000000
#define FIRST_BYTE_MASK 0x000000FF
#define SECOND_BYTE_MASK 0x0000FF00
#define THIRD_BYTE_MASK 0x00FF0000
#define BITMASK_0_9 0x000003FF
#define BITMASK_10_19 0x000FFC00
#define BITMASK_20_29 0x3FF00000
#define BITMASK_2_11 0x00000FFC
#define BITMASK_12_21 0x003FF000
#define BITMASK_22_31 0xFFC00000
#define FIRST_BYTE_OFFSET 0
#define SECOND_BYTE_OFFSET 8
#define THIRD_BYTE_OFFSET 16
#define HW_COLOR_BIT_DEPTH 10

#define DEFAULT_IN_WIDTH 128
#define DEFAULT_IN_HEIGHT 128

#define CRC_LOG_SEVERITY (CRC_LOG_SEVERITY_ERROR | CRC_LOG_SEVERITY_WARNING | CRC_LOG_SEVERITY_INFO | CRC_LOG_SEVERITY_CRITICAL_INFO)

#define CRC_LOG_ERROR(fmt, ...) \
do \
{ \
	if (CRC_LOG_SEVERITY & CRC_LOG_SEVERITY_ERROR) \
	{ \
	printf("CRC_ERROR " fmt, ##__VA_ARGS__); \
	printf("\n"); \
	} \
	} while (0)

#define CRC_LOG_WARNING(fmt, ...) \
do \
{ \
	if (CRC_LOG_SEVERITY & CRC_LOG_SEVERITY_WARNING) \
	{ \
		printf("CRC_WARNING " fmt, ##__VA_ARGS__); \
		printf("\n"); \
	} \
} while (0)

#define CRC_LOG_CRITICAL_INFO(fmt, ...) \
do \
{ \
if (CRC_LOG_SEVERITY & CRC_LOG_SEVERITY_CRITICAL_INFO) \
	{ \
		printf(fmt, ##__VA_ARGS__); \
		printf("\n");\
	}\
}while (0)
#define CRC_LOG_INFO(fmt, ...) \
do \
{ \
	if (CRC_LOG_SEVERITY & CRC_LOG_SEVERITY_INFO) \
	{ \
		printf(fmt, ##__VA_ARGS__); \
		printf("\n"); \
	} \
} while (0)

/* -----------------------------------------------------------------------------
* Structures and Enumerations
* ---------------------------------------------------------------------------*/
typedef enum
{
	CRC_FORMAT_NONE = 0,
	CRC_FORMAT_RGBA8888,
	CRC_FORMAT_RGB888,
	CRC_FORMAT_BGRA1010102,
	CRC_FORMAT_RGBA1010102
} CRC_ColorFormatType;
typedef struct
{
	CRC_ColorFormatType eFormat; // Change spacing
	char pcTag[20];
	bool bHasAlpha;
	int iBytesPerPixel;
	int iBitsPerComponent;
	int iRoiColorOrder[3];
	unsigned uBitMasks[3];
	unsigned uOffsets[3];
} CRC_ColorInfoType;

/* Image additional properties like resoultion */
typedef struct 
{
	int iWidth;
	int iHeight;
	// Line padding enabled or not
	bool bLinePadding;
	// dummy lines per iLinePadConst,
	int  iLinePadConst;
} CRC_ImagePropType;

/* -----------------------------------------------------------------------------
* Global Variables
* ---------------------------------------------------------------------------*/
CRC_ColorInfoType gColorFormatInfo[] =
{
	{
		CRC_FORMAT_RGB888,
		"RGB888",
		false,
		3,
		8,
		{1, 2, 0},
		{0xFF, 0xFF00, 0xFF0000},
		{0, 8, 16}
	},
	{
		CRC_FORMAT_RGBA8888,
		"RGBA8888",
		true,
		4,
		8,
		{1, 2, 0},
		{FIRST_BYTE_MASK, SECOND_BYTE_MASK, THIRD_BYTE_MASK},
		{FIRST_BYTE_OFFSET, SECOND_BYTE_OFFSET, THIRD_BYTE_OFFSET}
	},
	{
		CRC_FORMAT_RGBA1010102,
		"RGBA1010102",
		true,
		4,
		10,
		{1, 2, 0},
		{BITMASK_0_9, BITMASK_10_19, BITMASK_20_29},
		{0, 10, 20}
	},
	{
		CRC_FORMAT_BGRA1010102,
		"BGRA1010102",
		true,
		4,
		10,
		{0, 2, 1},
		{BITMASK_0_9, BITMASK_10_19, BITMASK_20_29},
		{0, 10, 20}
	}
};


/* -----------------------------------------------------------------------------
* Private Functions
* ---------------------------------------------------------------------------*/


/*****
* Function: CRC_Create_Mask
*
* Description: Used to create a mask for a 32 bit payload starting at bit
* number "uStart" and going to bit number "uEnd"
******************************************************************************/
unsigned CRC_Create_Mask(
unsigned uStart,
unsigned uEnd)
{
	unsigned uMask = 0;
	unsigned uI = 0;
	for (uI = uStart; uI <= uEnd; uI++)
	{
		uMask |= (1 << uI);
	}
	return uMask;
}

/*******************************************************************************
* Function: UpdateMISR
*
* Description: Performs MISR calculation to update "uMISR" value given
* the color components "uColorComps"
*
******************************************************************************/
size_t UpdateMISR(unsigned *uColorComps, size_t uMISRLocal, bool bAlpha)
{
	size_t uConstant = 0;
	unsigned int uSurface = 0;
	if (false == bAlpha)
	{
		uSurface = 0x00 | (uColorComps[0]) | (uColorComps[1] << HW_COLOR_BIT_DEPTH) | (uColorComps[2] << (HW_COLOR_BIT_DEPTH * 2));
	}
	else
	{
		uSurface = uColorComps[3];
	}
	uConstant = ((uMISRLocal & 0x80000000) > 0x00000000) ? CRC_MISR_POLYNOMIAL : 0x00000000;
	/* Calculate current uMISR value */
	uMISRLocal = (uMISRLocal << 1) ^ uConstant ^ uSurface;
	return uMISRLocal;
}
/*******************************************************************************
* Function: Convert888To101010
*
* Description: Converts rgb888 colour components "uColorComps" into 10 bit
* color components
*
******************************************************************************/
void Convert888To101010(unsigned *uColorComps)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		uColorComps[i] = (uColorComps[i] << 2);
		uColorComps[i] = DYN_EXP(uColorComps[i], 0x300, 8);
	}
}
/*******************************************************************************
* Function: CRC_Calc_MISR
*
* Description: Calculates the "eCrcType" CRC types given an input image
* "pcImage", its size "uSizeInBytes", and color information "psColorInfo"
******************************************************************************/
size_t CRC_Calc_MISR(
char *pcImage,
size_t uSizeInBytes,
CRC_ColorInfoType *psColorInfo, CRC_ImagePropType* psImgProp)
{
	static size_t uMISR = 0; /* ROI CRC */
	size_t uIdx = 0;
	char *pcSourceByte = NULL;
	size_t uNumPixels = 0;
	unsigned int uBitsPerComp = 0; /* Bits per color component in image */
	unsigned int uCombinedSource = 0;
	unsigned int uColorComps[4] = {0, 0, 0, 0}; /* R, G, B, A */
	int iLineCount = 0;
	int iPaddedLines = 0;

	if ((NULL != pcImage) && (NULL != psColorInfo))
	{
		pcSourceByte = pcImage;
		uNumPixels = uSizeInBytes / psColorInfo->iBytesPerPixel;
		uBitsPerComp = psColorInfo->iBitsPerComponent;
		CRC_LOG_INFO("%s :: uNumPixels %ld  :: BytesPerPixel %d \n",__FUNCTION__,uNumPixels, psColorInfo->iBytesPerPixel);
		for (uIdx = 0; uIdx < uNumPixels; uIdx++)
		{
			/* Combine all bytes into one 32 bit integer */
			uCombinedSource = *((unsigned int *)pcSourceByte);
			/* Caluclate ROI MISR value */
			uColorComps[psColorInfo->iRoiColorOrder[0]] = ((uCombinedSource & psColorInfo->uBitMasks[0]) >> psColorInfo->uOffsets[0]);
			uColorComps[psColorInfo->iRoiColorOrder[1]] = ((uCombinedSource & psColorInfo->uBitMasks[1]) >> psColorInfo->uOffsets[1]);
			uColorComps[psColorInfo->iRoiColorOrder[2]] = ((uCombinedSource & psColorInfo->uBitMasks[2]) >> psColorInfo->uOffsets[2]);
			if(8 == uBitsPerComp){
				/* Convert rgb888 components to 10 bit components */
				Convert888To101010(uColorComps);
			}
			uMISR = UpdateMISR(uColorComps, uMISR, false);
				/* Jump to next Pixel */
			pcSourceByte += psColorInfo->iBytesPerPixel;

			if (psImgProp && (true == psImgProp->bLinePadding))
			{
				if ((uIdx+1)%(psImgProp->iWidth) == 0 )
				{
					iLineCount ++;
					if ((iLineCount%psImgProp->iLinePadConst) == 0)
					{
							iPaddedLines++;
							for (int j = 0 ; j < psImgProp->iWidth ; j++)
							{
								unsigned int uDummySource = 0;//empty pixel
								/* Caluclate ROI MISR value */
								uColorComps[psColorInfo->iRoiColorOrder[0]] = ((uDummySource & psColorInfo->uBitMasks[0]) >> psColorInfo->uOffsets[0]);
								uColorComps[psColorInfo->iRoiColorOrder[1]] = ((uDummySource & psColorInfo->uBitMasks[1]) >> psColorInfo->uOffsets[1]);
								uColorComps[psColorInfo->iRoiColorOrder[2]] = ((uDummySource & psColorInfo->uBitMasks[2]) >> psColorInfo->uOffsets[2]);
								if(8 == uBitsPerComp){
									/* Convert rgb888 components to 10 bit components */
									Convert888To101010(uColorComps);
								}
								uMISR = UpdateMISR(uColorComps, uMISR, false);
							}
					}
				}
			}
		}
	}
	if (psImgProp && (true == psImgProp->bLinePadding))
	{
		CRC_LOG_INFO("Line Padding Included ! LineCount ::%d :: dummyLine %d  \n", iLineCount , iPaddedLines);
	}
	return uMISR;
}

void CRC_Print_Help(void)
{
	int iI = 0;
	int iNumColorInfo = 0;
	CRC_ColorInfoType *psColorInfo = NULL;
	CRC_LOG_CRITICAL_INFO(
			"\n"
			"MISR:: ROI CRC Calculator\n"
			"\n"
			"\n"
			"Given a raw input file and its color format & img prop and display padding info, this tool will calculate its ROI CRC\n"
			"that would match the CRC generated by the DPU HW.\n"
			"\n"
			"\n"
			"Usage:\n"
			"\n"
			" layer_crc_calc.exe -f <file_name> -c <color_format> -w width -h height -p <<optional> display padding ratio> > \n"
			"\n"
			"\n"
			" <color_format> supported:\n");
	iNumColorInfo = sizeof(gColorFormatInfo) / sizeof(CRC_ColorInfoType);
	for (iI = 0; iI < sizeof(gColorFormatInfo) / sizeof(CRC_ColorInfoType); iI++)
	{
		CRC_LOG_CRITICAL_INFO(" %s", gColorFormatInfo[iI].pcTag);
	}
	CRC_LOG_CRITICAL_INFO(
			"\n"
			" <color_format> convention used:\n"
			" - A letter denotes the color component: red (r), green (g), blue (b), alpha (a)\n"
			" - A number denotes the bits per color component\n");
}
/* -----------------------------------------------------------------------------
* Main
* ---------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
	int iArgLen = 0;
	int iArgIdx = 1;
	bool bFoundFileName = false;
	bool bFoundColorFormat = false;

	CRC_ColorFormatType eColorFormat = CRC_FORMAT_NONE;
	size_t uFileSizeInBytes = 0;
	char *pcImage = NULL;
	int iFD = -1;
	size_t uNumBytesRead = 0;
	size_t ROICRC;
	int iIdx = 0;
	int iNumColorInfo = 0;
	CRC_ColorInfoType *psColorInfo = NULL;
	struct stat sStat = {0};
	char pcFileName[CRC_MAX_FILE_NAME];
	if (5 > argc)
	{
		//minimum 5
		CRC_Print_Help();
		goto end;
	}
	memset(pcFileName, 0x00, sizeof(char) * CRC_MAX_FILE_NAME);
	memset((char *)&sStat, 0x00, sizeof(struct stat));
	CRC_ImagePropType sImgProp;
	sImgProp.iWidth = DEFAULT_IN_WIDTH;
	sImgProp.iHeight = DEFAULT_IN_HEIGHT;
	sImgProp.bLinePadding = false;

	while (iArgIdx < argc)
	{
		iArgLen = strlen(argv[iArgIdx]);
		//CRC_LOG_INFO("%s %d", argv[iArgIdx], iArgLen);
		if (0 == strcmp("-f", argv[iArgIdx]))
		{
			iArgIdx++;
			iArgLen = strlen(argv[iArgIdx]);
			if (CRC_MAX_FILE_NAME < iArgLen)
			{
				CRC_LOG_ERROR(
						"File name length (%d) exceeds max file name length (%d)",
						iArgLen, CRC_MAX_FILE_NAME);
				goto end;
			}
			else
			{
				memcpy(pcFileName, argv[iArgIdx], iArgLen);
				bFoundFileName = true;
				CRC_LOG_CRITICAL_INFO("File Name = %s", pcFileName);
			}

		}
		else if (0 == strcmp("-c", argv[iArgIdx]))
		{
			iArgIdx++;//take value
			iArgLen = strlen(argv[iArgIdx]);
			iNumColorInfo = sizeof(gColorFormatInfo) / sizeof(CRC_ColorInfoType);
			for (iIdx = 0; iIdx < iNumColorInfo; iIdx++)
			{
				
				psColorInfo = &gColorFormatInfo[iIdx];
				if ((strlen(psColorInfo->pcTag) == iArgLen) &&
						(0 == strcmp(psColorInfo->pcTag, argv[iArgIdx])))
				{
					eColorFormat = psColorInfo->eFormat;
					bFoundColorFormat = true;
					CRC_LOG_CRITICAL_INFO("Color Format = %s", psColorInfo->pcTag);
					break;//must  break here
				}
				
			}
			if (false == bFoundColorFormat)
			{
				CRC_LOG_ERROR("Color format %s NOT supported", argv[iArgIdx]);
				goto end;
			}
		}
		else if (0 == strcmp("-w", argv[iArgIdx]))
		{
			iArgIdx++;//take value
			sImgProp.iWidth = strtoul (argv[iArgIdx], NULL, 0);
		}
		else if (0 == strcmp("-h", argv[iArgIdx]))
		{
			iArgIdx++;//take value
			sImgProp.iHeight = strtoul (argv[iArgIdx], NULL, 0);
		}
		else if (0 == strcmp("-p", argv[iArgIdx]))
		{
			iArgIdx++;//take value
			sImgProp.bLinePadding = true;
			sImgProp.iLinePadConst = strtoul (argv[iArgIdx], NULL, 0);
		}
		else
		{
			CRC_LOG_ERROR("Option %s not supported", argv[iArgIdx]);
			
		}
		iArgIdx++;//increment to next
	}
	if ((false == bFoundFileName) || (false == bFoundColorFormat))
	{
		CRC_LOG_ERROR("Not enough information to continue");
		goto end;
	}
	stat(pcFileName, &sStat);
	uFileSizeInBytes = sStat.st_size;
	CRC_LOG_INFO("files size = %ld", uFileSizeInBytes);
	if (0 == uFileSizeInBytes)
	{
		CRC_LOG_ERROR("File does not exist or size is zero");
		goto end;
	}
	pcImage = (char *)malloc(uFileSizeInBytes);
	if (NULL == pcImage)
	{
		CRC_LOG_ERROR("Not enough memory to allocate read buffer for pcImage");
		goto end;
	}
	memset(pcImage, 0x00, uFileSizeInBytes);
	iFD = open(pcFileName, O_RDONLY, 0);
	if (-1 == iFD)
	{
		CRC_LOG_ERROR("Failed to open file %s", pcFileName);
		goto end;
	}
	uNumBytesRead = read(iFD, pcImage, uFileSizeInBytes);
	CRC_LOG_CRITICAL_INFO("Image Resolution:: %d x %d \n", sImgProp.iWidth, sImgProp.iHeight);
	if (true == sImgProp.bLinePadding)
	{
		CRC_LOG_CRITICAL_INFO("Padding constant => %d \n", sImgProp.iLinePadConst);
	}
	ROICRC = CRC_Calc_MISR(pcImage, uFileSizeInBytes, psColorInfo, &sImgProp);
	CRC_LOG_CRITICAL_INFO("ROI CRC = 0x%08X",(unsigned int) ROICRC);
end:

	if (NULL != pcImage)
	{
		free(pcImage);
	}
	if (-1 != iFD)
	{
		close(iFD);
	}
	return 0;
}
