#include "DrvECC_Public.h"
#include "DrvECC_Private.h"
#include "MCP_Types.h"

 void DrvECC_ERM_Clear_Single_Err (void) {    C_DrvECC_ERM_Registers->S_CR0 = C_DrvECC_ERM_Registers->S_CR0 & DRVECC_ERM_CR0_DISABLE_S; }
