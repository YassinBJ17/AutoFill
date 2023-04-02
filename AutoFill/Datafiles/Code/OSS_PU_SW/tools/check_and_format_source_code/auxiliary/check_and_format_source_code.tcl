#---------------------------------------------------------------------------------------------------------------------------------------------------------
set dirsForSrc {r:/source \
}
set auxiliaryPath [file dirname [info script]]
source $auxiliaryPath/../../_tcl_utils/genericProcs.tcl
source $auxiliaryPath/../../_tcl_utils/class_TermColor.tcl
source $auxiliaryPath/../../_tcl_utils/genericScanner.tcl
#---------------------------------------------------------------------------------------------------------------------------------------------------------
set termColor [TermColor new {							\
	{ NORMAL				white	1		black 	0 } \
	{ CODE					blue	1		black 	0 } \
	{ TITLE					yellow	1		blue 	1 } \
	{ GREEN					green	1		black 	0 } \
	{ INVERTED				yellow	1		black	0 } \
	{ WARNING				yellow	0		black 	0 } \
	{ ZEROSIZE				black 	0		gray	0 } \
	{ ERROR					red		1		black 	0 } \
	{ OK					green	1		black 	0 } \
	{ UNKNOWN				gray	0		black 	0 } \
}]
#---------------------------------------------------------------------------------------------------------------------------------------------------------
proc leavingDir { } {
}
#---------------------------------------------------------------------------------------------------------------------------------------------------------
proc enteringDir { } {
}
#---------------------------------------------------------------------------------------------------------------------------------------------------------
proc actionOnFile { file myVar } {
	lappend $myVar [pwd]/$file
}
#---------------------------------------------------------------------------------------------------------------------------------------------------------
set fileTypes [list *.c *.h *.psyh]
set ignoredDirs { }
foreach dir $dirsForSrc {
	::GenericScanner::recursivelyPerformActionIn $dir $ignoredDirs "prefix" $fileTypes enteringDir {} leavingDir {} actionOnFile {::listOfFiles}   0 {} {}	
}
#---------------------------------------------------------------------------------------------------------------------------------------------------------
set tempFileName $::env(TMP)/out.txt
file delete -force $tempFileName
set nbOfFilesChanged	0
set lastMsgLen 0
set nbOfErrSpecial		0

set templateLine_h(1)	"/* --------------------------------------------------------------------------" 
set templateLine_h(2)	" *                        SAFRAN Electronics & Defense"
set templateLine_h(3)	" *                   Reproduction and disclosure forbidden."
set templateLine_h(4)	" * -------------------------------------------------------------------------- */"

set templateLine_c(1)	"/* --------------------------------------------------------------------------" 
set templateLine_c(2)	" *                        SAFRAN Electronics & Defense"
set templateLine_c(3)	" *                   Reproduction and disclosure forbidden."
set templateLine_c(4)	" * --------------------------------------------------------------------------"
set templateLine_c(5)	" * DESCRIPTION : <short description of the operations of the .c file>"
set templateLine_c(6)	" * --------------------------------------------------------------------------"

