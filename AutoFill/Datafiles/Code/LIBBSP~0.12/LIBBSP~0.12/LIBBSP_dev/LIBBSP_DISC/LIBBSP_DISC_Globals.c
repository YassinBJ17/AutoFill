/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
#include "LIBBSP_DISC_Globals.h"

/*==== Definitions =====================================================================*/


const TS_LIBBSP_DISC_Max7312ConfCouple C_DISC_MAX7312_CONF_EXP_1 [C_DISC_NB_MAX7312_CONF] =
{
    { E_LIBBSP_DISC_MAX732_POLARITY_INVERSION_1, 0x00},
    { E_LIBBSP_DISC_MAX732_POLARITY_INVERSION_2, 0x00},
    { E_LIBBSP_DISC_MAX732_CONFIGURATION_1, 0xf5 },
    { E_LIBBSP_DISC_MAX732_CONFIGURATION_2, 0xff },
    { E_LIBBSP_DISC_MAX732_TIMEOUT, 0x00 }
};

const TS_LIBBSP_DISC_Max7312ConfCouple C_DISC_MAX7312_CONF_EXP_2 [C_DISC_NB_MAX7312_CONF] =
{
    { E_LIBBSP_DISC_MAX732_POLARITY_INVERSION_1, 0x00},
    { E_LIBBSP_DISC_MAX732_POLARITY_INVERSION_2, 0x00},
    { E_LIBBSP_DISC_MAX732_CONFIGURATION_1, 0x00 },
    { E_LIBBSP_DISC_MAX732_CONFIGURATION_2, 0xc0 },
    { E_LIBBSP_DISC_MAX732_TIMEOUT, 0x00 }
};

const uint16_t C_DISC_MASK_FIRST_BYTE = 0xFF;
const uint8_t C_DISC_MAX7312_IO_EXP1_ADDR	= 0x20;
const uint8_t C_DISC_MAX7312_IO_EXP2_ADDR	= 0x21;
const TE_LIBBSP_I2C_Bus C_DISC_MAX7312_USED_BUS      		= E_LIBBSP_I2C_BUS_2;
const TE_LIBBSP_I2C_FreqDiv C_DISC_MAX7312_DIVISOR_VALUE 	= E_LIBBSP_I2C_DIV_1024;
const uint8_t C_DISC_MAX7312_DIGITAL_FILTER 	= 0x10;



/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/*==== END =============================================================================*/