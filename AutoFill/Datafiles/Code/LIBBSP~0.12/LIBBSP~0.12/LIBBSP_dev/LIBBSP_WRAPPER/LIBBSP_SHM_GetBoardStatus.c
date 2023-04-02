/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_SHM_GetBoardStatus.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_SHM_GetBoardStatus(TS_LIBBSP_SHM_BoardStatus * const BoardStatus,
                               uint32_t * const                  v_regValue)
{
   TU_LIBBSP_SHM_RegValue v_RegValue;
   
   LIBBSP_SHM_GetStatus(E_LIBBSP_SHM_BOARD_STATUS, &v_RegValue);
   


   BoardStatus->pwr_good_28v1 = (boolean_t)v_RegValue.v_BoardBitField.pwr_good_28v1;
   BoardStatus->pwr_good_28v2 = (boolean_t)v_RegValue.v_BoardBitField.pwr_good_28v2;
   BoardStatus->ddr_vtt_uv = (boolean_t)v_RegValue.v_BoardBitField.ddr_vtt_uv;
   BoardStatus->ddr_vtt_ov = (boolean_t)v_RegValue.v_BoardBitField.ddr_vtt_ov;
   BoardStatus->vdd_uv = (boolean_t)v_RegValue.v_BoardBitField.vdd_uv;
   BoardStatus->vdd_ov = (boolean_t)v_RegValue.v_BoardBitField.vdd_ov;
   BoardStatus->cpcm_1v5_uv = (boolean_t)v_RegValue.v_BoardBitField.cpcm_1v5_uv;
   BoardStatus->cpcm_1v5_ov = (boolean_t)v_RegValue.v_BoardBitField.cpcm_1v5_ov;
   BoardStatus->vio_3v3_uv = (boolean_t)v_RegValue.v_BoardBitField.vio_3v3_uv;
   BoardStatus->vio_3v3_ov = (boolean_t)v_RegValue.v_BoardBitField.vio_3v3_ov;
   BoardStatus->cpcm_1v8_uv = (boolean_t)v_RegValue.v_BoardBitField.cpcm_1v8_uv;
   BoardStatus->cpcm_1v8_ov = (boolean_t)v_RegValue.v_BoardBitField.cpcm_1v8_ov;
   
   BoardStatus->mezz_pgood = (boolean_t)v_RegValue.v_BoardBitField.mezz_pgood;
   BoardStatus->mezz_fail = (boolean_t)v_RegValue.v_BoardBitField.mezz_fail;
   BoardStatus->ready_p1 = (boolean_t)v_RegValue.v_BoardBitField.ready_p1;
   BoardStatus->trig_out = (boolean_t)v_RegValue.v_BoardBitField.trig_out;
   BoardStatus->pgood_p2v5 = (boolean_t)v_RegValue.v_BoardBitField.pgood_p2v5;
   BoardStatus-> pgood_1v2meg = (boolean_t)v_RegValue.v_BoardBitField.pgood_1v2meg;
   BoardStatus->meg_fail = (boolean_t)v_RegValue.v_BoardBitField.meg_fail;
   BoardStatus->meg_pll_lock = (boolean_t)v_RegValue.v_BoardBitField.meg_pll_lock;
   BoardStatus->therm = (boolean_t)v_RegValue.v_BoardBitField.therm;
   BoardStatus->therm2 = (boolean_t)v_RegValue.v_BoardBitField.therm2;
   BoardStatus->lvdd_type = (boolean_t)v_RegValue.v_BoardBitField.lvdd_type;
   BoardStatus->tank_fail = (boolean_t)v_RegValue.v_BoardBitField.tank_fail;
   BoardStatus->pgood_vant = (boolean_t)v_RegValue.v_BoardBitField.pgood_vant;
   BoardStatus->pgood_vrm = (boolean_t)v_RegValue.v_BoardBitField.pgood_vrmm;
   BoardStatus->inhibit_wdg = (boolean_t)v_RegValue.v_BoardBitField.inhibit_wdg;

   *v_regValue = v_RegValue.v_data;

}

/*==== END =============================================================================*/
