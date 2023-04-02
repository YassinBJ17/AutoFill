set auxiliaryPath [file dirname [info script]]
source $auxiliaryPath/../../_tcl_utils/genericProcs.tcl
source $auxiliaryPath/../../_tcl_utils/class_TermColor.tcl
source $auxiliaryPath/../../_tcl_utils/class_OfficeExcel.tcl
#----------------------------------------------------------------------------------------------------------------------------------
set termColor [TermColor new {							\
	{ INF					black	0		green 	0 } \
	{ FILE_NAME				yellow	1		black	0 } \
	{ ERROR					red		1		black 	0 } \
	{ ERROR_MSG				yellow	0		black 	0 } \
	{ DATA_NAME				blue	1		black 	0 } \
	{ SHEET_NAME			yellow	1		blue 	0 } \
	{ NORMAL				white	0		black 	0 } \
	{ WARNING				yellow	1		black 	0 } \
	{ ZEROSIZE				black 	0		gray	0 } \
	{ UNKNOWN				gray	0		black 	0 } \
	{ ELF_DATA				blue	1		black	0 } \
	{ ELF_CODE				green	1		black 	0 } \
	{ ELF_KEYWORD_TEXT		white	1		green	0 } \
	{ ELF_KEYWORD_BSS		white	1		purple	0 } \
	{ ELF_KEYWORD_RODATA	black	0		yellow	0 } \
	{ ELF_KEYWORD_DATA		white	1		blue	1 } \
	{ ELF_KEYWORD_DEBUG		blue	0		black	0 } \
	{ ELF_SPARE				red		0		black	0 } \
	{ CODE					blue	1		black 	0 } \
	{ TITLE					yellow	1		blue 	1 } \
	{ OK					green	1		black 	0 } \
}]
#----------------------------------------------------------------------------------------------------------------------------------
set dataDefFile    [file dirname [info script]]/../data/OSS_CONF_Definition_Mapping.xlsm
set dataDefFileCsv [file dirname [info script]]/../out/[file rootname [file tail $dataDefFile]].csv

file delete -force $dataDefFileCsv

set exc [OfficeExcel new $dataDefFile 0]
set csvFile [open $dataDefFileCsv w]
puts $csvFile "Name\;Offset\;Val_g3\;Val_g4\;Size\;Type"

$::termColor putsColor "\[INF]" INF 1
puts -nonewline " Parsing excel file... "
flush stdout

set name ?
set dataId 0
for { set i 2 } { $name ne "" } { incr i }  { 
	set name   [$exc getCellVal    OSS_CONF_Definition_Mapping $i E] 
	set offset [$exc getCellVal    OSS_CONF_Definition_Mapping $i C] 
	set val_g3 [$exc getCellVal    OSS_CONF_Definition_Mapping $i K] 
	set val_g4 [$exc getCellVal    OSS_CONF_Definition_Mapping $i L] 
	set size   [$exc getCellValInt OSS_CONF_Definition_Mapping $i D] 
	set type   [$exc getCellVal    OSS_CONF_Definition_Mapping $i F] 
	set dataIdLength [string length $dataId]
	puts -nonewline [string repeat \b $dataIdLength]
	puts -nonewline [string repeat " " $dataIdLength]
	puts -nonewline [string repeat \b $dataIdLength]
	if { $name ne "" } {
		set listToAppend [list $name $offset $val_g3 $val_g4 $size $type]
		lappend myLines $listToAppend
		incr dataId
		puts -nonewline $dataId
		flush stdout
		puts $csvFile [join $listToAppend \;]
	}
}
puts Done.

$exc destroy
close $csvFile

$::termColor putsColor "\[INF]" INF 1
set totalNbOfVars [llength $myLines]
puts " $totalNbOfVars variable(s) found."
#----------------------------------------------------------------------------------------------------------------------------------
# Remove previous output files and open new ones for output :
foreach gx {g3 g4} {
	set outFile_$gx [file dirname [info script]]/../out/OSS_CONF_Definition_Mapping_$gx.out
	file delete -force [set outFile_$gx]
	set f_out_$gx   [open [set outFile_$gx] wb]
}

