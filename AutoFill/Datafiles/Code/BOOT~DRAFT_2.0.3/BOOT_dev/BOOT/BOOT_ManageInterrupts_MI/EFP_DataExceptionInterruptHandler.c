#include "BOOT_ManageInterrupts.h"
#include "BOOT_FailMode.h"
#include "BOOT_TCAHW_Decrementer.h"
#include "BOOT_TCAHW_FPU.h"
#include "BOOT_TCAHW_L2SRAM.h"
#include "BOOT_TCAHW_Megatice.h"
#include "BOOT_TCAHW_MMU.h"
#include "BOOT_TCAHW_SDRAM.h"
#include "LIBBSP_ECCMEM.h"
#include "LIBBSP_CCSR.h"

 void EFP_DataExceptionInterruptHandler(void) {    if(FPU_TestUnderway)    {       ExpectedEFP_DataExceptionIT_Raised = TRUE;    }    else    {       BOOT_FailMode();    } }
