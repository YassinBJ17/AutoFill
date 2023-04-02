source [file dirname [info script]]/../my_objdump/auxiliary/genericProcs.tcl
source [file dirname [info script]]/../my_objdump/auxiliary/class_TermColor.tcl

set addr_fpga_start 0x24000000
set file [file dirname [info script]]/a.xlsm

set termColor [TermColor new {							\
	{ NORMAL				white	1		black 	0 } \
	{ CODE					blue	1		black 	0 } \
	{ TITLE					yellow	1		blue 	1 } \
	{ INF					black	0		green  	1 } \
	{ INVERTED				yellow	1		black	0 } \
	{ WARNING				yellow	0		black 	0 } \
	{ ZEROSIZE				black 	0		gray	0 } \
	{ ERROR					red		1		black 	0 } \
	{ OK					green	1		black 	0 } \
	{ UNKNOWN				gray	0		black 	0 } \
}]

proc closeExcelFileAndQuit { excel workbooks workbook sheets } {
	$workbook Close 1
	$sheets    -destroy
	$workbook  -destroy
	$workbooks -destroy
	$excel Quit
	$excel -destroy 
}

package require twapi

set excel [::twapi::comobj Excel.Application]
$excel Visible 1
set workbooks [$excel Workbooks]
$workbooks Open [file normalize $file]
set workbook [$workbooks Item 1] 
puts  [$workbook  Name]
set sheets [$workbook Sheets]



set index 1
while { ![catch { set mySheet [$sheets Item $index] } errorMsg] } {
	set detectedSheets([string trim [$mySheet Name]]) $mySheet 
	incr index
}
puts "Found [llength [array names detectedSheets]] sheet(s) :"

foreach sheet [lsort -ascii [array names detectedSheets]] {
	puts "  '$sheet'"
}

if { [lsearch -exact [array names detectedSheets] "Global"] == -1 } { 
	puts "ERR : Cannot find sheet named 'Global' in file '$file', aborted."
	closeExcelFileAndQuit $excel $workbook 
	exit 0
}


puts "Found offsets from 'Global' sheet :"
set cells [$detectedSheets(Global) Cells]
set currentLine 6
while { 1 } {
	set cellSheet [$cells Item $currentLine B]
	set sheetName        [$cellSheet Value]
	if { $sheetName eq  "" } {
		$cellSheet -destroy
		break
	}
	set cellOffset [$cells Item $currentLine A]
	set addrOffset   0x[$cellOffset Value]
	if { $sheetName ne "Not Used" } {
		puts "  '$sheetName' -> $addrOffset"
		set offsets($sheetName) $addrOffset
	}
	$cellSheet -destroy
	$cellOffset -destroy
	incr currentLine
}
$cells -destroy

# Check that each offset in 'Global' sheet has a descriptive sheet :
foreach sheetNameFromOffsets [lsort -ascii [array names offsets]] {
	if { [regexp "^(.+)\\\[\[0-9]]\$" $sheetNameFromOffsets _ baseName ] } {
		set sheetNameFromOffsets $baseName
	}
	if { [lsearch -exact [array names detectedSheets] $sheetNameFromOffsets] == -1 } {
		puts "ERR : No offset for '$sheetNameFromOffsets'"
	}
}


