# this make file defines the common target

#include the variables
-include ../Makefile/MakefileVar.mk
-include ../../Makefile/MakefileVar.mk
-include ../../../Makefile/MakefileVar.mk
-include ../../../../Makefile/MakefileVar.mk

# include files
#INCLUDE_STD := 

# include files
INCLUDE_FILES := $(foreach d,$(INCLUDE_FILES),-I$(d))

# compute .o files
OBJECTS := $(patsubst %.c,$(OBJ_FOLDER)/%.o,$(SOURCES_FILES))
OBJECTS_S := $(patsubst %.s,$(OBJ_FOLDER)/%.o,$(SOURCES_FILES_S))



# compilation target
$(OBJ_FOLDER)/%.o: %.c
	@echo "newer prerequisites"
	@echo $?
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@  $(INCLUDE_FILES)
	
# compilation target
$(OBJ_FOLDER)/%.o: %.s
	@echo "newer prerequisites"
	@echo $?
	@mkdir -p $(@D)
	$(AS) $(ASFLAGS) -o $@ $(INCLUDE_FILES) $< 

# link target
$(LIB_FOLDER)/$(LIB_NAME).a : $(OBJECTS) $(OBJECTS_S)
	@echo "newer prerequisites"
	@echo $?
	@mkdir -p $(@D)
	$(AR) $(ARFLAGS) $@ $^


# dependencies
DEPENDENCIES := $(subst .o,.d,$(OBJECTS))
-include $(DEPENDENCIES)

# compilation target
$(OBJ_FOLDER)/%.d: %.c
	@echo "newer prerequisites"
	@echo $?
	@mkdir -p $(@D)
	$(DEP) $(DEP_ARG) $<  $(INCLUDE_FILES)  | sed "s/^\(.*:\)/$(subst /,\/,$(OBJ_FOLDER))\/\1/" | sed  "s/\(.*\)\.o:/\1.o \1.d:/" > $@


clean:
	rm -rf $(LIB_FOLDER)/$(LIB_NAME).a
	rm -rf $(OBJECTS)
	rm -rf $(OBJECTS_S)
	rm -rf $(DEPENDENCIES)


all : $(LIB_FOLDER)/$(LIB_NAME).a

.PHONY: clean all

