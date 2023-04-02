source [file dirname [info script]]/../../_tcl_utils/genericProcs.tcl
source [file dirname [info script]]/../../_tcl_utils/class_TermColor.tcl
#------------------------------------------------------------------------------------------------------------------------
set termColor [TermColor new {							\
	{ NORMAL				white	1		black 	0 } \
	{ WARNING				yellow	0		black 	0 } \
	{ ERROR					red		1		black 	0 } \
	{ ERROR_NATIVE			yellow	1		black 	0 } \
	{ VERSION				white	1		blue 	0 } \
	{ FILE_NAME				yellow	1		black 	0 } \
	{ OK					green	1		black 	0 } \
}]
#------------------------------------------------------------------------------------------------------------------------
#  Identify the directory / files which have to be delivered :
set listOfDirectoriesToDeliver [list									\
	R:/_build_out/dico													\
	R:/_build_out/gen													\
	R:/specific_binaries/boot/cpxb/Boot_SW/3_Sources/BOOT_code/build	\
	R:/specific_binaries/css_g1_2_3										\
	R:/specific_binaries/css_g4											\
	R:/specific_binaries/css_qualification								\
	R:/specific_binaries/css_stub										\
	R:/specific_binaries/error_handler									\
	R:/specific_binaries/int_source										\
	R:/specific_binaries/ext_source/_build_out/gen						\
	R:/specific_binaries/k2												\
	R:/specific_binaries/mcss											\
	R:/specific_binaries/mcss_qualification								\
	R:/specific_binaries/oss_conf_table									\
	R:/tools/trace32													\
	R:/tools/mount_vdisk												\
	R:/tools/_tcl_utils													\
	R:/tools/gen_oss_conf_binary										\
	R:/tools/gen_fls/FLX/delivery 										\
	R:/tools/gen_fls/FLX/FADEX-FLX_Guide.docm							\
]
#------------------------------------------------------------------------------------------------------------------------
proc verifyIdFormat { str } {
	if { [string is digit [string index $str 0]] && \
		 [string is digit [string index $str 1]] && \
		 [string index $str 2] eq "." && \
		 [string is digit [string index $str 3]] && \
		 [string is digit [string index $str 4]] && \
		 [string index $str 5] eq "." && \
		 [string is digit [string index $str 6]] && \
		 [string is digit [string index $str 7]] } {
		return 0
	} else {
		return 1
	}
}
#------------------------------------------------------------------------------------------------------------------------
# Find version in cartridge file :
set cartridgeFile "R:/source/oss/cartridge/cartridge_init.c"
if { [catch { set f [open $cartridgeFile r] } errorMsg] } {
	$termColor putsColor "\[ERR] " ERROR 1
	puts " : Cannot open file '$cartridgeFile'"
	puts -nonewline "         Tcl error is : "
	$termColor putsColor "\"$errorMsg\"" ERROR_NATIVE
	exit 0
}
while { [gets $f line] >= 0 } {
	if { [regexp "^#define OSS_VERSION \\(int8_t\\*\\)\"(.*)(.....)\"\$" $line _ versionId versionSuffix] } {
		if { $versionSuffix eq "-----" } {
			set versionSuffix ""
		}
		puts -nonewline "Version detected : "
		$termColor putsColor '$versionId$versionSuffix' VERSION
		break
	}
}
close $f
if { ![info exists versionId] || ![verifyIdFormat $versionId] } {
	$termColor putsColor "\[ERR] " ERROR 1
	puts " : Cannot parse version in $cartridgeFile !"
	puts "         Aborted."
	exit 0
}
#------------------------------------------------------------------------------------------------------------------------
# Set the archive file name :
set deliveryId  ${versionId}${versionSuffix}_on_[file join [clock format   [clock seconds] -format {%Y_%m_%d__%H_%M_%S}]]
set destination [file join $::env(TEMP) $deliveryId]
set archiveFile [file nativename [file normalize [file join $::env(TMP) $deliveryId.zip]]]
#------------------------------------------------------------------------------------------------------------------------
# Utility proc to recreate a delivery tree :
proc checkAndCreate { dirName } {
	set fatherDir [file dirname $dirName]
	if { ![file exists $fatherDir] } {
		checkAndCreate $fatherDir
	}
	file mkdir $dirName
}
#------------------------------------------------------------------------------------------------------------------------
# Clean up and copy files into temp folder :
file delete -force $destination 
file mkdir $destination 
set maxLength [string length $archiveFile]
foreach directoryToCopy $listOfDirectoriesToDeliver {
	set nativeFileName [file nativename "$directoryToCopy"]
	if { [string length $nativeFileName] > $maxLength } {
		set maxLength [string length $nativeFileName]
	}
}
foreach directoryToCopy $listOfDirectoriesToDeliver {
	set nativeFileName [file nativename "$directoryToCopy"]
	puts -nonewline "Copying          : "
	$termColor putsColor $nativeFileName FILE_NAME 1
	puts -nonewline "..."
	puts -nonewline [string repeat " " [expr { $maxLength - [string length $nativeFileName]}]]
	flush stdout
	set fatherDir [file dirname [file join $destination [string range $directoryToCopy 3 end]]]
	checkAndCreate $fatherDir
	file copy $directoryToCopy $fatherDir
	$termColor putsColor "Done."  OK
}
#------------------------------------------------------------------------------------------------------------------------
# Create a ZIP file from tree in temp folder :
puts -nonewline "Creating archive : "
$termColor putsColor [file nativename $destination.zip] FILE_NAME 1
puts -nonewline "..."
flush stdout
set dirBefore [pwd]
cd $::env(TMP)
exec zip -r  $destination.zip $deliveryId
cd $dirBefore
file delete  [file join $::env(TMP)  $deliveryId.tar]
$termColor putsColor "Done."  OK
#------------------------------------------------------------------------------------------------------------------------
# Open archive :
exec {*}[auto_execok cmd] /c start "" $archiveFile  ; #Open 7-zip
exec {*}[auto_execok cmd] /c start "" c:/WINDOWS/explorer.exe /select,$archiveFile
#------------------------------------------------------------------------------------------------------------------------






