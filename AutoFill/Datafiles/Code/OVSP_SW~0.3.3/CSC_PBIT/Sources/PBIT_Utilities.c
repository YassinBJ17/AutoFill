/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the PBIT Treatments function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "PBIT_Public.h"
#include "PBIT_Private.h"


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
#include "DrvNVIC_Public.h"
#include "DrvPAD_Public.h"
#include "DrvPCC_Public.h"
#include "DrvLPSPI_Public.h"

#include "OVSP_SW_Public.h"


/* ---------- internal define constants: ------------------------------------ */
/* None */


/* ---------- internal types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- provided operation bodies: ------------------------------------ */
/* PBIT_Test_OVSP_Side_Id: To test the OVSP Side Id integrity
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void PBIT_Test_OVSP_Side_Id (void)
{
   uint8_t v_OVSP_Side_Id;

   v_OVSP_Side_Id = Boot_Get_Side_Id ();

   switch (v_OVSP_Side_Id)
   {
      case BOOT_SIDE_ID_HS:
      case BOOT_SIDE_ID_LS:
      {
         V_PBIT_OVSP_Side_Id_Test_Result = E_PBIT_Passed;
      }
      break;

      default:
      {
         V_PBIT_OVSP_Side_Id_Test_Result = E_PBIT_Failed;
      }
      break;

   }   
}


/* PBIT_Test_OVSP_Cfg_Integrity: To test the OVSP Config Table integrity
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void PBIT_Test_OVSP_Cfg_Integrity (void)
{
   TE_Config_Integrity_Status v_Cfg_Integrity;

   v_Cfg_Integrity = Config_Get_Integrity_Status ();

   if (E_Config_Integrity_OK == v_Cfg_Integrity)
   {
      V_PBIT_OVSP_Cfg_Integrity = E_PBIT_Passed;
   }
   else
   {
      V_PBIT_OVSP_Cfg_Integrity = E_PBIT_Failed;
   }
}


/* PBIT_Test_EOC_Integrity: To test the OVSP EOC integrity
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void PBIT_Test_EOC_Integrity (void)
{
   uint32_t v_Check_Result;

   DrvFTFC_Check_EOC_32Bit_CRC (&v_Check_Result);

   if (OVSP_SW_RESULT_OK == v_Check_Result)
   {
      V_PBIT_OVSP_EOC_Integrity = E_PBIT_Passed;
   }
   else
   {
      V_PBIT_OVSP_EOC_Integrity = E_PBIT_Failed;
   }
}

/* PBIT_Test_ECC_Int_Single_Error: To test interrupt on internal ECC error
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void PBIT_Test_ECC_Int_Single_Error (void)
{
   /* Clear single error */
   DrvECC_ERM_Clear_Single_Err ();

   V_PBIT_ECC_Test_Result.S_ECC_Single_Test = E_PBIT_Passed;
}


/* PBIT_Test_ECC_Int_Multiple_Error: To test interrupt on internal ECC error
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void PBIT_Test_ECC_Int_Multiple_Error (void)
{
   /* clear multiple error */
   DrvECC_ERM_Clear_Multiple_Err ();

   V_PBIT_ECC_Test_Result.S_ECC_Mult_Test = E_PBIT_Passed;
}


/* PBIT_ECC_Generate_Single_Mult_Tests: To generate single-bit errors to test interrupts on internal ECC error
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void PBIT_ECC_Generate_Single_Mult_Tests (void)
{
   DrvNVIC_Initialize (DRVNVIC_BOOT_IRQ_SELECTION);
   
   DrvECC_Generate_SingMultErr ();
}


/* PBIT_ECC_FTFC_Int_Double_Bit_Err: To generate double-bit errors to test 
 *                                   interrupts on internal ECC error
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void PBIT_ECC_FTFC_Int_Double_Bit_Err (void)
{
   uint32_t v_Result;

   DrvFTFC_Clear_Flash_Fault (&v_Result);

   switch (V_PBIT_ECC_Cpt_FTFC)
   {
      case 0UL:
      {
         if (OVSP_SW_RESULT_OK == v_Result)
         {
            V_PBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_PFlash = E_PBIT_Passed;
         }
         else
         {
            V_PBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_PFlash = E_PBIT_Failed;
         }
      }
      break;

      case 1UL:
      {
         if (OVSP_SW_RESULT_OK == v_Result)
         {
            V_PBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_NVM = E_PBIT_Passed;
         }
         else
         {
            V_PBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_NVM = E_PBIT_Failed;
         }
      }
      break;

      default:
      { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
         /* Nothing to do */
      }
      break;

   }

   V_PBIT_ECC_Cpt_FTFC++;
}

