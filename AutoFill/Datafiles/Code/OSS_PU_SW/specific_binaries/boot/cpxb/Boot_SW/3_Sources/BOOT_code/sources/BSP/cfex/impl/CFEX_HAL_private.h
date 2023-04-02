#ifndef CFEX_HAL_PRIVATE_H_
#define CFEX_HAL_PRIVATE_H_



/* --------------------------------------------------------------------------
 *                           Sagem Defense Securite
 *                               SAFRAN Group
 * --------------------------------------------------------------------------
 * PROJECT : CHRONOS
 * CSU name :
 * %name: CFEX_HAL_private.h %
 * %full_name: fadex#1/incl/CFEX_HAL_private.h/1 %
 *
 * Creation information:
 *   Created by: F073297
 *   Date : Thu Jan 31 16:36:24 CET 2019
 *
 * Modification information:
 *   %derived_by: F605763 %
 *   %date_created:Thu May 12 18:18:00 CEST 2022 %
 * --------------------------------------------------------------------------
 * SAGEM Defense Securite document. Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "CMN_TYPES_common.h"

/* ---------- provided define constants: ------------------------------------ */

typedef enum
{
	e_CFEX_HWCRC_CONF_0 = 0,

	e_CFEX_HWCRC_CONF_NB
}
te_CFEX_HWCRC_CONF ;

typedef enum
{
	e_CFEX_DMA_CONF_HWCRC = 0 ,

	e_CFEX_DMA_CONF_NB
}
te_CFEX_DMA_CONF ;

#endif /* CFEX_HAL_PRIVATE_H_ */
