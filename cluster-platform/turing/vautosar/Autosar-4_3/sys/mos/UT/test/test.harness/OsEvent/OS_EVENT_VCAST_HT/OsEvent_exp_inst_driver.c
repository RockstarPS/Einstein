/*vcast_separate_expansion_start:S0000009.c*/
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
/*vcast_header_expansion_start:vcast_env_defines.h*/
/*vcast_header_expansion_end*/
/*vcast_header_expansion_start:OsEvent_driver_prefix.c*/
/*vcast_header_expansion_end*/
/*vcast_header_expansion_start:S0000009.h*/
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2025 Vector Informatik, GmbH.    *
 *                18 (02/04/18)                *
 ***********************************************/
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2025 Vector Informatik, GmbH.    *
 *                18 (02/04/18)                *
 ***********************************************/
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2025 Vector Informatik, GmbH.    *
 *                18 (02/04/18)                *
 ***********************************************/
/* ----------------------------------------------------------------------------
-- VectorCAST IO File
-- 
-- DISCLAIMER :
-- This file is provided "AS IS"  by  for the convenience of Vector Software.
-- Inconsistent modifications may cause VectorCAST to fail to work properly
-- 
-------------------------------------------------------------------------------*/
/* setup for "long long" capability */
/* setup for Microsoft "long long" */
/* setup for MinGW "long long" formats */
/* setup for other "long long" formats */
/* end "long long" formats */
/* end "long long" support */
/* no "long long" support */
/* end "long long" check */
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2025 Vector Informatik, GmbH.    *
 *                18 (02/04/18)                *
 ***********************************************/
/* ----------------------------------------------------------------------------
-- These funtions are called at the start and end of the test harenss
-- and contain conditionally compiled code to setup for the particular I/O
-- mode and in some case the particular target.
-------------------------------------------------------------------------------*/
void vectorcast_initialize_io (int inst_status, int inst_fd);
void vectorcast_terminate_io (void);
void vectorcast_write_vcast_end (void);
int vectorcast_fflush(int fpn);
void vectorcast_fclose(int fpn);
int vectorcast_feof(int fpn);
int vectorcast_fopen(char *filename, char *mode);
char *vectorcast_fgets (char *line, int maxline, int fpn);
/* return failure condition if the line we read is too long */
int vectorcast_readline(char *vcast_buf, int fpn);
void vectorcast_fprint_char (int fpn, char vcast_str);
void vectorcast_fprint_char_hex ( int fpn, char vcast_value );
void vectorcast_fprint_char_octl ( int fpn, char vcast_value );
void vectorcast_fprint_string (int fpn, char *vcast_str);
void vectorcast_fprint_string_with_cr (int fpn, char *vcast_str);
void vectorcast_print_string ( char *vcast_str);
void vectorcast_fprint_string_with_length(int fpn, char *vcast_str, int length);
void vectorcast_fprint_short (int vcast_fpn, short vcast_value );
void vectorcast_fprint_integer (int vcast_fpn, int vcast_value );
void vectorcast_fprint_long (int vcast_fpn, long vcast_value );
void vectorcast_fprint_long_long (int vcast_fpn, long long vcast_value );
void vectorcast_fprint_unsigned_short (int vcast_fpn,
                                       unsigned short vcast_value );
void vectorcast_fprint_unsigned_integer (int vcast_fpn,
                                         unsigned int vcast_value );
void vectorcast_fprint_unsigned_long (int vcast_fpn,
                                      unsigned long vcast_value );
void vectorcast_fprint_unsigned_long_long (int vcast_fpn,
                                           unsigned long long vcast_value );
void vectorcast_fprint_long_float (int fpn, vCAST_long_double);
/* numeric conversion routines */
void vcast_signed_to_string ( char vcDest[],
                              long long vcSrc );
void vcast_unsigned_to_string ( char vcDest[],
                                unsigned long long vcSrc );
void vcast_float_to_string ( char *mixed_str, vCAST_long_double vcast_f );
/* ----------------------------------------------------------------------------
-- API for Harness Trace Functions
-----------------------------------------------------------------------------*/
/* To write output, the normal API is: vectorcast_print_string
   vectorcast_write_to_std_out should only be used for abnormal termination
   and debug trace messages */
void vectorcast_write_to_std_out ( char *s);
/*---------------------------------------------------------------------------*/
void vcast_char_to_based_string ( char vcDest[],
                                  unsigned char vcSrc,
                                  unsigned vcUseHex );
/* ----------------------------------------------------------------------------
-- To Save Output Size, for some targets using stdout mode, we output a 
-- number rather than a filename.  So for example, we put out: 
-- "1: data" instead of: "ASCIIRES.DAT: data"
-- JJP TBD: Not sure why this needs to be in the header --
-------------------------------------------------------------------------------*/
enum vcast_env_file_kind
{
   VCAST_ASCIIRES_DAT = 1,
   VCAST_EXPECTED_DAT = 2,
   VCAST_TEMP_DIF_DAT = 3,
   VCAST_TESTINSS_DAT = 4,
   VCAST_THISTORY_DAT = 5,
   VCAST_USERDATA_DAT = 6
};
/* Get the name of the file */
char *vcast_get_filename(enum vcast_env_file_kind kind);
/* ----------------------------------------------------------------------------
-- Need to evaluate these items
-- JJP TBD
-------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------*/
/* End of File, close the Extern C block */
extern int vCAST_ITERATION_COUNTERS [3][19];
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2025 Vector Informatik, GmbH.    *
 *                18 (02/04/18)                *
 ***********************************************/
