# this make file defines the common target



#include the variables

include ../../Makefile/MakefileVar.mk



# include files

INCLUDE_STD := ../LIBMCP_api ../../LIBMCP_api
INCLUDE_STD := $(foreach d,$(INCLUDE_STD),-I$(d))

# include files
INCLUDE_FILES := $(foreach d,$(INCLUDE_FILES),-I$(d))

# compute .o files
OBJECTS := $(patsubst %.c,../../$(SCI)_gen/$(LIB_NAME)/obj/%.o,$(SOURCES_FILES))
OBJECTS_S := $(patsubst %.s,../../$(SCI)_gen/$(LIB_NAME)/obj/%.o,$(SOURCES_FILES_S))

# compilation target

../../$(SCI)_gen/$(LIB_NAME)/obj/%.o: %.c
	@echo "newer prerequisites"
	@echo $?
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE_STD) $(INCLUDE_FILES)

# compilation target
../../$(SCI)_gen/$(LIB_NAME)/obj/%.o: %.s
	@echo "newer prerequisites"
	@echo $?
	$(AS) $(ASFLAGS) -o $@ $< 

# link target

../../$(SCI)_gen/$(LIB_NAME)/lib/$(LIB_NAME).a : $(OBJECTS) $(OBJECTS_S)
	@echo "newer prerequisites"
	@echo $?
	$(AR) $(ARFLAGS) $@ $^

	

# dependancies
DEPENDENCIES := $(subst .o,.d,$(OBJECTS))
include $(DEPENDENCIES)	 



# compilation target
../../$(SCI)_gen/$(LIB_NAME)/obj/%.d: %.c
	@echo "newer prerequisites"
	@echo $?
	$(DEP) $(DEP_ARG) $< -I $(INCLUDE_STD) $(INCLUDE_FILES)  | sed "s/^\(.*:\)/..\/..\/$(SCI)_gen\/$(LIB_NAME)\/obj\/\1/" | sed  "s/\(.*\)\.o:/\1.o \1.d:/" > $@





clean:
	rm -rf ../../$(SCI)_gen/$(LIB_NAME)/lib/$(LIB_NAME).a
	rm -rf $(OBJECTS) $(OBJECTS_S)
	rm -rf $(DEPENDENCIES)
	

all : ../../$(SCI)_gen/$(LIB_NAME)/lib/$(LIB_NAME).a



.PHONY: clean all

