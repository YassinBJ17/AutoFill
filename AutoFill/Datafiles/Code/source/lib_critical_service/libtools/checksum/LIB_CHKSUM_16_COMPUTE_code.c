/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

#include "libtools/checksum/LIB_CHKSUM_public.h"

void LIB_CHKSUM_16_COMPUTE( uint8_t const * const p_buff,
                            uint16_t const p_nb_bytes,
                            uint16_t * const p_chck16 )
{
   uint16_t * pt_checksum;
   uint16_t v_nb_16_bytes_word;
   uint32_t v_i;


   *p_chck16 = (uint16_t) 0 ;

   /* Initialize the checksum value */
   /* >RELAX<SYNCHRONe_C_Code_11.1> there is no loss of data. the cast is done intentionally  */
   pt_checksum = (uint16_t *) p_buff;
   /* >RELAX<SYNCHRONe_C_Code_7.2> litteral to convert a Byte size into a 16 Bits size. Not a magic number */
   v_nb_16_bytes_word = (p_nb_bytes / (uint16_t) 2) ;

   /* Loop over words in the buffer */
   for ( v_i = 0ul ; v_i < (uint32_t) v_nb_16_bytes_word ; v_i++)
   {
      /* >RELAX<SYNCHRONe_C_Code_17.4> The memory area pointed by pt_buff32 can be considered as a table. */
      *p_chck16 += pt_checksum[ v_i ] ;
   }

}
