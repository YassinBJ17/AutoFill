/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : short description of the operations of the .c file
 * -------------------------------------------------------------------------- */


/* ---------- include required interface: ----------------------------------- */
#include "UART_CFEX_public.h"
#include "UART_HAL_public.h"
#include "driver/dma/DMA_HAL_public.h"

#include "libtools/time/LIB_TIME_public.h"

/* ---------- internal define constants: ------------------------------------ */


/* ---------- internal types: ----------------------------------------------- */


/* ---------- internal operations: ------------------------------------------ */


/* ---------- internal constants: ------------------------------------------- */


/* ---------- internal data: ------------------------------------------------ */
uint32_t const FDX_c_UART_LINFlexD_ctrler_addr[ e_UART_LINE_NB ] =
{
    UART_LINFLEXD_CONTROLLER_0_ADDR ,
    UART_LINFLEXD_CONTROLLER_1_ADDR ,
    UART_LINFLEXD_CONTROLLER_2_ADDR ,
    UART_LINFLEXD_CONTROLLER_14_ADDR ,
    UART_LINFLEXD_CONTROLLER_15_ADDR ,
    UART_LINFLEXD_CONTROLLER_16_ADDR
} ;
/* */
uint32_t const FDX_c_UART_LINFlexD_MASTER_ctrler_addr[ e_UART_LINE_NB ] =
{
    UART_LINFlexD_MASTER_ONLY_0_ADDR ,
    UART_LINFlexD_MASTER_ONLY_1_ADDR ,
    UART_LINFlexD_MASTER_ONLY_2_ADDR ,
    UART_LINFlexD_MASTER_ONLY_14_ADDR ,
    UART_LINFlexD_MASTER_ONLY_15_ADDR ,
    UART_LINFlexD_MASTER_ONLY_16_ADDR
} ;



/* ---------- provided operation bodies: ------------------------------------ */

