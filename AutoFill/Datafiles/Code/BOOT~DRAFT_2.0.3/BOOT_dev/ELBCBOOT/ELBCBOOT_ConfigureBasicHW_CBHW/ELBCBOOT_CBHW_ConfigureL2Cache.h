#ifndef _ELBCBOOT_CBHW_CONFIGURE_L2_CACHE_
#define _ELBCBOOT_CBHW_CONFIGURE_L2_CACHE_

#include "LIBBSP_CCSR.h"

#define C_CCSR_L2_CACHE_L2CTL_ADDRESS       (uint32_t)(C_LIBBSP_CCSR_ECCMEM_L2S + 0x0000ul)
#define C_CCSR_L2_CACHE_L2SRBAR0_ADDRESS    (uint32_t)(C_LIBBSP_CCSR_ECCMEM_L2S + 0x0100ul)
#define C_CCSR_L2_CACHE_L2ERRDIS_ADDRESS    (uint32_t)(C_LIBBSP_CCSR_ECCMEM_L2S + 0x0E44ul)

typedef union
{
   struct
   {
      uint32_t L2E         :  1; /* L2 enable */
      uint32_t L2I         :  1; /* L2 flash invalidate */
      uint32_t L2SIZ       :  2; /* L2 SRAM size (read only) */
      uint32_t             :  5;
      uint32_t L2DO        :  1; /* L2 data-only */
      uint32_t L2IO        :  1; /* L2 instruction-only */
      uint32_t             :  1;
      uint32_t L2INTDIS    :  1; /* Cache read intervention disable */
      uint32_t L2SRAM      :  3; /* L2 SRAM configuration */
      uint32_t             :  2;
      uint32_t L2LO        :  1; /* L2 cache lock overflow */
      uint32_t L2SLC       :  1; /* L2 snoop lock clear */
      uint32_t             :  1;
      uint32_t L2LFR       :  1; /* L2 cache lock bits flash reset */
      uint32_t L2LFRID     :  2; /* L2 cache lock bits flash reset select instruction or data */
      uint32_t             :  4;
      uint32_t L2STASHDIS  :  1; /* L2 stash allocate disable */
      uint32_t             :  1;
      uint32_t L2STASHCTL  :  2; /* L2 stash configuration */
   } Fields;
   uint32_t Value;
} tu_L2_Cache_L2CTL;

typedef union
{
   struct
   {
      uint32_t ADDR  :  18;    /* SRAM base address */
      uint32_t       :  14;
   } Fields;
   uint32_t Value;
} tu_L2_Cache_L2SRBARn;

typedef union
{
   struct
   {
      uint32_t          :  27;
      uint32_t TPARDIS  :  1; /* Tag parity error disable */
      uint32_t MBECCDIS :  1; /* Multiple-bit ECC error disable */
      uint32_t SBECCDIS :  1; /* Single-bit ECC error disable */
      uint32_t          :  1;
      uint32_t L2CFGDIS :  1; /* L2 configuration error disable */
   } Fields;
   uint32_t Value;
} tu_L2_Cache_L2ERRDIS;

void ELBCBOOT_CBHW_ConfigureL2Cache(void);

#endif