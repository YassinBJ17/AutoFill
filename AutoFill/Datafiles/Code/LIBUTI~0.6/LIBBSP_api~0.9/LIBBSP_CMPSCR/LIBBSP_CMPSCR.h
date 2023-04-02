/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_CMPSCR_H
#define LIBBSP_CMPSCR_H

#include "LIBMCP_Types.h"
#include "kcg_types.h"

/*==== Definitions =====================================================================*/
#define C_LIBBSP_CMPSCR_NB_SCRATCH 32

/*==== Types ===========================================================================*/
typedef enum {
   E_LIBBSP_CMPSCR_VALID_ADDR = 0,
   E_LIBBSP_CMPSCR_INVALID_ADDR =  1

} TE_LIBBSP_CMPSCR_AddrStatus;

/*typedef enum {
   E_LIBBSP_CMPSCR_SCRATCH_0 = 0,
   E_LIBBSP_CMPSCR_SCRATCH_1 =  1,
   E_LIBBSP_CMPSCR_SCRATCH_2 =  2,
   E_LIBBSP_CMPSCR_SCRATCH_3 =  3,
   E_LIBBSP_CMPSCR_SCRATCH_4 =  4,
   E_LIBBSP_CMPSCR_SCRATCH_5 =  5,
   E_LIBBSP_CMPSCR_SCRATCH_6 =  6,
   E_LIBBSP_CMPSCR_SCRATCH_7 =  7,
   E_LIBBSP_CMPSCR_SCRATCH_8 =  8,
   E_LIBBSP_CMPSCR_SCRATCH_9 =  9,
   E_LIBBSP_CMPSCR_SCRATCH_10 = 10,
   E_LIBBSP_CMPSCR_SCRATCH_11 = 11,
   E_LIBBSP_CMPSCR_SCRATCH_12 = 12,
   E_LIBBSP_CMPSCR_SCRATCH_13 = 13,
   E_LIBBSP_CMPSCR_SCRATCH_14 = 14,
   E_LIBBSP_CMPSCR_SCRATCH_15 = 15,
   E_LIBBSP_CMPSCR_SCRATCH_16 = 16,
   E_LIBBSP_CMPSCR_SCRATCH_17 = 17,
   E_LIBBSP_CMPSCR_SCRATCH_18 = 18,
   E_LIBBSP_CMPSCR_SCRATCH_19 = 19,
   E_LIBBSP_CMPSCR_SCRATCH_20 = 20,
   E_LIBBSP_CMPSCR_SCRATCH_21 = 21,
   E_LIBBSP_CMPSCR_SCRATCH_22 = 22,
   E_LIBBSP_CMPSCR_SCRATCH_23 = 23,
   E_LIBBSP_CMPSCR_SCRATCH_24 = 24,
   E_LIBBSP_CMPSCR_SCRATCH_25 = 25,
   E_LIBBSP_CMPSCR_SCRATCH_26 = 26,
   E_LIBBSP_CMPSCR_SCRATCH_27 = 27,
   E_LIBBSP_CMPSCR_SCRATCH_28 = 28,
   E_LIBBSP_CMPSCR_SCRATCH_29 = 29,
   E_LIBBSP_CMPSCR_SCRATCH_30 = 30,
   E_LIBBSP_CMPSCR_SCRATCH_31 = 31

} TE_LIBBSP_CMPSCR_Register;*/
/* defined in kcg_types */

typedef struct
{
    uint32_t REG_SCRATCH[C_LIBBSP_CMPSCR_NB_SCRATCH];
}TS_LIBBSP_CMPSCR_ScratchRegisters;


/*typedef struct
{
    uint32_t* p_CMPSCR_BaseAddress;
}TS_LIBBSP_CMPSCR_BaseAddress;*/

/*==== Variables========================================================================*/
//extern TS_LIBBSP_CMPSCR_BaseAddress CMPSCR_Interface;
extern volatile TS_LIBBSP_CMPSCR_ScratchRegisters * const V_CmpScratchRegs;
/*==== Services ========================================================================*/

extern void LIBBSP_CMPSCR_Read(const TE_LIBBSP_CMPSCR_Register v_CMPSCR_reg, uint32_t * const v_ReadValue);
extern void LIBBSP_CMPSCR_Write(const TE_LIBBSP_CMPSCR_Register v_CMPSCR_reg, const uint32_t v_WriteValue);

/*==== END =============================================================================*/
#endif /* LIBBSP_PLDCMP_H */
