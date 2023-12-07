package file.sutc.B1_Sheet.Subs;

import java.util.Objects;

import static file.code.ExtractFunction.ExtractFunctionFromCode;
import static file.commun.LoggerInitialize.*;
import static file.sutc.B1_Sheet.B1_ExcelSheet.*;
import static file.sutc.B1_Sheet.Commun.InsertData.*;
import static file.sutc.B1_Sheet.DataDictionarySearch.DataDictionary.DataDictionarySearch;
import static file.sutc.B1_Sheet.FunctionReturnFilling.FunctionReturnFilling.INDEX_RESERVED_FOR_FUNCTION_RETURN;
import static file.sutc.B1_Sheet.PrametersFilling.ParametersFilling.ExtractParameters;
import static file.sutc.Commun.ExcelManipulation.*;
import static file.sutc.Commun.ExcelRowsAndColsConstants.*;

import static file.sutc.B1_Sheet.Commun.ExtractData.Extract_Domain;
import static file.sutc.B1_Sheet.Commun.ExtractData.Extract_Invalid_Domain;
import static file.sutc.SutcCreationProcess.effectsTable;
import static file.sutc.SutcCreationProcess.llrOfTheFunction;


/////////////////////////////////////////////////////STUBS//////////////////////////////////////////////////////////
public class StubsFilling {

    public static void Stubs_Filling() {

        int numberOfParameters,row;
        String[] Code_stub;
        int first_row=0;
        Parameters=new String[100][10];
        numberOfStubs= Extract_Stubs();
        row= STUB_PARAMETERS_TABLE_POSITION;


        for (int i = 0; i <numberOfStubs ; i++) {

            Code_stub=ExtractFunctionFromCode(Stubs[i].trim());

            Fill_Cell(Stubs[i], SHEET_B1_INDEX, STUB_DEFINITION_TABLE_POSITION +(i* DISTANCE_BETWEEN_STUBS), CELL_COL_2);

            if(Code_stub==null){
                //ExcelModifier.Fill_Cell("not exist in the Code", SHEET_B1, B1_ExcelSheet.STUB_DEFINITION_TABLE_POSITION+ SutcCreation Process.number_of_UFT +(i* B1_ExcelSheet.DISTANCE_BETWEEN_STUBS)+2, CELL_COL_2);

                for (int j = 0; j <3 ; j++)  // add empty lines
                    Fill_Cell(" ", SHEET_B1_INDEX, STUB_PARAMETERS_TABLE_POSITION +(i* DISTANCE_BETWEEN_STUBS)+j, CELL_COL_1);

                row=row+ DISTANCE_BETWEEN_STUBS;
                continue; // if code not exist.
            }


            numberOfParameters= ExtractParameters(Code_stub, Stubs[i]);
            log4Debug(Stubs[i]+" numberOfParameters="+numberOfParameters);
            stubAccessDetect(Stubs[i],numberOfParameters);

            numberOfParameters=Stub_Return_Filling(Code_stub, Stubs[i],numberOfParameters);

            int startStub = row;

            for (int j = 0; j < numberOfParameters; j++,row++) {


                //System.out.println(Stubs[i]+"-"+Parameters[j][INDEX_OF_NAME]);

                if (Parameters[j][INDEX_OF_ACCESS]!=null)
                if ((Parameters[j][INDEX_OF_ACCESS].contains("out")|| Parameters[j][INDEX_OF_ACCESS].contains("Return"))&&(!(Parameters[j][INDEX_OF_INVALID_DOMAIN].equals("-")))){

                    first_row=row;
                   // System.out.println(Parameters[j][INDEX_OF_NAME]+"first row"+row);
                    Insert_Invalid_Row(row, Parameters[j]);
                    mergeRowsInRange(row);
                    row+=2;
                    Insert_Row(row, Parameters[j]);
                    mergeRowsInRange(row);
                    row+=2;
                    Insert_Invalid_Row(row, Parameters[j]);
                    mergeRowsInRange(row);
                    row++;
                   // System.out.println("end row"+row);



                }else {
                    first_row=row;
                   // System.out.println(Parameters[j][INDEX_OF_NAME]+"first row"+row);
                    Insert_Row(row, Parameters[j]);

                    if(!Objects.equals(Parameters[j][INDEX_OF_TYPE], "void"))
                    {
                    mergeRowsInRange(row);
                    row++;
                    }

                  //  System.out.println("end row"+row);
                }
                for (int k = 1; k <= 3 && row>first_row ; k++)
                    MergeRows(SHEET_B1_INDEX, k, first_row+1, row+1 );

            }

            row=startStub+ DISTANCE_BETWEEN_STUBS;

        }

        if(numberOfStubs==0) {
            for (int i = 0; i < 3; i++)  // add empty lines
                Fill_Cell(" ", SHEET_B1_INDEX, STUB_PARAMETERS_TABLE_POSITION, CELL_COL_1);
            row = row + DISTANCE_BETWEEN_STUBS;
        }

        removeExtraRows(SHEET_B1_INDEX,row-6, END_OF_SHEET_POSITION);
        Fill_Cell("End of UTC definition", SHEET_B1_INDEX,row-7,1);
        CorrectAlign(SHEET_B1_INDEX,row-7,1);
    }
    public static int Extract_Stubs(){

        int start= 0,end = 0;
        int numberOfStubs=0;

        for (int i = 0; i < llrOfTheFunction.length; i++) {

            if (Search(Stub_start,llrOfTheFunction[i])){
                start=i+1;
            }
            if (Search(Stub_end,llrOfTheFunction[i].trim()))
            {
                end=i-1;
                break;
            }
        }

        for (int j = start; j <= end ; j++) {

            if((llrOfTheFunction[j].trim().isEmpty()))//||(llrOfTheFunction[j].trim().equalsIgnoreCase("none"))||(llrOfTheFunction[j].trim().equalsIgnoreCase("none."))) // en cas ou supprimer le stub vide
                continue;

            Stubs[numberOfStubs]=llrOfTheFunction[j].trim();
            log4Debug("Stub n° "+numberOfStubs+" "+Stubs[numberOfStubs]);
            numberOfStubs++;
        }
        return numberOfStubs;
    }
    public static void stubAccessDetect(String stub_name, int numberOfParameters) {
        int position_of_stub=0;


        for (int i = llrOfTheFunction.length-1; i >=0 ; i--) {
            String llr_line=llrOfTheFunction[i].trim().toLowerCase();
            if((llr_line.contains(stub_name.toLowerCase()))||(llr_line.contains(stub_name.toLowerCase()+":")))
            {
                //System.out.println("llr_line"+llr_line);
                position_of_stub=i+1;
                break;

            }
        }


        int end = position_of_stub+numberOfParameters;
        int j=0;

        try {
            for (int i = position_of_stub; i < end; i++) {

                if (llrOfTheFunction[i].toUpperCase().contains("FUNCTION RETURN"))
                    end++;
                else if ((llrOfTheFunction[i].toUpperCase().contains("IN/OUT:")) || (llrOfTheFunction[i].toUpperCase().contains("IN/OUT ")) || (llrOfTheFunction[i].toUpperCase().contains("IN/OUT \t"))) {

                    log4Debug(Parameters[j][INDEX_OF_NAME] + " Access_IN_OUT :" + llrOfTheFunction[i]);
                    Parameters[j][INDEX_OF_ACCESS] = "_inout";
                    j++;
                } else if ((llrOfTheFunction[i].toUpperCase().contains("OUT:")) || (llrOfTheFunction[i].toUpperCase().contains("OUT "))) {
                    log4Debug(Parameters[j][INDEX_OF_NAME] + " Access_OUT :" + llrOfTheFunction[i]);
                    Parameters[j][INDEX_OF_ACCESS] = "_out";

                    j++;
                } else if ((llrOfTheFunction[i].toUpperCase().contains("IN:") || (llrOfTheFunction[i].toUpperCase().contains("IN ")))) {
                    log4Debug(Parameters[j][INDEX_OF_NAME] + " Access_IN :" + llrOfTheFunction[i]);
                    Parameters[j][INDEX_OF_ACCESS] = "_in";
                    Parameters[j][INDEX_OF_CLASS] = "-";
                    j++;
                } else if (j == 0) {
                    searchAccessFromEffectTable(stub_name);
                }

            }
        }catch (Exception e){
            String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
            log4Error(methodName+" : "+e.getMessage() );
        }
    }