/* PBIT ECC FTFC Generate Double Bit Error: To test interrupt on internal ECC error
 *
 * Parameters:
 *   Inputs: None
 *   Outputs: None
 *
 *  */
void PBIT_ECC_FTFC_Generate_Double_Bit_Err (void)
{
   volatile uint32_t v_test_value;

   uint32_t v_Result;
   
   DrvNVIC_Initialize (DRVNVIC_BOOT_IRQ_SELECTION);

   /* Prepare PFlash ECC test configuration */
   C_PtF_DrvFTFC_Config_ECC_Test ();
   v_test_value = *(uint32_t *) (DRVFTFC_PFLASH_START_ADDR); /* read PFlash, should raise an ECC IRQ for FTFC */

   /* Prepare FlexNVM ECC test configuration */
   C_PtF_DrvFTFC_Config_ECC_Test ();
   v_test_value = *(uint32_t *) (DRVFTFC_FLEXNVM_START_ADDR); /* read FlexNVM, should raise an ECC IRQ for FTFC */

   DrvFTFC_Enable_Flash_Fault_It (&v_Result);
}

void PBIT_Test_DrvADC_Registers (void)
{
   uint32_t v_Result;

   DrvADC_Check_RegConfig (&v_Result);

   if (OVSP_SW_RESULT_OK == v_Result)
   {
      V_PBIT_Test_Drivers_Result.S_DrvADC_Test = E_PBIT_Passed;
   }
   else
   {
      V_PBIT_Test_Drivers_Result.S_DrvADC_Test = E_PBIT_Failed;
   }
}

void PBIT_Test_DrvGPIO_Registers (void)
{
   uint32_t v_Result;
   uint8_t v_OVSP_Side_Id;

   DrvGPIO_Check_RegConfig (&v_Result);

   if (OVSP_SW_RESULT_OK == v_Result)
   {
      V_PBIT_Test_Drivers_Result.S_DrvGPIO_Test = E_PBIT_Passed;

      v_OVSP_Side_Id = Boot_Get_Side_Id ();

      if (BOOT_SIDE_ID_LS == v_OVSP_Side_Id)
      {
         /* CAM is a GPIO in Low Side thus considered as successful if the GPIO test is OK */
         V_PBIT_Test_Drivers_Result.S_DrvFTM_CAM_Test = E_PBIT_Passed;
      }
   }
   else
   {
      V_PBIT_Test_Drivers_Result.S_DrvGPIO_Test = E_PBIT_Failed;
   }
}

void PBIT_Test_DrvMCM_Registers (void)
{
   uint32_t v_Result;

   DrvMCM_Check_PBIT_RegConfig (&v_Result);

   if (OVSP_SW_RESULT_OK == v_Result)
   {
      V_PBIT_Test_Drivers_Result.S_DrvMCM_Test = E_PBIT_Passed;
   }
   else
   {
      V_PBIT_Test_Drivers_Result.S_DrvMCM_Test = E_PBIT_Failed;
   }
}


/* PBIT FPU Test: To test FPU interrupts
 *
 * Parameters:
 *   Inputs: None
 *   Outputs: None
 *
 *  */
