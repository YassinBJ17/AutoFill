/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the CBIT Treatments function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "CBIT_Public.h"
#include "CBIT_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "Boot_Public.h"
#include "Config_Public.h"
#include "DrvCPU_Public.h"
#include "DrvADC_Public.h"
#include "DrvCAN_Public.h"
#include "DrvECC_Public.h"
#include "DrvFTFC_Public.h"
#include "DrvFTM_Public.h"
#include "DrvGPIO_Public.h"
#include "DrvLPIT_Public.h"
#include "DrvMCM_Public.h"
#include "DrvPAD_Public.h"
#include "DrvPCC_Public.h"
#include "DrvLPSPI_Public.h"
#include "Modes_Public.h"

#include "OVSP_SW_Public.h"


/* ---------- internal define constants: ------------------------------------ */
#define CBIT_DRV_MCM_DEFAULT_VALUE_1                 0x8F020000UL
#define CBIT_DRV_MCM_DEFAULT_VALUE_2                 0x8F021000UL


/* ---------- internal types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* >RELAX<SYNCHRONe_C_Code_24.5> Waiting for SYNCHONe analyze, it seems to be a false violation. */
/* The data are not internal as shared within the CSC. */
uint32_t V_CBIT_ECC_Test_faulty_addr;


/* ---------- provided operation bodies: ------------------------------------ */
/* CBIT_Test_OVSP_Side_Id: To test the OVSP Side Id integrity
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void CBIT_Test_OVSP_Side_Id (void)
{
   uint8_t v_OVSP_Side_Id;

   v_OVSP_Side_Id = Boot_Get_Side_Id ();

   switch (v_OVSP_Side_Id)
   {
      case BOOT_SIDE_ID_HS:
      case BOOT_SIDE_ID_LS:
      {
         V_CBIT_OVSP_Side_Id_Test_Result = E_CBIT_Passed;
      }
      break;

      default:
      {
         V_CBIT_OVSP_Side_Id_Test_Result = E_CBIT_Failed;
      }
      break;

   }
}


/* CBIT_Test_OVSP_Cfg_Integrity: To test the OVSP Config Table integrity
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void CBIT_Test_OVSP_Cfg_Integrity (void)
{
   TE_Config_Integrity_Status v_Cfg_Integrity;

   v_Cfg_Integrity = Config_Get_Integrity_Status ();

   if (E_Config_Integrity_OK == v_Cfg_Integrity)
   {
      V_CBIT_OVSP_Cfg_Integrity = E_CBIT_Passed;
   }
   else
   {
      V_CBIT_OVSP_Cfg_Integrity = E_CBIT_Failed;
   }
}


/* CBIT_Test_EOC_Integrity: To test the OVSP EOC integrity
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void CBIT_Test_EOC_Integrity (void)
{
   uint32_t v_Check_Result;

   DrvFTFC_Check_EOC_32Bit_CRC (&v_Check_Result);

   if (OVSP_SW_RESULT_OK == v_Check_Result)
   {
      V_CBIT_OVSP_EOC_Integrity = E_CBIT_Passed;
   }
   else
   {
      V_CBIT_OVSP_EOC_Integrity = E_CBIT_Failed;
   }
}


/* CBIT_Test_ECC_Int_Single: To log a failure on internal ECC Single error interrupt
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void CBIT_Test_ECC_Int_Single (void)
{
   /* Clear single error */
   DrvECC_ERM_Clear_Single_Err ();

   V_CBIT_ECC_Test_Result.S_ECC_Single_Test = E_CBIT_Failed;
}


/* CBIT_Test_ECC_Int_Multiple: To log a failure on internal ECC Multiple error interrupt
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void CBIT_Test_ECC_Int_Multiple (void)
{
   /* Clear multiple error */
   DrvECC_ERM_Clear_Multiple_Err ();

   V_CBIT_ECC_Test_Result.S_ECC_Mult_Test = E_CBIT_Failed;
}


/* CBIT ECC FTFC Interrupt Double Bit Error: To test interrupt on internal ECC error
 *
 * Parameters:
 *   Inputs: None
 *   Outputs: None
 *
 *  */
void CBIT_ECC_FTFC_Int_Double_Bit_Err (void)
{
   uint32_t v_Status;

   /* Store the FLASH faulty address */
   asm("movw  r1,%lo(V_CBIT_ECC_Test_faulty_addr)");
   asm("movt  r1,%hi(V_CBIT_ECC_Test_faulty_addr)");
   asm("movs  r0,r14");
   asm("str   r0,[r1]");

   if (DRVFTFC_PFLASH_END_ADDR >= V_CBIT_ECC_Test_faulty_addr)
   {
      V_CBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_PFlash = E_CBIT_Failed;
   }
   else
   {
      if ((DRVFTFC_FLEXNVM_START_ADDR <= V_CBIT_ECC_Test_faulty_addr) &&
          (DRVFTFC_FLEXNVM_END_ADDR >= V_CBIT_ECC_Test_faulty_addr))
      {
         V_CBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_NVM = E_CBIT_Failed;
      }
      else
      {
         V_CBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_PFlash = E_CBIT_Failed;
         V_CBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_NVM = E_CBIT_Failed;
      }
   }

   DrvFTFC_Clear_Flash_Fault (&v_Status);

   if (OVSP_SW_RESULT_OK == v_Status)
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }
   else
   {
      V_CBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_PFlash = E_CBIT_Failed;
      V_CBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_NVM = E_CBIT_Failed;
   }
}


