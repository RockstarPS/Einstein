/*
*
* Copyright (c) 2023 Texas Instruments Incorporated
*
* All rights reserved not granted herein.
*
* Limited License.
*
* Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
* license under copyrights and patents it now or hereafter owns or controls to make,
* have made, use, import, offer to sell and sell ("Utilize") this software subject to the
* terms herein.  With respect to the foregoing patent license, such license is granted
* solely to the extent that any such patent is necessary to Utilize the software alone.
* The patent license shall not apply to any combinations which include this software,
* other than combinations with devices manufactured by or for TI ("TI Devices").
* No hardware patent is licensed hereunder.
*
* Redistributions must preserve existing copyright notices and reproduce this license
* (including the above copyright notice and the disclaimer and (if applicable) source
* code license limitations below) in the documentation and/or other materials provided
* with the distribution
*
* Redistribution and use in binary form, without modification, are permitted provided
* that the following conditions are met:
*
* *       No reverse engineering, decompilation, or disassembly of this software is
* permitted with respect to any software provided in binary form.
*
* *       any redistribution and use are licensed by TI for use only with TI Devices.
*
* *       Nothing shall obligate TI to provide you with source code for the software
* licensed and provided to you in object code.
*
* If software source code is provided to you, modification and redistribution of the
* source code are permitted provided that the following conditions are met:
*
* *       any redistribution and use of the source code, including any resulting derivative
* works, are licensed by TI for use only with TI Devices.
*
* *       any redistribution and use of any object code compiled from the source code
* and any resulting derivative works, are licensed by TI for use only with TI Devices.
*
* Neither the name of Texas Instruments Incorporated nor the names of its suppliers
*
* may be used to endorse or promote products derived from this software without
* specific prior written permission.
*
* DISCLAIMER.
*
* THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL TI AND TI'S LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
* OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
* OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

 /**
 *  \file     Platform_Types.h
 *
 *  \brief    This file defines platform dependent types and symbols
 *
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#ifdef __cplusplus
extern "C"{
#endif



/*=============================================================================
|                       EXPORTED CONSTANTS and MACROS                         |
=============================================================================*/
/* [SWS_BSW_00059] Published information elements. */
/** \brief Vendor ID */
#define PLATFORM_VENDOR_ID  (44U)
/** \brief Module ID */
#define PLATFORM_MODULE_ID  (199U)

#if defined (AUTOSAR_421)

/** \brief AUTOSAR Version Major Number */
#define PLATFORM_AR_RELEASE_MAJOR_VERSION       (4U)
/** \brief AUTOSAR Version Minor Number */
#define PLATFORM_AR_RELEASE_MINOR_VERSION       (2U)
/** \brief AUTOSAR Version Revision Number */
#define PLATFORM_AR_RELEASE_REVISION_VERSION    (1U)

#else

/** \brief AUTOSAR Version Major Number */
#define PLATFORM_AR_RELEASE_MAJOR_VERSION       (4U)
/** \brief AUTOSAR Version Minor Number */
#define PLATFORM_AR_RELEASE_MINOR_VERSION       (3U)
/** \brief AUTOSAR Version Revision Number */
#define PLATFORM_AR_RELEASE_REVISION_VERSION    (1U)

#endif

/** \brief Version Major Number */
#define PLATFORM_SW_MAJOR_VERSION   (9U)
/** \brief Version Minor Number */
#define PLATFORM_SW_MINOR_VERSION   (0U)
/** \brief Version Revision Number */
#define PLATFORM_SW_PATCH_VERSION   (0U)


/*****************************************************************************/
/* GLOBAL DEFINITIONS                                                        */
/*****************************************************************************/
/* [SWS_Platform_00057] */
#define CPU_TYPE_8          (8)
#define CPU_TYPE_16         (16)
#define CPU_TYPE_32         (32)

#if defined (AUTOSAR_431)
#define CPU_TYPE_64         (64)
#endif

#define MSB_FIRST           (0)
#define LSB_FIRST           (1)

