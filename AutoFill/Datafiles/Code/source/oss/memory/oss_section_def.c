/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Definition of the global initialization function for OSS
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "memory/oss_section_def_public.h"
#include "memory/memory_address_public.h"
#include "conf/oss_conf_public.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
uint32_t make_asterios_identify_this_file_4;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* MRAM area for profiling data */
#pragma section OSS_MRAM_PROFILING \
    ".oss_mram_profiling_src"           \
    ".oss_mram_profiling_src"
#pragma use_section OSS_MRAM_PROFILING mram_profiling_data
#pragma use_section OSS_MRAM_PROFILING oss_mram_profiling
ts_fct_exec_time mram_profiling_data;
uint8_t oss_mram_profiling[OSS_MRAM_AREA_SIZE_PROFILING - sizeof(ts_fct_exec_time)];
#pragma section OSS_MRAM_PROFILING

/* MRAM area for other things (OSS_CONF, logbook, ...) */
#pragma section OSS_MRAM_OTHER \
    ".oss_mram_other_src"           \
    ".oss_mram_other_src"
#pragma use_section OSS_MRAM_OTHER mram_oss_conf
#pragma use_section OSS_MRAM_OTHER oss_mram_other
ts_oss_conf_table mram_oss_conf;
uint8_t oss_mram_other[OSS_MRAM_AREA_SIZE_OTHER - sizeof(ts_oss_conf_table)];
#pragma section OSS_MRAM_OTHER

/* Configuration table area for the OSS */
#pragma section OSS_CONF_TAB_AREA \
    ".oss_conf_tab_src"           \
    ".oss_conf_tab_src"
#pragma use_section OSS_CONF_TAB_AREA oss_conf_tab_area
/* >RELAX<SYNCHRONe_C_Code_8.2> justification */
/* >RELAX<SYNCHRONe_C_Code_8.13> justification */
/* >RELAX<SYNCHRONe_C_Code_8.15> justification */
/* >RELAX<SYNCHRONe_C_Code_8.17> justification */
uint8_t oss_conf_tab_area[OSS_CONF_TAB_AREA_SIZE];
#pragma section OSS_CONF_TAB_AREA

/* FPGA register area */
#pragma section FPGA_REGISTER_AREA \
    ".fpga_register_src"           \
    ".fpga_register_src"
#pragma use_section FPGA_REGISTER_AREA fpga_register_area
/* >RELAX<SYNCHRONe_C_Code_8.2> justification */
/* >RELAX<SYNCHRONe_C_Code_8.13> justification */
/* >RELAX<SYNCHRONe_C_Code_8.15> justification */
/* >RELAX<SYNCHRONe_C_Code_8.17> justification */
uint8_t fpga_register_area[FPGA_REGISTER_AREA_SIZE];
#pragma section FPGA_REGISTER_AREA

/* OSS mailbox area */
#pragma section OSS_MAILBOX_AREA \
    ".oss_mailbox_src"           \
    ".oss_mailbox_src"
#pragma use_section OSS_MAILBOX_AREA oss_mailbox_area
/* >RELAX<SYNCHRONe_C_Code_8.2> justification */
/* >RELAX<SYNCHRONe_C_Code_8.13> justification */
/* >RELAX<SYNCHRONe_C_Code_8.15> justification */
/* >RELAX<SYNCHRONe_C_Code_8.17> justification */
uint8_t oss_mailbox_area[OSS_MAILBOX_AREA_SIZE];
#pragma section OSS_MAILBOX_AREA

/* ---------- provided operation bodies: ------------------------------------ */

/* ---------- internal operations: ------------------------------------------ */
