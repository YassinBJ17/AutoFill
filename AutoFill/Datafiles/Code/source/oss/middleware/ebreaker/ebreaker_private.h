/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef EBREAKER_PRIVATE_H
#define EBREAKER_PRIVATE_H

/* ---------- Linker command file symbol: ----------------------------------- */
#include "type/common_type.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
/* Activation flux CDM vers CDR */
#define EBREAKER_CMD1_ON     (uint32_t)0x806F7440
#define EBREAKER_CMD2_ON     (uint32_t)0xC27377B4

/* Disengage flux CDM vers CDR */
#define EBREAKER_CMD1_OFF    (uint32_t)0xBB02C254
#define EBREAKER_CMD2_OFF    (uint32_t)0x46C7C8EA

/* Global value for e-breaker */
#define EBREACKER_INIT_VALUE (uint32_t)0
#define EBREACKER_OPER_VALUE (uint32_t)1
#define FPGA_EBREACKER_INIT_VALUE (reg32_t)0
#define FPGA_EBREACKER_OPER_VALUE (reg32_t)1

/* FPGA STATE for E-BREAKER */
#define FPGA_RX_STATUS        (reg32_t*)(0x240F4004)
#define MASK_FPGA_RX_ENABLE   (reg32_t)(0x00010000)
#define OFFSET_FPGA_RX_ENABLE (reg32_t)(16)

/* ---------- provided types: ----------------------------------------------- */
typedef struct
{
   uint32_t      s_ebreaker_cmd_1;
   uint32_t      s_ebreaker_cmd_2;
}
ts_ebreaker_cmd;

typedef enum
{
   e_ebreaker_rx_disable   = 0,
   e_ebreaker_rx_enable    = 1,
   e_ebreaker_nb_cmd
}
te_ebreaker_rx_state;

typedef struct
{
   /* State value of RX mailbox */
   te_ebreaker_rx_state   s_rx_state;
   /* Commands values to access of RX state */
   ts_ebreaker_cmd        s_cmd_flow;
   /* Functions access */
   uint32_t               add_function_cmd_1;
   uint32_t               add_function_cmd_2;
}
ts_ebreaker_function;

/* ---------- provided constants: ------------------------------------------- */
extern const ts_ebreaker_function EBREAKER_tab[e_ebreaker_nb_cmd];

/* ---------- provided data: ------------------------------------------------ */
/* Previous command value from share memory on each previous RTC*/
extern uint32_t  ebreaker_previous_cmd;

/* ---------- provided operations: ------------------------------------------ */
extern void ebreaker_get(
   /* OUTPUT */
   te_ebreaker_rx_state*  const p_rx_state,
   uint32_t *             const p_ebreaker_cmd);

extern void ebreaker_monitor(
   /* INPUT */
   const te_ebreaker_rx_state    e_rx_state,
   const uint32_t                c_ebreaker_cmd);


#endif /* EBREAKER_PRIVATE_H */
