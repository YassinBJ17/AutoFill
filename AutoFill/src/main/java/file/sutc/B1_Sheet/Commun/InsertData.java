package file.sutc.B1_Sheet.Commun;

import org.apache.commons.codec.binary.StringUtils;

import java.util.Objects;

import static file.commun.LoggerInitialize.log4Error;
import static file.sutc.B1_Sheet.B1_ExcelSheet.INTERNAL_VARIABLES_POSITION;
import static file.sutc.B1_Sheet.B1_ExcelSheet.Parameters;
import static file.sutc.B1_Sheet.Commun.ExtractData.Access_Detect;
import static file.sutc.B1_Sheet.Commun.ExtractData.robustnessTestOn;
import static file.sutc.B1_Sheet.DataDictionarySearch.DataDictionary.DataDictionarySearch;
import static file.sutc.B1_Sheet.FunctionReturnFilling.FunctionReturnFilling.INDEX_RESERVED_FOR_FUNCTION_RETURN;
import static file.sutc.Commun.ExcelManipulation.Fill_Cell;
import static file.sutc.Commun.ExcelManipulation.MergeRows;
import static file.sutc.Commun.ExcelRowsAndColsConstants.*;

public class InsertData {

    public static int Insert_Parameter(int row,int Parameter_number){

        if(Parameter_number!=INDEX_RESERVED_FOR_FUNCTION_RETURN)
            Parameters[Parameter_number][INDEX_OF_ACCESS]= Access_Detect(Parameter_number);

        if(row<= INTERNAL_VARIABLES_POSITION-2)
            Parameters[Parameter_number][INDEX_OF_ACCESS] = Parameters[Parameter_number][INDEX_OF_ACCESS].replace("R", "In").replace("W", "Out");


        if (((Parameters[Parameter_number][INDEX_OF_ACCESS].contains("W"))||(Parameters[Parameter_number][INDEX_OF_ACCESS].contains("Out")))&&(!(Parameters[Parameter_number][INDEX_OF_ACCESS].contains("/"))))
            Parameters[Parameter_number][INDEX_OF_CLASS]="-";

        if (((Parameters[Parameter_number][INDEX_OF_ACCESS].contains("R"))||(Parameters[Parameter_number][INDEX_OF_ACCESS].contains("In")))&&(!(Parameters[Parameter_number][INDEX_OF_INVALID_DOMAIN].equals("-")))) {
            int first_row = row;
            Insert_Invalid_Row(row, Parameters[Parameter_number],false);
            row++;
            Insert_Row(row, Parameters[Parameter_number],true);
            row++;
            Insert_Invalid_Row(row, Parameters[Parameter_number],true);
            for (int i = 1; i <= 5; i++)
            {

                try{
                MergeRows(SHEET_B1_INDEX, i, first_row + 1, row + 1); // merge need exact number because don't start with 0
                }catch (Exception e){
                    String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
                    log4Error(methodName+" : "+e.getMessage() );
                }
                }
        }else {
            Insert_Row(row, Parameters[Parameter_number],false);
        }
        return ++row;
    }

    public static void Insert_Invalid_Row(int row, String[] parameter,boolean last) {

        String name=parameter[INDEX_OF_NAME];

        if (last)
            parameter[INDEX_OF_NAME]="";

        if ((Objects.equals(parameter[INDEX_OF_ACCESS], "In"))||(Objects.equals(parameter[INDEX_OF_ACCESS], "R"))){
            parameter[INDEX_OF_INIT]="-";
        }else
            parameter[INDEX_OF_INIT]=" ";

            Insert_Manipulation(row, parameter);
            parameter[INDEX_OF_INVALID_DOMAIN] = Insert_Invalide_Manipulation(row, parameter);
            parameter[INDEX_OF_NAME]=name;


    }

    private static boolean isInAccess(String[] parameter) {
        return parameter[INDEX_OF_ACCESS].equalsIgnoreCase("in") || parameter[INDEX_OF_ACCESS].equalsIgnoreCase("R");
    }

    private static boolean isReadAccess(String[] parameter) {
        return parameter[INDEX_OF_ACCESS].equalsIgnoreCase("in/out") || parameter[INDEX_OF_ACCESS].equalsIgnoreCase("R/W");
    }

