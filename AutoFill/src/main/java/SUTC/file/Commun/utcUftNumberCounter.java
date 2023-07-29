package SUTC.file.Commun;

import java.util.Objects;

import static SUTC.file.SutcCreationProcess.*;


public class utcUftNumberCounter {

   // public static int number_of_UFT;
 //   public static int number_of_UTC;
    public static int numberOfCauses =0;


    public static void utcUftCounter(){


        numberOfCauses =0;
        for (String cs:causesTable) {
            if (!Objects.equals(cs, "null"))
                numberOfCauses++;
        }


        if (numberOfCauses == 0) {
            numberOfUFT = 1;
            numberOfUTC = 1;
        } else {
            numberOfUFT = numberOfCauses + 1;
            numberOfUTC = numberOfUFT * 2;
        }


    }




}
