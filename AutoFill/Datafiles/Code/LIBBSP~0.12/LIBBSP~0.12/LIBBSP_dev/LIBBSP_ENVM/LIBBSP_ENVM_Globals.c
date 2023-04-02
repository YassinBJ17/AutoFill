/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
/*==== Definitions =====================================================================*/

#include "LIBBSP_ENVM_Globals.h"

const uint32_t p_ENVM_MEGA_BaseAddress =  C_LIBBSP_ENVM_MEGA_BASE + C_LIBBSP_ENVM_OFFSET_USER;
const uint32_t p_ENVM_COMP_BaseAddress =  C_LIBBSP_ENVM_COMP_BASE + C_LIBBSP_ENVM_OFFSET_USER;
const uint32_t p_SSI_COMP_BaseAddress  =  C_LIBBSP_ENVM_COMP_BASE + C_LIBBSP_ENVM_OFFSET_SSI;
const uint32_t p_LCS0_COMP_BaseAddress =  C_LIBBSP_ENVM_COMP_RAM;

uint32_t ENVM_Compagnon_Map_Size;
TS_LIBBSP_ENVM_CompagnonMap ENVM_Compagnon_Map[C_LIBBSP_ENVM_COMPAGNON_MAP_MAX];
TS_ENVM_OverrideRegister ENVM_OverrideReg;


const uint32_t C_ENVM_NVM_PIVOT = 0x40000ul;

volatile uint32_t *v_buffer;
volatile TU_LIBBSP_ENVM_RegCtrl *v_regCmd;
volatile TU_LIBBSP_ENVM_RegCtrl *v_regReqAccess;

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/*==== END =============================================================================*/
