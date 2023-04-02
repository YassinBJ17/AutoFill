/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_PSUM_InitThreshold.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_PSUM_InitThreshold(const TS_LIBBSP_PSUM_Conf * const p_conf,
                               const uint32_t                    v_nb_initilisation_couple)
{
   uint32_t v_i;
   volatile uint32_t * pt_reg;
   uint8_t* pt_base;
   /*{{RELAX<SYNCHRONe_C_Code_11.1,SYNCHRONe_C_Code_10.7>  */ 
   pt_base = (uint8_t*)(V_PSUMonitoring_BaseAddress);
   /*}}RELAX<SYNCHRONe_C_Code_11.1,SYNCHRONe_C_Code_10.7> */
   for ( v_i = 0ul ; v_i < v_nb_initilisation_couple ; v_i ++ )
   {
	  /*{{RELAX<SYNCHRONe_C_Code_17.4,SYNCHRONe_C_Code_11.1,SYNCHRONe_C_Code_10.7> */
	  /*Conversion of pointer because explicit computation of an adress */ 
	  /*Array indexing on p_conf because its used as a buffer*/
      pt_reg = (volatile uint32_t *)(pt_base + p_conf[v_i].v_address);
      *pt_reg = p_conf[v_i].v_data;
	  /*}}RELAX<SYNCHRONe_C_Code_17.4,SYNCHRONe_C_Code_11.1,SYNCHRONe_C_Code_10.7> */
   }
}
/*==== END =============================================================================*/
