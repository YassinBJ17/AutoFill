# Make does not offer a recursive wildcard function, so here's one:
rwildcard = $(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

# Configuration of the log head format
LOG := '\n'Log: `date +'%Y.%m.%d-%H:%M:%S'`

# Definition of the project build folders
DEP_DirName := Dependencies
EOC_DirName := EOC
HDR_DirName := Headers
HDE_DirName := Headers_Ext
ARC_DirName := Library
ARE_DirName := Library_Ext
OBJ_DirName := Objects
PRO_DirName := Procedure
SRC_DirName := Sources

UPPER_Lvl_Dir := ..

DEP_Dir := $(UPPER_Lvl_Dir)/$(DEP_DirName)
EOC_Dir := $(UPPER_Lvl_Dir)/$(EOC_DirName)
HDR_Dir := $(UPPER_Lvl_Dir)/$(HDR_DirName)
HDE_Dir := $(UPPER_Lvl_Dir)/$(HDE_DirName)
ARC_Dir := $(UPPER_Lvl_Dir)/$(ARC_DirName)
ARE_Dir := $(UPPER_Lvl_Dir)/$(ARE_DirName)
OBJ_Dir := $(UPPER_Lvl_Dir)/$(OBJ_DirName)
PRO_Dir := $(UPPER_Lvl_Dir)/$(PRO_DirName)
SRC_Dir := $(UPPER_Lvl_Dir)/$(SRC_DirName)

# Definition of the CSCI root folder
CSCI_Root := $(subst $(PRO_DirName),,$(CONF_Dir))

# Definition of the build options directory
EFS_BUILD_OPT_DIR ?= $(CSCI_Root)/$(UPPER_Lvl_Dir)/$(UPPER_Lvl_Dir)/Build_Options
BUILD_OPT_DIR     := $(subst \,/,$(EFS_BUILD_OPT_DIR))

# Include of the project configuration
include $(CONF_Dir)/Config.mk

# Definition of the include directive for compiler and assembler
ifeq (,$(INC_Folders))
   export INC_Folders := $(addprefix -I, $(shell find $(CSCI_Root) -type d -name $(HDR_DirName)) $(CSCI_Root)$(HDE_DirName))
endif

# SUB_layer definition
SUB_CSC_Recurs_List         := $(shell find $(UPPER_Lvl_Dir) -type d ! -name $(DEP_DirName) ! -name $(EOC_DirName) ! -name $(HDR_DirName) ! -name $(HDE_DirName) ! -name $(ARC_DirName) ! -name $(ARE_DirName) ! -name $(OBJ_DirName) ! -name $(PRO_DirName) ! -name $(SRC_DirName) ! -name ".." ! -name ".*" | sed 's/\.\.\/\..*//g' | sed 's/\.\.\///g')
SUB_CSC_List                := $(sort $(shell echo $(SUB_CSC_Recurs_List) | sed 's/\/[a-z;A-Z;0-9;_;/]*//g'))

SUB_CSC_All_Source_C_List   := $(foreach Sub_CSC, $(SUB_CSC_List), $(call rwildcard,$(UPPER_Lvl_Dir)/$(Sub_CSC)/,$(SRC_DirName)/*.c))
SUB_CSC_All_Source_ASM_List := $(foreach Sub_CSC, $(SUB_CSC_List), $(call rwildcard,$(UPPER_Lvl_Dir)/$(Sub_CSC)/,$(SRC_DirName)/*.s))
SUB_CSC_All_Source_List     := $(sort $(SUB_CSC_All_Source_C_List) $(SUB_CSC_All_Source_ASM_List))

SUB_CSC_All_Object_C_List   := $(subst $(SRC_DirName),$(OBJ_DirName),$(patsubst %.c,%.o,$(SUB_CSC_All_Source_C_List)))
SUB_CSC_All_Object_ASM_List := $(subst $(SRC_DirName),$(OBJ_DirName),$(patsubst %.s,%.o,$(SUB_CSC_All_Source_ASM_List)))
SUB_CSC_All_Object_List     := $(sort $(SUB_CSC_All_Object_C_List) $(SUB_CSC_All_Object_ASM_List))

SUB_CSC_With_Archive_List   := $(subst /,,$(sort $(foreach Sub_CSC, $(SUB_CSC_List), $(findstring /$(Sub_CSC)/,$(SUB_CSC_All_Source_List)))))
SUB_CSC_Archive_List        := $(foreach Sub_CSC, $(SUB_CSC_With_Archive_List), $(UPPER_Lvl_Dir)/$(Sub_CSC)/$(ARC_DirName)/$(Sub_CSC).a)
SUB_CSC_Archive_List_Cmd    := $(SUB_CSC_Archive_List)

SUB_CSC_R_With_Archive_List := $(sort $(foreach Sub_CSC, $(SUB_CSC_Recurs_List), $(findstring $(Sub_CSC),$(SUB_CSC_All_Source_List))))
SUB_CSC_R_Archive_List      := $(foreach Sub_CSC, $(SUB_CSC_R_With_Archive_List), $(UPPER_Lvl_Dir)/$(Sub_CSC)/$(ARC_DirName)/$(shell echo $(Sub_CSC) | sed 's/[a-z;A-Z;0-9;_]*\///g').a)

EXT_Archive_List            := $(sort $(wildcard $(ARE_Dir)/*.a))
EXT_Archive_List_Cmd        := $(EXT_Archive_List)

SUB_CSC_makefile_Path_List  := $(addprefix $(UPPER_Lvl_Dir)/, $(addsuffix /$(PRO_DirName), $(SUB_CSC_List)))

# Sources Code files list (C and ASM)
SRC_C   := $(sort $(wildcard $(SRC_Dir)/*.c))
SRC_ASM := $(sort $(wildcard $(SRC_Dir)/*.s))

# Generated Dependencies files list (DEP of C and DEP of ASM)
OUT_DEP_C   := $(subst $(SRC_DirName),$(DEP_DirName),$(patsubst %.c,%.d,$(SRC_C)))
OUT_DEP_ASM := $(subst $(SRC_DirName),$(DEP_DirName),$(patsubst %.s,%.d,$(SRC_ASM)))

# Generated Assembler files list (ASM from C)
OUT_ASM_C := $(subst $(SRC_DirName),$(OBJ_DirName),$(patsubst %.c,%.s,$(SRC_C)))

# Generated Ojbects Code files lists (OBJ from C and OBJ from ASM)
OUT_OBJ_C   := $(subst $(SRC_DirName),$(OBJ_DirName),$(patsubst %.c,%.o,$(SRC_C)))
OUT_OBJ_ASM := $(subst $(SRC_DirName),$(OBJ_DirName),$(patsubst %.s,%.o,$(SRC_ASM)))

# Generated Listing files lists (LST from C and LST from ASM)
OUT_LST_C   := $(subst $(SRC_DirName),$(OBJ_DirName),$(patsubst %.c,%.lst,$(SRC_C)))
OUT_LST_ASM := $(subst $(SRC_DirName),$(OBJ_DirName),$(patsubst %.s,%.lst,$(SRC_ASM)))

# Definition of the files lists for the clean target
Clean_DEP_List := $(sort $(call rwildcard,$(UPPER_Lvl_Dir)/,$(DEP_DirName)/*.d)   $(foreach Sub_CSC, $(SUB_CSC_List), $(call rwildcard,$(UPPER_Lvl_Dir)/$(Sub_CSC)/,$(DEP_DirName)/*.d)))
Clean_DBO_List := $(sort $(call rwildcard,$(UPPER_Lvl_Dir)/,$(OBJ_DirName)/*.dbo) $(foreach Sub_CSC, $(SUB_CSC_List), $(call rwildcard,$(UPPER_Lvl_Dir)/$(Sub_CSC)/,$(OBJ_DirName)/*.dbo)))
Clean_LST_List := $(sort $(call rwildcard,$(UPPER_Lvl_Dir)/,$(OBJ_DirName)/*.lst) $(foreach Sub_CSC, $(SUB_CSC_List), $(call rwildcard,$(UPPER_Lvl_Dir)/$(Sub_CSC)/,$(OBJ_DirName)/*.lst)))
Clean_OBJ_List := $(sort $(call rwildcard,$(UPPER_Lvl_Dir)/,$(OBJ_DirName)/*.o)   $(foreach Sub_CSC, $(SUB_CSC_List), $(call rwildcard,$(UPPER_Lvl_Dir)/$(Sub_CSC)/,$(OBJ_DirName)/*.o)))
Clean_ARC_List := $(sort $(call rwildcard,$(UPPER_Lvl_Dir)/,$(ARC_DirName)/*.a)   $(foreach Sub_CSC, $(SUB_CSC_List), $(call rwildcard,$(UPPER_Lvl_Dir)/$(Sub_CSC)/,$(ARC_DirName)/*.a)))
