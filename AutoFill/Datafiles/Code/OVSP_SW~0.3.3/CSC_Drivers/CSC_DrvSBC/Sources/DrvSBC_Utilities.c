/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the ...
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvSBC_Private.h"

#include "DrvLPSPI_Public.h"

#include "MCP_Types.h"


/* ---------- internal define constants: ------------------------------------ */
/* None */

/* ---------- internal types: ----------------------------------------------- */
/* None */

/* ---------- internal operations: ------------------------------------------ */
/* None */

/* ---------- internal constants: ------------------------------------------- */
/* None */

/* ---------- internal data: ------------------------------------------------ */
/* None */

/* ---------- provided operation bodies: ------------------------------------ */

/* DrvSBC_CAN_RT_Status : To retrieve the state of the CAN line of the SBC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
TE_DrvSBC_CAN_Status DrvSBC_CAN_RT_Status (void)
{
   TE_DrvSBC_CAN_Status v_CAN_Status;

   uint32_t v_Read_Value;
   uint32_t v_Status;

   DrvLPSPI_Write (DRVSBC_INIT_CAN_RT_STATUS, &v_Status);

   DrvLPSPI_Read (&v_Read_Value, &v_Status);

   /*Check if CAN driver is ON and CAN is in Rx TX mode */
   if ((DRVSBC_CAN_STATUS_CAN_DRV_STATE_MASK == (v_Read_Value & DRVSBC_CAN_STATUS_CAN_DRV_STATE_MASK)) &&
       (DRVSBC_CAN_STATUS_CAN_RCV_STATE_MASK == (v_Read_Value & DRVSBC_CAN_STATUS_CAN_RCV_STATE_MASK)))
   {
      v_CAN_Status = E_DrvSBC_CAN_OK;
   }
   else
   {
      v_CAN_Status = E_DrvSBC_CAN_KO;
   }

   /* >RELAX<SYNCHRONe_C_Code_16.12> Waiting for SYNCHONe analyze, it seems to be a false violation. */
   /* The returned data is of the function return type. */
   return (v_CAN_Status);
}


