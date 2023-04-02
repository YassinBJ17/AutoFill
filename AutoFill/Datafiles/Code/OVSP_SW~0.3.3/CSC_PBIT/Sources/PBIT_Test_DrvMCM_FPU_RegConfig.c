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

 void PBIT_Test_DrvMCM_FPU_RegConfig (void) {    uint32_t v_FPU_FIOC_Result;    uint32_t v_FPU_FDZC_Result;    uint32_t v_FPU_FIDC_Result;    uint32_t v_FPU_FIXC_Result;    uint32_t v_FPU_FOFC_Result;    uint32_t v_FPU_FUFC_Result;    V_PBIT_FPU_Generated_FIOC_Faults = DrvCPU_Generate_FPU_FIOC ();    DrvMCM_Check_PBIT_FPU_FIOC (&v_FPU_FIOC_Result, V_PBIT_FPU_Generated_FIOC_Faults);    DrvCPU_Generate_FPU_FDZC ();    DrvMCM_Check_PBIT_FPU_FDZC (&v_FPU_FDZC_Result);    DrvCPU_Generate_FPU_FIDC ();    DrvMCM_Check_PBIT_FPU_FIDC (&v_FPU_FIDC_Result);    DrvCPU_Generate_FPU_FIXC ();    DrvMCM_Check_PBIT_FPU_FIXC (&v_FPU_FIXC_Result);    DrvCPU_Generate_FPU_FOFC ();    DrvMCM_Check_PBIT_FPU_FOFC (&v_FPU_FOFC_Result);    DrvCPU_Generate_FPU_FUFC ();    DrvMCM_Check_PBIT_FPU_FUFC (&v_FPU_FUFC_Result);    if (OVSP_SW_RESULT_OK == v_FPU_FIOC_Result)    {       V_PBIT_FPU_Test_Result.S_FPU_FIOC_Test = E_PBIT_Passed;    }    else    {       V_PBIT_FPU_Test_Result.S_FPU_FIOC_Test = E_PBIT_Failed;    }    if (OVSP_SW_RESULT_OK == v_FPU_FDZC_Result)    {       V_PBIT_FPU_Test_Result.S_FPU_FDZC_Test = E_PBIT_Passed;    }    else    {       V_PBIT_FPU_Test_Result.S_FPU_FDZC_Test = E_PBIT_Failed;    }    if (OVSP_SW_RESULT_OK == v_FPU_FOFC_Result)    {       V_PBIT_FPU_Test_Result.S_FPU_FOFC_Test = E_PBIT_Passed;    }    else    {       V_PBIT_FPU_Test_Result.S_FPU_FOFC_Test = E_PBIT_Failed;    }    if (OVSP_SW_RESULT_OK == v_FPU_FUFC_Result)    {       V_PBIT_FPU_Test_Result.S_FPU_FUFC_Test = E_PBIT_Passed;    }    else    {       V_PBIT_FPU_Test_Result.S_FPU_FUFC_Test = E_PBIT_Failed;    }    if (OVSP_SW_RESULT_OK == v_FPU_FIDC_Result)    {       V_PBIT_FPU_Test_Result.S_FPU_FIDC_Test = E_PBIT_Passed;    }    else    {       V_PBIT_FPU_Test_Result.S_FPU_FIDC_Test = E_PBIT_Failed;    }    if (OVSP_SW_RESULT_OK == v_FPU_FIXC_Result)    {       V_PBIT_FPU_Test_Result.S_FPU_FIXC_Test = E_PBIT_Passed;    }    else    {       V_PBIT_FPU_Test_Result.S_FPU_FIXC_Test = E_PBIT_Failed;    }    DrvMCM_Inhibit_FPU_FIXC (); }
