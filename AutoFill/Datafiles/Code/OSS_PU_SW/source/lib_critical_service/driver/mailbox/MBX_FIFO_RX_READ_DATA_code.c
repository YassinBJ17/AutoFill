/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Mailbox Rx read data function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/mailbox/MBX_CFEX_public.h"
#include "driver/mailbox/MBX_HAL_public.h"
#include "driver/mailbox/MBX_REG_common.h"
#include "driver/mailbox/MBX_conf.h"
#include "driver/mailbox/MBX_private.h"
#if (MBX_TIME_CONF_ENABLE != 0)
#include "libtools/time/LIB_TIME_public.h"
#endif

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */
#if (MBX_TIME_CONF_ENABLE != 0)
   CMN_SYSTEM_TIME_t    v_duration_mbx_read_time;
#endif
/* ---------- provided operation bodies: ------------------------------------ */
/* */
void MBX_FIFO_READ_DATA( CMN_IOSP_ID_t        const p_MBX_FIFO_conf_id,
                         CMN_SYSTEM_SIZE_t    const p_buff_size,
                         uint32_t             const p_offset,
                         ts_CMN_IOSP_BUFFER * const p_buffer )
{
   /* Local variable declaration */
   ts_MBX_RX_REG volatile *    pt_mbx_rx_data_fifo_reg_descr;
   /* */
   uint32_t   v_i;
   uint32_t   v_length ;
   uint32_t * pt_data_read;
   uint32_t   v_buff_size;

#ifdef CBIT_MBX
   tu_MBX_RX_FIFO_STATUS_REG  v_rx_fifo_status_value;
   tu_RX_FIFO_CONTROL_REG     v_fifo_control_value;
   tu_RX_FIFO_STATUS_ACK_REG  v_rx_ack_value;
#endif

#if (MBX_TIME_CONF_ENABLE != 0)
   CMN_SYSTEM_TIME_t v_start_time;
   CMN_SYSTEM_TIME_t v_end_time;
#endif

   /* Local variable initialization */
   /* */
#if (MBX_TIME_CONF_ENABLE != 0 )
   LIBT_TIME_GET( &v_start_time );
#endif

   pt_data_read = MBX_rxBuf;

   /* Get the MBX_FIFO register descriptor */
   /* >RELAX<SYNCHRONe_C_Code_10.7> No loss of precision. The structure type 'ts_MBX_RX_REG' is tailor-made for the registers starting at this address.  */
   pt_mbx_rx_data_fifo_reg_descr = (ts_MBX_RX_REG volatile *)c_MBX_CFEX_CONFIGURATION_tab[p_MBX_FIFO_conf_id].s_mbx_rx_fifo_address;
   v_buff_size = p_buff_size + p_offset;

   /* convert size in number of words */
   if ( ( v_buff_size % 4 ) != 0 )
   {
      v_length = ( v_buff_size / 4 ) + 1;
   }
   else
   {
      v_length = ( v_buff_size / 4 );
   }

   /* Read mailbox register */
   for ( v_i = 0ul ; v_i < v_length ; v_i++ )
   {
      *pt_data_read = (uint32_t)(pt_mbx_rx_data_fifo_reg_descr->s_RX_DATA_REG);
      pt_data_read ++;
   }

   /* Initialize the read size */
   p_buffer->s_buffer_size = p_buff_size;
   p_buffer->s_buffer = (int8_t * )( MBX_rxBuf ) + p_offset;


#ifdef CBIT_MBX
   MBX_READ_STATUS ( (CMN_IOSP_ID_t)e_CFEX_MBX_CONF_0 , &v_rx_fifo_status_value );

   /* 1: In case of single bitter detected by FPGA */
   if( v_rx_fifo_status_value.u_B.s_rx_fifo_single_biterr == 1 )
   {
      /* 1: Remonter le flag de panne */
      cbit_mbx_status.RX_status |= v_rx_fifo_status_value.u_B.s_rx_fifo_single_biterr << as_return_mem_corr;
      cbit_mbx_status.RX_status |= v_rx_fifo_status_value.u_B.s_rx_fifo_single_biterr << as_return_no_frame;

      /* 2: Acknowledge the status */
      v_rx_ack_value.u_R = 0;
      v_rx_ack_value.u_B.s_rx_fifo_biterr_ack = 1;
      MBX_FIFO_RX_WRITE_STATUS_ACK ( p_MBX_FIFO_conf_id, &v_rx_ack_value );
   }

   /* 2: In case of double bitter detected by FPGA */
   if( v_rx_fifo_status_value.u_B.s_rx_fifo_double_biterr == 1 )
   {
      /* 1: Remonter a l'AS le flag de panne */
      cbit_mbx_status.RX_status |= v_rx_fifo_status_value.u_B.s_rx_fifo_double_biterr << as_return_mem_corr;
      cbit_mbx_status.RX_status |= v_rx_fifo_status_value.u_B.s_rx_fifo_double_biterr << as_return_no_frame;

      /* 2: Flush de la TX FIFO CMD */
      /*
       * Flush tx fifo
       */
      v_fifo_control_value.u_R = 0;
      v_fifo_control_value.u_B.s_rx_fifo_flush = 1;
      MBX_FIFO_RX_WRITE_CONTROL ( p_MBX_FIFO_conf_id, &v_fifo_control_value );

      v_rx_ack_value.u_R = 0;
      v_rx_ack_value.u_B.s_rx_fifo_flush_ack = 1;
      MBX_FIFO_RX_WRITE_STATUS_ACK ( p_MBX_FIFO_conf_id, &v_rx_ack_value );

      /* 3: Reinit du Datagramme UDP */
      ETH_UDP_Init(); /* From ETH_UDP_Init */

      /* 4: Record the error in Log Area */
      /* TODO PAULO : No logbook available */

      /* 5: Acknowledge the status */
      v_rx_ack_value.u_R = 0;
      v_rx_ack_value.u_B.s_rx_fifo_biterr_ack = 1;
      MBX_FIFO_RX_WRITE_STATUS_ACK ( p_MBX_FIFO_conf_id, &v_rx_ack_value );
   }

   /*Set final status of RX fifo */
   if ( cbit_mbx_status.RX_status == 0 )
   {
      cbit_mbx_status.RX_status |= 1ul ;
   }
#endif

#if (MBX_TIME_CONF_ENABLE != 0)
   LIBT_TIME_GET( &v_end_time );
   v_duration_mbx_read_time = v_end_time - v_start_time;
#endif
   /* else       */
   /* Size error */
}

/* ---------- internal operation bodies: ------------------------------------ */
