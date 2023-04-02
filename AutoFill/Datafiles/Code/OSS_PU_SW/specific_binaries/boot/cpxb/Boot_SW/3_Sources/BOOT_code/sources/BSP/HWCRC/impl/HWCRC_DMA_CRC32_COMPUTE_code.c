/* --------------------------------------------------------------------------
 *                           Sagem Defense Securite
 *                               SAFRAN Group
 * --------------------------------------------------------------------------
 * PROJECT : CHRONOS_MOCKUP
 * CSU name :
 * %name: HWCRC_DMA_CRC32_COMPUTE_code.c %
 * %full_name: fadex#1/csrc/HWCRC_DMA_CRC32_COMPUTE_code.c/1 %
 * DESCRIPTION : short description of the operations of the .c file
 *
 * Creation information:
 *   Created by: F073297
 *   Date : Thu Jan 31 16:48:21 CET 2019
 *
 * Modification information:
 *   %derived_by: F605763 %
 *   %date_created:Thu May 12 18:18:29 CEST 2022 %
 * --------------------------------------------------------------------------
 * SAGEM Defense Securite document. Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "HWCRC_CFEX_public.h"

/* ---------- include required interface: ----------------------------------- */
/* LPOS Common Interface */
/*  */
#include "CMN_TYPES_common.h"
#include "DMA_HAL_public.h"
#include "HWCRC_REG_common.h"

/* LPOS Public Interface */
#include "HWCRC_HAL_public.h"

/* LPOS Private Interface */
/* none */

/* ---------- internal define constants: ------------------------------------ */
#define BOOT_CRC_STOP_TEST   ((CMN_SYSTEM_TIME_t)(200*1000*1000/10))

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */

