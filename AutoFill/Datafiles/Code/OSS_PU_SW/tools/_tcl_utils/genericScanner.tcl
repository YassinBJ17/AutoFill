#------------------------------------------------------------------------------
# ::GenericScanner
#------------------------------------------------------------------------------

namespace eval ::GenericScanner {

   set dirStructPrefix 	"  "

   set ignoredDirs			{}
   set prefixOrSuffix		"prefix"
   set fileTypes			{}
   set preProc				""
   set preProcParams		{}
   set postProc			""
   set postProcParams		{}
   set actionProc			""
   set actionProcParams	{}
   set duplicateFileType   0

   #------------------------------------------------------------------------------

   proc nextChar { currentChar } {
      if { $currentChar == "/" } {
         return -
      } elseif { $currentChar == "-" } {
         return \\
         } elseif { $currentChar == "\\" } {
            return |
      } else {
         return /
      }
   }

   #------------------------------------------------------------------------------

   proc performActionInCurrentDir { { enableStdOut 1 } } {

      # 1-) Call pre-proc :
      if { $::GenericScanner::preProc != "" } {
         eval "$::GenericScanner::preProc $::GenericScanner::preProcParams"
      }

      # 2-) Perform action on each file :
      if { [llength $::GenericScanner::fileTypes] > 0 } {

         if { [catch { set relevantFiles [glob -types {f} -nocomplain {*}$::GenericScanner::fileTypes] } errorMsg] } {
            ::Logger::addLog ERR_LOG "*** $errorMsg *** [pwd] *** $::GenericScanner::fileTypes"
            set relevantFiles {}
            exit 1
         } else {
            # Check if there are multiple files returned by glob :
            if { $::GenericScanner::duplicateFileType } {
               set relevantFiles_final {}
               foreach fileFound $relevantFiles {
                  if { [lsearch -exact $relevantFiles_final $fileFound] == -1 } {
                     lappend relevantFiles_final $fileFound
                  }
               }
               set relevantFiles $relevantFiles_final
            }
         }
         set nbOfRelevantFiles [llength $relevantFiles]
         set nbOfProcessedFiles 0

         if { $nbOfRelevantFiles > 0 } {
            if { $enableStdOut } { puts -nonewline "\[-]" }
            set previouslyDisplayedSentence "\[-]"
            set currentDisplayedChar -
            foreach { relevantFile } $relevantFiles {

               # 1-) Gizmo update :
               set currentDisplayedChar [nextChar $currentDisplayedChar]
               if { $enableStdOut } {
                  puts -nonewline [string repeat "\b" [string length $previouslyDisplayedSentence]]
                  puts -nonewline [string repeat " "  [string length $previouslyDisplayedSentence]]
                  puts -nonewline [string repeat "\b" [string length $previouslyDisplayedSentence]]
               }
               set previouslyDisplayedSentence "\[$currentDisplayedChar] ($nbOfProcessedFiles/$nbOfRelevantFiles) $relevantFile"
               if { $enableStdOut } {
                  puts -nonewline "$previouslyDisplayedSentence"
                  flush stdout
               }

               # 2-) Do what you have to do :
               if { $::GenericScanner::actionProc != "" } {
                  eval "$::GenericScanner::actionProc {$relevantFile} $::GenericScanner::actionProcParams"
               }
               # 3-) For smooth scrolling :
               #after 1

               incr nbOfProcessedFiles
            }
            if { $enableStdOut } {
               puts -nonewline [string repeat "\b" [string length $previouslyDisplayedSentence]]
               puts -nonewline [string repeat " "  [string length $previouslyDisplayedSentence]]
               puts -nonewline [string repeat "\b" [string length $previouslyDisplayedSentence]]
            }
         }
      }

      # 3-) Eval post proc :
      if { $::GenericScanner::postProc != "" } {
         eval "$::GenericScanner::postProc $::GenericScanner::postProcParams"
      }
   }

   #------------------------------------------------------------------------------

