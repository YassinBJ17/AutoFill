# ----------------------------------------------------------------------------------------------------------------------
#                                             SAFRAN Electronics & Defense
#                                        Reproduction and disclosure forbidden.
# ----------------------------------------------------------------------------------------------------------------------
# DESCRIPTION : Makefile entry point
# The makefile is divided into several parts:
#    - The archives generation (performed without any link to psyko):
#       - The compilation of *.c and *.s into *.o
#       - The gathering of *.o into several *.a
#    - The applications generation (performed with psyko):
#       - The generation of *.parto and their associated *.elf
#       - The generation of *.app and their associated *.elf
#    - The tools added to make the makefile more comfortable to use
# ----------------------------------------------------------------------------------------------------------------------

# Include part ---------------------------------------------------------------------------------------------------------
# Include configuration file used till the archives generation
include R:/_build_proc/mak/conf.mak

# Include configuration file used till the applications generation
include R:/_build_proc/mak/conf_psyko.mak

# Include archiving file
include R:/_build_proc/mak/make_archive.mak

# Include application generation file
include R:/_build_proc/mak/make_exe.mak

# Cleanup---------------------------------------------------------------------------------------------------------------
clean:
	@R:/tools/deltree/deltree.bat $(DIR_ARC)
	@R:/tools/deltree/deltree.bat $(DIR_OUT)/ast
	@R:/tools/deltree/deltree.bat $(DIR_OUT)/dico
	@R:/tools/deltree/deltree.bat $(DIR_OUT)/gen
	@R:/tools/deltree/deltree.bat $(DIR_OUT)/lnk
	@R:/tools/deltree/deltree.bat $(DIR_LOG)
	@R:/tools/deltree/deltree.bat $(DIR_OBJ)

# Archives generation part ---------------------------------------------------------------------------------------------
# Clean dependencies *.d
clean_dep:
	@R:/tools/deltree/deltree.bat $(DIR_DEP)

# Regenerate dependencies *.d (used when an #include has been modified/added/removed)
dep: $(FULL_DEPS)
	@echo 'dep done.'

update_deps_by_delta:
	@R:/tools/update_deps_by_delta/update_deps_by_delta.bat

# Archives generation or regeneration are processed automatically by the application generation part

# Applications generation part -----------------------------------------------------------------------------------------

# Partitions generation or regeneration are processed automatically by the application generation part

# Applications *.app/*.elf generation for G1_2_3
app_g1_2_3_int_src: $(APP_G1_2_3_OSS_ELF_INT_SRC)
app_g1_2_3_ext_src: $(APP_G1_2_3_OSS_ELF_EXT_SRC)

# Applications *.app/*.elf generation for G4
app_g4_int_src: $(APP_G4_OSS_ELF_INT_SRC)
app_g4_ext_src: $(APP_G4_OSS_ELF_EXT_SRC)

# Applications *.app/*.elf generation for STUB_UOD
app_stub_uod_int_src: $(APP_STUB_UOD_OSS_ELF_INT_SRC)
app_stub_uod_ext_src: $(APP_STUB_UOD_OSS_ELF_EXT_SRC)

# Applications with warnings (in internal source only as the warnings will be the same than in external source)
MAIN_TGT = app_g1_2_3_int_src
$(MAIN_TGT)_with_warnings:   SUB_TGT := $(MAIN_TGT)
include R:/_build_proc/mak/app_with_wngs.mak

MAIN_TGT = app_g4_int_src
$(MAIN_TGT)_with_warnings:   SUB_TGT := $(MAIN_TGT)
include R:/_build_proc/mak/app_with_wngs.mak

MAIN_TGT = app_stub_int_src
include R:/_build_proc/mak/app_with_wngs.mak

# Generation of all applications in internal source
app_all_int: app_g1_2_3_int_src app_g4_int_src app_stub_uod_int_src

# Generation of all applications in external source
app_all_ext: app_g1_2_3_ext_src app_g4_ext_src app_stub_uod_ext_src

# Generation of all applications and their dictionaries
app_all: app_all_int app_all_ext dico

# Generation of all applications and their dictionaries with warnings
MAIN_TGT = app_all
include R:/_build_proc/mak/app_with_wngs.mak

# Tools ----------------------------------------------------------------------------------------------------------------
# Format the source code in *.c and *.h to be conform to the GT44 coding standard (/!\ in progress)
check_and_format_source_code:
	@R:/tools/check_and_format_source_code/check_and_format_source_code.bat

# Generate the rulechecker project and automatically open it
build_rulechecker_project:
	@R:/tools/build_rulechecker_project/build_rulechecker_project.bat

# Display in the terminal the list of the error code and their signification
ks_error_codes:
	@R:/tools/ks_error_codes/ks_error_codes.bat

# Launch T32 in the chosen configuration
launch_t32:
	@R:/tools/trace32/main/launch_t32.bat

# Generate the dictionaries in front of each application
dico:
	if [ ! -d $(DIR_DIC) ];then mkdir $(DIR_DIC); fi
	$(MD) $(PARTO_G4_OSS_ELF_INT_SRC)       $(DFLAGS) $(DIR_DIC)/parto_g4_oss_src_int.dic
	$(MD) $(PARTO_G1_2_3_OSS_ELF_INT_SRC)   $(DFLAGS) $(DIR_DIC)/parto_g1_2_3_oss_src_int.dic
	$(MD) $(PARTO_STUB_UOD_OSS_ELF_INT_SRC) $(DFLAGS) $(DIR_DIC)/parto_stub_uod_oss_src_int.dic
	$(MD) $(PARTO_G4_OSS_ELF_EXT_SRC)       $(DFLAGS) $(DIR_DIC)/parto_g4_oss_src_ext.dic
	$(MD) $(PARTO_G1_2_3_OSS_ELF_EXT_SRC)   $(DFLAGS) $(DIR_DIC)/parto_g1_2_3_oss_src_ext.dic
	$(MD) $(PARTO_STUB_UOD_OSS_ELF_EXT_SRC) $(DFLAGS) $(DIR_DIC)/parto_stub_uod_oss_src_ext.dic

# Generate 5 FLS from generated .elf / oss_conf / MRAM images : 
fls:
	@R:/tools/deltree/deltree.bat $(DIR_OUT)/gen/fls
	@R:/tools/gen_fls/FLX/dev/gen_fls.bat

# Generate a compressed directory containing all the elements for a delivery to the IVVQ team
deliver:
	@R:/tools/deliver/deliver.bat

# Integrate the use of TCL to have a better interface to launch the makefile command
x:
	@R:/tools/make_x/make_x.bat
	@$(TMP)/make_x_target.bat

# Add the content of the *.d files in the makefile in order to recompile only files that have changed
ifneq ($(MAKECMDGOALS),clean)
ifneq ("","$(FULL_DEPS)")
-include $(FULL_DEPS)
endif
endif
