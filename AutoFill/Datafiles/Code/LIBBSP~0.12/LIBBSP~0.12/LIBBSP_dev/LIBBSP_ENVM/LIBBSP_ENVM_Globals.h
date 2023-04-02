/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_ENVM_GLOBALS_H
#define LIBBSP_ENVM_GLOBALS_H

#include "LIBBSP_ENVM.h"
#include "LIBBSP_SHM.h"
#include "LIBBSP_PLDCMP.h"
#include "LIBBSP_PLDMEG.h"
#include "LIBBSP_CMN.h"

#define C_LIBBSP_ENVM_COMPAGNON_MAP_MAX 10ul
#define C_LIBBSP_ENVM_ACCELERATOR_FIFO_ADDR 0x7FFFCul
#define C_LIBBSP_ENVM_SSI_MODEREAD 0x04ul
#define C_LIBBSP_ENVM_SSI_MODEERASE 0x0Cul
#define C_LIBBSP_ENVM_FIFO_MAX_SIZE 362ul
#define C_LIBBSP_ENVM_MEGATICE_MAX_SIZE 0x7D000ul
#define C_LIBBSP_ENVM_SSI_MODE_RESET 0xFFul
#define C_LIBBSP_ENVM_SSI_MODEWRITE 0x08ul
#define C_ENVM_NB_READ_MAX 16ul
#define C_ENVM_END_ADDR 0xFFFFCul
#define C_LIBBSP_ENVM_MEGA_BASE 0xF1000000ul
#define C_LIBBSP_ENVM_COMP_BASE 0xF2000000ul
#define C_LIBBSP_ENVM_COMP_RAM  0xFFFF8000ul
#define C_LIBBSP_ENVM_OFFSET_USER 0x400000ul
#define C_LIBBSP_ENVM_OFFSET_SSI 0x5000ul
#define C_LIBBSP_ENVM_NVM0_BASE 0x80000ul
#define C_LIBBSP_ENVM_NVM1_BASE 0xC0000ul

#define C_ENVM_NVM0_SIZE  0x40000ul
#define C_ENVM_NVM1_SIZE  0x3D000ul

#define C_LIBBSP_ENVM_CTRL_WDBUFF 0x80ul
#define C_LIBBSP_ENVM_CTRL_STATUS 0x120ul
#define C_LIBBSP_ENVM_CTRL_CMD 0x148ul
#define C_LIBBSP_ENVM_CTRL_REQACCESS 0x1FCul

#define C_LIBBSP_ENVM_PAGESIZE (32ul * sizeof(uint32_t))

typedef union
{
	uint32_t v_reg;

	struct
	{
		uint32_t reserved : 31;
		uint32_t busy : 1;
	} Status;

	struct
	{
		uint32_t cmd : 8;
		uint32_t addr : 24;
	} Cmd;

	struct
	{
		uint32_t reserved : 29;
		uint32_t reqaccess : 3;
	} ReqAccess;

} TU_LIBBSP_ENVM_RegCtrl;



typedef struct
{
	uint32_t : 24;
	uint32_t request : 8;
} TS_LIBBSP_ENVM_SSI_Mode;

typedef struct
{
    TS_LIBBSP_ENVM_SSI_Mode* p_SSI_COMP_ReqAddress;
    uint32_t  v_SSI_COMP_ReqValue;
} TS_ENVM_OverrideRegister;

extern const uint32_t p_ENVM_MEGA_BaseAddress;
extern const uint32_t p_ENVM_COMP_BaseAddress;
extern const uint32_t p_SSI_COMP_BaseAddress; 
extern const uint32_t p_LCS0_COMP_BaseAddress;

extern uint32_t ENVM_Compagnon_Map_Size;
extern TS_LIBBSP_ENVM_CompagnonMap ENVM_Compagnon_Map[C_LIBBSP_ENVM_COMPAGNON_MAP_MAX];
extern TS_ENVM_OverrideRegister ENVM_OverrideReg;

extern volatile uint32_t *v_buffer;
extern volatile TU_LIBBSP_ENVM_RegCtrl *v_regCmd;
extern volatile TU_LIBBSP_ENVM_RegCtrl *v_regReqAccess;

extern const uint32_t C_ENVM_NVM_PIVOT;

#endif

/*==== Definitions =====================================================================*/

/*==== Services ========================================================================*/
