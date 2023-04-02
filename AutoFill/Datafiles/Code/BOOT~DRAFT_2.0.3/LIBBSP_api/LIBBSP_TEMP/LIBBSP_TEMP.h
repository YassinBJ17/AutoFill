/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_TEMP_H
#define LIBBSP_TEMP_H

#include "LIBBSP_I2C.h"
#include "LIBMCP_Types.h"

/*==== Definitions =====================================================================*/


/*==== Types ===========================================================================*/

typedef enum {
    E_TMP451_CLOSED                  = 0,
    E_TMP451_OPEN                    = 1
} TE_LIBBSP_TEMP_Tmp451State;

typedef enum {
	E_LIBBSP_TEMP_CMD_IDLE                   = 0,
	E_LIBBSP_TEMP_CMD_READ                   = 1
} TE_LIBBSP_TEMP_Cmd;

/*typedef enum
{
	E_LIBBSP_TEMP_READ_LOCAL_TEMPERATURE_HIGH_BYTE				=0x00,
	E_LIBBSP_TEMP_READ_LOCAL_REMOTE_HIGH_BYTE					=0x01,
	E_LIBBSP_TEMP_READ_STATUS_REGISTER							=0x02,
	E_LIBBSP_TEMP_READ_CONFIGURATION_REGISTER					=0x03,
	E_LIBBSP_TEMP_READ_CONVERSION_RATE_REGISTER					=0x04,
	E_LIBBSP_TEMP_READ_LOCAL_TEMPERATURE_HIGH_LIMIT				=0x05,
	E_LIBBSP_TEMP_READ_LOCAL_TEMPERATURE_LOW_LIMIT				=0x06,
	E_LIBBSP_TEMP_READ_REMOTE_TEMPERATURE_HIGH_LIMIT_HIGH_BITE	=0x07,
	E_LIBBSP_TEMP_READ_REMOTE_TEMPERATURE_LOW_LIMIT_HIGH_BITE	=0x08,
	E_LIBBSP_TEMP_READ_REMOTE_TEMPERATURE_LOW_BITE				=0x10,
	E_LIBBSP_TEMP_READ_REMOTE_TEMPERATURE_OFFSET_HIGH_BITE		=0x11,
	E_LIBBSP_TEMP_READ_REMOTE_TEMPERATURE_OFFSET_LOW_BITE		=0x12,
	E_LIBBSP_TEMP_READ_REMOTE_TEMPERATURE_HIGH_LIMIT_LOW_BITE	=0x13,
	E_LIBBSP_TEMP_READ_REMOTE_TEMPERATURE_LOW_LIMIT_LOW_BITE	=0x14,
	E_LIBBSP_TEMP_READ_LOCAL_TEMPERATURE_LOW_BYTE				=0x15,
	E_LIBBSP_TEMP_READ_REMOTE_TEMPERATURE_THERM_LIMIT			=0x19,
	E_LIBBSP_TEMP_READ_LOCAL_TEMPERATURE_THERM_LIMIT			=0x20,
	E_LIBBSP_TEMP_READ_THERM_HISTERESYS							=0x21,
	E_LIBBSP_TEMP_READ_CONSECUTIVE_ALTER						=0x22,
	E_LIBBSP_TEMP_READ_FACTOR_CORECTION							=0x23,
	E_LIBBSP_TEMP_READ_DIGITAL_FILTER_CONTROL					=0x24,
	E_LIBBSP_TEMP_READ_DIGITAL_MANUFATURER_IR					=0xFE
}
TE_LIBBSP_TEMP_ReadRegAddr;*/
/* define in kcg_typesh  */


