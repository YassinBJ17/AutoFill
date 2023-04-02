/* --------------------------------------------------------------------------
 *                           Sagem Defense Securite
 *                               SAFRAN Group
 * --------------------------------------------------------------------------
 * PROJECT : CHRONOS_MOCKUP
 * CSU name :
 * %name: DMA_REQUEST_code.c %
 * %full_name: fadex#8/csrc/DMA_REQUEST_code.c/1 %
 * DESCRIPTION : short description of the operations of the .c file
 *
 * Creation information:
 *   Created by: F073297
 *   Date : Thu May 31 09:54:59 CEST 2018
 *
 * Modification information:
 *   %derived_by: F605763 %
 *   %date_created:Thu May 12 18:18:08 CEST 2022 %
 * --------------------------------------------------------------------------
 * SAGEM Defense Securite document. Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DMA_HAL_public.h"

/* ---------- include required interface: ----------------------------------- */
/* LPOS Common Interface */
#include "CMN_TYPES_common.h"
#include "DMA_CFEX_public.h"

/* LPOS Public Interface */
/* none */

/* LPOS Private Interface */
/* none */

/* ---------- internal define constants: ------------------------------------ */
/* none */

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Used to enable or disable request signal dma */
void DMA_REQUEST ( CMN_IOSP_ID_t const p_dma_conf_id,
                          te_CMN_FLAG_ACTIVATION const p_dma_request_signal )
{
   /* Local variable declaration */
   ts_DMA_REG volatile * pt_dma_reg_descr;
   te_DMA_CFEX_DMA_LINE      v_dma_line_descr;
   /* */

   /* Writes the datas contained in the CPU internal write buffer  */
   /* >RELAX<SYNCHRONe_C_Code_14.2> Assembler instruction */
   asm("msync");

   /* Local variable initialization */
   /* Get the DMA register descriptor */
   pt_dma_reg_descr = DMA_descr[p_dma_conf_id].s_dma_addr;
   /* Get the DMA line descriptor */
   v_dma_line_descr = DMA_descr[p_dma_conf_id].s_line_nb;

   /* Enable request signal */
   if ( p_dma_request_signal == e_CMN_FLAG_ACTIVATE )
   {
      /* DMA request signal for channel x enabled*/
      if ( v_dma_line_descr < e_DMA_CFEX_DMA_LINE_32 )
      {
         /* Channel  [0..31] */
         /* >RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_10.3, SYNCHRONe_C_Code_12.14> : the v_dma_line_descr is an enumerate coded in 8 bits, so the multiplication by 2 can be coded as unsigned int  */
         pt_dma_reg_descr->s_ERQL.u_R = pt_dma_reg_descr->s_ERQL.u_R | ( reg32_t ) ( (0x00000001 << v_dma_line_descr) );
      }
      else
      {
         /* Channel  [32..63] */
         /* >RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_10.3, SYNCHRONe_C_Code_12.14> : the v_dma_line_descr is an enumerate coded in 8 bits, so the multiplication by 2 can be coded as unsigned int  */
         pt_dma_reg_descr->s_ERQH.u_R = pt_dma_reg_descr->s_ERQH.u_R | ( reg32_t ) ( (0x00000001 << (v_dma_line_descr - e_DMA_CFEX_DMA_LINE_32 )) );
      }
   }
   /* Disable request signal */
   else
   {
      /* DMA request signal for channel x enabled*/
      if ( v_dma_line_descr < e_DMA_CFEX_DMA_LINE_32 )
      {
         /* Channel  [0..31] */
         /* >RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_10.3, SYNCHRONe_C_Code_12.14> : the v_dma_line_descr is an enumerate coded in 8 bits, so the multiplication by 2 can be coded as unsigned int  */
         pt_dma_reg_descr->s_ERQL.u_R = pt_dma_reg_descr->s_ERQL.u_R & ( reg32_t ) ( (~(0x00000001 << v_dma_line_descr)) );
      }
      else
      {
         /* Channel  [32..63] */
         /* >RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_10.3, SYNCHRONe_C_Code_12.14> : the v_dma_line_descr is an enumerate coded in 8 bits, so the multiplication by 2 can be coded as unsigned int  */
         pt_dma_reg_descr->s_ERQH.u_R = pt_dma_reg_descr->s_ERQH.u_R & ( reg32_t ) ( ( ~( 0x00000001 << ( v_dma_line_descr - e_DMA_CFEX_DMA_LINE_32 ) ) ) );
      }
   }

}

/* ---------- internal operation bodies: ------------------------------------ */
/* none */
