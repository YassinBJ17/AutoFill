/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_ELBC_H
#define LIBBSP_ELBC_H

#include "LIBMCP_Types.h"

/*==== Definitions =====================================================================*/

#define C_ELBC_LTESR 0xB0
/*#define C_ELBC_LTEDR 0xB4*/
/*#define C_ELBC_LTEIR 0xB8*/

#define C_ELBC_MASK_LTESR_PAR 0x20000000ul
#define C_ELBC_SHIFT_LTESR_PAR 29

/*==== Types ===========================================================================*/
typedef enum 
{
   E_LIBBSP_ELBC_VALID_ADDR = 0,
   E_LIBBSP_ELBC_INVALID_ADDR =  1

} TE_LIBBSP_ELBC_AddrStatus;

/*==== Variables========================================================================*/
extern volatile uint32_t * const V_ELBC_Interface;

/*==== Services ========================================================================*/
extern boolean_t LIBBSP_ELBC_GetStatus(void);

/*==== END =============================================================================*/
#endif /* LIBBSP_ECCMEM_H */
