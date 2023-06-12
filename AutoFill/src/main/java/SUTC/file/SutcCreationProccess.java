package SUTC.file;
import SUTC.file.A0_Sheet.A0_ExcelSheet;
import SUTC.file.A1_Sheet.A1_ExcelSheet;
import SUTC.file.A2_Sheet.A2_ExcelSheet;
import SUTC.file.B1_Sheet.B1_ExcelSheet;
import SUTC.file.COMMUN.ExcelModifier;
import org.apache.poi.ss.usermodel.Workbook;
import org.apache.poi.ss.usermodel.WorkbookFactory;
import CODE.file.ExtractCode;
import org.apache.poi.xwpf.usermodel.XWPFDocument;
import org.apache.poi.xwpf.usermodel.XWPFTable;
import org.apache.poi.xwpf.usermodel.XWPFTableCell;

import javax.swing.*;
import java.io.*;
import java.util.ArrayList;
import java.util.Objects;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import static SDDD.file.ExtractRequirements.Extract_Req;
import static SDDD.file.ExtractCausesEffectTable.Extract_Table;
import static SDDD.file.ExtractTextFromSDDD.Extract_Text;
import static SUTC.file.B0_Sheet.A0_ExcelSheet.B0_sheet;
import static SUTC.file.COMMUN.SheetsNamesGenerating.Sheets_Name;
import static SUTC.file.COMMUN.TemplateChoosing.Template_Choosing;
import static COMMUN.GraphicUserInterfaces.*;
import static COMMUN.LoggerInitialize.*;
import static SUTC.file.COMMUN.ExcelRowsAndColsConstants.*;

public class SutcCreationProccess {

