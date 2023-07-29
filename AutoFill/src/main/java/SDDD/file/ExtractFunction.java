package SDDD.file;

public class ExtractFunction {


    public static String ExtractFunctionFromSDDD(String llr_to_treatment){

        llr_to_treatment=llr_to_treatment.substring(0,llr_to_treatment.indexOf("Rationale"));
        llr_to_treatment=" \n"+llr_to_treatment;

        return llr_to_treatment;
    }

}
