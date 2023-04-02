#/***********************************************************************************************************************
#*
#*                                                Safran Electronics & Defense
#*
#* _BEGIN_FILE_HEADER --------------------------------------------------------------------------------------------------
#*
#* File name  : RAMBOOT_Registers.s
#* CSC name   :
#* 
#* Description: Regisers interface CSU. 
#*
#* Configuration management identification:
#*    %full_name:  sknNEXT#1/ascii/ELBCBOOT_Registers.s/2 %
#*    Creation  :
#*
#* _END_FILE_HEADER ----------------------------------------------------------------------------------------------------
#*
#* LANGUAGE: ASM - Source file
#*
#* ---------------------------------------------------------------------------------------------------------------------
#* Copyright (c) 2017, SAFRAN E&D
# * SAFRAN Electronics & Defense document. Reproduction and disclosure forbidden.
#**********************************************************************************************************************/
   .file "ELBCBOOT_Registers.s"

#/* _BEGIN_INCLUDE ========================================== INCLUDE FILES ========================================== */
   .include "ELBCBOOT_Registers.inc"
#/* _END_INCLUDE ===================================================================================================== */

#/* _BEGIN_EXTERN_FUNCTION ========EXTERN FUNCTIONS DEFINITIONS ============ */
   .text

   .global REG_Init

#/* BEGIN FUNCTION HEADER--------------------------------------------------------------------------------------------- */
#/* <<LLR:  >>  SDD_DMS_LLR_REQ_0000020                                                                                */
#/*                                                                                                                    */
#/* <<FUNCTION:  >>  REG_Init                                                                                          */
#/*                                                                                                                    */
#/* <<DESCRIPTION:  >>  This function open TLB1 to allow access to every memory area.                                  */
#/*                                                                                                                    */
#/* END FUNCTION HEADER----------------------------------------------------------------------------------------------- */
REG_Init:
   lis     r3,0x1000
	lis     r4,0xC000
	ori     r4,r4,0x0B00
	li      r5,0x000E
	li      r6,0x0015
	li      r7,0x0000

   ; Write TLB entry
   mtspr    REG_MAS0,   r3
   mtspr    REG_MAS1,   r4
   mtspr    REG_MAS2,   r5
   mtspr    REG_MAS3,   r6
   mtspr    REG_MAS7,   r7
   REG_TLB_LOAD

   blr
#/*End of REG_Init */

#/* _END_EXTERN_FUNCTION ==================================================== */
