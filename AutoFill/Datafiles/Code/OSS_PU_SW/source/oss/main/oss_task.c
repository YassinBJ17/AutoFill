/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : C function containing all the OSS process
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "libtools/time/LIB_TIME_public.h"
#include "main/oss_task_public.h"
#include "middleware/rtc/rtc_public.h"
#include "middleware/pca9535e/pca9535e_public.h"

#include "middleware/accom/accom_public.h"
#include "middleware/watchdog/watchdog_public.h"
#include "middleware/tmot/tmot_public.h"
#include "middleware/smot/smot_public.h"
#include "middleware/powersup/powersup_public.h"
#include "middleware/sg/sg_public.h"
#include "middleware/resolver/resolver_public.h"
#include "middleware/lvdt/lvdt_public.h"
#include "middleware/nfreq/nfreq_public.h"
#include "middleware/can/can_public.h"
#include "middleware/a429/a429_public.h"
#include "middleware/tecu/tecu_public.h"
#include "middleware/vrt/vrt_public.h"
#include "middleware/t4/t4_public.h"
#include "middleware/discrete/discrete_public.h"
#include "middleware/ccdl/ccdl_public.h"
#include "middleware/icdl/MID_ICDL_public.h"
#include "middleware/hpdisc/hpdisc_public.h"
#include "middleware/lpdisc/lpdisc_public.h"
#include "middleware/pan3/pan3_public.h"
#include "middleware/pot/pot_public.h"
#include "middleware/calres/calres_public.h"
#include "middleware/accom/accom_public.h"
#include "middleware/pwm/pwm_public.h"
#include "middleware/uart_rs422/uart_public.h"
#include "middleware/ovsp/ovsp_public.h"
#include "middleware/mram/mram_public.h"
#include "middleware/p0/p0_public.h"

#include "memory/lib_critical_service_section_def_data.h"
#include "memory/memory_address_public.h"
#include "main/update_durations_in_mram_and_shmem.h"
#include "main/rtc_sync_fpga.h"
#include "driver/adc_over_spi/adc_over_spi_public.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

#define FPGA_REG_RTC_SYNC_ADDR    (0x24020020)            /* FPGA register for rtc sync */
#ifdef INSTRUM_RSF_WITH_GPIO
#define GPIO_054                  ((uint8_t *)0xFFFC1336) /*ATP_TST_MPC_F         */
#endif /* INSTRUM_RSF_WITH_GPIO */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Location in MRAM where are stored the max execution times of the functions */
ts_fct_exec_time* const max_times = (ts_fct_exec_time *)PROFILING_DATA_START_ADDR;

/* Current channel */
boolean_t current_channel_is_a;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* GPIO manipulation */
#ifdef INSTRUM_RSF_WITH_GPIO
uint8_t * gpioPtr;
#endif /* INSTRUM_RSF_WITH_GPIO */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-SCHED-0010 */
/* Implements REQ_FADEX_OS_SRD-SCHED-0020 */
/* Implements REQ_FADEX_OS_SRD-SCHED-0030 */
/* Global real time function for OSS */
void oss_task(void)
{
   /* Times used to compute the elapsed time */
   int64_t start_time_global;
   int64_t current_time_previous;
   tu_accom_ch_bit_fault_word accom_word;

#ifdef INSTRUM_RSF_WITH_GPIO
   gpioPtr = GPIO_054;
   *gpioPtr = 1;
   *gpioPtr = 0;
   *gpioPtr = 1;
#endif /* INSTRUM_RSF_WITH_GPIO */

   /* Get the current time */
   LIBT_TIME_GET(&start_time_global);
   current_time_previous = start_time_global;

   /* Identify channel */
   accom_word = accom_ch_cbit();
   if(FALSE == accom_word.u_bit.s_ch_id)
   {
      current_channel_is_a = TRUE;
   }
   else
   {
      current_channel_is_a = FALSE;
   }

   /* Perform the watchdog CBIT, ARM and REFRESH */
   watchdog_periodic();

   /* Increment the RTC counter */
   rtc_count();

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_watchdog,
                                                              &max_times->s_watchdog,
                                                              current_time_previous);

   /* Call accomodation */
   accom_periodic();

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_accom,
                                                              &max_times->s_accom,
                                                              current_time_previous);

   /* Get IO Expanders GPIO value */
   pca9535e_read_all();

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_pca9535e_read,
                                                              &max_times->s_pca9535e_read,
                                                              current_time_previous);

  /* Capability : power_sup  */
   powersup_periodic(current_channel_is_a);

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_powersup,
                                                              &max_times->s_powersup,
                                                              current_time_previous);

   /* Perform HP discrete processing */
   hpdisc_periodic();

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_hpdisc,
                                                              &max_times->s_hpdisc,
                                                              current_time_previous);

   /* Perform LP discrete processing */
   lpdisc_periodic();

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_lpdisc,
                                                              &max_times->s_lpdisc,
                                                              current_time_previous);

   /* Update IO Expanders GPIOs */
   pca9535e_write_all();

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_pca9535e_write,
                                                              &max_times->s_pca9535e_write,
                                                              current_time_previous);


  /* Perform nfreq processing */
   nfreq_periodic(current_channel_is_a);

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_nfreq,
                                                              &max_times->s_nfreq,
                                                              current_time_previous);


   /* Perform tecu processing */
   tecu_periodic(current_channel_is_a);

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_tecu,
                                                              &max_times->s_tecu,
                                                              current_time_previous);

    /* Perform CAN processing */
   can_periodic();

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_can,
                                                              &max_times->s_can,
                                                              current_time_previous);

   /* Perform A429 processing */
   a429_periodic(current_channel_is_a);

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_a429,
                                                              &max_times->s_a429,
                                                              current_time_previous);

   /* Perform periodic discretes check */
   discrete_periodic();

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_discrete,
                                                              &max_times->s_discrete,
                                                              current_time_previous);

    /* tmot periodic function (CBIT) */
   tmot_periodic(current_channel_is_a);

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_tmot,
                                                              &max_times->s_tmot,
                                                              current_time_previous);
   /* smot periodic function (CBIT) */
   smot_periodic();

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_smot,
                                                              &max_times->s_smot,
                                                              current_time_previous);

   /* Retrieve acquisition results */
   adc_over_spi_retrieve_acquired_voltages();

