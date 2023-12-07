package file.commun;

import java.io.File;
import static file.sutc.SutcCreationProcess.excelFinalManipulation;
import static file.commun.LoggerInitialize.*;

public class BrowsingInputFolder {

public static String designFileName;

public static void processing(String directory){

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
                    log4Info(designFileName);
                    path =directory+ designFileName;
                    excelFinalManipulation(path); //filling SUTC

                }
            }
        }

    }
}
