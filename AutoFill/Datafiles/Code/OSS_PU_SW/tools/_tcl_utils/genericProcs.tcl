namespace eval ::GenericProcs {

	set geoRegExp "(\[0-9]+)\[x](\[0-9]+)\[+-]+(\[0-9]+)\[+-]+(\[0-9]+)"

#--------------------------------------------------------------------------------------------------	
	
	proc getAttributeValueFromName { attlist key } {
		array set myVals $attlist
		if { ![info exists myVals($key)] } {
			::Logger::addLog ERR_LOG "Cannot find '$key' in the following list '$attlist'"
			error "\[getAttributeValueFromName] Cannot find '$key' in the following list '$attlist'"
		} else {
			return $myVals($key)
		}
	}
	
#--------------------------------------------------------------------------------------------------

	proc myConvertFromBadEncoding { data } {

		set ret [string map $::GenericProcs::badEncodingsDataPairs $data]
		set strLen [string length $ret]
		set lineNb 0
		for {set i 0 } { $i < $strLen } { incr i } {
			if { [scan [string index $ret $i] %c] > 127 } {
			
				set startOfFaultyLine  0
				for { set j $i } { $j >=0 } { incr j -1 } {
					if { [string index $ret $j] eq "\n" } {
						set startOfFaultyLine $j
						break
					}
				}
				set stopOfFaultyLine  0
				for { set j $i } { $j < $strLen } { incr j } {
					if { [string index $ret $j] eq "\n" } {
						set stopOfFaultyLine $j
						break
					}
				}
				::Logger::addLog ERR_LOG "Illegal non lower-ascii char in : $i / [string index $ret $i] / [scan [string index $ret $i]  %c] / $ret"
				::Logger::addLog ERR_LOG " --> '[string range $ret $startOfFaultyLine $stopOfFaultyLine]'"
				error "Illegal non lower-ascii char ! See log."
exit 1
			} 
			if { [string index $ret $i] eq "\n" } {
				incr lineNb
			}
		}
		return $ret 
	}	
					
#--------------------------------------------------------------------------------------------------

	proc getGeometryFor { window } {
		regexp $::GenericProcs::geoRegExp [wm geometry $window] junk width height x y
		if { [GenericProcs::getCurrentOS] eq "win32" } {
			if { [wm state $window] eq "zoomed" } {
				set x 0
				set y 0
			}
		}
		return [list $width $height $x $y]
	}

#--------------------------------------------------------------------------------------------------

	proc padStrUntilAndWith { str length { padChar " "} { justif left } } {
		set newStr $str
		if { [string length $str] < $length } {
			if { $justif eq "left" } {
				append newStr [string repeat $padChar [expr { $length - [string length $str]}]]
			} elseif { $justif eq "right" } {
				set newStr [string repeat $padChar [expr { $length - [string length $str]}]]$newStr
			} elseif { $justif eq "center" } {
				set nbOfChars [expr { ($length - [string length $str]) / 2}]
				set newStr [string repeat $padChar $nbOfChars]$newStr[string repeat $padChar $nbOfChars]
				append newStr [string repeat $padChar [expr {$length - [string length $newStr]}]]
			}
		}
		return $newStr
	}

#--------------------------------------------------------------------------------------------------

	proc getCurrentOS { } {

		if { $::tcl_platform(platform) eq "unix" } {
			# Linux or MacOS :
			#Logger::addLog INF_LOG "Unix-type operating system detected (" nonewline
			if { ($::tcl_platform(os) eq "Darwin") || ($::tcl_platform(os) eq "MacOS") } {
				#Logger::addLog APP_LOG "Mac)"
				set OS "mac"
			} else {
				#Logger::addLog APP_LOG "Linux)"
				set OS "linux"
			}

		} elseif { $::tcl_platform(platform) eq "windows" } {
			# Win32 system :
			#Logger::addLog INF_LOG "Windows family operating system detected."
			#set env(Path) [file join D:/ Progs  Cygwin bin]
			set OS "win32"
		} else {
			Logger::addLog ERR_LOG "Unknown operating system detected."
			exit 1
			set OS "unknown"
		}

		return $OS
	}

#--------------------------------------------------------------------------------------------------

	proc convertSecondsIntoHoursMinsSec { durationInS } {
		set hours   [expr $durationInS / 3600]

		set minutes [expr ($durationInS - ($hours * 3600)) / 60 ]

		set seconds [expr $durationInS - ($hours * 3600) - ($minutes * 60) ]
		return "$hours h $minutes m $seconds s"
	}

#--------------------------------------------------------------------------------------------------

	proc getPreExistingDir { initialDir } {
		set filePathToLook $initialDir
		if { ![file isdirectory $filePathToLook] } {
			set filePathToLook [file dirname $filePathToLook]
			if { ![file isdirectory $filePathToLook] } {
				set filePathToLook "."
			}
		}
		Logger::addLog INF_LOG "Returned : $filePathToLook"
		return $filePathToLook
	}

#--------------------------------------------------------------------------------------------------

	proc myFileChooser { parentWindow operation { initialDir "." } { types " \{ \"Text files\"  \{ .txt \}  \} \{ \"All files\"  \*  \}  " } { multiple 0 } { initialFile "" } } {
		set initialDir [::GenericProcs::getPreExistingDir $initialDir]

		if { $operation eq "open" } {
			set file [tk_getOpenFile -initialdir $initialDir -filetypes $types -parent $parentWindow  -multiple $multiple   ]
		} else {
			set file [tk_getSaveFile -initialdir $initialDir -filetypes $types -parent $parentWindow -initialfile $initialFile ]
		}
		return $file
	}

#--------------------------------------------------------------------------------------------------

	proc myDirChooser { parent initialDir title } {
		set initialDir [::GenericProcs::getPreExistingDir $initialDir]

		return [tk_chooseDirectory -parent $parent -initialdir $initialDir -title $title]
	}

#--------------------------------------------------------------------------------------------------

	proc myExitProc { { noNewLine "" } } {
		if { $noNewLine ne "" } {
			Logger::addLog APP_LOG ""
		}
		Logger::addLog INF_LOG "Destroying window..." noNewLine
		global widget
		destroy .
		Logger::disableLogWindow ; #To avoid callback being stopped upon error (log window has been destroyed) !
		Logger::addLog APP_LOG "\[OK\]"
		Logger::addLog INF_LOG "Bye."
	}

#--------------------------------------------------------------------------------------------------

	proc geometrizeDialogInCenterOf { mainTopLevelWindow dialogWindow } {
		Logger::addLog INF_LOG "$mainTopLevelWindow $dialogWindow"
		if { $mainTopLevelWindow eq "versusScreen" } {
			set mainWindowWidth  [winfo screenwidth .]
			set mainWindowHeight [winfo screenheight .]
			set mainWindowPosX   0
			set mainWindowPosY   0
		} else {
			# Get main window size & position :
# 			set mainWindowWidth  [winfo width  $mainTopLevelWindow]
# 			set mainWindowHeight [winfo height $mainTopLevelWindow]
# 			set mainWindowPosX   [winfo x      $mainTopLevelWindow]
# 			set mainWindowPosY   [winfo y      $mainTopLevelWindow]
			lassign [::GenericProcs::getGeometryFor $mainTopLevelWindow] mainWindowWidth mainWindowHeight mainWindowPosX mainWindowPosY
		}
		# Elaborate dialog size and position to have it centered on the main window :
		set dialogPosX [expr $mainWindowPosX + ($mainWindowWidth  / 2) - ([winfo reqwidth  $dialogWindow] / 2)]
		set dialogPosY [expr $mainWindowPosY + ($mainWindowHeight / 2) - ([winfo reqheight $dialogWindow] / 2)]
		wm geometry $dialogWindow +$dialogPosX+$dialogPosY
	}

#--------------------------------------------------------------------------------------------------

	proc tryToFindDirectory { initialDir defaultDir } {
		Logger::addLog INF_LOG "Try to find dir for '$initialDir'"
		if { [file isdirectory $initialDir] } {
			Logger::addLog INF_LOG "Dir for '$initialDir' found : $initialDir"
			return $initialDir
		} else {
			set dirName [file dirname $initialDir]
			if { [file isdirectory $dirName] } {
				Logger::addLog INF_LOG "Dir for '$initialDir' found : $dirName"
				return $dirName
			} else {
				Logger::addLog INF_LOG "Dir for '$initialDir' not found : $defaultDir selected"
				return $defaultDir
			}
		}
	}

#--------------------------------------------------------------------------------------------------

	proc loadCustomLib { libName { logOn 1 } } {
		if { $logOn } {
			puts -nonewline "Loading $libName[info sharedlibextension]..."
			flush stdout
		}
		set ::logOn $logOn
		set ::libName $libName
		uplevel 2 {
			if { [catch { load  "$libName[info sharedlibextension]" } errorMsg ] } {
				puts "\nCould not load library $libName[info sharedlibextension] ($errorMsg)!"
				puts "\nAborted."
				exit 1
			} else {
				if { $logOn } {
					puts "Done."
				}
			}
		}
		unset ::logOn
		unset ::libName
	}

#--------------------------------------------------------------------------------------------------

	proc readConfigFile { fileName listOfKeys varName } {
		if { [file exist $fileName ] } {
			if { [catch { set fileHandler [open $fileName { RDONLY } ] } errorMsg ] } {
				Logger::addLog ERR_LOG $errorMsg
			} else {
				Logger::addLog INF_LOG "ConfigFile : '$fileName' opened."

				#array set keyValuePairs $listOfKeyValues
				#set listOfKeys [array names keyValuePairs]

				# 0) Clear any existing var :
				array unset $varName
				
				# 1) Build the switch command :
				set keyValuesCmdsInstruction {}
				foreach myKey $listOfKeys {
					lappend keyValuesCmdsInstruction $myKey  " set newValue \[gets \$fileHandler]  ; \
					                                           set ${varName}($myKey) \$newValue ; \
					                                           Logger::addLog INF_LOG \"ConfigFile : \[set ${varName}($myKey)\] -> $myKey\" "
				}
				lappend keyValuesCmdsInstruction default "Logger::addLog ERR_LOG \"Config file holds an unknow parameter : \$line !\""

				# 2) Parse the file :
				if { [llength $keyValuesCmdsInstruction] } {
					while { [gets $fileHandler line] >= 0 } {
						set line [string trim $line]
						if { ([string length $line] > 0) && ([string index $line 0] ne "#") } {
							switch -exact $line $keyValuesCmdsInstruction
							#Logger::addLog INF_LOG "Read line: '$line'"
						}
					}
				}
				close $fileHandler
			}
		} else {
			Logger::addLog INF_LOG "No config file '$fileName' found."
		}
	}

#--------------------------------------------------------------------------------------------------

	proc writeConfigFile { fileName listOfKeyValues } {

		if { [file exist $fileName ] } {
			file delete -force $fileName
		}
		if { [catch { set fileHandler [open $fileName w ] } errorMsg ] } {
			Logger::addLog ERR_LOG $errorMsg
		} else {
			Logger::addLog INF_LOG "ConfigFile : '$fileName' opened."
			puts $fileHandler "# WARNING : If you edit this file manually, you can only change parameter values !\n"

			array set keyValuePairs $listOfKeyValues
			set listOfKeys [lsort -ascii -increasing [array names keyValuePairs]]

			foreach myKey $listOfKeys {
				Logger::addLog INF_LOG "ConfigFile : $keyValuePairs($myKey) <- $myKey"
				puts $fileHandler $myKey
				puts $fileHandler $keyValuePairs($myKey)\n
			}
			close $fileHandler
			Logger::addLog INF_LOG "ConfigFile : '$fileName' closed."
		}
	}

#--------------------------------------------------------------------------------------------------

	proc splitString { str strToFind } {            ; #TODO : Thomas - there's a [textutil::splitx] in tcllib that does what you're after
		set result {}
		set findIndex [string first $strToFind $str]
		if { $str eq "" } {
			set result ""
		} elseif { $findIndex == -1 } {
			set result [list $str]
		} else {
			while { $findIndex != -1 } {
				if { $findIndex == 0 } {
					lappend result {}
				} else {
					lappend result [string range $str 0 [expr { $findIndex -1 } ]]
				}
				if { ($findIndex + [string length $strToFind]) >= [string length $str] } {
					set str ""
				} else {
					set str [string range $str [expr { $findIndex + [string length $strToFind] } ] end]
				}
				set findIndex [string first $strToFind $str]
			}
			lappend result $str
		}
		return $result
	}
	if { 0 } {
		proc testSplit { testId strA strAx strB strBx } {
			puts -nonewline "    -> $testId : "
			set a [splitString $strA $strAx]
			set b [split $strB $strBx]
			if { $a == $b } {
				puts OK
			} else {
				puts "*** ERROR *** '$a' vs '$b'"
			}
		}
		testSplit 1 "" ok "" o
		testSplit 2 ok ok o o
		testSplit 3 okok ok oo o
		testSplit 4 aokok ok aoo o
		testSplit 5 aokbok ok aobo o
		testSplit 6 aokb ok aob o
		testSplit 7 aokbokc ok aoboc o
		testSplit 8 aaa ok aaa o
	}

#--------------------------------------------------------------------------------------------------

	proc emulateButton1PressFor { widget } {
		after idle [list event generate $widget <ButtonPress-1>   -x [expr { [winfo x $widget] + 5 }] -y [expr { [winfo y $widget] + 5 }]]
		after idle [list event generate $widget <ButtonRelease-1> -x [expr { [winfo x $widget] + 5 }] -y [expr { [winfo y $widget] + 5 }]]
		Logger::addLog INF_LOG "Emulated B1 for $widget"
	}

#--------------------------------------------------------------------------------------------------

	proc getVersionFromCHANGES_file { CHANGES_file } {
		if { [catch { set fileHandler [open $CHANGES_file r ] } errorMsg ] } {
			puts $errorMsg
			exit 2
		}
		set versionID ""
		while { [gets $fileHandler line] >= 0 } {
			set line [string trim $line]
			if { [regexp "^v(\[0-9]+).(\[0-9]+).(\[0-9]+)\$" $line trash n1 n2 n3] } {
				set versionID "v$n1.$n2.$n3"
				break
			}
		}
		close $fileHandler
		if { "" eq $versionID } {
			puts "Cannot find version from '$CHANGES_file' !"
			exit 1
		} else {
			return $versionID 
		}
	}

#--------------------------------------------------------------------------------------------------

	proc getCrc32 { fileName } {  ; # TODO ; test md5
		set fd [open $fileName]
		chan configure $fd -encoding binary -translation binary
		set data [read $fd]
		set crc32 [zlib crc32 $data]
		close $fd
		return $crc32
	}

#--------------------------------------------------------------------------------------------------

	proc checkPackageDependencies { listOfPackages } {
		foreach package $listOfPackages {
			if { ![namespace exists $package] } {
				::Logger::addLog ERR_LOG "Now, ::auto_path is '$::auto_path'"
				::Logger::addLog ERR_LOG "Package '$package' is required. Aborted."
				exit 1
			}
		}
	}

#--------------------------------------------------------------------------------------------------

	proc toXML { string } {
		# From : http://www.w3schools.com/xmL/xml_syntax.asp
		set XML_MAP {
			< &lt;
			> &gt;
			& &amp;
			\" &quot;
			' &apos;
			\n \\n
		}
		return [string map $XML_MAP $string]
	}

#--------------------------------------------------------------------------------------------------

	proc fromXML { string } {
		# From : http://www.w3schools.com/xmL/xml_syntax.asp
		set XML_MAP {
			&lt; <
			&gt; >
			&amp; &
			&quot; \"
			&apos; '
			\\n \n
		}
		return [string map $XML_MAP $string]
	}

#--------------------------------------------------------------------------------------------------

	proc fromHTML { string } {
		set HTML_MAP {
			&#64; @
		}
		return [string map $HTML_MAP $string]
	}
	
#--------------------------------------------------------------------------------------------------

	proc defProc { namespace procName } {
		eval "namespace eval $namespace { \
		proc $procName { args } {\
			return \[${namespace}::_$procName {*}\$args\]\
		}\
		}\
		"
	}

#--------------------------------------------------------------------------------------------------	
	
	proc defVar { namespace varName initialValue } {
		eval "\
			namespace eval $namespace { \n\
				set _$varName \"$initialValue\" \n\
				\n\
				proc get_$varName { } {\n\
					return \$${namespace}::_$varName\n\
				\n\
				}\n\
				proc set_$varName { newValue } {\n\
					set ${namespace}::_$varName \$newValue\n\
				}\n\
				proc getVar_$varName { } {\n\
					return ${namespace}::_$varName\n\
				\n\
				}\n\
			}\n\
			"	
	}
	
#--------------------------------------------------------------------------------------------------

	proc checkDirExistenceAndCreateIfRequired { dir } {
		if { ![file isdirectory $dir] } {
			::Logger::addLog INF_LOG "Creating $dir directory..." nonewline
			if { [catch {file mkdir $dir} errorMsg] } {
				::Logger::addLog ERR_LOG "Could not create '$dir' ($errorMsg) ! Aborted."
				exit 1
			} 
			::Logger::addLog APP_LOG "Done."
		} else {
			::Logger::addLog INF_LOG "Directory '$dir' found."
		}
	}

#--------------------------------------------------------------------------------------------------

	proc getWindowsTaskPIDs { taskName } {
		set tasks [split [exec tasklist /FO csv ] \n]
		set runningTaskPIDs {}
		foreach task [lrange $tasks 2 end] {   ; # The 2 1st lines are irrelevant
			lassign [split $task ","] task taskPID
			set task [string range $task 1 end-1]
			if { $task eq $taskName } {
				lappend runningTaskPIDs [string range $taskPID 1 end-1]
			}
		}
		return $runningTaskPIDs 
	}

#--------------------------------------------------------------------------------------------------

	proc compareVersions { versionA versionB } {
		set isANewerThanB 0
		lassign [split [string range $versionA 1 end] .] Ax Ay Az
		lassign [split [string range $versionB 1 end] .] Bx By Bz
		
		foreach x {Ax Ay Az Bx By Bz} {
				if { ![string is integer [set $x]] } {
					error "\[compareVersions] Version '[set $x]' is nowhere near an integer !"
				}
		}

		if { $Ax > $Bx } {
			set isANewerThanB 1
		} elseif { $Ax < $Bx } {
			set isANewerThanB -1
		} else {
			if { $Ay > $By } {
				set isANewerThanB 1
			} elseif { $Ay < $By } {
				set isANewerThanB -1
			} else {
				if { $Az > $Bz } {
					set isANewerThanB 1
				} elseif { $Az < $Bz } {
					set isANewerThanB -1
				} else {
					set isANewerThanB 0
				}
			}
		}
	}

#--------------------------------------------------------------------------------------------------

	proc checkDirExistenceAndCreateDirIfRequired { dir {toplev ""} } {  
		if { [file isdirectory $dir] } {
			::Logger::addLog INF_LOG "No need to create dir '$dir'"
			return 0
		} 
		if { [file exists $dir] } {
			set errorStr "Unable to create dir '$dir', a file already exists with this name !"
			::Logger::addLog ERR_LOG $errorStr
			if { $toplev ne "" } {
				tk_messageBox -parent $toplev -icon error -type ok -title "File system error" -message $errorStr
			}
			return 1
		} 
		if { [catch { file mkdir $dir } errorMsg] } {
			set errorStr "Could not create directory '$dir', error message was :\n\n  $errorMsg"
			::Logger::addLog ERR_LOG $errorStr
			if { $toplev ne "" } {
				tk_messageBox -parent $toplev -icon error -type ok -title "File system error" -message $errorStr
			}
			return 1
		} else {
			::Logger::addLog INF_LOG "Created dir '$dir'"
			return 0
		}
	}

#--------------------------------------------------------------------------------------------------	


	# Init bad encodings path :

	set pathToBadEncodings [file normalize [file dirname [info script]]]/common
	
	# Init encodings :
	
	set ::GenericProcs::badEncodingsDataPairs {}
	set fileToLoad [file join $pathToBadEncodings badEncodingsDataPairs.txt]
	if { [catch {
			set badEncodingsDataFileHandler [open $fileToLoad r]
		} errorMsg] } {
		puts stderr "*** ERROR : Could not open '[file nativename $fileToLoad]' ! Please fix."
		puts stderr "*** ERROR : Error message was :"
		foreach line [split $errorMsg \n] {
			puts stderr "*** ERROR :    -> $line"
		} 
		exit 1
	} else {
		while { [gets $badEncodingsDataFileHandler line] >= 0 } {
			set line [string trim $line]
			lassign $line k v
			if { [string index $line 0] ne "#" } {
				lappend ::GenericProcs::badEncodingsDataPairs $k
				lappend ::GenericProcs::badEncodingsDataPairs $v
			}
		}
		close $badEncodingsDataFileHandler
		foreach item [list [format %c 160] _ [format %c 194] \" [format %c 195] ? [format %c 168] ? [format %c 169] ?] {
			lappend ::GenericProcs::badEncodingsDataPairs $item
		}	
	}

#--------------------------------------------------------------------------------------------------		
	
	proc killAllMsWindowsProcesses { processName toplevel { canConfirm 0 } } {

		set tasks [split [exec tasklist /FO csv ] \n]
		set runningTaskNames {}
		foreach task [lrange $tasks 2 end] {   ; # The 2 1st lines are irrelevant
			lassign [split $task ","] task
			set task [string range $task 1 end-1]
			lappend runningTaskNames $task
		}	
		set nbOfInstances [llength [lsearch -all -exact $runningTaskNames $processName]]
		::Logger::addLog INF_LOG "Number of detected running $processName instances : $nbOfInstances"	
		
		if { $nbOfInstances > 0 } {
			if { !$canConfirm } {
				::Logger::addLog INF_LOG "Killing all $processName instances !"
				if { [catch { exec "TASKKILL" "/F" "/IM" $processName }  errorMsg] } {
					#puts "1=[exec [list TASKLIST /FI \"IMAGENAME eq $processName\"]]"
					#puts 2=[exec tasklist /FI \"IMAGENAME eq $processName\"]
					#puts [exec tasklist /FI \"IMAGENAME eq WINWORD.EXE\"]
					::Logger::addLog WNG_LOG "TASKKILL failed with msg : $errorMsg"
				}
			} else {
					if { "yes" eq [tk_messageBox -parent $toplevel -type yesno -icon question -title "$processName is already running" -message "Number of running $processName instances : $nbOfInstances \nKill all of them ?"] } {
						::Logger::addLog INF_LOG "Killing all $processName instances !"
						catch { exec "TASKKILL" "/F" "/IM" $processName }
					} else {
						::Logger::addLog INF_LOG "Ok. Aborted."
					}
			}
		}
	}		
	
} ;

###################################################################################################


