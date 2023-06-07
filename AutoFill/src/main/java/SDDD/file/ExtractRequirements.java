package SDDD.file;
import java.util.ArrayList;

import static COMMUN.LoggerInitialize.*;
import static SUTC.file.COMMUN.ExcelModifier.*;

public class ExtractRequirements {






    public static void Extract_Req(String LLR_Text, ArrayList<String> cause, ArrayList<String> effect) {


        String requirements_with_description ;
       // LLR_Text=LLR_Text.replace("\n\n","\n");
        LLR_Text=LLR_Text.replace("Traceability","[");

        logInfo("Extract requirements progress");

        for (int i = 0; i <cause.size() ; i++) {

            if (cause.get(i).startsWith("[")){
                requirements_with_description=LLR_Text.substring(LLR_Text.lastIndexOf(cause.get(i))+1);// extract description
                requirements_with_description=requirements_with_description.replace(" [","[");// delete space
                requirements_with_description=requirements_with_description.substring(0,requirements_with_description.indexOf("\n["));//end of description
                requirements_with_description=Cause_Modifier(requirements_with_description);
                cause.set(i,Cause_Modifier( requirements_with_description));
            }

        }



        for (int i = 0; i <effect.size() ; i++)
        {
            String requirement=effect.get(i);

            String final_requirements=requirement;

                while (requirement.contains("["))
                {
                    String requirements_without_description = requirement.substring(requirement.indexOf("["), requirement.indexOf("]")+1);
                    if (LLR_Text.contains(requirements_without_description))
                    {
                        requirements_with_description = LLR_Text.substring(LLR_Text.lastIndexOf(requirements_without_description) + 1); // 5dhina a partir mel requirements_with_description 7ata e5er l document LLR
                        requirements_with_description = (requirements_with_description.substring(0, requirements_with_description.indexOf("\n[")))+"\n"; // 5dhina description 7ata lin nouslou l awel accolade
                        final_requirements = final_requirements.replace(requirements_without_description, requirements_with_description); // nremplaciw description li 5dhinha
                        requirement = requirement.replace(requirements_without_description, "");

                    }
                }


            if (final_requirements.equals("")) {
                requirement=Delete_extra_return_line(requirement);
                effect.set(i, requirement);
                System.err.println(requirement);
            }
                else {

                final_requirements=Delete_extra_return_line(final_requirements);
                effect.set(i, StubCall_req_Modifier(SettingValue_req_Modifier(final_requirements)));
            }
        }
    }
}





