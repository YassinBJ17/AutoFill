package excel.file.A2;

import excel.file.Services.Excel;

import static excel.file.Services.ExcelFinal.Code;
import static excel.file.Services.ExcelModifier.*;
import static excel.file.Services.ExcelModifier.Fill_Cell;




public class A2_sheet {

    public static boolean return_function;

    public static void A2(String function_name){

        int number_of_header_file=0;
        
        String header_files;
        String prototype;
        
        for (String Code_line : Code) {



            if (Code_line.contains("#include")) {
                
                    header_files = Include_Modifier(Code_line); // extract the name of the file 
                    Fill_Cell(header_files, Excel.SHEET_A2, number_of_header_file + Excel.SHEET_B1, Excel.CELL_COL_2);
                    number_of_header_file++;

            }


            else if (Prototype_Detect(Code_line, function_name)) {
                
                prototype = Code_line;
                
                if (!(prototype.contains("void "))) { // the function return a value 
                    
                    Fill_Cell("Variable", Excel.SHEET_A2, Excel.CELL_ROW_30, Excel.CELL_COL_1);
                    Fill_Cell("RTRT_Ret", Excel.SHEET_A2, Excel.CELL_ROW_30, Excel.CELL_COL_2);
                    
                    String type = prototype.substring(0, prototype.indexOf(function_name) - 1);// type of the return value
                    Fill_Cell(type, Excel.SHEET_A2, Excel.CELL_ROW_30, Excel.CELL_COL_3);

                    return_function=true;
                }
                break;
            }
        }
    }

}
