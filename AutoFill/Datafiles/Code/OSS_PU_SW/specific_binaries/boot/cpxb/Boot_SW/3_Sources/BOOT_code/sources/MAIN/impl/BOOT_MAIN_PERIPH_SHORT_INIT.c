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

 void BOOT_MAIN_PERIPH_SHORT_INIT(void) {    BOOT_PINOUT_INIT();    BOOT_MEM_EBI_INIT();    BOOT_GPIO_INIT(); }