   proc enterAndPerformActionInDirAndSubDirs { pathToPerformActionIn isItTheFinalDir enableStdOut enterConditionFunc params } {

      # 1-) Update prefix : remove last char and add a directory level :

      set ::GenericScanner::dirStructPrefix "[string range $::GenericScanner::dirStructPrefix 0 [expr [string length $::GenericScanner::dirStructPrefix] - 2]] |-"

      # 2-) Backup current dir and enter directory to perform action in :

      set currentPath [pwd]
      if { [catch {
         cd $pathToPerformActionIn
      } errorMsg] } {
         ::Logger::addLog ERR_LOG "Unable to access [file nativename [file join [pwd] $pathToPerformActionIn]] !"
         ::Logger::addLog ERR_LOG "*** $errorMsg"
         exit 1
         return
      }

      # 3-) Perform action in current directory if depth-first prefix search ::
      if { $enableStdOut } { puts -nonewline "$::GenericScanner::dirStructPrefix$pathToPerformActionIn " }
      if { $::GenericScanner::prefixOrSuffix == "prefix" } {
         performActionInCurrentDir $enableStdOut
      }
      if { $enableStdOut } { puts "" }

      # 4-) If current dir is the final dir of the list, then update prefix :

      if { $isItTheFinalDir == true} {
         set ::GenericScanner::dirStructPrefix "[string range $::GenericScanner::dirStructPrefix 0 [expr [string length $::GenericScanner::dirStructPrefix] - 3]]  "
      }

      # 5-) Enter and perform action in all subdirectories in current dir :

      if { [catch { set listOfDirectoriesToPerformActionIn [glob -nocomplain */] } errorMsg ] } {
         set listOfDirectoriesToPerformActionIn {}
      }

      if { [llength $listOfDirectoriesToPerformActionIn] != 0 } {
         foreach { directoryToPerformActionIn } $listOfDirectoriesToPerformActionIn {

            # Check if this is the last subdir of the list :
            if { [lindex $listOfDirectoriesToPerformActionIn [expr [llength $listOfDirectoriesToPerformActionIn] - 1]] == $directoryToPerformActionIn } {
               set isItTheLastDir true
            } else {
               set isItTheLastDir false
            }

            # Enter the subdir :
            if { ([lsearch -exact $::GenericScanner::ignoredDirs [file tail $directoryToPerformActionIn]] != -1) ||
               (($enterConditionFunc ne "") && ![$enterConditionFunc $params [pwd] $directoryToPerformActionIn]) } {
               #puts "$directoryToPerformActionIn *** Ignored ***"
            } else {
               enterAndPerformActionInDirAndSubDirs $directoryToPerformActionIn $isItTheLastDir $enableStdOut $enterConditionFunc $params
            }
         }
      }

      # 5.1-) Depth-first suffix search :

      if { $::GenericScanner::prefixOrSuffix == "suffix" } {
         performActionInCurrentDir
      }

      # 6-) Get back to initial dir :

      cd $currentPath

      # 7-) Update prefix :

      set ::GenericScanner::dirStructPrefix [string range $::GenericScanner::dirStructPrefix 0 [expr [string length $::GenericScanner::dirStructPrefix] - 3]]
   }

   #------------------------------------------------------------------------------

   proc recursivelyPerformActionIn { initialPath ignoredDirs prefixOrSuffix fileTypes preProc preProcParams postProc postProcParams actionProc actionProcParams enableStdOut enterConditionFunc params  } {

      # If file type list contains identical items from a case-independent point of view, then raise a flag to filter out
      # duplicate files (glob *.tcl *.TCL will yield duplicates under win only (probably)!) :
      foreach type $fileTypes {
         lappend fileTypesLowerCase [string tolower $type]
      }
      set foundFileTypes {}
      foreach type $fileTypesLowerCase {
         if { [lsearch -exact $foundFileTypes $type] != -1 } {
            puts "Duplicate file type found : $type"
            set ::GenericScanner::duplicateFileType 1
            break
         } else {
            lappend foundFileTypes $type
         }
      }

      if { [file isdirectory $initialPath] != 1 } {
         $termColor putsColor "  ***ERR" ERROR 1
         puts " : Cannot access $initialPath, aborted."
         return error
      }

      if { [lsearch $ignoredDirs [file tail $initialPath]] != -1 } {
         $termColor putsColor "  ***ERR" ERROR 1
         puts " : Dir ignored, aborted."
         return error
      }

      set ::GenericScanner::ignoredDirs		$ignoredDirs
      set ::GenericScanner::prefixOrSuffix	$prefixOrSuffix
      set ::GenericScanner::fileTypes			$fileTypes
      set ::GenericScanner::preProc			$preProc
      set ::GenericScanner::preProcParams		$preProcParams
      set ::GenericScanner::postProc			$postProc
      set ::GenericScanner::postProcParams	$postProcParams
      set ::GenericScanner::actionProc		$actionProc
      set ::GenericScanner::actionProcParams	$actionProcParams

      # 1) Store execution path to restore it after multiple dir changes :
      set currentPath [pwd]

      # 2) Enter initial path :
      if { [catch {
         cd $initialPath
      } errorMsg] } {
         $termColor putsColor "  ***ERR" ERROR 1
         puts " : Unable to access $initialPath !"
         puts "          --> Error message is : $errorMsg"
         exit 1
         return error
      }


      # 3) First call to recursive proc :
      enterAndPerformActionInDirAndSubDirs "./" true $enableStdOut $enterConditionFunc $params

      # 4) Restore initial path :
      cd $currentPath

      return ok
   }
}

#------------------------------------------------------------------------------
