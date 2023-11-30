package file.sutc.A2_Sheet;

import static file.sutc.B1_Sheet.B1_ExcelSheet.Parameters;
import static file.sutc.B1_Sheet.Global.GlobalFilling.InternalDefinitionsExist;
import static file.sutc.Commun.ExcelRowsAndColsConstants.*;
import static file.sutc.SutcCreationProcess.codeOfTheFunction;
import static file.sutc.Commun.ExcelManipulation.*;
import static file.sutc.Commun.ExcelManipulation.Fill_Cell;
import static file.sutc.SutcCreationProcess.functionName;


public class A2_ExcelSheet {

    public static boolean return_function;
    public static int numberOfHeaderFiles =0;
    public static final int INTERNAL_DEFINITIONS_FIRST_LINE = 30;


    public static void Insert_Global_ParameterInA2(int Parameter_number) {

        Fill_Cell("Variable", SHEET_A2_INDEX, INTERNAL_DEFINITIONS_FIRST_LINE+ Parameter_number + 1 , CELL_COL_1);
        if (Parameters[Parameter_number][INDEX_OF_NAME].contains(".") || Parameters[Parameter_number][INDEX_OF_NAME].contains("->")) {
            int index;
            index = Parameters[Parameter_number][INDEX_OF_NAME].indexOf("->");

            if (index == -1)
                index = Parameters[Parameter_number][INDEX_OF_NAME].indexOf(".");

            Parameters[Parameter_number][INDEX_OF_NAME] = Parameters[Parameter_number][INDEX_OF_NAME].substring(0, index);
        }
        if (!InternalDefinitionsExist(Parameters[Parameter_number][INDEX_OF_NAME])) {
            Fill_Cell(Parameters[Parameter_number][INDEX_OF_NAME], SHEET_A2_INDEX, INTERNAL_DEFINITIONS_FIRST_LINE+ Parameter_number + 1, CELL_COL_2);
            Fill_Cell(Parameters[Parameter_number][INDEX_OF_TYPE].replace("[ARRAY]",""), SHEET_A2_INDEX, INTERNAL_DEFINITIONS_FIRST_LINE+ Parameter_number + 1, CELL_COL_3);
        }

    }

    public static void extractHeaderFiles(String Code_line, int number_of_header_file){


        String header_files = Include_Modifier(Code_line); // extract the name of the header file
        System.out.println(header_files+"-"+number_of_header_file);
        Fill_Cell(header_files, SHEET_A2_INDEX, number_of_header_file + SHEET_B1_INDEX, CELL_COL_2);
    }

    public static void extractFunctionReturn(String Code_line, String function_name){

        if (!(Code_line.contains("void "))) { // the function return a value
            Fill_Cell("Variable", SHEET_A2_INDEX, INTERNAL_DEFINITIONS_FIRST_LINE, CELL_COL_1);
            Fill_Cell("RTRT_Ret_"+function_name, SHEET_A2_INDEX, INTERNAL_DEFINITIONS_FIRST_LINE, CELL_COL_2);
            String type = Code_line.substring(0, Code_line.indexOf(function_name.toLowerCase()) - 1); // type of the return value
            Fill_Cell(type, SHEET_A2_INDEX, INTERNAL_DEFINITIONS_FIRST_LINE, CELL_COL_3);

            return_function=true;
        }
    }


    public static void fillingA2Sheet(){


        numberOfHeaderFiles=0;
        for (String Code_line : codeOfTheFunction) {

            if (Code_line.contains("#include")) {
                extractHeaderFiles(Code_line, numberOfHeaderFiles); // Files to be included filling
                numberOfHeaderFiles++;
            }
            else if (Prototype_Detect(Code_line, functionName)) { // detect function prototype

                extractFunctionReturn(Code_line,functionName);
                break;
            }
        }
    }

}
