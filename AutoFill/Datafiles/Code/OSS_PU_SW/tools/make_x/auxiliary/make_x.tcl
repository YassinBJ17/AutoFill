#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
package require Tk
package require tooltip
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
set auxiliaryPath [file dirname [info script]]
source $auxiliaryPath/../../_tcl_utils/genericProcs.tcl
source $auxiliaryPath/../../_tcl_utils/class_TermColor.tcl
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
set termColor [TermColor new {	\
	{ WNG				yellow	0		black 	0 } \
	{ INF				black   0		gray    0 } \
	{ TGT				yellow	1		black   0 } \
	{ DATE				blue    1		black   0 } \
}]
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
set ::currentSelectedTarget 0
set ::tempBatFile [file normalize $::env(TMP)]/make_x_target.bat
set ::listOfExcludedTargets { x dep }
set ::listOfExtraTargets    { app_all_with_warnings \
                              app_g1_2_3_int_src_with_warnings \
                              app_g4_int_src_with_warnings \
							  app_stub_uod_int_src_with_warnings \
							}
set ::toolTipsFile "R:\\tools\\make_x\\data\\tooltips.txt"
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
# Retrieve key-values for tool-tips :
set fh [open [file dirname [info script]]/../data/tooltips.txt r]
while { [gets $fh line] >= 0 } {
   set line [string trim $line]
   if { [string index $line 0] eq "#" } {
      continue
   }
   if { [regexp "^(\[^ \t]+)\[ \t]*\"(.+)\"\$" $line _ target text] } {
      set toolTips($target) [string map {\\n \n} $text]
   }
}
close $fh
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
# Retrieve target names from top level makefile :
set fh [open R:/_build_proc/mak/makefile r]
while { [gets $fh line] >= 0 } {
   if { [regexp "^(\[0-9a-zA-Z_]+):" $line _ target] } {
      if { [lsearch -exact $::listOfExcludedTargets $target] == -1 } {
         lappend targets $target
      }
   }
}
close $fh
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
# Add additional targets (for example, parametric targets not extracted from makefile) :
foreach extraTarget $::listOfExtraTargets {
	if { [lsearch -exact $targets $extraTarget] == -1 } {
		lappend targets $extraTarget
	}
}
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
# Retrieve previous make x command :
set previousTarget [lindex $targets 0]
if { ![catch { set fh [open $::tempBatFile r] } errorMsg] } {
   for { set i 0 } { $i < 2 } { incr i } {
	   gets $fh line
	   if { [regexp "^@make --no-print-directory (\[^ ]*)" $line _ target] } {
		  set previousTarget $target
	   }
   }
   close $fh
}
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
# Build gui :
ttk::frame .left
ttk::frame .right
pack .left  -expand yes -fill both -side left
pack .right -expand yes -fill both -side left
set nbOfTargets 0
set isOdd [expr { [llength $targets] % 2 == 1 }]
foreach target $targets {
   if { (!$isOdd && $nbOfTargets < [llength $targets] / 2)       || \
      ($isOdd  && $nbOfTargets < ([llength $targets] / 2) + 1) } {
      set frame .left
   } else {
      set frame .right
   }
   incr nbOfTargets
   set inFrame($target) $frame
   ttk::button $frame.$target -text $target -width 45 -command [list go $target]
   pack $inFrame($target).$target -expand yes -fill x

   if { [info exists ::toolTips($target)] } {
      ::tooltip::tooltip $frame.$target $::toolTips($target)
	  lappend usedToolTips $target
   } else {
      ::tooltip::tooltip $frame.$target "N/A : Please add target description in file $toolTipsFile"
      $termColor putsColor "***WNG " WNG 1
	  puts " : In file '$toolTipsFile' -> Missing tooltip text for '$target' !"
   }
}

# Check if all tool tips texts have been used :
foreach toolTip [lsort -ascii [array names ::toolTips]] {
	if { [lsearch -exact $usedToolTips $toolTip] == -1 } {
	  $termColor putsColor "***WNG " WNG 1
	  puts ": In file '$toolTipsFile' -> Unused tooltip text for '$toolTip' !"
	}
}

if { $isOdd } {
   ttk::button .right.${target}_ -text "" -width 45 -state disabled
   pack        .right.${target}_ -expand yes -fill x
}

