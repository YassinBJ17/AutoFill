package SDDD.file;
import java.util.ArrayList;

import static SDDD.file.ExtractText.removeInvisibleChars;
import static SUTC.file.Commun.ExcelManipulation.*;
import static SUTC.file.SutcCreationProcess.causesTable;
import static SUTC.file.SutcCreationProcess.effectsTable;

public class ExtractRequirements {






    public static void Extract_Req(String LLR_Text) {


        String requirements_with_description ;
       // LLR_Text=LLR_Text.replace("\n\n","\n");





        for (int i = 0; i <causesTable.size() ; i++) {

            if (causesTable.get(i).startsWith("[")){
                requirements_with_description=LLR_Text.substring(LLR_Text.lastIndexOf(causesTable.get(i))+1);// extract description
                requirements_with_description=requirements_with_description.replace(" [","[");// delete space
                requirements_with_description=requirements_with_description.substring(0,requirements_with_description.indexOf("\n["));//end of description
                requirements_with_description=Cause_Modifier(requirements_with_description);
                causesTable.set(i,Cause_Modifier( requirements_with_description));
            }

        }

        for (int i = 0; i <effectsTable.size() ; i++)
        {
            String requirement=effectsTable.get(i);

            String final_requirements=requirement;
                while (requirement.contains("["))
                {
                    String requirements_without_description = requirement.substring(requirement.indexOf("["), requirement.indexOf("]")+1);
                    if (LLR_Text.contains(requirements_without_description))
                    {
                        requirements_with_description = LLR_Text.substring(LLR_Text.lastIndexOf(requirements_without_description) + 1); // 5dhina a partir mel requirements_with_description 7ata e5er l document LLR
                        requirements_with_description = requirements_with_description.replaceAll("\n ","\n");
                        requirements_with_description = (requirements_with_description.substring(0, requirements_with_description.indexOf("\n[")))+"\n"; // 5dhina description 7ata lin nouslou l awel accolade
                        final_requirements = final_requirements.replace(requirements_without_description, requirements_with_description); // nremplaciw description li 5dhinha
                        requirement = requirement.replace(requirements_without_description, "");

                    }else {
                        break;
                    }
                }


            if (final_requirements.equals("")) {
                requirement=Delete_extra_return_line(requirement);
                //System.err.println(requirement);
                effectsTable.set(i, requirement);

            }
                else {

                final_requirements=Delete_extra_return_line(final_requirements);
               // System.err.println(final_requirements);
                effectsTable.set(i, StubCall_Requirements_Modifier(SettingValue_req_Modifier(final_requirements)));
            }
        }
    }

    public static String cleanLllrText(String llrText) {

        llrText= llrText.replace("Traceability","[");
        llrText=removeInvisibleChars(llrText);

        for (String s : effectsTable) {
            s=s.replaceAll("Set"," Set");
            llrText = llrText.replace(s, "");
        }

        for (String s : causesTable) {

            llrText = llrText.replace(s, "");
        }


        return llrText;


    }
}





