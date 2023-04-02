/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Test the CMPU protection
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_PBIT_public.h"
#include "BOOT_PBIT_private.h"
#include "BOOT_MEM_public.h"
#include "BOOT_RESET_public.h"
#include "BOOT_FAULT_public.h"

/* ---------- include required interface: ----------------------------------- */
/* none */

/* ---------- internal define constants: ------------------------------------ */
#define PBIT_CMPU_FLAG  ((uint32_t)0x99887766)

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- provided constants: ------------------------------------------- */

/* MAS values of the MPU entries created for PBIT */
/* 1st MPU entry: Allow all data accesses on [0x0;0x52810000] */
const ts_MPU_ENTRY c_CMPU_ENTRY0 = {0xA0000F3A, 0x00000000, 0x40003010, 0x0};
/* 2nd MPU entry :  Forbids user read access on [0x40003010; 0x40004000] */
const ts_MPU_ENTRY c_CMPU_ENTRY1 = {0xA001053A, 0x0000000, 0x40004000, 0x40003010};
/* 3rd MPU entry :  Allow all data accesses on [0x40004000; 0xFFFFFFFF] */
const ts_MPU_ENTRY c_CMPU_ENTRY2 = {0xA0020F3A, 0x00000000, 0xFFFFFFFF, 0x40004000};
/* 4th MPU entry: Allow all INST accesses on  [0x0;0xFFFFFFFF] */
const ts_MPU_ENTRY c_CMPU_ENTRY3 = {0xA1030F3A, 0x00000000, 0xFFFFFFFF, 0x0};



volatile const uint32_t c_ILLEGAL_USER_RD_AREA = 0x40003030;

/* ---------- provided data: ------------------------------------------------ */
volatile uint32_t * V_UserDataLoad_addr;
uint32_t   V_UserDataLoad_res;
uint32_t  V_BOOT_PBIT_INTC;

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- external data: ------------------------------------------------ */


/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ.MY_REQID-LLR_0xx */
void BOOT_PBIT_CMPU ( uint32_t const p_numcore )
{
   /* Initialization of data */
   V_BOOT_PBIT_INTC = PBIT_CMPU_FLAG;

   /* Deactivate SMPU */
   BOOT_MEM_SMPU_DISABLE();

   /* Configure MMU : 2 MPU entry, one for Data, one for instruction */
   BOOT_MEM_MPU_WRITE_ENTRY(c_CMPU_ENTRY0.s_mas0, c_CMPU_ENTRY0.s_mas1, c_CMPU_ENTRY0.s_mas2, c_CMPU_ENTRY0.s_mas3);
   BOOT_MEM_MPU_WRITE_ENTRY(c_CMPU_ENTRY1.s_mas0, c_CMPU_ENTRY1.s_mas1, c_CMPU_ENTRY1.s_mas2, c_CMPU_ENTRY1.s_mas3);
   BOOT_MEM_MPU_WRITE_ENTRY(c_CMPU_ENTRY2.s_mas0, c_CMPU_ENTRY2.s_mas1, c_CMPU_ENTRY2.s_mas2, c_CMPU_ENTRY2.s_mas3);
   BOOT_MEM_MPU_WRITE_ENTRY(c_CMPU_ENTRY3.s_mas0, c_CMPU_ENTRY3.s_mas1, c_CMPU_ENTRY3.s_mas2, c_CMPU_ENTRY3.s_mas3);


   /* Activate CMPU */
   BOOT_MEM_CMPU_CONFIG(e_MPU_EN_VAL);

   /* Set the user mode */
   BOOT_RESET_SET_USER_MODE();

   /* Perform an illegal data read access in user mode (DSI) */
   V_UserDataLoad_addr = (uint32_t * ) c_ILLEGAL_USER_RD_AREA;
	V_UserDataLoad_res = * V_UserDataLoad_addr;


   /* Invalidate the CMPU */
   BOOT_MEM_CMPU_CONFIG(e_MPU_INV_VAL);

   /* Check the result */
   if(V_BOOT_PBIT_INTC != BOOT_FAULT_DATA_ACCESS_IT)
   {
      BOOT_FAULT_LOG(BOOT_FAULT_PBIT_CMPU, PBIT_ORIGIN, p_numcore, LGBK_FIELD_DEFAULT_VALUE, LGBK_FIELD_DEFAULT_VALUE, LGBK_FIELD_DEFAULT_VALUE);
      BOOT_FAULT_INFINITELOOP();
   }

   V_BOOT_PBIT_INTC = 0;
}
