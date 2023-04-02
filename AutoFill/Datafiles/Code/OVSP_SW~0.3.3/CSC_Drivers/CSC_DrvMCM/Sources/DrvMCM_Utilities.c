/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvMCM CSC Utilities functions
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvMCM_Public.h"
#include "DrvMCM_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "MCP_Types.h"
#include "DrvCPU_Public.h"
#include "OVSP_SW_Public.h"

/* ---------- internal define constants: ------------------------------------ */
/* None */


/* ---------- internal types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- internal constants: ------------------------------------------- */
/* None */


/* ---------- internal data: ------------------------------------------------ */
/* None */


/* ---------- internal operations: ------------------------------------------ */
/* None */


/* ---------- provided operation bodies: ------------------------------------ */
/* DrvMCM_Reset_ISCR : To reset the DrvMCM ISCR register
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvMCM_Reset_ISCR (void)
{
   C_DrvMCM_Registers->S_ISCR = DRVMCM_ISCR_CONFIG;
}

/* CBIT FPU Interrupt Global Error Handler: To test interrupt on internal FPU error
 *
 * Parameters:
 *   Inputs: None
 *   Outputs: None
 *
 *  */
void DrvMCM_Check_CBIT_FPU_FIOC (uint32_t * p_pt_Check_Result)
{
   if (V_DrvMCM_CBIT_FPU_FIOC_status == OVSP_SW_RESULT_OK)
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_OK;
   }
   else
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;  
   }
}

void DrvMCM_Check_CBIT_FPU_FDZC (uint32_t * p_pt_Check_Result)
{
   if (V_DrvMCM_CBIT_FPU_FDZC_status == OVSP_SW_RESULT_OK)
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_OK;
   }
   else
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;  
   }
}

void DrvMCM_Check_CBIT_FPU_FOFC (uint32_t * p_pt_Check_Result)
{   
   if (V_DrvMCM_CBIT_FPU_FOFC_status == OVSP_SW_RESULT_OK)
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_OK;
   }
   else
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;  
   }
}

void DrvMCM_Check_CBIT_FPU_FUFC (uint32_t * p_pt_Check_Result)
{   
   if (V_DrvMCM_CBIT_FPU_FUFC_status == OVSP_SW_RESULT_OK)
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_OK;
   }
   else
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;  
   }
}


void DrvMCM_Check_CBIT_FPU_FIDC (uint32_t * p_pt_Check_Result)
{   
   if (V_DrvMCM_CBIT_FPU_FIDC_status == OVSP_SW_RESULT_OK)
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_OK;
   }
   else
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;  
   }
}


void DrvMCM_Check_PBIT_FPU_FIOC (uint32_t * p_pt_Check_Result, uint32_t p_generated_errors)
{
   if ((V_DrvMCM_PBIT_FPU_FIOC_status == OVSP_SW_RESULT_OK) &&
       (DRVMCM_FPU_FIOC_ERROR_NB == V_DrvMCM_PBIT_FPU_FIOC_Cnt) ||
       (DRVMCM_FPU_FIOC_ERROR_NB == p_generated_errors))
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_OK;
   }
   else
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;  
   }
}


void DrvMCM_Check_PBIT_FPU_FDZC (uint32_t * p_pt_Check_Result)
{
   if (V_DrvMCM_PBIT_FPU_FDZC_status == OVSP_SW_RESULT_OK)
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_OK;
   }
   else
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;  
   }
}


void DrvMCM_Check_PBIT_FPU_FOFC (uint32_t * p_pt_Check_Result)
{   
   if (V_DrvMCM_PBIT_FPU_FOFC_status == OVSP_SW_RESULT_OK)
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_OK;
   }
   else
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;  
   }
}


void DrvMCM_Check_PBIT_FPU_FUFC (uint32_t * p_pt_Check_Result)
{   
   if (V_DrvMCM_PBIT_FPU_FUFC_status == OVSP_SW_RESULT_OK)
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_OK;
   }
   else
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;  
   }
}


void DrvMCM_Check_PBIT_FPU_FIDC (uint32_t * p_pt_Check_Result)
{   
   if (V_DrvMCM_CBIT_FPU_FIDC_status == OVSP_SW_RESULT_OK)
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_OK;
   }
   else
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;  
   }
}


void DrvMCM_Check_PBIT_FPU_FIXC (uint32_t * p_pt_Check_Result)
{   
   if (V_DrvMCM_PBIT_FPU_FIXC_status == OVSP_SW_RESULT_OK)
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_OK;
   }
   else
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;  
   }
}


/* PBIT FPU Interrupt Global Error Handler: To test interrupt on internal FPU error
 *
 * Parameters:
 *   Inputs: None
 *   Outputs: None
 *
 *  */
