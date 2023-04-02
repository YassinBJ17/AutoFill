/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef PBIT_PRIVATE_H
#define PBIT_PRIVATE_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"
/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */
#define SRAM_TEST_VAL_NB      ((uint32_t)20)
#define SRAM_VAL_1_55  ((uint32_t)0x55555555)
#define SRAM_VAL_2_AA  ((uint32_t)0xAAAAAAAA)
#define FPGA_HARDCODED_ADD_1  ((uint32_t*)0x24003FF0)
#define FPGA_HARDCODED_ADD_2  ((uint32_t*)0x24003FF4)
#define FPGA_HARDCODED_VAL_1  ((uint32_t)0xAAAAAAAA)
#define FPGA_HARDCODED_VAL_2  ((uint32_t)0x55555555)

#define MRAM_ADD_1  ((uint32_t*)0x20000000)
#define MRAM_ADD_2  ((uint32_t*)0x2001FFFC)
#define MRAM_VAL_1  ((uint32_t)0xAAAAAAAA)
#define MRAM_VAL_2  ((uint32_t)0x55555555)

#define PLD_PLL_REG_ADD  ((uint32_t*)0x24000014)
#define PLD_PLL_LOCK_EBI_64M_BIT_MASK  ((uint32_t)0x80000000)
#define PLD_PLL_LOCK_EBI_80M_BIT_MASK  ((uint32_t)0x40000000)
#define PLD_PLL_LOCK_WD_80M_BIT_MASK  ((uint32_t)0x20000000)

#define SHIFT_31  (uint32_t)31
#define SHIFT_30  (uint32_t)30
#define SHIFT_29  (uint32_t)29

/* ---------- provided data: ------------------------------------------------ */


/* ---------- provided operations: ------------------------------------------ */

void pbit_ebi_ext_sram(void);

void pbit_ext_mram(void);

void pbit_pld_config(const boolean_t ch_is_a);

void pbit_pld_a429_1a_rx(void);

void pbit_pld_a429_2ab_rx(void);

void pbit_pld_a429_tx(const boolean_t ch_is_a);

void pbit_pld_pwm(void);

void pbit_pld_speed(void);

void pbit_pld_ccdl(void);

void pbit_pld_pll(void);

void pbit_pld_sm(void);

void pbit_fpga_hardcode(void);

void pbit_reset(const uint32_t err_flag, const uint32_t p_last_faulty_address, const uint32_t p_last_faulty_data);

#endif /* PBIT_PRIVATE_H */
