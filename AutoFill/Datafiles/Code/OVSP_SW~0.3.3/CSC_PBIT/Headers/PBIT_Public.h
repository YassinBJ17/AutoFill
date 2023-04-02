/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef PBIT_PUBLIC_H
#define PBIT_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
/* None */


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
/* None */


/* ---------- provided types: ----------------------------------------------- */
typedef enum
{
   E_PBIT_Passed = 0,
   E_PBIT_Failed = 1
} TE_PBIT_Test_Result;


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- provided operations: ------------------------------------------ */
extern void PBIT_Initialize (void);

extern void PBIT_Treatments (void);

extern void PBIT_Test_OVSP_Side_Id (void);

extern void PBIT_Test_OVSP_Cfg_Integrity (void);
extern void PBIT_Test_EOC_Integrity (void);

extern void PBIT_Test_ECC_Int_Single_Error(void);
extern void PBIT_Test_ECC_Int_Multiple_Error(void);
extern void PBIT_ECC_Generate_Single_Mult_Tests(void);
extern void PBIT_ECC_FTFC_Int_Double_Bit_Err (void);
extern void PBIT_ECC_FTFC_Generate_Double_Bit_Err (void);

extern void PBIT_Test_RAM (void);

extern void PBIT_Test_DrvMCM_FPU_RegConfig (void);

extern void PBIT_Treatments_Synthesis (void);

extern TE_PBIT_Test_Result PBIT_Get_Test_Result (void);


#endif /* PBIT_PUBLIC_H */
