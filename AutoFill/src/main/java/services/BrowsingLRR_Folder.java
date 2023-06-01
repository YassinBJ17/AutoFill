package services;

import docx.file.ExtractText;

import javax.swing.*;
import java.io.File;
import java.util.ArrayList;

import static excel.file.Services.ExcelFinal.Excel_Final;
import static services.GUInterfaces.Error_interface;
import static services.GUInterfaces.Waiting_interface;
import static services.Logger_init.logger4j;
import static services.Username.Username_filling;

public class BrowsingLRR_Folder {

public static void Processing(String directory){

    String LLR_text,path;
    ArrayList<String> cause = new ArrayList<>();
    ArrayList<String> effect = new ArrayList<>();
    
    File folder = new File(directory);
    File[] listOfFiles = folder.listFiles();

       for (File listOfFile : listOfFiles) {
        try {
            if (listOfFile.isFile()) {
                if (listOfFile.getName().contains(".docx") && (!listOfFile.getName().contains("~"))) {

                    JDialog dialog = Waiting_interface();

                    dialog.setModal(false);
                    dialog.setVisible(true);

                    //filling EXCEL
                    path =directory+ listOfFile.getName();

                    LLR_text = ExtractText.Extract_Text(path);

                    Excel_Final(path,LLR_text, Username_filling(), cause, effect,dialog);
                    cause= new ArrayList<>();
                    effect= new ArrayList<>();


                }
            }
        }
        catch (Exception e){
            logger4j.error(e);
            //JOptionPane.showMessageDialog(null, "", listOfFile.getName(), JOptionPane.ERROR_MESSAGE);
            Error_interface(String.valueOf(e));
        }
    }
}
}