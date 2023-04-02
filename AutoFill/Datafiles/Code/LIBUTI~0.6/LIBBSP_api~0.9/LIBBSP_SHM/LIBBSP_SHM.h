/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_SHM_H
#define LIBBSP_SHM_H

#include "LIBMCP_Types.h"
#include "kcg_types.h"


/*==== Definitions =====================================================================*/

/*==== Types ===========================================================================*/

typedef enum
{
    E_LIBBSP_SHM_VALID_ADDR,
	E_LIBBSP_SHM_INVALID_ADDR
}TE_LIBBSP_SHM_AddrStatus;

typedef enum
{
    E_BOARD_SUCCEEDED,
    E_BOARD_FAILED
}TE_Board_Status;
/*
typedef enum
{
	E_LIBBSP_SHM_POWER_UP_STATE = 1,
	E_LIBBSP_SHM_INITIALIZATION_STATE = 2,
	E_LIBBSP_SHM_IDLE_STATE = 4,
	E_LIBBSP_SHM_OPERATIONNAL_UP_STATE = 8,
	E_LIBBSP_SHM_DEGRADED_STATE = 16,
	E_LIBBSP_SHM_FAILURE_STATE = 32
}
TE_LIBBSP_SHM_Mode;
*/
/* defined in kcg_types.h */

/*
typedef struct 
{
	uint32_t critical_uvd_cnt;
	uint32_t hw_reset_request_cnt;
	uint32_t sw_reset_request_cnt;
	uint32_t wd_failure_cnt;
}TS_LIBBSP_SHM_CompStatus;

typedef struct
{
	boolean_t inhibit_wdg;
	boolean_t tank_fail;
	boolean_t lvdd_type;
	boolean_t therm2;
	boolean_t therm;
	boolean_t meg_pll_lock;
	boolean_t meg_fail;
	boolean_t pgood_1v2meg;
	boolean_t pgood_p2v5;
	boolean_t trig_out;
	boolean_t ready_p1;
	boolean_t mezz_fail;
	boolean_t mezz_pgood;
	boolean_t cpcm_1v8_ov;
	boolean_t cpcm_1v8_uv;
	boolean_t vio_3v3_ov;
	boolean_t vio_3v3_uv;
	boolean_t cpcm_1v5_ov;
	boolean_t cpcm_1v5_uv;
	boolean_t vdd_ov;
	boolean_t vdd_uv;
	boolean_t ddr_vtt_ov;
	boolean_t ddr_vtt_uv;
	boolean_t pwr_good_28v2;
	boolean_t pwr_good_28v1;
}TS_LIBBSP_SHM_BoardStatus;
*/
/* defined in user_types.h */

typedef struct
{
	TS_LIBBSP_SHM_BoardStatus Board_Status;
	TS_LIBBSP_SHM_CompStatus Comp_Status;
}TS_LIBBSP_SHM_State;


typedef union
{
	uint32_t v_data;
	/*TS_State_Bitfield*/
	struct 
	{
		uint32_t inhibit_wdg:1;
      uint32_t not_used :5;
      uint32_t pgood_vrmm:1;
      uint32_t pgood_vant:1;
		uint32_t tank_fail :1;
		uint32_t lvdd_type:1;
		uint32_t therm2:1;
		uint32_t therm:1;
		uint32_t meg_pll_lock:1;
		uint32_t meg_fail:1;
		uint32_t pgood_1v2meg:1;
		uint32_t pgood_p2v5:1;
		uint32_t trig_out:1;
		uint32_t ready_p1:1;
		uint32_t mezz_fail:1;
		uint32_t mezz_pgood:1;
		uint32_t cpcm_1v8_ov:1;
		uint32_t cpcm_1v8_uv:1;
		uint32_t vio_3v3_ov:1;
		uint32_t vio_3v3_uv:1;
		uint32_t cpcm_1v5_ov:1;
		uint32_t cpcm_1v5_uv:1;
		uint32_t vdd_ov:1;
		uint32_t vdd_uv:1;
		uint32_t ddr_vtt_ov:1;
		uint32_t ddr_vtt_uv:1;
		uint32_t pwr_good_28v2:1;
		uint32_t pwr_good_28v1:1;
	}	v_bitfield;
}
TU_LIBBSP_SHM_BoardBitfield;

