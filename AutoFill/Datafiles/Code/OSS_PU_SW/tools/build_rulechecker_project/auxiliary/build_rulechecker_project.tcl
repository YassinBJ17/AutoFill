set kalimetrixPath "C:/Program Files (x86)/Kalimetrix/Logiscope/7.2.2"
#---------------------------------------------------------------------------------------------------------------------------------------------------------
set dirsForSrc {                       \
      R:/source/css_wrapper_g1_2_3     \
      R:/source/css_wrapper_g4         \
      R:/source/css_wrapper_stub       \
      R:/source/lib_critical_service   \
      R:/source/mcss_wrapper           \
      R:/source/oss                    \
      R:/source/shared                 \
      R:/source/uod_wrapper            \
}
#---------------------------------------------------------------------------------------------------------------------------------------------------------
if {[catch { file delete -force R:/tools/build_rulechecker_project/project_files } errorMsg] } {
	puts "***ERR : Cannot delete R:/tools/build_rulechecker_project/project_files !"
	puts "         Aborted."
	exit 0
}
file mkdir         R:/tools/build_rulechecker_project/project_files
#---------------------------------------------------------------------------------------------------------------------------------------------------------
set auxiliaryPath [file dirname [info script]]
source $auxiliaryPath/../../_tcl_utils/genericProcs.tcl
source $auxiliaryPath/../../_tcl_utils/class_TermColor.tcl
source $auxiliaryPath/../../_tcl_utils/genericScanner.tcl
#---------------------------------------------------------------------------------------------------------------------------------------------------------
set termColor [TermColor new {	                    \
	{ NORMAL			white	1		black 	0 }	\
	{ TITLE				yellow	1		blue 	1 }	\
	{ GREEN				green	1		black 	0 }	\
	{ INVERTED			yellow 	1		black	0 }	\
	{ WARNING			yellow	1		black 	0 }	\
	{ ZEROSIZE			black 	0		gray	0 }	\
	{ ERROR				red		1		black 	0 }	\
	{ OK				green	1		black 	0 }	\
	{ UNKNOWN			gray	0		black 	0 }	\
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
set fileTypes [list *.c *.h]
set ignoredDirs { }
foreach dir $dirsForSrc {
   ::GenericScanner::recursivelyPerformActionIn $dir $ignoredDirs "prefix" $fileTypes enteringDir {} leavingDir {} actionOnFile {::listOfFiles}   0 {} {}
}
#---------------------------------------------------------------------------------------------------------------------------------------------------------
set fileName $::env(TMP)/listOfSourceFiles.txt
file delete -force $fileName
set fh_out [open $fileName w]
set nbOfConsideredFiles 0
set nbOfDiscardedFiles  0
foreach file $::listOfFiles {
   if { [string is upper [string index [file tail $file] 0]] } {
      puts "Discarding file : $file"
      incr nbOfDiscardedFiles
   } else {
      puts $fh_out [file nativename $file]
      incr nbOfConsideredFiles
   }
}
close $fh_out
puts "$nbOfDiscardedFiles file(s) discarded."
puts "$nbOfConsideredFiles file(s) added."
#---------------------------------------------------------------------------------------------------------------------------------------------------------
set result [exec "$kalimetrixPath/bin/create.exe" $auxiliaryPath/../project_files/oss_pu.ttp \
   -lang c -rule \
   -list $fileName \
   -def $auxiliaryPath/../config/mydef.def \
   -mac $auxiliaryPath/../config/mydef.mac \
   -dial ansi \
   -rules C:/App/SYNCHRONe/RuleCheckerForSYNCHRONe/4.3/CRulesQualified/RuleSets/C/SYNCHRONe_CSCI.rst \
   -rules C:/App/SYNCHRONe/RuleCheckerForSYNCHRONe/4.3/CRulesQualified/RuleSets/C/SYNCHRONe_MCP_only.rst \
   -ign $auxiliaryPath/../config/mydef.ign \
   -relax]
if { $result ne "" } {
   puts "Unexpected result : $result"
   exit 1
} else {
   puts -nonewline "Project file oss_pu.ttp generated in [file normalize [file dirname [info script]]/../project_files/] : \["
   $termColor putsColor "OK" GREEN 1
   puts -nonewline ]
   flush stdout
   exec "$kalimetrixPath/bin/VCS.EXE" R:/tools/build_rulechecker_project/project_files/oss_pu.ttp &
}
#---------------------------------------------------------------------------------------------------------------------------------------------------------
if {[catch { file copy -force R:/tools/build_rulechecker_project/rst_fix/oss_pu.rst  \
   R:/tools/build_rulechecker_project/project_files/ } errorMsg] } {
   puts "***ERR : Cannot copy rst_fix file !"
   puts "         Aborted."
   exit 0
}
#---------------------------------------------------------------------------------------------------------------------------------------------------------