void FDX_UART_INIT( tu_CMN_RC * const p_return_code )
{
   /* Local variable declaration */
   uint32_t                        v_i;
   ts_UART_CONFIG_DESC *           pt_uart_desc;
   const ts_UART_CFEX_ELT *        c_conf;
   ts_DMA_PROG                     v_dma_prog ;
   ts_UART_LINFlexD_REG            c_uart_reg;

   /* Local variable initialization */
   CMN_SYSTEM_TIME_t v_time = 0ll ;
   CMN_SYSTEM_TIME_t v_timeout = 0ll ;

   /* UART line configuration */
   for ( v_i = 0UL; v_i < FDX_c_UART_CFEX_tab_SIZE ; v_i++ )
   {
      /*>RELAX<SYNCHRONe_C_Code_10.7> The cast is safe. There is no loss of precision from (ts_UART_CONFIG_DESC*) to (ts_UART_CONFIG_DESC*). */
      pt_uart_desc = & ( FDX_UART_CFEX_descriptor_tab[v_i] );
      /*>RELAX<SYNCHRONe_C_Code_10.7> The cast is safe. There is no loss of precision from (const ts_UART_CFEX_ELT*) to (const ts_UART_CFEX_ELT*). */
      c_conf = & ( FDX_c_UART_CFEX_CONFIGURATION_tab[v_i] );

      /* initialization of internal descriptor */
      if (c_conf->s_tranfer_mode == e_UART_CFEX_TRANSFER_MODE_DMA)
      {
          pt_uart_desc->s_dma_conf_rx.s_conf_id              =  c_conf->s_dma_conf_rx.s_conf_id;
          pt_uart_desc->s_dma_conf_rx.s_type_dma_transfert   =  c_conf->s_dma_conf_rx.s_type_dma_transfert;
          pt_uart_desc->s_dma_conf_rx.s_type_fill            =  c_conf->s_dma_conf_rx.s_type_fill;
          pt_uart_desc->s_dma_conf_tx.s_conf_id              =  c_conf->s_dma_conf_tx.s_conf_id;
          pt_uart_desc->s_dma_conf_tx.s_type_dma_transfert   =  c_conf->s_dma_conf_tx.s_type_dma_transfert;
          pt_uart_desc->s_dma_conf_tx.s_type_fill            =  c_conf->s_dma_conf_tx.s_type_fill;
      }
      pt_uart_desc->s_desc_rx.s_buff_current   = (int8_t*)0x00000000;
      pt_uart_desc->s_desc_rx.s_buff_size      = 0UL;
      pt_uart_desc->s_desc_rx.s_nb_done        = 0UL;
      pt_uart_desc->s_desc_tx.s_buff_current   = (int8_t*)0x00000000;
      pt_uart_desc->s_desc_tx.s_buff_size      = 0UL;
      pt_uart_desc->s_desc_tx.s_nb_done        = 0UL;
      pt_uart_desc->s_desc_tx.s_nb_in_progress = 0UL;
      pt_uart_desc->s_address = (CMN_SYSTEM_ADDR_VAL_t)FDX_c_UART_LINFlexD_ctrler_addr[ c_conf->s_line_nb ] ;

      /*{{RELAX<SYNCHRONe_C_Code_10.7> The structure ts_UART_LINFlexD_COMMON_REG is explicitly made for this address. Cast is normal. */
      c_uart_reg.s_uart_common_reg = (ts_UART_LINFlexD_COMMON_REG volatile *)FDX_c_UART_LINFlexD_ctrler_addr[ c_conf->s_line_nb ];
      c_uart_reg.s_uart_master_reg = (ts_UART_LINFlexD_MASTER_REG volatile *)FDX_c_UART_LINFlexD_MASTER_ctrler_addr[ c_conf->s_line_nb ];
      /* }}<SYNCHRONe_C_Code_10.7> */

      /* enter INIT mode */
      c_uart_reg.s_uart_common_reg->s_LINCR1.u_B.s_SLEEP = 0U ;
      c_uart_reg.s_uart_common_reg->s_LINCR1.u_B.s_INIT = 1U ;

      /* wait for the INIT mode */
      LIBT_TIME_GET ( & v_timeout ) ;

      /* 300 us of time out */
      /*>RELAX<SYNCHRONe_C_Code_7.2> the literal 300*1000 is specified in Detailed Design. It represents 300 us. */
      v_timeout += 300ll * 1000ll ;
      v_time = 0ll ;

      /*>RELAX<SYNCHRONe_C_Code_7.2> CPU optimisation, the LINSR register is directly tested instead of its corresponding bits. */
      while ( ( 0x1000u != ( c_uart_reg.s_uart_common_reg->s_LINSR.u_R & 0xF000u ) ) && ( v_time < v_timeout ) )
      {
            LIBT_TIME_GET ( &v_time ) ;
      }

      if ( v_time < v_timeout )
      {
        /* configure for UART mode */
        /* set the UART bit first to be able to write the other bits */
        c_uart_reg.s_uart_common_reg->s_UARTCR.u_R = 0x0001U ;
        c_uart_reg.s_uart_common_reg->s_UARTCR.u_R = c_conf->s_uart_hw_conf.s_UARTCR_conf.u_R ;
        c_uart_reg.s_uart_common_reg->s_LINIBRR.u_R = c_conf->s_uart_hw_conf.s_int_part_LFDIV ;
        c_uart_reg.s_uart_common_reg->s_LINFBRR.u_R = c_conf->s_uart_hw_conf.s_frac_part_LFDIV ;
        c_uart_reg.s_uart_master_reg->s_GCR.u_B.s_STOP = c_conf->s_uart_hw_conf.s_UARTCR_conf.u_B.s_SBUR;

        /* enter NORMAL mode */
        c_uart_reg.s_uart_common_reg->s_LINCR1.u_B.s_INIT = 0U ;
        c_uart_reg.s_uart_master_reg->s_DMARXE.u_R = 0x0000U ;
        c_uart_reg.s_uart_master_reg->s_DMATXE.u_R = 0x0000U ;
      }
      else
      {
          p_return_code->u_b.s_RC_NOT_AVAILABLE = 1u ;
      }

      if (c_conf->s_tranfer_mode == e_UART_CFEX_TRANSFER_MODE_DMA)
      {
          /* rx configuration line */
          FDX_UART_DMA_SET_RX_CFG( (CMN_IOSP_ID_t) v_i , &v_dma_prog);
          FDX_DMA_CFG(c_conf->s_dma_conf_rx.s_conf_id , &v_dma_prog );

          /* tx configuration line */
          FDX_UART_DMA_SET_TX_CFG((CMN_IOSP_ID_t) v_i , &v_dma_prog);
          FDX_DMA_CFG (c_conf->s_dma_conf_tx.s_conf_id , &v_dma_prog );

          /* UART register configuration */
          c_uart_reg.s_uart_master_reg->s_DMARXE.u_R = 0x0001U ;
          c_uart_reg.s_uart_master_reg->s_DMATXE.u_R = 0x0001U ;
      }
   }
}

/* ---------- internal operation bodies: ------------------------------------ */
