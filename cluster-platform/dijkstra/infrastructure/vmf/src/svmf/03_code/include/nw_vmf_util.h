/*****************************************************************************/
/* Copyright Statement                                                       */
/* CONFIDENTIAL - VISTEON CORPORATION                                        */
/* This is an unpublished work, which contains trade secrets, created in     */
/* 2008. Visteon Corporation owns all rights to this work and intends        */
/* to maintain it in confidence to preserve its trade secret status. Visteon */
/* Corporation reserves the right, under the copyright laws of the United    */
/* States or those of any other country that may have jurisdiction, to       */
/* protect this work as an unpublished copyright work in the event of an     */
/* inadvertent or deliberate unauthorized publication. Visteon Corporation   */
/* also reserves its rights under the copyright laws to protect this work    */
/* as a published work, when appropriate. Those having access to this work   */
/* may not copy it, use it or disclose the information contained in it       */
/* without the written authorization of Visteon Corporation.                 */
/*****************************************************************************/

/*************************************************************************//**

  \file                 nw_vmf_util.h
  \brief                header file with some useful utils

  \author               Joerg Merkle
  \author               Visteon Deutschland GmbH, Infotainment Software

  *****************************************************************************/
#ifndef __VMF_UTIL_H__
#define __VMF_UTIL_H__

/* jmerkle  #include "nw_vmf_debug.h" */


/*! Macro for pointer argument check \n
    check if pointer == NULL then error \n\n
    NOTE: In case of error 'return with error-code' is called!! \n
        \param[in]  _pre_msg_  -- additional text like function name from where called.
        \param[in]  _pointer_  -- pointer to check */
#define NW_VMF_ARG_CHECK_POINTER(_pre_msg_, _pointer_)                  \
            if (NULL == _pointer_)                                      \
            {                                                           \
                NW_VMF_DEBUG_ERROR((_pre_msg_));                        \
                NW_VMF_DEBUG_ERROR((" --> NULL POINTER!\n"));           \
                return (vmf_ret_t)VMF_ERR_NULL_POINTER;                 \
            }

/*! Macro for argument check \n
    if argument > limit then ok else error \n\n
    NOTE: In case of error 'return with error-code' is called!! \n
        \param[in]  _pre_msg_ -- additional text like function name from where called.
        \param[in]  _val_     -- argument to be checked.
        \param[in]  _limit_   -- limit to check against. */
#define NW_VMF_ARG_CHECK_BIGGER(_pre_msg_, _val_, _limit_)              \
            if (_val_ <= _limit_)                                       \
            {                                                           \
                NW_VMF_DEBUG_ERROR((_pre_msg_));                        \
                NW_VMF_DEBUG_ERROR((" --> TOO SMALL!\n"));              \
                return (vmf_ret_t)VMF_ERR_OUT_OF_RANGE;                 \
            }

/*! Macro for argument check \n
    if argument >= limit then ok else error \n\n
    NOTE: In case of error 'return with error-code' is called!! \n
        \param[in]  _pre_msg_ -- additional text like function name from where called.
        \param[in]  _val_     -- argument to be checked.
        \param[in]  _limit_   -- limit to check against. */
#define NW_VMF_ARG_CHECK_BIGGER_OR_EQUAL(_pre_msg_, _val_, _limit_)     \
            if (_val_ < _limit_)                                        \
            {                                                           \
                NW_VMF_DEBUG_ERROR((_pre_msg_));                        \
                NW_VMF_DEBUG_ERROR((" --> TOO SMALL!\n"));              \
                return (vmf_ret_t)VMF_ERR_OUT_OF_RANGE;                 \
            }

/*! Macro for argument check \n
    if argument < limit then ok else error \n\n
    NOTE: In case of error 'return with error-code' is called!! \n
        \param[in]  _pre_msg_ -- additional text like function name from where called.
        \param[in]  _val_     -- argument to be checked.
        \param[in]  _limit_   -- limit to check against. */
#define NW_VMF_ARG_CHECK_SMALLER(_pre_msg_, _val_, _limit_)             \
            if (_val_ >= _limit_)                                       \
            {                                                           \
                NW_VMF_DEBUG_ERROR((_pre_msg_));                        \
                NW_VMF_DEBUG_ERROR((" --> TOO BIG\n"));                 \
                return (vmf_ret_t)VMF_ERR_OUT_OF_RANGE;                 \
            }

/*! Macro for argument check \n
    if argument > min AND argument < max then ok else error \n\n
    NOTE: In case of error 'return with error-code' is called!! \n
        \param[in]  _pre_msg_ -- additional text like function name from where called.
        \param[in]  _val_     -- argument to be checked.
        \param[in]  _min_     -- lower limit to check against.
        \param[in]  _min_     -- upper limit to check against. */
#define NW_VMF_ARG_CHECK_RANGE(_pre_msg_, _val_, _min_, _max_)          \
            if ((_val_ < _min_) || (_val_ > _max_))                     \
            {                                                           \
                NW_VMF_DEBUG_ERROR((_pre_msg_));                        \
                NW_VMF_DEBUG_ERROR((" --> OUT OF RANGE!\n"));           \
                return (vmf_ret_t)VMF_ERR_OUT_OF_RANGE;                 \
            }


#endif
