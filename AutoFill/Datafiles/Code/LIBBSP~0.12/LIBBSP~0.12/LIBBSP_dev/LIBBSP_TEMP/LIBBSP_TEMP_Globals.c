/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_TEMP_Globals.h"

/*==== Definitions =====================================================================*/

const uint8_t C_TEMP_TMP451_ADDRESS = 0x4C;
const TE_LIBBSP_I2C_Bus C_TEMP_TMP451_USED_BUS      = E_LIBBSP_I2C_BUS_1;
const TE_LIBBSP_I2C_FreqDiv C_TEMP_TMP451_DIVISOR_VALUE = E_LIBBSP_I2C_DIV_1024;
const uint8_t C_TEMP_TMP451_DIGITAL_FILTER = 0x10;
const TS_LIBBSP_TEMP_Tmp451ConfCouple C_TEMP_TMP451_CONF [C_TEMP_NB_TMP451_CONF] =
{
	{ E_LIBBSP_TEMP_WRITE_CONFIGURATION_REGISTER, 					0x24 },
	{ E_LIBBSP_TEMP_WRITE_LOCAL_TEMPERATURE_HIGH_LIMIT, 				0x9f },
	{ E_LIBBSP_TEMP_WRITE_LOCAL_TEMPERATURE_LOW_LIMIT, 				0x18 },
	{ E_LIBBSP_TEMP_WRITE_REMOTE_TEMPERATURE_HIGH_LIMIT_HIGH_BITE, 	0xa9 },
	{ E_LIBBSP_TEMP_WRITE_REMOTE_TEMPERATURE_LOW_LIMIT_HIGH_BITE, 	0x18 },
	{ E_LIBBSP_TEMP_WRITE_REMOTE_TEMPERATURE_THERM_LIMIT, 			0xb8 },
	{ E_LIBBSP_TEMP_WRITE_LOCAL_TEMPERATURE_THERM_LIMIT, 			0xa4 },
	{ E_LIBBSP_TEMP_WRITE_THERM_HISTERESYS, 							0x05 },
	{ E_LIBBSP_TEMP_WRITE_FACTOR_CORECTION, 							0x04 },
	{ E_LIBBSP_TEMP_WRITE_CONVERSION_RATE_REGISTER, 					0x04 },
};

const int32_t C_DELTA = -64;

TE_LIBBSP_TEMP_Tmp451State V_TEMP_TMP451_State;
TE_LIBBSP_TEMP_Cmd V_TEMP_Cmd;

/*==== Types ===========================================================================*/

/*==== SERVICES ========================================================================*/

