#ifndef DmnMgr_Types_h
#define DmnMgr_Types_h "DmnMgr_Types.h"

#if !defined(STD_TYPES_H) && !defined(TYPES_H)
	typedef unsigned char uint8;
	typedef unsigned short uint16;
	#if defined(__LP64__)
		typedef unsigned int uint32;
		typedef signed int sint32;
	#else
		typedef unsigned long uint32;
		typedef signed long sint32;
	#endif
	typedef signed char sint8;
	typedef signed short sint16;
	typedef float float32;
	typedef double float64;
	typedef unsigned long long uint64;
	typedef signed long long sint64;

	typedef uint8 Std_ReturnType;
#endif
	
typedef uint8 DmnMgr_ReturnType;

#define DMNMGR_START_SEC_CONST_8
#include "MemMap.h"
///
/// @brief Requested operation completed successfully
///
#define DMNMGR_E_OK ((DmnMgr_ReturnType) 0)
///
/// @brief Requested operation failed
///
#define DMNMGR_E_NOK ((DmnMgr_ReturnType) 1)
///
#endif //DmnMgr_Types_h

#define DMNMGR_STOP_SEC_CONST_8
#include "MemMap.h"

