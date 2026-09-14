/************************************************************************/
/*               (C) Fujitsu Semiconductor Europe GmbH (FSEU)           */
/*                                                                      */
/* The following software deliverable is intended for and must only be  */
/* used for reference and in an evaluation laboratory environment.      */
/* It is provided on an as-is basis without charge and is subject to    */
/* alterations.                                                         */
/* It is the user's obligation to fully test the software in its        */
/* environment and to ensure proper functionality, qualification and    */
/* compliance with component specifications.                            */
/*                                                                      */
/* In the event the software deliverable includes the use of open       */
/* source components, the provisions of the governing open source       */
/* license agreement shall apply with respect to such software          */
/* deliverable.                                                         */
/* FSEU does not warrant that the deliverables do not infringe any      */
/* third party intellectual property right (IPR). In the event that     */
/* the deliverables infringe a third party IPR it is the sole           */
/* responsibility of the customer to obtain necessary licenses to       */
/* continue the usage of the deliverable.                               */
/*                                                                      */
/* To the maximum extent permitted by applicable law FSEU disclaims all */
/* warranties, whether express or implied, in particular, but not       */
/* limited to, warranties of merchantability and fitness for a          */
/* particular purpose for which the deliverable is not designated.      */
/*                                                                      */
/* To the maximum extent permitted by applicable law, FSEU's liability  */
/* is restricted to intentional misconduct and gross negligence.        */
/* FSEU is not liable for consequential damages.                        */
/*                                                                      */
/* (V1.5)                                                               */
/************************************************************************/

/*!
 * \author      Fujitsu GCC Neuried
 * \version     0.01
 * \date        2010
 * \file        sm_util.h
 *              Emerald driver
 * \brief       This is just a helper implementation for development and will be removed in the final version.
 *
 *
 * \attention  THIS SAMPLE CODE IS PROVIDED AS IS.
 *             FUJITSU MICROELECTRONICS ACCEPTS NO RESPONSIBILITY OR LIABILITY
 *             FOR ANY ERRORS OR OMMISSIONS.
 */