bind . <Prior>       goTop
bind . <Next>        goBottom
bind . <Key-Up>      goUp
bind . <Key-Down>	   goDown
bind . <Key-Left>	   goLeft
bind . <Key-Right>   goRight
bind . <Return>      go
bind . <Escape>      { exit 0 }
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
proc updateGui { increment { isincrement 1 } } {
   set label $::inFrame([lindex $::targets $::currentSelectedTarget]).[lindex $::targets $::currentSelectedTarget]
   $label configure -style TButton
   if { ![regexp ">(\[^<>]*)<" [$label cget -text] _ labelOnly] } {
      set labelOnly [$label cget -text]
   }
   $label configure -text $labelOnly
   if { $isincrement } {
      incr ::currentSelectedTarget $increment
   } else {
      set ::currentSelectedTarget $increment
   }
   set label $::inFrame([lindex $::targets $::currentSelectedTarget]).[lindex $::targets $::currentSelectedTarget]
   $label configure -style selected.TButton
   set ::animatedLabelState 0
}
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
proc goLeft {} {
   if { $::currentSelectedTarget >= ([llength $::targets] / 2 + ($::isOdd ? 1 : 0)) } {
      updateGui [expr { -[llength $::targets] / 2 }]
   }
}
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
proc goRight {} {
   if { $::currentSelectedTarget < ([llength $::targets] / 2) } {
      updateGui [expr { [llength $::targets] / 2 + ($::isOdd ? 1 : 0) }]
   }
}
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
proc goDown { { step 1 } } {
   if { $::currentSelectedTarget < ([llength $::targets] - 1) } {
      updateGui $step
   }
}
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
proc goUp {} {
   if { $::currentSelectedTarget > 0 } {
      updateGui -1
   }
}
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
proc goBottom {} {
   updateGui [expr {[llength $::targets] - 1}] 0
}
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
proc goTop {} {
   updateGui 0 0
}
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#https://wiki.tcl-lang.org/page/thread
proc go { { target {} } } {
   if { $target == {} } {
      set target [lindex $::targets $::currentSelectedTarget]
   }
   $::termColor putsColor "\[INF]" INF 1
   puts -nonewline " Selected target : "
   $::termColor putsColor $target TGT 1
   puts -nonewline " on "
   $::termColor putsColor [clock format [clock seconds] -format "%d %B %Y"] DATE 1
   puts -nonewline " @ "
   $::termColor putsColor [clock format [clock seconds] -format %H:%M:%S] DATE
   wm withdraw .

   set fh_out [open $::tempBatFile w]
   puts $fh_out "@make --no-print-directory $target "

   close $fh_out

   exit 0
}
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
proc focusOnWin { } {
   focus -force .
   after 200 focusOnWin
}
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
font create myFont -family Helvetica -size 9 -weight bold
ttk::style configure selected.TButton -foreground red -background white
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
set targetId 0
foreach target $targets {
   if { $target eq $previousTarget } {
      set ::currentSelectedTarget $targetId
      break
   }
   incr targetId
}
set defaultSelectedTarget [lindex $::targets $::currentSelectedTarget]
$inFrame($defaultSelectedTarget).$defaultSelectedTarget configure -style selected.TButton
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
   focusOnWin
   animateLabel
}
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
set fh_out [open $tempBatFile w]
puts $fh_out "@echo Aborted."
close $fh_out
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
set animatedLabelState 0
proc animateLabel { } {
   set defaultSelectedTarget [lindex $::targets $::currentSelectedTarget]
   switch -exact $::animatedLabelState {
      0 -
      1 -
      2 {
         $::inFrame($defaultSelectedTarget).$defaultSelectedTarget configure -text ">[$::inFrame($defaultSelectedTarget).$defaultSelectedTarget cget -text]<"
         incr ::animatedLabelState
      }
      3 -
      4 -
      5 {
         $::inFrame($defaultSelectedTarget).$defaultSelectedTarget configure -text "[string range [$::inFrame($defaultSelectedTarget).$defaultSelectedTarget cget -text] 1 end-1]"
         incr ::animatedLabelState
         if { $::animatedLabelState == 6 } {
            set ::animatedLabelState 0
         }
      }
   }
   after 80 animateLabel
}
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
proc findNext { char direction } {
   set returnValue 0
   if { $direction == 1 } {
      set indexSearch [expr { $::currentSelectedTarget + 1 }]
   } else {
      set indexSearch [expr { $::currentSelectedTarget - 1 }] ;# TOTO REBOUSTIFY
   }
   while { $indexSearch >= 0 && $indexSearch < [llength $::targets] } {
      if { $char eq [string index [lindex $::targets $indexSearch] 0] } {
         set returnValue [expr {$indexSearch - $::currentSelectedTarget }]
         break
      }
      incr indexSearch $direction
   }
   return $returnValue
}

foreach target $targets {
   set firstChar [string index $target 0]
   if { [info exists found1stLetters($firstChar)] } {
      incr found1stLetters($firstChar)
   } else {
      set found1stLetters($firstChar) 1
   }
}
foreach char [array names found1stLetters] {
   if { $found1stLetters($char) } {
      bind .  <$char>                  [list eval "goDown \[findNext $char   1]" ]
      bind .  <[string toupper $char]> [list eval "goDown \[findNext $char  -1]" ]
   }
}
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
