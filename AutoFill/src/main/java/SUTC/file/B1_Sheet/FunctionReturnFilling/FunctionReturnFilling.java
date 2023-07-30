package SUTC.file.B1_Sheet.FunctionReturnFilling;

import static SUTC.file.B1_Sheet.B1_ExcelSheet.*;
import static SUTC.file.B1_Sheet.DataDictionarySearch.DataDictionary.DataDictionarySearch;
import static SUTC.file.Commun.ExcelManipulation.Prototype_Detect;
import static SUTC.file.Commun.ExcelRowsAndColsConstants.*;
import static SUTC.file.B1_Sheet.Commun.ExtractData.Extract_Domain;
import static SUTC.file.B1_Sheet.Commun.ExtractData.Extract_Invalid_Domain;
import static SUTC.file.B1_Sheet.Commun.InsertData.Insert_Parameter;
import static SUTC.file.SutcCreationProcess.codeOfTheFunction;
import static SUTC.file.SutcCreationProcess.functionName;

public class FunctionReturnFilling {

    public static final int INDEX_RESERVED_FOR_FUNCTION_RETURN =0;

    public static void Function_Return_Filling(){

        String prototype;
        String type;



        for (String cLine : codeOfTheFunction) {

            if (Prototype_Detect(cLine, functionName)) {

                prototype = cLine;

                if (!(prototype.contains("void "))) {


                    type = prototype.substring(0, prototype.indexOf(functionName) - 1);

                    Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_NAME]="RTRT_Ret_"+functionName;
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

                    Insert_Parameter(RETURN_FUNCTION_INDEX,INDEX_RESERVED_FOR_FUNCTION_RETURN);
                    prototypeOfTheFunction ="RTRT_Ret_"+functionName+"="+ prototypeOfTheFunction;

                }

                break;
            }
        }

    }
}
