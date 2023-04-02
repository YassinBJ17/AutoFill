/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DRVMCM_PRIVATE_H
#define DRVMCM_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
#define DRVMCM_MCM_ADDRESS        0xE0080000UL

#define DRVMCM_ISCR_CONFIG        0x9F020000UL

#define DRVMCM_FPU_FIOC_ERROR_NB  14UL
/* ---------- provided types: ----------------------------------------------- */
typedef struct
{
   uint32_t S_MCM_Reserved_1 [2];
   uint16_t S_PLASC;
   uint16_t S_PLAMC;
   uint32_t S_CPCR;
   uint32_t S_ISCR;
   uint32_t S_MCM_Reserved_2 [7];
   uint32_t S_PID;
   uint32_t S_MCM_Reserved_3 [3];
   uint32_t S_CPO;
   uint32_t S_MCM_Reserved_4 [239];
   uint32_t S_LMDR0;
   uint32_t S_LMDR1;
   uint32_t S_LMDR2;
   uint32_t S_MCM_Reserved_5 [29];
   uint32_t S_LMPECR;
   uint32_t S_MCM_Reserved_6;
   uint32_t S_LMPEIR;
   uint32_t S_MCM_Reserved_7;
   uint32_t S_LMFAR;
   uint32_t S_LMFATR;
   uint32_t S_MCM_Reserved_8 [2];
   uint32_t S_LMFDHR;
   uint32_t S_LMFDLR;
} TS_DrvMCM_Registers;


/* ---------- provided constants: ------------------------------------------- */
extern TS_DrvMCM_Registers * const C_DrvMCM_Registers;


/* ---------- provided data: ------------------------------------------------ */
extern volatile uint32_t V_DrvMCM_PBIT_FPU_FIOC_Cnt;
extern uint32_t V_DrvMCM_PBIT_FPU_FIOC_status;
extern uint32_t V_DrvMCM_PBIT_FPU_FDZC_status;
extern uint32_t V_DrvMCM_PBIT_FPU_FOFC_status;
extern uint32_t V_DrvMCM_PBIT_FPU_FUFC_status;
extern uint32_t V_DrvMCM_PBIT_FPU_FIXC_status;
extern uint32_t V_DrvMCM_PBIT_FPU_FIDC_status;

extern uint32_t V_DrvMCM_CBIT_FPU_FIOC_status;
extern uint32_t V_DrvMCM_CBIT_FPU_FDZC_status;
extern uint32_t V_DrvMCM_CBIT_FPU_FOFC_status;
extern uint32_t V_DrvMCM_CBIT_FPU_FUFC_status;
extern uint32_t V_DrvMCM_CBIT_FPU_FIDC_status;

/* ---------- provided operations: ------------------------------------------ */
/* None */


#endif /* DRVMCM_PRIVATE_H */
