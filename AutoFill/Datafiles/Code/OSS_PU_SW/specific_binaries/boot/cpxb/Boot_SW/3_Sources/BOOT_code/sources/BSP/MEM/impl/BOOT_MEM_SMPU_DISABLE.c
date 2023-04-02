#include "BOOT_MEM_public.h"
#include "BOOT_MAIN_public.h"
#include "BOOT_CONF_public.h"

 void BOOT_MEM_SMPU_DISABLE (void) {    pt_smpu_reg->s_SMPU_CESR0 = (reg32_t)SMPU_CESR0_DIS; }
