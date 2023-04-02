/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : resolver_init function which allows resolver acquisition
 *               initialization.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/resolver/resolver_public.h"
#include "middleware/resolver/resolver_private.h"
#include "conf/oss_conf_public.h"
#include "memory/memory_address_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "libtools/time/LIB_TIME_public.h"
#include "driver/spi/SPI_HAL_public.h"

/* ---------- internal define constants: ------------------------------------ */
/* GPIOs defs */
#define GPIO_003 ((uint8_t *)0xFFFC1303) /*SELECT XRB CALRES TX1 */
#define GPIO_035 ((uint8_t *)0xFFFC1323) /*SELECT XRB CALRES TX2 */
#define GPIO_225 ((uint8_t *)0xFFFC13E1) /*PBIT_XR_XRB_EXC_OPEN_N*/

/* Sinus generator frequency settings */
#define SIN_GEN_2500HZ 0x51CD0000

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */
/* GPIO manipulation */
uint8_t * gpioPtr_resolver;

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-RESOLVER-xxxx */
void resolver_init(const boolean_t channel_is_a)
{
   ts_oss_conf_table * pt_oss_conf = (ts_oss_conf_table *)OSS_CONF_START_ADDR;

    /* Set GPIOs for XRB and not CALRES : TODO */
   gpioPtr_resolver = GPIO_003;
   *gpioPtr_resolver = 0x1;
   gpioPtr_resolver = GPIO_035;
   *gpioPtr_resolver = 0x1;
   /* Set PBIT GPIO ?? TODO */
   gpioPtr_resolver = GPIO_225;      /* TODO ? SRD not mentioning it ? PBIT specific GPIO ?*/
   *gpioPtr_resolver = 0x1;

   /* Configure sinus generator on SPI if chA or chB with XRB enabled */
   if(channel_is_a
      ||
      (
        (FALSE == channel_is_a)
        &&
        (XRB_IS_ENABLED == pt_oss_conf->s_xrb_calres_select)
      )
   )
   {
      /* Set frequency for XR */
      /* TODO : use 16 bits data and not 32 bits*/
      CMN_SYSTEM_SIZE_t ws;

      uint32_t pushr = 0x01000000;
      SPI_FIFO_WRITE_DATA (3,
                           &pushr,
                           2,
                           &ws);

      LIBT_TIME_Wait(10* 20 * 1000);

      pushr = SIN_GEN_2500HZ;
      SPI_FIFO_WRITE_DATA (3,
                           &pushr,
                           2,
                           &ws);
      LIBT_TIME_Wait(10* 20 * 1000);

      pushr = 0x11000000;
      SPI_FIFO_WRITE_DATA (3,
                           &pushr,
                           2,
                           &ws);
      LIBT_TIME_Wait(10* 20 * 1000);

      pushr = 0x40030000;
      SPI_FIFO_WRITE_DATA (3,
                           &pushr,
                           2,
                           &ws);
      LIBT_TIME_Wait(10* 20 * 1000);

      pushr = 0xC0000000;
      SPI_FIFO_WRITE_DATA (3,
                           &pushr,
                           2,
                           &ws);
      LIBT_TIME_Wait(10* 20 * 1000);

      pushr = 0x00000000;
      SPI_FIFO_WRITE_DATA (3,
                           &pushr,
                           2,
                           &ws);
      LIBT_TIME_Wait(10* 20 * 1000);
   }
   else
   {
      /* Set sin gen in reset */
      CMN_SYSTEM_SIZE_t ws;

      uint32_t pushr = 0x01000000;
      SPI_FIFO_WRITE_DATA (3,
                           &pushr,
                           2,
                           &ws);
   }

   /* Init public datas */
   xr_measure      = 0.0;
   xr_vsin_measure = 0.0;
   xr_vcos_measure = 0.0;
}

/* ---------- internal operations: ------------------------------------------ */
