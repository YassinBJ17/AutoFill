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

/* UART register mask for RX FIFO empty Flag */
#define UARTSR_RX_FIFO_MASK (reg32_t) 0x00000004

/* ---------- provided operation bodies: ------------------------------------ */
/* */
void FDX_UART_FIFO_READ_UPDATE( CMN_IOSP_ID_t const p_uart_line_id ,
                            ts_UART_STATS_TRANSFERT * const p_stats )
{
   /* Local variable declaration */
   uint8_t                                v_rx_data ;
   ts_UART_LINFlexD_COMMON_REG volatile * pt_uart_reg ;
   ts_UART_CFEX_RX_ACCESS *               pt_buff_read ;

   /* Local variable initialization */
   /*>RELAX<SYNCHRONe_C_Code_10.7> The structure ts_UART_LINFlexD_COMMON_REG is explicitly made for this address. Cast is normal. */
   pt_uart_reg = (ts_UART_LINFlexD_COMMON_REG volatile *) FDX_UART_CFEX_descriptor_tab[ p_uart_line_id ].s_address ;
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe. There is no loss of precision from (ts_UART_CFEX_RX_ACCESS*) to (ts_UART_CFEX_RX_ACCESS*). */
   pt_buff_read = & ( FDX_UART_CFEX_descriptor_tab[ p_uart_line_id ].s_desc_rx ) ;

   while ( ( ( pt_uart_reg->s_UARTSR.u_R & UARTSR_RX_FIFO_MASK ) == 0U ) && /* data in the LinFlexD buffer exists */
   ( pt_buff_read->s_nb_done < pt_buff_read->s_buff_size ) )
   {
      /* get the data: note, that according to the Table 59-4. BDRM access    */
      /* in UART mode, in FIFO, the 32 bits access is forbidden.              */
      /* so the use of the bit type of the BDRM structure is useless.         */
      /* Thus the use of an offset from the base address to read the last byte*/
      /*>RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> The register (u_BDRM_R) will be parsed byte by byte. Cast is normal. */
      /*>RELAX<SYNCHRONe_C_Code_10.2, SYNCHRONe_C_Code_17.4> As the value '3' is applied to a uint8_t pointer, the value is in range of a MPC5777M register (32 bits).  */
      v_rx_data = * ( ( (uint8_t *) ( & (pt_uart_reg->s_BDRM.u_R ) ) ) + LAST_BYTE_32_BITS_OFFSET ) ;
      /* take */
      /*>RELAX<SYNCHRONe_C_Code_17.4> the 's_buff_current' is an array which size is given by s_buff_size. As the index array is control to be in range. the index array use is safe. */
      /*>RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_10.2> The cast is safe. There is no loss of precision from (uint8_t) to (uint8_t). */
      pt_buff_read->s_buff_current[ pt_buff_read->s_nb_done ] = (uint8_t) v_rx_data ;
      pt_buff_read->s_nb_done += 1UL ;
   }

   p_stats->s_size = pt_buff_read->s_buff_size ;
   p_stats->s_done_nb = pt_buff_read->s_nb_done ;
}

/* ---------- internal operation bodies: ------------------------------------ */
