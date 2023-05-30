package excel.file.Services;

import excel.file.A0.A0_sheet;
import java.util.logging.Logger;
import excel.file.A1.A1_sheet;
import excel.file.A2.A2_sheet;
import excel.file.B0.B0_sheet;
import excel.file.B1.B1_sheet;
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
import static docx.file.ExtractReq.Extract_Req;
import static docx.file.ExtractTable.Extract_Table;
import static excel.file.Services.ExcelModifier.Fill_Cell;


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

        int uft;

        number_of_causes=0;
        for (String cs:cause_table) {
            if (!Objects.equals(cs, "null"))
            number_of_causes++;
        }

        uft=number_of_causes+1;

        if (uft > 4)
            uft=maxUftNumber;

        number_of_UFT =uft+minUftNumber;
        number_of_UTC =(uft*numberOfUtcPerUft);

    }
    public static void LLR_Traceability_Filling(){

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
            //System.out.println("Error opening file: " + e.getMessage());
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }

    }

    public static String[] Code ;
    public static String[] LLR;
    public static ArrayList<String> cause;
    public static boolean[] switchArray=new boolean[50];
    private static void Switch_if_table_filling() {

    int index=0;


        for (String line : Code) {

            if ((line.contains("switch ("))||(line.contains("switch("))) {
                switchArray[index] = true;
                index++;

            } else if ((line.contains("if ("))||(line.contains("if(")))  {
                switchArray[index] = false;
                index++;
            }


        }

        }

  public static void Excel_Final(String path,String LLR_text, String userName, ArrayList<String> cause_table, ArrayList<String> effect_table, JDialog dialog) throws IOException {

      String template;
      LLR = LLR_text.split("\n");
      String function_name=LLR[1];
      String file_name=function_name+".c";
      String Code_text= ExtractCode.extract(file_name);
      Code = Code_text.split("\n");

          Switch_if_table_filling();
          Extract_Table(path, cause_table, effect_table);
          Extract_Req(LLR_text, cause_table, effect_table);
          UTC_Number_Filling(cause_table);

      LOGGER.setLevel(Level.INFO);
      cause=cause_table;

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

          new A0_sheet();
          new A1_sheet(userName);
          new SheetsName(workbook);
          new B0_sheet(cause_table,effect_table,workbook);
          if (!Code_text.isEmpty()) {
              A2_sheet.A2(function_name);
              new B1_sheet(workbook);
              }
              LLR_Traceability_Filling();


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

