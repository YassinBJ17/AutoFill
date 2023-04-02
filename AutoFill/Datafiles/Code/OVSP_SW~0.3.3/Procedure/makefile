# Configuration of the CSCI/CSI top level
ifeq (,$(EFS_CSCI_PROC_DIR))
   export EFS_CSCI_PROC_DIR := $(shell pwd)
endif

CONF_Dir := $(subst \,/,$(EFS_CSCI_PROC_DIR))

# Include of the common definitions
include $(CONF_Dir)/Common_Def.mk

# Configuration of the CSCI
ifeq (,$(CSCI_Name))
   CSCI_Name := $(shell pwd | sed 's/\/$(PRO_DirName)//g' | sed 's/.*\///g')
endif

# Configuration of the Relative path to CSCI root in sed syntax
ToRootForSed := $(shell pwd | sed 's/.*\/$(CSCI_Name)\///g' | sed 's/[a-z;A-z;_;0-9]*\//\.\.\\\//g' | sed 's/$(PRO_DirName)/\.\.\\\//g')

CSCI_All_Object_List := $(sort $(OUT_OBJ_C) $(OUT_OBJ_ASM) $(SUB_CSC_All_Object_C_List) $(SUB_CSC_All_Object_ASM_List))

# CSCI C Sources Code files list (C)
CSCI_SRC_C := $(sort $(wildcard $(SRC_Dir)/*.c))

# CSCI generated Dependencies files list (DEP of C)
CSCI_DEP_C := $(subst $(SRC_DirName),$(DEP_DirName),$(patsubst %.c,%.d,$(CSCI_SRC_C)))

# Definition of the generated CSCI files (ARC, EXE, MAP, BIN, LUP)
ifeq (,$(CSCI_All_Object_List))
   OUT_ARC :=
   OUT_EXE :=
   OUT_MAP :=
   OUT_BIN :=
   OUT_LUP :=
else
   IN_LD   := $(PRO_Dir)/$(CSCI_Name).ld

   OUT_ARC := $(ARC_Dir)/$(CSCI_Name).a
   OUT_EXE := $(EOC_Dir)/$(CSCI_Name).elf
   OUT_MAP := $(EOC_Dir)/$(CSCI_Name).map
   OUT_BIN := $(EOC_Dir)/$(CSCI_Name).bin
   OUT_LUP := $(EOC_Dir)/$(CSCI_Name).lup
endif

# Definition of the EOC files list for the clean target
Clean_EOC_List := $(sort $(call rwildcard,$(EOC_Dir)/,$(CSCI_Name).*))

clean: ;
ifeq ($(DATA_To_Clean),)
	@echo -e $(LOG) 'Clean: no Data requested to be deleted in the configuration'
else

ifneq (,$(findstring Dependencies,$(DATA_To_Clean)))
ifneq ($(Clean_DEP_List),)
	@echo -e $(LOG) 'Clean: Delete of the generated Dependencies files'
	@echo -e 'rm -f $(Clean_DEP_List)'
	@rm -f $(Clean_DEP_List)
else
	@echo -e $(LOG) 'Clean: no Dependency file to delete'
endif
endif

ifneq (,$(findstring Objects,$(DATA_To_Clean)))
ifneq ($(Clean_DBO_List)$(Clean_LST_List)$(Clean_OBJ_List),)
	@echo -e $(LOG) 'Clean: Delete of the generated Listing and Object files'
	@echo -e 'rm -f $(Clean_DBO_List)'
	@rm -f $(Clean_DBO_List)
	@echo -e 'rm -f $(Clean_LST_List)'
	@rm -f $(Clean_LST_List)
	@echo -e 'rm -f $(Clean_OBJ_List)'
	@rm -f $(Clean_OBJ_List)
else
	@echo -e $(LOG) 'Clean: no generated Listing or Object file to delete'
endif
endif

ifneq (,$(findstring Libraries,$(DATA_To_Clean)))
ifneq ($(Clean_ARC_List),)
	@echo -e $(LOG) 'Clean: Delete of the generated Library files'
	@echo -e 'rm -f $(Clean_ARC_List)'
	@rm -f $(Clean_ARC_List)
else
	@echo -e $(LOG) 'Clean: no Library file to delete'
endif
endif

ifneq (,$(findstring Binaries,$(DATA_To_Clean)))
ifneq ($(Clean_EOC_List),)
	@echo -e $(LOG) 'Clean: Delete of the generated files related to the EOC'
	@echo -e 'rm -f $(Clean_EOC_List)'
	@rm -f $(Clean_EOC_List)
else
	@echo -e $(LOG) 'Clean: no file to delete related to the EOC'
endif
endif
endif

all: compile archive $(CONF_CSCI_EOC) ;

compile: $(OUT_DEP_C) $(OUT_LST_C) $(OUT_OBJ_C) $(OUT_DEP_ASM) $(OUT_LST_ASM) $(OUT_OBJ_ASM) ;

archive: sub_archive $(CONF_CSCI_Archive) ;

sub_archive: $(SUB_CSC_Archive_List) ;
	@$(foreach mymake, $(SUB_CSC_makefile_Path_List), ("$(MAKE)" -C $(mymake) archive);)

archive_CSCI: $(OUT_ARC) ;

load: $(OUT_LUP) ;

link: $(OUT_EXE) $(OUT_MAP) ;

$(OUT_LUP): $(OUT_BIN) ;
	@echo -e $(LOG) 'Creation of the Load $(OUT_LUP)'
	@echo -e '$(LUP) $(LUP_Opt) $(OUT_BIN) $(OUT_LUP)'
	@$(LUP) $(LUP_Opt) $(OUT_BIN) $(OUT_LUP)

$(OUT_BIN): $(OUT_EXE) ;
	@echo -e $(LOG) 'Creation of the binary file $(OUT_BIN)'
	@echo -e '$(BIN) $(BIN_Opt) $(OUT_EXE) $(OUT_BIN)'
	@$(BIN) $(BIN_Opt) $(OUT_EXE) $(OUT_BIN)

$(OUT_EXE): $(IN_LD) $(OUT_OBJ_C) $(OUT_OBJ_ASM) $(SUB_CSC_All_Object_List) $(SUB_CSC_R_Archive_List) $(EXT_Archive_List) $(OUT_MAP) ;
	@echo -e $(LOG) 'Creation of the EOC $(OUT_EXE)'
	@echo -e '$(LD) -o$(OUT_EXE) $(LD_Lib) "$(LD_Dld)" -map="$(OUT_MAP)" $(LD_Opt) -extractall $(OUT_OBJ_C) $(OUT_OBJ_ASM) $(SUB_CSC_Archive_List_Cmd) $(EXT_Archive_List_Cmd)'
	@$(LD) -o$(OUT_EXE) $(LD_Lib) "$(LD_Dld)" -map="$(OUT_MAP)" $(LD_Opt) -extractall $(OUT_OBJ_C) $(OUT_OBJ_ASM) $(SUB_CSC_Archive_List_Cmd) $(EXT_Archive_List_Cmd)

$(OUT_MAP): $(OUT_OBJ_C) $(OUT_OBJ_ASM) $(SUB_CSC_All_Object_List) $(SUB_CSC_R_Archive_List) $(EXT_Archive_List) ;

$(OUT_ARC): $(OUT_OBJ_C) $(OUT_OBJ_ASM) $(SUB_CSC_All_Object_List) $(SUB_CSC_R_Archive_List) ;
	@echo -e $(LOG) 'Creation of the archive $(OUT_ARC)'
	@echo -e '$(AR) $(AR_Opt) $(OUT_ARC) $(OUT_OBJ_C) $(OUT_OBJ_ASM) $(SUB_CSC_Archive_List)'
	@$(AR) $(AR_Opt) $(OUT_ARC) $(OUT_OBJ_C) $(OUT_OBJ_ASM) $(SUB_CSC_Archive_List)

$(SUB_CSC_Archive_List): ;

$(EXT_Archive_List): ;

$(OBJ_Dir)/%.o: $(SRC_Dir)/%.c $(DEP_Dir)/%.d $(OBJ_Dir)/%.lst ;
	@echo -e $(LOG) 'Compiling and making dependency file of $(SRC_Dir)/$*.c'
	@echo -e '$(CC) -c $(SRC_Dir)/$*.c $(TARGET) $(CC_Opt) -MD -MF=$(DEP_Dir)/$*.d -list -list_dir=$(OBJ_Dir) -object_dir=$(OBJ_Dir) $(INC_Folders)'
	@$(CC) -c $(SRC_Dir)/$*.c $(TARGET) $(CC_Opt) -MD -MF=$(DEP_Dir)/$*.d -list -list_dir=$(OBJ_Dir) -object_dir=$(OBJ_Dir) $(INC_Folders)
	@#Adapt the dependency file to be compatible with make (put everything on one line)
	@sed -i 's/.*\/$(CSCI_Name)\//$(ToRootForSed)/g' $(DEP_Dir)/$*.d
	@sed -i ':a;N;$$!ba;s/ *\\ *\n */ /g' $(DEP_Dir)/$*.d
	@sed -i 's/\\/\//g' $(DEP_Dir)/$*.d

$(DEP_Dir)/%.d: $(SRC_Dir)/%.c ;

$(OBJ_Dir)/%.lst: $(SRC_Dir)/%.c ;

$(OBJ_Dir)/%.o: $(SRC_Dir)/%.s $(DEP_Dir)/%.d $(OBJ_Dir)/%.lst ;
	@echo -e $(LOG) 'Assembling and making dependency file of $(SRC_Dir)/$*.s'
	@echo -e '$(CC) -c $(SRC_Dir)/$*.s $(TARGET) -asm=$(AS_Opt) -MD -MF=$(DEP_Dir)/$*.d -list -list_dir=$(OBJ_Dir) -object_dir=$(OBJ_Dir) $(INC_Folders)'
	@$(CC) -c $(SRC_Dir)/$*.s $(TARGET) -asm=$(AS_Opt) -MD -MF=$(DEP_Dir)/$*.d -list -list_dir=$(OBJ_Dir) -object_dir=$(OBJ_Dir) $(INC_Folders)

$(DEP_Dir)/%.d: $(SRC_Dir)/%.s ;

$(OBJ_Dir)/%.lst: $(SRC_Dir)/%.s ;

# Include of Dependencies except for clean task
ifneq ($(MAKECMDGOALS),clean)
ifneq ("","$(OUT_DEP_C)")
-include $(OUT_DEP_C)
endif
ifneq ("","$(OUT_DEP_ASM)")
-include $(OUT_DEP_ASM)
endif
endif
