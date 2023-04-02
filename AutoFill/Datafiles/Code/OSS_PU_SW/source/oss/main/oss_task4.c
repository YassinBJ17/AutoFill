/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : C function containing all the OSS process
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "main/oss_task_public.h"
#include "libtools/time/LIB_TIME_public.h"
#include "main/oss_task_public.h"
#include "middleware/rtc/rtc_public.h"

#include "middleware/logbook/logbook_public.h"

#include "memory/lib_critical_service_section_def_data.h"
#include "memory/memory_address_public.h"
#include "main/update_durations_in_mram_and_shmem.h"
#include "driver/adc_over_spi/adc_over_spi_public.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

#ifdef INSTRUM_RSF_WITH_GPIO
extern uint8_t * gpioPtr;
#endif /* INSTRUM_RSF_WITH_GPIO */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-SCHED-0010 */
/* Implements REQ_FADEX_OS_SRD-SCHED-0020 */
/* Implements REQ_FADEX_OS_SRD-SCHED-0030 */
/* Global real time function for OSS */

void oss_task4(void)
{
   /* Times used to compute the elapsed time */
   int64_t current_time_previous;

   /* Aim 7.6 ms*/
   LIBT_TIME_Wait(500000);

#ifdef INSTRUM_RSF_WITH_GPIO
   *gpioPtr = 1;
#endif /* INSTRUM_RSF_WITH_GPIO */

   /* Trigger ADC over SPI acquisition */
   adc_over_spi_program_voltages_acquisitions();

   /* Get the current time */
   LIBT_TIME_GET(&current_time_previous);

   /* Create trigger logs */
   logbook_periodic(current_channel_is_a);

   /* Update duration measures */
   current_time_previous = update_durations_in_mram_and_shmem(&shmem.s_times.s_logbook,
                                                              &max_times->s_logbook,
                                                              current_time_previous);
#ifdef INSTRUM_RSF_WITH_GPIO
   *gpioPtr = 0;
#endif /* INSTRUM_RSF_WITH_GPIO */
}

/* ---------- internal operations: ------------------------------------------ */
