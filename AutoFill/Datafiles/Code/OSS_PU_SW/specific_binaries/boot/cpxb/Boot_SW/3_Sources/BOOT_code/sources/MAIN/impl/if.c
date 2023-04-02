#include "BOOT_MEM_public.h"
#include "BOOT_RESET_public.h"
#include "BOOT_MAIN_public.h"
#include "BOOT_MAIN_private.h"
#include "BOOT_CONF_public.h"
#include "BOOT_MC_public.h"
#include "BOOT_PBIT_public.h"
#include "BOOT_RESET_public.h"

    if( SEMA42_GATE0 != (uint8_t)0 || SEMA42_GATE1 != (uint8_t)0 )    {       while(SEMA42_GATE1 == (uint8_t)0);       while(SEMA42_GATE1 != (uint8_t)0);    }
