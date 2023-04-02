/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : p0_init function which allows p0 initialization.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/p0/p0_public.h"
#include "middleware/p0/p0_private.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */
/* Address of MSCR register of DATA multiplexed input (GPIO 892) */
#define CPXD_DATA_MSCR_MUX_ADDR  ((uint32_t *)0xFFFC1030)
/* Configuration of MSCR register of DATA multiplexed input */
#define CPXD_DATA_MSCR_MUX_CONF  ((uint32_t)0x00000002)

/* Address of MSCR register of DATA input (GPIO 60) */
#define CPXD_DATA_MSCR_ADDR      ((uint32_t *)0xFFFC0330)
/* Configuration of MSCR register of DATA input */
#define CPXD_DATA_MSCR_CONF      ((uint32_t)0x00190002)

/* Address of MSCR register of CLOCK multiplexed input (GPIO 893) */
#define CPXD_CLOCK_MSCR_MUX_ADDR ((uint32_t *)0xFFFC1034)
/* Configuration of MSCR register of CLOCK multiplexed input */
#define CPXD_CLOCK_MSCR_MUX_CONF ((uint32_t)0x00000001)

/* Address of MSCR register of CLOCK input (GPIO 61) */
#define CPXD_CLOCK_MSCR_ADDR     ((uint32_t *)0xFFFC0334)
/* Configuration of MSCR register of CLOCK input */
#define CPXD_CLOCK_MSCR_CONF     ((uint32_t)0x00190002)

/* Address of MSCR register of CHIP SELECT multiplexed input (GPIO 894) */
#define CPXD_CS_MSCR_MUX_ADDR    ((uint32_t *)0xFFFC1038)
/* Configuration of MSCR register of CHIP SELECT multiplexed input */
#define CPXD_CS_MSCR_MUX_CONF    ((uint32_t)0x00000001)

/* Address of MSCR register of CHIP SELECT input (GPIO 65) */
#define CPXD_CS_MSCR_ADDR        ((uint32_t *)0xFFFC0344)
/* Configuration of MSCR register of CHIP SELECT input */
#define CPXD_CS_MSCR_CONF        ((uint32_t)0x00190002)

/* Address of MSCR register of Pulse output (GPIO 48) */
#define CPXD_PULSE_MSCR_ADDR     ((uint32_t *)0xFFFC0300)
/* Configuration of MSCR register of Pulse output */
#define CPXD_PULSE_MSCR_CONF     ((uint32_t)0x12000000)

/* Address of MSCR register of Reset command (GPIO 58) */
#define CPXD_RST_CMD_MSCR_ADDR   ((uint32_t *)0xFFFC0328)
/* Configuration of MSCR register of Reset command */
#define CPXD_RST_CMD_MSCR_CONF   ((uint32_t)0x12180000)

/* Address of GPIO for reset of P0 (GPIO 58) */
#define GPIO_RESET_ADDR          ((uint8_t *)0xFFFC133A)

/* Address of GPIO for CE read command (GPIO 48 : SOUT) */
#define GPIO_CE_READ_CMD_ADDR    ((uint8_t *)0xFFFC1330)

/* Address of SPI 4 status register */
#define SPI_4_SR_ADDR            ((uint32_t *)0xFFE7802C)

/* Address of SPI 4 FIFO pop register */
#define SPI_4_POPR_ADDR          ((uint32_t *)0xFFE78038)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Initialize data needed by P0 */
/* Implements REQ_FADEX_OS_SRD-P0-0010 */
void p0_init(const boolean_t p_is_channel_a)
{
   /* MSCR registers of DATA input */
   uint32_t * cpxd_data_mscr_mux;
   uint32_t * cpxd_data_mscr;

   /* MSCR registers of CLOCK input */
   uint32_t * cpxd_clock_mscr_mux;
   uint32_t * cpxd_clock_mscr;

   /* MSCR registers of CHIP SELECT input */
   uint32_t * cpxd_cs_mscr_mux;
   uint32_t * cpxd_cs_mscr;

   /* MSCR register of Pulse output */
   uint32_t * cpxd_pulse_mscr;

   /* MSCR register of Reset command */
   uint32_t * cpxd_rst_cmd_mscr;

   /* When the channel is B */
   if (FALSE == p_is_channel_a)
   {
      /* Initialize pointers on MsCR registers */
      cpxd_data_mscr_mux   = CPXD_DATA_MSCR_MUX_ADDR;
      cpxd_data_mscr       = CPXD_DATA_MSCR_ADDR;
      cpxd_clock_mscr_mux  = CPXD_CLOCK_MSCR_MUX_ADDR;
      cpxd_clock_mscr      = CPXD_CLOCK_MSCR_ADDR;
      cpxd_cs_mscr_mux     = CPXD_CS_MSCR_MUX_ADDR;
      cpxd_cs_mscr         = CPXD_CS_MSCR_ADDR;
      cpxd_pulse_mscr      = CPXD_PULSE_MSCR_ADDR;
      cpxd_rst_cmd_mscr    = CPXD_RST_CMD_MSCR_ADDR;

      /* Change configuration of GPIO for CPXD */
      *cpxd_data_mscr_mux   = CPXD_DATA_MSCR_MUX_CONF;
      *cpxd_data_mscr       = CPXD_DATA_MSCR_CONF;
      *cpxd_clock_mscr_mux  = CPXD_CLOCK_MSCR_MUX_CONF;
      *cpxd_clock_mscr      = CPXD_CLOCK_MSCR_CONF;
      *cpxd_cs_mscr_mux     = CPXD_CS_MSCR_MUX_CONF;
      *cpxd_cs_mscr         = CPXD_CS_MSCR_CONF;
      *cpxd_pulse_mscr      = CPXD_PULSE_MSCR_CONF;
      *cpxd_rst_cmd_mscr    = CPXD_RST_CMD_MSCR_CONF;

      /* Initialize pointer on GPIO for reset of P0 */
      gpio_reset_p0 = GPIO_RESET_ADDR;

      /* Activate P0 */
      *gpio_reset_p0 = (uint8_t)1;
      p0_rtc_since_activation = (uint32_t)0;

      /* Initialize pointer on GPIO for CE read command */
      gpio_ce_read_command = GPIO_CE_READ_CMD_ADDR;

      /* Indicate P0 has never been reset because it is faulty since the beginning of the mission */
      p0_has_been_reset = FALSE;

      /* Reset the fault counter */
      p0_fault_counter = (uint8_t)0;
   }
}

/* ---------- internal operations: ------------------------------------------ */
