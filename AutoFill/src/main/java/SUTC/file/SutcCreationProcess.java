package SUTC.file;
import org.apache.poi.ss.usermodel.Workbook;
import javax.swing.*;
import java.io.*;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import static CODE.file.ExtractFunction.ExtractFunctionFromCode;
import static SDDD.file.ExtractCausesEffectTable.*;
import static SDDD.file.ExtractFunction.ExtractFunctionFromSDDD;
import static SDDD.file.ExtractRequirements.Extract_Req;
import static SDDD.file.ExtractRequirements.cleanLllrText;
import static SDDD.file.ExtractText.ExtractTextFromSDDD;
import static SUTC.file.A0_Sheet.A0_ExcelSheet.fillingA0Sheet;
import static SUTC.file.A1_Sheet.A1_ExcelSheet.fillingA1Sheet;
import static SUTC.file.A2_Sheet.A2_ExcelSheet.fillingA2Sheet;
import static SUTC.file.B0_Sheet.B0_ExcelSheet.fillingB0Sheet;
import static SUTC.file.B1_Sheet.B1_ExcelSheet.*;
import static SUTC.file.Commun.LlrTraceability.llrTraceabilityFilling;
import static SUTC.file.Commun.OpenCloseExcelTemplate.closeExcelTemplate;
import static SUTC.file.Commun.SheetsNamesGenerating.fillingSheetsName;
import static Commun.GraphicUserInterfaces.*;
import static Commun.LoggerInitialize.*;
import static SUTC.file.Commun.utcUftNumberCounter.utcUftCounter;

public class SutcCreationProcess {

    public static ArrayList<String> causesTable ;
    public static ArrayList<String> effectsTable;
    public static int numberOfUFT;
    public static int numberOfUTC;
    public static Workbook workbook;
    public static FileInputStream templateXLSfile;

    public static String functionName;
    public static String[] codeOfTheFunction;
    public static String[] llrOfTheFunction;
    public static ArrayList<String> cause;




    private static void WritingFile(String filePath) {

        closeExcelTemplate();
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
        //OpenFileDialog(functionName); // open XLS
    }

    private static String pathOfTheNewExcelFile(){
       return  "..\\Datafiles\\SUTC\\" + functionName + ".xls";
    }




  public static void excelFinalManipulation(String path, String userName) {

      String functionTextFromLlrFile,textFromSDDD;


      textFromSDDD = ExtractTextFromSDDD(path);
      Pattern pattern = Pattern.compile("\\b.*\nThis function"); // key word in SDDD is "This function" should be existed in every function
      Matcher matcher = pattern.matcher(textFromSDDD);
      causeEffectTableOrder=getTheFirstCauseEffectTable(path);// used to locate the first Cause Effect Table in the SDDD
      JDialog dialog;

      while (matcher.find()) {


          causesTable= new ArrayList<>(); // initialize cause table
          effectsTable= new ArrayList<>(); // initialize effect table


          functionTextFromLlrFile =ExtractFunctionFromSDDD(textFromSDDD.substring(matcher.start()));

          llrOfTheFunction =functionTextFromLlrFile.split("\n"); //split each LLR line of the function in a table lowLevelReq
          functionName=llrOfTheFunction[1].trim();
          log4Info(functionName); // extract the name of the function
          codeOfTheFunction =ExtractFunctionFromCode(functionName);


          if (codeOfTheFunction ==null) {
              causeEffectTableOrder++; // increment table order
              continue;
          }

          dialog = Waiting_interface(functionName+" Waiting..");
          dialog.setModal(false);
         // dialog.setVisible(true);

          String newExcelFilePath = pathOfTheNewExcelFile() ; // creation of the path
          Extract_Table(path); // extract cause/effect table
          functionTextFromLlrFile=cleanLllrText(functionTextFromLlrFile);
          Extract_Req(functionTextFromLlrFile);// extract all requirements
          utcUftCounter();


          fillingA0Sheet(); // Filling A0
          fillingA1Sheet(userName); // Filling A1
          fillingA2Sheet(); // Filling A2
          fillingB0Sheet(); // Filling B0
          fillingB1Sheet(); // Filling B1
          fillingSheetsName(); // Filling SheetsName
          llrTraceabilityFilling(); // Filling Traceability


          WritingFile(newExcelFilePath);// save XLS
          dialog.setVisible(false); // hide the dialog
          log4Info(functionName+".xls was saved successfully.");
      }
  }


}
