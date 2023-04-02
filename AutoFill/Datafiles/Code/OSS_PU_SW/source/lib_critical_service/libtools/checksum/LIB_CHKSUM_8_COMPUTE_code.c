/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "libtools/checksum/LIB_CHKSUM_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- provided operations: ------------------------------------------- */
void LIB_CHKSUM_8_COMPUTE( uint8_t  const * const p_buff,
                                   uint32_t   const p_buffLen,
                                   uint8_t * const p_chck8)
{
   uint32_t v_i ;

   *p_chck8 = (uint8_t) 0 ;
   for ( v_i = 0ul ; v_i < p_buffLen ; v_i++)
   {
      /* >RELAX<SYNCHRONe_C_Code_17.4> The memory area pointed by p_buff8 can be considered as a table. */
      *p_chck8 += p_buff[ v_i ] ;
   }
}
