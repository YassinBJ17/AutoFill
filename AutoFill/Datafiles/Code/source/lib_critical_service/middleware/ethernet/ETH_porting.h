/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef ETH_PORTING_H
#define ETH_PORTING_H

#include "type/common_type.h"
#include "middleware/stack_ip/ETH_public.h"

/* ---------- provided define constants --------------------------------------- */
#define ETH_FEC         0

/* ---------- provided types -------------------------------------------------- */
typedef struct {
   /* transfer done */
   int32_t s_len;
   te_CMN_FLAG_COMPLETE s_status;
} ts_ETH_HAL_STATS_TRANSFERT;

/* ---------- provided callback types ----------------------------------------- */
/* definitions of ETH COS callback types to map with HAL services    */

/* Name: *tf_HAL_INIT                                                */
/* Brief: all hardware abstraction layer initialization callback     */
/* Input/output: init status                                         */
/* Return: void                                                      */
typedef void (*tf_HAL_INIT)(tu_CMN_RC *const);
/* Name: *tf_HAL_ESTABLISH_CONNECTION                                */
/* Brief: callback to request connection establishment to HAL        */
/* Input/output: request status                                      */
/* Return: void                                                      */
typedef void (*tf_HAL_ESTABLISH_CONNECTION)(tu_CMN_RC *const);
/* Name: *tf_HAL_GET_STATUS_READ                                     */
/* Brief: callback to read HAL status                                */
/* Input/output: stats structure to fill                             */
/* Return: void                                                      */
typedef void (*tf_HAL_GET_STATUS_READ)(ts_ETH_HAL_STATS_TRANSFERT *const);
/* Name: *tf_HAL_GET_STATUS_WRITE                                    */
/* Brief: callback to update HAL status                              */
/* Input/output: stats structure to write                            */
/* Return: void                                                      */
typedef uint32_t (*tf_HAL_GET_STATUS_WRITE)(const ts_ETH_HAL_STATS_TRANSFERT *const);
/* Name: *tf_HAL_GET_MAC                                             */
/* Brief: callback to retrieve MAC address                           */
/* Input/output: structure to store MAC address in                   */
/* Return: void                                                      */
typedef void (*tf_HAL_GET_MAC)(ts_ETH_MACAddr *const);
/* Name: *tf_HAL_ALLOW_RCV                                           */
/* Brief: callback to allow data reception                           */
/* Input/output: void                                                */
/* Return: void                                                      */
typedef void (*tf_HAL_ALLOW_RCV)(void);
/* Name: *tf_HAL_READ                                                */
/* Brief: callback to request incoming data                          */
/* Input/output: buffer to fill with incoming data                   */
/* Return: void                                                      */
typedef void (*tf_HAL_READ)(ts_CMN_IOSP_BUFFER *const);
/* Name: *tf_HAL_WRITE                                               */
/* Brief: callback to request data transmission over HAL             */
/* Input/output: buffer filled with data to transmit                 */
/* Return: void                                                      */
typedef void (*tf_HAL_WRITE)(const ts_CMN_IOSP_BUFFER *const);

/* ---------- provided const and data ----------------------------------------- */
/* HAL callback extern declarations (formal declarations in ETH_porting.c) */
extern const tf_HAL_INIT hal_init_pt;
extern const tf_HAL_ESTABLISH_CONNECTION hal_establish_connection_pt;
extern const tf_HAL_GET_STATUS_READ hal_get_status_read_pt;
extern const tf_HAL_GET_STATUS_WRITE hal_get_status_write_pt;
extern const tf_HAL_GET_MAC hal_get_mac_pt;
extern const tf_HAL_ALLOW_RCV hal_allow_rcv_pt;
extern const tf_HAL_READ hal_read_pt;
extern const tf_HAL_WRITE hal_write_pt;

#endif /*ETH_PORTING_H*/
