package SUTC.file.B1_Sheet.FunctionReturnFilling;

import SUTC.file.B1_Sheet.B1_ExcelSheet;
import SUTC.file.B1_Sheet.DataDictionarySearch.DataDictionarySearch;
import SUTC.file.COMMUN.ExcelModifier;
import static SUTC.file.COMMUN.ExcelRowsAndColsConstants.*;
import java.io.IOException;

import static SUTC.file.B1_Sheet.COMMUN.ExtractData.Extract_Domain;
import static SUTC.file.B1_Sheet.COMMUN.ExtractData.Extract_Invalid_Domain;
import static SUTC.file.B1_Sheet.COMMUN.InsertData.Insert_Parameter;

public class FunctionRetrunFilling {

    public static void Function_Return_Filling(String[] Code, String function_name) throws IOException {

        String prototype;
        String type;
        for (String cLine : Code) {

            if (ExcelModifier.Prototype_Detect(cLine, function_name)) {

                prototype = cLine;


                if (!(prototype.contains("void "))) {


                    type = prototype.substring(0, prototype.indexOf(function_name) - 1);

                    B1_ExcelSheet.Parameters[0][INDEX_OF_NAME]="RTRT_Ret";
                    B1_ExcelSheet.Parameters[0][INDEX_OF_TYPE]=type;
                    B1_ExcelSheet.Parameters[0][INDEX_OF_ACCESS]="W";
                    B1_ExcelSheet.Parameters[0][INDEX_OF_DOMAIN]=(Extract_Domain(B1_ExcelSheet.Parameters[0][INDEX_OF_TYPE]))[0];
                    B1_ExcelSheet.Parameters[0][INDEX_OF_CLASS]=(Extract_Domain(B1_ExcelSheet.Parameters[0][INDEX_OF_TYPE]))[0];
                    B1_ExcelSheet.Parameters[0][INDEX_OF_INVALID_DOMAIN]=(Extract_Domain(B1_ExcelSheet.Parameters[0][INDEX_OF_TYPE]))[1];

                    if(B1_ExcelSheet.Parameters[0][INDEX_OF_DOMAIN].equals("-"))
                    {
                        B1_ExcelSheet.Parameters[0][INDEX_OF_DOMAIN]= DataDictionarySearch.DataDictionarySearch(B1_ExcelSheet.Parameters[0][INDEX_OF_TYPE],false);
                        B1_ExcelSheet.Parameters[0][INDEX_OF_CLASS]= DataDictionarySearch.DataDictionarySearch(B1_ExcelSheet.Parameters[0][INDEX_OF_TYPE],false);
                        B1_ExcelSheet.Parameters[0][INDEX_OF_INVALID_DOMAIN]= Extract_Invalid_Domain(B1_ExcelSheet.Parameters[0][INDEX_OF_DOMAIN]);
                    }

                    Insert_Parameter(B1_ExcelSheet.RETURN_FUNCTION_INDEX,0,null);
                    B1_ExcelSheet.Prototype="RTRT_ret="+ B1_ExcelSheet.Prototype;

                }

                break;
            }
        }

    }
}
