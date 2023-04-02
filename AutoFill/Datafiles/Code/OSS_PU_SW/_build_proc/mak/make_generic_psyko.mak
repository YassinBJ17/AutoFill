# ----------------------------------------------------------------------------------------------------------------------
#                                             SAFRAN Electronics & Defense
#                                        Reproduction and disclosure forbidden.
# ----------------------------------------------------------------------------------------------------------------------
# DESCRIPTION : Generic part of the makefile to compile *.psy into *.psyo
# ----------------------------------------------------------------------------------------------------------------------

# Get a list of the *.psy in $(DIR_SRC_PARAM) and its subdirectories
PSYS     =  $(call RWILDCARD,$(DIR_SRC_PARAM1),*.psy) $(call RWILDCARD,$(DIR_SRC_PARAM2),*.psy) \
            $(call RWILDCARD,$(DIR_SRC_LIB_CRITICAL_SERVICE),*.psy) $(call RWILDCARD,$(DIR_SRC_OSS),*.psy)

# Get a list of the *.psyh in $(DIR_SRC) and its subdirectories
PSY_HDRS =  $(call RWILDCARD,$(DIR_SRC),*.psyh)

# Get a list of the *.psyo generated through the compilation of *.psy (for internal source and external source)
PSYOBJS_SRC  =  $(subst $(DIR_SRC),$(DIR_OBJ)/$(SRC_TYPE),$(PSYS:.psy=.psyo))

# Compiling *.psy into *.psyo in internal source
$(DIR_OBJ)/src_int/%.psyo: $(DIR_SRC)/%.psy $(PSY_HDRS)
	@R:/tools/deltree/deltree.bat $(DIR_AST)
	@mkdir -p $(@D)
	@attrib -R $@ > NUL
	$(PSYKO) --gendir $(DIR_AST) module --output $@ -- $< $(COMP_OPT_SRC_INT)

# Compiling *.psy into *.psyo in external source
$(DIR_OBJ)/src_ext/%.psyo: $(DIR_SRC)/%.psy $(PSY_HDRS)
	@R:/tools/deltree/deltree.bat $(DIR_AST)
	mkdir -p $(@D)
	$(PSYKO) --gendir $(DIR_AST) module --output $@ -- $< $(COMP_OPT_SRC_EXT)

$(DIR_LNK)/%.hjson:
	@mkdir -p $(@D)
	$(eval DIR_GEN_PARAM = $(subst _oss_ext_src,,$(subst _oss_int_src,,$(subst app_,,$(subst parto_,,$(basename $(notdir $@)))))))
	@echo {\"link_options\":{\"ldflags\":[\"-@O=$(DIR_GEN)/$(DIR_GEN_PARAM)/$(basename $(notdir $@)).map\"\, \
	\"-@E=$(DIR_GEN)/$(DIR_GEN_PARAM)/$(basename $(notdir $@))_err.map\"]}} > $@

# Generating the kmemory /!\ command to generate the kmemory but it doesn't take into account here the fact that the
# file is included several times with the same $(KMY_NAME)
# $(KMY_NAME): $(KMY_DEP) $(ARC_LIB_CRITICAL_SERVICE) $(ARC_OSS) $(PSYOBJS_SRC)
# 	@R:/tools/deltree/deltree.bat $(DIR_AST)/psyko_temp
# 	$(PSYKO) --gendir $(DIR_AST)/psyko_temp gen-mem-conf --target partition --output $@ -- $^

# Generating the partition
$(PAR_NAME): $(KMY_PATCHED_NAME) $(ARC_LIB_CRITICAL_SERVICE) $(ARC_OSS) $(PAR_DEP) $(PSYOBJS_SRC)
	@R:/tools/deltree/deltree.bat $(DIR_AST)/$(basename $(notdir $@))
	@attrib -R $@                     > NUL
	@attrib -R $(basename $@).elf     > NUL
	@attrib -R $(basename $@).map     > NUL
	@attrib -R $(basename $@)_err.map > NUL
	$(PSYKO) --gendir $(DIR_AST)/$(basename $(notdir $@)) partition --output $@ --binary-output $(basename $@).elf \
	--overwrite-memory-configuration $< -- $(filter-out $<,$^)

# Generating the application
$(APP_NAME): $(KMY_APP_NAME) $(BUDGET) $(APP_DEP)
	@R:/tools/deltree/deltree.bat $(DIR_AST)
	@attrib -R $@                     > NUL
	@attrib -R $(basename $@).app     > NUL
	@attrib -R $(basename $@).elf     > NUL
	@attrib -R $(basename $@).map     > NUL
	@attrib -R $(basename $@)_err.map > NUL
	$(PSYKO) --gendir $(DIR_AST) app --binary-output $@ --app-output $(basename $@).app -- $^