#define HIGH_BYTE_FIRST     (0)
#define LOW_BYTE_FIRST      (1)


/* [SWS_Platform_00064], [SWS_Platform_00044] and [SWS_Platform_00045] */
#define CPU_TYPE        (CPU_TYPE_32)

/* [SWS_Platform_00038], [SWS_Platform_00043] and [SWS_Platform_00048] */
#define CPU_BIT_ORDER   (LSB_FIRST)

/* [SWS_Platform_00039], [SWS_Platform_00046] and [SWS_Platform_00050] */
#define CPU_BYTE_ORDER  (LOW_BYTE_FIRST)

/* [SWS_Platform_00056] */
#ifndef TRUE
    #define TRUE        ((unsigned char)1U)
#endif

#ifndef FALSE
    #define FALSE       ((unsigned char)0U)
#endif

/*****************************************************************************/
/* TYPE DEFINITIONS                                                          */
/*****************************************************************************/
/* [SWS_Platform_00026] */
typedef unsigned char       boolean;

/* [SWS_Platform_00013] */
typedef unsigned char       uint8;
/* [SWS_Platform_00014] */
typedef unsigned short      uint16;
/* [SWS_Platform_00015] */
typedef unsigned int        uint32;
/* [SWS_Platform_00066] */
/* On R5F, long is 32 bits wide, long long is 64bits */
typedef unsigned long long  uint64;

/* [SWS_Platform_00016] */
typedef signed char         sint8;
/* [SWS_Platform_00017] */
typedef signed short        sint16;
/* [SWS_Platform_00018] */
typedef signed int          sint32;
/* NCHELLAP Typedef added for MathLib component */
typedef signed int          sint;

/* [SWS_Platform_00067] */
typedef signed long long sint64;

/* [SWS_Platform_00020] */
typedef unsigned int        uint8_least;
/* [SWS_Platform_00021] */
typedef unsigned int        uint16_least;
/* [SWS_Platform_00022] */
typedef unsigned int        uint32_least;
/* [SWS_Platform_00023] */
typedef signed int          sint8_least;
/* [SWS_Platform_00024] */
typedef signed int          sint16_least;
/* [SWS_Platform_00025] */
typedef signed int          sint32_least;

