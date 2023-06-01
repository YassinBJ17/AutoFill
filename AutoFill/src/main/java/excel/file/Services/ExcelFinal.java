package excel.file.Services;


import java.util.logging.Logger;
import excel.file.A2_Sheet.A2_sheet;
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
import static excel.file.A0_Sheet.A0_ExcelSheet.A0_sheet;
import static excel.file.A1_Sheet.A1_ExcelSheet.A1_sheet;
import static excel.file.B0_Sheet.A0_ExcelSheet.B0_sheet;
import static excel.file.B1_Sheet.B1_ExcelSheet.B1_sheet;
import static excel.file.Services.ExcelModifier.Fill_Cell;
import static excel.file.Services.SheetsName.Sheets_Name;
import static excel.file.Services.Template_Choosing.TemplateChoosing;
import static services.GUInterfaces.*;
import static services.Logger_init.logger4j;


public class ExcelFinal {

    public static final int maxUftNumber=8;
    public static final int minUftNumber=1;
    public static final int numberOfUtcPerUft=3;
    public static Workbook workbook;
    public static int number_of_UFT;
    public static int number_of_UTC;
    public static int number_of_causes=0;
    public static String[] codeOfTheSoftware;
    public static String[] lowLevelReqDocument;
    public static ArrayList<String> cause;
    public static boolean[] switchArray=new boolean[50];



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
        for (int i = 0; i < lowLevelReqDocument.length ; i++) {

            if (lowLevelReqDocument[i].toUpperCase().contains("REQUIREMENTS")){
                llr_traceability= lowLevelReqDocument[i+1];
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
                Error_interface(String.valueOf(e));
                logger4j.error(e);
                //JOptionPane.showMessageDialog(null, "Error: " + e.getMessage(), function_name + ".xls", JOptionPane.ERROR_MESSAGE);
            }
        }
    }

    private static void Switch_if_table_filling() {

    int index=0;
        for (String line : codeOfTheSoftware) {
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

      String SUTC_template;
      lowLevelReqDocument = LLR_text.split("\n");
      String functionName= lowLevelReqDocument[1];
      String newXLS_filePath = "..\\Datafiles\\SUTC\\" + lowLevelReqDocument[1] + ".xls"; // creation of the path
      File file = new File(newXLS_filePath);
      String cFileName=functionName+".c";
      String Code_text= ExtractCode.extract(cFileName);
      codeOfTheSoftware = Code_text.split("\n");
      cause=cause_table;// used to extract classes


      //////////////////////////////////////////////////////////////////////////////////////////
      //________________________________________________________________________________________
      if(file.exists()){
          if(FileExisteDialog(functionName))
              return; }
      //________________________________________________________________________________________
      //////////////////////////////////////////////////////////////////////////////////////////


      //////////////////////////////////////////////////////////////////////////////////////////
      //________________________________________________________________________________________
          Switch_if_table_filling(); // check if the code contains switch statements
          Extract_Table(path, cause_table, effect_table); // extract cause/effect table
          Extract_Req(LLR_text, cause_table, effect_table);// extract all requirements
          UTC_Number_Filling(cause_table); //
      //________________________________________________________________________________________
      //////////////////////////////////////////////////////////////////////////////////////////



      SUTC_template=TemplateChoosing();

      FileInputStream templateXLSfile = new FileInputStream(SUTC_template);// open tampate
      workbook = WorkbookFactory.create(templateXLSfile);


      //////////////////////////////////////////////////////////////////////////////////////////
      //________________________________________________________________________________________
          A0_sheet(); // Filling A0
          A1_sheet(userName); // Filling A0
          Sheets_Name(workbook); // Filling A0
          B0_sheet(cause_table,effect_table); // Filling A0
          if (!Code_text.isEmpty()) { // if conde not existe dont fill A2 and B1
              A2_sheet.A2(functionName);
              B1_sheet(workbook);
              }
          LLR_Traceability_Filling();
      //________________________________________________________________________________________
      //////////////////////////////////////////////////////////////////////////////////////////


      dialog.setVisible(false); // hide the dialog
      dialog.dispose(); // dispose of the dialog to release resources
      templateXLSfile.close();// Close XLS to
      WritingFile(newXLS_filePath,functionName);// save XLS
      OpenFileDialog(functionName); // open XLS


  }


}

