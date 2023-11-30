package file.sutc.B1_Sheet.Commun;
import java.util.Objects;
import static file.sutc.B1_Sheet.B1_ExcelSheet.INTERNAL_VARIABLES_POSITION;
import static file.sutc.B1_Sheet.B1_ExcelSheet.Parameters;
import static file.sutc.B1_Sheet.Commun.ExtractData.Access_Detect;
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

        if (((Parameters[Parameter_number][INDEX_OF_ACCESS].contains("R"))||(Parameters[Parameter_number][INDEX_OF_ACCESS].contains("In")))&&(!(Parameters[Parameter_number][INDEX_OF_INVALID_DOMAIN].equals("-")))){
            int fist_row=row;
            row+=Insert_Invalid_Row(row, Parameters[Parameter_number]);
            row+=Insert_Row(row, Parameters[Parameter_number],false);
            row+=Insert_Invalid_Row(row, Parameters[Parameter_number]);

            for (int i = 1; i <= 5; i++)
                MergeRows(SHEET_B1_INDEX, i, fist_row+1, row );

        }else {
            row += Insert_Row(row, Parameters[Parameter_number],false);
        }
        return ++row;
    }
    public static int Insert_Invalid_Row(int row, String[] parameter){



            Insert_Manipulation(row,parameter);


            if ((parameter[INDEX_OF_ACCESS].equalsIgnoreCase("in"))||(parameter[INDEX_OF_ACCESS].equalsIgnoreCase("R"))) {

                parameter[INDEX_OF_INVALID_DOMAIN] = Insert_Invalide_Manipulation(row, parameter);


                return 1; // one line added

                //}else if ((parameter[INDEX_OF_ACCESS].equalsIgnoreCase("in/out"))||(parameter[INDEX_OF_ACCESS].equalsIgnoreCase("R/W"))){
            }else {

                parameter[INDEX_OF_INVALID_DOMAIN]=Insert_Invalide_Manipulation(row, parameter);

                for (int i = 6; i <= 8; i++)
                       MergeRows(SHEET_B1_INDEX, i, row+1, row +2);

                return 2; // two line added

            }

    }
    public static int Insert_Row(int row, String[] parameter,boolean stubParameter){

        int return_Number_Of_Rows=1;


        if ((parameter[INDEX_OF_ACCESS].equalsIgnoreCase("in"))||(parameter[INDEX_OF_ACCESS].equals("R"))||(Objects.equals(parameter[INDEX_OF_TYPE], "void"))){

            //parameter=Classes_Filling(parameter);
            Insert_Manipulation(row,parameter);
        }
        else{

            Insert_Manipulation(row,parameter);
            for (int i = 1; i <=8 ; i++)
            {
                boolean bool=((parameter[INDEX_OF_ACCESS].contains("W"))||(parameter[INDEX_OF_ACCESS].contains("Out"))||(parameter[INDEX_OF_ACCESS].equals("_in")))&&(!(parameter[INDEX_OF_ACCESS].contains("/")));
                // Check if variable
                if((Objects.equals(parameter[INDEX_OF_INVALID_DOMAIN], "-"))||(i>5)||(bool))
                    if ((i==4 || i==5 ) && stubParameter )
                    continue;

                    MergeRows(SHEET_B1_INDEX,i,row+1,row+2);
            }
            return_Number_Of_Rows++;
        }

        return return_Number_Of_Rows;


    }




    public static String Insert_Invalide_Manipulation(int row,final String[] parameter){

        String firstInterval=parameter[INDEX_OF_INVALID_DOMAIN],secondInterval=parameter[INDEX_OF_INVALID_DOMAIN];

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

    public static void Insert_Manipulation(int row, String[] parameter){
        for (int i = 1; i <= 8; i++) {
            if((i==4)||(i==5)||(i==7)){
                continue; }

            if (i==1) {
                if ((parameter[INDEX_OF_NAME].contains("["))&&(parameter[INDEX_OF_NAME].contains("]"))) {
                    Fill_Cell(parameter[INDEX_OF_NAME].replace("[", "[0..").replace("]", "-1]"), SHEET_B1_INDEX, row, i); // array manipulation
                    if (!parameter[INDEX_OF_TYPE].equals("not exist in the DD"))
                    parameter[INDEX_OF_TYPE]=parameter[INDEX_OF_TYPE].replace("Array of","")+"[ARRAY]";
                }else
                    Fill_Cell(parameter[i], SHEET_B1_INDEX,row,i);
            }else
                Fill_Cell(parameter[i], SHEET_B1_INDEX,row,i);
        }
    }

}
