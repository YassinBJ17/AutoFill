/* --------------------------------------------------------------------------
 *                           Sagem Defense Securite
 *                               SAFRAN Group
 * --------------------------------------------------------------------------
 * PROJECT : CHRONOS_MOCKUP
 * CSU name :
 * %name: HWCRC_CRC32_COMPUTE_code.c %
 * %full_name: fadex#1/csrc/HWCRC_CRC32_COMPUTE_code.c/1 %
 * DESCRIPTION : short description of the operations of the .c file
 *
 * Creation information:
 *   Created by: F073297
 *   Date : Thu May 31 09:55:01 CEST 2018
 *
 * Modification information:
 *   %derived_by: F605763 %
 *   %date_created:Thu May 12 18:18:29 CEST 2022 %
 * --------------------------------------------------------------------------
 * SAGEM Defense Securite document. Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
/* ---------- include provided interface: ----------------------------------- */
#include "HWCRC_CFEX_public.h"

/* ---------- include required interface: ----------------------------------- */
/* LPOS Common Interface */
/*  */
//#include "CMN_TYPES_common.h"
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
/* none */

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* */

/* Used to read the status dma */

void HWCRC_CRC32_COMPUTE( uint32_t         const p_crc_start,
                          uint32_t  const * const p_buf,
                          uint32_t         const p_size,
                          uint32_t       * const p_crc32 )
{
	   /* */
	   /* Local variables declaration */
	     uint32_t v_i;
	     uint32_t v_crc_result;
	     const uint32_t *pt_area_start;
	     /*const uint8_t TextString1[] = "0123456789";*/

	     /* Local Variables Initialization */
	     ts_HWCRC_REG volatile * pt_hwcrc_reg_descr = (ts_HWCRC_REG volatile *) HWCRC_1_BASE_ADDR;
	     v_crc_result = p_crc_start;
	     pt_area_start = p_buf;

	     /* CRC computation on the memory area excluding the CRC itself */
	     pt_hwcrc_reg_descr->s_CRC_CSTAT = p_crc_start;

	     for(v_i = 0UL ; v_i < p_size ; v_i++)
	     {
	    	 pt_hwcrc_reg_descr->s_CRC_INP = *pt_area_start;
	         pt_area_start++;
	     }
	     v_crc_result = pt_hwcrc_reg_descr->s_CRC_OUTP ;

	     *p_crc32 = v_crc_result;

	     /*pt_hwcrc_reg_descr->s_CRC_CFG.u_R = 0x7; //idem https://simplycalc.com/crc32-text.php
	     pt_hwcrc_reg_descr->s_CRC_CSTAT = 0xFFFFFFFF;
	     for(v_i = 0UL ; v_i < sizeof(TextString1)-1 ; v_i++)
	    		*(uint8_t*)&pt_hwcrc_reg_descr->s_CRC_INP = TextString1[v_i];*/
}

/* ---------- internal operation bodies: ------------------------------------ */
/* none */
