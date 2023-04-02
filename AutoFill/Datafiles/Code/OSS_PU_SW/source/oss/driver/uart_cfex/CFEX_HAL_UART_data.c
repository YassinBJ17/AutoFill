/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : short description of the operations of the .c file
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/uart/UART_CFEX_public.h"
#include "driver/dma_cfex/CFEX_HAL_DMA_public.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */
#define  CFEX_UART_CONF_NB 1

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */
/* >RELAX<SYNCHRONe_C_Code_8.17>: this is used in PSYC code.  */
/* >RELAX<SYNCHRONe_C_Code_8.12> : Test usage deviation.  */
/* >RELAX<SYNCHRONe_C_Code_10.2>: Code for Test.  */
/* >RELAX<SYNCHRONe_C_Code_10.7>: e_BOOT_CFEX_UART_LINE_NB can be coded in unsigned 32 bits. */

const uint32_t FDX_c_UART_CFEX_tab_SIZE =  (uint32_t) CFEX_UART_CONF_NB ;

ts_UART_CFEX_ELT FDX_c_UART_CFEX_CONFIGURATION_tab[CFEX_UART_CONF_NB] ;

/* ---------- internal data: ------------------------------------------------ */
/* SPI descriptor declaration */
ts_UART_CONFIG_DESC FDX_UART_CFEX_descriptor_tab[CFEX_UART_CONF_NB] ;


/* ---------- provided operation bodies: ------------------------------------ */

/* ---------- internal operation bodies: ------------------------------------ */
