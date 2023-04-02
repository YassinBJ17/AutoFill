/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_ETR_GLOBALS_H
#define LIBBSP_ETR_GLOBALS_H

#include "LIBBSP_ETR.h"
#include "LIBBSP_I2C.h"
#include "kcg_types.h"

/*==== Definitions =====================================================================*/

#define C_ETR_BUFF_CONF (2ul)
#define C_ETR_CONF_VALUE (0)


#define C_ETR_BUFF_WRITE 1ul
#define C_ETR_BUFF_READ 4
#define C_ETR_BUFF_READ_ALARM 4ul
#define C_ETR_BUFF_READ_EVENT_COUNTER 2

#define C_ETR_BUFF_CONF (2ul)
#define C_ETR_CONF_VALUE (0)

extern const uint32_t C_ETR_SHIFT_8_BITS;
extern const uint32_t C_ETR_SHIFT_16_BITS;
extern const uint32_t C_ETR_SHIFT_24_BITS;

extern const TE_LIBBSP_I2C_Bus C_ETR_DS1682_USED_BUS;
extern TE_LIBBSP_ETR_Ds1682State V_ETR_DS1682_State;
extern const uint32_t C_ETR_SHIFT_8_BITS;


/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/*==== END =============================================================================*/
#endif
