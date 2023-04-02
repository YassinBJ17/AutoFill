# Configuration of the CSCI/CSI top level
ifeq (,$(EFS_BOOT_PROC_DIR))
   export EFS_BOOT_PROC_DIR := $(shell pwd)
endif

CONF_Dir := $(subst \,/,$(EFS_BOOT_PROC_DIR))

# Include of the common definitions
include $(CONF_Dir)/Common_Def.mk

# Configuration of the CSC
CSC_Name := $(shell pwd | sed 's/\/$(PRO_DirName)//g' | sed 's/.*\///g')

CSC_All_Object_List := $(sort $(OUT_OBJ_C) $(OUT_OBJ_ASM) $(SUB_CSC_All_Object_C_List) $(SUB_CSC_All_Object_ASM_List))

# CSC C Sources Code files list (C)
CSC_SRC_C := $(sort $(wildcard $(SRC_Dir)/*.c))

# CSC generated Dependencies files list (DEP of C)
CSC_DEP_C := $(subst $(SRC_DirName),$(DEP_DirName),$(patsubst %.c,%.d,$(CSC_SRC_C)))

# Definition of the generated Library file (ARC)
ifeq (,$(CSC_All_Object_List))
   OUT_ARC :=
else
   OUT_ARC := $(ARC_Dir)/$(CSC_Name).a
endif

clean: ;
ifeq ($(DATA_To_Clean),)
	@echo -e $(LOG) 'Clean: no Data requested to be deleted in the configuration'
else
ifneq (,$(findstring $(DEP_DirName),$(DATA_To_Clean))$(findstring $(OBJ_DirName),$(DATA_To_Clean))$(findstring $(ARC_DirName),$(DATA_To_Clean)))
	@$(foreach mymake, $(SUB_CSC_makefile_Path_List), ("$(MAKE)" -C $(mymake) clean);)
endif

ifneq (,$(findstring $(DEP_DirName),$(DATA_To_Clean)))
ifneq (,$(findstring $(DEP_DirName),$(shell find $(DEP_Dir) -type f 2>NUL)))
	@echo -e $(LOG) 'Clean: Delete of the generated Dependencies files'
	@echo -e 'rm -f $(CSC_DEP_C)'
	@rm -f $(CSC_DEP_C)
else
	@echo -e $(LOG) 'Clean: no Dependency file to delete'
endif
endif

ifneq (,$(findstring $(OBJ_DirName),$(DATA_To_Clean)))
ifneq (,$(findstring $(OBJ_DirName),$(shell find $(OBJ_Dir) -type f 2>NUL)))
	@echo -e $(LOG) 'Clean: Delete of the generated Assembler, Listing and Object files'
	@echo -e 'rm -f $(OBJ_Dir)/*.s'
	@rm -f $(OBJ_Dir)/*.s
	@echo -e 'rm -f $(OBJ_Dir)/*.lst'
	@rm -f $(OBJ_Dir)/*.lst
	@echo -e 'rm -f $(OBJ_Dir)/*.o'
	@rm -f $(OBJ_Dir)/*.o
else
	@echo -e $(LOG) 'Clean: no Object file to delete'
endif
endif

ifneq (,$(findstring $(ARC_DirName),$(DATA_To_Clean)))
ifneq (,$(findstring $(ARC_DirName),$(shell find $(ARC_Dir) -type f 2>NUL)))
	@echo -e $(LOG) 'Clean: Delete of the generated Library file'
	@echo -e 'rm -f $(OUT_ARC)'
	@rm -f $(OUT_ARC)
else
	@echo -e $(LOG) 'Clean: no Library file to delete'
endif
endif
endif

all: compile archive ;

compile: comp assembly ;

comp: $(OUT_ASM_C) $(OUT_DEP_C) ;
	@$(foreach mymake, $(SUB_CSC_makefile_Path_List), ("$(MAKE)" -C $(mymake) comp);)

assembly: $(OUT_OBJ_C) $(OUT_LST_C) $(OUT_OBJ_ASM) $(OUT_LST_ASM) ;
	@$(foreach mymake, $(SUB_CSC_makefile_Path_List), ("$(MAKE)" -C $(mymake) assembly);)

archive: sub_archive archive_CSC ;

sub_archive: $(SUB_CSC_Archive_List) ;
	@$(foreach mymake, $(SUB_CSC_makefile_Path_List), ("$(MAKE)" -C $(mymake) archive);)

archive_CSC: $(OUT_ARC) ;

$(OUT_ARC): $(OUT_OBJ_C) $(OUT_OBJ_ASM) $(SUB_CSC_All_Object_List) ;
	@echo -e $(LOG) 'Creation of the archive $(OUT_ARC)'
	@echo -e '$(AR) $(AR_Opt) $(OUT_ARC) $(CSC_All_Object_List)'
	@$(AR) $(AR_Opt) $(OUT_ARC) $(CSC_All_Object_List)

$(SUB_CSC_Archive_List): ;

$(OBJ_Dir)/%.s: $(SRC_Dir)/%.c $(DEP_Dir)/%.d ;
	@echo -e $(LOG) 'Compiling and making dependency file of $(SRC_Dir)/$*.c'
	@echo -e '$(CC) $(CC_Opt) $(INC_Folders) $(SRC_Dir)/$*.c -o$(OBJ_Dir)/$*.s -Xmake-dependency=4 -Xmake-dependency-savefile=$(DEP_Dir)/$*.d'
	@$(CC) $(CC_Opt) $(INC_Folders) $(SRC_Dir)/$*.c -o$(OBJ_Dir)/$*.s -Xmake-dependency=4 -Xmake-dependency-savefile=$(DEP_Dir)/$*.d
	@#Adapt the dependency file to be compatible with make (put everything on one line)
	@sed -i ':a;N;$$!ba;s/ *\\ *\n */ /g' $(DEP_Dir)/$*.d

$(DEP_Dir)/%.d: $(SRC_Dir)/%.c ;

$(OBJ_Dir)/%.o: $(OBJ_Dir)/%.s $(OBJ_Dir)/%.lst ;
	@echo -e $(LOG) 'Assembling of $(OBJ_Dir)/$*.s'
	@echo -e '$(AS) $(AS_Opt) -Xasm-debug-off $(OBJ_Dir)/$*.s'
	@$(AS) $(AS_Opt) -Xasm-debug-off $(OBJ_Dir)/$*.s

$(OBJ_Dir)/%.lst: $(OBJ_Dir)/%.s ;

$(OBJ_Dir)/%.o: $(SRC_Dir)/%.s $(OBJ_Dir)/%.lst $(DEP_Dir)/%.d ;
	@echo -e $(LOG) 'Assembling of $(SRC_Dir)/$*.s'
	@echo -e '$(AS) $(AS_Opt) $(INC_Folders) -o$(OBJ_Dir)/$*.o $(SRC_Dir)/$*.s'
	@$(AS) $(AS_Opt) $(INC_Folders) -o$(OBJ_Dir)/$*.o $(SRC_Dir)/$*.s

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