void PBIT_Test_DrvMCM_FPU_RegConfig (void)
{

   uint32_t v_FPU_FIOC_Result;
   uint32_t v_FPU_FDZC_Result;
   uint32_t v_FPU_FIDC_Result;
   uint32_t v_FPU_FIXC_Result;
   uint32_t v_FPU_FOFC_Result;
   uint32_t v_FPU_FUFC_Result;
   
   V_PBIT_FPU_Generated_FIOC_Faults = DrvCPU_Generate_FPU_FIOC ();
   DrvMCM_Check_PBIT_FPU_FIOC (&v_FPU_FIOC_Result, V_PBIT_FPU_Generated_FIOC_Faults);

   DrvCPU_Generate_FPU_FDZC ();
   DrvMCM_Check_PBIT_FPU_FDZC (&v_FPU_FDZC_Result);
   
   DrvCPU_Generate_FPU_FIDC ();
   DrvMCM_Check_PBIT_FPU_FIDC (&v_FPU_FIDC_Result);
   
   DrvCPU_Generate_FPU_FIXC ();
   DrvMCM_Check_PBIT_FPU_FIXC (&v_FPU_FIXC_Result);
   
   DrvCPU_Generate_FPU_FOFC ();
   DrvMCM_Check_PBIT_FPU_FOFC (&v_FPU_FOFC_Result);

   DrvCPU_Generate_FPU_FUFC ();
   DrvMCM_Check_PBIT_FPU_FUFC (&v_FPU_FUFC_Result);

   if (OVSP_SW_RESULT_OK == v_FPU_FIOC_Result)
   {
      V_PBIT_FPU_Test_Result.S_FPU_FIOC_Test = E_PBIT_Passed;
   }
   else
   {
      V_PBIT_FPU_Test_Result.S_FPU_FIOC_Test = E_PBIT_Failed;
   }

   if (OVSP_SW_RESULT_OK == v_FPU_FDZC_Result)
   {
      V_PBIT_FPU_Test_Result.S_FPU_FDZC_Test = E_PBIT_Passed;
   }
   else
   {
      V_PBIT_FPU_Test_Result.S_FPU_FDZC_Test = E_PBIT_Failed;
   }

   if (OVSP_SW_RESULT_OK == v_FPU_FOFC_Result)
   {
      V_PBIT_FPU_Test_Result.S_FPU_FOFC_Test = E_PBIT_Passed;
   }
   else
   {
      V_PBIT_FPU_Test_Result.S_FPU_FOFC_Test = E_PBIT_Failed;
   }

   if (OVSP_SW_RESULT_OK == v_FPU_FUFC_Result)
   {
      V_PBIT_FPU_Test_Result.S_FPU_FUFC_Test = E_PBIT_Passed;
   }
   else
   {
      V_PBIT_FPU_Test_Result.S_FPU_FUFC_Test = E_PBIT_Failed;
   }

   if (OVSP_SW_RESULT_OK == v_FPU_FIDC_Result)
   {
      V_PBIT_FPU_Test_Result.S_FPU_FIDC_Test = E_PBIT_Passed;
   }
   else
   {
      V_PBIT_FPU_Test_Result.S_FPU_FIDC_Test = E_PBIT_Failed;
   }

   if (OVSP_SW_RESULT_OK == v_FPU_FIXC_Result)
   {
      V_PBIT_FPU_Test_Result.S_FPU_FIXC_Test = E_PBIT_Passed;
   }
   else
   {
      V_PBIT_FPU_Test_Result.S_FPU_FIXC_Test = E_PBIT_Failed;
   }


   DrvMCM_Inhibit_FPU_FIXC ();
}


void PBIT_Test_DrvCAN_Registers (void)
{
   uint32_t v_Result;

   DrvCAN_Check_RegConfig (&v_Result);

   if (OVSP_SW_RESULT_OK == v_Result)
   {
      V_PBIT_Test_Drivers_Result.S_DrvCAN_Test = E_PBIT_Passed;
   }
   else
   {
      V_PBIT_Test_Drivers_Result.S_DrvCAN_Test = E_PBIT_Failed;
   }
}

