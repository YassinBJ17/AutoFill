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

 void CBIT_ECC_FTFC_Int_Double_Bit_Err (void) {    uint32_t v_Status;    asm("movw  r1,%lo(V_CBIT_ECC_Test_faulty_addr)");    asm("movt  r1,%hi(V_CBIT_ECC_Test_faulty_addr)");    asm("movs  r0,r14");    asm("str   r0,[r1]");    if (DRVFTFC_PFLASH_END_ADDR >= V_CBIT_ECC_Test_faulty_addr)    {       V_CBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_PFlash = E_CBIT_Failed;    }    else    {       if ((DRVFTFC_FLEXNVM_START_ADDR <= V_CBIT_ECC_Test_faulty_addr) &&           (DRVFTFC_FLEXNVM_END_ADDR >= V_CBIT_ECC_Test_faulty_addr))       {          V_CBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_NVM = E_CBIT_Failed;       }       else       {          V_CBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_PFlash = E_CBIT_Failed;          V_CBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_NVM = E_CBIT_Failed;       }    }    DrvFTFC_Clear_Flash_Fault (&v_Status);    if (OVSP_SW_RESULT_OK == v_Status)    {     }    else    {       V_CBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_PFlash = E_CBIT_Failed;       V_CBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_NVM = E_CBIT_Failed;    } }
