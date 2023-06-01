package excel.file.Services;

import static excel.file.Services.ExcelFinal.number_of_causes;

public class Template_Choosing {

    public static final String TEMPLATE0_PATH ="../AutoFill/src/Template/SUTC TEMPLATE0.xls";
    public static final String TEMPLATE1_PATH ="../AutoFill/src/Template/SUTC TEMPLATE1.xls";
    public static final String TEMPLATE2_PATH ="../AutoFill/src/Template/SUTC TEMPLATE2.xls";
    public static final String TEMPLATE3_PATH ="../AutoFill/src/Template/SUTC TEMPLATE3.xls";
    public static final String TEMPLATEn_PATH ="../AutoFill/src/Template/SUTC TEMPLATEn.xls";


    public static String  TemplateChoosing(){
    String SUTC_template;
    switch (number_of_causes) {
        case 0 -> {
            SUTC_template = TEMPLATE0_PATH;
        }
        case 1 -> {
            SUTC_template = TEMPLATE1_PATH;
        }
        case 2 -> {
            SUTC_template = TEMPLATE2_PATH;
        }
        case 3 -> {
            SUTC_template = TEMPLATE3_PATH;
        }
        default -> {
            SUTC_template = TEMPLATEn_PATH;
        }
    }

return TEMPLATEn_PATH ;
    }
}
