#ifndef BOOT_CONF_PUBLIC_H
#define BOOT_CONF_PUBLIC_H

/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * -------------------------------------------------------------------------- */

/* ---------- include  ------------------------------------------------------ */
#include "CMN_TYPES_common.h"
#include "BOOT_MAIN_public.h"
#include "BOOT_XBAR_public.h"
#include "BOOT_PBRIDGE_public.h"
#include "BOOT_PINOUT_public.h"
#include "BOOT_GPIO_HAL_public.h"
#include "BOOT_GPIO_REG_common.h"

/* ---------- external define constants: ------------------------------------ */

#define CONF_ASTEKCONF_NB (3ul)

#define ACQUISITION_MAX_NUMBER                        3

/* Validity flags address */
#define CSS_PU_TASK_CONFIG_ADDR              (0x01200020)
#define DTL_REQUEST_ADDR                     (0x200046D0)

/* ---------- external types: ----------------------------------------------- */

typedef struct
{
   /* Table of the GPIO acquisitions */
   GPIO_PIN_VALUE_t s_gpio_value_tab[ACQUISITION_MAX_NUMBER];

   /* Indicates if the GPIO value is confirmed */
   te_CMN_FLAG_QUESTION s_is_GPIO_value_confirmed;
} ts_GPIO_acquisition_elt;

typedef struct
{
   /* Sampling index */
   uint32_t s_acquisition_index;

   /*  */
   ts_GPIO_acquisition_elt s_gpio_elt;

} ts_GPIO_acquisition;

/* Enumeration for operational OSS request */
typedef enum
{
    e_1_PERIODIC_TASK = 0xFADEC111,
    e_4_PERIODIC_TASK = 0x444FADEC
}
te_CSS_PU_TASK_CONFIG;

/* Enumeration for dataload request */
typedef enum
{
    e_DTL_REQUESTED     = 0xFADEC000,
    e_DTL_NOT_REQUESTED = 0x0
}
te_DTL_REQUEST;


/* ---------- external constants: ------------------------------------------- */

/* This table contains the different ASTERIOS configurations */
extern const ts_MAIN_ASTERIOS_RUNTIME_CONF c_CONF_ASTEK_tab[];

/* External Source minor frame period in units of 250us. */
extern const uint32_t c_CONF_RTC_PERIOD;

/* External Source timeout in units of 10us. */
extern const uint32_t c_CONF_RTC_TIMEOUT;
/* Definition of the configuration for each mode (dataloader or run mode)  */
extern const ts_MAIN_MODE_ELT c_CONF_MODES[e_MODE_NB];


/* XBAR registers configuration */
extern const ts_XBAR_CONF c_CONF_XBAR;

/* PBRIDGE A registers configuration */
extern const ts_PBRIDGE_CONF c_CONF_PBRIDGEA;
/* */
/* PBRIDGE B registers configuration */
extern const ts_PBRIDGE_CONF c_CONF_PBRIDGEB;
/* */

/* PINOUT PAD IO registers configuration */
extern const ts_PAD_IO_CFG c_conf_pad_io_st;
/* */
/* PINOUT PAD MUX registers configuration */
extern const ts_PAD_MUX_CFG c_conf_pad_mux_st;

/*---------- external datas: ------------------------------------------- */
/* Variable holding acquisitions informations */
extern ts_GPIO_acquisition V_CONF_MDIN_Acquisition;
/* Acquisition start time (starts after xBIST execution and reboot) */
extern CMN_SYSTEM_TIME_t V_acquisition_start_time;

extern uint32_t V_BOOT_UOD_ACTIVATION_FLAG_ADDR;
extern uint32_t V_BOOT_OPERATIONAL_4_PERIODIC_TASK;
extern uint32_t V_BOOT_OPERATIONAL_1_PERIODIC_TASK;

/* ---------- provided operations: ------------------------------------------- */
extern uint32_t BOOT_CONF_MODE_SELECT (void);
extern void BOOT_CONF_INIT_ACQUISITION (void);
extern void BOOT_CONF_READ_DISCRETES(void);
extern void BOOT_CONF_END_ACQUISITION(void);

#endif /* BOOT_CTRL_PUBLIC_H */
