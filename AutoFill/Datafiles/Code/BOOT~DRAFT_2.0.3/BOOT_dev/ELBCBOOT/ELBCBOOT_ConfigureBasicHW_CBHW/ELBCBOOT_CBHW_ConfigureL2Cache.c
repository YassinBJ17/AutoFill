#include "ELBCBOOT_CBHW_ConfigureL2Cache.h"
#include "LIBMCP_Types.h"

#define C_CCSR_L2_CACHE_L2SRBAR0_ADDR  0x20000000ul

const tu_L2_Cache_L2CTL L2_Cache_L2CTL =
{
   {
      1, /* The L2 SRAM (cache or memory-mapped SRAM) is enabled. */
      1,
      0,
      0,
      0,
      0,
      1, /* Entire array is a single SRAM */
      0,
      0,
      0,
      0,
      0,
      0
   }
};

const tu_L2_Cache_L2SRBARn L2_Cache_L2SRBARn =
{
   {
      C_CCSR_L2_CACHE_L2SRBAR0_ADDR >> 14
   }
};

const tu_L2_Cache_L2ERRDIS L2_Cache_L2ERRDIS =
{
   {
      0,
      1, /* Multiple-bit ECC error detection disabled */
      1, /* Single-bit ECC error detection disabled */
      0
   }
};

void ELBCBOOT_CBHW_ConfigureL2Cache(void)
{
   uint32_t v_regAddr;
   volatile uint32_t v_L2CTL;

   asm("mbar");
   asm("isync");
   v_regAddr = C_CCSR_L2_CACHE_L2CTL_ADDRESS;
   *((volatile uint32_t *)v_regAddr) = L2_Cache_L2CTL.Value;
   v_L2CTL = *((volatile uint32_t *)v_regAddr);
   asm("mbar");
   v_regAddr = C_CCSR_L2_CACHE_L2SRBAR0_ADDRESS;
   *((volatile uint32_t *)v_regAddr) = L2_Cache_L2SRBARn.Value;
   v_regAddr = C_CCSR_L2_CACHE_L2ERRDIS_ADDRESS;
   *((volatile uint32_t *)v_regAddr) = L2_Cache_L2ERRDIS.Value;
}