typedef enum
{
	E_LIBBSP_TEMP_WRITE_CONFIGURATION_REGISTER					=0x09,
	E_LIBBSP_TEMP_WRITE_CONVERSION_RATE_REGISTER				=0x0a,
	E_LIBBSP_TEMP_WRITE_LOCAL_TEMPERATURE_HIGH_LIMIT			=0x0b,
	E_LIBBSP_TEMP_WRITE_LOCAL_TEMPERATURE_LOW_LIMIT				=0x0c,
	E_LIBBSP_TEMP_WRITE_REMOTE_TEMPERATURE_HIGH_LIMIT_HIGH_BITE	=0x0d,
	E_LIBBSP_TEMP_WRITE_REMOTE_TEMPERATURE_LOW_LIMIT_HIGH_BITE	=0x0e,
	E_LIBBSP_TEMP_WRITE_ONE_SHOT_START							=0x0f,
	E_LIBBSP_TEMP_WRITE_REMOTE_TEMPERATURE_OFFSET_HIGH_BITE		=0x11,
	E_LIBBSP_TEMP_WRITE_REMOTE_TEMPERATURE_OFFSET_LOW_BITE		=0x12,
	E_LIBBSP_TEMP_WRITE_REMOTE_TEMPERATURE_HIGH_LIMIT_LOW_BITE	=0x13,
	E_LIBBSP_TEMP_WRITE_REMOTE_TEMPERATURE_LOW_LIMIT_LOW_BITE	=0x14,
	E_LIBBSP_TEMP_WRITE_REMOTE_TEMPERATURE_THERM_LIMIT			=0x19,
	E_LIBBSP_TEMP_WRITE_LOCAL_TEMPERATURE_THERM_LIMIT			=0x20,
	E_LIBBSP_TEMP_WRITE_THERM_HISTERESYS						=0x21,
	E_LIBBSP_TEMP_WRITE_CONSECUTIVE_ALTER						=0x22,
	E_LIBBSP_TEMP_WRITE_FACTOR_CORECTION						=0x23,
	E_LIBBSP_TEMP_WRITE_DIGITAL_FILTER_CONTROL					=0x24,
	E_LIBBSP_TEMP_WRITE_DIGITAL_MANUFATURER_IR					=0xFE
}
TE_LIBBSP_TEMP_WriteRegAddr;

typedef struct
{
	TE_LIBBSP_TEMP_WriteRegAddr v_reg;
	uint8_t      v_data;
} TS_LIBBSP_TEMP_Tmp451ConfCouple;

/*#define C_TEMP_NB_TMP451_CONF (10)*/
/*extern const TS_LIBBSP_TEMP_Tmp451ConfCouple C_TEMP_TMP451_CONF [C_TEMP_NB_TMP451_CONF];*/


/*==== Variables========================================================================*/

extern const uint8_t C_TEMP_TMP451_ADDRESS;
extern const TE_LIBBSP_I2C_Bus C_TEMP_TMP451_USED_BUS;
extern const TE_LIBBSP_I2C_FreqDiv C_TEMP_TMP451_DIVISOR_VALUE;
extern const uint8_t C_TEMP_TMP451_DIGITAL_FILTER;
extern TE_LIBBSP_TEMP_Tmp451State V_TEMP_TMP451_State;
extern TE_LIBBSP_TEMP_Cmd V_TEMP_Cmd;

/*==== Services ========================================================================*/

extern TE_LIBBSP_I2C_Code LIBBSP_TEMP_Close(void);
extern TE_LIBBSP_I2C_Code LIBBSP_TEMP_Open(void);
extern void LIBBSP_TEMP_ReadTempStep(TE_LIBBSP_I2C_CurrentStep const v_step_in, TE_LIBBSP_I2C_CurrentStep* const v_step_out, TE_LIBBSP_I2C_ErrorCode * const v_ret);
extern TE_LIBBSP_I2C_Code LIBBSP_TEMP_Configure(void);
extern float64_t LIBBSP_TEMP_GetTemp( void );
extern void LIBBSP_TEMP_ReadTemp(const TE_LIBBSP_TEMP_ReadRegAddr v_reg ,TE_LIBBSP_I2C_CurrentStep const v_step_in, TE_LIBBSP_I2C_CurrentStep* const v_step_out, TE_LIBBSP_I2C_ErrorCode * const v_ret);

/*==== END =============================================================================*/
#endif
