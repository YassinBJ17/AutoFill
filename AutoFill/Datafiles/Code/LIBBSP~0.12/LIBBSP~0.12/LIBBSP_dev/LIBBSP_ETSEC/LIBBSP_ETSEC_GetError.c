/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_ETSEC_GetError.h"
#include "LIBBSP_ETSEC_InitAddress.h"
#include "HW_CONF.h"
#include "etsec.h"

/*==== Definitions =====================================================================*/
#define C_ETSEC_SHIFT_QHLT0 23
#define C_ETSEC_SHIFT_THLT0 31
/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_ETSEC_NetworkStatus LIBBSP_ETSEC_GetError( const TE_LIBBSP_ETSEC_Network network, TS_LIBBSP_ETSEC_Error * const ErrorStatus )
{
   TE_LIBBSP_ETSEC_NetworkStatus v_ret;
   t_ETSEC *pt_etsec;

   if ( (network >= E_LIBBSP_ETSEC_NETWORK_1) && (network < E_LIBBSP_ETSEC_NB_NETWORK) )
   {
	   /* >RELAX<SYNCHRONe_C_Code_10.7> Cast specific enum to generic data */
	   pt_etsec = (t_ETSEC*)((uint32_t)CONF_CPU.init[network].etsec_base_address + (uint32_t)V_LIBBSP_ETSEC_ccsr_base_address);

	   /* {{RELAX<SYNCHRONe_C_Code_10.7> Apply right shift, cast result on uint8_t */
	   ErrorStatus->eTSECx_RSTAT_QHLT0 = (uint8_t)(pt_etsec->RSTAT >> C_ETSEC_SHIFT_QHLT0);
	   ErrorStatus->eTSECx_TSTAT_THLT0 = (uint8_t)(pt_etsec->TSTAT >> C_ETSEC_SHIFT_THLT0);
	   /* }} RELAX<SYNCHRONe_C_Code_10.7> */
	   
	   v_ret = E_LIBBSP_ETSEC_OK;
   }
   else
   {
	   ErrorStatus->eTSECx_RSTAT_QHLT0 = (uint8_t)0;
	   ErrorStatus->eTSECx_TSTAT_THLT0 = (uint8_t)0;
	   v_ret = E_LIBBSP_ETSEC_KO;
   }

   return v_ret; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */

}

/*==== END =============================================================================*/