    public static final int maxUftNumber=8;
    public static final int minUftNumber=1;
    public static final int numberOfUtcPerUft=3;
    public static Workbook workbook;
    public static int number_of_UFT;
    public static int number_of_UTC;
    public static int number_of_causes=0;
    public static String[] codeOfTheSoftware;
    public static String[] lowLevelReq;
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
        for (int i = 0; i < lowLevelReq.length ; i++) {

            if (lowLevelReq[i].toUpperCase().contains("REQUIREMENTS")){
                llr_traceability= lowLevelReq[i+1];
                llr_traceability=llr_traceability.substring(0,llr_traceability.length()-3);
                ExcelModifier.Fill_Cell(llr_traceability, SHEET_B0, CELL_ROW_3, CELL_COL_2+ number_of_UFT);
                ExcelModifier.Fill_Cell(llr_traceability, SHEET_B0, CELL_ROW_4+Math.max(1,number_of_causes), CELL_COL_2+ number_of_UFT);

                for (int j = 10; j < CELL_COL_10+ number_of_UTC; j++) {
                    ExcelModifier.Fill_Cell(llr_traceability, SHEET_B1, CELL_ROW_6, j);
                }

            }

        }

    }
    private static void WritingFile(String filePath) {

        while (true){
            try {
                FileOutputStream outputStream = new FileOutputStream(filePath);
                workbook.write(outputStream);
                outputStream.close();
                break;
            } catch (IOException e) {
                Error_interface(String.valueOf(e));
                String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
log4Error(methodName+" : "+e.getMessage() );
            }
        }
    }

    private static void Switch_if_table_filling() {

    int index=0;
        for (String line : codeOfTheSoftware) {
            if ((line.contains("switch ("))||(line.contains("switch("))) {
                switchArray[index] = true;
                log4Debug("Condition n°"+index+"= Switch ");
                index++;
            } else if ((line.contains("if ("))||(line.contains("if(")))  {
                switchArray[index] = false;
                log4Debug("Condition n°"+index+"= If ");
                index++;
            }
        }
    }

    private static String ExtractFunctionFromLRRDocument(String llr_to_treatment){

        llr_to_treatment=llr_to_treatment.substring(0,llr_to_treatment.indexOf("[END_REQ"));
        llr_to_treatment=" \n"+llr_to_treatment;

        return llr_to_treatment;
    }
    private static String[] ExtractFunctionFromCode(String functionName){

        String codeFileName=functionName+".c";
        String Code_text= ExtractCode.extract(codeFileName);
        if (Code_text.isEmpty())
            return null;
        return Code_text.split("\n");
    }
    private static String PathOfTheNewExcelFile(){

       return  "..\\Datafiles\\SUTC\\" + lowLevelReq[1] + ".xls";
    }
    private static int getTheFirstCauseEffectTable(String document_path){

        XWPFTableCell cell;
        XWPFTable table;
        try {
        File file = new File(document_path);
        FileInputStream fis = new FileInputStream(file);
        XWPFDocument document = new XWPFDocument(fis);

        for (int i = 0; i < document.getTables().size(); i++) {
            table = document.getTables().get(i);
            cell = table.getRow(0).getCell(1);
            if (cell!=null)
                if(cell.getText().equalsIgnoreCase("causes")){
                    document.close();
                    return i;
                }
        }
        document.close();
        } catch (Exception e){
            String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
            log4Error(methodName+" : "+e.getMessage() );
            Error_interface(String.valueOf(e));
        }
        return -1 ;
    }

  public static void Excel_Final(String path, String userName, ArrayList<String> cause_table, ArrayList<String> effect_table, JDialog dialog) {

      String functionName,SUTC_template,lowLevelReqText;

      String llr_text = Extract_Text(path);
      int CauseEffectTableOrder=getTheFirstCauseEffectTable(path);

      Pattern pattern = Pattern.compile("\\b.*\nThis function"); // key word in SDDD is "This function" should be existed in every function
      Matcher matcher = pattern.matcher(llr_text);

      while (matcher.find()) {

          dialog.setModal(false);
          dialog.setVisible(true);
          lowLevelReqText =ExtractFunctionFromLRRDocument(llr_text.substring(matcher.start()));
          lowLevelReq=lowLevelReqText.split("\n");
          functionName= lowLevelReq[1];// extract the name of the function
          codeOfTheSoftware=ExtractFunctionFromCode(functionName); // input function name
          String newExcel_filePath =PathOfTheNewExcelFile() ; // creation of the path
          cause=cause_table;// used to extract classes
          log4Info(functionName);
          String filePath = "..\\Datafiles\\SUTC\\" +functionName+ ".xls";
          File file = new File(filePath);

              // PART I
              //////////////////////////////////////////////////////////////////////////////////////////
              //________________________________________________________________________________________
               // if(file.exists()){ // check if file existe
                  if(FileExisteDialog(functionName)){
                      dialog.setVisible(false); // hide the dialog
                      dialog.dispose(); // dispose of the dialog to release resources
                      CauseEffectTableOrder++; // increment table order
                      continue;
                  }
               // }

              //}
              //________________________________________________________________________________________
              //////////////////////////////////////////////////////////////////////////////////////////

              // PART II
              //////////////////////////////////////////////////////////////////////////////////////////
              //________________________________________________________________________________________
                  Switch_if_table_filling(); // check if the code contains switch statements
                  Extract_Table(path, cause_table, effect_table,CauseEffectTableOrder); // extract cause/effect table
                  Extract_Req(lowLevelReqText, cause_table, effect_table);// extract all requirements
                  UTC_Number_Filling(cause_table);
              //________________________________________________________________________________________
              //////////////////////////////////////////////////////////////////////////////////////////

                  SUTC_template= Template_Choosing();
                  try {


                  FileInputStream templateXLSfile = new FileInputStream(SUTC_template);// open template
                  workbook = WorkbookFactory.create(templateXLSfile);


              //////////////////////////////////////////////////////////////////////////////////////////
              //________________________________________________________________________________________
                  A0_ExcelSheet.A0_sheet(); // Filling A0
                  A1_ExcelSheet.A1_sheet(userName); // Filling A0
                  Sheets_Name(workbook); // Filling A0
                  B0_sheet(cause_table,effect_table); // Filling A0
                  if (codeOfTheSoftware!=null) { // if conde not existe dont fill A2 and B1
                      A2_ExcelSheet.A2(functionName);
                      B1_ExcelSheet.B1_sheet(workbook);
                      }
                  LLR_Traceability_Filling();
              //________________________________________________________________________________________
              //////////////////////////////////////////////////////////////////////////////////////////

              log4Info("Saving progress");

              templateXLSfile.close();// Close XLS to
                  } catch (Exception e){
                      String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
                      log4Error(methodName+" : "+e.getMessage() );
                      Error_interface(String.valueOf(e));
                  }

              WritingFile(newExcel_filePath);// save XLS
              OpenFileDialog(functionName); // open XLS
              dialog.setVisible(false); // hide the dialog
              dialog.dispose(); // dispose of the dialog to release resourcesC:\Projets\Fadex\dev\work\LLR\OVSP\Lot1\CSC_OVSP\After QC

              CauseEffectTableOrder++; // increment table order
              cause_table= new ArrayList<>(); // initialize cause table
              effect_table= new ArrayList<>(); // initialize effect table
              log4Info(functionName+".xls saved in success");
      }
  }

}

