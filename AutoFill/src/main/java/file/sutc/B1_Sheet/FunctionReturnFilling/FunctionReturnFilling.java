package file.sutc.B1_Sheet.FunctionReturnFilling;

import static file.sutc.B1_Sheet.B1_ExcelSheet.*;
import static file.sutc.B1_Sheet.DataDictionarySearch.DataDictionary.DataDictionarySearch;
import static file.sutc.Commun.ExcelManipulation.Prototype_Detect;
import static file.sutc.Commun.ExcelRowsAndColsConstants.*;
import static file.sutc.B1_Sheet.Commun.ExtractData.Extract_Domain;
import static file.sutc.B1_Sheet.Commun.ExtractData.Extract_Invalid_Domain;
import static file.sutc.B1_Sheet.Commun.InsertData.Insert_Parameter;
import static file.sutc.SutcCreationProcess.codeOfTheFunction;
import static file.sutc.SutcCreationProcess.functionName;

public class FunctionReturnFilling {

    public static final int INDEX_RESERVED_FOR_FUNCTION_RETURN =0;

    public static void Function_Return_Filling(){

        String prototype;
        String type;
        String[] domainClass ;

        for (String codeLine : codeOfTheFunction) {

            if (Prototype_Detect(codeLine, functionName)) {

                prototype = codeLine;

                if (!(prototype.contains("void "))) {


                    type = prototype.substring(0, prototype.toLowerCase().indexOf(functionName.toLowerCase()) - 1);
                    Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_NAME]="RTRT_Ret_"+functionName;
                    Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_TYPE]=type.replace("const","");
                    Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_ACCESS]="W";

                    domainClass = Extract_Domain(Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_TYPE]);
                    Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_DOMAIN]=domainClass[0]; // 0 index of domain
                    Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_CLASS]=domainClass[0];
                    Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_INVALID_DOMAIN]=domainClass[1];

                    if(Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_DOMAIN].equals("-"))
                    {
                        Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_DOMAIN]=DataDictionarySearch(Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_TYPE],0);
                        Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_CLASS]= Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_DOMAIN];
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
