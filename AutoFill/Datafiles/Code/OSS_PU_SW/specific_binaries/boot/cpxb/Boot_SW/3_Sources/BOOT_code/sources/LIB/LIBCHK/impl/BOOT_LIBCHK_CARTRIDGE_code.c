/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function verify the integrity of a given software
 *               (checksum 32 and CRC 32).
 * -------------------------------------------------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "BOOT_LIBCHK_public.h"
#include "LIB_CHKSUM_internal.h"

#include "DMA_HAL_public.h"
#include "HWCRC_HAL_public.h"
/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- provided data: ------------------------------------------------ */
TS_LIB_CHKSUM_CRC_Registers * v_LIB_CHKSUM_CRC_Registers;

/* ---------- provided operations: ------------------------------------------- */
/* Implements REQ_[User Project Name]_BOOT-LLR_001 */
te_CMN_FLAG_VALIDITY BOOT_LIBCHK_CARTRIDGE ( const ts_SAFRAN_HEADER * const p_cartridge,
                                             uint32_t const p_startMemoryArea,
                                             uint32_t const p_endMemoryArea )
{
   te_CMN_FLAG_VALIDITY v_ret;

   /* Local Variables used for CRC 32 check*/
   uint32_t v_sw_length_1;
   uint32_t v_sw_length_2;
   uint32_t v_address_after_crc;
   uint32_t v_result;

   /* check integrity of the cartridge */
   /* the end written in the cartridge is before the start   */
   if ( ( p_cartridge->s_end_code <= p_cartridge->s_start_code ) || ( p_cartridge->s_start_code < p_startMemoryArea )
        || ( p_cartridge->s_end_code > p_endMemoryArea ) || ( p_cartridge->s_checksum_32 == 0UL )
        || ( p_cartridge->s_crc_32 == 0UL ) )
   {
      v_ret = e_CMN_FLAG_NOT_VALID;
   }
   else
   {
      /*****     Check of the CRC 32     *****/
      /* {{RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1>: The computations are safe. Indeed, the memory area*/
      /* area is organized like */
      /* followed : 1.Cartridge 2.Software Code. The start code gives the address of the cartridge. The if above */
      /* and the structure of the cartridge prevent from overflows in the following computations */
      /* (s_start_code < &s_crc_32 < &s_crc_32_cplt < v_address_after_crc < s_end_code) */
      /* Only memory addresses are manipulated here. */

      v_address_after_crc = (uint32_t)( &( p_cartridge->s_crc_32_cplt ) ) + (uint32_t)sizeof(uint32_t);

      /* Define the software first memory area length (for CRC computation) */
      v_sw_length_1 = ( (uint32_t)&( p_cartridge->s_crc_32 ) - (uint32_t)p_cartridge->s_start_code );

      /* Define the software second memory area length (for CRC computation) */
      v_sw_length_2 = ( p_cartridge->s_end_code - v_address_after_crc ) + 1UL;

      /* }}<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> */

      /* -------------------------------------------------------------------------- */
      /* Hardware Computation with DMA                                              */
      /* -------------------------------------------------------------------------- */


      /* Module CRC / eDMA Lib check integrity of the cartridge */
      DMA_INIT ();

      /* Set CRC hardware module 0 base address */
      v_LIB_CHKSUM_CRC_Registers = (TS_LIB_CHKSUM_CRC_Registers *)( BOOT_HW_CRC_0_BASE_ADDR );

      /* Set CRC_CFG config */
      v_LIB_CHKSUM_CRC_Registers->CRC_CFG = (uint32_t)K_LIB_CHKSUM_CRC_SWAP_BIT_WISE;

      /* Set seed value */
      v_LIB_CHKSUM_CRC_Registers->CRC_CSTAT = K_LIB_CHKSUM_CRC_SEED_VALUE;

      /* Compute CRC with hardware module CRC_0 */
      /* !!!! DO NOT DIVIDE LENGTH BY 4 AS THE TRANSFER TO DMA IS IN BYTES !!!! */
      BOOT_LIBCHK_CRC_HwDmaComputation32 ( (const uint32_t *)p_cartridge->s_start_code,
                                            v_sw_length_1,
                                            (const uint32_t *)v_address_after_crc,
                                            v_sw_length_2,
                                            &v_result);

      if ( v_result != p_cartridge->s_crc_32 )
      {
         v_ret = e_CMN_FLAG_NOT_VALID ;
      }
      else
      {
         v_ret = e_CMN_FLAG_VALID ;
      }

   }

   return v_ret;
}
