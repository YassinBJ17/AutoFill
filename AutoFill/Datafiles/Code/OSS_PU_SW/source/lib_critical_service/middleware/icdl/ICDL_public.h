/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef ICDL_PUBLIC_H
#define ICDL_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "middleware/stack_ip/ETH_UDP_public.h"
#include "type/common_type.h"

/* ---------- provided define constants: ------------------------------------ */
#define ICDL_MSG_TX_MAX (uint32_t)(5610)
/*#define ICDL_MSG_RX_MAX 6000*/

/* TODO PAULO : TO BE TESTED */
#define ICDL_MSG_RX_MAX  (uint32_t)(1518)
#define ICDL_NB_MSG_TX   (uint32_t)(3)
#define ICDL_NB_OS_PORTS (uint32_t)(6)

/* SHM TX SIZE capacity is 5610 bytes, 1480 is maximum payload information in one frame*/
#define ICDL_NB_FRAG_MAX (ICDL_MSG_TX_MAX / 1480 )

/*#define K_AS_CMD_UDP_PORTS_DST  49000*/
/*#define K_AS_CMD_UDP_PORTS_SRC  49000*/

/* Size of UOD buffer */
#define ICDL_UOD2_MSG_MAX_SIZE (uint32_t)1500

/* ---------- provided types: ----------------------------------------------- */
typedef enum
{
   e_ICDL_MBX_WRITE_MODE  = 0
}
te_WRITE_MODE ;


typedef struct
{
   void * in_msg;
   const void * out_msg;
   uint32_t status;
   uint16_t nb_bytes;

} t_extern_critical_services_icdl_params;

/* ---------- provided constants: ------------------------------------------- */
#define K_OPEN_PORT              (uint32_t)1
#define K_CLOSE_PORT             (uint32_t)0

/* ---------- provided datas: ----------------------------------------------- */
extern ts_CMN_IOSP_BUFFER udpBufferASReception;
/*extern int8_t udpASBuffer[ICDL_MSG_RX_MAX];*/

/* Create ICDL_NB_OS_PORTS buffers */
extern int8_t udpOSBuffer[ICDL_NB_OS_PORTS][ICDL_MSG_RX_MAX];

extern int8_t udpUODBuffer[ICDL_UOD2_MSG_MAX_SIZE];

extern uint32_t v_ICDL_WRITE_MODE ;
extern const tu_ETH_IPAddr ETH_CFEX_CDM_AS_EtherAddr ;
extern const tu_ETH_IPAddr ETH_CFEX_BENCH_EtherAddr ;

extern t_extern_critical_services_icdl_params * const Pt_extern_critical_services_icdl_params;

/* UOD PORT */
#define K_UOD_UDP_PORTS_SRC      (uint32_t)49800

/* ---------- provided operations: ------------------------------------------ */

/*---------------------------------------------------------------------------
-- mid_icdl_read
---------------------------------------------------------------------------*/
extern void icdl_read ( void );

/*---------------------------------------------------------------------------
-- mid_icdl_write
---------------------------------------------------------------------------*/
extern void icdl_write ( void );

/*---------------------------------------------------------------------------
-- icdl_create_ports
---------------------------------------------------------------------------*/
extern void icdl_create_ports ( void );


/*extern void ICDL_INIT( void );*/
/**/
/*extern void ICDL_WRITE( uint8_t * const p_buff_out , uint16_t const p_size, uint32_t const p_port_dst );*/
/**/
/*extern void ICDL_READ( uint8_t * const p_buffer_in , uint16_t * const p_size );*/
/**/
/*extern void ICDL_HANDLE_RECEPTION( uint32_t const p_cmd_port, uint32_t const p_port_src , te_ETH_UDP_PORT_Status * p_ETH_Init_status );*/
/**/
/*extern void ICDL_WRITE_MODE( const ts_CMN_IOSP_BUFFER* const p_buff );*/
/**/
/*extern void ICDL_GET_STATUS_WRITE_MODE( ts_ETH_HAL_STATS_TRANSFERT * const p_pt_stats );*/

#endif /* ICDL_PUBLIC_H */
