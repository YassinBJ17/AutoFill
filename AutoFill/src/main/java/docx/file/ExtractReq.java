package docx.file;
import java.util.ArrayList;

import static excel.file.Services.ExcelModifier.*;

public class ExtractReq {



    public static void Extract_Req(String LLR_Text, ArrayList<String> cause, ArrayList<String> effect) {


        String requirements_with_description ;
       // LLR_Text=LLR_Text.replace("\n\n","\n");
        LLR_Text=LLR_Text.replace("Traceability","[");



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
            while (true)
            {
                if (requirement.contains("["))
                {
                    String requirements_without_description = requirement.substring(requirement.indexOf("["), requirement.indexOf("]")+1);
                    if (LLR_Text.contains(requirements_without_description))
                    {
                        requirements_with_description = LLR_Text.substring(LLR_Text.lastIndexOf(requirements_without_description) + 1);
                        requirements_with_description = (requirements_with_description.substring(0, requirements_with_description.indexOf("\n[")))+"\n";
                        final_requirements = final_requirements.replace(requirements_without_description, requirements_with_description);
                        requirement = requirement.replace(requirements_without_description, "");

                    }
                }
                else
                {
                    break;
                }
            }

            if (final_requirements.equals("")) {
                requirement=requirement.replaceAll("Set","\nSet");
                effect.set(i, requirement);

            }
                else {
                final_requirements=final_requirements.replaceAll("Set","\nSet");

                effect.set(i, Stub_Modifier(Set_Modifier(final_requirements)));
            }
        }
    }
}





