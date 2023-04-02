/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef HPDISC_PRIVATE_H
#define HPDISC_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "middleware/hpdisc/hpdisc_public.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
/* Devices possible states */
#define C_HP_COMM_ERROR       ((uint16_t)0x0000)
#define C_HP_ALL_OPEN         ((uint16_t)0x0001)
#define C_HP_1_CLOSE_2_OPEN   ((uint16_t)0x0003)
#define C_HP_1_OPEN_2_CLOSE   ((uint16_t)0x0005)
#define C_HP_ALL_CLOSE        ((uint16_t)0x0007)

/* Authorized AS commands */
#define C_HP_CMD_OPEN   ((uint32_t)0x55555555)
#define C_HP_CMD_CLOSE  ((uint32_t)0xAAAAAAAA)
#define C_HP_CMD_NONE   ((uint32_t)0xFFFFFFFF)

/* ---------- provided types: ----------------------------------------------- */
/* Structure of devices item */
typedef struct
{
   uint16_t *s_io_pointer;
   uint16_t  s_io_mask;
   uint8_t  *s_err_pointer;
}
ts_hpdisk_item;

/*  */
typedef struct
{
   ts_hpdisk_item s_raw_swi_1;
   ts_hpdisk_item s_raw_swi_2;
   ts_hpdisk_item s_raw_status;
   uint16_t       s_state_read;
   uint16_t       s_state_call;
   boolean_t      s_open_in_progress;
}
ts_hpdisk_device;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Array holding information of all HP devices */
extern ts_hpdisk_device v_hp_devices[e_HpDeviceMax];

/* ---------- provided operations: ------------------------------------------ */

#endif /* HPDISC_PRIVATE_H */