/* [SWS_Platform_00041] */
typedef float               float32;
/* [SWS_Platform_00042] */
typedef double              float64;
typedef uint8 Std_ReturnType;


 /* Register Access Macros */
 #define CSL_REG32_WR(p, v)      (CSL_REG32_WR_RAW( \
                                     (volatile uint32_t *) (p), (uint32_t) (v)))                         
 #define CSL_REG32_RD(p)         (CSL_REG32_RD_RAW((volatile uint32_t *) (p)))
 
 #define CSL_REG32_FINS(p, fld, v)   (CSL_REG32_FINS_RAW( \
                                         ((volatile uint32_t *) (p)), \
                                         ((uint32_t) CSL_##fld##_MASK), \
                                         ((uint32_t) CSL_##fld##_SHIFT), \
                                         ((uint32_t) v)))
 #define CSL_REG32_FEXT(p, fld)      (CSL_REG32_FEXT_RAW( \
                                         ((volatile uint32_t *) (p)), \
                                         ((uint32_t) CSL_##fld##_MASK), \
                                         ((uint32_t) CSL_##fld##_SHIFT)))

/**
 *  \brief   This macro reads a 8-bit value from a hardware register
 *           and returns the value.
 *
 *  \param   p      Address of the memory mapped hardware register.
 *
 *  \return  Unsigned 8-bit value read from a register.
 */
#define CSL_REG8_RD(p)          (CSL_REG8_RD_RAW((volatile uint8_t *) (p)))

/**
 *  \brief   This macro writes a 8-bit value to a hardware register.
 *
 *  \param   p       Address of the memory mapped hardware register.
 *  \param   v       Unsigned 8-bit value which has to be written to the
 *                   register.
 */
#define CSL_REG8_WR(p, v)       (CSL_REG8_WR_RAW( \
                                    (volatile uint8_t *) (p), (uint8_t) (v)))
 
 /**
  *  \brief   This function reads a 32-bit value from a hardware register
  *           and returns the value.
  *
  *  \param   p      Address of the memory mapped hardware register.
  *
  *  \return  Unsigned 32-bit value read from a register.
  */
 static inline uint32_t CSL_REG32_RD_RAW(volatile const uint32_t * const p);
 static inline uint32_t CSL_REG32_RD_RAW(volatile const uint32_t * const p)
 {
     return (*p);
 }
 
 /**
  *  \brief   This function writes a 32-bit value to a hardware register.
  *
  *  \param   p      Address of the memory mapped hardware register.
  *  \param   v      Unsigned 32-bit value which has to be written to the
  *                  register.
  */
 static inline void CSL_REG32_WR_RAW(volatile uint32_t * const p, uint32_t v);
 static inline void CSL_REG32_WR_RAW(volatile uint32_t * const p, uint32_t v)
 {
     *p = v;
     return;
 }
 
 /**
  *  \brief   This function reads a 32 bit register, modifies specific set of
  *           bits and writes back to the register.
  *
  *  \param   p      Address of the memory mapped hardware register.
  *  \param   mask   Mask for the bit field.
  *  \param   shift  Bit field shift from LSB.
  *  \param   v      Value to be written to bit-field.
  */
 static inline void CSL_REG32_FINS_RAW(volatile uint32_t * const p,
                                       uint32_t mask,
                                       uint32_t shift,
                                       uint32_t v);
 static inline void CSL_REG32_FINS_RAW(volatile uint32_t * const p,
                                       uint32_t mask,
                                       uint32_t shift,
                                       uint32_t v)
 {
     uint32_t regVal = CSL_REG32_RD_RAW(p);
     regVal = (regVal & ~(mask));
     regVal |= (v << shift) & mask;
     CSL_REG32_WR_RAW(p, regVal);
     return;
 }
 
 /**
  *  \brief   This function reads a 32 bit register, masks specific set of bits
  *           and returns the left shifted value.
  *
  *  \param   p      Address of the memory mapped hardware register.
  *  \param   mask   Mask for the bit field.
  *  \param   shift  Bit field shift from LSB.
  *
  *  \return  Bit-field value (absolute value - shifted to LSB position)
  */
 static inline uint32_t CSL_REG32_FEXT_RAW(volatile const uint32_t * const p,
                                           uint32_t mask,
                                           uint32_t shift);
 static inline uint32_t CSL_REG32_FEXT_RAW(volatile const uint32_t * const p,
                                           uint32_t mask,
                                           uint32_t shift)
 {
     uint32_t regVal = CSL_REG32_RD_RAW(p);
     regVal = (regVal & mask) >> shift;
     return (regVal);
 }

 /**
 *  \brief   This function reads a 8-bit value from a hardware register
 *           and returns the value.
 *
 *  \param   p      Address of the memory mapped hardware register.
 *
 *  \return  Unsigned 8-bit value read from a register.
 */
static inline uint8_t CSL_REG8_RD_RAW(volatile const uint8_t * const p);
static inline uint8_t CSL_REG8_RD_RAW(volatile const uint8_t * const p)
{
    return (*p);
}

/**
 *  \brief   This function writes a 8-bit value to a hardware register.
 *
 *  \param   p      Address of the memory mapped hardware register.
 *  \param   v      Unsigned 8-bit value which has to be written to the
 *                  register.
 */
static inline void CSL_REG8_WR_RAW(volatile uint8_t * const p, uint8_t v);
static inline void CSL_REG8_WR_RAW(volatile uint8_t * const p, uint8_t v)
{
    *p = v;
    return;
}



/**
 *  \brief This macro calls read-modify-write API for 32 bit register. It also
 *         frames the mask and shift from register field macro.
 *
 *  \param regAddr        Register Address.
 *  \param REG_FIELD      Peripheral register bit field name, to which specified
 *                        value has to be set.
 *  \param fieldVal       Value of the field which has to be set.
 */
