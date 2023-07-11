package SUTC.file.A2_Sheet;

import static SUTC.file.B1_Sheet.B1_ExcelSheet.INTERNAL_DEFINITIONS_POSITION;
import static SUTC.file.B1_Sheet.B1_ExcelSheet.Parameters;
import static SUTC.file.B1_Sheet.Global.GlobalFilling.InternalDefinitionsExist;
import static SUTC.file.COMMUN.ExcelRowsAndColsConstants.*;
import static SUTC.file.SutcCreationProccess.codeOfTheSoftware;
import static SUTC.file.COMMUN.ExcelModifier.*;
import static SUTC.file.COMMUN.ExcelModifier.Fill_Cell;


public class A2_ExcelSheet {

    public static boolean return_function;
    public static final int INTERNAL_DEFINITIONS_FIRST_LINE = 32;


    public static void Insert_Global_ParameterInA2(int Parameter_number) {

        Fill_Cell("Variable", SHEET_A2, INTERNAL_DEFINITIONS_POSITION + Parameter_number, CELL_COL_1);
        if (Parameters[Parameter_number][INDEX_OF_NAME].contains(".") || Parameters[Parameter_number][INDEX_OF_NAME].contains("->")) {
            int index;
            index = Parameters[Parameter_number][INDEX_OF_NAME].indexOf("->");

            if (index == -1)
                index = Parameters[Parameter_number][INDEX_OF_NAME].indexOf(".");

            Parameters[Parameter_number][INDEX_OF_NAME] = Parameters[Parameter_number][INDEX_OF_NAME].substring(0, index);
        }
        if (!InternalDefinitionsExist(Parameters[Parameter_number][INDEX_OF_NAME])) {
            Fill_Cell(Parameters[Parameter_number][INDEX_OF_NAME], SHEET_A2, INTERNAL_DEFINITIONS_POSITION + Parameter_number, CELL_COL_2);
            Fill_Cell(Parameters[Parameter_number][INDEX_OF_TYPE].replace("[ARRAY]",""), SHEET_A2, INTERNAL_DEFINITIONS_POSITION + Parameter_number, CELL_COL_3);
        }

    }

    public static void extractHeaderFiles(String Code_line, int number_of_header_file){

        String header_files = Include_Modifier(Code_line); // extract the name of the header file
        Fill_Cell(header_files, SHEET_A2, number_of_header_file + SHEET_B1, CELL_COL_2);

    }

    public static void extractFunctionReturn(String Code_line, String function_name){

        String prototype = Code_line;

        if (!(prototype.contains("void "))) { // the function return a value
            Fill_Cell("Variable", SHEET_A2, INTERNAL_DEFINITIONS_FIRST_LINE, CELL_COL_1);
            Fill_Cell("RTRT_Ret_"+function_name, SHEET_A2, INTERNAL_DEFINITIONS_FIRST_LINE, CELL_COL_2);

            String type = prototype.substring(0, prototype.indexOf(function_name) - 1);// type of the return value
            Fill_Cell(type, SHEET_A2, INTERNAL_DEFINITIONS_FIRST_LINE, CELL_COL_3);

            return_function=true;
        }

    }


    public static void A2_sheet(String function_name){

        int number_of_header_file=0;
        
        for (String Code_line : codeOfTheSoftware) {

            if (Code_line.contains("#include")) {

                extractHeaderFiles(Code_line,number_of_header_file); // Files to be included filling
                number_of_header_file++;
            }
            else if (Prototype_Detect(Code_line, function_name)) { // detect function prototype

                extractFunctionReturn(Code_line,function_name);
                break;
            }
        }
    }

}
