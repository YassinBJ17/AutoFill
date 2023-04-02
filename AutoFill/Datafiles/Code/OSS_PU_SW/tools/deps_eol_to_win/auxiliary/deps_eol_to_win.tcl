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
proc actionOnFile { file params } {
	set g [open $file.new w]
	
	fconfigure $g -translation crlf
	
	set f [open $file r]
	while {[ gets $f line] >= 0 } {
		puts $g $line
	}
	close $f
	close $g
	
	file copy   -force $file.new $file
	file delete -force $file.new
}
#----------------------------------------------------------------------------------------------------------------------------------
set fileTypes [list *.d]
set ignoredDirs { }
::GenericScanner::recursivelyPerformActionIn "R:/_build_out/dep" $ignoredDirs "prefix" $fileTypes "" {} "" {} actionOnFile {tutu} 1 {} {}	
#----------------------------------------------------------------------------------------------------------------------------------
