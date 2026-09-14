/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2025 Vector Informatik, GmbH.    *
 *                18 (02/04/18)                *
 ***********************************************/
/***********************************************
 * VectorCAST Unit Information
 *
 * Name: OsEvent
 *
 * Path: C:/Sprint/Autosar4_3UT/sys/mos/src/src/OsEvent.c
 *
 * Type: stub-by-function
 *
 * Unit Number: 9
 *
 ***********************************************/
#ifndef VCAST_DRIVER_ONLY
/* Include the file which contains function prototypes
for stub processing and value/expected user code */
#include "vcast_uc_prototypes.h"
#include "vcast_basics.h"
/* STUB_DEPENDENCY_USER_CODE */
/* STUB_DEPENDENCY_USER_CODE_END */
#else
#include "vcast_env_defines.h"
#define __VCAST_BASICS_H__
#endif /* VCAST_DRIVER_ONLY */
#ifndef VCAST_DRIVER_ONLY
#ifndef VCAST_DONT_RENAME_EXIT
#ifdef __cplusplus
extern "C" {
#endif
void exit (int status);
#ifdef __cplusplus
}
#endif
/* used to capture the exit call */
#define exit VCAST_exit
#endif /* VCAST_DONT_RENAME_EXIT */
#endif /* VCAST_DRIVER_ONLY */
#ifndef VCAST_DRIVER_ONLY
#define VCAST_HEADER_EXPANSION
#ifdef VCAST_COVERAGE
#include "OsEvent_inst_prefix.c"
#else
#include "OsEvent_vcast_prefix.c"
#endif
#ifdef VCAST_COVERAGE
/* If coverage is enabled, include the instrumented UUT */
#include "OsEvent_inst.c"
#else
/* If coverage is not enabled, include the original UUT */
#include "OsEvent_vcast.c"
#endif
#ifdef VCAST_COVERAGE
#include "OsEvent_inst_appendix.c"
#else
#include "OsEvent_vcast_appendix.c"
#endif
#endif /* VCAST_DRIVER_ONLY */
#include "OsEvent_driver_prefix.c"
#ifdef VCAST_HEADER_EXPANSION
#ifdef VCAST_COVERAGE
#include "OsEvent_exp_inst_driver.c"
#else
#include "OsEvent_expanded_driver.c"
#endif /*VCAST_COVERAGE*/
#else
#include "S0000009.h"
#include "vcast_undef_9.h"
/* Include the file which contains function prototypes
for stub processing and value/expected user code */
#include "vcast_uc_prototypes.h"
#include "vcast_stubs_9.c"
/* begin declarations of inlined friends */
/* end declarations of inlined friends */
void VCAST_DRIVER_9( int VC_SUBPROGRAM, char *VC_EVENT_FLAGS, char *VC_SLOT_DESCR ) {
#ifdef VCAST_SBF_UNITS_AVAILABLE
  vCAST_MODIFY_SBF_TABLE(9, VC_SUBPROGRAM, vCAST_false);
#endif
  switch( VC_SUBPROGRAM ) {
    case 0:
      vCAST_SET_HISTORY_FLAGS ( 9, 0, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      break;
    case 1: {
      /* StatusType osSetEvent(TaskType TaskIndex, EventMaskType EventMask) */
      vCAST_SET_HISTORY_FLAGS ( 9, 1, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      R_9_1 = 
      ( osSetEvent(
        ( P_9_1_1 ),
        ( P_9_1_2 ) ) );
      break; }
    case 2: {
      /* StatusType osSysSetEvent(TaskType TaskIndex, EventMaskType EventMask) */
      vCAST_SET_HISTORY_FLAGS ( 9, 2, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      R_9_2 = 
      ( osSysSetEvent(
        ( P_9_2_1 ),
        ( P_9_2_2 ) ) );
      break; }
    case 3: {
      /* StatusType osClearEvent(EventMaskType EventMask) */
      vCAST_SET_HISTORY_FLAGS ( 9, 3, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      R_9_3 = 
      ( osClearEvent(
        ( P_9_3_1 ) ) );
      break; }
    case 4: {
      /* StatusType osGetEvent(TaskType TaskIndex, EventMaskRefType Event) */
      vCAST_SET_HISTORY_FLAGS ( 9, 4, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      R_9_4 = 
      ( osGetEvent(
        ( P_9_4_1 ),
        ( P_9_4_2 ) ) );
      break; }
    case 5: {
      /* StatusType osWaitEvent(EventMaskType EventMask) */
      vCAST_SET_HISTORY_FLAGS ( 9, 5, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      R_9_5 = 
      ( osWaitEvent(
        ( P_9_5_1 ) ) );
      break; }
    case 6: {
      /* StatusType osSysWaitEvent(EventMaskType EventMask) */
      vCAST_SET_HISTORY_FLAGS ( 9, 6, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      R_9_6 = 
      ( osSysWaitEvent(
        ( P_9_6_1 ) ) );
      break; }
    default:
      vectorcast_print_string("ERROR: Internal Tool Error\n");
      break;
  } /* switch */
}

void VCAST_SBF_9( int VC_SUBPROGRAM ) {
  switch( VC_SUBPROGRAM ) {
    case 1: {
      SBF_9_1 = 0;
      break; }
    case 2: {
      SBF_9_2 = 0;
      break; }
    case 3: {
      SBF_9_3 = 0;
      break; }
    case 4: {
      SBF_9_4 = 0;
      break; }
    case 5: {
      SBF_9_5 = 0;
      break; }
    case 6: {
      SBF_9_6 = 0;
      break; }
    default:
      break;
  } /* switch */
}
#include "vcast_ti_decls_9.h"
void VCAST_RUN_DATA_IF_9( int VCAST_SUB_INDEX, int VCAST_PARAM_INDEX ) {
  switch ( VCAST_SUB_INDEX ) {
    case 0: /* for global objects */
      switch( VCAST_PARAM_INDEX ) {
        case 1: /* for global object TcbTaskRefConfig */
          VCAST_TI_9_1 ( TcbTaskRefConfig);
          break;
        case 2: /* for global object OsCtrlParam */
          VCAST_TI_9_4 ( &(OsCtrlParam));
          break;
        default:
          vCAST_TOOL_ERROR = vCAST_true;
          break;
      } /* switch( VCAST_PARAM_INDEX ) */
      break; /* case 0 (global objects) */
    case 8: /* function osSchedInsertTask */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( &(P_10_2_1));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function osSchedInsertTask */
    case 11: /* function osCheckInterruptsEnabled */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( &(R_10_5));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function osCheckInterruptsEnabled */
    case 15: /* function OsErr_osApplicationErrorHook */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_8 ( &(P_10_9_1));
          break;
        case 2:
          VCAST_TI_9_2 ( &(P_10_9_2));
          break;
        case 3:
          VCAST_TI_9_6 ( &(P_10_9_3));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function OsErr_osApplicationErrorHook */
    case 17: /* function Os_GetContext */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_7 ( &(R_10_11));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function Os_GetContext */
    case 18: /* function osSuspendInterruptsAsm */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_8 ( &(R_10_12));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function osSuspendInterruptsAsm */
    case 1: /* function osSetEvent */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( &(P_9_1_1));
          break;
        case 2:
          VCAST_TI_9_3 ( &(P_9_1_2));
          break;
        case 3:
          VCAST_TI_9_6 ( &(R_9_1));
          break;
        case 4:
          VCAST_TI_SBF_OBJECT( &SBF_9_1 );
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function osSetEvent */
    case 2: /* function osSysSetEvent */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( &(P_9_2_1));
          break;
        case 2:
          VCAST_TI_9_3 ( &(P_9_2_2));
          break;
        case 3:
          VCAST_TI_9_6 ( &(R_9_2));
          break;
        case 4:
          VCAST_TI_SBF_OBJECT( &SBF_9_2 );
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function osSysSetEvent */
    case 3: /* function osClearEvent */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_3 ( &(P_9_3_1));
          break;
        case 2:
          VCAST_TI_9_6 ( &(R_9_3));
          break;
        case 3:
          VCAST_TI_SBF_OBJECT( &SBF_9_3 );
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function osClearEvent */
    case 4: /* function osGetEvent */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( &(P_9_4_1));
          break;
        case 2:
          VCAST_TI_9_5 ( &(P_9_4_2));
          break;
        case 3:
          VCAST_TI_9_6 ( &(R_9_4));
          break;
        case 4:
          VCAST_TI_SBF_OBJECT( &SBF_9_4 );
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function osGetEvent */
    case 5: /* function osWaitEvent */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_3 ( &(P_9_5_1));
          break;
        case 2:
          VCAST_TI_9_6 ( &(R_9_5));
          break;
        case 3:
          VCAST_TI_SBF_OBJECT( &SBF_9_5 );
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function osWaitEvent */
    case 6: /* function osSysWaitEvent */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_3 ( &(P_9_6_1));
          break;
        case 2:
          VCAST_TI_9_6 ( &(R_9_6));
          break;
        case 3:
          VCAST_TI_SBF_OBJECT( &SBF_9_6 );
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function osSysWaitEvent */
    default:
      vCAST_TOOL_ERROR = vCAST_true;
      break;
  } /* switch ( VCAST_SUB_INDEX ) */
}


/* An array */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_1 ( OsTaskConfigRefType vcast_param[21U] ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_1 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_1 ( OsTaskConfigRefType vcast_param[21U] ) 
{
  {
    int VCAST_TI_9_1_array_index = 0;
    int VCAST_TI_9_1_index = 0;
    int VCAST_TI_9_1_first, VCAST_TI_9_1_last;
    int VCAST_TI_9_1_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_1_local_field = 0;
    int VCAST_TI_9_1_value_printed = 0;


    vcast_get_range_value (&VCAST_TI_9_1_first, &VCAST_TI_9_1_last, &VCAST_TI_9_1_more_data);
    VCAST_TI_9_1_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_1_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,21U);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_1_upper = 21U;
      for (VCAST_TI_9_1_array_index=0; VCAST_TI_9_1_array_index< VCAST_TI_9_1_upper; VCAST_TI_9_1_array_index++){
        if ( (VCAST_TI_9_1_index >= VCAST_TI_9_1_first) && ( VCAST_TI_9_1_index <= VCAST_TI_9_1_last)){
          VCAST_TI_9_34 ( &(vcast_param[VCAST_TI_9_1_index]));
          VCAST_TI_9_1_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_1_local_field;
        } /* if */
        if (VCAST_TI_9_1_index >= VCAST_TI_9_1_last)
          break;
        VCAST_TI_9_1_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_1_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_1 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_4 ( OsCtrlParamType *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_4 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_4 ( OsCtrlParamType *vcast_param ) 
{
#if (defined(VCAST_NO_TYPE_SUPPORT))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->CoreParam */
      case 1: { 
        VCAST_TI_9_38 ( &(vcast_param->CoreParam));
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->AppParam */
      case 2: { 
        VCAST_TI_9_36 ( &(vcast_param->AppParam));
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->ActiveISRId */
      case 3: { 
        VCAST_TI_9_8 ( &(vcast_param->ActiveISRId));
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->pLastObjRef */
      case 4: { 
        VCAST_TI_9_24 ( &(vcast_param->pLastObjRef));
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->pActiveObjRef */
      case 5: { 
        VCAST_TI_9_24 ( &(vcast_param->pActiveObjRef));
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->ActiveTaskIndex */
      case 6: { 
        VCAST_TI_9_6 ( &(vcast_param->ActiveTaskIndex));
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->RequestedTaskIndex */
      case 7: { 
        VCAST_TI_9_6 ( &(vcast_param->RequestedTaskIndex));
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->ActiveTaskPriority */
      case 8: { 
        VCAST_TI_9_6 ( &(vcast_param->ActiveTaskPriority));
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->RequestedTaskPriority */
      case 9: { 
        VCAST_TI_9_6 ( &(vcast_param->RequestedTaskPriority));
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->ResOccVirtualPrioBits */
      case 10: { 
        VCAST_TI_9_6 ( &(vcast_param->ResOccVirtualPrioBits));
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->TaskPriorityBits */
      case 11: { 
        VCAST_TI_9_8 ( &(vcast_param->TaskPriorityBits));
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->RequestScheduler */
      case 12: { 
        VCAST_TI_9_6 ( &(vcast_param->RequestScheduler));
        break; /* end case 12*/
      } /* end case */
      /* Setting member variable vcast_param->LockDispatcher */
      case 13: { 
        VCAST_TI_9_6 ( &(vcast_param->LockDispatcher));
        break; /* end case 13*/
      } /* end case */
      /* Setting member variable vcast_param->IntSaveDisableRequestCounter */
      case 14: { 
        VCAST_TI_9_6 ( &(vcast_param->IntSaveDisableRequestCounter));
        break; /* end case 14*/
      } /* end case */
      /* Setting member variable vcast_param->IntSaveStatus */
      case 15: { 
        VCAST_TI_9_8 ( &(vcast_param->IntSaveStatus));
        break; /* end case 15*/
      } /* end case */
      /* Setting member variable vcast_param->IntSaveGlobal */
      case 16: { 
        VCAST_TI_9_8 ( &(vcast_param->IntSaveGlobal));
        break; /* end case 16*/
      } /* end case */
      /* Setting member variable vcast_param->CurrentContext */
      case 17: { 
        VCAST_TI_9_7 ( &(vcast_param->CurrentContext));
        break; /* end case 17*/
      } /* end case */
      /* Setting member variable vcast_param->OsIntSaveDisableRequestCounter */
      case 18: { 
        VCAST_TI_9_6 ( &(vcast_param->OsIntSaveDisableRequestCounter));
        break; /* end case 18*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/

} /* end VCAST_TI_9_4 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An integer */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_6 ( unsigned char *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_6 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_6 ( unsigned char *vcast_param ) 
{
  switch (vCAST_COMMAND) {
    case vCAST_PRINT :
      if ( vcast_param == 0)
        vectorcast_fprint_string (vCAST_OUTPUT_FILE,"null\n");
      else {
        vectorcast_fprint_integer(vCAST_OUTPUT_FILE, *vcast_param);
        vectorcast_fprint_string(vCAST_OUTPUT_FILE, "\n");
      }
      break;
    case vCAST_KEEP_VAL:
      break; /* KEEP doesn't do anything */
  case vCAST_SET_VAL :
    *vcast_param = ( unsigned char  ) vCAST_VALUE_INT;
    break;
  case vCAST_FIRST_VAL :
    *vcast_param = UCHAR_MIN;
    break;
  case vCAST_MID_VAL :
    *vcast_param = (UCHAR_MIN / 2) + (UCHAR_MAX / 2);
    break;
  case vCAST_LAST_VAL :
    *vcast_param = UCHAR_MAX;
    break;
  case vCAST_MIN_MINUS_1_VAL :
    *vcast_param = UCHAR_MIN;
    *vcast_param = *vcast_param - 1;
    break;
  case vCAST_MAX_PLUS_1_VAL :
    *vcast_param = UCHAR_MAX;
    *vcast_param = *vcast_param + 1;
    break;
  case vCAST_ZERO_VAL :
    *vcast_param = 0;
    break;
  default:
    break;
} /* end switch */
} /* end VCAST_TI_9_6 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An integer */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_8 ( unsigned long *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_8 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_8 ( unsigned long *vcast_param ) 
{
  switch (vCAST_COMMAND) {
    case vCAST_PRINT :
      if ( vcast_param == 0)
        vectorcast_fprint_string (vCAST_OUTPUT_FILE,"null\n");
      else {
        vectorcast_fprint_unsigned_long(vCAST_OUTPUT_FILE, *vcast_param);
        vectorcast_fprint_string(vCAST_OUTPUT_FILE, "\n");
      }
      break;
    case vCAST_KEEP_VAL:
      break; /* KEEP doesn't do anything */
  case vCAST_SET_VAL :
    *vcast_param = ( unsigned long  ) vCAST_VALUE_UNSIGNED;
    break;
  case vCAST_FIRST_VAL :
    *vcast_param = ULONG_MIN;
    break;
  case vCAST_MID_VAL :
    *vcast_param = (ULONG_MIN / 2) + (ULONG_MAX / 2);
    break;
  case vCAST_LAST_VAL :
    *vcast_param = ULONG_MAX;
    break;
  case vCAST_MIN_MINUS_1_VAL :
    *vcast_param = ULONG_MIN;
    *vcast_param = *vcast_param - 1;
    break;
  case vCAST_MAX_PLUS_1_VAL :
    *vcast_param = ULONG_MAX;
    *vcast_param = *vcast_param + 1;
    break;
  case vCAST_ZERO_VAL :
    *vcast_param = 0;
    break;
  default:
    break;
} /* end switch */
} /* end VCAST_TI_9_8 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A pointer */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_2 ( unsigned char **vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_2 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_2 ( unsigned char **vcast_param ) 
{
  {
    int VCAST_TI_9_2_index;
    if (((*vcast_param) == 0) && (vCAST_COMMAND != vCAST_ALLOCATE)){
      if ( vCAST_COMMAND == vCAST_PRINT )
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"null\n");
    } else {
      if ( (vCAST_COMMAND_IS_MIN_MAX == vCAST_true) &&( VCAST_FIND_INDEX() < 0 ) ) {
        switch ( vCAST_COMMAND ) {
          case vCAST_PRINT     :
            vectorcast_fprint_string(vCAST_OUTPUT_FILE,"0\n");
          case vCAST_FIRST_VAL :
          case vCAST_LAST_VAL  :
          case vCAST_POS_INF_VAL  :
          case vCAST_NEG_INF_VAL  :
          case vCAST_NAN_VAL  :
            break;
          default :
            vCAST_TOOL_ERROR = vCAST_true;
        }
      } else {
        if (vCAST_COMMAND == vCAST_ALLOCATE && vcast_proc_handles_command(1)) {
          int VCAST_TI_9_2_array_size = (int) vCAST_VALUE;
          if (VCAST_FIND_INDEX() == -1) {
            void **VCAST_TI_9_2_memory_ptr = (void**)vcast_param;
            *VCAST_TI_9_2_memory_ptr = (void*)VCAST_malloc(VCAST_TI_9_2_array_size*(sizeof(unsigned char )));
            VCAST_memset((void*)*vcast_param, 0x0, VCAST_TI_9_2_array_size*(sizeof(unsigned char )));
#ifndef VCAST_NO_MALLOC
            VCAST_Add_Allocated_Data(*VCAST_TI_9_2_memory_ptr);
#endif
          }
        } else if (vCAST_VALUE_NUL == vCAST_true && vcast_proc_handles_command(1)) {
          if (VCAST_FIND_INDEX() == -1)
            *vcast_param = 0;
        } else {
          if (VCAST_FIND_INDEX() == -1 )
            VCAST_TI_STRING ( (char**)vcast_param, sizeof ( vcast_param ), 0,-1);
          else {
            VCAST_TI_9_2_index = vcast_get_param();
            VCAST_TI_9_6 ( &((*vcast_param)[VCAST_TI_9_2_index]));
          }
        }
      }
    }
  }
} /* end VCAST_TI_9_2 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An integer */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_7 ( unsigned short *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_7 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_7 ( unsigned short *vcast_param ) 
{
  switch (vCAST_COMMAND) {
    case vCAST_PRINT :
      if ( vcast_param == 0)
        vectorcast_fprint_string (vCAST_OUTPUT_FILE,"null\n");
      else {
        vectorcast_fprint_unsigned_short(vCAST_OUTPUT_FILE, *vcast_param);
        vectorcast_fprint_string(vCAST_OUTPUT_FILE, "\n");
      }
      break;
    case vCAST_KEEP_VAL:
      break; /* KEEP doesn't do anything */
  case vCAST_SET_VAL :
    *vcast_param = ( unsigned short  ) vCAST_VALUE_INT;
    break;
  case vCAST_FIRST_VAL :
    *vcast_param = USHRT_MIN;
    break;
  case vCAST_MID_VAL :
    *vcast_param = (USHRT_MIN / 2) + (USHRT_MAX / 2);
    break;
  case vCAST_LAST_VAL :
    *vcast_param = USHRT_MAX;
    break;
  case vCAST_MIN_MINUS_1_VAL :
    *vcast_param = USHRT_MIN;
    *vcast_param = *vcast_param - 1;
    break;
  case vCAST_MAX_PLUS_1_VAL :
    *vcast_param = USHRT_MAX;
    *vcast_param = *vcast_param + 1;
    break;
  case vCAST_ZERO_VAL :
    *vcast_param = 0;
    break;
  default:
    break;
} /* end switch */
} /* end VCAST_TI_9_7 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An integer */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_3 ( unsigned long long *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_3 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_3 ( unsigned long long *vcast_param ) 
{
  switch (vCAST_COMMAND) {
    case vCAST_PRINT :
      if ( vcast_param == 0)
        vectorcast_fprint_string (vCAST_OUTPUT_FILE,"null\n");
      else {
        vectorcast_fprint_unsigned_long_long(vCAST_OUTPUT_FILE, *vcast_param);
        vectorcast_fprint_string(vCAST_OUTPUT_FILE, "\n");
      }
      break;
    case vCAST_KEEP_VAL:
      break; /* KEEP doesn't do anything */
  case vCAST_SET_VAL :
    *vcast_param = ( unsigned long long  ) vCAST_VALUE_UNSIGNED;
    break;
  case vCAST_FIRST_VAL :
    *vcast_param = 0;
    break;
  case vCAST_MID_VAL :
    *vcast_param = (ULLONG_MAX / 2);
    break;
  case vCAST_LAST_VAL :
    *vcast_param = ULLONG_MAX;
    break;
  case vCAST_MIN_MINUS_1_VAL :
    *vcast_param = 0;
    *vcast_param = *vcast_param - 1;
    break;
  case vCAST_MAX_PLUS_1_VAL :
    *vcast_param = ULLONG_MAX;
    *vcast_param = *vcast_param + 1;
    break;
  case vCAST_ZERO_VAL :
    *vcast_param = 0;
    break;
  default:
    break;
} /* end switch */
} /* end VCAST_TI_9_3 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A pointer */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_5 ( unsigned long long **vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_5 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_5 ( unsigned long long **vcast_param ) 
{
  {
    int VCAST_TI_9_5_index;
    if (((*vcast_param) == 0) && (vCAST_COMMAND != vCAST_ALLOCATE)){
      if ( vCAST_COMMAND == vCAST_PRINT )
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"null\n");
    } else {
      if ( (vCAST_COMMAND_IS_MIN_MAX == vCAST_true) &&( VCAST_FIND_INDEX() < 0 ) ) {
        switch ( vCAST_COMMAND ) {
          case vCAST_PRINT     :
            vectorcast_fprint_string(vCAST_OUTPUT_FILE,"0\n");
          case vCAST_FIRST_VAL :
          case vCAST_LAST_VAL  :
          case vCAST_POS_INF_VAL  :
          case vCAST_NEG_INF_VAL  :
          case vCAST_NAN_VAL  :
            break;
          default :
            vCAST_TOOL_ERROR = vCAST_true;
        }
      } else {
        if (vCAST_COMMAND == vCAST_ALLOCATE && vcast_proc_handles_command(1)) {
          int VCAST_TI_9_5_array_size = (int) vCAST_VALUE;
          if (VCAST_FIND_INDEX() == -1) {
            void **VCAST_TI_9_5_memory_ptr = (void**)vcast_param;
            *VCAST_TI_9_5_memory_ptr = (void*)VCAST_malloc(VCAST_TI_9_5_array_size*(sizeof(unsigned long long )));
            VCAST_memset((void*)*vcast_param, 0x0, VCAST_TI_9_5_array_size*(sizeof(unsigned long long )));
#ifndef VCAST_NO_MALLOC
            VCAST_Add_Allocated_Data(*VCAST_TI_9_5_memory_ptr);
#endif
          }
        } else if (vCAST_VALUE_NUL == vCAST_true && vcast_proc_handles_command(1)) {
          if (VCAST_FIND_INDEX() == -1)
            *vcast_param = 0;
        } else {
          VCAST_TI_9_5_index = vcast_get_param();
          VCAST_TI_9_3 ( &((*vcast_param)[VCAST_TI_9_5_index]));
        }
      }
    }
  }
} /* end VCAST_TI_9_5 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A pointer */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_34 ( OsTaskConfigType **vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_34 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_34 ( OsTaskConfigType **vcast_param ) 
{
  {
    int VCAST_TI_9_34_index;
    if (((*vcast_param) == 0) && (vCAST_COMMAND != vCAST_ALLOCATE)){
      if ( vCAST_COMMAND == vCAST_PRINT )
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"null\n");
    } else {
      if ( (vCAST_COMMAND_IS_MIN_MAX == vCAST_true) &&( VCAST_FIND_INDEX() < 0 ) ) {
        switch ( vCAST_COMMAND ) {
          case vCAST_PRINT     :
            vectorcast_fprint_string(vCAST_OUTPUT_FILE,"0\n");
          case vCAST_FIRST_VAL :
          case vCAST_LAST_VAL  :
          case vCAST_POS_INF_VAL  :
          case vCAST_NEG_INF_VAL  :
          case vCAST_NAN_VAL  :
            break;
          default :
            vCAST_TOOL_ERROR = vCAST_true;
        }
      } else {
        if (vCAST_COMMAND == vCAST_ALLOCATE && vcast_proc_handles_command(1)) {
          int VCAST_TI_9_34_array_size = (int) vCAST_VALUE;
          if (VCAST_FIND_INDEX() == -1) {
            void **VCAST_TI_9_34_memory_ptr = (void**)vcast_param;
            *VCAST_TI_9_34_memory_ptr = (void*)VCAST_malloc(VCAST_TI_9_34_array_size*(sizeof(OsTaskConfigType )));
            VCAST_memset((void*)*vcast_param, 0x0, VCAST_TI_9_34_array_size*(sizeof(OsTaskConfigType )));
#ifndef VCAST_NO_MALLOC
            VCAST_Add_Allocated_Data(*VCAST_TI_9_34_memory_ptr);
#endif
          }
        } else if (vCAST_VALUE_NUL == vCAST_true && vcast_proc_handles_command(1)) {
          if (VCAST_FIND_INDEX() == -1)
            *vcast_param = 0;
        } else {
          VCAST_TI_9_34_index = vcast_get_param();
          VCAST_TI_9_33 ( &((*vcast_param)[VCAST_TI_9_34_index]));
        }
      }
    }
  }
} /* end VCAST_TI_9_34 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_38 ( OsCoreParamType *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_38 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_38 ( OsCoreParamType *vcast_param ) 
{
#if (defined(VCAST_NO_TYPE_SUPPORT))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->State */
      case 1: { 
        VCAST_TI_9_6 ( &(vcast_param->State));
        break; /* end case 1*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/

} /* end VCAST_TI_9_38 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_36 ( OsAppParamType *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_36 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_36 ( OsAppParamType *vcast_param ) 
{
#if (defined(VCAST_NO_TYPE_SUPPORT))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->State */
      case 1: { 
        VCAST_TI_9_6 ( &(vcast_param->State));
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->AccessId */
      case 2: { 
        VCAST_TI_9_8 ( &(vcast_param->AccessId));
        break; /* end case 2*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/

} /* end VCAST_TI_9_36 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A pointer */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_24 ( OsObjConfigType **vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_24 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_24 ( OsObjConfigType **vcast_param ) 
{
  {
    int VCAST_TI_9_24_index;
    if (((*vcast_param) == 0) && (vCAST_COMMAND != vCAST_ALLOCATE)){
      if ( vCAST_COMMAND == vCAST_PRINT )
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"null\n");
    } else {
      if ( (vCAST_COMMAND_IS_MIN_MAX == vCAST_true) &&( VCAST_FIND_INDEX() < 0 ) ) {
        switch ( vCAST_COMMAND ) {
          case vCAST_PRINT     :
            vectorcast_fprint_string(vCAST_OUTPUT_FILE,"0\n");
          case vCAST_FIRST_VAL :
          case vCAST_LAST_VAL  :
          case vCAST_POS_INF_VAL  :
          case vCAST_NEG_INF_VAL  :
          case vCAST_NAN_VAL  :
            break;
          default :
            vCAST_TOOL_ERROR = vCAST_true;
        }
      } else {
        if (vCAST_COMMAND == vCAST_ALLOCATE && vcast_proc_handles_command(1)) {
          int VCAST_TI_9_24_array_size = (int) vCAST_VALUE;
          if (VCAST_FIND_INDEX() == -1) {
            void **VCAST_TI_9_24_memory_ptr = (void**)vcast_param;
            *VCAST_TI_9_24_memory_ptr = (void*)VCAST_malloc(VCAST_TI_9_24_array_size*(sizeof(OsObjConfigType )));
            VCAST_memset((void*)*vcast_param, 0x0, VCAST_TI_9_24_array_size*(sizeof(OsObjConfigType )));
#ifndef VCAST_NO_MALLOC
            VCAST_Add_Allocated_Data(*VCAST_TI_9_24_memory_ptr);
#endif
          }
        } else if (vCAST_VALUE_NUL == vCAST_true && vcast_proc_handles_command(1)) {
          if (VCAST_FIND_INDEX() == -1)
            *vcast_param = 0;
        } else {
          VCAST_TI_9_24_index = vcast_get_param();
          VCAST_TI_9_25 ( &((*vcast_param)[VCAST_TI_9_24_index]));
        }
      }
    }
  }
} /* end VCAST_TI_9_24 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_33 ( OsTaskConfigType *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_33 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_33 ( OsTaskConfigType *vcast_param ) 
{
#if (defined(VCAST_NO_TYPE_SUPPORT))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->TaskStartAddress */
      case 1: { 
        VCAST_TI_9_11 ( &(vcast_param->TaskStartAddress));
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->TaskStackStartAddress */
      case 2: { 
        VCAST_TI_9_12 ( &(vcast_param->TaskStackStartAddress));
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->TaskStackSize */
      case 3: { 
        VCAST_TI_9_8 ( &(vcast_param->TaskStackSize));
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->TaskPriority */
      case 4: { 
        VCAST_TI_9_6 ( &(vcast_param->TaskPriority));
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->TaskMaxActivationCount */
      case 5: { 
        VCAST_TI_9_6 ( &(vcast_param->TaskMaxActivationCount));
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->TaskCategory */
      case 6: { 
        VCAST_TI_9_6 ( &(vcast_param->TaskCategory));
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->pObjRef */
      case 7: { 
        VCAST_TI_9_24 ( &(vcast_param->pObjRef));
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->pAppRef */
      case 8: { 
        VCAST_TI_9_21 ( &(vcast_param->pAppRef));
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->TasksType */
      case 9: { 
        VCAST_TI_9_6 ( &(vcast_param->TasksType));
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->TasksID */
      case 10: { 
        VCAST_TI_9_6 ( &(vcast_param->TasksID));
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->TaskParamRef */
      case 11: { 
        VCAST_TI_9_31 ( &(vcast_param->TaskParamRef));
        break; /* end case 11*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/

} /* end VCAST_TI_9_33 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_25 ( OsObjConfigType *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_25 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_25 ( OsObjConfigType *vcast_param ) 
{
#if (defined(VCAST_NO_TYPE_SUPPORT))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->ObjId */
      case 1: { 
        VCAST_TI_9_8 ( &(vcast_param->ObjId));
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->CoreId */
      case 2: { 
        VCAST_TI_9_7 ( &(vcast_param->CoreId));
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->ObjType */
      case 3: { 
        VCAST_TI_9_6 ( &(vcast_param->ObjType));
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->AccessId */
      case 4: { 
        VCAST_TI_9_8 ( &(vcast_param->AccessId));
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->pAppRef */
      case 5: { 
        VCAST_TI_9_19 ( &(vcast_param->pAppRef));
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->StackStartAddress */
      case 6: { 
        VCAST_TI_9_12 ( &(vcast_param->StackStartAddress));
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->StackSize */
      case 7: { 
        VCAST_TI_9_8 ( &(vcast_param->StackSize));
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->StackRegAttribute */
      case 8: { 
        VCAST_TI_9_8 ( &(vcast_param->StackRegAttribute));
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->StackRegnSizeAndEnable */
      case 9: { 
        VCAST_TI_9_8 ( &(vcast_param->StackRegnSizeAndEnable));
        break; /* end case 9*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/

} /* end VCAST_TI_9_25 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A pointer */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_11 ( void (**vcast_param)(void) ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_11 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_11 ( void (**vcast_param)(void) ) 
{
  void (*vcast_local_ptr)(void);
  switch ( vCAST_COMMAND ) {
    case vCAST_PRINT:
      if ( !*vcast_param )
        vectorcast_fprint_string(vCAST_OUTPUT_FILE, "<<null>>\n");
      else if ( vcast_local_ptr = OsStartDispatchMetric, *vcast_param == vcast_local_ptr ) {
        vectorcast_fprint_integer (vCAST_OUTPUT_FILE, 0);
        vectorcast_fprint_string(vCAST_OUTPUT_FILE, "\n");
      }
      else if ( vcast_local_ptr = osSchedRemoveTask, *vcast_param == vcast_local_ptr ) {
        vectorcast_fprint_integer (vCAST_OUTPUT_FILE, 1);
        vectorcast_fprint_string(vCAST_OUTPUT_FILE, "\n");
      }
      else if ( vcast_local_ptr = osEnableAllInterrupts, *vcast_param == vcast_local_ptr ) {
        vectorcast_fprint_integer (vCAST_OUTPUT_FILE, 2);
        vectorcast_fprint_string(vCAST_OUTPUT_FILE, "\n");
      }
      else if ( vcast_local_ptr = OsPrvEnterCriticalSection, *vcast_param == vcast_local_ptr ) {
        vectorcast_fprint_integer (vCAST_OUTPUT_FILE, 3);
        vectorcast_fprint_string(vCAST_OUTPUT_FILE, "\n");
      }
      else if ( vcast_local_ptr = OsPrvExitCriticalSection, *vcast_param == vcast_local_ptr ) {
        vectorcast_fprint_integer (vCAST_OUTPUT_FILE, 4);
        vectorcast_fprint_string(vCAST_OUTPUT_FILE, "\n");
      }
      else if ( vcast_local_ptr = osDispatchAsm, *vcast_param == vcast_local_ptr ) {
        vectorcast_fprint_integer (vCAST_OUTPUT_FILE, 5);
        vectorcast_fprint_string(vCAST_OUTPUT_FILE, "\n");
      }
      else if ( vcast_local_ptr = osTaskStopHook, *vcast_param == vcast_local_ptr ) {
        vectorcast_fprint_integer (vCAST_OUTPUT_FILE, 6);
        vectorcast_fprint_string(vCAST_OUTPUT_FILE, "\n");
      }
      else
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<unknown>>\n");
      break;
    case vCAST_SET_VAL:
      if (vCAST_VALUE_NUL == vCAST_true && vcast_proc_handles_command(1)) {
        if (VCAST_FIND_INDEX() == -1)
          *vcast_param = 0;
        return;
      }
      switch ( (int) vCAST_VALUE ) {
        case 0:
          vcast_local_ptr = OsStartDispatchMetric;
          *vcast_param = vcast_local_ptr;
          break;
        case 1:
          vcast_local_ptr = osSchedRemoveTask;
          *vcast_param = vcast_local_ptr;
          break;
        case 2:
          vcast_local_ptr = osEnableAllInterrupts;
          *vcast_param = vcast_local_ptr;
          break;
        case 3:
          vcast_local_ptr = OsPrvEnterCriticalSection;
          *vcast_param = vcast_local_ptr;
          break;
        case 4:
          vcast_local_ptr = OsPrvExitCriticalSection;
          *vcast_param = vcast_local_ptr;
          break;
        case 5:
          vcast_local_ptr = osDispatchAsm;
          *vcast_param = vcast_local_ptr;
          break;
        case 6:
          vcast_local_ptr = osTaskStopHook;
          *vcast_param = vcast_local_ptr;
          break;
      }
      break;
  }
} /* end VCAST_TI_9_11 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A pointer */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_12 ( unsigned long **vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_12 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_12 ( unsigned long **vcast_param ) 
{
  {
    int VCAST_TI_9_12_index;
    if (((*vcast_param) == 0) && (vCAST_COMMAND != vCAST_ALLOCATE)){
      if ( vCAST_COMMAND == vCAST_PRINT )
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"null\n");
    } else {
      if ( (vCAST_COMMAND_IS_MIN_MAX == vCAST_true) &&( VCAST_FIND_INDEX() < 0 ) ) {
        switch ( vCAST_COMMAND ) {
          case vCAST_PRINT     :
            vectorcast_fprint_string(vCAST_OUTPUT_FILE,"0\n");
          case vCAST_FIRST_VAL :
          case vCAST_LAST_VAL  :
          case vCAST_POS_INF_VAL  :
          case vCAST_NEG_INF_VAL  :
          case vCAST_NAN_VAL  :
            break;
          default :
            vCAST_TOOL_ERROR = vCAST_true;
        }
      } else {
        if (vCAST_COMMAND == vCAST_ALLOCATE && vcast_proc_handles_command(1)) {
          int VCAST_TI_9_12_array_size = (int) vCAST_VALUE;
          if (VCAST_FIND_INDEX() == -1) {
            void **VCAST_TI_9_12_memory_ptr = (void**)vcast_param;
            *VCAST_TI_9_12_memory_ptr = (void*)VCAST_malloc(VCAST_TI_9_12_array_size*(sizeof(unsigned long )));
            VCAST_memset((void*)*vcast_param, 0x0, VCAST_TI_9_12_array_size*(sizeof(unsigned long )));
#ifndef VCAST_NO_MALLOC
            VCAST_Add_Allocated_Data(*VCAST_TI_9_12_memory_ptr);
#endif
          }
        } else if (vCAST_VALUE_NUL == vCAST_true && vcast_proc_handles_command(1)) {
          if (VCAST_FIND_INDEX() == -1)
            *vcast_param = 0;
        } else {
          VCAST_TI_9_12_index = vcast_get_param();
          VCAST_TI_9_8 ( &((*vcast_param)[VCAST_TI_9_12_index]));
        }
      }
    }
  }
} /* end VCAST_TI_9_12 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A pointer */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_21 ( struct OsAppConfigType_T **vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_21 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_21 ( struct OsAppConfigType_T **vcast_param ) 
{
  {
    int VCAST_TI_9_21_index;
    if (((*vcast_param) == 0) && (vCAST_COMMAND != vCAST_ALLOCATE)){
      if ( vCAST_COMMAND == vCAST_PRINT )
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"null\n");
    } else {
      if ( (vCAST_COMMAND_IS_MIN_MAX == vCAST_true) &&( VCAST_FIND_INDEX() < 0 ) ) {
        switch ( vCAST_COMMAND ) {
          case vCAST_PRINT     :
            vectorcast_fprint_string(vCAST_OUTPUT_FILE,"0\n");
          case vCAST_FIRST_VAL :
          case vCAST_LAST_VAL  :
          case vCAST_POS_INF_VAL  :
          case vCAST_NEG_INF_VAL  :
          case vCAST_NAN_VAL  :
            break;
          default :
            vCAST_TOOL_ERROR = vCAST_true;
        }
      } else {
        if (vCAST_COMMAND == vCAST_ALLOCATE && vcast_proc_handles_command(1)) {
          int VCAST_TI_9_21_array_size = (int) vCAST_VALUE;
          if (VCAST_FIND_INDEX() == -1) {
            void **VCAST_TI_9_21_memory_ptr = (void**)vcast_param;
            *VCAST_TI_9_21_memory_ptr = (void*)VCAST_malloc(VCAST_TI_9_21_array_size*(sizeof(struct OsAppConfigType_T )));
            VCAST_memset((void*)*vcast_param, 0x0, VCAST_TI_9_21_array_size*(sizeof(struct OsAppConfigType_T )));
#ifndef VCAST_NO_MALLOC
            VCAST_Add_Allocated_Data(*VCAST_TI_9_21_memory_ptr);
#endif
          }
        } else if (vCAST_VALUE_NUL == vCAST_true && vcast_proc_handles_command(1)) {
          if (VCAST_FIND_INDEX() == -1)
            *vcast_param = 0;
        } else {
          VCAST_TI_9_21_index = vcast_get_param();
          VCAST_TI_9_22 ( &((*vcast_param)[VCAST_TI_9_21_index]));
        }
      }
    }
  }
} /* end VCAST_TI_9_21 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A pointer */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_31 ( OsTaskParamType **vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_31 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_31 ( OsTaskParamType **vcast_param ) 
{
  {
    int VCAST_TI_9_31_index;
    if (((*vcast_param) == 0) && (vCAST_COMMAND != vCAST_ALLOCATE)){
      if ( vCAST_COMMAND == vCAST_PRINT )
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"null\n");
    } else {
      if ( (vCAST_COMMAND_IS_MIN_MAX == vCAST_true) &&( VCAST_FIND_INDEX() < 0 ) ) {
        switch ( vCAST_COMMAND ) {
          case vCAST_PRINT     :
            vectorcast_fprint_string(vCAST_OUTPUT_FILE,"0\n");
          case vCAST_FIRST_VAL :
          case vCAST_LAST_VAL  :
          case vCAST_POS_INF_VAL  :
          case vCAST_NEG_INF_VAL  :
          case vCAST_NAN_VAL  :
            break;
          default :
            vCAST_TOOL_ERROR = vCAST_true;
        }
      } else {
        if (vCAST_COMMAND == vCAST_ALLOCATE && vcast_proc_handles_command(1)) {
          int VCAST_TI_9_31_array_size = (int) vCAST_VALUE;
          if (VCAST_FIND_INDEX() == -1) {
            void **VCAST_TI_9_31_memory_ptr = (void**)vcast_param;
            *VCAST_TI_9_31_memory_ptr = (void*)VCAST_malloc(VCAST_TI_9_31_array_size*(sizeof(OsTaskParamType )));
            VCAST_memset((void*)*vcast_param, 0x0, VCAST_TI_9_31_array_size*(sizeof(OsTaskParamType )));
#ifndef VCAST_NO_MALLOC
            VCAST_Add_Allocated_Data(*VCAST_TI_9_31_memory_ptr);
#endif
          }
        } else if (vCAST_VALUE_NUL == vCAST_true && vcast_proc_handles_command(1)) {
          if (VCAST_FIND_INDEX() == -1)
            *vcast_param = 0;
        } else {
          VCAST_TI_9_31_index = vcast_get_param();
          VCAST_TI_9_30 ( &((*vcast_param)[VCAST_TI_9_31_index]));
        }
      }
    }
  }
} /* end VCAST_TI_9_31 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A pointer */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_19 ( struct OsAppConfigType_T **vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_19 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_19 ( struct OsAppConfigType_T **vcast_param ) 
{
  {
    int VCAST_TI_9_19_index;
    if (((*vcast_param) == 0) && (vCAST_COMMAND != vCAST_ALLOCATE)){
      if ( vCAST_COMMAND == vCAST_PRINT )
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"null\n");
    } else {
      if ( (vCAST_COMMAND_IS_MIN_MAX == vCAST_true) &&( VCAST_FIND_INDEX() < 0 ) ) {
        switch ( vCAST_COMMAND ) {
          case vCAST_PRINT     :
            vectorcast_fprint_string(vCAST_OUTPUT_FILE,"0\n");
          case vCAST_FIRST_VAL :
          case vCAST_LAST_VAL  :
          case vCAST_POS_INF_VAL  :
          case vCAST_NEG_INF_VAL  :
          case vCAST_NAN_VAL  :
            break;
          default :
            vCAST_TOOL_ERROR = vCAST_true;
        }
      } else {
        if (vCAST_COMMAND == vCAST_ALLOCATE && vcast_proc_handles_command(1)) {
          int VCAST_TI_9_19_array_size = (int) vCAST_VALUE;
          if (VCAST_FIND_INDEX() == -1) {
            void **VCAST_TI_9_19_memory_ptr = (void**)vcast_param;
            *VCAST_TI_9_19_memory_ptr = (void*)VCAST_malloc(VCAST_TI_9_19_array_size*(sizeof(struct OsAppConfigType_T )));
            VCAST_memset((void*)*vcast_param, 0x0, VCAST_TI_9_19_array_size*(sizeof(struct OsAppConfigType_T )));
#ifndef VCAST_NO_MALLOC
            VCAST_Add_Allocated_Data(*VCAST_TI_9_19_memory_ptr);
#endif
          }
        } else if (vCAST_VALUE_NUL == vCAST_true && vcast_proc_handles_command(1)) {
          if (VCAST_FIND_INDEX() == -1)
            *vcast_param = 0;
        } else {
          VCAST_TI_9_19_index = vcast_get_param();
          VCAST_TI_9_22 ( &((*vcast_param)[VCAST_TI_9_19_index]));
        }
      }
    }
  }
} /* end VCAST_TI_9_19 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A struct */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_22 ( struct OsAppConfigType_T *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_22 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_22 ( struct OsAppConfigType_T *vcast_param ) 
{
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->AppId */
      case 1: { 
        VCAST_TI_9_6 ( &(vcast_param->AppId));
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->AccessId */
      case 2: { 
        VCAST_TI_9_8 ( &(vcast_param->AccessId));
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->AccessLevel */
      case 3: { 
        VCAST_TI_9_6 ( &(vcast_param->AccessLevel));
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->pCoreRef */
      case 4: { 
        VCAST_TI_9_20 ( &(vcast_param->pCoreRef));
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->pObjListRef */
      case 5: { 
        VCAST_TI_9_24 ( &(vcast_param->pObjListRef));
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->pHookRef */
      case 6: { 
        VCAST_TI_9_17 ( &(vcast_param->pHookRef));
        break; /* end case 6*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
} /* end VCAST_TI_9_22 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_30 ( OsTaskParamType *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_30 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_30 ( OsTaskParamType *vcast_param ) 
{
#if (defined(VCAST_NO_TYPE_SUPPORT))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->WaitEventMask */
      case 1: { 
        VCAST_TI_9_3 ( &(vcast_param->WaitEventMask));
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->SetEventMask */
      case 2: { 
        VCAST_TI_9_3 ( &(vcast_param->SetEventMask));
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->StackAddress */
      case 3: { 
        VCAST_TI_9_12 ( &(vcast_param->StackAddress));
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->State */
      case 4: { 
        VCAST_TI_9_6 ( &(vcast_param->State));
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->ActivationCnt */
      case 5: { 
        VCAST_TI_9_6 ( &(vcast_param->ActivationCnt));
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->ResCnt */
      case 6: { 
        VCAST_TI_9_6 ( &(vcast_param->ResCnt));
        break; /* end case 6*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/

} /* end VCAST_TI_9_30 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A pointer */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_20 ( struct OsCoreConfigType_T **vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_20 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_20 ( struct OsCoreConfigType_T **vcast_param ) 
{
  {
    int VCAST_TI_9_20_index;
    if (((*vcast_param) == 0) && (vCAST_COMMAND != vCAST_ALLOCATE)){
      if ( vCAST_COMMAND == vCAST_PRINT )
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"null\n");
    } else {
      if ( (vCAST_COMMAND_IS_MIN_MAX == vCAST_true) &&( VCAST_FIND_INDEX() < 0 ) ) {
        switch ( vCAST_COMMAND ) {
          case vCAST_PRINT     :
            vectorcast_fprint_string(vCAST_OUTPUT_FILE,"0\n");
          case vCAST_FIRST_VAL :
          case vCAST_LAST_VAL  :
          case vCAST_POS_INF_VAL  :
          case vCAST_NEG_INF_VAL  :
          case vCAST_NAN_VAL  :
            break;
          default :
            vCAST_TOOL_ERROR = vCAST_true;
        }
      } else {
        if (vCAST_COMMAND == vCAST_ALLOCATE && vcast_proc_handles_command(1)) {
          int VCAST_TI_9_20_array_size = (int) vCAST_VALUE;
          if (VCAST_FIND_INDEX() == -1) {
            void **VCAST_TI_9_20_memory_ptr = (void**)vcast_param;
            *VCAST_TI_9_20_memory_ptr = (void*)VCAST_malloc(VCAST_TI_9_20_array_size*(sizeof(struct OsCoreConfigType_T )));
            VCAST_memset((void*)*vcast_param, 0x0, VCAST_TI_9_20_array_size*(sizeof(struct OsCoreConfigType_T )));
#ifndef VCAST_NO_MALLOC
            VCAST_Add_Allocated_Data(*VCAST_TI_9_20_memory_ptr);
#endif
          }
        } else if (vCAST_VALUE_NUL == vCAST_true && vcast_proc_handles_command(1)) {
          if (VCAST_FIND_INDEX() == -1)
            *vcast_param = 0;
        } else {
          VCAST_TI_9_20_index = vcast_get_param();
          VCAST_TI_9_29 ( &((*vcast_param)[VCAST_TI_9_20_index]));
        }
      }
    }
  }
} /* end VCAST_TI_9_20 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A pointer */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_17 ( OsHookConfigType **vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_17 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_17 ( OsHookConfigType **vcast_param ) 
{
  {
    int VCAST_TI_9_17_index;
    if (((*vcast_param) == 0) && (vCAST_COMMAND != vCAST_ALLOCATE)){
      if ( vCAST_COMMAND == vCAST_PRINT )
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"null\n");
    } else {
      if ( (vCAST_COMMAND_IS_MIN_MAX == vCAST_true) &&( VCAST_FIND_INDEX() < 0 ) ) {
        switch ( vCAST_COMMAND ) {
          case vCAST_PRINT     :
            vectorcast_fprint_string(vCAST_OUTPUT_FILE,"0\n");
          case vCAST_FIRST_VAL :
          case vCAST_LAST_VAL  :
          case vCAST_POS_INF_VAL  :
          case vCAST_NEG_INF_VAL  :
          case vCAST_NAN_VAL  :
            break;
          default :
            vCAST_TOOL_ERROR = vCAST_true;
        }
      } else {
        if (vCAST_COMMAND == vCAST_ALLOCATE && vcast_proc_handles_command(1)) {
          int VCAST_TI_9_17_array_size = (int) vCAST_VALUE;
          if (VCAST_FIND_INDEX() == -1) {
            void **VCAST_TI_9_17_memory_ptr = (void**)vcast_param;
            *VCAST_TI_9_17_memory_ptr = (void*)VCAST_malloc(VCAST_TI_9_17_array_size*(sizeof(OsHookConfigType )));
            VCAST_memset((void*)*vcast_param, 0x0, VCAST_TI_9_17_array_size*(sizeof(OsHookConfigType )));
#ifndef VCAST_NO_MALLOC
            VCAST_Add_Allocated_Data(*VCAST_TI_9_17_memory_ptr);
#endif
          }
        } else if (vCAST_VALUE_NUL == vCAST_true && vcast_proc_handles_command(1)) {
          if (VCAST_FIND_INDEX() == -1)
            *vcast_param = 0;
        } else {
          VCAST_TI_9_17_index = vcast_get_param();
          VCAST_TI_9_16 ( &((*vcast_param)[VCAST_TI_9_17_index]));
        }
      }
    }
  }
} /* end VCAST_TI_9_17 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A struct */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_29 ( struct OsCoreConfigType_T *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_29 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_29 ( struct OsCoreConfigType_T *vcast_param ) 
{
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->CoreId */
      case 1: { 
        VCAST_TI_9_7 ( &(vcast_param->CoreId));
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->IsAsrCore */
      case 2: { 
        VCAST_TI_9_6 ( &(vcast_param->IsAsrCore));
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->NumOfApp */
      case 3: { 
        VCAST_TI_9_6 ( &(vcast_param->NumOfApp));
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->pAppListRef */
      case 4: { 
        VCAST_TI_9_21 ( &(vcast_param->pAppListRef));
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->pOsCoreAppRef */
      case 5: { 
        VCAST_TI_9_21 ( &(vcast_param->pOsCoreAppRef));
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->pOsCoreObjRef */
      case 6: { 
        VCAST_TI_9_24 ( &(vcast_param->pOsCoreObjRef));
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->pHookRef */
      case 7: { 
        VCAST_TI_9_17 ( &(vcast_param->pHookRef));
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->pCoreSysRef */
      case 8: { 
        VCAST_TI_9_26 ( &(vcast_param->pCoreSysRef));
        break; /* end case 8*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
} /* end VCAST_TI_9_29 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_16 ( OsHookConfigType *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_16 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_16 ( OsHookConfigType *vcast_param ) 
{
#if (defined(VCAST_NO_TYPE_SUPPORT))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->StartHook */
      case 1: { 
        VCAST_TI_9_11 ( &(vcast_param->StartHook));
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->PreHook */
      case 2: { 
        VCAST_TI_9_11 ( &(vcast_param->PreHook));
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->PostHook */
      case 3: { 
        VCAST_TI_9_11 ( &(vcast_param->PostHook));
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->ShutdownHook */
      case 4: { 
        VCAST_TI_9_11 ( &(vcast_param->ShutdownHook));
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->ErrorHook */
      case 5: { 
        VCAST_TI_9_14 ( &(vcast_param->ErrorHook));
        break; /* end case 5*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/

} /* end VCAST_TI_9_16 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A pointer */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_26 ( OsCoreSysConfigType **vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_26 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_26 ( OsCoreSysConfigType **vcast_param ) 
{
  {
    int VCAST_TI_9_26_index;
    if (((*vcast_param) == 0) && (vCAST_COMMAND != vCAST_ALLOCATE)){
      if ( vCAST_COMMAND == vCAST_PRINT )
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"null\n");
    } else {
      if ( (vCAST_COMMAND_IS_MIN_MAX == vCAST_true) &&( VCAST_FIND_INDEX() < 0 ) ) {
        switch ( vCAST_COMMAND ) {
          case vCAST_PRINT     :
            vectorcast_fprint_string(vCAST_OUTPUT_FILE,"0\n");
          case vCAST_FIRST_VAL :
          case vCAST_LAST_VAL  :
          case vCAST_POS_INF_VAL  :
          case vCAST_NEG_INF_VAL  :
          case vCAST_NAN_VAL  :
            break;
          default :
            vCAST_TOOL_ERROR = vCAST_true;
        }
      } else {
        if (vCAST_COMMAND == vCAST_ALLOCATE && vcast_proc_handles_command(1)) {
          int VCAST_TI_9_26_array_size = (int) vCAST_VALUE;
          if (VCAST_FIND_INDEX() == -1) {
            void **VCAST_TI_9_26_memory_ptr = (void**)vcast_param;
            *VCAST_TI_9_26_memory_ptr = (void*)VCAST_malloc(VCAST_TI_9_26_array_size*(sizeof(OsCoreSysConfigType )));
            VCAST_memset((void*)*vcast_param, 0x0, VCAST_TI_9_26_array_size*(sizeof(OsCoreSysConfigType )));
#ifndef VCAST_NO_MALLOC
            VCAST_Add_Allocated_Data(*VCAST_TI_9_26_memory_ptr);
#endif
          }
        } else if (vCAST_VALUE_NUL == vCAST_true && vcast_proc_handles_command(1)) {
          if (VCAST_FIND_INDEX() == -1)
            *vcast_param = 0;
        } else {
          VCAST_TI_9_26_index = vcast_get_param();
          VCAST_TI_9_28 ( &((*vcast_param)[VCAST_TI_9_26_index]));
        }
      }
    }
  }
} /* end VCAST_TI_9_26 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A pointer */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_14 ( void (**vcast_param)(ErrReasonRefType ErrRef) ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_14 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_14 ( void (**vcast_param)(ErrReasonRefType ErrRef) ) 
{
  void (*vcast_local_ptr)(ErrReasonRefType ErrRef);
  switch ( vCAST_COMMAND ) {
    case vCAST_PRINT:
      if ( !*vcast_param )
        vectorcast_fprint_string(vCAST_OUTPUT_FILE, "<<null>>\n");
      else
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<unknown>>\n");
      break;
    case vCAST_SET_VAL:
      if (vCAST_VALUE_NUL == vCAST_true && vcast_proc_handles_command(1)) {
        if (VCAST_FIND_INDEX() == -1)
          *vcast_param = 0;
        return;
      }
      switch ( (int) vCAST_VALUE ) {
      }
      break;
  }
} /* end VCAST_TI_9_14 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_28 ( OsCoreSysConfigType *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_28 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_28 ( OsCoreSysConfigType *vcast_param ) 
{
#if (defined(VCAST_NO_TYPE_SUPPORT))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->StackStartAddress */
      case 1: { 
        VCAST_TI_9_12 ( &(vcast_param->StackStartAddress));
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->StackSize */
      case 2: { 
        VCAST_TI_9_8 ( &(vcast_param->StackSize));
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->StackRegAttribute */
      case 3: { 
        VCAST_TI_9_8 ( &(vcast_param->StackRegAttribute));
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->StackRegnSizeAndEnable */
      case 4: { 
        VCAST_TI_9_8 ( &(vcast_param->StackRegnSizeAndEnable));
        break; /* end case 4*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/

} /* end VCAST_TI_9_28 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


#ifdef VCAST_PARADIGM_ADD_SEGMENT
#pragma new_codesegment(1)
#endif
void VCAST_TI_RANGE_DATA_9 ( void ) {
#define VCAST_TI_SCALAR_TYPE "NEW_SCALAR\n"
#define VCAST_TI_ARRAY_TYPE  "NEW_ARRAY\n"
  /* Range Data for TI (array) VCAST_TI_9_1 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100003\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,21U);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (scalar) VCAST_TI_9_3 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_SCALAR_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"900003\n" );
  vectorcast_fprint_unsigned_long_long (vCAST_OUTPUT_FILE,0 );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_unsigned_long_long (vCAST_OUTPUT_FILE,(ULLONG_MAX / 2) );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_unsigned_long_long (vCAST_OUTPUT_FILE,ULLONG_MAX );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  /* Range Data for TI (scalar) VCAST_TI_9_6 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_SCALAR_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"900006\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,UCHAR_MIN );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,(UCHAR_MIN / 2) + (UCHAR_MAX / 2) );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,UCHAR_MAX );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  /* Range Data for TI (scalar) VCAST_TI_9_7 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_SCALAR_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"900007\n" );
  vectorcast_fprint_unsigned_short (vCAST_OUTPUT_FILE,USHRT_MIN );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_unsigned_short (vCAST_OUTPUT_FILE,(USHRT_MIN / 2) + (USHRT_MAX / 2) );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_unsigned_short (vCAST_OUTPUT_FILE,USHRT_MAX );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  /* Range Data for TI (scalar) VCAST_TI_9_8 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_SCALAR_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"900008\n" );
  vectorcast_fprint_unsigned_long (vCAST_OUTPUT_FILE,ULONG_MIN );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_unsigned_long (vCAST_OUTPUT_FILE,(ULONG_MIN / 2) + (ULONG_MAX / 2) );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_unsigned_long (vCAST_OUTPUT_FILE,ULONG_MAX );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
}
/* Include the file which contains function implementations
for stub processing and value/expected user code */
#include "OsEvent_uc.c"

void vCAST_COMMON_STUB_PROC_9(
            int unitIndex,
            int subprogramIndex,
            int robjectIndex,
            int readEobjectData )
{
   vCAST_BEGIN_STUB_PROC_9(unitIndex, subprogramIndex);
   if ( robjectIndex )
      vCAST_READ_COMMAND_DATA_FOR_ONE_PARAM( unitIndex, subprogramIndex, robjectIndex );
   if ( readEobjectData )
      vCAST_READ_COMMAND_DATA_FOR_ONE_PARAM( unitIndex, subprogramIndex, 0 );
   vCAST_SET_HISTORY( unitIndex, subprogramIndex );
   vCAST_READ_COMMAND_DATA( vCAST_CURRENT_SLOT, unitIndex, subprogramIndex, vCAST_true, vCAST_false );
   vCAST_READ_COMMAND_DATA_FOR_USER_GLOBALS();
   vCAST_STUB_PROCESSING_9(unitIndex, subprogramIndex);
}
#endif /* VCAST_HEADER_EXPANSION */