extern vCAST_array_boolean vCAST_GLOBALS_TOUCHED[6];
enum vCAST_testcase_options_type {
        vCAST_MULTI_RETURN_SPANS_RANGE,
        vCAST_MULTI_RETURN_SPANS_COMPOUND_ITERATIONS,
        vCAST_DISPLAY_INTEGER_RESULTS_IN_HEX,
        vCAST_DISPLAY_FULL_STRING_DATA,
        vCAST_HEX_NOTATION_FOR_UNPRINTABLE_CHARS,
        vCAST_DO_COMBINATION,
        vCAST_REFERENCED_GLOBALS,
        vCAST_FLOAT_POINT_DIGITS_OF_PRECISION,
        vCAST_FLOAT_POINT_TOLERANCE,
        vCAST_EVENT_LIMIT,
        vCAST_GLOBAL_DATA_DISPLAY,
        vCAST_EXPECTED_BEFORE_UUT_CALL,
        vCAST_DATA_PARTITIONS,
        vCAST_SHOW_ONLY_DATA_WITH_EXPECTED_RESULTS,
        vCAST_SHOW_ONLY_EVENTS_WITH_EXPECTED_RESULTS};
enum vCAST_globals_display_type {
        vCAST_EACH_EVENT,
        vCAST_RANGE_ITERATION,
        vCAST_SLOT_ITERATION,
        vCAST_TESTCASE};
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2025 Vector Informatik, GmbH.    *
 *                18 (02/04/18)                *
 ***********************************************/
/*************************************************************************
File : S0000004.c
Description : This file contains the declarations of functions in the 
   B0000004.c file.
***************************************************************************/
void vCAST_INITIALIZE_PARAMETERS(void);
void vCAST_USER_CODE_INITIALIZE(int vcast_slot_index, vCAST_boolean commands_read);
void vCAST_USER_CODE_CAPTURE (void);
void vCAST_USER_CODE_CAPTURE_GLOBALS (void);
void vCAST_ONE_SHOT_INIT(void);
void vCAST_ONE_SHOT_TERM(void);
void vCAST_GLOBAL_STUB_PROCESSING(void);
void vCAST_GLOBAL_BEGINNING_OF_STUB_PROCESSING(void);
typedef enum {
   VCAST_UCT_VALUE,
   VCAST_UCT_EXPECTED,
   VCAST_UCT_EXPECTED_GLOBALS
} VCAST_USER_CODE_TYPE;
void vCAST_USER_CODE( VCAST_USER_CODE_TYPE uct, int vcast_slot_index );
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2025 Vector Informatik, GmbH.    *
 *                18 (02/04/18)                *
 ***********************************************/
#include "c:/vcast/mingw/include/stdlib.h"
#include "c:/vcast/mingw/include/setjmp.h"
#include "c:/vcast/mingw/include/stdio.h"
#include "c:/vcast/mingw/include/string.h"
/* Wrappers for malloc and realloc are provided in B2.c */
void * VCAST_malloc (unsigned int vcast_size);
long long VCAST_atoi ( char *vcast_str );
unsigned long long VCAST_strtoul( char *vcast_nptr, char **vcast_endptr, int vcast_base);
int VCAST_signed_strlen ( signed char *vcast_str );
void VCAST_signed_strcpy ( signed char *VC_S, signed char *VC_T );
 extern jmp_buf VCAST_env;
/* This define use to define the temporary strings that we use
   when we are breaking down the harness commands like: "0.0.3.4%0\n"
   We use 8 because we do not expect a unit, subprogram, parameter, or field
   to be larger than 999999\n\0
*/
typedef long int vCAST_BIG_INT;
enum vCAST_COMMAND_TYPE { vCAST_SET_VAL,
                             vCAST_PRINT,
                             vCAST_FIRST_VAL,
                             vCAST_MID_VAL,
                             vCAST_LAST_VAL,
                             vCAST_POS_INF_VAL,
                             vCAST_NEG_INF_VAL,
                             vCAST_NAN_VAL,
                             vCAST_MIN_MINUS_1_VAL,
                             vCAST_MAX_PLUS_1_VAL,
                             vCAST_ZERO_VAL,
                             vCAST_KEEP_VAL,
                             vCAST_ALLOCATE,
                             vCAST_STUB_FUNCTION,
                             vCAST_FUNCTION };
struct vCAST_HIST_ENTRY {
  int VC_U;
  int VC_S;
};
struct vCAST_ORDER_ENTRY {
  int VC_I;
  char VC_N[13];
  char VC_T[1000];
  char VC_SLOT_DESCR[1000];
  char VC_PRINT_DATA[1000];
};
enum VCAST_RANGE_DATA_TYPE {
   VCAST_NULL_TYPE = 0,
   VCAST_RANGE_TYPE,
   VCAST_LIST_TYPE
};
/* If the max range is not set by the user at all
   we default to 20 */
/* if the user explicitly sets the max range to be 0,
   it means they don't want range processing at all */
