/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function sets ASTERIOS inputs (Repetitive Sequence of
 *               Frame (ASTEKCONF) and RTC (period and timeout before RESET)).
 * -------------------------------------------------------------------------- */

#include "BOOT_MAIN_public.h"
#include "BOOT_MAIN_private.h"
#include "BOOT_CONF_public.h"
/* ---------- include provided interface: ----------------------------------- */
/* none */

/* ---------- internal define constants: ------------------------------------ */

#ifndef ASTERIOS_K193
/* Address where to write the address of the ASTEKCONF. */
#define RSF_ADDR                       ((uint32_t)0x40000100)

/* Address where to write the value of the FPGA RTC period required by ASTERIOS kernel. */
#define RTC_FPGA_PERIOD_ADDR           ((uint32_t)0x4000FFF8 )

/* Address where to write the value of FPGA RTC timeout required by ASTERIOS kernel. */
#define RTC_FPGA_TIMEOUT_ADDR          ((uint32_t)0x4000FFFC)
#endif

#ifdef ASTERIOS_K193
#define ASTERIOS_INPUT_START_ADDR      ((uint32_t)0x40000100)
/* Magic number to indicate the presence of the Boot Interface Structure. */
#define AST_BOOT_CONFIG_MAGIC          ((uint32_t)0x457310CC)
/* Version 3 of interface structure BOOT/ASTERIOS. */
#define AST_BOOT_CONFIG_VERSION        ((uint32_t)3)
/* Value to skip the checksum */
#define AST_BOOT_CONFIG_SKIP_CHECKSUM  ((uint32_t)0x457313B9)
#define CORE_0_IDX 0
#define CORE_1_IDX 1
#define CORE_2_IDX 2
#define CORE_NB 3
#endif

/* ---------- internal types: ----------------------------------------------- */

#ifdef ASTERIOS_K193
typedef struct
{
  /* Marks the presence of the Boot Interface Structure. */
  uint32_t s_magic;
  /* Provides the version of the structure. */
  uint32_t s_version;
  /* Runtime entry point address */
  uint32_t s_runtime_address;
  /* When set to AST_BOOT_CONFIG_SKIP_CHECKSUM, skip the checksum performed at boot time */
  uint32_t s_skip_checksum;
  /* When set to AST_BOOT_CONFIG_DISABLE_PROFILING, disable the profiling feature at run time */
  uint32_t s_disable_profiling;
  /* Pointer to the Handler of Errors belonging to the `early` Category */
  uint32_t s_early_error_handler_addr;
  /* Number of cores booted by boot software */
  uint32_t s_nb_booted_cores;
  /* List of hardware identifiers of booted cores. */
   uint32_t s_booted_cores[CORE_NB];
  /* External Source minor frame period in units of 250us. */
  uint32_t s_xt_src_minor_frame_period;
  /* External Source timeout in units of 10us. */
  uint32_t s_xt_src_timeout;

}ts_MAIN_ASTERIOS_INPUTS;
#endif

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Implements REQ_[User Project Name]_BOOT-LLR_016 */
void BOOT_MAIN_SET_ASTERIOS_INPUT( uint32_t const p_astekconf_idx)
{

#ifdef ASTERIOS_K193

   ts_MAIN_ASTERIOS_INPUTS * pt_ASTERIOS_inputs = (ts_MAIN_ASTERIOS_INPUTS *) ASTERIOS_INPUT_START_ADDR;

   pt_ASTERIOS_inputs->s_magic = AST_BOOT_CONFIG_MAGIC;
   pt_ASTERIOS_inputs->s_version = AST_BOOT_CONFIG_VERSION;
   pt_ASTERIOS_inputs->s_runtime_address = c_CONF_ASTEK_tab[p_astekconf_idx].s_Runtime_addr_conf;
   pt_ASTERIOS_inputs->s_skip_checksum = AST_BOOT_CONFIG_SKIP_CHECKSUM;
   pt_ASTERIOS_inputs->s_disable_profiling = c_CONF_ASTEK_tab[p_astekconf_idx].s_disable_profiling_conf;
   pt_ASTERIOS_inputs->s_early_error_handler_addr = c_CONF_ASTEK_tab[p_astekconf_idx].s_early_error_handler_addr_conf;
   pt_ASTERIOS_inputs->s_nb_booted_cores = c_CONF_ASTEK_tab[p_astekconf_idx].s_nb_cores_conf;
   pt_ASTERIOS_inputs->s_booted_cores[CORE_0_IDX] = c_CONF_ASTEK_tab[p_astekconf_idx].s_cores_conf[CORE_0_IDX];
   pt_ASTERIOS_inputs->s_booted_cores[CORE_1_IDX] = c_CONF_ASTEK_tab[p_astekconf_idx].s_cores_conf[CORE_1_IDX];
   pt_ASTERIOS_inputs->s_booted_cores[CORE_2_IDX] = c_CONF_ASTEK_tab[p_astekconf_idx].s_cores_conf[CORE_2_IDX];
   pt_ASTERIOS_inputs->s_xt_src_minor_frame_period = c_CONF_RTC_PERIOD;
   pt_ASTERIOS_inputs->s_xt_src_timeout = c_CONF_RTC_TIMEOUT;
#endif

#ifndef ASTERIOS_K193

   uint32_t * pt_ASTERIOS_input;

   /* Indicate to ASTERIOS the address of the ASTEKCONF  */
   pt_ASTERIOS_input = (uint32_t *) RSF_ADDR;
   *pt_ASTERIOS_input = c_CONF_ASTEK_tab[p_astekconf_idx].s_Runtime_addr_conf;

   /* Indicate to ASTERIOS the period of the RTC FPGA*/
   pt_ASTERIOS_input = (uint32_t *) RTC_FPGA_PERIOD_ADDR;
   *pt_ASTERIOS_input = c_CONF_RTC_PERIOD;

   /* Indicate to ASTERIOS the maximum duration between 2 RTC (timeout) */
   pt_ASTERIOS_input = (uint32_t *) RTC_FPGA_TIMEOUT_ADDR;
   *pt_ASTERIOS_input = c_CONF_RTC_TIMEOUT;

#endif

}

/* ---------- internal operation bodies: ------------------------------------ */
/* none */
