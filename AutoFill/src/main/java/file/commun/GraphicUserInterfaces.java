package file.commun;

import javax.swing.*;
import java.awt.*;
import java.io.File;
import java.io.IOException;

import static file.commun.LoggerInitialize.*;

public class GraphicUserInterfaces {
    public static JDialog Waiting_interface(String message) {


        JOptionPane pane = new JOptionPane(message, JOptionPane.INFORMATION_MESSAGE);
        pane.setForeground(Color.WHITE);
        JDialog dialog = pane.createDialog(null, "Message");
        dialog.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);

        return dialog;
    }
    public static String Path_interface(){

        return JOptionPane.showInputDialog(null,"LLR path                                                                                                   ","..\\Datafiles\\LLR")+"\\";
    }

    public static String Version_interface(){

        return JOptionPane.showInputDialog(null,"Version :");
    }

    public static String Date_interface(){

        return JOptionPane.showInputDialog(null,"Date :");
    }


    public static boolean FileExisteDialog(String function_name) {


        Object[] options = {"Ok", "Cancel"};
        int choice = JOptionPane.showOptionDialog(null,
                "File already exists, Do you want to overwrite it?",
                function_name + ".xls",
                JOptionPane.YES_NO_OPTION,
                JOptionPane.QUESTION_MESSAGE,
                null,
                options,
                options[1]);

        if(choice == JOptionPane.NO_OPTION){
            log4Error("The operation has been canceled by the user");
            return true;
        }else
            return false;


        /* Copied FROM SutcCreationProcess /*
        // if(file.exists()){ // check if file existe
                 /* if(FileExisteDialog(functionName)){
                      dialog.setVisible(false); // hide the dialog
                      dialog.dispose(); // dispose of the dialog to release resources
                      causeEffectTableOrder++; // increment table order
                      continue; }
               // }
              //}*/


    }
    public static void OpenFileDialog(String function_name) {

        try {
            int result = JOptionPane.showOptionDialog(
                    null, // Parent component (null for default)
                    "The excel file have been generated successfully in SUTC folder, Do you want to open it ?", // Message to display
                    function_name + ".xls", // Dialog title
                    JOptionPane.YES_NO_OPTION, // Option type
                    JOptionPane.QUESTION_MESSAGE, // Message type
                    null, // Icon (null for default)
                    new String[]{"Yes", "No"}, // Button options
                    "Yes" // Default button option
            );
            if (result == 0)
                Desktop.getDesktop().open(new File("..\\Datafiles\\SUTC\\" + function_name + ".xls"));
        } catch (IOException e) {
            String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
log4Error(methodName+" : "+e.getMessage() );

        }

    }
    public static void Error_interface(String e){
    JOptionPane.showMessageDialog(null, e, "Error", JOptionPane.ERROR_MESSAGE);
}

}
