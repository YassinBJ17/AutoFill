/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef LPDISC_PRIVATE_H
#define LPDISC_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "middleware/lpdisc/lpdisc_public.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
/* Devices possible states */
#define C_LP_COMM_ERROR       ((uint16_t)0x0000)
#define C_LP_ALL_OPEN         ((uint16_t)0x0001)
#define C_LP_1_CLOSE_2_OPEN   ((uint16_t)0x0003)
#define C_LP_1_OPEN_2_CLOSE   ((uint16_t)0x0005)
#define C_LP_ALL_CLOSE        ((uint16_t)0x0007)

/* Authorized AS commands */
#define C_LP_CMD_OPEN   ((uint32_t)0x55555555)
#define C_LP_CMD_CLOSE  ((uint32_t)0xAAAAAAAA)
#define C_LP_CMD_NONE   ((uint32_t)0xFFFFFFFF)

/* ---------- provided types: ----------------------------------------------- */
/* Structure of devices item */
typedef struct
{
   uint16_t *s_io_pointer;
   uint16_t  s_io_mask;
   uint8_t  *s_err_pointer;
}
ts_lpdisk_item;

/*  */
typedef struct
{
   ts_lpdisk_item s_raw_swi_1;
   ts_lpdisk_item s_raw_swi_2;
   ts_lpdisk_item s_raw_status;
   uint16_t       s_state_read;
   uint16_t       s_state_call;
   boolean_t      s_open_in_progress;
}
ts_lpdisk_device;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Array holding information of all LP devices */
extern ts_lpdisk_device v_lp_devices[e_LpDeviceMax];

/* ---------- provided operations: ------------------------------------------ */

#endif /* LPDISC_PRIVATE_H */

