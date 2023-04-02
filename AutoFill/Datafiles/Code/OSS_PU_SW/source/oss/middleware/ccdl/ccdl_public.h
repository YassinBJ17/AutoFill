/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef CCDL_PUBLIC_H
#define CCDL_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"
#include "memory/shared_memory_public.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
/*  CCDL A429_2AB tx words count */
#define CCDL_A429_2AB_TX_WORDS_COUNT ((uint32_t) 27)

/*  Number of nfreq3 measures*/
#define NFREQ3_MEASURES_COUNT 12

/* ---------- provided types: ----------------------------------------------- */
/* CCDL frame structure */
typedef struct {
   uint32_t  s_index;
   uint32_t  s_css_data_size;
   uint8_t   s_css_data[CCDL_MSG_SIZE];
   uint32_t  s_a429_2ab_tx_count;
   uint32_t  s_a429_2ab_tx_words[CCDL_A429_2AB_TX_WORDS_COUNT];
   uint32_t  s_a429_2ab_tx_cbit_wrd;
   float32_t s_vrt1_measure;
   uint32_t  s_vrt1_cbit_wrd;
   float32_t s_vrt2_measure;
   uint32_t  s_vrt2_cbit_wrd;
   float32_t s_vrtff_measure;
   uint32_t  s_vrtff_cbit_wrd;
   float32_t s_p3_measure;
   uint32_t  s_p3_cbit_wrd;
   float32_t s_sg1_sg3_measure;
   uint32_t  s_sg1_sg3_cbit_wrd;
   float32_t s_sg2_sg4_measure;
   uint32_t  s_sg2_sg4_cbit_wrd;
   float32_t s_sg5_measure;
   uint32_t  s_sg5_cbit_wrd;
   float32_t s_t4_measure;
   uint32_t  s_t4_cbit_wrd;
   float32_t s_pot_1_2_measure;
   uint32_t  s_pot_1_2_cbit_wrd;
   float32_t s_potdiff_1_2_measure;
   uint32_t  s_potdiff_1_2_cbit_wrd;
   float32_t s_pot_3_measure;
   uint32_t  s_pot_3_cbit_wrd;
   float32_t s_xr_xrb_measure;
   float32_t s_xr_xrb_vcos_measure;
   float32_t s_xr_xrb_vsin_measure;
   uint32_t  s_xr_xrb_fault_wrd;
   float32_t s_lvdtab_ratio_measure;
   float32_t s_lvdtab_vs1_measure;
   float32_t s_lvdtab_vs2_measure;
   uint32_t  s_lvdtab_cbit_wrd;
   float32_t s_lvdtc_ratio_measure;
   float32_t s_lvdtc_vs1_measure;
   float32_t s_lvdtc_vs2_measure;
   uint32_t  s_lvdtc_cbit_wrd;
   float32_t s_p0_measure;
   uint32_t  s_p0_cbit_wrd;
   float32_t s_calres_1_3_measure;
   float32_t s_calres_2_4_measure;
   uint32_t  s_calres_cbit_wrd;
   float32_t s_tecu_measure;
   uint32_t  s_tecu_cbit_wrd;
   float32_t s_ngalt_measure;
   uint32_t  s_ngalt_cbit_wrd;
   float32_t s_nfreq2_measure;
   uint32_t  s_nfreq2_cbit_wrd;
   float32_t s_nfreq3_measure;
   uint32_t  s_nfreq3_cbit_wrd;
   float32_t s_nfreq3_ratio_measure;
   float32_t s_nfreq3_tn_measures [NFREQ3_MEASURES_COUNT];
   uint32_t  s_nfreq3_tpn_measures[NFREQ3_MEASURES_COUNT];
   float32_t s_tmot_measure_current;
   float32_t s_tmot_measure_voltage;
   uint32_t  s_tmot_cbit_wrd;
   uint32_t  s_ch_health_wrd;
}
ts_ccdl_frame;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
extern ts_ccdl_frame ccdl_rx_frame;

/* Data used by a429 : ch A tells ch B to send data on a429 2ab */
extern ts_a429_tx ccdl_a429_2ab_tx_from_ch_a;

/* ---------- provided operations: ------------------------------------------ */

/* Initialize ccdl acquisition */
extern void ccdl_init    (void);

/* Performs ccdl acquisition and provides CSS with results */
extern void ccdl_periodic_rx(const boolean_t channel_is_a);

/* Performs ccdl trasnmission over FPGA-based CCDL */
extern void ccdl_periodic_tx(const boolean_t channel_is_a);

#endif /* CCDL_PUBLIC_H */
