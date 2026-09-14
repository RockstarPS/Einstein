
#include <GL/glew.h>
#include "iris_pixformat.h"
#include <assert.h>
// cluts
#include "mm_defines.h"
#include "mm_types.h"
#include "mml_gdc_surfman.h"  

#define colorMASK(m) ((unsigned) (((m) < 25) ? ((255U << (m))) : 0xff000000U))
#define BITMASK(m) ((unsigned) (((m) < 32) ? ((1U << (m)) - 1U) : 0xffffffffU))

#define colorMASK2(m,c) ((unsigned) (((m) < 25) ? (((1<<c)-1) << (m)) : 0xff000000U))

typedef struct 
{
    unsigned char* pBuffer;
    unsigned int   curWordIx;
    unsigned int   curBitIx;
} Bitstream;

static int LogTable[256];

#ifdef _deb_simul
#include <iostream>
#include <fstream>
#include <iomanip>      // std::setw
using namespace std;

static int DebTable[256], deb_idx=0;
int idx;
void  LogToFile(const char* pFileName,int sz,unsigned char * pD)
{
    std::ofstream outf(pFileName,ios::trunc);

    outf<<"    ";

    for(idx=0; idx<sz; idx++)
    {
        if(((idx%16)==0) && (idx!=0))
        {
            outf<< endl;
            outf<<"    ";
        }
        // outf << "0x" << std::hex << setw(2) << (int)(pD[idx]) << ",";
        outf << "0x" <<  hex << setfill('0') << setw(2) << (int)(pD[idx]) <<", ";
    }

    outf.close(); // explicitly close the file
}
#endif

static void CleanDynamicRam(bool isSrcBufTemp, unsigned char &isWorkDynamic, unsigned char* pSrc)
{
    if(isSrcBufTemp == 1)
    {
        if(isWorkDynamic)
        {
            delete pSrc;
        }
        else
        {
            isWorkDynamic = true;
        }
    }
}

void IrisPixFormat_Init(void)
{
    for(int i = 0; i < 256;i++)
    {
        unsigned r = 0;
        unsigned t = i;
        while (t) { t >>= 1; r++; };
        
        LogTable[i] = r;
    }
}


static unsigned int readBitsRLC(unsigned char* pSrc, unsigned* pBitPos, int nBits)
{
    unsigned result;
    unsigned * rld = (unsigned*)pSrc;
    /* r bits left in the current word k */
    unsigned kWords = *pBitPos / 32;
    unsigned rBits = 32 - (*pBitPos % 32); /* 1..32 */
    unsigned dBits;

    nBits = (nBits >= 32)? 32: nBits;

    /* r >= n, n = r - d:
    * put n bits to current word at offset d
    */
    if (rBits >= nBits)
    {
        dBits = rBits-nBits; /*  0..31 */
        result = (rld[kWords] >> dBits) & BITMASK(nBits);
    }
    /* r < n, n = r + d:
    * put r bits to current word at offset 0
    * put d bits to next word at offset 32-d
    */
    else
    {
        dBits = nBits-rBits; /* 1..31 */

        result = rld[kWords] & (BITMASK(rBits));
        result = (result << dBits);
        result |= (rld[kWords+1] >> (32 - dBits));
    }

    //assert(result < 0xffffff);

    *pBitPos += nBits;

    return result;
}

static unsigned calcBufSize(unsigned width, unsigned height, unsigned bpp)
{
    unsigned result = (width * bpp + 7) / 8;

    return result * height;
}

