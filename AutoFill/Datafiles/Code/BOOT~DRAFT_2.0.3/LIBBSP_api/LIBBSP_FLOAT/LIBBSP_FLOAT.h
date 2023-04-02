/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_FLOAT_H
#define LIBBSP_FLOAT_H

#include "LIBMCP_Types.h"

/*==== Definitions =====================================================================*/


/*==== Types ===========================================================================*/

/*typedef struct
{
	uint32_t SOVH		: 1;
	uint32_t OVH		: 1;
	uint32_t FGH		: 1;
	uint32_t FXH		: 1;
	uint32_t FINVH 	: 1;
	uint32_t FDBZH 	: 1;
	uint32_t FUNFH 	: 1;
	uint32_t FOVFH 	: 1;
	uint32_t reserved2 : 2;
	uint32_t FINXS		: 1;
	uint32_t FINVS 	: 1;
	uint32_t FDBZS 	: 1;
	uint32_t FUNFS 	: 1;
	uint32_t FOVFS 	: 1;
	uint32_t MODE 		: 1;
	uint32_t SOV 		: 1;
	uint32_t OV 		: 1;
	uint32_t FG 		: 1;
	uint32_t FX 		: 1;
	uint32_t FINV 		: 1;
	uint32_t FDBZ 		: 1;
	uint32_t FUNF 		: 1;
	uint32_t FOVF 		: 1;
	uint32_t reserved3 : 1;
	uint32_t FINXE		: 1;
	uint32_t FINVE		: 1;
	uint32_t FDBZE 	: 1;
	uint32_t FUNFE 	: 1;
	uint32_t FOVFE 	: 1;
	uint32_t FRMC 		: 2;

} TS_LIBBSP_FLOAT_RegSpefscr;*/


typedef union
{
    /* Global SPEFSCR value. */
    uint32_t FpscrValue;

    /* SPEFSCR bitfields. */
    struct
    {
			uint32_t SOVH		: 1;
			uint32_t OVH		: 1;
			uint32_t FGH		: 1;
			uint32_t FXH		: 1;
			uint32_t FINVH 	: 1;
			uint32_t FDBZH 	: 1;
			uint32_t FUNFH 	: 1;
			uint32_t FOVFH 	: 1;
			uint32_t reserved2 : 2;
			uint32_t FINXS		: 1;
			uint32_t FINVS 	: 1;
			uint32_t FDBZS 	: 1;
			uint32_t FUNFS 	: 1;
			uint32_t FOVFS 	: 1;
			uint32_t MODE 		: 1;
			uint32_t SOV 		: 1;
			uint32_t OV 		: 1;
			uint32_t FG 		: 1;
			uint32_t FX 		: 1;
			uint32_t FINV 		: 1;
			uint32_t FDBZ 		: 1;
			uint32_t FUNF 		: 1;
			uint32_t FOVF 		: 1;
			uint32_t reserved3 : 1;
			uint32_t FINXE		: 1;
			uint32_t FINVE		: 1;
			uint32_t FDBZE 	: 1;
			uint32_t FUNFE 	: 1;
			uint32_t FOVFE 	: 1;
			uint32_t FRMC 		: 2;
   } FpscrFields;
    /*struct
    {
			uint32_t FRMC 		: 2;
			uint32_t FOVFE 	: 1;
			uint32_t FUNFE 	: 1;
			uint32_t FDBZE 	: 1;
			uint32_t FINVE		: 1;
			uint32_t FINXE		: 1;
			uint32_t reserved3 : 1;
			uint32_t FOVF 		: 1;
			uint32_t FUNF 		: 1;
			uint32_t FDBZ 		: 1;
			uint32_t FINV 		: 1;
			uint32_t FX 		: 1;
			uint32_t FG 		: 1;
			uint32_t OV 		: 1;
			uint32_t SOV 		: 1;
			uint32_t MODE 		: 1;
			uint32_t FOVFS 	: 1;
			uint32_t FUNFS 	: 1;
			uint32_t FDBZS 	: 1;
			uint32_t FINVS 	: 1;
			uint32_t FINXS		: 1;
			uint32_t reserved2 : 2;
			uint32_t FOVFH 	: 1;
			uint32_t FUNFH 	: 1;
			uint32_t FDBZH 	: 1;
			uint32_t FINVH 	: 1;
			uint32_t FXH		: 1;
			uint32_t FGH		: 1;
			uint32_t OVH		: 1;
			uint32_t SOVH		: 1;
   } FpscrFields;*/
/*Voir PowerPC e500 datasheet*/
}TS_LIBBSP_FLOAT_RegSpefscr;

/*==== Variables========================================================================*/

/*==== Services ========================================================================*/

extern TS_LIBBSP_FLOAT_RegSpefscr LIBBSP_FLOAT_GetFPR(void);
extern void LIBBSP_FLOAT_SetFPR(const uint32_t v_FPSCR);
/*==== END =============================================================================*/
#endif /* LIBBSP_FLOAT_H */
