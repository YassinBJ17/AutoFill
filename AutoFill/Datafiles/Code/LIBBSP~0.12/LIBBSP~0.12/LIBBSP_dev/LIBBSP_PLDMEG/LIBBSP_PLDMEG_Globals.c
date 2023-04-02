/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_PLDMEG_Globals.h"

/*==== Definitions =====================================================================*/

/*#define C_PLDMEG_GLOBAL_STATUS 0x10*/
/*#define C_PLDMEG_SEU_MONITORING_1 0x14*/
/*#define C_PLDMEG_SEU_MONITORING_2 0x18*/
/*#define C_PLDMEG_SEU_MONITORING_3 0x1C*/
/*#define C_PLDMEG_IF_CPU_STATUS 0x20*/
/*#define C_PLDMEG_ENVM_STATUS 0x24*/

/*==== Variables =======================================================================*/

//TS_LIBBSP_PLDMEG_BaseAddress PLDMEG_Interface;
volatile TS_LIBBSP_PLDMEG_GlobalRegisters * const V_PldMegRegs = (volatile TS_LIBBSP_PLDMEG_GlobalRegisters * const) C_LIBBSP_MEGREG_GLOBAL_REGISTERS; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: adress */

/*==== Services ========================================================================*/

/*==== END =============================================================================*/