static void writeBitsPixel(unsigned char* pDst, unsigned* pBitPos, unsigned* pixelIx, unsigned bufWidth, int nBits, unsigned int value)
{
    //writeBitsPixel(pDst, &dstBitIx, &pixelIx, width, bpp, pixel);
    unsigned char * rld = (unsigned char*)pDst;

    nBits = (nBits >= 32)? 32: nBits;

    if (16 == nBits)
    {
        value = ((value << 8) & 0xff00) | ((value >> 8) & 0x00ff);
    }
    else if (32 == nBits)
    {
        value = ((value << 24) & 0xff000000) | ((value << 8) & 0x00ff0000) | \
                ((value >> 8) & 0x0000ff00) | ((value >> 24) & 0x000000ff);
    }

    while(nBits > 0)
    {
        /* r bits left in the current word k */
        unsigned kWords = *pBitPos / 8;
        unsigned rBits = 8 - (*pBitPos % 8); /* 1..32 */
        unsigned dBits;

        value &= BITMASK(nBits);

        if (rBits >= nBits)
        {
            dBits = rBits-nBits; /*  0..31 */
            rld[kWords] &= ~(BITMASK(nBits)<<dBits);
            rld[kWords] |= (value<<dBits);

            (*pBitPos) += nBits;
            nBits = 0;
        }
        else
        {
            dBits = nBits-rBits; /* 1..31 */
            rld[kWords] &= ~BITMASK(rBits);
            rld[kWords] |= (value >> dBits);

            nBits -= rBits;
            value &= BITMASK(nBits);

            (*pBitPos) += rBits;
        }
    }

    (*pixelIx)++;
    if(*pixelIx >= bufWidth)
    {
        *pBitPos = (*pBitPos + 7) / 8 * 8;
        *pixelIx = 0;
    }
}

static void createPixel(unsigned int* pRGBA, IRIS2_Surface* pSurf, PixBufferCache* pCache, unsigned * pD, unsigned color)
{
    unsigned  pS[4];

    if(pSurf->bitperpixel == 16 && pSurf->colorbits == 0x05060500 && pSurf->colorshift == 0x0B050000)
    {
        pS[0] = pRGBA[0]<<3;
        pS[1] = pRGBA[1]<<2;
        pS[2] = pRGBA[2]<<3;

        pD[0]= 255<<24 | pS[2]<<16 | pS[1]<<8 | pS[0];
    }
    else if(pSurf->bitperpixel == 32 && pSurf->colorbits == 0x08080808 && pSurf->colorshift == 0x10080018)
    {
        //MML_GDC_SURF_FORMAT_A8R8G8B8
        pS[0] = pRGBA[0];
        pS[1] = pRGBA[1];
        pS[2] = pRGBA[2];
        pS[3] = pRGBA[3];

        pD[0]= pS[3]<<24 | pS[2]<<16 | pS[1]<<8 | pS[0];
    }
    else if(pSurf->bitperpixel == 24 && pSurf->colorbits == 0x08080800 && pSurf->colorshift == 0x10080000)
    {
        pS[0] = pRGBA[0];
        pS[1] = pRGBA[1];
        pS[2] = pRGBA[2];
        pD[0]= 255<<24 | pS[2]<<16 | pS[1]<<8 | pS[0];

    }
    else if(pSurf->bitperpixel == 8 && pSurf->colorbits == 0x00000008 && pSurf->colorshift == 0x00000000)
    {
        pD[0]= pRGBA[0]<<24 | (color&0xFFFFFF) ;
    }
    else if(pSurf->bitperpixel == 0x00000010 && pSurf->colorbits == 0x04040404 && pSurf->colorshift == 0x0804000c)
    { //MML_GDC_SURF_FORMAT_A4R4G4B4
        pS[0] = pRGBA[0]<<4;
        pS[1] = pRGBA[1]<<4;
        pS[2] = pRGBA[2]<<4;
        pS[3] = pRGBA[3]<<4;;
        pD[0]= pS[3]<<24 | pS[2]<<16 | pS[1]<<8 | pS[0];
    }
    else
    {   // todo
        assert(0);
    }
}

