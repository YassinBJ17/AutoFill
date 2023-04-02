/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_PSUM_H
#define LIBBSP_PSUM_H

#include "LIBMCP_Types.h"
#include "kcg_types.h"

/*==== Definitions =====================================================================*/

#define C_PSUM_ADC1_DELTA (0x100)
#define C_PSUM_ADC2_DELTA (0x200)
#define C_PSUM_ADC3_DELTA (0x300)
#define C_PSUM_ADC4_DELTA (0x400)
#define C_PSUM_ADC5_DELTA (0x500)
#define C_PSUM_ADC6_DELTA (0x600)
#define C_PSUM_ADC7_DELTA (0x700)

#define C_PSUM_ADC_SAMPLE (0x44)
/*==== Types ===========================================================================*/
/* function return */
typedef enum
{
    E_LIBBSP_PSUM_VALID_ADDR,
	E_LIBBSP_PSUM_INVALID_ADDR
} TE_LIBBSP_PSUM_AddrStatus;


/* function return */
/*typedef enum
{
    E_LIBBSP_PSUM_SUCCEEDED,
    E_LIBBSP_PSUM_FAILED
} TE_LIBBSP_PSUM_Status;*/
/* defined in kcg_types.h */

/* structure to convert an hex data in a voltage data */
typedef struct
{
	float64_t v_scale;
	float64_t v_offset;
} TS_LIBBSP_PSUM_AdcConversion;

/* function used to initialise the ADC */
/*typedef struct
{
	uint32_t v_address;
	uint32_t v_data;
}TS_LIBBSP_PSUM_Conf;*/
/* defined in kcg_types.h */


/* definition of the ADC */
/*typedef enum
{
    E_LIBBSP_PSUM_ADC_1 = 0,
    E_LIBBSP_PSUM_ADC_2,
    E_LIBBSP_PSUM_ADC_3,
    E_LIBBSP_PSUM_ADC_4,
    E_LIBBSP_PSUM_ADC_5,
    E_LIBBSP_PSUM_ADC_6,
    E_LIBBSP_PSUM_ADC_7,
	E_LIBBSP_PSUM_NB_ADC
}TE_LIBBSP_PSUM_Adc;*/
/* defined in kcg_types.h */

/* definition of the channels */
typedef enum
{
    E_LIBBSP_PSUM_CHANNEL_0 = 0,
	E_LIBBSP_PSUM_CHANNEL_1,
    E_LIBBSP_PSUM_CHANNEL_2,
	E_LIBBSP_PSUM_CHANNEL_3,
    E_LIBBSP_PSUM_CHANNEL_4,
    E_LIBBSP_PSUM_CHANNEL_5,
    E_LIBBSP_PSUM_CHANNEL_6,
    E_LIBBSP_PSUM_CHANNEL_7,
	E_LIBBSP_PSUM_NB_CHANNEL
}TE_LIBBSP_PSUM_AdcChannel;

typedef  struct
{
	TE_LIBBSP_PSUM_Adc v_adc;
	TE_LIBBSP_PSUM_AdcChannel v_channel;
} TS_Voltage_to_ADC_Channels;

/* error struct */
/*typedef struct */
/*{ */
/*	boolean_t PresFail_or_Vin6Failure */ /* ADC3_PRES_FAIL ADC7_VIN6_FAIL *//*;*/ /* not for adc other than 3 and 7 */
/*    boolean_t OverVoltage */ /* ADCN_OVD_FLAG*/ /*;*/
/*    boolean_t UnderVoltage */ /*ADCN_UVD_FLAG*//*;*/
/*    boolean_t ReferenceVoltageFailure */ /* ADCN_REF_FAIL *//*;*/
/*    boolean_t Vin7NotInRange */ /* ADCN_VIN7_FAIL *//*;*/
/*    boolean_t GeneralFailure */ /* ADCN_FAIL*//*;*/
/*}TS_LIBBSP_PSUM_AdcErrorFlags; */
/* defined in kcg_types.h */


/*==== Variables ========================================================================*/
extern const uint32_t C_PSUM_DRV_ADC_ADCn_DELTA[E_LIBBSP_PSUM_NB_ADC];
extern uint32_t * const V_PSUMonitoring_BaseAddress;

/*==== Services ========================================================================*/

extern void LIBBSP_PSUM_GetStatus(const TE_LIBBSP_PSUM_Adc v_ADC, /*IN*/
                                  TS_LIBBSP_PSUM_AdcErrorFlags * const p_ADCErrorFlags, uint16_t * const v_RegValue, TE_LIBBSP_PSUM_Status * const v_ret);

extern TE_LIBBSP_PSUM_Status LIBBSP_PSUM_GetValue(const TE_LIBBSP_PSUM_Adc v_ADC, /*IN*/
                            const TE_LIBBSP_PSUM_AdcChannel v_ADCChannel, /*IN*/
							uint32_t * const v_value /*OUT*/
                            );

extern TE_LIBBSP_PSUM_Status LIBBSP_PSUM_GetValueV(const TE_LIBBSP_PSUM_Adc v_ADC, /*IN*/
			const TE_LIBBSP_PSUM_AdcChannel v_ADCChannel, /*IN*/
			float64_t* const v_value /*OUT*/);

extern void LIBBSP_PSUM_InitDefaultThreshold(void);
#endif /*LIBBSP_PSUM_H*/
