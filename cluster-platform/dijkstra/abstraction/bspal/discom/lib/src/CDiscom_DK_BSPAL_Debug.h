/*============================================================================
 **
 **  \file CDiscom_DK_BSPAL_Debug.h
 **
 **  \brief Interface to interact with the Discom of rcar-gen3
 **
 **  This file provides functional defines for a Discom module
 **
 **  Component Name: Discom
 **  Archive:
 **  Date: Feb 09 2022
 **  Author: SKOPPISE
 **
 ** Copyright 2019 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (“Materials”) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, estoppel or otherwise, any rights in these Materials.
 **
 **==========================================================================*/

#ifndef CDISCOM_DK_BSPAL_DEBUG_H_
#define CDISCOM_DK_BSPAL_DEBUG_H_

#include <sys/slog.h>
#include <sys/slogcodes.h>

#define LOG_FMT     "%s:%d "
#define LOG_ARGS    __func__, __LINE__
#define NEWLINE     " "

#define LOG_ERROR(msg, vars...) (void)slogf(_SLOGC_CHAR, _SLOG_ERROR,LOG_FMT msg NEWLINE, LOG_ARGS, ##vars)
#define LOG_WARNING(msg, vars...) (void)slogf(_SLOGC_CHAR, _SLOG_WARNING,LOG_FMT msg NEWLINE, LOG_ARGS, ##vars)
#define LOG_INFO(msg, vars...) (void)slogf(_SLOGC_CHAR, _SLOG_INFO,LOG_FMT msg NEWLINE, LOG_ARGS, ##vars)
#define LOG_DEBUG(msg, vars...) (void)slogf(_SLOGC_CHAR, _SLOG_DEBUG1,LOG_FMT msg NEWLINE, LOG_ARGS, ##vars)

#endif /* CDISCOM_DEBUG_H_ */
