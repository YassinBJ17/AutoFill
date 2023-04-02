/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_PSUM_GLOABLS_H
#define LIBBSP_PSUM_GLOABLS_H

#include "LIBBSP_PSUM.h"
#include "LIBBSP_CMPREG.h"
#include "LIBBSP_MATH.h"

/*==== Definitions =====================================================================*/
#define C_PSUM_ADC7_VIN6_FAIL_ADC3_PRES_FAIL (5ul)
#define C_PSUM_ADC_OVD_FLAG (4ul)
#define C_PSUM_ADC_UVD_FLAG (3ul)
#define C_PSUM_ADC_VIN7_FAIL (1ul)
#define C_PSUM_ADC_FAIL (0ul)

#define C_PSUM_ADC_SAMPLE_MASK (0xFFFul)

#define C_PSUM_ADC_NB_INITIALISATION_COUPLES 114ul

#define C_PSUM_ADC1234_CFG  (+0x000) /*Configuration of ADC1 to ADC4*/
#define C_PSUM_ADC567_CFG (+0x004) /*Configuration of ADC5 to ADC7*/

#define C_PSUM_ADC1_UVD_THRESHOLD_0 (+0x104) /*Under voltage threshold for channel 0 of ADC1*/
#define C_PSUM_ADC1_UVD_THRESHOLD_1 (+0x108) /*Under voltage threshold for channel 1 of ADC1*/
#define C_PSUM_ADC1_UVD_THRESHOLD_2 (+0x10C) /*Under voltage threshold for channel 2 of ADC1*/
#define C_PSUM_ADC1_UVD_THRESHOLD_3 (+0x110) /*Under voltage threshold for channel 3 of ADC1*/
#define C_PSUM_ADC1_UVD_THRESHOLD_4 (+0x114) /*Under voltage threshold for channel 4 of ADC1*/
#define C_PSUM_ADC1_UVD_THRESHOLD_5 (+0x118) /*Under voltage threshold for channel 5 of ADC1*/
#define C_PSUM_ADC1_UVD_THRESHOLD_6 (+0x11C) /*Under voltage threshold for channel 6 of ADC1*/
#define C_PSUM_ADC1_UVD_THRESHOLD_7 (+0x120) /*Under voltage threshold for channel 7 of ADC1*/

#define C_PSUM_ADC1_OVD_THRESHOLD_0 (+0x124) /*Over voltage threshold for channel 0 of ADC1*/
#define C_PSUM_ADC1_OVD_THRESHOLD_1 (+0x128) /*Over voltage threshold for channel 1 of ADC1*/
#define C_PSUM_ADC1_OVD_THRESHOLD_2 (+0x12C) /*Over voltage threshold for channel 2 of ADC1*/
#define C_PSUM_ADC1_OVD_THRESHOLD_3 (+0x130) /*Over voltage threshold for channel 3 of ADC1*/
#define C_PSUM_ADC1_OVD_THRESHOLD_4 (+0x134) /*Over voltage threshold for channel 4 of ADC1*/
#define C_PSUM_ADC1_OVD_THRESHOLD_5 (+0x138) /*Over voltage threshold for channel 5 of ADC1*/
#define C_PSUM_ADC1_OVD_THRESHOLD_6 (+0x13C) /*Over voltage threshold for channel 6 of ADC1*/
#define C_PSUM_ADC1_OVD_THRESHOLD_7 (+0x140) /*Over voltage threshold for channel 7 of ADC1*/

#define C_PSUM_ADC2_UVD_THRESHOLD_0 (+0x204) /*Under voltage threshold for channel 0 of ADC2*/
#define C_PSUM_ADC2_UVD_THRESHOLD_1 (+0x208) /*Under voltage threshold for channel 1 of ADC2*/
#define C_PSUM_ADC2_UVD_THRESHOLD_2 (+0x20C) /*Under voltage threshold for channel 2 of ADC2*/
#define C_PSUM_ADC2_UVD_THRESHOLD_3 (+0x210) /*Under voltage threshold for channel 3 of ADC2*/
#define C_PSUM_ADC2_UVD_THRESHOLD_4 (+0x214) /*Under voltage threshold for channel 4 of ADC2*/
#define C_PSUM_ADC2_UVD_THRESHOLD_5 (+0x218) /*Under voltage threshold for channel 5 of ADC2*/
#define C_PSUM_ADC2_UVD_THRESHOLD_6 (+0x21C) /*Under voltage threshold for channel 6 of ADC2*/
#define C_PSUM_ADC2_UVD_THRESHOLD_7 (+0x220) /*Under voltage threshold for channel 7 of ADC2*/

