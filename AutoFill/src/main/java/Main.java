import docx.file.ExtractText;

import javax.swing.*;
import java.awt.*;
import java.io.*;
import java.util.ArrayList;
import java.util.Properties;

import static docx.file.ExtractReq.Extract_Req;
import static docx.file.ExtractTable.Extract_Table;
import static excel.file.Services.ExcelFinal.Excel_Final;
import static java.lang.System.exit;

public class Main {

    public static JDialog Waiting_windows() {

        String message = "Waiting..";
        JOptionPane pane = new JOptionPane(message, JOptionPane.INFORMATION_MESSAGE);
        pane.setForeground(Color.WHITE);
        JDialog dialog = pane.createDialog(null, "Message");
        dialog.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);

        return dialog;
    }
    public static boolean Verification_licences() throws IOException {

        Properties props = new Properties();
        try (InputStream is = new FileInputStream("..\\AutoFill\\target\\maven-archiver\\sfh.properties")) {
            props.load(is);
        }

        // Get the current version and decrement it
        int version = Integer.parseInt(props.getProperty("version"));
        version--;
        if (version==0){
            return true;
        }

        // Write the updated version back to the properties file
        try (OutputStream os = new FileOutputStream("..\\AutoFill\\target\\maven-archiver\\sfh.properties")) {
            props.setProperty("version", String.valueOf(version));
            props.store(os, null);
        }

        return false;
    }

    public static void main(String[] args) throws IOException {



        if(Verification_licences())
            System.exit(0);

        String userName = System.getProperty("user.name").toUpperCase();
        System.out.println("Welcome "+userName);
        ArrayList<String> cause = new ArrayList<>();
        ArrayList<String> effect = new ArrayList<>();

        String LLR_text;
        String path,directory ;

        directory=JOptionPane.showInputDialog(null,"LLR path                                                                                                   ","..\\Datafiles\\LLR")+"\\";

        File folder = new File(directory);
        File[] listOfFiles = folder.listFiles();





try {
    assert listOfFiles != null;
    for (File listOfFile : listOfFiles) {
            try {
            if (listOfFile.isFile()) {
                if (listOfFile.getName().contains(".docx") && (!listOfFile.getName().contains("~"))) {

                    JDialog dialog = Waiting_windows();

                    dialog.setModal(false);
                    dialog.setVisible(true);

                    //filling EXCEL
                    path =directory+ listOfFile.getName();

                    LLR_text = ExtractText.Extract_Text(path);

                    Excel_Final(path,LLR_text, userName, cause, effect,dialog);
                    cause= new ArrayList<>();
                    effect= new ArrayList<>();


                }
            }
        }
        catch (Exception e){
            e.printStackTrace();
            JOptionPane.showMessageDialog(null, "", listOfFile.getName(), JOptionPane.ERROR_MESSAGE);

        }
    }
} catch (Exception e) {
                   e.printStackTrace();
                    JOptionPane.showMessageDialog(null, "There is no LLR in this folder !", "Error", JOptionPane.ERROR_MESSAGE);
                                }







    }







}