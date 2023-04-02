/***********************************************************************************************************************
 *
 *                                                Sagem Defense Securite
 *                                                     SAFRAN Group
 *
 * _BEGIN_FILE_HEADER --------------------------------------------------------------------------------------------------
 *
 * File name  : LIBBSP_MATH_Casts.c
 * CSC name   : LIBBSP_MATH
 * 
 * Description: This file contains functions used for casts from or to 64 bits integers.
 *
 * Configuration management identification:
 *    %full_name: sknNEXT#1/csrc/LIBBSP_MATH_Casts.c/4 %
 *    Creation  : gt077945 on Mon Jul 25 13:11:41 2011
 *
 * _END_FILE_HEADER ----------------------------------------------------------------------------------------------------
 *
 * LANGUAGE: C - Source file
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * Copyright (c) 2009,2010,2011 SAGEM DS
 * SAGEM Defense Securite document. Reproduction and disclosure forbidden.
 **********************************************************************************************************************/

/* _BEGIN_INCLUDE ========================================== INCLUDE FILES ========================================== */
#include "LIBBSP_MATH_Casts.h"
/* _END_INCLUDE ===================================================================================================== */

/* _BEGIN_TYPE_CONSTANT ========== CONSTANTS FOR TYPES  ============================================================= */

/* _END_TYPE_CONSTANT =============================================================================================== */

/* _BEGIN_TYPE =====================  TYPES  ======================================================================== */

/* _END_TYPE ======================================================================================================== */

/* _BEGIN_CONSTANT ===============  CONSTANTS  ====================================================================== */

/* _END_CONSTANT ==================================================================================================== */

/* _BEGIN_MACRO ===================  MACROS  ======================================================================== */

/* _END_MACRO ======================================================================================================= */

/* _BEGIN_STATIC_PROTO ====  STATIC FUNCTIONS DECLARATIONS  ========================================================= */

/* _END_STATIC_PROTO ================================================================================================ */

/* _BEGIN_VARIABLE =============  STATIC VARIABLES  ================================================================= */

/* _END_VARIABLE ==================================================================================================== */

/* _BEGIN_STATIC_FUNCTION ====  STATIC FUNCTIONS DEFINITIONS  ======================================================= */

/* _END_STATIC_FUNCTION ============================================================================================= */

/* _BEGIN_VARIABLE =============  GLOBAL VARIABLES  ================================================================= */

/* _END_VARIABLE ==================================================================================================== */

/* _BEGIN_EXTERN_FUNCTION ========EXTERN FUNCTIONS DEFINITIONS  ===================================================== */

/* BEGIN FUNCTION HEADER--------------------------------------------------------------------------------------------- */
/* <<LLR:  >>  PUID                                                                                                   */
/*                                                                                                                    */
/* <<FUNCTION:  >> LIBBSP_MATH_ConvertUInt64ToFloat64                                                                    */
/*                                                                                                                    */
/* <<BRIEF:  >> Return double representation of a 64bits unsigned integer                                             */
/*                                                                                                                    */
/* <<DESCRIPTION:  >> This function computes the cast of a uint64_t data into float64_t data.                           */
/*                                                                                                                    */
/* <<RETURNED TYPE:  >>  void                                                                                         */
/*                                                                                                                    */
/* <<PARAMETERS:  >>  v_Value_UInt64 : (IN) of type uint64_t                                                           */
/*                    v_Float64 : (OUT) of type float64_t*                                                      */
/*                                                                                                                    */
/* <<GLOBALS Inputs:  >>  None                                                                                        */
/*                                                                                                                    */
/* <<GLOBALS Outputs:  >>  None                                                                                       */
/*                                                                                                                    */
/* <<CALLS:  >>  None                                                                                                 */
/*                                                                                                                    */
/* <<EXTERNAL CALLS:  >>  None                                                                                        */
/*                                                                                                                    */
/* <<PRECONDITIONS:  >>  None                                                                                         */
/*                                                                                                                    */
/* END FUNCTION HEADER----------------------------------------------------------------------------------------------- */
/* {{RELAX<SYNCHRONe_C_Code_10.3, SYNCHRONe_C_Code_10.7> part of cast functions so possible loss of precision is known */
float64_t LIBBSP_MATH_ConvertUInt64ToFloat64  ( const uint64_t          /* IN  */ v_Value_UInt64)
{
   /*-------------------*/
   /* LOCAL DATA :      */
   /*-------------------*/
   
   uint32_t  v_MSBUInt32;
   uint32_t  v_LSBUInt32;
   uint64_t  v_MSBUInt64;
   uint64_t  v_LSBUInt64;
   float64_t v_MSBFloat64;
   float64_t v_Float64;
   
   /*-------------------*/
   /* BODY :            */
   /*-------------------*/
   
   v_MSBUInt64 = v_Value_UInt64 & C_LIBMATH_CONST_32_BITS_MSB_MASK;
   v_MSBUInt64 = v_MSBUInt64 >> C_LIBMATH_CONST_NB_BIT_WORD32;
   
   v_MSBUInt32 = (uint32_t)v_MSBUInt64;
   
   v_MSBFloat64 = (float64_t)v_MSBUInt32;
   v_MSBFloat64 =  v_MSBFloat64 * C_LIBMATH_CONST_FL64_2EXP32;
   
   v_LSBUInt64 = v_Value_UInt64 & C_LIBMATH_CONST_32_BITS_LSB_MASK;
   
   v_LSBUInt32 = (uint32_t)v_LSBUInt64;
   
   v_Float64 = v_MSBFloat64 + ((float64_t)v_LSBUInt32);
   
   return v_Float64;
}


