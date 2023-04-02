/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_WD_InitDelay.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_WD_InitDelay( const uint16_t v_Delay ,
						  const uint16_t v_Width)
{
   uint32_t v_buff;
   
   /* construction du mot � �crire */
   v_buff = (uint32_t)( (uint32_t)v_Delay << C_WD_SHIFT_DELAY ) + (uint32_t)( (uint32_t)v_Width << C_WD_SHIFT_WIDTH );
   v_buff = v_buff & C_WD_MASK_CNT_CFG;
   
   V_WDRegs->wdg_cnt_cfg = v_buff;
}

/*==== END =============================================================================*/
