/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Mailbox ETH init function
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
void MBX_INIT_tx( CMN_IOSP_ID_t const p_mbx_fifo_conf_id )
{
   /* Local Variable Declaration */
   /*tu_TX_FIFO_CONFIG_REG v_tx_fifo_config_value;*/
   tu_MBX_TX_FIFO_STATUS_REG v_tx_fifo_status_value;
   tu_MBX_TX_CMD_FIFO_STATUS_REG v_tx_cmd_fifo_status_value;
   tu_TX_FIFO_CONTROL_REG v_fifo_control_value ;
   tu_TX_CMD_FIFO_CONTROL_REG v_cmd_fifo_control_value;
   tu_TX_FIFO_STATUS_ACK_REG v_tx_fifo_ack_value;
   tu_TX_CMD_FIFO_STATUS_ACK_REG v_tx_cmd_fifo_ack_value;

   /*
    * Configure tx fifo threshold
    * v_tx_fifo_config_value.u_B.s_tx_fifo_almost_empty_threshold = K_ETH_MAX_ENET_PACKET_SIZE/4+2;
    * v_tx_fifo_config_value.u_B.s_tx_fifo_almost_full_threshold = K_ETH_MAX_ENET_PACKET_SIZE/4+2;
    * MBX_FIFO_TX_WRITE_CONFIG (v_conf_ind,&v_tx_fifo_config_value);
    * MBX_FIFO_TX_READ_CONFIG (v_conf_ind , &v_tx_fifo_config_value);
    */

   /*
    * Flush tx fifo
    */
   v_fifo_control_value.u_R = 0;
   v_fifo_control_value.u_B.s_tx_fifo_flush = 1;
   MBX_FIFO_TX_WRITE_CONTROL ( p_mbx_fifo_conf_id, &v_fifo_control_value );

   /*
    * Get Flush tx fifo Status
    */
   v_tx_fifo_status_value.u_R = 0;
   MBX_FIFO_TX_READ_STATUS ( p_mbx_fifo_conf_id , &v_tx_fifo_status_value );

   /*
    * Flush tx cmd fifo
    */
   v_cmd_fifo_control_value.u_R = 0;
   v_cmd_fifo_control_value.u_B.s_tx_cmd_fifo_flush = 1;
   MBX_FIFO_TX_CMD_WRITE_CONTROL ( p_mbx_fifo_conf_id, &v_cmd_fifo_control_value );

   /*
    * Get Flush tx cmd fifo Status
    */
   v_tx_cmd_fifo_status_value.u_R = 0;
   MBX_FIFO_TX_CMD_READ_STATUS ( p_mbx_fifo_conf_id , &v_tx_cmd_fifo_status_value );

   /*
    * ACK tx fifo FLUSH
    */
   v_tx_fifo_ack_value.u_R = 0;
   v_tx_fifo_ack_value.u_B.s_tx_fifo_flush_ack = 1;
   MBX_FIFO_TX_WRITE_STATUS_ACK ( p_mbx_fifo_conf_id, &v_tx_fifo_ack_value );

   /*
    * Get Flush tx fifo Status
    */
   v_tx_fifo_status_value.u_R = 0;
   MBX_FIFO_TX_READ_STATUS ( p_mbx_fifo_conf_id , &v_tx_fifo_status_value );

   /*
    * ACK tx cmd fifo FLUSH
    */
   v_tx_cmd_fifo_ack_value.u_R = 0;
   v_tx_cmd_fifo_ack_value.u_B.s_tx_cmd_fifo_flush_ack = 1;
   MBX_FIFO_TX_CMD_WRITE_STATUS_ACK ( p_mbx_fifo_conf_id, &v_tx_cmd_fifo_ack_value );

   /*
    * Get Flush tx cmd fifo Status
    */
   v_tx_cmd_fifo_status_value.u_R = 0;
   MBX_FIFO_TX_CMD_READ_STATUS ( p_mbx_fifo_conf_id , &v_tx_cmd_fifo_status_value );


   /*
   * Disable Transmission
   */
   EBREAKER_FIFO_TX_CMD_DISABLE_SET_KEY1 ( p_mbx_fifo_conf_id );
   EBREAKER_FIFO_TX_CMD_DISABLE_SET_KEY2 ( p_mbx_fifo_conf_id );

   /*
    * Get Disable Transmission Status
    */
   MBX_FIFO_TX_CMD_READ_STATUS ( p_mbx_fifo_conf_id , &v_tx_cmd_fifo_status_value );
   /*
    * Enable Transmission
   */
   EBREAKER_FIFO_TX_CMD_ENABLE_SET_KEY1 ( p_mbx_fifo_conf_id );
   EBREAKER_FIFO_TX_CMD_ENABLE_SET_KEY2 ( p_mbx_fifo_conf_id );

   /*
    * Get Enable Transmission Status
    */
   MBX_FIFO_TX_CMD_READ_STATUS ( p_mbx_fifo_conf_id , &v_tx_cmd_fifo_status_value );

   /*
    * Get Enable Transmission Status
    */
   MBX_FIFO_TX_READ_STATUS ( p_mbx_fifo_conf_id , &v_tx_fifo_status_value );

}

/* ---------- internal operation bodies: ------------------------------------ */
