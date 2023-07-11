package COMMUN;

import javax.swing.*;
import java.io.File;
import java.util.ArrayList;
import static SUTC.file.SutcCreationProccess.Excel_Final;
import static COMMUN.GraphicUserInterfaces.Waiting_interface;
import static COMMUN.LoggerInitialize.*;
import static COMMUN.UsernameExtract.Username_filling;

public class BrowsingInputFolder {

public static String SDDDfileName;

public static void Processing(String directory){

    String path;
    ArrayList<String> cause ;
    ArrayList<String> effect;
    
    File folder = new File(directory);
    File[] listOfFiles = folder.listFiles();

    assert listOfFiles != null;
    log4Info("Process started");
    for (File listOfFile : listOfFiles) {
       // try {
            if (listOfFile.isFile()) {
                if ((listOfFile.getName().contains(".docm")||(listOfFile.getName().contains(".docx"))) && (!listOfFile.getName().contains("~"))) {


                    cause= new ArrayList<>(); // initialize cause table
                    effect= new ArrayList<>(); // initialize effect table
                    SDDDfileName =listOfFile.getName();
                    log4Info(SDDDfileName);
                    path =directory+ SDDDfileName;
                    Excel_Final(path, Username_filling(), cause, effect); //filling SUTC
                    log4Info("SUTC Creation success");
                }
            }
        }

    }
}
