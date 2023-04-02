#ifndef LL_TX_H
#define LL_TX_H

#include "LIBMCP_Types.h"
#include "LL.h"
/* #include "HW.h" */

/* #define ETSEC_TEST */



/* Index of TxBDs */
#define C_LL_TX_LAST_BD        (C_LIBBSP_ETSEC_ETHERNET_TX_FIFO_SIZE-(uint32_t)1) 

/* TxBD Fast Ethernet Controler control bits MPC8280RM.pdf 25.19 */
/* TxBD enhanced Three Speed Ethernet Controler control bits MPC1020RM.pdf 15-1105 */
#define C_FEC_ETSEC_TXBD_R             ((uint16_t)0x8000)
#define C_FEC_ETSEC_TXBD_PAD           ((uint16_t)0x4000)
/* #define C_ETSEC_TXBD_CRC               ((uint16_t)0x4000) */
#define C_FEC_ETSEC_TXBD_W             ((uint16_t)0x2000)
#define C_FEC_ETSEC_TXBD_I             ((uint16_t)0x1000)
#define C_FEC_ETSEC_TXBD_L             ((uint16_t)0x0800)
#define C_FEC_ETSEC_TXBD_TC            ((uint16_t)0x0400)
#define C_FEC_ETSEC_TXBD_NOT_R         ((uint16_t)0x0000)
#define C_FEC_ETSEC_TXBD_NOT_R_W       ((uint16_t)(C_FEC_ETSEC_TXBD_W))
#define C_FEC_ETSEC_TXBD_R_W           ((uint16_t)C_FEC_ETSEC_TXBD_R|C_FEC_ETSEC_TXBD_W)
#define C_FEC_ETSEC_TXBD_R_L           ((uint16_t)C_FEC_ETSEC_TXBD_R|C_FEC_ETSEC_TXBD_L)
#define C_FEC_ETSEC_TXBD_R_L_W         ((uint16_t)C_FEC_ETSEC_TXBD_R|C_FEC_ETSEC_TXBD_L|C_FEC_ETSEC_TXBD_W)
#define C_FEC_ETSEC_TXBD_R_L_TC        ((uint16_t)C_FEC_ETSEC_TXBD_R|C_FEC_ETSEC_TXBD_L|C_FEC_ETSEC_TXBD_TC)
#define C_FEC_ETSEC_TXBD_R_L_TC_W      ((uint16_t)C_FEC_ETSEC_TXBD_R_L_TC|C_FEC_ETSEC_TXBD_W)
#define C_FEC_ETSEC_TXBD_R_L_TC_PAD    ((uint16_t)C_FEC_ETSEC_TXBD_R_L_TC|C_FEC_ETSEC_TXBD_PAD)
#define C_FEC_ETSEC_TXBD_R_L_TC_PAD_W  ((uint16_t)C_FEC_ETSEC_TXBD_R_L_TC_PAD|C_FEC_ETSEC_TXBD_W)
/* #define C_FEC_ETSEC_TXBD_DEF        ((uint16_t)0x0200) */
/* #define C_ETSEC_TXBD_PRE            ((uint16_t)0x0200) */
/* #define C_FEC_TXBD_HB               ((uint16_t)0x0100) */
/* #define C_ETSEC_TXBD_HFE            ((uint16_t)0x0080) */
/* #define C_FEC_ETSEC_TXBD_LC         ((uint16_t)0x0080) */
/* #define C_ETSEC_TXBD_CF             ((uint16_t)0x0040) */
/* #define C_ETSEC_TXBD_EX             ((uint16_t)0x0040) */
/* #define C_FEC_ETSEC_TXBD_RL         ((uint16_t)0x0040) */
/* #define C_FEC_ETSEC_TXBD_RC         ((uint16_t)0x003C) */
/* #define C_FEC_ETSEC_TXBD_UN         ((uint16_t)0x0002) */
/* #define C_ETSEC_TXBD_TOE            ((uint16_t)0x0002) */
/* #define C_FEC_TXBD_CSL              ((uint16_t)0x0001) */
/* #define C_ETSEC_TXBD_TR             ((uint16_t)0x0001) */

/* Buffer d'emission TX */
/*typedef struct
  {
      uint8_t txbyte [ETHERNET_TX_BUFFER_SIZE];
  } t_ll_txbuffer;*/

/*#define ETHERNET_TX_FIFO_SIZE    ((uint32_t)20)*/
/* Buffer d'emission TX a associer aux BD TX */
/*typedef struct
  {
      t_ll_txbuffer txbuffer [ETHERNET_TX_FIFO_SIZE];
  } t_ll_tx_pool;*/

/*typedef struct
  {
      t_ll_tx_bd txbd [ETHERNET_TX_FIFO_SIZE];
  } t_ll_tx_bd_table;*/

/* Interface d'emission sur un network */
typedef struct
{
    uint32_t hw_txbd;
    uint32_t controler;
    uint32_t next_frame_to_send;
} TS_ll_tx_interface;

extern const uint8_t *LL_TX_initialize (const uint32_t controller);
extern void LL_TX_get_frame (const uint32_t controller, TS_LIBBSP_ETSEC_t_ll_tx_bd ** const p_bd);
extern void LL_TX_send_frame (const uint32_t controller, TS_LIBBSP_ETSEC_t_ll_tx_bd * const p_bd);

#endif
