#define _CRT_SECURE_NO_WARNINGS

#include "bmp_loader.h"
#include <stdio.h>
#include <stdlib.h>

#define L	printf
//#define L	

BmpData * BmpLoader(char *fileName)
{
	FILE *fp = NULL;
	fp = fopen(fileName,"rb");
	
	int pixelsStartOffset = 0;
	int totalBytesPerLine = 0;
	int currentCounter = 0;
	int i = 0, j = 0;
	
	if(fp == NULL)
	{
		printf("\n not able to open file %s ", fileName);
		return 0;
	}

	L("\nReading BMP Header.....");
	
	L("\nChecking BM.....");
	char temp = fgetc(fp);
	if(temp != 'B')
	{
		printf("\nnot in bmp file format %s ", fileName);
		return 0;
	}
	temp = fgetc(fp);
	if(temp != 'M')
	{
		printf("\nnot in bmp file format %s ", fileName);
		return 0;
	}	
	L("\nChecking BM Success.....");

	BmpData *imageData = (BmpData *)malloc(sizeof(BmpData));

	fseek ( fp , 0xA , SEEK_SET );
	fread(&pixelsStartOffset,4,1,fp);
	L("\nRead pixelStartOffset %d ", pixelsStartOffset);

	fseek ( fp , 0x12 , SEEK_SET );
	fread(&imageData->width,4,1,fp);
	L("\nRead width %d ", imageData->width);

	fseek ( fp , 0x16 , SEEK_SET );
	fread(&imageData->height,4,1,fp);
	L("\nRead height %d ", imageData->height);

	fseek ( fp , 0x1C , SEEK_SET );
	fread(&imageData->noBitPerPixel,2,1,fp);
	L("\nRead noBitPerPixel %d ", imageData->noBitPerPixel);

	totalBytesPerLine = (((imageData->width+1)*3)>>2)<<2;

	imageData->data =  (unsigned char *)malloc( imageData->height * totalBytesPerLine);

	if(imageData->data == NULL)
	{	
		L("\nNot able to allocated memeory....");
	}


	fseek ( fp , 0x36 , SEEK_SET );
	for(i = 0; i < imageData->height; i ++)
	{
		for(j = 0; j < imageData->width; j ++)
		{
			imageData->data[currentCounter + 2] = fgetc(fp);		//R
			imageData->data[currentCounter + 1] = fgetc(fp);		//G
			imageData->data[currentCounter + 0] = fgetc(fp);		//B
			currentCounter += 3;
		}

		for(; currentCounter < totalBytesPerLine; currentCounter ++)
		{
			imageData->data[currentCounter] = 0;
		}
	}

	imageData->format = BMP_RGB_888;

	fclose(fp);

	return imageData;
}

void BmpFree(BmpData *data)
{
	// if(data != 0)
	// {
		// if(data->data != 0)
			// free data->data;

		// free data;
	// }
}
