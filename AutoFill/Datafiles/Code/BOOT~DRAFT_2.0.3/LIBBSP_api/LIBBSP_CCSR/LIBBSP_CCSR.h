/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/

/*==== Definitions =====================================================================*/
#ifndef LIBBSP_CCSR_H
#define LIBBSP_CCSR_H

#include "LIBMCP_Types.h"


#define C_LIBBSP_CCSR_START             0xFF700000ul
#define C_LIBBSP_CCSR_I2C_DELTA         0x00003000ul
#define C_LIBBSP_CCSR_ELBC_DELTA        0x00005000ul
#define C_LIBBSP_CCSR_SPI_DELTA         0x00007000ul
#define C_LIBBSP_CCSR_GPIO_DELTA        0x0000F000ul
#define C_LIBBSP_CCSR_ECCMEM_L2S_DELTA  0x00020000ul
#define C_LIBBSP_CCSR_ECCMEM_DDR_DELTA  0x00002000ul
#define C_LIBBSP_CCSR_FNAND_DELTA       0x0002E000ul
#define C_LIBBSP_CCSR_GUTS_DELTA        0x000E0000ul
#define C_LIBBSP_CCSR_PIC_DELTA         0x00040000ul
#define C_LIBBSP_CCSR_LAW_DELTA         0x00000C00ul

#define C_LIBBSP_CCSR_I2C               (C_LIBBSP_CCSR_START+C_LIBBSP_CCSR_I2C_DELTA)
#define C_LIBBSP_CCSR_ELBC              (C_LIBBSP_CCSR_START+C_LIBBSP_CCSR_ELBC_DELTA)
#define C_LIBBSP_CCSR_SPI               (C_LIBBSP_CCSR_START+C_LIBBSP_CCSR_SPI_DELTA)
#define C_LIBBSP_CCSR_GPIO              (C_LIBBSP_CCSR_START+C_LIBBSP_CCSR_GPIO_DELTA)
#define C_LIBBSP_CCSR_ECCMEM_L2S        (C_LIBBSP_CCSR_START+C_LIBBSP_CCSR_ECCMEM_L2S_DELTA)
#define C_LIBBSP_CCSR_ECCMEM_DDR        (C_LIBBSP_CCSR_START+C_LIBBSP_CCSR_ECCMEM_DDR_DELTA)
#define C_LIBBSP_CCSR_FNAND             (C_LIBBSP_CCSR_START+C_LIBBSP_CCSR_FNAND_DELTA)
#define C_LIBBSP_CCSR_GUTS              (C_LIBBSP_CCSR_START+C_LIBBSP_CCSR_GUTS_DELTA)
#define C_LIBBSP_CCSR_PIC               (C_LIBBSP_CCSR_START+C_LIBBSP_CCSR_PIC_DELTA)
#define C_LIBBSP_CCSR_LAW               (C_LIBBSP_CCSR_START+C_LIBBSP_CCSR_LAW_DELTA)


/*==== Variables========================================================================*/


/*==== Services ========================================================================*/

    
/*==== END =============================================================================*/
#endif /* LIBBSP_CCSR_H */
