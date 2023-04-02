/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : short description of the operations of the .c file
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */


/* ---------- include required interface: ----------------------------------- */
#include "UART_CFEX_public.h"
#include "UART_HAL_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
void FDX_UART_FIFO_WRITE_UPDATE( CMN_IOSP_ID_t const p_uart_line_id ,
                             ts_UART_STATS_TRANSFERT * const p_stats )
{
   /* Local variable declaration */
   ts_UART_LINFlexD_COMMON_REG volatile *  pt_uart_reg ;
   ts_UART_CFEX_TX_ACCESS *                pt_buff_write ;
   uint8_t *                               pt_pTX ;

   /*>RELAX<SYNCHRONe_C_Code_10.7> The structure ts_UART_LINFlexD_COMMON_REG is explicitly made for this address. Cast is normal. */
   pt_uart_reg = (ts_UART_LINFlexD_COMMON_REG volatile *) FDX_UART_CFEX_descriptor_tab[ p_uart_line_id ].s_address ;
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe. There is no loss of precision from (ts_UART_CFEX_TX_ACCESS*) to (ts_UART_CFEX_TX_ACCESS*). */
   pt_buff_write = & (FDX_UART_CFEX_descriptor_tab[ p_uart_line_id ].s_desc_tx ) ;

   /* 2 cases : either the buffer is set in FIFO or not TXFIFO Buffer */
   /* write character to transmit buffer byte access have to be used in TXFIFO mode */
   /* compiler can use word instructions for byte access thus byte pointer is used instead */

   /*>RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> The register (u_BDRM_R) will be parsed byte by byte. Cast is normal. */
   /*>RELAX<SYNCHRONe_C_Code_10.2, SYNCHRONe_C_Code_7.2, SYNCHRONe_C_Code_17.4> As the value '3' is applied to a uint8_t pointer, the value is in range of a MPC5777M register (32 bits).  */
   pt_pTX = ( (uint8_t *) &pt_uart_reg->s_BDRL.u_R ) + LAST_BYTE_32_BITS_OFFSET ;

   if ( ( pt_buff_write->s_nb_done < pt_buff_write->s_buff_size ) &&
            ( 0U == pt_uart_reg->s_UARTSR.u_B.s_DTFTFF ) )
   {
      /*>RELAX<SYNCHRONe_C_Code_17.4> the 's_buff_current' is an array which size is given by s_buff_size. As the index array is control to be in range. the index array use is safe. */
      /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_10.2> The cast is safe. There is no loss of precision from (uint8_t) to (uint8_t). */
      *pt_pTX = pt_buff_write->s_buff_current[ pt_buff_write->s_nb_done ] ;
      pt_buff_write->s_nb_done += 1UL ;
   }

   p_stats->s_size = pt_buff_write->s_buff_size ;
   p_stats->s_done_nb = pt_buff_write->s_nb_done ;
}

/* ---------- internal operation bodies: ------------------------------------ */
