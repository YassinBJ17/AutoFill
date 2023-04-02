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
#include "middleware/stack_ip/ETH_IP_private.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* ---------- provided define constants: ------------------------------------ */
#define K_SECU_ALERT_ACK_CMD_UDP_PORTS_SRC  49200
#define K_SECU_ALERT_ACK_CMD_UDP_PORTS_DST  49200


/* ---------- provided operation bodies: ------------------------------------ */
void ICDL_PLT_SendSecuAlertAck ( CMN_SYSTEM_ADDR_t const p_buff_addr,
                                 CMN_SYSTEM_SIZE_t const p_buff_size )

{
   t_command   *eventBlock_cmd;
   boolean_t bool_channel_prepared;

   /*
    * Check the command can be handled
    */
   eventBlock_cmd = ICDL_LG_TriggerCommand( ID_CMD_SECU_ALERT_ACK, (uint16_t)p_buff_size );

   /*
    * Set channel transmission
    */
   eventBlock_cmd->st_descriptor->ethUdpInfo.s_SrcPort = K_SECU_ALERT_ACK_CMD_UDP_PORTS_SRC;
   eventBlock_cmd->st_descriptor->ethUdpInfo.s_DstPort = K_SECU_ALERT_ACK_CMD_UDP_PORTS_DST;

   bool_channel_prepared = ICDL_LG_PrepareTxChannel( eventBlock_cmd );

   /*
    * If ICDL accepts the command
    */
   if ( ( NULL != eventBlock_cmd ) && ( bool_channel_prepared == TRUE ) )
   {
      ICDL_LG_ComputeMsgArgSet( (int8_t *)p_buff_addr, (uint32_t)p_buff_size, eventBlock_cmd );
      ICDL_LG_UpdateFFLength( eventBlock_cmd->u32_channel_id, (uint32_t)eventBlock_cmd->st_descriptor->s_CmdCharacteristics.u16_ChannelBlockLength + p_buff_size );
      ICDL_LG_ChangeChannelStatus( eventBlock_cmd->u32_channel_id, E_READY_FOR_FF_TRANSMISSION );
      ICDL_LG_RemoveCommand( eventBlock_cmd );
   }

   ICDL_PLT_Eth_comm_write();
   ICDL_PLT_Eth_SendFragmentedFrame();
}

/* ---------- internal operation bodies: ------------------------------------ */
