DUMP := ddump
DUMP_OPT := -R -n .ExceptionTable,.flash_table_data,.text,.sdata,.sdata2,.rodata
DUMP_OPT_APP := -R -n .ExceptionTable,.flash_table_data,.text,.sdata,.sdata2,.rodata
OBJ_COPY := objcopy
OBJ_COPY_OPT := -I elf32-big -O binary
ELF_K2 := ../../../SNF1_gen/KS_files_K19.2.1
ELF_XT := ../../../SNF1_gen/SRC
BUILD_PATH_LUP := ../../$(PARTITION)_gen/loads
ELF_PROC := ../../$(PARTITION)_gen/astgen/gen
MINI_LUP := TRUE
BUILD_LOC := buildAll_Loc



# Applicative LUP to be done
ifeq ($(MINI_LUP), TRUE)
####################### MINI LUP ###############################
# list of all the agents/workers and the partition header
ifeq ($(PARTITION), ERH)
TASK := $(BUILD_PATH_LUP)/$(PARTITION).LUP
else
TASK := $(MODULES_PARTITION:$(PATH_PSY)/%.psy=$(BUILD_PATH_LUP)/%.LUP) $(BUILD_PATH_LUP)/$(PARTITION)_HEADER.LUP
endif
else
####################### FULL LUP ###############################
TASK := $(BUILD_PATH_LUP)/$(PARTITION).LUP
endif



#to keep temp files for debugging
#.PRECIOUS : $(BUILD_PATH_LUP)/%.LUP0 $(BUILD_PATH_LUP)/%_T1.s9 $(BUILD_PATH_LUP)/%_T2.s9 $(BUILD_PATH_LUP)/%_T3.s9 $(BUILD_PATH_LUP)/%_Worker.s9 $(BUILD_PATH_LUP)/%_HEADER.s9

#define all the LUP to be done
lup: $(TASK)
#\
#$(BUILD_PATH)/k2.LUP\
#$(BUILD_PATH)/xt-source.LUP\
#$(BUILD_PATH)/APP.LUP\
#$(BUILD_PATH)/ERH.LUP

ifeq ($(MINI_LUP), TRUE)
####################### MINI LUP ###############################
#suppress the trailing 0
$(BUILD_PATH_LUP)/%.LUP : $(BUILD_PATH_LUP)/%.LUP0
	python $(PYTHON_EVEN_SIZE_SCRIPT) $^ $@


#compute the LUP0 from the srecord
$(BUILD_PATH_LUP)/%.LUP0 : $(BUILD_PATH_LUP)/%.s9
	$(OBJ_COPY) $(OBJ_COPY_OPT) $^ $@ 

#compute agents/workers s-record
$(BUILD_PATH_LUP)/%_T1.s9 : $(ELF_PROC)/%.elf
	$(DUMP) -R -n .rodata_module_$(basename $(notdir $@)),.text_module_$(basename $(notdir $@)) -o $@ $^
$(BUILD_PATH_LUP)/%_T2.s9 : $(ELF_PROC)/%.elf
	$(DUMP) -R -n .rodata_module_$(basename $(notdir $@)),.text_module_$(basename $(notdir $@)) -o $@ $^
$(BUILD_PATH_LUP)/%_T3.s9 : $(ELF_PROC)/%.elf
	$(DUMP) -R -n .rodata_module_$(basename $(notdir $@)),.text_module_$(basename $(notdir $@)) -o $@ $^
$(BUILD_PATH_LUP)/%_Worker.s9 : $(ELF_PROC)/%.elf
	$(DUMP) -R -n .rodata_module_$(basename $(notdir $@)),.text_module_$(basename $(notdir $@)) -o $@ $^


#compute the LUP from the s-record
#no intermediate LUP0 since the file is very small
$(BUILD_PATH_LUP)/%_HEADER.LUP : $(BUILD_PATH_LUP)/%_HEADER.s9
	$(OBJ_COPY) $(OBJ_COPY_OPT) $^ $@ 

#compute partition header s-record	
$(BUILD_PATH_LUP)/%_HEADER.s9 : $(ELF_PROC)/%.elf
	$(DUMP) -R -n .rodata_global_objects,.ast_checksum_section -o $@  $^
else

####################### FULL LUP ###############################
$(BUILD_PATH_LUP)/ERH.LUP: $(ELF_PROC)/%.elf
	@$(OBJ_COPY) $(OBJ_COPY_OPT) $< $@
endif



