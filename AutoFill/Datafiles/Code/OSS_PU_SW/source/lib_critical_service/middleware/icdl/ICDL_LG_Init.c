/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/icdl/ICDL_LG_public.h"
#include "libtools/memory/LIB_MEM_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

boolean_t ICDL_LG_Init(void)
{
   /* Local variables definition */
   boolean_t v_InitSucceeded;

   /* Local variables initialization */
   v_InitSucceeded = FALSE;

   LIB_MEM_CPY( (int8_t * const)command_list,
                (int8_t const * const)c_command_list,
                (uint32_t)(sizeof(c_command_list)) );
   LIB_MEM_CPY( (int8_t * const)command_descriptor,
                (int8_t const * const)c_command_descriptor,
                (uint32_t)(sizeof(c_command_descriptor)) );


   {
      uint32_t v_ChannelIdIndex;
      for (v_ChannelIdIndex = 0; v_ChannelIdIndex < K_MAX_NB_CHANNEL; v_ChannelIdIndex = v_ChannelIdIndex + 1)
      {
         /**Initialize channels*/
         v_InitSucceeded = ICDL_LG_InitializeChannel(v_ChannelIdIndex);
      }
   }

   /**Initialize without any elected functional frames (in Tx) */
   p_ElectedFFInTransmission = NULL;

   return v_InitSucceeded;
}

/* ---------- internal operation bodies: ------------------------------------ */
