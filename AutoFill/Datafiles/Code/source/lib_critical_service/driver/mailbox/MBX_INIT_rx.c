/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/mailbox/MBX_CFEX_public.h"
#include "driver/mailbox/MBX_HAL_public.h"
#include "driver/mailbox/EBREAKER_HAL_public.h"
#include "driver/mailbox/MBX_REG_common.h"

/* ---------- include required interface: ----------------------------------- */
#include "driver/mailbox/MAC_ETH_HAL_public.h"
#include "libtools/memory/LIB_MEM_public.h"


/* ---------- internal define constants: ------------------------------------ */
#define K_ETH_MAX_ENET_PACKET_SIZE (1514ul)   /* Maximum packet size without FCS (from Ethernet_common.h)*/

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
void MBX_INIT_rx( CMN_IOSP_ID_t const p_mbx_fifo_conf_id )
{
   /* Local Variable Declaration */
   tu_RX_FIFO_CONFIG1_REG v_rx_fifo_config1_value;
   tu_MBX_RX_FIFO_STATUS_REG v_mbx_rx_fifo_status_reg;
   tu_RX_FIFO_CONTROL_REG v_rx_fifo_control_reg;

   v_rx_fifo_config1_value.u_R = 0;
   v_mbx_rx_fifo_status_reg.u_R = 0;

   /*
    * Configure rx fifo threshold
    * - {rx_fifo_full} is based on {rx_fifo_almost_full_threshold} as its use to store in {rx_fifo} only complete frames.
    * {rx_fifo_almost_full_threshold} must be configured to be able to store complete max sized frames.
    * Once {rx_fifo_full} is asserted and even if it remains space in the {rx_fifo} as a full sized frame can't be store, all received data is rejected.
    * The {rx_fifo_almost_full} value must include the fact that 2*32bits data are added in {rx_fifo} for each received frames,
    * it's recommended to set {rx_fifo_almost_full_threshold} at the max size of a frame + 2.
    */
   /*MBX_FIFO_RX_READ_CONFIG1 (p_mbx_fifo_conf_id , &v_rx_fifo_config1_value);
    v_rx_fifo_config1_value.u_B.s_rx_fifo_almost_full_threshold = K_ETH_MAX_ENET_PACKET_SIZE/4+2;
   MBX_FIFO_RX_WRITE_CONFIG1 (p_mbx_fifo_conf_id,&v_rx_fifo_config1_value);*/

   /*
    * Disable Reception
   */
   EBREAKER_FIFO_RX_DISABLE_SET_KEY1 ( p_mbx_fifo_conf_id );
   EBREAKER_FIFO_RX_DISABLE_SET_KEY2 ( p_mbx_fifo_conf_id );

   /*
    * Get Disable Reception Status
    */
   MBX_READ_STATUS ( p_mbx_fifo_conf_id , &v_mbx_rx_fifo_status_reg );

   /*
    * Flush rx fifo
    */
   v_rx_fifo_control_reg.u_R = 0;
   v_rx_fifo_control_reg.u_B.s_rx_fifo_flush = 1;
   MBX_FIFO_RX_WRITE_CONTROL ( p_mbx_fifo_conf_id, &v_rx_fifo_control_reg );

   /*
    * Get Flush rx fifo Status
    */
   MBX_READ_STATUS ( p_mbx_fifo_conf_id , &v_mbx_rx_fifo_status_reg );

   /*
    * Enable Reception
   */
   EBREAKER_FIFO_RX_ENABLE_SET_KEY1 ( p_mbx_fifo_conf_id );
   EBREAKER_FIFO_RX_ENABLE_SET_KEY2 ( p_mbx_fifo_conf_id );

   /*
    * Get Disable Reception Status
    */
   MBX_READ_STATUS ( p_mbx_fifo_conf_id , &v_mbx_rx_fifo_status_reg );

}

/* ---------- internal operation bodies: ------------------------------------ */
