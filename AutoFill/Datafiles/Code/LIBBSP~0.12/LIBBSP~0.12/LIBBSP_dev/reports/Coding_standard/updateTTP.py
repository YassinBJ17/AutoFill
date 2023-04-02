
import glob
import re

pathSrc = 'Coding_standard.ttp'
pathDst = 'Coding_standard_updated.ttp'
pathCodeSrcRel = "..\\..\\*\\*.c"

f_srcTTP = open(pathSrc, 'r')
f_dstTTP = open(pathDst, 'w')
listOfFileToAdd = glob.glob( pathCodeSrcRel )

flagFound = False
keyword = "file_ref ::= {"
line = "Run"
idToIncr = 0

while line != "" :
    line = f_srcTTP.readline()
    # print(line)
    f_dstTTP.write( line )

    if flagFound == True :
        idToIncr = re.findall(r'\d+', line)
        # print( idToIncr )
        break
    
    if keyword in line :
        flagFound = True
        # print("Found !!!")

    if line == "" :
        # print("End of file.")
        break


if flagFound == True :
    maxIncr = len(listOfFileToAdd)
    id = int(idToIncr[0]) +1 # Pour la liste des fichiers dans le WS

    for fileToAdd in listOfFileToAdd :
        newLine = "{\"" + str(id) + "\", \"15\", \"" +  fileToAdd.replace("\\", "\\\\") + "\"}"
        if maxIncr > 1:
            newLine = newLine + ","
        newLine = newLine + "\n"

        f_dstTTP.write( newLine )
        maxIncr = maxIncr-1
        id = id + 1

    f_dstTTP.write( "}\n" )
    f_dstTTP.write( "END\n" )
    
    