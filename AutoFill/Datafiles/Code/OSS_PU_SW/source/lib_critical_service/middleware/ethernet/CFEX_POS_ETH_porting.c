/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

#include "middleware/ethernet/ETH_porting.h"

#if (ETH_FEC == 0 )
#include "driver/mailbox/MBX_HAL_public.h"
#include "middleware/icdl/ICDL_public.h"
#endif
#include "middleware/ethernet/ETH_MAC_public.h"

/*------ callback declarations -----------------------------*/
#if (ETH_FEC != 0 )
/* On MPC5777m, COS is interfaced with the FEC driver (ethernet controler driver) */
const tf_HAL_INIT hal_init_pt = (const tf_HAL_INIT) &FEC_INIT;
const tf_HAL_ESTABLISH_CONNECTION hal_establish_connection_pt = (const tf_HAL_ESTABLISH_CONNECTION) &FEC_ESTABLISH_CONNECTION;
const tf_HAL_GET_STATUS_READ hal_get_status_read_pt = (const tf_HAL_GET_STATUS_READ) &FEC_GET_STATUS_READ;
const tf_HAL_GET_STATUS_WRITE hal_get_status_write_pt = (const tf_HAL_GET_STATUS_WRITE) &FEC_GET_STATUS_WRITE;
const tf_HAL_GET_MAC hal_get_mac_pt = (const tf_HAL_GET_MAC) &FEC_GET_MAC;
const tf_HAL_ALLOW_RCV hal_allow_rcv_pt = (const tf_HAL_ALLOW_RCV) &FEC_ALLOW_RCV;
const tf_HAL_READ hal_read_pt = (const tf_HAL_READ) &FEC_READ;
const tf_HAL_WRITE hal_write_pt = (const tf_HAL_WRITE) &FEC_WRITE;
#else
/* On FPGA, COS is interfaced with the Mailbox/MAC ETH IP driver (ethernet controller driver) */
const tf_HAL_INIT hal_init_pt = (const tf_HAL_INIT) &MBX_INIT;
const tf_HAL_ESTABLISH_CONNECTION hal_establish_connection_pt = (const tf_HAL_ESTABLISH_CONNECTION) &MBX_ESTABLISH_CONNECTION;
const tf_HAL_GET_MAC hal_get_mac_pt = (const tf_HAL_GET_MAC) &MBX_GET_MAC;
const tf_HAL_READ hal_read_pt = (const tf_HAL_READ) &MBX_READ;
const tf_HAL_GET_STATUS_READ hal_get_status_read_pt = (const tf_HAL_GET_STATUS_READ) &MBX_GET_STATUS_READ;
const tf_HAL_ALLOW_RCV hal_allow_rcv_pt = (const tf_HAL_ALLOW_RCV) &MBX_ALLOW_RCV;
const tf_HAL_GET_STATUS_WRITE hal_get_status_write_pt = (const tf_HAL_GET_STATUS_WRITE) &MBX_GET_STATUS_WRITE;
const tf_HAL_WRITE hal_write_pt = (const tf_HAL_WRITE) &MBX_WRITE;
#endif


