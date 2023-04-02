/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DRVSBC_PRIVATE_H
#define DRVSBC_PRIVATE_H

/* ---------- include predefined types: ------------------------------------- */
#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */

/* ---------- provided define constants: ------------------------------------ */

   /*----------  MOSI Commands definition  ----------*/
#define DRVSBC_INIT_CMD_INIT_WATCHDOG                      0x00009842UL      /* MOSI Command INIT_WATCHDOG */
#define DRVSBC_INIT_CMD_INIT_REG                           0x00004A80UL      /* MOSI Command INIT_REG */
#define DRVSBC_INIT_CMD_INIT_LIN_IO                        0x00004E00UL      /* MOSI Command INIT_LIN_IO */
#define DRVSBC_INIT_CMD_INIT_MISC                          0x00005000UL      /* MOSI Command INIT_MISC */
#define DRVSBC_INIT_CMD_WDOG_REFRESH                       0x00005A00UL      /* MOSI Command WATCHDOG Refresh Entering to NORMAL mode */
#define DRVSBC_INIT_CMD_TIMER_A                            0x00005400UL      /* MOSI Command TIMER reg A */
#define DRVSBC_INIT_CMD_TIMER_B                            0x00005600UL      /* MOSI Command TIMER reg B */
#define DRVSBC_INIT_CMD_TIMER_C                            0x0000580CUL      /* MOSI Command TIMER reg C */
#define DRVSBC_INIT_CMD_REG                                0x00005E14UL      /* MOSI Command REG reg */
#define DRVSBC_INIT_CMD_CAN_REG                            0x000060C0UL      /* MOSI Command REG reg :  Write CAN reg.: CAN in Tx & Rx modes, fast slew rate */
#define DRVSBC_INIT_CMD_IO                                 0x00006200UL      /* MOSI Command IO Reg */
#define DRVSBC_INIT_CMD_INT                                0x00006405UL      /* MOSI Command INT Reg */
#define DRVSBC_INIT_CMD_LIN1                               0x00006600UL      /* MOSI Command LIN1 Reg */
#define DRVSBC_INIT_CMD_LIN2                               0x00006800UL      /* MOSI Command LIN2 Reg */
#define DRVSBC_INIT_CMD_MUX_OUT                            0x00004068UL      /* MOSI Command MUX_OUT Reg */
#define DRVSBC_INIT_SAFE_REG_READ                          0x0000DD80UL      /* MOSI Command Read SAFE register */
#define DRVSBC_INIT_CAN_RT_STATUS                          0x00002180UL      /* MOSI Command Read CAN Real-Time status from SBC */

   /*----------  MISO Return Values  ----------*/
#define DRVSBC_MODE_INIT_VAL                               0UL
#define DRVSBC_MODE_FLASH_VAL                              1UL
#define DRVSBC_MODE_NORMAL_REQUEST_VAL                     2UL
#define DRVSBC_MODE_NORMAL_VAL                             3UL

   /*----------  MISO Masks definition  ----------*/
#define DRVSBC_CAN_STATUS_CAN_DRV_STATE_MASK               0x00000080UL
#define DRVSBC_CAN_STATUS_CAN_RCV_STATE_MASK               0x00000040UL

#define DRVSBC_MODE_LP_STATE_MASK                          0x00000010UL

#define DRVSBC_MODE_STATE_MASK                             0x000000F8UL
#define DRVSBC_MODE_STATE_SHIFT                            3UL

/* ---------- provided types: ----------------------------------------------- */
typedef enum
{
   E_DrvSBC_CAN_OK,
   E_DrvSBC_CAN_KO,
} TE_DrvSBC_CAN_Status;

typedef enum
{
   E_DrvSBC_Init_OK,
   E_DrvSBC_Init_KO,
} TE_DrvSBC_Init_Status;

typedef enum
{
   E_DrvSBC_Mode_Init_Reset,
   E_DrvSBC_Mode_Init,
   E_DrvSBC_Mode_Flash,
   E_DrvSBC_Mode_Normal_Request,
   E_DrvSBC_Mode_Normal,
   E_DrvSBC_Mode_Low_Power,
} TE_DrvSBC_States;

/* ---------- provided constants: ------------------------------------------- */
extern uint32_t const C_DrvSBC_Cmd_List[17];

/* ---------- provided data: ----------------------------------------------- */
/* None */

/* ---------- provided operations: ------------------------------------------ */
extern TE_DrvSBC_CAN_Status DrvSBC_CAN_RT_Status (void);

extern TE_DrvSBC_States DrvSBC_Get_Current_Mode (void);

extern void DrvSBC_Cmd_WDOG_Refresh (void);
extern void DrvSBC_Cmd_Init_WDOG (void);
extern void DrvSBC_Cmd_Init_Reg (void);
extern void DrvSBC_Cmd_Init_LIN_IO (void);
extern void DrvSBC_Cmd_Init_Misc (void);
extern void DrvSBC_Cmd_Timer_A (void);
extern void DrvSBC_Cmd_Timer_B (void);
extern void DrvSBC_Cmd_Timer_C (void);
extern void DrvSBC_Cmd_Reg (void);
extern void DrvSBC_Cmd_CAN_Reg (void);
extern void DrvSBC_Cmd_IO (void);
extern void DrvSBC_Cmd_Int (void);
extern void DrvSBC_Cmd_LIN1 (void);
extern void DrvSBC_Cmd_LIN2 (void);
extern void DrvSBC_Cmd_Mux_Out (void);


#endif /* DRVSBC_PRIVATE_H */
