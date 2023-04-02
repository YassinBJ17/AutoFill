/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_IMU_GetAdditionalReadDataWrapper.h"

/*==== Definitions =====================================================================*/
/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_IMU_GetAdditionalReadDataWrapper(const uint32_t NbDataToRead,
                                             float64_t * const AdditionnalReadData)
{
   TS_LIBBSP_IMU_DoubleWord v_RawAdditionalData [C_NB_MAX_ADDITIONAL_DATA];
   uint32_t v_i;
   
   LIBBSP_IMU_GetAdditionalReadData(NbDataToRead, &v_RawAdditionalData[0]);
   
   for (v_i=0ul;v_i<NbDataToRead;v_i++)
   {
	  /* >RELAX<SYNCHRONe_C_Code_17.4> AdditionnalReadData used as buffer with data to read in it.*/
      AdditionnalReadData[v_i] = LIBBSP_IMU_F40toF64(&v_RawAdditionalData[v_i]);
   }
}

/*==== END =============================================================================*/