struct vCAST_RANGE_DATA
{
  char *vCAST_COMMAND; /* command */
  enum VCAST_RANGE_DATA_TYPE vCAST_type; /* Determines range, list or null */
  /* For Range */
  vCAST_long_double vCAST_MIN; /* Min value */
  vCAST_long_double vCAST_MAX; /* Max value */
  vCAST_long_double vCAST_INC; /* Increment value */
  /* For List */
  char *vCAST_list; /* The actual list values */
  /* Is integer */
  int isInteger; /* 1 if min/mid/max is integer, 0 otherwise */
  int vCAST_COMBO_GROUPING; /* Number of times to repeat a command for combination testing before resetting */
  int vCAST_NUM_VALS;
};
/* vCAST function prototypes */
vCAST_double vCAST_power (short vcast_bits);
vCAST_long_double VCAST_itod ( char vcastStringParam[] );
void vCAST_SET_TESTCASE_CONFIGURATION_OPTIONS( int VCAST_option,int VCAST_value, int VCAST_set_default);
void vCAST_SET_TESTCASE_OPTIONS ( char vcast_options[] );
void vCAST_RUN_DATA_IF (char VCAST_PARAM[], vCAST_boolean POST_CONSTRUCTOR_USER_CODE);
void vCAST_slice (char vcast_target[], char vcast_source[], int vcast_first, int vcast_last);
void vCAST_EXTRACT_DATA_FROM_COMMAND_LINE (char *vcast_buf, char VCAST_PARAM[], int VC_POSITION);
void vCAST_STR_TO_LONG_DOUBLE(char vcastStringParam[], vCAST_long_double * vcastFloatParam);
void vCAST_DOUBLE_TO_STR (vCAST_long_double VC_F, char VC_S[], int VC_AS_INT);
void vCAST_RESET_LIST_VALUES(void);
void vCAST_ITERATION_COUNTER_RESET(void);
void vCAST_RESET_ITERATION_COUNTERS(enum vCAST_testcase_options_type );
int vCAST_GET_ITERATION_COUNTER_VALUE(int, int);
void vCAST_INCREMENT_ITERATION_COUNTER(int, int);
void vCAST_EXECUTE_RANGE_COMMANDS (int);
/* if range processing is disabled, no need to do this stuff!*/
void vCAST_GET_RANGE_VALUES(char *vcast_S, struct vCAST_RANGE_DATA *vcast_range_data);
void vCAST_MODIFY_SBF_TABLE(int sbf_unit, int vcast_sub, vCAST_boolean stubbed);
void vCAST_INITIALIZE_SBF_TABLE(void);
vCAST_boolean vCAST_is_sbf(long long vcast_unit, long long vcast_sub);
typedef unsigned char vcast_sbf_object_type;
void VCAST_TI_SBF_OBJECT(vcast_sbf_object_type* vcast_param);
void vCAST_RESET_RANGE_VALUES (void);
void vCAST_INITIALIZE_RANGE_VALUES (void);
void vCAST_FREE_RANGE_VALUES(void);
void vCAST_STORE_GLOBAL_ASCII_DATA (void);
void vCAST_CREATE_EVENT_FILE (void);
void vCAST_CREATE_HIST_FILE (void);
void vCAST_OPEN_HIST_FILE (void);
void vCAST_CREATE_INST_FILE (void);
int VCAST_test_name_cmp(char *vcast_tn);
long VCAST_convert_encoded_field( char *vcast_str);
/* Code coverage-related functions */
void vCAST_CREATE_INST_FILE (void);
void VCAST_WRITE_TO_INST_FILE ( char VC_S[]);
/* An explanation for the number of bytes required for VectorCAST/Cover.

 * 

 * This represents the maximum amount of RAM that will be required

 * to record coverage data when 100% of your application is executed.

 * It is likely that only a percentage of this storage will be 

 * required during a single program execution.

 * 

 * Please note, when using the static memory option, all of this data 

 * must be reserved in the instrumented executable through global arrays.

 * When you are not using the static memory option, this data is not 

 * reserved in the instrumented executable, and it is allocated on 

 * demand through the use of the malloc system call.

 * 

 * When instrumenting for MCDC, the size of the variables 

 * mcdc_statement_pool and avlnode_pool are controlled with the option 

 * "Maximum MC/DC expressions". The default is set to 1000, 

 * so that a large test case can execute with out fear of 

 * over flowing these buffers. The number chosen (e.g. 1000) will 

 * provide storage for that many unique MC/DC expressions.

 * 

 * For a 16 bit executable configuration:

 *   function call bit array:.............size: 1          bytes:  0 *

 *   Total (no MC/DC pool storage):......................................bytes:  0 *

 * 

 * For a 32 bit executable configuration:

 *   function call bit array:.............size: 1          bytes:  0 *

 *   Total (no MC/DC pool storage):......................................bytes:  0 *

 * 

 * For a 64 bit executable configuration:

 *   function call bit array:.............size: 1          bytes:  0 *

 *   Total (no MC/DC pool storage):......................................bytes:  0 *

 */
void vCAST_SET_OUTPUT_TO_EVENT_FILE (void);
void vCAST_CLOSE_INST_FILE (void);
/* Coverage data */
void vCAST_SET_OUTPUT_TO_EVENT_FILE (void);
void vCAST_CLOSE_INST_FILE (void);
void vCAST_CLOSE_EVENT_FILE (void);
void vCAST_CLOSE_HIST_FILE (void);
void vCAST_WRITE_END_FILE(void);
void vCAST_OPEN_E0_FILE (void);
void vCAST_OPEN_HARNOPTS_FILE(void);
void vCAST_RESET_HARNOPTS_FILE(void);
void vCAST_OPEN_TESTORDR_FILE (void);
void VCAST_READ_TESTORDER_LINE ( char[] );
void vCAST_STORE_ASCII_DATA ( int, int, char[] );
vCAST_boolean vCAST_READ_NEXT_ORDER (void);
vCAST_boolean vCAST_SHOULD_DISPLAY_GLOBALS ( int, char[] );
extern int vcast_user_file;
extern int VCAST_EXP_FILE;
extern int vCAST_UNIT;
extern int vCAST_SUBPROGRAM;
extern vCAST_boolean vCAST_DO_DATA_IF;
extern char vCAST_TEST_NAME[];
extern int vCAST_CURRENT_SLOT;
extern int vCAST_CURRENT_ITERATION;
extern int vCAST_HIST_INDEX;
extern int vCAST_HIST_LIMIT;
extern int vCAST_ENV_HIST_LIMIT;
extern vCAST_boolean vCAST_HAS_RANGE;
extern vCAST_boolean vCAST_SKIP_ITER;
extern int vCAST_NUM_RANGE_ITERATIONS;
extern int vCAST_RANGE_COUNTER;
extern struct vCAST_RANGE_DATA vCAST_RANGE_COUNT[];
extern struct vCAST_ORDER_ENTRY vCAST_ORDER_OBJECT;
extern vCAST_long_double vCAST_PARTITIONS;
extern vCAST_boolean vCAST_COMMAND_IS_MIN_MAX;
extern int vCAST_INST_FILE;
/* file identificastion number for the ASCIIRES.DAT file */
extern int vCAST_EVENT_FILE;
/* file identification number for the THISTORY.DAT file */
extern int vCAST_HIST_FILE;
extern int vCAST_ORDER_FILE;
extern int vCAST_E0_FILE;
/* file identification number for the TEMP_DIF.DAT file */
extern int vCAST_OUTPUT_FILE;
extern int vCAST_COUNT;
extern int vCAST_CURRENT_COUNT;
extern vCAST_array_boolean vCAST_TESTCASE_OPTIONS[15];
extern vCAST_boolean vcast_is_in_union;
extern vCAST_boolean vCAST_INST_FILE_OPEN;
/* true if the ASCIIRES.DAT file is open */
extern vCAST_boolean vCAST_EVENT_FILE_OPEN;
/* true if the THISTORY.DAT file is open */
extern vCAST_boolean vCAST_HIST_FILE_OPEN;
/* default harness options (from HARNOPTS.DAT) */
extern vCAST_boolean VCAST_DEFAULT_FULL_STRINGS;
extern vCAST_boolean VCAST_DEFAULT_HEX_NOTATION;
extern vCAST_boolean VCAST_DEFAULT_DO_COMBINATION;
extern unsigned short VCAST_GLOBALS_DISPLAY; /* when to capture global data */
extern vCAST_boolean VCAST_GLOBAL_FIRST_EVENT;
extern vCAST_boolean vCAST_HEX_NOTATION; /* use hex notation or not */
extern vCAST_boolean vCAST_DO_COMBINATION_TESTING;/* generate combination or not */
struct vCAST_ORDER_ENTRY* vCAST_ORDER(void);
void vCAST_signal(int sig);
void VCAST_driver_termination(int vcast_status, int eventCode);
int vcast_get_hc_id (char *vcast_command);
void vcast_get_unit_id_str (char *vcast_command, char *vcast_unit);
int vcast_get_unit_id (char *vcast_command);
void vcast_get_subprogram_id_str (char *vcast_command, char *vcast_subprogram);
int vcast_get_subprogram_id (char *vcast_command);
void vcast_get_parameter_id_str (char *vcast_command, char *vcast_subprogram);
int vcast_get_parameter_id (char *vcast_command);
int vcast_get_percent_pos (char *vcast_command);
void vCAST_END(void);
void VCAST_SLOT_SEPARATOR ( int VC_EndOfSlot, char VC_SLOT_DESCR );
/* "limits.h" and "float.h" has limits on base types
   If we don't use it, or some types do
   not have limits, define them here */
