package file.s3d;

import java.util.ArrayList;
import java.util.Arrays;

import static file.s3d.ExtractTextFromS3D.removeInvisibleChars;
import static file.sutc.Commun.ExcelManipulation.*;
import static file.sutc.SutcCreationProcess.causesTable;
import static file.sutc.SutcCreationProcess.effectsTable;

public class ExtractRequirements {

    public static void ExtractDescriptionOfRequirements(String TextFromLlrFile) {


        String requirements_with_description ;
       // TextFromLlrFile=TextFromLlrFile.replace("\n\n","\n");

        ArrayList<String> auxCausesTable = new ArrayList<>(causesTable);
        causesTable.clear();

        for (String cause:auxCausesTable) {

            cause = processRequirements(cause, TextFromLlrFile,true);

            if ((cause.contains("OR")) || (cause.contains("AND"))) { // OR , AND are required uppercase;
                String description=null;
                if(cause.contains(":"))
                {
                    description=cause.substring(0,cause.indexOf(":")+1);
                    cause=cause.substring(cause.indexOf(":")+1);
                }


                String[] cause_table = cause.split("(?<!\\bBITWISE)\\s+(OR|AND)\\s+");

                if (description!=null)
                    for (int i = 0; i < cause_table.length; i++) {
                        cause_table[i] = description + cause_table[i];
                    }

                causesTable.addAll(Arrays.asList(cause_table));
            }
            else
            if (!cause.isEmpty()) {
                // cause = deleteExtraReturnLine(cause);
                causesTable.add(cause);
            }
        }


        for (int i = 0; i < effectsTable.size(); i++) {

            String requirements = effectsTable.get(i);
            requirements = processRequirements(requirements, TextFromLlrFile,false);

            if (!requirements.isEmpty()) {
                requirements = deleteExtraReturnLine(requirements);
                effectsTable.set(i, (requirements));
            }
        }

    }

    private static String processRequirements(String requirement, String TextFromLlrFile,boolean isCause) {


        if (!(requirement.contains("["))||requirement.isEmpty()){
            return requirement;
        }

        String finalRequirements = "";
        String[] implementationSplit;
        String implimentation;


        implementationSplit=requirement.split("\\[");

        for (int i=0;i<implementationSplit.length ;i++) {
            String rest = "";
            implementationSplit[i]="["+implementationSplit[i];

            implimentation=implementationSplit[i].substring(implementationSplit[i].indexOf("["),implementationSplit[i].indexOf("]")+1 );
            implimentation=implimentation.replace("[ ","[").replace(" ]","]").trim();
            try {
                rest =implementationSplit[i].substring(implementationSplit[i].indexOf("]")+1 );
            }catch (Exception ignored){
                rest="";
            }

            if (implimentation.contains(" ")&&!(implimentation.contains("“")))
            {
                implimentation=replaceRequirement(implimentation,TextFromLlrFile);
                implementationSplit[i]=implimentation+rest;
            }
        }

        implementationSplit[0]=implementationSplit[0].replace("[","");
        for (String str : implementationSplit) {
            if(isCause){
                finalRequirements+= CauseModifier(str); }
                else{
            finalRequirements+= reqModifier(str); // Append each string without adding a space
        }
        }

        return finalRequirements;
    }

    private static String replaceRequirement(String requirement, String textFromLlrFile) {


                String requirementsWithoutDescription = requirement.substring(requirement.indexOf("["), requirement.indexOf("]") + 1);
                 if (textFromLlrFile.contains(requirementsWithoutDescription)) {

                    String requirementsWithDescription = textFromLlrFile.substring(textFromLlrFile.lastIndexOf(requirementsWithoutDescription) + 1);

                    requirementsWithDescription = requirementsWithDescription.replaceAll("\n ", "\n");

                    requirementsWithDescription = requirementsWithDescription.substring(0, requirementsWithDescription.indexOf("\n[") + 1);

                    return "\n"+requirementsWithDescription;

            }

        return requirement;
    }

    public static String cleanLlrText(String llrText) {

        llrText= llrText.replace("Traceability","[");
        llrText=removeInvisibleChars(llrText);

        return llrText;

    }
}





