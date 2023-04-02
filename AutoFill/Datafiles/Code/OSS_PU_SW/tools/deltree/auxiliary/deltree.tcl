source [file dirname [info script]]/../../_tcl_utils/genericProcs.tcl
source [file dirname [info script]]/../../_tcl_utils/class_TermColor.tcl
#---------------------------------------------------------------------------------------------------------------------------------------------------------
set termColor [TermColor new {								\
	{ NORMAL				white		1		black 	0 } \
	{ TITLE					yellow		1		blue 	1 } \
	{ GREEN					green		1		black 	0 } \
	{ INVERTED				yellow		1		black	0 } \
	{ WARNING				black		0		yellow	0 } \
	{ FILENAME				yellow		1		black 	0 } \
	{ ZEROSIZE				black 		0		gray	0 } \
	{ ERROR					black		0		red 	1 } \
	{ OK					green		1		black 	0 } \
	{ UNKNOWN				gray		0		black 	0 } \
	{ INF					black		0		gray 	0 } \
}]
#---------------------------------------------------------------------------------------------------------------------------------------------------------
set fileOrDirToDelete [lindex $::argv 0]
if { ![file exists $fileOrDirToDelete] } {
	$termColor putsColor "\[WNG]" WARNING 1
	puts -nonewline " Cannot find file/directory '"
	$termColor putsColor [file nativename $fileOrDirToDelete] FILENAME 1
	puts "', aborted."
	flush stdout
	exit 0
}
set attempt 1
while  { [catch { file delete -force $fileOrDirToDelete } errorMsg] } {
	$termColor putsColor "\[ERR]" ERROR 1
	puts -nonewline " Cannot delete file/directory '"
	$termColor putsColor [file nativename $fileOrDirToDelete] FILENAME 1
	puts "', retrying #$attempt..."
	flush stdout
	after 500
	incr attempt
}
$termColor putsColor "\[INF]" INF 1
puts -nonewline  " File/directory '"
$termColor putsColor [file nativename $fileOrDirToDelete] FILENAME 1
puts -nonewline  "' \["
$termColor putsColor "deleted" GREEN 1
puts "\]"
#---------------------------------------------------------------------------------------------------------------------------------------------------------
