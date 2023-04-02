#include "BOOT_MC_REG_public.h"
#include "BOOT_BIST_public.h"
#include "BOOT_PINOUT_public.h"
#include "BOOT_PBRIDGE_public.h"
#include "BOOT_PLL_REG_public.h"
#include "BOOT_MEM_public.h"

 void BOOT_MC_BIST_CORE_RST_ADDR(void) {    ts_MC_ME_REG volatile*  pt_mc_me_reg  = (ts_MC_ME_REG volatile*) MC_ME_BASE_ADDR;    ts_SIUL2_tag volatile*  pt_gpio_reg   = (ts_SIUL2_tag volatile*) SIUL2_BASE_ADDR;     if(pt_gpio_reg->s_MIDR1 & 0x10){            pt_mc_me_reg->s_MC_ME_CADDR[1] = 0x01200001;      pt_mc_me_reg->s_MC_ME_CADDR[2] = 0x00000001;      pt_mc_me_reg->s_MC_ME_CADDR[3] = 0x01400001;      pt_mc_me_reg->s_MC_ME_CADDR[4] = 0x01040001;       }else{    pt_mc_me_reg->s_MC_ME_CADDR[1] = 0x01010001;      pt_mc_me_reg->s_MC_ME_CADDR[2] = 0x01010001;      pt_mc_me_reg->s_MC_ME_CADDR[3] = 0x01014001;      pt_mc_me_reg->s_MC_ME_CADDR[4] = 0x01014001;       } }
