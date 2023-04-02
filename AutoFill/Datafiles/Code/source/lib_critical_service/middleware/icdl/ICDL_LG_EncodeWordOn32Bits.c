/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/icdl/ICDL_LG_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
uint32_t ICDL_LG_EncodeWordOn32Bits(uint32_t p_initial_value, uint32_t p_value_to_encode, uint32_t p_offset, uint32_t p_mask)
{
   /** @brief Clear bits of initial_value where the value is to be encoded */
   p_initial_value = (~p_mask) & p_initial_value;

   {
      /** Shift left the value to encode by the given offset (in bits) where it is to be placed in the initial value*/
      uint32_t v_part_to_add = p_value_to_encode << p_offset ;

      /** Apply the mask to the shifted value to keep only the useful bits */
      v_part_to_add = p_mask & v_part_to_add ;

      /** Insert the useful bits in the initial value */
      p_initial_value = (p_initial_value | v_part_to_add) ;
   }

   /** Return the encoded word*/
   return p_initial_value ;
}

/* ---------- internal operation bodies: ------------------------------------ */