typedef union
{
	uint32_t v_data;
	struct
	{
	   uint32_t wd_failure_cnt: 8;
	   uint32_t sw_reset_request_cnt: 8;
	   uint32_t hw_reset_request_cnt: 8;
		uint32_t critical_uvd_cnt: 8;
	} v_bitfield;
}
TU_LIBBSP_SHM_CompBitfield;


/*typedef struct
{
    uint32_t* p_Board_BaseAddress ;
}TS_LIBBSP_SHM_BoardInterface;*/

/*typedef enum { 
   E_LIBBSP_SHM_COMP_STATUS = 0, 
   E_LIBBSP_SHM_BOARD_STATUS =  1, 
   E_LIBBSP_SHM_NB_REGISTERS =  2 
} TE_LIBBSP_SHM_Register;*/ 
/* defined in kcg_types.h */
typedef union
{
	uint32_t v_data;
	struct 
	{
		uint32_t inhibit_wdg:1;
		uint32_t not_used :5;
		uint32_t pgood_vrmm:1;
		uint32_t pgood_vant:1;
		uint32_t tank_fail :1;
		uint32_t lvdd_type:1;
		uint32_t therm2:1;
		uint32_t therm:1;
		uint32_t meg_pll_lock:1;
		uint32_t meg_fail:1;
		uint32_t pgood_1v2meg:1;
		uint32_t pgood_p2v5:1;
		uint32_t trig_out:1;
		uint32_t ready_p1:1;
		uint32_t mezz_fail:1;
		uint32_t mezz_pgood:1;
		uint32_t cpcm_1v8_ov:1;
		uint32_t cpcm_1v8_uv:1;
		uint32_t vio_3v3_ov:1;
		uint32_t vio_3v3_uv:1;
		uint32_t cpcm_1v5_ov:1;
		uint32_t cpcm_1v5_uv:1;
		uint32_t vdd_ov:1;
		uint32_t vdd_uv:1;
		uint32_t ddr_vtt_ov:1;
		uint32_t ddr_vtt_uv:1;
		uint32_t pwr_good_28v2:1;
		uint32_t pwr_good_28v1:1;
	}	v_BoardBitField;
	struct
	{
	   uint32_t wd_failure_cnt: 8;
	   uint32_t sw_reset_request_cnt: 8;
	   uint32_t hw_reset_request_cnt: 8;
	   uint32_t critical_uvd_cnt: 8;
	} v_CompBitField;
}
TU_LIBBSP_SHM_RegValue;

typedef struct
{
	uint32_t reg_id_version;
	uint32_t shm_pbit_ok_ref;
    uint32_t shm_pbit_ok_user;
    uint32_t shm_state;
    uint32_t hw_rst_ref;
    uint32_t hw_rst_user;
    uint32_t fail_switch_ref;
    uint32_t fail_switch_user;
    uint32_t board_status;
    uint32_t comp_status;
    uint32_t reg_hpms_reset;
}TS_LIBBSP_SHM_Registers;

/*==== Variables ========================================================================*/

//extern TS_LIBBSP_SHM_BoardInterface V_Board_Interface_Context;

extern volatile TS_LIBBSP_SHM_Registers * const V_SHMRegs;
/*==== Services ========================================================================*/

extern TE_LIBBSP_SHM_Mode LIBBSP_SHM_GetMode(void);
extern void LIBBSP_SHM_Reset(const uint32_t v_SHM_User);
extern void LIBBSP_SHM_SetMode(const TE_LIBBSP_SHM_Mode v_SHM_Mode, const uint32_t v_SHM_User);
extern void LIBBSP_SHM_GetStatus(const TE_LIBBSP_SHM_Register v_RegName, TU_LIBBSP_SHM_RegValue * const v_RegValue);
extern void LIBBSP_SHM_GetVersion(uint32_t * const version);
extern void LIBBSP_SHM_SetHpmsReset(const boolean_t v_Value);
/******************************************************************************/

									

									



#endif /*LIBBSP_SHM_H*/