#define C_PSUM_ADC2_OVD_THRESHOLD_0 (+0x224) /*Over voltage threshold for channel 0 of ADC2*/
#define C_PSUM_ADC2_OVD_THRESHOLD_1 (+0x228) /*Over voltage threshold for channel 1 of ADC2*/
#define C_PSUM_ADC2_OVD_THRESHOLD_2 (+0x22C) /*Over voltage threshold for channel 2 of ADC2*/
#define C_PSUM_ADC2_OVD_THRESHOLD_3 (+0x230) /*Over voltage threshold for channel 3 of ADC2*/
#define C_PSUM_ADC2_OVD_THRESHOLD_4 (+0x234) /*Over voltage threshold for channel 4 of ADC2*/
#define C_PSUM_ADC2_OVD_THRESHOLD_5 (+0x238) /*Over voltage threshold for channel 5 of ADC2*/
#define C_PSUM_ADC2_OVD_THRESHOLD_6 (+0x23C) /*Over voltage threshold for channel 6 of ADC2*/
#define C_PSUM_ADC2_OVD_THRESHOLD_7 (+0x240) /*Over voltage threshold for channel 7 of ADC2*/

#define C_PSUM_ADC3_UVD_THRESHOLD_0 (+0x304) /*Under voltage threshold for channel 0 of ADC3*/
#define C_PSUM_ADC3_UVD_THRESHOLD_1 (+0x308) /*Under voltage threshold for channel 1 of ADC3*/
#define C_PSUM_ADC3_UVD_THRESHOLD_2 (+0x30C) /*Under voltage threshold for channel 2 of ADC3*/
#define C_PSUM_ADC3_UVD_THRESHOLD_3 (+0x310) /*Under voltage threshold for channel 3 of ADC3*/
#define C_PSUM_ADC3_UVD_THRESHOLD_4 (+0x314) /*Under voltage threshold for channel 4 of ADC3*/
#define C_PSUM_ADC3_UVD_THRESHOLD_5 (+0x318) /*Under voltage threshold for channel 5 of ADC3*/
#define C_PSUM_ADC3_UVD_THRESHOLD_6 (+0x31C) /*Under voltage threshold for channel 6 of ADC3*/
#define C_PSUM_ADC3_UVD_THRESHOLD_7 (+0x320) /*Under voltage threshold for channel 7 of ADC3*/

#define C_PSUM_ADC3_OVD_THRESHOLD_0 (+0x324) /*Over voltage threshold for channel 0 of ADC3*/
#define C_PSUM_ADC3_OVD_THRESHOLD_1 (+0x328) /*Over voltage threshold for channel 1 of ADC3*/
#define C_PSUM_ADC3_OVD_THRESHOLD_2 (+0x32C) /*Over voltage threshold for channel 2 of ADC3*/
#define C_PSUM_ADC3_OVD_THRESHOLD_3 (+0x330) /*Over voltage threshold for channel 3 of ADC3*/
#define C_PSUM_ADC3_OVD_THRESHOLD_4 (+0x334) /*Over voltage threshold for channel 4 of ADC3*/
#define C_PSUM_ADC3_OVD_THRESHOLD_5 (+0x338) /*Over voltage threshold for channel 5 of ADC3*/
#define C_PSUM_ADC3_OVD_THRESHOLD_6 (+0x33C) /*Over voltage threshold for channel 6 of ADC3*/
#define C_PSUM_ADC3_OVD_THRESHOLD_7 (+0x340) /*Over voltage threshold for channel 7 of ADC3*/

#define C_PSUM_ADC4_UVD_THRESHOLD_0 (+0x404) /*Under voltage threshold for channel 0 of ADC4*/
#define C_PSUM_ADC4_UVD_THRESHOLD_1 (+0x408) /*Under voltage threshold for channel 1 of ADC4*/
#define C_PSUM_ADC4_UVD_THRESHOLD_2 (+0x40C) /*Under voltage threshold for channel 2 of ADC4*/
#define C_PSUM_ADC4_UVD_THRESHOLD_3 (+0x410) /*Under voltage threshold for channel 3 of ADC4*/
#define C_PSUM_ADC4_UVD_THRESHOLD_4 (+0x414) /*Under voltage threshold for channel 4 of ADC4*/
#define C_PSUM_ADC4_UVD_THRESHOLD_5 (+0x418) /*Under voltage threshold for channel 5 of ADC4*/
#define C_PSUM_ADC4_UVD_THRESHOLD_6 (+0x41C) /*Under voltage threshold for channel 6 of ADC4*/
#define C_PSUM_ADC4_UVD_THRESHOLD_7 (+0x420) /*Under voltage threshold for channel 7 of ADC4*/

