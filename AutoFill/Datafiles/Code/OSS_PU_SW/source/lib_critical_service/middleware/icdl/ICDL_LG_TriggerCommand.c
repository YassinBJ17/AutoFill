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
t_command *ICDL_LG_TriggerCommand( t_command_id  p_command_id, uint16_t p_dataSize )
{
   uint16_t v_idx_cmd_list = 0;
   uint16_t v_idx_cmd = 0;
   t_command *pt_command_ptr = NULL;

   /*
    * Iterates on command list to find the right location
    */
   while ( ( v_idx_cmd_list < ICDL_NUMBER_OF_COMMAND_LIST ) &&
           ( ( p_command_id & command_list[v_idx_cmd_list].e_id ) != p_command_id ) )
   {
      ++v_idx_cmd_list;
   }

   /*
    * If location has been found, check the queue is not full
    */
   if ( v_idx_cmd_list < ICDL_NUMBER_OF_COMMAND_LIST )
   {
      while ( ( v_idx_cmd < command_list[v_idx_cmd_list].u32_commands_number ) &&
              ( command_list[v_idx_cmd_list].st_commands[v_idx_cmd].e_flag != FLAG_AVAILABLE ) )
      {
         ++v_idx_cmd;
      }

      /*
       * If there is enough space in the queue, trigs command
       */
      if ( v_idx_cmd < command_list[v_idx_cmd_list].u32_commands_number )
      {
         pt_command_ptr = &(command_list[v_idx_cmd_list].st_commands[v_idx_cmd]);
         pt_command_ptr->e_id = p_command_id;
         pt_command_ptr->e_flag = FLAG_IN_PROGRESS;
         pt_command_ptr->st_descriptor = ICDL_LG_GetCommandDescriptor(p_command_id);
         pt_command_ptr->u32_channel_id = UNDEF_CHANNEL;
         pt_command_ptr->udpBuffer.s_buffer = NULL;
         pt_command_ptr->udpBuffer.s_buffer_size = p_dataSize;
      }
   }

   return pt_command_ptr;
}
