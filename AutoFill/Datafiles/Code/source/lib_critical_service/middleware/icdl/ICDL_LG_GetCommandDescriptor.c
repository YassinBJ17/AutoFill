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
t_command_descriptor *ICDL_LG_GetCommandDescriptor(t_command_id p_command_id)
{
  uint16_t                 v_idx_command_desc = 0;
  t_command_descriptor   * pt_cmd_descriptor = NULL;

  /*
   * Iterate on command descriptor list
   */
  while ((v_idx_command_desc < ICDL_NUMBER_OF_COMMANDS) && (command_descriptor[v_idx_command_desc].id != p_command_id))
     ++v_idx_command_desc;

  /*
   * If command identifier found, return the pointer to its descriptor
   */
  if (v_idx_command_desc < ICDL_NUMBER_OF_COMMANDS)
     pt_cmd_descriptor = &(command_descriptor[v_idx_command_desc]);

  return pt_cmd_descriptor;
}
