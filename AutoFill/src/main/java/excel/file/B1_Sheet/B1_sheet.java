package excel.file.B1_Sheet;
import c.file.ExtractCode;
import excel.file.Services.Excel;
import excel.file.Services.ExcelModifier;
import excel.file.Services.ExcelSearch;
import org.apache.poi.ss.usermodel.*;
import org.apache.poi.ss.util.CellRangeAddress;
import java.io.IOException;
import java.util.Arrays;
import java.util.Objects;
import static excel.file.Services.ExcelFinal.*;
import static excel.file.Services.ExcelModifier.*;


public class B1_sheet {

    public static final int START_OF_PARAMETERS_TABLE=10;
    public static final int END_OF_SHEET_POSITION =workbook.getSheetAt(Excel.SHEET_B1).getLastRowNum();
    public static final int END_OF_GLOBAL_DEFINITION=56;
    public final int NUMBER_OF_EMPTY_CELL=25;
    public final int END_OF_SHEET=38;
    public final int RETURN_FUNCTION_INDEX=132;
    public final int DISTANCE_BETWEEN_STUBS =59;
    public final int STUB_PARAMETERS_TABLE_POSITION =140;
    public final int STUB_DEFINITION_TABLE_POSITION=133;
    public final int INTERNAL_DEFINITIONS_POSITION=30;
    public final int INTERNAL_VARIABLES_POSITION=71;
    public static int Global_Start=43;
    public static String Prototype;
    public static String[] Globals=new String[100];
    public static String[] Stubs=new String[100];
    public static String[][] Parameters=new String[100][10];


