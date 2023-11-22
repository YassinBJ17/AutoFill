package file.s3d;

import static file.commun.GraphicUserInterfaces.Error_interface;
import static file.commun.LoggerInitialize.log4Error;
import static file.s3d.ExtractText.removeInvisibleChars;
import static file.sutc.Commun.ExcelManipulation.*;
import static file.sutc.SutcCreationProcess.causesTable;
import static file.sutc.SutcCreationProcess.effectsTable;

public class ExtractRequirements {






    public static void ExtractDescriptionOfRequirements(String TextFromLlrFile) {


        String requirements_with_description ;
       // TextFromLlrFile=TextFromLlrFile.replace("\n\n","\n");




        for (int i = 0; i <causesTable.size() ; i++) {

            if (causesTable.get(i).startsWith("[")){
                requirements_with_description=TextFromLlrFile.substring(TextFromLlrFile.lastIndexOf(causesTable.get(i))+1);// extract description
               // System.out.println("requirements_with_description: "+requirements_with_description+"#");
                requirements_with_description=requirements_with_description.replace(" [","[");// delete space
                requirements_with_description=requirements_with_description.substring(0,requirements_with_description.indexOf("\n["));//end of description
                requirements_with_description=Cause_Modifier(requirements_with_description);
                causesTable.set(i,Cause_Modifier( requirements_with_description));
            }

        }

        for (int i = 0; i < effectsTable.size(); i++) {

            String requirement = effectsTable.get(i);

            String finalRequirements = processRequirements(requirement, TextFromLlrFile);

            if (finalRequirements.isEmpty()) {
                requirement = deleteExtraReturnLine(requirement);
                effectsTable.set(i, requirement);
            } else {
                finalRequirements = deleteExtraReturnLine(finalRequirements);
                effectsTable.set(i, stubCallRequirementsModifier(settingValueReqModifier(finalRequirements)));
            }
        }

    }

    private static String processRequirements(String requirement, String TextFromLlrFile) {
        String finalRequirements = requirement;

        try {

        while (requirement.startsWith("[")) {
            String requirementsWithoutDescription = requirement.substring(requirement.indexOf("["), requirement.indexOf("]") + 1);

            if (TextFromLlrFile.contains(requirementsWithoutDescription)) {

                String requirementsWithDescription = TextFromLlrFile.substring(TextFromLlrFile.lastIndexOf(requirementsWithoutDescription) + 1);

                requirementsWithDescription = requirementsWithDescription.replaceAll("\n ", "\n");

                requirementsWithDescription = requirementsWithDescription.substring(0, requirementsWithDescription.indexOf("\n[") + 1);

                finalRequirements = finalRequirements.replace(requirementsWithoutDescription, requirementsWithDescription);

                requirement = requirement.replace(requirementsWithoutDescription, "");

            } else {
               return "";
            }

        }
        }catch (StringIndexOutOfBoundsException e){
            String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
            log4Error(methodName+" : "+e.getMessage() );
        }

        return finalRequirements;
    }



    public static String cleanLlrText(String llrText) {

        llrText= llrText.replace("Traceability","[");
        llrText=removeInvisibleChars(llrText);
/*
        for (String s : effectsTable) {
            s=s.replaceAll("Set"," Set");
            llrText = llrText.replaceFirst(s, "");
        }

        for (String s : causesTable) {

            llrText = llrText.replaceFirst(s, "");
        }
*/

        return llrText;


    }
}





