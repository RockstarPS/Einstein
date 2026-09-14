///////////////////////////////////////////////////////////////////////////////
//
//                     CONFIDENTIAL VISTEON CORPORATION
//
// This is an unpublished work of authorship, which contains trade secrets,
// created in 2018. Visteon Corporation owns all rights to this work and
// intends to maintain it in confidence to preserve its trade secret status.
// Visteon Corporation reserves the right, under the copyright laws of the
// United States or those of any other country that may have jurisdiction,
// to protect this work as an unpublished work, in the event of an
// inadvertent or deliberate unauthorized publication. Visteon Corporation
// also reserves its rights under all copyright laws to protect this work as
// a published work, when appropriate. Those having access to this work may
// not copy it, use it, modify it or disclose the information contained in
// it without the written authorization of Visteon Corporation.
//
//  Filename    : rc_debug.h
//  Description : debug interfaces..
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file	rc_debug.h
///	\brief 		debug interfaces..
#ifndef rc_debug_h
#define rc_debug_h

#define GLCALL(call)  (call)
#define EGLCALL(call) (call)
#define RC_FPSTART(x_tag)
#define RC_FPBYTES(x_tag, x_bytes)
#define RC_FPSTARTM(x_tag, x_msg)
#define RC_FPBYTESM(x_tag, x_bytes)
#define RC_FPINIT(x)
#define RC_PROF_PRINT(x)
#define LOG_DISABLE_ALL()
#define LOG_DISABLE(x)
#define LOG_ENABLE(x)
#define SUPPRESS_LOG_REPEATS(x)
#define IS_LOGONCE()
#define RESET_GL_PROFILE()
#define RC_SET_THREAD_NAME(x)
#define ILOG(...)
#define LOG(...)
#define WLOG(...)
#define ELOG(p_msg)
#define RcDebugFilteredlogLine(x, y, z)
#define RcDebugGetTotalMemory()     (0U)
#define RcDebugGetCPUPer()          (-1.0F) 
#define RcDebugGetTotalVertices()   (0U)
#define RcDebugGetTotalTriangles()  (0U)
#define RcDebugGetTotalDrawCalls()  (0U)
#define RcDebugSetTotalVertices(x, y)
#define RcEnableGLCallProfile(x)
#define RcDebugListAvailableEGLConfigs(p_display, p_reqConfig, p_regConfigSize, p_colordepth,p_depth,p_msaa)
#define RcDebugPrintEGLConfig(p_dpy, p_numConfigs, p_config, p_reqConfig, p_regConfigSize)
#define RcDebugPrintGLInfo(p_dpy)
#define LOG_RENDERLIST(x)
#define CLEAR_RENDERLIST()

#endif