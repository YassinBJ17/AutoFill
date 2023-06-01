package excel.file.B1_Sheet.Services;

import excel.file.Services.Excel;
import excel.file.Services.ExcelModifier;

import java.util.Objects;

import static excel.file.B1_Sheet.B1_ExcelSheet.INTERNAL_VARIABLES_POSITION;
import static excel.file.B1_Sheet.B1_ExcelSheet.Parameters;
import static excel.file.B1_Sheet.Classes.ClassFilling.Classes_Filling;
import static excel.file.B1_Sheet.Services.ExtractData.Access_Detect;
import static excel.file.Services.ExcelFinal.number_of_UFT;

public class InsertData {


    public static int Insert_Parameter(int row,int Parameter_number,String[] LLR){

        if(LLR!=null)
            Parameters[Parameter_number][Excel.INDEX_OF_ACCESS]= Access_Detect(LLR,Parameters[Parameter_number][Excel.INDEX_OF_NAME]);
        if(row<=INTERNAL_VARIABLES_POSITION+number_of_UFT-2)
            Parameters[Parameter_number][Excel.INDEX_OF_ACCESS] = Parameters[Parameter_number][Excel.INDEX_OF_ACCESS].replace("R", "In").replace("W", "Out");


        if (((Parameters[Parameter_number][Excel.INDEX_OF_ACCESS].contains("W"))||(Parameters[Parameter_number][Excel.INDEX_OF_ACCESS].contains("Out")))&&(!(Parameters[Parameter_number][Excel.INDEX_OF_ACCESS].contains("/"))))
            Parameters[Parameter_number][Excel.INDEX_OF_CLASS]="-";


        row+=Insert_Row(row,Parameters[Parameter_number]);

        if (((Parameters[Parameter_number][Excel.INDEX_OF_ACCESS].contains("R"))||(Parameters[Parameter_number][Excel.INDEX_OF_ACCESS].contains("In")))&&(!(Parameters[Parameter_number][Excel.INDEX_OF_INVALID_DOMAIN].equals("-")))){
            row++;
            row+=Insert_Invalid_Row(row,Parameters[Parameter_number]);
        }
        return ++row;
    }
    public static int Insert_Invalid_Row(int row, final String[] parameter){


        try {
            if ((parameter[Excel.INDEX_OF_ACCESS].equalsIgnoreCase("in"))||(parameter[Excel.INDEX_OF_ACCESS].equals("R"))){

                for (int i = 6; i <= 8; i++) {
                    if (i == 7)
                        ExcelModifier.Fill_Cell("I", Excel.SHEET_B1, row, i);
                    else {
                        ExcelModifier.Fill_Cell(parameter[7], Excel.SHEET_B1, row, i);
                    }
                }

                for (int i = 1; i <= 5; i++)
                    ExcelModifier.Merge_Cells(Excel.SHEET_B1, i, row,row+1);
                return 0;


            }else{


                for (int i = 6; i <= 8; i++) {
                    if (i == 7)
                        ExcelModifier.Fill_Cell("I", Excel.SHEET_B1, row, i);
                    else {
                        ExcelModifier.Fill_Cell(parameter[7], Excel.SHEET_B1, row, i);
                    }
                }


                for (int i = 1; i <= 5; i++)
                    ExcelModifier.Merge_Cells(Excel.SHEET_B1, i, row-1, row +2);


                for (int i = 6; i <= 8; i++)
                    ExcelModifier.Merge_Cells(Excel.SHEET_B1, i, row+1, row + 2);


                return 1;

            }
        }catch (Exception e)
        {
            e.printStackTrace();
        }
        return 0;
    }
    public static int Insert_Row(int row, String[] parameter){

        int retrun_Number_Of_Rows=0;


        if ((parameter[Excel.INDEX_OF_ACCESS].equalsIgnoreCase("in"))||(parameter[Excel.INDEX_OF_ACCESS].equals("R"))||(Objects.equals(parameter[Excel.INDEX_OF_TYPE], "void"))){

            parameter=Classes_Filling(parameter);

            for (int i = 1; i <= 8; i++) {
                if((i==4)||(i==5)||(i==7)){
                    continue; }

                if (i==1) {
                    if ((parameter[Excel.INDEX_OF_NAME].contains("["))&&(parameter[Excel.INDEX_OF_NAME].contains("]")))
                        ExcelModifier.Fill_Cell(parameter[Excel.INDEX_OF_NAME].replace("[","[0..").replace("]","-1]"),Excel.SHEET_B1,row,i); // array manipulation
                    else
                        ExcelModifier.Fill_Cell(parameter[i],Excel.SHEET_B1,row,i);
                }else
                    ExcelModifier.Fill_Cell(parameter[i],Excel.SHEET_B1,row,i);
            }



        }
        else{

            for (int i = 1; i <= 8; i++) {

                if((i==4)||(i==5)||(i==7)){
                    continue;}
                if (i==1) {
                    if ((parameter[Excel.INDEX_OF_NAME].contains("["))&&(parameter[Excel.INDEX_OF_NAME].contains("]")))
                        ExcelModifier.Fill_Cell(parameter[Excel.INDEX_OF_NAME].replace("[","[0..").replace("]","-1]"),Excel.SHEET_B1,row,i); // array manipulation
                    else
                        ExcelModifier.Fill_Cell(parameter[i],Excel.SHEET_B1,row,i);

                }else
                    ExcelModifier.Fill_Cell(parameter[i],Excel.SHEET_B1,row,i);
            }

            for (int i = 1; i <=8 ; i++)
            {
                boolean bool=((parameter[Excel.INDEX_OF_ACCESS].contains("W"))||(parameter[Excel.INDEX_OF_ACCESS].contains("Out"))||(parameter[Excel.INDEX_OF_ACCESS].equals("_in")))&&(!(parameter[Excel.INDEX_OF_ACCESS].contains("/")));
                if((parameter[Excel.INDEX_OF_INVALID_DOMAIN]=="-")||(i>5)||(bool))

                    ExcelModifier.Merge_Cells(Excel.SHEET_B1,i,row+1,row+2);
            }
            retrun_Number_Of_Rows++;
        }

        return retrun_Number_Of_Rows;


    }
}
