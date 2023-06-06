package COMMUN;

import javax.swing.*;
import java.io.File;
import java.util.ArrayList;
import static SUTC.file.Services.ExcelFinal.Excel_Final;
import static COMMUN.GraphicUserInterfaces.Error_interface;
import static COMMUN.GraphicUserInterfaces.Waiting_interface;
import static COMMUN.LoggerInit.logger4j;
import static COMMUN.UsernameExtract.Username_filling;

public class BrowsingInputFolder {

public static String fileName;

public static void Processing(String directory){

    String path;
    ArrayList<String> cause ;
    ArrayList<String> effect;
    
    File folder = new File(directory);
    File[] listOfFiles = folder.listFiles();

    assert listOfFiles != null;
    logger4j.info("Process started");
    for (File listOfFile : listOfFiles) {
        try {
            if (listOfFile.isFile()) {
                if ((listOfFile.getName().contains(".docm")||(listOfFile.getName().contains(".docx"))) && (!listOfFile.getName().contains("~"))) {

                    JDialog dialog = Waiting_interface();
                    cause= new ArrayList<>(); // initialize cause table
                    effect= new ArrayList<>(); // initialize effect table
                    fileName=listOfFile.getName();
                    logger4j.info(fileName);
                    path =directory+ fileName;
                    Excel_Final(path, Username_filling(), cause, effect,dialog); //filling SUTC
                    logger4j.info("SUTC Creation success");
                }
            }
        }
        catch (Exception e){
            logger4j.error(e);
            Error_interface(String.valueOf(e));
        }
    }
}
}