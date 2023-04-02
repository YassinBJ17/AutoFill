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

boolean_t ICDL_LG_PrepareTxChannel(t_command *p_command_ptr)
{

   uint32_t   v_channel_id = 0;
   boolean_t  v_CmdAccepted = FALSE;

   /*
    * Retrieve a free channel that can take the command
    */
   boolean_t v_FreeChannel = ICDL_LG_GetFreeChannelID(&v_channel_id);

   if ( (TRUE == v_FreeChannel) && (NULL != p_command_ptr->st_descriptor) )
   {
      p_command_ptr->u32_channel_id = v_channel_id;

      ICDL_LG_SetUDPPorts(v_channel_id, p_command_ptr->st_descriptor->ethUdpInfo.s_SrcPort, p_command_ptr->st_descriptor->ethUdpInfo.s_DstPort);
      ICDL_LG_SetCmdType(v_channel_id, (uint32_t)p_command_ptr->st_descriptor->s_CmdCharacteristics.u16_Command);
      ICDL_LG_FillChannelFirstFunctionnalWord(v_channel_id, &(p_command_ptr->st_descriptor->s_CmdCharacteristics), p_command_ptr->udpBuffer.s_buffer_size);
      ICDL_LG_GetChannelArgDataBuffer(p_command_ptr->u32_channel_id, &(uint8_t *)p_command_ptr->udpBuffer.s_buffer);

      if ( NULL != p_command_ptr->udpBuffer.s_buffer )
         v_CmdAccepted = TRUE ;
      else
         v_CmdAccepted = FALSE ;
   }
   return v_CmdAccepted ;
}
