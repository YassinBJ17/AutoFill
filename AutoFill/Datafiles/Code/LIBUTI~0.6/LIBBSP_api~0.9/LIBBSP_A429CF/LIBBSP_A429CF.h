/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/

/*==== Definitions =====================================================================*/
#ifndef LIBBSP_A429CF_H
#define LIBBSP_A429CF_H

#include "LIBMCP_Types.h"
#include "kcg_types.h"

#define A429_TX_LINES_COUNT 8ul

/*==== Types ===========================================================================*/

typedef enum
{
    E_LIBBSP_A429CF_VALID_ADDR = 0,
    E_LIBBSP_A429CF_INVALID_ADDR = 1
} TE_LIBBSP_A429CF_AddrStatus;

typedef enum
{
    E_LIBBSP_A429CF_OK = 0,
    E_LIBBSP_A429CF_INVALID_TX_LINE = 1
} TE_LIBBSP_A429CF_ErrorCode;

/*==== Variables========================================================================*/

extern volatile uint32_t * const V_A429CF_Pointer;

/*==== Services ========================================================================*/

extern TE_LIBBSP_A429CF_ErrorCode LIBBSP_A429CF_MuxSelection(const uint8_t v_TxChannelNum);

/*==== END =============================================================================*/
#endif
