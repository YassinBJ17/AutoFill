package file.sutc;
import org.apache.poi.ss.usermodel.Workbook;
import javax.swing.*;
import java.io.*;
import java.util.ArrayList;
import java.util.Objects;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import static file.code.ExtractFunction.ExtractFunctionFromCode;
import static file.commun.ExcelFormatMaintenance.excelFormatMaintenance;
import static file.s3d.ExtractCausesEffectTable.*;
import static file.s3d.ExtractFunction.ExtractFunctionFromSDDD;
import static file.s3d.ExtractRequirements.ExtractDescriptionOfRequirements;
import static file.s3d.ExtractRequirements.cleanLlrText;
import static file.s3d.ExtractTextFromS3D.ExtractTextFromSDDD;
import static file.sutc.A0_Sheet.A0_ExcelSheet.*;
import static file.sutc.A2_Sheet.A2_ExcelSheet.fillingA2Sheet;
import static file.sutc.B0_Sheet.B0_ExcelSheet.fillingB0Sheet;
import static file.sutc.B1_Sheet.B1_ExcelSheet.*;
import static file.sutc.Commun.LlrTraceability.llrTraceabilityFilling;
import static file.sutc.Commun.OpenCloseExcelTemplate.closeExcelTemplate;
import static file.sutc.Commun.SheetsNamesGenerating.fillingSheetsName;
import static file.commun.GraphicUserInterfaces.*;
import static file.commun.LoggerInitialize.*;
import static file.sutc.Commun.utcUftNumberCounter.utcUftCounter;

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
    public static String SDDD_Version;
    public static String CSC_Name;



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

    private static String pathOfTheNewExcelFile() {
       /* String directoryPath = "C:\\Projets\\Fadex\\dev\\work\\LLT\\OSS_PU_LLT\\LL_Tests_BeforeTC"; // Replace this with your directory path
        String fileName = functionName + "_SUTC.xls"; // Replace this with your file name

        File directory = new File(directoryPath);
        String filePath = searchFile(directory, fileName);

        if (filePath != null) {
            return filePath;
        } else {
            return "..\\Datafiles\\SUTC\\" + functionName + "_SUTC.xls"; // File not found
        }
*/

       return "..\\Datafiles\\SUTC\\" + functionName + ".xls";
    }

    private static String searchFile(File directory, String fileName) {
        File[] files = directory.listFiles();

        if (files != null) {
            for (File file : files) {
                if (file.isDirectory()) {
                    String filePath = searchFile(file, fileName); // Recursively search subdirectories
                    if (filePath != null) {
                        return filePath;
                    }
                } else if (file.getName().equals(fileName)) {
                    return file.getAbsolutePath();
                }
            }
        }
        return null; // File not found
    }

  public static void excelFinalManipulation(String path,String functionToGenerate) {

      String TextFromLlrFile,textFromSDDD;

      textFromSDDD = ExtractTextFromSDDD(path);
      SDDD_Version= getSDDD_Version(textFromSDDD);
      CSC_Name=getCSC_Name(textFromSDDD);
      Pattern pattern = Pattern.compile("\\b.*\nThis function",Pattern.CASE_INSENSITIVE); // key word in SDDD is "This function" should be existed in every function
      Matcher matcher = pattern.matcher(textFromSDDD);
      causeEffectTableOrder=getTheFirstCauseEffectTable(path);// used to locate the first Cause Effect Table in the SDDD
      JDialog dialog;

      while (matcher.find()) {

          causesTable= new ArrayList<>(); // initialize cause table
          effectsTable= new ArrayList<>(); // initialize effect table

          TextFromLlrFile =ExtractFunctionFromSDDD(textFromSDDD.substring(matcher.start()));
          llrOfTheFunction =TextFromLlrFile.split("\n"); //split each LLR line of the function in a table lowLevelReq

          functionName=llrOfTheFunction[1].trim().toLowerCase();

          if ((!Objects.equals(functionToGenerate, "start"))&&(!functionToGenerate.toLowerCase().equals(functionName))){
              causeEffectTableOrder++;
              continue;
          }

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
          TextFromLlrFile= cleanLlrText(TextFromLlrFile);

          ExtractDescriptionOfRequirements(TextFromLlrFile);// extract all requirements
          utcUftCounter();


          fillingA0Sheet(); // Filling A0
          //fillingA1Sheet(userName); // Filling A1
          fillingA2Sheet(); // Filling A2
          fillingB0Sheet(); // Filling B0
          fillingB1Sheet(); // Filling B1
          fillingSheetsName(); // Filling SheetsName
          llrTraceabilityFilling(); // Filling Traceability

          excelFormatMaintenance();
          WritingFile(newExcelFilePath);// save XLS

          dialog.setVisible(false); // hide the dialog
          log4Success(newExcelFilePath+" was saved successfully.");
      }
  }


}
