#ifndef DMA_REG_PRIVATE_H
#define DMA_REG_PRIVATE_H
/* --------------------------------------------------------------------------
 *                           Sagem Defense Securite
 *                               SAFRAN Group
 * --------------------------------------------------------------------------
 * PROJECT : CHRONOS
 * CSU name :
 * %name: DMA_REG_common.h %
 * %full_name: fadex#8/incl/DMA_REG_common.h/1 %
 *
 * Creation information:
 *   Created by: F073297
 *   Date : Thu May 31 09:54:58 CEST 2018
 *
 * Modification information:
 *   %derived_by: F605763 %
 *   %date_created:Thu May 12 18:18:11 CEST 2022 %
 * --------------------------------------------------------------------------
 * SAGEM Defense Securite document. Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


/* ---------- include required interface: ----------------------------------- */
#include "CMN_TYPES_common.h"

/* ---------- provided define constants: ------------------------------------ */
/* MPC577 DMA register address      */
#define DMA_0_REG_ADDR   (ts_DMA_REG volatile *)0xFC0A0000          /* eDMA_0  */
#define DMA_1_REG_ADDR   (ts_DMA_REG volatile *)0xFC0A4000          /* eDMA_1  */
/* MPC577 DMA MUX register address  */
#define DMA_MUX_0_REG_ADDR   (ts_DMA_MUX_REG volatile *) 0xFFF6C000          /* MUX_0   */
#define DMA_MUX_1_REG_ADDR   (ts_DMA_MUX_REG volatile *) 0xFFF6C200          /* MUX_1   */
#define DMA_MUX_2_REG_ADDR   (ts_DMA_MUX_REG volatile *) 0xFFF6C400          /* MUX_2   */
#define DMA_MUX_3_REG_ADDR   (ts_DMA_MUX_REG volatile *) 0xFFF6C600          /* MUX_3   */
#define DMA_MUX_4_REG_ADDR   (ts_DMA_MUX_REG volatile *) 0xFFF6C800          /* MUX_4   */
#define DMA_MUX_5_REG_ADDR   (ts_DMA_MUX_REG volatile *) 0xFFF6CA00          /* MUX_5   */
#define DMA_MUX_6_REG_ADDR   (ts_DMA_MUX_REG volatile *) 0xFFF6CC00          /* MUX_6   */
#define DMA_MUX_7_REG_ADDR   (ts_DMA_MUX_REG volatile *) 0xFFF6CE00          /* MUX_7   */
#define DMA_MUX_8_REG_ADDR   (ts_DMA_MUX_REG volatile *) 0xFFF6D000          /* MUX_8   */
#define DMA_MUX_9_REG_ADDR   (ts_DMA_MUX_REG volatile *) 0xFFF6D200          /* MUX_9   */

/* ---------- provided types: ----------------------------------------------- */
/* {{RELAX<SYNCHRONe_C_Code_8.2,SYNCHRONe_C_Code_6.6, SYNCHRONe_C_Code_24.5, SYNCHRONe_C_Code_5.4> Register definition and it is compliant with the register template */
/* {{RELAX<SYNCHRONe_C_Code_8.17> All MPC5777M register are fully defined even if there are not used. */
/* {{RELAX<SYNCHRONe_C_Code_6.4> Bitfield used are for Register definition. Deviation is acceptable. */
/* {{RELAX<SYNCHRONe_C_Code_7.2> all literal value are defined by the MPC5777M Reference manual */
typedef struct
{
   PACKED_U08 union
   {                             /* Channel Configuration register */
      reg8_t u_R;
      PACKED_U08 struct
      {
         reg8_t s_ENBL:1;   /* DMA Channel Enable */
         reg8_t s_TRIG:1;   /* DMA Channel Trigger Enable */
         reg8_t s_SOURCE:6; /* DMA Channel Source (Slot) */
      } u_B;

   } s_CHCFG[16];
} ts_DMA_MUX_REG;

