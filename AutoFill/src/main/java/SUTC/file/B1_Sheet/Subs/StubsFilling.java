package SUTC.file.B1_Sheet.Subs;

import SUTC.file.B1_Sheet.B1_ExcelSheet;
import SUTC.file.B1_Sheet.DataDictionarySearch.DataDictionarySearch;
import SUTC.file.B1_Sheet.PrametersFilling.ParametersFilling;
import SUTC.file.SutcCreationProccess;
import SUTC.file.COMMUN.ExcelModifier;
import CODE.file.ExtractCode;
import static COMMUN.LoggerInitialize.*;
import static SUTC.file.B1_Sheet.B1_ExcelSheet.Parameters;
import static SUTC.file.B1_Sheet.B1_ExcelSheet.Stubs;
import static SUTC.file.B1_Sheet.PrametersFilling.ParametersFilling.Extract_Parameters;
import static SUTC.file.COMMUN.ExcelModifier.Fill_Cell;
import static SUTC.file.COMMUN.ExcelModifier.Search;
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

            Code_Stub=(ExtractCode.extract(Stubs[i]+".c"));

            Fill_Cell(Stubs[i], SHEET_B1, B1_ExcelSheet.STUB_DEFINITION_TABLE_POSITION+ SutcCreationProccess.number_of_UFT +(i* B1_ExcelSheet.DISTANCE_BETWEEN_STUBS), CELL_COL_2);

            if(Code_Stub.equals("")){
                //ExcelModifier.Fill_Cell("not exist in the Code", SHEET_B1, B1_ExcelSheet.STUB_DEFINITION_TABLE_POSITION+ SutcCreationProccess.number_of_UFT +(i* B1_ExcelSheet.DISTANCE_BETWEEN_STUBS)+2, CELL_COL_2);
                for (int j = 7; j <10 ; j++) { // add empty lines
                    Fill_Cell("'", SHEET_B1, B1_ExcelSheet.STUB_DEFINITION_TABLE_POSITION+ SutcCreationProccess.number_of_UFT +(i* B1_ExcelSheet.DISTANCE_BETWEEN_STUBS)+j, CELL_COL_1);
                }
                distance=distance+ B1_ExcelSheet.DISTANCE_BETWEEN_STUBS;
                continue; // if code not exist.
            }
            Code_stub=Code_Stub.split("\n"); // split code in table

            numberOfParameters= Extract_Parameters(Code_stub, Stubs[i]);
            log4Debug(Stubs[i]+" numberOfParameters="+numberOfParameters);
            Stub_Access_Detect(LLR, Stubs[i],numberOfParameters);

            numberOfParameters=Stub_Return_Filling(Code_stub, Stubs[i],numberOfParameters);

            int d = distance;

            for (int j = 0; j < numberOfParameters; j++) {

                distance+=Insert_Row(distance+j, Parameters[j]);

                if ((Parameters[j][INDEX_OF_ACCESS].contains("out")|| Parameters[j][INDEX_OF_ACCESS].contains("Return"))&&(!(Parameters[j][7].equals("-")))){
                    distance++;
                    distance+=Insert_Invalid_Row(distance+j, Parameters[j]);
                }

            }

            distance=d+ B1_ExcelSheet.DISTANCE_BETWEEN_STUBS;

        }


        ExcelModifier.Remove_Extra_Rows(SHEET_B1,distance-6, B1_ExcelSheet.END_OF_SHEET_POSITION+ SutcCreationProccess.number_of_UFT);
        Fill_Cell("End of UTC definition", SHEET_B1,distance-7,1);
    }
    public static int Extract_Stubs(String[] LLR){

        int start= 0,end = 0;
        int numberOfStubs=0;

        for (int i = 0; i < LLR.length; i++) {

            if (Search(Stub_start,LLR[i])){
                start=i+1;
            }
            if (Search(Stub_end,LLR[i]))
            {
                end=i-1;
                break;
            }
        }

        for (int j = start; j <= end ; j++) {

            if((LLR[j].trim().isEmpty())||(LLR[j].equalsIgnoreCase("none"))||(LLR[j].equalsIgnoreCase("none.")))
                continue;
            Stubs[numberOfStubs]=LLR[j].trim();
            numberOfStubs++;
        }
        return numberOfStubs;
    }
    public static void Stub_Access_Detect(String[] LLR, String stub_name, int numberOfParameters) {
        int position_of_stub=0;


        for (int i = LLR.length-1; i >=0 ; i--) {
            String llr_line=LLR[i].trim().toLowerCase();
            if((llr_line.contains(stub_name.toLowerCase()))||(llr_line.contains(stub_name.toLowerCase()+":")))
            {
                position_of_stub=i+1;
                break;

            }
        }

        int end = position_of_stub+numberOfParameters;
        int j=0;

        for (int i = position_of_stub; i <end; i++) {

            if (LLR[i].toUpperCase().contains("FUNCTION RETURN"))
                end++;
            else
            if ((LLR[i].toUpperCase().contains("IN/OUT:")) || (LLR[i].toUpperCase().contains("IN/OUT "))) {
                log4Debug(Parameters[j][INDEX_OF_NAME]+ " Access_IN_OUT :"+LLR[i]);
                Parameters[j][INDEX_OF_ACCESS] = "_inout";
                j++;
            } else if ((LLR[i].toUpperCase().contains("OUT:")) || (LLR[i].toUpperCase().contains("OUT "))) {
                log4Debug(Parameters[j][INDEX_OF_NAME]+ " Access_OUT :"+LLR[i]);
                Parameters[j][INDEX_OF_ACCESS] = "_out";

                j++;
            } else if ((LLR[i].toUpperCase().contains("IN:") || (LLR[i].toUpperCase().contains("IN ")))) {
                log4Debug(Parameters[j][INDEX_OF_NAME]+ " Access_IN :"+LLR[i]);
                Parameters[j][INDEX_OF_ACCESS] = "_in";
                Parameters[j][INDEX_OF_CLASS] = "-";
                j++;
            }

        }
    }
    public static int Stub_Return_Filling(String[] Code, String function_name, int numberOfParameters) {


        for (String code_line  : Code) {

            if (ExcelModifier.Prototype_Detect(code_line, function_name)) {


                for (int i = Parameters.length-2; i >= 0 ; i--) { // Shift the parameters table
                    System.arraycopy(Parameters[i], 0, Parameters[i + 1], 0, 10);
                }
                if (!(code_line.contains("void ")))  {

                    Parameters[0][INDEX_OF_NAME] = "Return_Function";
                    Parameters[0][INDEX_OF_TYPE] = code_line.trim().substring(0, code_line.trim().indexOf(" ") );
                    Parameters[0][INDEX_OF_ACCESS] = "Return";
                    Parameters[0][INDEX_OF_DOMAIN] = (Extract_Domain(Parameters[0][INDEX_OF_TYPE]))[0];
                    Parameters[0][INDEX_OF_CLASS] = (Extract_Domain(Parameters[0][INDEX_OF_TYPE]))[0];
                    Parameters[0][INDEX_OF_INVALID_DOMAIN] = (Extract_Domain(Parameters[0][INDEX_OF_TYPE]))[1];

                    if (Parameters[0][INDEX_OF_DOMAIN].equals("-")) {
                        Parameters[0][INDEX_OF_DOMAIN] = DataDictionarySearch.DataDictionarySearch(Parameters[0][INDEX_OF_TYPE], false);
                        Parameters[0][INDEX_OF_CLASS] = DataDictionarySearch.DataDictionarySearch(Parameters[0][INDEX_OF_TYPE], false);
                        Parameters[0][INDEX_OF_INVALID_DOMAIN] = Extract_Invalid_Domain(Parameters[0][INDEX_OF_DOMAIN]);
                    }

                    break;
                } else {
                    Parameters[0][INDEX_OF_NAME] = "Return_Function";
                    Parameters[0][INDEX_OF_TYPE] = "void";
                    Parameters[0][INDEX_OF_ACCESS] = "Return";
                    Parameters[0][INDEX_OF_DOMAIN] = "-";
                    Parameters[0][INDEX_OF_CLASS] = "-";
                    Parameters[0][INDEX_OF_INVALID_DOMAIN] = "-";

                    break;
                }

            }
        }

        return ++numberOfParameters;
    }

}
