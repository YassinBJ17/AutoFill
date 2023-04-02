/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_ETR_H
#define LIBBSP_ETR_H

#include "LIBBSP_I2C.h"
#include "LIBMCP_Types.h"
#include "kcg_types.h"

/*==== Definitions =====================================================================*/

/*==== Types ===========================================================================*/

/*typedef enum {
    E_LIBBSP_ETR_DS1682_CLOSED                  = 0,
    E_LIBBSP_ETR_DS1682_OPEN                    = 1
} TE_LIBBSP_ETR_Ds1682State;*/
/* defined in kcg_types */

typedef enum {
    E_LIBBSP_ETR_DS1682_CONFREG             = 0x00,         /* Configuration register */
    E_LIBBSP_ETR_DS1682_ALMREG_LL           = 0x01,         /* Alarm Register Low byte */
    E_LIBBSP_ETR_DS1682_ALMREG_LM           = 0x02,         /* Alarm Register Low Middle byte */
    E_LIBBSP_ETR_DS1682_ALMREG_HM           = 0x03,         /* Alarm Register High Middle byte */
    E_LIBBSP_ETR_DS1682_ALMREG_HH           = 0x04,         /* Alarm Register High byte */
    E_LIBBSP_ETR_DS1682_ETCREG_LL           = 0x05,         /* Elapsed Time Counter Low byte */
    E_LIBBSP_ETR_DS1682_ETCREG_LM           = 0x06,         /* Elapsed Time Counter Low Middle byte */
    E_LIBBSP_ETR_DS1682_ETCREG_HM           = 0x07,         /* Elapsed Time Counter High Middle byte */
    E_LIBBSP_ETR_DS1682_ETCREG_HH           = 0x08,         /* Elapsed Time Counter High byte */
    E_LIBBSP_ETR_DS1682_ECREG_L             = 0x09,         /* Event Counter Low byte */
    E_LIBBSP_ETR_DS1682_ECREG_H             = 0x0A,         /* Event Counter High byte */
    E_LIBBSP_ETR_DS1682_USRMEM              = 0x0B,         /* User Memory */
	E_LIBBSP_ETR_DS1682_BITE_1              = 0x0B,
	E_LIBBSP_ETR_DS1682_BITE_2              = 0x0C,
	E_LIBBSP_ETR_DS1682_BITE_3              = 0x0D,
	E_LIBBSP_ETR_DS1682_BITE_4              = 0x0E,
	E_LIBBSP_ETR_DS1682_BITE_5              = 0x0F,
	E_LIBBSP_ETR_DS1682_BITE_6              = 0x10,
	E_LIBBSP_ETR_DS1682_BITE_7              = 0x11,
	E_LIBBSP_ETR_DS1682_BITE_8              = 0x12,
	E_LIBBSP_ETR_DS1682_BITE_9              = 0x13,
	E_LIBBSP_ETR_DS1682_BITE_10             = 0x14,
	/* adresses between 0x18 and 0x1C not used */
    E_LIBBSP_ETR_DS1682_RESETCMD            = 0x1D,         /* Reset Command */
    E_LIBBSP_ETR_DS1682_WRITEDISABLE        = 0x1E,         /* Write Disable */
    E_LIBBSP_ETR_DS1682_WRITEMEMORYDISABLE  = 0x1F,          /* Write Memory Disable */
	E_LIBBSP_ETR_DS1682_NBREG        = 32
} TE_LIBBSP_ETR_Ds1682RegisterAddress;

/*typedef struct
{
	uint32_t      v_AlarmRegdata;
	uint32_t      v_ETregdata;
	uint16_t      v_EventCountdata;
} TS_LIBBSP_ETR_ReadInfos;*/
/* defined in kcg_types.h */

/*==== Variables========================================================================*/

extern const uint8_t C_ETR_DS1682_ADDRESS;
// extern const TE_LIBBSP_I2C_Bus C_ETR_DS1682_USED_BUS;
extern const TE_LIBBSP_I2C_FreqDiv C_ETR_DS1682_DIVISOR_VALUE;
extern const uint8_t C_ETR_DS1682_DIGITAL_FILTER;
// extern TE_LIBBSP_ETR_Ds1682State V_ETR_DS1682_State;

/*==== Services ========================================================================*/

extern TE_LIBBSP_I2C_Code LIBBSP_ETR_Close(void);
extern TE_LIBBSP_I2C_Code LIBBSP_ETR_Configure(void);
extern TE_LIBBSP_I2C_Code LIBBSP_ETR_Open(void);
extern void LIBBSP_ETR_ReadInfos(TS_LIBBSP_ETR_ReadInfos * const v_ReadValue, TE_LIBBSP_I2C_Code * const v_ret);

/*==== END =============================================================================*/
#endif /* _HARDDS1382_H_ */
