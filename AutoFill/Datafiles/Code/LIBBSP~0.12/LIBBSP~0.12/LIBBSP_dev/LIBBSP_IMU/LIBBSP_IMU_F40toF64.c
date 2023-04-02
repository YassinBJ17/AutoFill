/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/

#include "LIBBSP_IMU_F40toF64.h"



/*==== Definitions =====================================================================*/


/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
 float64_t LIBBSP_IMU_F40toF64( const TS_LIBBSP_IMU_DoubleWord* const p_dw)
{
	/* on ne fait pas de calcul, on se contente de changer le placement des bits pour */
	TS_LIBBSP_IMU_DoubleWord v_temp;
	/* pour g�rer les cas d�normalis�s */
	uint32_t v_mant;
	uint32_t v_dep;

	v_temp.float_double = 0.0;
	/*v_temp.float_64.first.s = p_dw->float_40.first.s;*/ /* recopie le bit de signe*/

	v_temp.double_int.msb = p_dw->double_int.msb; /* on ne veux copier que le signe mais ce n'est pas grave de tout */
	                                             /*copier car les donn�es seront re�cras�es plus tard */

	/* traitement des cas particuliers */
	if ( p_dw->float_40.first.exp == (uint32_t)0  ) /* exp = 0 => nombre d�norm�lis� ou -0 +0 */
	{
		if ((p_dw->float_40.first.mant == (uint32_t)0) && (p_dw->float_40.second.mant == (uint32_t)0) )  /* 0 ou -0*/
		{
			/* retour de la valeur 0 */
			/* +0 et -0 selon le signe copi� plus haut */
		}
		else /* nombre d�n�rmalis� */
		{
			/* un nombre d�normalis� en F40 l'est pas en F64 par construction */
			/* calcul du 1er 1 */
			v_dep = (uint32_t)0;
			/*{{RELAX<SYNCHRONe_C_Code_11.1,SYNCHRONe_C_Code_10.7>*/
			/*There is a poiter conversion with a loss odf precision on the lsb. This operation is wanted in the computation of v_mant*/
			v_mant = ( ( (p_dw->double_int.msb) & C_IMU_MASK_23_MSB_BITS ) << C_IMU_SHIFT_8_BITS ) + (uint32_t)(*( (uint8_t*)(&p_dw->double_int.lsb) ));
			/*}}RELAX<SYNCHRONe_C_Code_11.1,SYNCHRONe_C_Code_10.7> */
			/* on d�cale la mantisse bit par bit pour renormaliser le nombre */
			while ( (v_mant & C_IMU_MASK_BIT_31) == (uint32_t)0) /* v�rification du bit � 1 */
			{
				v_dep ++;
				v_mant <<= 1;
			}
			v_mant <<= 1; /* on d�cale une derni�re fois car en normalis� le MSB � 1 est implicite */
			v_dep++;
			v_temp.float_64.first.mant = ((v_mant)&C_IMU_MASK_31_MSB_BITS)>>C_IMU_SHIFT_11_BITS;
			v_temp.float_64.second = ((v_mant&C_IMU_MASK_11_MSB_BITS)<<C_IMU_SHIFT_21_BITS) ;
			/*{{RELAX<SYNCHRONe_C_Code_10.7>*/
			/*There is a pointer conversion with a loss of precision on the lsb. This operation is wanted in the computation of exp*/
			v_temp.float_64.first.exp = (uint32_t)(-((int32_t)C_IMU_EXPONENT_BIAS_SINGLE_PRECISION + (int32_t)v_dep)) + C_IMU_EXPONENT_BIAS_DOUBLE_PRECISION + (uint32_t)1 /* a cause de la renormalisation */;/* %RELAX<SYNCHRONe_C_Code_10.3> cast to type of different signedness: normalization */
			/*}}RELAX<SYNCHRONe_C_Code_10.7> */
		}
	}
	else if ( p_dw->float_40.first.exp == C_IMU_EXPONENT_VALUE_MAX_SINGLE_PRECISION ) /* +inf -inf qnan snan */
	{
		v_temp.float_64.first.exp = C_IMU_EXPONENT_VALUE_MAX_DOUBLE_PRECISION;
		if ( (p_dw->float_40.first.mant) == (uint32_t)0 && (p_dw->float_40.second.mant == (uint32_t)0) )
		{
			/* + or - infinite */
			/* le bit de signe a d�j� �t� copi� */
			/* pas besoin de recopier la mantisse qui est d�j� � 0  car la mantisse 40 a d�j� �t� recopi�e � 0 */
			/* au tout d�but de la fonction */
		}
		else /* qnan ou snan */
		{
			/* hors du MSB de la mantisse seul la dif par rapport � 0 est importante */
			if ( (p_dw->float_40.first.mant & ( C_IMU_MASK_BIT_23 ) ) != (uint32_t)0 ) /* qnan */
			{
				v_temp.float_64.first.mant = C_IMU_MASK_BIT_20;
			}
			else /* snan */
			{
				v_temp.float_64.first.mant = (uint32_t)1; /* 1 is added to avoid - infinite */
			}
		}
	}
	else
	{
		v_temp.float_64.first.exp = (((uint32_t)(p_dw->float_40.first.exp) - (uint32_t)127) + (uint32_t)1023) ; /* on repositionne le biai*/
		/* on recup�re les 20 premiers bits de la mantisse */
		v_temp.float_64.first.mant = p_dw->float_40.first.mant >> C_IMU_SHIFT_3_BITS; /* suppression de 3 bits */
		/* ecriture du second mot */
		v_temp.float_64.second = ((p_dw->float_40.first.mant & C_IMU_MASK_3_MSB_BITS)<<C_IMU_SHIFT_29_BITS) + (p_dw->float_40.second.mant << C_IMU_SHIFT_21_BITS);
	}


	return v_temp.float_double;
}
/*==== END =============================================================================*/
