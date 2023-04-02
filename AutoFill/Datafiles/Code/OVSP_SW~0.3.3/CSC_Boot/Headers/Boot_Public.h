/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef BOOT_PUBLIC_H
#define BOOT_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
#define BOOT_SIDE_ID_HS        ((uint8_t) 0xA5)
#define BOOT_SIDE_ID_LS        ((uint8_t) 0x5A)
#define BOOT_SIDE_ID_INVALID   ((uint8_t) 0xFF)


/* ---------- provided types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- provided operations: ------------------------------------------ */
extern void Boot_Initialize (void);

extern void Boot_Handle_NMI (void);
extern void Boot_Handle_HardFault (void);

extern uint8_t Boot_Get_Side_Id (void);


#endif /* BOOT_PUBLIC_H */