void CBIT_Test_DrvADC_RegConfig (void)
{
   uint32_t v_Result;

   DrvADC_Check_RegConfig (&v_Result);

   if (OVSP_SW_RESULT_OK == v_Result)
   {
      V_CBIT_Test_Drivers_Result.S_DrvADC_Test = E_CBIT_Passed;
   }
   else
   {
      V_CBIT_Test_Drivers_Result.S_DrvADC_Test = E_CBIT_Failed;
   }
}

void CBIT_Test_DrvGPIO_RegConfig (void)
{
   uint32_t v_Result;

   DrvGPIO_Check_RegConfig (&v_Result);

   if (OVSP_SW_RESULT_OK == v_Result)
   {
      V_CBIT_Test_Drivers_Result.S_DrvGPIO_Test = E_CBIT_Passed;
   }
   else
   {
      V_CBIT_Test_Drivers_Result.S_DrvGPIO_Test = E_CBIT_Failed;
   }
}

void CBIT_Test_DrvMCM_RegConfig (void)
{
   uint32_t v_Result;

   DrvMCM_Check_CBIT_RegConfig (&v_Result);

   if (OVSP_SW_RESULT_OK == v_Result)
   {
      V_CBIT_Test_Drivers_Result.S_DrvMCM_Test = E_CBIT_Passed;
   }
   else
   {
      V_CBIT_Test_Drivers_Result.S_DrvMCM_Test = E_CBIT_Failed;
   }
}

void CBIT_Test_DrvMCM_FPU_RegConfig (void)
{
   uint32_t v_FPU_FIOC_Result;
   uint32_t v_FPU_FDZC_Result;
   uint32_t v_FPU_FOFC_Result;
   uint32_t v_FPU_FUFC_Result;
   uint32_t v_FPU_FIDC_Result;

   DrvMCM_Check_CBIT_FPU_FIOC (&v_FPU_FIOC_Result);
   DrvMCM_Check_CBIT_FPU_FDZC (&v_FPU_FDZC_Result);
   DrvMCM_Check_CBIT_FPU_FOFC (&v_FPU_FOFC_Result);
   DrvMCM_Check_CBIT_FPU_FUFC (&v_FPU_FUFC_Result);
   DrvMCM_Check_CBIT_FPU_FIDC (&v_FPU_FIDC_Result);

   if (OVSP_SW_RESULT_OK == v_FPU_FIOC_Result)
   {
      V_CBIT_FPU_Test_Result.S_FPU_FIOC_Test = E_CBIT_Passed;
   }
   else
   {
      V_CBIT_FPU_Test_Result.S_FPU_FIOC_Test = E_CBIT_Failed;
   }

   if (OVSP_SW_RESULT_OK == v_FPU_FDZC_Result)
   {
      V_CBIT_FPU_Test_Result.S_FPU_FDZC_Test = E_CBIT_Passed;
   }
   else
   {
      V_CBIT_FPU_Test_Result.S_FPU_FDZC_Test = E_CBIT_Failed;
   }

   if (OVSP_SW_RESULT_OK == v_FPU_FOFC_Result)
   {
      V_CBIT_FPU_Test_Result.S_FPU_FOFC_Test = E_CBIT_Passed;
   }
   else
   {
      V_CBIT_FPU_Test_Result.S_FPU_FOFC_Test = E_CBIT_Failed;
   }

   if (OVSP_SW_RESULT_OK == v_FPU_FUFC_Result)
   {
      V_CBIT_FPU_Test_Result.S_FPU_FUFC_Test = E_CBIT_Passed;
   }
   else
   {
      V_CBIT_FPU_Test_Result.S_FPU_FUFC_Test = E_CBIT_Failed;
   }

   if (OVSP_SW_RESULT_OK == v_FPU_FIDC_Result)
   {
      V_CBIT_FPU_Test_Result.S_FPU_FIDC_Test = E_CBIT_Passed;
   }
   else
   {
      V_CBIT_FPU_Test_Result.S_FPU_FIDC_Test = E_CBIT_Failed;
   }
}


void CBIT_Test_DrvCAN_RegConfig (void)
{
   uint32_t v_Result;

   DrvCAN_Check_RegConfig (&v_Result);

   if (OVSP_SW_RESULT_OK == v_Result)
   {
      V_CBIT_Test_Drivers_Result.S_DrvCAN_Test = E_CBIT_Passed;
   }
   else
   {
      V_CBIT_Test_Drivers_Result.S_DrvCAN_Test = E_CBIT_Failed;
   }
}

