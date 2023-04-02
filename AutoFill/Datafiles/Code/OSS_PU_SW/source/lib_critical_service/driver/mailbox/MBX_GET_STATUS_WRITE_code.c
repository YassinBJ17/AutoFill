/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : MAC ETH Tx get status write function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/mailbox/MBX_CFEX_public.h"
#include "driver/mailbox/MBX_HAL_public.h"
#include "driver/mailbox/MBX_REG_common.h"
#include "driver/mailbox/MBX_private.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
void MBX_GET_STATUS_WRITE( ts_MBX_HAL_STATS_TRANSFERT * const p_pt_stats )
{
   tu_MBX_TX_CMD_FIFO_STATUS_REG v_tx_cmd_fifo_status_value;
   tu_MBX_TX_FIFO_STATUS_REG     v_tx_fifo_status_value;

#ifdef CBIT_MBX
   tu_TX_CMD_FIFO_CONTROL_REG    v_cmd_fifo_control_value;
   tu_TX_FIFO_CONTROL_REG        v_fifo_control_value;
   tu_TX_FIFO_STATUS_ACK_REG     v_tx_ack_value;
   tu_TX_CMD_FIFO_STATUS_ACK_REG v_tx_cmd_ack_value;
#endif

   /* 1 Write for TX CMD*/
   MBX_FIFO_TX_CMD_READ_STATUS ( (CMN_IOSP_ID_t)e_CFEX_MBX_CONF_0 , &v_tx_cmd_fifo_status_value );

   /* 2 Write for TX */
   MBX_FIFO_TX_READ_STATUS ( (CMN_IOSP_ID_t)e_CFEX_MBX_CONF_0 , &v_tx_fifo_status_value );

   g_mbx_tx_status.u_B.s_tx_cmd_fifo_fifo_ovf_err = v_tx_cmd_fifo_status_value.u_B.s_tx_cmd_fifo_overflow;
   g_mbx_tx_status.u_B.s_tx_fifo_fifo_ovf_err     = v_tx_fifo_status_value.u_B.s_tx_fifo_overflow;

   /* tx fifo cmd and fifo data available */
   if ( ( v_tx_cmd_fifo_status_value.u_B.s_tx_cmd_fifo_overflow != 1 ) && ( v_tx_fifo_status_value.u_B.s_tx_fifo_overflow != 1 ) )
   {
      p_pt_stats->s_status = e_CMN_FLAG_COMPLETE ;
      p_pt_stats->s_len = 0;/*TODO -> read size en fifo ?*/
   }
   else
   {
#ifdef CBIT_MBX
      if( v_tx_fifo_status_value.u_B.s_tx_fifo_overflow == 1 )
      {
         /* 1: Remonter le flag de panne */
         cbit_mbx_status.TX_status |= v_tx_fifo_status_value.u_B.s_tx_fifo_overflow << as_return_overflow;

         /* 2: Flush de la TX FIFO CMD */
         /*
          * Flush tx fifo
          */
         v_fifo_control_value.u_R = 0;
         v_fifo_control_value.u_B.s_tx_fifo_flush = 1;
         MBX_FIFO_TX_WRITE_CONTROL ( (CMN_IOSP_ID_t)e_CFEX_MBX_CONF_0, &v_fifo_control_value );

         v_tx_ack_value.u_R = 0;
         v_tx_ack_value.u_B.s_tx_fifo_flush_ack = 1;
         MBX_FIFO_TX_WRITE_STATUS_ACK ( (CMN_IOSP_ID_t)e_CFEX_MBX_CONF_0, &v_tx_ack_value );

         /* 3: Reinit du Datagramme UDP */
         ETH_UDP_Init(); /* From ETH_UDP_Init */

          /* 4: Record the error in Log Area */
         /* TODO PAULO : No logbook available */

         /* 5: Acknowledge the status */
         v_tx_ack_value.u_R = 0;
         v_tx_ack_value.u_B.s_tx_fifo_overflow_ack = 1;
         MBX_FIFO_TX_WRITE_STATUS_ACK ( (CMN_IOSP_ID_t)e_CFEX_MBX_CONF_0, &v_tx_ack_value );
      }

      if( v_tx_cmd_fifo_status_value.u_B.s_tx_cmd_fifo_overflow == 1 )
      {
         /* 1: Remonter le flag de panne */
         cbit_mbx_status.TX_status |= v_tx_cmd_fifo_status_value.u_B.s_tx_cmd_fifo_overflow << as_return_overflow;

         /* 2: Flush de la TX FIFO CMD */
         /*
          * Flush tx cmd fifo
          */
         v_cmd_fifo_control_value.u_R = 0;
         v_cmd_fifo_control_value.u_B.s_tx_cmd_fifo_flush = 1;
         MBX_FIFO_TX_CMD_WRITE_CONTROL ( (CMN_IOSP_ID_t)e_CFEX_MBX_CONF_0, &v_cmd_fifo_control_value );

         v_tx_cmd_ack_value.u_R = 0;
         v_tx_cmd_ack_value.u_B.s_tx_cmd_fifo_flush_ack = 1;
         MBX_FIFO_TX_CMD_WRITE_STATUS_ACK ( (CMN_IOSP_ID_t)e_CFEX_MBX_CONF_0, &v_tx_cmd_ack_value );

         /* 3: Reinit du Datagramme UDP */
         ETH_UDP_Init(); /* From ETH_UDP_Init */

          /* 4: Record the error in Log Area */
         /* TODO PAULO : No logbook available */

         /* 5: Acknowledge the status */
         v_tx_cmd_ack_value.u_R = 0;
         v_tx_cmd_ack_value.u_B.s_tx_cmd_fifo_overflow_ack = 1;
         MBX_FIFO_TX_CMD_WRITE_STATUS_ACK ( (CMN_IOSP_ID_t)e_CFEX_MBX_CONF_0, &v_tx_cmd_ack_value );
      }
#endif
      p_pt_stats->s_status = e_CMN_FLAG_NOT_COMPLETE ;
   }
}

/* ---------- internal operation bodies: ------------------------------------ */
