#ifndef LIB_CHKSUM_CRC_INTERNAL_H
#define LIB_CHKSUM_CRC_INTERNAL_H

/* ----------------------------------------------------------------------------------------------------- */
/*                           (c) Copyright Safran Electronics & Defense                                  */
/*                                                                                                       */
/* This program contains information of a proprietary nature to Safran Electronics & Defense company     */
/* and is submitted in confidence for a specific purpose. The recipient assumes custody and control      */
/* and agrees that this document will not be copied or reproduced in whole or in part, nor its contents  */
/* revealed in any manner or to any person except to meet the purpose for which it was delivered.        */
/*                                                                                                       */
/* ----------------------------------------------------------------------------------------------------- */
/* PROJECT                : COBRA_SW                                                                     */
/* COMPANY                : Safran Electronics & Defense                                                 */
/* CSU NAME               : LIB_CHKSUM_CRC                                                               */
/* FILENAME               : LIB_CHKSUM_internal.h                                                        */
/* SYNERGY IDENTIFICATION : %full_name: fadex#1/incl/LIB_CHKSUM_internal.h/1 %                           */
/* DESCRIPTION            : The component BOOT MON CRC provides to the following data for CRC functions  */
/* ----------------------------------------------------------------------------------------------------- */
/* -------------------------    CHANGE HISTORY    ------------------------------------------------------ */
/* ----------------------------------------------------------------------------------------------------- */
/* ----------------------------------------------------------------------------------------------------- */
/* AUTHOR         | DATE       | CR ID   | DESCRIPTION                                                   */
/* ----------------------------------------------------------------------------------------------------- */
/* ----------------------------------------------------------------------------------------------------- */
/* T.T. DUONG     | 10/09/2020 | -       | 1 - Creation                                                  */
/* ----------------------------------------------------------------------------------------------------- */
/* ----------------------------------------------------------------------------------------------------- */


/* ---------- include predefined types: ------------------------------------- */
#include "CMN_TYPES_common.h"

/* ---------- include required interface: ----------------------------------- */
/* None */

/* ---------- provided define constants: ------------------------------------ */
#define K_LIB_CHKSUM_CRC_UINT8_0            (uint8_t)(0)
#define K_LIB_CHKSUM_CRC_UINT8_8            (uint8_t)(8)

#define K_LIB_CHKSUM_CRC_UINT32_0           (uint32_t)(0)
#define K_LIB_CHKSUM_CRC_UINT32_1           (uint32_t)(1)
#define K_LIB_CHKSUM_CRC_UINT32_2           (uint32_t)(2)
#define K_LIB_CHKSUM_CRC_UINT32_4           (uint32_t)(4)
#define K_LIB_CHKSUM_CRC_UINT32_8           (uint32_t)(8)
#define K_LIB_CHKSUM_CRC_UINT32_16          (uint32_t)(16)
#define K_LIB_CHKSUM_CRC_UINT32_24          (uint32_t)(24)

#define K_LIB_CHKSUM_CRC_NB_DIV             (uint32_t)(256)

/* CRC_CFG -  Register values */
/* x^32 + x^26 + x^23 + x^22 + x^16 + x^12 + x^11 + x^10 + x^8 + x^7 + x^5 + x^4 + x^2 + x + 1 */
#define K_LIB_CHKSUM_CRC_POLYG_32           (uint32_t)(0x00000004L)
                                            /* SWAP_BYTEWISE = 0b  : no swap byte */
                                            /* SWAP_BITWISE  = 0b  : no swap bits */
                                            /* POLYG         = 01b : CRC-32 polynomial */
                                            /* SWAP          = 0b  : no swap on output */
                                            /* INV           = 0b  : no inversion on output */

#define K_LIB_CHKSUM_CRC_INV_OUTP           (uint32_t)(0x00000005L)
                                            /* SWAP_BYTEWISE = 0b  : no swap byte */
                                            /* SWAP_BITWISE  = 0b  : no swap bits */
                                            /* POLYG         = 01b : CRC-32 polynomial */
                                            /* SWAP          = 0b  : no swap on output */
                                            /* INV           = 1b  : inversion on output */