proc processData { line f_out_g3 f_out_g4 } {

	lassign $line name offset val_g3 val_g4 size type
	$::termColor putsColor "\[INF]" INF 1
	puts -nonewline " Processing data #[format "%0.[string length $::totalNbOfVars]d" $::dataId] : " 
	$::termColor putsColor '$name' DATA_NAME 1
	puts -nonewline "..."
	flush stdout
	incr ::dataId
	foreach gx {g3 g4} {
		seek [set f_out_$gx] $offset start
	}

	# Remove trailing ".0" for integer types in val_g3 / val_g4 :
	if { [lsearch -exact {"Signed Char" "Unsigned Char" "Signed Short" "Unsigned Short" "Signed Long" "Unsigned Long"} $type] != -1 } {
		foreach gx {g3 g4} {
			if { [string first . [set val_$gx]] != -1 } {
				set val_$gx [scan [set val_$gx] %d]
			}
		}
	}
	switch -exact $type {
		String {
			foreach gx {g3 g4} {
				set  strLen [string length [set val_$gx]]
				if { $strLen != $size } {
					$termColor putsColor "\[ERR]" ERROR 1
					puts " Default value for String '$name' is not the correct size=$size : [set val_$gx]"
					exit 0
				}
				puts -nonewline [set f_out_$gx] [binary format a$strLen [set val_$gx]]
			}
		}
		"Signed Char" -
		"Unsigned Char" {
			if { $name eq "Spare" } {
				foreach gx {g3 g4} {
					puts -nonewline [set f_out_$gx] [string repeat [binary format c [set val_$gx]] $size]
				}
			} else {
				foreach gx {g3 g4} {
					puts -nonewline [set f_out_$gx] [binary format c [set val_$gx]]
				}
			}
		}
		"Signed Short" -
		"Unsigned Short" {
				foreach gx {g3 g4} {
					puts -nonewline [set f_out_$gx] [binary format S [set val_$gx]]
				}
		}
		"Signed Long" -
		"Unsigned Long" {
				foreach gx {g3 g4} {
					puts -nonewline [set f_out_$gx] [binary format I [set val_$gx]]
				}
		}
		Float32 {
			foreach gx {g3 g4} {
				set binaryFloat [binary format f [set val_$gx]]
				puts -nonewline [set f_out_$gx] [string index $binaryFloat 3][string index $binaryFloat 2][string index $binaryFloat 1][string index $binaryFloat 0]
			}
		}
		Float64 {
			foreach gx {g3 g4} {
				set binaryFloat [binary format d [set val_$gx]]
				puts -nonewline [set f_out_$gx] [string index $binaryFloat 7][string index $binaryFloat 6][string index $binaryFloat 5][string index $binaryFloat 4][string index $binaryFloat 3][string index $binaryFloat 2][string index $binaryFloat 1][string index $binaryFloat 0]
			}
		}
		default {
			$termColor putsColor "\[ERR]" ERROR 1
			puts " Unsupported type for data '$name' : $size , type = $type"
			exit 0
		}
	}
	puts Done.
}

# Produce output files :
set dataId 0
foreach line $myLines {
	#Process data :
	if { [catch { processData $line $f_out_g3 $f_out_g4 } errorMsg] } {
		puts ""
		$::termColor putsColor "\[ERR]" ERROR 1
		puts "   -> Unable to process this data, please fix configuration file."
		$::termColor putsColor "\[ERR]" ERROR 1
		puts -nonewline "   -> Error message is : "
		flush stdout 
		$::termColor putsColor $errorMsg ERROR_MSG 
		$::termColor putsColor "\[ERR]" ERROR 1
		puts "   -> Aborted."
		exit 0
	}
}

foreach gx {g3 g4} {
	close [set f_out_$gx]
	$::termColor putsColor "\[INF]" INF 1	
	puts -nonewline " Binary file dumped at : "
	$::termColor putsColor '[file nativename [file normalize [set outFile_$gx]]]' FILE_NAME
	$::termColor putsColor "\[INF]" INF 1	
	puts "   -> Size = [file size [set outFile_$gx]] bytes"
}
#----------------------------------------------------------------------------------------------------------------------------------
