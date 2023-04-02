/***********************************************************************************************************************
 *
 *                                                Sagem Defense Securite
 *                                                     SAFRAN Group
 *
 * _BEGIN_FILE_HEADER --------------------------------------------------------------------------------------------------
 *
 * File name  : LIB_MATH_Casts.h
 * CSC name   : LIBMATH
 * 
 * Description: This file contains functions used for casts from or to 64 bits integers.
 *
 * Configuration management identification:
 *    %full_name: sknNEXT#1/incl/LIBBSP_MATH.h/1 %
 *    Creation  : galan on Tue Jul  9 10:51:15 2011
 *
 * _END_FILE_HEADER ----------------------------------------------------------------------------------------------------
 *
 * LANGUAGE: C - Header file
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * Copyright (c) 2009,2010,2011 SAGEM DS
 * SAGEM Defense Securite document. Reproduction and disclosure forbidden.
 **********************************************************************************************************************/

#ifndef _LIBBSP_MATH_H_
#define _LIBBSP_MATH_H_

/* _BEGIN_INCLUDE ========================================== INCLUDE FILES ========================================== */
#include "LIBMCP_Types.h"
/* _END_INCLUDE ===================================================================================================== */

/* _BEGIN_MACRO ================================================ MACROS ============================================= */
/* _END_MACRO ======================================================================================================= */

/* _BEGIN_TYPE ================================================== TYPES ============================================= */
/* _END_TYPE ======================================================================================================== */

/* _BEGIN_CONSTANT ============================================ CONSTANTS =========================================== */
/* _END_CONSTANT ==================================================================================================== */

/* _BEGIN_VARIABLE ========================================= GLOBAL VARIABLES ======================================= */
/* _END_VARIABLE ==================================================================================================== */

/* _BEGIN_EXTERN_PROTO ==================================== FUNCTION PROTOTYPES ===================================== */


/* _BEGIN_SERVICE=========================================== LIBBSP_MATH_ConvertUInt64ToFloat64 ======================== */
/* _BEGIN_DESCRIPTION ================================================== DESCRIPTION =================================*/
/* Description: Return double representation of a 64bits unsigned integer                                             */
/* Parameter(s):                                                                                                      */
/* const uint64_t   ( IN )  v_Value_UInt64                : Data to cast                                               */
/* float64_t* const ( OUT ) pa_Value_Float64              : Data casted                                                */
/* Returned type                                         : void                                                       */
/* _END_DESCRIPTION ================================================================================================= */

/* _BEGIN_PRECONDITION ======================= PRECONDITION FOR THIS SERVICE ======================================== */
/* None                                                                                                               */
/* _END_PRECONDITION ================================================================================================ */
/* {{RELAX<SP.006> Justification can be found in RFC d100#33146 */
extern float64_t LIBBSP_MATH_ConvertUInt64ToFloat64  ( const uint64_t          /* IN  */ v_Value_UInt64);
                                                     
                                                     
/* }}RELAX<SP.006> Justification can be found in RFC d100#33146 */
/* _END_EXTERN_PROTO ================================================================================================ */

/* _BEGIN_SERVICE=========================================== LIBBSP_MATH_ConvertUInt64ToFloat64 ======================== */
                                              
                                              
                                              
                                              
                                              
/* _BEGIN_SERVICE=========================================== LIBBSP_MATH_ConvertUInt64ToFloat32 ======================== */
/* _BEGIN_DESCRIPTION ================================================== DESCRIPTION =================================*/
/* Description: Return float representation of a 64bits unsigned integer                                              */
/* Parameter(s):                                                                                                      */
/* const uint64_t   ( IN )  v_Value_UInt64                : Data to cast                                               */
/* float32_t* const ( OUT ) pa_Value_Float32              : Data casted                                                */
/* Returned type                                         : void                                                       */
/* _END_DESCRIPTION ================================================================================================= */

/* _BEGIN_PRECONDITION ======================= PRECONDITION FOR THIS SERVICE ======================================== */
/* None                                                                                                               */
/* _END_PRECONDITION ================================================================================================ */
/* {{RELAX<SP.006> Justification can be found in RFC d100#33146 */
extern void LIBBSP_MATH_ConvertUInt64ToFloat32  ( const uint64_t          /* IN  */ v_Value_UInt64,
                                                     float32_t * const /* OUT */ pa_Value_Float32);
