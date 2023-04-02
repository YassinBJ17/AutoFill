#include "CBIT_Public.h"
#include "CBIT_Private.h"
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

 void CBIT_Test_DrvPAD_RegConfig (void) {    uint32_t v_Result;    DrvPAD_check_ports (&v_Result);    if (OVSP_SW_RESULT_OK == v_Result)    {       V_CBIT_Test_Drivers_Result.S_DrvPAD_Test = E_CBIT_Passed;    }    else    {       V_CBIT_Test_Drivers_Result.S_DrvPAD_Test = E_CBIT_Failed;    } }
