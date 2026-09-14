/**
*   @file           Compiler.h
*   @implements     Compiler.h_Artifact
*   @version 3.0.0
*
*   @brief   AUTOSAR Base - SWS Compiler abstraction
*   @details The file Compiler.h provides macros for the encapsulation of definitions and
*            declarations.
*            This file contains sample code only. It is not part of the production code deliverables
*
*   @addtogroup BASE_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : IMX8
*   Dependencies         : none
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : IMX8_MCAL_3_0_0_RTM_ASR_REL_4_2_REV_0002_20191016
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2018 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Compiler_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, A function should be used in preference to a function-like
* macro. This is the compiler abstraction specified in AutoSar Specification of Compiler Abstraction.
*
* @section Compiler_h_REF_2
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and
* functions shall not be reused. Symbol required to be defined when one compiler is used.
* Requested by AutoSAR (Req. COMPILER010).
*
* @section Compiler_h_REF_3
* Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser, a constant, a
* parenthesised expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
* This is used to abstract compiler specific encapsulation of definitions and declarations
*
* @section Compiler_h_REF_4
* Violates MISRA 2004 Required Rule 19.10, In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses unless it is used as the operand of # or ##.
* This is used to abstract compiler specific encapsulation of definitions and declarations
*
* @section Compiler_h_REF_5
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters. The used compilers use more than 31 chars for identifiers.
*
* @section Compiler_h_REF_6
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* This violation is due to the requirement that request to have a file version check.
*/

/**
* @file         Compiler.h
* @requirements COMPILER047
*/
#ifndef COMPILER_H
#define COMPILER_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Compiler_Cfg.h"
#include "CompilerDefinition.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief  Parameters that shall be published within the compiler abstraction header file and also in
          the module's description file.
@{
*/
#define COMPILER_VENDOR_ID                      43
/*
 * @violates @ref Compiler_h_REF_5 This is required as per autosar Requirement
 * @violates @ref Compiler_h_REF_6 Violates MISRA 2004 Rule 1.4, Identifier clash
 */
#define COMPILER_AR_RELEASE_MAJOR_VERSION       4
/*
 * @violates @ref Compiler_h_REF_5 This is required as per autosar Requirement
 * @violates @ref Compiler_h_REF_6 Violates MISRA 2004 Rule 1.4, Identifier clash
 */
#define COMPILER_AR_RELEASE_MINOR_VERSION       2
/*
 * @violates @ref Compiler_h_REF_5 This is required as per autosar Requirement
 * @violates @ref Compiler_h_REF_6 Violates MISRA 2004 Rule 1.4, Identifier clash
 */
#define COMPILER_AR_RELEASE_REVISION_VERSION    2
#define COMPILER_SW_MAJOR_VERSION               3
#define COMPILER_SW_MINOR_VERSION               0
#define COMPILER_SW_PATCH_VERSION               0
/**@}*/

// added for tvii rkumar35
#if (defined ISR_NATIVE) /* to prevent double definition */
#error ISR_NATIVE already defined
#endif /* if (defined ISR_NATIVE) */

/* Deviation from MISRA-C:2004 rule 19.7 and QA-C message 3453.
   Justification: Use the same style with ISR macro defined by the AUTOSAR specification. */
/* PRQA S 3453 1 */
#define ISR_NATIVE(x)     void  x(void)

#if 0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (COMPILER_VENDOR_ID != COMPILER_VENDOR_ID_CFG_H)
    #error "Compiler.h and Compiler_Cfg.h have different vendor ids"
#endif
/* Check if current file and Compiler_Cfg.h header file are of the same Autosar version */
#if ((COMPILER_AR_RELEASE_MAJOR_VERSION != COMPILER_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (COMPILER_AR_RELEASE_MINOR_VERSION != COMPILER_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (COMPILER_AR_RELEASE_REVISION_VERSION != COMPILER_AR_RELEASE_REVISION_VERSION_CFG_H))
    #error "AutoSar Version Numbers of Compiler.h and Compiler_Cfg.h are different"
#endif
/* Check if current file and Compiler_Cfg.h header file are of the same Software version */
#if ((COMPILER_SW_MAJOR_VERSION != COMPILER_SW_MAJOR_VERSION_CFG_H) || \
     (COMPILER_SW_MINOR_VERSION != COMPILER_SW_MINOR_VERSION_CFG_H) || \
     (COMPILER_SW_PATCH_VERSION != COMPILER_SW_PATCH_VERSION_CFG_H)    \
    )
    #error "Software Version Numbers of Compiler.h and Compiler_Cfg.h are different"
