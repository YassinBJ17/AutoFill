/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef MID_ICDL_PUBLIC_H
#define MID_ICDL_PUBLIC_H
/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- provided define constants: ------------------------------------ */
#define K_OPEN_PORT              (uint32_t)1
#define K_CLOSE_PORT             (uint32_t)0

#define ICDL_OS_NB_PORT (uint32_t)6

/* ---------- provided types: ----------------------------------------------- */
typedef enum
{
   FREAD          = 0x0A2,
   FWRITE         = 0x0A3,
   SEND_TO_MU     = 0x0C5,
   LOG            = 0x101,
   TECU_STREAM    = 0x102,
   SECU_ALERT_ACK = 0x110,
   POWERUPCOUNT   = 0x120,
   LASTPWRUPTIME  = 0x121,
   MU_ALIVE       = 0x130
} command_val_type;

typedef enum
{
   ICDL_FREAD_INDEX = 0,
   ICDL_FWRITE_INDEX,
   ICDL_SEND_TO_MU_INDEX,
   ICDL_LOG_INDEX,
   ICDL_TECU_STREAM_INDEX,
   ICDL_SECU_ALERT_ACK_INDEX,
   ICDL_POWERUPCOUNT_INDEX,
   ICDL_LASTPWRUPTIME_INDEX,
   ICDL_MU_ALIVE_INDEX,
   ICDL_NB_COMMAND
} ICDL_index_type;


typedef enum
{
   PORT_49100 = 49100,
   PORT_49200 = 49200,
   PORT_49300 = 49300,
   PORT_49400 = 49400,
   PORT_49500 = 49500,
   PORT_49700 = 49700,
   PORT_49900 = 49900,
   PORT_50000 = 50000,
   PORT_50100 = 50100,
   PORT_50200 = 50200,
   PORT_50300 = 50300
} ICDL_port_list_type;


typedef struct
{
   command_val_type command_val;
   uint32_t         boolean_data;
   uint32_t         nb_argument;
   uint32_t         frame_length;
} ICDL_data_command_type;

typedef struct
{
   ICDL_data_command_type command;
   ICDL_port_list_type    port;
} ICDL_command_type;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
extern int32_t g_init_log_sent;
extern int32_t g_compteur_htr;
extern int32_t g_compteur_htr_init_log_sent;
extern int32_t g_pltf_log_sent;
extern boolean_t g_mu_is_alive;

extern const ICDL_port_list_type c_port_list[ICDL_OS_NB_PORT];



/* ---------- provided operations: ------------------------------------------ */

/*---------------------------------------------------------------------------
-- mid_icdl_icdl_init
---------------------------------------------------------------------------*/
void mid_icdl_init( void );

/*---------------------------------------------------------------------------
-- mid_icdl_mngt
---------------------------------------------------------------------------*/
extern void mid_icdl_mngt ( const boolean_t p_channel_is_a );



#endif /* MID_ICDL_PUBLIC_H */
