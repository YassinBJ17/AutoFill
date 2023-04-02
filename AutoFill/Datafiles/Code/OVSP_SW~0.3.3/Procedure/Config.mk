# Configuration of the generated files name (whithout extension) for the CSCI/CSI (if <empty>, it is set to the project folder name)
CSCI_Name := 

# Target definition
TARGET = -cpu=cortexm4f

# Compiler
CC := ccarm.exe
# Compiler options
CC_Opt := $(shell cat $(BUILD_OPT_DIR)/GHS_S32K_Compiler_Options.opt) $(shell cat $(BUILD_OPT_DIR)/GHS_S32K_Debug_Options.opt)


# Assembler
AS := asarm.exe
# Assembler options
AS_Opt := $(shell cat $(BUILD_OPT_DIR)/GHS_S32K_Assembler_Options.opt)


# Archiver
AR := ax.exe
# Archiver options
AR_Opt := $(shell cat $(BUILD_OPT_DIR)/GHS_S32K_Archiver_Options.opt)


# Linker
LD := elxr.exe
# Linker options
LD_Opt := $(shell cat $(BUILD_OPT_DIR)/GHS_S32K_Linker_Options.opt)
# Library to be used
LD_Lib := 
# Linker Command File
LD_Dld := $(CONF_Dir)/OVSP_SW.ld


# BIN creator
BIN := objcopyppc.exe
# BIN options for converting elf into bin
BIN_Opt := -I elf32-little -O binary


# Load creator
LUP := Compute_32-bit_CRC.exe
# Load options
LUP_Opt := 


# Configuration of data to clean (Possible choises: one or several separated by space 'Dependencies Objects Libraries Binaries')
DATA_To_Clean := Dependencies Objects Libraries Binaries

# Configuration to make or not an archive for the CSCI/CSI (Possible choises: <empty> or 'archive_CSCI')
CONF_CSCI_Archive := 

# Configuration to make or not an EOC for the CSCI/CSI and to define the final one (Possible choises: <empty> | 'link' | 'load')
CONF_CSCI_EOC := load
