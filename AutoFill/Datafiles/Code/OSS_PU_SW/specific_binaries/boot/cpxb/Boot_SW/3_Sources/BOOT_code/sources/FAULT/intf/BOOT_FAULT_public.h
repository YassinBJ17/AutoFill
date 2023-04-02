#ifndef BOOT_FAULT_public_H
#define BOOT_FAULT_public_H

/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

/* ---------- include  ------------------------------------------------------ */
#include "CMN_TYPES_common.h"

/* ---------- internal define constants: ------------------------------------ */

#define BOOT_FAULT_POWERDOWN_IT         ( 0x0ul )
#define BOOT_FAULT_CRITICAL_INPUT_IT    ( 0x1ul )
#define BOOT_FAULT_MACHINE_CHECK_IT     ( 0x2ul )
#define BOOT_FAULT_DATA_ACCESS_IT       ( 0x3ul )
#define BOOT_FAULT_INST_ACCESS_IT       ( 0x4ul )
#define BOOT_FAULT_EXT_IT               ( 0x5ul )
#define BOOT_FAULT_ALIGNMENT_IT         ( 0x6ul )
#define BOOT_FAULT_PROGRAM_IT           ( 0x7ul )
#define BOOT_FAULT_PERF_MON_IT          ( 0x8ul )
#define BOOT_FAULT_SC_IT                ( 0x9ul )
#define BOOT_FAULT_BRKPT_IT             ( 0xAul )
#define BOOT_FAULT_EFPU_DATA_IT         ( 0xBul )
#define BOOT_FAULT_EFPU_ROUND_IT        ( 0xCul )
#define BOOT_FAULT_FCCU                 ( 0xDul )
#define BOOT_FAULT_PBIT_CMPU            ( 0xEul )
#define BOOT_FAULT_BOOT_INTEGRITY       ( 0xFul )
#define BOOT_FAULT_DTLD_INTEGRITY       ( 0x10ul)
#define BOOT_FAULT_OS_INTEGRITY         ( 0x11ul)
#define BOOT_FAULT_SW_COMPATIBILITY     ( 0x12ul)
#define BOOT_FAULT_XBIST                ( 0x13ul)
#define BOOT_FAULT_MBIST_LMEM_0         ( 0x14ul)
#define BOOT_FAULT_MBIST_LMEM_1         ( 0x15ul)
#define BOOT_FAULT_MBIST_LMEM_2         ( 0x16ul)
#define BOOT_FAULT_MBIST_SRAM           ( 0x17ul)
#define BOOT_FAULT_MBIST_DMA_RMA        ( 0x18ul)
#define BOOT_FAULT_MBIST_BAR            ( 0x19ul)
#define BOOT_FAULT_MBIST_OTHER_RAM      ( 0x1Aul)
#define BOOT_FAULT_MBIST_DBG_RAM        ( 0x1Bul)
#define BOOT_FAULT_LBIST_HSM            ( 0x30ul)
#define BOOT_FAULT_LBIST_CORE_2         ( 0x31ul)
#define BOOT_FAULT_LBIST_PERIPH_1       ( 0x32ul)
#define BOOT_FAULT_LBIST_COMPUT_SHELL   ( 0x33ul)
#define BOOT_FAULT_LBIST_PERIPH_2       ( 0x34ul)
#define BOOT_FAULT_LBIST_PERIPH_3       ( 0x35ul)
#define BOOT_FAULT_LBIST_GTM            ( 0x36ul)
#define BOOT_FAULT_LBIST_CORE_0         ( 0x37ul)
#define BOOT_FAULT_LBIST_CORE_CHK       ( 0x38ul)
#define BOOT_FAULT_LBIST_CORE_1         ( 0x39ul)
#define BOOT_FAULT_CONF_CSS_PU          ( 0x3Aul)

#define PBIT_ORIGIN        ( 0x1ul )
#define INTC_ORIGIN        ( 0x2ul )
#define FCCU_ORIGIN        ( 0x3ul )
#define MBIST_ORIGIN       ( 0x4ul )
#define LBIST_ORIGIN       ( 0x5ul )


#define LGBK_FIELD_DEFAULT_VALUE (uint32_t)0xDECACAFE
/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal datas: ----------------------------------------------- */
/* none */

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- provided operations: ------------------------------------------- */

extern void BOOT_FAULT_LOG ( uint32_t const p_ErrorCode,
                                    const uint32_t p_originId /* in */,
                                    const uint32_t p_rawData1 /* in */,
                                    const uint32_t p_rawData2 /* in */,
                                    const uint32_t p_rawData3 /* in */,
                                    const uint32_t p_rawData4 /* in */);

extern void BOOT_FAULT_INFINITELOOP ( void );
#endif /* BOOT_FAULT_public_H */
