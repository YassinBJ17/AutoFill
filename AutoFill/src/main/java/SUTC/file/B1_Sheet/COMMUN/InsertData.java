package SUTC.file.B1_Sheet.COMMUN;
import SUTC.file.B1_Sheet.B1_ExcelSheet;
import SUTC.file.SutcCreationProccess;
import SUTC.file.COMMUN.ExcelModifier;
import java.util.Objects;
import static SUTC.file.B1_Sheet.B1_ExcelSheet.INTERNAL_VARIABLES_POSITION;
import static SUTC.file.B1_Sheet.B1_ExcelSheet.Parameters;
import static SUTC.file.B1_Sheet.Classes.ClassFilling.Classes_Filling;
import static SUTC.file.B1_Sheet.COMMUN.ExtractData.Access_Detect;
import static COMMUN.LoggerInitialize.*;
import static SUTC.file.COMMUN.ExcelModifier.Fill_Cell;
import static SUTC.file.COMMUN.ExcelModifier.Merge_Cells;
import static SUTC.file.COMMUN.ExcelRowsAndColsConstants.*;
import static SUTC.file.SutcCreationProccess.number_of_UFT;


public class InsertData {

    public static int Insert_Parameter(int row,int Parameter_number,String[] LLR){

        if(LLR!=null)
            Parameters[Parameter_number][INDEX_OF_ACCESS]= Access_Detect(Parameter_number);
        if(row<= INTERNAL_VARIABLES_POSITION-2)
            Parameters[Parameter_number][INDEX_OF_ACCESS] = Parameters[Parameter_number][INDEX_OF_ACCESS].replace("R", "In").replace("W", "Out");


        if (((Parameters[Parameter_number][INDEX_OF_ACCESS].contains("W"))||(Parameters[Parameter_number][INDEX_OF_ACCESS].contains("Out")))&&(!(Parameters[Parameter_number][INDEX_OF_ACCESS].contains("/"))))
            Parameters[Parameter_number][INDEX_OF_CLASS]="-";

        if (((Parameters[Parameter_number][INDEX_OF_ACCESS].contains("R"))||(Parameters[Parameter_number][INDEX_OF_ACCESS].contains("In")))&&(!(Parameters[Parameter_number][INDEX_OF_INVALID_DOMAIN].equals("-")))){
            row+=Insert_Invalid_Row(row, Parameters[Parameter_number]);
            row+=Insert_Row(row, Parameters[Parameter_number]);
            row+=Insert_Invalid_Row(row, Parameters[Parameter_number]);
        }else {
            row += Insert_Row(row, Parameters[Parameter_number]);
        }
        return ++row;
    }
    public static int Insert_Invalid_Row(int row, String[] parameter){

        try {

            Insert_Manipulation(row,parameter);


            if ((parameter[INDEX_OF_ACCESS].equalsIgnoreCase("in"))||(parameter[INDEX_OF_ACCESS].equalsIgnoreCase("R"))) {

                parameter[INDEX_OF_INVALID_DOMAIN] = Insert_Invalide_Manipulation(row, parameter);


                return 1; // one line added

                //}else if ((parameter[INDEX_OF_ACCESS].equalsIgnoreCase("in/out"))||(parameter[INDEX_OF_ACCESS].equalsIgnoreCase("R/W"))){
            }else {

                parameter[INDEX_OF_INVALID_DOMAIN]=Insert_Invalide_Manipulation(row, parameter);

               for (int i = 6; i <= 8; i++)
                    Merge_Cells(SHEET_B1, i, row+1, row +2);

                return 2; // two line added

            }
        }catch (Exception e)
        {
            String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
            log4Error(methodName+" : "+e.getMessage() );
        }
        return 0;
    }
    public static int Insert_Row(int row, String[] parameter){

        int return_Number_Of_Rows=0;


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

                    Merge_Cells(SHEET_B1,i,row+1,row+2);
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
            Fill_Cell("I", SHEET_B1, row, i);
        else {
            Fill_Cell(firstInterval, SHEET_B1, row, i);
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
                    Fill_Cell(parameter[INDEX_OF_NAME].replace("[", "[0..").replace("]", "-1]"), SHEET_B1, row, i); // array manipulation
                    parameter[INDEX_OF_TYPE]=parameter[INDEX_OF_TYPE]+"[ARRAY]";
                }else
                    Fill_Cell(parameter[i], SHEET_B1,row,i);
            }else
                Fill_Cell(parameter[i], SHEET_B1,row,i);
        }
    }

}
