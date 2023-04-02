/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef CBIT_PRIVATE_H
#define CBIT_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "CBIT_Public.h"
#include "DrvECC_Public.h"

#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
/* None */


/* ---------- provided types: ----------------------------------------------- */
typedef struct
{
   TE_CBIT_Test_Result S_ECC_Single_Test;
   TE_CBIT_Test_Result S_ECC_Mult_Test;
   TE_CBIT_Test_Result S_ECC_FTFC_Double_Test_PFlash;
   TE_CBIT_Test_Result S_ECC_FTFC_Double_Test_NVM;
} TS_CBIT_ECC_Test_Result;

typedef struct
{
   TE_CBIT_Test_Result S_DrvADC_Test;
   TE_CBIT_Test_Result S_DrvCAN_Test;
   TE_CBIT_Test_Result S_DrvFTFC_Test;
   TE_CBIT_Test_Result S_DrvFTM_Test;
   TE_CBIT_Test_Result S_DrvFTM_CAM_Test;
   TE_CBIT_Test_Result S_DrvFTM_TSpeed_Test;
   TE_CBIT_Test_Result S_DrvGPIO_Test;
   TE_CBIT_Test_Result S_DrvLPSPI_Test;
   TE_CBIT_Test_Result S_DrvMCM_Test;
   TE_CBIT_Test_Result S_DrvPCC_Test;
   TE_CBIT_Test_Result S_DrvPAD_Test;
   TE_CBIT_Test_Result S_DrvLPIT_Test;
} TS_CBIT_DRV_Test_Result;

typedef struct
{
   TE_CBIT_Test_Result S_FPU_FIOC_Test;
   TE_CBIT_Test_Result S_FPU_FDZC_Test;
   TE_CBIT_Test_Result S_FPU_FOFC_Test;
   TE_CBIT_Test_Result S_FPU_FUFC_Test;
   TE_CBIT_Test_Result S_FPU_FIXC_Test;
   TE_CBIT_Test_Result S_FPU_FIDC_Test;
} TS_CBIT_FPU_Test_Result;


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
extern TE_CBIT_Test_Result V_CBIT_Test_Result;

extern TE_CBIT_Test_Result V_CBIT_OVSP_Side_Id_Test_Result;
extern TE_CBIT_Test_Result V_CBIT_OVSP_Cfg_Integrity;
extern TE_CBIT_Test_Result V_CBIT_OVSP_EOC_Integrity;

extern TS_CBIT_ECC_Test_Result V_CBIT_ECC_Test_Result;
extern TS_CBIT_FPU_Test_Result V_CBIT_FPU_Test_Result;
extern TS_CBIT_DRV_Test_Result V_CBIT_Test_Drivers_Result;


/* ---------- provided operations: ------------------------------------------ */
extern void CBIT_Treatments_Synthesis (void);

extern void CBIT_Test_Drivers (void);

extern void CBIT_Test_DrvADC_RegConfig (void);
extern void CBIT_Test_DrvFTM_CAM_RegConfig (void);
extern void CBIT_Test_DrvCAN_RegConfig (void);
extern void CBIT_Test_DrvFTFC_RegConfig (void);
extern void CBIT_Test_DrvFTM_RegConfig (void);
extern void CBIT_Test_DrvGPIO_RegConfig (void);
extern void CBIT_Test_DrvLPIT_RegConfig (void);
extern void CBIT_Test_DrvMCM_RegConfig (void);
extern void CBIT_Test_DrvMCM_FPU_RegConfig (void);
extern void CBIT_Test_DrvFTM_TSpeed_RegConfig (void);
extern void CBIT_Test_DrvPAD_RegConfig (void);
extern void CBIT_Test_DrvPCC_RegConfig (void);
extern void CBIT_Test_DrvLPSPI_RegConfig (void);

extern void CBIT_Test_OVSP_Side_Id (void);
extern void CBIT_Test_EOC_Integrity (void);
extern void CBIT_Test_OVSP_Cfg_Integrity (void);


#endif /* CBIT_PRIVATE_H */
