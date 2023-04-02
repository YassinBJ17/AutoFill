/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef CAN_CRITICAL_PUBLIC_H
#define CAN_CRITICAL_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
typedef struct
{
   uint32_t s_can_type_id;
   uint32_t s_can_baudrate;
   uint32_t s_can_adapt_pres;
}
ts_can_conf;

 extern ts_can_conf can1_conf;
 extern ts_can_conf can2_conf;

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */
/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/* Function CAN 1 WRITE critical service */
extern void can1_critical_write(void);

#endif /* CAN_CRITICAL_PUBLIC_H */
