/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

#include "libtools/checksum/LIB_CHKSUM_public.h"

void LIB_CHKSUM_32_COMPUTE(  uint32_t  const * const p_buff,
                             uint32_t   const p_buffLen,
                             uint32_t * const p_chck32)
{
   uint32_t v_i ;
   uint32_t v_length ;
   const uint32_t * c_buff32;

   *p_chck32 = 0ul ;

   /* >RELAX<SYNCHRONe_C_Code_11.1, SYNCHRONe_C_Code_10.2> Cast is under control, as the table size has been reduced as well. */
   c_buff32 = (const uint32_t  *)p_buff;
   /* >RELAX<SYNCHRONe_C_Code_7.2> litteral to convert a Byte size into a 32 Bits size. Not a magic number */
   v_length = (p_buffLen / 4ul)  ; /* the length is not a multiple of 4 */

   for ( v_i = 0ul ; v_i < v_length ; v_i++)
   {
      /* >RELAX<SYNCHRONe_C_Code_17.4> The memory area pointed by pt_buff32 can be considered as a table. */
      *p_chck32 += c_buff32[ v_i ] ;
   }
}