/* Used to transmit data */
void HWCRC_DMA_CRC32_COMPUTE ( uint32_t       const p_crc_start,
        				  CMN_IOSP_ID_t       const p_hwcrc_conf_id,
                          CMN_SYSTEM_ADDR_t   const p_buff_addr,
                          CMN_SYSTEM_SIZE_t   const p_buff_size,
                          CMN_SYSTEM_SIZE_t * const p_written_size,
                          uint32_t       * const p_crc32,
						  uint8_t        const p_crc_tempo
						)
{
   /* */
   /* Local variable definition */
   CMN_IOSP_ID_t       v_hwcrc_dma_conf_id;
   uint32_t            v_hwcrc_buff_data_nb;
   uint32_t            v_hwcrc_buff_data_size;
   ts_DMA_STATUS       v_hwcrc_dma_status;
   ts_DMA_PROG         v_hwcrc_dma_prog;
   uint32_t *          pt_hwcrc_write;
   uint32_t            v_hwcrc_dest_addr;
   uint32_t            v_crc_result;

   uint32_t v_i,v_j;

   ts_HWCRC_REG volatile * pt_hwcrc_reg_descr;
   v_crc_result = p_crc_start;

   /* */
   *p_written_size = 0ul;
   /* */
   v_hwcrc_dma_conf_id = HWCRC_CFEX_descriptor_tab[p_hwcrc_conf_id].s_dma_conf_nb;

   /* */
   v_hwcrc_buff_data_nb = (uint32_t)( p_buff_size / HWCRC_CFEX_DATA_SIZE );
   /* */
   v_hwcrc_buff_data_size = (uint32_t)( v_hwcrc_buff_data_nb * HWCRC_CFEX_DATA_SIZE );

   /* */
   if ( v_hwcrc_buff_data_nb > 0ul )
   {
      /* */
      DMA_CLEAR_DONE (0UL,e_CMN_FLAG_DO);
      /* */
      DMA_STATUS ( v_hwcrc_dma_conf_id, &v_hwcrc_dma_status );
      /* */
      if ( v_hwcrc_dma_status.s_cycle_count == v_hwcrc_dma_status.s_cycle_nb )
      {
         /* */
         /* >RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> The cast is safe. There is no loss of precision from (void*) to (uint32_t*). */
         pt_hwcrc_write = (uint32_t *)p_buff_addr;
         /* */
         v_hwcrc_dest_addr = HWCRC_CFEX_descriptor_tab[p_hwcrc_conf_id].s_address;

         /* Transfer code section */
         v_hwcrc_dma_prog.s_nb_byte_req    = v_hwcrc_buff_data_size;
         /* {{RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> The cast from (uint32_t *) to (uint32_t) is used to retrieve the value of the address itself. */
         v_hwcrc_dma_prog.s_src_addr       = (uint32_t)pt_hwcrc_write;
         v_hwcrc_dma_prog.s_src_last_addr  = (uint32_t)pt_hwcrc_write + (uint32_t)v_hwcrc_buff_data_size;
         /* }}<SYNCHRONe_C_Code_10.7,11.1> */
         v_hwcrc_dma_prog.s_src_off        = (uint16_t)HWCRC_CFEX_DATA_SIZE*4;
         v_hwcrc_dma_prog.s_dest_addr      = v_hwcrc_dest_addr+0x04;
         v_hwcrc_dma_prog.s_dest_last_addr = v_hwcrc_dest_addr+0x04;
         v_hwcrc_dma_prog.s_dest_off       = (uint16_t)0ul;
         v_hwcrc_dma_prog.s_nb_cycle       = 1;
         //v_hwcrc_dma_prog.s_nb_cycle       = ( (uint16_t)p_buff_size / (uint16_t)HWCRC_CFEX_DATA_SIZE);
         v_hwcrc_dma_prog.s_buff_type      = e_DMA_BUFFER_ONE_SHOT; /* One shot by default */

         /* */
         DMA_CFG ( v_hwcrc_dma_conf_id, &v_hwcrc_dma_prog);
         /* */
         pt_hwcrc_reg_descr = (ts_HWCRC_REG volatile *) v_hwcrc_dest_addr;
         HWCRC_INIT();
         pt_hwcrc_reg_descr->s_CRC_CSTAT = p_crc_start;
         /* */
         DMA_REQUEST ( v_hwcrc_dma_conf_id, e_CMN_FLAG_ACTIVATE);
         /* */
         /* ~4ms pour 1000000 iterations */
         /* ~200ms pour 5000000 iterations */
    	 DMA_STATUS ( v_hwcrc_dma_conf_id, &v_hwcrc_dma_status );
    	 if (p_crc_tempo != 0)
    	 {
    		 if (v_hwcrc_dma_status.s_read_done != 1)
    		 {
    			 /* ~169ms pour 4225000 iterations avec coeur 2 instr et data cache désactivé*/
    			 /* ~150ms pour 8450000 iterations avec coeur 0 instr et data cache activé*/
    			 /* ~169ms pour 8450000 iterations avec coeur 2 instr cache activé*/
    		     for (v_i=0; v_i < 6450000 ; v_i++)
    		     {
    		    	 v_j++;
    		     }
    		 }
        	 DMA_STATUS ( v_hwcrc_dma_conf_id, &v_hwcrc_dma_status );
			 while (v_hwcrc_dma_status.s_read_done != 1) {
				 DMA_STATUS ( v_hwcrc_dma_conf_id, &v_hwcrc_dma_status );
			 }
    	 }
    	 else {
             while (v_hwcrc_dma_status.s_read_done != 1) {
            	 DMA_STATUS ( v_hwcrc_dma_conf_id, &v_hwcrc_dma_status );
             }
    	 }

         /* */
	     v_crc_result = pt_hwcrc_reg_descr->s_CRC_OUTP ;
         /* */
	     *p_written_size = v_hwcrc_buff_data_size;
	     *p_crc32 = v_crc_result;

      }

   }
   /* else             */
   /* data number is 0 */
}

/* ---------- internal operation bodies: ------------------------------------ */
/* none */
