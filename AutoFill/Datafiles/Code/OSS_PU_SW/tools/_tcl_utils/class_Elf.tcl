#========================================================================================================================================================================================================
oo::class create Elf {
#------------------------------------------------------------------------------ M E M B E R    V A R I A B L E S ----------------------------------------------------------------------------------------
	variable m_fullPath
	variable m_elfData
	variable m_maxSectioNameLen
#----------------------------------------------------------------------------------- C O N S T R U C T O R ----------------------------------------------------------------------------------------------
	constructor { fullPath } {
		set m_maxSectioNameLen 0
		set m_fullPath $fullPath
		#puts "Trying to read elf $m_fullPath..."
		if { ![file exists $m_fullPath] } {
			$::termColor putsColor "  ***ERR : " ERROR 1
			puts "\[::Elf::constructor] Cannot read file '$m_fullPath' !"
			exit 1
		} else {
			set result [exec  objdump -hwr $m_fullPath]   ; # alternate : readelf -SW $elf
			set parsedLines {}
			set result [split $result \n]
			foreach line  $result {
				set regExpLine "^ +(\[0-9]+) (\[^ ]+) +(\[0-9a-f]+) +(\[0-9a-f]+) +(\[0-9a-f]+) +(\[0-9a-f]+) +(\[0-9*]+)  (.*)\$"
				if { [regexp $regExpLine $line dummy ID sectionName size VMA LMA offset algn flags] } {
					foreach f [split $flags ,] {
						lappend flags [string trim $f]
					}
					lappend m_elfData [list $ID $sectionName 0x$VMA 0x$size $algn $flags]
					if { [string length $sectionName] > $m_maxSectioNameLen } {
						set m_maxSectioNameLen [string length $sectionName]
					}
				}
			}	
		}
	}
#-------------------------------------------------------------------------------- P U B L I C    M E T H O D S ------------------------------------------------------------------------------------------
	method getElfData { } {
		return $m_elfData
	}
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
	method display { { sortMode StartAddr} } {
		switch -exact $sortMode {
			StartAddr {
				set sortIndex 2
				set sortFlag "integer"
			}
			Section {
				set sortIndex 1
				set sortFlag "ascii"
			}
			ID {
				set sortIndex 0
				set sortFlag "integer"
			}
			default {
				$::termColor putsColor  "***ERR"
				puts " : Unknown sort mode '$sortmode' !"
				puts "         -> Aborted."
				exit 1
			}
		}
		puts "+----+-[GenericProcs::padStrUntilAndWith - [my GetMaxSectionLen] "-"]-+------+------------+-------------------+-----+  File : [file tail $m_fullPath]"
		puts "| ID | [GenericProcs::padStrUntilAndWith {Section name} [my GetMaxSectionLen]] | TYPE | StartAddr  | Size       | Alig | R/W |  In   : [file dirname $m_fullPath]"
		puts "+----+-[GenericProcs::padStrUntilAndWith - [my GetMaxSectionLen] "-"]-+------+------------+-------------------+-----+  Sort : $sortMode"
		set previousEndAddr ?
		foreach data [lsort -$sortFlag -index $sortIndex $m_elfData] {
			lassign $data ID sectionName VMA size algn flags
			set paddedID [GenericProcs::padStrUntilAndWith [format %0.2d $ID] 3]
			if { ($sortMode eq "StartAddr") && ($previousEndAddr ne "?") && ($previousEndAddr < $VMA ) } {
				puts -nonewline "| "
				flush stdout
				$::termColor putsColor "--" ELF_SPARE 1
				puts -nonewline " | "
				flush stdout
				$::termColor putsColor [GenericProcs::padStrUntilAndWith SPARE [my GetMaxSectionLen] "-" center] ELF_SPARE 1
				puts -nonewline " | "
				flush stdout
				$::termColor putsColor "----" ELF_SPARE 1
				puts -nonewline " | "
				flush stdout
				$::termColor putsColor 0x[format %0.8x $previousEndAddr] ELF_SPARE 1
				puts -nonewline " | "
				flush stdout
				$::termColor putsColor 0x[format %0.8x [expr { $VMA - $previousEndAddr }]] ELF_SPARE 1
				puts -nonewline " | "
				flush stdout
				$::termColor putsColor "----" ELF_SPARE 1
				puts -nonewline " | "
				flush stdout
				$::termColor putsColor "---" ELF_SPARE 1
				puts " |"
				
			}
			set previousEndAddr [expr { $VMA + $size}]
			set paddedSectionName [GenericProcs::padStrUntilAndWith $sectionName [my GetMaxSectionLen]]
			$::termColor putsColor "| $paddedID| " NORMAL 1
			if { [lsearch -exact $flags CODE] != -1 } {
				set codeOrData CODE
				if { [string first .text $paddedSectionName] == 0 } {
					$::termColor putsColor .text ELF_KEYWORD_TEXT 1
					$::termColor putsColor [string range $paddedSectionName 5 end] NORMAL 1
				} else {
					$::termColor putsColor $paddedSectionName NORMAL 1
				}
			} else {
				set codeOrData DATA
				if { [string first .bss $paddedSectionName] == 0 } {
					$::termColor putsColor .bss ELF_KEYWORD_BSS 1
					$::termColor putsColor [string range $paddedSectionName 4 end] NORMAL 1
				} elseif { [string first .rodata $paddedSectionName] == 0 } {
					$::termColor putsColor .rodata ELF_KEYWORD_RODATA 1
					$::termColor putsColor [string range $paddedSectionName 7 end] NORMAL 1
				} elseif { [string first .data $paddedSectionName] == 0 } {
					$::termColor putsColor .data ELF_KEYWORD_DATA 1
					$::termColor putsColor [string range $paddedSectionName 5 end] NORMAL 1
				} elseif { [string first .debug $paddedSectionName] == 0 } {
					$::termColor putsColor .debug ELF_KEYWORD_DEBUG 1
					$::termColor putsColor [string range $paddedSectionName 6 end] ELF_KEYWORD_DEBUG 1
				} else {
					$::termColor putsColor $paddedSectionName NORMAL 1
				}
			}
			$::termColor putsColor  " | " NORMAL 1
			$::termColor putsColor  $codeOrData ELF_$codeOrData 1
			$::termColor putsColor  " | $VMA | " NORMAL 1
			if {  $size == 0 } {
				set sizeColor ZEROSIZE
			} else {
				set sizeColor NORMAL
			}
			$::termColor putsColor  $size  $sizeColor 1
			$::termColor putsColor  " | $algn |" NORMAL 1
			if { [lsearch -exact $flags READONLY] != -1 } {
				$::termColor putsColor  "  R  |" NORMAL
			} else {
				$::termColor putsColor  " R+W |" NORMAL
			}
		}
		puts "+----+-[GenericProcs::padStrUntilAndWith - [my GetMaxSectionLen] "-"]-+------+------------+-------------------+-----+"
	}
#-------------------------------------------------------------------------------- P R I V A T E    M E T H O D S ----------------------------------------------------------------------------------------
	method GetMaxSectionLen { } {
		return $m_maxSectioNameLen
	}
}
#========================================================================================================================================================================================================
