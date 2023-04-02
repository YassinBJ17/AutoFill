/* --------------------------------------------------------------------------
 *                           Sagem Defense Securite
 *                               SAFRAN Group
 * --------------------------------------------------------------------------
 * PROJECT : CHRONOS_MOCKUP
 * CSU name :
 * %name: HWCRC_INIT_code.c %
 * %full_name: fadex#1/csrc/HWCRC_INIT_code.c/1 %
 * DESCRIPTION : short description of the operations of the .c file
 *
 * Creation information:
 *   Created by: F073297
 *   Date : Thu Jan 31 16:48:16 CET 2019
 *
 * Modification information:
 *   %derived_by: F605763 %
 *   %date_created:Thu May 12 18:18:30 CEST 2022 %
 * --------------------------------------------------------------------------
 * SAGEM Defense Securite document. Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "HWCRC_CFEX_public.h"

/* ---------- include required interface: ----------------------------------- */
/* LPOS Common Interface */
/*  */
#include "CMN_TYPES_common.h"
#include "HWCRC_REG_common.h"

/* LPOS Public Interface */
#include "HWCRC_HAL_public.h"

/* LPOS Private Interface */
/* none */

/* ---------- internal define constants: ------------------------------------ */
/* none */


/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
/* */
/* MPC577 HWCRC specific controller register mapping */
uint32_t const c_HWCRC_ctrler_addr[8]=
{
   HWCRC_0_BASE_ADDR,      /* MPC5777DS_HWCRC0  */
   HWCRC_1_BASE_ADDR	   /* MPC5777DS_HWCRC1  */
};

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
void HWCRC_INIT( void )
{
   /* Local variable declaration */
   uint32_t                        v_hwcrc_index;
   ts_HWCRC_REG volatile *         pt_hwcrc_reg;
   ts_HWCRC_CFEX_ELT const *       pt_hwcrc_conf;

   /* */
   /* General HWCRC configuration */
   /* */

   /* */
   for ( v_hwcrc_index = 0ul ; v_hwcrc_index < c_HWCRC_CFEX_tab_SIZE ; v_hwcrc_index++ )
   {
      /* Get HWCRC configuration descriptor */
      pt_hwcrc_conf = &(c_HWCRC_CFEX_CONFIGURATION_tab[v_hwcrc_index]);

      /* Get HWCRC registers descriptor */
      /* >RELAX<SYNCHRONe_C_Code_10.7> No loss of precision. The structure type 'ts_HWCRC_REG' is tailor-made for the registers starting at this address.  */
      pt_hwcrc_reg = (ts_HWCRC_REG volatile *)c_HWCRC_ctrler_addr[pt_hwcrc_conf->s_module_nb];


      /* Polynome */
      if ( pt_hwcrc_conf->s_crc_poly == e_HWCRC_CFEX_CRC32_POLY )
      {
         /* CRC 32 ETH */
    	  pt_hwcrc_reg->s_CRC_CFG.u_B.s_POLYG = (reg32_t)e_HWCRC_CRC32_POLY;
    	  pt_hwcrc_reg->s_CRC_CFG.u_B.s_SWAP_BYTEWISE_CRC_32 = 1;
    	  pt_hwcrc_reg->s_CRC_CFG.u_B.s_SWAP = 1;
    	  pt_hwcrc_reg->s_CRC_CFG.u_B.s_INV = 1;

      }
      else   /* e_HWCRC_CFEX_CRC_CCITT_POLY or e_HWCRC_CFEX_CRC8_POLY */
      {

      }


      /* Transfer mode */
      if ( pt_hwcrc_conf->s_transfer_mode == e_HWCRC_CFEX_TRANSFER_MODE_SW )
      {
         /* Mode SW   */
      }
      else /* e_HWCRC_CFEX_TRANSFER_MODE_DMA */
      {
         /* Mode DMA   */
      }

      /* HWCRC Descriptor init       */
      /* Register s_address */
      HWCRC_CFEX_descriptor_tab[v_hwcrc_index].s_address = c_HWCRC_ctrler_addr[pt_hwcrc_conf->s_module_nb];
      /* DMA line number */
      HWCRC_CFEX_descriptor_tab[v_hwcrc_index].s_dma_conf_nb = pt_hwcrc_conf->s_dma_conf_nb;

   }
}

/* ---------- internal operation bodies: ------------------------------------ */
/* none */
