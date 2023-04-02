#include "BOOT_MC_public.h"
#include "BOOT_RESET_public.h"
#include "BOOT_MAIN_public.h"
#include "BOOT_MAIN_private.h"
#include "BOOT_CONF_public.h"

    for ( v_core_nb = 0ul ; v_core_nb < (uint32_t) e_CORE_NB ; v_core_nb++ )    {       v_core_mode = c_CONF_MODES[V_BOOT_MAIN_Cores_Running_Mode].s_cores_config[v_core_nb].s_mode;       switch (v_core_mode)       {          case e_CORE_RESET :          {             v_RMC_val = e_CMN_FLAG_YES ;             v_cctl_val = MC_CCTL_CORE_RUNNING_VAL;             v_boot_addr = (uint32_t)ENTRYPOINT_INIT_ADDR_tab[v_core_nb];          }          break;          case e_CORE_DESACTIVATE:          default:          {             v_RMC_val = e_CMN_FLAG_NO ;             v_cctl_val = MC_CCTL_CORE_DIS_VAL;             v_boot_addr = NULL_ADDRESS;          }          break;       }       BOOT_MC_SET_CONF( v_core_nb ,                         (void*)v_boot_addr ,                         v_RMC_val ,                         v_cctl_val  ) ;    }
