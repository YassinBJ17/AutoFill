#include "BOOT_LIBTIME_public.h"
#include "BOOT_GPIO_HAL_public.h"
#include "BOOT_GPIO_REG_common.h"
#include "BOOT_FCCU_public.h"
#include "BOOT_INTC_public.h"
#include "BOOT_MEM_public.h"
#include "BOOT_PBRIDGE_public.h"
#include "BOOT_PINOUT_public.h"
#include "BOOT_XBAR_public.h"
#include "BOOT_MAIN_private.h"

 void BOOT_MAIN_PERIPH_INIT( void ) {    volatile uint32_t *pt_opacrb = (volatile uint32_t *)(PBRIDGE_OPACRB_BASE_ADDR);    volatile uint32_t *pt_siul2_reg_prot = (volatile uint32_t *)(SIUL2_REG_PROT_GCR_ADDR);    BOOT_LIBTIME_INIT();    BOOT_PBRIDGE_INIT();    BOOT_XBAR_INIT();    *pt_opacrb &= ~(PBRIDGE_OPACRB_VAL);    *pt_siul2_reg_prot = SIUL2_REG_PROT_VAL;    BOOT_GPIO_INIT();    BOOT_PINOUT_INIT();    BOOT_MEM_EBI_INIT();    BOOT_INTC_INIT();    BOOT_FCCU_INIT(); }