#define C_PSUM_ADC4_OVD_THRESHOLD_0 (+0x424) /*Over voltage threshold for channel 0 of ADC4*/
#define C_PSUM_ADC4_OVD_THRESHOLD_1 (+0x428) /*Over voltage threshold for channel 1 of ADC4*/
#define C_PSUM_ADC4_OVD_THRESHOLD_2 (+0x42C) /*Over voltage threshold for channel 2 of ADC4*/
#define C_PSUM_ADC4_OVD_THRESHOLD_3 (+0x430) /*Over voltage threshold for channel 3 of ADC4*/
#define C_PSUM_ADC4_OVD_THRESHOLD_4 (+0x434) /*Over voltage threshold for channel 4 of ADC4*/
#define C_PSUM_ADC4_OVD_THRESHOLD_5 (+0x438) /*Over voltage threshold for channel 5 of ADC4*/
#define C_PSUM_ADC4_OVD_THRESHOLD_6 (+0x43C) /*Over voltage threshold for channel 6 of ADC4*/
#define C_PSUM_ADC4_OVD_THRESHOLD_7 (+0x440) /*Over voltage threshold for channel 7 of ADC4*/

#define C_PSUM_ADC5_UVD_THRESHOLD_0 (+0x504) /*Under voltage threshold for channel 0 of ADC5*/
#define C_PSUM_ADC5_UVD_THRESHOLD_1 (+0x508) /*Under voltage threshold for channel 1 of ADC5*/
#define C_PSUM_ADC5_UVD_THRESHOLD_2 (+0x50C) /*Under voltage threshold for channel 2 of ADC5*/
#define C_PSUM_ADC5_UVD_THRESHOLD_3 (+0x510) /*Under voltage threshold for channel 3 of ADC5*/
#define C_PSUM_ADC5_UVD_THRESHOLD_4 (+0x514) /*Under voltage threshold for channel 4 of ADC5*/
#define C_PSUM_ADC5_UVD_THRESHOLD_5 (+0x518) /*Under voltage threshold for channel 5 of ADC5*/
#define C_PSUM_ADC5_UVD_THRESHOLD_6 (+0x51C) /*Under voltage threshold for channel 6 of ADC5*/
#define C_PSUM_ADC5_UVD_THRESHOLD_7 (+0x520) /*Under voltage threshold for channel 7 of ADC5*/

#define C_PSUM_ADC5_OVD_THRESHOLD_0 (+0x524) /*Over voltage threshold for channel 0 of ADC5*/
#define C_PSUM_ADC5_OVD_THRESHOLD_1 (+0x528) /*Over voltage threshold for channel 1 of ADC5*/
#define C_PSUM_ADC5_OVD_THRESHOLD_2 (+0x52C) /*Over voltage threshold for channel 2 of ADC5*/
#define C_PSUM_ADC5_OVD_THRESHOLD_3 (+0x530) /*Over voltage threshold for channel 3 of ADC5*/
#define C_PSUM_ADC5_OVD_THRESHOLD_4 (+0x534) /*Over voltage threshold for channel 4 of ADC5*/
#define C_PSUM_ADC5_OVD_THRESHOLD_5 (+0x538) /*Over voltage threshold for channel 5 of ADC5*/
#define C_PSUM_ADC5_OVD_THRESHOLD_6 (+0x53C) /*Over voltage threshold for channel 6 of ADC5*/
#define C_PSUM_ADC5_OVD_THRESHOLD_7 (+0x540) /*Over voltage threshold for channel 7 of ADC5*/

#define C_PSUM_ADC6_UVD_THRESHOLD_0 (+0x604) /*Under voltage threshold for channel 0 of ADC6*/
#define C_PSUM_ADC6_UVD_THRESHOLD_1 (+0x608) /*Under voltage threshold for channel 1 of ADC6*/
#define C_PSUM_ADC6_UVD_THRESHOLD_2 (+0x60C) /*Under voltage threshold for channel 2 of ADC6*/
#define C_PSUM_ADC6_UVD_THRESHOLD_3 (+0x610) /*Under voltage threshold for channel 3 of ADC6*/
#define C_PSUM_ADC6_UVD_THRESHOLD_4 (+0x614) /*Under voltage threshold for channel 4 of ADC6*/
#define C_PSUM_ADC6_UVD_THRESHOLD_5 (+0x618) /*Under voltage threshold for channel 5 of ADC6*/
#define C_PSUM_ADC6_UVD_THRESHOLD_6 (+0x61C) /*Under voltage threshold for channel 6 of ADC6*/
#define C_PSUM_ADC6_UVD_THRESHOLD_7 (+0x620) /*Under voltage threshold for channel 7 of ADC6*/

