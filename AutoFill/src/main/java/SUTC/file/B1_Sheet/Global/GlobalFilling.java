package SUTC.file.B1_Sheet.Global;
import SUTC.file.B1_Sheet.B1_ExcelSheet;
import SUTC.file.SutcCreationProccess;
import SUTC.file.COMMUN.ExcelModifier;

import static SUTC.file.B1_Sheet.B1_ExcelSheet.INTERNAL_DEFINITIONS_POSITION;
import static SUTC.file.B1_Sheet.B1_ExcelSheet.Parameters;
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
import static SUTC.file.SutcCreationProccess.number_of_UFT;


public class GlobalFilling {

    public static void  Global_Parameters_Filling(String[] LLR) {
        int numberOfGlobals=Extract_Global(LLR);
        try {
            for (int i = 0; i < numberOfGlobals; i++) {

                if (B1_ExcelSheet.Globals[i].contains("{"))
                    Parameters[i][INDEX_OF_NAME]= B1_ExcelSheet.Globals[i].substring(B1_ExcelSheet.Globals[i].indexOf("{")+1, B1_ExcelSheet.Globals[i].indexOf("}")) ;
                else Parameters[i][INDEX_OF_NAME]= B1_ExcelSheet.Globals[i].substring(0, B1_ExcelSheet.Globals[i].indexOf(" ")) ;



                Parameters[i][INDEX_OF_TYPE]= DataDictionarySearch(Parameters[i][INDEX_OF_NAME],true) ;
                Parameters[i][INDEX_OF_DOMAIN]=(Extract_Domain(Parameters[i][INDEX_OF_TYPE]))[0];
                Parameters[i][INDEX_OF_CLASS]=(Extract_Domain(Parameters[i][INDEX_OF_TYPE]))[0];
                Parameters[i][INDEX_OF_INVALID_DOMAIN]=(Extract_Domain(Parameters[i][INDEX_OF_TYPE]))[1];

                if(Parameters[i][INDEX_OF_DOMAIN].equals("-")) {
                    Parameters[i][INDEX_OF_DOMAIN] = DataDictionarySearch(Parameters[i][INDEX_OF_TYPE], false);
                    Parameters[i][INDEX_OF_CLASS] = DataDictionarySearch(Parameters[i][INDEX_OF_TYPE], false);
                    Parameters[i][INDEX_OF_INVALID_DOMAIN]=Extract_Invalid_Domain(Parameters[i][INDEX_OF_DOMAIN]);
                }

                B1_ExcelSheet.Global_Start+=Insert_Global_Parameter(B1_ExcelSheet.Global_Start+i+ number_of_UFT,i,LLR);
            }
        }catch (Exception e){
            Error_interface(String.valueOf(e));
            String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
log4Error(methodName+" : "+e.getMessage() );
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


        Parameters[Parameter_number][INDEX_OF_ACCESS]= Access_Global_Detect(LLR, Parameters[Parameter_number][INDEX_OF_NAME]);
        Parameters[Parameter_number][INDEX_OF_NAME]= Parameters[Parameter_number][INDEX_OF_NAME].replace(":","");

        if ((Parameters[Parameter_number][INDEX_OF_ACCESS].contains("W"))&&(!(Parameters[Parameter_number][INDEX_OF_ACCESS].contains("/")))){
            Parameters[Parameter_number][INDEX_OF_CLASS]="-";
        }

        int return_Number_Of_Rows=Insert_Row(row, Parameters[Parameter_number]);
        row=row+return_Number_Of_Rows;

        if (((Parameters[Parameter_number][INDEX_OF_ACCESS].contains("R")))&&(!(Parameters[Parameter_number][INDEX_OF_INVALID_DOMAIN].equals("-")))){
            row++;
            Insert_Invalid_Row(row, Parameters[Parameter_number]);
        }


        // A2 filling
        ExcelModifier.Fill_Cell("Variable", SHEET_A2, INTERNAL_DEFINITIONS_POSITION+Parameter_number, CELL_COL_1);
        if (Parameters[Parameter_number][INDEX_OF_NAME].contains(".")|| Parameters[Parameter_number][INDEX_OF_NAME].contains("->")) {
            int index;
            index= Parameters[Parameter_number][INDEX_OF_NAME].indexOf("->");

            if (index==-1)
                index= Parameters[Parameter_number][INDEX_OF_NAME].indexOf(".");

            Parameters[Parameter_number][INDEX_OF_NAME] = Parameters[Parameter_number][INDEX_OF_NAME].substring(0,index);
        }
        if (!InternalDefinitionsExist(Parameters[Parameter_number][INDEX_OF_NAME])) {
            ExcelModifier.Fill_Cell(Parameters[Parameter_number][INDEX_OF_NAME], SHEET_A2, INTERNAL_DEFINITIONS_POSITION +  Parameter_number, CELL_COL_2);
            ExcelModifier.Fill_Cell(Parameters[Parameter_number][INDEX_OF_TYPE], SHEET_A2, INTERNAL_DEFINITIONS_POSITION +  Parameter_number, CELL_COL_3);
        }

        return return_Number_Of_Rows;
    }


}
