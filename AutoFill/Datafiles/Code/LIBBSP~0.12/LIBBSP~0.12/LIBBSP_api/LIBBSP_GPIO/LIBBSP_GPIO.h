/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_GPIO_H_
#define LIBBSP_GPIO_H_

#include "LIBMCP_Types.h"
#include "kcg_types.h"

/*==== Definitions =====================================================================*/

/*==== Types =======================================================================*/

typedef enum
{
    E_LIBBSP_GPIO_VALID_ADDR,
	E_LIBBSP_GPIO_INVALID_ADDR
} TE_LIBBSP_GPIO_AddrStatus;

/* function return */
/*typedef enum
{
    E_LIBBSP_GPIO_SUCCEEDED,
    E_LIBBSP_GPIO_FAILED
} TE_LIBBSP_GPIO_Status;*/
/* defined in kcg_types.h */

/*typedef enum*/
/*{*/
/*    E_LIBBSP_GPIO_MEGA_GPIO2 = 0x0001,*/
/*    E_LIBBSP_GPIO_MEGA_GPIO1 = 0x0002,*/
/*	E_LIBBSP_GPIO_MEGA_GPIO0 = 0x0004,*/
/*	E_LIBBSP_GPIO_COMP_GPIO2 = 0x0008,*/
/*	E_LIBBSP_GPIO_COMP_GPIO1 = 0x0010,*/
/*	E_LIBBSP_GPIO_COMP_GPIO0 = 0x0020,*/
/*	E_LIBBSP_GPIO_SDHC_W_PROTECT = 0x0040,*/
/*	E_LIBBSP_GPIO_SDHC_CARD_DETECT = 0x0080,*/
/*	E_LIBBSP_GPIO_GREEN_LED = 0x0100,*/
/*	E_LIBBSP_GPIO_YELLOW_LED = 0x0200,*/
/*	E_LIBBSP_GPIO_RED_LED = 0x0400,*/
/*	E_LIBBSP_GPIO_IRQ11 = 0x0800,*/
/*	E_LIBBSP_GPIO_DSI_SG_LABO = 0x1000,*/
/*	E_LIBBSP_GPIO_DSI_DL = 0x2000,*/
/*	E_LIBBSP_GPIO_IRQ8 = 0x4000,*/
/*	E_LIBBSP_GPIO_MEGA_MEZA_SPI_SEL = 0x8000*/
/*} TE_LIBBSP_GPIO_DiscName;*/
/* defined in kcg_types.h */


typedef struct
{
   volatile  uint16_t GPDIR;
   volatile  uint16_t RESERVED1;
   volatile  uint16_t GPODR;
   volatile  uint16_t RESERVED2;
   volatile  uint16_t GPDAT;
   volatile  uint16_t RESERVED3;
   volatile  uint16_t GPIER;
   volatile  uint16_t RESERVED4;
   volatile  uint16_t GPIMR;
   volatile  uint16_t RESERVED5;
   volatile  uint16_t GPICR;
   volatile  uint16_t RESERVED6;
} TS_LIBBSP_GPIO_Reg;


/*==== Variables =======================================================================*/
// extern volatile TS_LIBBSP_GPIO_Reg* const V_GPIOReg;
/*==== Services =======================================================================*/

extern TE_LIBBSP_GPIO_AddrStatus LIBBSP_GPIO_Configure( void );
extern boolean_t LIBBSP_GPIO_Read( const TE_LIBBSP_GPIO_DiscName GPIO);
extern TE_LIBBSP_GPIO_Status LIBBSP_GPIO_Write( const TE_LIBBSP_GPIO_DiscName GPIO, const boolean_t State);

#endif /* LIBBSP_GPIO_H_ */