static void decodeRLC(unsigned char* pSrc, unsigned int srcSize, unsigned char* pDst, unsigned int dstSize, unsigned int bpp, unsigned width, unsigned height)
{
    unsigned int srcBitIx, dstBitIx;
    unsigned pixelIx = 0;
    unsigned pixels = 0;
     
    srcBitIx = 0; dstBitIx = 0;
    while(srcBitIx < (srcSize * 32) && (pixels < width*height))
    {
        unsigned char srcVal = readBitsRLC(pSrc, &srcBitIx, 8);
        assert(srcVal < 256);

        if(srcVal & 0x80) // compressed
        {
            unsigned int size = (0x7f & srcVal) + 1;
            unsigned int pixel = readBitsRLC(pSrc, &srcBitIx, bpp); 

            while(size > 0)
            {
                pixels++;
                writeBitsPixel(pDst, &dstBitIx, &pixelIx, width, bpp, pixel);
                size--;
            }
        }
        else // not compressed
        {
            unsigned int size = srcVal + 1;

            while(size > 0)
            {
                unsigned int pixel = readBitsRLC(pSrc, &srcBitIx, bpp); 
                pixels++;
                writeBitsPixel(pDst, &dstBitIx,&pixelIx, width, bpp, pixel);
                size--;
            }
        }
    }

    assert(((dstBitIx + 7 ) / 8) == dstSize);
}

static unsigned int readBitsRLA(Bitstream* bs, int count)
{
    unsigned int* pWords = (unsigned int*)bs->pBuffer;
    unsigned int pos = bs->curBitIx;
    unsigned __int64 d = pWords[bs->curWordIx];

    bs->curBitIx += count;

    if (bs->curBitIx >= 32)
    {
        bs->curWordIx++;
        d |= (unsigned __int64)pWords[bs->curWordIx] << 32;
        bs->curBitIx -= 32;
    }

    return (unsigned int)((d >> pos) & ((1 << count) - 1));
}

static void decodeRLA(IRIS2_Surface* pSurf, PixBufferCache* pCache, unsigned color)
{
#define NUM_C 4
    unsigned int pixIx, colIx, x;
    unsigned bpc[NUM_C];
    unsigned bitPos = 0;
    unsigned pixelPos = 0;
    unsigned int pixelIx = 0;
    Bitstream src;  

    pCache->pBuffer = new unsigned char[pSurf->DispSize * 4];
    unsigned * pD = (unsigned*)pCache->pBuffer;

    x = 0;
    src.curBitIx = 0;
    src.curWordIx = 0;
    src.pBuffer = pSurf->pBuffer;

    bpc[0] = (pSurf->colorbits >> 24) & 0xff;
    bpc[1] = (pSurf->colorbits >> 16) & 0xff;
    bpc[2] = (pSurf->colorbits >> 8 ) & 0xff;
    bpc[3] = (pSurf->colorbits      ) & 0xff;
   
    while(1)
    {
        unsigned type, cnt, pcnt;
        unsigned cbpc[NUM_C], col_bias[NUM_C];
        unsigned col_prev[NUM_C], sofs[NUM_C];
        unsigned pixel[NUM_C];

        // read package header
        type = readBitsRLA(&src, 1); 
        cnt = readBitsRLA(&src, 5); // count of pixels

        for (colIx = 0; colIx < NUM_C; colIx++)
        {
            assert(bpc[colIx] < 256);
            cbpc[colIx] = readBitsRLA(&src, LogTable[bpc[colIx]]); // the count of bits per channel
        }
        
        for (colIx = 0; colIx < NUM_C; colIx++) 
        {
            col_bias[colIx] = readBitsRLA(&src, bpc[colIx]); // bias
        }

        pcnt = cnt + 1;
        if ((x + pcnt) > pSurf->width) 
        {
            pcnt = pSurf->width - x; // package always ends at end of line
        }

        // Decode pixels from the package
        for(pixIx = 0; pixIx < pcnt; pixIx++)
        {
            for (colIx = 0; colIx < NUM_C; colIx++) 
            {
                unsigned int cdat = readBitsRLA(&src, cbpc[colIx]);

                if (type == 0) // offset type
                {
                    pixel[colIx] = col_bias[colIx] + cdat;
                }
                else // delta type
                {
                    if (pixIx == 0) 
                    {
                        pixel[colIx] = col_bias[colIx];
                        sofs[colIx] = cdat;
                    }
                    else
                    {
                        pixel[colIx] = col_prev[colIx] + cdat - sofs[colIx]; // all subsequent pixels
                    }
                }                                        
                
                pixel[colIx] &= 0xff;

                col_prev[colIx] = pixel[colIx];
            } 

            createPixel(pixel, pSurf, pCache, pD, color);
            pD++;
            pixelIx++;

            x++;
            if(pSurf->width >= x) x = 0;
        
        } // pixIx
        if(pixelIx >= pSurf->DispSize) break;
    }
    pCache->oglFormat = GL_RGBA;
    pCache->oglType = GL_UNSIGNED_BYTE; 
    pCache->isBufferDynamic     = true; //isWorkDynamic
    pCache->color = color;
}