void PBIT_Test_DrvLPSPI_Registers (void)
{
   uint32_t v_Result;

   DrvLPSPI_Check_RegConfig (&v_Result);

   if (OVSP_SW_RESULT_OK == v_Result)
   {
      V_PBIT_Test_Drivers_Result.S_DrvLPSPI_Test = E_PBIT_Passed;
   }
   else
   {
      V_PBIT_Test_Drivers_Result.S_DrvLPSPI_Test = E_PBIT_Failed;
   }
}

void PBIT_Test_DrvFTM_Registers (void)
{
   uint32_t v_Result;

   DrvFTM_Check_Freqs_RegConfig (&v_Result);

   if (OVSP_SW_RESULT_OK == v_Result)
   {
      V_PBIT_Test_Drivers_Result.S_DrvFTM_Test = E_PBIT_Passed;
   }
   else
   {
      V_PBIT_Test_Drivers_Result.S_DrvFTM_Test = E_PBIT_Failed;
   }
}

void PBIT_Test_DrvCAM_Registers (void)
{
   uint32_t v_Result;

   DrvFTM_Check_CAM_RegConfig (&v_Result);

   if (OVSP_SW_RESULT_OK == v_Result)
   {
      V_PBIT_Test_Drivers_Result.S_DrvFTM_CAM_Test = E_PBIT_Passed;
   }
   else
   {
      V_PBIT_Test_Drivers_Result.S_DrvFTM_CAM_Test = E_PBIT_Failed;
   }
}

void PBIT_Test_DrvPAD_Registers (void)
{
   uint32_t v_Result;

   DrvPAD_check_ports (&v_Result);

   if (OVSP_SW_RESULT_OK == v_Result)
   {
      V_PBIT_Test_Drivers_Result.S_DrvPAD_Test = E_PBIT_Passed;
   }
   else
   {
      V_PBIT_Test_Drivers_Result.S_DrvPAD_Test = E_PBIT_Failed;
   }
}

void PBIT_Test_DrvPCC_Registers (void)
{
   uint32_t v_Result;

   DrvPCC_Check_RegConfig (&v_Result);

   if (OVSP_SW_RESULT_OK == v_Result)
   {
      V_PBIT_Test_Drivers_Result.S_DrvPCC_Test = E_PBIT_Passed;
   }
   else
   {
      V_PBIT_Test_Drivers_Result.S_DrvPCC_Test = E_PBIT_Failed;
   }
}

void PBIT_Test_DrvFTFC_Registers (void)
{
   uint32_t v_Result;
   
   DrvFTFC_Check_RegConfig (&v_Result);

   if (OVSP_SW_RESULT_OK == v_Result)
   {
      V_PBIT_Test_Drivers_Result.S_DrvFTFC_Test = E_PBIT_Passed;
   }
   else
   {
      V_PBIT_Test_Drivers_Result.S_DrvFTFC_Test = E_PBIT_Failed;
   }
}

void PBIT_Test_DrvLPIT_Registers (void)
{
   uint32_t v_Result;

   DrvLPIT_Check_Init_RegConfig (&v_Result);

   if (OVSP_SW_RESULT_OK == v_Result)
   {
      V_PBIT_Test_Drivers_Result.S_DrvLPIT_Test = E_PBIT_Passed;
   }
   else
   {
      V_PBIT_Test_Drivers_Result.S_DrvLPIT_Test = E_PBIT_Failed;
   }
}

void PBIT_Test_Drivers_Ressources (void)
{
   PBIT_Test_DrvMCM_Registers ();
   PBIT_Test_DrvCAN_Registers ();
   PBIT_Test_DrvLPSPI_Registers ();
   PBIT_Test_DrvFTM_Registers ();
   PBIT_Test_DrvCAM_Registers ();
   PBIT_Test_DrvPAD_Registers ();
   PBIT_Test_DrvPCC_Registers ();
   PBIT_Test_DrvGPIO_Registers ();
   PBIT_Test_DrvFTFC_Registers ();
   PBIT_Test_DrvADC_Registers ();
   PBIT_Test_DrvLPIT_Registers ();
   PBIT_Test_DrvMCM_FPU_RegConfig();
}
