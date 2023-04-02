#ifndef _BOOT_TCAHW_MMU_CONFIGURATION_
#define _BOOT_TCAHW_MMU_CONFIGURATION_

#include "LIBMCP_Types.h"

typedef struct
{
   uint32_t mas0;
   uint32_t mas1;
   uint32_t mas2;
   uint32_t mas3;
   uint32_t mas7;
} ts_MAS_Registers;

typedef struct
{
   /* MAS0 */
   uint32_t           :  2; /* 2 bit padding */
   uint32_t tlbsel    :  2; /* Select TLB for access (always 01) */
   uint32_t           :  7; /* 7 bits padding */
   uint32_t esel      :  5; /* Entry select for TLB1 */
   uint32_t           : 11; /* 11 bits padding */
   uint32_t nv        :  5; /* Next replacement victim for TLB1 */
   /* MAS1 */
   uint32_t valid     :  1; /* TLB entry valid */
   uint32_t iprot     :  1; /* Invalidation protect */
   uint32_t           :  6; /* 6 padding bits */
   uint32_t tid       :  8; /* Translation ID bits */
   uint32_t           :  3; /* 3 padding bits */
   uint32_t ts        :  1; /* Translation address space */
   uint32_t tsize     :  4; /* Entry page size */
   uint32_t           :  8; /* 8 padding bits */
   /* MAS2 */
   uint32_t epn       : 20; /* Effective page number */
   uint32_t           :  6; /* 6 padding bits */
   uint32_t vle       :  1; /* Power Architecture VLE */
   uint32_t w         :  1; /* Write-through */
   uint32_t i         :  1; /* Caching-inhibited */
   uint32_t m         :  1; /* Memory-coherency required */
   uint32_t g         :  1; /* Guarded */
   uint32_t e         :  1; /* Endianness */
   /* MAS3 */
   uint32_t rpn       : 20; /* Real page number */
   uint32_t           :  2; /* 2 bits padding */
   uint32_t userBits  :  4; /* User bits (U0, U1, U2, U3) */
   uint32_t ux        :  1; /* Permission bits: user execute */
   uint32_t sx        :  1; /* Permission bits: superviser execute */
   uint32_t uw        :  1; /* Permission bits: user write */
   uint32_t sw        :  1; /* Permission bits: superviser write */
   uint32_t ur        :  1; /* Permission bits: user read */
   uint32_t sr        :  1; /* Permission bits: superviser read */
   /* MAS7 */
   uint32_t           : 28; /* 28 padding bits */
   uint32_t rpn_h     :  4; /* 4 high order bits of rpn */
} ts_MAS_Fields;

typedef union
{
   ts_MAS_Fields MAS_Fields;
   ts_MAS_Registers MAS_Registers;
} ts_TLB_Config;

extern const ts_TLB_Config L2SRAM_TLB_Conf;
extern const ts_TLB_Config MMU_PBIT_RO_ZoneTLB_Conf;
extern const ts_TLB_Config MMU_PBIT_DIS_ZoneTLB_Conf;
extern const ts_TLB_Config MMU_PBIT_MIN_ZoneTLB_Conf;
extern const ts_TLB_Config SDRAM_TLB_Conf;
extern const ts_TLB_Config CCSR_TLB_Conf;
extern const ts_TLB_Config MEGATICE_PLD_TLB_Conf;
extern const ts_TLB_Config COMPAGNON_PLD_TLB_Conf;
extern const ts_TLB_Config COMPAGNON_RAM_TLB_Conf;

extern void REG_WriteTlbEntry(uint32_t mas0, uint32_t mas1, uint32_t mas2, uint32_t mas3, uint32_t mas7);

#endif