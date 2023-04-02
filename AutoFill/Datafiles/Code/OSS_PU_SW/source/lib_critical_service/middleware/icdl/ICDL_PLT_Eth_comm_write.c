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
#include "middleware/stack_ip/ETH_COMM_public.h"
#include "middleware/stack_ip/ETH_IP_private.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
t_eth_comm_status ICDL_PLT_Eth_comm_write( void )
{
   boolean_t v_FuncFrameToTransmit;
   uint32_t v_ChannelId;
   uint32_t v_lch_ctrl_tx_status;

   v_FuncFrameToTransmit = ICDL_LG_SearchFuncFrameToTransmit( &v_ChannelId );

   if( ( p_ElectedFFInTransmission != NULL ) && ( TRUE == v_FuncFrameToTransmit ) )
   {
      /* IP ADDR CDM OS */
      ethUdpInfo.s_IdDest.s_IpAddress.u_IP = ETH_CFEX_CDM_OS_A_EtherAddr.u_IP;
      ETH_COMM_write( (uint8_t *)p_ElectedFFInTransmission->p_ElectedFFInfo,
                      (uint32_t)p_ElectedFFInTransmission->u32_Size,
                      (uint16_t)(p_ElectedFFInTransmission->ethUdpInfo.s_SrcPort),
                      (uint16_t)(p_ElectedFFInTransmission->ethUdpInfo.s_DstPort),
                      (uint32_t)(ETH_CFEX_CDM_OS_A_EtherAddr.u_IP),
                      &v_lch_ctrl_tx_status );

      ICDL_LG_ChangeChannelStatus( v_ChannelId, E_FF_TRANSMISSION_IN_PROGRESS );
   }
   return ETH_COMM_STATUS_OK;
}


