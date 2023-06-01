package excel.file.B1_Sheet.FunctionReturnFilling;

import excel.file.Services.Excel;
import java.io.IOException;

import static excel.file.B1_Sheet.B1_ExcelSheet.*;
import static excel.file.B1_Sheet.DataDictionarySearch.DataDictionarySearch.DataDictionarySearch;
import static excel.file.B1_Sheet.Services.ExtractData.Extract_Domain;
import static excel.file.B1_Sheet.Services.ExtractData.Extract_Invalid_Domain;
import static excel.file.B1_Sheet.Services.InsertData.Insert_Parameter;
import static excel.file.Services.ExcelModifier.Prototype_Detect;

public class FunctionRetrunFilling {

    public static void Function_Return_Filling(String[] Code, String function_name) throws IOException {

        String prototype;
        String type;
        for (String cLine : Code) {

            if (Prototype_Detect(cLine, function_name)) {

                prototype = cLine;


                if (!(prototype.contains("void "))) {


                    type = prototype.substring(0, prototype.indexOf(function_name) - 1);

                    Parameters[0][Excel.INDEX_OF_NAME]="RTRT_Ret";
                    Parameters[0][Excel.INDEX_OF_TYPE]=type;
                    Parameters[0][Excel.INDEX_OF_ACCESS]="W";
                    Parameters[0][Excel.INDEX_OF_DOMAIN]=(Extract_Domain(Parameters[0][Excel.INDEX_OF_TYPE]))[0];
                    Parameters[0][Excel.INDEX_OF_CLASS]=(Extract_Domain(Parameters[0][Excel.INDEX_OF_TYPE]))[0];
                    Parameters[0][Excel.INDEX_OF_INVALID_DOMAIN]=(Extract_Domain(Parameters[0][Excel.INDEX_OF_TYPE]))[1];

                    if(Parameters[0][Excel.INDEX_OF_DOMAIN].equals("-"))
                    {
                        Parameters[0][Excel.INDEX_OF_DOMAIN]= DataDictionarySearch(Parameters[0][Excel.INDEX_OF_TYPE],false);
                        Parameters[0][Excel.INDEX_OF_CLASS]= DataDictionarySearch(Parameters[0][Excel.INDEX_OF_TYPE],false);
                        Parameters[0][Excel.INDEX_OF_INVALID_DOMAIN]= Extract_Invalid_Domain(Parameters[0][Excel.INDEX_OF_DOMAIN]);
                    }

                    Insert_Parameter(RETURN_FUNCTION_INDEX,0,null);
                    Prototype="RTRT_ret="+Prototype;

                }

                break;
            }
        }

    }
}
