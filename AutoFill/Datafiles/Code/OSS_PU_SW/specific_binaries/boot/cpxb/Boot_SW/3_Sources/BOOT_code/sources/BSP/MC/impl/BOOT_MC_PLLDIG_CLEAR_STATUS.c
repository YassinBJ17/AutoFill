#include "BOOT_MC_public.h"
#include "BOOT_MC_REG_public.h"
#include "BOOT_PLL_REG_public.h"

 void BOOT_MC_PLLDIG_CLEAR_STATUS( void ) {    PLLDIG_REGS.s_PLLDIG_PLL0SR = (reg32_t)PLLDIG_PLL0SR_LOLF_CLR;    PLLDIG_REGS.s_PLLDIG_PLL1SR = (reg32_t)PLLDIG_PLL1SR_LOLF_CLR; }
