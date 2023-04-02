/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DRVWDOG_PRIVATE_H
#define DRVWDOG_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
#define DRVWDOG_WDOG_ADDRESS         0x40052000UL

#define DRVWDOG_UNLOCK_WATCHDOG      0xD928C520UL
#define DRVWDOG_DISABLE_WATCHDOG     0x00002120UL
#define DRVWDOG_INITIALIZE_TIMEOUT   0x0000FFFFUL


/* ---------- provided types: ----------------------------------------------- */
typedef struct
{
   uint32_t S_CS;
   uint32_t S_CNT;
   uint32_t S_TOVAL;
   uint32_t S_WIN;
} TS_DrvWDOG_Registers;


/* ---------- provided constants: ------------------------------------------- */
extern TS_DrvWDOG_Registers * const C_DrvWDOG_Registers;


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- provided operations: ------------------------------------------ */
/* None */


#endif /* DRVWDOG_PRIVATE_H */