#endif

#if (COMPILER_VENDOR_ID != COMPILERDEFINITION_VENDOR_ID)
    #error "Compiler.h and CompilerDefinition.h have different vendor ids"
#endif
/* Check if current file and CompilerDefinition.h header file are of the same Autosar version */
#if ((COMPILER_AR_RELEASE_MAJOR_VERSION != COMPILERDEFINITION_AR_RELEASE_MAJOR_VERSION) || \
     (COMPILER_AR_RELEASE_MINOR_VERSION != COMPILERDEFINITION_AR_RELEASE_MINOR_VERSION) || \
     (COMPILER_AR_RELEASE_REVISION_VERSION != COMPILERDEFINITION_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Compiler.h and CompilerDefinition.h are different"
#endif
/* Check if current file and CompilerDefinition.h header file are of the same Software version */
#if ((COMPILER_SW_MAJOR_VERSION != COMPILERDEFINITION_SW_MAJOR_VERSION) || \
     (COMPILER_SW_MINOR_VERSION != COMPILERDEFINITION_SW_MINOR_VERSION) || \
     (COMPILER_SW_PATCH_VERSION != COMPILERDEFINITION_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Compiler.h and CompilerDefinition.h are different"
#endif

#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
* @brief The memory class AUTOMATIC shall be provided as empty definition, used for the declaration of local pointers.
*/
#define AUTOMATIC

/**
* @brief The memory class TYPEDEF shall be provided as empty definition. This memory class shall be
*        used within type definitions, where no memory qualifier can be specified. This can be
*        necessary for defining pointer types, with e.g. P2VAR, where the macros require two
*        parameters. First parameter can be specified in the type definition (distance to the memory
*        location referenced by the pointer), but the second one (memory allocation of the pointer itself) cannot be defined at this time. Hence memory class TYPEDEF shall be applied.
*/
#define TYPEDEF

/**
* @brief The compiler abstraction shall provide the NULL_PTR define with a void pointer to zero definition.
*/
#define NULL_PTR ((void *)0)

#if (defined FAR) /* to prevent double definition */
#error FAR already defined
#endif /* if (defined FAR) */

/** \brief definition of an far memory class
 **
 ** To be used for far addresses */
#define FAR

/**************************************** Green Hills *********************************************/
#ifdef _GREENHILLS_C_IMX8_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword inline.
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define INLINE              __inline

    /**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the keyword inline in functions with "static" scope
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define LOCAL_INLINE            static __inline

    /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define INTERRUPT_FUNC      __interrupt
#endif /* #ifdef _GREENHILLS_C_IMX8_ */

/**************************************** Wind River Diab *****************************************/
#ifdef _DIABDATA_C_IMX8_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define INLINE              __inline__

    /**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define LOCAL_INLINE            static __inline__

    /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define INTERRUPT_FUNC      __interrupt__
#endif /* #ifdef _DIABDATA_C_IMX8_ */

/*************************************** CodeWarrior **********************************************/
#ifdef _CODEWARRIOR_C_IMX8_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define INLINE              inline

    /**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define LOCAL_INLINE            static inline

     /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define INTERRUPT_FUNC      __declspec(interrupt nowarn)
 #endif /* #ifdef _CODEWARRIOR_C_IMX8_ */

/*************************************** Cosmic ***************************************************/
#ifdef _COSMIC_C_IMX8_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define INLINE @inline

    /**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define LOCAL_INLINE            static @inline

    /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define INTERRUPT_FUNC @interrupt
#endif /* #ifdef _COSMIC_C_IMX8_ */
/*************************************** HighTec **********************************************/
#ifdef _HITECH_C_IMX8_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define INLINE              __inline

/**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
*/
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define LOCAL_INLINE            static __inline

    /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define INTERRUPT_FUNC      __attribute__((interrupt));
#endif /* #ifdef _HITECH_C_IMX8_ */

/**************************************** Gcc *********************************************/
#ifdef _GCC_C_IMX8_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    */
    /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define INLINE                  inline __attribute__((always_inline))

    /**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
    */
    /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define LOCAL_INLINE            static inline __attribute__((always_inline))

    /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    */
    /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define INTERRUPT_FUNC     
#endif /* #ifdef _GCC_C_IMX8_ */
/**************************************** DS5 *************************************************/
#ifdef _ARM_DS5_C_IMX8_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define INLINE              __forceinline

    /**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define LOCAL_INLINE            static __forceinline

    /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define INTERRUPT_FUNC
#endif /* #ifdef _ARM_DS5_C_IMX8_ */

/**************************************** IAR *************************************************/
#ifdef _IAR_C_IMX8_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define INLINE              inline

    /**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define LOCAL_INLINE            static inline

    /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define INTERRUPT_FUNC
#endif /* #ifdef _IAR_C_IMX8_ */


/**
* @brief The compiler abstraction shall define the FUNC macro for the declaration and definition of
*        functions, that ensures correct syntax of function declarations as required by a specific compiler.
* @implements FUNC_macro
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
*    a constant, a parenthesised expression
*/
/*
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define FUNC(rettype, memclass) rettype

/**
* @brief The compiler abstraction shall define the P2VAR macro for the declaration and definition of pointers in RAM, pointing to variables.
* @implements P2VAR_macro
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
*    a constant, a parenthesised expression
*/
/*
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define P2VAR(ptrtype, memclass, ptrclass) ptrtype *

/**
* @brief The compiler abstraction shall define the P2CONST macro for the declaration and definition of pointers in RAM pointing to constants.
* @implements P2CONST_macro
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
*    a constant, a parenthesised expression
*/
/*
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define P2CONST(ptrtype, memclass, ptrclass) const ptrtype *

/**
* @brief The compiler abstraction shall define the CONSTP2VAR macro for the declaration and definition of constant pointers accessing variables.
* @implements CONSTP2VAR_macro
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
*    a constant, a parenthesised expression
*/
/*
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype * const

/**
* @brief The compiler abstraction shall define the CONSTP2CONST macro for the declaration and definition of constant pointers accessing constants.
* @implements CONSTP2CONST_macro
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
*    a constant, a parenthesised expression
*/
/*
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define CONSTP2CONST(ptrtype, memclass, ptrclass) const ptrtype * const

/**
* @brief The compiler abstraction shall define the P2FUNC macro for the type definition of pointers to functions.
* @implements P2FUNC_macro
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
*    a constant, a parenthesised expression
*/
/*
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define P2FUNC(rettype, ptrclass, fctname) rettype (*fctname)

/**
* @brief The compiler abstraction shall define the CONST macro for the declaration and definition of constants.
* @implements CONST_macro
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
*    a constant, a parenthesised expression
*/
/*
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define CONST(consttype, memclass) const consttype

/**
* @brief The compiler abstraction shall define the VAR macro for the declaration and definition of variables.
* @implements VAR_macro
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
*    a constant, a parenthesised expression
*/
/*
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define VAR(vartype, memclass) vartype

/**
* @brief The compiler abstraction for const pointer to function.
* @implements CONSTP2FUNC_macro
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in preference to a function-like macro.
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a parameter shall be enclosed in parentheses
*/
#define CONSTP2FUNC(rettype, ptrclass, fctname) rettype (* const fctname)


/**
* @brief The compiler abstraction shall define the FUNC_P2CONST macro for the declaration and definition of functions returning a pointer to a constant
* @implements FUNC_P2CONST_macro
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in preference to a function-like macro.
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a parameter shall be enclosed in parentheses
*/
#define FUNC_P2CONST(rettype, ptrclass, memclass) const ptrclass rettype * memclass

/**
* @brief The compiler abstraction shall define the FUNC_P2VAR macro for the declaration and definition of functions returning a pointer to a variable.
* @implements FUNC_P2VAR_macro
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in preference to a function-like macro.
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a parameter shall be enclosed in parentheses
*/
#define FUNC_P2VAR(rettype, ptrclass, memclass) ptrclass rettype * memclass
 
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* #ifndef COMPILER_H */

/** @} */
