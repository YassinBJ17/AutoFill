/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DRVCAN_PUBLIC_H
#define DRVCAN_PUBLIC_H

/* ---------- include predefined types: ------------------------------------- */
#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
#define DRVCAN_FRAME_32BIT_NB     2UL

#define DRVCAN_RXQUEUE0_ID        0UL
#define DRVCAN_RXQUEUE1_ID        1UL

#define DRVCAN_TX_DATA_MB_ID      10UL
#define DRVCAN_TX_SW_INFO_MB_ID   11UL


/* ---------- provided types: ----------------------------------------------- */
typedef struct
{
   uint32_t S_TxId;
   uint32_t S_TxData [DRVCAN_FRAME_32BIT_NB];
} TS_DrvCAN_TxFrame;

typedef struct
{
   uint32_t S_RxId;
   uint32_t S_RxData [DRVCAN_FRAME_32BIT_NB];
} TS_DrvCAN_RxFrame;


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- provided operations: ------------------------------------------ */
extern void DrvCAN_Initialize (void);

extern void DrvCAN_Read (void);

extern void DrvCAN_Write (const uint32_t p_TxMB_Id, const TS_DrvCAN_TxFrame * const p_pt_TxFrame);

extern void DrvCAN_Get_RxFrame_FromQueue (TS_DrvCAN_RxFrame * const p_pt_RxFrame, const uint32_t p_RxQueue_Id);

extern void DrvCAN_Check_RegConfig (uint32_t * const p_pt_Check_Result);


#endif /* DRVCAN_PUBLIC_H */
