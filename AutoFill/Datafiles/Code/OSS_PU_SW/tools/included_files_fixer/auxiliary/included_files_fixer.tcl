set auxiliaryPath [file dirname [info script]]
source $auxiliaryPath/../../_tcl_utils/genericProcs.tcl
source $auxiliaryPath/../../_tcl_utils/class_TermColor.tcl
source $auxiliaryPath/../../_tcl_utils/genericScanner.tcl
#----------------------------------------------------------------------------------------------------------------------------------
set termColor [TermColor new {						\
	{ NORMAL			white	1		black 	0 } \
	{ HEADER			yellow	1		black 	0 } \
	{ ERROR				red		1		black 	0 } \
	{ QUESTION 			green 	1		black 	0 } \
}]
#----------------------------------------------------------------------------------------------------------------------------------
set f [open $auxiliaryPath/../data/headers.csv r]
set files {}
while {[ gets $f line] >= 0 } {
	set line [string trim $line]
	set listOfpossibleIncludedFiles([file tail $line]) $line
}
close $f
parray listOfpossibleIncludedFiles
#----------------------------------------------------------------------------------------------------------------------------------
proc actionOnFile { file params } {
	set g [open $file.new w]

	set f [open $file r]
	while {[ gets $f line] >= 0 } {
	
		if { [regexp "^\[\#]include +\"(.+)\"" $line _ fileName] } {
			if { [catch { puts $g "#include \"$::listOfpossibleIncludedFiles($fileName)\"" } errorMsg] } {
				puts $g $line
				$termColor putsColor "\n  ***ERR : " ERROR 1
				$termColor putsColor "Header file '" NORMAL 1
				$termColor putsColor $fileName HEADER 1
				$termColor putsColor "' not found in .csv file !" NORMAL
				$termColor putsColor "           Note : It is included in file '" NORMAL 1
				$termColor putsColor $file HEADER 1
				$termColor putsColor "'" NORMAL
			}
		} else {
			puts $g $line
		}
	}
	close $f
	close $g
	
	if { $::dryRun != 1 } {
		file copy   -force $file.new $file
		file delete -force $file.new
	}
}
#----------------------------------------------------------------------------------------------------------------------------------
$termColor putsColor "QUESTION : " QUESTION 1
puts -nonewline "Do you want a dry run ? \[y] > "
flush stdout
gets stdin line
set line [string trim $line]
if { $line eq "" || $line eq "y" || $line eq "Y" || $line eq "yes" } {
	set ::dryRun 1
} else {
	set ::dryRun 0
}
#----------------------------------------------------------------------------------------------------------------------------------
set fileTypes [list *.h *.c ]
set ignoredDirs { }
::GenericScanner::recursivelyPerformActionIn "R:/Source" $ignoredDirs "prefix" $fileTypes "" {} "" {} actionOnFile {tutu} 1 {} {}	
#----------------------------------------------------------------------------------------------------------------------------------
