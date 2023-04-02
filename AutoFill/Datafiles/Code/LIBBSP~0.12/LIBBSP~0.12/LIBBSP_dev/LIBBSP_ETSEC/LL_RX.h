#ifndef LL_RX_H
#define LL_RX_H

#include "LIBMCP_Types.h"
#include "LL.h"
/* #include "HW.h" */

/* #define ETSEC_TEST */

/* Nombre de trames a depiler a chaque appel de ethernet_receive, a regler en fonction de la charge */
#define C_MAX_FRAMES_TO_RECEIVE   ((uint32_t)10)

#define ETHERNET_RX_FIFO_THRESHOLD     4ul

/* RxBD control bits MPC8280RM.pdf 25.18 */
#define C_FEC_ETSEC_RXBD_E          ((uint16_t)0x8000)
#define C_ETSEC_RXBD_RO1            ((uint16_t)0x4000)
#define C_FEC_ETSEC_RXBD_W          ((uint16_t)0x2000)
#define C_FEC_ETSEC_RXBD_I          ((uint16_t)0x1000)
#define C_FEC_ETSEC_RXBD_L          ((uint16_t)0x0800)
#define C_FEC_ETSEC_RXBD_F          ((uint16_t)0x0400)
#define C_FEC_RXBD_CMR              ((uint16_t)0x0200)
#define C_FEC_ETSEC_RXBD_M          ((uint16_t)0x0100)
#define C_FEC_ETSEC_RXBD_BC         ((uint16_t)0x0080)
#define C_FEC_ETSEC_RXBD_MC         ((uint16_t)0x0040)
#define C_FEC_ETSEC_RXBD_LG         ((uint16_t)0x0020)
#define C_FEC_ETSEC_RXBD_NO         ((uint16_t)0x0010)
#define C_FEC_ETSEC_RXBD_SH         ((uint16_t)0x0008)
#define C_FEC_ETSEC_RXBD_CR         ((uint16_t)0x0004)
#define C_FEC_ETSEC_RXBD_LG_SH      ((uint16_t)(C_FEC_ETSEC_RXBD_LG|C_FEC_ETSEC_RXBD_SH))
#define C_FEC_ETSEC_RXBD_OV         ((uint16_t)0x0002)
#define C_FEC_RXBD_CL               ((uint16_t)0x0001)
#define C_ETSEC_RXBD_TR             ((uint16_t)0x0001)
#define C_FEC_RXBD_OV_CL            ((uint16_t)(C_FEC_ETSEC_RXBD_OV|C_FEC_RXBD_CL))
#define C_FEC_ETSEC_RXBD_ALL_ERROR  ((uint16_t)(C_FEC_ETSEC_RXBD_CR|C_FEC_ETSEC_RXBD_NO|C_FEC_ETSEC_RXBD_LG_SH| \
                                              C_FEC_RXBD_OV_CL))
#define C_FEC_ETSEC_RXBD_NO_ERROR   ((uint16_t)(C_FEC_ETSEC_RXBD_L|C_FEC_ETSEC_RXBD_F))
#define C_FEC_ETSEC_RXBD_NOT_E      ((uint16_t)0x0000)
#define C_FEC_ETSEC_RXBD_E_W        ((uint16_t)(C_FEC_ETSEC_RXBD_E|C_FEC_ETSEC_RXBD_W))
#define C_FEC_ETSEC_RXBD_NOT_E_W    ((uint16_t)(C_FEC_ETSEC_RXBD_NOT_E|C_FEC_ETSEC_RXBD_W))
#define C_FEC_ETSEC_RXBD_L_F        ((uint16_t)(C_FEC_ETSEC_RXBD_L|C_FEC_ETSEC_RXBD_F))

/* Buffer de reception RX */
/* typedef struct {
	uint8_t rxbyte[ETHERNET_RX_BUFFER_SIZE];
  } t_ll_rxbuffer; */

/* Pool de buffers de reception a associer aux BD RX */
/* typedef struct {
	t_ll_rxbuffer rxbuffer[ETHERNET_RX_FIFO_SIZE];
 } t_ll_rx_pool;*/

/* #define ETHERNET_RX_FIFO_SIZE     ((uint32_t)20) */
/* Table de BDs associe a une interface reseau */
/* typedef struct {
	t_ll_rx_bd rxbd[ETHERNET_RX_FIFO_SIZE];
  } t_ll_rx_bd_table;*/

/* Interface de reception sur une interface reseau */
/* typedef struct {
	uint32_t controller;
	uint32_t next_frame_to_get;
  } t_ll_rx_interface;*/

extern TS_LIBBSP_ETSEC_t_ll_rx_interface V_LL_RX_interface [C_LIBBSP_ETSEC_ETHERNET_NB_CONTROLLERS];

extern void LL_RX_get_frame(const uint32_t controller,
                            TE_LIBBSP_ETSEC_FrameStatus * const paFrame_status,
                            const uint8_t ** const paFrame );
extern void LL_RX_get_bd ( const uint32_t controller, TS_LIBBSP_ETSEC_t_ll_rx_bd const ** p_bd );
extern void LL_RX_check_overrun( const uint32_t controller );
extern void LL_RX_flush( const uint32_t controller );
extern void LL_RX_free_frame( const uint32_t controller );
extern const uint8_t *LL_RX_initialize( const uint32_t controller );

#endif /* LL_RX_H */
