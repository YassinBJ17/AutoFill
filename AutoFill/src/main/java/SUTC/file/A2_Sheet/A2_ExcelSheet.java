package SUTC.file.A2_Sheet;

import static SUTC.file.COMMUN.ExcelRowsAndColsConstants.*;
import static SUTC.file.SutcCreationProccess.codeOfTheSoftware;
import static SUTC.file.COMMUN.ExcelModifier.*;
import static SUTC.file.COMMUN.ExcelModifier.Fill_Cell;


public class A2_ExcelSheet {

    public static boolean return_function;



    public static void extractHeaderFiles(String Code_line, int number_of_header_file){

        String header_files = Include_Modifier(Code_line); // extract the name of the header file
        Fill_Cell(header_files, SHEET_A2, number_of_header_file + SHEET_B1, CELL_COL_2);

    }

    public static void extractFunctionRetrun(String Code_line, String function_name){

        String prototype = Code_line;

        if (!(prototype.contains("void "))) { // the function return a value

            Fill_Cell("Variable", SHEET_A2, CELL_ROW_30, CELL_COL_1);
            Fill_Cell("RTRT_Ret", SHEET_A2, CELL_ROW_30, CELL_COL_2);

            String type = prototype.substring(0, prototype.indexOf(function_name) - 1);// type of the return value
            Fill_Cell(type, SHEET_A2, CELL_ROW_30, CELL_COL_3);

            return_function=true;
        }

    }


    public static void A2(String function_name){

        int number_of_header_file=0;
        
        for (String Code_line : codeOfTheSoftware) {

            if (Code_line.contains("#include")) {

                extractHeaderFiles(Code_line,number_of_header_file); // Files to be included filling
                number_of_header_file++;
            }
            else if (Prototype_Detect(Code_line, function_name)) { // detect function prototype

                extractFunctionRetrun(Code_line,function_name);
                break;
            }
        }
    }

}
