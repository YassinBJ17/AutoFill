package SUTC.file.B1_Sheet.COMMUN;

import SUTC.file.B1_Sheet.B1_ExcelSheet;
import SUTC.file.SutcCreationProccess;
import SUTC.file.COMMUN.ExcelModifier;
import java.util.Objects;
import static SUTC.file.B1_Sheet.Classes.ClassFilling.Classes_Filling;
import static SUTC.file.B1_Sheet.COMMUN.ExtractData.Access_Detect;
import static COMMUN.LoggerInitialize.*;
import static SUTC.file.COMMUN.ExcelRowsAndColsConstants.*;


public class InsertData {

    public static int Insert_Parameter(int row,int Parameter_number,String[] LLR){

        if(LLR!=null)
            B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_ACCESS]= Access_Detect(LLR, B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_NAME]);
        if(row<= B1_ExcelSheet.INTERNAL_VARIABLES_POSITION+ SutcCreationProccess.number_of_UFT-2)
            B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_ACCESS] = B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_ACCESS].replace("R", "In").replace("W", "Out");


        if (((B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_ACCESS].contains("W"))||(B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_ACCESS].contains("Out")))&&(!(B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_ACCESS].contains("/"))))
            B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_CLASS]="-";


        row+=Insert_Row(row, B1_ExcelSheet.Parameters[Parameter_number]);

        if (((B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_ACCESS].contains("R"))||(B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_ACCESS].contains("In")))&&(!(B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_INVALID_DOMAIN].equals("-")))){
            row++;
            row+=Insert_Invalid_Row(row, B1_ExcelSheet.Parameters[Parameter_number]);
        }
        return ++row;
    }
    public static int Insert_Invalid_Row(int row, final String[] parameter){


        try {
            if ((parameter[INDEX_OF_ACCESS].equalsIgnoreCase("in"))||(parameter[INDEX_OF_ACCESS].equals("R"))){

                for (int i = 6; i <= 8; i++) {
                    if (i == 7)
                        ExcelModifier.Fill_Cell("I", SHEET_B1, row, i);
                    else {
                        ExcelModifier.Fill_Cell(parameter[7], SHEET_B1, row, i);
                    }
                }

                for (int i = 1; i <= 5; i++)
                    ExcelModifier.Merge_Cells(SHEET_B1, i, row,row+1);
                return 0;


            }else{


                for (int i = 6; i <= 8; i++) {
                    if (i == 7)
                        ExcelModifier.Fill_Cell("I", SHEET_B1, row, i);
                    else {
                        ExcelModifier.Fill_Cell(parameter[7], SHEET_B1, row, i);
                    }
                }


                for (int i = 1; i <= 5; i++)
                    ExcelModifier.Merge_Cells(SHEET_B1, i, row-1, row +2);


                for (int i = 6; i <= 8; i++)
                    ExcelModifier.Merge_Cells(SHEET_B1, i, row+1, row + 2);


                return 1;

            }
        }catch (Exception e)
        {
            String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
log4Error(methodName+" : "+e.getMessage() );
        }
        return 0;
    }
    public static int Insert_Row(int row, String[] parameter){

        int retrun_Number_Of_Rows=0;


        if ((parameter[INDEX_OF_ACCESS].equalsIgnoreCase("in"))||(parameter[INDEX_OF_ACCESS].equals("R"))||(Objects.equals(parameter[INDEX_OF_TYPE], "void"))){

            parameter=Classes_Filling(parameter);

            for (int i = 1; i <= 8; i++) {
                if((i==4)||(i==5)||(i==7)){
                    continue; }

                if (i==1) {
                    if ((parameter[INDEX_OF_NAME].contains("["))&&(parameter[INDEX_OF_NAME].contains("]"))) {
                        ExcelModifier.Fill_Cell(parameter[INDEX_OF_NAME].replace("[", "[0..").replace("]", "-1]"), SHEET_B1, row, i); // array manipulation
                        parameter[INDEX_OF_TYPE]=parameter[INDEX_OF_TYPE]+"[ARRAY]";
                    }else
                        ExcelModifier.Fill_Cell(parameter[i], SHEET_B1,row,i);
                }else
                    ExcelModifier.Fill_Cell(parameter[i], SHEET_B1,row,i);
            }



        }
        else{

            for (int i = 1; i <= 8; i++) {

                if((i==4)||(i==5)||(i==7)){
                    continue;}
                if (i==1) {
                    if ((parameter[INDEX_OF_NAME].contains("["))&&(parameter[INDEX_OF_NAME].contains("]")))
                        ExcelModifier.Fill_Cell(parameter[INDEX_OF_NAME].replace("[","[0..").replace("]","-1]"), SHEET_B1,row,i); // array manipulation
                    else
                        ExcelModifier.Fill_Cell(parameter[i], SHEET_B1,row,i);

                }else
                    ExcelModifier.Fill_Cell(parameter[i], SHEET_B1,row,i);
            }

            for (int i = 1; i <=8 ; i++)
            {
                boolean bool=((parameter[INDEX_OF_ACCESS].contains("W"))||(parameter[INDEX_OF_ACCESS].contains("Out"))||(parameter[INDEX_OF_ACCESS].equals("_in")))&&(!(parameter[INDEX_OF_ACCESS].contains("/")));
                if((Objects.equals(parameter[INDEX_OF_INVALID_DOMAIN], "-"))||(i>5)||(bool))

                    ExcelModifier.Merge_Cells(SHEET_B1,i,row+1,row+2);
            }
            retrun_Number_Of_Rows++;
        }

        return retrun_Number_Of_Rows;


    }
}
