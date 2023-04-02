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
#include "middleware/hpdisc/hpdisc_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/hpdisc/hpdisc_private.h"
#include "middleware/hpdisc/hpdisc_init_devices.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */
/* Array holding information of all HP devices */
ts_hpdisk_device v_hp_devices[e_HpDeviceMax];

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-HPDISC-0010 */
/* Initialization of HP switches */
void hpdisc_init(void)
{
   te_hpdisc_device_index  v_hp_index;


   /*=====================*/
   /* Devices array setup */
   LIB_MEM_SET((void *)v_hp_devices,
               (int8_t)0,
               (uint32_t)sizeof (v_hp_devices));

   hpdisc_init_devices(v_hp_devices);

   /*=====================*/
   /* Shared memory reset */
   LIB_MEM_SET((void *)&shmem.s_hp_w,
               (int8_t)0,
               (uint32_t)sizeof (ts_hp_w));

   for (v_hp_index = (te_hpdisc_device_index)0; v_hp_index < e_HpDeviceMax; v_hp_index++)
      shmem.s_hp_w.s_hp_command[v_hp_index] = C_HP_CMD_NONE;
}

/* ---------- internal operations: ------------------------------------------ */
