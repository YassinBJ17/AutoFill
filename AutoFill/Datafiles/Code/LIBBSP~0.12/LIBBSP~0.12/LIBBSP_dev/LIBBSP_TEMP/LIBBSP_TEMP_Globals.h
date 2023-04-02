/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_TEMP_GLOBALS_H
#define LIBBSP_TEMP_GLOBALS_H

#include "LIBBSP_TEMP.h"

/*==== Definitions =====================================================================*/
#define C_TEMP_NB_TMP451_CONF (10)
#define C_TEMP_NB_BUFF_GET_TEMP 1ul
#define C_TEMP_NB_BUFF (2ul)
#define C_BUFF (2)

extern const TS_LIBBSP_TEMP_Tmp451ConfCouple C_TEMP_TMP451_CONF [C_TEMP_NB_TMP451_CONF];

extern const int32_t C_DELTA;

/*==== Types ===========================================================================*/

/*==== SERVICES ========================================================================*/
#endif
