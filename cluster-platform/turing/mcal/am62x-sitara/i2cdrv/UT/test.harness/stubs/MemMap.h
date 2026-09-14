/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2024. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/* ***** I2c File Memory Segments ****** */


#ifdef I2C_START_SEC_CODE_ISR
#undef I2C_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_0841 */
#pragma clang section text="I2C_ISR_TEXT_SECTION"
#endif

#ifdef I2C_STOP_SEC_CODE_ISR
#undef I2C_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_0841 */
#pragma clang section text= ""
#endif

#ifdef I2C_SEC_CODE_START
#pragma clang section text = ".I2cCode"
#undef I2C_SEC_CODE_START
#endif

#ifdef I2C_SEC_CODE_STOP
#pragma clang section text = ""
#undef I2C_SEC_CODE_STOP
#endif

#ifdef I2C_CORE_CONST_SEC_START
#pragma clang section rodata = ".I2cConst"
#undef I2C_CORE_CONST_SEC_START
#endif

#ifdef I2C_CORE_CONST_SEC_END
#pragma clang section rodata = ""
#undef I2C_CORE_CONST_SEC_END
#endif

#ifdef I2C_CORE_DATA_SEC_START
#pragma clang section data = ".I2cdata"
#undef I2C_CORE_DATA_SEC_START
#endif

#ifdef I2C_CORE_DATA_SEC_END
#pragma clang section data = ""
#undef I2C_CORE_DATA_SEC_END
#endif

#ifdef I2C_CORE_BSS_SEC_START
#pragma clang section bss = ".I2cBss"
#undef I2C_CORE_BSS_SEC_START
#endif

#ifdef I2C_CORE_BSS_SEC_END
#pragma clang section bss = ""
#undef I2C_CORE_BSS_SEC_END
#endif