    private static void searchAccessFromEffectTable(String stubName) {

        for (String effect: effectsTable
             ) {
                    if (effect.contains(stubName+" with"))
                    {

                        if ((effect.toUpperCase().contains("IN/OUT:")) || (effect.toUpperCase().contains("IN/OUT ")))  {

                            log4Debug(Parameters[0][INDEX_OF_NAME]+ " Access_IN_OUT :"+effect);
                            Parameters[0][INDEX_OF_ACCESS] = "_inout";

                        } else if ((effect.toUpperCase().contains("OUT:")) || (effect.toUpperCase().contains("OUT "))) {
                            log4Debug(Parameters[0][INDEX_OF_NAME]+ " Access_OUT :"+effect);
                            Parameters[0][INDEX_OF_ACCESS] = "_out";

                        } else if ((effect.toUpperCase().contains("IN:") || (effect.toUpperCase().contains("IN ")))) {
                            log4Debug(Parameters[0][INDEX_OF_NAME]+ " Access_IN :"+effect);
                            Parameters[0][INDEX_OF_ACCESS] = "_in";
                            Parameters[0][INDEX_OF_CLASS] = "-";

                        }



                    }
        }
    }

    public static int Stub_Return_Filling(String[] Code, String function_name, int numberOfParameters) {

        String[] domainClass;
        for (int i = Parameters.length-2; i >= 0 ; i--) { // Shift the parameters table
            System.arraycopy(Parameters[i], 0, Parameters[i + 1], 0, 10);
        }


        for (String code_line  : Code) {

            if (Prototype_Detect(code_line, function_name)) {

                if (!(code_line.contains("void ")))  {

                    Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_NAME] = "return_"+function_name;
                    Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_TYPE] = code_line.trim().substring(0, code_line.trim().indexOf(" ") );
                    Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_ACCESS] = "Return";
                    domainClass = Extract_Domain(Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_TYPE]);
                    Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_DOMAIN] = domainClass[0];
                    Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_CLASS] = domainClass[0];
                    Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_INVALID_DOMAIN] = domainClass[1];

                    if (Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_DOMAIN].equals("-")) {
                        domainClass[0]=DataDictionarySearch(Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_TYPE], false);
                        Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_DOMAIN] = domainClass[0];
                        Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_CLASS] =domainClass[0];
                        Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_INVALID_DOMAIN] = Extract_Invalid_Domain(Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_DOMAIN]);
                    }

                    break;
                } else {
                    Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_NAME] = "return_"+function_name;
                    Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_TYPE] = "void";
                    Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_ACCESS] = "Return";
                    Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_DOMAIN] = "-";
                    Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_CLASS] = "-";
                    Parameters[INDEX_RESERVED_FOR_FUNCTION_RETURN][INDEX_OF_INVALID_DOMAIN] = "-";

                    break;
                }

            }
        }

        return ++numberOfParameters;
    }

}
