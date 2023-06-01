package excel.file.B1_Sheet.PrametersFilling;

import excel.file.Services.Excel;

import java.io.IOException;

import static excel.file.B1_Sheet.B1_ExcelSheet.*;
import static excel.file.B1_Sheet.DataDictionarySearch.DataDictionarySearch.DataDictionarySearch;
import static excel.file.B1_Sheet.Services.ExtractData.Extract_Domain;
import static excel.file.B1_Sheet.Services.ExtractData.Extract_Invalid_Domain;
import static excel.file.B1_Sheet.Services.InsertData.Insert_Parameter;
import static excel.file.Services.ExcelFinal.number_of_UFT;
import static excel.file.Services.ExcelModifier.Parameters_Detect;

public class ParametersFilling {


    public static int Extract_Parameters(String[] code,String function_name) throws IOException {
        int start=0,end=0;
        int numberOfParameters=0;
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

            if ((code[i].contains(function_name+"("))||(code[i].contains(function_name+" (")))break;
        }


        for (int j = start; j <= end; j++) {
            param.append(code[j]);

        }
        parameter=param.toString();


        parameter = parameter.substring(parameter.indexOf("(") +1, parameter.indexOf(")"));// extract all the param

        if ((parameter.trim().length()==0)||(parameter.contains("void")))
        {return 0;}

        parameter = parameter.trim()+ ",";
        parameter = parameter.replaceAll(",,",",");
        parameter = parameter.replace(",", ", ");


        while (parameter.contains(",")){
            String p = parameter.substring(0, parameter.indexOf(","));
            parameter = parameter.substring(parameter.indexOf(",") + 1);

            Parameters[numberOfParameters][Excel.INDEX_OF_POINTER]="isNormal";
            if(p.contains("*")) { // if pointer
                Parameters[numberOfParameters][Excel.INDEX_OF_POINTER]="isPointer";
                p = p.replace("*", ""); // delete *
            }


            Parameters[numberOfParameters][Excel.INDEX_OF_NAME]= Parameters_Detect(p)[0];
            Parameters[numberOfParameters][Excel.INDEX_OF_TYPE]= Parameters_Detect(p)[1];
            Parameters[numberOfParameters][Excel.INDEX_OF_DOMAIN]=(Extract_Domain(Parameters[numberOfParameters][Excel.INDEX_OF_TYPE]))[0];
            Parameters[numberOfParameters][Excel.INDEX_OF_CLASS]=(Extract_Domain(Parameters[numberOfParameters][Excel.INDEX_OF_TYPE]))[0];
            Parameters[numberOfParameters][Excel.INDEX_OF_INVALID_DOMAIN]=(Extract_Domain(Parameters[numberOfParameters][Excel.INDEX_OF_TYPE]))[1];


            if(Parameters[numberOfParameters][Excel.INDEX_OF_DOMAIN].equals("-"))
            {
                Parameters[numberOfParameters][Excel.INDEX_OF_DOMAIN]= DataDictionarySearch(Parameters[numberOfParameters][Excel.INDEX_OF_TYPE],false);
                Parameters[numberOfParameters][Excel.INDEX_OF_CLASS]= DataDictionarySearch(Parameters[numberOfParameters][Excel.INDEX_OF_TYPE],false);
                Parameters[numberOfParameters][Excel.INDEX_OF_INVALID_DOMAIN]= Extract_Invalid_Domain(Parameters[numberOfParameters][Excel.INDEX_OF_DOMAIN]);
            }


            numberOfParameters++;
        }
        return numberOfParameters;
    }
    public static void Parameters_Filling(String[] code, String[] LLR) throws IOException{

        int numberOfParameters=Extract_Parameters(code,LLR[1]);
        int normal_parameters_index=START_OF_PARAMETERS_TABLE+ number_of_UFT;// for normal parameters
        int complex_parameters_index=INTERNAL_VARIABLES_POSITION+number_of_UFT;// for pointer Complex parameters
        for (int i = 0; i <numberOfParameters ; i++) {

            if (Parameters[i][Excel.INDEX_OF_POINTER].equals("isNormal")){
                normal_parameters_index=Insert_Parameter(normal_parameters_index,i, LLR);
                Prototype+= Parameters[i][Excel.INDEX_OF_NAME]+", ";
            }
            else
            {
                Prototype+= "&"+Parameters[i][Excel.INDEX_OF_NAME]+", ";
                if(Parameters[i][Excel.INDEX_OF_DOMAIN].equals("-"))
                    complex_parameters_index=Insert_Parameter(complex_parameters_index,i, LLR);
                else
                    normal_parameters_index=Insert_Parameter(normal_parameters_index,i, LLR);



            }


        }
        Global_Start=complex_parameters_index;

    }

}
