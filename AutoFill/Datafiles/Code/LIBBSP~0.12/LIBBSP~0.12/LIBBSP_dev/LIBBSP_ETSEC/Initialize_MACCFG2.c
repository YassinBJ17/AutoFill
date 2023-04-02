/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "etsec.h"
#include "HW_CONF.h"
#include "Initialize_MACCFG2.h"
/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void Initialize_MACCFG2(uint32_t * const init_value, uint32_t const speed, uint32_t const crc_type, uint32_t const duplex)
{

    *init_value = ETSEC_MACCFG2_PREAMB_SIZE;   /* pream is not parametrable */

    /* get link speed from CPU dependant parameter table */
    if(speed == HW_CONF_LINK_SPEED_1000_MBITS)
    {
        /* byte mode */
        *init_value |= ETSEC_MACCFG2_IF_1GB;   /* set 1000Mbits configuration */
    }
    else
    {
        /* nibble mode */
        *init_value |= ETSEC_MACCFG2_IF_100MB; /* set 100Mbits configuration */
    }

    /* get duplex type from CPU dependant parameter table */
    if(duplex == HW_CONF_LINK_FULL_DUPLEX)
    {
        *init_value |= ETSEC_MACCFG2_FULL_DUPLEX;
    }
    else
    {
         /* nop : default value is half duplex */
    }

    /* get crc type from CPU dependant parameter table */
    if(crc_type == (uint32_t)HW_CONF_CRC_TYPE_HW)
    {
        /* *init_value |= ETSEC_MACCFG2_CRC_HW;
        / modification LLJ le 6/5/2015 pour faire comme le driver uboot*/
        *init_value |= ETSEC_MACCFG2_PAD_CRC;
    }
    else
    {
         /* nop : defalut value is sw CRC computation */
    }

    /* assign initialization value to ETSEC register */
    //p_etsec->MACCFG2 = *init_value;
}

/*==== END =============================================================================*/
