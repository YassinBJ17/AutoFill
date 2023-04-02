/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/

/*==== Definitions =====================================================================*/
#ifndef LIBBSP_MEGREG_H
#define LIBBSP_MEGREG_H

#include "LIBMCP_Types.h"

/* these constants are used in the application */
/* sw to initialize the address used by       */
/* the driver. It doesn't aim to contain      */
/* all the registers of the MEGATICE PLD     */

#define C_LIBBSP_MEGREG_MEGATICE                ((uint32_t)0xF1000000)
#define C_LIBBSP_MEGREG_GLOBAL_REGISTERS_DELTA  ((uint32_t)0x00000000)
#define C_LIBBSP_MEGREG_SCRATCH_DELTA           ((uint32_t)0x00500000)
#define C_LIBBSP_MEGREG_A429_DELTA              ((uint32_t)0x00501000)
#define C_LIBBSP_MEGREG_TIC_ACCESS_DELTA        ((uint32_t)0x00522000)
#define C_LIBBSP_MEGREG_GPIO_CTRL_DELTA         ((uint32_t)0x00524000)
#define C_LIBBSP_MEGREG_UART_DELTA              ((uint32_t)0x00527000)
#define C_LIBBSP_MEGREG_TMP_DELTA               ((uint32_t)0x0052F000)
#define C_LIBBSP_MEGREG_ENVM_DELTA              ((uint32_t)0x00400000)
#define C_LIBBSP_MEGREG_BLADES_TIC_RDY_DELTA    ((uint32_t)0x00000308)
#define C_LIBBSP_MEGREG_BLADES_RT_XYZ_RDY_DELTA ((uint32_t)0x00000288)
#define C_LIBBSP_MEGREG_BLADES_LF_XYZ_RDY_DELTA ((uint32_t)0x000002C8)
#define C_LIBBSP_MEGREG_BLADES_TIC_DELTA        ((uint32_t)0x00300000)
#define C_LIBBSP_MEGREG_BLADES_LF_DELTA         ((uint32_t)0x001C0000)
#define C_LIBBSP_MEGREG_BLADES_RT_DELTA         ((uint32_t)0x00080000)
#define C_LIBBSP_MEGREG_REGSELECT_DELTA         ((uint32_t)0x00000004)



#define C_LIBBSP_MEGREG_GLOBAL_REGISTERS        (C_LIBBSP_MEGREG_MEGATICE+C_LIBBSP_MEGREG_GLOBAL_REGISTERS_DELTA)
#define C_LIBBSP_MEGREG_SCRATCH                 (C_LIBBSP_MEGREG_MEGATICE+C_LIBBSP_MEGREG_SCRATCH_DELTA)
#define C_LIBBSP_MEGREG_A429                    (C_LIBBSP_MEGREG_MEGATICE+C_LIBBSP_MEGREG_A429_DELTA)
#define C_LIBBSP_MEGREG_TIC_ACCESS              (C_LIBBSP_MEGREG_MEGATICE+C_LIBBSP_MEGREG_TIC_ACCESS_DELTA)
#define C_LIBBSP_MEGREG_GPIO_CTRL               (C_LIBBSP_MEGREG_MEGATICE+C_LIBBSP_MEGREG_GPIO_CTRL_DELTA)
#define C_LIBBSP_MEGREG_UART                    (C_LIBBSP_MEGREG_MEGATICE+C_LIBBSP_MEGREG_UART_DELTA)
#define C_LIBBSP_MEGREG_TMP                     (C_LIBBSP_MEGREG_MEGATICE+C_LIBBSP_MEGREG_TMP_DELTA)
#define C_LIBBSP_MEGREG_ENVM                    (C_LIBBSP_MEGREG_MEGATICE+C_LIBBSP_MEGREG_ENVM_DELTA)
#define C_LIBBSP_MEGREG_BLADES_TIC              (C_LIBBSP_MEGREG_MEGATICE+C_LIBBSP_MEGREG_BLADES_TIC_DELTA)
#define C_LIBBSP_MEGREG_BLADES_LF               (C_LIBBSP_MEGREG_MEGATICE+C_LIBBSP_MEGREG_BLADES_LF_DELTA)
#define C_LIBBSP_MEGREG_BLADES_RT               (C_LIBBSP_MEGREG_MEGATICE+C_LIBBSP_MEGREG_BLADES_RT_DELTA)
#define C_LIBBSP_MEGREG_BLADES_TIC_RDY          (C_LIBBSP_MEGREG_MEGATICE+C_LIBBSP_MEGREG_BLADES_TIC_RDY_DELTA)
#define C_LIBBSP_MEGREG_BLADES_RT_XYZ_RDY       (C_LIBBSP_MEGREG_MEGATICE+C_LIBBSP_MEGREG_BLADES_RT_XYZ_RDY_DELTA)
#define C_LIBBSP_MEGREG_BLADES_LF_XYZ_RDY       (C_LIBBSP_MEGREG_MEGATICE+C_LIBBSP_MEGREG_BLADES_LF_XYZ_RDY_DELTA)
#define C_LIBBSP_MEGREG_REGSELECT               (C_LIBBSP_MEGREG_MEGATICE+C_LIBBSP_MEGREG_REGSELECT_DELTA)

/*==== Variables========================================================================*/


/*==== Services ========================================================================*/

    
/*==== END =============================================================================*/
#endif /* LIBBSP_MEGREG_H */