/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
/* #include "MAC_interface.h" */
/* #include "netif.h" */
/* #include "HW_CONF.h" */
#include "LL.h"

#include "LIBMCP_Types.h"
#include "LIBBSP_ETSEC_InitAddress.h"
#include "etsec.h"
#include "LIBBSP_CCSR.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/
/*TS_LIBBSP_ETSEC_t_ll_p_tx_pools * P_LIBBSP_ETSEC_ll_tx_pools;
TS_LIBBSP_ETSEC_t_ll_p_rx_pools * P_LIBBSP_ETSEC_ll_rx_pools;
TS_LIBBSP_ETSEC_t_ll_p_tx_bd_tables * P_LIBBSP_ETSEC_ll_tx_bd_tables;
TS_LIBBSP_ETSEC_t_ll_p_rx_bd_tables * P_LIBBSP_ETSEC_ll_rx_bd_tables;*/


/*==== Services ========================================================================*/
/* {{RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Pointer conversion : Use generic pointer to pointeur of a specific struture */
TE_LIBBSP_ETSEC_NetworkStatus LIBBSP_ETSEC_InitAddress( const uint32_t * const txpool , const uint32_t * const txbd, 
                                                        const uint32_t * const rxpool , const uint32_t * const rxbd )
{

   P_LIBBSP_ETSEC_ll_tx_pools = (TS_LIBBSP_ETSEC_t_ll_p_tx_pools *) txpool;
   P_LIBBSP_ETSEC_ll_tx_bd_tables = (TS_LIBBSP_ETSEC_t_ll_p_tx_bd_tables *) txbd;
   P_LIBBSP_ETSEC_ll_rx_pools = (TS_LIBBSP_ETSEC_t_ll_p_rx_pools *) rxpool;
   P_LIBBSP_ETSEC_ll_rx_bd_tables = (TS_LIBBSP_ETSEC_t_ll_p_rx_bd_tables * ) rxbd;
   
   return E_LIBBSP_ETSEC_OK; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
/* }} RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> */
/*==== END =============================================================================*/