    public static void mergeRowsInRange(int row) {


        for (int i = 6; i <= 8; i++) {
            try{
            MergeRows(SHEET_B1_INDEX, i, row + 1, row + 2);
            }catch (Exception e){
                String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
                log4Error(methodName+" : "+e.getMessage() );
            }
            }
    }

    public static void Insert_Row(int row, String[] parameter,boolean last){
        String name=parameter[INDEX_OF_NAME];

        if (last)
            parameter[INDEX_OF_NAME]="";

        if ((Objects.equals(parameter[INDEX_OF_ACCESS], "In"))||(Objects.equals(parameter[INDEX_OF_ACCESS], "R"))){
                parameter[INDEX_OF_INIT]="-";
        }else
            parameter[INDEX_OF_INIT]=" ";


        Insert_Manipulation(row, parameter);
        parameter[INDEX_OF_NAME]=name;


    }




    public static String Insert_Invalide_Manipulation(int row,final String[] parameter){

        String firstInterval=parameter[INDEX_OF_INVALID_DOMAIN],secondInterval=parameter[INDEX_OF_INVALID_DOMAIN];
        robustnessTestOn=true;
        if (parameter[INDEX_OF_INVALID_DOMAIN].contains("#"))
        {
            firstInterval=parameter[INDEX_OF_INVALID_DOMAIN].substring(0,parameter[INDEX_OF_INVALID_DOMAIN].indexOf("#"));
            secondInterval=parameter[INDEX_OF_INVALID_DOMAIN].substring(parameter[INDEX_OF_INVALID_DOMAIN].indexOf("#")+1);

        }


    for (int i = 6; i <= 8; i++) {
        if (i == 7)
            Fill_Cell("I", SHEET_B1_INDEX, row, i);
        else {
            Fill_Cell(firstInterval, SHEET_B1_INDEX, row, i);
        }
    }
    return secondInterval;
    }

    public static String arraySizeReturn(String variableName,int sheet){

        String arraySize=DataDictionarySearch(variableName,2); // 2 signify array dimension

        if (arraySize.contains(".")){
            arraySize=arraySize.substring(0,arraySize.indexOf("."));
        }

        if (arraySize.matches("-?\\d+(\\.\\d+)?")) {
            int numericValue=1;

                if (sheet==SHEET_B1_INDEX) {
                    numericValue = Integer.parseInt(arraySize);
                    numericValue--;
                    arraySize = String.valueOf(numericValue);
                    return arraySize;
                }
                return arraySize;
        } else {
            if (sheet==SHEET_B1_INDEX) {
                return arraySize+"-1";
            }
            return arraySize;

    }
    }

    public static void Insert_Manipulation(int row, String[] parameter){
        for (int i = 1; i <= 9; i++) {
            if((i==4)||(i==5)||(i==7)){
                continue; }

            if (i==1) {
                if ((parameter[INDEX_OF_NAME].contains("["))&&(parameter[INDEX_OF_NAME].contains("]"))) {
                            Fill_Cell(parameter[INDEX_OF_NAME].replace("[", "[0..").replace("]", arraySizeReturn(parameter[INDEX_OF_NAME],SHEET_B1_INDEX)+"]"),SHEET_B1_INDEX, row, i); // array manipulation
                    if (!parameter[INDEX_OF_TYPE].equals("not exist in the DD"))
                    parameter[INDEX_OF_TYPE]=parameter[INDEX_OF_TYPE].replace("Array of","")+"[ARRAY]";
                }else if(parameter[INDEX_OF_TYPE].contains("Array of")) {
                    parameter[INDEX_OF_TYPE]=parameter[INDEX_OF_TYPE].replace("Array of","")+"[ARRAY]";
                    Fill_Cell(parameter[INDEX_OF_NAME]+"[0..-1]", SHEET_B1_INDEX, row, i);
                }else
                    Fill_Cell(parameter[i], SHEET_B1_INDEX,row,i);
            }else
                Fill_Cell(parameter[i], SHEET_B1_INDEX,row,i);
        }
    }

}
