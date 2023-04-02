#ifndef _RAMBOOT_CONFIGURE_ELBC_
#define _RAMBOOT_CONFIGURE_ELBC_

#include "LIBBSP_CCSR.h"

#define C_RAMBOOT_CCSR_ELBC_LBCR_ADDRESS  (uint32_t)(C_LIBBSP_CCSR_ELBC + 0xD0ul)
#define C_RAMBOOT_CCSR_ELBC_LCRR_ADDRESS  (uint32_t)(C_LIBBSP_CCSR_ELBC + 0xD4ul)

#define C_RAMBOOT_CCSR_ELBC_OFFSET        0x08ul
#define C_RAMBOOT_CCSR_ELBC_BR_OFFSET     0x00ul
#define C_RAMBOOT_CCSR_ELBC_OR_OFFSET     0x04ul

typedef union
{
   struct
   {
     uint32_t LDIS     :  1;   /* Local bus disable */
     uint32_t          :  7;
     uint32_t BCTLC    :  2;   /* Defines the use of LBCTL */
     uint32_t AHD      :  1;   /* Address hold disable */
     uint32_t          :  1;
     uint32_t ABSWP    :  1;   /* Address byte swap for 16-bit port size */
     uint32_t AS16     :  1;   /* Address shift for 16-bit port size */
     uint32_t LPBSE    :  1;   /* Enables parity byte select */
     uint32_t EPAR     :  1;   /* Determines odd or even parity */
     uint32_t BMT      :  8;   /* Bus monitor timing */
     uint32_t          :  4;
     uint32_t BMTPS    :  4;   /* Bus monitor timer prescale */
   } Fields;
   uint32_t Value;
} tu_eLBC_LBCR;

typedef union
{
   struct
   {
     uint32_t PBYP   :  1;   /* bit 0 must remain set for proper operation */
     uint32_t        :  13;
     uint32_t EADC   :  2;   /* External address delay cycles of LCLK */
     uint32_t        :  11;
     uint32_t CLKDIV :  5;   /* Clock divider */
   } Fields;
   uint32_t Value;
} tu_eLBC_LCRR;

typedef union
{
   struct
   {
     uint32_t BA   :  17;  /* Base address */
     uint32_t      :  2;
     uint32_t PS   :  2;   /* Port size */
     uint32_t DECC :  2;   /* Specifies the method for data error checking */
     uint32_t WP   :  1;   /* Write protect */
     uint32_t MSEL :  3;   /* Machine select */
     uint32_t      :  1;
     uint32_t      :  2;
     uint32_t      :  1;
     uint32_t V    :  1;   /* Valid bit */
   } Fields;
   uint32_t Value;
} tu_eLBC_BRn;

typedef union
{
   struct
   {
     uint32_t AM       :  17;  /* GPCM address mask */
     uint32_t          :  2;
     uint32_t BCTLD    :  1;   /* Buffer control disable */
     uint32_t CSNT     :  1;   /* Chip select negation time */
     uint32_t ACS      :  2;   /* Address to chip-select setup */
     uint32_t XACS     :  1;   /* Extra address to chip-select setup */
     uint32_t SCY      :  4;   /* Cycle length in bus clocks */
     uint32_t SETA     :  1;   /* External address termination */
     uint32_t TRLX     :  1;   /* Timing relaxed */
     uint32_t EHTR     :  1;   /* Extended hold time on read accesses */
     uint32_t EAD      :  1;   /* External address latch delay */
   } Fields;
   uint32_t Value;
} tu_eLBC_ORn;

typedef struct
{
   tu_eLBC_BRn  BR;
   tu_eLBC_ORn  OR;
} ts_eLBC_Config;

void RAMBOOT_ConfigureELBC(void);

#endif