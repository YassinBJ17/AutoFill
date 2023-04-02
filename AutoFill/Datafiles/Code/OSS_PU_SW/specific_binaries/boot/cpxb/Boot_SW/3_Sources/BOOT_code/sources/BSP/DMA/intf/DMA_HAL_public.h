#ifndef DMA_HAL_PUBLIC_H
#define DMA_HAL_PUBLIC_H


/* --------------------------------------------------------------------------
 *                           Sagem Defense Securite
 *                               SAFRAN Group
 * --------------------------------------------------------------------------
 * PROJECT : CHRONOS
 * CSU name :
 * %name: DMA_HAL_public.h %
 * %full_name: fadex#9/incl/DMA_HAL_public.h/1 %
 *
 * Creation information:
 *   Created by: F073297
 *   Date : Thu May 31 09:55:04 CEST 2018
 *
 * Modification information:
 *   %derived_by: F605763 %
 *   %date_created:Thu May 12 18:18:10 CEST 2022 %
 * --------------------------------------------------------------------------
 * SAGEM Defense Securite document. Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


/* ---------- include required interface: ----------------------------------- */


/* LPOS Common Interface */
#include "CMN_TYPES_common.h"
#include "CMN_IOSP_common.h"

/* ---------- provided define constants: ------------------------------------ */
/*  */
#define DMA_MAX_NB          2UL
#define DMA_LINE_MAX_NB     64UL
#define DMA_MUX_MAX_NB          10
#define DMA_MUX_LINE_MAX_NB     16
#define DMA_MUX_SOURCE_MAX_NB   64
#define DMA_MUX_LINE_DISABLE    0x00
#define DMA_MUX_LINE_ENABLE     0x80


/* ---------- provided types: ----------------------------------------------- */


/* {{RELAX<SYNCHRONe_C_Code_8.17> : all definitions are given even if only a configuration is used.
 Reuse strategy.  */
/* */
typedef enum
{
   e_DMA_BUFFER_ONE_SHOT = 1,
   e_DMA_BUFFER_CYCLIC   = 0

}
te_DMA_BUFFER_MGT;


/* */
typedef enum
{
   e_DMA_REQUEST_8_BIT  = 0,
   e_DMA_REQUEST_16_BIT = 1,
   e_DMA_REQUEST_32_BIT = 2,
   e_DMA_REQUEST_NB_VAL = 3 /* to be last value of the enum*/
}
te_DMA_BYTE_REQ;
/* }}<SYNCHRONe_C_Code_8.17> */


/* Define DMA MPC577 programming type */

typedef struct
{
   /* Number of byte by request */ //TODO
   //te_DMA_BYTE_REQ   s_nb_byte_req;
   uint32_t s_nb_byte_req;

   /* Source address */
   uint32_t               s_src_addr;

   /* Source last address */
   uint32_t               s_src_last_addr;

   /* Source offset data */
   uint16_t               s_src_off;

   /* Destination address */
   uint32_t               s_dest_addr;

   /* Destination last address */
   uint32_t               s_dest_last_addr;

   /* Destination offset data */
   uint16_t               s_dest_off;

   /* Number of cycle */
   uint16_t               s_nb_cycle;

   /* One shot (=1) or loop infinite (=0) */
   te_DMA_BUFFER_MGT s_buff_type;
}
ts_DMA_PROG;



/* Define DMA MPC577 status type */
typedef struct
{
   /* current data read  */
   uint16_t s_read_done;

   /* */
   uint16_t s_read_in_progress;

   /* Cycle counter */
   uint16_t s_cycle_count;

   /* Cycle number */
   uint16_t s_cycle_nb;
}
ts_DMA_STATUS;



/* ---------- provided constants: ------------------------------------------- */
/* none */



/* ---------- provided data: ------------------------------------------------ */
/* none */


/* ---------- provided operations: ------------------------------------------ */


extern void DMA_INIT( void );


/* */
/* Used to configure DMA */
extern void DMA_CFG ( CMN_IOSP_ID_t const       p_dma_conf_id,
                             ts_DMA_PROG const * const p_dma_prog );



extern void DMA_GET_CFG ( CMN_IOSP_ID_t       const p_dma_conf_id,
                                 ts_DMA_PROG * const p_dma_prog );



/* */
/* Used to start or stop DMA */
extern void DMA_START ( CMN_IOSP_ID_t const p_dma_conf_id,
                               te_CMN_FLAG_RUN const     p_dma_start );

/* */
/* Used to enable or disable request signal DMA */
extern void DMA_REQUEST ( CMN_IOSP_ID_t   const p_dma_conf_id,
                                 te_CMN_FLAG_ACTIVATION const p_dma_request_signal);





/* Used to read the status DMA */
extern void DMA_STATUS ( CMN_IOSP_ID_t         const p_dma_conf_id,
                                ts_DMA_STATUS * const p_dma_status);

/* Used to clear the DONE bit of the channel DMA */
extern void DMA_CLEAR_DONE ( CMN_IOSP_ID_t const p_dma_conf_id,
                             te_CMN_FLAG_RUN const p_dma_done );

#endif /* DMA_HAL_PUBLIC_H */


