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

 void PBIT_Test_OVSP_Cfg_Integrity (void) {    TE_Config_Integrity_Status v_Cfg_Integrity;    v_Cfg_Integrity = Config_Get_Integrity_Status ();    if (E_Config_Integrity_OK == v_Cfg_Integrity)    {       V_PBIT_OVSP_Cfg_Integrity = E_PBIT_Passed;    }    else    {       V_PBIT_OVSP_Cfg_Integrity = E_PBIT_Failed;    } }
