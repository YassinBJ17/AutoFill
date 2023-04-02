/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef PBIT_PRIVATE_H
#define PBIT_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "PBIT_Public.h"
#include "DrvECC_Public.h"

#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
/* None */


/* ---------- provided types: ----------------------------------------------- */
typedef struct
{
    TE_PBIT_Test_Result S_ECC_Single_Test;
    TE_PBIT_Test_Result S_ECC_Mult_Test;
    TE_PBIT_Test_Result S_ECC_FTFC_Double_Test_PFlash;
    TE_PBIT_Test_Result S_ECC_FTFC_Double_Test_NVM;
} TS_PBIT_ECC_Test_Result;


typedef struct
{
    TE_PBIT_Test_Result S_DrvMCM_Test;
    TE_PBIT_Test_Result S_DrvCAN_Test;
    TE_PBIT_Test_Result S_DrvLPSPI_Test;
    TE_PBIT_Test_Result S_DrvGPIO_Test;
    TE_PBIT_Test_Result S_DrvFTM_Test;
    TE_PBIT_Test_Result S_DrvFTFC_Test;
    TE_PBIT_Test_Result S_DrvFTM_CAM_Test;
    TE_PBIT_Test_Result S_DrvADC_Test;
    TE_PBIT_Test_Result S_DrvPCC_Test;
    TE_PBIT_Test_Result S_DrvPAD_Test;
    TE_PBIT_Test_Result S_DrvLPIT_Test;
} TS_PBIT_Drv_Test_Result;


typedef struct
{
    TE_PBIT_Test_Result S_FPU_FIOC_Test;
    TE_PBIT_Test_Result S_FPU_FDZC_Test;
    TE_PBIT_Test_Result S_FPU_FOFC_Test;
    TE_PBIT_Test_Result S_FPU_FUFC_Test;
    TE_PBIT_Test_Result S_FPU_FIXC_Test;
    TE_PBIT_Test_Result S_FPU_FIDC_Test;
} TS_PBIT_FPU_Test_Result;


/* ---------- provided constants: ------------------------------------------- */
extern TS_PBIT_ECC_Test_Result V_PBIT_ECC_Test_Result;
extern TS_PBIT_FPU_Test_Result V_PBIT_FPU_Test_Result;
extern TS_PBIT_Drv_Test_Result V_PBIT_Test_Drivers_Result;
extern TE_PBIT_Test_Result V_PBIT_RAM_Test_Result;
extern TE_PBIT_Test_Result V_PBIT_OVSP_Side_Id_Test_Result;
extern TE_PBIT_Test_Result V_PBIT_OVSP_Cfg_Integrity;
extern TE_PBIT_Test_Result V_PBIT_OVSP_EOC_Integrity;

extern uint32_t V_PBIT_ECC_Cpt_FTFC;
extern uint32_t V_PBIT_FPU_Generated_FIOC_Faults;


/* ---------- provided data: ------------------------------------------------ */
extern TE_PBIT_Test_Result V_PBIT_Test_Result;

extern void PBIT_Test_DrvMCM_Registers (void);
extern void PBIT_Test_DrvCAN_Registers (void);
extern void PBIT_Test_DrvLPSPI_Registers (void);
extern void PBIT_Test_DrvFTM_Registers (void);
extern void PBIT_Test_DrvCAM_Registers (void);
extern void PBIT_Test_DrvPAD_Registers (void);
extern void PBIT_Test_DrvPCC_Registers (void);
extern void PBIT_Test_DrvGPIO_Registers (void);
extern void PBIT_Test_DrvFTFC_Registers (void);
extern void PBIT_Test_DrvADC_Registers (void);
extern void PBIT_Test_DrvLPIT_Registers (void);

extern void PBIT_Test_Drivers_Ressources (void);


/* ---------- provided operations: ------------------------------------------ */
/* None */


#endif /* PBIT_PRIVATE_H */
