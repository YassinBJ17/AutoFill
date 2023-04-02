#ifndef _ELBCBOOT_CBHW_CONFIGURE_LAW_
#define _ELBCBOOT_CBHW_CONFIGURE_LAW_

#include "LIBBSP_CCSR.h"

#define C_ELBCBOOT_CCSR_LAW            (uint32_t)(C_LIBBSP_CCSR_LAW)

#define C_ELBCBOOT_CCSR_LAW_OFFSET     0x20ul
#define C_ELBCBOOT_CCSR_LAW_BAR_OFFSET 0x08ul
#define C_ELBCBOOT_CCSR_LAW_AR_OFFSET  0x10ul

typedef union
{
   struct
   {
      uint32_t             :  8;
      uint32_t BASE_ADDR   :  24;
   } Fields;
   uint32_t Value;
} tu_LAW_LAWBARn;

typedef union
{
   struct
   {
      uint32_t EN    :  1;
      uint32_t       :  6;
      uint32_t TRGT  :  5;
      uint32_t       :  14;
      uint32_t SIZE  :  6;
   } Fields;
   uint32_t Value;
} tu_LAW_LAWARn;

typedef struct
{
   tu_LAW_LAWBARn LAWBAR;
   tu_LAW_LAWARn  LAWAR;
} ts_LAW_Config;

void ELBCBOOT_CBHW_ConfigureLAW(void);

#endif