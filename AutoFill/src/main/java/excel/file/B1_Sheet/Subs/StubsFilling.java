package excel.file.B1_Sheet.Subs;

import c.file.ExtractCode;
import excel.file.Services.Excel;
import excel.file.Services.ExcelModifier;
import java.io.IOException;

import static excel.file.B1_Sheet.B1_ExcelSheet.*;
import static excel.file.B1_Sheet.DataDictionarySearch.DataDictionarySearch.DataDictionarySearch;
import static excel.file.B1_Sheet.PrametersFilling.ParametersFilling.Extract_Parameters;
import static excel.file.B1_Sheet.Services.ExtractData.Extract_Domain;
import static excel.file.B1_Sheet.Services.ExtractData.Extract_Invalid_Domain;
import static excel.file.B1_Sheet.Services.InsertData.Insert_Invalid_Row;
import static excel.file.B1_Sheet.Services.InsertData.Insert_Row;
import static excel.file.Services.ExcelFinal.number_of_UFT;
import static excel.file.Services.ExcelModifier.Prototype_Detect;

public class StubsFilling {



    /////////////////////////////////////////////////////STUBS//////////////////////////////////////////////////////////
    public static void Stubs_Filling(String[] LLR) throws IOException {

        int numberOfStubs= Extract_Stubs(LLR);



        String Code_Stub;
        String[] Code_stub;
        int numberOfParameters;

        int distance= STUB_PARAMETERS_TABLE_POSITION -1 +number_of_UFT;
        for (int i = 0; i <numberOfStubs ; i++) {



            Code_Stub=(ExtractCode.extract(Stubs[i]+".c"));

            ExcelModifier.Fill_Cell(Stubs[i], Excel.SHEET_B1, STUB_DEFINITION_TABLE_POSITION+number_of_UFT +(i*DISTANCE_BETWEEN_STUBS), Excel.CELL_COL_2);

            if(Code_Stub.equals("")){
                ExcelModifier.Fill_Cell("not exist in the Code",Excel.SHEET_B1, STUB_DEFINITION_TABLE_POSITION+number_of_UFT +(i*DISTANCE_BETWEEN_STUBS)+2, Excel.CELL_COL_2);
                for (int j = 7; j <12 ; j++) { // add empty lines
                    ExcelModifier.Fill_Cell("-",Excel.SHEET_B1, STUB_DEFINITION_TABLE_POSITION+number_of_UFT +(i*DISTANCE_BETWEEN_STUBS)+j, Excel.CELL_COL_1);
                }
                distance=distance+DISTANCE_BETWEEN_STUBS;
                continue; // if code not exist.
            }

            Code_stub=Code_Stub.split("\n"); // split code in table

            numberOfParameters=Extract_Parameters(Code_stub,Stubs[i]);

            Stub_Access_Detect(LLR,Stubs[i],numberOfParameters);

            numberOfParameters=Stub_Return_Filling(Code_stub,Stubs[i],numberOfParameters);

            int d = distance;


            for (int j = 0; j < numberOfParameters; j++) {

                distance+=Insert_Row(distance+j,Parameters[j]);

                if ((Parameters[j][Excel.INDEX_OF_ACCESS].contains("out")||Parameters[j][Excel.INDEX_OF_ACCESS].contains("Return"))&&(!(Parameters[j][7].equals("-")))){
                    distance++;
                    distance+=Insert_Invalid_Row(distance+j,Parameters[j]);
                }

            }

            distance=d+DISTANCE_BETWEEN_STUBS;

        }


        ExcelModifier.Remove_Extra_Rows(Excel.SHEET_B1,distance-6, END_OF_SHEET_POSITION+ number_of_UFT);
        ExcelModifier.Fill_Cell("End of UTC definition",Excel.SHEET_B1,distance-7,1);
    }
    public static int Extract_Stubs(String[] LLR){

        int start= 0,end = 0;
        int numberOfStubs=0;

        for (int i = 0; i < LLR.length; i++) {

            if (ExcelModifier.Search(Excel.Stub_start,LLR[i])){
                start=i+1;
            }
            if (ExcelModifier.Search(Excel.Stub_end,LLR[i]))
            {
                end=i-1;
                break;
            }
        }

        for (int j = start; j <= end ; j++) {

            if((LLR[j].trim().isEmpty())||(LLR[j].equalsIgnoreCase("none")))
                continue;
            Stubs[numberOfStubs]=LLR[j].trim();
            numberOfStubs++;
        }
        return numberOfStubs;
    }
    public static void Stub_Access_Detect(String[] LLR, String stub_name, int numberOfParameters) {
        int position_of_stub=0;


        for (int i = LLR.length-1; i >=0 ; i--) {
            if((LLR[i].trim().equalsIgnoreCase(stub_name))||(LLR[i].trim().equalsIgnoreCase(stub_name+":")))
            {
                position_of_stub=i;
                break;
            }
        }

        int end = position_of_stub+numberOfParameters;
        int j=0;

        for (int i = position_of_stub; i <=end; i++) {
            if (LLR[i].toUpperCase().contains("FUNCTION RETURN"))
                end++;
            else
            if ((LLR[i].toUpperCase().contains("IN/OUT")) || (LLR[i].toUpperCase().contains("IN/OUT:"))) {
                Parameters[j][Excel.INDEX_OF_ACCESS] = "_inout";
                j++;
            } else if ((LLR[i].toUpperCase().contains("OUT")) || (LLR[i].toUpperCase().contains("OUT:"))) {
                Parameters[j][Excel.INDEX_OF_ACCESS] = "_out";

                j++;
            } else if ((LLR[i].toUpperCase().contains("IN") || (LLR[i].toUpperCase().contains("IN:")))) {
                Parameters[j][Excel.INDEX_OF_ACCESS] = "_in";
                Parameters[j][Excel.INDEX_OF_CLASS] = "-";
                j++;
            }

        }
    }
    public static int Stub_Return_Filling(String[] Code, String function_name, int numberOfParameters) throws IOException {


        for (String code_line  : Code) {

            if (Prototype_Detect(code_line, function_name)) {


                for (int i = Parameters.length-2; i >= 0 ; i--) { // Shift the parameters table
                    System.arraycopy(Parameters[i], 0, Parameters[i + 1], 0, 10);
                }
                if (!(code_line.contains("void ")))  {

                    Parameters[0][Excel.INDEX_OF_NAME] = "Return_Function";
                    Parameters[0][Excel.INDEX_OF_TYPE] = code_line.trim().substring(0, code_line.trim().indexOf(" ") );
                    Parameters[0][Excel.INDEX_OF_ACCESS] = "Return";
                    Parameters[0][Excel.INDEX_OF_DOMAIN] = (Extract_Domain(Parameters[0][Excel.INDEX_OF_TYPE]))[0];
                    Parameters[0][Excel.INDEX_OF_CLASS] = (Extract_Domain(Parameters[0][Excel.INDEX_OF_TYPE]))[0];
                    Parameters[0][Excel.INDEX_OF_INVALID_DOMAIN] = (Extract_Domain(Parameters[0][Excel.INDEX_OF_TYPE]))[1];

                    if (Parameters[0][Excel.INDEX_OF_DOMAIN].equals("-")) {
                        Parameters[0][Excel.INDEX_OF_DOMAIN] = DataDictionarySearch(Parameters[0][Excel.INDEX_OF_TYPE], false);
                        Parameters[0][Excel.INDEX_OF_CLASS] = DataDictionarySearch(Parameters[0][Excel.INDEX_OF_TYPE], false);
                        Parameters[0][Excel.INDEX_OF_INVALID_DOMAIN] = Extract_Invalid_Domain(Parameters[0][Excel.INDEX_OF_DOMAIN]);
                    }

                    break;
                } else {
                    Parameters[0][Excel.INDEX_OF_NAME] = "Return_Function";
                    Parameters[0][Excel.INDEX_OF_TYPE] = "void";
                    Parameters[0][Excel.INDEX_OF_ACCESS] = "Return";
                    Parameters[0][Excel.INDEX_OF_DOMAIN] = "-";
                    Parameters[0][Excel.INDEX_OF_CLASS] = "-";
                    Parameters[0][Excel.INDEX_OF_INVALID_DOMAIN] = "-";

                    break;
                }

            }
        }

        return ++numberOfParameters;
    }
















}
