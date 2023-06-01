package excel.file.B1_Sheet.Global;
import excel.file.Services.Excel;
import excel.file.Services.ExcelModifier;
import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.ss.usermodel.Sheet;
import java.util.Objects;
import static excel.file.B1_Sheet.B1_ExcelSheet.*;
import static excel.file.B1_Sheet.DataDictionarySearch.DataDictionarySearch.DataDictionarySearch;
import static excel.file.B1_Sheet.Services.ExtractData.Extract_Domain;
import static excel.file.B1_Sheet.Services.ExtractData.Extract_Invalid_Domain;
import static excel.file.B1_Sheet.Services.InsertData.Insert_Invalid_Row;
import static excel.file.B1_Sheet.Services.InsertData.Insert_Row;
import static excel.file.Services.ExcelFinal.number_of_UFT;
import static excel.file.Services.ExcelFinal.workbook;
import static services.GUInterfaces.Error_interface;
import static services.Logger_init.logger4j;


public class GlobalFilling {

    public static void  Global_Parameters_Filling(String[] LLR) {
        int numberOfGlobals=Extract_Global(LLR);
        try {
            for (int i = 0; i < numberOfGlobals; i++) {

                if (Globals[i].contains("{"))
                    Parameters[i][Excel.INDEX_OF_NAME]=Globals[i].substring(Globals[i].indexOf("{")+1,Globals[i].indexOf("}")) ;
                else Parameters[i][Excel.INDEX_OF_NAME]=Globals[i].substring(0,Globals[i].indexOf(" ")) ;



                Parameters[i][Excel.INDEX_OF_TYPE]= DataDictionarySearch(Parameters[i][Excel.INDEX_OF_NAME],true) ;
                Parameters[i][Excel.INDEX_OF_DOMAIN]=(Extract_Domain(Parameters[i][Excel.INDEX_OF_TYPE]))[0];
                Parameters[i][Excel.INDEX_OF_CLASS]=(Extract_Domain(Parameters[i][Excel.INDEX_OF_TYPE]))[0];
                Parameters[i][Excel.INDEX_OF_INVALID_DOMAIN]=(Extract_Domain(Parameters[i][Excel.INDEX_OF_TYPE]))[1];

                if(Parameters[i][Excel.INDEX_OF_DOMAIN].equals("-")) {
                    Parameters[i][Excel.INDEX_OF_DOMAIN] = DataDictionarySearch(Parameters[i][Excel.INDEX_OF_TYPE], false);
                    Parameters[i][Excel.INDEX_OF_CLASS] = DataDictionarySearch(Parameters[i][Excel.INDEX_OF_TYPE], false);
                    Parameters[i][Excel.INDEX_OF_INVALID_DOMAIN]=Extract_Invalid_Domain(Parameters[i][Excel.INDEX_OF_DOMAIN]);
                }

                Global_Start+=Insert_Global_Parameter(Global_Start+i+number_of_UFT,i,LLR);
            }
        }catch (Exception e){
            Error_interface(String.valueOf(e));
            logger4j.error(e);
        }
    }
    public static int Extract_Global(String [] LLR){

        int numberOfGlobals=0;

        for (int i = 0; i < LLR.length; i++) {

            if (ExcelModifier.Search(Excel.Global_start,LLR[i].trim())){
                int j=i+1;
                while (!ExcelModifier.Search(Excel.Global_end,LLR[j].trim())){

                    if((LLR[j].trim().equalsIgnoreCase("None"))||(LLR[j].trim().equalsIgnoreCase("None.")))break;

                    if((!(LLR[j].trim().isEmpty()))&&(!(ExcelModifier.Search(Globals, LLR[j])))){
                        Globals[numberOfGlobals]=LLR[j].trim();
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

        Sheet A2_sheet= workbook.getSheetAt(Excel.SHEET_A2);

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


        Parameters[Parameter_number][Excel.INDEX_OF_ACCESS]= Access_Global_Detect(LLR,Parameters[Parameter_number][Excel.INDEX_OF_NAME]);
        Parameters[Parameter_number][Excel.INDEX_OF_NAME]=Parameters[Parameter_number][Excel.INDEX_OF_NAME].replace(":","");

        if ((Parameters[Parameter_number][Excel.INDEX_OF_ACCESS].contains("W"))&&(!(Parameters[Parameter_number][Excel.INDEX_OF_ACCESS].contains("/")))){
            Parameters[Parameter_number][Excel.INDEX_OF_CLASS]="-";
        }

        int return_Number_Of_Rows=Insert_Row(row,Parameters[Parameter_number]);
        row=row+return_Number_Of_Rows;

        if (((Parameters[Parameter_number][Excel.INDEX_OF_ACCESS].contains("R")))&&(!(Parameters[Parameter_number][Excel.INDEX_OF_INVALID_DOMAIN].equals("-")))){
            row++;
            Insert_Invalid_Row(row,Parameters[Parameter_number]);
        }


        // A2 filling
        ExcelModifier.Fill_Cell("Variable",Excel.SHEET_A2,INTERNAL_DEFINITIONS_POSITION+number_of_UFT+Parameter_number,Excel.CELL_COL_1);
        if (Parameters[Parameter_number][Excel.INDEX_OF_NAME].contains(".")||Parameters[Parameter_number][Excel.INDEX_OF_NAME].contains("->")) {
            int index;
            index=Parameters[Parameter_number][Excel.INDEX_OF_NAME].indexOf("->");

            if (index==-1)
                index=Parameters[Parameter_number][Excel.INDEX_OF_NAME].indexOf(".");

            Parameters[Parameter_number][Excel.INDEX_OF_NAME] = Parameters[Parameter_number][Excel.INDEX_OF_NAME].substring(0,index);
        }
        if (!InternalDefinitionsExist(Parameters[Parameter_number][Excel.INDEX_OF_NAME])) {
            ExcelModifier.Fill_Cell(Parameters[Parameter_number][Excel.INDEX_OF_NAME], Excel.SHEET_A2, INTERNAL_DEFINITIONS_POSITION + number_of_UFT + Parameter_number, Excel.CELL_COL_2);
            ExcelModifier.Fill_Cell(Parameters[Parameter_number][Excel.INDEX_OF_TYPE], Excel.SHEET_A2, INTERNAL_DEFINITIONS_POSITION + number_of_UFT + Parameter_number, Excel.CELL_COL_3);
        }

        return return_Number_Of_Rows;
    }


}
