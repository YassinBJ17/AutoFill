package file.sutc.Commun;

import java.util.Objects;

import static file.sutc.SutcCreationProcess.*;


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
        numberOfUTC=(Math.min(numberOfUFT, 40));
        numberOfUFT=(Math.min(numberOfUFT, 20));
    }




}
