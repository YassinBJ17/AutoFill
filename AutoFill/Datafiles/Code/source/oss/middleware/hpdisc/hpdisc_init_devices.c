/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/hpdisc/hpdisc_private.h"
#include "middleware/pca9535e/pca9535e_public.h"
#include "middleware/hpdisc/hpdisc_init_devices.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */
/* HP switches and status masks */
#define C_HP1_CMD    ((uint16_t)0x0004)
#define C_HP1_CMD_N  ((uint16_t)0xFBFF)
#define C_HP1_STATUS ((uint16_t)0x0080)

#define C_HP2_CMD    ((uint16_t)0x4000)
#define C_HP2_CMD_N  ((uint16_t)0xEFFF)
#define C_HP2_STATUS ((uint16_t)0x0080)

#define C_HP3_CMD    ((uint16_t)0x1000)
#define C_HP3_CMD_N  ((uint16_t)0xFBFF)
#define C_HP3_STATUS ((uint16_t)0x0020)

#define C_HP4_CMD_P0V  ((uint16_t)0x2000)
#define C_HP4_CMD_N    ((uint16_t)0xFEFF)

#define C_HP5_CMD    ((uint16_t)0x0400)
#define C_HP5_CMD_N  ((uint16_t)0xFEFF)
#define C_HP5_STATUS ((uint16_t)0x0008)

/* GPDO address */
#define  C_GPDO_203  0xFFFC13CB

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */
/* False status word for HP 4 */
uint8_t  v_hp4_gpio_status;

/* ---------- provided operation bodies: ------------------------------------ */

