/* ---------- include provided interface: ----------------------------------- */
#include "LIB_MATH_public.h"

/* ---------- include required interface: ----------------------------------- */
/* LPOS Common Interface */
#include "CMN_TYPES_common.h"

/* Logical Shift Right for 64 bits */
uint64_t LIB_MATH_UDIV64_LSR64( uint64_t const p_ulong,
                                uint32_t const p_shift )
{
   uint32_t v_high , v_low , v_high_s ;
   uint64_t v_result ;

   /* >RELAX<SYNCHRONe_C_Code_10.7> the result of the extract of the 32 MSB bits is coded on 32 bits.  */
   v_high = (uint32_t) ( p_ulong >> C_32_MSB_ULL ) ;

   /* >RELAX<SYNCHRONe_C_Code_10.7> the result of the extract of the 32 LSB bits is coded on 32 bits.  */
   v_low = (uint32_t) ( p_ulong & C_MASK_32_LSB_ON_64 ) ;

   if ( p_shift >= C_32_MSB_UL )
   {
      /* TODO : CHECK algo : the result should be v_high instead of v_low. Origin code: v_result = (uint64_t)(v_low >> (p_shift - 32ul)); */

      /* >RELAX<SYNCHRONe_C_Code_10.3> the result is coded less than 32 bits. Cas is safe */
      v_result = (uint64_t) ( v_high >> ( p_shift - C_32_MSB_UL ) ) ;
   }
   else
   {
      /* first p_shift v_low bytes */
      v_low = v_low >> p_shift ;
      /* second, p_shift v_high bytes to the left to get lower bits to put in the v_low bytes */
      v_high_s = v_high << ( C_32_MSB_UL - p_shift ) ;

      v_low = v_high_s | v_low ;

      /* p_shift v_high bytes */
      v_high = v_high >> p_shift ;

      /* form the v_result */
      v_result = ( ( (uint64_t) v_high ) << C_32_MSB_ULL ) | (uint64_t) ( v_low ) ;
   }

   return ( v_result ) ;

}