static unsigned char MskArr[8]=
{
	0x01,	//0
	0x02,	//1
	0x04,	//2
	0x08,	//3
	0x10,	//4
	0x20,	//5
	0x40,	//6
	0x80	//7
};

void CreatetClutTbl(IRIS2_Surface* pSurf, PixBufferCache* pCache)
{
    unsigned &oglFormat = (pCache->oglFormat);
    unsigned &oglType = pCache->oglType;
    unsigned char* &pWork = pCache->pBuffer;
    unsigned char &isWorkDynamic = (pCache->isBufferDynamic);
    unsigned* pClutTbl;
    unsigned char* pClutAddr = (unsigned char*)pSurf->pClutBufferAddress;

    pClutTbl = new unsigned int[pSurf->ClutCount];

    if(pSurf->ClutFormat == MML_GDC_SURF_CLF_R8G8B8)
    {
        for(unsigned i=0;i<pSurf->ClutCount;i++)
        { //AARRGGBB
            pClutTbl[i] = 0xFF<<24 | pClutAddr[i*3+2]<<16 | pClutAddr[i*3+1]<<8 | pClutAddr[i*3+0]; 
        }

    }
    else if(pSurf->ClutFormat == MML_GDC_SURF_CLF_B8G8R8)
    {
        for(unsigned i=0;i<pSurf->ClutCount;i++)
        { //AARRGGBB
            pClutTbl[i] = 0xFF<<24 | pClutAddr[i*3+2] | pClutAddr[i*3+1]<<8 | pClutAddr[i*3+0]<<16; 
        }
    }
    else if(pSurf->ClutFormat == MML_GDC_SURF_CLF_R5G5B5)
    {
        for(unsigned i=0;i<pSurf->ClutCount;i++)
        { //AARRGGBB
            pClutTbl[i] = 0xFF<<24 | pClutAddr[i*3+2]<<19 | pClutAddr[i*3+1]<<11| pClutAddr[i*3+0]<<3; 
        }
    }
    else if(pSurf->ClutFormat == MML_GDC_SURF_CLF_A1R5G5B5)
    {
        for(unsigned i=0;i<pSurf->ClutCount;i++)
        { //AARRGGBB
            pClutTbl[i] = (pClutAddr[i*4+3]*0xFF)<<24 | pClutAddr[i*4+2]<<19 | pClutAddr[i*4+1]<<11| pClutAddr[i*4+0]<<3; 
        }
    }
    else if(pSurf->ClutFormat == MML_GDC_SURF_CLF_A4R4G4B4)
    {
        for(unsigned i=0;i<pSurf->ClutCount;i++)
        { //AARRGGBB
            pClutTbl[i] = (pClutAddr[i*4+3])<<28 | pClutAddr[i*4+2]<<20 | pClutAddr[i*4+1]<<12| pClutAddr[i*4+0]<<4; 
        }
    }
    else
    {   // missing format
        assert(0);  
    }

    unsigned char* pS;
    unsigned * pD;
    pS = pSurf->pBuffer;
    pD = new unsigned [pSurf->DispSize ];
    pWork = (unsigned char*)pD;

	if(pSurf->bitperpixel==16)
	{
        unsigned char fl_color_idx;
		unsigned char fl_alpha;
		unsigned int  fl_color;
		unsigned short* pS_short =  (unsigned short*)pSurf->pBuffer;;
		for(int i = 0; i < pSurf->DispSize; i++)
		{
            fl_alpha = ((pS_short[i] >> 8) & 0xFF);
			fl_color_idx = (pS_short[i] & 0xFF);
			fl_color = pClutTbl[fl_color_idx];
            fl_color &= 0xFFFFFF;
			fl_color |= (fl_alpha << 24);
			pD[i] = fl_color; 
		}
	}
	else if(pSurf->bitperpixel==8)
	{
		for(int i = 0; i < pSurf->DispSize; i++)
		{
			pD[i] = pClutTbl[pS[i]]; 
		}
	}
	else if(pSurf->bitperpixel==4)
	{
	    unsigned tmp=0;
	    unsigned tmp2=0;
	    for(int i = 0; i < pSurf->DispSize; i++)
		{
			tmp2 = ((pS[0] >> tmp) & 0xF);
			pD[i] = pClutTbl[tmp2];
			tmp += 4;
			if(tmp>=8)
			{
				pS++;
				tmp=0;
			}
		}

	}
	else if(pSurf->bitperpixel==2)
	{
		unsigned tmp=0;
		unsigned tmp2=0;
		for(int i = 0; i < pSurf->DispSize; i++)
		{
			tmp2 = ((pS[0] >> tmp) & 0x3);
			pD[i] = pClutTbl[tmp2];
			tmp += 2;
			if(tmp>=8)
			{
				pS++;
				tmp=0;
			}
		}
	}
	else if(pSurf->bitperpixel==1)
	{
		unsigned tmp=0;
		for(int i = 0; i < pSurf->DispSize; i++)
		{
			if((pS[0]&MskArr[tmp])==0)
			{
				pD[i] = pClutTbl[0];
			}
			else
			{
				pD[i] = pClutTbl[1];
			}

			tmp++;
			if(tmp>7)
			{
				pS++;
				tmp=0;
			}
		}
	}
	else
	{	
		assert(0);
	}

    delete pClutTbl;

    oglFormat = GL_RGBA;
    oglType = GL_UNSIGNED_BYTE; 
    isWorkDynamic = true;
}
static void NoColorConvert(PixBufferCache* pCache, unsigned char* pSrc, bool bAlpha)
{
	if(bAlpha)
	{
		pCache->oglFormat = GL_RGBA;
	}
	else
	{
		pCache->oglFormat = GL_RGB;
	}
	pCache->oglType = GL_UNSIGNED_BYTE; 
	pCache->pBuffer = pSrc; 
	pCache->isBufferDynamic = false;
}

