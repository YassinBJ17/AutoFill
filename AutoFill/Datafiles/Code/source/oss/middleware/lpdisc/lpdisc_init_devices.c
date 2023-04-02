/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/lpdisc/lpdisc_private.h"
#include "middleware/pca9535e/pca9535e_public.h"
#include "middleware/lpdisc/lpdisc_init_devices.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */
/* LP switches and status masks */
#define C_LP01_CMD    ((uint16_t)0x0800)
#define C_LP01_STATUS ((uint16_t)0x0008)

#define C_LP02_CMD    ((uint16_t)0x0400)
#define C_LP02_STATUS ((uint16_t)0x0040)

#define C_LP03_CMD    ((uint16_t)0x0200)
#define C_LP03_STATUS ((uint16_t)0x0020)

#define C_LP04_CMD    ((uint16_t)0x0100)
#define C_LP04_STATUS ((uint16_t)0x0010)

#define C_LP05_CMD    ((uint16_t)0x8000)
#define C_LP05_CMD_N  ((uint16_t)0x7FFF)
#define C_LP05_STATUS ((uint16_t)0x0080)

#define C_LP06_CMD    ((uint16_t)0x4000)
#define C_LP06_CMD_N  ((uint16_t)0xBFFF)
#define C_LP06_STATUS ((uint16_t)0x0040)

#define C_LP07_CMD    ((uint16_t)0x2000)
#define C_LP07_CMD_N  ((uint16_t)0xDFFF)
#define C_LP07_STATUS ((uint16_t)0x0020)

#define C_LP08_CMD    ((uint16_t)0x1000)
#define C_LP08_CMD_N  ((uint16_t)0xEFFF)
#define C_LP08_STATUS ((uint16_t)0x0010)

#define C_LP09_CMD    ((uint16_t)0x0800)
#define C_LP09_STATUS ((uint16_t)0x0008)

