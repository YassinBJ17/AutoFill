package excel.file;

import org.apache.logging.log4j.LogManager;
import java.util.logging.Logger;
import org.apache.poi.ss.usermodel.Workbook;
import org.apache.poi.ss.usermodel.WorkbookFactory;
import c.file.ExtractCode;
import javax.swing.*;
import java.awt.*;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Objects;
import java.util.logging.Level;
import java.util.logging.*;


import static excel.file.ExcelModifier.Fill_Cell;


public class ExcelFinal {
    private static final Logger LOGGER = Logger.getLogger(ExcelFinal.class.getName());

    public static final String TEMPLATE0_PATH ="../AutoFill/src/Template/SUTC TEMPLATE0.xls";
    public static final String TEMPLATE1_PATH ="../AutoFill/src/Template/SUTC TEMPLATE1.xls";
    public static final String TEMPLATE2_PATH ="../AutoFill/src/Template/SUTC TEMPLATE2.xls";
    public static final String TEMPLATE3_PATH ="../AutoFill/src/Template/SUTC TEMPLATE3.xls";
    public static final String TEMPLATEn_PATH ="../AutoFill/src/Template/SUTC TEMPLATEn.xls";
    public static final int maxUftNumber=8;
    public static final int minUftNumber=1;
    public static final int numberOfUtcPerUft=3;

    public static Workbook workbook;
    public static int number_of_UFT;

    public static int number_of_UTC;

    public static int number_of_causes=0;


    public static void UTC_Number_Filling( ArrayList<String> cause_table){

        int uft=0;
        number_of_causes=0;
        for (String cs:cause_table
        ) {if (!Objects.equals(cs, "null"))
            number_of_causes++;
        }

        uft=number_of_causes+1;

        if (uft > 4)
            uft=8;

        number_of_UFT =uft+1;
        number_of_UTC =(uft*numberOfUtcPerUft);

    }
    public static void LLR_Traceability_Filling(String[] LLR){

        String llr_traceability;
        for (int i = 0; i < LLR.length ; i++) {

            if (LLR[i].toUpperCase().contains("REQUIREMENTS")){
                llr_traceability=LLR[i+1];
                llr_traceability=llr_traceability.substring(0,llr_traceability.length()-3);
                Fill_Cell(llr_traceability,Excel.SHEET_B0,Excel.CELL_ROW_3,Excel.CELL_COL_2+ number_of_UFT);
                Fill_Cell(llr_traceability,Excel.SHEET_B0,Excel.CELL_ROW_4+Math.max(1,number_of_causes),Excel.CELL_COL_2+ number_of_UFT);

                for (int j = 10; j <Excel.CELL_COL_10+ number_of_UTC; j++) {
                    Fill_Cell(llr_traceability, Excel.SHEET_B1, Excel.CELL_ROW_6, j);
                }

            }

        }

    }


    private static void WritingFile(String filePath, String function_name) {

        while (true){
            try {
                FileOutputStream outputStream = new FileOutputStream(filePath);
                workbook.write(outputStream);
                outputStream.close();
                break;
            } catch (IOException e) {
                JOptionPane.showMessageDialog(null, "Error: " + e.getMessage(), function_name + ".xls", JOptionPane.ERROR_MESSAGE);
            }
        }
    }

    private static boolean FileExisteDialog(String function_name) {


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
            LOGGER.info("The operation has been canceled by the user");
            return true;
        }else
            return false;
    }

    private static void OpenFileDialog(String function_name) {

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
            Thread.sleep(100);
        } catch (IOException e) {
            System.out.println("Error opening file: " + e.getMessage());
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }

    }


  public static void Excel_Final(String LLR_text, String userName, ArrayList<String> cause_table, ArrayList<String> effect_table, JDialog dialog) throws IOException {

      String template;
      UTC_Number_Filling(cause_table);
      LOGGER.setLevel(Level.INFO);

      switch (number_of_causes) {
          case 0 -> {
              template = TEMPLATE0_PATH;
              LOGGER.info("TEMPLATE 0");
          }
          case 1 -> {
              template = TEMPLATE1_PATH;
              LOGGER.info("TEMPLATE 1");
          }
          case 2 -> {
              template = TEMPLATE2_PATH;
              LOGGER.info("TEMPLATE 2");
          }
          case 3 -> {
              template = TEMPLATE3_PATH;
              LOGGER.info("TEMPLATE 3");
          }
          default -> {
              template = TEMPLATEn_PATH;
              LOGGER.info("TEMPLATE n is used");
          }
      }


     FileInputStream inputStream = new FileInputStream(template);
     workbook = WorkbookFactory.create(inputStream);

      String[] LLR = LLR_text.split("\n");
      String function_name=LLR[1];
      String file_name=function_name+".c";
      String Code_text= ExtractCode.extract(file_name);
      String[] Code = Code_text.split("\n");

          new A0_sheet(LLR);
          new A1_sheet(userName);
          new SheetsName(LLR,workbook);
          new B0_sheet(LLR,cause_table,effect_table,workbook);

          if (!Code_text.isEmpty()) {
              A2_sheet.A2(Code, function_name);
              new B1_sheet(LLR,Code,workbook);
              }
              LLR_Traceability_Filling(LLR);


      dialog.setVisible(false); // hide the dialog
      dialog.dispose(); // dispose of the dialog to release resources

                inputStream.close();
                String filePath = "..\\Datafiles\\SUTC\\" + LLR[1] + ".xls";
                File file = new File(filePath);
                if(file.exists()){
                    if(FileExisteDialog(function_name))
                        return;
                }

             WritingFile(filePath,function_name);
             OpenFileDialog(function_name);

  }

}

