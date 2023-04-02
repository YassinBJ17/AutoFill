/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function configure each core behaviour.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_MC_public.h"
#include "BOOT_RESET_public.h"
#include "BOOT_MAIN_public.h"
#include "BOOT_MAIN_private.h"
#include "BOOT_CONF_public.h"

/* ---------- internal define constants: ------------------------------------ */
#define NULL_ADDRESS 0ul

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
const CMN_SYSTEM_ADDR_t ENTRYPOINT_INIT_ADDR_tab[e_CORE_NB] =
{
   &BOOT_RESET_CORE_2 ,   /* CORE_2 */
   &BOOT_RESET_CORE_0 ,   /* CORE_0 */
   &BOOT_RESET_CORE_0 ,   /* CORE_CHK */
   &BOOT_RESET_CORE_1 ,   /* CORE_1 */
};

uint32_t V_BOOT_MAIN_Cores_Running_Mode;

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_[User Project Name]_BOOT-LLR_003 */
void BOOT_MAIN_ENTRYPOINT_INIT( void )
{
   uint32_t v_core_nb ;
   te_CMN_FLAG_QUESTION v_RMC_val ;
   uint16_t v_cctl_val ;
   uint32_t v_boot_addr ;
   te_MAIN_CORE_MODE v_core_mode;

   V_BOOT_MAIN_Cores_Running_Mode = BOOT_CONF_MODE_SELECT();


   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe : conversion the enum e_CORE_NB=4 to uint32_t */
   /* There is no loss of precision. */
   for ( v_core_nb = 0ul ; v_core_nb < (uint32_t) e_CORE_NB ; v_core_nb++ )
   {
      /* Get the core configuration for the selected mode */
      v_core_mode = c_CONF_MODES[V_BOOT_MAIN_Cores_Running_Mode].s_cores_config[v_core_nb].s_mode;

      switch (v_core_mode)
      {
         case e_CORE_RESET :
         {
            v_RMC_val = e_CMN_FLAG_YES ;
            v_cctl_val = MC_CCTL_CORE_RUNNING_VAL;
            /* >RELAX<SYNCHRONe_C_Code_11.1> The cast is safe : conversion of a function pointer (void*) to an*/
            /* address uint32_t */
            v_boot_addr = (uint32_t)ENTRYPOINT_INIT_ADDR_tab[v_core_nb];
         }
         break;

         case e_CORE_DESACTIVATE:
         default:
         {
            v_RMC_val = e_CMN_FLAG_NO ;
            v_cctl_val = MC_CCTL_CORE_DIS_VAL;
            v_boot_addr = NULL_ADDRESS;
         }
         break;
      }

      BOOT_MC_SET_CONF( v_core_nb ,
                        (void*)v_boot_addr ,
                        v_RMC_val ,
                        v_cctl_val  ) ;

   }

}

/* ---------- internal operation bodies: ------------------------------------ */
/* none */
