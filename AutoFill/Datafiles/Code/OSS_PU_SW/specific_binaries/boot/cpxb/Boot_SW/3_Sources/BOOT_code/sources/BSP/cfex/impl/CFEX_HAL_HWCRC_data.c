/* --------------------------------------------------------------------------
 *                           Sagem Defense Securite
 *                               SAFRAN Group
 * --------------------------------------------------------------------------
 * PROJECT : CHRONOS_MOCKUP
 * CSU name :
 * %name: CFEX_HAL_HWCRC_data.c %
 * %full_name: fadex#1/csrc/CFEX_HAL_HWCRC_data.c/1 %
 * DESCRIPTION : short description of the operations of the .c file
 *
 * Creation information:
 *   Created by: F576176
 *   Date : Fri Mar 15 17:26:30 CET 2019
 *
 * Modification information:
 *   %derived_by: F605763 %
 *   %date_created:Thu May 12 18:17:59 CEST 2022 %
 * --------------------------------------------------------------------------
 * SAGEM Defense Securite document. Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

#include "HWCRC_CFEX_public.h"
#include "HWCRC_HAL_public.h"

/* ---------- include required interface: ----------------------------------- */
/* LPOS Common Interface */
/*  */
#include "CFEX_HAL_private.h"

/* LPOS Public Interface */
/* none */

/* LPOS Private Interface */
/* none */

/* ---------- internal define constants: ------------------------------------ */
/*  */


/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
uint32_t const c_HWCRC_CFEX_tab_SIZE = e_CFEX_HWCRC_CONF_NB;


/* */
/* HWCRC configuration table */
ts_HWCRC_CFEX_ELT const c_HWCRC_CFEX_CONFIGURATION_tab[e_CFEX_HWCRC_CONF_NB] =
{
   /* HWCRC 0 */
   {
	  e_HWCRC_CFEX_MODULE_1,              /* HWCRC module number       */
	  e_HWCRC_CFEX_CRC32_POLY,            /* Slave-Master mode     */
	  e_HWCRC_CFEX_TRANSFER_MODE_DMA,     /* Transfer mode         */
	  e_CFEX_DMA_CONF_HWCRC              /* DMA line           */
   }
   /* HWCRC Module ... */
};

/* ---------- internal data: ------------------------------------------------ */
/* HWCRC descriptor declaration */
ts_HWCRC_CONFIG_DESC HWCRC_CFEX_descriptor_tab[e_CFEX_HWCRC_CONF_NB];

/* ---------- provided operation bodies: ------------------------------------ */
/* none */

/* ---------- internal operation bodies: ------------------------------------ */
/* none */