/* BEGIN FUNCTION HEADER--------------------------------------------------------------------------------------------- */
/* <<LLR:  >>  PUID                                                                                                   */
/*                                                                                                                    */
/* <<FUNCTION:  >> LIBBSP_MATH_ConvertUInt64ToFloat32                                                                    */
/*                                                                                                                    */
/* <<BRIEF:  >> Return float representation of a 64bits unsigned integer                                              */
/*                                                                                                                    */
/* <<DESCRIPTION:  >> This function computes the cast of a uint64_t data into float32_t data.                           */
/*                                                                                                                    */
/* <<RETURNED TYPE:  >>  void                                                                                         */
/*                                                                                                                    */
/* <<PARAMETERS:  >>  v_Value_UInt64 : (IN) of type uint64_t                                                           */
/*                    pa_Value_Float32 : (OUT) of type float32_t*                                                      */
/*                                                                                                                    */
/* <<GLOBALS Inputs:  >>  None                                                                                        */
/*                                                                                                                    */
/* <<GLOBALS Outputs:  >>  None                                                                                       */
/*                                                                                                                    */
/* <<CALLS:  >>  None                                                                                                 */
/*                                                                                                                    */
/* <<EXTERNAL CALLS:  >>  None                                                                                        */
/*                                                                                                                    */
/* <<PRECONDITIONS:  >>  None                                                                                         */
/*                                                                                                                    */
/* END FUNCTION HEADER----------------------------------------------------------------------------------------------- */
void LIBBSP_MATH_ConvertUInt64ToFloat32  ( const uint64_t          /* IN  */ v_Value_UInt64,
                                           float32_t * const       /* OUT */ pa_Value_Float32)
{
   /*-------------------*/
   /* LOCAL DATA :      */
   /*-------------------*/
   
   uint32_t  v_MSBUInt32;
   uint32_t  v_LSBUInt32;
   uint64_t  v_MSBUInt64;
   uint64_t  v_LSBUInt64;
   float32_t v_MSBFloat32;
   
   /*-------------------*/
   /* BODY :            */
   /*-------------------*/
   
   v_MSBUInt64 = v_Value_UInt64 & C_LIBMATH_CONST_32_BITS_MSB_MASK;
   v_MSBUInt64 = v_MSBUInt64 >> C_LIBMATH_CONST_NB_BIT_WORD32;
   
   v_MSBUInt32 = (uint32_t)v_MSBUInt64;
   
   v_MSBFloat32 = (float32_t)v_MSBUInt32;
   v_MSBFloat32 = v_MSBFloat32 * C_LIBMATH_CONST_FL32_2EXP32;
   
   v_LSBUInt64 = v_Value_UInt64 & C_LIBMATH_CONST_32_BITS_LSB_MASK;
   
   v_LSBUInt32 = (uint32_t)v_LSBUInt64;
   
   *pa_Value_Float32 = v_MSBFloat32 + ((float32_t)v_LSBUInt32);
}

