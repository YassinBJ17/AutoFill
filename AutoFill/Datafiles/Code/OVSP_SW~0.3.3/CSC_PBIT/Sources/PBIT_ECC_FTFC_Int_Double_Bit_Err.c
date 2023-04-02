#include "PBIT_Public.h"
#include "PBIT_Private.h"
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

 void PBIT_ECC_FTFC_Int_Double_Bit_Err (void) {    uint32_t v_Result;    DrvFTFC_Clear_Flash_Fault (&v_Result);    switch (V_PBIT_ECC_Cpt_FTFC)    {       case 0UL:       {          if (OVSP_SW_RESULT_OK == v_Result)          {             V_PBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_PFlash = E_PBIT_Passed;          }          else          {             V_PBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_PFlash = E_PBIT_Failed;          }       }       break;       case 1UL:       {          if (OVSP_SW_RESULT_OK == v_Result)          {             V_PBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_NVM = E_PBIT_Passed;          }          else          {             V_PBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_NVM = E_PBIT_Failed;          }       }       break;       default:       {        }       break;    }    V_PBIT_ECC_Cpt_FTFC++; }
