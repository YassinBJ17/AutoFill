/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef ACCOM_PRIVATE_H
#define ACCOM_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "middleware/accom/accom_public.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

#define CHANNEL_ID_A (uint32_t) 0x55555555 /* Channel ID A on a full word */
#define CHANNEL_ID_B (uint32_t) 0xAAAAAAAA /* Channel ID B on a full word */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

extern uint32_t ch_id; /* Full-word channel_id data */
extern uint32_t ch_id_backup; /* full-word channel_id data backup */

/* ---------- provided operations: ------------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-ACCOM-0060 */
/* Implements REQ_FADEX_OS_SRD-ACCOM-0090 */
/**
 * Function to get the channel_state data from the FPGA and GPIO.
 */
uint32_t accom_channel_state_read(void);

/* Implements REQ_FADEX_OS_SRD-ACCOM-0010 */
/**
 *  Function to force the channel A to start as active,
 *    which also allows the Tmot/Smot to initialize normally.
 */
void accom_tmot_init(const tu_accom_ch_bit_fault_word fault_word);

#endif /* ACCOM_PRIVATE_H  */