/* ---------- internal operations: ------------------------------------------ */
/* Fill devices structure array and init status */
void hpdisc_init_devices(ts_hpdisk_device *p_devices)
{
   uint8_t  *pv_gpio_addr;


   /* HP 1 */
   p_devices[e_hp_1].s_raw_swi_1.s_io_pointer  = &v_pca9535e_devices[e_device_42].s_io_state.u_word;
   p_devices[e_hp_1].s_raw_swi_1.s_io_mask     = C_HP1_CMD;
   p_devices[e_hp_1].s_raw_swi_1.s_err_pointer = &v_pca9535e_devices[e_device_42].s_status.u_word;
   p_devices[e_hp_1].s_raw_swi_2.s_io_pointer  = &v_pca9535e_devices[e_device_44].s_io_state.u_word;
   p_devices[e_hp_1].s_raw_swi_2.s_io_mask     = C_HP1_CMD_N;
   p_devices[e_hp_1].s_raw_swi_2.s_err_pointer = &v_pca9535e_devices[e_device_44].s_status.u_word;
   p_devices[e_hp_1].s_raw_status.s_io_pointer = &v_pca9535e_devices[e_device_44].s_io_state.u_word;
   p_devices[e_hp_1].s_raw_status.s_io_mask    = C_HP1_STATUS;

   v_pca9535e_devices[e_device_42].s_io_state.u_bit.s_io_12 = C_PCA9535E_IO_UNSET;
   v_pca9535e_devices[e_device_44].s_io_state.u_bit.s_io_02 = C_PCA9535E_IO_SET;
   p_devices[e_hp_1].s_state_call                           = C_HP_ALL_OPEN;

   /* HP 2 */
   p_devices[e_hp_2].s_raw_swi_1.s_io_pointer  = &v_pca9535e_devices[e_device_4A].s_io_state.u_word;
   p_devices[e_hp_2].s_raw_swi_1.s_io_mask     = C_HP2_CMD;
   p_devices[e_hp_2].s_raw_swi_1.s_err_pointer = &v_pca9535e_devices[e_device_4A].s_status.u_word;
   p_devices[e_hp_2].s_raw_swi_2.s_io_pointer  = &v_pca9535e_devices[e_device_4C].s_io_state.u_word;
   p_devices[e_hp_2].s_raw_swi_2.s_io_mask     = C_HP2_CMD_N;
   p_devices[e_hp_2].s_raw_swi_2.s_err_pointer = &v_pca9535e_devices[e_device_4C].s_status.u_word;
   p_devices[e_hp_2].s_raw_status.s_io_pointer = &v_pca9535e_devices[e_device_4C].s_io_state.u_word;
   p_devices[e_hp_2].s_raw_status.s_io_mask    = C_HP2_STATUS;

   v_pca9535e_devices[e_device_4A].s_io_state.u_bit.s_io_06 = C_PCA9535E_IO_UNSET;
   v_pca9535e_devices[e_device_4C].s_io_state.u_bit.s_io_04 = C_PCA9535E_IO_SET;
   p_devices[e_hp_2].s_state_call                           = C_HP_ALL_OPEN;

   /* HP 3 */
   p_devices[e_hp_3].s_raw_swi_1.s_io_pointer  = &v_pca9535e_devices[e_device_4A].s_io_state.u_word;
   p_devices[e_hp_3].s_raw_swi_1.s_io_mask     = C_HP3_CMD;
   p_devices[e_hp_3].s_raw_swi_1.s_err_pointer = &v_pca9535e_devices[e_device_4A].s_status.u_word;
   p_devices[e_hp_3].s_raw_swi_2.s_io_pointer  = &v_pca9535e_devices[e_device_4C].s_io_state.u_word;
   p_devices[e_hp_3].s_raw_swi_2.s_io_mask     = C_HP3_CMD_N;
   p_devices[e_hp_3].s_raw_swi_2.s_err_pointer = &v_pca9535e_devices[e_device_4C].s_status.u_word;
   p_devices[e_hp_3].s_raw_status.s_io_pointer = &v_pca9535e_devices[e_device_4C].s_io_state.u_word;
   p_devices[e_hp_3].s_raw_status.s_io_mask    = C_HP3_STATUS;

   v_pca9535e_devices[e_device_4A].s_io_state.u_bit.s_io_04 = C_PCA9535E_IO_UNSET;
   v_pca9535e_devices[e_device_4C].s_io_state.u_bit.s_io_02 = C_PCA9535E_IO_SET;
   p_devices[e_hp_3].s_state_call                           = C_HP_ALL_OPEN;

   /* HP 4 */
   p_devices[e_hp_4].s_raw_swi_1.s_io_pointer  = &v_pca9535e_devices[e_device_48].s_io_state.u_word;
   p_devices[e_hp_4].s_raw_swi_1.s_io_mask     = C_HP4_CMD_P0V;
   p_devices[e_hp_4].s_raw_swi_1.s_err_pointer = &v_pca9535e_devices[e_device_48].s_status.u_word;
   p_devices[e_hp_4].s_raw_swi_2.s_io_pointer  = (uint16_t *)C_GPDO_203;
   p_devices[e_hp_4].s_raw_swi_2.s_io_mask     = C_HP4_CMD_N;
   p_devices[e_hp_4].s_raw_swi_2.s_err_pointer = &v_hp4_gpio_status;
   p_devices[e_hp_4].s_raw_status.s_io_pointer = (uint16_t *)NULL;
   p_devices[e_hp_4].s_raw_status.s_io_mask    = (uint16_t)0;

   v_hp4_gpio_status                                        = (uint8_t)0;
   v_pca9535e_devices[e_device_48].s_io_state.u_bit.s_io_05 = C_PCA9535E_IO_UNSET;
   pv_gpio_addr                                             = (uint8_t *)C_GPDO_203;
   *pv_gpio_addr                                            = (uint8_t)0x01;
   p_devices[e_hp_4].s_state_call                           = C_HP_ALL_OPEN;

   /* HP 5 */
   p_devices[e_hp_5].s_raw_swi_1.s_io_pointer  = &v_pca9535e_devices[e_device_4A].s_io_state.u_word;
   p_devices[e_hp_5].s_raw_swi_1.s_io_mask     = C_HP5_CMD;
   p_devices[e_hp_5].s_raw_swi_1.s_err_pointer = &v_pca9535e_devices[e_device_4A].s_status.u_word;
   p_devices[e_hp_5].s_raw_swi_2.s_io_pointer  = &v_pca9535e_devices[e_device_4C].s_io_state.u_word;
   p_devices[e_hp_5].s_raw_swi_2.s_io_mask     = C_HP5_CMD_N;
   p_devices[e_hp_5].s_raw_swi_2.s_err_pointer = &v_pca9535e_devices[e_device_4C].s_status.u_word;
   p_devices[e_hp_5].s_raw_status.s_io_pointer = &v_pca9535e_devices[e_device_4C].s_io_state.u_word;
   p_devices[e_hp_5].s_raw_status.s_io_mask    = C_HP5_STATUS;

   v_pca9535e_devices[e_device_4A].s_io_state.u_bit.s_io_02 = C_PCA9535E_IO_UNSET;
   v_pca9535e_devices[e_device_4C].s_io_state.u_bit.s_io_00 = C_PCA9535E_IO_SET;
   p_devices[e_hp_5].s_state_call                           = C_HP_ALL_OPEN;
}
