/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef HPDISC_PUBLIC_H
#define HPDISC_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */
/* Index of all known HP devices */
typedef enum
{
   e_hp_1 = 0,
   e_hp_2,
   e_hp_3,
   e_hp_4,
   e_hp_5,
   e_HpDeviceMax
}
te_hpdisc_device_index;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* HP mon state */
extern uint16_t hpdisc_mon_state[e_HpDeviceMax];

/* HP 4 mon current and voltage */
extern float32_t hpdisc_current_mon;
extern float32_t hpdisc_voltage_mon;

/* ---------- provided operations: ------------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-HPDISC-0010 */
/* Initialization of HP switches */
extern void hpdisc_init(void);

/* Implements REQ_FADEX_OS_SRD-HPDISC-0020 */
/* Implements REQ_FADEX_OS_SRD-HPDISC-0030 */
/* Implements REQ_FADEX_OS_SRD-HPDISC-0040 */
/* Implements REQ_FADEX_OS_SRD-HPDISC-0050 */
/* Implements REQ_FADEX_OS_SRD-HPDISC-0060 */
/* Implements REQ_FADEX_OS_SRD-HPDISC-0070 */
/* Periodic process of HP devices */
extern void hpdisc_periodic(void);

#endif /* HPDISC_PUBLIC_H */

