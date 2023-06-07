package SUTC.file.B1_Sheet.PrametersFilling;

import SUTC.file.B1_Sheet.B1_ExcelSheet;
import SUTC.file.B1_Sheet.DataDictionarySearch.DataDictionarySearch;
import SUTC.file.SutcCreationProccess;
import SUTC.file.COMMUN.ExcelModifier;
import static SUTC.file.COMMUN.ExcelRowsAndColsConstants.*;

import java.io.IOException;

import static SUTC.file.B1_Sheet.COMMUN.ExtractData.Extract_Domain;
import static SUTC.file.B1_Sheet.COMMUN.ExtractData.Extract_Invalid_Domain;
import static SUTC.file.B1_Sheet.COMMUN.InsertData.Insert_Parameter;

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

            B1_ExcelSheet.Parameters[numberOfParameters][INDEX_OF_POINTER]="isNormal";
            if(p.contains("*")) { // if pointer
                B1_ExcelSheet.Parameters[numberOfParameters][INDEX_OF_POINTER]="isPointer";
                p = p.replace("*", ""); // delete *
            }


            B1_ExcelSheet.Parameters[numberOfParameters][INDEX_OF_NAME]= ExcelModifier.Parameters_Detect(p)[0];
            B1_ExcelSheet.Parameters[numberOfParameters][INDEX_OF_TYPE]= ExcelModifier.Parameters_Detect(p)[1];
            B1_ExcelSheet.Parameters[numberOfParameters][INDEX_OF_DOMAIN]=(Extract_Domain(B1_ExcelSheet.Parameters[numberOfParameters][INDEX_OF_TYPE]))[0];
            B1_ExcelSheet.Parameters[numberOfParameters][INDEX_OF_CLASS]=(Extract_Domain(B1_ExcelSheet.Parameters[numberOfParameters][INDEX_OF_TYPE]))[0];
            B1_ExcelSheet.Parameters[numberOfParameters][INDEX_OF_INVALID_DOMAIN]=(Extract_Domain(B1_ExcelSheet.Parameters[numberOfParameters][INDEX_OF_TYPE]))[1];


            if(B1_ExcelSheet.Parameters[numberOfParameters][INDEX_OF_DOMAIN].equals("-"))
            {
                B1_ExcelSheet.Parameters[numberOfParameters][INDEX_OF_DOMAIN]= DataDictionarySearch.DataDictionarySearch(B1_ExcelSheet.Parameters[numberOfParameters][INDEX_OF_TYPE],false);
                B1_ExcelSheet.Parameters[numberOfParameters][INDEX_OF_CLASS]= DataDictionarySearch.DataDictionarySearch(B1_ExcelSheet.Parameters[numberOfParameters][INDEX_OF_TYPE],false);
                B1_ExcelSheet.Parameters[numberOfParameters][INDEX_OF_INVALID_DOMAIN]= Extract_Invalid_Domain(B1_ExcelSheet.Parameters[numberOfParameters][INDEX_OF_DOMAIN]);
            }


            numberOfParameters++;
        }
        return numberOfParameters;
    }
    public static void Parameters_Filling(String[] code, String[] LLR) throws IOException{

        int numberOfParameters=Extract_Parameters(code,LLR[1]);
        int normal_parameters_index= B1_ExcelSheet.START_OF_PARAMETERS_TABLE+ SutcCreationProccess.number_of_UFT;// for normal parameters
        int complex_parameters_index= B1_ExcelSheet.INTERNAL_VARIABLES_POSITION+ SutcCreationProccess.number_of_UFT;// for pointer Complex parameters
        for (int i = 0; i <numberOfParameters ; i++) {

            if (B1_ExcelSheet.Parameters[i][INDEX_OF_POINTER].equals("isNormal")){
                normal_parameters_index=Insert_Parameter(normal_parameters_index,i, LLR);
                B1_ExcelSheet.Prototype+= B1_ExcelSheet.Parameters[i][INDEX_OF_NAME]+", ";
            }
            else
            {
                B1_ExcelSheet.Prototype+= "&"+ B1_ExcelSheet.Parameters[i][INDEX_OF_NAME]+", ";
                if(B1_ExcelSheet.Parameters[i][INDEX_OF_DOMAIN].equals("-"))
                    complex_parameters_index=Insert_Parameter(complex_parameters_index,i, LLR);
                else
                    normal_parameters_index=Insert_Parameter(normal_parameters_index,i, LLR);



            }


        }
        B1_ExcelSheet.Global_Start=complex_parameters_index;

    }

}
