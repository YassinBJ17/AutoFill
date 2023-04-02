/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_SPI_IOCtrl.h"


/*==== Definitions =====================================================================*/
/* Standard define for quick configurations of SPCOM register.            */
/* These standard command words allow faster configuration of eSPI block. */
/* See P2020 user manual, espi section and  SPCOM register for complete   */
/* description. */

/* Constants for eSPI block to send an ammount of char */
/* #define C_SPI_SPCOM_TX_NORMAL_32CHAR 0x0800001F */

/* #define C_SPI_SPCOM_TX_NORMAL_6CHAR  0x08000005 */

/* #define C_SPI_SPCOM_TX_NORMAL_4CHAR  0x08000003 */

/* #define C_SPI_SPCOM_TX_NORMAL_2CHAR  0x08000001 */

/* #define C_SPI_SPCOM_TX_NORMAL_1CHAR  0x08000000 */

/* configure eSPI block to send 1 char (and skip it) and receive 1 */
/* #define C_SPI_SPCOM_RX_NORMAL_1CHAR  0x00010001*/

/* configure eSPI block to send 4 char (and skip them) and receive 2 */
/* #define C_SPI_SPCOM_RX_NORMAL_2CHAR  0x00040005*/

/* #define C_SPI_SHIFT_30_BITS 30 */

/* #define C_SPI_TIMEOUT_US 10 */
/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_SPI_ErrorCode LIBBSP_SPI_IOCtrl(const TE_LIBBSP_SPI_Device  SpiDevice,
                                          const TE_LIBBSP_SPI_Command SpiCmd,
                                          uint8_t *             const Buffer) /* %RELAX<  SYNCHRONe_C_Code_8.18> Used as parameter for subfunction and it can be Input or Output */
{
   /* uint32_t v_timeout ; */
   TE_LIBBSP_SPI_ErrorCode v_SpiErr;

   switch (SpiCmd)
   {
      case E_LIBBSP_SPI_WRITE6  :
         LIBBSP_SPI_Write6Bytes(SpiDevice, Buffer, &v_SpiErr);
         break;
      case E_LIBBSP_SPI_WRITE4  :
         LIBBSP_SPI_Write4Bytes(SpiDevice, Buffer, &v_SpiErr);
         break;
      case E_LIBBSP_SPI_WRITE2  :
         LIBBSP_SPI_Write2Bytes(SpiDevice, Buffer, &v_SpiErr);
         break;
      case E_LIBBSP_SPI_WRITE1  :
         LIBBSP_SPI_Write1Bytes(SpiDevice, Buffer, &v_SpiErr);
         break;
      case E_LIBBSP_SPI_READ2   :
         LIBBSP_SPI_Read2Bytes( SpiDevice, Buffer, &v_SpiErr);
         break;
      case E_LIBBSP_SPI_READ1   :
         LIBBSP_SPI_Read1Bytes( SpiDevice, Buffer, &v_SpiErr);
         break;
      default:
         v_SpiErr = E_LIBBSP_SPI_TIMEOUT_WRONG_CMD;
         break;
   }
   
   return v_SpiErr; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
/*==== END =============================================================================*/
