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
/* RX Buffer mode selected */
/* data reception completed flag */
/* UARTSR_DRFRFE = 1U ; */
/* Release Message Buffer flag */
/* s_UARTSR_RMB = 1U ; */
#define UARTSR_RX_BUFFER_MODE_MASK (reg32_t) 0x00000204

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

void FDX_UART_BUFFER_READ_UPDATE ( CMN_IOSP_ID_t const p_uart_line_id ,
                               ts_UART_STATS_TRANSFERT * const p_stats )
{
   /* Local variable declaration */
   uint8_t *                              pt_pRX ;
   ts_UART_LINFlexD_COMMON_REG volatile * pt_uart_reg ;
   ts_UART_CFEX_RX_ACCESS *               pt_buff_read ;
   uint32_t                               v_nbCharacterToRetreive ;
   uint32_t                               v_i ;

   /* Local variable initialization */
   /*>RELAX<SYNCHRONe_C_Code_10.7> The structure ts_UART_LINFlexD_COMMON_REG is explicitly made for this address. Cast is normal. */
   pt_uart_reg = (ts_UART_LINFlexD_COMMON_REG volatile *)FDX_UART_CFEX_descriptor_tab[ p_uart_line_id ].s_address;
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe. There is no loss of precision from (ts_UART_CFEX_RX_ACCESS*) to (ts_UART_CFEX_RX_ACCESS*). */
   pt_buff_read = & ( FDX_UART_CFEX_descriptor_tab[ p_uart_line_id ].s_desc_rx ) ;

   while ( ( ( pt_uart_reg->s_UARTSR.u_R & UARTSR_RX_BUFFER_MODE_MASK ) == UARTSR_RX_BUFFER_MODE_MASK )
            && ( pt_buff_read->s_nb_done < pt_buff_read->s_buff_size )
   )
   {
      /* number of Character to copy */
      /*>RELAX<SYNCHRONe_C_Code_10.2> The cast is safe : casting from (reg32_t) to (uint32_t). */
      v_nbCharacterToRetreive = pt_uart_reg->s_UARTCR.u_B.s_RDFL_RFC + (reg32_t)1 ;
      if ( v_nbCharacterToRetreive > pt_buff_read->s_buff_size - pt_buff_read->s_nb_done )
      {
         v_nbCharacterToRetreive = pt_buff_read->s_buff_size - pt_buff_read->s_nb_done ;
      }
      pt_buff_read->s_nb_done += v_nbCharacterToRetreive ;
      /* get the data */
      /*>RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> The register (u_BDRM_R) will be parsed byte by byte. Cast is normal. */
      /*>RELAX<SYNCHRONe_C_Code_10.2, SYNCHRONe_C_Code_7.2, SYNCHRONe_C_Code_17.4> As the value '4' is applied to a uint8_t pointer, the value is in range of a MPC5777M register (32 bits).  */
      pt_pRX = ( ( (uint8_t *) ( & ( pt_uart_reg->s_BDRM.u_R ) ) ) + 4U ) - v_nbCharacterToRetreive ;

      for ( v_i = 0UL ; v_i < v_nbCharacterToRetreive ; v_i++ )
      {
         /* take byte by byte */
         /*>RELAX<SYNCHRONe_C_Code_17.4,SYNCHRONe_C_Code_10.2> the pointer is on a HW register, the array index is in range of the HW register size. */
         /*>RELAX<SYNCHRONe_C_Code_10.7> no loss of precision : cast from int8_t to int8_t */
         pt_buff_read->s_buff_current[ ( ( pt_buff_read->s_nb_done - (uint32_t)1 ) - v_i ) ] = pt_pRX[ v_i ] ;
      }
      /* clear DRFRFE and RMB flags by writing 1 to them */
      pt_uart_reg->s_UARTSR.u_R = UARTSR_RX_BUFFER_MODE_MASK ;
   }
   p_stats->s_size = pt_buff_read->s_buff_size ;
   p_stats->s_done_nb = pt_buff_read->s_nb_done ;
}


/* ---------- internal operation bodies: ------------------------------------ */

