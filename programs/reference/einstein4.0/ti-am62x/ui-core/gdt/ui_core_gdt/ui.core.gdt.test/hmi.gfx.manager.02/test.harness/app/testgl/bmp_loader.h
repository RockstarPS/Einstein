#ifndef __bmp_loader_H__
#define __bmp_loader_H__

///DESGIN : QUICK AND DIRTY...CKS

enum 
{
	BMP_RGB_888,
	BMP_BGR_888,
	BMP_RGB_565,
};

typedef struct 
{
	unsigned char *data;
	int width;
	int height;
	int noBitPerPixel;
	int format;

}BmpData;

extern BmpData *BmpLoader(char *fileName);

extern void BmpFree(BmpData *data);

#endif //__bmp_loader_H__