void CBIT_Test_DrvLPSPI_RegConfig (void)
{
   uint32_t v_Result;

   DrvLPSPI_Check_RegConfig (&v_Result);

   if (OVSP_SW_RESULT_OK == v_Result)
   {
      V_CBIT_Test_Drivers_Result.S_DrvLPSPI_Test = E_CBIT_Passed;
   }
   else
   {
      V_CBIT_Test_Drivers_Result.S_DrvLPSPI_Test = E_CBIT_Failed;
   }
}

void CBIT_Test_DrvFTM_RegConfig (void)
{
   uint32_t v_Result;

   DrvFTM_Check_Freqs_RegConfig (&v_Result);

   if (OVSP_SW_RESULT_OK == v_Result)
   {
      V_CBIT_Test_Drivers_Result.S_DrvFTM_Test = E_CBIT_Passed;
   }
   else
   {
      V_CBIT_Test_Drivers_Result.S_DrvFTM_Test = E_CBIT_Failed;
   }
}

void CBIT_Test_DrvFTM_CAM_RegConfig (void)
{
   uint32_t v_Result;

   DrvFTM_Check_CAM_RegConfig (&v_Result);

   if (OVSP_SW_RESULT_OK == v_Result)
   {
      V_CBIT_Test_Drivers_Result.S_DrvFTM_CAM_Test = E_CBIT_Passed;
   }
   else
   {
      V_CBIT_Test_Drivers_Result.S_DrvFTM_CAM_Test = E_CBIT_Failed;
   }
}

void CBIT_Test_DrvFTM_TSpeed_RegConfig (void)
{
   uint32_t v_Result;

   DrvFTM_Check_TSpeed_RegConfig (&v_Result);

   if (OVSP_SW_RESULT_OK == v_Result)
   {
      V_CBIT_Test_Drivers_Result.S_DrvFTM_TSpeed_Test = E_CBIT_Passed;
   }
   else
   {
      V_CBIT_Test_Drivers_Result.S_DrvFTM_TSpeed_Test = E_CBIT_Failed;
   }
}

void CBIT_Test_DrvPAD_RegConfig (void)
{
   uint32_t v_Result;

   DrvPAD_check_ports (&v_Result);

   if (OVSP_SW_RESULT_OK == v_Result)
   {
      V_CBIT_Test_Drivers_Result.S_DrvPAD_Test = E_CBIT_Passed;
   }
   else
   {
      V_CBIT_Test_Drivers_Result.S_DrvPAD_Test = E_CBIT_Failed;
   }
}

void CBIT_Test_DrvPCC_RegConfig (void)
{
   uint32_t v_Result;

   DrvPCC_Check_RegConfig (&v_Result);

   if (OVSP_SW_RESULT_OK == v_Result)
   {
      V_CBIT_Test_Drivers_Result.S_DrvPCC_Test = E_CBIT_Passed;
   }
   else
   {
      V_CBIT_Test_Drivers_Result.S_DrvPCC_Test = E_CBIT_Failed;
   }
}

void CBIT_Test_DrvFTFC_RegConfig (void)
{
   uint32_t v_Result;

   DrvFTFC_Check_RegConfig (&v_Result);

   if (OVSP_SW_RESULT_OK == v_Result)
   {
      V_CBIT_Test_Drivers_Result.S_DrvFTFC_Test = E_CBIT_Passed;
   }
   else
   {
      V_CBIT_Test_Drivers_Result.S_DrvFTFC_Test = E_CBIT_Failed;
   }
}

void CBIT_Test_DrvLPIT_RegConfig (void)
{
   uint32_t v_Result;

   DrvLPIT_Check_Run_RegConfig (&v_Result);

   if (OVSP_SW_RESULT_OK == v_Result)
   {
      V_CBIT_Test_Drivers_Result.S_DrvLPIT_Test = E_CBIT_Passed;
   }
   else
   {
      V_CBIT_Test_Drivers_Result.S_DrvLPIT_Test = E_CBIT_Failed;
   }
}

void CBIT_Test_Drivers (void)
{
   TE_Modes_SW_Mode v_SW_Mode;

   v_SW_Mode = Modes_Get_SW_Mode ();

   CBIT_Test_DrvADC_RegConfig ();
   CBIT_Test_DrvFTM_CAM_RegConfig ();
   CBIT_Test_DrvCAN_RegConfig ();
   CBIT_Test_DrvFTFC_RegConfig ();
   CBIT_Test_DrvGPIO_RegConfig ();
   CBIT_Test_DrvLPIT_RegConfig ();
   CBIT_Test_DrvMCM_RegConfig ();
   CBIT_Test_DrvMCM_FPU_RegConfig ();
   CBIT_Test_DrvPAD_RegConfig ();
   CBIT_Test_DrvPCC_RegConfig ();
   CBIT_Test_DrvLPSPI_RegConfig ();

   if (E_Modes_TriggeredTest == v_SW_Mode)
   {
      CBIT_Test_DrvFTM_TSpeed_RegConfig ();
   }
   else
   {
      CBIT_Test_DrvFTM_RegConfig ();
   }
}