#define C_PSUM_ADC6_OVD_THRESHOLD_0 (+0x624) /*Over voltage threshold for channel 0 of ADC6*/
#define C_PSUM_ADC6_OVD_THRESHOLD_1 (+0x628) /*Over voltage threshold for channel 1 of ADC6*/
#define C_PSUM_ADC6_OVD_THRESHOLD_2 (+0x62C) /*Over voltage threshold for channel 2 of ADC6*/
#define C_PSUM_ADC6_OVD_THRESHOLD_3 (+0x630) /*Over voltage threshold for channel 3 of ADC6*/
#define C_PSUM_ADC6_OVD_THRESHOLD_4 (+0x634) /*Over voltage threshold for channel 4 of ADC6*/
#define C_PSUM_ADC6_OVD_THRESHOLD_5 (+0x638) /*Over voltage threshold for channel 5 of ADC6*/
#define C_PSUM_ADC6_OVD_THRESHOLD_6 (+0x63C) /*Over voltage threshold for channel 6 of ADC6*/
#define C_PSUM_ADC6_OVD_THRESHOLD_7 (+0x640) /*Over voltage threshold for channel 7 of ADC6*/

#define C_PSUM_ADC7_UVD_THRESHOLD_0 (+0x704) /*Under voltage threshold for channel 0 of ADC7*/
#define C_PSUM_ADC7_UVD_THRESHOLD_1 (+0x708) /*Under voltage threshold for channel 1 of ADC7*/
#define C_PSUM_ADC7_UVD_THRESHOLD_2 (+0x70C) /*Under voltage threshold for channel 2 of ADC7*/
#define C_PSUM_ADC7_UVD_THRESHOLD_3 (+0x710) /*Under voltage threshold for channel 3 of ADC7*/
#define C_PSUM_ADC7_UVD_THRESHOLD_4 (+0x714) /*Under voltage threshold for channel 4 of ADC7*/
#define C_PSUM_ADC7_UVD_THRESHOLD_5 (+0x718) /*Under voltage threshold for channel 5 of ADC7*/
#define C_PSUM_ADC7_UVD_THRESHOLD_6 (+0x71C) /*Under voltage threshold for channel 6 of ADC7*/
#define C_PSUM_ADC7_UVD_THRESHOLD_7 (+0x720) /*Under voltage threshold for channel 7 of ADC7*/

#define C_PSUM_ADC7_OVD_THRESHOLD_0 (+0x724) /*Over voltage threshold for channel 0 of ADC7*/
#define C_PSUM_ADC7_OVD_THRESHOLD_1 (+0x728) /*Over voltage threshold for channel 1 of ADC7*/
#define C_PSUM_ADC7_OVD_THRESHOLD_2 (+0x72C) /*Over voltage threshold for channel 2 of ADC7*/
#define C_PSUM_ADC7_OVD_THRESHOLD_3 (+0x730) /*Over voltage threshold for channel 3 of ADC7*/
#define C_PSUM_ADC7_OVD_THRESHOLD_4 (+0x734) /*Over voltage threshold for channel 4 of ADC7*/
#define C_PSUM_ADC7_OVD_THRESHOLD_5 (+0x738) /*Over voltage threshold for channel 5 of ADC7*/
#define C_PSUM_ADC7_OVD_THRESHOLD_6 (+0x73C) /*Over voltage threshold for channel 6 of ADC7*/
#define C_PSUM_ADC7_OVD_THRESHOLD_7 (+0x740) /*Over voltage threshold for channel 7 of ADC7*/

extern const float64_t C_PSUM_ADC_SAMPLE_LSB ;
extern const TS_LIBBSP_PSUM_AdcConversion C_PSUM_CONV_SCALE_OFFSET [E_LIBBSP_PSUM_NB_ADC][E_LIBBSP_PSUM_NB_CHANNEL];

extern const TS_LIBBSP_PSUM_Conf C_PSUM_Initialisation_Couples[C_PSUM_ADC_NB_INITIALISATION_COUPLES];

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/*==== END =============================================================================*/
#endif
