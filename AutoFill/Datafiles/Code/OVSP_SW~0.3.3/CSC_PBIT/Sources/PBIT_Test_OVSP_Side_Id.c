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

 void PBIT_Test_OVSP_Side_Id (void) {    uint8_t v_OVSP_Side_Id;    v_OVSP_Side_Id = Boot_Get_Side_Id ();    switch (v_OVSP_Side_Id)    {       case BOOT_SIDE_ID_HS:       case BOOT_SIDE_ID_LS:       {          V_PBIT_OVSP_Side_Id_Test_Result = E_PBIT_Passed;       }       break;       default:       {          V_PBIT_OVSP_Side_Id_Test_Result = E_PBIT_Failed;       }       break;    }    }
