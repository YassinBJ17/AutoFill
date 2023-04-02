/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : GPIO Configuration Table
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_GPIO_CFEX_public.h"
#include "BOOT_GPIO_HAL_public.h"

/* ---------- include required interface: ----------------------------------- */
/* none */

/* ---------- internal define constants: ------------------------------------ */
/* none */

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
/* */
const uint32_t c_GPIO_CFEX_tab_SIZE = GPIO_NB;

/* GPIO configuration table */
const ts_GPIO_CFEX_ELT c_GPIO_CFEX_CONFIGURATION_tab[ GPIO_NB ] =
{
    /* 0 - Gpio DINSHOP */
   {
      e_GPIO_PIN_RW_ID_109,      /* gpio port */
      e_GPIO_CFEX_DIR_INPUT,     /* gpio direction */
      e_GPIO_CFEX_ACCESS_PIN,    /* gpio access */
      0,                         /* reset value */
      e_GPIO_CFEX_MASK_UNUSED,   /* mask enable */
      0                          /* mask value */
   }
   ,
   /* 1 - Gpio DINOLL */
   {
	  e_GPIO_PIN_RW_ID_110,      /* gpio port */
      e_GPIO_CFEX_DIR_INPUT,     /* gpio direction */
      e_GPIO_CFEX_ACCESS_PIN,    /* gpio access */
      0,                         /* reset value */
      e_GPIO_CFEX_MASK_UNUSED,   /* mask enable */
      0                          /* mask value */
   }
   ,
   /* 2 - Gpio DINTMODE  */
   {
	  e_GPIO_PIN_RW_ID_111,      /* gpio pin */
      e_GPIO_CFEX_DIR_INPUT,     /* gpio direction */
      e_GPIO_CFEX_ACCESS_PIN,    /* gpio access */
      0,                         /* reset value */
      e_GPIO_CFEX_MASK_UNUSED,   /* mask enable */
      0                          /* mask value */
   }
   ,
   /* 3 - Gpio MDIN */
   {
	  e_GPIO_PIN_RO_ID_339,      /* gpio pin */
      e_GPIO_CFEX_DIR_INPUT,     /* gpio direction */
      e_GPIO_CFEX_ACCESS_PIN,    /* gpio access */
      0,                         /* reset value */
      e_GPIO_CFEX_MASK_UNUSED,   /* mask enable */
      0                          /* mask value */
   }
   ,
   /* 4 - Gpio MPC_LED4 */
   {
      e_GPIO_PIN_RW_ID_234,      /* gpio pin */
      e_GPIO_CFEX_DIR_OUTPUT,    /* gpio direction */
      e_GPIO_CFEX_ACCESS_PIN,    /* gpio access */
      1,                         /* reset value */
      e_GPIO_CFEX_MASK_UNUSED,   /* mask enable */
      0                          /* mask value */
   }
   ,
   /* 5 - FCN_PHY_RST_OUTMPC_N    PF[9] */
   {
      e_GPIO_PIN_RW_ID_89,      /* gpio pin */
      e_GPIO_CFEX_DIR_OUTPUT,    /* gpio direction */
      e_GPIO_CFEX_ACCESS_PIN,    /* gpio access */
      1,                         /* reset value */
      e_GPIO_CFEX_MASK_UNUSED,   /* mask enable */
      0                          /* mask value */
   }
   ,
   /* 6 - MU_LOCAL_SHUTDOWN_OUTMPC_N    PC[4] */
   {
      e_GPIO_PIN_RW_ID_36,      /* gpio pin */
      e_GPIO_CFEX_DIR_OUTPUT,    /* gpio direction */
      e_GPIO_CFEX_ACCESS_PIN,    /* gpio access */
      1,                         /* reset value */
      e_GPIO_CFEX_MASK_UNUSED,   /* mask enable */
      0                          /* mask value */
   }
};

/* ---------- internal data: ------------------------------------------------ */
/* GPIO descriptor declaration */
/* >RELAX<SYNCHRONe_C_Code_8.12> : the table GPIO_CFEX_descriptor_tab size is a integration value so the table */
/* are declared without a size. */
ts_GPIO_CONFIG_DESC GPIO_CFEX_descriptor_tab[GPIO_NB];

/* ---------- provided operation bodies: ------------------------------------ */
/* none */

/* ---------- internal operation bodies: ------------------------------------ */
/* none */