void DrvMCM_Check_PBIT_FPU_IRQ (void)
{

   uint32_t v_FPU_int_flags;

   v_FPU_int_flags = C_DrvMCM_Registers->S_ISCR;

   DrvCPU_Init_FPSCR_Reg ();

   if (DRVMCM_ISCR_FIOC_MASK == (v_FPU_int_flags & DRVMCM_ISCR_FIOC_MASK))
   {
      V_DrvMCM_PBIT_FPU_FIOC_status = OVSP_SW_RESULT_OK;
      V_DrvMCM_PBIT_FPU_FIOC_Cnt++;
      v_FPU_int_flags &= ~ DRVMCM_ISCR_FIOCE_MASK;
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }

   if (DRVMCM_ISCR_FDZC_MASK == (v_FPU_int_flags & DRVMCM_ISCR_FDZC_MASK))
   {
      V_DrvMCM_PBIT_FPU_FDZC_status = OVSP_SW_RESULT_OK;
      v_FPU_int_flags &= ~ DRVMCM_ISCR_FDZCE_MASK;
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }

   if (DRVMCM_ISCR_FOFC_MASK == (v_FPU_int_flags & DRVMCM_ISCR_FOFC_MASK))
   {
      V_DrvMCM_PBIT_FPU_FOFC_status = OVSP_SW_RESULT_OK;
      v_FPU_int_flags &= ~ DRVMCM_ISCR_FOFCE_MASK;
   }

   if (DRVMCM_ISCR_FUFC_MASK == (v_FPU_int_flags & DRVMCM_ISCR_FUFC_MASK))
   {
      V_DrvMCM_PBIT_FPU_FUFC_status = OVSP_SW_RESULT_OK;
      v_FPU_int_flags &= ~ DRVMCM_ISCR_FUFCE_MASK;
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }

   if (DRVMCM_ISCR_FIXC_MASK == (v_FPU_int_flags & DRVMCM_ISCR_FIXC_MASK))
   {
      V_DrvMCM_PBIT_FPU_FIXC_status = OVSP_SW_RESULT_OK;
      v_FPU_int_flags &= ~ DRVMCM_ISCR_FIXCE_MASK;
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }

   if (DRVMCM_ISCR_FIDC_MASK == (v_FPU_int_flags & DRVMCM_ISCR_FIDC_MASK))
   {
      V_DrvMCM_CBIT_FPU_FIDC_status = OVSP_SW_RESULT_OK;
      v_FPU_int_flags &= ~ DRVMCM_ISCR_FIDCE_MASK;
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }

   C_DrvMCM_Registers->S_ISCR = v_FPU_int_flags;

   DrvCPU_Init_FPU_Sn_Reg ();
}

/* CBIT FPU Interrupt Global Error Handler: To test interrupt on internal FPU error
 *
 * Parameters:
 *   Inputs: None
 *   Outputs: None
 *
 *  */
void DrvMCM_Check_CBIT_FPU_IRQ (void)
{
   uint32_t v_FPU_int_flags;

   v_FPU_int_flags = C_DrvMCM_Registers->S_ISCR;

   DrvCPU_Init_FPSCR_Reg ();

   if (DRVMCM_ISCR_FIOC_MASK == (v_FPU_int_flags & DRVMCM_ISCR_FIOC_MASK))
   {
      V_DrvMCM_CBIT_FPU_FIOC_status = OVSP_SW_RESULT_FAILED;
      v_FPU_int_flags &= ~DRVMCM_ISCR_FIOCE_MASK;
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }
   
   if (DRVMCM_ISCR_FDZC_MASK == (v_FPU_int_flags & DRVMCM_ISCR_FDZC_MASK))
   {
      V_DrvMCM_CBIT_FPU_FDZC_status = OVSP_SW_RESULT_FAILED;
      v_FPU_int_flags &= ~DRVMCM_ISCR_FDZCE_MASK;
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }
   
   if (DRVMCM_ISCR_FOFC_MASK == (v_FPU_int_flags & DRVMCM_ISCR_FOFC_MASK))
   {
      V_DrvMCM_CBIT_FPU_FOFC_status = OVSP_SW_RESULT_FAILED;
      v_FPU_int_flags &= ~DRVMCM_ISCR_FOFCE_MASK;
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }
   
   if (DRVMCM_ISCR_FUFC_MASK == (v_FPU_int_flags & DRVMCM_ISCR_FUFC_MASK))
   {
      V_DrvMCM_CBIT_FPU_FUFC_status = OVSP_SW_RESULT_FAILED;
      v_FPU_int_flags &= ~DRVMCM_ISCR_FUFCE_MASK;
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }
   
   if (DRVMCM_ISCR_FIDC_MASK == (v_FPU_int_flags & DRVMCM_ISCR_FIDC_MASK))
   {
      V_DrvMCM_CBIT_FPU_FIDC_status = OVSP_SW_RESULT_FAILED;
      v_FPU_int_flags &= ~DRVMCM_ISCR_FIDCE_MASK;
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }

   C_DrvMCM_Registers->S_ISCR = v_FPU_int_flags;

   DrvCPU_Init_FPU_Sn_Reg ();
}

void DrvMCM_Inhibit_FPU_FIXC (void)
{
   uint32_t v_FPU_int_flags;
 
   v_FPU_int_flags = C_DrvMCM_Registers->S_ISCR;
   /* After the test, we inhibit the Float Inexact interrupt for PBITs */
   v_FPU_int_flags &= ~ DRVMCM_ISCR_FIXCE_MASK;

   C_DrvMCM_Registers->S_ISCR = v_FPU_int_flags;
}
