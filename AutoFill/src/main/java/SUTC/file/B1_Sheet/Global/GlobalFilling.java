package SUTC.file.B1_Sheet.Global;
import SUTC.file.B1_Sheet.B1_ExcelSheet;
import SUTC.file.SutcCreationProccess;
import SUTC.file.COMMUN.ExcelModifier;
import static SUTC.file.COMMUN.ExcelRowsAndColsConstants.*;
import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.ss.usermodel.Sheet;
import java.util.Objects;

import static SUTC.file.B1_Sheet.DataDictionarySearch.DataDictionarySearch.DataDictionarySearch;
import static SUTC.file.B1_Sheet.COMMUN.ExtractData.Extract_Domain;
import static SUTC.file.B1_Sheet.COMMUN.ExtractData.Extract_Invalid_Domain;
import static SUTC.file.B1_Sheet.COMMUN.InsertData.Insert_Invalid_Row;
import static SUTC.file.B1_Sheet.COMMUN.InsertData.Insert_Row;
import static COMMUN.GraphicUserInterfaces.Error_interface;
import static COMMUN.LoggerInitialize.*;


public class GlobalFilling {

    public static void  Global_Parameters_Filling(String[] LLR) {
        int numberOfGlobals=Extract_Global(LLR);
        try {
            for (int i = 0; i < numberOfGlobals; i++) {

                if (B1_ExcelSheet.Globals[i].contains("{"))
                    B1_ExcelSheet.Parameters[i][INDEX_OF_NAME]= B1_ExcelSheet.Globals[i].substring(B1_ExcelSheet.Globals[i].indexOf("{")+1, B1_ExcelSheet.Globals[i].indexOf("}")) ;
                else B1_ExcelSheet.Parameters[i][INDEX_OF_NAME]= B1_ExcelSheet.Globals[i].substring(0, B1_ExcelSheet.Globals[i].indexOf(" ")) ;



                B1_ExcelSheet.Parameters[i][INDEX_OF_TYPE]= DataDictionarySearch(B1_ExcelSheet.Parameters[i][INDEX_OF_NAME],true) ;
                B1_ExcelSheet.Parameters[i][INDEX_OF_DOMAIN]=(Extract_Domain(B1_ExcelSheet.Parameters[i][INDEX_OF_TYPE]))[0];
                B1_ExcelSheet.Parameters[i][INDEX_OF_CLASS]=(Extract_Domain(B1_ExcelSheet.Parameters[i][INDEX_OF_TYPE]))[0];
                B1_ExcelSheet.Parameters[i][INDEX_OF_INVALID_DOMAIN]=(Extract_Domain(B1_ExcelSheet.Parameters[i][INDEX_OF_TYPE]))[1];

                if(B1_ExcelSheet.Parameters[i][INDEX_OF_DOMAIN].equals("-")) {
                    B1_ExcelSheet.Parameters[i][INDEX_OF_DOMAIN] = DataDictionarySearch(B1_ExcelSheet.Parameters[i][INDEX_OF_TYPE], false);
                    B1_ExcelSheet.Parameters[i][INDEX_OF_CLASS] = DataDictionarySearch(B1_ExcelSheet.Parameters[i][INDEX_OF_TYPE], false);
                    B1_ExcelSheet.Parameters[i][INDEX_OF_INVALID_DOMAIN]=Extract_Invalid_Domain(B1_ExcelSheet.Parameters[i][INDEX_OF_DOMAIN]);
                }

                B1_ExcelSheet.Global_Start+=Insert_Global_Parameter(B1_ExcelSheet.Global_Start+i+ SutcCreationProccess.number_of_UFT,i,LLR);
            }
        }catch (Exception e){
            Error_interface(String.valueOf(e));
            String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
logError(methodName+" : "+e.getMessage() );
        }
    }
    public static int Extract_Global(String [] LLR){

        int numberOfGlobals=0;

        for (int i = 0; i < LLR.length; i++) {

            if (ExcelModifier.Search(Global_start,LLR[i].trim())){
                int j=i+1;
                while (!ExcelModifier.Search(Global_end,LLR[j].trim())){

                    if((LLR[j].trim().equalsIgnoreCase("None"))||(LLR[j].trim().equalsIgnoreCase("None.")))break;

                    if((!(LLR[j].trim().isEmpty()))&&(!(ExcelModifier.Search(B1_ExcelSheet.Globals, LLR[j])))){
                        B1_ExcelSheet.Globals[numberOfGlobals]=LLR[j].trim();
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

        Sheet A2_sheet= SutcCreationProccess.workbook.getSheetAt(SHEET_A2);

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
    public static int Insert_Global_Parameter(int row,int Parameter_number,String[] LLR) {


        B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_ACCESS]= Access_Global_Detect(LLR, B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_NAME]);
        B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_NAME]= B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_NAME].replace(":","");

        if ((B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_ACCESS].contains("W"))&&(!(B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_ACCESS].contains("/")))){
            B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_CLASS]="-";
        }

        int return_Number_Of_Rows=Insert_Row(row, B1_ExcelSheet.Parameters[Parameter_number]);
        row=row+return_Number_Of_Rows;

        if (((B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_ACCESS].contains("R")))&&(!(B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_INVALID_DOMAIN].equals("-")))){
            row++;
            Insert_Invalid_Row(row, B1_ExcelSheet.Parameters[Parameter_number]);
        }


        // A2 filling
        ExcelModifier.Fill_Cell("Variable", SHEET_A2, B1_ExcelSheet.INTERNAL_DEFINITIONS_POSITION+ SutcCreationProccess.number_of_UFT+Parameter_number, CELL_COL_1);
        if (B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_NAME].contains(".")|| B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_NAME].contains("->")) {
            int index;
            index= B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_NAME].indexOf("->");

            if (index==-1)
                index= B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_NAME].indexOf(".");

            B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_NAME] = B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_NAME].substring(0,index);
        }
        if (!InternalDefinitionsExist(B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_NAME])) {
            ExcelModifier.Fill_Cell(B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_NAME], SHEET_A2, B1_ExcelSheet.INTERNAL_DEFINITIONS_POSITION + SutcCreationProccess.number_of_UFT + Parameter_number, CELL_COL_2);
            ExcelModifier.Fill_Cell(B1_ExcelSheet.Parameters[Parameter_number][INDEX_OF_TYPE], SHEET_A2, B1_ExcelSheet.INTERNAL_DEFINITIONS_POSITION + SutcCreationProccess.number_of_UFT + Parameter_number, CELL_COL_3);
        }

        return return_Number_Of_Rows;
    }


}
