# Configuration of the CSCI/CSI top level
ifeq (,$(EFS_HWCAR_PROC_DIR))
   export EFS_HWCAR_PROC_DIR := $(shell pwd)
endif

CONF_Dir := $(subst \,/,$(EFS_HWCAR_PROC_DIR))

# Include of the common definitions
include $(CONF_Dir)/Common_Def.mk

# Configuration of the CSCI
ifeq (,$(CSCI_Name))
   CSCI_Name := $(shell pwd | sed 's/\/$(PRO_DirName)//g' | sed 's/.*\///g')
endif

CSCI_All_Object_List := $(sort $(OUT_OBJ_C) $(OUT_OBJ_ASM) $(SUB_CSC_All_Object_C_List) $(SUB_CSC_All_Object_ASM_List))

# CSCI C Sources Code files list (C)
CSCI_SRC_C := $(sort $(wildcard $(SRC_Dir)/*.c))

# CSCI generated Dependencies files list (DEP of C)
CSCI_DEP_C := $(subst $(SRC_DirName),$(DEP_DirName),$(patsubst %.c,%.d,$(CSCI_SRC_C)))

# Definition of the generated CSCI files (ARC, EXE, MAP, ABS, LUP)
ifeq (,$(CSCI_All_Object_List))
   OUT_ARC :=
   OUT_EXE :=
   OUT_MAP :=
   OUT_SRE :=
   OUT_LUP :=
   OUT_ABS :=
   OUT_S19 :=
   OUT_UEL :=
   OUT_BIN :=
else
   OUT_ARC := $(ARC_Dir)/$(CSCI_Name).a
   OUT_EXE := $(EOC_Dir)/$(CSCI_Name).elf
   OUT_MAP := $(EOC_Dir)/$(CSCI_Name).map
   OUT_SRE := $(EOC_Dir)/$(CSCI_Name).sre
   OUT_LUP := $(EOC_Dir)/$(CSCI_Name).lup
   OUT_ABS := $(EOC_Dir)/$(CSCI_Name).abs
   OUT_S19 := $(EOC_Dir)/$(CSCI_Name).s19
   OUT_UEL := $(EOC_Dir)/$(CSCI_Name).uelf
   OUT_BIN := $(EOC_Dir)/$(CSCI_Name).bin
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
	@echo -e 'rm -f $(CSCI_DEP_C)'
	@rm -f $(CSCI_DEP_C)
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

ifneq (,$(findstring $(EOC_DirName),$(DATA_To_Clean)))
ifneq (,$(findstring $(EOC_DirName),$(shell find $(EOC_Dir) -type f 2>NUL)))
	@echo -e $(LOG) 'Clean: Delete of the generated files related to the EOC'
	@echo -e 'rm -f $(OUT_MAP)'
	@rm -f $(OUT_MAP)
	@echo -e 'rm -f $(OUT_EXE)'
	@rm -f $(OUT_EXE)
	@echo -e 'rm -f $(OUT_SRE)'
	@rm -f $(OUT_SRE)
	@echo -e 'rm -f $(OUT_LUP)'
	@rm -f $(OUT_LUP)
	@echo -e 'rm -f $(OUT_ABS)'
	@rm -f $(OUT_ABS)
	@echo -e 'rm -f $(OUT_S19)'
	@rm -f $(OUT_S19)
	@echo -e 'rm -f $(OUT_UEL)'
	@rm -f $(OUT_UEL)
	@echo -e 'rm -f $(OUT_BIN)'
	@rm -f $(OUT_BIN)
else
	@echo -e $(LOG) 'Clean: no file to delete related to the EOC'
endif
endif

ifneq (,$(findstring RLCReports,$(DATA_To_Clean)))
ifneq (,$(findstring $(RLC_DirName),$(shell find $(RLC_Dir) -type f 2>NUL)))
	@echo -e $(LOG) 'Clean: Delete of the project files and Kalimetrix reports related to the EOC'
	@echo -e 'rm -f $(RLC_LOG) $(RLC_PROJ)'
	@rm -rf $(RLC_LOG) $(RLC_PROJ)
else
	@echo -e $(LOG) 'Clean: no file to delete related to the EOC'
endif
endif

endif

all: generate compile archive $(CONF_CSCI_EOC) ;

compile: comp assembly ;

comp: $(OUT_ASM_C) $(OUT_DEP_C) ;
	@$(foreach mymake, $(SUB_CSC_makefile_Path_List), ("$(MAKE)" -C $(mymake) comp);)

assembly: $(OUT_OBJ_C) $(OUT_LST_C) $(OUT_OBJ_ASM) $(OUT_LST_ASM) ;
	@$(foreach mymake, $(SUB_CSC_makefile_Path_List), ("$(MAKE)" -C $(mymake) assembly);)

archive: sub_archive $(CONF_CSCI_Archive) ;

sub_archive: $(SUB_CSC_Archive_List) ;
	@$(foreach mymake, $(SUB_CSC_makefile_Path_List), ("$(MAKE)" -C $(mymake) archive);)

archive_CSCI: $(OUT_ARC) ;

load: srecord $(OUT_LUP) ;

srecord: link $(OUT_SRE) ;

load_ccc: srec_s19 $(OUT_ABS) ;

srec_s19: link $(OUT_S19) ;

link: $(OUT_EXE) $(OUT_MAP) checks ;


checks: $(OUT_EXE)
	@echo -e $(LOG) '*** Check errata processor E010385 ***'
	@$(shell test -f $(E010385_CHECKER_LOG) && rm -rf $(E010385_CHECKER_LOG) || true)
	@echo -e ' $(E010385_CHECKER) $(OUT_EXE) > $(E010385_CHECKER_LOG)'
	@$(E010385_CHECKER) $(OUT_EXE) > $(E010385_CHECKER_LOG)

docgen: $(OUT_DOC) ;

rulechecker:
	@echo -e $(LOG) '*** Building Kalimetrix Rulechecker on project... ***'
	@echo -e 'batch $(RLC_PROJ) -clean -err $(RLC_LOG)'
	@batch $(RLC_PROJ) -clean -err $(RLC_LOG)
	@echo -e $(LOG) '*** Generating csv output on Kalimetrix Rulechecker project... ***'
	@batch $(RLC_PROJ) -clean -nobuild -addin export -format csv
	@echo -e $(LOG) '*** Build is finished on Kalimetrix Rulechecker project! ***'

print-%  : ; @echo $* = $($*);exit 0

generate: 
# Generate include directive file list for compiler and assembler
	@$(eval INC_Folders := $(addprefix -I, $(shell find $(CSCI_Root) -type d -name $(HDR_DirName) -o -name $(SRC_DirName)) $(CSCI_Root)$(HDE_DirName)))
	@$(shell test -f $(INC_File) && rm -rf $(INC_File) || true)
	@$(shell echo $(INC_Folders) > $(INC_File))

$(OUT_S19) : $(OUT_EXE) ;
	@echo -e $(LOG) 'Creation of S19 file $(OUT_S19)'
	@echo -e '$(DUMP) -Rv -w32 -m3  $(OUT_EXE) -o $(OUT_S19)'
	@$(DUMP) -Rv -w32 -m3 $(OUT_EXE) -o $(OUT_S19)

# SREC generated by CCC
$(OUT_ABS): AlignSREC
	@echo -e $(LOG) 'Creation of the CCC ABS file with cartridge $(OUT_ABS)'
	@echo -e '$(CCC) $(OUT_EXE) $(OUT_S19)_a $(OUT_ABS) $(CCC_Xml) $(CCC_Conf) -c=$(CCC_Opt)'
	@$(CCC) $(OUT_EXE) $(OUT_S19)_a $(OUT_ABS) $(CCC_Xml) $(CCC_Conf) -c=$(CCC_Opt)
	@rm -f $(OUT_S19)_a

AlignSREC :$(OUT_S19)
#Add commands to format the S3 file for MSW (for more details see SK-0000454573-01 : S-REC FILE ADDRESS ALIGNMENT ON 8 BYTES)
	@echo -e $(LOG) 'Creation of a aligned S19 file $(OUT_S19)_a'
	@export address; address=`sed -n -r "2 s/....(.{8}).*/\1/p" $(OUT_S19)`;$(SREC2BIN) -o $$address $(OUT_S19) $(OUT_BIN)
	@export address; address=`sed -n -r "2 s/....(.{8}).*/\1/p" $(OUT_S19)`;$(BIN2SREC) -l 32 -a 4 -o $$address $(OUT_BIN) > $(OUT_S19)_a
# Remove temporary files
	@rm -f $(OUT_BIN)

$(OUT_LUP) : $(OUT_SRE) ;
	@echo -e $(LOG) 'Creation of the A615 Load $(OUT_LUP)'
	@echo -e '$(LUP) $(LUP_Opt) $(OUT_SRE) $(OUT_LUP)'
	@$(LUP) $(LUP_Opt) $(OUT_SRE) $(OUT_LUP)

$(OUT_SRE) : $(OUT_EXE) ;
	@echo -e $(LOG) 'Creation of the Motorola S-Record $(OUT_SRE)'
	@echo -e '$(DUMP) $(DD_Opt) -o $(OUT_SRE) $(OUT_EXE)'
	@$(DUMP) $(DD_Opt) -o $(OUT_SRE) $(OUT_EXE)

$(OUT_EXE) : $(OUT_OBJ_C) $(OUT_OBJ_ASM) $(SUB_CSC_All_Object_List) $(SUB_CSC_Archive_List) $(EXT_Archive_List) $(OUT_MAP) ;
	@echo -e $(LOG) 'Creation of the EOC $(OUT_EXE)'
	@echo -e '$(LD) $(LD_Opt) $(OUT_OBJ_C) $(OUT_OBJ_ASM) $(SUB_CSC_Archive_List_Cmd) $(EXT_Archive_List_Cmd) -o$(OUT_EXE) $(LD_Lib) "$(LD_Dld)" -@O="$(OUT_MAP)"'
	@$(LD) $(LD_Opt) $(OUT_OBJ_C) $(OUT_OBJ_ASM) $(SUB_CSC_Archive_List_Cmd) $(EXT_Archive_List_Cmd) -o$(OUT_EXE) $(LD_Lib) "$(LD_Dld)" -@O="$(OUT_MAP)"

$(OUT_MAP) : $(OUT_OBJ_C) $(OUT_OBJ_ASM) $(SUB_CSC_All_Object_List) $(SUB_CSC_Archive_List) $(EXT_Archive_List) ;

$(OUT_ARC): $(OUT_OBJ_C) $(OUT_OBJ_ASM) $(SUB_CSC_All_Object_List) ;
	@echo -e $(LOG) 'Creation of the archive $(OUT_ARC)'
	@echo -e '$(AR) $(AR_Opt) $(OUT_ARC) $(CSCI_All_Object_List)'
	@$(AR) $(AR_Opt) $(OUT_ARC) $(CSCI_All_Object_List)

$(SUB_CSC_Archive_List): ;

$(EXT_Archive_List): ;

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

