/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "type/common_type.h"
#include "libtools/memory/LIB_MEM_public.h"
#include "memory/lib_critical_service_section_def_data.h"
#include "middleware/lpdisc/lpdisc_public.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */
#include "middleware/lpdisc/lpdisc_private.h"
#include "middleware/lpdisc/lpdisc_init_devices.h"

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */
/* Array holding information of all LP devices */
ts_lpdisk_device v_lp_devices[e_LpDeviceMax];

/* ---------- provided operation bodies: ------------------------------------ */
/* REQ_FADEX_OS_SRD-LPDISC-0010 */
/* Initialization of LP switches */
void lpdisc_init(void)
{
   te_lpdisc_device_index  v_lp_index;


   /*=====================*/
   /* Devices array setup */
   LIB_MEM_SET((void *)v_lp_devices,
               (int8_t)0,
               (uint32_t)sizeof (v_lp_devices));

   lpdisc_init_devices(v_lp_devices);

   /*=====================*/
   /* Shared memory reset */
   LIB_MEM_SET((void *)&shmem.s_lp_w,
               (int8_t)0,
               (uint32_t)sizeof (ts_lp_w));

   for (v_lp_index = (te_lpdisc_device_index)0; v_lp_index < e_LpDeviceMax; v_lp_index++)
      shmem.s_lp_w.s_lp_command[v_lp_index] = C_LP_CMD_NONE;
}

/* ---------- internal operations: ------------------------------------------ */