typedef struct
{
   union
   {                             /* Control Register */
      reg32_t u_R;
      struct
      {
         reg32_t s_reserve2 :14;
         reg32_t s_CX:1;
         reg32_t s_ECX:1;
         reg32_t s_GRP3PRI:2;
         reg32_t s_GRP2PRI:2;
         reg32_t s_GRP1PRI:2;
         reg32_t s_GRP0PRI:2;
         reg32_t s_EMLM:1;
         reg32_t s_CLM:1;
         reg32_t s_HALT:1;
         reg32_t s_HOE:1;
         reg32_t s_ERGA:1;
         reg32_t s_ERCA:1;
         reg32_t s_EDBG:1;
         reg32_t s_reserve :1;
      } u_B;
   } s_CR;

   union
   {                             /* Error Status */
      reg32_t u_R;
      struct
      {
         reg32_t s_VLD:1;
         reg32_t s_reserve :13;
         reg32_t s_UCE:1;
         reg32_t s_ECX:1;
         reg32_t s_GPE:1;
         reg32_t s_CPE:1;
         reg32_t s_ERRCHN:6;
         reg32_t s_SAE:1;
         reg32_t s_SOE:1;
         reg32_t s_DAE:1;
         reg32_t s_DOE:1;
         reg32_t s_NCE:1;
         reg32_t s_SGE:1;
         reg32_t s_SBE:1;
         reg32_t s_DBE:1;
      } u_B;
   } s_ES;

   union
   {                             /* Enable Request Register High */
      reg32_t u_R;
      struct
      {
         reg32_t s_ERQ63:1;
         reg32_t s_ERQ62:1;
         reg32_t s_ERQ61:1;
         reg32_t s_ERQ60:1;
         reg32_t s_ERQ59:1;
         reg32_t s_ERQ58:1;
         reg32_t s_ERQ57:1;
         reg32_t s_ERQ56:1;
         reg32_t s_ERQ55:1;
         reg32_t s_ERQ54:1;
         reg32_t s_ERQ53:1;
         reg32_t s_ERQ52:1;
         reg32_t s_ERQ51:1;
         reg32_t s_ERQ50:1;
         reg32_t s_ERQ49:1;
         reg32_t s_ERQ48:1;
         reg32_t s_ERQ47:1;
         reg32_t s_ERQ46:1;
         reg32_t s_ERQ45:1;
         reg32_t s_ERQ44:1;
         reg32_t s_ERQ43:1;
         reg32_t s_ERQ42:1;
         reg32_t s_ERQ41:1;
         reg32_t s_ERQ40:1;
         reg32_t s_ERQ39:1;
         reg32_t s_ERQ38:1;
         reg32_t s_ERQ37:1;
         reg32_t s_ERQ36:1;
         reg32_t s_ERQ35:1;
         reg32_t s_ERQ34:1;
         reg32_t s_ERQ33:1;
         reg32_t s_ERQ32:1;
      } u_B;
   } s_ERQH;

   union
   {                             /* Enable Request Register Low */
      reg32_t u_R;
      struct
      {
         reg32_t s_ERQ31:1;
         reg32_t s_ERQ30:1;
         reg32_t s_ERQ29:1;
         reg32_t s_ERQ28:1;
         reg32_t s_ERQ27:1;
         reg32_t s_ERQ26:1;
         reg32_t s_ERQ25:1;
         reg32_t s_ERQ24:1;
         reg32_t s_ERQ23:1;
         reg32_t s_ERQ22:1;
         reg32_t s_ERQ21:1;
         reg32_t s_ERQ20:1;
         reg32_t s_ERQ19:1;
         reg32_t s_ERQ18:1;
         reg32_t s_ERQ17:1;
         reg32_t s_ERQ16:1;
         reg32_t s_ERQ15:1;
         reg32_t s_ERQ14:1;
         reg32_t s_ERQ13:1;
         reg32_t s_ERQ12:1;
         reg32_t s_ERQ11:1;
         reg32_t s_ERQ10:1;
         reg32_t s_ERQ9:1;
         reg32_t s_ERQ8:1;
         reg32_t s_ERQ7:1;
         reg32_t s_ERQ6:1;
         reg32_t s_ERQ5:1;
         reg32_t s_ERQ4:1;
         reg32_t s_ERQ3:1;
         reg32_t s_ERQ2:1;
         reg32_t s_ERQ1:1;
         reg32_t s_ERQ0:1;
      } u_B;
   } s_ERQL;

   union
   {                             /* Enable Error Interrupt Register High */
      reg32_t u_R;
      struct
      {
         reg32_t s_EEI63:1;
         reg32_t s_EEI62:1;
         reg32_t s_EEI61:1;
         reg32_t s_EEI60:1;
         reg32_t s_EEI59:1;
         reg32_t s_EEI58:1;
         reg32_t s_EEI57:1;
         reg32_t s_EEI56:1;
         reg32_t s_EEI55:1;
         reg32_t s_EEI54:1;
         reg32_t s_EEI53:1;
         reg32_t s_EEI52:1;
         reg32_t s_EEI51:1;
         reg32_t s_EEI50:1;
         reg32_t s_EEI49:1;
         reg32_t s_EEI48:1;
         reg32_t s_EEI47:1;
         reg32_t s_EEI46:1;
         reg32_t s_EEI45:1;
         reg32_t s_EEI44:1;
         reg32_t s_EEI43:1;
         reg32_t s_EEI42:1;
         reg32_t s_EEI41:1;
         reg32_t s_EEI40:1;
         reg32_t s_EEI39:1;
         reg32_t s_EEI38:1;
         reg32_t s_EEI37:1;
         reg32_t s_EEI36:1;
         reg32_t s_EEI35:1;
         reg32_t s_EEI34:1;
         reg32_t s_EEI33:1;
         reg32_t s_EEI32:1;
      } u_B;
   } s_EEIH;

   union
   {                             /* Enable Error Interrupt Register Low */
      reg32_t u_R;
      struct
      {
         reg32_t s_EEI31:1;
         reg32_t s_EEI30:1;
         reg32_t s_EEI29:1;
         reg32_t s_EEI28:1;
         reg32_t s_EEI27:1;
         reg32_t s_EEI26:1;
         reg32_t s_EEI25:1;
         reg32_t s_EEI24:1;
         reg32_t s_EEI23:1;
         reg32_t s_EEI22:1;
         reg32_t s_EEI21:1;
         reg32_t s_EEI20:1;
         reg32_t s_EEI19:1;
         reg32_t s_EEI18:1;
         reg32_t s_EEI17:1;
         reg32_t s_EEI16:1;
         reg32_t s_EEI15:1;
         reg32_t s_EEI14:1;
         reg32_t s_EEI13:1;
         reg32_t s_EEI12:1;
         reg32_t s_EEI11:1;
         reg32_t s_EEI10:1;
         reg32_t s_EEI9:1;
         reg32_t s_EEI8:1;
         reg32_t s_EEI7:1;
         reg32_t s_EEI6:1;
         reg32_t s_EEI5:1;
         reg32_t s_EEI4:1;
         reg32_t s_EEI3:1;
         reg32_t s_EEI2:1;
         reg32_t s_EEI1:1;
         reg32_t s_EEI0:1;
      } u_B;
   } s_EEIL;

   PACKED_U08 union
   {                             /* Set Enable Request Register */
      reg8_t u_R;
      PACKED_U08 struct
      {
         reg8_t s_NOP:1;
         reg8_t s_SAER:1;
         reg8_t s_SERQ:6;
      } u_B;
   } s_SERQ;

   PACKED_U08 union
   {                             /* Clear Enable Request Register */
      reg8_t u_R;
      PACKED_U08 struct
      {
         reg8_t s_NOP:1;
         reg8_t s_CAER:1;
         reg8_t s_CERQ:6;
      } u_B;
   } s_CERQ;

   PACKED_U08 union
   {                             /* Set Enable Error Interrupt Register */
      reg8_t u_R;
      PACKED_U08 struct
      {
         reg8_t s_NOP:1;
         reg8_t s_SAEE:1;
         reg8_t s_SEEI:6;
      } u_B;
   } s_SEEI;

   PACKED_U08 union
   {                             /* Clear Enable Error Interrupt Register */
      reg8_t u_R;
      PACKED_U08 struct
      {
         reg8_t s_NOP:1;
         reg8_t s_CAEE:1;
         reg8_t s_CEEI:6;
      } u_B;
   } s_CEEI;

   PACKED_U08 union
   {                             /* Clear Interrupt Request Register */
      reg8_t u_R;
      PACKED_U08 struct
      {
         reg8_t s_NOP:1;
         reg8_t s_CAIR:1;
         reg8_t s_CINT:6;
      } u_B;
   } s_CINT;

   PACKED_U08 union
   {                             /* Clear Error Register */
      reg8_t u_R;
      PACKED_U08 struct
      {
         reg8_t s_NOP:1;
         reg8_t s_CAEI:1;
         reg8_t s_CERR:6;
      } u_B;
   } s_CERR;

   PACKED_U08 union
   {                             /* Set s_START Bit Register */
      reg8_t u_R;
      PACKED_U08 struct
      {
         reg8_t s_NOP:1;
         reg8_t s_SAST:1;
         reg8_t s_SSRT:6;
      } u_B;
   } s_SSRT;

   PACKED_U08 union
   {                             /* Clear s_DONE Status Bit Register */
      reg8_t u_R;
      PACKED_U08 struct
      {
         reg8_t s_NOP:1;
         reg8_t s_CADN:1;
         reg8_t s_CDNE:6;
      } u_B;
   } s_CDNE;

   union
   {                             /* Interrupt Request Register High */
      reg32_t u_R;
      struct
      {
         reg32_t s_INT63:1;
         reg32_t s_INT62:1;
         reg32_t s_INT61:1;
         reg32_t s_INT60:1;
         reg32_t s_INT59:1;
         reg32_t s_INT58:1;
         reg32_t s_INT57:1;
         reg32_t s_INT56:1;
         reg32_t s_INT55:1;
         reg32_t s_INT54:1;
         reg32_t s_INT53:1;
         reg32_t s_INT52:1;
         reg32_t s_INT51:1;
         reg32_t s_INT50:1;
         reg32_t s_INT49:1;
         reg32_t s_INT48:1;
         reg32_t s_INT47:1;
         reg32_t s_INT46:1;
         reg32_t s_INT45:1;
         reg32_t s_INT44:1;
         reg32_t s_INT43:1;
         reg32_t s_INT42:1;
         reg32_t s_INT41:1;
         reg32_t s_INT40:1;
         reg32_t s_INT39:1;
         reg32_t s_INT38:1;
         reg32_t s_INT37:1;
         reg32_t s_INT36:1;
         reg32_t s_INT35:1;
         reg32_t s_INT34:1;
         reg32_t s_INT33:1;
         reg32_t s_INT32:1;
      } u_B;
   } s_INTH;

   union
   {                             /* Interrupt Request Register Low */
      reg32_t u_R;
      struct
      {
         reg32_t s_INT31:1;
         reg32_t s_INT30:1;
         reg32_t s_INT29:1;
         reg32_t s_INT28:1;
         reg32_t s_INT27:1;
         reg32_t s_INT26:1;
         reg32_t s_INT25:1;
         reg32_t s_INT24:1;
         reg32_t s_INT23:1;
         reg32_t s_INT22:1;
         reg32_t s_INT21:1;
         reg32_t s_INT20:1;
         reg32_t s_INT19:1;
         reg32_t s_INT18:1;
         reg32_t s_INT17:1;
         reg32_t s_INT16:1;
         reg32_t s_INT15:1;
         reg32_t s_INT14:1;
         reg32_t s_INT13:1;
         reg32_t s_INT12:1;
         reg32_t s_INT11:1;
         reg32_t s_INT10:1;
         reg32_t s_INT9:1;
         reg32_t s_INT8:1;
         reg32_t s_INT7:1;
         reg32_t s_INT6:1;
         reg32_t s_INT5:1;
         reg32_t s_INT4:1;
         reg32_t s_INT3:1;
         reg32_t s_INT2:1;
         reg32_t s_INT1:1;
         reg32_t s_INT0:1;
      } u_B;
   } s_INTL;

   union
   {                             /* Error Register High */
      reg32_t u_R;
      struct
      {
         reg32_t s_ERR63:1;
         reg32_t s_ERR62:1;
         reg32_t s_ERR61:1;
         reg32_t s_ERR60:1;
         reg32_t s_ERR59:1;
         reg32_t s_ERR58:1;
         reg32_t s_ERR57:1;
         reg32_t s_ERR56:1;
         reg32_t s_ERR55:1;
         reg32_t s_ERR54:1;
         reg32_t s_ERR53:1;
         reg32_t s_ERR52:1;
         reg32_t s_ERR51:1;
         reg32_t s_ERR50:1;
         reg32_t s_ERR49:1;
         reg32_t s_ERR48:1;
         reg32_t s_ERR47:1;
         reg32_t s_ERR46:1;
         reg32_t s_ERR45:1;
         reg32_t s_ERR44:1;
         reg32_t s_ERR43:1;
         reg32_t s_ERR42:1;
         reg32_t s_ERR41:1;
         reg32_t s_ERR40:1;
         reg32_t s_ERR39:1;
         reg32_t s_ERR38:1;
         reg32_t s_ERR37:1;
         reg32_t s_ERR36:1;
         reg32_t s_ERR35:1;
         reg32_t s_ERR34:1;
         reg32_t s_ERR33:1;
         reg32_t s_ERR32:1;
      } u_B;
   } s_ERRH;

   union
   {                             /* Error Register Low */
      reg32_t u_R;
      struct
      {
         reg32_t s_ERR31:1;
         reg32_t s_ERR30:1;
         reg32_t s_ERR29:1;
         reg32_t s_ERR28:1;
         reg32_t s_ERR27:1;
         reg32_t s_ERR26:1;
         reg32_t s_ERR25:1;
         reg32_t s_ERR24:1;
         reg32_t s_ERR23:1;
         reg32_t s_ERR22:1;
         reg32_t s_ERR21:1;
         reg32_t s_ERR20:1;
         reg32_t s_ERR19:1;
         reg32_t s_ERR18:1;
         reg32_t s_ERR17:1;
         reg32_t s_ERR16:1;
         reg32_t s_ERR15:1;
         reg32_t s_ERR14:1;
         reg32_t s_ERR13:1;
         reg32_t s_ERR12:1;
         reg32_t s_ERR11:1;
         reg32_t s_ERR10:1;
         reg32_t s_ERR9:1;
         reg32_t s_ERR8:1;
         reg32_t s_ERR7:1;
         reg32_t s_ERR6:1;
         reg32_t s_ERR5:1;
         reg32_t s_ERR4:1;
         reg32_t s_ERR3:1;
         reg32_t s_ERR2:1;
         reg32_t s_ERR1:1;
         reg32_t s_ERR0:1;
      } u_B;
   } s_ERRL;

   union
   {                             /* Hardware Request Status Register High */
      reg32_t u_R;
      struct
      {
         reg32_t s_HRS63:1;
         reg32_t s_HRS62:1;
         reg32_t s_HRS61:1;
         reg32_t s_HRS60:1;
         reg32_t s_HRS59:1;
         reg32_t s_HRS58:1;
         reg32_t s_HRS57:1;
         reg32_t s_HRS56:1;
         reg32_t s_HRS55:1;
         reg32_t s_HRS54:1;
         reg32_t s_HRS53:1;
         reg32_t s_HRS52:1;
         reg32_t s_HRS51:1;
         reg32_t s_HRS50:1;
         reg32_t s_HRS49:1;
         reg32_t s_HRS48:1;
         reg32_t s_HRS47:1;
         reg32_t s_HRS46:1;
         reg32_t s_HRS45:1;
         reg32_t s_HRS44:1;
         reg32_t s_HRS43:1;
         reg32_t s_HRS42:1;
         reg32_t s_HRS41:1;
         reg32_t s_HRS40:1;
         reg32_t s_HRS39:1;
         reg32_t s_HRS38:1;
         reg32_t s_HRS37:1;
         reg32_t s_HRS36:1;
         reg32_t s_HRS35:1;
         reg32_t s_HRS34:1;
         reg32_t s_HRS33:1;
         reg32_t s_HRS32:1;
      } u_B;
   } s_HRSH;

   union
   {                             /* Hardware Request Status Register Low */
      reg32_t u_R;
      struct
      {
         reg32_t s_HRS31:1;
         reg32_t s_HRS30:1;
         reg32_t s_HRS29:1;
         reg32_t s_HRS28:1;
         reg32_t s_HRS27:1;
         reg32_t s_HRS26:1;
         reg32_t s_HRS25:1;
         reg32_t s_HRS24:1;
         reg32_t s_HRS23:1;
         reg32_t s_HRS22:1;
         reg32_t s_HRS21:1;
         reg32_t s_HRS20:1;
         reg32_t s_HRS19:1;
         reg32_t s_HRS18:1;
         reg32_t s_HRS17:1;
         reg32_t s_HRS16:1;
         reg32_t s_HRS15:1;
         reg32_t s_HRS14:1;
         reg32_t s_HRS13:1;
         reg32_t s_HRS12:1;
         reg32_t s_HRS11:1;
         reg32_t s_HRS10:1;
         reg32_t s_HRS9:1;
         reg32_t s_HRS8:1;
         reg32_t s_HRS7:1;
         reg32_t s_HRS6:1;
         reg32_t s_HRS5:1;
         reg32_t s_HRS4:1;
         reg32_t s_HRS3:1;
         reg32_t s_HRS2:1;
         reg32_t s_HRS1:1;
         reg32_t s_HRS0:1;
      } u_B;
   } s_HRSL;

   reg8_t s_eDMA_reserved0[200];

   PACKED_U08 union
   {                             /* Channel Priority Register */
      reg8_t u_R;
      PACKED_U08 struct
      {
         reg8_t s_ECP:1;
         reg8_t s_DPA:1;
         reg8_t s_GRPPRI:2;
         reg8_t s_CHPRI:4;
      } u_B;
   } s_DCHPRI[64];

   PACKED_U08 union
   {                             /* Channel Master ID Register */
      reg8_t u_R;
      PACKED_U08 struct
      {
         reg8_t s_EMI:1;
         reg8_t s_PAL:1;
         reg8_t s_reserve :2;
         reg8_t s_MID:4;
      } u_B;
   } s_DCHMID[64];

   reg8_t s_eDMA_reserved1[3712];
   struct
   {
      union
      {                          /* s_TCD Source Address */
         reg32_t u_R;
         struct
         {
            reg32_t s_SADDR:32;
         } u_B;
      } s_SADDR;
      PACKED_U16 union
      {                          /* s_TCD Transfer Attributes */
         reg16_t u_R;
         PACKED_U16 struct
         {
            reg16_t s_SMOD:5;
            reg16_t s_SSIZE:3;
            reg16_t s_DMOD:5;
            reg16_t s_DSIZE:3;
         } u_B;
      } s_ATTR;
      PACKED_U16 union
      {                          /* s_TCD Signed Source Address Offset */
         reg16_t u_R;
         PACKED_U16 struct
         {
            reg16_t s_SOFF:16;
         } u_B;
      } s_SOFF;
      union
      {
         union
         {                       /* s_TCD Minor Byte Count Minor Loop Disabled */
            reg32_t u_R;
            struct
            {
               reg32_t s_NBYTES:32;
            } u_B;
         } u_MLNO;
         union
         {                       /* s_TCD Signed Minor Loop Offset Minor Loop Enabled and Offset Disabled */
            reg32_t u_R;
            struct
            {
               reg32_t s_SMLOE:1;
               reg32_t s_DMLOE:1;
               reg32_t s_NBYTES:30;
            } u_B;
         } u_MLOFFNO;
         union
         {                       /* s_TCD Signed Minor Loop Offset Minor Loop and Offset Enabled */
            reg32_t u_R;
            struct
            {
               reg32_t s_SMLOE:1;
               reg32_t s_DMLOE:1;
               reg32_t s_MLOFF:20;
               reg32_t s_NBYTES:10;
            } u_B;
         } u_MLOFFYES;
      } s_NBYTES;
      union
      {                          /* s_TCD Last Source Address Adjustment */
         reg32_t u_R;
         struct
         {
            reg32_t s_SLAST:32;
         } u_B;
      } s_SLAST;
      union
      {                          /* s_TCD Destination Address */
         reg32_t u_R;
         struct
         {
            reg32_t s_DADDR:32;
         } u_B;
      } s_DADDR;
      PACKED_U16 union
      {
         PACKED_U16 union
         {                       /* s_TCD Current Minor Loop Link, Major Loop Count Channel Linking Disabled */
            reg16_t u_R;
            PACKED_U16 struct
            {
               reg16_t s_ELINK:1;
               reg16_t s_CITER:15;
            } u_B;
         } u_ELINKNO;
         PACKED_U16 union
         {                       /* s_TCD Current Minor Loop Link, Major Loop Count Channel Linking Enabled */
            reg16_t u_R;
            PACKED_U16 struct
            {
               reg16_t s_ELINK:1;
               reg16_t s_LINKCH:6;
               reg16_t s_CITER:9;
            } u_B;
         } u_ELINKYES;
      } s_CITER;
      PACKED_U16 union
      {                          /* s_TCD Signed Destination Address Offset */
         reg16_t u_R;
         PACKED_U16 struct
         {
            reg16_t s_DOFF:16;
         } u_B;
      } s_DOFF;
      union
      {                          /* s_TCD Last Destination Address Adjustment/Scatter Gather Address */
         reg32_t u_R;
         struct
         {
            reg32_t s_DLASTSGA:32;
         } u_B;
      } s_DLASTSGA;
      PACKED_U16 union
      {
         PACKED_U16 union
         {                       /* s_TCD Beginning Minor Loop Link, Major Loop Count Channel Linking Disabled */
            reg16_t u_R;
            PACKED_U16 struct
            {
               reg16_t s_ELINK:1;
               reg16_t s_BITER:15;
            } u_B;
         } u_ELINKNO;
         PACKED_U16 union
         {                       /* s_TCD Beginning Minor Loop Link, Major Loop Count Channel Linking Enabled */
            reg16_t u_R;
            PACKED_U16 struct
            {
               reg16_t s_ELINK:1;
               reg16_t s_LINKCH:6;
               reg16_t s_BITER:9;
            } u_B;
         } u_ELINKYES;
      } s_BITER;
      PACKED_U16 union
      {                          /* s_TCD Control and Status */
         reg16_t u_R;
         PACKED_U16 struct
         {
            reg16_t s_BWC:2;
            reg16_t s_MAJORLINKCH:6;
            reg16_t s_DONE:1;
            reg16_t s_ACTIVE:1;
            reg16_t s_MAJORELINK:1;
            reg16_t s_ESG:1;
            reg16_t s_DREQ:1;
            reg16_t s_INTHALF:1;
            reg16_t s_INTMAJOR:1;
            reg16_t s_START:1;
         } u_B;
      } s_CSR;
   } s_TCD[64];
}
ts_DMA_REG;
/* }}<SYNCHRONe_C_Code_8.2, SYNCHRONe_C_Code_6.6, SYNCHRONe_C_Code_24.5, SYNCHRONe_C_Code_5.4> */
/* }}<SYNCHRONe_C_Code_8.17> */
/* }}<SYNCHRONe_C_Code_6.4> */
/* }}<SYNCHRONe_C_Code_7.2> */

/* ---------- provided constants: ------------------------------------------- */
/* */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/* none */

#endif /* DMA_REG_PRIVATE_H */
