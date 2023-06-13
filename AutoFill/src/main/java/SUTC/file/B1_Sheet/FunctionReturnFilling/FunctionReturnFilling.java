package SUTC.file.B1_Sheet.FunctionReturnFilling;

import SUTC.file.B1_Sheet.B1_ExcelSheet;
import SUTC.file.COMMUN.ExcelModifier;

import static SUTC.file.B1_Sheet.B1_ExcelSheet.Parameters;
import static SUTC.file.B1_Sheet.DataDictionarySearch.DataDictionary.DataDictionarySearch;
import static SUTC.file.COMMUN.ExcelRowsAndColsConstants.*;
import static SUTC.file.B1_Sheet.COMMUN.ExtractData.Extract_Domain;
import static SUTC.file.B1_Sheet.COMMUN.ExtractData.Extract_Invalid_Domain;
import static SUTC.file.B1_Sheet.COMMUN.InsertData.Insert_Parameter;

public class FunctionReturnFilling {

    public static final int INDEX_RESERVED_FOR_FUNCTION_RETURN =0;

    public static void Function_Return_Filling(String[] Code, String function_name){

        String prototype;
        String type;
        for (String cLine : Code) {

            if (ExcelModifier.Prototype_Detect(cLine, function_name)) {

                prototype = cLine;


                if (!(prototype.contains("void "))) {


                    type = prototype.substring(0, prototype.indexOf(function_name) - 1);

                    Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_NAME]="RTRT_Ret_"+function_name;
                    Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_TYPE]=type;
                    Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_ACCESS]="W";
                    Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_DOMAIN]=(Extract_Domain(Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_TYPE]))[0]; // 0 index of domain
                    Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_CLASS]=(Extract_Domain(Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_TYPE]))[0];
                    Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_INVALID_DOMAIN]=(Extract_Domain(Parameters[0][INDEX_OF_TYPE]))[1];

                    if(Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_DOMAIN].equals("-"))
                    {
                        Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_DOMAIN]=DataDictionarySearch(Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_TYPE],false);
                        Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_CLASS]=DataDictionarySearch(Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_TYPE],false);
                        Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_INVALID_DOMAIN]= Extract_Invalid_Domain(Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_DOMAIN]);
                    }

                    Insert_Parameter(B1_ExcelSheet.RETURN_FUNCTION_INDEX,INDEX_RESERVED_FOR_FUNCTION_RETURN,null);
                    B1_ExcelSheet.Prototype="RTRT_Ret_"+function_name+"="+ B1_ExcelSheet.Prototype;

                }

                break;
            }
        }

    }
}
