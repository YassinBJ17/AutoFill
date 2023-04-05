package docx.file;
import java.util.ArrayList;

import static excel.file.ExcelModifier.*;

public class ExtractReq {


    public static boolean isVowel(char c) {
        c = Character.toLowerCase(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    public static void Delete_Double_causes(ArrayList<String> cause){

        for (int i = 0; i <cause.size() ; i++) {

            String req = cause.get(i).toUpperCase();
            req=req.replace(" NOT "," ");
            req=req.replace(" NO "," ");
            req=req.replace("[ ","[");
            req=req.replace(" DIFFERENT FROM "," EQUAL TO ");

            if(req.contains("[NO ")){
            if(isVowel(req.charAt(req.indexOf(" ")+1))){
                req=req.replace("[NO ","[AN ");
            }
                req=req.replace("[NO ","[A ");
            }

            for (int j = 0; j < cause.size(); j++) {

                String req2=cause.get(j);

                if ((req.equalsIgnoreCase(req2))&&(j!=i)){
                    {

                        cause.set(i, "null");

                    }
                }
            }

        }
    }



    public static void Extract_Req(String LLR_Text, ArrayList<String> cause, ArrayList<String> effect) {


        String requirements_with_description ;
       // LLR_Text=LLR_Text.replace("\n\n","\n");
        LLR_Text=LLR_Text.replace("Traceability","[");


        Delete_Double_causes(cause);

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





