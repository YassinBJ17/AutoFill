package CODE.file;

import static CODE.file.ExtractCode.extractFunctionCode;

public class ExtractFunction {

    public static String[] ExtractFunctionFromCode(String functionName){

        String codeFileName=functionName.trim()+".c";
        String Code_text= extractFunctionCode(codeFileName);
        if (Code_text.isEmpty())
            return null;
        return Code_text.split("\n");
    }

}
