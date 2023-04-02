/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef LPDISC_PUBLIC_H
#define LPDISC_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */
/* Index of all known HP devices */
typedef enum
{
   e_lp_01 = 0,
   e_lp_02,
   e_lp_03,
   e_lp_04,
   e_lp_05,
   e_lp_06,
   e_lp_07,
   e_lp_08,
   e_lp_09,
   e_lp_10,
   e_LpDeviceMax
}
te_lpdisc_device_index;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* LP mon state */
extern uint16_t lpdisc_mon_state[e_LpDeviceMax];

/* ---------- provided operations: ------------------------------------------ */
/* REQ_FADEX_OS_SRD-LPDISC-0010 */
/* Initialization of LP switches */
extern void lpdisc_init(void);

/* Implements REQ_FADEX_OS_SRD-LPDISC-0020 */
/* Implements REQ_FADEX_OS_SRD-LPDISC-0030 */
/* Implements REQ_FADEX_OS_SRD-LPDISC-0040 */
/* Implements REQ_FADEX_OS_SRD-LPDISC-0050 */
/* Implements REQ_FADEX_OS_SRD-LPDISC-0060 */
/* Implements REQ_FADEX_OS_SRD-LPDISC-0070 */
/* Periodic process of LP devices */
extern void lpdisc_periodic(void);


#endif /* LPDISC_PUBLIC_H */