#define K_LIB_CHKSUM_CRC_SWAP_OUTP          (uint32_t)(0x00000006L)
                                            /* SWAP_BYTEWISE = 0b  : no swap byte */
                                            /* SWAP_BITWISE  = 0b  : no swap bits */
                                            /* POLYG         = 01b : CRC-32 polynomial */
                                            /* SWAP          = 1b  : swap on output */
                                            /* INV           = 0b  : no inversion on output */

#define K_LIB_CHKSUM_CRC_SWAP_BIT_WISE      (uint32_t)(0x00000014L)
                                            /* SWAP_BYTEWISE = 0b  : no swap byte */
                                            /* SWAP_BITWISE  = 1b  : swap bits */
                                            /* POLYG         = 01b : CRC-32 polynomial */
                                            /* SWAP          = 0b  : swap on output */
                                            /* INV           = 0b  : no inversion on output */

#define K_LIB_CHKSUM_CRC_SWAP_BYTE_WISE     (uint32_t)(0x00000024L)
                                            /* SWAP_BYTEWISE = 1b  : swap byte */
                                            /* SWAP_BITWISE  = 0b  : no swap bits */
                                            /* POLYG         = 01b : CRC-32 polynomial */
                                            /* SWAP          = 0b  : swap on output */
                                            /* INV           = 0b  : no inversion on output */

//#define K_LIB_CHKSUM_CRC_SEED_VALUE         (uint32_t)(0xFFFFFFFFL)
#define K_LIB_CHKSUM_CRC_SEED_VALUE         (uint32_t)(0) //CKA
#define K_LIB_CHKSUM_CRC_FINAL_XOR_VALUE    (uint32_t)(0xFFFFFFFFL)

#define K_LIB_CHKSUM_DMA_LINE_0             (uint32_t)(0)

/* ---------- provided types: ----------------------------------------------- */

typedef signed int       boolean_t;

#define FALSE ((boolean_t) (0 == 1))   /* Expression returns '0' */
#define TRUE  ((boolean_t) (1 == 1))   /* Expression returns '1' */

/* CRC hardware module registers */
typedef struct
{
    /* CRC Config register, offset: 0x0 */
    uint32_t CRC_CFG;
    /* CRC Input register, offset: 0x4 */
    uint32_t CRC_INP;
    /* CRC Signature register, offset: 0x8 */
    uint32_t CRC_CSTAT;
    /* CRC Output register, offset: 0xC */
    uint32_t CRC_OUTP;
} TS_LIB_CHKSUM_CRC_Registers;


/* ---------- provided constants: ------------------------------------------- */
/* None */

/* ---------- provided data: ------------------------------------------------ */

extern void const * BOOT_HW_CRC_0_BASE_ADDR[];

/* ---------- provided operations: ------------------------------------------ */

/* -------------------------------------------------------------------------- */

/* BOOT CRC Hardware DMA Computation: To compute the compute the 32-bit Cyclic Redundancy Check using S32K CRC hardware module
 *                                    and DMA with 32-bit data
 *
 * Parameters:
 *   Inputs:
 *     - pt_StartAddr1 : pointer to the 1st memory area for CRC32 computation
 *     - p_Length1     : length of the 1st memory area
 *     - pt_StartAddr2 : pointer to the 2nd memory area for CRC32 computation
 *     - p_Length2     : length of the 2nd memory area
 *
 *   Outputs:
 *     - pt_CrcComputed : Computed CRC32
 *
 *   -------------------------------------------
 *   Pre-condition: Pointer(s) shall not be null
 *   -------------------------------------------
 *
 *  */
void LIB_CHKSUM_CRC_L_HwDmaComputation32(const uint32_t * const pt_StartAddr1, const uint32_t p_Length1,
                                         const uint32_t * const pt_StartAddr2, const uint32_t p_Length2,
                                         uint32_t *       const pt_CrcComputed);

#endif /* LIB_CHKSUM_CRC_INTERNAL_H */

/* ---------- End of file --------------------------------------------------- */

