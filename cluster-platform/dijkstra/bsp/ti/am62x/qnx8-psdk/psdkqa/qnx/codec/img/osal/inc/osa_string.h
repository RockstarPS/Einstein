/*****************************************************************************
*
* Copyright (c) Imagination Technologies Ltd.
* Copyright (c) 2018-22 Texas Instruments Incorporated - http://www.ti.com/
*
* The contents of this file are subject to the MIT license as set out below.
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHERa
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*
* Alternatively, the contents of this file may be used under the terms of the
* GNU General Public License Version 2 ("GPL")in which case the provisions of
* GPL are applicable instead of those above.
*
* If you wish to allow use of your version of this file only under the terms
* of GPL, and not to allow others to use your version of this file under the
* terms of the MIT license, indicate your decision by deleting the provisions
* above and replace them with the notice and other provisions required by GPL
* as set out in the file called "GPLHEADER" included in this distribution. If
* you do not delete the provisions above, a recipient may use your version of
* this file under the terms of either the MIT license or GPL.
*
* This License is also included in this distribution in the file called
* "MIT_COPYING".
*
*****************************************************************************/
/*
 * osa string management defintions
 *
 * Copyright (c) 2019 Texas Instruments Incorporated - http://www.ti.com/
 */

#ifndef OSA_STRING_H_
#define OSA_STRING_H_

#include "osa_types.h"

/**
 * osa_memcpy - copy memory from src to dst
 * @dst - destination adress
 * @src - source address
 * @bytes - size in bytes to copy
 *
 * Returns a pointer to dst
 */
void *osa_memcpy(void *dst, void *src, uint32 bytes);

/**
 * osa_memset - fill memory with specified value
 * @ptr - address of memory
 * @val - value to use to fill memory
 * @bytes - size in bytes to fill
 *
 * Returns a pointer to address filled
 */
void *osa_memset(void *ptr, uint32 val, uint32 bytes);

/**
 * osa_memmove - copy memory area
 *
 * @dst - destination area
 * @src - source area
 * @bytes - bytes to move
 *
 * Returns a pointer to dst
 */
void *osa_memmove(void *dst, void *src, uint32 bytes);

/**
 * osa_strcmp - compare two strings
 * @str1 - address of string 1 to compare
 * @str2 - address of string 2 to compare
 *
 * Returns 0 if the strings match, and non-zero value
 * if they do not match.
 */
int osa_strcmp(const osa_char *str1, const osa_char *str2);

/**
 * osa_strncmp - compare two strings for n bytes
 * @str1 - address of string 1
 * @str2 - address of string 2
 * @size - max size in bytes to compare
 *
 * Returns 0 if the strings match, and non-zero value
 * if they do not match.
 */
int osa_strncmp(const osa_char *str1, const osa_char *str2, uint32 size);

#endif /* OSA_STRING_H_ */
