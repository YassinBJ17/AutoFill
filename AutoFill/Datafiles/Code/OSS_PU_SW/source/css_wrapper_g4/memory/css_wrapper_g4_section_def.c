/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Definition of the sections for CSS wrapper GX
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "memory/memory_address_public.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */
const uint32_t cancel_pointless_warning_2 = (uint32_t)0;

/* ---------- provided data: ------------------------------------------------ */
uint32_t make_asterios_identify_this_file_2;

/* ---------- internal constants: ------------------------------------------- */
/* Code area for the CSS wrapper GX (also known as .text) */
#pragma section CSS_WRAPPER_GX_TEXT_AREA \
    ".css_wrapper_gx_text_src"           \
    ".css_wrapper_gx_text_src"
#pragma use_section CSS_WRAPPER_GX_TEXT_AREA css_wrapper_gx_text_area
/* >RELAX<SYNCHRONe_C_Code_8.2> justification */
/* >RELAX<SYNCHRONe_C_Code_8.13> justification */
/* >RELAX<SYNCHRONe_C_Code_8.17> justification */
const uint8_t css_wrapper_gx_text_area[CSS_WRAPPER_GX_TEXT_AREA_SIZE] = { (uint8_t)0 };
#pragma section CSS_WRAPPER_GX_TEXT_AREA

/* BSS area for the CSS wrapper GX */
#pragma section CSS_WRAPPER_GX_BSS_AREA \
    ".css_wrapper_gx_bss_src"           \
    ".css_wrapper_gx_bss_src"
#pragma use_section CSS_WRAPPER_GX_BSS_AREA css_wrapper_gx_bss_area
/* >RELAX<SYNCHRONe_C_Code_8.17> justification */
const uint8_t css_wrapper_gx_bss_area[CSS_WRAPPER_GX_BSS_AREA_SIZE] = { (uint8_t)0 };
#pragma section CSS_WRAPPER_GX_BSS_AREA

/* Data area for the CSS wrapper GX */
#pragma section CSS_WRAPPER_GX_DATA_AREA \
    ".css_wrapper_gx_data_src"           \
    ".css_wrapper_gx_data_src"
#pragma use_section CSS_WRAPPER_GX_DATA_AREA css_wrapper_gx_data_area
/* >RELAX<SYNCHRONe_C_Code_8.13> justification */
/* >RELAX<SYNCHRONe_C_Code_8.17> justification */
const uint8_t css_wrapper_gx_data_area[CSS_WRAPPER_GX_DATA_AREA_SIZE] = { (uint8_t)0 };
#pragma section CSS_WRAPPER_GX_DATA_AREA

/* Rodata area for the CSS wrapper GX */
#pragma section CSS_WRAPPER_GX_RODATA_AREA \
    ".css_wrapper_gx_rodata_src"           \
    ".css_wrapper_gx_rodata_src"
#pragma use_section CSS_WRAPPER_GX_RODATA_AREA css_wrapper_gx_rodata_area
/* >RELAX<SYNCHRONe_C_Code_8.13> justification */
/* >RELAX<SYNCHRONe_C_Code_8.17> justification */
const uint8_t css_wrapper_gx_rodata_area[CSS_WRAPPER_GX_RODATA_AREA_SIZE] = { (uint8_t)0 };
#pragma section CSS_WRAPPER_GX_RODATA_AREA

/* ---------- internal data: ------------------------------------------------ */
/* MRAM area for the CSS wrapper GX */
#pragma section CSS_WRAPPER_GX_MRAM_AREA \
    ".css_wrapper_gx_mram_src"           \
    ".css_wrapper_gx_mram_src"
#pragma use_section CSS_WRAPPER_GX_MRAM_AREA css_wrapper_gx_mram_area
/* >RELAX<SYNCHRONe_C_Code_8.13> justification */
/* >RELAX<SYNCHRONe_C_Code_8.15> justification */
/* >RELAX<SYNCHRONe_C_Code_8.17> justification */
uint8_t css_wrapper_gx_mram_area[CSS_WRAPPER_GX_MRAM_AREA_SIZE];
#pragma section CSS_WRAPPER_GX_MRAM_AREA

/* Configuration table area for the CSS wrapper GX */
#pragma section CSS_WRAPPER_GX_CONF_TAB_AREA \
    ".css_wrapper_gx_conf_tab_src"           \
    ".css_wrapper_gx_conf_tab_src"
#pragma use_section CSS_WRAPPER_GX_CONF_TAB_AREA css_wrapper_gx_conf_tab_area
/* >RELAX<SYNCHRONe_C_Code_8.13> justification */
/* >RELAX<SYNCHRONe_C_Code_8.15> justification */
/* >RELAX<SYNCHRONe_C_Code_8.17> justification */
uint8_t css_wrapper_gx_conf_tab_area[CSS_WRAPPER_GX_CONF_TAB_AREA_SIZE];
#pragma section CSS_WRAPPER_GX_CONF_TAB_AREA

/* Tasks pointers area for CSS wrapper GX */
#pragma section CSS_WRAPPER_GX_TASKS_AREA \
    ".css_wrapper_gx_task_src"           \
    ".css_wrapper_gx_task_src"
#pragma use_section CSS_WRAPPER_GX_TASKS_AREA css_wrapper_gx_task_area
/* >RELAX<SYNCHRONe_C_Code_8.13> justification */
/* >RELAX<SYNCHRONe_C_Code_8.15> justification */
/* >RELAX<SYNCHRONe_C_Code_8.17> justification */
uint8_t css_wrapper_gx_task_area[CSS_WRAPPER_GX_TASKS_AREA_SIZE];
#pragma section CSS_WRAPPER_GX_TASKS_AREA

/* ---------- provided operation bodies: ------------------------------------ */

/* ---------- internal operations: ------------------------------------------ */
