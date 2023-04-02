/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_ETSEC_CONSTS_H
#define LIBBSP_ETSEC_CONSTS_H

#include "LIBBSP_ETSEC.h"

/*==== Definitions =====================================================================*/

/*==== Types ========================================================================*/


/*==== Variables =======================================================================*/
extern const uint32_t V_LIBBSP_ETSEC_ccsr_base_address ;
extern TS_LIBBSP_ETSEC_t_ll_p_tx_pools * P_LIBBSP_ETSEC_ll_tx_pools;
extern TS_LIBBSP_ETSEC_t_ll_p_rx_pools * P_LIBBSP_ETSEC_ll_rx_pools;
extern TS_LIBBSP_ETSEC_t_ll_p_tx_bd_tables * P_LIBBSP_ETSEC_ll_tx_bd_tables;
extern TS_LIBBSP_ETSEC_t_ll_p_rx_bd_tables * P_LIBBSP_ETSEC_ll_rx_bd_tables;
/*==== Services ========================================================================*/

/*==== END =============================================================================*/
#endif
