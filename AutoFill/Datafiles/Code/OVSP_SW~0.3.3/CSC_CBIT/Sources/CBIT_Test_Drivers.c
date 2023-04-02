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

 void CBIT_Test_Drivers (void) {    TE_Modes_SW_Mode v_SW_Mode;    v_SW_Mode = Modes_Get_SW_Mode ();    CBIT_Test_DrvADC_RegConfig ();    CBIT_Test_DrvFTM_CAM_RegConfig ();    CBIT_Test_DrvCAN_RegConfig ();    CBIT_Test_DrvFTFC_RegConfig ();    CBIT_Test_DrvGPIO_RegConfig ();    CBIT_Test_DrvLPIT_RegConfig ();    CBIT_Test_DrvMCM_RegConfig ();    CBIT_Test_DrvMCM_FPU_RegConfig ();    CBIT_Test_DrvPAD_RegConfig ();    CBIT_Test_DrvPCC_RegConfig ();    CBIT_Test_DrvLPSPI_RegConfig ();    if (E_Modes_TriggeredTest == v_SW_Mode)    {       CBIT_Test_DrvFTM_TSpeed_RegConfig ();    }    else    {       CBIT_Test_DrvFTM_RegConfig ();    } }