/* DrvSBC_Cmd_Init_WDOG : To send a Init_WDOG SPI command to the SBC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvSBC_Cmd_Init_WDOG(void)
{
   uint32_t v_Read_Value;
   uint32_t v_Status;

   DrvLPSPI_Write (DRVSBC_INIT_CMD_INIT_WATCHDOG, &v_Status);

   DrvLPSPI_Read (&v_Read_Value, &v_Status);
}


/* DrvSBC_Cmd_Init_Reg : To send a Init_Reg SPI command to the SBC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvSBC_Cmd_Init_Reg(void)
{
   uint32_t v_Read_Value;
   uint32_t v_Status;

   DrvLPSPI_Write (DRVSBC_INIT_CMD_INIT_REG, &v_Status);

   DrvLPSPI_Read (&v_Read_Value, &v_Status);
}


/* DrvSBC_Cmd_Init_LIN_IO : To send a Init_LIN_IO SPI command to the SBC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvSBC_Cmd_Init_LIN_IO(void)
{
   uint32_t v_Read_Value;
   uint32_t v_Status;

   DrvLPSPI_Write (DRVSBC_INIT_CMD_INIT_LIN_IO, &v_Status);

   DrvLPSPI_Read (&v_Read_Value, &v_Status);
}


/* DrvSBC_Cmd_Init_Misc : To send a Init_Misc SPI command to the SBC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvSBC_Cmd_Init_Misc(void)
{
   uint32_t v_Read_Value;
   uint32_t v_Status;

   DrvLPSPI_Write (DRVSBC_INIT_CMD_INIT_MISC, &v_Status);

   DrvLPSPI_Read (&v_Read_Value, &v_Status);
}


/* DrvSBC_Cmd_Timer_A : To send a Timer_A SPI command to the SBC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvSBC_Cmd_Timer_A(void)
{
   uint32_t v_Read_Value;
   uint32_t v_Status;

   DrvLPSPI_Write (DRVSBC_INIT_CMD_TIMER_A, &v_Status);

   DrvLPSPI_Read (&v_Read_Value, &v_Status);
}


/* DrvSBC_Cmd_Timer_B : To send a Timer_B SPI command to the SBC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvSBC_Cmd_Timer_B(void)
{
   uint32_t v_Read_Value;
   uint32_t v_Status;

   DrvLPSPI_Write (DRVSBC_INIT_CMD_TIMER_B, &v_Status);

   DrvLPSPI_Read (&v_Read_Value, &v_Status);
}


/* DrvSBC_Cmd_Timer_C : To send a Timer_C SPI command to the SBC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvSBC_Cmd_Timer_C(void)
{
   uint32_t v_Read_Value;
   uint32_t v_Status;

   DrvLPSPI_Write (DRVSBC_INIT_CMD_TIMER_C, &v_Status);

   DrvLPSPI_Read (&v_Read_Value, &v_Status);
}


/* DrvSBC_Cmd_Reg : To send a Reg SPI command to the SBC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvSBC_Cmd_Reg(void)
{
   uint32_t v_Read_Value;
   uint32_t v_Status;

   DrvLPSPI_Write (DRVSBC_INIT_CMD_REG, &v_Status);

   DrvLPSPI_Read (&v_Read_Value, &v_Status);
}


/* DrvSBC_Cmd_CAN_Reg : To send a CAN_Reg SPI command to the SBC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvSBC_Cmd_CAN_Reg(void)
{
   uint32_t v_Read_Value;
   uint32_t v_Status;

   DrvLPSPI_Write (DRVSBC_INIT_CMD_CAN_REG, &v_Status);

   DrvLPSPI_Read (&v_Read_Value, &v_Status);
}


/* DrvSBC_Cmd_IO : To send a IO SPI command to the SBC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvSBC_Cmd_IO(void)
{
   uint32_t v_Read_Value;
   uint32_t v_Status;

   DrvLPSPI_Write (DRVSBC_INIT_CMD_IO, &v_Status);

   DrvLPSPI_Read (&v_Read_Value, &v_Status);
}


/* DrvSBC_Cmd_Int : To send a Int SPI command to the SBC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvSBC_Cmd_Int(void)
{
   uint32_t v_Read_Value;
   uint32_t v_Status;

   DrvLPSPI_Write (DRVSBC_INIT_CMD_INT, &v_Status);

   DrvLPSPI_Read (&v_Read_Value, &v_Status);
}


/* DrvSBC_Cmd_LIN1 : To send a LIN1 SPI command to the SBC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvSBC_Cmd_LIN1(void)
{
   uint32_t v_Read_Value;
   uint32_t v_Status;

   DrvLPSPI_Write (DRVSBC_INIT_CMD_LIN1, &v_Status);

   DrvLPSPI_Read (&v_Read_Value, &v_Status);
}


/* DrvSBC_Cmd_LIN2 : To send a LIN2 SPI command to the SBC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvSBC_Cmd_LIN2(void)
{
   uint32_t v_Read_Value;
   uint32_t v_Status;

   DrvLPSPI_Write (DRVSBC_INIT_CMD_LIN2, &v_Status);

   DrvLPSPI_Read (&v_Read_Value, &v_Status);
}


/* DrvSBC_Cmd_Mux_Out : To send a Mux_Out SPI command to the SBC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvSBC_Cmd_Mux_Out(void)
{
   uint32_t v_Read_Value;
   uint32_t v_Status;

   DrvLPSPI_Write (DRVSBC_INIT_CMD_MUX_OUT, &v_Status);

   DrvLPSPI_Read (&v_Read_Value, &v_Status);
}


/* DrvSBC_Cmd_WDOG_Refresh : To send a WDOG_Refresh SPI command to the SBC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvSBC_Cmd_WDOG_Refresh(void)
{
   uint32_t v_Read_Value;
   uint32_t v_Status;

   DrvLPSPI_Write (DRVSBC_INIT_CMD_WDOG_REFRESH, &v_Status);

   DrvLPSPI_Read (&v_Read_Value, &v_Status);
}