foreach file $::listOfFiles {
	set fh_in  [open $file         r]
	set fh_out [open $tempFileName w]
	set lineNumber 1
	set alertTab				0
	set alertAutoFix			0
	set alertOutOfRangeAscii	0
	set alertComment			0
	set hasToReplaceDefine      0
	set headerStr ""
	switch -exact [string index $file end] {
		c {
			set maxLineForChecks 4  ; #TODO improve DESCRIPTION detection !
			set isHeaderFile 0
		}
		h {
			set maxLineForChecks 4
			set isHeaderFile 1
		}
		default {
			puts "Extension error : $file"
			exit 1
		}
	}
	while { [gets $fh_in line] >= 0 } {
		set lineFromFile($lineNumber) $line
		# 0) Check first lines :
		if { $lineNumber == $maxLineForChecks } {
			for { set i 1 } { $i <= $maxLineForChecks } { incr i } {
				set lineToConsider [set ::templateLine_[string index $file end]($i)]
				if { $lineFromFile($i) ne $lineToConsider } {
					$termColor putsColor "  ***ERR : " ERROR 1
					puts "Header is incorrect, line [format "%5d" $i] fixed         : [file nativename $file]"
					append headerStr $lineToConsider\n
				} else {
					append headerStr $lineFromFile($i)\n
				}
			}
			puts -nonewline $fh_out $headerStr
			incr lineNumber
			break
		}
		incr lineNumber
	}
	while { [gets $fh_in line] >= 0 } {
		# 0) Check special Synergy keywords :
		set listOfForbiddenKywords {%derived_by %full_name %date_created}
		foreach keyword $listOfForbiddenKywords {
			if { [string first $keyword $line] != -1 } {
				$termColor putsColor "  ***ERR : " ERROR 1
				puts "Synergy keyword detected        @ line [format "%5d" $lineNumber]  : [file nativename $file]"
			}
		}
		
		# 0) Check line length :
		if { [string length [string trimright $line]] > 120 } {
			$termColor putsColor "  ***WNG : " WARNING 1
			puts "Too long line detected          @ line [format "%5d" $lineNumber]  : [file nativename $file]"
		}
		
		# 0) Trim trailing spaces :
		set line [string trimright $line]
		
		# 0) If line is /* none */, remove it :
		if { [string tolower $line] eq "/* none */" } {
			continue
		}
		
		# 0) Check #ifndef global directives :
		if { $isHeaderFile } {
			if { $hasToReplaceDefine == 0 } {
				if { [regexp "^#ifndef (.+)\$" $line _ ifndefSymbol] } {
					set theoreticalDirective [string toupper [string map {. _} [file tail $file]]]
					if { $ifndefSymbol ne $theoreticalDirective } {
						$termColor putsColor "  ***ERR : " ERROR 1
						puts "Replaced bad #include directive @ line [format "%5d" $lineNumber]  : [file nativename $file]"
						set line "#ifndef $theoreticalDirective"
						set hasToReplaceDefine 1
					}
				}
			} elseif { $hasToReplaceDefine == 1 } {
				set theoreticalDirective [string toupper [string map {. _} [file tail $file]]]
				set line "#define $theoreticalDirective"
				set hasToReplaceDefine 2
			} elseif { $hasToReplaceDefine == 2 } {
				if { [regexp "^#endif" $line] } {
					set hasToReplaceDefine 0
					set line "#endif /* $theoreticalDirective */"
				}
			}
		}
		
		# 1) Replace tabs :
		if { [string first "\t" $line] != -1 } {
			set alertTab 1
			$termColor putsColor "  ***ERR : " ERROR 1
			puts "Replaced tab by 3 spaces        @ line [format "%5d" $lineNumber]  : [file nativename $file]"
			puts -nonewline "             '"
			flush stdout
			$termColor putsColor $line CODE 1
			puts "'"
			puts -nonewline  "              "
			for { set i 0 } { $i < [string length $line] } { incr i } {
				if { [string index $line $i] ne "\t" } {
					puts -nonewline " "
				} else {
					puts -nonewline "^"
				}
			}
			puts ""
			set line [string map {\t "   "} $line]
		}
		
		# 2) Attempt auto correction :
		set fixedLine $line
		catch { set fixedLine [::GenericProcs::myConvertFromBadEncoding $line] }
		if { $fixedLine ne $line } {
			set alertAutoFix 1
			$termColor putsColor "  ***WNG : " WARNING 1
			puts "Performed auto-correction       @ line [format "%5d" $lineNumber]  : [file nativename $file]"
			puts -nonewline "             '"
			flush stdout
			$termColor putsColor $line CODE 1
			puts "'"
			puts -nonewline  "              "
			for { set i 0 } { $i < [string length $line] } { incr i } {
				if { [string index $fixedLine $i] eq [string index $line $i] } {
					puts -nonewline " "
				} else {
					puts -nonewline "^"
				}
			}
			puts ""			
			set line $fixedLine
		}
		
		# 3) Check lower/upper ascii :
		set fixedLine $line
		for { set i 0 } { $i < [string length $line] } { incr i } {
			set char [string index $line $i]
			if { ([scan $char %c] < 32) || \
			     ([scan $char %c] > 127) } {
				set alertOutOfRangeAscii 1
				$termColor putsColor "  ***WNG : " WARNING 1
				puts "Found out of range char         @ line [format "%5d" $lineNumber]  : [file nativename $file]"
				puts -nonewline "             '"
				flush stdout
				$termColor putsColor $line CODE 1
				puts "'"
				puts -nonewline  "              "
				set fixedLine ""
				for { set i 0 } { $i < [string length $line] } { incr i } {
					if { ([scan [string index $line $i] %c] < 32) || \
						 ([scan [string index $line $i] %c] > 127) } {
						puts -nonewline "^"
					} else {
						puts -nonewline " "
						append fixedLine [string index $line $i]
					}
				}
				puts ""
			}
		}
		
		# 4) Check // :
		if { ([string first *// $line] == -1) && ([string first //* $line] == -1) && ([string first // $line] != -1) } {
			set alertComment 1
			$termColor putsColor "  ***WNG : " WARNING 1
			puts "Found // coment                 @ line [format "%5d" $lineNumber]  : [file nativename $file]"
			puts -nonewline "             '"
			flush stdout
			$termColor putsColor $line CODE 1
			puts "'"
			puts -nonewline  "              "
			set fixedLine ""
			for { set i 0 } { $i < [string length $line] - 1 } { incr i } {
				if { [string range $line $i [expr { $i + 1 }]]  eq "//" } {
					puts -nonewline "^"
					append fixedLine /*
					incr i
				} else {
					puts -nonewline " "
					append fixedLine [string index $line $i]
				}
			}
			append fixedLine [string index $line $i]*/
			puts ""
		}
		
		set line $fixedLine
		
		puts $fh_out $line
		incr lineNumber
	}
	close $fh_in
	close $fh_out
	if { [catch { exec diff -q $tempFileName $file } errorMsg] } {
		if { !$alertTab && !$alertAutoFix && !$alertOutOfRangeAscii && !$alertComment } {
			$termColor putsColor "  ***WNG : " WARNING 1
			set msg "Files differ                                  : [file nativename $file]"
			set lastMsgLen [expr { [string length $msg] + 11 }]
			puts $msg
			flush stdout
		}
		if { [catch { file copy -force $tempFileName $file } errorMsg] } {
			$termColor putsColor "  ***ERR : " ERROR 1
			puts "Cannot write file '$file'"
		} else {
			$termColor putsColor "  ***INF : " OK 1
			puts "Patched file                                  : [file nativename $file]"
			incr nbOfFilesChanged
		}
	}
}
$termColor putsColor "" NORMAL 1
flush stdout
puts "Nb of patched files   : $nbOfFilesChanged"
puts "Nb of untouched files : [expr {[llength $::listOfFiles] - $nbOfFilesChanged }]"



