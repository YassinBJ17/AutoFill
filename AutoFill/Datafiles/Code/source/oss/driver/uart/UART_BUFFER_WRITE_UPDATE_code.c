/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : short description of the operations of the .c file
 * -------------------------------------------------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "UART_CFEX_public.h"
#include "UART_HAL_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */
/* Constant to clear the Data Transmission Complete flag */
#define CLEAR_DTFTFF_FLAG 0x0002U

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
void FDX_UART_BUFFER_WRITE_UPDATE ( CMN_IOSP_ID_t const p_uart_line_id ,
                                ts_UART_STATS_TRANSFERT * const p_stats )
{
   /* Local variable declaration */
   ts_UART_LINFlexD_COMMON_REG volatile *  pt_uart_reg ;
   ts_UART_CFEX_TX_ACCESS *                pt_buff_write ;
   uint32_t                                v_i ;
   uint32_t                                v_nb_charac ;
   te_CMN_FLAG_RUN                         v_write ;
   uint8_t *                               pt_pTX ;

   /* Local variable initialization */
   /*>RELAX<SYNCHRONe_C_Code_10.7> The structure ts_UART_LINFlexD_COMMON_REG is explicitly made for this address. Cast is normal. */
   pt_uart_reg = (ts_UART_LINFlexD_COMMON_REG volatile *) FDX_UART_CFEX_descriptor_tab[ p_uart_line_id ].s_address;
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe. There is no loss of precision from (ts_UART_CFEX_TX_ACCESS*) to (ts_UART_CFEX_TX_ACCESS*). */
   pt_buff_write = & ( FDX_UART_CFEX_descriptor_tab[ p_uart_line_id ].s_desc_tx ) ;

   /* TX Buffer write */
   if ( pt_buff_write->s_nb_in_progress > 0UL )
   {
      if ( 1U == pt_uart_reg->s_UARTSR.u_B.s_DTFTFF )
      {
         /* the last character has been sent, data transmission completed */
         /* clear the DTFTFF flag and not the other flags */
         /*>RELAX<SYNCHRONe_C_Code_7.2> CPU Optimization : in order to clear the DTFTFF field, the register is used. */
         pt_uart_reg->s_UARTSR.u_R = CLEAR_DTFTFF_FLAG ;
         v_write = e_CMN_FLAG_RUN ;
         pt_buff_write->s_nb_done += pt_buff_write->s_nb_in_progress ;
         pt_buff_write->s_nb_in_progress = 0UL ;
      }
      else
      {
         v_write = e_CMN_FLAG_STOP ;
      }
   }
   else
   {
      v_write = e_CMN_FLAG_RUN ;
   }
   if ( v_write == e_CMN_FLAG_RUN )
   {
      /*>RELAX<SYNCHRONe_C_Code_10.7> The cast is safe. There is no loss of precision from (reg32_t) to (reg32_t). */
      v_nb_charac = (uint32_t) ( pt_uart_reg->s_UARTCR.u_B.s_TDFL_TFC + (reg32_t)1 ) ;
      if ( v_nb_charac <= ( pt_buff_write->s_buff_size - pt_buff_write->s_nb_done ) )
      {
         /* write character to transmit buffer byte access have to be used in TXFIFO mode
          compiler can use word instructions for byte access thus byte pointer is used instead */

         /*>RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> The register (u_BDRM_R) will be parsed byte by byte. Cast is normal. */
         /*>RELAX<SYNCHRONe_C_Code_10.2, SYNCHRONe_C_Code_7.2, SYNCHRONe_C_Code_17.4> As the value '4 - v_nb_charac' is applied to a uint8_t pointer, the value is in range of a MPC5777M register (32 bits).  */
         pt_pTX = ( (uint8_t*) ( &pt_uart_reg->s_BDRL.u_R ) ) + ( (uint32_t)4 - v_nb_charac ) ;
         pt_buff_write->s_nb_in_progress = v_nb_charac ;
         for ( v_i = 0UL ; v_i < v_nb_charac ; v_i++ )
         {
            /* write byte by byte : inverse order */
            /*>RELAX<SYNCHRONe_C_Code_17.4,SYNCHRONe_C_Code_10.2> the 'pt_pTX' is a pointer on a HW register, the array indexer can be apply safely as the index range is in 0;4. */
            /*>RELAX<SYNCHRONe_C_Code_10.7> The cast is safe. There is no loss of precision from (int8_t*) to (int8_t*). */
            pt_pTX[ v_i ] = pt_buff_write->s_buff_current[ ( ( pt_buff_write->s_nb_done + v_nb_charac )- (uint32_t)1 ) - v_i ] ;
         }
      }
   }
   p_stats->s_size = pt_buff_write->s_buff_size ;
   p_stats->s_done_nb = pt_buff_write->s_nb_done ;
}

/* ---------- internal operation bodies: ------------------------------------ */
