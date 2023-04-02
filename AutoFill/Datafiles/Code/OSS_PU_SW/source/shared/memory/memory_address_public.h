/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef MEMORY_ADDRESS_PUBLIC_H
#define MEMORY_ADDRESS_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
/* Function pointer on the CSS GX initialization function */
#define CSS_WRAPPER_GX_INITIALIZATION_TASK_ADDR *((void (**)(void))0x21004000)

/* Function pointer on the CSS GX fast task */
#define CSS_WRAPPER_GX_FAST_TASK_ADDR *((void (**)(void))0x21004004)

/* Function pointer on the CSS G1_2_3 slow task */
#define CSS_WRAPPER_G1_2_3_SLOW_TASK_ADDR *((void (**)(void))0x21004008)

/* Function pointer on the CSS G1_2_3 very slow task */
#define CSS_WRAPPER_G1_2_3_VERY_SLOW_TASK_ADDR *((void (**)(void))0x2100400C)

/* Function pointer on the CSS G1_2_3 background task */
#define CSS_WRAPPER_G1_2_3_BACKGROUND_TASK_ADDR *((void (**)(void))0x21004010)

/* Function pointer on the MCSS initialization function */
#define MCSS_WRAPPER_INITIALIZATION_TASK_ADDR *((void (**)(void))0x21004014)

/* Function pointer on the MCSS task */
#define MCSS_WRAPPER_TASK_ADDR *((void (**)(void))0x2100401C)

/* Critical CSS data in MRAM (in bytes) */
#define CSS_WRAPPER_GX_MRAM_AREA_SIZE ((uint32_t)(0x0000F000 + 0x00000C20))   /* Offset added for UOD configuration access for CSS stub */

/* CSS GX configuration table (in bytes) */
#define CSS_WRAPPER_GX_CONF_TAB_AREA_SIZE (uint32_t)0x00080000

/* CSS GX task pointers size */
#define CSS_WRAPPER_GX_TASKS_AREA_SIZE (uint32_t)0x00000014

/* Size of the code area for the CSS GX (in bytes) */
#define CSS_WRAPPER_GX_TEXT_AREA_SIZE (uint32_t)0x00100000

/* Size of the bss area for the CSS GX (in bytes) */
#define CSS_WRAPPER_GX_BSS_AREA_SIZE (uint32_t)0x000FE000

/* Size of the data area for the CSS GX (in bytes) */
#define CSS_WRAPPER_GX_DATA_AREA_SIZE (uint32_t)0x000FE000

/* Size of the rodata area for the CSS GX (in bytes) */
#define CSS_WRAPPER_GX_RODATA_AREA_SIZE (uint32_t)0x00100000

/* Size of the code area for the MCSS (in bytes) */
#define MCSS_WRAPPER_TEXT_AREA_SIZE (uint32_t)0x00040000

/* Size of the bss area for the MCSS (in bytes) */
#define MCSS_WRAPPER_BSS_AREA_SIZE (uint32_t)0x00002000

/* Size of the data area for the MCSS (in bytes) */
#define MCSS_WRAPPER_DATA_AREA_SIZE (uint32_t)0x00002000

/* Size of the rodata area for the MCSS (in bytes) */
#define MCSS_WRAPPER_RODATA_AREA_SIZE (uint32_t)0x00020000

/* MCSS configuration table (in bytes) */
#define MCSS_WRAPPER_CONF_TAB_AREA_SIZE (uint32_t)0x00040000

/* MCSS task pointers size */
#define MCSS_WRAPPER_TASKS_AREA_SIZE (uint32_t)0x00000008

/* OSS configuration table (in bytes) */
#define OSS_CONF_TAB_AREA_SIZE (uint32_t)0x00040000

/* OSS MRAM section for profiling */
#define OSS_MRAM_AREA_SIZE_PROFILING ((uint32_t)0x00001000)

/* OSS MRAM area for OTHER */
#define OSS_MRAM_AREA_SIZE_OTHER     ((uint32_t)(0x0000D000 - 0x00000C20))   /* Offset added for UOD configuration access for CSS stub */

/* Size of the FPGA registers (TBD) accessed by the OSS (in bytes) */
#define FPGA_REGISTER_AREA_SIZE (uint32_t)0x00100000

/* Critical services pointers area size */
#define CRITICAL_SERVICES_POINTERS_AREA_SIZE (uint32_t)0x00000040

/* OSS mailbox area size */
#define OSS_MAILBOX_AREA_SIZE (uint32_t)0x00010000

/* FPGA start address  */
#define FPGA_MEMORY_ADDR (uint32_t)0x24000000

/* FPGA tmot register start adress */
#define TMOT_FPGA_MEMORY_ADDR (uint32_t)(FPGA_MEMORY_ADDR + 0x000EC000)

/* FPGA ACCOM register start adress */
#define ACCOM_FPGA_MEMORY_ADDR (uint32_t)(FPGA_MEMORY_ADDR + 0x000E8000)

/* FPGA ACCOM  sync status start address */
#define ACCOM_FPGA_SYNC_STATUS ((uint32_t)(FPGA_MEMORY_ADDR + 0x0002001C))

/* FPGA smot register start adress */
#define SMOT_FPGA_MEMORY_ADDR (ts_smot_fpga_reg*)(FPGA_MEMORY_ADDR + 0x000F0000)

/* Profiling data */
#define PROFILING_DATA_START_ADDR 0x20003000

/* OSS_CONF start adress : 0x20004000 for MRAM & 0x01200000 for FLASH */
#define OSS_CONF_START_ADDR       0x01200000

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */

#endif /* MEMORY_ADDRESS_PUBLIC_H */
