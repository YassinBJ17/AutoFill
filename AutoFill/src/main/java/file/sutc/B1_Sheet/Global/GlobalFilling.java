package file.sutc.B1_Sheet.Global;
import file.sutc.B1_Sheet.B1_ExcelSheet;
import file.sutc.Commun.ExcelManipulation;
import static file.sutc.A2_Sheet.A2_ExcelSheet.Insert_Global_ParameterInA2;
import static file.sutc.B1_Sheet.B1_ExcelSheet.*;
import static file.sutc.Commun.ExcelManipulation.MergeRows;
import static file.sutc.Commun.ExcelRowsAndColsConstants.*;
import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.ss.usermodel.Sheet;
import java.util.Objects;
import static file.sutc.B1_Sheet.DataDictionarySearch.DataDictionary.DataDictionarySearch;
import static file.sutc.B1_Sheet.Commun.ExtractData.Extract_Domain;
import static file.sutc.B1_Sheet.Commun.ExtractData.Extract_Invalid_Domain;
import static file.sutc.B1_Sheet.Commun.InsertData.Insert_Invalid_Row;
import static file.sutc.B1_Sheet.Commun.InsertData.Insert_Row;
import static file.commun.GraphicUserInterfaces.Error_interface;
import static file.commun.LoggerInitialize.*;
import static file.sutc.SutcCreationProcess.llrOfTheFunction;
import static file.sutc.SutcCreationProcess.workbook;


public class GlobalFilling {

    public static void GlobalParametersFilling() {


        Parameters=new String[100][10];
        int numberOfGlobals=Extract_Global();


            for (int i = 0; i < numberOfGlobals; i++) {

                try {
                if (Globals[i].contains("{"))

                    Parameters[i][INDEX_OF_NAME]= Globals[i].substring(Globals[i].indexOf("{")+1, B1_ExcelSheet.Globals[i].indexOf("}")) ;
                else
                    Parameters[i][INDEX_OF_NAME]=Globals[i].substring(0, Globals[i].indexOf(" ")) ;

                    } catch (Exception e){
                        Error_interface(e+" : "+Globals[i]);
                        String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
                        log4Error(methodName+" : "+e.getMessage() );
                    }

                Parameters[i][INDEX_OF_TYPE]= DataDictionarySearch(Parameters[i][INDEX_OF_NAME],true) ;
                String[] domainClass = Extract_Domain(Parameters[i][INDEX_OF_TYPE].replace("Array of",""));
                Parameters[i][INDEX_OF_DOMAIN]=domainClass[0];
                Parameters[i][INDEX_OF_CLASS]=domainClass[0];
                Parameters[i][INDEX_OF_INVALID_DOMAIN]=domainClass[1];

                if(Parameters[i][INDEX_OF_DOMAIN].equals("-")) {
                    Parameters[i][INDEX_OF_DOMAIN] = DataDictionarySearch(Parameters[i][INDEX_OF_TYPE], false);
                    Parameters[i][INDEX_OF_CLASS] = Parameters[i][INDEX_OF_DOMAIN];
                    Parameters[i][INDEX_OF_INVALID_DOMAIN]=Extract_Invalid_Domain(Parameters[i][INDEX_OF_DOMAIN]);
                }

                Global_Start+=Insert_Global_Parameter(Global_Start+i,i);
            }

    }
    public static int Extract_Global(){

        int numberOfGlobals=0;

        for (int i = 0; i < llrOfTheFunction.length; i++) {

            if (ExcelManipulation.Search(Global_start,llrOfTheFunction[i].trim())){
                int j=i+1;
                while (!ExcelManipulation.Search(Global_end,llrOfTheFunction[j].trim())){

                    if((llrOfTheFunction[j].trim().equalsIgnoreCase("None"))||(llrOfTheFunction[j].trim().equalsIgnoreCase("None.")))break;

                    if((!(llrOfTheFunction[j].trim().isEmpty()))&&(!(ExcelManipulation.Search(B1_ExcelSheet.Globals, llrOfTheFunction[j])))){
                        Globals[numberOfGlobals]=llrOfTheFunction[j].trim();
                        numberOfGlobals++;
                    }
                    j++;
                }
            }
        }
        return numberOfGlobals;
    }
    public static String Access_Global_Detect(String[] LLR, String parameter_name){


        for (int i = 0; i < LLR.length; i++) {

            if(LLR[i].contains(parameter_name)){
                LLR[i]=LLR[i].replace("\\","/");
                if((LLR[i].toUpperCase().contains("IN:"))||(LLR[i].toUpperCase().contains("IN :")))
                    return "R";
                else  if((LLR[i].toUpperCase().contains("IN/OUT:"))||(LLR[i].toUpperCase().contains("IN/OUT :")))
                    return "R/W";
                else  if((LLR[i].toUpperCase().contains("OUT:"))||(LLR[i].toUpperCase().contains("OUT :")))
                    return "W";
                else{

                    for(int j = i; j >=0; j--)
                    {
                        if(LLR[j].toUpperCase().contains("OUTPUT DATA"))
                            return "W";
                        else if(LLR[j].toUpperCase().contains("INPUT DATA"))
                            return "R";
                    }
                }
            }
        }
        return"";
    }
    public static boolean InternalDefinitionsExist(String parameter){

        Sheet A2_sheet= workbook.getSheetAt(SHEET_A2_INDEX);

        for (int i = 3; i <60 ; i++) {
            Row row = A2_sheet.getRow(i);

            if (row != null) {
                // Get the second cell in the row
                Cell cell = row.getCell(2);
                if (Objects.equals(cell.toString(), parameter))
                    return true;
            }

        }
        return false;
    }
    public static int Insert_Global_Parameter(int row, int parameterNumber) {
        int return_Number_Of_Rows;
        Parameters[parameterNumber][INDEX_OF_ACCESS]= Access_Global_Detect(llrOfTheFunction, Parameters[parameterNumber][INDEX_OF_NAME]);
        Parameters[parameterNumber][INDEX_OF_NAME]= Parameters[parameterNumber][INDEX_OF_NAME].replace(":","");

        if ((Parameters[parameterNumber][INDEX_OF_ACCESS].contains("W"))&&(!(Parameters[parameterNumber][INDEX_OF_ACCESS].contains("/")))){
            Parameters[parameterNumber][INDEX_OF_CLASS]="-";
            Insert_Row(row, Parameters[parameterNumber],false);
            return_Number_Of_Rows=1;

        }else if (((Parameters[parameterNumber][INDEX_OF_ACCESS].contains("R")))&&(!(Parameters[parameterNumber][INDEX_OF_INVALID_DOMAIN].equals("-")))){

            int fist_row=row;
            row+=Insert_Invalid_Row(row, Parameters[parameterNumber]);
            row+=Insert_Row(row, Parameters[parameterNumber],false);
            //row++;
            row+=Insert_Invalid_Row(row, Parameters[parameterNumber]);
            // merge cells
            for (int i = 1; i <= 5; i++)
            MergeRows(SHEET_B1_INDEX, i, fist_row+1, row );

            return_Number_Of_Rows=5;

        }else {
            Insert_Row(row, Parameters[parameterNumber],false);
            return_Number_Of_Rows=1;
        }

        // A2 filling
        Insert_Global_ParameterInA2( parameterNumber);
        return return_Number_Of_Rows;
    }


}