#compute the LUP for ERR. No intermediate file since the file is small
$(BUILD_PATH_LUP)/$(PARTITION).LUP: $(ELF_PROC)/$(PARTITION).elf
	$(OBJ_COPY) $(OBJ_COPY_OPT) $< $@

######################### COMMON RULES ###############################
###compute the .LUP for asterios provided elf	
##$(BUILD_PATH)/k2.LUP: $(ELF_PROC)/KS_files_K19.2.1/k2.elf
##	$(OBJ_COPY) $(OBJ_COPY_OPT) $< $@
##$(BUILD_PATH)/xt-source.LUP: $(ELF_PROC)/SRC/xt-source.elf
##	$(OBJ_COPY) $(OBJ_COPY_OPT) $< $@
##
###compute the LUP for APP
###$(BUILD_PATH)/APP.s9: $(ELF_PROC)/$(BUILD_LOC)/APP.elf
###	$(DUMP) -s $^ | grep ".rodata" | sed "s/\(\.ro.*\):/\1\,/g" | tr "\n\r" " " | tr -d " " > $(BUILD_PATH)/sections.txt 
###	$(DUMP) -R -n @$(BUILD_PATH)/sections.txt -o $@ $^
##$(BUILD_PATH)/APP.LUP: $(ELF_PROC)/$(BUILD_LOC)/APP.elf
##	$(OBJ_COPY) $(OBJ_COPY_OPT) $< $@
##
###compute the LUP for ERR. No intermediate file since the file is small
##$(BUILD_PATH)/ERH.LUP: $(ELF_PROC)/$(BUILD_LOC)/ERH.elf
##	$(OBJ_COPY) $(OBJ_COPY_OPT) $< $@
##
##
##
###remove of s9 and LUP0 shall be made automaticaly at the end of the build.
##clean_lup:
##	rm -f $(BUILD_PATH)/*.LUP
##	rm -f $(BUILD_PATH)/*.s9
##	rm -f $(BUILD_PATH)/*.LUP0


