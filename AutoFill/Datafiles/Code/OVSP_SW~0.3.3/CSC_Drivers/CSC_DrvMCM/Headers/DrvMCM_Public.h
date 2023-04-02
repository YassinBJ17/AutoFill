/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DRVMCM_PUBLIC_H
#define DRVMCM_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
#define DRVMCM_ISCR_FIOC_MASK                       0x00000100UL
#define DRVMCM_ISCR_FIOC_SHIFT                      8UL

#define DRVMCM_ISCR_FDZC_MASK                       0x00000200UL
#define DRVMCM_ISCR_FDZC_SHIFT                      9UL

#define DRVMCM_ISCR_FOFC_MASK                       0x00000400UL
#define DRVMCM_ISCR_FOFC_SHIFT                      10UL

#define DRVMCM_ISCR_FUFC_MASK                       0x00000800UL
#define DRVMCM_ISCR_FUFC_SHIFT                      11UL

#define DRVMCM_ISCR_FIXC_MASK                       0x00001000UL
#define DRVMCM_ISCR_FIXC_SHIFT                      12UL

#define DRVMCM_ISCR_FIDC_MASK                       0x00008000UL
#define DRVMCM_ISCR_FIDC_SHIFT                      15UL

#define DRVMCM_ISCR_FIOCE_MASK                      0x01000000UL
#define DRVMCM_ISCR_FDZCE_MASK                      0x02000000UL
#define DRVMCM_ISCR_FOFCE_MASK                      0x04000000UL
#define DRVMCM_ISCR_FUFCE_MASK                      0x08000000UL
#define DRVMCM_ISCR_FIXCE_MASK                      0x10000000UL
#define DRVMCM_ISCR_FIDCE_MASK                      0x80000000UL

#define DRVMCM_CBIT_VALID_CONFIG_1                  0x8F020000UL
#define DRVMCM_CBIT_VALID_CONFIG_2                  0x8F021000UL

#define DRVMCM_PBIT_VALID_CONFIG_1                  0x9F020000UL
#define DRVMCM_PBIT_VALID_CONFIG_2                  0x9F021000UL
/* ---------- provided types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- provided operations: ------------------------------------------ */
extern void DrvMCM_Initialize (void);

extern void DrvMCM_Check_PBIT_RegConfig (uint32_t * p_pt_Check_Result);
extern void DrvMCM_Check_CBIT_RegConfig (uint32_t * p_pt_Check_Result);

extern void DrvMCM_Check_PBIT_FPU_IRQ (void);
extern void DrvMCM_Check_PBIT_FPU_FIOC (uint32_t * p_pt_Check_Result, uint32_t p_generated_errors);
extern void DrvMCM_Check_PBIT_FPU_FDZC (uint32_t * p_pt_Check_Result);
extern void DrvMCM_Check_PBIT_FPU_FOFC (uint32_t * p_pt_Check_Result);
extern void DrvMCM_Check_PBIT_FPU_FUFC (uint32_t * p_pt_Check_Result);
extern void DrvMCM_Check_PBIT_FPU_FIDC (uint32_t * p_pt_Check_Result);
extern void DrvMCM_Check_PBIT_FPU_FIXC (uint32_t * p_pt_Check_Result);

extern void DrvMCM_Check_CBIT_FPU_IRQ (void);
extern void DrvMCM_Check_CBIT_FPU_FIOC (uint32_t * p_pt_Check_Result);
extern void DrvMCM_Check_CBIT_FPU_FDZC (uint32_t * p_pt_Check_Result);
extern void DrvMCM_Check_CBIT_FPU_FOFC (uint32_t * p_pt_Check_Result);
extern void DrvMCM_Check_CBIT_FPU_FUFC (uint32_t * p_pt_Check_Result);
extern void DrvMCM_Check_CBIT_FPU_FIDC (uint32_t * p_pt_Check_Result);

extern void DrvMCM_Inhibit_FPU_FIXC (void);

extern void DrvMCM_Reset_ISCR (void);

#endif /* DRVMCM_PUBLIC_H */
