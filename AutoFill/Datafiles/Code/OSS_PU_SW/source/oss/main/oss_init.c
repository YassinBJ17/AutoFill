/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Definition of the global initialization function for OSS
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "main/oss_task_public.h"
#include "libtools/time/LIB_TIME_public.h"
#include "middleware/rtc/rtc_public.h"
#include "middleware/accom/accom_public.h"
#include "middleware/watchdog/watchdog_public.h"
#include "middleware/reset/reset_public.h"
#include "cartridge/cartridge_public.h"
#include "middleware/mram/mram_public.h"
#include "middleware/logbook/logbook_public.h"

#include "middleware/resolver/resolver_public.h"
#include "middleware/lvdt/lvdt_public.h"
#include "middleware/sg/sg_public.h"
#include "middleware/tmot/tmot_public.h"
#include "middleware/smot/smot_public.h"
#include "middleware/powersup/powersup_public.h"
#include "middleware/can/can_public.h"
#include "middleware/nfreq/nfreq_public.h"
#include "middleware/a429/a429_public.h"
#include "middleware/t4/t4_public.h"
#include "middleware/ovsp/ovsp_public.h"
#include "middleware/tecu/tecu_public.h"
#include "middleware/vrt/vrt_public.h"
#include "middleware/discrete/discrete_public.h"
#include "middleware/ccdl/ccdl_public.h"
#include "middleware/icdl/MID_ICDL_public.h"
#include "middleware/pca9535e/pca9535e_public.h"
#include "middleware/hpdisc/hpdisc_public.h"
#include "middleware/lpdisc/lpdisc_public.h"
#include "middleware/pot/pot_public.h"
#include "middleware/calres/calres_public.h"
#include "middleware/accom/accom_public.h"
#include "middleware/pwm/pwm_public.h"
#include "middleware/uart_rs422/uart_public.h"
#include "middleware/p0/p0_public.h"

#include "memory/oss_section_def_public.h"
#include "middleware/uod_bypass/uod_bypass_public.h"
#include "driver/adc/ADC_HAL_public.h"
#include "driver/spi/SPI_HAL_public.h"
#include "driver/dma/DMA_HAL_public.h"
#include "driver/adc_over_spi/adc_over_spi_public.h"


/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-SCHED-0010 */
/* Implements REQ_FADEX_OS_SRD-SCHED-0020 */
/* Implements REQ_FADEX_OS_SRD-SCHED-0030 */
/* Global initialization function for OSS */
void oss_init(void)
{
   tu_accom_ch_bit_fault_word accom_word;
   boolean_t current_channel_is_a;

   /* Force ASTERIOS to consider the file in which this variable is defined */
   make_asterios_identify_this_file_4 = (uint32_t)0;

   /* Identify channel */
   accom_word = accom_ch_init();
   if(FALSE == accom_word.u_bit.s_ch_id)
   {
      current_channel_is_a = TRUE;
   }
   else
   {
      current_channel_is_a = FALSE;
   }

   /* Initialize the reset in the FPGA */
   reset_init();


   /* Initialize the cartridge in the memory */
   cartridge_init();

   /* Init UOD bypass */
   initialize_uod_bypass();

   /* Initialize the PIT */
   LIBT_TIME_INIT();

   /* Initialize the RTC counter */
   rtc_init();

   /* Initialize the wachdog function */
   watchdog_init();

   /* Initialize mram and the logbooks aftwerwards */
   mram_init();

   /* Initialize logbook when mram is initialized */
   logbook_init();

   /* -------------------------- */

   /* Initialize the internal ADC */
   ADC_INIT();

   /* DMA init */
   FDX_DMA_INIT();

   /* SPI initialization */
   SPI_INIT();

   /* ADC AD7327  initialization */
   adc_over_spi_init_ad7327();

   /* ADC over SPI initialization */
   adc_over_spi_init_acquisitions(current_channel_is_a);

   /* IO Expanders initialization */
   pca9535e_init_all();

   /* -------------------------- */

   /* can ovsp */
   ovsp_init_send();

   /* Strain gauge initialization */
   sg_init(current_channel_is_a);

   /* Torque motor initilization */
   tmot_init();

   /* Stepper motor initilization */
   smot_init();

   /* Power-supply initilization */
   powersup_init(current_channel_is_a);

   /* Resolver initialization */
   resolver_init(current_channel_is_a);

   /* LVDT initialization */
   lvdt_init(current_channel_is_a);

   /* CAN management initialization */
   can_init();

   /* nfreq initialization */
   nfreq_init();

   /* T4 initialization */
   t4_init();

   /* TECU initialization */
   tecu_init();

   /* VRT initialization */
   vrt_init(current_channel_is_a);

   /* A429 initialization */
   a429_init(current_channel_is_a);

   /* Perform initialization for discretes signal */
   discrete_init();

   /* Potentiometers initialization */
   pot_init(current_channel_is_a);

   /* Calres Initialization */
   calres_init(current_channel_is_a);

   /* CCDL initialization */
   ccdl_init();

   /* ICDL init */
   mid_icdl_init();

   /* HP discrete initialization */
   hpdisc_init();

   /* LP discrete initialization */
   lpdisc_init();

   /* PWM initialization */
   pwm_init(current_channel_is_a);

   /* Update all IO Expanders GPIOs */
   pca9535e_write_all();

   /* uart init */
   uart_init(current_channel_is_a);

   /* can ovsp init read */
   ovsp_init_read();

   /* p0 sensor */
   p0_init(current_channel_is_a);

   /* PBIT non fatal logs */
   logbook_pbit_logs();

   /* Program first acquisition */
   adc_over_spi_program_voltages_acquisitions();

   /* Retrieve values for 1st RTC */
   /* Note : XR samples will be slightly older than 2ms @ CSS start ...*/
   /*        At the end of the function below, XR samples will be ~300us */
   /*        old as postprocessings samples will take ~300us in this function. */
   /*        Then 2ms will be spent in OS RTC @ 2ms => ~2.3~2.4ms old samples*/
   /*        TODO : Improve age of samples by reducing at least 400 us */
   adc_over_spi_retrieve_acquired_voltages();

   return;
}

/* ---------- internal operations: ------------------------------------------ */
