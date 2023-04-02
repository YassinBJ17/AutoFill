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
#include "Logbook_Public.h"


/* ---------- internal define constants: ------------------------------------ */
#define PBIT_PFLASH_TEST_ID            0x00000000UL
#define PBIT_FLEXNVM_TEST_ID           0x00000001UL
#define PBIT_RAM_TEST_ID               0x00000002UL
#define PBIT_INTERN_RES_TEST_ID        0x00000003UL
#define PBIT_DSI_DSO_TEST_ID           0x00000004UL
#define PBIT_PWM_IN_OUT_TEST_ID        0x00000005UL
#define PBIT_ANALOG_IN_TEST_ID         0x00000006UL
#define PBIT_CAN_TEST_ID               0x00000007UL

#define PBIT_SIDE_ID_TEST_ID           0x00000008UL
#define PBIT_EOC_INTEG_TEST_ID         0x00000009UL
#define PBIT_OVSP_CONF_TABLE_TEST_ID   0x0000000AUL

#define PBIT_FAILURE_LOG_NUMBER        11UL


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
/* PBIT_Treatments_Synthesis : To perform the PBIT Treatments synthesis
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void PBIT_Treatments_Synthesis (void)
{
   uint32_t v_PBIT_synth[PBIT_FAILURE_LOG_NUMBER];
   uint32_t v_PBIT_accom_synth;
   uint32_t v_iter_PBIT_synth;
   TU_Logbook_Failure_Code v_Failure_Code;
   TU_Logbook_Failure_Detail v_Failure_Detail;

   for (v_iter_PBIT_synth = 0; v_iter_PBIT_synth < sizeof(v_PBIT_synth)/4; v_iter_PBIT_synth++)
   {
      v_PBIT_synth[v_iter_PBIT_synth] = 0;
   }

   v_Failure_Code.U_32BitUint = 0x00000000UL;

   /* PBIT ECC FTFC PFlash Synthesis */
   v_PBIT_synth[PBIT_PFLASH_TEST_ID] = V_PBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_PFlash;

   /* PBIT ECC FTFC NVM Synthesis */
   v_PBIT_synth[PBIT_FLEXNVM_TEST_ID] = V_PBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_NVM;

   /* PBIT RAM Test Synthesis */
   v_PBIT_synth[PBIT_RAM_TEST_ID] = V_PBIT_RAM_Test_Result | 
                                    V_PBIT_ECC_Test_Result.S_ECC_Single_Test | 
                                    V_PBIT_ECC_Test_Result.S_ECC_Mult_Test;

   /* PBIT Internal Ressources Synthesis */
   v_PBIT_synth[PBIT_INTERN_RES_TEST_ID] = V_PBIT_Test_Drivers_Result.S_DrvMCM_Test |
                                    V_PBIT_Test_Drivers_Result.S_DrvLPSPI_Test |
                                    V_PBIT_Test_Drivers_Result.S_DrvFTFC_Test |
                                    V_PBIT_Test_Drivers_Result.S_DrvPCC_Test |
                                    V_PBIT_Test_Drivers_Result.S_DrvPAD_Test |
                                    V_PBIT_Test_Drivers_Result.S_DrvLPIT_Test;

   v_PBIT_synth[PBIT_INTERN_RES_TEST_ID] |= V_PBIT_FPU_Test_Result.S_FPU_FIOC_Test | 
                                    V_PBIT_FPU_Test_Result.S_FPU_FDZC_Test | 
                                    V_PBIT_FPU_Test_Result.S_FPU_FOFC_Test | 
                                    V_PBIT_FPU_Test_Result.S_FPU_FUFC_Test | 
                                    V_PBIT_FPU_Test_Result.S_FPU_FIXC_Test | 
                                    V_PBIT_FPU_Test_Result.S_FPU_FIDC_Test ;

   /* PBIT Discrete Input/Output Synthesis */
   v_PBIT_synth[PBIT_DSI_DSO_TEST_ID] = V_PBIT_Test_Drivers_Result.S_DrvGPIO_Test;

   /* PBIT PWM Input/Output Synthesis */
   v_PBIT_synth[PBIT_PWM_IN_OUT_TEST_ID] = V_PBIT_Test_Drivers_Result.S_DrvFTM_Test | 
                                           V_PBIT_Test_Drivers_Result.S_DrvFTM_CAM_Test;
                                    

   /* PBIT Analog signals Input Synthesis */                                    
   v_PBIT_synth[PBIT_ANALOG_IN_TEST_ID] = V_PBIT_Test_Drivers_Result.S_DrvADC_Test;

   /* PBIT CAN BUS Synthesis */                                    
   v_PBIT_synth[PBIT_CAN_TEST_ID] = V_PBIT_Test_Drivers_Result.S_DrvCAN_Test;



   /* PBIT OVSP Side Identification Synthesis */                                    
   v_PBIT_synth[PBIT_SIDE_ID_TEST_ID] = V_PBIT_OVSP_Side_Id_Test_Result;

   /* PBIT OVSP EOC integrity Synthesis */                                    
   v_PBIT_synth[PBIT_EOC_INTEG_TEST_ID] = V_PBIT_OVSP_EOC_Integrity;
   
   /* PBIT OVSP Config Table integrity Synthesis */                                    
   v_PBIT_synth[PBIT_OVSP_CONF_TABLE_TEST_ID] = V_PBIT_OVSP_Cfg_Integrity;


   /* PBIT Synthesis */
   for (v_iter_PBIT_synth = 0; v_iter_PBIT_synth < sizeof(v_PBIT_synth)/4; v_iter_PBIT_synth++)
   {
      if (v_PBIT_synth[v_iter_PBIT_synth] != 0)
      {
         v_Failure_Code.U_Fields.S_FC_xBIT_Id = (uint8_t)(LOGBOOK_PBIT_FAILURE_ID);

         switch (v_iter_PBIT_synth)
         {
            case PBIT_PFLASH_TEST_ID:
            {
               v_Failure_Code.U_Fields.S_FC_PFlash_Mem = v_PBIT_synth[v_iter_PBIT_synth];
               break;
            }
            case PBIT_FLEXNVM_TEST_ID:
            {
               v_Failure_Code.U_Fields.S_FC_FlexNVM = v_PBIT_synth[v_iter_PBIT_synth];
               break;
            }

            case PBIT_RAM_TEST_ID:
            {
               v_Failure_Code.U_Fields.S_FC_RAM = v_PBIT_synth[v_iter_PBIT_synth];    
               break;
            }

            case PBIT_INTERN_RES_TEST_ID:
            {
               v_Failure_Code.U_Fields.S_FC_Micro_Int_Ressources = v_PBIT_synth[v_iter_PBIT_synth];
               break;
            }
            case PBIT_DSI_DSO_TEST_ID:
            {
               v_Failure_Code.U_Fields.S_FC_Discrete_IO = v_PBIT_synth[v_iter_PBIT_synth];
               break;
            }
            case PBIT_PWM_IN_OUT_TEST_ID:
            {
               v_Failure_Code.U_Fields.S_FC_Square_IO = v_PBIT_synth[v_iter_PBIT_synth];
               break;
            }
            case PBIT_ANALOG_IN_TEST_ID:
            {
               v_Failure_Code.U_Fields.S_FC_Analog_In = v_PBIT_synth[v_iter_PBIT_synth];
               break;
            }
            case PBIT_CAN_TEST_ID:
            {
               v_Failure_Code.U_Fields.S_FC_CAN_Bus = v_PBIT_synth[v_iter_PBIT_synth];
               break;
            }

            case PBIT_SIDE_ID_TEST_ID:
            {
               v_Failure_Code.U_Fields.S_FC_OVSP_Side_Id = v_PBIT_synth[v_iter_PBIT_synth];
               break;
            }
            case PBIT_EOC_INTEG_TEST_ID:
            {
               v_Failure_Code.U_Fields.S_FC_EOC_Integrity = v_PBIT_synth[v_iter_PBIT_synth];
               break;
            }
            case PBIT_OVSP_CONF_TABLE_TEST_ID:
            {
               v_Failure_Code.U_Fields.S_FC_Config_Integrity = v_PBIT_synth[v_iter_PBIT_synth];               
               break;
            }

            default:
               break;
         }
       
         v_PBIT_accom_synth |= v_PBIT_synth[v_iter_PBIT_synth];
      }
   }

   v_Failure_Detail.U_Fields.S_FD_PFlash_Mem = V_PBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_PFlash;;
   v_Failure_Detail.U_Fields.S_FD_FlexNVM = V_PBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_NVM;;

   v_Failure_Detail.U_Fields.S_FD_RAM_Addressability = V_PBIT_RAM_Test_Result;
   v_Failure_Detail.U_Fields.S_FD_RAM_ECC_Single_Bit = V_PBIT_ECC_Test_Result.S_ECC_Single_Test;
   v_Failure_Detail.U_Fields.S_FD_RAM_ECC_Multi_Bit = V_PBIT_ECC_Test_Result.S_ECC_Mult_Test;

   v_Failure_Detail.U_Fields.S_FD_FPU_Invalid_Operation = V_PBIT_FPU_Test_Result.S_FPU_FIOC_Test;
   v_Failure_Detail.U_Fields.S_FD_FPU_Divide_By_Zero = V_PBIT_FPU_Test_Result.S_FPU_FDZC_Test;
   v_Failure_Detail.U_Fields.S_FD_FPU_Overflow = V_PBIT_FPU_Test_Result.S_FPU_FOFC_Test;
   v_Failure_Detail.U_Fields.S_FD_FPU_Underflow = V_PBIT_FPU_Test_Result.S_FPU_FUFC_Test;
   v_Failure_Detail.U_Fields.S_FD_FPU_Inexact = V_PBIT_FPU_Test_Result.S_FPU_FIXC_Test;
   v_Failure_Detail.U_Fields.S_FD_FPU_Input_Denormal = V_PBIT_FPU_Test_Result.S_FPU_FIDC_Test;
   v_Failure_Detail.U_Fields.S_FD_MCM = V_PBIT_Test_Drivers_Result.S_DrvMCM_Test;
   v_Failure_Detail.U_Fields.S_FD_SPI = V_PBIT_Test_Drivers_Result.S_DrvLPSPI_Test;
   v_Failure_Detail.U_Fields.S_FD_Flash = V_PBIT_Test_Drivers_Result.S_DrvFTFC_Test;
   v_Failure_Detail.U_Fields.S_FD_PCC = V_PBIT_Test_Drivers_Result.S_DrvPCC_Test;
   v_Failure_Detail.U_Fields.S_FD_PAD = V_PBIT_Test_Drivers_Result.S_DrvPAD_Test;
   v_Failure_Detail.U_Fields.S_FD_LPIT = V_PBIT_Test_Drivers_Result.S_DrvLPIT_Test;

   v_Failure_Detail.U_Fields.S_FD_GPIO = V_PBIT_Test_Drivers_Result.S_DrvGPIO_Test;

   v_Failure_Detail.U_Fields.S_FD_CAM = V_PBIT_Test_Drivers_Result.S_DrvFTM_CAM_Test;
   v_Failure_Detail.U_Fields.S_FD_FTM = V_PBIT_Test_Drivers_Result.S_DrvFTM_Test;
   v_Failure_Detail.U_Fields.S_FD_Test_Speed = E_PBIT_Passed;

   v_Failure_Detail.U_Fields.S_FD_ADC = V_PBIT_Test_Drivers_Result.S_DrvADC_Test;

   v_Failure_Detail.U_Fields.S_FD_CAN_Bus = V_PBIT_Test_Drivers_Result.S_DrvCAN_Test;
   
   v_Failure_Detail.U_Fields.S_FD_OVSP_Side_Id = V_PBIT_OVSP_Side_Id_Test_Result;
   v_Failure_Detail.U_Fields.S_FD_EOC_Integrity = V_PBIT_OVSP_EOC_Integrity; 
   v_Failure_Detail.U_Fields.S_FD_Config_Integrity = V_PBIT_OVSP_Cfg_Integrity;

   if (v_PBIT_accom_synth == 0)
   {
      V_PBIT_Test_Result = E_PBIT_Passed;
   }
   else
   {
      if ((v_Failure_Detail.U_32BitUint & 0x02000000UL) != 0UL) /* OVSP_Conf_Table integrity Mask */
      {/* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
         /* Nothing to do */
      }
      else
      {
         V_PBIT_Test_Result = E_PBIT_Failed;
         Logbook_Log_New_Failure (LOGBOOK_PBIT_FAILURE_ID, v_Failure_Code.U_32BitUint, v_Failure_Detail.U_32BitUint);
      }
   }
}

/* PBIT_Treatments : To perform the PBIT Treatments
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void PBIT_Treatments (void)
{
   PBIT_Test_OVSP_Side_Id ();
   PBIT_Test_OVSP_Cfg_Integrity ();
   PBIT_Test_EOC_Integrity ();

   PBIT_ECC_Generate_Single_Mult_Tests();
   PBIT_ECC_FTFC_Generate_Double_Bit_Err();

   PBIT_Test_Drivers_Ressources ();

   PBIT_Treatments_Synthesis ();
}