#ifndef GDC_SURF_UTIL_H
#define GDC_SURF_UTIL_H
#ifdef __cplusplus
extern "C"
{
#endif

/** @addtogroup common Tutorial Utility Library
    @{
 **/

/*******************************************************************************
 Includes
*******************************************************************************/
#ifdef DEBUG
#include "stdio.h"
#endif /* DEBUG */
#include <iris_drv.h>

/*******************************************************************************
 Macro Definitions
*******************************************************************************/

/** This macro avoids execution if the previous instruction failed. */
static void Break(MM_S32 rc, char const *function, char const*file, int line)
{
    /* you can set a breakpoint here to detect failure of a function */
#ifdef PRINTF_AVAILABLE
    printf("Error 0x%08x in %s (%s line %d)\n", rc, function, file, line);
#endif
}
#define UTIL_SUCCESS(rc, execute)                              \
    do                                                         \
    {                                                          \
        if (rc == MML_OK)                                      \
        {                                                      \
           rc = (execute);                                     \
           if (rc != MML_OK)                                   \
            Break(rc, __FUNCTION__, __FILE__, __LINE__);       \
        }                                                      \
    } while(0)

/*******************************************************************************
 Data Types
*******************************************************************************/

/* N/A */

/*******************************************************************************
 Variables
*******************************************************************************/

/* N/A */

/*******************************************************************************
 Function Prototypes
*******************************************************************************/

/* N/A */

/*******************************************************************************
 Function Definitions
*******************************************************************************/

/**
 * Read a bitmap structure in memory and set the realated surface attributes
 * Please note the surface object must be created before. No memory will be
 * allocated in this function. The pImage pointer will be increased by the
 * size of the whole image so it points to the next image object if further
 * images are in the memory block.
 *  @param surf The surface object
 *  @param pImage address of the pointer to the image
 *  @return MML_OK on success, otherwise the related error code.
 **/
MM_S32 utSurfReadBitmap(MML_GDC_SURFACE surf, void **pImage);

/**
 * Read a bitmap structure, set the realated surface attributes, allocate
 * the required memory for pixel and CLUT buffer and copy the related data.
 * Please note the surface object must be created before.
 * Please use #utDeleteBuffer to delete the buffers before deleting
 * the surface object.
 *  @param surf The surface object
 *  @param pImage pointer to the image
 *  @param bCopyToVRAM MM_TRUE if the bitmap and color look up table memory should be
 *      copied into VRAM.
 *  @return MML_OK on success, otherwise the related error code.
 **/
MM_S32 utSurfLoadBitmap(MML_GDC_SURFACE surf, const void *pImage, MM_BOOL bCopyToVRAM);

/**
 * Return the width of a given surface object
 *  @param surf The surface object
 *  @return width of the surface.
 **/
int utSurfWidth(MML_GDC_SURFACE surf);

/**
 * Return the height of a given surface object
 *  @param surf The surface object
 *  @return height of the surface.
 **/
int utSurfHeight(MML_GDC_SURFACE surf);

/**
 * Create a buffer with the given dimension and color format and set the
 * related surface object properties.
 * Please use #utDeleteBuffer to delete the buffers before deleting
 * the surface object.
 * Please note the surface object must be created before.
 *  @param surf The surface object
 *  @param w width of the surface
 *  @param h height of the surface
 *  @param eFormat the requested color format
 *  @return MML_OK on success, otherwise the related error code.
 **/
MM_S32 utCreateBuffer(MML_GDC_SURFACE surf, MM_U32 w, MM_U32 h, MML_GDC_SURF_FORMAT eFormat);

/**
 * Delete the surface buffers.
 *  @param surf The surface object
 **/
void utDeleteBuffer(MML_GDC_SURFACE surf);

#ifdef WIN32
/**
 * Store the RGB image described by the surface object im ppm format
 * Please note not all possible surface formates are supported.
 *  @param surface The surface object
 *  @param pName Location and name for the target file
 *  @return MML_OK on success, otherwise the related error code.
 **/
MM_S32 utSavePPM(MML_GDC_SURFACE surf, char *pName);

/**
 * Store the aplha part of the image described by the surface object im ppm format
 * Please note not all possible surface formates are supported.
 *  @param surface The surface object
 *  @param pName Location and name for the target file
 *  @return MML_OK on success, otherwise the related error code.
 **/
MM_S32 utSaveAlphaPPM(MML_GDC_SURFACE surf, char *pName);
#endif

/**
 * Get the r, g, b, a pixel data of a surface at position x, y.
 * The pixel with the coordinates 0, 0 is the upper, left pixel
 * analoge to the the memory organisation of the memory buffer.
 * Please note that this is different to the glReadPixels specification.
 * Please note not all possible surface formates are supported.
 *  @param surf The surface object
 *  @param x x positon of the pixel
 *  @param y y positon of the pixel
 *  @param r pointer to get the red value
 *  @param g pointer to get the green value
 *  @param b pointer to get the blue value
 *  @param a pointer to get the alpha value
 *  @return MML_OK on success, otherwise the related error code.
 **/
MM_S32 utSurfGetPixel(MML_GDC_SURFACE surf, MM_U32 x, MM_U32 y, MM_U08 *r, MM_U08 *g, MM_U08 *b, MM_U08 *a);

/**
 * Set the r, g, b, a pixel data of a surface at position x, y
 * The pixel with the coordinates 0, 0 is the upper, left pixel
 * analoge to the the memory organisation of the memory buffer.
 * Please note that this is different to the glReadPixels specification.
 * Please note not all possible surface formates are supported.
 *  @param surf The surface object
 *  @param x x positon of the pixel
 *  @param y y positon of the pixel
 *  @param r new red value
 *  @param g new green value
 *  @param b new blue value
 *  @param a new alpha value
 *  @return MML_OK on success, otherwise the related error code.
 **/
MM_S32 utSurfSetPixel(MML_GDC_SURFACE surf, MM_U32 x, MM_U32 y, MM_U08 r, MM_U08 g, MM_U08 b, MM_U08 a);

/**
    @}
 **/

#ifdef __cplusplus
}
#endif
#endif /* GDC_SURF_UTIL_H */


