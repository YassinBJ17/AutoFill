/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_PQRFS_DEFINES_H
#define LIBBSP_PQRFS_DEFINES_H
#include "LIBBSP_PQRFS_Globals.h"

/*==== Definitions =====================================================================*/


#define C_LIBBSP_PQRFS_REG_PQR_CMD              (0x51E000)

#define C_LIBBSP_PQRFS_REG_C1_ERR_STS           (0x002804)
#define C_LIBBSP_PQRFS_REG_C2_ERR_STS           (0x002808)
#define C_LIBBSP_PQRFS_REG_C3_ERR_STS           (0x00280C)
#define C_LIBBSP_PQRFS_REG_C4_ERR_STS           (0x002810)
#define C_LIBBSP_PQRFS_REG_C1_ERR_DATA          (0x002814)
#define C_LIBBSP_PQRFS_REG_C2_ERR_DATA          (0x002818)
#define C_LIBBSP_PQRFS_REG_C3_ERR_DATA          (0x00281C)
#define C_LIBBSP_PQRFS_REG_C4_ERR_DATA          (0x002820)

#define C_BLADE_OFFSET                          (0x3C0000)

#define C_ADDR_DATA_TO_GET_C1                   (C_BLADE_OFFSET + 0xE8)
#define C_ADDR_DATA_TO_GET_C2                   (C_BLADE_OFFSET + 0x11C)
#define C_ADDR_DATA_TO_GET_C3                   (C_BLADE_OFFSET + 0x150)
#define C_ADDR_DATA_TO_GET_C4                   (C_BLADE_OFFSET + 0x184)

#define C_LIBBSP_PQRFS_OperationalMax_Address   (C_BLADE_OFFSET + 0x1B8)
#define C_LIBBSP_PQRFS_OperationalMin_Address   (C_BLADE_OFFSET + 0x200)
#define C_LIBBSP_PQRFS_LabelNumber_Address      (C_BLADE_OFFSET + 0x248)
#define C_LIBBSP_PQRFS_MSBLocation_Address      (C_BLADE_OFFSET + 0x290)
#define C_LIBBSP_PQRFS_LSBLocation_Address      (C_BLADE_OFFSET + 0x2D8)
#define C_LIBBSP_PQRFS_LSBValue_Address         (C_BLADE_OFFSET + 0x320)

#define C_DIFF_CN_to_CNp1                       (13)

#define C_ADDR_DATA_START_ITF                   (0x51F000)                      
#define C_ADDR_DATA_TIME_REF                    (C_ADDR_DATA_START_ITF + 0x4)
#define C_CYCLE_IDENTIFIER                      (C_ADDR_DATA_START_ITF + 0x8)
#define C_ADDR_DATA_ITF0                        (C_ADDR_DATA_START_ITF + 0xC)
#define C_ADDR_DATA_ITF13                       (C_ADDR_DATA_START_ITF + 0x40)
#define C_ADDR_SW_FAILURE                       (C_ADDR_DATA_START_ITF + 0x74)
#define C_ADDR_DATA_END_ITF                     (C_ADDR_DATA_START_ITF + 0x78)
#define C_ADDR_EN_DATA_CONSISTENCY              (C_ADDR_DATA_END_ITF + 0x4)
#define C_ITF_DATA_CONSISTENCY                  (0xE152A4CB)

#define C_TIC_DATA_ARINC_OFFSET                 (0x584)
#define C_RAM_TIC_OFFSET                        (0x300000)
#define C_RAM_TIC_DATA_START                    (C_RAM_TIC_OFFSET + 0x6100)

#define C_LIBBSP_PQRFS_ITF_Data_Start           (0x1)
#define C_LIBBSP_PQRFS_ITF_Data_End             (0x5)

#define C_LIBBSP_PQRFS_ITF_CI_12                (0x0C)
#define C_LIBBSP_PQRFS_ITF_CI_34                (0x22)



/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/*==== END =============================================================================*/
#endif