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
#include "Logbook_Public.h"


/* ---------- internal define constants: ------------------------------------ */
#define CBIT_PFLASH_TEST_ID            0x00000000UL
#define CBIT_FLEXNVM_TEST_ID           0x00000001UL
#define CBIT_RAM_TEST_ID               0x00000002UL
#define CBIT_INTERN_RES_TEST_ID        0x00000003UL
#define CBIT_DSI_DSO_TEST_ID           0x00000004UL
#define CBIT_PWM_IN_OUT_TEST_ID        0x00000005UL
#define CBIT_ANALOG_IN_TEST_ID         0x00000006UL
#define CBIT_CAN_TEST_ID               0x00000007UL

#define CBIT_SIDE_ID_TEST_ID           0x00000008UL
#define CBIT_EOC_INTEG_TEST_ID         0x00000009UL
#define CBIT_OVSP_CONF_TABLE_TEST_ID   0x0000000AUL

#define CBIT_FAILURE_LOG_NUMBER        11UL


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
/* CBIT_Treatments_Synthesis : To perform the CBIT Treatments synthesis
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void CBIT_Treatments_Synthesis (void)
{
   uint32_t v_CBIT_synth [CBIT_FAILURE_LOG_NUMBER];

   uint32_t v_CBIT_accom_synth;
   uint32_t v_iter_CBIT_synth;
   TU_Logbook_Failure_Code v_Failure_Code;
   TU_Logbook_Failure_Detail v_Failure_Detail;

   for (v_iter_CBIT_synth = 0UL; v_iter_CBIT_synth < CBIT_FAILURE_LOG_NUMBER ; v_iter_CBIT_synth++)
   {
      v_CBIT_synth [v_iter_CBIT_synth] = 0UL;
   }

   v_Failure_Code.U_32BitUint = 0x00000000UL;

   /* CBIT ECC FTFC PFlash Synthesis */
   v_CBIT_synth [CBIT_PFLASH_TEST_ID] = V_CBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_PFlash;

   /* CBIT ECC FTFC NVM Synthesis */
   v_CBIT_synth [CBIT_FLEXNVM_TEST_ID] = V_CBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_NVM;

   /* CBIT RAM Test Synthesis */
   v_CBIT_synth [CBIT_RAM_TEST_ID] = V_CBIT_ECC_Test_Result.S_ECC_Single_Test | V_CBIT_ECC_Test_Result.S_ECC_Mult_Test;

   /* CBIT Internal Ressources Synthesis */
   v_CBIT_synth [CBIT_INTERN_RES_TEST_ID] = V_CBIT_Test_Drivers_Result.S_DrvMCM_Test |
                                            V_CBIT_Test_Drivers_Result.S_DrvLPSPI_Test |
                                            V_CBIT_Test_Drivers_Result.S_DrvFTFC_Test |
                                            V_CBIT_Test_Drivers_Result.S_DrvPCC_Test |
                                            V_CBIT_Test_Drivers_Result.S_DrvPAD_Test |
                                            V_CBIT_Test_Drivers_Result.S_DrvLPIT_Test |
                                            V_CBIT_FPU_Test_Result.S_FPU_FIOC_Test |
                                            V_CBIT_FPU_Test_Result.S_FPU_FDZC_Test |
                                            V_CBIT_FPU_Test_Result.S_FPU_FOFC_Test |
                                            V_CBIT_FPU_Test_Result.S_FPU_FUFC_Test |
                                            V_CBIT_FPU_Test_Result.S_FPU_FIXC_Test |
                                            V_CBIT_FPU_Test_Result.S_FPU_FIDC_Test;

   /* CBIT Discrete Input/Output Synthesis */
   v_CBIT_synth [CBIT_DSI_DSO_TEST_ID] = V_CBIT_Test_Drivers_Result.S_DrvGPIO_Test;

   /* CBIT PWM Input/Output Synthesis */
   v_CBIT_synth [CBIT_PWM_IN_OUT_TEST_ID] = V_CBIT_Test_Drivers_Result.S_DrvFTM_Test |
                                            V_CBIT_Test_Drivers_Result.S_DrvFTM_CAM_Test | 
                                            V_CBIT_Test_Drivers_Result.S_DrvFTM_TSpeed_Test;

   /* CBIT Analog signals Input Synthesis */
   v_CBIT_synth [CBIT_ANALOG_IN_TEST_ID] = V_CBIT_Test_Drivers_Result.S_DrvADC_Test;

   /* CBIT CAN BUS Synthesis */
   v_CBIT_synth [CBIT_CAN_TEST_ID] = V_CBIT_Test_Drivers_Result.S_DrvCAN_Test;

   /* CBIT OVSP Side Identification Synthesis */
   v_CBIT_synth [CBIT_SIDE_ID_TEST_ID] = V_CBIT_OVSP_Side_Id_Test_Result;

   /* CBIT OVSP EOC integrity Synthesis */
   v_CBIT_synth [CBIT_EOC_INTEG_TEST_ID] = V_CBIT_OVSP_EOC_Integrity;

   /* CBIT OVSP Config Table integrity Synthesis */
   v_CBIT_synth [CBIT_OVSP_CONF_TABLE_TEST_ID] = V_CBIT_OVSP_Cfg_Integrity;

   /* CBIT Synthesis */
   for (v_iter_CBIT_synth = 0; v_iter_CBIT_synth < sizeof(v_CBIT_synth) / 4 ; v_iter_CBIT_synth++)
   {
      if (v_CBIT_synth [v_iter_CBIT_synth] != 0)
      {
         v_Failure_Code.U_Fields.S_FC_xBIT_Id = (uint8_t) (LOGBOOK_CBIT_FAILURE_ID);

         switch (v_iter_CBIT_synth)
         {
            case CBIT_PFLASH_TEST_ID:
            {
               v_Failure_Code.U_Fields.S_FC_PFlash_Mem = v_CBIT_synth [v_iter_CBIT_synth];
            }
            break;

            case CBIT_FLEXNVM_TEST_ID:
            {
               v_Failure_Code.U_Fields.S_FC_FlexNVM = v_CBIT_synth [v_iter_CBIT_synth];
            }
            break;

            case CBIT_RAM_TEST_ID:
            {
               v_Failure_Code.U_Fields.S_FC_RAM = v_CBIT_synth [v_iter_CBIT_synth];
            }
            break;

            case CBIT_INTERN_RES_TEST_ID:
            {
               v_Failure_Code.U_Fields.S_FC_Micro_Int_Ressources = v_CBIT_synth [v_iter_CBIT_synth];
            }
            break;

            case CBIT_DSI_DSO_TEST_ID:
            {
               v_Failure_Code.U_Fields.S_FC_Discrete_IO = v_CBIT_synth [v_iter_CBIT_synth];
            }
            break;

            case CBIT_PWM_IN_OUT_TEST_ID:
            {
               v_Failure_Code.U_Fields.S_FC_Square_IO = v_CBIT_synth [v_iter_CBIT_synth];
            }
            break;

            case CBIT_ANALOG_IN_TEST_ID:
            {
               v_Failure_Code.U_Fields.S_FC_Analog_In = v_CBIT_synth [v_iter_CBIT_synth];
            }
            break;

            case CBIT_CAN_TEST_ID:
            {
               v_Failure_Code.U_Fields.S_FC_CAN_Bus = v_CBIT_synth [v_iter_CBIT_synth];
            }
            break;

            case CBIT_SIDE_ID_TEST_ID:
            {
               v_Failure_Code.U_Fields.S_FC_OVSP_Side_Id = v_CBIT_synth [v_iter_CBIT_synth];
            }
            break;

            case CBIT_EOC_INTEG_TEST_ID:
            {
               v_Failure_Code.U_Fields.S_FC_EOC_Integrity = v_CBIT_synth [v_iter_CBIT_synth];
            }
            break;

            case CBIT_OVSP_CONF_TABLE_TEST_ID:
            {
               v_Failure_Code.U_Fields.S_FC_Config_Integrity = v_CBIT_synth [v_iter_CBIT_synth];
            }
            break;

            default:
            { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
               /* Nothing to do */
            }
            break;

         }

         v_CBIT_accom_synth |= v_CBIT_synth [v_iter_CBIT_synth];
      }
   }

   v_Failure_Detail.U_Fields.S_FD_PFlash_Mem = V_CBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_PFlash;

   v_Failure_Detail.U_Fields.S_FD_FlexNVM = V_CBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_NVM;

   v_Failure_Detail.U_Fields.S_FD_RAM_Addressability = E_CBIT_Passed;
   v_Failure_Detail.U_Fields.S_FD_RAM_ECC_Single_Bit = V_CBIT_ECC_Test_Result.S_ECC_Single_Test;
   v_Failure_Detail.U_Fields.S_FD_RAM_ECC_Multi_Bit = V_CBIT_ECC_Test_Result.S_ECC_Mult_Test;

   v_Failure_Detail.U_Fields.S_FD_FPU_Invalid_Operation = V_CBIT_FPU_Test_Result.S_FPU_FIOC_Test;
   v_Failure_Detail.U_Fields.S_FD_FPU_Divide_By_Zero = V_CBIT_FPU_Test_Result.S_FPU_FDZC_Test;
   v_Failure_Detail.U_Fields.S_FD_FPU_Overflow = V_CBIT_FPU_Test_Result.S_FPU_FOFC_Test;
   v_Failure_Detail.U_Fields.S_FD_FPU_Underflow = V_CBIT_FPU_Test_Result.S_FPU_FUFC_Test;
   v_Failure_Detail.U_Fields.S_FD_FPU_Inexact = V_CBIT_FPU_Test_Result.S_FPU_FIXC_Test;
   v_Failure_Detail.U_Fields.S_FD_FPU_Input_Denormal = V_CBIT_FPU_Test_Result.S_FPU_FIDC_Test;
   v_Failure_Detail.U_Fields.S_FD_MCM = V_CBIT_Test_Drivers_Result.S_DrvMCM_Test;
   v_Failure_Detail.U_Fields.S_FD_SPI = V_CBIT_Test_Drivers_Result.S_DrvLPSPI_Test;
   v_Failure_Detail.U_Fields.S_FD_Flash = V_CBIT_Test_Drivers_Result.S_DrvFTFC_Test;
   v_Failure_Detail.U_Fields.S_FD_PCC = V_CBIT_Test_Drivers_Result.S_DrvPCC_Test;
   v_Failure_Detail.U_Fields.S_FD_PAD = V_CBIT_Test_Drivers_Result.S_DrvPAD_Test;
   v_Failure_Detail.U_Fields.S_FD_LPIT = V_CBIT_Test_Drivers_Result.S_DrvLPIT_Test;

   v_Failure_Detail.U_Fields.S_FD_GPIO = V_CBIT_Test_Drivers_Result.S_DrvGPIO_Test;

   v_Failure_Detail.U_Fields.S_FD_CAM = V_CBIT_Test_Drivers_Result.S_DrvFTM_CAM_Test;
   v_Failure_Detail.U_Fields.S_FD_FTM = V_CBIT_Test_Drivers_Result.S_DrvFTM_Test;
   v_Failure_Detail.U_Fields.S_FD_Test_Speed = V_CBIT_Test_Drivers_Result.S_DrvFTM_TSpeed_Test;

   v_Failure_Detail.U_Fields.S_FD_ADC = V_CBIT_Test_Drivers_Result.S_DrvADC_Test;

   v_Failure_Detail.U_Fields.S_FD_CAN_Bus = V_CBIT_Test_Drivers_Result.S_DrvCAN_Test;

   v_Failure_Detail.U_Fields.S_FD_OVSP_Side_Id = V_CBIT_OVSP_Side_Id_Test_Result;
   v_Failure_Detail.U_Fields.S_FD_EOC_Integrity = V_CBIT_OVSP_EOC_Integrity;
   v_Failure_Detail.U_Fields.S_FD_Config_Integrity = V_CBIT_OVSP_Cfg_Integrity;

   if (v_CBIT_accom_synth == 0)
   {
      V_CBIT_Test_Result = E_CBIT_Passed;
   }
   else
   {
      if (((v_Failure_Detail.U_32BitUint & 0x000007E0UL) != 0UL) || /* FPU Mask*/
          ((v_Failure_Detail.U_32BitUint & 0x0000001CUL) != 0UL) || /* RAM ECC Mask*/
          ((v_Failure_Detail.U_32BitUint & 0x00000003UL) != 0UL) || /* FlexNVM, PFlash ECC Mask*/
          ((v_Failure_Detail.U_32BitUint & 0x01800000UL) != 0UL))   /* OS_Side_ID, EOC_Integrity Mask */
      {
         V_CBIT_Test_Result = E_CBIT_Fatal_Error;
      }
      else
      {
         V_CBIT_Test_Result = E_CBIT_Failed;
      }

      Logbook_Log_New_Failure (LOGBOOK_CBIT_FAILURE_ID, v_Failure_Code.U_32BitUint, v_Failure_Detail.U_32BitUint);
   }
}