## command to make for reminder
##
##REM Get srec of agents/workers
##ddump -R -n .rodata_global_objects -o ./build/ITF_Header.s9 ../../../SNF1_gen/buildARN_IRN_Loc/ITF.elf
##ddump -R -n .rodata_module_ITF_T1,.text_module_ITF_T1 -o ./build/ITF_T1.s9 ../../../SNF1_gen/buildARN_IRN_Loc/ITF.elf
##ddump -R -n .rodata_module_ITF_T2,.text_module_ITF_T2 -o ./build/ITF_T2.s9 ../../../SNF1_gen/buildARN_IRN_Loc/ITF.elf
##ddump -R -n .rodata_module_ITF_T3,.text_module_ITF_T3 -o ./build/ITF_T3.s9 ../../../SNF1_gen/buildARN_IRN_Loc/ITF.elf
##ddump -R -n .rodata_module_ITF_Worker,.text_module_ITF_Worker -o ./build/ITF_Worker.s9 ../../../SNF1_gen/buildARN_IRN_Loc/ITF.elf
##
##ddump -R -n .rodata_global_objects -o ./build/IRN_Header.s9 ../../../SNF1_gen/buildARN_IRN_Loc/IRN.elf
##ddump -R -n .rodata_module_IRN_T1,.text_module_IRN_T1 -o ./build/IRN_T1.s9 ../../../SNF1_gen/buildARN_IRN_Loc/IRN.elf
##ddump -R -n .rodata_module_IRN_T2,.text_module_IRN_T2 -o ./build/IRN_T2.s9 ../../../SNF1_gen/buildARN_IRN_Loc/IRN.elf
##ddump -R -n .rodata_module_IRN_T3,.text_module_IRN_T3 -o ./build/IRN_T3.s9 ../../../SNF1_gen/buildARN_IRN_Loc/IRN.elf
##
##ddump -R -n .rodata_global_objects -o ./build/MNT_Header.s9 ../../../SNF1_gen/buildARN_IRN_Loc/MNT.elf
##ddump -R -n .rodata_module_MNT_T1,.text_module_MNT_T1 -o ./build/MNT_T1.s9 ../../../SNF1_gen/buildARN_IRN_Loc/MNT.elf
##ddump -R -n .rodata_module_MNT_T3,.text_module_MNT_T3 -o ./build/MNT_T3.s9 ../../../SNF1_gen/buildARN_IRN_Loc/MNT.elf
##
##ddump -R -n .rodata_global_objects -o ./build/ARN_Header.s9 ../../../SNF1_gen/buildARN_IRN_Loc/ARN.elf
##ddump -R -n .rodata_module_ARN_T1,.text_module_ARN_T1 -o ./build/ARN_T1.s9 ../../../SNF1_gen/buildARN_IRN_Loc/ARN.elf
##
##objcopy -I elf32-big -O binary ./build/ITF_Header.s9 ./build/ITF_HEADER.LUP
##objcopy -I elf32-big -O binary ./build/ITF_T1.s9 ./build/ITF_T1_all.LUP
##objcopy -I elf32-big -O binary ./build/ITF_T2.s9 ./build/ITF_T2_all.LUP
##objcopy -I elf32-big -O binary ./build/ITF_T3.s9 ./build/ITF_T3_all.LUP
##objcopy -I elf32-big -O binary ./build/ITF_Worker.s9 ./build/ITF_Worker_all.LUP
##
##objcopy -I elf32-big -O binary ./build/IRN_Header.s9 ./build/IRN_HEADER.LUP
##objcopy -I elf32-big -O binary ./build/IRN_T1.s9 ./build/IRN_T1_all.LUP
##objcopy -I elf32-big -O binary ./build/IRN_T2.s9 ./build/IRN_T2_all.LUP
##objcopy -I elf32-big -O binary ./build/IRN_T3.s9 ./build/IRN_T3_all.LUP
##
##objcopy -I elf32-big -O binary ./build/MNT_Header.s9 ./build/MNT_HEADER.LUP
##objcopy -I elf32-big -O binary ./build/MNT_T1.s9 ./build/MNT_T1_all.LUP
##objcopy -I elf32-big -O binary ./build/MNT_T3.s9 ./build/MNT_T3_all.LUP
##
##objcopy -I elf32-big -O binary ./build/ARN_Header.s9 ./build/ARN_HEADER.LUP
##objcopy -I elf32-big -O binary ./build/ARN_T1.s9 ./build/ARN_T1_all.LUP
##
##REM KS and APP
##objcopy -I elf32-big -O binary ../../../SNF1_gen/KS_files_K19.2.1/k2.elf ./build/k2.LUP
##objcopy -I elf32-big -O binary ../../../SNF1_gen/SRC/xt-source.elf ./build/xt-source.LUP
##objcopy -I elf32-big -O binary ../../../SNF1_gen/buildARN_IRN_Loc/APP.elf ./build/APP.LUP
##objcopy -I elf32-big -O binary ../../../SNF1_gen/buildARN_IRN_Loc/ERR.elf ./build/ERR.LUP
##
##REM sup of trailing 0
##python ./Shrink.py ../../../SNF1_gen/buildARN_IRN_Loc/MappingITF.map ITF_T1 ./build/ITF_T1_all.LUP ./build/ITF_T1.LUP
##python ./Shrink.py ../../../SNF1_gen/buildARN_IRN_Loc/MappingITF.map ITF_T2 ./build/ITF_T2_all.LUP ./build/ITF_T2.LUP
##python ./Shrink.py ../../../SNF1_gen/buildARN_IRN_Loc/MappingITF.map ITF_T3 ./build/ITF_T3_all.LUP ./build/ITF_T3.LUP
##python ./Shrink.py ../../../SNF1_gen/buildARN_IRN_Loc/MappingITF.map ITF_Worker ./build/ITF_Worker_all.LUP ./build/ITF_Worker.LUP
##
##python ./Shrink.py ../../../SNF1_gen/buildARN_IRN_Loc/MappingIRN.map IRN_T1 ./build/IRN_T1_all.LUP ./build/IRN_T1.LUP
##python ./Shrink.py ../../../SNF1_gen/buildARN_IRN_Loc/MappingIRN.map IRN_T2 ./build/IRN_T2_all.LUP ./build/IRN_T2.LUP
##python ./Shrink.py ../../../SNF1_gen/buildARN_IRN_Loc/MappingIRN.map IRN_T3 ./build/IRN_T3_all.LUP ./build/IRN_T3.LUP
##
##python ./Shrink.py ../../../SNF1_gen/buildARN_IRN_Loc/MappingARN.map ARN_T1 ./build/ARN_T1_all.LUP ./build/ARN_T1.LUP
##
##python ./Shrink.py ../../../SNF1_gen/buildARN_IRN_Loc/MappingMNT.map MNT_T1 ./build/MNT_T1_all.LUP ./build/MNT_T1.LUP
##python ./Shrink.py ../../../SNF1_gen/buildARN_IRN_Loc/MappingMNT.map MNT_T3 ./build/MNT_T3_all.LUP ./build/MNT_T3.LUP
##