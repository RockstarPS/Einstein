/************************************************************************/
/*               (C) Fujitsu Semiconductor Europe GmbH (FSEU)           */
/*                                                                      */
/* The following software deliverable is intended for and must only be  */
/* used for reference and in an evaluation laboratory environment.      */
/* It is provided on an as-is basis without charge and is subject to    */
/* alterations.                                                         */
/* It is the user's obligation to fully test the software in its        */
/* environment and to ensure proper functionality, qualification and    */
/* compliance with component specifications.                            */
/*                                                                      */
/* In the event the software deliverable includes the use of open       */
/* source components, the provisions of the governing open source       */
/* license agreement shall apply with respect to such software          */
/* deliverable.                                                         */
/* FSEU does not warrant that the deliverables do not infringe any      */
/* third party intellectual property right (IPR). In the event that     */
/* the deliverables infringe a third party IPR it is the sole           */
/* responsibility of the customer to obtain necessary licenses to       */
/* continue the usage of the deliverable.                               */
/*                                                                      */
/* To the maximum extent permitted by applicable law FSEU disclaims all */
/* warranties, whether express or implied, in particular, but not       */
/* limited to, warranties of merchantability and fitness for a          */
/* particular purpose for which the deliverable is not designated.      */
/*                                                                      */
/* To the maximum extent permitted by applicable law, FSEU's liability  */
/* is restricted to intentional misconduct and gross negligence.        */
/* FSEU is not liable for consequential damages.                        */
/*                                                                      */
/* (V1.5)                                                               */
/************************************************************************/

/*!
 * \author      Fujitsu GCC Neuried
 * \version     0.01
 * \date        2010
 * \file        util_math.h
 * \brief       Mathematical utility functions
 *
 *
 * \attention  THIS SAMPLE CODE IS PROVIDED AS IS.
 *             FUJITSU SEMICONDUCTOR ACCEPTS NO RESPONSIBILITY OR LIABILITY
 *             FOR ANY ERRORS OR OMMISSIONS.
 */


#ifndef UTIL_MATH_H
 #define UTIL_MATH_H

#ifdef __cplusplus
    extern "C"
    {
#endif

/** @addtogroup common Tutorial Utility Library
 *  @{
 **/

/*****************************************************************************/
/*** INCLUDES ****************************************************************/
/*****************************************************************************/

/*****************************************************************************/
/*** DEFINITIONS *************************************************************/
/*****************************************************************************/

/*****************************************************************************/
/*** TYPES / STRUCTURES ******************************************************/
/*****************************************************************************/

/*! Matrix for geometry operations */
typedef MM_FLOAT       Mat3x2[6];
/*! Matrix for color operations */
typedef MM_FLOAT       Mat4x3[12];

/*****************************************************************************/
/*** FUNCTIONS ***************************************************************/
/*****************************************************************************/

/**
 * Copy the matrix content to a new one
 *  @param dst The destination matrix
 *  @param src The source matrix
 **/
void Mat3x2Copy(Mat3x2 dst, const Mat3x2 src);

/**
 * Multiply 2 matrices
 * The resulting matrix represents dst = src1 * src2
 *  @param dst The destination matrix
 *  @param src1 The first source matrix
 *  @param src2 The second source matrix
 **/
void Mat3x2Multiply(Mat3x2 dst, const Mat3x2 src1, const Mat3x2 src2);

/**
 * Reset the matrix content to a uniform matrix
 *  @param m The matrix to modify
 **/
void Mat3x2LoadIdentity(Mat3x2 m);

/**
 * Modify a matrix to realize a move operation
 * The resulting matrix represents m = m * m_trans
 *  @param m The matrix to modify
 *  @param x Move dimension in x direction
 *  @param y Move dimension in y direction
 **/
void Mat3x2Translate(Mat3x2 m, MM_FLOAT x, MM_FLOAT y);

/**
 * Modify a matrix by pre-multiplying a move matrix
 * The resulting matrix represents m = m_trans * m
 *  @param m The matrix to modify
 *  @param x Move dimension in x direction
 *  @param y Move dimension in y direction
 **/
void Mat3x2TranslatePre(Mat3x2 m, MM_FLOAT x, MM_FLOAT y);

/**
 * Modify a matrix to realize a scale operation
 * The resulting matrix represents m = m * m_scale
 *  @param m The matrix to modify
 *  @param x Scale factor in x direction
 *  @param y Scale factor in y direction
 **/
void Mat3x2Scale(Mat3x2 m, MM_FLOAT x, MM_FLOAT y);

/**
 * Modify a matrix by pre-multiplying a scale matrix
 * The resulting matrix represents m = m_scale * m
 *  @param m The matrix to modify
 *  @param x Scale factor in x direction
 *  @param y Scale factor in y direction
 **/
void Mat3x2ScalePre(Mat3x2 m, MM_FLOAT x, MM_FLOAT y);

/**
 * Modify a matrix to realize a rotation
 * The resulting matrix represents m = m * m_rot
 *  @param m The matrix to modify
 *  @param f Rotation angle in degrees
 **/
void Mat3x2Rot(Mat3x2 m, MM_FLOAT f);

/**
 * Modify a matrix by pre-multiplying a rotation matrix
 * The resulting matrix represents m = m_rot * m
 *  @param m The matrix to modify
 *  @param f Rotation angle in degrees
 **/
void Mat3x2RotPre(Mat3x2 m, MM_FLOAT f);

/**
 * Calculate the inverted matrix
 *  @param m The matrix to modify
 *  @return MML_OK on success,\n
 *          otherwise the related error code\n
 **/

#ifdef __cplusplus
    }
#endif

#endif /* UTIL_MATH_H */