/* BEGIN FUNCTION HEADER--------------------------------------------------------------------------------------------- */
/* <<LLR:  >>  PUID                                                                                                   */
/*                                                                                                                    */
/* <<FUNCTION:  >> LIBBSP_MATH_ConvertFloat64ToInt64                                                                     */
/*                                                                                                                    */
/* <<BRIEF:  >> Return 64bits signed integer representation of a double                                               */
/*                                                                                                                    */
/* <<DESCRIPTION:  >> This function computes the cast of a float64_t data into int64_t data.                            */
/*                                                                                                                    */
/* <<RETURNED TYPE:  >>  void                                                                                         */
/*                                                                                                                    */
/* <<PARAMETERS:  >>  v_Value_Float64 : (IN) of type float64_t                                                         */
/*                    pa_Value_Int64 : (OUT) of type int64_t*                                                          */
/*                                                                                                                    */
/* <<GLOBALS Inputs:  >>  None                                                                                        */
/*                                                                                                                    */
/* <<GLOBALS Outputs:  >>  None                                                                                       */
/*                                                                                                                    */
/* <<CALLS:  >>  None                                                                                                 */
/*                                                                                                                    */
/* <<EXTERNAL CALLS:  >>  None                                                                                        */
/*                                                                                                                    */
/* <<PRECONDITIONS:  >>  None                                                                                         */
/*                                                                                                                    */
/* END FUNCTION HEADER----------------------------------------------------------------------------------------------- */
void LIBBSP_MATH_ConvertFloat64ToInt64 ( const float64_t        /* IN  */ v_Value_Float64,
                                            int64_t  * const /* OUT */ pa_Value_Int64)
{
   /*-------------------*/
   /* LOCAL DATA :      */
   /*-------------------*/
   
   float64_t v_MSB;
   float64_t v_LSB;
   boolean_t v_IsNegative;
   
   int64_t v_MSBInt;
   uint64_t v_LSBInt;
   int64_t v_tempInt64;
   float64_t v_inputData;
   
   /*-------------------*/
   /* BODY :            */
   /*-------------------*/
   
   /* Check wether input float is negative or positive */
   if (v_Value_Float64 < 0.0)
   {
      v_IsNegative = TRUE;
      v_inputData = -v_Value_Float64;
   }
   else
   {
      v_IsNegative = FALSE;
      v_inputData = v_Value_Float64;
   }
   
   v_MSB = v_inputData / C_LIBMATH_CONST_FL64_2EXP32;
   
   v_LSB = v_inputData - (((float64_t)((int32_t)v_MSB)) * C_LIBMATH_CONST_FL64_2EXP32);
   
   v_MSBInt = (int64_t)((int32_t)v_MSB);
   v_LSBInt = (uint64_t)((uint32_t)v_LSB);
   
   v_tempInt64 = (int64_t)(v_MSBInt << C_LIBMATH_CONST_NB_BIT_WORD32) + (int64_t)v_LSBInt;
   
   if (v_IsNegative)
   {
      v_tempInt64 = -v_tempInt64;
   }
   
   
   *pa_Value_Int64 = v_tempInt64;
}

/* BEGIN FUNCTION HEADER--------------------------------------------------------------------------------------------- */
/* <<LLR:  >>  PUID                                                                                                   */
/*                                                                                                                    */
/* <<FUNCTION:  >> LIB_MATH_ConvertFloat64ToUInt64                                                                    */
/*                                                                                                                    */
/* <<BRIEF:  >> Return 64bits unsigned integer representation of a double                                             */
/*                                                                                                                    */
/* <<DESCRIPTION:  >> This function computes the cast of a float64_t data into uint64_t data.                           */
/*                                                                                                                    */
/* <<RETURNED TYPE:  >>  void                                                                                         */
/*                                                                                                                    */
/* <<PARAMETERS:  >>  v_Value_Float64 : (IN) of type float64_t                                                         */
/*                    pa_Value_UInt64 : (OUT) of type uint64_t*                                                        */
/*                                                                                                                    */
/* <<GLOBALS Inputs:  >>  None                                                                                        */
/*                                                                                                                    */
/* <<GLOBALS Outputs:  >>  None                                                                                       */
/*                                                                                                                    */
/* <<CALLS:  >>  None                                                                                                 */
/*                                                                                                                    */
/* <<EXTERNAL CALLS:  >>  None                                                                                        */
/*                                                                                                                    */
/* <<PRECONDITIONS:  >>  None                                                                                         */
/*                                                                                                                    */
/* END FUNCTION HEADER----------------------------------------------------------------------------------------------- */
void LIBBSP_MATH_ConvertFloat64ToUInt64  (const float64_t    /* IN  */ v_Value_Float64,
                                          uint64_t  * const  /* OUT */ pa_Value_UInt64)
{
   /*-------------------*/
   /* LOCAL DATA :      */
   /*-------------------*/
   
   float64_t v_MSB;
   float64_t v_LSB;
   
   uint32_t v_MSBUint;
   
   /*-------------------*/
   /* BODY :            */
   /*-------------------*/
   
   v_MSB = v_Value_Float64 / C_LIBMATH_CONST_FL64_2EXP32;
   
   v_LSB = v_Value_Float64 - (((float64_t)((uint32_t)v_MSB)) * C_LIBMATH_CONST_FL64_2EXP32);
   
   v_MSBUint = (uint32_t)v_MSB;
   
   *pa_Value_UInt64 =(uint64_t)((uint64_t)v_MSBUint << C_LIBMATH_CONST_NB_BIT_WORD32) + (uint64_t)((uint32_t)v_LSB);
}
/* }} RELAX<SYNCHRONe_C_Code_10.3, SYNCHRONe_C_Code_10.7> */
/* _END_EXTERN_FUNCTION ============================================================================================= */
