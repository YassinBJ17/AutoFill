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

 void PBIT_ECC_FTFC_Generate_Double_Bit_Err (void) {    volatile uint32_t v_test_value;    uint32_t v_Result;    DrvNVIC_Initialize (DRVNVIC_BOOT_IRQ_SELECTION);    C_PtF_DrvFTFC_Config_ECC_Test ();    v_test_value = *(uint32_t *) (DRVFTFC_PFLASH_START_ADDR);     C_PtF_DrvFTFC_Config_ECC_Test ();    v_test_value = *(uint32_t *) (DRVFTFC_FLEXNVM_START_ADDR);     DrvFTFC_Enable_Flash_Fault_It (&v_Result); }
