# this make file defines the common target

#include the variables
include ../../Makefile/MakefileVar.mk


INCLUDE_STD := ../LIBMCP_api

# include files
INCLUDE_FILES := $(foreach d,$(INCLUDE_FILES),-I$(d))

# compute .o files
OBJECTS := $(patsubst %.c,./obj/%.o,$(SOURCES_FILES))

# compilation target
./obj/%.o: ./src/%.c
	@echo "newer prerequisites"
	@echo $?
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE_STD) $(INCLUDE_FILES)

# link target
./lib/$(LIB_NAME).a : $(OBJECTS)
	@echo "newer prerequisites"
	@echo $?
	$(AR) $(ARFLAGS) $@ $^
	
# dependancies
DEPENDENCIES := $(subst .o,.d,$(OBJECTS))
ifneq ($(MAKECMDGOALS), clean)
include $(DEPENDENCIES)	 
endif

# compilation target
./obj/%.d: ./src/%.c
	@echo "newer prerequisites"
	@echo $?
	$(DEP) $(DEP_ARG) $< -I $(INCLUDE_STD) $(INCLUDE_FILES)  | sed "s/^\(.*:\)/obj\/\1/" | sed  "s/\(.*\)\.o:/\1.o \1.d:/" > $@


clean:
	@echo "clean"
	rm -rf ./lib/$(LIB_NAME).a
	rm -rf $(OBJECTS)
	rm -rf $(DEPENDENCIES)

	
all : ./lib/$(LIB_NAME).a

.PHONY: clean all
