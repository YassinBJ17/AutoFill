import docx.file.ExtractText;

import javax.swing.*;
import java.awt.*;
import java.io.File;
import java.util.ArrayList;

import static docx.file.ExtractReq.Extract_Req;
import static docx.file.ExtractTable.Extract_Table;
import static excel.file.Services.ExcelFinal.Excel_Final;
public class Main {

    public static JDialog Waiting_windows() {

        String message = "Waiting..";
        JOptionPane pane = new JOptionPane(message, JOptionPane.INFORMATION_MESSAGE);
        pane.setForeground(Color.WHITE);
        JDialog dialog = pane.createDialog(null, "Message");
        dialog.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);

        return dialog;
    }

    public static void main(String[] args) {


        long startTime = System.currentTimeMillis();

        ArrayList<String> cause = new ArrayList<>();
        ArrayList<String> effect = new ArrayList<>();

        String LLR_text;
        String path,directory ;
        String userName = System.getProperty("user.name").toUpperCase();
        System.out.println("Welcome "+userName);
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
                    Extract_Table(path, cause, effect);
                    LLR_text = ExtractText.Extract_Text(path);
                    Extract_Req(LLR_text, cause, effect);
                    Excel_Final(LLR_text, userName, cause, effect,dialog);
                    cause= new ArrayList<>();
                    effect= new ArrayList<>();


                }
            }
        }
        catch (Exception e){
            e.printStackTrace();
            JOptionPane.showMessageDialog(null, "An error occurred!                                                                ", listOfFile.getName(), JOptionPane.ERROR_MESSAGE);

        }}} catch (Exception e) {
                   e.printStackTrace();
                    JOptionPane.showMessageDialog(null, "There is no LLR in this folder !", "Error", JOptionPane.ERROR_MESSAGE);
                                }


    }



}