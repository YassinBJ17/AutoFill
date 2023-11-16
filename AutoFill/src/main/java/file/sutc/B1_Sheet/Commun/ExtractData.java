package file.sutc.B1_Sheet.Commun;

import static file.commun.GraphicUserInterfaces.Error_interface;
import static file.commun.LoggerInitialize.log4Error;
import static file.sutc.B1_Sheet.B1_ExcelSheet.Parameters;
import static file.sutc.Commun.ExcelRowsAndColsConstants.INDEX_OF_NAME;
import static file.sutc.SutcCreationProcess.llrOfTheFunction;

public class ExtractData {

    public static String Extract_Invalid_Domain(String domain){

        if (domain.equals("-")||domain.equals("not exist in the DD"))
            return "-";

        String max,min,invalid;

        domain=domain.substring(domain.indexOf("{")+1);
        domain=domain.trim();
        System.out.println(domain);
        min=domain.substring(0,domain.indexOf(" "));

        max=domain.substring(domain.lastIndexOf(",")+1);
        max=max.trim();
        max=max.replace("}"," ");
        max=max.substring(0,max.indexOf(" "));

        //invalid="[0x80000000.."+min+"-1] U ["+max+" +1..0x7FFFFFFF]";
        invalid="[-2147483648.."+min+"[ # ]"+max+"..2147483648]";
        return invalid;
    }
    public static String[] Extract_Domain(String type) {
        String [] tab = new String[3];
        tab[0]="";
        String[][] domain = {
                {"", "",""},
                {"int8_t", "[0x80..0x7F]","-"},
                {"int16_t", "[0x8000..0x7FFF]","-"},
                {"int32_t", "[0x80000000..0x7FFFFFFF]","-"},
                {"int64_t", "[0x8000000000000000..0x7FFFFFFFFFFFFFFF]","-"},
                {"uint8_t", "[0..0xFF]","-"},
                {"uint16_t", "[0..0xFFFF]","-"},
                {"uint32_t", "[0..0xFFFFFFFF]","-"},
                {"uint64_t", "[0..0xFFFFFFFFFFFFFFFF]","-"},
                {"boolean_t", "{FALSE,TRUE}","[0x80000000..FALSE[ # ]TRUE..0x7FFFFFFF]"},
                {"float32_t", "[-3.4E38..3.4E38]","-"},
                {"float64_t", "[2.2E-308..1.7E308]","-"}
        };

        tab[0]="-";
        tab[1]="-";

        for (int i = 0; i <= 6; i++) {

            if(domain[i][0].equals(type.trim())){
                tab[0]=domain[i][1];
                tab[1]=domain[i][2];
                return tab;
            }
        }
        return tab;
    }
    public static String Access_Detect( int p) {
        String r="";
        int pos_start=0,pos_end=0;

        for (int i = 0; i < llrOfTheFunction.length ; i++) {
            if(llrOfTheFunction[i].toUpperCase().contains("PARAMETERS"))
            {
                pos_start=i;
                break;
            }
        }
        for (int i = 0; i < llrOfTheFunction.length ; i++) {
            if(llrOfTheFunction[i].toUpperCase().contains("[COV.REQ"))
            {
                pos_end=i;
                break;
            }
        }

        for (int i = pos_start; i <pos_end ; i++) {

            if(llrOfTheFunction[i].contains( Parameters[p][INDEX_OF_NAME])){

                r= (llrOfTheFunction[i].substring(llrOfTheFunction[i].indexOf("(")+1, llrOfTheFunction[i].indexOf(")")));

                if ((!r.equals("R"))&&(!r.equals("W"))&&(!r.equals("R/W"))&&(!r.equals("R\\W")))
                {
                    try {
                        r= llrOfTheFunction[i].substring(llrOfTheFunction[i].indexOf(")")+1);
                        r= r.substring(r.indexOf("(")+1,r.indexOf(")"));
                    } catch (IndexOutOfBoundsException e) {
                        String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
                        log4Error(methodName+" : "+e.getMessage() );
                        Error_interface(String.valueOf(e));
                    }
                }

                return r;
            }
        }
        return r;
    }


}