/* }}RELAX<SP.006> Justification can be found in RFC d100#33146 */
/* _END_EXTERN_PROTO ================================================================================================ */

/* _BEGIN_SERVICE=========================================== LIBBSP_MATH_ConvertUInt64ToFloat32 ======================== */
                                              
                                              
                                              
                                              
                                              
/* _BEGIN_SERVICE=========================================== LIBBSP_MATH_ConvertFloat64ToInt64 ========================= */
/* _BEGIN_DESCRIPTION ================================================== DESCRIPTION =================================*/
/* Description: Return 64bits signed integer representation of a double                                               */
/* Parameter(s):                                                                                                      */
/* const uint64_t   ( IN )  v_Value_Float64               : Data to cast                                               */
/* int64_t* const ( OUT ) pa_Value_Int64                : Data casted                                                */
/* Returned type                                         : void                                                       */
/* _END_DESCRIPTION ================================================================================================= */

/* _BEGIN_PRECONDITION ======================= PRECONDITION FOR THIS SERVICE ======================================== */
/* None                                                                                                               */
/* _END_PRECONDITION ================================================================================================ */
/* {{RELAX<SP.006> Justification can be found in RFC d100#33146 */
extern void LIBBSP_MATH_ConvertFloat64ToInt64 ( const float64_t        /* IN  */ v_Value_Float64,
                                                   int64_t  * const /* OUT */ pa_Value_Int64);
/* }}RELAX<SP.006> Justification can be found in RFC d100#33146 */
/* _END_EXTERN_PROTO ================================================================================================ */

/* _BEGIN_SERVICE=========================================== LIB_MATH_ConvertFloat64ToInt64 ========================= */
                                              
                                              
                                              
                                              
                                              
/* _BEGIN_SERVICE=========================================== LIBBSP_MATH_ConvertFloat64ToUInt64 ======================== */
/* _BEGIN_DESCRIPTION ================================================== DESCRIPTION =================================*/
/* Description: Return 64bits unsigned integer representation of a double                                             */
/* Parameter(s):                                                                                                      */
/* const uint64_t   ( IN )  v_Value_Float64               : Data to cast                                               */
/* float64_t* const ( OUT ) pa_Value_UInt64               : Data casted                                                */
/* Returned type                                         : void                                                       */
/* _END_DESCRIPTION ================================================================================================= */

/* _BEGIN_PRECONDITION ======================= PRECONDITION FOR THIS SERVICE ======================================== */
/* None                                                                                                               */
/* _END_PRECONDITION ================================================================================================ */
/* {{RELAX<SP.006> Justification can be found in RFC d100#33146 */
extern void LIBBSP_MATH_ConvertFloat64ToUInt64  ( const float64_t         /* IN  */ v_Value_Float64,
                                                     uint64_t  * const /* OUT */ pa_Value_UInt64);
/* }}RELAX<SP.006> Justification can be found in RFC d100#33146 */
/* _END_EXTERN_PROTO ================================================================================================ */


/* _BEGIN_SERVICE=========================================== LIBBSP_MATH_BZero ======================== */
/* _BEGIN_DESCRIPTION ================================================== DESCRIPTION =================================*/
/* Description: set 0 in the address Dest to Dest+N_Bytes                                           */
/* Parameter(s):                                                                                                      */
/* void *const  ( IN/OUT )  Dest               : start address to zeroize                                               */
/* const uint32_t ( IN ) N_Bytes          : number of bytes to set to 0                                                */
/* Returned type                                         : void                                                       */
/* _END_DESCRIPTION ================================================================================================= */

/* _BEGIN_PRECONDITION ======================= PRECONDITION FOR THIS SERVICE ======================================== */
/* None                                                                                                               */
/* _END_PRECONDITION ================================================================================================ */
void	LIBBSP_MATH_BZero(       void   /* IN/OUT */  *const Dest,  const uint32_t /* IN */         N_Bytes);
/* _END_EXTERN_PROTO ================================================================================================ */

#endif /* _LIBBSP_MATH_CASTS_H_ */
