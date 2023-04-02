/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_ETSEC_AckError.h"
#include "LIBBSP_ETSEC_InitAddress.h"
#include "HW_CONF.h"
#include "etsec.h"

/*==== Definitions =====================================================================*/
#define ETSEC_RSTAT_QHLT0_MASK 0x00800000ul
#define ETSEC_TSTAT_THLT0_MASK 0x80000000ul

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_ETSEC_NetworkStatus LIBBSP_ETSEC_AckError( const TE_LIBBSP_ETSEC_Network network )
{
   TE_LIBBSP_ETSEC_NetworkStatus v_ret;
   t_ETSEC *pt_etsec;

   if ( (network < E_LIBBSP_ETSEC_NB_NETWORK) 
		&& (network >= E_LIBBSP_ETSEC_NETWORK_1 )
	)
   {
	   /* >RELAX<SYNCHRONe_C_Code_10.7> Cast specific enum to generic data */
	   pt_etsec = (t_ETSEC*)((uint32_t)CONF_CPU.init[network].etsec_base_address + (uint32_t)V_LIBBSP_ETSEC_ccsr_base_address); 

	    if((pt_etsec->RSTAT & ETSEC_RSTAT_QHLT0_MASK) == ETSEC_RSTAT_QHLT0_MASK)
		{
	    	pt_etsec->RSTAT = pt_etsec->RSTAT | ETSEC_RSTAT_QHLT0_MASK;
		}

	    if((pt_etsec->TSTAT & ETSEC_TSTAT_THLT0_MASK) == ETSEC_TSTAT_THLT0_MASK)
		{
	    	pt_etsec->TSTAT = pt_etsec->TSTAT | ETSEC_TSTAT_THLT0_MASK;
		}

	   v_ret = E_LIBBSP_ETSEC_OK;
   }
   else
   {
	   v_ret = E_LIBBSP_ETSEC_KO;
   }

   return v_ret; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */

}

/*==== END =============================================================================*/
