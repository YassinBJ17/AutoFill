/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Mailbox Tx write control function
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
void MBX_FIFO_TX_WRITE_DATA ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id,
                              uint32_t p_tx_fifo_data )
{
   /* Local Variable Declaration */
   ts_MBX_TX_REG volatile * pt_tx_fifo_data_reg;
#ifdef CBIT_MBX
   tu_MBX_TX_FIFO_STATUS_REG  v_tx_fifo_status_value;
   tu_TX_FIFO_CONTROL_REG     v_fifo_control_value;
   tu_TX_FIFO_STATUS_ACK_REG  v_tx_ack_value;
#endif

   /* Store the driver registers in local variable */
   /* >RELAX<SYNCHRONe_C_Code_10.3> The cast is safe as the structure is used to retrieve all ts_MBX_TX_REG registers which start at this address. */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe as all the structure fields are tailor-made for the different ts_MBX_TX_REG registers. */
   pt_tx_fifo_data_reg = (ts_MBX_TX_REG volatile *)c_MBX_CFEX_CONFIGURATION_tab[p_MBX_FIFO_conf_id].s_mbx_tx_fifo_address;

   /* Return Status value */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast changes register type to data type with same size */
   pt_tx_fifo_data_reg->s_TX_DATA_REG = (reg32_t)p_tx_fifo_data;

#ifdef CBIT_MBX
   MBX_FIFO_TX_READ_STATUS ( (CMN_IOSP_ID_t)e_CFEX_MBX_CONF_0 , &v_tx_fifo_status_value );

   /* 1: In case of overflow detected by FPGA */
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
      MBX_FIFO_TX_WRITE_CONTROL ( p_MBX_FIFO_conf_id, &v_fifo_control_value );

      v_tx_ack_value.u_R = 0;
      v_tx_ack_value.u_B.s_tx_fifo_flush_ack = 1;
      MBX_FIFO_TX_WRITE_STATUS_ACK ( p_MBX_FIFO_conf_id, &v_tx_ack_value );

      /* 3: Reinit du Datagramme UDP */
      ETH_UDP_Init(); /* From ETH_UDP_Init */

       /* 4: Record the error in Log Area */
      /* TODO PAULO : No logbook available */

      /* 5: Acknowledge the status */
      v_tx_ack_value.u_R = 0;
      v_tx_ack_value.u_B.s_tx_fifo_overflow_ack = 1;
      MBX_FIFO_TX_WRITE_STATUS_ACK ( p_MBX_FIFO_conf_id, &v_tx_ack_value );
   }

   /* 2: In case of single bitter detected by FPGA */
   if( v_tx_fifo_status_value.u_B.s_tx_fifo_single_biterr == 1 )
   {

      /* 1: Remonter le flag de panne */
      cbit_mbx_status.TX_status |= v_tx_fifo_status_value.u_B.s_tx_fifo_single_biterr << as_return_mem_corr;

      /* 2: Acknowledge the status */
      v_tx_ack_value.u_R = 0;
      v_tx_ack_value.u_B.s_tx_fifo_biterr_ack = 1;
      MBX_FIFO_TX_WRITE_STATUS_ACK ( p_MBX_FIFO_conf_id, &v_tx_ack_value );
   }

   /* 3: In case of double bitter by FPGA */
   if( v_tx_fifo_status_value.u_B.s_tx_fifo_double_biterr == 1 )
   {
      /* 1: Remonter le flag de panne */
      cbit_mbx_status.TX_status |= v_tx_fifo_status_value.u_B.s_tx_fifo_double_biterr << as_return_mem_corr;

      /* 2: Flush de la TX FIFO CMD */
      /*
       * Flush tx fifo
       */
      v_fifo_control_value.u_R = 0;
      v_fifo_control_value.u_B.s_tx_fifo_flush = 1;
      MBX_FIFO_TX_WRITE_CONTROL ( p_MBX_FIFO_conf_id, &v_fifo_control_value );

      v_tx_ack_value.u_R = 0;
      v_tx_ack_value.u_B.s_tx_fifo_flush_ack = 1;
      MBX_FIFO_TX_WRITE_STATUS_ACK ( p_MBX_FIFO_conf_id, &v_tx_ack_value );

      /* 3: Reinit du Datagramme UDP */
      ETH_UDP_Init(); /* From ETH_UDP_Init */

       /* 4: Record the error in Log Area */
      /* TODO PAULO : No logbook available */

      /* 5: Acknowledge the status */
      v_tx_ack_value.u_R = 0;
      v_tx_ack_value.u_B.s_tx_fifo_biterr_ack = 1;
      MBX_FIFO_TX_WRITE_STATUS_ACK ( p_MBX_FIFO_conf_id, &v_tx_ack_value );
   }

   /*Set final status of TX fifo */
   if ( cbit_mbx_status.TX_status == 0 )
   {
      cbit_mbx_status.TX_status |= 1ul ;
   }
#endif
}

/* ---------- internal operation bodies: ------------------------------------ */
