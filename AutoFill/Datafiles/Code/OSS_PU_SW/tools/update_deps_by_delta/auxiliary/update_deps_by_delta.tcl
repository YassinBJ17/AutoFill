#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
set auxiliaryPath [file dirname [info script]]
source $auxiliaryPath/../../_tcl_utils/genericProcs.tcl
source $auxiliaryPath/../../_tcl_utils/class_TermColor.tcl
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
set termColor [TermColor new {	\
	{ WNG				black 0	yellow	0 } \
	{ INF				black 0	green   1 } \
	{ ERR				black 0	red		1 } \
}]
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
package require Tk
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
ttk::labelframe .myFrame -text Password 
ttk::label .myFrame.lab -text "Synergy password for [string tolower $::env(USERNAME)] :" 
ttk::entry .myFrame.entry -width 30 -show * 

pack .myFrame.lab -side left -padx 4 -pady 4
pack .myFrame.entry -side left -padx 4 -pady 4
pack .myFrame -padx 4 -pady 4
bind .myFrame.entry <Escape>      abortUpdate
bind .myFrame.entry <Key-Return>  validatePassword

listbox .myFrame.combo -height  10 -width 80
bind .myFrame.combo <Escape>      abortUpdate
bind .myFrame.combo <Key-Return>  { set ::task [lindex [set ::listOfTasksForMe] [.myFrame.combo curselection]] }
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
# Find out real work area path behind "R" drive :
set regexp_subst ": => (.+)" 
if { [regexp $regexp_subst [exec subst] _ workAreaPath] } {
	set workAreaPath [file normalize $workAreaPath]
	$::termColor putsColor "\[INF]" INF 1
	puts " Work area (R:) : $workAreaPath"
} else {
	$::termColor putsColor "\[ERR]" ERR 1
	puts " Could not find work area path !"
	exit 0
}
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
proc abortUpdate { } {
	$::termColor putsColor "\[INF]" INF 1
	puts " Aborted."
	exit 0
}
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
proc updateFocus { focusWidget } {
	focus -force $focusWidget
	set ::after_id [after 200 updateFocus $focusWidget]
}
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
proc validatePassword { } {
	set ::password [.myFrame.entry get]
}
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
after idle {
   update
   set mainWindowWidth  [winfo screenwidth .]
   set mainWindowHeight [winfo screenheight .]
   set mainWindowPosX   0
   set mainWindowPosY   0
   set dialogPosX [expr $mainWindowPosX + ($mainWindowWidth  / 2) - ([winfo reqwidth  .] / 2)]
   set dialogPosY [expr $mainWindowPosY + ($mainWindowHeight / 2) - ([winfo reqheight .] / 2)]
   wm geometry . +$dialogPosX+$dialogPosY
   wm overrideredirect . 1
   updateFocus .myFrame.entry
}
vwait password
after cancel $::after_id
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
wm withdraw .
destroy .myFrame.lab
destroy .myFrame.entry
pack .myFrame.combo -side top -padx 4 -pady 4
.myFrame configure -text "Task selection"
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
$::termColor putsColor "\[INF]" INF 1
puts -nonewline " Retrieving pre-existing Synergy sessions..."
flush stdout
set sessions [split [exec "C:/Program Files (x86)/IBM/Rational/Synergy/7.1/bin/ccm" status] \n]
puts Done
foreach line $sessions {
	if { [regexp "^Command Interface @" $line] } {
		$::termColor putsColor "\[INF]" INF 1
		puts -nonewline " Removing pre-existing Synergy session $line..."
		flush stdout
		set ::env(CCM_ADDR) $line
		exec "C:/Program Files (x86)/IBM/Rational/Synergy/7.1/bin/ccm" stop
		puts Done
	}
}
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
$::termColor putsColor "\[INF]" INF 1
puts -nonewline " Starting Synergy session..."
flush stdout
if { [catch { set cliSession [exec "C:/Program Files (x86)/IBM/Rational/Synergy/7.1/bin/ccm" start -q -m -s http://synergy7c.sds.safran:8410  -n [string toupper $::env(USERNAME)] -d /opt/ccm/databases/FADEX -pw $password] } errorMsg] } {
	puts ""
	$::termColor putsColor "\[ERR]" ERR 1
	puts " Invalid username or password !"
	$::termColor putsColor "\[INF]" INF 1
	puts " Aborted."
	exit 0
}
puts Done
set ::env(CCM_ADDR) $cliSession

$::termColor putsColor "\[INF]" INF 1
puts " Synergy session started -> '$cliSession'"
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
proc puts_pipe { pipe } {
	gets $pipe line
	if { $line ne "" } {
		puts $line
	}
	if { [eof $pipe] } {
		close $pipe
		set ::forever 0
	}
}
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
$::termColor putsColor "\[INF]" INF 1
puts -nonewline " Retrieving tasks for $::env(USERNAME)..."
flush stdout
set listOfTasksForMe [split [exec "C:/Program Files (x86)/IBM/Rational/Synergy/7.1/bin/ccm" query /type task /state task_assigned /o [string toupper $::env(USERNAME)] -f "%displayname %task_synopsis"] \n]
puts Done.
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
if { [llength $listOfTasksForMe] == 0 } {
	$::termColor putsColor "\[ERR]" ERR 1
	puts " Could not find available tasks for $::env(USERNAME) !"
	$::termColor putsColor "\[ERR]" ERR 1
	puts " Aborted."
	exit 0
}
.myFrame.combo configure -listvariable ::listOfTasksForMe
wm deiconify .
after idle {
   update
   set mainWindowWidth  [winfo screenwidth .]
   set mainWindowHeight [winfo screenheight .]
   set mainWindowPosX   0
   set mainWindowPosY   0
   set dialogPosX [expr $mainWindowPosX + ($mainWindowWidth  / 2) - ([winfo reqwidth  .] / 2)]
   set dialogPosY [expr $mainWindowPosY + ($mainWindowHeight / 2) - ([winfo reqheight .] / 2)]
   wm geometry . +$dialogPosX+$dialogPosY
   wm overrideredirect . 1
   updateFocus .myFrame.combo
}
vwait ::task
after cancel $::after_id
wm withdraw .
destroy .
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
if { ![regexp "^\[^\\)]+\[\\)] (\[^ ]+) (.+)\$" $::task _ taskId taskSynopsis]  } {
	$::termColor putsColor "\[ERR]" ERR 1
	puts " Cannot match task id !"
	puts " Aborted."
	exit 0
}
set ::task $taskId
$::termColor putsColor "\[INF]" INF 1
puts " Selected task : $::task"
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
exec >&@stdout R:/tools/deltree/deltree.bat R:/_build_out/dep
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
exec >&@stdout R:/tools/deltree/deltree.bat R:/_build_out/dep_new
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
$::termColor putsColor "\[INF]" INF 1
puts " Rebuilding dependencies..."
exec >&@stdout make -f R:/_build_proc/mak/Makefile dep    ; # See : https://wiki.tcl-lang.org/page/exec
$::termColor putsColor "\[INF]" INF 1
puts " Rebuilding dependencies...Done"
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
exec >&@stdout R:/tools/deps_eol_to_win/deps_eol_to_win.bat
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
while { [catch { file rename r:/_build_out/dep r:/_build_out/dep_new } errorMsg] } {
	$::termColor putsColor "\[WNG]" WNG 1
	puts " Cannot rename r:/_build_out/dep into r:/_build_out/dep_new !"
	after 500
}
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
$::termColor putsColor "\[INF]" INF 1
puts " Discarding work area modifications from R:/_build_out/dep..."
set pipe [open "|\"C:/Program Files (x86)/IBM/Rational/Synergy/7.1/bin/ccm\" reconcile -r -update_wa ${workAreaPath}/_build_out/dep"]
fileevent $pipe readable [list puts_pipe $pipe]
vwait ::forever
$::termColor putsColor "\[INF]" INF 1
puts " Discarding done."
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
$::termColor putsColor "\[INF]" INF 1
puts -nonewline " Waiting for Winmerge closure..."
flush stdout
exec "C:/Program Files (x86)/WinMerge/WinMergeU.exe" /r R:/_build_out/dep R:/_build_out/dep_new
puts Done
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
exec >&@stdout R:/tools/deltree/deltree.bat R:/_build_out/dep_new
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
$::termColor putsColor "\[INF]" INF 1
puts -nonewline " Setting default task to $::task..."
flush stdout
exec "C:/Program Files (x86)/IBM/Rational/Synergy/7.1/bin/ccm" task -default $::task
puts Done
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
$::termColor putsColor "\[INF]" INF 1
puts -nonewline " Changing task synopsis..."
flush stdout
exec "C:/Program Files (x86)/IBM/Rational/Synergy/7.1/bin/ccm" task -mod -s "\[OSS_PU_SW] INTEG : Update .dep files on [clock format [clock seconds]]" $::task
puts Done
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
$::termColor putsColor "\[INF]" INF 1
puts " Updating Synergy database from work area modifications in R:/_build_out/dep..."
set pipe [open "|\"C:/Program Files (x86)/IBM/Rational/Synergy/7.1/bin/ccm\" reconcile -r -consider_uncontrolled -update_db ${workAreaPath}/_build_out/dep"]
fileevent $pipe readable [list puts_pipe $pipe]
vwait ::forever
$::termColor putsColor "\[INF]" INF 1
puts " Synergy db update done."
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
set result [exec "C:/Program Files (x86)/IBM/Rational/Synergy/7.1/bin/ccm" stop]
$::termColor putsColor "\[INF]" INF 1
puts " $result"
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
