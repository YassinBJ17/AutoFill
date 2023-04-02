/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_DISC_H
#define LIBBSP_DISC_H

#include "LIBBSP_I2C.h"
#include "LIBMCP_Types.h"

/*==== Definitions =====================================================================*/

#define C_DISC_NB_BUFF (2ul)
#define C_DISC_NB_WRITE (3ul)


/*==== Types ===========================================================================*/

//typedef enum {
//    E_LIBBSP_DISC_EXPANDER_1                  = 0,
//  E_LIBBSP_DISC_EXPANDER_2                  = 1,
//  E_LIBBSP_DISC_NB_EXPANDER
//} TE_LIBBSP_DISC_Expander;

typedef enum {
    E_LIBBSP_DISC_CMD_IDLE                   = 0,
    E_LIBBSP_DISC_CMD_WRITE                  = 1,
    E_LIBBSP_DISC_CMD_READ                   = 2
} TE_LIBBSP_DISC_Cmd;


/* Return codes of Flash layer */
typedef enum {
    E_LIBBSP_DISC_MAX7312_CLOSED                  = 0,
    E_LIBBSP_DISC_MAX7312_OPEN                    = 1
} TE_LIBBSP_DISC_Max7312State;

typedef enum
{
    E_LIBBSP_DISC_MAX732_INPUT_PORT_1           =0x00,
    E_LIBBSP_DISC_MAX732_INPUT_PORT_2           =0x01,
    E_LIBBSP_DISC_MAX732_OUTPUT_PORT_1          =0x02,
    E_LIBBSP_DISC_MAX732_OUTPUT_PORT_2          =0x03,
    E_LIBBSP_DISC_MAX732_POLARITY_INVERSION_1   =0x04,
    E_LIBBSP_DISC_MAX732_POLARITY_INVERSION_2   =0x05,
    E_LIBBSP_DISC_MAX732_CONFIGURATION_1        =0x06,
    E_LIBBSP_DISC_MAX732_CONFIGURATION_2        =0x07,
    E_LIBBSP_DISC_MAX732_TIMEOUT                =0x08
}
TE_LIBBSP_DISC_Max7312RegAddr;

typedef struct
{
    TE_LIBBSP_DISC_Max7312RegAddr       v_reg;
    uint8_t         v_data;
} TS_LIBBSP_DISC_Max7312ConfCouple;


typedef union
{
    struct
    {
        uint16_t s_value;
        uint16_t dummy;
    } max7312Short;
    struct
    {
        uint32_t di15: 1;
        uint32_t di14: 1;
        uint32_t di13: 1;
        uint32_t di12: 1;
        uint32_t di11: 1;
        uint32_t di10: 1;
        uint32_t di9: 1;
        uint32_t di8: 1;
        uint32_t di7: 1;
        uint32_t di6: 1;
        uint32_t di5: 1;
        uint32_t di4: 1;
        uint32_t di3: 1;
        uint32_t di2: 1;
        uint32_t di1: 1;
        uint32_t di0: 1;
        uint32_t : 16;
    } max7312Input;
    struct
    {
        uint32_t do15: 1;
        uint32_t do14: 1;
        uint32_t do13: 1;
        uint32_t do12: 1;
        uint32_t do11: 1;
        uint32_t do10: 1;
        uint32_t do9: 1;
        uint32_t do8: 1;
        uint32_t do7: 1;
        uint32_t do6: 1;
        uint32_t do5: 1;
        uint32_t do4: 1;
        uint32_t do3: 1;
        uint32_t do2: 1;
        uint32_t do1: 1;
        uint32_t do0: 1;
        uint32_t : 16;
    } max7312Output;
} TU_max7312Disc;

/*==== Variables========================================================================*/

extern TE_LIBBSP_DISC_Max7312State V_DISC_Max7312State[E_LIBBSP_DISC_NB_EXPANDER];
extern TE_LIBBSP_DISC_Cmd V_DISC_Cmd[E_LIBBSP_DISC_NB_EXPANDER];

extern const uint8_t C_DISC_MAX7312_IO_EXP1_ADDR ;
extern const uint8_t C_DISC_MAX7312_IO_EXP2_ADDR ;
extern const TE_LIBBSP_I2C_Bus C_DISC_MAX7312_USED_BUS;
extern const TE_LIBBSP_I2C_FreqDiv C_DISC_MAX7312_DIVISOR_VALUE;
extern const uint8_t C_DISC_MAX7312_DIGITAL_FILTER;

extern const uint32_t C_DISC_SHIFT_8_BITS;
extern const uint16_t C_DISC_MASK_FIRST_BYTE;
/*==== Services ========================================================================*/

extern TE_LIBBSP_I2C_Code LIBBSP_DISC_Close(void);
extern TE_LIBBSP_I2C_Code LIBBSP_DISC_Configure(const TE_LIBBSP_DISC_Expander expanderID);
extern uint16_t LIBBSP_DISC_GetReadDisc(void);
extern TE_LIBBSP_I2C_Code LIBBSP_DISC_Open( const TE_LIBBSP_DISC_Expander expanderID);
extern void LIBBSP_DISC_Read(const TE_LIBBSP_DISC_Expander expanderID, uint16_t* const v_reg, TE_LIBBSP_I2C_Code * const v_ret);
extern void LIBBSP_DISC_ReadNoWait(const TE_LIBBSP_DISC_Expander expanderID, const TE_LIBBSP_I2C_CurrentStep v_step_in, TE_LIBBSP_I2C_CurrentStep* const v_step_out, TE_LIBBSP_I2C_ErrorCode * const v_ret);
extern void LIBBSP_DISC_Step(const TE_LIBBSP_DISC_Expander expanderID, const TE_LIBBSP_I2C_CurrentStep v_step_in, TE_LIBBSP_I2C_CurrentStep* const v_step_out, TE_LIBBSP_I2C_ErrorCode * const v_ret);
extern TE_LIBBSP_I2C_Code LIBBSP_DISC_Write(const TE_LIBBSP_DISC_Expander expanderID, const uint16_t v_reg);
extern void LIBBSP_DISC_WriteNoWait(const TE_LIBBSP_DISC_Expander expanderID, const uint16_t v_reg, const TE_LIBBSP_I2C_CurrentStep v_step_in, TE_LIBBSP_I2C_CurrentStep* const v_step_out, TE_LIBBSP_I2C_ErrorCode * const v_ret);
/*==== END =============================================================================*/
#endif