# Generate code :
puts "Generate code :"
foreach sheet [lsort -ascii [array names detectedSheets]] {
	if { $sheet eq "Global" || $sheet eq "User Guide" } {
		continue
	}
	$termColor putsColor \[INF] INF 1
	$termColor putsColor " Processing sheet '$sheet'..." NORMAL
	set cells [$detectedSheets($sheet) Cells]
	
	# Search "# bits" column :
	set  found 0
	for {set i 0 } { $i < 25 } { incr i } {
		set cell [$cells Item 2 [format %c [expr {65 + $i}]]]
		if { [string first "# bits" [string tolower [$cell Value]]] != -1 } {
			set found $i
			$cell -destroy
			break
		}
		$cell -destroy
	}
	if { !$found } {
		puts "    Cannot find '# bits' column in sheet '$sheet', aborted."
		exit
	} else {
		set columnBits [format %c [expr {65 + $i}]]
		puts "    Found '# bits' @ column $columnBits"
	}

	# Search second "Name" column :
	set nbOfOcc 0
	set found   0
	for {set i 0 } { $i < 25 } { incr i } {
		set cell [$cells Item 2 [format %c [expr {65 + $i}]]]
		if { [string first "Name" [$cell Value]] != -1 } {
			if { $nbOfOcc == 0 } {
				incr nbOfOcc
			} else {
				set found $i
				$cell -destroy
				break
			}
		}
		$cell -destroy
	}
	if { !$found } {
		puts "    Cannot find 2nd 'Name' column in sheet '$sheet', aborted."
		exit
	} else {
		set columnName [format %c [expr {65 + $i}]]
		puts "    Found 2nd 'Name' @ column $columnName"
	}
	
	# Search "Field/Description" column :
	set nbOfOcc 0
	set found   0
	for {set i 0 } { $i < 25 } { incr i } {
		set cell [$cells Item 2 [format %c [expr {65 + $i}]]]
		if { [string first "Description" [$cell Value]] != -1 } {
			if { $nbOfOcc == 0 } {
				incr nbOfOcc
			} else {
				set found $i
				$cell -destroy
				break
			}
		}
		$cell -destroy
	}
	if { !$found } {
		puts "    Cannot find 2nd 'Description' column in sheet '$sheet', aborted."
		exit
	} else {
		set columnFieldDescription [format %c [expr {65 + $i}]]
		puts "    Found column 'Field Description' @ column $columnFieldDescription"
	}
	
	# Parse sheet :
	set currentLine					4
	set myRegistersGroup			?
	set fullListOfRegisters 		{}
	set listOfRegistersOfOneGroup 	{}
	set isInBitField				0
	set isInTableDef				0
	set offsetPrev					?
	set offsetPrevForTable			?
	set firstGroupOfRegistersAdded	0
	set spareId                     0
	while { 1 } {
		set cellOffset  [$cells Item $currentLine A]
		
		set offset					[string trim [$cellOffset  Value]]
		set cellName				[$cells Item $currentLine B]
		set name					[string trim [$cellName    Value]]
		set cellComment				[$cells Item $currentLine C]
		set comment					[string trim [$cellComment Value]]
		set cellD					[$cells Item $currentLine D]
		set D						[string trim [$cellD Value]]
		set cellE					[$cells Item $currentLine E]
		set E						[string trim [$cellE Value]]
		set cellBits				[$cells Item $currentLine $columnBits]
		set bits					[string trim [$cellBits Value]]
		set cellNameOff				[$cells Item $currentLine $columnName]
		set nameOff					[string trim [$cellNameOff Value]]
		set cellFieldDescription	[$cells Item $currentLine $columnFieldDescription]
		set fieldDescription		[string map { \n "" } [string trim [$cellFieldDescription Value]]]

		set isGroupOfRegistersDefLine [expr { $offset ne ""  && $name ne "" && $bits eq "" }]

		if { ($isInTableDef == 1) && $offset ne "" } {  ; # Condition on 'offset' for table of bitfields
			set isInTableDef 0
			set lastRegister [lindex  $listOfRegistersOfOneGroup end]
			set hexOffset 0x$offset
			set hexOffsetPrev 0x$offsetPrevForTable
			set lastRegister  [lreplace $lastRegister 0 0 [lindex $lastRegister 0]\[[expr { ($hexOffset - $hexOffsetPrev + 4) / 4 }]\]]
			set listOfRegistersOfOneGroup  [lreplace $listOfRegistersOfOneGroup 0 0 $lastRegister]
		} elseif { $offset eq "" && $name eq "" && $comment eq "" && $bits ne "" } {   ; # Useful secondary bits from bitfield ...
			if { $isInBitField } {
				set lastRegister [lindex $listOfRegistersOfOneGroup end]
				set lastBits     [lindex $lastRegister              end]
				lappend lastBits [list $bits $nameOff $fieldDescription]
				set lastRegister [lreplace $lastRegister end end $lastBits]
				set listOfRegistersOfOneGroup [lreplace $listOfRegistersOfOneGroup end end $lastRegister]
			}
		} elseif { $offset ne  "" && $name ne "" && $bits ne "" } {   ; # Useful line for non bitfield or 1st bits of bitfield description:
			if { $isInBitField && ([string range $bits end-1 end] eq ":0" || $bits eq "0") } {
				set isInBitField 0
			}
			if { !$isInBitField && $bits ne "31:0" } {
				set isInBitField 1
			}
			lappend listOfRegistersOfOneGroup [list $name 0x$offset [list [list $bits $nameOff $fieldDescription]]]
		} elseif { $offset eq "to"  && $name eq "" && $comment eq "" } {			; # Table definition 
			set isInTableDef 1
			set offsetPrevForTable $offsetPrev
		} elseif { $isGroupOfRegistersDefLine } {			; # Group of registers def line
			if { $myRegistersGroup ne "?" } {
				# Detect spare :
				if { $firstGroupOfRegistersAdded } {
					set registerEnd [lindex [lindex [lindex [lindex $fullListOfRegisters end] end] end] 1]
					if { [regexp "(.+)\\\[(.+)\\\]" [lindex [lindex [lindex [lindex $fullListOfRegisters end] end] end] 0] _ _ size] } {
						set registerEnd [expr { $registerEnd + ($size - 1) * 4 }]
					}	
					set registerStart [lindex [lindex $listOfRegistersOfOneGroup 0]                         1]
					set spareSize [expr { ($registerStart - $registerEnd - 4)/ 4 }]
					if { $spareSize > 0 } {
						lappend fullListOfRegisters [list spare_[format %02d $spareId]\[$spareSize\] [list [list _spare_ ? ?]]]
						incr spareId
					}
				}
				set firstGroupOfRegistersAdded 1
				lappend fullListOfRegisters [list $myRegistersGroup $listOfRegistersOfOneGroup]
			}
			set myRegistersGroup [string tolower [string map {" " _ / _ } [string trim $name]]]
			set listOfRegistersOfOneGroup {}
			set isInBitField 0
		}
		$cellOffset				-destroy
		$cellName				-destroy
		$cellComment			-destroy
		$cellD					-destroy
		$cellE					-destroy
		$cellBits				-destroy
		$cellNameOff			-destroy
		$cellFieldDescription	-destroy
		incr currentLine
		if { $offset eq  "" && $name eq "" && $comment eq "" && $bits eq "" } {   ; # End of file
			if { [llength $fullListOfRegisters] > 1 } {
				set registerEnd [lindex [lindex [lindex [lindex $fullListOfRegisters end] end] end] 1]			; # TODO : commonaliser avec le code ci-dessus
				if { [regexp "(.+)\\\[(.+)\\\]" [lindex [lindex [lindex [lindex $fullListOfRegisters end] end] end] 0] _ _ size] } {
					set registerEnd [expr { $registerEnd + ($size - 1) * 4 }]
				}
				set registerStart [lindex [lindex $listOfRegistersOfOneGroup 0]                         1]
				set spareSize [expr { ($registerStart - $registerEnd - 4) / 4 }]
				if { $spareSize > 0 } {
					lappend fullListOfRegisters [list spare_[format %02d $spareId]\[$spareSize\] [list [list _spare_ ? ?]]]
					incr spareId
				}
			}
			lappend fullListOfRegisters [list $myRegistersGroup $listOfRegistersOfOneGroup]
			break
		}
		if { $offset ne "" } {  ; # To cope with table of bitfields (lots of empty lines)
			set offsetPrev $offset
		}
	}
	$termColor putsColor \[INF] INF 1
	$termColor putsColor " Parsing of '$sheet' done." NORMAL

	# Generate header :
	set outFile R:/source/oss/driver/fpga/fpga_reg_[string tolower ${sheet}].h
	file delete -force $outFile
	set fh [open $outFile w]
	
	puts $fh "/* --------------------------------------------------------------------------"
	puts $fh " *                        SAFRAN Electronics & Defense"
	puts $fh " *                   Reproduction and disclosure forbidden."
	puts $fh " * -------------------------------------------------------------------------- */"
	puts $fh ""
	puts $fh "#ifndef FPGA_REG_[string toupper $sheet]_H"
	puts $fh "#define FPGA_REG_[string toupper $sheet]_H"
	puts $fh ""
	puts $fh "/* ---------- Linker command file symbol: ----------------------------------- */"
	puts $fh ""
	puts $fh "/* ---------- include required interface: ----------------------------------- */"
	puts $fh "#include \"type/mcp_types.h\""
	puts $fh "#include \"type/common_type.h\""
	puts $fh ""
	puts $fh "/* ---------- Linker command file symbol: ----------------------------------- */"
	puts $fh ""
	puts $fh "/* ---------- provided define constants: ------------------------------------ */"
	puts $fh ""
	puts $fh "/* ---------- provided types: ----------------------------------------------- */"
	puts $fh ""

	set currentAddr 0
	foreach groupOfRegs $fullListOfRegisters {
		lassign $groupOfRegs registersGroupName listOfRegisters
		if { [regexp "^spare_..\\\[.+\\\]\$" $registersGroupName] } {
			continue
		}
		foreach registerConf $listOfRegisters {
			lassign $registerConf regName regAddr bits
			if { [llength $bits] > 1 } {
				puts $fh "/* Union definition for register 's_[string tolower ${regName}]' */"
				puts $fh "typedef struct"
				puts $fh "\{"
				set usedBitsNames {}
				set linesToDump {}
				foreach setOfBits $bits {
					lassign $setOfBits theBits dataName fieldDescription
					set theBits [lindex [split $theBits \n] end]
					if { [regexp "^\(.+)\[:](.+)\$" $theBits _ start stop] } {
						if { $dataName eq "Not used" } {
							lappend linesToDump [list s_spare_${start}_to_${stop} [expr { $start - $stop + 1 }] $theBits $fieldDescription]
						} else {
							# In case of multiple occurrence of the same field in structure ("reserved"...) dataName, let's add a suffix whenever required :
							set suffixedName $dataName
							set suffixIndex 0
							while { [lsearch -exact $usedBitsNames $suffixedName] != -1 } {
								set suffixedName "${dataName}_[format %02d $suffixIndex]"
								incr suffixIndex
							}
							set dataName $suffixedName
							# Add item :
							lappend usedBitsNames $dataName
							lappend linesToDump [list s_${dataName} [expr { $start - $stop + 1 }] $theBits $fieldDescription]
						}
					} else {
						lappend linesToDump [list s_${dataName} " 1" [format %02d $theBits] $fieldDescription]
					}
				}
				set maxLen_unionMember		0
				set maxLen_bitsCount		0
				set maxLen_bitsDescr		0
				set maxLen_fieldDescription	0
				foreach line $linesToDump {
					lassign $line unionMember bitsCount bitsDescr fieldDescription
					foreach data {unionMember bitsCount bitsDescr fieldDescription} {
						if { [set maxLen_$data] < [string length [set $data]] } {
							set maxLen_$data [string length [set $data]]
						}
					}
				}
				foreach line $linesToDump {
					lassign $line unionMember byteCount bitsDescr fieldDescription
					puts -nonewline $fh "   uint32_t "
					puts -nonewline $fh "[::GenericProcs::padStrUntilAndWith $unionMember $maxLen_unionMember] "
					puts -nonewline $fh ": [::GenericProcs::padStrUntilAndWith $byteCount   $maxLen_bitsCount " " right]; "
					puts            $fh "/* Bits : [::GenericProcs::padStrUntilAndWith $bitsDescr   $maxLen_bitsDescr] : [::GenericProcs::padStrUntilAndWith [string trim $fieldDescription] $maxLen_fieldDescription] */"
				}
				puts $fh "\}"
				set baseName _fpga_reg_[string tolower $sheet]_[string tolower ${regName}]
				puts $fh "ts${baseName}_u_bit;"
				puts $fh ""
				puts $fh "typedef union"
				puts $fh "\{"
				puts $fh "   [::GenericProcs::padStrUntilAndWith uint32_t [string length ts${baseName}_u_bit ]] u_word;"
				puts $fh "   ts${baseName}_u_bit u_bit;"
				puts $fh "\}"
				puts $fh "tu${baseName};"
				puts $fh ""
			}
		}
			
		puts $fh "/* Group of registers in '$sheet' named '$registersGroupName' */"
		puts $fh "typedef struct"
		puts $fh "\{"
		set linesToDump {}
		set maxLen 0
		set currentAddr [lindex [lindex $listOfRegisters 0] 1]   ; # TODO :; check that group of registers adderss mataches first element ! and first group is offset zero too otherwise mapping pb..
		foreach registerConf $listOfRegisters {
			lassign $registerConf regName regAddr bits
			set spareSize 0
			set potentialStartSpare $currentAddr
			while { $regAddr > $currentAddr } { ; # TODO ; faire une soustraction...
				incr currentAddr 4
				incr spareSize   4
			}
			if { $spareSize > 0 } {
				puts "        << spare  0x[format %x $potentialStartSpare] -> 0x[format %x [expr { $currentAddr - 1}]] >> (0x[format %x $spareSize] bytes)"
				lappend linesToDump [list uint32_t "spare_0x[format %x $potentialStartSpare]_to_0x[format %x [expr { $currentAddr - 1}]]\[[expr { $spareSize / 4}]]"]
			}
			if {[llength $bits] > 1 } {
				lappend linesToDump [list "tu_fpga_reg_[string tolower $sheet]_[string tolower ${regName}]" "s_[string tolower ${regName}]"]
			} else {
				lappend linesToDump [list uint32_t "s_[string tolower ${regName}]"]
			}	
			if { [regexp "(.+)\\\[(.+)\\\]" $regName _ baseNameForReg sizeReg] } {
				incr currentAddr [expr { $sizeReg * 0x04 }]
			} else {
				incr currentAddr 0x04
			}
			if { $maxLen < [string length [lindex [lindex $linesToDump end] 0]] } {
				set maxLen [string length [lindex [lindex $linesToDump end] 0]]
			}
		}
		foreach line $linesToDump {
			lassign $line dataType dataName
			puts $fh "   [::GenericProcs::padStrUntilAndWith $dataType $maxLen] $dataName;"
		}
		puts $fh "\}"
		puts $fh "ts_fpga_reg_[string tolower $sheet]_${registersGroupName};"
		puts $fh ""
		puts $fh "/* ------------------------------------------------------------------------------- */"
		puts $fh ""
	}

	puts $fh "/* General definition of registers in '$sheet' */"
	puts $fh ""
	puts $fh "typedef struct"
	puts $fh "\{"
	
	set linesToDump {}
	set maxLen 0
	foreach groupOfRegs $fullListOfRegisters {
		lassign $groupOfRegs registersGroupName listOfRegisters
		if { [regexp "spare_(..)\\\[(.+)\\\]" $registersGroupName _ spareId sizeSpare] } {
			lappend linesToDump [list uint32_t s_${registersGroupName};]
		} else {
			lappend linesToDump [list ts_fpga_reg_[string tolower $sheet]_${registersGroupName} s_${registersGroupName}_regs;]
		}
		if { $maxLen < [string length [lindex [lindex $linesToDump end] 0]] } {
			set maxLen [string length [lindex [lindex $linesToDump end] 0]]
		}
	}
	foreach line $linesToDump {
		lassign $line dataType dataName
		puts $fh "   [::GenericProcs::padStrUntilAndWith $dataType $maxLen] $dataName;"
	}
	puts $fh "\}"
	puts $fh "ts_fpga_reg_[string tolower $sheet];"
	
	puts $fh ""
	puts $fh "#endif /* FPGA_REG_[string toupper $sheet]_H */"
	close $fh
	$cells -destroy
	puts "File generated : [file nativename $outFile]"
	$detectedSheets($sheet) -destroy
}

closeExcelFileAndQuit $excel $workbooks $workbook $sheets
