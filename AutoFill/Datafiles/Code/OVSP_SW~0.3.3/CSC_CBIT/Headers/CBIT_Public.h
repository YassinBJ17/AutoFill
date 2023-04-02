/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef CBIT_PUBLIC_H
#define CBIT_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
/* None */


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
/* None */


/* ---------- provided types: ----------------------------------------------- */
typedef enum
{
   E_CBIT_Passed      = 0,
   E_CBIT_Failed      = 1,
   E_CBIT_Fatal_Error = 2,
} TE_CBIT_Test_Result;


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- provided operations: ------------------------------------------ */
extern void CBIT_Initialize (void);

extern void CBIT_Treatments_RTC (void);
extern void CBIT_Treatments_BckGrnd (void);

extern void CBIT_Test_ECC_Int_Single (void);
extern void CBIT_Test_ECC_Int_Multiple (void);
extern void CBIT_ECC_FTFC_Int_Double_Bit_Err (void);

extern void CBIT_FPU_Int_global_handler (void);

extern TE_CBIT_Test_Result CBIT_Get_Test_Result (void);


#endif /* CBIT_PUBLIC_H */
