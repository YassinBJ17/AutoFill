/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef OVSP_PUBLIC_H
#define OVSP_PUBLIC_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"

#include "middleware/ovsp/ovsp_frame.h"

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */
#define OVSP_RX_NB_MAX_FRAME      ((uint32_t)64)    /* Made public for uod_bypass */
#define OVSP_TX_FRAME_SEND      ((uint32_t)14)    /* Made public for uod_bypass */

/* ---------- provided data: ------------------------------------------------ */
/* OVSP LS get_data response frame format */
extern ts_ovsp_data_resp_frame2 ls_resp_frame_format_2;   /* Response data frame format 2 */
extern ts_ovsp_data_resp_frame3 ls_resp_frame_format_3;   /* Response data frame format 3 */

/* OVSP LS internal fault word */
extern tu_ovs_hs_ls_intern_fault_word ovsp_ls_fault_word;

/* OVSP HS internal fault word */
extern tu_ovs_hs_ls_intern_fault_word ovsp_hs_fault_word;

/* ---------- provided operations: ------------------------------------------ */
/* OVSP initialization send command function */
extern void ovsp_init_send(void);

/* OVSP initialization read frame function */
extern void ovsp_init_read(void);

/* Implements REQ_FADEX_OS_SRD- */
/* OVSP periodic function acquisition and CBIT */
extern void ovsp_periodic(const boolean_t channel_is_a);

#endif /* OVSP_PUBLIC_H */
