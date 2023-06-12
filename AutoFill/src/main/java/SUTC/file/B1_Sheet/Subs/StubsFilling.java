package SUTC.file.B1_Sheet.Subs;

import SUTC.file.B1_Sheet.B1_ExcelSheet;
import SUTC.file.B1_Sheet.DataDictionarySearch.DataDictionarySearch;
import SUTC.file.B1_Sheet.PrametersFilling.ParametersFilling;
import SUTC.file.SutcCreationProccess;
import SUTC.file.COMMUN.ExcelModifier;
import CODE.file.ExtractCode;
import static SUTC.file.COMMUN.ExcelRowsAndColsConstants.*;
import java.io.IOException;

import static SUTC.file.B1_Sheet.COMMUN.ExtractData.Extract_Domain;
import static SUTC.file.B1_Sheet.COMMUN.ExtractData.Extract_Invalid_Domain;
import static SUTC.file.B1_Sheet.COMMUN.InsertData.Insert_Invalid_Row;
import static SUTC.file.B1_Sheet.COMMUN.InsertData.Insert_Row;


/////////////////////////////////////////////////////STUBS//////////////////////////////////////////////////////////
public class StubsFilling {

    public static void Stubs_Filling(String[] LLR) {

        int numberOfStubs= Extract_Stubs(LLR);



        String Code_Stub;
        String[] Code_stub;
        int numberOfParameters;

        int distance= B1_ExcelSheet.STUB_PARAMETERS_TABLE_POSITION -1 + SutcCreationProccess.number_of_UFT;
        for (int i = 0; i <numberOfStubs ; i++) {

            Code_Stub=(ExtractCode.extract(B1_ExcelSheet.Stubs[i]+".c"));

            ExcelModifier.Fill_Cell(B1_ExcelSheet.Stubs[i], SHEET_B1, B1_ExcelSheet.STUB_DEFINITION_TABLE_POSITION+ SutcCreationProccess.number_of_UFT +(i* B1_ExcelSheet.DISTANCE_BETWEEN_STUBS), CELL_COL_2);

            if(Code_Stub.equals("")){
                ExcelModifier.Fill_Cell("not exist in the Code", SHEET_B1, B1_ExcelSheet.STUB_DEFINITION_TABLE_POSITION+ SutcCreationProccess.number_of_UFT +(i* B1_ExcelSheet.DISTANCE_BETWEEN_STUBS)+2, CELL_COL_2);
                for (int j = 7; j <10 ; j++) { // add empty lines
                    ExcelModifier.Fill_Cell("'", SHEET_B1, B1_ExcelSheet.STUB_DEFINITION_TABLE_POSITION+ SutcCreationProccess.number_of_UFT +(i* B1_ExcelSheet.DISTANCE_BETWEEN_STUBS)+j, CELL_COL_1);
                }
                distance=distance+ B1_ExcelSheet.DISTANCE_BETWEEN_STUBS;
                continue; // if code not exist.
            }
            Code_stub=Code_Stub.split("\n"); // split code in table

            numberOfParameters= ParametersFilling.Extract_Parameters(Code_stub, B1_ExcelSheet.Stubs[i]);

            Stub_Access_Detect(LLR, B1_ExcelSheet.Stubs[i],numberOfParameters);

            numberOfParameters=Stub_Return_Filling(Code_stub, B1_ExcelSheet.Stubs[i],numberOfParameters);

            int d = distance;


            for (int j = 0; j < numberOfParameters; j++) {

                distance+=Insert_Row(distance+j, B1_ExcelSheet.Parameters[j]);

                if ((B1_ExcelSheet.Parameters[j][INDEX_OF_ACCESS].contains("out")|| B1_ExcelSheet.Parameters[j][INDEX_OF_ACCESS].contains("Return"))&&(!(B1_ExcelSheet.Parameters[j][7].equals("-")))){
                    distance++;
                    distance+=Insert_Invalid_Row(distance+j, B1_ExcelSheet.Parameters[j]);
                }

            }

            distance=d+ B1_ExcelSheet.DISTANCE_BETWEEN_STUBS;

        }


        ExcelModifier.Remove_Extra_Rows(SHEET_B1,distance-6, B1_ExcelSheet.END_OF_SHEET_POSITION+ SutcCreationProccess.number_of_UFT);
        ExcelModifier.Fill_Cell("End of UTC definition", SHEET_B1,distance-7,1);
    }
    public static int Extract_Stubs(String[] LLR){

        int start= 0,end = 0;
        int numberOfStubs=0;

        for (int i = 0; i < LLR.length; i++) {

            if (ExcelModifier.Search(Stub_start,LLR[i])){
                start=i+1;
            }
            if (ExcelModifier.Search(Stub_end,LLR[i]))
            {
                end=i-1;
                break;
            }
        }

        for (int j = start; j <= end ; j++) {

            if((LLR[j].trim().isEmpty())||(LLR[j].equalsIgnoreCase("none"))||(LLR[j].equalsIgnoreCase("none.")))
                continue;
            B1_ExcelSheet.Stubs[numberOfStubs]=LLR[j].trim();
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
                B1_ExcelSheet.Parameters[j][INDEX_OF_ACCESS] = "_inout";
                j++;
            } else if ((LLR[i].toUpperCase().contains("OUT")) || (LLR[i].toUpperCase().contains("OUT:"))) {
                B1_ExcelSheet.Parameters[j][INDEX_OF_ACCESS] = "_out";

                j++;
            } else if ((LLR[i].toUpperCase().contains("IN") || (LLR[i].toUpperCase().contains("IN:")))) {
                B1_ExcelSheet.Parameters[j][INDEX_OF_ACCESS] = "_in";
                B1_ExcelSheet.Parameters[j][INDEX_OF_CLASS] = "-";
                j++;
            }

        }
    }
    public static int Stub_Return_Filling(String[] Code, String function_name, int numberOfParameters) {


        for (String code_line  : Code) {

            if (ExcelModifier.Prototype_Detect(code_line, function_name)) {


                for (int i = B1_ExcelSheet.Parameters.length-2; i >= 0 ; i--) { // Shift the parameters table
                    System.arraycopy(B1_ExcelSheet.Parameters[i], 0, B1_ExcelSheet.Parameters[i + 1], 0, 10);
                }
                if (!(code_line.contains("void ")))  {

                    B1_ExcelSheet.Parameters[0][INDEX_OF_NAME] = "Return_Function";
                    B1_ExcelSheet.Parameters[0][INDEX_OF_TYPE] = code_line.trim().substring(0, code_line.trim().indexOf(" ") );
                    B1_ExcelSheet.Parameters[0][INDEX_OF_ACCESS] = "Return";
                    B1_ExcelSheet.Parameters[0][INDEX_OF_DOMAIN] = (Extract_Domain(B1_ExcelSheet.Parameters[0][INDEX_OF_TYPE]))[0];
                    B1_ExcelSheet.Parameters[0][INDEX_OF_CLASS] = (Extract_Domain(B1_ExcelSheet.Parameters[0][INDEX_OF_TYPE]))[0];
                    B1_ExcelSheet.Parameters[0][INDEX_OF_INVALID_DOMAIN] = (Extract_Domain(B1_ExcelSheet.Parameters[0][INDEX_OF_TYPE]))[1];

                    if (B1_ExcelSheet.Parameters[0][INDEX_OF_DOMAIN].equals("-")) {
                        B1_ExcelSheet.Parameters[0][INDEX_OF_DOMAIN] = DataDictionarySearch.DataDictionarySearch(B1_ExcelSheet.Parameters[0][INDEX_OF_TYPE], false);
                        B1_ExcelSheet.Parameters[0][INDEX_OF_CLASS] = DataDictionarySearch.DataDictionarySearch(B1_ExcelSheet.Parameters[0][INDEX_OF_TYPE], false);
                        B1_ExcelSheet.Parameters[0][INDEX_OF_INVALID_DOMAIN] = Extract_Invalid_Domain(B1_ExcelSheet.Parameters[0][INDEX_OF_DOMAIN]);
                    }

                    break;
                } else {
                    B1_ExcelSheet.Parameters[0][INDEX_OF_NAME] = "Return_Function";
                    B1_ExcelSheet.Parameters[0][INDEX_OF_TYPE] = "void";
                    B1_ExcelSheet.Parameters[0][INDEX_OF_ACCESS] = "Return";
                    B1_ExcelSheet.Parameters[0][INDEX_OF_DOMAIN] = "-";
                    B1_ExcelSheet.Parameters[0][INDEX_OF_CLASS] = "-";
                    B1_ExcelSheet.Parameters[0][INDEX_OF_INVALID_DOMAIN] = "-";

                    break;
                }

            }
        }

        return ++numberOfParameters;
    }

}