#define C_LP10_CMD    ((uint16_t)0x4000)
#define C_LP10_CMD_N  ((uint16_t)0xFEFF)
#define C_LP10_STATUS ((uint16_t)0x0040)

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* ---------- internal operations: ------------------------------------------ */
/* Fill devices structure array and init status */
void lpdisc_init_devices(ts_lpdisk_device *p_devices)
{
   /* LP 01 */
   p_devices[e_lp_01].s_raw_swi_1.s_io_pointer  = &v_pca9535e_devices[e_device_42].s_io_state.u_word;
   p_devices[e_lp_01].s_raw_swi_1.s_io_mask     = C_LP01_CMD;
   p_devices[e_lp_01].s_raw_swi_1.s_err_pointer = &v_pca9535e_devices[e_device_42].s_status.u_word;
   p_devices[e_lp_01].s_raw_swi_2.s_io_pointer  = &v_pca9535e_devices[e_device_42].s_io_state.u_word;
   p_devices[e_lp_01].s_raw_swi_2.s_io_mask     = C_LP01_CMD;
   p_devices[e_lp_01].s_raw_swi_2.s_err_pointer = &v_pca9535e_devices[e_device_42].s_status.u_word;
   p_devices[e_lp_01].s_raw_status.s_io_pointer = &v_pca9535e_devices[e_device_44].s_io_state.u_word;
   p_devices[e_lp_01].s_raw_status.s_io_mask    = C_LP01_STATUS;

   v_pca9535e_devices[e_device_42].s_io_state.u_bit.s_io_03 = C_PCA9535E_IO_UNSET;
   p_devices[e_lp_01].s_state_call                          = C_LP_ALL_OPEN;

   /* LP 02 */
   p_devices[e_lp_02].s_raw_swi_1.s_io_pointer  = &v_pca9535e_devices[e_device_42].s_io_state.u_word;
   p_devices[e_lp_02].s_raw_swi_1.s_io_mask     = C_LP02_CMD;
   p_devices[e_lp_02].s_raw_swi_1.s_err_pointer = &v_pca9535e_devices[e_device_42].s_status.u_word;
   p_devices[e_lp_02].s_raw_swi_2.s_io_pointer  = &v_pca9535e_devices[e_device_42].s_io_state.u_word;
   p_devices[e_lp_02].s_raw_swi_2.s_io_mask     = C_LP02_CMD;
   p_devices[e_lp_02].s_raw_swi_2.s_err_pointer = &v_pca9535e_devices[e_device_42].s_status.u_word;
   p_devices[e_lp_02].s_raw_status.s_io_pointer = &v_pca9535e_devices[e_device_44].s_io_state.u_word;
   p_devices[e_lp_02].s_raw_status.s_io_mask    = C_LP02_STATUS;

   v_pca9535e_devices[e_device_42].s_io_state.u_bit.s_io_02 = C_PCA9535E_IO_UNSET;
   p_devices[e_lp_02].s_state_call                          = C_LP_ALL_OPEN;

   /* LP 03 */
   p_devices[e_lp_03].s_raw_swi_1.s_io_pointer  = &v_pca9535e_devices[e_device_42].s_io_state.u_word;
   p_devices[e_lp_03].s_raw_swi_1.s_io_mask     = C_LP03_CMD;
   p_devices[e_lp_03].s_raw_swi_1.s_err_pointer = &v_pca9535e_devices[e_device_42].s_status.u_word;
   p_devices[e_lp_03].s_raw_swi_2.s_io_pointer  = &v_pca9535e_devices[e_device_42].s_io_state.u_word;
   p_devices[e_lp_03].s_raw_swi_2.s_io_mask     = C_LP03_CMD;
   p_devices[e_lp_03].s_raw_swi_2.s_err_pointer = &v_pca9535e_devices[e_device_42].s_status.u_word;
   p_devices[e_lp_03].s_raw_status.s_io_pointer = &v_pca9535e_devices[e_device_44].s_io_state.u_word;
   p_devices[e_lp_03].s_raw_status.s_io_mask    = C_LP03_STATUS;

   v_pca9535e_devices[e_device_42].s_io_state.u_bit.s_io_01 = C_PCA9535E_IO_UNSET;
   p_devices[e_lp_03].s_state_call                          = C_LP_ALL_OPEN;

   /* LP 04 */
   p_devices[e_lp_04].s_raw_swi_1.s_io_pointer  = &v_pca9535e_devices[e_device_42].s_io_state.u_word;
   p_devices[e_lp_04].s_raw_swi_1.s_io_mask     = C_LP04_CMD;
   p_devices[e_lp_04].s_raw_swi_1.s_err_pointer = &v_pca9535e_devices[e_device_42].s_status.u_word;
   p_devices[e_lp_04].s_raw_swi_2.s_io_pointer  = &v_pca9535e_devices[e_device_42].s_io_state.u_word;
   p_devices[e_lp_04].s_raw_swi_2.s_io_mask     = C_LP04_CMD;
   p_devices[e_lp_04].s_raw_swi_2.s_err_pointer = &v_pca9535e_devices[e_device_42].s_status.u_word;
   p_devices[e_lp_04].s_raw_status.s_io_pointer = &v_pca9535e_devices[e_device_44].s_io_state.u_word;
   p_devices[e_lp_04].s_raw_status.s_io_mask    = C_LP04_STATUS;

   v_pca9535e_devices[e_device_42].s_io_state.u_bit.s_io_00 = C_PCA9535E_IO_UNSET;
   p_devices[e_lp_04].s_state_call                          = C_LP_ALL_OPEN;

   /* LP 05 */
   p_devices[e_lp_05].s_raw_swi_1.s_io_pointer  = &v_pca9535e_devices[e_device_44].s_io_state.u_word;
   p_devices[e_lp_05].s_raw_swi_1.s_io_mask     = C_LP05_CMD;
   p_devices[e_lp_05].s_raw_swi_1.s_err_pointer = &v_pca9535e_devices[e_device_44].s_status.u_word;
   p_devices[e_lp_05].s_raw_swi_2.s_io_pointer  = &v_pca9535e_devices[e_device_42].s_io_state.u_word;
   p_devices[e_lp_05].s_raw_swi_2.s_io_mask     = C_LP05_CMD_N;
   p_devices[e_lp_05].s_raw_swi_2.s_err_pointer = &v_pca9535e_devices[e_device_42].s_status.u_word;
   p_devices[e_lp_05].s_raw_status.s_io_pointer = &v_pca9535e_devices[e_device_42].s_io_state.u_word;
   p_devices[e_lp_05].s_raw_status.s_io_mask    = C_LP05_STATUS;

   v_pca9535e_devices[e_device_44].s_io_state.u_bit.s_io_07 = C_PCA9535E_IO_UNSET;
   v_pca9535e_devices[e_device_42].s_io_state.u_bit.s_io_07 = C_PCA9535E_IO_SET;
   p_devices[e_lp_05].s_state_call                          = C_LP_ALL_OPEN;

   /* LP 06 */
   p_devices[e_lp_06].s_raw_swi_1.s_io_pointer  = &v_pca9535e_devices[e_device_44].s_io_state.u_word;
   p_devices[e_lp_06].s_raw_swi_1.s_io_mask     = C_LP06_CMD;
   p_devices[e_lp_06].s_raw_swi_1.s_err_pointer = &v_pca9535e_devices[e_device_44].s_status.u_word;
   p_devices[e_lp_06].s_raw_swi_2.s_io_pointer  = &v_pca9535e_devices[e_device_42].s_io_state.u_word;
   p_devices[e_lp_06].s_raw_swi_2.s_io_mask     = C_LP06_CMD_N;
   p_devices[e_lp_06].s_raw_swi_2.s_err_pointer = &v_pca9535e_devices[e_device_42].s_status.u_word;
   p_devices[e_lp_06].s_raw_status.s_io_pointer = &v_pca9535e_devices[e_device_42].s_io_state.u_word;
   p_devices[e_lp_06].s_raw_status.s_io_mask    = C_LP06_STATUS;

   v_pca9535e_devices[e_device_44].s_io_state.u_bit.s_io_06 = C_PCA9535E_IO_UNSET;
   v_pca9535e_devices[e_device_42].s_io_state.u_bit.s_io_06 = C_PCA9535E_IO_SET;
   p_devices[e_lp_06].s_state_call                          = C_LP_ALL_OPEN;

   /* LP 07 */
   p_devices[e_lp_07].s_raw_swi_1.s_io_pointer  = &v_pca9535e_devices[e_device_44].s_io_state.u_word;
   p_devices[e_lp_07].s_raw_swi_1.s_io_mask     = C_LP07_CMD;
   p_devices[e_lp_07].s_raw_swi_1.s_err_pointer = &v_pca9535e_devices[e_device_44].s_status.u_word;
   p_devices[e_lp_07].s_raw_swi_2.s_io_pointer  = &v_pca9535e_devices[e_device_42].s_io_state.u_word;
   p_devices[e_lp_07].s_raw_swi_2.s_io_mask     = C_LP07_CMD_N;
   p_devices[e_lp_07].s_raw_swi_2.s_err_pointer = &v_pca9535e_devices[e_device_42].s_status.u_word;
   p_devices[e_lp_07].s_raw_status.s_io_pointer = &v_pca9535e_devices[e_device_42].s_io_state.u_word;
   p_devices[e_lp_07].s_raw_status.s_io_mask    = C_LP07_STATUS;

   v_pca9535e_devices[e_device_44].s_io_state.u_bit.s_io_05 = C_PCA9535E_IO_UNSET;
   v_pca9535e_devices[e_device_42].s_io_state.u_bit.s_io_05 = C_PCA9535E_IO_SET;
   p_devices[e_lp_07].s_state_call                          = C_LP_ALL_OPEN;

   /* LP 08 */
   p_devices[e_lp_08].s_raw_swi_1.s_io_pointer  = &v_pca9535e_devices[e_device_44].s_io_state.u_word;
   p_devices[e_lp_08].s_raw_swi_1.s_io_mask     = C_LP08_CMD;
   p_devices[e_lp_08].s_raw_swi_1.s_err_pointer = &v_pca9535e_devices[e_device_44].s_status.u_word;
   p_devices[e_lp_08].s_raw_swi_2.s_io_pointer  = &v_pca9535e_devices[e_device_42].s_io_state.u_word;
   p_devices[e_lp_08].s_raw_swi_2.s_io_mask     = C_LP08_CMD_N;
   p_devices[e_lp_08].s_raw_swi_2.s_err_pointer = &v_pca9535e_devices[e_device_42].s_status.u_word;
   p_devices[e_lp_08].s_raw_status.s_io_pointer = &v_pca9535e_devices[e_device_42].s_io_state.u_word;
   p_devices[e_lp_08].s_raw_status.s_io_mask    = C_LP08_STATUS;

   v_pca9535e_devices[e_device_44].s_io_state.u_bit.s_io_04 = C_PCA9535E_IO_UNSET;
   v_pca9535e_devices[e_device_42].s_io_state.u_bit.s_io_04 = C_PCA9535E_IO_SET;
   p_devices[e_lp_08].s_state_call                          = C_LP_ALL_OPEN;

   /* LP 09 */
   p_devices[e_lp_09].s_raw_swi_1.s_io_pointer  = &v_pca9535e_devices[e_device_44].s_io_state.u_word;
   p_devices[e_lp_09].s_raw_swi_1.s_io_mask     = C_LP09_CMD;
   p_devices[e_lp_09].s_raw_swi_1.s_err_pointer = &v_pca9535e_devices[e_device_44].s_status.u_word;
   p_devices[e_lp_09].s_raw_swi_2.s_io_pointer  = &v_pca9535e_devices[e_device_44].s_io_state.u_word;
   p_devices[e_lp_09].s_raw_swi_2.s_io_mask     = C_LP09_CMD;
   p_devices[e_lp_09].s_raw_swi_2.s_err_pointer = &v_pca9535e_devices[e_device_44].s_status.u_word;
   p_devices[e_lp_09].s_raw_status.s_io_pointer = &v_pca9535e_devices[e_device_42].s_io_state.u_word;
   p_devices[e_lp_09].s_raw_status.s_io_mask    = C_LP09_STATUS;

   v_pca9535e_devices[e_device_44].s_io_state.u_bit.s_io_03 = C_PCA9535E_IO_UNSET;
   p_devices[e_lp_09].s_state_call                          = C_LP_ALL_OPEN;

   /* LP 10 */
   p_devices[e_lp_10].s_raw_swi_1.s_io_pointer  = &v_pca9535e_devices[e_device_4C].s_io_state.u_word;
   p_devices[e_lp_10].s_raw_swi_1.s_io_mask     = C_LP10_CMD;
   p_devices[e_lp_10].s_raw_swi_1.s_err_pointer = &v_pca9535e_devices[e_device_4C].s_status.u_word;
   p_devices[e_lp_10].s_raw_swi_2.s_io_pointer  = &v_pca9535e_devices[e_device_4A].s_io_state.u_word;
   p_devices[e_lp_10].s_raw_swi_2.s_io_mask     = C_LP10_CMD_N;
   p_devices[e_lp_10].s_raw_swi_2.s_err_pointer = &v_pca9535e_devices[e_device_4A].s_status.u_word;
   p_devices[e_lp_10].s_raw_status.s_io_pointer = &v_pca9535e_devices[e_device_4A].s_io_state.u_word;
   p_devices[e_lp_10].s_raw_status.s_io_mask    = C_LP10_STATUS;

   v_pca9535e_devices[e_device_4C].s_io_state.u_bit.s_io_06 = C_PCA9535E_IO_UNSET;
   v_pca9535e_devices[e_device_4A].s_io_state.u_bit.s_io_00 = C_PCA9535E_IO_SET;
   p_devices[e_lp_10].s_state_call                          = C_LP_ALL_OPEN;
}
