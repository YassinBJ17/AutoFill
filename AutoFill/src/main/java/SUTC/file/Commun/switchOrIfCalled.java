package SUTC.file.Commun;

import static Commun.LoggerInitialize.log4Debug;
import static SUTC.file.SutcCreationProcess.codeOfTheFunction;


public class switchOrIfCalled {

    public static boolean[] switchArray=new boolean[50];
    public static void CheckIfSwitchExistInCode() {

        int index=0;

        if(codeOfTheFunction==null) return;

        for (String line : codeOfTheFunction) {
            if ((line.contains("switch ("))||(line.contains("switch("))) {
                switchArray[index] = true;
                log4Debug("Condition n°"+index+"= Switch ");
                index++;
            } else if ((line.contains("if ("))||(line.contains("if(")))  {
                switchArray[index] = false;
                log4Debug("Condition n°"+index+"= If ");
                index++;
            }
        }
    }



}