    //////////////////////////////////////////////INITIALIZE////////////////////////////////////////////////////////////
    public static void Initialize_Data(String function_name) {
        Arrays.fill(Globals, "");
        Arrays.fill(Stubs, "");

        for (String[] row : Parameters) {
            Arrays.fill(row, "");
        }
        ExcelModifier.Fill_Cell("Unit Test Cases for: " + function_name, Excel.SHEET_B1, Excel.CELL_ROW_0, Excel.CELL_COL_2);

        Prototype=function_name+"(";

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    /////////////////////////////////////////////////////STUBS//////////////////////////////////////////////////////////
    public void Stubs_Filling(String[] LLR) throws IOException {

        int numberOfStubs= Extract_Stubs(LLR);



        String Code_Stub;
        String[] Code_stub;
        int numberOfParameters;

        int distance= STUB_PARAMETERS_TABLE_POSITION -1 +number_of_UFT;
        for (int i = 0; i <numberOfStubs ; i++) {



            Code_Stub=(ExtractCode.extract(Stubs[i]+".c"));

            ExcelModifier.Fill_Cell(Stubs[i],Excel.SHEET_B1, STUB_DEFINITION_TABLE_POSITION+number_of_UFT +(i*DISTANCE_BETWEEN_STUBS), Excel.CELL_COL_2);

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
    public int Extract_Stubs(String[] LLR){

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
    public int Stub_Return_Filling(String[] Code, String function_name,int numberOfParameters) throws IOException {


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
                            Parameters[0][Excel.INDEX_OF_DOMAIN] = ExcelSearch.SearchFromDD(Parameters[0][Excel.INDEX_OF_TYPE], false);
                            Parameters[0][Excel.INDEX_OF_CLASS] = ExcelSearch.SearchFromDD(Parameters[0][Excel.INDEX_OF_TYPE], false);
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

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




    //////////////////////////////////////////////INSERT////////////////////////////////////////////////////////////////
    public int Insert_Parameter(int row,int Parameter_number,String[] LLR){

        if(LLR!=null)
        Parameters[Parameter_number][Excel.INDEX_OF_ACCESS]= Access_Detect(LLR,Parameters[Parameter_number][Excel.INDEX_OF_NAME]);
        if(row<=INTERNAL_VARIABLES_POSITION+number_of_UFT-2)
            Parameters[Parameter_number][Excel.INDEX_OF_ACCESS] = Parameters[Parameter_number][Excel.INDEX_OF_ACCESS].replace("R", "In").replace("W", "Out");


        if (((Parameters[Parameter_number][Excel.INDEX_OF_ACCESS].contains("W"))||(Parameters[Parameter_number][Excel.INDEX_OF_ACCESS].contains("Out")))&&(!(Parameters[Parameter_number][Excel.INDEX_OF_ACCESS].contains("/"))))
            Parameters[Parameter_number][Excel.INDEX_OF_CLASS]="-";


        row+=Insert_Row(row,Parameters[Parameter_number]);

        if (((Parameters[Parameter_number][Excel.INDEX_OF_ACCESS].contains("R"))||(Parameters[Parameter_number][Excel.INDEX_OF_ACCESS].contains("In")))&&(!(Parameters[Parameter_number][Excel.INDEX_OF_INVALID_DOMAIN].equals("-")))){
            row++;
            row+=Insert_Invalid_Row(row,Parameters[Parameter_number]);
        }
        return ++row;
    }
    public int Insert_Invalid_Row(int row, final String[] parameter){


        try {
        if ((parameter[Excel.INDEX_OF_ACCESS].equalsIgnoreCase("in"))||(parameter[Excel.INDEX_OF_ACCESS].equals("R"))){

                for (int i = 6; i <= 8; i++) {
                    if (i == 7)
                        ExcelModifier.Fill_Cell("I", Excel.SHEET_B1, row, i);
                    else {
                        ExcelModifier.Fill_Cell(parameter[7], Excel.SHEET_B1, row, i);
                    }
                }

                for (int i = 1; i <= 5; i++)
                    ExcelModifier.Merge_Cells(Excel.SHEET_B1, i, row,row+1);
                return 0;


            }else{


                for (int i = 6; i <= 8; i++) {
                    if (i == 7)
                        ExcelModifier.Fill_Cell("I", Excel.SHEET_B1, row, i);
                    else {
                        ExcelModifier.Fill_Cell(parameter[7], Excel.SHEET_B1, row, i);
                    }
                }


                for (int i = 1; i <= 5; i++)
                    ExcelModifier.Merge_Cells(Excel.SHEET_B1, i, row-1, row +2);


                for (int i = 6; i <= 8; i++)
                    ExcelModifier.Merge_Cells(Excel.SHEET_B1, i, row+1, row + 2);


                return 1;

            }
    }catch (Exception e)
    {
        e.printStackTrace();
    }
    return 0;
}
    public int Insert_Row(int row, String[] parameter){

        int retrun_Number_Of_Rows=0;


                if ((parameter[Excel.INDEX_OF_ACCESS].equalsIgnoreCase("in"))||(parameter[Excel.INDEX_OF_ACCESS].equals("R"))||(Objects.equals(parameter[Excel.INDEX_OF_TYPE], "void"))){

                    parameter=Classes_Filling(parameter);

                    for (int i = 1; i <= 8; i++) {
                        if((i==4)||(i==5)||(i==7)){
                            continue; }

                        if (i==1) {
                            if ((parameter[Excel.INDEX_OF_NAME].contains("["))&&(parameter[Excel.INDEX_OF_NAME].contains("]")))
                                ExcelModifier.Fill_Cell(parameter[Excel.INDEX_OF_NAME].replace("[","[0..").replace("]","-1]"),Excel.SHEET_B1,row,i); // array manipulation
                            else
                                ExcelModifier.Fill_Cell(parameter[i],Excel.SHEET_B1,row,i);
                        }else
                        ExcelModifier.Fill_Cell(parameter[i],Excel.SHEET_B1,row,i);
                    }



        }
        else{

            for (int i = 1; i <= 8; i++) {

                if((i==4)||(i==5)||(i==7)){
                    continue;}
                if (i==1) {
                    if ((parameter[Excel.INDEX_OF_NAME].contains("["))&&(parameter[Excel.INDEX_OF_NAME].contains("]")))
                        ExcelModifier.Fill_Cell(parameter[Excel.INDEX_OF_NAME].replace("[","[0..").replace("]","-1]"),Excel.SHEET_B1,row,i); // array manipulation
                    else
                        ExcelModifier.Fill_Cell(parameter[i],Excel.SHEET_B1,row,i);

                }else
                    ExcelModifier.Fill_Cell(parameter[i],Excel.SHEET_B1,row,i);
            }

            for (int i = 1; i <=8 ; i++)
            {
                boolean bool=((parameter[Excel.INDEX_OF_ACCESS].contains("W"))||(parameter[Excel.INDEX_OF_ACCESS].contains("Out"))||(parameter[Excel.INDEX_OF_ACCESS].equals("_in")))&&(!(parameter[Excel.INDEX_OF_ACCESS].contains("/")));
                if((parameter[Excel.INDEX_OF_INVALID_DOMAIN]=="-")||(i>5)||(bool))

                ExcelModifier.Merge_Cells(Excel.SHEET_B1,i,row+1,row+2);
            }
            retrun_Number_Of_Rows++;
            }

            return retrun_Number_Of_Rows;


    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    public static String Extract_Invalid_Domain(String domain){

        if (domain.equals("-")||domain.equals("not exist in the DD"))
            return "-";

        String max,min,invalid;
        domain=domain.substring(domain.indexOf("{")+1);
        domain=domain.trim();
        min=domain.substring(0,domain.indexOf(" "));

        max=domain.substring(domain.lastIndexOf(",")+1);
        max=max.trim();
        max=max.replace("}"," ");
        max=max.substring(0,max.indexOf(" "));

        invalid="[0x80000000.."+min+"-1] U ["+max+" +1..0x7FFFFFFF]";
        return invalid;
    }
    public static String[] Extract_Domain(String type) {
        String [] tab = new String[3];
        tab[0]="";
        String[][] domain = {
                {"uint8_t", "[0..0xFF]","-"},
                {"uint16_t", "[0..0xFFFF]","-"},
                {"uint32_t", "[0..0xFFFFFFFF]","-"},
                {"uint64_t", "[0..0xFFFFFFFFFFFFFFFF]","-"},
                {"boolean_t", "{FALSE,TRUE}","[0x2..0xFFFFFFFF]"},
                {"float32_t", "[-3.4E38..3.4E38]","-"},
                {"float64_t", "[2.2E-308..1.7E308]","-"}
        };

        tab[0]="-";
        tab[1]="-";

        for (int i = 0; i <= 6; i++) {

            if(domain[i][0].contains(type.trim())){
                tab[0]=domain[i][1];
                tab[1]=domain[i][2];
                return tab;
            }
        }
        return tab;
    }
    public static String Access_Detect(String[] LLR, String p) {
        String r="";
        int pos=0;

        for (int i = 0; i <LLR.length ; i++) {
            if(LLR[i].toUpperCase().contains("PARAMETERS"))
            {
                pos=i;
                break;
            }}

        for (int i = pos; i <LLR.length ; i++) {

            if(LLR[i].contains(p)){
                r= (LLR[i].substring(LLR[i].indexOf("(")+1,LLR[i].indexOf(")")));

                if ((!r.equals("R"))&&(!r.equals("W"))&&(!r.equals("R/W")))
                {
                    r=LLR[i].substring(LLR[i].indexOf(")")+1);
                    r= r.substring(r.indexOf("(")+1,r.indexOf(")"));
                }

                return r;
            }
        }
        return r;
    }
    public int Extract_Parameters(String[] code,String function_name) throws IOException {
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


            Parameters[numberOfParameters][Excel.INDEX_OF_NAME]=Param_detect(p)[0];
            Parameters[numberOfParameters][Excel.INDEX_OF_TYPE]=Param_detect(p)[1];
            Parameters[numberOfParameters][Excel.INDEX_OF_DOMAIN]=(Extract_Domain(Parameters[numberOfParameters][Excel.INDEX_OF_TYPE]))[0];
            Parameters[numberOfParameters][Excel.INDEX_OF_CLASS]=(Extract_Domain(Parameters[numberOfParameters][Excel.INDEX_OF_TYPE]))[0];
            Parameters[numberOfParameters][Excel.INDEX_OF_INVALID_DOMAIN]=(Extract_Domain(Parameters[numberOfParameters][Excel.INDEX_OF_TYPE]))[1];


            if(Parameters[numberOfParameters][Excel.INDEX_OF_DOMAIN].equals("-"))
            {
                Parameters[numberOfParameters][Excel.INDEX_OF_DOMAIN]= ExcelSearch.SearchFromDD(Parameters[numberOfParameters][Excel.INDEX_OF_TYPE],false);
                Parameters[numberOfParameters][Excel.INDEX_OF_CLASS]= ExcelSearch.SearchFromDD(Parameters[numberOfParameters][Excel.INDEX_OF_TYPE],false);
                Parameters[numberOfParameters][Excel.INDEX_OF_INVALID_DOMAIN]= Extract_Invalid_Domain(Parameters[numberOfParameters][Excel.INDEX_OF_DOMAIN]);
            }


            numberOfParameters++;
        }
        return numberOfParameters;
    }
    public void Parameters_Filling(String[] code, String[] LLR) throws IOException{

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
    public void Function_Return_Filling(String[] Code, String function_name) throws IOException {

        String prototype;
        String type;
        for (String cLine : Code) {

            if (Prototype_Detect(cLine, function_name)) {

                prototype = cLine;


                if (!(prototype.contains("void "))) {


                    type = prototype.substring(0, prototype.indexOf(function_name) - 1);

                    Parameters[0][Excel.INDEX_OF_NAME]="RTRT_Ret";
                    Parameters[0][Excel.INDEX_OF_TYPE]=type;
                    Parameters[0][Excel.INDEX_OF_ACCESS]="W";
                    Parameters[0][Excel.INDEX_OF_DOMAIN]=(Extract_Domain(Parameters[0][Excel.INDEX_OF_TYPE]))[0];
                    Parameters[0][Excel.INDEX_OF_CLASS]=(Extract_Domain(Parameters[0][Excel.INDEX_OF_TYPE]))[0];
                    Parameters[0][Excel.INDEX_OF_INVALID_DOMAIN]=(Extract_Domain(Parameters[0][Excel.INDEX_OF_TYPE]))[1];

                    if(Parameters[0][Excel.INDEX_OF_DOMAIN].equals("-"))
                    {
                        Parameters[0][Excel.INDEX_OF_DOMAIN]= ExcelSearch.SearchFromDD(Parameters[0][Excel.INDEX_OF_TYPE],false);
                        Parameters[0][Excel.INDEX_OF_CLASS]= ExcelSearch.SearchFromDD(Parameters[0][Excel.INDEX_OF_TYPE],false);
                        Parameters[0][Excel.INDEX_OF_INVALID_DOMAIN]= Extract_Invalid_Domain(Parameters[0][Excel.INDEX_OF_DOMAIN]);
                    }

                    Insert_Parameter(RETURN_FUNCTION_INDEX,0,null);
                    Prototype="RTRT_ret="+Prototype;

                }

                break;
            }
        }

    }
    public static void Prototype_Filling() {

        Prototype=Prototype+")";
        Prototype=Prototype.replace(", )",")");
        ExcelModifier.Fill_Cell(Prototype,Excel.SHEET_B1, Excel.CELL_ROW_3, Excel.CELL_COL_2);
    }

    ///////////////////////////////////////////////GLOBAL PARAMETER/////////////////////////////////////////////////////
    public void Global_Parameters_Filling(String[] LLR) {
        int numberOfGlobals=Extract_Global(LLR);
    try {
        for (int i = 0; i < numberOfGlobals; i++) {

            if (Globals[i].contains("{"))
                Parameters[i][Excel.INDEX_OF_NAME]=Globals[i].substring(Globals[i].indexOf("{")+1,Globals[i].indexOf("}")) ;
            else Parameters[i][Excel.INDEX_OF_NAME]=Globals[i].substring(0,Globals[i].indexOf(" ")) ;



            Parameters[i][Excel.INDEX_OF_TYPE]=ExcelSearch.SearchFromDD(Parameters[i][Excel.INDEX_OF_NAME],true) ;
            Parameters[i][Excel.INDEX_OF_DOMAIN]=(Extract_Domain(Parameters[i][Excel.INDEX_OF_TYPE]))[0];
            Parameters[i][Excel.INDEX_OF_CLASS]=(Extract_Domain(Parameters[i][Excel.INDEX_OF_TYPE]))[0];
            Parameters[i][Excel.INDEX_OF_INVALID_DOMAIN]=(Extract_Domain(Parameters[i][Excel.INDEX_OF_TYPE]))[1];

            if(Parameters[i][Excel.INDEX_OF_DOMAIN].equals("-")) {
                Parameters[i][Excel.INDEX_OF_DOMAIN] = ExcelSearch.SearchFromDD(Parameters[i][Excel.INDEX_OF_TYPE], false);
                Parameters[i][Excel.INDEX_OF_CLASS] = ExcelSearch.SearchFromDD(Parameters[i][Excel.INDEX_OF_TYPE], false);
                Parameters[i][Excel.INDEX_OF_INVALID_DOMAIN]=Extract_Invalid_Domain(Parameters[i][Excel.INDEX_OF_DOMAIN]);
            }

            Global_Start+=Insert_Global_Parameter(Global_Start+i+number_of_UFT,i,LLR);
        }
    }catch (Exception e){
        e.printStackTrace();
    }
    }
    public int Extract_Global(String [] LLR){

        int numberOfGlobals=0;

        for (int i = 0; i < LLR.length; i++) {

            if (ExcelModifier.Search(Excel.Global_start,LLR[i].trim())){
                int j=i+1;
                while (!ExcelModifier.Search(Excel.Global_end,LLR[j].trim())){

                    if((LLR[j].trim().equalsIgnoreCase("None"))||(LLR[j].trim().equalsIgnoreCase("None.")))break;

                    if((!(LLR[j].trim().isEmpty()))&&(!(ExcelModifier.Search(Globals, LLR[j])))){
                        Globals[numberOfGlobals]=LLR[j].trim();
                        numberOfGlobals++;
                    }
                    j++;
                }
            }
        }
        return numberOfGlobals;
    }
    public String Access_Global_Detect(String [] LLR, String parameter_name){


        for (int i = 0; i < LLR.length; i++) {

            if(LLR[i].contains(parameter_name)){

                if((LLR[i].toUpperCase().contains("IN:"))||(LLR[i].toUpperCase().contains("IN :")))
                    return "R";
                else  if((LLR[i].toUpperCase().contains("IN/OUT:"))||(LLR[i].toUpperCase().contains("IN/OUT :")))
                    return "R/W";
                else  if((LLR[i].toUpperCase().contains("OUT:"))||(LLR[i].toUpperCase().contains("OUT :")))
                    return "W";
                else{

                    for(int j = i; j >=0; j--)
                    {
                        if(LLR[j].toUpperCase().contains("OUTPUT DATA"))
                            return "W";
                        else if(LLR[j].toUpperCase().contains("INPUT DATA"))
                            return "R";
                    }


                }




            }

        }

        return"";
    }
    public boolean InternalDefinitionsExist(String parameter){

        Sheet A2_sheet= workbook.getSheetAt(Excel.SHEET_A2);

        for (int i = 3; i <60 ; i++) {
            Row row = A2_sheet.getRow(i);

            if (row != null) {
                // Get the second cell in the row
                Cell cell = row.getCell(2);
                if (Objects.equals(cell.toString(), parameter))
                    return true;
            }

        }
        return false;
    }
    public int Insert_Global_Parameter(int row,int Parameter_number,String[] LLR) {


        String []parameters;

        Parameters[Parameter_number][Excel.INDEX_OF_ACCESS]= Access_Global_Detect(LLR,Parameters[Parameter_number][Excel.INDEX_OF_NAME]);
        Parameters[Parameter_number][Excel.INDEX_OF_NAME]=Parameters[Parameter_number][Excel.INDEX_OF_NAME].replace(":","");

        if ((Parameters[Parameter_number][Excel.INDEX_OF_ACCESS].contains("W"))&&(!(Parameters[Parameter_number][Excel.INDEX_OF_ACCESS].contains("/")))){
            Parameters[Parameter_number][Excel.INDEX_OF_CLASS]="-";
        }

        int return_Number_Of_Rows=Insert_Row(row,Parameters[Parameter_number]);
        row=row+return_Number_Of_Rows;

        if (((Parameters[Parameter_number][Excel.INDEX_OF_ACCESS].contains("R")))&&(!(Parameters[Parameter_number][Excel.INDEX_OF_INVALID_DOMAIN].equals("-")))){
            row++;
            Insert_Invalid_Row(row,Parameters[Parameter_number]);
        }


        // A2 filling
        ExcelModifier.Fill_Cell("Variable",Excel.SHEET_A2,INTERNAL_DEFINITIONS_POSITION+number_of_UFT+Parameter_number,Excel.CELL_COL_1);
        if (Parameters[Parameter_number][Excel.INDEX_OF_NAME].contains(".")||Parameters[Parameter_number][Excel.INDEX_OF_NAME].contains("->")) {
            int index;
            index=Parameters[Parameter_number][Excel.INDEX_OF_NAME].indexOf("->");

            if (index==-1)
                index=Parameters[Parameter_number][Excel.INDEX_OF_NAME].indexOf(".");

            Parameters[Parameter_number][Excel.INDEX_OF_NAME] = Parameters[Parameter_number][Excel.INDEX_OF_NAME].substring(0,index);
        }
        if (!InternalDefinitionsExist(Parameters[Parameter_number][Excel.INDEX_OF_NAME])) {
            ExcelModifier.Fill_Cell(Parameters[Parameter_number][Excel.INDEX_OF_NAME], Excel.SHEET_A2, INTERNAL_DEFINITIONS_POSITION + number_of_UFT + Parameter_number, Excel.CELL_COL_2);
            ExcelModifier.Fill_Cell(Parameters[Parameter_number][Excel.INDEX_OF_TYPE], Excel.SHEET_A2, INTERNAL_DEFINITIONS_POSITION + number_of_UFT + Parameter_number, Excel.CELL_COL_3);
        }

        return return_Number_Of_Rows;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    public static boolean isInteger(String str) {
        try {
            Integer.parseInt(str);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }
    private static String[] Classes_Filling(String[] parameter) {

        String c;
        String clas="{ ";

        if(!parameter[Excel.INDEX_OF_TYPE].contains("int"))
            return parameter;

        for (int i = 0; i <cause.size() ; i++) {

           c=cause.get(i);
            if (c.contains(parameter[Excel.INDEX_OF_NAME])) {

                c=change_Form(c);
            }
        }
        return parameter;
    }

    private static String change_Form(String input) {
                String result = "";


                    if (input.contains("equal to")) {
                        result=input.substring(input.indexOf(":")+1);
                        result=result+";"+result.replace("equal to" ,"different from");

                    } else if (input.contains("different from")) {
                        result=input.substring(input.indexOf(":")+1  );
                        result=result+";"+result.replace("different from" ,"equal to");
                    }




                return result;
            }




    ///////////////////////////////////////////////REMOVE EXTRA ROWS/////////////////////////////////////////////////////
    public static void  Remove_Extra_Row( Workbook workbook){

    Sheet B1_sheet= workbook.getSheetAt(Excel.SHEET_B1);
    Sheet A2_sheet= workbook.getSheetAt(Excel.SHEET_A2);
    boolean bool=true;

    while (bool){
        bool=false;
    for (int i = START_OF_PARAMETERS_TABLE+1+ number_of_UFT; i <B1_sheet.getLastRowNum() ; i++) {

            Row row = B1_sheet.getRow(i);

            if (row != null) {
                // Get the second cell in the row
                Cell secondCell = row.getCell(1);

                boolean isMerged=false;
                for (CellRangeAddress mergedRegion : B1_sheet.getMergedRegions()) {
                    if (mergedRegion.isInRange(i, 1)) {
                        isMerged = true;
                        break;
                    }
                }
                if(secondCell!=null){
                if (secondCell.getCellType() == CellType.BLANK && !isMerged) {
                    // If the second cell is empty or null, delete the row
                    try {
                        B1_sheet.shiftRows(i + 1, B1_sheet.getLastRowNum(), -1);
                    }catch (Exception e)
                    {
                        e.printStackTrace();
                    }
                    bool=true;
                }
                }
            }
        }


        for (int i = 2; i <A2_sheet.getLastRowNum(); i++) {

            Row row = A2_sheet.getRow(i);
            Cell secondCell = row.getCell(2);

            boolean isMerged=false;
            for (CellRangeAddress mergedRegion : A2_sheet.getMergedRegions()) {
                if (mergedRegion.isInRange(i, 1)) {
                    isMerged = true;
                    break;
                }
            }

            if ((secondCell.getCellType() == CellType.BLANK)&& !isMerged) {
                // If the second cell is empty or null, delete the row
                A2_sheet.shiftRows(i + 1, A2_sheet.getLastRowNum(), -1);
            }

        }

    }
}
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




    public B1_sheet(Workbook workbook ) throws IOException {

    String function_name=LLR[1];
    System.out.println(function_name+": In progress");
    Initialize_Data(function_name);
    Stubs_Filling(LLR);
    Parameters_Filling(Code,LLR);
    Global_Parameters_Filling(LLR);
    Function_Return_Filling(Code,function_name);
    Prototype_Filling();
   Remove_Extra_Row(workbook);

    }



}