#ifdef INSTRUM_RSF_WITH_GPIO
   *gpioPtr = 0;
#endif /* INSTRUM_RSF_WITH_GPIO */

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_adc_over_spi_stop,
                                                              &max_times->s_adc_over_spi_stop,
                                                              current_time_previous);

   /* Perform SG / SAI / P3 processing */
   sg_periodic();

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_sg,
                                                              &max_times->s_sg,
                                                              current_time_previous);

   /* Perform resolver processing */
   resolver_periodic(current_channel_is_a);

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_xr,
                                                              &max_times->s_xr,
                                                              current_time_previous);

   /* Perform lvdt processing */
   lvdt_periodic(current_channel_is_a);


   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_lvdt,
                                                              &max_times->s_lvdt,
                                                              current_time_previous);

   /* Perform T4 processing */
   t4_periodic(current_channel_is_a);

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_t4,
                                                              &max_times->s_t4,
                                                              current_time_previous);

   /* Perform vrt processing */
   vrt_periodic(current_channel_is_a);

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_vrt,
                                                              &max_times->s_vrt,
                                                              current_time_previous);

   /* Perform POT acquisitions */
   pot_periodic(current_channel_is_a);

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_pot,
                                                              &max_times->s_pot,
                                                              current_time_previous);

   /* Perform CALRES acquisitions */
   calres_periodic(current_channel_is_a);

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_calres,
                                                              &max_times->s_calres,
                                                              current_time_previous);

#ifdef INSTRUM_RSF_WITH_GPIO
   *gpioPtr = 1;
#endif /* INSTRUM_RSF_WITH_GPIO */

   /* ccdl periodic tx function */
   ccdl_periodic_tx(current_channel_is_a);

#ifdef INSTRUM_RSF_WITH_GPIO
   *gpioPtr = 0;
   *gpioPtr = 1;
   *gpioPtr = 0;
#endif /* INSTRUM_RSF_WITH_GPIO */

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_ccdl_tx,
                                                              &max_times->s_ccdl_tx,
                                                              current_time_previous);


   /* Perform PAN3 processing */
   pan3_periodic(current_channel_is_a);

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_pan3,
                                                              &max_times->s_pan3,
                                                              current_time_previous);

   /* Perform PWM processing */
   pwm_periodic(current_channel_is_a);

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_pwm,
                                                              &max_times->s_pwm,
                                                              current_time_previous);


   /* Perform ICDL */
   mid_icdl_mngt(current_channel_is_a);

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_icdl,
                                                              &max_times->s_icdl,
                                                              current_time_previous);

   /* Perform periodic UART treatment */
   uart_periodic();

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_uart,
                                                              &max_times->s_uart,
                                                              current_time_previous);

   /* Perform periodic OVSP reatment */
   ovsp_periodic(current_channel_is_a);

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_ovsp,
                                                              &max_times->s_ovsp,
                                                              current_time_previous);

   /* Perform MRAM management */
   mram_periodic(current_channel_is_a);

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_mram,
                                                              &max_times->s_mram,
                                                              current_time_previous);

   /* Acquire p0 */
   p0_periodic(current_channel_is_a);

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_p0,
                                                              &max_times->s_p0,
                                                              current_time_previous);


#ifdef INSTRUM_RSF_WITH_GPIO
   *gpioPtr = 1;
#endif /* INSTRUM_RSF_WITH_GPIO */

   /* Wait for CCDL Rx */
   {
      int64_t time_inst;
      LIBT_TIME_GET(&time_inst);
      while((time_inst - start_time_global) < 3200000)  /* 3240000 OK / 3241000 KO*/
      {
         LIBT_TIME_GET(&time_inst);
      }
   }

#ifdef INSTRUM_RSF_WITH_GPIO
   *gpioPtr = 0;
#endif /* INSTRUM_RSF_WITH_GPIO */

   /* ccdl periodic rx function */
   ccdl_periodic_rx(current_channel_is_a);

#ifdef INSTRUM_RSF_WITH_GPIO
   *gpioPtr = 1;
#endif /* INSTRUM_RSF_WITH_GPIO */

   /* Update duration measures */
   update_durations_in_mram_and_shmem(&shmem.s_times.s_ccdl_rx,
                                      &max_times->s_ccdl_rx,
                                      current_time_previous);

   /* Set "end of main 2ms RTC processings" into FPGA */
   {
      ts_rtc_sync_fpga_reg * rtc_sync_fpga_ptr = (ts_rtc_sync_fpga_reg *)FPGA_REG_RTC_SYNC_ADDR;

      rtc_sync_fpga_ptr->s_sync_cmd_reg.u_bit.s_raz_mf_activ = 1;
   }

   /* Update duration measures */
   update_durations_in_mram_and_shmem(&shmem.s_times.s_global,
                                      &max_times->s_global,
                                      start_time_global);
#ifdef INSTRUM_RSF_WITH_GPIO
   *gpioPtr = 0;
#endif /* INSTRUM_RSF_WITH_GPIO */

}

/* ---------- internal operations: ------------------------------------------ */
