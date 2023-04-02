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

 void PBIT_Test_Drivers_Ressources (void) {    PBIT_Test_DrvMCM_Registers ();    PBIT_Test_DrvCAN_Registers ();    PBIT_Test_DrvLPSPI_Registers ();    PBIT_Test_DrvFTM_Registers ();    PBIT_Test_DrvCAM_Registers ();    PBIT_Test_DrvPAD_Registers ();    PBIT_Test_DrvPCC_Registers ();    PBIT_Test_DrvGPIO_Registers ();    PBIT_Test_DrvFTFC_Registers ();    PBIT_Test_DrvADC_Registers ();    PBIT_Test_DrvLPIT_Registers ();    PBIT_Test_DrvMCM_FPU_RegConfig(); }