#include "c:/vcast/mingw/include/limits.h"
#include "c:/vcast/mingw/lib/gcc/mingw32/6.3.0/include/float.h"
/* FUNCTION PROTOTYPES */
void VCAST_get_indices(char *str_val, int *array_size);
void vCAST_signal(int sig);
void vcast_not_supported (void);
void vcast_get_range_value ( int *vCAST_FIRST_VAL,
                             int *vCAST_LAST_VAL,
                             int *vCAST_MORE_DATA);
int vcast_get_param (void);
int VCAST_FIND_INDEX (void);
/*------------------------------------------------------------------*/
vCAST_double vCAST_power (short vcast_bits);
void VCAST_TI_BITFIELD ( long long *vc_VAL, int Bits, vCAST_boolean is_signed );
void VCAST_TI_STRING (
      char **vcast_param,
      int vCAST_Size,
      int from_bounded_array,
      int size_of_bounded_array );
int vcast_add_to_hex(int previousNumber, char latestDigit);
char vcast_get_non_numerical_escape(char character);
int vcast_convert_size(char * input);
char * VCAST_convert(char * input);
/* ASCII value of the first char that can be displayed */
/* ASCII value of the last char that can be displayed */
/**************************************************************************
Function: isUnprintable
Parameters: character - character to check
Description: This function returns true if the character it is given is
a nongraphical one. 
 *************************************************************************/
void vCAST_slice ( char vcast_target[], char source[], int vcast_first, int vcast_last );
vCAST_boolean vcast_proc_handles_command(int vc_m);
void VCAST_SET_GLOBAL_SIZE(unsigned int *vcast_size);
unsigned int *VCAST_GET_GLOBAL_SIZE(void);
/* EXTERNED VARIABLES */
extern int vCAST_FILE;
extern char vCAST_PARAMETER[1000];
extern char vCAST_PARAMETER_KEY[1000];
extern long long vCAST_VALUE_INT;
extern unsigned long long vCAST_VALUE_UNSIGNED;
extern vCAST_long_double vCAST_VALUE;
extern int vCAST_PARAM_LENGTH;
extern int vCAST_INDEX;
extern int vCAST_DATA_FIELD;
extern int *VCAST_index_size;
extern int VCAST_index_count;
extern enum vCAST_COMMAND_TYPE vCAST_COMMAND;
extern vCAST_boolean vCAST_VALUE_NUL;
extern vCAST_boolean vCAST_SIZE;
extern vCAST_boolean vCAST_can_print_constructor;
struct VCAST_CSU_Data_Item
{
  void *vcast_item;
  char *vcast_command;
  struct VCAST_CSU_Data_Item *vcast_next;
};
struct VCAST_CSU_Data;
void VCAST_Add_CSU_Data (struct VCAST_CSU_Data **vcast_data,
                         struct VCAST_CSU_Data_Item *vcast_data_item);
struct VCAST_CSU_Data_Item *VCAST_Get_CSU_Data (
                         struct VCAST_CSU_Data **vcast_data,
                         char *vcast_command);
void VCAST_DRIVER_8( int VC_SUBPROGRAM, char *VC_EVENT_FLAGS, char *VC_SLOT_DESCR );
void VCAST_DRIVER_9( int VC_SUBPROGRAM, char *VC_EVENT_FLAGS, char *VC_SLOT_DESCR );void VCAST_SBF_9( int VC_SUBPROGRAM );
/*vcast_header_expansion_end*/
#include "vcast_undef_9.h"
/* Include the file which contains function prototypes
for stub processing and value/expected user code */
/*vcast_header_expansion_start:vcast_uc_prototypes.h*/
void vCAST_VALUE_USER_CODE_8(int vcast_slot_index );
void vCAST_EXPECTED_USER_CODE_8(int vcast_slot_index );
void vCAST_EGLOBALS_USER_CODE_8(int vcast_slot_index );
void vCAST_STUB_PROCESSING_8(
        int UnitIndex,
        int SubprogramIndex );
