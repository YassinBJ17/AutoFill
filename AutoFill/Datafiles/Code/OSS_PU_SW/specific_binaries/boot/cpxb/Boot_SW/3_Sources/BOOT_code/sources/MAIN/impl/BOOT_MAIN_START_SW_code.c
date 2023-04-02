/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function starts the platform software on the current
 *               core.
 * -------------------------------------------------------------------------- */


/* ---------- include required interface: ----------------------------------- */
#include "BOOT_MEM_public.h"
#include "BOOT_RESET_public.h"
#include "BOOT_MAIN_public.h"
#include "BOOT_MAIN_private.h"
#include "BOOT_CONF_public.h"
#include "BOOT_MC_public.h"
#include "BOOT_PBIT_public.h"
#include "BOOT_RESET_public.h"

/* ---------- internal define constants: ------------------------------------ */
#define SEMA42_GATE0 (*(reg8_t*)(0xFC03C000))
#define SEMA42_GATE1 (*(reg8_t*)(0xFC03C001))

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
const uint8_t c_corenb_lookuptable[e_CORE_NB] =
{
   2,    /* peripheral core_2 */
   0,    /* main core_0 */
   3,    /* checker core_0 */
   1,    /* main core_1 */
};
/* none */

/* ---------- provided operations: ------------------------------------------- */

/* Implements REQ_[User Project Name]_BOOT-LLR_089 */
void BOOT_MAIN_START_SW( uint32_t const p_numcore )
{
   /* Get SPEFSCR configuration for the current mode */
   const uint32_t c_FP_cfg = c_CONF_MODES[V_BOOT_MAIN_Cores_Running_Mode].s_FP_config;
   const uint8_t c_lock_value = c_corenb_lookuptable[p_numcore] + ((uint8_t)1);

   /* Get the SW entrypoint for the running core in the current mode */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe : from address (uint32_t) to pointer (on void) */
   const CMN_SYSTEM_ADDR_t c_SW_addr = 
   (CMN_SYSTEM_ADDR_t) c_CONF_MODES[V_BOOT_MAIN_Cores_Running_Mode].s_cores_config[p_numcore].s_addr_sw;

   /* {{RELAX<SYNCHRONe_C_Code_10.7> The casts are safe. All operations are between two unsigned 8-bits */
   /* words (SEMA42_GATE0 and c_lock_value or (uint8_t)0) */
   do
   {
      /* Try to lock the gate */
      SEMA42_GATE0 = c_lock_value;
   }
   while ( (SEMA42_GATE0) != c_lock_value );
   /* The semaphore has been locked */

   /* Launch the PBIT on CMPU */
   BOOT_PBIT_CMPU( p_numcore );

   /* unlock the gate */
   SEMA42_GATE0 = (uint8_t)0;
   /* }}<SYNCHRONe_C_Code_10.7> */

   /* Activates ECC on SRAM*/
   BOOT_MEM_ECC_CONFIG( SRAM_ECC_ON_VALUE );

   /* do the initialisation for RUN */
   BOOT_MEM_CMPU_CONFIG(e_MPU_DIS_VAL);

   /* Configure the SMPU for the run mode */

   BOOT_RESET_SET_SPEFSCR(c_FP_cfg);

   /* If the current executing core is the last one, */
   if ( SEMA42_GATE0 == (uint8_t)0 )
   {
      /* Lock the semaphore SEMA42_GATE1 */
      SEMA42_GATE1 = c_lock_value;

      /* Configure the SMPU for the run mode */
      BOOT_MEM_SMPU_CONFIG();

      /* Erase all xMEMs */
      BOOT_MEM_LRAM_INIT();

      /* unlock the semaphore SEMA42_GATE1 */
      SEMA42_GATE1 = (uint8_t)0;
   }

   /* If the current core is not alone and is not the last one */
   /* Condition 1 :
    *     SEMA42_GATE0 != (uint8_t)0 indicates that several cores are running. */
   /*     Indeed, when the condition is assessed by the current core, if another core was running, */
   /*     it would lock the semaphore SEMA42_GATE0 */
   /* Condition 2 :
   /*     SEMA42_GATE1 != (uint8_t)0 indicates that the current core is not the last one */
   if( SEMA42_GATE0 != (uint8_t)0 || SEMA42_GATE1 != (uint8_t)0 )
   {
      /* Several cores are running, wait the slowest core */
      /* wait that the last core locks the semaphore SEMA42_GATE1 to initialize the xMEMs */
      while(SEMA42_GATE1 == (uint8_t)0);
      /* wait that the last core unlocks the semaphore (it indicates that the initialization of the xMEMs is ended) */
      while(SEMA42_GATE1 != (uint8_t)0);
   }

   /* Clean all registers and launch the next software */
   BOOT_MAIN_LAUNCH_SOFTWARE(c_SW_addr);
}
