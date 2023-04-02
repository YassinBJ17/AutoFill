/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_MEGSCR_H
#define LIBBSP_MEGSCR_H

#include "LIBMCP_Types.h"
#include "kcg_types.h"

/*==== Definitions =====================================================================*/
#define C_LIBBSP_MEGSCR_NB_SCRATCH 32

/*==== Types ===========================================================================*/
typedef enum {
   E_LIBBSP_MEGSCR_VALID_ADDR = 0,
   E_LIBBSP_MEGSCR_INVALID_ADDR =  1

} TE_LIBBSP_MEGSCR_AddrStatus;

//typedef enum {
//   E_LIBBSP_MEGSCR_SCRATCH_0 = 0,
//   E_LIBBSP_MEGSCR_SCRATCH_1 =  1,
//   E_LIBBSP_MEGSCR_SCRATCH_2 =  2,
//   E_LIBBSP_MEGSCR_SCRATCH_3 =  3,
//   E_LIBBSP_MEGSCR_SCRATCH_4 =  4,
//   E_LIBBSP_MEGSCR_SCRATCH_5 =  5,
//   E_LIBBSP_MEGSCR_SCRATCH_6 =  6,
//   E_LIBBSP_MEGSCR_SCRATCH_7 =  7,
//   E_LIBBSP_MEGSCR_SCRATCH_8 =  8,
//   E_LIBBSP_MEGSCR_SCRATCH_9 =  9,
//   E_LIBBSP_MEGSCR_SCRATCH_10 = 10,
//   E_LIBBSP_MEGSCR_SCRATCH_11 = 11,
//   E_LIBBSP_MEGSCR_SCRATCH_12 = 12,
//   E_LIBBSP_MEGSCR_SCRATCH_13 = 13,
//   E_LIBBSP_MEGSCR_SCRATCH_14 = 14,
//   E_LIBBSP_MEGSCR_SCRATCH_15 = 15,
//   E_LIBBSP_MEGSCR_SCRATCH_16 = 16,
//   E_LIBBSP_MEGSCR_SCRATCH_17 = 17,
//   E_LIBBSP_MEGSCR_SCRATCH_18 = 18,
//   E_LIBBSP_MEGSCR_SCRATCH_19 = 19,
//   E_LIBBSP_MEGSCR_SCRATCH_20 = 20,
//   E_LIBBSP_MEGSCR_SCRATCH_21 = 21,
//   E_LIBBSP_MEGSCR_SCRATCH_22 = 22,
//   E_LIBBSP_MEGSCR_SCRATCH_23 = 23,
//   E_LIBBSP_MEGSCR_SCRATCH_24 = 24,
//   E_LIBBSP_MEGSCR_SCRATCH_25 = 25,
//   E_LIBBSP_MEGSCR_SCRATCH_26 = 26,
//   E_LIBBSP_MEGSCR_SCRATCH_27 = 27,
//   E_LIBBSP_MEGSCR_SCRATCH_28 = 28,
//   E_LIBBSP_MEGSCR_SCRATCH_29 = 29,
//   E_LIBBSP_MEGSCR_SCRATCH_30 = 30,
//   E_LIBBSP_MEGSCR_SCRATCH_31 = 31
//
//} TE_LIBBSP_MEGSCR_Register;
// defined in kcg_types.h

/*typedef struct
{
    uint32_t* p_MEGSCR_BaseAddress;
}TS_LIBBSP_MEGSCR_BaseAddress;*/

typedef struct
{
    uint32_t REG_SCRATCH[C_LIBBSP_MEGSCR_NB_SCRATCH];
}TS_LIBBSP_MEGSCR_ScratchRegisters;

/*==== Variables========================================================================*/
//extern TS_LIBBSP_MEGSCR_BaseAddress MEGSCR_Interface;
extern volatile TS_LIBBSP_MEGSCR_ScratchRegisters * const V_MegScratchRegs;

/*==== Services ========================================================================*/

extern void LIBBSP_MEGSCR_Read(const TE_LIBBSP_MEGSCR_Register v_MEGSCR_reg, uint32_t * const v_ReadValue);
extern void LIBBSP_MEGSCR_Write(const TE_LIBBSP_MEGSCR_Register v_MEGSCR_reg, const uint32_t v_WriteValue);

/*==== END =============================================================================*/
#endif /* LIBBSP_PLDCMP_H */