void vCAST_BEGIN_STUB_PROC_8(
        int UnitIndex,
        int SubprogramIndex );
void vCAST_COMMON_STUB_PROC_8(
            int unitIndex,
            int subprogramIndex,
            int robjectIndex,
            int readEobjectData );
void vCAST_VALUE_USER_CODE_9(int vcast_slot_index );
void vCAST_EXPECTED_USER_CODE_9(int vcast_slot_index );
void vCAST_EGLOBALS_USER_CODE_9(int vcast_slot_index );
void vCAST_STUB_PROCESSING_9(
        int UnitIndex,
        int SubprogramIndex );
void vCAST_BEGIN_STUB_PROC_9(
        int UnitIndex,
        int SubprogramIndex );
void vCAST_COMMON_STUB_PROC_9(
            int unitIndex,
            int subprogramIndex,
            int robjectIndex,
            int readEobjectData );
void vCAST_VALUE_USER_CODE_9(int vcast_slot_index );
void vCAST_EXPECTED_USER_CODE_9(int vcast_slot_index );
void vCAST_EGLOBALS_USER_CODE_9(int vcast_slot_index );
void vCAST_STUB_PROCESSING_9(
        int UnitIndex,
        int SubprogramIndex );
void vCAST_BEGIN_STUB_PROC_9(
        int UnitIndex,
        int SubprogramIndex );
void vCAST_COMMON_STUB_PROC_9(
            int unitIndex,
            int subprogramIndex,
            int robjectIndex,
            int readEobjectData );
