package excel.file;

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

import static excel.file.ExcelModifier.Fill_Cell;


public class ExcelFinal {

    public static final String TEMPLATE0_PATH ="../AutoFill/src/Template/SUTC TEMPLATE0.xls";
    public static final String TEMPLATE1_PATH ="../AutoFill/src/Template/SUTC TEMPLATE1.xls";
    public static final String TEMPLATE2_PATH ="../AutoFill/src/Template/SUTC TEMPLATE2.xls";
    public static final String TEMPLATE3_PATH ="../AutoFill/src/Template/SUTC TEMPLATE3.xls";
    public static final String TEMPLATEx_PATH ="../AutoFill/src/Template/SUTC TEMPLATEx.xls";
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
                Fill_Cell(llr_traceability,Excel.SHEET_B0,Excel.CELL_ROW_4+number_of_causes,Excel.CELL_COL_2+ number_of_UFT);

                for (int j = 10; j <Excel.CELL_COL_10+ number_of_UTC; j++) {
                    Fill_Cell(llr_traceability, Excel.SHEET_B1, Excel.CELL_ROW_6, j);
                }

            }

        }

    }






  public static void Excel_Final(String LLR_text, String userName, ArrayList<String> cause_table, ArrayList<String> effect_table, JDialog dialog) throws IOException {

      String template;
      UTC_Number_Filling(cause_table);

        switch (number_of_causes) {
            case 0:
                template = TEMPLATE0_PATH;
                System.out.println("TEMPLATE 0");
                break;
            case 1:
                template = TEMPLATE1_PATH;
                System.out.println("TEMPLATE 1");
                break;
            case 2:
                template = TEMPLATE2_PATH;
                System.out.println("TEMPLATE 2");
                break;
            case 3:
                template = TEMPLATE3_PATH;
                System.out.println("TEMPLATE 3");
                break;
            default:
                template = TEMPLATEx_PATH;
                System.out.println("TEMPLATE x");
                break;
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

                    //disappear Waiting window
                  dialog.setVisible(false); // hide the dialog
                  dialog.dispose(); // dispose of the dialog to release resources

                inputStream.close();
                String filePath = "..\\Datafiles\\SUTC\\" + LLR[1] + ".xls";
                File file = new File(filePath);
                if(file.exists()){
                    Object[] options = {"Ok", "Cancel"};

                    int choice = JOptionPane.showOptionDialog(null,
                            "File already exists, Do you want to overwrite it?",
                            LLR[1] + ".xls",
                            JOptionPane.YES_NO_OPTION,
                            JOptionPane.QUESTION_MESSAGE,
                            null,
                            options,
                            options[1]);

                    if(choice == JOptionPane.NO_OPTION){
                        JOptionPane.showMessageDialog(null, "Operation cancelled by user.");
                        return;
                    }
                }
      while (true){
            try {
                FileOutputStream outputStream = new FileOutputStream(filePath);
                workbook.write(outputStream);
                outputStream.close();
                break;
            } catch (IOException e) {
                JOptionPane.showMessageDialog(null, "Error: " + e.getMessage(), LLR[1] + ".xls", JOptionPane.ERROR_MESSAGE);
            }
        }





      try {
          int result = JOptionPane.showOptionDialog(
                  null, // Parent component (null for default)
                  "The excel file have been generated successfully in SUTC folder, Do you want to open it ?", // Message to display
                  LLR[1] + ".xls", // Dialog title
                  JOptionPane.YES_NO_OPTION, // Option type
                  JOptionPane.QUESTION_MESSAGE, // Message type
                  null, // Icon (null for default)
                  new String[]{"Yes", "No"}, // Button options
                  "Yes" // Default button option
          );
          if (result == 0)
              Desktop.getDesktop().open(new File("..\\Datafiles\\SUTC\\" + LLR[1] + ".xls"));
          Thread.sleep(1000);
      } catch (IOException e) {
          System.out.println("Error opening file: " + e.getMessage());
      } catch (InterruptedException e) {
          throw new RuntimeException(e);
      }


  }
  }

