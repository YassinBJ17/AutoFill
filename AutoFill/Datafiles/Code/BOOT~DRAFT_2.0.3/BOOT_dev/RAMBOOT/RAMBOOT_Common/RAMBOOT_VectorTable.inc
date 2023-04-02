#/***********************************************************************************************************************
#*
#*                                                Safran Electronics & Defense
#*                                                     SAFRAN Group
#*
#* _BEGIN_FILE_HEADER --------------------------------------------------------------------------------------------------
#*
#* File name  : RLB_RBI_VectorTable.P2020.inc
#* CSC name   :
#* 
#* Description: Vector Table CSU header file.
#*
#* Configuration management identification:
#*    %full_name:  sknNEXT#1/ascii/RAMBOOT_VectorTable.inc/1 %
#*    Creation  :
#*
#* _END_FILE_HEADER ----------------------------------------------------------------------------------------------------
#*
#* LANGUAGE: ASM - Header file
#*
#* ---------------------------------------------------------------------------------------------------------------------
#* Copyright (c) 2017, SAFRAN E&D
#* SAFRAN Electronics & Defense document. Reproduction and disclosure forbidden.
#**********************************************************************************************************************/

#/* _BEGIN_STATIC_PROTO ==================================== FUNCTION PROTOTYPES ===================================== */
#/* _END_STATIC_PROTO ================================================================================================ */

#/* _BEGIN_CONSTANT ============================================ CONSTANTS =========================================== */

	#/* HID0 init value, enable timer base */
	.set     C_HID0_INIT_VALUE     ,0x00004000

	#/* RAMBOOT MSR first configuration. Set SPE, ME and DE bits */
	.set     C_MSR_RAMBOOT_CONFIG      ,0x02001200

#/* _END_CONSTANT ==================================================================================================== */
