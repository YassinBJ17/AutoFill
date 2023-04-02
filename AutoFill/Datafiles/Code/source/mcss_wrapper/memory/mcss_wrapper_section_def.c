/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : short description of the operations of the .c file
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "memory/memory_address_public.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */
const uint32_t cancel_pointless_warning_3 = (uint32_t)0;

/* ---------- provided data: ------------------------------------------------ */
/* Variable that is used to force ASTERIOS to identify the sections */
uint32_t make_asterios_identify_this_file_1;

/* ---------- internal constants: ------------------------------------------- */
/* Code area for the CSS wrapper GX (also known as .text) */
#pragma section MCSS_WRAPPER_TEXT_AREA \
    ".mcss_wrapper_text_src"           \
    ".mcss_wrapper_text_src"
#pragma use_section MCSS_WRAPPER_TEXT_AREA mcss_wrapper_text_area
/* >RELAX<SYNCHRONe_C_Code_8.17> justification */
const uint8_t mcss_wrapper_text_area[MCSS_WRAPPER_TEXT_AREA_SIZE] = { (uint8_t)0 };
#pragma section MCSS_WRAPPER_TEXT_AREA

/* BSS area for the CSS wrapper GX */
#pragma section MCSS_WRAPPER_BSS_AREA \
    ".mcss_wrapper_bss_src"           \
    ".mcss_wrapper_bss_src"
#pragma use_section MCSS_WRAPPER_BSS_AREA mcss_wrapper_bss_area
/* >RELAX<SYNCHRONe_C_Code_8.17> justification */
const uint8_t mcss_wrapper_bss_area[MCSS_WRAPPER_BSS_AREA_SIZE] = { (uint8_t)0 };
#pragma section MCSS_WRAPPER_BSS_AREA

/* Data area for the CSS wrapper GX */
#pragma section MCSS_WRAPPER_DATA_AREA \
    ".mcss_wrapper_data_src"           \
    ".mcss_wrapper_data_src"
#pragma use_section MCSS_WRAPPER_DATA_AREA mcss_wrapper_data_area
/* >RELAX<SYNCHRONe_C_Code_8.17> justification */
const uint8_t mcss_wrapper_data_area[MCSS_WRAPPER_DATA_AREA_SIZE] = {  (uint8_t)0 };
#pragma section MCSS_WRAPPER_DATA_AREA

/* Rodata area for the CSS wrapper GX */
#pragma section MCSS_WRAPPER_RODATA_AREA \
    ".mcss_wrapper_rodata_src"           \
    ".mcss_wrapper_rodata_src"
#pragma use_section MCSS_WRAPPER_RODATA_AREA mcss_wrapper_rodata_area
/* >RELAX<SYNCHRONe_C_Code_8.17> justification */
const uint8_t mcss_wrapper_rodata_area[MCSS_WRAPPER_RODATA_AREA_SIZE] = { (uint8_t)0 };
#pragma section MCSS_WRAPPER_RODATA_AREA

/* ---------- internal data: ------------------------------------------------ */
/* Configuration table area for the MCSS wrapper */
#pragma section MCSS_WRAPPER_CONF_TAB_AREA \
    ".mcss_wrapper_conf_tab_src"           \
    ".mcss_wrapper_conf_tab_src"
#pragma use_section MCSS_WRAPPER_CONF_TAB_AREA mcss_wrapper_conf_tab_area
/* >RELAX<SYNCHRONe_C_Code_8.15> justification */
/* >RELAX<SYNCHRONe_C_Code_8.17> justification */
uint8_t mcss_wrapper_conf_tab_area[MCSS_WRAPPER_CONF_TAB_AREA_SIZE];
#pragma section MCSS_WRAPPER_CONF_TAB_AREA

/* Tasks pointers area for MCSS wrapper */
#pragma section MCSS_WRAPPER_TASKS_AREA \
    ".mcss_wrapper_task_src"           \
    ".mcss_wrapper_task_src"
#pragma use_section MCSS_WRAPPER_TASKS_AREA mcss_wrapper_task_area
/* >RELAX<SYNCHRONe_C_Code_8.15> justification */
/* >RELAX<SYNCHRONe_C_Code_8.17> justification */
uint8_t mcss_wrapper_task_area[MCSS_WRAPPER_TASKS_AREA_SIZE];
#pragma section MCSS_WRAPPER_TASKS_AREA

/* ---------- provided operation bodies: ------------------------------------ */

/* ---------- internal operations: ------------------------------------------ */

