#ifndef BOOT_MAIN_public_H
#define BOOT_MAIN_public_H

/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

/* ---------- include  ------------------------------------------------------ */
#include "CMN_TYPES_common.h"
#include "BOOT_MEM_public.h"

/* ---------- external define constants: ------------------------------------ */

/* Comment the following line if you want to use ASTERIOS K19.2 */
//#define ASTERIOS_K193

/* ---------- external types: ----------------------------------------------- */

typedef struct
{
   const uint32_t s_validity_flag_addr;
   /* Runtime entry point address */
   const uint32_t s_Runtime_addr_conf;
#ifdef ASTERIOS_K193
   /* Fiel to disable the profiling feature at run time */
   const uint32_t s_disable_profiling_conf;
   /* Pointer to the Handler of Errors belonging to the `early` Category */
   const uint32_t s_early_error_handler_addr_conf;
   /* Number of cores running ASTERIOS */
   const uint32_t s_nb_cores_conf;
   /* List of cores running of ASTERIOS */
   const uint32_t s_cores_conf[3];
#endif
}
ts_MAIN_ASTERIOS_RUNTIME_CONF;

typedef enum
{
   e_CORE_DESACTIVATE,
   e_CORE_RESET,
   e_CORE_CONTINUE
} te_MAIN_CORE_MODE;

/* same order than the MPC5777M register ; see chapter 65.3 */
typedef enum
{
   e_CORE_2,    /* peripheral core_2 */
   e_CORE_0,    /* main core_0 */
   e_CORE_CHK,  /* checker core_0 */
   e_CORE_1,    /* main core_1 */
   e_CORE_NB
} te_MAIN_CORE;

typedef enum
{
   e_MODE_CHOICE_ASTERIOS = 0,
   e_MODE_CHOICE_DTLD,
   e_MODE_NB
} te_FUNCTIONAL_MODE;

typedef struct
{
   te_MAIN_CORE_MODE s_mode;
   /* cpu entry point */
   CMN_SYSTEM_ADDR_VAL_t s_addr_sw;
}
ts_MAIN_ENTRY_POINT_ELT;

typedef ts_MAIN_ENTRY_POINT_ELT MAIN_CORE_CONFIG_t[e_CORE_NB];

typedef struct
{
   /* SMPU Configuration */
   const ts_SMPU_CONF       s_smpu_config;
   /* Cores configuration */
   const MAIN_CORE_CONFIG_t      s_cores_config;
   /* Floating-Point configuration */
   const uint32_t                s_FP_config;
   /* Indicate if ASTERIOS is launched in the mode */
   /* Number of software to verify for the mode*/
   /* Address of Mode software table (type of the table is ts_CONF_SW, size is s_sw_nb) */

}
ts_MAIN_MODE_ELT;

/* ---------- external operations: ------------------------------------------ */
/* none */

/* ---------- external datas: ----------------------------------------------- */
/*Mode selected and index of table c_CONF_CORE_CFG_TAB*/
extern uint32_t V_BOOT_MAIN_Cores_Running_Mode;

/* ---------- external constants: ------------------------------------------- */

/* ---------- provided operations: ------------------------------------------- */

extern void BOOT_MAIN_START_SW( uint32_t const p_numcore ) ;

#endif /* BOOT_MAIN_public_H */
