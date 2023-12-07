package file.sutc.B1_Sheet.PrametersFilling;

import file.sutc.B1_Sheet.B1_ExcelSheet;

import static file.commun.LoggerInitialize.log4Error;
import static file.sutc.B1_Sheet.B1_ExcelSheet.*;
import static file.sutc.B1_Sheet.DataDictionarySearch.DataDictionary.DataDictionarySearch;
import static file.sutc.Commun.ExcelManipulation.Parameters_Detect;
import static file.sutc.Commun.ExcelRowsAndColsConstants.*;
import static file.sutc.B1_Sheet.Commun.ExtractData.*;
import static file.sutc.B1_Sheet.Commun.InsertData.Insert_Parameter;
import static file.sutc.SutcCreationProcess.codeOfTheFunction;
import static file.sutc.SutcCreationProcess.functionName;


public class ParametersFilling {


    public static int ExtractParameters(String[] code, String function_name){
        int start=0,end=0;
        int numberOfParameters=0;
        String[] domainClass ;
        String parameter;
        StringBuilder param= new StringBuilder();

        for (int i = code.length - 1; i >= 0; i--) {

            code[i] = code[i].replaceAll("\\(\\(" , "");
            code[i] = code[i].replaceAll("\\)\\)" , "");

            if (code[i].contains("(")) {
                start = i;
            }
            if (code[i].contains(")")) {
                end = i+1;
            }

            if ((code[i].contains(" "+function_name+"("))||(code[i].contains(" "+function_name+" (")))
                break;
        }
        //System.out.println(function_name +":start "+start+"end "+end);

        for (int j = start; j <= end; j++) {

            param.append(code[j]);
        }
        parameter=param.toString();

        try {
            parameter = parameter.substring(parameter.indexOf("(") + 1, parameter.indexOf(")"));// extract all the param
        }catch (Exception e){

            String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
            log4Error(methodName+" : "+e.getMessage() );

        }

        if ((parameter.trim().length()==0)||(parameter.contains("void")))
        {return 0;}

        parameter = parameter.trim()+ ",";
        parameter = parameter.replaceAll(",,",",");
        parameter = parameter.replace(",", ", ");

        while (parameter.contains(",")){
            String p = parameter.substring(0, parameter.indexOf(","));
            parameter = parameter.substring(parameter.indexOf(",") + 1);

            Parameters[numberOfParameters][INDEX_OF_POINTER]="isNormal";
            if(p.contains("*")) { // if pointer
                Parameters[numberOfParameters][INDEX_OF_POINTER]="isPointer";
                p = p.replace("*", ""); // delete *
            }
            //System.out.println("#"+p+"#");
            String[] nameType=Parameters_Detect(p);

            Parameters[numberOfParameters][INDEX_OF_NAME]= nameType[0];
            Parameters[numberOfParameters][INDEX_OF_TYPE]= nameType[1];
            domainClass=Extract_Domain(Parameters[numberOfParameters][INDEX_OF_TYPE]);
            Parameters[numberOfParameters][INDEX_OF_DOMAIN]=domainClass[0];
            Parameters[numberOfParameters][INDEX_OF_CLASS]=domainClass[0];
            Parameters[numberOfParameters][INDEX_OF_INVALID_DOMAIN]=domainClass[1];


            if(Parameters[numberOfParameters][INDEX_OF_DOMAIN].equals("-"))
            {
                Parameters[numberOfParameters][INDEX_OF_DOMAIN]= DataDictionarySearch(Parameters[numberOfParameters][INDEX_OF_TYPE],false);
                Parameters[numberOfParameters][INDEX_OF_CLASS]= Parameters[numberOfParameters][INDEX_OF_DOMAIN];
                Parameters[numberOfParameters][INDEX_OF_INVALID_DOMAIN]= Extract_Invalid_Domain(Parameters[numberOfParameters][INDEX_OF_DOMAIN]);
            }

            numberOfParameters++;
        }
        return numberOfParameters;
    }
    public static void Parameters_Filling() {

        Parameters=new String[100][10];
        numberOfParameters= ExtractParameters(codeOfTheFunction,functionName);
        int normal_parameters_index= START_OF_PARAMETERS_TABLE;// for normal parameters
        int complex_parameters_index= INTERNAL_VARIABLES_POSITION;// for pointer Complex parameters

        for (int i = Parameters.length-2; i >= 0 ; i--) { // Shift the parameters table
            System.arraycopy(Parameters[i], 0, Parameters[i + 1], 0, 10);
        }

        for (int i = 1; i <numberOfParameters+1 ; i++) {

            if (Parameters[i][INDEX_OF_POINTER].equals("isNormal")){
                normal_parameters_index=Insert_Parameter(normal_parameters_index,i);
                prototypeOfTheFunction += Parameters[i][INDEX_OF_NAME]+", ";
            }
            else
            {
                B1_ExcelSheet.prototypeOfTheFunction += "&"+ Parameters[i][INDEX_OF_NAME]+", ";
                if(Parameters[i][INDEX_OF_DOMAIN].equals("-"))
                    complex_parameters_index=Insert_Parameter(complex_parameters_index,i);
                else
                    normal_parameters_index=Insert_Parameter(normal_parameters_index,i);

            }


        }
        Global_Start=complex_parameters_index;

    }

}