template <typename Ta>
static void ColorConvert(PixBufferCache* pCache, IRIS2_Surface* pSurf, unsigned char* pSrc, bool bAlphaAvailable, Ta type )
{
    unsigned colshifts = pSurf->colorshift;
	unsigned colorbits = pSurf->colorbits;
	unsigned cr,cg,cb,ca;
    unsigned aMsk, rMsk,gMsk,bMsk;
    unsigned r,g,b,a;
    Ta *pS = (Ta *)pSrc;
    unsigned *pD;
    unsigned sz = pSurf->DispSize;

    pCache->oglFormat = GL_RGBA;
    pCache->oglType = GL_UNSIGNED_BYTE;
    pCache->isBufferDynamic = true;

    pD = new unsigned [sz];
    pCache->pBuffer = (unsigned char*) pD;

    r = (colshifts & 0xFF000000)>>24;
	cr = (colorbits & 0xFF000000)>>24; 
    rMsk= colorMASK2(r,cr);
	cr=r-(8-cr);

    g = (colshifts & 0xFF0000)>>16;
	cg = (colorbits & 0xFF0000)>>16;
    gMsk= colorMASK2(g,cg);
	cg=8+(8-cg)-g;

    b = (colshifts & 0xFF00)>>8;
	cb = (colorbits & 0xFF00)>>8;
    bMsk= colorMASK2(b,cb);
	cb=16-b+(8-cb);

	if(bAlphaAvailable)
	{
		a = (colshifts & 0xFF);
		ca = (colorbits & 0xFF);
		aMsk= colorMASK(a);
		ca=24-a+(8-ca);
		for(int idx = 0; idx < sz; idx++)
		{
			// var view abgr
			// memory rgba
			pD[idx]= (pS[idx]&aMsk)<<ca | (pS[idx]&bMsk)<<cb | (pS[idx]&gMsk)<<cg | (pS[idx]&rMsk)>>cr;
		}
	}
	else
	{
		for(int idx = 0; idx < sz; idx++)
		{
			// var view abgr
			// memory rgba
			pD[idx]= (0xFF)<<24 | (pS[idx]&bMsk)<<cb | (pS[idx]&gMsk)<<cg | (pS[idx]&rMsk)>>cr ;
		}
	}
}

