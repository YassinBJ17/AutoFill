package Commun;

import java.io.File;
import static SUTC.file.SutcCreationProcess.excelFinalManipulation;
import static Commun.LoggerInitialize.*;
import static Commun.UsernameExtract.Username_filling;

public class BrowsingInputFolder {

public static String designFileName;

public static void Processing(String directory){

    String path;

    
    File folder = new File(directory);
    File[] listOfFiles = folder.listFiles();

    assert listOfFiles != null;
    log4Info("Process started");
    for (File listOfFile : listOfFiles) {
       // try {
            if (listOfFile.isFile()) {
                if ((listOfFile.getName().contains(".docm")||(listOfFile.getName().contains(".docx"))) && (!listOfFile.getName().contains("~"))) {


                    designFileName =listOfFile.getName();
                    path =directory+ designFileName;
                    excelFinalManipulation(path, Username_filling()); //filling SUTC

                }
            }
        }

    }
}
