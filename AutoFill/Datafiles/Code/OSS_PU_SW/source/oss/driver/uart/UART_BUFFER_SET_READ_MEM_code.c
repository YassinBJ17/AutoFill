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

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

void FDX_UART_BUFFER_SET_READ_MEM ( CMN_IOSP_ID_t const p_uart_line_id ,
                                const ts_CMN_IOSP_BUFFER * const p_buffer  )
{
   /* Local variable declaration */
   ts_UART_CFEX_RX_ACCESS * pt_buff_read ;

   /* Local variable initialization */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe. There is no loss of precision from (ts_UART_CFEX_RX_ACCESS*) to (ts_UART_CFEX_RX_ACCESS*). */
   pt_buff_read = & (FDX_UART_CFEX_descriptor_tab[ p_uart_line_id ].s_desc_rx );

   pt_buff_read->s_buff_current = p_buffer->s_buffer ;
   pt_buff_read->s_buff_size    = p_buffer->s_buffer_size ;
   pt_buff_read->s_nb_done      = 0UL ;
}

/* ---------- internal operation bodies: ------------------------------------ */
