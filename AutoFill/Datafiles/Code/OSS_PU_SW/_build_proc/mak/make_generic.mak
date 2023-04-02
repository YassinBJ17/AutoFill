# ----------------------------------------------------------------------------------------------------------------------
#                                             SAFRAN Electronics & Defense
#                                        Reproduction and disclosure forbidden.
# ----------------------------------------------------------------------------------------------------------------------
# DESCRIPTION : Generic part of the makefile to compile *.c / *.s into *.o while caring about dependencies and
#               resulting in an archive file *.a
# ----------------------------------------------------------------------------------------------------------------------

# Get a list of the *.c in $(DIR_SRC_PARAM) and its subdirectories
SRCS  =  $(call RWILDCARD,$(DIR_SRC_PARAM),*.c)

# Get a list of the *.s in $(DIR_SRC_PARAM) and its subdirectories
ASMS  =  $(call RWILDCARD,$(DIR_SRC_PARAM),*.s)

# Get a list of the dependencies *.d that will be generated
DEPS  =  $(subst $(DIR_SRC),$(DIR_DEP),$(SRCS:.c=.d))

# Get a list of the *.o generated through the compilation of *.c and *.s
OBJS  =  $(subst $(DIR_SRC),$(DIR_OBJ),$(SRCS:.c=.o)) $(subst $(DIR_SRC),$(DIR_OBJ),$(ASMS:.s=.o))

# Include directories definition
INCS  =  -I$(DIR_SRC)/css_wrapper_g1_2_3 -I$(DIR_SRC)/css_wrapper_g4 -I$(DIR_SRC)/css_wrapper_stub \
         -I$(DIR_SRC)/lib_critical_service -I$(DIR_SRC)/mcss_wrapper -I$(DIR_SRC)/oss -I$(DIR_SRC)/shared \
         -I$(DIR_SRC)/uod_wrapper

# Compiling *.s into *.o
$(DIR_OBJ)/%.o: $(DIR_SRC)/%.s
	@mkdir -p $(@D)
	@attrib -R $@ > NUL
	$(AS) $(SFLAGS) $(INCS) -o $@ $<

# Compiling *.c into *.o while caring about dependencies (*.d)
$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	@mkdir -p $(@D)
	@attrib -R $@ > NUL
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

# Generating dependencies *.d for *.c
$(DIR_DEP)/%.d:
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCS) $(DIR_SRC)/$*.c -Xmake-dependency=1 -Xmake-dependency-savefile=$@
#  Write the *.d content on one single line
	sed -i ':a;N;$$!ba;s/ *\\ *\n */ /g' $@
#  Add the path of the file in order to use it as a target (via the -include in another file)
	@echo $(dir $(subst .d,.o,$(subst $(DIR_DEP),$(DIR_OBJ),$@)))`cat $@` > $@

# Generating archive *.a from compiled *.o
$(ARCHIVE_NAME): $(OBJS)
	@mkdir -p $(@D)
	@attrib -R $@ > NUL
	$(AR) $(RFLAGS) $@ $^

# Add DEPS to full list :
FULL_DEPS := $(FULL_DEPS) $(DEPS)
