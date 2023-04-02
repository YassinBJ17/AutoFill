/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */
#include "type/common_type.h"
#include "libtools/math/LIB_MATH_public.h"


/*----------------------------------------------------------------------------*/
/* Function:   LIB_MATH_COPYSIGN                                              */
/*----------------------------------------------------------------------------*/
/* Description: Returns x with the sign of y                                  */
/*                                                                            */
/* Pre-condition:  none                                                       */
/*                                                                            */
/* Input: x : number from which the mantissa and the exponent is taken        */
/*      ex : number from which the sign is taken                              */
/* Output: none                                                               */
/* Return: v_copySign : Returns x with the sign of y                          */
/*----------------------------------------------------------------------------*/
float32_t LIB_MATH_COPYSIGN(const float32_t p_input_x, const float32_t p_input_y)
{
   /* Declarations */
   tu_CMN_BITFIELD v_x;
   tu_CMN_BITFIELD v_y;

   uint16_t    v_x_high;
   uint16_t    v_y_high;

   float32_t v_copySign;

   /* Initializations */
   v_x.u_word = p_input_x;
   v_y.u_word = p_input_y;

   /* Forget the sign of x */
   /* >RELAX<SYNCHRONe_C_Code_10.7> No loss of precision : s_HIGH_FIELD is on 16 bits  */
   v_x_high = ((uint16_t)v_x.u_word_bitfield.s_HIGH_FIELD);

   /* >RELAX<SYNCHRONe_C_Code_10.7> No loss of precision, C_MASK_BITS is on 16 bits  */
   v_x_high = ((uint16_t)v_x_high) & ( (reg16_t) C_MASK_BITS );

   /* And set the sign of y */
   /* >RELAX<SYNCHRONe_C_Code_10.7> No loss of precision, s_HIGH_FIELD is on 16 bits  */
   v_y_high = ((uint16_t)v_y.u_word_bitfield.s_HIGH_FIELD);
   /* >RELAX<SYNCHRONe_C_Code_10.7> No loss of precision, C_UINT_THRESHOLD is on 16 bits  */
   v_y_high = ((uint16_t)v_y_high) & ( (uint16_t) C_UINT_THRESHOLD );

   /* Statements */
   /* Reconstitute v_x.i.high */
   v_x.u_word_bitfield.s_HIGH_FIELD = v_x_high | v_y_high;
   v_copySign = v_x.u_word;

   return (v_copySign);
}