#define HW_WR_FIELD32(regAddr, REG_FIELD, fieldVal)                            \
    (HW_WR_FIELD32_RAW((uint32) (regAddr), ((uint32)REG_FIELD##_MASK),                   \
                          ((uint32)REG_FIELD##_SHIFT), (uint32)(fieldVal)))

/**
 *  \brief This macro calls read field API for 32 bit register. It also
 *         frames the mask and shift from register field macro.
 *
 *  \param regAddr        Register Address.
 *  \param REG_FIELD      Peripheral register bit field name, from which
 *                        specified bit-field value has to be read.
 *  \return Value of the bit-field
 */
#define HW_RD_FIELD32(regAddr, REG_FIELD)                                      \
    (HW_RD_FIELD32_RAW((uint32) (regAddr), ((uint32) REG_FIELD##_MASK),                   \
                          ((uint32) REG_FIELD##_SHIFT)))


/**
 *  \brief   This macro reads a 32-bit value from a hardware register
 *           and returns the value.
 *
 *  \param   addr    Address of the memory mapped hardware register.
 *
 *  \return  Unsigned 32-bit value read from a register.
 */
#define HW_RD_REG32(addr) (HW_RD_REG32_RAW((uint32_t) (addr)))

/**
 *  \brief   This macro writes a 32-bit value to a hardware register.
 *
 *  \param   addr    Address of the memory mapped hardware register.
 *  \param   value   unsigned 32-bit value which has to be written to the
 *                   register.
 */
#define HW_WR_REG32(addr, value)                                               \
    (HW_WR_REG32_RAW((uint32_t) (addr), (uint32_t) (value)))

/**
 *  \brief   This function reads a 32-bit value from a hardware register
 *           and returns the value.
 *
 *  \param   addr    Address of the memory mapped hardware register.
 *
 *  \return  Unsigned 32-bit value read from a register.
 */
static inline uint32_t HW_RD_REG32_RAW(uint32_t addr);

/**
 *  \brief   This function writes a 32-bit value to a hardware register.
 *
 *  \param   addr    Address of the memory mapped hardware register.
 *  \param   value   unsigned 32-bit value which has to be written to the
 *                   register.
 */
static inline void HW_WR_REG32_RAW(uint32_t addr, uint32_t value);

static inline uint32_t HW_RD_REG32_RAW(uint32_t addr)
{
    uint32_t regVal = *(volatile uint32_t *) ((uintptr_t) addr);
    return (regVal);
}

static inline void HW_WR_REG32_RAW(uint32_t addr, uint32_t value)
{
    *(volatile uint32_t *) ((uintptr_t) addr) = value;
    return;
}

static inline uint32 HW_RD_FIELD32_RAW(uint32 addr,
                                         uint32 mask,
                                         uint32 shift);

static inline uint32 HW_RD_FIELD32_RAW(uint32 addr,
                                         uint32 mask,
                                         uint32 shift)
{
    uint32 regVal = *(volatile uint32 *) ((uintptr_t) addr);
    regVal = (regVal & mask) >> shift;
    return (regVal);
}
/**
 *  \brief   This function reads a 32 bit register, modifies specific set of
 *           bits and writes back to the register.
 *
 *  \param   addr    Address of the memory mapped hardware register.
 *  \param   mask    Mask for the bit field.
 *  \param   shift   Bit field shift from LSB.
 *  \param   value   Value to be written to bit-field.
 */
static inline void HW_WR_FIELD32_RAW(uint32 addr,
                                     uint32 mask,
                                     uint32 shift,
                                     uint32 value);

static inline void HW_WR_FIELD32_RAW(uint32 addr,
                                     uint32 mask,
                                     uint32 shift,
                                     uint32 value)
{
    uint32 regVal = *(volatile uint32 *) ((uintptr_t) addr);
    regVal &= (~mask);
    regVal |= (value << shift) & mask;
    *(volatile uint32 *) ((uintptr_t) addr) = regVal;
    return;
}
#ifdef __cplusplus
}
#endif

#endif /* PLATFORM_TYPES_H_ */
