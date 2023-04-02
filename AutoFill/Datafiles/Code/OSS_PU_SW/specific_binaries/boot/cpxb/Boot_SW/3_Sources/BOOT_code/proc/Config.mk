# Configuration of the generated files name (without extension) for the CSCI/CSI (if <empty>, it is set to the project folder name)
CSCI_Name := BOOT

# Target definition
TARGET = -tPPCE200Z425BN3VFG

# Check availability of executables
#EXECUTABLES = create batch dcc das dld ddump objcopyppc ccc
#K := $(foreach exec,$(EXECUTABLES),\
      $(if $(shell which $(exec)), $(eval EXIST_$(exec) := 1),$(warning "No $(exec) in PATH")))

#ifeq (,$(EXIST_create))
#RLC_CREATE :=
#RLC_BATCH :=
#else
# Kalimetrix
#RLC_VERSION := 4.3
#RLC_PROJ := $(CSCI_Root)/$(RLC_Dir)/$(CSCI_Name)/$(CSCI_Name)_project.ttp
#RLC_DEF := $(CSCI_Root)/$(RLC_Dir)/$(CSCI_Name)/$(CSCI_Name).def
#RLC_MAC := $(CSCI_Root)/$(RLC_Dir)/$(CSCI_Name)/$(CSCI_Name).mac
#RLC_RLCFS := C:/App/SYNCHRONe/RuleCheckerForSYNCHRONe/$(RLC_VERSION)/CRulesQualified/RuleSets/C
#RLC_RST_1 := $(RLC_RLCFS)/SYNCHRONe_CSCI.rst
#RLC_RST_2 := $(RLC_RLCFS)/SYNCHRONe_MCP_only.rst
#RLC_RST_3 := $(CSCI_Root)/$(RLC_Dir)/$(CSCI_Name)/$(CSCI_Name).rst
#RLC_IGN := $(CSCI_Root)/$(RLC_Dir)/$(CSCI_Name)/$(CSCI_Name).ign
#RLC_LOG := $(CSCI_Root)/$(RLC_Dir)/$(CSCI_Name)/Logiscope

#RLC_CREATE := create $(RLC_PROJ) -rule -lang c -def $(RLC_DEF) -mac $(RLC_MAC) -dial ansi -rules $(RLC_RST_1) -rules $(RLC_RST_2) -ign $(RLC_IGN) -rules $(RLC_RST_3) -relax --
#RLC_BATCH := batch
#endif


# ----------------------------
# WindRiver DiabData toolchain
# ----------------------------
# Compiler
#CC := $(RLC_CREATE) dcc
CC:= dcc
# Compiler options
# CC_Opt := $(TARGET) $(shell cat $(BUILD_OPT_DIR)/dcc_Wind_River_Compiler_MPC5777M.opt)
CC_Opt := $(TARGET) -@$(BUILD_OPT_DIR)/dcc_Wind_River_Compiler_MPC5777M.opt -D$(A665_VERSION) -DA665_NODATA_ADDR

# WindRiver DiabData Assembler
AS := das
# Assembler options
AS_Opt := $(TARGET) $(shell cat $(BUILD_OPT_DIR)/das_Wind_River_Compiler_MPC5777M.opt)

# WindRiver DiabData Linker
LD := dld
# Linker options
#LD_Opt := $(shell cat $(BUILD_OPT_DIR)/dld_Wind_River_Compiler_MPC5777M.opt) -@"$(BUILD_OPT_DIR)/dld_Wind_River_Compiler_MPC5777M_StdLib.opt"
LD_Opt := $(TARGET) $(shell cat $(BUILD_OPT_DIR)/dld_Wind_River_Compiler_MPC5777M.opt)
# Library to be used
#LD_Lib := -lc $(TARGET)
LD_Lib :=
# Linker Command File
LD_Dld := $(CONF_Dir)/link-$(CSCI_Name).dld

# WindRiver DiabData Archiver
AR := dar
# Archiver options
AR_Opt := $(shell cat $(BUILD_OPT_DIR)/dar_Wind_River_Compiler_MPC5777M.opt)

# WindRiver DiabData Dumper
DUMP := ddump
# Dumper options for converting elf into abs
DD_Opt := $(shell cat $(BUILD_OPT_DIR)/ddump_Wind_River_Compiler_MPC5777M.opt)

# WindRiver DiabData LUP creator
LUP := objcopyppc
# LUP options for converting abs into lup
LUP_Opt := $(shell cat $(BUILD_OPT_DIR)/objcopyppc.opt)


# Safran Electronics & Defense CCC tool
CCC := $(CCC_TOOL)/ccc
# CCC file configurations
CCC_Conf :=
CCC_Xml := $(CONF_Dir)/$(CSCI_Name)_ccc.xml
# CCC options
CCC_Opt :=__CARTOUCHE_START

SREC2BIN := $(SREC_TOOLS)/srec2bin.exe -q
BIN2SREC := $(SREC_TOOLS)/bin2srec.exe -q

# Errata processor E010385 checker
E010385_CHECKER := $(E010385_ERRATA_E2004_TOOL)/branch_displacement_erratum_10385_checker.exe
E010385_CHECKER_LOG := $(EOC_Dir)/branch_displacement_erratum_10385_checker.txt

# Configuration of data to clean (Possible choices: one or several separated by space 'Dependencies Objects Libraries Binaries')
DATA_To_Clean := $(DEP_DirName) $(OBJ_DirName) $(ARC_DirName) $(EOC_DirName)
ifeq (,$(EXIST_create))
DATA_To_Clean += RLCReports
endif

# Configuration to make or not an archive for the CSCI/CSI (Possible choices: <empty> or 'archive_CSCI')
CONF_CSCI_Archive := archive_CSCI

# Configuration to make or not an EOC for the CSCI/CSI and to define the final one (Possible choices: <empty> | 'link' | 'srecord' | 'load' | 'srecord_s19' | 'load_ccc')
CONF_CSCI_EOC := link
