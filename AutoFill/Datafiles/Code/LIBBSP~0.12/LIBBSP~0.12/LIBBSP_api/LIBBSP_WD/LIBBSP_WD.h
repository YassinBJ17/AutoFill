/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_WD_H
#define LIBBSP_WD_H

#include "LIBMCP_Types.h"

/*==== Types ===========================================================================*/

typedef enum
{
    E_LIBBSP_VALID_ADDR,
	E_LIBBSP_INVALID_ADDR
}TE_LIBBSP_WD_AddrStatus;


/*typedef struct
{
    uint32_t* p_Watchdog_BaseAddress;
}TS_LIBBSP_WD_WatchdogInterface;*/

typedef struct
{
    uint32_t wdg_pwd_ref;
    uint32_t wdg_pwd_user;
    uint32_t wdg_cnt_cfg;
    uint32_t wdg_state;
    uint32_t init_wdg_delay;
}TS_LIBBSP_WD_Registers;


/*==== Variables========================================================================*/

//extern TS_LIBBSP_WD_WatchdogInterface V_Watchdog_Interface_Context;
// extern volatile TS_LIBBSP_WD_Registers * const V_WDRegs;

/*==== Services ========================================================================*/

extern void LIBBSP_WD_InitDelay( const uint16_t v_Delay ,
						  const uint16_t v_Width);
extern void LIBBSP_WD_Rearm(const uint32_t v_WDG_User);

/******************************************************************************/


#endif /* COMPAGNON_WATCHDOG_INTERFACE_H*/
