#ifndef _BOOT_TCAHW_PIC_
#define _BOOT_TCAHW_PIC_

#include "LIBMCP_Types.h"
#include "LIBBSP_CCSR.h"

#define C_REG_PIC_CTPR_ADDRESS      (C_LIBBSP_CCSR_PIC + 0x00080ul)
#define C_REG_PIC_GCR_ADDRESS       (C_LIBBSP_CCSR_PIC + 0x01020ul)
#define C_REG_PIC_EIVPR_0_ADDRESS   (C_LIBBSP_CCSR_PIC + 0x10000ul) /* + (IRQn * 0x20) */
#define C_REG_PIC_EIDR_0_ADDRESS    (C_LIBBSP_CCSR_PIC + 0x10010ul) /* + (IRQn * 0x20) */
#define C_REG_PIC_IIVPR_0_ADDRESS   (C_LIBBSP_CCSR_PIC + 0x10200ul) /* + (IRQn * 0x20) */
#define C_REG_PIC_IIDR_0_ADDRESS    (C_LIBBSP_CCSR_PIC + 0x10210ul) /* + (IRQn * 0x20) */

typedef union
{
   struct
   {
      uint32_t          : 28;
      uint32_t TASKP    :  4; /* Task priority */
   } Fields;
   uint32_t Value;
} tu_PIC_CTPR_Register;

typedef union
{
   struct
   {
      uint32_t RST :  1; /* Reset */
      uint32_t     :  1;
      uint32_t M   :  1; /* Mode */
      uint32_t     : 29;
   } Fields;
   uint32_t Value;
} tu_PIC_GCR_Register;

typedef union
{
   struct
   {
      uint32_t MSK      :  1; /* Mask */
      uint32_t A        :  1; /* Activity (RO) */
      uint32_t          :  6;
      uint32_t P        :  1; /* Polarity */
      uint32_t S        :  1; /* Sense */
      uint32_t          :  2;
      uint32_t PRIORITY :  4; /* Priority */
      uint32_t VECTOR   : 16; /* Vector */
   } Fields;
   uint32_t Value;
} tu_PIC_EIVPR_Register;

typedef union
{
   struct
   {
      uint32_t EP  :  1; /* External signal */
      uint32_t CI0 :  1; /* Critical interrupt 0 */
      uint32_t CI1 :  1; /* Critical interrupt 1 */
      uint32_t     : 27;
      uint32_t P1  :  1; /* Processor core 1 */
      uint32_t P0  :  1; /* Processor core 0 */
   } Fields;
   uint32_t Value;
} tu_PIC_EIDR_Register;

typedef union
{
   struct
   {
      uint32_t MSK      :  1; /* Mask */
      uint32_t A        :  1; /* Activity (RO) */
      uint32_t          :  6;
      uint32_t P        :  1; /* Polarity */
      uint32_t          :  3;
      uint32_t PRIORITY :  4; /* Priority */
      uint32_t VECTOR   : 16; /* Vector */
   } Fields;
   uint32_t Value;
} tu_PIC_IIVPR_Register;

typedef union
{
   struct
   {
      uint32_t EP  :  1; /* External signal */
      uint32_t CI0 :  1; /* Critical interrupt 0 */
      uint32_t     : 29;
      uint32_t P0  :  1; /* Processor core 0 */
   } Fields;
   uint32_t Value;
} tu_PIC_IIDR_Register;

extern boolean_t BOOT_TCAHW_PIC(void);

#endif