void IrisPixFormat_Convert(IRIS2_Surface* pSurf,  unsigned color, PixBufferCache* pCache, bool bCached)
{
    unsigned &oglFormat = (pCache->oglFormat);
    unsigned &oglType = pCache->oglType;
    unsigned char* &pWork = pCache->pBuffer;
    unsigned char &isWorkDynamic = (pCache->isBufferDynamic);
    unsigned char isReverseTexture = 0;
    bool isSrcBufTemp = 0;
    unsigned char* pSrc;
    unsigned * pClutTbl=0;

#ifdef _deb_simul

    if(deb_idx>255) 
    {
        deb_idx=0;
    }
    DebTable[deb_idx++]=pSurf->width;
    DebTable[deb_idx++]=pSurf->compression;
#endif    
    // uncompress the content, if needed
    if(pSurf->compression != 4)
    {
        int size;
        assert(pSurf->compression == 2 || pSurf->compression == 3);
     
        switch(pSurf->compression)
        {
        case 2: // RLA
            decodeRLA( pSurf, pCache,  color);
            return;

            break;
        case 3: // RLC
            size = calcBufSize(pSurf->width, pSurf->height, pSurf->bitperpixel);
            pSrc = new unsigned char[size];
            isSrcBufTemp = 1;
            decodeRLC(pSurf->pBuffer, pSurf->sizeinbytes, pSrc, size, pSurf->bitperpixel, pSurf->width, pSurf->height);
            break;
        }
    }
    else
    {       
        if(pSurf->ClutMode != eNoClut)
        {
            CreatetClutTbl(pSurf, pCache);
            return;
        }
        else
        {   // create and fill buffer if not existing 
            pSrc = (unsigned char*)pSurf->pBuffer;
            if(pSrc==0)
            {
                unsigned * pTmp = new unsigned int[pSurf->DispSize];
				unsigned ct=(color&0xFF)<<24 | (color&0xFF00)<<8 | (color&0xFF0000)>>8 | (color&0xFF000000)>>24;

                for(int i=0; i<pSurf->DispSize; i++)
                {
                    pTmp[i]= ct;
                }
                pSrc = (unsigned char*)pTmp;
                isWorkDynamic = true;
                isSrcBufTemp = 1;
            }
        }
    }

    // Do format conversion
    if(pSurf->bitperpixel == 16 && pSurf->colorbits == 0x05060500 && pSurf->colorshift == 0x0B050000)
    { // MML_GDC_SURF_FORMAT_R5G6B5
		//ColorConvert16(pCache,pSurf, pSrc,false);
		ColorConvert(pCache,pSurf, pSrc, false, (short)16);
    }
    else if(pSurf->bitperpixel == 32 && pSurf->colorbits == 0x08080808 && pSurf->colorshift == 0x10080018)
    { // MML_GDC_SURF_FORMAT_A8R8G8B8
        ColorConvert(pCache,pSurf, pSrc, true, (unsigned)32);
    }
    else if(pSurf->bitperpixel == 18 && pSurf->colorbits == 0x06060600 && pSurf->colorshift == 0x0C060000)
    { // MML_GDC_SURF_FORMAT_R6G6B6
		NoColorConvert(pCache,pSrc, false);
    }
    else if(pSurf->bitperpixel == 24 && pSurf->colorbits == 0x08080800 && pSurf->colorshift == 0x10080000)
    { // MML_GDC_SURF_FORMAT_R8G8B8
        oglFormat = GL_RGBA;
        oglType = GL_UNSIGNED_BYTE; 
        pWork = pSrc; 
        isWorkDynamic = false;

        unsigned char * pS;
        unsigned  * pD;
        unsigned sz = pSurf->DispSize ;

        oglFormat = GL_RGBA;
        oglType = GL_UNSIGNED_BYTE; 
        isWorkDynamic = true;

        pD = new unsigned [sz];
        pS = pSrc;
        pWork = (unsigned char*)pD;

        int j=0;
        for(int i=0; i<sz; i++)
        {
            // var view abgr
            // memory rgba
            //pD[i]=pS[0]<<16|pS[1]<<8|pS[2]<<0 |255<<24;
            pD[i]= 255<<24 | pS[0]<<16| pS[1]<<8 | pS[2]<<0;
            pS+=3;
        }
    }
    else if(pSurf->bitperpixel == 8 && pSurf->colorbits == 0x03020300 && pSurf->colorshift == 0x05030000)
    { // MML_GDC_SURF_FORMAT_RGB8
		NoColorConvert(pCache,pSrc, false);
    }
    else if(pSurf->bitperpixel == 8 && pSurf->colorbits == 0x00000008 && pSurf->colorshift == 0x00000000)
    { // MML_GDC_SURF_FORMAT_A8
        oglFormat = GL_ALPHA;
        oglType = GL_UNSIGNED_BYTE; 
        pWork = pSrc;
        isWorkDynamic = false;
    }
    else if(pSurf->bitperpixel == 4 && pSurf->colorbits == 0x00000004 && pSurf->colorshift == 0x00000000)
    { // MML_GDC_SURF_FORMAT_A4
        unsigned char * pS= pSrc;   
        unsigned int i, j;
        unsigned int color2 =  (0xFF & (color >> 24)) | ( 0xFF00 & (color >> 8)) | (0xFF0000 & (color << 8));
        unsigned * pD;
        unsigned tmp;

        oglFormat = GL_RGBA;
        oglType = GL_UNSIGNED_BYTE; 
        isWorkDynamic = true;
        pWork = new unsigned char[pSurf->DispSize * 4];
        pD =(unsigned *) pWork;

        for(i = 0; i < pSurf->height; i++)
        {
            for(j = 0; j < (pSurf->width / 2); j++)
            {
                tmp = (pS[j] & 0xf)*0x11000000;
                pD[0] = color2 + tmp;

                tmp = (pS[j] >> 4 )*0x11000000;
                pD[1] = color2 + tmp;

                pD += 2;
            }
            pS += (pSurf->width / 2);

            if((pSurf->width % 2) != 0)
            {
                tmp = (pS[0] & 0xf)*0x110000000;
                pD[0] = color2 + tmp;

                pD += 1;            
                pS += 1;
            }
        }
    }
  #if 0  //Need to update it clearly
	else if(pSurf->bitperpixel == 1 && pSurf->colorbits == 0x00000001 && pSurf->colorshift == 0x00000000)
    { // MML_GDC_SURF_FORMAT_A1
        unsigned char * pS= pSrc;   
        unsigned int i, j;
        unsigned int color2 =  (0xFF & (color >> 24)) | ( 0xFF00 & (color >> 8)) | (0xFF0000 & (color << 8));
        unsigned * pD;
        unsigned tmp;

        oglFormat = GL_RGBA;
        oglType = GL_UNSIGNED_BYTE; 
        isWorkDynamic = true;
        pWork = new unsigned char[pSurf->DispSize * 8];
        pD =(unsigned *) pWork;

        for(i = 0; i < pSurf->height; i++)
        {
            for(j = 0; j < (pSurf->width / 8); j++)
            {
				unsigned tmp=0;
				unsigned tmp2=0;
				unsigned idx=0;
				unsigned cnt=0;

				for(;cnt<8;)
				{
				   tmp2 = ((pS[j] >> tmp) & 0x1)*0x44000000;
				   pD[idx] = color2 + tmp2;
				   tmp++;
				   idx++;
				   if(tmp>=8)
				   {
					 cnt = tmp;
					 tmp=0;
					 idx=0;
				   }
				}
				pD += 8;

				pS += (pSurf->width / 8);
				if((pSurf->width % 2) != 0)
				{
				   tmp = (pS[0] & 0x1)*0x440000000;
				   pD[0] = color2 + tmp;

				   pD += 1;            
				   pS += 1;
				}
            }
        }
    }
  #endif
    else if(pSurf->bitperpixel == 32 && pSurf->colorbits == 0x08080808 && pSurf->colorshift == 0x00081018)
    { // MML_GDC_SURF_FORMAT_A8B8G8R8
        ColorConvert(pCache,pSurf,pSrc, true, (unsigned)32);
    }
    else if(pSurf->bitperpixel == 16 && pSurf->colorbits == 0x04040404 && pSurf->colorshift == 0x0C080400)
    { // MML_GDC_SURF_FORMAT_R4G4B4A4
		ColorConvert(pCache,pSurf, pSrc, true, (short)16);
    }
    else if(pSurf->bitperpixel == 16 && pSurf->colorbits == 0x04040404 && pSurf->colorshift == 0x0804000C)
    { // MML_GDC_SURF_FORMAT_A4R4G4B4
		ColorConvert(pCache,pSurf, pSrc, true, (unsigned short)16);
    }
	else if(pSurf->bitperpixel == 16 && pSurf->colorbits == 0x05050501 && pSurf->colorshift == 0x0A05000F)
    { // MML_GDC_SURF_FORMAT_A1R5G5B5
		ColorConvert(pCache,pSurf, pSrc, true, (unsigned short)16);
    }
    else if(pSurf->bitperpixel == 32 && pSurf->colorbits == 0x08080808 && pSurf->colorshift == 0x18100800)
    {//MML_GDC_SURF_FORMAT_R8G8B8A8
		NoColorConvert(pCache,pSrc, true);
    }
    else  
    { 
		// so far covered all GDT supported formats
		// unprocessed type. Need to be coded
        assert(0);

        //      /**< 32 bpp RGBA format. */
        //MML_GDC_SURF_FORMAT_B8G8R8A8,     /**< 32 bpp BGRA format. */
        //MML_GDC_SURF_FORMAT_R8G8B8X8,     /**< 32 bpp RGB format. */
        //MML_GDC_SURF_FORMAT_X8B8G8R8,     /**< 32 bpp BGR format. */
        //MML_GDC_SURF_FORMAT_X8R8G8B8,     /**< 32 bpp RGB format. */
        //MML_GDC_SURF_FORMAT_B8G8R8,       /**< 24 bpp BGR format. */
        //MML_GDC_SURF_FORMAT_R5G5B5A1,     /**< 16 bpp RGBA format (5 bit for RGB, 1 bit alpha). */
        //MML_GDC_SURF_FORMAT_A1B5G5R5,     /**< 16 bpp ABGR format (5 bit for RGB, 1 bit alpha). */
        //MML_GDC_SURF_FORMAT_B5G5R5A1,     /**< 16 bpp BGRA format (5 bit for RGB, 1 bit alpha). */
        //MML_GDC_SURF_FORMAT_A4RGB4,       /**< 8 bpp, A4RGB4 can be used for gray or indexed image buffers with additional alpha value.
        //MML_GDC_SURF_FORMAT_A2,           /**< 2 bpp alpha format, can be used (e.g., as text buffer or external alpha mask buffer). */
        //MML_GDC_SURF_FORMAT_A1,           /**< 1 bpp alpha format, can be used (e.g., as text buffer or external alpha mask buffer) */
        //MML_GDC_SURF_FORMAT_YVYU422,
        //MML_GDC_SURF_FORMAT_VYUY422
    }
   
    CleanDynamicRam(isSrcBufTemp, isWorkDynamic, pSrc);
}