/*vcast_header_expansion_end*/
/*vcast_header_expansion_start:vcast_stubs_9.c*/
/* Begin defined extern variables */
/* INITIALIZATION_OBJECTS_USER_CODE "1" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "1" */
OsTaskConfigRefType TcbTaskRefConfig[21U]
/* INITIALIZATION_CODE_USER_CODE "1" */
/* INITIALIZATION_CODE_USER_CODE_END "1" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "2" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "2" */
OsCtrlParamType OsCtrlParam
/* INITIALIZATION_CODE_USER_CODE "2" */
/* INITIALIZATION_CODE_USER_CODE_END "2" */
;
/* End defined extern variables */
/* Begin defined static member variables */
/* End defined static member variables */
/* BEGIN PROTOTYPE STUBS */
void OsStartDispatchMetric(void)
{
  vCAST_USER_CODE_TIMER_STOP();
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 1, 1, 0 );
  } /* vcast_is_in_driver */
  vCAST_USER_CODE_TIMER_START();
  return;
}
unsigned char P_10_2_1
;
void osSchedInsertTask(TaskType TaskIndex)
{
  vCAST_USER_CODE_TIMER_STOP();
  if ( vcast_is_in_driver ) {
    P_10_2_1 = TaskIndex;
    vCAST_COMMON_STUB_PROC_9( 10, 2, 2, 0 );
  } /* vcast_is_in_driver */
  vCAST_USER_CODE_TIMER_START();
  return;
}
void osSchedRemoveTask(void)
{
  vCAST_USER_CODE_TIMER_STOP();
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 3, 1, 0 );
  } /* vcast_is_in_driver */
  vCAST_USER_CODE_TIMER_START();
  return;
}
void osEnableAllInterrupts(void)
{
  vCAST_USER_CODE_TIMER_STOP();
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 4, 1, 0 );
  } /* vcast_is_in_driver */
  vCAST_USER_CODE_TIMER_START();
  return;
}
unsigned char R_10_5;
osbool osCheckInterruptsEnabled(void)
{
  vCAST_USER_CODE_TIMER_STOP();
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 5, 1, 0 );
  } /* vcast_is_in_driver */
  vCAST_USER_CODE_TIMER_START();
  return R_10_5;
}
void OsPrvEnterCriticalSection(void)
{
  vCAST_USER_CODE_TIMER_STOP();
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 6, 1, 0 );
  } /* vcast_is_in_driver */
  vCAST_USER_CODE_TIMER_START();
  return;
}
void OsPrvExitCriticalSection(void)
{
  vCAST_USER_CODE_TIMER_STOP();
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 7, 1, 0 );
  } /* vcast_is_in_driver */
  vCAST_USER_CODE_TIMER_START();
  return;
}
void osDispatchAsm(void)
{
  vCAST_USER_CODE_TIMER_STOP();
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 8, 1, 0 );
  } /* vcast_is_in_driver */
  vCAST_USER_CODE_TIMER_START();
  return;
}
unsigned long P_10_9_1
;
unsigned char *P_10_9_2
;
unsigned char P_10_9_3
;
void OsErr_osApplicationErrorHook(OsServiceIdType ServiceId, StatusType * pStatus, StatusType Status)
{
  vCAST_USER_CODE_TIMER_STOP();
  if ( vcast_is_in_driver ) {
    P_10_9_1 = ServiceId;
    P_10_9_2 = pStatus;
    P_10_9_3 = Status;
    vCAST_COMMON_STUB_PROC_9( 10, 9, 4, 0 );
  } /* vcast_is_in_driver */
  vCAST_USER_CODE_TIMER_START();
  return;
}
void osTaskStopHook(void)
{
  vCAST_USER_CODE_TIMER_STOP();
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 10, 1, 0 );
  } /* vcast_is_in_driver */
  vCAST_USER_CODE_TIMER_START();
  return;
}
unsigned short R_10_11;
osuint16 Os_GetContext(void)
{
  vCAST_USER_CODE_TIMER_STOP();
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 11, 1, 0 );
  } /* vcast_is_in_driver */
  vCAST_USER_CODE_TIMER_START();
  return R_10_11;
}
unsigned long R_10_12;
osIntGlobaltype osSuspendInterruptsAsm(void)
{
  vCAST_USER_CODE_TIMER_STOP();
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 12, 1, 0 );
  } /* vcast_is_in_driver */
  vCAST_USER_CODE_TIMER_START();
  return R_10_12;
}
/* END PROTOTYPE STUBS */
/*vcast_header_expansion_end*/
/* begin declarations of inlined friends */
/* end declarations of inlined friends */
void VCAST_DRIVER_9( int VC_SUBPROGRAM, char *VC_EVENT_FLAGS, char *VC_SLOT_DESCR ) {
  vCAST_MODIFY_SBF_TABLE(9, VC_SUBPROGRAM, vCAST_false);
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
/*vcast_header_expansion_start:vcast_ti_decls_9.h*/
void VCAST_TI_9_11 ( void (**vcast_param)(void) ) ;
void VCAST_TI_9_14 ( void (**vcast_param)(ErrReasonRefType ErrRef) ) ;
void VCAST_TI_9_1 ( OsTaskConfigRefType vcast_param[21U] ) ;
void VCAST_TI_9_12 ( unsigned long **vcast_param ) ;
void VCAST_TI_9_16 ( OsHookConfigType *vcast_param ) ;
void VCAST_TI_9_17 ( OsHookConfigType **vcast_param ) ;
void VCAST_TI_9_19 ( struct OsAppConfigType_T **vcast_param ) ;
void VCAST_TI_9_2 ( unsigned char **vcast_param ) ;
void VCAST_TI_9_20 ( struct OsCoreConfigType_T **vcast_param ) ;
void VCAST_TI_9_21 ( struct OsAppConfigType_T **vcast_param ) ;
void VCAST_TI_9_22 ( struct OsAppConfigType_T *vcast_param ) ;
void VCAST_TI_9_24 ( OsObjConfigType **vcast_param ) ;
void VCAST_TI_9_25 ( OsObjConfigType *vcast_param ) ;
void VCAST_TI_9_26 ( OsCoreSysConfigType **vcast_param ) ;
void VCAST_TI_9_28 ( OsCoreSysConfigType *vcast_param ) ;
void VCAST_TI_9_29 ( struct OsCoreConfigType_T *vcast_param ) ;
void VCAST_TI_9_3 ( unsigned long long *vcast_param ) ;
void VCAST_TI_9_30 ( OsTaskParamType *vcast_param ) ;
void VCAST_TI_9_31 ( OsTaskParamType **vcast_param ) ;
void VCAST_TI_9_33 ( OsTaskConfigType *vcast_param ) ;
void VCAST_TI_9_34 ( OsTaskConfigType **vcast_param ) ;
void VCAST_TI_9_36 ( OsAppParamType *vcast_param ) ;
void VCAST_TI_9_38 ( OsCoreParamType *vcast_param ) ;
void VCAST_TI_9_4 ( OsCtrlParamType *vcast_param ) ;
void VCAST_TI_9_5 ( unsigned long long **vcast_param ) ;
void VCAST_TI_9_6 ( unsigned char *vcast_param ) ;
void VCAST_TI_9_7 ( unsigned short *vcast_param ) ;
void VCAST_TI_9_8 ( unsigned long *vcast_param ) ;
/*vcast_header_expansion_end*/
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
/* A typedef */
void VCAST_TI_9_4 ( OsCtrlParamType *vcast_param )
{
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
} /* end VCAST_TI_9_4 */
/* An integer */
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
    *vcast_param = ( unsigned char ) vCAST_VALUE_INT;
    break;
  case vCAST_FIRST_VAL :
    *vcast_param = 0;
    break;
  case vCAST_MID_VAL :
    *vcast_param = (0 / 2) + (
                                     255 
                                               / 2);
    break;
  case vCAST_LAST_VAL :
    *vcast_param = 
                  255
                           ;
    break;
  case vCAST_MIN_MINUS_1_VAL :
    *vcast_param = 0;
    *vcast_param = *vcast_param - 1;
    break;
  case vCAST_MAX_PLUS_1_VAL :
    *vcast_param = 
                  255
                           ;
    *vcast_param = *vcast_param + 1;
    break;
  case vCAST_ZERO_VAL :
    *vcast_param = 0;
    break;
  default:
    break;
} /* end switch */
} /* end VCAST_TI_9_6 */
/* An integer */
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
    *vcast_param = ( unsigned long ) vCAST_VALUE_UNSIGNED;
    break;
  case vCAST_FIRST_VAL :
    *vcast_param = 0;
    break;
  case vCAST_MID_VAL :
    *vcast_param = (0 / 2) + (
                                     0xFFFFFFFFUL 
                                               / 2);
    break;
  case vCAST_LAST_VAL :
    *vcast_param = 
                  0xFFFFFFFFUL
                           ;
    break;
  case vCAST_MIN_MINUS_1_VAL :
    *vcast_param = 0;
    *vcast_param = *vcast_param - 1;
    break;
  case vCAST_MAX_PLUS_1_VAL :
    *vcast_param = 
                  0xFFFFFFFFUL
                           ;
    *vcast_param = *vcast_param + 1;
    break;
  case vCAST_ZERO_VAL :
    *vcast_param = 0;
    break;
  default:
    break;
} /* end switch */
} /* end VCAST_TI_9_8 */
/* A pointer */
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
          case vCAST_PRINT :
            vectorcast_fprint_string(vCAST_OUTPUT_FILE,"0\n");
          case vCAST_FIRST_VAL :
          case vCAST_LAST_VAL :
          case vCAST_POS_INF_VAL :
          case vCAST_NEG_INF_VAL :
          case vCAST_NAN_VAL :
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
            memset((void*)*vcast_param, 0x0, VCAST_TI_9_2_array_size*(sizeof(unsigned char )));
            ;
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
/* An integer */
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
    *vcast_param = ( unsigned short ) vCAST_VALUE_INT;
    break;
  case vCAST_FIRST_VAL :
    *vcast_param = 0;
    break;
  case vCAST_MID_VAL :
    *vcast_param = (0 / 2) + (
                                     0xFFFF 
                                               / 2);
    break;
  case vCAST_LAST_VAL :
    *vcast_param = 
                  0xFFFF
                           ;
    break;
  case vCAST_MIN_MINUS_1_VAL :
    *vcast_param = 0;
    *vcast_param = *vcast_param - 1;
    break;
  case vCAST_MAX_PLUS_1_VAL :
    *vcast_param = 
                  0xFFFF
                           ;
    *vcast_param = *vcast_param + 1;
    break;
  case vCAST_ZERO_VAL :
    *vcast_param = 0;
    break;
  default:
    break;
} /* end switch */
} /* end VCAST_TI_9_7 */
/* An integer */
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
    *vcast_param = ( unsigned long long ) vCAST_VALUE_UNSIGNED;
    break;
  case vCAST_FIRST_VAL :
    *vcast_param = 0;
    break;
  case vCAST_MID_VAL :
    *vcast_param = (
                   (2ULL * 9223372036854775807LL + 1) 
                              / 2);
    break;
  case vCAST_LAST_VAL :
    *vcast_param = 
                  (2ULL * 9223372036854775807LL + 1)
                            ;
    break;
  case vCAST_MIN_MINUS_1_VAL :
    *vcast_param = 0;
    *vcast_param = *vcast_param - 1;
    break;
  case vCAST_MAX_PLUS_1_VAL :
    *vcast_param = 
                  (2ULL * 9223372036854775807LL + 1)
                            ;
    *vcast_param = *vcast_param + 1;
    break;
  case vCAST_ZERO_VAL :
    *vcast_param = 0;
    break;
  default:
    break;
} /* end switch */
} /* end VCAST_TI_9_3 */
/* A pointer */
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
          case vCAST_PRINT :
            vectorcast_fprint_string(vCAST_OUTPUT_FILE,"0\n");
          case vCAST_FIRST_VAL :
          case vCAST_LAST_VAL :
          case vCAST_POS_INF_VAL :
          case vCAST_NEG_INF_VAL :
          case vCAST_NAN_VAL :
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
            memset((void*)*vcast_param, 0x0, VCAST_TI_9_5_array_size*(sizeof(unsigned long long )));
            ;
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
/* A pointer */
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
          case vCAST_PRINT :
            vectorcast_fprint_string(vCAST_OUTPUT_FILE,"0\n");
          case vCAST_FIRST_VAL :
          case vCAST_LAST_VAL :
          case vCAST_POS_INF_VAL :
          case vCAST_NEG_INF_VAL :
          case vCAST_NAN_VAL :
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
            memset((void*)*vcast_param, 0x0, VCAST_TI_9_34_array_size*(sizeof(OsTaskConfigType )));
            ;
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
/* A typedef */
void VCAST_TI_9_38 ( OsCoreParamType *vcast_param )
{
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
} /* end VCAST_TI_9_38 */
/* A typedef */
void VCAST_TI_9_36 ( OsAppParamType *vcast_param )
{
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
} /* end VCAST_TI_9_36 */
/* A pointer */
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
          case vCAST_PRINT :
            vectorcast_fprint_string(vCAST_OUTPUT_FILE,"0\n");
          case vCAST_FIRST_VAL :
          case vCAST_LAST_VAL :
          case vCAST_POS_INF_VAL :
          case vCAST_NEG_INF_VAL :
          case vCAST_NAN_VAL :
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
            memset((void*)*vcast_param, 0x0, VCAST_TI_9_24_array_size*(sizeof(OsObjConfigType )));
            ;
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
/* A typedef */
void VCAST_TI_9_33 ( OsTaskConfigType *vcast_param )
{
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
} /* end VCAST_TI_9_33 */
/* A typedef */
void VCAST_TI_9_25 ( OsObjConfigType *vcast_param )
{
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
} /* end VCAST_TI_9_25 */
/* A pointer */
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
/* A pointer */
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
          case vCAST_PRINT :
            vectorcast_fprint_string(vCAST_OUTPUT_FILE,"0\n");
          case vCAST_FIRST_VAL :
          case vCAST_LAST_VAL :
          case vCAST_POS_INF_VAL :
          case vCAST_NEG_INF_VAL :
          case vCAST_NAN_VAL :
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
            memset((void*)*vcast_param, 0x0, VCAST_TI_9_12_array_size*(sizeof(unsigned long )));
            ;
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
/* A pointer */
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
          case vCAST_PRINT :
            vectorcast_fprint_string(vCAST_OUTPUT_FILE,"0\n");
          case vCAST_FIRST_VAL :
          case vCAST_LAST_VAL :
          case vCAST_POS_INF_VAL :
          case vCAST_NEG_INF_VAL :
          case vCAST_NAN_VAL :
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
            memset((void*)*vcast_param, 0x0, VCAST_TI_9_21_array_size*(sizeof(struct OsAppConfigType_T )));
            ;
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
/* A pointer */
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
          case vCAST_PRINT :
            vectorcast_fprint_string(vCAST_OUTPUT_FILE,"0\n");
          case vCAST_FIRST_VAL :
          case vCAST_LAST_VAL :
          case vCAST_POS_INF_VAL :
          case vCAST_NEG_INF_VAL :
          case vCAST_NAN_VAL :
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
            memset((void*)*vcast_param, 0x0, VCAST_TI_9_31_array_size*(sizeof(OsTaskParamType )));
            ;
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
/* A pointer */
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
          case vCAST_PRINT :
            vectorcast_fprint_string(vCAST_OUTPUT_FILE,"0\n");
          case vCAST_FIRST_VAL :
          case vCAST_LAST_VAL :
          case vCAST_POS_INF_VAL :
          case vCAST_NEG_INF_VAL :
          case vCAST_NAN_VAL :
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
            memset((void*)*vcast_param, 0x0, VCAST_TI_9_19_array_size*(sizeof(struct OsAppConfigType_T )));
            ;
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
/* A struct */
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
/* A typedef */
void VCAST_TI_9_30 ( OsTaskParamType *vcast_param )
{
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
} /* end VCAST_TI_9_30 */
/* A pointer */
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
          case vCAST_PRINT :
            vectorcast_fprint_string(vCAST_OUTPUT_FILE,"0\n");
          case vCAST_FIRST_VAL :
          case vCAST_LAST_VAL :
          case vCAST_POS_INF_VAL :
          case vCAST_NEG_INF_VAL :
          case vCAST_NAN_VAL :
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
            memset((void*)*vcast_param, 0x0, VCAST_TI_9_20_array_size*(sizeof(struct OsCoreConfigType_T )));
            ;
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
/* A pointer */
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
          case vCAST_PRINT :
            vectorcast_fprint_string(vCAST_OUTPUT_FILE,"0\n");
          case vCAST_FIRST_VAL :
          case vCAST_LAST_VAL :
          case vCAST_POS_INF_VAL :
          case vCAST_NEG_INF_VAL :
          case vCAST_NAN_VAL :
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
            memset((void*)*vcast_param, 0x0, VCAST_TI_9_17_array_size*(sizeof(OsHookConfigType )));
            ;
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
/* A struct */
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
/* A typedef */
void VCAST_TI_9_16 ( OsHookConfigType *vcast_param )
{
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
} /* end VCAST_TI_9_16 */
/* A pointer */
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
          case vCAST_PRINT :
            vectorcast_fprint_string(vCAST_OUTPUT_FILE,"0\n");
          case vCAST_FIRST_VAL :
          case vCAST_LAST_VAL :
          case vCAST_POS_INF_VAL :
          case vCAST_NEG_INF_VAL :
          case vCAST_NAN_VAL :
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
            memset((void*)*vcast_param, 0x0, VCAST_TI_9_26_array_size*(sizeof(OsCoreSysConfigType )));
            ;
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
/* A pointer */
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
/* A typedef */
void VCAST_TI_9_28 ( OsCoreSysConfigType *vcast_param )
{
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
} /* end VCAST_TI_9_28 */
void VCAST_TI_RANGE_DATA_9 ( void ) {
  /* Range Data for TI (array) VCAST_TI_9_1 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100003\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,21U);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (scalar) VCAST_TI_9_3 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_SCALAR\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"900003\n" );
  vectorcast_fprint_unsigned_long_long (vCAST_OUTPUT_FILE,0 );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_unsigned_long_long (vCAST_OUTPUT_FILE,(
                                                          (2ULL * 9223372036854775807LL + 1) 
                                                                     / 2) );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_unsigned_long_long (vCAST_OUTPUT_FILE,
                                                         (2ULL * 9223372036854775807LL + 1) 
                                                                    );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  /* Range Data for TI (scalar) VCAST_TI_9_6 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_SCALAR\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"900006\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,0 );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,(0 / 2) + (
                                                                 255 
                                                                           / 2) );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,
                                              255 
                                                        );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  /* Range Data for TI (scalar) VCAST_TI_9_7 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_SCALAR\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"900007\n" );
  vectorcast_fprint_unsigned_short (vCAST_OUTPUT_FILE,0 );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_unsigned_short (vCAST_OUTPUT_FILE,(0 / 2) + (
                                                                        0xFFFF 
                                                                                  / 2) );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_unsigned_short (vCAST_OUTPUT_FILE,
                                                     0xFFFF 
                                                               );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  /* Range Data for TI (scalar) VCAST_TI_9_8 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_SCALAR\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"900008\n" );
  vectorcast_fprint_unsigned_long (vCAST_OUTPUT_FILE,0 );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_unsigned_long (vCAST_OUTPUT_FILE,(0 / 2) + (
                                                                       0xFFFFFFFFUL 
                                                                                 / 2) );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_unsigned_long (vCAST_OUTPUT_FILE,
                                                    0xFFFFFFFFUL 
                                                              );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
}
/* Include the file which contains function implementations
for stub processing and value/expected user code */
/*vcast_header_expansion_start:OsEvent_uc.c*/
void vCAST_VALUE_USER_CODE_9(int vcast_slot_index ) {
  {
  /* INSERT VALUE_USER_CODE_9 */
  }
}
void vCAST_EXPECTED_USER_CODE_9(int vcast_slot_index ) {
  {
  /* INSERT EXPECTED_USER_CODE_9 */
  }
}
void vCAST_EGLOBALS_USER_CODE_9(int vcast_slot_index ) {
  {
  /* INSERT EXPECTED_GLOBALS_USER_CODE_9 */
  }
}
void vCAST_STUB_PROCESSING_9(
        int UnitIndex,
        int SubprogramIndex ) {
  vCAST_GLOBAL_STUB_PROCESSING();
  {
  /* INSERT STUB_VAL_USER_CODE_9 */
  }
}
void vCAST_BEGIN_STUB_PROC_9(
        int UnitIndex,
        int SubprogramIndex ) {
  vCAST_GLOBAL_BEGINNING_OF_STUB_PROCESSING();
  {
  /* INSERT STUB_EXP_USER_CODE_9 */
  }
}
void VCAST_USER_CODE_UNIT_9( VCAST_USER_CODE_TYPE uct, int vcast_slot_index ) {
  switch( uct ) {
    case VCAST_UCT_VALUE:
      vCAST_VALUE_USER_CODE_9(vcast_slot_index);
      break;
    case VCAST_UCT_EXPECTED:
      vCAST_EXPECTED_USER_CODE_9(vcast_slot_index);
      break;
    case VCAST_UCT_EXPECTED_GLOBALS:
      vCAST_EGLOBALS_USER_CODE_9(vcast_slot_index);
      break;
  } /* switch( uct ) */
}
/*vcast_header_expansion_end*/
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
/*vcast_separate_expansion_end*/
