/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/icdl/ICDL_PLT_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/icdl/ICDL_LG_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

void ICDL_PLT_Init(void)
{
   ICDL_LG_Init();
   {
      uint16_t v_idx_cmd_list;
      uint16_t v_idx_cmd;

      for ( v_idx_cmd_list = 0; v_idx_cmd_list < ICDL_NUMBER_OF_COMMAND_LIST; ++v_idx_cmd_list )
      {
         for ( v_idx_cmd = 0; v_idx_cmd < command_list[v_idx_cmd_list].u32_commands_number; ++v_idx_cmd )
         {
            ICDL_LG_RemoveCommand( &(command_list[v_idx_cmd_list].st_commands[v_idx_cmd]) );
         }
      }
   }
}
